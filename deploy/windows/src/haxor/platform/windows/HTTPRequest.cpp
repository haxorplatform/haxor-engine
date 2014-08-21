#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
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
#ifndef INCLUDED_haxor_net_Web
#include <haxor/net/Web.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_HTTPRequest
#include <haxor/platform/windows/HTTPRequest.h>
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

Void HTTPRequest_obj::__construct(::String p_url,::String p_method,bool p_binary,::String p_data)
{
HX_STACK_FRAME("haxor.platform.windows.HTTPRequest","new",0x99f14a1f,"haxor.platform.windows.HTTPRequest.new","haxor/platform/windows/Web.hx",123,0x2cb2b125)
HX_STACK_THIS(this)
HX_STACK_ARG(p_url,"p_url")
HX_STACK_ARG(p_method,"p_method")
HX_STACK_ARG(p_binary,"p_binary")
HX_STACK_ARG(p_data,"p_data")
{
	HX_STACK_LINE(124)
	super::__construct(true,null());
	HX_STACK_LINE(125)
	int _g = p_url.indexOf(HX_CSTRING("./"),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(125)
	if (((_g >= (int)0))){
		HX_STACK_LINE(125)
		::String _g1 = ::StringTools_obj::replace(p_url,HX_CSTRING("./"),::haxor::net::Web_obj::root);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(125)
		p_url = _g1;
	}
	HX_STACK_LINE(126)
	this->url = p_url;
	HX_STACK_LINE(127)
	this->binary = p_binary;
	HX_STACK_LINE(128)
	::String _g2 = p_method.toUpperCase();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(128)
	this->method = _g2;
	HX_STACK_LINE(129)
	this->data = p_data;
	HX_STACK_LINE(130)
	this->bytesTotal = (int)0;
	HX_STACK_LINE(131)
	this->bytesLoaded = (int)0;
	HX_STACK_LINE(132)
	this->error = HX_CSTRING("");
	HX_STACK_LINE(133)
	::haxe::Http _g3 = ::haxe::Http_obj::__new(this->url);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(133)
	this->request = _g3;
	HX_STACK_LINE(134)
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

Void HTTPRequest_obj::OnStart( ){
{
		HX_STACK_FRAME("haxor.platform.windows.HTTPRequest","OnStart",0x8970ffe2,"haxor.platform.windows.HTTPRequest.OnStart","haxor/platform/windows/Web.hx",140,0x2cb2b125)
		HX_STACK_THIS(this)
	}
return null();
}


Void HTTPRequest_obj::OnStep( ){
{
		HX_STACK_FRAME("haxor.platform.windows.HTTPRequest","OnStep",0x230e4bcc,"haxor.platform.windows.HTTPRequest.OnStep","haxor/platform/windows/Web.hx",146,0x2cb2b125)
		HX_STACK_THIS(this)
		HX_STACK_LINE(145)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(147)
		if ((::haxor::platform::windows::HTTPRequest_obj::m_lock)){
			HX_STACK_LINE(147)
			return null();
		}
		HX_STACK_LINE(148)
		::haxor::platform::windows::HTTPRequest_obj::m_lock = true;
		HX_STACK_LINE(149)
		if ((!(this->m_loading))){
			HX_STACK_LINE(151)
			::haxor::core::Console_obj::Log((HX_CSTRING("HTTPRequest> ") + this->url),(int)4);
			HX_STACK_LINE(152)
			this->m_loading = true;

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_1,Array< ::Dynamic >,_g)
			Void run(::String err){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","haxor/platform/windows/Web.hx",153,0x2cb2b125)
				HX_STACK_ARG(err,"err")
				{
					HX_STACK_LINE(153)
					_g->__get((int)0).StaticCast< ::haxor::platform::windows::HTTPRequest >()->error = err;
					HX_STACK_LINE(153)
					_g->__get((int)0).StaticCast< ::haxor::platform::windows::HTTPRequest >()->OnError();
					HX_STACK_LINE(153)
					_g->__get((int)0).StaticCast< ::haxor::platform::windows::HTTPRequest >()->Cancel();
					HX_STACK_LINE(153)
					::haxor::platform::windows::HTTPRequest_obj::m_lock = false;
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(153)
			this->request->onError =  Dynamic(new _Function_2_1(_g));

			HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_2_2,Array< ::Dynamic >,_g)
			Void run(::String d){
				HX_STACK_FRAME("*","_Function_2_2",0x5201af79,"*._Function_2_2","haxor/platform/windows/Web.hx",155,0x2cb2b125)
				HX_STACK_ARG(d,"d")
				{
					HX_STACK_LINE(156)
					_g->__get((int)0).StaticCast< ::haxor::platform::windows::HTTPRequest >()->response = d;
					HX_STACK_LINE(157)
					_g->__get((int)0).StaticCast< ::haxor::platform::windows::HTTPRequest >()->set_progress(1.0);
					HX_STACK_LINE(158)
					::haxor::platform::windows::HTTPRequest_obj::m_lock = false;
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(154)
			this->request->onData =  Dynamic(new _Function_2_2(_g));

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_2_3)
			Void run(int n){
				HX_STACK_FRAME("*","_Function_2_3",0x5201af7a,"*._Function_2_3","haxor/platform/windows/Web.hx",160,0x2cb2b125)
				HX_STACK_ARG(n,"n")
				{
				}
				return null();
			}
			HX_END_LOCAL_FUNC1((void))

			HX_STACK_LINE(160)
			this->request->onStatus =  Dynamic(new _Function_2_3());
			HX_STACK_LINE(161)
			this->request->request((this->method == HX_CSTRING("POST")));
		}
	}
return null();
}


Void HTTPRequest_obj::OnComplete( ){
{
		HX_STACK_FRAME("haxor.platform.windows.HTTPRequest","OnComplete",0x5cc6a539,"haxor.platform.windows.HTTPRequest.OnComplete","haxor/platform/windows/Web.hx",168,0x2cb2b125)
		HX_STACK_THIS(this)
	}
return null();
}


Void HTTPRequest_obj::OnError( ){
{
		HX_STACK_FRAME("haxor.platform.windows.HTTPRequest","OnError",0x788f5748,"haxor.platform.windows.HTTPRequest.OnError","haxor/platform/windows/Web.hx",175,0x2cb2b125)
		HX_STACK_THIS(this)
		HX_STACK_LINE(175)
		::haxor::core::Console_obj::Log(((HX_CSTRING("HTTPRequest> Error [") + this->error) + HX_CSTRING("]")),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTTPRequest_obj,OnError,(void))

bool HTTPRequest_obj::m_lock;


HTTPRequest_obj::HTTPRequest_obj()
{
}

void HTTPRequest_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTTPRequest);
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_MEMBER_NAME(binary,"binary");
	HX_MARK_MEMBER_NAME(request,"request");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(method,"method");
	HX_MARK_MEMBER_NAME(response,"response");
	HX_MARK_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	HX_MARK_MEMBER_NAME(bytesTotal,"bytesTotal");
	HX_MARK_MEMBER_NAME(error,"error");
	HX_MARK_MEMBER_NAME(m_loading,"m_loading");
	::haxor::thread::Activity_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTTPRequest_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(url,"url");
	HX_VISIT_MEMBER_NAME(binary,"binary");
	HX_VISIT_MEMBER_NAME(request,"request");
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(method,"method");
	HX_VISIT_MEMBER_NAME(response,"response");
	HX_VISIT_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	HX_VISIT_MEMBER_NAME(bytesTotal,"bytesTotal");
	HX_VISIT_MEMBER_NAME(error,"error");
	HX_VISIT_MEMBER_NAME(m_loading,"m_loading");
	::haxor::thread::Activity_obj::__Visit(HX_VISIT_ARG);
}

Dynamic HTTPRequest_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"error") ) { return error; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_lock") ) { return m_lock; }
		if (HX_FIELD_EQ(inName,"binary") ) { return binary; }
		if (HX_FIELD_EQ(inName,"method") ) { return method; }
		if (HX_FIELD_EQ(inName,"OnStep") ) { return OnStep_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"request") ) { return request; }
		if (HX_FIELD_EQ(inName,"OnStart") ) { return OnStart_dyn(); }
		if (HX_FIELD_EQ(inName,"OnError") ) { return OnError_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"response") ) { return response; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_loading") ) { return m_loading; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { return bytesTotal; }
		if (HX_FIELD_EQ(inName,"OnComplete") ) { return OnComplete_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { return bytesLoaded; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTTPRequest_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"error") ) { error=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_lock") ) { m_lock=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"binary") ) { binary=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"method") ) { method=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"request") ) { request=inValue.Cast< ::haxe::Http >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"response") ) { response=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_loading") ) { m_loading=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { bytesTotal=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { bytesLoaded=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTTPRequest_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("url"));
	outFields->push(HX_CSTRING("binary"));
	outFields->push(HX_CSTRING("request"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("method"));
	outFields->push(HX_CSTRING("response"));
	outFields->push(HX_CSTRING("bytesLoaded"));
	outFields->push(HX_CSTRING("bytesTotal"));
	outFields->push(HX_CSTRING("error"));
	outFields->push(HX_CSTRING("m_loading"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_lock"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(HTTPRequest_obj,url),HX_CSTRING("url")},
	{hx::fsBool,(int)offsetof(HTTPRequest_obj,binary),HX_CSTRING("binary")},
	{hx::fsObject /*::haxe::Http*/ ,(int)offsetof(HTTPRequest_obj,request),HX_CSTRING("request")},
	{hx::fsString,(int)offsetof(HTTPRequest_obj,data),HX_CSTRING("data")},
	{hx::fsString,(int)offsetof(HTTPRequest_obj,method),HX_CSTRING("method")},
	{hx::fsString,(int)offsetof(HTTPRequest_obj,response),HX_CSTRING("response")},
	{hx::fsInt,(int)offsetof(HTTPRequest_obj,bytesLoaded),HX_CSTRING("bytesLoaded")},
	{hx::fsInt,(int)offsetof(HTTPRequest_obj,bytesTotal),HX_CSTRING("bytesTotal")},
	{hx::fsString,(int)offsetof(HTTPRequest_obj,error),HX_CSTRING("error")},
	{hx::fsBool,(int)offsetof(HTTPRequest_obj,m_loading),HX_CSTRING("m_loading")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("url"),
	HX_CSTRING("binary"),
	HX_CSTRING("request"),
	HX_CSTRING("data"),
	HX_CSTRING("method"),
	HX_CSTRING("response"),
	HX_CSTRING("bytesLoaded"),
	HX_CSTRING("bytesTotal"),
	HX_CSTRING("error"),
	HX_CSTRING("m_loading"),
	HX_CSTRING("OnStart"),
	HX_CSTRING("OnStep"),
	HX_CSTRING("OnComplete"),
	HX_CSTRING("OnError"),
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
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.windows.HTTPRequest"), hx::TCanCast< HTTPRequest_obj> ,sStaticFields,sMemberFields,
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
