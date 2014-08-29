#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#define INCLUDED_haxor_graphics_texture_Bitmap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Resource.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,PixelFormat)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,texture,Bitmap)
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS2(haxor,math,Color)
namespace haxor{
namespace graphics{
namespace texture{


class HXCPP_CLASS_ATTRIBUTES  Bitmap_obj : public ::haxor::core::Resource_obj{
	public:
		typedef ::haxor::core::Resource_obj super;
		typedef Bitmap_obj OBJ_;
		Bitmap_obj();
		Void __construct(int p_width,int p_height,::haxor::core::PixelFormat p_format);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Bitmap_obj > __new(int p_width,int p_height,::haxor::core::PixelFormat p_format);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Bitmap_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Bitmap"); }

		::haxor::io::Buffer buffer;
		virtual ::haxor::io::Buffer get_buffer( );
		Dynamic get_buffer_dyn();

		::haxor::io::Buffer m_buffer;
		bool _float;
		virtual bool get_float( );
		Dynamic get_float_dyn();

		bool m_float;
		int width;
		virtual int get_width( );
		Dynamic get_width_dyn();

		int m_width;
		int height;
		virtual int get_height( );
		Dynamic get_height_dyn();

		int m_height;
		int channels;
		virtual int get_channels( );
		Dynamic get_channels_dyn();

		int m_channels;
		::haxor::core::PixelFormat format;
		virtual ::haxor::core::PixelFormat get_format( );
		Dynamic get_format_dyn();

		::haxor::core::PixelFormat m_format;
		virtual ::haxor::math::Color GetPixel( int p_x,int p_y);
		Dynamic GetPixel_dyn();

		virtual Void SetPixel( int p_x,int p_y,::haxor::math::Color p_color);
		Dynamic SetPixel_dyn();

		virtual Void Fill( ::haxor::math::Color p_color);
		Dynamic Fill_dyn();

		virtual Void Set( int p_x,int p_y,hx::Null< Float >  p_v0,hx::Null< Float >  p_v1,hx::Null< Float >  p_v2,hx::Null< Float >  p_v3);
		Dynamic Set_dyn();

		virtual Void SetRange( int p_x,int p_y,int p_width,int p_height,Array< Float > p_values,hx::Null< int >  p_length);
		Dynamic SetRange_dyn();

};

} // end namespace haxor
} // end namespace graphics
} // end namespace texture

#endif /* INCLUDED_haxor_graphics_texture_Bitmap */ 
