#ifndef INCLUDED_haxor_math_Vector3
#define INCLUDED_haxor_math_Vector3

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,math,Color)
HX_DECLARE_CLASS2(haxor,math,Vector2)
HX_DECLARE_CLASS2(haxor,math,Vector3)
HX_DECLARE_CLASS2(haxor,math,Vector4)
namespace haxor{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Vector3_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Vector3_obj OBJ_;
		Vector3_obj();
		Void __construct(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Vector3_obj > __new(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Vector3_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Vector3"); }

		::haxor::math::Vector3 clone;
		virtual ::haxor::math::Vector3 get_clone( );
		Dynamic get_clone_dyn();

		::haxor::math::Color color;
		virtual ::haxor::math::Color get_color( );
		Dynamic get_color_dyn();

		::haxor::math::Vector3 xzy;
		virtual ::haxor::math::Vector3 get_xzy( );
		Dynamic get_xzy_dyn();

		::haxor::math::Vector3 yxz;
		virtual ::haxor::math::Vector3 get_yxz( );
		Dynamic get_yxz_dyn();

		::haxor::math::Vector3 yzx;
		virtual ::haxor::math::Vector3 get_yzx( );
		Dynamic get_yzx_dyn();

		::haxor::math::Vector3 zxy;
		virtual ::haxor::math::Vector3 get_zxy( );
		Dynamic get_zxy_dyn();

		::haxor::math::Vector3 zyx;
		virtual ::haxor::math::Vector3 get_zyx( );
		Dynamic get_zyx_dyn();

		::haxor::math::Vector2 xy;
		virtual ::haxor::math::Vector2 get_xy( );
		Dynamic get_xy_dyn();

		::haxor::math::Vector2 xz;
		virtual ::haxor::math::Vector2 get_xz( );
		Dynamic get_xz_dyn();

		::haxor::math::Vector2 yx;
		virtual ::haxor::math::Vector2 get_yx( );
		Dynamic get_yx_dyn();

		::haxor::math::Vector2 yz;
		virtual ::haxor::math::Vector2 get_yz( );
		Dynamic get_yz_dyn();

		::haxor::math::Vector2 zx;
		virtual ::haxor::math::Vector2 get_zx( );
		Dynamic get_zx_dyn();

		::haxor::math::Vector2 zy;
		virtual ::haxor::math::Vector2 get_zy( );
		Dynamic get_zy_dyn();

		Float length;
		virtual Float get_length( );
		Dynamic get_length_dyn();

		Float lengthSqr;
		virtual Float get_lengthSqr( );
		Dynamic get_lengthSqr_dyn();

		::haxor::math::Vector3 normalized;
		virtual ::haxor::math::Vector3 get_normalized( );
		Dynamic get_normalized_dyn();

		::haxor::math::Vector3 inverse;
		virtual ::haxor::math::Vector3 get_inverse( );
		Dynamic get_inverse_dyn();

		Float x;
		Float y;
		Float z;
		virtual ::haxor::math::Vector3 Set( hx::Null< Float >  p_x,hx::Null< Float >  p_y,hx::Null< Float >  p_z);
		Dynamic Set_dyn();

		virtual ::haxor::math::Vector3 Set2( ::haxor::math::Vector2 v);
		Dynamic Set2_dyn();

		virtual ::haxor::math::Vector3 Set3( ::haxor::math::Vector3 v);
		Dynamic Set3_dyn();

		virtual ::haxor::math::Vector3 Set4( ::haxor::math::Vector4 v);
		Dynamic Set4_dyn();

		virtual ::haxor::math::Vector3 SetColor( ::haxor::math::Color v);
		Dynamic SetColor_dyn();

		virtual Float Get( int p);
		Dynamic Get_dyn();

		virtual ::haxor::math::Vector3 Add( ::haxor::math::Vector3 p_v);
		Dynamic Add_dyn();

		virtual ::haxor::math::Vector3 Add3( Float p_x,Float p_y,Float p_z);
		Dynamic Add3_dyn();

		virtual ::haxor::math::Vector3 Sub( ::haxor::math::Vector3 p_v);
		Dynamic Sub_dyn();

		virtual ::haxor::math::Vector3 Multiply( ::haxor::math::Vector3 p_v);
		Dynamic Multiply_dyn();

		virtual bool Step( ::haxor::math::Vector3 p_to,Float p_step);
		Dynamic Step_dyn();

		virtual ::haxor::math::Vector3 Reflect( ::haxor::math::Vector3 p_normal);
		Dynamic Reflect_dyn();

		virtual ::haxor::math::Vector3 Invert( );
		Dynamic Invert_dyn();

		virtual ::haxor::math::Vector3 Scale( Float p_s);
		Dynamic Scale_dyn();

		virtual ::haxor::math::Vector3 Normalize( );
		Dynamic Normalize_dyn();

		virtual Array< Float > ToArray( );
		Dynamic ToArray_dyn();

		virtual ::String ToString( hx::Null< int >  p_places);
		Dynamic ToString_dyn();

		static ::haxor::math::Vector3 temp;
		static ::haxor::math::Vector3 get_temp( );
		static Dynamic get_temp_dyn();

		static ::haxor::math::Vector3 zero;
		static ::haxor::math::Vector3 get_zero( );
		static Dynamic get_zero_dyn();

		static ::haxor::math::Vector3 one;
		static ::haxor::math::Vector3 get_one( );
		static Dynamic get_one_dyn();

		static ::haxor::math::Vector3 right;
		static ::haxor::math::Vector3 get_right( );
		static Dynamic get_right_dyn();

		static ::haxor::math::Vector3 up;
		static ::haxor::math::Vector3 get_up( );
		static Dynamic get_up_dyn();

		static ::haxor::math::Vector3 forward;
		static ::haxor::math::Vector3 get_forward( );
		static Dynamic get_forward_dyn();

		static Float Dot( ::haxor::math::Vector3 p_a,::haxor::math::Vector3 p_b);
		static Dynamic Dot_dyn();

		static Float Distance( ::haxor::math::Vector3 p_a,::haxor::math::Vector3 p_b);
		static Dynamic Distance_dyn();

		static ::haxor::math::Vector3 Cross( ::haxor::math::Vector3 p_a,::haxor::math::Vector3 p_b,::haxor::math::Vector3 p_result);
		static Dynamic Cross_dyn();

		static ::haxor::math::Vector3 Lerp( ::haxor::math::Vector3 p_a,::haxor::math::Vector3 p_b,Float p_r,::haxor::math::Vector3 p_result);
		static Dynamic Lerp_dyn();

		static ::haxor::math::Vector3 Min( ::haxor::math::Vector3 p_a,::haxor::math::Vector3 p_b,::haxor::math::Vector3 p_result);
		static Dynamic Min_dyn();

		static ::haxor::math::Vector3 Max( ::haxor::math::Vector3 p_a,::haxor::math::Vector3 p_b,::haxor::math::Vector3 p_result);
		static Dynamic Max_dyn();

		static ::haxor::math::Vector3 Parse( ::String p_data,::String p_delimiter);
		static Dynamic Parse_dyn();

};

} // end namespace haxor
} // end namespace math

#endif /* INCLUDED_haxor_math_Vector3 */ 
