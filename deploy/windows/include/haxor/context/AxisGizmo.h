#ifndef INCLUDED_haxor_context_AxisGizmo
#define INCLUDED_haxor_context_AxisGizmo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/context/Gizmo.h>
HX_DECLARE_CLASS2(haxor,context,AxisGizmo)
HX_DECLARE_CLASS2(haxor,context,Gizmo)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  AxisGizmo_obj : public ::haxor::context::Gizmo_obj{
	public:
		typedef ::haxor::context::Gizmo_obj super;
		typedef AxisGizmo_obj OBJ_;
		AxisGizmo_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< AxisGizmo_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~AxisGizmo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("AxisGizmo"); }

		virtual Void OnBuild( );

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_AxisGizmo */ 
