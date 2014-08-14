#include <hxcpp.h>

#ifndef INCLUDED_haxe_remoting_Connection
#include <haxe/remoting/Connection.h>
#endif
namespace haxe{
namespace remoting{


static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Connection_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Connection_obj::__mClass,"__mClass");
};

#endif

Class Connection_obj::__mClass;

void Connection_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.remoting.Connection"), hx::TCanCast< Connection_obj> ,0,sMemberFields,
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

void Connection_obj::__boot()
{
}

} // end namespace haxe
} // end namespace remoting
