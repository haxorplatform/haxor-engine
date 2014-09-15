#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Camera
#include <haxor/component/Camera.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_GizmoContext
#include <haxor/context/GizmoContext.h>
#endif
#ifndef INCLUDED_haxor_context_ShaderContext
#include <haxor/context/ShaderContext.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_Graphics
#include <haxor/graphics/Graphics.h>
#endif
#ifndef INCLUDED_haxor_graphics_Screen
#include <haxor/graphics/Screen.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Shader
#include <haxor/graphics/material/Shader.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#include <haxor/graphics/mesh/Mesh.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshAttrib
#include <haxor/graphics/mesh/MeshAttrib.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
#ifndef INCLUDED_haxor_math_AABB3
#include <haxor/math/AABB3.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
namespace haxor{
namespace context{

Void GizmoContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.GizmoContext","new",0x3333c432,"haxor.context.GizmoContext.new","haxor/context/GizmoContext.hx",50,0xa99c50bc)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//GizmoContext_obj::~GizmoContext_obj() { }

Dynamic GizmoContext_obj::__CreateEmpty() { return  new GizmoContext_obj; }
hx::ObjectPtr< GizmoContext_obj > GizmoContext_obj::__new()
{  hx::ObjectPtr< GizmoContext_obj > result = new GizmoContext_obj();
	result->__construct();
	return result;}

Dynamic GizmoContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GizmoContext_obj > result = new GizmoContext_obj();
	result->__construct();
	return result;}

Void GizmoContext_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","Initialize",0x28223fde,"haxor.context.GizmoContext.Initialize","haxor/context/GizmoContext.hx",56,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(57)
		::haxor::graphics::material::Material mat;		HX_STACK_VAR(mat,"mat");
		HX_STACK_LINE(58)
		::haxor::graphics::material::Material _g = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("$GizmoMaterial"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(58)
		::haxor::graphics::material::Material _g1 = this->gizmo_material = _g;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(58)
		mat = _g1;
		HX_STACK_LINE(59)
		::haxor::graphics::material::Shader _g2 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::gizmo_source);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(59)
		mat->set_shader(_g2);
		HX_STACK_LINE(60)
		mat->blend = true;
		HX_STACK_LINE(61)
		mat->SetBlending((int)770,(int)771);
		HX_STACK_LINE(62)
		mat->SetFloat(HX_CSTRING("Area"),1000.0);
		HX_STACK_LINE(63)
		{
			HX_STACK_LINE(63)
			::haxor::math::Color p_color = ::haxor::math::Color_obj::__new(1.0,1.0,1.0,0.4);		HX_STACK_VAR(p_color,"p_color");
			HX_STACK_LINE(63)
			mat->SetFloat4(HX_CSTRING("Tint"),p_color->r,p_color->g,p_color->b,p_color->a);
		}
		HX_STACK_LINE(64)
		mat->ztest = false;
		HX_STACK_LINE(66)
		::haxor::graphics::material::Material _g3 = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("$TextureMaterial"));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(66)
		::haxor::graphics::material::Material _g4 = this->texture_material = _g3;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(66)
		mat = _g4;
		HX_STACK_LINE(67)
		::haxor::graphics::material::Shader _g5 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::texture_source);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(67)
		mat->set_shader(_g5);
		HX_STACK_LINE(68)
		mat->blend = true;
		HX_STACK_LINE(69)
		mat->SetBlending((int)770,(int)771);
		HX_STACK_LINE(70)
		mat->SetFloat2(HX_CSTRING("Screen"),::haxor::graphics::Screen_obj::m_width,::haxor::graphics::Screen_obj::m_height);
		HX_STACK_LINE(71)
		mat->SetFloat4(HX_CSTRING("Rect"),(int)0,(int)0,(int)100,(int)100);
		HX_STACK_LINE(72)
		{
			HX_STACK_LINE(72)
			::haxor::math::Color p_color = ::haxor::math::Color_obj::__new(1.0,1.0,1.0,1.0);		HX_STACK_VAR(p_color,"p_color");
			HX_STACK_LINE(72)
			mat->SetFloat4(HX_CSTRING("Tint"),p_color->r,p_color->g,p_color->b,p_color->a);
		}
		HX_STACK_LINE(73)
		mat->cull = (int)0;
		HX_STACK_LINE(74)
		mat->ztest = false;
		HX_STACK_LINE(76)
		this->CreateAxis();
		HX_STACK_LINE(77)
		this->CreateGrid(100.0);
		HX_STACK_LINE(78)
		this->CreateTextureQuad();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GizmoContext_obj,Initialize,(void))

