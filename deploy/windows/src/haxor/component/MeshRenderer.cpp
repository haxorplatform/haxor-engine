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
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_RendererContext
#include <haxor/context/RendererContext.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IResizeable
#include <haxor/core/IResizeable.h>
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
#ifndef INCLUDED_haxor_math_AABB3
#include <haxor/math/AABB3.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace component{

Void MeshRenderer_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.MeshRenderer","new",0x52d8f6df,"haxor.component.MeshRenderer.new","haxor/component/MeshRenderer.hx",24,0x9df8586f)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(24)
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
	HX_STACK_FRAME("haxor.component.MeshRenderer","get_mesh",0x8a77f297,"haxor.component.MeshRenderer.get_mesh","haxor/component/MeshRenderer.hx",37,0x9df8586f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(37)
	return this->m_mesh;
}


HX_DEFINE_DYNAMIC_FUNC0(MeshRenderer_obj,get_mesh,return )

::haxor::graphics::mesh::Mesh MeshRenderer_obj::set_mesh( ::haxor::graphics::mesh::Mesh v){
	HX_STACK_FRAME("haxor.component.MeshRenderer","set_mesh",0x38d54c0b,"haxor.component.MeshRenderer.set_mesh","haxor/component/MeshRenderer.hx",38,0x9df8586f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(38)
	if (((this->m_mesh == v))){
		HX_STACK_LINE(38)
		return v;
	}
	HX_STACK_LINE(38)
	this->m_mesh = v;
	HX_STACK_LINE(38)
	this->UpdateWorldBounds();
	HX_STACK_LINE(38)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(MeshRenderer_obj,set_mesh,return )

Void MeshRenderer_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.MeshRenderer","OnBuild",0xf16d736e,"haxor.component.MeshRenderer.OnBuild","haxor/component/MeshRenderer.hx",65,0x9df8586f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(66)
		this->m_has_mesh = true;
		HX_STACK_LINE(67)
		this->super::OnBuild();
		HX_STACK_LINE(68)
		::haxor::math::Vector3 _g = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(68)
		this->m_ws_center = _g;
		HX_STACK_LINE(69)
		::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(69)
		this->m_ws_radius = _g1;
		HX_STACK_LINE(70)
		this->m_culling_dirty = false;
		HX_STACK_LINE(71)
		::haxor::math::AABB3 _g2 = ::haxor::math::AABB3_obj::get_empty();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(71)
		this->m_aabb = _g2;
	}
return null();
}


