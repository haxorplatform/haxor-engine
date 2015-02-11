#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_file_MaterialFileUniform
#include <haxor/io/file/MaterialFileUniform.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void MaterialFileUniform_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.MaterialFileUniform","new",0xde1c6d6d,"haxor.io.file.MaterialFileUniform.new","haxor/io/file/MaterialFile.hx",271,0x5b3fbce4)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(272)
	this->type = HX_CSTRING("");
	HX_STACK_LINE(273)
	this->name = HX_CSTRING("");
	HX_STACK_LINE(274)
	this->value = HX_CSTRING("");
}
;
	return null();
}

//MaterialFileUniform_obj::~MaterialFileUniform_obj() { }

Dynamic MaterialFileUniform_obj::__CreateEmpty() { return  new MaterialFileUniform_obj; }
hx::ObjectPtr< MaterialFileUniform_obj > MaterialFileUniform_obj::__new()
{  hx::ObjectPtr< MaterialFileUniform_obj > result = new MaterialFileUniform_obj();
	result->__construct();
	return result;}

Dynamic MaterialFileUniform_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MaterialFileUniform_obj > result = new MaterialFileUniform_obj();
	result->__construct();
	return result;}


MaterialFileUniform_obj::MaterialFileUniform_obj()
{
}

void MaterialFileUniform_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MaterialFileUniform);
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(value,"value");
	HX_MARK_END_CLASS();
}

void MaterialFileUniform_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(value,"value");
}

Dynamic MaterialFileUniform_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return value; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MaterialFileUniform_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MaterialFileUniform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("value"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(MaterialFileUniform_obj,type),HX_CSTRING("type")},
	{hx::fsString,(int)offsetof(MaterialFileUniform_obj,name),HX_CSTRING("name")},
	{hx::fsString,(int)offsetof(MaterialFileUniform_obj,value),HX_CSTRING("value")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("type"),
	HX_CSTRING("name"),
	HX_CSTRING("value"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MaterialFileUniform_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MaterialFileUniform_obj::__mClass,"__mClass");
};

#endif

Class MaterialFileUniform_obj::__mClass;

void MaterialFileUniform_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.MaterialFileUniform"), hx::TCanCast< MaterialFileUniform_obj> ,sStaticFields,sMemberFields,
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

void MaterialFileUniform_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
