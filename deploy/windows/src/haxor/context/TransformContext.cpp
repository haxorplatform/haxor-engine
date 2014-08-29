#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_context_TransformContext
#include <haxor/context/TransformContext.h>
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
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
namespace haxor{
namespace context{

Void TransformContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.TransformContext","new",0xd328a300,"haxor.context.TransformContext.new","haxor/context/TransformContext.hx",23,0x797e3cae)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(24)
	::haxor::context::UID _g = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(24)
	this->tid = _g;
}
;
	return null();
}

//TransformContext_obj::~TransformContext_obj() { }

Dynamic TransformContext_obj::__CreateEmpty() { return  new TransformContext_obj; }
hx::ObjectPtr< TransformContext_obj > TransformContext_obj::__new()
{  hx::ObjectPtr< TransformContext_obj > result = new TransformContext_obj();
	result->__construct();
	return result;}

Dynamic TransformContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TransformContext_obj > result = new TransformContext_obj();
	result->__construct();
	return result;}

Void TransformContext_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.context.TransformContext","Initialize",0xf43cf6d0,"haxor.context.TransformContext.Initialize","haxor/context/TransformContext.hx",31,0x797e3cae)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TransformContext_obj,Initialize,(void))

Void TransformContext_obj::OnChange( ::haxor::component::Transform t){
{
		HX_STACK_FRAME("haxor.context.TransformContext","OnChange",0xc85ced6f,"haxor.context.TransformContext.OnChange","haxor/context/TransformContext.hx",40,0x797e3cae)
		HX_STACK_THIS(this)
		HX_STACK_ARG(t,"t")
		HX_STACK_LINE(41)
		t->m_uniform_dirty = true;
		HX_STACK_LINE(42)
		Array< ::Dynamic > cl = t->m_entity->m_components;		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(43)
		{
			HX_STACK_LINE(43)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(43)
			int _g = cl->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(43)
			while((true)){
				HX_STACK_LINE(43)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(43)
					break;
				}
				HX_STACK_LINE(43)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(43)
				cl->__get(i).StaticCast< ::haxor::component::Component >()->OnTransformUpdate();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TransformContext_obj,OnChange,(void))


TransformContext_obj::TransformContext_obj()
{
}

void TransformContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TransformContext);
	HX_MARK_MEMBER_NAME(tid,"tid");
	HX_MARK_END_CLASS();
}

void TransformContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(tid,"tid");
}

Dynamic TransformContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"tid") ) { return tid; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"OnChange") ) { return OnChange_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TransformContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"tid") ) { tid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TransformContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tid"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(TransformContext_obj,tid),HX_CSTRING("tid")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("tid"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("OnChange"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TransformContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TransformContext_obj::__mClass,"__mClass");
};

#endif

Class TransformContext_obj::__mClass;

void TransformContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.TransformContext"), hx::TCanCast< TransformContext_obj> ,sStaticFields,sMemberFields,
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

void TransformContext_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
