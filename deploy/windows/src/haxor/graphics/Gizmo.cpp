#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_CanvasGizmo
#include <haxor/context/CanvasGizmo.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_Gizmo
#include <haxor/context/Gizmo.h>
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
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
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
		HX_STACK_FRAME("haxor.graphics.Gizmo","Grid",0x0bc2b511,"haxor.graphics.Gizmo.Grid","haxor/graphics/Gizmo.hx",24,0x45aff45b)
		HX_STACK_ARG(p_area,"p_area")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_LINE(24)
		::haxor::context::EngineContext_obj::gizmo->DrawGrid(p_area,p_color);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Gizmo_obj,Grid,(void))

Void Gizmo_obj::Axis( ::haxor::math::Vector3 p_position,::haxor::math::Vector3 p_size,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.graphics.Gizmo","Axis",0x07cffaec,"haxor.graphics.Gizmo.Axis","haxor/graphics/Gizmo.hx",33,0x45aff45b)
		HX_STACK_ARG(p_position,"p_position")
		HX_STACK_ARG(p_size,"p_size")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_transform,"p_transform")
		HX_STACK_LINE(33)
		::haxor::context::EngineContext_obj::gizmo->DrawAxis(p_position,p_size,p_color,p_transform);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Gizmo_obj,Axis,(void))

Void Gizmo_obj::Line( ::haxor::math::Vector3 p_from,::haxor::math::Vector3 p_to,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.graphics.Gizmo","Line",0x0f09f63f,"haxor.graphics.Gizmo.Line","haxor/graphics/Gizmo.hx",45,0x45aff45b)
		HX_STACK_ARG(p_from,"p_from")
		HX_STACK_ARG(p_to,"p_to")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_transform,"p_transform")
		HX_STACK_LINE(45)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(p_from,p_to,p_color,p_transform);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Gizmo_obj,Line,(void))

Void Gizmo_obj::Point( ::haxor::math::Vector3 p_position,hx::Null< Float >  __o_p_size,::haxor::math::Color p_color,hx::Null< bool >  __o_p_smooth,::haxor::math::Matrix4 p_transform){
Float p_size = __o_p_size.Default(1.0);
bool p_smooth = __o_p_smooth.Default(true);
	HX_STACK_FRAME("haxor.graphics.Gizmo","Point",0x6b3b57a5,"haxor.graphics.Gizmo.Point","haxor/graphics/Gizmo.hx",58,0x45aff45b)
	HX_STACK_ARG(p_position,"p_position")
	HX_STACK_ARG(p_size,"p_size")
	HX_STACK_ARG(p_color,"p_color")
	HX_STACK_ARG(p_smooth,"p_smooth")
	HX_STACK_ARG(p_transform,"p_transform")
{
		HX_STACK_LINE(58)
		::haxor::context::EngineContext_obj::gizmo->DrawPoint(p_position,p_size,p_color,p_smooth,p_transform);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Gizmo_obj,Point,(void))

Void Gizmo_obj::WireSphere( ::haxor::math::Vector3 p_position,hx::Null< Float >  __o_p_radius,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform){
Float p_radius = __o_p_radius.Default(1.0);
	HX_STACK_FRAME("haxor.graphics.Gizmo","WireSphere",0x7136c1bd,"haxor.graphics.Gizmo.WireSphere","haxor/graphics/Gizmo.hx",69,0x45aff45b)
	HX_STACK_ARG(p_position,"p_position")
	HX_STACK_ARG(p_radius,"p_radius")
	HX_STACK_ARG(p_color,"p_color")
	HX_STACK_ARG(p_transform,"p_transform")
{
		HX_STACK_LINE(69)
		::haxor::context::EngineContext_obj::gizmo->DrawWireSphere(p_position,p_radius,p_color,p_transform);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Gizmo_obj,WireSphere,(void))

Void Gizmo_obj::WireCube( ::haxor::math::Vector3 p_position,::haxor::math::Vector3 p_size,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.graphics.Gizmo","WireCube",0xdbb643a5,"haxor.graphics.Gizmo.WireCube","haxor/graphics/Gizmo.hx",81,0x45aff45b)
		HX_STACK_ARG(p_position,"p_position")
		HX_STACK_ARG(p_size,"p_size")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_transform,"p_transform")
		HX_STACK_LINE(81)
		::haxor::context::EngineContext_obj::gizmo->DrawWireCube(p_position,p_size,p_color,p_transform);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Gizmo_obj,WireCube,(void))

Void Gizmo_obj::BeginPath( ::haxor::math::Color p_fill,::haxor::math::Color p_line,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.graphics.Gizmo","BeginPath",0xaaf43643,"haxor.graphics.Gizmo.BeginPath","haxor/graphics/Gizmo.hx",92,0x45aff45b)
		HX_STACK_ARG(p_fill,"p_fill")
		HX_STACK_ARG(p_line,"p_line")
		HX_STACK_ARG(p_transform,"p_transform")
		HX_STACK_LINE(92)
		::haxor::context::EngineContext_obj::gizmo->canvas_renderer->Begin(p_fill,p_line,p_transform);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Gizmo_obj,BeginPath,(void))

Void Gizmo_obj::LinePath( ::haxor::math::Vector3 p_position){
{
		HX_STACK_FRAME("haxor.graphics.Gizmo","LinePath",0xd5a69384,"haxor.graphics.Gizmo.LinePath","haxor/graphics/Gizmo.hx",101,0x45aff45b)
		HX_STACK_ARG(p_position,"p_position")
		HX_STACK_LINE(101)
		::haxor::context::EngineContext_obj::gizmo->canvas_renderer->Line(p_position);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Gizmo_obj,LinePath,(void))

Void Gizmo_obj::EndPath( ){
{
		HX_STACK_FRAME("haxor.graphics.Gizmo","EndPath",0x0dd181b5,"haxor.graphics.Gizmo.EndPath","haxor/graphics/Gizmo.hx",109,0x45aff45b)
		HX_STACK_LINE(109)
		::haxor::context::EngineContext_obj::gizmo->canvas_renderer->End();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Gizmo_obj,EndPath,(void))


Gizmo_obj::Gizmo_obj()
{
}

Dynamic Gizmo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"Grid") ) { return Grid_dyn(); }
		if (HX_FIELD_EQ(inName,"Axis") ) { return Axis_dyn(); }
		if (HX_FIELD_EQ(inName,"Line") ) { return Line_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Point") ) { return Point_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"EndPath") ) { return EndPath_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"WireCube") ) { return WireCube_dyn(); }
		if (HX_FIELD_EQ(inName,"LinePath") ) { return LinePath_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"BeginPath") ) { return BeginPath_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"WireSphere") ) { return WireSphere_dyn(); }
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
	HX_CSTRING("Line"),
	HX_CSTRING("Point"),
	HX_CSTRING("WireSphere"),
	HX_CSTRING("WireCube"),
	HX_CSTRING("BeginPath"),
	HX_CSTRING("LinePath"),
	HX_CSTRING("EndPath"),
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
