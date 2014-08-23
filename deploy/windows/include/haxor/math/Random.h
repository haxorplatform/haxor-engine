#ifndef INCLUDED_haxor_math_Random
#define INCLUDED_haxor_math_Random

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,math,Quaternion)
HX_DECLARE_CLASS2(haxor,math,Random)
HX_DECLARE_CLASS2(haxor,math,Vector2)
HX_DECLARE_CLASS2(haxor,math,Vector3)
namespace haxor{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Random_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Random_obj OBJ_;
		Random_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Random_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Random_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Random"); }

		static Float value;
		static Float get_value( );
		static Dynamic get_value_dyn();

		static Float interval;
		static Float get_interval( );
		static Dynamic get_interval_dyn();

		static ::haxor::math::Quaternion rotation;
		static ::haxor::math::Quaternion get_rotation( );
		static Dynamic get_rotation_dyn();

		static ::haxor::math::Vector3 box;
		static ::haxor::math::Vector3 get_box( );
		static Dynamic get_box_dyn();

		static ::haxor::math::Vector3 onBox;
		static ::haxor::math::Vector3 get_onBox( );
		static Dynamic get_onBox_dyn();

		static ::haxor::math::Vector2 square;
		static ::haxor::math::Vector2 get_square( );
		static Dynamic get_square_dyn();

		static ::haxor::math::Vector2 onSquare;
		static ::haxor::math::Vector2 get_onSquare( );
		static Dynamic get_onSquare_dyn();

		static ::haxor::math::Vector3 sphere;
		static ::haxor::math::Vector3 get_sphere( );
		static Dynamic get_sphere_dyn();

		static ::haxor::math::Vector3 onSphere;
		static ::haxor::math::Vector3 get_onSphere( );
		static Dynamic get_onSphere_dyn();

		static ::haxor::math::Vector2 circle;
		static ::haxor::math::Vector2 get_circle( );
		static Dynamic get_circle_dyn();

		static ::haxor::math::Vector2 onCircle;
		static ::haxor::math::Vector2 get_onCircle( );
		static Dynamic get_onCircle_dyn();

		static int Length( int v);
		static Dynamic Length_dyn();

		static Float Range( Float p_min,Float p_max);
		static Dynamic Range_dyn();

		static Float RangeInt( int p_min,int p_max);
		static Dynamic RangeInt_dyn();

		static Dynamic Item( Dynamic p_list);
		static Dynamic Item_dyn();

		static Void Shuffle( Dynamic p_list);
		static Dynamic Shuffle_dyn();

};

} // end namespace haxor
} // end namespace math

#endif /* INCLUDED_haxor_math_Random */ 
