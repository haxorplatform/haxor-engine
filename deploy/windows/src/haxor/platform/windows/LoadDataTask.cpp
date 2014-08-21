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
#ifndef INCLUDED_haxor_platform_windows_HTTPRequest
#include <haxor/platform/windows/HTTPRequest.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_LoadDataTask
#include <haxor/platform/windows/LoadDataTask.h>
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

Void LoadDataTask_obj::__construct(::String p_url,bool p_binary,Dynamic p_callback)
{
HX_STACK_FRAME("haxor.platform.windows.LoadDataTask","new",0x4255d6a1,"haxor.platform.windows.LoadDataTask.new","haxor/platform/windows/Web.hx",102,0x2cb2b125)
HX_STACK_THIS(this)
HX_STACK_ARG(p_url,"p_url")
HX_STACK_ARG(p_binary,"p_binary")
HX_STACK_ARG(p_callback,"p_callback")
{
	HX_STACK_LINE(103)
	super::__construct(p_url,HX_CSTRING("GET"),p_binary,null());
	HX_STACK_LINE(104)
	this->callback = p_callback;
}
;
	return null();
}

//LoadDataTask_obj::~LoadDataTask_obj() { }

Dynamic LoadDataTask_obj::__CreateEmpty() { return  new LoadDataTask_obj; }
hx::ObjectPtr< LoadDataTask_obj > LoadDataTask_obj::__new(::String p_url,bool p_binary,Dynamic p_callback)
{  hx::ObjectPtr< LoadDataTask_obj > result = new LoadDataTask_obj();
	result->__construct(p_url,p_binary,p_callback);
	return result;}

Dynamic LoadDataTask_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LoadDataTask_obj > result = new LoadDataTask_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void LoadDataTask_obj::OnStart( ){
{
		HX_STACK_FRAME("haxor.platform.windows.LoadDataTask","OnStart",0x2722f564,"haxor.platform.windows.LoadDataTask.OnStart","haxor/platform/windows/Web.hx",106,0x2cb2b125)
		HX_STACK_THIS(this)
		HX_STACK_LINE(106)
		if (((this->callback_dyn() != null()))){
			HX_STACK_LINE(106)
			this->callback(null(),0.0);
		}
	}
return null();
}


Void LoadDataTask_obj::OnProgress( ){
{
		HX_STACK_FRAME("haxor.platform.windows.LoadDataTask","OnProgress",0xf14c83eb,"haxor.platform.windows.LoadDataTask.OnProgress","haxor/platform/windows/Web.hx",107,0x2cb2b125)
		HX_STACK_THIS(this)
		HX_STACK_LINE(107)
		if (((this->callback_dyn() != null()))){
			HX_STACK_LINE(107)
			this->callback(null(),(this->m_progress * 0.9999));
		}
	}
return null();
}


Void LoadDataTask_obj::OnComplete( ){
{
		HX_STACK_FRAME("haxor.platform.windows.LoadDataTask","OnComplete",0xeae98cf7,"haxor.platform.windows.LoadDataTask.OnComplete","haxor/platform/windows/Web.hx",109,0x2cb2b125)
		HX_STACK_THIS(this)
		HX_STACK_LINE(110)
		if (((this->callback_dyn() == null()))){
			HX_STACK_LINE(110)
			return null();
		}
		HX_STACK_LINE(111)
		if ((this->binary)){
			HX_STACK_LINE(113)
			if (((this->response == null()))){
				HX_STACK_LINE(113)
				if (((this->callback_dyn() != null()))){
					HX_STACK_LINE(113)
					this->callback(null(),1.0);
				}
				HX_STACK_LINE(113)
				return null();
			}
			HX_STACK_LINE(114)
			::haxor::io::Buffer b = ::haxor::io::Buffer_obj::__new(this->response.length);		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(115)
			{
				HX_STACK_LINE(115)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(115)
				int _g = this->response.length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(115)
				while((true)){
					HX_STACK_LINE(115)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(115)
						break;
					}
					HX_STACK_LINE(115)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(115)
					Dynamic _g2 = this->response.charCodeAt(i);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(115)
					b->SetByte(i,_g2);
				}
			}
			HX_STACK_LINE(116)
			if (((this->callback_dyn() != null()))){
				HX_STACK_LINE(116)
				this->callback(b,1.0);
			}
		}
		else{
			HX_STACK_LINE(120)
			if (((this->callback_dyn() != null()))){
				HX_STACK_LINE(120)
				this->callback(this->response,1.0);
			}
		}
	}
return null();
}


Void LoadDataTask_obj::OnError( ){
{
		HX_STACK_FRAME("haxor.platform.windows.LoadDataTask","OnError",0x16414cca,"haxor.platform.windows.LoadDataTask.OnError","haxor/platform/windows/Web.hx",124,0x2cb2b125)
		HX_STACK_THIS(this)
		HX_STACK_LINE(124)
		if (((this->callback_dyn() != null()))){
			HX_STACK_LINE(124)
			this->callback(null(),1.0);
		}
	}
return null();
}



LoadDataTask_obj::LoadDataTask_obj()
{
}

void LoadDataTask_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LoadDataTask);
	HX_MARK_MEMBER_NAME(callback,"callback");
	::haxor::platform::windows::HTTPRequest_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void LoadDataTask_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(callback,"callback");
	::haxor::platform::windows::HTTPRequest_obj::__Visit(HX_VISIT_ARG);
}

Dynamic LoadDataTask_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic LoadDataTask_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"callback") ) { callback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LoadDataTask_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(LoadDataTask_obj,callback),HX_CSTRING("callback")},
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
	HX_MARK_MEMBER_NAME(LoadDataTask_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LoadDataTask_obj::__mClass,"__mClass");
};

#endif

Class LoadDataTask_obj::__mClass;

void LoadDataTask_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.windows.LoadDataTask"), hx::TCanCast< LoadDataTask_obj> ,sStaticFields,sMemberFields,
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

void LoadDataTask_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace windows
