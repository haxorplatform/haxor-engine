#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Type
#include <Type.h>
#endif
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_component_animation_Animation
#include <haxor/component/animation/Animation.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
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

Void Entity_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.core.Entity","new",0x37b4da38,"haxor.core.Entity.new","haxor/core/Entity.hx",79,0x47bf6bd8)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(81)
	super::__construct(p_name);
	HX_STACK_LINE(82)
	this->m_enabled = true;
	HX_STACK_LINE(83)
	this->m_components = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(84)
	this->m_layer = (int)1;
	HX_STACK_LINE(87)
	::haxor::component::Transform _g = this->AddComponent(hx::ClassOf< ::haxor::component::Transform >());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(87)
	this->m_transform = _g;
}
;
	return null();
}

//Entity_obj::~Entity_obj() { }

Dynamic Entity_obj::__CreateEmpty() { return  new Entity_obj; }
hx::ObjectPtr< Entity_obj > Entity_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< Entity_obj > result = new Entity_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic Entity_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Entity_obj > result = new Entity_obj();
	result->__construct(inArgs[0]);
	return result;}

bool Entity_obj::get_enabled( ){
	HX_STACK_FRAME("haxor.core.Entity","get_enabled",0x7cee0670,"haxor.core.Entity.get_enabled","haxor/core/Entity.hx",20,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(20)
	return (bool(this->m_enabled) && bool(!(this->m_destroyed)));
}


HX_DEFINE_DYNAMIC_FUNC0(Entity_obj,get_enabled,return )

bool Entity_obj::set_enabled( bool v){
	HX_STACK_FRAME("haxor.core.Entity","set_enabled",0x875b0d7c,"haxor.core.Entity.set_enabled","haxor/core/Entity.hx",22,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(23)
	if ((this->m_destroyed)){
		HX_STACK_LINE(23)
		return false;
	}
	HX_STACK_LINE(24)
	if (((this->m_enabled == v))){
		HX_STACK_LINE(24)
		return v;
	}
	HX_STACK_LINE(25)
	this->m_enabled = v;
	HX_STACK_LINE(26)
	{
		HX_STACK_LINE(26)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(26)
		int _g = this->m_components->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(26)
		while((true)){
			HX_STACK_LINE(26)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(26)
				break;
			}
			HX_STACK_LINE(26)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(28)
			::haxor::component::Component c = this->m_components->__get(i).StaticCast< ::haxor::component::Component >();		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(29)
			if ((c->m_is_behaviour)){
				HX_STACK_LINE(31)
				::haxor::component::Behaviour b = c;		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(32)
				b->set_enabled(v);
			}
		}
	}
	HX_STACK_LINE(35)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Entity_obj,set_enabled,return )

::haxor::component::Transform Entity_obj::get_transform( ){
	HX_STACK_FRAME("haxor.core.Entity","get_transform",0x2f07c91b,"haxor.core.Entity.get_transform","haxor/core/Entity.hx",43,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(43)
	return this->m_transform;
}


HX_DEFINE_DYNAMIC_FUNC0(Entity_obj,get_transform,return )

::haxor::component::animation::Animation Entity_obj::get_animation( ){
	HX_STACK_FRAME("haxor.core.Entity","get_animation",0x34a98ab3,"haxor.core.Entity.get_animation","haxor/core/Entity.hx",50,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(50)
	return this->m_animation;
}


HX_DEFINE_DYNAMIC_FUNC0(Entity_obj,get_animation,return )

int Entity_obj::get_layer( ){
	HX_STACK_FRAME("haxor.core.Entity","get_layer",0x80d3da00,"haxor.core.Entity.get_layer","haxor/core/Entity.hx",57,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_LINE(57)
	return this->m_layer;
}


HX_DEFINE_DYNAMIC_FUNC0(Entity_obj,get_layer,return )

int Entity_obj::set_layer( int v){
	HX_STACK_FRAME("haxor.core.Entity","set_layer",0x6424c60c,"haxor.core.Entity.set_layer","haxor/core/Entity.hx",59,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(60)
	if (((v <= (int)0))){
		HX_STACK_LINE(60)
		v = (int)1;
	}
	HX_STACK_LINE(61)
	if (((this->m_layer == v))){
		HX_STACK_LINE(61)
		return v;
	}
	HX_STACK_LINE(62)
	int ll = this->m_layer;		HX_STACK_VAR(ll,"ll");
	HX_STACK_LINE(63)
	this->m_layer = v;
	HX_STACK_LINE(64)
	::haxor::context::EngineContext_obj::OnEntiyLayerChange(hx::ObjectPtr<OBJ_>(this),ll,this->m_layer);
	HX_STACK_LINE(65)
	return this->m_layer;
}


HX_DEFINE_DYNAMIC_FUNC1(Entity_obj,set_layer,return )

Dynamic Entity_obj::AddComponent( ::Class p_type){
	HX_STACK_FRAME("haxor.core.Entity","AddComponent",0x084559a4,"haxor.core.Entity.AddComponent","haxor/core/Entity.hx",99,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(100)
	if ((this->m_destroyed)){
		HX_STACK_LINE(100)
		return null();
	}
	HX_STACK_LINE(102)
	if (((this->m_transform != null()))){
		HX_STACK_LINE(102)
		if (((p_type == hx::ClassOf< ::haxor::component::Transform >()))){
			HX_STACK_LINE(102)
			return this->m_transform;
		}
		else{
			HX_STACK_LINE(103)
			if (((this->m_animation != null()))){
				HX_STACK_LINE(103)
				if (((p_type == hx::ClassOf< ::haxor::component::animation::Animation >()))){
					HX_STACK_LINE(103)
					return this->m_animation;
				}
			}
		}
	}
	HX_STACK_LINE(105)
	::haxor::component::Component c = null();		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(106)
	::haxor::component::Component _g = ::Type_obj::createInstance(p_type,Dynamic( Array_obj<Dynamic>::__new().Add(HX_CSTRING(""))));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(106)
	c = _g;
	HX_STACK_LINE(107)
	if (((c == null()))){
		HX_STACK_LINE(107)
		return null();
	}
	HX_STACK_LINE(108)
	c->m_entity = hx::ObjectPtr<OBJ_>(this);
	HX_STACK_LINE(110)
	if (((p_type == hx::ClassOf< ::haxor::component::animation::Animation >()))){
		HX_STACK_LINE(110)
		this->m_animation = c;
	}
	HX_STACK_LINE(112)
	if ((c->m_is_behaviour)){
		HX_STACK_LINE(114)
		::haxor::component::Behaviour b = c;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(115)
		b->set_enabled((bool(this->m_enabled) && bool(!(this->m_destroyed))));
	}
	HX_STACK_LINE(117)
	c->OnBuild();
	HX_STACK_LINE(118)
	this->m_components->push(c);
	HX_STACK_LINE(119)
	return c;
}


HX_DEFINE_DYNAMIC_FUNC1(Entity_obj,AddComponent,return )

Dynamic Entity_obj::GetComponent( ::Class p_type){
	HX_STACK_FRAME("haxor.core.Entity","GetComponent",0x1847d48f,"haxor.core.Entity.GetComponent","haxor/core/Entity.hx",128,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(129)
	{
		HX_STACK_LINE(129)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(129)
		int _g = this->m_components->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(129)
		while((true)){
			HX_STACK_LINE(129)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(129)
				break;
			}
			HX_STACK_LINE(129)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(129)
			if ((::Std_obj::is(this->m_components->__get(i).StaticCast< ::haxor::component::Component >(),p_type))){
				HX_STACK_LINE(129)
				return this->m_components->__get(i).StaticCast< ::haxor::component::Component >();
			}
		}
	}
	HX_STACK_LINE(130)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Entity_obj,GetComponent,return )

Dynamic Entity_obj::GetComponents( ::Class p_type){
	HX_STACK_FRAME("haxor.core.Entity","GetComponents",0x26922904,"haxor.core.Entity.GetComponents","haxor/core/Entity.hx",139,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(140)
	Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(141)
	{
		HX_STACK_LINE(141)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(141)
		int _g = this->m_components->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(141)
		while((true)){
			HX_STACK_LINE(141)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(141)
				break;
			}
			HX_STACK_LINE(141)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(141)
			if ((::Std_obj::is(this->m_components->__get(i).StaticCast< ::haxor::component::Component >(),p_type))){
				HX_STACK_LINE(141)
				res->push(this->m_components->__get(i).StaticCast< ::haxor::component::Component >());
			}
		}
	}
	HX_STACK_LINE(142)
	return res;
}


HX_DEFINE_DYNAMIC_FUNC1(Entity_obj,GetComponents,return )

Dynamic Entity_obj::GetComponentInChildren( ::Class p_type){
	HX_STACK_FRAME("haxor.core.Entity","GetComponentInChildren",0xc729dfb3,"haxor.core.Entity.GetComponentInChildren","haxor/core/Entity.hx",150,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(150)
	Array< ::Dynamic > p_type1 = Array_obj< ::Dynamic >::__new().Add(p_type);		HX_STACK_VAR(p_type1,"p_type1");
	HX_STACK_LINE(152)
	Array< ::Dynamic > res = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(res,"res");
	HX_STACK_LINE(153)
	Array< ::Dynamic > res1 = Array_obj< ::Dynamic >::__new().Add(null());		HX_STACK_VAR(res1,"res1");

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,res1,Array< ::Dynamic >,p_type1)
	bool run(::haxor::component::Transform t,int d){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/core/Entity.hx",155,0x47bf6bd8)
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(d,"d")
		{
			HX_STACK_LINE(156)
			if (((res1->__get((int)0).StaticCast< ::haxor::component::Component >() != null()))){
				HX_STACK_LINE(156)
				return true;
			}
			HX_STACK_LINE(157)
			Dynamic l = t->m_entity->GetComponents(p_type1->__get((int)0).StaticCast< ::Class >());		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(158)
			if (((l->__Field(HX_CSTRING("length"),true) > (int)0))){
				HX_STACK_LINE(158)
				res1[(int)0] = l->__GetItem((int)0);
				HX_STACK_LINE(158)
				return true;
			}
			HX_STACK_LINE(159)
			return true;
		}
		return null();
	}
	HX_END_LOCAL_FUNC2(return)

	HX_STACK_LINE(154)
	this->m_transform->Traverse( Dynamic(new _Function_1_1(res1,p_type1)));
	HX_STACK_LINE(161)
	return res1->__get((int)0).StaticCast< ::haxor::component::Component >();
}


HX_DEFINE_DYNAMIC_FUNC1(Entity_obj,GetComponentInChildren,return )

Dynamic Entity_obj::GetComponentsInChildren( ::Class p_type){
	HX_STACK_FRAME("haxor.core.Entity","GetComponentsInChildren",0x36cc3868,"haxor.core.Entity.GetComponentsInChildren","haxor/core/Entity.hx",169,0x47bf6bd8)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(169)
	Array< ::Dynamic > p_type1 = Array_obj< ::Dynamic >::__new().Add(p_type);		HX_STACK_VAR(p_type1,"p_type1");
	HX_STACK_LINE(171)
	Dynamic res = Dynamic( Array_obj<Dynamic>::__new().Add(Dynamic( Array_obj<Dynamic>::__new())));		HX_STACK_VAR(res,"res");

	HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Dynamic,res,Array< ::Dynamic >,p_type1)
	bool run(::haxor::component::Transform t,int d){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/core/Entity.hx",173,0x47bf6bd8)
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(d,"d")
		{
			HX_STACK_LINE(174)
			Dynamic l = t->m_entity->GetComponents(p_type1->__get((int)0).StaticCast< ::Class >());		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(175)
			{
				HX_STACK_LINE(175)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(175)
				int _g = l->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(175)
				while(((_g1 < _g))){
					HX_STACK_LINE(175)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(175)
					res->__GetItem((int)0)->__Field(HX_CSTRING("push"),true)(l->__GetItem(i));
				}
			}
			HX_STACK_LINE(176)
			return true;
		}
		return null();
	}
	HX_END_LOCAL_FUNC2(return)

	HX_STACK_LINE(172)
	this->m_transform->Traverse( Dynamic(new _Function_1_1(res,p_type1)));
	HX_STACK_LINE(178)
	return res->__GetItem((int)0);
}


HX_DEFINE_DYNAMIC_FUNC1(Entity_obj,GetComponentsInChildren,return )

Void Entity_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.core.Entity","OnDestroy",0x6b6dc153,"haxor.core.Entity.OnDestroy","haxor/core/Entity.hx",185,0x47bf6bd8)
		HX_STACK_THIS(this)
		HX_STACK_LINE(186)
		{
			HX_STACK_LINE(186)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(186)
			int _g = this->m_components->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(186)
			while((true)){
				HX_STACK_LINE(186)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(186)
					break;
				}
				HX_STACK_LINE(186)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(188)
				this->m_components->__get(i).StaticCast< ::haxor::component::Component >()->OnDestroy();
			}
		}
		HX_STACK_LINE(190)
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
	HX_MARK_MEMBER_NAME(transform,"transform");
	HX_MARK_MEMBER_NAME(m_transform,"m_transform");
	HX_MARK_MEMBER_NAME(animation,"animation");
	HX_MARK_MEMBER_NAME(m_animation,"m_animation");
	HX_MARK_MEMBER_NAME(m_layer,"m_layer");
	HX_MARK_MEMBER_NAME(m_components,"m_components");
	::haxor::core::Resource_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Entity_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_enabled,"m_enabled");
	HX_VISIT_MEMBER_NAME(transform,"transform");
	HX_VISIT_MEMBER_NAME(m_transform,"m_transform");
	HX_VISIT_MEMBER_NAME(animation,"animation");
	HX_VISIT_MEMBER_NAME(m_animation,"m_animation");
	HX_VISIT_MEMBER_NAME(m_layer,"m_layer");
	HX_VISIT_MEMBER_NAME(m_components,"m_components");
	::haxor::core::Resource_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Entity_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"layer") ) { return get_layer(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return get_enabled(); }
		if (HX_FIELD_EQ(inName,"m_layer") ) { return m_layer; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_enabled") ) { return m_enabled; }
		if (HX_FIELD_EQ(inName,"transform") ) { return inCallProp ? get_transform() : transform; }
		if (HX_FIELD_EQ(inName,"animation") ) { return inCallProp ? get_animation() : animation; }
		if (HX_FIELD_EQ(inName,"get_layer") ) { return get_layer_dyn(); }
		if (HX_FIELD_EQ(inName,"set_layer") ) { return set_layer_dyn(); }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_enabled") ) { return get_enabled_dyn(); }
		if (HX_FIELD_EQ(inName,"set_enabled") ) { return set_enabled_dyn(); }
		if (HX_FIELD_EQ(inName,"m_transform") ) { return m_transform; }
		if (HX_FIELD_EQ(inName,"m_animation") ) { return m_animation; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"m_components") ) { return m_components; }
		if (HX_FIELD_EQ(inName,"AddComponent") ) { return AddComponent_dyn(); }
		if (HX_FIELD_EQ(inName,"GetComponent") ) { return GetComponent_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_transform") ) { return get_transform_dyn(); }
		if (HX_FIELD_EQ(inName,"get_animation") ) { return get_animation_dyn(); }
		if (HX_FIELD_EQ(inName,"GetComponents") ) { return GetComponents_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"GetComponentInChildren") ) { return GetComponentInChildren_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"GetComponentsInChildren") ) { return GetComponentsInChildren_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Entity_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"layer") ) { return set_layer(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return set_enabled(inValue); }
		if (HX_FIELD_EQ(inName,"m_layer") ) { m_layer=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_enabled") ) { m_enabled=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"transform") ) { transform=inValue.Cast< ::haxor::component::Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"animation") ) { animation=inValue.Cast< ::haxor::component::animation::Animation >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_transform") ) { m_transform=inValue.Cast< ::haxor::component::Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_animation") ) { m_animation=inValue.Cast< ::haxor::component::animation::Animation >(); return inValue; }
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
	outFields->push(HX_CSTRING("transform"));
	outFields->push(HX_CSTRING("m_transform"));
	outFields->push(HX_CSTRING("animation"));
	outFields->push(HX_CSTRING("m_animation"));
	outFields->push(HX_CSTRING("layer"));
	outFields->push(HX_CSTRING("m_layer"));
	outFields->push(HX_CSTRING("m_components"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Entity_obj,m_enabled),HX_CSTRING("m_enabled")},
	{hx::fsObject /*::haxor::component::Transform*/ ,(int)offsetof(Entity_obj,transform),HX_CSTRING("transform")},
	{hx::fsObject /*::haxor::component::Transform*/ ,(int)offsetof(Entity_obj,m_transform),HX_CSTRING("m_transform")},
	{hx::fsObject /*::haxor::component::animation::Animation*/ ,(int)offsetof(Entity_obj,animation),HX_CSTRING("animation")},
	{hx::fsObject /*::haxor::component::animation::Animation*/ ,(int)offsetof(Entity_obj,m_animation),HX_CSTRING("m_animation")},
	{hx::fsInt,(int)offsetof(Entity_obj,m_layer),HX_CSTRING("m_layer")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Entity_obj,m_components),HX_CSTRING("m_components")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_enabled"),
	HX_CSTRING("set_enabled"),
	HX_CSTRING("m_enabled"),
	HX_CSTRING("transform"),
	HX_CSTRING("get_transform"),
	HX_CSTRING("m_transform"),
	HX_CSTRING("animation"),
	HX_CSTRING("get_animation"),
	HX_CSTRING("m_animation"),
	HX_CSTRING("get_layer"),
	HX_CSTRING("set_layer"),
	HX_CSTRING("m_layer"),
	HX_CSTRING("m_components"),
	HX_CSTRING("AddComponent"),
	HX_CSTRING("GetComponent"),
	HX_CSTRING("GetComponents"),
	HX_CSTRING("GetComponentInChildren"),
	HX_CSTRING("GetComponentsInChildren"),
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
