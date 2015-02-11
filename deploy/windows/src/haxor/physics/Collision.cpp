#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_physics_Collider
#include <haxor/component/physics/Collider.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_ds_IUSetItem
#include <haxor/ds/IUSetItem.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_physics_Collision
#include <haxor/physics/Collision.h>
#endif
namespace haxor{
namespace physics{

Void Collision_obj::__construct()
{
HX_STACK_FRAME("haxor.physics.Collision","new",0x5d613131,"haxor.physics.Collision.new","haxor/physics/Collision.hx",25,0xa376a361)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(26)
	::haxor::math::Vector3 _g = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(26)
	this->normal = _g;
	HX_STACK_LINE(27)
	::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(27)
	this->point = _g1;
	HX_STACK_LINE(28)
	this->depth = 0.0;
	HX_STACK_LINE(29)
	this->speed = 0.0;
	HX_STACK_LINE(30)
	this->usid = (int)-1;
}
;
	return null();
}

//Collision_obj::~Collision_obj() { }

Dynamic Collision_obj::__CreateEmpty() { return  new Collision_obj; }
hx::ObjectPtr< Collision_obj > Collision_obj::__new()
{  hx::ObjectPtr< Collision_obj > result = new Collision_obj();
	result->__construct();
	return result;}

Dynamic Collision_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Collision_obj > result = new Collision_obj();
	result->__construct();
	return result;}

hx::Object *Collision_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::haxor::ds::IUSetItem_obj)) return operator ::haxor::ds::IUSetItem_obj *();
	return super::__ToInterface(inType);
}

::haxor::physics::Collision Collision_obj::Invert( ){
	HX_STACK_FRAME("haxor.physics.Collision","Invert",0x5c219305,"haxor.physics.Collision.Invert","haxor/physics/Collision.hx",38,0xa376a361)
	HX_STACK_THIS(this)
	HX_STACK_LINE(39)
	::haxor::component::physics::Collider tc = this->from;		HX_STACK_VAR(tc,"tc");
	HX_STACK_LINE(40)
	this->from = this->to;
	HX_STACK_LINE(41)
	this->to = tc;
	HX_STACK_LINE(42)
	this->normal->Invert();
	HX_STACK_LINE(43)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Collision_obj,Invert,return )

Void Collision_obj::Reset( ){
{
		HX_STACK_FRAME("haxor.physics.Collision","Reset",0x3db9b0c0,"haxor.physics.Collision.Reset","haxor/physics/Collision.hx",50,0xa376a361)
		HX_STACK_THIS(this)
		HX_STACK_LINE(51)
		this->normal->Set(null(),null(),null());
		HX_STACK_LINE(52)
		this->point->Set(null(),null(),null());
		HX_STACK_LINE(53)
		this->depth = (int)0;
		HX_STACK_LINE(54)
		this->speed = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Collision_obj,Reset,(void))


Collision_obj::Collision_obj()
{
}

void Collision_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Collision);
	HX_MARK_MEMBER_NAME(usid,"usid");
	HX_MARK_MEMBER_NAME(from,"from");
	HX_MARK_MEMBER_NAME(to,"to");
	HX_MARK_MEMBER_NAME(point,"point");
	HX_MARK_MEMBER_NAME(depth,"depth");
	HX_MARK_MEMBER_NAME(normal,"normal");
	HX_MARK_MEMBER_NAME(speed,"speed");
	HX_MARK_END_CLASS();
}

void Collision_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(usid,"usid");
	HX_VISIT_MEMBER_NAME(from,"from");
	HX_VISIT_MEMBER_NAME(to,"to");
	HX_VISIT_MEMBER_NAME(point,"point");
	HX_VISIT_MEMBER_NAME(depth,"depth");
	HX_VISIT_MEMBER_NAME(normal,"normal");
	HX_VISIT_MEMBER_NAME(speed,"speed");
}

Dynamic Collision_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"to") ) { return to; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"usid") ) { return usid; }
		if (HX_FIELD_EQ(inName,"from") ) { return from; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"point") ) { return point; }
		if (HX_FIELD_EQ(inName,"depth") ) { return depth; }
		if (HX_FIELD_EQ(inName,"speed") ) { return speed; }
		if (HX_FIELD_EQ(inName,"Reset") ) { return Reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"normal") ) { return normal; }
		if (HX_FIELD_EQ(inName,"Invert") ) { return Invert_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Collision_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"to") ) { to=inValue.Cast< ::haxor::component::physics::Collider >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"usid") ) { usid=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"from") ) { from=inValue.Cast< ::haxor::component::physics::Collider >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"point") ) { point=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"depth") ) { depth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"speed") ) { speed=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"normal") ) { normal=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Collision_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("usid"));
	outFields->push(HX_CSTRING("from"));
	outFields->push(HX_CSTRING("to"));
	outFields->push(HX_CSTRING("point"));
	outFields->push(HX_CSTRING("depth"));
	outFields->push(HX_CSTRING("normal"));
	outFields->push(HX_CSTRING("speed"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Collision_obj,usid),HX_CSTRING("usid")},
	{hx::fsObject /*::haxor::component::physics::Collider*/ ,(int)offsetof(Collision_obj,from),HX_CSTRING("from")},
	{hx::fsObject /*::haxor::component::physics::Collider*/ ,(int)offsetof(Collision_obj,to),HX_CSTRING("to")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Collision_obj,point),HX_CSTRING("point")},
	{hx::fsFloat,(int)offsetof(Collision_obj,depth),HX_CSTRING("depth")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Collision_obj,normal),HX_CSTRING("normal")},
	{hx::fsFloat,(int)offsetof(Collision_obj,speed),HX_CSTRING("speed")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("usid"),
	HX_CSTRING("from"),
	HX_CSTRING("to"),
	HX_CSTRING("point"),
	HX_CSTRING("depth"),
	HX_CSTRING("normal"),
	HX_CSTRING("speed"),
	HX_CSTRING("Invert"),
	HX_CSTRING("Reset"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Collision_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Collision_obj::__mClass,"__mClass");
};

#endif

Class Collision_obj::__mClass;

void Collision_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.physics.Collision"), hx::TCanCast< Collision_obj> ,sStaticFields,sMemberFields,
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

void Collision_obj::__boot()
{
}

} // end namespace haxor
} // end namespace physics
