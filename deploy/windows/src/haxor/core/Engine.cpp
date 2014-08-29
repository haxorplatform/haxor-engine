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
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
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
		HX_STACK_FRAME("haxor.core.Engine","Initialize",0x7c7ff859,"haxor.core.Engine.Initialize","haxor/core/Engine.hx",39,0xa988a499)
		HX_STACK_LINE(40)
		::haxor::core::Console_obj::Log(HX_CSTRING("Haxor> Engine Initialize."),(int)3);
		HX_STACK_LINE(41)
		::haxor::context::EngineContext_obj::Initialize();
		HX_STACK_LINE(42)
		::haxor::core::Engine_obj::state = ::haxor::core::EngineState_obj::Play;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Initialize,(void))

Void Engine_obj::Collect( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Collect",0x5d050f01,"haxor.core.Engine.Collect","haxor/core/Engine.hx",49,0xa988a499)
		HX_STACK_LINE(50)
		::haxor::context::Process dp = ::haxor::context::EngineContext_obj::disposables;		HX_STACK_VAR(dp,"dp");
		HX_STACK_LINE(51)
		{
			HX_STACK_LINE(51)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(51)
			int _g = ::haxor::context::EngineContext_obj::collectRate;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(51)
			while((true)){
				HX_STACK_LINE(51)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(51)
					break;
				}
				HX_STACK_LINE(51)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(53)
				if (((dp->m_length <= (int)0))){
					HX_STACK_LINE(53)
					break;
				}
				HX_STACK_LINE(54)
				::haxor::core::IDisposable o = dp->list->__GetItem((int)0);		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(55)
				o->OnDestroy();
				HX_STACK_LINE(56)
				dp->Remove(o);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Collect,(void))

Void Engine_obj::Update( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Update",0x23a5d492,"haxor.core.Engine.Update","haxor/core/Engine.hx",64,0xa988a499)
		HX_STACK_LINE(65)
		if (((::haxor::core::Engine_obj::state == ::haxor::core::EngineState_obj::Editor))){
			HX_STACK_LINE(65)
			return null();
		}
		HX_STACK_LINE(67)
		::haxor::context::Process up = ::haxor::context::EngineContext_obj::update;		HX_STACK_VAR(up,"up");
		HX_STACK_LINE(69)
		{
			HX_STACK_LINE(69)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(69)
			int _g = up->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(69)
			while((true)){
				HX_STACK_LINE(69)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(69)
					break;
				}
				HX_STACK_LINE(69)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(71)
				::haxor::core::Resource r = up->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(72)
				if ((r->m_destroyed)){
					HX_STACK_LINE(72)
					continue;
				}
				HX_STACK_LINE(73)
				if ((r->m_is_behaviour)){
					HX_STACK_LINE(75)
					::haxor::component::Behaviour b = r;		HX_STACK_VAR(b,"b");
					HX_STACK_LINE(76)
					if ((!(b->m_is_awake))){
						HX_STACK_LINE(76)
						b->OnAwake();
						HX_STACK_LINE(76)
						b->m_is_awake = true;
					}
					HX_STACK_LINE(77)
					if ((!(b->m_is_start))){
						HX_STACK_LINE(77)
						b->OnStart();
						HX_STACK_LINE(77)
						b->m_is_start = true;
					}
				}
				HX_STACK_LINE(79)
				up->list->__GetItem(i)->__Field(HX_CSTRING("OnUpdate"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Update,(void))

Void Engine_obj::Render( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Render",0xa1c9b9df,"haxor.core.Engine.Render","haxor/core/Engine.hx",87,0xa988a499)
		HX_STACK_LINE(88)
		Array< ::Dynamic > cl = ::haxor::context::EngineContext_obj::camera->list;		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(92)
		{
			HX_STACK_LINE(92)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(92)
			int _g = cl->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(92)
			while((true)){
				HX_STACK_LINE(92)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(92)
					break;
				}
				HX_STACK_LINE(92)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(94)
				::haxor::component::Camera c = ::haxor::component::Camera_obj::m_current = cl->__get(i).StaticCast< ::haxor::component::Camera >();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(95)
				::haxor::core::Engine_obj::RenderCamera(c);
			}
		}
		HX_STACK_LINE(98)
		::haxor::component::Camera_obj::m_current = null();
		HX_STACK_LINE(100)
		::haxor::core::Engine_obj::RenderIRenderers();
		HX_STACK_LINE(102)
		{
			HX_STACK_LINE(102)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(102)
			int _g = cl->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(102)
			while((true)){
				HX_STACK_LINE(102)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(102)
					break;
				}
				HX_STACK_LINE(102)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(104)
				cl->__get(i).StaticCast< ::haxor::component::Camera >()->m_view_uniform_dirty = false;
				HX_STACK_LINE(105)
				cl->__get(i).StaticCast< ::haxor::component::Camera >()->m_proj_uniform_dirty = false;
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Render,(void))

Void Engine_obj::RenderCamera( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.core.Engine","RenderCamera",0xc6ada5e4,"haxor.core.Engine.RenderCamera","haxor/core/Engine.hx",114,0xa988a499)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(115)
		if ((!(c->get_enabled()))){
			HX_STACK_LINE(115)
			return null();
		}
		HX_STACK_LINE(116)
		::haxor::context::EngineContext_obj::camera->Bind(c);
		HX_STACK_LINE(117)
		Array< int > layers = c->m_layers;		HX_STACK_VAR(layers,"layers");
		HX_STACK_LINE(118)
		{
			HX_STACK_LINE(118)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(118)
			int _g = layers->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(118)
			while((true)){
				HX_STACK_LINE(118)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(118)
					break;
				}
				HX_STACK_LINE(118)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(120)
				int l = layers->__get(i);		HX_STACK_VAR(l,"l");
				HX_STACK_LINE(121)
				::haxor::core::Engine_obj::RenderCameraLayer(l,c);
			}
		}
		HX_STACK_LINE(126)
		::haxor::context::EngineContext_obj::camera->Unbind(c);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Engine_obj,RenderCamera,(void))

Void Engine_obj::RenderCameraLayer( int l,::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.core.Engine","RenderCameraLayer",0xf508714d,"haxor.core.Engine.RenderCameraLayer","haxor/core/Engine.hx",135,0xa988a499)
		HX_STACK_ARG(l,"l")
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(136)
		::haxor::component::Transform lt = null();		HX_STACK_VAR(lt,"lt");
		HX_STACK_LINE(137)
		::haxor::context::Process renderers = ::haxor::context::EngineContext_obj::renderer->display->__get(l).StaticCast< ::haxor::context::Process >();		HX_STACK_VAR(renderers,"renderers");
		HX_STACK_LINE(138)
		{
			HX_STACK_LINE(138)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(138)
			int _g = renderers->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(138)
			while((true)){
				HX_STACK_LINE(138)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(138)
					break;
				}
				HX_STACK_LINE(138)
				int j = (_g1)++;		HX_STACK_VAR(j,"j");
				HX_STACK_LINE(140)
				::haxor::component::Renderer r = renderers->list->__GetItem(j);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(142)
				if (((r->m_entity->m_transform != lt))){
					HX_STACK_LINE(142)
					if (((lt != null()))){
						HX_STACK_LINE(142)
						lt->m_uniform_dirty = false;
					}
					HX_STACK_LINE(142)
					lt = r->m_entity->m_transform;
				}
				HX_STACK_LINE(143)
				::haxor::core::Engine_obj::RenderRenderer(r);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Engine_obj,RenderCameraLayer,(void))

Void Engine_obj::RenderRenderer( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.core.Engine","RenderRenderer",0xd482b242,"haxor.core.Engine.RenderRenderer","haxor/core/Engine.hx",155,0xa988a499)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(155)
		r->OnRender();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Engine_obj,RenderRenderer,(void))

Void Engine_obj::RenderIRenderers( ){
{
		HX_STACK_FRAME("haxor.core.Engine","RenderIRenderers",0x58ca4ae6,"haxor.core.Engine.RenderIRenderers","haxor/core/Engine.hx",164,0xa988a499)
		HX_STACK_LINE(165)
		::haxor::context::Process rp = ::haxor::context::EngineContext_obj::render;		HX_STACK_VAR(rp,"rp");
		HX_STACK_LINE(167)
		{
			HX_STACK_LINE(167)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(167)
			int _g = rp->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(167)
			while((true)){
				HX_STACK_LINE(167)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(167)
					break;
				}
				HX_STACK_LINE(167)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(169)
				::haxor::core::Resource r = rp->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(170)
				if ((r->m_destroyed)){
					HX_STACK_LINE(170)
					continue;
				}
				HX_STACK_LINE(171)
				rp->list->__GetItem(i)->__Field(HX_CSTRING("OnRender"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,RenderIRenderers,(void))

Void Engine_obj::Resize( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Resize",0xa51ba87d,"haxor.core.Engine.Resize","haxor/core/Engine.hx",179,0xa988a499)
		HX_STACK_LINE(180)
		::haxor::context::EngineContext_obj::camera->Resize();
		HX_STACK_LINE(181)
		if (((::haxor::core::Engine_obj::state == ::haxor::core::EngineState_obj::Editor))){
			HX_STACK_LINE(181)
			return null();
		}
		HX_STACK_LINE(182)
		::haxor::context::Process rp = ::haxor::context::EngineContext_obj::resize;		HX_STACK_VAR(rp,"rp");
		HX_STACK_LINE(183)
		{
			HX_STACK_LINE(183)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(183)
			int _g = rp->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(183)
			while((true)){
				HX_STACK_LINE(183)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(183)
					break;
				}
				HX_STACK_LINE(183)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(185)
				::haxor::core::Resource r = rp->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(186)
				if ((r->m_destroyed)){
					HX_STACK_LINE(186)
					continue;
				}
				HX_STACK_LINE(187)
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
	HX_CSTRING("RenderCamera"),
	HX_CSTRING("RenderCameraLayer"),
	HX_CSTRING("RenderRenderer"),
	HX_CSTRING("RenderIRenderers"),
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
