#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_Gizmo
#include <haxor/context/Gizmo.h>
#endif
#ifndef INCLUDED_haxor_context_WireCubeGizmo
#include <haxor/context/WireCubeGizmo.h>
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
namespace haxor{
namespace context{

Void WireCubeGizmo_obj::__construct()
{
HX_STACK_FRAME("haxor.context.WireCubeGizmo","new",0x323c28a7,"haxor.context.WireCubeGizmo.new","haxor/context/GizmoContext.hx",524,0xa99c50bc)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(524)
	super::__construct(::haxor::context::Gizmo_obj::WIRE_CUBE,::haxor::context::Gizmo_obj::MAX_GIZMOS);
}
;
	return null();
}

//WireCubeGizmo_obj::~WireCubeGizmo_obj() { }

Dynamic WireCubeGizmo_obj::__CreateEmpty() { return  new WireCubeGizmo_obj; }
hx::ObjectPtr< WireCubeGizmo_obj > WireCubeGizmo_obj::__new()
{  hx::ObjectPtr< WireCubeGizmo_obj > result = new WireCubeGizmo_obj();
	result->__construct();
	return result;}

Dynamic WireCubeGizmo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< WireCubeGizmo_obj > result = new WireCubeGizmo_obj();
	result->__construct();
	return result;}

Void WireCubeGizmo_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.context.WireCubeGizmo","OnBuild",0x88e12936,"haxor.context.WireCubeGizmo.OnBuild","haxor/context/GizmoContext.hx",530,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(531)
		::haxor::graphics::mesh::Mesh3 m = ::haxor::graphics::mesh::Mesh3_obj::__new(null());		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(532)
		m->set_name(HX_CSTRING("$GizmoWireCubeMesh"));
		HX_STACK_LINE(533)
		m->primitive = (int)1;
		HX_STACK_LINE(534)
		Float a = -0.5;		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(535)
		Float b = 0.5;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(538)
		::haxor::math::Vector3 _g = ::haxor::math::Vector3_obj::__new(a,a,a);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(538)
		::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new(a,a,b);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(538)
		::haxor::math::Vector3 _g2 = ::haxor::math::Vector3_obj::__new(b,a,b);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(538)
		::haxor::math::Vector3 _g3 = ::haxor::math::Vector3_obj::__new(b,a,a);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(539)
		::haxor::math::Vector3 _g4 = ::haxor::math::Vector3_obj::__new(a,b,a);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(539)
		::haxor::math::Vector3 _g5 = ::haxor::math::Vector3_obj::__new(a,b,b);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(539)
		::haxor::math::Vector3 _g6 = ::haxor::math::Vector3_obj::__new(b,b,b);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(539)
		::haxor::math::Vector3 _g7 = ::haxor::math::Vector3_obj::__new(b,b,a);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(537)
		Array< ::Dynamic > p = Array_obj< ::Dynamic >::__new().Add(_g).Add(_g1).Add(_g2).Add(_g3).Add(_g4).Add(_g5).Add(_g6).Add(_g7);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(542)
		Array< int > tp = Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)1).Add((int)2).Add((int)2).Add((int)3).Add((int)3).Add((int)0).Add((int)4).Add((int)5).Add((int)5).Add((int)6).Add((int)6).Add((int)7).Add((int)7).Add((int)4).Add((int)0).Add((int)1).Add((int)1).Add((int)5).Add((int)5).Add((int)4).Add((int)4).Add((int)0).Add((int)3).Add((int)2).Add((int)2).Add((int)6).Add((int)6).Add((int)7).Add((int)7).Add((int)3).Add((int)0).Add((int)3).Add((int)3).Add((int)7).Add((int)7).Add((int)4).Add((int)4).Add((int)0).Add((int)1).Add((int)5).Add((int)5).Add((int)6).Add((int)6).Add((int)2).Add((int)2).Add((int)1);		HX_STACK_VAR(tp,"tp");
		HX_STACK_LINE(550)
		::haxor::io::FloatArray va = ::haxor::io::FloatArray_obj::__new(((tp->length * (int)3) * this->m_gizmo_count));		HX_STACK_VAR(va,"va");
		HX_STACK_LINE(551)
		::haxor::io::FloatArray ia = ::haxor::io::FloatArray_obj::__new((tp->length * this->m_gizmo_count));		HX_STACK_VAR(ia,"ia");
		HX_STACK_LINE(552)
		int va_k = (int)0;		HX_STACK_VAR(va_k,"va_k");
		HX_STACK_LINE(553)
		int ia_k = (int)0;		HX_STACK_VAR(ia_k,"ia_k");
		HX_STACK_LINE(554)
		Float id = 0.0;		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(555)
		{
			HX_STACK_LINE(555)
			int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(555)
			int _g8 = this->m_gizmo_count;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(555)
			while((true)){
				HX_STACK_LINE(555)
				if ((!(((_g11 < _g8))))){
					HX_STACK_LINE(555)
					break;
				}
				HX_STACK_LINE(555)
				int k = (_g11)++;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(557)
				{
					HX_STACK_LINE(557)
					int _g31 = (int)0;		HX_STACK_VAR(_g31,"_g31");
					HX_STACK_LINE(557)
					int _g21 = tp->length;		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(557)
					while((true)){
						HX_STACK_LINE(557)
						if ((!(((_g31 < _g21))))){
							HX_STACK_LINE(557)
							break;
						}
						HX_STACK_LINE(557)
						int i = (_g31)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(559)
						int vid = tp->__get(i);		HX_STACK_VAR(vid,"vid");
						HX_STACK_LINE(560)
						int _g81 = (va_k)++;		HX_STACK_VAR(_g81,"_g81");
						HX_STACK_LINE(560)
						va->Set(_g81,p->__get(vid).StaticCast< ::haxor::math::Vector3 >()->x);
						HX_STACK_LINE(561)
						int _g9 = (va_k)++;		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(561)
						va->Set(_g9,p->__get(vid).StaticCast< ::haxor::math::Vector3 >()->y);
						HX_STACK_LINE(562)
						int _g10 = (va_k)++;		HX_STACK_VAR(_g10,"_g10");
						HX_STACK_LINE(562)
						va->Set(_g10,p->__get(vid).StaticCast< ::haxor::math::Vector3 >()->z);
						HX_STACK_LINE(563)
						int _g111 = (ia_k)++;		HX_STACK_VAR(_g111,"_g111");
						HX_STACK_LINE(563)
						ia->Set(_g111,id);
					}
				}
				HX_STACK_LINE(565)
				hx::AddEq(id,1.0);
			}
		}
		HX_STACK_LINE(567)
		m->Set(HX_CSTRING("id"),ia,(int)1);
		HX_STACK_LINE(568)
		m->Set(HX_CSTRING("vertex"),va,(int)3);
		HX_STACK_LINE(569)
		this->mesh = m;
	}
return null();
}



WireCubeGizmo_obj::WireCubeGizmo_obj()
{
}

Dynamic WireCubeGizmo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic WireCubeGizmo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void WireCubeGizmo_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(WireCubeGizmo_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(WireCubeGizmo_obj::__mClass,"__mClass");
};

#endif

Class WireCubeGizmo_obj::__mClass;

void WireCubeGizmo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.WireCubeGizmo"), hx::TCanCast< WireCubeGizmo_obj> ,sStaticFields,sMemberFields,
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

void WireCubeGizmo_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
