#ifndef INCLUDED_haxor_core_AnimationWrap
#define INCLUDED_haxor_core_AnimationWrap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,AnimationWrap)
namespace haxor{
namespace core{


class AnimationWrap_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef AnimationWrap_obj OBJ_;

	public:
		AnimationWrap_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.core.AnimationWrap"); }
		::String __ToString() const { return HX_CSTRING("AnimationWrap.") + tag; }

		static ::haxor::core::AnimationWrap Clamp;
		static inline ::haxor::core::AnimationWrap Clamp_dyn() { return Clamp; }
		static ::haxor::core::AnimationWrap Loop;
		static inline ::haxor::core::AnimationWrap Loop_dyn() { return Loop; }
		static ::haxor::core::AnimationWrap Oscilate;
		static inline ::haxor::core::AnimationWrap Oscilate_dyn() { return Oscilate; }
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_AnimationWrap */ 
