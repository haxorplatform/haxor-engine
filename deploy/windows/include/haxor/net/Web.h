#ifndef INCLUDED_haxor_net_Web
#define INCLUDED_haxor_net_Web

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,Shader)
HX_DECLARE_CLASS3(haxor,graphics,texture,Bitmap)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture)
HX_DECLARE_CLASS3(haxor,graphics,texture,Texture2D)
HX_DECLARE_CLASS3(haxor,io,file,AssetFile)
HX_DECLARE_CLASS3(haxor,io,file,AssetXML)
HX_DECLARE_CLASS3(haxor,io,file,ColladaFile)
HX_DECLARE_CLASS2(haxor,net,Web)
namespace haxor{
namespace net{


class HXCPP_CLASS_ATTRIBUTES  Web_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Web_obj OBJ_;
		Web_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Web_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Web_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Web"); }

		static ::String root;
		static Void Load( ::String p_url,Dynamic p_callback);
		static Dynamic Load_dyn();

		static Void LoadImg( ::String p_url,Dynamic p_callback);
		static Dynamic LoadImg_dyn();

		static Void LoadTexture2D( ::String p_url,bool p_apply,Dynamic p_callback);
		static Dynamic LoadTexture2D_dyn();

		static Void LoadCollada( ::String p_url,Dynamic p_callback);
		static Dynamic LoadCollada_dyn();

		static Void LoadShader( ::String p_url,Dynamic p_callback);
		static Dynamic LoadShader_dyn();

};

} // end namespace haxor
} // end namespace net

#endif /* INCLUDED_haxor_net_Web */ 
