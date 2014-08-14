#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxe_Http
#include <haxe/Http.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
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

Void LoadTask_obj::__construct(::String p_url,::String p_method,::String p_data,Dynamic p_ondata,Dynamic p_onerror)
{
HX_STACK_FRAME("haxor.platform.windows.LoadTask","new",0xc39d3a57,"haxor.platform.windows.LoadTask.new","haxor/platform/windows/Web.hx",73,0x2cb2b125)
HX_STACK_THIS(this)
HX_STACK_ARG(p_url,"p_url")
HX_STACK_ARG(p_method,"p_method")
HX_STACK_ARG(p_data,"p_data")
HX_STACK_ARG(p_ondata,"p_ondata")
HX_STACK_ARG(p_onerror,"p_onerror")
{
	HX_STACK_LINE(74)
	::String _g = ::StringTools_obj::replace(p_url,HX_CSTRING("./"),::haxor::platform::windows::Web_obj::root);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(74)
	this->url = _g;
	HX_STACK_LINE(75)
	this->method = p_method;
	HX_STACK_LINE(76)
	this->data = p_data;
	HX_STACK_LINE(77)
	this->ondata = p_ondata;
	HX_STACK_LINE(78)
	this->onerror = p_onerror;
}
;
	return null();
}

//LoadTask_obj::~LoadTask_obj() { }

Dynamic LoadTask_obj::__CreateEmpty() { return  new LoadTask_obj; }
hx::ObjectPtr< LoadTask_obj > LoadTask_obj::__new(::String p_url,::String p_method,::String p_data,Dynamic p_ondata,Dynamic p_onerror)
{  hx::ObjectPtr< LoadTask_obj > result = new LoadTask_obj();
	result->__construct(p_url,p_method,p_data,p_ondata,p_onerror);
	return result;}

Dynamic LoadTask_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LoadTask_obj > result = new LoadTask_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

Void LoadTask_obj::Run( ){
{
		HX_STACK_FRAME("haxor.platform.windows.LoadTask","Run",0xc3880922,"haxor.platform.windows.LoadTask.Run","haxor/platform/windows/Web.hx",82,0x2cb2b125)
		HX_STACK_THIS(this)
		HX_STACK_LINE(83)
		::haxe::Log_obj::trace(((HX_CSTRING("Web> Load from [") + this->url) + HX_CSTRING("]")),hx::SourceInfo(HX_CSTRING("Web.hx"),83,HX_CSTRING("haxor.platform.windows.LoadTask"),HX_CSTRING("Run")));
		HX_STACK_LINE(84)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(86)
			::String d = ::haxe::Http_obj::requestUrl(this->url);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(87)
			this->ondata(d);
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic err = __e;{
					HX_STACK_LINE(91)
					::String _g = ::Std_obj::string(err);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(91)
					::String _g1 = (_g + HX_CSTRING(""));		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(91)
					this->onerror(_g1);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(LoadTask_obj,Run,(void))


LoadTask_obj::LoadTask_obj()
{
}

void LoadTask_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LoadTask);
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_MEMBER_NAME(method,"method");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(ondata,"ondata");
	HX_MARK_MEMBER_NAME(onerror,"onerror");
	HX_MARK_END_CLASS();
}

void LoadTask_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(url,"url");
	HX_VISIT_MEMBER_NAME(method,"method");
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(ondata,"ondata");
	HX_VISIT_MEMBER_NAME(onerror,"onerror");
}

Dynamic LoadTask_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		if (HX_FIELD_EQ(inName,"Run") ) { return Run_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"method") ) { return method; }
		if (HX_FIELD_EQ(inName,"ondata") ) { return ondata; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onerror") ) { return onerror; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LoadTask_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"method") ) { method=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ondata") ) { ondata=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onerror") ) { onerror=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LoadTask_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("url"));
	outFields->push(HX_CSTRING("method"));
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(LoadTask_obj,url),HX_CSTRING("url")},
	{hx::fsString,(int)offsetof(LoadTask_obj,method),HX_CSTRING("method")},
	{hx::fsString,(int)offsetof(LoadTask_obj,data),HX_CSTRING("data")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(LoadTask_obj,ondata),HX_CSTRING("ondata")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(LoadTask_obj,onerror),HX_CSTRING("onerror")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("url"),
	HX_CSTRING("method"),
	HX_CSTRING("data"),
	HX_CSTRING("ondata"),
	HX_CSTRING("onerror"),
	HX_CSTRING("Run"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LoadTask_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LoadTask_obj::__mClass,"__mClass");
};

#endif

Class LoadTask_obj::__mClass;

void LoadTask_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.windows.LoadTask"), hx::TCanCast< LoadTask_obj> ,sStaticFields,sMemberFields,
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

void LoadTask_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace windows
