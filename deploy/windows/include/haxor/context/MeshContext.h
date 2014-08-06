#ifndef INCLUDED_haxor_context_MeshContext
#define INCLUDED_haxor_context_MeshContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,context,MeshContext)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  MeshContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MeshContext_obj OBJ_;
		MeshContext_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< MeshContext_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~MeshContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MeshContext"); }

		int aid;
		Array< int > buffers;
};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_MeshContext */ 
