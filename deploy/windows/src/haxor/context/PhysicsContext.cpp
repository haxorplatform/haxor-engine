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
#ifndef INCLUDED_haxor_component_physics_RigidBody
#include <haxor/component/physics/RigidBody.h>
#endif
#ifndef INCLUDED_haxor_context_BaseProcess
#include <haxor/context/BaseProcess.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_PhysicsContext
#include <haxor/context/PhysicsContext.h>
#endif
#ifndef INCLUDED_haxor_context_Process
#include <haxor/context/Process.h>
#endif
#ifndef INCLUDED_haxor_context_UID
#include <haxor/context/UID.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IFixedUpdateable
#include <haxor/core/IFixedUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
#endif
#ifndef INCLUDED_haxor_physics_CollisionSolver
#include <haxor/physics/CollisionSolver.h>
#endif
#ifndef INCLUDED_haxor_physics_Physics
#include <haxor/physics/Physics.h>
#endif
#ifndef INCLUDED_haxor_physics_broadphase_BroadPhase
#include <haxor/physics/broadphase/BroadPhase.h>
#endif
namespace haxor{
namespace context{

Void PhysicsContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.PhysicsContext","new",0xd8a4dec5,"haxor.context.PhysicsContext.new","haxor/context/PhysicsContext.hx",74,0x82743509)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(75)
	::haxor::context::UID _g = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(75)
	this->rid = _g;
	HX_STACK_LINE(76)
	::haxor::context::UID _g1 = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(76)
	this->cid = _g1;
	HX_STACK_LINE(77)
	this->colliders = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(80)
	this->rigidbodies = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(82)
	this->rbc = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(83)
	this->crb = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(85)
	this->collider_dirty = Array_obj< bool >::__new();
}
;
	return null();
}

//PhysicsContext_obj::~PhysicsContext_obj() { }

Dynamic PhysicsContext_obj::__CreateEmpty() { return  new PhysicsContext_obj; }
hx::ObjectPtr< PhysicsContext_obj > PhysicsContext_obj::__new()
{  hx::ObjectPtr< PhysicsContext_obj > result = new PhysicsContext_obj();
	result->__construct();
	return result;}

Dynamic PhysicsContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PhysicsContext_obj > result = new PhysicsContext_obj();
	result->__construct();
	return result;}

Void PhysicsContext_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.context.PhysicsContext","Initialize",0x7a5fedab,"haxor.context.PhysicsContext.Initialize","haxor/context/PhysicsContext.hx",96,0x82743509)
		HX_STACK_THIS(this)
		HX_STACK_LINE(96)
		this->accum_dt = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PhysicsContext_obj,Initialize,(void))

