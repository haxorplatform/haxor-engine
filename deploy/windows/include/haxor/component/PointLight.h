#ifndef INCLUDED_haxor_component_PointLight
#define INCLUDED_haxor_component_PointLight

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/Light.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,Light)
HX_DECLARE_CLASS2(haxor,component,PointLight)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,math,Color)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  PointLight_obj : public ::haxor::component::Light_obj{
	public:
		typedef ::haxor::component::Light_obj super;
		typedef PointLight_obj OBJ_;
		PointLight_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PointLight_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PointLight_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("PointLight"); }

		Float atten;
		Float radius;
		static ::haxor::component::PointLight Create( ::haxor::math::Color p_color,Float p_intensity,Float p_atten,Float p_radius);
		static Dynamic Create_dyn();

};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_PointLight */ 
