#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_core_BaseApplication
#include <haxor/core/BaseApplication.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GraphicAPI
#include <haxor/platform/graphics/GraphicAPI.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GraphicContext
#include <haxor/platform/graphics/GraphicContext.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_WinGL
#include <haxor/platform/graphics/WinGL.h>
#endif
namespace haxor{
namespace platform{
namespace graphics{

Void OpenGL_obj::__construct(::haxor::core::BaseApplication p_application)
{
HX_STACK_FRAME("haxor.platform.graphics.OpenGL","new",0xa0d46c35,"haxor.platform.graphics.OpenGL.new","haxor/platform/graphics/OpenGL.hx",27,0x3c17389a)
HX_STACK_THIS(this)
HX_STACK_ARG(p_application,"p_application")
{
	HX_STACK_LINE(28)
	super::__construct(p_application);
	HX_STACK_LINE(29)
	this->api = ::haxor::platform::graphics::GraphicAPI_obj::OpenGL;
}
;
	return null();
}

//OpenGL_obj::~OpenGL_obj() { }

Dynamic OpenGL_obj::__CreateEmpty() { return  new OpenGL_obj; }
hx::ObjectPtr< OpenGL_obj > OpenGL_obj::__new(::haxor::core::BaseApplication p_application)
{  hx::ObjectPtr< OpenGL_obj > result = new OpenGL_obj();
	result->__construct(p_application);
	return result;}

Dynamic OpenGL_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< OpenGL_obj > result = new OpenGL_obj();
	result->__construct(inArgs[0]);
	return result;}

Void OpenGL_obj::Clear( Float p_r,Float p_g,Float p_b,hx::Null< Float >  __o_p_a,hx::Null< Float >  __o_p_depth){
Float p_a = __o_p_a.Default(1.0);
Float p_depth = __o_p_depth.Default(1.0);
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Clear",0x1247dc82,"haxor.platform.graphics.OpenGL.Clear","haxor/platform/graphics/OpenGL.hx",42,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_r,"p_r")
	HX_STACK_ARG(p_g,"p_g")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_depth,"p_depth")
{
		HX_STACK_LINE(42)
		
		glClearDepth(p_depth); 
		glClearColor(p_r, p_g, p_b, p_a); 						
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		;
	}
return null();
}



OpenGL_obj::OpenGL_obj()
{
}

Dynamic OpenGL_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic OpenGL_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void OpenGL_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("Clear"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(OpenGL_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(OpenGL_obj::__mClass,"__mClass");
};

#endif

Class OpenGL_obj::__mClass;

void OpenGL_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.graphics.OpenGL"), hx::TCanCast< OpenGL_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void OpenGL_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace graphics