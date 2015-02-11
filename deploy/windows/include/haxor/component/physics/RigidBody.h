#ifndef INCLUDED_haxor_component_physics_RigidBody
#define INCLUDED_haxor_component_physics_RigidBody

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/Behaviour.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS3(haxor,component,physics,RigidBody)
HX_DECLARE_CLASS2(haxor,core,ForceMode)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,math,Quaternion)
HX_DECLARE_CLASS2(haxor,math,Vector3)
namespace haxor{
namespace component{
namespace physics{


class HXCPP_CLASS_ATTRIBUTES  RigidBody_obj : public ::haxor::component::Behaviour_obj{
	public:
		typedef ::haxor::component::Behaviour_obj super;
		typedef RigidBody_obj OBJ_;
		RigidBody_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< RigidBody_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~RigidBody_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("RigidBody"); }

		virtual ::haxor::math::Vector3 get_velocity( );
		Dynamic get_velocity_dyn();

		virtual ::haxor::math::Vector3 set_velocity( ::haxor::math::Vector3 v);
		Dynamic set_velocity_dyn();

		::haxor::math::Vector3 m_velocity;
		::haxor::math::Vector3 m_direction;
		::haxor::math::Vector3 m_dragForce;
		Float m_speed;
		virtual ::haxor::math::Vector3 get_angularVelocity( );
		Dynamic get_angularVelocity_dyn();

		virtual ::haxor::math::Vector3 set_angularVelocity( ::haxor::math::Vector3 v);
		Dynamic set_angularVelocity_dyn();

		::haxor::math::Vector3 m_angularVelocity;
		::haxor::math::Vector3 m_angularDirection;
		::haxor::math::Vector3 m_dragTorque;
		Float m_angularSpeed;
		bool gravity;
		virtual Float get_drag( );
		Dynamic get_drag_dyn();

		virtual Float set_drag( Float v);
		Dynamic set_drag_dyn();

		Float m_drag;
		Float m_idrag;
		virtual Float get_angularDrag( );
		Dynamic get_angularDrag_dyn();

		virtual Float set_angularDrag( Float v);
		Dynamic set_angularDrag_dyn();

		Float m_angularDrag;
		Float m_iangularDrag;
		virtual Float get_mass( );
		Dynamic get_mass_dyn();

		virtual Float set_mass( Float v);
		Dynamic set_mass_dyn();

		Float m_mass;
		Float m_imass;
		::haxor::math::Vector3 centerOfMass;
		bool kinematic;
		::haxor::math::Vector3 m_accel;
		::haxor::math::Vector3 m_torque;
		bool m_hasForce;
		bool m_hasTorque;
		::haxor::math::Quaternion m_avq;
		virtual Void OnBuild( );

		virtual Void AddTorque( ::haxor::math::Vector3 p_torque,::haxor::core::ForceMode p_mode);
		Dynamic AddTorque_dyn();

		virtual Void AddForce( ::haxor::math::Vector3 p_force,::haxor::core::ForceMode p_mode);
		Dynamic AddForce_dyn();

		virtual Void OnDestroy( );

		virtual Void ComputeForces( );
		Dynamic ComputeForces_dyn();

		virtual Void IntegrateVelocity( Float p_dt);
		Dynamic IntegrateVelocity_dyn();

		virtual Void IntegratePosition( Float p_dt);
		Dynamic IntegratePosition_dyn();

		virtual Void ResetForces( );
		Dynamic ResetForces_dyn();

};

} // end namespace haxor
} // end namespace component
} // end namespace physics

#endif /* INCLUDED_haxor_component_physics_RigidBody */ 
