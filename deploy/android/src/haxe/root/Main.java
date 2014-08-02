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
	
	
	public static   void __hx_ctor__Main(haxe.root.Main __temp_me1813)
	{
		haxor.core.Application.__hx_ctor_haxor_core_Application(__temp_me1813);
	}
	
	
	public static   void main()
	{
		{
		}
		
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
	}
	
	
	public   void OnUpdate()
	{
		{
		}
		
	}
	
	
	public   void OnRender()
	{
		haxor.core.Console.Log(( ( ( ( "ups[" + haxor.core.Time.m_ups ) + "] fps[" ) + haxor.core.Time.m_fps ) + "]" ), null);
		this.m_graphics.Clear(1.0, 0.0, 1.0, null, null);
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef1879 = true;
			switch (field.hashCode())
			{
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef1879 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRender"))) );
					}
					
					break;
				}
				
				
				case 2373894:
				{
					if (field.equals("Load")) 
					{
						__temp_executeDef1879 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Load"))) );
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef1879 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnUpdate"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef1879 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1879) 
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
			int __temp_hash1881 = field.hashCode();
			boolean __temp_executeDef1880 = true;
			switch (__temp_hash1881)
			{
				case -1430411344:case 2373894:
				{
					if (( (( ( __temp_hash1881 == -1430411344 ) && field.equals("Initialize") )) || field.equals("Load") )) 
					{
						__temp_executeDef1880 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1624208296:
				{
					if (field.equals("OnUpdate")) 
					{
						__temp_executeDef1880 = false;
						this.OnUpdate();
					}
					
					break;
				}
				
				
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef1880 = false;
						this.OnRender();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1880) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
}


