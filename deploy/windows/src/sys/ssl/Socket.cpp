#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_net_Host
#include <sys/net/Host.h>
#endif
#ifndef INCLUDED_sys_ssl_Socket
#include <sys/ssl/Socket.h>
#endif
#ifndef INCLUDED_sys_ssl__Socket_SocketInput
#include <sys/ssl/_Socket/SocketInput.h>
#endif
#ifndef INCLUDED_sys_ssl__Socket_SocketOutput
#include <sys/ssl/_Socket/SocketOutput.h>
#endif
namespace sys{
namespace ssl{

Void Socket_obj::__construct()
{
HX_STACK_FRAME("sys.ssl.Socket","new",0xb0189de8,"sys.ssl.Socket.new","sys/ssl/Socket.hx",136,0xb08761c6)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(138)
	this->initSSL();
	HX_STACK_LINE(139)
	Dynamic _g = ::sys::ssl::Socket_obj::socket_new(false);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(139)
	this->__s = _g;
	HX_STACK_LINE(140)
	::sys::ssl::_Socket::SocketInput _g1 = ::sys::ssl::_Socket::SocketInput_obj::__new(this->__s,null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(140)
	this->input = _g1;
	HX_STACK_LINE(141)
	::sys::ssl::_Socket::SocketOutput _g2 = ::sys::ssl::_Socket::SocketOutput_obj::__new(this->__s);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(141)
	this->output = _g2;
}
;
	return null();
}

//Socket_obj::~Socket_obj() { }

Dynamic Socket_obj::__CreateEmpty() { return  new Socket_obj; }
hx::ObjectPtr< Socket_obj > Socket_obj::__new()
{  hx::ObjectPtr< Socket_obj > result = new Socket_obj();
	result->__construct();
	return result;}

Dynamic Socket_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Socket_obj > result = new Socket_obj();
	result->__construct();
	return result;}

Void Socket_obj::connect( ::sys::net::Host host,int port){
{
		HX_STACK_FRAME("sys.ssl.Socket","connect",0x6aae6d72,"sys.ssl.Socket.connect","sys/ssl/Socket.hx",145,0xb08761c6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(host,"host")
		HX_STACK_ARG(port,"port")
		HX_STACK_LINE(145)
		try
		{
		HX_STACK_CATCHABLE(::String, 0);
		HX_STACK_CATCHABLE(Dynamic, 1);
		{
			HX_STACK_LINE(146)
			::sys::ssl::Socket_obj::socket_connect(this->__s,host->ip,port);
			HX_STACK_LINE(147)
			Dynamic _g = this->buildSSLContext();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(147)
			this->ctx = _g;
			HX_STACK_LINE(148)
			Dynamic _g1 = ::sys::ssl::Socket_obj::SSL_new(this->ctx);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(148)
			this->ssl = _g1;
			HX_STACK_LINE(149)
			this->input->ssl = this->ssl;
			HX_STACK_LINE(150)
			this->output->ssl = this->ssl;
			HX_STACK_LINE(151)
			Dynamic _g2 = ::sys::ssl::Socket_obj::BIO_NOCLOSE();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(151)
			Dynamic sbio = ::sys::ssl::Socket_obj::BIO_new_socket(this->__s,_g2);		HX_STACK_VAR(sbio,"sbio");
			HX_STACK_LINE(152)
			::sys::ssl::Socket_obj::SSL_set_bio(this->ssl,sbio,sbio);
			HX_STACK_LINE(153)
			int r = ::sys::ssl::Socket_obj::SSL_connect(this->ssl);		HX_STACK_VAR(r,"r");
		}
		}
		catch(Dynamic __e){
			if (__e.IsClass< ::String >() ){
				HX_STACK_BEGIN_CATCH
				::String s = __e;{
					HX_STACK_LINE(156)
					if (((s == HX_CSTRING("std@socket_connect")))){
						HX_STACK_LINE(157)
						::String _g3;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(157)
						try
						{
						HX_STACK_CATCHABLE(Dynamic, 0);
						{
							HX_STACK_LINE(157)
							_g3 = host->reverse();
						}
						}
						catch(Dynamic __e){
							{
								HX_STACK_BEGIN_CATCH
								Dynamic e = __e;{
									HX_STACK_LINE(157)
									_g3 = host->toString();
								}
							}
						}
						HX_STACK_LINE(157)
						::String _g4 = (HX_CSTRING("Failed to connect on ") + _g3);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(157)
						::String _g5 = (_g4 + HX_CSTRING(":"));		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(157)
						HX_STACK_DO_THROW((_g5 + port));
					}
					else{
						HX_STACK_LINE(159)
						::cpp::Lib_obj::rethrow(s);
					}
				}
			}
			else {
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
					HX_STACK_LINE(161)
					::cpp::Lib_obj::rethrow(e);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,connect,(void))

Void Socket_obj::setCertLocation( ::String file,::String folder){
{
		HX_STACK_FRAME("sys.ssl.Socket","setCertLocation",0xd189a183,"sys.ssl.Socket.setCertLocation","sys/ssl/Socket.hx",168,0xb08761c6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(file,"file")
		HX_STACK_ARG(folder,"folder")
		HX_STACK_LINE(169)
		this->certFile = file;
		HX_STACK_LINE(170)
		this->certFolder = folder;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,setCertLocation,(void))

::String Socket_obj::read( ){
	HX_STACK_FRAME("sys.ssl.Socket","read",0x681654ce,"sys.ssl.Socket.read","sys/ssl/Socket.hx",176,0xb08761c6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(177)
	::haxe::Log_obj::trace(HX_CSTRING("read"),hx::SourceInfo(HX_CSTRING("Socket.hx"),177,HX_CSTRING("sys.ssl.Socket"),HX_CSTRING("read")));
	HX_STACK_LINE(178)
	Dynamic b = ::sys::ssl::Socket_obj::socket_read(this->ssl);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(179)
	if (((b == null()))){
		HX_STACK_LINE(180)
		return HX_CSTRING("");
	}
	HX_STACK_LINE(181)
	::haxe::Log_obj::trace(HX_CSTRING("reat"),hx::SourceInfo(HX_CSTRING("Socket.hx"),181,HX_CSTRING("sys.ssl.Socket"),HX_CSTRING("read")));
	HX_STACK_LINE(182)
	return b->toString();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,read,return )

Void Socket_obj::write( ::String content){
{
		HX_STACK_FRAME("sys.ssl.Socket","write",0x9512ac67,"sys.ssl.Socket.write","sys/ssl/Socket.hx",187,0xb08761c6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(content,"content")
		HX_STACK_LINE(187)
		::sys::ssl::Socket_obj::socket_write(this->ssl,content);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,write,(void))

Void Socket_obj::close( ){
{
		HX_STACK_FRAME("sys.ssl.Socket","close",0x0d1c5740,"sys.ssl.Socket.close","sys/ssl/Socket.hx",193,0xb08761c6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(195)
		::sys::ssl::Socket_obj::SSL_close(this->ssl);
		HX_STACK_LINE(196)
		::sys::ssl::Socket_obj::SSL_CTX_close(this->ctx);
		HX_STACK_LINE(198)
		::sys::ssl::Socket_obj::socket_close(this->__s);
		HX_STACK_LINE(199)
		Dynamic _g = this->output->__s = null();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(199)
		this->input->__s = _g;
		HX_STACK_LINE(200)
		Dynamic _g1 = this->output->ssl = null();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(200)
		this->input->ssl = _g1;
		HX_STACK_LINE(201)
		this->input->close();
		HX_STACK_LINE(202)
		this->output->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,close,(void))

Void Socket_obj::shutdown( bool read,bool write){
{
		HX_STACK_FRAME("sys.ssl.Socket","shutdown",0x9e49220e,"sys.ssl.Socket.shutdown","sys/ssl/Socket.hx",250,0xb08761c6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(read,"read")
		HX_STACK_ARG(write,"write")
		HX_STACK_LINE(251)
		::sys::ssl::Socket_obj::SSL_shutdown(this->ssl);
		HX_STACK_LINE(252)
		::sys::ssl::Socket_obj::socket_shutdown(this->__s,read,write);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,shutdown,(void))

Dynamic Socket_obj::host( ){
	HX_STACK_FRAME("sys.ssl.Socket","host",0x6181d8e0,"sys.ssl.Socket.host","sys/ssl/Socket.hx",255,0xb08761c6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(256)
	Dynamic a = ::sys::ssl::Socket_obj::socket_host(this->__s);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(257)
	::sys::net::Host h = ::sys::net::Host_obj::__new(HX_CSTRING("127.0.0.1"));		HX_STACK_VAR(h,"h");
	HX_STACK_LINE(258)
	h->ip = a->__GetItem((int)0);
	struct _Function_1_1{
		inline static Dynamic Block( ::sys::net::Host &h,Dynamic &a){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","sys/ssl/Socket.hx",259,0xb08761c6)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("host") , h,false);
				__result->Add(HX_CSTRING("port") , a->__GetItem((int)1),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(259)
	return _Function_1_1::Block(h,a);
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,host,return )

Void Socket_obj::setTimeout( Float timeout){
{
		HX_STACK_FRAME("sys.ssl.Socket","setTimeout",0x84c1b297,"sys.ssl.Socket.setTimeout","sys/ssl/Socket.hx",263,0xb08761c6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(timeout,"timeout")
		HX_STACK_LINE(263)
		::sys::ssl::Socket_obj::socket_set_timeout(this->__s,timeout);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,setTimeout,(void))

Void Socket_obj::waitForRead( ){
{
		HX_STACK_FRAME("sys.ssl.Socket","waitForRead",0x433ec292,"sys.ssl.Socket.waitForRead","sys/ssl/Socket.hx",267,0xb08761c6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(267)
		::sys::ssl::Socket_obj::select(Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this)),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,waitForRead,(void))

Void Socket_obj::setBlocking( bool b){
{
		HX_STACK_FRAME("sys.ssl.Socket","setBlocking",0xbf2a84ff,"sys.ssl.Socket.setBlocking","sys/ssl/Socket.hx",271,0xb08761c6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(b,"b")
		HX_STACK_LINE(271)
		::sys::ssl::Socket_obj::socket_set_blocking(this->__s,b);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,setBlocking,(void))

Void Socket_obj::setFastSend( bool b){
{
		HX_STACK_FRAME("sys.ssl.Socket","setFastSend",0x2de5594e,"sys.ssl.Socket.setFastSend","sys/ssl/Socket.hx",275,0xb08761c6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(b,"b")
		HX_STACK_LINE(275)
		::sys::ssl::Socket_obj::socket_set_fast_send(this->__s,b);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Socket_obj,setFastSend,(void))

Void Socket_obj::initSSL( ){
{
		HX_STACK_FRAME("sys.ssl.Socket","initSSL",0x20bc8424,"sys.ssl.Socket.initSSL","sys/ssl/Socket.hx",278,0xb08761c6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(279)
		::sys::ssl::Socket_obj::SSL_library_init();
		HX_STACK_LINE(280)
		::sys::ssl::Socket_obj::SSL_load_error_strings();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,initSSL,(void))

Dynamic Socket_obj::buildSSLContext( ){
	HX_STACK_FRAME("sys.ssl.Socket","buildSSLContext",0xc7d561d9,"sys.ssl.Socket.buildSSLContext","sys/ssl/Socket.hx",283,0xb08761c6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(284)
	Dynamic _g = ::sys::ssl::Socket_obj::SSLv23_client_method();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(284)
	Dynamic ctx = ::sys::ssl::Socket_obj::SSL_CTX_new(_g);		HX_STACK_VAR(ctx,"ctx");
	HX_STACK_LINE(286)
	if (((bool((this->certFile != null())) && bool((this->certFolder != null()))))){
		HX_STACK_LINE(287)
		int r = ::sys::ssl::Socket_obj::SSL_CTX_load_verify_locations(ctx,this->certFile,this->certFolder);		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(288)
		if (((r == (int)0))){
			HX_STACK_LINE(289)
			HX_STACK_DO_THROW(HX_CSTRING("Failed to load certificates"));
		}
		HX_STACK_LINE(290)
		::sys::ssl::Socket_obj::SSL_CTX_set_verify(ctx);
	}
	HX_STACK_LINE(292)
	return ctx;
}


HX_DEFINE_DYNAMIC_FUNC0(Socket_obj,buildSSLContext,return )

Dynamic Socket_obj::select( Array< ::Dynamic > read,Array< ::Dynamic > write,Array< ::Dynamic > others,Dynamic timeout){
	HX_STACK_FRAME("sys.ssl.Socket","select",0xc7917274,"sys.ssl.Socket.select","sys/ssl/Socket.hx",295,0xb08761c6)
	HX_STACK_ARG(read,"read")
	HX_STACK_ARG(write,"write")
	HX_STACK_ARG(others,"others")
	HX_STACK_ARG(timeout,"timeout")
	HX_STACK_LINE(296)
	Array< ::Dynamic > neko_array = ::sys::ssl::Socket_obj::socket_select(read,write,others,timeout);		HX_STACK_VAR(neko_array,"neko_array");
	HX_STACK_LINE(297)
	if (((neko_array == null()))){
		HX_STACK_LINE(298)
		HX_STACK_DO_THROW(HX_CSTRING("Select error"));
	}
	struct _Function_1_1{
		inline static Dynamic Block( Array< ::Dynamic > &neko_array){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","sys/ssl/Socket.hx",299,0xb08761c6)
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("read") , neko_array->__get((int)0).StaticCast< Array< ::Dynamic > >(),false);
				__result->Add(HX_CSTRING("write") , neko_array->__get((int)1).StaticCast< Array< ::Dynamic > >(),false);
				__result->Add(HX_CSTRING("others") , neko_array->__get((int)2).StaticCast< Array< ::Dynamic > >(),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(299)
	return _Function_1_1::Block(neko_array);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Socket_obj,select,return )

Dynamic Socket_obj::SSL_library_init;

Dynamic Socket_obj::SSL_load_error_strings;

Dynamic Socket_obj::SSL_new;

Dynamic Socket_obj::SSL_close;

Dynamic Socket_obj::SSL_connect;

Dynamic Socket_obj::SSL_shutdown;

Dynamic Socket_obj::SSL_free;

Dynamic Socket_obj::SSL_set_bio;

Dynamic Socket_obj::SSLv23_client_method;

Dynamic Socket_obj::TLSv1_client_method;

Dynamic Socket_obj::SSL_CTX_new;

Dynamic Socket_obj::SSL_CTX_close;

Dynamic Socket_obj::SSL_CTX_load_verify_locations;

Dynamic Socket_obj::SSL_CTX_set_verify;

Dynamic Socket_obj::SSL_CTX_use_certificate_file;

Dynamic Socket_obj::BIO_new_socket;

Dynamic Socket_obj::BIO_NOCLOSE;

Dynamic Socket_obj::socket_read;

Dynamic Socket_obj::socket_write;

Dynamic Socket_obj::ssl_accept;

Dynamic Socket_obj::lib( ::String f,hx::Null< int >  __o_args){
int args = __o_args.Default(0);
	HX_STACK_FRAME("sys.ssl.Socket","lib",0xb0171ccd,"sys.ssl.Socket.lib","sys/ssl/Socket.hx",335,0xb08761c6)
	HX_STACK_ARG(f,"f")
	HX_STACK_ARG(args,"args")
{
		HX_STACK_LINE(335)
		return ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),(HX_CSTRING("hxssl_") + f),args);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Socket_obj,lib,return )

Dynamic Socket_obj::socket_new;

Dynamic Socket_obj::socket_close;

Dynamic Socket_obj::socket_connect;

Dynamic Socket_obj::socket_listen;

Dynamic Socket_obj::socket_select;

Dynamic Socket_obj::socket_bind;

Dynamic Socket_obj::socket_accept;

Dynamic Socket_obj::socket_peer;

Dynamic Socket_obj::socket_host;

Dynamic Socket_obj::socket_set_timeout;

Dynamic Socket_obj::socket_shutdown;

Dynamic Socket_obj::socket_set_blocking;

Dynamic Socket_obj::socket_set_fast_send;


Socket_obj::Socket_obj()
{
}

void Socket_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Socket);
	HX_MARK_MEMBER_NAME(input,"input");
	HX_MARK_MEMBER_NAME(output,"output");
	HX_MARK_MEMBER_NAME(custom,"custom");
	HX_MARK_MEMBER_NAME(__s,"__s");
	HX_MARK_MEMBER_NAME(ctx,"ctx");
	HX_MARK_MEMBER_NAME(ssl,"ssl");
	HX_MARK_MEMBER_NAME(certFile,"certFile");
	HX_MARK_MEMBER_NAME(certFolder,"certFolder");
	HX_MARK_END_CLASS();
}

void Socket_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(input,"input");
	HX_VISIT_MEMBER_NAME(output,"output");
	HX_VISIT_MEMBER_NAME(custom,"custom");
	HX_VISIT_MEMBER_NAME(__s,"__s");
	HX_VISIT_MEMBER_NAME(ctx,"ctx");
	HX_VISIT_MEMBER_NAME(ssl,"ssl");
	HX_VISIT_MEMBER_NAME(certFile,"certFile");
	HX_VISIT_MEMBER_NAME(certFolder,"certFolder");
}

Dynamic Socket_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"lib") ) { return lib_dyn(); }
		if (HX_FIELD_EQ(inName,"__s") ) { return __s; }
		if (HX_FIELD_EQ(inName,"ctx") ) { return ctx; }
		if (HX_FIELD_EQ(inName,"ssl") ) { return ssl; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"read") ) { return read_dyn(); }
		if (HX_FIELD_EQ(inName,"host") ) { return host_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { return input; }
		if (HX_FIELD_EQ(inName,"write") ) { return write_dyn(); }
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"select") ) { return select_dyn(); }
		if (HX_FIELD_EQ(inName,"output") ) { return output; }
		if (HX_FIELD_EQ(inName,"custom") ) { return custom; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"SSL_new") ) { return SSL_new; }
		if (HX_FIELD_EQ(inName,"connect") ) { return connect_dyn(); }
		if (HX_FIELD_EQ(inName,"initSSL") ) { return initSSL_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"SSL_free") ) { return SSL_free; }
		if (HX_FIELD_EQ(inName,"certFile") ) { return certFile; }
		if (HX_FIELD_EQ(inName,"shutdown") ) { return shutdown_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"SSL_close") ) { return SSL_close; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"ssl_accept") ) { return ssl_accept; }
		if (HX_FIELD_EQ(inName,"socket_new") ) { return socket_new; }
		if (HX_FIELD_EQ(inName,"certFolder") ) { return certFolder; }
		if (HX_FIELD_EQ(inName,"setTimeout") ) { return setTimeout_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SSL_connect") ) { return SSL_connect; }
		if (HX_FIELD_EQ(inName,"SSL_set_bio") ) { return SSL_set_bio; }
		if (HX_FIELD_EQ(inName,"SSL_CTX_new") ) { return SSL_CTX_new; }
		if (HX_FIELD_EQ(inName,"BIO_NOCLOSE") ) { return BIO_NOCLOSE; }
		if (HX_FIELD_EQ(inName,"socket_read") ) { return socket_read; }
		if (HX_FIELD_EQ(inName,"socket_bind") ) { return socket_bind; }
		if (HX_FIELD_EQ(inName,"socket_peer") ) { return socket_peer; }
		if (HX_FIELD_EQ(inName,"socket_host") ) { return socket_host; }
		if (HX_FIELD_EQ(inName,"waitForRead") ) { return waitForRead_dyn(); }
		if (HX_FIELD_EQ(inName,"setBlocking") ) { return setBlocking_dyn(); }
		if (HX_FIELD_EQ(inName,"setFastSend") ) { return setFastSend_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"SSL_shutdown") ) { return SSL_shutdown; }
		if (HX_FIELD_EQ(inName,"socket_write") ) { return socket_write; }
		if (HX_FIELD_EQ(inName,"socket_close") ) { return socket_close; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"SSL_CTX_close") ) { return SSL_CTX_close; }
		if (HX_FIELD_EQ(inName,"socket_listen") ) { return socket_listen; }
		if (HX_FIELD_EQ(inName,"socket_select") ) { return socket_select; }
		if (HX_FIELD_EQ(inName,"socket_accept") ) { return socket_accept; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"BIO_new_socket") ) { return BIO_new_socket; }
		if (HX_FIELD_EQ(inName,"socket_connect") ) { return socket_connect; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"socket_shutdown") ) { return socket_shutdown; }
		if (HX_FIELD_EQ(inName,"setCertLocation") ) { return setCertLocation_dyn(); }
		if (HX_FIELD_EQ(inName,"buildSSLContext") ) { return buildSSLContext_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"SSL_library_init") ) { return SSL_library_init; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"SSL_CTX_set_verify") ) { return SSL_CTX_set_verify; }
		if (HX_FIELD_EQ(inName,"socket_set_timeout") ) { return socket_set_timeout; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"TLSv1_client_method") ) { return TLSv1_client_method; }
		if (HX_FIELD_EQ(inName,"socket_set_blocking") ) { return socket_set_blocking; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"SSLv23_client_method") ) { return SSLv23_client_method; }
		if (HX_FIELD_EQ(inName,"socket_set_fast_send") ) { return socket_set_fast_send; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"SSL_load_error_strings") ) { return SSL_load_error_strings; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"SSL_CTX_use_certificate_file") ) { return SSL_CTX_use_certificate_file; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"SSL_CTX_load_verify_locations") ) { return SSL_CTX_load_verify_locations; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Socket_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__s") ) { __s=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ctx") ) { ctx=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ssl") ) { ssl=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { input=inValue.Cast< ::sys::ssl::_Socket::SocketInput >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"output") ) { output=inValue.Cast< ::sys::ssl::_Socket::SocketOutput >(); return inValue; }
		if (HX_FIELD_EQ(inName,"custom") ) { custom=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"SSL_new") ) { SSL_new=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"SSL_free") ) { SSL_free=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"certFile") ) { certFile=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"SSL_close") ) { SSL_close=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"ssl_accept") ) { ssl_accept=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_new") ) { socket_new=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"certFolder") ) { certFolder=inValue.Cast< ::String >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SSL_connect") ) { SSL_connect=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SSL_set_bio") ) { SSL_set_bio=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SSL_CTX_new") ) { SSL_CTX_new=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BIO_NOCLOSE") ) { BIO_NOCLOSE=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_read") ) { socket_read=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_bind") ) { socket_bind=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_peer") ) { socket_peer=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_host") ) { socket_host=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"SSL_shutdown") ) { SSL_shutdown=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_write") ) { socket_write=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_close") ) { socket_close=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"SSL_CTX_close") ) { SSL_CTX_close=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_listen") ) { socket_listen=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_select") ) { socket_select=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_accept") ) { socket_accept=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"BIO_new_socket") ) { BIO_new_socket=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_connect") ) { socket_connect=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"socket_shutdown") ) { socket_shutdown=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"SSL_library_init") ) { SSL_library_init=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"SSL_CTX_set_verify") ) { SSL_CTX_set_verify=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_set_timeout") ) { socket_set_timeout=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"TLSv1_client_method") ) { TLSv1_client_method=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_set_blocking") ) { socket_set_blocking=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"SSLv23_client_method") ) { SSLv23_client_method=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"socket_set_fast_send") ) { socket_set_fast_send=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"SSL_load_error_strings") ) { SSL_load_error_strings=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 28:
		if (HX_FIELD_EQ(inName,"SSL_CTX_use_certificate_file") ) { SSL_CTX_use_certificate_file=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 29:
		if (HX_FIELD_EQ(inName,"SSL_CTX_load_verify_locations") ) { SSL_CTX_load_verify_locations=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Socket_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("input"));
	outFields->push(HX_CSTRING("output"));
	outFields->push(HX_CSTRING("custom"));
	outFields->push(HX_CSTRING("__s"));
	outFields->push(HX_CSTRING("ctx"));
	outFields->push(HX_CSTRING("ssl"));
	outFields->push(HX_CSTRING("certFile"));
	outFields->push(HX_CSTRING("certFolder"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("select"),
	HX_CSTRING("SSL_library_init"),
	HX_CSTRING("SSL_load_error_strings"),
	HX_CSTRING("SSL_new"),
	HX_CSTRING("SSL_close"),
	HX_CSTRING("SSL_connect"),
	HX_CSTRING("SSL_shutdown"),
	HX_CSTRING("SSL_free"),
	HX_CSTRING("SSL_set_bio"),
	HX_CSTRING("SSLv23_client_method"),
	HX_CSTRING("TLSv1_client_method"),
	HX_CSTRING("SSL_CTX_new"),
	HX_CSTRING("SSL_CTX_close"),
	HX_CSTRING("SSL_CTX_load_verify_locations"),
	HX_CSTRING("SSL_CTX_set_verify"),
	HX_CSTRING("SSL_CTX_use_certificate_file"),
	HX_CSTRING("BIO_new_socket"),
	HX_CSTRING("BIO_NOCLOSE"),
	HX_CSTRING("socket_read"),
	HX_CSTRING("socket_write"),
	HX_CSTRING("ssl_accept"),
	HX_CSTRING("lib"),
	HX_CSTRING("socket_new"),
	HX_CSTRING("socket_close"),
	HX_CSTRING("socket_connect"),
	HX_CSTRING("socket_listen"),
	HX_CSTRING("socket_select"),
	HX_CSTRING("socket_bind"),
	HX_CSTRING("socket_accept"),
	HX_CSTRING("socket_peer"),
	HX_CSTRING("socket_host"),
	HX_CSTRING("socket_set_timeout"),
	HX_CSTRING("socket_shutdown"),
	HX_CSTRING("socket_set_blocking"),
	HX_CSTRING("socket_set_fast_send"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::sys::ssl::_Socket::SocketInput*/ ,(int)offsetof(Socket_obj,input),HX_CSTRING("input")},
	{hx::fsObject /*::sys::ssl::_Socket::SocketOutput*/ ,(int)offsetof(Socket_obj,output),HX_CSTRING("output")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Socket_obj,custom),HX_CSTRING("custom")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Socket_obj,__s),HX_CSTRING("__s")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Socket_obj,ctx),HX_CSTRING("ctx")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Socket_obj,ssl),HX_CSTRING("ssl")},
	{hx::fsString,(int)offsetof(Socket_obj,certFile),HX_CSTRING("certFile")},
	{hx::fsString,(int)offsetof(Socket_obj,certFolder),HX_CSTRING("certFolder")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("input"),
	HX_CSTRING("output"),
	HX_CSTRING("custom"),
	HX_CSTRING("__s"),
	HX_CSTRING("ctx"),
	HX_CSTRING("ssl"),
	HX_CSTRING("certFile"),
	HX_CSTRING("certFolder"),
	HX_CSTRING("connect"),
	HX_CSTRING("setCertLocation"),
	HX_CSTRING("read"),
	HX_CSTRING("write"),
	HX_CSTRING("close"),
	HX_CSTRING("shutdown"),
	HX_CSTRING("host"),
	HX_CSTRING("setTimeout"),
	HX_CSTRING("waitForRead"),
	HX_CSTRING("setBlocking"),
	HX_CSTRING("setFastSend"),
	HX_CSTRING("initSSL"),
	HX_CSTRING("buildSSLContext"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Socket_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Socket_obj::SSL_library_init,"SSL_library_init");
	HX_MARK_MEMBER_NAME(Socket_obj::SSL_load_error_strings,"SSL_load_error_strings");
	HX_MARK_MEMBER_NAME(Socket_obj::SSL_new,"SSL_new");
	HX_MARK_MEMBER_NAME(Socket_obj::SSL_close,"SSL_close");
	HX_MARK_MEMBER_NAME(Socket_obj::SSL_connect,"SSL_connect");
	HX_MARK_MEMBER_NAME(Socket_obj::SSL_shutdown,"SSL_shutdown");
	HX_MARK_MEMBER_NAME(Socket_obj::SSL_free,"SSL_free");
	HX_MARK_MEMBER_NAME(Socket_obj::SSL_set_bio,"SSL_set_bio");
	HX_MARK_MEMBER_NAME(Socket_obj::SSLv23_client_method,"SSLv23_client_method");
	HX_MARK_MEMBER_NAME(Socket_obj::TLSv1_client_method,"TLSv1_client_method");
	HX_MARK_MEMBER_NAME(Socket_obj::SSL_CTX_new,"SSL_CTX_new");
	HX_MARK_MEMBER_NAME(Socket_obj::SSL_CTX_close,"SSL_CTX_close");
	HX_MARK_MEMBER_NAME(Socket_obj::SSL_CTX_load_verify_locations,"SSL_CTX_load_verify_locations");
	HX_MARK_MEMBER_NAME(Socket_obj::SSL_CTX_set_verify,"SSL_CTX_set_verify");
	HX_MARK_MEMBER_NAME(Socket_obj::SSL_CTX_use_certificate_file,"SSL_CTX_use_certificate_file");
	HX_MARK_MEMBER_NAME(Socket_obj::BIO_new_socket,"BIO_new_socket");
	HX_MARK_MEMBER_NAME(Socket_obj::BIO_NOCLOSE,"BIO_NOCLOSE");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_read,"socket_read");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_write,"socket_write");
	HX_MARK_MEMBER_NAME(Socket_obj::ssl_accept,"ssl_accept");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_new,"socket_new");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_close,"socket_close");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_connect,"socket_connect");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_listen,"socket_listen");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_select,"socket_select");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_bind,"socket_bind");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_accept,"socket_accept");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_peer,"socket_peer");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_host,"socket_host");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_set_timeout,"socket_set_timeout");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_shutdown,"socket_shutdown");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_set_blocking,"socket_set_blocking");
	HX_MARK_MEMBER_NAME(Socket_obj::socket_set_fast_send,"socket_set_fast_send");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Socket_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSL_library_init,"SSL_library_init");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSL_load_error_strings,"SSL_load_error_strings");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSL_new,"SSL_new");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSL_close,"SSL_close");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSL_connect,"SSL_connect");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSL_shutdown,"SSL_shutdown");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSL_free,"SSL_free");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSL_set_bio,"SSL_set_bio");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSLv23_client_method,"SSLv23_client_method");
	HX_VISIT_MEMBER_NAME(Socket_obj::TLSv1_client_method,"TLSv1_client_method");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSL_CTX_new,"SSL_CTX_new");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSL_CTX_close,"SSL_CTX_close");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSL_CTX_load_verify_locations,"SSL_CTX_load_verify_locations");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSL_CTX_set_verify,"SSL_CTX_set_verify");
	HX_VISIT_MEMBER_NAME(Socket_obj::SSL_CTX_use_certificate_file,"SSL_CTX_use_certificate_file");
	HX_VISIT_MEMBER_NAME(Socket_obj::BIO_new_socket,"BIO_new_socket");
	HX_VISIT_MEMBER_NAME(Socket_obj::BIO_NOCLOSE,"BIO_NOCLOSE");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_read,"socket_read");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_write,"socket_write");
	HX_VISIT_MEMBER_NAME(Socket_obj::ssl_accept,"ssl_accept");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_new,"socket_new");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_close,"socket_close");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_connect,"socket_connect");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_listen,"socket_listen");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_select,"socket_select");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_bind,"socket_bind");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_accept,"socket_accept");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_peer,"socket_peer");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_host,"socket_host");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_set_timeout,"socket_set_timeout");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_shutdown,"socket_shutdown");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_set_blocking,"socket_set_blocking");
	HX_VISIT_MEMBER_NAME(Socket_obj::socket_set_fast_send,"socket_set_fast_send");
};

