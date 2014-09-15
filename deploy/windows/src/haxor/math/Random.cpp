#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_math_Quaternion
#include <haxor/math/Quaternion.h>
#endif
#ifndef INCLUDED_haxor_math_Random
#include <haxor/math/Random.h>
#endif
#ifndef INCLUDED_haxor_math_Vector2
#include <haxor/math/Vector2.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace math{

Void Random_obj::__construct()
{
	return null();
}

//Random_obj::~Random_obj() { }

Dynamic Random_obj::__CreateEmpty() { return  new Random_obj; }
hx::ObjectPtr< Random_obj > Random_obj::__new()
{  hx::ObjectPtr< Random_obj > result = new Random_obj();
	result->__construct();
	return result;}

Dynamic Random_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Random_obj > result = new Random_obj();
	result->__construct();
	return result;}

Float Random_obj::value;

Float Random_obj::get_value( ){
	HX_STACK_FRAME("haxor.math.Random","get_value",0x27f133f7,"haxor.math.Random.get_value","haxor/math/Random.hx",14,0x04916aa1)
	HX_STACK_LINE(14)
	return ::Math_obj::random();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Random_obj,get_value,return )

Float Random_obj::interval;

Float Random_obj::get_interval( ){
	HX_STACK_FRAME("haxor.math.Random","get_interval",0x383edc7f,"haxor.math.Random.get_interval","haxor/math/Random.hx",20,0x04916aa1)
	HX_STACK_LINE(20)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(20)
	Float _g1 = (_g - 0.499995);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(20)
	return (_g1 * 2.0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Random_obj,get_interval,return )

::haxor::math::Quaternion Random_obj::rotation;

::haxor::math::Quaternion Random_obj::get_rotation( ){
	HX_STACK_FRAME("haxor.math.Random","get_rotation",0x1848a078,"haxor.math.Random.get_rotation","haxor/math/Random.hx",26,0x04916aa1)
	HX_STACK_LINE(26)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(26)
	Float _g1 = (_g - 0.499995);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(26)
	Float _g2 = (_g1 * 2.0);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(26)
	Float _g3 = ::Math_obj::random();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(26)
	Float _g4 = (_g3 - 0.499995);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(26)
	Float _g5 = (_g4 * 2.0);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(26)
	Float _g6 = ::Math_obj::random();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(26)
	Float _g7 = (_g6 - 0.499995);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(26)
	Float _g8 = (_g7 * 2.0);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(26)
	Float _g9 = ::Math_obj::random();		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(26)
	::haxor::math::Vector3 _g10 = ::haxor::math::Vector3_obj::__new(_g2,_g5,_g8)->Normalize()->Scale(_g9);		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(26)
	Float _g11 = ::Math_obj::random();		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(26)
	Float _g12 = (_g11 - 0.499995);		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(26)
	Float _g13 = (_g12 * 2.0);		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(26)
	Float _g14 = (_g13 * 180.0);		HX_STACK_VAR(_g14,"_g14");
	HX_STACK_LINE(26)
	return ::haxor::math::Quaternion_obj::FromAxisAngle(_g10,_g14);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Random_obj,get_rotation,return )

::haxor::math::Vector3 Random_obj::box;

::haxor::math::Vector3 Random_obj::get_box( ){
	HX_STACK_FRAME("haxor.math.Random","get_box",0x4d572511,"haxor.math.Random.get_box","haxor/math/Random.hx",32,0x04916aa1)
	HX_STACK_LINE(32)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(32)
	Float _g1 = (_g - 0.499995);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(32)
	Float _g2 = (_g1 * 2.0);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(32)
	Float _g3 = (_g2 * 0.5);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(32)
	Float _g4 = ::Math_obj::random();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(32)
	Float _g5 = (_g4 - 0.499995);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(32)
	Float _g6 = (_g5 * 2.0);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(32)
	Float _g7 = (_g6 * 0.5);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(32)
	Float _g8 = ::Math_obj::random();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(32)
	Float _g9 = (_g8 - 0.499995);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(32)
	Float _g10 = (_g9 * 2.0);		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(32)
	Float _g11 = (_g10 * 0.5);		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(32)
	return ::haxor::math::Vector3_obj::__new(_g3,_g7,_g11);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Random_obj,get_box,return )

::haxor::math::Vector3 Random_obj::onBox;

::haxor::math::Vector3 Random_obj::get_onBox( ){
	HX_STACK_FRAME("haxor.math.Random","get_onBox",0x289b06b2,"haxor.math.Random.get_onBox","haxor/math/Random.hx",39,0x04916aa1)
	HX_STACK_LINE(40)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(40)
	Float _g1 = (_g - 0.499995);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(40)
	Float _g2 = (_g1 * 2.0);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(40)
	Float _g3 = (_g2 * 0.5);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(40)
	Float _g4 = ::Math_obj::random();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(40)
	Float _g5 = (_g4 - 0.499995);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(40)
	Float _g6 = (_g5 * 2.0);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(40)
	Float _g7 = (_g6 * 0.5);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(40)
	Float _g8 = ::Math_obj::random();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(40)
	Float _g9 = (_g8 - 0.499995);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(40)
	Float _g10 = (_g9 * 2.0);		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(40)
	Float _g11 = (_g10 * 0.5);		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(40)
	::haxor::math::Vector3 p = ::haxor::math::Vector3_obj::__new(_g3,_g7,_g11);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(41)
	Float _g12 = ::Math_obj::random();		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(41)
	Float _g13 = (_g12 * (int)3);		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(41)
	int i = (_g13 + 0.5);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(42)
	switch( (int)(i)){
		case (int)0: {
			HX_STACK_LINE(44)
			if (((p->x < 0.0))){
				HX_STACK_LINE(44)
				p->x = -0.5;
			}
			else{
				HX_STACK_LINE(44)
				p->x = 0.5;
			}
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(45)
			if (((p->y < 0.0))){
				HX_STACK_LINE(45)
				p->y = -0.5;
			}
			else{
				HX_STACK_LINE(45)
				p->y = 0.5;
			}
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(46)
			if (((p->z < 0.0))){
				HX_STACK_LINE(46)
				p->z = -0.5;
			}
			else{
				HX_STACK_LINE(46)
				p->z = 0.5;
			}
		}
		;break;
	}
	HX_STACK_LINE(48)
	return p;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Random_obj,get_onBox,return )

::haxor::math::Vector2 Random_obj::square;

::haxor::math::Vector2 Random_obj::get_square( ){
	HX_STACK_FRAME("haxor.math.Random","get_square",0xd4574157,"haxor.math.Random.get_square","haxor/math/Random.hx",55,0x04916aa1)
	HX_STACK_LINE(55)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(55)
	Float _g1 = (_g - 0.499995);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(55)
	Float _g2 = (_g1 * 2.0);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(55)
	Float _g3 = (_g2 * 0.5);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(55)
	Float _g4 = ::Math_obj::random();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(55)
	Float _g5 = (_g4 - 0.499995);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(55)
	Float _g6 = (_g5 * 2.0);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(55)
	Float _g7 = (_g6 * 0.5);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(55)
	return ::haxor::math::Vector2_obj::__new(_g3,_g7);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Random_obj,get_square,return )

::haxor::math::Vector2 Random_obj::onSquare;

::haxor::math::Vector2 Random_obj::get_onSquare( ){
	HX_STACK_FRAME("haxor.math.Random","get_onSquare",0x48615a56,"haxor.math.Random.get_onSquare","haxor/math/Random.hx",62,0x04916aa1)
	HX_STACK_LINE(63)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(63)
	Float _g1 = (_g - 0.499995);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(63)
	Float _g2 = (_g1 * 2.0);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(63)
	Float _g3 = (_g2 * 0.5);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(63)
	Float _g4 = ::Math_obj::random();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(63)
	Float _g5 = (_g4 - 0.499995);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(63)
	Float _g6 = (_g5 * 2.0);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(63)
	Float _g7 = (_g6 * 0.5);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(63)
	::haxor::math::Vector2 p = ::haxor::math::Vector2_obj::__new(_g3,_g7);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(64)
	Float _g8 = ::Math_obj::random();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(64)
	Float _g9 = (_g8 * (int)2);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(64)
	int i = (_g9 + 0.5);		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(65)
	switch( (int)(i)){
		case (int)0: {
			HX_STACK_LINE(67)
			if (((p->x < 0.0))){
				HX_STACK_LINE(67)
				p->x = -0.5;
			}
			else{
				HX_STACK_LINE(67)
				p->x = 0.5;
			}
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(68)
			if (((p->y < 0.0))){
				HX_STACK_LINE(68)
				p->y = -0.5;
			}
			else{
				HX_STACK_LINE(68)
				p->y = 0.5;
			}
		}
		;break;
	}
	HX_STACK_LINE(70)
	return p;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Random_obj,get_onSquare,return )

::haxor::math::Vector3 Random_obj::sphere;

::haxor::math::Vector3 Random_obj::get_sphere( ){
	HX_STACK_FRAME("haxor.math.Random","get_sphere",0x385befc7,"haxor.math.Random.get_sphere","haxor/math/Random.hx",77,0x04916aa1)
	HX_STACK_LINE(77)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(77)
	Float _g1 = (_g - 0.499995);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(77)
	Float _g2 = (_g1 * 2.0);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(77)
	Float _g3 = ::Math_obj::random();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(77)
	Float _g4 = (_g3 - 0.499995);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(77)
	Float _g5 = (_g4 * 2.0);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(77)
	Float _g6 = ::Math_obj::random();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(77)
	Float _g7 = (_g6 - 0.499995);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(77)
	Float _g8 = (_g7 * 2.0);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(77)
	Float _g9 = ::Math_obj::random();		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(77)
	return ::haxor::math::Vector3_obj::__new(_g2,_g5,_g8)->Normalize()->Scale(_g9);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Random_obj,get_sphere,return )

::haxor::math::Vector3 Random_obj::onSphere;

::haxor::math::Vector3 Random_obj::get_onSphere( ){
	HX_STACK_FRAME("haxor.math.Random","get_onSphere",0xac6608c6,"haxor.math.Random.get_onSphere","haxor/math/Random.hx",83,0x04916aa1)
	HX_STACK_LINE(83)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(83)
	Float _g1 = (_g - 0.499995);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(83)
	Float _g2 = (_g1 * 2.0);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(83)
	Float _g3 = ::Math_obj::random();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(83)
	Float _g4 = (_g3 - 0.499995);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(83)
	Float _g5 = (_g4 * 2.0);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(83)
	Float _g6 = ::Math_obj::random();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(83)
	Float _g7 = (_g6 - 0.499995);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(83)
	Float _g8 = (_g7 * 2.0);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(83)
	return ::haxor::math::Vector3_obj::__new(_g2,_g5,_g8)->Normalize();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Random_obj,get_onSphere,return )

::haxor::math::Vector2 Random_obj::circle;

::haxor::math::Vector2 Random_obj::get_circle( ){
	HX_STACK_FRAME("haxor.math.Random","get_circle",0xd172b2ca,"haxor.math.Random.get_circle","haxor/math/Random.hx",89,0x04916aa1)
	HX_STACK_LINE(89)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(89)
	Float _g1 = (_g - 0.499995);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(89)
	Float _g2 = (_g1 * 2.0);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(89)
	Float _g3 = ::Math_obj::random();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(89)
	Float _g4 = (_g3 - 0.499995);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(89)
	Float _g5 = (_g4 * 2.0);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(89)
	Float _g6 = ::Math_obj::random();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(89)
	return ::haxor::math::Vector2_obj::__new(_g2,_g5)->Normalize()->Scale(_g6);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Random_obj,get_circle,return )

::haxor::math::Vector2 Random_obj::onCircle;

::haxor::math::Vector2 Random_obj::get_onCircle( ){
	HX_STACK_FRAME("haxor.math.Random","get_onCircle",0x457ccbc9,"haxor.math.Random.get_onCircle","haxor/math/Random.hx",95,0x04916aa1)
	HX_STACK_LINE(95)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(95)
	Float _g1 = (_g - 0.499995);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(95)
	Float _g2 = (_g1 * 2.0);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(95)
	Float _g3 = ::Math_obj::random();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(95)
	Float _g4 = (_g3 - 0.499995);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(95)
	Float _g5 = (_g4 * 2.0);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(95)
	return ::haxor::math::Vector2_obj::__new(_g2,_g5)->Normalize();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Random_obj,get_onCircle,return )

int Random_obj::Length( int v){
	HX_STACK_FRAME("haxor.math.Random","Length",0xacc04d77,"haxor.math.Random.Length","haxor/math/Random.hx",100,0x04916aa1)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(100)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(100)
	return (((v + (int)1)) * _g);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Random_obj,Length,return )

Float Random_obj::Range( Float p_min,Float p_max){
	HX_STACK_FRAME("haxor.math.Random","Range",0xd542ea4c,"haxor.math.Random.Range","haxor/math/Random.hx",108,0x04916aa1)
	HX_STACK_ARG(p_min,"p_min")
	HX_STACK_ARG(p_max,"p_max")
	HX_STACK_LINE(108)
	Float p_ratio = ::Math_obj::random();		HX_STACK_VAR(p_ratio,"p_ratio");
	HX_STACK_LINE(108)
	return (p_min + (((p_max - p_min)) * p_ratio));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Random_obj,Range,return )

Float Random_obj::RangeInt( int p_min,int p_max){
	HX_STACK_FRAME("haxor.math.Random","RangeInt",0x3e5f5203,"haxor.math.Random.RangeInt","haxor/math/Random.hx",116,0x04916aa1)
	HX_STACK_ARG(p_min,"p_min")
	HX_STACK_ARG(p_max,"p_max")
	HX_STACK_LINE(116)
	Float p_ratio = ::Math_obj::random();		HX_STACK_VAR(p_ratio,"p_ratio");
	struct _Function_1_1{
		inline static Float Block( int &p_min,int &p_max,Float &p_ratio){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Random.hx",116,0x04916aa1)
			{
				HX_STACK_LINE(116)
				Float p_a = p_min;		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(116)
				return (p_a + ((((p_max + (int)1) - p_a)) * p_ratio));
			}
			return null();
		}
	};
	HX_STACK_LINE(116)
	return ::Std_obj::_int(_Function_1_1::Block(p_min,p_max,p_ratio));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Random_obj,RangeInt,return )

Dynamic Random_obj::Item( Dynamic p_list){
	HX_STACK_FRAME("haxor.math.Random","Item",0x82868764,"haxor.math.Random.Item","haxor/math/Random.hx",121,0x04916aa1)
	HX_STACK_ARG(p_list,"p_list")
	HX_STACK_LINE(121)
	Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(121)
	int _g1 = (p_list->__Field(HX_CSTRING("length"),true) * _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(121)
	return p_list->__GetItem(_g1);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Random_obj,Item,return )

Void Random_obj::Shuffle( Dynamic p_list){
{
		HX_STACK_FRAME("haxor.math.Random","Shuffle",0xd8c60c48,"haxor.math.Random.Shuffle","haxor/math/Random.hx",128,0x04916aa1)
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(129)
		int m = p_list->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(130)
		Dynamic t;		HX_STACK_VAR(t,"t");
		HX_STACK_LINE(131)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(133)
		while((true)){
			HX_STACK_LINE(133)
			if ((!(((m > (int)0))))){
				HX_STACK_LINE(133)
				break;
			}
			HX_STACK_LINE(136)
			Float _g = ::Math_obj::random();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(136)
			int _g1 = (m)--;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(136)
			Float _g2 = (_g * _g1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(136)
			int _g3 = ::Math_obj::floor(_g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(136)
			i = _g3;
			HX_STACK_LINE(138)
			t = p_list->__GetItem(m);
			HX_STACK_LINE(139)
			hx::IndexRef((p_list).mPtr,m) = p_list->__GetItem(i);
			HX_STACK_LINE(140)
			hx::IndexRef((p_list).mPtr,i) = t;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Random_obj,Shuffle,(void))


Random_obj::Random_obj()
{
}

Dynamic Random_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"box") ) { return inCallProp ? get_box() : box; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Item") ) { return Item_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { return inCallProp ? get_value() : value; }
		if (HX_FIELD_EQ(inName,"onBox") ) { return inCallProp ? get_onBox() : onBox; }
		if (HX_FIELD_EQ(inName,"Range") ) { return Range_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"square") ) { return inCallProp ? get_square() : square; }
		if (HX_FIELD_EQ(inName,"sphere") ) { return inCallProp ? get_sphere() : sphere; }
		if (HX_FIELD_EQ(inName,"circle") ) { return inCallProp ? get_circle() : circle; }
		if (HX_FIELD_EQ(inName,"Length") ) { return Length_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_box") ) { return get_box_dyn(); }
		if (HX_FIELD_EQ(inName,"Shuffle") ) { return Shuffle_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"interval") ) { return inCallProp ? get_interval() : interval; }
		if (HX_FIELD_EQ(inName,"rotation") ) { return inCallProp ? get_rotation() : rotation; }
		if (HX_FIELD_EQ(inName,"onSquare") ) { return inCallProp ? get_onSquare() : onSquare; }
		if (HX_FIELD_EQ(inName,"onSphere") ) { return inCallProp ? get_onSphere() : onSphere; }
		if (HX_FIELD_EQ(inName,"onCircle") ) { return inCallProp ? get_onCircle() : onCircle; }
		if (HX_FIELD_EQ(inName,"RangeInt") ) { return RangeInt_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_value") ) { return get_value_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onBox") ) { return get_onBox_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_square") ) { return get_square_dyn(); }
		if (HX_FIELD_EQ(inName,"get_sphere") ) { return get_sphere_dyn(); }
		if (HX_FIELD_EQ(inName,"get_circle") ) { return get_circle_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_interval") ) { return get_interval_dyn(); }
		if (HX_FIELD_EQ(inName,"get_rotation") ) { return get_rotation_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onSquare") ) { return get_onSquare_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onSphere") ) { return get_onSphere_dyn(); }
		if (HX_FIELD_EQ(inName,"get_onCircle") ) { return get_onCircle_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Random_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"box") ) { box=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"value") ) { value=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onBox") ) { onBox=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"square") ) { square=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sphere") ) { sphere=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"circle") ) { circle=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"interval") ) { interval=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rotation") ) { rotation=inValue.Cast< ::haxor::math::Quaternion >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onSquare") ) { onSquare=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onSphere") ) { onSphere=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"onCircle") ) { onCircle=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Random_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("value"),
	HX_CSTRING("get_value"),
	HX_CSTRING("interval"),
	HX_CSTRING("get_interval"),
	HX_CSTRING("rotation"),
	HX_CSTRING("get_rotation"),
	HX_CSTRING("box"),
	HX_CSTRING("get_box"),
	HX_CSTRING("onBox"),
	HX_CSTRING("get_onBox"),
	HX_CSTRING("square"),
	HX_CSTRING("get_square"),
	HX_CSTRING("onSquare"),
	HX_CSTRING("get_onSquare"),
	HX_CSTRING("sphere"),
	HX_CSTRING("get_sphere"),
	HX_CSTRING("onSphere"),
	HX_CSTRING("get_onSphere"),
	HX_CSTRING("circle"),
	HX_CSTRING("get_circle"),
	HX_CSTRING("onCircle"),
	HX_CSTRING("get_onCircle"),
	HX_CSTRING("Length"),
	HX_CSTRING("Range"),
	HX_CSTRING("RangeInt"),
	HX_CSTRING("Item"),
	HX_CSTRING("Shuffle"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Random_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Random_obj::value,"value");
	HX_MARK_MEMBER_NAME(Random_obj::interval,"interval");
	HX_MARK_MEMBER_NAME(Random_obj::rotation,"rotation");
	HX_MARK_MEMBER_NAME(Random_obj::box,"box");
	HX_MARK_MEMBER_NAME(Random_obj::onBox,"onBox");
	HX_MARK_MEMBER_NAME(Random_obj::square,"square");
	HX_MARK_MEMBER_NAME(Random_obj::onSquare,"onSquare");
	HX_MARK_MEMBER_NAME(Random_obj::sphere,"sphere");
	HX_MARK_MEMBER_NAME(Random_obj::onSphere,"onSphere");
	HX_MARK_MEMBER_NAME(Random_obj::circle,"circle");
	HX_MARK_MEMBER_NAME(Random_obj::onCircle,"onCircle");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Random_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Random_obj::value,"value");
	HX_VISIT_MEMBER_NAME(Random_obj::interval,"interval");
	HX_VISIT_MEMBER_NAME(Random_obj::rotation,"rotation");
	HX_VISIT_MEMBER_NAME(Random_obj::box,"box");
	HX_VISIT_MEMBER_NAME(Random_obj::onBox,"onBox");
	HX_VISIT_MEMBER_NAME(Random_obj::square,"square");
	HX_VISIT_MEMBER_NAME(Random_obj::onSquare,"onSquare");
	HX_VISIT_MEMBER_NAME(Random_obj::sphere,"sphere");
	HX_VISIT_MEMBER_NAME(Random_obj::onSphere,"onSphere");
	HX_VISIT_MEMBER_NAME(Random_obj::circle,"circle");
	HX_VISIT_MEMBER_NAME(Random_obj::onCircle,"onCircle");
};

#endif

Class Random_obj::__mClass;

void Random_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.math.Random"), hx::TCanCast< Random_obj> ,sStaticFields,sMemberFields,
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

void Random_obj::__boot()
{
}

} // end namespace haxor
} // end namespace math
