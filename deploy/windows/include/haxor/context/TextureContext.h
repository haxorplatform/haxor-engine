#ifndef INCLUDED_haxor_context_TextureContext
#define INCLUDED_haxor_context_TextureContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,context,TextureContext)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,graphics,PixelFormat)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  TextureContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TextureContext_obj OBJ_;
		TextureContext_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TextureContext_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TextureContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("TextureContext"); }

		int tid;
		virtual Void Initialize( );
		Dynamic Initialize_dyn();

		virtual Void Create( ::haxor::graphics::texture::Texture p_texture);
		Dynamic Create_dyn();

		virtual Void UpdateParameters( ::haxor::graphics::texture::Texture p_texture);
		Dynamic UpdateParameters_dyn();

		virtual Void Update( ::haxor::graphics::texture::Texture p_texture);
		Dynamic Update_dyn();

		virtual Void UpdateMipmaps( ::haxor::graphics::texture::Texture p_texture);
		Dynamic UpdateMipmaps_dyn();

		virtual Void Destroy( ::haxor::graphics::texture::Texture p_texture);
		Dynamic Destroy_dyn();

		static int FormatToChannelBits( ::haxor::graphics::PixelFormat p_format);
		static Dynamic FormatToChannelBits_dyn();

		static int FormatToChannelType( ::haxor::graphics::PixelFormat p_format);
		static Dynamic FormatToChannelType_dyn();

		static int FormatToChannelLayout( ::haxor::graphics::PixelFormat p_format);
		static Dynamic FormatToChannelLayout_dyn();

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_TextureContext */ 
