#ifndef INCLUDED_Main
#define INCLUDED_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Application.h>
#include <haxor/core/IRenderable.h>
#include <haxor/core/IUpdateable.h>
HX_DECLARE_CLASS0(Main)
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,Application)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IRenderable)
HX_DECLARE_CLASS2(haxor,core,IUpdateable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,platform,windows,WinApplication)


class HXCPP_CLASS_ATTRIBUTES  Main_obj : public ::haxor::core::Application_obj{
	public:
		typedef ::haxor::core::Application_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		inline operator ::haxor::core::IUpdateable_obj *()
			{ return new ::haxor::core::IUpdateable_delegate_< Main_obj >(this); }
		inline operator ::haxor::core::IRenderable_obj *()
			{ return new ::haxor::core::IRenderable_delegate_< Main_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Main"); }

		virtual bool Load( );

		virtual Void Initialize( );

		virtual Void OnUpdate( );
		Dynamic OnUpdate_dyn();

		virtual Void OnRender( );
		Dynamic OnRender_dyn();

		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_Main */ 