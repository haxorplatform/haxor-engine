package haxor.input;
import haxor.core.Console;
import haxor.core.Enums.InputState;
import haxor.core.Time;
import haxor.graphics.Screen;
import haxor.math.Mathf;
import haxor.math.Random;
import haxor.math.Vector2;
import haxor.math.Vector3;
import haxor.thread.Activity;

/**
 * Base class that will handle input updates from every platform.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class InputHandler
{

	/**
	 * Reference for the currently active joystick being updated.
	 */
	private var m_joystick : Joystick;
	
	/**
	 * Creates a new input handler.
	 */
	function new() 
	{
		Activity.Run(Update);
	}
	
	private function Update(t:Float):Bool
	{
		Input.wheel 	   = 0; 
		Input.deltaMouse.x = 0; 
		Input.deltaMouse.y = 0;		
		Input.UpdateInput();
		Input.UpdateTouchFSM();		
		UpdateInput();		
		EmulateTouch(KeyCode.Mouse0, 0);
		EmulateTouch(KeyCode.Mouse1, 2);
		EmulateTouch(KeyCode.Mouse2, 1);		
		return true;
	}
	
	/**
	 * Update API related input.
	 */
	private function UpdateInput():Void { }
	
	/**
	 * Updates mouse position data.
	 * @param	p_x
	 * @param	p_y
	 */
	private function OnMouseMove(p_x:Float,p_y:Float):Void
	{
		Input.deltaMouse.x = p_x - Input.mouse.x;
		Input.deltaMouse.y = p_y - Input.mouse.y;
		Input.mouse.x = p_x;
		Input.mouse.y = p_y;
		Input.relativeMouse.x = Input.mouse.x / Screen.width;
		Input.relativeMouse.y = Input.mouse.y / Screen.height;
	}
	
	/**
	 * Updates MouseWheel data.
	 * @param	p_wheel
	 */
	private function OnMouseWheel(p_wheel:Float):Void
	{
		Input.wheel = p_wheel;
	}
	
	/**
	 * Updates mouse button flags.
	 * @param	p_button
	 * @param	p_down
	 */
	private function OnMouseButton(p_button : Int, p_down:Bool):Void
	{
		switch(p_button)
		{
			case 0: { Input.UpdateInputState(KeyCode.Mouse0, p_down,false);  }
			case 1: { Input.UpdateInputState(KeyCode.Mouse1, p_down,false);  }
			case 2: { Input.UpdateInputState(KeyCode.Mouse2, p_down,false);  }
			case 3: { Input.UpdateInputState(KeyCode.Mouse3, p_down,false);  }
			case 4: { Input.UpdateInputState(KeyCode.Mouse4, p_down,false);  }					
		}
	}
	
	/**
	 * Updates keyboard flags.
	 * @param	p_code
	 * @param	p_down
	 */
	private function OnKey(p_code : Int, p_down:Bool):Void
	{
		Input.UpdateInputState(p_code, p_down);
	}
	
	/**
	 * Callback for when a touch interaction starts.
	 * @param	p_touch
	 */
	private function OnTouchStart(p_id : Int,p_x:Float,p_y:Float,p_rx:Float=0.0,p_ry:Float=0.0,p_pressure:Float=0.0,p_angle:Float=0.0):Void
	{
		//Console.Log("Input> TouchStart " + p_id);
		var t : Touch = Input.m_api_touches[p_id];			
		t.id 					= p_id;		
		t.position.x 			= p_x;
		t.position.y 			= p_y;
		t.relativePosition.x 	= t.position.x / Screen.width;
		t.relativePosition.y 	= t.position.y / Screen.height;
		t.delta.x 				= 0.0;
		t.delta.y 				= 0.0;
		t.pressure 				= p_pressure;
		t.radius.x 				= p_rx;
		t.radius.y 				= p_ry;
		t.angle    				= p_angle;	
		t.m_down				= true;
		if(Input.m_touches.indexOf(t)<0)Input.m_touches.push(t);
	}
	
	/**
	 * Callback called when a touch updates.
	 * @param	p_id
	 * @param	p_x
	 * @param	p_y
	 */
	private function OnTouchMove(p_id : Int, p_x : Float, p_y:Float):Void
	{
		var t : Touch = Input.m_api_touches[p_id];
		if (t.id >= 0)
		{
			t.delta.x = p_x - t.position.x;
			t.delta.y = p_y - t.position.y;
		}
		t.position.x 			= p_x;
		t.position.y 			= p_y;
		t.relativePosition.x 	= t.position.x / Screen.width;
		t.relativePosition.y 	= t.position.y / Screen.height;
	}
	
	/**
	 * Callback when a touch cancelled.
	 * @param	p_id
	 */
	private function OnTouchCancel(p_id : Int):Void
	{
		var t : Touch = Input.m_api_touches[p_id];
		t.m_down = false;
	}
	
	/**
	 * Callback when a touch ended.
	 * @param	p_id
	 */
	private function OnTouchEnd(p_id : Int):Void
	{
		//Console.Log("Input> TouchEnd " + p_id);
		var t : Touch = Input.m_api_touches[p_id];
		t.m_down = false;
	}
	
	/**
	 * Method called by joystick upon detection.
	 * @param	p_id
	 * @param	p_name
	 */
	private function OnJoystickStart(p_id:Int, p_name:String):Void
	{		
		m_joystick =  null;
		var jk 	: Joystick = Input.m_api_joystick[p_id];
		if (jk == null) return;
		m_joystick = jk;
		if (Input.m_joysticks.indexOf(jk) >= 0) return;
		jk.id   = p_id;
		jk.name = p_name;		
		Input.m_joysticks.push(jk);		
		Joystick.available = Input.m_joysticks.length > 0;
	}
	
	/**
	 * Updates the currently active joystick buttons.
	 * @param	p_id
	 * @param	p_code
	 * @param	p_value
	 */
	private function OnJoystickDataUpdate(p_code:Int, p_value : Float,p_is_analog:Bool):Void
	{
		if (m_joystick == null) return;	
		if (!p_is_analog)
		{
			m_joystick.button[p_code] 	 = p_value;
			m_joystick.state[p_code] 	 = Input.InputStateFSM(m_joystick.state[p_code], m_joystick.button[p_code] >= Joystick.buttonBias);
			if (m_joystick.state[p_code] == InputState.Hold) m_joystick.hold[p_code] += Time.delta;
			if (m_joystick.state[p_code] == InputState.None) m_joystick.hold[p_code]  = 0.0;
		}
		else
		{
			m_joystick.analog[p_code] = p_value;
		}
	}
	
	/**
	 * Updates the joystick and uses analog and buttons data to finish the update.
	 */
	private function OnJoystickAnalogUpdate():Void
	{
		if (m_joystick == null) return;	
		var b0 : Float = Joystick.analogBias[0];
		var b1 : Float = Joystick.analogBias[1];
		var s  : Float = 1.0;
		var v  : Vector3;
		var jk : Joystick = m_joystick;
		
		v = jk.analogLeft;
		v.x = jk.analog  [KeyCode.LeftAnalogueHor];  s = v.x < 0.0 ? -1.0 : 1.0; v.x = Mathf.Clamp01((Mathf.Abs(v.x) - b0) / (b1 - b0));  v.x =  s * Mathf.Floor(v.x * 100.0) * 0.01;
		v.y = jk.analog  [KeyCode.LeftAnalogueVert]; s = v.y < 0.0 ? -1.0 : 1.0; v.y = Mathf.Clamp01((Mathf.Abs(v.y) - b0) / (b1 - b0));  v.y = -s * Mathf.Floor(v.y * 100.0) * 0.01;
		
		v.z = jk.button[KeyCode.LeftAnalogueStick] > 0.5 ? 1.0 : 0.0;
		
		v = jk.analogRight;
		v.x = jk.analog  [KeyCode.RightAnalogueHor];  s = v.x < 0.0 ? -1.0 : 1.0; v.x = Mathf.Clamp01((Mathf.Abs(v.x) - b0) / (b1 - b0)); v.x =  s * Mathf.Floor(v.x * 100.0) * 0.01;
		v.y = jk.analog  [KeyCode.RightAnalogueVert]; s = v.y < 0.0 ? -1.0 : 1.0; v.y = Mathf.Clamp01((Mathf.Abs(v.y) - b0) / (b1 - b0)); v.y = -s * Mathf.Floor(v.y * 100.0) * 0.01;
		v.z = jk.button[KeyCode.RightAnalogueStick] > 0.5 ? 1.0 : 0.0;
		
		jk.triggerLeft  = jk.button[KeyCode.LeftShoulderBottom];  jk.triggerLeft  = Mathf.Clamp01((jk.triggerLeft  - b0) / (b1 - b0));
		jk.triggerRight = jk.button[KeyCode.RightShoulderBottom]; jk.triggerRight = Mathf.Clamp01((jk.triggerRight - b0) / (b1 - b0));		
	}
	
	/**
	 * Callback to handle change in the vibration of joysticks.
	 * @param	p_left
	 * @param	p_right
	 */
	private function RequestJoystickVibration(p_joystick:Joystick):Void { }
	
	/**
	 * Emulates touch events based on mouse. Only the touch with id 0 has updated position, so users can test 2 touch interactions.
	 * The 2nd touch will be centered on screen and the 3rd will be chosen a random location.
	 * @param	p_code
	 * @param	p_id
	 */
	private function EmulateTouch(p_code:Int,p_id:Int):Void
	{		
		if (Input.Down(p_code))
	 	{
			var p : Vector2 = Vector2.temp;		
			switch(p_id)
			{
				case 0: p.Set2(Input.mouse);
				case 1: p.Set(Screen.width * 0.5, Screen.height * 0.5);
				case 2: p.Set(Screen.width * Random.value, Screen.height * Random.value);
			}			
			OnTouchStart(p_id, p.x, p.y);
		}
		if(p_id==0) if (Input.Pressed(p_code)) 	if (Input.deltaMouse.length > 0) OnTouchMove(p_id, Input.mouse.x, Input.mouse.y);
		if (Input.Hit(p_code))		OnTouchEnd(p_id);
	}
}