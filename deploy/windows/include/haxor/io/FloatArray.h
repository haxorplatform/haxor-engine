#ifndef INCLUDED_haxor_io_FloatArray
#define INCLUDED_haxor_io_FloatArray

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/io/BaseArray.h>
HX_DECLARE_CLASS2(haxor,io,BaseArray)
HX_DECLARE_CLASS2(haxor,io,FloatArray)
namespace haxor{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  FloatArray_obj : public ::haxor::io::BaseArray_obj{
	public:
		typedef ::haxor::io::BaseArray_obj super;
		typedef FloatArray_obj OBJ_;
		FloatArray_obj();
		Void __construct(int p_capacity);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FloatArray_obj > __new(int p_capacity);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FloatArray_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FloatArray"); }

		virtual int get_length( );

		int m_length;
		virtual ::String get_type( );

		::cpp::Pointer< Float > b;
		virtual ::haxor::io::FloatArray Clone( );
		Dynamic Clone_dyn();

		virtual Void Fill( Array< Float > p_data);
		Dynamic Fill_dyn();

		virtual Float Get( int k);
		Dynamic Get_dyn();

		virtual Void Set( int k,Float v);
		Dynamic Set_dyn();

		static ::haxor::io::FloatArray Create( Array< Float > p_data);
		static Dynamic Create_dyn();

};

} // end namespace haxor
} // end namespace io

#endif /* INCLUDED_haxor_io_FloatArray */ 
