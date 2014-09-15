package haxor.input;
import haxor.core.Console;
import haxor.core.Enums.InputState;
import haxor.core.Time;
import haxor.math.Vector2;
import haxor.platform.Types.Float32;

/**
 * Class that holds Input information for the application. It includes keyboard, mouse, touch and gamepad realtime data.
 * In the future more devices and hardware (e.g. Occulus) can enter this class.
 * @author Eduardo Pons
 */
@:allow(haxor)
class Input 
{
	
	/**
	 * Table of KeyCodes and its input states.
	 */
	static var m_state : Map<Int,InputState>;
	
	/**
	 * Table of KeyCodes and its hold time.
	 */
	static var m_hold : Map<Int,Float>;
	
	/**
	 * List of down state flags indexed by KeyCodes.
	 */
	static var m_down: Array<Bool>;
		
	/**
	 * List of active keycode to optimize state update only for active keys/buttons.
	 */
	//static public var active(get_active, never) : Array<Int>;		
	//static function get_active() : Array<Int> { return m_active; }
	static var m_active: Array<Int>;
	
	/**
	 * Reference to the current handler.
	 */
	static var m_handler : InputHandler;
	
	/**
	 * List of touches occuring in the current frame.
	 */
	static public var touches(get_touches, never) : Array<Touch>;		
	static function get_touches() : Array<Touch> { return m_touches; }
	static var m_touches : Array<Touch>;
	static var m_api_touches : Array<Touch>;
	
	/**
	 * List of joysticks available.
	 */
	static public var joystick(get_joystick, never) : Array<Joystick>;	
	static function get_joystick() : Array<Joystick> { return m_joysticks; }
	static var m_joysticks    : Array<Joystick>;
	static var m_api_joystick : Array<Joystick>;
	
	
	/**
	 * Flag that indicates if touch input are available.
	 */
	static public var multitouch(get_multitouch, never) : Bool;	
	static function get_multitouch():Bool { return m_multitouch; }
	static var m_multitouch : Bool;
	
	/**
	 * Mouse position.
	 */
	static public var mouse : Vector2;
		
	/**
	 * Mouse moviment delta.
	 */
	static public var deltaMouse : Vector2;
	
	/**
	 * Mouse position relative to screen size in [0.0,1.0] range.
	 */
	static public var relativeMouse : Vector2;
	
	/**
	 * Mouse wheel delta.
	 */
	static public var wheel : Float32;
	
	/**
	 * Flag that tells if page scrolling is enabled (html-only)
	 */
	static public var scroll : Bool = false;
	
	/**
	 * Flag that indicates if context menu is allowed. Valid for platforms which supports context menus.
	 */
	static public var menu : Bool = false;
	
	/**
	 * Flag that indicates if touches will be emulated using Mouse012.
	 */
	static public var emulateTouch : Bool = false;
	
	/**
	 * Returns the input state for a given mouse or keyboard input "key" (check KeyCode).
	 * @param	p_code
	 * @return
	 */
	static public function GetInputState(p_code : Int) : InputState 
	{ 
		return m_state.get(p_code); 
	}
	
	/**
	 * Returns a flag that tells if a given key or mouse button is down.
	 * @param	p_code
	 * @return
	 */
	static public function Pressed(p_code : Int) : Bool 
	{
		var s : InputState = GetInputState(p_code);
		return (s == InputState.Down) || (s == InputState.Hold);
	}
	
	/**
	 * Returns a flag that tells if the key/button was just pressed.
	 * @param	p_code
	 * @return
	 */
	static public function Down(p_code : Int) : Bool 
	{
		var s : InputState = GetInputState(p_code);
		return (s == InputState.Down);
	}
	
	/**
	 * Returns a flag that indicates if a given key or mouse button was released.
	 * @param	p_code
	 * @return
	 */
	static public function Hit(p_code : Int) : Bool 
	{
		var s : InputState = GetInputState(p_code);
		return (s == InputState.Up);
	}
	
