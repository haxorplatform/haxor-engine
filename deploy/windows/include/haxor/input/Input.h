#ifndef INCLUDED_haxor_input_Input
#define INCLUDED_haxor_input_Input

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,IntMap)
HX_DECLARE_CLASS2(haxor,core,InputState)
HX_DECLARE_CLASS2(haxor,input,Input)
HX_DECLARE_CLASS2(haxor,input,Joystick)
HX_DECLARE_CLASS2(haxor,input,Touch)
HX_DECLARE_CLASS2(haxor,math,Vector2)
namespace haxor{
namespace input{


class HXCPP_CLASS_ATTRIBUTES  Input_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Input_obj OBJ_;
		Input_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Input_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Input_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("Input"); }

		static ::haxe::ds::IntMap m_state;
		static ::haxe::ds::IntMap m_hold;
		static Array< bool > m_down;
		static Array< int > m_active;
		static Array< ::Dynamic > get_touch( );
		static Dynamic get_touch_dyn();

		static Array< ::Dynamic > m_touch;
		static Array< ::Dynamic > get_joystick( );
		static Dynamic get_joystick_dyn();

		static Array< ::Dynamic > m_joysticks;
		static Array< ::Dynamic > m_api_joystick;
		static bool get_multitouch( );
		static Dynamic get_multitouch_dyn();

		static bool m_multitouch;
		static ::haxor::math::Vector2 mouse;
		static ::haxor::math::Vector2 deltaMouse;
		static ::haxor::math::Vector2 relativeMouse;
		static Float wheel;
		static bool scroll;
		static ::haxor::core::InputState GetInputState( int p_code);
		static Dynamic GetInputState_dyn();

		static bool Pressed( int p_code);
		static Dynamic Pressed_dyn();

		static bool Down( int p_code);
		static Dynamic Down_dyn();

		static bool Hit( int p_code);
		static Dynamic Hit_dyn();

		static Float GetHoldTime( int p_code);
		static Dynamic GetHoldTime_dyn();

		static Void Initialize( );
		static Dynamic Initialize_dyn();

		static Void UpdateTouchFSM( );
		static Dynamic UpdateTouchFSM_dyn();

		static Void UpdateInput( );
		static Dynamic UpdateInput_dyn();

		static Void ResetTouchDownFlag( );
		static Dynamic ResetTouchDownFlag_dyn();

		static Void TouchFSM( ::haxor::input::Touch t);
		static Dynamic TouchFSM_dyn();

		static Void UpdateInputState( int p_code,bool p_is_down);
		static Dynamic UpdateInputState_dyn();

		static ::haxor::core::InputState InputStateFSM( ::haxor::core::InputState p_current,bool p_is_down);
		static Dynamic InputStateFSM_dyn();

};

} // end namespace haxor
} // end namespace input

#endif /* INCLUDED_haxor_input_Input */ 
