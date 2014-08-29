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
#ifndef INCLUDED_haxor_io_UInt16Array
#include <haxor/io/UInt16Array.h>
#endif
namespace haxor{
namespace io{

Void UInt16Array_obj::__construct(int p_length)
{
HX_STACK_FRAME("haxor.io.UInt16Array","new",0xd0603430,"haxor.io.UInt16Array.new","haxor/io/UInt16Array.hx",12,0xf538efe0)
HX_STACK_THIS(this)
HX_STACK_ARG(p_length,"p_length")
{
	HX_STACK_LINE(12)
	super::__construct(p_length);
}
;
	return null();
}

//UInt16Array_obj::~UInt16Array_obj() { }

Dynamic UInt16Array_obj::__CreateEmpty() { return  new UInt16Array_obj; }
hx::ObjectPtr< UInt16Array_obj > UInt16Array_obj::__new(int p_length)
{  hx::ObjectPtr< UInt16Array_obj > result = new UInt16Array_obj();
	result->__construct(p_length);
	return result;}

Dynamic UInt16Array_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UInt16Array_obj > result = new UInt16Array_obj();
	result->__construct(inArgs[0]);
	return result;}

int UInt16Array_obj::get_bytesPerElement( ){
	HX_STACK_FRAME("haxor.io.UInt16Array","get_bytesPerElement",0xfbf13a91,"haxor.io.UInt16Array.get_bytesPerElement","haxor/io/UInt16Array.hx",38,0xf538efe0)
	HX_STACK_THIS(this)
	HX_STACK_LINE(38)
	return (int)2;
}


Void UInt16Array_obj::Resize( int p_length){
{
		HX_STACK_FRAME("haxor.io.UInt16Array","Resize",0xf61fac44,"haxor.io.UInt16Array.Resize","haxor/io/UInt16Array.hx",46,0xf538efe0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_length,"p_length")
		HX_STACK_LINE(46)
		this->super::Resize(p_length);
	}
return null();
}


int UInt16Array_obj::Get( int p_index){
	HX_STACK_FRAME("haxor.io.UInt16Array","Get",0xd0429c46,"haxor.io.UInt16Array.Get","haxor/io/UInt16Array.hx",62,0xf538efe0)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_LINE(69)
	::haxe::io::Bytes aux = this->m_buffer;		HX_STACK_VAR(aux,"aux");
	HX_STACK_LINE(70)
	int p = (p_index * (int)2);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(71)
	
		int v = 0;
		char* ptr = (char*)(&v);
		ptr[0] = (char) aux->b[p];
		ptr[1] = (char) aux->b[p+1];		
		return v;
		;
	HX_STACK_LINE(78)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC1(UInt16Array_obj,Get,return )

Void UInt16Array_obj::Set( int p_index,int p_value){
{
		HX_STACK_FRAME("haxor.io.UInt16Array","Set",0xd04bb752,"haxor.io.UInt16Array.Set","haxor/io/UInt16Array.hx",92,0xf538efe0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_index,"p_index")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(99)
		::haxe::io::Bytes aux = this->m_buffer;		HX_STACK_VAR(aux,"aux");
		HX_STACK_LINE(100)
		int p = (p_index * (int)2);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(101)
		
		int v   = p_value;
		char* ptr = (char*)(&v);
		aux->b[p]   = ptr[0];
		aux->b[p+1] = ptr[1];		
		;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(UInt16Array_obj,Set,(void))

Void UInt16Array_obj::SetRange( Array< int > p_data,hx::Null< int >  __o_p_offset){
int p_offset = __o_p_offset.Default(0);
	HX_STACK_FRAME("haxor.io.UInt16Array","SetRange",0xcf6d950b,"haxor.io.UInt16Array.SetRange","haxor/io/UInt16Array.hx",121,0xf538efe0)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_offset,"p_offset")
{
		HX_STACK_LINE(121)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(121)
		int _g = p_data->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(121)
		while((true)){
			HX_STACK_LINE(121)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(121)
				break;
			}
			HX_STACK_LINE(121)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(121)
			this->Set((i + p_offset),p_data->__get(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(UInt16Array_obj,SetRange,(void))

Void UInt16Array_obj::SetViewSlice( int p_start,int p_length){
{
		HX_STACK_FRAME("haxor.io.UInt16Array","SetViewSlice",0x830ee1fb,"haxor.io.UInt16Array.SetViewSlice","haxor/io/UInt16Array.hx",131,0xf538efe0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_start,"p_start")
		HX_STACK_ARG(p_length,"p_length")
		HX_STACK_LINE(131)
		this->super::SetViewSlice(p_start,p_length);
	}
return null();
}


::haxor::io::UInt16Array UInt16Array_obj::Alloc( Array< int > p_data){
	HX_STACK_FRAME("haxor.io.UInt16Array","Alloc",0xeb8a0c25,"haxor.io.UInt16Array.Alloc","haxor/io/UInt16Array.hx",20,0xf538efe0)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_LINE(21)
	::haxor::io::UInt16Array b = ::haxor::io::UInt16Array_obj::__new(p_data->length);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(22)
	b->SetRange(p_data,null());
	HX_STACK_LINE(23)
	return b;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UInt16Array_obj,Alloc,return )

::haxor::io::UInt16Array UInt16Array_obj::Parse( ::String p_data,::String __o_p_delimiter){
::String p_delimiter = __o_p_delimiter.Default(HX_CSTRING(" "));
	HX_STACK_FRAME("haxor.io.UInt16Array","Parse",0x874bf7e3,"haxor.io.UInt16Array.Parse","haxor/io/UInt16Array.hx",146,0xf538efe0)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_delimiter,"p_delimiter")
{
		HX_STACK_LINE(147)
		Array< ::String > tk = p_data.split(p_delimiter);		HX_STACK_VAR(tk,"tk");
		HX_STACK_LINE(148)
		::haxor::io::UInt16Array res = ::haxor::io::UInt16Array_obj::__new(tk->length);		HX_STACK_VAR(res,"res");
		HX_STACK_LINE(149)
		{
			HX_STACK_LINE(149)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(149)
			int _g = tk->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(149)
			while((true)){
				HX_STACK_LINE(149)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(149)
					break;
				}
				HX_STACK_LINE(149)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(149)
				::String _g2 = ::StringTools_obj::trim(tk->__get(i));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(149)
				Dynamic _g11 = ::Std_obj::parseInt(_g2);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(149)
				res->Set(i,_g11);
			}
		}
		HX_STACK_LINE(150)
		return res;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(UInt16Array_obj,Parse,return )


UInt16Array_obj::UInt16Array_obj()
{
}

Dynamic UInt16Array_obj::__Field(const ::String &inName,bool inCallProp)
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
	case 12:
		if (HX_FIELD_EQ(inName,"SetViewSlice") ) { return SetViewSlice_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_bytesPerElement") ) { return get_bytesPerElement_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic UInt16Array_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void UInt16Array_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Alloc"),
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
	HX_MARK_MEMBER_NAME(UInt16Array_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(UInt16Array_obj::__mClass,"__mClass");
};

#endif

Class UInt16Array_obj::__mClass;

void UInt16Array_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.UInt16Array"), hx::TCanCast< UInt16Array_obj> ,sStaticFields,sMemberFields,
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

void UInt16Array_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
