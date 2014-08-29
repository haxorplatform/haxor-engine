package haxor.input;
import haxor.core.Enums.InputState;
import haxor.math.Vector3;

/**
 * Class that describes a gamepad data structure.
 */
@:allow(haxor)
class Joystick
{
	
	/**
	 * Bias to declare a margin of 'no-input or full-input' for the analog sticks. Adjust it to tune your joystick sensitivity.
	 */
	static public var analogBias : Array<Float> = [0.1,0.9];
	
	/**
	 * Bias to define a margin of 'no-input or full-input' for analog buttons. Adjust it to tune your joystick sensitivity.
	 */
	static public var buttonBias : Float 		= 0.9;
	
	/**
	 * Flag that indicates if gamepads are available.
	 */
	static public var available : Bool 			= false;	
	
	/**
	 * Joystick name.
	 */
	public var name : String;
	
	/**
	 * Id of this joystick.
	 */
	public var id : Int;
	
	/**
	 * Button input values. Use 'KeyCode' to index the desired attribute.
	 */
	public var button : Array<Float>;
	
	/**
	 * Input state for buttons.
	 */
	public var state : Array<InputState>;
	
	/**
	 * Hold time for this joystick buttons.
	 */
	public var hold : Array<Float>;
	
	/**
	 * Analog values.
	 */
	public var analog : Array<Float>;
	
	/**
	 * Left analog position uses x[-1,1] y[-1,1] ranges.
	 */
	public var analogLeft  : Vector3;
	
	/**
	 * Right analog position uses x[-1,1] y[-1,1] ranges.
	 */
	public var analogRight : Vector3;
	
	/**
	 * Left trigger ranges uses [0.0,1.0] ranges.
	 */
	public var triggerLeft  : Float;
	
	/**
	 * Right trigger ranges uses [0.0,1.0] ranges.
	 */
	public var triggerRight : Float;
	
	/**
	 * Creates a new joystick instance.
	 */
	private function new()
	{
		var st : InputState = InputState.None;
		
		name 		 = "";
		id   		 = -1;
		button  	 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];		
		state   	 = [st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st, st];
		hold    	 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
		analog  	 = [0, 0, 0, 0, 0, 0, 0, 0];
		analogLeft   = new Vector3();
		analogRight  = new Vector3();
		triggerLeft  = 0.0;
		triggerRight = 0.0;
	}
	
	/**
	 * Checks if a given joystick button is down.
	 * @param	p_button
	 * @return
	 */
	public function IsDown(p_button : Int):Bool { return (state[p_button] == InputState.Hold) || (state[p_button] == InputState.Down); }
	
	/**
	 * Checks if a given joystick button was released.
	 * @param	p_button
	 * @return
	 */
	public function Hit(p_button : Int):Bool    { return (state[p_button] == InputState.Up); }
	
	
}