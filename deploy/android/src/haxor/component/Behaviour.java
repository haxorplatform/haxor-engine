package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Behaviour extends haxor.component.Component
{
	public    Behaviour(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Behaviour(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.Behaviour.__hx_ctor_haxor_component_Behaviour(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_component_Behaviour(haxor.component.Behaviour __temp_me160373, java.lang.String p_name)
	{
		haxor.component.Component.__hx_ctor_haxor_component_Component(__temp_me160373, p_name);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.Behaviour(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.Behaviour(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	
	
	public   boolean get_enabled()
	{
		return ( this.m_enabled &&  ! (this.m_destroyed)  );
	}
	
	
	public   boolean set_enabled(boolean v)
	{
		if (this.m_destroyed) 
		{
			return false;
		}
		
		if (( this.m_enabled == v )) 
		{
			return v;
		}
		
		this.m_enabled = v;
		if (v) 
		{
			haxor.context.EngineContext.Enable(this);
		}
		 else 
		{
			haxor.context.EngineContext.Disable(this);
		}
		
		return v;
	}
	
	
	public  boolean m_enabled;
	
	public  boolean m_is_awake;
	
	public  boolean m_is_start;
	
	@Override public   void OnBuild()
	{
		super.OnBuild();
		this.m_enabled = true;
		this.m_is_behaviour = true;
		haxor.context.EngineContext.Enable(this);
	}
	
	
	public   void OnAwake()
	{
		{
		}
		
	}
	
	
	public   void OnStart()
	{
		{
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef160769 = true;
			switch (field.hashCode())
			{
				case 270108831:
				{
					if (field.equals("m_is_start")) 
					{
						__temp_executeDef160769 = false;
						this.m_is_start = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1609594047:
				{
					if (field.equals("enabled")) 
					{
						__temp_executeDef160769 = false;
						this.set_enabled(haxe.lang.Runtime.toBool(value));
						return value;
					}
					
					break;
				}
				
				
				case 253574594:
				{
					if (field.equals("m_is_awake")) 
					{
						__temp_executeDef160769 = false;
						this.m_is_awake = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 1304589679:
				{
					if (field.equals("m_enabled")) 
					{
						__temp_executeDef160769 = false;
						this.m_enabled = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160769) 
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
			boolean __temp_executeDef160770 = true;
			switch (field.hashCode())
			{
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef160770 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnStart"))) );
					}
					
					break;
				}
				
				
				case -1609594047:
				{
					if (field.equals("enabled")) 
					{
						__temp_executeDef160770 = false;
						return this.get_enabled();
					}
					
					break;
				}
				
				
				case 311224006:
				{
					if (field.equals("OnAwake")) 
					{
						__temp_executeDef160770 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnAwake"))) );
					}
					
					break;
				}
				
				
				case -1533080744:
				{
					if (field.equals("get_enabled")) 
					{
						__temp_executeDef160770 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_enabled"))) );
					}
					
					break;
				}
				
				
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef160770 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
				case -1621660572:
				{
					if (field.equals("set_enabled")) 
					{
						__temp_executeDef160770 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_enabled"))) );
					}
					
					break;
				}
				
				
				case 270108831:
				{
					if (field.equals("m_is_start")) 
					{
						__temp_executeDef160770 = false;
						return this.m_is_start;
					}
					
					break;
				}
				
				
				case 1304589679:
				{
					if (field.equals("m_enabled")) 
					{
						__temp_executeDef160770 = false;
						return this.m_enabled;
					}
					
					break;
				}
				
				
				case 253574594:
				{
					if (field.equals("m_is_awake")) 
					{
						__temp_executeDef160770 = false;
						return this.m_is_awake;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160770) 
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
			boolean __temp_executeDef160771 = true;
			switch (field.hashCode())
			{
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef160771 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -1533080744:
				{
					if (field.equals("get_enabled")) 
					{
						__temp_executeDef160771 = false;
						return this.get_enabled();
					}
					
					break;
				}
				
				
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef160771 = false;
						this.OnStart();
					}
					
					break;
				}
				
				
				case -1621660572:
				{
					if (field.equals("set_enabled")) 
					{
						__temp_executeDef160771 = false;
						return this.set_enabled(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 311224006:
				{
					if (field.equals("OnAwake")) 
					{
						__temp_executeDef160771 = false;
						this.OnAwake();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160771) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_is_start");
		baseArr.push("m_is_awake");
		baseArr.push("m_enabled");
		baseArr.push("enabled");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


