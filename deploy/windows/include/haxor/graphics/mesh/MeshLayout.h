#ifndef INCLUDED_haxor_graphics_mesh_MeshLayout
#define INCLUDED_haxor_graphics_mesh_MeshLayout

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/graphics/mesh/Mesh.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
HX_DECLARE_CLASS3(haxor,graphics,mesh,MeshLayout)
HX_DECLARE_CLASS2(haxor,math,Color)
namespace haxor{
namespace graphics{
namespace mesh{


class HXCPP_CLASS_ATTRIBUTES  MeshLayout_obj : public ::haxor::graphics::mesh::Mesh_obj{
	public:
		typedef ::haxor::graphics::mesh::Mesh_obj super;
		typedef MeshLayout_obj OBJ_;
		MeshLayout_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MeshLayout_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MeshLayout_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MeshLayout"); }

		virtual Dynamic get_vertex( );
		Dynamic get_vertex_dyn();

		virtual Dynamic set_vertex( Dynamic v);
		Dynamic set_vertex_dyn();

		Dynamic m_vertex;
		virtual Dynamic get_normal( );
		Dynamic get_normal_dyn();

		virtual Dynamic set_normal( Dynamic v);
		Dynamic set_normal_dyn();

		Dynamic m_normal;
		virtual Array< ::Dynamic > get_color( );
		Dynamic get_color_dyn();

		virtual Array< ::Dynamic > set_color( Array< ::Dynamic > v);
		Dynamic set_color_dyn();

		Array< ::Dynamic > m_color;
		virtual Dynamic get_uv0( );
		Dynamic get_uv0_dyn();

		virtual Dynamic set_uv0( Dynamic v);
		Dynamic set_uv0_dyn();

		Dynamic m_uv0;
		virtual Dynamic get_uv1( );
		Dynamic get_uv1_dyn();

		virtual Dynamic set_uv1( Dynamic v);
		Dynamic set_uv1_dyn();

		Dynamic m_uv1;
		virtual Dynamic get_tangent( );
		Dynamic get_tangent_dyn();

		virtual Dynamic set_tangent( Dynamic v);
		Dynamic set_tangent_dyn();

		Dynamic m_tangent;
		virtual Dynamic get_binormal( );
		Dynamic get_binormal_dyn();

		virtual Dynamic set_binormal( Dynamic v);
		Dynamic set_binormal_dyn();

		Dynamic m_binormal;
		virtual Void GenerateBounds( );
		Dynamic GenerateBounds_dyn();

		virtual Dynamic UpdateAttribute( ::String p_name,Dynamic p_list,hx::Null< bool >  p_is_color);
		Dynamic UpdateAttribute_dyn();

};

} // end namespace haxor
} // end namespace graphics
} // end namespace mesh

#endif /* INCLUDED_haxor_graphics_mesh_MeshLayout */ 
