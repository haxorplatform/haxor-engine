#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_math_AABB2
#include <haxor/math/AABB2.h>
#endif
#ifndef INCLUDED_haxor_math_AABB3
#include <haxor/math/AABB3.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Quaternion
#include <haxor/math/Quaternion.h>
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
namespace context{

Void DataContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.DataContext","new",0xc27c598c,"haxor.context.DataContext.new","haxor/context/DataContext.hx",103,0xbece83e6)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(104)
	this->i = Array_obj< int >::__new();
	HX_STACK_LINE(105)
	this->v = Array_obj< Float >::__new();
	HX_STACK_LINE(106)
	this->m_v2 = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(107)
	this->m_v3 = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(108)
	this->m_v4 = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(109)
	this->m_c = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(110)
	this->m_q = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(111)
	this->m_m4 = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(112)
	this->m_aabb3 = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(113)
	this->m_aabb2 = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(115)
	this->m_nv2 = (int)0;
	HX_STACK_LINE(116)
	this->m_nv3 = (int)0;
	HX_STACK_LINE(117)
	this->m_nv4 = (int)0;
	HX_STACK_LINE(118)
	this->m_nc = (int)0;
	HX_STACK_LINE(119)
	this->m_nq = (int)0;
	HX_STACK_LINE(120)
	this->m_nm4 = (int)0;
	HX_STACK_LINE(121)
	this->m_naabb3 = (int)0;
	HX_STACK_LINE(122)
	this->m_naabb2 = (int)0;
	HX_STACK_LINE(124)
	this->m4l = Array_obj< Float >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0);
	HX_STACK_LINE(126)
	{
		HX_STACK_LINE(126)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(126)
		int _g = ::haxor::context::DataContext_obj::MAX_TEMP;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(126)
		while((true)){
			HX_STACK_LINE(126)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(126)
				break;
			}
			HX_STACK_LINE(126)
			int k = (_g1)++;		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(128)
			this->i->push((int)0);
			HX_STACK_LINE(129)
			this->v->push(0.0);
			HX_STACK_LINE(130)
			::haxor::math::Vector2 _g2 = ::haxor::math::Vector2_obj::__new((int)0,(int)0);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(130)
			this->m_v2->push(_g2);
			HX_STACK_LINE(131)
			::haxor::math::Vector3 _g11 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(131)
			this->m_v3->push(_g11);
			HX_STACK_LINE(132)
			::haxor::math::Vector4 _g21 = ::haxor::math::Vector4_obj::__new((int)0,(int)0,(int)0,(int)0);		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(132)
			this->m_v4->push(_g21);
			HX_STACK_LINE(133)
			::haxor::math::Color _g3 = ::haxor::math::Color_obj::__new((int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(133)
			this->m_c->push(_g3);
			HX_STACK_LINE(134)
			::haxor::math::Quaternion _g4 = ::haxor::math::Quaternion_obj::__new((int)0,(int)0,(int)0,1.0);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(134)
			this->m_q->push(_g4);
			HX_STACK_LINE(135)
			::haxor::math::Matrix4 _g5 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(135)
			this->m_m4->push(_g5);
			HX_STACK_LINE(136)
			::haxor::math::AABB3 _g6 = ::haxor::math::AABB3_obj::get_empty();		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(136)
			this->m_aabb3->push(_g6);
			HX_STACK_LINE(137)
			::haxor::math::AABB2 _g7 = ::haxor::math::AABB2_obj::get_empty();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(137)
			this->m_aabb2->push(_g7);
		}
	}
}
;
	return null();
}

//DataContext_obj::~DataContext_obj() { }

Dynamic DataContext_obj::__CreateEmpty() { return  new DataContext_obj; }
hx::ObjectPtr< DataContext_obj > DataContext_obj::__new()
{  hx::ObjectPtr< DataContext_obj > result = new DataContext_obj();
	result->__construct();
	return result;}

Dynamic DataContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DataContext_obj > result = new DataContext_obj();
	result->__construct();
	return result;}

