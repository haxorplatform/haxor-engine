#ifndef INCLUDED_haxor_core_Engine
#define INCLUDED_haxor_core_Engine

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,Engine)
HX_DECLARE_CLASS2(haxor,core,EngineState)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Engine_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Engine_obj OBJ_;
		Engine_obj();
		Void __construct(::haxor::core::BaseApplication p_application);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Engine_obj > __new(::haxor::core::BaseApplication p_application);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Engine_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Engine"); }

		::haxor::core::EngineState state;
		::haxor::core::BaseApplication m_application;
		virtual Void Collect( );
		Dynamic Collect_dyn();

		virtual Void Update( );
		Dynamic Update_dyn();

		virtual Void Render( );
		Dynamic Render_dyn();

		virtual Void Resize( );
		Dynamic Resize_dyn();

};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Engine */ 
