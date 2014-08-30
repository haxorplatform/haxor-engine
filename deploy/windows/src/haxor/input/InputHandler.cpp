#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IRenderable
#include <haxor/core/IRenderable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_InputState
#include <haxor/core/InputState.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
#endif
#ifndef INCLUDED_haxor_graphics_Screen
#include <haxor/graphics/Screen.h>
#endif
#ifndef INCLUDED_haxor_input_Input
#include <haxor/input/Input.h>
#endif
#ifndef INCLUDED_haxor_input_InputHandler
#include <haxor/input/InputHandler.h>
#endif
#ifndef INCLUDED_haxor_input_Joystick
#include <haxor/input/Joystick.h>
#endif
#ifndef INCLUDED_haxor_input_KeyCode
#include <haxor/input/KeyCode.h>
#endif
#ifndef INCLUDED_haxor_input_Touch
#include <haxor/input/Touch.h>
#endif
#ifndef INCLUDED_haxor_math_Vector2
#include <haxor/math/Vector2.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_thread_Activity
#include <haxor/thread/Activity.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace input{

Void InputHandler_obj::__construct()
{
HX_STACK_FRAME("haxor.input.InputHandler","new",0xc4966782,"haxor.input.InputHandler.new","haxor/input/InputHandler.hx",30,0x17daf1ac)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(30)
	::haxor::thread::Activity_obj::Run(this->Update_dyn(),null(),null());
}
;
	return null();
}

//InputHandler_obj::~InputHandler_obj() { }

Dynamic InputHandler_obj::__CreateEmpty() { return  new InputHandler_obj; }
hx::ObjectPtr< InputHandler_obj > InputHandler_obj::__new()
{  hx::ObjectPtr< InputHandler_obj > result = new InputHandler_obj();
	result->__construct();
	return result;}

Dynamic InputHandler_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InputHandler_obj > result = new InputHandler_obj();
	result->__construct();
	return result;}

