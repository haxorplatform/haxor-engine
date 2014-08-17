#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
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
		HX_STACK_FRAME("haxor.core.Engine","Initialize",0x7c7ff859,"haxor.core.Engine.Initialize","haxor/core/Engine.hx",35,0xa988a499)
		HX_STACK_LINE(36)
		::haxor::core::Console_obj::Log(HX_CSTRING("Haxor> Engine Initialize."),(int)3);
		HX_STACK_LINE(37)
		::haxor::context::EngineContext_obj::Initialize();
		HX_STACK_LINE(38)
		::haxor::core::Engine_obj::state = ::haxor::core::EngineState_obj::Play;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Initialize,(void))

Void Engine_obj::Collect( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Collect",0x5d050f01,"haxor.core.Engine.Collect","haxor/core/Engine.hx",45,0xa988a499)
		HX_STACK_LINE(46)
		::haxor::context::Process dp = ::haxor::context::EngineContext_obj::disposables;		HX_STACK_VAR(dp,"dp");
		HX_STACK_LINE(47)
		{
			HX_STACK_LINE(47)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(47)
			int _g = ::haxor::context::EngineContext_obj::collectRate;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(47)
			while((true)){
				HX_STACK_LINE(47)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(47)
					break;
				}
				HX_STACK_LINE(47)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(49)
				if (((dp->m_length <= (int)0))){
					HX_STACK_LINE(49)
					break;
				}
				HX_STACK_LINE(50)
				::haxor::core::IDisposable o = dp->list->__GetItem((int)0);		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(51)
				o->OnDestroy();
				HX_STACK_LINE(52)
				dp->Remove(o);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Collect,(void))

Void Engine_obj::Update( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Update",0x23a5d492,"haxor.core.Engine.Update","haxor/core/Engine.hx",60,0xa988a499)
		HX_STACK_LINE(61)
		if (((::haxor::core::Engine_obj::state == ::haxor::core::EngineState_obj::Editor))){
			HX_STACK_LINE(61)
			return null();
		}
		HX_STACK_LINE(63)
		::haxor::context::Process up = ::haxor::context::EngineContext_obj::update;		HX_STACK_VAR(up,"up");
		HX_STACK_LINE(65)
		{
			HX_STACK_LINE(65)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(65)
			int _g = up->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(65)
			while((true)){
				HX_STACK_LINE(65)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(65)
					break;
				}
				HX_STACK_LINE(65)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(67)
				::haxor::core::Resource r = up->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(68)
				if ((r->m_destroyed)){
					HX_STACK_LINE(68)
					continue;
				}
				HX_STACK_LINE(69)
				if ((r->m_is_behaviour)){
					HX_STACK_LINE(71)
					::haxor::component::Behaviour b = r;		HX_STACK_VAR(b,"b");
					HX_STACK_LINE(72)
					if ((!(b->m_is_awake))){
						HX_STACK_LINE(72)
						b->OnAwake();
						HX_STACK_LINE(72)
						b->m_is_awake = true;
					}
					HX_STACK_LINE(73)
					if ((!(b->m_is_start))){
						HX_STACK_LINE(73)
						b->OnStart();
						HX_STACK_LINE(73)
						b->m_is_start = true;
					}
				}
				HX_STACK_LINE(75)
				up->list->__GetItem(i)->__Field(HX_CSTRING("OnUpdate"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Update,(void))

Void Engine_obj::Render( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Render",0xa1c9b9df,"haxor.core.Engine.Render","haxor/core/Engine.hx",83,0xa988a499)
		HX_STACK_LINE(84)
		::haxor::context::Process rp = ::haxor::context::EngineContext_obj::render;		HX_STACK_VAR(rp,"rp");
		HX_STACK_LINE(85)
		{
			HX_STACK_LINE(85)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(85)
			int _g = rp->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(85)
			while((true)){
				HX_STACK_LINE(85)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(85)
					break;
				}
				HX_STACK_LINE(85)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(87)
				::haxor::core::Resource r = rp->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(88)
				if ((r->m_destroyed)){
					HX_STACK_LINE(88)
					continue;
				}
				HX_STACK_LINE(89)
				rp->list->__GetItem(i)->__Field(HX_CSTRING("OnRender"),true)();
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Render,(void))

Void Engine_obj::Resize( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Resize",0xa51ba87d,"haxor.core.Engine.Resize","haxor/core/Engine.hx",97,0xa988a499)
		HX_STACK_LINE(98)
		if (((::haxor::core::Engine_obj::state == ::haxor::core::EngineState_obj::Editor))){
			HX_STACK_LINE(98)
			return null();
		}
		HX_STACK_LINE(99)
		::haxor::context::Process rp = ::haxor::context::EngineContext_obj::resize;		HX_STACK_VAR(rp,"rp");
		HX_STACK_LINE(100)
		{
			HX_STACK_LINE(100)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(100)
			int _g = rp->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(100)
			while((true)){
				HX_STACK_LINE(100)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(100)
					break;
				}
				HX_STACK_LINE(100)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(102)
				::haxor::core::Resource r = rp->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(103)
				if ((r->m_destroyed)){
					HX_STACK_LINE(103)
					continue;
				}
				HX_STACK_LINE(104)
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
