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
#ifndef INCLUDED_haxor_context_BaseProcess
#include <haxor/context/BaseProcess.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_Process
#include <haxor/context/Process.h>
#endif
#ifndef INCLUDED_haxor_context_RendererContext
#include <haxor/context/RendererContext.h>
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
#ifndef INCLUDED_haxor_core_IResizeable
#include <haxor/core/IResizeable.h>
#endif
#ifndef INCLUDED_haxor_core_PixelFormat
#include <haxor/core/PixelFormat.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_ds_SAP
#include <haxor/ds/SAP.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#include <haxor/graphics/mesh/Mesh.h>
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
namespace context{

Void RendererContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.RendererContext","new",0x3d8f3d93,"haxor.context.RendererContext.new","haxor/context/RendererContext.hx",75,0xd2e9a6bf)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(76)
	::haxor::context::UID _g = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(76)
	this->rid = _g;
	HX_STACK_LINE(78)
	::haxor::context::UID _g1 = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(78)
	this->fcid = _g1;
	HX_STACK_LINE(79)
	::haxor::ds::SAP _g2 = ::haxor::ds::SAP_obj::__new(0.01,false);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(79)
	this->sap = _g2;
	HX_STACK_LINE(81)
	this->sap_dirty = false;
	HX_STACK_LINE(83)
	this->deferred_culling = (int)0;
	HX_STACK_LINE(84)
	this->deferred_offset = (int)100;
	HX_STACK_LINE(86)
	this->display = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(87)
	this->sort = Array_obj< bool >::__new();
	HX_STACK_LINE(88)
	{
		HX_STACK_LINE(88)
		int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(88)
		while((true)){
			HX_STACK_LINE(88)
			if ((!(((_g3 < (int)32))))){
				HX_STACK_LINE(88)
				break;
			}
			HX_STACK_LINE(88)
			int i = (_g3)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(90)
			::haxor::context::Process p = ::haxor::context::Process_obj::__new(HX_CSTRING("process.renderers"),::haxor::context::EngineContext_obj::maxNodes,(i == (int)31));		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(91)
			this->display->push(p);
			HX_STACK_LINE(92)
			this->sort->push(false);
		}
	}
}
;
	return null();
}

//RendererContext_obj::~RendererContext_obj() { }

Dynamic RendererContext_obj::__CreateEmpty() { return  new RendererContext_obj; }
hx::ObjectPtr< RendererContext_obj > RendererContext_obj::__new()
{  hx::ObjectPtr< RendererContext_obj > result = new RendererContext_obj();
	result->__construct();
	return result;}

Dynamic RendererContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RendererContext_obj > result = new RendererContext_obj();
	result->__construct();
	return result;}

Void RendererContext_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.context.RendererContext","Initialize",0x7335249d,"haxor.context.RendererContext.Initialize","haxor/context/RendererContext.hx",100,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_LINE(102)
		::haxor::graphics::texture::ComputeTexture _g = ::haxor::graphics::texture::ComputeTexture_obj::__new((int)512,(int)512,::haxor::core::PixelFormat_obj::Float4);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(102)
		this->skinning = _g;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(RendererContext_obj,Initialize,(void))

