#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_sys_ssl__Socket_SocketInput
#include <sys/ssl/_Socket/SocketInput.h>
#endif
namespace sys{
namespace ssl{
namespace _Socket{

Void SocketInput_obj::__construct(Dynamic s,Dynamic ssl)
{
HX_STACK_FRAME("sys.ssl._Socket.SocketInput","new",0x0d9c972a,"sys.ssl._Socket.SocketInput.new","sys/ssl/Socket.hx",27,0xb08761c6)
HX_STACK_THIS(this)
HX_STACK_ARG(s,"s")
HX_STACK_ARG(ssl,"ssl")
{
	HX_STACK_LINE(28)
	this->__s = s;
	HX_STACK_LINE(29)
	this->ssl = ssl;
}
;
	return null();
}

//SocketInput_obj::~SocketInput_obj() { }

Dynamic SocketInput_obj::__CreateEmpty() { return  new SocketInput_obj; }
hx::ObjectPtr< SocketInput_obj > SocketInput_obj::__new(Dynamic s,Dynamic ssl)
{  hx::ObjectPtr< SocketInput_obj > result = new SocketInput_obj();
	result->__construct(s,ssl);
	return result;}

Dynamic SocketInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SocketInput_obj > result = new SocketInput_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

int SocketInput_obj::readByte( ){
	HX_STACK_FRAME("sys.ssl._Socket.SocketInput","readByte",0xa45b5674,"sys.ssl._Socket.SocketInput.readByte","sys/ssl/Socket.hx",33,0xb08761c6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(33)
	try
	{
	HX_STACK_CATCHABLE(Dynamic, 0);
	{
		HX_STACK_LINE(34)
		return ::sys::ssl::_Socket::SocketInput_obj::socket_recv_char(this->ssl);
	}
	}
	catch(Dynamic __e){
		{
			HX_STACK_BEGIN_CATCH
			Dynamic e = __e;{
				HX_STACK_LINE(36)
				if (((e == HX_CSTRING("Blocking")))){
					HX_STACK_LINE(37)
					HX_STACK_DO_THROW(::haxe::io::Error_obj::Blocked);
				}
				else{
					HX_STACK_LINE(38)
					if (((this->__s == null()))){
						HX_STACK_LINE(39)
						HX_STACK_DO_THROW(::haxe::io::Error_obj::Custom(e));
					}
					else{
						HX_STACK_LINE(41)
						HX_STACK_DO_THROW(::haxe::io::Eof_obj::__new());
					}
				}
			}
		}
	}
	HX_STACK_LINE(33)
	return (int)0;
}


int SocketInput_obj::readBytes( ::haxe::io::Bytes buf,int pos,int len){
	HX_STACK_FRAME("sys.ssl._Socket.SocketInput","readBytes",0x2b904f7f,"sys.ssl._Socket.SocketInput.readBytes","sys/ssl/Socket.hx",45,0xb08761c6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(buf,"buf")
	HX_STACK_ARG(pos,"pos")
	HX_STACK_ARG(len,"len")
	HX_STACK_LINE(46)
	int r;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(47)
	if (((bool((this->ssl == null())) || bool((this->__s == null()))))){
		HX_STACK_LINE(48)
		HX_STACK_DO_THROW(HX_CSTRING("Invalid handle"));
	}
	HX_STACK_LINE(49)
	try
	{
	HX_STACK_CATCHABLE(Dynamic, 0);
	{
		HX_STACK_LINE(50)
		int _g = ::sys::ssl::_Socket::SocketInput_obj::socket_recv(this->ssl,buf->b,pos,len);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(50)
		r = _g;
	}
	}
	catch(Dynamic __e){
		{
			HX_STACK_BEGIN_CATCH
			Dynamic e = __e;{
				HX_STACK_LINE(52)
				if (((e == HX_CSTRING("Blocking")))){
					HX_STACK_LINE(53)
					HX_STACK_DO_THROW(::haxe::io::Error_obj::Blocked);
				}
				else{
					HX_STACK_LINE(55)
					HX_STACK_DO_THROW(::haxe::io::Error_obj::Custom(e));
				}
			}
		}
	}
	HX_STACK_LINE(57)
	if (((r == (int)0))){
		HX_STACK_LINE(58)
		HX_STACK_DO_THROW(::haxe::io::Eof_obj::__new());
	}
	HX_STACK_LINE(59)
	return r;
}


Void SocketInput_obj::close( ){
{
		HX_STACK_FRAME("sys.ssl._Socket.SocketInput","close",0xce82a502,"sys.ssl._Socket.SocketInput.close","sys/ssl/Socket.hx",62,0xb08761c6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(63)
		this->super::close();
		HX_STACK_LINE(64)
		if (((this->__s != null()))){
			HX_STACK_LINE(64)
			::sys::ssl::_Socket::SocketInput_obj::socket_close(this->__s);
		}
	}
return null();
}


Dynamic SocketInput_obj::socket_recv;

Dynamic SocketInput_obj::socket_recv_char;

Dynamic SocketInput_obj::socket_close;


SocketInput_obj::SocketInput_obj()
{
}

void SocketInput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SocketInput);
	HX_MARK_MEMBER_NAME(__s,"__s");
	HX_MARK_MEMBER_NAME(ssl,"ssl");
	HX_MARK_END_CLASS();
}

void SocketInput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__s,"__s");
	HX_VISIT_MEMBER_NAME(ssl,"ssl");
}

Dynamic SocketInput_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { return __s; }
		if (HX_FIELD_EQ(inName,"ssl") ) { return ssl; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"readBytes") ) { return readBytes_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"socket_recv") ) { return socket_recv; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { return socket_close; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"socket_recv_char") ) { return socket_recv_char; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SocketInput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { __s=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ssl") ) { ssl=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"socket_recv") ) { socket_recv=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { socket_close=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"socket_recv_char") ) { socket_recv_char=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SocketInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__s"));
	outFields->push(HX_CSTRING("ssl"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("socket_recv"),
	HX_CSTRING("socket_recv_char"),
	HX_CSTRING("socket_close"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(SocketInput_obj,__s),HX_CSTRING("__s")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(SocketInput_obj,ssl),HX_CSTRING("ssl")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("__s"),
	HX_CSTRING("ssl"),
	HX_CSTRING("readByte"),
	HX_CSTRING("readBytes"),
	HX_CSTRING("close"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SocketInput_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SocketInput_obj::socket_recv,"socket_recv");
	HX_MARK_MEMBER_NAME(SocketInput_obj::socket_recv_char,"socket_recv_char");
	HX_MARK_MEMBER_NAME(SocketInput_obj::socket_close,"socket_close");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SocketInput_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SocketInput_obj::socket_recv,"socket_recv");
	HX_VISIT_MEMBER_NAME(SocketInput_obj::socket_recv_char,"socket_recv_char");
	HX_VISIT_MEMBER_NAME(SocketInput_obj::socket_close,"socket_close");
};

#endif

Class SocketInput_obj::__mClass;

void SocketInput_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.ssl._Socket.SocketInput"), hx::TCanCast< SocketInput_obj> ,sStaticFields,sMemberFields,
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

void SocketInput_obj::__boot()
{
	socket_recv= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_recv"),(int)4);
	socket_recv_char= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_recv_char"),(int)1);
	socket_close= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_close"),(int)1);
}

} // end namespace sys
} // end namespace ssl
} // end namespace _Socket