::haxor::math::Vector2 DataContext_obj::get_v2( ){
	HX_STACK_FRAME("haxor.context.DataContext","get_v2",0x55587899,"haxor.context.DataContext.get_v2","haxor/context/DataContext.hx",40,0xbece83e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(40)
	int _g = this->m_nv2 = hx::Mod(((this->m_nv2 + (int)1)),this->m_v2->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(40)
	return this->m_v2->__get(_g).StaticCast< ::haxor::math::Vector2 >();
}


HX_DEFINE_DYNAMIC_FUNC0(DataContext_obj,get_v2,return )

::haxor::math::Vector3 DataContext_obj::get_v3( ){
	HX_STACK_FRAME("haxor.context.DataContext","get_v3",0x5558789a,"haxor.context.DataContext.get_v3","haxor/context/DataContext.hx",48,0xbece83e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(48)
	int _g = this->m_nv3 = hx::Mod(((this->m_nv3 + (int)1)),this->m_v3->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(48)
	return this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
}


HX_DEFINE_DYNAMIC_FUNC0(DataContext_obj,get_v3,return )

::haxor::math::Vector4 DataContext_obj::get_v4( ){
	HX_STACK_FRAME("haxor.context.DataContext","get_v4",0x5558789b,"haxor.context.DataContext.get_v4","haxor/context/DataContext.hx",56,0xbece83e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(56)
	int _g = this->m_nv4 = hx::Mod(((this->m_nv4 + (int)1)),this->m_v4->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(56)
	return this->m_v4->__get(_g).StaticCast< ::haxor::math::Vector4 >();
}


HX_DEFINE_DYNAMIC_FUNC0(DataContext_obj,get_v4,return )

::haxor::math::Color DataContext_obj::get_c( ){
	HX_STACK_FRAME("haxor.context.DataContext","get_c",0x959ed166,"haxor.context.DataContext.get_c","haxor/context/DataContext.hx",64,0xbece83e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(64)
	int _g = this->m_nc = hx::Mod(((this->m_nc + (int)1)),this->m_c->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(64)
	return this->m_c->__get(_g).StaticCast< ::haxor::math::Color >();
}


HX_DEFINE_DYNAMIC_FUNC0(DataContext_obj,get_c,return )

::haxor::math::Quaternion DataContext_obj::get_q( ){
	HX_STACK_FRAME("haxor.context.DataContext","get_q",0x959ed174,"haxor.context.DataContext.get_q","haxor/context/DataContext.hx",72,0xbece83e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(72)
	int _g = this->m_nq = hx::Mod(((this->m_nq + (int)1)),this->m_q->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(72)
	return this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
}


HX_DEFINE_DYNAMIC_FUNC0(DataContext_obj,get_q,return )

::haxor::math::AABB3 DataContext_obj::get_aabb3( ){
	HX_STACK_FRAME("haxor.context.DataContext","get_aabb3",0x5055b816,"haxor.context.DataContext.get_aabb3","haxor/context/DataContext.hx",80,0xbece83e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(80)
	int _g = this->m_naabb3 = hx::Mod(((this->m_naabb3 + (int)1)),this->m_aabb3->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(80)
	return this->m_aabb3->__get(_g).StaticCast< ::haxor::math::AABB3 >();
}


HX_DEFINE_DYNAMIC_FUNC0(DataContext_obj,get_aabb3,return )

::haxor::math::AABB2 DataContext_obj::get_aabb2( ){
	HX_STACK_FRAME("haxor.context.DataContext","get_aabb2",0x5055b815,"haxor.context.DataContext.get_aabb2","haxor/context/DataContext.hx",88,0xbece83e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(88)
	int _g = this->m_naabb2 = hx::Mod(((this->m_naabb2 + (int)1)),this->m_aabb2->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(88)
	return this->m_aabb2->__get(_g).StaticCast< ::haxor::math::AABB2 >();
}


HX_DEFINE_DYNAMIC_FUNC0(DataContext_obj,get_aabb2,return )

::haxor::math::Matrix4 DataContext_obj::get_m4( ){
	HX_STACK_FRAME("haxor.context.DataContext","get_m4",0x555870c4,"haxor.context.DataContext.get_m4","haxor/context/DataContext.hx",96,0xbece83e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(96)
	int _g = this->m_nq = hx::Mod(((this->m_nm4 + (int)1)),this->m_m4->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(96)
	return this->m_m4->__get(_g).StaticCast< ::haxor::math::Matrix4 >();
}


HX_DEFINE_DYNAMIC_FUNC0(DataContext_obj,get_m4,return )

int DataContext_obj::MAX_TEMP;


DataContext_obj::DataContext_obj()
{
}

void DataContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DataContext);
	HX_MARK_MEMBER_NAME(i,"i");
	HX_MARK_MEMBER_NAME(v,"v");
	HX_MARK_MEMBER_NAME(v2,"v2");
	HX_MARK_MEMBER_NAME(m_v2,"m_v2");
	HX_MARK_MEMBER_NAME(m_nv2,"m_nv2");
	HX_MARK_MEMBER_NAME(v3,"v3");
	HX_MARK_MEMBER_NAME(m_v3,"m_v3");
	HX_MARK_MEMBER_NAME(m_nv3,"m_nv3");
	HX_MARK_MEMBER_NAME(v4,"v4");
	HX_MARK_MEMBER_NAME(m_v4,"m_v4");
	HX_MARK_MEMBER_NAME(m_nv4,"m_nv4");
	HX_MARK_MEMBER_NAME(c,"c");
	HX_MARK_MEMBER_NAME(m_c,"m_c");
	HX_MARK_MEMBER_NAME(m_nc,"m_nc");
	HX_MARK_MEMBER_NAME(q,"q");
	HX_MARK_MEMBER_NAME(m_q,"m_q");
	HX_MARK_MEMBER_NAME(m_nq,"m_nq");
	HX_MARK_MEMBER_NAME(aabb3,"aabb3");
	HX_MARK_MEMBER_NAME(m_aabb3,"m_aabb3");
	HX_MARK_MEMBER_NAME(m_naabb3,"m_naabb3");
	HX_MARK_MEMBER_NAME(aabb2,"aabb2");
	HX_MARK_MEMBER_NAME(m_aabb2,"m_aabb2");
	HX_MARK_MEMBER_NAME(m_naabb2,"m_naabb2");
	HX_MARK_MEMBER_NAME(m4,"m4");
	HX_MARK_MEMBER_NAME(m_m4,"m_m4");
	HX_MARK_MEMBER_NAME(m_nm4,"m_nm4");
	HX_MARK_MEMBER_NAME(m4l,"m4l");
	HX_MARK_END_CLASS();
}

void DataContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(i,"i");
	HX_VISIT_MEMBER_NAME(v,"v");
	HX_VISIT_MEMBER_NAME(v2,"v2");
	HX_VISIT_MEMBER_NAME(m_v2,"m_v2");
	HX_VISIT_MEMBER_NAME(m_nv2,"m_nv2");
	HX_VISIT_MEMBER_NAME(v3,"v3");
	HX_VISIT_MEMBER_NAME(m_v3,"m_v3");
	HX_VISIT_MEMBER_NAME(m_nv3,"m_nv3");
	HX_VISIT_MEMBER_NAME(v4,"v4");
	HX_VISIT_MEMBER_NAME(m_v4,"m_v4");
	HX_VISIT_MEMBER_NAME(m_nv4,"m_nv4");
	HX_VISIT_MEMBER_NAME(c,"c");
	HX_VISIT_MEMBER_NAME(m_c,"m_c");
	HX_VISIT_MEMBER_NAME(m_nc,"m_nc");
	HX_VISIT_MEMBER_NAME(q,"q");
	HX_VISIT_MEMBER_NAME(m_q,"m_q");
	HX_VISIT_MEMBER_NAME(m_nq,"m_nq");
	HX_VISIT_MEMBER_NAME(aabb3,"aabb3");
	HX_VISIT_MEMBER_NAME(m_aabb3,"m_aabb3");
	HX_VISIT_MEMBER_NAME(m_naabb3,"m_naabb3");
	HX_VISIT_MEMBER_NAME(aabb2,"aabb2");
	HX_VISIT_MEMBER_NAME(m_aabb2,"m_aabb2");
	HX_VISIT_MEMBER_NAME(m_naabb2,"m_naabb2");
	HX_VISIT_MEMBER_NAME(m4,"m4");
	HX_VISIT_MEMBER_NAME(m_m4,"m_m4");
	HX_VISIT_MEMBER_NAME(m_nm4,"m_nm4");
	HX_VISIT_MEMBER_NAME(m4l,"m4l");
}

Dynamic DataContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"i") ) { return i; }
		if (HX_FIELD_EQ(inName,"v") ) { return v; }
		if (HX_FIELD_EQ(inName,"c") ) { return inCallProp ? get_c() : c; }
		if (HX_FIELD_EQ(inName,"q") ) { return inCallProp ? get_q() : q; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"v2") ) { return inCallProp ? get_v2() : v2; }
		if (HX_FIELD_EQ(inName,"v3") ) { return inCallProp ? get_v3() : v3; }
		if (HX_FIELD_EQ(inName,"v4") ) { return inCallProp ? get_v4() : v4; }
		if (HX_FIELD_EQ(inName,"m4") ) { return inCallProp ? get_m4() : m4; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"m_c") ) { return m_c; }
		if (HX_FIELD_EQ(inName,"m_q") ) { return m_q; }
		if (HX_FIELD_EQ(inName,"m4l") ) { return m4l; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"m_v2") ) { return m_v2; }
		if (HX_FIELD_EQ(inName,"m_v3") ) { return m_v3; }
		if (HX_FIELD_EQ(inName,"m_v4") ) { return m_v4; }
		if (HX_FIELD_EQ(inName,"m_nc") ) { return m_nc; }
		if (HX_FIELD_EQ(inName,"m_nq") ) { return m_nq; }
		if (HX_FIELD_EQ(inName,"m_m4") ) { return m_m4; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_nv2") ) { return m_nv2; }
		if (HX_FIELD_EQ(inName,"m_nv3") ) { return m_nv3; }
		if (HX_FIELD_EQ(inName,"m_nv4") ) { return m_nv4; }
		if (HX_FIELD_EQ(inName,"get_c") ) { return get_c_dyn(); }
		if (HX_FIELD_EQ(inName,"get_q") ) { return get_q_dyn(); }
		if (HX_FIELD_EQ(inName,"aabb3") ) { return inCallProp ? get_aabb3() : aabb3; }
		if (HX_FIELD_EQ(inName,"aabb2") ) { return inCallProp ? get_aabb2() : aabb2; }
		if (HX_FIELD_EQ(inName,"m_nm4") ) { return m_nm4; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"get_v2") ) { return get_v2_dyn(); }
		if (HX_FIELD_EQ(inName,"get_v3") ) { return get_v3_dyn(); }
		if (HX_FIELD_EQ(inName,"get_v4") ) { return get_v4_dyn(); }
		if (HX_FIELD_EQ(inName,"get_m4") ) { return get_m4_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_aabb3") ) { return m_aabb3; }
		if (HX_FIELD_EQ(inName,"m_aabb2") ) { return m_aabb2; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MAX_TEMP") ) { return MAX_TEMP; }
		if (HX_FIELD_EQ(inName,"m_naabb3") ) { return m_naabb3; }
		if (HX_FIELD_EQ(inName,"m_naabb2") ) { return m_naabb2; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_aabb3") ) { return get_aabb3_dyn(); }
		if (HX_FIELD_EQ(inName,"get_aabb2") ) { return get_aabb2_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DataContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"i") ) { i=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"v") ) { v=inValue.Cast< Array< Float > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"c") ) { c=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"q") ) { q=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"v2") ) { v2=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"v3") ) { v3=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"v4") ) { v4=inValue.Cast< ::haxor::math::Vector4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m4") ) { m4=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"m_c") ) { m_c=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_q") ) { m_q=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m4l") ) { m4l=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"m_v2") ) { m_v2=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_v3") ) { m_v3=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_v4") ) { m_v4=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_nc") ) { m_nc=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_nq") ) { m_nq=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_m4") ) { m_m4=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_nv2") ) { m_nv2=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_nv3") ) { m_nv3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_nv4") ) { m_nv4=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"aabb3") ) { aabb3=inValue.Cast< ::haxor::math::AABB3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"aabb2") ) { aabb2=inValue.Cast< ::haxor::math::AABB2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_nm4") ) { m_nm4=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_aabb3") ) { m_aabb3=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_aabb2") ) { m_aabb2=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MAX_TEMP") ) { MAX_TEMP=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_naabb3") ) { m_naabb3=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_naabb2") ) { m_naabb2=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DataContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("i"));
	outFields->push(HX_CSTRING("v"));
	outFields->push(HX_CSTRING("v2"));
	outFields->push(HX_CSTRING("m_v2"));
	outFields->push(HX_CSTRING("m_nv2"));
	outFields->push(HX_CSTRING("v3"));
	outFields->push(HX_CSTRING("m_v3"));
	outFields->push(HX_CSTRING("m_nv3"));
	outFields->push(HX_CSTRING("v4"));
	outFields->push(HX_CSTRING("m_v4"));
	outFields->push(HX_CSTRING("m_nv4"));
	outFields->push(HX_CSTRING("c"));
	outFields->push(HX_CSTRING("m_c"));
	outFields->push(HX_CSTRING("m_nc"));
	outFields->push(HX_CSTRING("q"));
	outFields->push(HX_CSTRING("m_q"));
	outFields->push(HX_CSTRING("m_nq"));
	outFields->push(HX_CSTRING("aabb3"));
	outFields->push(HX_CSTRING("m_aabb3"));
	outFields->push(HX_CSTRING("m_naabb3"));
	outFields->push(HX_CSTRING("aabb2"));
	outFields->push(HX_CSTRING("m_aabb2"));
	outFields->push(HX_CSTRING("m_naabb2"));
	outFields->push(HX_CSTRING("m4"));
	outFields->push(HX_CSTRING("m_m4"));
	outFields->push(HX_CSTRING("m_nm4"));
	outFields->push(HX_CSTRING("m4l"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("MAX_TEMP"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(DataContext_obj,i),HX_CSTRING("i")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(DataContext_obj,v),HX_CSTRING("v")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(DataContext_obj,v2),HX_CSTRING("v2")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(DataContext_obj,m_v2),HX_CSTRING("m_v2")},
	{hx::fsInt,(int)offsetof(DataContext_obj,m_nv2),HX_CSTRING("m_nv2")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(DataContext_obj,v3),HX_CSTRING("v3")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(DataContext_obj,m_v3),HX_CSTRING("m_v3")},
	{hx::fsInt,(int)offsetof(DataContext_obj,m_nv3),HX_CSTRING("m_nv3")},
	{hx::fsObject /*::haxor::math::Vector4*/ ,(int)offsetof(DataContext_obj,v4),HX_CSTRING("v4")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(DataContext_obj,m_v4),HX_CSTRING("m_v4")},
	{hx::fsInt,(int)offsetof(DataContext_obj,m_nv4),HX_CSTRING("m_nv4")},
	{hx::fsObject /*::haxor::math::Color*/ ,(int)offsetof(DataContext_obj,c),HX_CSTRING("c")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(DataContext_obj,m_c),HX_CSTRING("m_c")},
	{hx::fsInt,(int)offsetof(DataContext_obj,m_nc),HX_CSTRING("m_nc")},
	{hx::fsObject /*::haxor::math::Quaternion*/ ,(int)offsetof(DataContext_obj,q),HX_CSTRING("q")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(DataContext_obj,m_q),HX_CSTRING("m_q")},
	{hx::fsInt,(int)offsetof(DataContext_obj,m_nq),HX_CSTRING("m_nq")},
	{hx::fsObject /*::haxor::math::AABB3*/ ,(int)offsetof(DataContext_obj,aabb3),HX_CSTRING("aabb3")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(DataContext_obj,m_aabb3),HX_CSTRING("m_aabb3")},
	{hx::fsInt,(int)offsetof(DataContext_obj,m_naabb3),HX_CSTRING("m_naabb3")},
	{hx::fsObject /*::haxor::math::AABB2*/ ,(int)offsetof(DataContext_obj,aabb2),HX_CSTRING("aabb2")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(DataContext_obj,m_aabb2),HX_CSTRING("m_aabb2")},
	{hx::fsInt,(int)offsetof(DataContext_obj,m_naabb2),HX_CSTRING("m_naabb2")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(DataContext_obj,m4),HX_CSTRING("m4")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(DataContext_obj,m_m4),HX_CSTRING("m_m4")},
	{hx::fsInt,(int)offsetof(DataContext_obj,m_nm4),HX_CSTRING("m_nm4")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(DataContext_obj,m4l),HX_CSTRING("m4l")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("i"),
	HX_CSTRING("v"),
	HX_CSTRING("v2"),
	HX_CSTRING("get_v2"),
	HX_CSTRING("m_v2"),
	HX_CSTRING("m_nv2"),
	HX_CSTRING("v3"),
	HX_CSTRING("get_v3"),
	HX_CSTRING("m_v3"),
	HX_CSTRING("m_nv3"),
	HX_CSTRING("v4"),
	HX_CSTRING("get_v4"),
	HX_CSTRING("m_v4"),
	HX_CSTRING("m_nv4"),
	HX_CSTRING("c"),
	HX_CSTRING("get_c"),
	HX_CSTRING("m_c"),
	HX_CSTRING("m_nc"),
	HX_CSTRING("q"),
	HX_CSTRING("get_q"),
	HX_CSTRING("m_q"),
	HX_CSTRING("m_nq"),
	HX_CSTRING("aabb3"),
	HX_CSTRING("get_aabb3"),
	HX_CSTRING("m_aabb3"),
	HX_CSTRING("m_naabb3"),
	HX_CSTRING("aabb2"),
	HX_CSTRING("get_aabb2"),
	HX_CSTRING("m_aabb2"),
	HX_CSTRING("m_naabb2"),
	HX_CSTRING("m4"),
	HX_CSTRING("get_m4"),
	HX_CSTRING("m_m4"),
	HX_CSTRING("m_nm4"),
	HX_CSTRING("m4l"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DataContext_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(DataContext_obj::MAX_TEMP,"MAX_TEMP");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DataContext_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(DataContext_obj::MAX_TEMP,"MAX_TEMP");
};

#endif

Class DataContext_obj::__mClass;

void DataContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.DataContext"), hx::TCanCast< DataContext_obj> ,sStaticFields,sMemberFields,
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

void DataContext_obj::__boot()
{
	MAX_TEMP= (int)128;
}

} // end namespace haxor
} // end namespace context
