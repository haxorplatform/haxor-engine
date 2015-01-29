package haxor.component;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Renderer extends haxor.component.Behaviour
{
	public    Renderer(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    Renderer(java.lang.String p_name)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.component.Renderer.__hx_ctor_haxor_component_Renderer(this, p_name);
	}
	
	
	public static   void __hx_ctor_haxor_component_Renderer(haxor.component.Renderer __temp_me38, java.lang.String p_name)
	{
		haxor.component.Behaviour.__hx_ctor_haxor_component_Behaviour(__temp_me38, p_name);
		__temp_me38.m_has_mesh = false;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.component.Renderer(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.component.Renderer(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	
	
	public final   haxor.graphics.material.Material get_material()
	{
		return this.m_material;
	}
	
	
	public   haxor.graphics.material.Material set_material(haxor.graphics.material.Material v)
	{
		if (( this.m_material == v )) 
		{
			return v;
		}
		
		this.m_material = v;
		if (( v == null )) 
		{
			this.m_last_queue = -1;
		}
		 else 
		{
			this.m_last_queue = v.queue;
		}
		
		haxor.context.EngineContext.renderer.OnMaterialChange(this);
		return v;
	}
	
	
	public  haxor.graphics.material.Material m_material;
	
	
	
	public final   boolean get_visible()
	{
		return ( this.m_visible &&  ! (this.m_culled)  );
	}
	
	
	public   boolean set_visible(boolean v)
	{
		this.m_visible = v;
		return v;
	}
	
	
	public  boolean m_visible;
	
	public  boolean m_culled;
	
	public  boolean m_has_mesh;
	
	public  int m_last_queue;
	
	@Override public   void OnBuild()
	{
		super.OnBuild();
		this.m_last_queue = -1;
		this.m_visible = true;
		this.m_culled = false;
		haxor.context.EngineContext.renderer.Create(this);
	}
	
	
	public   void OnRender()
	{
		if (( this.m_material != null )) 
		{
			if (( this.m_last_queue != this.m_material.queue )) 
			{
				this.m_last_queue = this.m_material.queue;
				haxor.context.EngineContext.renderer.OnMaterialChange(this);
			}
			
		}
		
	}
	
	
	public   void UpdateCulling()
	{
		boolean v0 = this.m_culled;
		boolean v1 = this.CheckCulling();
		this.m_culled = v1;
		if (( v0 != v1 )) 
		{
			haxor.context.EngineContext.renderer.OnVisibilityChange(this,  ! (v1) );
		}
		
	}
	
	
	public   boolean CheckCulling()
	{
		return false;
	}
	
	
	@Override public   void OnDestroy()
	{
		haxor.context.EngineContext.renderer.Destroy(this);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef634 = true;
			switch (field.hashCode())
			{
				case 259065146:
				{
					if (field.equals("m_last_queue")) 
					{
						__temp_executeDef634 = false;
						this.m_last_queue = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef634) 
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
			boolean __temp_executeDef635 = true;
			switch (field.hashCode())
			{
				case 259065146:
				{
					if (field.equals("m_last_queue")) 
					{
						__temp_executeDef635 = false;
						this.m_last_queue = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 299066663:
				{
					if (field.equals("material")) 
					{
						__temp_executeDef635 = false;
						this.set_material(((haxor.graphics.material.Material) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 286009348:
				{
					if (field.equals("m_has_mesh")) 
					{
						__temp_executeDef635 = false;
						this.m_has_mesh = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 444448953:
				{
					if (field.equals("m_material")) 
					{
						__temp_executeDef635 = false;
						this.m_material = ((haxor.graphics.material.Material) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1948035677:
				{
					if (field.equals("m_culled")) 
					{
						__temp_executeDef635 = false;
						this.m_culled = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -914040160:
				{
					if (field.equals("m_visible")) 
					{
						__temp_executeDef635 = false;
						this.m_visible = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef635) 
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
			boolean __temp_executeDef636 = true;
			switch (field.hashCode())
			{
				case 602652923:
				{
					if (field.equals("OnDestroy")) 
					{
						__temp_executeDef636 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnDestroy"))) );
					}
					
					break;
				}
				
				
				case 299066663:
				{
					if (field.equals("material")) 
					{
						__temp_executeDef636 = false;
						return this.get_material();
					}
					
					break;
				}
				
				
				case 1224889128:
				{
					if (field.equals("CheckCulling")) 
					{
						__temp_executeDef636 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("CheckCulling"))) );
					}
					
					break;
				}
				
				
				case -1623988240:
				{
					if (field.equals("get_material")) 
					{
						__temp_executeDef636 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_material"))) );
					}
					
					break;
				}
				
				
				case 424235015:
				{
					if (field.equals("UpdateCulling")) 
					{
						__temp_executeDef636 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateCulling"))) );
					}
					
					break;
				}
				
				
				case -74995612:
				{
					if (field.equals("set_material")) 
					{
						__temp_executeDef636 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_material"))) );
					}
					
					break;
				}
				
				
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef636 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnRender"))) );
					}
					
					break;
				}
				
				
				case 444448953:
				{
					if (field.equals("m_material")) 
					{
						__temp_executeDef636 = false;
						return this.m_material;
					}
					
					break;
				}
				
				
				case 312095663:
				{
					if (field.equals("OnBuild")) 
					{
						__temp_executeDef636 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBuild"))) );
					}
					
					break;
				}
				
				
				case 466743410:
				{
					if (field.equals("visible")) 
					{
						__temp_executeDef636 = false;
						return this.get_visible();
					}
					
					break;
				}
				
				
				case 259065146:
				{
					if (field.equals("m_last_queue")) 
					{
						__temp_executeDef636 = false;
						return this.m_last_queue;
					}
					
					break;
				}
				
				
				case 543256713:
				{
					if (field.equals("get_visible")) 
					{
						__temp_executeDef636 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_visible"))) );
					}
					
					break;
				}
				
				
				case 286009348:
				{
					if (field.equals("m_has_mesh")) 
					{
						__temp_executeDef636 = false;
						return this.m_has_mesh;
					}
					
					break;
				}
				
				
				case 454676885:
				{
					if (field.equals("set_visible")) 
					{
						__temp_executeDef636 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_visible"))) );
					}
					
					break;
				}
				
				
				case -1948035677:
				{
					if (field.equals("m_culled")) 
					{
						__temp_executeDef636 = false;
						return this.m_culled;
					}
					
					break;
				}
				
				
				case -914040160:
				{
					if (field.equals("m_visible")) 
					{
						__temp_executeDef636 = false;
						return this.m_visible;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef636) 
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
			boolean __temp_executeDef637 = true;
			switch (field.hashCode())
			{
				case 259065146:
				{
					if (field.equals("m_last_queue")) 
					{
						__temp_executeDef637 = false;
						return ((double) (this.m_last_queue) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef637) 
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
			int __temp_hash639 = field.hashCode();
			boolean __temp_executeDef638 = true;
			switch (__temp_hash639)
			{
				case 602652923:case 312095663:
				{
					if (( (( ( __temp_hash639 == 602652923 ) && field.equals("OnDestroy") )) || field.equals("OnBuild") )) 
					{
						__temp_executeDef638 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -1623988240:
				{
					if (field.equals("get_material")) 
					{
						__temp_executeDef638 = false;
						return this.get_material();
					}
					
					break;
				}
				
				
				case 1224889128:
				{
					if (field.equals("CheckCulling")) 
					{
						__temp_executeDef638 = false;
						return this.CheckCulling();
					}
					
					break;
				}
				
				
				case -74995612:
				{
					if (field.equals("set_material")) 
					{
						__temp_executeDef638 = false;
						return this.set_material(((haxor.graphics.material.Material) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 424235015:
				{
					if (field.equals("UpdateCulling")) 
					{
						__temp_executeDef638 = false;
						this.UpdateCulling();
					}
					
					break;
				}
				
				
				case 543256713:
				{
					if (field.equals("get_visible")) 
					{
						__temp_executeDef638 = false;
						return this.get_visible();
					}
					
					break;
				}
				
				
				case 1528462453:
				{
					if (field.equals("OnRender")) 
					{
						__temp_executeDef638 = false;
						this.OnRender();
					}
					
					break;
				}
				
				
				case 454676885:
				{
					if (field.equals("set_visible")) 
					{
						__temp_executeDef638 = false;
						return this.set_visible(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef638) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_last_queue");
		baseArr.push("m_has_mesh");
		baseArr.push("m_culled");
		baseArr.push("m_visible");
		baseArr.push("visible");
		baseArr.push("m_material");
		baseArr.push("material");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