Void RendererContext_obj::Create( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.context.RendererContext","Create",0x58406fc9,"haxor.context.RendererContext.Create","haxor/context/RendererContext.hx",110,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(111)
		int _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(111)
		{
			HX_STACK_LINE(111)
			::haxor::context::UID _this = this->rid;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(111)
			if (((_this->m_cache->length <= (int)0))){
				HX_STACK_LINE(111)
				_g = (_this->m_id)++;
			}
			else{
				HX_STACK_LINE(111)
				_g = _this->m_cache->shift();
			}
		}
		HX_STACK_LINE(111)
		r->__cid = _g;
		HX_STACK_LINE(112)
		if ((r->m_has_mesh)){
			HX_STACK_LINE(114)
			::haxor::component::MeshRenderer mr = r;		HX_STACK_VAR(mr,"mr");
			HX_STACK_LINE(115)
			int _g1;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(115)
			{
				HX_STACK_LINE(115)
				::haxor::context::UID _this = this->fcid;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(115)
				if (((_this->m_cache->length <= (int)0))){
					HX_STACK_LINE(115)
					_g1 = (_this->m_id)++;
				}
				else{
					HX_STACK_LINE(115)
					_g1 = _this->m_cache->shift();
				}
			}
			HX_STACK_LINE(115)
			mr->__fcid = _g1;
			HX_STACK_LINE(116)
			this->sap->Create(mr->__fcid);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,Create,(void))

Void RendererContext_obj::AddCamera( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.RendererContext","AddCamera",0x595530f9,"haxor.context.RendererContext.AddCamera","haxor/context/RendererContext.hx",125,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(126)
		int _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(126)
		{
			HX_STACK_LINE(126)
			::haxor::context::UID _this = this->fcid;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(126)
			if (((_this->m_cache->length <= (int)0))){
				HX_STACK_LINE(126)
				_g = (_this->m_id)++;
			}
			else{
				HX_STACK_LINE(126)
				_g = _this->m_cache->shift();
			}
		}
		HX_STACK_LINE(126)
		c->__fcid = _g;
		HX_STACK_LINE(127)
		this->sap->Create(c->__fcid);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,AddCamera,(void))

Void RendererContext_obj::RemoveCamera( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.RendererContext","RemoveCamera",0xb6110296,"haxor.context.RendererContext.RemoveCamera","haxor/context/RendererContext.hx",135,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(136)
		{
			HX_STACK_LINE(136)
			int v = c->__fcid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(136)
			this->fcid->m_cache->push(v);
			HX_STACK_LINE(136)
			v;
		}
		HX_STACK_LINE(137)
		this->sap->Remove(c->__fcid);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,RemoveCamera,(void))

Void RendererContext_obj::OnMaterialChange( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.context.RendererContext","OnMaterialChange",0xd2d6d203,"haxor.context.RendererContext.OnMaterialChange","haxor/context/RendererContext.hx",145,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(146)
		int l = r->m_entity->m_layer;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(147)
		this->sort[l] = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,OnMaterialChange,(void))

Void RendererContext_obj::OnMeshChange( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.context.RendererContext","OnMeshChange",0x02f6c1c9,"haxor.context.RendererContext.OnMeshChange","haxor/context/RendererContext.hx",155,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(156)
		int l = r->m_entity->m_layer;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(157)
		this->sort[l] = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,OnMeshChange,(void))

Void RendererContext_obj::OnVisibilityChange( ::haxor::component::Renderer r,bool f){
{
		HX_STACK_FRAME("haxor.context.RendererContext","OnVisibilityChange",0x3d85106e,"haxor.context.RendererContext.OnVisibilityChange","haxor/context/RendererContext.hx",166,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_ARG(f,"f")
		HX_STACK_LINE(167)
		Array< ::Dynamic > cl = r->m_entity->m_components;		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(168)
		{
			HX_STACK_LINE(168)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(168)
			int _g = cl->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(168)
			while((true)){
				HX_STACK_LINE(168)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(168)
					break;
				}
				HX_STACK_LINE(168)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(168)
				cl->__get(i).StaticCast< ::haxor::component::Component >()->OnVisibilityChange(f);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(RendererContext_obj,OnVisibilityChange,(void))

bool RendererContext_obj::DeferredCulling( ::haxor::component::Renderer r){
	HX_STACK_FRAME("haxor.context.RendererContext","DeferredCulling",0x56f5b2a4,"haxor.context.RendererContext.DeferredCulling","haxor/context/RendererContext.hx",177,0xd2e9a6bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(r,"r")
	HX_STACK_LINE(179)
	return false;
	HX_STACK_LINE(180)
	if ((!(((bool(r->m_visible) && bool(!(r->m_culled))))))){
		HX_STACK_LINE(180)
		return false;
	}
	HX_STACK_LINE(181)
	int c_id = ::haxor::context::EngineContext_obj::renderer->deferred_culling;		HX_STACK_VAR(c_id,"c_id");
	HX_STACK_LINE(182)
	int c_off = this->deferred_offset;		HX_STACK_VAR(c_off,"c_off");
	HX_STACK_LINE(183)
	int _g = this->rid->get_next();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(183)
	int _g1 = hx::Mod(((this->deferred_culling + this->deferred_offset)),_g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(183)
	this->deferred_culling = _g1;
	struct _Function_1_1{
		inline static int Block( ::haxor::component::Renderer &r,int &c_id){
			HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/RendererContext.hx",184,0xd2e9a6bf)
			{
				HX_STACK_LINE(184)
				int p_a = (c_id - r->__cid);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(184)
				return (  (((p_a < (int)0))) ? int(-(p_a)) : int(p_a) );
			}
			return null();
		}
	};
	HX_STACK_LINE(184)
	if (((_Function_1_1::Block(r,c_id) > c_off))){
		HX_STACK_LINE(184)
		return true;
	}
	HX_STACK_LINE(185)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,DeferredCulling,return )

Void RendererContext_obj::OnLayerChange( ::haxor::component::Renderer r,int from,int to){
{
		HX_STACK_FRAME("haxor.context.RendererContext","OnLayerChange",0x2f73b215,"haxor.context.RendererContext.OnLayerChange","haxor/context/RendererContext.hx",195,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_ARG(from,"from")
		HX_STACK_ARG(to,"to")
		HX_STACK_LINE(196)
		this->sort[from] = true;
		HX_STACK_LINE(197)
		this->display->__get(from).StaticCast< ::haxor::context::Process >()->Remove(r);
		HX_STACK_LINE(198)
		if ((r->get_enabled())){
			HX_STACK_LINE(200)
			this->display->__get(to).StaticCast< ::haxor::context::Process >()->Add(r);
			HX_STACK_LINE(201)
			this->sort[to] = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(RendererContext_obj,OnLayerChange,(void))

Void RendererContext_obj::UpdateDisplayList( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.RendererContext","UpdateDisplayList",0xd536288a,"haxor.context.RendererContext.UpdateDisplayList","haxor/context/RendererContext.hx",209,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(210)
		Array< int > ll = c->m_layers;		HX_STACK_VAR(ll,"ll");
		HX_STACK_LINE(211)
		{
			HX_STACK_LINE(211)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(211)
			int _g = ll->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(211)
			while((true)){
				HX_STACK_LINE(211)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(211)
					break;
				}
				HX_STACK_LINE(211)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(213)
				int l = ll->__get(i);		HX_STACK_VAR(l,"l");
				HX_STACK_LINE(214)
				::haxor::context::Process rl = this->display->__get(l).StaticCast< ::haxor::context::Process >();		HX_STACK_VAR(rl,"rl");
				HX_STACK_LINE(215)
				bool need_sort = this->sort->__get(l);		HX_STACK_VAR(need_sort,"need_sort");
				HX_STACK_LINE(216)
				if ((need_sort)){
					HX_STACK_LINE(218)
					this->sort[l] = false;
					HX_STACK_LINE(219)
					if (((rl->m_length > (int)1))){
						HX_STACK_LINE(221)
						rl->Sort(this->DisplayListSort_dyn());
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,UpdateDisplayList,(void))

Void RendererContext_obj::Enable( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.context.RendererContext","Enable",0xd4b8b750,"haxor.context.RendererContext.Enable","haxor/context/RendererContext.hx",232,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(233)
		this->display->__get(r->m_entity->m_layer).StaticCast< ::haxor::context::Process >()->Add(r);
		HX_STACK_LINE(234)
		this->sort[r->m_entity->m_layer] = true;
		HX_STACK_LINE(235)
		if ((r->m_has_mesh)){
			HX_STACK_LINE(237)
			::haxor::component::MeshRenderer mr = r;		HX_STACK_VAR(mr,"mr");
			HX_STACK_LINE(238)
			mr->m_culling_dirty = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,Enable,(void))

Void RendererContext_obj::Disable( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.context.RendererContext","Disable",0x800f147b,"haxor.context.RendererContext.Disable","haxor/context/RendererContext.hx",247,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(248)
		this->display->__get(r->m_entity->m_layer).StaticCast< ::haxor::context::Process >()->Remove(r);
		HX_STACK_LINE(249)
		this->sort[r->m_entity->m_layer] = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,Disable,(void))

Void RendererContext_obj::UpdateCameraSAP( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.RendererContext","UpdateCameraSAP",0x6ecda8c7,"haxor.context.RendererContext.UpdateCameraSAP","haxor/context/RendererContext.hx",257,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(258)
		bool need_sap = (bool((bool(this->sap_dirty) || bool(c->m_view_uniform_dirty))) || bool(c->m_proj_uniform_dirty));		HX_STACK_VAR(need_sap,"need_sap");
		HX_STACK_LINE(259)
		if ((!(need_sap))){
			HX_STACK_LINE(259)
			return null();
		}
		struct _Function_1_1{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/RendererContext.hx",260,0xd2e9a6bf)
				{
					HX_STACK_LINE(260)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(260)
					int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(260)
					return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(260)
		::haxor::math::Vector3 n0 = (_Function_1_1::Block())->Set4(c->m_frustum->__get((int)0).StaticCast< ::haxor::math::Vector4 >());		HX_STACK_VAR(n0,"n0");
		struct _Function_1_2{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/RendererContext.hx",261,0xd2e9a6bf)
				{
					HX_STACK_LINE(261)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(261)
					int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(261)
					return _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(261)
		::haxor::math::Vector3 n1 = (_Function_1_2::Block())->Set4(c->m_frustum->__get((int)1).StaticCast< ::haxor::math::Vector4 >());		HX_STACK_VAR(n1,"n1");
		struct _Function_1_3{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/RendererContext.hx",262,0xd2e9a6bf)
				{
					HX_STACK_LINE(262)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(262)
					int _g2 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(262)
					return _this->m_v3->__get(_g2).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(262)
		::haxor::math::Vector3 n2 = (_Function_1_3::Block())->Set4(c->m_frustum->__get((int)2).StaticCast< ::haxor::math::Vector4 >());		HX_STACK_VAR(n2,"n2");
		struct _Function_1_4{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/RendererContext.hx",263,0xd2e9a6bf)
				{
					HX_STACK_LINE(263)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(263)
					int _g3 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(263)
					return _this->m_v3->__get(_g3).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(263)
		::haxor::math::Vector3 n3 = (_Function_1_4::Block())->Set4(c->m_frustum->__get((int)3).StaticCast< ::haxor::math::Vector4 >());		HX_STACK_VAR(n3,"n3");
		struct _Function_1_5{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/RendererContext.hx",264,0xd2e9a6bf)
				{
					HX_STACK_LINE(264)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(264)
					int _g4 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(264)
					return _this->m_v3->__get(_g4).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(264)
		::haxor::math::Vector3 f0 = (_Function_1_5::Block())->Set4(c->m_frustum->__get((int)4).StaticCast< ::haxor::math::Vector4 >());		HX_STACK_VAR(f0,"f0");
		struct _Function_1_6{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/RendererContext.hx",265,0xd2e9a6bf)
				{
					HX_STACK_LINE(265)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(265)
					int _g5 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(265)
					return _this->m_v3->__get(_g5).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(265)
		::haxor::math::Vector3 f1 = (_Function_1_6::Block())->Set4(c->m_frustum->__get((int)5).StaticCast< ::haxor::math::Vector4 >());		HX_STACK_VAR(f1,"f1");
		struct _Function_1_7{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/RendererContext.hx",266,0xd2e9a6bf)
				{
					HX_STACK_LINE(266)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(266)
					int _g6 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(266)
					return _this->m_v3->__get(_g6).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(266)
		::haxor::math::Vector3 f2 = (_Function_1_7::Block())->Set4(c->m_frustum->__get((int)6).StaticCast< ::haxor::math::Vector4 >());		HX_STACK_VAR(f2,"f2");
		struct _Function_1_8{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/RendererContext.hx",267,0xd2e9a6bf)
				{
					HX_STACK_LINE(267)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(267)
					int _g7 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(267)
					return _this->m_v3->__get(_g7).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(267)
		::haxor::math::Vector3 f3 = (_Function_1_8::Block())->Set4(c->m_frustum->__get((int)7).StaticCast< ::haxor::math::Vector4 >());		HX_STACK_VAR(f3,"f3");
		HX_STACK_LINE(269)
		{
			HX_STACK_LINE(269)
			::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(269)
			Float vx = ((((_this->m00 * n0->x) + (_this->m01 * n0->y)) + (_this->m02 * n0->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(269)
			Float vy = ((((_this->m10 * n0->x) + (_this->m11 * n0->y)) + (_this->m12 * n0->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(269)
			Float vz = ((((_this->m20 * n0->x) + (_this->m21 * n0->y)) + (_this->m22 * n0->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(269)
			n0->x = vx;
			HX_STACK_LINE(269)
			n0->y = vy;
			HX_STACK_LINE(269)
			n0->z = vz;
			HX_STACK_LINE(269)
			n0;
		}
		HX_STACK_LINE(270)
		{
			HX_STACK_LINE(270)
			::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(270)
			Float vx = ((((_this->m00 * n1->x) + (_this->m01 * n1->y)) + (_this->m02 * n1->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(270)
			Float vy = ((((_this->m10 * n1->x) + (_this->m11 * n1->y)) + (_this->m12 * n1->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(270)
			Float vz = ((((_this->m20 * n1->x) + (_this->m21 * n1->y)) + (_this->m22 * n1->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(270)
			n1->x = vx;
			HX_STACK_LINE(270)
			n1->y = vy;
			HX_STACK_LINE(270)
			n1->z = vz;
			HX_STACK_LINE(270)
			n1;
		}
		HX_STACK_LINE(271)
		{
			HX_STACK_LINE(271)
			::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(271)
			Float vx = ((((_this->m00 * n2->x) + (_this->m01 * n2->y)) + (_this->m02 * n2->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(271)
			Float vy = ((((_this->m10 * n2->x) + (_this->m11 * n2->y)) + (_this->m12 * n2->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(271)
			Float vz = ((((_this->m20 * n2->x) + (_this->m21 * n2->y)) + (_this->m22 * n2->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(271)
			n2->x = vx;
			HX_STACK_LINE(271)
			n2->y = vy;
			HX_STACK_LINE(271)
			n2->z = vz;
			HX_STACK_LINE(271)
			n2;
		}
		HX_STACK_LINE(272)
		{
			HX_STACK_LINE(272)
			::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(272)
			Float vx = ((((_this->m00 * n3->x) + (_this->m01 * n3->y)) + (_this->m02 * n3->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(272)
			Float vy = ((((_this->m10 * n3->x) + (_this->m11 * n3->y)) + (_this->m12 * n3->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(272)
			Float vz = ((((_this->m20 * n3->x) + (_this->m21 * n3->y)) + (_this->m22 * n3->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(272)
			n3->x = vx;
			HX_STACK_LINE(272)
			n3->y = vy;
			HX_STACK_LINE(272)
			n3->z = vz;
			HX_STACK_LINE(272)
			n3;
		}
		HX_STACK_LINE(273)
		{
			HX_STACK_LINE(273)
			::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(273)
			Float vx = ((((_this->m00 * f0->x) + (_this->m01 * f0->y)) + (_this->m02 * f0->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(273)
			Float vy = ((((_this->m10 * f0->x) + (_this->m11 * f0->y)) + (_this->m12 * f0->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(273)
			Float vz = ((((_this->m20 * f0->x) + (_this->m21 * f0->y)) + (_this->m22 * f0->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(273)
			f0->x = vx;
			HX_STACK_LINE(273)
			f0->y = vy;
			HX_STACK_LINE(273)
			f0->z = vz;
			HX_STACK_LINE(273)
			f0;
		}
		HX_STACK_LINE(274)
		{
			HX_STACK_LINE(274)
			::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(274)
			Float vx = ((((_this->m00 * f1->x) + (_this->m01 * f1->y)) + (_this->m02 * f1->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(274)
			Float vy = ((((_this->m10 * f1->x) + (_this->m11 * f1->y)) + (_this->m12 * f1->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(274)
			Float vz = ((((_this->m20 * f1->x) + (_this->m21 * f1->y)) + (_this->m22 * f1->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(274)
			f1->x = vx;
			HX_STACK_LINE(274)
			f1->y = vy;
			HX_STACK_LINE(274)
			f1->z = vz;
			HX_STACK_LINE(274)
			f1;
		}
		HX_STACK_LINE(275)
		{
			HX_STACK_LINE(275)
			::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(275)
			Float vx = ((((_this->m00 * f2->x) + (_this->m01 * f2->y)) + (_this->m02 * f2->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(275)
			Float vy = ((((_this->m10 * f2->x) + (_this->m11 * f2->y)) + (_this->m12 * f2->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(275)
			Float vz = ((((_this->m20 * f2->x) + (_this->m21 * f2->y)) + (_this->m22 * f2->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(275)
			f2->x = vx;
			HX_STACK_LINE(275)
			f2->y = vy;
			HX_STACK_LINE(275)
			f2->z = vz;
			HX_STACK_LINE(275)
			f2;
		}
		HX_STACK_LINE(276)
		{
			HX_STACK_LINE(276)
			::haxor::math::Matrix4 _this = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(276)
			Float vx = ((((_this->m00 * f3->x) + (_this->m01 * f3->y)) + (_this->m02 * f3->z)) + _this->m03);		HX_STACK_VAR(vx,"vx");
			HX_STACK_LINE(276)
			Float vy = ((((_this->m10 * f3->x) + (_this->m11 * f3->y)) + (_this->m12 * f3->z)) + _this->m13);		HX_STACK_VAR(vy,"vy");
			HX_STACK_LINE(276)
			Float vz = ((((_this->m20 * f3->x) + (_this->m21 * f3->y)) + (_this->m22 * f3->z)) + _this->m23);		HX_STACK_VAR(vz,"vz");
			HX_STACK_LINE(276)
			f3->x = vx;
			HX_STACK_LINE(276)
			f3->y = vy;
			HX_STACK_LINE(276)
			f3->z = vz;
			HX_STACK_LINE(276)
			f3;
		}
		struct _Function_1_9{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/RendererContext.hx",278,0xd2e9a6bf)
				{
					HX_STACK_LINE(278)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(278)
					int _g8 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(278)
					return _this->m_v3->__get(_g8).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(278)
		::haxor::math::Vector3 pmin = (_Function_1_9::Block())->Set(n0->x,n0->y,n0->z);		HX_STACK_VAR(pmin,"pmin");
		struct _Function_1_10{
			inline static ::haxor::math::Vector3 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/RendererContext.hx",279,0xd2e9a6bf)
				{
					HX_STACK_LINE(279)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(279)
					int _g9 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(279)
					return _this->m_v3->__get(_g9).StaticCast< ::haxor::math::Vector3 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(279)
		::haxor::math::Vector3 pmax = (_Function_1_10::Block())->Set(n0->x,n0->y,n0->z);		HX_STACK_VAR(pmax,"pmax");
		HX_STACK_LINE(281)
		Float _g10;		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(281)
		{
			HX_STACK_LINE(281)
			Float b;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(281)
			{
				HX_STACK_LINE(281)
				Float b1 = ::Math_obj::min(n2->x,n3->x);		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(281)
				b = ::Math_obj::min(n1->x,b1);
			}
			HX_STACK_LINE(281)
			_g10 = ::Math_obj::min(pmin->x,b);
		}
		HX_STACK_LINE(281)
		pmin->x = _g10;
		HX_STACK_LINE(282)
		Float _g11;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(282)
		{
			HX_STACK_LINE(282)
			Float b;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(282)
			{
				HX_STACK_LINE(282)
				Float b1 = ::Math_obj::min(n2->y,n3->y);		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(282)
				b = ::Math_obj::min(n1->y,b1);
			}
			HX_STACK_LINE(282)
			_g11 = ::Math_obj::min(pmin->y,b);
		}
		HX_STACK_LINE(282)
		pmin->y = _g11;
		HX_STACK_LINE(283)
		Float _g12;		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(283)
		{
			HX_STACK_LINE(283)
			Float b;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(283)
			{
				HX_STACK_LINE(283)
				Float b1 = ::Math_obj::min(n2->z,n3->z);		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(283)
				b = ::Math_obj::min(n1->z,b1);
			}
			HX_STACK_LINE(283)
			_g12 = ::Math_obj::min(pmin->z,b);
		}
		HX_STACK_LINE(283)
		pmin->z = _g12;
		HX_STACK_LINE(285)
		Float _g13;		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(285)
		{
			HX_STACK_LINE(285)
			Float b;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(285)
			{
				HX_STACK_LINE(285)
				Float b1 = ::Math_obj::max(n2->x,n3->x);		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(285)
				b = ::Math_obj::max(n1->x,b1);
			}
			HX_STACK_LINE(285)
			_g13 = ::Math_obj::max(pmax->x,b);
		}
		HX_STACK_LINE(285)
		pmax->x = _g13;
		HX_STACK_LINE(286)
		Float _g14;		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(286)
		{
			HX_STACK_LINE(286)
			Float b;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(286)
			{
				HX_STACK_LINE(286)
				Float b1 = ::Math_obj::max(n2->y,n3->y);		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(286)
				b = ::Math_obj::max(n1->y,b1);
			}
			HX_STACK_LINE(286)
			_g14 = ::Math_obj::max(pmax->y,b);
		}
		HX_STACK_LINE(286)
		pmax->y = _g14;
		HX_STACK_LINE(287)
		Float _g15;		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(287)
		{
			HX_STACK_LINE(287)
			Float b;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(287)
			{
				HX_STACK_LINE(287)
				Float b1 = ::Math_obj::max(n2->z,n3->z);		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(287)
				b = ::Math_obj::max(n1->z,b1);
			}
			HX_STACK_LINE(287)
			_g15 = ::Math_obj::max(pmax->z,b);
		}
		HX_STACK_LINE(287)
		pmax->z = _g15;
		HX_STACK_LINE(289)
		Float _g16;		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(289)
		{
			HX_STACK_LINE(289)
			Float b;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(289)
			{
				HX_STACK_LINE(289)
				Float b1;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(289)
				{
					HX_STACK_LINE(289)
					Float b2 = ::Math_obj::min(f2->x,f3->x);		HX_STACK_VAR(b2,"b2");
					HX_STACK_LINE(289)
					b1 = ::Math_obj::min(f1->x,b2);
				}
				HX_STACK_LINE(289)
				b = ::Math_obj::min(f0->x,b1);
			}
			HX_STACK_LINE(289)
			_g16 = ::Math_obj::min(pmin->x,b);
		}
		HX_STACK_LINE(289)
		pmin->x = _g16;
		HX_STACK_LINE(290)
		Float _g17;		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(290)
		{
			HX_STACK_LINE(290)
			Float b;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(290)
			{
				HX_STACK_LINE(290)
				Float b1;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(290)
				{
					HX_STACK_LINE(290)
					Float b2 = ::Math_obj::min(f2->y,f3->y);		HX_STACK_VAR(b2,"b2");
					HX_STACK_LINE(290)
					b1 = ::Math_obj::min(f1->y,b2);
				}
				HX_STACK_LINE(290)
				b = ::Math_obj::min(f0->y,b1);
			}
			HX_STACK_LINE(290)
			_g17 = ::Math_obj::min(pmin->y,b);
		}
		HX_STACK_LINE(290)
		pmin->y = _g17;
		HX_STACK_LINE(291)
		Float _g18;		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(291)
		{
			HX_STACK_LINE(291)
			Float b;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(291)
			{
				HX_STACK_LINE(291)
				Float b1;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(291)
				{
					HX_STACK_LINE(291)
					Float b2 = ::Math_obj::min(f2->z,f3->z);		HX_STACK_VAR(b2,"b2");
					HX_STACK_LINE(291)
					b1 = ::Math_obj::min(f1->z,b2);
				}
				HX_STACK_LINE(291)
				b = ::Math_obj::min(f0->z,b1);
			}
			HX_STACK_LINE(291)
			_g18 = ::Math_obj::min(pmin->z,b);
		}
		HX_STACK_LINE(291)
		pmin->z = _g18;
		HX_STACK_LINE(293)
		Float _g19;		HX_STACK_VAR(_g19,"_g19");
		HX_STACK_LINE(293)
		{
			HX_STACK_LINE(293)
			Float b;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(293)
			{
				HX_STACK_LINE(293)
				Float b1;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(293)
				{
					HX_STACK_LINE(293)
					Float b2 = ::Math_obj::max(f2->x,f3->x);		HX_STACK_VAR(b2,"b2");
					HX_STACK_LINE(293)
					b1 = ::Math_obj::max(f1->x,b2);
				}
				HX_STACK_LINE(293)
				b = ::Math_obj::max(f0->x,b1);
			}
			HX_STACK_LINE(293)
			_g19 = ::Math_obj::max(pmax->x,b);
		}
		HX_STACK_LINE(293)
		pmax->x = _g19;
		HX_STACK_LINE(294)
		Float _g20;		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(294)
		{
			HX_STACK_LINE(294)
			Float b;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(294)
			{
				HX_STACK_LINE(294)
				Float b1;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(294)
				{
					HX_STACK_LINE(294)
					Float b2 = ::Math_obj::max(f2->y,f3->y);		HX_STACK_VAR(b2,"b2");
					HX_STACK_LINE(294)
					b1 = ::Math_obj::max(f1->y,b2);
				}
				HX_STACK_LINE(294)
				b = ::Math_obj::max(f0->y,b1);
			}
			HX_STACK_LINE(294)
			_g20 = ::Math_obj::max(pmax->y,b);
		}
		HX_STACK_LINE(294)
		pmax->y = _g20;
		HX_STACK_LINE(295)
		Float _g21;		HX_STACK_VAR(_g21,"_g21");
		HX_STACK_LINE(295)
		{
			HX_STACK_LINE(295)
			Float b;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(295)
			{
				HX_STACK_LINE(295)
				Float b1;		HX_STACK_VAR(b1,"b1");
				HX_STACK_LINE(295)
				{
					HX_STACK_LINE(295)
					Float b2 = ::Math_obj::max(f2->z,f3->z);		HX_STACK_VAR(b2,"b2");
					HX_STACK_LINE(295)
					b1 = ::Math_obj::max(f1->z,b2);
				}
				HX_STACK_LINE(295)
				b = ::Math_obj::max(f0->z,b1);
			}
			HX_STACK_LINE(295)
			_g21 = ::Math_obj::max(pmax->z,b);
		}
		HX_STACK_LINE(295)
		pmax->z = _g21;
		HX_STACK_LINE(297)
		c->m_aabb->Set3(pmin,pmax);
		HX_STACK_LINE(299)
		this->UpdateSAP(c->__fcid,c,pmin,pmax);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,UpdateCameraSAP,(void))

Void RendererContext_obj::UpdateSAP( int p_id,Dynamic p_d,::haxor::math::Vector3 p_min,::haxor::math::Vector3 p_max){
{
		HX_STACK_FRAME("haxor.context.RendererContext","UpdateSAP",0x6c890eec,"haxor.context.RendererContext.UpdateSAP","haxor/context/RendererContext.hx",310,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_d,"p_d")
		HX_STACK_ARG(p_min,"p_min")
		HX_STACK_ARG(p_max,"p_max")
		HX_STACK_LINE(311)
		this->sap_dirty = true;
		HX_STACK_LINE(312)
		this->sap->Update(p_id,p_d,p_min,p_max);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(RendererContext_obj,UpdateSAP,(void))

bool RendererContext_obj::IsSAPCulled( ::haxor::component::Renderer r,::haxor::component::Camera c){
	HX_STACK_FRAME("haxor.context.RendererContext","IsSAPCulled",0xb9324b1c,"haxor.context.RendererContext.IsSAPCulled","haxor/context/RendererContext.hx",322,0xd2e9a6bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(r,"r")
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(323)
	if ((!(r->m_has_mesh))){
		HX_STACK_LINE(323)
		return false;
	}
	HX_STACK_LINE(324)
	::haxor::component::MeshRenderer mr = r;		HX_STACK_VAR(mr,"mr");
	HX_STACK_LINE(325)
	if ((mr->m_culling_dirty)){
		HX_STACK_LINE(325)
		return false;
	}
	HX_STACK_LINE(326)
	return !(this->sap->Overlap(mr->__fcid,c->__fcid));
}


HX_DEFINE_DYNAMIC_FUNC2(RendererContext_obj,IsSAPCulled,return )

Void RendererContext_obj::Destroy( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.context.RendererContext","Destroy",0xf33cd78d,"haxor.context.RendererContext.Destroy","haxor/context/RendererContext.hx",334,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(335)
		this->display->__get(r->m_entity->m_layer).StaticCast< ::haxor::context::Process >()->Remove(r);
		HX_STACK_LINE(336)
		this->sort[r->m_entity->m_layer] = true;
		HX_STACK_LINE(337)
		{
			HX_STACK_LINE(337)
			int v = r->__cid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(337)
			this->rid->m_cache->push(v);
			HX_STACK_LINE(337)
			v;
		}
		HX_STACK_LINE(340)
		if ((r->m_has_mesh)){
			HX_STACK_LINE(342)
			::haxor::component::MeshRenderer mr = r;		HX_STACK_VAR(mr,"mr");
			HX_STACK_LINE(343)
			{
				HX_STACK_LINE(343)
				int v = mr->__fcid;		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(343)
				this->fcid->m_cache->push(v);
				HX_STACK_LINE(343)
				v;
			}
			HX_STACK_LINE(344)
			this->sap->Remove(mr->__fcid);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,Destroy,(void))

int RendererContext_obj::DisplayListSort( ::haxor::component::Renderer a,::haxor::component::Renderer b){
	HX_STACK_FRAME("haxor.context.RendererContext","DisplayListSort",0xfdcfe4d1,"haxor.context.RendererContext.DisplayListSort","haxor/context/RendererContext.hx",366,0xd2e9a6bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(368)
	if (((a == null()))){
		HX_STACK_LINE(368)
		if (((b == null()))){
			HX_STACK_LINE(368)
			return (int)0;
		}
	}
	HX_STACK_LINE(369)
	if (((a == null()))){
		HX_STACK_LINE(369)
		return (int)1;
	}
	HX_STACK_LINE(370)
	if (((b == null()))){
		HX_STACK_LINE(370)
		return (int)-1;
	}
	HX_STACK_LINE(373)
	if (((a->m_material == null()))){
		HX_STACK_LINE(373)
		if (((b->m_material == null()))){
			HX_STACK_LINE(373)
			return (int)0;
		}
	}
	HX_STACK_LINE(376)
	if (((a->m_material == null()))){
		HX_STACK_LINE(376)
		return (int)1;
	}
	HX_STACK_LINE(377)
	if (((b->m_material == null()))){
		HX_STACK_LINE(377)
		return (int)-1;
	}
	HX_STACK_LINE(379)
	::haxor::graphics::material::Material ma = a->m_material;		HX_STACK_VAR(ma,"ma");
	HX_STACK_LINE(380)
	::haxor::graphics::material::Material mb = b->m_material;		HX_STACK_VAR(mb,"mb");
	HX_STACK_LINE(381)
	int ia = ma->queue;		HX_STACK_VAR(ia,"ia");
	HX_STACK_LINE(382)
	int ib = mb->queue;		HX_STACK_VAR(ib,"ib");
	HX_STACK_LINE(385)
	if (((ia != ib))){
		HX_STACK_LINE(385)
		if (((ia < ib))){
			HX_STACK_LINE(385)
			return (int)-1;
		}
		else{
			HX_STACK_LINE(385)
			return (int)1;
		}
	}
	HX_STACK_LINE(388)
	if ((!(a->m_has_mesh))){
		HX_STACK_LINE(388)
		if ((!(b->m_has_mesh))){
			HX_STACK_LINE(388)
			return (int)0;
		}
	}
	HX_STACK_LINE(391)
	if ((!(a->m_has_mesh))){
		HX_STACK_LINE(391)
		return (int)1;
	}
	HX_STACK_LINE(392)
	if ((!(b->m_has_mesh))){
		HX_STACK_LINE(392)
		return (int)-1;
	}
	HX_STACK_LINE(394)
	::haxor::component::MeshRenderer mra = a;		HX_STACK_VAR(mra,"mra");
	HX_STACK_LINE(395)
	::haxor::component::MeshRenderer mrb = b;		HX_STACK_VAR(mrb,"mrb");
	HX_STACK_LINE(398)
	int _g = mra->m_material->get_uid();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(398)
	int _g1 = mrb->m_material->get_uid();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(398)
	if (((_g < _g1))){
		HX_STACK_LINE(398)
		return (int)-1;
	}
	HX_STACK_LINE(399)
	int _g2 = mra->m_material->get_uid();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(399)
	int _g3 = mrb->m_material->get_uid();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(399)
	if (((_g2 > _g3))){
		HX_STACK_LINE(399)
		return (int)1;
	}
	HX_STACK_LINE(402)
	if (((mra->m_mesh == null()))){
		HX_STACK_LINE(402)
		if (((mrb->m_mesh == null()))){
			HX_STACK_LINE(402)
			return (int)0;
		}
	}
	HX_STACK_LINE(403)
	if (((mra->m_mesh == null()))){
		HX_STACK_LINE(403)
		return (int)1;
	}
	HX_STACK_LINE(404)
	if (((mrb->m_mesh == null()))){
		HX_STACK_LINE(404)
		return (int)-1;
	}
	HX_STACK_LINE(407)
	int _g4 = mra->m_mesh->get_uid();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(407)
	int _g5 = mrb->m_mesh->get_uid();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(407)
	if (((_g4 < _g5))){
		HX_STACK_LINE(407)
		return (int)-1;
	}
	HX_STACK_LINE(408)
	int _g6 = mra->m_mesh->get_uid();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(408)
	int _g7 = mrb->m_mesh->get_uid();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(408)
	if (((_g6 > _g7))){
		HX_STACK_LINE(408)
		return (int)1;
	}
	HX_STACK_LINE(410)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(RendererContext_obj,DisplayListSort,return )


RendererContext_obj::RendererContext_obj()
{
}

void RendererContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RendererContext);
	HX_MARK_MEMBER_NAME(rid,"rid");
	HX_MARK_MEMBER_NAME(fcid,"fcid");
	HX_MARK_MEMBER_NAME(display,"display");
	HX_MARK_MEMBER_NAME(sap,"sap");
	HX_MARK_MEMBER_NAME(sap_dirty,"sap_dirty");
	HX_MARK_MEMBER_NAME(sort,"sort");
	HX_MARK_MEMBER_NAME(skinning,"skinning");
	HX_MARK_MEMBER_NAME(deferred_culling,"deferred_culling");
	HX_MARK_MEMBER_NAME(deferred_offset,"deferred_offset");
	HX_MARK_END_CLASS();
}

void RendererContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(rid,"rid");
	HX_VISIT_MEMBER_NAME(fcid,"fcid");
	HX_VISIT_MEMBER_NAME(display,"display");
	HX_VISIT_MEMBER_NAME(sap,"sap");
	HX_VISIT_MEMBER_NAME(sap_dirty,"sap_dirty");
	HX_VISIT_MEMBER_NAME(sort,"sort");
	HX_VISIT_MEMBER_NAME(skinning,"skinning");
	HX_VISIT_MEMBER_NAME(deferred_culling,"deferred_culling");
	HX_VISIT_MEMBER_NAME(deferred_offset,"deferred_offset");
}

Dynamic RendererContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rid") ) { return rid; }
		if (HX_FIELD_EQ(inName,"sap") ) { return sap; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"fcid") ) { return fcid; }
		if (HX_FIELD_EQ(inName,"sort") ) { return sort; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Create") ) { return Create_dyn(); }
		if (HX_FIELD_EQ(inName,"Enable") ) { return Enable_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"display") ) { return display; }
		if (HX_FIELD_EQ(inName,"Disable") ) { return Disable_dyn(); }
		if (HX_FIELD_EQ(inName,"Destroy") ) { return Destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"skinning") ) { return skinning; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sap_dirty") ) { return sap_dirty; }
		if (HX_FIELD_EQ(inName,"AddCamera") ) { return AddCamera_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateSAP") ) { return UpdateSAP_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"IsSAPCulled") ) { return IsSAPCulled_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"RemoveCamera") ) { return RemoveCamera_dyn(); }
		if (HX_FIELD_EQ(inName,"OnMeshChange") ) { return OnMeshChange_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"OnLayerChange") ) { return OnLayerChange_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"deferred_offset") ) { return deferred_offset; }
		if (HX_FIELD_EQ(inName,"DeferredCulling") ) { return DeferredCulling_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateCameraSAP") ) { return UpdateCameraSAP_dyn(); }
		if (HX_FIELD_EQ(inName,"DisplayListSort") ) { return DisplayListSort_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"deferred_culling") ) { return deferred_culling; }
		if (HX_FIELD_EQ(inName,"OnMaterialChange") ) { return OnMaterialChange_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"UpdateDisplayList") ) { return UpdateDisplayList_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"OnVisibilityChange") ) { return OnVisibilityChange_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RendererContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rid") ) { rid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sap") ) { sap=inValue.Cast< ::haxor::ds::SAP >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"fcid") ) { fcid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sort") ) { sort=inValue.Cast< Array< bool > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"display") ) { display=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"skinning") ) { skinning=inValue.Cast< ::haxor::graphics::texture::ComputeTexture >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"sap_dirty") ) { sap_dirty=inValue.Cast< bool >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"deferred_offset") ) { deferred_offset=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"deferred_culling") ) { deferred_culling=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RendererContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("rid"));
	outFields->push(HX_CSTRING("fcid"));
	outFields->push(HX_CSTRING("display"));
	outFields->push(HX_CSTRING("sap"));
	outFields->push(HX_CSTRING("sap_dirty"));
	outFields->push(HX_CSTRING("sort"));
	outFields->push(HX_CSTRING("skinning"));
	outFields->push(HX_CSTRING("deferred_culling"));
	outFields->push(HX_CSTRING("deferred_offset"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(RendererContext_obj,rid),HX_CSTRING("rid")},
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(RendererContext_obj,fcid),HX_CSTRING("fcid")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(RendererContext_obj,display),HX_CSTRING("display")},
	{hx::fsObject /*::haxor::ds::SAP*/ ,(int)offsetof(RendererContext_obj,sap),HX_CSTRING("sap")},
	{hx::fsBool,(int)offsetof(RendererContext_obj,sap_dirty),HX_CSTRING("sap_dirty")},
	{hx::fsObject /*Array< bool >*/ ,(int)offsetof(RendererContext_obj,sort),HX_CSTRING("sort")},
	{hx::fsObject /*::haxor::graphics::texture::ComputeTexture*/ ,(int)offsetof(RendererContext_obj,skinning),HX_CSTRING("skinning")},
	{hx::fsInt,(int)offsetof(RendererContext_obj,deferred_culling),HX_CSTRING("deferred_culling")},
	{hx::fsInt,(int)offsetof(RendererContext_obj,deferred_offset),HX_CSTRING("deferred_offset")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("rid"),
	HX_CSTRING("fcid"),
	HX_CSTRING("display"),
	HX_CSTRING("sap"),
	HX_CSTRING("sap_dirty"),
	HX_CSTRING("sort"),
	HX_CSTRING("skinning"),
	HX_CSTRING("deferred_culling"),
	HX_CSTRING("deferred_offset"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Create"),
	HX_CSTRING("AddCamera"),
	HX_CSTRING("RemoveCamera"),
	HX_CSTRING("OnMaterialChange"),
	HX_CSTRING("OnMeshChange"),
	HX_CSTRING("OnVisibilityChange"),
	HX_CSTRING("DeferredCulling"),
	HX_CSTRING("OnLayerChange"),
	HX_CSTRING("UpdateDisplayList"),
	HX_CSTRING("Enable"),
	HX_CSTRING("Disable"),
	HX_CSTRING("UpdateCameraSAP"),
	HX_CSTRING("UpdateSAP"),
	HX_CSTRING("IsSAPCulled"),
	HX_CSTRING("Destroy"),
	HX_CSTRING("DisplayListSort"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RendererContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RendererContext_obj::__mClass,"__mClass");
};

#endif

Class RendererContext_obj::__mClass;

void RendererContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.RendererContext"), hx::TCanCast< RendererContext_obj> ,sStaticFields,sMemberFields,
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

void RendererContext_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
