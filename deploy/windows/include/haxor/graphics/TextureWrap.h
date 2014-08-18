#ifndef INCLUDED_haxor_graphics_TextureWrap
#define INCLUDED_haxor_graphics_TextureWrap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,graphics,TextureWrap)
namespace haxor{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  TextureWrap_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TextureWrap_obj OBJ_;
		TextureWrap_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TextureWrap_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TextureWrap_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("TextureWrap"); }

		static int ClampX;
		static int RepeatX;
		static int ClampY;
		static int RepeatY;
		static int ClampZ;
		static int RepeatZ;
};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_TextureWrap */ 
