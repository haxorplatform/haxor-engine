#include <hxcpp.h>

#ifndef INCLUDED_haxor_io_file_ColladaInput
#include <haxor/io/file/ColladaInput.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
#ifndef INCLUDED_haxor_math_Vector2
#include <haxor/math/Vector2.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_math_Vector4
#include <haxor/math/Vector4.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void ColladaInput_obj::__construct()
{
HX_STACK_FRAME("haxor.io.file.ColladaInput","new",0x731bf1a0,"haxor.io.file.ColladaInput.new","haxor/io/file/ColladaFile.hx",1191,0xa1888587)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(1197)
	this->stride = (int)0;
	HX_STACK_LINE(1196)
	this->values = null();
	HX_STACK_LINE(1195)
	this->set = (int)-1;
	HX_STACK_LINE(1194)
	this->offset = (int)0;
	HX_STACK_LINE(1193)
	this->semantic = HX_CSTRING("");
	HX_STACK_LINE(1201)
	this->values = Dynamic( Array_obj<Dynamic>::__new());
}
;
	return null();
}

//ColladaInput_obj::~ColladaInput_obj() { }

Dynamic ColladaInput_obj::__CreateEmpty() { return  new ColladaInput_obj; }
hx::ObjectPtr< ColladaInput_obj > ColladaInput_obj::__new()
{  hx::ObjectPtr< ColladaInput_obj > result = new ColladaInput_obj();
	result->__construct();
	return result;}

Dynamic ColladaInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ColladaInput_obj > result = new ColladaInput_obj();
	result->__construct();
	return result;}

Dynamic ColladaInput_obj::GetVectorArray( ){
	HX_STACK_FRAME("haxor.io.file.ColladaInput","GetVectorArray",0xd88157c0,"haxor.io.file.ColladaInput.GetVectorArray","haxor/io/file/ColladaFile.hx",1205,0xa1888587)
	HX_STACK_THIS(this)
	HX_STACK_LINE(1206)
	if (((this->stride <= (int)0))){
		HX_STACK_LINE(1206)
		return Dynamic( Array_obj<Dynamic>::__new());
	}
	HX_STACK_LINE(1207)
	Dynamic res = Dynamic( Array_obj<Dynamic>::__new());		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(1208)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(1210)
	while((true)){
		HX_STACK_LINE(1210)
		if ((!(((i < this->values->__Field(HX_CSTRING("length"),true)))))){
			HX_STACK_LINE(1210)
			break;
		}
		HX_STACK_LINE(1212)
		Dynamic v = null();		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(1213)
		{
			HX_STACK_LINE(1213)
			int _g = this->stride;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(1213)
			switch( (int)(_g)){
				case (int)1: {
					HX_STACK_LINE(1215)
					v = this->values->__GetItem(i);
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(1216)
					::haxor::math::Vector2 _g1 = ::haxor::math::Vector2_obj::__new(this->values->__GetItem(i),this->values->__GetItem((i + (int)1)));		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(1216)
					v = _g1;
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(1217)
					Dynamic _g1;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(1217)
					if (((this->semantic == HX_CSTRING("color")))){
						HX_STACK_LINE(1217)
						_g1 = ::haxor::math::Color_obj::__new(this->values->__GetItem(i),this->values->__GetItem((i + (int)1)),this->values->__GetItem((i + (int)2)),null());
					}
					else{
						HX_STACK_LINE(1217)
						_g1 = ::haxor::math::Vector3_obj::__new(this->values->__GetItem(i),this->values->__GetItem((i + (int)1)),this->values->__GetItem((i + (int)2)));
					}
					HX_STACK_LINE(1217)
					v = _g1;
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(1218)
					Dynamic _g2;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(1218)
					if (((this->semantic == HX_CSTRING("color")))){
						HX_STACK_LINE(1218)
						_g2 = ::haxor::math::Color_obj::__new(this->values->__GetItem(i),this->values->__GetItem((i + (int)1)),this->values->__GetItem((i + (int)2)),this->values->__GetItem((i + (int)3)));
					}
					else{
						HX_STACK_LINE(1218)
						_g2 = ::haxor::math::Vector4_obj::__new(this->values->__GetItem(i),this->values->__GetItem((i + (int)1)),this->values->__GetItem((i + (int)2)),this->values->__GetItem((i + (int)3)));
					}
					HX_STACK_LINE(1218)
					v = _g2;
				}
				;break;
			}
		}
		HX_STACK_LINE(1220)
		if (((v == null()))){
			HX_STACK_LINE(1220)
			continue;
		}
		HX_STACK_LINE(1222)
		res->__Field(HX_CSTRING("push"),true)(v);
		HX_STACK_LINE(1223)
		hx::AddEq(i,this->stride);
	}
	HX_STACK_LINE(1225)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC0(ColladaInput_obj,GetVectorArray,return )


ColladaInput_obj::ColladaInput_obj()
{
}

void ColladaInput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ColladaInput);
	HX_MARK_MEMBER_NAME(semantic,"semantic");
	HX_MARK_MEMBER_NAME(offset,"offset");
	HX_MARK_MEMBER_NAME(set,"set");
	HX_MARK_MEMBER_NAME(values,"values");
	HX_MARK_MEMBER_NAME(stride,"stride");
	HX_MARK_END_CLASS();
}

void ColladaInput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(semantic,"semantic");
	HX_VISIT_MEMBER_NAME(offset,"offset");
	HX_VISIT_MEMBER_NAME(set,"set");
	HX_VISIT_MEMBER_NAME(values,"values");
	HX_VISIT_MEMBER_NAME(stride,"stride");
}

Dynamic ColladaInput_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { return offset; }
		if (HX_FIELD_EQ(inName,"values") ) { return values; }
		if (HX_FIELD_EQ(inName,"stride") ) { return stride; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"semantic") ) { return semantic; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"GetVectorArray") ) { return GetVectorArray_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ColladaInput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { set=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { offset=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"values") ) { values=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"stride") ) { stride=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"semantic") ) { semantic=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ColladaInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("semantic"));
	outFields->push(HX_CSTRING("offset"));
	outFields->push(HX_CSTRING("set"));
	outFields->push(HX_CSTRING("values"));
	outFields->push(HX_CSTRING("stride"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(ColladaInput_obj,semantic),HX_CSTRING("semantic")},
	{hx::fsInt,(int)offsetof(ColladaInput_obj,offset),HX_CSTRING("offset")},
	{hx::fsInt,(int)offsetof(ColladaInput_obj,set),HX_CSTRING("set")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(ColladaInput_obj,values),HX_CSTRING("values")},
	{hx::fsInt,(int)offsetof(ColladaInput_obj,stride),HX_CSTRING("stride")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("semantic"),
	HX_CSTRING("offset"),
	HX_CSTRING("set"),
	HX_CSTRING("values"),
	HX_CSTRING("stride"),
	HX_CSTRING("GetVectorArray"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ColladaInput_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ColladaInput_obj::__mClass,"__mClass");
};

#endif

Class ColladaInput_obj::__mClass;

void ColladaInput_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.ColladaInput"), hx::TCanCast< ColladaInput_obj> ,sStaticFields,sMemberFields,
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

void ColladaInput_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