Void GizmoContext_obj::CreateTextureQuad( ){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","CreateTextureQuad",0xdfdc10d8,"haxor.context.GizmoContext.CreateTextureQuad","haxor/context/GizmoContext.hx",85,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(86)
		::haxor::graphics::mesh::Mesh _g = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$TextureQuad"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(86)
		::haxor::graphics::mesh::Mesh m = this->texture = _g;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(87)
		::haxor::io::FloatArray vl;		HX_STACK_VAR(vl,"vl");
		HX_STACK_LINE(88)
		::haxor::io::FloatArray _g1 = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)-1).Add((int)0).Add((int)1).Add((int)-1).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1).Add((int)-1).Add((int)0).Add((int)1).Add((int)0).Add((int)0));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(88)
		vl = _g1;
		HX_STACK_LINE(96)
		m->Set(HX_CSTRING("vertex"),vl,(int)3);
		HX_STACK_LINE(97)
		::haxor::math::AABB3 _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(97)
		{
			HX_STACK_LINE(97)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(97)
			int _g2 = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(97)
			_g3 = _this->m_aabb3->__get(_g2).StaticCast< ::haxor::math::AABB3 >();
		}
		HX_STACK_LINE(97)
		::haxor::math::AABB3 _g4 = m->GenerateAttribBounds(HX_CSTRING("vertex"),_g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(97)
		m->set_bounds(_g4);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GizmoContext_obj,CreateTextureQuad,(void))

