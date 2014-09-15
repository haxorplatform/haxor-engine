#ifndef INCLUDED_haxor_component_Camera
#define INCLUDED_haxor_component_Camera

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/Behaviour.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Camera)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,texture,RenderTexture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS3(haxor,graphics,texture,TextureCube)
HX_DECLARE_CLASS2(haxor,math,AABB2)
HX_DECLARE_CLASS2(haxor,math,Color)
HX_DECLARE_CLASS2(haxor,math,Matrix4)
HX_DECLARE_CLASS2(haxor,math,Vector3)
HX_DECLARE_CLASS2(haxor,math,Vector4)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  Camera_obj : public ::haxor::component::Behaviour_obj{
	public:
		typedef ::haxor::component::Behaviour_obj super;
		typedef Camera_obj OBJ_;
		Camera_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Camera_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Camera_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Camera"); }

		int __fcid;
		::haxor::math::Color background;
		::haxor::graphics::texture::TextureCube skybox;
		int clear;
		virtual int get_mask( );
		Dynamic get_mask_dyn();

		virtual int set_mask( int v);
		Dynamic set_mask_dyn();

		int m_mask;
		Array< int > m_layers;
		virtual Float get_fov( );
		Dynamic get_fov_dyn();

		virtual Float set_fov( Float v);
		Dynamic set_fov_dyn();

		Float m_fov;
		virtual Float get_near( );
		Dynamic get_near_dyn();

		virtual Float set_near( Float v);
		Dynamic set_near_dyn();

		Float m_near;
		virtual Float get_far( );
		Dynamic get_far_dyn();

		virtual Float set_far( Float v);
		Dynamic set_far_dyn();

		Float m_far;
		int m_order;
		virtual int get_order( );
		Dynamic get_order_dyn();

		virtual int set_order( int v);
		Dynamic set_order_dyn();

		virtual ::haxor::math::AABB2 get_pixelViewport( );
		Dynamic get_pixelViewport_dyn();

		::haxor::math::AABB2 m_pixelViewport;
		virtual ::haxor::math::AABB2 get_viewport( );
		Dynamic get_viewport_dyn();

		virtual ::haxor::math::AABB2 set_viewport( ::haxor::math::AABB2 v);
		Dynamic set_viewport_dyn();

		Float m_aspect;
		::haxor::math::AABB2 m_viewport;
		::haxor::math::Matrix4 CameraToWorld;
		virtual ::haxor::math::Matrix4 get_CameraToWorld( );
		Dynamic get_CameraToWorld_dyn();

		::haxor::math::Matrix4 WorldToCamera;
		virtual ::haxor::math::Matrix4 get_WorldToCamera( );
		Dynamic get_WorldToCamera_dyn();

		::haxor::math::Matrix4 ProjectionMatrix;
		virtual ::haxor::math::Matrix4 get_ProjectionMatrix( );
		Dynamic get_ProjectionMatrix_dyn();

		::haxor::math::Matrix4 m_projectionMatrix;
		::haxor::math::Matrix4 m_skyboxProjection;
		::haxor::math::Matrix4 ProjectionMatrixInverse;
		virtual ::haxor::math::Matrix4 get_ProjectionMatrixInverse( );
		Dynamic get_ProjectionMatrixInverse_dyn();

		::haxor::math::Matrix4 m_projectionMatrixInverse;
		::haxor::math::Matrix4 m_skyboxProjectionInverse;
		::haxor::graphics::texture::RenderTexture target;
		virtual ::haxor::graphics::texture::RenderTexture get_target( );
		Dynamic get_target_dyn();

		virtual ::haxor::graphics::texture::RenderTexture set_target( ::haxor::graphics::texture::RenderTexture v);
		Dynamic set_target_dyn();

		::haxor::graphics::texture::RenderTexture m_target;
		virtual Float get_quality( );
		Dynamic get_quality_dyn();

		virtual Float set_quality( Float v);
		Dynamic set_quality_dyn();

		Float m_quality;
		virtual bool get_captureDepth( );
		Dynamic get_captureDepth_dyn();

		virtual bool set_captureDepth( bool v);
		Dynamic set_captureDepth_dyn();

		bool m_captureDepth;
		virtual Dynamic get_filters( );
		Dynamic get_filters_dyn();

		virtual Dynamic set_filters( Dynamic v);
		Dynamic set_filters_dyn();

		Dynamic m_filters;
		virtual Array< ::Dynamic > get_frustum( );
		Dynamic get_frustum_dyn();

		Array< ::Dynamic > m_frustum;
		bool m_projection_dirty;
		bool m_view_uniform_dirty;
		bool m_proj_uniform_dirty;
		virtual Void OnBuild( );

		virtual ::haxor::math::Vector4 WorldToProjection( ::haxor::math::Vector3 p_world_point,::haxor::math::Vector4 p_result);
		Dynamic WorldToProjection_dyn();

		virtual Float WorldToDepth( ::haxor::math::Vector3 p_world_point);
		Dynamic WorldToDepth_dyn();

		virtual bool IsCulled( ::haxor::math::Vector3 p_world_point);
		Dynamic IsCulled_dyn();

		virtual Void LookAt( ::haxor::math::Vector3 p_at,::haxor::math::Vector3 p_up,hx::Null< Float >  p_smooth);
		Dynamic LookAt_dyn();

		virtual Void UpdateProjection( );
		Dynamic UpdateProjection_dyn();

		virtual Void OnTransformUpdate( );

		virtual Void OnDestroy( );

		static Array< ::Dynamic > get_list( );
		static Dynamic get_list_dyn();

		static ::haxor::component::Camera get_current( );
		static Dynamic get_current_dyn();

		static ::haxor::component::Camera m_current;
		static ::haxor::component::Camera get_main( );
		static Dynamic get_main_dyn();

		static ::haxor::component::Camera set_main( ::haxor::component::Camera v);
		static Dynamic set_main_dyn();

		static ::haxor::component::Camera m_main;
};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_Camera */ 
