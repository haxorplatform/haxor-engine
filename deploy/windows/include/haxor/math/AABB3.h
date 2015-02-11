#ifndef INCLUDED_haxor_math_AABB3
#define INCLUDED_haxor_math_AABB3

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,math,AABB3)
HX_DECLARE_CLASS2(haxor,math,Vector3)
namespace haxor{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  AABB3_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AABB3_obj OBJ_;
		AABB3_obj();
		Void __construct(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z,hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height,hx::Null< Float >  __o_p_depth);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AABB3_obj > __new(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z,hx::Null< Float >  __o_p_width,hx::Null< Float >  __o_p_height,hx::Null< Float >  __o_p_depth);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AABB3_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AABB3"); }

		::haxor::math::AABB3 clone;
		virtual ::haxor::math::AABB3 get_clone( );
		Dynamic get_clone_dyn();

		virtual ::haxor::math::Vector3 get_min( );
		Dynamic get_min_dyn();

		virtual ::haxor::math::Vector3 set_min( ::haxor::math::Vector3 v);
		Dynamic set_min_dyn();

		virtual ::haxor::math::Vector3 get_max( );
		Dynamic get_max_dyn();

		virtual ::haxor::math::Vector3 set_max( ::haxor::math::Vector3 v);
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
		virtual Float get_zMin( );
		Dynamic get_zMin_dyn();

		virtual Float set_zMin( Float v);
		Dynamic set_zMin_dyn();

		Float m_zMin;
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
		virtual Float get_zMax( );
		Dynamic get_zMax_dyn();

		virtual Float set_zMax( Float v);
		Dynamic set_zMax_dyn();

		Float m_zMax;
		virtual ::haxor::math::Vector3 get_center( );
		Dynamic get_center_dyn();

		virtual ::haxor::math::Vector3 set_center( ::haxor::math::Vector3 v);
		Dynamic set_center_dyn();

		virtual Float get_x( );
		Dynamic get_x_dyn();

		virtual Float set_x( Float v);
		Dynamic set_x_dyn();

		virtual Float get_y( );
		Dynamic get_y_dyn();

		virtual Float set_y( Float v);
		Dynamic set_y_dyn();

		virtual Float get_z( );
		Dynamic get_z_dyn();

		virtual Float set_z( Float v);
		Dynamic set_z_dyn();

		virtual Float get_width( );
		Dynamic get_width_dyn();

		virtual Float set_width( Float v);
		Dynamic set_width_dyn();

		virtual Float get_height( );
		Dynamic get_height_dyn();

		virtual Float set_height( Float v);
		Dynamic set_height_dyn();

		virtual Float get_depth( );
		Dynamic get_depth_dyn();

		virtual Float set_depth( Float v);
		Dynamic set_depth_dyn();

		virtual ::haxor::math::Vector3 get_size( );
		Dynamic get_size_dyn();

		virtual ::haxor::math::Vector3 set_size( ::haxor::math::Vector3 v);
		Dynamic set_size_dyn();

		virtual Void Validate( );
		Dynamic Validate_dyn();

		virtual ::haxor::math::AABB3 Add( ::haxor::math::AABB3 p_v);
		Dynamic Add_dyn();

		virtual ::haxor::math::AABB3 Set( hx::Null< Float >  p_xmin,hx::Null< Float >  p_xmax,hx::Null< Float >  p_ymin,hx::Null< Float >  p_ymax,hx::Null< Float >  p_zmin,hx::Null< Float >  p_zmax);
		Dynamic Set_dyn();

		virtual ::haxor::math::AABB3 Set3( ::haxor::math::Vector3 p_min,::haxor::math::Vector3 p_max);
		Dynamic Set3_dyn();

		virtual ::haxor::math::AABB3 SetAABB3( ::haxor::math::AABB3 p_v);
		Dynamic SetAABB3_dyn();

		virtual ::haxor::math::AABB3 SetXYZWHD( hx::Null< Float >  p_x,hx::Null< Float >  p_y,hx::Null< Float >  p_z,hx::Null< Float >  p_width,hx::Null< Float >  p_height,hx::Null< Float >  p_depth);
		Dynamic SetXYZWHD_dyn();

		virtual ::haxor::math::AABB3 Encapsulate( ::haxor::math::Vector3 p_point);
		Dynamic Encapsulate_dyn();

		virtual ::haxor::math::AABB3 Encapsulate3( hx::Null< Float >  p_x,hx::Null< Float >  p_y,hx::Null< Float >  p_z);
		Dynamic Encapsulate3_dyn();

		virtual ::String ToString( hx::Null< int >  p_places);
		Dynamic ToString_dyn();

		static ::haxor::math::AABB3 temp;
		static ::haxor::math::AABB3 get_temp( );
		static Dynamic get_temp_dyn();

		static ::haxor::math::Vector3 Center( ::haxor::math::AABB3 p_b,::haxor::math::Vector3 p_result);
		static Dynamic Center_dyn();

		static ::haxor::math::AABB3 FromMinMax( Float p_xmin,Float p_xmax,Float p_ymin,Float p_ymax,Float p_zmin,Float p_zmax,::haxor::math::AABB3 p_result);
		static Dynamic FromMinMax_dyn();

		static ::haxor::math::AABB3 FromCenter( Float p_x,Float p_y,Float p_z,Float p_width,Float p_height,Float p_depth,::haxor::math::AABB3 p_result);
		static Dynamic FromCenter_dyn();

		static ::haxor::math::AABB3 empty;
		static ::haxor::math::AABB3 get_empty( );
		static Dynamic get_empty_dyn();

};

} // end namespace haxor
} // end namespace math

#endif /* INCLUDED_haxor_math_AABB3 */ 
