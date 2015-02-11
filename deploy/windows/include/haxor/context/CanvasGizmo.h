#ifndef INCLUDED_haxor_context_CanvasGizmo
#define INCLUDED_haxor_context_CanvasGizmo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/context/Gizmo.h>
HX_DECLARE_CLASS2(haxor,context,CanvasGizmo)
HX_DECLARE_CLASS2(haxor,context,Gizmo)
HX_DECLARE_CLASS2(haxor,math,Color)
HX_DECLARE_CLASS2(haxor,math,Matrix4)
HX_DECLARE_CLASS2(haxor,math,Vector3)
namespace haxor{
namespace context{


class HXCPP_CLASS_ATTRIBUTES  CanvasGizmo_obj : public ::haxor::context::Gizmo_obj{
	public:
		typedef ::haxor::context::Gizmo_obj super;
		typedef CanvasGizmo_obj OBJ_;
		CanvasGizmo_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< CanvasGizmo_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~CanvasGizmo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CanvasGizmo"); }

		::haxor::math::Color fill;
		::haxor::math::Color line;
		::haxor::math::Vector3 start;
		::haxor::math::Vector3 p0;
		::haxor::math::Vector3 p1;
		::haxor::math::Matrix4 transform;
		int count;
		bool active;
		virtual Void Begin( ::haxor::math::Color p_fill,::haxor::math::Color p_line,::haxor::math::Matrix4 p_transform);
		Dynamic Begin_dyn();

		virtual Void Line( ::haxor::math::Vector3 p_position);
		Dynamic Line_dyn();

		virtual Void End( );
		Dynamic End_dyn();

		virtual Void OnBuild( );

};

} // end namespace haxor
} // end namespace context

#endif /* INCLUDED_haxor_context_CanvasGizmo */ 
