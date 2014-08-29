#ifndef INCLUDED_haxor_io_file_ColladaVisualScene
#define INCLUDED_haxor_io_file_ColladaVisualScene

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(haxor,io,file,ColladaNode)
HX_DECLARE_CLASS3(haxor,io,file,ColladaVisualScene)
namespace haxor{
namespace io{
namespace file{


class HXCPP_CLASS_ATTRIBUTES  ColladaVisualScene_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ColladaVisualScene_obj OBJ_;
		ColladaVisualScene_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ColladaVisualScene_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ColladaVisualScene_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("ColladaVisualScene"); }

		::String type;
		::String id;
		::String name;
		Array< ::Dynamic > children;
		virtual Void Traverse( Dynamic p_callback);
		Dynamic Traverse_dyn();

		virtual Void TraverseStep( ::haxor::io::file::ColladaNode p_node,Dynamic p_callback);
		Dynamic TraverseStep_dyn();

};

} // end namespace haxor
} // end namespace io
} // end namespace file

#endif /* INCLUDED_haxor_io_file_ColladaVisualScene */ 
