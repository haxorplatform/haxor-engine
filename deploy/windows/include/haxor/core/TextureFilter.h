#ifndef INCLUDED_haxor_core_TextureFilter
#define INCLUDED_haxor_core_TextureFilter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,TextureFilter)
namespace haxor{
namespace core{


class TextureFilter_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TextureFilter_obj OBJ_;

	public:
		TextureFilter_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.core.TextureFilter"); }
		::String __ToString() const { return HX_CSTRING("TextureFilter.") + tag; }

		static ::haxor::core::TextureFilter Linear;
		static inline ::haxor::core::TextureFilter Linear_dyn() { return Linear; }
		static ::haxor::core::TextureFilter LinearMipmapLinear;
		static inline ::haxor::core::TextureFilter LinearMipmapLinear_dyn() { return LinearMipmapLinear; }
		static ::haxor::core::TextureFilter LinearMipmapNearest;
		static inline ::haxor::core::TextureFilter LinearMipmapNearest_dyn() { return LinearMipmapNearest; }
		static ::haxor::core::TextureFilter Nearest;
		static inline ::haxor::core::TextureFilter Nearest_dyn() { return Nearest; }
		static ::haxor::core::TextureFilter NearestMipmapLinear;
		static inline ::haxor::core::TextureFilter NearestMipmapLinear_dyn() { return NearestMipmapLinear; }
		static ::haxor::core::TextureFilter NearestMipmapNearest;
		static inline ::haxor::core::TextureFilter NearestMipmapNearest_dyn() { return NearestMipmapNearest; }
		static ::haxor::core::TextureFilter Trilinear;
		static inline ::haxor::core::TextureFilter Trilinear_dyn() { return Trilinear; }
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_TextureFilter */ 
