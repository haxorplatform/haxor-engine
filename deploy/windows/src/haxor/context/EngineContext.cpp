#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_BaseProcess
#include <haxor/context/BaseProcess.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_MaterialContext
#include <haxor/context/MaterialContext.h>
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
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
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

::haxor::context::MaterialContext EngineContext_obj::material;

Array< ::Dynamic > EngineContext_obj::list;

Void EngineContext_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.context.EngineContext","Initialize",0x8336921c,"haxor.context.EngineContext.Initialize","haxor/context/EngineContext.hx",77,0x2d4338be)
		HX_STACK_LINE(79)
		::haxor::core::Console_obj::Log(HX_CSTRING("Haxor> Engine Context Initialize."),(int)3);
		HX_STACK_LINE(80)
		::haxor::context::Process _g = ::haxor::context::Process_obj::__new(HX_CSTRING("process.update"),::haxor::context::EngineContext_obj::maxNodes);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(80)
		::haxor::context::EngineContext_obj::update = _g;
		HX_STACK_LINE(81)
		::haxor::context::Process _g1 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.render"),::haxor::context::EngineContext_obj::maxNodes);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(81)
		::haxor::context::EngineContext_obj::render = _g1;
		HX_STACK_LINE(82)
		::haxor::context::Process _g2 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.resize"),::haxor::context::EngineContext_obj::maxNodes);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(82)
		::haxor::context::EngineContext_obj::resize = _g2;
		HX_STACK_LINE(83)
		::haxor::context::Process _g3 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.resources"),::haxor::context::EngineContext_obj::maxNodes);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(83)
		::haxor::context::EngineContext_obj::resources = _g3;
		HX_STACK_LINE(84)
		::haxor::context::Process _g4 = ::haxor::context::Process_obj::__new(HX_CSTRING("process.disposables"),::haxor::context::EngineContext_obj::maxNodes);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(84)
		::haxor::context::EngineContext_obj::disposables = _g4;
		HX_STACK_LINE(86)
		::haxor::context::EngineContext_obj::list = Array_obj< ::Dynamic >::__new().Add(::haxor::context::EngineContext_obj::update).Add(::haxor::context::EngineContext_obj::render).Add(::haxor::context::EngineContext_obj::resize).Add(::haxor::context::EngineContext_obj::resources).Add(::haxor::context::EngineContext_obj::disposables);
		HX_STACK_LINE(88)
		::haxor::context::MeshContext _g5 = ::haxor::context::MeshContext_obj::__new();		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(88)
		::haxor::context::EngineContext_obj::mesh = _g5;
		HX_STACK_LINE(89)
		::haxor::context::MaterialContext _g6 = ::haxor::context::MaterialContext_obj::__new();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(89)
		::haxor::context::EngineContext_obj::material = _g6;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(EngineContext_obj,Initialize,(void))

Void EngineContext_obj::Build( ){
{
		HX_STACK_FRAME("haxor.context.EngineContext","Build",0x61432de2,"haxor.context.EngineContext.Build","haxor/context/EngineContext.hx",96,0x2d4338be)
		HX_STACK_LINE(97)
		::haxor::context::EngineContext_obj::mesh->Initialize();
		HX_STACK_LINE(98)
		::haxor::context::EngineContext_obj::material->Initialize();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(EngineContext_obj,Build,(void))

Void EngineContext_obj::Destroy( ::haxor::core::Resource p_resource){
{
		HX_STACK_FRAME("haxor.context.EngineContext","Destroy",0x4f9f94ae,"haxor.context.EngineContext.Destroy","haxor/context/EngineContext.hx",106,0x2d4338be)
		HX_STACK_ARG(p_resource,"p_resource")
		HX_STACK_LINE(107)
		if ((p_resource->m_destroyed)){
			HX_STACK_LINE(107)
			return null();
		}
		HX_STACK_LINE(108)
		p_resource->m_destroyed = true;
		HX_STACK_LINE(109)
		{
			HX_STACK_LINE(109)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(109)
			int _g = ::haxor::context::EngineContext_obj::list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(109)
			while((true)){
				HX_STACK_LINE(109)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(109)
					break;
				}
				HX_STACK_LINE(109)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(109)
				::haxor::context::EngineContext_obj::list->__get(i).StaticCast< ::haxor::context::BaseProcess >()->Remove(p_resource);
			}
		}
		HX_STACK_LINE(110)
		::haxor::context::EngineContext_obj::disposables->Add(p_resource);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(EngineContext_obj,Destroy,(void))


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
		if (HX_FIELD_EQ(inName,"list") ) { return list; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Build") ) { return Build_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update; }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize; }
		if (HX_FIELD_EQ(inName,"render") ) { return render; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Destroy") ) { return Destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxNodes") ) { return maxNodes; }
		if (HX_FIELD_EQ(inName,"material") ) { return material; }
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
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { update=inValue.Cast< ::haxor::context::Process >(); return inValue; }
		if (HX_FIELD_EQ(inName,"resize") ) { resize=inValue.Cast< ::haxor::context::Process >(); return inValue; }
		if (HX_FIELD_EQ(inName,"render") ) { render=inValue.Cast< ::haxor::context::Process >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxNodes") ) { maxNodes=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"material") ) { material=inValue.Cast< ::haxor::context::MaterialContext >(); return inValue; }
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
	HX_CSTRING("material"),
	HX_CSTRING("list"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Build"),
	HX_CSTRING("Destroy"),
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
	HX_MARK_MEMBER_NAME(EngineContext_obj::material,"material");
	HX_MARK_MEMBER_NAME(EngineContext_obj::list,"list");
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
	HX_VISIT_MEMBER_NAME(EngineContext_obj::material,"material");
	HX_VISIT_MEMBER_NAME(EngineContext_obj::list,"list");
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
