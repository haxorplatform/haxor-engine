#ifndef INCLUDED_haxor_io_Buffer
#define INCLUDED_haxor_io_Buffer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxor,io,Buffer)
namespace haxor{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  Buffer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Buffer_obj OBJ_;
		Buffer_obj();
		Void __construct(int p_length);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Buffer_obj > __new(int p_length);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Buffer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Buffer"); }

		::haxe::io::Bytes buffer;
		virtual ::haxe::io::Bytes get_buffer( );
		Dynamic get_buffer_dyn();

		::haxe::io::Bytes m_buffer;
		::haxe::io::Bytes m_original;
		int m_offset;
		int byteLength;
		virtual int get_byteLength( );
		Dynamic get_byteLength_dyn();

		int bytesPerElement;
		virtual int get_bytesPerElement( );
		Dynamic get_bytesPerElement_dyn();

		int length;
		virtual int get_length( );
		Dynamic get_length_dyn();

		int m_length;
		virtual Void Resize( int p_length);
		Dynamic Resize_dyn();

		virtual int GetByte( int p_index);
		Dynamic GetByte_dyn();

		virtual Void SetByte( int p_index,int p_value);
		Dynamic SetByte_dyn();

		virtual Void SetBytes( Array< int > p_list,hx::Null< int >  p_offset);
		Dynamic SetBytes_dyn();

		virtual Void SetBuffer( ::haxor::io::Buffer p_target,hx::Null< int >  p_offset);
		Dynamic SetBuffer_dyn();

		virtual ::String EncodeBase64( );
		Dynamic EncodeBase64_dyn();

		virtual Void DecodeBase64( );
		Dynamic DecodeBase64_dyn();

		virtual ::String GetString( hx::Null< int >  p_offset,hx::Null< int >  p_length);
		Dynamic GetString_dyn();

		virtual Void SetString( ::String p_string,hx::Null< int >  p_offset);
		Dynamic SetString_dyn();

		virtual Void SetViewSlice( int p_start,int p_length);
		Dynamic SetViewSlice_dyn();

		virtual Void ResetSlice( );
		Dynamic ResetSlice_dyn();

		static ::haxor::io::Buffer FromString( ::String p_string);
		static Dynamic FromString_dyn();

};

} // end namespace haxor
} // end namespace io

#endif /* INCLUDED_haxor_io_Buffer */ 
