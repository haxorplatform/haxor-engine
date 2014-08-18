#ifndef INCLUDED_haxor_graphics_TextureFilter
#define INCLUDED_haxor_graphics_TextureFilter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,graphics,TextureFilter)
namespace haxor{
namespace graphics{


class TextureFilter_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TextureFilter_obj OBJ_;

	public:
		TextureFilter_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.graphics.TextureFilter"); }
		::String __ToString() const { return HX_CSTRING("TextureFilter.") + tag; }

		static ::haxor::graphics::TextureFilter Linear;
		static inline ::haxor::graphics::TextureFilter Linear_dyn() { return Linear; }
		static ::haxor::graphics::TextureFilter LinearMipmapLinear;
		static inline ::haxor::graphics::TextureFilter LinearMipmapLinear_dyn() { return LinearMipmapLinear; }
		static ::haxor::graphics::TextureFilter LinearMipmapNearest;
		static inline ::haxor::graphics::TextureFilter LinearMipmapNearest_dyn() { return LinearMipmapNearest; }
		static ::haxor::graphics::TextureFilter Nearest;
		static inline ::haxor::graphics::TextureFilter Nearest_dyn() { return Nearest; }
		static ::haxor::graphics::TextureFilter NearestMipmapLinear;
		static inline ::haxor::graphics::TextureFilter NearestMipmapLinear_dyn() { return NearestMipmapLinear; }
		static ::haxor::graphics::TextureFilter NearestMipmapNearest;
		static inline ::haxor::graphics::TextureFilter NearestMipmapNearest_dyn() { return NearestMipmapNearest; }
		static ::haxor::graphics::TextureFilter Trilinear;
		static inline ::haxor::graphics::TextureFilter Trilinear_dyn() { return Trilinear; }
};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_TextureFilter */ 
