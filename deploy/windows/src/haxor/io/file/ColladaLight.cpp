#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_file_ColladaLight
#include <haxor/io/file/ColladaLight.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaLight_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaLight","new",0x250f146c,"haxor.io.file.ColladaLight.new","haxor/io/file/ColladaFile.hx",1536,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1537)
	this->id = HX_CSTRING("");
	HX_STACK_LINE(1538)
	this->name = HX_CSTRING("");
	HX_STACK_LINE(1539)
	this->type = HX_CSTRING("");
	HX_STACK_LINE(1540)
	::haxor::math::Color _g = ::haxor::math::Color_obj::__new((int)1,(int)1,(int)1,(int)1);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(1540)
	this->color = _g;
	HX_STACK_LINE(1541)
	this->radius = 0.0;
	HX_STACK_LINE(1542)
	this->intensity = 0.0;
	HX_STACK_LINE(1543)
	this->atten = 0.0;
}
;
	return null();
}

//ColladaLight_obj::~ColladaLight_obj() { }

Dynamic ColladaLight_obj::__CreateEmpty() { return  new ColladaLight_obj; }
hx::ObjectPtr< ColladaLight_obj > ColladaLight_obj::__new()
{  hx::ObjectPtr< ColladaLight_obj > result = new ColladaLight_obj();
	result->__construct();
	return result;}

Dynamic ColladaLight_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaLight_obj > result = new ColladaLight_obj();
	result->__construct();
	return result;}


ColladaLight_obj::ColladaLight_obj()
{
}

void ColladaLight_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaLight);
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(radius,"radius");
	HX_MARK_MEMBER_NAME(intensity,"intensity");
	HX_MARK_MEMBER_NAME(atten,"atten");
	HX_MARK_END_CLASS();
}

void ColladaLight_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(color,"color");
	HX_VISIT_MEMBER_NAME(radius,"radius");
	HX_VISIT_MEMBER_NAME(intensity,"intensity");
	HX_VISIT_MEMBER_NAME(atten,"atten");
}

Dynamic ColladaLight_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
		if (HX_FIELD_EQ(inName,"atten") ) { return atten; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return radius; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"intensity") ) { return intensity; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaLight_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"atten") ) { atten=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { radius=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"intensity") ) { intensity=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaLight_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("radius"));
	outFields->push(HX_CSTRING("intensity"));
	outFields->push(HX_CSTRING("atten"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaLight_obj,id),HX_CSTRING("id")},
	{hx::fsString,(int)offsetof(ColladaLight_obj,name),HX_CSTRING("name")},
	{hx::fsString,(int)offsetof(ColladaLight_obj,type),HX_CSTRING("type")},
	{hx::fsObject /*::haxor::math::Color*/ ,(int)offsetof(ColladaLight_obj,color),HX_CSTRING("color")},
	{hx::fsFloat,(int)offsetof(ColladaLight_obj,radius),HX_CSTRING("radius")},
	{hx::fsFloat,(int)offsetof(ColladaLight_obj,intensity),HX_CSTRING("intensity")},
	{hx::fsFloat,(int)offsetof(ColladaLight_obj,atten),HX_CSTRING("atten")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("id"),
	HX_CSTRING("name"),
	HX_CSTRING("type"),
	HX_CSTRING("color"),
	HX_CSTRING("radius"),
	HX_CSTRING("intensity"),
	HX_CSTRING("atten"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaLight_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaLight_obj::__mClass,"__mClass");
};

#endif

Class ColladaLight_obj::__mClass;

void ColladaLight_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaLight"), hx::TCanCast< ColladaLight_obj> ,sStaticFields,sMemberFields,
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

void ColladaLight_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
