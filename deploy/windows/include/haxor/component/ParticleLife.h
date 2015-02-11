#ifndef INCLUDED_haxor_component_ParticleLife
#define INCLUDED_haxor_component_ParticleLife

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,ParticleAttribute)
HX_DECLARE_CLASS2(haxor,component,ParticleLife)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  ParticleLife_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ParticleLife_obj OBJ_;
		ParticleLife_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ParticleLife_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ParticleLife_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ParticleLife"); }

		::haxor::component::ParticleAttribute speed;
		::haxor::component::ParticleAttribute motion;
		::haxor::component::ParticleAttribute size;
		::haxor::component::ParticleAttribute rotation;
		::haxor::graphics::texture::Texture color;
};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_ParticleLife */ 
