#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_InputState
#include <haxor/core/InputState.h>
#endif
#ifndef INCLUDED_haxor_input_Touch
#include <haxor/input/Touch.h>
#endif
#ifndef INCLUDED_haxor_math_Vector2
#include <haxor/math/Vector2.h>
#endif
namespace haxor{
namespace input{

Void Touch_obj::__construct()
{
HX_STACK_FRAME("haxor.input.Touch","new",0x4c236081,"haxor.input.Touch.new","haxor/input/Touch.hx",63,0x27faf2d1)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(64)
	this->state = ::haxor::core::InputState_obj::None;
	HX_STACK_LINE(65)
	this->id = (int)-1;
	HX_STACK_LINE(66)
	::haxor::math::Vector2 _g = ::haxor::math::Vector2_obj::__new(null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(66)
	this->position = _g;
	HX_STACK_LINE(67)
	::haxor::math::Vector2 _g1 = ::haxor::math::Vector2_obj::__new(null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(67)
	this->delta = _g1;
	HX_STACK_LINE(68)
	::haxor::math::Vector2 _g2 = ::haxor::math::Vector2_obj::__new(null(),null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(68)
	this->relativePosition = _g2;
	HX_STACK_LINE(69)
	this->pressure = (int)0;
	HX_STACK_LINE(70)
	this->hold = (int)0;
	HX_STACK_LINE(71)
	this->angle = (int)0;
	HX_STACK_LINE(72)
	::haxor::math::Vector2 _g3 = ::haxor::math::Vector2_obj::__new(null(),null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(72)
	this->radius = _g3;
	HX_STACK_LINE(73)
	this->m_down = false;
}
;
	return null();
}

//Touch_obj::~Touch_obj() { }

Dynamic Touch_obj::__CreateEmpty() { return  new Touch_obj; }
hx::ObjectPtr< Touch_obj > Touch_obj::__new()
{  hx::ObjectPtr< Touch_obj > result = new Touch_obj();
	result->__construct();
	return result;}

Dynamic Touch_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Touch_obj > result = new Touch_obj();
	result->__construct();
	return result;}


Touch_obj::Touch_obj()
{
}

void Touch_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Touch);
	HX_MARK_MEMBER_NAME(state,"state");
	HX_MARK_MEMBER_NAME(id,"id");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(radius,"radius");
	HX_MARK_MEMBER_NAME(angle,"angle");
	HX_MARK_MEMBER_NAME(relativePosition,"relativePosition");
	HX_MARK_MEMBER_NAME(delta,"delta");
	HX_MARK_MEMBER_NAME(pressure,"pressure");
	HX_MARK_MEMBER_NAME(hold,"hold");
	HX_MARK_MEMBER_NAME(m_down,"m_down");
	HX_MARK_END_CLASS();
}

void Touch_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(state,"state");
	HX_VISIT_MEMBER_NAME(id,"id");
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(radius,"radius");
	HX_VISIT_MEMBER_NAME(angle,"angle");
	HX_VISIT_MEMBER_NAME(relativePosition,"relativePosition");
	HX_VISIT_MEMBER_NAME(delta,"delta");
	HX_VISIT_MEMBER_NAME(pressure,"pressure");
	HX_VISIT_MEMBER_NAME(hold,"hold");
	HX_VISIT_MEMBER_NAME(m_down,"m_down");
}

Dynamic Touch_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { return id; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"hold") ) { return hold; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		if (HX_FIELD_EQ(inName,"angle") ) { return angle; }
		if (HX_FIELD_EQ(inName,"delta") ) { return delta; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { return radius; }
		if (HX_FIELD_EQ(inName,"m_down") ) { return m_down; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		if (HX_FIELD_EQ(inName,"pressure") ) { return pressure; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"relativePosition") ) { return relativePosition; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Touch_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"id") ) { id=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"hold") ) { hold=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< ::haxor::core::InputState >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angle") ) { angle=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"delta") ) { delta=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"radius") ) { radius=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_down") ) { m_down=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pressure") ) { pressure=inValue.Cast< Float >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"relativePosition") ) { relativePosition=inValue.Cast< ::haxor::math::Vector2 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Touch_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("state"));
	outFields->push(HX_CSTRING("id"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("radius"));
	outFields->push(HX_CSTRING("angle"));
	outFields->push(HX_CSTRING("relativePosition"));
	outFields->push(HX_CSTRING("delta"));
	outFields->push(HX_CSTRING("pressure"));
	outFields->push(HX_CSTRING("hold"));
	outFields->push(HX_CSTRING("m_down"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::core::InputState*/ ,(int)offsetof(Touch_obj,state),HX_CSTRING("state")},
	{hx::fsInt,(int)offsetof(Touch_obj,id),HX_CSTRING("id")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Touch_obj,position),HX_CSTRING("position")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Touch_obj,radius),HX_CSTRING("radius")},
	{hx::fsFloat,(int)offsetof(Touch_obj,angle),HX_CSTRING("angle")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Touch_obj,relativePosition),HX_CSTRING("relativePosition")},
	{hx::fsObject /*::haxor::math::Vector2*/ ,(int)offsetof(Touch_obj,delta),HX_CSTRING("delta")},
	{hx::fsFloat,(int)offsetof(Touch_obj,pressure),HX_CSTRING("pressure")},
	{hx::fsFloat,(int)offsetof(Touch_obj,hold),HX_CSTRING("hold")},
	{hx::fsBool,(int)offsetof(Touch_obj,m_down),HX_CSTRING("m_down")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("state"),
	HX_CSTRING("id"),
	HX_CSTRING("position"),
	HX_CSTRING("radius"),
	HX_CSTRING("angle"),
	HX_CSTRING("relativePosition"),
	HX_CSTRING("delta"),
	HX_CSTRING("pressure"),
	HX_CSTRING("hold"),
	HX_CSTRING("m_down"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Touch_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Touch_obj::__mClass,"__mClass");
};

#endif

Class Touch_obj::__mClass;

void Touch_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.input.Touch"), hx::TCanCast< Touch_obj> ,sStaticFields,sMemberFields,
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

void Touch_obj::__boot()
{
}

} // end namespace haxor
} // end namespace input
