#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_haxe_crypto_Base64
#include <haxe/crypto/Base64.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
namespace haxor{
namespace io{

Void Buffer_obj::__construct(int p_length)
{
HX_STACK_FRAME("haxor.io.Buffer","new",0xda1b4a6e,"haxor.io.Buffer.new","haxor/io/Buffer.hx",76,0x07055222)
HX_STACK_THIS(this)
HX_STACK_ARG(p_length,"p_length")
{
	HX_STACK_LINE(76)
	this->Resize(p_length);
}
;
	return null();
}

//Buffer_obj::~Buffer_obj() { }

Dynamic Buffer_obj::__CreateEmpty() { return  new Buffer_obj; }
hx::ObjectPtr< Buffer_obj > Buffer_obj::__new(int p_length)
{  hx::ObjectPtr< Buffer_obj > result = new Buffer_obj();
	result->__construct(p_length);
	return result;}

Dynamic Buffer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Buffer_obj > result = new Buffer_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxe::io::Bytes Buffer_obj::get_buffer( ){
	HX_STACK_FRAME("haxor.io.Buffer","get_buffer",0xe95a307b,"haxor.io.Buffer.get_buffer","haxor/io/Buffer.hx",40,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_LINE(40)
	return this->m_buffer;
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,get_buffer,return )

int Buffer_obj::get_byteLength( ){
	HX_STACK_FRAME("haxor.io.Buffer","get_byteLength",0xbd506b09,"haxor.io.Buffer.get_byteLength","haxor/io/Buffer.hx",48,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_LINE(48)
	int _g = this->get_bytesPerElement();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(48)
	return (this->m_length * _g);
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,get_byteLength,return )

int Buffer_obj::get_bytesPerElement( ){
	HX_STACK_FRAME("haxor.io.Buffer","get_bytesPerElement",0x16c52ccf,"haxor.io.Buffer.get_bytesPerElement","haxor/io/Buffer.hx",54,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_LINE(54)
	return (int)1;
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,get_bytesPerElement,return )

int Buffer_obj::get_length( ){
	HX_STACK_FRAME("haxor.io.Buffer","get_length",0xb7cd0861,"haxor.io.Buffer.get_length","haxor/io/Buffer.hx",61,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_LINE(61)
	return this->m_length;
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,get_length,return )

Void Buffer_obj::Resize( int p_length){
{
		HX_STACK_FRAME("haxor.io.Buffer","Resize",0x26f190c6,"haxor.io.Buffer.Resize","haxor/io/Buffer.hx",84,0x07055222)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_length,"p_length")
		HX_STACK_LINE(85)
		this->m_length = p_length;
		HX_STACK_LINE(86)
		int _g = this->get_bytesPerElement();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(86)
		int len = (this->m_length * _g);		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(87)
		this->m_offset = (int)0;
		HX_STACK_LINE(95)
		::haxe::io::Bytes _g1 = ::haxe::io::Bytes_obj::alloc(len);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(95)
		this->m_buffer = _g1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Buffer_obj,Resize,(void))

int Buffer_obj::GetByte( int p_index){
	HX_STACK_FRAME("haxor.io.Buffer","GetByte",0x9c9f8fac,"haxor.io.Buffer.GetByte","haxor/io/Buffer.hx",109,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_LINE(115)
	return this->m_buffer->b->__get(p_index);
	HX_STACK_LINE(122)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC1(Buffer_obj,GetByte,return )

Void Buffer_obj::SetByte( int p_index,int p_value){
{
		HX_STACK_FRAME("haxor.io.Buffer","SetByte",0x8fa120b8,"haxor.io.Buffer.SetByte","haxor/io/Buffer.hx",137,0x07055222)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_index,"p_index")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(137)
		this->m_buffer->b[p_index] = p_value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Buffer_obj,SetByte,(void))

Void Buffer_obj::SetBytes( Array< int > p_list,hx::Null< int >  __o_p_offset){
int p_offset = __o_p_offset.Default(0);
	HX_STACK_FRAME("haxor.io.Buffer","SetBytes",0x1d5b80bb,"haxor.io.Buffer.SetBytes","haxor/io/Buffer.hx",151,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_list,"p_list")
	HX_STACK_ARG(p_offset,"p_offset")
{
		HX_STACK_LINE(151)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(151)
		int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(151)
		while((true)){
			HX_STACK_LINE(151)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(151)
				break;
			}
			HX_STACK_LINE(151)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(151)
			this->SetByte((i + p_offset),p_list->__get(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Buffer_obj,SetBytes,(void))

Void Buffer_obj::SetBuffer( ::haxor::io::Buffer p_target,hx::Null< int >  __o_p_offset){
int p_offset = __o_p_offset.Default(0);
	HX_STACK_FRAME("haxor.io.Buffer","SetBuffer",0x3bda8ab0,"haxor.io.Buffer.SetBuffer","haxor/io/Buffer.hx",160,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_target,"p_target")
	HX_STACK_ARG(p_offset,"p_offset")
{
		HX_STACK_LINE(160)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(160)
		int _g = p_target->get_bytesPerElement();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(160)
		int _g2 = (p_target->m_length * _g);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(160)
		while((true)){
			HX_STACK_LINE(160)
			if ((!(((_g1 < _g2))))){
				HX_STACK_LINE(160)
				break;
			}
			HX_STACK_LINE(160)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(160)
			int _g11 = p_target->GetByte(i);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(160)
			this->SetByte((i + p_offset),_g11);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Buffer_obj,SetBuffer,(void))

::String Buffer_obj::EncodeBase64( ){
	HX_STACK_FRAME("haxor.io.Buffer","EncodeBase64",0x6b983897,"haxor.io.Buffer.EncodeBase64","haxor/io/Buffer.hx",168,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_LINE(169)
	int _g = this->get_bytesPerElement();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(169)
	int _g1 = (this->m_length * _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(169)
	::haxe::io::Bytes b = ::haxe::io::Bytes_obj::alloc(_g1);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(170)
	{
		HX_STACK_LINE(170)
		int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(170)
		int _g2 = b->length;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(170)
		while((true)){
			HX_STACK_LINE(170)
			if ((!(((_g11 < _g2))))){
				HX_STACK_LINE(170)
				break;
			}
			HX_STACK_LINE(170)
			int i = (_g11)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(170)
			int v = this->GetByte(i);		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(170)
			b->b[i] = v;
		}
	}
	HX_STACK_LINE(171)
	::String res = ::haxe::crypto::Base64_obj::encode(b,null());		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(172)
	int _g2 = this->get_bytesPerElement();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(172)
	Float _g3 = (Float(res.length) / Float(_g2));		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(172)
	int new_len = ::Std_obj::_int(_g3);		HX_STACK_VAR(new_len,"new_len");
	HX_STACK_LINE(173)
	this->Resize(new_len);
	HX_STACK_LINE(174)
	this->SetString(res,null());
	HX_STACK_LINE(175)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,EncodeBase64,return )

Void Buffer_obj::DecodeBase64( ){
{
		HX_STACK_FRAME("haxor.io.Buffer","DecodeBase64",0xa20705af,"haxor.io.Buffer.DecodeBase64","haxor/io/Buffer.hx",183,0x07055222)
		HX_STACK_THIS(this)
		HX_STACK_LINE(184)
		::String b64 = this->GetString(null(),null());		HX_STACK_VAR(b64,"b64");
		HX_STACK_LINE(185)
		::haxe::io::Bytes b = ::haxe::crypto::Base64_obj::decode(b64,null());		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(186)
		int _g = this->get_bytesPerElement();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(186)
		Float _g1 = (Float(b->length) / Float(_g));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(186)
		int new_len = ::Std_obj::_int(_g1);		HX_STACK_VAR(new_len,"new_len");
		HX_STACK_LINE(187)
		this->Resize(new_len);
		HX_STACK_LINE(188)
		{
			HX_STACK_LINE(188)
			int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(188)
			int _g2 = b->length;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(188)
			while((true)){
				HX_STACK_LINE(188)
				if ((!(((_g11 < _g2))))){
					HX_STACK_LINE(188)
					break;
				}
				HX_STACK_LINE(188)
				int i = (_g11)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(188)
				this->SetByte(i,b->b->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,DecodeBase64,(void))

::String Buffer_obj::GetString( hx::Null< int >  __o_p_offset,hx::Null< int >  __o_p_length){
int p_offset = __o_p_offset.Default(0);
int p_length = __o_p_length.Default(0);
	HX_STACK_FRAME("haxor.io.Buffer","GetString",0x99250a75,"haxor.io.Buffer.GetString","haxor/io/Buffer.hx",198,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_offset,"p_offset")
	HX_STACK_ARG(p_length,"p_length")
{
		HX_STACK_LINE(199)
		int len;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(199)
		if (((p_length <= (int)0))){
			HX_STACK_LINE(199)
			int _g = this->get_bytesPerElement();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(199)
			len = (this->m_length * _g);
		}
		else{
			HX_STACK_LINE(199)
			len = p_length;
		}
		HX_STACK_LINE(200)
		::StringBuf s = ::StringBuf_obj::__new();		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(201)
		{
			HX_STACK_LINE(201)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(201)
			while((true)){
				HX_STACK_LINE(201)
				if ((!(((_g < len))))){
					HX_STACK_LINE(201)
					break;
				}
				HX_STACK_LINE(201)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(201)
				int c = this->GetByte((i + p_offset));		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(201)
				::String _g1 = ::String::fromCharCode(c);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(201)
				s->b->push(_g1);
			}
		}
		HX_STACK_LINE(202)
		return s->b->join(HX_CSTRING(""));
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Buffer_obj,GetString,return )

Void Buffer_obj::SetString( ::String p_string,hx::Null< int >  __o_p_offset){
int p_offset = __o_p_offset.Default(0);
	HX_STACK_FRAME("haxor.io.Buffer","SetString",0x7c75f681,"haxor.io.Buffer.SetString","haxor/io/Buffer.hx",212,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_string,"p_string")
	HX_STACK_ARG(p_offset,"p_offset")
{
		HX_STACK_LINE(212)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(212)
		int _g = p_string.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(212)
		while((true)){
			HX_STACK_LINE(212)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(212)
				break;
			}
			HX_STACK_LINE(212)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(214)
			Dynamic _g2 = p_string.charCodeAt(i);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(214)
			this->SetByte((i + p_offset),_g2);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Buffer_obj,SetString,(void))

Void Buffer_obj::SetViewSlice( int p_start,int p_length){
{
		HX_STACK_FRAME("haxor.io.Buffer","SetViewSlice",0xe24a13fd,"haxor.io.Buffer.SetViewSlice","haxor/io/Buffer.hx",224,0x07055222)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_start,"p_start")
		HX_STACK_ARG(p_length,"p_length")
		HX_STACK_LINE(225)
		int _g = this->get_bytesPerElement();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(225)
		int i0 = (p_start * _g);		HX_STACK_VAR(i0,"i0");
		HX_STACK_LINE(226)
		int _g1 = this->get_bytesPerElement();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(226)
		int _g2 = (p_length * _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(226)
		int i1 = (i0 + _g2);		HX_STACK_VAR(i1,"i1");
		HX_STACK_LINE(238)
		this->m_offset = i0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Buffer_obj,SetViewSlice,(void))

Void Buffer_obj::ResetSlice( ){
{
		HX_STACK_FRAME("haxor.io.Buffer","ResetSlice",0x865303d5,"haxor.io.Buffer.ResetSlice","haxor/io/Buffer.hx",260,0x07055222)
		HX_STACK_THIS(this)
		HX_STACK_LINE(260)
		this->m_offset = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,ResetSlice,(void))

::haxor::io::Buffer Buffer_obj::FromString( ::String p_string){
	HX_STACK_FRAME("haxor.io.Buffer","FromString",0x736335ad,"haxor.io.Buffer.FromString","haxor/io/Buffer.hx",30,0x07055222)
	HX_STACK_ARG(p_string,"p_string")
	HX_STACK_LINE(31)
	::haxor::io::Buffer b = ::haxor::io::Buffer_obj::__new(p_string.length);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(32)
	b->SetString(p_string,null());
	HX_STACK_LINE(33)
	return b;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Buffer_obj,FromString,return )


Buffer_obj::Buffer_obj()
{
}

void Buffer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Buffer);
	HX_MARK_MEMBER_NAME(buffer,"buffer");
	HX_MARK_MEMBER_NAME(m_buffer,"m_buffer");
	HX_MARK_MEMBER_NAME(m_original,"m_original");
	HX_MARK_MEMBER_NAME(m_offset,"m_offset");
	HX_MARK_MEMBER_NAME(byteLength,"byteLength");
	HX_MARK_MEMBER_NAME(bytesPerElement,"bytesPerElement");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(m_length,"m_length");
	HX_MARK_END_CLASS();
}

void Buffer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(buffer,"buffer");
	HX_VISIT_MEMBER_NAME(m_buffer,"m_buffer");
	HX_VISIT_MEMBER_NAME(m_original,"m_original");
	HX_VISIT_MEMBER_NAME(m_offset,"m_offset");
	HX_VISIT_MEMBER_NAME(byteLength,"byteLength");
	HX_VISIT_MEMBER_NAME(bytesPerElement,"bytesPerElement");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(m_length,"m_length");
}

Dynamic Buffer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"buffer") ) { return inCallProp ? get_buffer() : buffer; }
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? get_length() : length; }
		if (HX_FIELD_EQ(inName,"Resize") ) { return Resize_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GetByte") ) { return GetByte_dyn(); }
		if (HX_FIELD_EQ(inName,"SetByte") ) { return SetByte_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_buffer") ) { return m_buffer; }
		if (HX_FIELD_EQ(inName,"m_offset") ) { return m_offset; }
		if (HX_FIELD_EQ(inName,"m_length") ) { return m_length; }
		if (HX_FIELD_EQ(inName,"SetBytes") ) { return SetBytes_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"SetBuffer") ) { return SetBuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"GetString") ) { return GetString_dyn(); }
		if (HX_FIELD_EQ(inName,"SetString") ) { return SetString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FromString") ) { return FromString_dyn(); }
		if (HX_FIELD_EQ(inName,"get_buffer") ) { return get_buffer_dyn(); }
		if (HX_FIELD_EQ(inName,"m_original") ) { return m_original; }
		if (HX_FIELD_EQ(inName,"byteLength") ) { return inCallProp ? get_byteLength() : byteLength; }
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		if (HX_FIELD_EQ(inName,"ResetSlice") ) { return ResetSlice_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"EncodeBase64") ) { return EncodeBase64_dyn(); }
		if (HX_FIELD_EQ(inName,"DecodeBase64") ) { return DecodeBase64_dyn(); }
		if (HX_FIELD_EQ(inName,"SetViewSlice") ) { return SetViewSlice_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_byteLength") ) { return get_byteLength_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"bytesPerElement") ) { return inCallProp ? get_bytesPerElement() : bytesPerElement; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_bytesPerElement") ) { return get_bytesPerElement_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Buffer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"buffer") ) { buffer=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_buffer") ) { m_buffer=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_offset") ) { m_offset=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_length") ) { m_length=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_original") ) { m_original=inValue.Cast< ::haxe::io::Bytes >(); return inValue; }
		if (HX_FIELD_EQ(inName,"byteLength") ) { byteLength=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"bytesPerElement") ) { bytesPerElement=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Buffer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("buffer"));
	outFields->push(HX_CSTRING("m_buffer"));
	outFields->push(HX_CSTRING("m_original"));
	outFields->push(HX_CSTRING("m_offset"));
	outFields->push(HX_CSTRING("byteLength"));
	outFields->push(HX_CSTRING("bytesPerElement"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("m_length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("FromString"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::io::Bytes*/ ,(int)offsetof(Buffer_obj,buffer),HX_CSTRING("buffer")},
	{hx::fsObject /*::haxe::io::Bytes*/ ,(int)offsetof(Buffer_obj,m_buffer),HX_CSTRING("m_buffer")},
	{hx::fsObject /*::haxe::io::Bytes*/ ,(int)offsetof(Buffer_obj,m_original),HX_CSTRING("m_original")},
	{hx::fsInt,(int)offsetof(Buffer_obj,m_offset),HX_CSTRING("m_offset")},
	{hx::fsInt,(int)offsetof(Buffer_obj,byteLength),HX_CSTRING("byteLength")},
	{hx::fsInt,(int)offsetof(Buffer_obj,bytesPerElement),HX_CSTRING("bytesPerElement")},
	{hx::fsInt,(int)offsetof(Buffer_obj,length),HX_CSTRING("length")},
	{hx::fsInt,(int)offsetof(Buffer_obj,m_length),HX_CSTRING("m_length")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("buffer"),
	HX_CSTRING("get_buffer"),
	HX_CSTRING("m_buffer"),
	HX_CSTRING("m_original"),
	HX_CSTRING("m_offset"),
	HX_CSTRING("byteLength"),
	HX_CSTRING("get_byteLength"),
	HX_CSTRING("bytesPerElement"),
	HX_CSTRING("get_bytesPerElement"),
	HX_CSTRING("length"),
	HX_CSTRING("get_length"),
	HX_CSTRING("m_length"),
	HX_CSTRING("Resize"),
	HX_CSTRING("GetByte"),
	HX_CSTRING("SetByte"),
	HX_CSTRING("SetBytes"),
	HX_CSTRING("SetBuffer"),
	HX_CSTRING("EncodeBase64"),
	HX_CSTRING("DecodeBase64"),
	HX_CSTRING("GetString"),
	HX_CSTRING("SetString"),
	HX_CSTRING("SetViewSlice"),
	HX_CSTRING("ResetSlice"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Buffer_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Buffer_obj::__mClass,"__mClass");
};

#endif

Class Buffer_obj::__mClass;

void Buffer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.Buffer"), hx::TCanCast< Buffer_obj> ,sStaticFields,sMemberFields,
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

void Buffer_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
