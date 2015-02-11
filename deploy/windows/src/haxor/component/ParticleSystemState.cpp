#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_ParticleSystemState
#include <haxor/component/ParticleSystemState.h>
#endif
namespace haxor{
namespace component{

::haxor::component::ParticleSystemState ParticleSystemState_obj::None;

::haxor::component::ParticleSystemState ParticleSystemState_obj::Reset;

::haxor::component::ParticleSystemState ParticleSystemState_obj::Update;

HX_DEFINE_CREATE_ENUM(ParticleSystemState_obj)

int ParticleSystemState_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("None")) return 0;
	if (inName==HX_CSTRING("Reset")) return 1;
	if (inName==HX_CSTRING("Update")) return 2;
	return super::__FindIndex(inName);
}

int ParticleSystemState_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("None")) return 0;
	if (inName==HX_CSTRING("Reset")) return 0;
	if (inName==HX_CSTRING("Update")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic ParticleSystemState_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("None")) return None;
	if (inName==HX_CSTRING("Reset")) return Reset;
	if (inName==HX_CSTRING("Update")) return Update;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("None"),
	HX_CSTRING("Reset"),
	HX_CSTRING("Update"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ParticleSystemState_obj::None,"None");
	HX_MARK_MEMBER_NAME(ParticleSystemState_obj::Reset,"Reset");
	HX_MARK_MEMBER_NAME(ParticleSystemState_obj::Update,"Update");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ParticleSystemState_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ParticleSystemState_obj::None,"None");
	HX_VISIT_MEMBER_NAME(ParticleSystemState_obj::Reset,"Reset");
	HX_VISIT_MEMBER_NAME(ParticleSystemState_obj::Update,"Update");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class ParticleSystemState_obj::__mClass;

Dynamic __Create_ParticleSystemState_obj() { return new ParticleSystemState_obj; }

void ParticleSystemState_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.ParticleSystemState"), hx::TCanCast< ParticleSystemState_obj >,sStaticFields,sMemberFields,
	&__Create_ParticleSystemState_obj, &__Create,
	&super::__SGetClass(), &CreateParticleSystemState_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void ParticleSystemState_obj::__boot()
{
hx::Static(None) = hx::CreateEnum< ParticleSystemState_obj >(HX_CSTRING("None"),0);
hx::Static(Reset) = hx::CreateEnum< ParticleSystemState_obj >(HX_CSTRING("Reset"),1);
hx::Static(Update) = hx::CreateEnum< ParticleSystemState_obj >(HX_CSTRING("Update"),2);
}


} // end namespace haxor
} // end namespace component
