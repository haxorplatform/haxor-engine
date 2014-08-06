#ifndef INCLUDED_haxor_io_UInt16Array
#define INCLUDED_haxor_io_UInt16Array

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/io/BaseArray.h>
HX_DECLARE_CLASS2(haxor,io,BaseArray)
HX_DECLARE_CLASS2(haxor,io,UInt16Array)
namespace haxor{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  UInt16Array_obj : public ::haxor::io::BaseArray_obj{
	public:
		typedef ::haxor::io::BaseArray_obj super;
		typedef UInt16Array_obj OBJ_;
		UInt16Array_obj();
		Void __construct(int p_capacity);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< UInt16Array_obj > __new(int p_capacity);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~UInt16Array_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("UInt16Array"); }

		typedef int __array_access;
		virtual int get_length( );

		int m_length;
		virtual ::String get_type( );

		::cpp::Pointer< int > b;
		virtual ::haxor::io::UInt16Array Clone( );
		Dynamic Clone_dyn();

		virtual Void Set( Array< int > p_data);
		Dynamic Set_dyn();

		virtual int array_get( int k);
		Dynamic array_get_dyn();

		virtual int array_set( int k,int v);
		Dynamic array_set_dyn();

		static ::haxor::io::UInt16Array Create( Array< int > p_data);
		static Dynamic Create_dyn();

};

} // end namespace haxor
} // end namespace io

#endif /* INCLUDED_haxor_io_UInt16Array */ 
