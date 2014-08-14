#include <hxcpp.h>

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
HX_STACK_FRAME("haxor.io.FloatArray","new",0x4aef304b,"haxor.io.FloatArray.new","haxor/io/FloatArray.hx",46,0xf103c6e5)
HX_STACK_THIS(this)
HX_STACK_ARG(p_length,"p_length")
{
	HX_STACK_LINE(46)
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
	HX_STACK_FRAME("haxor.io.FloatArray","get_bytesPerElement",0xc4ef5cac,"haxor.io.FloatArray.get_bytesPerElement","haxor/io/FloatArray.hx",30,0xf103c6e5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(30)
	return (int)4;
}


Float FloatArray_obj::Get( int p_index){
	HX_STACK_FRAME("haxor.io.FloatArray","Get",0x4ad19861,"haxor.io.FloatArray.Get","haxor/io/FloatArray.hx",63,0xf103c6e5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_LINE(69)
	::haxe::io::Bytes aux = this->m_buffer;		HX_STACK_VAR(aux,"aux");
	HX_STACK_LINE(70)
	int p = (p_index * (int)4);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(71)
	
		float v = 0.0;
		char* ptr = (char*)(&v);
		ptr[0] = (char) aux->b[p];
		ptr[1] = (char) aux->b[p+1];
		ptr[2] = (char) aux->b[p+2];
		ptr[3] = (char) aux->b[p+3];
		return v;
		;
	HX_STACK_LINE(80)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC1(FloatArray_obj,Get,return )

Void FloatArray_obj::Set( int p_index,Float p_value){
{
		HX_STACK_FRAME("haxor.io.FloatArray","Set",0x4adab36d,"haxor.io.FloatArray.Set","haxor/io/FloatArray.hx",94,0xf103c6e5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_index,"p_index")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(100)
		::haxe::io::Bytes aux = this->m_buffer;		HX_STACK_VAR(aux,"aux");
		HX_STACK_LINE(101)
		int p = (p_index * (int)4);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(102)
		
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
	HX_STACK_FRAME("haxor.io.FloatArray","SetRange",0x0cafd710,"haxor.io.FloatArray.SetRange","haxor/io/FloatArray.hx",124,0xf103c6e5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_offset,"p_offset")
{
		HX_STACK_LINE(124)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(124)
		int _g = p_data->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(124)
		while((true)){
			HX_STACK_LINE(124)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(124)
				break;
			}
			HX_STACK_LINE(124)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(124)
			this->Set((i + p_offset),p_data->__get(i));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FloatArray_obj,SetRange,(void))

::haxor::io::FloatArray FloatArray_obj::Alloc( Array< Float > p_data){
	HX_STACK_FRAME("haxor.io.FloatArray","Alloc",0x64e48500,"haxor.io.FloatArray.Alloc","haxor/io/FloatArray.hx",20,0xf103c6e5)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_LINE(21)
	::haxor::io::FloatArray b = ::haxor::io::FloatArray_obj::__new(p_data->length);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(22)
	b->SetRange(p_data,null());
	HX_STACK_LINE(23)
	return b;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FloatArray_obj,Alloc,return )


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
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"SetRange") ) { return SetRange_dyn(); }
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
