#ifndef INCLUDED_haxor_context_CameraContext
#define INCLUDED_haxor_context_CameraContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Camera)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,context,CameraContext)
HX_DECLARE_CLASS2(haxor,context,UID)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,texture,RenderTexture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  CameraContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef CameraContext_obj OBJ_;
		CameraContext_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< CameraContext_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~CameraContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CameraContext"); }

		::haxor::context::UID cid;
		Array< ::Dynamic > list;
		Array< ::Dynamic > front;
		Array< ::Dynamic > back;
		virtual Void Create( ::haxor::component::Camera c);
		Dynamic Create_dyn();

		virtual Void Destroy( ::haxor::component::Camera c);
		Dynamic Destroy_dyn();

		virtual Void Bind( ::haxor::component::Camera c);
		Dynamic Bind_dyn();

		virtual Void Resize( );
		Dynamic Resize_dyn();

		virtual Void ClearTargets( ::haxor::component::Camera c);
		Dynamic ClearTargets_dyn();

		virtual Void Unbind( ::haxor::component::Camera c);
		Dynamic Unbind_dyn();

		virtual Void SwapTargets( ::haxor::component::Camera c);
		Dynamic SwapTargets_dyn();

		virtual Void UpdateViewport( ::haxor::component::Camera c);
		Dynamic UpdateViewport_dyn();

		virtual Void SortCameraList( );
		Dynamic SortCameraList_dyn();

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_CameraContext */ 
