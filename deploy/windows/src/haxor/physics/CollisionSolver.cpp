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
#ifndef INCLUDED_haxor_component_physics_BoxCollider
#include <haxor/component/physics/BoxCollider.h>
#endif
#ifndef INCLUDED_haxor_component_physics_Collider
#include <haxor/component/physics/Collider.h>
#endif
#ifndef INCLUDED_haxor_component_physics_RigidBody
#include <haxor/component/physics/RigidBody.h>
#endif
#ifndef INCLUDED_haxor_component_physics_SphereCollider
#include <haxor/component/physics/SphereCollider.h>
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
#ifndef INCLUDED_haxor_core_ColliderType
#include <haxor/core/ColliderType.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
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
#ifndef INCLUDED_haxor_ds_IUSetItem
#include <haxor/ds/IUSetItem.h>
#endif
#ifndef INCLUDED_haxor_ds_USet
#include <haxor/ds/USet.h>
#endif
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_physics_Collision
#include <haxor/physics/Collision.h>
#endif
#ifndef INCLUDED_haxor_physics_CollisionSolver
#include <haxor/physics/CollisionSolver.h>
#endif
#ifndef INCLUDED_haxor_physics_PhysicsMaterial
#include <haxor/physics/PhysicsMaterial.h>
#endif
#ifndef INCLUDED_haxor_physics_broadphase_BroadPhase
#include <haxor/physics/broadphase/BroadPhase.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace physics{

Void CollisionSolver_obj::__construct()
{
HX_STACK_FRAME("haxor.physics.CollisionSolver","new",0xd66d4424,"haxor.physics.CollisionSolver.new","haxor/physics/CollisionSolver.hx",42,0x478b5d4e)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(42)
	this->iterations = (int)3;
}
;
	return null();
}

//CollisionSolver_obj::~CollisionSolver_obj() { }

Dynamic CollisionSolver_obj::__CreateEmpty() { return  new CollisionSolver_obj; }
hx::ObjectPtr< CollisionSolver_obj > CollisionSolver_obj::__new()
{  hx::ObjectPtr< CollisionSolver_obj > result = new CollisionSolver_obj();
	result->__construct();
	return result;}

Dynamic CollisionSolver_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CollisionSolver_obj > result = new CollisionSolver_obj();
	result->__construct();
	return result;}

