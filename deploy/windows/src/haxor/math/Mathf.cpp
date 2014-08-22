#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_math_Mathf
#include <haxor/math/Mathf.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace math{

Void Mathf_obj::__construct()
{
	return null();
}

//Mathf_obj::~Mathf_obj() { }

Dynamic Mathf_obj::__CreateEmpty() { return  new Mathf_obj; }
hx::ObjectPtr< Mathf_obj > Mathf_obj::__new()
{  hx::ObjectPtr< Mathf_obj > result = new Mathf_obj();
	result->__construct();
	return result;}

Dynamic Mathf_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Mathf_obj > result = new Mathf_obj();
	result->__construct();
	return result;}

Float Mathf_obj::Epsilon;

Float Mathf_obj::NaN;

Float Mathf_obj::Infinity;

Float Mathf_obj::NegativeInfinity;

Float Mathf_obj::E;

Float Mathf_obj::PI;

Float Mathf_obj::HalfPI;

Float Mathf_obj::PI2;

Float Mathf_obj::PI4;

Float Mathf_obj::InvPI;

Float Mathf_obj::Rad2Deg;

Float Mathf_obj::Deg2Rad;

Float Mathf_obj::Px2Em;

Float Mathf_obj::Em2Px;

Float Mathf_obj::Byte2Float;

Float Mathf_obj::Short2Float;

Float Mathf_obj::Long2Float;

Float Mathf_obj::Float2Byte;

Float Mathf_obj::Float2Short;

Float Mathf_obj::Float2Long;

