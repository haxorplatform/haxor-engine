package haxor.platform.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class GraphicContext extends haxe.lang.HxObject
{
	public    GraphicContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    GraphicContext(haxor.core.BaseApplication p_application)
	{
		haxor.platform.graphics.GraphicContext.__hx_ctor_haxor_platform_graphics_GraphicContext(this, p_application);
	}
	
	
	public static   void __hx_ctor_haxor_platform_graphics_GraphicContext(haxor.platform.graphics.GraphicContext __temp_me42412, haxor.core.BaseApplication p_application)
	{
		__temp_me42412.m_api = haxor.platform.graphics.GraphicAPI.None;
		__temp_me42412.m_application = p_application;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.graphics.GraphicContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.graphics.GraphicContext(((haxor.core.BaseApplication) (arr.__get(0)) ));
	}
	
	
	
	
	public   haxor.platform.graphics.GraphicAPI get_api()
	{
		return this.m_api;
	}
	
	
	public  haxor.platform.graphics.GraphicAPI m_api;
	
	public  haxor.core.BaseApplication m_application;
	
	public   void CheckExtensions()
	{
		{
		}
		
	}
	
	
	public   void Destroy()
	{
		{
		}
		
	}
	
	
	public   void Flush()
	{
		{
		}
		
	}
	
	
	public   void Focus()
	{
		{
		}
		
	}
	
	
	public   void Resize()
	{
		{
		}
		
	}
	
	
	public   void BindBuffer(int p_target, int p_id)
	{
		{
		}
		
	}
	
	
	public   void BufferData(int p_target, haxor.io.Buffer p_data, int p_mode)
	{
		{
		}
		
	}
	
	
	public   void BufferSubData(int p_target, int p_offset, haxor.io.Buffer p_data)
	{
		{
		}
		
	}
	
	
	public   int CreateBuffer()
	{
		return haxor.platform.graphics.GL.INVALID;
	}
	
	
	public   void DeleteBuffer(int p_id)
	{
		{
		}
		
	}
	
	
	public   void DrawArrays(int p_primitive, int p_start, int p_count)
	{
		{
		}
		
	}
	
	
	public   void DrawElements(int p_primitive, int p_count, int p_type, int p_offset)
	{
		{
		}
		
	}
	
	
	public   void EnableVertexAttrib(int p_location)
	{
		{
		}
		
	}
	
	
	public   void DisableVertexAttrib(int p_location)
	{
		{
		}
		
	}
	
	
	public   void VertexAttrib3f(int p_location, double p_x, double p_y, double p_z)
	{
		{
		}
		
	}
	
	
	public   void VertexAttrib4f(int p_location, double p_x, double p_y, double p_z, double p_w)
	{
		{
		}
		
	}
	
	
	public   void VertexAttribPointer(int p_location, int p_components_size, int p_type, boolean p_normalized, int p_stride, int p_offset)
	{
		{
		}
		
	}
	
	
	public   void CompileShader(int p_shader)
	{
		{
		}
		
	}
	
	
	public   int CreateShader(int p_type)
	{
		return haxor.platform.graphics.GL.INVALID;
	}
	
	
	public   void DeleteShader(int p_shader)
	{
		{
		}
		
	}
	
	
	public   void DetachShader(int p_program, int p_shader)
	{
		{
		}
		
	}
	
	
	public   java.lang.String GetShaderInfoLog(int p_shader)
	{
		return "";
	}
	
	
	public   int GetShaderParameter(int p_shader, int p_parameter)
	{
		return -1;
	}
	
	
	public   void ShaderSource(int p_shader, java.lang.String p_source)
	{
		{
		}
		
	}
	
	
	public   void AttachShader(int p_program, int p_shader)
	{
		{
		}
		
	}
	
	
	public   void BindAttribLocation(int p_program, int p_location, java.lang.String p_name)
	{
		{
		}
		
	}
	
	
	public   int CreateProgram()
	{
		return haxor.platform.graphics.GL.INVALID;
	}
	
	
	public   void DeleteProgram(int p_program)
	{
		{
		}
		
	}
	
	
	public   int GetAttribLocation(int p_program, java.lang.String p_name)
	{
		return -1;
	}
	
	
	public   int GetUniformLocation(int p_program, java.lang.String p_name)
	{
		return haxor.platform.graphics.GL.INVALID;
	}
	
	
	public   java.lang.String GetProgramInfoLog(int p_program)
	{
		return "";
	}
	
	
	public   int GetProgramParameter(int p_program, int p_parameter)
	{
		return -1;
	}
	
	
	public   void LinkProgram(int p_program)
	{
		{
		}
		
	}
	
	
	public   void UseProgram(int p_program)
	{
		{
		}
		
	}
	
	
	public   void Uniform1f(int p_location, double p_x)
	{
		{
		}
		
	}
	
	
	public   void Uniform2f(int p_location, double p_x, double p_y)
	{
		{
		}
		
	}
	
	
	public   void Uniform3f(int p_location, double p_x, double p_y, double p_z)
	{
		{
		}
		
	}
	
	
	public   void Uniform4f(int p_location, double p_x, double p_y, double p_z, double p_w)
	{
		{
		}
		
	}
	
	
	public   void Uniform1i(int p_location, int p_x)
	{
		{
		}
		
	}
	
	
	public   void Uniform2i(int p_location, int p_x, int p_y)
	{
		{
		}
		
	}
	
	
	public   void Uniform3i(int p_location, int p_x, int p_y, int p_z)
	{
		{
		}
		
	}
	
	
	public   void Uniform4i(int p_location, int p_x, int p_y, int p_z, int p_w)
	{
		{
		}
		
	}
	
	
	public   void Uniform1fv(int p_location, haxor.io.FloatArray p_v)
	{
		{
		}
		
	}
	
	
	public   void Uniform2fv(int p_location, haxor.io.FloatArray p_v)
	{
		{
		}
		
	}
	
	
	public   void Uniform3fv(int p_location, haxor.io.FloatArray p_v)
	{
		{
		}
		
	}
	
	
	public   void Uniform4fv(int p_location, haxor.io.FloatArray p_v)
	{
		{
		}
		
	}
	
	
	public   void Uniform1iv(int p_location, haxor.io.Int32Array p_v)
	{
		{
		}
		
	}
	
	
	public   void Uniform2iv(int p_location, haxor.io.Int32Array p_v)
	{
		{
		}
		
	}
	
	
	public   void Uniform3iv(int p_location, haxor.io.Int32Array p_v)
	{
		{
		}
		
	}
	
	
	public   void Uniform4iv(int p_location, haxor.io.Int32Array p_v)
	{
		{
		}
		
	}
	
	
	public   void UniformMatrix2fv(int p_location, boolean p_transpose, haxor.io.FloatArray p_v)
	{
		{
		}
		
	}
	
	
	public   void UniformMatrix3fv(int p_location, boolean p_transpose, haxor.io.FloatArray p_v)
	{
		{
		}
		
	}
	
	
	public   void UniformMatrix4fv(int p_location, boolean p_transpose, haxor.io.FloatArray p_v)
	{
		{
		}
		
	}
	
	
	public   void ActiveTexture(int p_slot)
	{
		{
		}
		
	}
	
	
	public   void BindFramebuffer(int p_target, int p_id)
	{
		{
		}
		
	}
	
	
	public   void BindRenderbuffer(int p_target, int p_id)
	{
		{
		}
		
	}
	
	
	public   void BindTexture(int p_target, int p_id)
	{
		{
		}
		
	}
	
	
	public   int CreateFramebuffer()
	{
		return haxor.platform.graphics.GL.INVALID;
	}
	
	
	public   int CreateRenderbuffer()
	{
		return haxor.platform.graphics.GL.INVALID;
	}
	
	
	public   int CreateTexture()
	{
		return haxor.platform.graphics.GL.INVALID;
	}
	
	
	public   void DeleteFramebuffer(int p_id)
	{
		{
		}
		
	}
	
	
	public   void DeleteRenderbuffer(int p_id)
	{
		{
		}
		
	}
	
	
	public   void DeleteTexture(int p_id)
	{
		{
		}
		
	}
	
	
	public   void FramebufferRenderbuffer(int p_target, int p_attachment, int p_renderbuffer_target, int p_renderbuffer_id)
	{
		{
		}
		
	}
	
	
	public   void FramebufferTexture2D(int p_target, int p_attachment, int p_texture_target, int p_texture_id, int p_miplevel)
	{
		{
		}
		
	}
	
	
	public   void GenerateMipmap(int p_target)
	{
		{
		}
		
	}
	
	
	public   void PixelStorei(int p_parameter, int p_value)
	{
		{
		}
		
	}
	
	
	public   void RenderbufferStorage(int p_target, int p_format, int p_width, int p_height)
	{
		{
		}
		
	}
	
	
	public   void TexImage2DAlloc(int p_target, int p_level, int p_internal_format, int p_width, int p_height, int p_border, int p_format, int p_channel_type)
	{
		{
		}
		
	}
	
	
	public   void TexImage2D(int p_target, int p_level, int p_internal_format, int p_width, int p_height, int p_border, int p_format, int p_channel_type, haxor.io.Buffer p_data)
	{
		{
		}
		
	}
	
	
	public   void TexSubImage2D(int p_target, int p_level, int p_x, int p_y, int p_width, int p_height, int p_format, int p_channel_type, haxor.io.Buffer p_data)
	{
		{
		}
		
	}
	
	
	public   void TexStorage2D(int p_target, int p_num_mipmaps, int p_channels, int p_width, int p_height)
	{
		{
		}
		
	}
	
	
	public   void TexParameterf(int p_target, int p_parameter, double p_value)
	{
		{
		}
		
	}
	
	
	public   void TexParameteri(int p_target, int p_parameter, int p_value)
	{
		{
		}
		
	}
	
	
	public   void BlendFunc(int p_src, int p_dst)
	{
		{
		}
		
	}
	
	
	public   void Disable(int p_flag)
	{
		{
		}
		
	}
	
	
	public   void Enable(int p_flag)
	{
		{
		}
		
	}
	
	
	public   void DepthMask(boolean p_flag)
	{
		{
		}
		
	}
	
	
	public   void DepthFunc(int p_flag)
	{
		{
		}
		
	}
	
	
	public   void CullFace(int p_face)
	{
		{
		}
		
	}
	
	
	public   void FrontFace(int p_face)
	{
		{
		}
		
	}
	
	
	public   void Clear(int p_flag)
	{
		{
		}
		
	}
	
	
	public   void ClearDepth(double p_value)
	{
		{
		}
		
	}
	
	
	public   void ClearColor(double p_r, double p_g, double p_b, double p_a)
	{
		{
		}
		
	}
	
	
	public   void Viewport(int p_x, int p_y, int p_width, int p_height)
	{
		{
		}
		
	}
	
	
	public   void Scissor(int p_x, int p_y, int p_width, int p_height)
	{
		{
		}
		
	}
	
	
	public   void ReadPixels(int p_x, int p_y, int p_width, int p_height, int p_format, int p_type, haxor.io.Buffer p_pixels)
	{
		{
		}
		
	}
	
	
	public   int GetErrorCode()
	{
		return 0;
	}
	
	
	public   java.lang.String GetErrorString(int p_code)
	{
		switch (p_code)
		{
			case 0:
			{
				return "";
			}
			
			
			case 1280:
			{
				return "Invalid Enum.";
			}
			
			
			case 1281:
			{
				return "Numeric argument is out of range.";
			}
			
			
			case 1282:
			{
				return "Operation not allowed in the current state.";
			}
			
			
			case 1286:
			{
				return "Write or Read in FrameBuffer not complete.";
			}
			
			
			case 1285:
			{
				return "Out of Memory.";
			}
			
			
		}
		
		return "Unknown Error.";
	}
	
	
	public   java.lang.String GetError()
	{
		return this.GetErrorString(this.GetErrorCode());
	}
	
	
	public   void Assert(java.lang.String p_log)
	{
		int err = this.GetErrorCode();
		if (( err != 0 )) 
		{
			throw haxe.lang.HaxeException.wrap(( ( ( "GraphicContext> " + this.GetErrorString(err) ) + " - " ) + p_log ));
		}
		
	}
	
	
	public   void LogError()
	{
		haxor.core.Console.Log(this.GetError(), null);
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef42670 = true;
			switch (field.hashCode())
			{
				case -983947138:
				{
					if (field.equals("m_application")) 
					{
						__temp_executeDef42670 = false;
						this.m_application = ((haxor.core.BaseApplication) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103590728:
				{
					if (field.equals("m_api")) 
					{
						__temp_executeDef42670 = false;
						this.m_api = ((haxor.platform.graphics.GraphicAPI) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef42670) 
			{
				return super.__hx_setField(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef42671 = true;
			switch (field.hashCode())
			{
				case 2054294852:
				{
					if (field.equals("LogError")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("LogError"))) );
					}
					
					break;
				}
				
				
				case 96794:
				{
					if (field.equals("api")) 
					{
						__temp_executeDef42671 = false;
						return this.get_api();
					}
					
					break;
				}
				
				
				case 1970626406:
				{
					if (field.equals("Assert")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Assert"))) );
					}
					
					break;
				}
				
				
				case -74801743:
				{
					if (field.equals("get_api")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_api"))) );
					}
					
					break;
				}
				
				
				case 2017254514:
				{
					if (field.equals("GetError")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetError"))) );
					}
					
					break;
				}
				
				
				case 103590728:
				{
					if (field.equals("m_api")) 
					{
						__temp_executeDef42671 = false;
						return this.m_api;
					}
					
					break;
				}
				
				
				case 1491634979:
				{
					if (field.equals("GetErrorString")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetErrorString"))) );
					}
					
					break;
				}
				
				
				case -983947138:
				{
					if (field.equals("m_application")) 
					{
						__temp_executeDef42671 = false;
						return this.m_application;
					}
					
					break;
				}
				
				
				case 483751295:
				{
					if (field.equals("GetErrorCode")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetErrorCode"))) );
					}
					
					break;
				}
				
				
				case -1602602212:
				{
					if (field.equals("CheckExtensions")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CheckExtensions"))) );
					}
					
					break;
				}
				
				
				case 1397397507:
				{
					if (field.equals("ReadPixels")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ReadPixels"))) );
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Destroy"))) );
					}
					
					break;
				}
				
				
				case -711810116:
				{
					if (field.equals("Scissor")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Scissor"))) );
					}
					
					break;
				}
				
				
				case 67980004:
				{
					if (field.equals("Flush")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Flush"))) );
					}
					
					break;
				}
				
				
				case 1261329606:
				{
					if (field.equals("Viewport")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Viewport"))) );
					}
					
					break;
				}
				
				
				case 68052152:
				{
					if (field.equals("Focus")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Focus"))) );
					}
					
					break;
				}
				
				
				case 1234652470:
				{
					if (field.equals("ClearColor")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ClearColor"))) );
					}
					
					break;
				}
				
				
				case -1850570540:
				{
					if (field.equals("Resize")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Resize"))) );
					}
					
					break;
				}
				
				
				case 1235282070:
				{
					if (field.equals("ClearDepth")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ClearDepth"))) );
					}
					
					break;
				}
				
				
				case -1896767747:
				{
					if (field.equals("BindBuffer")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BindBuffer"))) );
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case -395725782:
				{
					if (field.equals("BufferData")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BufferData"))) );
					}
					
					break;
				}
				
				
				case 2131299334:
				{
					if (field.equals("FrontFace")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FrontFace"))) );
					}
					
					break;
				}
				
				
				case 1601301898:
				{
					if (field.equals("BufferSubData")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BufferSubData"))) );
					}
					
					break;
				}
				
				
				case 461794063:
				{
					if (field.equals("CullFace")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CullFace"))) );
					}
					
					break;
				}
				
				
				case 1213974652:
				{
					if (field.equals("CreateBuffer")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateBuffer"))) );
					}
					
					break;
				}
				
				
				case 1317758983:
				{
					if (field.equals("DepthFunc")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DepthFunc"))) );
					}
					
					break;
				}
				
				
				case -1081856533:
				{
					if (field.equals("DeleteBuffer")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteBuffer"))) );
					}
					
					break;
				}
				
				
				case 1317948463:
				{
					if (field.equals("DepthMask")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DepthMask"))) );
					}
					
					break;
				}
				
				
				case 1387908030:
				{
					if (field.equals("DrawArrays")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawArrays"))) );
					}
					
					break;
				}
				
				
				case 2079986083:
				{
					if (field.equals("Enable")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Enable"))) );
					}
					
					break;
				}
				
				
				case -670686597:
				{
					if (field.equals("DrawElements")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawElements"))) );
					}
					
					break;
				}
				
				
				case -959006008:
				{
					if (field.equals("Disable")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Disable"))) );
					}
					
					break;
				}
				
				
				case 1857751761:
				{
					if (field.equals("EnableVertexAttrib")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("EnableVertexAttrib"))) );
					}
					
					break;
				}
				
				
				case -1395603819:
				{
					if (field.equals("BlendFunc")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BlendFunc"))) );
					}
					
					break;
				}
				
				
				case 1204954230:
				{
					if (field.equals("DisableVertexAttrib")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DisableVertexAttrib"))) );
					}
					
					break;
				}
				
				
				case -1452160697:
				{
					if (field.equals("TexParameteri")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TexParameteri"))) );
					}
					
					break;
				}
				
				
				case -454645567:
				{
					if (field.equals("VertexAttrib3f")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("VertexAttrib3f"))) );
					}
					
					break;
				}
				
				
				case -1452160700:
				{
					if (field.equals("TexParameterf")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TexParameterf"))) );
					}
					
					break;
				}
				
				
				case -454645536:
				{
					if (field.equals("VertexAttrib4f")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("VertexAttrib4f"))) );
					}
					
					break;
				}
				
				
				case -1559394874:
				{
					if (field.equals("TexStorage2D")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TexStorage2D"))) );
					}
					
					break;
				}
				
				
				case 1170563247:
				{
					if (field.equals("VertexAttribPointer")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("VertexAttribPointer"))) );
					}
					
					break;
				}
				
				
				case -1480581644:
				{
					if (field.equals("TexSubImage2D")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TexSubImage2D"))) );
					}
					
					break;
				}
				
				
				case 490879960:
				{
					if (field.equals("CompileShader")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CompileShader"))) );
					}
					
					break;
				}
				
				
				case 768888550:
				{
					if (field.equals("TexImage2D")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TexImage2D"))) );
					}
					
					break;
				}
				
				
				case 1688513569:
				{
					if (field.equals("CreateShader")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateShader"))) );
					}
					
					break;
				}
				
				
				case -51526673:
				{
					if (field.equals("TexImage2DAlloc")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TexImage2DAlloc"))) );
					}
					
					break;
				}
				
				
				case -607317616:
				{
					if (field.equals("DeleteShader")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteShader"))) );
					}
					
					break;
				}
				
				
				case 1800947749:
				{
					if (field.equals("RenderbufferStorage")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("RenderbufferStorage"))) );
					}
					
					break;
				}
				
				
				case -440035976:
				{
					if (field.equals("DetachShader")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DetachShader"))) );
					}
					
					break;
				}
				
				
				case 450629038:
				{
					if (field.equals("PixelStorei")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("PixelStorei"))) );
					}
					
					break;
				}
				
				
				case 1073071227:
				{
					if (field.equals("GetShaderInfoLog")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetShaderInfoLog"))) );
					}
					
					break;
				}
				
				
				case 1000706173:
				{
					if (field.equals("GenerateMipmap")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GenerateMipmap"))) );
					}
					
					break;
				}
				
				
				case 1169816366:
				{
					if (field.equals("GetShaderParameter")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetShaderParameter"))) );
					}
					
					break;
				}
				
				
				case 962410336:
				{
					if (field.equals("FramebufferTexture2D")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FramebufferTexture2D"))) );
					}
					
					break;
				}
				
				
				case -1805459328:
				{
					if (field.equals("ShaderSource")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ShaderSource"))) );
					}
					
					break;
				}
				
				
				case 683029955:
				{
					if (field.equals("FramebufferRenderbuffer")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FramebufferRenderbuffer"))) );
					}
					
					break;
				}
				
				
				case -2011750742:
				{
					if (field.equals("AttachShader")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("AttachShader"))) );
					}
					
					break;
				}
				
				
				case -823627568:
				{
					if (field.equals("DeleteTexture")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteTexture"))) );
					}
					
					break;
				}
				
				
				case 1781319260:
				{
					if (field.equals("BindAttribLocation")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BindAttribLocation"))) );
					}
					
					break;
				}
				
				
				case 1756641985:
				{
					if (field.equals("DeleteRenderbuffer")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteRenderbuffer"))) );
					}
					
					break;
				}
				
				
				case -1558875704:
				{
					if (field.equals("CreateProgram")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateProgram"))) );
					}
					
					break;
				}
				
				
				case 32403746:
				{
					if (field.equals("DeleteFramebuffer")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteFramebuffer"))) );
					}
					
					break;
				}
				
				
				case 284801593:
				{
					if (field.equals("DeleteProgram")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteProgram"))) );
					}
					
					break;
				}
				
				
				case 1627662431:
				{
					if (field.equals("CreateTexture")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateTexture"))) );
					}
					
					break;
				}
				
				
				case -1248406155:
				{
					if (field.equals("GetAttribLocation")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetAttribLocation"))) );
					}
					
					break;
				}
				
				
				case 710403218:
				{
					if (field.equals("CreateRenderbuffer")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateRenderbuffer"))) );
					}
					
					break;
				}
				
				
				case 1131050867:
				{
					if (field.equals("GetUniformLocation")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetUniformLocation"))) );
					}
					
					break;
				}
				
				
				case 691390769:
				{
					if (field.equals("CreateFramebuffer")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateFramebuffer"))) );
					}
					
					break;
				}
				
				
				case 662129000:
				{
					if (field.equals("GetProgramInfoLog")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetProgramInfoLog"))) );
					}
					
					break;
				}
				
				
				case -316071426:
				{
					if (field.equals("BindTexture")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BindTexture"))) );
					}
					
					break;
				}
				
				
				case 1391327451:
				{
					if (field.equals("GetProgramParameter")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetProgramParameter"))) );
					}
					
					break;
				}
				
				
				case -1967581613:
				{
					if (field.equals("BindRenderbuffer")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BindRenderbuffer"))) );
					}
					
					break;
				}
				
				
				case -682516214:
				{
					if (field.equals("LinkProgram")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("LinkProgram"))) );
					}
					
					break;
				}
				
				
				case -1057563824:
				{
					if (field.equals("BindFramebuffer")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BindFramebuffer"))) );
					}
					
					break;
				}
				
				
				case 62838557:
				{
					if (field.equals("UseProgram")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UseProgram"))) );
					}
					
					break;
				}
				
				
				case -1798288619:
				{
					if (field.equals("ActiveTexture")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ActiveTexture"))) );
					}
					
					break;
				}
				
				
				case 1145594601:
				{
					if (field.equals("Uniform1f")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform1f"))) );
					}
					
					break;
				}
				
				
				case -1966618257:
				{
					if (field.equals("UniformMatrix4fv")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UniformMatrix4fv"))) );
					}
					
					break;
				}
				
				
				case 1145594632:
				{
					if (field.equals("Uniform2f")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform2f"))) );
					}
					
					break;
				}
				
				
				case -1966619218:
				{
					if (field.equals("UniformMatrix3fv")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UniformMatrix3fv"))) );
					}
					
					break;
				}
				
				
				case 1145594663:
				{
					if (field.equals("Uniform3f")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform3f"))) );
					}
					
					break;
				}
				
				
				case -1966620179:
				{
					if (field.equals("UniformMatrix2fv")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UniformMatrix2fv"))) );
					}
					
					break;
				}
				
				
				case 1145594694:
				{
					if (field.equals("Uniform4f")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform4f"))) );
					}
					
					break;
				}
				
				
				case 1153697357:
				{
					if (field.equals("Uniform4iv")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform4iv"))) );
					}
					
					break;
				}
				
				
				case 1145594604:
				{
					if (field.equals("Uniform1i")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform1i"))) );
					}
					
					break;
				}
				
				
				case 1153696396:
				{
					if (field.equals("Uniform3iv")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform3iv"))) );
					}
					
					break;
				}
				
				
				case 1145594635:
				{
					if (field.equals("Uniform2i")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform2i"))) );
					}
					
					break;
				}
				
				
				case 1153695435:
				{
					if (field.equals("Uniform2iv")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform2iv"))) );
					}
					
					break;
				}
				
				
				case 1145594666:
				{
					if (field.equals("Uniform3i")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform3i"))) );
					}
					
					break;
				}
				
				
				case 1153694474:
				{
					if (field.equals("Uniform1iv")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform1iv"))) );
					}
					
					break;
				}
				
				
				case 1145594697:
				{
					if (field.equals("Uniform4i")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform4i"))) );
					}
					
					break;
				}
				
				
				case 1153697264:
				{
					if (field.equals("Uniform4fv")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform4fv"))) );
					}
					
					break;
				}
				
				
				case 1153694381:
				{
					if (field.equals("Uniform1fv")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform1fv"))) );
					}
					
					break;
				}
				
				
				case 1153696303:
				{
					if (field.equals("Uniform3fv")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform3fv"))) );
					}
					
					break;
				}
				
				
				case 1153695342:
				{
					if (field.equals("Uniform2fv")) 
					{
						__temp_executeDef42671 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform2fv"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef42671) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			boolean __temp_executeDef42672 = true;
			switch (field.hashCode())
			{
				case 2054294852:
				{
					if (field.equals("LogError")) 
					{
						__temp_executeDef42672 = false;
						this.LogError();
					}
					
					break;
				}
				
				
				case -74801743:
				{
					if (field.equals("get_api")) 
					{
						__temp_executeDef42672 = false;
						return this.get_api();
					}
					
					break;
				}
				
				
				case 1970626406:
				{
					if (field.equals("Assert")) 
					{
						__temp_executeDef42672 = false;
						this.Assert(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1602602212:
				{
					if (field.equals("CheckExtensions")) 
					{
						__temp_executeDef42672 = false;
						this.CheckExtensions();
					}
					
					break;
				}
				
				
				case 2017254514:
				{
					if (field.equals("GetError")) 
					{
						__temp_executeDef42672 = false;
						return this.GetError();
					}
					
					break;
				}
				
				
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef42672 = false;
						this.Destroy();
					}
					
					break;
				}
				
				
				case 1491634979:
				{
					if (field.equals("GetErrorString")) 
					{
						__temp_executeDef42672 = false;
						return this.GetErrorString(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 67980004:
				{
					if (field.equals("Flush")) 
					{
						__temp_executeDef42672 = false;
						this.Flush();
					}
					
					break;
				}
				
				
				case 483751295:
				{
					if (field.equals("GetErrorCode")) 
					{
						__temp_executeDef42672 = false;
						return this.GetErrorCode();
					}
					
					break;
				}
				
				
				case 68052152:
				{
					if (field.equals("Focus")) 
					{
						__temp_executeDef42672 = false;
						this.Focus();
					}
					
					break;
				}
				
				
				case 1397397507:
				{
					if (field.equals("ReadPixels")) 
					{
						__temp_executeDef42672 = false;
						this.ReadPixels(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(4))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(5))) ), ((haxor.io.Buffer) (dynargs.__get(6)) ));
					}
					
					break;
				}
				
				
				case -1850570540:
				{
					if (field.equals("Resize")) 
					{
						__temp_executeDef42672 = false;
						this.Resize();
					}
					
					break;
				}
				
				
				case -711810116:
				{
					if (field.equals("Scissor")) 
					{
						__temp_executeDef42672 = false;
						this.Scissor(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case -1896767747:
				{
					if (field.equals("BindBuffer")) 
					{
						__temp_executeDef42672 = false;
						this.BindBuffer(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 1261329606:
				{
					if (field.equals("Viewport")) 
					{
						__temp_executeDef42672 = false;
						this.Viewport(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case -395725782:
				{
					if (field.equals("BufferData")) 
					{
						__temp_executeDef42672 = false;
						this.BufferData(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxor.io.Buffer) (dynargs.__get(1)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case 1234652470:
				{
					if (field.equals("ClearColor")) 
					{
						__temp_executeDef42672 = false;
						this.ClearColor(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case 1601301898:
				{
					if (field.equals("BufferSubData")) 
					{
						__temp_executeDef42672 = false;
						this.BufferSubData(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((haxor.io.Buffer) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case 1235282070:
				{
					if (field.equals("ClearDepth")) 
					{
						__temp_executeDef42672 = false;
						this.ClearDepth(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1213974652:
				{
					if (field.equals("CreateBuffer")) 
					{
						__temp_executeDef42672 = false;
						return this.CreateBuffer();
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef42672 = false;
						this.Clear(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1081856533:
				{
					if (field.equals("DeleteBuffer")) 
					{
						__temp_executeDef42672 = false;
						this.DeleteBuffer(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 2131299334:
				{
					if (field.equals("FrontFace")) 
					{
						__temp_executeDef42672 = false;
						this.FrontFace(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1387908030:
				{
					if (field.equals("DrawArrays")) 
					{
						__temp_executeDef42672 = false;
						this.DrawArrays(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case 461794063:
				{
					if (field.equals("CullFace")) 
					{
						__temp_executeDef42672 = false;
						this.CullFace(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -670686597:
				{
					if (field.equals("DrawElements")) 
					{
						__temp_executeDef42672 = false;
						this.DrawElements(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case 1317758983:
				{
					if (field.equals("DepthFunc")) 
					{
						__temp_executeDef42672 = false;
						this.DepthFunc(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1857751761:
				{
					if (field.equals("EnableVertexAttrib")) 
					{
						__temp_executeDef42672 = false;
						this.EnableVertexAttrib(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1317948463:
				{
					if (field.equals("DepthMask")) 
					{
						__temp_executeDef42672 = false;
						this.DepthMask(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1204954230:
				{
					if (field.equals("DisableVertexAttrib")) 
					{
						__temp_executeDef42672 = false;
						this.DisableVertexAttrib(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 2079986083:
				{
					if (field.equals("Enable")) 
					{
						__temp_executeDef42672 = false;
						this.Enable(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -454645567:
				{
					if (field.equals("VertexAttrib3f")) 
					{
						__temp_executeDef42672 = false;
						this.VertexAttrib3f(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case -959006008:
				{
					if (field.equals("Disable")) 
					{
						__temp_executeDef42672 = false;
						this.Disable(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -454645536:
				{
					if (field.equals("VertexAttrib4f")) 
					{
						__temp_executeDef42672 = false;
						this.VertexAttrib4f(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(4))) ));
					}
					
					break;
				}
				
				
				case -1395603819:
				{
					if (field.equals("BlendFunc")) 
					{
						__temp_executeDef42672 = false;
						this.BlendFunc(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 1170563247:
				{
					if (field.equals("VertexAttribPointer")) 
					{
						__temp_executeDef42672 = false;
						this.VertexAttribPointer(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), haxe.lang.Runtime.toBool(dynargs.__get(3)), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(4))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(5))) ));
					}
					
					break;
				}
				
				
				case -1452160697:
				{
					if (field.equals("TexParameteri")) 
					{
						__temp_executeDef42672 = false;
						this.TexParameteri(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case 490879960:
				{
					if (field.equals("CompileShader")) 
					{
						__temp_executeDef42672 = false;
						this.CompileShader(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1452160700:
				{
					if (field.equals("TexParameterf")) 
					{
						__temp_executeDef42672 = false;
						this.TexParameterf(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case 1688513569:
				{
					if (field.equals("CreateShader")) 
					{
						__temp_executeDef42672 = false;
						return this.CreateShader(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1559394874:
				{
					if (field.equals("TexStorage2D")) 
					{
						__temp_executeDef42672 = false;
						this.TexStorage2D(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(4))) ));
					}
					
					break;
				}
				
				
				case -607317616:
				{
					if (field.equals("DeleteShader")) 
					{
						__temp_executeDef42672 = false;
						this.DeleteShader(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1480581644:
				{
					if (field.equals("TexSubImage2D")) 
					{
						__temp_executeDef42672 = false;
						this.TexSubImage2D(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(4))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(5))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(6))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(7))) ), ((haxor.io.Buffer) (dynargs.__get(8)) ));
					}
					
					break;
				}
				
				
				case -440035976:
				{
					if (field.equals("DetachShader")) 
					{
						__temp_executeDef42672 = false;
						this.DetachShader(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 768888550:
				{
					if (field.equals("TexImage2D")) 
					{
						__temp_executeDef42672 = false;
						this.TexImage2D(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(4))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(5))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(6))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(7))) ), ((haxor.io.Buffer) (dynargs.__get(8)) ));
					}
					
					break;
				}
				
				
				case 1073071227:
				{
					if (field.equals("GetShaderInfoLog")) 
					{
						__temp_executeDef42672 = false;
						return this.GetShaderInfoLog(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -51526673:
				{
					if (field.equals("TexImage2DAlloc")) 
					{
						__temp_executeDef42672 = false;
						this.TexImage2DAlloc(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(4))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(5))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(6))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(7))) ));
					}
					
					break;
				}
				
				
				case 1169816366:
				{
					if (field.equals("GetShaderParameter")) 
					{
						__temp_executeDef42672 = false;
						return this.GetShaderParameter(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 1800947749:
				{
					if (field.equals("RenderbufferStorage")) 
					{
						__temp_executeDef42672 = false;
						this.RenderbufferStorage(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case -1805459328:
				{
					if (field.equals("ShaderSource")) 
					{
						__temp_executeDef42672 = false;
						this.ShaderSource(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), haxe.lang.Runtime.toString(dynargs.__get(1)));
					}
					
					break;
				}
				
				
				case 450629038:
				{
					if (field.equals("PixelStorei")) 
					{
						__temp_executeDef42672 = false;
						this.PixelStorei(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -2011750742:
				{
					if (field.equals("AttachShader")) 
					{
						__temp_executeDef42672 = false;
						this.AttachShader(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 1000706173:
				{
					if (field.equals("GenerateMipmap")) 
					{
						__temp_executeDef42672 = false;
						this.GenerateMipmap(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1781319260:
				{
					if (field.equals("BindAttribLocation")) 
					{
						__temp_executeDef42672 = false;
						this.BindAttribLocation(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), haxe.lang.Runtime.toString(dynargs.__get(2)));
					}
					
					break;
				}
				
				
				case 962410336:
				{
					if (field.equals("FramebufferTexture2D")) 
					{
						__temp_executeDef42672 = false;
						this.FramebufferTexture2D(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(4))) ));
					}
					
					break;
				}
				
				
				case -1558875704:
				{
					if (field.equals("CreateProgram")) 
					{
						__temp_executeDef42672 = false;
						return this.CreateProgram();
					}
					
					break;
				}
				
				
				case 683029955:
				{
					if (field.equals("FramebufferRenderbuffer")) 
					{
						__temp_executeDef42672 = false;
						this.FramebufferRenderbuffer(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case 284801593:
				{
					if (field.equals("DeleteProgram")) 
					{
						__temp_executeDef42672 = false;
						this.DeleteProgram(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -823627568:
				{
					if (field.equals("DeleteTexture")) 
					{
						__temp_executeDef42672 = false;
						this.DeleteTexture(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1248406155:
				{
					if (field.equals("GetAttribLocation")) 
					{
						__temp_executeDef42672 = false;
						return this.GetAttribLocation(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), haxe.lang.Runtime.toString(dynargs.__get(1)));
					}
					
					break;
				}
				
				
				case 1756641985:
				{
					if (field.equals("DeleteRenderbuffer")) 
					{
						__temp_executeDef42672 = false;
						this.DeleteRenderbuffer(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1131050867:
				{
					if (field.equals("GetUniformLocation")) 
					{
						__temp_executeDef42672 = false;
						return this.GetUniformLocation(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), haxe.lang.Runtime.toString(dynargs.__get(1)));
					}
					
					break;
				}
				
				
				case 32403746:
				{
					if (field.equals("DeleteFramebuffer")) 
					{
						__temp_executeDef42672 = false;
						this.DeleteFramebuffer(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 662129000:
				{
					if (field.equals("GetProgramInfoLog")) 
					{
						__temp_executeDef42672 = false;
						return this.GetProgramInfoLog(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1627662431:
				{
					if (field.equals("CreateTexture")) 
					{
						__temp_executeDef42672 = false;
						return this.CreateTexture();
					}
					
					break;
				}
				
				
				case 1391327451:
				{
					if (field.equals("GetProgramParameter")) 
					{
						__temp_executeDef42672 = false;
						return this.GetProgramParameter(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 710403218:
				{
					if (field.equals("CreateRenderbuffer")) 
					{
						__temp_executeDef42672 = false;
						return this.CreateRenderbuffer();
					}
					
					break;
				}
				
				
				case -682516214:
				{
					if (field.equals("LinkProgram")) 
					{
						__temp_executeDef42672 = false;
						this.LinkProgram(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 691390769:
				{
					if (field.equals("CreateFramebuffer")) 
					{
						__temp_executeDef42672 = false;
						return this.CreateFramebuffer();
					}
					
					break;
				}
				
				
				case 62838557:
				{
					if (field.equals("UseProgram")) 
					{
						__temp_executeDef42672 = false;
						this.UseProgram(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -316071426:
				{
					if (field.equals("BindTexture")) 
					{
						__temp_executeDef42672 = false;
						this.BindTexture(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 1145594601:
				{
					if (field.equals("Uniform1f")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform1f(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -1967581613:
				{
					if (field.equals("BindRenderbuffer")) 
					{
						__temp_executeDef42672 = false;
						this.BindRenderbuffer(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 1145594632:
				{
					if (field.equals("Uniform2f")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform2f(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case -1057563824:
				{
					if (field.equals("BindFramebuffer")) 
					{
						__temp_executeDef42672 = false;
						this.BindFramebuffer(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 1145594663:
				{
					if (field.equals("Uniform3f")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform3f(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case -1798288619:
				{
					if (field.equals("ActiveTexture")) 
					{
						__temp_executeDef42672 = false;
						this.ActiveTexture(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1145594694:
				{
					if (field.equals("Uniform4f")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform4f(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(4))) ));
					}
					
					break;
				}
				
				
				case -1966618257:
				{
					if (field.equals("UniformMatrix4fv")) 
					{
						__temp_executeDef42672 = false;
						this.UniformMatrix4fv(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), haxe.lang.Runtime.toBool(dynargs.__get(1)), ((haxor.io.FloatArray) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case 1145594604:
				{
					if (field.equals("Uniform1i")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform1i(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -1966619218:
				{
					if (field.equals("UniformMatrix3fv")) 
					{
						__temp_executeDef42672 = false;
						this.UniformMatrix3fv(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), haxe.lang.Runtime.toBool(dynargs.__get(1)), ((haxor.io.FloatArray) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case 1145594635:
				{
					if (field.equals("Uniform2i")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform2i(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case -1966620179:
				{
					if (field.equals("UniformMatrix2fv")) 
					{
						__temp_executeDef42672 = false;
						this.UniformMatrix2fv(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), haxe.lang.Runtime.toBool(dynargs.__get(1)), ((haxor.io.FloatArray) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case 1145594666:
				{
					if (field.equals("Uniform3i")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform3i(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case 1153697357:
				{
					if (field.equals("Uniform4iv")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform4iv(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxor.io.Int32Array) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1145594697:
				{
					if (field.equals("Uniform4i")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform4i(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(4))) ));
					}
					
					break;
				}
				
				
				case 1153696396:
				{
					if (field.equals("Uniform3iv")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform3iv(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxor.io.Int32Array) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1153694381:
				{
					if (field.equals("Uniform1fv")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform1fv(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxor.io.FloatArray) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1153695435:
				{
					if (field.equals("Uniform2iv")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform2iv(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxor.io.Int32Array) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1153695342:
				{
					if (field.equals("Uniform2fv")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform2fv(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxor.io.FloatArray) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1153694474:
				{
					if (field.equals("Uniform1iv")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform1iv(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxor.io.Int32Array) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1153696303:
				{
					if (field.equals("Uniform3fv")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform3fv(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxor.io.FloatArray) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case 1153697264:
				{
					if (field.equals("Uniform4fv")) 
					{
						__temp_executeDef42672 = false;
						this.Uniform4fv(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxor.io.FloatArray) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef42672) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_application");
		baseArr.push("m_api");
		baseArr.push("api");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


