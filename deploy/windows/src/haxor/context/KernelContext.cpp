#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_KernelContext
#include <haxor/context/KernelContext.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#include <haxor/graphics/mesh/Mesh.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh3
#include <haxor/graphics/mesh/Mesh3.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshLayout
#include <haxor/graphics/mesh/MeshLayout.h>
#endif
#ifndef INCLUDED_haxor_thread_Kernel
#include <haxor/thread/Kernel.h>
#endif
namespace haxor{
namespace context{

Void KernelContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.KernelContext","new",0x1b922419,"haxor.context.KernelContext.new","haxor/context/KernelContext.hx",30,0x8c1aae79)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//KernelContext_obj::~KernelContext_obj() { }

Dynamic KernelContext_obj::__CreateEmpty() { return  new KernelContext_obj; }
hx::ObjectPtr< KernelContext_obj > KernelContext_obj::__new()
{  hx::ObjectPtr< KernelContext_obj > result = new KernelContext_obj();
	result->__construct();
	return result;}

Dynamic KernelContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< KernelContext_obj > result = new KernelContext_obj();
	result->__construct();
	return result;}

Void KernelContext_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.context.KernelContext","Initialize",0x7c62bad7,"haxor.context.KernelContext.Initialize","haxor/context/KernelContext.hx",37,0x8c1aae79)
		HX_STACK_THIS(this)
		HX_STACK_LINE(37)
		this->list = Array_obj< ::Dynamic >::__new();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(KernelContext_obj,Initialize,(void))

Void KernelContext_obj::Execute( ){
{
		HX_STACK_FRAME("haxor.context.KernelContext","Execute",0xf2e3564e,"haxor.context.KernelContext.Execute","haxor/context/KernelContext.hx",45,0x8c1aae79)
		HX_STACK_THIS(this)
		HX_STACK_LINE(45)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(45)
		int _g = this->list->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(45)
		while((true)){
			HX_STACK_LINE(45)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(45)
				break;
			}
			HX_STACK_LINE(45)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(45)
			this->list->__get(i).StaticCast< ::haxor::thread::Kernel >()->Execute();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(KernelContext_obj,Execute,(void))

Void KernelContext_obj::OnCreate( ::haxor::thread::Kernel k){
{
		HX_STACK_FRAME("haxor.context.KernelContext","OnCreate",0x3068a742,"haxor.context.KernelContext.OnCreate","haxor/context/KernelContext.hx",54,0x8c1aae79)
		HX_STACK_THIS(this)
		HX_STACK_ARG(k,"k")
		HX_STACK_LINE(54)
		this->list->push(k);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(KernelContext_obj,OnCreate,(void))

Void KernelContext_obj::OnDestroy( ::haxor::thread::Kernel k){
{
		HX_STACK_FRAME("haxor.context.KernelContext","OnDestroy",0x3e4529f4,"haxor.context.KernelContext.OnDestroy","haxor/context/KernelContext.hx",63,0x8c1aae79)
		HX_STACK_THIS(this)
		HX_STACK_ARG(k,"k")
		HX_STACK_LINE(63)
		this->list->remove(k);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(KernelContext_obj,OnDestroy,(void))


KernelContext_obj::KernelContext_obj()
{
}

void KernelContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(KernelContext);
	HX_MARK_MEMBER_NAME(m_plane,"m_plane");
	HX_MARK_MEMBER_NAME(list,"list");
	HX_MARK_END_CLASS();
}

void KernelContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_plane,"m_plane");
	HX_VISIT_MEMBER_NAME(list,"list");
}

Dynamic KernelContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return list; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_plane") ) { return m_plane; }
		if (HX_FIELD_EQ(inName,"Execute") ) { return Execute_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"OnCreate") ) { return OnCreate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic KernelContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_plane") ) { m_plane=inValue.Cast< ::haxor::graphics::mesh::Mesh3 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void KernelContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_plane"));
	outFields->push(HX_CSTRING("list"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::graphics::mesh::Mesh3*/ ,(int)offsetof(KernelContext_obj,m_plane),HX_CSTRING("m_plane")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(KernelContext_obj,list),HX_CSTRING("list")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("m_plane"),
	HX_CSTRING("list"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Execute"),
	HX_CSTRING("OnCreate"),
	HX_CSTRING("OnDestroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(KernelContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(KernelContext_obj::__mClass,"__mClass");
};

#endif

Class KernelContext_obj::__mClass;

void KernelContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.KernelContext"), hx::TCanCast< KernelContext_obj> ,sStaticFields,sMemberFields,
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

void KernelContext_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
