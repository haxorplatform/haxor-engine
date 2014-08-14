package haxor.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Screen extends haxe.lang.HxObject
{
	public    Screen(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Screen()
	{
		haxor.graphics.Screen.__hx_ctor_haxor_graphics_Screen(this);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_Screen(haxor.graphics.Screen __temp_me4467)
	{
		{
		}
		
	}
	
	
	public static  double width;
	
	public static   double get_width()
	{
		return haxor.graphics.Screen.m_width;
	}
	
	
	public static  double m_width;
	
	public static  double height;
	
	public static   double get_height()
	{
		return haxor.graphics.Screen.m_height;
	}
	
	
	public static  double m_height;
	
	
	
	public static   boolean get_fullscreen()
	{
		return haxor.graphics.Screen.m_fullscreen;
	}
	
	
	public static   boolean set_fullscreen(boolean v)
	{
		haxor.graphics.Screen.m_fullscreen = haxor.graphics.Screen.m_application.OnFullscreenRequest(v);
		return haxor.graphics.Screen.m_fullscreen;
	}
	
	
	public static  boolean m_fullscreen;
	
	
	
	public static   haxor.graphics.CursorMode get_cursor()
	{
		return haxor.graphics.Screen.m_cursor;
	}
	
	
	public static   haxor.graphics.CursorMode set_cursor(haxor.graphics.CursorMode v)
	{
		if (( v == haxor.graphics.CursorMode.Lock )) 
		{
			boolean is_locked = haxor.graphics.Screen.m_application.OnPointerLockRequest(true);
			if ( ! (is_locked) ) 
			{
				return haxor.graphics.Screen.m_cursor = haxor.graphics.CursorMode.Show;
			}
			
			haxor.graphics.Screen.m_application.OnPointerVisibilityRequest(false);
			return haxor.graphics.Screen.m_cursor = haxor.graphics.CursorMode.Lock;
		}
		
		haxor.graphics.Screen.m_application.OnPointerLockRequest(false);
		boolean is_visible = haxor.graphics.Screen.m_application.OnPointerVisibilityRequest(( v == haxor.graphics.CursorMode.Show ));
		return ( (is_visible) ? (haxor.graphics.Screen.m_cursor = haxor.graphics.CursorMode.Show) : (haxor.graphics.Screen.m_cursor = haxor.graphics.CursorMode.Hide) );
	}
	
	
	public static  haxor.graphics.CursorMode m_cursor;
	
	public static  haxor.core.BaseApplication m_application;
	
	public static   void Initialize()
	{
		haxor.graphics.Screen.m_width = ((double) (0) );
		haxor.graphics.Screen.m_height = ((double) (0) );
		haxor.graphics.Screen.m_fullscreen = false;
		haxor.graphics.Screen.m_cursor = haxor.graphics.CursorMode.Show;
		haxor.graphics.Screen.m_application = null;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.Screen(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.Screen();
	}
	
	
}


