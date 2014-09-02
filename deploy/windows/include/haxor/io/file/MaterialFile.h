#ifndef INCLUDED_haxor_io_file_MaterialFile
#define INCLUDED_haxor_io_file_MaterialFile

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/io/file/AssetXML.h>
HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,io,file,AssetFile)
HX_DECLARE_CLASS3(haxor,io,file,AssetXML)
HX_DECLARE_CLASS3(haxor,io,file,MaterialFile)
HX_DECLARE_CLASS3(haxor,io,file,MaterialFileUniform)
namespace haxor{
namespace io{
namespace file{


class HXCPP_CLASS_ATTRIBUTES  MaterialFile_obj : public ::haxor::io::file::AssetXML_obj{
	public:
		typedef ::haxor::io::file::AssetXML_obj super;
		typedef MaterialFile_obj OBJ_;
		MaterialFile_obj();
		Void __construct(::String p_src);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MaterialFile_obj > __new(::String p_src);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MaterialFile_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MaterialFile"); }

		::String mguid;
		::String mname;
		::String queue;
		::String shader;
		int offset;
		bool ztest;
		::String zfunc;
		bool zwrite;
		bool blend;
		::String blendSrc;
		::String blendDst;
		bool invert;
		bool lighting;
		bool grab;
		::String cull;
		Array< ::Dynamic > uniforms;
		virtual Dynamic get_asset( );

		virtual Void Parse( ::Xml n);

		virtual Void ParseUniforms( ::Xml n);
		Dynamic ParseUniforms_dyn();

		virtual int BlendModeNameToEnum( ::String b);
		Dynamic BlendModeNameToEnum_dyn();

};

} // end namespace haxor
} // end namespace io
} // end namespace file

#endif /* INCLUDED_haxor_io_file_MaterialFile */ 
