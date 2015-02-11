#ifndef INCLUDED_haxor_context_PhysicsContext
#define INCLUDED_haxor_context_PhysicsContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS3(haxor,component,physics,Collider)
HX_DECLARE_CLASS3(haxor,component,physics,RigidBody)
HX_DECLARE_CLASS2(haxor,context,PhysicsContext)
HX_DECLARE_CLASS2(haxor,context,UID)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  PhysicsContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef PhysicsContext_obj OBJ_;
		PhysicsContext_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PhysicsContext_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PhysicsContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PhysicsContext"); }

		::haxor::context::UID rid;
		::haxor::context::UID cid;
		Array< ::Dynamic > colliders;
		Array< ::Dynamic > rigidbodies;
		Array< ::Dynamic > rbc;
		Array< ::Dynamic > crb;
		Array< bool > collider_dirty;
		Float accum_dt;
		virtual Void Initialize( );
		Dynamic Initialize_dyn();

		virtual Void CreateCollider( ::haxor::component::physics::Collider c);
		Dynamic CreateCollider_dyn();

		virtual Void OnColliderUpdate( ::haxor::component::physics::Collider c,bool h);
		Dynamic OnColliderUpdate_dyn();

		virtual Void CreateRigidBody( ::haxor::component::physics::RigidBody r);
		Dynamic CreateRigidBody_dyn();

		virtual Void Step( );
		Dynamic Step_dyn();

		virtual Void UpdateColliders( );
		Dynamic UpdateColliders_dyn();

		virtual Void DestroyCollider( ::haxor::component::physics::Collider c);
		Dynamic DestroyCollider_dyn();

		virtual Void DestroyRigidBody( ::haxor::component::physics::RigidBody r);
		Dynamic DestroyRigidBody_dyn();

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_PhysicsContext */ 
