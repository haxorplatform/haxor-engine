#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_Gizmo
#include <haxor/context/Gizmo.h>
#endif
#ifndef INCLUDED_haxor_context_WireSphereGizmo
#include <haxor/context/WireSphereGizmo.h>
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
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace context{

Void WireSphereGizmo_obj::__construct()
{
HX_STACK_FRAME("haxor.context.WireSphereGizmo","new",0x9f2ccf8f,"haxor.context.WireSphereGizmo.new","haxor/context/GizmoContext.hx",442,0xa99c50bc)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(442)
	super::__construct(::haxor::context::Gizmo_obj::WIRE_SPHERE,::haxor::context::Gizmo_obj::MAX_GIZMOS);
}
;
	return null();
}

//WireSphereGizmo_obj::~WireSphereGizmo_obj() { }

Dynamic WireSphereGizmo_obj::__CreateEmpty() { return  new WireSphereGizmo_obj; }
hx::ObjectPtr< WireSphereGizmo_obj > WireSphereGizmo_obj::__new()
{  hx::ObjectPtr< WireSphereGizmo_obj > result = new WireSphereGizmo_obj();
	result->__construct();
	return result;}

Dynamic WireSphereGizmo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WireSphereGizmo_obj > result = new WireSphereGizmo_obj();
	result->__construct();
	return result;}

