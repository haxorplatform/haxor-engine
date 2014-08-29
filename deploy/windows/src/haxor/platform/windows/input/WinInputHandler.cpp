#include <hxcpp.h>

#ifndef INCLUDED_haxor_input_InputHandler
#include <haxor/input/InputHandler.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_input_WinInputHandler
#include <haxor/platform/windows/input/WinInputHandler.h>
#endif
namespace haxor{
namespace platform{
namespace windows{
namespace input{

Void WinInputHandler_obj::__construct()
{
HX_STACK_FRAME("haxor.platform.windows.input.WinInputHandler","new",0xbd82d010,"haxor.platform.windows.input.WinInputHandler.new","haxor/platform/windows/input/WinInputHandler.hx",21,0x9e512882)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(21)
	super::__construct();
}
;
	return null();
}

//WinInputHandler_obj::~WinInputHandler_obj() { }

Dynamic WinInputHandler_obj::__CreateEmpty() { return  new WinInputHandler_obj; }
hx::ObjectPtr< WinInputHandler_obj > WinInputHandler_obj::__new()
{  hx::ObjectPtr< WinInputHandler_obj > result = new WinInputHandler_obj();
	result->__construct();
	return result;}

Dynamic WinInputHandler_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WinInputHandler_obj > result = new WinInputHandler_obj();
	result->__construct();
	return result;}

Void WinInputHandler_obj::UpdateInput( ){
{
		HX_STACK_FRAME("haxor.platform.windows.input.WinInputHandler","UpdateInput",0xa0a6f4d1,"haxor.platform.windows.input.WinInputHandler.UpdateInput","haxor/platform/windows/input/WinInputHandler.hx",28,0x9e512882)
		HX_STACK_THIS(this)
	}
return null();
}



WinInputHandler_obj::WinInputHandler_obj()
{
}

Dynamic WinInputHandler_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"UpdateInput") ) { return UpdateInput_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic WinInputHandler_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void WinInputHandler_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("UpdateInput"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(WinInputHandler_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(WinInputHandler_obj::__mClass,"__mClass");
};

#endif

Class WinInputHandler_obj::__mClass;

void WinInputHandler_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.windows.input.WinInputHandler"), hx::TCanCast< WinInputHandler_obj> ,sStaticFields,sMemberFields,
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

void WinInputHandler_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace windows
} // end namespace input
