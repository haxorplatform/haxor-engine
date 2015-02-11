#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
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
#ifndef INCLUDED_haxor_component_light_Light
#include <haxor/component/light/Light.h>
#endif
#ifndef INCLUDED_haxor_component_light_PointLight
#include <haxor/component/light/PointLight.h>
#endif
#ifndef INCLUDED_haxor_component_physics_BoxCollider
#include <haxor/component/physics/BoxCollider.h>
#endif
#ifndef INCLUDED_haxor_component_physics_Collider
#include <haxor/component/physics/Collider.h>
#endif
#ifndef INCLUDED_haxor_component_physics_SphereCollider
#include <haxor/component/physics/SphereCollider.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_GizmoContext
#include <haxor/context/GizmoContext.h>
#endif
#ifndef INCLUDED_haxor_core_ColliderType
#include <haxor/core/ColliderType.h>
#endif
#ifndef INCLUDED_haxor_core_Debug
#include <haxor/core/Debug.h>
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
#ifndef INCLUDED_haxor_graphics_Gizmo
#include <haxor/graphics/Gizmo.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#include <haxor/graphics/mesh/Mesh.h>
#endif
#ifndef INCLUDED_haxor_math_AABB3
#include <haxor/math/AABB3.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace core{

Void Debug_obj::__construct()
{
	return null();
}

//Debug_obj::~Debug_obj() { }

Dynamic Debug_obj::__CreateEmpty() { return  new Debug_obj; }
hx::ObjectPtr< Debug_obj > Debug_obj::__new()
{  hx::ObjectPtr< Debug_obj > result = new Debug_obj();
	result->__construct();
	return result;}

Dynamic Debug_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Debug_obj > result = new Debug_obj();
	result->__construct();
	return result;}

bool Debug_obj::collider;

bool Debug_obj::colliderAABB;

bool Debug_obj::colliderSB;

bool Debug_obj::transform;

bool Debug_obj::renderer;

bool Debug_obj::rendererAABB;

bool Debug_obj::light;

::haxor::math::Color Debug_obj::color_white;

::haxor::math::Color Debug_obj::color_collider;

::haxor::math::Color Debug_obj::color_trigger;

::haxor::math::Color Debug_obj::color_bounding;

::haxor::math::Color Debug_obj::color_renderer;

::haxor::math::Color Debug_obj::color_light;

Void Debug_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.core.Debug","Initialize",0x9c5fe88e,"haxor.core.Debug.Initialize","haxor/core/Debug.hx",75,0xbbdb7c8e)
		HX_STACK_LINE(76)
		::haxor::core::Debug_obj::collider = false;
		HX_STACK_LINE(77)
		::haxor::core::Debug_obj::colliderAABB = false;
		HX_STACK_LINE(78)
		::haxor::core::Debug_obj::colliderSB = false;
		HX_STACK_LINE(79)
		::haxor::core::Debug_obj::transform = false;
		HX_STACK_LINE(80)
		::haxor::core::Debug_obj::renderer = false;
		HX_STACK_LINE(81)
		::haxor::core::Debug_obj::rendererAABB = false;
		HX_STACK_LINE(82)
		::haxor::core::Debug_obj::light = false;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Debug_obj,Initialize,(void))