Void WireSphereGizmo_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.context.WireSphereGizmo","OnBuild",0x4713641e,"haxor.context.WireSphereGizmo.OnBuild","haxor/context/GizmoContext.hx",448,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(449)
		::haxor::graphics::mesh::Mesh3 m = ::haxor::graphics::mesh::Mesh3_obj::__new(null());		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(450)
		m->set_name(HX_CSTRING("$GizmoWireSphereMesh"));
		HX_STACK_LINE(451)
		m->primitive = (int)1;
		HX_STACK_LINE(452)
		Float r = 1.0;		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(453)
		::haxor::math::Vector3 v;		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(454)
		int steps = (int)720;		HX_STACK_VAR(steps,"steps");
		HX_STACK_LINE(455)
		::haxor::io::FloatArray ia = ::haxor::io::FloatArray_obj::__new(((steps * (int)6) * this->m_gizmo_count));		HX_STACK_VAR(ia,"ia");
		HX_STACK_LINE(456)
		::haxor::io::FloatArray va = ::haxor::io::FloatArray_obj::__new(((steps * (int)18) * this->m_gizmo_count));		HX_STACK_VAR(va,"va");
		HX_STACK_LINE(457)
		int va_k = (int)0;		HX_STACK_VAR(va_k,"va_k");
		HX_STACK_LINE(458)
		int ia_k = (int)0;		HX_STACK_VAR(ia_k,"ia_k");
		HX_STACK_LINE(459)
		Float id = 0.0;		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(460)
		{
			HX_STACK_LINE(460)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(460)
			int _g = this->m_gizmo_count;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(460)
			while((true)){
				HX_STACK_LINE(460)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(460)
					break;
				}
				HX_STACK_LINE(460)
				int k = (_g1)++;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(462)
				{
					HX_STACK_LINE(462)
					int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(462)
					while((true)){
						HX_STACK_LINE(462)
						if ((!(((_g2 < steps))))){
							HX_STACK_LINE(462)
							break;
						}
						HX_STACK_LINE(462)
						int i = (_g2)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(464)
						Float astp = (Float(1.0) / Float(((steps - (int)1))));		HX_STACK_VAR(astp,"astp");
						HX_STACK_LINE(465)
						Float a;		HX_STACK_VAR(a,"a");
						HX_STACK_LINE(466)
						a = (((int)360 * i) * astp);
						HX_STACK_LINE(467)
						Float _g3 = ::Math_obj::sin((a * 0.01745329251994329576923690768489));		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(467)
						Float _g11 = (_g3 * r);		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(467)
						Float sv0 = (_g11 * 0.5);		HX_STACK_VAR(sv0,"sv0");
						HX_STACK_LINE(468)
						Float _g21 = ::Math_obj::cos((a * 0.01745329251994329576923690768489));		HX_STACK_VAR(_g21,"_g21");
						HX_STACK_LINE(468)
						Float _g31 = (_g21 * r);		HX_STACK_VAR(_g31,"_g31");
						HX_STACK_LINE(468)
						Float cv0 = (_g31 * 0.5);		HX_STACK_VAR(cv0,"cv0");
						HX_STACK_LINE(469)
						a = (((int)360 * ((i + (int)1))) * astp);
						HX_STACK_LINE(470)
						Float _g4 = ::Math_obj::sin((a * 0.01745329251994329576923690768489));		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(470)
						Float _g5 = (_g4 * r);		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(470)
						Float sv1 = (_g5 * 0.5);		HX_STACK_VAR(sv1,"sv1");
						HX_STACK_LINE(471)
						Float _g6 = ::Math_obj::cos((a * 0.01745329251994329576923690768489));		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(471)
						Float _g7 = (_g6 * r);		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(471)
						Float cv1 = (_g7 * 0.5);		HX_STACK_VAR(cv1,"cv1");
						HX_STACK_LINE(472)
						int _g8 = (va_k)++;		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(472)
						va->Set(_g8,cv0);
						HX_STACK_LINE(472)
						int _g9 = (va_k)++;		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(472)
						va->Set(_g9,0.0);
						HX_STACK_LINE(472)
						int _g10 = (va_k)++;		HX_STACK_VAR(_g10,"_g10");
						HX_STACK_LINE(472)
						va->Set(_g10,sv0);
						HX_STACK_LINE(472)
						int _g111 = (ia_k)++;		HX_STACK_VAR(_g111,"_g111");
						HX_STACK_LINE(472)
						ia->Set(_g111,id);
						HX_STACK_LINE(473)
						int _g12 = (va_k)++;		HX_STACK_VAR(_g12,"_g12");
						HX_STACK_LINE(473)
						va->Set(_g12,cv1);
						HX_STACK_LINE(473)
						int _g13 = (va_k)++;		HX_STACK_VAR(_g13,"_g13");
						HX_STACK_LINE(473)
						va->Set(_g13,0.0);
						HX_STACK_LINE(473)
						int _g14 = (va_k)++;		HX_STACK_VAR(_g14,"_g14");
						HX_STACK_LINE(473)
						va->Set(_g14,sv1);
						HX_STACK_LINE(473)
						int _g15 = (ia_k)++;		HX_STACK_VAR(_g15,"_g15");
						HX_STACK_LINE(473)
						ia->Set(_g15,id);
						HX_STACK_LINE(474)
						int _g16 = (va_k)++;		HX_STACK_VAR(_g16,"_g16");
						HX_STACK_LINE(474)
						va->Set(_g16,0.0);
						HX_STACK_LINE(474)
						int _g17 = (va_k)++;		HX_STACK_VAR(_g17,"_g17");
						HX_STACK_LINE(474)
						va->Set(_g17,cv0);
						HX_STACK_LINE(474)
						int _g18 = (va_k)++;		HX_STACK_VAR(_g18,"_g18");
						HX_STACK_LINE(474)
						va->Set(_g18,sv0);
						HX_STACK_LINE(474)
						int _g19 = (ia_k)++;		HX_STACK_VAR(_g19,"_g19");
						HX_STACK_LINE(474)
						ia->Set(_g19,id);
						HX_STACK_LINE(475)
						int _g20 = (va_k)++;		HX_STACK_VAR(_g20,"_g20");
						HX_STACK_LINE(475)
						va->Set(_g20,0.0);
						HX_STACK_LINE(475)
						int _g211 = (va_k)++;		HX_STACK_VAR(_g211,"_g211");
						HX_STACK_LINE(475)
						va->Set(_g211,cv1);
						HX_STACK_LINE(475)
						int _g22 = (va_k)++;		HX_STACK_VAR(_g22,"_g22");
						HX_STACK_LINE(475)
						va->Set(_g22,sv1);
						HX_STACK_LINE(475)
						int _g23 = (ia_k)++;		HX_STACK_VAR(_g23,"_g23");
						HX_STACK_LINE(475)
						ia->Set(_g23,id);
						HX_STACK_LINE(476)
						int _g24 = (va_k)++;		HX_STACK_VAR(_g24,"_g24");
						HX_STACK_LINE(476)
						va->Set(_g24,cv0);
						HX_STACK_LINE(476)
						int _g25 = (va_k)++;		HX_STACK_VAR(_g25,"_g25");
						HX_STACK_LINE(476)
						va->Set(_g25,sv0);
						HX_STACK_LINE(476)
						int _g26 = (va_k)++;		HX_STACK_VAR(_g26,"_g26");
						HX_STACK_LINE(476)
						va->Set(_g26,0.0);
						HX_STACK_LINE(476)
						int _g27 = (ia_k)++;		HX_STACK_VAR(_g27,"_g27");
						HX_STACK_LINE(476)
						ia->Set(_g27,id);
						HX_STACK_LINE(477)
						int _g28 = (va_k)++;		HX_STACK_VAR(_g28,"_g28");
						HX_STACK_LINE(477)
						va->Set(_g28,cv1);
						HX_STACK_LINE(477)
						int _g29 = (va_k)++;		HX_STACK_VAR(_g29,"_g29");
						HX_STACK_LINE(477)
						va->Set(_g29,sv1);
						HX_STACK_LINE(477)
						int _g30 = (va_k)++;		HX_STACK_VAR(_g30,"_g30");
						HX_STACK_LINE(477)
						va->Set(_g30,0.0);
						HX_STACK_LINE(477)
						int _g311 = (ia_k)++;		HX_STACK_VAR(_g311,"_g311");
						HX_STACK_LINE(477)
						ia->Set(_g311,id);
					}
				}
				HX_STACK_LINE(479)
				hx::AddEq(id,1.0);
			}
		}
		HX_STACK_LINE(481)
		m->Set(HX_CSTRING("id"),ia,(int)1);
		HX_STACK_LINE(482)
		m->Set(HX_CSTRING("vertex"),va,(int)3);
		HX_STACK_LINE(483)
		this->mesh = m;
	}
return null();
}



WireSphereGizmo_obj::WireSphereGizmo_obj()
{
}

Dynamic WireSphereGizmo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic WireSphereGizmo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void WireSphereGizmo_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(WireSphereGizmo_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(WireSphereGizmo_obj::__mClass,"__mClass");
};

#endif

Class WireSphereGizmo_obj::__mClass;

void WireSphereGizmo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.WireSphereGizmo"), hx::TCanCast< WireSphereGizmo_obj> ,sStaticFields,sMemberFields,
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

void WireSphereGizmo_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
