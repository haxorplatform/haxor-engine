#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
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
namespace haxor{
namespace component{

Void Component_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.Component","new",0x57da5272,"haxor.component.Component.new","haxor/component/Component.hx",14,0x10f68780)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(14)
	super::__construct(p_name);
}
;
	return null();
}

//Component_obj::~Component_obj() { }

Dynamic Component_obj::__CreateEmpty() { return  new Component_obj; }
hx::ObjectPtr< Component_obj > Component_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< Component_obj > result = new Component_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic Component_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Component_obj > result = new Component_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Component_obj::get_name( ){
	HX_STACK_FRAME("haxor.component.Component","get_name",0x02c8ea82,"haxor.component.Component.get_name","haxor/component/Component.hx",21,0x10f68780)
	HX_STACK_THIS(this)
	HX_STACK_LINE(21)
	return this->m_entity->get_name();
}


::String Component_obj::set_name( ::String v){
	HX_STACK_FRAME("haxor.component.Component","set_name",0xb12643f6,"haxor.component.Component.set_name","haxor/component/Component.hx",27,0x10f68780)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(27)
	this->m_entity->set_name(v);
	HX_STACK_LINE(27)
	return v;
}


::haxor::core::Entity Component_obj::get_entity( ){
	HX_STACK_FRAME("haxor.component.Component","get_entity",0xde5d471a,"haxor.component.Component.get_entity","haxor/component/Component.hx",33,0x10f68780)
	HX_STACK_THIS(this)
	HX_STACK_LINE(33)
	return this->m_entity;
}


HX_DEFINE_DYNAMIC_FUNC0(Component_obj,get_entity,return )

::haxor::component::Transform Component_obj::get_transform( ){
	HX_STACK_FRAME("haxor.component.Component","get_transform",0x44178dd5,"haxor.component.Component.get_transform","haxor/component/Component.hx",40,0x10f68780)
	HX_STACK_THIS(this)
	HX_STACK_LINE(40)
	return this->m_entity->m_transform;
}


HX_DEFINE_DYNAMIC_FUNC0(Component_obj,get_transform,return )

Dynamic Component_obj::AddComponent( ::Class p_type){
	HX_STACK_FRAME("haxor.component.Component","AddComponent",0xb4900a2a,"haxor.component.Component.AddComponent","haxor/component/Component.hx",48,0x10f68780)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(48)
	return this->m_entity->AddComponent(p_type);
}


HX_DEFINE_DYNAMIC_FUNC1(Component_obj,AddComponent,return )

Dynamic Component_obj::GetComponent( ::Class p_type){
	HX_STACK_FRAME("haxor.component.Component","GetComponent",0xc4928515,"haxor.component.Component.GetComponent","haxor/component/Component.hx",55,0x10f68780)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(55)
	return this->m_entity->GetComponent(p_type);
}


HX_DEFINE_DYNAMIC_FUNC1(Component_obj,GetComponent,return )

Dynamic Component_obj::GetComponents( ::Class p_type){
	HX_STACK_FRAME("haxor.component.Component","GetComponents",0x3ba1edbe,"haxor.component.Component.GetComponents","haxor/component/Component.hx",62,0x10f68780)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(62)
	return this->m_entity->GetComponents(p_type);
}


HX_DEFINE_DYNAMIC_FUNC1(Component_obj,GetComponents,return )

Dynamic Component_obj::GetComponentInChildren( ::Class p_type){
	HX_STACK_FRAME("haxor.component.Component","GetComponentInChildren",0xd21cb3b9,"haxor.component.Component.GetComponentInChildren","haxor/component/Component.hx",69,0x10f68780)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(69)
	return this->m_entity->GetComponentInChildren(p_type);
}


HX_DEFINE_DYNAMIC_FUNC1(Component_obj,GetComponentInChildren,return )

Dynamic Component_obj::GetComponentsInChildren( ::Class p_type){
	HX_STACK_FRAME("haxor.component.Component","GetComponentsInChildren",0xc052e9a2,"haxor.component.Component.GetComponentsInChildren","haxor/component/Component.hx",76,0x10f68780)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(76)
	return this->m_entity->GetComponentsInChildren(p_type);
}


