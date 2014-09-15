#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IRenderable
#include <haxor/core/IRenderable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_thread_Activity
#include <haxor/thread/Activity.h>
#endif
#ifndef INCLUDED_haxor_thread_Task
#include <haxor/thread/Task.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace thread{

Void Task_obj::__construct(hx::Null< bool >  __o_p_threaded,Dynamic p_callback)
{
HX_STACK_FRAME("haxor.thread.Task","new",0x19b55acf,"haxor.thread.Task.new","haxor/thread/Task.hx",33,0x512a4561)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_threaded,"p_threaded")
HX_STACK_ARG(p_callback,"p_callback")
bool p_threaded = __o_p_threaded.Default(false);
{
	HX_STACK_LINE(34)
	Dynamic cb = p_callback;		HX_STACK_VAR(cb,"cb");
	HX_STACK_LINE(35)
	if (((cb == null()))){
		HX_STACK_LINE(35)
		cb = this->OnExecute_dyn();
	}
	HX_STACK_LINE(36)
	super::__construct(cb,p_threaded,null());
	HX_STACK_LINE(37)
	this->m_active = false;
	HX_STACK_LINE(38)
	this->m_progress = 0.0;
	HX_STACK_LINE(39)
	this->m_has_progress = false;
}
;
	return null();
}

//Task_obj::~Task_obj() { }

Dynamic Task_obj::__CreateEmpty() { return  new Task_obj; }
hx::ObjectPtr< Task_obj > Task_obj::__new(hx::Null< bool >  __o_p_threaded,Dynamic p_callback)
{  hx::ObjectPtr< Task_obj > result = new Task_obj();
	result->__construct(__o_p_threaded,p_callback);
	return result;}

Dynamic Task_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Task_obj > result = new Task_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Float Task_obj::get_progress( ){
	HX_STACK_FRAME("haxor.thread.Task","get_progress",0xf2abdb67,"haxor.thread.Task.get_progress","haxor/thread/Task.hx",16,0x512a4561)
	HX_STACK_THIS(this)
	HX_STACK_LINE(16)
	return this->m_progress;
}


HX_DEFINE_DYNAMIC_FUNC0(Task_obj,get_progress,return )

Float Task_obj::set_progress( Float v){
	HX_STACK_FRAME("haxor.thread.Task","set_progress",0x07a4fedb,"haxor.thread.Task.set_progress","haxor/thread/Task.hx",17,0x512a4561)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(17)
	Float _g = ::Math_obj::abs((v - this->m_progress));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(17)
	if (((_g > 0.0))){
		HX_STACK_LINE(17)
		this->m_progress = v;
		HX_STACK_LINE(17)
		this->m_has_progress = true;
	}
	HX_STACK_LINE(17)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Task_obj,set_progress,return )

bool Task_obj::get_active( ){
	HX_STACK_FRAME("haxor.thread.Task","get_active",0x49f0e300,"haxor.thread.Task.get_active","haxor/thread/Task.hx",25,0x512a4561)
	HX_STACK_THIS(this)
	HX_STACK_LINE(25)
	return this->m_active;
}


HX_DEFINE_DYNAMIC_FUNC0(Task_obj,get_active,return )

