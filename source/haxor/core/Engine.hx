package haxor.core;
import haxor.component.animation.Animation;
import haxor.component.Behaviour;
import haxor.context.EngineContext;
import haxor.context.Process;
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
		
		#if !ie8
		Animation.Update();
		#end
		
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
		#if !ie8
		RenderEngine.Render();
		#end
		
		RenderIRenderers();
		
		#if !ie8
		RenderEngine.RenderFinish();
		#end
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
		#if !ie8
		RenderEngine.Resize();
		#end
		
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