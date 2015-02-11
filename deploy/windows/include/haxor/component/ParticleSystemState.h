#ifndef INCLUDED_haxor_component_ParticleSystemState
#define INCLUDED_haxor_component_ParticleSystemState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,ParticleSystemState)
namespace haxor{
namespace component{


class ParticleSystemState_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef ParticleSystemState_obj OBJ_;

	public:
		ParticleSystemState_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.component.ParticleSystemState"); }
		::String __ToString() const { return HX_CSTRING("ParticleSystemState.") + tag; }

		static ::haxor::component::ParticleSystemState None;
		static inline ::haxor::component::ParticleSystemState None_dyn() { return None; }
		static ::haxor::component::ParticleSystemState Reset;
		static inline ::haxor::component::ParticleSystemState Reset_dyn() { return Reset; }
		static ::haxor::component::ParticleSystemState Update;
		static inline ::haxor::component::ParticleSystemState Update_dyn() { return Update; }
};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_ParticleSystemState */ 