Void CollisionSolver_obj::Step( ){
{
		HX_STACK_FRAME("haxor.physics.CollisionSolver","Step",0xb760eb28,"haxor.physics.CollisionSolver.Step","haxor/physics/CollisionSolver.hx",50,0x478b5d4e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(51)
		::haxor::ds::USet l = this->broadphase->pairs;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(52)
		::haxor::physics::Collision c;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(54)
			int _g = this->iterations;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(54)
			while((true)){
				HX_STACK_LINE(54)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(54)
					break;
				}
				HX_STACK_LINE(54)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(55)
				int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(55)
				int _g2 = l->get_length();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(55)
				while((true)){
					HX_STACK_LINE(55)
					if ((!(((_g3 < _g2))))){
						HX_STACK_LINE(55)
						break;
					}
					HX_STACK_LINE(55)
					int j = (_g3)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(57)
					::haxor::physics::Collision _g4 = l->Get(j);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(57)
					c = _g4;
					HX_STACK_LINE(58)
					this->Solve(c);
					HX_STACK_LINE(59)
					this->Apply(c);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CollisionSolver_obj,Step,(void))

Void CollisionSolver_obj::Solve( ::haxor::physics::Collision c){
{
		HX_STACK_FRAME("haxor.physics.CollisionSolver","Solve",0xba241c23,"haxor.physics.CollisionSolver.Solve","haxor/physics/CollisionSolver.hx",69,0x478b5d4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(70)
		::haxor::component::physics::Collider ca = c->from;		HX_STACK_VAR(ca,"ca");
		HX_STACK_LINE(71)
		::haxor::component::physics::Collider cb = c->to;		HX_STACK_VAR(cb,"cb");
		HX_STACK_LINE(72)
		::haxor::core::ColliderType ta = ca->get_type();		HX_STACK_VAR(ta,"ta");
		HX_STACK_LINE(73)
		::haxor::core::ColliderType tb = cb->get_type();		HX_STACK_VAR(tb,"tb");
		HX_STACK_LINE(74)
		if (((ta == ::haxor::core::ColliderType_obj::Box))){
			HX_STACK_LINE(74)
			if (((tb == ::haxor::core::ColliderType_obj::Box))){
				HX_STACK_LINE(74)
				this->SolveBoxBox(ca,cb,c);
				HX_STACK_LINE(74)
				return null();
			}
		}
		HX_STACK_LINE(75)
		if (((ta == ::haxor::core::ColliderType_obj::Sphere))){
			HX_STACK_LINE(75)
			if (((tb == ::haxor::core::ColliderType_obj::Box))){
				HX_STACK_LINE(75)
				this->SolveSphereBox(ca,cb,c);
				HX_STACK_LINE(75)
				return null();
			}
		}
		HX_STACK_LINE(76)
		if (((ta == ::haxor::core::ColliderType_obj::Box))){
			HX_STACK_LINE(76)
			if (((tb == ::haxor::core::ColliderType_obj::Sphere))){
				HX_STACK_LINE(76)
				this->SolveSphereBox(cb,ca,c);
				HX_STACK_LINE(76)
				return null();
			}
		}
		HX_STACK_LINE(77)
		if (((ta == ::haxor::core::ColliderType_obj::Sphere))){
			HX_STACK_LINE(77)
			if (((tb == ::haxor::core::ColliderType_obj::Sphere))){
				HX_STACK_LINE(77)
				this->SolveSphereSphere(ca,cb,c);
				HX_STACK_LINE(77)
				return null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CollisionSolver_obj,Solve,(void))

Void CollisionSolver_obj::Apply( ::haxor::physics::Collision c){
{
		HX_STACK_FRAME("haxor.physics.CollisionSolver","Apply",0x5d99e212,"haxor.physics.CollisionSolver.Apply","haxor/physics/CollisionSolver.hx",85,0x478b5d4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(86)
		::haxor::component::physics::Collider ca = c->from;		HX_STACK_VAR(ca,"ca");
		HX_STACK_LINE(87)
		::haxor::component::physics::Collider cb = c->to;		HX_STACK_VAR(cb,"cb");
		HX_STACK_LINE(89)
		::haxor::component::physics::RigidBody ra = ::haxor::context::EngineContext_obj::physics->crb->__get(ca->__cid).StaticCast< ::haxor::component::physics::RigidBody >();		HX_STACK_VAR(ra,"ra");
		HX_STACK_LINE(90)
		::haxor::component::physics::RigidBody rb = ::haxor::context::EngineContext_obj::physics->crb->__get(cb->__cid).StaticCast< ::haxor::component::physics::RigidBody >();		HX_STACK_VAR(rb,"rb");
		HX_STACK_LINE(92)
		Float ma;		HX_STACK_VAR(ma,"ma");
		HX_STACK_LINE(92)
		if (((ra == null()))){
			HX_STACK_LINE(92)
			ma = 0.0;
		}
		else{
			HX_STACK_LINE(92)
			ma = ra->get_mass();
		}
		HX_STACK_LINE(93)
		Float mb;		HX_STACK_VAR(mb,"mb");
		HX_STACK_LINE(93)
		if (((rb == null()))){
			HX_STACK_LINE(93)
			mb = 0.0;
		}
		else{
			HX_STACK_LINE(93)
			mb = rb->get_mass();
		}
		HX_STACK_LINE(94)
		Float sum;		HX_STACK_VAR(sum,"sum");
		HX_STACK_LINE(94)
		if ((((ma + mb) <= 0.0))){
			HX_STACK_LINE(94)
			sum = 0.0;
		}
		else{
			HX_STACK_LINE(94)
			sum = (Float(1.0) / Float(((ma + mb))));
		}
		HX_STACK_LINE(95)
		Float ar;		HX_STACK_VAR(ar,"ar");
		HX_STACK_LINE(95)
		if (((ra == null()))){
			HX_STACK_LINE(95)
			ar = 0.0;
		}
		else{
			HX_STACK_LINE(95)
			ar = (ma * sum);
		}
		HX_STACK_LINE(96)
		Float br;		HX_STACK_VAR(br,"br");
		HX_STACK_LINE(96)
		if (((rb == null()))){
			HX_STACK_LINE(96)
			br = 0.0;
		}
		else{
			HX_STACK_LINE(96)
			br = (mb * sum);
		}
		HX_STACK_LINE(98)
		if (((ra != null()))){
			HX_STACK_LINE(98)
			this->Resolve(ra,c,ar);
		}
		HX_STACK_LINE(98)
		c->Invert();
		HX_STACK_LINE(99)
		if (((rb != null()))){
			HX_STACK_LINE(99)
			this->Resolve(rb,c,br);
		}
		HX_STACK_LINE(99)
		c->Invert();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CollisionSolver_obj,Apply,(void))

Void CollisionSolver_obj::Resolve( ::haxor::component::physics::RigidBody rb,::haxor::physics::Collision c,Float ratio){
{
		HX_STACK_FRAME("haxor.physics.CollisionSolver","Resolve",0x7a89e090,"haxor.physics.CollisionSolver.Resolve","haxor/physics/CollisionSolver.hx",109,0x478b5d4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(rb,"rb")
		HX_STACK_ARG(c,"c")
		HX_STACK_ARG(ratio,"ratio")
		HX_STACK_LINE(110)
		Float rv;		HX_STACK_VAR(rv,"rv");
		HX_STACK_LINE(110)
		{
			HX_STACK_LINE(110)
			::haxor::math::Vector3 p_a = c->normal;		HX_STACK_VAR(p_a,"p_a");
			HX_STACK_LINE(110)
			::haxor::math::Vector3 p_b = rb->get_velocity();		HX_STACK_VAR(p_b,"p_b");
			HX_STACK_LINE(110)
			rv = (((p_a->x * p_b->x) + (p_a->y * p_b->y)) + (p_a->z * p_b->z));
		}
		HX_STACK_LINE(111)
		c->speed = rv;
		HX_STACK_LINE(113)
		::haxor::component::physics::Collider ca = c->from;		HX_STACK_VAR(ca,"ca");
		HX_STACK_LINE(114)
		::haxor::component::physics::Collider cb = c->to;		HX_STACK_VAR(cb,"cb");
		HX_STACK_LINE(116)
		bool need_impulse = !(((bool(ca->trigger) || bool(cb->trigger))));		HX_STACK_VAR(need_impulse,"need_impulse");
		HX_STACK_LINE(118)
		if ((!(rb->kinematic))){
			HX_STACK_LINE(119)
			if ((need_impulse)){
				HX_STACK_LINE(120)
				if (((c->depth < 0.0))){
					HX_STACK_LINE(124)
					::haxor::physics::PhysicsMaterial m0 = ca->material;		HX_STACK_VAR(m0,"m0");
					HX_STACK_LINE(124)
					::haxor::physics::PhysicsMaterial _g;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(124)
					if (((m0 == null()))){
						HX_STACK_LINE(124)
						_g = ::haxor::physics::PhysicsMaterial_obj::get_empty();
					}
					else{
						HX_STACK_LINE(124)
						_g = m0;
					}
					HX_STACK_LINE(124)
					m0 = _g;
					HX_STACK_LINE(125)
					::haxor::physics::PhysicsMaterial m1 = cb->material;		HX_STACK_VAR(m1,"m1");
					HX_STACK_LINE(125)
					::haxor::physics::PhysicsMaterial _g1;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(125)
					if (((m1 == null()))){
						HX_STACK_LINE(125)
						_g1 = ::haxor::physics::PhysicsMaterial_obj::get_empty();
					}
					else{
						HX_STACK_LINE(125)
						_g1 = m1;
					}
					HX_STACK_LINE(125)
					m1 = _g1;
					HX_STACK_LINE(126)
					Float bf = (((m0->bounce + m1->bounce)) * 0.5);		HX_STACK_VAR(bf,"bf");
					HX_STACK_LINE(127)
					Float restitution = bf;		HX_STACK_VAR(restitution,"restitution");
					HX_STACK_LINE(129)
					if (((rv < 0.0))){
						HX_STACK_LINE(131)
						Float _g2;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(131)
						{
							HX_STACK_LINE(131)
							::haxor::math::Vector3 p_a = rb->get_velocity();		HX_STACK_VAR(p_a,"p_a");
							HX_STACK_LINE(131)
							::haxor::math::Vector3 p_b = c->normal;		HX_STACK_VAR(p_b,"p_b");
							HX_STACK_LINE(131)
							_g2 = (((p_a->x * p_b->x) + (p_a->y * p_b->y)) + (p_a->z * p_b->z));
						}
						HX_STACK_LINE(131)
						Float impulse_v = (-(((1.0 + restitution))) * _g2);		HX_STACK_VAR(impulse_v,"impulse_v");
						HX_STACK_LINE(133)
						::haxor::math::Vector3 v = rb->get_velocity();		HX_STACK_VAR(v,"v");
						HX_STACK_LINE(134)
						hx::AddEq(v->x,(c->normal->x * impulse_v));
						HX_STACK_LINE(135)
						hx::AddEq(v->y,(c->normal->y * impulse_v));
						HX_STACK_LINE(136)
						hx::AddEq(v->z,(c->normal->z * impulse_v));
						HX_STACK_LINE(137)
						rb->set_velocity(v);
						HX_STACK_LINE(140)
						Float _g3 = ::haxor::core::Time_obj::get_fixedDelta();		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(140)
						Float correction = ((c->depth * -0.9) * _g3);		HX_STACK_VAR(correction,"correction");
						HX_STACK_LINE(141)
						::haxor::math::Vector3 cm = rb->m_entity->m_transform->get_localPosition();		HX_STACK_VAR(cm,"cm");
						HX_STACK_LINE(142)
						hx::AddEq(cm->x,(c->normal->x * correction));
						HX_STACK_LINE(143)
						hx::AddEq(cm->y,(c->normal->y * correction));
						HX_STACK_LINE(144)
						hx::AddEq(cm->z,(c->normal->z * correction));
						HX_STACK_LINE(145)
						rb->m_entity->m_transform->set_localPosition(cm);
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CollisionSolver_obj,Resolve,(void))

Void CollisionSolver_obj::SolveBoxBox( ::haxor::component::physics::BoxCollider ca,::haxor::component::physics::BoxCollider cb,::haxor::physics::Collision c){
{
		HX_STACK_FRAME("haxor.physics.CollisionSolver","SolveBoxBox",0x921c9d43,"haxor.physics.CollisionSolver.SolveBoxBox","haxor/physics/CollisionSolver.hx",157,0x478b5d4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ca,"ca")
		HX_STACK_ARG(cb,"cb")
		HX_STACK_ARG(c,"c")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CollisionSolver_obj,SolveBoxBox,(void))

Void CollisionSolver_obj::SolveSphereSphere( ::haxor::component::physics::SphereCollider ca,::haxor::component::physics::SphereCollider cb,::haxor::physics::Collision c){
{
		HX_STACK_FRAME("haxor.physics.CollisionSolver","SolveSphereSphere",0xd307aabd,"haxor.physics.CollisionSolver.SolveSphereSphere","haxor/physics/CollisionSolver.hx",166,0x478b5d4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ca,"ca")
		HX_STACK_ARG(cb,"cb")
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(167)
		::haxor::math::Matrix4 wma = ca->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(wma,"wma");
		HX_STACK_LINE(168)
		::haxor::math::Matrix4 wmb = cb->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(wmb,"wmb");
		struct _Function_1_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/physics/CollisionSolver.hx",169,0x478b5d4e)
				{
					HX_STACK_LINE(169)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(169)
					int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(169)
					return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(169)
		::haxor::math::Vector3 c0 = (_Function_1_1::Block())->Set3(ca->m_center);		HX_STACK_VAR(c0,"c0");
		HX_STACK_LINE(169)
		{
			HX_STACK_LINE(169)
			Float vx = ((((wma->m00 * c0->x) + (wma->m01 * c0->y)) + (wma->m02 * c0->z)) + wma->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(169)
			Float vy = ((((wma->m10 * c0->x) + (wma->m11 * c0->y)) + (wma->m12 * c0->z)) + wma->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(169)
			Float vz = ((((wma->m20 * c0->x) + (wma->m21 * c0->y)) + (wma->m22 * c0->z)) + wma->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(169)
			c0->x = vx;
			HX_STACK_LINE(169)
			c0->y = vy;
			HX_STACK_LINE(169)
			c0->z = vz;
			HX_STACK_LINE(169)
			c0;
		}
		HX_STACK_LINE(170)
		Float _g2 = ca->get_radius();		HX_STACK_VAR(_g2,"_g2");
		struct _Function_1_2{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/physics/CollisionSolver.hx",170,0x478b5d4e)
				{
					HX_STACK_LINE(170)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(170)
					int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(170)
					return _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(170)
		::haxor::math::Vector3 rv0 = (_Function_1_2::Block())->Set((int)0,(int)0,_g2);		HX_STACK_VAR(rv0,"rv0");
		HX_STACK_LINE(170)
		{
			HX_STACK_LINE(170)
			Float vx = (((wma->m00 * rv0->x) + (wma->m01 * rv0->y)) + (wma->m02 * rv0->z));		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(170)
			Float vy = (((wma->m10 * rv0->x) + (wma->m11 * rv0->y)) + (wma->m12 * rv0->z));		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(170)
			Float vz = (((wma->m20 * rv0->x) + (wma->m21 * rv0->y)) + (wma->m22 * rv0->z));		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(170)
			rv0->x = vx;
			HX_STACK_LINE(170)
			rv0->y = vy;
			HX_STACK_LINE(170)
			rv0->z = vz;
			HX_STACK_LINE(170)
			rv0;
		}
		HX_STACK_LINE(171)
		Float r0 = ::Math_obj::sqrt((((rv0->x * rv0->x) + (rv0->y * rv0->y)) + (rv0->z * rv0->z)));		HX_STACK_VAR(r0,"r0");
		struct _Function_1_3{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/physics/CollisionSolver.hx",172,0x478b5d4e)
				{
					HX_STACK_LINE(172)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(172)
					int _g3 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(172)
					return _this->m_v3->__get(_g3).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(172)
		::haxor::math::Vector3 c1 = (_Function_1_3::Block())->Set3(cb->m_center);		HX_STACK_VAR(c1,"c1");
		HX_STACK_LINE(172)
		{
			HX_STACK_LINE(172)
			Float vx = ((((wmb->m00 * c1->x) + (wmb->m01 * c1->y)) + (wmb->m02 * c1->z)) + wmb->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(172)
			Float vy = ((((wmb->m10 * c1->x) + (wmb->m11 * c1->y)) + (wmb->m12 * c1->z)) + wmb->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(172)
			Float vz = ((((wmb->m20 * c1->x) + (wmb->m21 * c1->y)) + (wmb->m22 * c1->z)) + wmb->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(172)
			c1->x = vx;
			HX_STACK_LINE(172)
			c1->y = vy;
			HX_STACK_LINE(172)
			c1->z = vz;
			HX_STACK_LINE(172)
			c1;
		}
		HX_STACK_LINE(173)
		Float _g5 = cb->get_radius();		HX_STACK_VAR(_g5,"_g5");
		struct _Function_1_4{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/physics/CollisionSolver.hx",173,0x478b5d4e)
				{
					HX_STACK_LINE(173)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(173)
					int _g4 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(173)
					return _this->m_v3->__get(_g4).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(173)
		::haxor::math::Vector3 rv1 = (_Function_1_4::Block())->Set((int)0,(int)0,_g5);		HX_STACK_VAR(rv1,"rv1");
		HX_STACK_LINE(173)
		{
			HX_STACK_LINE(173)
			Float vx = (((wmb->m00 * rv1->x) + (wmb->m01 * rv1->y)) + (wmb->m02 * rv1->z));		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(173)
			Float vy = (((wmb->m10 * rv1->x) + (wmb->m11 * rv1->y)) + (wmb->m12 * rv1->z));		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(173)
			Float vz = (((wmb->m20 * rv1->x) + (wmb->m21 * rv1->y)) + (wmb->m22 * rv1->z));		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(173)
			rv1->x = vx;
			HX_STACK_LINE(173)
			rv1->y = vy;
			HX_STACK_LINE(173)
			rv1->z = vz;
			HX_STACK_LINE(173)
			rv1;
		}
		HX_STACK_LINE(174)
		Float r1 = ::Math_obj::sqrt((((rv1->x * rv1->x) + (rv1->y * rv1->y)) + (rv1->z * rv1->z)));		HX_STACK_VAR(r1,"r1");
		HX_STACK_LINE(176)
		Float _g6 = ::haxor::math::Vector3_obj::Distance(c0,c1);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(176)
		Float d = (_g6 * 2.0);		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(178)
		c->depth = (d - ((r0 + r1)));
		HX_STACK_LINE(180)
		if (((c->depth < 0.0))){
			HX_STACK_LINE(182)
			c->normal->x = (c0->x - c1->x);
			HX_STACK_LINE(183)
			c->normal->y = (c0->y - c1->y);
			HX_STACK_LINE(184)
			c->normal->z = (c0->z - c1->z);
			HX_STACK_LINE(185)
			c->normal->Normalize();
			HX_STACK_LINE(186)
			c->point->Set3(c0);
			struct _Function_2_1{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/physics/CollisionSolver.hx",187,0x478b5d4e)
					{
						HX_STACK_LINE(187)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(187)
						int _g7 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(187)
						return _this->m_v3->__get(_g7).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(187)
			::haxor::math::Vector3 n = (_Function_2_1::Block())->Set3(c->normal);		HX_STACK_VAR(n,"n");
			HX_STACK_LINE(188)
			n->Scale((-(((r0 + c->depth))) * 0.5));
			HX_STACK_LINE(189)
			c->point->Add(n);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CollisionSolver_obj,SolveSphereSphere,(void))

Void CollisionSolver_obj::SolveSphereBox( ::haxor::component::physics::SphereCollider ca,::haxor::component::physics::BoxCollider cb,::haxor::physics::Collision c){
{
		HX_STACK_FRAME("haxor.physics.CollisionSolver","SolveSphereBox",0xe864945b,"haxor.physics.CollisionSolver.SolveSphereBox","haxor/physics/CollisionSolver.hx",200,0x478b5d4e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ca,"ca")
		HX_STACK_ARG(cb,"cb")
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(201)
		::haxor::math::Matrix4 wma = ca->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(wma,"wma");
		HX_STACK_LINE(202)
		::haxor::math::Matrix4 wmb = cb->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(wmb,"wmb");
		HX_STACK_LINE(203)
		::haxor::math::Matrix4 wmib = cb->m_entity->m_transform->get_WorldMatrixInverse();		HX_STACK_VAR(wmib,"wmib");
		struct _Function_1_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/physics/CollisionSolver.hx",205,0x478b5d4e)
				{
					HX_STACK_LINE(205)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(205)
					int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(205)
					return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(205)
		::haxor::math::Vector3 c0 = (_Function_1_1::Block())->Set3(ca->m_center);		HX_STACK_VAR(c0,"c0");
		HX_STACK_LINE(206)
		{
			HX_STACK_LINE(206)
			Float vx = ((((wma->m00 * c0->x) + (wma->m01 * c0->y)) + (wma->m02 * c0->z)) + wma->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(206)
			Float vy = ((((wma->m10 * c0->x) + (wma->m11 * c0->y)) + (wma->m12 * c0->z)) + wma->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(206)
			Float vz = ((((wma->m20 * c0->x) + (wma->m21 * c0->y)) + (wma->m22 * c0->z)) + wma->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(206)
			c0->x = vx;
			HX_STACK_LINE(206)
			c0->y = vy;
			HX_STACK_LINE(206)
			c0->z = vz;
			HX_STACK_LINE(206)
			c0;
		}
		HX_STACK_LINE(207)
		{
			HX_STACK_LINE(207)
			Float vx = ((((wmib->m00 * c0->x) + (wmib->m01 * c0->y)) + (wmib->m02 * c0->z)) + wmib->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(207)
			Float vy = ((((wmib->m10 * c0->x) + (wmib->m11 * c0->y)) + (wmib->m12 * c0->z)) + wmib->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(207)
			Float vz = ((((wmib->m20 * c0->x) + (wmib->m21 * c0->y)) + (wmib->m22 * c0->z)) + wmib->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(207)
			c0->x = vx;
			HX_STACK_LINE(207)
			c0->y = vy;
			HX_STACK_LINE(207)
			c0->z = vz;
			HX_STACK_LINE(207)
			c0;
		}
		HX_STACK_LINE(209)
		Float _g2 = ca->get_radius();		HX_STACK_VAR(_g2,"_g2");
		struct _Function_1_2{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/physics/CollisionSolver.hx",209,0x478b5d4e)
				{
					HX_STACK_LINE(209)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(209)
					int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(209)
					return _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(209)
		::haxor::math::Vector3 rv0 = (_Function_1_2::Block())->Set((int)0,(int)0,_g2);		HX_STACK_VAR(rv0,"rv0");
		HX_STACK_LINE(210)
		{
			HX_STACK_LINE(210)
			Float vx = (((wma->m00 * rv0->x) + (wma->m01 * rv0->y)) + (wma->m02 * rv0->z));		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(210)
			Float vy = (((wma->m10 * rv0->x) + (wma->m11 * rv0->y)) + (wma->m12 * rv0->z));		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(210)
			Float vz = (((wma->m20 * rv0->x) + (wma->m21 * rv0->y)) + (wma->m22 * rv0->z));		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(210)
			rv0->x = vx;
			HX_STACK_LINE(210)
			rv0->y = vy;
			HX_STACK_LINE(210)
			rv0->z = vz;
			HX_STACK_LINE(210)
			rv0;
		}
		struct _Function_1_3{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/physics/CollisionSolver.hx",213,0x478b5d4e)
				{
					HX_STACK_LINE(213)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(213)
					int _g3 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(213)
					return _this->m_v3->__get(_g3).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(213)
		::haxor::math::Vector3 c1 = (_Function_1_3::Block())->Set3(cb->m_center);		HX_STACK_VAR(c1,"c1");
		HX_STACK_LINE(214)
		::haxor::math::Vector3 _g5 = cb->get_size();		HX_STACK_VAR(_g5,"_g5");
		struct _Function_1_4{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/physics/CollisionSolver.hx",214,0x478b5d4e)
				{
					HX_STACK_LINE(214)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(214)
					int _g4 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(214)
					return _this->m_v3->__get(_g4).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(214)
		::haxor::math::Vector3 s1 = (_Function_1_4::Block())->Set3(_g5);		HX_STACK_VAR(s1,"s1");
		HX_STACK_LINE(216)
		Float hx = (s1->x * 0.5);		HX_STACK_VAR(hx,"hx");
		HX_STACK_LINE(218)
		Float xmin0 = (c1->x - hx);		HX_STACK_VAR(xmin0,"xmin0");
		HX_STACK_LINE(219)
		Float xmax1 = (c0->x + rv0->x);		HX_STACK_VAR(xmax1,"xmax1");
		HX_STACK_LINE(221)
		Float xmin1 = (c0->x - rv0->x);		HX_STACK_VAR(xmin1,"xmin1");
		HX_STACK_LINE(222)
		Float xmax0 = (c1->x + hx);		HX_STACK_VAR(xmax0,"xmax0");
		HX_STACK_LINE(224)
		Float hy = (s1->y * 0.5);		HX_STACK_VAR(hy,"hy");
		HX_STACK_LINE(226)
		Float ymin0 = (c1->y - hy);		HX_STACK_VAR(ymin0,"ymin0");
		HX_STACK_LINE(227)
		Float ymax1 = (c0->y + rv0->y);		HX_STACK_VAR(ymax1,"ymax1");
		HX_STACK_LINE(229)
		Float ymin1 = (c0->y - rv0->y);		HX_STACK_VAR(ymin1,"ymin1");
		HX_STACK_LINE(230)
		Float ymax0 = (c1->y + hy);		HX_STACK_VAR(ymax0,"ymax0");
		HX_STACK_LINE(232)
		Float hz = (s1->z * 0.5);		HX_STACK_VAR(hz,"hz");
		HX_STACK_LINE(234)
		Float zmin0 = (c1->z - hz);		HX_STACK_VAR(zmin0,"zmin0");
		HX_STACK_LINE(235)
		Float zmax1 = (c0->z + rv0->z);		HX_STACK_VAR(zmax1,"zmax1");
		HX_STACK_LINE(237)
		Float zmin1 = (c0->z - rv0->z);		HX_STACK_VAR(zmin1,"zmin1");
		HX_STACK_LINE(238)
		Float zmax0 = (c1->z + hz);		HX_STACK_VAR(zmax0,"zmax0");
		HX_STACK_LINE(241)
		::haxor::math::Vector3 cp;		HX_STACK_VAR(cp,"cp");
		HX_STACK_LINE(241)
		{
			HX_STACK_LINE(241)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(241)
			int _g6 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(241)
			cp = _this->m_v3->__get(_g6).StaticCast< ::haxor::math::Vector3 >();
		}
		HX_STACK_LINE(242)
		Float _g7;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(242)
		{
			HX_STACK_LINE(242)
			Float b = ::Math_obj::min(xmax0,c0->x);		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(242)
			_g7 = ::Math_obj::max(xmin0,b);
		}
		HX_STACK_LINE(242)
		cp->x = _g7;
		HX_STACK_LINE(243)
		Float _g8;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(243)
		{
			HX_STACK_LINE(243)
			Float b = ::Math_obj::min(ymax0,c0->y);		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(243)
			_g8 = ::Math_obj::max(ymin0,b);
		}
		HX_STACK_LINE(243)
		cp->y = _g8;
		HX_STACK_LINE(244)
		Float _g9;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(244)
		{
			HX_STACK_LINE(244)
			Float b = ::Math_obj::min(zmax0,c0->z);		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(244)
			_g9 = ::Math_obj::max(zmin0,b);
		}
		HX_STACK_LINE(244)
		cp->z = _g9;
		HX_STACK_LINE(246)
		{
			HX_STACK_LINE(246)
			Float vx = ((((wmb->m00 * cp->x) + (wmb->m01 * cp->y)) + (wmb->m02 * cp->z)) + wmb->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(246)
			Float vy = ((((wmb->m10 * cp->x) + (wmb->m11 * cp->y)) + (wmb->m12 * cp->z)) + wmb->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(246)
			Float vz = ((((wmb->m20 * cp->x) + (wmb->m21 * cp->y)) + (wmb->m22 * cp->z)) + wmb->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(246)
			cp->x = vx;
			HX_STACK_LINE(246)
			cp->y = vy;
			HX_STACK_LINE(246)
			cp->z = vz;
			HX_STACK_LINE(246)
			cp;
		}
		HX_STACK_LINE(247)
		{
			HX_STACK_LINE(247)
			Float vx = ((((wmb->m00 * c0->x) + (wmb->m01 * c0->y)) + (wmb->m02 * c0->z)) + wmb->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(247)
			Float vy = ((((wmb->m10 * c0->x) + (wmb->m11 * c0->y)) + (wmb->m12 * c0->z)) + wmb->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(247)
			Float vz = ((((wmb->m20 * c0->x) + (wmb->m21 * c0->y)) + (wmb->m22 * c0->z)) + wmb->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(247)
			c0->x = vx;
			HX_STACK_LINE(247)
			c0->y = vy;
			HX_STACK_LINE(247)
			c0->z = vz;
			HX_STACK_LINE(247)
			c0;
		}
		HX_STACK_LINE(249)
		Float _g10 = ::Math_obj::sqrt((((rv0->x * rv0->x) + (rv0->y * rv0->y)) + (rv0->z * rv0->z)));		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(249)
		Float r = (_g10 * 0.5);		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(250)
		Float d = ::haxor::math::Vector3_obj::Distance(cp,c0);		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(252)
		c->depth = (d - r);
		HX_STACK_LINE(253)
		if (((c->depth < 0.0))){
			HX_STACK_LINE(255)
			c->point->Set3(cp);
			HX_STACK_LINE(256)
			c->normal->x = (c0->x - cp->x);
			HX_STACK_LINE(257)
			c->normal->y = (c0->y - cp->y);
			HX_STACK_LINE(258)
			c->normal->z = (c0->z - cp->z);
			HX_STACK_LINE(259)
			c->normal->Normalize();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CollisionSolver_obj,SolveSphereBox,(void))


CollisionSolver_obj::CollisionSolver_obj()
{
}

void CollisionSolver_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CollisionSolver);
	HX_MARK_MEMBER_NAME(broadphase,"broadphase");
	HX_MARK_MEMBER_NAME(iterations,"iterations");
	HX_MARK_END_CLASS();
}

void CollisionSolver_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(broadphase,"broadphase");
	HX_VISIT_MEMBER_NAME(iterations,"iterations");
}

Dynamic CollisionSolver_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"Step") ) { return Step_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Solve") ) { return Solve_dyn(); }
		if (HX_FIELD_EQ(inName,"Apply") ) { return Apply_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Resolve") ) { return Resolve_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"broadphase") ) { return broadphase; }
		if (HX_FIELD_EQ(inName,"iterations") ) { return iterations; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SolveBoxBox") ) { return SolveBoxBox_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"SolveSphereBox") ) { return SolveSphereBox_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"SolveSphereSphere") ) { return SolveSphereSphere_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CollisionSolver_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"broadphase") ) { broadphase=inValue.Cast< ::haxor::physics::broadphase::BroadPhase >(); return inValue; }
		if (HX_FIELD_EQ(inName,"iterations") ) { iterations=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CollisionSolver_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("broadphase"));
	outFields->push(HX_CSTRING("iterations"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::physics::broadphase::BroadPhase*/ ,(int)offsetof(CollisionSolver_obj,broadphase),HX_CSTRING("broadphase")},
	{hx::fsInt,(int)offsetof(CollisionSolver_obj,iterations),HX_CSTRING("iterations")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("broadphase"),
	HX_CSTRING("iterations"),
	HX_CSTRING("Step"),
	HX_CSTRING("Solve"),
	HX_CSTRING("Apply"),
	HX_CSTRING("Resolve"),
	HX_CSTRING("SolveBoxBox"),
	HX_CSTRING("SolveSphereSphere"),
	HX_CSTRING("SolveSphereBox"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CollisionSolver_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CollisionSolver_obj::__mClass,"__mClass");
};

#endif

Class CollisionSolver_obj::__mClass;

void CollisionSolver_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.physics.CollisionSolver"), hx::TCanCast< CollisionSolver_obj> ,sStaticFields,sMemberFields,
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

void CollisionSolver_obj::__boot()
{
}

} // end namespace haxor
} // end namespace physics
