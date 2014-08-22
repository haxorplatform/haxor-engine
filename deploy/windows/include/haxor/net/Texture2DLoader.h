#ifndef INCLUDED_haxor_net_Texture2DLoader
#define INCLUDED_haxor_net_Texture2DLoader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/platform/windows/net/BitmapLoader.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,IRenderable)
HX_DECLARE_CLASS2(haxor,core,IUpdateable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,texture,Bitmap)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture2D)
HX_DECLARE_CLASS2(haxor,net,HTTPRequestTask)
HX_DECLARE_CLASS2(haxor,net,Texture2DLoader)
HX_DECLARE_CLASS4(haxor,platform,windows,net,BitmapLoader)
HX_DECLARE_CLASS4(haxor,platform,windows,net,HTTPLoader)
HX_DECLARE_CLASS4(haxor,platform,windows,net,HTTPRequest)
HX_DECLARE_CLASS2(haxor,thread,Activity)
HX_DECLARE_CLASS2(haxor,thread,Task)
namespace haxor{
namespace net{


class HXCPP_CLASS_ATTRIBUTES  Texture2DLoader_obj : public ::haxor::platform::windows::net::BitmapLoader_obj{
	public:
		typedef ::haxor::platform::windows::net::BitmapLoader_obj super;
		typedef Texture2DLoader_obj OBJ_;
		Texture2DLoader_obj();
		Void __construct(::String p_url,bool p_apply,Dynamic p_callback);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Texture2DLoader_obj > __new(::String p_url,bool p_apply,Dynamic p_callback);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Texture2DLoader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Texture2DLoader"); }

		Dynamic m_t2d_callback;
		Dynamic &m_t2d_callback_dyn() { return m_t2d_callback;}
		bool m_apply;
		virtual Void OnBitmapCallback( ::haxor::graphics::texture::Bitmap p_data,Float p_progress);
		Dynamic OnBitmapCallback_dyn();

		virtual Void OnError( );

};

} // end namespace haxor
} // end namespace net

#endif /* INCLUDED_haxor_net_Texture2DLoader */ 
