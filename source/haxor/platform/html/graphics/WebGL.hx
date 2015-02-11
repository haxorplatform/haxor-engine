#if html
package haxor.platform.html.graphics;
import js.html.HTMLCollection;
import js.html.NodeList;
import js.html.Node;
import haxor.platform.Types.Float32;
import haxe.ds.EnumValueMap;
import haxe.format.JsonParser;
import haxor.context.EngineContext;
import haxor.core.BaseApplication;
import haxor.core.Console;
import haxor.graphics.GL;
import haxor.graphics.GraphicContext;
import haxor.graphics.Screen;
import haxor.io.Buffer;
import haxor.io.FloatArray;
import haxor.io.Int32Array;
import haxor.io.UInt16Array;
import haxor.platform.html.HTMLApplication;
import haxor.platform.Types.ArrayBuffer;
import haxor.platform.Types.FrameBufferId;
import haxor.platform.Types.MeshBufferId;
import haxor.platform.Types.ProgramId;
import haxor.platform.Types.RenderBufferId;
import haxor.platform.Types.ShaderId;
import haxor.platform.Types.TextureId;
import haxor.platform.Types.UniformLocation;
import js.Browser;
import js.html.CanvasElement;
import js.html.DivElement;
import js.html.Element;
import js.html.Event;
import js.html.webgl.RenderingContext;


