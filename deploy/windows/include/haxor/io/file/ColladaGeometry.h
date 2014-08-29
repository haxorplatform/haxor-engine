#ifndef INCLUDED_haxor_io_file_ColladaGeometry
#define INCLUDED_haxor_io_file_ColladaGeometry

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(haxor,io,file,ColladaGeometry)
HX_DECLARE_CLASS3(haxor,io,file,ColladaMesh)
namespace haxor{
namespace io{
namespace file{


class HXCPP_CLASS_ATTRIBUTES  ColladaGeometry_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ColladaGeometry_obj OBJ_;
		ColladaGeometry_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ColladaGeometry_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ColladaGeometry_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ColladaGeometry"); }

		::String id;
		::String name;
		::haxor::io::file::ColladaMesh mesh;
};

} // end namespace haxor
} // end namespace io
} // end namespace file

#endif /* INCLUDED_haxor_io_file_ColladaGeometry */ 
