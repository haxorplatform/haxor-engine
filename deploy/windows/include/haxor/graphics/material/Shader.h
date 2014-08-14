#ifndef INCLUDED_haxor_graphics_material_Shader
#define INCLUDED_haxor_graphics_material_Shader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Resource.h>
HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,Shader)
namespace haxor{
namespace graphics{
namespace material{


class HXCPP_CLASS_ATTRIBUTES  Shader_obj : public ::haxor::core::Resource_obj{
	public:
		typedef ::haxor::core::Resource_obj super;
		typedef Shader_obj OBJ_;
		Shader_obj();
		Void __construct(::String p_source);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Shader_obj > __new(::String p_source);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Shader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Shader"); }

		::String m_vss;
		::String m_fss;
		virtual bool get_hasError( );
		Dynamic get_hasError_dyn();

		bool m_hasError;
		virtual ::String GetShaderSource( ::Xml n);
		Dynamic GetShaderSource_dyn();

		virtual Void OnDestroy( );

};

} // end namespace haxor
} // end namespace graphics
} // end namespace material

#endif /* INCLUDED_haxor_graphics_material_Shader */ 
