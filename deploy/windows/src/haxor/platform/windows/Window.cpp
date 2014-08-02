#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_core_Application
#include <haxor/core/Application.h>
#endif
#ifndef INCLUDED_haxor_core_BaseApplication
#include <haxor/core/BaseApplication.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_platform_OSWindow
#include <haxor/platform/OSWindow.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GraphicContext
#include <haxor/platform/graphics/GraphicContext.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_Graphics
#include <haxor/platform/graphics/Graphics.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_WinGL
#include <haxor/platform/graphics/WinGL.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_WinApplication
#include <haxor/platform/windows/WinApplication.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_Window
#include <haxor/platform/windows/Window.h>
#endif

HWND hwnd;

namespace haxor{
namespace platform{
namespace windows{



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


Void Window_obj::__construct(::haxor::core::Application p_application,::String p_title,int p_x,int p_y,int p_width,int p_height)
{
HX_STACK_FRAME("haxor.platform.windows.Window","new",0x242ce9bc,"haxor.platform.windows.Window.new","haxor/platform/windows/Window.hx",203,0xdc1fc533)
HX_STACK_THIS(this)
HX_STACK_ARG(p_application,"p_application")
HX_STACK_ARG(p_title,"p_title")
HX_STACK_ARG(p_x,"p_x")
HX_STACK_ARG(p_y,"p_y")
HX_STACK_ARG(p_width,"p_width")
HX_STACK_ARG(p_height,"p_height")
{
	HX_STACK_LINE(204)
	::haxor::platform::windows::Window_obj::m_instance = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(205)
	::haxor::platform::windows::Window_obj::m_application = p_application;
	HX_STACK_LINE(206)
	::haxor::platform::windows::Window_obj::m_application->m_window = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(207)
	::haxor::platform::windows::Window_obj::m_build = false;
	HX_STACK_LINE(209)
	super::__construct(p_title,p_x,p_y,p_width,p_height);
	HX_STACK_LINE(211)
	
		
		
		
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
			printf("Window> Failed to register window.\n"); 
			return null();
		}
		
		hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "HaxeWindow", p_title.__CStr(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, p_width, p_height, NULL, NULL, hInstance, NULL);
		
		if (hwnd == NULL) 
		{ 
			printf("Window> Failed to create window.\n"); 
			return null(); 
		}		
		
		ShowWindow(hwnd, nCmdShow);		
		UpdateWindow(hwnd);
		
		SetWindowPos(hwnd, NULL, m_x, m_y, m_width, m_height, SWP_SHOWWINDOW | SWP_DRAWFRAME);
		
		printf("Window> hwnd[%d]\n",hwnd); 
		
		;
	HX_STACK_LINE(258)
	::haxor::platform::windows::Window_obj::m_application->m_graphics->Initialize(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(259)
	::haxor::platform::windows::Window_obj::m_application->m_graphics->CheckExtensions();
	HX_STACK_LINE(261)
	::haxor::platform::windows::Window_obj::m_build = true;
	HX_STACK_LINE(263)
	if ((::haxor::platform::windows::Window_obj::m_application->Load())){
		HX_STACK_LINE(263)
		::haxor::platform::windows::Window_obj::m_application->LoadComplete();
	}
}
;
	return null();
}

//Window_obj::~Window_obj() { }

Dynamic Window_obj::__CreateEmpty() { return  new Window_obj; }
hx::ObjectPtr< Window_obj > Window_obj::__new(::haxor::core::Application p_application,::String p_title,int p_x,int p_y,int p_width,int p_height)
{  hx::ObjectPtr< Window_obj > result = new Window_obj();
	result->__construct(p_application,p_title,p_x,p_y,p_width,p_height);
	return result;}

Dynamic Window_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Window_obj > result = new Window_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

bool Window_obj::get_border( ){
	HX_STACK_FRAME("haxor.platform.windows.Window","get_border",0xc92ec6d9,"haxor.platform.windows.Window.get_border","haxor/platform/windows/Window.hx",174,0xdc1fc533)
	HX_STACK_THIS(this)
	HX_STACK_LINE(174)
	return this->m_border;
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,get_border,return )

bool Window_obj::set_border( bool v){
	HX_STACK_FRAME("haxor.platform.windows.Window","set_border",0xccac654d,"haxor.platform.windows.Window.set_border","haxor/platform/windows/Window.hx",175,0xdc1fc533)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(175)
	this->m_border = v;
	HX_STACK_LINE(175)
	this->OnStyle();
	HX_STACK_LINE(175)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Window_obj,set_border,return )

Void Window_obj::Run( ){
{
		HX_STACK_FRAME("haxor.platform.windows.Window","Run",0x2417b887,"haxor.platform.windows.Window.Run","haxor/platform/windows/Window.hx",272,0xdc1fc533)
		HX_STACK_THIS(this)
		HX_STACK_LINE(272)
		
			MSG Msg;
			
			while (GetMessage(&Msg, NULL, 0, 0) > 0) 
			{
				DispatchMessage(&Msg); 
			}
		;
	}
return null();
}


Void Window_obj::EnableCursor( ){
{
		HX_STACK_FRAME("haxor.platform.windows.Window","EnableCursor",0x2b081cfd,"haxor.platform.windows.Window.EnableCursor","haxor/platform/windows/Window.hx",286,0xdc1fc533)
		HX_STACK_THIS(this)
		HX_STACK_LINE(286)
		while (ShowCursor(true) < 0);
	}
return null();
}


Void Window_obj::DisableCursor( ){
{
		HX_STACK_FRAME("haxor.platform.windows.Window","DisableCursor",0xd16eff1a,"haxor.platform.windows.Window.DisableCursor","haxor/platform/windows/Window.hx",291,0xdc1fc533)
		HX_STACK_THIS(this)
		HX_STACK_LINE(291)
		while (ShowCursor(false) >= 0);
	}
return null();
}


Void Window_obj::OnResize( ){
{
		HX_STACK_FRAME("haxor.platform.windows.Window","OnResize",0xc03b85b7,"haxor.platform.windows.Window.OnResize","haxor/platform/windows/Window.hx",298,0xdc1fc533)
		HX_STACK_THIS(this)
	}
return null();
}


Void Window_obj::OnStyle( ){
{
		HX_STACK_FRAME("haxor.platform.windows.Window","OnStyle",0x696362ce,"haxor.platform.windows.Window.OnStyle","haxor/platform/windows/Window.hx",307,0xdc1fc533)
		HX_STACK_THIS(this)
		HX_STACK_LINE(307)
		
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
		;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Window_obj,OnStyle,(void))

Void Window_obj::OnTitleChange( ){
{
		HX_STACK_FRAME("haxor.platform.windows.Window","OnTitleChange",0xce59ae85,"haxor.platform.windows.Window.OnTitleChange","haxor/platform/windows/Window.hx",334,0xdc1fc533)
		HX_STACK_THIS(this)
		HX_STACK_LINE(334)
		SetWindowText(hwnd, m_title.__CStr());
	}
return null();
}


Void Window_obj::OnFullscreen( ){
{
		HX_STACK_FRAME("haxor.platform.windows.Window","OnFullscreen",0x1389037e,"haxor.platform.windows.Window.OnFullscreen","haxor/platform/windows/Window.hx",342,0xdc1fc533)
		HX_STACK_THIS(this)
		HX_STACK_LINE(342)
				
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
		;
	}
return null();
}


::haxor::core::Application Window_obj::m_application;

::haxor::platform::windows::Window Window_obj::m_instance;

bool Window_obj::m_build;


Window_obj::Window_obj()
{
}

Dynamic Window_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Run") ) { return Run_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { return get_border(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_build") ) { return m_build; }
		if (HX_FIELD_EQ(inName,"OnStyle") ) { return OnStyle_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_border") ) { return m_border; }
		if (HX_FIELD_EQ(inName,"OnResize") ) { return OnResize_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_instance") ) { return m_instance; }
		if (HX_FIELD_EQ(inName,"get_border") ) { return get_border_dyn(); }
		if (HX_FIELD_EQ(inName,"set_border") ) { return set_border_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"EnableCursor") ) { return EnableCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"OnFullscreen") ) { return OnFullscreen_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_application") ) { return m_application; }
		if (HX_FIELD_EQ(inName,"DisableCursor") ) { return DisableCursor_dyn(); }
		if (HX_FIELD_EQ(inName,"OnTitleChange") ) { return OnTitleChange_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Window_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"border") ) { return set_border(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_build") ) { m_build=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_border") ) { m_border=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_instance") ) { m_instance=inValue.Cast< ::haxor::platform::windows::Window >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_application") ) { m_application=inValue.Cast< ::haxor::core::Application >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Window_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("border"));
	outFields->push(HX_CSTRING("m_border"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_application"),
	HX_CSTRING("m_instance"),
	HX_CSTRING("m_build"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Window_obj,m_border),HX_CSTRING("m_border")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_border"),
	HX_CSTRING("set_border"),
	HX_CSTRING("m_border"),
	HX_CSTRING("Run"),
	HX_CSTRING("EnableCursor"),
	HX_CSTRING("DisableCursor"),
	HX_CSTRING("OnResize"),
	HX_CSTRING("OnStyle"),
	HX_CSTRING("OnTitleChange"),
	HX_CSTRING("OnFullscreen"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Window_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Window_obj::m_application,"m_application");
	HX_MARK_MEMBER_NAME(Window_obj::m_instance,"m_instance");
	HX_MARK_MEMBER_NAME(Window_obj::m_build,"m_build");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Window_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Window_obj::m_application,"m_application");
	HX_VISIT_MEMBER_NAME(Window_obj::m_instance,"m_instance");
	HX_VISIT_MEMBER_NAME(Window_obj::m_build,"m_build");
};

#endif

Class Window_obj::__mClass;

void Window_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.windows.Window"), hx::TCanCast< Window_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void Window_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace windows
