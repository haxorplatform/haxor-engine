#include <hxcpp.h>

#ifndef INCLUDED_haxor_platform_graphics_GraphicAPI
#include <haxor/platform/graphics/GraphicAPI.h>
#endif
namespace haxor{
namespace platform{
namespace graphics{

::haxor::platform::graphics::GraphicAPI GraphicAPI_obj::None;

::haxor::platform::graphics::GraphicAPI GraphicAPI_obj::OpenGL;

::haxor::platform::graphics::GraphicAPI GraphicAPI_obj::OpenGLES;

::haxor::platform::graphics::GraphicAPI GraphicAPI_obj::WebGL;

HX_DEFINE_CREATE_ENUM(GraphicAPI_obj)

int GraphicAPI_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("None")) return 0;
	if (inName==HX_CSTRING("OpenGL")) return 1;
	if (inName==HX_CSTRING("OpenGLES")) return 2;
	if (inName==HX_CSTRING("WebGL")) return 3;
	return super::__FindIndex(inName);
}

int GraphicAPI_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("None")) return 0;
	if (inName==HX_CSTRING("OpenGL")) return 0;
	if (inName==HX_CSTRING("OpenGLES")) return 0;
	if (inName==HX_CSTRING("WebGL")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic GraphicAPI_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("None")) return None;
	if (inName==HX_CSTRING("OpenGL")) return OpenGL;
	if (inName==HX_CSTRING("OpenGLES")) return OpenGLES;
	if (inName==HX_CSTRING("WebGL")) return WebGL;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("None"),
	HX_CSTRING("OpenGL"),
	HX_CSTRING("OpenGLES"),
	HX_CSTRING("WebGL"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GraphicAPI_obj::None,"None");
	HX_MARK_MEMBER_NAME(GraphicAPI_obj::OpenGL,"OpenGL");
	HX_MARK_MEMBER_NAME(GraphicAPI_obj::OpenGLES,"OpenGLES");
	HX_MARK_MEMBER_NAME(GraphicAPI_obj::WebGL,"WebGL");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GraphicAPI_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(GraphicAPI_obj::None,"None");
	HX_VISIT_MEMBER_NAME(GraphicAPI_obj::OpenGL,"OpenGL");
	HX_VISIT_MEMBER_NAME(GraphicAPI_obj::OpenGLES,"OpenGLES");
	HX_VISIT_MEMBER_NAME(GraphicAPI_obj::WebGL,"WebGL");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class GraphicAPI_obj::__mClass;

Dynamic __Create_GraphicAPI_obj() { return new GraphicAPI_obj; }

void GraphicAPI_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.graphics.GraphicAPI"), hx::TCanCast< GraphicAPI_obj >,sStaticFields,sMemberFields,
	&__Create_GraphicAPI_obj, &__Create,
	&super::__SGetClass(), &CreateGraphicAPI_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void GraphicAPI_obj::__boot()
{
hx::Static(None) = hx::CreateEnum< GraphicAPI_obj >(HX_CSTRING("None"),0);
hx::Static(OpenGL) = hx::CreateEnum< GraphicAPI_obj >(HX_CSTRING("OpenGL"),1);
hx::Static(OpenGLES) = hx::CreateEnum< GraphicAPI_obj >(HX_CSTRING("OpenGLES"),2);
hx::Static(WebGL) = hx::CreateEnum< GraphicAPI_obj >(HX_CSTRING("WebGL"),3);
}


} // end namespace haxor
} // end namespace platform
} // end namespace graphics