Void Task_obj::OnStart( ){
{
		HX_STACK_FRAME("haxor.thread.Task","OnStart",0xfb032892,"haxor.thread.Task.OnStart","haxor/thread/Task.hx",45,0x512a4561)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Task_obj,OnStart,(void))

Void Task_obj::OnStep( ){
{
		HX_STACK_FRAME("haxor.thread.Task","OnStep",0xdd89c91c,"haxor.thread.Task.OnStep","haxor/thread/Task.hx",50,0x512a4561)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Task_obj,OnStep,(void))

Void Task_obj::OnComplete( ){
{
		HX_STACK_FRAME("haxor.thread.Task","OnComplete",0x97530a89,"haxor.thread.Task.OnComplete","haxor/thread/Task.hx",55,0x512a4561)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Task_obj,OnComplete,(void))

Void Task_obj::OnProgress( ){
{
		HX_STACK_FRAME("haxor.thread.Task","OnProgress",0x9db6017d,"haxor.thread.Task.OnProgress","haxor/thread/Task.hx",60,0x512a4561)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Task_obj,OnProgress,(void))

bool Task_obj::OnExecute( Float p_time){
	HX_STACK_FRAME("haxor.thread.Task","OnExecute",0xb77e2a65,"haxor.thread.Task.OnExecute","haxor/thread/Task.hx",68,0x512a4561)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_time,"p_time")
	HX_STACK_LINE(69)
	if ((!(this->m_active))){
		HX_STACK_LINE(69)
		this->m_active = true;
		HX_STACK_LINE(69)
		this->OnStart();
	}
	HX_STACK_LINE(70)
	this->OnStep();
	HX_STACK_LINE(71)
	if ((this->m_has_progress)){
		HX_STACK_LINE(71)
		this->OnProgress();
		HX_STACK_LINE(71)
		this->m_has_progress = false;
	}
	HX_STACK_LINE(72)
	if (((this->m_progress >= 1.0))){
		HX_STACK_LINE(72)
		this->OnComplete();
		HX_STACK_LINE(72)
		return false;
	}
	HX_STACK_LINE(73)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(Task_obj,OnExecute,return )


Task_obj::Task_obj()
{
}

Dynamic Task_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { return inCallProp ? get_active() : active; }
		if (HX_FIELD_EQ(inName,"OnStep") ) { return OnStep_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"OnStart") ) { return OnStart_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"progress") ) { return get_progress(); }
		if (HX_FIELD_EQ(inName,"m_active") ) { return m_active; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"OnExecute") ) { return OnExecute_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_progress") ) { return m_progress; }
		if (HX_FIELD_EQ(inName,"get_active") ) { return get_active_dyn(); }
		if (HX_FIELD_EQ(inName,"OnComplete") ) { return OnComplete_dyn(); }
		if (HX_FIELD_EQ(inName,"OnProgress") ) { return OnProgress_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_progress") ) { return get_progress_dyn(); }
		if (HX_FIELD_EQ(inName,"set_progress") ) { return set_progress_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_has_progress") ) { return m_has_progress; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Task_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"progress") ) { return set_progress(inValue); }
		if (HX_FIELD_EQ(inName,"m_active") ) { m_active=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_progress") ) { m_progress=inValue.Cast< Float >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_has_progress") ) { m_has_progress=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Task_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("progress"));
	outFields->push(HX_CSTRING("m_progress"));
	outFields->push(HX_CSTRING("m_has_progress"));
	outFields->push(HX_CSTRING("active"));
	outFields->push(HX_CSTRING("m_active"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(Task_obj,m_progress),HX_CSTRING("m_progress")},
	{hx::fsBool,(int)offsetof(Task_obj,m_has_progress),HX_CSTRING("m_has_progress")},
	{hx::fsBool,(int)offsetof(Task_obj,active),HX_CSTRING("active")},
	{hx::fsBool,(int)offsetof(Task_obj,m_active),HX_CSTRING("m_active")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_progress"),
	HX_CSTRING("set_progress"),
	HX_CSTRING("m_progress"),
	HX_CSTRING("m_has_progress"),
	HX_CSTRING("active"),
	HX_CSTRING("get_active"),
	HX_CSTRING("m_active"),
	HX_CSTRING("OnStart"),
	HX_CSTRING("OnStep"),
	HX_CSTRING("OnComplete"),
	HX_CSTRING("OnProgress"),
	HX_CSTRING("OnExecute"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Task_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Task_obj::__mClass,"__mClass");
};

#endif

Class Task_obj::__mClass;

void Task_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.thread.Task"), hx::TCanCast< Task_obj> ,sStaticFields,sMemberFields,
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

void Task_obj::__boot()
{
}

} // end namespace haxor
} // end namespace thread
