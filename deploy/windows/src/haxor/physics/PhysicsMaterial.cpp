#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_physics_PhysicsMaterial
#include <haxor/physics/PhysicsMaterial.h>
#endif
namespace haxor{
namespace physics{

Void PhysicsMaterial_obj::__construct()
{
HX_STACK_FRAME("haxor.physics.PhysicsMaterial","new",0xb0f44f0d,"haxor.physics.PhysicsMaterial.new","haxor/physics/PhysicsMaterial.hx",38,0x90d8e285)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(39)
	super::__construct(null());
	HX_STACK_LINE(40)
	this->bounce = 0.0;
	HX_STACK_LINE(41)
	this->friction = 0.0;
}
;
	return null();
}

//PhysicsMaterial_obj::~PhysicsMaterial_obj() { }

Dynamic PhysicsMaterial_obj::__CreateEmpty() { return  new PhysicsMaterial_obj; }
hx::ObjectPtr< PhysicsMaterial_obj > PhysicsMaterial_obj::__new()
{  hx::ObjectPtr< PhysicsMaterial_obj > result = new PhysicsMaterial_obj();
	result->__construct();
	return result;}

Dynamic PhysicsMaterial_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PhysicsMaterial_obj > result = new PhysicsMaterial_obj();
	result->__construct();
	return result;}

::haxor::physics::PhysicsMaterial PhysicsMaterial_obj::m_empty;

::haxor::physics::PhysicsMaterial PhysicsMaterial_obj::get_empty( ){
	HX_STACK_FRAME("haxor.physics.PhysicsMaterial","get_empty",0x4697d551,"haxor.physics.PhysicsMaterial.get_empty","haxor/physics/PhysicsMaterial.hx",17,0x90d8e285)
	HX_STACK_LINE(18)
	if (((::haxor::physics::PhysicsMaterial_obj::m_empty != null()))){
		HX_STACK_LINE(18)
		return ::haxor::physics::PhysicsMaterial_obj::m_empty;
	}
	HX_STACK_LINE(19)
	::haxor::physics::PhysicsMaterial _g = ::haxor::physics::PhysicsMaterial_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(19)
	::haxor::physics::PhysicsMaterial_obj::m_empty = _g;
	HX_STACK_LINE(20)
	::haxor::physics::PhysicsMaterial_obj::m_empty->set_name(HX_CSTRING("$DefaultPhysicsMaterial"));
	HX_STACK_LINE(21)
	return ::haxor::physics::PhysicsMaterial_obj::m_empty;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(PhysicsMaterial_obj,get_empty,return )


PhysicsMaterial_obj::PhysicsMaterial_obj()
{
}

Dynamic PhysicsMaterial_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"empty") ) { return get_empty(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bounce") ) { return bounce; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_empty") ) { return m_empty; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"friction") ) { return friction; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_empty") ) { return get_empty_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PhysicsMaterial_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"bounce") ) { bounce=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_empty") ) { m_empty=inValue.Cast< ::haxor::physics::PhysicsMaterial >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"friction") ) { friction=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PhysicsMaterial_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bounce"));
	outFields->push(HX_CSTRING("friction"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_empty"),
	HX_CSTRING("get_empty"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(PhysicsMaterial_obj,bounce),HX_CSTRING("bounce")},
	{hx::fsFloat,(int)offsetof(PhysicsMaterial_obj,friction),HX_CSTRING("friction")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("bounce"),
	HX_CSTRING("friction"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PhysicsMaterial_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(PhysicsMaterial_obj::m_empty,"m_empty");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PhysicsMaterial_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(PhysicsMaterial_obj::m_empty,"m_empty");
};

#endif

Class PhysicsMaterial_obj::__mClass;

void PhysicsMaterial_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.physics.PhysicsMaterial"), hx::TCanCast< PhysicsMaterial_obj> ,sStaticFields,sMemberFields,
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

void PhysicsMaterial_obj::__boot()
{
}

} // end namespace haxor
} // end namespace physics
