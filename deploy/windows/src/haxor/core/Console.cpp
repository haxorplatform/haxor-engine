#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
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

::haxe::ds::StringMap Console_obj::m_benchmarks;

Void Console_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.core.Console","Initialize",0xd0fce4ca,"haxor.core.Console.Initialize","haxor/core/Console.hx",26,0xc2f3b4ca)
		HX_STACK_LINE(29)
		::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(29)
		::haxor::core::Console_obj::m_benchmarks = _g;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Console_obj,Initialize,(void))

int Console_obj::verbose;

Void Console_obj::Breakpoint( ){
{
		HX_STACK_FRAME("haxor.core.Console","Breakpoint",0x518caeab,"haxor.core.Console.Breakpoint","haxor/core/Console.hx",43,0xc2f3b4ca)
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Console_obj,Breakpoint,(void))

Void Console_obj::Log( ::String p_msg,hx::Null< int >  __o_p_level){
int p_level = __o_p_level.Default(0);
	HX_STACK_FRAME("haxor.core.Console","Log",0x0d81f5ca,"haxor.core.Console.Log","haxor/core/Console.hx",56,0xc2f3b4ca)
	HX_STACK_ARG(p_msg,"p_msg")
	HX_STACK_ARG(p_level,"p_level")
{
		HX_STACK_LINE(56)
		if (((::haxor::core::Console_obj::verbose >= p_level))){
			HX_STACK_LINE(71)
			::cpp::Lib_obj::println(p_msg);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,Log,(void))

Void Console_obj::LogImage( ::String p_url,int p_height){
{
		HX_STACK_FRAME("haxor.core.Console","LogImage",0xe2f35d31,"haxor.core.Console.LogImage","haxor/core/Console.hx",84,0xc2f3b4ca)
		HX_STACK_ARG(p_url,"p_url")
		HX_STACK_ARG(p_height,"p_height")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,LogImage,(void))

Void Console_obj::LogWarning( ::String p_msg,Dynamic p_obj){
{
		HX_STACK_FRAME("haxor.core.Console","LogWarning",0x54c1b9b2,"haxor.core.Console.LogWarning","haxor/core/Console.hx",110,0xc2f3b4ca)
		HX_STACK_ARG(p_msg,"p_msg")
		HX_STACK_ARG(p_obj,"p_obj")
		HX_STACK_LINE(110)
		::haxor::core::Console_obj::Log((HX_CSTRING("[W] ") + p_msg),null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,LogWarning,(void))

Void Console_obj::LogError( ::String p_msg,Dynamic p_obj){
{
		HX_STACK_FRAME("haxor.core.Console","LogError",0x98b4099e,"haxor.core.Console.LogError","haxor/core/Console.hx",132,0xc2f3b4ca)
		HX_STACK_ARG(p_msg,"p_msg")
		HX_STACK_ARG(p_obj,"p_obj")
		HX_STACK_LINE(132)
		::haxor::core::Console_obj::Log((HX_CSTRING("[E] ") + p_msg),null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Console_obj,LogError,(void))

Void Console_obj::ClearStyle( ){
{
		HX_STACK_FRAME("haxor.core.Console","ClearStyle",0x3d6997de,"haxor.core.Console.ClearStyle","haxor/core/Console.hx",141,0xc2f3b4ca)
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Console_obj,ClearStyle,(void))

Void Console_obj::Clear( ){
{
		HX_STACK_FRAME("haxor.core.Console","Clear",0xb9aa7053,"haxor.core.Console.Clear","haxor/core/Console.hx",151,0xc2f3b4ca)
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Console_obj,Clear,(void))

Void Console_obj::TimeStart( ::String p_id){
{
		HX_STACK_FRAME("haxor.core.Console","TimeStart",0x31f922db,"haxor.core.Console.TimeStart","haxor/core/Console.hx",168,0xc2f3b4ca)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(172)
		if ((::haxor::core::Console_obj::m_benchmarks->exists(p_id))){
			HX_STACK_LINE(172)
			return null();
		}
		HX_STACK_LINE(173)
		{
			HX_STACK_LINE(173)
			Float value = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(value,"value");
			HX_STACK_LINE(173)
			::haxor::core::Console_obj::m_benchmarks->set(p_id,value);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Console_obj,TimeStart,(void))

Void Console_obj::TimeEnd( ::String p_id){
{
		HX_STACK_FRAME("haxor.core.Console","TimeEnd",0x7af7f214,"haxor.core.Console.TimeEnd","haxor/core/Console.hx",183,0xc2f3b4ca)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(187)
		if ((!(::haxor::core::Console_obj::m_benchmarks->exists(p_id)))){
			HX_STACK_LINE(187)
			return null();
		}
		HX_STACK_LINE(188)
		Float t = ::haxor::core::Console_obj::m_benchmarks->get(p_id);		HX_STACK_VAR(t,"t");
		HX_STACK_LINE(189)
		::haxor::core::Console_obj::m_benchmarks->remove(p_id);
		HX_STACK_LINE(190)
		int _g = ::Math_obj::floor((t * 1000.0));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(190)
		::String _g1 = ((p_id + HX_CSTRING(": ")) + _g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(190)
		::String _g2 = (_g1 + HX_CSTRING("ms"));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(190)
		::haxor::core::Console_obj::Log(_g2,null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Console_obj,TimeEnd,(void))

Void Console_obj::StackTrace( ){
{
		HX_STACK_FRAME("haxor.core.Console","StackTrace",0x0d7fe597,"haxor.core.Console.StackTrace","haxor/core/Console.hx",198,0xc2f3b4ca)
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Console_obj,StackTrace,(void))

Void Console_obj::SetStyle( ::String __o_p_size,::String __o_p_color,::String __o_p_background,::String __o_p_font){
::String p_size = __o_p_size.Default(HX_CSTRING("12px"));
::String p_color = __o_p_color.Default(HX_CSTRING("rgba(0,0,0,1)"));
::String p_background = __o_p_background.Default(HX_CSTRING("rgba(255,255,255,0)"));
::String p_font = __o_p_font.Default(HX_CSTRING("'Lucida Console', Monaco, monospace"));
	HX_STACK_FRAME("haxor.core.Console","SetStyle",0xccd60f29,"haxor.core.Console.SetStyle","haxor/core/Console.hx",216,0xc2f3b4ca)
	HX_STACK_ARG(p_size,"p_size")
	HX_STACK_ARG(p_color,"p_color")
	HX_STACK_ARG(p_background,"p_background")
	HX_STACK_ARG(p_font,"p_font")
{
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Console_obj,SetStyle,(void))


Console_obj::Console_obj()
{
}

Dynamic Console_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Log") ) { return Log_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"verbose") ) { return verbose; }
		if (HX_FIELD_EQ(inName,"TimeEnd") ) { return TimeEnd_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"LogImage") ) { return LogImage_dyn(); }
		if (HX_FIELD_EQ(inName,"LogError") ) { return LogError_dyn(); }
		if (HX_FIELD_EQ(inName,"SetStyle") ) { return SetStyle_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"TimeStart") ) { return TimeStart_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"Breakpoint") ) { return Breakpoint_dyn(); }
		if (HX_FIELD_EQ(inName,"LogWarning") ) { return LogWarning_dyn(); }
		if (HX_FIELD_EQ(inName,"ClearStyle") ) { return ClearStyle_dyn(); }
		if (HX_FIELD_EQ(inName,"StackTrace") ) { return StackTrace_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_benchmarks") ) { return m_benchmarks; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Console_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"verbose") ) { verbose=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_benchmarks") ) { m_benchmarks=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Console_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_benchmarks"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("verbose"),
	HX_CSTRING("Breakpoint"),
	HX_CSTRING("Log"),
	HX_CSTRING("LogImage"),
	HX_CSTRING("LogWarning"),
	HX_CSTRING("LogError"),
	HX_CSTRING("ClearStyle"),
	HX_CSTRING("Clear"),
	HX_CSTRING("TimeStart"),
	HX_CSTRING("TimeEnd"),
	HX_CSTRING("StackTrace"),
	HX_CSTRING("SetStyle"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Console_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Console_obj::m_benchmarks,"m_benchmarks");
	HX_MARK_MEMBER_NAME(Console_obj::verbose,"verbose");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Console_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Console_obj::m_benchmarks,"m_benchmarks");
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
