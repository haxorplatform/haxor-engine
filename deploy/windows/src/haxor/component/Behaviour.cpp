#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
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
namespace haxor{
namespace component{

Void Behaviour_obj::__construct()
{
HX_STACK_FRAME("haxor.component.Behaviour","new",0xa41113f2,"haxor.component.Behaviour.new","haxor/component/Behaviour.hx",54,0x6f707600)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(55)
	super::__construct();
	HX_STACK_LINE(57)
	this->m_enabled = true;
	HX_STACK_LINE(58)
	this->m_is_behaviour = true;
	HX_STACK_LINE(59)
	bool _g = ::Std_obj::is(hx::ObjectPtr<OBJ_>(this),hx::ClassOf< ::haxor::core::IUpdateable >());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(59)
	this->m_is_updateable = _g;
	HX_STACK_LINE(60)
	bool _g1 = ::Std_obj::is(hx::ObjectPtr<OBJ_>(this),hx::ClassOf< ::haxor::core::IRenderable >());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(60)
	this->m_is_renderable = _g1;
	HX_STACK_LINE(61)
	bool _g2 = ::Std_obj::is(hx::ObjectPtr<OBJ_>(this),hx::ClassOf< ::haxor::core::IResizeable >());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(61)
	this->m_is_resizeable = _g2;
	HX_STACK_LINE(62)
	this->UpdateContextFlag(true);
}
;
	return null();
}

//Behaviour_obj::~Behaviour_obj() { }

Dynamic Behaviour_obj::__CreateEmpty() { return  new Behaviour_obj; }
hx::ObjectPtr< Behaviour_obj > Behaviour_obj::__new()
{  hx::ObjectPtr< Behaviour_obj > result = new Behaviour_obj();
	result->__construct();
	return result;}

Dynamic Behaviour_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Behaviour_obj > result = new Behaviour_obj();
	result->__construct();
	return result;}

bool Behaviour_obj::get_enabled( ){
	HX_STACK_FRAME("haxor.component.Behaviour","get_enabled",0xa9118a2a,"haxor.component.Behaviour.get_enabled","haxor/component/Behaviour.hx",18,0x6f707600)
	HX_STACK_THIS(this)
	HX_STACK_LINE(18)
	return (bool(this->m_enabled) && bool(!(this->m_destroyed)));
}


HX_DEFINE_DYNAMIC_FUNC0(Behaviour_obj,get_enabled,return )

bool Behaviour_obj::set_enabled( bool v){
	HX_STACK_FRAME("haxor.component.Behaviour","set_enabled",0xb37e9136,"haxor.component.Behaviour.set_enabled","haxor/component/Behaviour.hx",20,0x6f707600)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(21)
	if ((this->m_destroyed)){
		HX_STACK_LINE(21)
		return false;
	}
	HX_STACK_LINE(22)
	this->m_enabled = v;
	HX_STACK_LINE(23)
	this->UpdateContextFlag(v);
	HX_STACK_LINE(24)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Behaviour_obj,set_enabled,return )

