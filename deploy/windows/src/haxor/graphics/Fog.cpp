#include <hxcpp.h>

#ifndef INCLUDED_haxor_graphics_Fog
#include <haxor/graphics/Fog.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
namespace haxor{
namespace graphics{

Void Fog_obj::__construct()
{
	return null();
}

//Fog_obj::~Fog_obj() { }

Dynamic Fog_obj::__CreateEmpty() { return  new Fog_obj; }
hx::ObjectPtr< Fog_obj > Fog_obj::__new()
{  hx::ObjectPtr< Fog_obj > result = new Fog_obj();
	result->__construct();
	return result;}

Dynamic Fog_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Fog_obj > result = new Fog_obj();
	result->__construct();
	return result;}

::haxor::math::Color Fog_obj::color;

Float Fog_obj::density;

Float Fog_obj::exp;

Float Fog_obj::start;

Float Fog_obj::end;


Fog_obj::Fog_obj()
{
}

Dynamic Fog_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"exp") ) { return exp; }
		if (HX_FIELD_EQ(inName,"end") ) { return end; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
		if (HX_FIELD_EQ(inName,"start") ) { return start; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"density") ) { return density; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Fog_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"exp") ) { exp=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"end") ) { end=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"start") ) { start=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"density") ) { density=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Fog_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("color"),
	HX_CSTRING("density"),
	HX_CSTRING("exp"),
	HX_CSTRING("start"),
	HX_CSTRING("end"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Fog_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Fog_obj::color,"color");
	HX_MARK_MEMBER_NAME(Fog_obj::density,"density");
	HX_MARK_MEMBER_NAME(Fog_obj::exp,"exp");
	HX_MARK_MEMBER_NAME(Fog_obj::start,"start");
	HX_MARK_MEMBER_NAME(Fog_obj::end,"end");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Fog_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Fog_obj::color,"color");
	HX_VISIT_MEMBER_NAME(Fog_obj::density,"density");
	HX_VISIT_MEMBER_NAME(Fog_obj::exp,"exp");
	HX_VISIT_MEMBER_NAME(Fog_obj::start,"start");
	HX_VISIT_MEMBER_NAME(Fog_obj::end,"end");
};

#endif

Class Fog_obj::__mClass;

void Fog_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.Fog"), hx::TCanCast< Fog_obj> ,sStaticFields,sMemberFields,
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

void Fog_obj::__boot()
{
	color= ::haxor::math::Color_obj::__new(0.5,0.5,0.5,(int)1);
	density= 1.0;
	exp= 1.0;
	start= 0.0;
	end= 1.0;
}

} // end namespace haxor
} // end namespace graphics
