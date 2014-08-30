#include <hxcpp.h>

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
#ifndef INCLUDED_haxor_platform_windows_input_WinInputHandler
#include <haxor/platform/windows/input/WinInputHandler.h>
#endif
namespace haxor{
namespace platform{
namespace windows{
namespace input{

Void WinInputHandler_obj::__construct()
{
HX_STACK_FRAME("haxor.platform.windows.input.WinInputHandler","new",0xbd82d010,"haxor.platform.windows.input.WinInputHandler.new","haxor/platform/windows/input/WinInputHandler.hx",33,0x9e512882)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(34)
	int max_jk = (int)0;		HX_STACK_VAR(max_jk,"max_jk");
	HX_STACK_LINE(35)
	max_jk = 4;;
	HX_STACK_LINE(36)
	this->m_max_joystick = max_jk;
	HX_STACK_LINE(38)
	this->CheckJoysticks();
	HX_STACK_LINE(40)
	super::__construct();
}
;
	return null();
}

//WinInputHandler_obj::~WinInputHandler_obj() { }

Dynamic WinInputHandler_obj::__CreateEmpty() { return  new WinInputHandler_obj; }
hx::ObjectPtr< WinInputHandler_obj > WinInputHandler_obj::__new()
{  hx::ObjectPtr< WinInputHandler_obj > result = new WinInputHandler_obj();
	result->__construct();
	return result;}

Dynamic WinInputHandler_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WinInputHandler_obj > result = new WinInputHandler_obj();
	result->__construct();
	return result;}

Void WinInputHandler_obj::UpdateInput( ){
{
		HX_STACK_FRAME("haxor.platform.windows.input.WinInputHandler","UpdateInput",0xa0a6f4d1,"haxor.platform.windows.input.WinInputHandler.UpdateInput","haxor/platform/windows/input/WinInputHandler.hx",48,0x9e512882)
		HX_STACK_THIS(this)
		HX_STACK_LINE(48)
		this->UpdateJoysticks();
	}
return null();
}


Void WinInputHandler_obj::UpdateJoysticks( ){
{
		HX_STACK_FRAME("haxor.platform.windows.input.WinInputHandler","UpdateJoysticks",0x0351647e,"haxor.platform.windows.input.WinInputHandler.UpdateJoysticks","haxor/platform/windows/input/WinInputHandler.hx",52,0x9e512882)
		HX_STACK_THIS(this)
		HX_STACK_LINE(53)
		Float alx = 0.0;		HX_STACK_VAR(alx,"alx");
		HX_STACK_LINE(54)
		Float aly = 0.0;		HX_STACK_VAR(aly,"aly");
		HX_STACK_LINE(55)
		Float arx = 0.0;		HX_STACK_VAR(arx,"arx");
		HX_STACK_LINE(56)
		Float ary = 0.0;		HX_STACK_VAR(ary,"ary");
		HX_STACK_LINE(57)
		Float tl = 0.0;		HX_STACK_VAR(tl,"tl");
		HX_STACK_LINE(58)
		Float tr = 0.0;		HX_STACK_VAR(tr,"tr");
		HX_STACK_LINE(60)
		{
			HX_STACK_LINE(60)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(60)
			int _g = ::haxor::input::Input_obj::m_joysticks->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(60)
			while((true)){
				HX_STACK_LINE(60)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(60)
					break;
				}
				HX_STACK_LINE(60)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(62)
				::haxor::input::Joystick jk = ::haxor::input::Input_obj::m_joysticks->__get(i).StaticCast< ::haxor::input::Joystick >();		HX_STACK_VAR(jk,"jk");
				HX_STACK_LINE(63)
				this->OnJoystickStart(jk->id,jk->name);
				HX_STACK_LINE(64)
				int cid = jk->id;		HX_STACK_VAR(cid,"cid");
				HX_STACK_LINE(65)
							
			XINPUT_STATE state;
			ZeroMemory( & state, sizeof(XINPUT_STATE));
			//Check if device is connected.
			if (XInputGetState(cid, &state) != ERROR_SUCCESS) continue;			
			alx = ((float)state.Gamepad.sThumbLX)  / 32767.0;
			aly = ((float)state.Gamepad.sThumbLY)  / 32767.0;			
			arx = ((float)state.Gamepad.sThumbRX)  / 32767.0;
			ary = ((float)state.Gamepad.sThumbRY)  / 32767.0;						 
			tl = ((float)state.Gamepad.bLeftTrigger)  / 255.0;
			tr = ((float) state.Gamepad.bRightTrigger) / 255.0;			
			
			//state.Gamepad.wButtons & button
			
			;
				HX_STACK_LINE(81)
				Array< int > buttons = Array_obj< int >::__new().Add((int)4096).Add((int)8192).Add((int)16384).Add((int)32768).Add((int)256).Add((int)512).Add((int)-1).Add((int)-1).Add((int)32).Add((int)16).Add((int)64).Add((int)128).Add((int)1).Add((int)2).Add((int)4).Add((int)8);		HX_STACK_VAR(buttons,"buttons");
				HX_STACK_LINE(100)
				{
					HX_STACK_LINE(100)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(100)
					int _g2 = buttons->length;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(100)
					while((true)){
						HX_STACK_LINE(100)
						if ((!(((_g3 < _g2))))){
							HX_STACK_LINE(100)
							break;
						}
						HX_STACK_LINE(100)
						int i1 = (_g3)++;		HX_STACK_VAR(i1,"i1");
						HX_STACK_LINE(102)
						Float v = 0.0;		HX_STACK_VAR(v,"v");
						HX_STACK_LINE(103)
						int code = buttons->__get(i1);		HX_STACK_VAR(code,"code");
						HX_STACK_LINE(104)
						if (((i1 == ::haxor::input::KeyCode_obj::LeftShoulderBottom))){
							HX_STACK_LINE(104)
							v = tl;
						}
						else{
							HX_STACK_LINE(105)
							if (((i1 == ::haxor::input::KeyCode_obj::RightShoulderBottom))){
								HX_STACK_LINE(105)
								v = tr;
							}
							else{
								HX_STACK_LINE(107)
								
					v = (state.Gamepad.wButtons & code) != 0 ? 1.0 : 0.0;
					;
							}
						}
						HX_STACK_LINE(112)
						this->OnJoystickDataUpdate(i1,v,false);
					}
				}
				HX_STACK_LINE(115)
				Array< Float > axes = Array_obj< Float >::__new().Add(alx).Add(-(aly)).Add(arx).Add(-(ary));		HX_STACK_VAR(axes,"axes");
				HX_STACK_LINE(116)
				{
					HX_STACK_LINE(116)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(116)
					int _g2 = axes->length;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(116)
					while((true)){
						HX_STACK_LINE(116)
						if ((!(((_g3 < _g2))))){
							HX_STACK_LINE(116)
							break;
						}
						HX_STACK_LINE(116)
						int i1 = (_g3)++;		HX_STACK_VAR(i1,"i1");
						HX_STACK_LINE(116)
						this->OnJoystickDataUpdate(i1,axes->__get(i1),true);
					}
				}
				HX_STACK_LINE(117)
				this->OnJoystickAnalogUpdate();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(WinInputHandler_obj,UpdateJoysticks,(void))

Void WinInputHandler_obj::RequestJoystickVibration( ::haxor::input::Joystick p_joystick){
{
		HX_STACK_FRAME("haxor.platform.windows.input.WinInputHandler","RequestJoystickVibration",0xe3d85dd7,"haxor.platform.windows.input.WinInputHandler.RequestJoystickVibration","haxor/platform/windows/input/WinInputHandler.hx",124,0x9e512882)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_joystick,"p_joystick")
		HX_STACK_LINE(125)
		int cid = p_joystick->id;		HX_STACK_VAR(cid,"cid");
		HX_STACK_LINE(126)
		int lv = (p_joystick->m_vibrationLeft * 65535.0);		HX_STACK_VAR(lv,"lv");
		HX_STACK_LINE(127)
		int rv = (p_joystick->m_vibrationRight * 65535.0);		HX_STACK_VAR(rv,"rv");
		HX_STACK_LINE(129)
		
		XINPUT_VIBRATION vibration;
		ZeroMemory( &vibration, sizeof(XINPUT_VIBRATION) );
		vibration.wLeftMotorSpeed  = lv; // use any value between 0-65535 here
		vibration.wRightMotorSpeed = rv; // use any value between 0-65535 here
		XInputSetState(cid, & vibration );
		;
	}
return null();
}


Void WinInputHandler_obj::CheckJoysticks( ){
{
		HX_STACK_FRAME("haxor.platform.windows.input.WinInputHandler","CheckJoysticks",0xe01e04bf,"haxor.platform.windows.input.WinInputHandler.CheckJoysticks","haxor/platform/windows/input/WinInputHandler.hx",142,0x9e512882)
		HX_STACK_THIS(this)
		HX_STACK_LINE(143)
		int cid = (int)-1;		HX_STACK_VAR(cid,"cid");
		HX_STACK_LINE(144)
		{
			HX_STACK_LINE(144)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(144)
			int _g = this->m_max_joystick;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(144)
			while((true)){
				HX_STACK_LINE(144)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(144)
					break;
				}
				HX_STACK_LINE(144)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(146)
						
			XINPUT_STATE state;
			ZeroMemory(&state, sizeof(XINPUT_STATE));		 
			if (XInputGetState(i, &state) == ERROR_SUCCESS)	cid = i;	 		
			;
				HX_STACK_LINE(151)
				if (((cid >= (int)0))){
					HX_STACK_LINE(153)
					this->OnJoystickStart(cid,(HX_CSTRING("Joystick") + cid));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(WinInputHandler_obj,CheckJoysticks,(void))


WinInputHandler_obj::WinInputHandler_obj()
{
}

Dynamic WinInputHandler_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"UpdateInput") ) { return UpdateInput_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_max_joystick") ) { return m_max_joystick; }
		if (HX_FIELD_EQ(inName,"CheckJoysticks") ) { return CheckJoysticks_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"UpdateJoysticks") ) { return UpdateJoysticks_dyn(); }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"RequestJoystickVibration") ) { return RequestJoystickVibration_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic WinInputHandler_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 14:
		if (HX_FIELD_EQ(inName,"m_max_joystick") ) { m_max_joystick=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void WinInputHandler_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_max_joystick"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(WinInputHandler_obj,m_max_joystick),HX_CSTRING("m_max_joystick")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("m_max_joystick"),
	HX_CSTRING("UpdateInput"),
	HX_CSTRING("UpdateJoysticks"),
	HX_CSTRING("RequestJoystickVibration"),
	HX_CSTRING("CheckJoysticks"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(WinInputHandler_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(WinInputHandler_obj::__mClass,"__mClass");
};

#endif

Class WinInputHandler_obj::__mClass;

void WinInputHandler_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.windows.input.WinInputHandler"), hx::TCanCast< WinInputHandler_obj> ,sStaticFields,sMemberFields,
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

void WinInputHandler_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace windows
} // end namespace input
