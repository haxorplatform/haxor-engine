#ifndef INCLUDED_haxor_component_CylinderEmitter
#define INCLUDED_haxor_component_CylinderEmitter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/ParticleEmitter.h>
HX_DECLARE_CLASS2(haxor,component,CylinderEmitter)
HX_DECLARE_CLASS2(haxor,component,ParticleEmitter)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  CylinderEmitter_obj : public ::haxor::component::ParticleEmitter_obj{
	public:
		typedef ::haxor::component::ParticleEmitter_obj super;
		typedef CylinderEmitter_obj OBJ_;
		CylinderEmitter_obj();
		Void __construct(hx::Null< Float >  __o_p_radius,hx::Null< Float >  __o_p_height);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< CylinderEmitter_obj > __new(hx::Null< Float >  __o_p_radius,hx::Null< Float >  __o_p_height);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~CylinderEmitter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("CylinderEmitter"); }

		virtual Float get_radius( );
		Dynamic get_radius_dyn();

		virtual Float set_radius( Float v);
		Dynamic set_radius_dyn();

		virtual Float get_height( );
		Dynamic get_height_dyn();

		virtual Float set_height( Float v);
		Dynamic set_height_dyn();

};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_CylinderEmitter */ 
