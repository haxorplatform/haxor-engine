#ifndef INCLUDED_haxor_physics_Collision
#define INCLUDED_haxor_physics_Collision

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/ds/IUSetItem.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS3(haxor,component,physics,Collider)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,ds,IUSetItem)
HX_DECLARE_CLASS2(haxor,math,Vector3)
HX_DECLARE_CLASS2(haxor,physics,Collision)
namespace haxor{
namespace physics{


class HXCPP_CLASS_ATTRIBUTES  Collision_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Collision_obj OBJ_;
		Collision_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Collision_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Collision_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::haxor::ds::IUSetItem_obj *()
			{ return new ::haxor::ds::IUSetItem_delegate_< Collision_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Collision"); }

		int usid;
		::haxor::component::physics::Collider from;
		::haxor::component::physics::Collider to;
		::haxor::math::Vector3 point;
		Float depth;
		::haxor::math::Vector3 normal;
		Float speed;
		virtual ::haxor::physics::Collision Invert( );
		Dynamic Invert_dyn();

		virtual Void Reset( );
		Dynamic Reset_dyn();

};

} // end namespace haxor
} // end namespace physics

#endif /* INCLUDED_haxor_physics_Collision */ 
