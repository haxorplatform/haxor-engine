#ifndef INCLUDED_haxor_io_file_Asset
#define INCLUDED_haxor_io_file_Asset

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS3(haxor,io,file,Asset)
namespace haxor{
namespace io{
namespace file{


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
		static Dynamic Get( ::String p_id);
		static Dynamic Get_dyn();

		static Dynamic Remove( ::String p_id);
		static Dynamic Remove_dyn();

		static Void Add( ::String p_id,Dynamic p_asset);
		static Dynamic Add_dyn();

};

} // end namespace haxor
} // end namespace io
} // end namespace file

#endif /* INCLUDED_haxor_io_file_Asset */ 
