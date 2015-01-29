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
	
	
	public static   void __hx_ctor_haxor_core_Entity(haxor.core.Entity __temp_me163, java.lang.String p_name)
	{
		haxor.core.Resource.__hx_ctor_haxor_core_Resource(__temp_me163, ( (( p_name == null )) ? (haxe.lang.Runtime.toString("")) : (p_name) ));
		if (( p_name == null )) 
		{
			p_name = "";
		}
		
		__temp_me163.m_enabled = true;
		__temp_me163.m_components = new haxe.root.Array<haxor.component.Component>(new haxor.component.Component[]{});
		__temp_me163.m_layer = 1;
		__temp_me163.m_transform = ((haxor.component.Transform) (__temp_me163.AddComponent(((java.lang.Class<haxor.component.Component>) (((java.lang.Class) (haxor.component.Transform.class) )) ))) );
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
	
	public  haxor.component.Transform transform;
	
	public final   haxor.component.Transform get_transform()
	{
		return this.m_transform;
	}
	
	
	public  haxor.component.Transform m_transform;
	
	public  haxor.component.animation.Animation animation;
	
	public final   haxor.component.animation.Animation get_animation()
	{
		return this.m_animation;
	}
	
	
	public  haxor.component.animation.Animation m_animation;
	
	
	
	public final   int get_layer()
	{
		return this.m_layer;
	}
	
	
	public   int set_layer(int v)
	{
		if (( v <= 0 )) 
		{
			v = 1;
		}
		
		if (( this.m_layer == v )) 
		{
			return v;
		}
		
		int ll = this.m_layer;
		this.m_layer = v;
		haxor.context.EngineContext.OnEntiyLayerChange(this, ll, this.m_layer);
		return this.m_layer;
	}
	
	
	public  int m_layer;
	
	public  haxe.root.Array<haxor.component.Component> m_components;
	
	public   java.lang.Object AddComponent(java.lang.Class<haxor.component.Component> p_type)
	{
		if (this.m_destroyed) 
		{
			return null;
		}
		
		if (( this.m_transform != null )) 
		{
			if (( ((java.lang.Object) (p_type) ) == ((java.lang.Object) (haxor.component.Transform.class) ) )) 
			{
				return this.m_transform;
			}
			 else 
			{
				if (( this.m_animation != null )) 
				{
					if (( ((java.lang.Object) (p_type) ) == ((java.lang.Object) (haxor.component.animation.Animation.class) ) )) 
					{
						return this.m_animation;
					}
					
				}
				
			}
			
		}
		
		haxor.component.Component c = null;
		c = haxe.root.Type.createInstance(p_type, new haxe.root.Array(new java.lang.Object[]{""}));
		if (( c == null )) 
		{
			return null;
		}
		
		c.m_entity = this;
		if (( ((java.lang.Object) (p_type) ) == ((java.lang.Object) (haxor.component.animation.Animation.class) ) )) 
		{
			this.m_animation = ((haxor.component.animation.Animation) (c) );
		}
		
		if (c.m_is_behaviour) 
		{
			haxor.component.Behaviour b = ((haxor.component.Behaviour) (c) );
			b.set_enabled(( this.m_enabled &&  ! (this.m_destroyed)  ));
		}
		
		c.OnBuild();
		this.m_components.push(c);
		return c;
	}
	
	
	public   java.lang.Object GetComponent(java.lang.Class<haxor.component.Component> p_type)
	{
		{
			int _g1 = 0;
			int _g = this.m_components.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.root.Std.is(this.m_components.__get(i), p_type)) 
				{
					return this.m_components.__get(i);
				}
				
			}
			
		}
		
		return null;
	}
	
	
	public   haxe.root.Array GetComponents(java.lang.Class<haxor.component.Component> p_type)
	{
		haxe.root.Array<haxor.component.Component> res = new haxe.root.Array<haxor.component.Component>(new haxor.component.Component[]{});
		{
			int _g1 = 0;
			int _g = this.m_components.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (haxe.root.Std.is(this.m_components.__get(i), p_type)) 
				{
					res.push(this.m_components.__get(i));
				}
				
			}
			
		}
		
		return ((haxe.root.Array) (res) );
	}
	
	
	public   java.lang.Object GetComponentInChildren(java.lang.Class<haxor.component.Component> p_type)
	{
		haxe.root.Array<java.lang.Class<haxor.component.Component>> p_type1 = new haxe.root.Array<java.lang.Class<haxor.component.Component>>(new java.lang.Class[]{p_type});
		haxe.root.Array<haxor.component.Component> res = new haxe.root.Array<haxor.component.Component>(new haxor.component.Component[]{});
		haxe.root.Array<haxor.component.Component> res1 = new haxe.root.Array<haxor.component.Component>(new haxor.component.Component[]{null});
		this.m_transform.Traverse(new haxor.core.Entity_GetComponentInChildren_154__Fun(((haxe.root.Array<java.lang.Class<haxor.component.Component>>) (p_type1) ), ((haxe.root.Array<haxor.component.Component>) (res1) )));
		return res1.__get(0);
	}
	
	
	public   haxe.root.Array GetComponentsInChildren(java.lang.Class<haxor.component.Component> p_type)
	{
		haxe.root.Array<java.lang.Class<haxor.component.Component>> p_type1 = new haxe.root.Array<java.lang.Class<haxor.component.Component>>(new java.lang.Class[]{p_type});
		haxe.root.Array<haxe.root.Array> res = new haxe.root.Array<haxe.root.Array>(new haxe.root.Array[]{new haxe.root.Array(new java.lang.Object[]{})});
		this.m_transform.Traverse(new haxor.core.Entity_GetComponentsInChildren_172__Fun(((haxe.root.Array<haxe.root.Array>) (res) ), ((haxe.root.Array<java.lang.Class<haxor.component.Component>>) (p_type1) )));
		return res.__get(0);
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
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef939 = true;
			switch (field.hashCode())
			{
				case 776172287:
				{
					if (field.equals("m_layer")) 
					{
						__temp_executeDef939 = false;
						this.m_layer = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 102749521:
				{
					if (field.equals("layer")) 
					{
						__temp_executeDef939 = false;
						this.set_layer(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef939) 
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
			boolean __temp_executeDef940 = true;
			switch (field.hashCode())
			{
				case 1825980968:
				{
					if (field.equals("m_components")) 
					{
						__temp_executeDef940 = false;
						this.m_components = ((haxe.root.Array<haxor.component.Component>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1609594047:
				{
					if (field.equals("enabled")) 
					{
						__temp_executeDef940 = false;
						this.set_enabled(haxe.lang.Runtime.toBool(value));
						return value;
					}
					
					break;
				}
				
				
				case 776172287:
				{
					if (field.equals("m_layer")) 
					{
						__temp_executeDef940 = false;
						this.m_layer = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 1304589679:
				{
					if (field.equals("m_enabled")) 
					{
						__temp_executeDef940 = false;
						this.m_enabled = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 102749521:
				{
					if (field.equals("layer")) 
					{
						__temp_executeDef940 = false;
						this.set_layer(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 1052666732:
				{
					if (field.equals("transform")) 
					{
						__temp_executeDef940 = false;
						this.transform = ((haxor.component.Transform) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1330393650:
				{
					if (field.equals("m_animation")) 
					{
						__temp_executeDef940 = false;
						this.m_animation = ((haxor.component.animation.Animation) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1264550426:
				{
					if (field.equals("m_transform")) 
					{
						__temp_executeDef940 = false;
						this.m_transform = ((haxor.component.Transform) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1118509956:
				{
					if (field.equals("animation")) 
					{
						__temp_executeDef940 = false;
						this.animation = ((haxor.component.animation.Animation) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef940) 
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
			boolean __temp_executeDef941 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef941 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case -1609594047:
				{
					if (field.equals("enabled")) 
					{
						__temp_executeDef941 = false;
						return this.get_enabled();
					}
					
					break;
				}
				
				
				case 1277848144:
				{
					if (field.equals("GetComponentsInChildren")) 
					{
						__temp_executeDef941 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetComponentsInChildren"))) );
					}
					
					break;
				}
				
				
				case -1533080744:
				{
					if (field.equals("get_enabled")) 
					{
						__temp_executeDef941 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_enabled"))) );
					}
					
					break;
				}
				
				
				case -67697653:
				{
					if (field.equals("GetComponentInChildren")) 
					{
						__temp_executeDef941 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetComponentInChildren"))) );
					}
					
					break;
				}
				
				
				case -1621660572:
				{
					if (field.equals("set_enabled")) 
					{
						__temp_executeDef941 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_enabled"))) );
					}
					
					break;
				}
				
				
				case 53766892:
				{
					if (field.equals("GetComponents")) 
					{
						__temp_executeDef941 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetComponents"))) );
					}
					
					break;
				}
				
				
				case 1304589679:
				{
					if (field.equals("m_enabled")) 
					{
						__temp_executeDef941 = false;
						return this.m_enabled;
					}
					
					break;
				}
				
				
				case -1245191577:
				{
					if (field.equals("GetComponent")) 
					{
						__temp_executeDef941 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetComponent"))) );
					}
					
					break;
				}
				
				
				case 1052666732:
				{
					if (field.equals("transform")) 
					{
						__temp_executeDef941 = false;
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
				
				
				case -1373487748:
				{
					if (field.equals("AddComponent")) 
					{
						__temp_executeDef941 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("AddComponent"))) );
					}
					
					break;
				}
				
				
				case 1567506883:
				{
					if (field.equals("get_transform")) 
					{
						__temp_executeDef941 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_transform"))) );
					}
					
					break;
				}
				
				
				case 1825980968:
				{
					if (field.equals("m_components")) 
					{
						__temp_executeDef941 = false;
						return this.m_components;
					}
					
					break;
				}
				
				
				case 1264550426:
				{
					if (field.equals("m_transform")) 
					{
						__temp_executeDef941 = false;
						return this.m_transform;
					}
					
					break;
				}
				
				
				case 776172287:
				{
					if (field.equals("m_layer")) 
					{
						__temp_executeDef941 = false;
						return this.m_layer;
					}
					
					break;
				}
				
				
				case 1118509956:
				{
					if (field.equals("animation")) 
					{
						__temp_executeDef941 = false;
						if (handleProperties) 
						{
							return this.get_animation();
						}
						 else 
						{
							return this.animation;
						}
						
					}
					
					break;
				}
				
				
				case 925082420:
				{
					if (field.equals("set_layer")) 
					{
						__temp_executeDef941 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_layer"))) );
					}
					
					break;
				}
				
				
				case 1633350107:
				{
					if (field.equals("get_animation")) 
					{
						__temp_executeDef941 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_animation"))) );
					}
					
					break;
				}
				
				
				case 1139699496:
				{
					if (field.equals("get_layer")) 
					{
						__temp_executeDef941 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_layer"))) );
					}
					
					break;
				}
				
				
				case 1330393650:
				{
					if (field.equals("m_animation")) 
					{
						__temp_executeDef941 = false;
						return this.m_animation;
					}
					
					break;
				}
				
				
				case 102749521:
				{
					if (field.equals("layer")) 
					{
						__temp_executeDef941 = false;
						return this.get_layer();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef941) 
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
			boolean __temp_executeDef942 = true;
			switch (field.hashCode())
			{
				case 776172287:
				{
					if (field.equals("m_layer")) 
					{
						__temp_executeDef942 = false;
						return ((double) (this.m_layer) );
					}
					
					break;
				}
				
				
				case 102749521:
				{
					if (field.equals("layer")) 
					{
						__temp_executeDef942 = false;
						return ((double) (this.get_layer()) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef942) 
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
			boolean __temp_executeDef943 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef943 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -1533080744:
				{
					if (field.equals("get_enabled")) 
					{
						__temp_executeDef943 = false;
						return this.get_enabled();
					}
					
					break;
				}
				
				
				case 1277848144:
				{
					if (field.equals("GetComponentsInChildren")) 
					{
						__temp_executeDef943 = false;
						return this.GetComponentsInChildren(((java.lang.Class<haxor.component.Component>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1621660572:
				{
					if (field.equals("set_enabled")) 
					{
						__temp_executeDef943 = false;
						return this.set_enabled(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -67697653:
				{
					if (field.equals("GetComponentInChildren")) 
					{
						__temp_executeDef943 = false;
						return this.GetComponentInChildren(((java.lang.Class<haxor.component.Component>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1567506883:
				{
					if (field.equals("get_transform")) 
					{
						__temp_executeDef943 = false;
						return this.get_transform();
					}
					
					break;
				}
				
				
				case 53766892:
				{
					if (field.equals("GetComponents")) 
					{
						__temp_executeDef943 = false;
						return this.GetComponents(((java.lang.Class<haxor.component.Component>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1633350107:
				{
					if (field.equals("get_animation")) 
					{
						__temp_executeDef943 = false;
						return this.get_animation();
					}
					
					break;
				}
				
				
				case -1245191577:
				{
					if (field.equals("GetComponent")) 
					{
						__temp_executeDef943 = false;
						return this.GetComponent(((java.lang.Class<haxor.component.Component>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1139699496:
				{
					if (field.equals("get_layer")) 
					{
						__temp_executeDef943 = false;
						return this.get_layer();
					}
					
					break;
				}
				
				
				case -1373487748:
				{
					if (field.equals("AddComponent")) 
					{
						__temp_executeDef943 = false;
						return this.AddComponent(((java.lang.Class<haxor.component.Component>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 925082420:
				{
					if (field.equals("set_layer")) 
					{
						__temp_executeDef943 = false;
						return this.set_layer(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef943) 
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
		baseArr.push("m_layer");
		baseArr.push("layer");
		baseArr.push("m_animation");
		baseArr.push("animation");
		baseArr.push("m_transform");
		baseArr.push("transform");
		baseArr.push("m_enabled");
		baseArr.push("enabled");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


