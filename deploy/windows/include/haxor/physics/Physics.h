#ifndef INCLUDED_haxor_physics_Physics
#define INCLUDED_haxor_physics_Physics

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,IntMap)
HX_DECLARE_CLASS2(haxor,math,Vector3)
HX_DECLARE_CLASS2(haxor,physics,CollisionSolver)
HX_DECLARE_CLASS2(haxor,physics,Physics)
HX_DECLARE_CLASS3(haxor,physics,broadphase,BroadPhase)
namespace haxor{
namespace physics{


class HXCPP_CLASS_ATTRIBUTES  Physics_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Physics_obj OBJ_;
		Physics_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Physics_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Physics_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Physics"); }

		static ::haxor::math::Vector3 gravity;
		static ::haxor::physics::broadphase::BroadPhase get_broadphase( );
		static Dynamic get_broadphase_dyn();

		static ::haxor::physics::broadphase::BroadPhase set_broadphase( ::haxor::physics::broadphase::BroadPhase v);
		static Dynamic set_broadphase_dyn();

		static ::haxor::physics::broadphase::BroadPhase m_broadphase;
		static ::haxor::physics::CollisionSolver get_solver( );
		static Dynamic get_solver_dyn();

		static ::haxor::physics::CollisionSolver m_solver;
		static ::haxe::ds::IntMap m_it;
		static Void Initialize( );
		static Dynamic Initialize_dyn();

		static Void SetInteraction( int p_layer_bit_a,int p_layer_bit_b,bool p_flag);
		static Dynamic SetInteraction_dyn();

		static bool CanInteract( int p_layer_bit_a,int p_layer_bit_b);
		static Dynamic CanInteract_dyn();

};

} // end namespace haxor
} // end namespace physics

#endif /* INCLUDED_haxor_physics_Physics */ 
