#if windows

package haxor.platform.windows.input;
import haxor.platform.Types.Float32;
import haxor.graphics.Screen;
import haxor.math.Vector2;
import haxor.input.KeyCode;
import haxor.input.Joystick;
import haxor.input.Input;
import haxor.input.InputHandler;

@:headerCode('
#include <Windows.h>
#include <Xinput.h>
')

@:headerClassCode('
#undef RegisterClass
')

/**
 * Platform class that handles the input detection and update of the static 'Input' class.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class WinInputHandler extends InputHandler
{
	/**
	 * Max joysticks to detect.
	 */
	private var m_max_joystick : Int;
		
	/**
	 * Initializes this input handler with the target DOM element.
	 * @param	p_target
	 */
	private function new():Void
	{		
		super();
		var max_jk : Int = 0;
		untyped __cpp__('max_jk = 4;');
		m_max_joystick = max_jk;
	
		CheckJoysticks();		
	}
	
	/**
	 * Handles the input loop if any.
	 */
	override function UpdateInput():Void 
	{		
		UpdateJoysticks();		
	}
	
	/**
	 * Loop through the API joysticks and updates their data.
	 */
	private function UpdateJoysticks():Void
	{
		var alx :Float32= 0.0;
		var aly :Float32= 0.0;
		var arx :Float32= 0.0;
		var ary :Float32= 0.0;
		var tl  :Float32= 0.0;
		var tr  :Float32= 0.0;
		
		for (i in 0...Input.m_joysticks.length)
		{
			var jk : Joystick = Input.m_joysticks[i];
			OnJoystickStart(jk.id, jk.name);
			var cid : Int = jk.id;
			untyped __cpp__('			
			XINPUT_STATE state;
			ZeroMemory( & state, sizeof(XINPUT_STATE));
			//Check if device is connected.
			if (XInputGetState(cid, &state) != ERROR_SUCCESS) continue;
			alx = ((float)state.Gamepad.sThumbLX)  / 32767.0;
			aly = ((float)state.Gamepad.sThumbLY)  / 32767.0;			
			arx = ((float)state.Gamepad.sThumbRX)  / 32767.0;
			ary = ((float)state.Gamepad.sThumbRY)  / 32767.0;						 
			tl = ((float)state.Gamepad.bLeftTrigger)  / 255.0;
			tr = ((float) state.Gamepad.bRightTrigger) / 255.0;						
			');
			
			var buttons : Array<Int> = [
			0x1000,  //XINPUT_GAMEPAD_A
			0x2000,  //XINPUT_GAMEPAD_B
			0x4000,  //XINPUT_GAMEPAD_X
			0x8000,  //XINPUT_GAMEPAD_Y
			0x0100,  //XINPUT_GAMEPAD_LEFT_SHOULDER   
			0x0200,  //XINPUT_GAMEPAD_RIGHT_SHOULDER
			-1,		 
			-1,
			0x0020,  //XINPUT_GAMEPAD_BACK			 
			0x0010,  //XINPUT_GAMEPAD_START			 
			0x0040,  //XINPUT_GAMEPAD_LEFT_THUMB		 
			0x0080,  //XINPUT_GAMEPAD_RIGHT_THUMB	 
			0x0001,  //XINPUT_GAMEPAD_DPAD_UP		 
			0x0002,  //XINPUT_GAMEPAD_DPAD_DOWN		 
			0x0004,  //XINPUT_GAMEPAD_DPAD_LEFT		 
			0x0008   //XINPUT_GAMEPAD_DPAD_RIGHT		 
			];
			
			for (i in 0...buttons.length)
			{
				var v 	 : Float32 = 0.0;
				var code : Int   = buttons[i];
				if (i == KeyCode.LeftShoulderBottom)  v = tl; else
				if (i == KeyCode.RightShoulderBottom) v = tr; else
				{
					untyped __cpp__('
					v = (state.Gamepad.wButtons & code) != 0 ? 1.0 : 0.0;
					');
				}
				
				OnJoystickDataUpdate(i, v, false);
			}			
			var axes : Array<Float32> = [alx, -aly, arx, -ary];			
			for (i in 0...axes.length) OnJoystickDataUpdate(i, axes[i], true);			
			OnJoystickAnalogUpdate();			
		}
	}
	
	/**
	 * Calls the XInput API to activate the joystick vibration.
	 * @param	p_joystick
	 */
	override function RequestJoystickVibration(p_joystick:Joystick):Void 
	{
		var cid : Int = p_joystick.id;
		var lv	: Int = cast(p_joystick.m_vibrationLeft * 65535.0);
		var rv	: Int = cast(p_joystick.m_vibrationRight * 65535.0);		
		untyped __cpp__('
		XINPUT_VIBRATION vibration;
		ZeroMemory( &vibration, sizeof(XINPUT_VIBRATION) );
		vibration.wLeftMotorSpeed  = lv; // use any value between 0-65535 here
		vibration.wRightMotorSpeed = rv; // use any value between 0-65535 here
		XInputSetState(cid, & vibration );
		');
	}
	
	/**
	 * Detects the devices connected.
	 */
	private function CheckJoysticks():Void
	{
		var cid : Int = -1;
		for (i in 0...m_max_joystick)
		{
			untyped __cpp__('		
			XINPUT_STATE state;
			ZeroMemory(&state, sizeof(XINPUT_STATE));		 
			if (XInputGetState(i, &state) == ERROR_SUCCESS)	cid = i;	 		
			');
			if (cid >= 0 )
			{
				OnJoystickStart(cid, "Joystick" + cid);
			}
		}
		
	}
	
	
}

#end