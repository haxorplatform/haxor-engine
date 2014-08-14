#ifndef INCLUDED_haxor_io_UInt16Array
#define INCLUDED_haxor_io_UInt16Array

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/io/Buffer.h>
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS2(haxor,io,UInt16Array)
namespace haxor{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  UInt16Array_obj : public ::haxor::io::Buffer_obj{
	public:
		typedef ::haxor::io::Buffer_obj super;
		typedef UInt16Array_obj OBJ_;
		UInt16Array_obj();
		Void __construct(int p_length);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< UInt16Array_obj > __new(int p_length);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~UInt16Array_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("UInt16Array"); }

		virtual int get_bytesPerElement( );

		virtual int Get( int p_index);
		Dynamic Get_dyn();

		virtual Void Set( int p_index,int p_value);
		Dynamic Set_dyn();

		virtual Void SetRange( Array< int > p_data,hx::Null< int >  p_offset);
		Dynamic SetRange_dyn();

		static ::haxor::io::UInt16Array Alloc( Array< int > p_data);
		static Dynamic Alloc_dyn();

};

} // end namespace haxor
} // end namespace io

#endif /* INCLUDED_haxor_io_UInt16Array */ 
