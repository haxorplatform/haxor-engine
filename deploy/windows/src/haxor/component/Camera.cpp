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
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_UID
#include <haxor/context/UID.h>
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
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
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
#ifndef INCLUDED_haxor_math_Quaternion
#include <haxor/math/Quaternion.h>
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
	HX_STACK_FRAME("haxor.component.Camera","get_mask",0x14398c61,"haxor.component.Camera.get_mask","haxor/component/Camera.hx",66,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(66)
	return this->m_mask;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_mask,return )

int Camera_obj::set_mask( int v){
	HX_STACK_FRAME("haxor.component.Camera","set_mask",0xc296e5d5,"haxor.component.Camera.set_mask","haxor/component/Camera.hx",68,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(69)
	if (((this->m_mask == v))){
		HX_STACK_LINE(69)
		return v;
	}
	HX_STACK_LINE(70)
	this->m_mask = v;
	HX_STACK_LINE(71)
	int it = this->m_mask;		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(72)
	this->m_layers = Array_obj< int >::__new();
	HX_STACK_LINE(73)
	{
		HX_STACK_LINE(73)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(73)
		while((true)){
			HX_STACK_LINE(73)
			if ((!(((_g < (int)32))))){
				HX_STACK_LINE(73)
				break;
			}
			HX_STACK_LINE(73)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(75)
			if (((((int(it) & int((int)1))) != (int)0))){
				HX_STACK_LINE(75)
				this->m_layers->push((int((int)1) << int(i)));
			}
			HX_STACK_LINE(76)
			it = (int(it) >> int((int)1));
		}
	}
	HX_STACK_LINE(78)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_mask,return )

Float Camera_obj::get_fov( ){
	HX_STACK_FRAME("haxor.component.Camera","get_fov",0x8f916138,"haxor.component.Camera.get_fov","haxor/component/Camera.hx",88,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(88)
	return this->m_fov;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_fov,return )

Float Camera_obj::set_fov( Float v){
	HX_STACK_FRAME("haxor.component.Camera","set_fov",0x8292f244,"haxor.component.Camera.set_fov","haxor/component/Camera.hx",89,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(89)
	this->m_fov = v;
	HX_STACK_LINE(89)
	this->m_projection_dirty = true;
	HX_STACK_LINE(89)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_fov,return )

Float Camera_obj::get_near( ){
	HX_STACK_FRAME("haxor.component.Camera","get_near",0x14e5bc5d,"haxor.component.Camera.get_near","haxor/component/Camera.hx",96,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(96)
	return this->m_near;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_near,return )

Float Camera_obj::set_near( Float v){
	HX_STACK_FRAME("haxor.component.Camera","set_near",0xc34315d1,"haxor.component.Camera.set_near","haxor/component/Camera.hx",97,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(97)
	this->m_near = v;
	HX_STACK_LINE(97)
	this->m_projection_dirty = true;
	HX_STACK_LINE(97)
	this->m_proj_uniform_dirty = true;
	HX_STACK_LINE(97)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_near,return )

Float Camera_obj::get_far( ){
	HX_STACK_FRAME("haxor.component.Camera","get_far",0x8f915502,"haxor.component.Camera.get_far","haxor/component/Camera.hx",104,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(104)
	return this->m_far;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_far,return )

Float Camera_obj::set_far( Float v){
	HX_STACK_FRAME("haxor.component.Camera","set_far",0x8292e60e,"haxor.component.Camera.set_far","haxor/component/Camera.hx",105,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(105)
	this->m_far = v;
	HX_STACK_LINE(105)
	this->m_projection_dirty = true;
	HX_STACK_LINE(105)
	this->m_proj_uniform_dirty = true;
	HX_STACK_LINE(105)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_far,return )

int Camera_obj::get_order( ){
	HX_STACK_FRAME("haxor.component.Camera","get_order",0xd01fab79,"haxor.component.Camera.get_order","haxor/component/Camera.hx",113,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(113)
	return this->m_order;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_order,return )

int Camera_obj::set_order( int v){
	HX_STACK_FRAME("haxor.component.Camera","set_order",0xb3709785,"haxor.component.Camera.set_order","haxor/component/Camera.hx",114,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(114)
	if (((this->m_order == v))){
		HX_STACK_LINE(114)
		return v;
	}
	HX_STACK_LINE(114)
	this->m_order = v;
	HX_STACK_LINE(114)
	::haxor::context::EngineContext_obj::camera->SortCameraList();
	HX_STACK_LINE(114)
	return this->m_order;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_order,return )

::haxor::math::AABB2 Camera_obj::get_pixelViewport( ){
	HX_STACK_FRAME("haxor.component.Camera","get_pixelViewport",0x0871e2f7,"haxor.component.Camera.get_pixelViewport","haxor/component/Camera.hx",120,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(120)
	return this->m_pixelViewport->get_clone();
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_pixelViewport,return )

::haxor::math::AABB2 Camera_obj::get_viewport( ){
	HX_STACK_FRAME("haxor.component.Camera","get_viewport",0x016bf65b,"haxor.component.Camera.get_viewport","haxor/component/Camera.hx",128,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(128)
	return this->m_viewport->get_clone();
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_viewport,return )

::haxor::math::AABB2 Camera_obj::set_viewport( ::haxor::math::AABB2 v){
	HX_STACK_FRAME("haxor.component.Camera","set_viewport",0x166519cf,"haxor.component.Camera.set_viewport","haxor/component/Camera.hx",129,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(129)
	this->m_viewport->SetAABB2(v);
	HX_STACK_LINE(129)
	::haxor::context::EngineContext_obj::camera->UpdateViewport(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(129)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_viewport,return )

::haxor::math::Matrix4 Camera_obj::get_CameraToWorld( ){
	HX_STACK_FRAME("haxor.component.Camera","get_CameraToWorld",0xbdba807d,"haxor.component.Camera.get_CameraToWorld","haxor/component/Camera.hx",137,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(137)
	return this->m_entity->m_transform->get_WorldMatrix();
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_CameraToWorld,return )

::haxor::math::Matrix4 Camera_obj::get_WorldToCamera( ){
	HX_STACK_FRAME("haxor.component.Camera","get_WorldToCamera",0xaa8f50bd,"haxor.component.Camera.get_WorldToCamera","haxor/component/Camera.hx",144,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(144)
	return this->m_entity->m_transform->get_WorldMatrixInverse();
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_WorldToCamera,return )

::haxor::math::Matrix4 Camera_obj::get_ProjectionMatrix( ){
	HX_STACK_FRAME("haxor.component.Camera","get_ProjectionMatrix",0xc4d78b45,"haxor.component.Camera.get_ProjectionMatrix","haxor/component/Camera.hx",151,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(151)
	this->UpdateProjection();
	HX_STACK_LINE(151)
	return this->m_projectionMatrix;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_ProjectionMatrix,return )

::haxor::math::Matrix4 Camera_obj::get_ProjectionMatrixInverse( ){
	HX_STACK_FRAME("haxor.component.Camera","get_ProjectionMatrixInverse",0x6ddb0aeb,"haxor.component.Camera.get_ProjectionMatrixInverse","haxor/component/Camera.hx",159,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(159)
	this->UpdateProjection();
	HX_STACK_LINE(159)
	return this->m_projectionMatrixInverse;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_ProjectionMatrixInverse,return )

::haxor::graphics::texture::RenderTexture Camera_obj::get_target( ){
	HX_STACK_FRAME("haxor.component.Camera","get_target",0x8ad1c606,"haxor.component.Camera.get_target","haxor/component/Camera.hx",167,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(167)
	return this->m_target;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_target,return )

::haxor::graphics::texture::RenderTexture Camera_obj::set_target( ::haxor::graphics::texture::RenderTexture v){
	HX_STACK_FRAME("haxor.component.Camera","set_target",0x8e4f647a,"haxor.component.Camera.set_target","haxor/component/Camera.hx",168,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(168)
	this->m_target = v;
	HX_STACK_LINE(168)
	::haxor::context::EngineContext_obj::camera->UpdateViewport(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(168)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_target,return )

Float Camera_obj::get_quality( ){
	HX_STACK_FRAME("haxor.component.Camera","get_quality",0xa89f906a,"haxor.component.Camera.get_quality","haxor/component/Camera.hx",175,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(175)
	return this->m_quality;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_quality,return )

Float Camera_obj::set_quality( Float v){
	HX_STACK_FRAME("haxor.component.Camera","set_quality",0xb30c9776,"haxor.component.Camera.set_quality","haxor/component/Camera.hx",176,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(176)
	if (((v <= 0.0))){
		HX_STACK_LINE(176)
		this->m_quality = 0.0;
	}
	else{
		HX_STACK_LINE(176)
		if (((v >= 1.0))){
			HX_STACK_LINE(176)
			this->m_quality = 1.0;
		}
		else{
			HX_STACK_LINE(176)
			this->m_quality = v;
		}
	}
	HX_STACK_LINE(176)
	::haxor::context::EngineContext_obj::camera->UpdateViewport(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(176)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_quality,return )

bool Camera_obj::get_captureDepth( ){
	HX_STACK_FRAME("haxor.component.Camera","get_captureDepth",0x75413312,"haxor.component.Camera.get_captureDepth","haxor/component/Camera.hx",183,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(183)
	return this->m_captureDepth;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_captureDepth,return )

bool Camera_obj::set_captureDepth( bool v){
	HX_STACK_FRAME("haxor.component.Camera","set_captureDepth",0xcb832086,"haxor.component.Camera.set_captureDepth","haxor/component/Camera.hx",184,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(184)
	this->m_captureDepth = v;
	HX_STACK_LINE(184)
	::haxor::context::EngineContext_obj::camera->ClearTargets(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(184)
	::haxor::context::EngineContext_obj::camera->UpdateViewport(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(184)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_captureDepth,return )

Dynamic Camera_obj::get_filters( ){
	HX_STACK_FRAME("haxor.component.Camera","get_filters",0x6d9a2d66,"haxor.component.Camera.get_filters","haxor/component/Camera.hx",191,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(191)
	return this->m_filters;
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_filters,return )

Dynamic Camera_obj::set_filters( Dynamic v){
	HX_STACK_FRAME("haxor.component.Camera","set_filters",0x78073472,"haxor.component.Camera.set_filters","haxor/component/Camera.hx",193,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(194)
	if (((v == null()))){
		HX_STACK_LINE(194)
		this->m_filters = Dynamic( Array_obj<Dynamic>::__new());
	}
	else{
		HX_STACK_LINE(194)
		this->m_filters = v;
	}
	HX_STACK_LINE(195)
	return this->m_filters;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,set_filters,return )

Void Camera_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.Camera","OnBuild",0x87487303,"haxor.component.Camera.OnBuild","haxor/component/Camera.hx",219,0xf5fa0e7a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(220)
		this->super::OnBuild();
		HX_STACK_LINE(221)
		int _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(221)
		{
			HX_STACK_LINE(221)
			::haxor::context::UID _this = ::haxor::context::EngineContext_obj::camera->cid;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(221)
			if (((_this->m_cache->length <= (int)0))){
				HX_STACK_LINE(221)
				_g = (_this->m_id)++;
			}
			else{
				HX_STACK_LINE(221)
				_g = _this->m_cache->shift();
			}
		}
		HX_STACK_LINE(221)
		this->__cid = _g;
		HX_STACK_LINE(222)
		if (((::haxor::component::Camera_obj::m_main == null()))){
			HX_STACK_LINE(222)
			::haxor::component::Camera_obj::m_main = hx::ObjectPtr<OBJ_>(this);
		}
		HX_STACK_LINE(223)
		this->m_order = (int)0;
		HX_STACK_LINE(224)
		this->m_quality = 1.0;
		HX_STACK_LINE(225)
		::haxor::math::AABB2 _g1 = ::haxor::math::AABB2_obj::get_empty();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(225)
		this->m_pixelViewport = _g1;
		HX_STACK_LINE(226)
		::haxor::math::AABB2 _g2 = ::haxor::math::AABB2_obj::get_empty();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(226)
		this->m_viewport = _g2;
		HX_STACK_LINE(227)
		::haxor::math::Matrix4 _g3 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(227)
		this->m_projectionMatrix = _g3;
		HX_STACK_LINE(228)
		::haxor::math::Matrix4 _g4 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(228)
		this->m_projectionMatrixInverse = _g4;
		HX_STACK_LINE(229)
		::haxor::math::Matrix4 _g5 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(229)
		this->m_skyboxProjection = _g5;
		HX_STACK_LINE(230)
		::haxor::math::Matrix4 _g6 = ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(230)
		this->m_skyboxProjectionInverse = _g6;
		HX_STACK_LINE(231)
		this->m_fov = (int)60;
		HX_STACK_LINE(232)
		this->m_near = 0.1;
		HX_STACK_LINE(233)
		this->m_far = (int)500;
		HX_STACK_LINE(234)
		this->m_filters = Dynamic( Array_obj<Dynamic>::__new());
		HX_STACK_LINE(235)
		::haxor::math::Color _g7 = ::haxor::math::Color_obj::__new((int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(235)
		this->background = _g7;
		HX_STACK_LINE(236)
		this->clear = ::haxor::core::ClearFlag_obj::ColorDepth;
		HX_STACK_LINE(237)
		this->set_mask((int)1);
		HX_STACK_LINE(238)
		{
			HX_STACK_LINE(238)
			::haxor::math::AABB2 v = ::haxor::math::AABB2_obj::__new((int)0,(int)0,(int)1,(int)1);		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(238)
			this->m_viewport->SetAABB2(v);
			HX_STACK_LINE(238)
			::haxor::context::EngineContext_obj::camera->UpdateViewport(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(238)
			v;
		}
		HX_STACK_LINE(239)
		this->m_projection_dirty = true;
		HX_STACK_LINE(240)
		this->m_view_uniform_dirty = true;
		HX_STACK_LINE(241)
		this->m_proj_uniform_dirty = true;
		HX_STACK_LINE(242)
		::haxor::context::EngineContext_obj::camera->Create(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


::haxor::math::Vector4 Camera_obj::WorldToProjection( ::haxor::math::Vector3 p_world_point){
	HX_STACK_FRAME("haxor.component.Camera","WorldToProjection",0x920ca1d0,"haxor.component.Camera.WorldToProjection","haxor/component/Camera.hx",251,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_world_point,"p_world_point")
	HX_STACK_LINE(252)
	::haxor::math::Vector4 p;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(252)
	{
		HX_STACK_LINE(252)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(252)
		int _g = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(252)
		p = _this->m_v4->__get(_g).StaticCast< ::haxor::math::Vector4 >();
	}
	HX_STACK_LINE(253)
	p->w = 1.0;
	HX_STACK_LINE(254)
	p->x = p_world_point->x;
	HX_STACK_LINE(255)
	p->y = p_world_point->y;
	HX_STACK_LINE(256)
	p->z = p_world_point->z;
	HX_STACK_LINE(257)
	{
		HX_STACK_LINE(257)
		::haxor::math::Matrix4 _this = this->get_WorldToCamera();		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(257)
		Float vx = ((((_this->m00 * p->x) + (_this->m01 * p->y)) + (_this->m02 * p->z)) + (_this->m03 * p->w));		HX_STACK_VAR(vx,"vx");
		HX_STACK_LINE(257)
		Float vy = ((((_this->m10 * p->x) + (_this->m11 * p->y)) + (_this->m12 * p->z)) + (_this->m13 * p->w));		HX_STACK_VAR(vy,"vy");
		HX_STACK_LINE(257)
		Float vz = ((((_this->m20 * p->x) + (_this->m21 * p->y)) + (_this->m22 * p->z)) + (_this->m23 * p->w));		HX_STACK_VAR(vz,"vz");
		HX_STACK_LINE(257)
		Float vw = ((((_this->m30 * p->x) + (_this->m31 * p->y)) + (_this->m32 * p->z)) + (_this->m33 * p->w));		HX_STACK_VAR(vw,"vw");
		HX_STACK_LINE(257)
		p->x = vx;
		HX_STACK_LINE(257)
		p->y = vy;
		HX_STACK_LINE(257)
		p->z = vz;
		HX_STACK_LINE(257)
		p->w = vw;
		HX_STACK_LINE(257)
		p;
	}
	HX_STACK_LINE(258)
	{
		HX_STACK_LINE(258)
		::haxor::math::Matrix4 _this;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(258)
		{
			HX_STACK_LINE(258)
			this->UpdateProjection();
			HX_STACK_LINE(258)
			_this = this->m_projectionMatrix;
		}
		HX_STACK_LINE(258)
		Float vx = ((((_this->m00 * p->x) + (_this->m01 * p->y)) + (_this->m02 * p->z)) + (_this->m03 * p->w));		HX_STACK_VAR(vx,"vx");
		HX_STACK_LINE(258)
		Float vy = ((((_this->m10 * p->x) + (_this->m11 * p->y)) + (_this->m12 * p->z)) + (_this->m13 * p->w));		HX_STACK_VAR(vy,"vy");
		HX_STACK_LINE(258)
		Float vz = ((((_this->m20 * p->x) + (_this->m21 * p->y)) + (_this->m22 * p->z)) + (_this->m23 * p->w));		HX_STACK_VAR(vz,"vz");
		HX_STACK_LINE(258)
		Float vw = ((((_this->m30 * p->x) + (_this->m31 * p->y)) + (_this->m32 * p->z)) + (_this->m33 * p->w));		HX_STACK_VAR(vw,"vw");
		HX_STACK_LINE(258)
		p->x = vx;
		HX_STACK_LINE(258)
		p->y = vy;
		HX_STACK_LINE(258)
		p->z = vz;
		HX_STACK_LINE(258)
		p->w = vw;
		HX_STACK_LINE(258)
		p;
	}
	HX_STACK_LINE(259)
	return p;
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,WorldToProjection,return )

Float Camera_obj::WorldToDepth( ::haxor::math::Vector3 p_world_point){
	HX_STACK_FRAME("haxor.component.Camera","WorldToDepth",0x4fe15f62,"haxor.component.Camera.WorldToDepth","haxor/component/Camera.hx",268,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_world_point,"p_world_point")
	HX_STACK_LINE(269)
	::haxor::math::Matrix4 wm = this->get_WorldToCamera();		HX_STACK_VAR(wm,"wm");
	HX_STACK_LINE(270)
	return ((((wm->m20 * p_world_point->x) + (wm->m21 * p_world_point->y)) + (wm->m22 * p_world_point->z)) + wm->m23);
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,WorldToDepth,return )

bool Camera_obj::IsCulled( ::haxor::math::Vector3 p_world_point){
	HX_STACK_FRAME("haxor.component.Camera","IsCulled",0xb92fd627,"haxor.component.Camera.IsCulled","haxor/component/Camera.hx",280,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_world_point,"p_world_point")
	HX_STACK_LINE(280)
	return this->WorldToProjection(p_world_point)->IsCulled();
}


HX_DEFINE_DYNAMIC_FUNC1(Camera_obj,IsCulled,return )

Void Camera_obj::LookAt( ::haxor::math::Vector3 p_at,::haxor::math::Vector3 p_up,hx::Null< Float >  __o_p_smooth){
Float p_smooth = __o_p_smooth.Default(0.0);
	HX_STACK_FRAME("haxor.component.Camera","LookAt",0xd028663e,"haxor.component.Camera.LookAt","haxor/component/Camera.hx",290,0xf5fa0e7a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_at,"p_at")
	HX_STACK_ARG(p_up,"p_up")
	HX_STACK_ARG(p_smooth,"p_smooth")
{
		HX_STACK_LINE(291)
		::haxor::math::Vector3 p = this->m_entity->m_transform->get_position();		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(292)
		::haxor::math::Quaternion r;		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(292)
		{
			HX_STACK_LINE(292)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(292)
			int _g = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(292)
			r = _this->m_q->__get(_g).StaticCast< ::haxor::math::Quaternion >();
		}
		HX_STACK_LINE(293)
		::haxor::math::Quaternion q;		HX_STACK_VAR(q,"q");
		HX_STACK_LINE(293)
		{
			HX_STACK_LINE(293)
			::haxor::math::Quaternion p_result;		HX_STACK_VAR(p_result,"p_result");
			HX_STACK_LINE(293)
			{
				HX_STACK_LINE(293)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(293)
				int _g1 = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(293)
				p_result = _this->m_q->__get(_g1).StaticCast< ::haxor::math::Quaternion >();
			}
			HX_STACK_LINE(293)
			::haxor::math::Matrix4 _g3;		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(293)
			{
				HX_STACK_LINE(293)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(293)
				int _g2 = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(293)
				_g3 = _this->m_m4->__get(_g2).StaticCast< ::haxor::math::Matrix4 >();
			}
			HX_STACK_LINE(293)
			::haxor::math::Matrix4 _g4 = ::haxor::math::Matrix4_obj::LookAt(p,p_at,p_up,_g3);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(293)
			q = ::haxor::math::Quaternion_obj::FromMatrix(_g4,p_result);
		}
		HX_STACK_LINE(294)
		if (((p_smooth > (int)0))){
			HX_STACK_LINE(296)
			::haxor::math::Quaternion _g6;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(296)
			{
				HX_STACK_LINE(296)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(296)
				int _g5 = _this->m_nq = hx::Mod(((_this->m_nq + (int)1)),_this->m_q->length);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(296)
				_g6 = _this->m_q->__get(_g5).StaticCast< ::haxor::math::Quaternion >();
			}
			HX_STACK_LINE(296)
			::haxor::math::Quaternion _g7 = ::haxor::math::Quaternion_obj::Lerp(r,q,(p_smooth * ::haxor::core::Time_obj::m_delta),_g6);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(296)
			r = _g7;
		}
		else{
			HX_STACK_LINE(300)
			r = q;
		}
		HX_STACK_LINE(302)
		this->m_entity->m_transform->set_rotation(r);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Camera_obj,LookAt,(void))

Void Camera_obj::UpdateProjection( ){
{
		HX_STACK_FRAME("haxor.component.Camera","UpdateProjection",0x2cce9004,"haxor.component.Camera.UpdateProjection","haxor/component/Camera.hx",309,0xf5fa0e7a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(310)
		if ((!(this->m_projection_dirty))){
			HX_STACK_LINE(310)
			return null();
		}
		HX_STACK_LINE(311)
		this->m_projection_dirty = false;
		HX_STACK_LINE(312)
		this->m_view_uniform_dirty = true;
		HX_STACK_LINE(313)
		::haxor::math::Matrix4_obj::Perspective(this->m_fov,this->m_aspect,this->m_near,this->m_far,this->m_projectionMatrix);
		HX_STACK_LINE(314)
		::haxor::math::Matrix4_obj::PerspectiveInverse(this->m_fov,this->m_aspect,this->m_near,this->m_far,this->m_projectionMatrixInverse);
		HX_STACK_LINE(315)
		::haxor::math::Matrix4_obj::Perspective(this->m_fov,this->m_aspect,0.1,100000.0,this->m_skyboxProjection);
		HX_STACK_LINE(316)
		::haxor::math::Matrix4_obj::PerspectiveInverse(this->m_fov,this->m_aspect,0.1,100000.0,this->m_skyboxProjectionInverse);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,UpdateProjection,(void))

Void Camera_obj::OnTransformUpdate( ){
{
		HX_STACK_FRAME("haxor.component.Camera","OnTransformUpdate",0xef4a94aa,"haxor.component.Camera.OnTransformUpdate","haxor/component/Camera.hx",322,0xf5fa0e7a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(322)
		this->m_view_uniform_dirty = true;
	}
return null();
}


Void Camera_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.component.Camera","OnDestroy",0xf559240f,"haxor.component.Camera.OnDestroy","haxor/component/Camera.hx",330,0xf5fa0e7a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(330)
		::haxor::context::EngineContext_obj::camera->Destroy(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


Array< ::Dynamic > Camera_obj::get_list( ){
	HX_STACK_FRAME("haxor.component.Camera","get_list",0x139667d3,"haxor.component.Camera.get_list","haxor/component/Camera.hx",31,0xf5fa0e7a)
	HX_STACK_LINE(31)
	return ::haxor::context::EngineContext_obj::camera->list->copy();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_list,return )

::haxor::component::Camera Camera_obj::get_current( ){
	HX_STACK_FRAME("haxor.component.Camera","get_current",0x303727e4,"haxor.component.Camera.get_current","haxor/component/Camera.hx",36,0xf5fa0e7a)
	HX_STACK_LINE(36)
	return ::haxor::component::Camera_obj::m_current;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_current,return )

::haxor::component::Camera Camera_obj::m_current;

::haxor::component::Camera Camera_obj::get_main( ){
	HX_STACK_FRAME("haxor.component.Camera","get_main",0x143983ae,"haxor.component.Camera.get_main","haxor/component/Camera.hx",43,0xf5fa0e7a)
	HX_STACK_LINE(43)
	return ::haxor::component::Camera_obj::m_main;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Camera_obj,get_main,return )

::haxor::component::Camera Camera_obj::set_main( ::haxor::component::Camera v){
	HX_STACK_FRAME("haxor.component.Camera","set_main",0xc296dd22,"haxor.component.Camera.set_main","haxor/component/Camera.hx",44,0xf5fa0e7a)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(44)
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
	::haxor::component::Component_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Camera_obj::__Visit(HX_VISIT_PARAMS)
{
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
	::haxor::component::Component_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Camera_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
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
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_main") ) { return m_main; }
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
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_main") ) { m_main=inValue.Cast< ::haxor::component::Camera >(); return inValue; }
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
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("get_list"),
	HX_CSTRING("get_current"),
	HX_CSTRING("m_current"),
	HX_CSTRING("get_main"),
	HX_CSTRING("set_main"),
	HX_CSTRING("m_main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
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
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
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
	HX_MARK_MEMBER_NAME(Camera_obj::m_current,"m_current");
	HX_MARK_MEMBER_NAME(Camera_obj::m_main,"m_main");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Camera_obj::__mClass,"__mClass");
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
}

} // end namespace haxor
} // end namespace component