Void GizmoContext_obj::CreateAxis( ){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","CreateAxis",0x8e6dec4b,"haxor.context.GizmoContext.CreateAxis","haxor/context/GizmoContext.hx",104,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(105)
		::haxor::graphics::mesh::Mesh _g = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$GridAxis"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(105)
		::haxor::graphics::mesh::Mesh m = this->axis = _g;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(106)
		m->primitive = (int)1;
		HX_STACK_LINE(107)
		::haxor::io::FloatArray vl = ::haxor::io::FloatArray_obj::__new((int)18);		HX_STACK_VAR(vl,"vl");
		HX_STACK_LINE(108)
		::haxor::io::FloatArray cl = ::haxor::io::FloatArray_obj::__new((int)24);		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(109)
		int k;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(112)
		k = (int)0;
		HX_STACK_LINE(114)
		int _g1 = (k)++;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(114)
		vl->Set(_g1,0.0);
		HX_STACK_LINE(114)
		int _g2 = (k)++;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(114)
		vl->Set(_g2,0.0);
		HX_STACK_LINE(114)
		int _g3 = (k)++;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(114)
		vl->Set(_g3,0.0);
		HX_STACK_LINE(115)
		int _g4 = (k)++;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(115)
		vl->Set(_g4,1.0);
		HX_STACK_LINE(115)
		int _g5 = (k)++;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(115)
		vl->Set(_g5,0.0);
		HX_STACK_LINE(115)
		int _g6 = (k)++;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(115)
		vl->Set(_g6,0.0);
		HX_STACK_LINE(118)
		int _g7 = (k)++;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(118)
		vl->Set(_g7,0.0);
		HX_STACK_LINE(118)
		int _g8 = (k)++;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(118)
		vl->Set(_g8,0.0);
		HX_STACK_LINE(118)
		int _g9 = (k)++;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(118)
		vl->Set(_g9,0.0);
		HX_STACK_LINE(119)
		int _g10 = (k)++;		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(119)
		vl->Set(_g10,0.0);
		HX_STACK_LINE(119)
		int _g11 = (k)++;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(119)
		vl->Set(_g11,1.0);
		HX_STACK_LINE(119)
		int _g12 = (k)++;		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(119)
		vl->Set(_g12,0.0);
		HX_STACK_LINE(122)
		int _g13 = (k)++;		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(122)
		vl->Set(_g13,0.0);
		HX_STACK_LINE(122)
		int _g14 = (k)++;		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(122)
		vl->Set(_g14,0.0);
		HX_STACK_LINE(122)
		int _g15 = (k)++;		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(122)
		vl->Set(_g15,0.0);
		HX_STACK_LINE(123)
		int _g16 = (k)++;		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(123)
		vl->Set(_g16,0.0);
		HX_STACK_LINE(123)
		int _g17 = (k)++;		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(123)
		vl->Set(_g17,0.0);
		HX_STACK_LINE(123)
		int _g18 = (k)++;		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(123)
		vl->Set(_g18,1.0);
		HX_STACK_LINE(126)
		k = (int)0;
		HX_STACK_LINE(128)
		int _g19 = (k)++;		HX_STACK_VAR(_g19,"_g19");
		HX_STACK_LINE(128)
		cl->Set(_g19,1.0);
		HX_STACK_LINE(128)
		int _g20 = (k)++;		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(128)
		cl->Set(_g20,0.0);
		HX_STACK_LINE(128)
		int _g21 = (k)++;		HX_STACK_VAR(_g21,"_g21");
		HX_STACK_LINE(128)
		cl->Set(_g21,0.0);
		HX_STACK_LINE(128)
		int _g22 = (k)++;		HX_STACK_VAR(_g22,"_g22");
		HX_STACK_LINE(128)
		cl->Set(_g22,1.0);
		HX_STACK_LINE(129)
		int _g23 = (k)++;		HX_STACK_VAR(_g23,"_g23");
		HX_STACK_LINE(129)
		cl->Set(_g23,1.0);
		HX_STACK_LINE(129)
		int _g24 = (k)++;		HX_STACK_VAR(_g24,"_g24");
		HX_STACK_LINE(129)
		cl->Set(_g24,0.3);
		HX_STACK_LINE(129)
		int _g25 = (k)++;		HX_STACK_VAR(_g25,"_g25");
		HX_STACK_LINE(129)
		cl->Set(_g25,0.3);
		HX_STACK_LINE(129)
		int _g26 = (k)++;		HX_STACK_VAR(_g26,"_g26");
		HX_STACK_LINE(129)
		cl->Set(_g26,1.0);
		HX_STACK_LINE(132)
		int _g27 = (k)++;		HX_STACK_VAR(_g27,"_g27");
		HX_STACK_LINE(132)
		cl->Set(_g27,0.0);
		HX_STACK_LINE(132)
		int _g28 = (k)++;		HX_STACK_VAR(_g28,"_g28");
		HX_STACK_LINE(132)
		cl->Set(_g28,1.0);
		HX_STACK_LINE(132)
		int _g29 = (k)++;		HX_STACK_VAR(_g29,"_g29");
		HX_STACK_LINE(132)
		cl->Set(_g29,0.0);
		HX_STACK_LINE(132)
		int _g30 = (k)++;		HX_STACK_VAR(_g30,"_g30");
		HX_STACK_LINE(132)
		cl->Set(_g30,1.0);
		HX_STACK_LINE(133)
		int _g31 = (k)++;		HX_STACK_VAR(_g31,"_g31");
		HX_STACK_LINE(133)
		cl->Set(_g31,0.3);
		HX_STACK_LINE(133)
		int _g32 = (k)++;		HX_STACK_VAR(_g32,"_g32");
		HX_STACK_LINE(133)
		cl->Set(_g32,1.0);
		HX_STACK_LINE(133)
		int _g33 = (k)++;		HX_STACK_VAR(_g33,"_g33");
		HX_STACK_LINE(133)
		cl->Set(_g33,0.3);
		HX_STACK_LINE(133)
		int _g34 = (k)++;		HX_STACK_VAR(_g34,"_g34");
		HX_STACK_LINE(133)
		cl->Set(_g34,1.0);
		HX_STACK_LINE(136)
		int _g35 = (k)++;		HX_STACK_VAR(_g35,"_g35");
		HX_STACK_LINE(136)
		cl->Set(_g35,0.0);
		HX_STACK_LINE(136)
		int _g36 = (k)++;		HX_STACK_VAR(_g36,"_g36");
		HX_STACK_LINE(136)
		cl->Set(_g36,0.0);
		HX_STACK_LINE(136)
		int _g37 = (k)++;		HX_STACK_VAR(_g37,"_g37");
		HX_STACK_LINE(136)
		cl->Set(_g37,1.0);
		HX_STACK_LINE(136)
		int _g38 = (k)++;		HX_STACK_VAR(_g38,"_g38");
		HX_STACK_LINE(136)
		cl->Set(_g38,1.0);
		HX_STACK_LINE(137)
		int _g39 = (k)++;		HX_STACK_VAR(_g39,"_g39");
		HX_STACK_LINE(137)
		cl->Set(_g39,0.3);
		HX_STACK_LINE(137)
		int _g40 = (k)++;		HX_STACK_VAR(_g40,"_g40");
		HX_STACK_LINE(137)
		cl->Set(_g40,0.3);
		HX_STACK_LINE(137)
		int _g41 = (k)++;		HX_STACK_VAR(_g41,"_g41");
		HX_STACK_LINE(137)
		cl->Set(_g41,1.0);
		HX_STACK_LINE(137)
		int _g42 = (k)++;		HX_STACK_VAR(_g42,"_g42");
		HX_STACK_LINE(137)
		cl->Set(_g42,1.0);
		HX_STACK_LINE(140)
		m->Set(HX_CSTRING("vertex"),vl,(int)3);
		HX_STACK_LINE(141)
		m->Set(HX_CSTRING("color"),cl,(int)4);
		HX_STACK_LINE(143)
		::haxor::math::AABB3 _g44;		HX_STACK_VAR(_g44,"_g44");
		HX_STACK_LINE(143)
		{
			HX_STACK_LINE(143)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(143)
			int _g43 = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g43,"_g43");
			HX_STACK_LINE(143)
			_g44 = _this->m_aabb3->__get(_g43).StaticCast< ::haxor::math::AABB3 >();
		}
		HX_STACK_LINE(143)
		::haxor::math::AABB3 _g45 = m->GenerateAttribBounds(HX_CSTRING("vertex"),_g44);		HX_STACK_VAR(_g45,"_g45");
		HX_STACK_LINE(143)
		m->set_bounds(_g45);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GizmoContext_obj,CreateAxis,(void))

