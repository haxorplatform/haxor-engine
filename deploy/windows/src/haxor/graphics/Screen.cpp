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
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_CursorMode
#include <haxor/graphics/CursorMode.h>
#endif
#ifndef INCLUDED_haxor_graphics_Screen
#include <haxor/graphics/Screen.h>
#endif
namespace haxor{
namespace graphics{

Void Screen_obj::__construct()
{
	return null();
}

//Screen_obj::~Screen_obj() { }

Dynamic Screen_obj::__CreateEmpty() { return  new Screen_obj; }
hx::ObjectPtr< Screen_obj > Screen_obj::__new()
{  hx::ObjectPtr< Screen_obj > result = new Screen_obj();
	result->__construct();
	return result;}

Dynamic Screen_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Screen_obj > result = new Screen_obj();
	result->__construct();
	return result;}

Float Screen_obj::width;

Float Screen_obj::get_width( ){
	HX_STACK_FRAME("haxor.graphics.Screen","get_width",0x9765f0d2,"haxor.graphics.Screen.get_width","haxor/graphics/Screen.hx",19,0x29014c1b)
	HX_STACK_LINE(19)
	return ::haxor::graphics::Screen_obj::m_width;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Screen_obj,get_width,return )

Float Screen_obj::m_width;

Float Screen_obj::height;

Float Screen_obj::get_height( ){
	HX_STACK_FRAME("haxor.graphics.Screen","get_height",0x981c3f9b,"haxor.graphics.Screen.get_height","haxor/graphics/Screen.hx",26,0x29014c1b)
	HX_STACK_LINE(26)
	return ::haxor::graphics::Screen_obj::m_height;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Screen_obj,get_height,return )

Float Screen_obj::m_height;

bool Screen_obj::get_fullscreen( ){
	HX_STACK_FRAME("haxor.graphics.Screen","get_fullscreen",0x658c5bef,"haxor.graphics.Screen.get_fullscreen","haxor/graphics/Screen.hx",33,0x29014c1b)
	HX_STACK_LINE(33)
	return ::haxor::graphics::Screen_obj::m_fullscreen;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Screen_obj,get_fullscreen,return )

bool Screen_obj::set_fullscreen( bool v){
	HX_STACK_FRAME("haxor.graphics.Screen","set_fullscreen",0x85ac4463,"haxor.graphics.Screen.set_fullscreen","haxor/graphics/Screen.hx",34,0x29014c1b)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(34)
	bool _g = ::haxor::graphics::Screen_obj::m_application->OnFullscreenRequest(v);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(34)
	::haxor::graphics::Screen_obj::m_fullscreen = _g;
	HX_STACK_LINE(34)
	return ::haxor::graphics::Screen_obj::m_fullscreen;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Screen_obj,set_fullscreen,return )

bool Screen_obj::m_fullscreen;

::haxor::graphics::CursorMode Screen_obj::get_cursor( ){
	HX_STACK_FRAME("haxor.graphics.Screen","get_cursor",0xd4b8c68a,"haxor.graphics.Screen.get_cursor","haxor/graphics/Screen.hx",41,0x29014c1b)
	HX_STACK_LINE(41)
	return ::haxor::graphics::Screen_obj::m_cursor;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Screen_obj,get_cursor,return )

::haxor::graphics::CursorMode Screen_obj::set_cursor( ::haxor::graphics::CursorMode v){
	HX_STACK_FRAME("haxor.graphics.Screen","set_cursor",0xd83664fe,"haxor.graphics.Screen.set_cursor","haxor/graphics/Screen.hx",43,0x29014c1b)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(44)
	if (((v == ::haxor::graphics::CursorMode_obj::Lock))){
		HX_STACK_LINE(46)
		bool is_locked = ::haxor::graphics::Screen_obj::m_application->OnPointerLockRequest(true);		HX_STACK_VAR(is_locked,"is_locked");
		HX_STACK_LINE(47)
		if ((!(is_locked))){
			HX_STACK_LINE(47)
			return ::haxor::graphics::Screen_obj::m_cursor = ::haxor::graphics::CursorMode_obj::Show;
		}
		HX_STACK_LINE(48)
		::haxor::graphics::Screen_obj::m_application->OnPointerVisibilityRequest(false);
		HX_STACK_LINE(49)
		return ::haxor::graphics::Screen_obj::m_cursor = ::haxor::graphics::CursorMode_obj::Lock;
	}
	HX_STACK_LINE(51)
	::haxor::graphics::Screen_obj::m_application->OnPointerLockRequest(false);
	HX_STACK_LINE(52)
	bool is_visible = ::haxor::graphics::Screen_obj::m_application->OnPointerVisibilityRequest((v == ::haxor::graphics::CursorMode_obj::Show));		HX_STACK_VAR(is_visible,"is_visible");
	HX_STACK_LINE(53)
	return (  ((is_visible)) ? ::haxor::graphics::CursorMode(::haxor::graphics::Screen_obj::m_cursor = ::haxor::graphics::CursorMode_obj::Show) : ::haxor::graphics::CursorMode(::haxor::graphics::Screen_obj::m_cursor = ::haxor::graphics::CursorMode_obj::Hide) );
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Screen_obj,set_cursor,return )

::haxor::graphics::CursorMode Screen_obj::m_cursor;

::haxor::core::BaseApplication Screen_obj::m_application;

Void Screen_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.graphics.Screen","Initialize",0x88b4fd5b,"haxor.graphics.Screen.Initialize","haxor/graphics/Screen.hx",60,0x29014c1b)
		HX_STACK_LINE(61)
		::haxor::graphics::Screen_obj::m_width = (int)0;
		HX_STACK_LINE(62)
		::haxor::graphics::Screen_obj::m_height = (int)0;
		HX_STACK_LINE(63)
		::haxor::graphics::Screen_obj::m_fullscreen = false;
		HX_STACK_LINE(64)
		::haxor::graphics::Screen_obj::m_cursor = ::haxor::graphics::CursorMode_obj::Show;
		HX_STACK_LINE(65)
		::haxor::graphics::Screen_obj::m_application = null();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Screen_obj,Initialize,(void))