HX_DEFINE_DYNAMIC_FUNC1(Component_obj,GetComponentsInChildren,return )

Void Component_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.Component","OnBuild",0x259f9481,"haxor.component.Component.OnBuild","haxor/component/Component.hx",81,0x10f68780)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Component_obj,OnBuild,(void))

Void Component_obj::OnTransformUpdate( ){
{
		HX_STACK_FRAME("haxor.component.Component","OnTransformUpdate",0x99adbfa8,"haxor.component.Component.OnTransformUpdate","haxor/component/Component.hx",86,0x10f68780)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Component_obj,OnTransformUpdate,(void))

Void Component_obj::OnVisibilityChange( bool p_visible){
{
		HX_STACK_FRAME("haxor.component.Component","OnVisibilityChange",0xb5c44e6f,"haxor.component.Component.OnVisibilityChange","haxor/component/Component.hx",91,0x10f68780)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_visible,"p_visible")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Component_obj,OnVisibilityChange,(void))


Component_obj::Component_obj()
{
}

void Component_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Component);
	HX_MARK_MEMBER_NAME(entity,"entity");
	HX_MARK_MEMBER_NAME(m_entity,"m_entity");
	HX_MARK_MEMBER_NAME(transform,"transform");
	::haxor::core::Resource_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Component_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(entity,"entity");
	HX_VISIT_MEMBER_NAME(m_entity,"m_entity");
	HX_VISIT_MEMBER_NAME(transform,"transform");
	::haxor::core::Resource_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Component_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"entity") ) { return inCallProp ? get_entity() : entity; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_name") ) { return get_name_dyn(); }
		if (HX_FIELD_EQ(inName,"set_name") ) { return set_name_dyn(); }
		if (HX_FIELD_EQ(inName,"m_entity") ) { return m_entity; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { return inCallProp ? get_transform() : transform; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_entity") ) { return get_entity_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"AddComponent") ) { return AddComponent_dyn(); }
		if (HX_FIELD_EQ(inName,"GetComponent") ) { return GetComponent_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_transform") ) { return get_transform_dyn(); }
		if (HX_FIELD_EQ(inName,"GetComponents") ) { return GetComponents_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"OnTransformUpdate") ) { return OnTransformUpdate_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"OnVisibilityChange") ) { return OnVisibilityChange_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"GetComponentInChildren") ) { return GetComponentInChildren_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"GetComponentsInChildren") ) { return GetComponentsInChildren_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Component_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"entity") ) { entity=inValue.Cast< ::haxor::core::Entity >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_entity") ) { m_entity=inValue.Cast< ::haxor::core::Entity >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { transform=inValue.Cast< ::haxor::component::Transform >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Component_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("entity"));
	outFields->push(HX_CSTRING("m_entity"));
	outFields->push(HX_CSTRING("transform"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::core::Entity*/ ,(int)offsetof(Component_obj,entity),HX_CSTRING("entity")},
	{hx::fsObject /*::haxor::core::Entity*/ ,(int)offsetof(Component_obj,m_entity),HX_CSTRING("m_entity")},
	{hx::fsObject /*::haxor::component::Transform*/ ,(int)offsetof(Component_obj,transform),HX_CSTRING("transform")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_name"),
	HX_CSTRING("set_name"),
	HX_CSTRING("entity"),
	HX_CSTRING("get_entity"),
	HX_CSTRING("m_entity"),
	HX_CSTRING("transform"),
	HX_CSTRING("get_transform"),
	HX_CSTRING("AddComponent"),
	HX_CSTRING("GetComponent"),
	HX_CSTRING("GetComponents"),
	HX_CSTRING("GetComponentInChildren"),
	HX_CSTRING("GetComponentsInChildren"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("OnTransformUpdate"),
	HX_CSTRING("OnVisibilityChange"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Component_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Component_obj::__mClass,"__mClass");
};

#endif

Class Component_obj::__mClass;

void Component_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.Component"), hx::TCanCast< Component_obj> ,sStaticFields,sMemberFields,
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

void Component_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
