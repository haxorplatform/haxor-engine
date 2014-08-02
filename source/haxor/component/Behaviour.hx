package haxor.component;
import haxor.context.HaxorContext;
import haxor.core.IRenderable;
import haxor.core.IResizeable;
import haxor.core.IUpdateable;

/**
 * Components specialization to allow enabling and disabling.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Behaviour extends Component
{
	/**
	 * Flag that indicates if the component is active.
	 */
	public var enabled(get_enabled, set_enabled):Bool;
	private function get_enabled() : Bool { return m_enabled && (!m_destroyed); }
	private function set_enabled(v:Bool) : Bool 
	{ 
		if (m_destroyed) return false;
		m_enabled = v; 
		UpdateContextFlag(v);
		return v; 
	}
	private var m_enabled : Bool;
	
	/**
	 * Lookup flag for the interface.
	 */
	private var m_is_updateable : Bool;
	
	/**
	 * Lookup flag for the interface.
	 */
	private var m_is_renderable : Bool;
	
	/**
	 * Lookup flag for the interface.
	 */
	private var m_is_resizeable : Bool;
	
	/**
	 * Flag that indicates if this behaviour has awaken.
	 */
	private var m_is_awake : Bool;
	
	/**
	 * Flag that indicates if this behaviour has started.
	 */
	private var m_is_start : Bool;

	function new() 
	{
		super();
		
		m_enabled 		= true;
		m_is_behaviour  = true;
		m_is_updateable = Std.is(this, IUpdateable);
		m_is_renderable = Std.is(this, IRenderable);
		m_is_resizeable = Std.is(this, IResizeable);
		
		UpdateContextFlag(true);
	}
	
	/**
	 * Method called after OnBuild and before OnStart if this behaviour is enabled..
	 */
	private function OnAwake():Void { }
	
	/**
	 * Method called after OnAwake if this behaviour is enabled.
	 */
	private function OnStart():Void { }
	
	
	private function UpdateContextFlag(p_flag:Bool):Void
	{
		if (m_is_updateable) { if(p_flag) HaxorContext.update.Add(this); else HaxorContext.update.Remove(this); }
		if (m_is_renderable) { if(p_flag) HaxorContext.render.Add(this); else HaxorContext.render.Remove(this); }
		if (m_is_resizeable) { if(p_flag) HaxorContext.resize.Add(this); else HaxorContext.resize.Remove(this); }
	}
}