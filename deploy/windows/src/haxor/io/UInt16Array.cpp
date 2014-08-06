#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_BaseArray
#include <haxor/io/BaseArray.h>
#endif
#ifndef INCLUDED_haxor_io_UInt16Array
#include <haxor/io/UInt16Array.h>
#endif
namespace haxor{
namespace io{

Void UInt16Array_obj::__construct(int p_capacity)
{
HX_STACK_FRAME("haxor.io.UInt16Array","new",0xd0603430,"haxor.io.UInt16Array.new","haxor/io/UInt16Array.hx",51,0xf538efe0)
HX_STACK_THIS(this)
HX_STACK_ARG(p_capacity,"p_capacity")
{
	HX_STACK_LINE(64)
	this->m_length = p_capacity;
	HX_STACK_LINE(65)
	Array< int > arr = Array_obj< int >::__new();		HX_STACK_VAR(arr,"arr");
	HX_STACK_LINE(66)
	{
		HX_STACK_LINE(66)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(66)
		int _g = this->m_length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(66)
		while((true)){
			HX_STACK_LINE(66)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(66)
				break;
			}
			HX_STACK_LINE(66)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(66)
			arr->push((int)0);
		}
	}
	HX_STACK_LINE(67)
	::cpp::Pointer< int > _g = ::cpp::Pointer_obj::fromArray(arr,(int)0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(67)
	this->b = _g;
}
;
	return null();
}

//UInt16Array_obj::~UInt16Array_obj() { }

Dynamic UInt16Array_obj::__CreateEmpty() { return  new UInt16Array_obj; }
hx::ObjectPtr< UInt16Array_obj > UInt16Array_obj::__new(int p_capacity)
{  hx::ObjectPtr< UInt16Array_obj > result = new UInt16Array_obj();
	result->__construct(p_capacity);
	return result;}

Dynamic UInt16Array_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UInt16Array_obj > result = new UInt16Array_obj();
	result->__construct(inArgs[0]);
	return result;}

int UInt16Array_obj::get_length( ){
	HX_STACK_FRAME("haxor.io.UInt16Array","get_length",0x1421badf,"haxor.io.UInt16Array.get_length","haxor/io/UInt16Array.hx",34,0xf538efe0)
	HX_STACK_THIS(this)
	HX_STACK_LINE(34)
	return this->m_length;
}


::String UInt16Array_obj::get_type( ){
	HX_STACK_FRAME("haxor.io.UInt16Array","get_type",0xd02b7873,"haxor.io.UInt16Array.get_type","haxor/io/UInt16Array.hx",38,0xf538efe0)
	HX_STACK_THIS(this)
	HX_STACK_LINE(38)
	return HX_CSTRING("int");
}


::haxor::io::UInt16Array UInt16Array_obj::Clone( ){
	HX_STACK_FRAME("haxor.io.UInt16Array","Clone",0x12597b0d,"haxor.io.UInt16Array.Clone","haxor/io/UInt16Array.hx",76,0xf538efe0)
	HX_STACK_THIS(this)
	HX_STACK_LINE(77)
	::haxor::io::UInt16Array a = ::haxor::io::UInt16Array_obj::__new(this->m_length);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(78)
	{
		HX_STACK_LINE(78)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(78)
		int _g = this->m_length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(78)
		while((true)){
			HX_STACK_LINE(78)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(78)
				break;
			}
			HX_STACK_LINE(78)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(78)
			int v = this->b->__get(i);		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(78)
			hx::__ArrayImplRef(a->b,i) = v;
			HX_STACK_LINE(78)
			v;
		}
	}
	HX_STACK_LINE(79)
	return a;
}


HX_DEFINE_DYNAMIC_FUNC0(UInt16Array_obj,Clone,return )

Void UInt16Array_obj::Set( Array< int > p_data){
{
		HX_STACK_FRAME("haxor.io.UInt16Array","Set",0xd04bb752,"haxor.io.UInt16Array.Set","haxor/io/UInt16Array.hx",89,0xf538efe0)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_LINE(89)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(89)
		int _g = p_data->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(89)
		while((true)){
			HX_STACK_LINE(89)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(89)
				break;
			}
			HX_STACK_LINE(89)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(89)
			int v = p_data->__get(i);		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(89)
			hx::__ArrayImplRef(this->b,i) = v;
			HX_STACK_LINE(89)
			v;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(UInt16Array_obj,Set,(void))

int UInt16Array_obj::array_get( int k){
	HX_STACK_FRAME("haxor.io.UInt16Array","array_get",0x951b9380,"haxor.io.UInt16Array.array_get","haxor/io/UInt16Array.hx",102,0xf538efe0)
	HX_STACK_THIS(this)
	HX_STACK_ARG(k,"k")
	HX_STACK_LINE(102)
	return this->b->__get(k);
}


HX_DEFINE_DYNAMIC_FUNC1(UInt16Array_obj,array_get,return )

int UInt16Array_obj::array_set( int k,int v){
	HX_STACK_FRAME("haxor.io.UInt16Array","array_set",0x9524ae8c,"haxor.io.UInt16Array.array_set","haxor/io/UInt16Array.hx",108,0xf538efe0)
	HX_STACK_THIS(this)
	HX_STACK_ARG(k,"k")
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(116)
	hx::__ArrayImplRef(this->b,k) = v;
	HX_STACK_LINE(118)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC2(UInt16Array_obj,array_set,return )

::haxor::io::UInt16Array UInt16Array_obj::Create( Array< int > p_data){
	HX_STACK_FRAME("haxor.io.UInt16Array","Create",0x69b3b94c,"haxor.io.UInt16Array.Create","haxor/io/UInt16Array.hx",20,0xf538efe0)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_LINE(21)
	::haxor::io::UInt16Array a = ::haxor::io::UInt16Array_obj::__new(p_data->length);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(22)
	a->Set(p_data);
	HX_STACK_LINE(23)
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(UInt16Array_obj,Create,return )


UInt16Array_obj::UInt16Array_obj()
{
}

void UInt16Array_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(UInt16Array);
	HX_MARK_MEMBER_NAME(m_length,"m_length");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_END_CLASS();
}

void UInt16Array_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_length,"m_length");
	HX_VISIT_MEMBER_NAME(b,"b");
}

Dynamic UInt16Array_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Clone") ) { return Clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Create") ) { return Create_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_length") ) { return m_length; }
		if (HX_FIELD_EQ(inName,"get_type") ) { return get_type_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"array_get") ) { return array_get_dyn(); }
		if (HX_FIELD_EQ(inName,"array_set") ) { return array_set_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic UInt16Array_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< ::cpp::Pointer< int > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_length") ) { m_length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void UInt16Array_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_length"));
	outFields->push(HX_CSTRING("b"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Create"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(UInt16Array_obj,m_length),HX_CSTRING("m_length")},
	{hx::fsObject /*::cpp::Pointer< int >*/ ,(int)offsetof(UInt16Array_obj,b),HX_CSTRING("b")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_length"),
	HX_CSTRING("m_length"),
	HX_CSTRING("get_type"),
	HX_CSTRING("b"),
	HX_CSTRING("Clone"),
	HX_CSTRING("Set"),
	HX_CSTRING("array_get"),
	HX_CSTRING("array_set"),
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
