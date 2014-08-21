#ifndef INCLUDED_haxor_graphics_texture_Texture2D
#define INCLUDED_haxor_graphics_texture_Texture2D

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/graphics/texture/Texture.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,graphics,PixelFormat)
HX_DECLARE_CLASS2(haxor,graphics,TextureType)
HX_DECLARE_CLASS3(haxor,graphics,texture,Bitmap)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture2D)
namespace haxor{
namespace graphics{
namespace texture{


class HXCPP_CLASS_ATTRIBUTES  Texture2D_obj : public ::haxor::graphics::texture::Texture_obj{
	public:
		typedef ::haxor::graphics::texture::Texture_obj super;
		typedef Texture2D_obj OBJ_;
		Texture2D_obj();
		Void __construct(int p_width,int p_height,::haxor::graphics::PixelFormat p_format);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Texture2D_obj > __new(int p_width,int p_height,::haxor::graphics::PixelFormat p_format);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Texture2D_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Texture2D"); }

		::haxor::graphics::texture::Bitmap data;
		virtual ::haxor::graphics::texture::Bitmap get_data( );
		Dynamic get_data_dyn();

		::haxor::graphics::texture::Bitmap m_data;
		virtual ::haxor::graphics::TextureType get_type( );

		virtual Void Upload( hx::Null< int >  p_steps,Dynamic p_on_complete);
		Dynamic Upload_dyn();

		static ::haxor::graphics::texture::Texture2D get_white( );
		static Dynamic get_white_dyn();

		static ::haxor::graphics::texture::Texture2D m_white;
		static ::haxor::graphics::texture::Texture2D get_red( );
		static Dynamic get_red_dyn();

		static ::haxor::graphics::texture::Texture2D m_red;
		static ::haxor::graphics::texture::Texture2D FromBitmap( ::haxor::graphics::texture::Bitmap p_bitmap,hx::Null< bool >  p_apply);
		static Dynamic FromBitmap_dyn();

};

} // end namespace haxor
} // end namespace graphics
} // end namespace texture

#endif /* INCLUDED_haxor_graphics_texture_Texture2D */ 
