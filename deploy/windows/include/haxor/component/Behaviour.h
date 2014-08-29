#ifndef INCLUDED_haxor_component_Behaviour
#define INCLUDED_haxor_component_Behaviour

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/Component.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  Behaviour_obj : public ::haxor::component::Component_obj{
	public:
		typedef ::haxor::component::Component_obj super;
		typedef Behaviour_obj OBJ_;
		Behaviour_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Behaviour_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Behaviour_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Behaviour"); }

		virtual bool get_enabled( );
		Dynamic get_enabled_dyn();

		virtual bool set_enabled( bool v);
		Dynamic set_enabled_dyn();

		bool m_enabled;
		bool m_is_awake;
		bool m_is_start;
		virtual Void OnBuild( );

		virtual Void OnAwake( );
		Dynamic OnAwake_dyn();

		virtual Void OnStart( );
		Dynamic OnStart_dyn();

};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_Behaviour */ 
