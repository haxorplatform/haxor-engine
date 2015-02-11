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
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#include <haxor/graphics/mesh/Mesh.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh3
#include <haxor/graphics/mesh/Mesh3.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshLayout
#include <haxor/graphics/mesh/MeshLayout.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_SkinnedMesh3
#include <haxor/graphics/mesh/SkinnedMesh3.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#include <haxor/graphics/texture/Bitmap.h>
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
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
namespace haxor{
namespace component{

Void SkinnedMeshRenderer_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.SkinnedMeshRenderer","new",0xfc589b55,"haxor.component.SkinnedMeshRenderer.new","haxor/component/SkinnedMeshRenderer.hx",17,0x9853527d)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(17)
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
	HX_STACK_FRAME("haxor.component.SkinnedMeshRenderer","set_joints",0x5cdea3d1,"haxor.component.SkinnedMeshRenderer.set_joints","haxor/component/SkinnedMeshRenderer.hx",23,0x9853527d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(23)
	if (((v == null()))){
		HX_STACK_LINE(23)
		this->m_joints = Array_obj< ::Dynamic >::__new();
	}
	else{
		HX_STACK_LINE(23)
		this->m_joints = v;
	}
	HX_STACK_LINE(23)
	return this->m_joints;
}


HX_DEFINE_DYNAMIC_FUNC1(SkinnedMeshRenderer_obj,set_joints,return )

Array< ::Dynamic > SkinnedMeshRenderer_obj::get_joints( ){
	HX_STACK_FRAME("haxor.component.SkinnedMeshRenderer","get_joints",0x5961055d,"haxor.component.SkinnedMeshRenderer.get_joints","haxor/component/SkinnedMeshRenderer.hx",24,0x9853527d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(24)
	return this->m_joints;
}


HX_DEFINE_DYNAMIC_FUNC0(SkinnedMeshRenderer_obj,get_joints,return )

Void SkinnedMeshRenderer_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.SkinnedMeshRenderer","OnBuild",0x6ed78ae4,"haxor.component.SkinnedMeshRenderer.OnBuild","haxor/component/SkinnedMeshRenderer.hx",35,0x9853527d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(36)
		this->super::OnBuild();
		HX_STACK_LINE(37)
		this->m_joints = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(40)
		this->m_buffer = Array_obj< Float >::__new();
		HX_STACK_LINE(41)
		{
			HX_STACK_LINE(41)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(41)
			while((true)){
				HX_STACK_LINE(41)
				if ((!(((_g < (int)8192))))){
					HX_STACK_LINE(41)
					break;
				}
				HX_STACK_LINE(41)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(41)
				this->m_buffer->push((int)0);
			}
		}
		HX_STACK_LINE(42)
		::haxor::graphics::texture::ComputeTexture _g = ::haxor::graphics::texture::ComputeTexture_obj::__new((int)1,(int)2048,::haxor::core::PixelFormat_obj::Float4);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(42)
		this->m_data = _g;
		HX_STACK_LINE(43)
		int _g1 = this->get_uid();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(43)
		::String _g2 = (HX_CSTRING("SkinningTexture") + _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(43)
		this->m_data->set_name(_g2);
	}
return null();
}


Void SkinnedMeshRenderer_obj::OnRender( ){
{
		HX_STACK_FRAME("haxor.component.SkinnedMeshRenderer","OnRender",0xc0567ae0,"haxor.component.SkinnedMeshRenderer.OnRender","haxor/component/SkinnedMeshRenderer.hx",50,0x9853527d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(52)
		if (((this->m_material != null()))){
			HX_STACK_LINE(54)
			::haxor::graphics::mesh::SkinnedMesh3 skm = this->m_mesh;		HX_STACK_VAR(skm,"skm");
			HX_STACK_LINE(55)
			int k = (int)0;		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(56)
			::haxor::math::Matrix4 jm;		HX_STACK_VAR(jm,"jm");
			HX_STACK_LINE(57)
			::haxor::math::Matrix4 bm;		HX_STACK_VAR(bm,"bm");
			HX_STACK_LINE(58)
			::haxor::io::FloatArray f32 = this->m_data->m_data->get_buffer();		HX_STACK_VAR(f32,"f32");
			HX_STACK_LINE(62)
			{
				HX_STACK_LINE(62)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(62)
				int _g = this->m_joints->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(62)
				while((true)){
					HX_STACK_LINE(62)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(62)
						break;
					}
					HX_STACK_LINE(62)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(64)
					::haxor::math::Matrix4 _g2 = this->m_joints->__get(i).StaticCast< ::haxor::component::Transform >()->get_WorldMatrix();		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(64)
					jm = _g2;
					HX_STACK_LINE(65)
					Array< ::Dynamic > _g11 = skm->get_binds();		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(65)
					::haxor::math::Matrix4 _g21 = _g11->__get(i).StaticCast< ::haxor::math::Matrix4 >();		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(65)
					bm = _g21;
					HX_STACK_LINE(66)
					{
						HX_STACK_LINE(66)
						int _g22 = (int)0;		HX_STACK_VAR(_g22,"_g22");
						HX_STACK_LINE(66)
						while((true)){
							HX_STACK_LINE(66)
							if ((!(((_g22 < (int)12))))){
								HX_STACK_LINE(66)
								break;
							}
							HX_STACK_LINE(66)
							int j = (_g22)++;		HX_STACK_VAR(j,"j");
							HX_STACK_LINE(68)
							Float _g3 = jm->GetIndex(j);		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(68)
							f32->Set(k,_g3);
							HX_STACK_LINE(69)
							Float _g4 = bm->GetIndex(j);		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(69)
							f32->Set((k + (int)4096),_g4);
							HX_STACK_LINE(70)
							(k)++;
						}
					}
				}
			}
			HX_STACK_LINE(75)
			this->m_data->Invalidate();
			HX_STACK_LINE(77)
			this->m_material->SetTexture(HX_CSTRING("Skinning"),this->m_data);
		}
		HX_STACK_LINE(82)
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
		if (HX_FIELD_EQ(inName,"m_buffer") ) { m_buffer=inValue.Cast< Array< Float > >(); return inValue; }
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
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(SkinnedMeshRenderer_obj,m_buffer),HX_CSTRING("m_buffer")},
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
