#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_core_InputState
#include <haxor/core/InputState.h>
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
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace input{

Void Joystick_obj::__construct()
{
HX_STACK_FRAME("haxor.input.Joystick","new",0x36a0c55e,"haxor.input.Joystick.new","haxor/input/Joystick.hx",98,0x86e4ec50)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(99)
	::haxor::core::InputState st = ::haxor::core::InputState_obj::None;		HX_STACK_VAR(st,"st");
	HX_STACK_LINE(101)
	this->name = HX_CSTRING("");
	HX_STACK_LINE(102)
	this->id = (int)-1;
	HX_STACK_LINE(103)
	this->button = Array_obj< Float >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0);
	HX_STACK_LINE(104)
	this->state = Array_obj< ::Dynamic >::__new().Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st);
	HX_STACK_LINE(105)
	this->hold = Array_obj< Float >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0);
	HX_STACK_LINE(106)
	this->analog = Array_obj< Float >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0);
	HX_STACK_LINE(107)
	::haxor::math::Vector3 _g = ::haxor::math::Vector3_obj::__new(null(),null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(107)
	this->analogLeft = _g;
	HX_STACK_LINE(108)
	::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new(null(),null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(108)
	this->analogRight = _g1;
	HX_STACK_LINE(109)
	this->triggerLeft = 0.0;
	HX_STACK_LINE(110)
	this->triggerRight = 0.0;
	HX_STACK_LINE(111)
	this->m_vibrationLeft = 0.0;
	HX_STACK_LINE(112)
	this->m_vibrationRight = 0.0;
}
;
	return null();
}

//Joystick_obj::~Joystick_obj() { }

Dynamic Joystick_obj::__CreateEmpty() { return  new Joystick_obj; }
hx::ObjectPtr< Joystick_obj > Joystick_obj::__new()
{  hx::ObjectPtr< Joystick_obj > result = new Joystick_obj();
	result->__construct();
	return result;}

Dynamic Joystick_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Joystick_obj > result = new Joystick_obj();
	result->__construct();
	return result;}

Float Joystick_obj::get_vibrationLeft( ){
	HX_STACK_FRAME("haxor.input.Joystick","get_vibrationLeft",0xb511060e,"haxor.input.Joystick.get_vibrationLeft","haxor/input/Joystick.hx",82,0x86e4ec50)
	HX_STACK_THIS(this)
	HX_STACK_LINE(82)
	return this->m_vibrationLeft;
}


HX_DEFINE_DYNAMIC_FUNC0(Joystick_obj,get_vibrationLeft,return )

