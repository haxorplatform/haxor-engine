#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_component_physics_RigidBody
#include <haxor/component/physics/RigidBody.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_PhysicsContext
#include <haxor/context/PhysicsContext.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_ForceMode
#include <haxor/core/ForceMode.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
#endif
#ifndef INCLUDED_haxor_math_Quaternion
#include <haxor/math/Quaternion.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_physics_Physics
#include <haxor/physics/Physics.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace component{
namespace physics{

Void RigidBody_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.physics.RigidBody","new",0x843b1bbb,"haxor.component.physics.RigidBody.new","haxor/component/physics/RigidBody.hx",21,0x9a85c9d8)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(21)
	super::__construct(p_name);
}
;
	return null();
}

//RigidBody_obj::~RigidBody_obj() { }

Dynamic RigidBody_obj::__CreateEmpty() { return  new RigidBody_obj; }
hx::ObjectPtr< RigidBody_obj > RigidBody_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< RigidBody_obj > result = new RigidBody_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic RigidBody_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RigidBody_obj > result = new RigidBody_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::math::Vector3 RigidBody_obj::get_velocity( ){
	HX_STACK_FRAME("haxor.component.physics.RigidBody","get_velocity",0x46e7a76b,"haxor.component.physics.RigidBody.get_velocity","haxor/component/physics/RigidBody.hx",28,0x9a85c9d8)
	HX_STACK_THIS(this)
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",28,0x9a85c9d8)
			{
				HX_STACK_LINE(28)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(28)
				int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(28)
				return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(28)
	return (_Function_1_1::Block())->Set(this->m_velocity->x,this->m_velocity->y,this->m_velocity->z);
}


HX_DEFINE_DYNAMIC_FUNC0(RigidBody_obj,get_velocity,return )

::haxor::math::Vector3 RigidBody_obj::set_velocity( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.physics.RigidBody","set_velocity",0x5be0cadf,"haxor.component.physics.RigidBody.set_velocity","haxor/component/physics/RigidBody.hx",30,0x9a85c9d8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(31)
	Float _g = ::Math_obj::sqrt((((v->x * v->x) + (v->y * v->y)) + (v->z * v->z)));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(31)
	this->m_speed = _g;
	HX_STACK_LINE(32)
	Float ispd;		HX_STACK_VAR(ispd,"ispd");
	HX_STACK_LINE(32)
	if (((this->m_speed <= 0.0))){
		HX_STACK_LINE(32)
		ispd = 0.0;
	}
	else{
		HX_STACK_LINE(32)
		ispd = (Float(1.0) / Float(this->m_speed));
	}
	HX_STACK_LINE(33)
	this->m_velocity->Set3(v);
	HX_STACK_LINE(34)
	this->m_direction->Set3(v)->Scale(ispd);
	HX_STACK_LINE(35)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(RigidBody_obj,set_velocity,return )

::haxor::math::Vector3 RigidBody_obj::get_angularVelocity( ){
	HX_STACK_FRAME("haxor.component.physics.RigidBody","get_angularVelocity",0xe121df91,"haxor.component.physics.RigidBody.get_angularVelocity","haxor/component/physics/RigidBody.hx",46,0x9a85c9d8)
	HX_STACK_THIS(this)
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",46,0x9a85c9d8)
			{
				HX_STACK_LINE(46)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(46)
				int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(46)
				return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(46)
	return (_Function_1_1::Block())->Set(this->m_angularVelocity->x,this->m_angularVelocity->y,this->m_angularVelocity->z);
}


HX_DEFINE_DYNAMIC_FUNC0(RigidBody_obj,get_angularVelocity,return )

::haxor::math::Vector3 RigidBody_obj::set_angularVelocity( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.component.physics.RigidBody","set_angularVelocity",0x1dbed29d,"haxor.component.physics.RigidBody.set_angularVelocity","haxor/component/physics/RigidBody.hx",48,0x9a85c9d8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(49)
	Float _g = ::Math_obj::sqrt((((v->x * v->x) + (v->y * v->y)) + (v->z * v->z)));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(49)
	this->m_angularSpeed = _g;
	HX_STACK_LINE(50)
	Float ispd;		HX_STACK_VAR(ispd,"ispd");
	HX_STACK_LINE(50)
	if (((this->m_angularSpeed <= 0.0))){
		HX_STACK_LINE(50)
		ispd = 0.0;
	}
	else{
		HX_STACK_LINE(50)
		ispd = (Float(1.0) / Float(this->m_angularSpeed));
	}
	HX_STACK_LINE(51)
	this->m_angularVelocity->Set3(v);
	HX_STACK_LINE(52)
	this->m_angularDirection->Set3(v)->Scale(ispd);
	HX_STACK_LINE(53)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(RigidBody_obj,set_angularVelocity,return )

Float RigidBody_obj::get_drag( ){
	HX_STACK_FRAME("haxor.component.physics.RigidBody","get_drag",0xdf6d9242,"haxor.component.physics.RigidBody.get_drag","haxor/component/physics/RigidBody.hx",69,0x9a85c9d8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(69)
	return this->m_drag;
}


HX_DEFINE_DYNAMIC_FUNC0(RigidBody_obj,get_drag,return )

Float RigidBody_obj::set_drag( Float v){
	HX_STACK_FRAME("haxor.component.physics.RigidBody","set_drag",0x8dcaebb6,"haxor.component.physics.RigidBody.set_drag","haxor/component/physics/RigidBody.hx",71,0x9a85c9d8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(72)
	Float _g = ::Math_obj::max((int)0,v);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(72)
	this->m_drag = _g;
	HX_STACK_LINE(73)
	return this->m_drag;
}


HX_DEFINE_DYNAMIC_FUNC1(RigidBody_obj,set_drag,return )

Float RigidBody_obj::get_angularDrag( ){
	HX_STACK_FRAME("haxor.component.physics.RigidBody","get_angularDrag",0xcf933f68,"haxor.component.physics.RigidBody.get_angularDrag","haxor/component/physics/RigidBody.hx",82,0x9a85c9d8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(82)
	return this->m_angularDrag;
}


HX_DEFINE_DYNAMIC_FUNC0(RigidBody_obj,get_angularDrag,return )

Float RigidBody_obj::set_angularDrag( Float v){
	HX_STACK_FRAME("haxor.component.physics.RigidBody","set_angularDrag",0xcb5ebc74,"haxor.component.physics.RigidBody.set_angularDrag","haxor/component/physics/RigidBody.hx",84,0x9a85c9d8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(85)
	Float _g = ::Math_obj::max((int)0,v);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(85)
	this->m_angularDrag = _g;
	HX_STACK_LINE(86)
	return this->m_angularDrag;
}


HX_DEFINE_DYNAMIC_FUNC1(RigidBody_obj,set_angularDrag,return )

Float RigidBody_obj::get_mass( ){
	HX_STACK_FRAME("haxor.component.physics.RigidBody","get_mass",0xe553a742,"haxor.component.physics.RigidBody.get_mass","haxor/component/physics/RigidBody.hx",95,0x9a85c9d8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(95)
	return this->m_mass;
}


HX_DEFINE_DYNAMIC_FUNC0(RigidBody_obj,get_mass,return )

Float RigidBody_obj::set_mass( Float v){
	HX_STACK_FRAME("haxor.component.physics.RigidBody","set_mass",0x93b100b6,"haxor.component.physics.RigidBody.set_mass","haxor/component/physics/RigidBody.hx",97,0x9a85c9d8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(98)
	Float _g = ::Math_obj::max((int)0,v);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(98)
	this->m_mass = _g;
	HX_STACK_LINE(99)
	if (((this->m_mass <= 0.0))){
		HX_STACK_LINE(99)
		this->m_imass = 0.0;
	}
	else{
		HX_STACK_LINE(99)
		this->m_imass = (Float(1.0) / Float(this->m_mass));
	}
	HX_STACK_LINE(100)
	return this->m_mass;
}


HX_DEFINE_DYNAMIC_FUNC1(RigidBody_obj,set_mass,return )

Void RigidBody_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.physics.RigidBody","OnBuild",0x94d9364a,"haxor.component.physics.RigidBody.OnBuild","haxor/component/physics/RigidBody.hx",129,0x9a85c9d8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(131)
		::haxor::math::Vector3 _g = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(131)
		this->m_velocity = _g;
		HX_STACK_LINE(132)
		::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(132)
		this->m_dragForce = _g1;
		HX_STACK_LINE(133)
		::haxor::math::Vector3 _g2 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(133)
		this->m_direction = _g2;
		HX_STACK_LINE(134)
		this->m_speed = 0.0;
		HX_STACK_LINE(136)
		::haxor::math::Quaternion _g3 = ::haxor::math::Quaternion_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(136)
		this->m_avq = _g3;
		HX_STACK_LINE(137)
		::haxor::math::Vector3 _g4 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(137)
		this->m_angularVelocity = _g4;
		HX_STACK_LINE(138)
		::haxor::math::Vector3 _g5 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(138)
		this->m_dragTorque = _g5;
		HX_STACK_LINE(139)
		::haxor::math::Vector3 _g6 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(139)
		this->m_angularDirection = _g6;
		HX_STACK_LINE(140)
		this->m_angularSpeed = 0.0;
		HX_STACK_LINE(142)
		::haxor::math::Vector3 _g7 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(142)
		this->m_accel = _g7;
		HX_STACK_LINE(143)
		::haxor::math::Vector3 _g8 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(143)
		this->m_torque = _g8;
		HX_STACK_LINE(145)
		this->m_hasForce = false;
		HX_STACK_LINE(146)
		this->m_hasTorque = false;
		HX_STACK_LINE(148)
		this->kinematic = false;
		HX_STACK_LINE(150)
		this->set_mass(1.0);
		HX_STACK_LINE(151)
		this->set_drag(0.0);
		HX_STACK_LINE(152)
		this->set_angularDrag(0.0);
		HX_STACK_LINE(155)
		this->gravity = true;
		HX_STACK_LINE(157)
		::haxor::math::Vector3 _g9 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(157)
		this->centerOfMass = _g9;
		HX_STACK_LINE(159)
		::haxor::context::EngineContext_obj::physics->CreateRigidBody(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


Void RigidBody_obj::AddTorque( ::haxor::math::Vector3 p_torque,::haxor::core::ForceMode p_mode){
{
		HX_STACK_FRAME("haxor.component.physics.RigidBody","AddTorque",0x6d9a8d46,"haxor.component.physics.RigidBody.AddTorque","haxor/component/physics/RigidBody.hx",168,0x9a85c9d8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_torque,"p_torque")
		HX_STACK_ARG(p_mode,"p_mode")
		HX_STACK_LINE(169)
		::haxor::core::ForceMode m;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(169)
		if (((p_mode == null()))){
			HX_STACK_LINE(169)
			m = ::haxor::core::ForceMode_obj::Force;
		}
		else{
			HX_STACK_LINE(169)
			m = p_mode;
		}
		HX_STACK_LINE(170)
		Float mdt = 1.0;		HX_STACK_VAR(mdt,"mdt");
		HX_STACK_LINE(171)
		Float dt = 1.0;		HX_STACK_VAR(dt,"dt");
		HX_STACK_LINE(172)
		::haxor::math::Vector3 v;		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(172)
		if (((p_mode == ::haxor::core::ForceMode_obj::Velocity))){
			HX_STACK_LINE(172)
			v = this->get_angularVelocity();
		}
		else{
			HX_STACK_LINE(172)
			v = this->m_torque;
		}
		HX_STACK_LINE(173)
		switch( (int)(m->__Index())){
			case (int)3: {
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(176)
				mdt = this->m_imass;
			}
			;break;
			case (int)0: {
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(178)
				mdt = this->m_imass;
			}
			;break;
		}
		HX_STACK_LINE(180)
		hx::AddEq(v->x,(p_torque->x * mdt));
		HX_STACK_LINE(181)
		hx::AddEq(v->y,(p_torque->y * mdt));
		HX_STACK_LINE(182)
		hx::AddEq(v->z,(p_torque->z * mdt));
		HX_STACK_LINE(183)
		this->m_hasTorque = (p_mode != ::haxor::core::ForceMode_obj::Velocity);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(RigidBody_obj,AddTorque,(void))

Void RigidBody_obj::AddForce( ::haxor::math::Vector3 p_force,::haxor::core::ForceMode p_mode){
{
		HX_STACK_FRAME("haxor.component.physics.RigidBody","AddForce",0x74e63eef,"haxor.component.physics.RigidBody.AddForce","haxor/component/physics/RigidBody.hx",192,0x9a85c9d8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_force,"p_force")
		HX_STACK_ARG(p_mode,"p_mode")
		HX_STACK_LINE(193)
		::haxor::core::ForceMode m;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(193)
		if (((p_mode == null()))){
			HX_STACK_LINE(193)
			m = ::haxor::core::ForceMode_obj::Force;
		}
		else{
			HX_STACK_LINE(193)
			m = p_mode;
		}
		HX_STACK_LINE(194)
		Float mdt = 1.0;		HX_STACK_VAR(mdt,"mdt");
		HX_STACK_LINE(195)
		Float dt = ::haxor::core::Time_obj::get_fixedDelta();		HX_STACK_VAR(dt,"dt");
		HX_STACK_LINE(196)
		::haxor::math::Vector3 v;		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(196)
		if (((p_mode == ::haxor::core::ForceMode_obj::Velocity))){
			HX_STACK_LINE(196)
			v = this->get_velocity();
		}
		else{
			HX_STACK_LINE(196)
			v = this->m_accel;
		}
		HX_STACK_LINE(197)
		switch( (int)(m->__Index())){
			case (int)3: {
				HX_STACK_LINE(199)
				mdt = dt;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(200)
				mdt = ((this->m_imass * dt) * dt);
			}
			;break;
			case (int)0: {
				HX_STACK_LINE(201)
				mdt = (dt * dt);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(202)
				mdt = (this->m_imass * dt);
			}
			;break;
		}
		HX_STACK_LINE(204)
		hx::AddEq(v->x,(p_force->x * mdt));
		HX_STACK_LINE(205)
		hx::AddEq(v->y,(p_force->y * mdt));
		HX_STACK_LINE(206)
		hx::AddEq(v->z,(p_force->z * mdt));
		HX_STACK_LINE(208)
		if (((p_mode == ::haxor::core::ForceMode_obj::Velocity))){
			HX_STACK_LINE(208)
			this->set_velocity(v);
		}
		HX_STACK_LINE(210)
		this->m_hasForce = (p_mode != ::haxor::core::ForceMode_obj::Velocity);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(RigidBody_obj,AddForce,(void))

Void RigidBody_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.component.physics.RigidBody","OnDestroy",0x1b168716,"haxor.component.physics.RigidBody.OnDestroy","haxor/component/physics/RigidBody.hx",214,0x9a85c9d8)
		HX_STACK_THIS(this)
	}
return null();
}


Void RigidBody_obj::ComputeForces( ){
{
		HX_STACK_FRAME("haxor.component.physics.RigidBody","ComputeForces",0xb310a5fa,"haxor.component.physics.RigidBody.ComputeForces","haxor/component/physics/RigidBody.hx",220,0x9a85c9d8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(221)
		if ((this->gravity)){
			HX_STACK_LINE(221)
			this->AddForce(::haxor::physics::Physics_obj::gravity,::haxor::core::ForceMode_obj::Velocity);
		}
		HX_STACK_LINE(223)
		Float _g = this->get_drag();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(223)
		if (((_g > 0.0))){
			HX_STACK_LINE(224)
			if (((this->m_speed > 0.0))){
				HX_STACK_LINE(226)
				Float _g1 = this->get_drag();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(226)
				Float _g2 = (-(this->m_velocity->x) * _g1);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(226)
				this->m_dragForce->x = _g2;
				HX_STACK_LINE(227)
				Float _g3 = this->get_drag();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(227)
				Float _g4 = (-(this->m_velocity->y) * _g3);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(227)
				this->m_dragForce->y = _g4;
				HX_STACK_LINE(228)
				Float _g5 = this->get_drag();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(228)
				Float _g6 = (-(this->m_velocity->z) * _g5);		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(228)
				this->m_dragForce->z = _g6;
				struct _Function_3_1{
					inline static Float Block( hx::ObjectPtr< ::haxor::component::physics::RigidBody_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",229,0x9a85c9d8)
						{
							HX_STACK_LINE(229)
							Float p_a = __this->m_dragForce->x;		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(229)
							return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
						}
						return null();
					}
				};
				HX_STACK_LINE(229)
				if (((_Function_3_1::Block(this) >= 0.0001))){
					HX_STACK_LINE(229)
					hx::AddEq(this->m_accel->x,this->m_dragForce->x);
					HX_STACK_LINE(229)
					this->m_hasForce = true;
				}
				struct _Function_3_2{
					inline static Float Block( hx::ObjectPtr< ::haxor::component::physics::RigidBody_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",230,0x9a85c9d8)
						{
							HX_STACK_LINE(230)
							Float p_a = __this->m_dragForce->y;		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(230)
							return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
						}
						return null();
					}
				};
				HX_STACK_LINE(230)
				if (((_Function_3_2::Block(this) >= 0.0001))){
					HX_STACK_LINE(230)
					hx::AddEq(this->m_accel->y,this->m_dragForce->y);
					HX_STACK_LINE(230)
					this->m_hasForce = true;
				}
				struct _Function_3_3{
					inline static Float Block( hx::ObjectPtr< ::haxor::component::physics::RigidBody_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",231,0x9a85c9d8)
						{
							HX_STACK_LINE(231)
							Float p_a = __this->m_dragForce->z;		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(231)
							return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
						}
						return null();
					}
				};
				HX_STACK_LINE(231)
				if (((_Function_3_3::Block(this) >= 0.0001))){
					HX_STACK_LINE(231)
					hx::AddEq(this->m_accel->z,this->m_dragForce->z);
					HX_STACK_LINE(231)
					this->m_hasForce = true;
				}
			}
		}
		HX_STACK_LINE(234)
		Float _g7 = this->get_angularDrag();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(234)
		if (((_g7 > 0.0))){
			HX_STACK_LINE(235)
			if (((this->m_angularSpeed > 0.0))){
				HX_STACK_LINE(237)
				Float _g8 = this->get_angularDrag();		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(237)
				Float _g9 = (-(this->m_angularVelocity->x) * _g8);		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(237)
				this->m_dragTorque->x = _g9;
				HX_STACK_LINE(238)
				Float _g10 = this->get_angularDrag();		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(238)
				Float _g11 = (-(this->m_angularVelocity->y) * _g10);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(238)
				this->m_dragTorque->y = _g11;
				HX_STACK_LINE(239)
				Float _g12 = this->get_angularDrag();		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(239)
				Float _g13 = (-(this->m_angularVelocity->z) * _g12);		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(239)
				this->m_dragTorque->z = _g13;
				struct _Function_3_1{
					inline static Float Block( hx::ObjectPtr< ::haxor::component::physics::RigidBody_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",240,0x9a85c9d8)
						{
							HX_STACK_LINE(240)
							Float p_a = __this->m_dragTorque->x;		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(240)
							return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
						}
						return null();
					}
				};
				HX_STACK_LINE(240)
				if (((_Function_3_1::Block(this) >= 0.0001))){
					HX_STACK_LINE(240)
					hx::AddEq(this->m_torque->x,this->m_dragTorque->x);
					HX_STACK_LINE(240)
					this->m_hasTorque = true;
				}
				struct _Function_3_2{
					inline static Float Block( hx::ObjectPtr< ::haxor::component::physics::RigidBody_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",241,0x9a85c9d8)
						{
							HX_STACK_LINE(241)
							Float p_a = __this->m_dragTorque->y;		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(241)
							return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
						}
						return null();
					}
				};
				HX_STACK_LINE(241)
				if (((_Function_3_2::Block(this) >= 0.0001))){
					HX_STACK_LINE(241)
					hx::AddEq(this->m_torque->y,this->m_dragTorque->y);
					HX_STACK_LINE(241)
					this->m_hasTorque = true;
				}
				struct _Function_3_3{
					inline static Float Block( hx::ObjectPtr< ::haxor::component::physics::RigidBody_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",242,0x9a85c9d8)
						{
							HX_STACK_LINE(242)
							Float p_a = __this->m_dragTorque->z;		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(242)
							return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
						}
						return null();
					}
				};
				HX_STACK_LINE(242)
				if (((_Function_3_3::Block(this) >= 0.0001))){
					HX_STACK_LINE(242)
					hx::AddEq(this->m_torque->z,this->m_dragTorque->z);
					HX_STACK_LINE(242)
					this->m_hasTorque = true;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(RigidBody_obj,ComputeForces,(void))

Void RigidBody_obj::IntegrateVelocity( Float p_dt){
{
		HX_STACK_FRAME("haxor.component.physics.RigidBody","IntegrateVelocity",0x55a99a29,"haxor.component.physics.RigidBody.IntegrateVelocity","haxor/component/physics/RigidBody.hx",247,0x9a85c9d8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_dt,"p_dt")
		HX_STACK_LINE(248)
		if ((this->kinematic)){
			HX_STACK_LINE(248)
			return null();
		}
		HX_STACK_LINE(250)
		Float dt = p_dt;		HX_STACK_VAR(dt,"dt");
		HX_STACK_LINE(252)
		if ((this->m_hasForce)){
			HX_STACK_LINE(254)
			::haxor::math::Vector3 v = this->get_velocity();		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(255)
			hx::AddEq(v->x,(this->m_accel->x * dt));
			HX_STACK_LINE(256)
			hx::AddEq(v->y,(this->m_accel->y * dt));
			HX_STACK_LINE(257)
			hx::AddEq(v->z,(this->m_accel->z * dt));
			HX_STACK_LINE(258)
			this->set_velocity(v);
		}
		HX_STACK_LINE(261)
		if ((!(this->m_hasForce))){
			HX_STACK_LINE(262)
			if (((this->m_speed <= 0.14))){
			}
		}
		HX_STACK_LINE(267)
		if ((this->m_hasTorque)){
			HX_STACK_LINE(269)
			::haxor::math::Vector3 v = this->get_angularVelocity();		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(270)
			hx::AddEq(v->x,(this->m_torque->x * dt));
			HX_STACK_LINE(271)
			hx::AddEq(v->y,(this->m_torque->y * dt));
			HX_STACK_LINE(272)
			hx::AddEq(v->z,(this->m_torque->z * dt));
			HX_STACK_LINE(273)
			this->set_angularVelocity(v);
		}
		HX_STACK_LINE(276)
		if ((!(this->m_hasTorque))){
			HX_STACK_LINE(277)
			if (((this->m_angularSpeed <= 0.0024434609527920616))){
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RigidBody_obj,IntegrateVelocity,(void))

Void RigidBody_obj::IntegratePosition( Float p_dt){
{
		HX_STACK_FRAME("haxor.component.physics.RigidBody","IntegratePosition",0x01a638b5,"haxor.component.physics.RigidBody.IntegratePosition","haxor/component/physics/RigidBody.hx",285,0x9a85c9d8)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_dt,"p_dt")
		HX_STACK_LINE(286)
		bool integrate_position = true;		HX_STACK_VAR(integrate_position,"integrate_position");
		HX_STACK_LINE(287)
		Float dt = p_dt;		HX_STACK_VAR(dt,"dt");
		struct _Function_1_1{
			inline static Float Block( hx::ObjectPtr< ::haxor::component::physics::RigidBody_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",289,0x9a85c9d8)
				{
					HX_STACK_LINE(289)
					Float p_a = __this->m_velocity->x;		HX_STACK_VAR(p_a,"p_a");
					HX_STACK_LINE(289)
					return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
				}
				return null();
			}
		};
		HX_STACK_LINE(289)
		if (((_Function_1_1::Block(this) < 0.0001))){
			struct _Function_2_1{
				inline static Float Block( hx::ObjectPtr< ::haxor::component::physics::RigidBody_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",290,0x9a85c9d8)
					{
						HX_STACK_LINE(290)
						Float p_a = __this->m_velocity->y;		HX_STACK_VAR(p_a,"p_a");
						HX_STACK_LINE(290)
						return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
					}
					return null();
				}
			};
			HX_STACK_LINE(290)
			if (((_Function_2_1::Block(this) < 0.0001))){
				struct _Function_3_1{
					inline static Float Block( hx::ObjectPtr< ::haxor::component::physics::RigidBody_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",291,0x9a85c9d8)
						{
							HX_STACK_LINE(291)
							Float p_a = __this->m_velocity->z;		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(291)
							return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
						}
						return null();
					}
				};
				HX_STACK_LINE(291)
				if (((_Function_3_1::Block(this) < 0.0001))){
					HX_STACK_LINE(291)
					integrate_position = false;
				}
			}
		}
		HX_STACK_LINE(294)
		if ((integrate_position)){
			HX_STACK_LINE(296)
			::haxor::math::Vector3 p = this->m_entity->m_transform->get_localPosition();		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(297)
			hx::AddEq(p->x,(this->m_velocity->x * dt));
			HX_STACK_LINE(298)
			hx::AddEq(p->y,(this->m_velocity->y * dt));
			HX_STACK_LINE(299)
			hx::AddEq(p->z,(this->m_velocity->z * dt));
			HX_STACK_LINE(300)
			this->m_entity->m_transform->set_localPosition(p);
		}
		HX_STACK_LINE(303)
		bool integrate_rotation = false;		HX_STACK_VAR(integrate_rotation,"integrate_rotation");
		struct _Function_1_2{
			inline static Float Block( hx::ObjectPtr< ::haxor::component::physics::RigidBody_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",305,0x9a85c9d8)
				{
					HX_STACK_LINE(305)
					Float p_a = __this->m_angularVelocity->x;		HX_STACK_VAR(p_a,"p_a");
					HX_STACK_LINE(305)
					return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
				}
				return null();
			}
		};
		HX_STACK_LINE(305)
		if (((_Function_1_2::Block(this) < 0.0001))){
			struct _Function_2_1{
				inline static Float Block( hx::ObjectPtr< ::haxor::component::physics::RigidBody_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",306,0x9a85c9d8)
					{
						HX_STACK_LINE(306)
						Float p_a = __this->m_angularVelocity->y;		HX_STACK_VAR(p_a,"p_a");
						HX_STACK_LINE(306)
						return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
					}
					return null();
				}
			};
			HX_STACK_LINE(306)
			if (((_Function_2_1::Block(this) < 0.0001))){
				struct _Function_3_1{
					inline static Float Block( hx::ObjectPtr< ::haxor::component::physics::RigidBody_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/physics/RigidBody.hx",307,0x9a85c9d8)
						{
							HX_STACK_LINE(307)
							Float p_a = __this->m_angularVelocity->z;		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(307)
							return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
						}
						return null();
					}
				};
				HX_STACK_LINE(307)
				if (((_Function_3_1::Block(this) < 0.0001))){
					HX_STACK_LINE(307)
					integrate_rotation = false;
				}
			}
		}
		HX_STACK_LINE(310)
		if ((integrate_rotation)){
			HX_STACK_LINE(312)
			::haxor::math::Quaternion r = this->m_entity->m_transform->get_localRotation();		HX_STACK_VAR(r,"r");
			HX_STACK_LINE(313)
			this->m_avq->Set(this->m_angularVelocity->x,this->m_angularVelocity->y,this->m_angularVelocity->z,0.0);
			HX_STACK_LINE(314)
			this->m_avq->Multiply(r,false);
			HX_STACK_LINE(315)
			this->m_avq->Scale(0.25);
			HX_STACK_LINE(316)
			hx::AddEq(r->x,(this->m_avq->x * dt));
			HX_STACK_LINE(317)
			hx::AddEq(r->y,(this->m_avq->y * dt));
			HX_STACK_LINE(318)
			hx::AddEq(r->z,(this->m_avq->z * dt));
			HX_STACK_LINE(319)
			hx::AddEq(r->w,(this->m_avq->w * dt));
			HX_STACK_LINE(320)
			r->Normalize();
			HX_STACK_LINE(321)
			this->m_entity->m_transform->set_localRotation(r);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RigidBody_obj,IntegratePosition,(void))

Void RigidBody_obj::ResetForces( ){
{
		HX_STACK_FRAME("haxor.component.physics.RigidBody","ResetForces",0x7a48b592,"haxor.component.physics.RigidBody.ResetForces","haxor/component/physics/RigidBody.hx",329,0x9a85c9d8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(330)
		this->m_accel->x = (int)0;
		HX_STACK_LINE(331)
		this->m_accel->y = (int)0;
		HX_STACK_LINE(332)
		this->m_accel->z = (int)0;
		HX_STACK_LINE(333)
		this->m_hasForce = false;
		HX_STACK_LINE(334)
		this->m_torque->x = (int)0;
		HX_STACK_LINE(335)
		this->m_torque->y = (int)0;
		HX_STACK_LINE(336)
		this->m_torque->z = (int)0;
		HX_STACK_LINE(337)
		this->m_hasTorque = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(RigidBody_obj,ResetForces,(void))


RigidBody_obj::RigidBody_obj()
{
}

void RigidBody_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RigidBody);
	HX_MARK_MEMBER_NAME(m_velocity,"m_velocity");
	HX_MARK_MEMBER_NAME(m_direction,"m_direction");
	HX_MARK_MEMBER_NAME(m_dragForce,"m_dragForce");
	HX_MARK_MEMBER_NAME(m_speed,"m_speed");
	HX_MARK_MEMBER_NAME(m_angularVelocity,"m_angularVelocity");
	HX_MARK_MEMBER_NAME(m_angularDirection,"m_angularDirection");
	HX_MARK_MEMBER_NAME(m_dragTorque,"m_dragTorque");
	HX_MARK_MEMBER_NAME(m_angularSpeed,"m_angularSpeed");
	HX_MARK_MEMBER_NAME(gravity,"gravity");
	HX_MARK_MEMBER_NAME(m_drag,"m_drag");
	HX_MARK_MEMBER_NAME(m_idrag,"m_idrag");
	HX_MARK_MEMBER_NAME(m_angularDrag,"m_angularDrag");
	HX_MARK_MEMBER_NAME(m_iangularDrag,"m_iangularDrag");
	HX_MARK_MEMBER_NAME(m_mass,"m_mass");
	HX_MARK_MEMBER_NAME(m_imass,"m_imass");
	HX_MARK_MEMBER_NAME(centerOfMass,"centerOfMass");
	HX_MARK_MEMBER_NAME(kinematic,"kinematic");
	HX_MARK_MEMBER_NAME(m_accel,"m_accel");
	HX_MARK_MEMBER_NAME(m_torque,"m_torque");
	HX_MARK_MEMBER_NAME(m_hasForce,"m_hasForce");
	HX_MARK_MEMBER_NAME(m_hasTorque,"m_hasTorque");
	HX_MARK_MEMBER_NAME(m_avq,"m_avq");
	::haxor::component::Component_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void RigidBody_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_velocity,"m_velocity");
	HX_VISIT_MEMBER_NAME(m_direction,"m_direction");
	HX_VISIT_MEMBER_NAME(m_dragForce,"m_dragForce");
	HX_VISIT_MEMBER_NAME(m_speed,"m_speed");
	HX_VISIT_MEMBER_NAME(m_angularVelocity,"m_angularVelocity");
	HX_VISIT_MEMBER_NAME(m_angularDirection,"m_angularDirection");
	HX_VISIT_MEMBER_NAME(m_dragTorque,"m_dragTorque");
	HX_VISIT_MEMBER_NAME(m_angularSpeed,"m_angularSpeed");
	HX_VISIT_MEMBER_NAME(gravity,"gravity");
	HX_VISIT_MEMBER_NAME(m_drag,"m_drag");
	HX_VISIT_MEMBER_NAME(m_idrag,"m_idrag");
	HX_VISIT_MEMBER_NAME(m_angularDrag,"m_angularDrag");
	HX_VISIT_MEMBER_NAME(m_iangularDrag,"m_iangularDrag");
	HX_VISIT_MEMBER_NAME(m_mass,"m_mass");
	HX_VISIT_MEMBER_NAME(m_imass,"m_imass");
	HX_VISIT_MEMBER_NAME(centerOfMass,"centerOfMass");
	HX_VISIT_MEMBER_NAME(kinematic,"kinematic");
	HX_VISIT_MEMBER_NAME(m_accel,"m_accel");
	HX_VISIT_MEMBER_NAME(m_torque,"m_torque");
	HX_VISIT_MEMBER_NAME(m_hasForce,"m_hasForce");
	HX_VISIT_MEMBER_NAME(m_hasTorque,"m_hasTorque");
	HX_VISIT_MEMBER_NAME(m_avq,"m_avq");
	::haxor::component::Component_obj::__Visit(HX_VISIT_ARG);
}

Dynamic RigidBody_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"drag") ) { return get_drag(); }
		if (HX_FIELD_EQ(inName,"mass") ) { return get_mass(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_avq") ) { return m_avq; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_drag") ) { return m_drag; }
		if (HX_FIELD_EQ(inName,"m_mass") ) { return m_mass; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_speed") ) { return m_speed; }
		if (HX_FIELD_EQ(inName,"gravity") ) { return gravity; }
		if (HX_FIELD_EQ(inName,"m_idrag") ) { return m_idrag; }
		if (HX_FIELD_EQ(inName,"m_imass") ) { return m_imass; }
		if (HX_FIELD_EQ(inName,"m_accel") ) { return m_accel; }
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"velocity") ) { return get_velocity(); }
		if (HX_FIELD_EQ(inName,"get_drag") ) { return get_drag_dyn(); }
		if (HX_FIELD_EQ(inName,"set_drag") ) { return set_drag_dyn(); }
		if (HX_FIELD_EQ(inName,"get_mass") ) { return get_mass_dyn(); }
		if (HX_FIELD_EQ(inName,"set_mass") ) { return set_mass_dyn(); }
		if (HX_FIELD_EQ(inName,"m_torque") ) { return m_torque; }
		if (HX_FIELD_EQ(inName,"AddForce") ) { return AddForce_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"kinematic") ) { return kinematic; }
		if (HX_FIELD_EQ(inName,"AddTorque") ) { return AddTorque_dyn(); }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_velocity") ) { return m_velocity; }
		if (HX_FIELD_EQ(inName,"m_hasForce") ) { return m_hasForce; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_direction") ) { return m_direction; }
		if (HX_FIELD_EQ(inName,"m_dragForce") ) { return m_dragForce; }
		if (HX_FIELD_EQ(inName,"angularDrag") ) { return get_angularDrag(); }
		if (HX_FIELD_EQ(inName,"m_hasTorque") ) { return m_hasTorque; }
		if (HX_FIELD_EQ(inName,"ResetForces") ) { return ResetForces_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_velocity") ) { return get_velocity_dyn(); }
		if (HX_FIELD_EQ(inName,"set_velocity") ) { return set_velocity_dyn(); }
		if (HX_FIELD_EQ(inName,"m_dragTorque") ) { return m_dragTorque; }
		if (HX_FIELD_EQ(inName,"centerOfMass") ) { return centerOfMass; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_angularDrag") ) { return m_angularDrag; }
		if (HX_FIELD_EQ(inName,"ComputeForces") ) { return ComputeForces_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_angularSpeed") ) { return m_angularSpeed; }
		if (HX_FIELD_EQ(inName,"m_iangularDrag") ) { return m_iangularDrag; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"angularVelocity") ) { return get_angularVelocity(); }
		if (HX_FIELD_EQ(inName,"get_angularDrag") ) { return get_angularDrag_dyn(); }
		if (HX_FIELD_EQ(inName,"set_angularDrag") ) { return set_angularDrag_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_angularVelocity") ) { return m_angularVelocity; }
		if (HX_FIELD_EQ(inName,"IntegrateVelocity") ) { return IntegrateVelocity_dyn(); }
		if (HX_FIELD_EQ(inName,"IntegratePosition") ) { return IntegratePosition_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_angularDirection") ) { return m_angularDirection; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_angularVelocity") ) { return get_angularVelocity_dyn(); }
		if (HX_FIELD_EQ(inName,"set_angularVelocity") ) { return set_angularVelocity_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RigidBody_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"drag") ) { return set_drag(inValue); }
		if (HX_FIELD_EQ(inName,"mass") ) { return set_mass(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_avq") ) { m_avq=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_drag") ) { m_drag=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_mass") ) { m_mass=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_speed") ) { m_speed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gravity") ) { gravity=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_idrag") ) { m_idrag=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_imass") ) { m_imass=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_accel") ) { m_accel=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"velocity") ) { return set_velocity(inValue); }
		if (HX_FIELD_EQ(inName,"m_torque") ) { m_torque=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"kinematic") ) { kinematic=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_velocity") ) { m_velocity=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_hasForce") ) { m_hasForce=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_direction") ) { m_direction=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_dragForce") ) { m_dragForce=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angularDrag") ) { return set_angularDrag(inValue); }
		if (HX_FIELD_EQ(inName,"m_hasTorque") ) { m_hasTorque=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_dragTorque") ) { m_dragTorque=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"centerOfMass") ) { centerOfMass=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_angularDrag") ) { m_angularDrag=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_angularSpeed") ) { m_angularSpeed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_iangularDrag") ) { m_iangularDrag=inValue.Cast< Float >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"angularVelocity") ) { return set_angularVelocity(inValue); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"m_angularVelocity") ) { m_angularVelocity=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_angularDirection") ) { m_angularDirection=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RigidBody_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("velocity"));
	outFields->push(HX_CSTRING("m_velocity"));
	outFields->push(HX_CSTRING("m_direction"));
	outFields->push(HX_CSTRING("m_dragForce"));
	outFields->push(HX_CSTRING("m_speed"));
	outFields->push(HX_CSTRING("angularVelocity"));
	outFields->push(HX_CSTRING("m_angularVelocity"));
	outFields->push(HX_CSTRING("m_angularDirection"));
	outFields->push(HX_CSTRING("m_dragTorque"));
	outFields->push(HX_CSTRING("m_angularSpeed"));
	outFields->push(HX_CSTRING("gravity"));
	outFields->push(HX_CSTRING("drag"));
	outFields->push(HX_CSTRING("m_drag"));
	outFields->push(HX_CSTRING("m_idrag"));
	outFields->push(HX_CSTRING("angularDrag"));
	outFields->push(HX_CSTRING("m_angularDrag"));
	outFields->push(HX_CSTRING("m_iangularDrag"));
	outFields->push(HX_CSTRING("mass"));
	outFields->push(HX_CSTRING("m_mass"));
	outFields->push(HX_CSTRING("m_imass"));
	outFields->push(HX_CSTRING("centerOfMass"));
	outFields->push(HX_CSTRING("kinematic"));
	outFields->push(HX_CSTRING("m_accel"));
	outFields->push(HX_CSTRING("m_torque"));
	outFields->push(HX_CSTRING("m_hasForce"));
	outFields->push(HX_CSTRING("m_hasTorque"));
	outFields->push(HX_CSTRING("m_avq"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(RigidBody_obj,m_velocity),HX_CSTRING("m_velocity")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(RigidBody_obj,m_direction),HX_CSTRING("m_direction")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(RigidBody_obj,m_dragForce),HX_CSTRING("m_dragForce")},
	{hx::fsFloat,(int)offsetof(RigidBody_obj,m_speed),HX_CSTRING("m_speed")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(RigidBody_obj,m_angularVelocity),HX_CSTRING("m_angularVelocity")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(RigidBody_obj,m_angularDirection),HX_CSTRING("m_angularDirection")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(RigidBody_obj,m_dragTorque),HX_CSTRING("m_dragTorque")},
	{hx::fsFloat,(int)offsetof(RigidBody_obj,m_angularSpeed),HX_CSTRING("m_angularSpeed")},
	{hx::fsBool,(int)offsetof(RigidBody_obj,gravity),HX_CSTRING("gravity")},
	{hx::fsFloat,(int)offsetof(RigidBody_obj,m_drag),HX_CSTRING("m_drag")},
	{hx::fsFloat,(int)offsetof(RigidBody_obj,m_idrag),HX_CSTRING("m_idrag")},
	{hx::fsFloat,(int)offsetof(RigidBody_obj,m_angularDrag),HX_CSTRING("m_angularDrag")},
	{hx::fsFloat,(int)offsetof(RigidBody_obj,m_iangularDrag),HX_CSTRING("m_iangularDrag")},
	{hx::fsFloat,(int)offsetof(RigidBody_obj,m_mass),HX_CSTRING("m_mass")},
	{hx::fsFloat,(int)offsetof(RigidBody_obj,m_imass),HX_CSTRING("m_imass")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(RigidBody_obj,centerOfMass),HX_CSTRING("centerOfMass")},
	{hx::fsBool,(int)offsetof(RigidBody_obj,kinematic),HX_CSTRING("kinematic")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(RigidBody_obj,m_accel),HX_CSTRING("m_accel")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(RigidBody_obj,m_torque),HX_CSTRING("m_torque")},
	{hx::fsBool,(int)offsetof(RigidBody_obj,m_hasForce),HX_CSTRING("m_hasForce")},
	{hx::fsBool,(int)offsetof(RigidBody_obj,m_hasTorque),HX_CSTRING("m_hasTorque")},
	{hx::fsObject /*::haxor::math::Quaternion*/ ,(int)offsetof(RigidBody_obj,m_avq),HX_CSTRING("m_avq")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_velocity"),
	HX_CSTRING("set_velocity"),
	HX_CSTRING("m_velocity"),
	HX_CSTRING("m_direction"),
	HX_CSTRING("m_dragForce"),
	HX_CSTRING("m_speed"),
	HX_CSTRING("get_angularVelocity"),
	HX_CSTRING("set_angularVelocity"),
	HX_CSTRING("m_angularVelocity"),
	HX_CSTRING("m_angularDirection"),
	HX_CSTRING("m_dragTorque"),
	HX_CSTRING("m_angularSpeed"),
	HX_CSTRING("gravity"),
	HX_CSTRING("get_drag"),
	HX_CSTRING("set_drag"),
	HX_CSTRING("m_drag"),
	HX_CSTRING("m_idrag"),
	HX_CSTRING("get_angularDrag"),
	HX_CSTRING("set_angularDrag"),
	HX_CSTRING("m_angularDrag"),
	HX_CSTRING("m_iangularDrag"),
	HX_CSTRING("get_mass"),
	HX_CSTRING("set_mass"),
	HX_CSTRING("m_mass"),
	HX_CSTRING("m_imass"),
	HX_CSTRING("centerOfMass"),
	HX_CSTRING("kinematic"),
	HX_CSTRING("m_accel"),
	HX_CSTRING("m_torque"),
	HX_CSTRING("m_hasForce"),
	HX_CSTRING("m_hasTorque"),
	HX_CSTRING("m_avq"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("AddTorque"),
	HX_CSTRING("AddForce"),
	HX_CSTRING("OnDestroy"),
	HX_CSTRING("ComputeForces"),
	HX_CSTRING("IntegrateVelocity"),
	HX_CSTRING("IntegratePosition"),
	HX_CSTRING("ResetForces"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RigidBody_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RigidBody_obj::__mClass,"__mClass");
};

#endif

Class RigidBody_obj::__mClass;

void RigidBody_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.physics.RigidBody"), hx::TCanCast< RigidBody_obj> ,sStaticFields,sMemberFields,
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

void RigidBody_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
} // end namespace physics
