#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_file_ColladaInstance
#include <haxor/io/file/ColladaInstance.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaInstance_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaInstance","new",0xe4a64de3,"haxor.io.file.ColladaInstance.new","haxor/io/file/ColladaFile.hx",1463,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1467)
	this->target = HX_CSTRING("");
	HX_STACK_LINE(1465)
	this->type = HX_CSTRING("");
	HX_STACK_LINE(1473)
	this->materials = Array_obj< ::String >::__new();
}
;
	return null();
}

//ColladaInstance_obj::~ColladaInstance_obj() { }

Dynamic ColladaInstance_obj::__CreateEmpty() { return  new ColladaInstance_obj; }
hx::ObjectPtr< ColladaInstance_obj > ColladaInstance_obj::__new()
{  hx::ObjectPtr< ColladaInstance_obj > result = new ColladaInstance_obj();
	result->__construct();
	return result;}

Dynamic ColladaInstance_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaInstance_obj > result = new ColladaInstance_obj();
	result->__construct();
	return result;}


ColladaInstance_obj::ColladaInstance_obj()
{
}

void ColladaInstance_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaInstance);
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(materials,"materials");
	HX_MARK_END_CLASS();
}

void ColladaInstance_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(materials,"materials");
}

Dynamic ColladaInstance_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"materials") ) { return materials; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaInstance_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"materials") ) { materials=inValue.Cast< Array< ::String > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaInstance_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("materials"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaInstance_obj,type),HX_CSTRING("type")},
	{hx::fsString,(int)offsetof(ColladaInstance_obj,target),HX_CSTRING("target")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(ColladaInstance_obj,materials),HX_CSTRING("materials")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("type"),
	HX_CSTRING("target"),
	HX_CSTRING("materials"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaInstance_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaInstance_obj::__mClass,"__mClass");
};

#endif

Class ColladaInstance_obj::__mClass;

void ColladaInstance_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaInstance"), hx::TCanCast< ColladaInstance_obj> ,sStaticFields,sMemberFields,
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

void ColladaInstance_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
