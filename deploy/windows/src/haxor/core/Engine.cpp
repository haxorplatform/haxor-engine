#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_context_HaxorContext
#include <haxor/context/HaxorContext.h>
#endif
#ifndef INCLUDED_haxor_context_Process
#include <haxor/context/Process.h>
#endif
#ifndef INCLUDED_haxor_core_BaseApplication
#include <haxor/core/BaseApplication.h>
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

Void Engine_obj::__construct(::haxor::core::BaseApplication p_application)
{
HX_STACK_FRAME("haxor.core.Engine","new",0x65fd4a57,"haxor.core.Engine.new","haxor/core/Engine.hx",37,0xa988a499)
HX_STACK_THIS(this)
HX_STACK_ARG(p_application,"p_application")
{
	HX_STACK_LINE(38)
	this->m_application = p_application;
	HX_STACK_LINE(39)
	this->state = ::haxor::core::EngineState_obj::Play;
}
;
	return null();
}

//Engine_obj::~Engine_obj() { }

Dynamic Engine_obj::__CreateEmpty() { return  new Engine_obj; }
hx::ObjectPtr< Engine_obj > Engine_obj::__new(::haxor::core::BaseApplication p_application)
{  hx::ObjectPtr< Engine_obj > result = new Engine_obj();
	result->__construct(p_application);
	return result;}

