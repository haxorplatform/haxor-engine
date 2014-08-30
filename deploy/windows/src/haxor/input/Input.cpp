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
#ifndef INCLUDED_haxor_input_InputHandler
#include <haxor/input/InputHandler.h>
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

::haxor::input::InputHandler Input_obj::m_handler;

Array< ::Dynamic > Input_obj::get_touches( ){
	HX_STACK_FRAME("haxor.input.Input","get_touches",0x329207f0,"haxor.input.Input.get_touches","haxor/input/Input.hx",47,0xee96c766)
	HX_STACK_LINE(47)
	return ::haxor::input::Input_obj::m_touches;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Input_obj,get_touches,return )

Array< ::Dynamic > Input_obj::m_touches;

Array< ::Dynamic > Input_obj::m_api_touches;

Array< ::Dynamic > Input_obj::get_joystick( ){
	HX_STACK_FRAME("haxor.input.Input","get_joystick",0xa904b959,"haxor.input.Input.get_joystick","haxor/input/Input.hx",55,0xee96c766)
	HX_STACK_LINE(55)
	return ::haxor::input::Input_obj::m_joysticks;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Input_obj,get_joystick,return )

Array< ::Dynamic > Input_obj::m_joysticks;

Array< ::Dynamic > Input_obj::m_api_joystick;

bool Input_obj::get_multitouch( ){
	HX_STACK_FRAME("haxor.input.Input","get_multitouch",0xeaa7f083,"haxor.input.Input.get_multitouch","haxor/input/Input.hx",64,0xee96c766)
	HX_STACK_LINE(64)
	return ::haxor::input::Input_obj::m_multitouch;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Input_obj,get_multitouch,return )

bool Input_obj::m_multitouch;

::haxor::math::Vector2 Input_obj::mouse;

::haxor::math::Vector2 Input_obj::deltaMouse;

::haxor::math::Vector2 Input_obj::relativeMouse;

Float Input_obj::wheel;

bool Input_obj::scroll;

bool Input_obj::menu;

::haxor::core::InputState Input_obj::GetInputState( int p_code){
	HX_STACK_FRAME("haxor.input.Input","GetInputState",0x48afc6a9,"haxor.input.Input.GetInputState","haxor/input/Input.hx",104,0xee96c766)
	HX_STACK_ARG(p_code,"p_code")
	HX_STACK_LINE(104)
	return ::haxor::input::Input_obj::m_state->get(p_code);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Input_obj,GetInputState,return )

