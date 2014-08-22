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
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_net_HTTPRequestTask
#include <haxor/net/HTTPRequestTask.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_net_HTTPLoader
#include <haxor/platform/windows/net/HTTPLoader.h>
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

Void HTTPLoader_obj::__construct(::String p_url,bool p_binary,Dynamic p_callback)
{
HX_STACK_FRAME("haxor.platform.windows.net.HTTPLoader","new",0xd20427d8,"haxor.platform.windows.net.HTTPLoader.new","haxor/platform/windows/net/HTTPLoader.hx",23,0x6e62a8f6)
HX_STACK_THIS(this)
HX_STACK_ARG(p_url,"p_url")
HX_STACK_ARG(p_binary,"p_binary")
HX_STACK_ARG(p_callback,"p_callback")
{
	HX_STACK_LINE(24)
	super::__construct(p_url,HX_CSTRING("GET"),p_binary,null());
	HX_STACK_LINE(25)
	this->callback = p_callback;
}
;
	return null();
}

//HTTPLoader_obj::~HTTPLoader_obj() { }

Dynamic HTTPLoader_obj::__CreateEmpty() { return  new HTTPLoader_obj; }
hx::ObjectPtr< HTTPLoader_obj > HTTPLoader_obj::__new(::String p_url,bool p_binary,Dynamic p_callback)
{  hx::ObjectPtr< HTTPLoader_obj > result = new HTTPLoader_obj();
	result->__construct(p_url,p_binary,p_callback);
	return result;}

Dynamic HTTPLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HTTPLoader_obj > result = new HTTPLoader_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void HTTPLoader_obj::OnStart( ){
{
		HX_STACK_FRAME("haxor.platform.windows.net.HTTPLoader","OnStart",0x45d7ae1b,"haxor.platform.windows.net.HTTPLoader.OnStart","haxor/platform/windows/net/HTTPLoader.hx",27,0x6e62a8f6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(27)
		if (((this->callback_dyn() != null()))){
			HX_STACK_LINE(27)
			this->callback(null(),0.0);
		}
	}
return null();
}


Void HTTPLoader_obj::OnProgress( ){
{
		HX_STACK_FRAME("haxor.platform.windows.net.HTTPLoader","OnProgress",0x1350d794,"haxor.platform.windows.net.HTTPLoader.OnProgress","haxor/platform/windows/net/HTTPLoader.hx",28,0x6e62a8f6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(28)
		if (((this->callback_dyn() != null()))){
			HX_STACK_LINE(28)
			this->callback(null(),(this->m_progress * 0.9999));
		}
	}
return null();
}


Void HTTPLoader_obj::OnComplete( ){
{
		HX_STACK_FRAME("haxor.platform.windows.net.HTTPLoader","OnComplete",0x0cede0a0,"haxor.platform.windows.net.HTTPLoader.OnComplete","haxor/platform/windows/net/HTTPLoader.hx",30,0x6e62a8f6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(31)
		if (((this->callback_dyn() == null()))){
			HX_STACK_LINE(31)
			return null();
		}
		HX_STACK_LINE(32)
		if ((this->binary)){
			HX_STACK_LINE(34)
			if (((this->response == null()))){
				HX_STACK_LINE(34)
				if (((this->callback_dyn() != null()))){
					HX_STACK_LINE(34)
					this->callback(null(),1.0);
				}
				HX_STACK_LINE(34)
				return null();
			}
			HX_STACK_LINE(35)
			::haxor::io::Buffer b = ::haxor::io::Buffer_obj::__new(this->response->__Field(HX_CSTRING("length"),true));		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(36)
			{
				HX_STACK_LINE(36)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(36)
				int _g = this->response->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(36)
				while((true)){
					HX_STACK_LINE(36)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(36)
						break;
					}
					HX_STACK_LINE(36)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(36)
					Dynamic _g2 = this->response->__Field(HX_CSTRING("charCodeAt"),true)(i);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(36)
					b->SetByte(i,_g2);
				}
			}
			HX_STACK_LINE(37)
			if (((this->callback_dyn() != null()))){
				HX_STACK_LINE(37)
				this->callback(b,1.0);
			}
		}
		else{
			HX_STACK_LINE(41)
			if (((this->callback_dyn() != null()))){
				HX_STACK_LINE(41)
				this->callback(this->response,1.0);
			}
		}
	}
return null();
}


Void HTTPLoader_obj::OnError( ){
{
		HX_STACK_FRAME("haxor.platform.windows.net.HTTPLoader","OnError",0x34f60581,"haxor.platform.windows.net.HTTPLoader.OnError","haxor/platform/windows/net/HTTPLoader.hx",45,0x6e62a8f6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(45)
		this->super::OnError();
		HX_STACK_LINE(45)
		if (((this->callback_dyn() != null()))){
			HX_STACK_LINE(45)
			this->callback(null(),1.0);
		}
	}
return null();
}



HTTPLoader_obj::HTTPLoader_obj()
{
}

void HTTPLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HTTPLoader);
	HX_MARK_MEMBER_NAME(callback,"callback");
	::haxor::net::HTTPRequestTask_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HTTPLoader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(callback,"callback");
	::haxor::net::HTTPRequestTask_obj::__Visit(HX_VISIT_ARG);
}

Dynamic HTTPLoader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"OnStart") ) { return OnStart_dyn(); }
		if (HX_FIELD_EQ(inName,"OnError") ) { return OnError_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"callback") ) { return callback; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"OnProgress") ) { return OnProgress_dyn(); }
		if (HX_FIELD_EQ(inName,"OnComplete") ) { return OnComplete_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HTTPLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"callback") ) { callback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HTTPLoader_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(HTTPLoader_obj,callback),HX_CSTRING("callback")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("callback"),
	HX_CSTRING("OnStart"),
	HX_CSTRING("OnProgress"),
	HX_CSTRING("OnComplete"),
	HX_CSTRING("OnError"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HTTPLoader_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HTTPLoader_obj::__mClass,"__mClass");
};

#endif

Class HTTPLoader_obj::__mClass;

void HTTPLoader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.windows.net.HTTPLoader"), hx::TCanCast< HTTPLoader_obj> ,sStaticFields,sMemberFields,
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

void HTTPLoader_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace windows
} // end namespace net
