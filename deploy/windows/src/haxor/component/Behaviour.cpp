#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
namespace haxor{
namespace component{

Void Behaviour_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.Behaviour","new",0xa41113f2,"haxor.component.Behaviour.new","haxor/component/Behaviour.hx",13,0x6f707600)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(13)
	super::__construct(p_name);
}
;
	return null();
}

//Behaviour_obj::~Behaviour_obj() { }

Dynamic Behaviour_obj::__CreateEmpty() { return  new Behaviour_obj; }
hx::ObjectPtr< Behaviour_obj > Behaviour_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< Behaviour_obj > result = new Behaviour_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic Behaviour_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Behaviour_obj > result = new Behaviour_obj();
	result->__construct(inArgs[0]);
	return result;}

bool Behaviour_obj::get_enabled( ){
	HX_STACK_FRAME("haxor.component.Behaviour","get_enabled",0xa9118a2a,"haxor.component.Behaviour.get_enabled","haxor/component/Behaviour.hx",19,0x6f707600)
	HX_STACK_THIS(this)
	HX_STACK_LINE(19)
	return (bool(this->m_enabled) && bool(!(this->m_destroyed)));
}


HX_DEFINE_DYNAMIC_FUNC0(Behaviour_obj,get_enabled,return )

bool Behaviour_obj::set_enabled( bool v){
	HX_STACK_FRAME("haxor.component.Behaviour","set_enabled",0xb37e9136,"haxor.component.Behaviour.set_enabled","haxor/component/Behaviour.hx",21,0x6f707600)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(22)
	if ((this->m_destroyed)){
		HX_STACK_LINE(22)
		return false;
	}
	HX_STACK_LINE(23)
	if (((this->m_enabled == v))){
		HX_STACK_LINE(23)
		return v;
	}
	HX_STACK_LINE(24)
	this->m_enabled = v;
	HX_STACK_LINE(25)
	if ((v)){
		HX_STACK_LINE(25)
		::haxor::context::EngineContext_obj::Enable(hx::ObjectPtr<OBJ_>(this));
	}
	else{
		HX_STACK_LINE(25)
		::haxor::context::EngineContext_obj::Disable(hx::ObjectPtr<OBJ_>(this));
	}
	HX_STACK_LINE(26)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Behaviour_obj,set_enabled,return )

Void Behaviour_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.Behaviour","OnBuild",0xce151601,"haxor.component.Behaviour.OnBuild","haxor/component/Behaviour.hx",44,0x6f707600)
		HX_STACK_THIS(this)
		HX_STACK_LINE(45)
		this->super::OnBuild();
		HX_STACK_LINE(46)
		this->m_enabled = true;
		HX_STACK_LINE(47)
		this->m_is_behaviour = true;
		HX_STACK_LINE(48)
		::haxor::context::EngineContext_obj::Enable(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


Void Behaviour_obj::OnAwake( ){
{
		HX_STACK_FRAME("haxor.component.Behaviour","OnAwake",0x3bfadbd8,"haxor.component.Behaviour.OnAwake","haxor/component/Behaviour.hx",54,0x6f707600)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Behaviour_obj,OnAwake,(void))

Void Behaviour_obj::OnStart( ){
{
		HX_STACK_FRAME("haxor.component.Behaviour","OnStart",0x9735af35,"haxor.component.Behaviour.OnStart","haxor/component/Behaviour.hx",59,0x6f707600)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Behaviour_obj,OnStart,(void))


Behaviour_obj::Behaviour_obj()
{
}

Dynamic Behaviour_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return get_enabled(); }
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
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
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Behaviour_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("enabled"));
	outFields->push(HX_CSTRING("m_enabled"));
	outFields->push(HX_CSTRING("m_is_awake"));
	outFields->push(HX_CSTRING("m_is_start"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Behaviour_obj,m_enabled),HX_CSTRING("m_enabled")},
	{hx::fsBool,(int)offsetof(Behaviour_obj,m_is_awake),HX_CSTRING("m_is_awake")},
	{hx::fsBool,(int)offsetof(Behaviour_obj,m_is_start),HX_CSTRING("m_is_start")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_enabled"),
	HX_CSTRING("set_enabled"),
	HX_CSTRING("m_enabled"),
	HX_CSTRING("m_is_awake"),
	HX_CSTRING("m_is_start"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("OnAwake"),
	HX_CSTRING("OnStart"),
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
