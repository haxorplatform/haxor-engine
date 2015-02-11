#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_CameraMode
#include <haxor/core/CameraMode.h>
#endif
namespace haxor{
namespace core{

::haxor::core::CameraMode CameraMode_obj::Custom;

::haxor::core::CameraMode CameraMode_obj::Ortho;

::haxor::core::CameraMode CameraMode_obj::Perspective;

::haxor::core::CameraMode CameraMode_obj::UI;

HX_DEFINE_CREATE_ENUM(CameraMode_obj)

int CameraMode_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("Custom")) return 0;
	if (inName==HX_CSTRING("Ortho")) return 2;
	if (inName==HX_CSTRING("Perspective")) return 1;
	if (inName==HX_CSTRING("UI")) return 3;
	return super::__FindIndex(inName);
}

int CameraMode_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("Custom")) return 0;
	if (inName==HX_CSTRING("Ortho")) return 0;
	if (inName==HX_CSTRING("Perspective")) return 0;
	if (inName==HX_CSTRING("UI")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic CameraMode_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("Custom")) return Custom;
	if (inName==HX_CSTRING("Ortho")) return Ortho;
	if (inName==HX_CSTRING("Perspective")) return Perspective;
	if (inName==HX_CSTRING("UI")) return UI;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Custom"),
	HX_CSTRING("Perspective"),
	HX_CSTRING("Ortho"),
	HX_CSTRING("UI"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CameraMode_obj::Custom,"Custom");
	HX_MARK_MEMBER_NAME(CameraMode_obj::Ortho,"Ortho");
	HX_MARK_MEMBER_NAME(CameraMode_obj::Perspective,"Perspective");
	HX_MARK_MEMBER_NAME(CameraMode_obj::UI,"UI");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CameraMode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(CameraMode_obj::Custom,"Custom");
	HX_VISIT_MEMBER_NAME(CameraMode_obj::Ortho,"Ortho");
	HX_VISIT_MEMBER_NAME(CameraMode_obj::Perspective,"Perspective");
	HX_VISIT_MEMBER_NAME(CameraMode_obj::UI,"UI");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class CameraMode_obj::__mClass;

Dynamic __Create_CameraMode_obj() { return new CameraMode_obj; }

void CameraMode_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.CameraMode"), hx::TCanCast< CameraMode_obj >,sStaticFields,sMemberFields,
	&__Create_CameraMode_obj, &__Create,
	&super::__SGetClass(), &CreateCameraMode_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void CameraMode_obj::__boot()
{
hx::Static(Custom) = hx::CreateEnum< CameraMode_obj >(HX_CSTRING("Custom"),0);
hx::Static(Ortho) = hx::CreateEnum< CameraMode_obj >(HX_CSTRING("Ortho"),2);
hx::Static(Perspective) = hx::CreateEnum< CameraMode_obj >(HX_CSTRING("Perspective"),1);
hx::Static(UI) = hx::CreateEnum< CameraMode_obj >(HX_CSTRING("UI"),3);
}


} // end namespace haxor
} // end namespace core
