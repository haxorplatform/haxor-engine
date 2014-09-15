package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Component extends haxor.core.Resource
{
	public    Component(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Component(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.Component.__hx_ctor_haxor_component_Component(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_component_Component(haxor.component.Component __temp_me255317, java.lang.String p_name)
	{
		haxor.core.Resource.__hx_ctor_haxor_core_Resource(__temp_me255317, p_name);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.Component(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.Component(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	@Override public   java.lang.String get_name()
	{
		return this.m_entity.get_name();
	}
	
	
	@Override public   java.lang.String set_name(java.lang.String v)
	{
		this.m_entity.set_name(v);
		return v;
	}
	
	
	public  haxor.core.Entity entity;
	
	public final   haxor.core.Entity get_entity()
	{
		return this.m_entity;
	}
	
	
	public  haxor.core.Entity m_entity;
	
	public  haxor.component.Transform transform;
	
	public final   haxor.component.Transform get_transform()
	{
		return this.m_entity.m_transform;
	}
	
	
	public final   java.lang.Object AddComponent(java.lang.Class<haxor.component.Component> p_type)
	{
		return this.m_entity.AddComponent(p_type);
	}
	
	
	public final   java.lang.Object GetComponent(java.lang.Class<haxor.component.Component> p_type)
	{
		return this.m_entity.GetComponent(p_type);
	}
	
	
	public final   haxe.root.Array GetComponents(java.lang.Class<haxor.component.Component> p_type)
	{
		return this.m_entity.GetComponents(p_type);
	}
	
	
	public final   java.lang.Object GetComponentInChildren(java.lang.Class<haxor.component.Component> p_type)
	{
		return this.m_entity.GetComponentInChildren(p_type);
	}
	
	
	public final   haxe.root.Array GetComponentsInChildren(java.lang.Class<haxor.component.Component> p_type)
	{
		return this.m_entity.GetComponentsInChildren(p_type);
	}
	
	
	public   void OnBuild()
	{
		{
		}
		
	}
	
	
	public   void OnTransformUpdate()
	{
		{
		}
		
	}
	
	
	public   void OnVisibilityChange(boolean p_visible)
	{
		{
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef255690 = true;
			switch (field.hashCode())
			{
				case 1052666732:
				{
					if (field.equals("transform")) 
					{
						__temp_executeDef255690 = false;
						this.transform = ((haxor.component.Transform) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1298275357:
				{
					if (field.equals("entity")) 
					{
						__temp_executeDef255690 = false;
						this.entity = ((haxor.core.Entity) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1897006091:
				{
					if (field.equals("m_entity")) 
					{
						__temp_executeDef255690 = false;
						this.m_entity = ((haxor.core.Entity) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255690) 
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
			boolean __temp_executeDef255691 = true;
			switch (field.hashCode())
			{
				case -1403863679:
				{
					if (field.equals("OnVisibilityChange")) 
					{
						__temp_executeDef255691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnVisibilityChange"))) );
					}
					
					break;
				}
				
				
				case 1976486356:
				{
					if (field.equals("get_name")) 
					{
						__temp_executeDef255691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_name"))) );
					}
					
					break;
				}
				
				
				case 1899224918:
				{
					if (field.equals("OnTransformUpdate")) 
					{
						__temp_executeDef255691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnTransformUpdate"))) );
					}
					
					break;
				}
				
				
				case 1415373896:
				{
					if (field.equals("set_name")) 
					{
						__temp_executeDef255691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_name"))) );
					}
					
					break;
				}
				
				
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef255691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
				case -1298275357:
				{
					if (field.equals("entity")) 
					{
						__temp_executeDef255691 = false;
						if (handleProperties) 
						{
							return this.get_entity();
						}
						 else 
						{
							return this.entity;
						}
						
					}
					
					break;
				}
				
				
				case 1277848144:
				{
					if (field.equals("GetComponentsInChildren")) 
					{
						__temp_executeDef255691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetComponentsInChildren"))) );
					}
					
					break;
				}
				
				
				case 782402796:
				{
					if (field.equals("get_entity")) 
					{
						__temp_executeDef255691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_entity"))) );
					}
					
					break;
				}
				
				
				case -67697653:
				{
					if (field.equals("GetComponentInChildren")) 
					{
						__temp_executeDef255691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetComponentInChildren"))) );
					}
					
					break;
				}
				
				
				case -1897006091:
				{
					if (field.equals("m_entity")) 
					{
						__temp_executeDef255691 = false;
						return this.m_entity;
					}
					
					break;
				}
				
				
				case 53766892:
				{
					if (field.equals("GetComponents")) 
					{
						__temp_executeDef255691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetComponents"))) );
					}
					
					break;
				}
				
				
				case 1052666732:
				{
					if (field.equals("transform")) 
					{
						__temp_executeDef255691 = false;
						if (handleProperties) 
						{
							return this.get_transform();
						}
						 else 
						{
							return this.transform;
						}
						
					}
					
					break;
				}
				
				
				case -1245191577:
				{
					if (field.equals("GetComponent")) 
					{
						__temp_executeDef255691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetComponent"))) );
					}
					
					break;
				}
				
				
				case 1567506883:
				{
					if (field.equals("get_transform")) 
					{
						__temp_executeDef255691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_transform"))) );
					}
					
					break;
				}
				
				
				case -1373487748:
				{
					if (field.equals("AddComponent")) 
					{
						__temp_executeDef255691 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("AddComponent"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255691) 
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
			int __temp_hash255693 = field.hashCode();
			boolean __temp_executeDef255692 = true;
			switch (__temp_hash255693)
			{
				case 1415373896:case 1976486356:
				{
					if (( (( ( __temp_hash255693 == 1415373896 ) && field.equals("set_name") )) || field.equals("get_name") )) 
					{
						__temp_executeDef255692 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 782402796:
				{
					if (field.equals("get_entity")) 
					{
						__temp_executeDef255692 = false;
						return this.get_entity();
					}
					
					break;
				}
				
				
				case -1403863679:
				{
					if (field.equals("OnVisibilityChange")) 
					{
						__temp_executeDef255692 = false;
						this.OnVisibilityChange(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1567506883:
				{
					if (field.equals("get_transform")) 
					{
						__temp_executeDef255692 = false;
						return this.get_transform();
					}
					
					break;
				}
				
				
				case 1899224918:
				{
					if (field.equals("OnTransformUpdate")) 
					{
						__temp_executeDef255692 = false;
						this.OnTransformUpdate();
					}
					
					break;
				}
				
				
				case -1373487748:
				{
					if (field.equals("AddComponent")) 
					{
						__temp_executeDef255692 = false;
						return this.AddComponent(((java.lang.Class<haxor.component.Component>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef255692 = false;
						this.OnBuild();
					}
					
					break;
				}
				
				
				case -1245191577:
				{
					if (field.equals("GetComponent")) 
					{
						__temp_executeDef255692 = false;
						return this.GetComponent(((java.lang.Class<haxor.component.Component>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1277848144:
				{
					if (field.equals("GetComponentsInChildren")) 
					{
						__temp_executeDef255692 = false;
						return this.GetComponentsInChildren(((java.lang.Class<haxor.component.Component>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 53766892:
				{
					if (field.equals("GetComponents")) 
					{
						__temp_executeDef255692 = false;
						return this.GetComponents(((java.lang.Class<haxor.component.Component>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -67697653:
				{
					if (field.equals("GetComponentInChildren")) 
					{
						__temp_executeDef255692 = false;
						return this.GetComponentInChildren(((java.lang.Class<haxor.component.Component>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef255692) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("transform");
		baseArr.push("m_entity");
		baseArr.push("entity");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


