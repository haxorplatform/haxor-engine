#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_CylinderEmitter
#include <haxor/component/CylinderEmitter.h>
#endif
#ifndef INCLUDED_haxor_component_ParticleEmitter
#include <haxor/component/ParticleEmitter.h>
#endif
namespace haxor{
namespace component{

Void CylinderEmitter_obj::__construct(hx::Null< Float >  __o_p_radius,hx::Null< Float >  __o_p_height)
{
HX_STACK_FRAME("haxor.component.CylinderEmitter","new",0x42422d2d,"haxor.component.CylinderEmitter.new","haxor/component/ParticleRenderer.hx",473,0x91e29536)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_radius,"p_radius")
HX_STACK_ARG(__o_p_height,"p_height")
Float p_radius = __o_p_radius.Default(1.0);
Float p_height = __o_p_height.Default(1.0);
{
	HX_STACK_LINE(474)
	super::__construct();
	HX_STACK_LINE(475)
	this->m_data[(int)0] = 3.0;
	HX_STACK_LINE(476)
	this->set_radius(p_radius);
	HX_STACK_LINE(477)
	this->set_height(p_height);
}
;
	return null();
}

//CylinderEmitter_obj::~CylinderEmitter_obj() { }

Dynamic CylinderEmitter_obj::__CreateEmpty() { return  new CylinderEmitter_obj; }
hx::ObjectPtr< CylinderEmitter_obj > CylinderEmitter_obj::__new(hx::Null< Float >  __o_p_radius,hx::Null< Float >  __o_p_height)
{  hx::ObjectPtr< CylinderEmitter_obj > result = new CylinderEmitter_obj();
	result->__construct(__o_p_radius,__o_p_height);
	return result;}

Dynamic CylinderEmitter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CylinderEmitter_obj > result = new CylinderEmitter_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Float CylinderEmitter_obj::get_radius( ){
	HX_STACK_FRAME("haxor.component.CylinderEmitter","get_radius",0x87b8c6ee,"haxor.component.CylinderEmitter.get_radius","haxor/component/ParticleRenderer.hx",465,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(465)
	return this->m_data->__get((int)3);
}


HX_DEFINE_DYNAMIC_FUNC0(CylinderEmitter_obj,get_radius,return )

Float CylinderEmitter_obj::set_radius( Float v){
	HX_STACK_FRAME("haxor.component.CylinderEmitter","set_radius",0x8b366562,"haxor.component.CylinderEmitter.set_radius","haxor/component/ParticleRenderer.hx",466,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(466)
	this->m_data[(int)3] = v;
	HX_STACK_LINE(466)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(CylinderEmitter_obj,set_radius,return )

Float CylinderEmitter_obj::get_height( ){
	HX_STACK_FRAME("haxor.component.CylinderEmitter","get_height",0xd90dfe83,"haxor.component.CylinderEmitter.get_height","haxor/component/ParticleRenderer.hx",469,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(469)
	return this->m_data->__get((int)4);
}


HX_DEFINE_DYNAMIC_FUNC0(CylinderEmitter_obj,get_height,return )

Float CylinderEmitter_obj::set_height( Float v){
	HX_STACK_FRAME("haxor.component.CylinderEmitter","set_height",0xdc8b9cf7,"haxor.component.CylinderEmitter.set_height","haxor/component/ParticleRenderer.hx",470,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(470)
	this->m_data[(int)4] = v;
	HX_STACK_LINE(470)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(CylinderEmitter_obj,set_height,return )


CylinderEmitter_obj::CylinderEmitter_obj()
{
}

Dynamic CylinderEmitter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return get_radius(); }
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_radius") ) { return get_radius_dyn(); }
		if (HX_FIELD_EQ(inName,"set_radius") ) { return set_radius_dyn(); }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CylinderEmitter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return set_radius(inValue); }
		if (HX_FIELD_EQ(inName,"height") ) { return set_height(inValue); }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CylinderEmitter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("radius"));
	outFields->push(HX_CSTRING("height"));
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
	HX_CSTRING("get_height"),
	HX_CSTRING("set_height"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CylinderEmitter_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CylinderEmitter_obj::__mClass,"__mClass");
};

#endif

Class CylinderEmitter_obj::__mClass;

void CylinderEmitter_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.CylinderEmitter"), hx::TCanCast< CylinderEmitter_obj> ,sStaticFields,sMemberFields,
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

void CylinderEmitter_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
