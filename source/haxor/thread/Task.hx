package haxor.thread;

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
	public var progress : Float;

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
		progress = 0.0;
	}
	
	/**
	 * Callback called when the Task has started.
	 */
	public function OnStart():Void { }
	
	/**
	 * Callback called while the Task is updated.
	 */
	public function OnStep():Void { }
	
	/**
	 * Callback called when the Task is completed.
	 */
	public function OnComplete():Void { }
	
	/**
	 * Internal execution step.
	 * @param	p_time
	 * @return
	 */
	private function OnExecute(p_time:Float):Bool
	{
		if (!m_active) { m_active = true; OnStart(); }
		OnStep();
		if (progress >= 1.0) { OnComplete(); return false; }
		return true;
	}
	
}