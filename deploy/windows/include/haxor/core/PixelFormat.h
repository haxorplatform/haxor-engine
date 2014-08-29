#ifndef INCLUDED_haxor_core_PixelFormat
#define INCLUDED_haxor_core_PixelFormat

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,PixelFormat)
namespace haxor{
namespace core{


class PixelFormat_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef PixelFormat_obj OBJ_;

	public:
		PixelFormat_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.core.PixelFormat"); }
		::String __ToString() const { return HX_CSTRING("PixelFormat.") + tag; }

		static ::haxor::core::PixelFormat Alpha8;
		static inline ::haxor::core::PixelFormat Alpha8_dyn() { return Alpha8; }
		static ::haxor::core::PixelFormat Depth;
		static inline ::haxor::core::PixelFormat Depth_dyn() { return Depth; }
		static ::haxor::core::PixelFormat _Float;
		static inline ::haxor::core::PixelFormat _Float_dyn() { return _Float; }
		static ::haxor::core::PixelFormat Float3;
		static inline ::haxor::core::PixelFormat Float3_dyn() { return Float3; }
		static ::haxor::core::PixelFormat Float4;
		static inline ::haxor::core::PixelFormat Float4_dyn() { return Float4; }
		static ::haxor::core::PixelFormat Half;
		static inline ::haxor::core::PixelFormat Half_dyn() { return Half; }
		static ::haxor::core::PixelFormat Half3;
		static inline ::haxor::core::PixelFormat Half3_dyn() { return Half3; }
		static ::haxor::core::PixelFormat Half4;
		static inline ::haxor::core::PixelFormat Half4_dyn() { return Half4; }
		static ::haxor::core::PixelFormat Luminance;
		static inline ::haxor::core::PixelFormat Luminance_dyn() { return Luminance; }
		static ::haxor::core::PixelFormat RGB8;
		static inline ::haxor::core::PixelFormat RGB8_dyn() { return RGB8; }
		static ::haxor::core::PixelFormat RGBA8;
		static inline ::haxor::core::PixelFormat RGBA8_dyn() { return RGBA8; }
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_PixelFormat */ 
