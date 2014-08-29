#ifndef INCLUDED_haxor_io_Int32Array
#define INCLUDED_haxor_io_Int32Array

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/io/Buffer.h>
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS2(haxor,io,Int32Array)
namespace haxor{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  Int32Array_obj : public ::haxor::io::Buffer_obj{
	public:
		typedef ::haxor::io::Buffer_obj super;
		typedef Int32Array_obj OBJ_;
		Int32Array_obj();
		Void __construct(int p_length);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Int32Array_obj > __new(int p_length);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Int32Array_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Int32Array"); }

		virtual int get_bytesPerElement( );

		virtual Void Resize( int p_length);

		virtual int Get( int p_index);
		Dynamic Get_dyn();

		virtual Void Set( int p_index,int p_value);
		Dynamic Set_dyn();

		virtual Void SetRange( Array< int > p_data,hx::Null< int >  p_offset);
		Dynamic SetRange_dyn();

		virtual Void SetViewSlice( int p_start,int p_length);

		static ::haxor::io::Int32Array Alloc( Array< int > p_data);
		static Dynamic Alloc_dyn();

		static ::haxor::io::Int32Array Parse( ::String p_data,::String p_delimiter);
		static Dynamic Parse_dyn();

};

} // end namespace haxor
} // end namespace io

#endif /* INCLUDED_haxor_io_Int32Array */ 
