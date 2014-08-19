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
	
	
	public    Engine()
	{
		haxor.core.Engine.__hx_ctor_haxor_core_Engine(this);
	}
	
	
	public static   void __hx_ctor_haxor_core_Engine(haxor.core.Engine __temp_me42360)
	{
		{
		}
		
	}
	
	
	public static  haxor.core.EngineState state;
	
	public static   void Initialize()
	{
		haxor.core.Console.Log("Haxor> Engine Initialize.", 3);
		haxor.context.EngineContext.Initialize();
		haxor.core.Engine.state = haxor.core.EngineState.Play;
	}
	
	
	public static   void Collect()
	{
		haxor.context.Process<haxor.core.IDisposable> dp = haxor.context.EngineContext.disposables;
		{
			int _g1 = 0;
			int _g = haxor.context.EngineContext.collectRate;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				if (( dp.m_length <= 0 )) 
				{
					break;
				}
				
				haxor.core.IDisposable o = dp.list.__get(0);
				o.OnDestroy();
				dp.Remove(((haxor.core.Resource) (o) ));
			}
			
		}
		
	}
	
	
	public static   void Update()
	{
		if (( haxor.core.Engine.state == haxor.core.EngineState.Editor )) 
		{
			return ;
		}
		
		haxor.context.Process<haxor.core.IUpdateable> up = haxor.context.EngineContext.update;
		{
			int _g1 = 0;
			int _g = up.m_length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.core.Resource r = ((haxor.core.Resource) (((java.lang.Object) (up.list.__get(i)) )) );
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
				
				up.list.__get(i).OnUpdate();
			}
			
		}
		
	}
	
	
	public static   void Render()
	{
		haxor.context.Process<haxor.core.IRenderable> rp = haxor.context.EngineContext.render;
		{
			int _g1 = 0;
			int _g = rp.m_length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.core.Resource r = ((haxor.core.Resource) (((java.lang.Object) (rp.list.__get(i)) )) );
				if (r.m_destroyed) 
				{
					continue;
				}
				
				rp.list.__get(i).OnRender();
			}
			
		}
		
	}
	
	
	public static   void Resize()
	{
		if (( haxor.core.Engine.state == haxor.core.EngineState.Editor )) 
		{
			return ;
		}
		
		haxor.context.Process<haxor.core.IResizeable> rp = haxor.context.EngineContext.resize;
		{
			int _g1 = 0;
			int _g = rp.m_length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.core.Resource r = ((haxor.core.Resource) (((java.lang.Object) (rp.list.__get(i)) )) );
				if (r.m_destroyed) 
				{
					continue;
				}
				
				rp.list.__get(i).OnResize(haxor.graphics.Screen.m_width, haxor.graphics.Screen.m_height);
			}
			
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.core.Engine(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.Engine();
	}
	
	
}


