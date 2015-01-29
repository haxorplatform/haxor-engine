#ifndef INCLUDED_haxor_component_animation_FloatKeyFrame
#define INCLUDED_haxor_component_animation_FloatKeyFrame

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/component/animation/KeyFrame.h>
HX_DECLARE_CLASS3(haxor,component,animation,FloatKeyFrame)
HX_DECLARE_CLASS3(haxor,component,animation,KeyFrame)
namespace haxor{
namespace component{
namespace animation{


class HXCPP_CLASS_ATTRIBUTES  FloatKeyFrame_obj : public ::haxor::component::animation::KeyFrame_obj{
	public:
		typedef ::haxor::component::animation::KeyFrame_obj super;
		typedef FloatKeyFrame_obj OBJ_;
		FloatKeyFrame_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FloatKeyFrame_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FloatKeyFrame_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("FloatKeyFrame"); }

		Float value;
		virtual ::haxor::component::animation::KeyFrame Blend( ::haxor::component::animation::KeyFrame b,Float r);

		virtual Dynamic Sample( Dynamic v,hx::Null< Float >  w);

		static ::haxor::component::animation::FloatKeyFrame m_temp;
};

} // end namespace haxor
} // end namespace component
} // end namespace animation

#endif /* INCLUDED_haxor_component_animation_FloatKeyFrame */ 
