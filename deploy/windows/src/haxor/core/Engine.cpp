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
#ifndef INCLUDED_haxor_context_Process
#include <haxor/context/Process.h>
#endif
#ifndef INCLUDED_haxor_context_RendererContext
#include <haxor/context/RendererContext.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_haxor_core_Engine
#include <haxor/core/Engine.h>
#endif
#ifndef INCLUDED_haxor_core_EngineState
#include <haxor/core/EngineState.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IRenderable
#include <haxor/core/IRenderable.h>
#endif
#ifndef INCLUDED_haxor_core_IResizeable
#include <haxor/core/IResizeable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_Stats
#include <haxor/core/Stats.h>
#endif
#ifndef INCLUDED_haxor_graphics_Screen
#include <haxor/graphics/Screen.h>
#endif
namespace haxor{
namespace core{

Void Engine_obj::__construct()
{
	return null();
}

//Engine_obj::~Engine_obj() { }

Dynamic Engine_obj::__CreateEmpty() { return  new Engine_obj; }
hx::ObjectPtr< Engine_obj > Engine_obj::__new()
{  hx::ObjectPtr< Engine_obj > result = new Engine_obj();
	result->__construct();
	return result;}

Dynamic Engine_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Engine_obj > result = new Engine_obj();
	result->__construct();
	return result;}

::haxor::core::EngineState Engine_obj::state;

Void Engine_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Initialize",0x7c7ff859,"haxor.core.Engine.Initialize","haxor/core/Engine.hx",40,0xa988a499)
		HX_STACK_LINE(41)
		::haxor::core::Console_obj::Log(HX_CSTRING("Haxor> Engine Initialize."),(int)3);
		HX_STACK_LINE(42)
		::haxor::context::EngineContext_obj::Initialize();
		HX_STACK_LINE(43)
		::haxor::core::Engine_obj::state = ::haxor::core::EngineState_obj::Play;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Initialize,(void))

