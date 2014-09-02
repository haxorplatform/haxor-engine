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
#ifndef INCLUDED_haxor_context_BaseProcess
#include <haxor/context/BaseProcess.h>
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
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
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
	::haxor::ds::SAP _g2 = ::haxor::ds::SAP_obj::__new();		HX_STACK_VAR(_g2,"_g2");
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

Void RendererContext_obj::UpdateSAP( int p_id,Dynamic p_d,::haxor::math::Vector3 p_min,::haxor::math::Vector3 p_max){
{
		HX_STACK_FRAME("haxor.context.RendererContext","UpdateSAP",0x6c890eec,"haxor.context.RendererContext.UpdateSAP","haxor/context/RendererContext.hx",259,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_d,"p_d")
		HX_STACK_ARG(p_min,"p_min")
		HX_STACK_ARG(p_max,"p_max")
		HX_STACK_LINE(260)
		this->sap_dirty = true;
		HX_STACK_LINE(261)
		this->sap->Update(p_id,p_d,p_min,p_max);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(RendererContext_obj,UpdateSAP,(void))

bool RendererContext_obj::IsSAPCulled( ::haxor::component::Renderer r,::haxor::component::Camera c){
	HX_STACK_FRAME("haxor.context.RendererContext","IsSAPCulled",0xb9324b1c,"haxor.context.RendererContext.IsSAPCulled","haxor/context/RendererContext.hx",271,0xd2e9a6bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(r,"r")
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(272)
	if ((!(r->m_has_mesh))){
		HX_STACK_LINE(272)
		return false;
	}
	HX_STACK_LINE(273)
	::haxor::component::MeshRenderer mr = r;		HX_STACK_VAR(mr,"mr");
	HX_STACK_LINE(274)
	return this->sap->Overlap(mr->__fcid,c->__fcid);
}


HX_DEFINE_DYNAMIC_FUNC2(RendererContext_obj,IsSAPCulled,return )

Void RendererContext_obj::Destroy( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.context.RendererContext","Destroy",0xf33cd78d,"haxor.context.RendererContext.Destroy","haxor/context/RendererContext.hx",282,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(283)
		this->display->__get(r->m_entity->m_layer).StaticCast< ::haxor::context::Process >()->Remove(r);
		HX_STACK_LINE(284)
		this->sort[r->m_entity->m_layer] = true;
		HX_STACK_LINE(285)
		{
			HX_STACK_LINE(285)
			int v = r->__cid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(285)
			this->rid->m_cache->push(v);
			HX_STACK_LINE(285)
			v;
		}
		HX_STACK_LINE(288)
		if ((r->m_has_mesh)){
			HX_STACK_LINE(290)
			::haxor::component::MeshRenderer mr = r;		HX_STACK_VAR(mr,"mr");
			HX_STACK_LINE(291)
			{
				HX_STACK_LINE(291)
				int v = mr->__fcid;		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(291)
				this->fcid->m_cache->push(v);
				HX_STACK_LINE(291)
				v;
			}
			HX_STACK_LINE(292)
			this->sap->Remove(mr->__fcid);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,Destroy,(void))

int RendererContext_obj::DisplayListSort( ::haxor::component::Renderer a,::haxor::component::Renderer b){
	HX_STACK_FRAME("haxor.context.RendererContext","DisplayListSort",0xfdcfe4d1,"haxor.context.RendererContext.DisplayListSort","haxor/context/RendererContext.hx",314,0xd2e9a6bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(316)
	if (((a == null()))){
		HX_STACK_LINE(316)
		if (((b == null()))){
			HX_STACK_LINE(316)
			return (int)0;
		}
	}
	HX_STACK_LINE(317)
	if (((a == null()))){
		HX_STACK_LINE(317)
		return (int)1;
	}
	HX_STACK_LINE(318)
	if (((b == null()))){
		HX_STACK_LINE(318)
		return (int)-1;
	}
	HX_STACK_LINE(321)
	if (((a->m_material == null()))){
		HX_STACK_LINE(321)
		if (((b->m_material == null()))){
			HX_STACK_LINE(321)
			return (int)0;
		}
	}
	HX_STACK_LINE(324)
	if (((a->m_material == null()))){
		HX_STACK_LINE(324)
		return (int)1;
	}
	HX_STACK_LINE(325)
	if (((b->m_material == null()))){
		HX_STACK_LINE(325)
		return (int)-1;
	}
	HX_STACK_LINE(327)
	::haxor::graphics::material::Material ma = a->m_material;		HX_STACK_VAR(ma,"ma");
	HX_STACK_LINE(328)
	::haxor::graphics::material::Material mb = b->m_material;		HX_STACK_VAR(mb,"mb");
	HX_STACK_LINE(329)
	int ia = ma->queue;		HX_STACK_VAR(ia,"ia");
	HX_STACK_LINE(330)
	int ib = mb->queue;		HX_STACK_VAR(ib,"ib");
	HX_STACK_LINE(333)
	if (((ia != ib))){
		HX_STACK_LINE(333)
		if (((ia < ib))){
			HX_STACK_LINE(333)
			return (int)-1;
		}
		else{
			HX_STACK_LINE(333)
			return (int)1;
		}
	}
	HX_STACK_LINE(336)
	if ((!(a->m_has_mesh))){
		HX_STACK_LINE(336)
		if ((!(b->m_has_mesh))){
			HX_STACK_LINE(336)
			return (int)0;
		}
	}
	HX_STACK_LINE(339)
	if ((!(a->m_has_mesh))){
		HX_STACK_LINE(339)
		return (int)1;
	}
	HX_STACK_LINE(340)
	if ((!(b->m_has_mesh))){
		HX_STACK_LINE(340)
		return (int)-1;
	}
	HX_STACK_LINE(342)
	::haxor::component::MeshRenderer mra = a;		HX_STACK_VAR(mra,"mra");
	HX_STACK_LINE(343)
	::haxor::component::MeshRenderer mrb = b;		HX_STACK_VAR(mrb,"mrb");
	HX_STACK_LINE(346)
	int _g = mra->m_material->get_uid();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(346)
	int _g1 = mrb->m_material->get_uid();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(346)
	if (((_g < _g1))){
		HX_STACK_LINE(346)
		return (int)-1;
	}
	HX_STACK_LINE(347)
	int _g2 = mra->m_material->get_uid();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(347)
	int _g3 = mrb->m_material->get_uid();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(347)
	if (((_g2 > _g3))){
		HX_STACK_LINE(347)
		return (int)1;
	}
	HX_STACK_LINE(350)
	if (((mra->m_mesh == null()))){
		HX_STACK_LINE(350)
		if (((mrb->m_mesh == null()))){
			HX_STACK_LINE(350)
			return (int)0;
		}
	}
	HX_STACK_LINE(351)
	if (((mra->m_mesh == null()))){
		HX_STACK_LINE(351)
		return (int)1;
	}
	HX_STACK_LINE(352)
	if (((mrb->m_mesh == null()))){
		HX_STACK_LINE(352)
		return (int)-1;
	}
	HX_STACK_LINE(355)
	int _g4 = mra->m_mesh->get_uid();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(355)
	int _g5 = mrb->m_mesh->get_uid();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(355)
	if (((_g4 < _g5))){
		HX_STACK_LINE(355)
		return (int)-1;
	}
	HX_STACK_LINE(356)
	int _g6 = mra->m_mesh->get_uid();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(356)
	int _g7 = mrb->m_mesh->get_uid();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(356)
	if (((_g6 > _g7))){
		HX_STACK_LINE(356)
		return (int)1;
	}
	HX_STACK_LINE(358)
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
