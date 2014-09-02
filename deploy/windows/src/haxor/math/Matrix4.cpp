#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace math{

Void Matrix4_obj::__construct(hx::Null< Float >  __o_p_m00,hx::Null< Float >  __o_p_m01,hx::Null< Float >  __o_p_m02,hx::Null< Float >  __o_p_m03,hx::Null< Float >  __o_p_m10,hx::Null< Float >  __o_p_m11,hx::Null< Float >  __o_p_m12,hx::Null< Float >  __o_p_m13,hx::Null< Float >  __o_p_m20,hx::Null< Float >  __o_p_m21,hx::Null< Float >  __o_p_m22,hx::Null< Float >  __o_p_m23,hx::Null< Float >  __o_p_m30,hx::Null< Float >  __o_p_m31,hx::Null< Float >  __o_p_m32,hx::Null< Float >  __o_p_m33)
{
HX_STACK_FRAME("haxor.math.Matrix4","new",0xdf8f7d2b,"haxor.math.Matrix4.new","haxor/math/Matrix4.hx",439,0xc9a22505)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_m00,"p_m00")
HX_STACK_ARG(__o_p_m01,"p_m01")
HX_STACK_ARG(__o_p_m02,"p_m02")
HX_STACK_ARG(__o_p_m03,"p_m03")
HX_STACK_ARG(__o_p_m10,"p_m10")
HX_STACK_ARG(__o_p_m11,"p_m11")
HX_STACK_ARG(__o_p_m12,"p_m12")
HX_STACK_ARG(__o_p_m13,"p_m13")
HX_STACK_ARG(__o_p_m20,"p_m20")
HX_STACK_ARG(__o_p_m21,"p_m21")
HX_STACK_ARG(__o_p_m22,"p_m22")
HX_STACK_ARG(__o_p_m23,"p_m23")
HX_STACK_ARG(__o_p_m30,"p_m30")
HX_STACK_ARG(__o_p_m31,"p_m31")
HX_STACK_ARG(__o_p_m32,"p_m32")
HX_STACK_ARG(__o_p_m33,"p_m33")
Float p_m00 = __o_p_m00.Default(0);
Float p_m01 = __o_p_m01.Default(0);
Float p_m02 = __o_p_m02.Default(0);
Float p_m03 = __o_p_m03.Default(0);
Float p_m10 = __o_p_m10.Default(0);
Float p_m11 = __o_p_m11.Default(0);
Float p_m12 = __o_p_m12.Default(0);
Float p_m13 = __o_p_m13.Default(0);
Float p_m20 = __o_p_m20.Default(0);
Float p_m21 = __o_p_m21.Default(0);
Float p_m22 = __o_p_m22.Default(0);
Float p_m23 = __o_p_m23.Default(0);
Float p_m30 = __o_p_m30.Default(0);
Float p_m31 = __o_p_m31.Default(0);
Float p_m32 = __o_p_m32.Default(0);
Float p_m33 = __o_p_m33.Default(0);
{
	HX_STACK_LINE(440)
	this->m00 = p_m00;
	HX_STACK_LINE(440)
	this->m01 = p_m01;
	HX_STACK_LINE(440)
	this->m02 = p_m02;
	HX_STACK_LINE(440)
	this->m03 = p_m03;
	HX_STACK_LINE(440)
	this->m10 = p_m10;
	HX_STACK_LINE(440)
	this->m11 = p_m11;
	HX_STACK_LINE(440)
	this->m12 = p_m12;
	HX_STACK_LINE(440)
	this->m13 = p_m13;
	HX_STACK_LINE(440)
	this->m20 = p_m20;
	HX_STACK_LINE(440)
	this->m21 = p_m21;
	HX_STACK_LINE(440)
	this->m22 = p_m22;
	HX_STACK_LINE(440)
	this->m23 = p_m23;
	HX_STACK_LINE(440)
	this->m30 = p_m30;
	HX_STACK_LINE(440)
	this->m31 = p_m31;
	HX_STACK_LINE(440)
	this->m32 = p_m32;
	HX_STACK_LINE(440)
	this->m33 = p_m33;
}
;
	return null();
}

//Matrix4_obj::~Matrix4_obj() { }

Dynamic Matrix4_obj::__CreateEmpty() { return  new Matrix4_obj; }
hx::ObjectPtr< Matrix4_obj > Matrix4_obj::__new(hx::Null< Float >  __o_p_m00,hx::Null< Float >  __o_p_m01,hx::Null< Float >  __o_p_m02,hx::Null< Float >  __o_p_m03,hx::Null< Float >  __o_p_m10,hx::Null< Float >  __o_p_m11,hx::Null< Float >  __o_p_m12,hx::Null< Float >  __o_p_m13,hx::Null< Float >  __o_p_m20,hx::Null< Float >  __o_p_m21,hx::Null< Float >  __o_p_m22,hx::Null< Float >  __o_p_m23,hx::Null< Float >  __o_p_m30,hx::Null< Float >  __o_p_m31,hx::Null< Float >  __o_p_m32,hx::Null< Float >  __o_p_m33)
{  hx::ObjectPtr< Matrix4_obj > result = new Matrix4_obj();
	result->__construct(__o_p_m00,__o_p_m01,__o_p_m02,__o_p_m03,__o_p_m10,__o_p_m11,__o_p_m12,__o_p_m13,__o_p_m20,__o_p_m21,__o_p_m22,__o_p_m23,__o_p_m30,__o_p_m31,__o_p_m32,__o_p_m33);
	return result;}

Dynamic Matrix4_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Matrix4_obj > result = new Matrix4_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6],inArgs[7],inArgs[8],inArgs[9],inArgs[10],inArgs[11],inArgs[12],inArgs[13],inArgs[14],inArgs[15]);
	return result;}

