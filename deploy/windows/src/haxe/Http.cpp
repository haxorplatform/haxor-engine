#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxe_Http
#include <haxe/Http.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_BytesBuffer
#include <haxe/io/BytesBuffer.h>
#endif
#ifndef INCLUDED_haxe_io_BytesOutput
#include <haxe/io/BytesOutput.h>
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
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_net_Host
#include <sys/net/Host.h>
#endif
#ifndef INCLUDED_sys_net_Socket
#include <sys/net/Socket.h>
#endif
namespace haxe{

Void Http_obj::__construct(::String url)
{
HX_STACK_FRAME("haxe.Http","new",0x57ac51e2,"haxe.Http.new","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Http.hx",88,0xddb358ba)
HX_STACK_THIS(this)
HX_STACK_ARG(url,"url")
{
	HX_STACK_LINE(89)
	this->url = url;
	HX_STACK_LINE(90)
	::List _g = ::List_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(90)
	this->headers = _g;
	HX_STACK_LINE(91)
	::List _g1 = ::List_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(91)
	this->params = _g1;
	HX_STACK_LINE(96)
	this->cnxTimeout = (int)10;
}
;
	return null();
}

//Http_obj::~Http_obj() { }

Dynamic Http_obj::__CreateEmpty() { return  new Http_obj; }
hx::ObjectPtr< Http_obj > Http_obj::__new(::String url)
{  hx::ObjectPtr< Http_obj > result = new Http_obj();
	result->__construct(url);
	return result;}

Dynamic Http_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Http_obj > result = new Http_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Http_obj::request( Dynamic post){
{
		HX_STACK_FRAME("haxe.Http","request",0xb2c949d1,"haxe.Http.request","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Http.hx",197,0xddb358ba)
		HX_STACK_THIS(this)
		HX_STACK_ARG(post,"post")
		HX_STACK_LINE(198)
		::haxe::Http me = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(me,"me");
		HX_STACK_LINE(363)
		Array< ::Dynamic > me1 = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(me1,"me1");
		HX_STACK_LINE(364)
		Array< ::Dynamic > output = Array_obj< ::Dynamic >::__new().Add(::haxe::io::BytesOutput_obj::__new());		HX_STACK_VAR(output,"output");
		HX_STACK_LINE(365)
		Dynamic old = Dynamic( Array_obj<Dynamic>::__new().Add(this->onError_dyn()));		HX_STACK_VAR(old,"old");
		HX_STACK_LINE(366)
		Array< bool > err = Array_obj< bool >::__new().Add(false);		HX_STACK_VAR(err,"err");

		HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_1_1,Dynamic,old,Array< ::Dynamic >,me1,Array< ::Dynamic >,output,Array< bool >,err)
		Void run(::String e){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Http.hx",367,0xddb358ba)
			HX_STACK_ARG(e,"e")
			{
				HX_STACK_LINE(371)
				me1->__get((int)0).StaticCast< ::haxe::Http >()->responseData = output->__get((int)0).StaticCast< ::haxe::io::BytesOutput >()->getBytes()->toString();
				HX_STACK_LINE(373)
				err[(int)0] = true;
				HX_STACK_LINE(374)
				old->__GetItem((int)0)(e).Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(367)
		this->onError =  Dynamic(new _Function_1_1(old,me1,output,err));
		HX_STACK_LINE(376)
		this->customRequest(post,output->__get((int)0).StaticCast< ::haxe::io::BytesOutput >(),null(),null());
		HX_STACK_LINE(377)
		if ((!(err->__get((int)0)))){
			HX_STACK_LINE(381)
			::String _g = output->__get((int)0).StaticCast< ::haxe::io::BytesOutput >()->getBytes()->toString();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(381)
			::String _g1 = me1->__get((int)0).StaticCast< ::haxe::Http >()->responseData = _g;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(381)
			me1->__get((int)0).StaticCast< ::haxe::Http >()->onData(_g1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Http_obj,request,(void))

Void Http_obj::customRequest( bool post,::haxe::io::Output api,Dynamic sock,::String method){
{
		HX_STACK_FRAME("haxe.Http","customRequest",0x68e97fa0,"haxe.Http.customRequest","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Http.hx",400,0xddb358ba)
		HX_STACK_THIS(this)
		HX_STACK_ARG(post,"post")
		HX_STACK_ARG(api,"api")
		HX_STACK_ARG(sock,"sock")
		HX_STACK_ARG(method,"method")
		HX_STACK_LINE(401)
		this->responseData = null();
		HX_STACK_LINE(402)
		::EReg url_regexp = ::EReg_obj::__new(HX_CSTRING("^(https?://)?([a-zA-Z\\.0-9-]+)(:[0-9]+)?(.*)$"),HX_CSTRING(""));		HX_STACK_VAR(url_regexp,"url_regexp");
		HX_STACK_LINE(403)
		if ((!(url_regexp->match(this->url)))){
			HX_STACK_LINE(404)
			this->onError(HX_CSTRING("Invalid URL"));
			HX_STACK_LINE(405)
			return null();
		}
		HX_STACK_LINE(407)
		::String _g = url_regexp->matched((int)1);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(407)
		bool secure = (_g == HX_CSTRING("https://"));		HX_STACK_VAR(secure,"secure");
		HX_STACK_LINE(408)
		if (((sock == null()))){
			HX_STACK_LINE(409)
			if ((secure)){
				HX_STACK_LINE(417)
				HX_STACK_DO_THROW(HX_CSTRING("Https is only supported with -lib hxssl"));
			}
			else{
				HX_STACK_LINE(420)
				::sys::net::Socket _g1 = ::sys::net::Socket_obj::__new();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(420)
				sock = _g1;
			}
		}
		HX_STACK_LINE(422)
		::String host = url_regexp->matched((int)2);		HX_STACK_VAR(host,"host");
		HX_STACK_LINE(423)
		::String portString = url_regexp->matched((int)3);		HX_STACK_VAR(portString,"portString");
		HX_STACK_LINE(424)
		::String request = url_regexp->matched((int)4);		HX_STACK_VAR(request,"request");
		HX_STACK_LINE(425)
		if (((request == HX_CSTRING("")))){
			HX_STACK_LINE(426)
			request = HX_CSTRING("/");
		}
		HX_STACK_LINE(427)
		Dynamic port;		HX_STACK_VAR(port,"port");
		HX_STACK_LINE(427)
		if (((bool((portString == null())) || bool((portString == HX_CSTRING("")))))){
			HX_STACK_LINE(427)
			if ((secure)){
				HX_STACK_LINE(427)
				port = (int)443;
			}
			else{
				HX_STACK_LINE(427)
				port = (int)80;
			}
		}
		else{
			HX_STACK_LINE(427)
			::String _g2 = portString.substr((int)1,(portString.length - (int)1));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(427)
			port = ::Std_obj::parseInt(_g2);
		}
		HX_STACK_LINE(428)
		Dynamic data;		HX_STACK_VAR(data,"data");
		HX_STACK_LINE(430)
		bool multipart = (this->file != null());		HX_STACK_VAR(multipart,"multipart");
		HX_STACK_LINE(431)
		::String boundary = null();		HX_STACK_VAR(boundary,"boundary");
		HX_STACK_LINE(432)
		::String uri = null();		HX_STACK_VAR(uri,"uri");
		HX_STACK_LINE(433)
		if ((multipart)){
			HX_STACK_LINE(434)
			post = true;
			HX_STACK_LINE(435)
			int _g3 = ::Std_obj::random((int)1000);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(435)
			::String _g4 = ::Std_obj::string(_g3);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(435)
			int _g5 = ::Std_obj::random((int)1000);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(435)
			::String _g6 = ::Std_obj::string(_g5);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(435)
			::String _g7 = (_g4 + _g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(435)
			int _g8 = ::Std_obj::random((int)1000);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(435)
			::String _g9 = ::Std_obj::string(_g8);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(435)
			::String _g10 = (_g7 + _g9);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(435)
			int _g11 = ::Std_obj::random((int)1000);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(435)
			::String _g12 = ::Std_obj::string(_g11);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(435)
			::String _g13 = (_g10 + _g12);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(435)
			boundary = _g13;
			HX_STACK_LINE(436)
			while((true)){
				HX_STACK_LINE(436)
				if ((!(((boundary.length < (int)38))))){
					HX_STACK_LINE(436)
					break;
				}
				HX_STACK_LINE(437)
				boundary = (HX_CSTRING("-") + boundary);
			}
			HX_STACK_LINE(438)
			::StringBuf b = ::StringBuf_obj::__new();		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(439)
			for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(this->params->iterator());  __it->hasNext(); ){
				Dynamic p = __it->next();
				{
					HX_STACK_LINE(440)
					b->add(HX_CSTRING("--"));
					HX_STACK_LINE(441)
					b->add(boundary);
					HX_STACK_LINE(442)
					b->add(HX_CSTRING("\r\n"));
					HX_STACK_LINE(443)
					b->add(HX_CSTRING("Content-Disposition: form-data; name=\""));
					HX_STACK_LINE(444)
					b->add(p->__Field(HX_CSTRING("param"),true));
					HX_STACK_LINE(445)
					b->add(HX_CSTRING("\""));
					HX_STACK_LINE(446)
					b->add(HX_CSTRING("\r\n"));
					HX_STACK_LINE(447)
					b->add(HX_CSTRING("\r\n"));
					HX_STACK_LINE(448)
					b->add(p->__Field(HX_CSTRING("value"),true));
					HX_STACK_LINE(449)
					b->add(HX_CSTRING("\r\n"));
				}
;
			}
			HX_STACK_LINE(451)
			b->add(HX_CSTRING("--"));
			HX_STACK_LINE(452)
			b->add(boundary);
			HX_STACK_LINE(453)
			b->add(HX_CSTRING("\r\n"));
			HX_STACK_LINE(454)
			b->add(HX_CSTRING("Content-Disposition: form-data; name=\""));
			HX_STACK_LINE(455)
			b->add(this->file->__Field(HX_CSTRING("param"),true));
			HX_STACK_LINE(456)
			b->add(HX_CSTRING("\"; filename=\""));
			HX_STACK_LINE(457)
			b->add(this->file->__Field(HX_CSTRING("filename"),true));
			HX_STACK_LINE(458)
			b->add(HX_CSTRING("\""));
			HX_STACK_LINE(459)
			b->add(HX_CSTRING("\r\n"));
			HX_STACK_LINE(460)
			b->add((((HX_CSTRING("Content-Type: ") + this->file->__Field(HX_CSTRING("mimeType"),true)) + HX_CSTRING("\r\n")) + HX_CSTRING("\r\n")));
			HX_STACK_LINE(461)
			::String _g14 = b->b->join(HX_CSTRING(""));		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(461)
			uri = _g14;
		}
		else{
			HX_STACK_LINE(463)
			for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(this->params->iterator());  __it->hasNext(); ){
				Dynamic p = __it->next();
				{
					HX_STACK_LINE(464)
					if (((uri == null()))){
						HX_STACK_LINE(465)
						uri = HX_CSTRING("");
					}
					else{
						HX_STACK_LINE(467)
						hx::AddEq(uri,HX_CSTRING("&"));
					}
					HX_STACK_LINE(468)
					::String _g15 = ::StringTools_obj::urlEncode(p->__Field(HX_CSTRING("param"),true));		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(468)
					::String _g16 = (_g15 + HX_CSTRING("="));		HX_STACK_VAR(_g16,"_g16");
					HX_STACK_LINE(468)
					::String _g17 = ::StringTools_obj::urlEncode(p->__Field(HX_CSTRING("value"),true));		HX_STACK_VAR(_g17,"_g17");
					HX_STACK_LINE(468)
					::String _g18 = (_g16 + _g17);		HX_STACK_VAR(_g18,"_g18");
					HX_STACK_LINE(468)
					hx::AddEq(uri,_g18);
				}
;
			}
		}
		HX_STACK_LINE(472)
		::StringBuf b = ::StringBuf_obj::__new();		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(473)
		if (((method != null()))){
			HX_STACK_LINE(474)
			b->add(method);
			HX_STACK_LINE(475)
			b->add(HX_CSTRING(" "));
		}
		else{
			HX_STACK_LINE(476)
			if ((post)){
				HX_STACK_LINE(477)
				b->add(HX_CSTRING("POST "));
			}
			else{
				HX_STACK_LINE(479)
				b->add(HX_CSTRING("GET "));
			}
		}
		HX_STACK_LINE(481)
		if (((::haxe::Http_obj::PROXY != null()))){
			HX_STACK_LINE(482)
			b->add(HX_CSTRING("http://"));
			HX_STACK_LINE(483)
			b->add(host);
			HX_STACK_LINE(484)
			if (((port != (int)80))){
				HX_STACK_LINE(485)
				b->add(HX_CSTRING(":"));
				HX_STACK_LINE(486)
				b->add(port);
			}
		}
		HX_STACK_LINE(489)
		b->add(request);
		HX_STACK_LINE(491)
		if (((bool(!(post)) && bool((uri != null()))))){
			HX_STACK_LINE(492)
			int _g19 = request.indexOf(HX_CSTRING("?"),(int)0);		HX_STACK_VAR(_g19,"_g19");
			HX_STACK_LINE(492)
			if (((_g19 >= (int)0))){
				HX_STACK_LINE(493)
				b->add(HX_CSTRING("&"));
			}
			else{
				HX_STACK_LINE(495)
				b->add(HX_CSTRING("?"));
			}
			HX_STACK_LINE(496)
			b->add(uri);
		}
		HX_STACK_LINE(498)
		b->add(((HX_CSTRING(" HTTP/1.1\r\nHost: ") + host) + HX_CSTRING("\r\n")));
		HX_STACK_LINE(499)
		if (((this->postData != null()))){
			HX_STACK_LINE(500)
			b->add(((HX_CSTRING("Content-Length: ") + this->postData.length) + HX_CSTRING("\r\n")));
		}
		else{
			HX_STACK_LINE(501)
			if (((bool(post) && bool((uri != null()))))){

				HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_3_1)
				bool run(Dynamic h){
					HX_STACK_FRAME("*","_Function_3_1",0x520271b9,"*._Function_3_1","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Http.hx",502,0xddb358ba)
					HX_STACK_ARG(h,"h")
					{
						HX_STACK_LINE(502)
						return (h->__Field(HX_CSTRING("header"),true) == HX_CSTRING("Content-Type"));
					}
					return null();
				}
				HX_END_LOCAL_FUNC1(return)

				HX_STACK_LINE(502)
				if (((  ((!(multipart))) ? bool(!(::Lambda_obj::exists(this->headers, Dynamic(new _Function_3_1())))) : bool(true) ))){
					HX_STACK_LINE(503)
					b->add(HX_CSTRING("Content-Type: "));
					HX_STACK_LINE(504)
					if ((multipart)){
						HX_STACK_LINE(505)
						b->add(HX_CSTRING("multipart/form-data"));
						HX_STACK_LINE(506)
						b->add(HX_CSTRING("; boundary="));
						HX_STACK_LINE(507)
						b->add(boundary);
					}
					else{
						HX_STACK_LINE(509)
						b->add(HX_CSTRING("application/x-www-form-urlencoded"));
					}
					HX_STACK_LINE(510)
					b->add(HX_CSTRING("\r\n"));
				}
				HX_STACK_LINE(512)
				if ((multipart)){
					HX_STACK_LINE(513)
					b->add(((HX_CSTRING("Content-Length: ") + ((((uri.length + this->file->__Field(HX_CSTRING("size"),true)) + boundary.length) + (int)6))) + HX_CSTRING("\r\n")));
				}
				else{
					HX_STACK_LINE(515)
					b->add(((HX_CSTRING("Content-Length: ") + uri.length) + HX_CSTRING("\r\n")));
				}
			}
		}
		HX_STACK_LINE(517)
		for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(this->headers->iterator());  __it->hasNext(); ){
			Dynamic h = __it->next();
			{
				HX_STACK_LINE(518)
				b->add(h->__Field(HX_CSTRING("header"),true));
				HX_STACK_LINE(519)
				b->add(HX_CSTRING(": "));
				HX_STACK_LINE(520)
				b->add(h->__Field(HX_CSTRING("value"),true));
				HX_STACK_LINE(521)
				b->add(HX_CSTRING("\r\n"));
			}
;
		}
		HX_STACK_LINE(523)
		b->add(HX_CSTRING("\r\n"));
		HX_STACK_LINE(524)
		if (((this->postData != null()))){
			HX_STACK_LINE(525)
			b->add(this->postData);
		}
		else{
			HX_STACK_LINE(526)
			if (((bool(post) && bool((uri != null()))))){
				HX_STACK_LINE(527)
				b->add(uri);
			}
		}
		HX_STACK_LINE(528)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(529)
			if (((::haxe::Http_obj::PROXY != null()))){
				HX_STACK_LINE(530)
				::sys::net::Host _g20 = ::sys::net::Host_obj::__new(::haxe::Http_obj::PROXY->__Field(HX_CSTRING("host"),true));		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(530)
				sock->__Field(HX_CSTRING("connect"),true)(_g20,::haxe::Http_obj::PROXY->__Field(HX_CSTRING("port"),true));
			}
			else{
				HX_STACK_LINE(532)
				::sys::net::Host _g21 = ::sys::net::Host_obj::__new(host);		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(532)
				sock->__Field(HX_CSTRING("connect"),true)(_g21,port);
			}
			HX_STACK_LINE(533)
			::String _g22 = b->b->join(HX_CSTRING(""));		HX_STACK_VAR(_g22,"_g22");
			HX_STACK_LINE(533)
			sock->__Field(HX_CSTRING("write"),true)(_g22);
			HX_STACK_LINE(534)
			if ((multipart)){
				HX_STACK_LINE(535)
				int bufsize = (int)4096;		HX_STACK_VAR(bufsize,"bufsize");
				HX_STACK_LINE(536)
				::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);		HX_STACK_VAR(buf,"buf");
				HX_STACK_LINE(537)
				while((true)){
					HX_STACK_LINE(537)
					if ((!(((this->file->__Field(HX_CSTRING("size"),true) > (int)0))))){
						HX_STACK_LINE(537)
						break;
					}
					HX_STACK_LINE(538)
					int size;		HX_STACK_VAR(size,"size");
					HX_STACK_LINE(538)
					if (((this->file->__Field(HX_CSTRING("size"),true) > bufsize))){
						HX_STACK_LINE(538)
						size = bufsize;
					}
					else{
						HX_STACK_LINE(538)
						size = this->file->__Field(HX_CSTRING("size"),true);
					}
					HX_STACK_LINE(539)
					int len = (int)0;		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(540)
					try
					{
					HX_STACK_CATCHABLE(::haxe::io::Eof, 0);
					{
						HX_STACK_LINE(541)
						int _g23 = this->file->__Field(HX_CSTRING("io"),true)->__Field(HX_CSTRING("readBytes"),true)(buf,(int)0,size);		HX_STACK_VAR(_g23,"_g23");
						HX_STACK_LINE(541)
						len = _g23;
					}
					}
					catch(Dynamic __e){
						if (__e.IsClass< ::haxe::io::Eof >() ){
							HX_STACK_BEGIN_CATCH
							::haxe::io::Eof e = __e;{
								HX_STACK_LINE(542)
								break;
							}
						}
						else {
						    HX_STACK_DO_THROW(__e);
						}
					}
					HX_STACK_LINE(543)
					sock->__Field(HX_CSTRING("output"),true)->__Field(HX_CSTRING("writeFullBytes"),true)(buf,(int)0,len);
					HX_STACK_LINE(544)
					hx::SubEq(this->file->__FieldRef(HX_CSTRING("size")),len);
				}
				HX_STACK_LINE(546)
				sock->__Field(HX_CSTRING("write"),true)(HX_CSTRING("\r\n"));
				HX_STACK_LINE(547)
				sock->__Field(HX_CSTRING("write"),true)(HX_CSTRING("--"));
				HX_STACK_LINE(548)
				sock->__Field(HX_CSTRING("write"),true)(boundary);
				HX_STACK_LINE(549)
				sock->__Field(HX_CSTRING("write"),true)(HX_CSTRING("--"));
			}
			HX_STACK_LINE(551)
			this->readHttpResponse(api,sock);
			HX_STACK_LINE(552)
			sock->__Field(HX_CSTRING("close"),true)();
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
					HX_STACK_LINE(554)
					try
					{
					HX_STACK_CATCHABLE(Dynamic, 0);
					{
						HX_STACK_LINE(554)
						sock->__Field(HX_CSTRING("close"),true)();
					}
					}
					catch(Dynamic __e){
						{
							HX_STACK_BEGIN_CATCH
							Dynamic e1 = __e;{
							}
						}
					}
					HX_STACK_LINE(555)
					::String _g24 = ::Std_obj::string(e);		HX_STACK_VAR(_g24,"_g24");
					HX_STACK_LINE(555)
					this->onError(_g24);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Http_obj,customRequest,(void))

Void Http_obj::readHttpResponse( ::haxe::io::Output api,Dynamic sock){
{
		HX_STACK_FRAME("haxe.Http","readHttpResponse",0x6bff43dd,"haxe.Http.readHttpResponse","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Http.hx",559,0xddb358ba)
		HX_STACK_THIS(this)
		HX_STACK_ARG(api,"api")
		HX_STACK_ARG(sock,"sock")
		HX_STACK_LINE(561)
		::haxe::io::BytesBuffer b = ::haxe::io::BytesBuffer_obj::__new();		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(562)
		int k = (int)4;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(563)
		::haxe::io::Bytes s = ::haxe::io::Bytes_obj::alloc((int)4);		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(564)
		sock->__Field(HX_CSTRING("setTimeout"),true)(this->cnxTimeout);
		HX_STACK_LINE(565)
		while((true)){
			HX_STACK_LINE(566)
			int p = sock->__Field(HX_CSTRING("input"),true)->__Field(HX_CSTRING("readBytes"),true)(s,(int)0,k);		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(567)
			while((true)){
				HX_STACK_LINE(567)
				if ((!(((p != k))))){
					HX_STACK_LINE(567)
					break;
				}
				HX_STACK_LINE(568)
				int _g = sock->__Field(HX_CSTRING("input"),true)->__Field(HX_CSTRING("readBytes"),true)(s,p,(k - p));		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(568)
				hx::AddEq(p,_g);
			}
			HX_STACK_LINE(569)
			{
				HX_STACK_LINE(569)
				if (((bool((k < (int)0)) || bool((k > s->length))))){
					HX_STACK_LINE(569)
					HX_STACK_DO_THROW(::haxe::io::Error_obj::OutsideBounds);
				}
				HX_STACK_LINE(569)
				Array< unsigned char > b1 = b->b;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(569)
				Array< unsigned char > b2 = s->b;		HX_STACK_VAR(b2,"b2");
				HX_STACK_LINE(569)
				{
					HX_STACK_LINE(569)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(569)
					int _g = k;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(569)
					while((true)){
						HX_STACK_LINE(569)
						if ((!(((_g1 < _g))))){
							HX_STACK_LINE(569)
							break;
						}
						HX_STACK_LINE(569)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(569)
						b->b->push(b2->__get(i));
					}
				}
			}
			HX_STACK_LINE(570)
			int _switch_1 = (k);
			if (  ( _switch_1==(int)1)){
				HX_STACK_LINE(572)
				int c = s->b->__get((int)0);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(573)
				if (((c == (int)10))){
					HX_STACK_LINE(574)
					break;
				}
				HX_STACK_LINE(575)
				if (((c == (int)13))){
					HX_STACK_LINE(576)
					k = (int)3;
				}
				else{
					HX_STACK_LINE(578)
					k = (int)4;
				}
			}
			else if (  ( _switch_1==(int)2)){
				HX_STACK_LINE(580)
				int c = s->b->__get((int)1);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(581)
				if (((c == (int)10))){
					HX_STACK_LINE(582)
					if (((s->b->__get((int)0) == (int)13))){
						HX_STACK_LINE(583)
						break;
					}
					HX_STACK_LINE(584)
					k = (int)4;
				}
				else{
					HX_STACK_LINE(585)
					if (((c == (int)13))){
						HX_STACK_LINE(586)
						k = (int)3;
					}
					else{
						HX_STACK_LINE(588)
						k = (int)4;
					}
				}
			}
			else if (  ( _switch_1==(int)3)){
				HX_STACK_LINE(590)
				int c = s->b->__get((int)2);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(591)
				if (((c == (int)10))){
					HX_STACK_LINE(592)
					if (((s->b->__get((int)1) != (int)13))){
						HX_STACK_LINE(593)
						k = (int)4;
					}
					else{
						HX_STACK_LINE(594)
						if (((s->b->__get((int)0) != (int)10))){
							HX_STACK_LINE(595)
							k = (int)2;
						}
						else{
							HX_STACK_LINE(597)
							break;
						}
					}
				}
				else{
					HX_STACK_LINE(598)
					if (((c == (int)13))){
						HX_STACK_LINE(599)
						if (((bool((s->b->__get((int)1) != (int)10)) || bool((s->b->__get((int)0) != (int)13))))){
							HX_STACK_LINE(600)
							k = (int)1;
						}
						else{
							HX_STACK_LINE(602)
							k = (int)3;
						}
					}
					else{
						HX_STACK_LINE(604)
						k = (int)4;
					}
				}
			}
			else if (  ( _switch_1==(int)4)){
				HX_STACK_LINE(606)
				int c = s->b->__get((int)3);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(607)
				if (((c == (int)10))){
					HX_STACK_LINE(608)
					if (((s->b->__get((int)2) != (int)13))){
						HX_STACK_LINE(609)
						continue;
					}
					else{
						HX_STACK_LINE(610)
						if (((bool((s->b->__get((int)1) != (int)10)) || bool((s->b->__get((int)0) != (int)13))))){
							HX_STACK_LINE(611)
							k = (int)2;
						}
						else{
							HX_STACK_LINE(613)
							break;
						}
					}
				}
				else{
					HX_STACK_LINE(614)
					if (((c == (int)13))){
						HX_STACK_LINE(615)
						if (((bool((s->b->__get((int)2) != (int)10)) || bool((s->b->__get((int)1) != (int)13))))){
							HX_STACK_LINE(616)
							k = (int)3;
						}
						else{
							HX_STACK_LINE(618)
							k = (int)1;
						}
					}
				}
			}
		}
		HX_STACK_LINE(625)
		Array< ::String > headers = b->getBytes()->toString().split(HX_CSTRING("\r\n"));		HX_STACK_VAR(headers,"headers");
		HX_STACK_LINE(627)
		::String response = headers->shift();		HX_STACK_VAR(response,"response");
		HX_STACK_LINE(628)
		Array< ::String > rp = response.split(HX_CSTRING(" "));		HX_STACK_VAR(rp,"rp");
		HX_STACK_LINE(629)
		Dynamic status = ::Std_obj::parseInt(rp->__get((int)1));		HX_STACK_VAR(status,"status");
		HX_STACK_LINE(630)
		if (((bool((status == (int)0)) || bool((status == null()))))){
			HX_STACK_LINE(631)
			HX_STACK_DO_THROW(HX_CSTRING("Response status error"));
		}
		HX_STACK_LINE(634)
		headers->pop();
		HX_STACK_LINE(635)
		headers->pop();
		HX_STACK_LINE(636)
		::haxe::ds::StringMap _g1 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(636)
		this->responseHeaders = _g1;
		HX_STACK_LINE(637)
		Dynamic size = null();		HX_STACK_VAR(size,"size");
		HX_STACK_LINE(638)
		bool chunked = false;		HX_STACK_VAR(chunked,"chunked");
		HX_STACK_LINE(639)
		{
			HX_STACK_LINE(639)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(639)
			while((true)){
				HX_STACK_LINE(639)
				if ((!(((_g < headers->length))))){
					HX_STACK_LINE(639)
					break;
				}
				HX_STACK_LINE(639)
				::String hline = headers->__get(_g);		HX_STACK_VAR(hline,"hline");
				HX_STACK_LINE(639)
				++(_g);
				HX_STACK_LINE(640)
				Array< ::String > a = hline.split(HX_CSTRING(": "));		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(641)
				::String hname = a->shift();		HX_STACK_VAR(hname,"hname");
				HX_STACK_LINE(642)
				::String hval;		HX_STACK_VAR(hval,"hval");
				HX_STACK_LINE(642)
				if (((a->length == (int)1))){
					HX_STACK_LINE(642)
					hval = a->__get((int)0);
				}
				else{
					HX_STACK_LINE(642)
					hval = a->join(HX_CSTRING(": "));
				}
				HX_STACK_LINE(643)
				::String _g2 = ::StringTools_obj::rtrim(hval);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(643)
				::String _g3 = ::StringTools_obj::ltrim(_g2);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(643)
				hval = _g3;
				HX_STACK_LINE(644)
				this->responseHeaders->set(hname,hval);
				HX_STACK_LINE(645)
				{
					HX_STACK_LINE(645)
					::String _g11 = hname.toLowerCase();		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(645)
					::String _switch_2 = (_g11);
					if (  ( _switch_2==HX_CSTRING("content-length"))){
						HX_STACK_LINE(648)
						Dynamic _g4 = ::Std_obj::parseInt(hval);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(648)
						size = _g4;
					}
					else if (  ( _switch_2==HX_CSTRING("transfer-encoding"))){
						HX_STACK_LINE(650)
						::String _g5 = hval.toLowerCase();		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(650)
						bool _g6 = (_g5 == HX_CSTRING("chunked"));		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(650)
						chunked = _g6;
					}
				}
			}
		}
		HX_STACK_LINE(654)
		this->onStatus(status);
		HX_STACK_LINE(656)
		::EReg chunk_re = ::EReg_obj::__new(HX_CSTRING("^([0-9A-Fa-f]+)[ ]*\r\n"),HX_CSTRING("m"));		HX_STACK_VAR(chunk_re,"chunk_re");
		HX_STACK_LINE(657)
		this->chunk_size = null();
		HX_STACK_LINE(658)
		this->chunk_buf = null();
		HX_STACK_LINE(660)
		int bufsize = (int)1024;		HX_STACK_VAR(bufsize,"bufsize");
		HX_STACK_LINE(661)
		::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);		HX_STACK_VAR(buf,"buf");
		HX_STACK_LINE(662)
		if (((size == null()))){
			HX_STACK_LINE(663)
			if ((!(this->noShutdown))){
				HX_STACK_LINE(664)
				sock->__Field(HX_CSTRING("shutdown"),true)(false,true);
			}
			HX_STACK_LINE(665)
			try
			{
			HX_STACK_CATCHABLE(::haxe::io::Eof, 0);
			{
				HX_STACK_LINE(666)
				while((true)){
					HX_STACK_LINE(667)
					int len = sock->__Field(HX_CSTRING("input"),true)->__Field(HX_CSTRING("readBytes"),true)(buf,(int)0,bufsize);		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(668)
					if ((chunked)){
						HX_STACK_LINE(669)
						if ((!(this->readChunk(chunk_re,api,buf,len)))){
							HX_STACK_LINE(670)
							break;
						}
					}
					else{
						HX_STACK_LINE(672)
						api->writeBytes(buf,(int)0,len);
					}
				}
			}
			}
			catch(Dynamic __e){
				if (__e.IsClass< ::haxe::io::Eof >() ){
					HX_STACK_BEGIN_CATCH
					::haxe::io::Eof e = __e;{
					}
				}
				else {
				    HX_STACK_DO_THROW(__e);
				}
			}
		}
		else{
			HX_STACK_LINE(677)
			api->prepare(size);
			HX_STACK_LINE(678)
			try
			{
			HX_STACK_CATCHABLE(::haxe::io::Eof, 0);
			{
				HX_STACK_LINE(679)
				while((true)){
					HX_STACK_LINE(679)
					if ((!(((size > (int)0))))){
						HX_STACK_LINE(679)
						break;
					}
					HX_STACK_LINE(680)
					int len = sock->__Field(HX_CSTRING("input"),true)->__Field(HX_CSTRING("readBytes"),true)(buf,(int)0,(  (((size > bufsize))) ? int(bufsize) : int(size) ));		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(681)
					if ((chunked)){
						HX_STACK_LINE(682)
						if ((!(this->readChunk(chunk_re,api,buf,len)))){
							HX_STACK_LINE(683)
							break;
						}
					}
					else{
						HX_STACK_LINE(685)
						api->writeBytes(buf,(int)0,len);
					}
					HX_STACK_LINE(686)
					hx::SubEq(size,len);
				}
			}
			}
			catch(Dynamic __e){
				if (__e.IsClass< ::haxe::io::Eof >() ){
					HX_STACK_BEGIN_CATCH
					::haxe::io::Eof e = __e;{
						HX_STACK_LINE(689)
						HX_STACK_DO_THROW(HX_CSTRING("Transfer aborted"));
					}
				}
				else {
				    HX_STACK_DO_THROW(__e);
				}
			}
		}
		HX_STACK_LINE(692)
		if (((bool(chunked) && bool(((bool((this->chunk_size != null())) || bool((this->chunk_buf != null())))))))){
			HX_STACK_LINE(693)
			HX_STACK_DO_THROW(HX_CSTRING("Invalid chunk"));
		}
		HX_STACK_LINE(694)
		if (((bool((status < (int)200)) || bool((status >= (int)400))))){
			HX_STACK_LINE(695)
			HX_STACK_DO_THROW((HX_CSTRING("Http Error #") + status));
		}
		HX_STACK_LINE(696)
		api->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Http_obj,readHttpResponse,(void))

bool Http_obj::readChunk( ::EReg chunk_re,::haxe::io::Output api,::haxe::io::Bytes buf,int len){
	HX_STACK_FRAME("haxe.Http","readChunk",0xeebfa239,"haxe.Http.readChunk","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Http.hx",699,0xddb358ba)
	HX_STACK_THIS(this)
	HX_STACK_ARG(chunk_re,"chunk_re")
	HX_STACK_ARG(api,"api")
	HX_STACK_ARG(buf,"buf")
	HX_STACK_ARG(len,"len")
	HX_STACK_LINE(700)
	if (((this->chunk_size == null()))){
		HX_STACK_LINE(701)
		if (((this->chunk_buf != null()))){
			HX_STACK_LINE(702)
			::haxe::io::BytesBuffer b = ::haxe::io::BytesBuffer_obj::__new();		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(703)
			{
				HX_STACK_LINE(703)
				::haxe::io::Bytes src = this->chunk_buf;		HX_STACK_VAR(src,"src");
				HX_STACK_LINE(703)
				Array< unsigned char > b1 = b->b;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(703)
				Array< unsigned char > b2 = src->b;		HX_STACK_VAR(b2,"b2");
				HX_STACK_LINE(703)
				{
					HX_STACK_LINE(703)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(703)
					int _g = src->length;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(703)
					while((true)){
						HX_STACK_LINE(703)
						if ((!(((_g1 < _g))))){
							HX_STACK_LINE(703)
							break;
						}
						HX_STACK_LINE(703)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(703)
						b->b->push(b2->__get(i));
					}
				}
			}
			HX_STACK_LINE(704)
			{
				HX_STACK_LINE(704)
				if (((bool((len < (int)0)) || bool((len > buf->length))))){
					HX_STACK_LINE(704)
					HX_STACK_DO_THROW(::haxe::io::Error_obj::OutsideBounds);
				}
				HX_STACK_LINE(704)
				Array< unsigned char > b1 = b->b;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(704)
				Array< unsigned char > b2 = buf->b;		HX_STACK_VAR(b2,"b2");
				HX_STACK_LINE(704)
				{
					HX_STACK_LINE(704)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(704)
					int _g = len;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(704)
					while((true)){
						HX_STACK_LINE(704)
						if ((!(((_g1 < _g))))){
							HX_STACK_LINE(704)
							break;
						}
						HX_STACK_LINE(704)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(704)
						b->b->push(b2->__get(i));
					}
				}
			}
			HX_STACK_LINE(705)
			::haxe::io::Bytes _g = b->getBytes();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(705)
			buf = _g;
			HX_STACK_LINE(706)
			hx::AddEq(len,this->chunk_buf->length);
			HX_STACK_LINE(707)
			this->chunk_buf = null();
		}
		HX_STACK_LINE(712)
		::String _g1 = buf->toString();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(712)
		if ((chunk_re->match(_g1))){
			HX_STACK_LINE(714)
			Dynamic p = chunk_re->matchedPos();		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(715)
			if (((p->__Field(HX_CSTRING("len"),true) <= len))){
				HX_STACK_LINE(716)
				::String cstr = chunk_re->matched((int)1);		HX_STACK_VAR(cstr,"cstr");
				HX_STACK_LINE(717)
				Dynamic _g2 = ::Std_obj::parseInt((HX_CSTRING("0x") + cstr));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(717)
				this->chunk_size = _g2;
				HX_STACK_LINE(718)
				if (((cstr == HX_CSTRING("0")))){
					HX_STACK_LINE(719)
					this->chunk_size = null();
					HX_STACK_LINE(720)
					this->chunk_buf = null();
					HX_STACK_LINE(721)
					return false;
				}
				HX_STACK_LINE(723)
				hx::SubEq(len,p->__Field(HX_CSTRING("len"),true));
				HX_STACK_LINE(724)
				::haxe::io::Bytes _g3 = buf->sub(p->__Field(HX_CSTRING("len"),true),len);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(724)
				return this->readChunk(chunk_re,api,_g3,len);
			}
		}
		HX_STACK_LINE(728)
		if (((len > (int)10))){
			HX_STACK_LINE(729)
			this->onError(HX_CSTRING("Invalid chunk"));
			HX_STACK_LINE(730)
			return false;
		}
		HX_STACK_LINE(732)
		::haxe::io::Bytes _g4 = buf->sub((int)0,len);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(732)
		this->chunk_buf = _g4;
		HX_STACK_LINE(733)
		return true;
	}
	HX_STACK_LINE(735)
	if (((this->chunk_size > len))){
		HX_STACK_LINE(736)
		hx::SubEq(this->chunk_size,len);
		HX_STACK_LINE(737)
		api->writeBytes(buf,(int)0,len);
		HX_STACK_LINE(738)
		return true;
	}
	HX_STACK_LINE(740)
	int end = (this->chunk_size + (int)2);		HX_STACK_VAR(end,"end");
	HX_STACK_LINE(741)
	if (((len >= end))){
		HX_STACK_LINE(742)
		if (((this->chunk_size > (int)0))){
			HX_STACK_LINE(743)
			api->writeBytes(buf,(int)0,this->chunk_size);
		}
		HX_STACK_LINE(744)
		hx::SubEq(len,end);
		HX_STACK_LINE(745)
		this->chunk_size = null();
		HX_STACK_LINE(746)
		if (((len == (int)0))){
			HX_STACK_LINE(747)
			return true;
		}
		HX_STACK_LINE(748)
		::haxe::io::Bytes _g5 = buf->sub(end,len);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(748)
		return this->readChunk(chunk_re,api,_g5,len);
	}
	HX_STACK_LINE(750)
	if (((this->chunk_size > (int)0))){
		HX_STACK_LINE(751)
		api->writeBytes(buf,(int)0,this->chunk_size);
	}
	HX_STACK_LINE(752)
	hx::SubEq(this->chunk_size,len);
	HX_STACK_LINE(753)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC4(Http_obj,readChunk,return )

HX_BEGIN_DEFAULT_FUNC(__default_onData,Http_obj)
Void run(::String data){
{
		HX_STACK_FRAME("haxe.Http","onData",0x4f093aa7,"haxe.Http.onData","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Http.hx",765,0xddb358ba)
		HX_STACK_THIS(this)
		HX_STACK_ARG(data,"data")
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

HX_BEGIN_DEFAULT_FUNC(__default_onError,Http_obj)
Void run(::String msg){
{
		HX_STACK_FRAME("haxe.Http","onError",0x77abd4ab,"haxe.Http.onError","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Http.hx",775,0xddb358ba)
		HX_STACK_THIS(this)
		HX_STACK_ARG(msg,"msg")
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

HX_BEGIN_DEFAULT_FUNC(__default_onStatus,Http_obj)
Void run(int status){
{
		HX_STACK_FRAME("haxe.Http","onStatus",0xf341a4ef,"haxe.Http.onStatus","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Http.hx",785,0xddb358ba)
		HX_STACK_THIS(this)
		HX_STACK_ARG(status,"status")
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

Dynamic Http_obj::PROXY;


Http_obj::Http_obj()
{
	onData = new __default_onData(this);
	onError = new __default_onError(this);
	onStatus = new __default_onStatus(this);
}

void Http_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Http);
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_MEMBER_NAME(responseData,"responseData");
	HX_MARK_MEMBER_NAME(noShutdown,"noShutdown");
	HX_MARK_MEMBER_NAME(cnxTimeout,"cnxTimeout");
	HX_MARK_MEMBER_NAME(responseHeaders,"responseHeaders");
	HX_MARK_MEMBER_NAME(chunk_size,"chunk_size");
	HX_MARK_MEMBER_NAME(chunk_buf,"chunk_buf");
	HX_MARK_MEMBER_NAME(file,"file");
	HX_MARK_MEMBER_NAME(postData,"postData");
	HX_MARK_MEMBER_NAME(headers,"headers");
	HX_MARK_MEMBER_NAME(params,"params");
	HX_MARK_MEMBER_NAME(onData,"onData");
	HX_MARK_MEMBER_NAME(onError,"onError");
	HX_MARK_MEMBER_NAME(onStatus,"onStatus");
	HX_MARK_END_CLASS();
}

void Http_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(url,"url");
	HX_VISIT_MEMBER_NAME(responseData,"responseData");
	HX_VISIT_MEMBER_NAME(noShutdown,"noShutdown");
	HX_VISIT_MEMBER_NAME(cnxTimeout,"cnxTimeout");
	HX_VISIT_MEMBER_NAME(responseHeaders,"responseHeaders");
	HX_VISIT_MEMBER_NAME(chunk_size,"chunk_size");
	HX_VISIT_MEMBER_NAME(chunk_buf,"chunk_buf");
	HX_VISIT_MEMBER_NAME(file,"file");
	HX_VISIT_MEMBER_NAME(postData,"postData");
	HX_VISIT_MEMBER_NAME(headers,"headers");
	HX_VISIT_MEMBER_NAME(params,"params");
	HX_VISIT_MEMBER_NAME(onData,"onData");
	HX_VISIT_MEMBER_NAME(onError,"onError");
	HX_VISIT_MEMBER_NAME(onStatus,"onStatus");
}

Dynamic Http_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"file") ) { return file; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"PROXY") ) { return PROXY; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"params") ) { return params; }
		if (HX_FIELD_EQ(inName,"onData") ) { return onData; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"headers") ) { return headers; }
		if (HX_FIELD_EQ(inName,"request") ) { return request_dyn(); }
		if (HX_FIELD_EQ(inName,"onError") ) { return onError; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"postData") ) { return postData; }
		if (HX_FIELD_EQ(inName,"onStatus") ) { return onStatus; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"chunk_buf") ) { return chunk_buf; }
		if (HX_FIELD_EQ(inName,"readChunk") ) { return readChunk_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"noShutdown") ) { return noShutdown; }
		if (HX_FIELD_EQ(inName,"cnxTimeout") ) { return cnxTimeout; }
		if (HX_FIELD_EQ(inName,"chunk_size") ) { return chunk_size; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"responseData") ) { return responseData; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"customRequest") ) { return customRequest_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"responseHeaders") ) { return responseHeaders; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"readHttpResponse") ) { return readHttpResponse_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Http_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"file") ) { file=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"PROXY") ) { PROXY=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"params") ) { params=inValue.Cast< ::List >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onData") ) { onData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"headers") ) { headers=inValue.Cast< ::List >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onError") ) { onError=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"postData") ) { postData=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onStatus") ) { onStatus=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"chunk_buf") ) { chunk_buf=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"noShutdown") ) { noShutdown=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cnxTimeout") ) { cnxTimeout=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"chunk_size") ) { chunk_size=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"responseData") ) { responseData=inValue.Cast< ::String >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"responseHeaders") ) { responseHeaders=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Http_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("url"));
	outFields->push(HX_CSTRING("responseData"));
	outFields->push(HX_CSTRING("noShutdown"));
	outFields->push(HX_CSTRING("cnxTimeout"));
	outFields->push(HX_CSTRING("responseHeaders"));
	outFields->push(HX_CSTRING("chunk_size"));
	outFields->push(HX_CSTRING("chunk_buf"));
	outFields->push(HX_CSTRING("file"));
	outFields->push(HX_CSTRING("postData"));
	outFields->push(HX_CSTRING("headers"));
	outFields->push(HX_CSTRING("params"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PROXY"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(Http_obj,url),HX_CSTRING("url")},
	{hx::fsString,(int)offsetof(Http_obj,responseData),HX_CSTRING("responseData")},
	{hx::fsBool,(int)offsetof(Http_obj,noShutdown),HX_CSTRING("noShutdown")},
	{hx::fsFloat,(int)offsetof(Http_obj,cnxTimeout),HX_CSTRING("cnxTimeout")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(Http_obj,responseHeaders),HX_CSTRING("responseHeaders")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Http_obj,chunk_size),HX_CSTRING("chunk_size")},
	{hx::fsObject /*::haxe::io::Bytes*/ ,(int)offsetof(Http_obj,chunk_buf),HX_CSTRING("chunk_buf")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Http_obj,file),HX_CSTRING("file")},
	{hx::fsString,(int)offsetof(Http_obj,postData),HX_CSTRING("postData")},
	{hx::fsObject /*::List*/ ,(int)offsetof(Http_obj,headers),HX_CSTRING("headers")},
	{hx::fsObject /*::List*/ ,(int)offsetof(Http_obj,params),HX_CSTRING("params")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Http_obj,onData),HX_CSTRING("onData")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Http_obj,onError),HX_CSTRING("onError")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Http_obj,onStatus),HX_CSTRING("onStatus")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("url"),
	HX_CSTRING("responseData"),
	HX_CSTRING("noShutdown"),
	HX_CSTRING("cnxTimeout"),
	HX_CSTRING("responseHeaders"),
	HX_CSTRING("chunk_size"),
	HX_CSTRING("chunk_buf"),
	HX_CSTRING("file"),
	HX_CSTRING("postData"),
	HX_CSTRING("headers"),
	HX_CSTRING("params"),
	HX_CSTRING("request"),
	HX_CSTRING("customRequest"),
	HX_CSTRING("readHttpResponse"),
	HX_CSTRING("readChunk"),
	HX_CSTRING("onData"),
	HX_CSTRING("onError"),
	HX_CSTRING("onStatus"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Http_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Http_obj::PROXY,"PROXY");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Http_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Http_obj::PROXY,"PROXY");
};

#endif

Class Http_obj::__mClass;

void Http_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Http"), hx::TCanCast< Http_obj> ,sStaticFields,sMemberFields,
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

void Http_obj::__boot()
{
	PROXY= null();
}

} // end namespace haxe
