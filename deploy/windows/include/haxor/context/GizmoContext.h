#ifndef INCLUDED_haxor_context_GizmoContext
#define INCLUDED_haxor_context_GizmoContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,context,AxisGizmo)
HX_DECLARE_CLASS2(haxor,context,CanvasGizmo)
HX_DECLARE_CLASS2(haxor,context,Gizmo)
HX_DECLARE_CLASS2(haxor,context,GizmoContext)
HX_DECLARE_CLASS2(haxor,context,LineGizmo)
HX_DECLARE_CLASS2(haxor,context,PointGizmo)
HX_DECLARE_CLASS2(haxor,context,WireCubeGizmo)
HX_DECLARE_CLASS2(haxor,context,WireSphereGizmo)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,Material)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
HX_DECLARE_CLASS2(haxor,math,Color)
HX_DECLARE_CLASS2(haxor,math,Matrix4)
HX_DECLARE_CLASS2(haxor,math,Vector3)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  GizmoContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GizmoContext_obj OBJ_;
		GizmoContext_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GizmoContext_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GizmoContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GizmoContext"); }

		::haxor::graphics::mesh::Mesh grid;
		::haxor::graphics::mesh::Mesh axis;
		::haxor::graphics::mesh::Mesh texture;
		::haxor::graphics::material::Material gizmo_material;
		::haxor::graphics::material::Material texture_material;
		::haxor::context::WireSphereGizmo wire_sphere_renderer;
		::haxor::context::WireCubeGizmo wire_cube_renderer;
		::haxor::context::AxisGizmo axis_renderer;
		::haxor::context::LineGizmo line_renderer;
		::haxor::context::PointGizmo point_renderer;
		::haxor::context::CanvasGizmo canvas_renderer;
		virtual Void Initialize( );
		Dynamic Initialize_dyn();

		virtual Void CreateTextureQuad( );
		Dynamic CreateTextureQuad_dyn();

		virtual Void CreateGrid( Float p_step);
		Dynamic CreateGrid_dyn();

		virtual Void DrawGrid( Float p_area,::haxor::math::Color p_color);
		Dynamic DrawGrid_dyn();

		virtual Void DrawWireSphere( ::haxor::math::Vector3 p_position,Float p_radius,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform);
		Dynamic DrawWireSphere_dyn();

		virtual Void DrawWireCube( ::haxor::math::Vector3 p_position,::haxor::math::Vector3 p_size,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform);
		Dynamic DrawWireCube_dyn();

		virtual Void DrawAxis( ::haxor::math::Vector3 p_position,::haxor::math::Vector3 p_size,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform);
		Dynamic DrawAxis_dyn();

		virtual Void DrawLine( ::haxor::math::Vector3 p_from,::haxor::math::Vector3 p_to,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform);
		Dynamic DrawLine_dyn();

		virtual Void DrawPoint( ::haxor::math::Vector3 p_position,Float p_size,::haxor::math::Color p_color,bool p_smooth,::haxor::math::Matrix4 p_transform);
		Dynamic DrawPoint_dyn();

		virtual Void Render( );
		Dynamic Render_dyn();

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_GizmoContext */ 
