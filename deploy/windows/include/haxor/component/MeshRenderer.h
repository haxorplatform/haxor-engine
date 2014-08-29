#ifndef INCLUDED_haxor_component_MeshRenderer
#define INCLUDED_haxor_component_MeshRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/Renderer.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Camera)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,MeshRenderer)
HX_DECLARE_CLASS2(haxor,component,Renderer)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  MeshRenderer_obj : public ::haxor::component::Renderer_obj{
	public:
		typedef ::haxor::component::Renderer_obj super;
		typedef MeshRenderer_obj OBJ_;
		MeshRenderer_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MeshRenderer_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MeshRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MeshRenderer"); }

		virtual ::haxor::graphics::mesh::Mesh get_mesh( );
		Dynamic get_mesh_dyn();

		virtual ::haxor::graphics::mesh::Mesh set_mesh( ::haxor::graphics::mesh::Mesh v);
		Dynamic set_mesh_dyn();

		::haxor::graphics::mesh::Mesh m_mesh;
		virtual bool get_visible( );
		Dynamic get_visible_dyn();

		virtual Void OnBuild( );

		virtual bool IsVisible( ::haxor::component::Camera p_camera);
		Dynamic IsVisible_dyn();

		virtual bool CheckCulling( );
		Dynamic CheckCulling_dyn();

		virtual Void OnRender( );

};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_MeshRenderer */ 
