#ifndef INCLUDED_haxor_component_ParticleRenderer
#define INCLUDED_haxor_component_ParticleRenderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/MeshRenderer.h>
#include <haxor/core/IUpdateable.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,MeshRenderer)
HX_DECLARE_CLASS2(haxor,component,ParticleAttribute)
HX_DECLARE_CLASS2(haxor,component,ParticleEmitter)
HX_DECLARE_CLASS2(haxor,component,ParticleLife)
HX_DECLARE_CLASS2(haxor,component,ParticleRenderer)
HX_DECLARE_CLASS2(haxor,component,ParticleSheet)
HX_DECLARE_CLASS2(haxor,component,ParticleStart)
HX_DECLARE_CLASS2(haxor,component,ParticleSystemState)
HX_DECLARE_CLASS2(haxor,component,Renderer)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IUpdateable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,Material)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh3)
HX_DECLARE_CLASS3(haxor,graphics,mesh,MeshLayout)
HX_DECLARE_CLASS2(haxor,math,AABB3)
HX_DECLARE_CLASS2(haxor,math,Vector3)
HX_DECLARE_CLASS2(haxor,thread,Kernel)
HX_DECLARE_CLASS2(haxor,thread,ParticleKernel)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  ParticleRenderer_obj : public ::haxor::component::MeshRenderer_obj{
	public:
		typedef ::haxor::component::MeshRenderer_obj super;
		typedef ParticleRenderer_obj OBJ_;
		ParticleRenderer_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ParticleRenderer_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ParticleRenderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::haxor::core::IUpdateable_obj *()
			{ return new ::haxor::core::IUpdateable_delegate_< ParticleRenderer_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("ParticleRenderer"); }

		virtual Float get_emitted( );
		Dynamic get_emitted_dyn();

		Float m_emitted_start;
		Float m_emitted_count;
		virtual bool get_playing( );
		Dynamic get_playing_dyn();

		bool m_playing;
		virtual ::haxor::math::AABB3 get_bounds( );
		Dynamic get_bounds_dyn();

		virtual ::haxor::math::AABB3 set_bounds( ::haxor::math::AABB3 v);
		Dynamic set_bounds_dyn();

		virtual int get_count( );
		Dynamic get_count_dyn();

		virtual int set_count( int v);
		Dynamic set_count_dyn();

		int m_count;
		Float elapsed;
		Float duration;
		bool billboard;
		bool local;
		bool loop;
		::haxor::component::ParticleEmitter emitter;
		::haxor::component::ParticleStart start;
		::haxor::component::ParticleLife life;
		::haxor::component::ParticleSheet sheet;
		::haxor::component::ParticleAttribute rate;
		::haxor::math::Vector3 force;
		::haxor::graphics::mesh::Mesh3 m_particles;
		::haxor::component::ParticleSystemState m_state;
		::haxor::thread::ParticleKernel m_kernel;
		virtual Void OnBuild( );

		virtual Void Emit( hx::Null< Float >  p_emit_count);
		Dynamic Emit_dyn();

		virtual Void Play( );
		Dynamic Play_dyn();

		virtual Void Pause( );
		Dynamic Pause_dyn();

		virtual Void Reset( );
		Dynamic Reset_dyn();

		virtual Void Stop( );
		Dynamic Stop_dyn();

		virtual Void Simulate( );
		Dynamic Simulate_dyn();

		virtual Void OnUpdate( );
		Dynamic OnUpdate_dyn();

		virtual Void UpdateMesh( );
		Dynamic UpdateMesh_dyn();

};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_ParticleRenderer */ 
