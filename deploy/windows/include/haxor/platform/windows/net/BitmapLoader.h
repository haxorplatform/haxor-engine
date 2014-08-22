#ifndef INCLUDED_haxor_platform_windows_net_BitmapLoader
#define INCLUDED_haxor_platform_windows_net_BitmapLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/platform/windows/net/HTTPLoader.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IRenderable)
HX_DECLARE_CLASS2(haxor,core,IUpdateable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,texture,Bitmap)
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS2(haxor,net,HTTPRequestTask)
HX_DECLARE_CLASS4(haxor,platform,windows,net,BitmapLoader)
HX_DECLARE_CLASS4(haxor,platform,windows,net,HTTPLoader)
HX_DECLARE_CLASS4(haxor,platform,windows,net,HTTPRequest)
HX_DECLARE_CLASS2(haxor,thread,Activity)
HX_DECLARE_CLASS2(haxor,thread,Task)


#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STBI_NO_HDR
#include "stb/stb_image.h"                              // Header File For STB Image lib.
#endif


namespace haxor{
namespace platform{
namespace windows{
namespace net{


class HXCPP_CLASS_ATTRIBUTES  BitmapLoader_obj : public ::haxor::platform::windows::net::HTTPLoader_obj{
	public:
		typedef ::haxor::platform::windows::net::HTTPLoader_obj super;
		typedef BitmapLoader_obj OBJ_;
		BitmapLoader_obj();
		Void __construct(::String p_url,Dynamic p_callback);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BitmapLoader_obj > __new(::String p_url,Dynamic p_callback);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BitmapLoader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BitmapLoader"); }

		Dynamic m_bitmap_callback;
		Dynamic &m_bitmap_callback_dyn() { return m_bitmap_callback;}
		virtual Void OnBufferCallback( ::haxor::io::Buffer p_data,Float p_progress);
		Dynamic OnBufferCallback_dyn();

		virtual Void OnError( );

};

} // end namespace haxor
} // end namespace platform
} // end namespace windows
} // end namespace net

#endif /* INCLUDED_haxor_platform_windows_net_BitmapLoader */ 
