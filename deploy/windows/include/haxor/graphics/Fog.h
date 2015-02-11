#ifndef INCLUDED_haxor_graphics_Fog
#define INCLUDED_haxor_graphics_Fog

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,graphics,Fog)
HX_DECLARE_CLASS2(haxor,math,Color)
namespace haxor{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  Fog_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Fog_obj OBJ_;
		Fog_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Fog_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Fog_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Fog"); }

		static ::haxor::math::Color color;
		static Float density;
		static Float exp;
		static Float start;
		static Float end;
};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_Fog */ 
