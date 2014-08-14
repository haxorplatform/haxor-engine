#ifndef INCLUDED_haxor_graphics_BlendMode
#define INCLUDED_haxor_graphics_BlendMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,graphics,BlendMode)
namespace haxor{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  BlendMode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BlendMode_obj OBJ_;
		BlendMode_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BlendMode_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BlendMode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("BlendMode"); }

		static int Zero;
		static int One;
		static int SrcColor;
		static int OneMinusSrcColor;
		static int SrcAlpha;
		static int OneMinusSrcAlpha;
		static int DstAlpha;
		static int OneMinusDstAlpha;
		static int DstColor;
		static int OneMinusDstColor;
		static int SrcAlphaSaturate;
};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_BlendMode */ 
