#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_AxisGizmo
#include <haxor/context/AxisGizmo.h>
#endif
#ifndef INCLUDED_haxor_context_Gizmo
#include <haxor/context/Gizmo.h>
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
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
namespace haxor{
namespace context{

Void AxisGizmo_obj::__construct()
{
HX_STACK_FRAME("haxor.context.AxisGizmo","new",0x2c9d8080,"haxor.context.AxisGizmo.new","haxor/context/GizmoContext.hx",581,0xa99c50bc)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(581)
	super::__construct(::haxor::context::Gizmo_obj::AXIS,::haxor::context::Gizmo_obj::MAX_GIZMOS);
}
;
	return null();
}

//AxisGizmo_obj::~AxisGizmo_obj() { }

Dynamic AxisGizmo_obj::__CreateEmpty() { return  new AxisGizmo_obj; }
hx::ObjectPtr< AxisGizmo_obj > AxisGizmo_obj::__new()
{  hx::ObjectPtr< AxisGizmo_obj > result = new AxisGizmo_obj();
	result->__construct();
	return result;}

Dynamic AxisGizmo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AxisGizmo_obj > result = new AxisGizmo_obj();
	result->__construct();
	return result;}

Void AxisGizmo_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.context.AxisGizmo","OnBuild",0x962de18f,"haxor.context.AxisGizmo.OnBuild","haxor/context/GizmoContext.hx",587,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(588)
		::haxor::graphics::mesh::Mesh3 m = ::haxor::graphics::mesh::Mesh3_obj::__new(null());		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(589)
		m->set_name(HX_CSTRING("$GizmoAxisMesh"));
		HX_STACK_LINE(590)
		m->primitive = (int)1;
		HX_STACK_LINE(592)
		::haxor::math::Color cr = ::haxor::math::Color_obj::__new(0.9,0.3,0.3,(int)1);		HX_STACK_VAR(cr,"cr");
		HX_STACK_LINE(593)
		::haxor::math::Color cg = ::haxor::math::Color_obj::__new(0.3,0.9,0.3,(int)1);		HX_STACK_VAR(cg,"cg");
		HX_STACK_LINE(594)
		::haxor::math::Color cb = ::haxor::math::Color_obj::__new(0.3,0.3,0.9,(int)1);		HX_STACK_VAR(cb,"cb");
		HX_STACK_LINE(596)
		Float id = 0.0;		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(597)
		::haxor::io::FloatArray ia = ::haxor::io::FloatArray_obj::__new((this->m_gizmo_count * (int)6));		HX_STACK_VAR(ia,"ia");
		HX_STACK_LINE(598)
		::haxor::io::FloatArray va = ::haxor::io::FloatArray_obj::__new(((this->m_gizmo_count * (int)6) * (int)3));		HX_STACK_VAR(va,"va");
		HX_STACK_LINE(599)
		::haxor::io::FloatArray ca = ::haxor::io::FloatArray_obj::__new(((this->m_gizmo_count * (int)6) * (int)3));		HX_STACK_VAR(ca,"ca");
		HX_STACK_LINE(601)
		int va_k = (int)0;		HX_STACK_VAR(va_k,"va_k");
		HX_STACK_LINE(602)
		int ca_k = (int)0;		HX_STACK_VAR(ca_k,"ca_k");
		HX_STACK_LINE(603)
		int ia_k = (int)0;		HX_STACK_VAR(ia_k,"ia_k");
		HX_STACK_LINE(605)
		{
			HX_STACK_LINE(605)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(605)
			int _g = this->m_gizmo_count;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(605)
			while((true)){
				HX_STACK_LINE(605)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(605)
					break;
				}
				HX_STACK_LINE(605)
				int k = (_g1)++;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(608)
				int _g2 = (va_k)++;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(608)
				va->Set(_g2,0.0);
				HX_STACK_LINE(608)
				int _g11 = (va_k)++;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(608)
				va->Set(_g11,0.0);
				HX_STACK_LINE(608)
				int _g21 = (va_k)++;		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(608)
				va->Set(_g21,0.0);
				HX_STACK_LINE(608)
				int _g3 = (ia_k)++;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(608)
				ia->Set(_g3,id);
				HX_STACK_LINE(609)
				int _g4 = (va_k)++;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(609)
				va->Set(_g4,1.0);
				HX_STACK_LINE(609)
				int _g5 = (va_k)++;		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(609)
				va->Set(_g5,0.0);
				HX_STACK_LINE(609)
				int _g6 = (va_k)++;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(609)
				va->Set(_g6,0.0);
				HX_STACK_LINE(609)
				int _g7 = (ia_k)++;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(609)
				ia->Set(_g7,id);
				HX_STACK_LINE(610)
				int _g8 = (va_k)++;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(610)
				va->Set(_g8,0.0);
				HX_STACK_LINE(610)
				int _g9 = (va_k)++;		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(610)
				va->Set(_g9,0.0);
				HX_STACK_LINE(610)
				int _g10 = (va_k)++;		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(610)
				va->Set(_g10,0.0);
				HX_STACK_LINE(610)
				int _g111 = (ia_k)++;		HX_STACK_VAR(_g111,"_g111");
				HX_STACK_LINE(610)
				ia->Set(_g111,id);
				HX_STACK_LINE(611)
				int _g12 = (va_k)++;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(611)
				va->Set(_g12,0.0);
				HX_STACK_LINE(611)
				int _g13 = (va_k)++;		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(611)
				va->Set(_g13,1.0);
				HX_STACK_LINE(611)
				int _g14 = (va_k)++;		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(611)
				va->Set(_g14,0.0);
				HX_STACK_LINE(611)
				int _g15 = (ia_k)++;		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(611)
				ia->Set(_g15,id);
				HX_STACK_LINE(612)
				int _g16 = (va_k)++;		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(612)
				va->Set(_g16,0.0);
				HX_STACK_LINE(612)
				int _g17 = (va_k)++;		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(612)
				va->Set(_g17,0.0);
				HX_STACK_LINE(612)
				int _g18 = (va_k)++;		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(612)
				va->Set(_g18,0.0);
				HX_STACK_LINE(612)
				int _g19 = (ia_k)++;		HX_STACK_VAR(_g19,"_g19");
				HX_STACK_LINE(612)
				ia->Set(_g19,id);
				HX_STACK_LINE(613)
				int _g20 = (va_k)++;		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(613)
				va->Set(_g20,0.0);
				HX_STACK_LINE(613)
				int _g211 = (va_k)++;		HX_STACK_VAR(_g211,"_g211");
				HX_STACK_LINE(613)
				va->Set(_g211,0.0);
				HX_STACK_LINE(613)
				int _g22 = (va_k)++;		HX_STACK_VAR(_g22,"_g22");
				HX_STACK_LINE(613)
				va->Set(_g22,1.0);
				HX_STACK_LINE(613)
				int _g23 = (ia_k)++;		HX_STACK_VAR(_g23,"_g23");
				HX_STACK_LINE(613)
				ia->Set(_g23,id);
				HX_STACK_LINE(614)
				::haxor::math::Color c;		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(615)
				c = cr;
				HX_STACK_LINE(616)
				int _g24 = (ca_k)++;		HX_STACK_VAR(_g24,"_g24");
				HX_STACK_LINE(616)
				ca->Set(_g24,c->r);
				HX_STACK_LINE(616)
				int _g25 = (ca_k)++;		HX_STACK_VAR(_g25,"_g25");
				HX_STACK_LINE(616)
				ca->Set(_g25,c->g);
				HX_STACK_LINE(616)
				int _g26 = (ca_k)++;		HX_STACK_VAR(_g26,"_g26");
				HX_STACK_LINE(616)
				ca->Set(_g26,c->b);
				HX_STACK_LINE(616)
				int _g27 = (ca_k)++;		HX_STACK_VAR(_g27,"_g27");
				HX_STACK_LINE(616)
				ca->Set(_g27,c->a);
				HX_STACK_LINE(617)
				int _g28 = (ca_k)++;		HX_STACK_VAR(_g28,"_g28");
				HX_STACK_LINE(617)
				ca->Set(_g28,c->r);
				HX_STACK_LINE(617)
				int _g29 = (ca_k)++;		HX_STACK_VAR(_g29,"_g29");
				HX_STACK_LINE(617)
				ca->Set(_g29,c->g);
				HX_STACK_LINE(617)
				int _g30 = (ca_k)++;		HX_STACK_VAR(_g30,"_g30");
				HX_STACK_LINE(617)
				ca->Set(_g30,c->b);
				HX_STACK_LINE(617)
				int _g31 = (ca_k)++;		HX_STACK_VAR(_g31,"_g31");
				HX_STACK_LINE(617)
				ca->Set(_g31,c->a);
				HX_STACK_LINE(618)
				c = cg;
				HX_STACK_LINE(619)
				int _g32 = (ca_k)++;		HX_STACK_VAR(_g32,"_g32");
				HX_STACK_LINE(619)
				ca->Set(_g32,c->r);
				HX_STACK_LINE(619)
				int _g33 = (ca_k)++;		HX_STACK_VAR(_g33,"_g33");
				HX_STACK_LINE(619)
				ca->Set(_g33,c->g);
				HX_STACK_LINE(619)
				int _g34 = (ca_k)++;		HX_STACK_VAR(_g34,"_g34");
				HX_STACK_LINE(619)
				ca->Set(_g34,c->b);
				HX_STACK_LINE(619)
				int _g35 = (ca_k)++;		HX_STACK_VAR(_g35,"_g35");
				HX_STACK_LINE(619)
				ca->Set(_g35,c->a);
				HX_STACK_LINE(620)
				int _g36 = (ca_k)++;		HX_STACK_VAR(_g36,"_g36");
				HX_STACK_LINE(620)
				ca->Set(_g36,c->r);
				HX_STACK_LINE(620)
				int _g37 = (ca_k)++;		HX_STACK_VAR(_g37,"_g37");
				HX_STACK_LINE(620)
				ca->Set(_g37,c->g);
				HX_STACK_LINE(620)
				int _g38 = (ca_k)++;		HX_STACK_VAR(_g38,"_g38");
				HX_STACK_LINE(620)
				ca->Set(_g38,c->b);
				HX_STACK_LINE(620)
				int _g39 = (ca_k)++;		HX_STACK_VAR(_g39,"_g39");
				HX_STACK_LINE(620)
				ca->Set(_g39,c->a);
				HX_STACK_LINE(621)
				c = cb;
				HX_STACK_LINE(622)
				int _g40 = (ca_k)++;		HX_STACK_VAR(_g40,"_g40");
				HX_STACK_LINE(622)
				ca->Set(_g40,c->r);
				HX_STACK_LINE(622)
				int _g41 = (ca_k)++;		HX_STACK_VAR(_g41,"_g41");
				HX_STACK_LINE(622)
				ca->Set(_g41,c->g);
				HX_STACK_LINE(622)
				int _g42 = (ca_k)++;		HX_STACK_VAR(_g42,"_g42");
				HX_STACK_LINE(622)
				ca->Set(_g42,c->b);
				HX_STACK_LINE(622)
				int _g43 = (ca_k)++;		HX_STACK_VAR(_g43,"_g43");
				HX_STACK_LINE(622)
				ca->Set(_g43,c->a);
				HX_STACK_LINE(623)
				int _g44 = (ca_k)++;		HX_STACK_VAR(_g44,"_g44");
				HX_STACK_LINE(623)
				ca->Set(_g44,c->r);
				HX_STACK_LINE(623)
				int _g45 = (ca_k)++;		HX_STACK_VAR(_g45,"_g45");
				HX_STACK_LINE(623)
				ca->Set(_g45,c->g);
				HX_STACK_LINE(623)
				int _g46 = (ca_k)++;		HX_STACK_VAR(_g46,"_g46");
				HX_STACK_LINE(623)
				ca->Set(_g46,c->b);
				HX_STACK_LINE(623)
				int _g47 = (ca_k)++;		HX_STACK_VAR(_g47,"_g47");
				HX_STACK_LINE(623)
				ca->Set(_g47,c->a);
				HX_STACK_LINE(624)
				hx::AddEq(id,1.0);
			}
		}
		HX_STACK_LINE(626)
		m->Set(HX_CSTRING("id"),ia,(int)1);
		HX_STACK_LINE(627)
		m->Set(HX_CSTRING("vertex"),va,(int)3);
		HX_STACK_LINE(628)
		m->Set(HX_CSTRING("color"),ca,(int)4);
		HX_STACK_LINE(629)
		this->mesh = m;
	}
return null();
}



AxisGizmo_obj::AxisGizmo_obj()
{
}

Dynamic AxisGizmo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AxisGizmo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void AxisGizmo_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(AxisGizmo_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AxisGizmo_obj::__mClass,"__mClass");
};

#endif

Class AxisGizmo_obj::__mClass;

void AxisGizmo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.AxisGizmo"), hx::TCanCast< AxisGizmo_obj> ,sStaticFields,sMemberFields,
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

void AxisGizmo_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
