#ifndef INCLUDED_haxor_math_Color
#define INCLUDED_haxor_math_Color

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,math,Color)
HX_DECLARE_CLASS2(haxor,math,Vector3)
HX_DECLARE_CLASS2(haxor,math,Vector4)
namespace haxor{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Color_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Color_obj OBJ_;
		Color_obj();
		Void __construct(hx::Null< Float >  __o_p_r,hx::Null< Float >  __o_p_g,hx::Null< Float >  __o_p_b,hx::Null< Float >  __o_p_a);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Color_obj > __new(hx::Null< Float >  __o_p_r,hx::Null< Float >  __o_p_g,hx::Null< Float >  __o_p_b,hx::Null< Float >  __o_p_a);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Color_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Color"); }

		::haxor::math::Color clone;
		virtual ::haxor::math::Color get_clone( );
		Dynamic get_clone_dyn();

		::haxor::math::Vector3 xyz;
		virtual ::haxor::math::Vector3 get_xyz( );
		Dynamic get_xyz_dyn();

		::haxor::math::Vector4 xyzw;
		virtual ::haxor::math::Vector4 get_xyzw( );
		Dynamic get_xyzw_dyn();

		virtual int get_argb( );
		Dynamic get_argb_dyn();

		virtual int set_argb( int v);
		Dynamic set_argb_dyn();

		virtual ::String get_css( );
		Dynamic get_css_dyn();

		virtual int get_rgba( );
		Dynamic get_rgba_dyn();

		virtual int set_rgba( int v);
		Dynamic set_rgba_dyn();

		virtual int get_rgb( );
		Dynamic get_rgb_dyn();

		virtual int set_rgb( int v);
		Dynamic set_rgb_dyn();

		Float luminance;
		virtual Float get_luminance( );
		Dynamic get_luminance_dyn();

		::haxor::math::Color negative;
		virtual ::haxor::math::Color get_negative( );
		Dynamic get_negative_dyn();

		Float r;
		Float g;
		Float b;
		Float a;
		virtual ::haxor::math::Color Set( hx::Null< Float >  p_r,hx::Null< Float >  p_g,hx::Null< Float >  p_b,hx::Null< Float >  p_a);
		Dynamic Set_dyn();

		virtual ::haxor::math::Color Set3( ::haxor::math::Vector3 v);
		Dynamic Set3_dyn();

		virtual ::haxor::math::Color Set4( ::haxor::math::Vector4 v);
		Dynamic Set4_dyn();

		virtual ::haxor::math::Color SetColor( ::haxor::math::Color p_color);
		Dynamic SetColor_dyn();

		virtual Float Get( int p);
		Dynamic Get_dyn();

		virtual ::haxor::math::Color Add( ::haxor::math::Color p_v);
		Dynamic Add_dyn();

		virtual ::haxor::math::Color Sub( ::haxor::math::Color p_v);
		Dynamic Sub_dyn();

		virtual ::haxor::math::Color Multiply( ::haxor::math::Color p_v);
		Dynamic Multiply_dyn();

		virtual ::haxor::math::Color MultiplyRGB( ::haxor::math::Color p_v);
		Dynamic MultiplyRGB_dyn();

		virtual ::haxor::math::Color Scale( Float p_s);
		Dynamic Scale_dyn();

		virtual ::haxor::math::Color ScaleRGB( Float p_s);
		Dynamic ScaleRGB_dyn();

		virtual Array< Float > ToArray( );
		Dynamic ToArray_dyn();

		virtual ::String ToString( hx::Null< int >  p_places);
		Dynamic ToString_dyn();

		static ::haxor::math::Color temp;
		static ::haxor::math::Color get_temp( );
		static Dynamic get_temp_dyn();

		static ::haxor::math::Color red;
		static ::haxor::math::Color get_red( );
		static Dynamic get_red_dyn();

		static ::haxor::math::Color yellow;
		static ::haxor::math::Color get_yellow( );
		static Dynamic get_yellow_dyn();

		static ::haxor::math::Color green;
		static ::haxor::math::Color get_green( );
		static Dynamic get_green_dyn();

		static ::haxor::math::Color cyan;
		static ::haxor::math::Color get_cyan( );
		static Dynamic get_cyan_dyn();

		static ::haxor::math::Color blue;
		static ::haxor::math::Color get_blue( );
		static Dynamic get_blue_dyn();

		static ::haxor::math::Color magenta;
		static ::haxor::math::Color get_magenta( );
		static Dynamic get_magenta_dyn();

		static ::haxor::math::Color black;
		static ::haxor::math::Color get_black( );
		static Dynamic get_black_dyn();

		static ::haxor::math::Color white;
		static ::haxor::math::Color get_white( );
		static Dynamic get_white_dyn();

		static ::haxor::math::Color empty;
		static ::haxor::math::Color get_empty( );
		static Dynamic get_empty_dyn();

		static ::haxor::math::Color gray10;
		static ::haxor::math::Color get_gray10( );
		static Dynamic get_gray10_dyn();

		static ::haxor::math::Color gray25;
		static ::haxor::math::Color get_gray25( );
		static Dynamic get_gray25_dyn();

		static ::haxor::math::Color gray50;
		static ::haxor::math::Color get_gray50( );
		static Dynamic get_gray50_dyn();

		static ::haxor::math::Color gray75;
		static ::haxor::math::Color get_gray75( );
		static Dynamic get_gray75_dyn();

		static ::haxor::math::Color gray90;
		static ::haxor::math::Color get_gray90( );
		static Dynamic get_gray90_dyn();

		static ::haxor::math::Color FromHex( ::String p_hex);
		static Dynamic FromHex_dyn();

		static ::haxor::math::Color FromBytes( hx::Null< Float >  p_r,hx::Null< Float >  p_g,hx::Null< Float >  p_b,hx::Null< Float >  p_a);
		static Dynamic FromBytes_dyn();

		static ::haxor::math::Color Lerp( ::haxor::math::Color a,::haxor::math::Color b,Float r);
		static Dynamic Lerp_dyn();

		static ::haxor::math::Color Sample( Array< ::Dynamic > g,Float r);
		static Dynamic Sample_dyn();

};

} // end namespace haxor
} // end namespace math

#endif /* INCLUDED_haxor_math_Color */ 
