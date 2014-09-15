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
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
namespace haxor{
namespace component{

Void Light_obj::__construct()
{
HX_STACK_FRAME("haxor.component.Light","new",0x4234558b,"haxor.component.Light.new","haxor/component/Light.hx",59,0x76b66187)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(60)
	if (((::haxor::component::Light_obj::m_list == null()))){
		HX_STACK_LINE(60)
		::haxor::component::Light_obj::m_list = Array_obj< ::Dynamic >::__new();
	}
	HX_STACK_LINE(61)
	if (((::haxor::component::Light_obj::m_buffer == null()))){
		HX_STACK_LINE(61)
		::haxor::io::FloatArray _g = ::haxor::io::FloatArray_obj::__new(((int)12 * ::haxor::component::Light_obj::max));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(61)
		::haxor::component::Light_obj::m_buffer = _g;
	}
	HX_STACK_LINE(62)
	::haxor::component::Light_obj::m_list->push(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(63)
	super::__construct(null());
	HX_STACK_LINE(64)
	::haxor::math::Color _g1 = ::haxor::math::Color_obj::__new((int)1,(int)1,(int)1,(int)1);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(64)
	this->color = _g1;
	HX_STACK_LINE(65)
	this->intensity = 1.0;
}
;
	return null();
}

//Light_obj::~Light_obj() { }

Dynamic Light_obj::__CreateEmpty() { return  new Light_obj; }
hx::ObjectPtr< Light_obj > Light_obj::__new()
{  hx::ObjectPtr< Light_obj > result = new Light_obj();
	result->__construct();
	return result;}

Dynamic Light_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Light_obj > result = new Light_obj();
	result->__construct();
	return result;}

Void Light_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.component.Light","OnDestroy",0x2ab0fce6,"haxor.component.Light.OnDestroy","haxor/component/Light.hx",72,0x76b66187)
		HX_STACK_THIS(this)
		HX_STACK_LINE(73)
		this->super::OnDestroy();
		HX_STACK_LINE(74)
		::haxor::component::Light_obj::m_list->remove(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


::haxor::math::Color Light_obj::ambient;

int Light_obj::max;

::haxor::io::FloatArray Light_obj::m_buffer;

Array< ::Dynamic > Light_obj::list;

Array< ::Dynamic > Light_obj::m_list;

Array< ::Dynamic > Light_obj::get_list( ){
	HX_STACK_FRAME("haxor.component.Light","get_list",0x61e3b6dc,"haxor.component.Light.get_list","haxor/component/Light.hx",37,0x76b66187)
	HX_STACK_LINE(38)
	Array< ::Dynamic > l = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(39)
	if (((::haxor::component::Light_obj::m_list == null()))){
		HX_STACK_LINE(39)
		return l;
	}
	HX_STACK_LINE(40)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(41)
	while((true)){
		HX_STACK_LINE(41)
		if ((!(((i < ::haxor::component::Light_obj::m_list->length))))){
			HX_STACK_LINE(41)
			break;
		}
		HX_STACK_LINE(41)
		l->push(::haxor::component::Light_obj::m_list->__get(i).StaticCast< ::haxor::component::Light >());
		HX_STACK_LINE(41)
		(i)++;
	}
	HX_STACK_LINE(42)
	return l;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Light_obj,get_list,return )

Void Light_obj::SetLightData( int p_id,Float p_type,Float p_intensity,Float p_radius,Float p_atten,Float p_x,Float p_y,Float p_z,Float p_r,Float p_g,Float p_b,Float p_a){
{
		HX_STACK_FRAME("haxor.component.Light","SetLightData",0x26cc3fb3,"haxor.component.Light.SetLightData","haxor/component/Light.hx",93,0x76b66187)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_type,"p_type")
		HX_STACK_ARG(p_intensity,"p_intensity")
		HX_STACK_ARG(p_radius,"p_radius")
		HX_STACK_ARG(p_atten,"p_atten")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_r,"p_r")
		HX_STACK_ARG(p_g,"p_g")
		HX_STACK_ARG(p_b,"p_b")
		HX_STACK_ARG(p_a,"p_a")
		HX_STACK_LINE(94)
		int pos = (p_id * (int)12);		HX_STACK_VAR(pos,"pos");
		HX_STACK_LINE(95)
		::haxor::component::Light_obj::m_buffer->Set(pos,p_type);
		HX_STACK_LINE(96)
		::haxor::component::Light_obj::m_buffer->Set((pos + (int)1),p_intensity);
		HX_STACK_LINE(97)
		::haxor::component::Light_obj::m_buffer->Set((pos + (int)2),p_radius);
		HX_STACK_LINE(98)
		::haxor::component::Light_obj::m_buffer->Set((pos + (int)3),p_atten);
		HX_STACK_LINE(99)
		::haxor::component::Light_obj::m_buffer->Set((pos + (int)4),p_x);
		HX_STACK_LINE(100)
		::haxor::component::Light_obj::m_buffer->Set((pos + (int)5),p_y);
		HX_STACK_LINE(101)
		::haxor::component::Light_obj::m_buffer->Set((pos + (int)6),p_z);
		HX_STACK_LINE(102)
		::haxor::component::Light_obj::m_buffer->Set((pos + (int)8),p_r);
		HX_STACK_LINE(103)
		::haxor::component::Light_obj::m_buffer->Set((pos + (int)9),p_g);
		HX_STACK_LINE(104)
		::haxor::component::Light_obj::m_buffer->Set((pos + (int)10),p_b);
		HX_STACK_LINE(105)
		::haxor::component::Light_obj::m_buffer->Set((pos + (int)11),p_a);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC12(Light_obj,SetLightData,(void))


Light_obj::Light_obj()
{
}

void Light_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Light);
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(intensity,"intensity");
	::haxor::component::Component_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Light_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(color,"color");
	HX_VISIT_MEMBER_NAME(intensity,"intensity");
	::haxor::component::Component_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Light_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"max") ) { return max; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return inCallProp ? get_list() : list; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { return color; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_list") ) { return m_list; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"ambient") ) { return ambient; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_buffer") ) { return m_buffer; }
		if (HX_FIELD_EQ(inName,"get_list") ) { return get_list_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"intensity") ) { return intensity; }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"SetLightData") ) { return SetLightData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Light_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"max") ) { max=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_list") ) { m_list=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"ambient") ) { ambient=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_buffer") ) { m_buffer=inValue.Cast< ::haxor::io::FloatArray >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"intensity") ) { intensity=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Light_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("intensity"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ambient"),
	HX_CSTRING("max"),
	HX_CSTRING("m_buffer"),
	HX_CSTRING("list"),
	HX_CSTRING("m_list"),
	HX_CSTRING("get_list"),
	HX_CSTRING("SetLightData"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Color*/ ,(int)offsetof(Light_obj,color),HX_CSTRING("color")},
	{hx::fsFloat,(int)offsetof(Light_obj,intensity),HX_CSTRING("intensity")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("color"),
	HX_CSTRING("intensity"),
	HX_CSTRING("OnDestroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Light_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Light_obj::ambient,"ambient");
	HX_MARK_MEMBER_NAME(Light_obj::max,"max");
	HX_MARK_MEMBER_NAME(Light_obj::m_buffer,"m_buffer");
	HX_MARK_MEMBER_NAME(Light_obj::list,"list");
	HX_MARK_MEMBER_NAME(Light_obj::m_list,"m_list");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Light_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Light_obj::ambient,"ambient");
	HX_VISIT_MEMBER_NAME(Light_obj::max,"max");
	HX_VISIT_MEMBER_NAME(Light_obj::m_buffer,"m_buffer");
	HX_VISIT_MEMBER_NAME(Light_obj::list,"list");
	HX_VISIT_MEMBER_NAME(Light_obj::m_list,"m_list");
};

#endif

Class Light_obj::__mClass;

void Light_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.Light"), hx::TCanCast< Light_obj> ,sStaticFields,sMemberFields,
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

void Light_obj::__boot()
{
	ambient= ::haxor::math::Color_obj::__new(0.0,0.0,0.0,1.0);
	max= (int)8;
	m_list= Array_obj< ::Dynamic >::__new();
}

} // end namespace haxor
} // end namespace component
