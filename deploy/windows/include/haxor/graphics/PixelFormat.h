#ifndef INCLUDED_haxor_graphics_PixelFormat
#define INCLUDED_haxor_graphics_PixelFormat

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,graphics,PixelFormat)
namespace haxor{
namespace graphics{


class PixelFormat_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef PixelFormat_obj OBJ_;

	public:
		PixelFormat_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.graphics.PixelFormat"); }
		::String __ToString() const { return HX_CSTRING("PixelFormat.") + tag; }

		static ::haxor::graphics::PixelFormat Alpha8;
		static inline ::haxor::graphics::PixelFormat Alpha8_dyn() { return Alpha8; }
		static ::haxor::graphics::PixelFormat Depth;
		static inline ::haxor::graphics::PixelFormat Depth_dyn() { return Depth; }
		static ::haxor::graphics::PixelFormat _Float;
		static inline ::haxor::graphics::PixelFormat _Float_dyn() { return _Float; }
		static ::haxor::graphics::PixelFormat Float3;
		static inline ::haxor::graphics::PixelFormat Float3_dyn() { return Float3; }
		static ::haxor::graphics::PixelFormat Float4;
		static inline ::haxor::graphics::PixelFormat Float4_dyn() { return Float4; }
		static ::haxor::graphics::PixelFormat Half;
		static inline ::haxor::graphics::PixelFormat Half_dyn() { return Half; }
		static ::haxor::graphics::PixelFormat Half3;
		static inline ::haxor::graphics::PixelFormat Half3_dyn() { return Half3; }
		static ::haxor::graphics::PixelFormat Half4;
		static inline ::haxor::graphics::PixelFormat Half4_dyn() { return Half4; }
		static ::haxor::graphics::PixelFormat Luminance;
		static inline ::haxor::graphics::PixelFormat Luminance_dyn() { return Luminance; }
		static ::haxor::graphics::PixelFormat RGB8;
		static inline ::haxor::graphics::PixelFormat RGB8_dyn() { return RGB8; }
		static ::haxor::graphics::PixelFormat RGBA8;
		static inline ::haxor::graphics::PixelFormat RGBA8_dyn() { return RGBA8; }
};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_PixelFormat */ 
