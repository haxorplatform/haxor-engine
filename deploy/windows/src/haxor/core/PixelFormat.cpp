#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_PixelFormat
#include <haxor/core/PixelFormat.h>
#endif
namespace haxor{
namespace core{

::haxor::core::PixelFormat PixelFormat_obj::Alpha8;

::haxor::core::PixelFormat PixelFormat_obj::Depth;

::haxor::core::PixelFormat PixelFormat_obj::_Float;

::haxor::core::PixelFormat PixelFormat_obj::Float3;

::haxor::core::PixelFormat PixelFormat_obj::Float4;

::haxor::core::PixelFormat PixelFormat_obj::Half;

::haxor::core::PixelFormat PixelFormat_obj::Half3;

::haxor::core::PixelFormat PixelFormat_obj::Half4;

::haxor::core::PixelFormat PixelFormat_obj::Luminance;

::haxor::core::PixelFormat PixelFormat_obj::RGB8;

::haxor::core::PixelFormat PixelFormat_obj::RGBA8;

HX_DEFINE_CREATE_ENUM(PixelFormat_obj)

int PixelFormat_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("Alpha8")) return 0;
	if (inName==HX_CSTRING("Depth")) return 10;
	if (inName==HX_CSTRING("Float")) return 7;
	if (inName==HX_CSTRING("Float3")) return 8;
	if (inName==HX_CSTRING("Float4")) return 9;
	if (inName==HX_CSTRING("Half")) return 4;
	if (inName==HX_CSTRING("Half3")) return 5;
	if (inName==HX_CSTRING("Half4")) return 6;
	if (inName==HX_CSTRING("Luminance")) return 1;
	if (inName==HX_CSTRING("RGB8")) return 2;
	if (inName==HX_CSTRING("RGBA8")) return 3;
	return super::__FindIndex(inName);
}

int PixelFormat_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("Alpha8")) return 0;
	if (inName==HX_CSTRING("Depth")) return 0;
	if (inName==HX_CSTRING("Float")) return 0;
	if (inName==HX_CSTRING("Float3")) return 0;
	if (inName==HX_CSTRING("Float4")) return 0;
	if (inName==HX_CSTRING("Half")) return 0;
	if (inName==HX_CSTRING("Half3")) return 0;
	if (inName==HX_CSTRING("Half4")) return 0;
	if (inName==HX_CSTRING("Luminance")) return 0;
	if (inName==HX_CSTRING("RGB8")) return 0;
	if (inName==HX_CSTRING("RGBA8")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic PixelFormat_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("Alpha8")) return Alpha8;
	if (inName==HX_CSTRING("Depth")) return Depth;
	if (inName==HX_CSTRING("Float")) return _Float;
	if (inName==HX_CSTRING("Float3")) return Float3;
	if (inName==HX_CSTRING("Float4")) return Float4;
	if (inName==HX_CSTRING("Half")) return Half;
	if (inName==HX_CSTRING("Half3")) return Half3;
	if (inName==HX_CSTRING("Half4")) return Half4;
	if (inName==HX_CSTRING("Luminance")) return Luminance;
	if (inName==HX_CSTRING("RGB8")) return RGB8;
	if (inName==HX_CSTRING("RGBA8")) return RGBA8;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Alpha8"),
	HX_CSTRING("Luminance"),
	HX_CSTRING("RGB8"),
	HX_CSTRING("RGBA8"),
	HX_CSTRING("Half"),
	HX_CSTRING("Half3"),
	HX_CSTRING("Half4"),
	HX_CSTRING("Float"),
	HX_CSTRING("Float3"),
	HX_CSTRING("Float4"),
	HX_CSTRING("Depth"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PixelFormat_obj::Alpha8,"Alpha8");
	HX_MARK_MEMBER_NAME(PixelFormat_obj::Depth,"Depth");
	HX_MARK_MEMBER_NAME(PixelFormat_obj::_Float,"_Float");
	HX_MARK_MEMBER_NAME(PixelFormat_obj::Float3,"Float3");
	HX_MARK_MEMBER_NAME(PixelFormat_obj::Float4,"Float4");
	HX_MARK_MEMBER_NAME(PixelFormat_obj::Half,"Half");
	HX_MARK_MEMBER_NAME(PixelFormat_obj::Half3,"Half3");
	HX_MARK_MEMBER_NAME(PixelFormat_obj::Half4,"Half4");
	HX_MARK_MEMBER_NAME(PixelFormat_obj::Luminance,"Luminance");
	HX_MARK_MEMBER_NAME(PixelFormat_obj::RGB8,"RGB8");
	HX_MARK_MEMBER_NAME(PixelFormat_obj::RGBA8,"RGBA8");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PixelFormat_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PixelFormat_obj::Alpha8,"Alpha8");
	HX_VISIT_MEMBER_NAME(PixelFormat_obj::Depth,"Depth");
	HX_VISIT_MEMBER_NAME(PixelFormat_obj::_Float,"_Float");
	HX_VISIT_MEMBER_NAME(PixelFormat_obj::Float3,"Float3");
	HX_VISIT_MEMBER_NAME(PixelFormat_obj::Float4,"Float4");
	HX_VISIT_MEMBER_NAME(PixelFormat_obj::Half,"Half");
	HX_VISIT_MEMBER_NAME(PixelFormat_obj::Half3,"Half3");
	HX_VISIT_MEMBER_NAME(PixelFormat_obj::Half4,"Half4");
	HX_VISIT_MEMBER_NAME(PixelFormat_obj::Luminance,"Luminance");
	HX_VISIT_MEMBER_NAME(PixelFormat_obj::RGB8,"RGB8");
	HX_VISIT_MEMBER_NAME(PixelFormat_obj::RGBA8,"RGBA8");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class PixelFormat_obj::__mClass;

Dynamic __Create_PixelFormat_obj() { return new PixelFormat_obj; }

void PixelFormat_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.PixelFormat"), hx::TCanCast< PixelFormat_obj >,sStaticFields,sMemberFields,
	&__Create_PixelFormat_obj, &__Create,
	&super::__SGetClass(), &CreatePixelFormat_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void PixelFormat_obj::__boot()
{
hx::Static(Alpha8) = hx::CreateEnum< PixelFormat_obj >(HX_CSTRING("Alpha8"),0);
hx::Static(Depth) = hx::CreateEnum< PixelFormat_obj >(HX_CSTRING("Depth"),10);
hx::Static(_Float) = hx::CreateEnum< PixelFormat_obj >(HX_CSTRING("Float"),7);
hx::Static(Float3) = hx::CreateEnum< PixelFormat_obj >(HX_CSTRING("Float3"),8);
hx::Static(Float4) = hx::CreateEnum< PixelFormat_obj >(HX_CSTRING("Float4"),9);
hx::Static(Half) = hx::CreateEnum< PixelFormat_obj >(HX_CSTRING("Half"),4);
hx::Static(Half3) = hx::CreateEnum< PixelFormat_obj >(HX_CSTRING("Half3"),5);
hx::Static(Half4) = hx::CreateEnum< PixelFormat_obj >(HX_CSTRING("Half4"),6);
hx::Static(Luminance) = hx::CreateEnum< PixelFormat_obj >(HX_CSTRING("Luminance"),1);
hx::Static(RGB8) = hx::CreateEnum< PixelFormat_obj >(HX_CSTRING("RGB8"),2);
hx::Static(RGBA8) = hx::CreateEnum< PixelFormat_obj >(HX_CSTRING("RGBA8"),3);
}


} // end namespace haxor
} // end namespace core
