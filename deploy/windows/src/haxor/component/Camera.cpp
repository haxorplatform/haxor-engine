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
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_context_CameraContext
#include <haxor/context/CameraContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_core_ClearFlag
#include <haxor/core/ClearFlag.h>
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
#ifndef INCLUDED_haxor_graphics_texture_RenderTexture
#include <haxor/graphics/texture/RenderTexture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_TextureCube
#include <haxor/graphics/texture/TextureCube.h>
#endif
#ifndef INCLUDED_haxor_math_AABB2
#include <haxor/math/AABB2.h>
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
#ifndef INCLUDED_haxor_math_Vector4
#include <haxor/math/Vector4.h>
#endif
namespace haxor{
namespace component{

Void Camera_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.Camera","new",0x924d47f4,"haxor.component.Camera.new","haxor/component/Camera.hx",25,0xf5fa0e7a)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(25)
	super::__construct(p_name);
}
;
	return null();
}

//Camera_obj::~Camera_obj() { }

Dynamic Camera_obj::__CreateEmpty() { return  new Camera_obj; }
hx::ObjectPtr< Camera_obj > Camera_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< Camera_obj > result = new Camera_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic Camera_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Camera_obj > result = new Camera_obj();
	result->__construct(inArgs[0]);
	return result;}

