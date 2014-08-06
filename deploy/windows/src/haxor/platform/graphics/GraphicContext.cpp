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
#ifndef INCLUDED_haxor_platform_graphics_GraphicAPI
#include <haxor/platform/graphics/GraphicAPI.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GraphicContext
#include <haxor/platform/graphics/GraphicContext.h>
#endif
namespace haxor{
namespace platform{
namespace graphics{

Void GraphicContext_obj::__construct(::haxor::core::BaseApplication p_application)
{
HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","new",0xdecf5bed,"haxor.platform.graphics.GraphicContext.new","haxor/platform/graphics/GraphicContext.hx",41,0x2319fee2)
HX_STACK_THIS(this)
HX_STACK_ARG(p_application,"p_application")
{
	HX_STACK_LINE(42)
	this->m_api = ::haxor::platform::graphics::GraphicAPI_obj::None;
	HX_STACK_LINE(43)
	this->m_application = p_application;
}
;
	return null();
}

//GraphicContext_obj::~GraphicContext_obj() { }

Dynamic GraphicContext_obj::__CreateEmpty() { return  new GraphicContext_obj; }
hx::ObjectPtr< GraphicContext_obj > GraphicContext_obj::__new(::haxor::core::BaseApplication p_application)
{  hx::ObjectPtr< GraphicContext_obj > result = new GraphicContext_obj();
	result->__construct(p_application);
	return result;}

Dynamic GraphicContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GraphicContext_obj > result = new GraphicContext_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::platform::graphics::GraphicAPI GraphicContext_obj::get_api( ){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","get_api",0x40db9b3e,"haxor.platform.graphics.GraphicContext.get_api","haxor/platform/graphics/GraphicContext.hx",29,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(29)
	return this->m_api;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,get_api,return )

Void GraphicContext_obj::CheckExtensions( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","CheckExtensions",0x7d7b15e9,"haxor.platform.graphics.GraphicContext.CheckExtensions","haxor/platform/graphics/GraphicContext.hx",49,0x2319fee2)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,CheckExtensions,(void))

Void GraphicContext_obj::Focus( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","Focus",0xb4d61885,"haxor.platform.graphics.GraphicContext.Focus","haxor/platform/graphics/GraphicContext.hx",54,0x2319fee2)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,Focus,(void))

Void GraphicContext_obj::Flush( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","Flush",0xb2e81b71,"haxor.platform.graphics.GraphicContext.Flush","haxor/platform/graphics/GraphicContext.hx",59,0x2319fee2)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,Flush,(void))

int GraphicContext_obj::CreateBuffer( ){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","CreateBuffer",0x0d3b640f,"haxor.platform.graphics.GraphicContext.CreateBuffer","haxor/platform/graphics/GraphicContext.hx",65,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(65)
	return ::haxor::platform::graphics::GL_obj::NULL_ID;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,CreateBuffer,return )

Void GraphicContext_obj::DeleteBuffer( int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","DeleteBuffer",0x517e4a7e,"haxor.platform.graphics.GraphicContext.DeleteBuffer","haxor/platform/graphics/GraphicContext.hx",71,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,DeleteBuffer,(void))

Void GraphicContext_obj::Destroy( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","Destroy",0x0bf42ae7,"haxor.platform.graphics.GraphicContext.Destroy","haxor/platform/graphics/GraphicContext.hx",76,0x2319fee2)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,Destroy,(void))

Void GraphicContext_obj::Resize( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","Resize",0x9b5038a7,"haxor.platform.graphics.GraphicContext.Resize","haxor/platform/graphics/GraphicContext.hx",82,0x2319fee2)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,Resize,(void))

Void GraphicContext_obj::Clear( Float p_r,Float p_g,Float p_b,Float p_a,Float p_depth){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","Clear",0xf8a82a3a,"haxor.platform.graphics.GraphicContext.Clear","haxor/platform/graphics/GraphicContext.hx",91,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_r,"p_r")
		HX_STACK_ARG(p_g,"p_g")
		HX_STACK_ARG(p_b,"p_b")
		HX_STACK_ARG(p_a,"p_a")
		HX_STACK_ARG(p_depth,"p_depth")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(GraphicContext_obj,Clear,(void))


GraphicContext_obj::GraphicContext_obj()
{
}

void GraphicContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GraphicContext);
	HX_MARK_MEMBER_NAME(api,"api");
	HX_MARK_MEMBER_NAME(m_api,"m_api");
	HX_MARK_MEMBER_NAME(m_application,"m_application");
	HX_MARK_END_CLASS();
}

void GraphicContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(api,"api");
	HX_VISIT_MEMBER_NAME(m_api,"m_api");
	HX_VISIT_MEMBER_NAME(m_application,"m_application");
}

Dynamic GraphicContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"api") ) { return api; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_api") ) { return m_api; }
		if (HX_FIELD_EQ(inName,"Focus") ) { return Focus_dyn(); }
		if (HX_FIELD_EQ(inName,"Flush") ) { return Flush_dyn(); }
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Resize") ) { return Resize_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_api") ) { return get_api_dyn(); }
		if (HX_FIELD_EQ(inName,"Destroy") ) { return Destroy_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"CreateBuffer") ) { return CreateBuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"DeleteBuffer") ) { return DeleteBuffer_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_application") ) { return m_application; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"CheckExtensions") ) { return CheckExtensions_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GraphicContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"api") ) { api=inValue.Cast< ::haxor::platform::graphics::GraphicAPI >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_api") ) { m_api=inValue.Cast< ::haxor::platform::graphics::GraphicAPI >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_application") ) { m_application=inValue.Cast< ::haxor::core::BaseApplication >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GraphicContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("api"));
	outFields->push(HX_CSTRING("m_api"));
	outFields->push(HX_CSTRING("m_application"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::platform::graphics::GraphicAPI*/ ,(int)offsetof(GraphicContext_obj,api),HX_CSTRING("api")},
	{hx::fsObject /*::haxor::platform::graphics::GraphicAPI*/ ,(int)offsetof(GraphicContext_obj,m_api),HX_CSTRING("m_api")},
	{hx::fsObject /*::haxor::core::BaseApplication*/ ,(int)offsetof(GraphicContext_obj,m_application),HX_CSTRING("m_application")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("api"),
	HX_CSTRING("get_api"),
	HX_CSTRING("m_api"),
	HX_CSTRING("m_application"),
	HX_CSTRING("CheckExtensions"),
	HX_CSTRING("Focus"),
	HX_CSTRING("Flush"),
	HX_CSTRING("CreateBuffer"),
	HX_CSTRING("DeleteBuffer"),
	HX_CSTRING("Destroy"),
	HX_CSTRING("Resize"),
	HX_CSTRING("Clear"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GraphicContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GraphicContext_obj::__mClass,"__mClass");
};

#endif

Class GraphicContext_obj::__mClass;

void GraphicContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.graphics.GraphicContext"), hx::TCanCast< GraphicContext_obj> ,sStaticFields,sMemberFields,
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

void GraphicContext_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace graphics
