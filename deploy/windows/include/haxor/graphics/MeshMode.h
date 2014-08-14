#ifndef INCLUDED_haxor_graphics_MeshMode
#define INCLUDED_haxor_graphics_MeshMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,graphics,MeshMode)
namespace haxor{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  MeshMode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MeshMode_obj OBJ_;
		MeshMode_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MeshMode_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MeshMode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("MeshMode"); }

		static int StaticDraw;
		static int StreamDraw;
		static int DynamicDraw;
};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_MeshMode */ 
