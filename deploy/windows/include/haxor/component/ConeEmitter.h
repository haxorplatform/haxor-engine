#ifndef INCLUDED_haxor_component_ConeEmitter
#define INCLUDED_haxor_component_ConeEmitter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/ParticleEmitter.h>
HX_DECLARE_CLASS2(haxor,component,ConeEmitter)
HX_DECLARE_CLASS2(haxor,component,ParticleEmitter)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  ConeEmitter_obj : public ::haxor::component::ParticleEmitter_obj{
	public:
		typedef ::haxor::component::ParticleEmitter_obj super;
		typedef ConeEmitter_obj OBJ_;
		ConeEmitter_obj();
		Void __construct(hx::Null< Float >  __o_p_angle,hx::Null< Float >  __o_p_height);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ConeEmitter_obj > __new(hx::Null< Float >  __o_p_angle,hx::Null< Float >  __o_p_height);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ConeEmitter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("ConeEmitter"); }

		virtual Float get_angle( );
		Dynamic get_angle_dyn();

		virtual Float set_angle( Float v);
		Dynamic set_angle_dyn();

		virtual Float get_height( );
		Dynamic get_height_dyn();

		virtual Float set_height( Float v);
		Dynamic set_height_dyn();

};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_ConeEmitter */ 
