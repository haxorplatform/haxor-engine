#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
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
#ifndef INCLUDED_haxor_physics_broadphase_SAPBroadPhase
#include <haxor/physics/broadphase/SAPBroadPhase.h>
#endif
namespace haxor{
namespace physics{

Void Physics_obj::__construct()
{
	return null();
}

//Physics_obj::~Physics_obj() { }

Dynamic Physics_obj::__CreateEmpty() { return  new Physics_obj; }
hx::ObjectPtr< Physics_obj > Physics_obj::__new()
{  hx::ObjectPtr< Physics_obj > result = new Physics_obj();
	result->__construct();
	return result;}

Dynamic Physics_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Physics_obj > result = new Physics_obj();
	result->__construct();
	return result;}

::haxor::math::Vector3 Physics_obj::gravity;

::haxor::physics::broadphase::BroadPhase Physics_obj::get_broadphase( ){
	HX_STACK_FRAME("haxor.physics.Physics","get_broadphase",0x5997d15c,"haxor.physics.Physics.get_broadphase","haxor/physics/Physics.hx",39,0xbec2a6ec)
	HX_STACK_LINE(39)
	return ::haxor::physics::Physics_obj::m_broadphase;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Physics_obj,get_broadphase,return )

::haxor::physics::broadphase::BroadPhase Physics_obj::set_broadphase( ::haxor::physics::broadphase::BroadPhase v){
	HX_STACK_FRAME("haxor.physics.Physics","set_broadphase",0x79b7b9d0,"haxor.physics.Physics.set_broadphase","haxor/physics/Physics.hx",41,0xbec2a6ec)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(42)
	if (((v == null()))){
		HX_STACK_LINE(42)
		return ::haxor::physics::Physics_obj::m_broadphase;
	}
	HX_STACK_LINE(43)
	::haxor::physics::Physics_obj::m_broadphase = v;
	HX_STACK_LINE(44)
	::haxor::physics::Physics_obj::m_broadphase->Initialize();
	HX_STACK_LINE(45)
	return ::haxor::physics::Physics_obj::m_broadphase;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Physics_obj,set_broadphase,return )

::haxor::physics::broadphase::BroadPhase Physics_obj::m_broadphase;

::haxor::physics::CollisionSolver Physics_obj::get_solver( ){
	HX_STACK_FRAME("haxor.physics.Physics","get_solver",0xa42af636,"haxor.physics.Physics.get_solver","haxor/physics/Physics.hx",54,0xbec2a6ec)
	HX_STACK_LINE(54)
	return ::haxor::physics::Physics_obj::m_solver;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Physics_obj,get_solver,return )

::haxor::physics::CollisionSolver Physics_obj::m_solver;

::haxe::ds::IntMap Physics_obj::m_it;

Void Physics_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.physics.Physics","Initialize",0x6acdebca,"haxor.physics.Physics.Initialize","haxor/physics/Physics.hx",66,0xbec2a6ec)
		HX_STACK_LINE(67)
		::haxor::core::Console_obj::Log(HX_CSTRING("Physics> Initialize"),(int)5);
		HX_STACK_LINE(68)
		::haxe::ds::IntMap _g = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(68)
		::haxor::physics::Physics_obj::m_it = _g;
		HX_STACK_LINE(69)
		{
			HX_STACK_LINE(69)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(69)
			while((true)){
				HX_STACK_LINE(69)
				if ((!(((_g1 < (int)32))))){
					HX_STACK_LINE(69)
					break;
				}
				HX_STACK_LINE(69)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(70)
				int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(70)
				while((true)){
					HX_STACK_LINE(70)
					if ((!(((_g11 < (int)32))))){
						HX_STACK_LINE(70)
						break;
					}
					HX_STACK_LINE(70)
					int j = (_g11)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(72)
					::haxor::physics::Physics_obj::SetInteraction((int((int)1) << int(i)),(int((int)1) << int(j)),false);
				}
			}
		}
		HX_STACK_LINE(75)
		::haxor::physics::Physics_obj::SetInteraction((int)1,(int)1,true);
		HX_STACK_LINE(77)
		::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new(0.0,-9.81,0.0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(77)
		::haxor::physics::Physics_obj::gravity = _g1;
		HX_STACK_LINE(78)
		::haxor::physics::broadphase::SAPBroadPhase _g2 = ::haxor::physics::broadphase::SAPBroadPhase_obj::__new();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(78)
		::haxor::physics::Physics_obj::set_broadphase(_g2);
		HX_STACK_LINE(79)
		::haxor::physics::CollisionSolver _g3 = ::haxor::physics::CollisionSolver_obj::__new();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(79)
		::haxor::physics::Physics_obj::m_solver = _g3;
		HX_STACK_LINE(81)
		::haxor::core::Console_obj::Log(HX_CSTRING("\tSAP Broadphase"),(int)5);
		HX_STACK_LINE(82)
		::haxor::core::Console_obj::Log(((HX_CSTRING("\tSolver iterations[") + ::haxor::physics::Physics_obj::m_solver->iterations) + HX_CSTRING("]")),(int)5);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Physics_obj,Initialize,(void))

Void Physics_obj::SetInteraction( int p_layer_bit_a,int p_layer_bit_b,bool p_flag){
{
		HX_STACK_FRAME("haxor.physics.Physics","SetInteraction",0x99f1f2ca,"haxor.physics.Physics.SetInteraction","haxor/physics/Physics.hx",92,0xbec2a6ec)
		HX_STACK_ARG(p_layer_bit_a,"p_layer_bit_a")
		HX_STACK_ARG(p_layer_bit_b,"p_layer_bit_b")
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(93)
		int f = (int(p_layer_bit_a) | int(p_layer_bit_b));		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(94)
		::haxor::physics::Physics_obj::m_it->set(f,p_flag);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Physics_obj,SetInteraction,(void))

bool Physics_obj::CanInteract( int p_layer_bit_a,int p_layer_bit_b){
	HX_STACK_FRAME("haxor.physics.Physics","CanInteract",0x2a64bc2c,"haxor.physics.Physics.CanInteract","haxor/physics/Physics.hx",104,0xbec2a6ec)
	HX_STACK_ARG(p_layer_bit_a,"p_layer_bit_a")
	HX_STACK_ARG(p_layer_bit_b,"p_layer_bit_b")
	HX_STACK_LINE(105)
	int k = (int(p_layer_bit_a) | int(p_layer_bit_b));		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(106)
	if ((::haxor::physics::Physics_obj::m_it->exists(k))){
		HX_STACK_LINE(106)
		return ::haxor::physics::Physics_obj::m_it->get(k);
	}
	else{
		HX_STACK_LINE(106)
		return false;
	}
	HX_STACK_LINE(106)
	return false;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Physics_obj,CanInteract,return )


Physics_obj::Physics_obj()
{
}

Dynamic Physics_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_it") ) { return m_it; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"solver") ) { return get_solver(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"gravity") ) { return gravity; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_solver") ) { return m_solver; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"broadphase") ) { return get_broadphase(); }
		if (HX_FIELD_EQ(inName,"get_solver") ) { return get_solver_dyn(); }
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"CanInteract") ) { return CanInteract_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_broadphase") ) { return m_broadphase; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_broadphase") ) { return get_broadphase_dyn(); }
		if (HX_FIELD_EQ(inName,"set_broadphase") ) { return set_broadphase_dyn(); }
		if (HX_FIELD_EQ(inName,"SetInteraction") ) { return SetInteraction_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Physics_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_it") ) { m_it=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"gravity") ) { gravity=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_solver") ) { m_solver=inValue.Cast< ::haxor::physics::CollisionSolver >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"broadphase") ) { return set_broadphase(inValue); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_broadphase") ) { m_broadphase=inValue.Cast< ::haxor::physics::broadphase::BroadPhase >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Physics_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("gravity"),
	HX_CSTRING("get_broadphase"),
	HX_CSTRING("set_broadphase"),
	HX_CSTRING("m_broadphase"),
	HX_CSTRING("get_solver"),
	HX_CSTRING("m_solver"),
	HX_CSTRING("m_it"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("SetInteraction"),
	HX_CSTRING("CanInteract"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Physics_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Physics_obj::gravity,"gravity");
	HX_MARK_MEMBER_NAME(Physics_obj::m_broadphase,"m_broadphase");
	HX_MARK_MEMBER_NAME(Physics_obj::m_solver,"m_solver");
	HX_MARK_MEMBER_NAME(Physics_obj::m_it,"m_it");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Physics_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Physics_obj::gravity,"gravity");
	HX_VISIT_MEMBER_NAME(Physics_obj::m_broadphase,"m_broadphase");
	HX_VISIT_MEMBER_NAME(Physics_obj::m_solver,"m_solver");
	HX_VISIT_MEMBER_NAME(Physics_obj::m_it,"m_it");
};

#endif

Class Physics_obj::__mClass;

void Physics_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.physics.Physics"), hx::TCanCast< Physics_obj> ,sStaticFields,sMemberFields,
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

void Physics_obj::__boot()
{
}

} // end namespace haxor
} // end namespace physics
