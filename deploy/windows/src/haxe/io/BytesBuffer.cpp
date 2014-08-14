#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_BytesBuffer
#include <haxe/io/BytesBuffer.h>
#endif
namespace haxe{
namespace io{

Void BytesBuffer_obj::__construct()
{
HX_STACK_FRAME("haxe.io.BytesBuffer","new",0x022790dd,"haxe.io.BytesBuffer.new","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/io/BytesBuffer.hx",45,0xb4f6d0e0)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(54)
	Array< unsigned char > _g = Array_obj< unsigned char >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(54)
	this->b = _g;
}
;
	return null();
}

//BytesBuffer_obj::~BytesBuffer_obj() { }

Dynamic BytesBuffer_obj::__CreateEmpty() { return  new BytesBuffer_obj; }
hx::ObjectPtr< BytesBuffer_obj > BytesBuffer_obj::__new()
{  hx::ObjectPtr< BytesBuffer_obj > result = new BytesBuffer_obj();
	result->__construct();
	return result;}

Dynamic BytesBuffer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BytesBuffer_obj > result = new BytesBuffer_obj();
	result->__construct();
	return result;}


BytesBuffer_obj::BytesBuffer_obj()
{
}

void BytesBuffer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BytesBuffer);
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_END_CLASS();
}

void BytesBuffer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(b,"b");
}

Dynamic BytesBuffer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BytesBuffer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Array< unsigned char > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BytesBuffer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("b"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< unsigned char >*/ ,(int)offsetof(BytesBuffer_obj,b),HX_CSTRING("b")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("b"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BytesBuffer_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BytesBuffer_obj::__mClass,"__mClass");
};

#endif

Class BytesBuffer_obj::__mClass;

void BytesBuffer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.BytesBuffer"), hx::TCanCast< BytesBuffer_obj> ,sStaticFields,sMemberFields,
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

void BytesBuffer_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
