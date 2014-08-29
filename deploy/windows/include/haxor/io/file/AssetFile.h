#ifndef INCLUDED_haxor_io_file_AssetFile
#define INCLUDED_haxor_io_file_AssetFile

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/core/Resource.h>
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,io,file,AssetFile)
namespace haxor{
namespace io{
namespace file{


class HXCPP_CLASS_ATTRIBUTES  AssetFile_obj : public ::haxor::core::Resource_obj{
	public:
		typedef ::haxor::core::Resource_obj super;
		typedef AssetFile_obj OBJ_;
		AssetFile_obj();
		Void __construct(::String p_name);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AssetFile_obj > __new(::String p_name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AssetFile_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AssetFile"); }

		Dynamic asset;
		virtual Dynamic get_asset( );
		Dynamic get_asset_dyn();

		virtual Array< Float > stof32a( ::String v,::String sep);
		Dynamic stof32a_dyn();

		virtual Array< int > stoi16a( ::String v,::String sep);
		Dynamic stoi16a_dyn();

		virtual Array< ::Dynamic > stoi16ta( ::String v,int s,::String sep);
		Dynamic stoi16ta_dyn();

};

} // end namespace haxor
} // end namespace io
} // end namespace file

#endif /* INCLUDED_haxor_io_file_AssetFile */ 
