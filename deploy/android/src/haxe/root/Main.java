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
	
	
	public static   void __hx_ctor__Main(haxe.root.Main __temp_me4434)
	{
		haxor.core.Application.__hx_ctor_haxor_core_Application(__temp_me4434);
		__temp_me4434.init = false;
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
	
	@Override public   boolean Load()
	{
		return true;
	}
	
	
	@Override public   void Initialize()
	{
		haxor.core.Console.Log("Initialize!", null);
		double s = 0.8;
		haxor.io.FloatArray vl = haxor.io.FloatArray.Alloc(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) ( - (s) ) ), ((java.lang.Object) ( - (s) ) ), ((java.lang.Object) (0.5) ), ((java.lang.Object) (s) ), ((java.lang.Object) ( - (s) ) ), ((java.lang.Object) (0.5) ), ((java.lang.Object) (0) ), ((java.lang.Object) (s) ), ((java.lang.Object) (0.5) )}));
		haxor.io.FloatArray cl = haxor.io.FloatArray.Alloc(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (0.0) ), ((java.lang.Object) (1.0) ), ((java.lang.Object) (0.0) )}));
		haxor.io.UInt16Array il = haxor.io.UInt16Array.Alloc(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0, 1, 2}));
		haxor.graphics.mesh.Mesh m = this.mesh = new haxor.graphics.mesh.Mesh();
		m.Set("vertex", vl, 3);
		m.Set("color", cl, 4);
		m.set_topology(il);
		java.lang.String ss = "\r\n\t\t<shader id=\"haxor/debug\">\r\n\t\t\t<vertex>\t\t\t\r\n\t\t\tattribute vec3 vertex;\r\n\t\t\tattribute vec4 color;\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{ \r\n\t\t\t\tv_color = color;\r\n\t\t\t\tgl_Position = vec4(vertex, 1.0);\t\t\t\t\r\n\t\t\t}\t\t\t\r\n\t\t\t</vertex>\t\t\t\r\n\t\t\t<fragment>\t\t\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{ \r\n\t\t\t\tgl_FragColor = v_color;\r\n\t\t\t}\t\t\t\r\n\t\t\t</fragment>\r\n\t\t</shader>\r\n\t\t";
		haxor.graphics.material.Shader shd = new haxor.graphics.material.Shader(haxe.lang.Runtime.toString(ss));
		this.mat = new haxor.graphics.material.Material(haxe.lang.Runtime.toString("DebugMaterial"));
		this.mat.blend = true;
		this.mat.SetBlending(770, 771);
		this.mat.set_shader(shd);
	}
	
	
	public   void OnUpdate()
	{
		{
		}
		
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
			boolean __temp_executeDef4525 = true;
			switch (field.hashCode())
			{
				case 3756:
				{
					if (field.equals("vb")) 
					{
						__temp_executeDef4525 = false;
						this.vb = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef4525) 
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
			boolean __temp_executeDef4526 = true;
			switch (field.hashCode())
			{
				case 3756:
				{
					if (field.equals("vb")) 
					{
						__temp_executeDef4526 = false;
						this.vb = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef4526 = false;
						this.mesh = ((haxor.graphics.mesh.Mesh) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3237136:
				{
					if (field.equals("init")) 
					{
						__temp_executeDef4526 = false;
						this.init = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 107872:
				{
					if (field.equals("mat")) 
					{
						__temp_executeDef4526 = false;
						this.mat = ((haxor.graphics.material.Material) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef4526) 
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
			boolean __temp_executeDef4527 = true;
			switch (field.hashCode())
			{
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef4527 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRender"))) );
					}
					
					break;
				}
				
				
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef4527 = false;
						return this.mesh;
					}
					
					break;
				}
				
				
				case 3756:
				{
					if (field.equals("vb")) 
					{
						__temp_executeDef4527 = false;
						return this.vb;
					}
					
					break;
				}
				
				
				case 107872:
				{
					if (field.equals("mat")) 
					{
						__temp_executeDef4527 = false;
						return this.mat;
					}
					
					break;
				}
				
				
				case 3237136:
				{
					if (field.equals("init")) 
					{
						__temp_executeDef4527 = false;
						return this.init;
					}
					
					break;
				}
				
				
				case 2373894:
				{
					if (field.equals("Load")) 
					{
						__temp_executeDef4527 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Load"))) );
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef4527 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUpdate"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef4527 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef4527) 
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
			boolean __temp_executeDef4528 = true;
			switch (field.hashCode())
			{
				case 3756:
				{
					if (field.equals("vb")) 
					{
						__temp_executeDef4528 = false;
						return ((double) (this.vb) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef4528) 
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
			int __temp_hash4530 = field.hashCode();
			boolean __temp_executeDef4529 = true;
			switch (__temp_hash4530)
			{
				case -1430411344:case 2373894:
				{
					if (( (( ( __temp_hash4530 == -1430411344 ) && field.equals("Initialize") )) || field.equals("Load") )) 
					{
						__temp_executeDef4529 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef4529 = false;
						this.OnUpdate();
					}
					
					break;
				}
				
				
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef4529 = false;
						this.OnRender();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef4529) 
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
		baseArr.push("mat");
		baseArr.push("mesh");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


