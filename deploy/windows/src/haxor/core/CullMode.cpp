#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_CullMode
#include <haxor/core/CullMode.h>
#endif
namespace haxor{
namespace core{

Void CullMode_obj::__construct()
{
	return null();
}

//CullMode_obj::~CullMode_obj() { }

Dynamic CullMode_obj::__CreateEmpty() { return  new CullMode_obj; }
hx::ObjectPtr< CullMode_obj > CullMode_obj::__new()
{  hx::ObjectPtr< CullMode_obj > result = new CullMode_obj();
	result->__construct();
	return result;}

Dynamic CullMode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CullMode_obj > result = new CullMode_obj();
	result->__construct();
	return result;}

int CullMode_obj::None;

int CullMode_obj::Front;

int CullMode_obj::Back;


CullMode_obj::CullMode_obj()
{
}

Dynamic CullMode_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic CullMode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void CullMode_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("None"),
	HX_CSTRING("Front"),
	HX_CSTRING("Back"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CullMode_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(CullMode_obj::None,"None");
	HX_MARK_MEMBER_NAME(CullMode_obj::Front,"Front");
	HX_MARK_MEMBER_NAME(CullMode_obj::Back,"Back");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CullMode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(CullMode_obj::None,"None");
	HX_VISIT_MEMBER_NAME(CullMode_obj::Front,"Front");
	HX_VISIT_MEMBER_NAME(CullMode_obj::Back,"Back");
};

#endif

Class CullMode_obj::__mClass;

void CullMode_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.CullMode"), hx::TCanCast< CullMode_obj> ,sStaticFields,sMemberFields,
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

void CullMode_obj::__boot()
{
	None= (int)0;
	Front= (int)1;
	Back= (int)2;
}

} // end namespace haxor
} // end namespace core
