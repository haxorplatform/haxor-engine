package haxor.platform.graphics;

import haxor.core.BaseApplication;
import haxor.core.Console;
import haxor.io.Buffer;
import haxor.platform.Types.ArrayBuffer;
import haxor.platform.Types.MeshBufferId;
import haxor.platform.Types.ProgramId;
import haxor.platform.Types.ShaderId;



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
	public function BindBuffer(p_target : Int,p_id : MeshBufferId):Void {  }	
	public function BufferData(p_target:Int,p_data:Buffer,p_mode:Int):Void {  }	
	public function BufferSubData(p_target : Int, p_offset:Int, p_data : Buffer):Void {  }	
	public function CreateBuffer():MeshBufferId { return GL.NULL; }	
	public function DeleteBuffer(p_id : MeshBufferId):Void {  }	
	public function DrawArrays(p_primitive : Int,p_start : Int, p_count : Int):Void { }		
	public function DrawElements(p_primitive : Int, p_count : Int,p_type : Int,p_offset : Int) : Void { }	
	public function EnableVertexAttrib(p_location:Int):Void { }		
	public function DisableVertexAttrib(p_location:Int):Void { }
	public function VertexAttrib3f(p_location : Int,p_x : Float,p_y:Float,p_z : Float):Void { }	
	public function VertexAttrib4f(p_location : Int, p_x : Float, p_y:Float, p_z : Float, p_w : Float):Void { }	
	public function VertexAttribPointer(p_location : Int,p_components_size : Int,p_type : Int,p_normalized : Bool,p_stride : Int, p_offset : Int):Void { }
	
	//Shaders
	public function CompileShader(p_shader : ShaderId):Void { }	
	public function CreateShader(p_type:Int):ShaderId { return GL.NULL; }
	public function DeleteShader(p_shader : ShaderId):Void { }	
	public function DetachShader (p_program : ProgramId,p_shader : ShaderId):Void { }
	public function GetShaderInfoLog(p_shader : ShaderId) : String { return ""; }	
	public function GetShaderParameter(p_shader : ShaderId,p_parameter:Int):Int { return -1; }
	public function ShaderSource(p_shader : ShaderId, p_source : String):Void { }
	public function AttachShader(p_program : ProgramId, p_shader : ShaderId):Void { }	
	public function BindAttribLocation(p_program : ProgramId,p_location : Int,p_name : String):Void { }		
	public function CreateProgram():ProgramId { return GL.NULL; }	
	public function DeleteProgram(p_program : ProgramId):Void { } 	
	public function GetAttribLocation(p_program : ProgramId, p_name : String):Int { return -1; } 
	public function GetProgramInfoLog(p_program : ProgramId):String { return ""; }
	public function GetProgramParameter(p_program : ProgramId, p_parameter:Int):Int { return -1; }
	public function LinkProgram(p_program:ProgramId):Void { }
	public function UseProgram(p_program : ProgramId):Void { }
	
	//Uniforms	
	public function Uniform1f():Void { }
	public function Uniform1fv():Void { }
	public function Uniform1i():Void { }
	public function Uniform1iv():Void { }
	public function Uniform2f():Void { }
	public function Uniform2fv():Void { }
	public function Uniform2i():Void { }
	public function Uniform2iv():Void { }
	public function Uniform3f():Void { }
	public function Uniform3fv():Void { }
	public function Uniform3i():Void { }
	public function Uniform3iv():Void { }
	public function Uniform4f():Void { }
	public function Uniform4fv():Void { }
	public function Uniform4i():Void { }
	public function Uniform4iv():Void { }
	public function UniformMatrix2fv():Void { }
	public function UniformMatrix3fv():Void { }
	public function UniformMatrix4fv():Void { }
	
	//Texture	
	public function ActiveTexture():Void { }	
	public function BindFramebuffer():Void { }
	public function BindRenderbuffer():Void { }
	public function BindTexture():Void { }
	public function CreateFramebuffer():Void { }
	public function CreateTexture():Void { }
	public function DeleteFramebuffer():Void { }
	public function DeleteRenderbuffer():Void { }
	public function DeleteTexture():Void { }	
	public function FramebufferRenderbuffer():Void { }	
	public function FramebufferTexture2D():Void { }	
	public function GenerateMipmap():Void { }
	public function PixelStorei():Void { }
	public function RenderbufferStorage():Void { }	
	public function TexImage2D():Void { }
	public function TexSubImage2D():Void { }
	public function TexStorage2D(p_target:Int,p_num_mipmaps : Int, p_channels : Int,p_width : Int, p_height:Int) { }
	public function TexParameterf():Void{}
	public function TexParameteri():Void{}
	
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
	public function ClearDepth(p_value : Float):Void { 	}	
	public function ClearColor(p_r: Float, p_g:Float, p_b:Float, p_a:Float):Void { 	}	
	public function Viewport(p_x:Int,p_y:Int,p_width:Int,p_height:Int):Void { }
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
	public function LogError():Void { Console.Log(GetError()); }
	
}