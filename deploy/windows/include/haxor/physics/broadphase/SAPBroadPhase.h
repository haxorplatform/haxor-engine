#ifndef INCLUDED_haxor_physics_broadphase_SAPBroadPhase
#define INCLUDED_haxor_physics_broadphase_SAPBroadPhase

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/physics/broadphase/BroadPhase.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS3(haxor,component,physics,Collider)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,ds,SAP)
HX_DECLARE_CLASS3(haxor,physics,broadphase,BroadPhase)
HX_DECLARE_CLASS3(haxor,physics,broadphase,SAPBroadPhase)
namespace haxor{
namespace physics{
namespace broadphase{


class HXCPP_CLASS_ATTRIBUTES  SAPBroadPhase_obj : public ::haxor::physics::broadphase::BroadPhase_obj{
	public:
		typedef ::haxor::physics::broadphase::BroadPhase_obj super;
		typedef SAPBroadPhase_obj OBJ_;
		SAPBroadPhase_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SAPBroadPhase_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SAPBroadPhase_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SAPBroadPhase"); }

		::haxor::ds::SAP sap;
		virtual Void Initialize( );

		virtual Void Update( ::haxor::component::physics::Collider c);

		virtual Void Add( ::haxor::component::physics::Collider c);

		virtual Void Remove( ::haxor::component::physics::Collider c);

		virtual Void Query( ::haxor::component::physics::Collider c);

		virtual Void OnSAPFetch( Dynamic a,Dynamic b);
		Dynamic OnSAPFetch_dyn();

};

} // end namespace haxor
} // end namespace physics
} // end namespace broadphase

#endif /* INCLUDED_haxor_physics_broadphase_SAPBroadPhase */ 
