#ifndef INCLUDED_haxor_math_Matrix4
#define INCLUDED_haxor_math_Matrix4

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,math,Matrix4)
HX_DECLARE_CLASS2(haxor,math,Quaternion)
HX_DECLARE_CLASS2(haxor,math,Vector2)
HX_DECLARE_CLASS2(haxor,math,Vector3)
HX_DECLARE_CLASS2(haxor,math,Vector4)
namespace haxor{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Matrix4_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Matrix4_obj OBJ_;
		Matrix4_obj();
		Void __construct(hx::Null< Float >  __o_p_m00,hx::Null< Float >  __o_p_m01,hx::Null< Float >  __o_p_m02,hx::Null< Float >  __o_p_m03,hx::Null< Float >  __o_p_m10,hx::Null< Float >  __o_p_m11,hx::Null< Float >  __o_p_m12,hx::Null< Float >  __o_p_m13,hx::Null< Float >  __o_p_m20,hx::Null< Float >  __o_p_m21,hx::Null< Float >  __o_p_m22,hx::Null< Float >  __o_p_m23,hx::Null< Float >  __o_p_m30,hx::Null< Float >  __o_p_m31,hx::Null< Float >  __o_p_m32,hx::Null< Float >  __o_p_m33);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Matrix4_obj > __new(hx::Null< Float >  __o_p_m00,hx::Null< Float >  __o_p_m01,hx::Null< Float >  __o_p_m02,hx::Null< Float >  __o_p_m03,hx::Null< Float >  __o_p_m10,hx::Null< Float >  __o_p_m11,hx::Null< Float >  __o_p_m12,hx::Null< Float >  __o_p_m13,hx::Null< Float >  __o_p_m20,hx::Null< Float >  __o_p_m21,hx::Null< Float >  __o_p_m22,hx::Null< Float >  __o_p_m23,hx::Null< Float >  __o_p_m30,hx::Null< Float >  __o_p_m31,hx::Null< Float >  __o_p_m32,hx::Null< Float >  __o_p_m33);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Matrix4_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Matrix4"); }

		virtual ::haxor::math::Matrix4 get_clone( );
		Dynamic get_clone_dyn();

		virtual ::haxor::math::Quaternion get_quaternion( );
		Dynamic get_quaternion_dyn();

		virtual ::haxor::math::Quaternion set_quaternion( ::haxor::math::Quaternion v);
		Dynamic set_quaternion_dyn();

		virtual Float get_trace( );
		Dynamic get_trace_dyn();

		::haxor::math::Matrix4 rotation;
		virtual ::haxor::math::Matrix4 get_rotation( );
		Dynamic get_rotation_dyn();

		::haxor::math::Matrix4 scale;
		virtual ::haxor::math::Matrix4 get_scale( );
		Dynamic get_scale_dyn();

		::haxor::math::Matrix4 translation;
		virtual ::haxor::math::Matrix4 get_translation( );
		Dynamic get_translation_dyn();

		::haxor::math::Matrix4 inverseTransform;
		virtual ::haxor::math::Matrix4 get_inverseTransform( );
		Dynamic get_inverseTransform_dyn();

		::haxor::math::Matrix4 transposed;
		virtual ::haxor::math::Matrix4 get_transposed( );
		Dynamic get_transposed_dyn();

		virtual Array< Float > ToRowMajor( );
		Dynamic ToRowMajor_dyn();

		virtual Array< Float > ToColumnMajor( );
		Dynamic ToColumnMajor_dyn();

		Float m00;
		Float m01;
		Float m02;
		Float m03;
		Float m10;
		Float m11;
		Float m12;
		Float m13;
		Float m20;
		Float m21;
		Float m22;
		Float m23;
		Float m30;
		Float m31;
		Float m32;
		Float m33;
		virtual ::haxor::math::Vector4 GetLine( int p_index,::haxor::math::Vector4 p_result);
		Dynamic GetLine_dyn();

		virtual Void SetLine( int p_index,Float p_x,Float p_y,Float p_z,Float p_w);
		Dynamic SetLine_dyn();

		virtual ::haxor::math::Vector4 GetColumn( int p_index,::haxor::math::Vector4 p_result);
		Dynamic GetColumn_dyn();

