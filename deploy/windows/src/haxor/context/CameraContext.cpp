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
#ifndef INCLUDED_haxor_context_RendererContext
#include <haxor/context/RendererContext.h>
#endif
#ifndef INCLUDED_haxor_context_TextureContext
#include <haxor/context/TextureContext.h>
#endif
#ifndef INCLUDED_haxor_context_UID
#include <haxor/context/UID.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
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
#ifndef INCLUDED_haxor_graphics_Graphics
#include <haxor/graphics/Graphics.h>
#endif
#ifndef INCLUDED_haxor_graphics_Screen
#include <haxor/graphics/Screen.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_RenderTexture
#include <haxor/graphics/texture/RenderTexture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_math_AABB2
#include <haxor/math/AABB2.h>
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
namespace context{

Void CameraContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.CameraContext","new",0xddbd8c31,"haxor.context.CameraContext.new","haxor/context/CameraContext.hx",49,0x8aadd161)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(50)
	::haxor::context::UID _g = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(50)
	this->cid = _g;
	HX_STACK_LINE(51)
	this->list = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(52)
	this->front = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(53)
	this->back = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(55)
	{
		HX_STACK_LINE(55)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(55)
		while((true)){
			HX_STACK_LINE(55)
			if ((!(((_g1 < (int)64))))){
				HX_STACK_LINE(55)
				break;
			}
			HX_STACK_LINE(55)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(57)
			this->front->push(null());
			HX_STACK_LINE(58)
			this->back->push(null());
		}
	}
}
;
	return null();
}

//CameraContext_obj::~CameraContext_obj() { }

Dynamic CameraContext_obj::__CreateEmpty() { return  new CameraContext_obj; }
hx::ObjectPtr< CameraContext_obj > CameraContext_obj::__new()
{  hx::ObjectPtr< CameraContext_obj > result = new CameraContext_obj();
	result->__construct();
	return result;}

Dynamic CameraContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CameraContext_obj > result = new CameraContext_obj();
	result->__construct();
	return result;}

