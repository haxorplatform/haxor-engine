#ifndef INCLUDED_haxor_math_Quaternion
#define INCLUDED_haxor_math_Quaternion

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,math,Matrix4)
HX_DECLARE_CLASS2(haxor,math,Quaternion)
HX_DECLARE_CLASS2(haxor,math,Vector3)
HX_DECLARE_CLASS2(haxor,math,Vector4)
namespace haxor{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Quaternion_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Quaternion_obj OBJ_;
		Quaternion_obj();
		Void __construct(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z,hx::Null< Float >  __o_p_w);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Quaternion_obj > __new(hx::Null< Float >  __o_p_x,hx::Null< Float >  __o_p_y,hx::Null< Float >  __o_p_z,hx::Null< Float >  __o_p_w);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Quaternion_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Quaternion"); }

		virtual ::haxor::math::Matrix4 get_matrix( );
		Dynamic get_matrix_dyn();

		virtual ::haxor::math::Matrix4 set_matrix( ::haxor::math::Matrix4 v);
		Dynamic set_matrix_dyn();

		virtual ::haxor::math::Vector3 get_euler( );
		Dynamic get_euler_dyn();

		virtual ::haxor::math::Vector3 set_euler( ::haxor::math::Vector3 v);
		Dynamic set_euler_dyn();

		::haxor::math::Quaternion clone;
		virtual ::haxor::math::Quaternion get_clone( );
		Dynamic get_clone_dyn();

		::haxor::math::Vector4 xyzw;
		virtual ::haxor::math::Vector4 get_xyzw( );
		Dynamic get_xyzw_dyn();

		Float length;
		virtual Float get_length( );
		Dynamic get_length_dyn();

		::haxor::math::Quaternion normalized;
		virtual ::haxor::math::Quaternion get_normalized( );
		Dynamic get_normalized_dyn();

		Float x;
		Float y;
		Float z;
		Float w;
		virtual ::haxor::math::Quaternion Set( hx::Null< Float >  p_x,hx::Null< Float >  p_y,hx::Null< Float >  p_z,hx::Null< Float >  p_w);
		Dynamic Set_dyn();

		virtual ::haxor::math::Quaternion SetQuaternion( ::haxor::math::Quaternion p_q);
		Dynamic SetQuaternion_dyn();

		virtual ::haxor::math::Quaternion Normalize( );
		Dynamic Normalize_dyn();

		::haxor::math::Quaternion conjugate;
		virtual ::haxor::math::Quaternion get_conjugate( );
		Dynamic get_conjugate_dyn();

		::haxor::math::Quaternion inverse;
		virtual ::haxor::math::Quaternion get_inverse( );
		Dynamic get_inverse_dyn();

		virtual ::haxor::math::Quaternion Invert( );
		Dynamic Invert_dyn();

		virtual ::haxor::math::Quaternion Scale( Float p_v);
		Dynamic Scale_dyn();

		virtual ::haxor::math::Quaternion Multiply( ::haxor::math::Quaternion p_v,hx::Null< bool >  p_normalize);
		Dynamic Multiply_dyn();

		virtual ::haxor::math::Vector3 Transform( ::haxor::math::Vector3 p_v);
		Dynamic Transform_dyn();

		virtual ::haxor::math::Quaternion Delta( ::haxor::math::Quaternion p_q);
		Dynamic Delta_dyn();

		virtual ::haxor::math::Quaternion SetAxisAngle( ::haxor::math::Vector3 p_axis,Float p_angle);
		Dynamic SetAxisAngle_dyn();

		virtual Array< Float > ToArray( );
		Dynamic ToArray_dyn();

		virtual ::String ToString( hx::Null< int >  p_places);
		Dynamic ToString_dyn();

		static ::haxor::math::Quaternion temp;
		static ::haxor::math::Quaternion get_temp( );
		static Dynamic get_temp_dyn();

		static ::haxor::math::Quaternion identity;
		static ::haxor::math::Quaternion get_identity( );
		static Dynamic get_identity_dyn();

		static ::haxor::math::Quaternion FromEuler( ::haxor::math::Vector3 p_euler,::haxor::math::Quaternion p_result);
		static Dynamic FromEuler_dyn();

		static ::haxor::math::Vector3 ToEuler( ::haxor::math::Quaternion p_quaternion,::haxor::math::Vector3 p_result);
		static Dynamic ToEuler_dyn();

		static ::haxor::math::Quaternion FromMatrix4( ::haxor::math::Matrix4 p_matrix,::haxor::math::Quaternion p_result);
		static Dynamic FromMatrix4_dyn();

		static Float Dot( ::haxor::math::Quaternion p_a,::haxor::math::Quaternion p_b);
		static Dynamic Dot_dyn();

		static ::haxor::math::Quaternion DeltaRotation( ::haxor::math::Quaternion p_a,::haxor::math::Quaternion p_b,::haxor::math::Quaternion p_result);
		static Dynamic DeltaRotation_dyn();

		static ::haxor::math::Quaternion Inverse( ::haxor::math::Quaternion p_q,::haxor::math::Quaternion p_result);
		static Dynamic Inverse_dyn();

		static ::haxor::math::Quaternion Lerp( ::haxor::math::Quaternion p_a,::haxor::math::Quaternion p_b,Float p_ratio,::haxor::math::Quaternion p_result);
		static Dynamic Lerp_dyn();

		static ::haxor::math::Quaternion Slerp( ::haxor::math::Quaternion p_a,::haxor::math::Quaternion p_b,Float p_ratio);
		static Dynamic Slerp_dyn();

		static ::haxor::math::Quaternion FromAxisAngle( ::haxor::math::Vector3 p_axis,Float p_angle);
		static Dynamic FromAxisAngle_dyn();

		static ::haxor::math::Quaternion LookAt( ::haxor::math::Vector3 p_eye,::haxor::math::Vector3 p_at,::haxor::math::Vector3 p_up,::haxor::math::Quaternion p_result);
		static Dynamic LookAt_dyn();

		static ::haxor::math::Quaternion LookRotation( ::haxor::math::Vector3 p_forward,::haxor::math::Vector3 p_up);
		static Dynamic LookRotation_dyn();

		static ::haxor::math::Quaternion Parse( ::String p_data,::String p_delimiter);
		static Dynamic Parse_dyn();

};

} // end namespace haxor
} // end namespace math

#endif /* INCLUDED_haxor_math_Quaternion */ 
