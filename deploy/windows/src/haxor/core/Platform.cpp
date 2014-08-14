#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_Platform
#include <haxor/core/Platform.h>
#endif
namespace haxor{
namespace core{

::haxor::core::Platform Platform_obj::Android;

::haxor::core::Platform Platform_obj::HTML;

::haxor::core::Platform Platform_obj::Linux;

::haxor::core::Platform Platform_obj::MacOS;

::haxor::core::Platform Platform_obj::NodeJS;

::haxor::core::Platform Platform_obj::Unknown;

::haxor::core::Platform Platform_obj::Windows;

::haxor::core::Platform Platform_obj::iOS;

HX_DEFINE_CREATE_ENUM(Platform_obj)

int Platform_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("Android")) return 3;
	if (inName==HX_CSTRING("HTML")) return 6;
	if (inName==HX_CSTRING("Linux")) return 2;
	if (inName==HX_CSTRING("MacOS")) return 4;
	if (inName==HX_CSTRING("NodeJS")) return 7;
	if (inName==HX_CSTRING("Unknown")) return 0;
	if (inName==HX_CSTRING("Windows")) return 1;
	if (inName==HX_CSTRING("iOS")) return 5;
	return super::__FindIndex(inName);
}

int Platform_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("Android")) return 0;
	if (inName==HX_CSTRING("HTML")) return 0;
	if (inName==HX_CSTRING("Linux")) return 0;
	if (inName==HX_CSTRING("MacOS")) return 0;
	if (inName==HX_CSTRING("NodeJS")) return 0;
	if (inName==HX_CSTRING("Unknown")) return 0;
	if (inName==HX_CSTRING("Windows")) return 0;
	if (inName==HX_CSTRING("iOS")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Platform_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("Android")) return Android;
	if (inName==HX_CSTRING("HTML")) return HTML;
	if (inName==HX_CSTRING("Linux")) return Linux;
	if (inName==HX_CSTRING("MacOS")) return MacOS;
	if (inName==HX_CSTRING("NodeJS")) return NodeJS;
	if (inName==HX_CSTRING("Unknown")) return Unknown;
	if (inName==HX_CSTRING("Windows")) return Windows;
	if (inName==HX_CSTRING("iOS")) return iOS;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Unknown"),
	HX_CSTRING("Windows"),
	HX_CSTRING("Linux"),
	HX_CSTRING("Android"),
	HX_CSTRING("MacOS"),
	HX_CSTRING("iOS"),
	HX_CSTRING("HTML"),
	HX_CSTRING("NodeJS"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Platform_obj::Android,"Android");
	HX_MARK_MEMBER_NAME(Platform_obj::HTML,"HTML");
	HX_MARK_MEMBER_NAME(Platform_obj::Linux,"Linux");
	HX_MARK_MEMBER_NAME(Platform_obj::MacOS,"MacOS");
	HX_MARK_MEMBER_NAME(Platform_obj::NodeJS,"NodeJS");
	HX_MARK_MEMBER_NAME(Platform_obj::Unknown,"Unknown");
	HX_MARK_MEMBER_NAME(Platform_obj::Windows,"Windows");
	HX_MARK_MEMBER_NAME(Platform_obj::iOS,"iOS");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Platform_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Platform_obj::Android,"Android");
	HX_VISIT_MEMBER_NAME(Platform_obj::HTML,"HTML");
	HX_VISIT_MEMBER_NAME(Platform_obj::Linux,"Linux");
	HX_VISIT_MEMBER_NAME(Platform_obj::MacOS,"MacOS");
	HX_VISIT_MEMBER_NAME(Platform_obj::NodeJS,"NodeJS");
	HX_VISIT_MEMBER_NAME(Platform_obj::Unknown,"Unknown");
	HX_VISIT_MEMBER_NAME(Platform_obj::Windows,"Windows");
	HX_VISIT_MEMBER_NAME(Platform_obj::iOS,"iOS");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class Platform_obj::__mClass;

Dynamic __Create_Platform_obj() { return new Platform_obj; }

void Platform_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.Platform"), hx::TCanCast< Platform_obj >,sStaticFields,sMemberFields,
	&__Create_Platform_obj, &__Create,
	&super::__SGetClass(), &CreatePlatform_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void Platform_obj::__boot()
{
hx::Static(Android) = hx::CreateEnum< Platform_obj >(HX_CSTRING("Android"),3);
hx::Static(HTML) = hx::CreateEnum< Platform_obj >(HX_CSTRING("HTML"),6);
hx::Static(Linux) = hx::CreateEnum< Platform_obj >(HX_CSTRING("Linux"),2);
hx::Static(MacOS) = hx::CreateEnum< Platform_obj >(HX_CSTRING("MacOS"),4);
hx::Static(NodeJS) = hx::CreateEnum< Platform_obj >(HX_CSTRING("NodeJS"),7);
hx::Static(Unknown) = hx::CreateEnum< Platform_obj >(HX_CSTRING("Unknown"),0);
hx::Static(Windows) = hx::CreateEnum< Platform_obj >(HX_CSTRING("Windows"),1);
hx::Static(iOS) = hx::CreateEnum< Platform_obj >(HX_CSTRING("iOS"),5);
}


} // end namespace haxor
} // end namespace core
