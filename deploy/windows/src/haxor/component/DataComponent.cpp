#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_DataComponent
#include <haxor/component/DataComponent.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
namespace haxor{
namespace component{

Void DataComponent_obj::__construct()
{
HX_STACK_FRAME("haxor.component.DataComponent","new",0x96b91768,"haxor.component.DataComponent.new","haxor/component/DataComponent.hx",14,0xe8bf5c4a)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(14)
	super::__construct(null());
	HX_STACK_LINE(14)
	::haxe::ds::StringMap _g = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(14)
	this->data = _g;
}
;
	return null();
}

//DataComponent_obj::~DataComponent_obj() { }

Dynamic DataComponent_obj::__CreateEmpty() { return  new DataComponent_obj; }
hx::ObjectPtr< DataComponent_obj > DataComponent_obj::__new()
{  hx::ObjectPtr< DataComponent_obj > result = new DataComponent_obj();
	result->__construct();
	return result;}

Dynamic DataComponent_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< DataComponent_obj > result = new DataComponent_obj();
	result->__construct();
	return result;}


DataComponent_obj::DataComponent_obj()
{
}

void DataComponent_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(DataComponent);
	HX_MARK_MEMBER_NAME(data,"data");
	::haxor::component::Component_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void DataComponent_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(data,"data");
	::haxor::component::Component_obj::__Visit(HX_VISIT_ARG);
}

Dynamic DataComponent_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic DataComponent_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void DataComponent_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Dynamic*/ ,(int)offsetof(DataComponent_obj,data),HX_CSTRING("data")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(DataComponent_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(DataComponent_obj::__mClass,"__mClass");
};

#endif

Class DataComponent_obj::__mClass;

void DataComponent_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.DataComponent"), hx::TCanCast< DataComponent_obj> ,sStaticFields,sMemberFields,
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

void DataComponent_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
