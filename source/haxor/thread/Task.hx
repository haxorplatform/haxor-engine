package haxor.thread;
import haxor.core.Console;
import haxor.platform.Types.Float32;

/**
 * Base class for async operations that can run on the main thread or in an extra one.
 * This class can be extended to implement the target functionality the user wants.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Task extends Activity
{
	/**
	 * Progress of the activity. The user must manually update it to finish the Task.
	 */
	public var progress(get_progress,set_progress) : Float32;
	private inline function get_progress():Float32{ return m_progress; }
	private function set_progress(v:Float32):Float32{ if (Math.abs(v-m_progress) > 0.0) { m_progress = v; m_has_progress = true; } return v; }
	private var m_progress : Float32;
	private var m_has_progress : Bool;

	/**
	 * Flag that indicates if the Task has been activated.
	 */
	public var active(get_active, null):Bool;
	private inline function get_active():Bool { return m_active; }
	private var m_active : Bool;
	
	/**
	 * Creates a new Activity with the option of being threaded or not.
	 * @param	p_threaded
	 */
	public function new(p_threaded:Bool=false,p_callback : Float->Bool=null) 
	{
		var cb : Float->Bool = p_callback;
		if (cb == null) cb = OnExecute;
		super(cb, p_threaded);
		m_active = false;
		m_progress = 0.0;
		m_has_progress = false;
	}
	
	/**
	 * Callback called when the Task has started.
	 */
	private function OnStart():Void { }
	
	/**
	 * Callback called while the Task is updated.
	 */
	private function OnStep():Void { }
	
	/**
	 * Callback called when the Task is completed.
	 */
	private function OnComplete():Void { }
	
	/**
	 * Callback called when there was progress between steps.
	 */
	private function OnProgress():Void { }
	
	/**
	 * Internal execution step.
	 * @param	p_time
	 * @return
	 */
	private function OnExecute(p_time:Float32):Bool
	{
		if (!m_active) { m_active = true; OnStart(); }
		OnStep();		
		if (m_has_progress) { OnProgress(); m_has_progress = false; }
		if (progress >= 1.0) { OnComplete(); return false; }
		return true;
	}
	
}