bool Mathf_obj::IsPOT( int p_v){
	HX_STACK_FRAME("haxor.math.Mathf","IsPOT",0xd55d00c1,"haxor.math.Mathf.IsPOT","haxor/math/Mathf.hx",32,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(32)
	return (bool((p_v > (int)0)) && bool((((int(p_v) & int((p_v - (int)1)))) == (int)0)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,IsPOT,return )

int Mathf_obj::NextPOT( int p_v){
	HX_STACK_FRAME("haxor.math.Mathf","NextPOT",0xfe950cd8,"haxor.math.Mathf.NextPOT","haxor/math/Mathf.hx",34,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(35)
	--(p_v);
	HX_STACK_LINE(36)
	hx::OrEq(p_v,(int(p_v) >> int((int)1)));
	HX_STACK_LINE(36)
	hx::OrEq(p_v,(int(p_v) >> int((int)2)));
	HX_STACK_LINE(37)
	hx::OrEq(p_v,(int(p_v) >> int((int)4)));
	HX_STACK_LINE(37)
	hx::OrEq(p_v,(int(p_v) >> int((int)8)));
	HX_STACK_LINE(38)
	hx::OrEq(p_v,(int(p_v) >> int((int)16)));
	HX_STACK_LINE(39)
	return ++(p_v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,NextPOT,return )

Float Mathf_obj::Sign( Float p_a){
	HX_STACK_FRAME("haxor.math.Mathf","Sign",0x27ae4c07,"haxor.math.Mathf.Sign","haxor/math/Mathf.hx",42,0x3182889a)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_LINE(42)
	if (((p_a < (int)0))){
		HX_STACK_LINE(42)
		return -1.0;
	}
	else{
		HX_STACK_LINE(42)
		return 1.0;
	}
	HX_STACK_LINE(42)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Sign,return )

int Mathf_obj::SignInt( int p_a){
	HX_STACK_FRAME("haxor.math.Mathf","SignInt",0x9a217728,"haxor.math.Mathf.SignInt","haxor/math/Mathf.hx",43,0x3182889a)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_LINE(43)
	if (((p_a < (int)0))){
		HX_STACK_LINE(43)
		return (int)-1;
	}
	else{
		HX_STACK_LINE(43)
		return (int)1;
	}
	HX_STACK_LINE(43)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,SignInt,return )

Float Mathf_obj::Abs( Float p_a){
	HX_STACK_FRAME("haxor.math.Mathf","Abs",0xcb513be8,"haxor.math.Mathf.Abs","haxor/math/Mathf.hx",44,0x3182889a)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_LINE(44)
	if (((p_a < (int)0))){
		HX_STACK_LINE(44)
		return -(p_a);
	}
	else{
		HX_STACK_LINE(44)
		return p_a;
	}
	HX_STACK_LINE(44)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Abs,return )

int Mathf_obj::AbsInt( int p_a){
	HX_STACK_FRAME("haxor.math.Mathf","AbsInt",0xf676e9e7,"haxor.math.Mathf.AbsInt","haxor/math/Mathf.hx",45,0x3182889a)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_LINE(45)
	if (((p_a < (int)0))){
		HX_STACK_LINE(45)
		return -(p_a);
	}
	else{
		HX_STACK_LINE(45)
		return p_a;
	}
	HX_STACK_LINE(45)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,AbsInt,return )

Float Mathf_obj::Clamp( Float p_v,Float p_min,Float p_max){
	HX_STACK_FRAME("haxor.math.Mathf","Clamp",0x5c6207f1,"haxor.math.Mathf.Clamp","haxor/math/Mathf.hx",46,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_ARG(p_min,"p_min")
	HX_STACK_ARG(p_max,"p_max")
	HX_STACK_LINE(46)
	if (((p_v <= p_min))){
		HX_STACK_LINE(46)
		return p_min;
	}
	else{
		HX_STACK_LINE(46)
		if (((p_v >= p_max))){
			HX_STACK_LINE(46)
			return p_max;
		}
		else{
			HX_STACK_LINE(46)
			return p_v;
		}
	}
	HX_STACK_LINE(46)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Mathf_obj,Clamp,return )

Float Mathf_obj::Clamp01( Float p_v){
	HX_STACK_FRAME("haxor.math.Mathf","Clamp01",0xbee8d032,"haxor.math.Mathf.Clamp01","haxor/math/Mathf.hx",47,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(47)
	if (((p_v <= 0.0))){
		HX_STACK_LINE(47)
		return 0.0;
	}
	else{
		HX_STACK_LINE(47)
		if (((p_v >= 1.0))){
			HX_STACK_LINE(47)
			return 1.0;
		}
		else{
			HX_STACK_LINE(47)
			return p_v;
		}
	}
	HX_STACK_LINE(47)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Clamp01,return )

int Mathf_obj::ClampInt( int p_v,int p_min,int p_max){
	HX_STACK_FRAME("haxor.math.Mathf","ClampInt",0x4ce0897e,"haxor.math.Mathf.ClampInt","haxor/math/Mathf.hx",48,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_ARG(p_min,"p_min")
	HX_STACK_ARG(p_max,"p_max")
	HX_STACK_LINE(48)
	return ::Std_obj::_int((  (((p_v <= p_min))) ? Float(p_min) : Float((  (((p_v >= p_max))) ? Float(p_max) : Float(p_v) )) ));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Mathf_obj,ClampInt,return )

Float Mathf_obj::Min( Float a,Float b){
	HX_STACK_FRAME("haxor.math.Mathf","Min",0xcb5a5d08,"haxor.math.Mathf.Min","haxor/math/Mathf.hx",49,0x3182889a)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(49)
	return ::Math_obj::min(a,b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,Min,return )

Float Mathf_obj::Max( Float a,Float b){
	HX_STACK_FRAME("haxor.math.Mathf","Max",0xcb5a561a,"haxor.math.Mathf.Max","haxor/math/Mathf.hx",50,0x3182889a)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(50)
	return ::Math_obj::max(a,b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,Max,return )

int Mathf_obj::MinInt( int a,int b){
	HX_STACK_FRAME("haxor.math.Mathf","MinInt",0xc73f3cc7,"haxor.math.Mathf.MinInt","haxor/math/Mathf.hx",51,0x3182889a)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(51)
	return ::Math_obj::min(a,b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,MinInt,return )

int Mathf_obj::MaxInt( int a,int b){
	HX_STACK_FRAME("haxor.math.Mathf","MaxInt",0x32a6baf5,"haxor.math.Mathf.MaxInt","haxor/math/Mathf.hx",52,0x3182889a)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(52)
	return ::Math_obj::max(a,b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,MaxInt,return )

Float Mathf_obj::Sin( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","Sin",0xcb5eea8e,"haxor.math.Mathf.Sin","haxor/math/Mathf.hx",53,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(53)
	return ::Math_obj::sin(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Sin,return )

Float Mathf_obj::Cos( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","Cos",0xcb52cbbd,"haxor.math.Mathf.Cos","haxor/math/Mathf.hx",54,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(54)
	return ::Math_obj::cos(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Cos,return )

Float Mathf_obj::ASin( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","ASin",0x1bb7c501,"haxor.math.Mathf.ASin","haxor/math/Mathf.hx",55,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(55)
	return ::Math_obj::asin(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,ASin,return )

Float Mathf_obj::ACos( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","ACos",0x1baba630,"haxor.math.Mathf.ACos","haxor/math/Mathf.hx",56,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(56)
	return ::Math_obj::acos(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,ACos,return )

Float Mathf_obj::Tan( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","Tan",0xcb5fa5d7,"haxor.math.Mathf.Tan","haxor/math/Mathf.hx",57,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(57)
	return ::Math_obj::tan(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Tan,return )

Float Mathf_obj::ATan( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","ATan",0x1bb8804a,"haxor.math.Mathf.ATan","haxor/math/Mathf.hx",58,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(58)
	return ::Math_obj::atan(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,ATan,return )

Float Mathf_obj::ATan2( Float y,Float x){
	HX_STACK_FRAME("haxor.math.Mathf","ATan2",0x25b7c0a8,"haxor.math.Mathf.ATan2","haxor/math/Mathf.hx",59,0x3182889a)
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(59)
	return ::Math_obj::atan2(y,x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,ATan2,return )

Float Mathf_obj::Sqrt( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","Sqrt",0x27b467aa,"haxor.math.Mathf.Sqrt","haxor/math/Mathf.hx",60,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(60)
	return ::Math_obj::sqrt(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Sqrt,return )

Float Mathf_obj::Pow( Float b,Float exp){
	HX_STACK_FRAME("haxor.math.Mathf","Pow",0xcb5ca90e,"haxor.math.Mathf.Pow","haxor/math/Mathf.hx",61,0x3182889a)
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(exp,"exp")
	HX_STACK_LINE(61)
	return ::Math_obj::pow(b,exp);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,Pow,return )

Float Mathf_obj::Floor( Float p_v){
	HX_STACK_FRAME("haxor.math.Mathf","Floor",0x16a066c2,"haxor.math.Mathf.Floor","haxor/math/Mathf.hx",63,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(63)
	return ::Std_obj::_int(p_v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Floor,return )

Float Mathf_obj::Ceil( Float p_v){
	HX_STACK_FRAME("haxor.math.Mathf","Ceil",0x1d17dacf,"haxor.math.Mathf.Ceil","haxor/math/Mathf.hx",64,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(64)
	return ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.9999999) : Float(0.9999999) ))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Ceil,return )

Float Mathf_obj::Round( Float p_v){
	HX_STACK_FRAME("haxor.math.Mathf","Round",0x016f8d44,"haxor.math.Mathf.Round","haxor/math/Mathf.hx",65,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(65)
	return ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Round,return )

Float Mathf_obj::RoundPlaces( Float p_v,hx::Null< int >  __o_p_decimal_places){
int p_decimal_places = __o_p_decimal_places.Default(2);
	HX_STACK_FRAME("haxor.math.Mathf","RoundPlaces",0x09078630,"haxor.math.Mathf.RoundPlaces","haxor/math/Mathf.hx",67,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_ARG(p_decimal_places,"p_decimal_places")
{
		HX_STACK_LINE(68)
		Float d = ::Math_obj::pow((int)10,p_decimal_places);		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(69)
		Float _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(69)
		{
			HX_STACK_LINE(69)
			Float p_v1 = (p_v * d);		HX_STACK_VAR(p_v1,"p_v1");
			HX_STACK_LINE(69)
			_g = ::Std_obj::_int((p_v1 + ((  (((p_v1 < (int)0))) ? Float(-0.5) : Float(0.5) ))));
		}
		HX_STACK_LINE(69)
		return (Float(_g) / Float(d));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,RoundPlaces,return )

Float Mathf_obj::Lerp( Float p_a,Float p_b,Float p_ratio){
	HX_STACK_FRAME("haxor.math.Mathf","Lerp",0x230ace41,"haxor.math.Mathf.Lerp","haxor/math/Mathf.hx",72,0x3182889a)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_ratio,"p_ratio")
	HX_STACK_LINE(72)
	return (p_a + (((p_b - p_a)) * p_ratio));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Mathf_obj,Lerp,return )

int Mathf_obj::LerpInt( int p_a,int p_b,Float p_ratio){
	HX_STACK_FRAME("haxor.math.Mathf","LerpInt",0x3458952e,"haxor.math.Mathf.LerpInt","haxor/math/Mathf.hx",73,0x3182889a)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_ratio,"p_ratio")
	struct _Function_1_1{
		inline static Float Block( int &p_a,int &p_b,Float &p_ratio){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Mathf.hx",73,0x3182889a)
			{
				HX_STACK_LINE(73)
				Float p_a1 = p_a;		HX_STACK_VAR(p_a1,"p_a1");
				HX_STACK_LINE(73)
				return (p_a1 + (((p_b - p_a1)) * p_ratio));
			}
			return null();
		}
	};
	HX_STACK_LINE(73)
	return ::Std_obj::_int(_Function_1_1::Block(p_a,p_b,p_ratio));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Mathf_obj,LerpInt,return )

Float Mathf_obj::Frac( Float p_v){
	HX_STACK_FRAME("haxor.math.Mathf","Frac",0x1f1d54f8,"haxor.math.Mathf.Frac","haxor/math/Mathf.hx",75,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(75)
	Float _g = ::Math_obj::ffloor(p_v);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(75)
	return (p_v - _g);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Frac,return )

Float Mathf_obj::Loop( Float p_v,Float p_v0,Float p_v1){
	HX_STACK_FRAME("haxor.math.Mathf","Loop",0x2312622e,"haxor.math.Mathf.Loop","haxor/math/Mathf.hx",78,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_ARG(p_v0,"p_v0")
	HX_STACK_ARG(p_v1,"p_v1")
	HX_STACK_LINE(79)
	Float vv0 = ::Math_obj::min(p_v0,p_v1);		HX_STACK_VAR(vv0,"vv0");
	HX_STACK_LINE(80)
	Float vv1 = ::Math_obj::max(p_v0,p_v1);		HX_STACK_VAR(vv1,"vv1");
	HX_STACK_LINE(81)
	Float dv = (vv1 - vv0);		HX_STACK_VAR(dv,"dv");
	HX_STACK_LINE(82)
	if (((dv <= (int)0))){
		HX_STACK_LINE(82)
		return vv0;
	}
	HX_STACK_LINE(83)
	Float n = (Float(((p_v - p_v0))) / Float(dv));		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(84)
	Float r;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(84)
	if (((p_v < (int)0))){
		HX_STACK_LINE(84)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(84)
		{
			HX_STACK_LINE(84)
			Float p_v2;		HX_STACK_VAR(p_v2,"p_v2");
			HX_STACK_LINE(84)
			if (((n < (int)0))){
				HX_STACK_LINE(84)
				p_v2 = -(n);
			}
			else{
				HX_STACK_LINE(84)
				p_v2 = n;
			}
			HX_STACK_LINE(84)
			Float _g = ::Math_obj::ffloor(p_v2);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(84)
			_g1 = (p_v2 - _g);
		}
		HX_STACK_LINE(84)
		r = (1.0 - _g1);
	}
	else{
		HX_STACK_LINE(84)
		Float _g2 = ::Math_obj::ffloor(n);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(84)
		r = (n - _g2);
	}
	HX_STACK_LINE(85)
	return (p_v0 + (((p_v1 - p_v0)) * r));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Mathf_obj,Loop,return )

Float Mathf_obj::Linear2Gamma( Float p_v){
	HX_STACK_FRAME("haxor.math.Mathf","Linear2Gamma",0x512ce304,"haxor.math.Mathf.Linear2Gamma","haxor/math/Mathf.hx",88,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(88)
	return ::Math_obj::pow(p_v,2.2);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Linear2Gamma,return )

Float Mathf_obj::Oscilate( Float p_v,Float p_v0,Float p_v1){
	HX_STACK_FRAME("haxor.math.Mathf","Oscilate",0x9adde9ba,"haxor.math.Mathf.Oscilate","haxor/math/Mathf.hx",91,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_ARG(p_v0,"p_v0")
	HX_STACK_ARG(p_v1,"p_v1")
	struct _Function_1_1{
		inline static Float Block( Float &p_v){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Mathf.hx",93,0x3182889a)
			{
				HX_STACK_LINE(93)
				Float p_a = ::haxor::math::Mathf_obj::Loop((p_v - 1.0),-1.0,1.0);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(93)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	HX_STACK_LINE(93)
	Float _g = -(_Function_1_1::Block(p_v));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(93)
	Float w = (_g + 1.0);		HX_STACK_VAR(w,"w");
	HX_STACK_LINE(94)
	return (w + (((p_v0 - w)) * p_v1));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Mathf_obj,Oscilate,return )

Float Mathf_obj::WrapAngle( Float p_angle){
	HX_STACK_FRAME("haxor.math.Mathf","WrapAngle",0x054f059f,"haxor.math.Mathf.WrapAngle","haxor/math/Mathf.hx",98,0x3182889a)
	HX_STACK_ARG(p_angle,"p_angle")
	HX_STACK_LINE(99)
	if (((p_angle < 360.0))){
		HX_STACK_LINE(99)
		if (((p_angle > -360.0))){
			HX_STACK_LINE(99)
			return p_angle;
		}
	}
	HX_STACK_LINE(100)
	Float _g1;		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(100)
	{
		HX_STACK_LINE(100)
		Float p_v;		HX_STACK_VAR(p_v,"p_v");
		HX_STACK_LINE(100)
		p_v = (Float(((  (((p_angle < (int)0))) ? Float(-(p_angle)) : Float(p_angle) ))) / Float(360.0));
		HX_STACK_LINE(100)
		Float _g = ::Math_obj::ffloor(p_v);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(100)
		_g1 = (p_v - _g);
	}
	HX_STACK_LINE(100)
	return (_g1 * 360.0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,WrapAngle,return )


Mathf_obj::Mathf_obj()
{
}

Dynamic Mathf_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"NaN") ) { return NaN; }
		if (HX_FIELD_EQ(inName,"Abs") ) { return Abs_dyn(); }
		if (HX_FIELD_EQ(inName,"Min") ) { return Min_dyn(); }
		if (HX_FIELD_EQ(inName,"Max") ) { return Max_dyn(); }
		if (HX_FIELD_EQ(inName,"Sin") ) { return Sin_dyn(); }
		if (HX_FIELD_EQ(inName,"Cos") ) { return Cos_dyn(); }
		if (HX_FIELD_EQ(inName,"Tan") ) { return Tan_dyn(); }
		if (HX_FIELD_EQ(inName,"Pow") ) { return Pow_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Sign") ) { return Sign_dyn(); }
		if (HX_FIELD_EQ(inName,"ASin") ) { return ASin_dyn(); }
		if (HX_FIELD_EQ(inName,"ACos") ) { return ACos_dyn(); }
		if (HX_FIELD_EQ(inName,"ATan") ) { return ATan_dyn(); }
		if (HX_FIELD_EQ(inName,"Sqrt") ) { return Sqrt_dyn(); }
		if (HX_FIELD_EQ(inName,"Ceil") ) { return Ceil_dyn(); }
		if (HX_FIELD_EQ(inName,"Lerp") ) { return Lerp_dyn(); }
		if (HX_FIELD_EQ(inName,"Frac") ) { return Frac_dyn(); }
		if (HX_FIELD_EQ(inName,"Loop") ) { return Loop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"IsPOT") ) { return IsPOT_dyn(); }
		if (HX_FIELD_EQ(inName,"Clamp") ) { return Clamp_dyn(); }
		if (HX_FIELD_EQ(inName,"ATan2") ) { return ATan2_dyn(); }
		if (HX_FIELD_EQ(inName,"Floor") ) { return Floor_dyn(); }
		if (HX_FIELD_EQ(inName,"Round") ) { return Round_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"AbsInt") ) { return AbsInt_dyn(); }
		if (HX_FIELD_EQ(inName,"MinInt") ) { return MinInt_dyn(); }
		if (HX_FIELD_EQ(inName,"MaxInt") ) { return MaxInt_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"NextPOT") ) { return NextPOT_dyn(); }
		if (HX_FIELD_EQ(inName,"SignInt") ) { return SignInt_dyn(); }
		if (HX_FIELD_EQ(inName,"Clamp01") ) { return Clamp01_dyn(); }
		if (HX_FIELD_EQ(inName,"LerpInt") ) { return LerpInt_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Infinity") ) { return Infinity; }
		if (HX_FIELD_EQ(inName,"ClampInt") ) { return ClampInt_dyn(); }
		if (HX_FIELD_EQ(inName,"Oscilate") ) { return Oscilate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"WrapAngle") ) { return WrapAngle_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"RoundPlaces") ) { return RoundPlaces_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"Linear2Gamma") ) { return Linear2Gamma_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"NegativeInfinity") ) { return NegativeInfinity; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Mathf_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"NaN") ) { NaN=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Infinity") ) { Infinity=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"NegativeInfinity") ) { NegativeInfinity=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Mathf_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Epsilon"),
	HX_CSTRING("NaN"),
	HX_CSTRING("Infinity"),
	HX_CSTRING("NegativeInfinity"),
	HX_CSTRING("E"),
	HX_CSTRING("PI"),
	HX_CSTRING("HalfPI"),
	HX_CSTRING("PI2"),
	HX_CSTRING("PI4"),
	HX_CSTRING("InvPI"),
	HX_CSTRING("Rad2Deg"),
	HX_CSTRING("Deg2Rad"),
	HX_CSTRING("Px2Em"),
	HX_CSTRING("Em2Px"),
	HX_CSTRING("Byte2Float"),
	HX_CSTRING("Short2Float"),
	HX_CSTRING("Long2Float"),
	HX_CSTRING("Float2Byte"),
	HX_CSTRING("Float2Short"),
	HX_CSTRING("Float2Long"),
	HX_CSTRING("IsPOT"),
	HX_CSTRING("NextPOT"),
	HX_CSTRING("Sign"),
	HX_CSTRING("SignInt"),
	HX_CSTRING("Abs"),
	HX_CSTRING("AbsInt"),
	HX_CSTRING("Clamp"),
	HX_CSTRING("Clamp01"),
	HX_CSTRING("ClampInt"),
	HX_CSTRING("Min"),
	HX_CSTRING("Max"),
	HX_CSTRING("MinInt"),
	HX_CSTRING("MaxInt"),
	HX_CSTRING("Sin"),
	HX_CSTRING("Cos"),
	HX_CSTRING("ASin"),
	HX_CSTRING("ACos"),
	HX_CSTRING("Tan"),
	HX_CSTRING("ATan"),
	HX_CSTRING("ATan2"),
	HX_CSTRING("Sqrt"),
	HX_CSTRING("Pow"),
	HX_CSTRING("Floor"),
	HX_CSTRING("Ceil"),
	HX_CSTRING("Round"),
	HX_CSTRING("RoundPlaces"),
	HX_CSTRING("Lerp"),
	HX_CSTRING("LerpInt"),
	HX_CSTRING("Frac"),
	HX_CSTRING("Loop"),
	HX_CSTRING("Linear2Gamma"),
	HX_CSTRING("Oscilate"),
	HX_CSTRING("WrapAngle"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Mathf_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Mathf_obj::Epsilon,"Epsilon");
	HX_MARK_MEMBER_NAME(Mathf_obj::NaN,"NaN");
	HX_MARK_MEMBER_NAME(Mathf_obj::Infinity,"Infinity");
	HX_MARK_MEMBER_NAME(Mathf_obj::NegativeInfinity,"NegativeInfinity");
	HX_MARK_MEMBER_NAME(Mathf_obj::E,"E");
	HX_MARK_MEMBER_NAME(Mathf_obj::PI,"PI");
	HX_MARK_MEMBER_NAME(Mathf_obj::HalfPI,"HalfPI");
	HX_MARK_MEMBER_NAME(Mathf_obj::PI2,"PI2");
	HX_MARK_MEMBER_NAME(Mathf_obj::PI4,"PI4");
	HX_MARK_MEMBER_NAME(Mathf_obj::InvPI,"InvPI");
	HX_MARK_MEMBER_NAME(Mathf_obj::Rad2Deg,"Rad2Deg");
	HX_MARK_MEMBER_NAME(Mathf_obj::Deg2Rad,"Deg2Rad");
	HX_MARK_MEMBER_NAME(Mathf_obj::Px2Em,"Px2Em");
	HX_MARK_MEMBER_NAME(Mathf_obj::Em2Px,"Em2Px");
	HX_MARK_MEMBER_NAME(Mathf_obj::Byte2Float,"Byte2Float");
	HX_MARK_MEMBER_NAME(Mathf_obj::Short2Float,"Short2Float");
	HX_MARK_MEMBER_NAME(Mathf_obj::Long2Float,"Long2Float");
	HX_MARK_MEMBER_NAME(Mathf_obj::Float2Byte,"Float2Byte");
	HX_MARK_MEMBER_NAME(Mathf_obj::Float2Short,"Float2Short");
	HX_MARK_MEMBER_NAME(Mathf_obj::Float2Long,"Float2Long");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Mathf_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Mathf_obj::Epsilon,"Epsilon");
	HX_VISIT_MEMBER_NAME(Mathf_obj::NaN,"NaN");
	HX_VISIT_MEMBER_NAME(Mathf_obj::Infinity,"Infinity");
	HX_VISIT_MEMBER_NAME(Mathf_obj::NegativeInfinity,"NegativeInfinity");
	HX_VISIT_MEMBER_NAME(Mathf_obj::E,"E");
	HX_VISIT_MEMBER_NAME(Mathf_obj::PI,"PI");
	HX_VISIT_MEMBER_NAME(Mathf_obj::HalfPI,"HalfPI");
	HX_VISIT_MEMBER_NAME(Mathf_obj::PI2,"PI2");
	HX_VISIT_MEMBER_NAME(Mathf_obj::PI4,"PI4");
	HX_VISIT_MEMBER_NAME(Mathf_obj::InvPI,"InvPI");
	HX_VISIT_MEMBER_NAME(Mathf_obj::Rad2Deg,"Rad2Deg");
	HX_VISIT_MEMBER_NAME(Mathf_obj::Deg2Rad,"Deg2Rad");
	HX_VISIT_MEMBER_NAME(Mathf_obj::Px2Em,"Px2Em");
	HX_VISIT_MEMBER_NAME(Mathf_obj::Em2Px,"Em2Px");
	HX_VISIT_MEMBER_NAME(Mathf_obj::Byte2Float,"Byte2Float");
	HX_VISIT_MEMBER_NAME(Mathf_obj::Short2Float,"Short2Float");
	HX_VISIT_MEMBER_NAME(Mathf_obj::Long2Float,"Long2Float");
	HX_VISIT_MEMBER_NAME(Mathf_obj::Float2Byte,"Float2Byte");
	HX_VISIT_MEMBER_NAME(Mathf_obj::Float2Short,"Float2Short");
	HX_VISIT_MEMBER_NAME(Mathf_obj::Float2Long,"Float2Long");
};

#endif

Class Mathf_obj::__mClass;

void Mathf_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.math.Mathf"), hx::TCanCast< Mathf_obj> ,sStaticFields,sMemberFields,
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

void Mathf_obj::__boot()
{
	Epsilon= 1e-005;
	NaN= ::Math_obj::NaN;
	Infinity= ::Math_obj::POSITIVE_INFINITY;
	NegativeInfinity= ::Math_obj::NEGATIVE_INFINITY;
	E= 2.7182818284590452353602874713527;
	PI= 3.1415926535897932384626433832795028841971693993751058;
	HalfPI= 1.5707963267948966192313216916398;
	PI2= 6.283185307179586476925286766559;
	PI4= 12.566370614359172953850573533118;
	InvPI= 0.31830988618379067153776752674503;
	Rad2Deg= 57.295779513082320876798154814105;
	Deg2Rad= 0.01745329251994329576923690768489;
	Px2Em= 0.063;
	Em2Px= 15.87301587301587;
	Byte2Float= 0.00392156863;
	Short2Float= 0.0000152587890625;
	Long2Float= 0.00000000023283064365386962890625;
	Float2Byte= 255.0;
	Float2Short= 65536.0;
	Float2Long= 4294967296.0;
}

} // end namespace haxor
} // end namespace math
