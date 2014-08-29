#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IRenderable
#include <haxor/core/IRenderable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
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
#ifndef INCLUDED_haxor_input_KeyCode
#include <haxor/input/KeyCode.h>
#endif
#ifndef INCLUDED_haxor_math_Vector2
#include <haxor/math/Vector2.h>
#endif
#ifndef INCLUDED_haxor_thread_Activity
#include <haxor/thread/Activity.h>
#endif
namespace haxor{
namespace input{

Void InputHandler_obj::__construct()
{
HX_STACK_FRAME("haxor.input.InputHandler","new",0xc4966782,"haxor.input.InputHandler.new","haxor/input/InputHandler.hx",17,0x17daf1ac)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(17)
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
	HX_STACK_FRAME("haxor.input.InputHandler","Update",0x72490447,"haxor.input.InputHandler.Update","haxor/input/InputHandler.hx",21,0x17daf1ac)
	HX_STACK_THIS(this)
	HX_STACK_ARG(t,"t")
	HX_STACK_LINE(22)
	::haxor::input::Input_obj::wheel = (int)0;
	HX_STACK_LINE(23)
	::haxor::input::Input_obj::deltaMouse->x = (int)0;
	HX_STACK_LINE(24)
	::haxor::input::Input_obj::deltaMouse->y = (int)0;
	HX_STACK_LINE(27)
	::haxor::input::Input_obj::UpdateInput();
	HX_STACK_LINE(29)
	this->UpdateInput();
	HX_STACK_LINE(31)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(InputHandler_obj,Update,return )

Void InputHandler_obj::UpdateInput( ){
{
		HX_STACK_FRAME("haxor.input.InputHandler","UpdateInput",0xc72a4e43,"haxor.input.InputHandler.UpdateInput","haxor/input/InputHandler.hx",37,0x17daf1ac)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InputHandler_obj,UpdateInput,(void))

Void InputHandler_obj::OnMouseMove( Float p_x,Float p_y){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnMouseMove",0x3a6c9fb9,"haxor.input.InputHandler.OnMouseMove","haxor/input/InputHandler.hx",45,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(46)
		::haxor::input::Input_obj::deltaMouse->x = (p_x - ::haxor::input::Input_obj::mouse->x);
		HX_STACK_LINE(47)
		::haxor::input::Input_obj::deltaMouse->y = (p_y - ::haxor::input::Input_obj::mouse->y);
		HX_STACK_LINE(48)
		::haxor::input::Input_obj::mouse->x = p_x;
		HX_STACK_LINE(49)
		::haxor::input::Input_obj::mouse->y = p_y;
		HX_STACK_LINE(50)
		::haxor::input::Input_obj::relativeMouse->x = (Float(::haxor::input::Input_obj::mouse->x) / Float(::haxor::graphics::Screen_obj::m_width));
		HX_STACK_LINE(51)
		::haxor::input::Input_obj::relativeMouse->y = (Float(::haxor::input::Input_obj::mouse->y) / Float(::haxor::graphics::Screen_obj::m_height));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InputHandler_obj,OnMouseMove,(void))

Void InputHandler_obj::OnMouseWheel( Float p_wheel){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnMouseWheel",0xa1f38af3,"haxor.input.InputHandler.OnMouseWheel","haxor/input/InputHandler.hx",60,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_wheel,"p_wheel")
		HX_STACK_LINE(60)
		::haxor::input::Input_obj::wheel = p_wheel;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InputHandler_obj,OnMouseWheel,(void))

Void InputHandler_obj::OnMouseButton( int p_button,bool p_down){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnMouseButton",0x33d2989a,"haxor.input.InputHandler.OnMouseButton","haxor/input/InputHandler.hx",70,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_button,"p_button")
		HX_STACK_ARG(p_down,"p_down")
		HX_STACK_LINE(70)
		switch( (int)(p_button)){
			case (int)0: {
				HX_STACK_LINE(72)
				::haxor::input::Input_obj::UpdateInputState(::haxor::input::KeyCode_obj::Mouse0,p_down);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(73)
				::haxor::input::Input_obj::UpdateInputState(::haxor::input::KeyCode_obj::Mouse1,p_down);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(74)
				::haxor::input::Input_obj::UpdateInputState(::haxor::input::KeyCode_obj::Mouse2,p_down);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(75)
				::haxor::input::Input_obj::UpdateInputState(::haxor::input::KeyCode_obj::Mouse3,p_down);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(76)
				::haxor::input::Input_obj::UpdateInputState(::haxor::input::KeyCode_obj::Mouse4,p_down);
			}
			;break;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InputHandler_obj,OnMouseButton,(void))

Void InputHandler_obj::OnKey( int p_code,bool p_down){
{
		HX_STACK_FRAME("haxor.input.InputHandler","OnKey",0x1106b142,"haxor.input.InputHandler.OnKey","haxor/input/InputHandler.hx",87,0x17daf1ac)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_code,"p_code")
		HX_STACK_ARG(p_down,"p_down")
		HX_STACK_LINE(87)
		::haxor::input::Input_obj::UpdateInputState(p_code,p_down);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InputHandler_obj,OnKey,(void))


InputHandler_obj::InputHandler_obj()
{
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
	case 11:
		if (HX_FIELD_EQ(inName,"UpdateInput") ) { return UpdateInput_dyn(); }
		if (HX_FIELD_EQ(inName,"OnMouseMove") ) { return OnMouseMove_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"OnMouseWheel") ) { return OnMouseWheel_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"OnMouseButton") ) { return OnMouseButton_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic InputHandler_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void InputHandler_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("Update"),
	HX_CSTRING("UpdateInput"),
	HX_CSTRING("OnMouseMove"),
	HX_CSTRING("OnMouseWheel"),
	HX_CSTRING("OnMouseButton"),
	HX_CSTRING("OnKey"),
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
