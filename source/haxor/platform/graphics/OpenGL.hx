#if (windows || osx || linux)
package haxor.platform.graphics;
import haxor.io.Buffer;
import haxe.io.BytesData;
import haxe.io.Bytes;
import haxe.io.BytesBuffer;
import haxor.io.UInt16Array;
import haxor.io.FloatArray;
import haxor.graphics.Enums.BufferPrimitive;
import cpp.NativeArray;
import haxor.platform.Types.ProgramId;
import haxor.platform.Types.ShaderId;
import cpp.Pointer;
import haxor.platform.Types.ArrayBuffer;
import haxor.platform.Types.MeshBufferId;
import haxor.core.Time;
import haxor.core.Console;
import haxor.platform.graphics.GraphicContext;
import haxor.platform.OSWindow;
import haxor.core.BaseApplication;

/**
 * Wrapper for OpenGL API commands and context management.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class OpenGL extends

#if windows
WinGL
#end

#if linux
#end

#if osx
#end

{	
	
	
	/**
	 * Creates a new OpenGL context.
	 * @param	p_application
	 */
	override public function new(p_application : BaseApplication):Void
	{
		super(p_application);
		m_api = GraphicAPI.OpenGL;
	}
	
	override public function CheckExtensions():Void 
	{
		Focus();
		var extstr : String = "";		
		untyped __cpp__('
		const char *str = (const char *)glGetString(GL_EXTENSIONS);
		int len = strlen(str);
		extstr.__s = str;
		extstr.length = len;				
		');		
		
		var f : Float = 0.0;
		var i : Int = 0;
		
		var exts : Array<String> = extstr.split(" ");				
		for (i in 0...exts.length)
		{
			var n : String = exts[i];			
			n = StringTools.replace(n, "GL_", "");
			if (n == "") continue;
			Console.Log("\t" + n);
			switch(n)
			{
				case "ARB_texture_half_float":					
					GL.HALF_FLOAT 	= 0x8D61;
					GL.TEXTURE_HALF = true;
					
				case "ARB_texture_half_float_linear":					
					GL.TEXTURE_HALF_LINEAR = true;
				
				case "EXT_texture_filter_anisotropic":					
					untyped __cpp__('glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &f);');
					GL.MAX_ANISOTROPY 		= cast f;
					GL.TEXTURE_ANISOTROPY 	= true;
					Console.Log("\t\tMAX_TEXTURE_MAX_ANISOTROPY: " + GL.MAX_ANISOTROPY);
				
				case "ARB_texture_float":					
					GL.TEXTURE_FLOAT = true;	
				
				case "ARB_depth_texture":					
					GL.TEXTURE_DEPTH = true;					
			}			
		}
		
		
		untyped __cpp__('glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &i);');
		GL.MAX_ACTIVE_TEXTURE = i;
		Console.Log("\tMax Active Textures: " + i);				
		
	}
		
	//Attribs
	override public function BindBuffer(p_target:Int, p_id:MeshBufferId):Void 									{ untyped __cpp__('glBindBuffer(p_target,p_id);'); }		
	override public function BufferData(p_target:Int, p_data:Buffer, p_mode:Int):Void 			
	{ 	
		var bl : Int = p_data.byteLength;
		var ba : Bytes = p_data.buffer;
		untyped __cpp__('glBufferData(p_target, bl, (void*)&ba->b[0], p_mode);'); 		
	}	
	override public function BufferSubData(p_target:Int, p_offset:Int, p_data:Buffer):Void 	
	{ 
		var bl : Int 	= p_data.byteLength;
		var ba : Bytes  = p_data.buffer;
		untyped __cpp__('glBufferSubData(p_target, p_offset,bl,(void*)&ba->b[0]);'); 
	}	
	
	override public function CreateBuffer():MeshBufferId 														{ untyped __cpp__('GLuint id; glGenBuffers(1, &id); return id;'); return GL.NULL; }	
	override public function DrawArrays(p_primitive:Int, p_start:Int, p_count:Int):Void 						{ untyped __cpp__('glDrawArrays(p_primitive, p_start, p_count);'); }	
	override public function DrawElements(p_primitive:Int, p_count:Int, p_type:Int, p_offset:Int):Void 			{ untyped __cpp__('glDrawElements(p_primitive, p_count, p_type,(void*)p_offset);'); }	
	override public function DeleteBuffer(p_id:MeshBufferId):Void 												{ untyped __cpp__('GLuint id = p_id; glDeleteBuffers(1, &id);'); }	
	override public function DisableVertexAttrib(p_location:Int):Void 											{ untyped __cpp__('glDisableVertexAttribArray(p_location);'); }		
	override public function EnableVertexAttrib(p_location:Int):Void 											{ untyped __cpp__('glEnableVertexAttribArray(p_location);'); }		
	override public function VertexAttrib3f(p_location:Int, p_x:Float, p_y:Float, p_z:Float):Void 				{ untyped __cpp__('glVertexAttrib3f(p_location,p_x,p_y,p_z);'); }	
	override public function VertexAttrib4f(p_location:Int, p_x:Float, p_y:Float, p_z:Float, p_w:Float):Void    { untyped __cpp__('glVertexAttrib4f(p_location,p_x,p_y,p_z,p_w);'); }	
	override public function VertexAttribPointer(p_location:Int, p_components_size:Int, p_type:Int, p_normalized:Bool, p_stride:Int, p_offset:Int):Void { untyped __cpp__('glVertexAttribPointer(p_location,p_components_size,p_type,p_normalized,p_stride,(void*)p_offset);');	}
	
	//Shaders
	override public function CompileShader(p_shader : ShaderId):Void 															{ untyped __cpp__('glCompileShader(p_shader);'); }	
	override public function CreateShader(p_type:Int):ShaderId 																	{ untyped __cpp__('return glCreateShader(p_type);'); return GL.NULL; }
	override public function DetachShader(p_program : ProgramId, p_shader : ShaderId):Void 					 					{ untyped __cpp__('glDetachShader(p_program, p_shader);'); }
	override public function DeleteShader(p_shader : ShaderId):Void 															{ untyped __cpp__('glDeleteShader(p_shader);');}	
	override public function GetShaderInfoLog(p_shader : ShaderId) : String 													{ untyped __cpp__('char s[1024]; glGetShaderInfoLog(p_shader,1024,0,s); return s;'); return ""; }	
	override public function GetShaderParameter(p_shader : ShaderId,p_parameter:Int):Int 										{ untyped __cpp__('int d[1]; glGetShaderiv(p_shader, p_parameter, d); return d[0];'); return -1; }
	override public function ShaderSource(p_shader : ShaderId, p_source : String):Void 											
	{ 
		var len : Int = p_source.length; 
		untyped __cpp__('
		const char ** str = (const char ** ) &p_source.__s;		
		glShaderSource(p_shader, 1, str, & len);
		'); 
	}
	override public function AttachShader(p_program : ProgramId,p_shader : ShaderId):Void 										{ untyped __cpp__('glAttachShader(p_program, p_shader);');}
	override public function BindAttribLocation(p_program : ProgramId,p_location : Int,p_name : String):Void 					{ untyped __cpp__('glBindAttribLocation(p_program, p_location, p_name.__s);');}		
	override public function CreateProgram():ProgramId 																			{ untyped __cpp__('return glCreateProgram();'); return GL.NULL; }	
	override public function DeleteProgram(p_program : ProgramId):Void 															{ untyped __cpp__('glDeleteProgram(p_program);');} 	
	override public function GetAttribLocation(p_program : ProgramId, p_name : String):Int 										{ untyped __cpp__('return glGetAttribLocation(p_program,p_name.__s);'); return -1; } 
	override public function GetProgramInfoLog(p_program : ProgramId):String 													{ untyped __cpp__('char s[1024]; glGetProgramInfoLog(p_program,1024,0,s); return s;'); return ""; }
	override public function GetProgramParameter(p_program : ProgramId, p_parameter:Int):Int 									{ untyped __cpp__('int d[1]; glGetProgramiv(p_program, p_parameter, d); return d[0];'); return -1; }
	override public function LinkProgram(p_program:ProgramId):Void 																{ untyped __cpp__('glLinkProgram(p_program);'); }
	override public function UseProgram(p_program : ProgramId):Void 															{ untyped __cpp__('glUseProgram(p_program);'); }
	
	//Flags
	override public function BlendFunc(p_src : Int, p_dst : Int):Void 	{ untyped __cpp__('glBlendFunc(p_src, p_dst);'); }
	override public function Disable(p_flag : Int):Void 					{ untyped __cpp__('glDisable(p_flag);'); }
	override public function Enable(p_flag : Int):Void 					{ untyped __cpp__('glEnable(p_flag);'); }
	override public function DepthMask(p_flag : Bool):Void 				{ untyped __cpp__('glDepthMask(p_flag);'); }
	override public function DepthFunc(p_flag : Int):Void 				{ untyped __cpp__('glDepthFunc(p_flag);'); }
	override public function CullFace(p_face : Int):Void 				{ untyped __cpp__('glCullFace(p_face);'); }
	override public function FrontFace(p_face : Int):Void 				{ untyped __cpp__('glFrontFace(p_face);'); }
	
	//Clear
	override public function Clear(p_flag : Int):Void 										{ untyped __cpp__('glClear(p_flag);');	}	
	override public function ClearDepth(p_value : Float):Void 								{ untyped __cpp__('glClearDepthf(p_value);'); }	
	override public function ClearColor(p_r: Float, p_g:Float, p_b:Float, p_a:Float):Void 	{ untyped __cpp__('glClearColor(p_r, p_g, p_b, p_a);'); }
	
	//Errors and Assert
	override public function GetErrorCode():Int { untyped __cpp__('return glGetError();');	return 0; }
	
}



#end