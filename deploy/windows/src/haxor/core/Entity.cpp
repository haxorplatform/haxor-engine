#include <hxcpp.h>

#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
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
namespace core{

Void Entity_obj::__construct(::String p_name)
{
HX_STACK_FRAME("haxor.core.Entity","new",0x37b4da38,"haxor.core.Entity.new","haxor/core/Entity.hx",46,0x47bf6bd8)
HX_STACK_THIS(this)
HX_STACK_ARG(p_name,"p_name")
{
	HX_STACK_LINE(47)
	super::__construct(p_name);
	HX_STACK_LINE(48)
	this->m_enabled = true;
	HX_STACK_LINE(49)
	this->m_components = Array_obj< ::Dynamic >::__new();
}
;
	return null();
}

//Entity_obj::~Entity_obj() { }

Dynamic Entity_obj::__CreateEmpty() { return  new Entity_obj; }
hx::ObjectPtr< Entity_obj > Entity_obj::__new(::String p_name)
{  hx::ObjectPtr< Entity_obj > result = new Entity_obj();
	result->__construct(p_name);
	return result;}

Dynamic Entity_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Entity_obj > result = new Entity_obj();
	result->__construct(inArgs[0]);
	return result;}

bool Entity_obj::get_enabled( ){
	HX_STACK_FRAME("haxor.core.Entity","get_enabled",0x7cee0670,"haxor.core.Entity.get_enabled","haxor/core/Entity.hx",17,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(17)
	return (bool(this->m_enabled) && bool(!(this->m_destroyed)));
}


HX_DEFINE_DYNAMIC_FUNC0(Entity_obj,get_enabled,return )

bool Entity_obj::set_enabled( bool v){
	HX_STACK_FRAME("haxor.core.Entity","set_enabled",0x875b0d7c,"haxor.core.Entity.set_enabled","haxor/core/Entity.hx",19,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(20)
	if ((this->m_destroyed)){
		HX_STACK_LINE(20)
		return false;
	}
	HX_STACK_LINE(21)
	if (((this->m_enabled == v))){
		HX_STACK_LINE(21)
		return v;
	}
	HX_STACK_LINE(22)
	this->m_enabled = v;
	HX_STACK_LINE(23)
	{
		HX_STACK_LINE(23)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(23)
		int _g = this->m_components->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(23)
		while((true)){
			HX_STACK_LINE(23)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(23)
				break;
			}
			HX_STACK_LINE(23)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(25)
			::haxor::component::Component c = this->m_components->__get(i).StaticCast< ::haxor::component::Component >();		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(26)
			if ((c->m_is_behaviour)){
				HX_STACK_LINE(28)
				::haxor::component::Behaviour b = c;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(29)
				b->set_enabled(v);
			}
		}
	}
	HX_STACK_LINE(32)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Entity_obj,set_enabled,return )

Dynamic Entity_obj::AddComponent( ::Class p_type){
	HX_STACK_FRAME("haxor.core.Entity","AddComponent",0x084559a4,"haxor.core.Entity.AddComponent","haxor/core/Entity.hx",58,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(59)
	if ((this->m_destroyed)){
		HX_STACK_LINE(59)
		return null();
	}
	HX_STACK_LINE(60)
	::haxor::component::Component c = ::Type_obj::createInstance(p_type,Dynamic( Array_obj<Dynamic>::__new()));		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(61)
	c->m_entity = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(62)
	if ((c->m_is_behaviour)){
		HX_STACK_LINE(64)
		::haxor::component::Behaviour b = c;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(65)
		b->set_enabled((bool(this->m_enabled) && bool(!(this->m_destroyed))));
	}
	HX_STACK_LINE(67)
	this->m_components->push(c);
	HX_STACK_LINE(68)
	return c;
}


HX_DEFINE_DYNAMIC_FUNC1(Entity_obj,AddComponent,return )

Void Entity_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.core.Entity","OnDestroy",0x6b6dc153,"haxor.core.Entity.OnDestroy","haxor/core/Entity.hx",75,0x47bf6bd8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(76)
		{
			HX_STACK_LINE(76)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(76)
			int _g = this->m_components->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(76)
			while((true)){
				HX_STACK_LINE(76)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(76)
					break;
				}
				HX_STACK_LINE(76)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(78)
				this->m_components->__get(i).StaticCast< ::haxor::component::Component >()->OnDestroy();
			}
		}
		HX_STACK_LINE(80)
		this->m_components = null();
	}
return null();
}



Entity_obj::Entity_obj()
{
}

void Entity_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Entity);
	HX_MARK_MEMBER_NAME(m_enabled,"m_enabled");
	HX_MARK_MEMBER_NAME(m_components,"m_components");
	::haxor::core::Resource_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Entity_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_enabled,"m_enabled");
	HX_VISIT_MEMBER_NAME(m_components,"m_components");
	::haxor::core::Resource_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Entity_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return get_enabled(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_enabled") ) { return m_enabled; }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_enabled") ) { return get_enabled_dyn(); }
		if (HX_FIELD_EQ(inName,"set_enabled") ) { return set_enabled_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_components") ) { return m_components; }
		if (HX_FIELD_EQ(inName,"AddComponent") ) { return AddComponent_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Entity_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return set_enabled(inValue); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_enabled") ) { m_enabled=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_components") ) { m_components=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Entity_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("enabled"));
	outFields->push(HX_CSTRING("m_enabled"));
	outFields->push(HX_CSTRING("m_components"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Entity_obj,m_enabled),HX_CSTRING("m_enabled")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Entity_obj,m_components),HX_CSTRING("m_components")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_enabled"),
	HX_CSTRING("set_enabled"),
	HX_CSTRING("m_enabled"),
	HX_CSTRING("m_components"),
	HX_CSTRING("AddComponent"),
	HX_CSTRING("OnDestroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Entity_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Entity_obj::__mClass,"__mClass");
};

#endif

Class Entity_obj::__mClass;

void Entity_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.Entity"), hx::TCanCast< Entity_obj> ,sStaticFields,sMemberFields,
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

void Entity_obj::__boot()
{
}

} // end namespace haxor
} // end namespace core
