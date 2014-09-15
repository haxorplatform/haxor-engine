#include <hxcpp.h>

#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#include <haxor/graphics/mesh/Mesh.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh2
#include <haxor/graphics/mesh/Mesh2.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshLayout
#include <haxor/graphics/mesh/MeshLayout.h>
#endif
namespace haxor{
namespace graphics{
namespace mesh{

Void Mesh2_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.graphics.mesh.Mesh2","new",0x67dec54d,"haxor.graphics.mesh.Mesh2.new","haxor/graphics/mesh/MeshLayout.hx",165,0x92e5291c)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(165)
	super::__construct(p_name);
}
;
	return null();
}

//Mesh2_obj::~Mesh2_obj() { }

Dynamic Mesh2_obj::__CreateEmpty() { return  new Mesh2_obj; }
hx::ObjectPtr< Mesh2_obj > Mesh2_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< Mesh2_obj > result = new Mesh2_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic Mesh2_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Mesh2_obj > result = new Mesh2_obj();
	result->__construct(inArgs[0]);
	return result;}


Mesh2_obj::Mesh2_obj()
{
}

Dynamic Mesh2_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic Mesh2_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Mesh2_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(Mesh2_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Mesh2_obj::__mClass,"__mClass");
};

#endif

Class Mesh2_obj::__mClass;

void Mesh2_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.mesh.Mesh2"), hx::TCanCast< Mesh2_obj> ,sStaticFields,sMemberFields,
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

void Mesh2_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace mesh
