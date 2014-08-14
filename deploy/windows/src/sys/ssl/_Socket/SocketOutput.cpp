#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_ssl__Socket_SocketOutput
#include <sys/ssl/_Socket/SocketOutput.h>
#endif
namespace sys{
namespace ssl{
namespace _Socket{

Void SocketOutput_obj::__construct(Dynamic s)
{
HX_STACK_FRAME("sys.ssl._Socket.SocketOutput","new",0xc0bfe785,"sys.ssl._Socket.SocketOutput.new","sys/ssl/Socket.hx",79,0xb08761c6)
HX_STACK_THIS(this)
HX_STACK_ARG(s,"s")
{
	HX_STACK_LINE(79)
	this->__s = s;
}
;
	return null();
}

//SocketOutput_obj::~SocketOutput_obj() { }

Dynamic SocketOutput_obj::__CreateEmpty() { return  new SocketOutput_obj; }
hx::ObjectPtr< SocketOutput_obj > SocketOutput_obj::__new(Dynamic s)
{  hx::ObjectPtr< SocketOutput_obj > result = new SocketOutput_obj();
	result->__construct(s);
	return result;}

Dynamic SocketOutput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SocketOutput_obj > result = new SocketOutput_obj();
	result->__construct(inArgs[0]);
	return result;}

Void SocketOutput_obj::writeByte( int c){
{
		HX_STACK_FRAME("sys.ssl._Socket.SocketOutput","writeByte",0x9388946c,"sys.ssl._Socket.SocketOutput.writeByte","sys/ssl/Socket.hx",82,0xb08761c6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(83)
		if (((this->__s == null()))){
			HX_STACK_LINE(84)
			HX_STACK_DO_THROW(HX_CSTRING("Invalid handle"));
		}
		HX_STACK_LINE(85)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(86)
			::sys::ssl::_Socket::SocketOutput_obj::socket_send_char(this->ssl,c);
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
					HX_STACK_LINE(88)
					if (((e == HX_CSTRING("Blocking")))){
						HX_STACK_LINE(89)
						HX_STACK_DO_THROW(::haxe::io::Error_obj::Blocked);
					}
					else{
						HX_STACK_LINE(91)
						HX_STACK_DO_THROW(::haxe::io::Error_obj::Custom(e));
					}
				}
			}
		}
	}
return null();
}


int SocketOutput_obj::writeBytes( ::haxe::io::Bytes buf,int pos,int len){
	HX_STACK_FRAME("sys.ssl._Socket.SocketOutput","writeBytes",0x83f94a87,"sys.ssl._Socket.SocketOutput.writeBytes","sys/ssl/Socket.hx",96,0xb08761c6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(buf,"buf")
	HX_STACK_ARG(pos,"pos")
	HX_STACK_ARG(len,"len")
	HX_STACK_LINE(96)
	try
	{
	HX_STACK_CATCHABLE(Dynamic, 0);
	{
		HX_STACK_LINE(97)
		return ::sys::ssl::_Socket::SocketOutput_obj::socket_send(this->ssl,buf->b,pos,len);
	}
	}
	catch(Dynamic __e){
		{
			HX_STACK_BEGIN_CATCH
			Dynamic e = __e;{
				HX_STACK_LINE(99)
				if (((e == HX_CSTRING("Blocking")))){
					HX_STACK_LINE(100)
					HX_STACK_DO_THROW(::haxe::io::Error_obj::Blocked);
				}
				else{
					HX_STACK_LINE(102)
					HX_STACK_DO_THROW(::haxe::io::Error_obj::Custom(e));
				}
			}
		}
	}
	HX_STACK_LINE(96)
	return (int)0;
}


Void SocketOutput_obj::close( ){
{
		HX_STACK_FRAME("sys.ssl._Socket.SocketOutput","close",0x0d5f021d,"sys.ssl._Socket.SocketOutput.close","sys/ssl/Socket.hx",106,0xb08761c6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(107)
		this->super::close();
		HX_STACK_LINE(108)
		if (((this->__s != null()))){
			HX_STACK_LINE(108)
			::sys::ssl::_Socket::SocketOutput_obj::socket_close(this->__s);
		}
	}
return null();
}


Dynamic SocketOutput_obj::socket_close;

Dynamic SocketOutput_obj::socket_send_char;

Dynamic SocketOutput_obj::socket_send;


SocketOutput_obj::SocketOutput_obj()
{
}

void SocketOutput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SocketOutput);
	HX_MARK_MEMBER_NAME(__s,"__s");
	HX_MARK_MEMBER_NAME(ssl,"ssl");
	HX_MARK_END_CLASS();
}

void SocketOutput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__s,"__s");
	HX_VISIT_MEMBER_NAME(ssl,"ssl");
}

Dynamic SocketOutput_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { return __s; }
		if (HX_FIELD_EQ(inName,"ssl") ) { return ssl; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"socket_send") ) { return socket_send; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { return socket_close; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"socket_send_char") ) { return socket_send_char; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SocketOutput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { __s=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ssl") ) { ssl=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"socket_send") ) { socket_send=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"socket_close") ) { socket_close=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"socket_send_char") ) { socket_send_char=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SocketOutput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__s"));
	outFields->push(HX_CSTRING("ssl"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("socket_close"),
	HX_CSTRING("socket_send_char"),
	HX_CSTRING("socket_send"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(SocketOutput_obj,__s),HX_CSTRING("__s")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(SocketOutput_obj,ssl),HX_CSTRING("ssl")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("__s"),
	HX_CSTRING("ssl"),
	HX_CSTRING("writeByte"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("close"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SocketOutput_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(SocketOutput_obj::socket_close,"socket_close");
	HX_MARK_MEMBER_NAME(SocketOutput_obj::socket_send_char,"socket_send_char");
	HX_MARK_MEMBER_NAME(SocketOutput_obj::socket_send,"socket_send");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SocketOutput_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(SocketOutput_obj::socket_close,"socket_close");
	HX_VISIT_MEMBER_NAME(SocketOutput_obj::socket_send_char,"socket_send_char");
	HX_VISIT_MEMBER_NAME(SocketOutput_obj::socket_send,"socket_send");
};

#endif

Class SocketOutput_obj::__mClass;

void SocketOutput_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.ssl._Socket.SocketOutput"), hx::TCanCast< SocketOutput_obj> ,sStaticFields,sMemberFields,
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

void SocketOutput_obj::__boot()
{
	socket_close= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_close"),(int)1);
	socket_send_char= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_send_char"),(int)2);
	socket_send= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_send"),(int)4);
}

} // end namespace sys
} // end namespace ssl
} // end namespace _Socket
