#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_BaseArray
#include <haxor/io/BaseArray.h>
#endif
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
namespace haxor{
namespace io{

Void FloatArray_obj::__construct(int p_capacity)
{
HX_STACK_FRAME("haxor.io.FloatArray","new",0x4aef304b,"haxor.io.FloatArray.new","haxor/io/FloatArray.hx",55,0xf103c6e5)
HX_STACK_THIS(this)
HX_STACK_ARG(p_capacity,"p_capacity")
{
	HX_STACK_LINE(68)
	this->m_length = p_capacity;
	HX_STACK_LINE(69)
	Array< Float > arr = Array_obj< Float >::__new();		HX_STACK_VAR(arr,"arr");
	HX_STACK_LINE(70)
	{
		HX_STACK_LINE(70)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(70)
		int _g = this->m_length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(70)
		while((true)){
			HX_STACK_LINE(70)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(70)
				break;
			}
			HX_STACK_LINE(70)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(70)
			arr->push(0.0);
		}
	}
	HX_STACK_LINE(71)
	::cpp::Pointer< Float > _g = ::cpp::Pointer_obj::fromArray(arr,(int)0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(71)
	this->b = _g;
}
;
	return null();
}

//FloatArray_obj::~FloatArray_obj() { }

Dynamic FloatArray_obj::__CreateEmpty() { return  new FloatArray_obj; }
hx::ObjectPtr< FloatArray_obj > FloatArray_obj::__new(int p_capacity)
{  hx::ObjectPtr< FloatArray_obj > result = new FloatArray_obj();
	result->__construct(p_capacity);
	return result;}

Dynamic FloatArray_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FloatArray_obj > result = new FloatArray_obj();
	result->__construct(inArgs[0]);
	return result;}

int FloatArray_obj::get_length( ){
	HX_STACK_FRAME("haxor.io.FloatArray","get_length",0xd7fc4824,"haxor.io.FloatArray.get_length","haxor/io/FloatArray.hx",36,0xf103c6e5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(36)
	return this->m_length;
}


::String FloatArray_obj::get_type( ){
	HX_STACK_FRAME("haxor.io.FloatArray","get_type",0x0d6dba78,"haxor.io.FloatArray.get_type","haxor/io/FloatArray.hx",43,0xf103c6e5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(43)
	return HX_CSTRING("float");
}


::haxor::io::FloatArray FloatArray_obj::Clone( ){
	HX_STACK_FRAME("haxor.io.FloatArray","Clone",0x8bb3f3e8,"haxor.io.FloatArray.Clone","haxor/io/FloatArray.hx",80,0xf103c6e5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(81)
	::haxor::io::FloatArray a = ::haxor::io::FloatArray_obj::__new(this->m_length);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(82)
	{
		HX_STACK_LINE(82)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(82)
		int _g = this->m_length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(82)
		while((true)){
			HX_STACK_LINE(82)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(82)
				break;
			}
			HX_STACK_LINE(82)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(84)
			Float n = this->b->__get(i);		HX_STACK_VAR(n,"n");
			HX_STACK_LINE(85)
			hx::__ArrayImplRef(a->b,i) = n;
		}
	}
	HX_STACK_LINE(87)
	return a;
}


HX_DEFINE_DYNAMIC_FUNC0(FloatArray_obj,Clone,return )

Void FloatArray_obj::Fill( Array< Float > p_data){
{
		HX_STACK_FRAME("haxor.io.FloatArray","Fill",0x2bed8858,"haxor.io.FloatArray.Fill","haxor/io/FloatArray.hx",96,0xf103c6e5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_LINE(96)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(96)
		int _g = p_data->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(96)
		while((true)){
			HX_STACK_LINE(96)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(96)
				break;
			}
			HX_STACK_LINE(96)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(98)
			hx::__ArrayImplRef(this->b,i) = p_data->__get(i);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FloatArray_obj,Fill,(void))

Float FloatArray_obj::Get( int k){
	HX_STACK_FRAME("haxor.io.FloatArray","Get",0x4ad19861,"haxor.io.FloatArray.Get","haxor/io/FloatArray.hx",116,0xf103c6e5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(k,"k")
	HX_STACK_LINE(116)
	return this->b->__get(k);
}


HX_DEFINE_DYNAMIC_FUNC1(FloatArray_obj,Get,return )

Void FloatArray_obj::Set( int k,Float v){
{
		HX_STACK_FRAME("haxor.io.FloatArray","Set",0x4adab36d,"haxor.io.FloatArray.Set","haxor/io/FloatArray.hx",135,0xf103c6e5)
		HX_STACK_THIS(this)
		HX_STACK_ARG(k,"k")
		HX_STACK_ARG(v,"v")
		HX_STACK_LINE(135)
		hx::__ArrayImplRef(this->b,k) = v;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(FloatArray_obj,Set,(void))

::haxor::io::FloatArray FloatArray_obj::Create( Array< Float > p_data){
	HX_STACK_FRAME("haxor.io.FloatArray","Create",0x1f830011,"haxor.io.FloatArray.Create","haxor/io/FloatArray.hx",22,0xf103c6e5)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_LINE(23)
	::haxor::io::FloatArray a = ::haxor::io::FloatArray_obj::__new(p_data->length);		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(24)
	a->Fill(p_data);
	HX_STACK_LINE(25)
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FloatArray_obj,Create,return )


FloatArray_obj::FloatArray_obj()
{
}

void FloatArray_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FloatArray);
	HX_MARK_MEMBER_NAME(m_length,"m_length");
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_END_CLASS();
}

void FloatArray_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_length,"m_length");
	HX_VISIT_MEMBER_NAME(b,"b");
}

Dynamic FloatArray_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Fill") ) { return Fill_dyn(); }
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
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FloatArray_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< ::cpp::Pointer< Float > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_length") ) { m_length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FloatArray_obj::__GetFields(Array< ::String> &outFields)
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
	{hx::fsInt,(int)offsetof(FloatArray_obj,m_length),HX_CSTRING("m_length")},
	{hx::fsObject /*::cpp::Pointer< Float >*/ ,(int)offsetof(FloatArray_obj,b),HX_CSTRING("b")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_length"),
	HX_CSTRING("m_length"),
	HX_CSTRING("get_type"),
	HX_CSTRING("b"),
	HX_CSTRING("Clone"),
	HX_CSTRING("Fill"),
	HX_CSTRING("Get"),
	HX_CSTRING("Set"),
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