Void PhysicsContext_obj::CreateCollider( ::haxor::component::physics::Collider c){
{
		HX_STACK_FRAME("haxor.context.PhysicsContext","CreateCollider",0x0639e42b,"haxor.context.PhysicsContext.CreateCollider","haxor/context/PhysicsContext.hx",104,0x82743509)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(105)
		this->colliders->push(c);
		HX_STACK_LINE(106)
		int nid = this->cid->get_next();		HX_STACK_VAR(nid,"nid");
		HX_STACK_LINE(107)
		int _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(107)
		{
			HX_STACK_LINE(107)
			::haxor::context::UID _this = this->cid;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(107)
			if (((_this->m_cache->length <= (int)0))){
				HX_STACK_LINE(107)
				_g = (_this->m_id)++;
			}
			else{
				HX_STACK_LINE(107)
				_g = _this->m_cache->shift();
			}
		}
		HX_STACK_LINE(107)
		c->__cid = _g;
		HX_STACK_LINE(109)
		if (((nid >= c->__cid))){
			HX_STACK_LINE(111)
			this->crb->push(null());
			HX_STACK_LINE(112)
			this->collider_dirty->push(true);
		}
		else{
			HX_STACK_LINE(116)
			this->collider_dirty[c->__cid] = true;
		}
		HX_STACK_LINE(118)
		this->crb[c->__cid] = c->m_entity->GetComponent(hx::ClassOf< ::haxor::component::physics::RigidBody >());
		HX_STACK_LINE(119)
		::haxor::physics::Physics_obj::get_broadphase()->Add(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PhysicsContext_obj,CreateCollider,(void))

Void PhysicsContext_obj::OnColliderUpdate( ::haxor::component::physics::Collider c,bool h){
{
		HX_STACK_FRAME("haxor.context.PhysicsContext","OnColliderUpdate",0xb04e3877,"haxor.context.PhysicsContext.OnColliderUpdate","haxor/context/PhysicsContext.hx",128,0x82743509)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_ARG(h,"h")
		HX_STACK_LINE(128)
		this->collider_dirty[c->__cid] = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PhysicsContext_obj,OnColliderUpdate,(void))

Void PhysicsContext_obj::CreateRigidBody( ::haxor::component::physics::RigidBody r){
{
		HX_STACK_FRAME("haxor.context.PhysicsContext","CreateRigidBody",0x76f43816,"haxor.context.PhysicsContext.CreateRigidBody","haxor/context/PhysicsContext.hx",138,0x82743509)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(139)
		this->rigidbodies->push(r);
		HX_STACK_LINE(140)
		int nid;		HX_STACK_VAR(nid,"nid");
		HX_STACK_LINE(140)
		{
			HX_STACK_LINE(140)
			::haxor::context::UID _this = this->rid;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(140)
			if (((_this->m_cache->length <= (int)0))){
				HX_STACK_LINE(140)
				nid = (_this->m_id)++;
			}
			else{
				HX_STACK_LINE(140)
				nid = _this->m_cache->shift();
			}
		}
		HX_STACK_LINE(141)
		r->__cid = nid;
		HX_STACK_LINE(143)
		if (((nid >= this->rbc->length))){
			HX_STACK_LINE(145)
			this->rbc->push(Array_obj< ::Dynamic >::__new());
		}
		else{
			HX_STACK_LINE(149)
			this->rbc[nid] = Array_obj< ::Dynamic >::__new();
		}
		HX_STACK_LINE(153)
		Array< ::Dynamic > cl = r->m_entity->GetComponents(hx::ClassOf< ::haxor::component::physics::Collider >());		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(154)
		{
			HX_STACK_LINE(154)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(154)
			int _g = cl->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(154)
			while((true)){
				HX_STACK_LINE(154)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(154)
					break;
				}
				HX_STACK_LINE(154)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(156)
				::haxor::component::physics::Collider c = cl->__get(i).StaticCast< ::haxor::component::physics::Collider >();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(157)
				this->rbc->__get(nid).StaticCast< Array< ::Dynamic > >()->push(c);
				HX_STACK_LINE(158)
				this->crb[c->__cid] = r;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PhysicsContext_obj,CreateRigidBody,(void))

Void PhysicsContext_obj::Step( ){
{
		HX_STACK_FRAME("haxor.context.PhysicsContext","Step",0xa5d09d67,"haxor.context.PhysicsContext.Step","haxor/context/PhysicsContext.hx",167,0x82743509)
		HX_STACK_THIS(this)
		HX_STACK_LINE(168)
		::haxor::context::Process up = ::haxor::context::EngineContext_obj::fixed_update;		HX_STACK_VAR(up,"up");
		HX_STACK_LINE(169)
		::haxor::physics::broadphase::BroadPhase bp = ::haxor::physics::Physics_obj::get_broadphase();		HX_STACK_VAR(bp,"bp");
		HX_STACK_LINE(170)
		::haxor::physics::CollisionSolver cs = ::haxor::physics::Physics_obj::m_solver;		HX_STACK_VAR(cs,"cs");
		HX_STACK_LINE(171)
		int steps = (int)0;		HX_STACK_VAR(steps,"steps");
		HX_STACK_LINE(173)
		cs->broadphase = bp;
		HX_STACK_LINE(175)
		this->accum_dt = ::haxor::core::Time_obj::m_delta;
		HX_STACK_LINE(177)
		Float t0;		HX_STACK_VAR(t0,"t0");
		HX_STACK_LINE(179)
		while((true)){
			HX_STACK_LINE(179)
			if ((!(((this->accum_dt >= (int)0))))){
				HX_STACK_LINE(179)
				break;
			}
			HX_STACK_LINE(182)
			if (((steps >= (int)5))){
				HX_STACK_LINE(182)
				break;
			}
			HX_STACK_LINE(183)
			(steps)++;
			HX_STACK_LINE(186)
			{
				HX_STACK_LINE(186)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(186)
				int _g = up->m_length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(186)
				while((true)){
					HX_STACK_LINE(186)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(186)
						break;
					}
					HX_STACK_LINE(186)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(188)
					::haxor::core::Resource r = up->list->__GetItem(i);		HX_STACK_VAR(r,"r");
					HX_STACK_LINE(189)
					if ((r->m_destroyed)){
						HX_STACK_LINE(189)
						continue;
					}
					HX_STACK_LINE(190)
					up->list->__GetItem(i)->__Field(HX_CSTRING("OnFixedUpdate"),true)();
				}
			}
			HX_STACK_LINE(194)
			this->UpdateColliders();
			HX_STACK_LINE(196)
			Array< ::Dynamic > l = this->rigidbodies;		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(198)
			{
				HX_STACK_LINE(198)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(198)
				int _g = l->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(198)
				while((true)){
					HX_STACK_LINE(198)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(198)
						break;
					}
					HX_STACK_LINE(198)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(200)
					if ((l->__get(i).StaticCast< ::haxor::component::physics::RigidBody >()->get_enabled())){
						HX_STACK_LINE(202)
						if ((!(l->__get(i).StaticCast< ::haxor::component::physics::RigidBody >()->kinematic))){
							HX_STACK_LINE(204)
							l->__get(i).StaticCast< ::haxor::component::physics::RigidBody >()->ComputeForces();
							HX_STACK_LINE(205)
							Float _g2 = ::haxor::core::Time_obj::get_fixedDelta();		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(205)
							l->__get(i).StaticCast< ::haxor::component::physics::RigidBody >()->IntegrateVelocity(_g2);
						}
					}
				}
			}
			HX_STACK_LINE(210)
			{
				HX_STACK_LINE(210)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(210)
				int _g = cs->iterations;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(210)
				while((true)){
					HX_STACK_LINE(210)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(210)
						break;
					}
					HX_STACK_LINE(210)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(212)
					cs->Step();
				}
			}
			HX_STACK_LINE(215)
			{
				HX_STACK_LINE(215)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(215)
				int _g = l->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(215)
				while((true)){
					HX_STACK_LINE(215)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(215)
						break;
					}
					HX_STACK_LINE(215)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(217)
					if ((l->__get(i).StaticCast< ::haxor::component::physics::RigidBody >()->get_enabled())){
						HX_STACK_LINE(219)
						if ((!(l->__get(i).StaticCast< ::haxor::component::physics::RigidBody >()->kinematic))){
							HX_STACK_LINE(221)
							Float _g11 = ::haxor::core::Time_obj::get_fixedDelta();		HX_STACK_VAR(_g11,"_g11");
							HX_STACK_LINE(221)
							l->__get(i).StaticCast< ::haxor::component::physics::RigidBody >()->IntegratePosition(_g11);
						}
					}
					HX_STACK_LINE(224)
					l->__get(i).StaticCast< ::haxor::component::physics::RigidBody >()->ResetForces();
				}
			}
			HX_STACK_LINE(227)
			Float _g2 = ::haxor::core::Time_obj::get_fixedDelta();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(227)
			hx::SubEq(this->accum_dt,_g2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PhysicsContext_obj,Step,(void))

Void PhysicsContext_obj::UpdateColliders( ){
{
		HX_STACK_FRAME("haxor.context.PhysicsContext","UpdateColliders",0x1b03d93b,"haxor.context.PhysicsContext.UpdateColliders","haxor/context/PhysicsContext.hx",236,0x82743509)
		HX_STACK_THIS(this)
		HX_STACK_LINE(237)
		::haxor::physics::broadphase::BroadPhase bp = ::haxor::physics::Physics_obj::get_broadphase();		HX_STACK_VAR(bp,"bp");
		HX_STACK_LINE(239)
		bp->Step();
		HX_STACK_LINE(242)
		{
			HX_STACK_LINE(242)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(242)
			int _g = this->colliders->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(242)
			while((true)){
				HX_STACK_LINE(242)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(242)
					break;
				}
				HX_STACK_LINE(242)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(244)
				::haxor::component::physics::Collider c = this->colliders->__get(i).StaticCast< ::haxor::component::physics::Collider >();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(246)
				if ((!(c->get_enabled()))){
					HX_STACK_LINE(246)
					continue;
				}
				HX_STACK_LINE(248)
				if ((this->collider_dirty->__get(c->__cid))){
					HX_STACK_LINE(250)
					bp->Clear(c);
					HX_STACK_LINE(251)
					bp->Update(c);
					HX_STACK_LINE(252)
					bp->Query(c);
				}
				HX_STACK_LINE(254)
				this->collider_dirty[c->__cid] = false;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PhysicsContext_obj,UpdateColliders,(void))

Void PhysicsContext_obj::DestroyCollider( ::haxor::component::physics::Collider c){
{
		HX_STACK_FRAME("haxor.context.PhysicsContext","DestroyCollider",0x3605ec13,"haxor.context.PhysicsContext.DestroyCollider","haxor/context/PhysicsContext.hx",264,0x82743509)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(265)
		this->colliders->remove(c);
		HX_STACK_LINE(266)
		{
			HX_STACK_LINE(266)
			int v = c->__cid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(266)
			this->cid->m_cache->push(v);
			HX_STACK_LINE(266)
			v;
		}
		HX_STACK_LINE(267)
		::haxor::component::physics::RigidBody rb = this->crb->__get(c->__cid).StaticCast< ::haxor::component::physics::RigidBody >();		HX_STACK_VAR(rb,"rb");
		HX_STACK_LINE(268)
		this->crb[c->__cid] = null();
		HX_STACK_LINE(269)
		::haxor::physics::Physics_obj::get_broadphase()->Remove(c);
		HX_STACK_LINE(270)
		if (((rb != null()))){
			HX_STACK_LINE(272)
			this->rbc->__get(rb->__cid).StaticCast< Array< ::Dynamic > >()->remove(c);
		}
		HX_STACK_LINE(274)
		::haxor::physics::Physics_obj::get_broadphase()->Remove(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PhysicsContext_obj,DestroyCollider,(void))

Void PhysicsContext_obj::DestroyRigidBody( ::haxor::component::physics::RigidBody r){
{
		HX_STACK_FRAME("haxor.context.PhysicsContext","DestroyRigidBody",0x19af1b2e,"haxor.context.PhysicsContext.DestroyRigidBody","haxor/context/PhysicsContext.hx",282,0x82743509)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(283)
		this->rigidbodies->remove(r);
		HX_STACK_LINE(284)
		Array< ::Dynamic > cl = this->rbc->__get(r->__cid).StaticCast< Array< ::Dynamic > >();		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(285)
		{
			HX_STACK_LINE(285)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(285)
			int _g = cl->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(285)
			while((true)){
				HX_STACK_LINE(285)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(285)
					break;
				}
				HX_STACK_LINE(285)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(287)
				::haxor::component::physics::Collider c = cl->__get(i).StaticCast< ::haxor::component::physics::Collider >();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(288)
				this->crb[c->__cid] = null();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(PhysicsContext_obj,DestroyRigidBody,(void))


PhysicsContext_obj::PhysicsContext_obj()
{
}

void PhysicsContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PhysicsContext);
	HX_MARK_MEMBER_NAME(rid,"rid");
	HX_MARK_MEMBER_NAME(cid,"cid");
	HX_MARK_MEMBER_NAME(colliders,"colliders");
	HX_MARK_MEMBER_NAME(rigidbodies,"rigidbodies");
	HX_MARK_MEMBER_NAME(rbc,"rbc");
	HX_MARK_MEMBER_NAME(crb,"crb");
	HX_MARK_MEMBER_NAME(collider_dirty,"collider_dirty");
	HX_MARK_MEMBER_NAME(accum_dt,"accum_dt");
	HX_MARK_END_CLASS();
}

void PhysicsContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(rid,"rid");
	HX_VISIT_MEMBER_NAME(cid,"cid");
	HX_VISIT_MEMBER_NAME(colliders,"colliders");
	HX_VISIT_MEMBER_NAME(rigidbodies,"rigidbodies");
	HX_VISIT_MEMBER_NAME(rbc,"rbc");
	HX_VISIT_MEMBER_NAME(crb,"crb");
	HX_VISIT_MEMBER_NAME(collider_dirty,"collider_dirty");
	HX_VISIT_MEMBER_NAME(accum_dt,"accum_dt");
}

Dynamic PhysicsContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rid") ) { return rid; }
		if (HX_FIELD_EQ(inName,"cid") ) { return cid; }
		if (HX_FIELD_EQ(inName,"rbc") ) { return rbc; }
		if (HX_FIELD_EQ(inName,"crb") ) { return crb; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Step") ) { return Step_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"accum_dt") ) { return accum_dt; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"colliders") ) { return colliders; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"rigidbodies") ) { return rigidbodies; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"collider_dirty") ) { return collider_dirty; }
		if (HX_FIELD_EQ(inName,"CreateCollider") ) { return CreateCollider_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"CreateRigidBody") ) { return CreateRigidBody_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateColliders") ) { return UpdateColliders_dyn(); }
		if (HX_FIELD_EQ(inName,"DestroyCollider") ) { return DestroyCollider_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"OnColliderUpdate") ) { return OnColliderUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"DestroyRigidBody") ) { return DestroyRigidBody_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PhysicsContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rid") ) { rid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cid") ) { cid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rbc") ) { rbc=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"crb") ) { crb=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"accum_dt") ) { accum_dt=inValue.Cast< Float >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"colliders") ) { colliders=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"rigidbodies") ) { rigidbodies=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"collider_dirty") ) { collider_dirty=inValue.Cast< Array< bool > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PhysicsContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("rid"));
	outFields->push(HX_CSTRING("cid"));
	outFields->push(HX_CSTRING("colliders"));
	outFields->push(HX_CSTRING("rigidbodies"));
	outFields->push(HX_CSTRING("rbc"));
	outFields->push(HX_CSTRING("crb"));
	outFields->push(HX_CSTRING("collider_dirty"));
	outFields->push(HX_CSTRING("accum_dt"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(PhysicsContext_obj,rid),HX_CSTRING("rid")},
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(PhysicsContext_obj,cid),HX_CSTRING("cid")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PhysicsContext_obj,colliders),HX_CSTRING("colliders")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PhysicsContext_obj,rigidbodies),HX_CSTRING("rigidbodies")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PhysicsContext_obj,rbc),HX_CSTRING("rbc")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(PhysicsContext_obj,crb),HX_CSTRING("crb")},
	{hx::fsObject /*Array< bool >*/ ,(int)offsetof(PhysicsContext_obj,collider_dirty),HX_CSTRING("collider_dirty")},
	{hx::fsFloat,(int)offsetof(PhysicsContext_obj,accum_dt),HX_CSTRING("accum_dt")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("rid"),
	HX_CSTRING("cid"),
	HX_CSTRING("colliders"),
	HX_CSTRING("rigidbodies"),
	HX_CSTRING("rbc"),
	HX_CSTRING("crb"),
	HX_CSTRING("collider_dirty"),
	HX_CSTRING("accum_dt"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("CreateCollider"),
	HX_CSTRING("OnColliderUpdate"),
	HX_CSTRING("CreateRigidBody"),
	HX_CSTRING("Step"),
	HX_CSTRING("UpdateColliders"),
	HX_CSTRING("DestroyCollider"),
	HX_CSTRING("DestroyRigidBody"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PhysicsContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PhysicsContext_obj::__mClass,"__mClass");
};

#endif

Class PhysicsContext_obj::__mClass;

void PhysicsContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.PhysicsContext"), hx::TCanCast< PhysicsContext_obj> ,sStaticFields,sMemberFields,
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

void PhysicsContext_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
