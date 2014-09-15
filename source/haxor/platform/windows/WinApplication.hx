#if windows
package haxor.platform.windows;
import haxor.platform.Types.Float32;
import haxor.core.Console;
import haxor.graphics.GL;
import cpp.Lib;
import haxe.Timer;
import haxor.core.BaseApplication;


/**
 * Class that defines a base Application for Windows projects.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class WinApplication extends BaseApplication
{
	
	/**
	 * Reference to the window containing the application.
	 */
	public var window(get_window, null):Window;
	private function get_window():Window { return m_window; }
	private var m_window : Window;
	
	
	/**
	 * Creates a new ApplicationWindows.
	 */
	public function new() 
	{
		super();
		m_platform = Platform.Windows;
		
	}
	
	override private function GetContainerWidth():Float32{ return cast window.width;  }
	
	override private function GetContainerHeight():Float32{ return cast window.height; }
	
		
	/**
	 * General Window Message Callback
	 * @param	p_msg
	 * @param	p_wp
	 * @param	p_lp
	 */
	private function OnMessage(p_msg : Int, p_wp : Int, p_lp:Int):Void { }
	
	/**
	 * Handles the change between window mode and fullscreen mode.
	 * @param	v
	 */
	override function OnFullscreenRequest(v:Bool):Bool
	{
		window.fullscreen = v;
		return v;
	}
	
	/**
	 * Handles the requests for pointer locking.
	 * @param	v
	 */
	override function OnPointerLockRequest(v:Bool):Bool 
	{
		if (v)
		{
			window.LockCursor();			
		}
		else
		{
			window.EnableCursor();			
		}
		
		return v;
	}
	
	/**
	 * Handles the requests for enabling/disabling the mouse pointer.
	 * @param	v
	 */
	override function OnPointerVisibilityRequest(v:Bool):Bool 
	{
		if (v) window.EnableCursor(); else window.DisableCursor();
		return v;
	}
	
	
}

#end