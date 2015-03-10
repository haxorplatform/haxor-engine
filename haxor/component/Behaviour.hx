package haxor.component;
import haxor.context.EngineContext;
import haxor.core.Console;
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
		if (m_enabled == v) return v;
		m_enabled = v;		
		if (v) EngineContext.Enable(this); else EngineContext.Disable(this);
		return v; 
	}
	private var m_enabled : Bool;
	
	/**
	 * Flag that indicates if this behaviour has awaken.
	 */
	private var m_is_awake : Bool;
	
	/**
	 * Flag that indicates if this behaviour has started.
	 */
	private var m_is_start : Bool;

	/**
	 * Method called when the component is created.
	 */
	override function OnBuild():Void 
	{
		super.OnBuild();		
		m_enabled 		= true;
		m_is_behaviour  = true;
		m_is_awake		= false;
		m_is_start		= false;
		EngineContext.Enable(this);
		EngineContext.awake.push(this);
		EngineContext.start.push(this);
	}
	
	/**
	 * Method called after OnBuild and before OnStart if this behaviour is enabled..
	 */
	private function OnAwake():Void { }
	
	/**
	 * Method called after OnAwake if this behaviour is enabled.
	 */
	private function OnStart():Void { }
	
}