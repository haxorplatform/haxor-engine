#ifndef INCLUDED_haxor_context_GizmoContext
#define INCLUDED_haxor_context_GizmoContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,context,GizmoContext)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,Material)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
HX_DECLARE_CLASS2(haxor,math,Color)
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
		virtual Void Initialize( );
		Dynamic Initialize_dyn();

		virtual Void CreateTextureQuad( );
		Dynamic CreateTextureQuad_dyn();

		virtual Void CreateAxis( );
		Dynamic CreateAxis_dyn();

		virtual Void CreateGrid( Float p_step);
		Dynamic CreateGrid_dyn();

		virtual Void DrawGrid( Float p_area,::haxor::math::Color p_color);
		Dynamic DrawGrid_dyn();

		virtual Void DrawAxis( Float p_area);
		Dynamic DrawAxis_dyn();

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_GizmoContext */ 
