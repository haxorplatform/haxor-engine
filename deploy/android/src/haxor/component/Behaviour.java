package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Behaviour extends haxor.component.Component
{
	public    Behaviour(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    Behaviour()
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.component.Behaviour.__hx_ctor_haxor_component_Behaviour(this);
	}
	
	
	public static   void __hx_ctor_haxor_component_Behaviour(haxor.component.Behaviour __temp_me42334)
	{
		haxor.component.Component.__hx_ctor_haxor_component_Component(__temp_me42334);
		__temp_me42334.m_enabled = true;
		__temp_me42334.m_is_behaviour = true;
		__temp_me42334.m_is_updateable = ( __temp_me42334 instanceof haxor.core.IUpdateable );
		__temp_me42334.m_is_renderable = ( __temp_me42334 instanceof haxor.core.IRenderable );
		__temp_me42334.m_is_resizeable = ( __temp_me42334 instanceof haxor.core.IResizeable );
		__temp_me42334.UpdateContextFlag(true);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.Behaviour(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.Behaviour();
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
		
		this.m_enabled = v;
		this.UpdateContextFlag(v);
		return v;
	}
	
	
	public  boolean m_enabled;
	
	public  boolean m_is_updateable;
	
	public  boolean m_is_renderable;
	
	public  boolean m_is_resizeable;
	
	public  boolean m_is_awake;
	
	public  boolean m_is_start;
	
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
	
	
	public   void UpdateContextFlag(boolean p_flag)
	{
		if (this.m_is_updateable) 
		{
			if (p_flag) 
			{
				haxor.context.EngineContext.update.Add(this);
			}
			 else 
			{
				haxor.context.EngineContext.update.Remove(this);
			}
			
		}
		
		if (this.m_is_renderable) 
		{
			if (p_flag) 
			{
				haxor.context.EngineContext.render.Add(this);
			}
			 else 
			{
				haxor.context.EngineContext.render.Remove(this);
			}
			
		}
		
		if (this.m_is_resizeable) 
		{
			if (p_flag) 
			{
				haxor.context.EngineContext.resize.Add(this);
			}
			 else 
			{
				haxor.context.EngineContext.resize.Remove(this);
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef42461 = true;
			switch (field.hashCode())
			{
				case 270108831:
				{
					if (field.equals("m_is_start")) 
					{
						__temp_executeDef42461 = false;
						this.m_is_start = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1609594047:
				{
					if (field.equals("enabled")) 
					{
						__temp_executeDef42461 = false;
						this.set_enabled(haxe.lang.Runtime.toBool(value));
						return value;
					}
					
					break;
				}
				
				
				case 253574594:
				{
					if (field.equals("m_is_awake")) 
					{
						__temp_executeDef42461 = false;
						this.m_is_awake = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 1304589679:
				{
					if (field.equals("m_enabled")) 
					{
						__temp_executeDef42461 = false;
						this.m_enabled = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 391713265:
				{
					if (field.equals("m_is_resizeable")) 
					{
						__temp_executeDef42461 = false;
						this.m_is_resizeable = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1954178170:
				{
					if (field.equals("m_is_updateable")) 
					{
						__temp_executeDef42461 = false;
						this.m_is_updateable = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -464161325:
				{
					if (field.equals("m_is_renderable")) 
					{
						__temp_executeDef42461 = false;
						this.m_is_renderable = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef42461) 
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
			boolean __temp_executeDef42462 = true;
			switch (field.hashCode())
			{
				case -1599225582:
				{
					if (field.equals("UpdateContextFlag")) 
					{
						__temp_executeDef42462 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateContextFlag"))) );
					}
					
					break;
				}
				
				
				case -1609594047:
				{
					if (field.equals("enabled")) 
					{
						__temp_executeDef42462 = false;
						return this.get_enabled();
					}
					
					break;
				}
				
				
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef42462 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnStart"))) );
					}
					
					break;
				}
				
				
				case -1533080744:
				{
					if (field.equals("get_enabled")) 
					{
						__temp_executeDef42462 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_enabled"))) );
					}
					
					break;
				}
				
				
				case 311224006:
				{
					if (field.equals("OnAwake")) 
					{
						__temp_executeDef42462 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnAwake"))) );
					}
					
					break;
				}
				
				
				case -1621660572:
				{
					if (field.equals("set_enabled")) 
					{
						__temp_executeDef42462 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_enabled"))) );
					}
					
					break;
				}
				
				
				case 270108831:
				{
					if (field.equals("m_is_start")) 
					{
						__temp_executeDef42462 = false;
						return this.m_is_start;
					}
					
					break;
				}
				
				
				case 1304589679:
				{
					if (field.equals("m_enabled")) 
					{
						__temp_executeDef42462 = false;
						return this.m_enabled;
					}
					
					break;
				}
				
				
				case 253574594:
				{
					if (field.equals("m_is_awake")) 
					{
						__temp_executeDef42462 = false;
						return this.m_is_awake;
					}
					
					break;
				}
				
				
				case -1954178170:
				{
					if (field.equals("m_is_updateable")) 
					{
						__temp_executeDef42462 = false;
						return this.m_is_updateable;
					}
					
					break;
				}
				
				
				case 391713265:
				{
					if (field.equals("m_is_resizeable")) 
					{
						__temp_executeDef42462 = false;
						return this.m_is_resizeable;
					}
					
					break;
				}
				
				
				case -464161325:
				{
					if (field.equals("m_is_renderable")) 
					{
						__temp_executeDef42462 = false;
						return this.m_is_renderable;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef42462) 
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
			boolean __temp_executeDef42463 = true;
			switch (field.hashCode())
			{
				case -1599225582:
				{
					if (field.equals("UpdateContextFlag")) 
					{
						__temp_executeDef42463 = false;
						this.UpdateContextFlag(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1533080744:
				{
					if (field.equals("get_enabled")) 
					{
						__temp_executeDef42463 = false;
						return this.get_enabled();
					}
					
					break;
				}
				
				
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef42463 = false;
						this.OnStart();
					}
					
					break;
				}
				
				
				case -1621660572:
				{
					if (field.equals("set_enabled")) 
					{
						__temp_executeDef42463 = false;
						return this.set_enabled(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 311224006:
				{
					if (field.equals("OnAwake")) 
					{
						__temp_executeDef42463 = false;
						this.OnAwake();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef42463) 
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
		baseArr.push("m_is_resizeable");
		baseArr.push("m_is_renderable");
		baseArr.push("m_is_updateable");
		baseArr.push("m_enabled");
		baseArr.push("enabled");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


