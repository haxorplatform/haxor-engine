#ifndef INCLUDED_haxor_graphics_texture_TextureCube
#define INCLUDED_haxor_graphics_texture_TextureCube

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/graphics/texture/Texture.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture2D)
HX_DECLARE_CLASS3(haxor,graphics,texture,TextureCube)
namespace haxor{
namespace graphics{
namespace texture{


class HXCPP_CLASS_ATTRIBUTES  TextureCube_obj : public ::haxor::graphics::texture::Texture_obj{
	public:
		typedef ::haxor::graphics::texture::Texture_obj super;
		typedef TextureCube_obj OBJ_;
		TextureCube_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TextureCube_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TextureCube_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TextureCube"); }

		virtual ::haxor::graphics::texture::Texture get_px( );
		Dynamic get_px_dyn();

		virtual ::haxor::graphics::texture::Texture set_px( ::haxor::graphics::texture::Texture v);
		Dynamic set_px_dyn();

		::haxor::graphics::texture::Texture p_px;
		virtual ::haxor::graphics::texture::Texture get_nx( );
		Dynamic get_nx_dyn();

		virtual ::haxor::graphics::texture::Texture set_nx( ::haxor::graphics::texture::Texture v);
		Dynamic set_nx_dyn();

		::haxor::graphics::texture::Texture p_nx;
		virtual ::haxor::graphics::texture::Texture get_py( );
		Dynamic get_py_dyn();

		virtual ::haxor::graphics::texture::Texture set_py( ::haxor::graphics::texture::Texture v);
		Dynamic set_py_dyn();

		::haxor::graphics::texture::Texture p_py;
		virtual ::haxor::graphics::texture::Texture get_ny( );
		Dynamic get_ny_dyn();

		virtual ::haxor::graphics::texture::Texture set_ny( ::haxor::graphics::texture::Texture v);
		Dynamic set_ny_dyn();

		::haxor::graphics::texture::Texture p_ny;
		virtual ::haxor::graphics::texture::Texture get_pz( );
		Dynamic get_pz_dyn();

		virtual ::haxor::graphics::texture::Texture set_pz( ::haxor::graphics::texture::Texture v);
		Dynamic set_pz_dyn();

		::haxor::graphics::texture::Texture p_pz;
		virtual ::haxor::graphics::texture::Texture get_nz( );
		Dynamic get_nz_dyn();

		virtual ::haxor::graphics::texture::Texture set_nz( ::haxor::graphics::texture::Texture v);
		Dynamic set_nz_dyn();

		::haxor::graphics::texture::Texture p_nz;
		Array< ::Dynamic > m_faces;
		bool m_is_cross;
		virtual Void OnDestroy( );

		virtual Void InvalidateCross( );
		Dynamic InvalidateCross_dyn();

		static ::haxor::graphics::texture::TextureCube FromCrossTexture( ::haxor::graphics::texture::Texture2D p_texture);
		static Dynamic FromCrossTexture_dyn();

};

} // end namespace haxor
} // end namespace graphics
} // end namespace texture

#endif /* INCLUDED_haxor_graphics_texture_TextureCube */ 
