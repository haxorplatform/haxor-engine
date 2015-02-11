#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_math_AABB3
#include <haxor/math/AABB3.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace math{

Void AABB3_obj::__construct(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z,hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height,hx::Null< Float >  __o_p_depth)
{
HX_STACK_FRAME("haxor.math.AABB3","new",0x13a3b68b,"haxor.math.AABB3.new","haxor/math/AABB3.hx",174,0x4fae5fa5)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_x,"p_x")
HX_STACK_ARG(__o_p_y,"p_y")
HX_STACK_ARG(__o_p_z,"p_z")
HX_STACK_ARG(__o_p_width,"p_width")
HX_STACK_ARG(__o_p_height,"p_height")
HX_STACK_ARG(__o_p_depth,"p_depth")
Float p_x = __o_p_x.Default(0);
Float p_y = __o_p_y.Default(0);
Float p_z = __o_p_z.Default(0);
Float p_width = __o_p_width.Default(0);
Float p_height = __o_p_height.Default(0);
Float p_depth = __o_p_depth.Default(0);
{
	HX_STACK_LINE(175)
	this->m_xMin = p_x;
	HX_STACK_LINE(176)
	this->m_yMin = p_y;
	HX_STACK_LINE(177)
	this->m_zMin = p_y;
	HX_STACK_LINE(178)
	this->m_xMax = (this->m_xMin + p_width);
	HX_STACK_LINE(179)
	this->m_yMax = (this->m_yMin + p_height);
	HX_STACK_LINE(180)
	this->m_zMax = (this->m_zMin + p_depth);
}
;
	return null();
}

//AABB3_obj::~AABB3_obj() { }

Dynamic AABB3_obj::__CreateEmpty() { return  new AABB3_obj; }
hx::ObjectPtr< AABB3_obj > AABB3_obj::__new(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z,hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height,hx::Null< Float >  __o_p_depth)
{  hx::ObjectPtr< AABB3_obj > result = new AABB3_obj();
	result->__construct(__o_p_x,__o_p_y,__o_p_z,__o_p_width,__o_p_height,__o_p_depth);
	return result;}

Dynamic AABB3_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AABB3_obj > result = new AABB3_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}

::haxor::math::AABB3 AABB3_obj::get_clone( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_clone",0xc967c81f,"haxor.math.AABB3.get_clone","haxor/math/AABB3.hx",77,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(77)
	return ::haxor::math::AABB3_obj::FromMinMax(this->m_xMin,this->m_xMax,this->m_yMin,this->m_yMax,this->m_zMin,this->m_zMax,null());
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_clone,return )

::haxor::math::Vector3 AABB3_obj::get_min( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_min",0x793db1d4,"haxor.math.AABB3.get_min","haxor/math/AABB3.hx",81,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(81)
	return ::haxor::math::Vector3_obj::__new(this->m_xMin,this->m_yMin,null());
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_min,return )

::haxor::math::Vector3 AABB3_obj::set_min( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.math.AABB3","set_min",0x6c3f42e0,"haxor.math.AABB3.set_min","haxor/math/AABB3.hx",82,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(82)
	this->set_xMin(v->x);
	HX_STACK_LINE(82)
	this->set_yMin(v->y);
	HX_STACK_LINE(82)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_min,return )

::haxor::math::Vector3 AABB3_obj::get_max( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_max",0x793daae6,"haxor.math.AABB3.get_max","haxor/math/AABB3.hx",85,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(85)
	return ::haxor::math::Vector3_obj::__new(this->m_xMax,this->m_yMax,null());
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_max,return )

::haxor::math::Vector3 AABB3_obj::set_max( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.math.AABB3","set_max",0x6c3f3bf2,"haxor.math.AABB3.set_max","haxor/math/AABB3.hx",86,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(86)
	this->set_xMax(v->x);
	HX_STACK_LINE(86)
	this->set_yMax(v->y);
	HX_STACK_LINE(86)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_max,return )

Float AABB3_obj::get_xMin( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_xMin",0xa3edfd78,"haxor.math.AABB3.get_xMin","haxor/math/AABB3.hx",89,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(89)
	return this->m_xMin;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_xMin,return )