Void GizmoContext_obj::CreateGrid( Float p_step){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","CreateGrid",0x9260a670,"haxor.context.GizmoContext.CreateGrid","haxor/context/GizmoContext.hx",151,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_step,"p_step")
		HX_STACK_LINE(152)
		::haxor::graphics::mesh::Mesh _g = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$GridMesh"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(152)
		this->grid = _g;
		HX_STACK_LINE(153)
		this->grid->primitive = (int)1;
		HX_STACK_LINE(154)
		int len = (p_step + (int)1);		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(155)
		p_step = (Float(1.0) / Float(p_step));
		HX_STACK_LINE(156)
		Float ox = 0.5;		HX_STACK_VAR(ox,"ox");
		HX_STACK_LINE(157)
		Float oz = 0.5;		HX_STACK_VAR(oz,"oz");
		HX_STACK_LINE(158)
		Float px = 0.0;		HX_STACK_VAR(px,"px");
		HX_STACK_LINE(159)
		Float pz = 0.0;		HX_STACK_VAR(pz,"pz");
		HX_STACK_LINE(160)
		::haxor::io::FloatArray vl = ::haxor::io::FloatArray_obj::__new(((int)12 * len));		HX_STACK_VAR(vl,"vl");
		HX_STACK_LINE(161)
		int k;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(163)
		k = (int)0;
		HX_STACK_LINE(164)
		{
			HX_STACK_LINE(164)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(164)
			while((true)){
				HX_STACK_LINE(164)
				if ((!(((_g1 < len))))){
					HX_STACK_LINE(164)
					break;
				}
				HX_STACK_LINE(164)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(166)
				int _g11 = (k)++;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(166)
				vl->Set(_g11,(px - ox));
				HX_STACK_LINE(166)
				int _g2 = (k)++;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(166)
				vl->Set(_g2,0.0);
				HX_STACK_LINE(166)
				int _g3 = (k)++;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(166)
				vl->Set(_g3,oz);
				HX_STACK_LINE(167)
				int _g4 = (k)++;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(167)
				vl->Set(_g4,(px - ox));
				HX_STACK_LINE(167)
				int _g5 = (k)++;		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(167)
				vl->Set(_g5,0.0);
				HX_STACK_LINE(167)
				int _g6 = (k)++;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(167)
				vl->Set(_g6,-(oz));
				HX_STACK_LINE(168)
				hx::AddEq(px,p_step);
			}
		}
		HX_STACK_LINE(172)
		{
			HX_STACK_LINE(172)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(172)
			while((true)){
				HX_STACK_LINE(172)
				if ((!(((_g1 < len))))){
					HX_STACK_LINE(172)
					break;
				}
				HX_STACK_LINE(172)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(174)
				int _g7 = (k)++;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(174)
				vl->Set(_g7,ox);
				HX_STACK_LINE(174)
				int _g8 = (k)++;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(174)
				vl->Set(_g8,0.0);
				HX_STACK_LINE(174)
				int _g9 = (k)++;		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(174)
				vl->Set(_g9,(pz - oz));
				HX_STACK_LINE(175)
				int _g10 = (k)++;		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(175)
				vl->Set(_g10,-(ox));
				HX_STACK_LINE(175)
				int _g11 = (k)++;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(175)
				vl->Set(_g11,0.0);
				HX_STACK_LINE(175)
				int _g12 = (k)++;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(175)
				vl->Set(_g12,(pz - oz));
				HX_STACK_LINE(176)
				hx::AddEq(pz,p_step);
			}
		}
		HX_STACK_LINE(178)
		this->grid->Set(HX_CSTRING("vertex"),vl,(int)3);
		HX_STACK_LINE(179)
		::haxor::math::AABB3 _g14;		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(179)
		{
			HX_STACK_LINE(179)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(179)
			int _g13 = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(179)
			_g14 = _this->m_aabb3->__get(_g13).StaticCast< ::haxor::math::AABB3 >();
		}
		HX_STACK_LINE(179)
		::haxor::math::AABB3 _g15 = this->grid->GenerateAttribBounds(HX_CSTRING("vertex"),_g14);		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(179)
		this->grid->set_bounds(_g15);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GizmoContext_obj,CreateGrid,(void))

