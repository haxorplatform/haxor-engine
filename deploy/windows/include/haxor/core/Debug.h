#ifndef INCLUDED_haxor_core_Debug
#define INCLUDED_haxor_core_Debug

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Camera)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,MeshRenderer)
HX_DECLARE_CLASS2(haxor,component,Renderer)
HX_DECLARE_CLASS2(haxor,component,Transform)
HX_DECLARE_CLASS3(haxor,component,light,Light)
HX_DECLARE_CLASS3(haxor,component,physics,Collider)
HX_DECLARE_CLASS2(haxor,core,Debug)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IResizeable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,math,AABB3)
HX_DECLARE_CLASS2(haxor,math,Color)
HX_DECLARE_CLASS2(haxor,math,Vector4)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Debug_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Debug_obj OBJ_;
		Debug_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Debug_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Debug_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Debug"); }

		static bool collider;
		static bool colliderAABB;
		static bool colliderSB;
		static bool transform;
		static bool renderer;
		static bool rendererAABB;
		static bool light;
		static ::haxor::math::Color color_white;
		static ::haxor::math::Color color_collider;
		static ::haxor::math::Color color_trigger;
		static ::haxor::math::Color color_bounding;
		static ::haxor::math::Color color_renderer;
		static ::haxor::math::Color color_light;
		static Void Initialize( );
		static Dynamic Initialize_dyn();

		static Void Collider( ::haxor::component::physics::Collider c);
		static Dynamic Collider_dyn();

		static Void BoundingAABB( ::haxor::math::AABB3 c);
		static Dynamic BoundingAABB_dyn();

		static Void BoundingSphere( ::haxor::math::Vector4 c);
		static Dynamic BoundingSphere_dyn();

		static Void MeshRenderer( ::haxor::component::MeshRenderer r);
		static Dynamic MeshRenderer_dyn();

		static Void Transform( ::haxor::component::Transform t);
		static Dynamic Transform_dyn();

		static Void Camera( ::haxor::component::Camera c);
		static Dynamic Camera_dyn();

		static Void Light( ::haxor::component::light::Light l);
		static Dynamic Light_dyn();

};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Debug */ 
