#ifndef INCLUDED_haxor_graphics_Gizmo
#define INCLUDED_haxor_graphics_Gizmo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,graphics,Gizmo)
HX_DECLARE_CLASS2(haxor,math,Color)
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

		static Void Axis( Float p_area);
		static Dynamic Axis_dyn();

};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_Gizmo */ 
