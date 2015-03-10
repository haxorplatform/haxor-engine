package haxor.component.animation;

/**
 * Class that describes an Animation event instance.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class AnimationEvent
{
	/**
	 * Frame that the event will be dispatched.
	 */
	public var frame : Int;
	
	/**
	 * Arguments of this event.
	 */
	public var args : Array<Dynamic>;
	
	/**
	 * Listener that was called.
	 */
	public var listener : AnimationEvent -> Void;
	
	/**
	 * Repeat count of this event.
	 */
	public var repeat : Int;
	
	/**
	 * Creates a new Animation event.
	 * @param	p_frame
	 * @param	p_listener
	 * @param	p_repeat
	 * @param	p_args
	 */
	private function new(p_frame : Int, p_listener : AnimationEvent -> Void,p_repeat : Int=0, p_args : Array<Dynamic> = null)
	{
		frame 	 = p_frame;
		listener = p_listener;
		args     = p_args == null ? [] : p_args;
		repeat   = p_repeat;
	}
	
	/**
	 * Dispatches this event.
	 * @return
	 */
	private function Dispatch():Bool
	{
		if (listener != null)
		{
			listener(this);
			if (repeat <= 0) return true;
			repeat--;
			if (repeat <= 0) return false;			
			return true;
		}
		return false;
	}
}