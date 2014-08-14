#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_core_BaseApplication
#include <haxor/core/BaseApplication.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
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
#ifndef INCLUDED_haxor_platform_graphics_WinGL
#include <haxor/platform/graphics/WinGL.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_Window
#include <haxor/platform/windows/Window.h>
#endif

HGLRC   hrc;                           // Permanent Rendering Context
HDC     hdc;                           // Private GDI Device Context
PIXELFORMATDESCRIPTOR pfd;			   // pfd Tells Windows How We Want Things To Be
int     pf;

namespace haxor{
namespace platform{
namespace graphics{

Void WinGL_obj::__construct(::haxor::core::BaseApplication p_application)
{
HX_STACK_FRAME("haxor.platform.graphics.WinGL","new",0x140421df,"haxor.platform.graphics.WinGL.new","haxor/platform/graphics/WinGL.hx",49,0xd2011392)
HX_STACK_THIS(this)
HX_STACK_ARG(p_application,"p_application")
{
	HX_STACK_LINE(49)
	super::__construct(p_application);
}
;
	return null();
}

//WinGL_obj::~WinGL_obj() { }

Dynamic WinGL_obj::__CreateEmpty() { return  new WinGL_obj; }
hx::ObjectPtr< WinGL_obj > WinGL_obj::__new(::haxor::core::BaseApplication p_application)
{  hx::ObjectPtr< WinGL_obj > result = new WinGL_obj();
	result->__construct(p_application);
	return result;}

Dynamic WinGL_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WinGL_obj > result = new WinGL_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::platform::windows::Window WinGL_obj::get_window( ){
	HX_STACK_FRAME("haxor.platform.graphics.WinGL","get_window",0x5b86701a,"haxor.platform.graphics.WinGL.get_window","haxor/platform/graphics/WinGL.hx",56,0xd2011392)
	HX_STACK_THIS(this)
	HX_STACK_LINE(56)
	return this->m_window;
}


HX_DEFINE_DYNAMIC_FUNC0(WinGL_obj,get_window,return )

bool WinGL_obj::Initialize( ::haxor::platform::windows::Window p_window){
	HX_STACK_FRAME("haxor.platform.graphics.WinGL","Initialize",0xfbdea1d1,"haxor.platform.graphics.WinGL.Initialize","haxor/platform/graphics/WinGL.hx",63,0xd2011392)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_window,"p_window")
	HX_STACK_LINE(64)
	::String _g = ::Std_obj::string(p_window);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(64)
	::String _g1 = (HX_CSTRING("Graphics> Initialize. hwnd[") + _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(64)
	::String _g2 = (_g1 + HX_CSTRING("]"));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(64)
	::haxor::core::Console_obj::Log(_g2,(int)1);
	HX_STACK_LINE(66)
			
		{
			if (p_window->hwnd == NULL) 
			{ 
				printf("Graphics> Invalid Window Handler."); 
				return false; 
			}
			printf("  Window Handler [0x%x]\n", p_window->hwnd);
			hdc  = GetDC(p_window->hwnd);
			printf("  Device Context [0x%x]\n", hdc);
			if (hdc == NULL) 
			{ 
				printf("Graphics> Could not create Device Context!\n"); 
				return false; 
			}
			
			PIXELFORMATDESCRIPTOR l_pfd =                  
			{
				sizeof(PIXELFORMATDESCRIPTOR),  // Size Of This Pixel Format Descriptor
				1,                              // Version Number
				PFD_DRAW_TO_WINDOW |            // Format Must Support Window
				PFD_SUPPORT_OPENGL |            // Format Must Support OpenGL
				PFD_DOUBLEBUFFER,               // Must Support Double Buffering
				PFD_TYPE_RGBA,                  // Request An RGBA Format
				32,                             // Select Our Color Depth
				0, 0, 0, 0, 0, 0,               // Color Bits Ignored
				0,                              // No Alpha Buffer
				0,                              // Shift Bit Ignored
				0,                              // No Accumulation Buffer
				0, 0, 0, 0,                     // Accumulation Bits Ignored
				16,                             // 16Bit Z-Buffer (Depth Buffer)
				0,                              // No Stencil Buffer
				0,                              // No Auxiliary Buffer
				PFD_MAIN_PLANE,                 // Main Drawing Layer
				0,                              // Reserved
				0, 0, 0                         // Layer Masks Ignored
			};
			
			pf = ChoosePixelFormat(hdc, &l_pfd);
			
			pfd = l_pfd;
			
			if (!pf) 
			{ 
				printf("Graphics> Failed to choose pixel format!\n"); 
				return false; 
			}
			
			printf("  Pixel Format [%d]\n", pf);
			
			if (!SetPixelFormat(hdc, pf, & pfd)) 
			{ 
				printf("Graphics> Failed to set pixel format!\n"); 
				return false;
			}
			
			hrc = wglCreateContext(hdc);
			int  err = GetLastError();
			
			if (!hrc)
			{ 
				printf("Graphics> Failed to create Rendering context !\n"); 				
				return false; 
			}
			
			printf("  Rendering Context [0x%x]\n", hrc);
			
			//Make current to init glew.
			Focus();
			
			//glewExperimental = GL_TRUE;
			GLenum glerr = glewInit();
			if (glerr != GLEW_OK)
			{
				fprintf(stderr, "Graphics> GLEW Error: %s\n", glewGetErrorString(glerr));
				return false;
			}
			
		}
		;
	HX_STACK_LINE(147)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(WinGL_obj,Initialize,return )

Void WinGL_obj::CheckExtensions( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.WinGL","CheckExtensions",0xc139fedb,"haxor.platform.graphics.WinGL.CheckExtensions","haxor/platform/graphics/WinGL.hx",155,0xd2011392)
		HX_STACK_THIS(this)
		HX_STACK_LINE(156)
		
		if (hdc == NULL) return null();
		;
		HX_STACK_LINE(159)
		::haxor::core::Console_obj::Log(HX_CSTRING("Graphics> Available Extensions:"),(int)1);
	}
return null();
}


Void WinGL_obj::Focus( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.WinGL","Focus",0x353dbef7,"haxor.platform.graphics.WinGL.Focus","haxor/platform/graphics/WinGL.hx",167,0xd2011392)
		HX_STACK_THIS(this)
		HX_STACK_LINE(167)
		
		wglMakeCurrent(hdc, hrc);
		;
	}
return null();
}


Void WinGL_obj::Flush( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.WinGL","Flush",0x334fc1e3,"haxor.platform.graphics.WinGL.Flush","haxor/platform/graphics/WinGL.hx",177,0xd2011392)
		HX_STACK_THIS(this)
		HX_STACK_LINE(177)
		
		SwapBuffers(hdc);
		;
	}
return null();
}



WinGL_obj::WinGL_obj()
{
}

void WinGL_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(WinGL);
	HX_MARK_MEMBER_NAME(window,"window");
	HX_MARK_MEMBER_NAME(m_window,"m_window");
	::haxor::platform::graphics::GraphicContext_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void WinGL_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(window,"window");
	HX_VISIT_MEMBER_NAME(m_window,"m_window");
	::haxor::platform::graphics::GraphicContext_obj::__Visit(HX_VISIT_ARG);
}

