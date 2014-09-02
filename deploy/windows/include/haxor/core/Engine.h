#ifndef INCLUDED_haxor_core_Engine
#define INCLUDED_haxor_core_Engine

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Camera)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,Renderer)
HX_DECLARE_CLASS2(haxor,core,Engine)
HX_DECLARE_CLASS2(haxor,core,EngineState)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Engine_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Engine_obj OBJ_;
		Engine_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Engine_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Engine_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Engine"); }

		static ::haxor::core::EngineState state;
		static Void Initialize( );
		static Dynamic Initialize_dyn();

		static Void Collect( );
		static Dynamic Collect_dyn();

		static Void Update( );
		static Dynamic Update_dyn();

		static Void Render( );
		static Dynamic Render_dyn();

		static Void RenderCameras( );
		static Dynamic RenderCameras_dyn();

		static Void RenderCamera( ::haxor::component::Camera c);
		static Dynamic RenderCamera_dyn();

		static Void RenderCameraLayer( int l,::haxor::component::Camera c);
		static Dynamic RenderCameraLayer_dyn();

		static Void RenderRenderer( ::haxor::component::Renderer r);
		static Dynamic RenderRenderer_dyn();

		static Void RenderIRenderers( );
		static Dynamic RenderIRenderers_dyn();

		static Void RenderFinish( );
		static Dynamic RenderFinish_dyn();

		static Void Resize( );
		static Dynamic Resize_dyn();

};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Engine */ 
