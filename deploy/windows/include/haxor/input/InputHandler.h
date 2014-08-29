#ifndef INCLUDED_haxor_input_InputHandler
#define INCLUDED_haxor_input_InputHandler

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,input,InputHandler)
namespace haxor{
namespace input{


class HXCPP_CLASS_ATTRIBUTES  InputHandler_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef InputHandler_obj OBJ_;
		InputHandler_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< InputHandler_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~InputHandler_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("InputHandler"); }

		virtual bool Update( Float t);
		Dynamic Update_dyn();

		virtual Void UpdateInput( );
		Dynamic UpdateInput_dyn();

		virtual Void OnMouseMove( Float p_x,Float p_y);
		Dynamic OnMouseMove_dyn();

		virtual Void OnMouseWheel( Float p_wheel);
		Dynamic OnMouseWheel_dyn();

		virtual Void OnMouseButton( int p_button,bool p_down);
		Dynamic OnMouseButton_dyn();

		virtual Void OnKey( int p_code,bool p_down);
		Dynamic OnKey_dyn();

};

} // end namespace haxor
} // end namespace input

#endif /* INCLUDED_haxor_input_InputHandler */ 
