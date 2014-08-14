#include <hxcpp.h>

#ifndef INCLUDED_haxor_graphics_BufferPrimitive
#include <haxor/graphics/BufferPrimitive.h>
#endif
namespace haxor{
namespace graphics{

Void BufferPrimitive_obj::__construct()
{
	return null();
}

//BufferPrimitive_obj::~BufferPrimitive_obj() { }

Dynamic BufferPrimitive_obj::__CreateEmpty() { return  new BufferPrimitive_obj; }
hx::ObjectPtr< BufferPrimitive_obj > BufferPrimitive_obj::__new()
{  hx::ObjectPtr< BufferPrimitive_obj > result = new BufferPrimitive_obj();
	result->__construct();
	return result;}

Dynamic BufferPrimitive_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BufferPrimitive_obj > result = new BufferPrimitive_obj();
	result->__construct();
	return result;}

int BufferPrimitive_obj::U8;

int BufferPrimitive_obj::U16;

int BufferPrimitive_obj::U32;

int BufferPrimitive_obj::I8;

int BufferPrimitive_obj::I16;

int BufferPrimitive_obj::I32;

int BufferPrimitive_obj::F32;

int BufferPrimitive_obj::F64;


BufferPrimitive_obj::BufferPrimitive_obj()
{
}

Dynamic BufferPrimitive_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic BufferPrimitive_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void BufferPrimitive_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("U8"),
	HX_CSTRING("U16"),
	HX_CSTRING("U32"),
	HX_CSTRING("I8"),
	HX_CSTRING("I16"),
	HX_CSTRING("I32"),
	HX_CSTRING("F32"),
	HX_CSTRING("F64"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BufferPrimitive_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BufferPrimitive_obj::U8,"U8");
	HX_MARK_MEMBER_NAME(BufferPrimitive_obj::U16,"U16");
	HX_MARK_MEMBER_NAME(BufferPrimitive_obj::U32,"U32");
	HX_MARK_MEMBER_NAME(BufferPrimitive_obj::I8,"I8");
	HX_MARK_MEMBER_NAME(BufferPrimitive_obj::I16,"I16");
	HX_MARK_MEMBER_NAME(BufferPrimitive_obj::I32,"I32");
	HX_MARK_MEMBER_NAME(BufferPrimitive_obj::F32,"F32");
	HX_MARK_MEMBER_NAME(BufferPrimitive_obj::F64,"F64");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BufferPrimitive_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BufferPrimitive_obj::U8,"U8");
	HX_VISIT_MEMBER_NAME(BufferPrimitive_obj::U16,"U16");
	HX_VISIT_MEMBER_NAME(BufferPrimitive_obj::U32,"U32");
	HX_VISIT_MEMBER_NAME(BufferPrimitive_obj::I8,"I8");
	HX_VISIT_MEMBER_NAME(BufferPrimitive_obj::I16,"I16");
	HX_VISIT_MEMBER_NAME(BufferPrimitive_obj::I32,"I32");
	HX_VISIT_MEMBER_NAME(BufferPrimitive_obj::F32,"F32");
	HX_VISIT_MEMBER_NAME(BufferPrimitive_obj::F64,"F64");
};

#endif

Class BufferPrimitive_obj::__mClass;

void BufferPrimitive_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.BufferPrimitive"), hx::TCanCast< BufferPrimitive_obj> ,sStaticFields,sMemberFields,
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

void BufferPrimitive_obj::__boot()
{
	U8= (int)0;
	U16= (int)1;
	U32= (int)2;
	I8= (int)3;
	I16= (int)4;
	I32= (int)5;
	F32= (int)6;
	F64= (int)7;
}

} // end namespace haxor
} // end namespace graphics
