package haxor.core;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class RenderEngine extends haxe.lang.HxObject
{
	public    RenderEngine(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    RenderEngine()
	{
		haxor.core.RenderEngine.__hx_ctor_haxor_core_RenderEngine(this);
	}
	
	
	public static   void __hx_ctor_haxor_core_RenderEngine(haxor.core.RenderEngine __temp_me172)
	{
		{
		}
		
	}
	
	
	public static   void Render()
	{
		haxor.core.RenderEngine.RenderCameras();
	}
	
	
	public static   void RenderCameras()
	{
		haxe.root.Array<haxor.component.Camera> cl = haxor.context.EngineContext.camera.list;
		{
			int _g1 = 0;
			int _g = cl.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				haxor.component.Camera c = haxor.component.Camera.m_current = cl.__get(i);
				haxor.core.RenderEngine.RenderCamera(c);
			}
			
		}
		
	}
	
	
	public static   void RenderCamera(haxor.component.Camera c)
	{
		if ( ! (c.get_enabled()) ) 
		{
			return ;
		}
		
		haxor.context.EngineContext.camera.Bind(c);
		haxe.root.Array<java.lang.Object> layers = c.m_layers;
		{
			int _g1 = 0;
			int _g = layers.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				int l = ((int) (haxe.lang.Runtime.toInt(layers.__get(i))) );
				haxor.core.RenderEngine.RenderCameraLayer(l, c);
			}
			
		}
		
		if (( c == haxor.component.Camera.m_main )) 
		{
			haxor.context.EngineContext.gizmo.Render();
		}
		
		haxor.context.EngineContext.camera.Unbind(c);
	}
	
	
	public static   void RenderCameraLayer(int l, haxor.component.Camera c)
	{
		haxor.component.Transform lt = null;
		haxor.context.Process<haxor.component.Renderer> renderers = ((haxor.context.Process<haxor.component.Renderer>) (((haxor.context.Process) (haxor.context.EngineContext.renderer.display.__get(l)) )) );
		{
			int _g1 = 0;
			int _g = renderers.m_length;
			while (( _g1 < _g ))
			{
				int j = _g1++;
				haxor.component.Renderer r = renderers.list.__get(j);
				if (haxor.context.EngineContext.renderer.IsSAPCulled(r, c)) 
				{
					continue;
				}
				
				haxor.core.RenderEngine.RenderRenderer(r);
			}
			
		}
		
	}
	
	
	public static   void RenderRenderer(haxor.component.Renderer r)
	{
		r.UpdateCulling();
		if ( ! ((( r.m_visible &&  ! (r.m_culled)  ))) ) 
		{
			return ;
		}
		
		r.OnRender();
	}
	
	
	public static   void RenderFinish()
	{
		haxe.root.Array<haxor.component.Camera> cl = haxor.context.EngineContext.camera.list;
		{
			int _g1 = 0;
			int _g = cl.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				cl.__get(i).m_view_uniform_dirty = false;
				cl.__get(i).m_proj_uniform_dirty = false;
			}
			
		}
		
		haxor.context.EngineContext.renderer.sap_dirty = false;
	}
	
	
	public static   void Resize()
	{
		haxor.context.EngineContext.camera.Resize();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.core.RenderEngine(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.core.RenderEngine();
	}
	
	
}