Dynamic Engine_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Engine_obj > result = new Engine_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Engine_obj::Collect( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Collect",0x5d050f01,"haxor.core.Engine.Collect","haxor/core/Engine.hx",46,0xa988a499)
		HX_STACK_THIS(this)
		HX_STACK_LINE(48)
		::haxor::context::Process dispose_p = ::haxor::context::HaxorContext_obj::disposables;		HX_STACK_VAR(dispose_p,"dispose_p");
		HX_STACK_LINE(49)
		{
			HX_STACK_LINE(49)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(49)
			int _g = ::haxor::context::HaxorContext_obj::collectRate;		HX_STACK_VAR(_g,"_g");
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
				int _g2 = dispose_p->get_length();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(51)
				if (((_g2 <= (int)0))){
					HX_STACK_LINE(51)
					break;
				}
				HX_STACK_LINE(52)
				::haxor::core::IDisposable o = dispose_p->list->__GetItem((int)0);		HX_STACK_VAR(o,"o");
				HX_STACK_LINE(53)
				o->OnDestroy();
				HX_STACK_LINE(54)
				dispose_p->Remove(o);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Collect,(void))

Void Engine_obj::Update( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Update",0x23a5d492,"haxor.core.Engine.Update","haxor/core/Engine.hx",62,0xa988a499)
		HX_STACK_THIS(this)
		HX_STACK_LINE(63)
		if (((this->state == ::haxor::core::EngineState_obj::Editor))){
			HX_STACK_LINE(63)
			return null();
		}
		HX_STACK_LINE(65)
		::haxor::context::Process update_p = ::haxor::context::HaxorContext_obj::update;		HX_STACK_VAR(update_p,"update_p");
		HX_STACK_LINE(67)
		{
			HX_STACK_LINE(67)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(67)
			int _g = update_p->get_length();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(67)
			while((true)){
				HX_STACK_LINE(67)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(67)
					break;
				}
				HX_STACK_LINE(67)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(69)
				::haxor::core::Resource r = update_p->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(70)
				if ((r->m_destroyed)){
					HX_STACK_LINE(70)
					continue;
				}
				HX_STACK_LINE(71)
				if ((r->m_is_behaviour)){
					HX_STACK_LINE(73)
					::haxor::component::Behaviour b = r;		HX_STACK_VAR(b,"b");
					HX_STACK_LINE(74)
					if ((!(b->m_is_awake))){
						HX_STACK_LINE(74)
						b->OnAwake();
						HX_STACK_LINE(74)
						b->m_is_awake = true;
					}
					HX_STACK_LINE(75)
					if ((!(b->m_is_start))){
						HX_STACK_LINE(75)
						b->OnStart();
						HX_STACK_LINE(75)
						b->m_is_start = true;
					}
				}
				HX_STACK_LINE(77)
				update_p->list->__GetItem(i)->__Field(HX_CSTRING("OnUpdate"),true)();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Update,(void))

Void Engine_obj::Render( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Render",0xa1c9b9df,"haxor.core.Engine.Render","haxor/core/Engine.hx",85,0xa988a499)
		HX_STACK_THIS(this)
		HX_STACK_LINE(87)
		::haxor::context::Process render_p = ::haxor::context::HaxorContext_obj::render;		HX_STACK_VAR(render_p,"render_p");
		HX_STACK_LINE(88)
		{
			HX_STACK_LINE(88)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(88)
			int _g = render_p->get_length();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(88)
			while((true)){
				HX_STACK_LINE(88)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(88)
					break;
				}
				HX_STACK_LINE(88)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(90)
				::haxor::core::Resource r = render_p->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(91)
				if ((r->m_destroyed)){
					HX_STACK_LINE(91)
					continue;
				}
				HX_STACK_LINE(92)
				render_p->list->__GetItem(i)->__Field(HX_CSTRING("OnRender"),true)();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Render,(void))

Void Engine_obj::Resize( ){
{
		HX_STACK_FRAME("haxor.core.Engine","Resize",0xa51ba87d,"haxor.core.Engine.Resize","haxor/core/Engine.hx",100,0xa988a499)
		HX_STACK_THIS(this)
		HX_STACK_LINE(101)
		if (((this->state == ::haxor::core::EngineState_obj::Editor))){
			HX_STACK_LINE(101)
			return null();
		}
		HX_STACK_LINE(102)
		::haxor::context::Process resize_p = ::haxor::context::HaxorContext_obj::resize;		HX_STACK_VAR(resize_p,"resize_p");
		HX_STACK_LINE(103)
		{
			HX_STACK_LINE(103)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(103)
			int _g = resize_p->get_length();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(103)
			while((true)){
				HX_STACK_LINE(103)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(103)
					break;
				}
				HX_STACK_LINE(103)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(105)
				::haxor::core::Resource r = resize_p->list->__GetItem(i);		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(106)
				if ((r->m_destroyed)){
					HX_STACK_LINE(106)
					continue;
				}
				HX_STACK_LINE(107)
				resize_p->list->__GetItem(i)->__Field(HX_CSTRING("OnResize"),true)(::haxor::graphics::Screen_obj::m_width,::haxor::graphics::Screen_obj::m_height);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Engine_obj,Resize,(void))


Engine_obj::Engine_obj()
{
}

void Engine_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Engine);
	HX_MARK_MEMBER_NAME(state,"state");
	HX_MARK_MEMBER_NAME(m_application,"m_application");
	HX_MARK_END_CLASS();
}

void Engine_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(state,"state");
	HX_VISIT_MEMBER_NAME(m_application,"m_application");
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
	case 13:
		if (HX_FIELD_EQ(inName,"m_application") ) { return m_application; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Engine_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< ::haxor::core::EngineState >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_application") ) { m_application=inValue.Cast< ::haxor::core::BaseApplication >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Engine_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("state"));
	outFields->push(HX_CSTRING("m_application"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::core::EngineState*/ ,(int)offsetof(Engine_obj,state),HX_CSTRING("state")},
	{hx::fsObject /*::haxor::core::BaseApplication*/ ,(int)offsetof(Engine_obj,m_application),HX_CSTRING("m_application")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("state"),
	HX_CSTRING("m_application"),
	HX_CSTRING("Collect"),
	HX_CSTRING("Update"),
	HX_CSTRING("Render"),
	HX_CSTRING("Resize"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Engine_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Engine_obj::__mClass,"__mClass");
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
