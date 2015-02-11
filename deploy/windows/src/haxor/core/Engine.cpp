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
#ifndef INCLUDED_haxor_context_PhysicsContext
#include <haxor/context/PhysicsContext.h>
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
		HX_STACK_FRAME("haxor.core.Engine","Initialize",0x7c7ff859,"haxor.core.Engine.Initialize","haxor/core/Engine.hx",37,0xa988a499)
		HX_STACK_LINE(38)
		::haxor::core::Console_obj::Log(HX_CSTRING("Haxor> Engine Initialize."),(int)3);
		HX_STACK_LINE(39)
		::haxor::context::EngineContext_obj::Initialize();
		HX_STACK_LINE(40)
		::haxor::core::Engine_obj::state = ::haxor::core::EngineState_obj::Play;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Initialize,(void))

Void Engine_obj::Collect( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Collect",0x5d050f01,"haxor.core.Engine.Collect","haxor/core/Engine.hx",47,0xa988a499)
		HX_STACK_LINE(48)
		::haxor::context::Process dp = ::haxor::context::EngineContext_obj::disposables;		HX_STACK_VAR(dp,"dp");
		HX_STACK_LINE(49)
		{
			HX_STACK_LINE(49)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(49)
			int _g = ::haxor::context::EngineContext_obj::collectRate;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(49)
			while((true)){
				HX_STACK_LINE(49)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(49)
					break;
				}
				HX_STACK_LINE(49)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(51)
				if (((dp->m_length <= (int)0))){
					HX_STACK_LINE(51)
					break;
				}
				HX_STACK_LINE(52)
				::haxor::core::IDisposable o = dp->list->__GetItem((int)0);		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(53)
				o->OnDestroy();
				HX_STACK_LINE(54)
				dp->Remove(o);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Collect,(void))

Void Engine_obj::Update( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Update",0x23a5d492,"haxor.core.Engine.Update","haxor/core/Engine.hx",62,0xa988a499)
		HX_STACK_LINE(64)
		if (((::haxor::core::Engine_obj::state == ::haxor::core::EngineState_obj::Editor))){
			HX_STACK_LINE(64)
			return null();
		}
		HX_STACK_LINE(66)
		Array< ::Dynamic > bl;		HX_STACK_VAR(bl,"bl");
		HX_STACK_LINE(67)
		int k;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(69)
		bl = ::haxor::context::EngineContext_obj::awake;
		HX_STACK_LINE(70)
		{
			HX_STACK_LINE(70)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(70)
			int _g = bl->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(70)
			while((true)){
				HX_STACK_LINE(70)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(70)
					break;
				}
				HX_STACK_LINE(70)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(72)
				::haxor::component::Behaviour b = bl->shift().StaticCast< ::haxor::component::Behaviour >();		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(73)
				b->OnAwake();
				HX_STACK_LINE(74)
				b->m_is_awake = true;
			}
		}
		HX_STACK_LINE(78)
		bl = ::haxor::context::EngineContext_obj::start;
		HX_STACK_LINE(78)
		k = (int)0;
		HX_STACK_LINE(79)
		while((true)){
			HX_STACK_LINE(79)
			if ((!(((k < bl->length))))){
				HX_STACK_LINE(79)
				break;
			}
			HX_STACK_LINE(81)
			int _g = (k)++;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(81)
			::haxor::component::Behaviour b = bl->__get(_g).StaticCast< ::haxor::component::Behaviour >();		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(82)
			if ((!(b->get_enabled()))){
				HX_STACK_LINE(82)
				continue;
			}
			HX_STACK_LINE(83)
			if ((!(b->m_is_awake))){
				HX_STACK_LINE(83)
				continue;
			}
			HX_STACK_LINE(84)
			b->OnStart();
			HX_STACK_LINE(85)
			b->m_is_start = true;
			HX_STACK_LINE(86)
			bl->remove(b);
			HX_STACK_LINE(87)
			(k)--;
		}
		HX_STACK_LINE(90)
		::haxor::context::Process up = ::haxor::context::EngineContext_obj::update;		HX_STACK_VAR(up,"up");
		HX_STACK_LINE(92)
		{
			HX_STACK_LINE(92)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(92)
			int _g = up->m_length;		HX_STACK_VAR(_g,"_g");
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
				::haxor::core::Resource r = up->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(95)
				if (((r == null()))){
					HX_STACK_LINE(95)
					continue;
				}
				HX_STACK_LINE(96)
				if ((r->m_destroyed)){
					HX_STACK_LINE(96)
					continue;
				}
				HX_STACK_LINE(97)
				if ((r->m_is_behaviour)){
					HX_STACK_LINE(99)
					::haxor::component::Behaviour b = r;		HX_STACK_VAR(b,"b");
					HX_STACK_LINE(100)
					if ((!(b->m_is_awake))){
						HX_STACK_LINE(100)
						continue;
					}
					HX_STACK_LINE(101)
					if ((!(b->m_is_start))){
						HX_STACK_LINE(101)
						continue;
					}
				}
				HX_STACK_LINE(103)
				up->list->__GetItem(i)->__Field(HX_CSTRING("OnUpdate"),true)();
			}
		}
		HX_STACK_LINE(107)
		::haxor::component::animation::Animation_obj::Update();
		HX_STACK_LINE(108)
		::haxor::context::EngineContext_obj::physics->Step();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Update,(void))

