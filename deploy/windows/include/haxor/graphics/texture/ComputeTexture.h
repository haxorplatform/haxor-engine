#ifndef INCLUDED_haxor_graphics_texture_ComputeTexture
#define INCLUDED_haxor_graphics_texture_ComputeTexture

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/graphics/texture/Texture2D.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,PixelFormat)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,core,TextureType)
HX_DECLARE_CLASS3(haxor,graphics,texture,ComputeTexture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture2D)
namespace haxor{
namespace graphics{
namespace texture{


class HXCPP_CLASS_ATTRIBUTES  ComputeTexture_obj : public ::haxor::graphics::texture::Texture2D_obj{
	public:
		typedef ::haxor::graphics::texture::Texture2D_obj super;
		typedef ComputeTexture_obj OBJ_;
		ComputeTexture_obj();
		Void __construct(int p_width,int p_height,::haxor::core::PixelFormat p_format);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ComputeTexture_obj > __new(int p_width,int p_height,::haxor::core::PixelFormat p_format);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ComputeTexture_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("ComputeTexture"); }

		bool m_lock;
		bool m_dirty;
		virtual ::haxor::core::TextureType get_type( );

		virtual Void Write( int p_x,int p_y,Dynamic p_v0,Dynamic p_v1,Dynamic p_v2,Dynamic p_v3);
		Dynamic Write_dyn();

		virtual Void WriteRange( Array< Float > p_values,hx::Null< int >  p_x,hx::Null< int >  p_y,hx::Null< int >  p_width,hx::Null< int >  p_height);
		Dynamic WriteRange_dyn();

		virtual Void Invalidate( );
		Dynamic Invalidate_dyn();

		virtual Void OnUploadComplete( );
		Dynamic OnUploadComplete_dyn();

};

} // end namespace haxor
} // end namespace graphics
} // end namespace texture

#endif /* INCLUDED_haxor_graphics_texture_ComputeTexture */ 
