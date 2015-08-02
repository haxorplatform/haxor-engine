package haxor.graphics;

import haxor.core.BaseApplication;
import haxor.core.Console;
import haxor.io.Buffer;
import haxor.io.FloatArray;
import haxor.io.Int32Array;
import haxor.io.UInt16Array;
import haxor.platform.Types.ArrayBuffer;
import haxor.platform.Types.Float32;
import haxor.platform.Types.FrameBufferId;
import haxor.platform.Types.MeshBufferId;
import haxor.platform.Types.ProgramId;
import haxor.platform.Types.RenderBufferId;
import haxor.platform.Types.ShaderId;
import haxor.platform.Types.TextureId;
import haxor.platform.Types.UniformLocation;
import haxor.platform.Types.VAOId;



/**
 * API Enumeration
 */
enum GraphicAPI
{	
	None;
	OpenGL;
	OpenGLES;
	//DirectX;
	WebGL;
}

/**
 * Base class that describes a Graphics Rendering context with common graphic operations.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class GraphicContext
{
	
	/**
	 * See GL.
	 */
	public var api(get_api,never) : GraphicAPI;	
	private function get_api():GraphicAPI { return m_api; }
	private var m_api : GraphicAPI;

	/**
	 * Reference to the application that contains this context.
	 */
	private var m_application : BaseApplication;
	
	/**
	 * Creates a new GraphicContext.
	 */
	public function new(p_application : BaseApplication) 
	{
		m_api 			= GraphicAPI.None;
		m_application 	= p_application;
	}
		
	/**
	 * Callback to treat extensions case by case.
	 */
	public function CheckExtensions():Void { }
	
	//Misc
	public function Destroy():Void { }			
	public function Flush():Void { }
	public function Focus():Void { }	
	public function Resize():Void { }	
	
	//Attribs
	public function BindBuffer(p_target : Int, p_id : MeshBufferId):Void {  }
	public function BindVAO(p_id : VAOId):Void {  }
	public function BufferData(p_target:Int,p_data:Buffer,p_mode:Int):Void {  }	
	public function BufferSubData(p_target : Int, p_offset:Int, p_data : Buffer):Void {  }	
	public function CreateBuffer():MeshBufferId { return GL.INVALID; }	
	public function CreateVAO():VAOId { return GL.INVALID;  }
	public function DeleteBuffer(p_id : MeshBufferId):Void {  }	
	public function DeleteVAO(p_id : VAOId):Void {  }		
	public function DrawArrays(p_primitive : Int,p_start : Int, p_count : Int):Void { }		
	public function DrawElements(p_primitive : Int, p_count : Int,p_type : Int,p_offset : Int) : Void { }	
	public function EnableVertexAttrib(p_location:Int):Void { }		
	public function DisableVertexAttrib(p_location:Int):Void { }
	public function VertexAttrib1f(p_location : Int,p_x : Float32):Void { }	
	public function VertexAttrib2f(p_location : Int,p_x : Float32,p_y:Float32):Void { }	
	public function VertexAttrib3f(p_location : Int,p_x : Float32,p_y:Float32,p_z : Float32):Void { }	
	public function VertexAttrib4f(p_location : Int, p_x : Float32, p_y:Float32, p_z : Float32, p_w : Float32):Void { }	
	public function VertexAttribPointer(p_location : Int,p_components_size : Int,p_type : Int,p_normalized : Bool,p_stride : Int, p_offset : Int):Void { }
	
	//Shaders
	public function CompileShader(p_shader : ShaderId):Void { }	
	public function CreateShader(p_type:Int):ShaderId { return GL.INVALID; }
	public function DeleteShader(p_shader : ShaderId):Void { }	
	public function DetachShader (p_program : ProgramId,p_shader : ShaderId):Void { }
	public function GetShaderInfoLog(p_shader : ShaderId) : String { return ""; }	
	public function GetShaderParameter(p_shader : ShaderId,p_parameter:Int):Int { return -1; }
	public function ShaderSource(p_shader : ShaderId, p_source : String):Void { }
	public function AttachShader(p_program : ProgramId, p_shader : ShaderId):Void { }	
	public function BindAttribLocation(p_program : ProgramId,p_location : Int,p_name : String):Void { }		
	public function CreateProgram():ProgramId { return GL.INVALID; }	
	public function DeleteProgram(p_program : ProgramId):Void { } 	
	public function GetAttribLocation(p_program : ProgramId, p_name : String):Int { return -1; }
	public function GetUniformLocation(p_program : ProgramId, p_name : String):UniformLocation { return GL.INVALID; }	
	public function GetProgramInfoLog(p_program : ProgramId):String { return ""; }
	public function GetProgramParameter(p_program : ProgramId, p_parameter:Int):Int { return -1; }
	public function LinkProgram(p_program:ProgramId):Void { }
	public function UseProgram(p_program : ProgramId):Void { }
	
	//Uniforms	
	public function Uniform1f(p_location:UniformLocation,p_x:Float32):Void 										{ }	
	public function Uniform2f(p_location:UniformLocation,p_x:Float32, p_y:Float32):Void 							{ }	
	public function Uniform3f(p_location:UniformLocation,p_x:Float32, p_y:Float32,p_z:Float32):Void 					{ }		
	public function Uniform4f(p_location:UniformLocation,p_x:Float32, p_y:Float32,p_z:Float32,p_w:Float32):Void 		{ }		
	public function Uniform1i(p_location:UniformLocation,p_x:Int):Void 											{ }	
	public function Uniform2i(p_location:UniformLocation,p_x:Int,p_y:Int):Void 									{ }	
	public function Uniform3i(p_location:UniformLocation,p_x:Int,p_y:Int,p_z:Int):Void 							{ }		
	public function Uniform4i(p_location:UniformLocation,p_x:Int,p_y:Int,p_z:Int,p_w:Int):Void 					{ }	
	public function Uniform1fv(p_location:UniformLocation,p_v:FloatArray):Void 									{ }
	public function Uniform2fv(p_location:UniformLocation,p_v:FloatArray):Void									{ }
	public function Uniform3fv(p_location:UniformLocation,p_v:FloatArray):Void 									{ }
	public function Uniform4fv(p_location:UniformLocation,p_v:FloatArray):Void 									{ }	
	public function Uniform1iv(p_location:UniformLocation,p_v:Int32Array):Void 									{ }
	public function Uniform2iv(p_location:UniformLocation,p_v:Int32Array):Void 									{ }	
	public function Uniform3iv(p_location:UniformLocation,p_v:Int32Array):Void 									{ }	
	public function Uniform4iv(p_location:UniformLocation,p_v:Int32Array):Void 									{ }	
	public function UniformMatrix2fv(p_location:UniformLocation,p_transpose:Bool,p_v:FloatArray):Void			{ }
	public function UniformMatrix3fv(p_location:UniformLocation,p_transpose:Bool,p_v:FloatArray):Void			{ }
	public function UniformMatrix4fv(p_location:UniformLocation,p_transpose:Bool,p_v:FloatArray):Void			{ }
	
	//Texture	
	public function ActiveTexture(p_slot:Int):Void { }	
	public function BindFramebuffer(p_target:Int,p_id:FrameBufferId):Void { }
	public function BindRenderbuffer(p_target:Int,p_id:RenderBufferId):Void { }
	public function BindTexture(p_target:Int,p_id:TextureId):Void { }
	public function CreateFramebuffer():FrameBufferId { return GL.INVALID; }
	public function CreateRenderbuffer():RenderBufferId { return GL.INVALID; }	
	public function CreateTexture():TextureId { return GL.INVALID; }	
	public function DeleteFramebuffer(p_id:FrameBufferId):Void { }
	public function DeleteRenderbuffer(p_id:RenderBufferId):Void { }
	public function DeleteTexture(p_id:TextureId):Void { }		
	public function FramebufferRenderbuffer(p_target:Int, p_attachment:Int, p_renderbuffer_target:Int, p_renderbuffer_id:RenderBufferId):Void { }		
	public function FramebufferTexture2D(p_target:Int, p_attachment:Int, p_texture_target:Int, p_texture_id:TextureId, p_miplevel:Int):Void { }		
	public function GenerateMipmap(p_target:Int):Void { }	
	public function PixelStorei(p_parameter:Int, p_value:Int):Void { }	
	public function RenderbufferStorage(p_target:Int, p_format:Int, p_width:Int, p_height:Int):Void { }		
	public function TexImage2DAlloc(p_target:Int, p_level:Int, p_internal_format:Int, p_width:Int, p_height:Int, p_border:Int, p_format:Int, p_channel_type:Int):Void { }	
	public function TexImage2D(p_target:Int, p_level:Int, p_internal_format:Int, p_width:Int, p_height:Int, p_border:Int, p_format:Int, p_channel_type:Int, p_data:Buffer):Void { }	
	public function TexSubImage2D(p_target:Int, p_level:Int, p_x:Int, p_y:Int, p_width:Int, p_height:Int, p_format:Int, p_channel_type:Int, p_data:Buffer):Void { }	
	public function TexStorage2D(p_target:Int, p_num_mipmaps : Int, p_channels : Int, p_width : Int, p_height:Int) { }	
	public function TexParameterf(p_target:Int, p_parameter:Int, p_value:Float32):Void { }	
	public function TexParameteri(p_target:Int, p_parameter:Int, p_value:Int):Void { }
	
	
	//Flags
	public function BlendFunc(p_src : Int,p_dst : Int):Void { }
	public function Disable(p_flag : Int):Void { }
	public function Enable(p_flag : Int):Void { }
	public function DepthMask(p_flag : Bool):Void { }
	public function DepthFunc(p_flag : Int):Void { }
	public function CullFace(p_face : Int):Void { }
	public function FrontFace(p_face : Int):Void { }
	
	//Screen
	public function Clear(p_flag : Int):Void { 	}	
	public function ClearDepth(p_value : Float32):Void { 	}	
	public function ClearColor(p_r: Float32, p_g:Float32, p_b:Float32, p_a:Float32):Void { 	}	
	public function Viewport(p_x:Int,p_y:Int,p_width:Int,p_height:Int):Void { }
	public function Scissor(p_x:Int, p_y:Int, p_width:Int, p_height:Int):Void 		{ }
	public function ReadPixels(p_x:Int,p_y:Int,p_width:Int,p_height:Int,p_format:Int,p_type:Int,p_pixels:Buffer):Void { }
	
	
	
	//Error and Assert
	public function GetErrorCode():Int { return 0; }	
	public function GetErrorString(p_code : Int):String
	{
		switch(p_code)
		{
			case GL.NO_ERROR_GL:					return "";
			case GL.INVALID_ENUM: 					return "Invalid Enum.";
			case GL.INVALID_VALUE:					return "Numeric argument is out of range.";
			case GL.INVALID_OPERATION:				return "Operation not allowed in the current state.";
			case GL.INVALID_FRAMEBUFFER_OPERATION:	return "Write or Read in FrameBuffer not complete.";
			case GL.OUT_OF_MEMORY:					return "Out of Memory.";
		}	
		return "Unknown Error.";
	}	
	public function GetError():String { return GetErrorString(GetErrorCode()); }	
	public function Assert(p_log : String):Void	
	{ 		
		var err : Int = GetErrorCode(); 
		if (err != 0) throw "GraphicContext> " + GetErrorString(err) + " - " + p_log; 		
	}	
	public inline function LogError():Void { trace(GetError()); }
	
}