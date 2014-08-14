#ifndef INCLUDED_haxor_graphics_material_UberShader
#define INCLUDED_haxor_graphics_material_UberShader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/graphics/material/Shader.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,Shader)
HX_DECLARE_CLASS3(haxor,graphics,material,UberShader)
namespace haxor{
namespace graphics{
namespace material{


class HXCPP_CLASS_ATTRIBUTES  UberShader_obj : public ::haxor::graphics::material::Shader_obj{
	public:
		typedef ::haxor::graphics::material::Shader_obj super;
		typedef UberShader_obj OBJ_;
		UberShader_obj();
		Void __construct(::String p_source);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< UberShader_obj > __new(::String p_source);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~UberShader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("UberShader"); }

};

} // end namespace haxor
} // end namespace graphics
} // end namespace material

#endif /* INCLUDED_haxor_graphics_material_UberShader */ 
