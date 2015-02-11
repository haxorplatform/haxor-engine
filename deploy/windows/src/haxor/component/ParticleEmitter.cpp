#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_ParticleEmitter
#include <haxor/component/ParticleEmitter.h>
#endif
namespace haxor{
namespace component{

Void ParticleEmitter_obj::__construct()
{
HX_STACK_FRAME("haxor.component.ParticleEmitter","new",0x5149eb3d,"haxor.component.ParticleEmitter.new","haxor/component/ParticleRenderer.hx",397,0x91e29536)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(398)
	this->m_data = Array_obj< Float >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0);
	HX_STACK_LINE(399)
	this->set_surface(false);
	HX_STACK_LINE(400)
	this->set_random(false);
	HX_STACK_LINE(401)
	this->ranges = Array_obj< Float >::__new().Add((int)-1000).Add((int)1000).Add((int)-1000).Add((int)1000).Add((int)-1000).Add((int)1000);
}
;
	return null();
}

//ParticleEmitter_obj::~ParticleEmitter_obj() { }

Dynamic ParticleEmitter_obj::__CreateEmpty() { return  new ParticleEmitter_obj; }
hx::ObjectPtr< ParticleEmitter_obj > ParticleEmitter_obj::__new()
{  hx::ObjectPtr< ParticleEmitter_obj > result = new ParticleEmitter_obj();
	result->__construct();
	return result;}

Dynamic ParticleEmitter_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ParticleEmitter_obj > result = new ParticleEmitter_obj();
	result->__construct();
	return result;}

bool ParticleEmitter_obj::get_surface( ){
	HX_STACK_FRAME("haxor.component.ParticleEmitter","get_surface",0xb94b8621,"haxor.component.ParticleEmitter.get_surface","haxor/component/ParticleRenderer.hx",385,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(385)
	return (this->m_data->__get((int)1) > 0.0);
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleEmitter_obj,get_surface,return )

bool ParticleEmitter_obj::set_surface( bool v){
	HX_STACK_FRAME("haxor.component.ParticleEmitter","set_surface",0xc3b88d2d,"haxor.component.ParticleEmitter.set_surface","haxor/component/ParticleRenderer.hx",386,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(386)
	if ((v)){
		HX_STACK_LINE(386)
		this->m_data[(int)1] = 1.0;
	}
	else{
		HX_STACK_LINE(386)
		this->m_data[(int)1] = 0.0;
	}
	HX_STACK_LINE(386)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(ParticleEmitter_obj,set_surface,return )

bool ParticleEmitter_obj::get_random( ){
	HX_STACK_FRAME("haxor.component.ParticleEmitter","get_random",0x82043c8f,"haxor.component.ParticleEmitter.get_random","haxor/component/ParticleRenderer.hx",389,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(389)
	return (this->m_data->__get((int)2) > 0.0);
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleEmitter_obj,get_random,return )

bool ParticleEmitter_obj::set_random( bool v){
	HX_STACK_FRAME("haxor.component.ParticleEmitter","set_random",0x8581db03,"haxor.component.ParticleEmitter.set_random","haxor/component/ParticleRenderer.hx",390,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(390)
	if ((v)){
		HX_STACK_LINE(390)
		this->m_data[(int)2] = 1.0;
	}
	else{
		HX_STACK_LINE(390)
		this->m_data[(int)2] = 0.0;
	}
	HX_STACK_LINE(390)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(ParticleEmitter_obj,set_random,return )


ParticleEmitter_obj::ParticleEmitter_obj()
{
}

void ParticleEmitter_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ParticleEmitter);
	HX_MARK_MEMBER_NAME(ranges,"ranges");
	HX_MARK_MEMBER_NAME(m_data,"m_data");
	HX_MARK_END_CLASS();
}

void ParticleEmitter_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(ranges,"ranges");
	HX_VISIT_MEMBER_NAME(m_data,"m_data");
}

Dynamic ParticleEmitter_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"random") ) { return get_random(); }
		if (HX_FIELD_EQ(inName,"ranges") ) { return ranges; }
		if (HX_FIELD_EQ(inName,"m_data") ) { return m_data; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"surface") ) { return get_surface(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_random") ) { return get_random_dyn(); }
		if (HX_FIELD_EQ(inName,"set_random") ) { return set_random_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_surface") ) { return get_surface_dyn(); }
		if (HX_FIELD_EQ(inName,"set_surface") ) { return set_surface_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ParticleEmitter_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"random") ) { return set_random(inValue); }
		if (HX_FIELD_EQ(inName,"ranges") ) { ranges=inValue.Cast< Array< Float > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_data") ) { m_data=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"surface") ) { return set_surface(inValue); }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ParticleEmitter_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("surface"));
	outFields->push(HX_CSTRING("random"));
	outFields->push(HX_CSTRING("ranges"));
	outFields->push(HX_CSTRING("m_data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(ParticleEmitter_obj,ranges),HX_CSTRING("ranges")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(ParticleEmitter_obj,m_data),HX_CSTRING("m_data")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_surface"),
	HX_CSTRING("set_surface"),
	HX_CSTRING("get_random"),
	HX_CSTRING("set_random"),
	HX_CSTRING("ranges"),
	HX_CSTRING("m_data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ParticleEmitter_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ParticleEmitter_obj::__mClass,"__mClass");
};

#endif

Class ParticleEmitter_obj::__mClass;

void ParticleEmitter_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.ParticleEmitter"), hx::TCanCast< ParticleEmitter_obj> ,sStaticFields,sMemberFields,
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

void ParticleEmitter_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
