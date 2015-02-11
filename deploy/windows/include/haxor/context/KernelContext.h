#ifndef INCLUDED_haxor_context_KernelContext
#define INCLUDED_haxor_context_KernelContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,context,KernelContext)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS3(haxor,graphics,material,Material)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh)
HX_DECLARE_CLASS3(haxor,graphics,mesh,Mesh3)
HX_DECLARE_CLASS3(haxor,graphics,mesh,MeshLayout)
HX_DECLARE_CLASS2(haxor,thread,Kernel)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  KernelContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef KernelContext_obj OBJ_;
		KernelContext_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< KernelContext_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~KernelContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("KernelContext"); }

		::haxor::graphics::mesh::Mesh3 m_plane;
		Array< ::Dynamic > list;
		virtual Void Initialize( );
		Dynamic Initialize_dyn();

		virtual Void Execute( );
		Dynamic Execute_dyn();

		virtual Void OnCreate( ::haxor::thread::Kernel k);
		Dynamic OnCreate_dyn();

		virtual Void OnDestroy( ::haxor::thread::Kernel k);
		Dynamic OnDestroy_dyn();

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_KernelContext */ 
