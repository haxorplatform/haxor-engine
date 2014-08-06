#ifndef INCLUDED_haxor_platform_graphics_WinGL
#define INCLUDED_haxor_platform_graphics_WinGL

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/platform/graphics/GraphicContext.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,platform,OSWindow)
HX_DECLARE_CLASS3(haxor,platform,graphics,GraphicContext)
HX_DECLARE_CLASS3(haxor,platform,graphics,WinGL)
HX_DECLARE_CLASS3(haxor,platform,windows,Window)

#include <windows.h>
#include "gl/glew.h"                              // Header File For The GLEW Library



namespace haxor{
namespace platform{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  WinGL_obj : public ::haxor::platform::graphics::GraphicContext_obj{
	public:
		typedef ::haxor::platform::graphics::GraphicContext_obj super;
		typedef WinGL_obj OBJ_;
		WinGL_obj();
		Void __construct(::haxor::core::BaseApplication p_application);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< WinGL_obj > __new(::haxor::core::BaseApplication p_application);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~WinGL_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("WinGL"); }

		::haxor::platform::windows::Window window;
		virtual ::haxor::platform::windows::Window get_window( );
		Dynamic get_window_dyn();

		::haxor::platform::OSWindow m_window;
		virtual bool Initialize( ::haxor::platform::windows::Window p_window);
		Dynamic Initialize_dyn();

		virtual Void CheckExtensions( );

		virtual Void Focus( );

		virtual Void Flush( );


#undef RegisterClass





};

} // end namespace haxor
} // end namespace platform
} // end namespace graphics

#endif /* INCLUDED_haxor_platform_graphics_WinGL */ 
