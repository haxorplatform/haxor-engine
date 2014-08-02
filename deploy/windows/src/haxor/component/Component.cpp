#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
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

Void Component_obj::__construct()
{
HX_STACK_FRAME("haxor.component.Component","new",0x57da5272,"haxor.component.Component.new","haxor/component/Component.hx",45,0x10f68780)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(46)
	super::__construct(HX_CSTRING(""));
	HX_STACK_LINE(47)
	this->OnBuild();
}
;
	return null();
}

//Component_obj::~Component_obj() { }

Dynamic Component_obj::__CreateEmpty() { return  new Component_obj; }
hx::ObjectPtr< Component_obj > Component_obj::__new()
{  hx::ObjectPtr< Component_obj > result = new Component_obj();
	result->__construct();
	return result;}

Dynamic Component_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Component_obj > result = new Component_obj();
	result->__construct();
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

Void Component_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.Component","OnBuild",0x259f9481,"haxor.component.Component.OnBuild","haxor/component/Component.hx",53,0x10f68780)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Component_obj,OnBuild,(void))


Component_obj::Component_obj()
{
}

void Component_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Component);
	HX_MARK_MEMBER_NAME(entity,"entity");
	HX_MARK_MEMBER_NAME(m_entity,"m_entity");
	::haxor::core::Resource_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Component_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(entity,"entity");
	HX_VISIT_MEMBER_NAME(m_entity,"m_entity");
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
	case 10:
		if (HX_FIELD_EQ(inName,"get_entity") ) { return get_entity_dyn(); }
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
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Component_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("entity"));
	outFields->push(HX_CSTRING("m_entity"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::core::Entity*/ ,(int)offsetof(Component_obj,entity),HX_CSTRING("entity")},
	{hx::fsObject /*::haxor::core::Entity*/ ,(int)offsetof(Component_obj,m_entity),HX_CSTRING("m_entity")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_name"),
	HX_CSTRING("set_name"),
	HX_CSTRING("entity"),
	HX_CSTRING("get_entity"),
	HX_CSTRING("m_entity"),
	HX_CSTRING("OnBuild"),
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
