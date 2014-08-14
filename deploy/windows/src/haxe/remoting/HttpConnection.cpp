#include <hxcpp.h>

#ifndef INCLUDED_haxe_Serializer
#include <haxe/Serializer.h>
#endif
#ifndef INCLUDED_haxe_Unserializer
#include <haxe/Unserializer.h>
#endif
#ifndef INCLUDED_haxe_remoting_Connection
#include <haxe/remoting/Connection.h>
#endif
#ifndef INCLUDED_haxe_remoting_Context
#include <haxe/remoting/Context.h>
#endif
#ifndef INCLUDED_haxe_remoting_HttpConnection
#include <haxe/remoting/HttpConnection.h>
#endif
namespace haxe{
namespace remoting{

Void HttpConnection_obj::__construct()
{
	return null();
}

//HttpConnection_obj::~HttpConnection_obj() { }

Dynamic HttpConnection_obj::__CreateEmpty() { return  new HttpConnection_obj; }
hx::ObjectPtr< HttpConnection_obj > HttpConnection_obj::__new()
{  hx::ObjectPtr< HttpConnection_obj > result = new HttpConnection_obj();
	result->__construct();
	return result;}

Dynamic HttpConnection_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HttpConnection_obj > result = new HttpConnection_obj();
	result->__construct();
	return result;}

hx::Object *HttpConnection_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::haxe::remoting::Connection_obj)) return operator ::haxe::remoting::Connection_obj *();
	return super::__ToInterface(inType);
}

::String HttpConnection_obj::processRequest( ::String requestData,::haxe::remoting::Context ctx){
	HX_STACK_FRAME("haxe.remoting.HttpConnection","processRequest",0x45dc8305,"haxe.remoting.HttpConnection.processRequest","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/remoting/HttpConnection.hx",95,0x195bd368)
	HX_STACK_ARG(requestData,"requestData")
	HX_STACK_ARG(ctx,"ctx")
	HX_STACK_LINE(95)
	try
	{
	HX_STACK_CATCHABLE(Dynamic, 0);
	{
		HX_STACK_LINE(96)
		::haxe::Unserializer u = ::haxe::Unserializer_obj::__new(requestData);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(97)
		Array< ::String > path = u->unserialize();		HX_STACK_VAR(path,"path");
		HX_STACK_LINE(98)
		Dynamic args = u->unserialize();		HX_STACK_VAR(args,"args");
		HX_STACK_LINE(99)
		Dynamic data = ctx->call(path,args);		HX_STACK_VAR(data,"data");
		HX_STACK_LINE(100)
		::haxe::Serializer s = ::haxe::Serializer_obj::__new();		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(101)
		s->serialize(data);
		HX_STACK_LINE(102)
		::String _g = s->toString();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(102)
		return (HX_CSTRING("hxr") + _g);
	}
	}
	catch(Dynamic __e){
		{
			HX_STACK_BEGIN_CATCH
			Dynamic e = __e;{
				HX_STACK_LINE(104)
				::haxe::Serializer s = ::haxe::Serializer_obj::__new();		HX_STACK_VAR(s,"s");
				HX_STACK_LINE(105)
				s->serializeException(e);
				HX_STACK_LINE(106)
				::String _g1 = s->toString();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(106)
				return (HX_CSTRING("hxr") + _g1);
			}
		}
	}
	HX_STACK_LINE(95)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HttpConnection_obj,processRequest,return )


HttpConnection_obj::HttpConnection_obj()
{
	HX_INIT_IMPLEMENT_DYNAMIC;
}

void HttpConnection_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HttpConnection);
	HX_MARK_DYNAMIC;
	HX_MARK_END_CLASS();
}

void HttpConnection_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_DYNAMIC;
}

Dynamic HttpConnection_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"processRequest") ) { return processRequest_dyn(); }
	}
	HX_CHECK_DYNAMIC_GET_FIELD(inName);
	return super::__Field(inName,inCallProp);
}

Dynamic HttpConnection_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	try { return super::__SetField(inName,inValue,inCallProp); }
	catch(Dynamic e) { HX_DYNAMIC_SET_FIELD(inName,inValue); }
	return inValue;
}

void HttpConnection_obj::__GetFields(Array< ::String> &outFields)
{
	HX_APPEND_DYNAMIC_FIELDS(outFields);
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("processRequest"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HttpConnection_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HttpConnection_obj::__mClass,"__mClass");
};

#endif

Class HttpConnection_obj::__mClass;

void HttpConnection_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.remoting.HttpConnection"), hx::TCanCast< HttpConnection_obj> ,sStaticFields,sMemberFields,
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

void HttpConnection_obj::__boot()
{
}

} // end namespace haxe
} // end namespace remoting
