#ifndef INCLUDED_haxor_graphics_TextureType
#define INCLUDED_haxor_graphics_TextureType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,graphics,TextureType)
namespace haxor{
namespace graphics{


class TextureType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TextureType_obj OBJ_;

	public:
		TextureType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.graphics.TextureType"); }
		::String __ToString() const { return HX_CSTRING("TextureType.") + tag; }

		static ::haxor::graphics::TextureType None;
		static inline ::haxor::graphics::TextureType None_dyn() { return None; }
		static ::haxor::graphics::TextureType RenderTexture;
		static inline ::haxor::graphics::TextureType RenderTexture_dyn() { return RenderTexture; }
		static ::haxor::graphics::TextureType Texture2D;
		static inline ::haxor::graphics::TextureType Texture2D_dyn() { return Texture2D; }
		static ::haxor::graphics::TextureType TextureCube;
		static inline ::haxor::graphics::TextureType TextureCube_dyn() { return TextureCube; }
};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_TextureType */ 
