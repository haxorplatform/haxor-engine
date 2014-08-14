#ifndef INCLUDED_haxor_graphics_DepthTest
#define INCLUDED_haxor_graphics_DepthTest

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,graphics,DepthTest)
namespace haxor{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  DepthTest_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef DepthTest_obj OBJ_;
		DepthTest_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< DepthTest_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~DepthTest_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("DepthTest"); }

		static int Never;
		static int Less;
		static int Equal;
		static int LessEqual;
		static int Greater;
		static int NotEqual;
		static int GreaterEqual;
		static int Always;
};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_DepthTest */ 
