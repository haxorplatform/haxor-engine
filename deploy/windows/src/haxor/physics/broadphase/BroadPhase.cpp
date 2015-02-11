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
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_PhysicsContext
#include <haxor/context/PhysicsContext.h>
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
#ifndef INCLUDED_haxor_ds_IUSetItem
#include <haxor/ds/IUSetItem.h>
#endif
#ifndef INCLUDED_haxor_ds_PairTable
#include <haxor/ds/PairTable.h>
#endif
#ifndef INCLUDED_haxor_ds_USet
#include <haxor/ds/USet.h>
#endif
#ifndef INCLUDED_haxor_physics_Collision
#include <haxor/physics/Collision.h>
#endif
#ifndef INCLUDED_haxor_physics_Physics
#include <haxor/physics/Physics.h>
#endif
#ifndef INCLUDED_haxor_physics_broadphase_BroadPhase
#include <haxor/physics/broadphase/BroadPhase.h>
#endif
namespace haxor{
namespace physics{
namespace broadphase{

Void BroadPhase_obj::__construct()
{
HX_STACK_FRAME("haxor.physics.broadphase.BroadPhase","new",0xd77298ad,"haxor.physics.broadphase.BroadPhase.new","haxor/physics/broadphase/BroadPhase.hx",38,0xfe120dc4)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(39)
	::haxor::ds::USet _g = ::haxor::ds::USet_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(39)
	this->pairs = _g;
	HX_STACK_LINE(41)
	::haxor::ds::PairTable _g1 = ::haxor::ds::PairTable_obj::__new((int)800,null(),true);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(41)
	this->m_table = _g1;
	HX_STACK_LINE(42)
	this->m_table->Iterate(this->InitCollisions_dyn());
}
;
	return null();
}

//BroadPhase_obj::~BroadPhase_obj() { }

Dynamic BroadPhase_obj::__CreateEmpty() { return  new BroadPhase_obj; }
hx::ObjectPtr< BroadPhase_obj > BroadPhase_obj::__new()
{  hx::ObjectPtr< BroadPhase_obj > result = new BroadPhase_obj();
	result->__construct();
	return result;}

Dynamic BroadPhase_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BroadPhase_obj > result = new BroadPhase_obj();
	result->__construct();
	return result;}

Void BroadPhase_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.physics.broadphase.BroadPhase","Initialize",0xe962c0c3,"haxor.physics.broadphase.BroadPhase.Initialize","haxor/physics/broadphase/BroadPhase.hx",48,0xfe120dc4)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BroadPhase_obj,Initialize,(void))

Void BroadPhase_obj::Step( ){
{
		HX_STACK_FRAME("haxor.physics.broadphase.BroadPhase","Step",0x9b058e7f,"haxor.physics.broadphase.BroadPhase.Step","haxor/physics/broadphase/BroadPhase.hx",53,0xfe120dc4)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BroadPhase_obj,Step,(void))

Void BroadPhase_obj::Update( ::haxor::component::physics::Collider c){
{
		HX_STACK_FRAME("haxor.physics.broadphase.BroadPhase","Update",0x10cd9ffc,"haxor.physics.broadphase.BroadPhase.Update","haxor/physics/broadphase/BroadPhase.hx",60,0xfe120dc4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BroadPhase_obj,Update,(void))

Void BroadPhase_obj::Add( ::haxor::component::physics::Collider c){
{
		HX_STACK_FRAME("haxor.physics.broadphase.BroadPhase","Add",0xd750724e,"haxor.physics.broadphase.BroadPhase.Add","haxor/physics/broadphase/BroadPhase.hx",66,0xfe120dc4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BroadPhase_obj,Add,(void))

Void BroadPhase_obj::Remove( ::haxor::component::physics::Collider c){
{
		HX_STACK_FRAME("haxor.physics.broadphase.BroadPhase","Remove",0x8e50b637,"haxor.physics.broadphase.BroadPhase.Remove","haxor/physics/broadphase/BroadPhase.hx",72,0xfe120dc4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BroadPhase_obj,Remove,(void))

Void BroadPhase_obj::Query( ::haxor::component::physics::Collider c){
{
		HX_STACK_FRAME("haxor.physics.broadphase.BroadPhase","Query",0xe3b33075,"haxor.physics.broadphase.BroadPhase.Query","haxor/physics/broadphase/BroadPhase.hx",77,0xfe120dc4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BroadPhase_obj,Query,(void))

Void BroadPhase_obj::Clear( ::haxor::component::physics::Collider c){
{
		HX_STACK_FRAME("haxor.physics.broadphase.BroadPhase","Clear",0xce2416fa,"haxor.physics.broadphase.BroadPhase.Clear","haxor/physics/broadphase/BroadPhase.hx",83,0xfe120dc4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(84)
		int cid = c->__cid;		HX_STACK_VAR(cid,"cid");
		HX_STACK_LINE(85)
		::haxor::physics::Collision col;		HX_STACK_VAR(col,"col");
		HX_STACK_LINE(86)
		{
			HX_STACK_LINE(86)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(86)
			while((true)){
				HX_STACK_LINE(86)
				if ((!(((_g < cid))))){
					HX_STACK_LINE(86)
					break;
				}
				HX_STACK_LINE(86)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(88)
				::haxor::physics::Collision _g1 = this->m_table->Get(i,cid);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(88)
				col = _g1;
				HX_STACK_LINE(89)
				this->pairs->Remove(col);
			}
		}
		HX_STACK_LINE(91)
		{
			HX_STACK_LINE(91)
			int _g1 = (cid + (int)1);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(91)
			int _g = this->m_table->get_rows();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(91)
			while((true)){
				HX_STACK_LINE(91)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(91)
					break;
				}
				HX_STACK_LINE(91)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(93)
				::haxor::physics::Collision _g11 = this->m_table->Get(cid,i);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(93)
				col = _g11;
				HX_STACK_LINE(94)
				this->pairs->Remove(col);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BroadPhase_obj,Clear,(void))

Void BroadPhase_obj::OnFetch( ::haxor::component::physics::Collider a,::haxor::component::physics::Collider b){
{
		HX_STACK_FRAME("haxor.physics.broadphase.BroadPhase","OnFetch",0x99864d48,"haxor.physics.broadphase.BroadPhase.OnFetch","haxor/physics/broadphase/BroadPhase.hx",103,0xfe120dc4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(a,"a")
		HX_STACK_ARG(b,"b")
		HX_STACK_LINE(104)
		int ia;		HX_STACK_VAR(ia,"ia");
		HX_STACK_LINE(104)
		if (((a->__cid > b->__cid))){
			HX_STACK_LINE(104)
			ia = a->__cid;
		}
		else{
			HX_STACK_LINE(104)
			ia = b->__cid;
		}
		HX_STACK_LINE(105)
		int ib;		HX_STACK_VAR(ib,"ib");
		HX_STACK_LINE(105)
		if (((a->__cid < b->__cid))){
			HX_STACK_LINE(105)
			ib = a->__cid;
		}
		else{
			HX_STACK_LINE(105)
			ib = b->__cid;
		}
		HX_STACK_LINE(106)
		if (((ia == ib))){
			HX_STACK_LINE(106)
			return null();
		}
		HX_STACK_LINE(108)
		::haxor::component::physics::RigidBody ra = ::haxor::context::EngineContext_obj::physics->crb->__get(ia).StaticCast< ::haxor::component::physics::RigidBody >();		HX_STACK_VAR(ra,"ra");
		HX_STACK_LINE(109)
		::haxor::component::physics::RigidBody rb = ::haxor::context::EngineContext_obj::physics->crb->__get(ib).StaticCast< ::haxor::component::physics::RigidBody >();		HX_STACK_VAR(rb,"rb");
		HX_STACK_LINE(111)
		if (((ra == null()))){
			HX_STACK_LINE(111)
			if (((rb == null()))){
				HX_STACK_LINE(111)
				return null();
			}
		}
		HX_STACK_LINE(113)
		if (((ra != null()))){
			HX_STACK_LINE(113)
			if ((!(ra->get_enabled()))){
				HX_STACK_LINE(113)
				return null();
			}
		}
		HX_STACK_LINE(114)
		if (((rb != null()))){
			HX_STACK_LINE(114)
			if ((!(rb->get_enabled()))){
				HX_STACK_LINE(114)
				return null();
			}
		}
		HX_STACK_LINE(116)
		::haxor::component::physics::Collider ca;		HX_STACK_VAR(ca,"ca");
		HX_STACK_LINE(116)
		if (((ia > ib))){
			HX_STACK_LINE(116)
			ca = a;
		}
		else{
			HX_STACK_LINE(116)
			ca = b;
		}
		HX_STACK_LINE(117)
		if ((!(ca->get_enabled()))){
			HX_STACK_LINE(117)
			return null();
		}
		HX_STACK_LINE(119)
		::haxor::component::physics::Collider cb;		HX_STACK_VAR(cb,"cb");
		HX_STACK_LINE(119)
		if (((ia < ib))){
			HX_STACK_LINE(119)
			cb = a;
		}
		else{
			HX_STACK_LINE(119)
			cb = b;
		}
		HX_STACK_LINE(120)
		if ((!(cb->get_enabled()))){
			HX_STACK_LINE(120)
			return null();
		}
		HX_STACK_LINE(122)
		if ((!(::haxor::physics::Physics_obj::CanInteract(ca->m_entity->m_layer,cb->m_entity->m_layer)))){
			HX_STACK_LINE(122)
			return null();
		}
		HX_STACK_LINE(124)
		::haxor::physics::Collision col = this->m_table->Get(ia,ib);		HX_STACK_VAR(col,"col");
		HX_STACK_LINE(125)
		col->Reset();
		HX_STACK_LINE(126)
		col->from = ca;
		HX_STACK_LINE(127)
		col->to = cb;
		HX_STACK_LINE(128)
		this->pairs->Add(col);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BroadPhase_obj,OnFetch,(void))

Void BroadPhase_obj::InitCollisions( int p_x,int p_y,::haxor::physics::Collision p_v){
{
		HX_STACK_FRAME("haxor.physics.broadphase.BroadPhase","InitCollisions",0x7d1333e4,"haxor.physics.broadphase.BroadPhase.InitCollisions","haxor/physics/broadphase/BroadPhase.hx",138,0xfe120dc4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(139)
		::haxor::physics::Collision _g = ::haxor::physics::Collision_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(139)
		this->m_table->Set(p_x,p_y,_g);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BroadPhase_obj,InitCollisions,(void))


BroadPhase_obj::BroadPhase_obj()
{
}

void BroadPhase_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BroadPhase);
	HX_MARK_MEMBER_NAME(pairs,"pairs");
	HX_MARK_MEMBER_NAME(m_table,"m_table");
	HX_MARK_END_CLASS();
}

void BroadPhase_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(pairs,"pairs");
	HX_VISIT_MEMBER_NAME(m_table,"m_table");
}

Dynamic BroadPhase_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Step") ) { return Step_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"pairs") ) { return pairs; }
		if (HX_FIELD_EQ(inName,"Query") ) { return Query_dyn(); }
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Update") ) { return Update_dyn(); }
		if (HX_FIELD_EQ(inName,"Remove") ) { return Remove_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_table") ) { return m_table; }
		if (HX_FIELD_EQ(inName,"OnFetch") ) { return OnFetch_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"InitCollisions") ) { return InitCollisions_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BroadPhase_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"pairs") ) { pairs=inValue.Cast< ::haxor::ds::USet >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_table") ) { m_table=inValue.Cast< ::haxor::ds::PairTable >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BroadPhase_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pairs"));
	outFields->push(HX_CSTRING("m_table"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::ds::USet*/ ,(int)offsetof(BroadPhase_obj,pairs),HX_CSTRING("pairs")},
	{hx::fsObject /*::haxor::ds::PairTable*/ ,(int)offsetof(BroadPhase_obj,m_table),HX_CSTRING("m_table")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("pairs"),
	HX_CSTRING("m_table"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Step"),
	HX_CSTRING("Update"),
	HX_CSTRING("Add"),
	HX_CSTRING("Remove"),
	HX_CSTRING("Query"),
	HX_CSTRING("Clear"),
	HX_CSTRING("OnFetch"),
	HX_CSTRING("InitCollisions"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BroadPhase_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BroadPhase_obj::__mClass,"__mClass");
};

#endif

Class BroadPhase_obj::__mClass;

void BroadPhase_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.physics.broadphase.BroadPhase"), hx::TCanCast< BroadPhase_obj> ,sStaticFields,sMemberFields,
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

void BroadPhase_obj::__boot()
{
}

} // end namespace haxor
} // end namespace physics
} // end namespace broadphase
