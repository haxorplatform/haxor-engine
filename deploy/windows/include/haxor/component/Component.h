#ifndef INCLUDED_haxor_component_Component
#define INCLUDED_haxor_component_Component

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Resource.h>
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,Entity)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  Component_obj : public ::haxor::core::Resource_obj{
	public:
		typedef ::haxor::core::Resource_obj super;
		typedef Component_obj OBJ_;
		Component_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Component_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Component_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Component"); }

		virtual ::String get_name( );

		virtual ::String set_name( ::String v);

		::haxor::core::Entity entity;
		virtual ::haxor::core::Entity get_entity( );
		Dynamic get_entity_dyn();

		::haxor::core::Entity m_entity;
		virtual Void OnBuild( );
		Dynamic OnBuild_dyn();

};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_Component */ 
