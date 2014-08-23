#ifndef INCLUDED_haxor_math_Vector2
#define INCLUDED_haxor_math_Vector2

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,math,Vector2)
HX_DECLARE_CLASS2(haxor,math,Vector3)
HX_DECLARE_CLASS2(haxor,math,Vector4)
namespace haxor{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Vector2_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Vector2_obj OBJ_;
		Vector2_obj();
		Void __construct(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Vector2_obj > __new(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Vector2_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Vector2"); }

		::haxor::math::Vector2 clone;
		virtual ::haxor::math::Vector2 get_clone( );
		Dynamic get_clone_dyn();

		::haxor::math::Vector2 xy;
		virtual ::haxor::math::Vector2 get_xy( );
		Dynamic get_xy_dyn();

		::haxor::math::Vector2 yx;
		virtual ::haxor::math::Vector2 get_yx( );
		Dynamic get_yx_dyn();

		Float length;
		virtual Float get_length( );
		Dynamic get_length_dyn();

		Float lengthSqr;
		virtual Float get_lengthSqr( );
		Dynamic get_lengthSqr_dyn();

		::haxor::math::Vector2 normalized;
		virtual ::haxor::math::Vector2 get_normalized( );
		Dynamic get_normalized_dyn();

		::haxor::math::Vector2 inverse;
		virtual ::haxor::math::Vector2 get_inverse( );
		Dynamic get_inverse_dyn();

		Float x;
		Float y;
		virtual ::haxor::math::Vector2 Set( hx::Null< Float >  p_x,hx::Null< Float >  p_y);
		Dynamic Set_dyn();

		virtual ::haxor::math::Vector2 Set2( ::haxor::math::Vector2 v);
		Dynamic Set2_dyn();

		virtual ::haxor::math::Vector2 Set3( ::haxor::math::Vector3 v);
		Dynamic Set3_dyn();

		virtual ::haxor::math::Vector2 Set4( ::haxor::math::Vector4 v);
		Dynamic Set4_dyn();

		virtual Float Get( int p);
		Dynamic Get_dyn();

		virtual ::haxor::math::Vector2 Add( ::haxor::math::Vector2 p_v);
		Dynamic Add_dyn();

		virtual ::haxor::math::Vector2 Sub( ::haxor::math::Vector2 p_v);
		Dynamic Sub_dyn();

		virtual ::haxor::math::Vector2 Multiply( ::haxor::math::Vector2 p_v);
		Dynamic Multiply_dyn();

		virtual ::haxor::math::Vector2 Scale( Float p_s);
		Dynamic Scale_dyn();

		virtual bool Step( ::haxor::math::Vector2 p_to,Float p_step);
		Dynamic Step_dyn();

		virtual ::haxor::math::Vector2 Reflect( ::haxor::math::Vector2 p_normal);
		Dynamic Reflect_dyn();

		virtual ::haxor::math::Vector2 Invert( );
		Dynamic Invert_dyn();

		virtual ::haxor::math::Vector2 Normalize( );
		Dynamic Normalize_dyn();

		virtual Array< Float > ToArray( );
		Dynamic ToArray_dyn();

		virtual ::String ToString( hx::Null< int >  p_places);
		Dynamic ToString_dyn();

		static ::haxor::math::Vector2 temp;
		static ::haxor::math::Vector2 get_temp( );
		static Dynamic get_temp_dyn();

		static ::haxor::math::Vector2 zero;
		static ::haxor::math::Vector2 get_zero( );
		static Dynamic get_zero_dyn();

		static ::haxor::math::Vector2 one;
		static ::haxor::math::Vector2 get_one( );
		static Dynamic get_one_dyn();

		static ::haxor::math::Vector2 right;
		static ::haxor::math::Vector2 get_right( );
		static Dynamic get_right_dyn();

		static ::haxor::math::Vector2 up;
		static ::haxor::math::Vector2 get_up( );
		static Dynamic get_up_dyn();

		static Float Dot( ::haxor::math::Vector2 p_a,::haxor::math::Vector2 p_b);
		static Dynamic Dot_dyn();

		static ::haxor::math::Vector2 Lerp( ::haxor::math::Vector2 p_a,::haxor::math::Vector2 p_b,Float p_r);
		static Dynamic Lerp_dyn();

};

} // end namespace haxor
} // end namespace math

#endif /* INCLUDED_haxor_math_Vector2 */ 
