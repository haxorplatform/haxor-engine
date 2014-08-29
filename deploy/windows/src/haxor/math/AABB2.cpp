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
#ifndef INCLUDED_haxor_math_AABB2
#include <haxor/math/AABB2.h>
#endif
#ifndef INCLUDED_haxor_math_Vector2
#include <haxor/math/Vector2.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace math{

Void AABB2_obj::__construct(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height)
{
HX_STACK_FRAME("haxor.math.AABB2","new",0x803d220a,"haxor.math.AABB2.new","haxor/math/AABB2.hx",117,0x4f052906)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_x,"p_x")
HX_STACK_ARG(__o_p_y,"p_y")
HX_STACK_ARG(__o_p_width,"p_width")
HX_STACK_ARG(__o_p_height,"p_height")
Float p_x = __o_p_x.Default(0);
Float p_y = __o_p_y.Default(0);
Float p_width = __o_p_width.Default(0);
Float p_height = __o_p_height.Default(0);
{
	HX_STACK_LINE(117)
	this->SetXYWH(p_x,p_y,p_width,p_height);
}
;
	return null();
}

//AABB2_obj::~AABB2_obj() { }

Dynamic AABB2_obj::__CreateEmpty() { return  new AABB2_obj; }
hx::ObjectPtr< AABB2_obj > AABB2_obj::__new(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height)
{  hx::ObjectPtr< AABB2_obj > result = new AABB2_obj();
	result->__construct(__o_p_x,__o_p_y,__o_p_width,__o_p_height);
	return result;}

Dynamic AABB2_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AABB2_obj > result = new AABB2_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::haxor::math::AABB2 AABB2_obj::get_clone( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_clone",0x48895cde,"haxor.math.AABB2.get_clone","haxor/math/AABB2.hx",44,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(44)
	Float _g = this->get_xMin();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(44)
	Float _g1 = this->get_xMax();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(44)
	Float _g2 = this->get_yMin();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(44)
	Float _g3 = this->get_yMax();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(44)
	return ::haxor::math::AABB2_obj::FromMinMax(_g,_g1,_g2,_g3);
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_clone,return )

::haxor::math::Vector2 AABB2_obj::get_min( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_min",0xa64c48d3,"haxor.math.AABB2.get_min","haxor/math/AABB2.hx",47,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(47)
	return ::haxor::math::Vector2_obj::__new(this->m_xMin,this->m_yMin);
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_min,return )

