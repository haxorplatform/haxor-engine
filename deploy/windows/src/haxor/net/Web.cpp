#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IRenderable
#include <haxor/core/IRenderable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#include <haxor/graphics/texture/Bitmap.h>
#endif
#ifndef INCLUDED_haxor_net_Web
#include <haxor/net/Web.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_BitmapLoader
#include <haxor/platform/windows/BitmapLoader.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_HTTPLoader
#include <haxor/platform/windows/HTTPLoader.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_HTTPRequest
#include <haxor/platform/windows/HTTPRequest.h>
#endif
#ifndef INCLUDED_haxor_thread_Activity
#include <haxor/thread/Activity.h>
#endif
#ifndef INCLUDED_haxor_thread_Task
#include <haxor/thread/Task.h>
#endif
namespace haxor{
namespace net{

Void Web_obj::__construct()
{
	return null();
}

//Web_obj::~Web_obj() { }

Dynamic Web_obj::__CreateEmpty() { return  new Web_obj; }
hx::ObjectPtr< Web_obj > Web_obj::__new()
{  hx::ObjectPtr< Web_obj > result = new Web_obj();
	result->__construct();
	return result;}

Dynamic Web_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Web_obj > result = new Web_obj();
	result->__construct();
	return result;}

::String Web_obj::root;

Void Web_obj::Load( ::String p_url,Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.net.Web","Load",0x1fa4e45d,"haxor.net.Web.Load","haxor/net/Web.hx",35,0x66abd769)
		HX_STACK_ARG(p_url,"p_url")
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(35)
		::haxor::platform::windows::HTTPLoader ld = ::haxor::platform::windows::HTTPLoader_obj::__new(p_url,false,p_callback);		HX_STACK_VAR(ld,"ld");
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Web_obj,Load,(void))

Void Web_obj::LoadImg( ::String p_url,Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.net.Web","LoadImg",0x313237a6,"haxor.net.Web.LoadImg","haxor/net/Web.hx",42,0x66abd769)
		HX_STACK_ARG(p_url,"p_url")
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(42)
		::haxor::platform::windows::BitmapLoader ld = ::haxor::platform::windows::BitmapLoader_obj::__new(p_url,p_callback);		HX_STACK_VAR(ld,"ld");
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Web_obj,LoadImg,(void))


Web_obj::Web_obj()
{
}

Dynamic Web_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"root") ) { return root; }
		if (HX_FIELD_EQ(inName,"Load") ) { return Load_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"LoadImg") ) { return LoadImg_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Web_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"root") ) { root=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Web_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("root"),
	HX_CSTRING("Load"),
	HX_CSTRING("LoadImg"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Web_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Web_obj::root,"root");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Web_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Web_obj::root,"root");
};

#endif

Class Web_obj::__mClass;

void Web_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.net.Web"), hx::TCanCast< Web_obj> ,sStaticFields,sMemberFields,
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

void Web_obj::__boot()
{
	root= HX_CSTRING("");
}

} // end namespace haxor
} // end namespace net
