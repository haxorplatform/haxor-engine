#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_EngineState
#include <haxor/core/EngineState.h>
#endif
namespace haxor{
namespace core{

::haxor::core::EngineState EngineState_obj::Editor;

::haxor::core::EngineState EngineState_obj::Play;

HX_DEFINE_CREATE_ENUM(EngineState_obj)

int EngineState_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("Editor")) return 1;
	if (inName==HX_CSTRING("Play")) return 0;
	return super::__FindIndex(inName);
}

int EngineState_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("Editor")) return 0;
	if (inName==HX_CSTRING("Play")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic EngineState_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("Editor")) return Editor;
	if (inName==HX_CSTRING("Play")) return Play;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Play"),
	HX_CSTRING("Editor"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EngineState_obj::Editor,"Editor");
	HX_MARK_MEMBER_NAME(EngineState_obj::Play,"Play");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EngineState_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(EngineState_obj::Editor,"Editor");
	HX_VISIT_MEMBER_NAME(EngineState_obj::Play,"Play");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class EngineState_obj::__mClass;

Dynamic __Create_EngineState_obj() { return new EngineState_obj; }

void EngineState_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.EngineState"), hx::TCanCast< EngineState_obj >,sStaticFields,sMemberFields,
	&__Create_EngineState_obj, &__Create,
	&super::__SGetClass(), &CreateEngineState_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void EngineState_obj::__boot()
{
hx::Static(Editor) = hx::CreateEnum< EngineState_obj >(HX_CSTRING("Editor"),1);
hx::Static(Play) = hx::CreateEnum< EngineState_obj >(HX_CSTRING("Play"),0);
}


} // end namespace haxor
} // end namespace core
