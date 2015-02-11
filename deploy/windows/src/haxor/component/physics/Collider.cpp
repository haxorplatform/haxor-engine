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
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_PhysicsContext
#include <haxor/context/PhysicsContext.h>
#endif
#ifndef INCLUDED_haxor_core_ColliderType
#include <haxor/core/ColliderType.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_math_AABB3
#include <haxor/math/AABB3.h>
#endif
#ifndef INCLUDED_haxor_math_Vector4
#include <haxor/math/Vector4.h>
#endif
#ifndef INCLUDED_haxor_physics_PhysicsMaterial
#include <haxor/physics/PhysicsMaterial.h>
#endif
namespace haxor{
namespace component{
namespace physics{

Void Collider_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.physics.Collider","new",0x66a4ae4a,"haxor.component.physics.Collider.new","haxor/component/physics/Collider.hx",14,0xb2857c03)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(14)
	super::__construct(p_name);
}
;
	return null();
}

//Collider_obj::~Collider_obj() { }

Dynamic Collider_obj::__CreateEmpty() { return  new Collider_obj; }
hx::ObjectPtr< Collider_obj > Collider_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< Collider_obj > result = new Collider_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic Collider_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Collider_obj > result = new Collider_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::core::ColliderType Collider_obj::get_type( ){
	HX_STACK_FRAME("haxor.component.physics.Collider","get_type",0xf2b42019,"haxor.component.physics.Collider.get_type","haxor/component/physics/Collider.hx",21,0xb2857c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(21)
	return this->m_type;
}


HX_DEFINE_DYNAMIC_FUNC0(Collider_obj,get_type,return )

bool Collider_obj::set_enabled( bool v){
	HX_STACK_FRAME("haxor.component.physics.Collider","set_enabled",0x7d38438e,"haxor.component.physics.Collider.set_enabled","haxor/component/physics/Collider.hx",30,0xb2857c03)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(31)
	this->super::set_enabled(v);
	HX_STACK_LINE(32)
	::haxor::context::EngineContext_obj::physics->OnColliderUpdate(hx::ObjectPtr<OBJ_>(this),false);
	HX_STACK_LINE(33)
	return v;
}


::haxor::math::Vector4 Collider_obj::get_sphere( ){
	HX_STACK_FRAME("haxor.component.physics.Collider","get_sphere",0x85cf322c,"haxor.component.physics.Collider.get_sphere","haxor/component/physics/Collider.hx",50,0xb2857c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(50)
	if ((this->m_sphere_dirty)){
		HX_STACK_LINE(50)
		this->GenerateSphere();
		HX_STACK_LINE(50)
		this->m_sphere_dirty = false;
	}
	HX_STACK_LINE(50)
	::haxor::math::Vector4 _this = this->m_sphere;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(50)
	return ::haxor::math::Vector4_obj::__new(_this->x,_this->y,_this->z,_this->w);
}


HX_DEFINE_DYNAMIC_FUNC0(Collider_obj,get_sphere,return )

::haxor::math::AABB3 Collider_obj::get_aabb( ){
	HX_STACK_FRAME("haxor.component.physics.Collider","get_aabb",0xe612cfff,"haxor.component.physics.Collider.get_aabb","haxor/component/physics/Collider.hx",58,0xb2857c03)
	HX_STACK_THIS(this)
	HX_STACK_LINE(58)
	if ((this->m_aabb_dirty)){
		HX_STACK_LINE(58)
		this->GenerateAABB();
		HX_STACK_LINE(58)
		this->m_aabb_dirty = false;
	}
	HX_STACK_LINE(58)
	return this->m_aabb->get_clone();
}


HX_DEFINE_DYNAMIC_FUNC0(Collider_obj,get_aabb,return )

Void Collider_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.physics.Collider","OnBuild",0x36c0bc59,"haxor.component.physics.Collider.OnBuild","haxor/component/physics/Collider.hx",67,0xb2857c03)
		HX_STACK_THIS(this)
		HX_STACK_LINE(68)
		this->super::OnBuild();
		HX_STACK_LINE(69)
		::haxor::context::EngineContext_obj::physics->CreateCollider(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(70)
		this->trigger = false;
		HX_STACK_LINE(71)
		::haxor::math::AABB3 _g = ::haxor::math::AABB3_obj::get_empty();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(71)
		this->m_aabb = _g;
		HX_STACK_LINE(72)
		::haxor::math::Vector4 _g1 = ::haxor::math::Vector4_obj::__new((int)0,(int)0,(int)0,(int)0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(72)
		this->m_sphere = _g1;
		HX_STACK_LINE(73)
		this->m_aabb_dirty = false;
		HX_STACK_LINE(74)
		this->m_sphere_dirty = false;
	}
return null();
}


Void Collider_obj::OnTransformUpdate( bool p_hierarchy){
{
		HX_STACK_FRAME("haxor.component.physics.Collider","OnTransformUpdate",0x5c102580,"haxor.component.physics.Collider.OnTransformUpdate","haxor/component/physics/Collider.hx",81,0xb2857c03)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_hierarchy,"p_hierarchy")
		HX_STACK_LINE(82)
		this->super::OnTransformUpdate(p_hierarchy);
		HX_STACK_LINE(83)
		this->Refresh();
		HX_STACK_LINE(84)
		::haxor::context::EngineContext_obj::physics->OnColliderUpdate(hx::ObjectPtr<OBJ_>(this),p_hierarchy);
	}
return null();
}


Void Collider_obj::GenerateSphere( ){
{
		HX_STACK_FRAME("haxor.component.physics.Collider","GenerateSphere",0x64526298,"haxor.component.physics.Collider.GenerateSphere","haxor/component/physics/Collider.hx",91,0xb2857c03)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Collider_obj,GenerateSphere,(void))

Void Collider_obj::GenerateAABB( ){
{
		HX_STACK_FRAME("haxor.component.physics.Collider","GenerateAABB",0x3872694b,"haxor.component.physics.Collider.GenerateAABB","haxor/component/physics/Collider.hx",96,0xb2857c03)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Collider_obj,GenerateAABB,(void))

Void Collider_obj::Refresh( ){
{
		HX_STACK_FRAME("haxor.component.physics.Collider","Refresh",0xd2b91ca5,"haxor.component.physics.Collider.Refresh","haxor/component/physics/Collider.hx",283,0xb2857c03)
		HX_STACK_THIS(this)
		HX_STACK_LINE(284)
		this->m_aabb_dirty = true;
		HX_STACK_LINE(285)
		this->m_sphere_dirty = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Collider_obj,Refresh,(void))


Collider_obj::Collider_obj()
{
}

void Collider_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Collider);
	HX_MARK_MEMBER_NAME(m_type,"m_type");
	HX_MARK_MEMBER_NAME(trigger,"trigger");
	HX_MARK_MEMBER_NAME(material,"material");
	HX_MARK_MEMBER_NAME(m_sphere,"m_sphere");
	HX_MARK_MEMBER_NAME(m_sphere_dirty,"m_sphere_dirty");
	HX_MARK_MEMBER_NAME(m_aabb,"m_aabb");
	HX_MARK_MEMBER_NAME(m_aabb_dirty,"m_aabb_dirty");
	::haxor::component::Component_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Collider_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_type,"m_type");
	HX_VISIT_MEMBER_NAME(trigger,"trigger");
	HX_VISIT_MEMBER_NAME(material,"material");
	HX_VISIT_MEMBER_NAME(m_sphere,"m_sphere");
	HX_VISIT_MEMBER_NAME(m_sphere_dirty,"m_sphere_dirty");
	HX_VISIT_MEMBER_NAME(m_aabb,"m_aabb");
	HX_VISIT_MEMBER_NAME(m_aabb_dirty,"m_aabb_dirty");
	::haxor::component::Component_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Collider_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"type") ) { return get_type(); }
		if (HX_FIELD_EQ(inName,"aabb") ) { return get_aabb(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { return m_type; }
		if (HX_FIELD_EQ(inName,"sphere") ) { return get_sphere(); }
		if (HX_FIELD_EQ(inName,"m_aabb") ) { return m_aabb; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"trigger") ) { return trigger; }
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		if (HX_FIELD_EQ(inName,"Refresh") ) { return Refresh_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_type") ) { return get_type_dyn(); }
		if (HX_FIELD_EQ(inName,"material") ) { return material; }
		if (HX_FIELD_EQ(inName,"m_sphere") ) { return m_sphere; }
		if (HX_FIELD_EQ(inName,"get_aabb") ) { return get_aabb_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_sphere") ) { return get_sphere_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_enabled") ) { return set_enabled_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_aabb_dirty") ) { return m_aabb_dirty; }
		if (HX_FIELD_EQ(inName,"GenerateAABB") ) { return GenerateAABB_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_sphere_dirty") ) { return m_sphere_dirty; }
		if (HX_FIELD_EQ(inName,"GenerateSphere") ) { return GenerateSphere_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"OnTransformUpdate") ) { return OnTransformUpdate_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Collider_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_type") ) { m_type=inValue.Cast< ::haxor::core::ColliderType >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_aabb") ) { m_aabb=inValue.Cast< ::haxor::math::AABB3 >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"trigger") ) { trigger=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"material") ) { material=inValue.Cast< ::haxor::physics::PhysicsMaterial >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_sphere") ) { m_sphere=inValue.Cast< ::haxor::math::Vector4 >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_aabb_dirty") ) { m_aabb_dirty=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_sphere_dirty") ) { m_sphere_dirty=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Collider_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("m_type"));
	outFields->push(HX_CSTRING("trigger"));
	outFields->push(HX_CSTRING("material"));
	outFields->push(HX_CSTRING("sphere"));
	outFields->push(HX_CSTRING("m_sphere"));
	outFields->push(HX_CSTRING("m_sphere_dirty"));
	outFields->push(HX_CSTRING("aabb"));
	outFields->push(HX_CSTRING("m_aabb"));
	outFields->push(HX_CSTRING("m_aabb_dirty"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::core::ColliderType*/ ,(int)offsetof(Collider_obj,m_type),HX_CSTRING("m_type")},
	{hx::fsBool,(int)offsetof(Collider_obj,trigger),HX_CSTRING("trigger")},
	{hx::fsObject /*::haxor::physics::PhysicsMaterial*/ ,(int)offsetof(Collider_obj,material),HX_CSTRING("material")},
	{hx::fsObject /*::haxor::math::Vector4*/ ,(int)offsetof(Collider_obj,m_sphere),HX_CSTRING("m_sphere")},
	{hx::fsBool,(int)offsetof(Collider_obj,m_sphere_dirty),HX_CSTRING("m_sphere_dirty")},
	{hx::fsObject /*::haxor::math::AABB3*/ ,(int)offsetof(Collider_obj,m_aabb),HX_CSTRING("m_aabb")},
	{hx::fsBool,(int)offsetof(Collider_obj,m_aabb_dirty),HX_CSTRING("m_aabb_dirty")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_type"),
	HX_CSTRING("m_type"),
	HX_CSTRING("set_enabled"),
	HX_CSTRING("trigger"),
	HX_CSTRING("material"),
	HX_CSTRING("get_sphere"),
	HX_CSTRING("m_sphere"),
	HX_CSTRING("m_sphere_dirty"),
	HX_CSTRING("get_aabb"),
	HX_CSTRING("m_aabb"),
	HX_CSTRING("m_aabb_dirty"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("OnTransformUpdate"),
	HX_CSTRING("GenerateSphere"),
	HX_CSTRING("GenerateAABB"),
	HX_CSTRING("Refresh"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Collider_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Collider_obj::__mClass,"__mClass");
};

#endif

Class Collider_obj::__mClass;

void Collider_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.physics.Collider"), hx::TCanCast< Collider_obj> ,sStaticFields,sMemberFields,
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

void Collider_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
} // end namespace physics
