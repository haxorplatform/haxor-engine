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
namespace haxor{
namespace context{

Void RendererContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.RendererContext","new",0x3d8f3d93,"haxor.context.RendererContext.new","haxor/context/RendererContext.hx",45,0xd2e9a6bf)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(46)
	::haxor::context::UID _g = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(46)
	this->rid = _g;
	HX_STACK_LINE(48)
	this->display = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(49)
	this->sort = Array_obj< bool >::__new();
	HX_STACK_LINE(50)
	{
		HX_STACK_LINE(50)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(50)
		while((true)){
			HX_STACK_LINE(50)
			if ((!(((_g1 < (int)32))))){
				HX_STACK_LINE(50)
				break;
			}
			HX_STACK_LINE(50)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(52)
			::haxor::context::Process p = ::haxor::context::Process_obj::__new(HX_CSTRING("process.renderers"),::haxor::context::EngineContext_obj::maxNodes,(i == (int)31));		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(53)
			this->display->push(p);
			HX_STACK_LINE(54)
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
		HX_STACK_FRAME("haxor.context.RendererContext","Initialize",0x7335249d,"haxor.context.RendererContext.Initialize","haxor/context/RendererContext.hx",62,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_LINE(64)
		::haxor::graphics::texture::ComputeTexture _g = ::haxor::graphics::texture::ComputeTexture_obj::__new((int)512,(int)512,::haxor::core::PixelFormat_obj::Float4);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(64)
		this->skinning = _g;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(RendererContext_obj,Initialize,(void))

Void RendererContext_obj::OnMaterialChange( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.context.RendererContext","OnMaterialChange",0xd2d6d203,"haxor.context.RendererContext.OnMaterialChange","haxor/context/RendererContext.hx",72,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(73)
		int l = r->m_entity->m_layer;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(74)
		this->sort[l] = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,OnMaterialChange,(void))

Void RendererContext_obj::OnMeshChange( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.context.RendererContext","OnMeshChange",0x02f6c1c9,"haxor.context.RendererContext.OnMeshChange","haxor/context/RendererContext.hx",82,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(83)
		int l = r->m_entity->m_layer;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(84)
		this->sort[l] = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,OnMeshChange,(void))

Void RendererContext_obj::OnLayerChange( ::haxor::component::Renderer r,int from,int to){
{
		HX_STACK_FRAME("haxor.context.RendererContext","OnLayerChange",0x2f73b215,"haxor.context.RendererContext.OnLayerChange","haxor/context/RendererContext.hx",94,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_ARG(from,"from")
		HX_STACK_ARG(to,"to")
		HX_STACK_LINE(95)
		this->sort[from] = true;
		HX_STACK_LINE(96)
		this->display->__get(from).StaticCast< ::haxor::context::Process >()->Remove(r);
		HX_STACK_LINE(97)
		if ((r->get_enabled())){
			HX_STACK_LINE(99)
			this->display->__get(to).StaticCast< ::haxor::context::Process >()->Add(r);
			HX_STACK_LINE(100)
			this->sort[to] = true;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(RendererContext_obj,OnLayerChange,(void))

Void RendererContext_obj::UpdateDisplayList( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.RendererContext","UpdateDisplayList",0xd536288a,"haxor.context.RendererContext.UpdateDisplayList","haxor/context/RendererContext.hx",108,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(109)
		Array< int > ll = c->m_layers;		HX_STACK_VAR(ll,"ll");
		HX_STACK_LINE(110)
		{
			HX_STACK_LINE(110)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(110)
			int _g = ll->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(110)
			while((true)){
				HX_STACK_LINE(110)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(110)
					break;
				}
				HX_STACK_LINE(110)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(112)
				int l = ll->__get(i);		HX_STACK_VAR(l,"l");
				HX_STACK_LINE(113)
				::haxor::context::Process rl = this->display->__get(l).StaticCast< ::haxor::context::Process >();		HX_STACK_VAR(rl,"rl");
				HX_STACK_LINE(114)
				bool need_sort = this->sort->__get(l);		HX_STACK_VAR(need_sort,"need_sort");
				HX_STACK_LINE(115)
				if ((need_sort)){
					HX_STACK_LINE(117)
					this->sort[l] = false;
					HX_STACK_LINE(118)
					if (((rl->m_length > (int)1))){
						HX_STACK_LINE(118)
						rl->list->__Field(HX_CSTRING("sort"),true)(this->DisplayListSort_dyn());
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
		HX_STACK_FRAME("haxor.context.RendererContext","Enable",0xd4b8b750,"haxor.context.RendererContext.Enable","haxor/context/RendererContext.hx",128,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(129)
		this->display->__get(r->m_entity->m_layer).StaticCast< ::haxor::context::Process >()->Add(r);
		HX_STACK_LINE(130)
		this->sort[r->m_entity->m_layer] = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,Enable,(void))

Void RendererContext_obj::Disable( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.context.RendererContext","Disable",0x800f147b,"haxor.context.RendererContext.Disable","haxor/context/RendererContext.hx",138,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(139)
		this->display->__get(r->m_entity->m_layer).StaticCast< ::haxor::context::Process >()->Remove(r);
		HX_STACK_LINE(140)
		this->sort[r->m_entity->m_layer] = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,Disable,(void))

Void RendererContext_obj::Destroy( ::haxor::component::Renderer r){
{
		HX_STACK_FRAME("haxor.context.RendererContext","Destroy",0xf33cd78d,"haxor.context.RendererContext.Destroy","haxor/context/RendererContext.hx",148,0xd2e9a6bf)
		HX_STACK_THIS(this)
		HX_STACK_ARG(r,"r")
		HX_STACK_LINE(149)
		this->display->__get(r->m_entity->m_layer).StaticCast< ::haxor::context::Process >()->Remove(r);
		HX_STACK_LINE(150)
		this->sort[r->m_entity->m_layer] = true;
		HX_STACK_LINE(151)
		{
			HX_STACK_LINE(151)
			int v = r->__cid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(151)
			::haxor::context::EngineContext_obj::renderer->rid->m_cache->push(v);
			HX_STACK_LINE(151)
			v;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(RendererContext_obj,Destroy,(void))

int RendererContext_obj::DisplayListSort( ::haxor::component::Renderer a,::haxor::component::Renderer b){
	HX_STACK_FRAME("haxor.context.RendererContext","DisplayListSort",0xfdcfe4d1,"haxor.context.RendererContext.DisplayListSort","haxor/context/RendererContext.hx",172,0xd2e9a6bf)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(174)
	if (((a == null()))){
		HX_STACK_LINE(174)
		if (((b == null()))){
			HX_STACK_LINE(174)
			return (int)0;
		}
	}
	HX_STACK_LINE(175)
	if (((a == null()))){
		HX_STACK_LINE(175)
		return (int)1;
	}
	HX_STACK_LINE(176)
	if (((b == null()))){
		HX_STACK_LINE(176)
		return (int)-1;
	}
	HX_STACK_LINE(179)
	if (((a->m_material == null()))){
		HX_STACK_LINE(179)
		if (((b->m_material == null()))){
			HX_STACK_LINE(179)
			return (int)0;
		}
	}
	HX_STACK_LINE(182)
	if (((a->m_material == null()))){
		HX_STACK_LINE(182)
		return (int)1;
	}
	HX_STACK_LINE(183)
	if (((b->m_material == null()))){
		HX_STACK_LINE(183)
		return (int)-1;
	}
	HX_STACK_LINE(185)
	::haxor::graphics::material::Material ma = a->m_material;		HX_STACK_VAR(ma,"ma");
	HX_STACK_LINE(186)
	::haxor::graphics::material::Material mb = b->m_material;		HX_STACK_VAR(mb,"mb");
	HX_STACK_LINE(187)
	int ia = ma->queue;		HX_STACK_VAR(ia,"ia");
	HX_STACK_LINE(188)
	int ib = mb->queue;		HX_STACK_VAR(ib,"ib");
	HX_STACK_LINE(191)
	if (((ia != ib))){
		HX_STACK_LINE(191)
		if (((ia < ib))){
			HX_STACK_LINE(191)
			return (int)-1;
		}
		else{
			HX_STACK_LINE(191)
			return (int)1;
		}
	}
	HX_STACK_LINE(194)
	if ((!(a->m_has_mesh))){
		HX_STACK_LINE(194)
		if ((!(b->m_has_mesh))){
			HX_STACK_LINE(194)
			return (int)0;
		}
	}
	HX_STACK_LINE(197)
	if ((!(a->m_has_mesh))){
		HX_STACK_LINE(197)
		return (int)1;
	}
	HX_STACK_LINE(198)
	if ((!(b->m_has_mesh))){
		HX_STACK_LINE(198)
		return (int)-1;
	}
	HX_STACK_LINE(200)
	::haxor::component::MeshRenderer mra = a;		HX_STACK_VAR(mra,"mra");
	HX_STACK_LINE(201)
	::haxor::component::MeshRenderer mrb = b;		HX_STACK_VAR(mrb,"mrb");
	HX_STACK_LINE(204)
	int _g = mra->m_material->get_uid();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(204)
	int _g1 = mrb->m_material->get_uid();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(204)
	if (((_g < _g1))){
		HX_STACK_LINE(204)
		return (int)-1;
	}
	HX_STACK_LINE(205)
	int _g2 = mra->m_material->get_uid();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(205)
	int _g3 = mrb->m_material->get_uid();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(205)
	if (((_g2 > _g3))){
		HX_STACK_LINE(205)
		return (int)1;
	}
	HX_STACK_LINE(208)
	if (((mra->m_mesh == null()))){
		HX_STACK_LINE(208)
		if (((mrb->m_mesh == null()))){
			HX_STACK_LINE(208)
			return (int)0;
		}
	}
	HX_STACK_LINE(209)
	if (((mra->m_mesh == null()))){
		HX_STACK_LINE(209)
		return (int)1;
	}
	HX_STACK_LINE(210)
	if (((mrb->m_mesh == null()))){
		HX_STACK_LINE(210)
		return (int)-1;
	}
	HX_STACK_LINE(213)
	int _g4 = mra->m_mesh->get_uid();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(213)
	int _g5 = mrb->m_mesh->get_uid();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(213)
	if (((_g4 < _g5))){
		HX_STACK_LINE(213)
		return (int)-1;
	}
	HX_STACK_LINE(214)
	int _g6 = mra->m_mesh->get_uid();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(214)
	int _g7 = mrb->m_mesh->get_uid();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(214)
	if (((_g6 > _g7))){
		HX_STACK_LINE(214)
		return (int)1;
	}
	HX_STACK_LINE(216)
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
	HX_MARK_MEMBER_NAME(display,"display");
	HX_MARK_MEMBER_NAME(sort,"sort");
	HX_MARK_MEMBER_NAME(skinning,"skinning");
	HX_MARK_END_CLASS();
}

void RendererContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(rid,"rid");
	HX_VISIT_MEMBER_NAME(display,"display");
	HX_VISIT_MEMBER_NAME(sort,"sort");
	HX_VISIT_MEMBER_NAME(skinning,"skinning");
}

Dynamic RendererContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rid") ) { return rid; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"sort") ) { return sort; }
		break;
	case 6:
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
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"OnMeshChange") ) { return OnMeshChange_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"OnLayerChange") ) { return OnLayerChange_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"DisplayListSort") ) { return DisplayListSort_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"OnMaterialChange") ) { return OnMaterialChange_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"UpdateDisplayList") ) { return UpdateDisplayList_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RendererContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"rid") ) { rid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"sort") ) { sort=inValue.Cast< Array< bool > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"display") ) { display=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"skinning") ) { skinning=inValue.Cast< ::haxor::graphics::texture::ComputeTexture >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RendererContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("rid"));
	outFields->push(HX_CSTRING("display"));
	outFields->push(HX_CSTRING("sort"));
	outFields->push(HX_CSTRING("skinning"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(RendererContext_obj,rid),HX_CSTRING("rid")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(RendererContext_obj,display),HX_CSTRING("display")},
	{hx::fsObject /*Array< bool >*/ ,(int)offsetof(RendererContext_obj,sort),HX_CSTRING("sort")},
	{hx::fsObject /*::haxor::graphics::texture::ComputeTexture*/ ,(int)offsetof(RendererContext_obj,skinning),HX_CSTRING("skinning")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("rid"),
	HX_CSTRING("display"),
	HX_CSTRING("sort"),
	HX_CSTRING("skinning"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("OnMaterialChange"),
	HX_CSTRING("OnMeshChange"),
	HX_CSTRING("OnLayerChange"),
	HX_CSTRING("UpdateDisplayList"),
	HX_CSTRING("Enable"),
	HX_CSTRING("Disable"),
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
