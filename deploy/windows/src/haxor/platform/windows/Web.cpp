#include <hxcpp.h>

#ifndef INCLUDED_cpp_vm_Thread
#include <cpp/vm/Thread.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_LoadTask
#include <haxor/platform/windows/LoadTask.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_Web
#include <haxor/platform/windows/Web.h>
#endif
namespace haxor{
namespace platform{
namespace windows{

Void Web_obj::__construct()
{
	return null();
}

//Web_obj::~Web_obj() { }

Dynamic Web_obj::__CreateEmpty() { return  new Web_obj; }
hx::ObjectPtr< Web_obj > Web_obj::__new()
{  hx::ObjectPtr< Web_obj > result = new Web_obj();
	result->__construct();
	return result;}

Dynamic Web_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Web_obj > result = new Web_obj();
	result->__construct();
	return result;}

::String Web_obj::root;

bool Web_obj::m_running;

Array< ::Dynamic > Web_obj::q;

Void Web_obj::Load( ::String p_url,Dynamic p_callback){
{
		HX_STACK_FRAME("haxor.platform.windows.Web","Load",0x7de2eaba,"haxor.platform.windows.Web.Load","haxor/platform/windows/Web.hx",33,0x2cb2b125)
		HX_STACK_ARG(p_url,"p_url")
		HX_STACK_ARG(p_callback,"p_callback")
		HX_STACK_LINE(33)
		Dynamic p_callback1 = Dynamic( Array_obj<Dynamic>::__new().Add(p_callback));		HX_STACK_VAR(p_callback1,"p_callback1");
		HX_STACK_LINE(35)
		if (((::haxor::platform::windows::Web_obj::q == null()))){
			HX_STACK_LINE(35)
			::haxor::platform::windows::Web_obj::q = Array_obj< ::Dynamic >::__new();
		}
		HX_STACK_LINE(36)
		p_callback1->__GetItem((int)0)(null(),0.0).Cast< Void >();

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Dynamic,p_callback1)
		Void run(::String d){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/platform/windows/Web.hx",39,0x2cb2b125)
			HX_STACK_ARG(d,"d")
			{
				HX_STACK_LINE(39)
				p_callback1->__GetItem((int)0)(d,1.0).Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))


		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_2,Dynamic,p_callback1)
		Void run(::String err){
			HX_STACK_FRAME("*","_Function_1_2",0x5200ed38,"*._Function_1_2","haxor/platform/windows/Web.hx",44,0x2cb2b125)
			HX_STACK_ARG(err,"err")
			{
				HX_STACK_LINE(44)
				p_callback1->__GetItem((int)0)(null(),1.0).Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(37)
		::haxor::platform::windows::LoadTask ld = ::haxor::platform::windows::LoadTask_obj::__new(p_url,HX_CSTRING("GET"),HX_CSTRING(""), Dynamic(new _Function_1_1(p_callback1)), Dynamic(new _Function_1_2(p_callback1)));		HX_STACK_VAR(ld,"ld");
		HX_STACK_LINE(46)
		::haxor::platform::windows::Web_obj::q->push(ld);
		HX_STACK_LINE(47)
		if ((!(::haxor::platform::windows::Web_obj::m_running))){
			HX_STACK_LINE(47)
			::cpp::vm::Thread_obj::create(::haxor::platform::windows::Web_obj::QueueUpdate_dyn());
			HX_STACK_LINE(47)
			::haxor::platform::windows::Web_obj::m_running = true;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Web_obj,Load,(void))

Void Web_obj::QueueUpdate( ){
{
		HX_STACK_FRAME("haxor.platform.windows.Web","QueueUpdate",0xcf1d3466,"haxor.platform.windows.Web.QueueUpdate","haxor/platform/windows/Web.hx",51,0x2cb2b125)
		HX_STACK_LINE(52)
		while((true)){
			HX_STACK_LINE(52)
			if ((!(((::haxor::platform::windows::Web_obj::q->length > (int)0))))){
				HX_STACK_LINE(52)
				break;
			}
			HX_STACK_LINE(54)
			::haxor::platform::windows::LoadTask ld = ::haxor::platform::windows::Web_obj::q->shift().StaticCast< ::haxor::platform::windows::LoadTask >();		HX_STACK_VAR(ld,"ld");
			HX_STACK_LINE(55)
			ld->Run();
		}
		HX_STACK_LINE(57)
		::haxor::platform::windows::Web_obj::m_running = false;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Web_obj,QueueUpdate,(void))


Web_obj::Web_obj()
{
}

Dynamic Web_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"q") ) { return q; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"root") ) { return root; }
		if (HX_FIELD_EQ(inName,"Load") ) { return Load_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_running") ) { return m_running; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"QueueUpdate") ) { return QueueUpdate_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Web_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"q") ) { q=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"root") ) { root=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_running") ) { m_running=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Web_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("root"),
	HX_CSTRING("m_running"),
	HX_CSTRING("q"),
	HX_CSTRING("Load"),
	HX_CSTRING("QueueUpdate"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Web_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Web_obj::root,"root");
	HX_MARK_MEMBER_NAME(Web_obj::m_running,"m_running");
	HX_MARK_MEMBER_NAME(Web_obj::q,"q");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Web_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Web_obj::root,"root");
	HX_VISIT_MEMBER_NAME(Web_obj::m_running,"m_running");
	HX_VISIT_MEMBER_NAME(Web_obj::q,"q");
};

#endif

Class Web_obj::__mClass;

void Web_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.windows.Web"), hx::TCanCast< Web_obj> ,sStaticFields,sMemberFields,
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

void Web_obj::__boot()
{
	root= HX_CSTRING("");
	m_running= false;
}

} // end namespace haxor
} // end namespace platform
} // end namespace windows
