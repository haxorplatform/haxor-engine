#ifndef INCLUDED_haxor_graphics_BufferPrimitive
#define INCLUDED_haxor_graphics_BufferPrimitive

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,graphics,BufferPrimitive)
namespace haxor{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  BufferPrimitive_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BufferPrimitive_obj OBJ_;
		BufferPrimitive_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BufferPrimitive_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BufferPrimitive_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("BufferPrimitive"); }

		static int U8;
		static int U16;
		static int U32;
		static int I8;
		static int I16;
		static int I32;
		static int F32;
		static int F64;
};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_BufferPrimitive */ 