/**
 * Wrapper for all WebGL API commands and context management.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class WebGL extends GraphicContext
{	
	private var c : RenderingContext;
	
	private var m_canvas : CanvasElement;
	
	private var m_container : Element;
		
	/**
	 * Creates a new WebGL context.
	 * @param	p_application
	 */
	override public function new(p_application : BaseApplication):Void
	{
		super(p_application);
		m_api = GraphicAPI.WebGL;
	}
	
	/**
	 * Creates the 3D rendering context by adding a [canvas] element in the choosen DOM Element container.
	 * @param	p_container_id
	 * @return
	 */
	public function Initialize(p_container_id : String):Bool
	{
		
		var app : HTMLApplication = cast m_application;
		app.m_container = m_container = Browser.document.getElementById(p_container_id);
		
		if (m_container == null)
		{ 
			Console.Log("Graphics> Canvas container not defined id["+p_container_id+"].");
			return false; 
		}
		
		m_canvas = Browser.document.createCanvasElement();
		
		m_canvas.style.position = "absolute";
		m_canvas.style.left   	= "0px";
		m_canvas.style.top  	= "0px";
		m_canvas.style.width  	= "100%";
		m_canvas.style.height 	= "100%";
		//*/
		m_canvas.width 			= m_container.clientWidth;		
		m_canvas.height 		= m_container.clientHeight;
		m_canvas.id 			= "haxor-canvas";
		
		var fc : Element = m_container.firstElementChild;		
		m_container.appendChild(m_canvas);				
		if (fc != null) m_container.insertBefore(m_canvas, fc);
		
		var ctx_attrib 			: Dynamic 		 = { };		
		var ctx_attrib_list 	: Array<String>  = ["alpha", "antialias", "depth", "stencil", "premultipliedAlpha", "preserveDrawingBuffer"];
		var ctx_attrib_default  : Array<Bool> 	 = [false, false, true, false, true, false];
		
		Console.Log("Graphics> Initialize WebGL",1);
		
		for (i in 0...ctx_attrib_list.length)
		{
			var a : String 		= ctx_attrib_list[i];
			var ca : Dynamic 	= m_container.getAttribute(ctx_attrib_list[i]);			
			var flag : Bool 	= ca == null ? ctx_attrib_default[i] : (ca == "true");
			Console.Log("\t" + ctx_attrib_list[i] + ": " + flag,1);			
			untyped __js__("ctx_attrib[a]=flag");
		}
		
		c = m_canvas.getContextWebGL(ctx_attrib);
		
		if (c == null) 
		{ 
			Console.Log("Graphics> Could not create RenderingContext3D."); 
			return false;
		}
		
		return true;
	}
	
	/**
	 * Checks and activates the extension in the WebGL context.
	 */
	override public function CheckExtensions():Void 
	{
		if (c == null) return;
		
		Console.Log("Graphics> Available Extensions.",1);
		var extensions : Array<String> = c.getSupportedExtensions();
		for (i in 0...extensions.length)
		{
			if (extensions[i].indexOf("MOZ_") >= 0) continue;
			if (extensions[i].indexOf("WEBKIT_") >= 0) continue;
			var ext : Dynamic = c.getExtension(extensions[i]);
			Console.Log("\t" + extensions[i],1);			
			switch(extensions[i])
			{
				case "OES_vertex_array_object":
					GL.VERTEX_ARRAY_OBJECT = true;
					
				case "OES_texture_half_float":
					GL.HALF_FLOAT = 0x8D61;
					GL.TEXTURE_HALF = true;
					
				case "OES_texture_half_float_linear":
					GL.TEXTURE_HALF_LINEAR = true;
				
				case "EXT_texture_filter_anisotropic", "WEBKIT_EXT_texture_filter_anisotropic":
					GL.TEXTURE_ANISOTROPY     = ext.TEXTURE_MAX_ANISOTROPY_EXT;
					GL.MAX_TEXTURE_ANISOTROPY = c.getParameter(ext.MAX_TEXTURE_MAX_ANISOTROPY_EXT);							
					GL.TEXTURE_ANISOTROPY_ENABLED = true;					
					Console.Log("\t\tMax Aniso: " +GL.MAX_TEXTURE_ANISOTROPY,1);
				
				case "OES_texture_float":
					GL.TEXTURE_FLOAT = true;	
					
				case "OES_texture_float_linear":
					GL.TEXTURE_FLOAT_LINEAR = true;
				
				case "OES_depth_texture":
					GL.TEXTURE_DEPTH_ENABLED = true;
			}
		}
		
		GL.MAX_ACTIVE_TEXTURE = cast c.getParameter(GL.MAX_TEXTURE_IMAGE_UNITS);
		Console.Log("\tMax Active Textures: " + GL.MAX_ACTIVE_TEXTURE,1);
		
	}
	
	/**
	 * Adjust the <canvas> element for the new rendering area.
	 */
	override public /*inline*/ function Resize():Void 
	{
		m_canvas.width 			= m_container.clientWidth;		
		m_canvas.height 		= m_container.clientHeight;
	}
	
	//Attribs
	override public /*inline*/ function CreateBuffer():MeshBufferId 													{ return c.createBuffer(); }	
	override public /*inline*/ function BindBuffer(p_target:Int, p_id:MeshBufferId):Void 								{ c.bindBuffer(p_target, p_id); }	
	override public /*inline*/ function BufferData(p_target:Int, p_data:Buffer, p_mode:Int):Void 						{ c.bufferData(p_target, p_data.buffer, p_mode); }	
	override public /*inline*/ function BufferSubData(p_target:Int, p_offset:Int, p_data:Buffer):Void 					{ c.bufferSubData(p_target, p_offset, p_data.buffer); }	
	override public /*inline*/ function DeleteBuffer(p_id:MeshBufferId):Void 											{ c.deleteBuffer(p_id); }	
	override public /*inline*/ function DrawArrays(p_primitive:Int, p_start:Int, p_count:Int):Void 						{ c.drawArrays(p_primitive, p_start, p_count); }	
	override public /*inline*/ function DrawElements(p_primitive:Int, p_count:Int, p_type:Int, p_offset:Int):Void  		{ c.drawElements(p_primitive, p_count, p_type, p_offset); }	
	override public /*inline*/ function DisableVertexAttrib(p_location:Int):Void 										{ c.disableVertexAttribArray(p_location); }	
	override public /*inline*/ function EnableVertexAttrib(p_location:Int):Void  										{ c.enableVertexAttribArray(p_location); }	
	override public /*inline*/ function VertexAttrib3f(p_location:Int, p_x:Float32, p_y:Float32, p_z:Float32):Void 			{ c.vertexAttrib3f(p_location, p_x, p_y, p_z); }
	override public /*inline*/ function VertexAttrib4f(p_location:Int, p_x:Float32, p_y:Float32, p_z:Float32, p_w:Float32):Void { c.vertexAttrib4f(p_location, p_x, p_y, p_z, p_w);	}
	override public /*inline*/ function VertexAttribPointer(p_location:Int, p_components_size:Int, p_type:Int, p_normalized:Bool, p_stride:Int, p_offset:Int):Void { c.vertexAttribPointer(p_location, p_components_size, p_type, p_normalized, p_stride, p_offset); }
	
	//Shaders
	override public /*inline*/ function CompileShader(p_shader : ShaderId):Void 											{ c.compileShader(p_shader); }	
	override public /*inline*/ function CreateShader(p_type:Int):ShaderId 													{ return c.createShader(p_type); }
	override public /*inline*/ function DetachShader (p_program : ProgramId, p_shader : ShaderId):Void 						{ c.detachShader(p_program, p_shader); }
	override public /*inline*/ function DeleteShader(p_shader : ShaderId):Void 												{ c.deleteShader(p_shader); }	
	override public /*inline*/ function GetShaderInfoLog(p_shader : ShaderId) : String 										{ return c.getShaderInfoLog(p_shader); }	
	override public /*inline*/ function GetShaderParameter(p_shader : ShaderId,p_parameter:Int):Int 						{ return cast c.getShaderParameter(p_shader, p_parameter); } 		
	override public /*inline*/ function ShaderSource(p_shader : ShaderId, p_source : String):Void 							{ c.shaderSource(p_shader, p_source); }
	override public /*inline*/ function AttachShader(p_program : ProgramId, p_shader : ShaderId):Void 						{ c.attachShader(p_program, p_shader); }
	override public /*inline*/ function BindAttribLocation(p_program : ProgramId, p_location : Int, p_name : String):Void 	{ c.bindAttribLocation(p_program, p_location, p_name); }		
	override public /*inline*/ function CreateProgram():ProgramId 															{ return c.createProgram(); }	
	override public /*inline*/ function DeleteProgram(p_program : ProgramId):Void 											{ c.deleteProgram(p_program); } 	
	override public /*inline*/ function GetAttribLocation(p_program : ProgramId, p_name : String):Int 						{ return c.getAttribLocation(p_program, p_name); } 
	override public /*inline*/ function GetUniformLocation(p_program : ProgramId, p_name : String):UniformLocation 			{ return c.getUniformLocation(p_program,p_name); }
	override public /*inline*/ function GetProgramInfoLog(p_program : ProgramId):String 									{ return c.getProgramInfoLog(p_program); }
	override public /*inline*/ function GetProgramParameter(p_program : ProgramId, p_parameter:Int):Int		 				{ return cast c.getProgramParameter(p_program, p_parameter); } //glGetProgramiv	
	override public /*inline*/ function LinkProgram(p_program:ProgramId):Void 												{ c.linkProgram(p_program); }
	override public /*inline*/ function UseProgram(p_program : ProgramId):Void 												{ c.useProgram(p_program); }
	
	//Textures
	override public /*inline*/ function ActiveTexture(p_slot:Int):Void 														{ c.activeTexture(p_slot); }	
	override public /*inline*/ function BindFramebuffer(p_target:Int, p_id:FrameBufferId):Void 								{ c.bindFramebuffer(p_target, p_id); }
	override public /*inline*/ function BindRenderbuffer(p_target:Int, p_id:RenderBufferId):Void							{ c.bindRenderbuffer(p_target, p_id); }
	override public /*inline*/ function BindTexture(p_target:Int, p_id:TextureId):Void 										{ c.bindTexture(p_target, p_id); }
	override public /*inline*/ function CreateFramebuffer():FrameBufferId													{ return c.createFramebuffer(); }
	override public /*inline*/ function CreateRenderbuffer():RenderBufferId 												{ return c.createRenderbuffer(); }	
	override public /*inline*/ function CreateTexture():TextureId 															{ return c.createTexture(); }	
	override public /*inline*/ function DeleteFramebuffer(p_id:FrameBufferId):Void 											{ c.deleteFramebuffer(p_id); }
	override public /*inline*/ function DeleteRenderbuffer(p_id:RenderBufferId):Void 										{ c.deleteRenderbuffer(p_id); }
	override public /*inline*/ function DeleteTexture(p_id:TextureId):Void 													{ c.deleteTexture(p_id); }		
	override public /*inline*/ function FramebufferRenderbuffer(p_target:Int, p_attachment:Int, p_renderbuffer_target:Int, p_renderbuffer_id:RenderBufferId):Void 			
																															{ c.framebufferRenderbuffer(p_target, p_attachment, p_renderbuffer_target, p_renderbuffer_id);  }		
	override public /*inline*/ function FramebufferTexture2D(p_target:Int, p_attachment:Int, p_texture_target:Int, p_texture_id:TextureId, p_miplevel:Int):Void 					
																															{ c.framebufferTexture2D(p_target, p_attachment, p_texture_target, p_texture_id, p_miplevel); }		
	override public /*inline*/ function GenerateMipmap(p_target:Int):Void 													{ c.generateMipmap(p_target); }	
	override public /*inline*/ function PixelStorei(p_parameter:Int, p_value:Int):Void 										{ c.pixelStorei(p_parameter, p_value); }	
	override public /*inline*/ function RenderbufferStorage(p_target:Int, p_format:Int, p_width:Int, p_height:Int):Void 	{ c.renderbufferStorage(p_target, p_format, p_width, p_height); }		
	override public /*inline*/ function TexImage2D(p_target:Int, p_level:Int, p_internal_format:Int, p_width:Int, p_height:Int, p_border:Int, p_format:Int, p_channel_type:Int, p_data:Buffer):Void 
																															{ c.texImage2D(p_target, p_level, p_internal_format, p_width, p_height, p_border, p_format, p_channel_type, p_data.aux); }	
	override public /*inline*/ function TexImage2DAlloc(p_target:Int, p_level:Int, p_internal_format:Int, p_width:Int, p_height:Int, p_border:Int, p_format:Int, p_channel_type:Int):Void 
																															{ c.texImage2D(p_target, p_level, p_internal_format, p_width, p_height, p_border, p_format, p_channel_type, null); }	
	override public /*inline*/ function TexSubImage2D(p_target:Int, p_level:Int, p_x:Int, p_y:Int, p_width:Int, p_height:Int, p_format:Int, p_channel_type:Int, p_data:Buffer):Void 
																															{ c.texSubImage2D(p_target, p_level, p_x, p_y,p_width,p_height,p_format, p_channel_type, p_data.aux); }		
	override public /*inline*/ function TexParameterf(p_target:Int, p_parameter:Int, p_value:Float32):Void 					{ c.texParameterf(p_target, p_parameter, p_value); }	
	override public /*inline*/ function TexParameteri(p_target:Int, p_parameter:Int, p_value:Int):Void 						{ c.texParameteri(p_target, p_parameter, p_value); }
	
	//Flags
	override public /*inline*/ function BlendFunc(p_src : Int, p_dst : Int):Void 			{ c.blendFunc(p_src, p_dst); }
	override public /*inline*/ function Disable(p_flag : Int):Void 							{ c.disable(p_flag); }
	override public /*inline*/ function Enable(p_flag : Int):Void 							{ c.enable(p_flag); }
	override public /*inline*/ function DepthMask(p_flag : Bool):Void 						{ c.depthMask(p_flag); }
	override public /*inline*/ function DepthFunc(p_flag : Int):Void 						{ c.depthFunc(p_flag); }
	override public /*inline*/ function CullFace(p_face : Int):Void 						{ c.cullFace(p_face); }
	override public /*inline*/ function FrontFace(p_face : Int):Void 						{ c.frontFace(p_face); }
	
	//Uniforms
	override public /*inline*/ function Uniform1f(p_location:UniformLocation, p_x:Float32):Void 										{ c.uniform1f(p_location, p_x); }		
	override public /*inline*/ function Uniform2f(p_location:UniformLocation, p_x:Float32, p_y:Float32):Void 							{ c.uniform2f(p_location, p_x, p_y); }		
	override public /*inline*/ function Uniform3f(p_location:UniformLocation, p_x:Float32, p_y:Float32, p_z:Float32):Void 				{ c.uniform3f(p_location, p_x, p_y, p_z); }	
	override public /*inline*/ function Uniform4f(p_location:UniformLocation, p_x:Float32, p_y:Float32, p_z:Float32, p_w:Float32):Void 		{ c.uniform4f(p_location, p_x, p_y, p_z, p_w); }			
	override public /*inline*/ function Uniform1i(p_location:UniformLocation,p_x:Int):Void 											{ c.uniform1i(p_location, p_x); }			
	override public /*inline*/ function Uniform2i(p_location:UniformLocation,p_x:Int,p_y:Int):Void 									{ c.uniform2i(p_location, p_x, p_y); }			
	override public /*inline*/ function Uniform3i(p_location:UniformLocation,p_x:Int,p_y:Int,p_z:Int):Void 							{ c.uniform3i(p_location, p_x, p_y, p_z); }			
	override public /*inline*/ function Uniform4i(p_location:UniformLocation,p_x:Int,p_y:Int,p_z:Int,p_w:Int):Void 					{ c.uniform4i(p_location, p_x, p_y, p_z, p_w); }	
	override public /*inline*/ function Uniform1fv(p_location:UniformLocation, p_v:FloatArray):Void 								{ c.uniform1fv(p_location,cast p_v.aux); }
	override public /*inline*/ function Uniform2fv(p_location:UniformLocation,p_v:FloatArray):Void									{ c.uniform2fv(p_location,cast p_v.aux); }
	override public /*inline*/ function Uniform3fv(p_location:UniformLocation,p_v:FloatArray):Void 									{ c.uniform3fv(p_location,cast p_v.aux); }
	override public /*inline*/ function Uniform4fv(p_location:UniformLocation,p_v:FloatArray):Void 									{ c.uniform4fv(p_location,cast p_v.aux); }	
	override public /*inline*/ function Uniform1iv(p_location:UniformLocation,p_v:Int32Array):Void 									{ c.uniform1iv(p_location,cast p_v.aux); }
	override public /*inline*/ function Uniform2iv(p_location:UniformLocation,p_v:Int32Array):Void 									{ c.uniform2iv(p_location,cast p_v.aux); }
	override public /*inline*/ function Uniform3iv(p_location:UniformLocation,p_v:Int32Array):Void 									{ c.uniform3iv(p_location,cast p_v.aux); }
	override public /*inline*/ function Uniform4iv(p_location:UniformLocation,p_v:Int32Array):Void 									{ c.uniform4iv(p_location,cast p_v.aux); }
	override public /*inline*/ function UniformMatrix2fv(p_location:UniformLocation,p_transpose:Bool,p_v:FloatArray):Void 			{ c.uniformMatrix2fv(p_location, p_transpose,cast p_v.aux); }
	override public /*inline*/ function UniformMatrix3fv(p_location:UniformLocation,p_transpose:Bool,p_v:FloatArray):Void 			{ c.uniformMatrix3fv(p_location, p_transpose,cast p_v.aux); }
	override public /*inline*/ function UniformMatrix4fv(p_location:UniformLocation,p_transpose:Bool,p_v:FloatArray):Void 			{ c.uniformMatrix4fv(p_location, p_transpose,cast p_v.aux); }
	
	//Screen
	override public /*inline*/ function Clear(p_flag : Int):Void 										{ c.clear(p_flag);	}	
	override public /*inline*/ function ClearDepth(p_value : Float32):Void 								{ c.clearDepth(p_value); }	
	override public /*inline*/ function ClearColor(p_r: Float32, p_g:Float32, p_b:Float32, p_a:Float32):Void 	{ c.clearColor(p_r, p_g, p_b, p_a);	}
	override public /*inline*/ function Viewport(p_x:Int, p_y:Int, p_width:Int, p_height:Int):Void 		{ c.viewport(p_x, p_y, p_width, p_height); }
	override public /*inline*/ function Scissor(p_x:Int, p_y:Int, p_width:Int, p_height:Int):Void 		{ c.scissor(p_x, p_y, p_width, p_height); }
	override public /*inline*/ function ReadPixels(p_x:Int, p_y:Int, p_width:Int, p_height:Int, p_format:Int, p_type:Int, p_pixels:Buffer):Void { c.readPixels(p_x, p_y, p_width, p_height, p_format, p_type, p_pixels.m_buffer); }
	
	override public inline function Flush():Void 
	{		
		//c.flush();
	}
	
	//Error and Assert
	override public /*inline*/ function GetErrorCode():Int { return c.getError(); }		
}
#end