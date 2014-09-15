#ifndef INCLUDED_haxor_context_TextureContext
#define INCLUDED_haxor_context_TextureContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,context,TextureContext)
HX_DECLARE_CLASS2(haxor,context,UID)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,PixelFormat)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,texture,RenderTexture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture2D)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  TextureContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TextureContext_obj OBJ_;
		TextureContext_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TextureContext_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TextureContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TextureContext"); }

		::haxor::context::UID tid;
		Array< int > ids;
		Array< int > framebuffers;
		Array< int > renderbuffers;
		::haxor::graphics::texture::RenderTexture target;
		Array< ::Dynamic > bind;
		int active;
		int next_slot;
		bool is_flip_y;
		virtual Void Initialize( );
		Dynamic Initialize_dyn();

		virtual Void Alloc( ::haxor::graphics::texture::Texture p_texture);
		Dynamic Alloc_dyn();

		virtual Void Create( ::haxor::graphics::texture::Texture p_texture);
		Dynamic Create_dyn();

		virtual Void Bind( ::haxor::graphics::texture::Texture p_texture);
		Dynamic Bind_dyn();

		virtual Void Unbind( );
		Dynamic Unbind_dyn();

		virtual Void UpdateParameters( ::haxor::graphics::texture::Texture p_texture);
		Dynamic UpdateParameters_dyn();

		virtual Void Update( ::haxor::graphics::texture::Texture p_texture);
		Dynamic Update_dyn();

		virtual Void UploadTexture( ::haxor::graphics::texture::Texture2D p_texture,int p_x,int p_y,int p_width,int p_height,int p_steps,Dynamic p_on_complete);
		Dynamic UploadTexture_dyn();

		virtual Void WriteTexture( int p_target,::haxor::graphics::texture::Texture p_texture);
		Dynamic WriteTexture_dyn();

		virtual Void BindTarget( ::haxor::graphics::texture::RenderTexture rt);
		Dynamic BindTarget_dyn();

		virtual Void UpdateMipmaps( ::haxor::graphics::texture::Texture p_texture);
		Dynamic UpdateMipmaps_dyn();

		virtual Void Destroy( ::haxor::graphics::texture::Texture p_texture);
		Dynamic Destroy_dyn();

		static int TextureToTarget( ::haxor::graphics::texture::Texture p_texture);
		static Dynamic TextureToTarget_dyn();

		static int FormatToChannelBits( ::haxor::core::PixelFormat p_format);
		static Dynamic FormatToChannelBits_dyn();

		static int FormatToChannelType( ::haxor::core::PixelFormat p_format);
		static Dynamic FormatToChannelType_dyn();

		static int FormatToChannelLayout( ::haxor::core::PixelFormat p_format);
		static Dynamic FormatToChannelLayout_dyn();

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_TextureContext */ 
