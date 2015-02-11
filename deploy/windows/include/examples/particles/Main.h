#ifndef INCLUDED_examples_particles_Main
#define INCLUDED_examples_particles_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Application.h>
#include <haxor/core/IRenderable.h>
#include <haxor/core/IUpdateable.h>
HX_DECLARE_CLASS2(examples,particles,Main)
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,CameraOrbit)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,MeshRenderer)
HX_DECLARE_CLASS2(haxor,component,ParticleRenderer)
HX_DECLARE_CLASS2(haxor,component,Renderer)
HX_DECLARE_CLASS2(haxor,core,Application)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IRenderable)
HX_DECLARE_CLASS2(haxor,core,IUpdateable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,platform,windows,WinApplication)
namespace examples{
namespace particles{


class HXCPP_CLASS_ATTRIBUTES  Main_obj : public ::haxor::core::Application_obj{
	public:
		typedef ::haxor::core::Application_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::haxor::core::IUpdateable_obj *()
			{ return new ::haxor::core::IUpdateable_delegate_< Main_obj >(this); }
		inline operator ::haxor::core::IRenderable_obj *()
			{ return new ::haxor::core::IRenderable_delegate_< Main_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Main"); }

		bool debug;
		::haxor::component::CameraOrbit orbit;
		::haxor::component::ParticleRenderer particle;
		Float angle;
		virtual Void LoadDebug( );
		Dynamic LoadDebug_dyn();

		virtual Void Initialize( );

		virtual Void OnStart( );

		virtual Void CreateParticle( );
		Dynamic CreateParticle_dyn();

		virtual Void OnUpdate( );
		Dynamic OnUpdate_dyn();

		virtual Void OnRender( );
		Dynamic OnRender_dyn();

		virtual bool Load( );

		virtual Void OnLoadProgress( ::String p_id,Float p_progress);

		virtual Void OnLoadComplete( ::String p_id,Dynamic p_asset);

		static Void main( );
		static Dynamic main_dyn();

};

} // end namespace examples
} // end namespace particles

#endif /* INCLUDED_examples_particles_Main */ 
