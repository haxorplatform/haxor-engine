#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_RendererContext
#include <haxor/context/RendererContext.h>
#endif
#ifndef INCLUDED_haxor_context_UID
#include <haxor/context/UID.h>
#endif
#ifndef INCLUDED_haxor_core_RenderStats
#include <haxor/core/RenderStats.h>
#endif
namespace haxor{
namespace core{

Void RenderStats_obj::__construct()
{
	return null();
}

//RenderStats_obj::~RenderStats_obj() { }

Dynamic RenderStats_obj::__CreateEmpty() { return  new RenderStats_obj; }
hx::ObjectPtr< RenderStats_obj > RenderStats_obj::__new()
{  hx::ObjectPtr< RenderStats_obj > result = new RenderStats_obj();
	result->__construct();
	return result;}

Dynamic RenderStats_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RenderStats_obj > result = new RenderStats_obj();
	result->__construct();
	return result;}

int RenderStats_obj::visible;

int RenderStats_obj::culled;

int RenderStats_obj::triangles;

int RenderStats_obj::total;

int RenderStats_obj::get_total( ){
	HX_STACK_FRAME("haxor.core.RenderStats","get_total",0xfaa86e93,"haxor.core.RenderStats.get_total","haxor/core/RenderStats.hx",30,0x4388c1f8)
	HX_STACK_LINE(30)
	return (::haxor::core::RenderStats_obj::visible + ::haxor::core::RenderStats_obj::culled);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(RenderStats_obj,get_total,return )

int RenderStats_obj::renderers;

Void RenderStats_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.core.RenderStats","Initialize",0xb3c61ff8,"haxor.core.RenderStats.Initialize","haxor/core/RenderStats.hx",38,0x4388c1f8)
		HX_STACK_LINE(39)
		::haxor::core::RenderStats_obj::visible = (int)0;
		HX_STACK_LINE(40)
		::haxor::core::RenderStats_obj::culled = (int)0;
		HX_STACK_LINE(41)
		::haxor::core::RenderStats_obj::triangles = (int)0;
		HX_STACK_LINE(42)
		::haxor::core::RenderStats_obj::renderers = (int)0;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(RenderStats_obj,Initialize,(void))

Void RenderStats_obj::BeginRender( ){
{
		HX_STACK_FRAME("haxor.core.RenderStats","BeginRender",0x01d532b7,"haxor.core.RenderStats.BeginRender","haxor/core/RenderStats.hx",46,0x4388c1f8)
		HX_STACK_LINE(47)
		::haxor::core::RenderStats_obj::visible = (int)0;
		HX_STACK_LINE(48)
		::haxor::core::RenderStats_obj::culled = (int)0;
		HX_STACK_LINE(49)
		::haxor::core::RenderStats_obj::triangles = (int)0;
		HX_STACK_LINE(50)
		int _g = ::haxor::context::EngineContext_obj::renderer->rid->get_next();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(50)
		::haxor::core::RenderStats_obj::renderers = _g;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(RenderStats_obj,BeginRender,(void))


RenderStats_obj::RenderStats_obj()
{
}

Dynamic RenderStats_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"total") ) { return inCallProp ? get_total() : total; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"culled") ) { return culled; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"visible") ) { return visible; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"triangles") ) { return triangles; }
		if (HX_FIELD_EQ(inName,"get_total") ) { return get_total_dyn(); }
		if (HX_FIELD_EQ(inName,"renderers") ) { return renderers; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"BeginRender") ) { return BeginRender_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RenderStats_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"total") ) { total=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"culled") ) { culled=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"visible") ) { visible=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"triangles") ) { triangles=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"renderers") ) { renderers=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RenderStats_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("visible"),
	HX_CSTRING("culled"),
	HX_CSTRING("triangles"),
	HX_CSTRING("total"),
	HX_CSTRING("get_total"),
	HX_CSTRING("renderers"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("BeginRender"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RenderStats_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(RenderStats_obj::visible,"visible");
	HX_MARK_MEMBER_NAME(RenderStats_obj::culled,"culled");
	HX_MARK_MEMBER_NAME(RenderStats_obj::triangles,"triangles");
	HX_MARK_MEMBER_NAME(RenderStats_obj::total,"total");
	HX_MARK_MEMBER_NAME(RenderStats_obj::renderers,"renderers");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RenderStats_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(RenderStats_obj::visible,"visible");
	HX_VISIT_MEMBER_NAME(RenderStats_obj::culled,"culled");
	HX_VISIT_MEMBER_NAME(RenderStats_obj::triangles,"triangles");
	HX_VISIT_MEMBER_NAME(RenderStats_obj::total,"total");
	HX_VISIT_MEMBER_NAME(RenderStats_obj::renderers,"renderers");
};

#endif

Class RenderStats_obj::__mClass;

void RenderStats_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.RenderStats"), hx::TCanCast< RenderStats_obj> ,sStaticFields,sMemberFields,
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

void RenderStats_obj::__boot()
{
}

} // end namespace haxor
} // end namespace core