Void GizmoContext_obj::DrawGrid( Float p_area,::haxor::math::Color p_color){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawGrid",0xe6e82ff8,"haxor.context.GizmoContext.DrawGrid","haxor/context/GizmoContext.hx",188,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_area,"p_area")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_LINE(189)
		this->gizmo_material->SetFloat(HX_CSTRING("Area"),p_area);
		HX_STACK_LINE(190)
		if (((p_color != null()))){
			HX_STACK_LINE(190)
			this->gizmo_material->SetFloat4(HX_CSTRING("Tint"),p_color->r,p_color->g,p_color->b,p_color->a);
		}
		HX_STACK_LINE(191)
		::haxor::graphics::Graphics_obj::Render(this->grid,this->gizmo_material,null(),::haxor::component::Camera_obj::m_main);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GizmoContext_obj,DrawGrid,(void))

Void GizmoContext_obj::DrawAxis( Float p_area){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawAxis",0xe2f575d3,"haxor.context.GizmoContext.DrawAxis","haxor/context/GizmoContext.hx",199,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_area,"p_area")
		HX_STACK_LINE(200)
		this->gizmo_material->SetFloat(HX_CSTRING("Area"),p_area);
		HX_STACK_LINE(201)
		{
			struct _Function_2_1{
				inline static ::haxor::math::Color Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",201,0xa99c50bc)
					{
						HX_STACK_LINE(201)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(201)
						int _g = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(201)
						return _this->m_c->__get(_g).StaticCast< ::haxor::math::Color >();
					}
					return null();
				}
			};
			HX_STACK_LINE(201)
			::haxor::math::Color p_color = (_Function_2_1::Block())->Set((int)1,(int)1,(int)1,(int)1);		HX_STACK_VAR(p_color,"p_color");
			HX_STACK_LINE(201)
			this->gizmo_material->SetFloat4(HX_CSTRING("Tint"),p_color->r,p_color->g,p_color->b,p_color->a);
		}
		HX_STACK_LINE(202)
		::haxor::graphics::Graphics_obj::Render(this->axis,this->gizmo_material,null(),::haxor::component::Camera_obj::m_main);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GizmoContext_obj,DrawAxis,(void))


