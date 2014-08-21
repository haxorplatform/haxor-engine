package haxor.platform.android.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class AndroidGL extends haxor.graphics.GraphicContext
{
	public    AndroidGL(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    AndroidGL(haxor.core.BaseApplication p_application)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.platform.android.graphics.AndroidGL.__hx_ctor_haxor_platform_android_graphics_AndroidGL(this, p_application);
	}
	
	
	public static   void __hx_ctor_haxor_platform_android_graphics_AndroidGL(haxor.platform.android.graphics.AndroidGL __temp_me54554, haxor.core.BaseApplication p_application)
	{
		haxor.graphics.GraphicContext.__hx_ctor_haxor_graphics_GraphicContext(__temp_me54554, p_application);
		__temp_me54554.m_api = haxor.graphics.GraphicAPI.OpenGLES;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.graphics.AndroidGL(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.graphics.AndroidGL(((haxor.core.BaseApplication) (arr.__get(0)) ));
	}
	
	
	public  android.opengl.GLSurfaceView c;
	
	public  int[] m_ids;
	
	public   boolean Initialize(haxor.platform.android.Entry p_entry, java.lang.Object p_version)
	{
		int __temp_p_version54553 = ( (( p_version == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_version)) )) );
		if (( p_entry == null )) 
		{
			haxor.core.Console.Log("Graphics> Invalid Entry Activity.", null);
			return false;
		}
		
		int cv = __temp_p_version54553;
		
		 c = new android.opengl.GLSurfaceView(p_entry.getApplication());
		 ;
		if (( this.c == null )) 
		{
			haxor.core.Console.Log("Graphics> Could not create GLSurfaceView.", null);
			return false;
		}
		
		int w = 0;
		int h = 0;
		
		c.setEGLContextClientVersion(cv);
		c.setRenderer(p_entry);		
		p_entry.setContentView(c);		
		
		android.view.Display display = p_entry.getWindowManager().getDefaultDisplay();
		
		android.util.DisplayMetrics metrics = new android.util.DisplayMetrics();
		display.getMetrics(metrics);

		w = metrics.widthPixels;
		h = metrics.heightPixels;
		
		;
		this.m_ids = new int[((int) (1) )];
		haxor.core.Console.Log(( ( ( ( ( ( "Graphics> Initialize Android GLES version[" + __temp_p_version54553 ) + "] Resolution[" ) + w ) + "," ) + h ) + "]" ), 1);
		return true;
	}
	
	
	public   void OnPause()
	{
		c.onPause();
	}
	
	
	public   void OnResume()
	{
		c.onResume();
	}
	
	
	@Override public   void CheckExtensions()
	{
		if (( this.c == null )) 
		{
			return ;
		}
		
		haxor.core.Console.Log("Graphics> Available Extensions.", 1);
		int[] il = new int[((int) (1) )];
		float[] fl = new float[((int) (1) )];
		haxe.root.Array<java.lang.String> exts = haxe.lang.StringExt.split(android.opengl.GLES20.glGetString(((int) (android.opengl.GLES20.GL_EXTENSIONS) )), " ");
		{
			int _g1 = 0;
			int _g = exts.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				java.lang.String n = exts.__get(i);
				n = haxe.root.StringTools.replace(n, "GL_", "");
				if (haxe.lang.Runtime.valEq(n, "")) 
				{
					continue;
				}
				
				haxor.core.Console.Log(( "\t" + n ), null);
				{
					java.lang.String __temp_svar54830 = (n);
					int __temp_hash54832 = __temp_svar54830.hashCode();
					switch (__temp_hash54832)
					{
						case 1647472438:
						{
							if (__temp_svar54830.equals("OES_texture_half_float")) 
							{
								haxor.graphics.GL.HALF_FLOAT = 36193;
								haxor.graphics.GL.TEXTURE_HALF = true;
							}
							
							break;
						}
						
						
						case 928981241:
						{
							if (__temp_svar54830.equals("WEBGL_depth_texture")) 
							{
								haxor.graphics.GL.TEXTURE_DEPTH_ENABLED = true;
							}
							
							break;
						}
						
						
						case 221819982:
						{
							if (__temp_svar54830.equals("OES_texture_half_float_linear")) 
							{
								haxor.graphics.GL.TEXTURE_HALF_LINEAR = true;
							}
							
							break;
						}
						
						
						case -915640650:
						{
							if (__temp_svar54830.equals("OES_texture_float")) 
							{
								haxor.graphics.GL.TEXTURE_FLOAT = true;
							}
							
							break;
						}
						
						
						case 133065385:case 1139773900:
						{
							if (( (( ( __temp_hash54832 == 133065385 ) && __temp_svar54830.equals("WEBKIT_EXT_texture_filter_anisotropic") )) || __temp_svar54830.equals("EXT_texture_filter_anisotropic") )) 
							{
								android.opengl.GLES20.glGetFloatv(((int) (android.opengl.GLES11Ext.GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT) ), ((float[]) (fl) ), ((int) (0) ));
								haxor.graphics.GL.MAX_TEXTURE_ANISOTROPY = ((int) (fl[0]) );
								haxor.graphics.GL.TEXTURE_ANISOTROPY_ENABLED = true;
								haxor.core.Console.Log(( "\t\tMAX_TEXTURE_MAX_ANISOTROPY: " + haxor.graphics.GL.MAX_TEXTURE_ANISOTROPY ), null);
							}
							
							break;
						}
						
						
					}
					
				}
				
			}
			
		}
		
		android.opengl.GLES20.glGetIntegerv(((int) (android.opengl.GLES20.GL_MAX_TEXTURE_IMAGE_UNITS) ), ((int[]) (il) ), ((int) (0) ));
		haxor.graphics.GL.MAX_ACTIVE_TEXTURE = il[0];
		haxor.core.Console.Log(( "\tMax Active Textures: " + haxor.graphics.GL.MAX_ACTIVE_TEXTURE ), null);
	}
	
	
	@Override public   void BindBuffer(int p_target, int p_id)
	{
		android.opengl.GLES20.glBindBuffer(((int) (p_target) ), ((int) (p_id) ));
	}
	
	
	@Override public   void BufferData(int p_target, haxor.io.Buffer p_data, int p_mode)
	{
		android.opengl.GLES20.glBufferData(((int) (p_target) ), ((int) (( p_data.m_length * p_data.get_bytesPerElement() )) ), ((java.nio.Buffer) (p_data.m_buffer) ), ((int) (p_mode) ));
	}
	
	
	@Override public   void BufferSubData(int p_target, int p_offset, haxor.io.Buffer p_data)
	{
		android.opengl.GLES20.glBufferSubData(((int) (p_target) ), ((int) (p_offset) ), ((int) (( p_data.m_length * p_data.get_bytesPerElement() )) ), ((java.nio.Buffer) (p_data.m_buffer) ));
	}
	
	
	@Override public   int CreateBuffer()
	{
		android.opengl.GLES20.glGenBuffers(((int) (1) ), ((int[]) (this.m_ids) ), ((int) (0) ));
		return this.m_ids[0];
	}
	
	
	@Override public   void DrawArrays(int p_primitive, int p_start, int p_count)
	{
		android.opengl.GLES20.glDrawArrays(((int) (p_primitive) ), ((int) (p_start) ), ((int) (p_count) ));
	}
	
	
	@Override public   void DrawElements(int p_primitive, int p_count, int p_type, int p_offset)
	{
		android.opengl.GLES20.glDrawElements(((int) (p_primitive) ), ((int) (p_count) ), ((int) (p_type) ), ((int) (p_offset) ));
	}
	
	
	@Override public   void DeleteBuffer(int p_id)
	{
		this.m_ids[0] = p_id;
		android.opengl.GLES20.glDeleteBuffers(((int) (1) ), ((int[]) (this.m_ids) ), ((int) (0) ));
	}
	
	
	@Override public   void DisableVertexAttrib(int p_location)
	{
		android.opengl.GLES20.glDisableVertexAttribArray(((int) (p_location) ));
	}
	
	
	@Override public   void EnableVertexAttrib(int p_location)
	{
		android.opengl.GLES20.glEnableVertexAttribArray(((int) (p_location) ));
	}
	
	
	@Override public   void VertexAttrib3f(int p_location, double p_x, double p_y, double p_z)
	{
		android.opengl.GLES20.glVertexAttrib3f(((int) (p_location) ), ((float) (p_x) ), ((float) (p_y) ), ((float) (p_z) ));
	}
	
	
	@Override public   void VertexAttrib4f(int p_location, double p_x, double p_y, double p_z, double p_w)
	{
		android.opengl.GLES20.glVertexAttrib4f(((int) (p_location) ), ((float) (p_x) ), ((float) (p_y) ), ((float) (p_z) ), ((float) (p_w) ));
	}
	
	
	@Override public   void VertexAttribPointer(int p_location, int p_components_size, int p_type, boolean p_normalized, int p_stride, int p_offset)
	{
		android.opengl.GLES20.glVertexAttribPointer(((int) (p_location) ), ((int) (p_components_size) ), ((int) (p_type) ), haxe.lang.Runtime.toBool(p_normalized), ((int) (p_stride) ), ((int) (p_offset) ));
	}
	
	
	@Override public   void CompileShader(int p_shader)
	{
		android.opengl.GLES20.glCompileShader(((int) (p_shader) ));
	}
	
	
	@Override public   int CreateShader(int p_type)
	{
		return android.opengl.GLES20.glCreateShader(((int) (p_type) ));
	}
	
	
	@Override public   void DetachShader(int p_program, int p_shader)
	{
		android.opengl.GLES20.glDetachShader(((int) (p_program) ), ((int) (p_shader) ));
	}
	
	
	@Override public   void DeleteShader(int p_shader)
	{
		android.opengl.GLES20.glDeleteShader(((int) (p_shader) ));
	}
	
	
	@Override public   java.lang.String GetShaderInfoLog(int p_shader)
	{
		return android.opengl.GLES20.glGetShaderInfoLog(((int) (p_shader) ));
	}
	
	
	@Override public   int GetShaderParameter(int p_shader, int p_parameter)
	{
		int[] d = new int[((int) (1) )];
		android.opengl.GLES20.glGetShaderiv(((int) (p_shader) ), ((int) (p_parameter) ), ((int[]) (d) ), ((int) (0) ));
		return d[0];
	}
	
	
	@Override public   void ShaderSource(int p_shader, java.lang.String p_source)
	{
		android.opengl.GLES20.glShaderSource(((int) (p_shader) ), haxe.lang.Runtime.toString(p_source));
	}
	
	
	@Override public   void AttachShader(int p_program, int p_shader)
	{
		android.opengl.GLES20.glAttachShader(((int) (p_program) ), ((int) (p_shader) ));
	}
	
	
	@Override public   void BindAttribLocation(int p_program, int p_location, java.lang.String p_name)
	{
		android.opengl.GLES20.glBindAttribLocation(((int) (p_program) ), ((int) (p_location) ), haxe.lang.Runtime.toString(p_name));
	}
	
	
	@Override public   int CreateProgram()
	{
		return android.opengl.GLES20.glCreateProgram();
	}
	
	
	@Override public   void DeleteProgram(int p_program)
	{
		android.opengl.GLES20.glDeleteProgram(((int) (p_program) ));
	}
	
	
	@Override public   int GetAttribLocation(int p_program, java.lang.String p_name)
	{
		return android.opengl.GLES20.glGetAttribLocation(((int) (p_program) ), haxe.lang.Runtime.toString(p_name));
	}
	
	
	@Override public   int GetUniformLocation(int p_program, java.lang.String p_name)
	{
		return android.opengl.GLES20.glGetUniformLocation(((int) (p_program) ), haxe.lang.Runtime.toString(p_name));
	}
	
	
	@Override public   java.lang.String GetProgramInfoLog(int p_program)
	{
		return android.opengl.GLES20.glGetProgramInfoLog(((int) (p_program) ));
	}
	
	
	@Override public   int GetProgramParameter(int p_program, int p_parameter)
	{
		int[] d = new int[((int) (1) )];
		android.opengl.GLES20.glGetProgramiv(((int) (p_program) ), ((int) (p_parameter) ), ((int[]) (d) ), ((int) (0) ));
		return d[0];
	}
	
	
	@Override public   void LinkProgram(int p_program)
	{
		android.opengl.GLES20.glLinkProgram(((int) (p_program) ));
	}
	
	
	@Override public   void UseProgram(int p_program)
	{
		android.opengl.GLES20.glUseProgram(((int) (p_program) ));
	}
	
	
	@Override public   void ActiveTexture(int p_slot)
	{
		android.opengl.GLES20.glActiveTexture(((int) (p_slot) ));
	}
	
	
	@Override public   void BindFramebuffer(int p_target, int p_id)
	{
		android.opengl.GLES20.glBindFramebuffer(((int) (p_target) ), ((int) (p_id) ));
	}
	
	
	@Override public   void BindRenderbuffer(int p_target, int p_id)
	{
		android.opengl.GLES20.glBindRenderbuffer(((int) (p_target) ), ((int) (p_id) ));
	}
	
	
	@Override public   void BindTexture(int p_target, int p_id)
	{
		android.opengl.GLES20.glBindTexture(((int) (p_target) ), ((int) (p_id) ));
	}
	
	
	@Override public   int CreateFramebuffer()
	{
		android.opengl.GLES20.glGenFramebuffers(((int) (1) ), ((int[]) (this.m_ids) ), ((int) (0) ));
		return this.m_ids[0];
	}
	
	
	@Override public   int CreateRenderbuffer()
	{
		android.opengl.GLES20.glGenRenderbuffers(((int) (1) ), ((int[]) (this.m_ids) ), ((int) (0) ));
		return this.m_ids[0];
	}
	
	
	@Override public   int CreateTexture()
	{
		android.opengl.GLES20.glGenTextures(((int) (1) ), ((int[]) (this.m_ids) ), ((int) (0) ));
		return this.m_ids[0];
	}
	
	
	@Override public   void DeleteFramebuffer(int p_id)
	{
		this.m_ids[0] = p_id;
		android.opengl.GLES20.glDeleteFramebuffers(((int) (1) ), ((int[]) (this.m_ids) ), ((int) (0) ));
	}
	
	
	@Override public   void DeleteRenderbuffer(int p_id)
	{
		this.m_ids[0] = p_id;
		android.opengl.GLES20.glDeleteRenderbuffers(((int) (1) ), ((int[]) (this.m_ids) ), ((int) (0) ));
	}
	
	
	@Override public   void DeleteTexture(int p_id)
	{
		this.m_ids[0] = p_id;
		android.opengl.GLES20.glDeleteTextures(((int) (1) ), ((int[]) (this.m_ids) ), ((int) (0) ));
	}
	
	
	@Override public   void FramebufferRenderbuffer(int p_target, int p_attachment, int p_renderbuffer_target, int p_renderbuffer_id)
	{
		android.opengl.GLES20.glFramebufferRenderbuffer(((int) (p_target) ), ((int) (p_attachment) ), ((int) (p_renderbuffer_target) ), ((int) (p_renderbuffer_id) ));
	}
	
	
	@Override public   void FramebufferTexture2D(int p_target, int p_attachment, int p_texture_target, int p_texture_id, int p_miplevel)
	{
		android.opengl.GLES20.glFramebufferTexture2D(((int) (p_target) ), ((int) (p_attachment) ), ((int) (p_texture_target) ), ((int) (p_texture_id) ), ((int) (p_miplevel) ));
	}
	
	
	@Override public   void GenerateMipmap(int p_target)
	{
		android.opengl.GLES20.glGenerateMipmap(((int) (p_target) ));
	}
	
	
	@Override public   void PixelStorei(int p_parameter, int p_value)
	{
		android.opengl.GLES20.glPixelStorei(((int) (p_parameter) ), ((int) (p_value) ));
	}
	
	
	@Override public   void RenderbufferStorage(int p_target, int p_format, int p_width, int p_height)
	{
		android.opengl.GLES20.glRenderbufferStorage(((int) (p_target) ), ((int) (p_format) ), ((int) (p_width) ), ((int) (p_height) ));
	}
	
	
	@Override public   void TexImage2D(int p_target, int p_level, int p_internal_format, int p_width, int p_height, int p_border, int p_format, int p_channel_type, haxor.io.Buffer p_data)
	{
		android.opengl.GLES20.glTexImage2D(((int) (p_target) ), ((int) (p_level) ), ((int) (p_internal_format) ), ((int) (p_width) ), ((int) (p_height) ), ((int) (p_border) ), ((int) (p_format) ), ((int) (p_channel_type) ), ((java.nio.Buffer) (p_data.m_buffer) ));
	}
	
	
	@Override public   void TexImage2DAlloc(int p_target, int p_level, int p_internal_format, int p_width, int p_height, int p_border, int p_format, int p_channel_type)
	{
		android.opengl.GLES20.glTexImage2D(((int) (p_target) ), ((int) (p_level) ), ((int) (p_internal_format) ), ((int) (p_width) ), ((int) (p_height) ), ((int) (p_border) ), ((int) (p_format) ), ((int) (p_channel_type) ), ((java.nio.Buffer) (null) ));
	}
	
	
	@Override public   void TexSubImage2D(int p_target, int p_level, int p_x, int p_y, int p_width, int p_height, int p_format, int p_channel_type, haxor.io.Buffer p_data)
	{
		android.opengl.GLES20.glTexSubImage2D(((int) (p_target) ), ((int) (p_level) ), ((int) (p_x) ), ((int) (p_y) ), ((int) (p_width) ), ((int) (p_height) ), ((int) (p_format) ), ((int) (p_channel_type) ), ((java.nio.Buffer) (p_data.m_buffer) ));
	}
	
	
	@Override public   void TexParameterf(int p_target, int p_parameter, double p_value)
	{
		android.opengl.GLES20.glTexParameterf(((int) (p_target) ), ((int) (p_parameter) ), ((float) (p_value) ));
	}
	
	
	@Override public   void TexParameteri(int p_target, int p_parameter, int p_value)
	{
		android.opengl.GLES20.glTexParameteri(((int) (p_target) ), ((int) (p_parameter) ), ((int) (p_value) ));
	}
	
	
	@Override public   void Uniform1f(int p_location, double p_x)
	{
		android.opengl.GLES20.glUniform1f(((int) (p_location) ), ((float) (p_x) ));
	}
	
	
	@Override public   void Uniform2f(int p_location, double p_x, double p_y)
	{
		android.opengl.GLES20.glUniform2f(((int) (p_location) ), ((float) (p_x) ), ((float) (p_y) ));
	}
	
	
	@Override public   void Uniform3f(int p_location, double p_x, double p_y, double p_z)
	{
		android.opengl.GLES20.glUniform3f(((int) (p_location) ), ((float) (p_x) ), ((float) (p_y) ), ((float) (p_z) ));
	}
	
	
	@Override public   void Uniform4f(int p_location, double p_x, double p_y, double p_z, double p_w)
	{
		android.opengl.GLES20.glUniform4f(((int) (p_location) ), ((float) (p_x) ), ((float) (p_y) ), ((float) (p_z) ), ((float) (p_w) ));
	}
	
	
	@Override public   void Uniform1i(int p_location, int p_x)
	{
		android.opengl.GLES20.glUniform1i(((int) (p_location) ), ((int) (p_x) ));
	}
	
	
	@Override public   void Uniform2i(int p_location, int p_x, int p_y)
	{
		android.opengl.GLES20.glUniform2i(((int) (p_location) ), ((int) (p_x) ), ((int) (p_y) ));
	}
	
	
	@Override public   void Uniform3i(int p_location, int p_x, int p_y, int p_z)
	{
		android.opengl.GLES20.glUniform3i(((int) (p_location) ), ((int) (p_x) ), ((int) (p_y) ), ((int) (p_z) ));
	}
	
	
	@Override public   void Uniform4i(int p_location, int p_x, int p_y, int p_z, int p_w)
	{
		android.opengl.GLES20.glUniform4i(((int) (p_location) ), ((int) (p_x) ), ((int) (p_y) ), ((int) (p_z) ), ((int) (p_w) ));
	}
	
	
	@Override public   void Uniform1fv(int p_location, haxor.io.FloatArray p_v)
	{
		android.opengl.GLES20.glUniform1fv(((int) (p_location) ), ((int) (p_v.m_length) ), ((java.nio.FloatBuffer) (p_v.aux) ));
	}
	
	
	@Override public   void Uniform2fv(int p_location, haxor.io.FloatArray p_v)
	{
		android.opengl.GLES20.glUniform2fv(((int) (p_location) ), ( p_v.m_length / 2 ), ((java.nio.FloatBuffer) (p_v.aux) ));
	}
	
	
	@Override public   void Uniform3fv(int p_location, haxor.io.FloatArray p_v)
	{
		android.opengl.GLES20.glUniform3fv(((int) (p_location) ), ( p_v.m_length / 3 ), ((java.nio.FloatBuffer) (p_v.aux) ));
	}
	
	
	@Override public   void Uniform4fv(int p_location, haxor.io.FloatArray p_v)
	{
		android.opengl.GLES20.glUniform4fv(((int) (p_location) ), ( p_v.m_length / 4 ), ((java.nio.FloatBuffer) (p_v.aux) ));
	}
	
	
	@Override public   void Uniform1iv(int p_location, haxor.io.Int32Array p_v)
	{
		android.opengl.GLES20.glUniform1iv(((int) (p_location) ), ((int) (p_v.m_length) ), ((java.nio.IntBuffer) (p_v.aux) ));
	}
	
	
	@Override public   void Uniform2iv(int p_location, haxor.io.Int32Array p_v)
	{
		android.opengl.GLES20.glUniform2iv(((int) (p_location) ), ( p_v.m_length / 2 ), ((java.nio.IntBuffer) (p_v.aux) ));
	}
	
	
	@Override public   void Uniform3iv(int p_location, haxor.io.Int32Array p_v)
	{
		android.opengl.GLES20.glUniform3iv(((int) (p_location) ), ( p_v.m_length / 3 ), ((java.nio.IntBuffer) (p_v.aux) ));
	}
	
	
	@Override public   void Uniform4iv(int p_location, haxor.io.Int32Array p_v)
	{
		android.opengl.GLES20.glUniform4iv(((int) (p_location) ), ( p_v.m_length / 4 ), ((java.nio.IntBuffer) (p_v.aux) ));
	}
	
	
	@Override public   void UniformMatrix2fv(int p_location, boolean p_transpose, haxor.io.FloatArray p_v)
	{
		android.opengl.GLES20.glUniformMatrix2fv(((int) (p_location) ), ( p_v.m_length / 4 ), haxe.lang.Runtime.toBool(p_transpose), ((java.nio.FloatBuffer) (p_v.aux) ));
	}
	
	
	@Override public   void UniformMatrix3fv(int p_location, boolean p_transpose, haxor.io.FloatArray p_v)
	{
		android.opengl.GLES20.glUniformMatrix3fv(((int) (p_location) ), ( p_v.m_length / 9 ), haxe.lang.Runtime.toBool(p_transpose), ((java.nio.FloatBuffer) (p_v.aux) ));
	}
	
	
	@Override public   void UniformMatrix4fv(int p_location, boolean p_transpose, haxor.io.FloatArray p_v)
	{
		android.opengl.GLES20.glUniformMatrix4fv(((int) (p_location) ), ( p_v.m_length / 16 ), haxe.lang.Runtime.toBool(p_transpose), ((java.nio.FloatBuffer) (p_v.aux) ));
	}
	
	
	@Override public   void BlendFunc(int p_src, int p_dst)
	{
		android.opengl.GLES20.glBlendFunc(((int) (p_src) ), ((int) (p_dst) ));
	}
	
	
	@Override public   void Disable(int p_flag)
	{
		android.opengl.GLES20.glDisable(((int) (p_flag) ));
	}
	
	
	@Override public   void Enable(int p_flag)
	{
		android.opengl.GLES20.glEnable(((int) (p_flag) ));
	}
	
	
	@Override public   void DepthMask(boolean p_flag)
	{
		android.opengl.GLES20.glDepthMask(haxe.lang.Runtime.toBool(p_flag));
	}
	
	
	@Override public   void DepthFunc(int p_flag)
	{
		android.opengl.GLES20.glDepthFunc(((int) (p_flag) ));
	}
	
	
	@Override public   void CullFace(int p_face)
	{
		android.opengl.GLES20.glCullFace(((int) (p_face) ));
	}
	
	
	@Override public   void FrontFace(int p_face)
	{
		android.opengl.GLES20.glFrontFace(((int) (p_face) ));
	}
	
	
	@Override public   void Clear(int p_flag)
	{
		android.opengl.GLES20.glClear(((int) (p_flag) ));
	}
	
	
	@Override public   void ClearDepth(double p_value)
	{
		android.opengl.GLES20.glClearDepthf(((float) (p_value) ));
	}
	
	
	@Override public   void ClearColor(double p_r, double p_g, double p_b, double p_a)
	{
		android.opengl.GLES20.glClearColor(((float) (p_r) ), ((float) (p_g) ), ((float) (p_b) ), ((float) (p_a) ));
	}
	
	
	@Override public   void Viewport(int p_x, int p_y, int p_width, int p_height)
	{
		android.opengl.GLES20.glViewport(((int) (p_x) ), ((int) (p_y) ), ((int) (p_width) ), ((int) (p_height) ));
	}
	
	
	@Override public   void Scissor(int p_x, int p_y, int p_width, int p_height)
	{
		android.opengl.GLES20.glScissor(((int) (p_x) ), ((int) (p_y) ), ((int) (p_width) ), ((int) (p_height) ));
	}
	
	
	@Override public   void ReadPixels(int p_x, int p_y, int p_width, int p_height, int p_format, int p_type, haxor.io.Buffer p_pixels)
	{
		android.opengl.GLES20.glReadPixels(((int) (p_x) ), ((int) (p_y) ), ((int) (p_width) ), ((int) (p_height) ), ((int) (p_format) ), ((int) (p_type) ), ((java.nio.Buffer) (p_pixels.m_buffer) ));
	}
	
	
	@Override public   int GetErrorCode()
	{
		return android.opengl.GLES20.glGetError();
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef54833 = true;
			switch (field.hashCode())
			{
				case 103598054:
				{
					if (field.equals("m_ids")) 
					{
						__temp_executeDef54833 = false;
						this.m_ids = ((int[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 99:
				{
					if (field.equals("c")) 
					{
						__temp_executeDef54833 = false;
						this.c = ((android.opengl.GLSurfaceView) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54833) 
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
			boolean __temp_executeDef54834 = true;
			switch (field.hashCode())
			{
				case 483751295:
				{
					if (field.equals("GetErrorCode")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetErrorCode"))) );
					}
					
					break;
				}
				
				
				case 99:
				{
					if (field.equals("c")) 
					{
						__temp_executeDef54834 = false;
						return this.c;
					}
					
					break;
				}
				
				
				case 1397397507:
				{
					if (field.equals("ReadPixels")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ReadPixels"))) );
					}
					
					break;
				}
				
				
				case 103598054:
				{
					if (field.equals("m_ids")) 
					{
						__temp_executeDef54834 = false;
						return this.m_ids;
					}
					
					break;
				}
				
				
				case -711810116:
				{
					if (field.equals("Scissor")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Scissor"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case 1261329606:
				{
					if (field.equals("Viewport")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Viewport"))) );
					}
					
					break;
				}
				
				
				case 324440887:
				{
					if (field.equals("OnPause")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnPause"))) );
					}
					
					break;
				}
				
				
				case 1234652470:
				{
					if (field.equals("ClearColor")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ClearColor"))) );
					}
					
					break;
				}
				
				
				case 1528627980:
				{
					if (field.equals("OnResume")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnResume"))) );
					}
					
					break;
				}
				
				
				case 1235282070:
				{
					if (field.equals("ClearDepth")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ClearDepth"))) );
					}
					
					break;
				}
				
				
				case -1602602212:
				{
					if (field.equals("CheckExtensions")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CheckExtensions"))) );
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case -1896767747:
				{
					if (field.equals("BindBuffer")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BindBuffer"))) );
					}
					
					break;
				}
				
				
				case 2131299334:
				{
					if (field.equals("FrontFace")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FrontFace"))) );
					}
					
					break;
				}
				
				
				case -395725782:
				{
					if (field.equals("BufferData")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BufferData"))) );
					}
					
					break;
				}
				
				
				case 461794063:
				{
					if (field.equals("CullFace")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CullFace"))) );
					}
					
					break;
				}
				
				
				case 1601301898:
				{
					if (field.equals("BufferSubData")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BufferSubData"))) );
					}
					
					break;
				}
				
				
				case 1317758983:
				{
					if (field.equals("DepthFunc")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DepthFunc"))) );
					}
					
					break;
				}
				
				
				case 1213974652:
				{
					if (field.equals("CreateBuffer")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateBuffer"))) );
					}
					
					break;
				}
				
				
				case 1317948463:
				{
					if (field.equals("DepthMask")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DepthMask"))) );
					}
					
					break;
				}
				
				
				case 1387908030:
				{
					if (field.equals("DrawArrays")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawArrays"))) );
					}
					
					break;
				}
				
				
				case 2079986083:
				{
					if (field.equals("Enable")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Enable"))) );
					}
					
					break;
				}
				
				
				case -670686597:
				{
					if (field.equals("DrawElements")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawElements"))) );
					}
					
					break;
				}
				
				
				case -959006008:
				{
					if (field.equals("Disable")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Disable"))) );
					}
					
					break;
				}
				
				
				case -1081856533:
				{
					if (field.equals("DeleteBuffer")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteBuffer"))) );
					}
					
					break;
				}
				
				
				case -1395603819:
				{
					if (field.equals("BlendFunc")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BlendFunc"))) );
					}
					
					break;
				}
				
				
				case 1204954230:
				{
					if (field.equals("DisableVertexAttrib")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DisableVertexAttrib"))) );
					}
					
					break;
				}
				
				
				case -1966618257:
				{
					if (field.equals("UniformMatrix4fv")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UniformMatrix4fv"))) );
					}
					
					break;
				}
				
				
				case 1857751761:
				{
					if (field.equals("EnableVertexAttrib")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("EnableVertexAttrib"))) );
					}
					
					break;
				}
				
				
				case -1966619218:
				{
					if (field.equals("UniformMatrix3fv")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UniformMatrix3fv"))) );
					}
					
					break;
				}
				
				
				case -454645567:
				{
					if (field.equals("VertexAttrib3f")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("VertexAttrib3f"))) );
					}
					
					break;
				}
				
				
				case -1966620179:
				{
					if (field.equals("UniformMatrix2fv")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UniformMatrix2fv"))) );
					}
					
					break;
				}
				
				
				case -454645536:
				{
					if (field.equals("VertexAttrib4f")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("VertexAttrib4f"))) );
					}
					
					break;
				}
				
				
				case 1153697357:
				{
					if (field.equals("Uniform4iv")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform4iv"))) );
					}
					
					break;
				}
				
				
				case 1170563247:
				{
					if (field.equals("VertexAttribPointer")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("VertexAttribPointer"))) );
					}
					
					break;
				}
				
				
				case 1153696396:
				{
					if (field.equals("Uniform3iv")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform3iv"))) );
					}
					
					break;
				}
				
				
				case 490879960:
				{
					if (field.equals("CompileShader")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CompileShader"))) );
					}
					
					break;
				}
				
				
				case 1153695435:
				{
					if (field.equals("Uniform2iv")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform2iv"))) );
					}
					
					break;
				}
				
				
				case 1688513569:
				{
					if (field.equals("CreateShader")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateShader"))) );
					}
					
					break;
				}
				
				
				case 1153694474:
				{
					if (field.equals("Uniform1iv")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform1iv"))) );
					}
					
					break;
				}
				
				
				case -440035976:
				{
					if (field.equals("DetachShader")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DetachShader"))) );
					}
					
					break;
				}
				
				
				case 1153697264:
				{
					if (field.equals("Uniform4fv")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform4fv"))) );
					}
					
					break;
				}
				
				
				case -607317616:
				{
					if (field.equals("DeleteShader")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteShader"))) );
					}
					
					break;
				}
				
				
				case 1153696303:
				{
					if (field.equals("Uniform3fv")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform3fv"))) );
					}
					
					break;
				}
				
				
				case 1073071227:
				{
					if (field.equals("GetShaderInfoLog")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetShaderInfoLog"))) );
					}
					
					break;
				}
				
				
				case 1153695342:
				{
					if (field.equals("Uniform2fv")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform2fv"))) );
					}
					
					break;
				}
				
				
				case 1169816366:
				{
					if (field.equals("GetShaderParameter")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetShaderParameter"))) );
					}
					
					break;
				}
				
				
				case 1153694381:
				{
					if (field.equals("Uniform1fv")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform1fv"))) );
					}
					
					break;
				}
				
				
				case -1805459328:
				{
					if (field.equals("ShaderSource")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ShaderSource"))) );
					}
					
					break;
				}
				
				
				case 1145594697:
				{
					if (field.equals("Uniform4i")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform4i"))) );
					}
					
					break;
				}
				
				
				case -2011750742:
				{
					if (field.equals("AttachShader")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("AttachShader"))) );
					}
					
					break;
				}
				
				
				case 1145594666:
				{
					if (field.equals("Uniform3i")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform3i"))) );
					}
					
					break;
				}
				
				
				case 1781319260:
				{
					if (field.equals("BindAttribLocation")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BindAttribLocation"))) );
					}
					
					break;
				}
				
				
				case 1145594635:
				{
					if (field.equals("Uniform2i")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform2i"))) );
					}
					
					break;
				}
				
				
				case -1558875704:
				{
					if (field.equals("CreateProgram")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateProgram"))) );
					}
					
					break;
				}
				
				
				case 1145594604:
				{
					if (field.equals("Uniform1i")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform1i"))) );
					}
					
					break;
				}
				
				
				case 284801593:
				{
					if (field.equals("DeleteProgram")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteProgram"))) );
					}
					
					break;
				}
				
				
				case 1145594694:
				{
					if (field.equals("Uniform4f")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform4f"))) );
					}
					
					break;
				}
				
				
				case -1248406155:
				{
					if (field.equals("GetAttribLocation")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetAttribLocation"))) );
					}
					
					break;
				}
				
				
				case 1145594663:
				{
					if (field.equals("Uniform3f")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform3f"))) );
					}
					
					break;
				}
				
				
				case 1131050867:
				{
					if (field.equals("GetUniformLocation")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetUniformLocation"))) );
					}
					
					break;
				}
				
				
				case 1145594632:
				{
					if (field.equals("Uniform2f")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform2f"))) );
					}
					
					break;
				}
				
				
				case 662129000:
				{
					if (field.equals("GetProgramInfoLog")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetProgramInfoLog"))) );
					}
					
					break;
				}
				
				
				case 1145594601:
				{
					if (field.equals("Uniform1f")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Uniform1f"))) );
					}
					
					break;
				}
				
				
				case 1391327451:
				{
					if (field.equals("GetProgramParameter")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetProgramParameter"))) );
					}
					
					break;
				}
				
				
				case -1452160697:
				{
					if (field.equals("TexParameteri")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TexParameteri"))) );
					}
					
					break;
				}
				
				
				case -682516214:
				{
					if (field.equals("LinkProgram")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("LinkProgram"))) );
					}
					
					break;
				}
				
				
				case -1452160700:
				{
					if (field.equals("TexParameterf")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TexParameterf"))) );
					}
					
					break;
				}
				
				
				case 62838557:
				{
					if (field.equals("UseProgram")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UseProgram"))) );
					}
					
					break;
				}
				
				
				case -1480581644:
				{
					if (field.equals("TexSubImage2D")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TexSubImage2D"))) );
					}
					
					break;
				}
				
				
				case -1798288619:
				{
					if (field.equals("ActiveTexture")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ActiveTexture"))) );
					}
					
					break;
				}
				
				
				case -51526673:
				{
					if (field.equals("TexImage2DAlloc")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TexImage2DAlloc"))) );
					}
					
					break;
				}
				
				
				case -1057563824:
				{
					if (field.equals("BindFramebuffer")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BindFramebuffer"))) );
					}
					
					break;
				}
				
				
				case 768888550:
				{
					if (field.equals("TexImage2D")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("TexImage2D"))) );
					}
					
					break;
				}
				
				
				case -1967581613:
				{
					if (field.equals("BindRenderbuffer")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BindRenderbuffer"))) );
					}
					
					break;
				}
				
				
				case 1800947749:
				{
					if (field.equals("RenderbufferStorage")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("RenderbufferStorage"))) );
					}
					
					break;
				}
				
				
				case -316071426:
				{
					if (field.equals("BindTexture")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BindTexture"))) );
					}
					
					break;
				}
				
				
				case 450629038:
				{
					if (field.equals("PixelStorei")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("PixelStorei"))) );
					}
					
					break;
				}
				
				
				case 691390769:
				{
					if (field.equals("CreateFramebuffer")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateFramebuffer"))) );
					}
					
					break;
				}
				
				
				case 1000706173:
				{
					if (field.equals("GenerateMipmap")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GenerateMipmap"))) );
					}
					
					break;
				}
				
				
				case 710403218:
				{
					if (field.equals("CreateRenderbuffer")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateRenderbuffer"))) );
					}
					
					break;
				}
				
				
				case 962410336:
				{
					if (field.equals("FramebufferTexture2D")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FramebufferTexture2D"))) );
					}
					
					break;
				}
				
				
				case 1627662431:
				{
					if (field.equals("CreateTexture")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateTexture"))) );
					}
					
					break;
				}
				
				
				case 683029955:
				{
					if (field.equals("FramebufferRenderbuffer")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FramebufferRenderbuffer"))) );
					}
					
					break;
				}
				
				
				case 32403746:
				{
					if (field.equals("DeleteFramebuffer")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteFramebuffer"))) );
					}
					
					break;
				}
				
				
				case -823627568:
				{
					if (field.equals("DeleteTexture")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteTexture"))) );
					}
					
					break;
				}
				
				
				case 1756641985:
				{
					if (field.equals("DeleteRenderbuffer")) 
					{
						__temp_executeDef54834 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteRenderbuffer"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54834) 
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
			int __temp_hash54836 = field.hashCode();
			boolean __temp_executeDef54835 = true;
			switch (__temp_hash54836)
			{
				case 483751295:case 1397397507:case -711810116:case 1261329606:case 1234652470:case 1235282070:case 65193517:case 2131299334:case 461794063:case 1317758983:case 1317948463:case 2079986083:case -959006008:case -1395603819:case -1966618257:case -1966619218:case -1966620179:case 1153697357:case 1153696396:case 1153695435:case 1153694474:case 1153697264:case 1153696303:case 1153695342:case 1153694381:case 1145594697:case 1145594666:case 1145594635:case 1145594604:case 1145594694:case 1145594663:case 1145594632:case 1145594601:case -1452160697:case -1452160700:case -1480581644:case -51526673:case 768888550:case 1800947749:case 450629038:case 1000706173:case 962410336:case 683029955:case -823627568:case 1756641985:case 32403746:case 1627662431:case 710403218:case 691390769:case -316071426:case -1967581613:case -1057563824:case -1798288619:case 62838557:case -682516214:case 1391327451:case 662129000:case 1131050867:case -1248406155:case 284801593:case -1558875704:case 1781319260:case -2011750742:case -1805459328:case 1169816366:case 1073071227:case -607317616:case -440035976:case 1688513569:case 490879960:case 1170563247:case -454645536:case -454645567:case 1857751761:case 1204954230:case -1081856533:case -670686597:case 1387908030:case 1213974652:case 1601301898:case -395725782:case -1896767747:case -1602602212:
				{
					if (( (( ( __temp_hash54836 == 483751295 ) && field.equals("GetErrorCode") )) || ( (( ( __temp_hash54836 == 1397397507 ) && field.equals("ReadPixels") )) || ( (( ( __temp_hash54836 == -711810116 ) && field.equals("Scissor") )) || ( (( ( __temp_hash54836 == 1261329606 ) && field.equals("Viewport") )) || ( (( ( __temp_hash54836 == 1234652470 ) && field.equals("ClearColor") )) || ( (( ( __temp_hash54836 == 1235282070 ) && field.equals("ClearDepth") )) || ( (( ( __temp_hash54836 == 65193517 ) && field.equals("Clear") )) || ( (( ( __temp_hash54836 == 2131299334 ) && field.equals("FrontFace") )) || ( (( ( __temp_hash54836 == 461794063 ) && field.equals("CullFace") )) || ( (( ( __temp_hash54836 == 1317758983 ) && field.equals("DepthFunc") )) || ( (( ( __temp_hash54836 == 1317948463 ) && field.equals("DepthMask") )) || ( (( ( __temp_hash54836 == 2079986083 ) && field.equals("Enable") )) || ( (( ( __temp_hash54836 == -959006008 ) && field.equals("Disable") )) || ( (( ( __temp_hash54836 == -1395603819 ) && field.equals("BlendFunc") )) || ( (( ( __temp_hash54836 == -1966618257 ) && field.equals("UniformMatrix4fv") )) || ( (( ( __temp_hash54836 == -1966619218 ) && field.equals("UniformMatrix3fv") )) || ( (( ( __temp_hash54836 == -1966620179 ) && field.equals("UniformMatrix2fv") )) || ( (( ( __temp_hash54836 == 1153697357 ) && field.equals("Uniform4iv") )) || ( (( ( __temp_hash54836 == 1153696396 ) && field.equals("Uniform3iv") )) || ( (( ( __temp_hash54836 == 1153695435 ) && field.equals("Uniform2iv") )) || ( (( ( __temp_hash54836 == 1153694474 ) && field.equals("Uniform1iv") )) || ( (( ( __temp_hash54836 == 1153697264 ) && field.equals("Uniform4fv") )) || ( (( ( __temp_hash54836 == 1153696303 ) && field.equals("Uniform3fv") )) || ( (( ( __temp_hash54836 == 1153695342 ) && field.equals("Uniform2fv") )) || ( (( ( __temp_hash54836 == 1153694381 ) && field.equals("Uniform1fv") )) || ( (( ( __temp_hash54836 == 1145594697 ) && field.equals("Uniform4i") )) || ( (( ( __temp_hash54836 == 1145594666 ) && field.equals("Uniform3i") )) || ( (( ( __temp_hash54836 == 1145594635 ) && field.equals("Uniform2i") )) || ( (( ( __temp_hash54836 == 1145594604 ) && field.equals("Uniform1i") )) || ( (( ( __temp_hash54836 == 1145594694 ) && field.equals("Uniform4f") )) || ( (( ( __temp_hash54836 == 1145594663 ) && field.equals("Uniform3f") )) || ( (( ( __temp_hash54836 == 1145594632 ) && field.equals("Uniform2f") )) || ( (( ( __temp_hash54836 == 1145594601 ) && field.equals("Uniform1f") )) || ( (( ( __temp_hash54836 == -1452160697 ) && field.equals("TexParameteri") )) || ( (( ( __temp_hash54836 == -1452160700 ) && field.equals("TexParameterf") )) || ( (( ( __temp_hash54836 == -1480581644 ) && field.equals("TexSubImage2D") )) || ( (( ( __temp_hash54836 == -51526673 ) && field.equals("TexImage2DAlloc") )) || ( (( ( __temp_hash54836 == 768888550 ) && field.equals("TexImage2D") )) || ( (( ( __temp_hash54836 == 1800947749 ) && field.equals("RenderbufferStorage") )) || ( (( ( __temp_hash54836 == 450629038 ) && field.equals("PixelStorei") )) || ( (( ( __temp_hash54836 == 1000706173 ) && field.equals("GenerateMipmap") )) || ( (( ( __temp_hash54836 == 962410336 ) && field.equals("FramebufferTexture2D") )) || ( (( ( __temp_hash54836 == 683029955 ) && field.equals("FramebufferRenderbuffer") )) || ( (( ( __temp_hash54836 == -823627568 ) && field.equals("DeleteTexture") )) || ( (( ( __temp_hash54836 == 1756641985 ) && field.equals("DeleteRenderbuffer") )) || ( (( ( __temp_hash54836 == 32403746 ) && field.equals("DeleteFramebuffer") )) || ( (( ( __temp_hash54836 == 1627662431 ) && field.equals("CreateTexture") )) || ( (( ( __temp_hash54836 == 710403218 ) && field.equals("CreateRenderbuffer") )) || ( (( ( __temp_hash54836 == 691390769 ) && field.equals("CreateFramebuffer") )) || ( (( ( __temp_hash54836 == -316071426 ) && field.equals("BindTexture") )) || ( (( ( __temp_hash54836 == -1967581613 ) && field.equals("BindRenderbuffer") )) || ( (( ( __temp_hash54836 == -1057563824 ) && field.equals("BindFramebuffer") )) || ( (( ( __temp_hash54836 == -1798288619 ) && field.equals("ActiveTexture") )) || ( (( ( __temp_hash54836 == 62838557 ) && field.equals("UseProgram") )) || ( (( ( __temp_hash54836 == -682516214 ) && field.equals("LinkProgram") )) || ( (( ( __temp_hash54836 == 1391327451 ) && field.equals("GetProgramParameter") )) || ( (( ( __temp_hash54836 == 662129000 ) && field.equals("GetProgramInfoLog") )) || ( (( ( __temp_hash54836 == 1131050867 ) && field.equals("GetUniformLocation") )) || ( (( ( __temp_hash54836 == -1248406155 ) && field.equals("GetAttribLocation") )) || ( (( ( __temp_hash54836 == 284801593 ) && field.equals("DeleteProgram") )) || ( (( ( __temp_hash54836 == -1558875704 ) && field.equals("CreateProgram") )) || ( (( ( __temp_hash54836 == 1781319260 ) && field.equals("BindAttribLocation") )) || ( (( ( __temp_hash54836 == -2011750742 ) && field.equals("AttachShader") )) || ( (( ( __temp_hash54836 == -1805459328 ) && field.equals("ShaderSource") )) || ( (( ( __temp_hash54836 == 1169816366 ) && field.equals("GetShaderParameter") )) || ( (( ( __temp_hash54836 == 1073071227 ) && field.equals("GetShaderInfoLog") )) || ( (( ( __temp_hash54836 == -607317616 ) && field.equals("DeleteShader") )) || ( (( ( __temp_hash54836 == -440035976 ) && field.equals("DetachShader") )) || ( (( ( __temp_hash54836 == 1688513569 ) && field.equals("CreateShader") )) || ( (( ( __temp_hash54836 == 490879960 ) && field.equals("CompileShader") )) || ( (( ( __temp_hash54836 == 1170563247 ) && field.equals("VertexAttribPointer") )) || ( (( ( __temp_hash54836 == -454645536 ) && field.equals("VertexAttrib4f") )) || ( (( ( __temp_hash54836 == -454645567 ) && field.equals("VertexAttrib3f") )) || ( (( ( __temp_hash54836 == 1857751761 ) && field.equals("EnableVertexAttrib") )) || ( (( ( __temp_hash54836 == 1204954230 ) && field.equals("DisableVertexAttrib") )) || ( (( ( __temp_hash54836 == -1081856533 ) && field.equals("DeleteBuffer") )) || ( (( ( __temp_hash54836 == -670686597 ) && field.equals("DrawElements") )) || ( (( ( __temp_hash54836 == 1387908030 ) && field.equals("DrawArrays") )) || ( (( ( __temp_hash54836 == 1213974652 ) && field.equals("CreateBuffer") )) || ( (( ( __temp_hash54836 == 1601301898 ) && field.equals("BufferSubData") )) || ( (( ( __temp_hash54836 == -395725782 ) && field.equals("BufferData") )) || ( (( ( __temp_hash54836 == -1896767747 ) && field.equals("BindBuffer") )) || field.equals("CheckExtensions") ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )) 
					{
						__temp_executeDef54835 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef54835 = false;
						return this.Initialize(((haxor.platform.android.Entry) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 1528627980:
				{
					if (field.equals("OnResume")) 
					{
						__temp_executeDef54835 = false;
						this.OnResume();
					}
					
					break;
				}
				
				
				case 324440887:
				{
					if (field.equals("OnPause")) 
					{
						__temp_executeDef54835 = false;
						this.OnPause();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54835) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_ids");
		baseArr.push("c");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