int Camera_obj::get_mask( ){
	HX_STACK_FRAME("haxor.component.Camera","get_mask",0x14398c61,"haxor.component.Camera.get_mask","haxor/component/Camera.hx",76,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(76)
	return this->m_mask;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_mask,return )

int Camera_obj::set_mask( int v){
	HX_STACK_FRAME("haxor.component.Camera","set_mask",0xc296e5d5,"haxor.component.Camera.set_mask","haxor/component/Camera.hx",78,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(79)
	if (((this->m_mask == v))){
		HX_STACK_LINE(79)
		return v;
	}
	HX_STACK_LINE(80)
	this->m_mask = v;
	HX_STACK_LINE(81)
	int it = this->m_mask;		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(82)
	this->m_layers = Array_obj< int >::__new();
	HX_STACK_LINE(83)
	{
		HX_STACK_LINE(83)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(83)
		while((true)){
			HX_STACK_LINE(83)
			if ((!(((_g < (int)32))))){
				HX_STACK_LINE(83)
				break;
			}
			HX_STACK_LINE(83)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(85)
			if (((((int(it) & int((int)1))) != (int)0))){
				HX_STACK_LINE(85)
				this->m_layers->push((int((int)1) << int(i)));
			}
			HX_STACK_LINE(86)
			it = (int(it) >> int((int)1));
		}
	}
	HX_STACK_LINE(88)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_mask,return )

Float Camera_obj::get_fov( ){
	HX_STACK_FRAME("haxor.component.Camera","get_fov",0x8f916138,"haxor.component.Camera.get_fov","haxor/component/Camera.hx",98,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(98)
	return this->m_fov;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_fov,return )

Float Camera_obj::set_fov( Float v){
	HX_STACK_FRAME("haxor.component.Camera","set_fov",0x8292f244,"haxor.component.Camera.set_fov","haxor/component/Camera.hx",99,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(99)
	this->m_fov = v;
	HX_STACK_LINE(99)
	this->m_projection_dirty = true;
	HX_STACK_LINE(99)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_fov,return )

Float Camera_obj::get_near( ){
	HX_STACK_FRAME("haxor.component.Camera","get_near",0x14e5bc5d,"haxor.component.Camera.get_near","haxor/component/Camera.hx",106,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(106)
	return this->m_near;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_near,return )

Float Camera_obj::set_near( Float v){
	HX_STACK_FRAME("haxor.component.Camera","set_near",0xc34315d1,"haxor.component.Camera.set_near","haxor/component/Camera.hx",107,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(107)
	this->m_near = v;
	HX_STACK_LINE(107)
	this->m_projection_dirty = true;
	HX_STACK_LINE(107)
	this->m_proj_uniform_dirty = true;
	HX_STACK_LINE(107)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_near,return )

Float Camera_obj::get_far( ){
	HX_STACK_FRAME("haxor.component.Camera","get_far",0x8f915502,"haxor.component.Camera.get_far","haxor/component/Camera.hx",114,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(114)
	return this->m_far;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_far,return )

Float Camera_obj::set_far( Float v){
	HX_STACK_FRAME("haxor.component.Camera","set_far",0x8292e60e,"haxor.component.Camera.set_far","haxor/component/Camera.hx",115,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(115)
	this->m_far = v;
	HX_STACK_LINE(115)
	this->m_projection_dirty = true;
	HX_STACK_LINE(115)
	this->m_proj_uniform_dirty = true;
	HX_STACK_LINE(115)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_far,return )

int Camera_obj::get_order( ){
	HX_STACK_FRAME("haxor.component.Camera","get_order",0xd01fab79,"haxor.component.Camera.get_order","haxor/component/Camera.hx",123,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(123)
	return this->m_order;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_order,return )

int Camera_obj::set_order( int v){
	HX_STACK_FRAME("haxor.component.Camera","set_order",0xb3709785,"haxor.component.Camera.set_order","haxor/component/Camera.hx",124,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(124)
	if (((this->m_order == v))){
		HX_STACK_LINE(124)
		return v;
	}
	HX_STACK_LINE(124)
	this->m_order = v;
	HX_STACK_LINE(124)
	::haxor::context::EngineContext_obj::camera->SortCameraList();
	HX_STACK_LINE(124)
	return this->m_order;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_order,return )

::haxor::math::AABB2 Camera_obj::get_pixelViewport( ){
	HX_STACK_FRAME("haxor.component.Camera","get_pixelViewport",0x0871e2f7,"haxor.component.Camera.get_pixelViewport","haxor/component/Camera.hx",130,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(130)
	return this->m_pixelViewport->get_clone();
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_pixelViewport,return )

::haxor::math::AABB2 Camera_obj::get_viewport( ){
	HX_STACK_FRAME("haxor.component.Camera","get_viewport",0x016bf65b,"haxor.component.Camera.get_viewport","haxor/component/Camera.hx",138,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(138)
	return this->m_viewport->get_clone();
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_viewport,return )

::haxor::math::AABB2 Camera_obj::set_viewport( ::haxor::math::AABB2 v){
	HX_STACK_FRAME("haxor.component.Camera","set_viewport",0x166519cf,"haxor.component.Camera.set_viewport","haxor/component/Camera.hx",139,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(139)
	this->m_viewport->SetAABB2(v);
	HX_STACK_LINE(139)
	::haxor::context::EngineContext_obj::camera->UpdateViewport(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(139)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_viewport,return )

::haxor::math::Matrix4 Camera_obj::get_CameraToWorld( ){
	HX_STACK_FRAME("haxor.component.Camera","get_CameraToWorld",0xbdba807d,"haxor.component.Camera.get_CameraToWorld","haxor/component/Camera.hx",147,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(147)
	return this->m_entity->m_transform->get_WorldMatrix();
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_CameraToWorld,return )

::haxor::math::Matrix4 Camera_obj::get_WorldToCamera( ){
	HX_STACK_FRAME("haxor.component.Camera","get_WorldToCamera",0xaa8f50bd,"haxor.component.Camera.get_WorldToCamera","haxor/component/Camera.hx",154,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(154)
	return this->m_entity->m_transform->get_WorldMatrixInverse();
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_WorldToCamera,return )

::haxor::math::Matrix4 Camera_obj::get_ProjectionMatrix( ){
	HX_STACK_FRAME("haxor.component.Camera","get_ProjectionMatrix",0xc4d78b45,"haxor.component.Camera.get_ProjectionMatrix","haxor/component/Camera.hx",161,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(161)
	this->UpdateProjection();
	HX_STACK_LINE(161)
	return this->m_projectionMatrix;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_ProjectionMatrix,return )

::haxor::math::Matrix4 Camera_obj::get_ProjectionMatrixInverse( ){
	HX_STACK_FRAME("haxor.component.Camera","get_ProjectionMatrixInverse",0x6ddb0aeb,"haxor.component.Camera.get_ProjectionMatrixInverse","haxor/component/Camera.hx",169,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(169)
	this->UpdateProjection();
	HX_STACK_LINE(169)
	return this->m_projectionMatrixInverse;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_ProjectionMatrixInverse,return )

::haxor::graphics::texture::RenderTexture Camera_obj::get_target( ){
	HX_STACK_FRAME("haxor.component.Camera","get_target",0x8ad1c606,"haxor.component.Camera.get_target","haxor/component/Camera.hx",177,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(177)
	return this->m_target;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_target,return )

::haxor::graphics::texture::RenderTexture Camera_obj::set_target( ::haxor::graphics::texture::RenderTexture v){
	HX_STACK_FRAME("haxor.component.Camera","set_target",0x8e4f647a,"haxor.component.Camera.set_target","haxor/component/Camera.hx",178,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(178)
	this->m_target = v;
	HX_STACK_LINE(178)
	::haxor::context::EngineContext_obj::camera->UpdateViewport(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(178)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_target,return )

Float Camera_obj::get_quality( ){
	HX_STACK_FRAME("haxor.component.Camera","get_quality",0xa89f906a,"haxor.component.Camera.get_quality","haxor/component/Camera.hx",185,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(185)
	return this->m_quality;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_quality,return )

Float Camera_obj::set_quality( Float v){
	HX_STACK_FRAME("haxor.component.Camera","set_quality",0xb30c9776,"haxor.component.Camera.set_quality","haxor/component/Camera.hx",186,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(186)
	if (((v <= 0.0))){
		HX_STACK_LINE(186)
		this->m_quality = 0.0;
	}
	else{
		HX_STACK_LINE(186)
		if (((v >= 1.0))){
			HX_STACK_LINE(186)
			this->m_quality = 1.0;
		}
		else{
			HX_STACK_LINE(186)
			this->m_quality = v;
		}
	}
	HX_STACK_LINE(186)
	::haxor::context::EngineContext_obj::camera->UpdateViewport(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(186)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_quality,return )

bool Camera_obj::get_captureDepth( ){
	HX_STACK_FRAME("haxor.component.Camera","get_captureDepth",0x75413312,"haxor.component.Camera.get_captureDepth","haxor/component/Camera.hx",193,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(193)
	return this->m_captureDepth;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_captureDepth,return )

bool Camera_obj::set_captureDepth( bool v){
	HX_STACK_FRAME("haxor.component.Camera","set_captureDepth",0xcb832086,"haxor.component.Camera.set_captureDepth","haxor/component/Camera.hx",194,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(194)
	this->m_captureDepth = v;
	HX_STACK_LINE(194)
	::haxor::context::EngineContext_obj::camera->ClearTargets(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(194)
	::haxor::context::EngineContext_obj::camera->UpdateViewport(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(194)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_captureDepth,return )

Dynamic Camera_obj::get_filters( ){
	HX_STACK_FRAME("haxor.component.Camera","get_filters",0x6d9a2d66,"haxor.component.Camera.get_filters","haxor/component/Camera.hx",201,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(201)
	return this->m_filters;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_filters,return )

Dynamic Camera_obj::set_filters( Dynamic v){
	HX_STACK_FRAME("haxor.component.Camera","set_filters",0x78073472,"haxor.component.Camera.set_filters","haxor/component/Camera.hx",203,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(204)
	if (((v == null()))){
		HX_STACK_LINE(204)
		this->m_filters = Dynamic( Array_obj<Dynamic>::__new());
	}
	else{
		HX_STACK_LINE(204)
		this->m_filters = v;
	}
	HX_STACK_LINE(205)
	return this->m_filters;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_filters,return )

Void Camera_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.Camera","OnBuild",0x87487303,"haxor.component.Camera.OnBuild","haxor/component/Camera.hx",238,0xf5fa0e7a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(239)
		this->super::OnBuild();
		HX_STACK_LINE(240)
		::haxor::context::EngineContext_obj::camera->Create(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(241)
		if (((::haxor::component::Camera_obj::m_main == null()))){
			HX_STACK_LINE(241)
			::haxor::component::Camera_obj::m_main = hx::ObjectPtr<OBJ_>(this);
		}
		HX_STACK_LINE(242)
		this->m_order = (int)0;
		HX_STACK_LINE(243)
		this->m_quality = 1.0;
		HX_STACK_LINE(244)
		::haxor::math::AABB2 _g = ::haxor::math::AABB2_obj::get_empty();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(244)
		this->m_pixelViewport = _g;
		HX_STACK_LINE(245)
		::haxor::math::AABB2 _g1 = ::haxor::math::AABB2_obj::get_empty();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(245)
		this->m_viewport = _g1;
		HX_STACK_LINE(246)
		::haxor::math::Matrix4 _g2 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(246)
		this->m_projectionMatrix = _g2;
		HX_STACK_LINE(247)
		::haxor::math::Matrix4 _g3 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(247)
		this->m_projectionMatrixInverse = _g3;
		HX_STACK_LINE(248)
		::haxor::math::Matrix4 _g4 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(248)
		this->m_skyboxProjection = _g4;
		HX_STACK_LINE(249)
		::haxor::math::Matrix4 _g5 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(249)
		this->m_skyboxProjectionInverse = _g5;
		HX_STACK_LINE(250)
		this->m_fov = (int)60;
		HX_STACK_LINE(251)
		this->m_near = 0.1;
		HX_STACK_LINE(252)
		this->m_far = (int)500;
		HX_STACK_LINE(253)
		this->m_filters = Dynamic( Array_obj<Dynamic>::__new());
		HX_STACK_LINE(254)
		::haxor::math::Color _g6 = ::haxor::math::Color_obj::__new((int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(254)
		this->background = _g6;
		HX_STACK_LINE(255)
		this->clear = ::haxor::core::ClearFlag_obj::ColorDepth;
		HX_STACK_LINE(256)
		this->set_mask((int)1);
		HX_STACK_LINE(257)
		{
			HX_STACK_LINE(257)
			::haxor::math::AABB2 v = ::haxor::math::AABB2_obj::__new((int)0,(int)0,(int)1,(int)1);		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(257)
			this->m_viewport->SetAABB2(v);
			HX_STACK_LINE(257)
			::haxor::context::EngineContext_obj::camera->UpdateViewport(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(257)
			v;
		}
		HX_STACK_LINE(258)
		this->m_projection_dirty = true;
		HX_STACK_LINE(259)
		this->m_view_uniform_dirty = true;
		HX_STACK_LINE(260)
		this->m_proj_uniform_dirty = true;
		HX_STACK_LINE(262)
		::haxor::math::Vector4 _g7 = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(262)
		this->m_fn0 = _g7;
		HX_STACK_LINE(263)
		::haxor::math::Vector4 _g8 = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(263)
		this->m_fn1 = _g8;
		HX_STACK_LINE(264)
		::haxor::math::Vector4 _g9 = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(264)
		this->m_fn2 = _g9;
		HX_STACK_LINE(265)
		::haxor::math::Vector4 _g10 = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(265)
		this->m_fn3 = _g10;
		HX_STACK_LINE(266)
		::haxor::math::Vector4 _g11 = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(266)
		this->m_ff0 = _g11;
		HX_STACK_LINE(267)
		::haxor::math::Vector4 _g12 = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(267)
		this->m_ff1 = _g12;
		HX_STACK_LINE(268)
		::haxor::math::Vector4 _g13 = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(268)
		this->m_ff2 = _g13;
		HX_STACK_LINE(269)
		::haxor::math::Vector4 _g14 = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(269)
		this->m_ff3 = _g14;
	}
return null();
}


::haxor::math::Vector4 Camera_obj::WorldToProjection( ::haxor::math::Vector3 p_world_point,::haxor::math::Vector4 p_result){
	HX_STACK_FRAME("haxor.component.Camera","WorldToProjection",0x920ca1d0,"haxor.component.Camera.WorldToProjection","haxor/component/Camera.hx",280,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_world_point,"p_world_point")
	HX_STACK_ARG(p_result,"p_result")
	HX_STACK_LINE(281)
	::haxor::math::Vector4 p;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(281)
	if (((p_result == null()))){
		HX_STACK_LINE(281)
		p = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());
	}
	else{
		HX_STACK_LINE(281)
		p = p_result;
	}
	HX_STACK_LINE(282)
	p->w = 1.0;
	HX_STACK_LINE(283)
	p->x = p_world_point->x;
	HX_STACK_LINE(284)
	p->y = p_world_point->y;
	HX_STACK_LINE(285)
	p->z = p_world_point->z;
	HX_STACK_LINE(286)
	{
		HX_STACK_LINE(286)
		::haxor::math::Matrix4 _this = this->get_WorldToCamera();		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(286)
		Float vx = ((((_this->m00 * p->x) + (_this->m01 * p->y)) + (_this->m02 * p->z)) + (_this->m03 * p->w));		HX_STACK_VAR(vx,"vx");
		HX_STACK_LINE(286)
		Float vy = ((((_this->m10 * p->x) + (_this->m11 * p->y)) + (_this->m12 * p->z)) + (_this->m13 * p->w));		HX_STACK_VAR(vy,"vy");
		HX_STACK_LINE(286)
		Float vz = ((((_this->m20 * p->x) + (_this->m21 * p->y)) + (_this->m22 * p->z)) + (_this->m23 * p->w));		HX_STACK_VAR(vz,"vz");
		HX_STACK_LINE(286)
		Float vw = ((((_this->m30 * p->x) + (_this->m31 * p->y)) + (_this->m32 * p->z)) + (_this->m33 * p->w));		HX_STACK_VAR(vw,"vw");
		HX_STACK_LINE(286)
		p->x = vx;
		HX_STACK_LINE(286)
		p->y = vy;
		HX_STACK_LINE(286)
		p->z = vz;
		HX_STACK_LINE(286)
		p->w = vw;
		HX_STACK_LINE(286)
		p;
	}
	HX_STACK_LINE(287)
	{
		HX_STACK_LINE(287)
		::haxor::math::Matrix4 _this;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(287)
		{
			HX_STACK_LINE(287)
			this->UpdateProjection();
			HX_STACK_LINE(287)
			_this = this->m_projectionMatrix;
		}
		HX_STACK_LINE(287)
		Float vx = ((((_this->m00 * p->x) + (_this->m01 * p->y)) + (_this->m02 * p->z)) + (_this->m03 * p->w));		HX_STACK_VAR(vx,"vx");
		HX_STACK_LINE(287)
		Float vy = ((((_this->m10 * p->x) + (_this->m11 * p->y)) + (_this->m12 * p->z)) + (_this->m13 * p->w));		HX_STACK_VAR(vy,"vy");
		HX_STACK_LINE(287)
		Float vz = ((((_this->m20 * p->x) + (_this->m21 * p->y)) + (_this->m22 * p->z)) + (_this->m23 * p->w));		HX_STACK_VAR(vz,"vz");
		HX_STACK_LINE(287)
		Float vw = ((((_this->m30 * p->x) + (_this->m31 * p->y)) + (_this->m32 * p->z)) + (_this->m33 * p->w));		HX_STACK_VAR(vw,"vw");
		HX_STACK_LINE(287)
		p->x = vx;
		HX_STACK_LINE(287)
		p->y = vy;
		HX_STACK_LINE(287)
		p->z = vz;
		HX_STACK_LINE(287)
		p->w = vw;
		HX_STACK_LINE(287)
		p;
	}
	HX_STACK_LINE(288)
	return p;
}


HX_DEFINE_DYNAMIC_FUNC2(Camera_obj,WorldToProjection,return )

Float Camera_obj::WorldToDepth( ::haxor::math::Vector3 p_world_point){
	HX_STACK_FRAME("haxor.component.Camera","WorldToDepth",0x4fe15f62,"haxor.component.Camera.WorldToDepth","haxor/component/Camera.hx",297,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_world_point,"p_world_point")
	HX_STACK_LINE(298)
	::haxor::math::Matrix4 wm = this->get_WorldToCamera();		HX_STACK_VAR(wm,"wm");
	HX_STACK_LINE(299)
	return ((((wm->m20 * p_world_point->x) + (wm->m21 * p_world_point->y)) + (wm->m22 * p_world_point->z)) + wm->m23);
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,WorldToDepth,return )

bool Camera_obj::IsCulled( ::haxor::math::Vector3 p_world_point){
	HX_STACK_FRAME("haxor.component.Camera","IsCulled",0xb92fd627,"haxor.component.Camera.IsCulled","haxor/component/Camera.hx",309,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_world_point,"p_world_point")
	HX_STACK_LINE(309)
	return this->WorldToProjection(p_world_point,null())->IsCulled();
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,IsCulled,return )

Void Camera_obj::LookAt( ::haxor::math::Vector3 p_at,::haxor::math::Vector3 p_up,hx::Null< Float >  __o_p_smooth){
Float p_smooth = __o_p_smooth.Default(0.0);
	HX_STACK_FRAME("haxor.component.Camera","LookAt",0xd028663e,"haxor.component.Camera.LookAt","haxor/component/Camera.hx",318,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_at,"p_at")
	HX_STACK_ARG(p_up,"p_up")
	HX_STACK_ARG(p_smooth,"p_smooth")
{
		HX_STACK_LINE(318)
		this->m_entity->m_transform->LookAt(p_at,p_up,p_smooth);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Camera_obj,LookAt,(void))

Void Camera_obj::UpdateProjection( ){
{
		HX_STACK_FRAME("haxor.component.Camera","UpdateProjection",0x2cce9004,"haxor.component.Camera.UpdateProjection","haxor/component/Camera.hx",324,0xf5fa0e7a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(325)
		if ((!(this->m_projection_dirty))){
			HX_STACK_LINE(325)
			return null();
		}
		HX_STACK_LINE(326)
		this->m_projection_dirty = false;
		HX_STACK_LINE(327)
		this->m_view_uniform_dirty = true;
		HX_STACK_LINE(328)
		::haxor::math::Matrix4_obj::Perspective(this->m_fov,this->m_aspect,this->m_near,this->m_far,this->m_projectionMatrix);
		HX_STACK_LINE(329)
		::haxor::math::Matrix4_obj::PerspectiveInverse(this->m_fov,this->m_aspect,this->m_near,this->m_far,this->m_projectionMatrixInverse);
		HX_STACK_LINE(330)
		::haxor::math::Matrix4_obj::Perspective(this->m_fov,this->m_aspect,0.1,100000.0,this->m_skyboxProjection);
		HX_STACK_LINE(331)
		::haxor::math::Matrix4_obj::PerspectiveInverse(this->m_fov,this->m_aspect,0.1,100000.0,this->m_skyboxProjectionInverse);
		HX_STACK_LINE(333)
		::haxor::math::Vector4 p;		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(334)
		Float iw;		HX_STACK_VAR(iw,"iw");
		HX_STACK_LINE(335)
		p = this->m_fn0;
		HX_STACK_LINE(335)
		p->Set(-1.0,1.0,0.0,1.0);
		HX_STACK_LINE(335)
		{
			HX_STACK_LINE(335)
			::haxor::math::Matrix4 _this = this->m_projectionMatrixInverse;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(335)
			Float vx = ((((_this->m00 * p->x) + (_this->m01 * p->y)) + (_this->m02 * p->z)) + (_this->m03 * p->w));		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(335)
			Float vy = ((((_this->m10 * p->x) + (_this->m11 * p->y)) + (_this->m12 * p->z)) + (_this->m13 * p->w));		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(335)
			Float vz = ((((_this->m20 * p->x) + (_this->m21 * p->y)) + (_this->m22 * p->z)) + (_this->m23 * p->w));		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(335)
			Float vw = ((((_this->m30 * p->x) + (_this->m31 * p->y)) + (_this->m32 * p->z)) + (_this->m33 * p->w));		HX_STACK_VAR(vw,"vw");
			HX_STACK_LINE(335)
			p->x = vx;
			HX_STACK_LINE(335)
			p->y = vy;
			HX_STACK_LINE(335)
			p->z = vz;
			HX_STACK_LINE(335)
			p->w = vw;
			HX_STACK_LINE(335)
			p;
		}
		HX_STACK_LINE(335)
		if (((p->w <= 0.0))){
			HX_STACK_LINE(335)
			iw = 0.0;
		}
		else{
			HX_STACK_LINE(335)
			iw = (Float(1.0) / Float(p->w));
		}
		HX_STACK_LINE(335)
		p->Scale(iw);
		HX_STACK_LINE(336)
		p = this->m_fn1;
		HX_STACK_LINE(336)
		p->Set(1.0,1.0,0.0,1.0);
		HX_STACK_LINE(336)
		{
			HX_STACK_LINE(336)
			::haxor::math::Matrix4 _this = this->m_projectionMatrixInverse;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(336)
			Float vx = ((((_this->m00 * p->x) + (_this->m01 * p->y)) + (_this->m02 * p->z)) + (_this->m03 * p->w));		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(336)
			Float vy = ((((_this->m10 * p->x) + (_this->m11 * p->y)) + (_this->m12 * p->z)) + (_this->m13 * p->w));		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(336)
			Float vz = ((((_this->m20 * p->x) + (_this->m21 * p->y)) + (_this->m22 * p->z)) + (_this->m23 * p->w));		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(336)
			Float vw = ((((_this->m30 * p->x) + (_this->m31 * p->y)) + (_this->m32 * p->z)) + (_this->m33 * p->w));		HX_STACK_VAR(vw,"vw");
			HX_STACK_LINE(336)
			p->x = vx;
			HX_STACK_LINE(336)
			p->y = vy;
			HX_STACK_LINE(336)
			p->z = vz;
			HX_STACK_LINE(336)
			p->w = vw;
			HX_STACK_LINE(336)
			p;
		}
		HX_STACK_LINE(336)
		if (((p->w <= 0.0))){
			HX_STACK_LINE(336)
			iw = 0.0;
		}
		else{
			HX_STACK_LINE(336)
			iw = (Float(1.0) / Float(p->w));
		}
		HX_STACK_LINE(336)
		p->Scale(iw);
		HX_STACK_LINE(337)
		p = this->m_fn2;
		HX_STACK_LINE(337)
		p->Set(-1.0,-1.0,0.0,1.0);
		HX_STACK_LINE(337)
		{
			HX_STACK_LINE(337)
			::haxor::math::Matrix4 _this = this->m_projectionMatrixInverse;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(337)
			Float vx = ((((_this->m00 * p->x) + (_this->m01 * p->y)) + (_this->m02 * p->z)) + (_this->m03 * p->w));		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(337)
			Float vy = ((((_this->m10 * p->x) + (_this->m11 * p->y)) + (_this->m12 * p->z)) + (_this->m13 * p->w));		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(337)
			Float vz = ((((_this->m20 * p->x) + (_this->m21 * p->y)) + (_this->m22 * p->z)) + (_this->m23 * p->w));		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(337)
			Float vw = ((((_this->m30 * p->x) + (_this->m31 * p->y)) + (_this->m32 * p->z)) + (_this->m33 * p->w));		HX_STACK_VAR(vw,"vw");
			HX_STACK_LINE(337)
			p->x = vx;
			HX_STACK_LINE(337)
			p->y = vy;
			HX_STACK_LINE(337)
			p->z = vz;
			HX_STACK_LINE(337)
			p->w = vw;
			HX_STACK_LINE(337)
			p;
		}
		HX_STACK_LINE(337)
		if (((p->w <= 0.0))){
			HX_STACK_LINE(337)
			iw = 0.0;
		}
		else{
			HX_STACK_LINE(337)
			iw = (Float(1.0) / Float(p->w));
		}
		HX_STACK_LINE(337)
		p->Scale(iw);
		HX_STACK_LINE(338)
		p = this->m_fn3;
		HX_STACK_LINE(338)
		p->Set(1.0,-1.0,0.0,1.0);
		HX_STACK_LINE(338)
		{
			HX_STACK_LINE(338)
			::haxor::math::Matrix4 _this = this->m_projectionMatrixInverse;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(338)
			Float vx = ((((_this->m00 * p->x) + (_this->m01 * p->y)) + (_this->m02 * p->z)) + (_this->m03 * p->w));		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(338)
			Float vy = ((((_this->m10 * p->x) + (_this->m11 * p->y)) + (_this->m12 * p->z)) + (_this->m13 * p->w));		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(338)
			Float vz = ((((_this->m20 * p->x) + (_this->m21 * p->y)) + (_this->m22 * p->z)) + (_this->m23 * p->w));		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(338)
			Float vw = ((((_this->m30 * p->x) + (_this->m31 * p->y)) + (_this->m32 * p->z)) + (_this->m33 * p->w));		HX_STACK_VAR(vw,"vw");
			HX_STACK_LINE(338)
			p->x = vx;
			HX_STACK_LINE(338)
			p->y = vy;
			HX_STACK_LINE(338)
			p->z = vz;
			HX_STACK_LINE(338)
			p->w = vw;
			HX_STACK_LINE(338)
			p;
		}
		HX_STACK_LINE(338)
		if (((p->w <= 0.0))){
			HX_STACK_LINE(338)
			iw = 0.0;
		}
		else{
			HX_STACK_LINE(338)
			iw = (Float(1.0) / Float(p->w));
		}
		HX_STACK_LINE(338)
		p->Scale(iw);
		HX_STACK_LINE(340)
		p = this->m_ff0;
		HX_STACK_LINE(340)
		p->Set(-1.0,1.0,1.0,1.0);
		HX_STACK_LINE(340)
		{
			HX_STACK_LINE(340)
			::haxor::math::Matrix4 _this = this->m_projectionMatrixInverse;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(340)
			Float vx = ((((_this->m00 * p->x) + (_this->m01 * p->y)) + (_this->m02 * p->z)) + (_this->m03 * p->w));		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(340)
			Float vy = ((((_this->m10 * p->x) + (_this->m11 * p->y)) + (_this->m12 * p->z)) + (_this->m13 * p->w));		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(340)
			Float vz = ((((_this->m20 * p->x) + (_this->m21 * p->y)) + (_this->m22 * p->z)) + (_this->m23 * p->w));		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(340)
			Float vw = ((((_this->m30 * p->x) + (_this->m31 * p->y)) + (_this->m32 * p->z)) + (_this->m33 * p->w));		HX_STACK_VAR(vw,"vw");
			HX_STACK_LINE(340)
			p->x = vx;
			HX_STACK_LINE(340)
			p->y = vy;
			HX_STACK_LINE(340)
			p->z = vz;
			HX_STACK_LINE(340)
			p->w = vw;
			HX_STACK_LINE(340)
			p;
		}
		HX_STACK_LINE(340)
		if (((p->w <= 0.0))){
			HX_STACK_LINE(340)
			iw = 0.0;
		}
		else{
			HX_STACK_LINE(340)
			iw = (Float(1.0) / Float(p->w));
		}
		HX_STACK_LINE(340)
		p->Scale(iw);
		HX_STACK_LINE(341)
		p = this->m_ff1;
		HX_STACK_LINE(341)
		p->Set(1.0,1.0,1.0,1.0);
		HX_STACK_LINE(341)
		{
			HX_STACK_LINE(341)
			::haxor::math::Matrix4 _this = this->m_projectionMatrixInverse;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(341)
			Float vx = ((((_this->m00 * p->x) + (_this->m01 * p->y)) + (_this->m02 * p->z)) + (_this->m03 * p->w));		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(341)
			Float vy = ((((_this->m10 * p->x) + (_this->m11 * p->y)) + (_this->m12 * p->z)) + (_this->m13 * p->w));		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(341)
			Float vz = ((((_this->m20 * p->x) + (_this->m21 * p->y)) + (_this->m22 * p->z)) + (_this->m23 * p->w));		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(341)
			Float vw = ((((_this->m30 * p->x) + (_this->m31 * p->y)) + (_this->m32 * p->z)) + (_this->m33 * p->w));		HX_STACK_VAR(vw,"vw");
			HX_STACK_LINE(341)
			p->x = vx;
			HX_STACK_LINE(341)
			p->y = vy;
			HX_STACK_LINE(341)
			p->z = vz;
			HX_STACK_LINE(341)
			p->w = vw;
			HX_STACK_LINE(341)
			p;
		}
		HX_STACK_LINE(341)
		if (((p->w <= 0.0))){
			HX_STACK_LINE(341)
			iw = 0.0;
		}
		else{
			HX_STACK_LINE(341)
			iw = (Float(1.0) / Float(p->w));
		}
		HX_STACK_LINE(341)
		p->Scale(iw);
		HX_STACK_LINE(342)
		p = this->m_ff2;
		HX_STACK_LINE(342)
		p->Set(-1.0,-1.0,1.0,1.0);
		HX_STACK_LINE(342)
		{
			HX_STACK_LINE(342)
			::haxor::math::Matrix4 _this = this->m_projectionMatrixInverse;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(342)
			Float vx = ((((_this->m00 * p->x) + (_this->m01 * p->y)) + (_this->m02 * p->z)) + (_this->m03 * p->w));		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(342)
			Float vy = ((((_this->m10 * p->x) + (_this->m11 * p->y)) + (_this->m12 * p->z)) + (_this->m13 * p->w));		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(342)
			Float vz = ((((_this->m20 * p->x) + (_this->m21 * p->y)) + (_this->m22 * p->z)) + (_this->m23 * p->w));		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(342)
			Float vw = ((((_this->m30 * p->x) + (_this->m31 * p->y)) + (_this->m32 * p->z)) + (_this->m33 * p->w));		HX_STACK_VAR(vw,"vw");
			HX_STACK_LINE(342)
			p->x = vx;
			HX_STACK_LINE(342)
			p->y = vy;
			HX_STACK_LINE(342)
			p->z = vz;
			HX_STACK_LINE(342)
			p->w = vw;
			HX_STACK_LINE(342)
			p;
		}
		HX_STACK_LINE(342)
		if (((p->w <= 0.0))){
			HX_STACK_LINE(342)
			iw = 0.0;
		}
		else{
			HX_STACK_LINE(342)
			iw = (Float(1.0) / Float(p->w));
		}
		HX_STACK_LINE(342)
		p->Scale(iw);
		HX_STACK_LINE(343)
		p = this->m_ff3;
		HX_STACK_LINE(343)
		p->Set(1.0,-1.0,1.0,1.0);
		HX_STACK_LINE(343)
		{
			HX_STACK_LINE(343)
			::haxor::math::Matrix4 _this = this->m_projectionMatrixInverse;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(343)
			Float vx = ((((_this->m00 * p->x) + (_this->m01 * p->y)) + (_this->m02 * p->z)) + (_this->m03 * p->w));		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(343)
			Float vy = ((((_this->m10 * p->x) + (_this->m11 * p->y)) + (_this->m12 * p->z)) + (_this->m13 * p->w));		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(343)
			Float vz = ((((_this->m20 * p->x) + (_this->m21 * p->y)) + (_this->m22 * p->z)) + (_this->m23 * p->w));		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(343)
			Float vw = ((((_this->m30 * p->x) + (_this->m31 * p->y)) + (_this->m32 * p->z)) + (_this->m33 * p->w));		HX_STACK_VAR(vw,"vw");
			HX_STACK_LINE(343)
			p->x = vx;
			HX_STACK_LINE(343)
			p->y = vy;
			HX_STACK_LINE(343)
			p->z = vz;
			HX_STACK_LINE(343)
			p->w = vw;
			HX_STACK_LINE(343)
			p;
		}
		HX_STACK_LINE(343)
		if (((p->w <= 0.0))){
			HX_STACK_LINE(343)
			iw = 0.0;
		}
		else{
			HX_STACK_LINE(343)
			iw = (Float(1.0) / Float(p->w));
		}
		HX_STACK_LINE(343)
		p->Scale(iw);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,UpdateProjection,(void))

Void Camera_obj::OnTransformUpdate( ){
{
		HX_STACK_FRAME("haxor.component.Camera","OnTransformUpdate",0xef4a94aa,"haxor.component.Camera.OnTransformUpdate","haxor/component/Camera.hx",351,0xf5fa0e7a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(351)
		this->m_view_uniform_dirty = true;
	}
return null();
}


Void Camera_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.component.Camera","OnDestroy",0xf559240f,"haxor.component.Camera.OnDestroy","haxor/component/Camera.hx",359,0xf5fa0e7a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(359)
		::haxor::context::EngineContext_obj::camera->Destroy(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


bool Camera_obj::sap;

Array< ::Dynamic > Camera_obj::get_list( ){
	HX_STACK_FRAME("haxor.component.Camera","get_list",0x139667d3,"haxor.component.Camera.get_list","haxor/component/Camera.hx",36,0xf5fa0e7a)
	HX_STACK_LINE(36)
	return ::haxor::context::EngineContext_obj::camera->list->copy();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_list,return )

::haxor::component::Camera Camera_obj::get_current( ){
	HX_STACK_FRAME("haxor.component.Camera","get_current",0x303727e4,"haxor.component.Camera.get_current","haxor/component/Camera.hx",41,0xf5fa0e7a)
	HX_STACK_LINE(41)
	return ::haxor::component::Camera_obj::m_current;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_current,return )

::haxor::component::Camera Camera_obj::m_current;

::haxor::component::Camera Camera_obj::get_main( ){
	HX_STACK_FRAME("haxor.component.Camera","get_main",0x143983ae,"haxor.component.Camera.get_main","haxor/component/Camera.hx",48,0xf5fa0e7a)
	HX_STACK_LINE(48)
	return ::haxor::component::Camera_obj::m_main;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_main,return )

::haxor::component::Camera Camera_obj::set_main( ::haxor::component::Camera v){
	HX_STACK_FRAME("haxor.component.Camera","set_main",0xc296dd22,"haxor.component.Camera.set_main","haxor/component/Camera.hx",49,0xf5fa0e7a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(49)
	return ::haxor::component::Camera_obj::m_main = v;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_main,return )

::haxor::component::Camera Camera_obj::m_main;


Camera_obj::Camera_obj()
{
}

void Camera_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Camera);
	HX_MARK_MEMBER_NAME(__fcid,"__fcid");
	HX_MARK_MEMBER_NAME(background,"background");
	HX_MARK_MEMBER_NAME(skybox,"skybox");
	HX_MARK_MEMBER_NAME(clear,"clear");
	HX_MARK_MEMBER_NAME(m_mask,"m_mask");
	HX_MARK_MEMBER_NAME(m_layers,"m_layers");
	HX_MARK_MEMBER_NAME(m_fov,"m_fov");
	HX_MARK_MEMBER_NAME(m_near,"m_near");
	HX_MARK_MEMBER_NAME(m_far,"m_far");
	HX_MARK_MEMBER_NAME(m_order,"m_order");
	HX_MARK_MEMBER_NAME(m_pixelViewport,"m_pixelViewport");
	HX_MARK_MEMBER_NAME(m_aspect,"m_aspect");
	HX_MARK_MEMBER_NAME(m_viewport,"m_viewport");
	HX_MARK_MEMBER_NAME(CameraToWorld,"CameraToWorld");
	HX_MARK_MEMBER_NAME(WorldToCamera,"WorldToCamera");
	HX_MARK_MEMBER_NAME(ProjectionMatrix,"ProjectionMatrix");
	HX_MARK_MEMBER_NAME(m_projectionMatrix,"m_projectionMatrix");
	HX_MARK_MEMBER_NAME(m_skyboxProjection,"m_skyboxProjection");
	HX_MARK_MEMBER_NAME(ProjectionMatrixInverse,"ProjectionMatrixInverse");
	HX_MARK_MEMBER_NAME(m_projectionMatrixInverse,"m_projectionMatrixInverse");
	HX_MARK_MEMBER_NAME(m_skyboxProjectionInverse,"m_skyboxProjectionInverse");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(m_target,"m_target");
	HX_MARK_MEMBER_NAME(m_quality,"m_quality");
	HX_MARK_MEMBER_NAME(m_captureDepth,"m_captureDepth");
	HX_MARK_MEMBER_NAME(m_filters,"m_filters");
	HX_MARK_MEMBER_NAME(m_projection_dirty,"m_projection_dirty");
	HX_MARK_MEMBER_NAME(m_view_uniform_dirty,"m_view_uniform_dirty");
	HX_MARK_MEMBER_NAME(m_proj_uniform_dirty,"m_proj_uniform_dirty");
	HX_MARK_MEMBER_NAME(m_fn0,"m_fn0");
	HX_MARK_MEMBER_NAME(m_fn1,"m_fn1");
	HX_MARK_MEMBER_NAME(m_fn2,"m_fn2");
	HX_MARK_MEMBER_NAME(m_fn3,"m_fn3");
	HX_MARK_MEMBER_NAME(m_ff0,"m_ff0");
	HX_MARK_MEMBER_NAME(m_ff1,"m_ff1");
	HX_MARK_MEMBER_NAME(m_ff2,"m_ff2");
	HX_MARK_MEMBER_NAME(m_ff3,"m_ff3");
	::haxor::component::Component_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Camera_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__fcid,"__fcid");
	HX_VISIT_MEMBER_NAME(background,"background");
	HX_VISIT_MEMBER_NAME(skybox,"skybox");
	HX_VISIT_MEMBER_NAME(clear,"clear");
	HX_VISIT_MEMBER_NAME(m_mask,"m_mask");
	HX_VISIT_MEMBER_NAME(m_layers,"m_layers");
	HX_VISIT_MEMBER_NAME(m_fov,"m_fov");
	HX_VISIT_MEMBER_NAME(m_near,"m_near");
	HX_VISIT_MEMBER_NAME(m_far,"m_far");
	HX_VISIT_MEMBER_NAME(m_order,"m_order");
	HX_VISIT_MEMBER_NAME(m_pixelViewport,"m_pixelViewport");
	HX_VISIT_MEMBER_NAME(m_aspect,"m_aspect");
	HX_VISIT_MEMBER_NAME(m_viewport,"m_viewport");
	HX_VISIT_MEMBER_NAME(CameraToWorld,"CameraToWorld");
	HX_VISIT_MEMBER_NAME(WorldToCamera,"WorldToCamera");
	HX_VISIT_MEMBER_NAME(ProjectionMatrix,"ProjectionMatrix");
	HX_VISIT_MEMBER_NAME(m_projectionMatrix,"m_projectionMatrix");
	HX_VISIT_MEMBER_NAME(m_skyboxProjection,"m_skyboxProjection");
	HX_VISIT_MEMBER_NAME(ProjectionMatrixInverse,"ProjectionMatrixInverse");
	HX_VISIT_MEMBER_NAME(m_projectionMatrixInverse,"m_projectionMatrixInverse");
	HX_VISIT_MEMBER_NAME(m_skyboxProjectionInverse,"m_skyboxProjectionInverse");
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(m_target,"m_target");
	HX_VISIT_MEMBER_NAME(m_quality,"m_quality");
	HX_VISIT_MEMBER_NAME(m_captureDepth,"m_captureDepth");
	HX_VISIT_MEMBER_NAME(m_filters,"m_filters");
	HX_VISIT_MEMBER_NAME(m_projection_dirty,"m_projection_dirty");
	HX_VISIT_MEMBER_NAME(m_view_uniform_dirty,"m_view_uniform_dirty");
	HX_VISIT_MEMBER_NAME(m_proj_uniform_dirty,"m_proj_uniform_dirty");
	HX_VISIT_MEMBER_NAME(m_fn0,"m_fn0");
	HX_VISIT_MEMBER_NAME(m_fn1,"m_fn1");
	HX_VISIT_MEMBER_NAME(m_fn2,"m_fn2");
	HX_VISIT_MEMBER_NAME(m_fn3,"m_fn3");
	HX_VISIT_MEMBER_NAME(m_ff0,"m_ff0");
	HX_VISIT_MEMBER_NAME(m_ff1,"m_ff1");
	HX_VISIT_MEMBER_NAME(m_ff2,"m_ff2");
	HX_VISIT_MEMBER_NAME(m_ff3,"m_ff3");
	::haxor::component::Component_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Camera_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"sap") ) { return sap; }
		if (HX_FIELD_EQ(inName,"fov") ) { return get_fov(); }
		if (HX_FIELD_EQ(inName,"far") ) { return get_far(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return get_list(); }
		if (HX_FIELD_EQ(inName,"main") ) { return get_main(); }
		if (HX_FIELD_EQ(inName,"mask") ) { return get_mask(); }
		if (HX_FIELD_EQ(inName,"near") ) { return get_near(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear; }
		if (HX_FIELD_EQ(inName,"m_fov") ) { return m_fov; }
		if (HX_FIELD_EQ(inName,"m_far") ) { return m_far; }
		if (HX_FIELD_EQ(inName,"order") ) { return get_order(); }
		if (HX_FIELD_EQ(inName,"m_fn0") ) { return m_fn0; }
		if (HX_FIELD_EQ(inName,"m_fn1") ) { return m_fn1; }
		if (HX_FIELD_EQ(inName,"m_fn2") ) { return m_fn2; }
		if (HX_FIELD_EQ(inName,"m_fn3") ) { return m_fn3; }
		if (HX_FIELD_EQ(inName,"m_ff0") ) { return m_ff0; }
		if (HX_FIELD_EQ(inName,"m_ff1") ) { return m_ff1; }
		if (HX_FIELD_EQ(inName,"m_ff2") ) { return m_ff2; }
		if (HX_FIELD_EQ(inName,"m_ff3") ) { return m_ff3; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_main") ) { return m_main; }
		if (HX_FIELD_EQ(inName,"__fcid") ) { return __fcid; }
		if (HX_FIELD_EQ(inName,"skybox") ) { return skybox; }
		if (HX_FIELD_EQ(inName,"m_mask") ) { return m_mask; }
		if (HX_FIELD_EQ(inName,"m_near") ) { return m_near; }
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		if (HX_FIELD_EQ(inName,"LookAt") ) { return LookAt_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { return get_current(); }
		if (HX_FIELD_EQ(inName,"get_fov") ) { return get_fov_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fov") ) { return set_fov_dyn(); }
		if (HX_FIELD_EQ(inName,"get_far") ) { return get_far_dyn(); }
		if (HX_FIELD_EQ(inName,"set_far") ) { return set_far_dyn(); }
		if (HX_FIELD_EQ(inName,"m_order") ) { return m_order; }
		if (HX_FIELD_EQ(inName,"quality") ) { return get_quality(); }
		if (HX_FIELD_EQ(inName,"filters") ) { return get_filters(); }
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_list") ) { return get_list_dyn(); }
		if (HX_FIELD_EQ(inName,"get_main") ) { return get_main_dyn(); }
		if (HX_FIELD_EQ(inName,"set_main") ) { return set_main_dyn(); }
		if (HX_FIELD_EQ(inName,"get_mask") ) { return get_mask_dyn(); }
		if (HX_FIELD_EQ(inName,"set_mask") ) { return set_mask_dyn(); }
		if (HX_FIELD_EQ(inName,"m_layers") ) { return m_layers; }
		if (HX_FIELD_EQ(inName,"get_near") ) { return get_near_dyn(); }
		if (HX_FIELD_EQ(inName,"set_near") ) { return set_near_dyn(); }
		if (HX_FIELD_EQ(inName,"viewport") ) { return get_viewport(); }
		if (HX_FIELD_EQ(inName,"m_aspect") ) { return m_aspect; }
		if (HX_FIELD_EQ(inName,"m_target") ) { return m_target; }
		if (HX_FIELD_EQ(inName,"IsCulled") ) { return IsCulled_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_current") ) { return m_current; }
		if (HX_FIELD_EQ(inName,"get_order") ) { return get_order_dyn(); }
		if (HX_FIELD_EQ(inName,"set_order") ) { return set_order_dyn(); }
		if (HX_FIELD_EQ(inName,"m_quality") ) { return m_quality; }
		if (HX_FIELD_EQ(inName,"m_filters") ) { return m_filters; }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { return background; }
		if (HX_FIELD_EQ(inName,"m_viewport") ) { return m_viewport; }
		if (HX_FIELD_EQ(inName,"get_target") ) { return get_target_dyn(); }
		if (HX_FIELD_EQ(inName,"set_target") ) { return set_target_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_current") ) { return get_current_dyn(); }
		if (HX_FIELD_EQ(inName,"get_quality") ) { return get_quality_dyn(); }
		if (HX_FIELD_EQ(inName,"set_quality") ) { return set_quality_dyn(); }
		if (HX_FIELD_EQ(inName,"get_filters") ) { return get_filters_dyn(); }
		if (HX_FIELD_EQ(inName,"set_filters") ) { return set_filters_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_viewport") ) { return get_viewport_dyn(); }
		if (HX_FIELD_EQ(inName,"set_viewport") ) { return set_viewport_dyn(); }
		if (HX_FIELD_EQ(inName,"captureDepth") ) { return get_captureDepth(); }
		if (HX_FIELD_EQ(inName,"WorldToDepth") ) { return WorldToDepth_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"pixelViewport") ) { return get_pixelViewport(); }
		if (HX_FIELD_EQ(inName,"CameraToWorld") ) { return inCallProp ? get_CameraToWorld() : CameraToWorld; }
		if (HX_FIELD_EQ(inName,"WorldToCamera") ) { return inCallProp ? get_WorldToCamera() : WorldToCamera; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_captureDepth") ) { return m_captureDepth; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_pixelViewport") ) { return m_pixelViewport; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"ProjectionMatrix") ) { return inCallProp ? get_ProjectionMatrix() : ProjectionMatrix; }
		if (HX_FIELD_EQ(inName,"get_captureDepth") ) { return get_captureDepth_dyn(); }
		if (HX_FIELD_EQ(inName,"set_captureDepth") ) { return set_captureDepth_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateProjection") ) { return UpdateProjection_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"get_pixelViewport") ) { return get_pixelViewport_dyn(); }
		if (HX_FIELD_EQ(inName,"get_CameraToWorld") ) { return get_CameraToWorld_dyn(); }
		if (HX_FIELD_EQ(inName,"get_WorldToCamera") ) { return get_WorldToCamera_dyn(); }
		if (HX_FIELD_EQ(inName,"WorldToProjection") ) { return WorldToProjection_dyn(); }
		if (HX_FIELD_EQ(inName,"OnTransformUpdate") ) { return OnTransformUpdate_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_projectionMatrix") ) { return m_projectionMatrix; }
		if (HX_FIELD_EQ(inName,"m_skyboxProjection") ) { return m_skyboxProjection; }
		if (HX_FIELD_EQ(inName,"m_projection_dirty") ) { return m_projection_dirty; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"get_ProjectionMatrix") ) { return get_ProjectionMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"m_view_uniform_dirty") ) { return m_view_uniform_dirty; }
		if (HX_FIELD_EQ(inName,"m_proj_uniform_dirty") ) { return m_proj_uniform_dirty; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"ProjectionMatrixInverse") ) { return inCallProp ? get_ProjectionMatrixInverse() : ProjectionMatrixInverse; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"m_projectionMatrixInverse") ) { return m_projectionMatrixInverse; }
		if (HX_FIELD_EQ(inName,"m_skyboxProjectionInverse") ) { return m_skyboxProjectionInverse; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"get_ProjectionMatrixInverse") ) { return get_ProjectionMatrixInverse_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Camera_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"sap") ) { sap=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"fov") ) { return set_fov(inValue); }
		if (HX_FIELD_EQ(inName,"far") ) { return set_far(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return set_main(inValue); }
		if (HX_FIELD_EQ(inName,"mask") ) { return set_mask(inValue); }
		if (HX_FIELD_EQ(inName,"near") ) { return set_near(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { clear=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fov") ) { m_fov=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_far") ) { m_far=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"order") ) { return set_order(inValue); }
		if (HX_FIELD_EQ(inName,"m_fn0") ) { m_fn0=inValue.Cast< ::haxor::math::Vector4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fn1") ) { m_fn1=inValue.Cast< ::haxor::math::Vector4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fn2") ) { m_fn2=inValue.Cast< ::haxor::math::Vector4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_fn3") ) { m_fn3=inValue.Cast< ::haxor::math::Vector4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_ff0") ) { m_ff0=inValue.Cast< ::haxor::math::Vector4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_ff1") ) { m_ff1=inValue.Cast< ::haxor::math::Vector4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_ff2") ) { m_ff2=inValue.Cast< ::haxor::math::Vector4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_ff3") ) { m_ff3=inValue.Cast< ::haxor::math::Vector4 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_main") ) { m_main=inValue.Cast< ::haxor::component::Camera >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__fcid") ) { __fcid=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"skybox") ) { skybox=inValue.Cast< ::haxor::graphics::texture::TextureCube >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_mask") ) { m_mask=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_near") ) { m_near=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::haxor::graphics::texture::RenderTexture >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_order") ) { m_order=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"quality") ) { return set_quality(inValue); }
		if (HX_FIELD_EQ(inName,"filters") ) { return set_filters(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_layers") ) { m_layers=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"viewport") ) { return set_viewport(inValue); }
		if (HX_FIELD_EQ(inName,"m_aspect") ) { m_aspect=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_target") ) { m_target=inValue.Cast< ::haxor::graphics::texture::RenderTexture >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_current") ) { m_current=inValue.Cast< ::haxor::component::Camera >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_quality") ) { m_quality=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_filters") ) { m_filters=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"background") ) { background=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_viewport") ) { m_viewport=inValue.Cast< ::haxor::math::AABB2 >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"captureDepth") ) { return set_captureDepth(inValue); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"CameraToWorld") ) { CameraToWorld=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"WorldToCamera") ) { WorldToCamera=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_captureDepth") ) { m_captureDepth=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_pixelViewport") ) { m_pixelViewport=inValue.Cast< ::haxor::math::AABB2 >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"ProjectionMatrix") ) { ProjectionMatrix=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"m_projectionMatrix") ) { m_projectionMatrix=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_skyboxProjection") ) { m_skyboxProjection=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_projection_dirty") ) { m_projection_dirty=inValue.Cast< bool >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"m_view_uniform_dirty") ) { m_view_uniform_dirty=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_proj_uniform_dirty") ) { m_proj_uniform_dirty=inValue.Cast< bool >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"ProjectionMatrixInverse") ) { ProjectionMatrixInverse=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"m_projectionMatrixInverse") ) { m_projectionMatrixInverse=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_skyboxProjectionInverse") ) { m_skyboxProjectionInverse=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Camera_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__fcid"));
	outFields->push(HX_CSTRING("background"));
	outFields->push(HX_CSTRING("skybox"));
	outFields->push(HX_CSTRING("clear"));
	outFields->push(HX_CSTRING("mask"));
	outFields->push(HX_CSTRING("m_mask"));
	outFields->push(HX_CSTRING("m_layers"));
	outFields->push(HX_CSTRING("fov"));
	outFields->push(HX_CSTRING("m_fov"));
	outFields->push(HX_CSTRING("near"));
	outFields->push(HX_CSTRING("m_near"));
	outFields->push(HX_CSTRING("far"));
	outFields->push(HX_CSTRING("m_far"));
	outFields->push(HX_CSTRING("order"));
	outFields->push(HX_CSTRING("m_order"));
	outFields->push(HX_CSTRING("pixelViewport"));
	outFields->push(HX_CSTRING("m_pixelViewport"));
	outFields->push(HX_CSTRING("viewport"));
	outFields->push(HX_CSTRING("m_aspect"));
	outFields->push(HX_CSTRING("m_viewport"));
	outFields->push(HX_CSTRING("CameraToWorld"));
	outFields->push(HX_CSTRING("WorldToCamera"));
	outFields->push(HX_CSTRING("ProjectionMatrix"));
	outFields->push(HX_CSTRING("m_projectionMatrix"));
	outFields->push(HX_CSTRING("m_skyboxProjection"));
	outFields->push(HX_CSTRING("ProjectionMatrixInverse"));
	outFields->push(HX_CSTRING("m_projectionMatrixInverse"));
	outFields->push(HX_CSTRING("m_skyboxProjectionInverse"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("m_target"));
	outFields->push(HX_CSTRING("quality"));
	outFields->push(HX_CSTRING("m_quality"));
	outFields->push(HX_CSTRING("captureDepth"));
	outFields->push(HX_CSTRING("m_captureDepth"));
	outFields->push(HX_CSTRING("filters"));
	outFields->push(HX_CSTRING("m_filters"));
	outFields->push(HX_CSTRING("m_projection_dirty"));
	outFields->push(HX_CSTRING("m_view_uniform_dirty"));
	outFields->push(HX_CSTRING("m_proj_uniform_dirty"));
	outFields->push(HX_CSTRING("m_fn0"));
	outFields->push(HX_CSTRING("m_fn1"));
	outFields->push(HX_CSTRING("m_fn2"));
	outFields->push(HX_CSTRING("m_fn3"));
	outFields->push(HX_CSTRING("m_ff0"));
	outFields->push(HX_CSTRING("m_ff1"));
	outFields->push(HX_CSTRING("m_ff2"));
	outFields->push(HX_CSTRING("m_ff3"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("sap"),
	HX_CSTRING("get_list"),
	HX_CSTRING("get_current"),
	HX_CSTRING("m_current"),
	HX_CSTRING("get_main"),
	HX_CSTRING("set_main"),
	HX_CSTRING("m_main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Camera_obj,__fcid),HX_CSTRING("__fcid")},
	{hx::fsObject /*::haxor::math::Color*/ ,(int)offsetof(Camera_obj,background),HX_CSTRING("background")},
	{hx::fsObject /*::haxor::graphics::texture::TextureCube*/ ,(int)offsetof(Camera_obj,skybox),HX_CSTRING("skybox")},
	{hx::fsInt,(int)offsetof(Camera_obj,clear),HX_CSTRING("clear")},
	{hx::fsInt,(int)offsetof(Camera_obj,m_mask),HX_CSTRING("m_mask")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Camera_obj,m_layers),HX_CSTRING("m_layers")},
	{hx::fsFloat,(int)offsetof(Camera_obj,m_fov),HX_CSTRING("m_fov")},
	{hx::fsFloat,(int)offsetof(Camera_obj,m_near),HX_CSTRING("m_near")},
	{hx::fsFloat,(int)offsetof(Camera_obj,m_far),HX_CSTRING("m_far")},
	{hx::fsInt,(int)offsetof(Camera_obj,m_order),HX_CSTRING("m_order")},
	{hx::fsObject /*::haxor::math::AABB2*/ ,(int)offsetof(Camera_obj,m_pixelViewport),HX_CSTRING("m_pixelViewport")},
	{hx::fsFloat,(int)offsetof(Camera_obj,m_aspect),HX_CSTRING("m_aspect")},
	{hx::fsObject /*::haxor::math::AABB2*/ ,(int)offsetof(Camera_obj,m_viewport),HX_CSTRING("m_viewport")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Camera_obj,CameraToWorld),HX_CSTRING("CameraToWorld")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Camera_obj,WorldToCamera),HX_CSTRING("WorldToCamera")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Camera_obj,ProjectionMatrix),HX_CSTRING("ProjectionMatrix")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Camera_obj,m_projectionMatrix),HX_CSTRING("m_projectionMatrix")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Camera_obj,m_skyboxProjection),HX_CSTRING("m_skyboxProjection")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Camera_obj,ProjectionMatrixInverse),HX_CSTRING("ProjectionMatrixInverse")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Camera_obj,m_projectionMatrixInverse),HX_CSTRING("m_projectionMatrixInverse")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(Camera_obj,m_skyboxProjectionInverse),HX_CSTRING("m_skyboxProjectionInverse")},
	{hx::fsObject /*::haxor::graphics::texture::RenderTexture*/ ,(int)offsetof(Camera_obj,target),HX_CSTRING("target")},
	{hx::fsObject /*::haxor::graphics::texture::RenderTexture*/ ,(int)offsetof(Camera_obj,m_target),HX_CSTRING("m_target")},
	{hx::fsFloat,(int)offsetof(Camera_obj,m_quality),HX_CSTRING("m_quality")},
	{hx::fsBool,(int)offsetof(Camera_obj,m_captureDepth),HX_CSTRING("m_captureDepth")},
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(Camera_obj,m_filters),HX_CSTRING("m_filters")},
	{hx::fsBool,(int)offsetof(Camera_obj,m_projection_dirty),HX_CSTRING("m_projection_dirty")},
	{hx::fsBool,(int)offsetof(Camera_obj,m_view_uniform_dirty),HX_CSTRING("m_view_uniform_dirty")},
	{hx::fsBool,(int)offsetof(Camera_obj,m_proj_uniform_dirty),HX_CSTRING("m_proj_uniform_dirty")},
	{hx::fsObject /*::haxor::math::Vector4*/ ,(int)offsetof(Camera_obj,m_fn0),HX_CSTRING("m_fn0")},
	{hx::fsObject /*::haxor::math::Vector4*/ ,(int)offsetof(Camera_obj,m_fn1),HX_CSTRING("m_fn1")},
	{hx::fsObject /*::haxor::math::Vector4*/ ,(int)offsetof(Camera_obj,m_fn2),HX_CSTRING("m_fn2")},
	{hx::fsObject /*::haxor::math::Vector4*/ ,(int)offsetof(Camera_obj,m_fn3),HX_CSTRING("m_fn3")},
	{hx::fsObject /*::haxor::math::Vector4*/ ,(int)offsetof(Camera_obj,m_ff0),HX_CSTRING("m_ff0")},
	{hx::fsObject /*::haxor::math::Vector4*/ ,(int)offsetof(Camera_obj,m_ff1),HX_CSTRING("m_ff1")},
	{hx::fsObject /*::haxor::math::Vector4*/ ,(int)offsetof(Camera_obj,m_ff2),HX_CSTRING("m_ff2")},
	{hx::fsObject /*::haxor::math::Vector4*/ ,(int)offsetof(Camera_obj,m_ff3),HX_CSTRING("m_ff3")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("__fcid"),
	HX_CSTRING("background"),
	HX_CSTRING("skybox"),
	HX_CSTRING("clear"),
	HX_CSTRING("get_mask"),
	HX_CSTRING("set_mask"),
	HX_CSTRING("m_mask"),
	HX_CSTRING("m_layers"),
	HX_CSTRING("get_fov"),
	HX_CSTRING("set_fov"),
	HX_CSTRING("m_fov"),
	HX_CSTRING("get_near"),
	HX_CSTRING("set_near"),
	HX_CSTRING("m_near"),
	HX_CSTRING("get_far"),
	HX_CSTRING("set_far"),
	HX_CSTRING("m_far"),
	HX_CSTRING("m_order"),
	HX_CSTRING("get_order"),
	HX_CSTRING("set_order"),
	HX_CSTRING("get_pixelViewport"),
	HX_CSTRING("m_pixelViewport"),
	HX_CSTRING("get_viewport"),
	HX_CSTRING("set_viewport"),
	HX_CSTRING("m_aspect"),
	HX_CSTRING("m_viewport"),
	HX_CSTRING("CameraToWorld"),
	HX_CSTRING("get_CameraToWorld"),
	HX_CSTRING("WorldToCamera"),
	HX_CSTRING("get_WorldToCamera"),
	HX_CSTRING("ProjectionMatrix"),
	HX_CSTRING("get_ProjectionMatrix"),
	HX_CSTRING("m_projectionMatrix"),
	HX_CSTRING("m_skyboxProjection"),
	HX_CSTRING("ProjectionMatrixInverse"),
	HX_CSTRING("get_ProjectionMatrixInverse"),
	HX_CSTRING("m_projectionMatrixInverse"),
	HX_CSTRING("m_skyboxProjectionInverse"),
	HX_CSTRING("target"),
	HX_CSTRING("get_target"),
	HX_CSTRING("set_target"),
	HX_CSTRING("m_target"),
	HX_CSTRING("get_quality"),
	HX_CSTRING("set_quality"),
	HX_CSTRING("m_quality"),
	HX_CSTRING("get_captureDepth"),
	HX_CSTRING("set_captureDepth"),
	HX_CSTRING("m_captureDepth"),
	HX_CSTRING("get_filters"),
	HX_CSTRING("set_filters"),
	HX_CSTRING("m_filters"),
	HX_CSTRING("m_projection_dirty"),
	HX_CSTRING("m_view_uniform_dirty"),
	HX_CSTRING("m_proj_uniform_dirty"),
	HX_CSTRING("m_fn0"),
	HX_CSTRING("m_fn1"),
	HX_CSTRING("m_fn2"),
	HX_CSTRING("m_fn3"),
	HX_CSTRING("m_ff0"),
	HX_CSTRING("m_ff1"),
	HX_CSTRING("m_ff2"),
	HX_CSTRING("m_ff3"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("WorldToProjection"),
	HX_CSTRING("WorldToDepth"),
	HX_CSTRING("IsCulled"),
	HX_CSTRING("LookAt"),
	HX_CSTRING("UpdateProjection"),
	HX_CSTRING("OnTransformUpdate"),
	HX_CSTRING("OnDestroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Camera_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Camera_obj::sap,"sap");
	HX_MARK_MEMBER_NAME(Camera_obj::m_current,"m_current");
	HX_MARK_MEMBER_NAME(Camera_obj::m_main,"m_main");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Camera_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Camera_obj::sap,"sap");
	HX_VISIT_MEMBER_NAME(Camera_obj::m_current,"m_current");
	HX_VISIT_MEMBER_NAME(Camera_obj::m_main,"m_main");
};

#endif

Class Camera_obj::__mClass;

void Camera_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.Camera"), hx::TCanCast< Camera_obj> ,sStaticFields,sMemberFields,
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

void Camera_obj::__boot()
{
	sap= true;
}

} // end namespace haxor
} // end namespace component
