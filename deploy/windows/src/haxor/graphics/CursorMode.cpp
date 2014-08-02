#include <hxcpp.h>

#ifndef INCLUDED_haxor_graphics_CursorMode
#include <haxor/graphics/CursorMode.h>
#endif
namespace haxor{
namespace graphics{

::haxor::graphics::CursorMode CursorMode_obj::Hide;

::haxor::graphics::CursorMode CursorMode_obj::Lock;

::haxor::graphics::CursorMode CursorMode_obj::Show;

HX_DEFINE_CREATE_ENUM(CursorMode_obj)

int CursorMode_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("Hide")) return 1;
	if (inName==HX_CSTRING("Lock")) return 2;
	if (inName==HX_CSTRING("Show")) return 0;
	return super::__FindIndex(inName);
}

int CursorMode_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("Hide")) return 0;
	if (inName==HX_CSTRING("Lock")) return 0;
	if (inName==HX_CSTRING("Show")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic CursorMode_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("Hide")) return Hide;
	if (inName==HX_CSTRING("Lock")) return Lock;
	if (inName==HX_CSTRING("Show")) return Show;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Show"),
	HX_CSTRING("Hide"),
	HX_CSTRING("Lock"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CursorMode_obj::Hide,"Hide");
	HX_MARK_MEMBER_NAME(CursorMode_obj::Lock,"Lock");
	HX_MARK_MEMBER_NAME(CursorMode_obj::Show,"Show");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CursorMode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(CursorMode_obj::Hide,"Hide");
	HX_VISIT_MEMBER_NAME(CursorMode_obj::Lock,"Lock");
	HX_VISIT_MEMBER_NAME(CursorMode_obj::Show,"Show");
};
#endif

static ::String sMemberFields[] = { ::String(null()) };
Class CursorMode_obj::__mClass;

Dynamic __Create_CursorMode_obj() { return new CursorMode_obj; }

void CursorMode_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.CursorMode"), hx::TCanCast< CursorMode_obj >,sStaticFields,sMemberFields,
	&__Create_CursorMode_obj, &__Create,
	&super::__SGetClass(), &CreateCursorMode_obj, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatic
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void CursorMode_obj::__boot()
{
hx::Static(Hide) = hx::CreateEnum< CursorMode_obj >(HX_CSTRING("Hide"),1);
hx::Static(Lock) = hx::CreateEnum< CursorMode_obj >(HX_CSTRING("Lock"),2);
hx::Static(Show) = hx::CreateEnum< CursorMode_obj >(HX_CSTRING("Show"),0);
}


} // end namespace haxor
} // end namespace graphics
