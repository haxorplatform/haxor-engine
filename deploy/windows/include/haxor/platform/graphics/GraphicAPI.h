#ifndef INCLUDED_haxor_platform_graphics_GraphicAPI
#define INCLUDED_haxor_platform_graphics_GraphicAPI

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(haxor,platform,graphics,GraphicAPI)
namespace haxor{
namespace platform{
namespace graphics{


class GraphicAPI_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef GraphicAPI_obj OBJ_;

	public:
		GraphicAPI_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxor.platform.graphics.GraphicAPI"); }
		::String __ToString() const { return HX_CSTRING("GraphicAPI.") + tag; }

		static ::haxor::platform::graphics::GraphicAPI None;
		static inline ::haxor::platform::graphics::GraphicAPI None_dyn() { return None; }
		static ::haxor::platform::graphics::GraphicAPI OpenGL;
		static inline ::haxor::platform::graphics::GraphicAPI OpenGL_dyn() { return OpenGL; }
		static ::haxor::platform::graphics::GraphicAPI OpenGLES;
		static inline ::haxor::platform::graphics::GraphicAPI OpenGLES_dyn() { return OpenGLES; }
		static ::haxor::platform::graphics::GraphicAPI WebGL;
		static inline ::haxor::platform::graphics::GraphicAPI WebGL_dyn() { return WebGL; }
};

} // end namespace haxor
} // end namespace platform
} // end namespace graphics

#endif /* INCLUDED_haxor_platform_graphics_GraphicAPI */ 
