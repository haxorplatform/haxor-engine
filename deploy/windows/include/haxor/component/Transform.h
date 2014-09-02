#ifndef INCLUDED_haxor_component_Transform
#define INCLUDED_haxor_component_Transform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/Component.h>
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,Transform)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,math,Matrix4)
HX_DECLARE_CLASS2(haxor,math,Quaternion)
HX_DECLARE_CLASS2(haxor,math,Vector3)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  Transform_obj : public ::haxor::component::Component_obj{
	public:
		typedef ::haxor::component::Component_obj super;
		typedef Transform_obj OBJ_;
		Transform_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Transform_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Transform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Transform"); }

		virtual ::haxor::math::Vector3 get_right( );
		Dynamic get_right_dyn();

		virtual ::haxor::math::Vector3 set_right( ::haxor::math::Vector3 v);
		Dynamic set_right_dyn();

		::haxor::math::Vector3 m_right;
		virtual ::haxor::math::Vector3 get_up( );
		Dynamic get_up_dyn();

		virtual ::haxor::math::Vector3 set_up( ::haxor::math::Vector3 v);
		Dynamic set_up_dyn();

		::haxor::math::Vector3 m_up;
		virtual ::haxor::math::Vector3 get_forward( );
		Dynamic get_forward_dyn();

		virtual ::haxor::math::Vector3 set_forward( ::haxor::math::Vector3 v);
		Dynamic set_forward_dyn();

		::haxor::math::Vector3 m_forward;
		virtual ::haxor::component::Transform get_parent( );
		Dynamic get_parent_dyn();

		virtual ::haxor::component::Transform set_parent( ::haxor::component::Transform v);
		Dynamic set_parent_dyn();

		::haxor::component::Transform m_parent;
		int childCount;
		virtual int get_childCount( );
		Dynamic get_childCount_dyn();

		virtual ::haxor::math::Vector3 get_localPosition( );
		Dynamic get_localPosition_dyn();

		virtual ::haxor::math::Vector3 set_localPosition( ::haxor::math::Vector3 v);
		Dynamic set_localPosition_dyn();

		::haxor::math::Vector3 m_localPosition;
		virtual ::haxor::math::Quaternion get_localRotation( );
		Dynamic get_localRotation_dyn();

		virtual ::haxor::math::Quaternion set_localRotation( ::haxor::math::Quaternion v);
		Dynamic set_localRotation_dyn();

		::haxor::math::Quaternion m_localRotation;
		virtual ::haxor::math::Vector3 get_localEuler( );
		Dynamic get_localEuler_dyn();

		virtual ::haxor::math::Vector3 set_localEuler( ::haxor::math::Vector3 v);
		Dynamic set_localEuler_dyn();

		virtual ::haxor::math::Vector3 get_localScale( );
		Dynamic get_localScale_dyn();

		virtual ::haxor::math::Vector3 set_localScale( ::haxor::math::Vector3 v);
		Dynamic set_localScale_dyn();

		::haxor::math::Vector3 m_localScale;
		virtual ::haxor::math::Vector3 get_position( );
		Dynamic get_position_dyn();

		virtual ::haxor::math::Vector3 set_position( ::haxor::math::Vector3 v);
		Dynamic set_position_dyn();

		::haxor::math::Vector3 m_position;
		virtual ::haxor::math::Quaternion get_rotation( );
		Dynamic get_rotation_dyn();

		virtual ::haxor::math::Quaternion set_rotation( ::haxor::math::Quaternion v);
		Dynamic set_rotation_dyn();

		::haxor::math::Quaternion m_rotation;
		virtual ::haxor::math::Vector3 get_euler( );
		Dynamic get_euler_dyn();

		virtual ::haxor::math::Vector3 set_euler( ::haxor::math::Vector3 v);
		Dynamic set_euler_dyn();

		virtual ::haxor::math::Vector3 get_scale( );
		Dynamic get_scale_dyn();

		::haxor::math::Vector3 m_scale;
		virtual ::haxor::math::Matrix4 get_WorldMatrix( );
		Dynamic get_WorldMatrix_dyn();

		::haxor::math::Matrix4 m_worldMatrix;
		virtual ::haxor::math::Matrix4 get_WorldMatrixInverse( );
		Dynamic get_WorldMatrixInverse_dyn();

		::haxor::math::Matrix4 m_worldMatrixInverse;
		::haxor::math::Matrix4 m_localMatrix;
		bool m_lmt_dirty;
		bool m_lmrs_dirty;
		bool m_uniform_dirty;
		bool m_dirty;
		bool m_inverse_dirty;
		bool m_wsp_dirty;
		bool m_wsrs_dirty;
		Array< ::Dynamic > m_hierarchy;
		virtual Void OnBuild( );

		virtual Void UpdateLMT( );
		Dynamic UpdateLMT_dyn();

		virtual Void UpdateWSP( );
		Dynamic UpdateWSP_dyn();

		virtual Void UpdateLMRS( );
		Dynamic UpdateLMRS_dyn();

		virtual Void UpdateWSRS( );
		Dynamic UpdateWSRS_dyn();

		virtual Void UpdateWorldMatrix( );
		Dynamic UpdateWorldMatrix_dyn();

		virtual Void Invalidate( );
		Dynamic Invalidate_dyn();

		virtual Void LookAt( ::haxor::math::Vector3 p_at,::haxor::math::Vector3 p_up,hx::Null< Float >  p_smooth);
		Dynamic LookAt_dyn();

		virtual ::haxor::component::Transform GetChild( int p_index);
		Dynamic GetChild_dyn();

		virtual ::haxor::component::Transform GetChildByName( ::String p_name);
		Dynamic GetChildByName_dyn();

		virtual ::haxor::component::Transform Navigate( ::String p_path);
		Dynamic Navigate_dyn();

		virtual ::haxor::component::Transform Search( ::String p_name,hx::Null< bool >  p_exact);
		Dynamic Search_dyn();

		virtual Array< ::Dynamic > GetPathToRoot( );
		Dynamic GetPathToRoot_dyn();

		virtual ::String OutputHierarchy( );
		Dynamic OutputHierarchy_dyn();

		virtual Void Traverse( Dynamic p_callback);
		Dynamic Traverse_dyn();

		virtual Void TraverseStep( ::haxor::component::Transform p_child,int p_depth,Dynamic p_callback);
		Dynamic TraverseStep_dyn();

		virtual Void OnDestroy( );

		virtual ::String ToString( hx::Null< bool >  p_use_local,hx::Null< int >  p_places);
		Dynamic ToString_dyn();

		static Void TransformConcat( ::haxor::component::Transform t);
		static Dynamic TransformConcat_dyn();

		static ::haxor::component::Transform get_root( );
		static Dynamic get_root_dyn();

		static ::haxor::component::Transform m_root;
};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_Transform */ 
