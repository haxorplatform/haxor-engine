#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_ForceMode
#include <haxor/core/ForceMode.h>
#endif
namespace haxor{
namespace core{

::haxor::core::ForceMode ForceMode_obj::Acceleration;

::haxor::core::ForceMode ForceMode_obj::Force;

::haxor::core::ForceMode ForceMode_obj::Impulse;

::haxor::core::ForceMode ForceMode_obj::Velocity;

HX_DEFINE_CREATE_ENUM(ForceMode_obj)

int ForceMode_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("Acceleration")) return 0;
	if (inName==HX_CSTRING("Force")) return 1;
	if (inName==HX_CSTRING("Impulse")) return 2;
	if (inName==HX_CSTRING("Velocity")) return 3;
	return super::__FindIndex(inName);
}

int ForceMode_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("Acceleration")) return 0;
	if (inName==HX_CSTRING("Force")) return 0;
	if (inName==HX_CSTRING("Impulse")) return 0;
	if (inName==HX_CSTRING("Velocity")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic ForceMode_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("Acceleration")) return Acceleration;
	if (inName==HX_CSTRING("Force")) return Force;
	if (inName==HX_CSTRING("Impulse")) return Impulse;
	if (inName==HX_CSTRING("Velocity")) return Velocity;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Acceleration"),
	HX_CSTRING("Force"),
	HX_CSTRING("Impulse"),
	HX_CSTRING("Velocity"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ForceMode_obj::Acceleration,"Acceleration");
	HX_MARK_MEMBER_NAME(ForceMode_obj::Force,"Force");
	HX_MARK_MEMBER_NAME(ForceMode_obj::Impulse,"Impulse");
	HX_MARK_MEMBER_NAME(ForceMode_obj::Velocity,"Velocity");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ForceMode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ForceMode_obj::Acceleration,"Acceleration");
	HX_VISIT_MEMBER_NAME(ForceMode_obj::Force,"Force");
	HX_VISIT_MEMBER_NAME(ForceMode_obj::Impulse,"Impulse");
	HX_VISIT_MEMBER_NAME(ForceMode_obj::Velocity,"Velocity");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class ForceMode_obj::__mClass;

Dynamic __Create_ForceMode_obj() { return new ForceMode_obj; }

void ForceMode_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.ForceMode"), hx::TCanCast< ForceMode_obj >,sStaticFields,sMemberFields,
	&__Create_ForceMode_obj, &__Create,
	&super::__SGetClass(), &CreateForceMode_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void ForceMode_obj::__boot()
{
hx::Static(Acceleration) = hx::CreateEnum< ForceMode_obj >(HX_CSTRING("Acceleration"),0);
hx::Static(Force) = hx::CreateEnum< ForceMode_obj >(HX_CSTRING("Force"),1);
hx::Static(Impulse) = hx::CreateEnum< ForceMode_obj >(HX_CSTRING("Impulse"),2);
hx::Static(Velocity) = hx::CreateEnum< ForceMode_obj >(HX_CSTRING("Velocity"),3);
}


} // end namespace haxor
} // end namespace core