bool InputHandler_obj::Update( Float t){
	HX_STACK_FRAME("haxor.input.InputHandler","Update",0x72490447,"haxor.input.InputHandler.Update","haxor/input/InputHandler.hx",34,0x17daf1ac)
	HX_STACK_THIS(this)
	HX_STACK_ARG(t,"t")
	HX_STACK_LINE(35)
	::haxor::input::Input_obj::wheel = (int)0;
	HX_STACK_LINE(36)
	::haxor::input::Input_obj::deltaMouse->x = (int)0;
	HX_STACK_LINE(37)
	::haxor::input::Input_obj::deltaMouse->y = (int)0;
	HX_STACK_LINE(38)
	::haxor::input::Input_obj::UpdateInput();
	HX_STACK_LINE(39)
	::haxor::input::Input_obj::UpdateTouchFSM();
	HX_STACK_LINE(40)
	this->UpdateInput();
	HX_STACK_LINE(41)
	this->EmulateTouch(::haxor::input::KeyCode_obj::Mouse0,(int)0);
	HX_STACK_LINE(42)
	this->EmulateTouch(::haxor::input::KeyCode_obj::Mouse1,(int)2);
	HX_STACK_LINE(43)
	this->EmulateTouch(::haxor::input::KeyCode_obj::Mouse2,(int)1);
	HX_STACK_LINE(44)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(InputHandler_obj,Update,return )

Void InputHandler_obj::UpdateInput( ){
{
		HX_STACK_FRAME("haxor.input.InputHandler","UpdateInput",0xc72a4e43,"haxor.input.InputHandler.UpdateInput","haxor/input/InputHandler.hx",50,0x17daf1ac)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InputHandler_obj,UpdateInput,(void))

Void InputHandler_obj::OnMouseMove( Float p_x,Float p_y){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnMouseMove",0x3a6c9fb9,"haxor.input.InputHandler.OnMouseMove","haxor/input/InputHandler.hx",58,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(59)
		::haxor::input::Input_obj::deltaMouse->x = (p_x - ::haxor::input::Input_obj::mouse->x);
		HX_STACK_LINE(60)
		::haxor::input::Input_obj::deltaMouse->y = (p_y - ::haxor::input::Input_obj::mouse->y);
		HX_STACK_LINE(61)
		::haxor::input::Input_obj::mouse->x = p_x;
		HX_STACK_LINE(62)
		::haxor::input::Input_obj::mouse->y = p_y;
		HX_STACK_LINE(63)
		::haxor::input::Input_obj::relativeMouse->x = (Float(::haxor::input::Input_obj::mouse->x) / Float(::haxor::graphics::Screen_obj::m_width));
		HX_STACK_LINE(64)
		::haxor::input::Input_obj::relativeMouse->y = (Float(::haxor::input::Input_obj::mouse->y) / Float(::haxor::graphics::Screen_obj::m_height));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InputHandler_obj,OnMouseMove,(void))

Void InputHandler_obj::OnMouseWheel( Float p_wheel){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnMouseWheel",0xa1f38af3,"haxor.input.InputHandler.OnMouseWheel","haxor/input/InputHandler.hx",73,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_wheel,"p_wheel")
		HX_STACK_LINE(73)
		::haxor::input::Input_obj::wheel = p_wheel;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InputHandler_obj,OnMouseWheel,(void))

Void InputHandler_obj::OnMouseButton( int p_button,bool p_down){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnMouseButton",0x33d2989a,"haxor.input.InputHandler.OnMouseButton","haxor/input/InputHandler.hx",83,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_button,"p_button")
		HX_STACK_ARG(p_down,"p_down")
		HX_STACK_LINE(83)
		switch( (int)(p_button)){
			case (int)0: {
				HX_STACK_LINE(85)
				::haxor::input::Input_obj::UpdateInputState(::haxor::input::KeyCode_obj::Mouse0,p_down,false);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(86)
				::haxor::input::Input_obj::UpdateInputState(::haxor::input::KeyCode_obj::Mouse1,p_down,false);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(87)
				::haxor::input::Input_obj::UpdateInputState(::haxor::input::KeyCode_obj::Mouse2,p_down,false);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(88)
				::haxor::input::Input_obj::UpdateInputState(::haxor::input::KeyCode_obj::Mouse3,p_down,false);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(89)
				::haxor::input::Input_obj::UpdateInputState(::haxor::input::KeyCode_obj::Mouse4,p_down,false);
			}
			;break;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InputHandler_obj,OnMouseButton,(void))

Void InputHandler_obj::OnKey( int p_code,bool p_down){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnKey",0x1106b142,"haxor.input.InputHandler.OnKey","haxor/input/InputHandler.hx",100,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_code,"p_code")
		HX_STACK_ARG(p_down,"p_down")
		HX_STACK_LINE(100)
		::haxor::input::Input_obj::UpdateInputState(p_code,p_down,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InputHandler_obj,OnKey,(void))

Void InputHandler_obj::OnTouchStart( int p_id,Float p_x,Float p_y,hx::Null< Float >  __o_p_rx,hx::Null< Float >  __o_p_ry,hx::Null< Float >  __o_p_pressure,hx::Null< Float >  __o_p_angle){
Float p_rx = __o_p_rx.Default(0.0);
Float p_ry = __o_p_ry.Default(0.0);
Float p_pressure = __o_p_pressure.Default(0.0);
Float p_angle = __o_p_angle.Default(0.0);
	HX_STACK_FRAME("haxor.input.InputHandler","OnTouchStart",0x3808bae0,"haxor.input.InputHandler.OnTouchStart","haxor/input/InputHandler.hx",108,0x17daf1ac)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_id,"p_id")
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_ARG(p_rx,"p_rx")
	HX_STACK_ARG(p_ry,"p_ry")
	HX_STACK_ARG(p_pressure,"p_pressure")
	HX_STACK_ARG(p_angle,"p_angle")
{
		HX_STACK_LINE(110)
		::haxor::input::Touch t = ::haxor::input::Input_obj::m_api_touches->__get(p_id).StaticCast< ::haxor::input::Touch >();		HX_STACK_VAR(t,"t");
		HX_STACK_LINE(111)
		t->id = p_id;
		HX_STACK_LINE(112)
		t->position->x = p_x;
		HX_STACK_LINE(113)
		t->position->y = p_y;
		HX_STACK_LINE(114)
		t->relativePosition->x = (Float(t->position->x) / Float(::haxor::graphics::Screen_obj::m_width));
		HX_STACK_LINE(115)
		t->relativePosition->y = (Float(t->position->y) / Float(::haxor::graphics::Screen_obj::m_height));
		HX_STACK_LINE(116)
		t->delta->x = 0.0;
		HX_STACK_LINE(117)
		t->delta->y = 0.0;
		HX_STACK_LINE(118)
		t->pressure = p_pressure;
		HX_STACK_LINE(119)
		t->radius->x = p_rx;
		HX_STACK_LINE(120)
		t->radius->y = p_ry;
		HX_STACK_LINE(121)
		t->angle = p_angle;
		HX_STACK_LINE(122)
		t->m_down = true;
		HX_STACK_LINE(123)
		int _g = ::haxor::input::Input_obj::m_touches->indexOf(t,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(123)
		if (((_g < (int)0))){
			HX_STACK_LINE(123)
			::haxor::input::Input_obj::m_touches->push(t);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(InputHandler_obj,OnTouchStart,(void))

Void InputHandler_obj::OnTouchMove( int p_id,Float p_x,Float p_y){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnTouchMove",0x53847653,"haxor.input.InputHandler.OnTouchMove","haxor/input/InputHandler.hx",133,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(134)
		::haxor::input::Touch t = ::haxor::input::Input_obj::m_api_touches->__get(p_id).StaticCast< ::haxor::input::Touch >();		HX_STACK_VAR(t,"t");
		HX_STACK_LINE(135)
		if (((t->id >= (int)0))){
			HX_STACK_LINE(137)
			t->delta->x = (p_x - t->position->x);
			HX_STACK_LINE(138)
			t->delta->y = (p_y - t->position->y);
		}
		HX_STACK_LINE(140)
		t->position->x = p_x;
		HX_STACK_LINE(141)
		t->position->y = p_y;
		HX_STACK_LINE(142)
		t->relativePosition->x = (Float(t->position->x) / Float(::haxor::graphics::Screen_obj::m_width));
		HX_STACK_LINE(143)
		t->relativePosition->y = (Float(t->position->y) / Float(::haxor::graphics::Screen_obj::m_height));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(InputHandler_obj,OnTouchMove,(void))

Void InputHandler_obj::OnTouchCancel( int p_id){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnTouchCancel",0x81d4553c,"haxor.input.InputHandler.OnTouchCancel","haxor/input/InputHandler.hx",151,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(152)
		::haxor::input::Touch t = ::haxor::input::Input_obj::m_api_touches->__get(p_id).StaticCast< ::haxor::input::Touch >();		HX_STACK_VAR(t,"t");
		HX_STACK_LINE(153)
		t->m_down = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InputHandler_obj,OnTouchCancel,(void))

Void InputHandler_obj::OnTouchEnd( int p_id){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnTouchEnd",0x56730ed9,"haxor.input.InputHandler.OnTouchEnd","haxor/input/InputHandler.hx",161,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(163)
		::haxor::input::Touch t = ::haxor::input::Input_obj::m_api_touches->__get(p_id).StaticCast< ::haxor::input::Touch >();		HX_STACK_VAR(t,"t");
		HX_STACK_LINE(164)
		t->m_down = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InputHandler_obj,OnTouchEnd,(void))

Void InputHandler_obj::OnJoystickStart( int p_id,::String p_name){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnJoystickStart",0x827d0b69,"haxor.input.InputHandler.OnJoystickStart","haxor/input/InputHandler.hx",173,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_LINE(174)
		this->m_joystick = null();
		HX_STACK_LINE(175)
		::haxor::input::Joystick jk = ::haxor::input::Input_obj::m_api_joystick->__get(p_id).StaticCast< ::haxor::input::Joystick >();		HX_STACK_VAR(jk,"jk");
		HX_STACK_LINE(176)
		if (((jk == null()))){
			HX_STACK_LINE(176)
			return null();
		}
		HX_STACK_LINE(177)
		this->m_joystick = jk;
		HX_STACK_LINE(178)
		int _g = ::haxor::input::Input_obj::m_joysticks->indexOf(jk,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(178)
		if (((_g >= (int)0))){
			HX_STACK_LINE(178)
			return null();
		}
		HX_STACK_LINE(179)
		jk->id = p_id;
		HX_STACK_LINE(180)
		jk->name = p_name;
		HX_STACK_LINE(181)
		::haxor::input::Input_obj::m_joysticks->push(jk);
		HX_STACK_LINE(182)
		::haxor::input::Joystick_obj::available = (::haxor::input::Input_obj::m_joysticks->length > (int)0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InputHandler_obj,OnJoystickStart,(void))

Void InputHandler_obj::OnJoystickDataUpdate( int p_code,Float p_value,bool p_is_analog){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnJoystickDataUpdate",0x2a91db6c,"haxor.input.InputHandler.OnJoystickDataUpdate","haxor/input/InputHandler.hx",192,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_code,"p_code")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_ARG(p_is_analog,"p_is_analog")
		HX_STACK_LINE(193)
		if (((this->m_joystick == null()))){
			HX_STACK_LINE(193)
			return null();
		}
		HX_STACK_LINE(194)
		if ((!(p_is_analog))){
			HX_STACK_LINE(196)
			this->m_joystick->button[p_code] = p_value;
			HX_STACK_LINE(197)
			this->m_joystick->state[p_code] = ::haxor::input::Input_obj::InputStateFSM(this->m_joystick->state->__get(p_code).StaticCast< ::haxor::core::InputState >(),(this->m_joystick->button->__get(p_code) >= ::haxor::input::Joystick_obj::buttonBias));
			HX_STACK_LINE(198)
			if (((this->m_joystick->state->__get(p_code).StaticCast< ::haxor::core::InputState >() == ::haxor::core::InputState_obj::Hold))){
				HX_STACK_LINE(198)
				hx::AddEq(this->m_joystick->hold[p_code],::haxor::core::Time_obj::m_delta);
			}
			HX_STACK_LINE(199)
			if (((this->m_joystick->state->__get(p_code).StaticCast< ::haxor::core::InputState >() == ::haxor::core::InputState_obj::None))){
				HX_STACK_LINE(199)
				this->m_joystick->hold[p_code] = 0.0;
			}
		}
		else{
			HX_STACK_LINE(203)
			this->m_joystick->analog[p_code] = p_value;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(InputHandler_obj,OnJoystickDataUpdate,(void))

Void InputHandler_obj::OnJoystickAnalogUpdate( ){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnJoystickAnalogUpdate",0xda26fc32,"haxor.input.InputHandler.OnJoystickAnalogUpdate","haxor/input/InputHandler.hx",211,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_LINE(212)
		if (((this->m_joystick == null()))){
			HX_STACK_LINE(212)
			return null();
		}
		HX_STACK_LINE(213)
		Float b0 = ::haxor::input::Joystick_obj::analogBias->__get((int)0);		HX_STACK_VAR(b0,"b0");
		HX_STACK_LINE(214)
		Float b1 = ::haxor::input::Joystick_obj::analogBias->__get((int)1);		HX_STACK_VAR(b1,"b1");
		HX_STACK_LINE(215)
		Float s = 1.0;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(216)
		::haxor::math::Vector3 v;		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(217)
		::haxor::input::Joystick jk = this->m_joystick;		HX_STACK_VAR(jk,"jk");
		HX_STACK_LINE(219)
		v = jk->analogLeft;
		HX_STACK_LINE(220)
		v->x = jk->analog->__get(::haxor::input::KeyCode_obj::LeftAnalogueHor);
		HX_STACK_LINE(220)
		if (((v->x < 0.0))){
			HX_STACK_LINE(220)
			s = -1.0;
		}
		else{
			HX_STACK_LINE(220)
			s = 1.0;
		}
		HX_STACK_LINE(220)
		{
			HX_STACK_LINE(220)
			Float p_v;		HX_STACK_VAR(p_v,"p_v");
			struct _Function_2_1{
				inline static Float Block( ::haxor::math::Vector3 &v){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/input/InputHandler.hx",220,0x17daf1ac)
					{
						HX_STACK_LINE(220)
						Float p_a = v->x;		HX_STACK_VAR(p_a,"p_a");
						HX_STACK_LINE(220)
						return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
					}
					return null();
				}
			};
			HX_STACK_LINE(220)
			p_v = (Float(((_Function_2_1::Block(v) - b0))) / Float(((b1 - b0))));
			HX_STACK_LINE(220)
			if (((p_v <= 0.0))){
				HX_STACK_LINE(220)
				v->x = 0.0;
			}
			else{
				HX_STACK_LINE(220)
				if (((p_v >= 1.0))){
					HX_STACK_LINE(220)
					v->x = 1.0;
				}
				else{
					HX_STACK_LINE(220)
					v->x = p_v;
				}
			}
		}
		HX_STACK_LINE(220)
		Float _g = ::Std_obj::_int((v->x * 100.0));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(220)
		Float _g1 = (s * _g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(220)
		Float _g2 = (_g1 * 0.01);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(220)
		v->x = _g2;
		HX_STACK_LINE(221)
		v->y = jk->analog->__get(::haxor::input::KeyCode_obj::LeftAnalogueVert);
		HX_STACK_LINE(221)
		if (((v->y < 0.0))){
			HX_STACK_LINE(221)
			s = -1.0;
		}
		else{
			HX_STACK_LINE(221)
			s = 1.0;
		}
		HX_STACK_LINE(221)
		{
			HX_STACK_LINE(221)
			Float p_v;		HX_STACK_VAR(p_v,"p_v");
			struct _Function_2_1{
				inline static Float Block( ::haxor::math::Vector3 &v){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/input/InputHandler.hx",221,0x17daf1ac)
					{
						HX_STACK_LINE(221)
						Float p_a = v->y;		HX_STACK_VAR(p_a,"p_a");
						HX_STACK_LINE(221)
						return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
					}
					return null();
				}
			};
			HX_STACK_LINE(221)
			p_v = (Float(((_Function_2_1::Block(v) - b0))) / Float(((b1 - b0))));
			HX_STACK_LINE(221)
			if (((p_v <= 0.0))){
				HX_STACK_LINE(221)
				v->y = 0.0;
			}
			else{
				HX_STACK_LINE(221)
				if (((p_v >= 1.0))){
					HX_STACK_LINE(221)
					v->y = 1.0;
				}
				else{
					HX_STACK_LINE(221)
					v->y = p_v;
				}
			}
		}
		HX_STACK_LINE(221)
		Float _g3 = ::Std_obj::_int((v->y * 100.0));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(221)
		Float _g4 = (-(s) * _g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(221)
		Float _g5 = (_g4 * 0.01);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(221)
		v->y = _g5;
		HX_STACK_LINE(223)
		if (((jk->button->__get(::haxor::input::KeyCode_obj::LeftAnalogueStick) > 0.5))){
			HX_STACK_LINE(223)
			v->z = 1.0;
		}
		else{
			HX_STACK_LINE(223)
			v->z = 0.0;
		}
		HX_STACK_LINE(225)
		v = jk->analogRight;
		HX_STACK_LINE(226)
		v->x = jk->analog->__get(::haxor::input::KeyCode_obj::RightAnalogueHor);
		HX_STACK_LINE(226)
		if (((v->x < 0.0))){
			HX_STACK_LINE(226)
			s = -1.0;
		}
		else{
			HX_STACK_LINE(226)
			s = 1.0;
		}
		HX_STACK_LINE(226)
		{
			HX_STACK_LINE(226)
			Float p_v;		HX_STACK_VAR(p_v,"p_v");
			struct _Function_2_1{
				inline static Float Block( ::haxor::math::Vector3 &v){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/input/InputHandler.hx",226,0x17daf1ac)
					{
						HX_STACK_LINE(226)
						Float p_a = v->x;		HX_STACK_VAR(p_a,"p_a");
						HX_STACK_LINE(226)
						return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
					}
					return null();
				}
			};
			HX_STACK_LINE(226)
			p_v = (Float(((_Function_2_1::Block(v) - b0))) / Float(((b1 - b0))));
			HX_STACK_LINE(226)
			if (((p_v <= 0.0))){
				HX_STACK_LINE(226)
				v->x = 0.0;
			}
			else{
				HX_STACK_LINE(226)
				if (((p_v >= 1.0))){
					HX_STACK_LINE(226)
					v->x = 1.0;
				}
				else{
					HX_STACK_LINE(226)
					v->x = p_v;
				}
			}
		}
		HX_STACK_LINE(226)
		Float _g6 = ::Std_obj::_int((v->x * 100.0));		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(226)
		Float _g7 = (s * _g6);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(226)
		Float _g8 = (_g7 * 0.01);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(226)
		v->x = _g8;
		HX_STACK_LINE(227)
		v->y = jk->analog->__get(::haxor::input::KeyCode_obj::RightAnalogueVert);
		HX_STACK_LINE(227)
		if (((v->y < 0.0))){
			HX_STACK_LINE(227)
			s = -1.0;
		}
		else{
			HX_STACK_LINE(227)
			s = 1.0;
		}
		HX_STACK_LINE(227)
		{
			HX_STACK_LINE(227)
			Float p_v;		HX_STACK_VAR(p_v,"p_v");
			struct _Function_2_1{
				inline static Float Block( ::haxor::math::Vector3 &v){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/input/InputHandler.hx",227,0x17daf1ac)
					{
						HX_STACK_LINE(227)
						Float p_a = v->y;		HX_STACK_VAR(p_a,"p_a");
						HX_STACK_LINE(227)
						return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
					}
					return null();
				}
			};
			HX_STACK_LINE(227)
			p_v = (Float(((_Function_2_1::Block(v) - b0))) / Float(((b1 - b0))));
			HX_STACK_LINE(227)
			if (((p_v <= 0.0))){
				HX_STACK_LINE(227)
				v->y = 0.0;
			}
			else{
				HX_STACK_LINE(227)
				if (((p_v >= 1.0))){
					HX_STACK_LINE(227)
					v->y = 1.0;
				}
				else{
					HX_STACK_LINE(227)
					v->y = p_v;
				}
			}
		}
		HX_STACK_LINE(227)
		Float _g9 = ::Std_obj::_int((v->y * 100.0));		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(227)
		Float _g10 = (-(s) * _g9);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(227)
		Float _g11 = (_g10 * 0.01);		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(227)
		v->y = _g11;
		HX_STACK_LINE(228)
		if (((jk->button->__get(::haxor::input::KeyCode_obj::RightAnalogueStick) > 0.5))){
			HX_STACK_LINE(228)
			v->z = 1.0;
		}
		else{
			HX_STACK_LINE(228)
			v->z = 0.0;
		}
		HX_STACK_LINE(230)
		jk->triggerLeft = jk->button->__get(::haxor::input::KeyCode_obj::LeftShoulderBottom);
		HX_STACK_LINE(230)
		{
			HX_STACK_LINE(230)
			Float p_v = (Float(((jk->triggerLeft - b0))) / Float(((b1 - b0))));		HX_STACK_VAR(p_v,"p_v");
			HX_STACK_LINE(230)
			if (((p_v <= 0.0))){
				HX_STACK_LINE(230)
				jk->triggerLeft = 0.0;
			}
			else{
				HX_STACK_LINE(230)
				if (((p_v >= 1.0))){
					HX_STACK_LINE(230)
					jk->triggerLeft = 1.0;
				}
				else{
					HX_STACK_LINE(230)
					jk->triggerLeft = p_v;
				}
			}
		}
		HX_STACK_LINE(231)
		jk->triggerRight = jk->button->__get(::haxor::input::KeyCode_obj::RightShoulderBottom);
		HX_STACK_LINE(231)
		{
			HX_STACK_LINE(231)
			Float p_v = (Float(((jk->triggerRight - b0))) / Float(((b1 - b0))));		HX_STACK_VAR(p_v,"p_v");
			HX_STACK_LINE(231)
			if (((p_v <= 0.0))){
				HX_STACK_LINE(231)
				jk->triggerRight = 0.0;
			}
			else{
				HX_STACK_LINE(231)
				if (((p_v >= 1.0))){
					HX_STACK_LINE(231)
					jk->triggerRight = 1.0;
				}
				else{
					HX_STACK_LINE(231)
					jk->triggerRight = p_v;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InputHandler_obj,OnJoystickAnalogUpdate,(void))

Void InputHandler_obj::RequestJoystickVibration( ::haxor::input::Joystick p_joystick){
{
		HX_STACK_FRAME("haxor.input.InputHandler","RequestJoystickVibration",0x9aa08525,"haxor.input.InputHandler.RequestJoystickVibration","haxor/input/InputHandler.hx",239,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_joystick,"p_joystick")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InputHandler_obj,RequestJoystickVibration,(void))

Void InputHandler_obj::EmulateTouch( int p_code,int p_id){
{
		HX_STACK_FRAME("haxor.input.InputHandler","EmulateTouch",0x1e86c6ca,"haxor.input.InputHandler.EmulateTouch","haxor/input/InputHandler.hx",248,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_code,"p_code")
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(249)
		if ((::haxor::input::Input_obj::Down(p_code))){
			HX_STACK_LINE(251)
			::haxor::math::Vector2 p;		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(251)
			{
				HX_STACK_LINE(251)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(251)
				int _g = _this->m_nv2 = hx::Mod(((_this->m_nv2 + (int)1)),_this->m_v2->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(251)
				p = _this->m_v2->__get(_g).StaticCast< ::haxor::math::Vector2 >();
			}
			HX_STACK_LINE(252)
			switch( (int)(p_id)){
				case (int)0: {
					HX_STACK_LINE(254)
					p->Set2(::haxor::input::Input_obj::mouse);
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(255)
					p->Set((::haxor::graphics::Screen_obj::m_width * 0.5),(::haxor::graphics::Screen_obj::m_height * 0.5));
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(256)
					Float _g1 = ::Math_obj::random();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(256)
					Float _g2 = (::haxor::graphics::Screen_obj::m_width * _g1);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(256)
					Float _g3 = ::Math_obj::random();		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(256)
					Float _g4 = (::haxor::graphics::Screen_obj::m_height * _g3);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(256)
					p->Set(_g2,_g4);
				}
				;break;
			}
			HX_STACK_LINE(258)
			this->OnTouchStart(p_id,p->x,p->y,null(),null(),null(),null());
		}
		HX_STACK_LINE(260)
		if (((p_id == (int)0))){
			HX_STACK_LINE(260)
			if ((::haxor::input::Input_obj::Pressed(p_code))){
				HX_STACK_LINE(260)
				Float _g5;		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(260)
				{
					HX_STACK_LINE(260)
					::haxor::math::Vector2 _this = ::haxor::input::Input_obj::deltaMouse;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(260)
					_g5 = ::Math_obj::sqrt(((_this->x * _this->x) + (_this->y * _this->y)));
				}
				HX_STACK_LINE(260)
				if (((_g5 > (int)0))){
					HX_STACK_LINE(260)
					this->OnTouchMove(p_id,::haxor::input::Input_obj::mouse->x,::haxor::input::Input_obj::mouse->y);
				}
			}
		}
		HX_STACK_LINE(261)
		if ((::haxor::input::Input_obj::Hit(p_code))){
			HX_STACK_LINE(261)
			this->OnTouchEnd(p_id);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InputHandler_obj,EmulateTouch,(void))


InputHandler_obj::InputHandler_obj()
{
}

void InputHandler_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InputHandler);
	HX_MARK_MEMBER_NAME(m_joystick,"m_joystick");
	HX_MARK_END_CLASS();
}

void InputHandler_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_joystick,"m_joystick");
}

Dynamic InputHandler_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"OnKey") ) { return OnKey_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Update") ) { return Update_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_joystick") ) { return m_joystick; }
		if (HX_FIELD_EQ(inName,"OnTouchEnd") ) { return OnTouchEnd_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"UpdateInput") ) { return UpdateInput_dyn(); }
		if (HX_FIELD_EQ(inName,"OnMouseMove") ) { return OnMouseMove_dyn(); }
		if (HX_FIELD_EQ(inName,"OnTouchMove") ) { return OnTouchMove_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"OnMouseWheel") ) { return OnMouseWheel_dyn(); }
		if (HX_FIELD_EQ(inName,"OnTouchStart") ) { return OnTouchStart_dyn(); }
		if (HX_FIELD_EQ(inName,"EmulateTouch") ) { return EmulateTouch_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"OnMouseButton") ) { return OnMouseButton_dyn(); }
		if (HX_FIELD_EQ(inName,"OnTouchCancel") ) { return OnTouchCancel_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"OnJoystickStart") ) { return OnJoystickStart_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"OnJoystickDataUpdate") ) { return OnJoystickDataUpdate_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"OnJoystickAnalogUpdate") ) { return OnJoystickAnalogUpdate_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"RequestJoystickVibration") ) { return RequestJoystickVibration_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InputHandler_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"m_joystick") ) { m_joystick=inValue.Cast< ::haxor::input::Joystick >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void InputHandler_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_joystick"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::input::Joystick*/ ,(int)offsetof(InputHandler_obj,m_joystick),HX_CSTRING("m_joystick")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("m_joystick"),
	HX_CSTRING("Update"),
	HX_CSTRING("UpdateInput"),
	HX_CSTRING("OnMouseMove"),
	HX_CSTRING("OnMouseWheel"),
	HX_CSTRING("OnMouseButton"),
	HX_CSTRING("OnKey"),
	HX_CSTRING("OnTouchStart"),
	HX_CSTRING("OnTouchMove"),
	HX_CSTRING("OnTouchCancel"),
	HX_CSTRING("OnTouchEnd"),
	HX_CSTRING("OnJoystickStart"),
	HX_CSTRING("OnJoystickDataUpdate"),
	HX_CSTRING("OnJoystickAnalogUpdate"),
	HX_CSTRING("RequestJoystickVibration"),
	HX_CSTRING("EmulateTouch"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(InputHandler_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(InputHandler_obj::__mClass,"__mClass");
};

#endif

Class InputHandler_obj::__mClass;

void InputHandler_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.input.InputHandler"), hx::TCanCast< InputHandler_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void InputHandler_obj::__boot()
{
}

} // end namespace haxor
} // end namespace input
