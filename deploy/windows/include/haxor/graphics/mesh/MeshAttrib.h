#ifndef INCLUDED_haxor_graphics_mesh_MeshAttrib
#define INCLUDED_haxor_graphics_mesh_MeshAttrib

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(haxor,graphics,mesh,MeshAttrib)
HX_DECLARE_CLASS2(haxor,io,Buffer)
namespace haxor{
namespace graphics{
namespace mesh{


class HXCPP_CLASS_ATTRIBUTES  MeshAttrib_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MeshAttrib_obj OBJ_;
		MeshAttrib_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MeshAttrib_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MeshAttrib_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MeshAttrib"); }

		int _cid_;
		int _loc_;
		virtual ::String get_name( );
		Dynamic get_name_dyn();

		::String m_name;
		::haxor::io::Buffer data;
		int offset;
		virtual int get_count( );
		Dynamic get_count_dyn();

};

} // end namespace haxor
} // end namespace graphics
} // end namespace mesh

#endif /* INCLUDED_haxor_graphics_mesh_MeshAttrib */ 
