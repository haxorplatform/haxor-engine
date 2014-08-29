#ifndef INCLUDED_haxor_io_file_ColladaInput
#define INCLUDED_haxor_io_file_ColladaInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(haxor,io,file,ColladaInput)
namespace haxor{
namespace io{
namespace file{


class HXCPP_CLASS_ATTRIBUTES  ColladaInput_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ColladaInput_obj OBJ_;
		ColladaInput_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ColladaInput_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ColladaInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ColladaInput"); }

		::String semantic;
		int offset;
		int set;
		Dynamic values;
		int stride;
		virtual Dynamic GetVectorArray( );
		Dynamic GetVectorArray_dyn();

};

} // end namespace haxor
} // end namespace io
} // end namespace file

#endif /* INCLUDED_haxor_io_file_ColladaInput */ 
