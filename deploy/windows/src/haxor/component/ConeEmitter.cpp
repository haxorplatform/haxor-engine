#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_ConeEmitter
#include <haxor/component/ConeEmitter.h>
#endif
#ifndef INCLUDED_haxor_component_ParticleEmitter
#include <haxor/component/ParticleEmitter.h>
#endif
namespace haxor{
namespace component{

Void ConeEmitter_obj::__construct(hx::Null< Float >  __o_p_angle,hx::Null< Float >  __o_p_height)
{
HX_STACK_FRAME("haxor.component.ConeEmitter","new",0x18764d40,"haxor.component.ConeEmitter.new","haxor/component/ParticleRenderer.hx",454,0x91e29536)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_angle,"p_angle")
HX_STACK_ARG(__o_p_height,"p_height")
Float p_angle = __o_p_angle.Default(45.0);
Float p_height = __o_p_height.Default(1.0);
{
	HX_STACK_LINE(455)
	super::__construct();
	HX_STACK_LINE(456)
	this->m_data[(int)0] = 2.0;
	HX_STACK_LINE(457)
	this->set_angle(p_angle);
	HX_STACK_LINE(458)
	this->set_height(p_height);
}
;
	return null();
}

//ConeEmitter_obj::~ConeEmitter_obj() { }

Dynamic ConeEmitter_obj::__CreateEmpty() { return  new ConeEmitter_obj; }
hx::ObjectPtr< ConeEmitter_obj > ConeEmitter_obj::__new(hx::Null< Float >  __o_p_angle,hx::Null< Float >  __o_p_height)
{  hx::ObjectPtr< ConeEmitter_obj > result = new ConeEmitter_obj();
	result->__construct(__o_p_angle,__o_p_height);
	return result;}

Dynamic ConeEmitter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ConeEmitter_obj > result = new ConeEmitter_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Float ConeEmitter_obj::get_angle( ){
	HX_STACK_FRAME("haxor.component.ConeEmitter","get_angle",0x0c7b050a,"haxor.component.ConeEmitter.get_angle","haxor/component/ParticleRenderer.hx",446,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(446)
	return this->m_data->__get((int)3);
}


HX_DEFINE_DYNAMIC_FUNC0(ConeEmitter_obj,get_angle,return )

Float ConeEmitter_obj::set_angle( Float v){
	HX_STACK_FRAME("haxor.component.ConeEmitter","set_angle",0xefcbf116,"haxor.component.ConeEmitter.set_angle","haxor/component/ParticleRenderer.hx",447,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(447)
	this->m_data[(int)3] = v;
	HX_STACK_LINE(447)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(ConeEmitter_obj,set_angle,return )

Float ConeEmitter_obj::get_height( ){
	HX_STACK_FRAME("haxor.component.ConeEmitter","get_height",0x7e5c56d0,"haxor.component.ConeEmitter.get_height","haxor/component/ParticleRenderer.hx",450,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(450)
	return this->m_data->__get((int)4);
}


HX_DEFINE_DYNAMIC_FUNC0(ConeEmitter_obj,get_height,return )

Float ConeEmitter_obj::set_height( Float v){
	HX_STACK_FRAME("haxor.component.ConeEmitter","set_height",0x81d9f544,"haxor.component.ConeEmitter.set_height","haxor/component/ParticleRenderer.hx",451,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(451)
	this->m_data[(int)4] = v;
	HX_STACK_LINE(451)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(ConeEmitter_obj,set_height,return )


ConeEmitter_obj::ConeEmitter_obj()
{
}

Dynamic ConeEmitter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"angle") ) { return get_angle(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_angle") ) { return get_angle_dyn(); }
		if (HX_FIELD_EQ(inName,"set_angle") ) { return set_angle_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ConeEmitter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"angle") ) { return set_angle(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return set_height(inValue); }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ConeEmitter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("angle"));
	outFields->push(HX_CSTRING("height"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_angle"),
	HX_CSTRING("set_angle"),
	HX_CSTRING("get_height"),
	HX_CSTRING("set_height"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ConeEmitter_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ConeEmitter_obj::__mClass,"__mClass");
};

#endif

Class ConeEmitter_obj::__mClass;

void ConeEmitter_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.ConeEmitter"), hx::TCanCast< ConeEmitter_obj> ,sStaticFields,sMemberFields,
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

void ConeEmitter_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
