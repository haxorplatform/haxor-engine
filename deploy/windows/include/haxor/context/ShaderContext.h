#ifndef INCLUDED_haxor_context_ShaderContext
#define INCLUDED_haxor_context_ShaderContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,context,ShaderContext)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  ShaderContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef ShaderContext_obj OBJ_;
		ShaderContext_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< ShaderContext_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~ShaderContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("ShaderContext"); }

		static ::String flat_source;
		static ::String flat_texture_source;
		static ::String flat_texture_skin_source;
		static ::String grid_source;
		static ::String texture_source;
		static ::String gizmo_source;
		static ::String flat_particle_source;
};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_ShaderContext */ 
