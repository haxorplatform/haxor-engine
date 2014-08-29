#ifndef INCLUDED_haxor_io_file_ColladaMesh
#define INCLUDED_haxor_io_file_ColladaMesh

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(haxor,io,file,ColladaMesh)
HX_DECLARE_CLASS3(haxor,io,file,ColladaPrimitive)
namespace haxor{
namespace io{
namespace file{


class HXCPP_CLASS_ATTRIBUTES  ColladaMesh_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ColladaMesh_obj OBJ_;
		ColladaMesh_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ColladaMesh_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ColladaMesh_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ColladaMesh"); }

		::String type;
		Array< ::Dynamic > primitives;
};

} // end namespace haxor
} // end namespace io
} // end namespace file

#endif /* INCLUDED_haxor_io_file_ColladaMesh */ 