Void Behaviour_obj::OnAwake( ){
{
		HX_STACK_FRAME("haxor.component.Behaviour","OnAwake",0x3bfadbd8,"haxor.component.Behaviour.OnAwake","haxor/component/Behaviour.hx",68,0x6f707600)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Behaviour_obj,OnAwake,(void))

Void Behaviour_obj::OnStart( ){
{
		HX_STACK_FRAME("haxor.component.Behaviour","OnStart",0x9735af35,"haxor.component.Behaviour.OnStart","haxor/component/Behaviour.hx",73,0x6f707600)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Behaviour_obj,OnStart,(void))

Void Behaviour_obj::UpdateContextFlag( bool p_flag){
{
		HX_STACK_FRAME("haxor.component.Behaviour","UpdateContextFlag",0xcd7efca4,"haxor.component.Behaviour.UpdateContextFlag","haxor/component/Behaviour.hx",77,0x6f707600)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(78)
		if ((this->m_is_updateable)){
			HX_STACK_LINE(78)
			if ((p_flag)){
				HX_STACK_LINE(78)
				::haxor::context::EngineContext_obj::update->Add(hx::ObjectPtr<OBJ_>(this));
			}
			else{
				HX_STACK_LINE(78)
				::haxor::context::EngineContext_obj::update->Remove(hx::ObjectPtr<OBJ_>(this));
			}
		}
		HX_STACK_LINE(79)
		if ((this->m_is_renderable)){
			HX_STACK_LINE(79)
			if ((p_flag)){
				HX_STACK_LINE(79)
				::haxor::context::EngineContext_obj::render->Add(hx::ObjectPtr<OBJ_>(this));
			}
			else{
				HX_STACK_LINE(79)
				::haxor::context::EngineContext_obj::render->Remove(hx::ObjectPtr<OBJ_>(this));
			}
		}
		HX_STACK_LINE(80)
		if ((this->m_is_resizeable)){
			HX_STACK_LINE(80)
			if ((p_flag)){
				HX_STACK_LINE(80)
				::haxor::context::EngineContext_obj::resize->Add(hx::ObjectPtr<OBJ_>(this));
			}
			else{
				HX_STACK_LINE(80)
				::haxor::context::EngineContext_obj::resize->Remove(hx::ObjectPtr<OBJ_>(this));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Behaviour_obj,UpdateContextFlag,(void))


Behaviour_obj::Behaviour_obj()
{
}

Dynamic Behaviour_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return get_enabled(); }
		if (HX_FIELD_EQ(inName,"OnAwake") ) { return OnAwake_dyn(); }
		if (HX_FIELD_EQ(inName,"OnStart") ) { return OnStart_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_enabled") ) { return m_enabled; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_is_awake") ) { return m_is_awake; }
		if (HX_FIELD_EQ(inName,"m_is_start") ) { return m_is_start; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_enabled") ) { return get_enabled_dyn(); }
		if (HX_FIELD_EQ(inName,"set_enabled") ) { return set_enabled_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_is_updateable") ) { return m_is_updateable; }
		if (HX_FIELD_EQ(inName,"m_is_renderable") ) { return m_is_renderable; }
		if (HX_FIELD_EQ(inName,"m_is_resizeable") ) { return m_is_resizeable; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"UpdateContextFlag") ) { return UpdateContextFlag_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Behaviour_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return set_enabled(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_enabled") ) { m_enabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_is_awake") ) { m_is_awake=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_is_start") ) { m_is_start=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_is_updateable") ) { m_is_updateable=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_is_renderable") ) { m_is_renderable=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_is_resizeable") ) { m_is_resizeable=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Behaviour_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("enabled"));
	outFields->push(HX_CSTRING("m_enabled"));
	outFields->push(HX_CSTRING("m_is_updateable"));
	outFields->push(HX_CSTRING("m_is_renderable"));
	outFields->push(HX_CSTRING("m_is_resizeable"));
	outFields->push(HX_CSTRING("m_is_awake"));
	outFields->push(HX_CSTRING("m_is_start"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Behaviour_obj,m_enabled),HX_CSTRING("m_enabled")},
	{hx::fsBool,(int)offsetof(Behaviour_obj,m_is_updateable),HX_CSTRING("m_is_updateable")},
	{hx::fsBool,(int)offsetof(Behaviour_obj,m_is_renderable),HX_CSTRING("m_is_renderable")},
	{hx::fsBool,(int)offsetof(Behaviour_obj,m_is_resizeable),HX_CSTRING("m_is_resizeable")},
	{hx::fsBool,(int)offsetof(Behaviour_obj,m_is_awake),HX_CSTRING("m_is_awake")},
	{hx::fsBool,(int)offsetof(Behaviour_obj,m_is_start),HX_CSTRING("m_is_start")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_enabled"),
	HX_CSTRING("set_enabled"),
	HX_CSTRING("m_enabled"),
	HX_CSTRING("m_is_updateable"),
	HX_CSTRING("m_is_renderable"),
	HX_CSTRING("m_is_resizeable"),
	HX_CSTRING("m_is_awake"),
	HX_CSTRING("m_is_start"),
	HX_CSTRING("OnAwake"),
	HX_CSTRING("OnStart"),
	HX_CSTRING("UpdateContextFlag"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Behaviour_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Behaviour_obj::__mClass,"__mClass");
};

#endif

Class Behaviour_obj::__mClass;

void Behaviour_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.Behaviour"), hx::TCanCast< Behaviour_obj> ,sStaticFields,sMemberFields,
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

void Behaviour_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
