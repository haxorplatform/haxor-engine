#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
namespace haxor{
namespace io{

Void FloatArray_obj::__construct(int p_length)
{
HX_STACK_FRAME("haxor.io.FloatArray","new",0x4aef304b,"haxor.io.FloatArray.new","haxor/io/FloatArray.hx",15,0xf103c6e5)
HX_STACK_THIS(this)
HX_STACK_ARG(p_length,"p_length")
{
	HX_STACK_LINE(15)
	super::__construct(p_length);
}
;
	return null();
}

//FloatArray_obj::~FloatArray_obj() { }

Dynamic FloatArray_obj::__CreateEmpty() { return  new FloatArray_obj; }
hx::ObjectPtr< FloatArray_obj > FloatArray_obj::__new(int p_length)
{  hx::ObjectPtr< FloatArray_obj > result = new FloatArray_obj();
	result->__construct(p_length);
	return result;}

Dynamic FloatArray_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FloatArray_obj > result = new FloatArray_obj();
	result->__construct(inArgs[0]);
	return result;}

int FloatArray_obj::get_bytesPerElement( ){
	HX_STACK_FRAME("haxor.io.FloatArray","get_bytesPerElement",0xc4ef5cac,"haxor.io.FloatArray.get_bytesPerElement","haxor/io/FloatArray.hx",47,0xf103c6e5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(47)
	return (int)4;
}


Void FloatArray_obj::Resize( int p_length){
{
		HX_STACK_FRAME("haxor.io.FloatArray","Resize",0xabeef309,"haxor.io.FloatArray.Resize","haxor/io/FloatArray.hx",63,0xf103c6e5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_length,"p_length")
		HX_STACK_LINE(63)
		this->super::Resize(p_length);
	}
return null();
}


Float FloatArray_obj::Get( int p_index){
	HX_STACK_FRAME("haxor.io.FloatArray","Get",0x4ad19861,"haxor.io.FloatArray.Get","haxor/io/FloatArray.hx",79,0xf103c6e5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_LINE(86)
	::haxe::io::Bytes aux = this->m_buffer;		HX_STACK_VAR(aux,"aux");
	HX_STACK_LINE(87)
	int p = (p_index * (int)4);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(88)
	
		float v = 0.0;
		char* ptr = (char*)(&v);
		ptr[0] = (char) aux->b[p];
		ptr[1] = (char) aux->b[p+1];
		ptr[2] = (char) aux->b[p+2];
		ptr[3] = (char) aux->b[p+3];
		return v;
		;
	HX_STACK_LINE(97)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC1(FloatArray_obj,Get,return )

Void FloatArray_obj::Set( int p_index,Float p_value){
{
		HX_STACK_FRAME("haxor.io.FloatArray","Set",0x4adab36d,"haxor.io.FloatArray.Set","haxor/io/FloatArray.hx",111,0xf103c6e5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_index,"p_index")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(118)
		::haxe::io::Bytes aux = this->m_buffer;		HX_STACK_VAR(aux,"aux");
		HX_STACK_LINE(119)
		int p = (p_index * (int)4);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(120)
		
		float v   = p_value;
		char * ptr = (char * )( & v);		
		aux->b[p]   = ptr[0];
		aux->b[p+1] = ptr[1];
		aux->b[p+2] = ptr[2];
		aux->b[p+3] = ptr[3];
		;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FloatArray_obj,Set,(void))

Void FloatArray_obj::SetRange( Array< Float > p_data,hx::Null< int >  __o_p_offset){
int p_offset = __o_p_offset.Default(0);
	HX_STACK_FRAME("haxor.io.FloatArray","SetRange",0x0cafd710,"haxor.io.FloatArray.SetRange","haxor/io/FloatArray.hx",142,0xf103c6e5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_offset,"p_offset")
{
		HX_STACK_LINE(142)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(142)
		int _g = p_data->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(142)
		while((true)){
			HX_STACK_LINE(142)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(142)
				break;
			}
			HX_STACK_LINE(142)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(142)
			this->Set((i + p_offset),p_data->__get(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FloatArray_obj,SetRange,(void))

Void FloatArray_obj::SetViewSlice( int p_start,int p_length){
{
		HX_STACK_FRAME("haxor.io.FloatArray","SetViewSlice",0xdc9b0a80,"haxor.io.FloatArray.SetViewSlice","haxor/io/FloatArray.hx",152,0xf103c6e5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_start,"p_start")
		HX_STACK_ARG(p_length,"p_length")
		HX_STACK_LINE(152)
		this->super::SetViewSlice(p_start,p_length);
	}
return null();
}


::haxor::io::FloatArray FloatArray_obj::Alloc( Array< Float > p_data){
	HX_STACK_FRAME("haxor.io.FloatArray","Alloc",0x64e48500,"haxor.io.FloatArray.Alloc","haxor/io/FloatArray.hx",24,0xf103c6e5)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_LINE(25)
	::haxor::io::FloatArray b = ::haxor::io::FloatArray_obj::__new(p_data->length);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(26)
	b->SetRange(p_data,null());
	HX_STACK_LINE(27)
	return b;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FloatArray_obj,Alloc,return )

::haxor::io::FloatArray FloatArray_obj::FromBase64( ::String p_data){
	HX_STACK_FRAME("haxor.io.FloatArray","FromBase64",0xd78a4a2e,"haxor.io.FloatArray.FromBase64","haxor/io/FloatArray.hx",36,0xf103c6e5)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_LINE(37)
	int _g = ::Std_obj::_int((Float(p_data.length) / Float((int)4)));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(37)
	::haxor::io::FloatArray b = ::haxor::io::FloatArray_obj::__new(_g);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(38)
	b->SetString(p_data,null());
	HX_STACK_LINE(39)
	b->DecodeBase64();
	HX_STACK_LINE(40)
	return b;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FloatArray_obj,FromBase64,return )

::haxor::io::FloatArray FloatArray_obj::Parse( ::String p_data,::String __o_p_delimiter){
::String p_delimiter = __o_p_delimiter.Default(HX_CSTRING(" "));
	HX_STACK_FRAME("haxor.io.FloatArray","Parse",0x00a670be,"haxor.io.FloatArray.Parse","haxor/io/FloatArray.hx",167,0xf103c6e5)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_delimiter,"p_delimiter")
{
		HX_STACK_LINE(168)
		Array< ::String > tk = p_data.split(p_delimiter);		HX_STACK_VAR(tk,"tk");
		HX_STACK_LINE(169)
		::haxor::io::FloatArray res = ::haxor::io::FloatArray_obj::__new(tk->length);		HX_STACK_VAR(res,"res");
		HX_STACK_LINE(170)
		{
			HX_STACK_LINE(170)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(170)
			int _g = tk->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(170)
			while((true)){
				HX_STACK_LINE(170)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(170)
					break;
				}
				HX_STACK_LINE(170)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(170)
				::String _g2 = ::StringTools_obj::trim(tk->__get(i));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(170)
				Float _g11 = ::Std_obj::parseFloat(_g2);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(170)
				res->Set(i,_g11);
			}
		}
		HX_STACK_LINE(171)
		return res;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FloatArray_obj,Parse,return )


FloatArray_obj::FloatArray_obj()
{
}

Dynamic FloatArray_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Alloc") ) { return Alloc_dyn(); }
		if (HX_FIELD_EQ(inName,"Parse") ) { return Parse_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Resize") ) { return Resize_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"SetRange") ) { return SetRange_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FromBase64") ) { return FromBase64_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"SetViewSlice") ) { return SetViewSlice_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_bytesPerElement") ) { return get_bytesPerElement_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FloatArray_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FloatArray_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Alloc"),
	HX_CSTRING("FromBase64"),
	HX_CSTRING("Parse"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_bytesPerElement"),
	HX_CSTRING("Resize"),
	HX_CSTRING("Get"),
	HX_CSTRING("Set"),
	HX_CSTRING("SetRange"),
	HX_CSTRING("SetViewSlice"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FloatArray_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FloatArray_obj::__mClass,"__mClass");
};

#endif

Class FloatArray_obj::__mClass;

void FloatArray_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.FloatArray"), hx::TCanCast< FloatArray_obj> ,sStaticFields,sMemberFields,
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

void FloatArray_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
