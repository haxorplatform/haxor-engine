#ifndef INCLUDED_haxor_core_InputState
#define INCLUDED_haxor_core_InputState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,InputState)
namespace haxor{
namespace core{


class InputState_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef InputState_obj OBJ_;

	public:
		InputState_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.core.InputState"); }
		::String __ToString() const { return HX_CSTRING("InputState.") + tag; }

		static ::haxor::core::InputState Down;
		static inline ::haxor::core::InputState Down_dyn() { return Down; }
		static ::haxor::core::InputState Hold;
		static inline ::haxor::core::InputState Hold_dyn() { return Hold; }
		static ::haxor::core::InputState None;
		static inline ::haxor::core::InputState None_dyn() { return None; }
		static ::haxor::core::InputState Up;
		static inline ::haxor::core::InputState Up_dyn() { return Up; }
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_InputState */ 
