#ifndef INCLUDED_haxor_input_Joystick
#define INCLUDED_haxor_input_Joystick

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,core,InputState)
HX_DECLARE_CLASS2(haxor,input,Joystick)
HX_DECLARE_CLASS2(haxor,math,Vector3)
namespace haxor{
namespace input{


class HXCPP_CLASS_ATTRIBUTES  Joystick_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Joystick_obj OBJ_;
		Joystick_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Joystick_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Joystick_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Joystick"); }

		::String name;
		int id;
		Array< Float > button;
		Array< ::Dynamic > state;
		Array< Float > hold;
		Array< Float > analog;
		::haxor::math::Vector3 analogLeft;
		::haxor::math::Vector3 analogRight;
		Float triggerLeft;
		Float triggerRight;
		virtual bool IsDown( int p_button);
		Dynamic IsDown_dyn();

		virtual bool Hit( int p_button);
		Dynamic Hit_dyn();

		static Array< Float > analogBias;
		static Float buttonBias;
		static bool available;
};

} // end namespace haxor
} // end namespace input

#endif /* INCLUDED_haxor_input_Joystick */ 
