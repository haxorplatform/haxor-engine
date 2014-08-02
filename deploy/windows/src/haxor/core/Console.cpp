#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
namespace haxor{
namespace core{

Void Console_obj::__construct()
{
	return null();
}

//Console_obj::~Console_obj() { }

Dynamic Console_obj::__CreateEmpty() { return  new Console_obj; }
hx::ObjectPtr< Console_obj > Console_obj::__new()
{  hx::ObjectPtr< Console_obj > result = new Console_obj();
	result->__construct();
	return result;}

Dynamic Console_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Console_obj > result = new Console_obj();
	result->__construct();
	return result;}

int Console_obj::verbose;

Void Console_obj::Log( ::String p_msg,hx::Null< int >  __o_p_level){
int p_level = __o_p_level.Default(0);
	HX_STACK_FRAME("haxor.core.Console","Log",0x0d81f5ca,"haxor.core.Console.Log","haxor/core/Console.hx",24,0xc2f3b4ca)
	HX_STACK_ARG(p_msg,"p_msg")
	HX_STACK_ARG(p_level,"p_level")
{
		HX_STACK_LINE(24)
		if (((::haxor::core::Console_obj::verbose >= p_level))){
			HX_STACK_LINE(39)
			::cpp::Lib_obj::println(p_msg);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,Log,(void))


Console_obj::Console_obj()
{
}

Dynamic Console_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Log") ) { return Log_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"verbose") ) { return verbose; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Console_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"verbose") ) { verbose=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Console_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("verbose"),
	HX_CSTRING("Log"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Console_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Console_obj::verbose,"verbose");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Console_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Console_obj::verbose,"verbose");
};

#endif

Class Console_obj::__mClass;

void Console_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.Console"), hx::TCanCast< Console_obj> ,sStaticFields,sMemberFields,
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

void Console_obj::__boot()
{
	verbose= (int)0;
}

} // end namespace haxor
} // end namespace core
