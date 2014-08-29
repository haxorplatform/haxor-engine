#ifndef INCLUDED_haxor_io_file_ColladaPrimitive
#define INCLUDED_haxor_io_file_ColladaPrimitive

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(haxor,io,file,ColladaInput)
HX_DECLARE_CLASS3(haxor,io,file,ColladaPrimitive)
namespace haxor{
namespace io{
namespace file{


class HXCPP_CLASS_ATTRIBUTES  ColladaPrimitive_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ColladaPrimitive_obj OBJ_;
		ColladaPrimitive_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ColladaPrimitive_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ColladaPrimitive_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ColladaPrimitive"); }

		::String type;
		::String material;
		Array< ::Dynamic > inputs;
		Array< int > vcount;
		Array< ::Dynamic > indexes;
		virtual Array< ::Dynamic > get_triangles( );
		Dynamic get_triangles_dyn();

		Array< ::Dynamic > m_triangles;
		virtual int get_offset( );
		Dynamic get_offset_dyn();

		virtual ::haxor::io::file::ColladaInput GetInput( ::String p_semantic,hx::Null< int >  p_set);
		Dynamic GetInput_dyn();

		virtual Dynamic GetTriangulatedVectorArray( ::String p_semantic,hx::Null< int >  p_set,hx::Null< bool >  p_debug);
		Dynamic GetTriangulatedVectorArray_dyn();

		virtual Dynamic GetVectorArray( ::String p_semantic,hx::Null< int >  p_set);
		Dynamic GetVectorArray_dyn();

};

} // end namespace haxor
} // end namespace io
} // end namespace file

#endif /* INCLUDED_haxor_io_file_ColladaPrimitive */ 
