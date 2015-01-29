#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_AnimationWrap
#include <haxor/core/AnimationWrap.h>
#endif
namespace haxor{
namespace core{

::haxor::core::AnimationWrap AnimationWrap_obj::Clamp;

::haxor::core::AnimationWrap AnimationWrap_obj::Loop;

::haxor::core::AnimationWrap AnimationWrap_obj::Oscilate;

HX_DEFINE_CREATE_ENUM(AnimationWrap_obj)

int AnimationWrap_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("Clamp")) return 0;
	if (inName==HX_CSTRING("Loop")) return 1;
	if (inName==HX_CSTRING("Oscilate")) return 2;
	return super::__FindIndex(inName);
}

int AnimationWrap_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("Clamp")) return 0;
	if (inName==HX_CSTRING("Loop")) return 0;
	if (inName==HX_CSTRING("Oscilate")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic AnimationWrap_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("Clamp")) return Clamp;
	if (inName==HX_CSTRING("Loop")) return Loop;
	if (inName==HX_CSTRING("Oscilate")) return Oscilate;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Clamp"),
	HX_CSTRING("Loop"),
	HX_CSTRING("Oscilate"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AnimationWrap_obj::Clamp,"Clamp");
	HX_MARK_MEMBER_NAME(AnimationWrap_obj::Loop,"Loop");
	HX_MARK_MEMBER_NAME(AnimationWrap_obj::Oscilate,"Oscilate");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AnimationWrap_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(AnimationWrap_obj::Clamp,"Clamp");
	HX_VISIT_MEMBER_NAME(AnimationWrap_obj::Loop,"Loop");
	HX_VISIT_MEMBER_NAME(AnimationWrap_obj::Oscilate,"Oscilate");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class AnimationWrap_obj::__mClass;

Dynamic __Create_AnimationWrap_obj() { return new AnimationWrap_obj; }

void AnimationWrap_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.AnimationWrap"), hx::TCanCast< AnimationWrap_obj >,sStaticFields,sMemberFields,
	&__Create_AnimationWrap_obj, &__Create,
	&super::__SGetClass(), &CreateAnimationWrap_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void AnimationWrap_obj::__boot()
{
hx::Static(Clamp) = hx::CreateEnum< AnimationWrap_obj >(HX_CSTRING("Clamp"),0);
hx::Static(Loop) = hx::CreateEnum< AnimationWrap_obj >(HX_CSTRING("Loop"),1);
hx::Static(Oscilate) = hx::CreateEnum< AnimationWrap_obj >(HX_CSTRING("Oscilate"),2);
}


} // end namespace haxor
} // end namespace core
