#ifndef INCLUDED_haxor_component_ParticleSheet
#define INCLUDED_haxor_component_ParticleSheet

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,ParticleAttribute)
HX_DECLARE_CLASS2(haxor,component,ParticleSheet)
HX_DECLARE_CLASS2(haxor,core,AnimationWrap)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  ParticleSheet_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ParticleSheet_obj OBJ_;
		ParticleSheet_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ParticleSheet_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ParticleSheet_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ParticleSheet"); }

		Float width;
		Float height;
		int length;
		Float fps;
		::haxor::component::ParticleAttribute frame;
		::haxor::core::AnimationWrap wrap;
		bool reverse;
};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_ParticleSheet */ 
