#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_ParticleEmitter
#include <haxor/component/ParticleEmitter.h>
#endif
#ifndef INCLUDED_haxor_component_SphereEmitter
#include <haxor/component/SphereEmitter.h>
#endif
namespace haxor{
namespace component{

Void SphereEmitter_obj::__construct(hx::Null< Float >  __o_p_radius)
{
HX_STACK_FRAME("haxor.component.SphereEmitter","new",0xec3ffb16,"haxor.component.SphereEmitter.new","haxor/component/ParticleRenderer.hx",412,0x91e29536)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_radius,"p_radius")
Float p_radius = __o_p_radius.Default(1.0);
{
	HX_STACK_LINE(413)
	super::__construct();
	HX_STACK_LINE(414)
	this->m_data[(int)0] = 0.0;
	HX_STACK_LINE(415)
	this->set_radius(p_radius);
}
;
	return null();
}

//SphereEmitter_obj::~SphereEmitter_obj() { }

Dynamic SphereEmitter_obj::__CreateEmpty() { return  new SphereEmitter_obj; }
hx::ObjectPtr< SphereEmitter_obj > SphereEmitter_obj::__new(hx::Null< Float >  __o_p_radius)
{  hx::ObjectPtr< SphereEmitter_obj > result = new SphereEmitter_obj();
	result->__construct(__o_p_radius);
	return result;}

Dynamic SphereEmitter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SphereEmitter_obj > result = new SphereEmitter_obj();
	result->__construct(inArgs[0]);
	return result;}

Float SphereEmitter_obj::get_radius( ){
	HX_STACK_FRAME("haxor.component.SphereEmitter","get_radius",0x3ba87825,"haxor.component.SphereEmitter.get_radius","haxor/component/ParticleRenderer.hx",408,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(408)
	return this->m_data->__get((int)3);
}


HX_DEFINE_DYNAMIC_FUNC0(SphereEmitter_obj,get_radius,return )

Float SphereEmitter_obj::set_radius( Float v){
	HX_STACK_FRAME("haxor.component.SphereEmitter","set_radius",0x3f261699,"haxor.component.SphereEmitter.set_radius","haxor/component/ParticleRenderer.hx",409,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(409)
	this->m_data[(int)3] = v;
	HX_STACK_LINE(409)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(SphereEmitter_obj,set_radius,return )


SphereEmitter_obj::SphereEmitter_obj()
{
}

Dynamic SphereEmitter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return get_radius(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_radius") ) { return get_radius_dyn(); }
		if (HX_FIELD_EQ(inName,"set_radius") ) { return set_radius_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SphereEmitter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return set_radius(inValue); }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SphereEmitter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("radius"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_radius"),
	HX_CSTRING("set_radius"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SphereEmitter_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SphereEmitter_obj::__mClass,"__mClass");
};

#endif

Class SphereEmitter_obj::__mClass;

void SphereEmitter_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.SphereEmitter"), hx::TCanCast< SphereEmitter_obj> ,sStaticFields,sMemberFields,
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

void SphereEmitter_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
