#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_HaxorContext
#include <haxor/context/HaxorContext.h>
#endif
#ifndef INCLUDED_haxor_context_Process
#include <haxor/context/Process.h>
#endif
namespace haxor{
namespace context{

Void HaxorContext_obj::__construct()
{
	return null();
}

//HaxorContext_obj::~HaxorContext_obj() { }

Dynamic HaxorContext_obj::__CreateEmpty() { return  new HaxorContext_obj; }
hx::ObjectPtr< HaxorContext_obj > HaxorContext_obj::__new()
{  hx::ObjectPtr< HaxorContext_obj > result = new HaxorContext_obj();
	result->__construct();
	return result;}

Dynamic HaxorContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HaxorContext_obj > result = new HaxorContext_obj();
	result->__construct();
	return result;}

int HaxorContext_obj::uid;

int HaxorContext_obj::maxNodes;

int HaxorContext_obj::collectRate;

::haxor::context::Process HaxorContext_obj::update;

::haxor::context::Process HaxorContext_obj::resize;

::haxor::context::Process HaxorContext_obj::render;

::haxor::context::Process HaxorContext_obj::resources;

::haxor::context::Process HaxorContext_obj::disposables;

Void HaxorContext_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.context.HaxorContext","Initialize",0xfe7c6ea6,"haxor.context.HaxorContext.Initialize","haxor/context/HaxorContext.hx",60,0xa3c67784)
		HX_STACK_LINE(61)
		::haxor::context::Process _g = ::haxor::context::Process_obj::__new(HX_CSTRING("process.update"),::haxor::context::HaxorContext_obj::maxNodes);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(61)
		::haxor::context::HaxorContext_obj::update = _g;
		HX_STACK_LINE(62)
		::haxor::context::Process _g1 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.render"),::haxor::context::HaxorContext_obj::maxNodes);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(62)
		::haxor::context::HaxorContext_obj::render = _g1;
		HX_STACK_LINE(63)
		::haxor::context::Process _g2 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.resize"),::haxor::context::HaxorContext_obj::maxNodes);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(63)
		::haxor::context::HaxorContext_obj::resize = _g2;
		HX_STACK_LINE(64)
		::haxor::context::Process _g3 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.resources"),::haxor::context::HaxorContext_obj::maxNodes);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(64)
		::haxor::context::HaxorContext_obj::resources = _g3;
		HX_STACK_LINE(65)
		::haxor::context::Process _g4 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.disposbales"),::haxor::context::HaxorContext_obj::maxNodes);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(65)
		::haxor::context::HaxorContext_obj::disposables = _g4;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(HaxorContext_obj,Initialize,(void))


HaxorContext_obj::HaxorContext_obj()
{
}

Dynamic HaxorContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"uid") ) { return uid; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update; }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize; }
		if (HX_FIELD_EQ(inName,"render") ) { return render; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxNodes") ) { return maxNodes; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"resources") ) { return resources; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"collectRate") ) { return collectRate; }
		if (HX_FIELD_EQ(inName,"disposables") ) { return disposables; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HaxorContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"uid") ) { uid=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { update=inValue.Cast< ::haxor::context::Process >(); return inValue; }
		if (HX_FIELD_EQ(inName,"resize") ) { resize=inValue.Cast< ::haxor::context::Process >(); return inValue; }
		if (HX_FIELD_EQ(inName,"render") ) { render=inValue.Cast< ::haxor::context::Process >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxNodes") ) { maxNodes=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"resources") ) { resources=inValue.Cast< ::haxor::context::Process >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"collectRate") ) { collectRate=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"disposables") ) { disposables=inValue.Cast< ::haxor::context::Process >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HaxorContext_obj::__GetFields(Array< ::String> &outFields)
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
	HX_CSTRING("Initialize"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HaxorContext_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(HaxorContext_obj::uid,"uid");
	HX_MARK_MEMBER_NAME(HaxorContext_obj::maxNodes,"maxNodes");
	HX_MARK_MEMBER_NAME(HaxorContext_obj::collectRate,"collectRate");
	HX_MARK_MEMBER_NAME(HaxorContext_obj::update,"update");
	HX_MARK_MEMBER_NAME(HaxorContext_obj::resize,"resize");
	HX_MARK_MEMBER_NAME(HaxorContext_obj::render,"render");
	HX_MARK_MEMBER_NAME(HaxorContext_obj::resources,"resources");
	HX_MARK_MEMBER_NAME(HaxorContext_obj::disposables,"disposables");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HaxorContext_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(HaxorContext_obj::uid,"uid");
	HX_VISIT_MEMBER_NAME(HaxorContext_obj::maxNodes,"maxNodes");
	HX_VISIT_MEMBER_NAME(HaxorContext_obj::collectRate,"collectRate");
	HX_VISIT_MEMBER_NAME(HaxorContext_obj::update,"update");
	HX_VISIT_MEMBER_NAME(HaxorContext_obj::resize,"resize");
	HX_VISIT_MEMBER_NAME(HaxorContext_obj::render,"render");
	HX_VISIT_MEMBER_NAME(HaxorContext_obj::resources,"resources");
	HX_VISIT_MEMBER_NAME(HaxorContext_obj::disposables,"disposables");
};

#endif

Class HaxorContext_obj::__mClass;

void HaxorContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.HaxorContext"), hx::TCanCast< HaxorContext_obj> ,sStaticFields,sMemberFields,
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

void HaxorContext_obj::__boot()
{
	uid= (int)0;
	maxNodes= (int)1000;
	collectRate= (int)10;
}

} // end namespace haxor
} // end namespace context
