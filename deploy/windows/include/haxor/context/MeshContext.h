#ifndef INCLUDED_haxor_context_MeshContext
#define INCLUDED_haxor_context_MeshContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,context,MeshContext)
HX_DECLARE_CLASS2(haxor,context,UID)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
HX_DECLARE_CLASS3(haxor,graphics,mesh,MeshAttrib)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  MeshContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MeshContext_obj OBJ_;
		MeshContext_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MeshContext_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MeshContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MeshContext"); }

		::haxor::context::UID aid;
		::haxor::context::UID mid;
		Array< ::String > attribs;
		Array< int > buffers;
		Array< bool > activated;
		int active_max;
		::haxor::graphics::mesh::Mesh current;
		virtual Void Initialize( );
		Dynamic Initialize_dyn();

		virtual Void Bind( ::haxor::graphics::mesh::Mesh p_mesh);
		Dynamic Bind_dyn();

		virtual Void Unbind( );
		Dynamic Unbind_dyn();

		virtual Void Draw( ::haxor::graphics::mesh::Mesh m);
		Dynamic Draw_dyn();

		virtual Void RemoveAttrib( ::haxor::graphics::mesh::MeshAttrib p_attrib);
		Dynamic RemoveAttrib_dyn();

		virtual Void UpdateAttrib( ::haxor::graphics::mesh::MeshAttrib a,int p_mode,bool p_is_index);
		Dynamic UpdateAttrib_dyn();

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_MeshContext */ 
