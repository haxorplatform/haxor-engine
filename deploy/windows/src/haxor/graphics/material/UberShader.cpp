#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Shader
#include <haxor/graphics/material/Shader.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_UberShader
#include <haxor/graphics/material/UberShader.h>
#endif
namespace haxor{
namespace graphics{
namespace material{

Void UberShader_obj::__construct(::String p_source)
{
HX_STACK_FRAME("haxor.graphics.material.UberShader","new",0x947afe41,"haxor.graphics.material.UberShader.new","haxor/graphics/material/UberShader.hx",17,0x5e5df78e)
HX_STACK_THIS(this)
HX_STACK_ARG(p_source,"p_source")
{
	HX_STACK_LINE(17)
	super::__construct(p_source);
}
;
	return null();
}

//UberShader_obj::~UberShader_obj() { }

Dynamic UberShader_obj::__CreateEmpty() { return  new UberShader_obj; }
hx::ObjectPtr< UberShader_obj > UberShader_obj::__new(::String p_source)
{  hx::ObjectPtr< UberShader_obj > result = new UberShader_obj();
	result->__construct(p_source);
	return result;}

Dynamic UberShader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< UberShader_obj > result = new UberShader_obj();
	result->__construct(inArgs[0]);
	return result;}


UberShader_obj::UberShader_obj()
{
}

Dynamic UberShader_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic UberShader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void UberShader_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(UberShader_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(UberShader_obj::__mClass,"__mClass");
};

#endif

Class UberShader_obj::__mClass;

void UberShader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.material.UberShader"), hx::TCanCast< UberShader_obj> ,sStaticFields,sMemberFields,
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

void UberShader_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace material
