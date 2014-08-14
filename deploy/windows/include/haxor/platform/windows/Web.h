#ifndef INCLUDED_haxor_platform_windows_Web
#define INCLUDED_haxor_platform_windows_Web

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(haxor,platform,windows,LoadTask)
HX_DECLARE_CLASS3(haxor,platform,windows,Web)
namespace haxor{
namespace platform{
namespace windows{


class HXCPP_CLASS_ATTRIBUTES  Web_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Web_obj OBJ_;
		Web_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Web_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Web_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Web"); }

		static ::String root;
		static bool m_running;
		static Array< ::Dynamic > q;
		static Void Load( ::String p_url,Dynamic p_callback);
		static Dynamic Load_dyn();

		static Void QueueUpdate( );
		static Dynamic QueueUpdate_dyn();

};

} // end namespace haxor
} // end namespace platform
} // end namespace windows

#endif /* INCLUDED_haxor_platform_windows_Web */ 