Void Engine_obj::Render( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Render",0xa1c9b9df,"haxor.core.Engine.Render","haxor/core/Engine.hx",117,0xa988a499)
		HX_STACK_LINE(119)
		::haxor::core::RenderEngine_obj::Render();
		HX_STACK_LINE(122)
		::haxor::core::Engine_obj::RenderIRenderers();
		HX_STACK_LINE(125)
		::haxor::core::RenderEngine_obj::RenderFinish();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Render,(void))

Void Engine_obj::RenderIRenderers( ){
{
		HX_STACK_FRAME("haxor.core.Engine","RenderIRenderers",0x58ca4ae6,"haxor.core.Engine.RenderIRenderers","haxor/core/Engine.hx",134,0xa988a499)
		HX_STACK_LINE(135)
		::haxor::context::Process rp = ::haxor::context::EngineContext_obj::render;		HX_STACK_VAR(rp,"rp");
		HX_STACK_LINE(137)
		{
			HX_STACK_LINE(137)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(137)
			int _g = rp->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(137)
			while((true)){
				HX_STACK_LINE(137)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(137)
					break;
				}
				HX_STACK_LINE(137)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(139)
				::haxor::core::Resource r = rp->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(140)
				if ((r->m_destroyed)){
					HX_STACK_LINE(140)
					continue;
				}
				HX_STACK_LINE(141)
				rp->list->__GetItem(i)->__Field(HX_CSTRING("OnRender"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,RenderIRenderers,(void))

Void Engine_obj::Resize( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Resize",0xa51ba87d,"haxor.core.Engine.Resize","haxor/core/Engine.hx",149,0xa988a499)
		HX_STACK_LINE(151)
		::haxor::core::RenderEngine_obj::Resize();
		HX_STACK_LINE(154)
		if (((::haxor::core::Engine_obj::state == ::haxor::core::EngineState_obj::Editor))){
			HX_STACK_LINE(154)
			return null();
		}
		HX_STACK_LINE(156)
		::haxor::context::Process rp = ::haxor::context::EngineContext_obj::resize;		HX_STACK_VAR(rp,"rp");
		HX_STACK_LINE(157)
		{
			HX_STACK_LINE(157)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(157)
			int _g = rp->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(157)
			while((true)){
				HX_STACK_LINE(157)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(157)
					break;
				}
				HX_STACK_LINE(157)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(159)
				::haxor::core::Resource r = rp->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(160)
				if ((r->m_destroyed)){
					HX_STACK_LINE(160)
					continue;
				}
				HX_STACK_LINE(161)
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
