#ifndef INCLUDED_haxor_graphics_material_MaterialUniform
#define INCLUDED_haxor_graphics_material_MaterialUniform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,MaterialUniform)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS2(haxor,io,Buffer)
namespace haxor{
namespace graphics{
namespace material{


class HXCPP_CLASS_ATTRIBUTES  MaterialUniform_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MaterialUniform_obj OBJ_;
		MaterialUniform_obj();
		Void __construct(::String p_name,bool p_is_float,int p_length,int p_offset);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MaterialUniform_obj > __new(::String p_name,bool p_is_float,int p_length,int p_offset);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MaterialUniform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MaterialUniform"); }

		int __cid;
		bool __d;
		::String name;
		::haxor::io::Buffer data;
		int offset;
		::haxor::graphics::texture::Texture texture;
		bool isFloat;
};

} // end namespace haxor
} // end namespace graphics
} // end namespace material

#endif /* INCLUDED_haxor_graphics_material_MaterialUniform */ 
