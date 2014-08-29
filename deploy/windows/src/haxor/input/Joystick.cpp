#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_InputState
#include <haxor/core/InputState.h>
#endif
#ifndef INCLUDED_haxor_input_Joystick
#include <haxor/input/Joystick.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
namespace haxor{
namespace input{

Void Joystick_obj::__construct()
{
HX_STACK_FRAME("haxor.input.Joystick","new",0x36a0c55e,"haxor.input.Joystick.new","haxor/input/Joystick.hx",81,0x86e4ec50)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(82)
	::haxor::core::InputState st = ::haxor::core::InputState_obj::None;		HX_STACK_VAR(st,"st");
	HX_STACK_LINE(84)
	this->name = HX_CSTRING("");
	HX_STACK_LINE(85)
	this->id = (int)-1;
	HX_STACK_LINE(86)
	this->button = Array_obj< Float >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0);
	HX_STACK_LINE(87)
	this->state = Array_obj< ::Dynamic >::__new().Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st).Add(st);
	HX_STACK_LINE(88)
	this->hold = Array_obj< Float >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0);
	HX_STACK_LINE(89)
	this->analog = Array_obj< Float >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0);
	HX_STACK_LINE(90)
	::haxor::math::Vector3 _g = ::haxor::math::Vector3_obj::__new(null(),null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(90)
	this->analogLeft = _g;
	HX_STACK_LINE(91)
	::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new(null(),null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(91)
	this->analogRight = _g1;
	HX_STACK_LINE(92)
	this->triggerLeft = 0.0;
	HX_STACK_LINE(93)
	this->triggerRight = 0.0;
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

bool Joystick_obj::IsDown( int p_button){
	HX_STACK_FRAME("haxor.input.Joystick","IsDown",0x4590ef4e,"haxor.input.Joystick.IsDown","haxor/input/Joystick.hx",101,0x86e4ec50)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_button,"p_button")
	HX_STACK_LINE(101)
	return (bool((this->state->__get(p_button).StaticCast< ::haxor::core::InputState >() == ::haxor::core::InputState_obj::Hold)) || bool((this->state->__get(p_button).StaticCast< ::haxor::core::InputState >() == ::haxor::core::InputState_obj::Down)));
}


HX_DEFINE_DYNAMIC_FUNC1(Joystick_obj,IsDown,return )

bool Joystick_obj::Hit( int p_button){
	HX_STACK_FRAME("haxor.input.Joystick","Hit",0x3683f331,"haxor.input.Joystick.Hit","haxor/input/Joystick.hx",108,0x86e4ec50)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_button,"p_button")
	HX_STACK_LINE(108)
	return (this->state->__get(p_button).StaticCast< ::haxor::core::InputState >() == ::haxor::core::InputState_obj::Up);
}


HX_DEFINE_DYNAMIC_FUNC1(Joystick_obj,Hit,return )

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
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"button") ) { return button; }
		if (HX_FIELD_EQ(inName,"analog") ) { return analog; }
		if (HX_FIELD_EQ(inName,"IsDown") ) { return IsDown_dyn(); }
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
	HX_CSTRING("IsDown"),
	HX_CSTRING("Hit"),
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
