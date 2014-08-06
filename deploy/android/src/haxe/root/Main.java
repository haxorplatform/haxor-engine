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
	
	
	public static   void __hx_ctor__Main(haxe.root.Main __temp_me26079)
	{
		haxor.core.Application.__hx_ctor_haxor_core_Application(__temp_me26079);
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
	
	
	@Override public   boolean Load()
	{
		return true;
	}
	
	
	@Override public   void Initialize()
	{
		haxor.core.Console.Log("Initialize!", null);
		haxor.core.Console.Log("mesh create", null);
		haxor.graphics.mesh.Mesh m = new haxor.graphics.mesh.Mesh();
		haxor.io.FloatArray f32 = haxor.io.FloatArray.Create(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (0.0) ), ((java.lang.Object) (1.1) ), ((java.lang.Object) (2.2) ), ((java.lang.Object) (3.3) )}));
		haxor.io.UInt16Array i16 = haxor.io.UInt16Array.Create(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{2, 3, 4, 5}));
		f32.b.put(((int) (0) ), ((float) (1.1) ));
		haxor.core.Console.Log(( haxe.lang.Runtime.toString(((double) (f32.b.get(((int) (0) ))) )) + "!!!" ), null);
		m.Set("factor", f32, 1);
		m.Set("idx", i16, 1);
		m.set_topology(haxor.io.UInt16Array.Create(new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{0, 1, 2, 2, 1, 3})));
		{
			int _g1 = 0;
			int _g = m.get_attribs().length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.graphics.mesh.MeshAttrib a = m.GetAttribute(m.get_attribs().__get(i));
				haxe.Log.trace.__hx_invoke2_o(0.0, ( ( ( ( ( ( a.name + " " ) + a.type ) + " " ) + a.offset ) + " " ) + a.data.get_length() ), 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"Main", "Main.hx", "Initialize"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (64) )) )})));
			}
			
		}
		
	}
	
	
	public   void OnUpdate()
	{
		{
		}
		
	}
	
	
	public   void OnRender()
	{
		haxor.platform.graphics.GL.m_gl.Clear(1.0, 0.0, 1.0, 1.0, 1.0);
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef26149 = true;
			switch (field.hashCode())
			{
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef26149 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRender"))) );
					}
					
					break;
				}
				
				
				case 2373894:
				{
					if (field.equals("Load")) 
					{
						__temp_executeDef26149 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Load"))) );
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef26149 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUpdate"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef26149 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26149) 
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
			int __temp_hash26151 = field.hashCode();
			boolean __temp_executeDef26150 = true;
			switch (__temp_hash26151)
			{
				case -1430411344:case 2373894:
				{
					if (( (( ( __temp_hash26151 == -1430411344 ) && field.equals("Initialize") )) || field.equals("Load") )) 
					{
						__temp_executeDef26150 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef26150 = false;
						this.OnUpdate();
					}
					
					break;
				}
				
				
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef26150 = false;
						this.OnRender();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26150) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
}


