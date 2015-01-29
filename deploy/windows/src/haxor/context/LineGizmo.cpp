#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_Gizmo
#include <haxor/context/Gizmo.h>
#endif
#ifndef INCLUDED_haxor_context_LineGizmo
#include <haxor/context/LineGizmo.h>
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

Void LineGizmo_obj::__construct()
{
HX_STACK_FRAME("haxor.context.LineGizmo","new",0x51f102cd,"haxor.context.LineGizmo.new","haxor/context/GizmoContext.hx",612,0xa99c50bc)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(612)
	super::__construct(::haxor::context::Gizmo_obj::LINE,(::haxor::context::Gizmo_obj::MAX_GIZMOS * (int)3));
}
;
	return null();
}

//LineGizmo_obj::~LineGizmo_obj() { }

Dynamic LineGizmo_obj::__CreateEmpty() { return  new LineGizmo_obj; }
hx::ObjectPtr< LineGizmo_obj > LineGizmo_obj::__new()
{  hx::ObjectPtr< LineGizmo_obj > result = new LineGizmo_obj();
	result->__construct();
	return result;}

Dynamic LineGizmo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LineGizmo_obj > result = new LineGizmo_obj();
	result->__construct();
	return result;}

Void LineGizmo_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.context.LineGizmo","OnBuild",0xce450e5c,"haxor.context.LineGizmo.OnBuild","haxor/context/GizmoContext.hx",618,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(619)
		::haxor::graphics::mesh::Mesh3 m = ::haxor::graphics::mesh::Mesh3_obj::__new(null());		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(620)
		m->set_name(HX_CSTRING("$GizmoLineMesh"));
		HX_STACK_LINE(621)
		m->primitive = (int)1;
		HX_STACK_LINE(622)
		Float id = 0.0;		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(623)
		::haxor::io::FloatArray ia = ::haxor::io::FloatArray_obj::__new((this->m_gizmo_count * (int)2));		HX_STACK_VAR(ia,"ia");
		HX_STACK_LINE(624)
		::haxor::io::FloatArray va = ::haxor::io::FloatArray_obj::__new(((this->m_gizmo_count * (int)2) * (int)3));		HX_STACK_VAR(va,"va");
		HX_STACK_LINE(625)
		int va_k = (int)0;		HX_STACK_VAR(va_k,"va_k");
		HX_STACK_LINE(626)
		int ia_k = (int)0;		HX_STACK_VAR(ia_k,"ia_k");
		HX_STACK_LINE(627)
		{
			HX_STACK_LINE(627)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(627)
			int _g = this->m_gizmo_count;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(627)
			while((true)){
				HX_STACK_LINE(627)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(627)
					break;
				}
				HX_STACK_LINE(627)
				int k = (_g1)++;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(629)
				int _g2 = (va_k)++;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(629)
				va->Set(_g2,0.0);
				HX_STACK_LINE(629)
				int _g11 = (va_k)++;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(629)
				va->Set(_g11,0.0);
				HX_STACK_LINE(629)
				int _g21 = (va_k)++;		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(629)
				va->Set(_g21,0.0);
				HX_STACK_LINE(629)
				int _g3 = (ia_k)++;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(629)
				ia->Set(_g3,id);
				HX_STACK_LINE(630)
				int _g4 = (va_k)++;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(630)
				va->Set(_g4,1.0);
				HX_STACK_LINE(630)
				int _g5 = (va_k)++;		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(630)
				va->Set(_g5,1.0);
				HX_STACK_LINE(630)
				int _g6 = (va_k)++;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(630)
				va->Set(_g6,1.0);
				HX_STACK_LINE(630)
				int _g7 = (ia_k)++;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(630)
				ia->Set(_g7,id);
				HX_STACK_LINE(631)
				hx::AddEq(id,1.0);
			}
		}
		HX_STACK_LINE(633)
		m->Set(HX_CSTRING("id"),ia,(int)1);
		HX_STACK_LINE(634)
		m->Set(HX_CSTRING("vertex"),va,(int)3);
		HX_STACK_LINE(635)
		this->mesh = m;
	}
return null();
}



LineGizmo_obj::LineGizmo_obj()
{
}

Dynamic LineGizmo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LineGizmo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void LineGizmo_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(LineGizmo_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LineGizmo_obj::__mClass,"__mClass");
};

#endif

Class LineGizmo_obj::__mClass;

void LineGizmo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.LineGizmo"), hx::TCanCast< LineGizmo_obj> ,sStaticFields,sMemberFields,
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

void LineGizmo_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
