package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Main extends haxor.core.Application implements haxor.core.IRenderable, haxor.core.IUpdateable
{
	public static void main(String[] args)
	{
		main();
	}
	public    Main(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    Main()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxe.root.Main.__hx_ctor__Main(this);
	}
	
	
	public static   void __hx_ctor__Main(haxe.root.Main __temp_me27869)
	{
		haxor.core.Application.__hx_ctor_haxor_core_Application(__temp_me27869);
		__temp_me27869.init = false;
	}
	
	
	public static   void main()
	{
		haxor.platform.android.Entry.Initialize();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.Main(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.Main();
	}
	
	
	public  haxor.graphics.mesh.Mesh mesh;
	
	public  haxor.graphics.material.Material mat;
	
	public  java.lang.String ss;
	
	@Override public   boolean Load()
	{
		haxor.platform.android.Web.root = "https://dl.dropboxusercontent.com/u/20655747/haxor/resources/";
		return true;
	}
	
	
	@Override public   void Initialize()
	{
		haxor.core.Console.Log("Initialize!", null);
		this.get_application().set_fps(50);
		double s = 0.8;
		haxor.io.FloatArray vl = haxor.io.FloatArray.Alloc(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) ( - (s) ) ), ((java.lang.Object) ( - (s) ) ), ((java.lang.Object) (0.5) ), ((java.lang.Object) (s) ), ((java.lang.Object) ( - (s) ) ), ((java.lang.Object) (0.5) ), ((java.lang.Object) (s) ), ((java.lang.Object) (s) ), ((java.lang.Object) (0.5) ), ((java.lang.Object) ( - (s) ) ), ((java.lang.Object) (s) ), ((java.lang.Object) (0.5) )}));
		haxor.io.FloatArray cl = haxor.io.FloatArray.Alloc(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) )}));
		haxor.io.UInt16Array il = haxor.io.UInt16Array.Alloc(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0, 1, 2, 0, 2, 3}));
		haxor.graphics.mesh.Mesh m = this.mesh = new haxor.graphics.mesh.Mesh();
		m.Set("vertex", vl, 3);
		m.Set("color", cl, 4);
		m.set_topology(il);
		if (( this.ss == null )) 
		{
			this.ss = "\r\n\t\t\t<shader id=\"haxor/debug\">\r\n\t\t\t\t<vertex>\t\t\t\r\n\t\t\t\tattribute vec3 vertex;\r\n\t\t\t\tattribute vec4 color;\t\t\t\r\n\t\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tv_color = color;\r\n\t\t\t\t\tgl_Position = vec4(vertex, 1.0);\t\t\t\t\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</vertex>\t\t\t\r\n\t\t\t\t<fragment>\t\t\t\t\t\r\n\t\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tgl_FragColor = v_color;\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</fragment>\r\n\t\t\t</shader>\r\n\t\t\t";
		}
		
		haxor.graphics.material.Shader shd = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(this.ss));
		this.mat = new haxor.graphics.material.Material(haxe.lang.Runtime.toString("DebugMaterial"));
		this.mat.blend = true;
		this.mat.SetBlending(770, 771);
		this.mat.set_shader(shd);
		haxor.core.Console.Log("Start", null);
		double t0 = haxor.core.Time.m_clock;
		int len = 10000000;
		int max = 4;
		int total = max;
	}
	
	
	public   void OnActivityComplete()
	{
		haxor.thread.Activity.Run(( (( haxe.root.Main_OnActivityComplete_178__Fun.__hx_current != null )) ? (haxe.root.Main_OnActivityComplete_178__Fun.__hx_current) : (haxe.root.Main_OnActivityComplete_178__Fun.__hx_current = ((haxe.root.Main_OnActivityComplete_178__Fun) (new haxe.root.Main_OnActivityComplete_178__Fun()) )) ), true);
	}
	
	
	public   void OnUpdate()
	{
		int __temp_stmt27974 = 0;
		{
			haxor.core.Application _this = this.get_application();
			__temp_stmt27974 = _this.m_fps;
		}
		
		haxor.core.Console.Log(( ( ( ( ( ( ( ( ( ( "ups[" + haxor.core.Time.m_ups ) + "] fps[" ) + haxor.core.Time.m_fps ) + "] elapsed[" ) + haxe.lang.Runtime.toString(haxor.core.Time.m_elapsed) ) + "] frames[" ) + haxor.core.Time.m_frame ) + "] a[" ) + __temp_stmt27974 ) + "]" ), null);
	}
	
	
	public  boolean init;
	
	public  int vb;
	
	public   void OnRender()
	{
		haxor.platform.graphics.GL.m_gl.ClearColor(1.0, 0.0, 1.0, 1.0);
		haxor.platform.graphics.GL.m_gl.ClearDepth(1.0);
		haxor.platform.graphics.GL.m_gl.Clear(16640);
		if (( this.mesh == null )) 
		{
			return ;
		}
		
		if (( this.mat == null )) 
		{
			return ;
		}
		
		haxor.graphics.Graphics.RenderMesh(this.mesh, this.mat);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef27975 = true;
			switch (field.hashCode())
			{
				case 3756:
				{
					if (field.equals("vb")) 
					{
						__temp_executeDef27975 = false;
						this.vb = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef27975) 
			{
				return super.__hx_setField_f(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef27976 = true;
			switch (field.hashCode())
			{
				case 3756:
				{
					if (field.equals("vb")) 
					{
						__temp_executeDef27976 = false;
						this.vb = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef27976 = false;
						this.mesh = ((haxor.graphics.mesh.Mesh) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3237136:
				{
					if (field.equals("init")) 
					{
						__temp_executeDef27976 = false;
						this.init = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 107872:
				{
					if (field.equals("mat")) 
					{
						__temp_executeDef27976 = false;
						this.mat = ((haxor.graphics.material.Material) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3680:
				{
					if (field.equals("ss")) 
					{
						__temp_executeDef27976 = false;
						this.ss = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef27976) 
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
			boolean __temp_executeDef27977 = true;
			switch (field.hashCode())
			{
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef27977 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRender"))) );
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef27977 = false;
						return this.mesh;
					}
					
					break;
				}
				
				
				case 3756:
				{
					if (field.equals("vb")) 
					{
						__temp_executeDef27977 = false;
						return this.vb;
					}
					
					break;
				}
				
				
				case 107872:
				{
					if (field.equals("mat")) 
					{
						__temp_executeDef27977 = false;
						return this.mat;
					}
					
					break;
				}
				
				
				case 3237136:
				{
					if (field.equals("init")) 
					{
						__temp_executeDef27977 = false;
						return this.init;
					}
					
					break;
				}
				
				
				case 3680:
				{
					if (field.equals("ss")) 
					{
						__temp_executeDef27977 = false;
						return this.ss;
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef27977 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUpdate"))) );
					}
					
					break;
				}
				
				
				case 2373894:
				{
					if (field.equals("Load")) 
					{
						__temp_executeDef27977 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Load"))) );
					}
					
					break;
				}
				
				
				case -946767481:
				{
					if (field.equals("OnActivityComplete")) 
					{
						__temp_executeDef27977 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnActivityComplete"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef27977 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef27977) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			boolean __temp_executeDef27978 = true;
			switch (field.hashCode())
			{
				case 3756:
				{
					if (field.equals("vb")) 
					{
						__temp_executeDef27978 = false;
						return ((double) (this.vb) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef27978) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
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
			int __temp_hash27980 = field.hashCode();
			boolean __temp_executeDef27979 = true;
			switch (__temp_hash27980)
			{
				case -1430411344:case 2373894:
				{
					if (( (( ( __temp_hash27980 == -1430411344 ) && field.equals("Initialize") )) || field.equals("Load") )) 
					{
						__temp_executeDef27979 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -946767481:
				{
					if (field.equals("OnActivityComplete")) 
					{
						__temp_executeDef27979 = false;
						this.OnActivityComplete();
					}
					
					break;
				}
				
				
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef27979 = false;
						this.OnRender();
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef27979 = false;
						this.OnUpdate();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef27979) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("vb");
		baseArr.push("init");
		baseArr.push("ss");
		baseArr.push("mat");
		baseArr.push("mesh");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


