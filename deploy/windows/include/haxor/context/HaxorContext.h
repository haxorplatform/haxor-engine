#ifndef INCLUDED_haxor_context_HaxorContext
#define INCLUDED_haxor_context_HaxorContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,context,HaxorContext)
HX_DECLARE_CLASS2(haxor,context,Process)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  HaxorContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef HaxorContext_obj OBJ_;
		HaxorContext_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< HaxorContext_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~HaxorContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("HaxorContext"); }

		static int uid;
		static int maxNodes;
		static int collectRate;
		static ::haxor::context::Process update;
		static ::haxor::context::Process resize;
		static ::haxor::context::Process render;
		static ::haxor::context::Process resources;
		static ::haxor::context::Process disposables;
		static Void Initialize( );
		static Dynamic Initialize_dyn();

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_HaxorContext */ 
