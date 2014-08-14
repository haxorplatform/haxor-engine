#include <hxcpp.h>

#ifndef INCLUDED_cpp_NativeArray
#include <cpp/NativeArray.h>
#endif
namespace cpp{

Void NativeArray_obj::__construct()
{
	return null();
}

//NativeArray_obj::~NativeArray_obj() { }

Dynamic NativeArray_obj::__CreateEmpty() { return  new NativeArray_obj; }
hx::ObjectPtr< NativeArray_obj > NativeArray_obj::__new()
{  hx::ObjectPtr< NativeArray_obj > result = new NativeArray_obj();
	result->__construct();
	return result;}

Dynamic NativeArray_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< NativeArray_obj > result = new NativeArray_obj();
	result->__construct();
	return result;}


NativeArray_obj::NativeArray_obj()
{
}

Dynamic NativeArray_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic NativeArray_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void NativeArray_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(NativeArray_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(NativeArray_obj::__mClass,"__mClass");
};

#endif

Class NativeArray_obj::__mClass;

void NativeArray_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("cpp.NativeArray"), hx::TCanCast< NativeArray_obj> ,sStaticFields,sMemberFields,
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

void NativeArray_obj::__boot()
{
}

} // end namespace cpp