bool Input_obj::Pressed( int p_code){
	HX_STACK_FRAME("haxor.input.Input","Pressed",0x3d791e6e,"haxor.input.Input.Pressed","haxor/input/Input.hx",113,0xee96c766)
	HX_STACK_ARG(p_code,"p_code")
	HX_STACK_LINE(114)
	::haxor::core::InputState s = ::haxor::input::Input_obj::GetInputState(p_code);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(115)
	return (bool((s == ::haxor::core::InputState_obj::Down)) || bool((s == ::haxor::core::InputState_obj::Hold)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Input_obj,Pressed,return )

bool Input_obj::Down( int p_code){
	HX_STACK_FRAME("haxor.input.Input","Down",0xbbbf9516,"haxor.input.Input.Down","haxor/input/Input.hx",124,0xee96c766)
	HX_STACK_ARG(p_code,"p_code")
	HX_STACK_LINE(125)
	::haxor::core::InputState s = ::haxor::input::Input_obj::GetInputState(p_code);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(126)
	return (s == ::haxor::core::InputState_obj::Down);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Input_obj,Down,return )

bool Input_obj::Hit( int p_code){
	HX_STACK_FRAME("haxor.input.Input","Hit",0x4dc4bc1f,"haxor.input.Input.Hit","haxor/input/Input.hx",135,0xee96c766)
	HX_STACK_ARG(p_code,"p_code")
	HX_STACK_LINE(136)
	::haxor::core::InputState s = ::haxor::input::Input_obj::GetInputState(p_code);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(137)
	return (s == ::haxor::core::InputState_obj::Up);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Input_obj,Hit,return )

Float Input_obj::GetHoldTime( int p_code){
	HX_STACK_FRAME("haxor.input.Input","GetHoldTime",0x1c85b16e,"haxor.input.Input.GetHoldTime","haxor/input/Input.hx",145,0xee96c766)
	HX_STACK_ARG(p_code,"p_code")
	HX_STACK_LINE(145)
	return ::haxor::input::Input_obj::m_hold->get(p_code);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Input_obj,GetHoldTime,return )

Void Input_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.input.Input","Initialize",0x0a414d04,"haxor.input.Input.Initialize","haxor/input/Input.hx",152,0xee96c766)
		HX_STACK_LINE(153)
		::haxe::ds::IntMap _g = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(153)
		::haxor::input::Input_obj::m_state = _g;
		HX_STACK_LINE(154)
		::haxe::ds::IntMap _g1 = ::haxe::ds::IntMap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(154)
		::haxor::input::Input_obj::m_hold = _g1;
		HX_STACK_LINE(155)
		Array< int > _g2 = Array_obj< int >::__new();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(155)
		::haxor::input::Input_obj::m_active = _g2;
		HX_STACK_LINE(156)
		Array< bool > _g3 = Array_obj< bool >::__new();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(156)
		::haxor::input::Input_obj::m_down = _g3;
		HX_STACK_LINE(158)
		::haxor::input::Input_obj::m_touches = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(159)
		::haxor::input::Input_obj::m_api_touches = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(161)
		{
			HX_STACK_LINE(161)
			int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(161)
			while((true)){
				HX_STACK_LINE(161)
				if ((!(((_g4 < (int)10))))){
					HX_STACK_LINE(161)
					break;
				}
				HX_STACK_LINE(161)
				int i = (_g4)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(163)
				::haxor::input::Touch _g41 = ::haxor::input::Touch_obj::__new();		HX_STACK_VAR(_g41,"_g41");
				HX_STACK_LINE(163)
				::haxor::input::Input_obj::m_api_touches->push(_g41);
			}
		}
		HX_STACK_LINE(166)
		{
			HX_STACK_LINE(166)
			int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(166)
			while((true)){
				HX_STACK_LINE(166)
				if ((!(((_g4 < (int)256))))){
					HX_STACK_LINE(166)
					break;
				}
				HX_STACK_LINE(166)
				int i = (_g4)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(168)
				::haxor::input::Input_obj::m_state->set(i,::haxor::core::InputState_obj::None);
				HX_STACK_LINE(169)
				::haxor::input::Input_obj::m_hold->set(i,(int)0);
				HX_STACK_LINE(170)
				::haxor::input::Input_obj::m_down->push(false);
			}
		}
		HX_STACK_LINE(173)
		::haxor::input::Input_obj::m_joysticks = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(174)
		::haxor::input::Input_obj::m_api_joystick = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(175)
		{
			HX_STACK_LINE(175)
			int _g4 = (int)0;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(175)
			while((true)){
				HX_STACK_LINE(175)
				if ((!(((_g4 < (int)10))))){
					HX_STACK_LINE(175)
					break;
				}
				HX_STACK_LINE(175)
				int i = (_g4)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(177)
				::haxor::input::Joystick _g5 = ::haxor::input::Joystick_obj::__new();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(177)
				::haxor::input::Input_obj::m_api_joystick->push(_g5);
			}
		}
		HX_STACK_LINE(180)
		::haxor::math::Vector2 _g6 = ::haxor::math::Vector2_obj::__new(null(),null());		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(180)
		::haxor::input::Input_obj::mouse = _g6;
		HX_STACK_LINE(181)
		::haxor::math::Vector2 _g7 = ::haxor::math::Vector2_obj::__new(null(),null());		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(181)
		::haxor::input::Input_obj::deltaMouse = _g7;
		HX_STACK_LINE(182)
		::haxor::math::Vector2 _g8 = ::haxor::math::Vector2_obj::__new(null(),null());		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(182)
		::haxor::input::Input_obj::relativeMouse = _g8;
		HX_STACK_LINE(184)
		::haxor::core::Console_obj::Log(HX_CSTRING("Haxor> Input Initialize"),(int)4);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Input_obj,Initialize,(void))

Void Input_obj::UpdateTouchFSM( ){
{
		HX_STACK_FRAME("haxor.input.Input","UpdateTouchFSM",0x038468de,"haxor.input.Input.UpdateTouchFSM","haxor/input/Input.hx",192,0xee96c766)
		HX_STACK_LINE(192)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(192)
		int _g = ::haxor::input::Input_obj::m_touches->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(192)
		while((true)){
			HX_STACK_LINE(192)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(192)
				break;
			}
			HX_STACK_LINE(192)
			int j = (_g1)++;		HX_STACK_VAR(j,"j");
			HX_STACK_LINE(192)
			::haxor::input::Input_obj::TouchFSM(::haxor::input::Input_obj::m_touches->__get(j).StaticCast< ::haxor::input::Touch >());
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Input_obj,UpdateTouchFSM,(void))

Void Input_obj::UpdateInput( ){
{
		HX_STACK_FRAME("haxor.input.Input","UpdateInput",0x5b884f0d,"haxor.input.Input.UpdateInput","haxor/input/Input.hx",198,0xee96c766)
		HX_STACK_LINE(198)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(198)
		int _g = ::haxor::input::Input_obj::m_active->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(198)
		while((true)){
			HX_STACK_LINE(198)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(198)
				break;
			}
			HX_STACK_LINE(198)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(198)
			::haxor::input::Input_obj::UpdateInputState(::haxor::input::Input_obj::m_active->__get(i),::haxor::input::Input_obj::m_down->__get(::haxor::input::Input_obj::m_active->__get(i)),null());
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Input_obj,UpdateInput,(void))

Void Input_obj::TouchFSM( ::haxor::input::Touch t){
{
		HX_STACK_FRAME("haxor.input.Input","TouchFSM",0x1c7a76b5,"haxor.input.Input.TouchFSM","haxor/input/Input.hx",205,0xee96c766)
		HX_STACK_ARG(t,"t")
		HX_STACK_LINE(206)
		if (((t == null()))){
			HX_STACK_LINE(206)
			return null();
		}
		HX_STACK_LINE(207)
		::haxor::core::InputState current = t->state;		HX_STACK_VAR(current,"current");
		HX_STACK_LINE(208)
		bool d = t->m_down;		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(209)
		if (((current == ::haxor::core::InputState_obj::Up))){
			HX_STACK_LINE(209)
			::haxor::input::Input_obj::m_touches->remove(t);
		}
		HX_STACK_LINE(210)
		if (((current == ::haxor::core::InputState_obj::Hold))){
			HX_STACK_LINE(210)
			hx::AddEq(t->hold,::haxor::core::Time_obj::m_delta);
		}
		HX_STACK_LINE(211)
		::haxor::core::InputState _g = ::haxor::input::Input_obj::InputStateFSM(current,d);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(211)
		t->state = _g;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Input_obj,TouchFSM,(void))

Void Input_obj::UpdateInputState( int p_code,bool p_is_down,hx::Null< bool >  __o_p_update_state){
bool p_update_state = __o_p_update_state.Default(true);
	HX_STACK_FRAME("haxor.input.Input","UpdateInputState",0x52d5e7c4,"haxor.input.Input.UpdateInputState","haxor/input/Input.hx",220,0xee96c766)
	HX_STACK_ARG(p_code,"p_code")
	HX_STACK_ARG(p_is_down,"p_is_down")
	HX_STACK_ARG(p_update_state,"p_update_state")
{
		HX_STACK_LINE(221)
		::haxor::core::InputState current = ::haxor::input::Input_obj::m_state->get(p_code);		HX_STACK_VAR(current,"current");
		HX_STACK_LINE(222)
		if (((current == null()))){
			HX_STACK_LINE(222)
			current = ::haxor::core::InputState_obj::None;
		}
		HX_STACK_LINE(223)
		::haxor::core::InputState next = current;		HX_STACK_VAR(next,"next");
		HX_STACK_LINE(224)
		bool d0 = ::haxor::input::Input_obj::m_down->__get(p_code);		HX_STACK_VAR(d0,"d0");
		HX_STACK_LINE(225)
		bool d = ::haxor::input::Input_obj::m_down[p_code] = p_is_down;		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(227)
		if ((!(d0))){
			HX_STACK_LINE(227)
			if ((d)){
				HX_STACK_LINE(227)
				::haxor::input::Input_obj::m_active->push(p_code);
			}
		}
		HX_STACK_LINE(228)
		if ((!(d))){
			HX_STACK_LINE(228)
			if ((d0)){
				HX_STACK_LINE(228)
				return null();
			}
		}
		HX_STACK_LINE(230)
		if ((p_update_state)){
			HX_STACK_LINE(232)
			if (((current == ::haxor::core::InputState_obj::Up))){
				HX_STACK_LINE(234)
				::haxor::input::Input_obj::m_hold->set(p_code,(int)0);
				HX_STACK_LINE(235)
				::haxor::input::Input_obj::m_active->remove(p_code);
			}
			HX_STACK_LINE(238)
			if (((current == ::haxor::core::InputState_obj::Hold))){
				HX_STACK_LINE(240)
				Float h = ::haxor::input::Input_obj::m_hold->get(p_code);		HX_STACK_VAR(h,"h");
				HX_STACK_LINE(241)
				::haxor::input::Input_obj::m_hold->set(p_code,(h + ::haxor::core::Time_obj::m_delta));
			}
			HX_STACK_LINE(244)
			::haxor::core::InputState _g = ::haxor::input::Input_obj::InputStateFSM(current,d);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(244)
			next = _g;
			HX_STACK_LINE(246)
			if (((current != next))){
				HX_STACK_LINE(246)
				::haxor::input::Input_obj::m_state->set(p_code,next);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Input_obj,UpdateInputState,(void))

::haxor::core::InputState Input_obj::InputStateFSM( ::haxor::core::InputState p_current,bool p_is_down){
	HX_STACK_FRAME("haxor.input.Input","InputStateFSM",0xd80d17e5,"haxor.input.Input.InputStateFSM","haxor/input/Input.hx",257,0xee96c766)
	HX_STACK_ARG(p_current,"p_current")
	HX_STACK_ARG(p_is_down,"p_is_down")
	HX_STACK_LINE(258)
	::haxor::core::InputState current = p_current;		HX_STACK_VAR(current,"current");
	HX_STACK_LINE(259)
	::haxor::core::InputState next = current;		HX_STACK_VAR(next,"next");
	HX_STACK_LINE(260)
	bool d = p_is_down;		HX_STACK_VAR(d,"d");
	HX_STACK_LINE(261)
	switch( (int)(current->__Index())){
		case (int)0: {
			HX_STACK_LINE(264)
			if ((d)){
				HX_STACK_LINE(264)
				next = ::haxor::core::InputState_obj::Down;
			}
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(266)
			if ((!(d))){
				HX_STACK_LINE(266)
				next = ::haxor::core::InputState_obj::Up;
			}
			HX_STACK_LINE(267)
			next = ::haxor::core::InputState_obj::Hold;
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(270)
			next = ::haxor::core::InputState_obj::None;
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(273)
			if ((!(d))){
				HX_STACK_LINE(273)
				next = ::haxor::core::InputState_obj::Up;
			}
		}
		;break;
	}
	HX_STACK_LINE(275)
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
		if (HX_FIELD_EQ(inName,"menu") ) { return menu; }
		if (HX_FIELD_EQ(inName,"Down") ) { return Down_dyn(); }
		break;
	case 5:
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
		if (HX_FIELD_EQ(inName,"touches") ) { return get_touches(); }
		if (HX_FIELD_EQ(inName,"Pressed") ) { return Pressed_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_active") ) { return m_active; }
		if (HX_FIELD_EQ(inName,"joystick") ) { return get_joystick(); }
		if (HX_FIELD_EQ(inName,"TouchFSM") ) { return TouchFSM_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_handler") ) { return m_handler; }
		if (HX_FIELD_EQ(inName,"m_touches") ) { return m_touches; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"multitouch") ) { return get_multitouch(); }
		if (HX_FIELD_EQ(inName,"deltaMouse") ) { return deltaMouse; }
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_touches") ) { return get_touches_dyn(); }
		if (HX_FIELD_EQ(inName,"m_joysticks") ) { return m_joysticks; }
		if (HX_FIELD_EQ(inName,"GetHoldTime") ) { return GetHoldTime_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateInput") ) { return UpdateInput_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_joystick") ) { return get_joystick_dyn(); }
		if (HX_FIELD_EQ(inName,"m_multitouch") ) { return m_multitouch; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_api_touches") ) { return m_api_touches; }
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
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Input_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"menu") ) { menu=inValue.Cast< bool >(); return inValue; }
		break;
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
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_active") ) { m_active=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_handler") ) { m_handler=inValue.Cast< ::haxor::input::InputHandler >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_touches") ) { m_touches=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
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
		if (HX_FIELD_EQ(inName,"m_api_touches") ) { m_api_touches=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
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
	HX_CSTRING("m_handler"),
	HX_CSTRING("get_touches"),
	HX_CSTRING("m_touches"),
	HX_CSTRING("m_api_touches"),
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
	HX_CSTRING("menu"),
	HX_CSTRING("GetInputState"),
	HX_CSTRING("Pressed"),
	HX_CSTRING("Down"),
	HX_CSTRING("Hit"),
	HX_CSTRING("GetHoldTime"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("UpdateTouchFSM"),
	HX_CSTRING("UpdateInput"),
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
	HX_MARK_MEMBER_NAME(Input_obj::m_handler,"m_handler");
	HX_MARK_MEMBER_NAME(Input_obj::m_touches,"m_touches");
	HX_MARK_MEMBER_NAME(Input_obj::m_api_touches,"m_api_touches");
	HX_MARK_MEMBER_NAME(Input_obj::m_joysticks,"m_joysticks");
	HX_MARK_MEMBER_NAME(Input_obj::m_api_joystick,"m_api_joystick");
	HX_MARK_MEMBER_NAME(Input_obj::m_multitouch,"m_multitouch");
	HX_MARK_MEMBER_NAME(Input_obj::mouse,"mouse");
	HX_MARK_MEMBER_NAME(Input_obj::deltaMouse,"deltaMouse");
	HX_MARK_MEMBER_NAME(Input_obj::relativeMouse,"relativeMouse");
	HX_MARK_MEMBER_NAME(Input_obj::wheel,"wheel");
	HX_MARK_MEMBER_NAME(Input_obj::scroll,"scroll");
	HX_MARK_MEMBER_NAME(Input_obj::menu,"menu");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Input_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Input_obj::m_state,"m_state");
	HX_VISIT_MEMBER_NAME(Input_obj::m_hold,"m_hold");
	HX_VISIT_MEMBER_NAME(Input_obj::m_down,"m_down");
	HX_VISIT_MEMBER_NAME(Input_obj::m_active,"m_active");
	HX_VISIT_MEMBER_NAME(Input_obj::m_handler,"m_handler");
	HX_VISIT_MEMBER_NAME(Input_obj::m_touches,"m_touches");
	HX_VISIT_MEMBER_NAME(Input_obj::m_api_touches,"m_api_touches");
	HX_VISIT_MEMBER_NAME(Input_obj::m_joysticks,"m_joysticks");
	HX_VISIT_MEMBER_NAME(Input_obj::m_api_joystick,"m_api_joystick");
	HX_VISIT_MEMBER_NAME(Input_obj::m_multitouch,"m_multitouch");
	HX_VISIT_MEMBER_NAME(Input_obj::mouse,"mouse");
	HX_VISIT_MEMBER_NAME(Input_obj::deltaMouse,"deltaMouse");
	HX_VISIT_MEMBER_NAME(Input_obj::relativeMouse,"relativeMouse");
	HX_VISIT_MEMBER_NAME(Input_obj::wheel,"wheel");
	HX_VISIT_MEMBER_NAME(Input_obj::scroll,"scroll");
	HX_VISIT_MEMBER_NAME(Input_obj::menu,"menu");
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
	menu= false;
}

} // end namespace haxor
} // end namespace input
