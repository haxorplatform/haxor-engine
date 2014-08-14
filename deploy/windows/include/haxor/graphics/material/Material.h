#ifndef INCLUDED_haxor_graphics_material_Material
#define INCLUDED_haxor_graphics_material_Material

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Resource.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,Material)
HX_DECLARE_CLASS3(haxor,graphics,material,Shader)
namespace haxor{
namespace graphics{
namespace material{


class HXCPP_CLASS_ATTRIBUTES  Material_obj : public ::haxor::core::Resource_obj{
	public:
		typedef ::haxor::core::Resource_obj super;
		typedef Material_obj OBJ_;
		Material_obj();
		Void __construct(::String p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Material_obj > __new(::String p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Material_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Material"); }

		bool ztest;
		int zfunc;
		bool zwrite;
		bool blend;
		int queue;
		int blendSrc;
		int blendDst;
		bool invert;
		int cull;
		bool lighting;
		bool grab;
		virtual ::haxor::graphics::material::Shader get_shader( );
		Dynamic get_shader_dyn();

		virtual ::haxor::graphics::material::Shader set_shader( ::haxor::graphics::material::Shader v);
		Dynamic set_shader_dyn();

		::haxor::graphics::material::Shader m_shader;
		virtual Void SetBlending( int p_src,int p_dst);
		Dynamic SetBlending_dyn();

		virtual Void OnDestroy( );

};

} // end namespace haxor
} // end namespace graphics
} // end namespace material

#endif /* INCLUDED_haxor_graphics_material_Material */ 
