#ifndef INCLUDED_haxor_math_AABB2
#define INCLUDED_haxor_math_AABB2

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,math,AABB2)
HX_DECLARE_CLASS2(haxor,math,Vector2)
namespace haxor{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  AABB2_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AABB2_obj OBJ_;
		AABB2_obj();
		Void __construct(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AABB2_obj > __new(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AABB2_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AABB2"); }

		::haxor::math::AABB2 clone;
		virtual ::haxor::math::AABB2 get_clone( );
		Dynamic get_clone_dyn();

		virtual ::haxor::math::Vector2 get_min( );
		Dynamic get_min_dyn();

		virtual ::haxor::math::Vector2 set_min( ::haxor::math::Vector2 v);
		Dynamic set_min_dyn();

		virtual ::haxor::math::Vector2 get_max( );
		Dynamic get_max_dyn();

		virtual ::haxor::math::Vector2 set_max( ::haxor::math::Vector2 v);
		Dynamic set_max_dyn();

		virtual Float get_xMin( );
		Dynamic get_xMin_dyn();

		virtual Float set_xMin( Float v);
		Dynamic set_xMin_dyn();

		Float m_xMin;
		virtual Float get_yMin( );
		Dynamic get_yMin_dyn();

		virtual Float set_yMin( Float v);
		Dynamic set_yMin_dyn();

		Float m_yMin;
		virtual Float get_xMax( );
		Dynamic get_xMax_dyn();

		virtual Float set_xMax( Float v);
		Dynamic set_xMax_dyn();

		Float m_xMax;
		virtual Float get_yMax( );
		Dynamic get_yMax_dyn();

		virtual Float set_yMax( Float v);
		Dynamic set_yMax_dyn();

		Float m_yMax;
		virtual ::haxor::math::Vector2 get_center( );
		Dynamic get_center_dyn();

		virtual ::haxor::math::Vector2 set_center( ::haxor::math::Vector2 v);
		Dynamic set_center_dyn();

		virtual Float get_x( );
		Dynamic get_x_dyn();

		virtual Float set_x( Float v);
		Dynamic set_x_dyn();

		virtual Float get_y( );
		Dynamic get_y_dyn();

		virtual Float set_y( Float v);
		Dynamic set_y_dyn();

		virtual Float get_width( );
		Dynamic get_width_dyn();

		virtual Float set_width( Float v);
		Dynamic set_width_dyn();

		virtual Float get_height( );
		Dynamic get_height_dyn();

		virtual Float set_height( Float v);
		Dynamic set_height_dyn();

		virtual ::haxor::math::Vector2 get_size( );
		Dynamic get_size_dyn();

		virtual ::haxor::math::Vector2 set_size( ::haxor::math::Vector2 v);
		Dynamic set_size_dyn();

		virtual Void Validate( );
		Dynamic Validate_dyn();

		virtual ::haxor::math::AABB2 Add( ::haxor::math::AABB2 p_v);
		Dynamic Add_dyn();

		virtual ::haxor::math::AABB2 Set( Float p_xmin,Float p_xmax,Float p_ymin,Float p_ymax);
		Dynamic Set_dyn();

		virtual ::haxor::math::AABB2 SetXYWH( Float p_x,Float p_y,Float p_width,Float p_height);
		Dynamic SetXYWH_dyn();

		virtual ::haxor::math::AABB2 SetAABB2( ::haxor::math::AABB2 p_v);
		Dynamic SetAABB2_dyn();

		virtual Void Encapsulate( ::haxor::math::Vector2 p_point);
		Dynamic Encapsulate_dyn();

		virtual ::haxor::math::AABB2 Encapsulate3( hx::Null< Float >  p_x,hx::Null< Float >  p_y);
		Dynamic Encapsulate3_dyn();

		virtual ::String ToString( hx::Null< int >  p_places);
		Dynamic ToString_dyn();

		static ::haxor::math::AABB2 temp;
		static ::haxor::math::AABB2 get_temp( );
		static Dynamic get_temp_dyn();

		static ::haxor::math::AABB2 FromMinMax( Float p_xmin,Float p_xmax,Float p_ymin,Float p_ymax);
		static Dynamic FromMinMax_dyn();

		static ::haxor::math::AABB2 empty;
		static ::haxor::math::AABB2 get_empty( );
		static Dynamic get_empty_dyn();

};

} // end namespace haxor
} // end namespace math

#endif /* INCLUDED_haxor_math_AABB2 */ 
