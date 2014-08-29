#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_file_ColladaMesh
#include <haxor/io/file/ColladaMesh.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaPrimitive
#include <haxor/io/file/ColladaPrimitive.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaMesh_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaMesh","new",0x8196e63b,"haxor.io.file.ColladaMesh.new","haxor/io/file/ColladaFile.hx",1072,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1075)
	this->primitives = null();
	HX_STACK_LINE(1074)
	this->type = HX_CSTRING("");
	HX_STACK_LINE(1078)
	this->primitives = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

//ColladaMesh_obj::~ColladaMesh_obj() { }

Dynamic ColladaMesh_obj::__CreateEmpty() { return  new ColladaMesh_obj; }
hx::ObjectPtr< ColladaMesh_obj > ColladaMesh_obj::__new()
{  hx::ObjectPtr< ColladaMesh_obj > result = new ColladaMesh_obj();
	result->__construct();
	return result;}

Dynamic ColladaMesh_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaMesh_obj > result = new ColladaMesh_obj();
	result->__construct();
	return result;}


ColladaMesh_obj::ColladaMesh_obj()
{
}

void ColladaMesh_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaMesh);
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(primitives,"primitives");
	HX_MARK_END_CLASS();
}

void ColladaMesh_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(primitives,"primitives");
}

Dynamic ColladaMesh_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"primitives") ) { return primitives; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaMesh_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"primitives") ) { primitives=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaMesh_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("primitives"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaMesh_obj,type),HX_CSTRING("type")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(ColladaMesh_obj,primitives),HX_CSTRING("primitives")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("type"),
	HX_CSTRING("primitives"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaMesh_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaMesh_obj::__mClass,"__mClass");
};

#endif

Class ColladaMesh_obj::__mClass;

void ColladaMesh_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaMesh"), hx::TCanCast< ColladaMesh_obj> ,sStaticFields,sMemberFields,
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

void ColladaMesh_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
