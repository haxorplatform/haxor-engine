#ifndef INCLUDED_haxor_graphics_Graphics
#define INCLUDED_haxor_graphics_Graphics

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Camera)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,component,Transform)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IResizeable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,graphics,Graphics)
HX_DECLARE_CLASS3(haxor,graphics,material,Material)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS2(haxor,math,AABB2)
HX_DECLARE_CLASS2(haxor,math,Color)
namespace haxor{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  Graphics_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Graphics_obj OBJ_;
		Graphics_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Graphics_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Graphics_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Graphics"); }

		static ::haxor::math::AABB2 m_last_viewport;
		static Void Viewport( ::haxor::math::AABB2 p_viewport);
		static Dynamic Viewport_dyn();

		static Void Clear( ::haxor::component::Camera p_camera);
		static Dynamic Clear_dyn();

		static Void Render( ::haxor::graphics::mesh::Mesh p_mesh,::haxor::graphics::material::Material p_material,::haxor::component::Transform p_transform,::haxor::component::Camera p_camera);
		static Dynamic Render_dyn();

		static Void DrawTexture( ::haxor::graphics::texture::Texture p_texture,hx::Null< Float >  p_x,hx::Null< Float >  p_y,hx::Null< Float >  p_width,hx::Null< Float >  p_height,::haxor::math::Color p_color);
		static Dynamic DrawTexture_dyn();

		static Void ReadPixels( int p_x,int p_y,int p_width,int p_height,::haxor::io::Buffer p_buffer);
		static Dynamic ReadPixels_dyn();

};

} // end namespace haxor
} // end namespace graphics

#endif /* INCLUDED_haxor_graphics_Graphics */ 
