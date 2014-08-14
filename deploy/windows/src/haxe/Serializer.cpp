#include <hxcpp.h>

#ifndef INCLUDED_Date
#include <Date.h>
#endif
#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Reflect
#include <Reflect.h>
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
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_ValueType
#include <ValueType.h>
#endif
#ifndef INCLUDED_haxe_Serializer
#include <haxe/Serializer.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxe{

Void Serializer_obj::__construct()
{
HX_STACK_FRAME("haxe.Serializer","new",0xcdbbc7ec,"haxe.Serializer.new","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Serializer.hx",100,0xd4456af0)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(101)
	::StringBuf _g = ::StringBuf_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(101)
	this->buf = _g;
	HX_STACK_LINE(102)
	Dynamic _g1 = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(102)
	this->cache = _g1;
	HX_STACK_LINE(103)
	this->useCache = ::haxe::Serializer_obj::USE_CACHE;
	HX_STACK_LINE(104)
	this->useEnumIndex = ::haxe::Serializer_obj::USE_ENUM_INDEX;
	HX_STACK_LINE(105)
	::haxe::ds::StringMap _g2 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(105)
	this->shash = _g2;
	HX_STACK_LINE(106)
	this->scount = (int)0;
}
;
	return null();
}

//Serializer_obj::~Serializer_obj() { }

Dynamic Serializer_obj::__CreateEmpty() { return  new Serializer_obj; }
hx::ObjectPtr< Serializer_obj > Serializer_obj::__new()
{  hx::ObjectPtr< Serializer_obj > result = new Serializer_obj();
	result->__construct();
	return result;}

Dynamic Serializer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Serializer_obj > result = new Serializer_obj();
	result->__construct();
	return result;}

::String Serializer_obj::toString( ){
	HX_STACK_FRAME("haxe.Serializer","toString",0x95bdfda0,"haxe.Serializer.toString","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Serializer.hx",116,0xd4456af0)
	HX_STACK_THIS(this)
	HX_STACK_LINE(116)
	return this->buf->b->join(HX_CSTRING(""));
}


HX_DEFINE_DYNAMIC_FUNC0(Serializer_obj,toString,return )