Void CameraContext_obj::Create( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","Create",0x7fe697eb,"haxor.context.CameraContext.Create","haxor/context/CameraContext.hx",67,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(68)
		this->list->push(c);
		HX_STACK_LINE(69)
		this->SortCameraList();
		HX_STACK_LINE(70)
		::haxor::context::EngineContext_obj::renderer->AddCamera(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,Create,(void))

Void CameraContext_obj::Destroy( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","Destroy",0x7cf9cd2b,"haxor.context.CameraContext.Destroy","haxor/context/CameraContext.hx",78,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(79)
		this->ClearTargets(c);
		HX_STACK_LINE(80)
		this->list->remove(c);
		HX_STACK_LINE(81)
		this->SortCameraList();
		HX_STACK_LINE(82)
		{
			HX_STACK_LINE(82)
			int v = c->__cid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(82)
			this->cid->m_cache->push(v);
			HX_STACK_LINE(82)
			v;
		}
		HX_STACK_LINE(83)
		::haxor::context::EngineContext_obj::renderer->RemoveCamera(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,Destroy,(void))

Void CameraContext_obj::Bind( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","Bind",0x0b0abcec,"haxor.context.CameraContext.Bind","haxor/context/CameraContext.hx",93,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(94)
		::haxor::graphics::texture::RenderTexture ft = this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();		HX_STACK_VAR(ft,"ft");
		HX_STACK_LINE(95)
		::haxor::graphics::texture::RenderTexture rt = c->m_target;		HX_STACK_VAR(rt,"rt");
		HX_STACK_LINE(96)
		::haxor::graphics::texture::RenderTexture target;		HX_STACK_VAR(target,"target");
		HX_STACK_LINE(96)
		if (((ft == null()))){
			HX_STACK_LINE(96)
			target = rt;
		}
		else{
			HX_STACK_LINE(96)
			target = ft;
		}
		HX_STACK_LINE(98)
		c->UpdateProjection();
		HX_STACK_LINE(100)
		bool need_sap = (bool((bool(::haxor::context::EngineContext_obj::renderer->sap_dirty) || bool(c->m_view_uniform_dirty))) || bool(c->m_proj_uniform_dirty));		HX_STACK_VAR(need_sap,"need_sap");
		HX_STACK_LINE(102)
		need_sap = (bool(need_sap) && bool(::haxor::component::Camera_obj::sap));
		HX_STACK_LINE(104)
		if ((need_sap)){
			struct _Function_2_1{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/CameraContext.hx",106,0x8aadd161)
					{
						HX_STACK_LINE(106)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(106)
						int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(106)
						return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(106)
			::haxor::math::Vector3 n0 = (_Function_2_1::Block())->Set4(c->m_fn0);		HX_STACK_VAR(n0,"n0");
			struct _Function_2_2{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/CameraContext.hx",107,0x8aadd161)
					{
						HX_STACK_LINE(107)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(107)
						int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(107)
						return _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(107)
			::haxor::math::Vector3 n1 = (_Function_2_2::Block())->Set4(c->m_fn1);		HX_STACK_VAR(n1,"n1");
			struct _Function_2_3{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/CameraContext.hx",108,0x8aadd161)
					{
						HX_STACK_LINE(108)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(108)
						int _g2 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(108)
						return _this->m_v3->__get(_g2).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(108)
			::haxor::math::Vector3 n2 = (_Function_2_3::Block())->Set4(c->m_fn2);		HX_STACK_VAR(n2,"n2");
			struct _Function_2_4{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/CameraContext.hx",109,0x8aadd161)
					{
						HX_STACK_LINE(109)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(109)
						int _g3 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(109)
						return _this->m_v3->__get(_g3).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(109)
			::haxor::math::Vector3 n3 = (_Function_2_4::Block())->Set4(c->m_fn3);		HX_STACK_VAR(n3,"n3");
			struct _Function_2_5{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/CameraContext.hx",110,0x8aadd161)
					{
						HX_STACK_LINE(110)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(110)
						int _g4 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(110)
						return _this->m_v3->__get(_g4).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(110)
			::haxor::math::Vector3 f0 = (_Function_2_5::Block())->Set4(c->m_ff0);		HX_STACK_VAR(f0,"f0");
			struct _Function_2_6{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/CameraContext.hx",111,0x8aadd161)
					{
						HX_STACK_LINE(111)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(111)
						int _g5 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(111)
						return _this->m_v3->__get(_g5).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(111)
			::haxor::math::Vector3 f1 = (_Function_2_6::Block())->Set4(c->m_ff1);		HX_STACK_VAR(f1,"f1");
			struct _Function_2_7{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/CameraContext.hx",112,0x8aadd161)
					{
						HX_STACK_LINE(112)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(112)
						int _g6 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(112)
						return _this->m_v3->__get(_g6).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(112)
			::haxor::math::Vector3 f2 = (_Function_2_7::Block())->Set4(c->m_ff2);		HX_STACK_VAR(f2,"f2");
			struct _Function_2_8{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/CameraContext.hx",113,0x8aadd161)
					{
						HX_STACK_LINE(113)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(113)
						int _g7 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(113)
						return _this->m_v3->__get(_g7).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(113)
			::haxor::math::Vector3 f3 = (_Function_2_8::Block())->Set4(c->m_ff3);		HX_STACK_VAR(f3,"f3");
			HX_STACK_LINE(115)
			{
				HX_STACK_LINE(115)
				::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(115)
				Float vx = ((((_this->m00 * n0->x) + (_this->m01 * n0->y)) + (_this->m02 * n0->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
				HX_STACK_LINE(115)
				Float vy = ((((_this->m10 * n0->x) + (_this->m11 * n0->y)) + (_this->m12 * n0->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
				HX_STACK_LINE(115)
				Float vz = ((((_this->m20 * n0->x) + (_this->m21 * n0->y)) + (_this->m22 * n0->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
				HX_STACK_LINE(115)
				n0->x = vx;
				HX_STACK_LINE(115)
				n0->y = vy;
				HX_STACK_LINE(115)
				n0->z = vz;
				HX_STACK_LINE(115)
				n0;
			}
			HX_STACK_LINE(116)
			{
				HX_STACK_LINE(116)
				::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(116)
				Float vx = ((((_this->m00 * n1->x) + (_this->m01 * n1->y)) + (_this->m02 * n1->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
				HX_STACK_LINE(116)
				Float vy = ((((_this->m10 * n1->x) + (_this->m11 * n1->y)) + (_this->m12 * n1->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
				HX_STACK_LINE(116)
				Float vz = ((((_this->m20 * n1->x) + (_this->m21 * n1->y)) + (_this->m22 * n1->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
				HX_STACK_LINE(116)
				n1->x = vx;
				HX_STACK_LINE(116)
				n1->y = vy;
				HX_STACK_LINE(116)
				n1->z = vz;
				HX_STACK_LINE(116)
				n1;
			}
			HX_STACK_LINE(117)
			{
				HX_STACK_LINE(117)
				::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(117)
				Float vx = ((((_this->m00 * n2->x) + (_this->m01 * n2->y)) + (_this->m02 * n2->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
				HX_STACK_LINE(117)
				Float vy = ((((_this->m10 * n2->x) + (_this->m11 * n2->y)) + (_this->m12 * n2->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
				HX_STACK_LINE(117)
				Float vz = ((((_this->m20 * n2->x) + (_this->m21 * n2->y)) + (_this->m22 * n2->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
				HX_STACK_LINE(117)
				n2->x = vx;
				HX_STACK_LINE(117)
				n2->y = vy;
				HX_STACK_LINE(117)
				n2->z = vz;
				HX_STACK_LINE(117)
				n2;
			}
			HX_STACK_LINE(118)
			{
				HX_STACK_LINE(118)
				::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(118)
				Float vx = ((((_this->m00 * n3->x) + (_this->m01 * n3->y)) + (_this->m02 * n3->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
				HX_STACK_LINE(118)
				Float vy = ((((_this->m10 * n3->x) + (_this->m11 * n3->y)) + (_this->m12 * n3->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
				HX_STACK_LINE(118)
				Float vz = ((((_this->m20 * n3->x) + (_this->m21 * n3->y)) + (_this->m22 * n3->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
				HX_STACK_LINE(118)
				n3->x = vx;
				HX_STACK_LINE(118)
				n3->y = vy;
				HX_STACK_LINE(118)
				n3->z = vz;
				HX_STACK_LINE(118)
				n3;
			}
			HX_STACK_LINE(119)
			{
				HX_STACK_LINE(119)
				::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(119)
				Float vx = ((((_this->m00 * f0->x) + (_this->m01 * f0->y)) + (_this->m02 * f0->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
				HX_STACK_LINE(119)
				Float vy = ((((_this->m10 * f0->x) + (_this->m11 * f0->y)) + (_this->m12 * f0->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
				HX_STACK_LINE(119)
				Float vz = ((((_this->m20 * f0->x) + (_this->m21 * f0->y)) + (_this->m22 * f0->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
				HX_STACK_LINE(119)
				f0->x = vx;
				HX_STACK_LINE(119)
				f0->y = vy;
				HX_STACK_LINE(119)
				f0->z = vz;
				HX_STACK_LINE(119)
				f0;
			}
			HX_STACK_LINE(120)
			{
				HX_STACK_LINE(120)
				::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(120)
				Float vx = ((((_this->m00 * f1->x) + (_this->m01 * f1->y)) + (_this->m02 * f1->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
				HX_STACK_LINE(120)
				Float vy = ((((_this->m10 * f1->x) + (_this->m11 * f1->y)) + (_this->m12 * f1->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
				HX_STACK_LINE(120)
				Float vz = ((((_this->m20 * f1->x) + (_this->m21 * f1->y)) + (_this->m22 * f1->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
				HX_STACK_LINE(120)
				f1->x = vx;
				HX_STACK_LINE(120)
				f1->y = vy;
				HX_STACK_LINE(120)
				f1->z = vz;
				HX_STACK_LINE(120)
				f1;
			}
			HX_STACK_LINE(121)
			{
				HX_STACK_LINE(121)
				::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(121)
				Float vx = ((((_this->m00 * f2->x) + (_this->m01 * f2->y)) + (_this->m02 * f2->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
				HX_STACK_LINE(121)
				Float vy = ((((_this->m10 * f2->x) + (_this->m11 * f2->y)) + (_this->m12 * f2->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
				HX_STACK_LINE(121)
				Float vz = ((((_this->m20 * f2->x) + (_this->m21 * f2->y)) + (_this->m22 * f2->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
				HX_STACK_LINE(121)
				f2->x = vx;
				HX_STACK_LINE(121)
				f2->y = vy;
				HX_STACK_LINE(121)
				f2->z = vz;
				HX_STACK_LINE(121)
				f2;
			}
			HX_STACK_LINE(122)
			{
				HX_STACK_LINE(122)
				::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(122)
				Float vx = ((((_this->m00 * f3->x) + (_this->m01 * f3->y)) + (_this->m02 * f3->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
				HX_STACK_LINE(122)
				Float vy = ((((_this->m10 * f3->x) + (_this->m11 * f3->y)) + (_this->m12 * f3->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
				HX_STACK_LINE(122)
				Float vz = ((((_this->m20 * f3->x) + (_this->m21 * f3->y)) + (_this->m22 * f3->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
				HX_STACK_LINE(122)
				f3->x = vx;
				HX_STACK_LINE(122)
				f3->y = vy;
				HX_STACK_LINE(122)
				f3->z = vz;
				HX_STACK_LINE(122)
				f3;
			}
			struct _Function_2_9{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/CameraContext.hx",124,0x8aadd161)
					{
						HX_STACK_LINE(124)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(124)
						int _g8 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(124)
						return _this->m_v3->__get(_g8).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(124)
			::haxor::math::Vector3 pmin = (_Function_2_9::Block())->Set(n0->x,n0->y,n0->z);		HX_STACK_VAR(pmin,"pmin");
			struct _Function_2_10{
				inline static ::haxor::math::Vector3 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/CameraContext.hx",125,0x8aadd161)
					{
						HX_STACK_LINE(125)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(125)
						int _g9 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(125)
						return _this->m_v3->__get(_g9).StaticCast< ::haxor::math::Vector3 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(125)
			::haxor::math::Vector3 pmax = (_Function_2_10::Block())->Set(n0->x,n0->y,n0->z);		HX_STACK_VAR(pmax,"pmax");
			HX_STACK_LINE(126)
			::haxor::math::Vector3 p;		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(128)
			Float _g10;		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(128)
			{
				HX_STACK_LINE(128)
				Float b;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(128)
				{
					HX_STACK_LINE(128)
					Float b1 = ::Math_obj::min(n2->x,n3->x);		HX_STACK_VAR(b1,"b1");
					HX_STACK_LINE(128)
					b = ::Math_obj::min(n1->x,b1);
				}
				HX_STACK_LINE(128)
				_g10 = ::Math_obj::min(pmin->x,b);
			}
			HX_STACK_LINE(128)
			pmin->x = _g10;
			HX_STACK_LINE(129)
			Float _g11;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(129)
			{
				HX_STACK_LINE(129)
				Float b;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(129)
				{
					HX_STACK_LINE(129)
					Float b1 = ::Math_obj::min(n2->y,n3->y);		HX_STACK_VAR(b1,"b1");
					HX_STACK_LINE(129)
					b = ::Math_obj::min(n1->y,b1);
				}
				HX_STACK_LINE(129)
				_g11 = ::Math_obj::min(pmin->y,b);
			}
			HX_STACK_LINE(129)
			pmin->y = _g11;
			HX_STACK_LINE(130)
			Float _g12;		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(130)
			{
				HX_STACK_LINE(130)
				Float b;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(130)
				{
					HX_STACK_LINE(130)
					Float b1 = ::Math_obj::min(n2->z,n3->z);		HX_STACK_VAR(b1,"b1");
					HX_STACK_LINE(130)
					b = ::Math_obj::min(n1->z,b1);
				}
				HX_STACK_LINE(130)
				_g12 = ::Math_obj::min(pmin->z,b);
			}
			HX_STACK_LINE(130)
			pmin->z = _g12;
			HX_STACK_LINE(131)
			Float _g13;		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(131)
			{
				HX_STACK_LINE(131)
				Float b;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(131)
				{
					HX_STACK_LINE(131)
					Float b1 = ::Math_obj::max(n2->x,n3->x);		HX_STACK_VAR(b1,"b1");
					HX_STACK_LINE(131)
					b = ::Math_obj::max(n1->x,b1);
				}
				HX_STACK_LINE(131)
				_g13 = ::Math_obj::max(pmax->x,b);
			}
			HX_STACK_LINE(131)
			pmax->x = _g13;
			HX_STACK_LINE(132)
			Float _g14;		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(132)
			{
				HX_STACK_LINE(132)
				Float b;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(132)
				{
					HX_STACK_LINE(132)
					Float b1 = ::Math_obj::max(n2->y,n3->y);		HX_STACK_VAR(b1,"b1");
					HX_STACK_LINE(132)
					b = ::Math_obj::max(n1->y,b1);
				}
				HX_STACK_LINE(132)
				_g14 = ::Math_obj::max(pmax->y,b);
			}
			HX_STACK_LINE(132)
			pmax->y = _g14;
			HX_STACK_LINE(133)
			Float _g15;		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(133)
			{
				HX_STACK_LINE(133)
				Float b;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(133)
				{
					HX_STACK_LINE(133)
					Float b1 = ::Math_obj::max(n2->z,n3->z);		HX_STACK_VAR(b1,"b1");
					HX_STACK_LINE(133)
					b = ::Math_obj::max(n1->z,b1);
				}
				HX_STACK_LINE(133)
				_g15 = ::Math_obj::max(pmax->z,b);
			}
			HX_STACK_LINE(133)
			pmax->z = _g15;
			HX_STACK_LINE(135)
			Float _g16;		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(135)
			{
				HX_STACK_LINE(135)
				Float b;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(135)
				{
					HX_STACK_LINE(135)
					Float b1;		HX_STACK_VAR(b1,"b1");
					HX_STACK_LINE(135)
					{
						HX_STACK_LINE(135)
						Float b2 = ::Math_obj::min(f2->x,f3->x);		HX_STACK_VAR(b2,"b2");
						HX_STACK_LINE(135)
						b1 = ::Math_obj::min(f1->x,b2);
					}
					HX_STACK_LINE(135)
					b = ::Math_obj::min(f0->x,b1);
				}
				HX_STACK_LINE(135)
				_g16 = ::Math_obj::min(pmin->x,b);
			}
			HX_STACK_LINE(135)
			pmin->x = _g16;
			HX_STACK_LINE(136)
			Float _g17;		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(136)
			{
				HX_STACK_LINE(136)
				Float b;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(136)
				{
					HX_STACK_LINE(136)
					Float b1;		HX_STACK_VAR(b1,"b1");
					HX_STACK_LINE(136)
					{
						HX_STACK_LINE(136)
						Float b2 = ::Math_obj::min(f2->y,f3->y);		HX_STACK_VAR(b2,"b2");
						HX_STACK_LINE(136)
						b1 = ::Math_obj::min(f1->y,b2);
					}
					HX_STACK_LINE(136)
					b = ::Math_obj::min(f0->y,b1);
				}
				HX_STACK_LINE(136)
				_g17 = ::Math_obj::min(pmin->y,b);
			}
			HX_STACK_LINE(136)
			pmin->y = _g17;
			HX_STACK_LINE(137)
			Float _g18;		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(137)
			{
				HX_STACK_LINE(137)
				Float b;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(137)
				{
					HX_STACK_LINE(137)
					Float b1;		HX_STACK_VAR(b1,"b1");
					HX_STACK_LINE(137)
					{
						HX_STACK_LINE(137)
						Float b2 = ::Math_obj::min(f2->z,f3->z);		HX_STACK_VAR(b2,"b2");
						HX_STACK_LINE(137)
						b1 = ::Math_obj::min(f1->z,b2);
					}
					HX_STACK_LINE(137)
					b = ::Math_obj::min(f0->z,b1);
				}
				HX_STACK_LINE(137)
				_g18 = ::Math_obj::min(pmin->z,b);
			}
			HX_STACK_LINE(137)
			pmin->z = _g18;
			HX_STACK_LINE(138)
			Float _g19;		HX_STACK_VAR(_g19,"_g19");
			HX_STACK_LINE(138)
			{
				HX_STACK_LINE(138)
				Float b;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(138)
				{
					HX_STACK_LINE(138)
					Float b1;		HX_STACK_VAR(b1,"b1");
					HX_STACK_LINE(138)
					{
						HX_STACK_LINE(138)
						Float b2 = ::Math_obj::min(f2->x,f3->x);		HX_STACK_VAR(b2,"b2");
						HX_STACK_LINE(138)
						b1 = ::Math_obj::max(f1->x,b2);
					}
					HX_STACK_LINE(138)
					b = ::Math_obj::max(f0->x,b1);
				}
				HX_STACK_LINE(138)
				_g19 = ::Math_obj::max(pmax->x,b);
			}
			HX_STACK_LINE(138)
			pmax->x = _g19;
			HX_STACK_LINE(139)
			Float _g20;		HX_STACK_VAR(_g20,"_g20");
			HX_STACK_LINE(139)
			{
				HX_STACK_LINE(139)
				Float b;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(139)
				{
					HX_STACK_LINE(139)
					Float b1;		HX_STACK_VAR(b1,"b1");
					HX_STACK_LINE(139)
					{
						HX_STACK_LINE(139)
						Float b2 = ::Math_obj::min(f2->y,f3->y);		HX_STACK_VAR(b2,"b2");
						HX_STACK_LINE(139)
						b1 = ::Math_obj::max(f1->y,b2);
					}
					HX_STACK_LINE(139)
					b = ::Math_obj::max(f0->y,b1);
				}
				HX_STACK_LINE(139)
				_g20 = ::Math_obj::max(pmax->y,b);
			}
			HX_STACK_LINE(139)
			pmax->y = _g20;
			HX_STACK_LINE(140)
			Float _g21;		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(140)
			{
				HX_STACK_LINE(140)
				Float b;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(140)
				{
					HX_STACK_LINE(140)
					Float b1;		HX_STACK_VAR(b1,"b1");
					HX_STACK_LINE(140)
					{
						HX_STACK_LINE(140)
						Float b2 = ::Math_obj::min(f2->z,f3->z);		HX_STACK_VAR(b2,"b2");
						HX_STACK_LINE(140)
						b1 = ::Math_obj::max(f1->z,b2);
					}
					HX_STACK_LINE(140)
					b = ::Math_obj::max(f0->z,b1);
				}
				HX_STACK_LINE(140)
				_g21 = ::Math_obj::max(pmax->z,b);
			}
			HX_STACK_LINE(140)
			pmax->z = _g21;
			HX_STACK_LINE(143)
			Float dx = (((pmax->x - pmin->x)) * 0.005);		HX_STACK_VAR(dx,"dx");
			HX_STACK_LINE(144)
			Float dy = (((pmax->y - pmin->y)) * 0.005);		HX_STACK_VAR(dy,"dy");
			HX_STACK_LINE(145)
			Float dz = (((pmax->z - pmin->z)) * 0.005);		HX_STACK_VAR(dz,"dz");
			HX_STACK_LINE(147)
			hx::SubEq(pmin->x,dx);
			HX_STACK_LINE(147)
			hx::AddEq(pmax->x,dx);
			HX_STACK_LINE(148)
			hx::SubEq(pmin->y,dy);
			HX_STACK_LINE(148)
			hx::AddEq(pmax->y,dy);
			HX_STACK_LINE(149)
			hx::SubEq(pmin->z,dz);
			HX_STACK_LINE(149)
			hx::AddEq(pmax->z,dz);
			HX_STACK_LINE(154)
			::haxor::context::EngineContext_obj::renderer->UpdateSAP(c->__fcid,c,pmin,pmax);
		}
		HX_STACK_LINE(157)
		::haxor::context::EngineContext_obj::texture->BindTarget(target);
		HX_STACK_LINE(158)
		::haxor::context::EngineContext_obj::renderer->UpdateDisplayList(c);
		HX_STACK_LINE(159)
		::haxor::graphics::Graphics_obj::Clear(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,Bind,(void))

Void CameraContext_obj::Resize( ){
{
		HX_STACK_FRAME("haxor.context.CameraContext","Resize",0x0c528ae3,"haxor.context.CameraContext.Resize","haxor/context/CameraContext.hx",167,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_LINE(167)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(167)
		int _g = this->list->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(167)
		while((true)){
			HX_STACK_LINE(167)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(167)
				break;
			}
			HX_STACK_LINE(167)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(167)
			this->UpdateViewport(this->list->__get(i).StaticCast< ::haxor::component::Camera >());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CameraContext_obj,Resize,(void))

Void CameraContext_obj::ClearTargets( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","ClearTargets",0x3bcbb424,"haxor.context.CameraContext.ClearTargets","haxor/context/CameraContext.hx",175,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(176)
		::haxor::graphics::texture::RenderTexture rt;		HX_STACK_VAR(rt,"rt");
		HX_STACK_LINE(177)
		rt = this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
		HX_STACK_LINE(177)
		if (((rt != null()))){
			HX_STACK_LINE(177)
			::haxor::core::Resource_obj::Destroy(rt);
		}
		HX_STACK_LINE(178)
		rt = this->back->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
		HX_STACK_LINE(178)
		if (((rt != null()))){
			HX_STACK_LINE(178)
			::haxor::core::Resource_obj::Destroy(rt);
		}
		HX_STACK_LINE(179)
		this->front[c->__cid] = null();
		HX_STACK_LINE(180)
		this->back[c->__cid] = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,ClearTargets,(void))

Void CameraContext_obj::Unbind( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","Unbind",0x62c32d85,"haxor.context.CameraContext.Unbind","haxor/context/CameraContext.hx",190,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(190)
		this->SwapTargets(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,Unbind,(void))

Void CameraContext_obj::SwapTargets( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","SwapTargets",0xf131c660,"haxor.context.CameraContext.SwapTargets","haxor/context/CameraContext.hx",198,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(199)
		::haxor::graphics::texture::RenderTexture tmp;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(200)
		tmp = this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
		HX_STACK_LINE(201)
		this->front[c->__cid] = this->back->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
		HX_STACK_LINE(202)
		this->back[c->__cid] = tmp;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,SwapTargets,(void))

Void CameraContext_obj::UpdateViewport( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","UpdateViewport",0x37b7777e,"haxor.context.CameraContext.UpdateViewport","haxor/context/CameraContext.hx",210,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(211)
		bool need_buffer = false;		HX_STACK_VAR(need_buffer,"need_buffer");
		HX_STACK_LINE(212)
		if (((c->m_quality < 1.0))){
			HX_STACK_LINE(212)
			need_buffer = true;
		}
		else{
			HX_STACK_LINE(214)
			if (((c->get_filters()->__Field(HX_CSTRING("length"),true) > (int)0))){
				HX_STACK_LINE(214)
				need_buffer = true;
			}
		}
		HX_STACK_LINE(216)
		Float w = ::haxor::graphics::Screen_obj::m_width;		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(217)
		Float h = ::haxor::graphics::Screen_obj::m_height;		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(219)
		if (((c->m_target != null()))){
			HX_STACK_LINE(221)
			w = c->m_target->m_width;
			HX_STACK_LINE(222)
			h = c->m_target->m_height;
		}
		HX_STACK_LINE(225)
		c->m_aspect = (Float(w) / Float(h));
		HX_STACK_LINE(227)
		Float sw = (w * c->m_quality);		HX_STACK_VAR(sw,"sw");
		HX_STACK_LINE(228)
		Float sh = (h * c->m_quality);		HX_STACK_VAR(sh,"sh");
		HX_STACK_LINE(229)
		if (((sw < 1.0))){
			HX_STACK_LINE(229)
			w = 1.0;
		}
		else{
			HX_STACK_LINE(229)
			w = sw;
		}
		HX_STACK_LINE(230)
		if (((sh < 1.0))){
			HX_STACK_LINE(230)
			h = 1.0;
		}
		else{
			HX_STACK_LINE(230)
			h = sh;
		}
		HX_STACK_LINE(232)
		Float _g = c->m_viewport->get_xMin();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(232)
		Float _g1 = (_g * w);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(232)
		Float vx = ::Std_obj::_int(_g1);		HX_STACK_VAR(vx,"vx");
		HX_STACK_LINE(233)
		Float _g2 = c->m_viewport->get_yMin();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(233)
		Float _g3 = (_g2 * h);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(233)
		Float vy = ::Std_obj::_int(_g3);		HX_STACK_VAR(vy,"vy");
		HX_STACK_LINE(234)
		Float _g6;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(234)
		{
			HX_STACK_LINE(234)
			::haxor::math::AABB2 _this = c->m_viewport;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(234)
			{
				HX_STACK_LINE(234)
				Float _g4 = _this->get_xMax();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(234)
				Float _g5 = _this->get_xMin();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(234)
				Float p_a = (_g4 - _g5);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(234)
				if (((p_a < (int)0))){
					HX_STACK_LINE(234)
					_g6 = -(p_a);
				}
				else{
					HX_STACK_LINE(234)
					_g6 = p_a;
				}
			}
		}
		HX_STACK_LINE(234)
		Float aw = (_g6 * w);		HX_STACK_VAR(aw,"aw");
		HX_STACK_LINE(235)
		Float _g9;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(235)
		{
			HX_STACK_LINE(235)
			::haxor::math::AABB2 _this = c->m_viewport;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(235)
			{
				HX_STACK_LINE(235)
				Float _g7 = _this->get_yMax();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(235)
				Float _g8 = _this->get_yMin();		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(235)
				Float p_a = (_g7 - _g8);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(235)
				if (((p_a < (int)0))){
					HX_STACK_LINE(235)
					_g9 = -(p_a);
				}
				else{
					HX_STACK_LINE(235)
					_g9 = p_a;
				}
			}
		}
		HX_STACK_LINE(235)
		Float ah = (_g9 * h);		HX_STACK_VAR(ah,"ah");
		HX_STACK_LINE(237)
		{
			HX_STACK_LINE(237)
			c->m_pixelViewport->set_xMin(vx);
			HX_STACK_LINE(237)
			vx;
		}
		HX_STACK_LINE(238)
		{
			HX_STACK_LINE(238)
			Float v = ((h - ah) - vy);		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(238)
			c->m_pixelViewport->set_yMin(v);
			HX_STACK_LINE(238)
			v;
		}
		HX_STACK_LINE(239)
		{
			HX_STACK_LINE(239)
			::haxor::math::AABB2 _this = c->m_pixelViewport;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(239)
			Float _g10 = _this->get_xMin();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(239)
			Float _g11 = (_g10 + aw);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(239)
			_this->set_xMax(_g11);
			HX_STACK_LINE(239)
			aw;
		}
		HX_STACK_LINE(240)
		{
			HX_STACK_LINE(240)
			::haxor::math::AABB2 _this = c->m_pixelViewport;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(240)
			Float _g12 = _this->get_yMin();		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(240)
			Float _g13 = (_g12 + ah);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(240)
			_this->set_yMax(_g13);
			HX_STACK_LINE(240)
			ah;
		}
		HX_STACK_LINE(242)
		int tw = aw;		HX_STACK_VAR(tw,"tw");
		HX_STACK_LINE(243)
		int th = ah;		HX_STACK_VAR(th,"th");
		HX_STACK_LINE(245)
		::haxor::graphics::texture::RenderTexture grt;		HX_STACK_VAR(grt,"grt");
		HX_STACK_LINE(247)
		grt = this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
		HX_STACK_LINE(249)
		if (((grt != null()))){
			HX_STACK_LINE(251)
			if (((tw != grt->m_width))){
				HX_STACK_LINE(251)
				this->ClearTargets(c);
			}
			else{
				HX_STACK_LINE(253)
				if (((th != grt->m_height))){
					HX_STACK_LINE(253)
					this->ClearTargets(c);
				}
			}
		}
		HX_STACK_LINE(256)
		grt = this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
		HX_STACK_LINE(258)
		if (((grt == null()))){
			HX_STACK_LINE(260)
			if ((need_buffer)){
				HX_STACK_LINE(263)
				::haxor::core::PixelFormat tf;		HX_STACK_VAR(tf,"tf");
				HX_STACK_LINE(263)
				if (((c->m_target == null()))){
					HX_STACK_LINE(263)
					tf = ::haxor::core::PixelFormat_obj::RGB8;
				}
				else{
					HX_STACK_LINE(263)
					tf = c->m_target->m_format;
				}
				HX_STACK_LINE(264)
				this->front[c->__cid] = ::haxor::graphics::texture::RenderTexture_obj::__new(aw,ah,tf,c->m_captureDepth);
				HX_STACK_LINE(265)
				if (((c->get_filters()->__Field(HX_CSTRING("length"),true) <= (int)0))){
					HX_STACK_LINE(265)
					this->back[c->__cid] = this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
				}
				else{
					HX_STACK_LINE(265)
					this->back[c->__cid] = ::haxor::graphics::texture::RenderTexture_obj::__new(aw,ah,tf,c->m_captureDepth);
				}
				HX_STACK_LINE(267)
				::String _g14 = this->back->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >()->set_name(HX_CSTRING("CameraScreenBuffer"));		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(266)
				this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >()->set_name(_g14);
			}
		}
		HX_STACK_LINE(271)
		c->m_projection_dirty = true;
		HX_STACK_LINE(272)
		c->m_proj_uniform_dirty = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,UpdateViewport,(void))

Void CameraContext_obj::SortCameraList( ){
{
		HX_STACK_FRAME("haxor.context.CameraContext","SortCameraList",0x68c4ca90,"haxor.context.CameraContext.SortCameraList","haxor/context/CameraContext.hx",280,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_LINE(280)
		if (((this->list->length > (int)1))){

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_2_1)
			int run(::haxor::component::Camera a,::haxor::component::Camera b){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","haxor/context/CameraContext.hx",281,0x8aadd161)
				HX_STACK_ARG(a,"a")
				HX_STACK_ARG(b,"b")
				{
					HX_STACK_LINE(281)
					if (((a->get_order() == b->get_order()))){
						HX_STACK_LINE(281)
						if (((a->m_entity->get_name() < b->m_entity->get_name()))){
							HX_STACK_LINE(281)
							return (int)-1;
						}
						else{
							HX_STACK_LINE(281)
							return (int)1;
						}
					}
					else{
						HX_STACK_LINE(281)
						if (((a->get_order() < b->get_order()))){
							HX_STACK_LINE(281)
							return (int)-1;
						}
						else{
							HX_STACK_LINE(281)
							return (int)1;
						}
					}
					HX_STACK_LINE(281)
					return (int)0;
				}
				return null();
			}
			HX_END_LOCAL_FUNC2(return)

			HX_STACK_LINE(281)
			this->list->sort( Dynamic(new _Function_2_1()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CameraContext_obj,SortCameraList,(void))


CameraContext_obj::CameraContext_obj()
{
}

void CameraContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CameraContext);
	HX_MARK_MEMBER_NAME(cid,"cid");
	HX_MARK_MEMBER_NAME(list,"list");
	HX_MARK_MEMBER_NAME(front,"front");
	HX_MARK_MEMBER_NAME(back,"back");
	HX_MARK_END_CLASS();
}

void CameraContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(cid,"cid");
	HX_VISIT_MEMBER_NAME(list,"list");
	HX_VISIT_MEMBER_NAME(front,"front");
	HX_VISIT_MEMBER_NAME(back,"back");
}

Dynamic CameraContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"cid") ) { return cid; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return list; }
		if (HX_FIELD_EQ(inName,"back") ) { return back; }
		if (HX_FIELD_EQ(inName,"Bind") ) { return Bind_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"front") ) { return front; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Create") ) { return Create_dyn(); }
		if (HX_FIELD_EQ(inName,"Resize") ) { return Resize_dyn(); }
		if (HX_FIELD_EQ(inName,"Unbind") ) { return Unbind_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Destroy") ) { return Destroy_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SwapTargets") ) { return SwapTargets_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ClearTargets") ) { return ClearTargets_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"UpdateViewport") ) { return UpdateViewport_dyn(); }
		if (HX_FIELD_EQ(inName,"SortCameraList") ) { return SortCameraList_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CameraContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"cid") ) { cid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"back") ) { back=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"front") ) { front=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CameraContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("cid"));
	outFields->push(HX_CSTRING("list"));
	outFields->push(HX_CSTRING("front"));
	outFields->push(HX_CSTRING("back"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(CameraContext_obj,cid),HX_CSTRING("cid")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(CameraContext_obj,list),HX_CSTRING("list")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(CameraContext_obj,front),HX_CSTRING("front")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(CameraContext_obj,back),HX_CSTRING("back")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("cid"),
	HX_CSTRING("list"),
	HX_CSTRING("front"),
	HX_CSTRING("back"),
	HX_CSTRING("Create"),
	HX_CSTRING("Destroy"),
	HX_CSTRING("Bind"),
	HX_CSTRING("Resize"),
	HX_CSTRING("ClearTargets"),
	HX_CSTRING("Unbind"),
	HX_CSTRING("SwapTargets"),
	HX_CSTRING("UpdateViewport"),
	HX_CSTRING("SortCameraList"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CameraContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CameraContext_obj::__mClass,"__mClass");
};

#endif

Class CameraContext_obj::__mClass;

void CameraContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.CameraContext"), hx::TCanCast< CameraContext_obj> ,sStaticFields,sMemberFields,
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

void CameraContext_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
