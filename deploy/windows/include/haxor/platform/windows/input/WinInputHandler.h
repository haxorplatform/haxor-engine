#ifndef INCLUDED_haxor_platform_windows_input_WinInputHandler
#define INCLUDED_haxor_platform_windows_input_WinInputHandler

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/input/InputHandler.h>
HX_DECLARE_CLASS2(haxor,input,InputHandler)
HX_DECLARE_CLASS2(haxor,input,Joystick)
HX_DECLARE_CLASS4(haxor,platform,windows,input,WinInputHandler)

#include <Windows.h>
#include <Xinput.h>

namespace haxor{
namespace platform{
namespace windows{
namespace input{


class HXCPP_CLASS_ATTRIBUTES  WinInputHandler_obj : public ::haxor::input::InputHandler_obj{
	public:
		typedef ::haxor::input::InputHandler_obj super;
		typedef WinInputHandler_obj OBJ_;
		WinInputHandler_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< WinInputHandler_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~WinInputHandler_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("WinInputHandler"); }

		int m_max_joystick;
		virtual Void UpdateInput( );

		virtual Void UpdateJoysticks( );
		Dynamic UpdateJoysticks_dyn();

		virtual Void RequestJoystickVibration( ::haxor::input::Joystick p_joystick);

		virtual Void CheckJoysticks( );
		Dynamic CheckJoysticks_dyn();


#undef RegisterClass

};

} // end namespace haxor
} // end namespace platform
} // end namespace windows
} // end namespace input

#endif /* INCLUDED_haxor_platform_windows_input_WinInputHandler */ 
