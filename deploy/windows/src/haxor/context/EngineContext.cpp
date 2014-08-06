#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_MeshContext
#include <haxor/context/MeshContext.h>
#endif
#ifndef INCLUDED_haxor_context_Process
#include <haxor/context/Process.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
namespace haxor{
namespace context{

Void EngineContext_obj::__construct()
{
	return null();
}

//EngineContext_obj::~EngineContext_obj() { }

Dynamic EngineContext_obj::__CreateEmpty() { return  new EngineContext_obj; }
hx::ObjectPtr< EngineContext_obj > EngineContext_obj::__new()
{  hx::ObjectPtr< EngineContext_obj > result = new EngineContext_obj();
	result->__construct();
	return result;}

Dynamic EngineContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< EngineContext_obj > result = new EngineContext_obj();
	result->__construct();
	return result;}

int EngineContext_obj::uid;

int EngineContext_obj::maxNodes;

int EngineContext_obj::collectRate;

::haxor::context::Process EngineContext_obj::update;

::haxor::context::Process EngineContext_obj::resize;

::haxor::context::Process EngineContext_obj::render;

::haxor::context::Process EngineContext_obj::resources;

::haxor::context::Process EngineContext_obj::disposables;

::haxor::context::MeshContext EngineContext_obj::mesh;

Void EngineContext_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.context.EngineContext","Initialize",0x8336921c,"haxor.context.EngineContext.Initialize","haxor/context/EngineContext.hx",66,0x2d4338be)
		HX_STACK_LINE(67)
		::haxor::core::Console_obj::Log(HX_CSTRING("Haxor> Engine Context Initialize."),(int)3);
		HX_STACK_LINE(68)
		::haxor::context::Process _g = ::haxor::context::Process_obj::__new(HX_CSTRING("process.update"),::haxor::context::EngineContext_obj::maxNodes);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(68)
		::haxor::context::EngineContext_obj::update = _g;
		HX_STACK_LINE(69)
		::haxor::context::Process _g1 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.render"),::haxor::context::EngineContext_obj::maxNodes);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(69)
		::haxor::context::EngineContext_obj::render = _g1;
		HX_STACK_LINE(70)
		::haxor::context::Process _g2 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.resize"),::haxor::context::EngineContext_obj::maxNodes);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(70)
		::haxor::context::EngineContext_obj::resize = _g2;
		HX_STACK_LINE(71)
		::haxor::context::Process _g3 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.resources"),::haxor::context::EngineContext_obj::maxNodes);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(71)
		::haxor::context::EngineContext_obj::resources = _g3;
		HX_STACK_LINE(72)
		::haxor::context::Process _g4 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.disposables"),::haxor::context::EngineContext_obj::maxNodes);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(72)
		::haxor::context::EngineContext_obj::disposables = _g4;
		HX_STACK_LINE(75)
		::haxor::context::MeshContext _g5 = ::haxor::context::MeshContext_obj::__new();		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(75)
		::haxor::context::EngineContext_obj::mesh = _g5;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(EngineContext_obj,Initialize,(void))


EngineContext_obj::EngineContext_obj()
{
}

Dynamic EngineContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"uid") ) { return uid; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mesh") ) { return mesh; }
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

Dynamic EngineContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"uid") ) { uid=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mesh") ) { mesh=inValue.Cast< ::haxor::context::MeshContext >(); return inValue; }
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

void EngineContext_obj::__GetFields(Array< ::String> &outFields)
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
	HX_CSTRING("mesh"),
	HX_CSTRING("Initialize"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(EngineContext_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(EngineContext_obj::uid,"uid");
	HX_MARK_MEMBER_NAME(EngineContext_obj::maxNodes,"maxNodes");
	HX_MARK_MEMBER_NAME(EngineContext_obj::collectRate,"collectRate");
	HX_MARK_MEMBER_NAME(EngineContext_obj::update,"update");
	HX_MARK_MEMBER_NAME(EngineContext_obj::resize,"resize");
	HX_MARK_MEMBER_NAME(EngineContext_obj::render,"render");
	HX_MARK_MEMBER_NAME(EngineContext_obj::resources,"resources");
	HX_MARK_MEMBER_NAME(EngineContext_obj::disposables,"disposables");
	HX_MARK_MEMBER_NAME(EngineContext_obj::mesh,"mesh");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(EngineContext_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::uid,"uid");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::maxNodes,"maxNodes");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::collectRate,"collectRate");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::update,"update");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::resize,"resize");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::render,"render");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::resources,"resources");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::disposables,"disposables");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::mesh,"mesh");
};

#endif

Class EngineContext_obj::__mClass;

void EngineContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.EngineContext"), hx::TCanCast< EngineContext_obj> ,sStaticFields,sMemberFields,
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

void EngineContext_obj::__boot()
{
	uid= (int)0;
	maxNodes= (int)1000;
	collectRate= (int)10;
}

} // end namespace haxor
} // end namespace context
