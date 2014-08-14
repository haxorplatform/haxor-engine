#if windows
package haxor.platform.windows;
import haxor.platform.graphics.GL;
import haxor.core.Console;
import haxor.core.Application;
import haxor.graphics.Screen;
import haxor.core.BaseApplication;
import cpp.Lib;
import cpp.NativeArray;
import cpp.Pointer;
import haxor.platform.OSWindow;

@:headerCode('
#include <windows.h>
#include <stdio.h>
#include "gl/glew.h"

')


@:headerClassCode('
#undef RegisterClass
HWND 	hwnd;

static LRESULT CALLBACK WndProc(HWND p_hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
')


@:cppFileCode('
HWND hwnd;
')

@:cppNamespaceCode('

int k = 0;

LRESULT CALLBACK haxor::platform::windows::Window_obj::WndProc(HWND p_hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
	m_application->OnMessage(msg,wParam,lParam);
	
	RECT * wr; 
	
	
	
    switch(msg)
    {
		case WM_CREATE:
			{
				
			}
			break;
		case WM_PAINT:
			{			
				POINT mp;
				GetCursorPos( & mp);
				ScreenToClient(p_hwnd, & mp);			
				if (m_instance-> m_cursor_lock)
				{				
					POINT lp; lp.x = 300; lp.y = 300;
					if (m_instance-> m_cursor_flag == 0) SetCursorPos(lp.x, lp.y);								
					ScreenToClient(p_hwnd, &lp);
					if (m_instance-> m_cursor_flag == 0)
					{
						mp.x = lp.x;
						mp.y = lp.y;
					}												
					m_instance-> m_cursor_flag = (m_instance-> m_cursor_flag + 1) % 5;
				}			
				m_instance-> m_mouseX = mp.x;
				m_instance-> m_mouseY = mp.y;
									
				if (m_build)m_application->Update();
				if (m_build)m_application->Render();
				
				return true;
			}
			
		case WM_SETFOCUS:
			m_instance->m_focused = true;
			if (m_build)m_application->OnFocus();
			break;
			
		case WM_KILLFOCUS:
			m_instance->m_focused = false;
			if (m_build)m_application->OnUnfocus();
			break;
			
		case WM_MOUSEMOVE:
			{
				POINT mp;
				GetCursorPos(&mp);
				//SetCursorPos(300, 300);		
			}
			break;
			
		case WM_KEYDOWN:
			
			if (wParam == VK_SPACE)
			{
				//bool b = m_instance-> get_fullscreen();
				//m_instance->set_fullscreen(!b);
				
				m_instance-> m_cursor_lock = !m_instance-> m_cursor_lock;
				
			}
			
			break;
		
		case WM_MOVING:
			{
				
				wr = (RECT * ) lParam;
				m_instance-> m_x 	  = wr->left;			
				m_instance-> m_y 	  = wr->top;
				
			}			
			break;
			
		case WM_SIZE:
			{
				//if (m_application->m_build)
				//{
				int fwSizeType    = wParam; 
				if(fwSizeType == SIZE_MINIMIZED) break;					
				m_instance-> m_width  = LOWORD(lParam); 
				m_instance-> m_height = HIWORD(lParam);				
				m_instance-> OnResize();
				//}
				
			}			
			break;
			
		case WM_SIZING:
			{
				
				wr = (RECT * ) lParam;
				m_instance-> m_x 	  = wr->left;			
				m_instance-> m_y 	  = wr->top;
				m_instance-> m_width  = wr->right - wr->left;
				m_instance-> m_height = wr->bottom - wr->top;
				m_instance-> OnResize();
				
			}
			break;
        
		case WM_CLOSE:			
            DestroyWindow(p_hwnd);
        break;
		
		case WM_DESTROY:		
			m_application->OnQuit();
            PostQuitMessage(0);			
        break;
		
    }
    return DefWindowProc(p_hwnd, msg, wParam, lParam);
}

')


/**
 * Defines a native window instance of windows.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Window extends OSWindow
{
	
	/**
	 * Window Border Flag
	 */
	public var border(get_border, set_border):Bool;
	private function get_border():Bool { return m_border; }
	private function set_border(v:Bool):Bool { m_border = v; OnStyle(); return v; }
	private var m_border : Bool;
		
	
	/**
	 * Reference to the main application.
	 */
	static private var m_application : Application;
	
	/**
	 * Reference to the created window
	 */
	static private var m_instance : Window;
	
	/**
	 * Flag that indicates that the application was built.
	 */
	static private var m_build : Bool;
	
	/**
	 * Creates a new window.
	 * @param	p_title
	 * @param	p_x
	 * @param	p_y
	 * @param	p_width
	 * @param	p_height
	 */
	public function new(p_application : Application,p_title:String,p_x:Int,p_y:Int,p_width:Int,p_height:Int) 
	{
		m_instance 				= this;		
		m_application 			= p_application;
		m_application.m_window 	= this;
		m_build					= false;
		
		super(p_title, p_x, p_y, p_width, p_height);
		
		untyped __cpp__
		('
		
		
		
		HINSTANCE hInstance 		= GetModuleHandle(NULL);
		HINSTANCE hPrevInstance		= NULL;
		LPSTR lpCmdLine 			= GetCommandLine();
		int nCmdShow 				= SW_SHOWNORMAL;		
		
		WNDCLASSEX wc;
		wc.cbSize        = sizeof(WNDCLASSEX);
		wc.style         = 0;
		wc.lpfnWndProc   = WndProc;
		wc.cbClsExtra    = 0;
		wc.cbWndExtra    = 0;
		wc.hInstance     = hInstance;
		wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
		wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
		wc.lpszMenuName  = NULL;
		wc.lpszClassName = "HaxeWindow";
		wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
		
		if (!RegisterClassEx( & wc)) 
		{ 
			printf("Window> Failed to register window.\\n"); 
			return null();
		}
		
		hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "HaxeWindow", p_title.__CStr(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, p_width, p_height, NULL, NULL, hInstance, NULL);
		
		if (hwnd == NULL) 
		{ 
			printf("Window> Failed to create window.\\n"); 
			return null(); 
		}		
		
		ShowWindow(hwnd, nCmdShow);		
		UpdateWindow(hwnd);
		
		SetWindowPos(hwnd, NULL, m_x, m_y, m_width, m_height, SWP_SHOWWINDOW | SWP_DRAWFRAME);
		
		printf("Window> hwnd[%d]\\n",hwnd); 
		
		');		
		m_build = true;
	}
	
	/**
	 * Starts the message loop.
	 */
	override public function Run():Void
	{
		untyped __cpp__
		('
			MSG Msg;
			
			while (GetMessage(&Msg, NULL, 0, 0) > 0) 
			{
				DispatchMessage(&Msg); 
			}
		');
	}
	
	/**
	 * Shows the mouse cursor
	 */
	override public function EnableCursor():Void { untyped __cpp__('while (ShowCursor(true) < 0)');	}
	
	/**
	 * Hides the mouse cursor
	 */
	override public function DisableCursor():Void { untyped __cpp__('while (ShowCursor(false) >= 0)');	}
	
	
	/**
	 * Callback for changes in window size and position.
	 */
	override private function OnResize():Void
	{	
		
	}
	
	/**
	 * Callback for window style changes
	 */
	private function OnStyle():Void
	{
		untyped __cpp__
		('
			LONG lStyle = GetWindowLong(hwnd, GWL_STYLE);
			if (!m_border) lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_SYSMENU);
			else lStyle |= (WS_CAPTION  | WS_THICKFRAME | WS_SYSMENU);			
			SetWindowLong(hwnd, GWL_STYLE, lStyle);
			
			LONG lExStyle = GetWindowLong(hwnd, GWL_EXSTYLE);
			if (!m_border)
			{
				lExStyle &= ~(WS_EX_DLGMODALFRAME | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);
			}
			else
			{
				lExStyle |= (WS_EX_DLGMODALFRAME | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);
			}
			SetWindowLong(hwnd, GWL_EXSTYLE, lExStyle);
		');
		
		
	}
	
	/**
	 * Callback called when the title changes.
	 */
	override function OnTitleChange():Void 
	{
		untyped __cpp__('SetWindowText(hwnd, m_title.__CStr())');
	}
	
	/**
	 * Callback for when window enters/leave fullscreen mode.
	 */
	override function OnFullscreen():Void 	
	{
		untyped __cpp__
		('		
			if (m_fullscreen)
			{
				set_border(false);
				HWND desktop = GetDesktopWindow(); 
				RECT dr;
				GetWindowRect(desktop, & dr);
				m_fs_x 		= m_x;
				m_fs_y 	    = m_y;
				m_fs_width  = m_width;
				m_fs_height = m_height;
				SetWindowPos(hwnd, NULL, dr.left, dr.top, dr.right - dr.left, dr.bottom - dr.top, SWP_SHOWWINDOW | SWP_DRAWFRAME);
				m_application->OnFullscreenEnter();
			}
			else
			{				
				m_x 		= m_fs_x;
				m_y 	    = m_fs_y;
				m_width  	= m_fs_width;
				m_height 	= m_fs_height;
				SetWindowPos(hwnd,NULL,m_x,m_y,m_width,m_height,SWP_SHOWWINDOW | SWP_DRAWFRAME);
				set_border(true);
				m_application->OnFullscreenExit();
			}
		');
	}
	
}
#end