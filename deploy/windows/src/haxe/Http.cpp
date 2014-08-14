#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_IMap
#include <IMap.h>
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
#ifndef INCLUDED_sys_ssl_Socket
#include <sys/ssl/Socket.h>
#endif
namespace haxe{

Void Http_obj::__construct(::String url)
{
HX_STACK_FRAME("haxe.Http","new",0x57ac51e2,"haxe.Http.new","haxe/Http.hx",95,0x8e8a71ed)
HX_STACK_THIS(this)
HX_STACK_ARG(url,"url")
{
	HX_STACK_LINE(96)
	this->url = url;
	HX_STACK_LINE(97)
	::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(97)
	this->headers = _g;
	HX_STACK_LINE(98)
	::haxe::ds::StringMap _g1 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(98)
	this->params = _g1;
	HX_STACK_LINE(102)
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

::haxe::Http Http_obj::setHeader( ::String header,::String value){
	HX_STACK_FRAME("haxe.Http","setHeader",0x34bd0dd1,"haxe.Http.setHeader","haxe/Http.hx",116,0x8e8a71ed)
	HX_STACK_THIS(this)
	HX_STACK_ARG(header,"header")
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(117)
	this->headers->set(header,value);
	HX_STACK_LINE(118)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(Http_obj,setHeader,return )

::haxe::Http Http_obj::setParameter( ::String param,::String value){
	HX_STACK_FRAME("haxe.Http","setParameter",0x96e033e5,"haxe.Http.setParameter","haxe/Http.hx",128,0x8e8a71ed)
	HX_STACK_THIS(this)
	HX_STACK_ARG(param,"param")
	HX_STACK_ARG(value,"value")
	HX_STACK_LINE(129)
	this->params->set(param,value);
	HX_STACK_LINE(130)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(Http_obj,setParameter,return )

::haxe::Http Http_obj::setPostData( ::String data){
	HX_STACK_FRAME("haxe.Http","setPostData",0x64dc53ee,"haxe.Http.setPostData","haxe/Http.hx",144,0x8e8a71ed)
	HX_STACK_THIS(this)
	HX_STACK_ARG(data,"data")
	HX_STACK_LINE(145)
	this->postData = data;
	HX_STACK_LINE(146)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Http_obj,setPostData,return )

Void Http_obj::request( Dynamic post){
{
		HX_STACK_FRAME("haxe.Http","request",0xb2c949d1,"haxe.Http.request","haxe/Http.hx",167,0x8e8a71ed)
		HX_STACK_THIS(this)
		HX_STACK_ARG(post,"post")
		HX_STACK_LINE(168)
		::haxe::Http me = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(me,"me");
		HX_STACK_LINE(321)
		Array< ::Dynamic > me1 = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(me1,"me1");
		HX_STACK_LINE(322)
		Array< ::Dynamic > output = Array_obj< ::Dynamic >::__new().Add(::haxe::io::BytesOutput_obj::__new());		HX_STACK_VAR(output,"output");
		HX_STACK_LINE(323)
		Dynamic old = Dynamic( Array_obj<Dynamic>::__new().Add(this->onError_dyn()));		HX_STACK_VAR(old,"old");
		HX_STACK_LINE(324)
		Array< bool > err = Array_obj< bool >::__new().Add(false);		HX_STACK_VAR(err,"err");

		HX_BEGIN_LOCAL_FUNC_S4(hx::LocalFunc,_Function_1_1,Dynamic,old,Array< ::Dynamic >,me1,Array< ::Dynamic >,output,Array< bool >,err)
		Void run(::String e){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxe/Http.hx",325,0x8e8a71ed)
			HX_STACK_ARG(e,"e")
			{
				HX_STACK_LINE(329)
				me1->__get((int)0).StaticCast< ::haxe::Http >()->responseData = output->__get((int)0).StaticCast< ::haxe::io::BytesOutput >()->getBytes()->toString();
				HX_STACK_LINE(331)
				err[(int)0] = true;
				HX_STACK_LINE(332)
				old->__GetItem((int)0)(e).Cast< Void >();
			}
			return null();
		}
		HX_END_LOCAL_FUNC1((void))

		HX_STACK_LINE(325)
		this->onError =  Dynamic(new _Function_1_1(old,me1,output,err));
		HX_STACK_LINE(334)
		this->customRequest(post,output->__get((int)0).StaticCast< ::haxe::io::BytesOutput >(),null(),null());
		HX_STACK_LINE(335)
		if ((!(err->__get((int)0)))){
			HX_STACK_LINE(339)
			::String _g = output->__get((int)0).StaticCast< ::haxe::io::BytesOutput >()->getBytes()->toString();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(339)
			::String _g1 = me1->__get((int)0).StaticCast< ::haxe::Http >()->responseData = _g;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(339)
			me1->__get((int)0).StaticCast< ::haxe::Http >()->onData(_g1);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Http_obj,request,(void))

Void Http_obj::fileTransfert( ::String argname,::String filename,::haxe::io::Input file,int size){
{
		HX_STACK_FRAME("haxe.Http","fileTransfert",0x5f2130cf,"haxe.Http.fileTransfert","haxe/Http.hx",347,0x8e8a71ed)
		HX_STACK_THIS(this)
		HX_STACK_ARG(argname,"argname")
		HX_STACK_ARG(filename,"filename")
		HX_STACK_ARG(file,"file")
		HX_STACK_ARG(size,"size")
		struct _Function_1_1{
			inline static Dynamic Block( int &size,::String &filename,::haxe::io::Input &file,::String &argname){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxe/Http.hx",347,0x8e8a71ed)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("param") , argname,false);
					__result->Add(HX_CSTRING("filename") , filename,false);
					__result->Add(HX_CSTRING("io") , file,false);
					__result->Add(HX_CSTRING("size") , size,false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(347)
		this->file = _Function_1_1::Block(size,filename,file,argname);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Http_obj,fileTransfert,(void))

Void Http_obj::customRequest( bool post,::haxe::io::Output api,Dynamic sock,::String method){
{
		HX_STACK_FRAME("haxe.Http","customRequest",0x68e97fa0,"haxe.Http.customRequest","haxe/Http.hx",350,0x8e8a71ed)
		HX_STACK_THIS(this)
		HX_STACK_ARG(post,"post")
		HX_STACK_ARG(api,"api")
		HX_STACK_ARG(sock,"sock")
		HX_STACK_ARG(method,"method")
		HX_STACK_LINE(351)
		this->responseData = null();
		HX_STACK_LINE(352)
		::EReg url_regexp = ::EReg_obj::__new(HX_CSTRING("^(https?://)?([a-zA-Z\\.0-9-]+)(:[0-9]+)?(.*)$"),HX_CSTRING(""));		HX_STACK_VAR(url_regexp,"url_regexp");
		HX_STACK_LINE(353)
		if ((!(url_regexp->match(this->url)))){
			HX_STACK_LINE(354)
			this->onError(HX_CSTRING("Invalid URL"));
			HX_STACK_LINE(355)
			return null();
		}
		HX_STACK_LINE(357)
		::String _g = url_regexp->matched((int)1);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(357)
		bool secure = (_g == HX_CSTRING("https://"));		HX_STACK_VAR(secure,"secure");
		HX_STACK_LINE(358)
		if (((sock == null()))){
			HX_STACK_LINE(359)
			if ((secure)){
				HX_STACK_LINE(363)
				::sys::ssl::Socket _g1 = ::sys::ssl::Socket_obj::__new();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(363)
				sock = _g1;
				HX_STACK_LINE(364)
				sock->__Field(HX_CSTRING("setCertLocation"),true)(this->certFile,this->certFolder);
			}
			else{
				HX_STACK_LINE(370)
				::sys::ssl::Socket _g2 = ::sys::ssl::Socket_obj::__new();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(370)
				sock = _g2;
			}
		}
		HX_STACK_LINE(376)
		::String host = url_regexp->matched((int)2);		HX_STACK_VAR(host,"host");
		HX_STACK_LINE(377)
		::String portString = url_regexp->matched((int)3);		HX_STACK_VAR(portString,"portString");
		HX_STACK_LINE(378)
		::String request = url_regexp->matched((int)4);		HX_STACK_VAR(request,"request");
		HX_STACK_LINE(379)
		if (((request == HX_CSTRING("")))){
			HX_STACK_LINE(380)
			request = HX_CSTRING("/");
		}
		HX_STACK_LINE(381)
		Dynamic port;		HX_STACK_VAR(port,"port");
		HX_STACK_LINE(381)
		if (((bool((portString == null())) || bool((portString == HX_CSTRING("")))))){
			HX_STACK_LINE(381)
			if ((secure)){
				HX_STACK_LINE(381)
				port = (int)443;
			}
			else{
				HX_STACK_LINE(381)
				port = (int)80;
			}
		}
		else{
			HX_STACK_LINE(381)
			::String _g3 = portString.substr((int)1,(portString.length - (int)1));		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(381)
			port = ::Std_obj::parseInt(_g3);
		}
		HX_STACK_LINE(382)
		Dynamic data;		HX_STACK_VAR(data,"data");
		HX_STACK_LINE(384)
		bool multipart = (this->file != null());		HX_STACK_VAR(multipart,"multipart");
		HX_STACK_LINE(385)
		::String boundary = null();		HX_STACK_VAR(boundary,"boundary");
		HX_STACK_LINE(386)
		::String uri = null();		HX_STACK_VAR(uri,"uri");
		HX_STACK_LINE(387)
		if ((multipart)){
			HX_STACK_LINE(388)
			post = true;
			HX_STACK_LINE(389)
			int _g4 = ::Std_obj::random((int)1000);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(389)
			::String _g5 = ::Std_obj::string(_g4);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(389)
			int _g6 = ::Std_obj::random((int)1000);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(389)
			::String _g7 = ::Std_obj::string(_g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(389)
			::String _g8 = (_g5 + _g7);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(389)
			int _g9 = ::Std_obj::random((int)1000);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(389)
			::String _g10 = ::Std_obj::string(_g9);		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(389)
			::String _g11 = (_g8 + _g10);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(389)
			int _g12 = ::Std_obj::random((int)1000);		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(389)
			::String _g13 = ::Std_obj::string(_g12);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(389)
			::String _g14 = (_g11 + _g13);		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(389)
			boundary = _g14;
			HX_STACK_LINE(390)
			while((true)){
				HX_STACK_LINE(390)
				if ((!(((boundary.length < (int)38))))){
					HX_STACK_LINE(390)
					break;
				}
				HX_STACK_LINE(391)
				boundary = (HX_CSTRING("-") + boundary);
			}
			HX_STACK_LINE(392)
			::StringBuf b = ::StringBuf_obj::__new();		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(393)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->params->keys());  __it->hasNext(); ){
				::String p = __it->next();
				{
					HX_STACK_LINE(394)
					b->add(HX_CSTRING("--"));
					HX_STACK_LINE(395)
					b->add(boundary);
					HX_STACK_LINE(396)
					b->add(HX_CSTRING("\r\n"));
					HX_STACK_LINE(397)
					b->add(HX_CSTRING("Content-Disposition: form-data; name=\""));
					HX_STACK_LINE(398)
					b->add(p);
					HX_STACK_LINE(399)
					b->add(HX_CSTRING("\""));
					HX_STACK_LINE(400)
					b->add(HX_CSTRING("\r\n"));
					HX_STACK_LINE(401)
					b->add(HX_CSTRING("\r\n"));
					HX_STACK_LINE(402)
					::String _g15 = this->params->get(p);		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(402)
					b->add(_g15);
					HX_STACK_LINE(403)
					b->add(HX_CSTRING("\r\n"));
				}
;
			}
			HX_STACK_LINE(405)
			b->add(HX_CSTRING("--"));
			HX_STACK_LINE(406)
			b->add(boundary);
			HX_STACK_LINE(407)
			b->add(HX_CSTRING("\r\n"));
			HX_STACK_LINE(408)
			b->add(HX_CSTRING("Content-Disposition: form-data; name=\""));
			HX_STACK_LINE(409)
			b->add(this->file->__Field(HX_CSTRING("param"),true));
			HX_STACK_LINE(410)
			b->add(HX_CSTRING("\"; filename=\""));
			HX_STACK_LINE(411)
			b->add(this->file->__Field(HX_CSTRING("filename"),true));
			HX_STACK_LINE(412)
			b->add(HX_CSTRING("\""));
			HX_STACK_LINE(413)
			b->add(HX_CSTRING("\r\n"));
			HX_STACK_LINE(414)
			b->add(HX_CSTRING("Content-Type: application/octet-stream\r\n\r\n"));
			HX_STACK_LINE(415)
			::String _g16 = b->b->join(HX_CSTRING(""));		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(415)
			uri = _g16;
		}
		else{
			HX_STACK_LINE(417)
			for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->params->keys());  __it->hasNext(); ){
				::String p = __it->next();
				{
					HX_STACK_LINE(418)
					if (((uri == null()))){
						HX_STACK_LINE(419)
						uri = HX_CSTRING("");
					}
					else{
						HX_STACK_LINE(421)
						hx::AddEq(uri,HX_CSTRING("&"));
					}
					HX_STACK_LINE(422)
					::String _g17 = ::StringTools_obj::urlEncode(p);		HX_STACK_VAR(_g17,"_g17");
					HX_STACK_LINE(422)
					::String _g18 = (_g17 + HX_CSTRING("="));		HX_STACK_VAR(_g18,"_g18");
					HX_STACK_LINE(422)
					::String _g19 = this->params->get(p);		HX_STACK_VAR(_g19,"_g19");
					HX_STACK_LINE(422)
					::String _g20 = ::StringTools_obj::urlEncode(_g19);		HX_STACK_VAR(_g20,"_g20");
					HX_STACK_LINE(422)
					::String _g21 = (_g18 + _g20);		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(422)
					hx::AddEq(uri,_g21);
				}
;
			}
		}
		HX_STACK_LINE(426)
		::StringBuf b = ::StringBuf_obj::__new();		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(427)
		if (((method != null()))){
			HX_STACK_LINE(428)
			b->add(method);
			HX_STACK_LINE(429)
			b->add(HX_CSTRING(" "));
		}
		else{
			HX_STACK_LINE(430)
			if ((post)){
				HX_STACK_LINE(431)
				b->add(HX_CSTRING("POST "));
			}
			else{
				HX_STACK_LINE(433)
				b->add(HX_CSTRING("GET "));
			}
		}
		HX_STACK_LINE(435)
		if (((::haxe::Http_obj::PROXY != null()))){
			HX_STACK_LINE(436)
			b->add(HX_CSTRING("http://"));
			HX_STACK_LINE(437)
			b->add(host);
			HX_STACK_LINE(438)
			if (((port != (int)80))){
				HX_STACK_LINE(439)
				b->add(HX_CSTRING(":"));
				HX_STACK_LINE(440)
				b->add(port);
			}
		}
		HX_STACK_LINE(443)
		b->add(request);
		HX_STACK_LINE(445)
		if (((bool(!(post)) && bool((uri != null()))))){
			HX_STACK_LINE(446)
			int _g22 = request.indexOf(HX_CSTRING("?"),(int)0);		HX_STACK_VAR(_g22,"_g22");
			HX_STACK_LINE(446)
			if (((_g22 >= (int)0))){
				HX_STACK_LINE(447)
				b->add(HX_CSTRING("&"));
			}
			else{
				HX_STACK_LINE(449)
				b->add(HX_CSTRING("?"));
			}
			HX_STACK_LINE(450)
			b->add(uri);
		}
		HX_STACK_LINE(452)
		b->add(((HX_CSTRING(" HTTP/1.1\r\nHost: ") + host) + HX_CSTRING("\r\n")));
		HX_STACK_LINE(453)
		if (((this->postData != null()))){
			HX_STACK_LINE(454)
			b->add(((HX_CSTRING("Content-Length: ") + this->postData.length) + HX_CSTRING("\r\n")));
		}
		else{
			HX_STACK_LINE(455)
			if (((bool(post) && bool((uri != null()))))){
				struct _Function_3_1{
					inline static bool Block( hx::ObjectPtr< ::haxe::Http_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxe/Http.hx",456,0x8e8a71ed)
						{
							HX_STACK_LINE(456)
							::String _g23 = __this->headers->get(HX_CSTRING("Content-Type"));		HX_STACK_VAR(_g23,"_g23");
							HX_STACK_LINE(456)
							return (_g23 == null());
						}
						return null();
					}
				};
				HX_STACK_LINE(456)
				if (((  ((!(multipart))) ? bool(_Function_3_1::Block(this)) : bool(true) ))){
					HX_STACK_LINE(457)
					b->add(HX_CSTRING("Content-Type: "));
					HX_STACK_LINE(458)
					if ((multipart)){
						HX_STACK_LINE(459)
						b->add(HX_CSTRING("multipart/form-data"));
						HX_STACK_LINE(460)
						b->add(HX_CSTRING("; boundary="));
						HX_STACK_LINE(461)
						b->add(boundary);
					}
					else{
						HX_STACK_LINE(463)
						b->add(HX_CSTRING("application/x-www-form-urlencoded"));
					}
					HX_STACK_LINE(464)
					b->add(HX_CSTRING("\r\n"));
				}
				HX_STACK_LINE(466)
				if ((multipart)){
					HX_STACK_LINE(467)
					b->add(((HX_CSTRING("Content-Length: ") + ((((uri.length + this->file->__Field(HX_CSTRING("size"),true)) + boundary.length) + (int)6))) + HX_CSTRING("\r\n")));
				}
				else{
					HX_STACK_LINE(469)
					b->add(((HX_CSTRING("Content-Length: ") + uri.length) + HX_CSTRING("\r\n")));
				}
			}
		}
		HX_STACK_LINE(471)
		for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(this->headers->keys());  __it->hasNext(); ){
			::String h = __it->next();
			{
				HX_STACK_LINE(472)
				b->add(h);
				HX_STACK_LINE(473)
				b->add(HX_CSTRING(": "));
				HX_STACK_LINE(474)
				::String _g24 = this->headers->get(h);		HX_STACK_VAR(_g24,"_g24");
				HX_STACK_LINE(474)
				b->add(_g24);
				HX_STACK_LINE(475)
				b->add(HX_CSTRING("\r\n"));
			}
;
		}
		HX_STACK_LINE(477)
		b->add(HX_CSTRING("\r\n"));
		HX_STACK_LINE(478)
		if (((this->postData != null()))){
			HX_STACK_LINE(479)
			b->add(this->postData);
		}
		else{
			HX_STACK_LINE(480)
			if (((bool(post) && bool((uri != null()))))){
				HX_STACK_LINE(481)
				b->add(uri);
			}
		}
		HX_STACK_LINE(482)
		try
		{
		HX_STACK_CATCHABLE(Dynamic, 0);
		{
			HX_STACK_LINE(483)
			if (((::haxe::Http_obj::PROXY != null()))){
				HX_STACK_LINE(484)
				::sys::net::Host _g25 = ::sys::net::Host_obj::__new(::haxe::Http_obj::PROXY->__Field(HX_CSTRING("host"),true));		HX_STACK_VAR(_g25,"_g25");
				HX_STACK_LINE(484)
				sock->__Field(HX_CSTRING("connect"),true)(_g25,::haxe::Http_obj::PROXY->__Field(HX_CSTRING("port"),true));
			}
			else{
				HX_STACK_LINE(486)
				::sys::net::Host _g26 = ::sys::net::Host_obj::__new(host);		HX_STACK_VAR(_g26,"_g26");
				HX_STACK_LINE(486)
				sock->__Field(HX_CSTRING("connect"),true)(_g26,port);
			}
			HX_STACK_LINE(487)
			::String _g27 = b->b->join(HX_CSTRING(""));		HX_STACK_VAR(_g27,"_g27");
			HX_STACK_LINE(487)
			sock->__Field(HX_CSTRING("write"),true)(_g27);
			HX_STACK_LINE(488)
			if ((multipart)){
				HX_STACK_LINE(489)
				int bufsize = (int)4096;		HX_STACK_VAR(bufsize,"bufsize");
				HX_STACK_LINE(490)
				::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);		HX_STACK_VAR(buf,"buf");
				HX_STACK_LINE(491)
				while((true)){
					HX_STACK_LINE(491)
					if ((!(((this->file->__Field(HX_CSTRING("size"),true) > (int)0))))){
						HX_STACK_LINE(491)
						break;
					}
					HX_STACK_LINE(492)
					int size;		HX_STACK_VAR(size,"size");
					HX_STACK_LINE(492)
					if (((this->file->__Field(HX_CSTRING("size"),true) > bufsize))){
						HX_STACK_LINE(492)
						size = bufsize;
					}
					else{
						HX_STACK_LINE(492)
						size = this->file->__Field(HX_CSTRING("size"),true);
					}
					HX_STACK_LINE(493)
					int len = (int)0;		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(494)
					try
					{
					HX_STACK_CATCHABLE(::haxe::io::Eof, 0);
					{
						HX_STACK_LINE(495)
						int _g28 = this->file->__Field(HX_CSTRING("io"),true)->__Field(HX_CSTRING("readBytes"),true)(buf,(int)0,size);		HX_STACK_VAR(_g28,"_g28");
						HX_STACK_LINE(495)
						len = _g28;
					}
					}
					catch(Dynamic __e){
						if (__e.IsClass< ::haxe::io::Eof >() ){
							HX_STACK_BEGIN_CATCH
							::haxe::io::Eof e = __e;{
								HX_STACK_LINE(496)
								break;
							}
						}
						else {
						    HX_STACK_DO_THROW(__e);
						}
					}
					HX_STACK_LINE(497)
					sock->__Field(HX_CSTRING("output"),true)->__Field(HX_CSTRING("writeFullBytes"),true)(buf,(int)0,len);
					HX_STACK_LINE(498)
					hx::SubEq(this->file->__FieldRef(HX_CSTRING("size")),len);
				}
				HX_STACK_LINE(500)
				sock->__Field(HX_CSTRING("write"),true)(HX_CSTRING("\r\n"));
				HX_STACK_LINE(501)
				sock->__Field(HX_CSTRING("write"),true)(HX_CSTRING("--"));
				HX_STACK_LINE(502)
				sock->__Field(HX_CSTRING("write"),true)(boundary);
				HX_STACK_LINE(503)
				sock->__Field(HX_CSTRING("write"),true)(HX_CSTRING("--"));
			}
			HX_STACK_LINE(505)
			this->readHttpResponse(api,sock);
			HX_STACK_LINE(506)
			sock->__Field(HX_CSTRING("close"),true)();
		}
		}
		catch(Dynamic __e){
			{
				HX_STACK_BEGIN_CATCH
				Dynamic e = __e;{
					HX_STACK_LINE(508)
					try
					{
					HX_STACK_CATCHABLE(Dynamic, 0);
					{
						HX_STACK_LINE(508)
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
					HX_STACK_LINE(509)
					::String _g29 = ::Std_obj::string(e);		HX_STACK_VAR(_g29,"_g29");
					HX_STACK_LINE(509)
					this->onError(_g29);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Http_obj,customRequest,(void))

Void Http_obj::readHttpResponse( ::haxe::io::Output api,Dynamic sock){
{
		HX_STACK_FRAME("haxe.Http","readHttpResponse",0x6bff43dd,"haxe.Http.readHttpResponse","haxe/Http.hx",513,0x8e8a71ed)
		HX_STACK_THIS(this)
		HX_STACK_ARG(api,"api")
		HX_STACK_ARG(sock,"sock")
		HX_STACK_LINE(515)
		::haxe::io::BytesBuffer b = ::haxe::io::BytesBuffer_obj::__new();		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(516)
		int k = (int)4;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(517)
		::haxe::io::Bytes s = ::haxe::io::Bytes_obj::alloc((int)4);		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(518)
		sock->__Field(HX_CSTRING("setTimeout"),true)(this->cnxTimeout);
		HX_STACK_LINE(519)
		while((true)){
			HX_STACK_LINE(520)
			int p = sock->__Field(HX_CSTRING("input"),true)->__Field(HX_CSTRING("readBytes"),true)(s,(int)0,k);		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(521)
			while((true)){
				HX_STACK_LINE(521)
				if ((!(((p != k))))){
					HX_STACK_LINE(521)
					break;
				}
				HX_STACK_LINE(522)
				int _g = sock->__Field(HX_CSTRING("input"),true)->__Field(HX_CSTRING("readBytes"),true)(s,p,(k - p));		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(522)
				hx::AddEq(p,_g);
			}
			HX_STACK_LINE(523)
			{
				HX_STACK_LINE(523)
				if (((bool((k < (int)0)) || bool((k > s->length))))){
					HX_STACK_LINE(523)
					HX_STACK_DO_THROW(::haxe::io::Error_obj::OutsideBounds);
				}
				HX_STACK_LINE(523)
				Array< unsigned char > b1 = b->b;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(523)
				Array< unsigned char > b2 = s->b;		HX_STACK_VAR(b2,"b2");
				HX_STACK_LINE(523)
				{
					HX_STACK_LINE(523)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(523)
					int _g = k;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(523)
					while((true)){
						HX_STACK_LINE(523)
						if ((!(((_g1 < _g))))){
							HX_STACK_LINE(523)
							break;
						}
						HX_STACK_LINE(523)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(523)
						b->b->push(b2->__get(i));
					}
				}
			}
			HX_STACK_LINE(524)
			int _switch_1 = (k);
			if (  ( _switch_1==(int)1)){
				HX_STACK_LINE(526)
				int c = s->b->__get((int)0);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(527)
				if (((c == (int)10))){
					HX_STACK_LINE(528)
					break;
				}
				HX_STACK_LINE(529)
				if (((c == (int)13))){
					HX_STACK_LINE(530)
					k = (int)3;
				}
				else{
					HX_STACK_LINE(532)
					k = (int)4;
				}
			}
			else if (  ( _switch_1==(int)2)){
				HX_STACK_LINE(534)
				int c = s->b->__get((int)1);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(535)
				if (((c == (int)10))){
					HX_STACK_LINE(536)
					if (((s->b->__get((int)0) == (int)13))){
						HX_STACK_LINE(537)
						break;
					}
					HX_STACK_LINE(538)
					k = (int)4;
				}
				else{
					HX_STACK_LINE(539)
					if (((c == (int)13))){
						HX_STACK_LINE(540)
						k = (int)3;
					}
					else{
						HX_STACK_LINE(542)
						k = (int)4;
					}
				}
			}
			else if (  ( _switch_1==(int)3)){
				HX_STACK_LINE(544)
				int c = s->b->__get((int)2);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(545)
				if (((c == (int)10))){
					HX_STACK_LINE(546)
					if (((s->b->__get((int)1) != (int)13))){
						HX_STACK_LINE(547)
						k = (int)4;
					}
					else{
						HX_STACK_LINE(548)
						if (((s->b->__get((int)0) != (int)10))){
							HX_STACK_LINE(549)
							k = (int)2;
						}
						else{
							HX_STACK_LINE(551)
							break;
						}
					}
				}
				else{
					HX_STACK_LINE(552)
					if (((c == (int)13))){
						HX_STACK_LINE(553)
						if (((bool((s->b->__get((int)1) != (int)10)) || bool((s->b->__get((int)0) != (int)13))))){
							HX_STACK_LINE(554)
							k = (int)1;
						}
						else{
							HX_STACK_LINE(556)
							k = (int)3;
						}
					}
					else{
						HX_STACK_LINE(558)
						k = (int)4;
					}
				}
			}
			else if (  ( _switch_1==(int)4)){
				HX_STACK_LINE(560)
				int c = s->b->__get((int)3);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(561)
				if (((c == (int)10))){
					HX_STACK_LINE(562)
					if (((s->b->__get((int)2) != (int)13))){
						HX_STACK_LINE(563)
						continue;
					}
					else{
						HX_STACK_LINE(564)
						if (((bool((s->b->__get((int)1) != (int)10)) || bool((s->b->__get((int)0) != (int)13))))){
							HX_STACK_LINE(565)
							k = (int)2;
						}
						else{
							HX_STACK_LINE(567)
							break;
						}
					}
				}
				else{
					HX_STACK_LINE(568)
					if (((c == (int)13))){
						HX_STACK_LINE(569)
						if (((bool((s->b->__get((int)2) != (int)10)) || bool((s->b->__get((int)1) != (int)13))))){
							HX_STACK_LINE(570)
							k = (int)3;
						}
						else{
							HX_STACK_LINE(572)
							k = (int)1;
						}
					}
				}
			}
		}
		HX_STACK_LINE(579)
		Array< ::String > headers = b->getBytes()->toString().split(HX_CSTRING("\r\n"));		HX_STACK_VAR(headers,"headers");
		HX_STACK_LINE(581)
		::String response = headers->shift();		HX_STACK_VAR(response,"response");
		HX_STACK_LINE(582)
		Array< ::String > rp = response.split(HX_CSTRING(" "));		HX_STACK_VAR(rp,"rp");
		HX_STACK_LINE(583)
		Dynamic status = ::Std_obj::parseInt(rp->__get((int)1));		HX_STACK_VAR(status,"status");
		HX_STACK_LINE(584)
		if (((bool((status == (int)0)) || bool((status == null()))))){
			HX_STACK_LINE(585)
			HX_STACK_DO_THROW(HX_CSTRING("Response status error"));
		}
		HX_STACK_LINE(588)
		headers->pop();
		HX_STACK_LINE(589)
		headers->pop();
		HX_STACK_LINE(590)
		::haxe::ds::StringMap _g1 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(590)
		this->responseHeaders = _g1;
		HX_STACK_LINE(591)
		Dynamic size = null();		HX_STACK_VAR(size,"size");
		HX_STACK_LINE(592)
		bool chunked = false;		HX_STACK_VAR(chunked,"chunked");
		HX_STACK_LINE(593)
		{
			HX_STACK_LINE(593)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(593)
			while((true)){
				HX_STACK_LINE(593)
				if ((!(((_g < headers->length))))){
					HX_STACK_LINE(593)
					break;
				}
				HX_STACK_LINE(593)
				::String hline = headers->__get(_g);		HX_STACK_VAR(hline,"hline");
				HX_STACK_LINE(593)
				++(_g);
				HX_STACK_LINE(594)
				Array< ::String > a = hline.split(HX_CSTRING(": "));		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(595)
				::String hname = a->shift();		HX_STACK_VAR(hname,"hname");
				HX_STACK_LINE(596)
				::String hval;		HX_STACK_VAR(hval,"hval");
				HX_STACK_LINE(596)
				if (((a->length == (int)1))){
					HX_STACK_LINE(596)
					hval = a->__get((int)0);
				}
				else{
					HX_STACK_LINE(596)
					hval = a->join(HX_CSTRING(": "));
				}
				HX_STACK_LINE(597)
				this->responseHeaders->set(hname,hval);
				HX_STACK_LINE(598)
				{
					HX_STACK_LINE(598)
					::String _g11 = hname.toLowerCase();		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(598)
					::String _switch_2 = (_g11);
					if (  ( _switch_2==HX_CSTRING("content-length"))){
						HX_STACK_LINE(601)
						Dynamic _g2 = ::Std_obj::parseInt(hval);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(601)
						size = _g2;
					}
					else if (  ( _switch_2==HX_CSTRING("transfer-encoding"))){
						HX_STACK_LINE(603)
						::String _g3 = hval.toLowerCase();		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(603)
						bool _g4 = (_g3 == HX_CSTRING("chunked"));		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(603)
						chunked = _g4;
					}
				}
			}
		}
		HX_STACK_LINE(607)
		this->onStatus(status);
		HX_STACK_LINE(609)
		::EReg chunk_re = ::EReg_obj::__new(HX_CSTRING("^([0-9A-Fa-f]+)[ ]*\r\n"),HX_CSTRING("m"));		HX_STACK_VAR(chunk_re,"chunk_re");
		HX_STACK_LINE(610)
		this->chunk_size = null();
		HX_STACK_LINE(611)
		this->chunk_buf = null();
		HX_STACK_LINE(613)
		int bufsize = (int)1024;		HX_STACK_VAR(bufsize,"bufsize");
		HX_STACK_LINE(614)
		::haxe::io::Bytes buf = ::haxe::io::Bytes_obj::alloc(bufsize);		HX_STACK_VAR(buf,"buf");
		HX_STACK_LINE(615)
		if (((size == null()))){
			HX_STACK_LINE(616)
			if ((!(this->noShutdown))){
				HX_STACK_LINE(617)
				sock->__Field(HX_CSTRING("shutdown"),true)(false,true);
			}
			HX_STACK_LINE(618)
			try
			{
			HX_STACK_CATCHABLE(::haxe::io::Eof, 0);
			{
				HX_STACK_LINE(619)
				while((true)){
					HX_STACK_LINE(620)
					int len = sock->__Field(HX_CSTRING("input"),true)->__Field(HX_CSTRING("readBytes"),true)(buf,(int)0,bufsize);		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(621)
					if ((chunked)){
						HX_STACK_LINE(622)
						if ((!(this->readChunk(chunk_re,api,buf,len)))){
							HX_STACK_LINE(623)
							break;
						}
					}
					else{
						HX_STACK_LINE(625)
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
			HX_STACK_LINE(630)
			api->prepare(size);
			HX_STACK_LINE(631)
			try
			{
			HX_STACK_CATCHABLE(::haxe::io::Eof, 0);
			{
				HX_STACK_LINE(632)
				while((true)){
					HX_STACK_LINE(632)
					if ((!(((size > (int)0))))){
						HX_STACK_LINE(632)
						break;
					}
					HX_STACK_LINE(633)
					int len = sock->__Field(HX_CSTRING("input"),true)->__Field(HX_CSTRING("readBytes"),true)(buf,(int)0,(  (((size > bufsize))) ? int(bufsize) : int(size) ));		HX_STACK_VAR(len,"len");
					HX_STACK_LINE(634)
					if ((chunked)){
						HX_STACK_LINE(635)
						if ((!(this->readChunk(chunk_re,api,buf,len)))){
							HX_STACK_LINE(636)
							break;
						}
					}
					else{
						HX_STACK_LINE(638)
						api->writeBytes(buf,(int)0,len);
					}
					HX_STACK_LINE(639)
					hx::SubEq(size,len);
				}
			}
			}
			catch(Dynamic __e){
				if (__e.IsClass< ::haxe::io::Eof >() ){
					HX_STACK_BEGIN_CATCH
					::haxe::io::Eof e = __e;{
						HX_STACK_LINE(642)
						HX_STACK_DO_THROW(HX_CSTRING("Transfert aborted"));
					}
				}
				else {
				    HX_STACK_DO_THROW(__e);
				}
			}
		}
		HX_STACK_LINE(645)
		if (((bool(chunked) && bool(((bool((this->chunk_size != null())) || bool((this->chunk_buf != null())))))))){
			HX_STACK_LINE(646)
			HX_STACK_DO_THROW(HX_CSTRING("Invalid chunk"));
		}
		HX_STACK_LINE(647)
		if (((bool((status < (int)200)) || bool((status >= (int)400))))){
			HX_STACK_LINE(648)
			HX_STACK_DO_THROW((HX_CSTRING("Http Error #") + status));
		}
		HX_STACK_LINE(649)
		api->close();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Http_obj,readHttpResponse,(void))

bool Http_obj::readChunk( ::EReg chunk_re,::haxe::io::Output api,::haxe::io::Bytes buf,int len){
	HX_STACK_FRAME("haxe.Http","readChunk",0xeebfa239,"haxe.Http.readChunk","haxe/Http.hx",652,0x8e8a71ed)
	HX_STACK_THIS(this)
	HX_STACK_ARG(chunk_re,"chunk_re")
	HX_STACK_ARG(api,"api")
	HX_STACK_ARG(buf,"buf")
	HX_STACK_ARG(len,"len")
	HX_STACK_LINE(653)
	if (((this->chunk_size == null()))){
		HX_STACK_LINE(654)
		if (((this->chunk_buf != null()))){
			HX_STACK_LINE(655)
			::haxe::io::BytesBuffer b = ::haxe::io::BytesBuffer_obj::__new();		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(656)
			{
				HX_STACK_LINE(656)
				::haxe::io::Bytes src = this->chunk_buf;		HX_STACK_VAR(src,"src");
				HX_STACK_LINE(656)
				Array< unsigned char > b1 = b->b;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(656)
				Array< unsigned char > b2 = src->b;		HX_STACK_VAR(b2,"b2");
				HX_STACK_LINE(656)
				{
					HX_STACK_LINE(656)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(656)
					int _g = src->length;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(656)
					while((true)){
						HX_STACK_LINE(656)
						if ((!(((_g1 < _g))))){
							HX_STACK_LINE(656)
							break;
						}
						HX_STACK_LINE(656)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(656)
						b->b->push(b2->__get(i));
					}
				}
			}
			HX_STACK_LINE(657)
			{
				HX_STACK_LINE(657)
				if (((bool((len < (int)0)) || bool((len > buf->length))))){
					HX_STACK_LINE(657)
					HX_STACK_DO_THROW(::haxe::io::Error_obj::OutsideBounds);
				}
				HX_STACK_LINE(657)
				Array< unsigned char > b1 = b->b;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(657)
				Array< unsigned char > b2 = buf->b;		HX_STACK_VAR(b2,"b2");
				HX_STACK_LINE(657)
				{
					HX_STACK_LINE(657)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(657)
					int _g = len;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(657)
					while((true)){
						HX_STACK_LINE(657)
						if ((!(((_g1 < _g))))){
							HX_STACK_LINE(657)
							break;
						}
						HX_STACK_LINE(657)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(657)
						b->b->push(b2->__get(i));
					}
				}
			}
			HX_STACK_LINE(658)
			::haxe::io::Bytes _g = b->getBytes();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(658)
			buf = _g;
			HX_STACK_LINE(659)
			hx::AddEq(len,this->chunk_buf->length);
			HX_STACK_LINE(660)
			this->chunk_buf = null();
		}
		HX_STACK_LINE(665)
		::String _g1 = buf->toString();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(665)
		if ((chunk_re->match(_g1))){
			HX_STACK_LINE(667)
			Dynamic p = chunk_re->matchedPos();		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(668)
			if (((p->__Field(HX_CSTRING("len"),true) <= len))){
				HX_STACK_LINE(669)
				::String cstr = chunk_re->matched((int)1);		HX_STACK_VAR(cstr,"cstr");
				HX_STACK_LINE(670)
				Dynamic _g2 = ::Std_obj::parseInt((HX_CSTRING("0x") + cstr));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(670)
				this->chunk_size = _g2;
				HX_STACK_LINE(671)
				if (((cstr == HX_CSTRING("0")))){
					HX_STACK_LINE(672)
					this->chunk_size = null();
					HX_STACK_LINE(673)
					this->chunk_buf = null();
					HX_STACK_LINE(674)
					return false;
				}
				HX_STACK_LINE(676)
				hx::SubEq(len,p->__Field(HX_CSTRING("len"),true));
				HX_STACK_LINE(677)
				::haxe::io::Bytes _g3 = buf->sub(p->__Field(HX_CSTRING("len"),true),len);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(677)
				return this->readChunk(chunk_re,api,_g3,len);
			}
		}
		HX_STACK_LINE(681)
		if (((len > (int)10))){
			HX_STACK_LINE(682)
			this->onError(HX_CSTRING("Invalid chunk"));
			HX_STACK_LINE(683)
			return false;
		}
		HX_STACK_LINE(685)
		::haxe::io::Bytes _g4 = buf->sub((int)0,len);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(685)
		this->chunk_buf = _g4;
		HX_STACK_LINE(686)
		return true;
	}
	HX_STACK_LINE(688)
	if (((this->chunk_size > len))){
		HX_STACK_LINE(689)
		hx::SubEq(this->chunk_size,len);
		HX_STACK_LINE(690)
		api->writeBytes(buf,(int)0,len);
		HX_STACK_LINE(691)
		return true;
	}
	HX_STACK_LINE(693)
	int end = (this->chunk_size + (int)2);		HX_STACK_VAR(end,"end");
	HX_STACK_LINE(694)
	if (((len >= end))){
		HX_STACK_LINE(695)
		if (((this->chunk_size > (int)0))){
			HX_STACK_LINE(696)
			api->writeBytes(buf,(int)0,this->chunk_size);
		}
		HX_STACK_LINE(697)
		hx::SubEq(len,end);
		HX_STACK_LINE(698)
		this->chunk_size = null();
		HX_STACK_LINE(699)
		if (((len == (int)0))){
			HX_STACK_LINE(700)
			return true;
		}
		HX_STACK_LINE(701)
		::haxe::io::Bytes _g5 = buf->sub(end,len);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(701)
		return this->readChunk(chunk_re,api,_g5,len);
	}
	HX_STACK_LINE(703)
	if (((this->chunk_size > (int)0))){
		HX_STACK_LINE(704)
		api->writeBytes(buf,(int)0,this->chunk_size);
	}
	HX_STACK_LINE(705)
	hx::SubEq(this->chunk_size,len);
	HX_STACK_LINE(706)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC4(Http_obj,readChunk,return )

HX_BEGIN_DEFAULT_FUNC(__default_onData,Http_obj)
Void run(::String data){
{
		HX_STACK_FRAME("haxe.Http","onData",0x4f093aa7,"haxe.Http.onData","haxe/Http.hx",718,0x8e8a71ed)
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
		HX_STACK_FRAME("haxe.Http","onError",0x77abd4ab,"haxe.Http.onError","haxe/Http.hx",728,0x8e8a71ed)
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
		HX_STACK_FRAME("haxe.Http","onStatus",0xf341a4ef,"haxe.Http.onStatus","haxe/Http.hx",738,0x8e8a71ed)
		HX_STACK_THIS(this)
		HX_STACK_ARG(status,"status")
	}
return null();
}
HX_END_LOCAL_FUNC1((void))
HX_END_DEFAULT_FUNC

Dynamic Http_obj::PROXY;

::String Http_obj::requestUrl( ::String url){
	HX_STACK_FRAME("haxe.Http","requestUrl",0x3bd0d21e,"haxe.Http.requestUrl","haxe/Http.hx",750,0x8e8a71ed)
	HX_STACK_ARG(url,"url")
	HX_STACK_LINE(751)
	::haxe::Http h = ::haxe::Http_obj::__new(url);		HX_STACK_VAR(h,"h");
	HX_STACK_LINE(755)
	Array< ::String > r = Array_obj< ::String >::__new().Add(null());		HX_STACK_VAR(r,"r");

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::String >,r)
	Void run(::String d){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxe/Http.hx",757,0x8e8a71ed)
		HX_STACK_ARG(d,"d")
		{
			HX_STACK_LINE(757)
			r[(int)0] = d;
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(756)
	h->onData =  Dynamic(new _Function_1_1(r));

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_2)
	Void run(::String e){
		HX_STACK_FRAME("*","_Function_1_2",0x5200ed38,"*._Function_1_2","haxe/Http.hx",760,0x8e8a71ed)
		HX_STACK_ARG(e,"e")
		{
			HX_STACK_LINE(760)
			HX_STACK_DO_THROW(e);
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(759)
	h->onError =  Dynamic(new _Function_1_2());
	HX_STACK_LINE(762)
	h->request(false);
	HX_STACK_LINE(763)
	return r->__get((int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Http_obj,requestUrl,return )


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
	HX_MARK_MEMBER_NAME(certFile,"certFile");
	HX_MARK_MEMBER_NAME(certFolder,"certFolder");
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
	HX_VISIT_MEMBER_NAME(certFile,"certFile");
	HX_VISIT_MEMBER_NAME(certFolder,"certFolder");
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
		if (HX_FIELD_EQ(inName,"certFile") ) { return certFile; }
		if (HX_FIELD_EQ(inName,"onStatus") ) { return onStatus; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"chunk_buf") ) { return chunk_buf; }
		if (HX_FIELD_EQ(inName,"setHeader") ) { return setHeader_dyn(); }
		if (HX_FIELD_EQ(inName,"readChunk") ) { return readChunk_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"requestUrl") ) { return requestUrl_dyn(); }
		if (HX_FIELD_EQ(inName,"noShutdown") ) { return noShutdown; }
		if (HX_FIELD_EQ(inName,"cnxTimeout") ) { return cnxTimeout; }
		if (HX_FIELD_EQ(inName,"chunk_size") ) { return chunk_size; }
		if (HX_FIELD_EQ(inName,"certFolder") ) { return certFolder; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"setPostData") ) { return setPostData_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"responseData") ) { return responseData; }
		if (HX_FIELD_EQ(inName,"setParameter") ) { return setParameter_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"fileTransfert") ) { return fileTransfert_dyn(); }
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
		if (HX_FIELD_EQ(inName,"params") ) { params=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onData") ) { onData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"headers") ) { headers=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onError") ) { onError=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"postData") ) { postData=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"certFile") ) { certFile=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onStatus") ) { onStatus=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"chunk_buf") ) { chunk_buf=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"noShutdown") ) { noShutdown=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cnxTimeout") ) { cnxTimeout=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"chunk_size") ) { chunk_size=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"certFolder") ) { certFolder=inValue.Cast< ::String >(); return inValue; }
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
	outFields->push(HX_CSTRING("certFile"));
	outFields->push(HX_CSTRING("certFolder"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("PROXY"),
	HX_CSTRING("requestUrl"),
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
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(Http_obj,headers),HX_CSTRING("headers")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(Http_obj,params),HX_CSTRING("params")},
	{hx::fsString,(int)offsetof(Http_obj,certFile),HX_CSTRING("certFile")},
	{hx::fsString,(int)offsetof(Http_obj,certFolder),HX_CSTRING("certFolder")},
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
	HX_CSTRING("certFile"),
	HX_CSTRING("certFolder"),
	HX_CSTRING("setHeader"),
	HX_CSTRING("setParameter"),
	HX_CSTRING("setPostData"),
	HX_CSTRING("request"),
	HX_CSTRING("fileTransfert"),
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
