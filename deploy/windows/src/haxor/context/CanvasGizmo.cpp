#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_CanvasGizmo
#include <haxor/context/CanvasGizmo.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_Gizmo
#include <haxor/context/Gizmo.h>
#endif
#ifndef INCLUDED_haxor_context_GizmoContext
#include <haxor/context/GizmoContext.h>
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
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_math_Vector4
#include <haxor/math/Vector4.h>
#endif
namespace haxor{
namespace context{

Void CanvasGizmo_obj::__construct()
{
HX_STACK_FRAME("haxor.context.CanvasGizmo","new",0x954f30a9,"haxor.context.CanvasGizmo.new","haxor/context/GizmoContext.hx",747,0xa99c50bc)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(748)
	super::__construct(::haxor::context::Gizmo_obj::CANVAS,(int)3000);
	HX_STACK_LINE(749)
	::haxor::math::Color _g = ::haxor::math::Color_obj::__new((int)1,(int)1,(int)1,(int)1);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(749)
	this->fill = _g;
	HX_STACK_LINE(750)
	::haxor::math::Color _g1 = ::haxor::math::Color_obj::__new((int)0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(750)
	this->line = _g1;
	HX_STACK_LINE(751)
	::haxor::math::Vector3 _g2 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(751)
	this->p0 = _g2;
	HX_STACK_LINE(752)
	::haxor::math::Vector3 _g3 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(752)
	this->p1 = _g3;
	HX_STACK_LINE(753)
	::haxor::math::Vector3 _g4 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(753)
	this->start = _g4;
	HX_STACK_LINE(754)
	this->count = (int)0;
	HX_STACK_LINE(755)
	this->active = false;
	HX_STACK_LINE(757)
	this->material->cull = (int)0;
}
;
	return null();
}

//CanvasGizmo_obj::~CanvasGizmo_obj() { }

Dynamic CanvasGizmo_obj::__CreateEmpty() { return  new CanvasGizmo_obj; }
hx::ObjectPtr< CanvasGizmo_obj > CanvasGizmo_obj::__new()
{  hx::ObjectPtr< CanvasGizmo_obj > result = new CanvasGizmo_obj();
	result->__construct();
	return result;}

Dynamic CanvasGizmo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CanvasGizmo_obj > result = new CanvasGizmo_obj();
	result->__construct();
	return result;}

Void CanvasGizmo_obj::Begin( ::haxor::math::Color p_fill,::haxor::math::Color p_line,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.context.CanvasGizmo","Begin",0x964e1e92,"haxor.context.CanvasGizmo.Begin","haxor/context/GizmoContext.hx",767,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_fill,"p_fill")
		HX_STACK_ARG(p_line,"p_line")
		HX_STACK_ARG(p_transform,"p_transform")
		HX_STACK_LINE(768)
		if ((this->active)){
			HX_STACK_LINE(768)
			return null();
		}
		HX_STACK_LINE(769)
		this->fill->SetColor(p_fill);
		HX_STACK_LINE(770)
		if (((p_line == null()))){
			HX_STACK_LINE(770)
			this->line->a = 0.0;
		}
		else{
			HX_STACK_LINE(770)
			this->line->SetColor(p_line);
		}
		HX_STACK_LINE(771)
		this->transform = p_transform;
		HX_STACK_LINE(772)
		this->count = (int)0;
		HX_STACK_LINE(773)
		this->active = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(CanvasGizmo_obj,Begin,(void))

Void CanvasGizmo_obj::Line( ::haxor::math::Vector3 p_position){
{
		HX_STACK_FRAME("haxor.context.CanvasGizmo","Line",0xf98523ab,"haxor.context.CanvasGizmo.Line","haxor/context/GizmoContext.hx",781,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_position,"p_position")
		HX_STACK_LINE(782)
		if ((!(this->active))){
			HX_STACK_LINE(782)
			return null();
		}
		HX_STACK_LINE(783)
		if (((this->count >= (int)2))){
			HX_STACK_LINE(783)
			::haxor::context::EngineContext_obj::gizmo->DrawLine(this->p0,this->p1,this->line,this->transform);
		}
		HX_STACK_LINE(784)
		if (((this->count <= (int)0))){
			HX_STACK_LINE(784)
			this->start->Set3(p_position);
		}
		HX_STACK_LINE(786)
		this->p1->Set3(this->p0);
		HX_STACK_LINE(787)
		this->p0->Set3(p_position);
		HX_STACK_LINE(789)
		if (((this->count >= (int)2))){
			struct _Function_2_1{
				inline static ::haxor::math::Vector4 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",791,0xa99c50bc)
					{
						HX_STACK_LINE(791)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(791)
						int _g = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(791)
						return _this->m_v4->__get(_g).StaticCast< ::haxor::math::Vector4 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(791)
			::haxor::math::Vector4 _g1 = (_Function_2_1::Block())->Set((int)1,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g1,"_g1");
			struct _Function_2_2{
				inline static ::haxor::math::Vector4 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",791,0xa99c50bc)
					{
						HX_STACK_LINE(791)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(791)
						int _g2 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(791)
						return _this->m_v4->__get(_g2).StaticCast< ::haxor::math::Vector4 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(791)
			::haxor::math::Vector4 _g3 = (_Function_2_2::Block())->Set3(this->start);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(791)
			this->Push(this->fill,_g1,_g3,this->transform);
			struct _Function_2_3{
				inline static ::haxor::math::Vector4 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",792,0xa99c50bc)
					{
						HX_STACK_LINE(792)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(792)
						int _g4 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(792)
						return _this->m_v4->__get(_g4).StaticCast< ::haxor::math::Vector4 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(792)
			::haxor::math::Vector4 _g5 = (_Function_2_3::Block())->Set((int)1,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g5,"_g5");
			struct _Function_2_4{
				inline static ::haxor::math::Vector4 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",792,0xa99c50bc)
					{
						HX_STACK_LINE(792)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(792)
						int _g6 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(792)
						return _this->m_v4->__get(_g6).StaticCast< ::haxor::math::Vector4 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(792)
			::haxor::math::Vector4 _g7 = (_Function_2_4::Block())->Set3(this->p1);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(792)
			this->Push(this->fill,_g5,_g7,this->transform);
			struct _Function_2_5{
				inline static ::haxor::math::Vector4 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",793,0xa99c50bc)
					{
						HX_STACK_LINE(793)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(793)
						int _g8 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(793)
						return _this->m_v4->__get(_g8).StaticCast< ::haxor::math::Vector4 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(793)
			::haxor::math::Vector4 _g9 = (_Function_2_5::Block())->Set((int)1,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g9,"_g9");
			struct _Function_2_6{
				inline static ::haxor::math::Vector4 Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",793,0xa99c50bc)
					{
						HX_STACK_LINE(793)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(793)
						int _g10 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g10,"_g10");
						HX_STACK_LINE(793)
						return _this->m_v4->__get(_g10).StaticCast< ::haxor::math::Vector4 >();
					}
					return null();
				}
			};
			HX_STACK_LINE(793)
			::haxor::math::Vector4 _g11 = (_Function_2_6::Block())->Set3(this->p0);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(793)
			this->Push(this->fill,_g9,_g11,this->transform);
		}
		HX_STACK_LINE(796)
		(this->count)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CanvasGizmo_obj,Line,(void))

Void CanvasGizmo_obj::End( ){
{
		HX_STACK_FRAME("haxor.context.CanvasGizmo","End",0x95301c04,"haxor.context.CanvasGizmo.End","haxor/context/GizmoContext.hx",803,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(804)
		if ((!(this->active))){
			HX_STACK_LINE(804)
			return null();
		}
		HX_STACK_LINE(805)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(this->p0,this->start,this->line,this->transform);
		HX_STACK_LINE(806)
		::haxor::context::EngineContext_obj::gizmo->DrawLine(this->p0,this->p1,this->line,this->transform);
		HX_STACK_LINE(808)
		this->active = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CanvasGizmo_obj,End,(void))

Void CanvasGizmo_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.context.CanvasGizmo","OnBuild",0xcce55a38,"haxor.context.CanvasGizmo.OnBuild","haxor/context/GizmoContext.hx",815,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(816)
		::haxor::graphics::mesh::Mesh3 m = ::haxor::graphics::mesh::Mesh3_obj::__new(null());		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(817)
		m->set_name(HX_CSTRING("$GizmoCanvasMesh"));
		HX_STACK_LINE(818)
		m->primitive = (int)4;
		HX_STACK_LINE(819)
		Float id = 0.0;		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(820)
		::haxor::io::FloatArray ia = ::haxor::io::FloatArray_obj::__new((this->m_gizmo_count * (int)3));		HX_STACK_VAR(ia,"ia");
		HX_STACK_LINE(821)
		::haxor::io::FloatArray va = ::haxor::io::FloatArray_obj::__new(((this->m_gizmo_count * (int)3) * (int)3));		HX_STACK_VAR(va,"va");
		HX_STACK_LINE(822)
		int va_k = (int)0;		HX_STACK_VAR(va_k,"va_k");
		HX_STACK_LINE(823)
		int ia_k = (int)0;		HX_STACK_VAR(ia_k,"ia_k");
		HX_STACK_LINE(824)
		{
			HX_STACK_LINE(824)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(824)
			int _g = this->m_gizmo_count;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(824)
			while((true)){
				HX_STACK_LINE(824)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(824)
					break;
				}
				HX_STACK_LINE(824)
				int k = (_g1)++;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(826)
				int _g2 = (va_k)++;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(826)
				va->Set(_g2,0.0);
				HX_STACK_LINE(826)
				int _g11 = (va_k)++;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(826)
				va->Set(_g11,0.0);
				HX_STACK_LINE(826)
				int _g21 = (va_k)++;		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(826)
				va->Set(_g21,0.0);
				HX_STACK_LINE(826)
				int _g3 = (ia_k)++;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(826)
				ia->Set(_g3,id);
				HX_STACK_LINE(826)
				hx::AddEq(id,1.0);
				HX_STACK_LINE(827)
				int _g4 = (va_k)++;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(827)
				va->Set(_g4,0.0);
				HX_STACK_LINE(827)
				int _g5 = (va_k)++;		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(827)
				va->Set(_g5,0.0);
				HX_STACK_LINE(827)
				int _g6 = (va_k)++;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(827)
				va->Set(_g6,0.0);
				HX_STACK_LINE(827)
				int _g7 = (ia_k)++;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(827)
				ia->Set(_g7,id);
				HX_STACK_LINE(827)
				hx::AddEq(id,1.0);
				HX_STACK_LINE(828)
				int _g8 = (va_k)++;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(828)
				va->Set(_g8,0.0);
				HX_STACK_LINE(828)
				int _g9 = (va_k)++;		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(828)
				va->Set(_g9,0.0);
				HX_STACK_LINE(828)
				int _g10 = (va_k)++;		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(828)
				va->Set(_g10,0.0);
				HX_STACK_LINE(828)
				int _g111 = (ia_k)++;		HX_STACK_VAR(_g111,"_g111");
				HX_STACK_LINE(828)
				ia->Set(_g111,id);
				HX_STACK_LINE(828)
				hx::AddEq(id,1.0);
			}
		}
		HX_STACK_LINE(831)
		m->Set(HX_CSTRING("id"),ia,(int)1);
		HX_STACK_LINE(832)
		m->Set(HX_CSTRING("vertex"),va,(int)3);
		HX_STACK_LINE(833)
		this->mesh = m;
	}
return null();
}



CanvasGizmo_obj::CanvasGizmo_obj()
{
}

void CanvasGizmo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CanvasGizmo);
	HX_MARK_MEMBER_NAME(fill,"fill");
	HX_MARK_MEMBER_NAME(line,"line");
	HX_MARK_MEMBER_NAME(start,"start");
	HX_MARK_MEMBER_NAME(p0,"p0");
	HX_MARK_MEMBER_NAME(p1,"p1");
	HX_MARK_MEMBER_NAME(transform,"transform");
	HX_MARK_MEMBER_NAME(count,"count");
	HX_MARK_MEMBER_NAME(active,"active");
	::haxor::context::Gizmo_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CanvasGizmo_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(fill,"fill");
	HX_VISIT_MEMBER_NAME(line,"line");
	HX_VISIT_MEMBER_NAME(start,"start");
	HX_VISIT_MEMBER_NAME(p0,"p0");
	HX_VISIT_MEMBER_NAME(p1,"p1");
	HX_VISIT_MEMBER_NAME(transform,"transform");
	HX_VISIT_MEMBER_NAME(count,"count");
	HX_VISIT_MEMBER_NAME(active,"active");
	::haxor::context::Gizmo_obj::__Visit(HX_VISIT_ARG);
}

Dynamic CanvasGizmo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"p0") ) { return p0; }
		if (HX_FIELD_EQ(inName,"p1") ) { return p1; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"End") ) { return End_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"fill") ) { return fill; }
		if (HX_FIELD_EQ(inName,"line") ) { return line; }
		if (HX_FIELD_EQ(inName,"Line") ) { return Line_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return start; }
		if (HX_FIELD_EQ(inName,"count") ) { return count; }
		if (HX_FIELD_EQ(inName,"Begin") ) { return Begin_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { return transform; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CanvasGizmo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"p0") ) { p0=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p1") ) { p1=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"fill") ) { fill=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		if (HX_FIELD_EQ(inName,"line") ) { line=inValue.Cast< ::haxor::math::Color >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { start=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"count") ) { count=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< bool >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { transform=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CanvasGizmo_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("fill"));
	outFields->push(HX_CSTRING("line"));
	outFields->push(HX_CSTRING("start"));
	outFields->push(HX_CSTRING("p0"));
	outFields->push(HX_CSTRING("p1"));
	outFields->push(HX_CSTRING("transform"));
	outFields->push(HX_CSTRING("count"));
	outFields->push(HX_CSTRING("active"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::math::Color*/ ,(int)offsetof(CanvasGizmo_obj,fill),HX_CSTRING("fill")},
	{hx::fsObject /*::haxor::math::Color*/ ,(int)offsetof(CanvasGizmo_obj,line),HX_CSTRING("line")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(CanvasGizmo_obj,start),HX_CSTRING("start")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(CanvasGizmo_obj,p0),HX_CSTRING("p0")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(CanvasGizmo_obj,p1),HX_CSTRING("p1")},
	{hx::fsObject /*::haxor::math::Matrix4*/ ,(int)offsetof(CanvasGizmo_obj,transform),HX_CSTRING("transform")},
	{hx::fsInt,(int)offsetof(CanvasGizmo_obj,count),HX_CSTRING("count")},
	{hx::fsBool,(int)offsetof(CanvasGizmo_obj,active),HX_CSTRING("active")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("fill"),
	HX_CSTRING("line"),
	HX_CSTRING("start"),
	HX_CSTRING("p0"),
	HX_CSTRING("p1"),
	HX_CSTRING("transform"),
	HX_CSTRING("count"),
	HX_CSTRING("active"),
	HX_CSTRING("Begin"),
	HX_CSTRING("Line"),
	HX_CSTRING("End"),
	HX_CSTRING("OnBuild"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CanvasGizmo_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CanvasGizmo_obj::__mClass,"__mClass");
};

#endif

Class CanvasGizmo_obj::__mClass;

void CanvasGizmo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.CanvasGizmo"), hx::TCanCast< CanvasGizmo_obj> ,sStaticFields,sMemberFields,
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

void CanvasGizmo_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
