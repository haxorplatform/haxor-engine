#ifndef INCLUDED_haxor_component_animation_Vector3KeyFrame
#define INCLUDED_haxor_component_animation_Vector3KeyFrame

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/animation/KeyFrame.h>
HX_DECLARE_CLASS3(haxor,component,animation,KeyFrame)
HX_DECLARE_CLASS3(haxor,component,animation,Vector3KeyFrame)
HX_DECLARE_CLASS2(haxor,math,Vector3)
namespace haxor{
namespace component{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  Vector3KeyFrame_obj : public ::haxor::component::animation::KeyFrame_obj{
	public:
		typedef ::haxor::component::animation::KeyFrame_obj super;
		typedef Vector3KeyFrame_obj OBJ_;
		Vector3KeyFrame_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Vector3KeyFrame_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Vector3KeyFrame_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Vector3KeyFrame"); }

		::haxor::math::Vector3 value;
		virtual ::haxor::component::animation::KeyFrame Blend( ::haxor::component::animation::KeyFrame b,Float r);

		virtual Dynamic Sample( Dynamic v,hx::Null< Float >  w);

		static ::haxor::component::animation::Vector3KeyFrame m_temp;
};

} // end namespace haxor
} // end namespace component
} // end namespace animation

#endif /* INCLUDED_haxor_component_animation_Vector3KeyFrame */ 
