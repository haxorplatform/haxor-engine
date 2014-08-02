#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_IResizeable
#include <haxor/core/IResizeable.h>
#endif
namespace haxor{
namespace core{

HX_DEFINE_DYNAMIC_FUNC2(IResizeable_obj,OnResize,)


static ::String sMemberFields[] = {
	HX_CSTRING("OnResize"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IResizeable_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IResizeable_obj::__mClass,"__mClass");
};

#endif

Class IResizeable_obj::__mClass;

void IResizeable_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.IResizeable"), hx::TCanCast< IResizeable_obj> ,0,sMemberFields,
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

void IResizeable_obj::__boot()
{
}

} // end namespace haxor
} // end namespace core
