#ifndef INCLUDED_haxor_context_LineGizmo
#define INCLUDED_haxor_context_LineGizmo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/context/Gizmo.h>
HX_DECLARE_CLASS2(haxor,context,Gizmo)
HX_DECLARE_CLASS2(haxor,context,LineGizmo)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  LineGizmo_obj : public ::haxor::context::Gizmo_obj{
	public:
		typedef ::haxor::context::Gizmo_obj super;
		typedef LineGizmo_obj OBJ_;
		LineGizmo_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< LineGizmo_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~LineGizmo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("LineGizmo"); }

		virtual Void OnBuild( );

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_LineGizmo */ 
