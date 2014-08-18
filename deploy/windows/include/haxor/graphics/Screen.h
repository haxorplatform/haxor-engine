#ifndef INCLUDED_haxor_graphics_Screen
#define INCLUDED_haxor_graphics_Screen

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,graphics,CursorMode)
HX_DECLARE_CLASS2(haxor,graphics,Screen)
namespace haxor{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  Screen_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Screen_obj OBJ_;
		Screen_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Screen_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Screen_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Screen"); }

		static Float width;
		static Float get_width( );
		static Dynamic get_width_dyn();

		static Float m_width;
		static Float height;
		static Float get_height( );
		static Dynamic get_height_dyn();

		static Float m_height;
		static bool get_fullscreen( );
		static Dynamic get_fullscreen_dyn();

		static bool set_fullscreen( bool v);
		static Dynamic set_fullscreen_dyn();

		static bool m_fullscreen;
		static ::haxor::graphics::CursorMode get_cursor( );
		static Dynamic get_cursor_dyn();

		static ::haxor::graphics::CursorMode set_cursor( ::haxor::graphics::CursorMode v);
		static Dynamic set_cursor_dyn();

		static ::haxor::graphics::CursorMode m_cursor;
		static ::haxor::core::BaseApplication m_application;
		static Void Initialize( ::haxor::core::BaseApplication p_application);
		static Dynamic Initialize_dyn();

};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_Screen */ 
