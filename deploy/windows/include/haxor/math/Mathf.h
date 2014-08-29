#ifndef INCLUDED_haxor_math_Mathf
#define INCLUDED_haxor_math_Mathf

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,math,Mathf)
namespace haxor{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Mathf_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Mathf_obj OBJ_;
		Mathf_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Mathf_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Mathf_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Mathf"); }

		static Float Epsilon;
		static Float NaN;
		static Float Infinity;
		static Float NegativeInfinity;
		static Float E;
		static Float PI;
		static Float HalfPI;
		static Float PI2;
		static Float PI4;
		static Float InvPI;
		static Float Rad2Deg;
		static Float Deg2Rad;
		static Float Px2Em;
		static Float Em2Px;
		static Float Byte2Float;
		static Float Short2Float;
		static Float Long2Float;
		static Float Float2Byte;
		static Float Float2Short;
		static Float Float2Long;
		static bool IsPOT( int p_v);
		static Dynamic IsPOT_dyn();

		static int NextPOT( int p_v);
		static Dynamic NextPOT_dyn();

		static Float Sign( Float p_a);
		static Dynamic Sign_dyn();

		static int SignInt( int p_a);
		static Dynamic SignInt_dyn();

		static Float Abs( Float p_a);
		static Dynamic Abs_dyn();

		static int AbsInt( int p_a);
		static Dynamic AbsInt_dyn();

		static Float Clamp( Float p_v,Float p_min,Float p_max);
		static Dynamic Clamp_dyn();

		static Float Clamp01( Float p_v);
		static Dynamic Clamp01_dyn();

		static int ClampInt( int p_v,int p_min,int p_max);
		static Dynamic ClampInt_dyn();

		static Float Min( Float a,Float b);
		static Dynamic Min_dyn();

		static Float MinRange( Array< Float > v);
		static Dynamic MinRange_dyn();

		static Float Max( Float a,Float b);
		static Dynamic Max_dyn();

		static Float MaxRange( Array< Float > v);
		static Dynamic MaxRange_dyn();

		static int MinInt( int a,int b);
		static Dynamic MinInt_dyn();

		static int MaxInt( int a,int b);
		static Dynamic MaxInt_dyn();

		static Float Sin( Float v);
		static Dynamic Sin_dyn();

		static Float Cos( Float v);
		static Dynamic Cos_dyn();

		static Float ASin( Float v);
		static Dynamic ASin_dyn();

		static Float ACos( Float v);
		static Dynamic ACos_dyn();

		static Float Tan( Float v);
		static Dynamic Tan_dyn();

		static Float ATan( Float v);
		static Dynamic ATan_dyn();

		static Float ATan2( Float y,Float x);
		static Dynamic ATan2_dyn();

		static Float Sqrt( Float v);
		static Dynamic Sqrt_dyn();

		static Float Pow( Float b,Float exp);
		static Dynamic Pow_dyn();

		static Float Floor( Float p_v);
		static Dynamic Floor_dyn();

		static Float Ceil( Float p_v);
		static Dynamic Ceil_dyn();

		static Float Round( Float p_v);
		static Dynamic Round_dyn();

		static Float RoundPlaces( Float p_v,hx::Null< int >  p_decimal_places);
		static Dynamic RoundPlaces_dyn();

		static Float Lerp( Float p_a,Float p_b,Float p_ratio);
		static Dynamic Lerp_dyn();

		static int LerpInt( int p_a,int p_b,Float p_ratio);
		static Dynamic LerpInt_dyn();

		static Float Frac( Float p_v);
		static Dynamic Frac_dyn();

		static Float Loop( Float p_v,Float p_v0,Float p_v1);
		static Dynamic Loop_dyn();

		static Float Linear2Gamma( Float p_v);
		static Dynamic Linear2Gamma_dyn();

		static Float Oscilate( Float p_v,Float p_v0,Float p_v1);
		static Dynamic Oscilate_dyn();

		static Float WrapAngle( Float p_angle);
		static Dynamic WrapAngle_dyn();

};

} // end namespace haxor
} // end namespace math

#endif /* INCLUDED_haxor_math_Mathf */ 
