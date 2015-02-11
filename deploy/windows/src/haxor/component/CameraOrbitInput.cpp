#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_CameraOrbit
#include <haxor/component/CameraOrbit.h>
#endif
#ifndef INCLUDED_haxor_component_CameraOrbitInput
#include <haxor/component/CameraOrbitInput.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_input_Input
#include <haxor/input/Input.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace component{

Void CameraOrbitInput_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.CameraOrbitInput","new",0xf4da32b4,"haxor.component.CameraOrbitInput.new","haxor/component/CameraOrbit.hx",120,0xdbbd8c58)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(125)
	this->rotateSpeed = 0.5;
	HX_STACK_LINE(124)
	this->zoomSpeed = 0.5;
	HX_STACK_LINE(123)
	this->zoom = true;
	HX_STACK_LINE(122)
	this->rotate = true;
	HX_STACK_LINE(120)
	super::__construct(p_name);
}
;
	return null();
}

//CameraOrbitInput_obj::~CameraOrbitInput_obj() { }

Dynamic CameraOrbitInput_obj::__CreateEmpty() { return  new CameraOrbitInput_obj; }
hx::ObjectPtr< CameraOrbitInput_obj > CameraOrbitInput_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< CameraOrbitInput_obj > result = new CameraOrbitInput_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic CameraOrbitInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CameraOrbitInput_obj > result = new CameraOrbitInput_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *CameraOrbitInput_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::haxor::core::IUpdateable_obj)) return operator ::haxor::core::IUpdateable_obj *();
	return super::__ToInterface(inType);
}

Void CameraOrbitInput_obj::OnStart( ){
{
		HX_STACK_FRAME("haxor.component.CameraOrbitInput","OnStart",0x39a256f7,"haxor.component.CameraOrbitInput.OnStart","haxor/component/CameraOrbit.hx",130,0xdbbd8c58)
		HX_STACK_THIS(this)
		HX_STACK_LINE(131)
		Dynamic _g = this->m_entity->GetComponent(hx::ClassOf< ::haxor::component::CameraOrbit >());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(131)
		this->m_orbit = _g;
	}
return null();
}


