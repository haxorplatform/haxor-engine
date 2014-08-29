#if windows

package haxor.platform.windows.input;
import haxor.input.InputHandler;


/**
 * Platform class that handles the input detection and update of the static 'Input' class.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class WinInputHandler extends InputHandler
{
	
	/**
	 * Initializes this input handler with the target DOM element.
	 * @param	p_target
	 */
	private function new():Void
	{
		super();
	}
	
	/**
	 * Handles the input loop if any.
	 */
	override function UpdateInput():Void 
	{
		
	}
	
	
	
	
}

#end