Screen_obj::Screen_obj()
{
}

Dynamic Screen_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return inCallProp ? get_width() : width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return inCallProp ? get_height() : height; }
		if (HX_FIELD_EQ(inName,"cursor") ) { return get_cursor(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_width") ) { return m_width; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_height") ) { return m_height; }
		if (HX_FIELD_EQ(inName,"m_cursor") ) { return m_cursor; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"fullscreen") ) { return get_fullscreen(); }
		if (HX_FIELD_EQ(inName,"get_cursor") ) { return get_cursor_dyn(); }
		if (HX_FIELD_EQ(inName,"set_cursor") ) { return set_cursor_dyn(); }
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_fullscreen") ) { return m_fullscreen; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_application") ) { return m_application; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_fullscreen") ) { return get_fullscreen_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fullscreen") ) { return set_fullscreen_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Screen_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cursor") ) { return set_cursor(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_width") ) { m_width=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_height") ) { m_height=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_cursor") ) { m_cursor=inValue.Cast< ::haxor::graphics::CursorMode >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fullscreen") ) { return set_fullscreen(inValue); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_fullscreen") ) { m_fullscreen=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_application") ) { m_application=inValue.Cast< ::haxor::core::BaseApplication >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Screen_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("width"),
	HX_CSTRING("get_width"),
	HX_CSTRING("m_width"),
	HX_CSTRING("height"),
	HX_CSTRING("get_height"),
	HX_CSTRING("m_height"),
	HX_CSTRING("get_fullscreen"),
	HX_CSTRING("set_fullscreen"),
	HX_CSTRING("m_fullscreen"),
	HX_CSTRING("get_cursor"),
	HX_CSTRING("set_cursor"),
	HX_CSTRING("m_cursor"),
	HX_CSTRING("m_application"),
	HX_CSTRING("Initialize"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Screen_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Screen_obj::width,"width");
	HX_MARK_MEMBER_NAME(Screen_obj::m_width,"m_width");
	HX_MARK_MEMBER_NAME(Screen_obj::height,"height");
	HX_MARK_MEMBER_NAME(Screen_obj::m_height,"m_height");
	HX_MARK_MEMBER_NAME(Screen_obj::m_fullscreen,"m_fullscreen");
	HX_MARK_MEMBER_NAME(Screen_obj::m_cursor,"m_cursor");
	HX_MARK_MEMBER_NAME(Screen_obj::m_application,"m_application");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Screen_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Screen_obj::width,"width");
	HX_VISIT_MEMBER_NAME(Screen_obj::m_width,"m_width");
	HX_VISIT_MEMBER_NAME(Screen_obj::height,"height");
	HX_VISIT_MEMBER_NAME(Screen_obj::m_height,"m_height");
	HX_VISIT_MEMBER_NAME(Screen_obj::m_fullscreen,"m_fullscreen");
	HX_VISIT_MEMBER_NAME(Screen_obj::m_cursor,"m_cursor");
	HX_VISIT_MEMBER_NAME(Screen_obj::m_application,"m_application");
};

#endif

Class Screen_obj::__mClass;

void Screen_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.Screen"), hx::TCanCast< Screen_obj> ,sStaticFields,sMemberFields,
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

void Screen_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