#endif

Class Socket_obj::__mClass;

void Socket_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.ssl.Socket"), hx::TCanCast< Socket_obj> ,sStaticFields,sMemberFields,
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

void Socket_obj::__boot()
{
struct _Function_0_1{
	inline static Dynamic Block( ){
		HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","sys/ssl/Socket.hx",306,0xb08761c6)
		{
			HX_STACK_LINE(306)
			int args = (int)0;		HX_STACK_VAR(args,"args");
			HX_STACK_LINE(306)
			return ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_library_init"),args);
		}
		return null();
	}
};
	SSL_library_init= _Function_0_1::Block();
struct _Function_0_2{
	inline static Dynamic Block( ){
		HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","sys/ssl/Socket.hx",307,0xb08761c6)
		{
			HX_STACK_LINE(307)
			int args = (int)0;		HX_STACK_VAR(args,"args");
			HX_STACK_LINE(307)
			return ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_load_error_strings"),args);
		}
		return null();
	}
};
	SSL_load_error_strings= _Function_0_2::Block();
	SSL_new= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_new"),(int)1);
	SSL_close= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_close"),(int)1);
	SSL_connect= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_connect"),(int)1);
	SSL_shutdown= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_shutdown"),(int)1);
	SSL_free= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_free"),(int)1);
	SSL_set_bio= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_set_bio"),(int)3);
struct _Function_0_3{
	inline static Dynamic Block( ){
		HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","sys/ssl/Socket.hx",317,0xb08761c6)
		{
			HX_STACK_LINE(317)
			int args = (int)0;		HX_STACK_VAR(args,"args");
			HX_STACK_LINE(317)
			return ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSLv23_client_method"),args);
		}
		return null();
	}
};
	SSLv23_client_method= _Function_0_3::Block();
struct _Function_0_4{
	inline static Dynamic Block( ){
		HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","sys/ssl/Socket.hx",318,0xb08761c6)
		{
			HX_STACK_LINE(318)
			int args = (int)0;		HX_STACK_VAR(args,"args");
			HX_STACK_LINE(318)
			return ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_TLSv1_client_method"),args);
		}
		return null();
	}
};
	TLSv1_client_method= _Function_0_4::Block();
	SSL_CTX_new= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_CTX_new"),(int)1);
	SSL_CTX_close= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_CTX_close"),(int)1);
	SSL_CTX_load_verify_locations= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_CTX_load_verify_locations"),(int)3);
	SSL_CTX_set_verify= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_CTX_set_verify"),(int)1);
	SSL_CTX_use_certificate_file= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_SSL_CTX_use_certificate_file"),(int)3);
	BIO_new_socket= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_BIO_new_socket"),(int)2);
	BIO_NOCLOSE= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl_BIO_NOCLOSE"),(int)0);
	socket_read= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl___SSL_read"),(int)1);
	socket_write= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl___SSL_write"),(int)2);
	ssl_accept= ::cpp::Lib_obj::load(HX_CSTRING("hxssl"),HX_CSTRING("hxssl___SSL_accept"),(int)1);
	socket_new= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_new"),(int)1);
	socket_close= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_close"),(int)1);
	socket_connect= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_connect"),(int)3);
	socket_listen= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_listen"),(int)2);
	socket_select= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_select"),(int)4);
	socket_bind= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_bind"),(int)3);
	socket_accept= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_accept"),(int)1);
	socket_peer= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_peer"),(int)1);
	socket_host= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_host"),(int)1);
	socket_set_timeout= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_set_timeout"),(int)2);
	socket_shutdown= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_shutdown"),(int)3);
	socket_set_blocking= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("socket_set_blocking"),(int)2);
	socket_set_fast_send= ::cpp::Lib_obj::loadLazy(HX_CSTRING("std"),HX_CSTRING("socket_set_fast_send"),(int)2);
}

} // end namespace sys
} // end namespace ssl
