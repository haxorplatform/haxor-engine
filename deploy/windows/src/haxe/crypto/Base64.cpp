#include <hxcpp.h>

#ifndef INCLUDED_haxe_crypto_Base64
#include <haxe/crypto/Base64.h>
#endif
#ifndef INCLUDED_haxe_crypto_BaseCode
#include <haxe/crypto/BaseCode.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
namespace haxe{
namespace crypto{

Void Base64_obj::__construct()
{
	return null();
}

//Base64_obj::~Base64_obj() { }

Dynamic Base64_obj::__CreateEmpty() { return  new Base64_obj; }
hx::ObjectPtr< Base64_obj > Base64_obj::__new()
{  hx::ObjectPtr< Base64_obj > result = new Base64_obj();
	result->__construct();
	return result;}

Dynamic Base64_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Base64_obj > result = new Base64_obj();
	result->__construct();
	return result;}

::String Base64_obj::CHARS;

::haxe::io::Bytes Base64_obj::BYTES;

::String Base64_obj::encode( ::haxe::io::Bytes bytes,hx::Null< bool >  __o_complement){
bool complement = __o_complement.Default(true);
	HX_STACK_FRAME("haxe.crypto.Base64","encode",0xc6961450,"haxe.crypto.Base64.encode","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/crypto/Base64.hx",32,0x4c9cf9bd)
	HX_STACK_ARG(bytes,"bytes")
	HX_STACK_ARG(complement,"complement")
{
		HX_STACK_LINE(33)
		::String str = ::haxe::crypto::BaseCode_obj::__new(::haxe::crypto::Base64_obj::BYTES)->encodeBytes(bytes)->toString();		HX_STACK_VAR(str,"str");
		HX_STACK_LINE(34)
		if ((complement)){
			HX_STACK_LINE(35)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(35)
			int _g = hx::Mod((((int)3 - hx::Mod((bytes->length * (int)4),(int)3))),(int)3);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(35)
			while((true)){
				HX_STACK_LINE(35)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(35)
					break;
				}
				HX_STACK_LINE(35)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(36)
				hx::AddEq(str,HX_CSTRING("="));
			}
		}
		HX_STACK_LINE(37)
		return str;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Base64_obj,encode,return )

::haxe::io::Bytes Base64_obj::decode( ::String str,hx::Null< bool >  __o_complement){
bool complement = __o_complement.Default(true);
	HX_STACK_FRAME("haxe.crypto.Base64","decode",0x319f7f68,"haxe.crypto.Base64.decode","F:\\development\\resource\\platform\\haxe\\3_1_3\\haxe\\std/haxe/crypto/Base64.hx",40,0x4c9cf9bd)
	HX_STACK_ARG(str,"str")
	HX_STACK_ARG(complement,"complement")
{
		HX_STACK_LINE(41)
		if ((complement)){
			HX_STACK_LINE(42)
			while((true)){
				HX_STACK_LINE(42)
				Dynamic _g = str.charCodeAt((str.length - (int)1));		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(42)
				if ((!(((_g == (int)61))))){
					HX_STACK_LINE(42)
					break;
				}
				HX_STACK_LINE(43)
				::String _g1 = str.substr((int)0,(int)-1);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(43)
				str = _g1;
			}
		}
		HX_STACK_LINE(44)
		::haxe::io::Bytes _g2 = ::haxe::io::Bytes_obj::ofString(str);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(44)
		return ::haxe::crypto::BaseCode_obj::__new(::haxe::crypto::Base64_obj::BYTES)->decodeBytes(_g2);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Base64_obj,decode,return )


Base64_obj::Base64_obj()
{
}

Dynamic Base64_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"CHARS") ) { return CHARS; }
		if (HX_FIELD_EQ(inName,"BYTES") ) { return BYTES; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"encode") ) { return encode_dyn(); }
		if (HX_FIELD_EQ(inName,"decode") ) { return decode_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Base64_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"CHARS") ) { CHARS=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BYTES") ) { BYTES=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Base64_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("CHARS"),
	HX_CSTRING("BYTES"),
	HX_CSTRING("encode"),
	HX_CSTRING("decode"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Base64_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Base64_obj::CHARS,"CHARS");
	HX_MARK_MEMBER_NAME(Base64_obj::BYTES,"BYTES");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Base64_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Base64_obj::CHARS,"CHARS");
	HX_VISIT_MEMBER_NAME(Base64_obj::BYTES,"BYTES");
};

#endif

Class Base64_obj::__mClass;

void Base64_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.crypto.Base64"), hx::TCanCast< Base64_obj> ,sStaticFields,sMemberFields,
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

void Base64_obj::__boot()
{
	CHARS= HX_CSTRING("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
	BYTES= ::haxe::io::Bytes_obj::ofString(::haxe::crypto::Base64_obj::CHARS);
}

} // end namespace haxe
} // end namespace crypto
