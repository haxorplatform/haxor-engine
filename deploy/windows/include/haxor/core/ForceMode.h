#ifndef INCLUDED_haxor_core_ForceMode
#define INCLUDED_haxor_core_ForceMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,ForceMode)
namespace haxor{
namespace core{


class ForceMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef ForceMode_obj OBJ_;

	public:
		ForceMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.core.ForceMode"); }
		::String __ToString() const { return HX_CSTRING("ForceMode.") + tag; }

		static ::haxor::core::ForceMode Acceleration;
		static inline ::haxor::core::ForceMode Acceleration_dyn() { return Acceleration; }
		static ::haxor::core::ForceMode Force;
		static inline ::haxor::core::ForceMode Force_dyn() { return Force; }
		static ::haxor::core::ForceMode Impulse;
		static inline ::haxor::core::ForceMode Impulse_dyn() { return Impulse; }
		static ::haxor::core::ForceMode Velocity;
		static inline ::haxor::core::ForceMode Velocity_dyn() { return Velocity; }
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_ForceMode */ 