::haxor::math::Vector2 AABB2_obj::set_min( ::haxor::math::Vector2 v){
	HX_STACK_FRAME("haxor.math.AABB2","set_min",0x994dd9df,"haxor.math.AABB2.set_min","haxor/math/AABB2.hx",48,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(48)
	this->set_xMin(v->x);
	HX_STACK_LINE(48)
	this->set_yMin(v->y);
	HX_STACK_LINE(48)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,set_min,return )

::haxor::math::Vector2 AABB2_obj::get_max( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_max",0xa64c41e5,"haxor.math.AABB2.get_max","haxor/math/AABB2.hx",51,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(51)
	return ::haxor::math::Vector2_obj::__new(this->m_xMax,this->m_yMax);
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_max,return )

::haxor::math::Vector2 AABB2_obj::set_max( ::haxor::math::Vector2 v){
	HX_STACK_FRAME("haxor.math.AABB2","set_max",0x994dd2f1,"haxor.math.AABB2.set_max","haxor/math/AABB2.hx",52,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(52)
	this->set_xMax(v->x);
	HX_STACK_LINE(52)
	this->set_yMax(v->y);
	HX_STACK_LINE(52)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,set_max,return )

Float AABB2_obj::get_xMin( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_xMin",0xe3a38599,"haxor.math.AABB2.get_xMin","haxor/math/AABB2.hx",55,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(55)
	return this->m_xMin;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_xMin,return )

Float AABB2_obj::set_xMin( Float v){
	HX_STACK_FRAME("haxor.math.AABB2","set_xMin",0x9200df0d,"haxor.math.AABB2.set_xMin","haxor/math/AABB2.hx",56,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(56)
	this->m_xMin = v;
	HX_STACK_LINE(56)
	this->Validate();
	HX_STACK_LINE(56)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,set_xMin,return )

Float AABB2_obj::get_yMin( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_yMin",0xe44cbc38,"haxor.math.AABB2.get_yMin","haxor/math/AABB2.hx",60,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(60)
	return this->m_yMin;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_yMin,return )

Float AABB2_obj::set_yMin( Float v){
	HX_STACK_FRAME("haxor.math.AABB2","set_yMin",0x92aa15ac,"haxor.math.AABB2.set_yMin","haxor/math/AABB2.hx",61,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(61)
	this->m_yMin = v;
	HX_STACK_LINE(61)
	this->Validate();
	HX_STACK_LINE(61)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,set_yMin,return )

Float AABB2_obj::get_xMax( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_xMax",0xe3a37eab,"haxor.math.AABB2.get_xMax","haxor/math/AABB2.hx",65,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(65)
	return this->m_xMax;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_xMax,return )

Float AABB2_obj::set_xMax( Float v){
	HX_STACK_FRAME("haxor.math.AABB2","set_xMax",0x9200d81f,"haxor.math.AABB2.set_xMax","haxor/math/AABB2.hx",66,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(66)
	this->m_xMax = v;
	HX_STACK_LINE(66)
	this->Validate();
	HX_STACK_LINE(66)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,set_xMax,return )

Float AABB2_obj::get_yMax( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_yMax",0xe44cb54a,"haxor.math.AABB2.get_yMax","haxor/math/AABB2.hx",70,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(70)
	return this->m_yMax;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_yMax,return )

Float AABB2_obj::set_yMax( Float v){
	HX_STACK_FRAME("haxor.math.AABB2","set_yMax",0x92aa0ebe,"haxor.math.AABB2.set_yMax","haxor/math/AABB2.hx",71,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(71)
	this->m_yMax = v;
	HX_STACK_LINE(71)
	this->Validate();
	HX_STACK_LINE(71)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,set_yMax,return )

::haxor::math::Vector2 AABB2_obj::get_center( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_center",0x27352d34,"haxor.math.AABB2.get_center","haxor/math/AABB2.hx",75,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(75)
	Float _g = this->get_xMin();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(75)
	Float _g1 = this->get_xMax();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(75)
	Float _g2 = this->get_xMin();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(75)
	Float _g3 = (_g1 - _g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(75)
	Float _g4 = (_g3 * 0.5);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(75)
	Float _g5 = (_g + _g4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(75)
	Float _g6 = this->get_yMin();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(75)
	Float _g7 = this->get_yMax();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(75)
	Float _g8 = this->get_yMin();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(75)
	Float _g9 = (_g7 - _g8);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(75)
	Float _g10 = (_g9 * 0.5);		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(75)
	Float _g11 = (_g6 + _g10);		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(75)
	return ::haxor::math::Vector2_obj::__new(_g5,_g11);
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_center,return )

::haxor::math::Vector2 AABB2_obj::set_center( ::haxor::math::Vector2 v){
	HX_STACK_FRAME("haxor.math.AABB2","set_center",0x2ab2cba8,"haxor.math.AABB2.set_center","haxor/math/AABB2.hx",77,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(78)
	Float _g2;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(78)
	{
		HX_STACK_LINE(78)
		Float _g = this->get_xMax();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(78)
		Float _g1 = this->get_xMin();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(78)
		Float p_a = (_g - _g1);		HX_STACK_VAR(p_a,"p_a");
		HX_STACK_LINE(78)
		if (((p_a < (int)0))){
			HX_STACK_LINE(78)
			_g2 = -(p_a);
		}
		else{
			HX_STACK_LINE(78)
			_g2 = p_a;
		}
	}
	HX_STACK_LINE(78)
	Float hw = (_g2 * 0.5);		HX_STACK_VAR(hw,"hw");
	HX_STACK_LINE(79)
	Float _g5;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(79)
	{
		HX_STACK_LINE(79)
		Float _g3 = this->get_yMax();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(79)
		Float _g4 = this->get_yMin();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(79)
		Float p_a = (_g3 - _g4);		HX_STACK_VAR(p_a,"p_a");
		HX_STACK_LINE(79)
		if (((p_a < (int)0))){
			HX_STACK_LINE(79)
			_g5 = -(p_a);
		}
		else{
			HX_STACK_LINE(79)
			_g5 = p_a;
		}
	}
	HX_STACK_LINE(79)
	Float hh = (_g5 * 0.5);		HX_STACK_VAR(hh,"hh");
	HX_STACK_LINE(80)
	this->m_xMin = (v->x - hw);
	HX_STACK_LINE(81)
	this->m_xMax = (v->x + hw);
	HX_STACK_LINE(82)
	this->m_yMin = (v->y - hh);
	HX_STACK_LINE(83)
	this->m_yMax = (v->y + hh);
	HX_STACK_LINE(84)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,set_center,return )

Float AABB2_obj::get_x( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_x",0xdb813579,"haxor.math.AABB2.get_x","haxor/math/AABB2.hx",88,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(88)
	return this->get_xMin();
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_x,return )

Float AABB2_obj::set_x( Float v){
	HX_STACK_FRAME("haxor.math.AABB2","set_x",0xc4502b85,"haxor.math.AABB2.set_x","haxor/math/AABB2.hx",89,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(89)
	this->set_xMin(v);
	HX_STACK_LINE(89)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,set_x,return )

Float AABB2_obj::get_y( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_y",0xdb81357a,"haxor.math.AABB2.get_y","haxor/math/AABB2.hx",92,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(92)
	return this->get_yMin();
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_y,return )

Float AABB2_obj::set_y( Float v){
	HX_STACK_FRAME("haxor.math.AABB2","set_y",0xc4502b86,"haxor.math.AABB2.set_y","haxor/math/AABB2.hx",93,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(93)
	this->set_yMin(v);
	HX_STACK_LINE(93)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,set_y,return )

Float AABB2_obj::get_width( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_width",0xca88ff87,"haxor.math.AABB2.get_width","haxor/math/AABB2.hx",97,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(97)
	Float _g = this->get_xMax();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(97)
	Float _g1 = this->get_xMin();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(97)
	Float p_a = (_g - _g1);		HX_STACK_VAR(p_a,"p_a");
	HX_STACK_LINE(97)
	if (((p_a < (int)0))){
		HX_STACK_LINE(97)
		return -(p_a);
	}
	else{
		HX_STACK_LINE(97)
		return p_a;
	}
	HX_STACK_LINE(97)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_width,return )

Float AABB2_obj::set_width( Float v){
	HX_STACK_FRAME("haxor.math.AABB2","set_width",0xadd9eb93,"haxor.math.AABB2.set_width","haxor/math/AABB2.hx",98,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(98)
	Float _g = this->get_xMin();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(98)
	Float _g1 = (_g + v);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(98)
	this->set_xMax(_g1);
	HX_STACK_LINE(98)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,set_width,return )

Float AABB2_obj::get_height( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_height",0x23a60f46,"haxor.math.AABB2.get_height","haxor/math/AABB2.hx",101,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(101)
	Float _g = this->get_yMax();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(101)
	Float _g1 = this->get_yMin();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(101)
	Float p_a = (_g - _g1);		HX_STACK_VAR(p_a,"p_a");
	HX_STACK_LINE(101)
	if (((p_a < (int)0))){
		HX_STACK_LINE(101)
		return -(p_a);
	}
	else{
		HX_STACK_LINE(101)
		return p_a;
	}
	HX_STACK_LINE(101)
	return 0.;
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_height,return )

Float AABB2_obj::set_height( Float v){
	HX_STACK_FRAME("haxor.math.AABB2","set_height",0x2723adba,"haxor.math.AABB2.set_height","haxor/math/AABB2.hx",102,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(102)
	Float _g = this->get_yMin();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(102)
	Float _g1 = (_g + v);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(102)
	this->set_yMax(_g1);
	HX_STACK_LINE(102)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,set_height,return )

::haxor::math::Vector2 AABB2_obj::get_size( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_size",0xe06ac260,"haxor.math.AABB2.get_size","haxor/math/AABB2.hx",105,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_LINE(105)
	Float _g2;		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(105)
	{
		HX_STACK_LINE(105)
		Float _g = this->get_xMax();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(105)
		Float _g1 = this->get_xMin();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(105)
		Float p_a = (_g - _g1);		HX_STACK_VAR(p_a,"p_a");
		HX_STACK_LINE(105)
		if (((p_a < (int)0))){
			HX_STACK_LINE(105)
			_g2 = -(p_a);
		}
		else{
			HX_STACK_LINE(105)
			_g2 = p_a;
		}
	}
	HX_STACK_LINE(105)
	Float _g5;		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(105)
	{
		HX_STACK_LINE(105)
		Float _g3 = this->get_yMax();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(105)
		Float _g4 = this->get_yMin();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(105)
		Float p_a = (_g3 - _g4);		HX_STACK_VAR(p_a,"p_a");
		HX_STACK_LINE(105)
		if (((p_a < (int)0))){
			HX_STACK_LINE(105)
			_g5 = -(p_a);
		}
		else{
			HX_STACK_LINE(105)
			_g5 = p_a;
		}
	}
	HX_STACK_LINE(105)
	return ::haxor::math::Vector2_obj::__new(_g2,_g5);
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_size,return )

::haxor::math::Vector2 AABB2_obj::set_size( ::haxor::math::Vector2 v){
	HX_STACK_FRAME("haxor.math.AABB2","set_size",0x8ec81bd4,"haxor.math.AABB2.set_size","haxor/math/AABB2.hx",106,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(106)
	{
		HX_STACK_LINE(106)
		Float v1 = v->x;		HX_STACK_VAR(v1,"v1");
		HX_STACK_LINE(106)
		Float _g = this->get_xMin();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(106)
		Float _g1 = (_g + v1);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(106)
		this->set_xMax(_g1);
		HX_STACK_LINE(106)
		v1;
	}
	HX_STACK_LINE(106)
	{
		HX_STACK_LINE(106)
		Float v1 = v->y;		HX_STACK_VAR(v1,"v1");
		HX_STACK_LINE(106)
		Float _g2 = this->get_yMin();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(106)
		Float _g3 = (_g2 + v1);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(106)
		this->set_yMax(_g3);
		HX_STACK_LINE(106)
		v1;
	}
	HX_STACK_LINE(106)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,set_size,return )

Void AABB2_obj::Validate( ){
{
		HX_STACK_FRAME("haxor.math.AABB2","Validate",0xf2f1f2cc,"haxor.math.AABB2.Validate","haxor/math/AABB2.hx",124,0x4f052906)
		HX_STACK_THIS(this)
		HX_STACK_LINE(126)
		Float x0 = this->m_xMin;		HX_STACK_VAR(x0,"x0");
		HX_STACK_LINE(127)
		Float x1 = this->m_xMax;		HX_STACK_VAR(x1,"x1");
		HX_STACK_LINE(128)
		Float y0 = this->m_yMin;		HX_STACK_VAR(y0,"y0");
		HX_STACK_LINE(129)
		Float y1 = this->m_yMax;		HX_STACK_VAR(y1,"y1");
		HX_STACK_LINE(130)
		if (((x0 <= x1))){
			HX_STACK_LINE(130)
			this->m_xMin = x0;
			HX_STACK_LINE(130)
			this->m_xMax = x1;
		}
		else{
			HX_STACK_LINE(130)
			this->m_xMin = x1;
			HX_STACK_LINE(130)
			this->m_xMax = x0;
		}
		HX_STACK_LINE(131)
		if (((y0 <= y1))){
			HX_STACK_LINE(131)
			this->m_yMin = y0;
			HX_STACK_LINE(131)
			this->m_yMax = y1;
		}
		else{
			HX_STACK_LINE(131)
			this->m_yMin = y1;
			HX_STACK_LINE(131)
			this->m_yMax = y0;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,Validate,(void))

::haxor::math::AABB2 AABB2_obj::Add( ::haxor::math::AABB2 p_v){
	HX_STACK_FRAME("haxor.math.AABB2","Add",0x801afbab,"haxor.math.AABB2.Add","haxor/math/AABB2.hx",141,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(142)
	Float _g = ::Math_obj::max(p_v->m_xMax,this->m_xMax);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(142)
	this->m_xMax = _g;
	HX_STACK_LINE(143)
	Float _g1 = ::Math_obj::min(p_v->m_xMin,this->m_xMin);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(143)
	this->m_xMin = _g1;
	HX_STACK_LINE(144)
	Float _g2 = ::Math_obj::max(p_v->m_yMax,this->m_yMax);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(144)
	this->m_yMax = _g2;
	HX_STACK_LINE(145)
	Float _g3 = ::Math_obj::min(p_v->m_yMin,this->m_yMin);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(145)
	this->m_yMin = _g3;
	HX_STACK_LINE(146)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,Add,return )

::haxor::math::AABB2 AABB2_obj::Set( Float p_xmin,Float p_xmax,Float p_ymin,Float p_ymax){
	HX_STACK_FRAME("haxor.math.AABB2","Set",0x8028a52c,"haxor.math.AABB2.Set","haxor/math/AABB2.hx",158,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_xmin,"p_xmin")
	HX_STACK_ARG(p_xmax,"p_xmax")
	HX_STACK_ARG(p_ymin,"p_ymin")
	HX_STACK_ARG(p_ymax,"p_ymax")
	HX_STACK_LINE(159)
	this->m_xMin = p_xmin;
	HX_STACK_LINE(160)
	this->m_yMin = p_ymin;
	HX_STACK_LINE(161)
	this->m_xMax = p_xmax;
	HX_STACK_LINE(162)
	this->m_yMax = p_ymax;
	HX_STACK_LINE(163)
	this->Validate();
	HX_STACK_LINE(164)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC4(AABB2_obj,Set,return )

::haxor::math::AABB2 AABB2_obj::SetXYWH( Float p_x,Float p_y,Float p_width,Float p_height){
	HX_STACK_FRAME("haxor.math.AABB2","SetXYWH",0x61ef467e,"haxor.math.AABB2.SetXYWH","haxor/math/AABB2.hx",176,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_ARG(p_width,"p_width")
	HX_STACK_ARG(p_height,"p_height")
	HX_STACK_LINE(177)
	this->m_xMin = p_x;
	HX_STACK_LINE(178)
	this->m_yMin = p_y;
	HX_STACK_LINE(179)
	this->m_xMax = (this->m_xMin + p_width);
	HX_STACK_LINE(180)
	this->m_yMax = (this->m_yMin + p_height);
	HX_STACK_LINE(181)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC4(AABB2_obj,SetXYWH,return )

::haxor::math::AABB2 AABB2_obj::SetAABB2( ::haxor::math::AABB2 p_v){
	HX_STACK_FRAME("haxor.math.AABB2","SetAABB2",0x0149fce6,"haxor.math.AABB2.SetAABB2","haxor/math/AABB2.hx",190,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(191)
	this->m_xMin = p_v->m_xMin;
	HX_STACK_LINE(192)
	this->m_yMin = p_v->m_yMin;
	HX_STACK_LINE(193)
	this->m_xMax = p_v->m_xMax;
	HX_STACK_LINE(194)
	this->m_yMax = p_v->m_yMax;
	HX_STACK_LINE(195)
	return hx::ObjectPtr<OBJ_>(this);
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,SetAABB2,return )

Void AABB2_obj::Encapsulate( ::haxor::math::Vector2 p_point){
{
		HX_STACK_FRAME("haxor.math.AABB2","Encapsulate",0xf4daac5b,"haxor.math.AABB2.Encapsulate","haxor/math/AABB2.hx",203,0x4f052906)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_point,"p_point")
		HX_STACK_LINE(204)
		Float _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(204)
		{
			HX_STACK_LINE(204)
			Float b = this->get_xMin();		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(204)
			_g = ::Math_obj::min(p_point->x,b);
		}
		HX_STACK_LINE(204)
		this->set_xMin(_g);
		HX_STACK_LINE(205)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(205)
		{
			HX_STACK_LINE(205)
			Float b = this->get_xMax();		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(205)
			_g1 = ::Math_obj::max(p_point->x,b);
		}
		HX_STACK_LINE(205)
		this->set_xMax(_g1);
		HX_STACK_LINE(206)
		Float _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(206)
		{
			HX_STACK_LINE(206)
			Float b = this->get_yMin();		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(206)
			_g2 = ::Math_obj::min(p_point->y,b);
		}
		HX_STACK_LINE(206)
		this->set_yMin(_g2);
		HX_STACK_LINE(207)
		Float _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(207)
		{
			HX_STACK_LINE(207)
			Float b = this->get_yMax();		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(207)
			_g3 = ::Math_obj::max(p_point->y,b);
		}
		HX_STACK_LINE(207)
		this->set_yMax(_g3);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,Encapsulate,(void))

::haxor::math::AABB2 AABB2_obj::Encapsulate3( hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y){
Float p_x = __o_p_x.Default(0);
Float p_y = __o_p_y.Default(0);
	HX_STACK_FRAME("haxor.math.AABB2","Encapsulate3",0x4a7c2378,"haxor.math.AABB2.Encapsulate3","haxor/math/AABB2.hx",217,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
{
		HX_STACK_LINE(218)
		Float _g = ::Math_obj::min(p_x,this->m_xMin);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(218)
		this->m_xMin = _g;
		HX_STACK_LINE(219)
		Float _g1 = ::Math_obj::max(p_x,this->m_xMax);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(219)
		this->m_xMax = _g1;
		HX_STACK_LINE(220)
		Float _g2 = ::Math_obj::min(p_y,this->m_yMin);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(220)
		this->m_yMin = _g2;
		HX_STACK_LINE(221)
		Float _g3 = ::Math_obj::max(p_y,this->m_yMax);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(221)
		this->m_yMax = _g3;
		HX_STACK_LINE(222)
		this->Validate();
		HX_STACK_LINE(223)
		return hx::ObjectPtr<OBJ_>(this);
	}
}


HX_DEFINE_DYNAMIC_FUNC2(AABB2_obj,Encapsulate3,return )

::String AABB2_obj::ToString( hx::Null< int >  __o_p_places){
int p_places = __o_p_places.Default(2);
	HX_STACK_FRAME("haxor.math.AABB2","ToString",0x267cf2e2,"haxor.math.AABB2.ToString","haxor/math/AABB2.hx",231,0x4f052906)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_places,"p_places")
{
		HX_STACK_LINE(232)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(232)
		{
			HX_STACK_LINE(232)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(232)
			Float _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(232)
			{
				HX_STACK_LINE(232)
				Float p_v = (this->m_xMin * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(232)
				_g = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(232)
			_g1 = (Float(_g) / Float(d));
		}
		HX_STACK_LINE(232)
		::String s0 = (_g1 + HX_CSTRING(""));		HX_STACK_VAR(s0,"s0");
		HX_STACK_LINE(233)
		Float _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(233)
		{
			HX_STACK_LINE(233)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(233)
			Float _g2;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(233)
			{
				HX_STACK_LINE(233)
				Float p_v = (this->m_xMax * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(233)
				_g2 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(233)
			_g3 = (Float(_g2) / Float(d));
		}
		HX_STACK_LINE(233)
		::String s1 = (_g3 + HX_CSTRING(""));		HX_STACK_VAR(s1,"s1");
		HX_STACK_LINE(234)
		Float _g5;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(234)
		{
			HX_STACK_LINE(234)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(234)
			Float _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(234)
			{
				HX_STACK_LINE(234)
				Float p_v = (this->m_yMin * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(234)
				_g4 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(234)
			_g5 = (Float(_g4) / Float(d));
		}
		HX_STACK_LINE(234)
		::String s2 = (_g5 + HX_CSTRING(""));		HX_STACK_VAR(s2,"s2");
		HX_STACK_LINE(235)
		Float _g7;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(235)
		{
			HX_STACK_LINE(235)
			Float d = ::Math_obj::pow((int)10,p_places);		HX_STACK_VAR(d,"d");
			HX_STACK_LINE(235)
			Float _g6;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(235)
			{
				HX_STACK_LINE(235)
				Float p_v = (this->m_yMax * d);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(235)
				_g6 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
			}
			HX_STACK_LINE(235)
			_g7 = (Float(_g6) / Float(d));
		}
		HX_STACK_LINE(235)
		::String s3 = (_g7 + HX_CSTRING(""));		HX_STACK_VAR(s3,"s3");
		HX_STACK_LINE(236)
		return ((((((((HX_CSTRING("[") + s0) + HX_CSTRING(",")) + s1) + HX_CSTRING("|")) + s2) + HX_CSTRING(",")) + s3) + HX_CSTRING("]"));
	}
}


HX_DEFINE_DYNAMIC_FUNC1(AABB2_obj,ToString,return )

::haxor::math::AABB2 AABB2_obj::temp;

::haxor::math::AABB2 AABB2_obj::get_temp( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_temp",0xe110e4b3,"haxor.math.AABB2.get_temp","haxor/math/AABB2.hx",14,0x4f052906)
	HX_STACK_LINE(14)
	::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
	HX_STACK_LINE(14)
	int _g = _this->m_naabb2 = hx::Mod(((_this->m_naabb2 + (int)1)),_this->m_aabb2->length);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(14)
	return _this->m_aabb2->__get(_g).StaticCast< ::haxor::math::AABB2 >();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_temp,return )

::haxor::math::AABB2 AABB2_obj::FromMinMax( Float p_xmin,Float p_xmax,Float p_ymin,Float p_ymax){
	HX_STACK_FRAME("haxor.math.AABB2","FromMinMax",0xbdb118f2,"haxor.math.AABB2.FromMinMax","haxor/math/AABB2.hx",25,0x4f052906)
	HX_STACK_ARG(p_xmin,"p_xmin")
	HX_STACK_ARG(p_xmax,"p_xmax")
	HX_STACK_ARG(p_ymin,"p_ymin")
	HX_STACK_ARG(p_ymax,"p_ymax")
	HX_STACK_LINE(26)
	::haxor::math::AABB2 b = ::haxor::math::AABB2_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(27)
	b->set_xMin(p_xmin);
	HX_STACK_LINE(28)
	b->set_xMax(p_xmax);
	HX_STACK_LINE(29)
	b->set_yMin(p_ymin);
	HX_STACK_LINE(30)
	b->set_yMax(p_ymax);
	HX_STACK_LINE(31)
	return b;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(AABB2_obj,FromMinMax,return )

::haxor::math::AABB2 AABB2_obj::empty;

::haxor::math::AABB2 AABB2_obj::get_empty( ){
	HX_STACK_FRAME("haxor.math.AABB2","get_empty",0x7000840e,"haxor.math.AABB2.get_empty","haxor/math/AABB2.hx",38,0x4f052906)
	HX_STACK_LINE(38)
	return ::haxor::math::AABB2_obj::__new(null(),null(),null(),null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(AABB2_obj,get_empty,return )


AABB2_obj::AABB2_obj()
{
}

void AABB2_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AABB2);
	HX_MARK_MEMBER_NAME(clone,"clone");
	HX_MARK_MEMBER_NAME(m_xMin,"m_xMin");
	HX_MARK_MEMBER_NAME(m_yMin,"m_yMin");
	HX_MARK_MEMBER_NAME(m_xMax,"m_xMax");
	HX_MARK_MEMBER_NAME(m_yMax,"m_yMax");
	HX_MARK_END_CLASS();
}

void AABB2_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(clone,"clone");
	HX_VISIT_MEMBER_NAME(m_xMin,"m_xMin");
	HX_VISIT_MEMBER_NAME(m_yMin,"m_yMin");
	HX_VISIT_MEMBER_NAME(m_xMax,"m_xMax");
	HX_VISIT_MEMBER_NAME(m_yMax,"m_yMax");
}

Dynamic AABB2_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return get_x(); }
		if (HX_FIELD_EQ(inName,"y") ) { return get_y(); }
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
		if (HX_FIELD_EQ(inName,"xMax") ) { return get_xMax(); }
		if (HX_FIELD_EQ(inName,"yMax") ) { return get_yMax(); }
		if (HX_FIELD_EQ(inName,"size") ) { return get_size(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"empty") ) { return inCallProp ? get_empty() : empty; }
		if (HX_FIELD_EQ(inName,"clone") ) { return inCallProp ? get_clone() : clone; }
		if (HX_FIELD_EQ(inName,"get_x") ) { return get_x_dyn(); }
		if (HX_FIELD_EQ(inName,"set_x") ) { return set_x_dyn(); }
		if (HX_FIELD_EQ(inName,"get_y") ) { return get_y_dyn(); }
		if (HX_FIELD_EQ(inName,"set_y") ) { return set_y_dyn(); }
		if (HX_FIELD_EQ(inName,"width") ) { return get_width(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_xMin") ) { return m_xMin; }
		if (HX_FIELD_EQ(inName,"m_yMin") ) { return m_yMin; }
		if (HX_FIELD_EQ(inName,"m_xMax") ) { return m_xMax; }
		if (HX_FIELD_EQ(inName,"m_yMax") ) { return m_yMax; }
		if (HX_FIELD_EQ(inName,"center") ) { return get_center(); }
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_min") ) { return get_min_dyn(); }
		if (HX_FIELD_EQ(inName,"set_min") ) { return set_min_dyn(); }
		if (HX_FIELD_EQ(inName,"get_max") ) { return get_max_dyn(); }
		if (HX_FIELD_EQ(inName,"set_max") ) { return set_max_dyn(); }
		if (HX_FIELD_EQ(inName,"SetXYWH") ) { return SetXYWH_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_temp") ) { return get_temp_dyn(); }
		if (HX_FIELD_EQ(inName,"get_xMin") ) { return get_xMin_dyn(); }
		if (HX_FIELD_EQ(inName,"set_xMin") ) { return set_xMin_dyn(); }
		if (HX_FIELD_EQ(inName,"get_yMin") ) { return get_yMin_dyn(); }
		if (HX_FIELD_EQ(inName,"set_yMin") ) { return set_yMin_dyn(); }
		if (HX_FIELD_EQ(inName,"get_xMax") ) { return get_xMax_dyn(); }
		if (HX_FIELD_EQ(inName,"set_xMax") ) { return set_xMax_dyn(); }
		if (HX_FIELD_EQ(inName,"get_yMax") ) { return get_yMax_dyn(); }
		if (HX_FIELD_EQ(inName,"set_yMax") ) { return set_yMax_dyn(); }
		if (HX_FIELD_EQ(inName,"get_size") ) { return get_size_dyn(); }
		if (HX_FIELD_EQ(inName,"set_size") ) { return set_size_dyn(); }
		if (HX_FIELD_EQ(inName,"Validate") ) { return Validate_dyn(); }
		if (HX_FIELD_EQ(inName,"SetAABB2") ) { return SetAABB2_dyn(); }
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_empty") ) { return get_empty_dyn(); }
		if (HX_FIELD_EQ(inName,"get_clone") ) { return get_clone_dyn(); }
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"set_width") ) { return set_width_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FromMinMax") ) { return FromMinMax_dyn(); }
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

Dynamic AABB2_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return set_x(inValue); }
		if (HX_FIELD_EQ(inName,"y") ) { return set_y(inValue); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"min") ) { return set_min(inValue); }
		if (HX_FIELD_EQ(inName,"max") ) { return set_max(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"temp") ) { temp=inValue.Cast< ::haxor::math::AABB2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"xMin") ) { return set_xMin(inValue); }
		if (HX_FIELD_EQ(inName,"yMin") ) { return set_yMin(inValue); }
		if (HX_FIELD_EQ(inName,"xMax") ) { return set_xMax(inValue); }
		if (HX_FIELD_EQ(inName,"yMax") ) { return set_yMax(inValue); }
		if (HX_FIELD_EQ(inName,"size") ) { return set_size(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"empty") ) { empty=inValue.Cast< ::haxor::math::AABB2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"clone") ) { clone=inValue.Cast< ::haxor::math::AABB2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { return set_width(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_xMin") ) { m_xMin=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_yMin") ) { m_yMin=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_xMax") ) { m_xMax=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_yMax") ) { m_yMax=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"center") ) { return set_center(inValue); }
		if (HX_FIELD_EQ(inName,"height") ) { return set_height(inValue); }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AABB2_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("clone"));
	outFields->push(HX_CSTRING("min"));
	outFields->push(HX_CSTRING("max"));
	outFields->push(HX_CSTRING("xMin"));
	outFields->push(HX_CSTRING("m_xMin"));
	outFields->push(HX_CSTRING("yMin"));
	outFields->push(HX_CSTRING("m_yMin"));
	outFields->push(HX_CSTRING("xMax"));
	outFields->push(HX_CSTRING("m_xMax"));
	outFields->push(HX_CSTRING("yMax"));
	outFields->push(HX_CSTRING("m_yMax"));
	outFields->push(HX_CSTRING("center"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("size"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("temp"),
	HX_CSTRING("get_temp"),
	HX_CSTRING("FromMinMax"),
	HX_CSTRING("empty"),
	HX_CSTRING("get_empty"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::AABB2*/ ,(int)offsetof(AABB2_obj,clone),HX_CSTRING("clone")},
	{hx::fsFloat,(int)offsetof(AABB2_obj,m_xMin),HX_CSTRING("m_xMin")},
	{hx::fsFloat,(int)offsetof(AABB2_obj,m_yMin),HX_CSTRING("m_yMin")},
	{hx::fsFloat,(int)offsetof(AABB2_obj,m_xMax),HX_CSTRING("m_xMax")},
	{hx::fsFloat,(int)offsetof(AABB2_obj,m_yMax),HX_CSTRING("m_yMax")},
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
	HX_CSTRING("get_xMax"),
	HX_CSTRING("set_xMax"),
	HX_CSTRING("m_xMax"),
	HX_CSTRING("get_yMax"),
	HX_CSTRING("set_yMax"),
	HX_CSTRING("m_yMax"),
	HX_CSTRING("get_center"),
	HX_CSTRING("set_center"),
	HX_CSTRING("get_x"),
	HX_CSTRING("set_x"),
	HX_CSTRING("get_y"),
	HX_CSTRING("set_y"),
	HX_CSTRING("get_width"),
	HX_CSTRING("set_width"),
	HX_CSTRING("get_height"),
	HX_CSTRING("set_height"),
	HX_CSTRING("get_size"),
	HX_CSTRING("set_size"),
	HX_CSTRING("Validate"),
	HX_CSTRING("Add"),
	HX_CSTRING("Set"),
	HX_CSTRING("SetXYWH"),
	HX_CSTRING("SetAABB2"),
	HX_CSTRING("Encapsulate"),
	HX_CSTRING("Encapsulate3"),
	HX_CSTRING("ToString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AABB2_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(AABB2_obj::temp,"temp");
	HX_MARK_MEMBER_NAME(AABB2_obj::empty,"empty");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AABB2_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(AABB2_obj::temp,"temp");
	HX_VISIT_MEMBER_NAME(AABB2_obj::empty,"empty");
};

#endif

Class AABB2_obj::__mClass;

void AABB2_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.math.AABB2"), hx::TCanCast< AABB2_obj> ,sStaticFields,sMemberFields,
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

void AABB2_obj::__boot()
{
}

} // end namespace haxor
} // end namespace math
