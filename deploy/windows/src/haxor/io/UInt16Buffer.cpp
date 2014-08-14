#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_UInt16Buffer
#include <haxor/io/UInt16Buffer.h>
#endif
namespace haxor{
namespace io{

Void UInt16Buffer_obj::__construct(int p_length)
{
HX_STACK_FRAME("haxor.io.UInt16Buffer","new",0xdc4f792d,"haxor.io.UInt16Buffer.new","haxor/io/UInt16Buffer.hx",45,0xd0abc843)
HX_STACK_THIS(this)
HX_STACK_ARG(p_length,"p_length")
{
	HX_STACK_LINE(45)
	super::__construct(p_length);
}
;
	return null();
}

//UInt16Buffer_obj::~UInt16Buffer_obj() { }

Dynamic UInt16Buffer_obj::__CreateEmpty() { return  new UInt16Buffer_obj; }
hx::ObjectPtr< UInt16Buffer_obj > UInt16Buffer_obj::__new(int p_length)
{  hx::ObjectPtr< UInt16Buffer_obj > result = new UInt16Buffer_obj();
	result->__construct(p_length);
	return result;}

Dynamic UInt16Buffer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UInt16Buffer_obj > result = new UInt16Buffer_obj();
	result->__construct(inArgs[0]);
	return result;}

int UInt16Buffer_obj::get_bytesPerElement( ){
	HX_STACK_FRAME("haxor.io.UInt16Buffer","get_bytesPerElement",0x449f098e,"haxor.io.UInt16Buffer.get_bytesPerElement","haxor/io/UInt16Buffer.hx",37,0xd0abc843)
	HX_STACK_THIS(this)
	HX_STACK_LINE(37)
	return (int)2;
}


int UInt16Buffer_obj::Get( int p_index){
	HX_STACK_FRAME("haxor.io.UInt16Buffer","Get",0xdc31e143,"haxor.io.UInt16Buffer.Get","haxor/io/UInt16Buffer.hx",57,0xd0abc843)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_LINE(63)
	::haxe::io::Bytes aux = this->m_buffer;		HX_STACK_VAR(aux,"aux");
	HX_STACK_LINE(64)
	int p = (p_index * (int)2);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(65)
	
		int v = 0;
		char* ptr = (char*)(&v);
		ptr[0] = (char) aux->b[p];
		ptr[1] = (char) aux->b[p+1];		
		return v;
		;
	HX_STACK_LINE(72)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC1(UInt16Buffer_obj,Get,return )

Void UInt16Buffer_obj::Set( int p_index,int p_value){
{
		HX_STACK_FRAME("haxor.io.UInt16Buffer","Set",0xdc3afc4f,"haxor.io.UInt16Buffer.Set","haxor/io/UInt16Buffer.hx",86,0xd0abc843)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_index,"p_index")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(92)
		::haxe::io::Bytes aux = this->m_buffer;		HX_STACK_VAR(aux,"aux");
		HX_STACK_LINE(93)
		int p = (p_index * (int)2);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(94)
		
		int v   = p_value;
		char* ptr = (char*)(&v);
		aux->b[p]   = ptr[0];
		aux->b[p+1] = ptr[1];		
		;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(UInt16Buffer_obj,Set,(void))

Void UInt16Buffer_obj::SetRange( Array< int > p_data,hx::Null< int >  __o_p_offset){
int p_offset = __o_p_offset.Default(0);
	HX_STACK_FRAME("haxor.io.UInt16Buffer","SetRange",0x8df21aee,"haxor.io.UInt16Buffer.SetRange","haxor/io/UInt16Buffer.hx",114,0xd0abc843)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_offset,"p_offset")
{
		HX_STACK_LINE(114)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(114)
		int _g = p_data->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(114)
		while((true)){
			HX_STACK_LINE(114)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(114)
				break;
			}
			HX_STACK_LINE(114)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(114)
			this->Set((i + p_offset),p_data->__get(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(UInt16Buffer_obj,SetRange,(void))

::haxor::io::UInt16Buffer UInt16Buffer_obj::Alloc( Array< int > p_data){
	HX_STACK_FRAME("haxor.io.UInt16Buffer","Alloc",0x45924a62,"haxor.io.UInt16Buffer.Alloc","haxor/io/UInt16Buffer.hx",19,0xd0abc843)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_LINE(20)
	::haxor::io::UInt16Buffer b = ::haxor::io::UInt16Buffer_obj::__new(p_data->length);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(21)
	b->SetRange(p_data,null());
	HX_STACK_LINE(22)
	return b;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UInt16Buffer_obj,Alloc,return )


UInt16Buffer_obj::UInt16Buffer_obj()
{
}

Dynamic UInt16Buffer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Alloc") ) { return Alloc_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"SetRange") ) { return SetRange_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"get_bytesPerElement") ) { return get_bytesPerElement_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic UInt16Buffer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void UInt16Buffer_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Alloc"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_bytesPerElement"),
	HX_CSTRING("Get"),
	HX_CSTRING("Set"),
	HX_CSTRING("SetRange"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(UInt16Buffer_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(UInt16Buffer_obj::__mClass,"__mClass");
};

#endif

Class UInt16Buffer_obj::__mClass;

void UInt16Buffer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.UInt16Buffer"), hx::TCanCast< UInt16Buffer_obj> ,sStaticFields,sMemberFields,
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

void UInt16Buffer_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
