#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
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
#ifndef INCLUDED_haxor_component_animation_Animation
#include <haxor/component/animation/Animation.h>
#endif
#ifndef INCLUDED_haxor_context_BaseProcess
#include <haxor/context/BaseProcess.h>
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
#ifndef INCLUDED_haxor_context_GizmoContext
#include <haxor/context/GizmoContext.h>
#endif
#ifndef INCLUDED_haxor_context_MaterialContext
#include <haxor/context/MaterialContext.h>
#endif
#ifndef INCLUDED_haxor_context_MeshContext
#include <haxor/context/MeshContext.h>
#endif
#ifndef INCLUDED_haxor_context_Process
#include <haxor/context/Process.h>
#endif
#ifndef INCLUDED_haxor_context_RendererContext
#include <haxor/context/RendererContext.h>
#endif
#ifndef INCLUDED_haxor_context_TextureContext
#include <haxor/context/TextureContext.h>
#endif
#ifndef INCLUDED_haxor_context_TransformContext
#include <haxor/context/TransformContext.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IRenderable
#include <haxor/core/IRenderable.h>
#endif
#ifndef INCLUDED_haxor_core_IResizeable
#include <haxor/core/IResizeable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
namespace haxor{
namespace context{

Void EngineContext_obj::__construct()
{
	return null();
}

//EngineContext_obj::~EngineContext_obj() { }

Dynamic EngineContext_obj::__CreateEmpty() { return  new EngineContext_obj; }
hx::ObjectPtr< EngineContext_obj > EngineContext_obj::__new()
{  hx::ObjectPtr< EngineContext_obj > result = new EngineContext_obj();
	result->__construct();
	return result;}

Dynamic EngineContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EngineContext_obj > result = new EngineContext_obj();
	result->__construct();
	return result;}

int EngineContext_obj::uid;

int EngineContext_obj::maxNodes;

int EngineContext_obj::collectRate;

::haxor::context::Process EngineContext_obj::update;

::haxor::context::Process EngineContext_obj::resize;

::haxor::context::Process EngineContext_obj::render;

::haxor::context::Process EngineContext_obj::resources;

::haxor::context::Process EngineContext_obj::disposables;

Array< ::Dynamic > EngineContext_obj::list;

::haxor::context::MeshContext EngineContext_obj::mesh;

::haxor::context::MaterialContext EngineContext_obj::material;

::haxor::context::TextureContext EngineContext_obj::texture;

::haxor::context::CameraContext EngineContext_obj::camera;

::haxor::context::RendererContext EngineContext_obj::renderer;

::haxor::context::GizmoContext EngineContext_obj::gizmo;

::haxor::context::DataContext EngineContext_obj::data;

::haxor::context::TransformContext EngineContext_obj::transform;

Void EngineContext_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.context.EngineContext","Initialize",0x8336921c,"haxor.context.EngineContext.Initialize","haxor/context/EngineContext.hx",115,0x2d4338be)
		HX_STACK_LINE(116)
		::haxor::core::Console_obj::Log(HX_CSTRING("Haxor> Engine Context Initialize."),(int)3);
		HX_STACK_LINE(117)
		::haxor::context::Process _g = ::haxor::context::Process_obj::__new(HX_CSTRING("process.update"),::haxor::context::EngineContext_obj::maxNodes,null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(117)
		::haxor::context::EngineContext_obj::update = _g;
		HX_STACK_LINE(118)
		::haxor::context::Process _g1 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.render"),::haxor::context::EngineContext_obj::maxNodes,null());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(118)
		::haxor::context::EngineContext_obj::render = _g1;
		HX_STACK_LINE(119)
		::haxor::context::Process _g2 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.resize"),::haxor::context::EngineContext_obj::maxNodes,null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(119)
		::haxor::context::EngineContext_obj::resize = _g2;
		HX_STACK_LINE(120)
		::haxor::context::Process _g3 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.resources"),::haxor::context::EngineContext_obj::maxNodes,null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(120)
		::haxor::context::EngineContext_obj::resources = _g3;
		HX_STACK_LINE(121)
		::haxor::context::Process _g4 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.disposables"),::haxor::context::EngineContext_obj::maxNodes,null());		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(121)
		::haxor::context::EngineContext_obj::disposables = _g4;
		HX_STACK_LINE(123)
		::haxor::context::EngineContext_obj::list = Array_obj< ::Dynamic >::__new().Add(::haxor::context::EngineContext_obj::update).Add(::haxor::context::EngineContext_obj::render).Add(::haxor::context::EngineContext_obj::resize).Add(::haxor::context::EngineContext_obj::resources).Add(::haxor::context::EngineContext_obj::disposables);
		HX_STACK_LINE(125)
		::haxor::context::DataContext _g5 = ::haxor::context::DataContext_obj::__new();		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(125)
		::haxor::context::EngineContext_obj::data = _g5;
		HX_STACK_LINE(130)
		::haxor::component::animation::Animation_obj::Initialize();
		HX_STACK_LINE(132)
		::haxor::context::RendererContext _g6 = ::haxor::context::RendererContext_obj::__new();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(132)
		::haxor::context::EngineContext_obj::renderer = _g6;
		HX_STACK_LINE(133)
		::haxor::context::MeshContext _g7 = ::haxor::context::MeshContext_obj::__new();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(133)
		::haxor::context::EngineContext_obj::mesh = _g7;
		HX_STACK_LINE(134)
		::haxor::context::MaterialContext _g8 = ::haxor::context::MaterialContext_obj::__new();		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(134)
		::haxor::context::EngineContext_obj::material = _g8;
		HX_STACK_LINE(135)
		::haxor::context::TextureContext _g9 = ::haxor::context::TextureContext_obj::__new();		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(135)
		::haxor::context::EngineContext_obj::texture = _g9;
		HX_STACK_LINE(136)
		::haxor::context::GizmoContext _g10 = ::haxor::context::GizmoContext_obj::__new();		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(136)
		::haxor::context::EngineContext_obj::gizmo = _g10;
		HX_STACK_LINE(137)
		::haxor::context::CameraContext _g11 = ::haxor::context::CameraContext_obj::__new();		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(137)
		::haxor::context::EngineContext_obj::camera = _g11;
		HX_STACK_LINE(138)
		::haxor::context::TransformContext _g12 = ::haxor::context::TransformContext_obj::__new();		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(138)
		::haxor::context::EngineContext_obj::transform = _g12;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(EngineContext_obj,Initialize,(void))

Void EngineContext_obj::Build( ){
{
		HX_STACK_FRAME("haxor.context.EngineContext","Build",0x61432de2,"haxor.context.EngineContext.Build","haxor/context/EngineContext.hx",147,0x2d4338be)
		HX_STACK_LINE(149)
		::haxor::context::EngineContext_obj::mesh->Initialize();
		HX_STACK_LINE(150)
		::haxor::context::EngineContext_obj::material->Initialize();
		HX_STACK_LINE(151)
		::haxor::context::EngineContext_obj::texture->Initialize();
		HX_STACK_LINE(152)
		::haxor::context::EngineContext_obj::gizmo->Initialize();
		HX_STACK_LINE(153)
		::haxor::context::EngineContext_obj::transform->Initialize();
		HX_STACK_LINE(154)
		::haxor::context::EngineContext_obj::renderer->Initialize();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(EngineContext_obj,Build,(void))

Void EngineContext_obj::Enable( ::haxor::core::Resource p_resource){
{
		HX_STACK_FRAME("haxor.context.EngineContext","Enable",0xdf77b94f,"haxor.context.EngineContext.Enable","haxor/context/EngineContext.hx",163,0x2d4338be)
		HX_STACK_ARG(p_resource,"p_resource")
		HX_STACK_LINE(164)
		if ((::Std_obj::is(p_resource,hx::ClassOf< ::haxor::core::IUpdateable >()))){
			HX_STACK_LINE(164)
			::haxor::context::EngineContext_obj::update->Add(p_resource);
		}
		HX_STACK_LINE(165)
		if ((::Std_obj::is(p_resource,hx::ClassOf< ::haxor::core::IRenderable >()))){
			HX_STACK_LINE(165)
			::haxor::context::EngineContext_obj::render->Add(p_resource);
		}
		HX_STACK_LINE(166)
		if ((::Std_obj::is(p_resource,hx::ClassOf< ::haxor::core::IResizeable >()))){
			HX_STACK_LINE(166)
			::haxor::context::EngineContext_obj::resize->Add(p_resource);
		}
		HX_STACK_LINE(169)
		if ((::Std_obj::is(p_resource,hx::ClassOf< ::haxor::component::Renderer >()))){
			HX_STACK_LINE(169)
			::haxor::context::EngineContext_obj::renderer->Enable(p_resource);
		}
		HX_STACK_LINE(171)
		if ((::Std_obj::is(p_resource,hx::ClassOf< ::haxor::core::Entity >()))){
			HX_STACK_LINE(173)
			::haxor::core::Entity e = p_resource;		HX_STACK_VAR(e,"e");
			HX_STACK_LINE(174)
			{
				HX_STACK_LINE(174)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(174)
				int _g = e->m_components->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(174)
				while((true)){
					HX_STACK_LINE(174)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(174)
						break;
					}
					HX_STACK_LINE(174)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(176)
					::haxor::component::Component c = e->m_components->__get(i).StaticCast< ::haxor::component::Component >();		HX_STACK_VAR(c,"c");
					HX_STACK_LINE(177)
					if ((::Std_obj::is(c,hx::ClassOf< ::haxor::component::MeshRenderer >()))){
						HX_STACK_LINE(179)
						::haxor::context::EngineContext_obj::renderer->Enable(c);
					}
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(EngineContext_obj,Enable,(void))

Void EngineContext_obj::Disable( ::haxor::core::Resource p_resource){
{
		HX_STACK_FRAME("haxor.context.EngineContext","Disable",0xdc71d19c,"haxor.context.EngineContext.Disable","haxor/context/EngineContext.hx",191,0x2d4338be)
		HX_STACK_ARG(p_resource,"p_resource")
		HX_STACK_LINE(192)
		if ((::Std_obj::is(p_resource,hx::ClassOf< ::haxor::core::IUpdateable >()))){
			HX_STACK_LINE(192)
			::haxor::context::EngineContext_obj::update->Remove(p_resource);
		}
		HX_STACK_LINE(193)
		if ((::Std_obj::is(p_resource,hx::ClassOf< ::haxor::core::IRenderable >()))){
			HX_STACK_LINE(193)
			::haxor::context::EngineContext_obj::render->Remove(p_resource);
		}
		HX_STACK_LINE(194)
		if ((::Std_obj::is(p_resource,hx::ClassOf< ::haxor::core::IResizeable >()))){
			HX_STACK_LINE(194)
			::haxor::context::EngineContext_obj::resize->Remove(p_resource);
		}
		HX_STACK_LINE(195)
		if ((::Std_obj::is(p_resource,hx::ClassOf< ::haxor::component::Renderer >()))){
			HX_STACK_LINE(195)
			::haxor::context::EngineContext_obj::renderer->Disable(p_resource);
		}
		HX_STACK_LINE(196)
		if ((::Std_obj::is(p_resource,hx::ClassOf< ::haxor::core::Entity >()))){
			HX_STACK_LINE(198)
			::haxor::core::Entity e = p_resource;		HX_STACK_VAR(e,"e");
			HX_STACK_LINE(199)
			{
				HX_STACK_LINE(199)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(199)
				int _g = e->m_components->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(199)
				while((true)){
					HX_STACK_LINE(199)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(199)
						break;
					}
					HX_STACK_LINE(199)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(201)
					::haxor::component::Component c = e->m_components->__get(i).StaticCast< ::haxor::component::Component >();		HX_STACK_VAR(c,"c");
					HX_STACK_LINE(202)
					if ((::Std_obj::is(c,hx::ClassOf< ::haxor::component::MeshRenderer >()))){
						HX_STACK_LINE(202)
						::haxor::context::EngineContext_obj::renderer->Disable(c);
					}
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(EngineContext_obj,Disable,(void))

Void EngineContext_obj::OnEntiyLayerChange( ::haxor::core::Entity p_entity,int p_from,int p_to){
{
		HX_STACK_FRAME("haxor.context.EngineContext","OnEntiyLayerChange",0x553c7951,"haxor.context.EngineContext.OnEntiyLayerChange","haxor/context/EngineContext.hx",213,0x2d4338be)
		HX_STACK_ARG(p_entity,"p_entity")
		HX_STACK_ARG(p_from,"p_from")
		HX_STACK_ARG(p_to,"p_to")
		HX_STACK_LINE(214)
		::haxor::core::Entity e = p_entity;		HX_STACK_VAR(e,"e");
		HX_STACK_LINE(215)
		{
			HX_STACK_LINE(215)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(215)
			int _g = e->m_components->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(215)
			while((true)){
				HX_STACK_LINE(215)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(215)
					break;
				}
				HX_STACK_LINE(215)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(217)
				::haxor::component::Component c = e->m_components->__get(i).StaticCast< ::haxor::component::Component >();		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(219)
				if ((::Std_obj::is(c,hx::ClassOf< ::haxor::component::Renderer >()))){
					HX_STACK_LINE(219)
					::haxor::context::EngineContext_obj::renderer->OnLayerChange(c,p_from,p_to);
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(EngineContext_obj,OnEntiyLayerChange,(void))

Void EngineContext_obj::Destroy( ::haxor::core::Resource p_resource){
{
		HX_STACK_FRAME("haxor.context.EngineContext","Destroy",0x4f9f94ae,"haxor.context.EngineContext.Destroy","haxor/context/EngineContext.hx",229,0x2d4338be)
		HX_STACK_ARG(p_resource,"p_resource")
		HX_STACK_LINE(230)
		if ((p_resource->m_destroyed)){
			HX_STACK_LINE(230)
			return null();
		}
		HX_STACK_LINE(231)
		p_resource->m_destroyed = true;
		HX_STACK_LINE(232)
		{
			HX_STACK_LINE(232)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(232)
			int _g = ::haxor::context::EngineContext_obj::list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(232)
			while((true)){
				HX_STACK_LINE(232)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(232)
					break;
				}
				HX_STACK_LINE(232)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(232)
				::haxor::context::EngineContext_obj::list->__get(i).StaticCast< ::haxor::context::BaseProcess >()->Remove(p_resource);
			}
		}
		HX_STACK_LINE(233)
		::haxor::context::EngineContext_obj::disposables->Add(p_resource);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(EngineContext_obj,Destroy,(void))


EngineContext_obj::EngineContext_obj()
{
}

Dynamic EngineContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"uid") ) { return uid; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return list; }
		if (HX_FIELD_EQ(inName,"mesh") ) { return mesh; }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"gizmo") ) { return gizmo; }
		if (HX_FIELD_EQ(inName,"Build") ) { return Build_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update; }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize; }
		if (HX_FIELD_EQ(inName,"render") ) { return render; }
		if (HX_FIELD_EQ(inName,"camera") ) { return camera; }
		if (HX_FIELD_EQ(inName,"Enable") ) { return Enable_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { return texture; }
		if (HX_FIELD_EQ(inName,"Disable") ) { return Disable_dyn(); }
		if (HX_FIELD_EQ(inName,"Destroy") ) { return Destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxNodes") ) { return maxNodes; }
		if (HX_FIELD_EQ(inName,"material") ) { return material; }
		if (HX_FIELD_EQ(inName,"renderer") ) { return renderer; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"resources") ) { return resources; }
		if (HX_FIELD_EQ(inName,"transform") ) { return transform; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"collectRate") ) { return collectRate; }
		if (HX_FIELD_EQ(inName,"disposables") ) { return disposables; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"OnEntiyLayerChange") ) { return OnEntiyLayerChange_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic EngineContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"uid") ) { uid=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mesh") ) { mesh=inValue.Cast< ::haxor::context::MeshContext >(); return inValue; }
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::haxor::context::DataContext >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"gizmo") ) { gizmo=inValue.Cast< ::haxor::context::GizmoContext >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { update=inValue.Cast< ::haxor::context::Process >(); return inValue; }
		if (HX_FIELD_EQ(inName,"resize") ) { resize=inValue.Cast< ::haxor::context::Process >(); return inValue; }
		if (HX_FIELD_EQ(inName,"render") ) { render=inValue.Cast< ::haxor::context::Process >(); return inValue; }
		if (HX_FIELD_EQ(inName,"camera") ) { camera=inValue.Cast< ::haxor::context::CameraContext >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { texture=inValue.Cast< ::haxor::context::TextureContext >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxNodes") ) { maxNodes=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"material") ) { material=inValue.Cast< ::haxor::context::MaterialContext >(); return inValue; }
		if (HX_FIELD_EQ(inName,"renderer") ) { renderer=inValue.Cast< ::haxor::context::RendererContext >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"resources") ) { resources=inValue.Cast< ::haxor::context::Process >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transform") ) { transform=inValue.Cast< ::haxor::context::TransformContext >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"collectRate") ) { collectRate=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"disposables") ) { disposables=inValue.Cast< ::haxor::context::Process >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void EngineContext_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("uid"),
	HX_CSTRING("maxNodes"),
	HX_CSTRING("collectRate"),
	HX_CSTRING("update"),
	HX_CSTRING("resize"),
	HX_CSTRING("render"),
	HX_CSTRING("resources"),
	HX_CSTRING("disposables"),
	HX_CSTRING("list"),
	HX_CSTRING("mesh"),
	HX_CSTRING("material"),
	HX_CSTRING("texture"),
	HX_CSTRING("camera"),
	HX_CSTRING("renderer"),
	HX_CSTRING("gizmo"),
	HX_CSTRING("data"),
	HX_CSTRING("transform"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Build"),
	HX_CSTRING("Enable"),
	HX_CSTRING("Disable"),
	HX_CSTRING("OnEntiyLayerChange"),
	HX_CSTRING("Destroy"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EngineContext_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(EngineContext_obj::uid,"uid");
	HX_MARK_MEMBER_NAME(EngineContext_obj::maxNodes,"maxNodes");
	HX_MARK_MEMBER_NAME(EngineContext_obj::collectRate,"collectRate");
	HX_MARK_MEMBER_NAME(EngineContext_obj::update,"update");
	HX_MARK_MEMBER_NAME(EngineContext_obj::resize,"resize");
	HX_MARK_MEMBER_NAME(EngineContext_obj::render,"render");
	HX_MARK_MEMBER_NAME(EngineContext_obj::resources,"resources");
	HX_MARK_MEMBER_NAME(EngineContext_obj::disposables,"disposables");
	HX_MARK_MEMBER_NAME(EngineContext_obj::list,"list");
	HX_MARK_MEMBER_NAME(EngineContext_obj::mesh,"mesh");
	HX_MARK_MEMBER_NAME(EngineContext_obj::material,"material");
	HX_MARK_MEMBER_NAME(EngineContext_obj::texture,"texture");
	HX_MARK_MEMBER_NAME(EngineContext_obj::camera,"camera");
	HX_MARK_MEMBER_NAME(EngineContext_obj::renderer,"renderer");
	HX_MARK_MEMBER_NAME(EngineContext_obj::gizmo,"gizmo");
	HX_MARK_MEMBER_NAME(EngineContext_obj::data,"data");
	HX_MARK_MEMBER_NAME(EngineContext_obj::transform,"transform");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EngineContext_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::uid,"uid");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::maxNodes,"maxNodes");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::collectRate,"collectRate");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::update,"update");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::resize,"resize");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::render,"render");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::resources,"resources");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::disposables,"disposables");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::list,"list");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::mesh,"mesh");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::material,"material");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::texture,"texture");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::camera,"camera");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::renderer,"renderer");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::gizmo,"gizmo");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::data,"data");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::transform,"transform");
};

#endif

Class EngineContext_obj::__mClass;

void EngineContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.EngineContext"), hx::TCanCast< EngineContext_obj> ,sStaticFields,sMemberFields,
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

void EngineContext_obj::__boot()
{
	uid= (int)0;
	maxNodes= (int)5000;
	collectRate= (int)10;
}

} // end namespace haxor
} // end namespace context
