#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_ILateUpdateable
#include <haxor/core/ILateUpdateable.h>
#endif
namespace haxor{
namespace core{

HX_DEFINE_DYNAMIC_FUNC0(ILateUpdateable_obj,OnLateUpdate,)


static ::String sMemberFields[] = {
	HX_CSTRING("OnLateUpdate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ILateUpdateable_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ILateUpdateable_obj::__mClass,"__mClass");
};

#endif

Class ILateUpdateable_obj::__mClass;

void ILateUpdateable_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.ILateUpdateable"), hx::TCanCast< ILateUpdateable_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void ILateUpdateable_obj::__boot()
{
}

} // end namespace haxor
} // end namespace core
