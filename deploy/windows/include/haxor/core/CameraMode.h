#ifndef INCLUDED_haxor_core_CameraMode
#define INCLUDED_haxor_core_CameraMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,CameraMode)
namespace haxor{
namespace core{


class CameraMode_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef CameraMode_obj OBJ_;

	public:
		CameraMode_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.core.CameraMode"); }
		::String __ToString() const { return HX_CSTRING("CameraMode.") + tag; }

		static ::haxor::core::CameraMode Custom;
		static inline ::haxor::core::CameraMode Custom_dyn() { return Custom; }
		static ::haxor::core::CameraMode Ortho;
		static inline ::haxor::core::CameraMode Ortho_dyn() { return Ortho; }
		static ::haxor::core::CameraMode Perspective;
		static inline ::haxor::core::CameraMode Perspective_dyn() { return Perspective; }
		static ::haxor::core::CameraMode UI;
		static inline ::haxor::core::CameraMode UI_dyn() { return UI; }
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_CameraMode */ 
