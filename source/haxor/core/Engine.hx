package haxor.core;
import haxor.component.Behaviour;
import haxor.component.Camera;
import haxor.component.Renderer;
import haxor.component.Transform;
import haxor.context.EngineContext;
import haxor.context.Process;
import haxor.graphics.Graphics;
import haxor.graphics.Screen;

/**
 * Engine execution state.
 */
enum EngineState
{
	Play;
	Editor;	
}


/**
 * Class that describes the update and rendering engine.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Engine
{
	
	/**
	 * Engine execution state.
	 */
	static private var state : EngineState;
		
	/**
	 * Creates the engine.
	 * @param	p_application
	 */
	static private function Initialize():Void
	{
		Console.Log("Haxor> Engine Initialize.",3);
		EngineContext.Initialize();		
		state 		  = EngineState.Play;
	}
	
	/**
	 * Calls the destroy callback for destroyed elements.
	 */
	static private function Collect():Void
	{
		var dp : Process<IDisposable> = EngineContext.disposables;						
		for (i in 0...EngineContext.collectRate)
		{
			if (dp.length <= 0) break;
			var o : IDisposable = dp.list[0];
			o.OnDestroy();
			dp.Remove(cast o);
		}
	}
	
	/**
	 * Update callback. Runs at the minimum latency allowed by the platform.
	 */
	static private function Update():Void
	{
		if (state == EngineState.Editor) return;
		
		var up : Process<IUpdateable> = EngineContext.update;				
		
		for (i in 0...up.length)
		{
			var r : Resource = cast up.list[i];
			if (r.m_destroyed) continue;
			if (r.m_is_behaviour)
			{
				var b : Behaviour = cast r;
				if (!b.m_is_awake) { b.OnAwake(); b.m_is_awake = true; }
				if (!b.m_is_start) { b.OnStart(); b.m_is_start = true; }
			}			
			up.list[i].OnUpdate();
		}
	}
	
	/**
	 * Render callback. Runs at the FPS specified at the Application class.
	 */
	static private function Render():Void
	{		
		var cl  : Array<Camera> = EngineContext.camera.list;
		
		//Shadow Collect Pass
		
		for (i in 0...cl.length)
		{
			var c : Camera = Camera.m_current = cl[i];			
			RenderCamera(c);
		}
		
		Camera.m_current = null;
		
		RenderIRenderers();
		
		for (i in 0...cl.length)
		{
			cl[i].m_view_uniform_dirty = false;
			cl[i].m_proj_uniform_dirty = false;
		}
	}
	
	/**
	 * Renders a camera.
	 * @param	c
	 */
	static private function RenderCamera(c:Camera):Void
	{
		if (!c.enabled) return;
		EngineContext.camera.Bind(c);			
		var layers : Array<Int> = c.m_layers;						
		for (i in 0...layers.length)
		{	
			var l : Int = layers[i];
			RenderCameraLayer(l, c);
		}		
		
		//Filters			
		
		EngineContext.camera.Unbind(c);
	}
	
	/**
	 * Renders a camera layer display list.
	 * @param	l
	 * @param	c
	 */
	static private function RenderCameraLayer(l:Int,c:Camera):Void
	{
		var lt  : Transform			   	  = null; //Last used transform.
		var renderers : Process<Renderer> = EngineContext.renderer.display[l];
		for (j in 0...renderers.length)
		{
			var r : Renderer = renderers.list[j];			
			//If the current Renderer's Entity is different reset the uniform flag of the last transform.
			if (r.transform != lt) { if(lt!=null) lt.m_uniform_dirty = false; lt = r.transform; }
			RenderRenderer(r);
		}
	}
	
	/**
	 * Renders the target renderer.
	 * @param	r
	 */
	static private function RenderRenderer(r : Renderer):Void
	{		
		//Grab Texture if requested. Check index of start then capture up to it, then stop for optimization.
			
		r.OnRender();
			
		//Shadow Cast if receiver.			
	}
	
	/**
	 * Render renderers based on IRenderers.
	 */
	static private function RenderIRenderers():Void
	{
		var rp  : Process<IRenderable> = EngineContext.render;		
		//"Free" renderers pass.
		for (i in 0...rp.length)
		{
			var r : Resource = cast rp.list[i];
			if (r.m_destroyed) continue;
			rp.list[i].OnRender();
		}
	}
	
	/**
	 * Resize callback.
	 */
	static private function Resize():Void
	{
		EngineContext.camera.Resize();
		if (state == EngineState.Editor) return;
		var rp : Process<IResizeable> = EngineContext.resize;				
		for (i in 0...rp.length)
		{
			var r : Resource = cast rp.list[i];
			if (r.m_destroyed) continue;
			rp.list[i].OnResize(Screen.m_width, Screen.m_height);
		}
	}
	
}