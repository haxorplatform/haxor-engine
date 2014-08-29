#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_GizmoContext
#include <haxor/context/GizmoContext.h>
#endif
#ifndef INCLUDED_haxor_graphics_Gizmo
#include <haxor/graphics/Gizmo.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
namespace haxor{
namespace graphics{

Void Gizmo_obj::__construct()
{
	return null();
}

//Gizmo_obj::~Gizmo_obj() { }

Dynamic Gizmo_obj::__CreateEmpty() { return  new Gizmo_obj; }
hx::ObjectPtr< Gizmo_obj > Gizmo_obj::__new()
{  hx::ObjectPtr< Gizmo_obj > result = new Gizmo_obj();
	result->__construct();
	return result;}

Dynamic Gizmo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Gizmo_obj > result = new Gizmo_obj();
	result->__construct();
	return result;}

Void Gizmo_obj::Grid( Float p_area,::haxor::math::Color p_color){
{
		HX_STACK_FRAME("haxor.graphics.Gizmo","Grid",0x0bc2b511,"haxor.graphics.Gizmo.Grid","haxor/graphics/Gizmo.hx",19,0x45aff45b)
		HX_STACK_ARG(p_area,"p_area")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_LINE(19)
		::haxor::context::EngineContext_obj::gizmo->DrawGrid(p_area,p_color);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Gizmo_obj,Grid,(void))

Void Gizmo_obj::Axis( Float p_area){
{
		HX_STACK_FRAME("haxor.graphics.Gizmo","Axis",0x07cffaec,"haxor.graphics.Gizmo.Axis","haxor/graphics/Gizmo.hx",28,0x45aff45b)
		HX_STACK_ARG(p_area,"p_area")
		HX_STACK_LINE(28)
		::haxor::context::EngineContext_obj::gizmo->DrawAxis(p_area);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Gizmo_obj,Axis,(void))


Gizmo_obj::Gizmo_obj()
{
}

Dynamic Gizmo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"Grid") ) { return Grid_dyn(); }
		if (HX_FIELD_EQ(inName,"Axis") ) { return Axis_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Gizmo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Gizmo_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Grid"),
	HX_CSTRING("Axis"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Gizmo_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Gizmo_obj::__mClass,"__mClass");
};

#endif

Class Gizmo_obj::__mClass;

void Gizmo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.Gizmo"), hx::TCanCast< Gizmo_obj> ,sStaticFields,sMemberFields,
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

void Gizmo_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
