#ifndef INCLUDED_haxor_component_ParticleStart
#define INCLUDED_haxor_component_ParticleStart

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,ParticleAttribute)
HX_DECLARE_CLASS2(haxor,component,ParticleStart)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  ParticleStart_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ParticleStart_obj OBJ_;
		ParticleStart_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ParticleStart_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ParticleStart_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ParticleStart"); }

		::haxor::component::ParticleAttribute life;
		::haxor::component::ParticleAttribute speed;
		::haxor::component::ParticleAttribute size;
		::haxor::component::ParticleAttribute rotation;
		::haxor::graphics::texture::Texture color;
};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_ParticleStart */ 