		virtual Void SetColumn( int p_index,Float p_x,Float p_y,Float p_z,Float p_w);
		Dynamic SetColumn_dyn();

		virtual ::haxor::math::Vector4 get_diagonalLR( );
		Dynamic get_diagonalLR_dyn();

		virtual ::haxor::math::Vector4 set_diagonalLR( ::haxor::math::Vector4 v);
		Dynamic set_diagonalLR_dyn();

		virtual ::haxor::math::Matrix4 SetIdentity( );
		Dynamic SetIdentity_dyn();

		virtual ::haxor::math::Matrix4 Set( hx::Null< Float >  p_m00,hx::Null< Float >  p_m01,hx::Null< Float >  p_m02,hx::Null< Float >  p_m03,hx::Null< Float >  p_m10,hx::Null< Float >  p_m11,hx::Null< Float >  p_m12,hx::Null< Float >  p_m13,hx::Null< Float >  p_m20,hx::Null< Float >  p_m21,hx::Null< Float >  p_m22,hx::Null< Float >  p_m23,hx::Null< Float >  p_m30,hx::Null< Float >  p_m31,hx::Null< Float >  p_m32,hx::Null< Float >  p_m33);
		Dynamic Set_dyn();

		virtual ::haxor::math::Matrix4 SetMatrix4( ::haxor::math::Matrix4 p_matrix);
		Dynamic SetMatrix4_dyn();

		virtual Float GetIndex( int p_index);
		Dynamic GetIndex_dyn();

		virtual ::haxor::math::Matrix4 SetIndex( int p_index,Float p_value);
		Dynamic SetIndex_dyn();

		virtual ::haxor::math::Matrix4 SetRowCol( int p_row,int p_col,Float p_value);
		Dynamic SetRowCol_dyn();

		virtual Float GetRowCol( int p_row,int p_col);
		Dynamic GetRowCol_dyn();

		virtual ::haxor::math::Matrix4 SwapCol( int p_a,int p_b);
		Dynamic SwapCol_dyn();

		virtual ::haxor::math::Matrix4 SwapRow( int p_a,int p_b);
		Dynamic SwapRow_dyn();

		virtual ::haxor::math::Matrix4 Transpose( );
		Dynamic Transpose_dyn();

		virtual ::haxor::math::Matrix4 ToRotation( );
		Dynamic ToRotation_dyn();

		virtual ::haxor::math::Vector3 Rotate( ::haxor::math::Vector3 p_vector);
		Dynamic Rotate_dyn();

		virtual ::haxor::math::Matrix4 SetTRS( ::haxor::math::Vector3 p_position,::haxor::math::Quaternion p_rotation,::haxor::math::Vector3 p_scale);
		Dynamic SetTRS_dyn();

		virtual ::haxor::math::Matrix4 MultiplyTransform( ::haxor::math::Matrix4 p_matrix);
		Dynamic MultiplyTransform_dyn();

		virtual ::haxor::math::Matrix4 Multiply3x4( ::haxor::math::Matrix4 p_matrix);
		Dynamic Multiply3x4_dyn();

		virtual ::haxor::math::Matrix4 Multiply( ::haxor::math::Matrix4 p_matrix);
		Dynamic Multiply_dyn();

		virtual ::haxor::math::Vector4 Transform4x4( ::haxor::math::Vector4 p_point);
		Dynamic Transform4x4_dyn();

		virtual ::haxor::math::Vector3 Transform3x4( ::haxor::math::Vector3 p_point);
		Dynamic Transform3x4_dyn();

		virtual ::haxor::math::Vector3 Transform3x3( ::haxor::math::Vector3 p_point);
		Dynamic Transform3x3_dyn();

		virtual Void Transform2x3( ::haxor::math::Vector2 p_point);
		Dynamic Transform2x3_dyn();

		virtual Void Transform2x2( ::haxor::math::Vector2 p_point);
		Dynamic Transform2x2_dyn();

		virtual ::haxor::math::Matrix4 SetLookAt( ::haxor::math::Vector3 p_eye,::haxor::math::Vector3 p_at,::haxor::math::Vector3 p_up);
		Dynamic SetLookAt_dyn();

