#ifndef INCLUDED_haxor_component_physics_SphereCollider
#define INCLUDED_haxor_component_physics_SphereCollider

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/physics/Collider.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS3(haxor,component,physics,Collider)
HX_DECLARE_CLASS3(haxor,component,physics,SphereCollider)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,math,Vector3)
namespace haxor{
namespace component{
namespace physics{


class HXCPP_CLASS_ATTRIBUTES  SphereCollider_obj : public ::haxor::component::physics::Collider_obj{
	public:
		typedef ::haxor::component::physics::Collider_obj super;
		typedef SphereCollider_obj OBJ_;
		SphereCollider_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SphereCollider_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SphereCollider_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SphereCollider"); }

		virtual ::haxor::math::Vector3 get_center( );
		Dynamic get_center_dyn();

		virtual ::haxor::math::Vector3 set_center( ::haxor::math::Vector3 v);
		Dynamic set_center_dyn();

		::haxor::math::Vector3 m_center;
		virtual Float get_radius( );
		Dynamic get_radius_dyn();

		virtual Float set_radius( Float v);
		Dynamic set_radius_dyn();

		Float m_radius;
		virtual Void OnBuild( );

		virtual Void GenerateSphere( );

		virtual Void GenerateAABB( );

};

} // end namespace haxor
} // end namespace component
} // end namespace physics

#endif /* INCLUDED_haxor_component_physics_SphereCollider */ 