Void CameraOrbitInput_obj::OnUpdate( ){
{
		HX_STACK_FRAME("haxor.component.CameraOrbitInput","OnUpdate",0xb574e5d4,"haxor.component.CameraOrbitInput.OnUpdate","haxor/component/CameraOrbit.hx",135,0xdbbd8c58)
		HX_STACK_THIS(this)
		HX_STACK_LINE(136)
		Float dx;		HX_STACK_VAR(dx,"dx");
		HX_STACK_LINE(136)
		if (((::haxor::input::Input_obj::get_touches()->length == (int)1))){
			HX_STACK_LINE(136)
			Array< ::Dynamic > _g = ::haxor::input::Input_obj::get_touches();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(136)
			dx = _g->__get((int)0).StaticCast< ::haxor::input::Touch >()->delta->x;
		}
		else{
			HX_STACK_LINE(136)
			dx = ::haxor::input::Input_obj::deltaMouse->x;
		}
		HX_STACK_LINE(137)
		Float dy;		HX_STACK_VAR(dy,"dy");
		HX_STACK_LINE(137)
		if (((::haxor::input::Input_obj::get_touches()->length == (int)1))){
			HX_STACK_LINE(137)
			Array< ::Dynamic > _g1 = ::haxor::input::Input_obj::get_touches();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(137)
			dy = _g1->__get((int)0).StaticCast< ::haxor::input::Touch >()->delta->y;
		}
		else{
			HX_STACK_LINE(137)
			dy = ::haxor::input::Input_obj::deltaMouse->y;
		}
		HX_STACK_LINE(139)
		if ((this->rotate)){
			HX_STACK_LINE(142)
			bool is_rotate;		HX_STACK_VAR(is_rotate,"is_rotate");
			HX_STACK_LINE(142)
			if ((!(::haxor::input::Input_obj::Pressed(::haxor::input::KeyCode_obj::Mouse0)))){
				HX_STACK_LINE(142)
				is_rotate = (::haxor::input::Input_obj::get_touches()->length == (int)1);
			}
			else{
				HX_STACK_LINE(142)
				is_rotate = true;
			}
			HX_STACK_LINE(144)
			if ((is_rotate)){
				HX_STACK_LINE(146)
				hx::AddEq(this->m_orbit->angle->x,(-(dx) * this->rotateSpeed));
				HX_STACK_LINE(147)
				hx::AddEq(this->m_orbit->angle->y,(dy * this->rotateSpeed));
			}
		}
		HX_STACK_LINE(151)
		if ((this->zoom)){
			HX_STACK_LINE(153)
			Float _g2 = ::Math_obj::abs(::haxor::input::Input_obj::wheel);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(153)
			if (((_g2 > (int)0))){
				HX_STACK_LINE(155)
				if (((::haxor::input::Input_obj::wheel < (int)0))){
					HX_STACK_LINE(155)
					hx::AddEq(this->m_orbit->distance,this->zoomSpeed);
				}
				else{
					HX_STACK_LINE(155)
					hx::AddEq(this->m_orbit->distance,-(this->zoomSpeed));
				}
			}
			HX_STACK_LINE(158)
			if (((::haxor::input::Input_obj::get_touches()->length == (int)2))){
				HX_STACK_LINE(160)
				hx::AddEq(this->m_orbit->distance,((::haxor::input::Input_obj::get_touches()->__get((int)0).StaticCast< ::haxor::input::Touch >()->delta->y * this->zoomSpeed) * 0.05));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CameraOrbitInput_obj,OnUpdate,(void))


CameraOrbitInput_obj::CameraOrbitInput_obj()
{
}

void CameraOrbitInput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CameraOrbitInput);
	HX_MARK_MEMBER_NAME(rotate,"rotate");
	HX_MARK_MEMBER_NAME(zoom,"zoom");
	HX_MARK_MEMBER_NAME(zoomSpeed,"zoomSpeed");
	HX_MARK_MEMBER_NAME(rotateSpeed,"rotateSpeed");
	HX_MARK_MEMBER_NAME(m_orbit,"m_orbit");
	::haxor::component::Component_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CameraOrbitInput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(rotate,"rotate");
	HX_VISIT_MEMBER_NAME(zoom,"zoom");
	HX_VISIT_MEMBER_NAME(zoomSpeed,"zoomSpeed");
	HX_VISIT_MEMBER_NAME(rotateSpeed,"rotateSpeed");
	HX_VISIT_MEMBER_NAME(m_orbit,"m_orbit");
	::haxor::component::Component_obj::__Visit(HX_VISIT_ARG);
}

Dynamic CameraOrbitInput_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { return zoom; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"rotate") ) { return rotate; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_orbit") ) { return m_orbit; }
		if (HX_FIELD_EQ(inName,"OnStart") ) { return OnStart_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"OnUpdate") ) { return OnUpdate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"zoomSpeed") ) { return zoomSpeed; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"rotateSpeed") ) { return rotateSpeed; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CameraOrbitInput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"zoom") ) { zoom=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"rotate") ) { rotate=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_orbit") ) { m_orbit=inValue.Cast< ::haxor::component::CameraOrbit >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"zoomSpeed") ) { zoomSpeed=inValue.Cast< Float >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"rotateSpeed") ) { rotateSpeed=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CameraOrbitInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("rotate"));
	outFields->push(HX_CSTRING("zoom"));
	outFields->push(HX_CSTRING("zoomSpeed"));
	outFields->push(HX_CSTRING("rotateSpeed"));
	outFields->push(HX_CSTRING("m_orbit"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(CameraOrbitInput_obj,rotate),HX_CSTRING("rotate")},
	{hx::fsBool,(int)offsetof(CameraOrbitInput_obj,zoom),HX_CSTRING("zoom")},
	{hx::fsFloat,(int)offsetof(CameraOrbitInput_obj,zoomSpeed),HX_CSTRING("zoomSpeed")},
	{hx::fsFloat,(int)offsetof(CameraOrbitInput_obj,rotateSpeed),HX_CSTRING("rotateSpeed")},
	{hx::fsObject /*::haxor::component::CameraOrbit*/ ,(int)offsetof(CameraOrbitInput_obj,m_orbit),HX_CSTRING("m_orbit")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("rotate"),
	HX_CSTRING("zoom"),
	HX_CSTRING("zoomSpeed"),
	HX_CSTRING("rotateSpeed"),
	HX_CSTRING("m_orbit"),
	HX_CSTRING("OnStart"),
	HX_CSTRING("OnUpdate"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CameraOrbitInput_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CameraOrbitInput_obj::__mClass,"__mClass");
};

#endif

Class CameraOrbitInput_obj::__mClass;

void CameraOrbitInput_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.CameraOrbitInput"), hx::TCanCast< CameraOrbitInput_obj> ,sStaticFields,sMemberFields,
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

void CameraOrbitInput_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
