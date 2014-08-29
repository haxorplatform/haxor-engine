#ifndef INCLUDED_haxor_core_TextureType
#define INCLUDED_haxor_core_TextureType

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,TextureType)
namespace haxor{
namespace core{


class TextureType_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TextureType_obj OBJ_;

	public:
		TextureType_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.core.TextureType"); }
		::String __ToString() const { return HX_CSTRING("TextureType.") + tag; }

		static ::haxor::core::TextureType None;
		static inline ::haxor::core::TextureType None_dyn() { return None; }
		static ::haxor::core::TextureType RenderTexture;
		static inline ::haxor::core::TextureType RenderTexture_dyn() { return RenderTexture; }
		static ::haxor::core::TextureType Texture2D;
		static inline ::haxor::core::TextureType Texture2D_dyn() { return Texture2D; }
		static ::haxor::core::TextureType TextureCube;
		static inline ::haxor::core::TextureType TextureCube_dyn() { return TextureCube; }
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_TextureType */ 