Void Serializer_obj::serializeString( ::String s){
{
		HX_STACK_FRAME("haxe.Serializer","serializeString",0xd565bc5d,"haxe.Serializer.serializeString","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Serializer.hx",150,0xd4456af0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(151)
		Dynamic x = this->shash->get(s);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(152)
		if (((x != null()))){
			HX_STACK_LINE(153)
			this->buf->add(HX_CSTRING("R"));
			HX_STACK_LINE(154)
			this->buf->add(x);
			HX_STACK_LINE(155)
			return null();
		}
		HX_STACK_LINE(157)
		int _g = (this->scount)++;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(157)
		this->shash->set(s,_g);
		HX_STACK_LINE(162)
		this->buf->add(HX_CSTRING("y"));
		HX_STACK_LINE(163)
		::String _g1 = ::StringTools_obj::urlEncode(s);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(163)
		s = _g1;
		HX_STACK_LINE(164)
		this->buf->add(s.length);
		HX_STACK_LINE(165)
		this->buf->add(HX_CSTRING(":"));
		HX_STACK_LINE(166)
		this->buf->add(s);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeString,(void))

bool Serializer_obj::serializeRef( Dynamic v){
	HX_STACK_FRAME("haxe.Serializer","serializeRef",0x0b8ed647,"haxe.Serializer.serializeRef","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Serializer.hx",169,0xd4456af0)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(173)
	{
		HX_STACK_LINE(173)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(173)
		int _g = this->cache->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(173)
		while((true)){
			HX_STACK_LINE(173)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(173)
				break;
			}
			HX_STACK_LINE(173)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(178)
			if (((this->cache->__GetItem(i) == v))){
				HX_STACK_LINE(180)
				this->buf->add(HX_CSTRING("r"));
				HX_STACK_LINE(181)
				this->buf->add(i);
				HX_STACK_LINE(182)
				return true;
			}
		}
	}
	HX_STACK_LINE(185)
	this->cache->__Field(HX_CSTRING("push"),true)(v);
	HX_STACK_LINE(186)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeRef,return )

Void Serializer_obj::serializeFields( Dynamic v){
{
		HX_STACK_FRAME("haxe.Serializer","serializeFields",0x44c42205,"haxe.Serializer.serializeFields","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Serializer.hx",206,0xd4456af0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(207)
		{
			HX_STACK_LINE(207)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(207)
			Array< ::String > _g1 = ::Reflect_obj::fields(v);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(207)
			while((true)){
				HX_STACK_LINE(207)
				if ((!(((_g < _g1->length))))){
					HX_STACK_LINE(207)
					break;
				}
				HX_STACK_LINE(207)
				::String f = _g1->__get(_g);		HX_STACK_VAR(f,"f");
				HX_STACK_LINE(207)
				++(_g);
				HX_STACK_LINE(208)
				this->serializeString(f);
				HX_STACK_LINE(209)
				Dynamic _g2 = ::Reflect_obj::field(v,f);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(209)
				this->serialize(_g2);
			}
		}
		HX_STACK_LINE(211)
		this->buf->add(HX_CSTRING("g"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeFields,(void))

Void Serializer_obj::serialize( Dynamic v){
{
		HX_STACK_FRAME("haxe.Serializer","serialize",0x3cea866c,"haxe.Serializer.serialize","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Serializer.hx",225,0xd4456af0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(225)
		{
			HX_STACK_LINE(225)
			::ValueType _g = ::Type_obj::_typeof(v);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(225)
			switch( (int)(_g->__Index())){
				case (int)0: {
					HX_STACK_LINE(227)
					this->buf->add(HX_CSTRING("n"));
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(229)
					int v1 = v;		HX_STACK_VAR(v1,"v1");
					HX_STACK_LINE(230)
					if (((v1 == (int)0))){
						HX_STACK_LINE(231)
						this->buf->add(HX_CSTRING("z"));
						HX_STACK_LINE(232)
						return null();
					}
					HX_STACK_LINE(234)
					this->buf->add(HX_CSTRING("i"));
					HX_STACK_LINE(235)
					this->buf->add(v1);
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(237)
					Float v1 = v;		HX_STACK_VAR(v1,"v1");
					HX_STACK_LINE(238)
					if ((::Math_obj::isNaN(v1))){
						HX_STACK_LINE(239)
						this->buf->add(HX_CSTRING("k"));
					}
					else{
						HX_STACK_LINE(240)
						if ((!(::Math_obj::isFinite(v1)))){
							HX_STACK_LINE(241)
							this->buf->add((  (((v1 < (int)0))) ? ::String(HX_CSTRING("m")) : ::String(HX_CSTRING("p")) ));
						}
						else{
							HX_STACK_LINE(243)
							this->buf->add(HX_CSTRING("d"));
							HX_STACK_LINE(244)
							this->buf->add(v1);
						}
					}
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(247)
					this->buf->add((  ((v)) ? ::String(HX_CSTRING("t")) : ::String(HX_CSTRING("f")) ));
				}
				;break;
				case (int)6: {
					HX_STACK_LINE(225)
					::Class c = (::ValueType(_g))->__Param(0);		HX_STACK_VAR(c,"c");
					HX_STACK_LINE(248)
					{
						HX_STACK_LINE(249)
						if (((c == hx::ClassOf< ::String >()))){
							HX_STACK_LINE(250)
							this->serializeString(v);
							HX_STACK_LINE(251)
							return null();
						}
						HX_STACK_LINE(253)
						if (((  ((this->useCache)) ? bool(this->serializeRef(v)) : bool(false) ))){
							HX_STACK_LINE(254)
							return null();
						}
						HX_STACK_LINE(255)
						::Class _switch_1 = (c);
						if (  ( _switch_1==hx::ClassOf< Array<int> >())){
							HX_STACK_LINE(257)
							int ucount = (int)0;		HX_STACK_VAR(ucount,"ucount");
							HX_STACK_LINE(258)
							this->buf->add(HX_CSTRING("a"));
							HX_STACK_LINE(262)
							int l = v->__length();		HX_STACK_VAR(l,"l");
							HX_STACK_LINE(263)
							{
								HX_STACK_LINE(263)
								int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
								HX_STACK_LINE(263)
								while((true)){
									HX_STACK_LINE(263)
									if ((!(((_g1 < l))))){
										HX_STACK_LINE(263)
										break;
									}
									HX_STACK_LINE(263)
									int i = (_g1)++;		HX_STACK_VAR(i,"i");
									HX_STACK_LINE(264)
									if (((v->__GetItem(i) == null()))){
										HX_STACK_LINE(265)
										(ucount)++;
									}
									else{
										HX_STACK_LINE(267)
										if (((ucount > (int)0))){
											HX_STACK_LINE(268)
											if (((ucount == (int)1))){
												HX_STACK_LINE(269)
												this->buf->add(HX_CSTRING("n"));
											}
											else{
												HX_STACK_LINE(271)
												this->buf->add(HX_CSTRING("u"));
												HX_STACK_LINE(272)
												this->buf->add(ucount);
											}
											HX_STACK_LINE(274)
											ucount = (int)0;
										}
										HX_STACK_LINE(276)
										this->serialize(v->__GetItem(i));
									}
								}
							}
							HX_STACK_LINE(279)
							if (((ucount > (int)0))){
								HX_STACK_LINE(280)
								if (((ucount == (int)1))){
									HX_STACK_LINE(281)
									this->buf->add(HX_CSTRING("n"));
								}
								else{
									HX_STACK_LINE(283)
									this->buf->add(HX_CSTRING("u"));
									HX_STACK_LINE(284)
									this->buf->add(ucount);
								}
							}
							HX_STACK_LINE(287)
							this->buf->add(HX_CSTRING("h"));
						}
						else if (  ( _switch_1==hx::ClassOf< ::List >())){
							HX_STACK_LINE(289)
							this->buf->add(HX_CSTRING("l"));
							HX_STACK_LINE(290)
							::List v1 = v;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(291)
							for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(v1->iterator());  __it->hasNext(); ){
								Dynamic i = __it->next();
								this->serialize(i);
							}
							HX_STACK_LINE(293)
							this->buf->add(HX_CSTRING("h"));
						}
						else if (  ( _switch_1==hx::ClassOf< ::Date >())){
							HX_STACK_LINE(295)
							::Date d = v;		HX_STACK_VAR(d,"d");
							HX_STACK_LINE(296)
							this->buf->add(HX_CSTRING("v"));
							HX_STACK_LINE(297)
							::String _g1 = d->toString();		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(297)
							this->buf->add(_g1);
						}
						else if (  ( _switch_1==hx::ClassOf< ::haxe::ds::StringMap >())){
							HX_STACK_LINE(299)
							this->buf->add(HX_CSTRING("b"));
							HX_STACK_LINE(300)
							::haxe::ds::StringMap v1 = v;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(301)
							for(::cpp::FastIterator_obj< ::String > *__it = ::cpp::CreateFastIterator< ::String >(v1->keys());  __it->hasNext(); ){
								::String k = __it->next();
								{
									HX_STACK_LINE(302)
									this->serializeString(k);
									HX_STACK_LINE(303)
									Dynamic _g1 = v1->get(k);		HX_STACK_VAR(_g1,"_g1");
									HX_STACK_LINE(303)
									this->serialize(_g1);
								}
;
							}
							HX_STACK_LINE(305)
							this->buf->add(HX_CSTRING("h"));
						}
						else if (  ( _switch_1==hx::ClassOf< ::haxe::ds::IntMap >())){
							HX_STACK_LINE(307)
							this->buf->add(HX_CSTRING("q"));
							HX_STACK_LINE(308)
							::haxe::ds::IntMap v1 = v;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(309)
							for(::cpp::FastIterator_obj< int > *__it = ::cpp::CreateFastIterator< int >(v1->keys());  __it->hasNext(); ){
								int k = __it->next();
								{
									HX_STACK_LINE(310)
									this->buf->add(HX_CSTRING(":"));
									HX_STACK_LINE(311)
									this->buf->add(k);
									HX_STACK_LINE(312)
									Dynamic _g2 = v1->get(k);		HX_STACK_VAR(_g2,"_g2");
									HX_STACK_LINE(312)
									this->serialize(_g2);
								}
;
							}
							HX_STACK_LINE(314)
							this->buf->add(HX_CSTRING("h"));
						}
						else if (  ( _switch_1==hx::ClassOf< ::haxe::ds::ObjectMap >())){
							HX_STACK_LINE(316)
							this->buf->add(HX_CSTRING("M"));
							HX_STACK_LINE(317)
							::haxe::ds::ObjectMap v1 = v;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(318)
							for(::cpp::FastIterator_obj< Dynamic > *__it = ::cpp::CreateFastIterator< Dynamic >(v1->keys());  __it->hasNext(); ){
								Dynamic k = __it->next();
								{
									HX_STACK_LINE(325)
									this->serialize(k);
									HX_STACK_LINE(327)
									Dynamic _g3 = v1->get(k);		HX_STACK_VAR(_g3,"_g3");
									HX_STACK_LINE(327)
									this->serialize(_g3);
								}
;
							}
							HX_STACK_LINE(329)
							this->buf->add(HX_CSTRING("h"));
						}
						else if (  ( _switch_1==hx::ClassOf< ::haxe::io::Bytes >())){
							HX_STACK_LINE(331)
							::haxe::io::Bytes v1 = v;		HX_STACK_VAR(v1,"v1");
							HX_STACK_LINE(335)
							int i = (int)0;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(336)
							int max = (v1->length - (int)2);		HX_STACK_VAR(max,"max");
							HX_STACK_LINE(337)
							::StringBuf charsBuf = ::StringBuf_obj::__new();		HX_STACK_VAR(charsBuf,"charsBuf");
							HX_STACK_LINE(338)
							::String b64 = ::haxe::Serializer_obj::BASE64;		HX_STACK_VAR(b64,"b64");
							HX_STACK_LINE(339)
							while((true)){
								HX_STACK_LINE(339)
								if ((!(((i < max))))){
									HX_STACK_LINE(339)
									break;
								}
								HX_STACK_LINE(340)
								int b1;		HX_STACK_VAR(b1,"b1");
								HX_STACK_LINE(340)
								{
									HX_STACK_LINE(340)
									int pos = (i)++;		HX_STACK_VAR(pos,"pos");
									HX_STACK_LINE(340)
									b1 = v1->b->__get(pos);
								}
								HX_STACK_LINE(341)
								int b2;		HX_STACK_VAR(b2,"b2");
								HX_STACK_LINE(341)
								{
									HX_STACK_LINE(341)
									int pos = (i)++;		HX_STACK_VAR(pos,"pos");
									HX_STACK_LINE(341)
									b2 = v1->b->__get(pos);
								}
								HX_STACK_LINE(342)
								int b3;		HX_STACK_VAR(b3,"b3");
								HX_STACK_LINE(342)
								{
									HX_STACK_LINE(342)
									int pos = (i)++;		HX_STACK_VAR(pos,"pos");
									HX_STACK_LINE(342)
									b3 = v1->b->__get(pos);
								}
								HX_STACK_LINE(344)
								::String _g4 = b64.charAt((int(b1) >> int((int)2)));		HX_STACK_VAR(_g4,"_g4");
								HX_STACK_LINE(344)
								charsBuf->add(_g4);
								HX_STACK_LINE(345)
								::String _g5 = b64.charAt((int(((int((int(b1) << int((int)4))) | int((int(b2) >> int((int)4)))))) & int((int)63)));		HX_STACK_VAR(_g5,"_g5");
								HX_STACK_LINE(345)
								charsBuf->add(_g5);
								HX_STACK_LINE(346)
								::String _g6 = b64.charAt((int(((int((int(b2) << int((int)2))) | int((int(b3) >> int((int)6)))))) & int((int)63)));		HX_STACK_VAR(_g6,"_g6");
								HX_STACK_LINE(346)
								charsBuf->add(_g6);
								HX_STACK_LINE(347)
								::String _g7 = b64.charAt((int(b3) & int((int)63)));		HX_STACK_VAR(_g7,"_g7");
								HX_STACK_LINE(347)
								charsBuf->add(_g7);
							}
							HX_STACK_LINE(349)
							if (((i == max))){
								HX_STACK_LINE(350)
								int b1;		HX_STACK_VAR(b1,"b1");
								HX_STACK_LINE(350)
								{
									HX_STACK_LINE(350)
									int pos = (i)++;		HX_STACK_VAR(pos,"pos");
									HX_STACK_LINE(350)
									b1 = v1->b->__get(pos);
								}
								HX_STACK_LINE(351)
								int b2;		HX_STACK_VAR(b2,"b2");
								HX_STACK_LINE(351)
								{
									HX_STACK_LINE(351)
									int pos = (i)++;		HX_STACK_VAR(pos,"pos");
									HX_STACK_LINE(351)
									b2 = v1->b->__get(pos);
								}
								HX_STACK_LINE(352)
								::String _g8 = b64.charAt((int(b1) >> int((int)2)));		HX_STACK_VAR(_g8,"_g8");
								HX_STACK_LINE(352)
								charsBuf->add(_g8);
								HX_STACK_LINE(353)
								::String _g9 = b64.charAt((int(((int((int(b1) << int((int)4))) | int((int(b2) >> int((int)4)))))) & int((int)63)));		HX_STACK_VAR(_g9,"_g9");
								HX_STACK_LINE(353)
								charsBuf->add(_g9);
								HX_STACK_LINE(354)
								::String _g10 = b64.charAt((int((int(b2) << int((int)2))) & int((int)63)));		HX_STACK_VAR(_g10,"_g10");
								HX_STACK_LINE(354)
								charsBuf->add(_g10);
							}
							else{
								HX_STACK_LINE(355)
								if (((i == (max + (int)1)))){
									HX_STACK_LINE(356)
									int b1;		HX_STACK_VAR(b1,"b1");
									HX_STACK_LINE(356)
									{
										HX_STACK_LINE(356)
										int pos = (i)++;		HX_STACK_VAR(pos,"pos");
										HX_STACK_LINE(356)
										b1 = v1->b->__get(pos);
									}
									HX_STACK_LINE(357)
									::String _g11 = b64.charAt((int(b1) >> int((int)2)));		HX_STACK_VAR(_g11,"_g11");
									HX_STACK_LINE(357)
									charsBuf->add(_g11);
									HX_STACK_LINE(358)
									::String _g12 = b64.charAt((int((int(b1) << int((int)4))) & int((int)63)));		HX_STACK_VAR(_g12,"_g12");
									HX_STACK_LINE(358)
									charsBuf->add(_g12);
								}
							}
							HX_STACK_LINE(360)
							::String chars = charsBuf->b->join(HX_CSTRING(""));		HX_STACK_VAR(chars,"chars");
							HX_STACK_LINE(362)
							this->buf->add(HX_CSTRING("s"));
							HX_STACK_LINE(363)
							this->buf->add(chars.length);
							HX_STACK_LINE(364)
							this->buf->add(HX_CSTRING(":"));
							HX_STACK_LINE(365)
							this->buf->add(chars);
						}
						else  {
							HX_STACK_LINE(367)
							if ((this->useCache)){
								HX_STACK_LINE(367)
								this->cache->__Field(HX_CSTRING("pop"),true)();
							}
							HX_STACK_LINE(368)
							if (((v->__Field(HX_CSTRING("hxSerialize"),true) != null()))){
								HX_STACK_LINE(369)
								this->buf->add(HX_CSTRING("C"));
								HX_STACK_LINE(370)
								::String _g13 = ::Type_obj::getClassName(c);		HX_STACK_VAR(_g13,"_g13");
								HX_STACK_LINE(370)
								this->serializeString(_g13);
								HX_STACK_LINE(371)
								if ((this->useCache)){
									HX_STACK_LINE(371)
									this->cache->__Field(HX_CSTRING("push"),true)(v);
								}
								HX_STACK_LINE(372)
								v->__Field(HX_CSTRING("hxSerialize"),true)(hx::ObjectPtr<OBJ_>(this));
								HX_STACK_LINE(373)
								this->buf->add(HX_CSTRING("g"));
							}
							else{
								HX_STACK_LINE(375)
								this->buf->add(HX_CSTRING("c"));
								HX_STACK_LINE(376)
								::String _g14 = ::Type_obj::getClassName(c);		HX_STACK_VAR(_g14,"_g14");
								HX_STACK_LINE(376)
								this->serializeString(_g14);
								HX_STACK_LINE(377)
								if ((this->useCache)){
									HX_STACK_LINE(377)
									this->cache->__Field(HX_CSTRING("push"),true)(v);
								}
								HX_STACK_LINE(381)
								this->serializeFields(v);
							}
						}
;
;
					}
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(386)
					if (((  ((this->useCache)) ? bool(this->serializeRef(v)) : bool(false) ))){
						HX_STACK_LINE(387)
						return null();
					}
					HX_STACK_LINE(388)
					this->buf->add(HX_CSTRING("o"));
					HX_STACK_LINE(389)
					this->serializeFields(v);
				}
				;break;
				case (int)7: {
					HX_STACK_LINE(225)
					::Enum e = (::ValueType(_g))->__Param(0);		HX_STACK_VAR(e,"e");
					HX_STACK_LINE(390)
					{
						HX_STACK_LINE(391)
						if ((this->useCache)){
							HX_STACK_LINE(392)
							if ((this->serializeRef(v))){
								HX_STACK_LINE(393)
								return null();
							}
							HX_STACK_LINE(394)
							this->cache->__Field(HX_CSTRING("pop"),true)();
						}
						HX_STACK_LINE(396)
						this->buf->add((  ((this->useEnumIndex)) ? ::String(HX_CSTRING("j")) : ::String(HX_CSTRING("w")) ));
						HX_STACK_LINE(397)
						::String _g15 = ::Type_obj::getEnumName(e);		HX_STACK_VAR(_g15,"_g15");
						HX_STACK_LINE(397)
						this->serializeString(_g15);
						HX_STACK_LINE(430)
						if ((this->useEnumIndex)){
							HX_STACK_LINE(431)
							this->buf->add(HX_CSTRING(":"));
							HX_STACK_LINE(432)
							Dynamic _g16 = v->__Index();		HX_STACK_VAR(_g16,"_g16");
							HX_STACK_LINE(432)
							this->buf->add(_g16);
						}
						else{
							HX_STACK_LINE(434)
							Dynamic _g17 = v->__Tag();		HX_STACK_VAR(_g17,"_g17");
							HX_STACK_LINE(434)
							this->serializeString(_g17);
						}
						HX_STACK_LINE(435)
						this->buf->add(HX_CSTRING(":"));
						HX_STACK_LINE(436)
						Dynamic pl = v->__EnumParams();		HX_STACK_VAR(pl,"pl");
						HX_STACK_LINE(437)
						if (((pl == null()))){
							HX_STACK_LINE(438)
							this->buf->add((int)0);
						}
						else{
							HX_STACK_LINE(440)
							this->buf->add(pl->__Field(HX_CSTRING("length"),true));
							HX_STACK_LINE(441)
							{
								HX_STACK_LINE(441)
								int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
								HX_STACK_LINE(441)
								while((true)){
									HX_STACK_LINE(441)
									if ((!(((_g1 < pl->__Field(HX_CSTRING("length"),true)))))){
										HX_STACK_LINE(441)
										break;
									}
									HX_STACK_LINE(441)
									Dynamic p = pl->__GetItem(_g1);		HX_STACK_VAR(p,"p");
									HX_STACK_LINE(441)
									++(_g1);
									HX_STACK_LINE(442)
									this->serialize(p);
								}
							}
						}
						HX_STACK_LINE(488)
						if ((this->useCache)){
							HX_STACK_LINE(488)
							this->cache->__Field(HX_CSTRING("push"),true)(v);
						}
					}
				}
				;break;
				case (int)5: {
					HX_STACK_LINE(490)
					HX_STACK_DO_THROW(HX_CSTRING("Cannot serialize function"));
				}
				;break;
				default: {
					HX_STACK_LINE(499)
					::String _g18 = ::Std_obj::string(v);		HX_STACK_VAR(_g18,"_g18");
					HX_STACK_LINE(499)
					HX_STACK_DO_THROW((HX_CSTRING("Cannot serialize ") + _g18));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serialize,(void))

Void Serializer_obj::serializeException( Dynamic e){
{
		HX_STACK_FRAME("haxe.Serializer","serializeException",0xdb6c3c43,"haxe.Serializer.serializeException","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/Serializer.hx",503,0xd4456af0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(504)
		this->buf->add(HX_CSTRING("x"));
		HX_STACK_LINE(516)
		this->serialize(e);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Serializer_obj,serializeException,(void))

bool Serializer_obj::USE_CACHE;

bool Serializer_obj::USE_ENUM_INDEX;

::String Serializer_obj::BASE64;


Serializer_obj::Serializer_obj()
{
}

void Serializer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Serializer);
	HX_MARK_MEMBER_NAME(buf,"buf");
	HX_MARK_MEMBER_NAME(cache,"cache");
	HX_MARK_MEMBER_NAME(shash,"shash");
	HX_MARK_MEMBER_NAME(scount,"scount");
	HX_MARK_MEMBER_NAME(useCache,"useCache");
	HX_MARK_MEMBER_NAME(useEnumIndex,"useEnumIndex");
	HX_MARK_END_CLASS();
}

void Serializer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(buf,"buf");
	HX_VISIT_MEMBER_NAME(cache,"cache");
	HX_VISIT_MEMBER_NAME(shash,"shash");
	HX_VISIT_MEMBER_NAME(scount,"scount");
	HX_VISIT_MEMBER_NAME(useCache,"useCache");
	HX_VISIT_MEMBER_NAME(useEnumIndex,"useEnumIndex");
}

Dynamic Serializer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { return buf; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"cache") ) { return cache; }
		if (HX_FIELD_EQ(inName,"shash") ) { return shash; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BASE64") ) { return BASE64; }
		if (HX_FIELD_EQ(inName,"scount") ) { return scount; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"useCache") ) { return useCache; }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"USE_CACHE") ) { return USE_CACHE; }
		if (HX_FIELD_EQ(inName,"serialize") ) { return serialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"useEnumIndex") ) { return useEnumIndex; }
		if (HX_FIELD_EQ(inName,"serializeRef") ) { return serializeRef_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"USE_ENUM_INDEX") ) { return USE_ENUM_INDEX; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"serializeString") ) { return serializeString_dyn(); }
		if (HX_FIELD_EQ(inName,"serializeFields") ) { return serializeFields_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"serializeException") ) { return serializeException_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Serializer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"buf") ) { buf=inValue.Cast< ::StringBuf >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"cache") ) { cache=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shash") ) { shash=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"BASE64") ) { BASE64=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scount") ) { scount=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"useCache") ) { useCache=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"USE_CACHE") ) { USE_CACHE=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"useEnumIndex") ) { useEnumIndex=inValue.Cast< bool >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"USE_ENUM_INDEX") ) { USE_ENUM_INDEX=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Serializer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("buf"));
	outFields->push(HX_CSTRING("cache"));
	outFields->push(HX_CSTRING("shash"));
	outFields->push(HX_CSTRING("scount"));
	outFields->push(HX_CSTRING("useCache"));
	outFields->push(HX_CSTRING("useEnumIndex"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("USE_CACHE"),
	HX_CSTRING("USE_ENUM_INDEX"),
	HX_CSTRING("BASE64"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::StringBuf*/ ,(int)offsetof(Serializer_obj,buf),HX_CSTRING("buf")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Serializer_obj,cache),HX_CSTRING("cache")},
	{hx::fsObject /*::haxe::ds::StringMap*/ ,(int)offsetof(Serializer_obj,shash),HX_CSTRING("shash")},
	{hx::fsInt,(int)offsetof(Serializer_obj,scount),HX_CSTRING("scount")},
	{hx::fsBool,(int)offsetof(Serializer_obj,useCache),HX_CSTRING("useCache")},
	{hx::fsBool,(int)offsetof(Serializer_obj,useEnumIndex),HX_CSTRING("useEnumIndex")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("buf"),
	HX_CSTRING("cache"),
	HX_CSTRING("shash"),
	HX_CSTRING("scount"),
	HX_CSTRING("useCache"),
	HX_CSTRING("useEnumIndex"),
	HX_CSTRING("toString"),
	HX_CSTRING("serializeString"),
	HX_CSTRING("serializeRef"),
	HX_CSTRING("serializeFields"),
	HX_CSTRING("serialize"),
	HX_CSTRING("serializeException"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Serializer_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Serializer_obj::USE_CACHE,"USE_CACHE");
	HX_MARK_MEMBER_NAME(Serializer_obj::USE_ENUM_INDEX,"USE_ENUM_INDEX");
	HX_MARK_MEMBER_NAME(Serializer_obj::BASE64,"BASE64");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Serializer_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Serializer_obj::USE_CACHE,"USE_CACHE");
	HX_VISIT_MEMBER_NAME(Serializer_obj::USE_ENUM_INDEX,"USE_ENUM_INDEX");
	HX_VISIT_MEMBER_NAME(Serializer_obj::BASE64,"BASE64");
};

#endif

Class Serializer_obj::__mClass;

void Serializer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.Serializer"), hx::TCanCast< Serializer_obj> ,sStaticFields,sMemberFields,
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

void Serializer_obj::__boot()
{
	USE_CACHE= false;
	USE_ENUM_INDEX= false;
	BASE64= HX_CSTRING("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:");
}

} // end namespace haxe