::haxor::math::Matrix4 Matrix4_obj::get_clone( ){
	HX_STACK_FRAME("haxor.math.Matrix4","get_clone",0x6ed646bf,"haxor.math.Matrix4.get_clone","haxor/math/Matrix4.hx",306,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(306)
	return ::haxor::math::Matrix4_obj::__new(this->m00,this->m01,this->m02,this->m03,this->m10,this->m11,this->m12,this->m13,this->m20,this->m21,this->m22,this->m23,this->m30,this->m31,this->m32,this->m33);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,get_clone,return )

::haxor::math::Quaternion Matrix4_obj::get_quaternion( ){
	HX_STACK_FRAME("haxor.math.Matrix4","get_quaternion",0x16d7567c,"haxor.math.Matrix4.get_quaternion","haxor/math/Matrix4.hx",312,0xc9a22505)
	HX_STACK_THIS(this)
	struct _Function_1_1{
		inline static ::haxor::math::Matrix4 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Matrix4.hx",312,0xc9a22505)
			{
				HX_STACK_LINE(312)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(312)
				int _g = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(312)
				return _this->m_m4->__get(_g).StaticCast< ::haxor::math::Matrix4 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(312)
	::haxor::math::Matrix4 _g1 = (_Function_1_1::Block())->SetMatrix4(hx::ObjectPtr<OBJ_>(this))->ToRotation();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(312)
	return ::haxor::math::Quaternion_obj::FromMatrix4(_g1,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,get_quaternion,return )

::haxor::math::Quaternion Matrix4_obj::set_quaternion( ::haxor::math::Quaternion v){
	HX_STACK_FRAME("haxor.math.Matrix4","set_quaternion",0x36f73ef0,"haxor.math.Matrix4.set_quaternion","haxor/math/Matrix4.hx",313,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(313)
	::haxor::math::Matrix4_obj::FromQuaternion(v,hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(313)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,set_quaternion,return )

Float Matrix4_obj::get_trace( ){
	HX_STACK_FRAME("haxor.math.Matrix4","get_trace",0x3c92c1e7,"haxor.math.Matrix4.get_trace","haxor/math/Matrix4.hx",319,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(319)
	return (((this->m00 + this->m11) + this->m22) + this->m33);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,get_trace,return )

::haxor::math::Matrix4 Matrix4_obj::get_rotation( ){
	HX_STACK_FRAME("haxor.math.Matrix4","get_rotation",0x229bd31c,"haxor.math.Matrix4.get_rotation","haxor/math/Matrix4.hx",326,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(326)
	return ::haxor::math::Matrix4_obj::__new(this->m00,this->m01,this->m02,this->m03,this->m10,this->m11,this->m12,this->m13,this->m20,this->m21,this->m22,this->m23,this->m30,this->m31,this->m32,this->m33)->ToRotation();
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,get_rotation,return )

::haxor::math::Matrix4 Matrix4_obj::get_scale( ){
	HX_STACK_FRAME("haxor.math.Matrix4","get_scale",0x9f4201ec,"haxor.math.Matrix4.get_scale","haxor/math/Matrix4.hx",333,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(334)
	Float d0 = ::Math_obj::sqrt((((this->m00 * this->m00) + (this->m10 * this->m10)) + (this->m20 * this->m20)));		HX_STACK_VAR(d0,"d0");
	HX_STACK_LINE(335)
	Float d1 = ::Math_obj::sqrt((((this->m01 * this->m01) + (this->m11 * this->m11)) + (this->m21 * this->m21)));		HX_STACK_VAR(d1,"d1");
	HX_STACK_LINE(336)
	Float d2 = ::Math_obj::sqrt((((this->m02 * this->m02) + (this->m12 * this->m12)) + (this->m22 * this->m22)));		HX_STACK_VAR(d2,"d2");
	HX_STACK_LINE(337)
	return ::haxor::math::Matrix4_obj::__new(d0,(int)0,(int)0,(int)0,(int)0,d1,(int)0,(int)0,(int)0,(int)0,d2,(int)0,(int)0,(int)0,(int)0,(int)1);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,get_scale,return )

::haxor::math::Matrix4 Matrix4_obj::get_translation( ){
	HX_STACK_FRAME("haxor.math.Matrix4","get_translation",0x3b3519d3,"haxor.math.Matrix4.get_translation","haxor/math/Matrix4.hx",344,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(344)
	return ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,this->m03,(int)0,(int)1,(int)0,this->m13,(int)0,(int)0,(int)1,this->m23,(int)0,(int)0,(int)0,(int)1);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,get_translation,return )

::haxor::math::Matrix4 Matrix4_obj::get_inverseTransform( ){
	HX_STACK_FRAME("haxor.math.Matrix4","get_inverseTransform",0x0e316f7a,"haxor.math.Matrix4.get_inverseTransform","haxor/math/Matrix4.hx",351,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(352)
	::haxor::math::Matrix4 result = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(353)
	::haxor::math::Vector3 l0 = ::haxor::math::Vector3_obj::__new(this->m00,this->m01,this->m02);		HX_STACK_VAR(l0,"l0");
	HX_STACK_LINE(354)
	::haxor::math::Vector3 l1 = ::haxor::math::Vector3_obj::__new(this->m10,this->m11,this->m12);		HX_STACK_VAR(l1,"l1");
	HX_STACK_LINE(355)
	::haxor::math::Vector3 l2 = ::haxor::math::Vector3_obj::__new(this->m20,this->m21,this->m22);		HX_STACK_VAR(l2,"l2");
	HX_STACK_LINE(356)
	Float vl0 = ::Math_obj::sqrt((((l0->x * l0->x) + (l0->y * l0->y)) + (l0->z * l0->z)));		HX_STACK_VAR(vl0,"vl0");
	HX_STACK_LINE(357)
	Float vl1 = ::Math_obj::sqrt((((l1->x * l1->x) + (l1->y * l1->y)) + (l1->z * l1->z)));		HX_STACK_VAR(vl1,"vl1");
	HX_STACK_LINE(358)
	Float vl2 = ::Math_obj::sqrt((((l2->x * l2->x) + (l2->y * l2->y)) + (l2->z * l2->z)));		HX_STACK_VAR(vl2,"vl2");
	HX_STACK_LINE(361)
	Float sx;		HX_STACK_VAR(sx,"sx");
	HX_STACK_LINE(361)
	if (((((  (((vl0 < (int)0))) ? Float(-(vl0)) : Float(vl0) )) <= 0.0001))){
		HX_STACK_LINE(361)
		sx = 0.0;
	}
	else{
		HX_STACK_LINE(361)
		sx = (Float(1.0) / Float(vl0));
	}
	HX_STACK_LINE(362)
	Float sy;		HX_STACK_VAR(sy,"sy");
	HX_STACK_LINE(362)
	if (((((  (((vl1 < (int)0))) ? Float(-(vl1)) : Float(vl1) )) <= 0.0001))){
		HX_STACK_LINE(362)
		sy = 0.0;
	}
	else{
		HX_STACK_LINE(362)
		sy = (Float(1.0) / Float(vl1));
	}
	HX_STACK_LINE(363)
	Float sz;		HX_STACK_VAR(sz,"sz");
	HX_STACK_LINE(363)
	if (((((  (((vl2 < (int)0))) ? Float(-(vl2)) : Float(vl2) )) <= 0.0001))){
		HX_STACK_LINE(363)
		sz = 0.0;
	}
	else{
		HX_STACK_LINE(363)
		sz = (Float(1.0) / Float(vl2));
	}
	HX_STACK_LINE(366)
	hx::MultEq(l0->x,sx);
	HX_STACK_LINE(366)
	hx::MultEq(l0->y,sx);
	HX_STACK_LINE(366)
	hx::MultEq(l0->z,sx);
	HX_STACK_LINE(367)
	hx::MultEq(l1->x,sy);
	HX_STACK_LINE(367)
	hx::MultEq(l1->y,sy);
	HX_STACK_LINE(367)
	hx::MultEq(l1->z,sy);
	HX_STACK_LINE(368)
	hx::MultEq(l2->x,sz);
	HX_STACK_LINE(368)
	hx::MultEq(l2->y,sz);
	HX_STACK_LINE(368)
	hx::MultEq(l2->z,sz);
	HX_STACK_LINE(370)
	result->Set((sx * l0->x),(sx * l1->x),(sx * l2->x),(sx * ((((l0->x * -(this->m03)) + (l1->x * -(this->m13))) + (l2->x * -(this->m23))))),(sy * l0->y),(sy * l1->y),(sy * l2->y),(sy * ((((l0->y * -(this->m03)) + (l1->y * -(this->m13))) + (l2->y * -(this->m23))))),(sz * l0->z),(sz * l1->z),(sz * l2->z),(sz * ((((l0->z * -(this->m03)) + (l1->z * -(this->m13))) + (l2->z * -(this->m23))))),(int)0,(int)0,(int)0,(int)1);
	HX_STACK_LINE(376)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,get_inverseTransform,return )

::haxor::math::Matrix4 Matrix4_obj::get_transposed( ){
	HX_STACK_FRAME("haxor.math.Matrix4","get_transposed",0x58446329,"haxor.math.Matrix4.get_transposed","haxor/math/Matrix4.hx",384,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(384)
	return ::haxor::math::Matrix4_obj::__new(this->m00,this->m10,this->m20,this->m30,this->m01,this->m11,this->m21,this->m31,this->m02,this->m12,this->m22,this->m32,this->m03,this->m13,this->m23,this->m33);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,get_transposed,return )

Array< Float > Matrix4_obj::ToRowMajor( ){
	HX_STACK_FRAME("haxor.math.Matrix4","ToRowMajor",0xa1a6580f,"haxor.math.Matrix4.ToRowMajor","haxor/math/Matrix4.hx",389,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(389)
	return Array_obj< Float >::__new().Add(this->m00).Add(this->m01).Add(this->m02).Add(this->m03).Add(this->m10).Add(this->m11).Add(this->m12).Add(this->m13).Add(this->m20).Add(this->m21).Add(this->m22).Add(this->m23).Add(this->m30).Add(this->m31).Add(this->m32).Add(this->m33);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,ToRowMajor,return )

Array< Float > Matrix4_obj::ToColumnMajor( ){
	HX_STACK_FRAME("haxor.math.Matrix4","ToColumnMajor",0xdf285d33,"haxor.math.Matrix4.ToColumnMajor","haxor/math/Matrix4.hx",394,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(394)
	return Array_obj< Float >::__new().Add(this->m00).Add(this->m10).Add(this->m20).Add(this->m30).Add(this->m01).Add(this->m11).Add(this->m21).Add(this->m31).Add(this->m02).Add(this->m12).Add(this->m22).Add(this->m32).Add(this->m03).Add(this->m13).Add(this->m23).Add(this->m33);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,ToColumnMajor,return )

::haxor::math::Vector4 Matrix4_obj::GetLine( int p_index,::haxor::math::Vector4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","GetLine",0x4e605dd5,"haxor.math.Matrix4.GetLine","haxor/math/Matrix4.hx",449,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(450)
	::haxor::math::Vector4 _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(450)
	if (((p_result == null()))){
		HX_STACK_LINE(450)
		_g = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(450)
		_g = p_result;
	}
	HX_STACK_LINE(450)
	p_result = _g;
	HX_STACK_LINE(451)
	Float _g1 = this->GetRowCol(p_index,(int)0);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(451)
	Float _g2 = this->GetRowCol(p_index,(int)1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(451)
	Float _g3 = this->GetRowCol(p_index,(int)2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(451)
	Float _g4 = this->GetRowCol(p_index,(int)3);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(451)
	return p_result->Set(_g1,_g2,_g3,_g4);
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix4_obj,GetLine,return )

Void Matrix4_obj::SetLine( int p_index,Float p_x,Float p_y,Float p_z,Float p_w){
{
		HX_STACK_FRAME("haxor.math.Matrix4","SetLine",0x4161eee1,"haxor.math.Matrix4.SetLine","haxor/math/Matrix4.hx",465,0xc9a22505)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_index,"p_index")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(465)
		switch( (int)(p_index)){
			case (int)0: {
				HX_STACK_LINE(467)
				this->m00 = p_x;
				HX_STACK_LINE(467)
				this->m01 = p_y;
				HX_STACK_LINE(467)
				this->m02 = p_z;
				HX_STACK_LINE(467)
				this->m03 = p_w;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(468)
				this->m10 = p_x;
				HX_STACK_LINE(468)
				this->m11 = p_y;
				HX_STACK_LINE(468)
				this->m12 = p_z;
				HX_STACK_LINE(468)
				this->m13 = p_w;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(469)
				this->m20 = p_x;
				HX_STACK_LINE(469)
				this->m21 = p_y;
				HX_STACK_LINE(469)
				this->m22 = p_z;
				HX_STACK_LINE(469)
				this->m23 = p_w;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(470)
				this->m30 = p_x;
				HX_STACK_LINE(470)
				this->m31 = p_y;
				HX_STACK_LINE(470)
				this->m32 = p_z;
				HX_STACK_LINE(470)
				this->m33 = p_w;
			}
			;break;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Matrix4_obj,SetLine,(void))

::haxor::math::Vector4 Matrix4_obj::GetColumn( int p_index,::haxor::math::Vector4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","GetColumn",0xc77e8ef7,"haxor.math.Matrix4.GetColumn","haxor/math/Matrix4.hx",480,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(481)
	::haxor::math::Vector4 _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(481)
	if (((p_result == null()))){
		HX_STACK_LINE(481)
		_g = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(481)
		_g = p_result;
	}
	HX_STACK_LINE(481)
	p_result = _g;
	HX_STACK_LINE(482)
	Float _g1 = this->GetRowCol((int)0,p_index);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(482)
	Float _g2 = this->GetRowCol((int)1,p_index);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(482)
	Float _g3 = this->GetRowCol((int)2,p_index);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(482)
	Float _g4 = this->GetRowCol((int)3,p_index);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(482)
	return p_result->Set(_g1,_g2,_g3,_g4);
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix4_obj,GetColumn,return )

Void Matrix4_obj::SetColumn( int p_index,Float p_x,Float p_y,Float p_z,Float p_w){
{
		HX_STACK_FRAME("haxor.math.Matrix4","SetColumn",0xaacf7b03,"haxor.math.Matrix4.SetColumn","haxor/math/Matrix4.hx",496,0xc9a22505)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_index,"p_index")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(496)
		switch( (int)(p_index)){
			case (int)0: {
				HX_STACK_LINE(498)
				this->m00 = p_x;
				HX_STACK_LINE(498)
				this->m10 = p_y;
				HX_STACK_LINE(498)
				this->m20 = p_z;
				HX_STACK_LINE(498)
				this->m30 = p_w;
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(499)
				this->m01 = p_x;
				HX_STACK_LINE(499)
				this->m11 = p_y;
				HX_STACK_LINE(499)
				this->m21 = p_z;
				HX_STACK_LINE(499)
				this->m31 = p_w;
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(500)
				this->m02 = p_x;
				HX_STACK_LINE(500)
				this->m12 = p_y;
				HX_STACK_LINE(500)
				this->m22 = p_z;
				HX_STACK_LINE(500)
				this->m32 = p_w;
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(501)
				this->m03 = p_x;
				HX_STACK_LINE(501)
				this->m13 = p_y;
				HX_STACK_LINE(501)
				this->m23 = p_z;
				HX_STACK_LINE(501)
				this->m33 = p_w;
			}
			;break;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Matrix4_obj,SetColumn,(void))

::haxor::math::Vector4 Matrix4_obj::get_diagonalLR( ){
	HX_STACK_FRAME("haxor.math.Matrix4","get_diagonalLR",0xfc88f819,"haxor.math.Matrix4.get_diagonalLR","haxor/math/Matrix4.hx",509,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(509)
	return ::haxor::math::Vector4_obj::__new(this->m00,this->m11,this->m22,this->m33);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,get_diagonalLR,return )

::haxor::math::Vector4 Matrix4_obj::set_diagonalLR( ::haxor::math::Vector4 v){
	HX_STACK_FRAME("haxor.math.Matrix4","set_diagonalLR",0x1ca8e08d,"haxor.math.Matrix4.set_diagonalLR","haxor/math/Matrix4.hx",510,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(510)
	this->m00 = v->x;
	HX_STACK_LINE(510)
	this->m11 = v->y;
	HX_STACK_LINE(510)
	this->m22 = v->z;
	HX_STACK_LINE(510)
	this->m33 = v->w;
	HX_STACK_LINE(510)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,set_diagonalLR,return )

::haxor::math::Matrix4 Matrix4_obj::SetIdentity( ){
	HX_STACK_FRAME("haxor.math.Matrix4","SetIdentity",0x57f896ab,"haxor.math.Matrix4.SetIdentity","haxor/math/Matrix4.hx",516,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(516)
	return this->Set((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,SetIdentity,return )

::haxor::math::Matrix4 Matrix4_obj::Set( hx::Null< Float >  __o_p_m00,hx::Null< Float >  __o_p_m01,hx::Null< Float >  __o_p_m02,hx::Null< Float >  __o_p_m03,hx::Null< Float >  __o_p_m10,hx::Null< Float >  __o_p_m11,hx::Null< Float >  __o_p_m12,hx::Null< Float >  __o_p_m13,hx::Null< Float >  __o_p_m20,hx::Null< Float >  __o_p_m21,hx::Null< Float >  __o_p_m22,hx::Null< Float >  __o_p_m23,hx::Null< Float >  __o_p_m30,hx::Null< Float >  __o_p_m31,hx::Null< Float >  __o_p_m32,hx::Null< Float >  __o_p_m33){
Float p_m00 = __o_p_m00.Default(0);
Float p_m01 = __o_p_m01.Default(0);
Float p_m02 = __o_p_m02.Default(0);
Float p_m03 = __o_p_m03.Default(0);
Float p_m10 = __o_p_m10.Default(0);
Float p_m11 = __o_p_m11.Default(0);
Float p_m12 = __o_p_m12.Default(0);
Float p_m13 = __o_p_m13.Default(0);
Float p_m20 = __o_p_m20.Default(0);
Float p_m21 = __o_p_m21.Default(0);
Float p_m22 = __o_p_m22.Default(0);
Float p_m23 = __o_p_m23.Default(0);
Float p_m30 = __o_p_m30.Default(0);
Float p_m31 = __o_p_m31.Default(0);
Float p_m32 = __o_p_m32.Default(0);
Float p_m33 = __o_p_m33.Default(0);
	HX_STACK_FRAME("haxor.math.Matrix4","Set",0xdf7b004d,"haxor.math.Matrix4.Set","haxor/math/Matrix4.hx",541,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_m00,"p_m00")
	HX_STACK_ARG(p_m01,"p_m01")
	HX_STACK_ARG(p_m02,"p_m02")
	HX_STACK_ARG(p_m03,"p_m03")
	HX_STACK_ARG(p_m10,"p_m10")
	HX_STACK_ARG(p_m11,"p_m11")
	HX_STACK_ARG(p_m12,"p_m12")
	HX_STACK_ARG(p_m13,"p_m13")
	HX_STACK_ARG(p_m20,"p_m20")
	HX_STACK_ARG(p_m21,"p_m21")
	HX_STACK_ARG(p_m22,"p_m22")
	HX_STACK_ARG(p_m23,"p_m23")
	HX_STACK_ARG(p_m30,"p_m30")
	HX_STACK_ARG(p_m31,"p_m31")
	HX_STACK_ARG(p_m32,"p_m32")
	HX_STACK_ARG(p_m33,"p_m33")
{
		HX_STACK_LINE(542)
		this->m00 = p_m00;
		HX_STACK_LINE(542)
		this->m01 = p_m01;
		HX_STACK_LINE(542)
		this->m02 = p_m02;
		HX_STACK_LINE(542)
		this->m03 = p_m03;
		HX_STACK_LINE(543)
		this->m10 = p_m10;
		HX_STACK_LINE(543)
		this->m11 = p_m11;
		HX_STACK_LINE(543)
		this->m12 = p_m12;
		HX_STACK_LINE(543)
		this->m13 = p_m13;
		HX_STACK_LINE(544)
		this->m20 = p_m20;
		HX_STACK_LINE(544)
		this->m21 = p_m21;
		HX_STACK_LINE(544)
		this->m22 = p_m22;
		HX_STACK_LINE(544)
		this->m23 = p_m23;
		HX_STACK_LINE(545)
		this->m30 = p_m30;
		HX_STACK_LINE(545)
		this->m31 = p_m31;
		HX_STACK_LINE(545)
		this->m32 = p_m32;
		HX_STACK_LINE(545)
		this->m33 = p_m33;
		HX_STACK_LINE(546)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC16(Matrix4_obj,Set,return )

::haxor::math::Matrix4 Matrix4_obj::SetMatrix4( ::haxor::math::Matrix4 p_matrix){
	HX_STACK_FRAME("haxor.math.Matrix4","SetMatrix4",0x6ac9be06,"haxor.math.Matrix4.SetMatrix4","haxor/math/Matrix4.hx",555,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_matrix,"p_matrix")
	HX_STACK_LINE(556)
	this->m00 = p_matrix->m00;
	HX_STACK_LINE(556)
	this->m01 = p_matrix->m01;
	HX_STACK_LINE(556)
	this->m02 = p_matrix->m02;
	HX_STACK_LINE(556)
	this->m03 = p_matrix->m03;
	HX_STACK_LINE(557)
	this->m10 = p_matrix->m10;
	HX_STACK_LINE(557)
	this->m11 = p_matrix->m11;
	HX_STACK_LINE(557)
	this->m12 = p_matrix->m12;
	HX_STACK_LINE(557)
	this->m13 = p_matrix->m13;
	HX_STACK_LINE(558)
	this->m20 = p_matrix->m20;
	HX_STACK_LINE(558)
	this->m21 = p_matrix->m21;
	HX_STACK_LINE(558)
	this->m22 = p_matrix->m22;
	HX_STACK_LINE(558)
	this->m23 = p_matrix->m23;
	HX_STACK_LINE(559)
	this->m30 = p_matrix->m30;
	HX_STACK_LINE(559)
	this->m31 = p_matrix->m31;
	HX_STACK_LINE(559)
	this->m32 = p_matrix->m32;
	HX_STACK_LINE(559)
	this->m33 = p_matrix->m33;
	HX_STACK_LINE(560)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,SetMatrix4,return )

Float Matrix4_obj::GetIndex( int p_index){
	HX_STACK_FRAME("haxor.math.Matrix4","GetIndex",0x8f047a11,"haxor.math.Matrix4.GetIndex","haxor/math/Matrix4.hx",569,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_LINE(570)
	switch( (int)(p_index)){
		case (int)0: {
			HX_STACK_LINE(572)
			return this->m00;
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(573)
			return this->m01;
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(574)
			return this->m02;
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(575)
			return this->m03;
		}
		;break;
		case (int)4: {
			HX_STACK_LINE(576)
			return this->m10;
		}
		;break;
		case (int)5: {
			HX_STACK_LINE(577)
			return this->m11;
		}
		;break;
		case (int)6: {
			HX_STACK_LINE(578)
			return this->m12;
		}
		;break;
		case (int)7: {
			HX_STACK_LINE(579)
			return this->m13;
		}
		;break;
		case (int)8: {
			HX_STACK_LINE(580)
			return this->m20;
		}
		;break;
		case (int)9: {
			HX_STACK_LINE(581)
			return this->m21;
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(582)
			return this->m22;
		}
		;break;
		case (int)11: {
			HX_STACK_LINE(583)
			return this->m23;
		}
		;break;
		case (int)12: {
			HX_STACK_LINE(584)
			return this->m30;
		}
		;break;
		case (int)13: {
			HX_STACK_LINE(585)
			return this->m31;
		}
		;break;
		case (int)14: {
			HX_STACK_LINE(586)
			return this->m32;
		}
		;break;
		case (int)15: {
			HX_STACK_LINE(587)
			return this->m33;
		}
		;break;
	}
	HX_STACK_LINE(589)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,GetIndex,return )

::haxor::math::Matrix4 Matrix4_obj::SetIndex( int p_index,Float p_value){
	HX_STACK_FRAME("haxor.math.Matrix4","SetIndex",0x3d61d385,"haxor.math.Matrix4.SetIndex","haxor/math/Matrix4.hx",598,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_index,"p_index")
	HX_STACK_ARG(p_value,"p_value")
	HX_STACK_LINE(599)
	switch( (int)(p_index)){
		case (int)0: {
			HX_STACK_LINE(601)
			this->m00 = p_value;
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(602)
			this->m01 = p_value;
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(603)
			this->m02 = p_value;
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(604)
			this->m03 = p_value;
		}
		;break;
		case (int)4: {
			HX_STACK_LINE(605)
			this->m10 = p_value;
		}
		;break;
		case (int)5: {
			HX_STACK_LINE(606)
			this->m11 = p_value;
		}
		;break;
		case (int)6: {
			HX_STACK_LINE(607)
			this->m12 = p_value;
		}
		;break;
		case (int)7: {
			HX_STACK_LINE(608)
			this->m13 = p_value;
		}
		;break;
		case (int)8: {
			HX_STACK_LINE(609)
			this->m20 = p_value;
		}
		;break;
		case (int)9: {
			HX_STACK_LINE(610)
			this->m21 = p_value;
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(611)
			this->m22 = p_value;
		}
		;break;
		case (int)11: {
			HX_STACK_LINE(612)
			this->m23 = p_value;
		}
		;break;
		case (int)12: {
			HX_STACK_LINE(613)
			this->m30 = p_value;
		}
		;break;
		case (int)13: {
			HX_STACK_LINE(614)
			this->m31 = p_value;
		}
		;break;
		case (int)14: {
			HX_STACK_LINE(615)
			this->m32 = p_value;
		}
		;break;
		case (int)15: {
			HX_STACK_LINE(616)
			this->m33 = p_value;
		}
		;break;
	}
	HX_STACK_LINE(618)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix4_obj,SetIndex,return )

::haxor::math::Matrix4 Matrix4_obj::SetRowCol( int p_row,int p_col,Float p_value){
	HX_STACK_FRAME("haxor.math.Matrix4","SetRowCol",0xb1494e73,"haxor.math.Matrix4.SetRowCol","haxor/math/Matrix4.hx",627,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_row,"p_row")
	HX_STACK_ARG(p_col,"p_col")
	HX_STACK_ARG(p_value,"p_value")
	HX_STACK_LINE(627)
	return this->SetIndex((p_col + ((int(p_row) << int((int)2)))),p_value);
}


HX_DEFINE_DYNAMIC_FUNC3(Matrix4_obj,SetRowCol,return )

Float Matrix4_obj::GetRowCol( int p_row,int p_col){
	HX_STACK_FRAME("haxor.math.Matrix4","GetRowCol",0xcdf86267,"haxor.math.Matrix4.GetRowCol","haxor/math/Matrix4.hx",635,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_row,"p_row")
	HX_STACK_ARG(p_col,"p_col")
	HX_STACK_LINE(635)
	return this->GetIndex((p_col + ((int(p_row) << int((int)2)))));
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix4_obj,GetRowCol,return )

::haxor::math::Matrix4 Matrix4_obj::SwapCol( int p_a,int p_b){
	HX_STACK_FRAME("haxor.math.Matrix4","SwapCol",0x9ae04198,"haxor.math.Matrix4.SwapCol","haxor/math/Matrix4.hx",644,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_LINE(645)
	Float a0 = this->GetRowCol((int)0,p_a);		HX_STACK_VAR(a0,"a0");
	HX_STACK_LINE(646)
	Float a1 = this->GetRowCol((int)1,p_a);		HX_STACK_VAR(a1,"a1");
	HX_STACK_LINE(647)
	Float a2 = this->GetRowCol((int)2,p_a);		HX_STACK_VAR(a2,"a2");
	HX_STACK_LINE(648)
	Float a3 = this->GetRowCol((int)3,p_a);		HX_STACK_VAR(a3,"a3");
	HX_STACK_LINE(649)
	Float _g = this->GetRowCol((int)0,p_b);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(649)
	this->SetRowCol((int)0,p_a,_g);
	HX_STACK_LINE(650)
	Float _g1 = this->GetRowCol((int)1,p_b);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(650)
	this->SetRowCol((int)1,p_a,_g1);
	HX_STACK_LINE(651)
	Float _g2 = this->GetRowCol((int)2,p_b);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(651)
	this->SetRowCol((int)2,p_a,_g2);
	HX_STACK_LINE(652)
	Float _g3 = this->GetRowCol((int)3,p_b);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(652)
	this->SetRowCol((int)3,p_a,_g3);
	HX_STACK_LINE(653)
	this->SetRowCol((int)0,p_b,a0);
	HX_STACK_LINE(654)
	this->SetRowCol((int)1,p_b,a1);
	HX_STACK_LINE(655)
	this->SetRowCol((int)2,p_b,a2);
	HX_STACK_LINE(656)
	this->SetRowCol((int)3,p_b,a3);
	HX_STACK_LINE(657)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix4_obj,SwapCol,return )

::haxor::math::Matrix4 Matrix4_obj::SwapRow( int p_a,int p_b){
	HX_STACK_FRAME("haxor.math.Matrix4","SwapRow",0x9aeba372,"haxor.math.Matrix4.SwapRow","haxor/math/Matrix4.hx",667,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_LINE(668)
	Float a0 = this->GetRowCol(p_a,(int)0);		HX_STACK_VAR(a0,"a0");
	HX_STACK_LINE(669)
	Float a1 = this->GetRowCol(p_a,(int)1);		HX_STACK_VAR(a1,"a1");
	HX_STACK_LINE(670)
	Float a2 = this->GetRowCol(p_a,(int)2);		HX_STACK_VAR(a2,"a2");
	HX_STACK_LINE(671)
	Float a3 = this->GetRowCol(p_a,(int)3);		HX_STACK_VAR(a3,"a3");
	HX_STACK_LINE(672)
	Float _g = this->GetRowCol(p_b,(int)0);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(672)
	this->SetRowCol(p_a,(int)0,_g);
	HX_STACK_LINE(673)
	Float _g1 = this->GetRowCol(p_b,(int)1);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(673)
	this->SetRowCol(p_a,(int)1,_g1);
	HX_STACK_LINE(674)
	Float _g2 = this->GetRowCol(p_b,(int)2);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(674)
	this->SetRowCol(p_a,(int)2,_g2);
	HX_STACK_LINE(675)
	Float _g3 = this->GetRowCol(p_b,(int)3);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(675)
	this->SetRowCol(p_a,(int)3,_g3);
	HX_STACK_LINE(676)
	this->SetRowCol(p_b,(int)0,a0);
	HX_STACK_LINE(677)
	this->SetRowCol(p_b,(int)1,a1);
	HX_STACK_LINE(678)
	this->SetRowCol(p_b,(int)2,a2);
	HX_STACK_LINE(679)
	this->SetRowCol(p_b,(int)3,a3);
	HX_STACK_LINE(680)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix4_obj,SwapRow,return )

::haxor::math::Matrix4 Matrix4_obj::Transpose( ){
	HX_STACK_FRAME("haxor.math.Matrix4","Transpose",0xd0cc0764,"haxor.math.Matrix4.Transpose","haxor/math/Matrix4.hx",688,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(689)
	Float t00 = this->m00;		HX_STACK_VAR(t00,"t00");
	HX_STACK_LINE(689)
	Float t01 = this->m01;		HX_STACK_VAR(t01,"t01");
	HX_STACK_LINE(689)
	Float t02 = this->m02;		HX_STACK_VAR(t02,"t02");
	HX_STACK_LINE(689)
	Float t03 = this->m03;		HX_STACK_VAR(t03,"t03");
	HX_STACK_LINE(690)
	Float t10 = this->m10;		HX_STACK_VAR(t10,"t10");
	HX_STACK_LINE(690)
	Float t11 = this->m11;		HX_STACK_VAR(t11,"t11");
	HX_STACK_LINE(690)
	Float t12 = this->m12;		HX_STACK_VAR(t12,"t12");
	HX_STACK_LINE(690)
	Float t13 = this->m13;		HX_STACK_VAR(t13,"t13");
	HX_STACK_LINE(691)
	Float t20 = this->m20;		HX_STACK_VAR(t20,"t20");
	HX_STACK_LINE(691)
	Float t21 = this->m21;		HX_STACK_VAR(t21,"t21");
	HX_STACK_LINE(691)
	Float t22 = this->m22;		HX_STACK_VAR(t22,"t22");
	HX_STACK_LINE(691)
	Float t23 = this->m23;		HX_STACK_VAR(t23,"t23");
	HX_STACK_LINE(692)
	Float t30 = this->m30;		HX_STACK_VAR(t30,"t30");
	HX_STACK_LINE(692)
	Float t31 = this->m31;		HX_STACK_VAR(t31,"t31");
	HX_STACK_LINE(692)
	Float t32 = this->m32;		HX_STACK_VAR(t32,"t32");
	HX_STACK_LINE(692)
	Float t33 = this->m33;		HX_STACK_VAR(t33,"t33");
	HX_STACK_LINE(693)
	return this->Set(t00,t10,t20,t30,t01,t11,t21,t31,t02,t12,t22,t32,t03,t13,t23,t33);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,Transpose,return )

::haxor::math::Matrix4 Matrix4_obj::ToRotation( ){
	HX_STACK_FRAME("haxor.math.Matrix4","ToRotation",0xff26288e,"haxor.math.Matrix4.ToRotation","haxor/math/Matrix4.hx",701,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(702)
	::haxor::math::Vector3 tmp;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(702)
	{
		HX_STACK_LINE(702)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(702)
		int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(702)
		tmp = _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
	}
	HX_STACK_LINE(703)
	tmp->Set(this->m00,this->m01,this->m02)->Normalize();
	HX_STACK_LINE(703)
	this->m00 = tmp->x;
	HX_STACK_LINE(703)
	this->m01 = tmp->y;
	HX_STACK_LINE(703)
	this->m02 = tmp->z;
	HX_STACK_LINE(703)
	this->m03 = 0.0;
	HX_STACK_LINE(704)
	tmp->Set(this->m10,this->m11,this->m12)->Normalize();
	HX_STACK_LINE(704)
	this->m10 = tmp->x;
	HX_STACK_LINE(704)
	this->m11 = tmp->y;
	HX_STACK_LINE(704)
	this->m12 = tmp->z;
	HX_STACK_LINE(704)
	this->m13 = 0.0;
	HX_STACK_LINE(705)
	tmp->Set(this->m20,this->m21,this->m22)->Normalize();
	HX_STACK_LINE(705)
	this->m20 = tmp->x;
	HX_STACK_LINE(705)
	this->m21 = tmp->y;
	HX_STACK_LINE(705)
	this->m22 = tmp->z;
	HX_STACK_LINE(705)
	this->m23 = 0.0;
	HX_STACK_LINE(706)
	Float _g1 = this->m32 = 0.0;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(706)
	Float _g2 = this->m31 = _g1;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(706)
	this->m30 = _g2;
	HX_STACK_LINE(706)
	this->m33 = 1.0;
	HX_STACK_LINE(707)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,ToRotation,return )

::haxor::math::Vector3 Matrix4_obj::Rotate( ::haxor::math::Vector3 p_vector){
	HX_STACK_FRAME("haxor.math.Matrix4","Rotate",0x4e3ade90,"haxor.math.Matrix4.Rotate","haxor/math/Matrix4.hx",716,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_vector,"p_vector")
	HX_STACK_LINE(717)
	::haxor::math::Vector3 tmp;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(717)
	{
		HX_STACK_LINE(717)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(717)
		int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(717)
		tmp = _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
	}
	HX_STACK_LINE(718)
	tmp->Set(this->m00,this->m01,this->m02)->Normalize();
	HX_STACK_LINE(719)
	p_vector->x = (((tmp->x * p_vector->x) + (tmp->y * p_vector->y)) + (tmp->z * p_vector->z));
	HX_STACK_LINE(720)
	tmp->Set(this->m10,this->m11,this->m12)->Normalize();
	HX_STACK_LINE(721)
	p_vector->y = (((tmp->x * p_vector->x) + (tmp->y * p_vector->y)) + (tmp->z * p_vector->z));
	HX_STACK_LINE(722)
	tmp->Set(this->m20,this->m21,this->m22)->Normalize();
	HX_STACK_LINE(723)
	p_vector->z = (((tmp->x * p_vector->x) + (tmp->y * p_vector->y)) + (tmp->z * p_vector->z));
	HX_STACK_LINE(724)
	return p_vector;
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,Rotate,return )

::haxor::math::Matrix4 Matrix4_obj::SetTRS( ::haxor::math::Vector3 p_position,::haxor::math::Quaternion p_rotation,::haxor::math::Vector3 p_scale){
	HX_STACK_FRAME("haxor.math.Matrix4","SetTRS",0xf28a72e8,"haxor.math.Matrix4.SetTRS","haxor/math/Matrix4.hx",734,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_position,"p_position")
	HX_STACK_ARG(p_rotation,"p_rotation")
	HX_STACK_ARG(p_scale,"p_scale")
	HX_STACK_LINE(734)
	Float sx;		HX_STACK_VAR(sx,"sx");
	HX_STACK_LINE(734)
	if (((p_scale == null()))){
		HX_STACK_LINE(734)
		sx = 1.0;
	}
	else{
		HX_STACK_LINE(734)
		sx = p_scale->x;
	}
	HX_STACK_LINE(734)
	Float sy;		HX_STACK_VAR(sy,"sy");
	HX_STACK_LINE(734)
	if (((p_scale == null()))){
		HX_STACK_LINE(734)
		sy = 1.0;
	}
	else{
		HX_STACK_LINE(734)
		sy = p_scale->y;
	}
	HX_STACK_LINE(734)
	Float sz;		HX_STACK_VAR(sz,"sz");
	HX_STACK_LINE(734)
	if (((p_scale == null()))){
		HX_STACK_LINE(734)
		sz = 1.0;
	}
	else{
		HX_STACK_LINE(734)
		sz = p_scale->z;
	}
	HX_STACK_LINE(734)
	Float px = p_position->x;		HX_STACK_VAR(px,"px");
	HX_STACK_LINE(734)
	Float py = p_position->y;		HX_STACK_VAR(py,"py");
	HX_STACK_LINE(734)
	Float pz = p_position->z;		HX_STACK_VAR(pz,"pz");
	HX_STACK_LINE(734)
	::haxor::math::Matrix4 r;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(734)
	{
		HX_STACK_LINE(734)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(734)
		int _g = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(734)
		r = _this->m_m4->__get(_g).StaticCast< ::haxor::math::Matrix4 >();
	}
	HX_STACK_LINE(734)
	::haxor::math::Matrix4_obj::FromQuaternion(p_rotation,r);
	HX_STACK_LINE(734)
	::haxor::math::Matrix4 l = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(734)
	l->m00 = (r->m00 * sx);
	HX_STACK_LINE(734)
	l->m01 = (r->m01 * sy);
	HX_STACK_LINE(734)
	l->m02 = (r->m02 * sz);
	HX_STACK_LINE(734)
	l->m03 = px;
	HX_STACK_LINE(734)
	l->m10 = (r->m10 * sx);
	HX_STACK_LINE(734)
	l->m11 = (r->m11 * sy);
	HX_STACK_LINE(734)
	l->m12 = (r->m12 * sz);
	HX_STACK_LINE(734)
	l->m13 = py;
	HX_STACK_LINE(734)
	l->m20 = (r->m20 * sx);
	HX_STACK_LINE(734)
	l->m21 = (r->m21 * sy);
	HX_STACK_LINE(734)
	l->m22 = (r->m22 * sz);
	HX_STACK_LINE(734)
	l->m23 = pz;
	HX_STACK_LINE(734)
	Float _g1 = l->m32 = 0.0;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(734)
	Float _g2 = l->m31 = _g1;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(734)
	l->m30 = _g2;
	HX_STACK_LINE(734)
	l->m33 = 1.0;
	HX_STACK_LINE(734)
	return l;
}


HX_DEFINE_DYNAMIC_FUNC3(Matrix4_obj,SetTRS,return )

::haxor::math::Matrix4 Matrix4_obj::MultiplyTransform( ::haxor::math::Matrix4 p_matrix){
	HX_STACK_FRAME("haxor.math.Matrix4","MultiplyTransform",0x2883e093,"haxor.math.Matrix4.MultiplyTransform","haxor/math/Matrix4.hx",742,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_matrix,"p_matrix")
	HX_STACK_LINE(743)
	Float r00 = (((this->m00 * p_matrix->m00) + (this->m01 * p_matrix->m10)) + (this->m02 * p_matrix->m20));		HX_STACK_VAR(r00,"r00");
	HX_STACK_LINE(744)
	Float r01 = (((this->m00 * p_matrix->m01) + (this->m01 * p_matrix->m11)) + (this->m02 * p_matrix->m21));		HX_STACK_VAR(r01,"r01");
	HX_STACK_LINE(745)
	Float r02 = (((this->m00 * p_matrix->m02) + (this->m01 * p_matrix->m12)) + (this->m02 * p_matrix->m22));		HX_STACK_VAR(r02,"r02");
	HX_STACK_LINE(746)
	Float r03 = ((((this->m00 * p_matrix->m03) + (this->m01 * p_matrix->m13)) + (this->m02 * p_matrix->m23)) + this->m03);		HX_STACK_VAR(r03,"r03");
	HX_STACK_LINE(747)
	Float r10 = (((this->m10 * p_matrix->m00) + (this->m11 * p_matrix->m10)) + (this->m12 * p_matrix->m20));		HX_STACK_VAR(r10,"r10");
	HX_STACK_LINE(748)
	Float r11 = (((this->m10 * p_matrix->m01) + (this->m11 * p_matrix->m11)) + (this->m12 * p_matrix->m21));		HX_STACK_VAR(r11,"r11");
	HX_STACK_LINE(749)
	Float r12 = (((this->m10 * p_matrix->m02) + (this->m11 * p_matrix->m12)) + (this->m12 * p_matrix->m22));		HX_STACK_VAR(r12,"r12");
	HX_STACK_LINE(750)
	Float r13 = ((((this->m10 * p_matrix->m03) + (this->m11 * p_matrix->m13)) + (this->m12 * p_matrix->m23)) + this->m13);		HX_STACK_VAR(r13,"r13");
	HX_STACK_LINE(751)
	Float r20 = (((this->m20 * p_matrix->m00) + (this->m21 * p_matrix->m10)) + (this->m22 * p_matrix->m20));		HX_STACK_VAR(r20,"r20");
	HX_STACK_LINE(752)
	Float r21 = (((this->m20 * p_matrix->m01) + (this->m21 * p_matrix->m11)) + (this->m22 * p_matrix->m21));		HX_STACK_VAR(r21,"r21");
	HX_STACK_LINE(753)
	Float r22 = (((this->m20 * p_matrix->m02) + (this->m21 * p_matrix->m12)) + (this->m22 * p_matrix->m22));		HX_STACK_VAR(r22,"r22");
	HX_STACK_LINE(754)
	Float r23 = ((((this->m20 * p_matrix->m03) + (this->m21 * p_matrix->m13)) + (this->m22 * p_matrix->m23)) + this->m23);		HX_STACK_VAR(r23,"r23");
	HX_STACK_LINE(755)
	this->Set(r00,r01,r02,r03,r10,r11,r12,r13,r20,r21,r22,r23,(int)0,(int)0,(int)0,(int)1);
	HX_STACK_LINE(760)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,MultiplyTransform,return )

::haxor::math::Matrix4 Matrix4_obj::Multiply3x4( ::haxor::math::Matrix4 p_matrix){
	HX_STACK_FRAME("haxor.math.Matrix4","Multiply3x4",0x6d87afb6,"haxor.math.Matrix4.Multiply3x4","haxor/math/Matrix4.hx",769,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_matrix,"p_matrix")
	HX_STACK_LINE(770)
	Float r00 = ((((this->m00 * p_matrix->m00) + (this->m01 * p_matrix->m10)) + (this->m02 * p_matrix->m20)) + (this->m03 * p_matrix->m30));		HX_STACK_VAR(r00,"r00");
	HX_STACK_LINE(771)
	Float r01 = ((((this->m00 * p_matrix->m01) + (this->m01 * p_matrix->m11)) + (this->m02 * p_matrix->m21)) + (this->m03 * p_matrix->m31));		HX_STACK_VAR(r01,"r01");
	HX_STACK_LINE(772)
	Float r02 = ((((this->m00 * p_matrix->m02) + (this->m01 * p_matrix->m12)) + (this->m02 * p_matrix->m22)) + (this->m03 * p_matrix->m32));		HX_STACK_VAR(r02,"r02");
	HX_STACK_LINE(773)
	Float r03 = ((((this->m00 * p_matrix->m03) + (this->m01 * p_matrix->m13)) + (this->m02 * p_matrix->m23)) + (this->m03 * p_matrix->m33));		HX_STACK_VAR(r03,"r03");
	HX_STACK_LINE(774)
	Float r10 = ((((this->m10 * p_matrix->m00) + (this->m11 * p_matrix->m10)) + (this->m12 * p_matrix->m20)) + (this->m13 * p_matrix->m30));		HX_STACK_VAR(r10,"r10");
	HX_STACK_LINE(775)
	Float r11 = ((((this->m10 * p_matrix->m01) + (this->m11 * p_matrix->m11)) + (this->m12 * p_matrix->m21)) + (this->m13 * p_matrix->m31));		HX_STACK_VAR(r11,"r11");
	HX_STACK_LINE(776)
	Float r12 = ((((this->m10 * p_matrix->m02) + (this->m11 * p_matrix->m12)) + (this->m12 * p_matrix->m22)) + (this->m13 * p_matrix->m32));		HX_STACK_VAR(r12,"r12");
	HX_STACK_LINE(777)
	Float r13 = ((((this->m10 * p_matrix->m03) + (this->m11 * p_matrix->m13)) + (this->m12 * p_matrix->m23)) + (this->m13 * p_matrix->m33));		HX_STACK_VAR(r13,"r13");
	HX_STACK_LINE(778)
	Float r20 = ((((this->m20 * p_matrix->m00) + (this->m21 * p_matrix->m10)) + (this->m22 * p_matrix->m20)) + (this->m23 * p_matrix->m30));		HX_STACK_VAR(r20,"r20");
	HX_STACK_LINE(779)
	Float r21 = ((((this->m20 * p_matrix->m01) + (this->m21 * p_matrix->m11)) + (this->m22 * p_matrix->m21)) + (this->m23 * p_matrix->m31));		HX_STACK_VAR(r21,"r21");
	HX_STACK_LINE(780)
	Float r22 = ((((this->m20 * p_matrix->m02) + (this->m21 * p_matrix->m12)) + (this->m22 * p_matrix->m22)) + (this->m23 * p_matrix->m32));		HX_STACK_VAR(r22,"r22");
	HX_STACK_LINE(781)
	Float r23 = ((((this->m20 * p_matrix->m03) + (this->m21 * p_matrix->m13)) + (this->m22 * p_matrix->m23)) + (this->m23 * p_matrix->m33));		HX_STACK_VAR(r23,"r23");
	HX_STACK_LINE(782)
	this->Set(r00,r01,r02,r03,r10,r11,r12,r13,r20,r21,r22,r23,this->m30,this->m31,this->m32,this->m33);
	HX_STACK_LINE(787)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,Multiply3x4,return )

::haxor::math::Matrix4 Matrix4_obj::Multiply( ::haxor::math::Matrix4 p_matrix){
	HX_STACK_FRAME("haxor.math.Matrix4","Multiply",0x0ba5b199,"haxor.math.Matrix4.Multiply","haxor/math/Matrix4.hx",796,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_matrix,"p_matrix")
	HX_STACK_LINE(797)
	Float r00 = ((((this->m00 * p_matrix->m00) + (this->m01 * p_matrix->m10)) + (this->m02 * p_matrix->m20)) + (this->m03 * p_matrix->m30));		HX_STACK_VAR(r00,"r00");
	HX_STACK_LINE(798)
	Float r01 = ((((this->m00 * p_matrix->m01) + (this->m01 * p_matrix->m11)) + (this->m02 * p_matrix->m21)) + (this->m03 * p_matrix->m31));		HX_STACK_VAR(r01,"r01");
	HX_STACK_LINE(799)
	Float r02 = ((((this->m00 * p_matrix->m02) + (this->m01 * p_matrix->m12)) + (this->m02 * p_matrix->m22)) + (this->m03 * p_matrix->m32));		HX_STACK_VAR(r02,"r02");
	HX_STACK_LINE(800)
	Float r03 = ((((this->m00 * p_matrix->m03) + (this->m01 * p_matrix->m13)) + (this->m02 * p_matrix->m23)) + (this->m03 * p_matrix->m33));		HX_STACK_VAR(r03,"r03");
	HX_STACK_LINE(802)
	Float r10 = ((((this->m10 * p_matrix->m00) + (this->m11 * p_matrix->m10)) + (this->m12 * p_matrix->m20)) + (this->m13 * p_matrix->m30));		HX_STACK_VAR(r10,"r10");
	HX_STACK_LINE(803)
	Float r11 = ((((this->m10 * p_matrix->m01) + (this->m11 * p_matrix->m11)) + (this->m12 * p_matrix->m21)) + (this->m13 * p_matrix->m31));		HX_STACK_VAR(r11,"r11");
	HX_STACK_LINE(804)
	Float r12 = ((((this->m10 * p_matrix->m02) + (this->m11 * p_matrix->m12)) + (this->m12 * p_matrix->m22)) + (this->m13 * p_matrix->m32));		HX_STACK_VAR(r12,"r12");
	HX_STACK_LINE(805)
	Float r13 = ((((this->m10 * p_matrix->m03) + (this->m11 * p_matrix->m13)) + (this->m12 * p_matrix->m23)) + (this->m13 * p_matrix->m33));		HX_STACK_VAR(r13,"r13");
	HX_STACK_LINE(807)
	Float r20 = ((((this->m20 * p_matrix->m00) + (this->m21 * p_matrix->m10)) + (this->m22 * p_matrix->m20)) + (this->m23 * p_matrix->m30));		HX_STACK_VAR(r20,"r20");
	HX_STACK_LINE(808)
	Float r21 = ((((this->m20 * p_matrix->m01) + (this->m21 * p_matrix->m11)) + (this->m22 * p_matrix->m21)) + (this->m23 * p_matrix->m31));		HX_STACK_VAR(r21,"r21");
	HX_STACK_LINE(809)
	Float r22 = ((((this->m20 * p_matrix->m02) + (this->m21 * p_matrix->m12)) + (this->m22 * p_matrix->m22)) + (this->m23 * p_matrix->m32));		HX_STACK_VAR(r22,"r22");
	HX_STACK_LINE(810)
	Float r23 = ((((this->m20 * p_matrix->m03) + (this->m21 * p_matrix->m13)) + (this->m22 * p_matrix->m23)) + (this->m23 * p_matrix->m33));		HX_STACK_VAR(r23,"r23");
	HX_STACK_LINE(812)
	Float r30 = ((((this->m30 * p_matrix->m00) + (this->m31 * p_matrix->m10)) + (this->m32 * p_matrix->m20)) + (this->m33 * p_matrix->m30));		HX_STACK_VAR(r30,"r30");
	HX_STACK_LINE(813)
	Float r31 = ((((this->m30 * p_matrix->m01) + (this->m31 * p_matrix->m11)) + (this->m32 * p_matrix->m21)) + (this->m33 * p_matrix->m31));		HX_STACK_VAR(r31,"r31");
	HX_STACK_LINE(814)
	Float r32 = ((((this->m30 * p_matrix->m02) + (this->m31 * p_matrix->m12)) + (this->m32 * p_matrix->m22)) + (this->m33 * p_matrix->m32));		HX_STACK_VAR(r32,"r32");
	HX_STACK_LINE(815)
	Float r33 = ((((this->m30 * p_matrix->m03) + (this->m31 * p_matrix->m13)) + (this->m32 * p_matrix->m23)) + (this->m33 * p_matrix->m33));		HX_STACK_VAR(r33,"r33");
	HX_STACK_LINE(816)
	this->Set(r00,r01,r02,r03,r10,r11,r12,r13,r20,r21,r22,r23,r30,r31,r32,r33);
	HX_STACK_LINE(821)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,Multiply,return )

::haxor::math::Vector4 Matrix4_obj::Transform4x4( ::haxor::math::Vector4 p_point){
	HX_STACK_FRAME("haxor.math.Matrix4","Transform4x4",0x6b8009f9,"haxor.math.Matrix4.Transform4x4","haxor/math/Matrix4.hx",829,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_point,"p_point")
	HX_STACK_LINE(830)
	Float vx = ((((this->m00 * p_point->x) + (this->m01 * p_point->y)) + (this->m02 * p_point->z)) + (this->m03 * p_point->w));		HX_STACK_VAR(vx,"vx");
	HX_STACK_LINE(831)
	Float vy = ((((this->m10 * p_point->x) + (this->m11 * p_point->y)) + (this->m12 * p_point->z)) + (this->m13 * p_point->w));		HX_STACK_VAR(vy,"vy");
	HX_STACK_LINE(832)
	Float vz = ((((this->m20 * p_point->x) + (this->m21 * p_point->y)) + (this->m22 * p_point->z)) + (this->m23 * p_point->w));		HX_STACK_VAR(vz,"vz");
	HX_STACK_LINE(833)
	Float vw = ((((this->m30 * p_point->x) + (this->m31 * p_point->y)) + (this->m32 * p_point->z)) + (this->m33 * p_point->w));		HX_STACK_VAR(vw,"vw");
	HX_STACK_LINE(834)
	p_point->x = vx;
	HX_STACK_LINE(835)
	p_point->y = vy;
	HX_STACK_LINE(836)
	p_point->z = vz;
	HX_STACK_LINE(837)
	p_point->w = vw;
	HX_STACK_LINE(838)
	return p_point;
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,Transform4x4,return )

::haxor::math::Vector3 Matrix4_obj::Transform3x4( ::haxor::math::Vector3 p_point){
	HX_STACK_FRAME("haxor.math.Matrix4","Transform3x4",0x6b7f47b8,"haxor.math.Matrix4.Transform3x4","haxor/math/Matrix4.hx",846,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_point,"p_point")
	HX_STACK_LINE(847)
	Float vx = ((((this->m00 * p_point->x) + (this->m01 * p_point->y)) + (this->m02 * p_point->z)) + this->m03);		HX_STACK_VAR(vx,"vx");
	HX_STACK_LINE(848)
	Float vy = ((((this->m10 * p_point->x) + (this->m11 * p_point->y)) + (this->m12 * p_point->z)) + this->m13);		HX_STACK_VAR(vy,"vy");
	HX_STACK_LINE(849)
	Float vz = ((((this->m20 * p_point->x) + (this->m21 * p_point->y)) + (this->m22 * p_point->z)) + this->m23);		HX_STACK_VAR(vz,"vz");
	HX_STACK_LINE(850)
	p_point->x = vx;
	HX_STACK_LINE(851)
	p_point->y = vy;
	HX_STACK_LINE(852)
	p_point->z = vz;
	HX_STACK_LINE(853)
	return p_point;
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,Transform3x4,return )

::haxor::math::Vector3 Matrix4_obj::Transform3x3( ::haxor::math::Vector3 p_point){
	HX_STACK_FRAME("haxor.math.Matrix4","Transform3x3",0x6b7f47b7,"haxor.math.Matrix4.Transform3x3","haxor/math/Matrix4.hx",861,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_point,"p_point")
	HX_STACK_LINE(862)
	Float vx = (((this->m00 * p_point->x) + (this->m01 * p_point->y)) + (this->m02 * p_point->z));		HX_STACK_VAR(vx,"vx");
	HX_STACK_LINE(863)
	Float vy = (((this->m10 * p_point->x) + (this->m11 * p_point->y)) + (this->m12 * p_point->z));		HX_STACK_VAR(vy,"vy");
	HX_STACK_LINE(864)
	Float vz = (((this->m20 * p_point->x) + (this->m21 * p_point->y)) + (this->m22 * p_point->z));		HX_STACK_VAR(vz,"vz");
	HX_STACK_LINE(865)
	p_point->x = vx;
	HX_STACK_LINE(866)
	p_point->y = vy;
	HX_STACK_LINE(867)
	p_point->z = vz;
	HX_STACK_LINE(868)
	return p_point;
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,Transform3x3,return )

Void Matrix4_obj::Transform2x3( ::haxor::math::Vector2 p_point){
{
		HX_STACK_FRAME("haxor.math.Matrix4","Transform2x3",0x6b7e8576,"haxor.math.Matrix4.Transform2x3","haxor/math/Matrix4.hx",876,0xc9a22505)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_point,"p_point")
		HX_STACK_LINE(877)
		Float vx = (((this->m00 * p_point->x) + (this->m01 * p_point->y)) + this->m03);		HX_STACK_VAR(vx,"vx");
		HX_STACK_LINE(878)
		Float vy = (((this->m10 * p_point->x) + (this->m11 * p_point->y)) + this->m13);		HX_STACK_VAR(vy,"vy");
		HX_STACK_LINE(879)
		p_point->x = vx;
		HX_STACK_LINE(880)
		p_point->y = vy;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,Transform2x3,(void))

Void Matrix4_obj::Transform2x2( ::haxor::math::Vector2 p_point){
{
		HX_STACK_FRAME("haxor.math.Matrix4","Transform2x2",0x6b7e8575,"haxor.math.Matrix4.Transform2x2","haxor/math/Matrix4.hx",888,0xc9a22505)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_point,"p_point")
		HX_STACK_LINE(889)
		Float vx = ((this->m00 * p_point->x) + (this->m01 * p_point->y));		HX_STACK_VAR(vx,"vx");
		HX_STACK_LINE(890)
		Float vy = ((this->m10 * p_point->x) + (this->m11 * p_point->y));		HX_STACK_VAR(vy,"vy");
		HX_STACK_LINE(891)
		p_point->x = vx;
		HX_STACK_LINE(892)
		p_point->y = vy;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix4_obj,Transform2x2,(void))

::haxor::math::Matrix4 Matrix4_obj::SetLookAt( ::haxor::math::Vector3 p_eye,::haxor::math::Vector3 p_at,::haxor::math::Vector3 p_up){
	HX_STACK_FRAME("haxor.math.Matrix4","SetLookAt",0x45f9a15f,"haxor.math.Matrix4.SetLookAt","haxor/math/Matrix4.hx",902,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_eye,"p_eye")
	HX_STACK_ARG(p_at,"p_at")
	HX_STACK_ARG(p_up,"p_up")
	HX_STACK_LINE(902)
	return ::haxor::math::Matrix4_obj::LookAt(p_eye,p_at,p_up,hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC3(Matrix4_obj,SetLookAt,return )

::haxor::math::Matrix4 Matrix4_obj::SetFrustum( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far){
	HX_STACK_FRAME("haxor.math.Matrix4","SetFrustum",0xa7dcc295,"haxor.math.Matrix4.SetFrustum","haxor/math/Matrix4.hx",914,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_left,"p_left")
	HX_STACK_ARG(p_right,"p_right")
	HX_STACK_ARG(p_top,"p_top")
	HX_STACK_ARG(p_bottom,"p_bottom")
	HX_STACK_ARG(p_near,"p_near")
	HX_STACK_ARG(p_far,"p_far")
	HX_STACK_LINE(914)
	::haxor::math::Matrix4 m = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(914)
	Float n2 = (p_near * 2.0);		HX_STACK_VAR(n2,"n2");
	HX_STACK_LINE(914)
	Float rml = (Float(1.0) / Float(((p_right - p_left))));		HX_STACK_VAR(rml,"rml");
	HX_STACK_LINE(914)
	Float tmb = (Float(1.0) / Float(((p_top - p_bottom))));		HX_STACK_VAR(tmb,"tmb");
	HX_STACK_LINE(914)
	Float fmn = (Float(1.0) / Float(((p_far - p_near))));		HX_STACK_VAR(fmn,"fmn");
	HX_STACK_LINE(914)
	m->m00 = (n2 * rml);
	HX_STACK_LINE(914)
	m->m01 = 0.0;
	HX_STACK_LINE(914)
	m->m02 = (((p_right + p_left)) * rml);
	HX_STACK_LINE(914)
	m->m03 = 0.0;
	HX_STACK_LINE(914)
	m->m10 = 0.0;
	HX_STACK_LINE(914)
	m->m11 = (n2 * tmb);
	HX_STACK_LINE(914)
	m->m12 = (((p_top + p_bottom)) * tmb);
	HX_STACK_LINE(914)
	m->m13 = 0.0;
	HX_STACK_LINE(914)
	m->m20 = 0.0;
	HX_STACK_LINE(914)
	m->m21 = 0.0;
	HX_STACK_LINE(914)
	m->m22 = (-(((p_near + p_far))) * fmn);
	HX_STACK_LINE(914)
	m->m23 = ((-(n2) * p_far) * fmn);
	HX_STACK_LINE(914)
	m->m30 = 0.0;
	HX_STACK_LINE(914)
	m->m31 = 0.0;
	HX_STACK_LINE(914)
	m->m32 = -1.0;
	HX_STACK_LINE(914)
	m->m33 = (int)0;
	HX_STACK_LINE(914)
	return m;
}


HX_DEFINE_DYNAMIC_FUNC6(Matrix4_obj,SetFrustum,return )

::haxor::math::Matrix4 Matrix4_obj::SetFrustumInverse( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far){
	HX_STACK_FRAME("haxor.math.Matrix4","SetFrustumInverse",0xdbbe5d9b,"haxor.math.Matrix4.SetFrustumInverse","haxor/math/Matrix4.hx",926,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_left,"p_left")
	HX_STACK_ARG(p_right,"p_right")
	HX_STACK_ARG(p_top,"p_top")
	HX_STACK_ARG(p_bottom,"p_bottom")
	HX_STACK_ARG(p_near,"p_near")
	HX_STACK_ARG(p_far,"p_far")
	HX_STACK_LINE(926)
	::haxor::math::Matrix4 m = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(926)
	Float n2 = (p_near * 2.0);		HX_STACK_VAR(n2,"n2");
	HX_STACK_LINE(926)
	Float rml = (p_right - p_left);		HX_STACK_VAR(rml,"rml");
	HX_STACK_LINE(926)
	Float tmb = (p_top - p_bottom);		HX_STACK_VAR(tmb,"tmb");
	HX_STACK_LINE(926)
	Float fmn = (p_far - p_near);		HX_STACK_VAR(fmn,"fmn");
	HX_STACK_LINE(926)
	m->m00 = (Float(rml) / Float(n2));
	HX_STACK_LINE(926)
	m->m01 = 0.0;
	HX_STACK_LINE(926)
	m->m02 = 0.0;
	HX_STACK_LINE(926)
	m->m03 = (Float(((p_right + p_left))) / Float(n2));
	HX_STACK_LINE(926)
	m->m10 = 0.0;
	HX_STACK_LINE(926)
	m->m11 = (Float(tmb) / Float(n2));
	HX_STACK_LINE(926)
	m->m12 = 0.0;
	HX_STACK_LINE(926)
	m->m13 = (Float(((p_top + p_bottom))) / Float(n2));
	HX_STACK_LINE(926)
	m->m20 = 0.0;
	HX_STACK_LINE(926)
	m->m21 = 0.0;
	HX_STACK_LINE(926)
	m->m22 = 0.0;
	HX_STACK_LINE(926)
	m->m23 = -1.0;
	HX_STACK_LINE(926)
	m->m30 = 0.0;
	HX_STACK_LINE(926)
	m->m31 = 0.0;
	HX_STACK_LINE(926)
	m->m32 = (Float(fmn) / Float(((-(n2) * p_far))));
	HX_STACK_LINE(926)
	m->m33 = (Float(((p_far + p_near))) / Float(((n2 * p_far))));
	HX_STACK_LINE(926)
	return m;
}


HX_DEFINE_DYNAMIC_FUNC6(Matrix4_obj,SetFrustumInverse,return )

::haxor::math::Matrix4 Matrix4_obj::SetOrtho( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far){
	HX_STACK_FRAME("haxor.math.Matrix4","SetOrtho",0xb47a4fab,"haxor.math.Matrix4.SetOrtho","haxor/math/Matrix4.hx",938,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_left,"p_left")
	HX_STACK_ARG(p_right,"p_right")
	HX_STACK_ARG(p_top,"p_top")
	HX_STACK_ARG(p_bottom,"p_bottom")
	HX_STACK_ARG(p_near,"p_near")
	HX_STACK_ARG(p_far,"p_far")
	HX_STACK_LINE(938)
	return ::haxor::math::Matrix4_obj::Ortho(p_left,p_right,p_top,p_bottom,p_near,p_far,hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC6(Matrix4_obj,SetOrtho,return )

::haxor::math::Matrix4 Matrix4_obj::SetPerspective( Float p_fov,Float p_aspect,Float p_near,Float p_far){
	HX_STACK_FRAME("haxor.math.Matrix4","SetPerspective",0x981d762f,"haxor.math.Matrix4.SetPerspective","haxor/math/Matrix4.hx",948,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_fov,"p_fov")
	HX_STACK_ARG(p_aspect,"p_aspect")
	HX_STACK_ARG(p_near,"p_near")
	HX_STACK_ARG(p_far,"p_far")
	HX_STACK_LINE(948)
	return ::haxor::math::Matrix4_obj::Perspective(p_fov,p_aspect,p_near,p_far,hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC4(Matrix4_obj,SetPerspective,return )

::haxor::math::Matrix4 Matrix4_obj::SetPerspectiveInverse( Float p_fov,Float p_aspect,Float p_near,Float p_far){
	HX_STACK_FRAME("haxor.math.Matrix4","SetPerspectiveInverse",0x21a2b141,"haxor.math.Matrix4.SetPerspectiveInverse","haxor/math/Matrix4.hx",958,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_fov,"p_fov")
	HX_STACK_ARG(p_aspect,"p_aspect")
	HX_STACK_ARG(p_near,"p_near")
	HX_STACK_ARG(p_far,"p_far")
	HX_STACK_LINE(958)
	return ::haxor::math::Matrix4_obj::PerspectiveInverse(p_fov,p_aspect,p_near,p_far,hx::ObjectPtr<OBJ_>(this));
}


HX_DEFINE_DYNAMIC_FUNC4(Matrix4_obj,SetPerspectiveInverse,return )

Array< Float > Matrix4_obj::ToArray( ){
	HX_STACK_FRAME("haxor.math.Matrix4","ToArray",0x263e5049,"haxor.math.Matrix4.ToArray","haxor/math/Matrix4.hx",964,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_LINE(964)
	return Array_obj< Float >::__new().Add(this->m00).Add(this->m01).Add(this->m02).Add(this->m03).Add(this->m10).Add(this->m11).Add(this->m12).Add(this->m13).Add(this->m20).Add(this->m21).Add(this->m22).Add(this->m23).Add(this->m30).Add(this->m31).Add(this->m32).Add(this->m33);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,ToArray,return )

::String Matrix4_obj::ToString( hx::Null< bool >  __o_p_linear,hx::Null< int >  __o_p_places){
bool p_linear = __o_p_linear.Default(true);
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.math.Matrix4","ToString",0xa987a021,"haxor.math.Matrix4.ToString","haxor/math/Matrix4.hx",971,0xc9a22505)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_linear,"p_linear")
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(972)
		Array< Float > a = this->ToArray();		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(973)
		Array< ::String > s = Array_obj< ::String >::__new();		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(974)
		{
			HX_STACK_LINE(974)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(974)
			int _g = a->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(974)
			while((true)){
				HX_STACK_LINE(974)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(974)
					break;
				}
				HX_STACK_LINE(974)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(976)
				{
					HX_STACK_LINE(976)
					Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
					HX_STACK_LINE(976)
					Float _g2;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(976)
					{
						HX_STACK_LINE(976)
						Float p_v = (a->__get(i) * d);		HX_STACK_VAR(p_v,"p_v");
						HX_STACK_LINE(976)
						_g2 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
					}
					HX_STACK_LINE(976)
					a[i] = (Float(_g2) / Float(d));
				}
				HX_STACK_LINE(977)
				s->push((  (((a->__get(i) >= (int)0))) ? ::String((HX_CSTRING(" ") + a->__get(i))) : ::String((a->__get(i) + HX_CSTRING(""))) ));
			}
		}
		HX_STACK_LINE(979)
		::String res;		HX_STACK_VAR(res,"res");
		HX_STACK_LINE(979)
		if ((p_linear)){
			HX_STACK_LINE(979)
			res = HX_CSTRING("[");
		}
		else{
			HX_STACK_LINE(979)
			res = HX_CSTRING("");
		}
		HX_STACK_LINE(980)
		{
			HX_STACK_LINE(980)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(980)
			while((true)){
				HX_STACK_LINE(980)
				if ((!(((_g < (int)4))))){
					HX_STACK_LINE(980)
					break;
				}
				HX_STACK_LINE(980)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(982)
				{
					HX_STACK_LINE(982)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(982)
					while((true)){
						HX_STACK_LINE(982)
						if ((!(((_g1 < (int)4))))){
							HX_STACK_LINE(982)
							break;
						}
						HX_STACK_LINE(982)
						int j = (_g1)++;		HX_STACK_VAR(j,"j");
						HX_STACK_LINE(982)
						hx::AddEq(res,(s->__get((j + (i * (int)4))) + ((  (((j < (int)3))) ? ::String(HX_CSTRING(",")) : ::String(HX_CSTRING("")) ))));
					}
				}
				HX_STACK_LINE(983)
				if (((i == (int)3))){
					HX_STACK_LINE(983)
					hx::AddEq(res,HX_CSTRING(""));
				}
				else{
					HX_STACK_LINE(983)
					if ((p_linear)){
						HX_STACK_LINE(983)
						hx::AddEq(res,HX_CSTRING(" |"));
					}
					else{
						HX_STACK_LINE(983)
						hx::AddEq(res,HX_CSTRING("\n"));
					}
				}
			}
		}
		HX_STACK_LINE(986)
		if ((p_linear)){
			HX_STACK_LINE(986)
			hx::AddEq(res,HX_CSTRING("]"));
		}
		HX_STACK_LINE(987)
		return res;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix4_obj,ToString,return )

::haxor::math::Matrix4 Matrix4_obj::temp;

::haxor::math::Matrix4 Matrix4_obj::get_temp( ){
	HX_STACK_FRAME("haxor.math.Matrix4","get_temp",0x641b91f2,"haxor.math.Matrix4.get_temp","haxor/math/Matrix4.hx",15,0xc9a22505)
	HX_STACK_LINE(15)
	::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(15)
	int _g = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(15)
	return _this->m_m4->__get(_g).StaticCast< ::haxor::math::Matrix4 >();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,get_temp,return )

::haxor::math::Matrix4 Matrix4_obj::identity;

::haxor::math::Matrix4 Matrix4_obj::get_identity( ){
	HX_STACK_FRAME("haxor.math.Matrix4","get_identity",0xd344db1c,"haxor.math.Matrix4.get_identity","haxor/math/Matrix4.hx",21,0xc9a22505)
	HX_STACK_LINE(21)
	return ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Matrix4_obj,get_identity,return )

::haxor::math::Matrix4 Matrix4_obj::FromQuaternion( ::haxor::math::Quaternion p_quaternion,::haxor::math::Matrix4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","FromQuaternion",0x4363b45d,"haxor.math.Matrix4.FromQuaternion","haxor/math/Matrix4.hx",30,0xc9a22505)
	HX_STACK_ARG(p_quaternion,"p_quaternion")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(31)
	::haxor::math::Matrix4 m;		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(31)
	if (((p_result == null()))){
		HX_STACK_LINE(31)
		m = ::haxor::math::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(31)
		m = p_result;
	}
	HX_STACK_LINE(32)
	::haxor::math::Quaternion q = p_quaternion;		HX_STACK_VAR(q,"q");
	HX_STACK_LINE(33)
	Float x2 = (q->x * q->x);		HX_STACK_VAR(x2,"x2");
	HX_STACK_LINE(34)
	Float y2 = (q->y * q->y);		HX_STACK_VAR(y2,"y2");
	HX_STACK_LINE(35)
	Float z2 = (q->z * q->z);		HX_STACK_VAR(z2,"z2");
	HX_STACK_LINE(36)
	Float xy = (q->x * q->y);		HX_STACK_VAR(xy,"xy");
	HX_STACK_LINE(37)
	Float xz = (q->x * q->z);		HX_STACK_VAR(xz,"xz");
	HX_STACK_LINE(38)
	Float yz = (q->y * q->z);		HX_STACK_VAR(yz,"yz");
	HX_STACK_LINE(39)
	Float xw = (q->w * q->x);		HX_STACK_VAR(xw,"xw");
	HX_STACK_LINE(40)
	Float yw = (q->w * q->y);		HX_STACK_VAR(yw,"yw");
	HX_STACK_LINE(41)
	Float zw = (q->w * q->z);		HX_STACK_VAR(zw,"zw");
	HX_STACK_LINE(42)
	m->m00 = (1.0 - (2.0 * ((y2 + z2))));
	HX_STACK_LINE(42)
	m->m01 = (2.0 * ((xy - zw)));
	HX_STACK_LINE(42)
	m->m02 = (2.0 * ((xz + yw)));
	HX_STACK_LINE(43)
	m->m10 = (2.0 * ((xy + zw)));
	HX_STACK_LINE(43)
	m->m11 = (1.0 - (2.0 * ((x2 + z2))));
	HX_STACK_LINE(43)
	m->m12 = (2.0 * ((yz - xw)));
	HX_STACK_LINE(44)
	m->m20 = (2.0 * ((xz - yw)));
	HX_STACK_LINE(44)
	m->m21 = (2.0 * ((yz + xw)));
	HX_STACK_LINE(44)
	m->m22 = (1.0 - (2.0 * ((x2 + y2))));
	HX_STACK_LINE(45)
	Float _g = m->m32 = 0.0;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(45)
	Float _g1 = m->m31 = _g;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(45)
	m->m30 = _g1;
	HX_STACK_LINE(45)
	m->m33 = 1.0;
	HX_STACK_LINE(46)
	return m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Matrix4_obj,FromQuaternion,return )

::haxor::math::Matrix4 Matrix4_obj::FromArray( Array< Float > p_array,::haxor::math::Matrix4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","FromArray",0x5eb50eba,"haxor.math.Matrix4.FromArray","haxor/math/Matrix4.hx",54,0xc9a22505)
	HX_STACK_ARG(p_array,"p_array")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(54)
	::haxor::math::Matrix4 res;		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(54)
	if (((p_result == null()))){
		HX_STACK_LINE(54)
		res = ::haxor::math::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(54)
		res = p_result;
	}
	HX_STACK_LINE(54)
	{
		HX_STACK_LINE(54)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(54)
		int _g = p_array->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(54)
		while((true)){
			HX_STACK_LINE(54)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(54)
				break;
			}
			HX_STACK_LINE(54)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(54)
			res->SetIndex(i,p_array->__get(i));
		}
	}
	HX_STACK_LINE(54)
	return res;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Matrix4_obj,FromArray,return )

::haxor::math::Matrix4 Matrix4_obj::TRS( ::haxor::math::Vector3 p_position,::haxor::math::Quaternion p_rotation,::haxor::math::Vector3 p_scale,::haxor::math::Matrix4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","TRS",0xdf7bb1e0,"haxor.math.Matrix4.TRS","haxor/math/Matrix4.hx",64,0xc9a22505)
	HX_STACK_ARG(p_position,"p_position")
	HX_STACK_ARG(p_rotation,"p_rotation")
	HX_STACK_ARG(p_scale,"p_scale")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(65)
	Float sx;		HX_STACK_VAR(sx,"sx");
	HX_STACK_LINE(65)
	if (((p_scale == null()))){
		HX_STACK_LINE(65)
		sx = 1.0;
	}
	else{
		HX_STACK_LINE(65)
		sx = p_scale->x;
	}
	HX_STACK_LINE(66)
	Float sy;		HX_STACK_VAR(sy,"sy");
	HX_STACK_LINE(66)
	if (((p_scale == null()))){
		HX_STACK_LINE(66)
		sy = 1.0;
	}
	else{
		HX_STACK_LINE(66)
		sy = p_scale->y;
	}
	HX_STACK_LINE(67)
	Float sz;		HX_STACK_VAR(sz,"sz");
	HX_STACK_LINE(67)
	if (((p_scale == null()))){
		HX_STACK_LINE(67)
		sz = 1.0;
	}
	else{
		HX_STACK_LINE(67)
		sz = p_scale->z;
	}
	HX_STACK_LINE(68)
	Float px = p_position->x;		HX_STACK_VAR(px,"px");
	HX_STACK_LINE(69)
	Float py = p_position->y;		HX_STACK_VAR(py,"py");
	HX_STACK_LINE(70)
	Float pz = p_position->z;		HX_STACK_VAR(pz,"pz");
	HX_STACK_LINE(71)
	::haxor::math::Matrix4 r;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(71)
	{
		HX_STACK_LINE(71)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(71)
		int _g = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(71)
		r = _this->m_m4->__get(_g).StaticCast< ::haxor::math::Matrix4 >();
	}
	HX_STACK_LINE(72)
	::haxor::math::Matrix4_obj::FromQuaternion(p_rotation,r);
	HX_STACK_LINE(73)
	::haxor::math::Matrix4 l;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(73)
	if (((p_result == null()))){
		HX_STACK_LINE(73)
		l = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);
	}
	else{
		HX_STACK_LINE(73)
		l = p_result;
	}
	HX_STACK_LINE(74)
	l->m00 = (r->m00 * sx);
	HX_STACK_LINE(74)
	l->m01 = (r->m01 * sy);
	HX_STACK_LINE(74)
	l->m02 = (r->m02 * sz);
	HX_STACK_LINE(74)
	l->m03 = px;
	HX_STACK_LINE(75)
	l->m10 = (r->m10 * sx);
	HX_STACK_LINE(75)
	l->m11 = (r->m11 * sy);
	HX_STACK_LINE(75)
	l->m12 = (r->m12 * sz);
	HX_STACK_LINE(75)
	l->m13 = py;
	HX_STACK_LINE(76)
	l->m20 = (r->m20 * sx);
	HX_STACK_LINE(76)
	l->m21 = (r->m21 * sy);
	HX_STACK_LINE(76)
	l->m22 = (r->m22 * sz);
	HX_STACK_LINE(76)
	l->m23 = pz;
	HX_STACK_LINE(77)
	Float _g1 = l->m32 = 0.0;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(77)
	Float _g2 = l->m31 = _g1;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(77)
	l->m30 = _g2;
	HX_STACK_LINE(77)
	l->m33 = 1.0;
	HX_STACK_LINE(78)
	return l;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Matrix4_obj,TRS,return )

::haxor::math::Matrix4 Matrix4_obj::Frustum( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far,::haxor::math::Matrix4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","Frustum",0x04a4dd8d,"haxor.math.Matrix4.Frustum","haxor/math/Matrix4.hx",93,0xc9a22505)
	HX_STACK_ARG(p_left,"p_left")
	HX_STACK_ARG(p_right,"p_right")
	HX_STACK_ARG(p_top,"p_top")
	HX_STACK_ARG(p_bottom,"p_bottom")
	HX_STACK_ARG(p_near,"p_near")
	HX_STACK_ARG(p_far,"p_far")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(94)
	::haxor::math::Matrix4 m;		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(94)
	if (((p_result == null()))){
		HX_STACK_LINE(94)
		m = ::haxor::math::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(94)
		m = p_result;
	}
	HX_STACK_LINE(95)
	Float n2 = (p_near * 2.0);		HX_STACK_VAR(n2,"n2");
	HX_STACK_LINE(96)
	Float rml = (Float(1.0) / Float(((p_right - p_left))));		HX_STACK_VAR(rml,"rml");
	HX_STACK_LINE(97)
	Float tmb = (Float(1.0) / Float(((p_top - p_bottom))));		HX_STACK_VAR(tmb,"tmb");
	HX_STACK_LINE(98)
	Float fmn = (Float(1.0) / Float(((p_far - p_near))));		HX_STACK_VAR(fmn,"fmn");
	HX_STACK_LINE(99)
	m->m00 = (n2 * rml);
	HX_STACK_LINE(99)
	m->m01 = 0.0;
	HX_STACK_LINE(99)
	m->m02 = (((p_right + p_left)) * rml);
	HX_STACK_LINE(99)
	m->m03 = 0.0;
	HX_STACK_LINE(100)
	m->m10 = 0.0;
	HX_STACK_LINE(100)
	m->m11 = (n2 * tmb);
	HX_STACK_LINE(100)
	m->m12 = (((p_top + p_bottom)) * tmb);
	HX_STACK_LINE(100)
	m->m13 = 0.0;
	HX_STACK_LINE(101)
	m->m20 = 0.0;
	HX_STACK_LINE(101)
	m->m21 = 0.0;
	HX_STACK_LINE(101)
	m->m22 = (-(((p_near + p_far))) * fmn);
	HX_STACK_LINE(101)
	m->m23 = ((-(n2) * p_far) * fmn);
	HX_STACK_LINE(102)
	m->m30 = 0.0;
	HX_STACK_LINE(102)
	m->m31 = 0.0;
	HX_STACK_LINE(102)
	m->m32 = -1.0;
	HX_STACK_LINE(102)
	m->m33 = (int)0;
	HX_STACK_LINE(103)
	return m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(Matrix4_obj,Frustum,return )

::haxor::math::Matrix4 Matrix4_obj::FrustumInverse( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far,::haxor::math::Matrix4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","FrustumInverse",0xb06c11a3,"haxor.math.Matrix4.FrustumInverse","haxor/math/Matrix4.hx",117,0xc9a22505)
	HX_STACK_ARG(p_left,"p_left")
	HX_STACK_ARG(p_right,"p_right")
	HX_STACK_ARG(p_top,"p_top")
	HX_STACK_ARG(p_bottom,"p_bottom")
	HX_STACK_ARG(p_near,"p_near")
	HX_STACK_ARG(p_far,"p_far")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(118)
	::haxor::math::Matrix4 m;		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(118)
	if (((p_result == null()))){
		HX_STACK_LINE(118)
		m = ::haxor::math::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(118)
		m = p_result;
	}
	HX_STACK_LINE(119)
	Float n2 = (p_near * 2.0);		HX_STACK_VAR(n2,"n2");
	HX_STACK_LINE(120)
	Float rml = (p_right - p_left);		HX_STACK_VAR(rml,"rml");
	HX_STACK_LINE(121)
	Float tmb = (p_top - p_bottom);		HX_STACK_VAR(tmb,"tmb");
	HX_STACK_LINE(122)
	Float fmn = (p_far - p_near);		HX_STACK_VAR(fmn,"fmn");
	HX_STACK_LINE(123)
	m->m00 = (Float(rml) / Float(n2));
	HX_STACK_LINE(123)
	m->m01 = 0.0;
	HX_STACK_LINE(123)
	m->m02 = 0.0;
	HX_STACK_LINE(123)
	m->m03 = (Float(((p_right + p_left))) / Float(n2));
	HX_STACK_LINE(124)
	m->m10 = 0.0;
	HX_STACK_LINE(124)
	m->m11 = (Float(tmb) / Float(n2));
	HX_STACK_LINE(124)
	m->m12 = 0.0;
	HX_STACK_LINE(124)
	m->m13 = (Float(((p_top + p_bottom))) / Float(n2));
	HX_STACK_LINE(125)
	m->m20 = 0.0;
	HX_STACK_LINE(125)
	m->m21 = 0.0;
	HX_STACK_LINE(125)
	m->m22 = 0.0;
	HX_STACK_LINE(125)
	m->m23 = -1.0;
	HX_STACK_LINE(126)
	m->m30 = 0.0;
	HX_STACK_LINE(126)
	m->m31 = 0.0;
	HX_STACK_LINE(126)
	m->m32 = (Float(fmn) / Float(((-(n2) * p_far))));
	HX_STACK_LINE(126)
	m->m33 = (Float(((p_far + p_near))) / Float(((n2 * p_far))));
	HX_STACK_LINE(127)
	return m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(Matrix4_obj,FrustumInverse,return )

::haxor::math::Matrix4 Matrix4_obj::Ortho( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far,::haxor::math::Matrix4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","Ortho",0xaf733ca3,"haxor.math.Matrix4.Ortho","haxor/math/Matrix4.hx",142,0xc9a22505)
	HX_STACK_ARG(p_left,"p_left")
	HX_STACK_ARG(p_right,"p_right")
	HX_STACK_ARG(p_top,"p_top")
	HX_STACK_ARG(p_bottom,"p_bottom")
	HX_STACK_ARG(p_near,"p_near")
	HX_STACK_ARG(p_far,"p_far")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(143)
	::haxor::math::Matrix4 m;		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(143)
	if (((p_result == null()))){
		HX_STACK_LINE(143)
		m = ::haxor::math::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(143)
		m = p_result;
	}
	HX_STACK_LINE(144)
	Float n2 = (p_near * 2.0);		HX_STACK_VAR(n2,"n2");
	HX_STACK_LINE(145)
	Float rml = (Float(1.0) / Float(((p_right - p_left))));		HX_STACK_VAR(rml,"rml");
	HX_STACK_LINE(146)
	Float tmb = (Float(1.0) / Float(((p_top - p_bottom))));		HX_STACK_VAR(tmb,"tmb");
	HX_STACK_LINE(147)
	Float fmn = (Float(1.0) / Float(((p_far - p_near))));		HX_STACK_VAR(fmn,"fmn");
	HX_STACK_LINE(148)
	m->m00 = (2.0 * rml);
	HX_STACK_LINE(148)
	m->m01 = 0.0;
	HX_STACK_LINE(148)
	m->m02 = 0.0;
	HX_STACK_LINE(148)
	m->m03 = (-(((p_right + p_left))) * rml);
	HX_STACK_LINE(149)
	m->m10 = 0.0;
	HX_STACK_LINE(149)
	m->m11 = (2.0 * tmb);
	HX_STACK_LINE(149)
	m->m12 = 0.0;
	HX_STACK_LINE(149)
	m->m13 = (-(((p_top + p_bottom))) * tmb);
	HX_STACK_LINE(150)
	m->m20 = 0.0;
	HX_STACK_LINE(150)
	m->m21 = 0.0;
	HX_STACK_LINE(150)
	m->m22 = (-2. * fmn);
	HX_STACK_LINE(150)
	m->m23 = (-(((p_far + p_near))) * fmn);
	HX_STACK_LINE(151)
	m->m30 = 0.0;
	HX_STACK_LINE(151)
	m->m31 = 0.0;
	HX_STACK_LINE(151)
	m->m32 = 0.0;
	HX_STACK_LINE(151)
	m->m33 = 1.0;
	HX_STACK_LINE(152)
	return m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(Matrix4_obj,Ortho,return )

::haxor::math::Matrix4 Matrix4_obj::OrthoInverse( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far,::haxor::math::Matrix4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","OrthoInverse",0xbe0d614d,"haxor.math.Matrix4.OrthoInverse","haxor/math/Matrix4.hx",167,0xc9a22505)
	HX_STACK_ARG(p_left,"p_left")
	HX_STACK_ARG(p_right,"p_right")
	HX_STACK_ARG(p_top,"p_top")
	HX_STACK_ARG(p_bottom,"p_bottom")
	HX_STACK_ARG(p_near,"p_near")
	HX_STACK_ARG(p_far,"p_far")
	HX_STACK_ARG(p_result,"p_result")
	struct _Function_1_1{
		inline static ::haxor::math::Matrix4 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Matrix4.hx",168,0xc9a22505)
			{
				HX_STACK_LINE(168)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(168)
				int _g = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(168)
				return _this->m_m4->__get(_g).StaticCast< ::haxor::math::Matrix4 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(168)
	::haxor::math::Matrix4 m = (_Function_1_1::Block())->SetOrtho(p_left,p_right,p_top,p_bottom,p_near,p_far);		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(169)
	return ::haxor::math::Matrix4_obj::GetInverseTransform(m,p_result);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(Matrix4_obj,OrthoInverse,return )

::haxor::math::Matrix4 Matrix4_obj::Perspective( Float p_fov,Float p_aspect,Float p_near,Float p_far,::haxor::math::Matrix4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","Perspective",0x2f5a6d27,"haxor.math.Matrix4.Perspective","haxor/math/Matrix4.hx",182,0xc9a22505)
	HX_STACK_ARG(p_fov,"p_fov")
	HX_STACK_ARG(p_aspect,"p_aspect")
	HX_STACK_ARG(p_near,"p_near")
	HX_STACK_ARG(p_far,"p_far")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(183)
	Float _g = ::Math_obj::tan(((p_fov * 0.5) * 0.01745329251994329576923690768489));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(183)
	Float t = (_g * p_near);		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(184)
	Float b = -(t);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(185)
	Float l = (p_aspect * b);		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(186)
	Float r = (p_aspect * t);		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(187)
	::haxor::math::Matrix4 m;		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(187)
	if (((p_result == null()))){
		HX_STACK_LINE(187)
		m = ::haxor::math::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(187)
		m = p_result;
	}
	HX_STACK_LINE(187)
	Float n2 = (p_near * 2.0);		HX_STACK_VAR(n2,"n2");
	HX_STACK_LINE(187)
	Float rml = (Float(1.0) / Float(((r - l))));		HX_STACK_VAR(rml,"rml");
	HX_STACK_LINE(187)
	Float tmb = (Float(1.0) / Float(((t - b))));		HX_STACK_VAR(tmb,"tmb");
	HX_STACK_LINE(187)
	Float fmn = (Float(1.0) / Float(((p_far - p_near))));		HX_STACK_VAR(fmn,"fmn");
	HX_STACK_LINE(187)
	m->m00 = (n2 * rml);
	HX_STACK_LINE(187)
	m->m01 = 0.0;
	HX_STACK_LINE(187)
	m->m02 = (((r + l)) * rml);
	HX_STACK_LINE(187)
	m->m03 = 0.0;
	HX_STACK_LINE(187)
	m->m10 = 0.0;
	HX_STACK_LINE(187)
	m->m11 = (n2 * tmb);
	HX_STACK_LINE(187)
	m->m12 = (((t + b)) * tmb);
	HX_STACK_LINE(187)
	m->m13 = 0.0;
	HX_STACK_LINE(187)
	m->m20 = 0.0;
	HX_STACK_LINE(187)
	m->m21 = 0.0;
	HX_STACK_LINE(187)
	m->m22 = (-(((p_near + p_far))) * fmn);
	HX_STACK_LINE(187)
	m->m23 = ((-(n2) * p_far) * fmn);
	HX_STACK_LINE(187)
	m->m30 = 0.0;
	HX_STACK_LINE(187)
	m->m31 = 0.0;
	HX_STACK_LINE(187)
	m->m32 = -1.0;
	HX_STACK_LINE(187)
	m->m33 = (int)0;
	HX_STACK_LINE(187)
	return m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Matrix4_obj,Perspective,return )

::haxor::math::Matrix4 Matrix4_obj::PerspectiveInverse( Float p_fov,Float p_aspect,Float p_near,Float p_far,::haxor::math::Matrix4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","PerspectiveInverse",0x0c6f0949,"haxor.math.Matrix4.PerspectiveInverse","haxor/math/Matrix4.hx",199,0xc9a22505)
	HX_STACK_ARG(p_fov,"p_fov")
	HX_STACK_ARG(p_aspect,"p_aspect")
	HX_STACK_ARG(p_near,"p_near")
	HX_STACK_ARG(p_far,"p_far")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(200)
	Float _g = ::Math_obj::tan(((p_fov * 0.5) * 0.01745329251994329576923690768489));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(200)
	Float t = (_g * p_near);		HX_STACK_VAR(t,"t");
	HX_STACK_LINE(201)
	Float b = -(t);		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(202)
	Float l = (p_aspect * b);		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(203)
	Float r = (p_aspect * t);		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(204)
	::haxor::math::Matrix4 m;		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(204)
	if (((p_result == null()))){
		HX_STACK_LINE(204)
		m = ::haxor::math::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(204)
		m = p_result;
	}
	HX_STACK_LINE(204)
	Float n2 = (p_near * 2.0);		HX_STACK_VAR(n2,"n2");
	HX_STACK_LINE(204)
	Float rml = (r - l);		HX_STACK_VAR(rml,"rml");
	HX_STACK_LINE(204)
	Float tmb = (t - b);		HX_STACK_VAR(tmb,"tmb");
	HX_STACK_LINE(204)
	Float fmn = (p_far - p_near);		HX_STACK_VAR(fmn,"fmn");
	HX_STACK_LINE(204)
	m->m00 = (Float(rml) / Float(n2));
	HX_STACK_LINE(204)
	m->m01 = 0.0;
	HX_STACK_LINE(204)
	m->m02 = 0.0;
	HX_STACK_LINE(204)
	m->m03 = (Float(((r + l))) / Float(n2));
	HX_STACK_LINE(204)
	m->m10 = 0.0;
	HX_STACK_LINE(204)
	m->m11 = (Float(tmb) / Float(n2));
	HX_STACK_LINE(204)
	m->m12 = 0.0;
	HX_STACK_LINE(204)
	m->m13 = (Float(((t + b))) / Float(n2));
	HX_STACK_LINE(204)
	m->m20 = 0.0;
	HX_STACK_LINE(204)
	m->m21 = 0.0;
	HX_STACK_LINE(204)
	m->m22 = 0.0;
	HX_STACK_LINE(204)
	m->m23 = -1.0;
	HX_STACK_LINE(204)
	m->m30 = 0.0;
	HX_STACK_LINE(204)
	m->m31 = 0.0;
	HX_STACK_LINE(204)
	m->m32 = (Float(fmn) / Float(((-(n2) * p_far))));
	HX_STACK_LINE(204)
	m->m33 = (Float(((p_far + p_near))) / Float(((n2 * p_far))));
	HX_STACK_LINE(204)
	return m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Matrix4_obj,PerspectiveInverse,return )

::haxor::math::Matrix4 Matrix4_obj::GetRotation( ::haxor::math::Matrix4 p_matrix4,::haxor::math::Matrix4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","GetRotation",0x9ce2879f,"haxor.math.Matrix4.GetRotation","haxor/math/Matrix4.hx",214,0xc9a22505)
	HX_STACK_ARG(p_matrix4,"p_matrix4")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(215)
	::haxor::math::Matrix4 m;		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(215)
	if (((p_result == null()))){
		HX_STACK_LINE(215)
		m = ::haxor::math::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(215)
		m = p_result;
	}
	HX_STACK_LINE(216)
	::haxor::math::Vector3 tmp;		HX_STACK_VAR(tmp,"tmp");
	HX_STACK_LINE(216)
	{
		HX_STACK_LINE(216)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(216)
		int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(216)
		tmp = _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
	}
	HX_STACK_LINE(217)
	tmp->Set(m->m00,m->m01,m->m02)->Normalize();
	HX_STACK_LINE(217)
	m->m00 = tmp->x;
	HX_STACK_LINE(217)
	m->m01 = tmp->y;
	HX_STACK_LINE(217)
	m->m02 = tmp->z;
	HX_STACK_LINE(217)
	m->m03 = 0.0;
	HX_STACK_LINE(218)
	tmp->Set(m->m10,m->m11,m->m12)->Normalize();
	HX_STACK_LINE(218)
	m->m10 = tmp->x;
	HX_STACK_LINE(218)
	m->m11 = tmp->y;
	HX_STACK_LINE(218)
	m->m12 = tmp->z;
	HX_STACK_LINE(218)
	m->m13 = 0.0;
	HX_STACK_LINE(219)
	tmp->Set(m->m20,m->m21,m->m22)->Normalize();
	HX_STACK_LINE(219)
	m->m20 = tmp->x;
	HX_STACK_LINE(219)
	m->m21 = tmp->y;
	HX_STACK_LINE(219)
	m->m22 = tmp->z;
	HX_STACK_LINE(219)
	m->m23 = 0.0;
	HX_STACK_LINE(220)
	Float _g1 = m->m32 = 0.0;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(220)
	Float _g2 = m->m31 = _g1;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(220)
	m->m30 = _g2;
	HX_STACK_LINE(220)
	m->m33 = 1.0;
	HX_STACK_LINE(221)
	return m;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Matrix4_obj,GetRotation,return )

::haxor::math::Matrix4 Matrix4_obj::GetInverseTransform( ::haxor::math::Matrix4 p_matrix,::haxor::math::Matrix4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","GetInverseTransform",0xedd4defd,"haxor.math.Matrix4.GetInverseTransform","haxor/math/Matrix4.hx",231,0xc9a22505)
	HX_STACK_ARG(p_matrix,"p_matrix")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(232)
	::haxor::math::Matrix4 result;		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(232)
	if (((p_result == null()))){
		HX_STACK_LINE(232)
		result = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);
	}
	else{
		HX_STACK_LINE(232)
		result = p_result;
	}
	HX_STACK_LINE(233)
	::haxor::math::Matrix4 m = p_matrix;		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(235)
	Float l0x = m->m00;		HX_STACK_VAR(l0x,"l0x");
	HX_STACK_LINE(235)
	Float l0y = m->m01;		HX_STACK_VAR(l0y,"l0y");
	HX_STACK_LINE(235)
	Float l0z = m->m02;		HX_STACK_VAR(l0z,"l0z");
	HX_STACK_LINE(235)
	Float l0w = m->m03;		HX_STACK_VAR(l0w,"l0w");
	HX_STACK_LINE(236)
	Float l1x = m->m10;		HX_STACK_VAR(l1x,"l1x");
	HX_STACK_LINE(236)
	Float l1y = m->m11;		HX_STACK_VAR(l1y,"l1y");
	HX_STACK_LINE(236)
	Float l1z = m->m12;		HX_STACK_VAR(l1z,"l1z");
	HX_STACK_LINE(236)
	Float l1w = m->m13;		HX_STACK_VAR(l1w,"l1w");
	HX_STACK_LINE(237)
	Float l2x = m->m20;		HX_STACK_VAR(l2x,"l2x");
	HX_STACK_LINE(237)
	Float l2y = m->m21;		HX_STACK_VAR(l2y,"l2y");
	HX_STACK_LINE(237)
	Float l2z = m->m22;		HX_STACK_VAR(l2z,"l2z");
	HX_STACK_LINE(237)
	Float l2w = m->m23;		HX_STACK_VAR(l2w,"l2w");
	HX_STACK_LINE(240)
	Float vl0 = ::Math_obj::sqrt((((l0x * l0x) + (l1x * l1x)) + (l2x * l2x)));		HX_STACK_VAR(vl0,"vl0");
	HX_STACK_LINE(241)
	Float vl1 = ::Math_obj::sqrt((((l0y * l0y) + (l1y * l1y)) + (l2y * l2y)));		HX_STACK_VAR(vl1,"vl1");
	HX_STACK_LINE(242)
	Float vl2 = ::Math_obj::sqrt((((l0z * l0z) + (l1z * l1z)) + (l2z * l2z)));		HX_STACK_VAR(vl2,"vl2");
	HX_STACK_LINE(244)
	Float sx;		HX_STACK_VAR(sx,"sx");
	HX_STACK_LINE(244)
	if (((((  (((vl0 < (int)0))) ? Float(-(vl0)) : Float(vl0) )) <= 0.0001))){
		HX_STACK_LINE(244)
		sx = 0.0;
	}
	else{
		HX_STACK_LINE(244)
		sx = (Float(1.0) / Float(vl0));
	}
	HX_STACK_LINE(245)
	Float sy;		HX_STACK_VAR(sy,"sy");
	HX_STACK_LINE(245)
	if (((((  (((vl1 < (int)0))) ? Float(-(vl1)) : Float(vl1) )) <= 0.0001))){
		HX_STACK_LINE(245)
		sy = 0.0;
	}
	else{
		HX_STACK_LINE(245)
		sy = (Float(1.0) / Float(vl1));
	}
	HX_STACK_LINE(246)
	Float sz;		HX_STACK_VAR(sz,"sz");
	HX_STACK_LINE(246)
	if (((((  (((vl2 < (int)0))) ? Float(-(vl2)) : Float(vl2) )) <= 0.0001))){
		HX_STACK_LINE(246)
		sz = 0.0;
	}
	else{
		HX_STACK_LINE(246)
		sz = (Float(1.0) / Float(vl2));
	}
	HX_STACK_LINE(249)
	hx::MultEq(l0x,sx);
	HX_STACK_LINE(249)
	hx::MultEq(l0y,sy);
	HX_STACK_LINE(249)
	hx::MultEq(l0z,sz);
	HX_STACK_LINE(250)
	hx::MultEq(l1x,sx);
	HX_STACK_LINE(250)
	hx::MultEq(l1y,sy);
	HX_STACK_LINE(250)
	hx::MultEq(l1z,sz);
	HX_STACK_LINE(251)
	hx::MultEq(l2x,sx);
	HX_STACK_LINE(251)
	hx::MultEq(l2y,sy);
	HX_STACK_LINE(251)
	hx::MultEq(l2z,sz);
	HX_STACK_LINE(253)
	result->Set((sx * l0x),(sx * l1x),(sx * l2x),(sx * ((((l0x * -(l0w)) + (l1x * -(l1w))) + (l2x * -(l2w))))),(sy * l0y),(sy * l1y),(sy * l2y),(sy * ((((l0y * -(l0w)) + (l1y * -(l1w))) + (l2y * -(l2w))))),(sz * l0z),(sz * l1z),(sz * l2z),(sz * ((((l0z * -(l0w)) + (l1z * -(l1w))) + (l2z * -(l2w))))),(int)0,(int)0,(int)0,(int)1);
	HX_STACK_LINE(259)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Matrix4_obj,GetInverseTransform,return )

::haxor::math::Matrix4 Matrix4_obj::LookRotation( ::haxor::math::Vector3 p_forward,::haxor::math::Vector3 p_up,::haxor::math::Matrix4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","LookRotation",0x37a9c4b2,"haxor.math.Matrix4.LookRotation","haxor/math/Matrix4.hx",268,0xc9a22505)
	HX_STACK_ARG(p_forward,"p_forward")
	HX_STACK_ARG(p_up,"p_up")
	HX_STACK_ARG(p_result,"p_result")
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Matrix4.hx",268,0xc9a22505)
			{
				HX_STACK_LINE(268)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(268)
				int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(268)
				return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(268)
	::haxor::math::Vector3 _g1 = (_Function_1_1::Block())->Set((int)0,(int)0,(int)0);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(268)
	return ::haxor::math::Matrix4_obj::LookAt(_g1,p_forward,p_up,p_result);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Matrix4_obj,LookRotation,return )

::haxor::math::Matrix4 Matrix4_obj::LookAt( ::haxor::math::Vector3 p_eye,::haxor::math::Vector3 p_at,::haxor::math::Vector3 p_up,::haxor::math::Matrix4 p_result){
	HX_STACK_FRAME("haxor.math.Matrix4","LookAt",0xe4d00d67,"haxor.math.Matrix4.LookAt","haxor/math/Matrix4.hx",278,0xc9a22505)
	HX_STACK_ARG(p_eye,"p_eye")
	HX_STACK_ARG(p_at,"p_at")
	HX_STACK_ARG(p_up,"p_up")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(279)
	::haxor::math::Matrix4 _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(279)
	if (((p_result == null()))){
		HX_STACK_LINE(279)
		_g = ::haxor::math::Matrix4_obj::__new(null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(279)
		_g = p_result;
	}
	HX_STACK_LINE(279)
	p_result = _g;
	HX_STACK_LINE(280)
	::haxor::math::Vector3 _g2;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(280)
	if (((p_up == null()))){
		struct _Function_2_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Matrix4.hx",280,0xc9a22505)
				{
					HX_STACK_LINE(280)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(280)
					int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(280)
					return _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(280)
		_g2 = (_Function_2_1::Block())->Set((int)0,(int)1,(int)0);
	}
	else{
		HX_STACK_LINE(280)
		_g2 = p_up;
	}
	HX_STACK_LINE(280)
	p_up = _g2;
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Matrix4.hx",281,0xc9a22505)
			{
				HX_STACK_LINE(281)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(281)
				int _g3 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(281)
				return _this->m_v3->__get(_g3).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(281)
	::haxor::math::Vector3 f = (_Function_1_1::Block())->Set3(p_at)->Sub(p_eye)->Normalize();		HX_STACK_VAR(f,"f");
	HX_STACK_LINE(282)
	::haxor::math::Vector3 _g5;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(282)
	{
		HX_STACK_LINE(282)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(282)
		int _g4 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(282)
		_g5 = _this->m_v3->__get(_g4).StaticCast< ::haxor::math::Vector3 >();
	}
	HX_STACK_LINE(282)
	::haxor::math::Vector3 s = ::haxor::math::Vector3_obj::Cross(f,p_up,_g5)->Normalize();		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(283)
	::haxor::math::Vector3 _g7;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(283)
	{
		HX_STACK_LINE(283)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(283)
		int _g6 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(283)
		_g7 = _this->m_v3->__get(_g6).StaticCast< ::haxor::math::Vector3 >();
	}
	HX_STACK_LINE(283)
	::haxor::math::Vector3 u = ::haxor::math::Vector3_obj::Cross(s,f,_g7);		HX_STACK_VAR(u,"u");
	HX_STACK_LINE(284)
	p_result->m00 = s->x;
	HX_STACK_LINE(285)
	p_result->m10 = s->y;
	HX_STACK_LINE(286)
	p_result->m20 = s->z;
	HX_STACK_LINE(287)
	p_result->m01 = u->x;
	HX_STACK_LINE(288)
	p_result->m11 = u->y;
	HX_STACK_LINE(289)
	p_result->m21 = u->z;
	HX_STACK_LINE(290)
	p_result->m02 = -(f->x);
	HX_STACK_LINE(291)
	p_result->m12 = -(f->y);
	HX_STACK_LINE(292)
	p_result->m22 = -(f->z);
	HX_STACK_LINE(293)
	p_result->m03 = -(((((s->x * p_eye->x) + (s->y * p_eye->y)) + (s->z * p_eye->z))));
	HX_STACK_LINE(294)
	p_result->m13 = -(((((u->x * p_eye->x) + (u->y * p_eye->y)) + (u->z * p_eye->z))));
	HX_STACK_LINE(295)
	p_result->m23 = (((f->x * p_eye->x) + (f->y * p_eye->y)) + (f->z * p_eye->z));
	HX_STACK_LINE(296)
	Float _g8 = p_result->m32 = 0.0;		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(296)
	Float _g9 = p_result->m31 = _g8;		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(296)
	p_result->m30 = _g9;
	HX_STACK_LINE(296)
	p_result->m33 = 1.0;
	HX_STACK_LINE(297)
	return p_result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Matrix4_obj,LookAt,return )

::haxor::math::Matrix4 Matrix4_obj::Parse( ::String p_data,::String __o_p_delimiter){
::String p_delimiter = __o_p_delimiter.Default(HX_CSTRING(" "));
	HX_STACK_FRAME("haxor.math.Matrix4","Parse",0x379bb59e,"haxor.math.Matrix4.Parse","haxor/math/Matrix4.hx",996,0xc9a22505)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_delimiter,"p_delimiter")
{
		HX_STACK_LINE(997)
		Array< ::String > tk = p_data.split(p_delimiter);		HX_STACK_VAR(tk,"tk");
		HX_STACK_LINE(998)
		::haxor::math::Matrix4 res = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(res,"res");
		HX_STACK_LINE(999)
		{
			HX_STACK_LINE(999)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(999)
			int _g = tk->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(999)
			while((true)){
				HX_STACK_LINE(999)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(999)
					break;
				}
				HX_STACK_LINE(999)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(1001)
				::String _g2 = ::StringTools_obj::trim(tk->__get(i));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(1001)
				Float n = ::Std_obj::parseFloat(_g2);		HX_STACK_VAR(n,"n");
				HX_STACK_LINE(1003)
				res->SetIndex(i,n);
			}
		}
		HX_STACK_LINE(1005)
		return res;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Matrix4_obj,Parse,return )


Matrix4_obj::Matrix4_obj()
{
}

void Matrix4_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Matrix4);
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(translation,"translation");
	HX_MARK_MEMBER_NAME(inverseTransform,"inverseTransform");
	HX_MARK_MEMBER_NAME(transposed,"transposed");
	HX_MARK_MEMBER_NAME(m00,"m00");
	HX_MARK_MEMBER_NAME(m01,"m01");
	HX_MARK_MEMBER_NAME(m02,"m02");
	HX_MARK_MEMBER_NAME(m03,"m03");
	HX_MARK_MEMBER_NAME(m10,"m10");
	HX_MARK_MEMBER_NAME(m11,"m11");
	HX_MARK_MEMBER_NAME(m12,"m12");
	HX_MARK_MEMBER_NAME(m13,"m13");
	HX_MARK_MEMBER_NAME(m20,"m20");
	HX_MARK_MEMBER_NAME(m21,"m21");
	HX_MARK_MEMBER_NAME(m22,"m22");
	HX_MARK_MEMBER_NAME(m23,"m23");
	HX_MARK_MEMBER_NAME(m30,"m30");
	HX_MARK_MEMBER_NAME(m31,"m31");
	HX_MARK_MEMBER_NAME(m32,"m32");
	HX_MARK_MEMBER_NAME(m33,"m33");
	HX_MARK_END_CLASS();
}

void Matrix4_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(rotation,"rotation");
	HX_VISIT_MEMBER_NAME(scale,"scale");
	HX_VISIT_MEMBER_NAME(translation,"translation");
	HX_VISIT_MEMBER_NAME(inverseTransform,"inverseTransform");
	HX_VISIT_MEMBER_NAME(transposed,"transposed");
	HX_VISIT_MEMBER_NAME(m00,"m00");
	HX_VISIT_MEMBER_NAME(m01,"m01");
	HX_VISIT_MEMBER_NAME(m02,"m02");
	HX_VISIT_MEMBER_NAME(m03,"m03");
	HX_VISIT_MEMBER_NAME(m10,"m10");
	HX_VISIT_MEMBER_NAME(m11,"m11");
	HX_VISIT_MEMBER_NAME(m12,"m12");
	HX_VISIT_MEMBER_NAME(m13,"m13");
	HX_VISIT_MEMBER_NAME(m20,"m20");
	HX_VISIT_MEMBER_NAME(m21,"m21");
	HX_VISIT_MEMBER_NAME(m22,"m22");
	HX_VISIT_MEMBER_NAME(m23,"m23");
	HX_VISIT_MEMBER_NAME(m30,"m30");
	HX_VISIT_MEMBER_NAME(m31,"m31");
	HX_VISIT_MEMBER_NAME(m32,"m32");
	HX_VISIT_MEMBER_NAME(m33,"m33");
}

Dynamic Matrix4_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"TRS") ) { return TRS_dyn(); }
		if (HX_FIELD_EQ(inName,"m00") ) { return m00; }
		if (HX_FIELD_EQ(inName,"m01") ) { return m01; }
		if (HX_FIELD_EQ(inName,"m02") ) { return m02; }
		if (HX_FIELD_EQ(inName,"m03") ) { return m03; }
		if (HX_FIELD_EQ(inName,"m10") ) { return m10; }
		if (HX_FIELD_EQ(inName,"m11") ) { return m11; }
		if (HX_FIELD_EQ(inName,"m12") ) { return m12; }
		if (HX_FIELD_EQ(inName,"m13") ) { return m13; }
		if (HX_FIELD_EQ(inName,"m20") ) { return m20; }
		if (HX_FIELD_EQ(inName,"m21") ) { return m21; }
		if (HX_FIELD_EQ(inName,"m22") ) { return m22; }
		if (HX_FIELD_EQ(inName,"m23") ) { return m23; }
		if (HX_FIELD_EQ(inName,"m30") ) { return m30; }
		if (HX_FIELD_EQ(inName,"m31") ) { return m31; }
		if (HX_FIELD_EQ(inName,"m32") ) { return m32; }
		if (HX_FIELD_EQ(inName,"m33") ) { return m33; }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"temp") ) { return inCallProp ? get_temp() : temp; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Ortho") ) { return Ortho_dyn(); }
		if (HX_FIELD_EQ(inName,"Parse") ) { return Parse_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return get_clone(); }
		if (HX_FIELD_EQ(inName,"trace") ) { return get_trace(); }
		if (HX_FIELD_EQ(inName,"scale") ) { return inCallProp ? get_scale() : scale; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"LookAt") ) { return LookAt_dyn(); }
		if (HX_FIELD_EQ(inName,"Rotate") ) { return Rotate_dyn(); }
		if (HX_FIELD_EQ(inName,"SetTRS") ) { return SetTRS_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Frustum") ) { return Frustum_dyn(); }
		if (HX_FIELD_EQ(inName,"GetLine") ) { return GetLine_dyn(); }
		if (HX_FIELD_EQ(inName,"SetLine") ) { return SetLine_dyn(); }
		if (HX_FIELD_EQ(inName,"SwapCol") ) { return SwapCol_dyn(); }
		if (HX_FIELD_EQ(inName,"SwapRow") ) { return SwapRow_dyn(); }
		if (HX_FIELD_EQ(inName,"ToArray") ) { return ToArray_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_temp") ) { return get_temp_dyn(); }
		if (HX_FIELD_EQ(inName,"identity") ) { return inCallProp ? get_identity() : identity; }
		if (HX_FIELD_EQ(inName,"rotation") ) { return inCallProp ? get_rotation() : rotation; }
		if (HX_FIELD_EQ(inName,"GetIndex") ) { return GetIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"SetIndex") ) { return SetIndex_dyn(); }
		if (HX_FIELD_EQ(inName,"Multiply") ) { return Multiply_dyn(); }
		if (HX_FIELD_EQ(inName,"SetOrtho") ) { return SetOrtho_dyn(); }
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"FromArray") ) { return FromArray_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clone") ) { return get_clone_dyn(); }
		if (HX_FIELD_EQ(inName,"get_trace") ) { return get_trace_dyn(); }
		if (HX_FIELD_EQ(inName,"get_scale") ) { return get_scale_dyn(); }
		if (HX_FIELD_EQ(inName,"GetColumn") ) { return GetColumn_dyn(); }
		if (HX_FIELD_EQ(inName,"SetColumn") ) { return SetColumn_dyn(); }
		if (HX_FIELD_EQ(inName,"SetRowCol") ) { return SetRowCol_dyn(); }
		if (HX_FIELD_EQ(inName,"GetRowCol") ) { return GetRowCol_dyn(); }
		if (HX_FIELD_EQ(inName,"Transpose") ) { return Transpose_dyn(); }
		if (HX_FIELD_EQ(inName,"SetLookAt") ) { return SetLookAt_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"quaternion") ) { return get_quaternion(); }
		if (HX_FIELD_EQ(inName,"transposed") ) { return inCallProp ? get_transposed() : transposed; }
		if (HX_FIELD_EQ(inName,"ToRowMajor") ) { return ToRowMajor_dyn(); }
		if (HX_FIELD_EQ(inName,"diagonalLR") ) { return get_diagonalLR(); }
		if (HX_FIELD_EQ(inName,"SetMatrix4") ) { return SetMatrix4_dyn(); }
		if (HX_FIELD_EQ(inName,"ToRotation") ) { return ToRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFrustum") ) { return SetFrustum_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"Perspective") ) { return Perspective_dyn(); }
		if (HX_FIELD_EQ(inName,"GetRotation") ) { return GetRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"translation") ) { return inCallProp ? get_translation() : translation; }
		if (HX_FIELD_EQ(inName,"SetIdentity") ) { return SetIdentity_dyn(); }
		if (HX_FIELD_EQ(inName,"Multiply3x4") ) { return Multiply3x4_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_identity") ) { return get_identity_dyn(); }
		if (HX_FIELD_EQ(inName,"OrthoInverse") ) { return OrthoInverse_dyn(); }
		if (HX_FIELD_EQ(inName,"LookRotation") ) { return LookRotation_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rotation") ) { return get_rotation_dyn(); }
		if (HX_FIELD_EQ(inName,"Transform4x4") ) { return Transform4x4_dyn(); }
		if (HX_FIELD_EQ(inName,"Transform3x4") ) { return Transform3x4_dyn(); }
		if (HX_FIELD_EQ(inName,"Transform3x3") ) { return Transform3x3_dyn(); }
		if (HX_FIELD_EQ(inName,"Transform2x3") ) { return Transform2x3_dyn(); }
		if (HX_FIELD_EQ(inName,"Transform2x2") ) { return Transform2x2_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"ToColumnMajor") ) { return ToColumnMajor_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"FromQuaternion") ) { return FromQuaternion_dyn(); }
		if (HX_FIELD_EQ(inName,"FrustumInverse") ) { return FrustumInverse_dyn(); }
		if (HX_FIELD_EQ(inName,"get_quaternion") ) { return get_quaternion_dyn(); }
		if (HX_FIELD_EQ(inName,"set_quaternion") ) { return set_quaternion_dyn(); }
		if (HX_FIELD_EQ(inName,"get_transposed") ) { return get_transposed_dyn(); }
		if (HX_FIELD_EQ(inName,"get_diagonalLR") ) { return get_diagonalLR_dyn(); }
		if (HX_FIELD_EQ(inName,"set_diagonalLR") ) { return set_diagonalLR_dyn(); }
		if (HX_FIELD_EQ(inName,"SetPerspective") ) { return SetPerspective_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_translation") ) { return get_translation_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"inverseTransform") ) { return inCallProp ? get_inverseTransform() : inverseTransform; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"MultiplyTransform") ) { return MultiplyTransform_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFrustumInverse") ) { return SetFrustumInverse_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"PerspectiveInverse") ) { return PerspectiveInverse_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"GetInverseTransform") ) { return GetInverseTransform_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"get_inverseTransform") ) { return get_inverseTransform_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"SetPerspectiveInverse") ) { return SetPerspectiveInverse_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Matrix4_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m00") ) { m00=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m01") ) { m01=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m02") ) { m02=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m03") ) { m03=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m10") ) { m10=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m11") ) { m11=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m12") ) { m12=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m13") ) { m13=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m20") ) { m20=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m21") ) { m21=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m22") ) { m22=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m23") ) { m23=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m30") ) { m30=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m31") ) { m31=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m32") ) { m32=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m33") ) { m33=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"temp") ) { temp=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"identity") ) { identity=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rotation") ) { rotation=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"quaternion") ) { return set_quaternion(inValue); }
		if (HX_FIELD_EQ(inName,"transposed") ) { transposed=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"diagonalLR") ) { return set_diagonalLR(inValue); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"translation") ) { translation=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"inverseTransform") ) { inverseTransform=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Matrix4_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("clone"));
	outFields->push(HX_CSTRING("quaternion"));
	outFields->push(HX_CSTRING("trace"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("translation"));
	outFields->push(HX_CSTRING("inverseTransform"));
	outFields->push(HX_CSTRING("transposed"));
	outFields->push(HX_CSTRING("m00"));
	outFields->push(HX_CSTRING("m01"));
	outFields->push(HX_CSTRING("m02"));
	outFields->push(HX_CSTRING("m03"));
	outFields->push(HX_CSTRING("m10"));
	outFields->push(HX_CSTRING("m11"));
	outFields->push(HX_CSTRING("m12"));
	outFields->push(HX_CSTRING("m13"));
	outFields->push(HX_CSTRING("m20"));
	outFields->push(HX_CSTRING("m21"));
	outFields->push(HX_CSTRING("m22"));
	outFields->push(HX_CSTRING("m23"));
	outFields->push(HX_CSTRING("m30"));
	outFields->push(HX_CSTRING("m31"));
	outFields->push(HX_CSTRING("m32"));
	outFields->push(HX_CSTRING("m33"));
	outFields->push(HX_CSTRING("diagonalLR"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("temp"),
	HX_CSTRING("get_temp"),
	HX_CSTRING("identity"),
	HX_CSTRING("get_identity"),
	HX_CSTRING("FromQuaternion"),
	HX_CSTRING("FromArray"),
	HX_CSTRING("TRS"),
	HX_CSTRING("Frustum"),
	HX_CSTRING("FrustumInverse"),
	HX_CSTRING("Ortho"),
	HX_CSTRING("OrthoInverse"),
	HX_CSTRING("Perspective"),
	HX_CSTRING("PerspectiveInverse"),
	HX_CSTRING("GetRotation"),
	HX_CSTRING("GetInverseTransform"),
	HX_CSTRING("LookRotation"),
	HX_CSTRING("LookAt"),
	HX_CSTRING("Parse"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Matrix4_obj,rotation),HX_CSTRING("rotation")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Matrix4_obj,scale),HX_CSTRING("scale")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Matrix4_obj,translation),HX_CSTRING("translation")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Matrix4_obj,inverseTransform),HX_CSTRING("inverseTransform")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Matrix4_obj,transposed),HX_CSTRING("transposed")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m00),HX_CSTRING("m00")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m01),HX_CSTRING("m01")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m02),HX_CSTRING("m02")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m03),HX_CSTRING("m03")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m10),HX_CSTRING("m10")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m11),HX_CSTRING("m11")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m12),HX_CSTRING("m12")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m13),HX_CSTRING("m13")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m20),HX_CSTRING("m20")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m21),HX_CSTRING("m21")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m22),HX_CSTRING("m22")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m23),HX_CSTRING("m23")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m30),HX_CSTRING("m30")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m31),HX_CSTRING("m31")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m32),HX_CSTRING("m32")},
	{hx::fsFloat,(int)offsetof(Matrix4_obj,m33),HX_CSTRING("m33")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_clone"),
	HX_CSTRING("get_quaternion"),
	HX_CSTRING("set_quaternion"),
	HX_CSTRING("get_trace"),
	HX_CSTRING("rotation"),
	HX_CSTRING("get_rotation"),
	HX_CSTRING("scale"),
	HX_CSTRING("get_scale"),
	HX_CSTRING("translation"),
	HX_CSTRING("get_translation"),
	HX_CSTRING("inverseTransform"),
	HX_CSTRING("get_inverseTransform"),
	HX_CSTRING("transposed"),
	HX_CSTRING("get_transposed"),
	HX_CSTRING("ToRowMajor"),
	HX_CSTRING("ToColumnMajor"),
	HX_CSTRING("m00"),
	HX_CSTRING("m01"),
	HX_CSTRING("m02"),
	HX_CSTRING("m03"),
	HX_CSTRING("m10"),
	HX_CSTRING("m11"),
	HX_CSTRING("m12"),
	HX_CSTRING("m13"),
	HX_CSTRING("m20"),
	HX_CSTRING("m21"),
	HX_CSTRING("m22"),
	HX_CSTRING("m23"),
	HX_CSTRING("m30"),
	HX_CSTRING("m31"),
	HX_CSTRING("m32"),
	HX_CSTRING("m33"),
	HX_CSTRING("GetLine"),
	HX_CSTRING("SetLine"),
	HX_CSTRING("GetColumn"),
	HX_CSTRING("SetColumn"),
	HX_CSTRING("get_diagonalLR"),
	HX_CSTRING("set_diagonalLR"),
	HX_CSTRING("SetIdentity"),
	HX_CSTRING("Set"),
	HX_CSTRING("SetMatrix4"),
	HX_CSTRING("GetIndex"),
	HX_CSTRING("SetIndex"),
	HX_CSTRING("SetRowCol"),
	HX_CSTRING("GetRowCol"),
	HX_CSTRING("SwapCol"),
	HX_CSTRING("SwapRow"),
	HX_CSTRING("Transpose"),
	HX_CSTRING("ToRotation"),
	HX_CSTRING("Rotate"),
	HX_CSTRING("SetTRS"),
	HX_CSTRING("MultiplyTransform"),
	HX_CSTRING("Multiply3x4"),
	HX_CSTRING("Multiply"),
	HX_CSTRING("Transform4x4"),
	HX_CSTRING("Transform3x4"),
	HX_CSTRING("Transform3x3"),
	HX_CSTRING("Transform2x3"),
	HX_CSTRING("Transform2x2"),
	HX_CSTRING("SetLookAt"),
	HX_CSTRING("SetFrustum"),
	HX_CSTRING("SetFrustumInverse"),
	HX_CSTRING("SetOrtho"),
	HX_CSTRING("SetPerspective"),
	HX_CSTRING("SetPerspectiveInverse"),
	HX_CSTRING("ToArray"),
	HX_CSTRING("ToString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Matrix4_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Matrix4_obj::temp,"temp");
	HX_MARK_MEMBER_NAME(Matrix4_obj::identity,"identity");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Matrix4_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Matrix4_obj::temp,"temp");
	HX_VISIT_MEMBER_NAME(Matrix4_obj::identity,"identity");
};

#endif

Class Matrix4_obj::__mClass;

void Matrix4_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.math.Matrix4"), hx::TCanCast< Matrix4_obj> ,sStaticFields,sMemberFields,
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

void Matrix4_obj::__boot()
{
}

} // end namespace haxor
} // end namespace math
