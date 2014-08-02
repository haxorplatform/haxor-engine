#ifndef INCLUDED_haxor_platform_graphics_Graphics
#define INCLUDED_haxor_platform_graphics_Graphics

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/platform/graphics/OpenGL.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,platform,graphics,GraphicContext)
HX_DECLARE_CLASS3(haxor,platform,graphics,Graphics)
HX_DECLARE_CLASS3(haxor,platform,graphics,OpenGL)
HX_DECLARE_CLASS3(haxor,platform,graphics,WinGL)
namespace haxor{
namespace platform{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  Graphics_obj : public ::haxor::platform::graphics::OpenGL_obj{
	public:
		typedef ::haxor::platform::graphics::OpenGL_obj super;
		typedef Graphics_obj OBJ_;
		Graphics_obj();
		Void __construct(::haxor::core::BaseApplication p_application);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Graphics_obj > __new(::haxor::core::BaseApplication p_application);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Graphics_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Graphics"); }

};

} // end namespace haxor
} // end namespace platform
} // end namespace graphics

#endif /* INCLUDED_haxor_platform_graphics_Graphics */ 
