#ifndef INCLUDED_haxor_core_Asset
#define INCLUDED_haxor_core_Asset

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS2(haxor,core,Asset)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
namespace haxor{
namespace core{


class HXCPP_CLASS_ATTRIBUTES  Asset_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Asset_obj OBJ_;
		Asset_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Asset_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Asset_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Asset"); }

		static ::haxe::ds::StringMap m_database;
		static ::haxe::ds::StringMap m_load_progress;
		static Float get_progress( );
		static Dynamic get_progress_dyn();

		static Dynamic Get( ::String p_id);
		static Dynamic Get_dyn();

		static Dynamic Remove( ::String p_id);
		static Dynamic Remove_dyn();

		static Void Add( ::String p_id,Dynamic p_asset);
		static Dynamic Add_dyn();

		static Void LoadTexture2D( ::String p_id,::String p_url);
		static Dynamic LoadTexture2D_dyn();

		static Void LoadCollada( ::String p_id,::String p_url);
		static Dynamic LoadCollada_dyn();

		static Void LoadShader( ::String p_id,::String p_url);
		static Dynamic LoadShader_dyn();

		static Void LoadMaterial( ::String p_id,::String p_url);
		static Dynamic LoadMaterial_dyn();

		static Dynamic Instantiate( ::haxor::core::Resource p_target);
		static Dynamic Instantiate_dyn();

		static Void UpdateProgress( ::String p_id,Float p_progress,Dynamic p_asset);
		static Dynamic UpdateProgress_dyn();

};

} // end namespace haxor
} // end namespace core

#endif /* INCLUDED_haxor_core_Asset */ 
