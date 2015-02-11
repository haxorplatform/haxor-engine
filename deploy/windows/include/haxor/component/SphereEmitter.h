#ifndef INCLUDED_haxor_component_SphereEmitter
#define INCLUDED_haxor_component_SphereEmitter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/ParticleEmitter.h>
HX_DECLARE_CLASS2(haxor,component,ParticleEmitter)
HX_DECLARE_CLASS2(haxor,component,SphereEmitter)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  SphereEmitter_obj : public ::haxor::component::ParticleEmitter_obj{
	public:
		typedef ::haxor::component::ParticleEmitter_obj super;
		typedef SphereEmitter_obj OBJ_;
		SphereEmitter_obj();
		Void __construct(hx::Null< Float >  __o_p_radius);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SphereEmitter_obj > __new(hx::Null< Float >  __o_p_radius);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SphereEmitter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("SphereEmitter"); }

		virtual Float get_radius( );
		Dynamic get_radius_dyn();

		virtual Float set_radius( Float v);
		Dynamic set_radius_dyn();

};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_SphereEmitter */ 
