package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Engine extends haxe.lang.HxObject
{
	public    Engine(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Engine(haxor.core.BaseApplication p_application)
	{
		haxor.core.Engine.__hx_ctor_haxor_core_Engine(this, p_application);
	}
	
	
	public static   void __hx_ctor_haxor_core_Engine(haxor.core.Engine __temp_me1827, haxor.core.BaseApplication p_application)
	{
		__temp_me1827.m_application = p_application;
		__temp_me1827.state = haxor.core.EngineState.Play;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.core.Engine(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.Engine(((haxor.core.BaseApplication) (arr.__get(0)) ));
	}
	
	
	public  haxor.core.EngineState state;
	
	public  haxor.core.BaseApplication m_application;
	
	public   void Collect()
	{
		haxor.context.Process<haxor.core.IDisposable> dispose_p = haxor.context.HaxorContext.disposables;
		{
			int _g1 = 0;
			int _g = haxor.context.HaxorContext.collectRate;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (( dispose_p.get_length() <= 0 )) 
				{
					break;
				}
				
				haxor.core.IDisposable o = dispose_p.list.__get(0);
				o.OnDestroy();
				dispose_p.Remove(((haxor.core.Resource) (o) ));
			}
			
		}
		
	}
	
	
	public   void Update()
	{
		if (( this.state == haxor.core.EngineState.Editor )) 
		{
			return ;
		}
		
		haxor.context.Process<haxor.core.IUpdateable> update_p = haxor.context.HaxorContext.update;
		{
			int _g1 = 0;
			int _g = update_p.get_length();
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.core.Resource r = ((haxor.core.Resource) (((java.lang.Object) (update_p.list.__get(i)) )) );
				if (r.m_destroyed) 
				{
					continue;
				}
				
				if (r.m_is_behaviour) 
				{
					haxor.component.Behaviour b = ((haxor.component.Behaviour) (r) );
					if ( ! (b.m_is_awake) ) 
					{
						b.OnAwake();
						b.m_is_awake = true;
					}
					
					if ( ! (b.m_is_start) ) 
					{
						b.OnStart();
						b.m_is_start = true;
					}
					
				}
				
				update_p.list.__get(i).OnUpdate();
			}
			
		}
		
	}
	
	
	public   void Render()
	{
		haxor.context.Process<haxor.core.IRenderable> render_p = haxor.context.HaxorContext.render;
		{
			int _g1 = 0;
			int _g = render_p.get_length();
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.core.Resource r = ((haxor.core.Resource) (((java.lang.Object) (render_p.list.__get(i)) )) );
				if (r.m_destroyed) 
				{
					continue;
				}
				
				render_p.list.__get(i).OnRender();
			}
			
		}
		
	}
	
	
	public   void Resize()
	{
		if (( this.state == haxor.core.EngineState.Editor )) 
		{
			return ;
		}
		
		haxor.context.Process<haxor.core.IResizeable> resize_p = haxor.context.HaxorContext.resize;
		{
			int _g1 = 0;
			int _g = resize_p.get_length();
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.core.Resource r = ((haxor.core.Resource) (((java.lang.Object) (resize_p.list.__get(i)) )) );
				if (r.m_destroyed) 
				{
					continue;
				}
				
				resize_p.list.__get(i).OnResize(haxor.graphics.Screen.m_width, haxor.graphics.Screen.m_height);
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef1908 = true;
			switch (field.hashCode())
			{
				case -983947138:
				{
					if (field.equals("m_application")) 
					{
						__temp_executeDef1908 = false;
						this.m_application = ((haxor.core.BaseApplication) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 109757585:
				{
					if (field.equals("state")) 
					{
						__temp_executeDef1908 = false;
						this.state = ((haxor.core.EngineState) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1908) 
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
			boolean __temp_executeDef1909 = true;
			switch (field.hashCode())
			{
				case -1850570540:
				{
					if (field.equals("Resize")) 
					{
						__temp_executeDef1909 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Resize"))) );
					}
					
					break;
				}
				
				
				case 109757585:
				{
					if (field.equals("state")) 
					{
						__temp_executeDef1909 = false;
						return this.state;
					}
					
					break;
				}
				
				
				case -1850724938:
				{
					if (field.equals("Render")) 
					{
						__temp_executeDef1909 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Render"))) );
					}
					
					break;
				}
				
				
				case -983947138:
				{
					if (field.equals("m_application")) 
					{
						__temp_executeDef1909 = false;
						return this.m_application;
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef1909 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Update"))) );
					}
					
					break;
				}
				
				
				case -1680869110:
				{
					if (field.equals("Collect")) 
					{
						__temp_executeDef1909 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Collect"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1909) 
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
			boolean __temp_executeDef1910 = true;
			switch (field.hashCode())
			{
				case -1850570540:
				{
					if (field.equals("Resize")) 
					{
						__temp_executeDef1910 = false;
						this.Resize();
					}
					
					break;
				}
				
				
				case -1680869110:
				{
					if (field.equals("Collect")) 
					{
						__temp_executeDef1910 = false;
						this.Collect();
					}
					
					break;
				}
				
				
				case -1850724938:
				{
					if (field.equals("Render")) 
					{
						__temp_executeDef1910 = false;
						this.Render();
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef1910 = false;
						this.Update();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1910) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_application");
		baseArr.push("state");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


