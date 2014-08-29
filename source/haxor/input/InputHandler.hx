package haxor.input;
import haxor.graphics.Screen;
import haxor.thread.Activity;

/**
 * Base class that will handle input updates from every platform.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class InputHandler
{

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
		
		UpdateInput();
		
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
			case 0: { Input.UpdateInputState(KeyCode.Mouse0, p_down);  }
			case 1: { Input.UpdateInputState(KeyCode.Mouse1, p_down);  }
			case 2: { Input.UpdateInputState(KeyCode.Mouse2, p_down);  }
			case 3: { Input.UpdateInputState(KeyCode.Mouse3, p_down);  }
			case 4: { Input.UpdateInputState(KeyCode.Mouse4, p_down);  }					
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
}