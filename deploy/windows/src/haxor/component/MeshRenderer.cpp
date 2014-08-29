#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Camera
#include <haxor/component/Camera.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_MeshRenderer
#include <haxor/component/MeshRenderer.h>
#endif
#ifndef INCLUDED_haxor_component_Renderer
#include <haxor/component/Renderer.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_Graphics
#include <haxor/graphics/Graphics.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#include <haxor/graphics/mesh/Mesh.h>
#endif
namespace haxor{
namespace component{

Void MeshRenderer_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.MeshRenderer","new",0x52d8f6df,"haxor.component.MeshRenderer.new","haxor/component/MeshRenderer.hx",20,0x9df8586f)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(20)
	super::__construct(p_name);
}
;
	return null();
}

//MeshRenderer_obj::~MeshRenderer_obj() { }

Dynamic MeshRenderer_obj::__CreateEmpty() { return  new MeshRenderer_obj; }
hx::ObjectPtr< MeshRenderer_obj > MeshRenderer_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< MeshRenderer_obj > result = new MeshRenderer_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic MeshRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MeshRenderer_obj > result = new MeshRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::graphics::mesh::Mesh MeshRenderer_obj::get_mesh( ){
	HX_STACK_FRAME("haxor.component.MeshRenderer","get_mesh",0x8a77f297,"haxor.component.MeshRenderer.get_mesh","haxor/component/MeshRenderer.hx",27,0x9df8586f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(27)
	return this->m_mesh;
}


HX_DEFINE_DYNAMIC_FUNC0(MeshRenderer_obj,get_mesh,return )

::haxor::graphics::mesh::Mesh MeshRenderer_obj::set_mesh( ::haxor::graphics::mesh::Mesh v){
	HX_STACK_FRAME("haxor.component.MeshRenderer","set_mesh",0x38d54c0b,"haxor.component.MeshRenderer.set_mesh","haxor/component/MeshRenderer.hx",28,0x9df8586f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(28)
	if (((this->m_mesh == v))){
		HX_STACK_LINE(28)
		return v;
	}
	HX_STACK_LINE(28)
	this->m_mesh = v;
	HX_STACK_LINE(28)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(MeshRenderer_obj,set_mesh,return )

bool MeshRenderer_obj::get_visible( ){
	HX_STACK_FRAME("haxor.component.MeshRenderer","get_visible",0x83fd1608,"haxor.component.MeshRenderer.get_visible","haxor/component/MeshRenderer.hx",35,0x9df8586f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(35)
	return this->IsVisible(::haxor::component::Camera_obj::m_main);
}


HX_DEFINE_DYNAMIC_FUNC0(MeshRenderer_obj,get_visible,return )

Void MeshRenderer_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.MeshRenderer","OnBuild",0xf16d736e,"haxor.component.MeshRenderer.OnBuild","haxor/component/MeshRenderer.hx",41,0x9df8586f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(42)
		this->super::OnBuild();
		HX_STACK_LINE(43)
		this->m_has_mesh = true;
	}
return null();
}


bool MeshRenderer_obj::IsVisible( ::haxor::component::Camera p_camera){
	HX_STACK_FRAME("haxor.component.MeshRenderer","IsVisible",0x9e016547,"haxor.component.MeshRenderer.IsVisible","haxor/component/MeshRenderer.hx",52,0x9df8586f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_camera,"p_camera")
	HX_STACK_LINE(53)
	if (((p_camera == null()))){
		HX_STACK_LINE(53)
		return false;
	}
	HX_STACK_LINE(54)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC1(MeshRenderer_obj,IsVisible,return )

bool MeshRenderer_obj::CheckCulling( ){
	HX_STACK_FRAME("haxor.component.MeshRenderer","CheckCulling",0x30b87849,"haxor.component.MeshRenderer.CheckCulling","haxor/component/MeshRenderer.hx",100,0x9df8586f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(100)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(MeshRenderer_obj,CheckCulling,return )

Void MeshRenderer_obj::OnRender( ){
{
		HX_STACK_FRAME("haxor.component.MeshRenderer","OnRender",0x80ec0b16,"haxor.component.MeshRenderer.OnRender","haxor/component/MeshRenderer.hx",108,0x9df8586f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(109)
		this->super::OnRender();
		HX_STACK_LINE(110)
		if (((this->m_mesh == null()))){
			HX_STACK_LINE(110)
			return null();
		}
		HX_STACK_LINE(111)
		::haxor::graphics::Graphics_obj::Render(this->m_mesh,this->m_material,this->m_entity->m_transform,::haxor::component::Camera_obj::m_current);
	}
return null();
}



MeshRenderer_obj::MeshRenderer_obj()
{
}

void MeshRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MeshRenderer);
	HX_MARK_MEMBER_NAME(m_mesh,"m_mesh");
	::haxor::component::Renderer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MeshRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_mesh,"m_mesh");
	::haxor::component::Renderer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic MeshRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mesh") ) { return get_mesh(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_mesh") ) { return m_mesh; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"visible") ) { return get_visible(); }
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_mesh") ) { return get_mesh_dyn(); }
		if (HX_FIELD_EQ(inName,"set_mesh") ) { return set_mesh_dyn(); }
		if (HX_FIELD_EQ(inName,"OnRender") ) { return OnRender_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"IsVisible") ) { return IsVisible_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_visible") ) { return get_visible_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"CheckCulling") ) { return CheckCulling_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MeshRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mesh") ) { return set_mesh(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_mesh") ) { m_mesh=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MeshRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mesh"));
	outFields->push(HX_CSTRING("m_mesh"));
	outFields->push(HX_CSTRING("visible"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::graphics::mesh::Mesh*/ ,(int)offsetof(MeshRenderer_obj,m_mesh),HX_CSTRING("m_mesh")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_mesh"),
	HX_CSTRING("set_mesh"),
	HX_CSTRING("m_mesh"),
	HX_CSTRING("get_visible"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("IsVisible"),
	HX_CSTRING("CheckCulling"),
	HX_CSTRING("OnRender"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MeshRenderer_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MeshRenderer_obj::__mClass,"__mClass");
};

#endif

Class MeshRenderer_obj::__mClass;

void MeshRenderer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.MeshRenderer"), hx::TCanCast< MeshRenderer_obj> ,sStaticFields,sMemberFields,
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

void MeshRenderer_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
