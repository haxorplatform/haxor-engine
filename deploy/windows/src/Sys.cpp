#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif

Void Sys_obj::__construct()
{
	return null();
}

//Sys_obj::~Sys_obj() { }

Dynamic Sys_obj::__CreateEmpty() { return  new Sys_obj; }
hx::ObjectPtr< Sys_obj > Sys_obj::__new()
{  hx::ObjectPtr< Sys_obj > result = new Sys_obj();
	result->__construct();
	return result;}

Dynamic Sys_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sys_obj > result = new Sys_obj();
	result->__construct();
	return result;}

Array< ::String > Sys_obj::args( ){
	HX_STACK_FRAME("Sys","args",0xeaeddc7e,"Sys.args","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/Sys.hx",50,0x72b36d63)
	HX_STACK_LINE(50)
	return ::__get_args();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,args,return )

Void Sys_obj::sleep( Float seconds){
{
		HX_STACK_FRAME("Sys","sleep",0xfe70aad6,"Sys.sleep","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/Sys.hx",65,0x72b36d63)
		HX_STACK_ARG(seconds,"seconds")
		HX_STACK_LINE(65)
		::Sys_obj::_sleep(seconds);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,sleep,(void))

::String Sys_obj::escapeArgument( ::String arg){
	HX_STACK_FRAME("Sys","escapeArgument",0xb9d4397f,"Sys.escapeArgument","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/Sys.hx",84,0x72b36d63)
	HX_STACK_ARG(arg,"arg")
	HX_STACK_LINE(85)
	bool ok = true;		HX_STACK_VAR(ok,"ok");
	HX_STACK_LINE(86)
	{
		HX_STACK_LINE(86)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(86)
		int _g = arg.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(86)
		while((true)){
			HX_STACK_LINE(86)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(86)
				break;
			}
			HX_STACK_LINE(86)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(87)
			Dynamic _g2 = arg.charCodeAt(i);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(87)
			switch( (int)(_g2)){
				case (int)32: case (int)34: {
					HX_STACK_LINE(89)
					ok = false;
				}
				;break;
				case (int)0: case (int)13: case (int)10: {
					HX_STACK_LINE(91)
					::String _g3 = arg.substr((int)0,i);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(91)
					arg = _g3;
				}
				;break;
			}
		}
	}
	HX_STACK_LINE(93)
	if ((ok)){
		HX_STACK_LINE(94)
		return arg;
	}
	HX_STACK_LINE(95)
	::String _g1 = arg.split(HX_CSTRING("\""))->join(HX_CSTRING("\\\""));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(95)
	::String _g2 = (HX_CSTRING("\"") + _g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(95)
	return (_g2 + HX_CSTRING("\""));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,escapeArgument,return )

int Sys_obj::command( ::String cmd,Array< ::String > args){
	HX_STACK_FRAME("Sys","command",0x363f8cca,"Sys.command","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/Sys.hx",98,0x72b36d63)
	HX_STACK_ARG(cmd,"cmd")
	HX_STACK_ARG(args,"args")
	HX_STACK_LINE(99)
	if (((args != null()))){
		HX_STACK_LINE(100)
		::String _g = ::Sys_obj::escapeArgument(cmd);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(100)
		cmd = _g;
		HX_STACK_LINE(101)
		{
			HX_STACK_LINE(101)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(101)
			while((true)){
				HX_STACK_LINE(101)
				if ((!(((_g1 < args->length))))){
					HX_STACK_LINE(101)
					break;
				}
				HX_STACK_LINE(101)
				::String a = args->__get(_g1);		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(101)
				++(_g1);
				HX_STACK_LINE(102)
				::String _g11 = ::Sys_obj::escapeArgument(a);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(102)
				::String _g2 = (HX_CSTRING(" ") + _g11);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(102)
				hx::AddEq(cmd,_g2);
			}
		}
	}
	HX_STACK_LINE(104)
	return ::Sys_obj::sys_command(cmd);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Sys_obj,command,return )

Dynamic Sys_obj::_sleep;

Dynamic Sys_obj::sys_command;


Sys_obj::Sys_obj()
{
}

Dynamic Sys_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"args") ) { return args_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"sleep") ) { return sleep_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_sleep") ) { return _sleep; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"command") ) { return command_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"sys_command") ) { return sys_command; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"escapeArgument") ) { return escapeArgument_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Sys_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"_sleep") ) { _sleep=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"sys_command") ) { sys_command=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Sys_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("args"),
	HX_CSTRING("sleep"),
	HX_CSTRING("escapeArgument"),
	HX_CSTRING("command"),
	HX_CSTRING("_sleep"),
	HX_CSTRING("sys_command"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Sys_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Sys_obj::_sleep,"_sleep");
	HX_MARK_MEMBER_NAME(Sys_obj::sys_command,"sys_command");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Sys_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Sys_obj::_sleep,"_sleep");
	HX_VISIT_MEMBER_NAME(Sys_obj::sys_command,"sys_command");
};

#endif

Class Sys_obj::__mClass;

void Sys_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Sys"), hx::TCanCast< Sys_obj> ,sStaticFields,sMemberFields,
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

void Sys_obj::__boot()
{
	_sleep= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_sleep"),(int)1);
	sys_command= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_command"),(int)1);
}

