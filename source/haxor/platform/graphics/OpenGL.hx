#if (windows || osx || linux)
package haxor.platform.graphics;
import cpp.NativeArray;
import cpp.Pointer;
import haxe.io.Bytes;
import haxe.io.BytesBuffer;
import haxe.io.BytesData;
import haxor.core.BaseApplication;
import haxor.core.Console;
import haxor.core.Time;
import haxor.graphics.GL;
import haxor.graphics.GraphicContext;
import haxor.io.Buffer;
import haxor.io.FloatArray;
import haxor.io.Int32Array;
import haxor.io.UInt16Array;
import haxor.platform.OSWindow;
import haxor.platform.Types.ArrayBuffer;
import haxor.platform.Types.FrameBufferId;
import haxor.platform.Types.MeshBufferId;
import haxor.platform.Types.ProgramId;
import haxor.platform.Types.RenderBufferId;
import haxor.platform.Types.ShaderId;
import haxor.platform.Types.TextureId;
import haxor.platform.Types.UniformLocation;

/**
 * Wrapper for OpenGL API commands and context management.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class OpenGL extends

#if windows
haxor.platform.windows.graphics.WinGL
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
					GL.MAX_TEXTURE_ANISOTROPY 		= cast f;
					GL.TEXTURE_ANISOTROPY_ENABLED 	= true;
					Console.Log("\t\tMAX_TEXTURE_MAX_ANISOTROPY: " + GL.MAX_TEXTURE_ANISOTROPY);
				
				case "ARB_texture_float":					
					GL.TEXTURE_FLOAT = true;	
				
				case "ARB_depth_texture":					
					GL.TEXTURE_DEPTH_ENABLED = true;					
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
	
	override public function CreateBuffer():MeshBufferId 														{ untyped __cpp__('GLuint id; glGenBuffers(1, &id); return id;'); return GL.INVALID; }	
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
	override public function CreateShader(p_type:Int):ShaderId 																	{ untyped __cpp__('return glCreateShader(p_type);'); return GL.INVALID; }
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
	override public function CreateProgram():ProgramId 																			{ untyped __cpp__('return glCreateProgram();'); return GL.INVALID; }	
	override public function DeleteProgram(p_program : ProgramId):Void 															{ untyped __cpp__('glDeleteProgram(p_program);');} 	
	override public function GetAttribLocation(p_program : ProgramId, p_name : String):Int 										{ untyped __cpp__('return glGetAttribLocation(p_program,p_name.__s);'); return -1; } 
	override public function GetUniformLocation(p_program : ProgramId, p_name : String):UniformLocation 						{ untyped __cpp__('return glGetUniformLocation(p_program,p_name.__s);'); return -1; }
	override public function GetProgramInfoLog(p_program : ProgramId):String 													{ untyped __cpp__('char s[1024]; glGetProgramInfoLog(p_program,1024,0,s); return s;'); return ""; }
	override public function GetProgramParameter(p_program : ProgramId, p_parameter:Int):Int 									{ untyped __cpp__('int d[1]; glGetProgramiv(p_program, p_parameter, d); return d[0];'); return -1; }
	override public function LinkProgram(p_program:ProgramId):Void 																{ untyped __cpp__('glLinkProgram(p_program);'); }
	override public function UseProgram(p_program : ProgramId):Void 															{ untyped __cpp__('glUseProgram(p_program);'); }
	
	//Textures
	override public function ActiveTexture(p_slot:Int):Void 														{ untyped __cpp__('glActiveTexture(p_slot);'); }	
	override public function BindFramebuffer(p_target:Int, p_id:FrameBufferId):Void 								{ untyped __cpp__('glBindFramebuffer(p_target, p_id);'); }
	override public function BindRenderbuffer(p_target:Int, p_id:RenderBufferId):Void								{ untyped __cpp__('glBindRenderbuffer(p_target, p_id);'); }
	override public function BindTexture(p_target:Int, p_id:TextureId):Void 										{ untyped __cpp__('glBindTexture(p_target, p_id);'); }
	override public function CreateFramebuffer():FrameBufferId														{ untyped __cpp__('unsigned int id; glGenFramebuffers(1, &id);   return id;'); return GL.INVALID; }
	override public function CreateRenderbuffer():RenderBufferId 													{ untyped __cpp__('unsigned int id; glGenRenderbuffers(1, &id);  return id;'); return GL.INVALID; }	
	override public function CreateTexture():TextureId 																{ untyped __cpp__('unsigned int id; glGenTextures(1, &id);  	 return id;'); return GL.INVALID; }	
	override public function DeleteFramebuffer(p_id:FrameBufferId):Void 											{ untyped __cpp__('GLuint id = p_id; glDeleteFramebuffers(1, &id);'); }
	override public function DeleteRenderbuffer(p_id:RenderBufferId):Void 											{ untyped __cpp__('GLuint id = p_id; glDeleteRenderbuffers(1,&id);'); }
	override public function DeleteTexture(p_id:TextureId):Void 													{ untyped __cpp__('GLuint id = p_id; glDeleteTextures(1,&id);'); }		
	override public function FramebufferRenderbuffer(p_target:Int, p_attachment:Int, p_renderbuffer_target:Int, p_renderbuffer_id:RenderBufferId):Void 			
																													{ untyped __cpp__('glFramebufferRenderbuffer(p_target, p_attachment, p_renderbuffer_target, p_renderbuffer_id);');  }		
	override public function FramebufferTexture2D(p_target:Int, p_attachment:Int, p_texture_target:Int, p_texture_id:TextureId, p_miplevel:Int):Void 					
																													{ untyped __cpp__('glFramebufferTexture2D(p_target, p_attachment, p_texture_target, p_texture_id, p_miplevel);'); }		
	override public function GenerateMipmap(p_target:Int):Void 														{ untyped __cpp__('glGenerateMipmap(p_target);'); }	
	override public function PixelStorei(p_parameter:Int, p_value:Int):Void 										{ untyped __cpp__('glPixelStorei(p_parameter, p_value);'); }	
	override public function RenderbufferStorage(p_target:Int, p_format:Int, p_width:Int, p_height:Int):Void 		{ untyped __cpp__('glRenderbufferStorage(p_target, p_format, p_width, p_height);'); }		
	override public function TexImage2D(p_target:Int, p_level:Int, p_internal_format:Int, p_width:Int, p_height:Int, p_border:Int, p_format:Int, p_channel_type:Int, p_data:Buffer):Void 																													
	{ 		
		var ba : Bytes = p_data.buffer; 
		untyped __cpp__('glTexImage2D(p_target, p_level, p_internal_format,p_width,p_height,p_border, p_format, p_channel_type,(void*)&ba->b[0]);'); 
	}	
	override public function TexImage2DAlloc(p_target:Int, p_level:Int, p_internal_format:Int, p_width:Int, p_height:Int, p_border:Int, p_format:Int, p_channel_type:Int):Void 																												
	{
		untyped __cpp__('glTexImage2D(p_target, p_level, p_internal_format,p_width,p_height,p_border, p_format, p_channel_type,(void*)NULL);');
	}
	override public function TexSubImage2D(p_target:Int, p_level:Int, p_x:Int, p_y:Int, p_width:Int, p_height:Int, p_format:Int, p_channel_type:Int, p_data:Buffer):Void 																													
	{ 		
		var ba : Bytes = p_data.buffer;
		var off : Int = p_data.m_offset;
		untyped __cpp__('glTexSubImage2D(p_target, p_level, p_x, p_y,p_width,p_height,p_format, p_channel_type,(void*)((&ba->b[0])+off));'); 
	}		
	override public function TexParameterf(p_target:Int, p_parameter:Int, p_value:Float):Void 						{ untyped __cpp__('glTexParameterf(p_target, p_parameter, p_value);'); }	
	override public function TexParameteri(p_target:Int, p_parameter:Int, p_value:Int):Void 						{ untyped __cpp__('glTexParameteri(p_target, p_parameter, p_value);'); }
	
	//Uniforms
	override public function Uniform1f(p_location:UniformLocation, p_x:Float):Void 										{ untyped __cpp__('glUniform1f(p_location, p_x);'); }		
	override public function Uniform2f(p_location:UniformLocation, p_x:Float, p_y:Float):Void 							{ untyped __cpp__('glUniform2f(p_location, p_x, p_y);'); }		
	override public function Uniform3f(p_location:UniformLocation, p_x:Float, p_y:Float, p_z:Float):Void 				{ untyped __cpp__('glUniform3f(p_location, p_x, p_y, p_z);'); }	
	override public function Uniform4f(p_location:UniformLocation, p_x:Float, p_y:Float, p_z:Float, p_w:Float):Void 	{ untyped __cpp__('glUniform4f(p_location, p_x, p_y, p_z, p_w);'); }			
	override public function Uniform1i(p_location:UniformLocation,p_x:Int):Void 										{ untyped __cpp__('glUniform1i(p_location, p_x);'); }			
	override public function Uniform2i(p_location:UniformLocation,p_x:Int,p_y:Int):Void 								{ untyped __cpp__('glUniform2i(p_location, p_x, p_y);'); }			
	override public function Uniform3i(p_location:UniformLocation,p_x:Int,p_y:Int,p_z:Int):Void 						{ untyped __cpp__('glUniform3i(p_location, p_x, p_y, p_z);'); }			
	override public function Uniform4i(p_location:UniformLocation,p_x:Int,p_y:Int,p_z:Int,p_w:Int):Void 				{ untyped __cpp__('glUniform4i(p_location, p_x, p_y, p_z, p_w);'); }	
	override public function Uniform1fv(p_location:UniformLocation, p_v:FloatArray):Void 								{ var ba : Bytes = p_v.buffer; var len:Int = p_v.length; untyped __cpp__('glUniform1fv(p_location,len,(float*)&ba->b[0]);'); }
	override public function Uniform2fv(p_location:UniformLocation,p_v:FloatArray):Void									{ var ba : Bytes = p_v.buffer; var len:Int = p_v.length; untyped __cpp__('glUniform2fv(p_location,len/2,(float*)&ba->b[0]);'); }
	override public function Uniform3fv(p_location:UniformLocation,p_v:FloatArray):Void 								{ var ba : Bytes = p_v.buffer; var len:Int = p_v.length; untyped __cpp__('glUniform3fv(p_location,len/3,(float*)&ba->b[0]);'); }
	override public function Uniform4fv(p_location:UniformLocation,p_v:FloatArray):Void 								{ var ba : Bytes = p_v.buffer; var len:Int = p_v.length; untyped __cpp__('glUniform4fv(p_location,len/4,(float*)&ba->b[0]);'); }
	override public function Uniform1iv(p_location:UniformLocation, p_v:Int32Array):Void 								
	{ 	var ba : Bytes  = p_v.buffer; var len :Int = p_v.length; untyped __cpp__('int * il = new int[len]; long * b = (long*)(&ba->b[0]); for (int i = 0; i < len; i++) il[i] = (int) b; glUniform1iv(p_location, len, il); delete[] il;'); }
	override public function Uniform2iv(p_location:UniformLocation, p_v:Int32Array):Void
	{ 	var ba : Bytes  = p_v.buffer; var len :Int = p_v.length; untyped __cpp__('int * il = new int[len]; long * b = (long*)(&ba->b[0]); for (int i = 0; i < len; i++) il[i] = (int) b; glUniform2iv(p_location, len/2, il); delete[] il;'); }
	override public function Uniform3iv(p_location:UniformLocation, p_v:Int32Array):Void
	{ 	var ba : Bytes  = p_v.buffer; var len :Int = p_v.length; untyped __cpp__('int * il = new int[len]; long * b = (long*)(&ba->b[0]); for (int i = 0; i < len; i++) il[i] = (int) b; glUniform3iv(p_location, len/3, il); delete[] il;'); }
	override public function Uniform4iv(p_location:UniformLocation, p_v:Int32Array):Void
	{ 	var ba : Bytes  = p_v.buffer; var len :Int = p_v.length; untyped __cpp__('int * il = new int[len]; long * b = (long*)(&ba->b[0]); for (int i = 0; i < len; i++) il[i] = (int) b; glUniform4iv(p_location, len/4, il); delete[] il;'); }
	
	override public function UniformMatrix2fv(p_location:UniformLocation,p_transpose:Bool,p_v:FloatArray):Void 			{ var ba : Bytes = p_v.buffer; var len:Int = p_v.length; untyped __cpp__('glUniformMatrix2fv(p_location,len/4,  p_transpose, (float*)&ba->b[0]);'); }
	override public function UniformMatrix3fv(p_location:UniformLocation,p_transpose:Bool,p_v:FloatArray):Void 			{ var ba : Bytes = p_v.buffer; var len:Int = p_v.length; untyped __cpp__('glUniformMatrix3fv(p_location,len/9,  p_transpose, (float*)&ba->b[0]);'); }
	override public function UniformMatrix4fv(p_location:UniformLocation,p_transpose:Bool,p_v:FloatArray):Void 			{ var ba : Bytes = p_v.buffer; var len:Int = p_v.length; untyped __cpp__('glUniformMatrix4fv(p_location,len/16, p_transpose, (float*)&ba->b[0]);'); }
	
	//Flags
	override public function BlendFunc(p_src : Int, p_dst : Int):Void 	{ untyped __cpp__('glBlendFunc(p_src, p_dst);'); }
	override public function Disable(p_flag : Int):Void 				{ untyped __cpp__('glDisable(p_flag);'); }
	override public function Enable(p_flag : Int):Void 					{ untyped __cpp__('glEnable(p_flag);'); }
	override public function DepthMask(p_flag : Bool):Void 				{ untyped __cpp__('glDepthMask(p_flag);'); }
	override public function DepthFunc(p_flag : Int):Void 				{ untyped __cpp__('glDepthFunc(p_flag);'); }
	override public function CullFace(p_face : Int):Void 				{ untyped __cpp__('glCullFace(p_face);'); }
	override public function FrontFace(p_face : Int):Void 				{ untyped __cpp__('glFrontFace(p_face);'); }
	
	
	//Screen
	override public function Clear(p_flag : Int):Void 										{ untyped __cpp__('glClear(p_flag);');	}	
	override public function ClearDepth(p_value : Float):Void 								{ untyped __cpp__('glClearDepthf(p_value);'); }	
	override public function ClearColor(p_r: Float, p_g:Float, p_b:Float, p_a:Float):Void 	{ untyped __cpp__('glClearColor(p_r, p_g, p_b, p_a);'); }
	override public function Viewport(p_x:Int, p_y:Int, p_width:Int, p_height:Int):Void 	{ untyped __cpp__('glViewport(p_x, p_y, p_width, p_height);');	}
	override public function Scissor(p_x:Int, p_y:Int, p_width:Int, p_height:Int):Void 		{ untyped __cpp__('glScissor(p_x, p_y, p_width, p_height);');	}
	override public function ReadPixels(p_x:Int, p_y:Int, p_width:Int, p_height:Int, p_format:Int, p_type:Int, p_pixels:Buffer):Void 
																							{ var ba : Bytes = p_pixels.buffer; untyped __cpp__('glReadPixels(p_x, p_y, p_width, p_height, p_format, p_type, (void*)(&ba->b[0]));'); }
	
	//Errors and Assert
	override public function GetErrorCode():Int { untyped __cpp__('return glGetError();');	return 0; }
	
}



#end