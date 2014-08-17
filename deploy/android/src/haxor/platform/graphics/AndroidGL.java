package haxor.platform.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class AndroidGL extends haxor.platform.graphics.GraphicContext
{
	public    AndroidGL(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    AndroidGL(haxor.core.BaseApplication p_application)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.platform.graphics.AndroidGL.__hx_ctor_haxor_platform_graphics_AndroidGL(this, p_application);
	}
	
	
	public static   void __hx_ctor_haxor_platform_graphics_AndroidGL(haxor.platform.graphics.AndroidGL __temp_me27922, haxor.core.BaseApplication p_application)
	{
		haxor.platform.graphics.GraphicContext.__hx_ctor_haxor_platform_graphics_GraphicContext(__temp_me27922, p_application);
		__temp_me27922.m_api = haxor.platform.graphics.GraphicAPI.OpenGLES;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.graphics.AndroidGL(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.graphics.AndroidGL(((haxor.core.BaseApplication) (arr.__get(0)) ));
	}
	
	
	public  android.opengl.GLSurfaceView c;
	
	public  int[] m_ids;
	
	public   boolean Initialize(haxor.platform.android.Entry p_entry, java.lang.Object p_version)
	{
		int __temp_p_version27921 = ( (( p_version == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_version)) )) );
		if (( p_entry == null )) 
		{
			haxor.core.Console.Log("Graphics> Invalid Entry Activity.", null);
			return false;
		}
		
		int cv = __temp_p_version27921;
		
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
		haxor.core.Console.Log(( ( ( ( ( ( "Graphics> Initialize Android GLES version[" + __temp_p_version27921 ) + "] Resolution[" ) + w ) + "," ) + h ) + "]" ), 1);
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
	
	
	@Override public   int GetErrorCode()
	{
		return android.opengl.GLES20.glGetError();
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef28126 = true;
			switch (field.hashCode())
			{
				case 103598054:
				{
					if (field.equals("m_ids")) 
					{
						__temp_executeDef28126 = false;
						this.m_ids = ((int[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 99:
				{
					if (field.equals("c")) 
					{
						__temp_executeDef28126 = false;
						this.c = ((android.opengl.GLSurfaceView) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28126) 
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
			boolean __temp_executeDef28127 = true;
			switch (field.hashCode())
			{
				case 483751295:
				{
					if (field.equals("GetErrorCode")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetErrorCode"))) );
					}
					
					break;
				}
				
				
				case 99:
				{
					if (field.equals("c")) 
					{
						__temp_executeDef28127 = false;
						return this.c;
					}
					
					break;
				}
				
				
				case 1234652470:
				{
					if (field.equals("ClearColor")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ClearColor"))) );
					}
					
					break;
				}
				
				
				case 103598054:
				{
					if (field.equals("m_ids")) 
					{
						__temp_executeDef28127 = false;
						return this.m_ids;
					}
					
					break;
				}
				
				
				case 1235282070:
				{
					if (field.equals("ClearDepth")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ClearDepth"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case 324440887:
				{
					if (field.equals("OnPause")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnPause"))) );
					}
					
					break;
				}
				
				
				case 2131299334:
				{
					if (field.equals("FrontFace")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("FrontFace"))) );
					}
					
					break;
				}
				
				
				case 1528627980:
				{
					if (field.equals("OnResume")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnResume"))) );
					}
					
					break;
				}
				
				
				case 461794063:
				{
					if (field.equals("CullFace")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CullFace"))) );
					}
					
					break;
				}
				
				
				case -1602602212:
				{
					if (field.equals("CheckExtensions")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CheckExtensions"))) );
					}
					
					break;
				}
				
				
				case 1317758983:
				{
					if (field.equals("DepthFunc")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DepthFunc"))) );
					}
					
					break;
				}
				
				
				case -1896767747:
				{
					if (field.equals("BindBuffer")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BindBuffer"))) );
					}
					
					break;
				}
				
				
				case 1317948463:
				{
					if (field.equals("DepthMask")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DepthMask"))) );
					}
					
					break;
				}
				
				
				case -395725782:
				{
					if (field.equals("BufferData")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BufferData"))) );
					}
					
					break;
				}
				
				
				case 2079986083:
				{
					if (field.equals("Enable")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Enable"))) );
					}
					
					break;
				}
				
				
				case 1601301898:
				{
					if (field.equals("BufferSubData")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BufferSubData"))) );
					}
					
					break;
				}
				
				
				case -959006008:
				{
					if (field.equals("Disable")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Disable"))) );
					}
					
					break;
				}
				
				
				case 1213974652:
				{
					if (field.equals("CreateBuffer")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateBuffer"))) );
					}
					
					break;
				}
				
				
				case -1395603819:
				{
					if (field.equals("BlendFunc")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BlendFunc"))) );
					}
					
					break;
				}
				
				
				case 1387908030:
				{
					if (field.equals("DrawArrays")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawArrays"))) );
					}
					
					break;
				}
				
				
				case 62838557:
				{
					if (field.equals("UseProgram")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UseProgram"))) );
					}
					
					break;
				}
				
				
				case -670686597:
				{
					if (field.equals("DrawElements")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DrawElements"))) );
					}
					
					break;
				}
				
				
				case -682516214:
				{
					if (field.equals("LinkProgram")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("LinkProgram"))) );
					}
					
					break;
				}
				
				
				case -1081856533:
				{
					if (field.equals("DeleteBuffer")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteBuffer"))) );
					}
					
					break;
				}
				
				
				case 1391327451:
				{
					if (field.equals("GetProgramParameter")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetProgramParameter"))) );
					}
					
					break;
				}
				
				
				case 1204954230:
				{
					if (field.equals("DisableVertexAttrib")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DisableVertexAttrib"))) );
					}
					
					break;
				}
				
				
				case 662129000:
				{
					if (field.equals("GetProgramInfoLog")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetProgramInfoLog"))) );
					}
					
					break;
				}
				
				
				case 1857751761:
				{
					if (field.equals("EnableVertexAttrib")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("EnableVertexAttrib"))) );
					}
					
					break;
				}
				
				
				case -1248406155:
				{
					if (field.equals("GetAttribLocation")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetAttribLocation"))) );
					}
					
					break;
				}
				
				
				case -454645567:
				{
					if (field.equals("VertexAttrib3f")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("VertexAttrib3f"))) );
					}
					
					break;
				}
				
				
				case 284801593:
				{
					if (field.equals("DeleteProgram")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteProgram"))) );
					}
					
					break;
				}
				
				
				case -454645536:
				{
					if (field.equals("VertexAttrib4f")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("VertexAttrib4f"))) );
					}
					
					break;
				}
				
				
				case -1558875704:
				{
					if (field.equals("CreateProgram")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateProgram"))) );
					}
					
					break;
				}
				
				
				case 1170563247:
				{
					if (field.equals("VertexAttribPointer")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("VertexAttribPointer"))) );
					}
					
					break;
				}
				
				
				case 1781319260:
				{
					if (field.equals("BindAttribLocation")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BindAttribLocation"))) );
					}
					
					break;
				}
				
				
				case 490879960:
				{
					if (field.equals("CompileShader")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CompileShader"))) );
					}
					
					break;
				}
				
				
				case -2011750742:
				{
					if (field.equals("AttachShader")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("AttachShader"))) );
					}
					
					break;
				}
				
				
				case 1688513569:
				{
					if (field.equals("CreateShader")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CreateShader"))) );
					}
					
					break;
				}
				
				
				case -1805459328:
				{
					if (field.equals("ShaderSource")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ShaderSource"))) );
					}
					
					break;
				}
				
				
				case -440035976:
				{
					if (field.equals("DetachShader")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DetachShader"))) );
					}
					
					break;
				}
				
				
				case 1169816366:
				{
					if (field.equals("GetShaderParameter")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetShaderParameter"))) );
					}
					
					break;
				}
				
				
				case -607317616:
				{
					if (field.equals("DeleteShader")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("DeleteShader"))) );
					}
					
					break;
				}
				
				
				case 1073071227:
				{
					if (field.equals("GetShaderInfoLog")) 
					{
						__temp_executeDef28127 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetShaderInfoLog"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28127) 
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
			int __temp_hash28129 = field.hashCode();
			boolean __temp_executeDef28128 = true;
			switch (__temp_hash28129)
			{
				case 483751295:case 1234652470:case 1235282070:case 65193517:case 2131299334:case 461794063:case 1317758983:case 1317948463:case 2079986083:case -959006008:case -1395603819:case 62838557:case -682516214:case 1391327451:case 662129000:case -1248406155:case 284801593:case -1558875704:case 1781319260:case -2011750742:case -1805459328:case 1169816366:case 1073071227:case -607317616:case -440035976:case 1688513569:case 490879960:case 1170563247:case -454645536:case -454645567:case 1857751761:case 1204954230:case -1081856533:case -670686597:case 1387908030:case 1213974652:case 1601301898:case -395725782:case -1896767747:case -1602602212:
				{
					if (( (( ( __temp_hash28129 == 483751295 ) && field.equals("GetErrorCode") )) || ( (( ( __temp_hash28129 == 1234652470 ) && field.equals("ClearColor") )) || ( (( ( __temp_hash28129 == 1235282070 ) && field.equals("ClearDepth") )) || ( (( ( __temp_hash28129 == 65193517 ) && field.equals("Clear") )) || ( (( ( __temp_hash28129 == 2131299334 ) && field.equals("FrontFace") )) || ( (( ( __temp_hash28129 == 461794063 ) && field.equals("CullFace") )) || ( (( ( __temp_hash28129 == 1317758983 ) && field.equals("DepthFunc") )) || ( (( ( __temp_hash28129 == 1317948463 ) && field.equals("DepthMask") )) || ( (( ( __temp_hash28129 == 2079986083 ) && field.equals("Enable") )) || ( (( ( __temp_hash28129 == -959006008 ) && field.equals("Disable") )) || ( (( ( __temp_hash28129 == -1395603819 ) && field.equals("BlendFunc") )) || ( (( ( __temp_hash28129 == 62838557 ) && field.equals("UseProgram") )) || ( (( ( __temp_hash28129 == -682516214 ) && field.equals("LinkProgram") )) || ( (( ( __temp_hash28129 == 1391327451 ) && field.equals("GetProgramParameter") )) || ( (( ( __temp_hash28129 == 662129000 ) && field.equals("GetProgramInfoLog") )) || ( (( ( __temp_hash28129 == -1248406155 ) && field.equals("GetAttribLocation") )) || ( (( ( __temp_hash28129 == 284801593 ) && field.equals("DeleteProgram") )) || ( (( ( __temp_hash28129 == -1558875704 ) && field.equals("CreateProgram") )) || ( (( ( __temp_hash28129 == 1781319260 ) && field.equals("BindAttribLocation") )) || ( (( ( __temp_hash28129 == -2011750742 ) && field.equals("AttachShader") )) || ( (( ( __temp_hash28129 == -1805459328 ) && field.equals("ShaderSource") )) || ( (( ( __temp_hash28129 == 1169816366 ) && field.equals("GetShaderParameter") )) || ( (( ( __temp_hash28129 == 1073071227 ) && field.equals("GetShaderInfoLog") )) || ( (( ( __temp_hash28129 == -607317616 ) && field.equals("DeleteShader") )) || ( (( ( __temp_hash28129 == -440035976 ) && field.equals("DetachShader") )) || ( (( ( __temp_hash28129 == 1688513569 ) && field.equals("CreateShader") )) || ( (( ( __temp_hash28129 == 490879960 ) && field.equals("CompileShader") )) || ( (( ( __temp_hash28129 == 1170563247 ) && field.equals("VertexAttribPointer") )) || ( (( ( __temp_hash28129 == -454645536 ) && field.equals("VertexAttrib4f") )) || ( (( ( __temp_hash28129 == -454645567 ) && field.equals("VertexAttrib3f") )) || ( (( ( __temp_hash28129 == 1857751761 ) && field.equals("EnableVertexAttrib") )) || ( (( ( __temp_hash28129 == 1204954230 ) && field.equals("DisableVertexAttrib") )) || ( (( ( __temp_hash28129 == -1081856533 ) && field.equals("DeleteBuffer") )) || ( (( ( __temp_hash28129 == -670686597 ) && field.equals("DrawElements") )) || ( (( ( __temp_hash28129 == 1387908030 ) && field.equals("DrawArrays") )) || ( (( ( __temp_hash28129 == 1213974652 ) && field.equals("CreateBuffer") )) || ( (( ( __temp_hash28129 == 1601301898 ) && field.equals("BufferSubData") )) || ( (( ( __temp_hash28129 == -395725782 ) && field.equals("BufferData") )) || ( (( ( __temp_hash28129 == -1896767747 ) && field.equals("BindBuffer") )) || field.equals("CheckExtensions") ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) ) )) 
					{
						__temp_executeDef28128 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef28128 = false;
						return this.Initialize(((haxor.platform.android.Entry) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 1528627980:
				{
					if (field.equals("OnResume")) 
					{
						__temp_executeDef28128 = false;
						this.OnResume();
					}
					
					break;
				}
				
				
				case 324440887:
				{
					if (field.equals("OnPause")) 
					{
						__temp_executeDef28128 = false;
						this.OnPause();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28128) 
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


