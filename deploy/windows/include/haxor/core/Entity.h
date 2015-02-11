#ifndef INCLUDED_haxor_core_Entity
#define INCLUDED_haxor_core_Entity

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Resource.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Camera)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,DataComponent)
HX_DECLARE_CLASS2(haxor,component,Renderer)
HX_DECLARE_CLASS2(haxor,component,Transform)
HX_DECLARE_CLASS3(haxor,component,animation,Animation)
HX_DECLARE_CLASS3(haxor,component,physics,RigidBody)
HX_DECLARE_CLASS2(haxor,core,Entity)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IResizeable)
HX_DECLARE_CLASS2(haxor,core,Resource)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Entity_obj : public ::haxor::core::Resource_obj{
	public:
		typedef ::haxor::core::Resource_obj super;
		typedef Entity_obj OBJ_;
		Entity_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Entity_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Entity_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Entity"); }

		virtual bool get_enabled( );
		Dynamic get_enabled_dyn();

		virtual bool set_enabled( bool v);
		Dynamic set_enabled_dyn();

		bool m_enabled;
		::haxor::component::Transform transform;
		virtual ::haxor::component::Transform get_transform( );
		Dynamic get_transform_dyn();

		::haxor::component::Transform m_transform;
		virtual ::haxor::component::Camera get_camera( );
		Dynamic get_camera_dyn();

		virtual ::haxor::component::DataComponent get_data( );
		Dynamic get_data_dyn();

		virtual ::haxor::component::animation::Animation get_animation( );
		Dynamic get_animation_dyn();

		virtual ::haxor::component::Renderer get_renderer( );
		Dynamic get_renderer_dyn();

		virtual ::haxor::component::physics::RigidBody get_rigidbody( );
		Dynamic get_rigidbody_dyn();

		virtual int get_layer( );
		Dynamic get_layer_dyn();

		virtual int set_layer( int v);
		Dynamic set_layer_dyn();

		int m_layer;
		Array< ::Dynamic > m_components;
		virtual Dynamic AddComponent( ::Class p_type);
		Dynamic AddComponent_dyn();

		virtual Dynamic GetComponent( ::Class p_type);
		Dynamic GetComponent_dyn();

		virtual Dynamic GetComponents( ::Class p_type);
		Dynamic GetComponents_dyn();

		virtual Dynamic GetComponentInChildren( ::Class p_type);
		Dynamic GetComponentInChildren_dyn();

		virtual Dynamic GetComponentsInChildren( ::Class p_type);
		Dynamic GetComponentsInChildren_dyn();

		virtual Void OnDestroy( );

};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Entity */ 
