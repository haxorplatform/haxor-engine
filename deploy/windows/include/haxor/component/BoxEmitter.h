#ifndef INCLUDED_haxor_component_BoxEmitter
#define INCLUDED_haxor_component_BoxEmitter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/ParticleEmitter.h>
HX_DECLARE_CLASS2(haxor,component,BoxEmitter)
HX_DECLARE_CLASS2(haxor,component,ParticleEmitter)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  BoxEmitter_obj : public ::haxor::component::ParticleEmitter_obj{
	public:
		typedef ::haxor::component::ParticleEmitter_obj super;
		typedef BoxEmitter_obj OBJ_;
		BoxEmitter_obj();
		Void __construct(hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height,hx::Null< Float >  __o_p_depth);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BoxEmitter_obj > __new(hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height,hx::Null< Float >  __o_p_depth);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BoxEmitter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("BoxEmitter"); }

		virtual Float get_width( );
		Dynamic get_width_dyn();

		virtual Float set_width( Float v);
		Dynamic set_width_dyn();

		virtual Float get_height( );
		Dynamic get_height_dyn();

		virtual Float set_height( Float v);
		Dynamic set_height_dyn();

		virtual Float get_depth( );
		Dynamic get_depth_dyn();

		virtual Float set_depth( Float v);
		Dynamic set_depth_dyn();

};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_BoxEmitter */ 
