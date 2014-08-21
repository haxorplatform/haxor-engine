#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_sys_net_Host
#include <sys/net/Host.h>
#endif
namespace sys{
namespace net{

Void Host_obj::__construct(::String name)
{
HX_STACK_FRAME("sys.net.Host","new",0x056496ac,"sys.net.Host.new","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/sys/net/Host.hx",29,0x7ed80650)
HX_STACK_THIS(this)
HX_STACK_ARG(name,"name")
{
	HX_STACK_LINE(30)
	int _g = ::sys::net::Host_obj::host_resolve(name);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(30)
	this->ip = _g;
}
;
	return null();
}

//Host_obj::~Host_obj() { }

Dynamic Host_obj::__CreateEmpty() { return  new Host_obj; }
hx::ObjectPtr< Host_obj > Host_obj::__new(::String name)
{  hx::ObjectPtr< Host_obj > result = new Host_obj();
	result->__construct(name);
	return result;}

Dynamic Host_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Host_obj > result = new Host_obj();
	result->__construct(inArgs[0]);
	return result;}

void Host_obj::__init__() {
HX_STACK_FRAME("sys.net.Host","__init__",0xecfcc384,"sys.net.Host.__init__","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/sys/net/Host.hx",46,0x7ed80650)
{
	HX_STACK_LINE(46)
	::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_init"),(int)0)();
}
}

::String Host_obj::toString( ){
	HX_STACK_FRAME("sys.net.Host","toString",0xe5efb6e0,"sys.net.Host.toString","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/cpp/_std/sys/net/Host.hx",33,0x7ed80650)
	HX_STACK_THIS(this)
	HX_STACK_LINE(34)
	::String _g = ::sys::net::Host_obj::host_to_string(this->ip);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(34)
	return ::String(_g);
}


HX_DEFINE_DYNAMIC_FUNC0(Host_obj,toString,return )

Dynamic Host_obj::host_resolve;

Dynamic Host_obj::host_to_string;


Host_obj::Host_obj()
{
}

Dynamic Host_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ip") ) { return ip; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"host_resolve") ) { return host_resolve; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"host_to_string") ) { return host_to_string; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Host_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ip") ) { ip=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"host_resolve") ) { host_resolve=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"host_to_string") ) { host_to_string=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Host_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("ip"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("host_resolve"),
	HX_CSTRING("host_to_string"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Host_obj,ip),HX_CSTRING("ip")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("ip"),
	HX_CSTRING("toString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Host_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Host_obj::host_resolve,"host_resolve");
	HX_MARK_MEMBER_NAME(Host_obj::host_to_string,"host_to_string");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Host_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Host_obj::host_resolve,"host_resolve");
	HX_VISIT_MEMBER_NAME(Host_obj::host_to_string,"host_to_string");
};

#endif

Class Host_obj::__mClass;

void Host_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.net.Host"), hx::TCanCast< Host_obj> ,sStaticFields,sMemberFields,
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

void Host_obj::__boot()
{
	host_resolve= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("host_resolve"),(int)1);
	host_to_string= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("host_to_string"),(int)1);
}

} // end namespace sys
} // end namespace net