	/**
	 * Retrieves the holding time of a given key or mouse button.
	 * @param	p_code
	 * @return
	 */
	static public function GetHoldTime(p_code : Int) : Float32 { return m_hold.get(p_code); }
	
	/**
	 * Initializes the Input class.
	 * @param	p_target
	 */
	static function Initialize():Void
	{
		m_state 			= new Map<Int,InputState>();
		m_hold  			= new Map<Int,Float>();
		m_active 			= new Array<Int>();
		m_down 				= new Array <Bool>();		
		
		m_touches 			= [];
		m_api_touches		= [];
		
		for (i in 0...10)
		{
			m_api_touches.push(new Touch());
		}
		
		for (i in 0...256)
		{
			m_state.set(i, InputState.None);		
			m_hold.set(i, 0);	
			m_down.push(false);
		}
		
		m_joysticks 	= []; //List of active joysticks
		m_api_joystick 	= []; //Instance holder to the API update and move to 'm_joysticks'.
		for (i in 0...10)
		{
			m_api_joystick.push(new Joystick());
		}
		
		mouse 				= new Vector2();
		deltaMouse 			= new Vector2();
		relativeMouse 		= new Vector2();
		
		Console.Log("Haxor> Input Initialize",4);
	}
	
	/**
	 * Updates all touches FSM.
	 */
	static private function UpdateTouchFSM():Void 
	{ 
		for (j in 0...m_touches.length) TouchFSM(m_touches[j]); 
	}
	
	/**
	 * Updates all active input keycodes.
	 */
	static private function UpdateInput():Void { for (i in 0...m_active.length) UpdateInputState(m_active[i], m_down[m_active[i]]); }
	
	/**
	 * Updates the Touch FSM machine.
	 * @param	t
	 */
	static private function TouchFSM(t : Touch):Void
	{
		if (t == null) return;		
		var current : InputState 	= t.state;		
		var d 		: Bool 			= t.m_down;		
		if (current == InputState.Up) 	m_touches.remove(t);		
		if (current == InputState.Hold)	t.hold += Time.delta;
		t.state = InputStateFSM(current, d);		
	}
	
	/**
	 * Updates the State of a single input.
	 * @param	p_code
	 * @param	p_is_down
	 */
	static function UpdateInputState(p_code : Int, p_is_down:Bool,p_update_state:Bool=true) : Void
	{
		var current : InputState 	= m_state.get(p_code);
		if(current == null) current =  InputState.None;
		var next 	: InputState 	= current;
		var d0 		: Bool 		 	= m_down[p_code];
		var d  		: Bool 		 	= m_down[p_code] = p_is_down;
		
		if (!d0) if (d) { m_active.push(p_code);  }
		if (!d) if (d0) { return; }
		
		if (p_update_state)
		{
			if (current == InputState.Up)
			{
				m_hold.set(p_code, 0);
				m_active.remove(p_code);
			}
			
			if (current == InputState.Hold)
			{
				var h:Float32= m_hold.get(p_code);
				m_hold.set(p_code, h + Time.delta);
			}
			
			next = InputStateFSM(current, d);
			
			if (current != next) m_state.set(p_code, next);
		}
	}
	
	/**
	 * FSM that handles the change of state of input elements.
	 * @param	p_current
	 * @param	p_is_down
	 * @return
	 */
	static function InputStateFSM(p_current : InputState, p_is_down:Bool) : InputState
	{
		var current : InputState = p_current;
		var next 	: InputState = current;
		var d 		: Bool 		 = p_is_down;		
		switch(current)
		{
			case InputState.None: 
				if (d) { next = InputState.Down; }				
			case InputState.Down: 
				if (!d) next = InputState.Up;
				next = InputState.Hold;
				
			case InputState.Up:				
				next = InputState.None;				
				
			case InputState.Hold:				
				if (!d) next = InputState.Up;
		}
		return next;
	}
	
	
}