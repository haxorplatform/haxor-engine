#ifndef INCLUDED_haxor_io_file_ColladaImage
#define INCLUDED_haxor_io_file_ColladaImage

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,texture,Bitmap)
HX_DECLARE_CLASS3(haxor,io,file,ColladaImage)
namespace haxor{
namespace io{
namespace file{


class HXCPP_CLASS_ATTRIBUTES  ColladaImage_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ColladaImage_obj OBJ_;
		ColladaImage_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ColladaImage_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ColladaImage_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ColladaImage"); }

		::String id;
		::String name;
		::String format;
		::String source;
		int width;
		int height;
		int depth;
		::haxor::graphics::texture::Bitmap data;
};

} // end namespace haxor
} // end namespace io
} // end namespace file

#endif /* INCLUDED_haxor_io_file_ColladaImage */ 
