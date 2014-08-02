package haxor.graphics;


import haxor.core.BaseApplication;
import haxor.graphics.Screen.CursorMode;

/**
 * Flag that indicates the behaviour of the mouse cursor.
 */
enum CursorMode
{
	Show;
	Hide;
	Lock;
}

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
	static public var width(get_width, null):Float;
	static private inline function get_width():Float { return m_width; }
	static private var m_width:Float;
	
	/**
	 * Screen width of the application rendering area.
	 */
	static public var height(get_height, null):Float;
	static inline private function get_height():Float { return m_height; }
	static private var m_height:Float;
	
	/**
	 * Fullscreen flag.
	 */
	static public var fullscreen(get_fullscreen, set_fullscreen):Bool;
	static inline private function get_fullscreen():Bool { return m_fullscreen; }
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
	
	static private var m_application : BaseApplication;
	
	static function Initialize():Void
	{
		m_width  		= 0;
		m_height 		= 0;
		m_fullscreen 	= false;
		m_cursor 		= CursorMode.Show;
		m_application 	= null;
	}
	
	
	
	
}