#ifndef INCLUDED_haxor_input_Touch
#define INCLUDED_haxor_input_Touch

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,InputState)
HX_DECLARE_CLASS2(haxor,input,Touch)
HX_DECLARE_CLASS2(haxor,math,Vector2)
namespace haxor{
namespace input{


class HXCPP_CLASS_ATTRIBUTES  Touch_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Touch_obj OBJ_;
		Touch_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Touch_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Touch_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Touch"); }

		::haxor::core::InputState state;
		int id;
		::haxor::math::Vector2 position;
		::haxor::math::Vector2 radius;
		Float angle;
		::haxor::math::Vector2 relativePosition;
		::haxor::math::Vector2 delta;
		Float pressure;
		Float hold;
		bool m_down;
		virtual ::String ToString( );
		Dynamic ToString_dyn();

};

} // end namespace haxor
} // end namespace input

#endif /* INCLUDED_haxor_input_Touch */ 
