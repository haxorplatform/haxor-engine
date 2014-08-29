#ifndef INCLUDED_haxor_math_Vector4
#define INCLUDED_haxor_math_Vector4

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,math,Color)
HX_DECLARE_CLASS2(haxor,math,Vector2)
HX_DECLARE_CLASS2(haxor,math,Vector3)
HX_DECLARE_CLASS2(haxor,math,Vector4)
namespace haxor{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Vector4_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Vector4_obj OBJ_;
		Vector4_obj();
		Void __construct(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z,hx::Null< Float >  __o_p_w);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Vector4_obj > __new(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z,hx::Null< Float >  __o_p_w);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Vector4_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Vector4"); }

		::haxor::math::Vector4 clone;
		virtual ::haxor::math::Vector4 get_clone( );
		Dynamic get_clone_dyn();

		::haxor::math::Color rgba;
		virtual ::haxor::math::Color get_rgba( );
		Dynamic get_rgba_dyn();

		::haxor::math::Color rgb;
		virtual ::haxor::math::Color get_rgb( );
		Dynamic get_rgb_dyn();

		::haxor::math::Vector3 xyz;
		virtual ::haxor::math::Vector3 get_xyz( );
		Dynamic get_xyz_dyn();

		::haxor::math::Vector2 xy;
		virtual ::haxor::math::Vector2 get_xy( );
		Dynamic get_xy_dyn();

		Float length;
		virtual Float get_length( );
		Dynamic get_length_dyn();

		Float lengthSqr;
		virtual Float get_lengthSqr( );
		Dynamic get_lengthSqr_dyn();

		::haxor::math::Vector4 normalized;
		virtual ::haxor::math::Vector4 get_normalized( );
		Dynamic get_normalized_dyn();

		Float x;
		Float y;
		Float z;
		Float w;
		virtual Float Get( int p);
		Dynamic Get_dyn();

		virtual ::haxor::math::Vector4 Set( hx::Null< Float >  p_x,hx::Null< Float >  p_y,hx::Null< Float >  p_z,hx::Null< Float >  p_w);
		Dynamic Set_dyn();

		virtual ::haxor::math::Vector4 Set2( ::haxor::math::Vector2 v);
		Dynamic Set2_dyn();

		virtual ::haxor::math::Vector4 Set3( ::haxor::math::Vector3 v);
		Dynamic Set3_dyn();

		virtual ::haxor::math::Vector4 SetColor( ::haxor::math::Color v);
		Dynamic SetColor_dyn();

		virtual ::haxor::math::Vector4 Add( ::haxor::math::Vector4 p_v);
		Dynamic Add_dyn();

		virtual ::haxor::math::Vector4 Sub( ::haxor::math::Vector4 p_v);
		Dynamic Sub_dyn();

		virtual ::haxor::math::Vector4 Multiply( ::haxor::math::Vector4 p_v);
		Dynamic Multiply_dyn();

		virtual ::haxor::math::Vector4 Scale( Float p_s);
		Dynamic Scale_dyn();

		virtual ::haxor::math::Vector4 Normalize( );
		Dynamic Normalize_dyn();

		virtual bool IsCulled( );
		Dynamic IsCulled_dyn();

		virtual Array< Float > ToArray( );
		Dynamic ToArray_dyn();

		virtual ::String ToString( hx::Null< int >  p_places);
		Dynamic ToString_dyn();

		static ::haxor::math::Vector4 temp;
		static ::haxor::math::Vector4 get_temp( );
		static Dynamic get_temp_dyn();

		static ::haxor::math::Vector4 zero;
		static ::haxor::math::Vector4 get_zero( );
		static Dynamic get_zero_dyn();

		static ::haxor::math::Vector4 one;
		static ::haxor::math::Vector4 get_one( );
		static Dynamic get_one_dyn();

		static ::haxor::math::Vector4 W;
		static ::haxor::math::Vector4 get_W( );
		static Dynamic get_W_dyn();

		static ::haxor::math::Vector4 Lerp( ::haxor::math::Vector4 p_a,::haxor::math::Vector4 p_b,Float p_r);
		static Dynamic Lerp_dyn();

		static ::haxor::math::Vector4 Parse( ::String p_data,::String p_delimiter);
		static Dynamic Parse_dyn();

};

} // end namespace haxor
} // end namespace math

#endif /* INCLUDED_haxor_math_Vector4 */ 