Void Debug_obj::Collider( ::haxor::component::physics::Collider c){
{
		HX_STACK_FRAME("haxor.core.Debug","Collider",0xf621aaf2,"haxor.core.Debug.Collider","haxor/core/Debug.hx",90,0xbbdb7c8e)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(91)
		::haxor::component::Transform t = c->m_entity->m_transform;		HX_STACK_VAR(t,"t");
		HX_STACK_LINE(92)
		::haxor::math::Matrix4 wm = t->get_WorldMatrix();		HX_STACK_VAR(wm,"wm");
		HX_STACK_LINE(93)
		::haxor::component::physics::BoxCollider bc;		HX_STACK_VAR(bc,"bc");
		HX_STACK_LINE(94)
		::haxor::component::physics::SphereCollider sc;		HX_STACK_VAR(sc,"sc");
		struct _Function_1_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",95,0xbbdb7c8e)
				{
					HX_STACK_LINE(95)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(95)
					int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(95)
					return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(95)
		::haxor::math::Vector3 o = (_Function_1_1::Block())->Set(null(),null(),null());		HX_STACK_VAR(o,"o");
		HX_STACK_LINE(96)
		::haxor::math::Color cl;		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(96)
		if ((c->trigger)){
			HX_STACK_LINE(96)
			cl = ::haxor::core::Debug_obj::color_trigger;
		}
		else{
			HX_STACK_LINE(96)
			cl = ::haxor::core::Debug_obj::color_collider;
		}
		HX_STACK_LINE(98)
		Float _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(98)
		if ((c->get_enabled())){
			HX_STACK_LINE(98)
			_g1 = 1.0;
		}
		else{
			HX_STACK_LINE(98)
			_g1 = 0.01;
		}
		HX_STACK_LINE(98)
		cl->a = _g1;
		HX_STACK_LINE(100)
		{
			HX_STACK_LINE(100)
			::haxor::core::ColliderType _g = c->get_type();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(100)
			switch( (int)(_g->__Index())){
				case (int)2: {
					HX_STACK_LINE(103)
					bc = c;
					HX_STACK_LINE(104)
					o->Set3(bc->m_center);
					HX_STACK_LINE(105)
					::haxor::graphics::Gizmo_obj::WireCube(o,bc->m_size,cl,wm);
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(108)
					sc = c;
					struct _Function_3_1{
						inline static ::haxor::math::Vector3 Block( ){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",109,0xbbdb7c8e)
							{
								HX_STACK_LINE(109)
								::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
								HX_STACK_LINE(109)
								int _g2 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g2,"_g2");
								HX_STACK_LINE(109)
								return _this->m_v3->__get(_g2).StaticCast< ::haxor::math::Vector3 >();
							}
							return null();
						}
					};
					HX_STACK_LINE(109)
					::haxor::math::Vector3 rad = (_Function_3_1::Block())->Set(0.5773507,0.5773507,0.5773507);		HX_STACK_VAR(rad,"rad");
					HX_STACK_LINE(110)
					::haxor::math::Matrix4 _g4;		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(110)
					{
						HX_STACK_LINE(110)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(110)
						int _g3 = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(110)
						_g4 = _this->m_m4->__get(_g3).StaticCast< ::haxor::math::Matrix4 >();
					}
					HX_STACK_LINE(110)
					::haxor::math::Matrix4 sm = ::haxor::math::Matrix4_obj::GetScale(wm,_g4);		HX_STACK_VAR(sm,"sm");
					HX_STACK_LINE(111)
					{
						HX_STACK_LINE(111)
						Float vx = (((sm->m00 * rad->x) + (sm->m01 * rad->y)) + (sm->m02 * rad->z));		HX_STACK_VAR(vx,"vx");
						HX_STACK_LINE(111)
						Float vy = (((sm->m10 * rad->x) + (sm->m11 * rad->y)) + (sm->m12 * rad->z));		HX_STACK_VAR(vy,"vy");
						HX_STACK_LINE(111)
						Float vz = (((sm->m20 * rad->x) + (sm->m21 * rad->y)) + (sm->m22 * rad->z));		HX_STACK_VAR(vz,"vz");
						HX_STACK_LINE(111)
						rad->x = vx;
						HX_STACK_LINE(111)
						rad->y = vy;
						HX_STACK_LINE(111)
						rad->z = vz;
						HX_STACK_LINE(111)
						rad;
					}
					HX_STACK_LINE(112)
					o->Set3(sc->m_center);
					HX_STACK_LINE(113)
					Float _g5 = ::Math_obj::sqrt((((rad->x * rad->x) + (rad->y * rad->y)) + (rad->z * rad->z)));		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(113)
					Float _g6 = sc->get_radius();		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(113)
					Float _g7 = (_g5 * _g6);		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(113)
					::haxor::graphics::Gizmo_obj::WireSphere(o,_g7,cl,wm);
				}
				;break;
				case (int)0: {
				}
				;break;
				case (int)1: {
				}
				;break;
				case (int)5: {
				}
				;break;
				case (int)4: {
				}
				;break;
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Debug_obj,Collider,(void))

Void Debug_obj::BoundingAABB( ::haxor::math::AABB3 c){
{
		HX_STACK_FRAME("haxor.core.Debug","BoundingAABB",0xd7de06c2,"haxor.core.Debug.BoundingAABB","haxor/core/Debug.hx",127,0xbbdb7c8e)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(128)
		::haxor::math::AABB3 bb = c;		HX_STACK_VAR(bb,"bb");
		HX_STACK_LINE(129)
		::haxor::math::Vector3 _g = bb->get_center();		HX_STACK_VAR(_g,"_g");
		struct _Function_1_1{
			inline static Float Block( ::haxor::math::AABB3 &bb){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",129,0xbbdb7c8e)
				{
					HX_STACK_LINE(129)
					Float p_a = (bb->m_xMax - bb->m_xMin);		HX_STACK_VAR(p_a,"p_a");
					HX_STACK_LINE(129)
					return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
				}
				return null();
			}
		};
		struct _Function_1_2{
			inline static Float Block( ::haxor::math::AABB3 &bb){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",129,0xbbdb7c8e)
				{
					HX_STACK_LINE(129)
					Float p_a = (bb->m_yMax - bb->m_yMin);		HX_STACK_VAR(p_a,"p_a");
					HX_STACK_LINE(129)
					return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
				}
				return null();
			}
		};
		struct _Function_1_3{
			inline static Float Block( ::haxor::math::AABB3 &bb){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",129,0xbbdb7c8e)
				{
					HX_STACK_LINE(129)
					Float p_a = (bb->m_zMax - bb->m_zMin);		HX_STACK_VAR(p_a,"p_a");
					HX_STACK_LINE(129)
					return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
				}
				return null();
			}
		};
		HX_STACK_LINE(129)
		::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0)->Set(_Function_1_1::Block(bb),_Function_1_2::Block(bb),_Function_1_3::Block(bb));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(129)
		::haxor::graphics::Gizmo_obj::WireCube(_g,_g1,::haxor::core::Debug_obj::color_bounding,null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Debug_obj,BoundingAABB,(void))

Void Debug_obj::BoundingSphere( ::haxor::math::Vector4 c){
{
		HX_STACK_FRAME("haxor.core.Debug","BoundingSphere",0x6bf98bcf,"haxor.core.Debug.BoundingSphere","haxor/core/Debug.hx",137,0xbbdb7c8e)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(138)
		::haxor::math::Vector4 sb = c;		HX_STACK_VAR(sb,"sb");
		struct _Function_1_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",139,0xbbdb7c8e)
				{
					HX_STACK_LINE(139)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(139)
					int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(139)
					return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(139)
		::haxor::math::Vector3 _g1 = (_Function_1_1::Block())->Set(sb->x,sb->y,sb->z);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(139)
		::haxor::graphics::Gizmo_obj::WireSphere(_g1,sb->w,::haxor::core::Debug_obj::color_bounding,null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Debug_obj,BoundingSphere,(void))

Void Debug_obj::MeshRenderer( ::haxor::component::MeshRenderer r){
{
		HX_STACK_FRAME("haxor.core.Debug","MeshRenderer",0xe205830e,"haxor.core.Debug.MeshRenderer","haxor/core/Debug.hx",147,0xbbdb7c8e)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(148)
		::haxor::math::AABB3 bb = r->m_mesh->m_bounds;		HX_STACK_VAR(bb,"bb");
		struct _Function_1_1{
			inline static ::haxor::math::Color Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",149,0xbbdb7c8e)
				{
					HX_STACK_LINE(149)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(149)
					int _g = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(149)
					return _this->m_c->__get(_g).StaticCast< ::haxor::math::Color >();
				}
				return null();
			}
		};
		HX_STACK_LINE(149)
		::haxor::math::Color c = (_Function_1_1::Block())->SetColor(::haxor::core::Debug_obj::color_renderer);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(150)
		if (((bool(r->m_visible) && bool(!(r->m_culled))))){
			HX_STACK_LINE(150)
			c->a = 1.0;
		}
		else{
			HX_STACK_LINE(150)
			c->a = 0.2;
		}
		HX_STACK_LINE(151)
		::haxor::math::Vector3 _g1 = bb->get_center();		HX_STACK_VAR(_g1,"_g1");
		struct _Function_1_2{
			inline static Float Block( ::haxor::math::AABB3 &bb){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",151,0xbbdb7c8e)
				{
					HX_STACK_LINE(151)
					Float p_a = (bb->m_xMax - bb->m_xMin);		HX_STACK_VAR(p_a,"p_a");
					HX_STACK_LINE(151)
					return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
				}
				return null();
			}
		};
		struct _Function_1_3{
			inline static Float Block( ::haxor::math::AABB3 &bb){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",151,0xbbdb7c8e)
				{
					HX_STACK_LINE(151)
					Float p_a = (bb->m_yMax - bb->m_yMin);		HX_STACK_VAR(p_a,"p_a");
					HX_STACK_LINE(151)
					return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
				}
				return null();
			}
		};
		struct _Function_1_4{
			inline static Float Block( ::haxor::math::AABB3 &bb){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",151,0xbbdb7c8e)
				{
					HX_STACK_LINE(151)
					Float p_a = (bb->m_zMax - bb->m_zMin);		HX_STACK_VAR(p_a,"p_a");
					HX_STACK_LINE(151)
					return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
				}
				return null();
			}
		};
		HX_STACK_LINE(151)
		::haxor::math::Vector3 _g2 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0)->Set(_Function_1_2::Block(bb),_Function_1_3::Block(bb),_Function_1_4::Block(bb));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(151)
		::haxor::math::Matrix4 _g3 = r->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(151)
		::haxor::graphics::Gizmo_obj::WireCube(_g1,_g2,c,_g3);
		HX_STACK_LINE(153)
		if ((::haxor::core::Debug_obj::rendererAABB)){
			HX_STACK_LINE(155)
			bb = r->m_aabb;
			struct _Function_2_1{
				inline static ::haxor::math::Color Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",156,0xbbdb7c8e)
					{
						HX_STACK_LINE(156)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(156)
						int _g4 = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(156)
						return _this->m_c->__get(_g4).StaticCast< ::haxor::math::Color >();
					}
					return null();
				}
			};
			HX_STACK_LINE(156)
			::haxor::math::Color _g5 = (_Function_2_1::Block())->SetColor(::haxor::core::Debug_obj::color_bounding);		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(156)
			c = _g5;
			HX_STACK_LINE(157)
			if (((bool(r->m_visible) && bool(!(r->m_culled))))){
				HX_STACK_LINE(157)
				c->a = 1.0;
			}
			else{
				HX_STACK_LINE(157)
				c->a = 0.2;
			}
			HX_STACK_LINE(158)
			::haxor::math::Vector3 _g6 = bb->get_center();		HX_STACK_VAR(_g6,"_g6");
			struct _Function_2_2{
				inline static Float Block( ::haxor::math::AABB3 &bb){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",158,0xbbdb7c8e)
					{
						HX_STACK_LINE(158)
						Float p_a = (bb->m_xMax - bb->m_xMin);		HX_STACK_VAR(p_a,"p_a");
						HX_STACK_LINE(158)
						return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
					}
					return null();
				}
			};
			struct _Function_2_3{
				inline static Float Block( ::haxor::math::AABB3 &bb){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",158,0xbbdb7c8e)
					{
						HX_STACK_LINE(158)
						Float p_a = (bb->m_yMax - bb->m_yMin);		HX_STACK_VAR(p_a,"p_a");
						HX_STACK_LINE(158)
						return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
					}
					return null();
				}
			};
			struct _Function_2_4{
				inline static Float Block( ::haxor::math::AABB3 &bb){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",158,0xbbdb7c8e)
					{
						HX_STACK_LINE(158)
						Float p_a = (bb->m_zMax - bb->m_zMin);		HX_STACK_VAR(p_a,"p_a");
						HX_STACK_LINE(158)
						return (  (((p_a < (int)0))) ? Float(-(p_a)) : Float(p_a) );
					}
					return null();
				}
			};
			HX_STACK_LINE(158)
			::haxor::math::Vector3 _g7 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0)->Set(_Function_2_2::Block(bb),_Function_2_3::Block(bb),_Function_2_4::Block(bb));		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(158)
			::haxor::graphics::Gizmo_obj::WireCube(_g6,_g7,c,null());
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Debug_obj,MeshRenderer,(void))

Void Debug_obj::Transform( ::haxor::component::Transform t){
{
		HX_STACK_FRAME("haxor.core.Debug","Transform",0xdb99a7ee,"haxor.core.Debug.Transform","haxor/core/Debug.hx",169,0xbbdb7c8e)
		HX_STACK_ARG(t,"t")
		struct _Function_1_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",169,0xbbdb7c8e)
				{
					HX_STACK_LINE(169)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(169)
					int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(169)
					return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(169)
		::haxor::math::Vector3 p_position = (_Function_1_1::Block())->Set(null(),null(),null());		HX_STACK_VAR(p_position,"p_position");
		struct _Function_1_2{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",169,0xbbdb7c8e)
				{
					HX_STACK_LINE(169)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(169)
					int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(169)
					return _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(169)
		::haxor::math::Vector3 p_size = (_Function_1_2::Block())->Set(0.5,0.5,0.5);		HX_STACK_VAR(p_size,"p_size");
		HX_STACK_LINE(169)
		::haxor::math::Matrix4 p_transform = t->get_WorldMatrix();		HX_STACK_VAR(p_transform,"p_transform");
		HX_STACK_LINE(169)
		::haxor::context::EngineContext_obj::gizmo->DrawAxis(p_position,p_size,::haxor::core::Debug_obj::color_white,p_transform);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Debug_obj,Transform,(void))

Void Debug_obj::Camera( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.core.Debug","Camera",0x9ef906e3,"haxor.core.Debug.Camera","haxor/core/Debug.hx",177,0xbbdb7c8e)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(179)
		::haxor::core::Debug_obj::Transform(c->m_entity->m_transform);
		HX_STACK_LINE(180)
		::haxor::core::Debug_obj::Transform(c->m_entity->m_transform->m_parent);
		HX_STACK_LINE(182)
		Array< ::Dynamic > fp = c->m_frustum;		HX_STACK_VAR(fp,"fp");
		HX_STACK_LINE(183)
		Array< ::Dynamic > l = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(184)
		{
			HX_STACK_LINE(184)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(184)
			int _g = fp->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(184)
			while((true)){
				HX_STACK_LINE(184)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(184)
					break;
				}
				HX_STACK_LINE(184)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				struct _Function_3_1{
					inline static ::haxor::math::Vector4 Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/core/Debug.hx",186,0xbbdb7c8e)
						{
							HX_STACK_LINE(186)
							::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(186)
							int _g2 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(186)
							return _this->m_v4->__get(_g2).StaticCast< ::haxor::math::Vector4 >();
						}
						return null();
					}
				};
				HX_STACK_LINE(186)
				::haxor::math::Vector4 _g11 = (_Function_3_1::Block())->Set4(fp->__get(i).StaticCast< ::haxor::math::Vector4 >());		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(186)
				l->push(_g11);
				HX_STACK_LINE(187)
				{
					HX_STACK_LINE(187)
					::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(187)
					::haxor::math::Vector4 p_point = l->__get(i).StaticCast< ::haxor::math::Vector4 >();		HX_STACK_VAR(p_point,"p_point");
					HX_STACK_LINE(187)
					Float vx = ((((_this->m00 * p_point->x) + (_this->m01 * p_point->y)) + (_this->m02 * p_point->z)) + (_this->m03 * p_point->w));		HX_STACK_VAR(vx,"vx");
					HX_STACK_LINE(187)
					Float vy = ((((_this->m10 * p_point->x) + (_this->m11 * p_point->y)) + (_this->m12 * p_point->z)) + (_this->m13 * p_point->w));		HX_STACK_VAR(vy,"vy");
					HX_STACK_LINE(187)
					Float vz = ((((_this->m20 * p_point->x) + (_this->m21 * p_point->y)) + (_this->m22 * p_point->z)) + (_this->m23 * p_point->w));		HX_STACK_VAR(vz,"vz");
					HX_STACK_LINE(187)
					Float vw = ((((_this->m30 * p_point->x) + (_this->m31 * p_point->y)) + (_this->m32 * p_point->z)) + (_this->m33 * p_point->w));		HX_STACK_VAR(vw,"vw");
					HX_STACK_LINE(187)
					p_point->x = vx;
					HX_STACK_LINE(187)
					p_point->y = vy;
					HX_STACK_LINE(187)
					p_point->z = vz;
					HX_STACK_LINE(187)
					p_point->w = vw;
					HX_STACK_LINE(187)
					p_point;
				}
			}
		}
		HX_STACK_LINE(189)
		fp = l;
		HX_STACK_LINE(191)
		::haxor::math::Vector3 p0;		HX_STACK_VAR(p0,"p0");
		HX_STACK_LINE(191)
		{
			HX_STACK_LINE(191)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(191)
			int _g2 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(191)
			p0 = _this->m_v3->__get(_g2).StaticCast< ::haxor::math::Vector3 >();
		}
		HX_STACK_LINE(192)
		::haxor::math::Vector3 p1;		HX_STACK_VAR(p1,"p1");
		HX_STACK_LINE(192)
		{
			HX_STACK_LINE(192)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(192)
			int _g3 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(192)
			p1 = _this->m_v3->__get(_g3).StaticCast< ::haxor::math::Vector3 >();
		}
		HX_STACK_LINE(194)
		p0->Set4(fp->__get((int)0).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(194)
		p1->Set4(fp->__get((int)1).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(194)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(p0,p1,::haxor::core::Debug_obj::color_white,null());
		HX_STACK_LINE(195)
		p0->Set4(fp->__get((int)1).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(195)
		p1->Set4(fp->__get((int)2).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(195)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(p0,p1,::haxor::core::Debug_obj::color_white,null());
		HX_STACK_LINE(196)
		p0->Set4(fp->__get((int)2).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(196)
		p1->Set4(fp->__get((int)3).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(196)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(p0,p1,::haxor::core::Debug_obj::color_white,null());
		HX_STACK_LINE(197)
		p0->Set4(fp->__get((int)3).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(197)
		p1->Set4(fp->__get((int)0).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(197)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(p0,p1,::haxor::core::Debug_obj::color_white,null());
		HX_STACK_LINE(199)
		p0->Set4(fp->__get((int)4).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(199)
		p1->Set4(fp->__get((int)5).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(199)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(p0,p1,::haxor::core::Debug_obj::color_white,null());
		HX_STACK_LINE(200)
		p0->Set4(fp->__get((int)5).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(200)
		p1->Set4(fp->__get((int)6).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(200)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(p0,p1,::haxor::core::Debug_obj::color_white,null());
		HX_STACK_LINE(201)
		p0->Set4(fp->__get((int)6).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(201)
		p1->Set4(fp->__get((int)7).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(201)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(p0,p1,::haxor::core::Debug_obj::color_white,null());
		HX_STACK_LINE(202)
		p0->Set4(fp->__get((int)7).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(202)
		p1->Set4(fp->__get((int)4).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(202)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(p0,p1,::haxor::core::Debug_obj::color_white,null());
		HX_STACK_LINE(204)
		p0->Set4(fp->__get((int)0).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(204)
		p1->Set4(fp->__get((int)4).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(204)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(p0,p1,::haxor::core::Debug_obj::color_white,null());
		HX_STACK_LINE(205)
		p0->Set4(fp->__get((int)1).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(205)
		p1->Set4(fp->__get((int)5).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(205)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(p0,p1,::haxor::core::Debug_obj::color_white,null());
		HX_STACK_LINE(206)
		p0->Set4(fp->__get((int)2).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(206)
		p1->Set4(fp->__get((int)6).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(206)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(p0,p1,::haxor::core::Debug_obj::color_white,null());
		HX_STACK_LINE(207)
		p0->Set4(fp->__get((int)3).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(207)
		p1->Set4(fp->__get((int)7).StaticCast< ::haxor::math::Vector4 >());
		HX_STACK_LINE(207)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(p0,p1,::haxor::core::Debug_obj::color_white,null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Debug_obj,Camera,(void))

Void Debug_obj::Light( ::haxor::component::light::Light l){
{
		HX_STACK_FRAME("haxor.core.Debug","Light",0x45cf2258,"haxor.core.Debug.Light","haxor/core/Debug.hx",216,0xbbdb7c8e)
		HX_STACK_ARG(l,"l")
		HX_STACK_LINE(217)
		::haxor::math::Color cl;		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(217)
		{
			HX_STACK_LINE(217)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(217)
			int _g = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(217)
			cl = _this->m_c->__get(_g).StaticCast< ::haxor::math::Color >();
		}
		HX_STACK_LINE(218)
		if ((::Std_obj::is(l,hx::ClassOf< ::haxor::component::light::PointLight >()))){
			HX_STACK_LINE(220)
			::haxor::component::light::PointLight pl = l;		HX_STACK_VAR(pl,"pl");
			HX_STACK_LINE(221)
			::haxor::math::Vector3 p = l->m_entity->m_transform->get_position();		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(222)
			cl->SetColor(::haxor::core::Debug_obj::color_light);
			HX_STACK_LINE(222)
			Float _g1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(222)
			if ((l->get_enabled())){
				HX_STACK_LINE(222)
				_g1 = 1.0;
			}
			else{
				HX_STACK_LINE(222)
				_g1 = 0.33;
			}
			HX_STACK_LINE(222)
			cl->a = _g1;
			HX_STACK_LINE(223)
			::haxor::graphics::Gizmo_obj::WireSphere(p,pl->radius,cl,null());
			HX_STACK_LINE(224)
			cl->SetColor(l->color);
			HX_STACK_LINE(224)
			Float _g2;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(224)
			if ((l->get_enabled())){
				HX_STACK_LINE(224)
				_g2 = 1.0;
			}
			else{
				HX_STACK_LINE(224)
				_g2 = 0.33;
			}
			HX_STACK_LINE(224)
			cl->a = _g2;
			HX_STACK_LINE(225)
			::haxor::graphics::Gizmo_obj::Point(p,15.0,l->color,null(),null());
			HX_STACK_LINE(226)
			return null();
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Debug_obj,Light,(void))


Debug_obj::Debug_obj()
{
}

Dynamic Debug_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"light") ) { return light; }
		if (HX_FIELD_EQ(inName,"Light") ) { return Light_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Camera") ) { return Camera_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"collider") ) { return collider; }
		if (HX_FIELD_EQ(inName,"renderer") ) { return renderer; }
		if (HX_FIELD_EQ(inName,"Collider") ) { return Collider_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { return transform; }
		if (HX_FIELD_EQ(inName,"Transform") ) { return Transform_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"colliderSB") ) { return colliderSB; }
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"color_white") ) { return color_white; }
		if (HX_FIELD_EQ(inName,"color_light") ) { return color_light; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"colliderAABB") ) { return colliderAABB; }
		if (HX_FIELD_EQ(inName,"rendererAABB") ) { return rendererAABB; }
		if (HX_FIELD_EQ(inName,"BoundingAABB") ) { return BoundingAABB_dyn(); }
		if (HX_FIELD_EQ(inName,"MeshRenderer") ) { return MeshRenderer_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"color_trigger") ) { return color_trigger; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"color_collider") ) { return color_collider; }
		if (HX_FIELD_EQ(inName,"color_bounding") ) { return color_bounding; }
		if (HX_FIELD_EQ(inName,"color_renderer") ) { return color_renderer; }
		if (HX_FIELD_EQ(inName,"BoundingSphere") ) { return BoundingSphere_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Debug_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"light") ) { light=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"collider") ) { collider=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"renderer") ) { renderer=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { transform=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"colliderSB") ) { colliderSB=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"color_white") ) { color_white=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"color_light") ) { color_light=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"colliderAABB") ) { colliderAABB=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rendererAABB") ) { rendererAABB=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"color_trigger") ) { color_trigger=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"color_collider") ) { color_collider=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"color_bounding") ) { color_bounding=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"color_renderer") ) { color_renderer=inValue.Cast< ::haxor::math::Color >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Debug_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("collider"),
	HX_CSTRING("colliderAABB"),
	HX_CSTRING("colliderSB"),
	HX_CSTRING("transform"),
	HX_CSTRING("renderer"),
	HX_CSTRING("rendererAABB"),
	HX_CSTRING("light"),
	HX_CSTRING("color_white"),
	HX_CSTRING("color_collider"),
	HX_CSTRING("color_trigger"),
	HX_CSTRING("color_bounding"),
	HX_CSTRING("color_renderer"),
	HX_CSTRING("color_light"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Collider"),
	HX_CSTRING("BoundingAABB"),
	HX_CSTRING("BoundingSphere"),
	HX_CSTRING("MeshRenderer"),
	HX_CSTRING("Transform"),
	HX_CSTRING("Camera"),
	HX_CSTRING("Light"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Debug_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Debug_obj::collider,"collider");
	HX_MARK_MEMBER_NAME(Debug_obj::colliderAABB,"colliderAABB");
	HX_MARK_MEMBER_NAME(Debug_obj::colliderSB,"colliderSB");
	HX_MARK_MEMBER_NAME(Debug_obj::transform,"transform");
	HX_MARK_MEMBER_NAME(Debug_obj::renderer,"renderer");
	HX_MARK_MEMBER_NAME(Debug_obj::rendererAABB,"rendererAABB");
	HX_MARK_MEMBER_NAME(Debug_obj::light,"light");
	HX_MARK_MEMBER_NAME(Debug_obj::color_white,"color_white");
	HX_MARK_MEMBER_NAME(Debug_obj::color_collider,"color_collider");
	HX_MARK_MEMBER_NAME(Debug_obj::color_trigger,"color_trigger");
	HX_MARK_MEMBER_NAME(Debug_obj::color_bounding,"color_bounding");
	HX_MARK_MEMBER_NAME(Debug_obj::color_renderer,"color_renderer");
	HX_MARK_MEMBER_NAME(Debug_obj::color_light,"color_light");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Debug_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Debug_obj::collider,"collider");
	HX_VISIT_MEMBER_NAME(Debug_obj::colliderAABB,"colliderAABB");
	HX_VISIT_MEMBER_NAME(Debug_obj::colliderSB,"colliderSB");
	HX_VISIT_MEMBER_NAME(Debug_obj::transform,"transform");
	HX_VISIT_MEMBER_NAME(Debug_obj::renderer,"renderer");
	HX_VISIT_MEMBER_NAME(Debug_obj::rendererAABB,"rendererAABB");
	HX_VISIT_MEMBER_NAME(Debug_obj::light,"light");
	HX_VISIT_MEMBER_NAME(Debug_obj::color_white,"color_white");
	HX_VISIT_MEMBER_NAME(Debug_obj::color_collider,"color_collider");
	HX_VISIT_MEMBER_NAME(Debug_obj::color_trigger,"color_trigger");
	HX_VISIT_MEMBER_NAME(Debug_obj::color_bounding,"color_bounding");
	HX_VISIT_MEMBER_NAME(Debug_obj::color_renderer,"color_renderer");
	HX_VISIT_MEMBER_NAME(Debug_obj::color_light,"color_light");
};

#endif

Class Debug_obj::__mClass;

void Debug_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.Debug"), hx::TCanCast< Debug_obj> ,sStaticFields,sMemberFields,
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

void Debug_obj::__boot()
{
	color_white= ::haxor::math::Color_obj::__new((int)1,(int)1,(int)1,(int)1);
	color_collider= ::haxor::math::Color_obj::__new(0.5,0.9,0.5,(int)1);
	color_trigger= ::haxor::math::Color_obj::__new(0.9,0.5,0.5,(int)1);
	color_bounding= ::haxor::math::Color_obj::__new(0.3,0.3,0.9,(int)1);
	color_renderer= ::haxor::math::Color_obj::__new(0.5,0.5,0.9,(int)1);
	color_light= ::haxor::math::Color_obj::__new(0.9,0.9,0.5,(int)1);
}

} // end namespace haxor
} // end namespace core
