#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_file_ColladaGeometry
#include <haxor/io/file/ColladaGeometry.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaMesh
#include <haxor/io/file/ColladaMesh.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaGeometry_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaGeometry","new",0x753a8380,"haxor.io.file.ColladaGeometry.new","haxor/io/file/ColladaFile.hx",1063,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1067)
	this->mesh = null();
	HX_STACK_LINE(1066)
	this->name = HX_CSTRING("");
	HX_STACK_LINE(1065)
	this->id = HX_CSTRING("");
}
;
	return null();
}

//ColladaGeometry_obj::~ColladaGeometry_obj() { }

Dynamic ColladaGeometry_obj::__CreateEmpty() { return  new ColladaGeometry_obj; }
hx::ObjectPtr< ColladaGeometry_obj > ColladaGeometry_obj::__new()
{  hx::ObjectPtr< ColladaGeometry_obj > result = new ColladaGeometry_obj();
	result->__construct();
	return result;}

Dynamic ColladaGeometry_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaGeometry_obj > result = new ColladaGeometry_obj();
	result->__construct();
	return result;}


ColladaGeometry_obj::ColladaGeometry_obj()
{
}

void ColladaGeometry_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaGeometry);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(mesh,"mesh");
	HX_MARK_END_CLASS();
}

void ColladaGeometry_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(mesh,"mesh");
}

Dynamic ColladaGeometry_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		if (HX_FIELD_EQ(inName,"mesh") ) { return mesh; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaGeometry_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mesh") ) { mesh=inValue.Cast< ::haxor::io::file::ColladaMesh >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaGeometry_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("mesh"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaGeometry_obj,id),HX_CSTRING("id")},
	{hx::fsString,(int)offsetof(ColladaGeometry_obj,name),HX_CSTRING("name")},
	{hx::fsObject /*::haxor::io::file::ColladaMesh*/ ,(int)offsetof(ColladaGeometry_obj,mesh),HX_CSTRING("mesh")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("id"),
	HX_CSTRING("name"),
	HX_CSTRING("mesh"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaGeometry_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaGeometry_obj::__mClass,"__mClass");
};

#endif

Class ColladaGeometry_obj::__mClass;

void ColladaGeometry_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaGeometry"), hx::TCanCast< ColladaGeometry_obj> ,sStaticFields,sMemberFields,
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

void ColladaGeometry_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
