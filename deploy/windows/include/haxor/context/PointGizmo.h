#ifndef INCLUDED_haxor_context_PointGizmo
#define INCLUDED_haxor_context_PointGizmo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/context/Gizmo.h>
HX_DECLARE_CLASS2(haxor,context,Gizmo)
HX_DECLARE_CLASS2(haxor,context,PointGizmo)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  PointGizmo_obj : public ::haxor::context::Gizmo_obj{
	public:
		typedef ::haxor::context::Gizmo_obj super;
		typedef PointGizmo_obj OBJ_;
		PointGizmo_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PointGizmo_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PointGizmo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("PointGizmo"); }

		virtual Void OnBuild( );

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_PointGizmo */ 
