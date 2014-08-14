#include <hxcpp.h>

#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_LoadStringTask
#include <haxor/platform/windows/LoadStringTask.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_LoadTask
#include <haxor/platform/windows/LoadTask.h>
#endif
namespace haxor{
namespace platform{
namespace windows{

Void LoadStringTask_obj::__construct(::String p_url,::String p_method,::String p_data,Dynamic p_callback)
{
HX_STACK_FRAME("haxor.platform.windows.LoadStringTask","new",0xa1a85048,"haxor.platform.windows.LoadStringTask.new","haxor/platform/windows/Web.hx",73,0x2cb2b125)
HX_STACK_THIS(this)
HX_STACK_ARG(p_url,"p_url")
HX_STACK_ARG(p_method,"p_method")
HX_STACK_ARG(p_data,"p_data")
HX_STACK_ARG(p_callback,"p_callback")
{
	HX_STACK_LINE(74)
	super::__construct(p_url,p_method,p_data,this->OnData_dyn(),this->OnError_dyn());
	HX_STACK_LINE(75)
	this->callback = p_callback;
	HX_STACK_LINE(76)
	this->callback(null(),0.0);
}
;
	return null();
}

//LoadStringTask_obj::~LoadStringTask_obj() { }

Dynamic LoadStringTask_obj::__CreateEmpty() { return  new LoadStringTask_obj; }
hx::ObjectPtr< LoadStringTask_obj > LoadStringTask_obj::__new(::String p_url,::String p_method,::String p_data,Dynamic p_callback)
{  hx::ObjectPtr< LoadStringTask_obj > result = new LoadStringTask_obj();
	result->__construct(p_url,p_method,p_data,p_callback);
	return result;}

Dynamic LoadStringTask_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LoadStringTask_obj > result = new LoadStringTask_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void LoadStringTask_obj::OnData( ::String p_data){
{
		HX_STACK_FRAME("haxor.platform.windows.LoadStringTask","OnData",0x90203421,"haxor.platform.windows.LoadStringTask.OnData","haxor/platform/windows/Web.hx",81,0x2cb2b125)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_LINE(81)
		::haxe::Log_obj::trace(this->callback_dyn(),hx::SourceInfo(HX_CSTRING("Web.hx"),81,HX_CSTRING("haxor.platform.windows.LoadStringTask"),HX_CSTRING("OnData")));
	}
return null();
}


Void LoadStringTask_obj::OnError( ::String p_message){
{
		HX_STACK_FRAME("haxor.platform.windows.LoadStringTask","OnError",0x2aaf25f1,"haxor.platform.windows.LoadStringTask.OnError","haxor/platform/windows/Web.hx",86,0x2cb2b125)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_message,"p_message")
		HX_STACK_LINE(86)
		this->callback(null(),1.0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LoadStringTask_obj,OnError,(void))


LoadStringTask_obj::LoadStringTask_obj()
{
}

void LoadStringTask_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LoadStringTask);
	HX_MARK_MEMBER_NAME(callback,"callback");
	::haxor::platform::windows::LoadTask_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void LoadStringTask_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(callback,"callback");
	::haxor::platform::windows::LoadTask_obj::__Visit(HX_VISIT_ARG);
}

Dynamic LoadStringTask_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"OnData") ) { return OnData_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"OnError") ) { return OnError_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"callback") ) { return callback; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LoadStringTask_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"callback") ) { callback=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LoadStringTask_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(LoadStringTask_obj,callback),HX_CSTRING("callback")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("callback"),
	HX_CSTRING("OnData"),
	HX_CSTRING("OnError"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LoadStringTask_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LoadStringTask_obj::__mClass,"__mClass");
};

#endif

Class LoadStringTask_obj::__mClass;

void LoadStringTask_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.windows.LoadStringTask"), hx::TCanCast< LoadStringTask_obj> ,sStaticFields,sMemberFields,
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

void LoadStringTask_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace windows
