#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
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
#ifndef INCLUDED_haxor_net_Web
#include <haxor/net/Web.h>
#endif
#ifndef INCLUDED_haxor_thread_Activity
#include <haxor/thread/Activity.h>
#endif
#ifndef INCLUDED_haxor_thread_Task
#include <haxor/thread/Task.h>
#endif
namespace haxor{
namespace net{

Void HTTPRequestTask_obj::__construct(::String p_url,::String p_method,bool p_binary,Dynamic p_data)
{
HX_STACK_FRAME("haxor.net.HTTPRequestTask","new",0x48fd59c1,"haxor.net.HTTPRequestTask.new","haxor/net/HTTPRequestTask.hx",62,0x1884b5d1)
HX_STACK_THIS(this)
HX_STACK_ARG(p_url,"p_url")
HX_STACK_ARG(p_method,"p_method")
HX_STACK_ARG(p_binary,"p_binary")
HX_STACK_ARG(p_data,"p_data")
{
	HX_STACK_LINE(63)
	super::__construct(null(),null());
	HX_STACK_LINE(64)
	int _g = p_url.indexOf(HX_CSTRING("./"),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(64)
	if (((_g >= (int)0))){
		HX_STACK_LINE(64)
		::String _g1 = ::StringTools_obj::replace(p_url,HX_CSTRING("./"),::haxor::net::Web_obj::root);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(64)
		p_url = _g1;
	}
	HX_STACK_LINE(65)
	this->url = p_url;
	HX_STACK_LINE(66)
	this->binary = p_binary;
	HX_STACK_LINE(67)
	this->method = p_method;
	HX_STACK_LINE(68)
	this->data = p_data;
	HX_STACK_LINE(69)
	this->bytesLoaded = (int)0;
	HX_STACK_LINE(70)
	this->bytesTotal = (int)0;
	HX_STACK_LINE(71)
	this->error = HX_CSTRING("");
	HX_STACK_LINE(72)
	::haxor::core::Console_obj::Log((HX_CSTRING("HTTPRequest> ") + this->url),(int)6);
}
;
	return null();
}

//HTTPRequestTask_obj::~HTTPRequestTask_obj() { }

Dynamic HTTPRequestTask_obj::__CreateEmpty() { return  new HTTPRequestTask_obj; }
hx::ObjectPtr< HTTPRequestTask_obj > HTTPRequestTask_obj::__new(::String p_url,::String p_method,bool p_binary,Dynamic p_data)
{  hx::ObjectPtr< HTTPRequestTask_obj > result = new HTTPRequestTask_obj();
	result->__construct(p_url,p_method,p_binary,p_data);
	return result;}

Dynamic HTTPRequestTask_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTTPRequestTask_obj > result = new HTTPRequestTask_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void HTTPRequestTask_obj::OnStart( ){
{
		HX_STACK_FRAME("haxor.net.HTTPRequestTask","OnStart",0xf81a8884,"haxor.net.HTTPRequestTask.OnStart","haxor/net/HTTPRequestTask.hx",78,0x1884b5d1)
		HX_STACK_THIS(this)
	}
return null();
}


Void HTTPRequestTask_obj::OnError( ){
{
		HX_STACK_FRAME("haxor.net.HTTPRequestTask","OnError",0xe738dfea,"haxor.net.HTTPRequestTask.OnError","haxor/net/HTTPRequestTask.hx",83,0x1884b5d1)
		HX_STACK_THIS(this)
		HX_STACK_LINE(83)
		::haxor::core::Console_obj::LogError(((HX_CSTRING("HTTPRequest> Error [") + this->error) + HX_CSTRING("]")),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(HTTPRequestTask_obj,OnError,(void))


HTTPRequestTask_obj::HTTPRequestTask_obj()
{
}

void HTTPRequestTask_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTTPRequestTask);
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_MEMBER_NAME(request,"request");
	HX_MARK_MEMBER_NAME(response,"response");
	HX_MARK_MEMBER_NAME(binary,"binary");
	HX_MARK_MEMBER_NAME(method,"method");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	HX_MARK_MEMBER_NAME(bytesTotal,"bytesTotal");
	HX_MARK_MEMBER_NAME(error,"error");
	::haxor::thread::Activity_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTTPRequestTask_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(url,"url");
	HX_VISIT_MEMBER_NAME(request,"request");
	HX_VISIT_MEMBER_NAME(response,"response");
	HX_VISIT_MEMBER_NAME(binary,"binary");
	HX_VISIT_MEMBER_NAME(method,"method");
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	HX_VISIT_MEMBER_NAME(bytesTotal,"bytesTotal");
	HX_VISIT_MEMBER_NAME(error,"error");
	::haxor::thread::Activity_obj::__Visit(HX_VISIT_ARG);
}

Dynamic HTTPRequestTask_obj::__Field(const ::String &inName,bool inCallProp)
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
		if (HX_FIELD_EQ(inName,"binary") ) { return binary; }
		if (HX_FIELD_EQ(inName,"method") ) { return method; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"request") ) { return request; }
		if (HX_FIELD_EQ(inName,"OnStart") ) { return OnStart_dyn(); }
		if (HX_FIELD_EQ(inName,"OnError") ) { return OnError_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"response") ) { return response; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { return bytesTotal; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { return bytesLoaded; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTTPRequestTask_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"error") ) { error=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"binary") ) { binary=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"method") ) { method=inValue.Cast< ::String >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"request") ) { request=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"response") ) { response=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { bytesTotal=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { bytesLoaded=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTTPRequestTask_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("url"));
	outFields->push(HX_CSTRING("request"));
	outFields->push(HX_CSTRING("response"));
	outFields->push(HX_CSTRING("binary"));
	outFields->push(HX_CSTRING("method"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("bytesLoaded"));
	outFields->push(HX_CSTRING("bytesTotal"));
	outFields->push(HX_CSTRING("error"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(HTTPRequestTask_obj,url),HX_CSTRING("url")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(HTTPRequestTask_obj,request),HX_CSTRING("request")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(HTTPRequestTask_obj,response),HX_CSTRING("response")},
	{hx::fsBool,(int)offsetof(HTTPRequestTask_obj,binary),HX_CSTRING("binary")},
	{hx::fsString,(int)offsetof(HTTPRequestTask_obj,method),HX_CSTRING("method")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(HTTPRequestTask_obj,data),HX_CSTRING("data")},
	{hx::fsInt,(int)offsetof(HTTPRequestTask_obj,bytesLoaded),HX_CSTRING("bytesLoaded")},
	{hx::fsInt,(int)offsetof(HTTPRequestTask_obj,bytesTotal),HX_CSTRING("bytesTotal")},
	{hx::fsString,(int)offsetof(HTTPRequestTask_obj,error),HX_CSTRING("error")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("url"),
	HX_CSTRING("request"),
	HX_CSTRING("response"),
	HX_CSTRING("binary"),
	HX_CSTRING("method"),
	HX_CSTRING("data"),
	HX_CSTRING("bytesLoaded"),
	HX_CSTRING("bytesTotal"),
	HX_CSTRING("error"),
	HX_CSTRING("OnStart"),
	HX_CSTRING("OnError"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTTPRequestTask_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTTPRequestTask_obj::__mClass,"__mClass");
};

#endif

Class HTTPRequestTask_obj::__mClass;

void HTTPRequestTask_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.net.HTTPRequestTask"), hx::TCanCast< HTTPRequestTask_obj> ,sStaticFields,sMemberFields,
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

void HTTPRequestTask_obj::__boot()
{
}

} // end namespace haxor
} // end namespace net
