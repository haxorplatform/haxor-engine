#ifndef INCLUDED_haxor_physics_broadphase_BroadPhase
#define INCLUDED_haxor_physics_broadphase_BroadPhase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS3(haxor,component,physics,Collider)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,ds,IUSetItem)
HX_DECLARE_CLASS2(haxor,ds,PairTable)
HX_DECLARE_CLASS2(haxor,ds,USet)
HX_DECLARE_CLASS2(haxor,physics,Collision)
HX_DECLARE_CLASS3(haxor,physics,broadphase,BroadPhase)
namespace haxor{
namespace physics{
namespace broadphase{


class HXCPP_CLASS_ATTRIBUTES  BroadPhase_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BroadPhase_obj OBJ_;
		BroadPhase_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BroadPhase_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BroadPhase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BroadPhase"); }

		::haxor::ds::USet pairs;
		::haxor::ds::PairTable m_table;
		virtual Void Initialize( );
		Dynamic Initialize_dyn();

		virtual Void Step( );
		Dynamic Step_dyn();

		virtual Void Update( ::haxor::component::physics::Collider c);
		Dynamic Update_dyn();

		virtual Void Add( ::haxor::component::physics::Collider c);
		Dynamic Add_dyn();

		virtual Void Remove( ::haxor::component::physics::Collider c);
		Dynamic Remove_dyn();

		virtual Void Query( ::haxor::component::physics::Collider c);
		Dynamic Query_dyn();

		virtual Void Clear( ::haxor::component::physics::Collider c);
		Dynamic Clear_dyn();

		virtual Void OnFetch( ::haxor::component::physics::Collider a,::haxor::component::physics::Collider b);
		Dynamic OnFetch_dyn();

		virtual Void InitCollisions( int p_x,int p_y,::haxor::physics::Collision p_v);
		Dynamic InitCollisions_dyn();

};

} // end namespace haxor
} // end namespace physics
} // end namespace broadphase

#endif /* INCLUDED_haxor_physics_broadphase_BroadPhase */ 
