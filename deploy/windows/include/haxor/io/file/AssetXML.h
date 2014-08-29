#ifndef INCLUDED_haxor_io_file_AssetXML
#define INCLUDED_haxor_io_file_AssetXML

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/io/file/AssetFile.h>
HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,io,file,AssetFile)
HX_DECLARE_CLASS3(haxor,io,file,AssetXML)
namespace haxor{
namespace io{
namespace file{


class HXCPP_CLASS_ATTRIBUTES  AssetXML_obj : public ::haxor::io::file::AssetFile_obj{
	public:
		typedef ::haxor::io::file::AssetFile_obj super;
		typedef AssetXML_obj OBJ_;
		AssetXML_obj();
		Void __construct(::String p_name,::String p_src);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AssetXML_obj > __new(::String p_name,::String p_src);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AssetXML_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AssetXML"); }

		::Xml x;
		virtual Void Parse( ::Xml n);
		Dynamic Parse_dyn();

		virtual Void TraverseStep( ::Xml n);
		Dynamic TraverseStep_dyn();

		virtual ::String _a( ::Xml n,::String a,Dynamic v);
		Dynamic _a_dyn();

		virtual ::String _tla( ::Xml n,::String a,Dynamic v);
		Dynamic _tla_dyn();

		virtual Dynamic _p( ::Xml n,::String p,Dynamic v,hx::Null< bool >  t,hx::Null< bool >  tl);
		Dynamic _p_dyn();

		virtual ::Xml _f( ::Xml n,::String p,::String a,::String t);
		Dynamic _f_dyn();

};

} // end namespace haxor
} // end namespace io
} // end namespace file

#endif /* INCLUDED_haxor_io_file_AssetXML */ 
