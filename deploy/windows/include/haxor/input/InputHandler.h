#ifndef INCLUDED_haxor_input_InputHandler
#define INCLUDED_haxor_input_InputHandler

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,input,InputHandler)
HX_DECLARE_CLASS2(haxor,input,Joystick)
namespace haxor{
namespace input{


class HXCPP_CLASS_ATTRIBUTES  InputHandler_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef InputHandler_obj OBJ_;
		InputHandler_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< InputHandler_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~InputHandler_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("InputHandler"); }

		::haxor::input::Joystick m_joystick;
		virtual Void Update( );
		Dynamic Update_dyn();

		virtual Void UpdateInput( );
		Dynamic UpdateInput_dyn();

		virtual Void Clear( );
		Dynamic Clear_dyn();

		virtual Void OnMouseMove( Float p_x,Float p_y);
		Dynamic OnMouseMove_dyn();

		virtual Void OnMouseWheel( Float p_wheel);
		Dynamic OnMouseWheel_dyn();

		virtual Void OnMouseButton( int p_button,bool p_down);
		Dynamic OnMouseButton_dyn();

		virtual Void OnKey( int p_code,bool p_down);
		Dynamic OnKey_dyn();

		virtual Void OnTouchStart( int p_id,Float p_x,Float p_y,hx::Null< Float >  p_rx,hx::Null< Float >  p_ry,hx::Null< Float >  p_pressure,hx::Null< Float >  p_angle);
		Dynamic OnTouchStart_dyn();

		virtual Void OnTouchMove( int p_id,Float p_x,Float p_y);
		Dynamic OnTouchMove_dyn();

		virtual Void OnTouchCancel( int p_id);
		Dynamic OnTouchCancel_dyn();

		virtual Void OnTouchEnd( int p_id);
		Dynamic OnTouchEnd_dyn();

		virtual Void OnJoystickStart( int p_id,::String p_name);
		Dynamic OnJoystickStart_dyn();

		virtual Void OnJoystickDataUpdate( int p_code,Float p_value,bool p_is_analog);
		Dynamic OnJoystickDataUpdate_dyn();

		virtual Void OnJoystickAnalogUpdate( );
		Dynamic OnJoystickAnalogUpdate_dyn();

		virtual Void RequestJoystickVibration( ::haxor::input::Joystick p_joystick);
		Dynamic RequestJoystickVibration_dyn();

		virtual Void EmulateTouch( int p_code,int p_id);
		Dynamic EmulateTouch_dyn();

};

} // end namespace haxor
} // end namespace input

#endif /* INCLUDED_haxor_input_InputHandler */ 
