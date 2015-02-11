#ifndef INCLUDED_haxor_component_physics_Collider
#define INCLUDED_haxor_component_physics_Collider

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/Behaviour.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS3(haxor,component,physics,Collider)
HX_DECLARE_CLASS2(haxor,core,ColliderType)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,math,AABB3)
HX_DECLARE_CLASS2(haxor,math,Vector4)
HX_DECLARE_CLASS2(haxor,physics,PhysicsMaterial)
namespace haxor{
namespace component{
namespace physics{


class HXCPP_CLASS_ATTRIBUTES  Collider_obj : public ::haxor::component::Behaviour_obj{
	public:
		typedef ::haxor::component::Behaviour_obj super;
		typedef Collider_obj OBJ_;
		Collider_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Collider_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Collider_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Collider"); }

		virtual ::haxor::core::ColliderType get_type( );
		Dynamic get_type_dyn();

		::haxor::core::ColliderType m_type;
		virtual bool set_enabled( bool v);

		bool trigger;
		::haxor::physics::PhysicsMaterial material;
		virtual ::haxor::math::Vector4 get_sphere( );
		Dynamic get_sphere_dyn();

		::haxor::math::Vector4 m_sphere;
		bool m_sphere_dirty;
		virtual ::haxor::math::AABB3 get_aabb( );
		Dynamic get_aabb_dyn();

		::haxor::math::AABB3 m_aabb;
		bool m_aabb_dirty;
		virtual Void OnBuild( );

		virtual Void OnTransformUpdate( bool p_hierarchy);

		virtual Void GenerateSphere( );
		Dynamic GenerateSphere_dyn();

		virtual Void GenerateAABB( );
		Dynamic GenerateAABB_dyn();

		virtual Void Refresh( );
		Dynamic Refresh_dyn();

};

} // end namespace haxor
} // end namespace component
} // end namespace physics

#endif /* INCLUDED_haxor_component_physics_Collider */ 
