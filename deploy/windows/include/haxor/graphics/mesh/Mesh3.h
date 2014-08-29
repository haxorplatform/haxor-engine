#ifndef INCLUDED_haxor_graphics_mesh_Mesh3
#define INCLUDED_haxor_graphics_mesh_Mesh3

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/graphics/mesh/MeshLayout.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh3)
HX_DECLARE_CLASS3(haxor,graphics,mesh,MeshLayout)
namespace haxor{
namespace graphics{
namespace mesh{


class HXCPP_CLASS_ATTRIBUTES  Mesh3_obj : public ::haxor::graphics::mesh::MeshLayout_obj{
	public:
		typedef ::haxor::graphics::mesh::MeshLayout_obj super;
		typedef Mesh3_obj OBJ_;
		Mesh3_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Mesh3_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Mesh3_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Mesh3"); }

};

} // end namespace haxor
} // end namespace graphics
} // end namespace mesh

#endif /* INCLUDED_haxor_graphics_mesh_Mesh3 */ 
