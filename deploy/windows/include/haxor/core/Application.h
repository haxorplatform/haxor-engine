#ifndef INCLUDED_haxor_core_Application
#define INCLUDED_haxor_core_Application

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/platform/windows/WinApplication.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,Application)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,platform,windows,WinApplication)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Application_obj : public ::haxor::platform::windows::WinApplication_obj{
	public:
		typedef ::haxor::platform::windows::WinApplication_obj super;
		typedef Application_obj OBJ_;
		Application_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Application_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Application_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Application"); }

};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Application */ 
