#ifndef INCLUDED_haxor_core_EngineState
#define INCLUDED_haxor_core_EngineState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,EngineState)
namespace haxor{
namespace core{


class EngineState_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef EngineState_obj OBJ_;

	public:
		EngineState_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.core.EngineState"); }
		::String __ToString() const { return HX_CSTRING("EngineState.") + tag; }

		static ::haxor::core::EngineState Editor;
		static inline ::haxor::core::EngineState Editor_dyn() { return Editor; }
		static ::haxor::core::EngineState Play;
		static inline ::haxor::core::EngineState Play_dyn() { return Play; }
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_EngineState */ 
