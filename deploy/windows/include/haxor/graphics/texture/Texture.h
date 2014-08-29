#ifndef INCLUDED_haxor_graphics_texture_Texture
#define INCLUDED_haxor_graphics_texture_Texture

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Resource.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,PixelFormat)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,core,TextureFilter)
HX_DECLARE_CLASS2(haxor,core,TextureType)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
namespace haxor{
namespace graphics{
namespace texture{


class HXCPP_CLASS_ATTRIBUTES  Texture_obj : public ::haxor::core::Resource_obj{
	public:
		typedef ::haxor::core::Resource_obj super;
		typedef Texture_obj OBJ_;
		Texture_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Texture_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Texture_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Texture"); }

		virtual int get_width( );
		Dynamic get_width_dyn();

		int m_width;
		virtual int get_height( );
		Dynamic get_height_dyn();

		int m_height;
		virtual ::haxor::core::PixelFormat get_format( );
		Dynamic get_format_dyn();

		::haxor::core::PixelFormat m_format;
		virtual int get_wrap( );
		Dynamic get_wrap_dyn();

		virtual int set_wrap( int v);
		Dynamic set_wrap_dyn();

		int m_wrap;
		virtual int get_aniso( );
		Dynamic get_aniso_dyn();

		virtual int set_aniso( int v);
		Dynamic set_aniso_dyn();

		int m_aniso;
		virtual ::haxor::core::TextureFilter get_minFilter( );
		Dynamic get_minFilter_dyn();

		virtual ::haxor::core::TextureFilter set_minFilter( ::haxor::core::TextureFilter v);
		Dynamic set_minFilter_dyn();

		::haxor::core::TextureFilter m_minFilter;
		virtual ::haxor::core::TextureFilter get_magFilter( );
		Dynamic get_magFilter_dyn();

		virtual ::haxor::core::TextureFilter set_magFilter( ::haxor::core::TextureFilter v);
		Dynamic set_magFilter_dyn();

		::haxor::core::TextureFilter m_magFilter;
		bool mipmaps;
		virtual bool get_mipmaps( );
		Dynamic get_mipmaps_dyn();

		bool m_mipmaps;
		::haxor::core::TextureType type;
		virtual ::haxor::core::TextureType get_type( );
		Dynamic get_type_dyn();

		int __slot;
		virtual Void Apply( );
		Dynamic Apply_dyn();

		virtual Void GenerateMipmaps( );
		Dynamic GenerateMipmaps_dyn();

		virtual Void OnDestroy( );

};

} // end namespace haxor
} // end namespace graphics
} // end namespace texture

#endif /* INCLUDED_haxor_graphics_texture_Texture */ 
