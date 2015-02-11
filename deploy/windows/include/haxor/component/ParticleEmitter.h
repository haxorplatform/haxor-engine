#ifndef INCLUDED_haxor_component_ParticleEmitter
#define INCLUDED_haxor_component_ParticleEmitter

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,ParticleEmitter)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  ParticleEmitter_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ParticleEmitter_obj OBJ_;
		ParticleEmitter_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ParticleEmitter_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ParticleEmitter_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ParticleEmitter"); }

		virtual bool get_surface( );
		Dynamic get_surface_dyn();

		virtual bool set_surface( bool v);
		Dynamic set_surface_dyn();

		virtual bool get_random( );
		Dynamic get_random_dyn();

		virtual bool set_random( bool v);
		Dynamic set_random_dyn();

		Array< Float > ranges;
		Array< Float > m_data;
};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_ParticleEmitter */ 
