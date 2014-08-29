#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_file_ColladaMaterial
#include <haxor/io/file/ColladaMaterial.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaMaterial_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaMaterial","new",0xfc037bf5,"haxor.io.file.ColladaMaterial.new","haxor/io/file/ColladaFile.hx",1469,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1473)
	this->name = HX_CSTRING("");
	HX_STACK_LINE(1471)
	this->id = HX_CSTRING("");
}
;
	return null();
}

//ColladaMaterial_obj::~ColladaMaterial_obj() { }

Dynamic ColladaMaterial_obj::__CreateEmpty() { return  new ColladaMaterial_obj; }
hx::ObjectPtr< ColladaMaterial_obj > ColladaMaterial_obj::__new()
{  hx::ObjectPtr< ColladaMaterial_obj > result = new ColladaMaterial_obj();
	result->__construct();
	return result;}

Dynamic ColladaMaterial_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaMaterial_obj > result = new ColladaMaterial_obj();
	result->__construct();
	return result;}


ColladaMaterial_obj::ColladaMaterial_obj()
{
}

void ColladaMaterial_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaMaterial);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_END_CLASS();
}

void ColladaMaterial_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(name,"name");
}

Dynamic ColladaMaterial_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaMaterial_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaMaterial_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("name"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaMaterial_obj,id),HX_CSTRING("id")},
	{hx::fsString,(int)offsetof(ColladaMaterial_obj,name),HX_CSTRING("name")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("id"),
	HX_CSTRING("name"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaMaterial_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaMaterial_obj::__mClass,"__mClass");
};

#endif

Class ColladaMaterial_obj::__mClass;

void ColladaMaterial_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaMaterial"), hx::TCanCast< ColladaMaterial_obj> ,sStaticFields,sMemberFields,
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

void ColladaMaterial_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
