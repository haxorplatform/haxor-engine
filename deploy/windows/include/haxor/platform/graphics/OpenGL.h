#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#define INCLUDED_haxor_platform_graphics_OpenGL

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/platform/graphics/WinGL.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,platform,graphics,GraphicContext)
HX_DECLARE_CLASS3(haxor,platform,graphics,OpenGL)
HX_DECLARE_CLASS3(haxor,platform,graphics,WinGL)
namespace haxor{
namespace platform{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  OpenGL_obj : public ::haxor::platform::graphics::WinGL_obj{
	public:
		typedef ::haxor::platform::graphics::WinGL_obj super;
		typedef OpenGL_obj OBJ_;
		OpenGL_obj();
		Void __construct(::haxor::core::BaseApplication p_application);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< OpenGL_obj > __new(::haxor::core::BaseApplication p_application);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~OpenGL_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("OpenGL"); }

		virtual Void Clear( Float p_r,Float p_g,Float p_b,hx::Null< Float >  p_a,hx::Null< Float >  p_depth);

};

} // end namespace haxor
} // end namespace platform
} // end namespace graphics

#endif /* INCLUDED_haxor_platform_graphics_OpenGL */ 
