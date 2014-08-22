#include <hxcpp.h>

#ifndef INCLUDED_haxe_Http
#include <haxe/Http.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
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
#ifndef INCLUDED_haxor_net_HTTPRequestTask
#include <haxor/net/HTTPRequestTask.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_net_HTTPRequest
#include <haxor/platform/windows/net/HTTPRequest.h>
#endif
#ifndef INCLUDED_haxor_thread_Activity
#include <haxor/thread/Activity.h>
#endif
#ifndef INCLUDED_haxor_thread_Task
#include <haxor/thread/Task.h>
#endif
namespace haxor{
namespace platform{
namespace windows{
namespace net{

Void HTTPRequest_obj::__construct(::String p_url,::String p_method,bool p_binary,::String p_data)
{
HX_STACK_FRAME("haxor.platform.windows.net.HTTPRequest","new",0xf97dc30e,"haxor.platform.windows.net.HTTPRequest.new","haxor/platform/windows/net/HTTPRequest.hx",31,0x83d55c04)
HX_STACK_THIS(this)
HX_STACK_ARG(p_url,"p_url")
HX_STACK_ARG(p_method,"p_method")
HX_STACK_ARG(p_binary,"p_binary")
HX_STACK_ARG(p_data,"p_data")
{
	HX_STACK_LINE(32)
	super::__construct(p_url,p_method,p_binary,p_data);
	HX_STACK_LINE(33)
	::haxe::Http _g = ::haxe::Http_obj::__new(this->url);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(33)
	this->request = _g;
	HX_STACK_LINE(34)
	this->m_loading = false;
}
;
	return null();
}

//HTTPRequest_obj::~HTTPRequest_obj() { }

Dynamic HTTPRequest_obj::__CreateEmpty() { return  new HTTPRequest_obj; }
hx::ObjectPtr< HTTPRequest_obj > HTTPRequest_obj::__new(::String p_url,::String p_method,bool p_binary,::String p_data)
{  hx::ObjectPtr< HTTPRequest_obj > result = new HTTPRequest_obj();
	result->__construct(p_url,p_method,p_binary,p_data);
	return result;}

Dynamic HTTPRequest_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTTPRequest_obj > result = new HTTPRequest_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void HTTPRequest_obj::OnStep( ){
{
		HX_STACK_FRAME("haxor.platform.windows.net.HTTPRequest","OnStep",0xf296d23d,"haxor.platform.windows.net.HTTPRequest.OnStep","haxor/platform/windows/net/HTTPRequest.hx",41,0x83d55c04)
		HX_STACK_THIS(this)
		HX_STACK_LINE(40)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(42)
		if ((::haxor::platform::windows::net::HTTPRequest_obj::m_lock)){
			HX_STACK_LINE(42)
			return null();
		}
		HX_STACK_LINE(43)
		::haxor::platform::windows::net::HTTPRequest_obj::m_lock = true;
		HX_STACK_LINE(44)
		if ((!(this->m_loading))){
			HX_STACK_LINE(46)
			::haxor::core::Console_obj::Log((HX_CSTRING("HTTPRequest> ") + this->url),(int)4);
			HX_STACK_LINE(47)
			this->m_loading = true;

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::Dynamic >,_g)
			Void run(::String err){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","haxor/platform/windows/net/HTTPRequest.hx",48,0x83d55c04)
				HX_STACK_ARG(err,"err")
				{
					HX_STACK_LINE(48)
					_g->__get((int)0).StaticCast< ::haxor::platform::windows::net::HTTPRequest >()->error = err;
					HX_STACK_LINE(48)
					_g->__get((int)0).StaticCast< ::haxor::platform::windows::net::HTTPRequest >()->OnError();
					HX_STACK_LINE(48)
					_g->__get((int)0).StaticCast< ::haxor::platform::windows::net::HTTPRequest >()->Cancel();
					HX_STACK_LINE(48)
					::haxor::platform::windows::net::HTTPRequest_obj::m_lock = false;
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(48)
			this->request->__FieldRef(HX_CSTRING("onError")) =  Dynamic(new _Function_2_1(_g));

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_2,Array< ::Dynamic >,_g)
			Void run(::String d){
				HX_STACK_FRAME("*","_Function_2_2",0x5201af79,"*._Function_2_2","haxor/platform/windows/net/HTTPRequest.hx",50,0x83d55c04)
				HX_STACK_ARG(d,"d")
				{
					HX_STACK_LINE(51)
					_g->__get((int)0).StaticCast< ::haxor::platform::windows::net::HTTPRequest >()->response = d;
					HX_STACK_LINE(52)
					_g->__get((int)0).StaticCast< ::haxor::platform::windows::net::HTTPRequest >()->set_progress(1.0);
					HX_STACK_LINE(53)
					::haxor::platform::windows::net::HTTPRequest_obj::m_lock = false;
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(49)
			this->request->__FieldRef(HX_CSTRING("onData")) =  Dynamic(new _Function_2_2(_g));

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_2_3)
			Void run(int n){
				HX_STACK_FRAME("*","_Function_2_3",0x5201af7a,"*._Function_2_3","haxor/platform/windows/net/HTTPRequest.hx",55,0x83d55c04)
				HX_STACK_ARG(n,"n")
				{
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(55)
			this->request->__FieldRef(HX_CSTRING("onStatus")) =  Dynamic(new _Function_2_3());
			HX_STACK_LINE(56)
			this->request->__Field(HX_CSTRING("request"),true)((this->method == HX_CSTRING("POST")));
		}
	}
return null();
}


bool HTTPRequest_obj::m_lock;


HTTPRequest_obj::HTTPRequest_obj()
{
}

Dynamic HTTPRequest_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_lock") ) { return m_lock; }
		if (HX_FIELD_EQ(inName,"OnStep") ) { return OnStep_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_loading") ) { return m_loading; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTTPRequest_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"m_lock") ) { m_lock=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_loading") ) { m_loading=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTTPRequest_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_loading"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_lock"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(HTTPRequest_obj,m_loading),HX_CSTRING("m_loading")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("m_loading"),
	HX_CSTRING("OnStep"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTTPRequest_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(HTTPRequest_obj::m_lock,"m_lock");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTTPRequest_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(HTTPRequest_obj::m_lock,"m_lock");
};

#endif

Class HTTPRequest_obj::__mClass;

void HTTPRequest_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.windows.net.HTTPRequest"), hx::TCanCast< HTTPRequest_obj> ,sStaticFields,sMemberFields,
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

void HTTPRequest_obj::__boot()
{
	m_lock= false;
}

} // end namespace haxor
} // end namespace platform
} // end namespace windows
} // end namespace net