Void Engine_obj::Collect( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Collect",0x5d050f01,"haxor.core.Engine.Collect","haxor/core/Engine.hx",50,0xa988a499)
		HX_STACK_LINE(51)
		::haxor::context::Process dp = ::haxor::context::EngineContext_obj::disposables;		HX_STACK_VAR(dp,"dp");
		HX_STACK_LINE(52)
		{
			HX_STACK_LINE(52)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(52)
			int _g = ::haxor::context::EngineContext_obj::collectRate;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(52)
			while((true)){
				HX_STACK_LINE(52)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(52)
					break;
				}
				HX_STACK_LINE(52)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(54)
				if (((dp->m_length <= (int)0))){
					HX_STACK_LINE(54)
					break;
				}
				HX_STACK_LINE(55)
				::haxor::core::IDisposable o = dp->list->__GetItem((int)0);		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(56)
				o->OnDestroy();
				HX_STACK_LINE(57)
				dp->Remove(o);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Collect,(void))

Void Engine_obj::Update( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Update",0x23a5d492,"haxor.core.Engine.Update","haxor/core/Engine.hx",65,0xa988a499)
		HX_STACK_LINE(67)
		if (((::haxor::core::Engine_obj::state == ::haxor::core::EngineState_obj::Editor))){
			HX_STACK_LINE(67)
			return null();
		}
		HX_STACK_LINE(69)
		::haxor::context::Process up = ::haxor::context::EngineContext_obj::update;		HX_STACK_VAR(up,"up");
		HX_STACK_LINE(71)
		{
			HX_STACK_LINE(71)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(71)
			int _g = up->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(71)
			while((true)){
				HX_STACK_LINE(71)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(71)
					break;
				}
				HX_STACK_LINE(71)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(73)
				::haxor::core::Resource r = up->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(74)
				if ((r->m_destroyed)){
					HX_STACK_LINE(74)
					continue;
				}
				HX_STACK_LINE(75)
				if ((r->m_is_behaviour)){
					HX_STACK_LINE(77)
					::haxor::component::Behaviour b = r;		HX_STACK_VAR(b,"b");
					HX_STACK_LINE(78)
					if ((!(b->m_is_awake))){
						HX_STACK_LINE(78)
						b->OnAwake();
						HX_STACK_LINE(78)
						b->m_is_awake = true;
					}
					HX_STACK_LINE(79)
					if ((!(b->m_is_start))){
						HX_STACK_LINE(79)
						b->OnStart();
						HX_STACK_LINE(79)
						b->m_is_start = true;
					}
				}
				HX_STACK_LINE(81)
				up->list->__GetItem(i)->__Field(HX_CSTRING("OnUpdate"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Update,(void))

Void Engine_obj::Render( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Render",0xa1c9b9df,"haxor.core.Engine.Render","haxor/core/Engine.hx",89,0xa988a499)
		HX_STACK_LINE(91)
		::haxor::core::Stats_obj::BeginRender();
		HX_STACK_LINE(94)
		::haxor::core::Engine_obj::RenderCameras();
		HX_STACK_LINE(95)
		::haxor::core::Engine_obj::RenderIRenderers();
		HX_STACK_LINE(96)
		::haxor::core::Engine_obj::RenderFinish();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Render,(void))

Void Engine_obj::RenderCameras( ){
{
		HX_STACK_FRAME("haxor.core.Engine","RenderCameras",0x1143820f,"haxor.core.Engine.RenderCameras","haxor/core/Engine.hx",103,0xa988a499)
		HX_STACK_LINE(104)
		Array< ::Dynamic > cl = ::haxor::context::EngineContext_obj::camera->list;		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(105)
		{
			HX_STACK_LINE(105)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(105)
			int _g = cl->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(105)
			while((true)){
				HX_STACK_LINE(105)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(105)
					break;
				}
				HX_STACK_LINE(105)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(107)
				::haxor::component::Camera c = ::haxor::component::Camera_obj::m_current = cl->__get(i).StaticCast< ::haxor::component::Camera >();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(108)
				::haxor::core::Engine_obj::RenderCamera(c);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,RenderCameras,(void))

Void Engine_obj::RenderCamera( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.core.Engine","RenderCamera",0xc6ada5e4,"haxor.core.Engine.RenderCamera","haxor/core/Engine.hx",117,0xa988a499)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(118)
		if ((!(c->get_enabled()))){
			HX_STACK_LINE(118)
			return null();
		}
		HX_STACK_LINE(119)
		::haxor::context::EngineContext_obj::camera->Bind(c);
		HX_STACK_LINE(120)
		Array< int > layers = c->m_layers;		HX_STACK_VAR(layers,"layers");
		HX_STACK_LINE(121)
		{
			HX_STACK_LINE(121)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(121)
			int _g = layers->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(121)
			while((true)){
				HX_STACK_LINE(121)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(121)
					break;
				}
				HX_STACK_LINE(121)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(123)
				int l = layers->__get(i);		HX_STACK_VAR(l,"l");
				HX_STACK_LINE(124)
				::haxor::core::Engine_obj::RenderCameraLayer(l,c);
			}
		}
		HX_STACK_LINE(129)
		::haxor::context::EngineContext_obj::camera->Unbind(c);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Engine_obj,RenderCamera,(void))

Void Engine_obj::RenderCameraLayer( int l,::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.core.Engine","RenderCameraLayer",0xf508714d,"haxor.core.Engine.RenderCameraLayer","haxor/core/Engine.hx",140,0xa988a499)
		HX_STACK_ARG(l,"l")
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(142)
		::haxor::component::Transform lt = null();		HX_STACK_VAR(lt,"lt");
		HX_STACK_LINE(143)
		::haxor::context::Process renderers = ::haxor::context::EngineContext_obj::renderer->display->__get(l).StaticCast< ::haxor::context::Process >();		HX_STACK_VAR(renderers,"renderers");
		HX_STACK_LINE(144)
		{
			HX_STACK_LINE(144)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(144)
			int _g = renderers->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(144)
			while((true)){
				HX_STACK_LINE(144)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(144)
					break;
				}
				HX_STACK_LINE(144)
				int j = (_g1)++;		HX_STACK_VAR(j,"j");
				HX_STACK_LINE(146)
				::haxor::component::Renderer r = renderers->list->__GetItem(j);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(148)
				if ((::haxor::context::EngineContext_obj::renderer->IsSAPCulled(r,c))){
					HX_STACK_LINE(148)
					continue;
				}
				HX_STACK_LINE(151)
				::haxor::core::Engine_obj::RenderRenderer(r);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Engine_obj,RenderCameraLayer,(void))

Void Engine_obj::RenderRenderer( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.core.Engine","RenderRenderer",0xd482b242,"haxor.core.Engine.RenderRenderer","haxor/core/Engine.hx",160,0xa988a499)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(162)
		r->UpdateCulling();
		HX_STACK_LINE(164)
		if ((!(((bool(r->m_visible) && bool(!(r->m_culled))))))){
			HX_STACK_LINE(167)
			(::haxor::core::Stats_obj::culled)++;
			HX_STACK_LINE(169)
			return null();
		}
		HX_STACK_LINE(173)
		(::haxor::core::Stats_obj::visible)++;
		HX_STACK_LINE(178)
		r->OnRender();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Engine_obj,RenderRenderer,(void))

Void Engine_obj::RenderIRenderers( ){
{
		HX_STACK_FRAME("haxor.core.Engine","RenderIRenderers",0x58ca4ae6,"haxor.core.Engine.RenderIRenderers","haxor/core/Engine.hx",187,0xa988a499)
		HX_STACK_LINE(188)
		::haxor::component::Camera_obj::m_current = null();
		HX_STACK_LINE(189)
		::haxor::context::Process rp = ::haxor::context::EngineContext_obj::render;		HX_STACK_VAR(rp,"rp");
		HX_STACK_LINE(191)
		{
			HX_STACK_LINE(191)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(191)
			int _g = rp->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(191)
			while((true)){
				HX_STACK_LINE(191)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(191)
					break;
				}
				HX_STACK_LINE(191)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(193)
				::haxor::core::Resource r = rp->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(194)
				if ((r->m_destroyed)){
					HX_STACK_LINE(194)
					continue;
				}
				HX_STACK_LINE(195)
				rp->list->__GetItem(i)->__Field(HX_CSTRING("OnRender"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,RenderIRenderers,(void))

Void Engine_obj::RenderFinish( ){
{
		HX_STACK_FRAME("haxor.core.Engine","RenderFinish",0x95a09f92,"haxor.core.Engine.RenderFinish","haxor/core/Engine.hx",203,0xa988a499)
		HX_STACK_LINE(204)
		Array< ::Dynamic > cl = ::haxor::context::EngineContext_obj::camera->list;		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(205)
		{
			HX_STACK_LINE(205)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(205)
			int _g = cl->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(205)
			while((true)){
				HX_STACK_LINE(205)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(205)
					break;
				}
				HX_STACK_LINE(205)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(207)
				cl->__get(i).StaticCast< ::haxor::component::Camera >()->m_view_uniform_dirty = false;
				HX_STACK_LINE(208)
				cl->__get(i).StaticCast< ::haxor::component::Camera >()->m_proj_uniform_dirty = false;
			}
		}
		HX_STACK_LINE(211)
		::haxor::context::EngineContext_obj::renderer->sap_dirty = false;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,RenderFinish,(void))

Void Engine_obj::Resize( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Resize",0xa51ba87d,"haxor.core.Engine.Resize","haxor/core/Engine.hx",218,0xa988a499)
		HX_STACK_LINE(219)
		::haxor::context::EngineContext_obj::camera->Resize();
		HX_STACK_LINE(220)
		if (((::haxor::core::Engine_obj::state == ::haxor::core::EngineState_obj::Editor))){
			HX_STACK_LINE(220)
			return null();
		}
		HX_STACK_LINE(221)
		::haxor::context::Process rp = ::haxor::context::EngineContext_obj::resize;		HX_STACK_VAR(rp,"rp");
		HX_STACK_LINE(222)
		{
			HX_STACK_LINE(222)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(222)
			int _g = rp->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(222)
			while((true)){
				HX_STACK_LINE(222)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(222)
					break;
				}
				HX_STACK_LINE(222)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(224)
				::haxor::core::Resource r = rp->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(225)
				if ((r->m_destroyed)){
					HX_STACK_LINE(225)
					continue;
				}
				HX_STACK_LINE(226)
				rp->list->__GetItem(i)->__Field(HX_CSTRING("OnResize"),true)(::haxor::graphics::Screen_obj::m_width,::haxor::graphics::Screen_obj::m_height);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Resize,(void))


Engine_obj::Engine_obj()
{
}

Dynamic Engine_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Update") ) { return Update_dyn(); }
		if (HX_FIELD_EQ(inName,"Render") ) { return Render_dyn(); }
		if (HX_FIELD_EQ(inName,"Resize") ) { return Resize_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Collect") ) { return Collect_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
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
	case 16:
		if (HX_FIELD_EQ(inName,"RenderIRenderers") ) { return RenderIRenderers_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"RenderCameraLayer") ) { return RenderCameraLayer_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Engine_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< ::haxor::core::EngineState >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Engine_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("state"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Collect"),
	HX_CSTRING("Update"),
	HX_CSTRING("Render"),
	HX_CSTRING("RenderCameras"),
	HX_CSTRING("RenderCamera"),
	HX_CSTRING("RenderCameraLayer"),
	HX_CSTRING("RenderRenderer"),
	HX_CSTRING("RenderIRenderers"),
	HX_CSTRING("RenderFinish"),
	HX_CSTRING("Resize"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Engine_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Engine_obj::state,"state");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Engine_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Engine_obj::state,"state");
};

#endif

Class Engine_obj::__mClass;

void Engine_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.Engine"), hx::TCanCast< Engine_obj> ,sStaticFields,sMemberFields,
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

void Engine_obj::__boot()
{
}

} // end namespace haxor
} // end namespace core
