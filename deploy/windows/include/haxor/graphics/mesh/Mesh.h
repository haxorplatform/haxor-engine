#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#define INCLUDED_haxor_graphics_mesh_Mesh

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Resource.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
HX_DECLARE_CLASS3(haxor,graphics,mesh,MeshAttrib)
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS2(haxor,io,UInt16Array)
HX_DECLARE_CLASS2(haxor,math,AABB3)
namespace haxor{
namespace graphics{
namespace mesh{


class HXCPP_CLASS_ATTRIBUTES  Mesh_obj : public ::haxor::core::Resource_obj{
	public:
		typedef ::haxor::core::Resource_obj super;
		typedef Mesh_obj OBJ_;
		Mesh_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Mesh_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Mesh_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Mesh"); }

		virtual ::haxor::io::UInt16Array get_topology( );
		Dynamic get_topology_dyn();

		virtual ::haxor::io::UInt16Array set_topology( ::haxor::io::UInt16Array v);
		Dynamic set_topology_dyn();

		::haxor::graphics::mesh::MeshAttrib m_topology_attrib;
		virtual bool get_indexed( );
		Dynamic get_indexed_dyn();

		bool m_indexed;
		virtual int get_mode( );
		Dynamic get_mode_dyn();

		virtual int set_mode( int v);
		Dynamic set_mode_dyn();

		int m_mode;
		int primitive;
		Array< ::String > attribs;
		virtual Array< ::String > get_attribs( );
		Dynamic get_attribs_dyn();

		Array< ::Dynamic > m_attribs;
		virtual int get_vcount( );
		Dynamic get_vcount_dyn();

		int m_vcount;
		virtual ::haxor::math::AABB3 get_bounds( );
		Dynamic get_bounds_dyn();

		virtual ::haxor::math::AABB3 set_bounds( ::haxor::math::AABB3 v);
		Dynamic set_bounds_dyn();

		::haxor::math::AABB3 m_bounds;
		virtual Void Clear( hx::Null< bool >  p_from_gpu);
		Dynamic Clear_dyn();

		virtual bool Exists( ::String p_name);
		Dynamic Exists_dyn();

		virtual Dynamic Get( ::String p_name);
		Dynamic Get_dyn();

		virtual ::haxor::graphics::mesh::MeshAttrib GetAttribute( ::String p_name);
		Dynamic GetAttribute_dyn();

		virtual Void Remove( ::String p_name);
		Dynamic Remove_dyn();

		virtual ::haxor::graphics::mesh::MeshAttrib Set( ::String p_name,::haxor::io::Buffer p_data,hx::Null< int >  p_offset);
		Dynamic Set_dyn();

		virtual ::haxor::math::AABB3 GenerateAttribBounds( ::String p_attrib,::haxor::math::AABB3 p_result);
		Dynamic GenerateAttribBounds_dyn();

		virtual Void OnDestroy( );

};

} // end namespace haxor
} // end namespace graphics
} // end namespace mesh

#endif /* INCLUDED_haxor_graphics_mesh_Mesh */ 