bool MeshRenderer_obj::IsVisible( ::haxor::component::Camera p_camera){
	HX_STACK_FRAME("haxor.component.MeshRenderer","IsVisible",0x9e016547,"haxor.component.MeshRenderer.IsVisible","haxor/component/MeshRenderer.hx",80,0x9df8586f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_camera,"p_camera")
	HX_STACK_LINE(81)
	::haxor::component::Camera c = p_camera;		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(82)
	if (((c == null()))){
		HX_STACK_LINE(82)
		return false;
	}
	HX_STACK_LINE(83)
	if (((this->m_mesh == null()))){
		HX_STACK_LINE(83)
		return false;
	}
	struct _Function_1_1{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/MeshRenderer.hx",85,0x9df8586f)
			{
				HX_STACK_LINE(85)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(85)
				int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(85)
				return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(85)
	::haxor::math::Vector3 _g1 = (_Function_1_1::Block())->Set3(this->m_ws_center);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(85)
	::haxor::math::Vector4 _g3;		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(85)
	{
		HX_STACK_LINE(85)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(85)
		int _g2 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(85)
		_g3 = _this->m_v4->__get(_g2).StaticCast< ::haxor::math::Vector4 >();
	}
	HX_STACK_LINE(85)
	::haxor::math::Vector4 ps_center = c->WorldToProjection(_g1,_g3);		HX_STACK_VAR(ps_center,"ps_center");
	HX_STACK_LINE(86)
	Float w = ps_center->w;		HX_STACK_VAR(w,"w");
	HX_STACK_LINE(87)
	::haxor::math::Vector4 p = ps_center;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(89)
	if (((w <= 0.0))){
		HX_STACK_LINE(89)
		return false;
	}
	HX_STACK_LINE(92)
	if (((p->x >= -(w)))){
		HX_STACK_LINE(93)
		if (((p->x <= w))){
			HX_STACK_LINE(94)
			if (((p->y >= -(w)))){
				HX_STACK_LINE(95)
				if (((p->y <= w))){
					HX_STACK_LINE(96)
					if (((p->z >= -(w)))){
						HX_STACK_LINE(97)
						if (((p->z <= w))){
							HX_STACK_LINE(97)
							return true;
						}
					}
				}
			}
		}
	}
	struct _Function_1_2{
		inline static ::haxor::math::Vector3 Block( ){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/MeshRenderer.hx",99,0x9df8586f)
			{
				HX_STACK_LINE(99)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(99)
				int _g4 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(99)
				return _this->m_v3->__get(_g4).StaticCast< ::haxor::math::Vector3 >();
			}
			return null();
		}
	};
	HX_STACK_LINE(99)
	::haxor::math::Vector3 _g5 = (_Function_1_2::Block())->Set3(this->m_ws_radius);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(99)
	::haxor::math::Vector4 _g7;		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(99)
	{
		HX_STACK_LINE(99)
		::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(99)
		int _g6 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(99)
		_g7 = _this->m_v4->__get(_g6).StaticCast< ::haxor::math::Vector4 >();
	}
	HX_STACK_LINE(99)
	::haxor::math::Vector4 v = c->WorldToProjection(_g5,_g7);		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(100)
	Float r = ::Math_obj::sqrt(((((v->x * v->x) + (v->y * v->y)) + (v->z * v->z)) + (v->w * v->w)));		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(102)
	if ((((p->x + r) >= -(w)))){
		HX_STACK_LINE(103)
		if ((((p->x - r) <= w))){
			HX_STACK_LINE(104)
			if ((((p->y + r) >= -(w)))){
				HX_STACK_LINE(105)
				if ((((p->y - r) <= w))){
					HX_STACK_LINE(106)
					if ((((p->z + r) >= -(w)))){
						HX_STACK_LINE(107)
						if ((((p->z - r) <= w))){
							HX_STACK_LINE(107)
							return true;
						}
					}
				}
			}
		}
	}
	HX_STACK_LINE(109)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(MeshRenderer_obj,IsVisible,return )

bool MeshRenderer_obj::CheckCulling( ){
	HX_STACK_FRAME("haxor.component.MeshRenderer","CheckCulling",0x30b87849,"haxor.component.MeshRenderer.CheckCulling","haxor/component/MeshRenderer.hx",117,0x9df8586f)
	HX_STACK_THIS(this)
	HX_STACK_LINE(118)
	::haxor::component::Camera c = ::haxor::component::Camera_obj::m_current;		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(119)
	if (((c == null()))){
		HX_STACK_LINE(119)
		return this->m_culled;
	}
	HX_STACK_LINE(121)
	if ((!(c->m_view_uniform_dirty))){
		HX_STACK_LINE(122)
		if ((!(c->m_proj_uniform_dirty))){
			HX_STACK_LINE(123)
			if ((!(this->m_culling_dirty))){
				HX_STACK_LINE(123)
				return this->m_culled;
			}
		}
	}
	HX_STACK_LINE(124)
	this->UpdateWorldBounds();
	HX_STACK_LINE(125)
	return !(this->IsVisible(c));
}


Void MeshRenderer_obj::OnTransformUpdate( bool p_hierarchy){
{
		HX_STACK_FRAME("haxor.component.MeshRenderer","OnTransformUpdate",0x36a668d5,"haxor.component.MeshRenderer.OnTransformUpdate","haxor/component/MeshRenderer.hx",133,0x9df8586f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_hierarchy,"p_hierarchy")
		HX_STACK_LINE(133)
		this->m_culling_dirty = true;
	}
return null();
}


Void MeshRenderer_obj::UpdateWorldBounds( ){
{
		HX_STACK_FRAME("haxor.component.MeshRenderer","UpdateWorldBounds",0x4b4a6d7d,"haxor.component.MeshRenderer.UpdateWorldBounds","haxor/component/MeshRenderer.hx",142,0x9df8586f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(142)
		if (((this->m_mesh != null()))){
			HX_STACK_LINE(146)
			::haxor::math::AABB3_obj::Center(this->m_mesh->m_bounds,this->m_ws_center);
			HX_STACK_LINE(148)
			{
				HX_STACK_LINE(148)
				::haxor::math::Matrix4 _this = this->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(148)
				::haxor::math::Vector3 p_point = this->m_ws_center;		HX_STACK_VAR(p_point,"p_point");
				HX_STACK_LINE(148)
				Float vx = ((((_this->m00 * p_point->x) + (_this->m01 * p_point->y)) + (_this->m02 * p_point->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
				HX_STACK_LINE(148)
				Float vy = ((((_this->m10 * p_point->x) + (_this->m11 * p_point->y)) + (_this->m12 * p_point->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
				HX_STACK_LINE(148)
				Float vz = ((((_this->m20 * p_point->x) + (_this->m21 * p_point->y)) + (_this->m22 * p_point->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
				HX_STACK_LINE(148)
				p_point->x = vx;
				HX_STACK_LINE(148)
				p_point->y = vy;
				HX_STACK_LINE(148)
				p_point->z = vz;
				HX_STACK_LINE(148)
				p_point;
			}
			struct _Function_2_1{
				inline static Float Block( hx::ObjectPtr< ::haxor::component::MeshRenderer_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/MeshRenderer.hx",151,0x9df8586f)
					{
						HX_STACK_LINE(151)
						::haxor::math::AABB3 _this = __this->m_mesh->m_bounds;		HX_STACK_VAR(_this,"_this");
						struct _Function_3_1{
							inline static Float Block( ::haxor::math::AABB3 _this){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/MeshRenderer.hx",151,0x9df8586f)
								{
									HX_STACK_LINE(151)
									Float p_a = (_this->m_xMax - _this->m_xMin);		HX_STACK_VAR(p_a,"p_a");
									HX_STACK_LINE(151)
									return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
								}
								return null();
							}
						};
						HX_STACK_LINE(151)
						return _Function_3_1::Block(_this);
					}
					return null();
				}
			};
			struct _Function_2_2{
				inline static Float Block( hx::ObjectPtr< ::haxor::component::MeshRenderer_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/MeshRenderer.hx",151,0x9df8586f)
					{
						HX_STACK_LINE(151)
						::haxor::math::AABB3 _this = __this->m_mesh->m_bounds;		HX_STACK_VAR(_this,"_this");
						struct _Function_3_1{
							inline static Float Block( ::haxor::math::AABB3 _this){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/MeshRenderer.hx",151,0x9df8586f)
								{
									HX_STACK_LINE(151)
									Float p_a = (_this->m_yMax - _this->m_yMin);		HX_STACK_VAR(p_a,"p_a");
									HX_STACK_LINE(151)
									return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
								}
								return null();
							}
						};
						HX_STACK_LINE(151)
						return _Function_3_1::Block(_this);
					}
					return null();
				}
			};
			struct _Function_2_3{
				inline static Float Block( hx::ObjectPtr< ::haxor::component::MeshRenderer_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/MeshRenderer.hx",151,0x9df8586f)
					{
						HX_STACK_LINE(151)
						::haxor::math::AABB3 _this = __this->m_mesh->m_bounds;		HX_STACK_VAR(_this,"_this");
						struct _Function_3_1{
							inline static Float Block( ::haxor::math::AABB3 _this){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/component/MeshRenderer.hx",151,0x9df8586f)
								{
									HX_STACK_LINE(151)
									Float p_a = (_this->m_zMax - _this->m_zMin);		HX_STACK_VAR(p_a,"p_a");
									HX_STACK_LINE(151)
									return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
								}
								return null();
							}
						};
						HX_STACK_LINE(151)
						return _Function_3_1::Block(_this);
					}
					return null();
				}
			};
			HX_STACK_LINE(151)
			this->m_ws_radius->Set(_Function_2_1::Block(this),_Function_2_2::Block(this),_Function_2_3::Block(this));
			HX_STACK_LINE(152)
			{
				HX_STACK_LINE(152)
				::haxor::math::Matrix4 _this = this->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(152)
				::haxor::math::Vector3 p_point = this->m_ws_radius;		HX_STACK_VAR(p_point,"p_point");
				HX_STACK_LINE(152)
				Float vx = (((_this->m00 * p_point->x) + (_this->m01 * p_point->y)) + (_this->m02 * p_point->z));		HX_STACK_VAR(vx,"vx");
				HX_STACK_LINE(152)
				Float vy = (((_this->m10 * p_point->x) + (_this->m11 * p_point->y)) + (_this->m12 * p_point->z));		HX_STACK_VAR(vy,"vy");
				HX_STACK_LINE(152)
				Float vz = (((_this->m20 * p_point->x) + (_this->m21 * p_point->y)) + (_this->m22 * p_point->z));		HX_STACK_VAR(vz,"vz");
				HX_STACK_LINE(152)
				p_point->x = vx;
				HX_STACK_LINE(152)
				p_point->y = vy;
				HX_STACK_LINE(152)
				p_point->z = vz;
				HX_STACK_LINE(152)
				p_point;
			}
			HX_STACK_LINE(154)
			Float _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(154)
			{
				HX_STACK_LINE(154)
				::haxor::math::Vector3 _this = this->m_ws_radius;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(154)
				_g = ::Math_obj::sqrt((((_this->x * _this->x) + (_this->y * _this->y)) + (_this->z * _this->z)));
			}
			HX_STACK_LINE(154)
			Float r = (_g * 0.5);		HX_STACK_VAR(r,"r");
			HX_STACK_LINE(155)
			::haxor::math::Vector3 pmin;		HX_STACK_VAR(pmin,"pmin");
			HX_STACK_LINE(155)
			{
				HX_STACK_LINE(155)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(155)
				int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(155)
				pmin = _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
			}
			HX_STACK_LINE(156)
			::haxor::math::Vector3 pmax;		HX_STACK_VAR(pmax,"pmax");
			HX_STACK_LINE(156)
			{
				HX_STACK_LINE(156)
				::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(156)
				int _g2 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(156)
				pmax = _this->m_v3->__get(_g2).StaticCast< ::haxor::math::Vector3 >();
			}
			HX_STACK_LINE(157)
			pmin->Set((this->m_ws_center->x - r),(this->m_ws_center->y - r),(this->m_ws_center->z - r));
			HX_STACK_LINE(158)
			pmax->Set((this->m_ws_center->x + r),(this->m_ws_center->y + r),(this->m_ws_center->z + r));
			HX_STACK_LINE(159)
			this->m_aabb->Set3(pmin,pmax);
			HX_STACK_LINE(160)
			::haxor::context::EngineContext_obj::renderer->UpdateSAP(this->__fcid,hx::ObjectPtr<OBJ_>(this),pmin,pmax);
			HX_STACK_LINE(162)
			this->m_culling_dirty = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MeshRenderer_obj,UpdateWorldBounds,(void))

Void MeshRenderer_obj::OnRender( ){
{
		HX_STACK_FRAME("haxor.component.MeshRenderer","OnRender",0x80ec0b16,"haxor.component.MeshRenderer.OnRender","haxor/component/MeshRenderer.hx",170,0x9df8586f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(171)
		this->super::OnRender();
		HX_STACK_LINE(172)
		if (((this->m_mesh == null()))){
			HX_STACK_LINE(172)
			return null();
		}
		HX_STACK_LINE(174)
		::haxor::component::MeshRenderer_obj::current = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(176)
		::haxor::graphics::Graphics_obj::Render(this->m_mesh,this->m_material,this->m_entity->m_transform,::haxor::component::Camera_obj::m_current);
	}
return null();
}


::haxor::component::MeshRenderer MeshRenderer_obj::current;


MeshRenderer_obj::MeshRenderer_obj()
{
}

void MeshRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MeshRenderer);
	HX_MARK_MEMBER_NAME(__fcid,"__fcid");
	HX_MARK_MEMBER_NAME(m_mesh,"m_mesh");
	HX_MARK_MEMBER_NAME(m_ws_center,"m_ws_center");
	HX_MARK_MEMBER_NAME(m_ws_radius,"m_ws_radius");
	HX_MARK_MEMBER_NAME(m_aabb,"m_aabb");
	HX_MARK_MEMBER_NAME(m_culling_dirty,"m_culling_dirty");
	::haxor::component::Renderer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MeshRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__fcid,"__fcid");
	HX_VISIT_MEMBER_NAME(m_mesh,"m_mesh");
	HX_VISIT_MEMBER_NAME(m_ws_center,"m_ws_center");
	HX_VISIT_MEMBER_NAME(m_ws_radius,"m_ws_radius");
	HX_VISIT_MEMBER_NAME(m_aabb,"m_aabb");
	HX_VISIT_MEMBER_NAME(m_culling_dirty,"m_culling_dirty");
	::haxor::component::Renderer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic MeshRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"mesh") ) { return get_mesh(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"__fcid") ) { return __fcid; }
		if (HX_FIELD_EQ(inName,"m_mesh") ) { return m_mesh; }
		if (HX_FIELD_EQ(inName,"m_aabb") ) { return m_aabb; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { return current; }
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
		if (HX_FIELD_EQ(inName,"m_ws_center") ) { return m_ws_center; }
		if (HX_FIELD_EQ(inName,"m_ws_radius") ) { return m_ws_radius; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"CheckCulling") ) { return CheckCulling_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_culling_dirty") ) { return m_culling_dirty; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"OnTransformUpdate") ) { return OnTransformUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateWorldBounds") ) { return UpdateWorldBounds_dyn(); }
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
		if (HX_FIELD_EQ(inName,"__fcid") ) { __fcid=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_mesh") ) { m_mesh=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_aabb") ) { m_aabb=inValue.Cast< ::haxor::math::AABB3 >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { current=inValue.Cast< ::haxor::component::MeshRenderer >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_ws_center") ) { m_ws_center=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_ws_radius") ) { m_ws_radius=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_culling_dirty") ) { m_culling_dirty=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MeshRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__fcid"));
	outFields->push(HX_CSTRING("mesh"));
	outFields->push(HX_CSTRING("m_mesh"));
	outFields->push(HX_CSTRING("m_ws_center"));
	outFields->push(HX_CSTRING("m_ws_radius"));
	outFields->push(HX_CSTRING("m_aabb"));
	outFields->push(HX_CSTRING("m_culling_dirty"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("current"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(MeshRenderer_obj,__fcid),HX_CSTRING("__fcid")},
	{hx::fsObject /*::haxor::graphics::mesh::Mesh*/ ,(int)offsetof(MeshRenderer_obj,m_mesh),HX_CSTRING("m_mesh")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(MeshRenderer_obj,m_ws_center),HX_CSTRING("m_ws_center")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(MeshRenderer_obj,m_ws_radius),HX_CSTRING("m_ws_radius")},
	{hx::fsObject /*::haxor::math::AABB3*/ ,(int)offsetof(MeshRenderer_obj,m_aabb),HX_CSTRING("m_aabb")},
	{hx::fsBool,(int)offsetof(MeshRenderer_obj,m_culling_dirty),HX_CSTRING("m_culling_dirty")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("__fcid"),
	HX_CSTRING("get_mesh"),
	HX_CSTRING("set_mesh"),
	HX_CSTRING("m_mesh"),
	HX_CSTRING("m_ws_center"),
	HX_CSTRING("m_ws_radius"),
	HX_CSTRING("m_aabb"),
	HX_CSTRING("m_culling_dirty"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("IsVisible"),
	HX_CSTRING("CheckCulling"),
	HX_CSTRING("OnTransformUpdate"),
	HX_CSTRING("UpdateWorldBounds"),
	HX_CSTRING("OnRender"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MeshRenderer_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(MeshRenderer_obj::current,"current");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MeshRenderer_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(MeshRenderer_obj::current,"current");
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
