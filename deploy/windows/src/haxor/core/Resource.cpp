#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
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
#ifndef INCLUDED_haxor_core_Application
#include <haxor/core/Application.h>
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
#ifndef INCLUDED_haxor_platform_windows_WinApplication
#include <haxor/platform/windows/WinApplication.h>
#endif
namespace haxor{
namespace core{

Void Resource_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.core.Resource","new",0x26988423,"haxor.core.Resource.new","haxor/core/Resource.hx",88,0x735dd04d)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(89)
	int _g = (::haxor::context::EngineContext_obj::uid)++;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(89)
	this->m_uid = _g;
	HX_STACK_LINE(90)
	this->m_destroyed = false;
	HX_STACK_LINE(91)
	this->_cid_ = (int)0;
	HX_STACK_LINE(92)
	this->m_pid = Array_obj< int >::__new().Add((int)-1).Add((int)-1).Add((int)-1).Add((int)-1).Add((int)-1).Add((int)-1);
	HX_STACK_LINE(93)
	this->m_name = p_name;
	HX_STACK_LINE(95)
	bool _g1 = ::Std_obj::is(hx::ObjectPtr<OBJ_>(this),hx::ClassOf< ::haxor::component::Behaviour >());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(95)
	this->m_is_behaviour = _g1;
	HX_STACK_LINE(98)
	::Class _g2 = ::Type_obj::getClass(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(98)
	this->m_type_class = _g2;
	HX_STACK_LINE(99)
	::String _g3 = ::Type_obj::getClassName(this->m_type_class);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(99)
	this->m_type_full_name = _g3;
	HX_STACK_LINE(100)
	Array< ::String > nt = this->m_type_full_name.split(HX_CSTRING("."));		HX_STACK_VAR(nt,"nt");
	HX_STACK_LINE(100)
	nt->reverse();
	HX_STACK_LINE(101)
	this->m_type_name = nt->__get((int)0);
	HX_STACK_LINE(103)
	if (((p_name == HX_CSTRING("")))){
		HX_STACK_LINE(103)
		this->m_name = (this->m_type_name + this->m_uid);
	}
	else{
		HX_STACK_LINE(103)
		this->m_name = p_name;
	}
	HX_STACK_LINE(105)
	::haxor::context::EngineContext_obj::resources->Add(hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

//Resource_obj::~Resource_obj() { }

Dynamic Resource_obj::__CreateEmpty() { return  new Resource_obj; }
hx::ObjectPtr< Resource_obj > Resource_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< Resource_obj > result = new Resource_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic Resource_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Resource_obj > result = new Resource_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *Resource_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::haxor::core::IDisposable_obj)) return operator ::haxor::core::IDisposable_obj *();
	return super::__ToInterface(inType);
}

::haxor::core::Application Resource_obj::get_application( ){
	HX_STACK_FRAME("haxor.core.Resource","get_application",0x20c52f2a,"haxor.core.Resource.get_application","haxor/core/Resource.hx",26,0x735dd04d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(26)
	return ::haxor::core::BaseApplication_obj::m_instance;
}


HX_DEFINE_DYNAMIC_FUNC0(Resource_obj,get_application,return )

int Resource_obj::get_uid( ){
	HX_STACK_FRAME("haxor.core.Resource","get_uid",0xc00b3d6a,"haxor.core.Resource.get_uid","haxor/core/Resource.hx",33,0x735dd04d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(33)
	return this->m_uid;
}


HX_DEFINE_DYNAMIC_FUNC0(Resource_obj,get_uid,return )

::String Resource_obj::get_name( ){
	HX_STACK_FRAME("haxor.core.Resource","get_name",0x4523f731,"haxor.core.Resource.get_name","haxor/core/Resource.hx",40,0x735dd04d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(40)
	return this->m_name;
}


HX_DEFINE_DYNAMIC_FUNC0(Resource_obj,get_name,return )

::String Resource_obj::set_name( ::String v){
	HX_STACK_FRAME("haxor.core.Resource","set_name",0xf38150a5,"haxor.core.Resource.set_name","haxor/core/Resource.hx",41,0x735dd04d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(41)
	this->m_name = v;
	HX_STACK_LINE(41)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Resource_obj,set_name,return )

bool Resource_obj::get_destroyed( ){
	HX_STACK_FRAME("haxor.core.Resource","get_destroyed",0x87393133,"haxor.core.Resource.get_destroyed","haxor/core/Resource.hx",48,0x735dd04d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(48)
	return this->m_destroyed;
}


HX_DEFINE_DYNAMIC_FUNC0(Resource_obj,get_destroyed,return )

::Class Resource_obj::GetType( ){
	HX_STACK_FRAME("haxor.core.Resource","GetType",0x861a1b93,"haxor.core.Resource.GetType","haxor/core/Resource.hx",112,0x735dd04d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(112)
	return this->m_type_class;
}


HX_DEFINE_DYNAMIC_FUNC0(Resource_obj,GetType,return )

::String Resource_obj::GetTypeName( ){
	HX_STACK_FRAME("haxor.core.Resource","GetTypeName",0x44837f7e,"haxor.core.Resource.GetTypeName","haxor/core/Resource.hx",118,0x735dd04d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(118)
	return this->m_type_name;
}


HX_DEFINE_DYNAMIC_FUNC0(Resource_obj,GetTypeName,return )

::String Resource_obj::GetTypeFullName( ){
	HX_STACK_FRAME("haxor.core.Resource","GetTypeFullName",0xfd911e2d,"haxor.core.Resource.GetTypeFullName","haxor/core/Resource.hx",124,0x735dd04d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(124)
	return this->m_type_full_name;
}


HX_DEFINE_DYNAMIC_FUNC0(Resource_obj,GetTypeFullName,return )

Void Resource_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.core.Resource","OnDestroy",0xfe2a2d7e,"haxor.core.Resource.OnDestroy","haxor/core/Resource.hx",129,0x735dd04d)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Resource_obj,OnDestroy,(void))

Void Resource_obj::Destroy( ::haxor::core::Resource p_target){
{
		HX_STACK_FRAME("haxor.core.Resource","Destroy",0x8b14a61d,"haxor.core.Resource.Destroy","haxor/core/Resource.hx",19,0x735dd04d)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_LINE(19)
		::haxor::context::EngineContext_obj::Destroy(p_target);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Resource_obj,Destroy,(void))


Resource_obj::Resource_obj()
{
}

void Resource_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Resource);
	HX_MARK_MEMBER_NAME(application,"application");
	HX_MARK_MEMBER_NAME(uid,"uid");
	HX_MARK_MEMBER_NAME(m_uid,"m_uid");
	HX_MARK_MEMBER_NAME(m_name,"m_name");
	HX_MARK_MEMBER_NAME(destroyed,"destroyed");
	HX_MARK_MEMBER_NAME(m_destroyed,"m_destroyed");
	HX_MARK_MEMBER_NAME(_cid_,"_cid_");
	HX_MARK_MEMBER_NAME(m_pid,"m_pid");
	HX_MARK_MEMBER_NAME(m_type_name,"m_type_name");
	HX_MARK_MEMBER_NAME(m_type_full_name,"m_type_full_name");
	HX_MARK_MEMBER_NAME(m_type_class,"m_type_class");
	HX_MARK_MEMBER_NAME(m_is_behaviour,"m_is_behaviour");
	HX_MARK_END_CLASS();
}

void Resource_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(application,"application");
	HX_VISIT_MEMBER_NAME(uid,"uid");
	HX_VISIT_MEMBER_NAME(m_uid,"m_uid");
	HX_VISIT_MEMBER_NAME(m_name,"m_name");
	HX_VISIT_MEMBER_NAME(destroyed,"destroyed");
	HX_VISIT_MEMBER_NAME(m_destroyed,"m_destroyed");
	HX_VISIT_MEMBER_NAME(_cid_,"_cid_");
	HX_VISIT_MEMBER_NAME(m_pid,"m_pid");
	HX_VISIT_MEMBER_NAME(m_type_name,"m_type_name");
	HX_VISIT_MEMBER_NAME(m_type_full_name,"m_type_full_name");
	HX_VISIT_MEMBER_NAME(m_type_class,"m_type_class");
	HX_VISIT_MEMBER_NAME(m_is_behaviour,"m_is_behaviour");
}

Dynamic Resource_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"uid") ) { return inCallProp ? get_uid() : uid; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return get_name(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_uid") ) { return m_uid; }
		if (HX_FIELD_EQ(inName,"_cid_") ) { return _cid_; }
		if (HX_FIELD_EQ(inName,"m_pid") ) { return m_pid; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_name") ) { return m_name; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Destroy") ) { return Destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"get_uid") ) { return get_uid_dyn(); }
		if (HX_FIELD_EQ(inName,"GetType") ) { return GetType_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_name") ) { return get_name_dyn(); }
		if (HX_FIELD_EQ(inName,"set_name") ) { return set_name_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"destroyed") ) { return inCallProp ? get_destroyed() : destroyed; }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"application") ) { return inCallProp ? get_application() : application; }
		if (HX_FIELD_EQ(inName,"m_destroyed") ) { return m_destroyed; }
		if (HX_FIELD_EQ(inName,"m_type_name") ) { return m_type_name; }
		if (HX_FIELD_EQ(inName,"GetTypeName") ) { return GetTypeName_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_type_class") ) { return m_type_class; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_destroyed") ) { return get_destroyed_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_is_behaviour") ) { return m_is_behaviour; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_application") ) { return get_application_dyn(); }
		if (HX_FIELD_EQ(inName,"GetTypeFullName") ) { return GetTypeFullName_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_type_full_name") ) { return m_type_full_name; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Resource_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"uid") ) { uid=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return set_name(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_uid") ) { m_uid=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_cid_") ) { _cid_=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_pid") ) { m_pid=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_name") ) { m_name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"destroyed") ) { destroyed=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"application") ) { application=inValue.Cast< ::haxor::core::Application >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_destroyed") ) { m_destroyed=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_type_name") ) { m_type_name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_type_class") ) { m_type_class=inValue.Cast< ::Class >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_is_behaviour") ) { m_is_behaviour=inValue.Cast< bool >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_type_full_name") ) { m_type_full_name=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Resource_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("application"));
	outFields->push(HX_CSTRING("uid"));
	outFields->push(HX_CSTRING("m_uid"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("m_name"));
	outFields->push(HX_CSTRING("destroyed"));
	outFields->push(HX_CSTRING("m_destroyed"));
	outFields->push(HX_CSTRING("_cid_"));
	outFields->push(HX_CSTRING("m_pid"));
	outFields->push(HX_CSTRING("m_type_name"));
	outFields->push(HX_CSTRING("m_type_full_name"));
	outFields->push(HX_CSTRING("m_type_class"));
	outFields->push(HX_CSTRING("m_is_behaviour"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Destroy"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::core::Application*/ ,(int)offsetof(Resource_obj,application),HX_CSTRING("application")},
	{hx::fsInt,(int)offsetof(Resource_obj,uid),HX_CSTRING("uid")},
	{hx::fsInt,(int)offsetof(Resource_obj,m_uid),HX_CSTRING("m_uid")},
	{hx::fsString,(int)offsetof(Resource_obj,m_name),HX_CSTRING("m_name")},
	{hx::fsBool,(int)offsetof(Resource_obj,destroyed),HX_CSTRING("destroyed")},
	{hx::fsBool,(int)offsetof(Resource_obj,m_destroyed),HX_CSTRING("m_destroyed")},
	{hx::fsInt,(int)offsetof(Resource_obj,_cid_),HX_CSTRING("_cid_")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Resource_obj,m_pid),HX_CSTRING("m_pid")},
	{hx::fsString,(int)offsetof(Resource_obj,m_type_name),HX_CSTRING("m_type_name")},
	{hx::fsString,(int)offsetof(Resource_obj,m_type_full_name),HX_CSTRING("m_type_full_name")},
	{hx::fsObject /*::Class*/ ,(int)offsetof(Resource_obj,m_type_class),HX_CSTRING("m_type_class")},
	{hx::fsBool,(int)offsetof(Resource_obj,m_is_behaviour),HX_CSTRING("m_is_behaviour")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("application"),
	HX_CSTRING("get_application"),
	HX_CSTRING("uid"),
	HX_CSTRING("get_uid"),
	HX_CSTRING("m_uid"),
	HX_CSTRING("get_name"),
	HX_CSTRING("set_name"),
	HX_CSTRING("m_name"),
	HX_CSTRING("destroyed"),
	HX_CSTRING("get_destroyed"),
	HX_CSTRING("m_destroyed"),
	HX_CSTRING("_cid_"),
	HX_CSTRING("m_pid"),
	HX_CSTRING("m_type_name"),
	HX_CSTRING("m_type_full_name"),
	HX_CSTRING("m_type_class"),
	HX_CSTRING("m_is_behaviour"),
	HX_CSTRING("GetType"),
	HX_CSTRING("GetTypeName"),
	HX_CSTRING("GetTypeFullName"),
	HX_CSTRING("OnDestroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Resource_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Resource_obj::__mClass,"__mClass");
};

#endif

Class Resource_obj::__mClass;

void Resource_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.Resource"), hx::TCanCast< Resource_obj> ,sStaticFields,sMemberFields,
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

void Resource_obj::__boot()
{
}

} // end namespace haxor
} // end namespace core
