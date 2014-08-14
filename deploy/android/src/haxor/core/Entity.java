package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Entity extends haxor.core.Resource
{
	public    Entity(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Entity(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.core.Entity.__hx_ctor_haxor_core_Entity(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_core_Entity(haxor.core.Entity __temp_me4456, java.lang.String p_name)
	{
		haxor.core.Resource.__hx_ctor_haxor_core_Resource(__temp_me4456, p_name);
		__temp_me4456.m_enabled = true;
		__temp_me4456.m_components = new haxe.root.Array<haxor.component.Component>(new haxor.component.Component[]{});
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.core.Entity(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.Entity(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	
	
	public final   boolean get_enabled()
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
		{
			int _g1 = 0;
			int _g = this.m_components.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.component.Component c = this.m_components.__get(i);
				if (c.m_is_behaviour) 
				{
					haxor.component.Behaviour b = ((haxor.component.Behaviour) (c) );
					b.set_enabled(v);
				}
				
			}
			
		}
		
		return v;
	}
	
	
	public  boolean m_enabled;
	
	public  haxe.root.Array<haxor.component.Component> m_components;
	
	public   java.lang.Object AddComponent(java.lang.Class<haxor.component.Component> p_type)
	{
		if (this.m_destroyed) 
		{
			return null;
		}
		
		haxor.component.Component c = haxe.root.Type.createInstance(p_type, new haxe.root.Array(new java.lang.Object[]{}));
		c.m_entity = this;
		if (c.m_is_behaviour) 
		{
			haxor.component.Behaviour b = ((haxor.component.Behaviour) (c) );
			b.set_enabled(( this.m_enabled &&  ! (this.m_destroyed)  ));
		}
		
		this.m_components.push(c);
		return c;
	}
	
	
	@Override public   void OnDestroy()
	{
		{
			int _g1 = 0;
			int _g = this.m_components.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				this.m_components.__get(i).OnDestroy();
			}
			
		}
		
		this.m_components = null;
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef4616 = true;
			switch (field.hashCode())
			{
				case 1825980968:
				{
					if (field.equals("m_components")) 
					{
						__temp_executeDef4616 = false;
						this.m_components = ((haxe.root.Array<haxor.component.Component>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1609594047:
				{
					if (field.equals("enabled")) 
					{
						__temp_executeDef4616 = false;
						this.set_enabled(haxe.lang.Runtime.toBool(value));
						return value;
					}
					
					break;
				}
				
				
				case 1304589679:
				{
					if (field.equals("m_enabled")) 
					{
						__temp_executeDef4616 = false;
						this.m_enabled = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef4616) 
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
			boolean __temp_executeDef4617 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef4617 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case -1609594047:
				{
					if (field.equals("enabled")) 
					{
						__temp_executeDef4617 = false;
						return this.get_enabled();
					}
					
					break;
				}
				
				
				case -1373487748:
				{
					if (field.equals("AddComponent")) 
					{
						__temp_executeDef4617 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("AddComponent"))) );
					}
					
					break;
				}
				
				
				case -1533080744:
				{
					if (field.equals("get_enabled")) 
					{
						__temp_executeDef4617 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_enabled"))) );
					}
					
					break;
				}
				
				
				case 1825980968:
				{
					if (field.equals("m_components")) 
					{
						__temp_executeDef4617 = false;
						return this.m_components;
					}
					
					break;
				}
				
				
				case -1621660572:
				{
					if (field.equals("set_enabled")) 
					{
						__temp_executeDef4617 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_enabled"))) );
					}
					
					break;
				}
				
				
				case 1304589679:
				{
					if (field.equals("m_enabled")) 
					{
						__temp_executeDef4617 = false;
						return this.m_enabled;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef4617) 
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
			boolean __temp_executeDef4618 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef4618 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -1533080744:
				{
					if (field.equals("get_enabled")) 
					{
						__temp_executeDef4618 = false;
						return this.get_enabled();
					}
					
					break;
				}
				
				
				case -1373487748:
				{
					if (field.equals("AddComponent")) 
					{
						__temp_executeDef4618 = false;
						return this.AddComponent(((java.lang.Class<haxor.component.Component>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1621660572:
				{
					if (field.equals("set_enabled")) 
					{
						__temp_executeDef4618 = false;
						return this.set_enabled(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef4618) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_components");
		baseArr.push("m_enabled");
		baseArr.push("enabled");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


