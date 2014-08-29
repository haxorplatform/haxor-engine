#ifndef INCLUDED_haxor_context_RendererContext
#define INCLUDED_haxor_context_RendererContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Camera)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,Renderer)
HX_DECLARE_CLASS2(haxor,context,BaseProcess)
HX_DECLARE_CLASS2(haxor,context,Process)
HX_DECLARE_CLASS2(haxor,context,RendererContext)
HX_DECLARE_CLASS2(haxor,context,UID)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,texture,ComputeTexture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture2D)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  RendererContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef RendererContext_obj OBJ_;
		RendererContext_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< RendererContext_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~RendererContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("RendererContext"); }

		::haxor::context::UID rid;
		Array< ::Dynamic > display;
		Array< bool > sort;
		::haxor::graphics::texture::ComputeTexture skinning;
		virtual Void Initialize( );
		Dynamic Initialize_dyn();

		virtual Void OnMaterialChange( ::haxor::component::Renderer r);
		Dynamic OnMaterialChange_dyn();

		virtual Void OnMeshChange( ::haxor::component::Renderer r);
		Dynamic OnMeshChange_dyn();

		virtual Void OnLayerChange( ::haxor::component::Renderer r,int from,int to);
		Dynamic OnLayerChange_dyn();

		virtual Void UpdateDisplayList( ::haxor::component::Camera c);
		Dynamic UpdateDisplayList_dyn();

		virtual Void Enable( ::haxor::component::Renderer r);
		Dynamic Enable_dyn();

		virtual Void Disable( ::haxor::component::Renderer r);
		Dynamic Disable_dyn();

		virtual Void Destroy( ::haxor::component::Renderer r);
		Dynamic Destroy_dyn();

		virtual int DisplayListSort( ::haxor::component::Renderer a,::haxor::component::Renderer b);
		Dynamic DisplayListSort_dyn();

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_RendererContext */ 
