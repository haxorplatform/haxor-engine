#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Camera
#include <haxor/component/Camera.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_Renderer
#include <haxor/component/Renderer.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_context_BaseProcess
#include <haxor/context/BaseProcess.h>
#endif
#ifndef INCLUDED_haxor_context_CameraContext
#include <haxor/context/CameraContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_GizmoContext
#include <haxor/context/GizmoContext.h>
#endif
#ifndef INCLUDED_haxor_context_Process
#include <haxor/context/Process.h>
#endif
#ifndef INCLUDED_haxor_context_RendererContext
#include <haxor/context/RendererContext.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_RenderEngine
#include <haxor/core/RenderEngine.h>
#endif
#ifndef INCLUDED_haxor_core_RenderStats
#include <haxor/core/RenderStats.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
namespace haxor{
namespace core{

Void RenderEngine_obj::__construct()
{
	return null();
}

//RenderEngine_obj::~RenderEngine_obj() { }

Dynamic RenderEngine_obj::__CreateEmpty() { return  new RenderEngine_obj; }
hx::ObjectPtr< RenderEngine_obj > RenderEngine_obj::__new()
{  hx::ObjectPtr< RenderEngine_obj > result = new RenderEngine_obj();
	result->__construct();
	return result;}

Dynamic RenderEngine_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RenderEngine_obj > result = new RenderEngine_obj();
	result->__construct();
	return result;}

Void RenderEngine_obj::Render( ){
{
		HX_STACK_FRAME("haxor.core.RenderEngine","Render",0xee5e4c69,"haxor.core.RenderEngine.Render","haxor/core/RenderEngine.hx",18,0xca802223)
		HX_STACK_LINE(20)
		::haxor::core::RenderStats_obj::BeginRender();
		HX_STACK_LINE(23)
		::haxor::core::RenderEngine_obj::RenderCameras();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(RenderEngine_obj,Render,(void))

Void RenderEngine_obj::RenderCameras( ){
{
		HX_STACK_FRAME("haxor.core.RenderEngine","RenderCameras",0xd976b4c5,"haxor.core.RenderEngine.RenderCameras","haxor/core/RenderEngine.hx",32,0xca802223)
		HX_STACK_LINE(33)
		Array< ::Dynamic > cl = ::haxor::context::EngineContext_obj::camera->list;		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(34)
		{
			HX_STACK_LINE(34)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(34)
			int _g = cl->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(34)
			while((true)){
				HX_STACK_LINE(34)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(34)
					break;
				}
				HX_STACK_LINE(34)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(36)
				::haxor::component::Camera c = ::haxor::component::Camera_obj::m_current = cl->__get(i).StaticCast< ::haxor::component::Camera >();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(37)
				::haxor::core::RenderEngine_obj::RenderCamera(c);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(RenderEngine_obj,RenderCameras,(void))

Void RenderEngine_obj::RenderCamera( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.core.RenderEngine","RenderCamera",0x628dbbee,"haxor.core.RenderEngine.RenderCamera","haxor/core/RenderEngine.hx",46,0xca802223)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(47)
		if ((!(c->get_enabled()))){
			HX_STACK_LINE(47)
			return null();
		}
		HX_STACK_LINE(48)
		::haxor::context::EngineContext_obj::camera->Bind(c);
		HX_STACK_LINE(49)
		Array< int > layers = c->m_layers;		HX_STACK_VAR(layers,"layers");
		HX_STACK_LINE(50)
		{
			HX_STACK_LINE(50)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(50)
			int _g = layers->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(50)
			while((true)){
				HX_STACK_LINE(50)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(50)
					break;
				}
				HX_STACK_LINE(50)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(52)
				int l = layers->__get(i);		HX_STACK_VAR(l,"l");
				HX_STACK_LINE(53)
				::haxor::core::RenderEngine_obj::RenderCameraLayer(l,c);
			}
		}
		HX_STACK_LINE(58)
		if (((c == ::haxor::component::Camera_obj::m_main))){
			HX_STACK_LINE(60)
			::haxor::context::EngineContext_obj::gizmo->Render();
		}
		HX_STACK_LINE(63)
		::haxor::context::EngineContext_obj::camera->Unbind(c);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(RenderEngine_obj,RenderCamera,(void))

Void RenderEngine_obj::RenderCameraLayer( int l,::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.core.RenderEngine","RenderCameraLayer",0x26aa3703,"haxor.core.RenderEngine.RenderCameraLayer","haxor/core/RenderEngine.hx",74,0xca802223)
		HX_STACK_ARG(l,"l")
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(76)
		::haxor::component::Transform lt = null();		HX_STACK_VAR(lt,"lt");
		HX_STACK_LINE(77)
		::haxor::context::Process renderers = ::haxor::context::EngineContext_obj::renderer->display->__get(l).StaticCast< ::haxor::context::Process >();		HX_STACK_VAR(renderers,"renderers");
		HX_STACK_LINE(78)
		{
			HX_STACK_LINE(78)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(78)
			int _g = renderers->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(78)
			while((true)){
				HX_STACK_LINE(78)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(78)
					break;
				}
				HX_STACK_LINE(78)
				int j = (_g1)++;		HX_STACK_VAR(j,"j");
				HX_STACK_LINE(80)
				::haxor::component::Renderer r = renderers->list->__GetItem(j);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(82)
				if ((::haxor::context::EngineContext_obj::renderer->IsSAPCulled(r,c))){
					HX_STACK_LINE(82)
					continue;
				}
				HX_STACK_LINE(85)
				::haxor::core::RenderEngine_obj::RenderRenderer(r);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(RenderEngine_obj,RenderCameraLayer,(void))

Void RenderEngine_obj::RenderRenderer( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.core.RenderEngine","RenderRenderer",0x391bdecc,"haxor.core.RenderEngine.RenderRenderer","haxor/core/RenderEngine.hx",94,0xca802223)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(96)
		r->UpdateCulling();
		HX_STACK_LINE(98)
		if ((!(((bool(r->m_visible) && bool(!(r->m_culled))))))){
			HX_STACK_LINE(101)
			(::haxor::core::RenderStats_obj::culled)++;
			HX_STACK_LINE(103)
			return null();
		}
		HX_STACK_LINE(107)
		(::haxor::core::RenderStats_obj::visible)++;
		HX_STACK_LINE(112)
		r->OnRender();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(RenderEngine_obj,RenderRenderer,(void))

Void RenderEngine_obj::RenderFinish( ){
{
		HX_STACK_FRAME("haxor.core.RenderEngine","RenderFinish",0x3180b59c,"haxor.core.RenderEngine.RenderFinish","haxor/core/RenderEngine.hx",121,0xca802223)
		HX_STACK_LINE(122)
		Array< ::Dynamic > cl = ::haxor::context::EngineContext_obj::camera->list;		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(123)
		{
			HX_STACK_LINE(123)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(123)
			int _g = cl->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(123)
			while((true)){
				HX_STACK_LINE(123)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(123)
					break;
				}
				HX_STACK_LINE(123)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(125)
				cl->__get(i).StaticCast< ::haxor::component::Camera >()->m_view_uniform_dirty = false;
				HX_STACK_LINE(126)
				cl->__get(i).StaticCast< ::haxor::component::Camera >()->m_proj_uniform_dirty = false;
			}
		}
		HX_STACK_LINE(129)
		::haxor::context::EngineContext_obj::renderer->sap_dirty = false;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(RenderEngine_obj,RenderFinish,(void))

Void RenderEngine_obj::Resize( ){
{
		HX_STACK_FRAME("haxor.core.RenderEngine","Resize",0xf1b03b07,"haxor.core.RenderEngine.Resize","haxor/core/RenderEngine.hx",137,0xca802223)
		HX_STACK_LINE(137)
		::haxor::context::EngineContext_obj::camera->Resize();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(RenderEngine_obj,Resize,(void))


RenderEngine_obj::RenderEngine_obj()
{
}

Dynamic RenderEngine_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"Render") ) { return Render_dyn(); }
		if (HX_FIELD_EQ(inName,"Resize") ) { return Resize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"RenderCamera") ) { return RenderCamera_dyn(); }
		if (HX_FIELD_EQ(inName,"RenderFinish") ) { return RenderFinish_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"RenderCameras") ) { return RenderCameras_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"RenderRenderer") ) { return RenderRenderer_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"RenderCameraLayer") ) { return RenderCameraLayer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RenderEngine_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void RenderEngine_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Render"),
	HX_CSTRING("RenderCameras"),
	HX_CSTRING("RenderCamera"),
	HX_CSTRING("RenderCameraLayer"),
	HX_CSTRING("RenderRenderer"),
	HX_CSTRING("RenderFinish"),
	HX_CSTRING("Resize"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RenderEngine_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RenderEngine_obj::__mClass,"__mClass");
};

#endif

Class RenderEngine_obj::__mClass;

void RenderEngine_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.RenderEngine"), hx::TCanCast< RenderEngine_obj> ,sStaticFields,sMemberFields,
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

void RenderEngine_obj::__boot()
{
}

} // end namespace haxor
} // end namespace core
