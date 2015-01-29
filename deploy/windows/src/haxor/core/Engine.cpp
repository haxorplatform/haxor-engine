#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_animation_Animation
#include <haxor/component/animation/Animation.h>
#endif
#ifndef INCLUDED_haxor_context_BaseProcess
#include <haxor/context/BaseProcess.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_Process
#include <haxor/context/Process.h>
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
#ifndef INCLUDED_haxor_core_RenderEngine
#include <haxor/core/RenderEngine.h>
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
		HX_STACK_FRAME("haxor.core.Engine","Initialize",0x7c7ff859,"haxor.core.Engine.Initialize","haxor/core/Engine.hx",36,0xa988a499)
		HX_STACK_LINE(37)
		::haxor::core::Console_obj::Log(HX_CSTRING("Haxor> Engine Initialize."),(int)3);
		HX_STACK_LINE(38)
		::haxor::context::EngineContext_obj::Initialize();
		HX_STACK_LINE(39)
		::haxor::core::Engine_obj::state = ::haxor::core::EngineState_obj::Play;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Initialize,(void))

Void Engine_obj::Collect( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Collect",0x5d050f01,"haxor.core.Engine.Collect","haxor/core/Engine.hx",46,0xa988a499)
		HX_STACK_LINE(47)
		::haxor::context::Process dp = ::haxor::context::EngineContext_obj::disposables;		HX_STACK_VAR(dp,"dp");
		HX_STACK_LINE(48)
		{
			HX_STACK_LINE(48)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(48)
			int _g = ::haxor::context::EngineContext_obj::collectRate;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(48)
			while((true)){
				HX_STACK_LINE(48)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(48)
					break;
				}
				HX_STACK_LINE(48)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(50)
				if (((dp->m_length <= (int)0))){
					HX_STACK_LINE(50)
					break;
				}
				HX_STACK_LINE(51)
				::haxor::core::IDisposable o = dp->list->__GetItem((int)0);		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(52)
				o->OnDestroy();
				HX_STACK_LINE(53)
				dp->Remove(o);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Collect,(void))

Void Engine_obj::Update( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Update",0x23a5d492,"haxor.core.Engine.Update","haxor/core/Engine.hx",61,0xa988a499)
		HX_STACK_LINE(63)
		if (((::haxor::core::Engine_obj::state == ::haxor::core::EngineState_obj::Editor))){
			HX_STACK_LINE(63)
			return null();
		}
		HX_STACK_LINE(66)
		::haxor::component::animation::Animation_obj::Update();
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
		::haxor::core::RenderEngine_obj::Render();
		HX_STACK_LINE(94)
		::haxor::core::Engine_obj::RenderIRenderers();
		HX_STACK_LINE(97)
		::haxor::core::RenderEngine_obj::RenderFinish();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Render,(void))

Void Engine_obj::RenderIRenderers( ){
{
		HX_STACK_FRAME("haxor.core.Engine","RenderIRenderers",0x58ca4ae6,"haxor.core.Engine.RenderIRenderers","haxor/core/Engine.hx",106,0xa988a499)
		HX_STACK_LINE(107)
		::haxor::context::Process rp = ::haxor::context::EngineContext_obj::render;		HX_STACK_VAR(rp,"rp");
		HX_STACK_LINE(109)
		{
			HX_STACK_LINE(109)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(109)
			int _g = rp->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(109)
			while((true)){
				HX_STACK_LINE(109)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(109)
					break;
				}
				HX_STACK_LINE(109)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(111)
				::haxor::core::Resource r = rp->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(112)
				if ((r->m_destroyed)){
					HX_STACK_LINE(112)
					continue;
				}
				HX_STACK_LINE(113)
				rp->list->__GetItem(i)->__Field(HX_CSTRING("OnRender"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,RenderIRenderers,(void))

Void Engine_obj::Resize( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Resize",0xa51ba87d,"haxor.core.Engine.Resize","haxor/core/Engine.hx",121,0xa988a499)
		HX_STACK_LINE(123)
		::haxor::core::RenderEngine_obj::Resize();
		HX_STACK_LINE(126)
		if (((::haxor::core::Engine_obj::state == ::haxor::core::EngineState_obj::Editor))){
			HX_STACK_LINE(126)
			return null();
		}
		HX_STACK_LINE(128)
		::haxor::context::Process rp = ::haxor::context::EngineContext_obj::resize;		HX_STACK_VAR(rp,"rp");
		HX_STACK_LINE(129)
		{
			HX_STACK_LINE(129)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(129)
			int _g = rp->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(129)
			while((true)){
				HX_STACK_LINE(129)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(129)
					break;
				}
				HX_STACK_LINE(129)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(131)
				::haxor::core::Resource r = rp->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(132)
				if ((r->m_destroyed)){
					HX_STACK_LINE(132)
					continue;
				}
				HX_STACK_LINE(133)
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
	case 16:
		if (HX_FIELD_EQ(inName,"RenderIRenderers") ) { return RenderIRenderers_dyn(); }
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
