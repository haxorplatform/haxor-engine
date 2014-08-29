#ifndef INCLUDED_haxor_component_SkinnedMeshRenderer
#define INCLUDED_haxor_component_SkinnedMeshRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/MeshRenderer.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,MeshRenderer)
HX_DECLARE_CLASS2(haxor,component,Renderer)
HX_DECLARE_CLASS2(haxor,component,SkinnedMeshRenderer)
HX_DECLARE_CLASS2(haxor,component,Transform)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,texture,ComputeTexture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture2D)
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS2(haxor,io,FloatArray)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  SkinnedMeshRenderer_obj : public ::haxor::component::MeshRenderer_obj{
	public:
		typedef ::haxor::component::MeshRenderer_obj super;
		typedef SkinnedMeshRenderer_obj OBJ_;
		SkinnedMeshRenderer_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SkinnedMeshRenderer_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SkinnedMeshRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SkinnedMeshRenderer"); }

		virtual Array< ::Dynamic > set_joints( Array< ::Dynamic > v);
		Dynamic set_joints_dyn();

		virtual Array< ::Dynamic > get_joints( );
		Dynamic get_joints_dyn();

		Array< ::Dynamic > m_joints;
		::haxor::io::FloatArray m_buffer;
		::haxor::graphics::texture::ComputeTexture m_data;
		virtual Void OnBuild( );

		virtual Void OnRender( );

};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_SkinnedMeshRenderer */ 
