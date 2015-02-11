#ifndef INCLUDED_haxor_component_ParticleAttribute
#define INCLUDED_haxor_component_ParticleAttribute

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,ParticleAttribute)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  ParticleAttribute_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ParticleAttribute_obj OBJ_;
		ParticleAttribute_obj();
		Void __construct(Dynamic p_start,Dynamic p_end,hx::Null< Float >  __o_p_curve,hx::Null< bool >  __o_p_random);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ParticleAttribute_obj > __new(Dynamic p_start,Dynamic p_end,hx::Null< Float >  __o_p_curve,hx::Null< bool >  __o_p_random);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ParticleAttribute_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ParticleAttribute"); }

		Dynamic start;
		Dynamic end;
		Float curve;
		bool random;
};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_ParticleAttribute */ 
