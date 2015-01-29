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
	HX_STACK_FRAME("haxor.math.Mathf","IsPOT",0xd55d00c1,"haxor.math.Mathf.IsPOT","haxor/math/Mathf.hx",117,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(117)
	return (bool((p_v > (int)0)) && bool((((int(p_v) & int((p_v - (int)1)))) == (int)0)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,IsPOT,return )

int Mathf_obj::NextPOT( int p_v){
	HX_STACK_FRAME("haxor.math.Mathf","NextPOT",0xfe950cd8,"haxor.math.Mathf.NextPOT","haxor/math/Mathf.hx",125,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(126)
	--(p_v);
	HX_STACK_LINE(127)
	hx::OrEq(p_v,(int(p_v) >> int((int)1)));
	HX_STACK_LINE(127)
	hx::OrEq(p_v,(int(p_v) >> int((int)2)));
	HX_STACK_LINE(128)
	hx::OrEq(p_v,(int(p_v) >> int((int)4)));
	HX_STACK_LINE(128)
	hx::OrEq(p_v,(int(p_v) >> int((int)8)));
	HX_STACK_LINE(129)
	hx::OrEq(p_v,(int(p_v) >> int((int)16)));
	HX_STACK_LINE(130)
	return ++(p_v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,NextPOT,return )

Float Mathf_obj::Sign( Float p_a){
	HX_STACK_FRAME("haxor.math.Mathf","Sign",0x27ae4c07,"haxor.math.Mathf.Sign","haxor/math/Mathf.hx",138,0x3182889a)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_LINE(138)
	if (((p_a < (int)0))){
		HX_STACK_LINE(138)
		return -1.0;
	}
	else{
		HX_STACK_LINE(138)
		return 1.0;
	}
	HX_STACK_LINE(138)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Sign,return )

int Mathf_obj::SignInt( int p_a){
	HX_STACK_FRAME("haxor.math.Mathf","SignInt",0x9a217728,"haxor.math.Mathf.SignInt","haxor/math/Mathf.hx",145,0x3182889a)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_LINE(145)
	if (((p_a < (int)0))){
		HX_STACK_LINE(145)
		return (int)-1;
	}
	else{
		HX_STACK_LINE(145)
		return (int)1;
	}
	HX_STACK_LINE(145)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,SignInt,return )

Float Mathf_obj::Abs( Float p_a){
	HX_STACK_FRAME("haxor.math.Mathf","Abs",0xcb513be8,"haxor.math.Mathf.Abs","haxor/math/Mathf.hx",152,0x3182889a)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_LINE(152)
	if (((p_a < (int)0))){
		HX_STACK_LINE(152)
		return -(p_a);
	}
	else{
		HX_STACK_LINE(152)
		return p_a;
	}
	HX_STACK_LINE(152)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Abs,return )

int Mathf_obj::AbsInt( int p_a){
	HX_STACK_FRAME("haxor.math.Mathf","AbsInt",0xf676e9e7,"haxor.math.Mathf.AbsInt","haxor/math/Mathf.hx",159,0x3182889a)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_LINE(159)
	if (((p_a < (int)0))){
		HX_STACK_LINE(159)
		return -(p_a);
	}
	else{
		HX_STACK_LINE(159)
		return p_a;
	}
	HX_STACK_LINE(159)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,AbsInt,return )

Float Mathf_obj::Clamp( Float p_v,Float p_min,Float p_max){
	HX_STACK_FRAME("haxor.math.Mathf","Clamp",0x5c6207f1,"haxor.math.Mathf.Clamp","haxor/math/Mathf.hx",168,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_ARG(p_min,"p_min")
	HX_STACK_ARG(p_max,"p_max")
	HX_STACK_LINE(168)
	if (((p_v <= p_min))){
		HX_STACK_LINE(168)
		return p_min;
	}
	else{
		HX_STACK_LINE(168)
		if (((p_v >= p_max))){
			HX_STACK_LINE(168)
			return p_max;
		}
		else{
			HX_STACK_LINE(168)
			return p_v;
		}
	}
	HX_STACK_LINE(168)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Mathf_obj,Clamp,return )

Float Mathf_obj::Clamp01( Float p_v){
	HX_STACK_FRAME("haxor.math.Mathf","Clamp01",0xbee8d032,"haxor.math.Mathf.Clamp01","haxor/math/Mathf.hx",175,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(175)
	if (((p_v <= 0.0))){
		HX_STACK_LINE(175)
		return 0.0;
	}
	else{
		HX_STACK_LINE(175)
		if (((p_v >= 1.0))){
			HX_STACK_LINE(175)
			return 1.0;
		}
		else{
			HX_STACK_LINE(175)
			return p_v;
		}
	}
	HX_STACK_LINE(175)
	return 0.;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Clamp01,return )

int Mathf_obj::ClampInt( int p_v,int p_min,int p_max){
	HX_STACK_FRAME("haxor.math.Mathf","ClampInt",0x4ce0897e,"haxor.math.Mathf.ClampInt","haxor/math/Mathf.hx",184,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_ARG(p_min,"p_min")
	HX_STACK_ARG(p_max,"p_max")
	HX_STACK_LINE(184)
	return ::Std_obj::_int((  (((p_v <= p_min))) ? Float(p_min) : Float((  (((p_v >= p_max))) ? Float(p_max) : Float(p_v) )) ));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Mathf_obj,ClampInt,return )

Float Mathf_obj::Min( Float a,Float b){
	HX_STACK_FRAME("haxor.math.Mathf","Min",0xcb5a5d08,"haxor.math.Mathf.Min","haxor/math/Mathf.hx",192,0x3182889a)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(192)
	return ::Math_obj::min(a,b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,Min,return )

Float Mathf_obj::MinRange( Array< Float > v){
	HX_STACK_FRAME("haxor.math.Mathf","MinRange",0xa91c7b95,"haxor.math.Mathf.MinRange","haxor/math/Mathf.hx",199,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(199)
	if (((v->length <= (int)0))){
		HX_STACK_LINE(199)
		return 0.0;
	}
	HX_STACK_LINE(199)
	Float n = v->__get((int)0);		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(199)
	{
		HX_STACK_LINE(199)
		int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(199)
		int _g = v->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(199)
		while((true)){
			HX_STACK_LINE(199)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(199)
				break;
			}
			HX_STACK_LINE(199)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(199)
			Float _g2 = ::Math_obj::min(n,v->__get(i));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(199)
			n = _g2;
		}
	}
	HX_STACK_LINE(199)
	return n;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,MinRange,return )

Float Mathf_obj::Max( Float a,Float b){
	HX_STACK_FRAME("haxor.math.Mathf","Max",0xcb5a561a,"haxor.math.Mathf.Max","haxor/math/Mathf.hx",207,0x3182889a)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(207)
	return ::Math_obj::max(a,b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,Max,return )

Float Mathf_obj::MaxRange( Array< Float > v){
	HX_STACK_FRAME("haxor.math.Mathf","MaxRange",0x5c026143,"haxor.math.Mathf.MaxRange","haxor/math/Mathf.hx",214,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(214)
	if (((v->length <= (int)0))){
		HX_STACK_LINE(214)
		return 0.0;
	}
	HX_STACK_LINE(214)
	Float n = v->__get((int)0);		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(214)
	{
		HX_STACK_LINE(214)
		int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(214)
		int _g = v->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(214)
		while((true)){
			HX_STACK_LINE(214)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(214)
				break;
			}
			HX_STACK_LINE(214)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(214)
			Float _g2 = ::Math_obj::max(n,v->__get(i));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(214)
			n = _g2;
		}
	}
	HX_STACK_LINE(214)
	return n;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,MaxRange,return )

int Mathf_obj::MinInt( int a,int b){
	HX_STACK_FRAME("haxor.math.Mathf","MinInt",0xc73f3cc7,"haxor.math.Mathf.MinInt","haxor/math/Mathf.hx",222,0x3182889a)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(222)
	return ::Math_obj::min(a,b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,MinInt,return )

int Mathf_obj::MaxInt( int a,int b){
	HX_STACK_FRAME("haxor.math.Mathf","MaxInt",0x32a6baf5,"haxor.math.Mathf.MaxInt","haxor/math/Mathf.hx",230,0x3182889a)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(230)
	return ::Math_obj::max(a,b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,MaxInt,return )

Float Mathf_obj::Sin( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","Sin",0xcb5eea8e,"haxor.math.Mathf.Sin","haxor/math/Mathf.hx",237,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(237)
	return ::Math_obj::sin(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Sin,return )

Float Mathf_obj::Cos( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","Cos",0xcb52cbbd,"haxor.math.Mathf.Cos","haxor/math/Mathf.hx",244,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(244)
	return ::Math_obj::cos(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Cos,return )

Float Mathf_obj::Asin( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","Asin",0x1bd00d21,"haxor.math.Mathf.Asin","haxor/math/Mathf.hx",251,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(251)
	return ::Math_obj::asin(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Asin,return )

Float Mathf_obj::Acos( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","Acos",0x1bc3ee50,"haxor.math.Mathf.Acos","haxor/math/Mathf.hx",258,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(258)
	return ::Math_obj::acos(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Acos,return )

Float Mathf_obj::Tan( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","Tan",0xcb5fa5d7,"haxor.math.Mathf.Tan","haxor/math/Mathf.hx",265,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(265)
	return ::Math_obj::tan(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Tan,return )

Float Mathf_obj::ATan( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","ATan",0x1bb8804a,"haxor.math.Mathf.ATan","haxor/math/Mathf.hx",272,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(272)
	return ::Math_obj::atan(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,ATan,return )

Float Mathf_obj::ATan2( Float y,Float x){
	HX_STACK_FRAME("haxor.math.Mathf","ATan2",0x25b7c0a8,"haxor.math.Mathf.ATan2","haxor/math/Mathf.hx",279,0x3182889a)
	HX_STACK_ARG(y,"y")
	HX_STACK_ARG(x,"x")
	HX_STACK_LINE(279)
	return ::Math_obj::atan2(y,x);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,ATan2,return )

Float Mathf_obj::Sqrt( Float v){
	HX_STACK_FRAME("haxor.math.Mathf","Sqrt",0x27b467aa,"haxor.math.Mathf.Sqrt","haxor/math/Mathf.hx",286,0x3182889a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(286)
	return ::Math_obj::sqrt(v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Sqrt,return )

Float Mathf_obj::Pow( Float b,Float exp){
	HX_STACK_FRAME("haxor.math.Mathf","Pow",0xcb5ca90e,"haxor.math.Mathf.Pow","haxor/math/Mathf.hx",294,0x3182889a)
	HX_STACK_ARG(b,"b")
	HX_STACK_ARG(exp,"exp")
	HX_STACK_LINE(294)
	return ::Math_obj::pow(b,exp);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,Pow,return )

Float Mathf_obj::Floor( Float p_v){
	HX_STACK_FRAME("haxor.math.Mathf","Floor",0x16a066c2,"haxor.math.Mathf.Floor","haxor/math/Mathf.hx",301,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(301)
	return ::Std_obj::_int(p_v);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Floor,return )

Float Mathf_obj::Ceil( Float p_v){
	HX_STACK_FRAME("haxor.math.Mathf","Ceil",0x1d17dacf,"haxor.math.Mathf.Ceil","haxor/math/Mathf.hx",308,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(308)
	return ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.9999999) : Float(0.9999999) ))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Ceil,return )

Float Mathf_obj::Round( Float p_v){
	HX_STACK_FRAME("haxor.math.Mathf","Round",0x016f8d44,"haxor.math.Mathf.Round","haxor/math/Mathf.hx",315,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(315)
	return ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Round,return )

Float Mathf_obj::RoundPlaces( Float p_v,hx::Null< int >  __o_p_decimal_places){
int p_decimal_places = __o_p_decimal_places.Default(2);
	HX_STACK_FRAME("haxor.math.Mathf","RoundPlaces",0x09078630,"haxor.math.Mathf.RoundPlaces","haxor/math/Mathf.hx",324,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_ARG(p_decimal_places,"p_decimal_places")
{
		HX_STACK_LINE(325)
		Float d = ::Math_obj::pow((int)10,p_decimal_places);		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(326)
		Float _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(326)
		{
			HX_STACK_LINE(326)
			Float p_v1 = (p_v * d);		HX_STACK_VAR(p_v1,"p_v1");
			HX_STACK_LINE(326)
			_g = ::Std_obj::_int((p_v1 + ((  (((p_v1 < (int)0))) ? Float(-0.5) : Float(0.5) ))));
		}
		HX_STACK_LINE(326)
		return (Float(_g) / Float(d));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Mathf_obj,RoundPlaces,return )

Float Mathf_obj::Lerp( Float p_a,Float p_b,Float p_ratio){
	HX_STACK_FRAME("haxor.math.Mathf","Lerp",0x230ace41,"haxor.math.Mathf.Lerp","haxor/math/Mathf.hx",336,0x3182889a)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_ratio,"p_ratio")
	HX_STACK_LINE(336)
	return (p_a + (((p_b - p_a)) * p_ratio));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Mathf_obj,Lerp,return )

int Mathf_obj::LerpInt( int p_a,int p_b,Float p_ratio){
	HX_STACK_FRAME("haxor.math.Mathf","LerpInt",0x3458952e,"haxor.math.Mathf.LerpInt","haxor/math/Mathf.hx",345,0x3182889a)
	HX_STACK_ARG(p_a,"p_a")
	HX_STACK_ARG(p_b,"p_b")
	HX_STACK_ARG(p_ratio,"p_ratio")
	struct _Function_1_1{
		inline static Float Block( int &p_a,int &p_b,Float &p_ratio){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Mathf.hx",345,0x3182889a)
			{
				HX_STACK_LINE(345)
				Float p_a1 = p_a;		HX_STACK_VAR(p_a1,"p_a1");
				HX_STACK_LINE(345)
				return (p_a1 + (((p_b - p_a1)) * p_ratio));
			}
			return null();
		}
	};
	HX_STACK_LINE(345)
	return ::Std_obj::_int(_Function_1_1::Block(p_a,p_b,p_ratio));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Mathf_obj,LerpInt,return )

Float Mathf_obj::Frac( Float p_v){
	HX_STACK_FRAME("haxor.math.Mathf","Frac",0x1f1d54f8,"haxor.math.Mathf.Frac","haxor/math/Mathf.hx",352,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(352)
	Float _g = ::Math_obj::ffloor(p_v);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(352)
	return (p_v - _g);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Frac,return )

Float Mathf_obj::Loop( Float p_v,Float p_v0,Float p_v1){
	HX_STACK_FRAME("haxor.math.Mathf","Loop",0x2312622e,"haxor.math.Mathf.Loop","haxor/math/Mathf.hx",362,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_ARG(p_v0,"p_v0")
	HX_STACK_ARG(p_v1,"p_v1")
	HX_STACK_LINE(363)
	Float vv0 = ::Math_obj::min(p_v0,p_v1);		HX_STACK_VAR(vv0,"vv0");
	HX_STACK_LINE(364)
	Float vv1 = ::Math_obj::max(p_v0,p_v1);		HX_STACK_VAR(vv1,"vv1");
	HX_STACK_LINE(365)
	Float dv = (vv1 - vv0);		HX_STACK_VAR(dv,"dv");
	HX_STACK_LINE(366)
	if (((dv <= (int)0))){
		HX_STACK_LINE(366)
		return vv0;
	}
	HX_STACK_LINE(367)
	Float n = (Float(((p_v - p_v0))) / Float(dv));		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(368)
	Float r;		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(368)
	if (((p_v < (int)0))){
		HX_STACK_LINE(368)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(368)
		{
			HX_STACK_LINE(368)
			Float p_v2;		HX_STACK_VAR(p_v2,"p_v2");
			HX_STACK_LINE(368)
			if (((n < (int)0))){
				HX_STACK_LINE(368)
				p_v2 = -(n);
			}
			else{
				HX_STACK_LINE(368)
				p_v2 = n;
			}
			HX_STACK_LINE(368)
			Float _g = ::Math_obj::ffloor(p_v2);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(368)
			_g1 = (p_v2 - _g);
		}
		HX_STACK_LINE(368)
		r = (1.0 - _g1);
	}
	else{
		HX_STACK_LINE(368)
		Float _g2 = ::Math_obj::ffloor(n);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(368)
		r = (n - _g2);
	}
	HX_STACK_LINE(369)
	return (p_v0 + (((p_v1 - p_v0)) * r));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Mathf_obj,Loop,return )

Float Mathf_obj::Linear2Gamma( Float p_v){
	HX_STACK_FRAME("haxor.math.Mathf","Linear2Gamma",0x512ce304,"haxor.math.Mathf.Linear2Gamma","haxor/math/Mathf.hx",377,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_LINE(377)
	return ::Math_obj::pow(p_v,2.2);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Mathf_obj,Linear2Gamma,return )

Float Mathf_obj::Oscilate( Float p_v,Float p_v0,Float p_v1){
	HX_STACK_FRAME("haxor.math.Mathf","Oscilate",0x9adde9ba,"haxor.math.Mathf.Oscilate","haxor/math/Mathf.hx",386,0x3182889a)
	HX_STACK_ARG(p_v,"p_v")
	HX_STACK_ARG(p_v0,"p_v0")
	HX_STACK_ARG(p_v1,"p_v1")
	struct _Function_1_1{
		inline static Float Block( Float &p_v){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/math/Mathf.hx",387,0x3182889a)
			{
				HX_STACK_LINE(387)
				Float p_a = ::haxor::math::Mathf_obj::Loop((p_v - 1.0),-1.0,1.0);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(387)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	HX_STACK_LINE(387)
	Float _g = -(_Function_1_1::Block(p_v));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(387)
	Float w = (_g + 1.0);		HX_STACK_VAR(w,"w");
	HX_STACK_LINE(388)
	return (w + (((p_v0 - w)) * p_v1));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Mathf_obj,Oscilate,return )

Float Mathf_obj::WrapAngle( Float p_angle){
	HX_STACK_FRAME("haxor.math.Mathf","WrapAngle",0x054f059f,"haxor.math.Mathf.WrapAngle","haxor/math/Mathf.hx",397,0x3182889a)
	HX_STACK_ARG(p_angle,"p_angle")
	HX_STACK_LINE(398)
	if (((p_angle < -360.0))){
		HX_STACK_LINE(398)
		return ((int)360 + p_angle);
	}
	HX_STACK_LINE(399)
	if (((p_angle > 360.0))){
		HX_STACK_LINE(399)
		return (p_angle - (int)360);
	}
	HX_STACK_LINE(400)
	return p_angle;
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
		if (HX_FIELD_EQ(inName,"Asin") ) { return Asin_dyn(); }
		if (HX_FIELD_EQ(inName,"Acos") ) { return Acos_dyn(); }
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
		if (HX_FIELD_EQ(inName,"MinRange") ) { return MinRange_dyn(); }
		if (HX_FIELD_EQ(inName,"MaxRange") ) { return MaxRange_dyn(); }
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
	HX_CSTRING("MinRange"),
	HX_CSTRING("Max"),
	HX_CSTRING("MaxRange"),
	HX_CSTRING("MinInt"),
	HX_CSTRING("MaxInt"),
	HX_CSTRING("Sin"),
	HX_CSTRING("Cos"),
	HX_CSTRING("Asin"),
	HX_CSTRING("Acos"),
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
	Epsilon= 0.0001;
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
