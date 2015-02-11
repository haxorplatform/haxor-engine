#ifndef INCLUDED_haxor_physics_PhysicsMaterial
#define INCLUDED_haxor_physics_PhysicsMaterial

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Resource.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,physics,PhysicsMaterial)
namespace haxor{
namespace physics{


class HXCPP_CLASS_ATTRIBUTES  PhysicsMaterial_obj : public ::haxor::core::Resource_obj{
	public:
		typedef ::haxor::core::Resource_obj super;
		typedef PhysicsMaterial_obj OBJ_;
		PhysicsMaterial_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PhysicsMaterial_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PhysicsMaterial_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("PhysicsMaterial"); }

		Float bounce;
		Float friction;
		static ::haxor::physics::PhysicsMaterial m_empty;
		static ::haxor::physics::PhysicsMaterial get_empty( );
		static Dynamic get_empty_dyn();

};

} // end namespace haxor
} // end namespace physics

#endif /* INCLUDED_haxor_physics_PhysicsMaterial */ 
