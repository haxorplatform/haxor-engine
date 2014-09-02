package haxor.platform;

/**
 * Base class that describes an OS native window.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class OSWindow
{

	/**
	 * Window X
	 */
	public var x(get_x, set_x):Int;
	private function get_x():Int { return m_x; }
	private function set_x(v:Int):Int { m_x = v; OnResize(); return v; }
	private var m_x : Int;
	private var m_fs_x:Int;
	
	/**
	 * Window Y
	 */
	public var y(get_y, set_y):Int;
	private function get_y():Int { return m_y; }
	private function set_y(v:Int):Int { m_y = v; OnResize(); return v; }
	private var m_y : Int;
	private var m_fs_y:Int;
	
	/**
	 * Window Width
	 */
	public var width(get_width, set_width):Int;
	private function get_width():Int { return m_width; }
	private function set_width(v:Int):Int { m_width = v; OnResize(); return v; }
	private var m_width : Int;
	private var m_fs_width:Int;
	
	/**
	 * Window Height
	 */
	public var height(get_height, set_height):Int;
	private function get_height():Int { return m_height; }
	private function set_height(v:Int):Int { m_height = v; OnResize(); return v; }	
	private var m_height : Int;
	private var m_fs_height:Int;

	
	/**
	 * Window Title
	 */
	public var title(get_title, set_title):String;
	private function get_title():String { return m_title; }
	private function set_title(v:String):String 
	{
		m_title = v;		
		OnTitleChange();		
		return v; 
	}
	private var m_title : String;
	
	/**
	 * Window Focus Flag
	 */
	public var focused(get_focused, null):Bool;
	private function get_focused():Bool { return m_focused; }
	private var m_focused : Bool;
	
	/**
	 * Window Fullscreen Flag
	 */
	public var fullscreen(get_fullscreen, set_fullscreen):Bool;
	private function get_fullscreen():Bool { return m_fullscreen; }
	private function set_fullscreen(v:Bool):Bool { if (m_fullscreen == v) return v; m_fullscreen = v; OnFullscreen(); return v; }
	private var m_fullscreen : Bool;
	
	/**
	 * Window Mouse X
	 */
	public var mouseX(get_mouseX, null):Int;
	private function get_mouseX():Int { return m_mouseX; }
	private var m_mouseX : Int;
	
	/**
	 * Window Mouse Y
	 */
	public var mouseY(get_mouseY, null):Int;
	private function get_mouseY():Int { return m_mouseY; }
	private var m_mouseY : Int;
	
	
	private var m_cursor_lock : Bool;
	private var m_cursor_flag : Int;
	
	/**
	 * Creates a new window
	 * @param	p_title
	 * @param	p_x
	 * @param	p_y
	 * @param	p_width
	 * @param	p_height
	 */
	public function new(p_title:String, p_x:Int, p_y:Int, p_width:Int, p_height:Int) 
	{
		m_x 	 		= p_x;
		m_y      		= p_y;
		m_width  		= p_width;
		m_height 		= p_height;
		m_title  		= p_title;		
		m_focused 		= true;
		m_fullscreen 	= false;
		m_cursor_lock 	= false;
		m_cursor_flag   = 0;
		m_mouseX = 0;
		m_mouseY = 0;
	}
	
	
	/**
	 * Starts the window loop.
	 */
	public function Run():Void { }
	
	/**
	 * Shows the mouse cursor
	 */
	public function EnableCursor():Void { }
	
	/**
	 * Hides the mouse cursor
	 */
	public function DisableCursor():Void { }
	
	/**
	 * Locks the cursor in place.
	 */
	public function LockCursor():Void { m_cursor_lock = true; m_cursor_flag = 0; }
	
	/**
	 * Unlocks the cursor free.
	 */
	public function UnlockCursor():Void { m_cursor_lock = false; }
	
	/**
	 * Callback called when the window suffers resizing.
	 */
	private function OnResize():Void { }
	
	/**
	 * Callback called when the window fullscreen flag changes.
	 */
	private function OnFullscreen():Void { }
	
	/**
	 * Callback called when the title changed.
	 */
	private function OnTitleChange():Void { }
	
	
	
}