#ifndef INCLUDED_haxor_graphics_mesh_Model
#define INCLUDED_haxor_graphics_mesh_Model

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Model)
namespace haxor{
namespace graphics{
namespace mesh{


class HXCPP_CLASS_ATTRIBUTES  Model_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Model_obj OBJ_;
		Model_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Model_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Model_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Model"); }

		static ::haxor::graphics::mesh::Mesh screen;
		static ::haxor::graphics::mesh::Mesh get_screen( );
		static Dynamic get_screen_dyn();

		static ::haxor::graphics::mesh::Mesh m_screen;
		static ::haxor::graphics::mesh::Mesh planeXY;
		static ::haxor::graphics::mesh::Mesh get_planeXY( );
		static Dynamic get_planeXY_dyn();

		static ::haxor::graphics::mesh::Mesh m_planeXY;
		static ::haxor::graphics::mesh::Mesh planeXZ;
		static ::haxor::graphics::mesh::Mesh get_planeXZ( );
		static Dynamic get_planeXZ_dyn();

		static ::haxor::graphics::mesh::Mesh m_planeXZ;
		static ::haxor::graphics::mesh::Mesh planeYZ;
		static ::haxor::graphics::mesh::Mesh get_planeYZ( );
		static Dynamic get_planeYZ_dyn();

		static ::haxor::graphics::mesh::Mesh m_planeYZ;
		static ::haxor::graphics::mesh::Mesh cube;
		static ::haxor::graphics::mesh::Mesh get_cube( );
		static Dynamic get_cube_dyn();

		static ::haxor::graphics::mesh::Mesh m_cube;
		static ::haxor::graphics::mesh::Mesh tetrahedron;
		static ::haxor::graphics::mesh::Mesh get_tetrahedron( );
		static Dynamic get_tetrahedron_dyn();

		static ::haxor::graphics::mesh::Mesh m_tetrahedron;
		static ::haxor::graphics::mesh::Mesh sphere;
		static ::haxor::graphics::mesh::Mesh get_sphere( );
		static Dynamic get_sphere_dyn();

		static ::haxor::graphics::mesh::Mesh m_sphere;
};

} // end namespace haxor
} // end namespace graphics
} // end namespace mesh

#endif /* INCLUDED_haxor_graphics_mesh_Model */ 
