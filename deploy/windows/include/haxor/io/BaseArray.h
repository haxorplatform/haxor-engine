#ifndef INCLUDED_haxor_io_BaseArray
#define INCLUDED_haxor_io_BaseArray

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,io,BaseArray)
namespace haxor{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  BaseArray_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BaseArray_obj OBJ_;
		BaseArray_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< BaseArray_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~BaseArray_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BaseArray"); }

		virtual int get_length( );
		Dynamic get_length_dyn();

		virtual int get_byteLength( );
		Dynamic get_byteLength_dyn();

		Dynamic m_buffer;
		virtual int get_type( );
		Dynamic get_type_dyn();

};

} // end namespace haxor
} // end namespace io

#endif /* INCLUDED_haxor_io_BaseArray */ 
