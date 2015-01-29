#ifndef INCLUDED_haxor_component_light_Light
#define INCLUDED_haxor_component_light_Light

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/Behaviour.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS3(haxor,component,light,Light)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS2(haxor,io,FloatArray)
HX_DECLARE_CLASS2(haxor,math,Color)
namespace haxor{
namespace component{
namespace light{


class HXCPP_CLASS_ATTRIBUTES  Light_obj : public ::haxor::component::Behaviour_obj{
	public:
		typedef ::haxor::component::Behaviour_obj super;
		typedef Light_obj OBJ_;
		Light_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Light_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Light_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Light"); }

		::haxor::math::Color color;
		Float intensity;
		virtual Void OnDestroy( );

		static ::haxor::math::Color ambient;
		static int max;
		static ::haxor::io::FloatArray m_buffer;
		static Array< ::Dynamic > list;
		static Array< ::Dynamic > m_list;
		static Array< ::Dynamic > get_list( );
		static Dynamic get_list_dyn();

		static Void SetLightData( int p_id,Float p_type,Float p_intensity,Float p_radius,Float p_atten,Float p_x,Float p_y,Float p_z,Float p_r,Float p_g,Float p_b,Float p_a);
		static Dynamic SetLightData_dyn();

};

} // end namespace haxor
} // end namespace component
} // end namespace light

#endif /* INCLUDED_haxor_component_light_Light */ 
