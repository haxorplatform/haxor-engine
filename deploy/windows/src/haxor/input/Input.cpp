#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_haxor_core_InputState
#include <haxor/core/InputState.h>
#endif
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
#endif
#ifndef INCLUDED_haxor_input_Input
#include <haxor/input/Input.h>
#endif
#ifndef INCLUDED_haxor_input_Joystick
#include <haxor/input/Joystick.h>
#endif
#ifndef INCLUDED_haxor_input_Touch
#include <haxor/input/Touch.h>
#endif
#ifndef INCLUDED_haxor_math_Vector2
#include <haxor/math/Vector2.h>
#endif
namespace haxor{
namespace input{

Void Input_obj::__construct()
{
	return null();
}

//Input_obj::~Input_obj() { }

Dynamic Input_obj::__CreateEmpty() { return  new Input_obj; }
hx::ObjectPtr< Input_obj > Input_obj::__new()
{  hx::ObjectPtr< Input_obj > result = new Input_obj();
	result->__construct();
	return result;}

Dynamic Input_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Input_obj > result = new Input_obj();
	result->__construct();
	return result;}

::haxe::ds::IntMap Input_obj::m_state;

::haxe::ds::IntMap Input_obj::m_hold;

Array< bool > Input_obj::m_down;

Array< int > Input_obj::m_active;

Array< ::Dynamic > Input_obj::get_touch( ){
	HX_STACK_FRAME("haxor.input.Input","get_touch",0x7b9f6b02,"haxor.input.Input.get_touch","haxor/input/Input.hx",42,0xee96c766)
	HX_STACK_LINE(42)
	return ::haxor::input::Input_obj::m_touch;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Input_obj,get_touch,return )

Array< ::Dynamic > Input_obj::m_touch;

Array< ::Dynamic > Input_obj::get_joystick( ){
	HX_STACK_FRAME("haxor.input.Input","get_joystick",0xa904b959,"haxor.input.Input.get_joystick","haxor/input/Input.hx",49,0xee96c766)
	HX_STACK_LINE(49)
	return ::haxor::input::Input_obj::m_joysticks;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Input_obj,get_joystick,return )

Array< ::Dynamic > Input_obj::m_joysticks;

Array< ::Dynamic > Input_obj::m_api_joystick;

bool Input_obj::get_multitouch( ){
	HX_STACK_FRAME("haxor.input.Input","get_multitouch",0xeaa7f083,"haxor.input.Input.get_multitouch","haxor/input/Input.hx",58,0xee96c766)
	HX_STACK_LINE(58)
	return ::haxor::input::Input_obj::m_multitouch;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Input_obj,get_multitouch,return )

bool Input_obj::m_multitouch;

::haxor::math::Vector2 Input_obj::mouse;

::haxor::math::Vector2 Input_obj::deltaMouse;

::haxor::math::Vector2 Input_obj::relativeMouse;

Float Input_obj::wheel;

bool Input_obj::scroll;

::haxor::core::InputState Input_obj::GetInputState( int p_code){
	HX_STACK_FRAME("haxor.input.Input","GetInputState",0x48afc6a9,"haxor.input.Input.GetInputState","haxor/input/Input.hx",93,0xee96c766)
	HX_STACK_ARG(p_code,"p_code")
	HX_STACK_LINE(93)
	return ::haxor::input::Input_obj::m_state->get(p_code);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Input_obj,GetInputState,return )

bool Input_obj::Pressed( int p_code){
	HX_STACK_FRAME("haxor.input.Input","Pressed",0x3d791e6e,"haxor.input.Input.Pressed","haxor/input/Input.hx",102,0xee96c766)
	HX_STACK_ARG(p_code,"p_code")
	HX_STACK_LINE(103)
	::haxor::core::InputState s = ::haxor::input::Input_obj::GetInputState(p_code);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(104)
	return (bool((s == ::haxor::core::InputState_obj::Down)) || bool((s == ::haxor::core::InputState_obj::Hold)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Input_obj,Pressed,return )

bool Input_obj::Down( int p_code){
	HX_STACK_FRAME("haxor.input.Input","Down",0xbbbf9516,"haxor.input.Input.Down","haxor/input/Input.hx",113,0xee96c766)
	HX_STACK_ARG(p_code,"p_code")
	HX_STACK_LINE(114)
	::haxor::core::InputState s = ::haxor::input::Input_obj::GetInputState(p_code);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(115)
	return (s == ::haxor::core::InputState_obj::Down);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Input_obj,Down,return )

bool Input_obj::Hit( int p_code){
	HX_STACK_FRAME("haxor.input.Input","Hit",0x4dc4bc1f,"haxor.input.Input.Hit","haxor/input/Input.hx",124,0xee96c766)
	HX_STACK_ARG(p_code,"p_code")
	HX_STACK_LINE(125)
	::haxor::core::InputState s = ::haxor::input::Input_obj::GetInputState(p_code);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(126)
	return (s == ::haxor::core::InputState_obj::Up);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Input_obj,Hit,return )

Float Input_obj::GetHoldTime( int p_code){
	HX_STACK_FRAME("haxor.input.Input","GetHoldTime",0x1c85b16e,"haxor.input.Input.GetHoldTime","haxor/input/Input.hx",134,0xee96c766)
	HX_STACK_ARG(p_code,"p_code")
	HX_STACK_LINE(134)
	return ::haxor::input::Input_obj::m_hold->get(p_code);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Input_obj,GetHoldTime,return )

Void Input_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.input.Input","Initialize",0x0a414d04,"haxor.input.Input.Initialize","haxor/input/Input.hx",141,0xee96c766)
		HX_STACK_LINE(142)
		::haxe::ds::IntMap _g = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(142)
		::haxor::input::Input_obj::m_state = _g;
		HX_STACK_LINE(143)
		::haxe::ds::IntMap _g1 = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(143)
		::haxor::input::Input_obj::m_hold = _g1;
		HX_STACK_LINE(144)
		Array< int > _g2 = Array_obj< int >::__new();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(144)
		::haxor::input::Input_obj::m_active = _g2;
		HX_STACK_LINE(145)
		Array< bool > _g3 = Array_obj< bool >::__new();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(145)
		::haxor::input::Input_obj::m_down = _g3;
		HX_STACK_LINE(146)
		::haxor::input::Input_obj::m_touch = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(148)
		{
			HX_STACK_LINE(148)
			int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(148)
			while((true)){
				HX_STACK_LINE(148)
				if ((!(((_g4 < (int)256))))){
					HX_STACK_LINE(148)
					break;
				}
				HX_STACK_LINE(148)
				int i = (_g4)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(150)
				::haxor::input::Input_obj::m_state->set(i,::haxor::core::InputState_obj::None);
				HX_STACK_LINE(151)
				::haxor::input::Input_obj::m_hold->set(i,(int)0);
				HX_STACK_LINE(152)
				::haxor::input::Input_obj::m_down->push(false);
			}
		}
		HX_STACK_LINE(155)
		::haxor::input::Input_obj::m_joysticks = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(156)
		::haxor::input::Input_obj::m_api_joystick = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(157)
		{
			HX_STACK_LINE(157)
			int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(157)
			while((true)){
				HX_STACK_LINE(157)
				if ((!(((_g4 < (int)10))))){
					HX_STACK_LINE(157)
					break;
				}
				HX_STACK_LINE(157)
				int i = (_g4)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(159)
				::haxor::input::Joystick _g41 = ::haxor::input::Joystick_obj::__new();		HX_STACK_VAR(_g41,"_g41");
				HX_STACK_LINE(159)
				::haxor::input::Input_obj::m_api_joystick->push(_g41);
			}
		}
		HX_STACK_LINE(162)
		::haxor::math::Vector2 _g5 = ::haxor::math::Vector2_obj::__new(null(),null());		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(162)
		::haxor::input::Input_obj::mouse = _g5;
		HX_STACK_LINE(163)
		::haxor::math::Vector2 _g6 = ::haxor::math::Vector2_obj::__new(null(),null());		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(163)
		::haxor::input::Input_obj::deltaMouse = _g6;
		HX_STACK_LINE(164)
		::haxor::math::Vector2 _g7 = ::haxor::math::Vector2_obj::__new(null(),null());		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(164)
		::haxor::input::Input_obj::relativeMouse = _g7;
		HX_STACK_LINE(166)
		::haxor::core::Console_obj::Log(HX_CSTRING("Input> Initialize"),(int)4);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Input_obj,Initialize,(void))

Void Input_obj::UpdateTouchFSM( ){
{
		HX_STACK_FRAME("haxor.input.Input","UpdateTouchFSM",0x038468de,"haxor.input.Input.UpdateTouchFSM","haxor/input/Input.hx",172,0xee96c766)
		HX_STACK_LINE(172)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(172)
		int _g = ::haxor::input::Input_obj::m_touch->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(172)
		while((true)){
			HX_STACK_LINE(172)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(172)
				break;
			}
			HX_STACK_LINE(172)
			int j = (_g1)++;		HX_STACK_VAR(j,"j");
			HX_STACK_LINE(172)
			::haxor::input::Input_obj::TouchFSM(::haxor::input::Input_obj::m_touch->__get(j).StaticCast< ::haxor::input::Touch >());
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Input_obj,UpdateTouchFSM,(void))

Void Input_obj::UpdateInput( ){
{
		HX_STACK_FRAME("haxor.input.Input","UpdateInput",0x5b884f0d,"haxor.input.Input.UpdateInput","haxor/input/Input.hx",177,0xee96c766)
		HX_STACK_LINE(177)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(177)
		int _g = ::haxor::input::Input_obj::m_active->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(177)
		while((true)){
			HX_STACK_LINE(177)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(177)
				break;
			}
			HX_STACK_LINE(177)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(177)
			::haxor::input::Input_obj::UpdateInputState(::haxor::input::Input_obj::m_active->__get(i),::haxor::input::Input_obj::m_down->__get(::haxor::input::Input_obj::m_active->__get(i)));
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Input_obj,UpdateInput,(void))

Void Input_obj::ResetTouchDownFlag( ){
{
		HX_STACK_FRAME("haxor.input.Input","ResetTouchDownFlag",0xda82f472,"haxor.input.Input.ResetTouchDownFlag","haxor/input/Input.hx",182,0xee96c766)
		HX_STACK_LINE(182)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(182)
		int _g = ::haxor::input::Input_obj::m_touch->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(182)
		while((true)){
			HX_STACK_LINE(182)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(182)
				break;
			}
			HX_STACK_LINE(182)
			int j = (_g1)++;		HX_STACK_VAR(j,"j");
			HX_STACK_LINE(182)
			::haxor::input::Input_obj::m_touch->__get(j).StaticCast< ::haxor::input::Touch >()->m_down = false;
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Input_obj,ResetTouchDownFlag,(void))

Void Input_obj::TouchFSM( ::haxor::input::Touch t){
{
		HX_STACK_FRAME("haxor.input.Input","TouchFSM",0x1c7a76b5,"haxor.input.Input.TouchFSM","haxor/input/Input.hx",189,0xee96c766)
		HX_STACK_ARG(t,"t")
		HX_STACK_LINE(190)
		if (((t == null()))){
			HX_STACK_LINE(190)
			return null();
		}
		HX_STACK_LINE(191)
		::haxor::core::InputState current = t->state;		HX_STACK_VAR(current,"current");
		HX_STACK_LINE(192)
		bool d = t->m_down;		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(193)
		if (((current == ::haxor::core::InputState_obj::Up))){
			HX_STACK_LINE(193)
			::haxor::input::Input_obj::m_touch->remove(t);
		}
		HX_STACK_LINE(194)
		if (((current == ::haxor::core::InputState_obj::Hold))){
			HX_STACK_LINE(194)
			hx::AddEq(t->hold,::haxor::core::Time_obj::m_delta);
		}
		HX_STACK_LINE(195)
		::haxor::core::InputState _g = ::haxor::input::Input_obj::InputStateFSM(current,d);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(195)
		t->state = _g;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Input_obj,TouchFSM,(void))

Void Input_obj::UpdateInputState( int p_code,bool p_is_down){
{
		HX_STACK_FRAME("haxor.input.Input","UpdateInputState",0x52d5e7c4,"haxor.input.Input.UpdateInputState","haxor/input/Input.hx",204,0xee96c766)
		HX_STACK_ARG(p_code,"p_code")
		HX_STACK_ARG(p_is_down,"p_is_down")
		HX_STACK_LINE(205)
		::haxor::core::InputState current = ::haxor::input::Input_obj::m_state->get(p_code);		HX_STACK_VAR(current,"current");
		HX_STACK_LINE(206)
		if (((current == null()))){
			HX_STACK_LINE(206)
			current = ::haxor::core::InputState_obj::None;
		}
		HX_STACK_LINE(207)
		::haxor::core::InputState next = current;		HX_STACK_VAR(next,"next");
		HX_STACK_LINE(208)
		bool d0 = ::haxor::input::Input_obj::m_down->__get(p_code);		HX_STACK_VAR(d0,"d0");
		HX_STACK_LINE(209)
		bool d = ::haxor::input::Input_obj::m_down[p_code] = p_is_down;		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(211)
		if ((!(d0))){
			HX_STACK_LINE(211)
			if ((d)){
				HX_STACK_LINE(211)
				::haxor::input::Input_obj::m_active->push(p_code);
			}
		}
		HX_STACK_LINE(212)
		if ((!(d))){
			HX_STACK_LINE(212)
			if ((d0)){
				HX_STACK_LINE(212)
				return null();
			}
		}
		HX_STACK_LINE(214)
		if (((current == ::haxor::core::InputState_obj::Up))){
			HX_STACK_LINE(216)
			::haxor::input::Input_obj::m_hold->set(p_code,(int)0);
			HX_STACK_LINE(217)
			::haxor::input::Input_obj::m_active->remove(p_code);
		}
		HX_STACK_LINE(220)
		if (((current == ::haxor::core::InputState_obj::Hold))){
			HX_STACK_LINE(222)
			Float h = ::haxor::input::Input_obj::m_hold->get(p_code);		HX_STACK_VAR(h,"h");
			HX_STACK_LINE(223)
			::haxor::input::Input_obj::m_hold->set(p_code,(h + ::haxor::core::Time_obj::m_delta));
		}
		HX_STACK_LINE(226)
		::haxor::core::InputState _g = ::haxor::input::Input_obj::InputStateFSM(current,d);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(226)
		next = _g;
		HX_STACK_LINE(228)
		if (((current != next))){
			HX_STACK_LINE(228)
			::haxor::input::Input_obj::m_state->set(p_code,next);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Input_obj,UpdateInputState,(void))

::haxor::core::InputState Input_obj::InputStateFSM( ::haxor::core::InputState p_current,bool p_is_down){
	HX_STACK_FRAME("haxor.input.Input","InputStateFSM",0xd80d17e5,"haxor.input.Input.InputStateFSM","haxor/input/Input.hx",238,0xee96c766)
	HX_STACK_ARG(p_current,"p_current")
	HX_STACK_ARG(p_is_down,"p_is_down")
	HX_STACK_LINE(239)
	::haxor::core::InputState current = p_current;		HX_STACK_VAR(current,"current");
	HX_STACK_LINE(240)
	::haxor::core::InputState next = current;		HX_STACK_VAR(next,"next");
	HX_STACK_LINE(241)
	bool d = p_is_down;		HX_STACK_VAR(d,"d");
	HX_STACK_LINE(242)
	switch( (int)(current->__Index())){
		case (int)0: {
			HX_STACK_LINE(245)
			if ((d)){
				HX_STACK_LINE(245)
				next = ::haxor::core::InputState_obj::Down;
			}
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(247)
			if ((!(d))){
				HX_STACK_LINE(247)
				next = ::haxor::core::InputState_obj::Up;
			}
			HX_STACK_LINE(248)
			next = ::haxor::core::InputState_obj::Hold;
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(251)
			next = ::haxor::core::InputState_obj::None;
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(254)
			if ((!(d))){
				HX_STACK_LINE(254)
				next = ::haxor::core::InputState_obj::Up;
			}
		}
		;break;
	}
	HX_STACK_LINE(256)
	return next;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Input_obj,InputStateFSM,return )


Input_obj::Input_obj()
{
}

Dynamic Input_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"Hit") ) { return Hit_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Down") ) { return Down_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"touch") ) { return get_touch(); }
		if (HX_FIELD_EQ(inName,"mouse") ) { return mouse; }
		if (HX_FIELD_EQ(inName,"wheel") ) { return wheel; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_hold") ) { return m_hold; }
		if (HX_FIELD_EQ(inName,"m_down") ) { return m_down; }
		if (HX_FIELD_EQ(inName,"scroll") ) { return scroll; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_state") ) { return m_state; }
		if (HX_FIELD_EQ(inName,"m_touch") ) { return m_touch; }
		if (HX_FIELD_EQ(inName,"Pressed") ) { return Pressed_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_active") ) { return m_active; }
		if (HX_FIELD_EQ(inName,"joystick") ) { return get_joystick(); }
		if (HX_FIELD_EQ(inName,"TouchFSM") ) { return TouchFSM_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_touch") ) { return get_touch_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"multitouch") ) { return get_multitouch(); }
		if (HX_FIELD_EQ(inName,"deltaMouse") ) { return deltaMouse; }
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_joysticks") ) { return m_joysticks; }
		if (HX_FIELD_EQ(inName,"GetHoldTime") ) { return GetHoldTime_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateInput") ) { return UpdateInput_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_joystick") ) { return get_joystick_dyn(); }
		if (HX_FIELD_EQ(inName,"m_multitouch") ) { return m_multitouch; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"relativeMouse") ) { return relativeMouse; }
		if (HX_FIELD_EQ(inName,"GetInputState") ) { return GetInputState_dyn(); }
		if (HX_FIELD_EQ(inName,"InputStateFSM") ) { return InputStateFSM_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_api_joystick") ) { return m_api_joystick; }
		if (HX_FIELD_EQ(inName,"get_multitouch") ) { return get_multitouch_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateTouchFSM") ) { return UpdateTouchFSM_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"UpdateInputState") ) { return UpdateInputState_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"ResetTouchDownFlag") ) { return ResetTouchDownFlag_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Input_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"mouse") ) { mouse=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"wheel") ) { wheel=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_hold") ) { m_hold=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_down") ) { m_down=inValue.Cast< Array< bool > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scroll") ) { scroll=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_state") ) { m_state=inValue.Cast< ::haxe::ds::IntMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_touch") ) { m_touch=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_active") ) { m_active=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"deltaMouse") ) { deltaMouse=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_joysticks") ) { m_joysticks=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_multitouch") ) { m_multitouch=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"relativeMouse") ) { relativeMouse=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_api_joystick") ) { m_api_joystick=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Input_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_state"),
	HX_CSTRING("m_hold"),
	HX_CSTRING("m_down"),
	HX_CSTRING("m_active"),
	HX_CSTRING("get_touch"),
	HX_CSTRING("m_touch"),
	HX_CSTRING("get_joystick"),
	HX_CSTRING("m_joysticks"),
	HX_CSTRING("m_api_joystick"),
	HX_CSTRING("get_multitouch"),
	HX_CSTRING("m_multitouch"),
	HX_CSTRING("mouse"),
	HX_CSTRING("deltaMouse"),
	HX_CSTRING("relativeMouse"),
	HX_CSTRING("wheel"),
	HX_CSTRING("scroll"),
	HX_CSTRING("GetInputState"),
	HX_CSTRING("Pressed"),
	HX_CSTRING("Down"),
	HX_CSTRING("Hit"),
	HX_CSTRING("GetHoldTime"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("UpdateTouchFSM"),
	HX_CSTRING("UpdateInput"),
	HX_CSTRING("ResetTouchDownFlag"),
	HX_CSTRING("TouchFSM"),
	HX_CSTRING("UpdateInputState"),
	HX_CSTRING("InputStateFSM"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Input_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Input_obj::m_state,"m_state");
	HX_MARK_MEMBER_NAME(Input_obj::m_hold,"m_hold");
	HX_MARK_MEMBER_NAME(Input_obj::m_down,"m_down");
	HX_MARK_MEMBER_NAME(Input_obj::m_active,"m_active");
	HX_MARK_MEMBER_NAME(Input_obj::m_touch,"m_touch");
	HX_MARK_MEMBER_NAME(Input_obj::m_joysticks,"m_joysticks");
	HX_MARK_MEMBER_NAME(Input_obj::m_api_joystick,"m_api_joystick");
	HX_MARK_MEMBER_NAME(Input_obj::m_multitouch,"m_multitouch");
	HX_MARK_MEMBER_NAME(Input_obj::mouse,"mouse");
	HX_MARK_MEMBER_NAME(Input_obj::deltaMouse,"deltaMouse");
	HX_MARK_MEMBER_NAME(Input_obj::relativeMouse,"relativeMouse");
	HX_MARK_MEMBER_NAME(Input_obj::wheel,"wheel");
	HX_MARK_MEMBER_NAME(Input_obj::scroll,"scroll");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Input_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Input_obj::m_state,"m_state");
	HX_VISIT_MEMBER_NAME(Input_obj::m_hold,"m_hold");
	HX_VISIT_MEMBER_NAME(Input_obj::m_down,"m_down");
	HX_VISIT_MEMBER_NAME(Input_obj::m_active,"m_active");
	HX_VISIT_MEMBER_NAME(Input_obj::m_touch,"m_touch");
	HX_VISIT_MEMBER_NAME(Input_obj::m_joysticks,"m_joysticks");
	HX_VISIT_MEMBER_NAME(Input_obj::m_api_joystick,"m_api_joystick");
	HX_VISIT_MEMBER_NAME(Input_obj::m_multitouch,"m_multitouch");
	HX_VISIT_MEMBER_NAME(Input_obj::mouse,"mouse");
	HX_VISIT_MEMBER_NAME(Input_obj::deltaMouse,"deltaMouse");
	HX_VISIT_MEMBER_NAME(Input_obj::relativeMouse,"relativeMouse");
	HX_VISIT_MEMBER_NAME(Input_obj::wheel,"wheel");
	HX_VISIT_MEMBER_NAME(Input_obj::scroll,"scroll");
};

#endif

Class Input_obj::__mClass;

void Input_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.input.Input"), hx::TCanCast< Input_obj> ,sStaticFields,sMemberFields,
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

void Input_obj::__boot()
{
	scroll= false;
}

} // end namespace haxor
} // end namespace input
