#ifndef INCLUDED_haxor_graphics_Gizmo
#define INCLUDED_haxor_graphics_Gizmo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,graphics,Gizmo)
HX_DECLARE_CLASS2(haxor,math,Color)
HX_DECLARE_CLASS2(haxor,math,Matrix4)
HX_DECLARE_CLASS2(haxor,math,Vector3)
namespace haxor{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  Gizmo_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Gizmo_obj OBJ_;
		Gizmo_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Gizmo_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Gizmo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Gizmo"); }

		static Void Grid( Float p_area,::haxor::math::Color p_color);
		static Dynamic Grid_dyn();

		static Void Axis( ::haxor::math::Vector3 p_position,::haxor::math::Vector3 p_size,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform);
		static Dynamic Axis_dyn();

		static Void Line( ::haxor::math::Vector3 p_from,::haxor::math::Vector3 p_to,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform);
		static Dynamic Line_dyn();

		static Void Point( ::haxor::math::Vector3 p_position,hx::Null< Float >  p_size,::haxor::math::Color p_color,hx::Null< bool >  p_smooth,::haxor::math::Matrix4 p_transform);
		static Dynamic Point_dyn();

		static Void WireSphere( ::haxor::math::Vector3 p_position,hx::Null< Float >  p_radius,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform);
		static Dynamic WireSphere_dyn();

		static Void WireCube( ::haxor::math::Vector3 p_position,::haxor::math::Vector3 p_size,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform);
		static Dynamic WireCube_dyn();

		static Void BeginPath( ::haxor::math::Color p_fill,::haxor::math::Color p_line,::haxor::math::Matrix4 p_transform);
		static Dynamic BeginPath_dyn();

		static Void LinePath( ::haxor::math::Vector3 p_position);
		static Dynamic LinePath_dyn();

		static Void EndPath( );
		static Dynamic EndPath_dyn();

};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_Gizmo */ 
