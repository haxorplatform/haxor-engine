#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
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
#ifndef INCLUDED_haxor_component_SkinnedMeshRenderer
#include <haxor/component/SkinnedMeshRenderer.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_PixelFormat
#include <haxor/core/PixelFormat.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_ComputeTexture
#include <haxor/graphics/texture/ComputeTexture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture2D
#include <haxor/graphics/texture/Texture2D.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
namespace haxor{
namespace component{

Void SkinnedMeshRenderer_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.SkinnedMeshRenderer","new",0xfc589b55,"haxor.component.SkinnedMeshRenderer.new","haxor/component/SkinnedMeshRenderer.hx",10,0x9853527d)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(10)
	super::__construct(p_name);
}
;
	return null();
}

//SkinnedMeshRenderer_obj::~SkinnedMeshRenderer_obj() { }

Dynamic SkinnedMeshRenderer_obj::__CreateEmpty() { return  new SkinnedMeshRenderer_obj; }
hx::ObjectPtr< SkinnedMeshRenderer_obj > SkinnedMeshRenderer_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< SkinnedMeshRenderer_obj > result = new SkinnedMeshRenderer_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic SkinnedMeshRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SkinnedMeshRenderer_obj > result = new SkinnedMeshRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

Array< ::Dynamic > SkinnedMeshRenderer_obj::set_joints( Array< ::Dynamic > v){
	HX_STACK_FRAME("haxor.component.SkinnedMeshRenderer","set_joints",0x5cdea3d1,"haxor.component.SkinnedMeshRenderer.set_joints","haxor/component/SkinnedMeshRenderer.hx",16,0x9853527d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(16)
	if (((v == null()))){
		HX_STACK_LINE(16)
		this->m_joints = Array_obj< ::Dynamic >::__new();
	}
	else{
		HX_STACK_LINE(16)
		this->m_joints = v;
	}
	HX_STACK_LINE(16)
	return this->m_joints;
}


HX_DEFINE_DYNAMIC_FUNC1(SkinnedMeshRenderer_obj,set_joints,return )

Array< ::Dynamic > SkinnedMeshRenderer_obj::get_joints( ){
	HX_STACK_FRAME("haxor.component.SkinnedMeshRenderer","get_joints",0x5961055d,"haxor.component.SkinnedMeshRenderer.get_joints","haxor/component/SkinnedMeshRenderer.hx",17,0x9853527d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(17)
	return this->m_joints;
}


HX_DEFINE_DYNAMIC_FUNC0(SkinnedMeshRenderer_obj,get_joints,return )

Void SkinnedMeshRenderer_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.SkinnedMeshRenderer","OnBuild",0x6ed78ae4,"haxor.component.SkinnedMeshRenderer.OnBuild","haxor/component/SkinnedMeshRenderer.hx",28,0x9853527d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(29)
		this->super::OnBuild();
		HX_STACK_LINE(30)
		this->m_joints = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(33)
		::haxor::io::FloatArray _g = ::haxor::io::FloatArray_obj::__new((int)8192);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(33)
		this->m_buffer = _g;
		HX_STACK_LINE(34)
		::haxor::graphics::texture::ComputeTexture _g1 = ::haxor::graphics::texture::ComputeTexture_obj::__new((int)1,(int)2048,::haxor::core::PixelFormat_obj::Float4);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(34)
		this->m_data = _g1;
		HX_STACK_LINE(35)
		int _g2 = this->get_uid();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(35)
		::String _g3 = (HX_CSTRING("SkinningTexture") + _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(35)
		this->m_data->set_name(_g3);
	}
return null();
}


Void SkinnedMeshRenderer_obj::OnRender( ){
{
		HX_STACK_FRAME("haxor.component.SkinnedMeshRenderer","OnRender",0xc0567ae0,"haxor.component.SkinnedMeshRenderer.OnRender","haxor/component/SkinnedMeshRenderer.hx",66,0x9853527d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(66)
		this->super::OnRender();
	}
return null();
}



SkinnedMeshRenderer_obj::SkinnedMeshRenderer_obj()
{
}

void SkinnedMeshRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SkinnedMeshRenderer);
	HX_MARK_MEMBER_NAME(m_joints,"m_joints");
	HX_MARK_MEMBER_NAME(m_buffer,"m_buffer");
	HX_MARK_MEMBER_NAME(m_data,"m_data");
	::haxor::component::MeshRenderer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SkinnedMeshRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_joints,"m_joints");
	HX_VISIT_MEMBER_NAME(m_buffer,"m_buffer");
	HX_VISIT_MEMBER_NAME(m_data,"m_data");
	::haxor::component::MeshRenderer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic SkinnedMeshRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"joints") ) { return get_joints(); }
		if (HX_FIELD_EQ(inName,"m_data") ) { return m_data; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_joints") ) { return m_joints; }
		if (HX_FIELD_EQ(inName,"m_buffer") ) { return m_buffer; }
		if (HX_FIELD_EQ(inName,"OnRender") ) { return OnRender_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_joints") ) { return set_joints_dyn(); }
		if (HX_FIELD_EQ(inName,"get_joints") ) { return get_joints_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SkinnedMeshRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"joints") ) { return set_joints(inValue); }
		if (HX_FIELD_EQ(inName,"m_data") ) { m_data=inValue.Cast< ::haxor::graphics::texture::ComputeTexture >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_joints") ) { m_joints=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_buffer") ) { m_buffer=inValue.Cast< ::haxor::io::FloatArray >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SkinnedMeshRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("joints"));
	outFields->push(HX_CSTRING("m_joints"));
	outFields->push(HX_CSTRING("m_buffer"));
	outFields->push(HX_CSTRING("m_data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(SkinnedMeshRenderer_obj,m_joints),HX_CSTRING("m_joints")},
	{hx::fsObject /*::haxor::io::FloatArray*/ ,(int)offsetof(SkinnedMeshRenderer_obj,m_buffer),HX_CSTRING("m_buffer")},
	{hx::fsObject /*::haxor::graphics::texture::ComputeTexture*/ ,(int)offsetof(SkinnedMeshRenderer_obj,m_data),HX_CSTRING("m_data")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("set_joints"),
	HX_CSTRING("get_joints"),
	HX_CSTRING("m_joints"),
	HX_CSTRING("m_buffer"),
	HX_CSTRING("m_data"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("OnRender"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SkinnedMeshRenderer_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SkinnedMeshRenderer_obj::__mClass,"__mClass");
};

#endif

Class SkinnedMeshRenderer_obj::__mClass;

void SkinnedMeshRenderer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.SkinnedMeshRenderer"), hx::TCanCast< SkinnedMeshRenderer_obj> ,sStaticFields,sMemberFields,
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

void SkinnedMeshRenderer_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