Float Joystick_obj::set_vibrationLeft( Float v){
	HX_STACK_FRAME("haxor.input.Joystick","set_vibrationLeft",0xd87ede1a,"haxor.input.Joystick.set_vibrationLeft","haxor/input/Joystick.hx",83,0x86e4ec50)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	struct _Function_1_1{
		inline static Float Block( hx::ObjectPtr< ::haxor::input::Joystick_obj > __this,Float &v){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/input/Joystick.hx",83,0x86e4ec50)
			{
				HX_STACK_LINE(83)
				Float p_a = (__this->m_vibrationLeft - v);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(83)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	HX_STACK_LINE(83)
	if (((_Function_1_1::Block(this,v) <= 0.0))){
		HX_STACK_LINE(83)
		return v;
	}
	HX_STACK_LINE(83)
	this->m_vibrationLeft = v;
	HX_STACK_LINE(83)
	::haxor::input::Input_obj::m_handler->RequestJoystickVibration(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(83)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Joystick_obj,set_vibrationLeft,return )

Float Joystick_obj::get_vibrationRight( ){
	HX_STACK_FRAME("haxor.input.Joystick","get_vibrationRight",0x30e153f5,"haxor.input.Joystick.get_vibrationRight","haxor/input/Joystick.hx",90,0x86e4ec50)
	HX_STACK_THIS(this)
	HX_STACK_LINE(90)
	return this->m_vibrationRight;
}


HX_DEFINE_DYNAMIC_FUNC0(Joystick_obj,get_vibrationRight,return )

Float Joystick_obj::set_vibrationRight( Float v){
	HX_STACK_FRAME("haxor.input.Joystick","set_vibrationRight",0x0d908669,"haxor.input.Joystick.set_vibrationRight","haxor/input/Joystick.hx",91,0x86e4ec50)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	struct _Function_1_1{
		inline static Float Block( hx::ObjectPtr< ::haxor::input::Joystick_obj > __this,Float &v){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/input/Joystick.hx",91,0x86e4ec50)
			{
				HX_STACK_LINE(91)
				Float p_a = (__this->m_vibrationRight - v);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(91)
				return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
			}
			return null();
		}
	};
	HX_STACK_LINE(91)
	if (((_Function_1_1::Block(this,v) <= 0.0))){
		HX_STACK_LINE(91)
		return v;
	}
	HX_STACK_LINE(91)
	this->m_vibrationRight = v;
	HX_STACK_LINE(91)
	::haxor::input::Input_obj::m_handler->RequestJoystickVibration(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(91)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Joystick_obj,set_vibrationRight,return )

bool Joystick_obj::Pressed( int p_button){
	HX_STACK_FRAME("haxor.input.Joystick","Pressed",0x58d64680,"haxor.input.Joystick.Pressed","haxor/input/Joystick.hx",120,0x86e4ec50)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_button,"p_button")
	HX_STACK_LINE(120)
	return (bool((this->state->__get(p_button).StaticCast< ::haxor::core::InputState >() == ::haxor::core::InputState_obj::Hold)) || bool((this->state->__get(p_button).StaticCast< ::haxor::core::InputState >() == ::haxor::core::InputState_obj::Down)));
}


HX_DEFINE_DYNAMIC_FUNC1(Joystick_obj,Pressed,return )

bool Joystick_obj::Down( int p_button){
	HX_STACK_FRAME("haxor.input.Joystick","Down",0x7a508dc4,"haxor.input.Joystick.Down","haxor/input/Joystick.hx",127,0x86e4ec50)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_button,"p_button")
	HX_STACK_LINE(127)
	return (this->state->__get(p_button).StaticCast< ::haxor::core::InputState >() == ::haxor::core::InputState_obj::Down);
}


HX_DEFINE_DYNAMIC_FUNC1(Joystick_obj,Down,return )

bool Joystick_obj::Hit( int p_button){
	HX_STACK_FRAME("haxor.input.Joystick","Hit",0x3683f331,"haxor.input.Joystick.Hit","haxor/input/Joystick.hx",134,0x86e4ec50)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_button,"p_button")
	HX_STACK_LINE(134)
	return (this->state->__get(p_button).StaticCast< ::haxor::core::InputState >() == ::haxor::core::InputState_obj::Up);
}


HX_DEFINE_DYNAMIC_FUNC1(Joystick_obj,Hit,return )

::String Joystick_obj::ToString( hx::Null< bool >  __o_p_analog,hx::Null< bool >  __o_p_button,hx::Null< bool >  __o_p_trigger,hx::Null< bool >  __o_p_pad){
bool p_analog = __o_p_analog.Default(true);
bool p_button = __o_p_button.Default(true);
bool p_trigger = __o_p_trigger.Default(true);
bool p_pad = __o_p_pad.Default(true);
	HX_STACK_FRAME("haxor.input.Joystick","ToString",0x2b04bf0e,"haxor.input.Joystick.ToString","haxor/input/Joystick.hx",141,0x86e4ec50)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_analog,"p_analog")
	HX_STACK_ARG(p_button,"p_button")
	HX_STACK_ARG(p_trigger,"p_trigger")
	HX_STACK_ARG(p_pad,"p_pad")
{
		HX_STACK_LINE(142)
		::String s = HX_CSTRING("");		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(143)
		hx::AddEq(s,(HX_CSTRING("J") + this->id));
		HX_STACK_LINE(144)
		if ((p_analog)){
			HX_STACK_LINE(146)
			::String _g = this->analogLeft->ToString((int)1);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(146)
			::String _g1 = (HX_CSTRING(" AL") + _g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(146)
			hx::AddEq(s,_g1);
			HX_STACK_LINE(147)
			::String _g2 = this->analogRight->ToString((int)1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(147)
			::String _g3 = (HX_CSTRING(" AR") + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(147)
			hx::AddEq(s,_g3);
		}
		HX_STACK_LINE(150)
		if ((p_button)){
			HX_STACK_LINE(152)
			::String _g4;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(152)
			if ((this->Pressed(::haxor::input::KeyCode_obj::ButtonA))){
				HX_STACK_LINE(152)
				_g4 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(152)
				_g4 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(152)
			::String _g5 = (HX_CSTRING(" A[") + _g4);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(152)
			hx::AddEq(s,_g5);
			HX_STACK_LINE(153)
			::String _g6;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(153)
			if ((this->Pressed(::haxor::input::KeyCode_obj::ButtonB))){
				HX_STACK_LINE(153)
				_g6 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(153)
				_g6 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(153)
			::String _g7 = (HX_CSTRING(" B[") + _g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(153)
			hx::AddEq(s,_g7);
			HX_STACK_LINE(154)
			::String _g8;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(154)
			if ((this->Pressed(::haxor::input::KeyCode_obj::ButtonX))){
				HX_STACK_LINE(154)
				_g8 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(154)
				_g8 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(154)
			::String _g9 = (HX_CSTRING(" X[") + _g8);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(154)
			hx::AddEq(s,_g9);
			HX_STACK_LINE(155)
			::String _g10;		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(155)
			if ((this->Pressed(::haxor::input::KeyCode_obj::ButtonY))){
				HX_STACK_LINE(155)
				_g10 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(155)
				_g10 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(155)
			::String _g11 = (HX_CSTRING(" Y[") + _g10);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(155)
			hx::AddEq(s,_g11);
			HX_STACK_LINE(156)
			::String _g12;		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(156)
			if ((this->Pressed(::haxor::input::KeyCode_obj::LeftShoulder))){
				HX_STACK_LINE(156)
				_g12 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(156)
				_g12 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(156)
			::String _g13 = (HX_CSTRING(" L[") + _g12);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(156)
			hx::AddEq(s,_g13);
			HX_STACK_LINE(157)
			::String _g14;		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(157)
			if ((this->Pressed(::haxor::input::KeyCode_obj::RightShoulder))){
				HX_STACK_LINE(157)
				_g14 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(157)
				_g14 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(157)
			::String _g15 = (HX_CSTRING(" R[") + _g14);		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(157)
			hx::AddEq(s,_g15);
			HX_STACK_LINE(158)
			::String _g16;		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(158)
			if ((this->Pressed(::haxor::input::KeyCode_obj::LeftShoulderBottom))){
				HX_STACK_LINE(158)
				_g16 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(158)
				_g16 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(158)
			::String _g17 = (HX_CSTRING(" LB[") + _g16);		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(158)
			hx::AddEq(s,_g17);
			HX_STACK_LINE(159)
			::String _g18;		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(159)
			if ((this->Pressed(::haxor::input::KeyCode_obj::RightShoulderBottom))){
				HX_STACK_LINE(159)
				_g18 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(159)
				_g18 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(159)
			::String _g19 = (HX_CSTRING(" RB[") + _g18);		HX_STACK_VAR(_g19,"_g19");
			HX_STACK_LINE(159)
			hx::AddEq(s,_g19);
			HX_STACK_LINE(160)
			::String _g20;		HX_STACK_VAR(_g20,"_g20");
			HX_STACK_LINE(160)
			if ((this->Pressed(::haxor::input::KeyCode_obj::ButtonStart))){
				HX_STACK_LINE(160)
				_g20 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(160)
				_g20 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(160)
			::String _g21 = (HX_CSTRING(" Start[") + _g20);		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(160)
			hx::AddEq(s,_g21);
			HX_STACK_LINE(161)
			::String _g22;		HX_STACK_VAR(_g22,"_g22");
			HX_STACK_LINE(161)
			if ((this->Pressed(::haxor::input::KeyCode_obj::ButtonSelect))){
				HX_STACK_LINE(161)
				_g22 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(161)
				_g22 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(161)
			::String _g23 = (HX_CSTRING(" Select[") + _g22);		HX_STACK_VAR(_g23,"_g23");
			HX_STACK_LINE(161)
			hx::AddEq(s,_g23);
		}
		HX_STACK_LINE(164)
		if ((p_pad)){
			HX_STACK_LINE(166)
			::String _g24;		HX_STACK_VAR(_g24,"_g24");
			HX_STACK_LINE(166)
			if ((this->Pressed(::haxor::input::KeyCode_obj::PadLeft))){
				HX_STACK_LINE(166)
				_g24 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(166)
				_g24 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(166)
			::String _g25 = (HX_CSTRING(" PL[") + _g24);		HX_STACK_VAR(_g25,"_g25");
			HX_STACK_LINE(166)
			hx::AddEq(s,_g25);
			HX_STACK_LINE(167)
			::String _g26;		HX_STACK_VAR(_g26,"_g26");
			HX_STACK_LINE(167)
			if ((this->Pressed(::haxor::input::KeyCode_obj::PadRight))){
				HX_STACK_LINE(167)
				_g26 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(167)
				_g26 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(167)
			::String _g27 = (HX_CSTRING(" PR[") + _g26);		HX_STACK_VAR(_g27,"_g27");
			HX_STACK_LINE(167)
			hx::AddEq(s,_g27);
			HX_STACK_LINE(168)
			::String _g28;		HX_STACK_VAR(_g28,"_g28");
			HX_STACK_LINE(168)
			if ((this->Pressed(::haxor::input::KeyCode_obj::PadTop))){
				HX_STACK_LINE(168)
				_g28 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(168)
				_g28 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(168)
			::String _g29 = (HX_CSTRING(" PU[") + _g28);		HX_STACK_VAR(_g29,"_g29");
			HX_STACK_LINE(168)
			hx::AddEq(s,_g29);
			HX_STACK_LINE(169)
			::String _g30;		HX_STACK_VAR(_g30,"_g30");
			HX_STACK_LINE(169)
			if ((this->Pressed(::haxor::input::KeyCode_obj::PadBottom))){
				HX_STACK_LINE(169)
				_g30 = HX_CSTRING("1]");
			}
			else{
				HX_STACK_LINE(169)
				_g30 = HX_CSTRING("0]");
			}
			HX_STACK_LINE(169)
			::String _g31 = (HX_CSTRING(" PD[") + _g30);		HX_STACK_VAR(_g31,"_g31");
			HX_STACK_LINE(169)
			hx::AddEq(s,_g31);
		}
		HX_STACK_LINE(172)
		if ((p_trigger)){
			HX_STACK_LINE(174)
			Float _g33;		HX_STACK_VAR(_g33,"_g33");
			HX_STACK_LINE(174)
			{
				HX_STACK_LINE(174)
				Float d = ::Math_obj::pow((int)10,(int)1);		HX_STACK_VAR(d,"d");
				HX_STACK_LINE(174)
				Float _g32;		HX_STACK_VAR(_g32,"_g32");
				HX_STACK_LINE(174)
				{
					HX_STACK_LINE(174)
					Float p_v = (this->triggerLeft * d);		HX_STACK_VAR(p_v,"p_v");
					HX_STACK_LINE(174)
					_g32 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
				}
				HX_STACK_LINE(174)
				_g33 = (Float(_g32) / Float(d));
			}
			HX_STACK_LINE(174)
			::String _g34 = (HX_CSTRING(" TL[") + _g33);		HX_STACK_VAR(_g34,"_g34");
			HX_STACK_LINE(174)
			::String _g35 = (_g34 + HX_CSTRING("]"));		HX_STACK_VAR(_g35,"_g35");
			HX_STACK_LINE(174)
			hx::AddEq(s,_g35);
			HX_STACK_LINE(175)
			Float _g37;		HX_STACK_VAR(_g37,"_g37");
			HX_STACK_LINE(175)
			{
				HX_STACK_LINE(175)
				Float d = ::Math_obj::pow((int)10,(int)1);		HX_STACK_VAR(d,"d");
				HX_STACK_LINE(175)
				Float _g36;		HX_STACK_VAR(_g36,"_g36");
				HX_STACK_LINE(175)
				{
					HX_STACK_LINE(175)
					Float p_v = (this->triggerRight * d);		HX_STACK_VAR(p_v,"p_v");
					HX_STACK_LINE(175)
					_g36 = ::Std_obj::_int((p_v + ((  (((p_v < (int)0))) ? Float(-0.5) : Float(0.5) ))));
				}
				HX_STACK_LINE(175)
				_g37 = (Float(_g36) / Float(d));
			}
			HX_STACK_LINE(175)
			::String _g38 = (HX_CSTRING(" TR[") + _g37);		HX_STACK_VAR(_g38,"_g38");
			HX_STACK_LINE(175)
			::String _g39 = (_g38 + HX_CSTRING("]"));		HX_STACK_VAR(_g39,"_g39");
			HX_STACK_LINE(175)
			hx::AddEq(s,_g39);
		}
		HX_STACK_LINE(177)
		return s;
	}
}


HX_DEFINE_DYNAMIC_FUNC4(Joystick_obj,ToString,return )

Array< Float > Joystick_obj::analogBias;

Float Joystick_obj::buttonBias;

bool Joystick_obj::available;


Joystick_obj::Joystick_obj()
{
}

void Joystick_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Joystick);
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(button,"button");
	HX_MARK_MEMBER_NAME(state,"state");
	HX_MARK_MEMBER_NAME(hold,"hold");
	HX_MARK_MEMBER_NAME(analog,"analog");
	HX_MARK_MEMBER_NAME(analogLeft,"analogLeft");
	HX_MARK_MEMBER_NAME(analogRight,"analogRight");
	HX_MARK_MEMBER_NAME(triggerLeft,"triggerLeft");
	HX_MARK_MEMBER_NAME(triggerRight,"triggerRight");
	HX_MARK_MEMBER_NAME(m_vibrationLeft,"m_vibrationLeft");
	HX_MARK_MEMBER_NAME(m_vibrationRight,"m_vibrationRight");
	HX_MARK_END_CLASS();
}

void Joystick_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(button,"button");
	HX_VISIT_MEMBER_NAME(state,"state");
	HX_VISIT_MEMBER_NAME(hold,"hold");
	HX_VISIT_MEMBER_NAME(analog,"analog");
	HX_VISIT_MEMBER_NAME(analogLeft,"analogLeft");
	HX_VISIT_MEMBER_NAME(analogRight,"analogRight");
	HX_VISIT_MEMBER_NAME(triggerLeft,"triggerLeft");
	HX_VISIT_MEMBER_NAME(triggerRight,"triggerRight");
	HX_VISIT_MEMBER_NAME(m_vibrationLeft,"m_vibrationLeft");
	HX_VISIT_MEMBER_NAME(m_vibrationRight,"m_vibrationRight");
}

Dynamic Joystick_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"Hit") ) { return Hit_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		if (HX_FIELD_EQ(inName,"hold") ) { return hold; }
		if (HX_FIELD_EQ(inName,"Down") ) { return Down_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"button") ) { return button; }
		if (HX_FIELD_EQ(inName,"analog") ) { return analog; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Pressed") ) { return Pressed_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ToString") ) { return ToString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"available") ) { return available; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"analogBias") ) { return analogBias; }
		if (HX_FIELD_EQ(inName,"buttonBias") ) { return buttonBias; }
		if (HX_FIELD_EQ(inName,"analogLeft") ) { return analogLeft; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"analogRight") ) { return analogRight; }
		if (HX_FIELD_EQ(inName,"triggerLeft") ) { return triggerLeft; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"triggerRight") ) { return triggerRight; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"vibrationLeft") ) { return get_vibrationLeft(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"vibrationRight") ) { return get_vibrationRight(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_vibrationLeft") ) { return m_vibrationLeft; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_vibrationRight") ) { return m_vibrationRight; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_vibrationLeft") ) { return get_vibrationLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"set_vibrationLeft") ) { return set_vibrationLeft_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"get_vibrationRight") ) { return get_vibrationRight_dyn(); }
		if (HX_FIELD_EQ(inName,"set_vibrationRight") ) { return set_vibrationRight_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Joystick_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"hold") ) { hold=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"button") ) { button=inValue.Cast< Array< Float > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"analog") ) { analog=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"available") ) { available=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"analogBias") ) { analogBias=inValue.Cast< Array< Float > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"buttonBias") ) { buttonBias=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"analogLeft") ) { analogLeft=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"analogRight") ) { analogRight=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"triggerLeft") ) { triggerLeft=inValue.Cast< Float >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"triggerRight") ) { triggerRight=inValue.Cast< Float >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"vibrationLeft") ) { return set_vibrationLeft(inValue); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"vibrationRight") ) { return set_vibrationRight(inValue); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_vibrationLeft") ) { m_vibrationLeft=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"m_vibrationRight") ) { m_vibrationRight=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Joystick_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("button"));
	outFields->push(HX_CSTRING("state"));
	outFields->push(HX_CSTRING("hold"));
	outFields->push(HX_CSTRING("analog"));
	outFields->push(HX_CSTRING("analogLeft"));
	outFields->push(HX_CSTRING("analogRight"));
	outFields->push(HX_CSTRING("triggerLeft"));
	outFields->push(HX_CSTRING("triggerRight"));
	outFields->push(HX_CSTRING("vibrationLeft"));
	outFields->push(HX_CSTRING("m_vibrationLeft"));
	outFields->push(HX_CSTRING("vibrationRight"));
	outFields->push(HX_CSTRING("m_vibrationRight"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("analogBias"),
	HX_CSTRING("buttonBias"),
	HX_CSTRING("available"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(Joystick_obj,name),HX_CSTRING("name")},
	{hx::fsInt,(int)offsetof(Joystick_obj,id),HX_CSTRING("id")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(Joystick_obj,button),HX_CSTRING("button")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Joystick_obj,state),HX_CSTRING("state")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(Joystick_obj,hold),HX_CSTRING("hold")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(Joystick_obj,analog),HX_CSTRING("analog")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Joystick_obj,analogLeft),HX_CSTRING("analogLeft")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(Joystick_obj,analogRight),HX_CSTRING("analogRight")},
	{hx::fsFloat,(int)offsetof(Joystick_obj,triggerLeft),HX_CSTRING("triggerLeft")},
	{hx::fsFloat,(int)offsetof(Joystick_obj,triggerRight),HX_CSTRING("triggerRight")},
	{hx::fsFloat,(int)offsetof(Joystick_obj,m_vibrationLeft),HX_CSTRING("m_vibrationLeft")},
	{hx::fsFloat,(int)offsetof(Joystick_obj,m_vibrationRight),HX_CSTRING("m_vibrationRight")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("name"),
	HX_CSTRING("id"),
	HX_CSTRING("button"),
	HX_CSTRING("state"),
	HX_CSTRING("hold"),
	HX_CSTRING("analog"),
	HX_CSTRING("analogLeft"),
	HX_CSTRING("analogRight"),
	HX_CSTRING("triggerLeft"),
	HX_CSTRING("triggerRight"),
	HX_CSTRING("get_vibrationLeft"),
	HX_CSTRING("set_vibrationLeft"),
	HX_CSTRING("m_vibrationLeft"),
	HX_CSTRING("get_vibrationRight"),
	HX_CSTRING("set_vibrationRight"),
	HX_CSTRING("m_vibrationRight"),
	HX_CSTRING("Pressed"),
	HX_CSTRING("Down"),
	HX_CSTRING("Hit"),
	HX_CSTRING("ToString"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Joystick_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Joystick_obj::analogBias,"analogBias");
	HX_MARK_MEMBER_NAME(Joystick_obj::buttonBias,"buttonBias");
	HX_MARK_MEMBER_NAME(Joystick_obj::available,"available");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Joystick_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Joystick_obj::analogBias,"analogBias");
	HX_VISIT_MEMBER_NAME(Joystick_obj::buttonBias,"buttonBias");
	HX_VISIT_MEMBER_NAME(Joystick_obj::available,"available");
};

#endif

Class Joystick_obj::__mClass;

void Joystick_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.input.Joystick"), hx::TCanCast< Joystick_obj> ,sStaticFields,sMemberFields,
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

void Joystick_obj::__boot()
{
	analogBias= Array_obj< Float >::__new().Add(0.1).Add(0.9);
	buttonBias= 0.9;
	available= false;
}

} // end namespace haxor
} // end namespace input
