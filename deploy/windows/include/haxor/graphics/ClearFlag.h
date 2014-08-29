#ifndef INCLUDED_haxor_graphics_ClearFlag
#define INCLUDED_haxor_graphics_ClearFlag

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,graphics,ClearFlag)
namespace haxor{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  ClearFlag_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ClearFlag_obj OBJ_;
		ClearFlag_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ClearFlag_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ClearFlag_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("ClearFlag"); }

		static int None;
		static int Color;
		static int Depth;
		static int Skybox;
		static int ColorDepth;
		static int SkyboxDepth;
};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_ClearFlag */ 