GizmoContext_obj::GizmoContext_obj()
{
}

void GizmoContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GizmoContext);
	HX_MARK_MEMBER_NAME(grid,"grid");
	HX_MARK_MEMBER_NAME(axis,"axis");
	HX_MARK_MEMBER_NAME(texture,"texture");
	HX_MARK_MEMBER_NAME(gizmo_material,"gizmo_material");
	HX_MARK_MEMBER_NAME(texture_material,"texture_material");
	HX_MARK_END_CLASS();
}

void GizmoContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(grid,"grid");
	HX_VISIT_MEMBER_NAME(axis,"axis");
	HX_VISIT_MEMBER_NAME(texture,"texture");
	HX_VISIT_MEMBER_NAME(gizmo_material,"gizmo_material");
	HX_VISIT_MEMBER_NAME(texture_material,"texture_material");
}

Dynamic GizmoContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"grid") ) { return grid; }
		if (HX_FIELD_EQ(inName,"axis") ) { return axis; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { return texture; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"DrawGrid") ) { return DrawGrid_dyn(); }
		if (HX_FIELD_EQ(inName,"DrawAxis") ) { return DrawAxis_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateAxis") ) { return CreateAxis_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateGrid") ) { return CreateGrid_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"gizmo_material") ) { return gizmo_material; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"texture_material") ) { return texture_material; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"CreateTextureQuad") ) { return CreateTextureQuad_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GizmoContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"grid") ) { grid=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"axis") ) { axis=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { texture=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"gizmo_material") ) { gizmo_material=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"texture_material") ) { texture_material=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GizmoContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("grid"));
	outFields->push(HX_CSTRING("axis"));
	outFields->push(HX_CSTRING("texture"));
	outFields->push(HX_CSTRING("gizmo_material"));
	outFields->push(HX_CSTRING("texture_material"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::graphics::mesh::Mesh*/ ,(int)offsetof(GizmoContext_obj,grid),HX_CSTRING("grid")},
	{hx::fsObject /*::haxor::graphics::mesh::Mesh*/ ,(int)offsetof(GizmoContext_obj,axis),HX_CSTRING("axis")},
	{hx::fsObject /*::haxor::graphics::mesh::Mesh*/ ,(int)offsetof(GizmoContext_obj,texture),HX_CSTRING("texture")},
	{hx::fsObject /*::haxor::graphics::material::Material*/ ,(int)offsetof(GizmoContext_obj,gizmo_material),HX_CSTRING("gizmo_material")},
	{hx::fsObject /*::haxor::graphics::material::Material*/ ,(int)offsetof(GizmoContext_obj,texture_material),HX_CSTRING("texture_material")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("grid"),
	HX_CSTRING("axis"),
	HX_CSTRING("texture"),
	HX_CSTRING("gizmo_material"),
	HX_CSTRING("texture_material"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("CreateTextureQuad"),
	HX_CSTRING("CreateAxis"),
	HX_CSTRING("CreateGrid"),
	HX_CSTRING("DrawGrid"),
	HX_CSTRING("DrawAxis"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GizmoContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GizmoContext_obj::__mClass,"__mClass");
};

#endif

Class GizmoContext_obj::__mClass;

void GizmoContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.GizmoContext"), hx::TCanCast< GizmoContext_obj> ,sStaticFields,sMemberFields,
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

void GizmoContext_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
