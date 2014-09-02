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
#ifndef INCLUDED_haxor_core_Stats
#include <haxor/core/Stats.h>
#endif
namespace haxor{
namespace core{

Void Stats_obj::__construct()
{
	return null();
}

//Stats_obj::~Stats_obj() { }

Dynamic Stats_obj::__CreateEmpty() { return  new Stats_obj; }
hx::ObjectPtr< Stats_obj > Stats_obj::__new()
{  hx::ObjectPtr< Stats_obj > result = new Stats_obj();
	result->__construct();
	return result;}

Dynamic Stats_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Stats_obj > result = new Stats_obj();
	result->__construct();
	return result;}

int Stats_obj::visible;

int Stats_obj::culled;

int Stats_obj::triangles;

int Stats_obj::total;

int Stats_obj::get_total( ){
	HX_STACK_FRAME("haxor.core.Stats","get_total",0xf1e2a589,"haxor.core.Stats.get_total","haxor/core/Stats.hx",30,0x93bec042)
	HX_STACK_LINE(30)
	return (::haxor::core::Stats_obj::visible + ::haxor::core::Stats_obj::culled);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,get_total,return )

int Stats_obj::renderers;

Void Stats_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.core.Stats","Initialize",0x0f7c0042,"haxor.core.Stats.Initialize","haxor/core/Stats.hx",38,0x93bec042)
		HX_STACK_LINE(39)
		::haxor::core::Stats_obj::visible = (int)0;
		HX_STACK_LINE(40)
		::haxor::core::Stats_obj::culled = (int)0;
		HX_STACK_LINE(41)
		::haxor::core::Stats_obj::triangles = (int)0;
		HX_STACK_LINE(42)
		::haxor::core::Stats_obj::renderers = (int)0;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,Initialize,(void))

Void Stats_obj::BeginRender( ){
{
		HX_STACK_FRAME("haxor.core.Stats","BeginRender",0xe543932d,"haxor.core.Stats.BeginRender","haxor/core/Stats.hx",46,0x93bec042)
		HX_STACK_LINE(47)
		::haxor::core::Stats_obj::visible = (int)0;
		HX_STACK_LINE(48)
		::haxor::core::Stats_obj::culled = (int)0;
		HX_STACK_LINE(49)
		::haxor::core::Stats_obj::triangles = (int)0;
		HX_STACK_LINE(50)
		int _g = ::haxor::context::EngineContext_obj::renderer->rid->get_next();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(50)
		::haxor::core::Stats_obj::renderers = _g;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Stats_obj,BeginRender,(void))


Stats_obj::Stats_obj()
{
}

Dynamic Stats_obj::__Field(const ::String &inName,bool inCallProp)
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

Dynamic Stats_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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

void Stats_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(Stats_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Stats_obj::visible,"visible");
	HX_MARK_MEMBER_NAME(Stats_obj::culled,"culled");
	HX_MARK_MEMBER_NAME(Stats_obj::triangles,"triangles");
	HX_MARK_MEMBER_NAME(Stats_obj::total,"total");
	HX_MARK_MEMBER_NAME(Stats_obj::renderers,"renderers");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Stats_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Stats_obj::visible,"visible");
	HX_VISIT_MEMBER_NAME(Stats_obj::culled,"culled");
	HX_VISIT_MEMBER_NAME(Stats_obj::triangles,"triangles");
	HX_VISIT_MEMBER_NAME(Stats_obj::total,"total");
	HX_VISIT_MEMBER_NAME(Stats_obj::renderers,"renderers");
};

#endif

Class Stats_obj::__mClass;

void Stats_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.Stats"), hx::TCanCast< Stats_obj> ,sStaticFields,sMemberFields,
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

void Stats_obj::__boot()
{
}

} // end namespace haxor
} // end namespace core
