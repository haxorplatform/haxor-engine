#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_DepthTest
#include <haxor/core/DepthTest.h>
#endif
namespace haxor{
namespace core{

Void DepthTest_obj::__construct()
{
	return null();
}

//DepthTest_obj::~DepthTest_obj() { }

Dynamic DepthTest_obj::__CreateEmpty() { return  new DepthTest_obj; }
hx::ObjectPtr< DepthTest_obj > DepthTest_obj::__new()
{  hx::ObjectPtr< DepthTest_obj > result = new DepthTest_obj();
	result->__construct();
	return result;}

Dynamic DepthTest_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DepthTest_obj > result = new DepthTest_obj();
	result->__construct();
	return result;}

int DepthTest_obj::Never;

int DepthTest_obj::Less;

int DepthTest_obj::Equal;

int DepthTest_obj::LessEqual;

int DepthTest_obj::Greater;

int DepthTest_obj::NotEqual;

int DepthTest_obj::GreaterEqual;

int DepthTest_obj::Always;


DepthTest_obj::DepthTest_obj()
{
}

Dynamic DepthTest_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic DepthTest_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void DepthTest_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Never"),
	HX_CSTRING("Less"),
	HX_CSTRING("Equal"),
	HX_CSTRING("LessEqual"),
	HX_CSTRING("Greater"),
	HX_CSTRING("NotEqual"),
	HX_CSTRING("GreaterEqual"),
	HX_CSTRING("Always"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DepthTest_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(DepthTest_obj::Never,"Never");
	HX_MARK_MEMBER_NAME(DepthTest_obj::Less,"Less");
	HX_MARK_MEMBER_NAME(DepthTest_obj::Equal,"Equal");
	HX_MARK_MEMBER_NAME(DepthTest_obj::LessEqual,"LessEqual");
	HX_MARK_MEMBER_NAME(DepthTest_obj::Greater,"Greater");
	HX_MARK_MEMBER_NAME(DepthTest_obj::NotEqual,"NotEqual");
	HX_MARK_MEMBER_NAME(DepthTest_obj::GreaterEqual,"GreaterEqual");
	HX_MARK_MEMBER_NAME(DepthTest_obj::Always,"Always");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DepthTest_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(DepthTest_obj::Never,"Never");
	HX_VISIT_MEMBER_NAME(DepthTest_obj::Less,"Less");
	HX_VISIT_MEMBER_NAME(DepthTest_obj::Equal,"Equal");
	HX_VISIT_MEMBER_NAME(DepthTest_obj::LessEqual,"LessEqual");
	HX_VISIT_MEMBER_NAME(DepthTest_obj::Greater,"Greater");
	HX_VISIT_MEMBER_NAME(DepthTest_obj::NotEqual,"NotEqual");
	HX_VISIT_MEMBER_NAME(DepthTest_obj::GreaterEqual,"GreaterEqual");
	HX_VISIT_MEMBER_NAME(DepthTest_obj::Always,"Always");
};

#endif

Class DepthTest_obj::__mClass;

void DepthTest_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.DepthTest"), hx::TCanCast< DepthTest_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void DepthTest_obj::__boot()
{
	Never= (int)512;
	Less= (int)513;
	Equal= (int)514;
	LessEqual= (int)515;
	Greater= (int)516;
	NotEqual= (int)517;
	GreaterEqual= (int)518;
	Always= (int)519;
}

} // end namespace haxor
} // end namespace core
