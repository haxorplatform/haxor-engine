#ifndef INCLUDED_haxor_core_BaseApplication
#define INCLUDED_haxor_core_BaseApplication

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/Behaviour.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,ApplicationProtocol)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Platform)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,core,Scene)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  BaseApplication_obj : public ::haxor::component::Behaviour_obj{
	public:
		typedef ::haxor::component::Behaviour_obj super;
		typedef BaseApplication_obj OBJ_;
		BaseApplication_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BaseApplication_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BaseApplication_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BaseApplication"); }

		virtual ::haxor::core::ApplicationProtocol get_protocol( );
		Dynamic get_protocol_dyn();

		virtual ::String get_vendor( );
		Dynamic get_vendor_dyn();

		::String m_vendor;
		virtual int get_fps( );
		Dynamic get_fps_dyn();

		virtual int set_fps( int v);
		Dynamic set_fps_dyn();

		Float m_mspf;
		int m_fps;
		Float m_frame_ms;
		::haxor::core::Platform platform;
		virtual ::haxor::core::Platform get_platform( );
		Dynamic get_platform_dyn();

		::haxor::core::Platform m_platform;
		Array< ::Dynamic > m_scenes;
		virtual Void LoadScene( ::String p_name);
		Dynamic LoadScene_dyn();

		virtual Void DestroyScene( ::String p_name);
		Dynamic DestroyScene_dyn();

		virtual bool Load( );
		Dynamic Load_dyn();

		virtual Void Initialize( );
		Dynamic Initialize_dyn();

		virtual Void LoadComplete( );
		Dynamic LoadComplete_dyn();

		virtual Void Update( );
		Dynamic Update_dyn();

		virtual Void Render( );
		Dynamic Render_dyn();

		virtual Void OnQuit( );
		Dynamic OnQuit_dyn();

		virtual Void OnFocus( );
		Dynamic OnFocus_dyn();

		virtual Void OnUnfocus( );
		Dynamic OnUnfocus_dyn();

		virtual Void CheckResize( );
		Dynamic CheckResize_dyn();

		virtual Void OnResize( );
		Dynamic OnResize_dyn();

		virtual Void OnFullscreenEnter( );
		Dynamic OnFullscreenEnter_dyn();

		virtual Void OnFullscreenExit( );
		Dynamic OnFullscreenExit_dyn();

		virtual bool OnFullscreenRequest( bool v);
		Dynamic OnFullscreenRequest_dyn();

		virtual bool OnPointerLockRequest( bool v);
		Dynamic OnPointerLockRequest_dyn();

		virtual bool OnPointerVisibilityRequest( bool v);
		Dynamic OnPointerVisibilityRequest_dyn();

		virtual Void OnMousePosition( Float p_x,Float p_y);
		Dynamic OnMousePosition_dyn();

		virtual Float GetContainerWidth( );
		Dynamic GetContainerWidth_dyn();

		virtual Float GetContainerHeight( );
		Dynamic GetContainerHeight_dyn();

		static ::haxor::core::BaseApplication m_instance;
};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_BaseApplication */ 
