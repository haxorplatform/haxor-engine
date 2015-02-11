#ifndef INCLUDED_MainNative
#define INCLUDED_MainNative

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Application.h>
HX_DECLARE_CLASS0(MainNative)
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,Application)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,platform,windows,WinApplication)


class HXCPP_CLASS_ATTRIBUTES  MainNative_obj : public ::haxor::core::Application_obj{
	public:
		typedef ::haxor::core::Application_obj super;
		typedef MainNative_obj OBJ_;
		MainNative_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MainNative_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MainNative_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("MainNative"); }

		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_MainNative */ 
