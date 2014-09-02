#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_Light
#include <haxor/component/Light.h>
#endif
#ifndef INCLUDED_haxor_component_PointLight
#include <haxor/component/PointLight.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
namespace haxor{
namespace component{

Void PointLight_obj::__construct()
{
HX_STACK_FRAME("haxor.component.PointLight","new",0x37d5d2b5,"haxor.component.PointLight.new","haxor/component/PointLight.hx",45,0x729bedd9)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(46)
	super::__construct();
	HX_STACK_LINE(47)
	this->atten = 1.0;
	HX_STACK_LINE(48)
	this->radius = 1.0;
}
;
	return null();
}

//PointLight_obj::~PointLight_obj() { }

Dynamic PointLight_obj::__CreateEmpty() { return  new PointLight_obj; }
hx::ObjectPtr< PointLight_obj > PointLight_obj::__new()
{  hx::ObjectPtr< PointLight_obj > result = new PointLight_obj();
	result->__construct();
	return result;}

Dynamic PointLight_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PointLight_obj > result = new PointLight_obj();
	result->__construct();
	return result;}

::haxor::component::PointLight PointLight_obj::Create( ::haxor::math::Color p_color,Float p_intensity,Float p_atten,Float p_radius){
	HX_STACK_FRAME("haxor.component.PointLight","Create",0x20fe3be7,"haxor.component.PointLight.Create","haxor/component/PointLight.hx",20,0x729bedd9)
	HX_STACK_ARG(p_color,"p_color")
	HX_STACK_ARG(p_intensity,"p_intensity")
	HX_STACK_ARG(p_atten,"p_atten")
	HX_STACK_ARG(p_radius,"p_radius")
	HX_STACK_LINE(21)
	::haxor::core::Entity e = ::haxor::core::Entity_obj::__new(null());		HX_STACK_VAR(e,"e");
	HX_STACK_LINE(22)
	e->set_name(HX_CSTRING("PointLight"));
	HX_STACK_LINE(23)
	::haxor::component::PointLight l = e->AddComponent(hx::ClassOf< ::haxor::component::PointLight >());		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(24)
	l->color = p_color;
	HX_STACK_LINE(25)
	l->intensity = p_intensity;
	HX_STACK_LINE(26)
	l->atten = p_atten;
	HX_STACK_LINE(27)
	l->radius = p_radius;
	HX_STACK_LINE(28)
	return l;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(PointLight_obj,Create,return )


PointLight_obj::PointLight_obj()
{
}

Dynamic PointLight_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"atten") ) { return atten; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Create") ) { return Create_dyn(); }
		if (HX_FIELD_EQ(inName,"radius") ) { return radius; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PointLight_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"atten") ) { atten=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { radius=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PointLight_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("atten"));
	outFields->push(HX_CSTRING("radius"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Create"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(PointLight_obj,atten),HX_CSTRING("atten")},
	{hx::fsFloat,(int)offsetof(PointLight_obj,radius),HX_CSTRING("radius")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("atten"),
	HX_CSTRING("radius"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PointLight_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PointLight_obj::__mClass,"__mClass");
};

#endif

Class PointLight_obj::__mClass;

void PointLight_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.PointLight"), hx::TCanCast< PointLight_obj> ,sStaticFields,sMemberFields,
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

void PointLight_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component