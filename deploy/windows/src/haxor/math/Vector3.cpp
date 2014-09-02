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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace math{

Void Vector3_obj::__construct(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z)
{
HX_STACK_FRAME("haxor.math.Vector3","new",0xd8de16e8,"haxor.math.Vector3.new","haxor/math/Vector3.hx",247,0x4fead1e8)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_x,"p_x")
HX_STACK_ARG(__o_p_y,"p_y")
HX_STACK_ARG(__o_p_z,"p_z")
Float p_x = __o_p_x.Default(0);
Float p_y = __o_p_y.Default(0);
Float p_z = __o_p_z.Default(0);
{
	HX_STACK_LINE(248)
	this->x = p_x;
	HX_STACK_LINE(249)
	this->y = p_y;
	HX_STACK_LINE(250)
	this->z = p_z;
}
;
	return null();
}

//Vector3_obj::~Vector3_obj() { }

Dynamic Vector3_obj::__CreateEmpty() { return  new Vector3_obj; }
hx::ObjectPtr< Vector3_obj > Vector3_obj::__new(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z)
{  hx::ObjectPtr< Vector3_obj > result = new Vector3_obj();
	result->__construct(__o_p_x,__o_p_y,__o_p_z);
	return result;}

Dynamic Vector3_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Vector3_obj > result = new Vector3_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::haxor::math::Vector3 Vector3_obj::get_clone( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_clone",0x5df64c3c,"haxor.math.Vector3.get_clone","haxor/math/Vector3.hx",137,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(137)
	return ::haxor::math::Vector3_obj::__new(this->x,this->y,this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_clone,return )

::haxor::math::Color Vector3_obj::get_color( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_color",0x5fefaa42,"haxor.math.Vector3.get_color","haxor/math/Vector3.hx",143,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(143)
	return ::haxor::math::Color_obj::__new(this->x,this->y,this->z,null());
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_color,return )

::haxor::math::Vector3 Vector3_obj::get_xzy( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_xzy",0x67746c56,"haxor.math.Vector3.get_xzy","haxor/math/Vector3.hx",148,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(148)
	return ::haxor::math::Vector3_obj::__new(this->x,this->z,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_xzy,return )

::haxor::math::Vector3 Vector3_obj::get_yxz( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_yxz",0x67752cda,"haxor.math.Vector3.get_yxz","haxor/math/Vector3.hx",153,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(153)
	return ::haxor::math::Vector3_obj::__new(this->y,this->z,this->x);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_yxz,return )

::haxor::math::Vector3 Vector3_obj::get_yzx( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_yzx",0x67752e96,"haxor.math.Vector3.get_yzx","haxor/math/Vector3.hx",158,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(158)
	return ::haxor::math::Vector3_obj::__new(this->y,this->z,this->x);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_yzx,return )

::haxor::math::Vector3 Vector3_obj::get_zxy( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_zxy",0x6775ef1a,"haxor.math.Vector3.get_zxy","haxor/math/Vector3.hx",163,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(163)
	return ::haxor::math::Vector3_obj::__new(this->z,this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_zxy,return )

::haxor::math::Vector3 Vector3_obj::get_zyx( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_zyx",0x6775eff8,"haxor.math.Vector3.get_zyx","haxor/math/Vector3.hx",168,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(168)
	return ::haxor::math::Vector3_obj::__new(this->z,this->y,this->x);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_zyx,return )

::haxor::math::Vector2 Vector3_obj::get_xy( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_xy",0xdbba7ec2,"haxor.math.Vector3.get_xy","haxor/math/Vector3.hx",173,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(173)
	return ::haxor::math::Vector2_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_xy,return )

::haxor::math::Vector2 Vector3_obj::get_xz( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_xz",0xdbba7ec3,"haxor.math.Vector3.get_xz","haxor/math/Vector3.hx",178,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(178)
	return ::haxor::math::Vector2_obj::__new(this->x,this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_xz,return )

::haxor::math::Vector2 Vector3_obj::get_yx( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_yx",0xdbba7fa0,"haxor.math.Vector3.get_yx","haxor/math/Vector3.hx",183,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(183)
	return ::haxor::math::Vector2_obj::__new(this->y,this->x);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_yx,return )

::haxor::math::Vector2 Vector3_obj::get_yz( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_yz",0xdbba7fa2,"haxor.math.Vector3.get_yz","haxor/math/Vector3.hx",188,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(188)
	return ::haxor::math::Vector2_obj::__new(this->y,this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_yz,return )

::haxor::math::Vector2 Vector3_obj::get_zx( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_zx",0xdbba807f,"haxor.math.Vector3.get_zx","haxor/math/Vector3.hx",193,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(193)
	return ::haxor::math::Vector2_obj::__new(this->z,this->x);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_zx,return )

::haxor::math::Vector2 Vector3_obj::get_zy( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_zy",0xdbba8080,"haxor.math.Vector3.get_zy","haxor/math/Vector3.hx",198,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(198)
	return ::haxor::math::Vector2_obj::__new(this->z,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_zy,return )

Float Vector3_obj::get_length( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_length",0x6a461f27,"haxor.math.Vector3.get_length","haxor/math/Vector3.hx",204,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(204)
	return ::Math_obj::sqrt((((this->x * this->x) + (this->y * this->y)) + (this->z * this->z)));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_length,return )

Float Vector3_obj::get_lengthSqr( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_lengthSqr",0x5d1df12d,"haxor.math.Vector3.get_lengthSqr","haxor/math/Vector3.hx",210,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(210)
	return (((this->x * this->x) + (this->y * this->y)) + (this->z * this->z));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_lengthSqr,return )

::haxor::math::Vector3 Vector3_obj::get_normalized( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_normalized",0x7cc6a2f8,"haxor.math.Vector3.get_normalized","haxor/math/Vector3.hx",216,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(216)
	return ::haxor::math::Vector3_obj::__new(this->x,this->y,this->z)->Normalize();
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_normalized,return )

::haxor::math::Vector3 Vector3_obj::get_inverse( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_inverse",0x496bba4f,"haxor.math.Vector3.get_inverse","haxor/math/Vector3.hx",222,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(222)
	return ::haxor::math::Vector3_obj::__new(this->x,this->y,this->z)->Invert();
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_inverse,return )

::haxor::math::Vector3 Vector3_obj::Set( hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z){
Float p_x = __o_p_x.Default(0);
Float p_y = __o_p_y.Default(0);
Float p_z = __o_p_z.Default(0);
	HX_STACK_FRAME("haxor.math.Vector3","Set",0xd8c99a0a,"haxor.math.Vector3.Set","haxor/math/Vector3.hx",260,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_ARG(p_z,"p_z")
{
		HX_STACK_LINE(260)
		this->x = p_x;
		HX_STACK_LINE(260)
		this->y = p_y;
		HX_STACK_LINE(260)
		this->z = p_z;
		HX_STACK_LINE(260)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,Set,return )

::haxor::math::Vector3 Vector3_obj::Set2( ::haxor::math::Vector2 v){
	HX_STACK_FRAME("haxor.math.Vector3","Set2",0xd79d2ee8,"haxor.math.Vector3.Set2","haxor/math/Vector3.hx",267,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(267)
	this->x = v->x;
	HX_STACK_LINE(267)
	this->y = v->y;
	HX_STACK_LINE(267)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,Set2,return )

::haxor::math::Vector3 Vector3_obj::Set3( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.math.Vector3","Set3",0xd79d2ee9,"haxor.math.Vector3.Set3","haxor/math/Vector3.hx",274,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(274)
	this->x = v->x;
	HX_STACK_LINE(274)
	this->y = v->y;
	HX_STACK_LINE(274)
	this->z = v->z;
	HX_STACK_LINE(274)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,Set3,return )

::haxor::math::Vector3 Vector3_obj::Set4( ::haxor::math::Vector4 v){
	HX_STACK_FRAME("haxor.math.Vector3","Set4",0xd79d2eea,"haxor.math.Vector3.Set4","haxor/math/Vector3.hx",281,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(281)
	this->x = v->x;
	HX_STACK_LINE(281)
	this->y = v->y;
	HX_STACK_LINE(281)
	this->z = v->z;
	HX_STACK_LINE(281)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,Set4,return )

::haxor::math::Vector3 Vector3_obj::SetColor( ::haxor::math::Color v){
	HX_STACK_FRAME("haxor.math.Vector3","SetColor",0x8143a2f9,"haxor.math.Vector3.SetColor","haxor/math/Vector3.hx",288,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(288)
	this->x = v->r;
	HX_STACK_LINE(288)
	this->y = v->g;
	HX_STACK_LINE(288)
	this->z = v->b;
	HX_STACK_LINE(288)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,SetColor,return )

Float Vector3_obj::Get( int p){
	HX_STACK_FRAME("haxor.math.Vector3","Get",0xd8c07efe,"haxor.math.Vector3.Get","haxor/math/Vector3.hx",295,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p,"p")
	HX_STACK_LINE(295)
	if (((p == (int)0))){
		HX_STACK_LINE(295)
		return this->x;
	}
	else{
		HX_STACK_LINE(295)
		if (((p == (int)1))){
			HX_STACK_LINE(295)
			return this->y;
		}
		else{
			HX_STACK_LINE(295)
			return this->z;
		}
	}
	HX_STACK_LINE(295)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,Get,return )

::haxor::math::Vector3 Vector3_obj::Add( ::haxor::math::Vector3 p_v){
	HX_STACK_FRAME("haxor.math.Vector3","Add",0xd8bbf089,"haxor.math.Vector3.Add","haxor/math/Vector3.hx",302,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(302)
	hx::AddEq(this->x,p_v->x);
	HX_STACK_LINE(302)
	hx::AddEq(this->y,p_v->y);
	HX_STACK_LINE(302)
	hx::AddEq(this->z,p_v->z);
	HX_STACK_LINE(302)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,Add,return )

::haxor::math::Vector3 Vector3_obj::Add3( Float p_x,Float p_y,Float p_z){
	HX_STACK_FRAME("haxor.math.Vector3","Add3",0xcbb6878a,"haxor.math.Vector3.Add3","haxor/math/Vector3.hx",311,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_ARG(p_z,"p_z")
	HX_STACK_LINE(311)
	hx::AddEq(this->x,p_x);
	HX_STACK_LINE(311)
	hx::AddEq(this->y,p_y);
	HX_STACK_LINE(311)
	hx::AddEq(this->z,p_z);
	HX_STACK_LINE(311)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,Add3,return )

::haxor::math::Vector3 Vector3_obj::Sub( ::haxor::math::Vector3 p_v){
	HX_STACK_FRAME("haxor.math.Vector3","Sub",0xd8c9a7e8,"haxor.math.Vector3.Sub","haxor/math/Vector3.hx",318,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(318)
	hx::SubEq(this->x,p_v->x);
	HX_STACK_LINE(318)
	hx::SubEq(this->y,p_v->y);
	HX_STACK_LINE(318)
	hx::SubEq(this->z,p_v->z);
	HX_STACK_LINE(318)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,Sub,return )

::haxor::math::Vector3 Vector3_obj::Multiply( ::haxor::math::Vector3 p_v){
	HX_STACK_FRAME("haxor.math.Vector3","Multiply",0xc33faabc,"haxor.math.Vector3.Multiply","haxor/math/Vector3.hx",325,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(325)
	hx::MultEq(this->x,p_v->x);
	HX_STACK_LINE(325)
	hx::MultEq(this->y,p_v->y);
	HX_STACK_LINE(325)
	hx::MultEq(this->z,p_v->z);
	HX_STACK_LINE(325)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,Multiply,return )

bool Vector3_obj::Step( ::haxor::math::Vector3 p_to,Float p_step){
	HX_STACK_FRAME("haxor.math.Vector3","Step",0xd7a883e4,"haxor.math.Vector3.Step","haxor/math/Vector3.hx",334,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_to,"p_to")
	HX_STACK_ARG(p_step,"p_step")
	HX_STACK_LINE(335)
	Float vx = (p_to->x - this->x);		HX_STACK_VAR(vx,"vx");
	HX_STACK_LINE(336)
	Float vy = (p_to->y - this->y);		HX_STACK_VAR(vy,"vy");
	HX_STACK_LINE(337)
	Float vz = (p_to->z - this->z);		HX_STACK_VAR(vz,"vz");
	HX_STACK_LINE(338)
	Float l = ::Math_obj::sqrt((((vx * vx) + (vy * vy)) + (vz * vz)));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(339)
	if (((l <= 0.0001))){
		HX_STACK_LINE(339)
		return false;
	}
	HX_STACK_LINE(340)
	Float s;		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(340)
	if (((p_step > l))){
		HX_STACK_LINE(340)
		s = l;
	}
	else{
		HX_STACK_LINE(340)
		s = p_step;
	}
	HX_STACK_LINE(341)
	l = (Float(s) / Float(l));
	HX_STACK_LINE(342)
	hx::MultEq(vx,l);
	HX_STACK_LINE(343)
	hx::MultEq(vy,l);
	HX_STACK_LINE(344)
	hx::MultEq(vz,l);
	HX_STACK_LINE(345)
	hx::AddEq(this->x,vx);
	HX_STACK_LINE(346)
	hx::AddEq(this->y,vy);
	HX_STACK_LINE(347)
	hx::AddEq(this->z,vz);
	HX_STACK_LINE(348)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,Step,return )

::haxor::math::Vector3 Vector3_obj::Reflect( ::haxor::math::Vector3 p_normal){
	HX_STACK_FRAME("haxor.math.Vector3","Reflect",0xf71ed6a5,"haxor.math.Vector3.Reflect","haxor/math/Vector3.hx",357,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_normal,"p_normal")
	HX_STACK_LINE(358)
	Float _g = ::Math_obj::min(0.0,(((p_normal->x * this->x) + (p_normal->y * this->y)) + (p_normal->z * this->z)));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(358)
	Float d = (_g * 2.0);		HX_STACK_VAR(d,"d");
	HX_STACK_LINE(359)
	hx::AddEq(this->x,(-(p_normal->x) * d));
	HX_STACK_LINE(360)
	hx::AddEq(this->y,(-(p_normal->y) * d));
	HX_STACK_LINE(361)
	hx::AddEq(this->z,(-(p_normal->z) * d));
	HX_STACK_LINE(362)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,Reflect,return )

::haxor::math::Vector3 Vector3_obj::Invert( ){
	HX_STACK_FRAME("haxor.math.Vector3","Invert",0x0cf7d9ae,"haxor.math.Vector3.Invert","haxor/math/Vector3.hx",369,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(369)
	this->x = -(this->x);
	HX_STACK_LINE(369)
	this->y = -(this->y);
	HX_STACK_LINE(369)
	this->z = -(this->z);
	HX_STACK_LINE(369)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,Invert,return )

::haxor::math::Vector3 Vector3_obj::Scale( Float p_s){
	HX_STACK_FRAME("haxor.math.Vector3","Scale",0xd08b36f2,"haxor.math.Vector3.Scale","haxor/math/Vector3.hx",376,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_s,"p_s")
	HX_STACK_LINE(376)
	hx::MultEq(this->x,p_s);
	HX_STACK_LINE(376)
	hx::MultEq(this->y,p_s);
	HX_STACK_LINE(376)
	hx::MultEq(this->z,p_s);
	HX_STACK_LINE(376)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,Scale,return )

::haxor::math::Vector3 Vector3_obj::Normalize( ){
	HX_STACK_FRAME("haxor.math.Vector3","Normalize",0x1f5df3f5,"haxor.math.Vector3.Normalize","haxor/math/Vector3.hx",383,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(384)
	Float l = ::Math_obj::sqrt((((this->x * this->x) + (this->y * this->y)) + (this->z * this->z)));		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(385)
	if (((l <= (int)0))){
		HX_STACK_LINE(385)
		return hx::ObjectPtr<OBJ_>(this);
	}
	HX_STACK_LINE(386)
	Float _g = l = (Float(1.0) / Float(l));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(386)
	hx::MultEq(this->x,_g);
	HX_STACK_LINE(387)
	hx::MultEq(this->y,l);
	HX_STACK_LINE(388)
	hx::MultEq(this->z,l);
	HX_STACK_LINE(389)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,Normalize,return )

Array< Float > Vector3_obj::ToArray( ){
	HX_STACK_FRAME("haxor.math.Vector3","ToArray",0x00090c86,"haxor.math.Vector3.ToArray","haxor/math/Vector3.hx",396,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(396)
	return Array_obj< Float >::__new().Add(this->x).Add(this->y).Add(this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,ToArray,return )

::String Vector3_obj::ToString( hx::Null< int >  __o_p_places){
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.math.Vector3","ToString",0x61219944,"haxor.math.Vector3.ToString","haxor/math/Vector3.hx",402,0x4fead1e8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(402)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(402)
		{
			HX_STACK_LINE(402)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(402)
			Float _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(402)
			{
				HX_STACK_LINE(402)
				Float p_v = (this->x * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(402)
				_g = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(402)
			_g1 = (Float(_g) / Float(d));
		}
		HX_STACK_LINE(402)
		::String _g2 = (HX_CSTRING("[") + _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(402)
		::String _g3 = (_g2 + HX_CSTRING(","));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(402)
		Float _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(402)
		{
			HX_STACK_LINE(402)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(402)
			Float _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(402)
			{
				HX_STACK_LINE(402)
				Float p_v = (this->y * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(402)
				_g4 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(402)
			_g5 = (Float(_g4) / Float(d));
		}
		HX_STACK_LINE(402)
		::String _g6 = (_g3 + _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(402)
		::String _g7 = (_g6 + HX_CSTRING(","));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(402)
		Float _g9;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(402)
		{
			HX_STACK_LINE(402)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(402)
			Float _g8;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(402)
			{
				HX_STACK_LINE(402)
				Float p_v = (this->z * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(402)
				_g8 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(402)
			_g9 = (Float(_g8) / Float(d));
		}
		HX_STACK_LINE(402)
		::String _g10 = (_g7 + _g9);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(402)
		return (_g10 + HX_CSTRING("]"));
	}
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,ToString,return )

::haxor::math::Vector3 Vector3_obj::temp;

::haxor::math::Vector3 Vector3_obj::get_temp( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_temp",0x1bb58b15,"haxor.math.Vector3.get_temp","haxor/math/Vector3.hx",14,0x4fead1e8)
	HX_STACK_LINE(14)
	::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(14)
	int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(14)
	return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_temp,return )

::haxor::math::Vector3 Vector3_obj::zero;

::haxor::math::Vector3 Vector3_obj::get_zero( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_zero",0x1facd729,"haxor.math.Vector3.get_zero","haxor/math/Vector3.hx",20,0x4fead1e8)
	HX_STACK_LINE(20)
	return ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_zero,return )

::haxor::math::Vector3 Vector3_obj::one;

::haxor::math::Vector3 Vector3_obj::get_one( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_one",0x676d8d85,"haxor.math.Vector3.get_one","haxor/math/Vector3.hx",26,0x4fead1e8)
	HX_STACK_LINE(26)
	return ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_one,return )

::haxor::math::Vector3 Vector3_obj::right;

::haxor::math::Vector3 Vector3_obj::get_right( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_right",0xfef744bb,"haxor.math.Vector3.get_right","haxor/math/Vector3.hx",32,0x4fead1e8)
	HX_STACK_LINE(32)
	return ::haxor::math::Vector3_obj::__new((int)1,(int)0,(int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_right,return )

::haxor::math::Vector3 Vector3_obj::up;

::haxor::math::Vector3 Vector3_obj::get_up( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_up",0xdbba7c1c,"haxor.math.Vector3.get_up","haxor/math/Vector3.hx",38,0x4fead1e8)
	HX_STACK_LINE(38)
	return ::haxor::math::Vector3_obj::__new((int)0,(int)1,(int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_up,return )

::haxor::math::Vector3 Vector3_obj::forward;

::haxor::math::Vector3 Vector3_obj::get_forward( ){
	HX_STACK_FRAME("haxor.math.Vector3","get_forward",0xf1455064,"haxor.math.Vector3.get_forward","haxor/math/Vector3.hx",44,0x4fead1e8)
	HX_STACK_LINE(44)
	return ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,get_forward,return )

Float Vector3_obj::Dot( ::haxor::math::Vector3 p_a,::haxor::math::Vector3 p_b){
	HX_STACK_FRAME("haxor.math.Vector3","Dot",0xd8be40f1,"haxor.math.Vector3.Dot","haxor/math/Vector3.hx",52,0x4fead1e8)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_LINE(52)
	return (((p_a->x * p_b->x) + (p_a->y * p_b->y)) + (p_a->z * p_b->z));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,Dot,return )

Float Vector3_obj::Distance( ::haxor::math::Vector3 p_a,::haxor::math::Vector3 p_b){
	HX_STACK_FRAME("haxor.math.Vector3","Distance",0x94ac5bcd,"haxor.math.Vector3.Distance","haxor/math/Vector3.hx",61,0x4fead1e8)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_LINE(62)
	Float dx = (p_a->x - p_b->x);		HX_STACK_VAR(dx,"dx");
	HX_STACK_LINE(63)
	Float dy = (p_a->y - p_b->y);		HX_STACK_VAR(dy,"dy");
	HX_STACK_LINE(64)
	Float dz = (p_a->z - p_b->z);		HX_STACK_VAR(dz,"dz");
	HX_STACK_LINE(65)
	return ::Math_obj::sqrt((((dx * dx) + (dy * dy)) + (dz * dz)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,Distance,return )

::haxor::math::Vector3 Vector3_obj::Cross( ::haxor::math::Vector3 p_a,::haxor::math::Vector3 p_b,::haxor::math::Vector3 p_result){
	HX_STACK_FRAME("haxor.math.Vector3","Cross",0xa416c7e8,"haxor.math.Vector3.Cross","haxor/math/Vector3.hx",75,0x4fead1e8)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(76)
	::haxor::math::Vector3 _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(76)
	if (((p_result == null()))){
		HX_STACK_LINE(76)
		_g = ::haxor::math::Vector3_obj::__new(null(),null(),null());
	}
	else{
		HX_STACK_LINE(76)
		_g = p_result;
	}
	HX_STACK_LINE(76)
	p_result = _g;
	HX_STACK_LINE(77)
	return p_result->Set(((p_a->y * p_b->z) - (p_a->z * p_b->y)),((p_a->z * p_b->x) - (p_a->x * p_b->z)),((p_a->x * p_b->y) - (p_a->y * p_b->x)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,Cross,return )

::haxor::math::Vector3 Vector3_obj::Lerp( ::haxor::math::Vector3 p_a,::haxor::math::Vector3 p_b,Float p_r,::haxor::math::Vector3 p_result){
	HX_STACK_FRAME("haxor.math.Vector3","Lerp",0xd2fcaf0f,"haxor.math.Vector3.Lerp","haxor/math/Vector3.hx",92,0x4fead1e8)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_r,"p_r")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(93)
	::haxor::math::Vector3 _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(93)
	if (((p_result == null()))){
		HX_STACK_LINE(93)
		_g = ::haxor::math::Vector3_obj::__new(null(),null(),null());
	}
	else{
		HX_STACK_LINE(93)
		_g = p_result;
	}
	HX_STACK_LINE(93)
	p_result = _g;
	HX_STACK_LINE(94)
	return p_result->Set((p_a->x + (((p_b->x - p_a->x)) * p_r)),(p_a->y + (((p_b->y - p_a->y)) * p_r)),(p_a->z + (((p_b->z - p_a->z)) * p_r)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Vector3_obj,Lerp,return )

::haxor::math::Vector3 Vector3_obj::Min( ::haxor::math::Vector3 p_a,::haxor::math::Vector3 p_b,::haxor::math::Vector3 p_result){
	HX_STACK_FRAME("haxor.math.Vector3","Min",0xd8c50ffa,"haxor.math.Vector3.Min","haxor/math/Vector3.hx",109,0x4fead1e8)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(110)
	::haxor::math::Vector3 _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(110)
	if (((p_result == null()))){
		HX_STACK_LINE(110)
		_g = ::haxor::math::Vector3_obj::__new(null(),null(),null());
	}
	else{
		HX_STACK_LINE(110)
		_g = p_result;
	}
	HX_STACK_LINE(110)
	p_result = _g;
	HX_STACK_LINE(111)
	Float _g1 = ::Math_obj::min(p_a->x,p_b->x);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(111)
	p_result->x = _g1;
	HX_STACK_LINE(112)
	Float _g2 = ::Math_obj::min(p_a->y,p_b->y);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(112)
	p_result->y = _g2;
	HX_STACK_LINE(113)
	Float _g3 = ::Math_obj::min(p_a->z,p_b->z);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(113)
	p_result->z = _g3;
	HX_STACK_LINE(114)
	return p_result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,Min,return )

::haxor::math::Vector3 Vector3_obj::Max( ::haxor::math::Vector3 p_a,::haxor::math::Vector3 p_b,::haxor::math::Vector3 p_result){
	HX_STACK_FRAME("haxor.math.Vector3","Max",0xd8c5090c,"haxor.math.Vector3.Max","haxor/math/Vector3.hx",125,0x4fead1e8)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(126)
	::haxor::math::Vector3 _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(126)
	if (((p_result == null()))){
		HX_STACK_LINE(126)
		_g = ::haxor::math::Vector3_obj::__new(null(),null(),null());
	}
	else{
		HX_STACK_LINE(126)
		_g = p_result;
	}
	HX_STACK_LINE(126)
	p_result = _g;
	HX_STACK_LINE(127)
	Float _g1 = ::Math_obj::max(p_a->x,p_b->x);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(127)
	p_result->x = _g1;
	HX_STACK_LINE(128)
	Float _g2 = ::Math_obj::max(p_a->y,p_b->y);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(128)
	p_result->y = _g2;
	HX_STACK_LINE(129)
	Float _g3 = ::Math_obj::max(p_a->z,p_b->z);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(129)
	p_result->z = _g3;
	HX_STACK_LINE(130)
	return p_result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,Max,return )

::haxor::math::Vector3 Vector3_obj::Parse( ::String p_data,::String __o_p_delimiter){
::String p_delimiter = __o_p_delimiter.Default(HX_CSTRING(" "));
	HX_STACK_FRAME("haxor.math.Vector3","Parse",0x1511f89b,"haxor.math.Vector3.Parse","haxor/math/Vector3.hx",410,0x4fead1e8)
	HX_STACK_ARG(p_data,"p_data")
	HX_STACK_ARG(p_delimiter,"p_delimiter")
{
		HX_STACK_LINE(411)
		Array< ::String > tk = p_data.split(p_delimiter);		HX_STACK_VAR(tk,"tk");
		HX_STACK_LINE(413)
		::String _g = ::StringTools_obj::trim(tk->__get((int)0));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(413)
		Float _g1 = ::Std_obj::parseFloat(_g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(414)
		::String _g2 = ::StringTools_obj::trim(tk->__get((int)1));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(414)
		Float _g3 = ::Std_obj::parseFloat(_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(415)
		::String _g4 = ::StringTools_obj::trim(tk->__get((int)2));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(415)
		Float _g5 = ::Std_obj::parseFloat(_g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(412)
		return ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0)->Set(_g1,_g3,_g5);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,Parse,return )


Vector3_obj::Vector3_obj()
{
}

void Vector3_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Vector3);
	HX_MARK_MEMBER_NAME(clone,"clone");
	HX_MARK_MEMBER_NAME(color,"color");
	HX_MARK_MEMBER_NAME(xzy,"xzy");
	HX_MARK_MEMBER_NAME(yxz,"yxz");
	HX_MARK_MEMBER_NAME(yzx,"yzx");
	HX_MARK_MEMBER_NAME(zxy,"zxy");
	HX_MARK_MEMBER_NAME(zyx,"zyx");
	HX_MARK_MEMBER_NAME(xy,"xy");
	HX_MARK_MEMBER_NAME(xz,"xz");
	HX_MARK_MEMBER_NAME(yx,"yx");
	HX_MARK_MEMBER_NAME(yz,"yz");
	HX_MARK_MEMBER_NAME(zx,"zx");
	HX_MARK_MEMBER_NAME(zy,"zy");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(lengthSqr,"lengthSqr");
	HX_MARK_MEMBER_NAME(normalized,"normalized");
	HX_MARK_MEMBER_NAME(inverse,"inverse");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(z,"z");
	HX_MARK_END_CLASS();
}

void Vector3_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(clone,"clone");
	HX_VISIT_MEMBER_NAME(color,"color");
	HX_VISIT_MEMBER_NAME(xzy,"xzy");
	HX_VISIT_MEMBER_NAME(yxz,"yxz");
	HX_VISIT_MEMBER_NAME(yzx,"yzx");
	HX_VISIT_MEMBER_NAME(zxy,"zxy");
	HX_VISIT_MEMBER_NAME(zyx,"zyx");
	HX_VISIT_MEMBER_NAME(xy,"xy");
	HX_VISIT_MEMBER_NAME(xz,"xz");
	HX_VISIT_MEMBER_NAME(yx,"yx");
	HX_VISIT_MEMBER_NAME(yz,"yz");
	HX_VISIT_MEMBER_NAME(zx,"zx");
	HX_VISIT_MEMBER_NAME(zy,"zy");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(lengthSqr,"lengthSqr");
	HX_VISIT_MEMBER_NAME(normalized,"normalized");
	HX_VISIT_MEMBER_NAME(inverse,"inverse");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(z,"z");
}

Dynamic Vector3_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"z") ) { return z; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"up") ) { return inCallProp ? get_up() : up; }
		if (HX_FIELD_EQ(inName,"xy") ) { return inCallProp ? get_xy() : xy; }
		if (HX_FIELD_EQ(inName,"xz") ) { return inCallProp ? get_xz() : xz; }
		if (HX_FIELD_EQ(inName,"yx") ) { return inCallProp ? get_yx() : yx; }
		if (HX_FIELD_EQ(inName,"yz") ) { return inCallProp ? get_yz() : yz; }
		if (HX_FIELD_EQ(inName,"zx") ) { return inCallProp ? get_zx() : zx; }
		if (HX_FIELD_EQ(inName,"zy") ) { return inCallProp ? get_zy() : zy; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"one") ) { return inCallProp ? get_one() : one; }
		if (HX_FIELD_EQ(inName,"Dot") ) { return Dot_dyn(); }
		if (HX_FIELD_EQ(inName,"Min") ) { return Min_dyn(); }
		if (HX_FIELD_EQ(inName,"Max") ) { return Max_dyn(); }
		if (HX_FIELD_EQ(inName,"xzy") ) { return inCallProp ? get_xzy() : xzy; }
		if (HX_FIELD_EQ(inName,"yxz") ) { return inCallProp ? get_yxz() : yxz; }
		if (HX_FIELD_EQ(inName,"yzx") ) { return inCallProp ? get_yzx() : yzx; }
		if (HX_FIELD_EQ(inName,"zxy") ) { return inCallProp ? get_zxy() : zxy; }
		if (HX_FIELD_EQ(inName,"zyx") ) { return inCallProp ? get_zyx() : zyx; }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		if (HX_FIELD_EQ(inName,"Get") ) { return Get_dyn(); }
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		if (HX_FIELD_EQ(inName,"Sub") ) { return Sub_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"temp") ) { return inCallProp ? get_temp() : temp; }
		if (HX_FIELD_EQ(inName,"zero") ) { return inCallProp ? get_zero() : zero; }
		if (HX_FIELD_EQ(inName,"Lerp") ) { return Lerp_dyn(); }
		if (HX_FIELD_EQ(inName,"Set2") ) { return Set2_dyn(); }
		if (HX_FIELD_EQ(inName,"Set3") ) { return Set3_dyn(); }
		if (HX_FIELD_EQ(inName,"Set4") ) { return Set4_dyn(); }
		if (HX_FIELD_EQ(inName,"Add3") ) { return Add3_dyn(); }
		if (HX_FIELD_EQ(inName,"Step") ) { return Step_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"right") ) { return inCallProp ? get_right() : right; }
		if (HX_FIELD_EQ(inName,"Cross") ) { return Cross_dyn(); }
		if (HX_FIELD_EQ(inName,"Parse") ) { return Parse_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return inCallProp ? get_clone() : clone; }
		if (HX_FIELD_EQ(inName,"color") ) { return inCallProp ? get_color() : color; }
		if (HX_FIELD_EQ(inName,"Scale") ) { return Scale_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"get_up") ) { return get_up_dyn(); }
		if (HX_FIELD_EQ(inName,"get_xy") ) { return get_xy_dyn(); }
		if (HX_FIELD_EQ(inName,"get_xz") ) { return get_xz_dyn(); }
		if (HX_FIELD_EQ(inName,"get_yx") ) { return get_yx_dyn(); }
		if (HX_FIELD_EQ(inName,"get_yz") ) { return get_yz_dyn(); }
		if (HX_FIELD_EQ(inName,"get_zx") ) { return get_zx_dyn(); }
		if (HX_FIELD_EQ(inName,"get_zy") ) { return get_zy_dyn(); }
		if (HX_FIELD_EQ(inName,"length") ) { return inCallProp ? get_length() : length; }
		if (HX_FIELD_EQ(inName,"Invert") ) { return Invert_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_one") ) { return get_one_dyn(); }
		if (HX_FIELD_EQ(inName,"forward") ) { return inCallProp ? get_forward() : forward; }
		if (HX_FIELD_EQ(inName,"get_xzy") ) { return get_xzy_dyn(); }
		if (HX_FIELD_EQ(inName,"get_yxz") ) { return get_yxz_dyn(); }
		if (HX_FIELD_EQ(inName,"get_yzx") ) { return get_yzx_dyn(); }
		if (HX_FIELD_EQ(inName,"get_zxy") ) { return get_zxy_dyn(); }
		if (HX_FIELD_EQ(inName,"get_zyx") ) { return get_zyx_dyn(); }
		if (HX_FIELD_EQ(inName,"inverse") ) { return inCallProp ? get_inverse() : inverse; }
		if (HX_FIELD_EQ(inName,"Reflect") ) { return Reflect_dyn(); }
		if (HX_FIELD_EQ(inName,"ToArray") ) { return ToArray_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_temp") ) { return get_temp_dyn(); }
		if (HX_FIELD_EQ(inName,"get_zero") ) { return get_zero_dyn(); }
		if (HX_FIELD_EQ(inName,"Distance") ) { return Distance_dyn(); }
		if (HX_FIELD_EQ(inName,"SetColor") ) { return SetColor_dyn(); }
		if (HX_FIELD_EQ(inName,"Multiply") ) { return Multiply_dyn(); }
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_right") ) { return get_right_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clone") ) { return get_clone_dyn(); }
		if (HX_FIELD_EQ(inName,"get_color") ) { return get_color_dyn(); }
		if (HX_FIELD_EQ(inName,"lengthSqr") ) { return inCallProp ? get_lengthSqr() : lengthSqr; }
		if (HX_FIELD_EQ(inName,"Normalize") ) { return Normalize_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_length") ) { return get_length_dyn(); }
		if (HX_FIELD_EQ(inName,"normalized") ) { return inCallProp ? get_normalized() : normalized; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_forward") ) { return get_forward_dyn(); }
		if (HX_FIELD_EQ(inName,"get_inverse") ) { return get_inverse_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_lengthSqr") ) { return get_lengthSqr_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_normalized") ) { return get_normalized_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Vector3_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"z") ) { z=inValue.Cast< Float >(); return inValue; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"up") ) { up=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xy") ) { xy=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xz") ) { xz=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"yx") ) { yx=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"yz") ) { yz=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"zx") ) { zx=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"zy") ) { zy=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"one") ) { one=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xzy") ) { xzy=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"yxz") ) { yxz=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"yzx") ) { yzx=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"zxy") ) { zxy=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"zyx") ) { zyx=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"temp") ) { temp=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"zero") ) { zero=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"right") ) { right=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clone") ) { clone=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"color") ) { color=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"forward") ) { forward=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"inverse") ) { inverse=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"lengthSqr") ) { lengthSqr=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"normalized") ) { normalized=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Vector3_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("clone"));
	outFields->push(HX_CSTRING("color"));
	outFields->push(HX_CSTRING("xzy"));
	outFields->push(HX_CSTRING("yxz"));
	outFields->push(HX_CSTRING("yzx"));
	outFields->push(HX_CSTRING("zxy"));
	outFields->push(HX_CSTRING("zyx"));
	outFields->push(HX_CSTRING("xy"));
	outFields->push(HX_CSTRING("xz"));
	outFields->push(HX_CSTRING("yx"));
	outFields->push(HX_CSTRING("yz"));
	outFields->push(HX_CSTRING("zx"));
	outFields->push(HX_CSTRING("zy"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("lengthSqr"));
	outFields->push(HX_CSTRING("normalized"));
	outFields->push(HX_CSTRING("inverse"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("z"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("temp"),
	HX_CSTRING("get_temp"),
	HX_CSTRING("zero"),
	HX_CSTRING("get_zero"),
	HX_CSTRING("one"),
	HX_CSTRING("get_one"),
	HX_CSTRING("right"),
	HX_CSTRING("get_right"),
	HX_CSTRING("up"),
	HX_CSTRING("get_up"),
	HX_CSTRING("forward"),
	HX_CSTRING("get_forward"),
	HX_CSTRING("Dot"),
	HX_CSTRING("Distance"),
	HX_CSTRING("Cross"),
	HX_CSTRING("Lerp"),
	HX_CSTRING("Min"),
	HX_CSTRING("Max"),
	HX_CSTRING("Parse"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Vector3_obj,clone),HX_CSTRING("clone")},
	{hx::fsObject /*::haxor::math::Color*/ ,(int)offsetof(Vector3_obj,color),HX_CSTRING("color")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Vector3_obj,xzy),HX_CSTRING("xzy")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Vector3_obj,yxz),HX_CSTRING("yxz")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Vector3_obj,yzx),HX_CSTRING("yzx")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Vector3_obj,zxy),HX_CSTRING("zxy")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Vector3_obj,zyx),HX_CSTRING("zyx")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Vector3_obj,xy),HX_CSTRING("xy")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Vector3_obj,xz),HX_CSTRING("xz")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Vector3_obj,yx),HX_CSTRING("yx")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Vector3_obj,yz),HX_CSTRING("yz")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Vector3_obj,zx),HX_CSTRING("zx")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Vector3_obj,zy),HX_CSTRING("zy")},
	{hx::fsFloat,(int)offsetof(Vector3_obj,length),HX_CSTRING("length")},
	{hx::fsFloat,(int)offsetof(Vector3_obj,lengthSqr),HX_CSTRING("lengthSqr")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Vector3_obj,normalized),HX_CSTRING("normalized")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Vector3_obj,inverse),HX_CSTRING("inverse")},
	{hx::fsFloat,(int)offsetof(Vector3_obj,x),HX_CSTRING("x")},
	{hx::fsFloat,(int)offsetof(Vector3_obj,y),HX_CSTRING("y")},
	{hx::fsFloat,(int)offsetof(Vector3_obj,z),HX_CSTRING("z")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("clone"),
	HX_CSTRING("get_clone"),
	HX_CSTRING("color"),
	HX_CSTRING("get_color"),
	HX_CSTRING("xzy"),
	HX_CSTRING("get_xzy"),
	HX_CSTRING("yxz"),
	HX_CSTRING("get_yxz"),
	HX_CSTRING("yzx"),
	HX_CSTRING("get_yzx"),
	HX_CSTRING("zxy"),
	HX_CSTRING("get_zxy"),
	HX_CSTRING("zyx"),
	HX_CSTRING("get_zyx"),
	HX_CSTRING("xy"),
	HX_CSTRING("get_xy"),
	HX_CSTRING("xz"),
	HX_CSTRING("get_xz"),
	HX_CSTRING("yx"),
	HX_CSTRING("get_yx"),
	HX_CSTRING("yz"),
	HX_CSTRING("get_yz"),
	HX_CSTRING("zx"),
	HX_CSTRING("get_zx"),
	HX_CSTRING("zy"),
	HX_CSTRING("get_zy"),
	HX_CSTRING("length"),
	HX_CSTRING("get_length"),
	HX_CSTRING("lengthSqr"),
	HX_CSTRING("get_lengthSqr"),
	HX_CSTRING("normalized"),
	HX_CSTRING("get_normalized"),
	HX_CSTRING("inverse"),
	HX_CSTRING("get_inverse"),
	HX_CSTRING("x"),
	HX_CSTRING("y"),
	HX_CSTRING("z"),
	HX_CSTRING("Set"),
	HX_CSTRING("Set2"),
	HX_CSTRING("Set3"),
	HX_CSTRING("Set4"),
	HX_CSTRING("SetColor"),
	HX_CSTRING("Get"),
	HX_CSTRING("Add"),
	HX_CSTRING("Add3"),
	HX_CSTRING("Sub"),
	HX_CSTRING("Multiply"),
	HX_CSTRING("Step"),
	HX_CSTRING("Reflect"),
	HX_CSTRING("Invert"),
	HX_CSTRING("Scale"),
	HX_CSTRING("Normalize"),
	HX_CSTRING("ToArray"),
	HX_CSTRING("ToString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Vector3_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Vector3_obj::temp,"temp");
	HX_MARK_MEMBER_NAME(Vector3_obj::zero,"zero");
	HX_MARK_MEMBER_NAME(Vector3_obj::one,"one");
	HX_MARK_MEMBER_NAME(Vector3_obj::right,"right");
	HX_MARK_MEMBER_NAME(Vector3_obj::up,"up");
	HX_MARK_MEMBER_NAME(Vector3_obj::forward,"forward");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Vector3_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Vector3_obj::temp,"temp");
	HX_VISIT_MEMBER_NAME(Vector3_obj::zero,"zero");
	HX_VISIT_MEMBER_NAME(Vector3_obj::one,"one");
	HX_VISIT_MEMBER_NAME(Vector3_obj::right,"right");
	HX_VISIT_MEMBER_NAME(Vector3_obj::up,"up");
	HX_VISIT_MEMBER_NAME(Vector3_obj::forward,"forward");
};

#endif

Class Vector3_obj::__mClass;

void Vector3_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.math.Vector3"), hx::TCanCast< Vector3_obj> ,sStaticFields,sMemberFields,
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

void Vector3_obj::__boot()
{
}

} // end namespace haxor
} // end namespace math
