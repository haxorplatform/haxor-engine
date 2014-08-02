package haxor.core;
import haxor.component.Behaviour;
import haxor.context.HaxorContext;
import haxor.context.Process;
import haxor.graphics.Screen;

enum EngineState
{
	Play;
	Editor;	
}


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Engine
{
	
	/**
	 * Engine execution state.
	 */
	public var state : EngineState;
	
	/**
	 * Reference to the created application.
	 */
	private var m_application : BaseApplication;
	
	/**
	 * Creates the engine.
	 * @param	p_application
	 */
	public function new(p_application:BaseApplication) 
	{
		m_application = p_application;
		state = EngineState.Play;
	}
	
	/**
	 * Calls the destroy callback for destroyed elements.
	 */
	public function Collect():Void
	{
		
		var dispose_p : Process<IDisposable> = HaxorContext.disposables;						
		for (i in 0...HaxorContext.collectRate)
		{
			if (dispose_p.length <= 0) break;
			var o : IDisposable = dispose_p.list[0];
			o.OnDestroy();
			dispose_p.Remove(cast o);
		}
	}
	
	/**
	 * Update callback. Runs at the minimum latency allowed by the platform.
	 */
	public function Update():Void
	{
		if (state == EngineState.Editor) return;
		
		var update_p : Process<IUpdateable> = HaxorContext.update;				
		
		for (i in 0...update_p.length)
		{
			var r : Resource = cast update_p.list[i];
			if (r.m_destroyed) continue;
			if (r.m_is_behaviour)
			{
				var b : Behaviour = cast r;
				if (!b.m_is_awake) { b.OnAwake(); b.m_is_awake = true; }
				if (!b.m_is_start) { b.OnStart(); b.m_is_start = true; }
			}			
			update_p.list[i].OnUpdate();
		}
	}
	
	/**
	 * Render callback. Runs at the FPS specified at the Application class.
	 */
	public function Render():Void
	{
		
		var render_p : Process<IRenderable> = HaxorContext.render;				
		for (i in 0...render_p.length)
		{
			var r : Resource = cast render_p.list[i];
			if (r.m_destroyed) continue;
			render_p.list[i].OnRender();
		}
	}
	
	/**
	 * Resize callback.
	 */
	public function Resize():Void
	{
		if (state == EngineState.Editor) return;
		var resize_p : Process<IResizeable> = HaxorContext.resize;				
		for (i in 0...resize_p.length)
		{
			var r : Resource = cast resize_p.list[i];
			if (r.m_destroyed) continue;
			resize_p.list[i].OnResize(Screen.m_width, Screen.m_height);
		}
	}
	
}