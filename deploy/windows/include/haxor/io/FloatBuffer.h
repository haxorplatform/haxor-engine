#ifndef INCLUDED_haxor_io_FloatBuffer
#define INCLUDED_haxor_io_FloatBuffer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/io/Buffer.h>
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS2(haxor,io,FloatBuffer)
namespace haxor{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  FloatBuffer_obj : public ::haxor::io::Buffer_obj{
	public:
		typedef ::haxor::io::Buffer_obj super;
		typedef FloatBuffer_obj OBJ_;
		FloatBuffer_obj();
		Void __construct(int p_length);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FloatBuffer_obj > __new(int p_length);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FloatBuffer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("FloatBuffer"); }

		virtual int get_bytesPerElement( );

		virtual Float Get( int p_index);
		Dynamic Get_dyn();

		virtual Void Set( int p_index,Float p_value);
		Dynamic Set_dyn();

		virtual Void SetRange( Array< Float > p_data,hx::Null< int >  p_offset);
		Dynamic SetRange_dyn();

		static ::haxor::io::FloatBuffer Alloc( Array< Float > p_data);
		static Dynamic Alloc_dyn();

};

} // end namespace haxor
} // end namespace io

#endif /* INCLUDED_haxor_io_FloatBuffer */ 