Dynamic WinGL_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"Focus") ) { return Focus_dyn(); }
		if (HX_FIELD_EQ(inName,"Flush") ) { return Flush_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"window") ) { return inCallProp ? get_window() : window; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_window") ) { return m_window; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_window") ) { return get_window_dyn(); }
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"CheckExtensions") ) { return CheckExtensions_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic WinGL_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"window") ) { window=inValue.Cast< ::haxor::platform::windows::Window >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_window") ) { m_window=inValue.Cast< ::haxor::platform::OSWindow >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void WinGL_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("window"));
	outFields->push(HX_CSTRING("m_window"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::platform::windows::Window*/ ,(int)offsetof(WinGL_obj,window),HX_CSTRING("window")},
	{hx::fsObject /*::haxor::platform::OSWindow*/ ,(int)offsetof(WinGL_obj,m_window),HX_CSTRING("m_window")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("window"),
	HX_CSTRING("get_window"),
	HX_CSTRING("m_window"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("CheckExtensions"),
	HX_CSTRING("Focus"),
	HX_CSTRING("Flush"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(WinGL_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(WinGL_obj::__mClass,"__mClass");
};

#endif

Class WinGL_obj::__mClass;

void WinGL_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.graphics.WinGL"), hx::TCanCast< WinGL_obj> ,sStaticFields,sMemberFields,
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

void WinGL_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace graphics