		virtual ::haxor::math::Matrix4 SetFrustum( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far);
		Dynamic SetFrustum_dyn();

		virtual ::haxor::math::Matrix4 SetFrustumInverse( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far);
		Dynamic SetFrustumInverse_dyn();

		virtual ::haxor::math::Matrix4 SetOrtho( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far);
		Dynamic SetOrtho_dyn();

		virtual ::haxor::math::Matrix4 SetPerspective( Float p_fov,Float p_aspect,Float p_near,Float p_far);
		Dynamic SetPerspective_dyn();

		virtual ::haxor::math::Matrix4 SetPerspectiveInverse( Float p_fov,Float p_aspect,Float p_near,Float p_far);
		Dynamic SetPerspectiveInverse_dyn();

		virtual Array< Float > ToArray( );
		Dynamic ToArray_dyn();

		virtual ::String ToString( hx::Null< bool >  p_linear,hx::Null< int >  p_places);
		Dynamic ToString_dyn();

		static ::haxor::math::Matrix4 temp;
		static ::haxor::math::Matrix4 get_temp( );
		static Dynamic get_temp_dyn();

		static ::haxor::math::Matrix4 identity;
		static ::haxor::math::Matrix4 get_identity( );
		static Dynamic get_identity_dyn();

		static ::haxor::math::Matrix4 FromQuaternion( ::haxor::math::Quaternion p_quaternion,::haxor::math::Matrix4 p_result);
		static Dynamic FromQuaternion_dyn();

		static ::haxor::math::Matrix4 FromArray( Array< Float > p_array,::haxor::math::Matrix4 p_result);
		static Dynamic FromArray_dyn();

		static ::haxor::math::Matrix4 TRS( ::haxor::math::Vector3 p_position,::haxor::math::Quaternion p_rotation,::haxor::math::Vector3 p_scale,::haxor::math::Matrix4 p_result);
		static Dynamic TRS_dyn();

		static ::haxor::math::Matrix4 Frustum( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far,::haxor::math::Matrix4 p_result);
		static Dynamic Frustum_dyn();

		static ::haxor::math::Matrix4 FrustumInverse( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far,::haxor::math::Matrix4 p_result);
		static Dynamic FrustumInverse_dyn();

		static ::haxor::math::Matrix4 Ortho( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far,::haxor::math::Matrix4 p_result);
		static Dynamic Ortho_dyn();

		static ::haxor::math::Matrix4 OrthoInverse( Float p_left,Float p_right,Float p_top,Float p_bottom,Float p_near,Float p_far,::haxor::math::Matrix4 p_result);
		static Dynamic OrthoInverse_dyn();

		static ::haxor::math::Matrix4 Perspective( Float p_fov,Float p_aspect,Float p_near,Float p_far,::haxor::math::Matrix4 p_result);
		static Dynamic Perspective_dyn();

		static ::haxor::math::Matrix4 PerspectiveInverse( Float p_fov,Float p_aspect,Float p_near,Float p_far,::haxor::math::Matrix4 p_result);
		static Dynamic PerspectiveInverse_dyn();

		static ::haxor::math::Matrix4 GetRotation( ::haxor::math::Matrix4 p_matrix4,::haxor::math::Matrix4 p_result);
		static Dynamic GetRotation_dyn();

		static ::haxor::math::Matrix4 GetInverseTransform( ::haxor::math::Matrix4 p_matrix,::haxor::math::Matrix4 p_result);
		static Dynamic GetInverseTransform_dyn();

		static ::haxor::math::Matrix4 LookRotation( ::haxor::math::Vector3 p_forward,::haxor::math::Vector3 p_up,::haxor::math::Matrix4 p_result);
		static Dynamic LookRotation_dyn();

		static ::haxor::math::Matrix4 LookAt( ::haxor::math::Vector3 p_eye,::haxor::math::Vector3 p_at,::haxor::math::Vector3 p_up,::haxor::math::Matrix4 p_result);
		static Dynamic LookAt_dyn();

		static ::haxor::math::Matrix4 Parse( ::String p_data,::String p_delimiter);
		static Dynamic Parse_dyn();

};

} // end namespace haxor
} // end namespace math

#endif /* INCLUDED_haxor_math_Matrix4 */ 
