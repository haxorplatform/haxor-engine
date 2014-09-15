#if android
package haxor.platform.android.graphics;
import haxor.platform.Types.Float32;
import haxor.graphics.GL;
import haxor.graphics.GraphicContext;
import haxor.io.Int32Array;
import haxor.platform.Types.UniformLocation;
import haxor.platform.Types.RenderBufferId;
import haxor.platform.Types.TextureId;
import haxor.platform.Types.FrameBufferId;
import haxor.io.Buffer;
import haxor.platform.Types.ProgramId;
import haxor.platform.Types.ShaderId;
import haxor.context.EngineContext;
import haxor.platform.Types.ArrayBuffer;
import haxor.io.FloatArray;
import haxor.io.UInt16Array;

import java.NativeArray;
import haxor.platform.Types.MeshBufferId;
import haxor.platform.android.Entry;
import haxor.core.Console;
import haxor.graphics.GraphicContext.GraphicAPI;
import haxor.core.BaseApplication;
import android.app.Activity;
import haxor.platform.Types.GLES;
import android.opengl.GLSurfaceView;
import android.opengl.GLES10;
import android.opengl.GLES11;
import android.opengl.GLES11Ext;
import android.opengl.GLES20;
import android.opengl.GLES30;
import android.view.View;

/**
 * Wrapper for all Android GLES API commands and context management.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class AndroidGL extends GraphicContext
{	
	private var c : GLSurfaceView;
	
	private var m_ids : NativeArray<Int>;
	
	/**
	 * Creates a new Android GLES context.
	 * @param	p_application
	 */
	override public function new(p_application : BaseApplication):Void
	{
		super(p_application);
		m_api = GraphicAPI.OpenGLES;		
	}
	
	/**
	 * Initializes the GLES context passing its setup attributes.
	 * @param	p_application
	 * @param	p_canvas
	 * @param	p_alpha
	 * @param	p_depth
	 * @param	p_antialias
	 * @param	p_stencil
	 * @param	p_premultipliedAlpha
	 * @param	p_preserveDrawingBuffer
	 * @return
	 */
	public function Initialize(p_entry : Entry,p_version:Int=2):Bool
	{
		if (p_entry == null) { Console.Log("Graphics> Invalid Entry Activity."); return false; }
				
		var cv : Int = p_version;
		untyped __java__('
		 c = new android.opengl.GLSurfaceView(p_entry.getApplication());
		 ');
		 
		if (c == null) { Console.Log("Graphics> Could not create GLSurfaceView."); return false; }
		
		
		var w:Int=0;
		var h:Int=0;
		
		untyped __java__('
		c.setEGLContextClientVersion(cv);
		c.setRenderer(p_entry);				
		p_entry.setContentView(c);	
		
		
		
		android.view.Display display = p_entry.getWindowManager().getDefaultDisplay();
		
		android.util.DisplayMetrics metrics = new android.util.DisplayMetrics();
		display.getMetrics(metrics);

		w = metrics.widthPixels;
		h = metrics.heightPixels;
		
		');
		
		m_ids = new NativeArray<Int>(1);
		
		Console.Log("Graphics> Initialize Android GLES version["+p_version+"] Resolution["+w+","+h+"]",1);
		
		return true;
	}
	
	/**
	 * Callback for OnPause
	 */
	function OnPause():Void { untyped __java__ ('c.onPause()'); }
	
	/**
	 * Callback for OnResume
	 */
	function OnResume():Void { untyped __java__ ('c.onResume()'); }
	
	/**
	 * See GL.
	 */
	override public function CheckExtensions():Void 
	{
		if (c == null) return;	
		
		c.setLayerType(android.view.View.LAYER_TYPE_HARDWARE, null);
		
		Console.Log("Graphics> Available Extensions. Hardware["+c.isHardwareAccelerated()+"]", 1);
		var il : NativeArray<Int> = new NativeArray(1);
		var fl : NativeArray<Single> = new NativeArray(1);
		var exts : Array<String> = GLES20.glGetString(GLES20.GL_EXTENSIONS).split(" ");
		
		for (i in 0...exts.length)
		{
			var n : String = exts[i];			
			n = StringTools.replace(n, "GL_", "");
			if (n == "") continue;
			Console.Log("\t" + n);
			switch(n)
			{
				case "OES_texture_half_float":
					GL.HALF_FLOAT 	= 0x8D61;
					GL.TEXTURE_HALF = true;
					
				case "OES_texture_half_float_linear":
					GL.TEXTURE_HALF_LINEAR = true;
				
				case "EXT_texture_filter_anisotropic", "WEBKIT_EXT_texture_filter_anisotropic":					
					GLES20.glGetFloatv(GLES11Ext.GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, fl, 0);
					GL.MAX_TEXTURE_ANISOTROPY = cast fl[0];
					GL.TEXTURE_ANISOTROPY_ENABLED = true;
					Console.Log("\t\tMAX_TEXTURE_MAX_ANISOTROPY: " + GL.MAX_TEXTURE_ANISOTROPY);
				
				case "OES_texture_float":
					GL.TEXTURE_FLOAT = true;	
				
				case "WEBGL_depth_texture":
					GL.TEXTURE_DEPTH_ENABLED = true;					
			}			
		}	
		
		GLES20.glGetIntegerv(GLES.GL_MAX_TEXTURE_IMAGE_UNITS, il, 0);
		GL.MAX_ACTIVE_TEXTURE = il[0];
		Console.Log("\tMax Active Textures: " + GL.MAX_ACTIVE_TEXTURE);
		
	}
		
	//Attribs
	override public /*inline*/ function BindBuffer(p_target:Int, p_id:MeshBufferId):Void 								 { GLES.glBindBuffer(p_target, p_id); }	
	override public /*inline*/ function BufferData(p_target:Int, p_data:Buffer, p_mode:Int):Void 					 	 { GLES.glBufferData(p_target, p_data.byteLength, p_data.buffer, p_mode); }
	override public /*inline*/ function BufferSubData(p_target:Int, p_offset:Int, p_data:Buffer):Void   			 	 { GLES.glBufferSubData(p_target, p_offset, p_data.byteLength, p_data.buffer); 	}
	override public /*inline*/ function CreateBuffer():MeshBufferId 													 { GLES.glGenBuffers(1,m_ids,0);	return m_ids[0];	}	
	override public /*inline*/ function DrawArrays(p_primitive:Int, p_start:Int, p_count:Int):Void 					 	 { GLES.glDrawArrays(p_primitive, p_start, p_count); }
	override public /*inline*/ function DrawElements(p_primitive:Int, p_count:Int, p_type:Int, p_offset:Int):Void 		 { GLES.glDrawElements(p_primitive, p_count, p_type, p_offset);	}
	override public /*inline*/ function DeleteBuffer(p_id:MeshBufferId):Void 											 { m_ids[0] = p_id; GLES.glDeleteBuffers(1,m_ids, 0); }
	override public /*inline*/ function DisableVertexAttrib(p_location:Int):Void  										 { GLES.glDisableVertexAttribArray(p_location); }
	override public /*inline*/ function EnableVertexAttrib(p_location:Int):Void 										 { GLES.glEnableVertexAttribArray(p_location); }
	override public /*inline*/ function VertexAttrib3f(p_location:Int, p_x:Float32, p_y:Float32, p_z:Float32):Void 			 { GLES.glVertexAttrib3f(p_location, p_x, p_y, p_z);	}
	override public /*inline*/ function VertexAttrib4f(p_location:Int, p_x:Float32, p_y:Float32, p_z:Float32, p_w:Float32):Void  { GLES.glVertexAttrib4f(p_location, p_x, p_y, p_z, p_w);	}
	override public /*inline*/ function VertexAttribPointer(p_location:Int, p_components_size:Int, p_type:Int, p_normalized:Bool, p_stride:Int, p_offset:Int):Void { GLES.glVertexAttribPointer(p_location, p_components_size, p_type, p_normalized, p_stride, p_offset); }
	
	///Shaders
	override public /*inline*/ function CompileShader(p_shader : ShaderId):Void 											{ GLES.glCompileShader(p_shader); }	
	override public /*inline*/ function CreateShader(p_type:Int):ShaderId 													{ return GLES.glCreateShader(p_type); }
	override public /*inline*/ function DetachShader(p_program : ProgramId, p_shader : ShaderId):Void 					 	{ GLES.glDetachShader(p_program, p_shader); }
	override public /*inline*/ function DeleteShader(p_shader : ShaderId):Void 												{ GLES.glDeleteShader(p_shader); }	
	override public /*inline*/ function GetShaderInfoLog(p_shader : ShaderId) : String 										{ return GLES.glGetShaderInfoLog(p_shader); }	
	override public /*inline*/ function GetShaderParameter(p_shader : ShaderId, p_parameter:Int):Int		 				{ var d : NativeArray<Int> = new NativeArray(1); GLES.glGetShaderiv(p_shader, p_parameter, d,0); return d[0]; }
	override public /*inline*/ function ShaderSource(p_shader : ShaderId, p_source : String):Void							{ GLES.glShaderSource(p_shader, p_source); }
	override public /*inline*/ function AttachShader(p_program : ProgramId, p_shader : ShaderId):Void 					 	{ GLES.glAttachShader(p_program, p_shader); }
	override public /*inline*/ function BindAttribLocation(p_program : ProgramId, p_location : Int, p_name : String):Void 	{ GLES.glBindAttribLocation(p_program, p_location, p_name); }		
	override public /*inline*/ function CreateProgram():ProgramId 															{ return GLES.glCreateProgram(); }	
	override public /*inline*/ function DeleteProgram(p_program : ProgramId):Void 											{ GLES.glDeleteProgram(p_program); } 	
	override public /*inline*/ function GetAttribLocation(p_program : ProgramId, p_name : String):Int 						{ return GLES.glGetAttribLocation(p_program, p_name); } 
	override public /*inline*/ function GetUniformLocation(p_program : ProgramId, p_name : String):UniformLocation 			{ return GLES.glGetUniformLocation(p_program,p_name); }
	override public /*inline*/ function GetProgramInfoLog(p_program : ProgramId):String 									{ return GLES.glGetProgramInfoLog(p_program); }
	override public /*inline*/ function GetProgramParameter(p_program : ProgramId, p_parameter:Int):Int		 				{ var d : NativeArray<Int> = new NativeArray(1); GLES.glGetProgramiv(p_program, p_parameter, d, 0); return d[0]; }
	override public /*inline*/ function LinkProgram(p_program:ProgramId):Void 												{ GLES.glLinkProgram(p_program); }
	override public /*inline*/ function UseProgram(p_program : ProgramId):Void 												{ GLES.glUseProgram(p_program); }
	
	//Textures
	override public /*inline*/ function ActiveTexture(p_slot:Int):Void 														{ GLES.glActiveTexture(p_slot); }	
	override public /*inline*/ function BindFramebuffer(p_target:Int, p_id:FrameBufferId):Void 								{ GLES.glBindFramebuffer(p_target, p_id); }
	override public /*inline*/ function BindRenderbuffer(p_target:Int, p_id:RenderBufferId):Void							{ GLES.glBindRenderbuffer(p_target, p_id); }
	override public /*inline*/ function BindTexture(p_target:Int, p_id:TextureId):Void 										{ GLES.glBindTexture(p_target, p_id); }
	override public /*inline*/ function CreateFramebuffer():FrameBufferId													{ GLES.glGenFramebuffers(1, m_ids,0);   return m_ids[0]; }
	override public /*inline*/ function CreateRenderbuffer():RenderBufferId 												{ GLES.glGenRenderbuffers(1, m_ids,0);  return m_ids[0]; }	
	override public /*inline*/ function CreateTexture():TextureId 															{ GLES.glGenTextures(1, m_ids,0); 		return m_ids[0]; }	
	override public /*inline*/ function DeleteFramebuffer(p_id:FrameBufferId):Void 											{ m_ids[0] = p_id; GLES.glDeleteFramebuffers(1, m_ids, 0); }
	override public /*inline*/ function DeleteRenderbuffer(p_id:RenderBufferId):Void 										{ m_ids[0] = p_id; GLES.glDeleteRenderbuffers(1, m_ids, 0); }
	override public /*inline*/ function DeleteTexture(p_id:TextureId):Void 													{ m_ids[0] = p_id; GLES.glDeleteTextures(1, m_ids, 0); }		
	override public /*inline*/ function FramebufferRenderbuffer(p_target:Int, p_attachment:Int, p_renderbuffer_target:Int, p_renderbuffer_id:RenderBufferId):Void 			
																															{ GLES.glFramebufferRenderbuffer(p_target, p_attachment, p_renderbuffer_target, p_renderbuffer_id);  }		
	override public /*inline*/ function FramebufferTexture2D(p_target:Int, p_attachment:Int, p_texture_target:Int, p_texture_id:TextureId, p_miplevel:Int):Void 					
																															{ GLES.glFramebufferTexture2D(p_target, p_attachment, p_texture_target, p_texture_id, p_miplevel); }		
	override public /*inline*/ function GenerateMipmap(p_target:Int):Void 													{ GLES.glGenerateMipmap(p_target); }	
	override public /*inline*/ function PixelStorei(p_parameter:Int, p_value:Int):Void 										{ GLES.glPixelStorei(p_parameter, p_value); }	
	override public /*inline*/ function RenderbufferStorage(p_target:Int, p_format:Int, p_width:Int, p_height:Int):Void 	{ GLES.glRenderbufferStorage(p_target, p_format, p_width, p_height); }		
	override public /*inline*/ function TexImage2D(p_target:Int, p_level:Int, p_internal_format:Int, p_width:Int, p_height:Int, p_border:Int, p_format:Int, p_channel_type:Int, p_data:Buffer):Void 
																															{ GLES.glTexImage2D(p_target, p_level, p_internal_format, p_width, p_height, p_border, p_format, p_channel_type, p_data.buffer); }	
	override public /*inline*/ function TexImage2DAlloc(p_target:Int, p_level:Int, p_internal_format:Int, p_width:Int, p_height:Int, p_border:Int, p_format:Int, p_channel_type:Int):Void 
																															{ GLES.glTexImage2D(p_target, p_level, p_internal_format,p_width,p_height,p_border, p_format, p_channel_type,null); }																																
	override public /*inline*/ function TexSubImage2D(p_target:Int, p_level:Int, p_x:Int, p_y:Int, p_width:Int, p_height:Int, p_format:Int, p_channel_type:Int, p_data:Buffer):Void 
																															{ GLES.glTexSubImage2D(p_target, p_level, p_x, p_y,p_width,p_height,p_format, p_channel_type, p_data.buffer); }		
	override public /*inline*/ function TexParameterf(p_target:Int, p_parameter:Int, p_value:Float32):Void 					{ GLES.glTexParameterf(p_target, p_parameter, p_value); }	
	override public /*inline*/ function TexParameteri(p_target:Int, p_parameter:Int, p_value:Int):Void 						{ GLES.glTexParameteri(p_target, p_parameter, p_value); }
	
	//Uniforms
	override public /*inline*/ function Uniform1f(p_location:UniformLocation, p_x:Float32):Void 										{ GLES.glUniform1f(p_location,cast p_x); }		
	override public /*inline*/ function Uniform2f(p_location:UniformLocation, p_x:Float32, p_y:Float32):Void 							{ GLES.glUniform2f(p_location,cast p_x, cast p_y); }		
	override public /*inline*/ function Uniform3f(p_location:UniformLocation, p_x:Float32, p_y:Float32, p_z:Float32):Void 				{ GLES.glUniform3f(p_location,cast p_x, cast p_y, cast p_z); }	
	override public /*inline*/ function Uniform4f(p_location:UniformLocation, p_x:Float32, p_y:Float32, p_z:Float32, p_w:Float32):Void 		{ GLES.glUniform4f(p_location,cast p_x, cast p_y, cast p_z, cast p_w); }			
	override public /*inline*/ function Uniform1i(p_location:UniformLocation,p_x:Int):Void 											{ GLES.glUniform1i(p_location, p_x); }			
	override public /*inline*/ function Uniform2i(p_location:UniformLocation,p_x:Int,p_y:Int):Void 									{ GLES.glUniform2i(p_location, p_x, p_y); }			
	override public /*inline*/ function Uniform3i(p_location:UniformLocation,p_x:Int,p_y:Int,p_z:Int):Void 							{ GLES.glUniform3i(p_location, p_x, p_y, p_z); }			
	override public /*inline*/ function Uniform4i(p_location:UniformLocation,p_x:Int,p_y:Int,p_z:Int,p_w:Int):Void 					{ GLES.glUniform4i(p_location, p_x, p_y, p_z, p_w); }	
	override public /*inline*/ function Uniform1fv(p_location:UniformLocation, p_v:FloatArray):Void 								{ GLES.glUniform1fv(p_location,p_v.length, p_v.aux); }
	override public /*inline*/ function Uniform2fv(p_location:UniformLocation,p_v:FloatArray):Void									{ GLES.glUniform2fv(p_location,Std.int(p_v.length/2), p_v.aux); }
	override public /*inline*/ function Uniform3fv(p_location:UniformLocation,p_v:FloatArray):Void 									{ GLES.glUniform3fv(p_location,Std.int(p_v.length/3), p_v.aux); }
	override public /*inline*/ function Uniform4fv(p_location:UniformLocation,p_v:FloatArray):Void 									{ GLES.glUniform4fv(p_location,Std.int(p_v.length/4), p_v.aux); }	
	override public /*inline*/ function Uniform1iv(p_location:UniformLocation, p_v:Int32Array):Void 								{ GLES.glUniform1iv(p_location,p_v.length, p_v.aux); }
	override public /*inline*/ function Uniform2iv(p_location:UniformLocation,p_v:Int32Array):Void 									{ GLES.glUniform2iv(p_location,Std.int(p_v.length/2), p_v.aux); }	
	override public /*inline*/ function Uniform3iv(p_location:UniformLocation,p_v:Int32Array):Void 									{ GLES.glUniform3iv(p_location,Std.int(p_v.length/3), p_v.aux); }	
	override public /*inline*/ function Uniform4iv(p_location:UniformLocation,p_v:Int32Array):Void 									{ GLES.glUniform4iv(p_location,Std.int(p_v.length/4), p_v.aux); }	
	override public /*inline*/ function UniformMatrix2fv(p_location:UniformLocation,p_transpose:Bool,p_v:FloatArray):Void 			{ GLES.glUniformMatrix2fv(p_location,Std.int(p_v.length/4), p_transpose,  p_v.aux); }
	override public /*inline*/ function UniformMatrix3fv(p_location:UniformLocation,p_transpose:Bool,p_v:FloatArray):Void 			{ GLES.glUniformMatrix3fv(p_location,Std.int(p_v.length/9), p_transpose,  p_v.aux); }
	override public /*inline*/ function UniformMatrix4fv(p_location:UniformLocation,p_transpose:Bool,p_v:FloatArray):Void 			{ GLES.glUniformMatrix4fv(p_location,Std.int(p_v.length/16), p_transpose, p_v.aux); }
	
	//Flags
	override public /*inline*/ function BlendFunc(p_src : Int, p_dst : Int):Void 	{ GLES.glBlendFunc(p_src, p_dst); }
	override public /*inline*/ function Disable(p_flag : Int):Void 					{ GLES.glDisable(p_flag); }
	override public /*inline*/ function Enable(p_flag : Int):Void 					{ GLES.glEnable(p_flag); }
	override public /*inline*/ function DepthMask(p_flag : Bool):Void 				{ GLES.glDepthMask(p_flag); }
	override public /*inline*/ function DepthFunc(p_flag : Int):Void 				{ GLES.glDepthFunc(p_flag); }
	override public /*inline*/ function CullFace(p_face : Int):Void 				{ GLES.glCullFace(p_face); }
	override public /*inline*/ function FrontFace(p_face : Int):Void 				{ GLES.glFrontFace(p_face); }
	
	//Screen
	override public /*inline*/ function Clear(p_flag : Int):Void 										{ GLES.glClear(p_flag);	}	
	override public /*inline*/ function ClearDepth(p_value : Float32):Void 								{ GLES.glClearDepthf(p_value); }	
	override public /*inline*/ function ClearColor(p_r: Float32, p_g:Float32, p_b:Float32, p_a:Float32):Void 	{ GLES.glClearColor(p_r, p_g, p_b, p_a); }
	override public /*inline*/ function Viewport(p_x:Int, p_y:Int, p_width:Int, p_height:Int):Void 		{ GLES.glViewport(p_x, p_y, p_width, p_height);	}
	override public /*inline*/ function Scissor(p_x:Int, p_y:Int, p_width:Int, p_height:Int):Void 		{ GLES.glScissor(p_x, p_y, p_width, p_height);	}	
	override public /*inline*/ function ReadPixels(p_x:Int, p_y:Int, p_width:Int, p_height:Int, p_format:Int, p_type:Int, p_pixels:Buffer):Void { GLES.glReadPixels(p_x, p_y, p_width, p_height, p_format, p_type, p_pixels.m_buffer); }
	
	
	
	//Errors and Assert
	override public /*inline*/ function GetErrorCode():Int { return GLES.glGetError(); }
}
#end