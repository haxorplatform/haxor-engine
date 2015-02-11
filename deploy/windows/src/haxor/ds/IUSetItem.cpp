#include <hxcpp.h>

#ifndef INCLUDED_haxor_ds_IUSetItem
#include <haxor/ds/IUSetItem.h>
#endif
namespace haxor{
namespace ds{


static ::String sMemberFields[] = {
	HX_CSTRING("usid"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(IUSetItem_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(IUSetItem_obj::__mClass,"__mClass");
};

#endif

Class IUSetItem_obj::__mClass;

void IUSetItem_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.ds.IUSetItem"), hx::TCanCast< IUSetItem_obj> ,0,sMemberFields,
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

void IUSetItem_obj::__boot()
{
}

} // end namespace haxor
} // end namespace ds
