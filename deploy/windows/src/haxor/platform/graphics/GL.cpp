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
#ifndef INCLUDED_haxor_platform_graphics_GL
#include <haxor/platform/graphics/GL.h>
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

Void GL_obj::__construct()
{
	return null();
}

//GL_obj::~GL_obj() { }

Dynamic GL_obj::__CreateEmpty() { return  new GL_obj; }
hx::ObjectPtr< GL_obj > GL_obj::__new()
{  hx::ObjectPtr< GL_obj > result = new GL_obj();
	result->__construct();
	return result;}

Dynamic GL_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GL_obj > result = new GL_obj();
	result->__construct();
	return result;}

int GL_obj::NULL_ID;

::haxor::platform::graphics::OpenGL GL_obj::m_gl;

Void GL_obj::Initialize( ::haxor::core::BaseApplication p_application){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Initialize",0xe247b265,"haxor.platform.graphics.GL.Initialize","haxor/platform/graphics/GL.hx",42,0x83cf3744)
		HX_STACK_ARG(p_application,"p_application")
		HX_STACK_LINE(43)
		::haxor::platform::graphics::OpenGL _g = ::haxor::platform::graphics::OpenGL_obj::__new(p_application);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(43)
		::haxor::platform::graphics::GL_obj::m_gl = _g;
		HX_STACK_LINE(44)
		::haxor::platform::graphics::GL_obj::m_gl->CheckExtensions();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,Initialize,(void))

Void GL_obj::Resize( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Resize",0xfd626c89,"haxor.platform.graphics.GL.Resize","haxor/platform/graphics/GL.hx",50,0x83cf3744)
		HX_STACK_LINE(50)
		::haxor::platform::graphics::GL_obj::m_gl->Resize();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,Resize,(void))

Void GL_obj::Clear( Float p_r,Float p_g,Float p_b,Float p_a,Float p_depth){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Clear",0x0ee88898,"haxor.platform.graphics.GL.Clear","haxor/platform/graphics/GL.hx",60,0x83cf3744)
		HX_STACK_ARG(p_r,"p_r")
		HX_STACK_ARG(p_g,"p_g")
		HX_STACK_ARG(p_b,"p_b")
		HX_STACK_ARG(p_a,"p_a")
		HX_STACK_ARG(p_depth,"p_depth")
		HX_STACK_LINE(60)
		::haxor::platform::graphics::GL_obj::m_gl->Clear(p_r,p_g,p_b,p_a,p_depth);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(GL_obj,Clear,(void))

int GL_obj::CreateBuffer( ){
	HX_STACK_FRAME("haxor.platform.graphics.GL","CreateBuffer",0xc568ad71,"haxor.platform.graphics.GL.CreateBuffer","haxor/platform/graphics/GL.hx",66,0x83cf3744)
	HX_STACK_LINE(66)
	return ::haxor::platform::graphics::GL_obj::m_gl->CreateBuffer();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,CreateBuffer,return )

Void GL_obj::DeleteBuffer( int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","DeleteBuffer",0x09ab93e0,"haxor.platform.graphics.GL.DeleteBuffer","haxor/platform/graphics/GL.hx",72,0x83cf3744)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(72)
		::haxor::platform::graphics::GL_obj::m_gl->DeleteBuffer(p_id);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,DeleteBuffer,(void))

Void GL_obj::Flush( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Flush",0xc92879cf,"haxor.platform.graphics.GL.Flush","haxor/platform/graphics/GL.hx",77,0x83cf3744)
		HX_STACK_LINE(77)
		::haxor::platform::graphics::GL_obj::m_gl->Flush();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,Flush,(void))

Void GL_obj::Focus( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Focus",0xcb1676e3,"haxor.platform.graphics.GL.Focus","haxor/platform/graphics/GL.hx",82,0x83cf3744)
		HX_STACK_LINE(82)
		::haxor::platform::graphics::GL_obj::m_gl->Focus();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,Focus,(void))


GL_obj::GL_obj()
{
}

Dynamic GL_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_gl") ) { return m_gl; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		if (HX_FIELD_EQ(inName,"Flush") ) { return Flush_dyn(); }
		if (HX_FIELD_EQ(inName,"Focus") ) { return Focus_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Resize") ) { return Resize_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"NULL_ID") ) { return NULL_ID; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"CreateBuffer") ) { return CreateBuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"DeleteBuffer") ) { return DeleteBuffer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GL_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_gl") ) { m_gl=inValue.Cast< ::haxor::platform::graphics::OpenGL >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"NULL_ID") ) { NULL_ID=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GL_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("NULL_ID"),
	HX_CSTRING("m_gl"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Resize"),
	HX_CSTRING("Clear"),
	HX_CSTRING("CreateBuffer"),
	HX_CSTRING("DeleteBuffer"),
	HX_CSTRING("Flush"),
	HX_CSTRING("Focus"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GL_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(GL_obj::NULL_ID,"NULL_ID");
	HX_MARK_MEMBER_NAME(GL_obj::m_gl,"m_gl");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GL_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(GL_obj::NULL_ID,"NULL_ID");
	HX_VISIT_MEMBER_NAME(GL_obj::m_gl,"m_gl");
};

#endif

Class GL_obj::__mClass;

void GL_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.graphics.GL"), hx::TCanCast< GL_obj> ,sStaticFields,sMemberFields,
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

void GL_obj::__boot()
{
	NULL_ID= (int)-1;
}

} // end namespace haxor
} // end namespace platform
} // end namespace graphics
