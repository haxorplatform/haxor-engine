#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
namespace haxor{
namespace core{

HX_DEFINE_DYNAMIC_FUNC0(IDisposable_obj,OnDestroy,)


static ::String sMemberFields[] = {
	HX_CSTRING("OnDestroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IDisposable_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IDisposable_obj::__mClass,"__mClass");
};

#endif

Class IDisposable_obj::__mClass;

void IDisposable_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.IDisposable"), hx::TCanCast< IDisposable_obj> ,0,sMemberFields,
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

void IDisposable_obj::__boot()
{
}

} // end namespace haxor
} // end namespace core
