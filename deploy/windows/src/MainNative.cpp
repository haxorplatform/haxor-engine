#include <hxcpp.h>

#ifndef INCLUDED_MainNative
#include <MainNative.h>
#endif
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
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
#ifndef INCLUDED_haxor_platform_windows_Entry
#include <haxor/platform/windows/Entry.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_WinApplication
#include <haxor/platform/windows/WinApplication.h>
#endif

Void MainNative_obj::__construct()
{
HX_STACK_FRAME("MainNative","new",0x44cb33c2,"MainNative.new","MainNative.hx",12,0x58b3f9ee)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(12)
	super::__construct();
}
;
	return null();
}

//MainNative_obj::~MainNative_obj() { }

Dynamic MainNative_obj::__CreateEmpty() { return  new MainNative_obj; }
hx::ObjectPtr< MainNative_obj > MainNative_obj::__new()
{  hx::ObjectPtr< MainNative_obj > result = new MainNative_obj();
	result->__construct();
	return result;}

Dynamic MainNative_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MainNative_obj > result = new MainNative_obj();
	result->__construct();
	return result;}

Void MainNative_obj::main( ){
{
		HX_STACK_FRAME("MainNative","main",0xec55ca97,"MainNative.main","MainNative.hx",17,0x58b3f9ee)
		HX_STACK_LINE(17)
		::haxor::platform::windows::Entry_obj::Initialize();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(MainNative_obj,main,(void))


MainNative_obj::MainNative_obj()
{
}

Dynamic MainNative_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MainNative_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void MainNative_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MainNative_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MainNative_obj::__mClass,"__mClass");
};

#endif

Class MainNative_obj::__mClass;

void MainNative_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("MainNative"), hx::TCanCast< MainNative_obj> ,sStaticFields,sMemberFields,
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

void MainNative_obj::__boot()
{
}

