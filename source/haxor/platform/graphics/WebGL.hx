#if html
package haxor.platform.graphics;
import haxor.io.Buffer;
import haxor.platform.Types.ProgramId;
import haxor.platform.Types.ShaderId;
import haxor.context.EngineContext;
import haxor.platform.Types.ArrayBuffer;
import haxor.platform.Types.MeshBufferId;
import js.html.Event;
import haxe.ds.EnumValueMap;
import haxor.platform.html.HTMLApplication;
import haxor.graphics.Screen;
import haxor.core.Console;
import haxor.platform.graphics.GraphicContext;

import haxor.core.BaseApplication;
import js.html.Element;
import js.Browser;
import js.html.DivElement;
import js.html.webgl.GL;
import js.html.CanvasElement;
import haxe.format.JsonParser;
import js.html.webgl.RenderingContext;

/**
 * Wrapper for all WebGL API commands and context management.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
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
		/*
		m_canvas.style.position = "absolute";
		m_canvas.style.left   	= "0px";
		m_canvas.style.top  	= "0px";
		m_canvas.style.width  	= "100%";
		m_canvas.style.height 	= "100%";
		//*/
		m_canvas.width 			= m_container.clientWidth;		
		m_canvas.height 		= m_container.clientHeight;
		m_container.appendChild(m_canvas);
		
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
			var ext : Dynamic = c.getExtension(extensions[i]);
			Console.Log("\t" + extensions[i],1);			
			switch(extensions[i])
			{
				case "OES_texture_half_float":
					//TextureAPI.HALF_FLOAT_OES = 0x8D61;
					
				case "OES_texture_half_float_linear":
					//TextureAPI.HALF_FLOAT_LINEAR = true;
				
				case "EXT_texture_filter_anisotropic", "WEBKIT_EXT_texture_filter_anisotropic":
					//TextureAPI.TEXTURE_MAX_ANISOTROPY_EXT = ext.TEXTURE_MAX_ANISOTROPY_EXT;
					//trace("\t\tMAX_TEXTURE_MAX_ANISOTROPY: " + c.getParameter(ext.MAX_TEXTURE_MAX_ANISOTROPY_EXT));
				
				case "OES_texture_float":
					//TextureAPI.TEXTURE_FLOAT = true;	
				
				case "WEBGL_depth_texture":
					//TextureAPI.TEXTURE_DEPTH = true;
			}					
		}
		
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
	override public /*inline*/ function VertexAttrib3f(p_location:Int, p_x:Float, p_y:Float, p_z:Float):Void 			{ c.vertexAttrib3f(p_location, p_x, p_y, p_z); }
	override public /*inline*/ function VertexAttrib4f(p_location:Int, p_x:Float, p_y:Float, p_z:Float, p_w:Float):Void { c.vertexAttrib4f(p_location, p_x, p_y, p_z, p_w);	}
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
	override public /*inline*/ function GetAttribLocation(p_program : ProgramId, p_name : String):Int 						{ return c.getAttribLocation(p_program,p_name); } 
	override public /*inline*/ function GetProgramInfoLog(p_program : ProgramId):String 									{ return c.getProgramInfoLog(p_program); }
	override public /*inline*/ function GetProgramParameter(p_program : ProgramId, p_parameter:Int):Int		 				{ return cast c.getProgramParameter(p_program, p_parameter); } //glGetProgramiv	
	override public /*inline*/ function LinkProgram(p_program:ProgramId):Void 												{ c.linkProgram(p_program); }
	override public /*inline*/ function UseProgram(p_program : ProgramId):Void 												{ c.useProgram(p_program); }
	
	//Flags
	override public /*inline*/ function BlendFunc(p_src : Int, p_dst : Int):Void 			{ c.blendFunc(p_src, p_dst); }
	override public /*inline*/ function Disable(p_flag : Int):Void 							{ c.disable(p_flag); }
	override public /*inline*/ function Enable(p_flag : Int):Void 							{ c.enable(p_flag); }
	override public /*inline*/ function DepthMask(p_flag : Bool):Void 						{ c.depthMask(p_flag); }
	override public /*inline*/ function DepthFunc(p_flag : Int):Void 						{ c.depthFunc(p_flag); }
	override public /*inline*/ function CullFace(p_face : Int):Void 						{ c.cullFace(p_face); }
	override public /*inline*/ function FrontFace(p_face : Int):Void 						{ c.frontFace(p_face); }
	
	//Clear
	override public /*inline*/ function Clear(p_flag : Int):Void 										{ c.clear(p_flag);	}	
	override public /*inline*/ function ClearDepth(p_value : Float):Void 								{ c.clearDepth(p_value); }	
	override public /*inline*/ function ClearColor(p_r: Float, p_g:Float, p_b:Float, p_a:Float):Void 	{ c.clearColor(p_r, p_g, p_b, p_a);	}
	
	//Error and Assert
	override public /*inline*/ function GetErrorCode():Int { return c.getError(); }		
}
#end