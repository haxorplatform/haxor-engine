#ifndef INCLUDED_haxor_graphics_mesh_Mesh2D
#define INCLUDED_haxor_graphics_mesh_Mesh2D

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/graphics/mesh/MeshLayout.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh2D)
HX_DECLARE_CLASS3(haxor,graphics,mesh,MeshLayout)
namespace haxor{
namespace graphics{
namespace mesh{


class HXCPP_CLASS_ATTRIBUTES  Mesh2D_obj : public ::haxor::graphics::mesh::MeshLayout_obj{
	public:
		typedef ::haxor::graphics::mesh::MeshLayout_obj super;
		typedef Mesh2D_obj OBJ_;
		Mesh2D_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Mesh2D_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Mesh2D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Mesh2D"); }

};

} // end namespace haxor
} // end namespace graphics
} // end namespace mesh

#endif /* INCLUDED_haxor_graphics_mesh_Mesh2D */ 
