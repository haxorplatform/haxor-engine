#ifndef INCLUDED_haxor_io_file_MaterialFileUniform
#define INCLUDED_haxor_io_file_MaterialFileUniform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(haxor,io,file,MaterialFileUniform)
namespace haxor{
namespace io{
namespace file{


class HXCPP_CLASS_ATTRIBUTES  MaterialFileUniform_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MaterialFileUniform_obj OBJ_;
		MaterialFileUniform_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MaterialFileUniform_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MaterialFileUniform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MaterialFileUniform"); }

		::String type;
		::String name;
		::String value;
};

} // end namespace haxor
} // end namespace io
} // end namespace file

#endif /* INCLUDED_haxor_io_file_MaterialFileUniform */ 
