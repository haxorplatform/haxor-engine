#ifndef INCLUDED_haxor_core_Entity
#define INCLUDED_haxor_core_Entity

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Resource.h>
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,Entity)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Entity_obj : public ::haxor::core::Resource_obj{
	public:
		typedef ::haxor::core::Resource_obj super;
		typedef Entity_obj OBJ_;
		Entity_obj();
		Void __construct(::String p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Entity_obj > __new(::String p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Entity_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Entity"); }

		virtual bool get_enabled( );
		Dynamic get_enabled_dyn();

		virtual bool set_enabled( bool v);
		Dynamic set_enabled_dyn();

		bool m_enabled;
		Array< ::Dynamic > m_components;
		virtual Dynamic AddComponent( ::Class p_type);
		Dynamic AddComponent_dyn();

		virtual Void OnDestroy( );

};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Entity */ 