Float AABB3_obj::set_xMin( Float v){
	HX_STACK_FRAME("haxor.math.AABB3","set_xMin",0x524b56ec,"haxor.math.AABB3.set_xMin","haxor/math/AABB3.hx",90,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(90)
	this->m_xMin = v;
	HX_STACK_LINE(90)
	this->Validate();
	HX_STACK_LINE(90)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_xMin,return )

Float AABB3_obj::get_yMin( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_yMin",0xa4973417,"haxor.math.AABB3.get_yMin","haxor/math/AABB3.hx",94,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(94)
	return this->m_yMin;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_yMin,return )

Float AABB3_obj::set_yMin( Float v){
	HX_STACK_FRAME("haxor.math.AABB3","set_yMin",0x52f48d8b,"haxor.math.AABB3.set_yMin","haxor/math/AABB3.hx",95,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(95)
	this->m_yMin = v;
	HX_STACK_LINE(95)
	this->Validate();
	HX_STACK_LINE(95)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_yMin,return )

Float AABB3_obj::get_zMin( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_zMin",0xa5406ab6,"haxor.math.AABB3.get_zMin","haxor/math/AABB3.hx",99,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(99)
	return this->m_zMin;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_zMin,return )

Float AABB3_obj::set_zMin( Float v){
	HX_STACK_FRAME("haxor.math.AABB3","set_zMin",0x539dc42a,"haxor.math.AABB3.set_zMin","haxor/math/AABB3.hx",100,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(100)
	this->m_zMin = v;
	HX_STACK_LINE(100)
	this->Validate();
	HX_STACK_LINE(100)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_zMin,return )

Float AABB3_obj::get_xMax( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_xMax",0xa3edf68a,"haxor.math.AABB3.get_xMax","haxor/math/AABB3.hx",104,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(104)
	return this->m_xMax;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_xMax,return )

Float AABB3_obj::set_xMax( Float v){
	HX_STACK_FRAME("haxor.math.AABB3","set_xMax",0x524b4ffe,"haxor.math.AABB3.set_xMax","haxor/math/AABB3.hx",105,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(105)
	this->m_xMax = v;
	HX_STACK_LINE(105)
	this->Validate();
	HX_STACK_LINE(105)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_xMax,return )

Float AABB3_obj::get_yMax( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_yMax",0xa4972d29,"haxor.math.AABB3.get_yMax","haxor/math/AABB3.hx",109,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(109)
	return this->m_yMax;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_yMax,return )

Float AABB3_obj::set_yMax( Float v){
	HX_STACK_FRAME("haxor.math.AABB3","set_yMax",0x52f4869d,"haxor.math.AABB3.set_yMax","haxor/math/AABB3.hx",110,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(110)
	this->m_yMax = v;
	HX_STACK_LINE(110)
	this->Validate();
	HX_STACK_LINE(110)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_yMax,return )

Float AABB3_obj::get_zMax( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_zMax",0xa54063c8,"haxor.math.AABB3.get_zMax","haxor/math/AABB3.hx",114,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(114)
	return this->m_zMax;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_zMax,return )

Float AABB3_obj::set_zMax( Float v){
	HX_STACK_FRAME("haxor.math.AABB3","set_zMax",0x539dbd3c,"haxor.math.AABB3.set_zMax","haxor/math/AABB3.hx",115,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(115)
	this->m_zMax = v;
	HX_STACK_LINE(115)
	this->Validate();
	HX_STACK_LINE(115)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_zMax,return )

::haxor::math::Vector3 AABB3_obj::get_center( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_center",0x68f49ad3,"haxor.math.AABB3.get_center","haxor/math/AABB3.hx",119,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(119)
	return ::haxor::math::AABB3_obj::Center(hx::ObjectPtr<OBJ_>(this),null());
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_center,return )

::haxor::math::Vector3 AABB3_obj::set_center( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.math.AABB3","set_center",0x6c723947,"haxor.math.AABB3.set_center","haxor/math/AABB3.hx",121,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(122)
	Float hw;		HX_STACK_VAR(hw,"hw");
	struct _Function_1_1{
		inline static Float Block( hx::ObjectPtr< ::haxor::math::AABB3_obj > __this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/AABB3.hx",122,0x4fae5fa5)
			{
				HX_STACK_LINE(122)
				Float p_a = (__this->m_xMax - __this->m_xMin);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(122)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	HX_STACK_LINE(122)
	hw = (_Function_1_1::Block(this) * 0.5);
	HX_STACK_LINE(123)
	Float hh;		HX_STACK_VAR(hh,"hh");
	struct _Function_1_2{
		inline static Float Block( hx::ObjectPtr< ::haxor::math::AABB3_obj > __this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/AABB3.hx",123,0x4fae5fa5)
			{
				HX_STACK_LINE(123)
				Float p_a = (__this->m_yMax - __this->m_yMin);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(123)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	HX_STACK_LINE(123)
	hh = (_Function_1_2::Block(this) * 0.5);
	HX_STACK_LINE(124)
	Float hd;		HX_STACK_VAR(hd,"hd");
	struct _Function_1_3{
		inline static Float Block( hx::ObjectPtr< ::haxor::math::AABB3_obj > __this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/AABB3.hx",124,0x4fae5fa5)
			{
				HX_STACK_LINE(124)
				Float p_a = (__this->m_zMax - __this->m_zMin);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(124)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	HX_STACK_LINE(124)
	hd = (_Function_1_3::Block(this) * 0.5);
	HX_STACK_LINE(125)
	this->m_xMin = (v->x - hw);
	HX_STACK_LINE(126)
	this->m_xMax = (v->x + hw);
	HX_STACK_LINE(127)
	this->m_yMin = (v->y - hh);
	HX_STACK_LINE(128)
	this->m_yMax = (v->y + hh);
	HX_STACK_LINE(129)
	this->m_zMin = (v->z - hd);
	HX_STACK_LINE(130)
	this->m_zMax = (v->z + hd);
	HX_STACK_LINE(131)
	this->Validate();
	HX_STACK_LINE(132)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_center,return )

Float AABB3_obj::get_x( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_x",0x0516ac3a,"haxor.math.AABB3.get_x","haxor/math/AABB3.hx",136,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(136)
	return this->m_xMin;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_x,return )

Float AABB3_obj::set_x( Float v){
	HX_STACK_FRAME("haxor.math.AABB3","set_x",0xede5a246,"haxor.math.AABB3.set_x","haxor/math/AABB3.hx",137,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(137)
	this->set_xMin(v);
	HX_STACK_LINE(137)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_x,return )

Float AABB3_obj::get_y( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_y",0x0516ac3b,"haxor.math.AABB3.get_y","haxor/math/AABB3.hx",140,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(140)
	return this->m_yMin;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_y,return )

Float AABB3_obj::set_y( Float v){
	HX_STACK_FRAME("haxor.math.AABB3","set_y",0xede5a247,"haxor.math.AABB3.set_y","haxor/math/AABB3.hx",141,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(141)
	this->set_yMin(v);
	HX_STACK_LINE(141)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_y,return )

Float AABB3_obj::get_z( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_z",0x0516ac3c,"haxor.math.AABB3.get_z","haxor/math/AABB3.hx",144,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(144)
	return this->m_zMin;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_z,return )

Float AABB3_obj::set_z( Float v){
	HX_STACK_FRAME("haxor.math.AABB3","set_z",0xede5a248,"haxor.math.AABB3.set_z","haxor/math/AABB3.hx",145,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(145)
	this->set_zMin(v);
	HX_STACK_LINE(145)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_z,return )

Float AABB3_obj::get_width( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_width",0x4b676ac8,"haxor.math.AABB3.get_width","haxor/math/AABB3.hx",149,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(149)
	Float p_a = (this->m_xMax - this->m_xMin);		HX_STACK_VAR(p_a,"p_a");
	HX_STACK_LINE(149)
	if (((p_a < (int)0))){
		HX_STACK_LINE(149)
		return -(p_a);
	}
	else{
		HX_STACK_LINE(149)
		return p_a;
	}
	HX_STACK_LINE(149)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_width,return )

Float AABB3_obj::set_width( Float v){
	HX_STACK_FRAME("haxor.math.AABB3","set_width",0x2eb856d4,"haxor.math.AABB3.set_width","haxor/math/AABB3.hx",150,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(150)
	this->set_xMax((this->m_xMin + v));
	HX_STACK_LINE(150)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_width,return )

Float AABB3_obj::get_height( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_height",0x65657ce5,"haxor.math.AABB3.get_height","haxor/math/AABB3.hx",153,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(153)
	Float p_a = (this->m_yMax - this->m_yMin);		HX_STACK_VAR(p_a,"p_a");
	HX_STACK_LINE(153)
	if (((p_a < (int)0))){
		HX_STACK_LINE(153)
		return -(p_a);
	}
	else{
		HX_STACK_LINE(153)
		return p_a;
	}
	HX_STACK_LINE(153)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_height,return )

Float AABB3_obj::set_height( Float v){
	HX_STACK_FRAME("haxor.math.AABB3","set_height",0x68e31b59,"haxor.math.AABB3.set_height","haxor/math/AABB3.hx",154,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(154)
	this->set_yMax((this->m_yMin + v));
	HX_STACK_LINE(154)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_height,return )

Float AABB3_obj::get_depth( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_depth",0x582ea5c5,"haxor.math.AABB3.get_depth","haxor/math/AABB3.hx",157,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_LINE(157)
	Float p_a = (this->m_zMax - this->m_zMin);		HX_STACK_VAR(p_a,"p_a");
	HX_STACK_LINE(157)
	if (((p_a < (int)0))){
		HX_STACK_LINE(157)
		return -(p_a);
	}
	else{
		HX_STACK_LINE(157)
		return p_a;
	}
	HX_STACK_LINE(157)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_depth,return )

Float AABB3_obj::set_depth( Float v){
	HX_STACK_FRAME("haxor.math.AABB3","set_depth",0x3b7f91d1,"haxor.math.AABB3.set_depth","haxor/math/AABB3.hx",158,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(158)
	this->set_zMax((this->m_zMin + v));
	HX_STACK_LINE(158)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_depth,return )

::haxor::math::Vector3 AABB3_obj::get_size( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_size",0xa0b53a3f,"haxor.math.AABB3.get_size","haxor/math/AABB3.hx",161,0x4fae5fa5)
	HX_STACK_THIS(this)
	struct _Function_1_1{
		inline static Float Block( hx::ObjectPtr< ::haxor::math::AABB3_obj > __this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/AABB3.hx",161,0x4fae5fa5)
			{
				HX_STACK_LINE(161)
				Float p_a = (__this->m_xMax - __this->m_xMin);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(161)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	struct _Function_1_2{
		inline static Float Block( hx::ObjectPtr< ::haxor::math::AABB3_obj > __this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/AABB3.hx",161,0x4fae5fa5)
			{
				HX_STACK_LINE(161)
				Float p_a = (__this->m_yMax - __this->m_yMin);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(161)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	struct _Function_1_3{
		inline static Float Block( hx::ObjectPtr< ::haxor::math::AABB3_obj > __this){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/AABB3.hx",161,0x4fae5fa5)
			{
				HX_STACK_LINE(161)
				Float p_a = (__this->m_zMax - __this->m_zMin);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(161)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	HX_STACK_LINE(161)
	return ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0)->Set(_Function_1_1::Block(this),_Function_1_2::Block(this),_Function_1_3::Block(this));
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_size,return )

::haxor::math::Vector3 AABB3_obj::set_size( ::haxor::math::Vector3 v){
	HX_STACK_FRAME("haxor.math.AABB3","set_size",0x4f1293b3,"haxor.math.AABB3.set_size","haxor/math/AABB3.hx",162,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(162)
	{
		HX_STACK_LINE(162)
		Float v1 = v->x;		HX_STACK_VAR(v1,"v1");
		HX_STACK_LINE(162)
		this->set_xMax((this->m_xMin + v1));
		HX_STACK_LINE(162)
		v1;
	}
	HX_STACK_LINE(162)
	{
		HX_STACK_LINE(162)
		Float v1 = v->y;		HX_STACK_VAR(v1,"v1");
		HX_STACK_LINE(162)
		this->set_yMax((this->m_yMin + v1));
		HX_STACK_LINE(162)
		v1;
	}
	HX_STACK_LINE(162)
	{
		HX_STACK_LINE(162)
		Float v1 = v->z;		HX_STACK_VAR(v1,"v1");
		HX_STACK_LINE(162)
		this->set_zMax((this->m_zMin + v1));
		HX_STACK_LINE(162)
		v1;
	}
	HX_STACK_LINE(162)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,set_size,return )

Void AABB3_obj::Validate( ){
{
		HX_STACK_FRAME("haxor.math.AABB3","Validate",0xb33c6aab,"haxor.math.AABB3.Validate","haxor/math/AABB3.hx",187,0x4fae5fa5)
		HX_STACK_THIS(this)
		HX_STACK_LINE(188)
		Float x0 = this->m_xMin;		HX_STACK_VAR(x0,"x0");
		HX_STACK_LINE(189)
		Float x1 = this->m_xMax;		HX_STACK_VAR(x1,"x1");
		HX_STACK_LINE(190)
		Float y0 = this->m_yMin;		HX_STACK_VAR(y0,"y0");
		HX_STACK_LINE(191)
		Float y1 = this->m_yMax;		HX_STACK_VAR(y1,"y1");
		HX_STACK_LINE(192)
		Float z0 = this->m_zMin;		HX_STACK_VAR(z0,"z0");
		HX_STACK_LINE(193)
		Float z1 = this->m_zMax;		HX_STACK_VAR(z1,"z1");
		HX_STACK_LINE(194)
		if (((x0 <= x1))){
			HX_STACK_LINE(194)
			this->m_xMin = x0;
			HX_STACK_LINE(194)
			this->m_xMax = x1;
		}
		else{
			HX_STACK_LINE(194)
			this->m_xMin = x1;
			HX_STACK_LINE(194)
			this->m_xMax = x0;
		}
		HX_STACK_LINE(195)
		if (((y0 <= y1))){
			HX_STACK_LINE(195)
			this->m_yMin = y0;
			HX_STACK_LINE(195)
			this->m_yMax = y1;
		}
		else{
			HX_STACK_LINE(195)
			this->m_yMin = y1;
			HX_STACK_LINE(195)
			this->m_yMax = y0;
		}
		HX_STACK_LINE(196)
		if (((z0 <= z1))){
			HX_STACK_LINE(196)
			this->m_zMin = z0;
			HX_STACK_LINE(196)
			this->m_zMax = z1;
		}
		else{
			HX_STACK_LINE(196)
			this->m_zMin = z1;
			HX_STACK_LINE(196)
			this->m_zMax = z0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,Validate,(void))

::haxor::math::AABB3 AABB3_obj::Add( ::haxor::math::AABB3 p_v){
	HX_STACK_FRAME("haxor.math.AABB3","Add",0x1381902c,"haxor.math.AABB3.Add","haxor/math/AABB3.hx",205,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(206)
	Float _g = ::Math_obj::max(p_v->m_xMax,this->m_xMax);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(206)
	this->m_xMax = _g;
	HX_STACK_LINE(207)
	Float _g1 = ::Math_obj::min(p_v->m_xMin,this->m_xMin);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(207)
	this->m_xMin = _g1;
	HX_STACK_LINE(208)
	Float _g2 = ::Math_obj::max(p_v->m_yMax,this->m_yMax);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(208)
	this->m_yMax = _g2;
	HX_STACK_LINE(209)
	Float _g3 = ::Math_obj::min(p_v->m_yMin,this->m_yMin);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(209)
	this->m_yMin = _g3;
	HX_STACK_LINE(210)
	Float _g4 = ::Math_obj::max(p_v->m_zMax,this->m_zMax);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(210)
	this->m_zMax = _g4;
	HX_STACK_LINE(211)
	Float _g5 = ::Math_obj::min(p_v->m_zMin,this->m_zMin);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(211)
	this->m_zMin = _g5;
	HX_STACK_LINE(212)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,Add,return )

::haxor::math::AABB3 AABB3_obj::Set( hx::Null< Float >  __o_p_xmin,hx::Null< Float >  __o_p_xmax,hx::Null< Float >  __o_p_ymin,hx::Null< Float >  __o_p_ymax,hx::Null< Float >  __o_p_zmin,hx::Null< Float >  __o_p_zmax){
Float p_xmin = __o_p_xmin.Default(0);
Float p_xmax = __o_p_xmax.Default(0);
Float p_ymin = __o_p_ymin.Default(0);
Float p_ymax = __o_p_ymax.Default(0);
Float p_zmin = __o_p_zmin.Default(0);
Float p_zmax = __o_p_zmax.Default(0);
	HX_STACK_FRAME("haxor.math.AABB3","Set",0x138f39ad,"haxor.math.AABB3.Set","haxor/math/AABB3.hx",226,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_xmin,"p_xmin")
	HX_STACK_ARG(p_xmax,"p_xmax")
	HX_STACK_ARG(p_ymin,"p_ymin")
	HX_STACK_ARG(p_ymax,"p_ymax")
	HX_STACK_ARG(p_zmin,"p_zmin")
	HX_STACK_ARG(p_zmax,"p_zmax")
{
		HX_STACK_LINE(227)
		this->m_xMin = p_xmin;
		HX_STACK_LINE(228)
		this->m_yMin = p_ymin;
		HX_STACK_LINE(229)
		this->m_zMin = p_zmin;
		HX_STACK_LINE(230)
		this->m_xMax = p_xmax;
		HX_STACK_LINE(231)
		this->m_yMax = p_ymax;
		HX_STACK_LINE(232)
		this->m_zMax = p_zmax;
		HX_STACK_LINE(233)
		this->Validate();
		HX_STACK_LINE(234)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC6(AABB3_obj,Set,return )

::haxor::math::AABB3 AABB3_obj::Set3( ::haxor::math::Vector3 p_min,::haxor::math::Vector3 p_max){
	HX_STACK_FRAME("haxor.math.AABB3","Set3",0x09c33de6,"haxor.math.AABB3.Set3","haxor/math/AABB3.hx",245,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_min,"p_min")
	HX_STACK_ARG(p_max,"p_max")
	HX_STACK_LINE(245)
	return this->Set(p_min->x,p_max->x,p_min->y,p_max->y,p_min->z,p_max->z);
}


HX_DEFINE_DYNAMIC_FUNC2(AABB3_obj,Set3,return )

::haxor::math::AABB3 AABB3_obj::SetAABB3( ::haxor::math::AABB3 p_v){
	HX_STACK_FRAME("haxor.math.AABB3","SetAABB3",0xc19474c6,"haxor.math.AABB3.SetAABB3","haxor/math/AABB3.hx",254,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(255)
	this->m_xMin = p_v->m_xMin;
	HX_STACK_LINE(256)
	this->m_yMin = p_v->m_yMin;
	HX_STACK_LINE(257)
	this->m_zMin = p_v->m_zMin;
	HX_STACK_LINE(258)
	this->m_xMax = p_v->m_xMax;
	HX_STACK_LINE(259)
	this->m_yMax = p_v->m_yMax;
	HX_STACK_LINE(260)
	this->m_zMax = p_v->m_zMax;
	HX_STACK_LINE(261)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,SetAABB3,return )

::haxor::math::AABB3 AABB3_obj::SetXYZWHD( hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z,hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height,hx::Null< Float >  __o_p_depth){
Float p_x = __o_p_x.Default(0);
Float p_y = __o_p_y.Default(0);
Float p_z = __o_p_z.Default(0);
Float p_width = __o_p_width.Default(0);
Float p_height = __o_p_height.Default(0);
Float p_depth = __o_p_depth.Default(0);
	HX_STACK_FRAME("haxor.math.AABB3","SetXYZWHD",0xb41211e7,"haxor.math.AABB3.SetXYZWHD","haxor/math/AABB3.hx",273,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_ARG(p_z,"p_z")
	HX_STACK_ARG(p_width,"p_width")
	HX_STACK_ARG(p_height,"p_height")
	HX_STACK_ARG(p_depth,"p_depth")
{
		HX_STACK_LINE(274)
		this->m_xMin = p_x;
		HX_STACK_LINE(275)
		this->m_yMin = p_y;
		HX_STACK_LINE(276)
		this->m_zMin = p_y;
		HX_STACK_LINE(277)
		this->m_xMax = (this->m_xMin + p_width);
		HX_STACK_LINE(278)
		this->m_yMax = (this->m_yMin + p_height);
		HX_STACK_LINE(279)
		this->m_zMax = (this->m_zMin + p_depth);
		HX_STACK_LINE(280)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC6(AABB3_obj,SetXYZWHD,return )

::haxor::math::AABB3 AABB3_obj::Encapsulate( ::haxor::math::Vector3 p_point){
	HX_STACK_FRAME("haxor.math.AABB3","Encapsulate",0x3a9b29dc,"haxor.math.AABB3.Encapsulate","haxor/math/AABB3.hx",287,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_point,"p_point")
	HX_STACK_LINE(287)
	return this->Encapsulate3(p_point->x,p_point->y,p_point->z);
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,Encapsulate,return )

::haxor::math::AABB3 AABB3_obj::Encapsulate3( hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z){
Float p_x = __o_p_x.Default(0);
Float p_y = __o_p_y.Default(0);
Float p_z = __o_p_z.Default(0);
	HX_STACK_FRAME("haxor.math.AABB3","Encapsulate3",0x0d2976d7,"haxor.math.AABB3.Encapsulate3","haxor/math/AABB3.hx",296,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_ARG(p_z,"p_z")
{
		HX_STACK_LINE(297)
		Float _g = ::Math_obj::min(p_x,this->m_xMin);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(297)
		this->m_xMin = _g;
		HX_STACK_LINE(298)
		Float _g1 = ::Math_obj::max(p_x,this->m_xMax);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(298)
		this->m_xMax = _g1;
		HX_STACK_LINE(299)
		Float _g2 = ::Math_obj::min(p_y,this->m_yMin);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(299)
		this->m_yMin = _g2;
		HX_STACK_LINE(300)
		Float _g3 = ::Math_obj::max(p_y,this->m_yMax);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(300)
		this->m_yMax = _g3;
		HX_STACK_LINE(301)
		Float _g4 = ::Math_obj::min(p_z,this->m_zMin);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(301)
		this->m_zMin = _g4;
		HX_STACK_LINE(302)
		Float _g5 = ::Math_obj::max(p_z,this->m_zMax);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(302)
		this->m_zMax = _g5;
		HX_STACK_LINE(303)
		this->Validate();
		HX_STACK_LINE(304)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC3(AABB3_obj,Encapsulate3,return )

::String AABB3_obj::ToString( hx::Null< int >  __o_p_places){
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.math.AABB3","ToString",0xe6c76ac1,"haxor.math.AABB3.ToString","haxor/math/AABB3.hx",313,0x4fae5fa5)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(314)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(314)
		{
			HX_STACK_LINE(314)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(314)
			Float _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(314)
			{
				HX_STACK_LINE(314)
				Float p_v = (this->m_xMin * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(314)
				_g = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(314)
			_g1 = (Float(_g) / Float(d));
		}
		HX_STACK_LINE(314)
		::String s0 = (_g1 + HX_CSTRING(""));		HX_STACK_VAR(s0,"s0");
		HX_STACK_LINE(315)
		Float _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(315)
		{
			HX_STACK_LINE(315)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(315)
			Float _g2;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(315)
			{
				HX_STACK_LINE(315)
				Float p_v = (this->m_xMax * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(315)
				_g2 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(315)
			_g3 = (Float(_g2) / Float(d));
		}
		HX_STACK_LINE(315)
		::String s1 = (_g3 + HX_CSTRING(""));		HX_STACK_VAR(s1,"s1");
		HX_STACK_LINE(316)
		Float _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(316)
		{
			HX_STACK_LINE(316)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(316)
			Float _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(316)
			{
				HX_STACK_LINE(316)
				Float p_v = (this->m_yMin * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(316)
				_g4 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(316)
			_g5 = (Float(_g4) / Float(d));
		}
		HX_STACK_LINE(316)
		::String s2 = (_g5 + HX_CSTRING(""));		HX_STACK_VAR(s2,"s2");
		HX_STACK_LINE(317)
		Float _g7;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(317)
		{
			HX_STACK_LINE(317)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(317)
			Float _g6;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(317)
			{
				HX_STACK_LINE(317)
				Float p_v = (this->m_yMax * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(317)
				_g6 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(317)
			_g7 = (Float(_g6) / Float(d));
		}
		HX_STACK_LINE(317)
		::String s3 = (_g7 + HX_CSTRING(""));		HX_STACK_VAR(s3,"s3");
		HX_STACK_LINE(318)
		Float _g9;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(318)
		{
			HX_STACK_LINE(318)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(318)
			Float _g8;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(318)
			{
				HX_STACK_LINE(318)
				Float p_v = (this->m_zMin * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(318)
				_g8 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(318)
			_g9 = (Float(_g8) / Float(d));
		}
		HX_STACK_LINE(318)
		::String s4 = (_g9 + HX_CSTRING(""));		HX_STACK_VAR(s4,"s4");
		HX_STACK_LINE(319)
		Float _g11;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(319)
		{
			HX_STACK_LINE(319)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(319)
			Float _g10;		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(319)
			{
				HX_STACK_LINE(319)
				Float p_v = (this->m_zMax * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(319)
				_g10 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(319)
			_g11 = (Float(_g10) / Float(d));
		}
		HX_STACK_LINE(319)
		::String s5 = (_g11 + HX_CSTRING(""));		HX_STACK_VAR(s5,"s5");
		HX_STACK_LINE(320)
		return ((((((((((((HX_CSTRING("[") + s0) + HX_CSTRING(",")) + s1) + HX_CSTRING("|")) + s2) + HX_CSTRING(",")) + s3) + HX_CSTRING("|")) + s4) + HX_CSTRING(",")) + s5) + HX_CSTRING("]"));
	}
}


HX_DEFINE_DYNAMIC_FUNC1(AABB3_obj,ToString,return )

::haxor::math::AABB3 AABB3_obj::temp;

::haxor::math::AABB3 AABB3_obj::get_temp( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_temp",0xa15b5c92,"haxor.math.AABB3.get_temp","haxor/math/AABB3.hx",16,0x4fae5fa5)
	HX_STACK_LINE(16)
	::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(16)
	int _g = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(16)
	return _this->m_aabb3->__get(_g).StaticCast< ::haxor::math::AABB3 >();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_temp,return )

::haxor::math::Vector3 AABB3_obj::Center( ::haxor::math::AABB3 p_b,::haxor::math::Vector3 p_result){
	HX_STACK_FRAME("haxor.math.AABB3","Center",0x05ffa0aa,"haxor.math.AABB3.Center","haxor/math/AABB3.hx",25,0x4fae5fa5)
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(26)
	::haxor::math::Vector3 v;		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(26)
	if (((p_result == null()))){
		HX_STACK_LINE(26)
		v = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);
	}
	else{
		HX_STACK_LINE(26)
		v = p_result;
	}
	HX_STACK_LINE(27)
	return v->Set((p_b->m_xMin + (((p_b->m_xMax - p_b->m_xMin)) * 0.5)),(p_b->m_yMin + (((p_b->m_yMax - p_b->m_yMin)) * 0.5)),(p_b->m_zMin + (((p_b->m_zMax - p_b->m_zMin)) * 0.5)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(AABB3_obj,Center,return )

::haxor::math::AABB3 AABB3_obj::FromMinMax( Float p_xmin,Float p_xmax,Float p_ymin,Float p_ymax,Float p_zmin,Float p_zmax,::haxor::math::AABB3 p_result){
	HX_STACK_FRAME("haxor.math.AABB3","FromMinMax",0xff708691,"haxor.math.AABB3.FromMinMax","haxor/math/AABB3.hx",44,0x4fae5fa5)
	HX_STACK_ARG(p_xmin,"p_xmin")
	HX_STACK_ARG(p_xmax,"p_xmax")
	HX_STACK_ARG(p_ymin,"p_ymin")
	HX_STACK_ARG(p_ymax,"p_ymax")
	HX_STACK_ARG(p_zmin,"p_zmin")
	HX_STACK_ARG(p_zmax,"p_zmax")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(45)
	::haxor::math::AABB3 b;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(45)
	if (((p_result == null()))){
		HX_STACK_LINE(45)
		b = ::haxor::math::AABB3_obj::__new(null(),null(),null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(45)
		b = p_result;
	}
	HX_STACK_LINE(46)
	return b->Set(p_xmin,p_xmax,p_ymin,p_ymax,p_zmin,p_zmax);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(AABB3_obj,FromMinMax,return )

::haxor::math::AABB3 AABB3_obj::FromCenter( Float p_x,Float p_y,Float p_z,Float p_width,Float p_height,Float p_depth,::haxor::math::AABB3 p_result){
	HX_STACK_FRAME("haxor.math.AABB3","FromCenter",0xb2623434,"haxor.math.AABB3.FromCenter","haxor/math/AABB3.hx",60,0x4fae5fa5)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_ARG(p_z,"p_z")
	HX_STACK_ARG(p_width,"p_width")
	HX_STACK_ARG(p_height,"p_height")
	HX_STACK_ARG(p_depth,"p_depth")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(61)
	Float w2 = (p_width * 0.5);		HX_STACK_VAR(w2,"w2");
	HX_STACK_LINE(62)
	Float h2 = (p_height * 0.5);		HX_STACK_VAR(h2,"h2");
	HX_STACK_LINE(63)
	Float d2 = (p_depth * 0.5);		HX_STACK_VAR(d2,"d2");
	HX_STACK_LINE(64)
	return ::haxor::math::AABB3_obj::FromMinMax((p_x - w2),(p_x + w2),(p_y - h2),(p_y + h2),(p_z - d2),(p_z + d2),p_result);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(AABB3_obj,FromCenter,return )

::haxor::math::AABB3 AABB3_obj::empty;

::haxor::math::AABB3 AABB3_obj::get_empty( ){
	HX_STACK_FRAME("haxor.math.AABB3","get_empty",0xf0deef4f,"haxor.math.AABB3.get_empty","haxor/math/AABB3.hx",71,0x4fae5fa5)
	HX_STACK_LINE(71)
	return ::haxor::math::AABB3_obj::__new(null(),null(),null(),null(),null(),null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AABB3_obj,get_empty,return )


AABB3_obj::AABB3_obj()
{
}

void AABB3_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AABB3);
	HX_MARK_MEMBER_NAME(clone,"clone");
	HX_MARK_MEMBER_NAME(m_xMin,"m_xMin");
	HX_MARK_MEMBER_NAME(m_yMin,"m_yMin");
	HX_MARK_MEMBER_NAME(m_zMin,"m_zMin");
	HX_MARK_MEMBER_NAME(m_xMax,"m_xMax");
	HX_MARK_MEMBER_NAME(m_yMax,"m_yMax");
	HX_MARK_MEMBER_NAME(m_zMax,"m_zMax");
	HX_MARK_END_CLASS();
}

void AABB3_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(clone,"clone");
	HX_VISIT_MEMBER_NAME(m_xMin,"m_xMin");
	HX_VISIT_MEMBER_NAME(m_yMin,"m_yMin");
	HX_VISIT_MEMBER_NAME(m_zMin,"m_zMin");
	HX_VISIT_MEMBER_NAME(m_xMax,"m_xMax");
	HX_VISIT_MEMBER_NAME(m_yMax,"m_yMax");
	HX_VISIT_MEMBER_NAME(m_zMax,"m_zMax");
}

Dynamic AABB3_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return get_x(); }
		if (HX_FIELD_EQ(inName,"y") ) { return get_y(); }
		if (HX_FIELD_EQ(inName,"z") ) { return get_z(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"min") ) { return get_min(); }
		if (HX_FIELD_EQ(inName,"max") ) { return get_max(); }
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		if (HX_FIELD_EQ(inName,"Set") ) { return Set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"temp") ) { return inCallProp ? get_temp() : temp; }
		if (HX_FIELD_EQ(inName,"xMin") ) { return get_xMin(); }
		if (HX_FIELD_EQ(inName,"yMin") ) { return get_yMin(); }
		if (HX_FIELD_EQ(inName,"zMin") ) { return get_zMin(); }
		if (HX_FIELD_EQ(inName,"xMax") ) { return get_xMax(); }
		if (HX_FIELD_EQ(inName,"yMax") ) { return get_yMax(); }
		if (HX_FIELD_EQ(inName,"zMax") ) { return get_zMax(); }
		if (HX_FIELD_EQ(inName,"size") ) { return get_size(); }
		if (HX_FIELD_EQ(inName,"Set3") ) { return Set3_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"empty") ) { return inCallProp ? get_empty() : empty; }
		if (HX_FIELD_EQ(inName,"clone") ) { return inCallProp ? get_clone() : clone; }
		if (HX_FIELD_EQ(inName,"get_x") ) { return get_x_dyn(); }
		if (HX_FIELD_EQ(inName,"set_x") ) { return set_x_dyn(); }
		if (HX_FIELD_EQ(inName,"get_y") ) { return get_y_dyn(); }
		if (HX_FIELD_EQ(inName,"set_y") ) { return set_y_dyn(); }
		if (HX_FIELD_EQ(inName,"get_z") ) { return get_z_dyn(); }
		if (HX_FIELD_EQ(inName,"set_z") ) { return set_z_dyn(); }
		if (HX_FIELD_EQ(inName,"width") ) { return get_width(); }
		if (HX_FIELD_EQ(inName,"depth") ) { return get_depth(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Center") ) { return Center_dyn(); }
		if (HX_FIELD_EQ(inName,"m_xMin") ) { return m_xMin; }
		if (HX_FIELD_EQ(inName,"m_yMin") ) { return m_yMin; }
		if (HX_FIELD_EQ(inName,"m_zMin") ) { return m_zMin; }
		if (HX_FIELD_EQ(inName,"m_xMax") ) { return m_xMax; }
		if (HX_FIELD_EQ(inName,"m_yMax") ) { return m_yMax; }
		if (HX_FIELD_EQ(inName,"m_zMax") ) { return m_zMax; }
		if (HX_FIELD_EQ(inName,"center") ) { return get_center(); }
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_min") ) { return get_min_dyn(); }
		if (HX_FIELD_EQ(inName,"set_min") ) { return set_min_dyn(); }
		if (HX_FIELD_EQ(inName,"get_max") ) { return get_max_dyn(); }
		if (HX_FIELD_EQ(inName,"set_max") ) { return set_max_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_temp") ) { return get_temp_dyn(); }
		if (HX_FIELD_EQ(inName,"get_xMin") ) { return get_xMin_dyn(); }
		if (HX_FIELD_EQ(inName,"set_xMin") ) { return set_xMin_dyn(); }
		if (HX_FIELD_EQ(inName,"get_yMin") ) { return get_yMin_dyn(); }
		if (HX_FIELD_EQ(inName,"set_yMin") ) { return set_yMin_dyn(); }
		if (HX_FIELD_EQ(inName,"get_zMin") ) { return get_zMin_dyn(); }
		if (HX_FIELD_EQ(inName,"set_zMin") ) { return set_zMin_dyn(); }
		if (HX_FIELD_EQ(inName,"get_xMax") ) { return get_xMax_dyn(); }
		if (HX_FIELD_EQ(inName,"set_xMax") ) { return set_xMax_dyn(); }
		if (HX_FIELD_EQ(inName,"get_yMax") ) { return get_yMax_dyn(); }
		if (HX_FIELD_EQ(inName,"set_yMax") ) { return set_yMax_dyn(); }
		if (HX_FIELD_EQ(inName,"get_zMax") ) { return get_zMax_dyn(); }
		if (HX_FIELD_EQ(inName,"set_zMax") ) { return set_zMax_dyn(); }
		if (HX_FIELD_EQ(inName,"get_size") ) { return get_size_dyn(); }
		if (HX_FIELD_EQ(inName,"set_size") ) { return set_size_dyn(); }
		if (HX_FIELD_EQ(inName,"Validate") ) { return Validate_dyn(); }
		if (HX_FIELD_EQ(inName,"SetAABB3") ) { return SetAABB3_dyn(); }
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_empty") ) { return get_empty_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clone") ) { return get_clone_dyn(); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		if (HX_FIELD_EQ(inName,"get_depth") ) { return get_depth_dyn(); }
		if (HX_FIELD_EQ(inName,"set_depth") ) { return set_depth_dyn(); }
		if (HX_FIELD_EQ(inName,"SetXYZWHD") ) { return SetXYZWHD_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FromMinMax") ) { return FromMinMax_dyn(); }
		if (HX_FIELD_EQ(inName,"FromCenter") ) { return FromCenter_dyn(); }
		if (HX_FIELD_EQ(inName,"get_center") ) { return get_center_dyn(); }
		if (HX_FIELD_EQ(inName,"set_center") ) { return set_center_dyn(); }
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"set_height") ) { return set_height_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"Encapsulate") ) { return Encapsulate_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"Encapsulate3") ) { return Encapsulate3_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AABB3_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return set_x(inValue); }
		if (HX_FIELD_EQ(inName,"y") ) { return set_y(inValue); }
		if (HX_FIELD_EQ(inName,"z") ) { return set_z(inValue); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"min") ) { return set_min(inValue); }
		if (HX_FIELD_EQ(inName,"max") ) { return set_max(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"temp") ) { temp=inValue.Cast< ::haxor::math::AABB3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xMin") ) { return set_xMin(inValue); }
		if (HX_FIELD_EQ(inName,"yMin") ) { return set_yMin(inValue); }
		if (HX_FIELD_EQ(inName,"zMin") ) { return set_zMin(inValue); }
		if (HX_FIELD_EQ(inName,"xMax") ) { return set_xMax(inValue); }
		if (HX_FIELD_EQ(inName,"yMax") ) { return set_yMax(inValue); }
		if (HX_FIELD_EQ(inName,"zMax") ) { return set_zMax(inValue); }
		if (HX_FIELD_EQ(inName,"size") ) { return set_size(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"empty") ) { empty=inValue.Cast< ::haxor::math::AABB3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clone") ) { clone=inValue.Cast< ::haxor::math::AABB3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { return set_width(inValue); }
		if (HX_FIELD_EQ(inName,"depth") ) { return set_depth(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_xMin") ) { m_xMin=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_yMin") ) { m_yMin=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_zMin") ) { m_zMin=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_xMax") ) { m_xMax=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_yMax") ) { m_yMax=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_zMax") ) { m_zMax=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"center") ) { return set_center(inValue); }
		if (HX_FIELD_EQ(inName,"height") ) { return set_height(inValue); }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AABB3_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("clone"));
	outFields->push(HX_CSTRING("min"));
	outFields->push(HX_CSTRING("max"));
	outFields->push(HX_CSTRING("xMin"));
	outFields->push(HX_CSTRING("m_xMin"));
	outFields->push(HX_CSTRING("yMin"));
	outFields->push(HX_CSTRING("m_yMin"));
	outFields->push(HX_CSTRING("zMin"));
	outFields->push(HX_CSTRING("m_zMin"));
	outFields->push(HX_CSTRING("xMax"));
	outFields->push(HX_CSTRING("m_xMax"));
	outFields->push(HX_CSTRING("yMax"));
	outFields->push(HX_CSTRING("m_yMax"));
	outFields->push(HX_CSTRING("zMax"));
	outFields->push(HX_CSTRING("m_zMax"));
	outFields->push(HX_CSTRING("center"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("z"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("depth"));
	outFields->push(HX_CSTRING("size"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("temp"),
	HX_CSTRING("get_temp"),
	HX_CSTRING("Center"),
	HX_CSTRING("FromMinMax"),
	HX_CSTRING("FromCenter"),
	HX_CSTRING("empty"),
	HX_CSTRING("get_empty"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::AABB3*/ ,(int)offsetof(AABB3_obj,clone),HX_CSTRING("clone")},
	{hx::fsFloat,(int)offsetof(AABB3_obj,m_xMin),HX_CSTRING("m_xMin")},
	{hx::fsFloat,(int)offsetof(AABB3_obj,m_yMin),HX_CSTRING("m_yMin")},
	{hx::fsFloat,(int)offsetof(AABB3_obj,m_zMin),HX_CSTRING("m_zMin")},
	{hx::fsFloat,(int)offsetof(AABB3_obj,m_xMax),HX_CSTRING("m_xMax")},
	{hx::fsFloat,(int)offsetof(AABB3_obj,m_yMax),HX_CSTRING("m_yMax")},
	{hx::fsFloat,(int)offsetof(AABB3_obj,m_zMax),HX_CSTRING("m_zMax")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("clone"),
	HX_CSTRING("get_clone"),
	HX_CSTRING("get_min"),
	HX_CSTRING("set_min"),
	HX_CSTRING("get_max"),
	HX_CSTRING("set_max"),
	HX_CSTRING("get_xMin"),
	HX_CSTRING("set_xMin"),
	HX_CSTRING("m_xMin"),
	HX_CSTRING("get_yMin"),
	HX_CSTRING("set_yMin"),
	HX_CSTRING("m_yMin"),
	HX_CSTRING("get_zMin"),
	HX_CSTRING("set_zMin"),
	HX_CSTRING("m_zMin"),
	HX_CSTRING("get_xMax"),
	HX_CSTRING("set_xMax"),
	HX_CSTRING("m_xMax"),
	HX_CSTRING("get_yMax"),
	HX_CSTRING("set_yMax"),
	HX_CSTRING("m_yMax"),
	HX_CSTRING("get_zMax"),
	HX_CSTRING("set_zMax"),
	HX_CSTRING("m_zMax"),
	HX_CSTRING("get_center"),
	HX_CSTRING("set_center"),
	HX_CSTRING("get_x"),
	HX_CSTRING("set_x"),
	HX_CSTRING("get_y"),
	HX_CSTRING("set_y"),
	HX_CSTRING("get_z"),
	HX_CSTRING("set_z"),
	HX_CSTRING("get_width"),
	HX_CSTRING("set_width"),
	HX_CSTRING("get_height"),
	HX_CSTRING("set_height"),
	HX_CSTRING("get_depth"),
	HX_CSTRING("set_depth"),
	HX_CSTRING("get_size"),
	HX_CSTRING("set_size"),
	HX_CSTRING("Validate"),
	HX_CSTRING("Add"),
	HX_CSTRING("Set"),
	HX_CSTRING("Set3"),
	HX_CSTRING("SetAABB3"),
	HX_CSTRING("SetXYZWHD"),
	HX_CSTRING("Encapsulate"),
	HX_CSTRING("Encapsulate3"),
	HX_CSTRING("ToString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AABB3_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(AABB3_obj::temp,"temp");
	HX_MARK_MEMBER_NAME(AABB3_obj::empty,"empty");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AABB3_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(AABB3_obj::temp,"temp");
	HX_VISIT_MEMBER_NAME(AABB3_obj::empty,"empty");
};

#endif

Class AABB3_obj::__mClass;

void AABB3_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.math.AABB3"), hx::TCanCast< AABB3_obj> ,sStaticFields,sMemberFields,
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

void AABB3_obj::__boot()
{
}

} // end namespace haxor
} // end namespace math
