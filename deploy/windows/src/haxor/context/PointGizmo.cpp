#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_Gizmo
#include <haxor/context/Gizmo.h>
#endif
#ifndef INCLUDED_haxor_context_PointGizmo
#include <haxor/context/PointGizmo.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#include <haxor/graphics/mesh/Mesh.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh3
#include <haxor/graphics/mesh/Mesh3.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshAttrib
#include <haxor/graphics/mesh/MeshAttrib.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshLayout
#include <haxor/graphics/mesh/MeshLayout.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
namespace haxor{
namespace context{

Void PointGizmo_obj::__construct()
{
HX_STACK_FRAME("haxor.context.PointGizmo","new",0xdc90fd67,"haxor.context.PointGizmo.new","haxor/context/GizmoContext.hx",647,0xa99c50bc)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(647)
	super::__construct(::haxor::context::Gizmo_obj::POINT,(::haxor::context::Gizmo_obj::MAX_GIZMOS * (int)5));
}
;
	return null();
}

//PointGizmo_obj::~PointGizmo_obj() { }

Dynamic PointGizmo_obj::__CreateEmpty() { return  new PointGizmo_obj; }
hx::ObjectPtr< PointGizmo_obj > PointGizmo_obj::__new()
{  hx::ObjectPtr< PointGizmo_obj > result = new PointGizmo_obj();
	result->__construct();
	return result;}

Dynamic PointGizmo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PointGizmo_obj > result = new PointGizmo_obj();
	result->__construct();
	return result;}

Void PointGizmo_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.context.PointGizmo","OnBuild",0x6d1f5df6,"haxor.context.PointGizmo.OnBuild","haxor/context/GizmoContext.hx",653,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(654)
		::haxor::graphics::mesh::Mesh3 m = ::haxor::graphics::mesh::Mesh3_obj::__new(null());		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(655)
		m->set_name(HX_CSTRING("$GizmoPointMesh"));
		HX_STACK_LINE(656)
		m->primitive = (int)0;
		HX_STACK_LINE(657)
		Float id = 0.0;		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(658)
		::haxor::io::FloatArray ia = ::haxor::io::FloatArray_obj::__new(this->m_gizmo_count);		HX_STACK_VAR(ia,"ia");
		HX_STACK_LINE(659)
		::haxor::io::FloatArray va = ::haxor::io::FloatArray_obj::__new((this->m_gizmo_count * (int)3));		HX_STACK_VAR(va,"va");
		HX_STACK_LINE(660)
		int va_k = (int)0;		HX_STACK_VAR(va_k,"va_k");
		HX_STACK_LINE(661)
		int ia_k = (int)0;		HX_STACK_VAR(ia_k,"ia_k");
		HX_STACK_LINE(662)
		{
			HX_STACK_LINE(662)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(662)
			int _g = this->m_gizmo_count;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(662)
			while((true)){
				HX_STACK_LINE(662)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(662)
					break;
				}
				HX_STACK_LINE(662)
				int k = (_g1)++;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(664)
				int _g2 = (va_k)++;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(664)
				va->Set(_g2,0.0);
				HX_STACK_LINE(664)
				int _g11 = (va_k)++;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(664)
				va->Set(_g11,0.0);
				HX_STACK_LINE(664)
				int _g21 = (va_k)++;		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(664)
				va->Set(_g21,0.0);
				HX_STACK_LINE(664)
				int _g3 = (ia_k)++;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(664)
				ia->Set(_g3,id);
				HX_STACK_LINE(665)
				hx::AddEq(id,1.0);
			}
		}
		HX_STACK_LINE(667)
		m->Set(HX_CSTRING("id"),ia,(int)1);
		HX_STACK_LINE(668)
		m->Set(HX_CSTRING("vertex"),va,(int)3);
		HX_STACK_LINE(669)
		this->mesh = m;
	}
return null();
}



PointGizmo_obj::PointGizmo_obj()
{
}

Dynamic PointGizmo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PointGizmo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void PointGizmo_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("OnBuild"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PointGizmo_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PointGizmo_obj::__mClass,"__mClass");
};

#endif

Class PointGizmo_obj::__mClass;

void PointGizmo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.PointGizmo"), hx::TCanCast< PointGizmo_obj> ,sStaticFields,sMemberFields,
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

void PointGizmo_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
