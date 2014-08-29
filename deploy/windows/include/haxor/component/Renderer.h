#ifndef INCLUDED_haxor_component_Renderer
#define INCLUDED_haxor_component_Renderer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/Behaviour.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,Renderer)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,Material)
namespace haxor{
namespace component{


class HXCPP_CLASS_ATTRIBUTES  Renderer_obj : public ::haxor::component::Behaviour_obj{
	public:
		typedef ::haxor::component::Behaviour_obj super;
		typedef Renderer_obj OBJ_;
		Renderer_obj();
		Void __construct(::String __o_p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Renderer_obj > __new(::String __o_p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Renderer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Renderer"); }

		virtual ::haxor::graphics::material::Material get_material( );
		Dynamic get_material_dyn();

		virtual ::haxor::graphics::material::Material set_material( ::haxor::graphics::material::Material v);
		Dynamic set_material_dyn();

		::haxor::graphics::material::Material m_material;
		bool m_has_mesh;
		int m_last_queue;
		virtual Void OnBuild( );

		virtual Void OnRender( );
		Dynamic OnRender_dyn();

		virtual Void OnDestroy( );

};

} // end namespace haxor
} // end namespace component

#endif /* INCLUDED_haxor_component_Renderer */ 
