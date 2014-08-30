package haxor.input;
import haxor.core.Enums.InputState;
import haxor.math.Vector2;

/**
 * Class that describes a Touch input data structure.
 */
@:allow(haxor)
class Touch
{
	
	/**
	 * Input state of this Touch instance.
	 */
	public var state 	: InputState;
	
	/**
	 * Id of this touch.
	 */
	public var id 		: Int;
	
	/**
	 * Position of this touch in the screen.
	 */
	public var position : Vector2;
	
	/**
	 * Touch area radius. (not always available)
	 */
	public var radius : Vector2;
	
	/**
	 * Touch angle. (not always available).
	 */
	public var angle : Float;
	
	/**
	 * Relative position in the screen inside the [0.0,1.0] range.
	 */
	public var relativePosition : Vector2;
	
	/**
	 * Touch movement delta.
	 */
	public var delta 	: Vector2;
	
	/**
	 * Touch pressure. (not always available).
	 */
	public var pressure : Float;
	
	/**
	 * Holding time for this touch instance.
	 */
	public var hold : Float;
	
	private var m_down : Bool;
	
	/**
	 * Creates a new Touch data structure.
	 */
	private function new()
	{
		state		 		= InputState.None;
		id 			 		= -1;
		position 	 		= new Vector2();
		delta 				= new Vector2();
		relativePosition 	= new Vector2();
		pressure 			= 0;
		hold 				= 0;	
		angle 				= 0;
		radius 				= new Vector2();
		m_down 				= false;
	}	
	
	/**
	 * Returns the string representation of this touch structure.
	 * @return
	 */
	public function ToString():String
	{
		return "id[" + id + "] pos" + position.ToString(2) + "[" + state+"]";
	}
}