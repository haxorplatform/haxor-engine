package haxor.input;
import haxor.core.Enums.InputState;
import haxor.math.Mathf;
import haxor.math.Vector3;
import haxor.platform.Types.Float32;

/**
 * Class that describes a gamepad data structure.
 */
@:allow(haxor)
class Joystick
{
	
	/**
	 * Bias to declare a margin of 'no-input or full-input' for the analog sticks. Adjust it to tune your joystick sensitivity.
	 */
	static public var analogBias : Array<Float32> = [0.1,0.9];
	
	/**
	 * Bias to define a margin of 'no-input or full-input' for analog buttons. Adjust it to tune your joystick sensitivity.
	 */
	static public var buttonBias : Float32 = 0.9;
	
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
	 * Button RAW input values. Use 'KeyCode' to index the desired attribute.
	 */
	public var button : Array<Float32>;
	
	/**
	 * Input state for buttons.
	 */
	public var state : Array<InputState>;
	
	/**
	 * Hold time for this joystick buttons.
	 */
	public var hold : Array<Float32>;
	
	/**
	 * Analog RAW values.
	 */
	public var analog : Array<Float32>;
	
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
	public var triggerLeft  : Float32;
	
	/**
	 * Right trigger ranges uses [0.0,1.0] ranges.
	 */
	public var triggerRight : Float32;
	
	/**
	 * Vibration intensity in the left motor.
	 */
	public var vibrationLeft(get_vibrationLeft, set_vibrationLeft):Float32;
	private inline function get_vibrationLeft():Float32{ return m_vibrationLeft; }
	private function set_vibrationLeft(v:Float32):Float32{ if (Mathf.Abs(m_vibrationLeft - v) <= 0.0) return v; m_vibrationLeft = v; Input.m_handler.RequestJoystickVibration(this); return v; }	
	private var m_vibrationLeft : Float32;
	
	/**
	 * Vibration intensity in the right motor.
	 */
	public var vibrationRight(get_vibrationRight, set_vibrationRight):Float32;
	private inline function get_vibrationRight():Float32{ return m_vibrationRight; }
	private function set_vibrationRight(v:Float32):Float32{ if (Mathf.Abs(m_vibrationRight - v) <= 0.0) return v; m_vibrationRight = v; Input.m_handler.RequestJoystickVibration(this); return v; }	
	private var m_vibrationRight : Float32;
	
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
		m_vibrationLeft  = 0.0;
		m_vibrationRight = 0.0;
	}
	
	/**
	 * Checks if a given joystick button is down.
	 * @param	p_button
	 * @return
	 */
	public function Pressed(p_button : Int):Bool { return (state[p_button] == InputState.Hold) || (state[p_button] == InputState.Down); }
	
	/**
	 * Returns a flag that indicates if the button was pressed.
	 * @param	p_button
	 * @return
	 */
	public function Down(p_button : Int):Bool { return (state[p_button] == InputState.Down); }
	
	/**
	 * Checks if a given joystick button was released.
	 * @param	p_button
	 * @return
	 */
	public function Hit(p_button : Int):Bool    { return (state[p_button] == InputState.Up); }
	
	/**
	 * Returns the string representation of this joystick data.
	 * @return
	 */
	public function ToString(p_analog : Bool=true,p_button:Bool=true,p_trigger:Bool=true,p_pad:Bool=true):String
	{
		var s : String = "";
		s += "J" + id;
		if (p_analog)
		{
			s += " AL" + analogLeft.ToString(1);
			s += " AR" + analogRight.ToString(1); 
		}		
		
		if (p_button)
		{
			s += " A[" + (Pressed(KeyCode.ButtonA) ? "1]" : "0]");
			s += " B[" + (Pressed(KeyCode.ButtonB) ? "1]" : "0]");
			s += " X[" + (Pressed(KeyCode.ButtonX) ? "1]" : "0]");
			s += " Y[" + (Pressed(KeyCode.ButtonY) ? "1]" : "0]");
			s += " L[" + (Pressed(KeyCode.LeftShoulder) ? "1]" : "0]");
			s += " R[" + (Pressed(KeyCode.RightShoulder) ? "1]" : "0]");
			s += " LB[" + (Pressed(KeyCode.LeftShoulderBottom) ? "1]" : "0]");
			s += " RB[" + (Pressed(KeyCode.RightShoulderBottom) ? "1]" : "0]");
			s += " Start[" + (Pressed(KeyCode.ButtonStart) ? "1]" : "0]");
			s += " Select[" + (Pressed(KeyCode.ButtonSelect) ? "1]" : "0]");
		}
		
		if (p_pad)
		{
			s += " PL[" + (Pressed(KeyCode.PadLeft)   ? "1]" : "0]");
			s += " PR[" + (Pressed(KeyCode.PadRight)  ? "1]" : "0]");
			s += " PU[" + (Pressed(KeyCode.PadTop)    ? "1]" : "0]");
			s += " PD[" + (Pressed(KeyCode.PadBottom) ? "1]" : "0]");			
		}
		
		if (p_trigger)
		{
			s += " TL[" + Mathf.RoundPlaces(triggerLeft, 1) + "]";
			s += " TR[" + Mathf.RoundPlaces(triggerRight, 1) + "]";
		}
		return s;
	}
}