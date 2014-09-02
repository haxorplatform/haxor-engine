#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_Renderer
#include <haxor/component/Renderer.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_RendererContext
#include <haxor/context/RendererContext.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
#endif
namespace haxor{
namespace component{

Void Renderer_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.Renderer","new",0x83675ed2,"haxor.component.Renderer.new","haxor/component/Renderer.hx",13,0x7c4f98dc)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(44)
	this->m_has_mesh = false;
	HX_STACK_LINE(13)
	super::__construct(p_name);
}
;
	return null();
}

//Renderer_obj::~Renderer_obj() { }

Dynamic Renderer_obj::__CreateEmpty() { return  new Renderer_obj; }
hx::ObjectPtr< Renderer_obj > Renderer_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< Renderer_obj > result = new Renderer_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic Renderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Renderer_obj > result = new Renderer_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::graphics::material::Material Renderer_obj::get_material( ){
	HX_STACK_FRAME("haxor.component.Renderer","get_material",0x97f323fe,"haxor.component.Renderer.get_material","haxor/component/Renderer.hx",21,0x7c4f98dc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(21)
	return this->m_material;
}


HX_DEFINE_DYNAMIC_FUNC0(Renderer_obj,get_material,return )

::haxor::graphics::material::Material Renderer_obj::set_material( ::haxor::graphics::material::Material v){
	HX_STACK_FRAME("haxor.component.Renderer","set_material",0xacec4772,"haxor.component.Renderer.set_material","haxor/component/Renderer.hx",23,0x7c4f98dc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(24)
	if (((this->m_material == v))){
		HX_STACK_LINE(24)
		return v;
	}
	HX_STACK_LINE(25)
	this->m_material = v;
	HX_STACK_LINE(26)
	if (((v == null()))){
		HX_STACK_LINE(26)
		this->m_last_queue = (int)-1;
	}
	else{
		HX_STACK_LINE(26)
		this->m_last_queue = v->queue;
	}
	HX_STACK_LINE(27)
	::haxor::context::EngineContext_obj::renderer->OnMaterialChange(hx::ObjectPtr<OBJ_>(this));
	HX_STACK_LINE(28)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Renderer_obj,set_material,return )

bool Renderer_obj::get_visible( ){
	HX_STACK_FRAME("haxor.component.Renderer","get_visible",0x4ef128fb,"haxor.component.Renderer.get_visible","haxor/component/Renderer.hx",36,0x7c4f98dc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(36)
	return (bool(this->m_visible) && bool(!(this->m_culled)));
}


HX_DEFINE_DYNAMIC_FUNC0(Renderer_obj,get_visible,return )

bool Renderer_obj::set_visible( bool v){
	HX_STACK_FRAME("haxor.component.Renderer","set_visible",0x595e3007,"haxor.component.Renderer.set_visible","haxor/component/Renderer.hx",37,0x7c4f98dc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(37)
	this->m_visible = v;
	HX_STACK_LINE(37)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Renderer_obj,set_visible,return )

Void Renderer_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.Renderer","OnBuild",0xb11a50e1,"haxor.component.Renderer.OnBuild","haxor/component/Renderer.hx",55,0x7c4f98dc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(56)
		this->super::OnBuild();
		HX_STACK_LINE(57)
		this->m_last_queue = (int)-1;
		HX_STACK_LINE(58)
		this->m_visible = true;
		HX_STACK_LINE(59)
		this->m_culled = false;
		HX_STACK_LINE(60)
		::haxor::context::EngineContext_obj::renderer->Create(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


Void Renderer_obj::OnRender( ){
{
		HX_STACK_FRAME("haxor.component.Renderer","OnRender",0x7880f243,"haxor.component.Renderer.OnRender","haxor/component/Renderer.hx",67,0x7c4f98dc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(67)
		if (((this->m_material != null()))){
			HX_STACK_LINE(68)
			if (((this->m_last_queue != this->m_material->queue))){
				HX_STACK_LINE(70)
				this->m_last_queue = this->m_material->queue;
				HX_STACK_LINE(71)
				::haxor::context::EngineContext_obj::renderer->OnMaterialChange(hx::ObjectPtr<OBJ_>(this));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Renderer_obj,OnRender,(void))

Void Renderer_obj::UpdateCulling( ){
{
		HX_STACK_FRAME("haxor.component.Renderer","UpdateCulling",0x62436839,"haxor.component.Renderer.UpdateCulling","haxor/component/Renderer.hx",79,0x7c4f98dc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(82)
		bool v0 = this->m_culled;		HX_STACK_VAR(v0,"v0");
		HX_STACK_LINE(83)
		bool v1 = this->CheckCulling();		HX_STACK_VAR(v1,"v1");
		HX_STACK_LINE(84)
		this->m_culled = v1;
		HX_STACK_LINE(86)
		if (((v0 != v1))){
			HX_STACK_LINE(88)
			::haxor::context::EngineContext_obj::renderer->OnVisibilityChange(hx::ObjectPtr<OBJ_>(this),!(v1));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Renderer_obj,UpdateCulling,(void))

bool Renderer_obj::CheckCulling( ){
	HX_STACK_FRAME("haxor.component.Renderer","CheckCulling",0xfb54f9f6,"haxor.component.Renderer.CheckCulling","haxor/component/Renderer.hx",95,0x7c4f98dc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(95)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC0(Renderer_obj,CheckCulling,return )

Void Renderer_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.component.Renderer","OnDestroy",0x9dc4b56d,"haxor.component.Renderer.OnDestroy","haxor/component/Renderer.hx",102,0x7c4f98dc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(102)
		::haxor::context::EngineContext_obj::renderer->Destroy(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}



Renderer_obj::Renderer_obj()
{
}

void Renderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Renderer);
	HX_MARK_MEMBER_NAME(m_material,"m_material");
	HX_MARK_MEMBER_NAME(m_visible,"m_visible");
	HX_MARK_MEMBER_NAME(m_culled,"m_culled");
	HX_MARK_MEMBER_NAME(m_has_mesh,"m_has_mesh");
	HX_MARK_MEMBER_NAME(m_last_queue,"m_last_queue");
	::haxor::component::Component_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Renderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_material,"m_material");
	HX_VISIT_MEMBER_NAME(m_visible,"m_visible");
	HX_VISIT_MEMBER_NAME(m_culled,"m_culled");
	HX_VISIT_MEMBER_NAME(m_has_mesh,"m_has_mesh");
	HX_VISIT_MEMBER_NAME(m_last_queue,"m_last_queue");
	::haxor::component::Component_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Renderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"visible") ) { return get_visible(); }
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"material") ) { return get_material(); }
		if (HX_FIELD_EQ(inName,"m_culled") ) { return m_culled; }
		if (HX_FIELD_EQ(inName,"OnRender") ) { return OnRender_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_visible") ) { return m_visible; }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_material") ) { return m_material; }
		if (HX_FIELD_EQ(inName,"m_has_mesh") ) { return m_has_mesh; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_visible") ) { return get_visible_dyn(); }
		if (HX_FIELD_EQ(inName,"set_visible") ) { return set_visible_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_material") ) { return get_material_dyn(); }
		if (HX_FIELD_EQ(inName,"set_material") ) { return set_material_dyn(); }
		if (HX_FIELD_EQ(inName,"m_last_queue") ) { return m_last_queue; }
		if (HX_FIELD_EQ(inName,"CheckCulling") ) { return CheckCulling_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"UpdateCulling") ) { return UpdateCulling_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Renderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"material") ) { return set_material(inValue); }
		if (HX_FIELD_EQ(inName,"m_culled") ) { m_culled=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_visible") ) { m_visible=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_material") ) { m_material=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_has_mesh") ) { m_has_mesh=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_last_queue") ) { m_last_queue=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Renderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("material"));
	outFields->push(HX_CSTRING("m_material"));
	outFields->push(HX_CSTRING("visible"));
	outFields->push(HX_CSTRING("m_visible"));
	outFields->push(HX_CSTRING("m_culled"));
	outFields->push(HX_CSTRING("m_has_mesh"));
	outFields->push(HX_CSTRING("m_last_queue"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::graphics::material::Material*/ ,(int)offsetof(Renderer_obj,m_material),HX_CSTRING("m_material")},
	{hx::fsBool,(int)offsetof(Renderer_obj,m_visible),HX_CSTRING("m_visible")},
	{hx::fsBool,(int)offsetof(Renderer_obj,m_culled),HX_CSTRING("m_culled")},
	{hx::fsBool,(int)offsetof(Renderer_obj,m_has_mesh),HX_CSTRING("m_has_mesh")},
	{hx::fsInt,(int)offsetof(Renderer_obj,m_last_queue),HX_CSTRING("m_last_queue")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_material"),
	HX_CSTRING("set_material"),
	HX_CSTRING("m_material"),
	HX_CSTRING("get_visible"),
	HX_CSTRING("set_visible"),
	HX_CSTRING("m_visible"),
	HX_CSTRING("m_culled"),
	HX_CSTRING("m_has_mesh"),
	HX_CSTRING("m_last_queue"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("OnRender"),
	HX_CSTRING("UpdateCulling"),
	HX_CSTRING("CheckCulling"),
	HX_CSTRING("OnDestroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Renderer_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Renderer_obj::__mClass,"__mClass");
};

#endif

Class Renderer_obj::__mClass;

void Renderer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.Renderer"), hx::TCanCast< Renderer_obj> ,sStaticFields,sMemberFields,
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

void Renderer_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
