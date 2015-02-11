#ifndef INCLUDED_haxor_thread_ParticleKernel
#define INCLUDED_haxor_thread_ParticleKernel

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/thread/Kernel.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,MeshRenderer)
HX_DECLARE_CLASS2(haxor,component,ParticleRenderer)
HX_DECLARE_CLASS2(haxor,component,Renderer)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IUpdateable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,Material)
HX_DECLARE_CLASS3(haxor,graphics,material,Shader)
HX_DECLARE_CLASS3(haxor,graphics,texture,RenderTexture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS2(haxor,thread,Kernel)
HX_DECLARE_CLASS2(haxor,thread,ParticleKernel)
namespace haxor{
namespace thread{


class HXCPP_CLASS_ATTRIBUTES  ParticleKernel_obj : public ::haxor::thread::Kernel_obj{
	public:
		typedef ::haxor::thread::Kernel_obj super;
		typedef ParticleKernel_obj OBJ_;
		ParticleKernel_obj();
		Void __construct(::haxor::component::ParticleRenderer p_renderer);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ParticleKernel_obj > __new(::haxor::component::ParticleRenderer p_renderer);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ParticleKernel_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ParticleKernel"); }

		::haxor::graphics::texture::RenderTexture m_back;
		Float m_time;
		Float m_dt;
		::haxor::component::ParticleRenderer m_renderer;
		bool m_resize;
		Array< Float > m_system;
		virtual Void Execute( );

		static int DATA_SIZE;
		static ::haxor::graphics::material::Shader particle_kernel_shader;
		static ::String particle_kernel_source;
};

} // end namespace haxor
} // end namespace thread

#endif /* INCLUDED_haxor_thread_ParticleKernel */ 
