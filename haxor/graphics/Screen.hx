package haxor.graphics;


import haxor.core.BaseApplication;
import haxor.graphics.Screen.CursorMode;
import haxor.math.Vector2;
import haxor.platform.Types.Float32;

/**
 * Class that handles screen related data and functionalities.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Screen
{		
	
	/**
	 * Screen width of the application rendering area.
	 */
	static public var width(get_width, null):Float32;
	static private inline function get_width():Float32{ return m_width; }
	static private var m_width:Float32;
	
	/**
	 * Screen width of the application rendering area.
	 */
	static public var height(get_height, null):Float32;
	static private inline function get_height():Float32{ return m_height; }
	static private var m_height:Float32;
	
	/**
	 * Fullscreen flag.
	 */
	static public var fullscreen(get_fullscreen, set_fullscreen):Bool;
	static private inline function get_fullscreen():Bool { return m_fullscreen; }
	static private function set_fullscreen(v:Bool):Bool { m_fullscreen = m_application.OnFullscreenRequest(v); return m_fullscreen; }
	static private var m_fullscreen:Bool;
	
	/**
	 * Cursor mode
	 */
	static public var cursor(get_cursor, set_cursor):CursorMode;
	static private inline function get_cursor():CursorMode { return m_cursor; }
	static private function set_cursor(v:CursorMode):CursorMode 
	{
		if (v == CursorMode.Lock)
		{
			var is_locked : Bool = m_application.OnPointerLockRequest(true);
			if (!is_locked) { return m_cursor = CursorMode.Show; }
			m_application.OnPointerVisibilityRequest(false);
			return m_cursor = CursorMode.Lock;
		}
		m_application.OnPointerLockRequest(false);
		var is_visible : Bool = m_application.OnPointerVisibilityRequest(v == CursorMode.Show);
		return m_cursor = is_visible ? CursorMode.Show : CursorMode.Hide;
	}
	static private var m_cursor:CursorMode;
	
	/**
	 * Reference to the native application.
	 */
	static private var m_application : BaseApplication;
	
	/**
	 * Initializes the Screen class to handle screen and pointer functionalities.
	 * @param	p_application
	 */
	static function Initialize(p_application : BaseApplication):Void
	{
		m_application   = p_application;
		m_width  		= 0;
		m_height 		= 0;
		m_fullscreen 	= false;
		m_cursor 		= CursorMode.Show;
		m_application 	= null;
	}
	
}

/**
 * Flag that indicates the behaviour of the mouse cursor.
 */
enum CursorMode
{
	/**
	 * Shows the cursor.
	 */
	Show;
	
	/**
	 * Hide the cursor.
	 */
	Hide;
	
	/**
	 * Hides the cursor and locks its movement.
	 */
	Lock;
}