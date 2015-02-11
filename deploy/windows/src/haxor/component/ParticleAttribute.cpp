#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_ParticleAttribute
#include <haxor/component/ParticleAttribute.h>
#endif
namespace haxor{
namespace component{

Void ParticleAttribute_obj::__construct(Dynamic p_start,Dynamic p_end,hx::Null< Float >  __o_p_curve,hx::Null< bool >  __o_p_random)
{
HX_STACK_FRAME("haxor.component.ParticleAttribute","new",0xd105062b,"haxor.component.ParticleAttribute.new","haxor/component/ParticleRenderer.hx",25,0x91e29536)
HX_STACK_THIS(this)
HX_STACK_ARG(p_start,"p_start")
HX_STACK_ARG(p_end,"p_end")
HX_STACK_ARG(__o_p_curve,"p_curve")
HX_STACK_ARG(__o_p_random,"p_random")
Float p_curve = __o_p_curve.Default(1.0);
bool p_random = __o_p_random.Default(false);
{
	HX_STACK_LINE(26)
	this->start = p_start;
	HX_STACK_LINE(27)
	this->end = p_end;
	HX_STACK_LINE(28)
	this->curve = p_curve;
	HX_STACK_LINE(29)
	this->random = p_random;
}
;
	return null();
}

//ParticleAttribute_obj::~ParticleAttribute_obj() { }

Dynamic ParticleAttribute_obj::__CreateEmpty() { return  new ParticleAttribute_obj; }
hx::ObjectPtr< ParticleAttribute_obj > ParticleAttribute_obj::__new(Dynamic p_start,Dynamic p_end,hx::Null< Float >  __o_p_curve,hx::Null< bool >  __o_p_random)
{  hx::ObjectPtr< ParticleAttribute_obj > result = new ParticleAttribute_obj();
	result->__construct(p_start,p_end,__o_p_curve,__o_p_random);
	return result;}

Dynamic ParticleAttribute_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ParticleAttribute_obj > result = new ParticleAttribute_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}


ParticleAttribute_obj::ParticleAttribute_obj()
{
}

void ParticleAttribute_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ParticleAttribute);
	HX_MARK_MEMBER_NAME(start,"start");
	HX_MARK_MEMBER_NAME(end,"end");
	HX_MARK_MEMBER_NAME(curve,"curve");
	HX_MARK_MEMBER_NAME(random,"random");
	HX_MARK_END_CLASS();
}

void ParticleAttribute_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(start,"start");
	HX_VISIT_MEMBER_NAME(end,"end");
	HX_VISIT_MEMBER_NAME(curve,"curve");
	HX_VISIT_MEMBER_NAME(random,"random");
}

Dynamic ParticleAttribute_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"end") ) { return end; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start; }
		if (HX_FIELD_EQ(inName,"curve") ) { return curve; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"random") ) { return random; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ParticleAttribute_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"end") ) { end=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { start=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"curve") ) { curve=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"random") ) { random=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ParticleAttribute_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("start"));
	outFields->push(HX_CSTRING("end"));
	outFields->push(HX_CSTRING("curve"));
	outFields->push(HX_CSTRING("random"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(ParticleAttribute_obj,start),HX_CSTRING("start")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(ParticleAttribute_obj,end),HX_CSTRING("end")},
	{hx::fsFloat,(int)offsetof(ParticleAttribute_obj,curve),HX_CSTRING("curve")},
	{hx::fsBool,(int)offsetof(ParticleAttribute_obj,random),HX_CSTRING("random")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("start"),
	HX_CSTRING("end"),
	HX_CSTRING("curve"),
	HX_CSTRING("random"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ParticleAttribute_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ParticleAttribute_obj::__mClass,"__mClass");
};

#endif

Class ParticleAttribute_obj::__mClass;

void ParticleAttribute_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.ParticleAttribute"), hx::TCanCast< ParticleAttribute_obj> ,sStaticFields,sMemberFields,
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

void ParticleAttribute_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
