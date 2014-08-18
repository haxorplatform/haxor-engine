#include <hxcpp.h>

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
HX_STACK_FRAME("haxor.io.Buffer","new",0xda1b4a6e,"haxor.io.Buffer.new","haxor/io/Buffer.hx",57,0x07055222)
HX_STACK_THIS(this)
HX_STACK_ARG(p_length,"p_length")
{
	HX_STACK_LINE(58)
	this->m_length = p_length;
	HX_STACK_LINE(59)
	int _g = this->get_bytesPerElement();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(59)
	int len = (this->m_length * _g);		HX_STACK_VAR(len,"len");
	HX_STACK_LINE(66)
	::haxe::io::Bytes _g1 = ::haxe::io::Bytes_obj::alloc(len);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(66)
	this->m_buffer = _g1;
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
	HX_STACK_FRAME("haxor.io.Buffer","get_buffer",0xe95a307b,"haxor.io.Buffer.get_buffer","haxor/io/Buffer.hx",27,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_LINE(27)
	return this->m_buffer;
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,get_buffer,return )

int Buffer_obj::get_byteLength( ){
	HX_STACK_FRAME("haxor.io.Buffer","get_byteLength",0xbd506b09,"haxor.io.Buffer.get_byteLength","haxor/io/Buffer.hx",34,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_LINE(34)
	int _g = this->get_bytesPerElement();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(34)
	return (this->m_length * _g);
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,get_byteLength,return )

int Buffer_obj::get_bytesPerElement( ){
	HX_STACK_FRAME("haxor.io.Buffer","get_bytesPerElement",0x16c52ccf,"haxor.io.Buffer.get_bytesPerElement","haxor/io/Buffer.hx",40,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_LINE(40)
	return (int)1;
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,get_bytesPerElement,return )

int Buffer_obj::get_length( ){
	HX_STACK_FRAME("haxor.io.Buffer","get_length",0xb7cd0861,"haxor.io.Buffer.get_length","haxor/io/Buffer.hx",47,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_LINE(47)
	return this->m_length;
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,get_length,return )

int Buffer_obj::GetByte( int p_index){
	HX_STACK_FRAME("haxor.io.Buffer","GetByte",0x9c9f8fac,"haxor.io.Buffer.GetByte","haxor/io/Buffer.hx",81,0x07055222)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_LINE(87)
	return this->m_buffer->b->__get(p_index);
	HX_STACK_LINE(94)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC1(Buffer_obj,GetByte,return )

Void Buffer_obj::SetByte( int p_index,int p_value){
{
		HX_STACK_FRAME("haxor.io.Buffer","SetByte",0x8fa120b8,"haxor.io.Buffer.SetByte","haxor/io/Buffer.hx",109,0x07055222)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_index,"p_index")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(109)
		this->m_buffer->b[p_index] = p_value;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Buffer_obj,SetByte,(void))


Buffer_obj::Buffer_obj()
{
}

void Buffer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Buffer);
	HX_MARK_MEMBER_NAME(buffer,"buffer");
	HX_MARK_MEMBER_NAME(m_buffer,"m_buffer");
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
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"GetByte") ) { return GetByte_dyn(); }
		if (HX_FIELD_EQ(inName,"SetByte") ) { return SetByte_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_buffer") ) { return m_buffer; }
		if (HX_FIELD_EQ(inName,"m_length") ) { return m_length; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_buffer") ) { return get_buffer_dyn(); }
		if (HX_FIELD_EQ(inName,"byteLength") ) { return inCallProp ? get_byteLength() : byteLength; }
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
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
		if (HX_FIELD_EQ(inName,"m_length") ) { m_length=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
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
	outFields->push(HX_CSTRING("byteLength"));
	outFields->push(HX_CSTRING("bytesPerElement"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("m_length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxe::io::Bytes*/ ,(int)offsetof(Buffer_obj,buffer),HX_CSTRING("buffer")},
	{hx::fsObject /*::haxe::io::Bytes*/ ,(int)offsetof(Buffer_obj,m_buffer),HX_CSTRING("m_buffer")},
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
	HX_CSTRING("byteLength"),
	HX_CSTRING("get_byteLength"),
	HX_CSTRING("bytesPerElement"),
	HX_CSTRING("get_bytesPerElement"),
	HX_CSTRING("length"),
	HX_CSTRING("get_length"),
	HX_CSTRING("m_length"),
	HX_CSTRING("GetByte"),
	HX_CSTRING("SetByte"),
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
