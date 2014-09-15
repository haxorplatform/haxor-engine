#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_core_BaseApplication
#include <haxor/core/BaseApplication.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Platform
#include <haxor/core/Platform.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_platform_OSWindow
#include <haxor/platform/OSWindow.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_WinApplication
#include <haxor/platform/windows/WinApplication.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_Window
#include <haxor/platform/windows/Window.h>
#endif
namespace haxor{
namespace platform{
namespace windows{

Void WinApplication_obj::__construct()
{
HX_STACK_FRAME("haxor.platform.windows.WinApplication","new",0xe4507a60,"haxor.platform.windows.WinApplication.new","haxor/platform/windows/WinApplication.hx",31,0x94d4ac0f)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(32)
	super::__construct(null());
	HX_STACK_LINE(33)
	this->m_platform = ::haxor::core::Platform_obj::Windows;
}
;
	return null();
}

//WinApplication_obj::~WinApplication_obj() { }

Dynamic WinApplication_obj::__CreateEmpty() { return  new WinApplication_obj; }
hx::ObjectPtr< WinApplication_obj > WinApplication_obj::__new()
{  hx::ObjectPtr< WinApplication_obj > result = new WinApplication_obj();
	result->__construct();
	return result;}

Dynamic WinApplication_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WinApplication_obj > result = new WinApplication_obj();
	result->__construct();
	return result;}

::haxor::platform::windows::Window WinApplication_obj::get_window( ){
	HX_STACK_FRAME("haxor.platform.windows.WinApplication","get_window",0x966099b9,"haxor.platform.windows.WinApplication.get_window","haxor/platform/windows/WinApplication.hx",23,0x94d4ac0f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(23)
	return this->m_window;
}


HX_DEFINE_DYNAMIC_FUNC0(WinApplication_obj,get_window,return )

Float WinApplication_obj::GetContainerWidth( ){
	HX_STACK_FRAME("haxor.platform.windows.WinApplication","GetContainerWidth",0x0cb29e1b,"haxor.platform.windows.WinApplication.GetContainerWidth","haxor/platform/windows/WinApplication.hx",37,0x94d4ac0f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(37)
	return this->get_window()->get_width();
}


Float WinApplication_obj::GetContainerHeight( ){
	HX_STACK_FRAME("haxor.platform.windows.WinApplication","GetContainerHeight",0xc5e73232,"haxor.platform.windows.WinApplication.GetContainerHeight","haxor/platform/windows/WinApplication.hx",39,0x94d4ac0f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(39)
	return this->get_window()->get_height();
}


Void WinApplication_obj::OnMessage( int p_msg,int p_wp,int p_lp){
{
		HX_STACK_FRAME("haxor.platform.windows.WinApplication","OnMessage",0x5d66f848,"haxor.platform.windows.WinApplication.OnMessage","haxor/platform/windows/WinApplication.hx",48,0x94d4ac0f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_msg,"p_msg")
		HX_STACK_ARG(p_wp,"p_wp")
		HX_STACK_ARG(p_lp,"p_lp")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(WinApplication_obj,OnMessage,(void))

bool WinApplication_obj::OnFullscreenRequest( bool v){
	HX_STACK_FRAME("haxor.platform.windows.WinApplication","OnFullscreenRequest",0xb00da815,"haxor.platform.windows.WinApplication.OnFullscreenRequest","haxor/platform/windows/WinApplication.hx",55,0x94d4ac0f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(56)
	this->get_window()->set_fullscreen(v);
	HX_STACK_LINE(57)
	return v;
}


bool WinApplication_obj::OnPointerLockRequest( bool v){
	HX_STACK_FRAME("haxor.platform.windows.WinApplication","OnPointerLockRequest",0x71f71006,"haxor.platform.windows.WinApplication.OnPointerLockRequest","haxor/platform/windows/WinApplication.hx",65,0x94d4ac0f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(66)
	if ((v)){
		HX_STACK_LINE(68)
		this->get_window()->LockCursor();
	}
	else{
		HX_STACK_LINE(72)
		this->get_window()->EnableCursor();
	}
	HX_STACK_LINE(75)
	return v;
}


bool WinApplication_obj::OnPointerVisibilityRequest( bool v){
	HX_STACK_FRAME("haxor.platform.windows.WinApplication","OnPointerVisibilityRequest",0x1b884e7f,"haxor.platform.windows.WinApplication.OnPointerVisibilityRequest","haxor/platform/windows/WinApplication.hx",83,0x94d4ac0f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(84)
	if ((v)){
		HX_STACK_LINE(84)
		this->get_window()->EnableCursor();
	}
	else{
		HX_STACK_LINE(84)
		this->get_window()->DisableCursor();
	}
	HX_STACK_LINE(85)
	return v;
}



WinApplication_obj::WinApplication_obj()
{
}

void WinApplication_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(WinApplication);
	HX_MARK_MEMBER_NAME(window,"window");
	HX_MARK_MEMBER_NAME(m_window,"m_window");
	::haxor::core::BaseApplication_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void WinApplication_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(window,"window");
	HX_VISIT_MEMBER_NAME(m_window,"m_window");
	::haxor::core::BaseApplication_obj::__Visit(HX_VISIT_ARG);
}

Dynamic WinApplication_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"window") ) { return inCallProp ? get_window() : window; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_window") ) { return m_window; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"OnMessage") ) { return OnMessage_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_window") ) { return get_window_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"GetContainerWidth") ) { return GetContainerWidth_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"GetContainerHeight") ) { return GetContainerHeight_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"OnFullscreenRequest") ) { return OnFullscreenRequest_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"OnPointerLockRequest") ) { return OnPointerLockRequest_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"OnPointerVisibilityRequest") ) { return OnPointerVisibilityRequest_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic WinApplication_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"window") ) { window=inValue.Cast< ::haxor::platform::windows::Window >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_window") ) { m_window=inValue.Cast< ::haxor::platform::windows::Window >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void WinApplication_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("window"));
	outFields->push(HX_CSTRING("m_window"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::platform::windows::Window*/ ,(int)offsetof(WinApplication_obj,window),HX_CSTRING("window")},
	{hx::fsObject /*::haxor::platform::windows::Window*/ ,(int)offsetof(WinApplication_obj,m_window),HX_CSTRING("m_window")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("window"),
	HX_CSTRING("get_window"),
	HX_CSTRING("m_window"),
	HX_CSTRING("GetContainerWidth"),
	HX_CSTRING("GetContainerHeight"),
	HX_CSTRING("OnMessage"),
	HX_CSTRING("OnFullscreenRequest"),
	HX_CSTRING("OnPointerLockRequest"),
	HX_CSTRING("OnPointerVisibilityRequest"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(WinApplication_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(WinApplication_obj::__mClass,"__mClass");
};

#endif

Class WinApplication_obj::__mClass;

void WinApplication_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.windows.WinApplication"), hx::TCanCast< WinApplication_obj> ,sStaticFields,sMemberFields,
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

void WinApplication_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace windows
