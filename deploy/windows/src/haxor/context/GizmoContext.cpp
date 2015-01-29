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
#ifndef INCLUDED_haxor_context_AxisGizmo
#include <haxor/context/AxisGizmo.h>
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
#ifndef INCLUDED_haxor_context_LineGizmo
#include <haxor/context/LineGizmo.h>
#endif
#ifndef INCLUDED_haxor_context_PointGizmo
#include <haxor/context/PointGizmo.h>
#endif
#ifndef INCLUDED_haxor_context_ShaderContext
#include <haxor/context/ShaderContext.h>
#endif
#ifndef INCLUDED_haxor_context_WireCubeGizmo
#include <haxor/context/WireCubeGizmo.h>
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

Void GizmoContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.GizmoContext","new",0x3333c432,"haxor.context.GizmoContext.new","haxor/context/GizmoContext.hx",69,0xa99c50bc)
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
		HX_STACK_FRAME("haxor.context.GizmoContext","Initialize",0x28223fde,"haxor.context.GizmoContext.Initialize","haxor/context/GizmoContext.hx",73,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(74)
		::haxor::graphics::material::Material mat;		HX_STACK_VAR(mat,"mat");
		HX_STACK_LINE(75)
		::haxor::graphics::material::Material _g = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("$GizmoMaterial"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(75)
		::haxor::graphics::material::Material _g1 = this->gizmo_material = _g;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(75)
		mat = _g1;
		HX_STACK_LINE(76)
		::haxor::graphics::material::Shader _g2 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::grid_source);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(76)
		mat->set_shader(_g2);
		HX_STACK_LINE(77)
		mat->blend = true;
		HX_STACK_LINE(78)
		mat->SetBlending((int)770,(int)771);
		HX_STACK_LINE(79)
		mat->SetFloat(HX_CSTRING("Area"),1000.0);
		HX_STACK_LINE(80)
		{
			HX_STACK_LINE(80)
			::haxor::math::Color p_color = ::haxor::math::Color_obj::__new(1.0,1.0,1.0,0.4);		HX_STACK_VAR(p_color,"p_color");
			HX_STACK_LINE(80)
			mat->SetFloat4(HX_CSTRING("Tint"),p_color->r,p_color->g,p_color->b,p_color->a);
		}
		HX_STACK_LINE(81)
		mat->ztest = false;
		HX_STACK_LINE(83)
		::haxor::graphics::material::Material _g3 = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("$TextureMaterial"));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(83)
		::haxor::graphics::material::Material _g4 = this->texture_material = _g3;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(83)
		mat = _g4;
		HX_STACK_LINE(84)
		::haxor::graphics::material::Shader _g5 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::texture_source);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(84)
		mat->set_shader(_g5);
		HX_STACK_LINE(85)
		mat->blend = true;
		HX_STACK_LINE(86)
		mat->SetBlending((int)770,(int)771);
		HX_STACK_LINE(87)
		mat->SetFloat2(HX_CSTRING("Screen"),::haxor::graphics::Screen_obj::m_width,::haxor::graphics::Screen_obj::m_height);
		HX_STACK_LINE(88)
		mat->SetFloat4(HX_CSTRING("Rect"),(int)0,(int)0,(int)100,(int)100);
		HX_STACK_LINE(89)
		{
			HX_STACK_LINE(89)
			::haxor::math::Color p_color = ::haxor::math::Color_obj::__new(1.0,1.0,1.0,1.0);		HX_STACK_VAR(p_color,"p_color");
			HX_STACK_LINE(89)
			mat->SetFloat4(HX_CSTRING("Tint"),p_color->r,p_color->g,p_color->b,p_color->a);
		}
		HX_STACK_LINE(90)
		mat->cull = (int)0;
		HX_STACK_LINE(91)
		mat->ztest = false;
		HX_STACK_LINE(93)
		this->CreateAxis();
		HX_STACK_LINE(94)
		this->CreateGrid(100.0);
		HX_STACK_LINE(95)
		this->CreateTextureQuad();
		HX_STACK_LINE(98)
		::haxor::context::WireSphereGizmo _g6 = ::haxor::context::WireSphereGizmo_obj::__new();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(98)
		this->wire_sphere_renderer = _g6;
		HX_STACK_LINE(99)
		::haxor::context::WireCubeGizmo _g7 = ::haxor::context::WireCubeGizmo_obj::__new();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(99)
		this->wire_cube_renderer = _g7;
		HX_STACK_LINE(100)
		::haxor::context::AxisGizmo _g8 = ::haxor::context::AxisGizmo_obj::__new();		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(100)
		this->axis_renderer = _g8;
		HX_STACK_LINE(101)
		::haxor::context::LineGizmo _g9 = ::haxor::context::LineGizmo_obj::__new();		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(101)
		this->line_renderer = _g9;
		HX_STACK_LINE(102)
		::haxor::context::PointGizmo _g10 = ::haxor::context::PointGizmo_obj::__new();		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(102)
		this->point_renderer = _g10;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GizmoContext_obj,Initialize,(void))

Void GizmoContext_obj::CreateTextureQuad( ){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","CreateTextureQuad",0xdfdc10d8,"haxor.context.GizmoContext.CreateTextureQuad","haxor/context/GizmoContext.hx",109,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(110)
		::haxor::graphics::mesh::Mesh _g = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$TextureQuad"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(110)
		::haxor::graphics::mesh::Mesh m = this->texture = _g;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(111)
		::haxor::io::FloatArray vl;		HX_STACK_VAR(vl,"vl");
		HX_STACK_LINE(112)
		::haxor::io::FloatArray _g1 = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)-1).Add((int)0).Add((int)1).Add((int)-1).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1).Add((int)-1).Add((int)0).Add((int)1).Add((int)0).Add((int)0));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(112)
		vl = _g1;
		HX_STACK_LINE(120)
		m->Set(HX_CSTRING("vertex"),vl,(int)3);
		HX_STACK_LINE(121)
		::haxor::math::AABB3 _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(121)
		{
			HX_STACK_LINE(121)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(121)
			int _g2 = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(121)
			_g3 = _this->m_aabb3->__get(_g2).StaticCast< ::haxor::math::AABB3 >();
		}
		HX_STACK_LINE(121)
		::haxor::math::AABB3 _g4 = m->GenerateAttribBounds(HX_CSTRING("vertex"),_g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(121)
		m->set_bounds(_g4);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GizmoContext_obj,CreateTextureQuad,(void))

Void GizmoContext_obj::CreateAxis( ){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","CreateAxis",0x8e6dec4b,"haxor.context.GizmoContext.CreateAxis","haxor/context/GizmoContext.hx",128,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(129)
		::haxor::graphics::mesh::Mesh _g = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$GridAxis"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(129)
		::haxor::graphics::mesh::Mesh m = this->axis = _g;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(130)
		m->primitive = (int)1;
		HX_STACK_LINE(131)
		::haxor::io::FloatArray vl = ::haxor::io::FloatArray_obj::__new((int)18);		HX_STACK_VAR(vl,"vl");
		HX_STACK_LINE(132)
		::haxor::io::FloatArray cl = ::haxor::io::FloatArray_obj::__new((int)24);		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(133)
		int k;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(136)
		k = (int)0;
		HX_STACK_LINE(138)
		int _g1 = (k)++;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(138)
		vl->Set(_g1,0.0);
		HX_STACK_LINE(138)
		int _g2 = (k)++;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(138)
		vl->Set(_g2,0.0);
		HX_STACK_LINE(138)
		int _g3 = (k)++;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(138)
		vl->Set(_g3,0.0);
		HX_STACK_LINE(139)
		int _g4 = (k)++;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(139)
		vl->Set(_g4,1.0);
		HX_STACK_LINE(139)
		int _g5 = (k)++;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(139)
		vl->Set(_g5,0.0);
		HX_STACK_LINE(139)
		int _g6 = (k)++;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(139)
		vl->Set(_g6,0.0);
		HX_STACK_LINE(142)
		int _g7 = (k)++;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(142)
		vl->Set(_g7,0.0);
		HX_STACK_LINE(142)
		int _g8 = (k)++;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(142)
		vl->Set(_g8,0.0);
		HX_STACK_LINE(142)
		int _g9 = (k)++;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(142)
		vl->Set(_g9,0.0);
		HX_STACK_LINE(143)
		int _g10 = (k)++;		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(143)
		vl->Set(_g10,0.0);
		HX_STACK_LINE(143)
		int _g11 = (k)++;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(143)
		vl->Set(_g11,1.0);
		HX_STACK_LINE(143)
		int _g12 = (k)++;		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(143)
		vl->Set(_g12,0.0);
		HX_STACK_LINE(146)
		int _g13 = (k)++;		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(146)
		vl->Set(_g13,0.0);
		HX_STACK_LINE(146)
		int _g14 = (k)++;		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(146)
		vl->Set(_g14,0.0);
		HX_STACK_LINE(146)
		int _g15 = (k)++;		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(146)
		vl->Set(_g15,0.0);
		HX_STACK_LINE(147)
		int _g16 = (k)++;		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(147)
		vl->Set(_g16,0.0);
		HX_STACK_LINE(147)
		int _g17 = (k)++;		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(147)
		vl->Set(_g17,0.0);
		HX_STACK_LINE(147)
		int _g18 = (k)++;		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(147)
		vl->Set(_g18,1.0);
		HX_STACK_LINE(150)
		k = (int)0;
		HX_STACK_LINE(152)
		int _g19 = (k)++;		HX_STACK_VAR(_g19,"_g19");
		HX_STACK_LINE(152)
		cl->Set(_g19,1.0);
		HX_STACK_LINE(152)
		int _g20 = (k)++;		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(152)
		cl->Set(_g20,0.0);
		HX_STACK_LINE(152)
		int _g21 = (k)++;		HX_STACK_VAR(_g21,"_g21");
		HX_STACK_LINE(152)
		cl->Set(_g21,0.0);
		HX_STACK_LINE(152)
		int _g22 = (k)++;		HX_STACK_VAR(_g22,"_g22");
		HX_STACK_LINE(152)
		cl->Set(_g22,1.0);
		HX_STACK_LINE(153)
		int _g23 = (k)++;		HX_STACK_VAR(_g23,"_g23");
		HX_STACK_LINE(153)
		cl->Set(_g23,1.0);
		HX_STACK_LINE(153)
		int _g24 = (k)++;		HX_STACK_VAR(_g24,"_g24");
		HX_STACK_LINE(153)
		cl->Set(_g24,0.3);
		HX_STACK_LINE(153)
		int _g25 = (k)++;		HX_STACK_VAR(_g25,"_g25");
		HX_STACK_LINE(153)
		cl->Set(_g25,0.3);
		HX_STACK_LINE(153)
		int _g26 = (k)++;		HX_STACK_VAR(_g26,"_g26");
		HX_STACK_LINE(153)
		cl->Set(_g26,1.0);
		HX_STACK_LINE(156)
		int _g27 = (k)++;		HX_STACK_VAR(_g27,"_g27");
		HX_STACK_LINE(156)
		cl->Set(_g27,0.0);
		HX_STACK_LINE(156)
		int _g28 = (k)++;		HX_STACK_VAR(_g28,"_g28");
		HX_STACK_LINE(156)
		cl->Set(_g28,1.0);
		HX_STACK_LINE(156)
		int _g29 = (k)++;		HX_STACK_VAR(_g29,"_g29");
		HX_STACK_LINE(156)
		cl->Set(_g29,0.0);
		HX_STACK_LINE(156)
		int _g30 = (k)++;		HX_STACK_VAR(_g30,"_g30");
		HX_STACK_LINE(156)
		cl->Set(_g30,1.0);
		HX_STACK_LINE(157)
		int _g31 = (k)++;		HX_STACK_VAR(_g31,"_g31");
		HX_STACK_LINE(157)
		cl->Set(_g31,0.3);
		HX_STACK_LINE(157)
		int _g32 = (k)++;		HX_STACK_VAR(_g32,"_g32");
		HX_STACK_LINE(157)
		cl->Set(_g32,1.0);
		HX_STACK_LINE(157)
		int _g33 = (k)++;		HX_STACK_VAR(_g33,"_g33");
		HX_STACK_LINE(157)
		cl->Set(_g33,0.3);
		HX_STACK_LINE(157)
		int _g34 = (k)++;		HX_STACK_VAR(_g34,"_g34");
		HX_STACK_LINE(157)
		cl->Set(_g34,1.0);
		HX_STACK_LINE(160)
		int _g35 = (k)++;		HX_STACK_VAR(_g35,"_g35");
		HX_STACK_LINE(160)
		cl->Set(_g35,0.0);
		HX_STACK_LINE(160)
		int _g36 = (k)++;		HX_STACK_VAR(_g36,"_g36");
		HX_STACK_LINE(160)
		cl->Set(_g36,0.0);
		HX_STACK_LINE(160)
		int _g37 = (k)++;		HX_STACK_VAR(_g37,"_g37");
		HX_STACK_LINE(160)
		cl->Set(_g37,1.0);
		HX_STACK_LINE(160)
		int _g38 = (k)++;		HX_STACK_VAR(_g38,"_g38");
		HX_STACK_LINE(160)
		cl->Set(_g38,1.0);
		HX_STACK_LINE(161)
		int _g39 = (k)++;		HX_STACK_VAR(_g39,"_g39");
		HX_STACK_LINE(161)
		cl->Set(_g39,0.3);
		HX_STACK_LINE(161)
		int _g40 = (k)++;		HX_STACK_VAR(_g40,"_g40");
		HX_STACK_LINE(161)
		cl->Set(_g40,0.3);
		HX_STACK_LINE(161)
		int _g41 = (k)++;		HX_STACK_VAR(_g41,"_g41");
		HX_STACK_LINE(161)
		cl->Set(_g41,1.0);
		HX_STACK_LINE(161)
		int _g42 = (k)++;		HX_STACK_VAR(_g42,"_g42");
		HX_STACK_LINE(161)
		cl->Set(_g42,1.0);
		HX_STACK_LINE(164)
		m->Set(HX_CSTRING("vertex"),vl,(int)3);
		HX_STACK_LINE(165)
		m->Set(HX_CSTRING("color"),cl,(int)4);
		HX_STACK_LINE(167)
		::haxor::math::AABB3 _g44;		HX_STACK_VAR(_g44,"_g44");
		HX_STACK_LINE(167)
		{
			HX_STACK_LINE(167)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(167)
			int _g43 = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g43,"_g43");
			HX_STACK_LINE(167)
			_g44 = _this->m_aabb3->__get(_g43).StaticCast< ::haxor::math::AABB3 >();
		}
		HX_STACK_LINE(167)
		::haxor::math::AABB3 _g45 = m->GenerateAttribBounds(HX_CSTRING("vertex"),_g44);		HX_STACK_VAR(_g45,"_g45");
		HX_STACK_LINE(167)
		m->set_bounds(_g45);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GizmoContext_obj,CreateAxis,(void))

Void GizmoContext_obj::CreateGrid( Float p_step){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","CreateGrid",0x9260a670,"haxor.context.GizmoContext.CreateGrid","haxor/context/GizmoContext.hx",175,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_step,"p_step")
		HX_STACK_LINE(176)
		::haxor::graphics::mesh::Mesh _g = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$GridMesh"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(176)
		this->grid = _g;
		HX_STACK_LINE(177)
		this->grid->primitive = (int)1;
		HX_STACK_LINE(178)
		int len = (p_step + (int)1);		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(179)
		p_step = (Float(1.0) / Float(p_step));
		HX_STACK_LINE(180)
		Float ox = 0.5;		HX_STACK_VAR(ox,"ox");
		HX_STACK_LINE(181)
		Float oz = 0.5;		HX_STACK_VAR(oz,"oz");
		HX_STACK_LINE(182)
		Float px = 0.0;		HX_STACK_VAR(px,"px");
		HX_STACK_LINE(183)
		Float pz = 0.0;		HX_STACK_VAR(pz,"pz");
		HX_STACK_LINE(184)
		::haxor::io::FloatArray vl = ::haxor::io::FloatArray_obj::__new(((int)12 * len));		HX_STACK_VAR(vl,"vl");
		HX_STACK_LINE(185)
		int k;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(187)
		k = (int)0;
		HX_STACK_LINE(188)
		{
			HX_STACK_LINE(188)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(188)
			while((true)){
				HX_STACK_LINE(188)
				if ((!(((_g1 < len))))){
					HX_STACK_LINE(188)
					break;
				}
				HX_STACK_LINE(188)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(190)
				int _g11 = (k)++;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(190)
				vl->Set(_g11,(px - ox));
				HX_STACK_LINE(190)
				int _g2 = (k)++;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(190)
				vl->Set(_g2,0.0);
				HX_STACK_LINE(190)
				int _g3 = (k)++;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(190)
				vl->Set(_g3,oz);
				HX_STACK_LINE(191)
				int _g4 = (k)++;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(191)
				vl->Set(_g4,(px - ox));
				HX_STACK_LINE(191)
				int _g5 = (k)++;		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(191)
				vl->Set(_g5,0.0);
				HX_STACK_LINE(191)
				int _g6 = (k)++;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(191)
				vl->Set(_g6,-(oz));
				HX_STACK_LINE(192)
				hx::AddEq(px,p_step);
			}
		}
		HX_STACK_LINE(196)
		{
			HX_STACK_LINE(196)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(196)
			while((true)){
				HX_STACK_LINE(196)
				if ((!(((_g1 < len))))){
					HX_STACK_LINE(196)
					break;
				}
				HX_STACK_LINE(196)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(198)
				int _g7 = (k)++;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(198)
				vl->Set(_g7,ox);
				HX_STACK_LINE(198)
				int _g8 = (k)++;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(198)
				vl->Set(_g8,0.0);
				HX_STACK_LINE(198)
				int _g9 = (k)++;		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(198)
				vl->Set(_g9,(pz - oz));
				HX_STACK_LINE(199)
				int _g10 = (k)++;		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(199)
				vl->Set(_g10,-(ox));
				HX_STACK_LINE(199)
				int _g11 = (k)++;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(199)
				vl->Set(_g11,0.0);
				HX_STACK_LINE(199)
				int _g12 = (k)++;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(199)
				vl->Set(_g12,(pz - oz));
				HX_STACK_LINE(200)
				hx::AddEq(pz,p_step);
			}
		}
		HX_STACK_LINE(202)
		this->grid->Set(HX_CSTRING("vertex"),vl,(int)3);
		HX_STACK_LINE(203)
		::haxor::math::AABB3 _g14;		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(203)
		{
			HX_STACK_LINE(203)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(203)
			int _g13 = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(203)
			_g14 = _this->m_aabb3->__get(_g13).StaticCast< ::haxor::math::AABB3 >();
		}
		HX_STACK_LINE(203)
		::haxor::math::AABB3 _g15 = this->grid->GenerateAttribBounds(HX_CSTRING("vertex"),_g14);		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(203)
		this->grid->set_bounds(_g15);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GizmoContext_obj,CreateGrid,(void))

Void GizmoContext_obj::DrawGrid( Float p_area,::haxor::math::Color p_color){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawGrid",0xe6e82ff8,"haxor.context.GizmoContext.DrawGrid","haxor/context/GizmoContext.hx",212,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_area,"p_area")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_LINE(213)
		this->gizmo_material->SetFloat(HX_CSTRING("Area"),p_area);
		HX_STACK_LINE(214)
		if (((p_color != null()))){
			HX_STACK_LINE(214)
			this->gizmo_material->SetFloat4(HX_CSTRING("Tint"),p_color->r,p_color->g,p_color->b,p_color->a);
		}
		HX_STACK_LINE(215)
		::haxor::graphics::Graphics_obj::Render(this->grid,this->gizmo_material,null(),::haxor::component::Camera_obj::m_main);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GizmoContext_obj,DrawGrid,(void))

Void GizmoContext_obj::DrawWireSphere( ::haxor::math::Vector3 p_position,Float p_radius,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawWireSphere",0x7691e3e4,"haxor.context.GizmoContext.DrawWireSphere","haxor/context/GizmoContext.hx",225,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_position,"p_position")
		HX_STACK_ARG(p_radius,"p_radius")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_transform,"p_transform")
		struct _Function_1_1{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",226,0xa99c50bc)
				{
					HX_STACK_LINE(226)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(226)
					int _g = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(226)
					return _this->m_v4->__get(_g).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(226)
		::haxor::math::Vector4 _g1 = (_Function_1_1::Block())->Set(p_radius,p_radius,p_radius,1.0);		HX_STACK_VAR(_g1,"_g1");
		struct _Function_1_2{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",226,0xa99c50bc)
				{
					HX_STACK_LINE(226)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(226)
					int _g2 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(226)
					return _this->m_v4->__get(_g2).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(226)
		::haxor::math::Vector4 _g3 = (_Function_1_2::Block())->Set3(p_position);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(226)
		this->wire_sphere_renderer->Push(p_color,_g1,_g3,p_transform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(GizmoContext_obj,DrawWireSphere,(void))

Void GizmoContext_obj::DrawWireCube( ::haxor::math::Vector3 p_position,::haxor::math::Vector3 p_size,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawWireCube",0x91b0be0c,"haxor.context.GizmoContext.DrawWireCube","haxor/context/GizmoContext.hx",237,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_position,"p_position")
		HX_STACK_ARG(p_size,"p_size")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_transform,"p_transform")
		struct _Function_1_1{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",238,0xa99c50bc)
				{
					HX_STACK_LINE(238)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(238)
					int _g = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(238)
					return _this->m_v4->__get(_g).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(238)
		::haxor::math::Vector4 _g1 = (_Function_1_1::Block())->Set3(p_size);		HX_STACK_VAR(_g1,"_g1");
		struct _Function_1_2{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",238,0xa99c50bc)
				{
					HX_STACK_LINE(238)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(238)
					int _g2 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(238)
					return _this->m_v4->__get(_g2).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(238)
		::haxor::math::Vector4 _g3 = (_Function_1_2::Block())->Set3(p_position);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(238)
		this->wire_cube_renderer->Push(p_color,_g1,_g3,p_transform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(GizmoContext_obj,DrawWireCube,(void))

Void GizmoContext_obj::DrawAxis( ::haxor::math::Vector3 p_position,::haxor::math::Vector3 p_size,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawAxis",0xe2f575d3,"haxor.context.GizmoContext.DrawAxis","haxor/context/GizmoContext.hx",249,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_position,"p_position")
		HX_STACK_ARG(p_size,"p_size")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_transform,"p_transform")
		struct _Function_1_1{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",250,0xa99c50bc)
				{
					HX_STACK_LINE(250)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(250)
					int _g = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(250)
					return _this->m_v4->__get(_g).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(250)
		::haxor::math::Vector4 _g1 = (_Function_1_1::Block())->Set3(p_size);		HX_STACK_VAR(_g1,"_g1");
		struct _Function_1_2{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",250,0xa99c50bc)
				{
					HX_STACK_LINE(250)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(250)
					int _g2 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(250)
					return _this->m_v4->__get(_g2).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(250)
		::haxor::math::Vector4 _g3 = (_Function_1_2::Block())->Set3(p_position);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(250)
		this->axis_renderer->Push(p_color,_g1,_g3,p_transform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(GizmoContext_obj,DrawAxis,(void))

Void GizmoContext_obj::DrawLine( ::haxor::math::Vector3 p_from,::haxor::math::Vector3 p_to,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawLine",0xea2f7126,"haxor.context.GizmoContext.DrawLine","haxor/context/GizmoContext.hx",261,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_from,"p_from")
		HX_STACK_ARG(p_to,"p_to")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_transform,"p_transform")
		struct _Function_1_1{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",262,0xa99c50bc)
				{
					HX_STACK_LINE(262)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(262)
					int _g = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(262)
					return _this->m_v4->__get(_g).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(262)
		::haxor::math::Vector4 _g1 = (_Function_1_1::Block())->Set3(p_from);		HX_STACK_VAR(_g1,"_g1");
		struct _Function_1_2{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",262,0xa99c50bc)
				{
					HX_STACK_LINE(262)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(262)
					int _g2 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(262)
					return _this->m_v4->__get(_g2).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(262)
		::haxor::math::Vector4 _g3 = (_Function_1_2::Block())->Set3(p_to);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(262)
		this->line_renderer->Push(p_color,_g1,_g3,p_transform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(GizmoContext_obj,DrawLine,(void))

Void GizmoContext_obj::DrawPoint( ::haxor::math::Vector3 p_position,Float p_size,::haxor::math::Color p_color,bool p_smooth,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawPoint",0x50e166de,"haxor.context.GizmoContext.DrawPoint","haxor/context/GizmoContext.hx",274,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_position,"p_position")
		HX_STACK_ARG(p_size,"p_size")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_smooth,"p_smooth")
		HX_STACK_ARG(p_transform,"p_transform")
		struct _Function_1_1{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",275,0xa99c50bc)
				{
					HX_STACK_LINE(275)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(275)
					int _g = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(275)
					return _this->m_v4->__get(_g).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(275)
		::haxor::math::Vector4 _g1 = (_Function_1_1::Block())->Set(p_size,(  ((p_smooth)) ? Float(1.0) : Float(0.0) ),0.0,0.0);		HX_STACK_VAR(_g1,"_g1");
		struct _Function_1_2{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",275,0xa99c50bc)
				{
					HX_STACK_LINE(275)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(275)
					int _g2 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(275)
					return _this->m_v4->__get(_g2).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(275)
		::haxor::math::Vector4 _g3 = (_Function_1_2::Block())->Set3(p_position);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(275)
		this->point_renderer->Push(p_color,_g1,_g3,p_transform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(GizmoContext_obj,DrawPoint,(void))

Void GizmoContext_obj::Render( ){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","Render",0x05e69ae4,"haxor.context.GizmoContext.Render","haxor/context/GizmoContext.hx",282,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(283)
		::haxor::context::Gizmo gr;		HX_STACK_VAR(gr,"gr");
		HX_STACK_LINE(284)
		gr = this->wire_sphere_renderer;
		HX_STACK_LINE(284)
		gr->Render();
		HX_STACK_LINE(284)
		gr->Clear();
		HX_STACK_LINE(285)
		gr = this->wire_cube_renderer;
		HX_STACK_LINE(285)
		gr->Render();
		HX_STACK_LINE(285)
		gr->Clear();
		HX_STACK_LINE(286)
		gr = this->axis_renderer;
		HX_STACK_LINE(286)
		gr->Render();
		HX_STACK_LINE(286)
		gr->Clear();
		HX_STACK_LINE(287)
		gr = this->line_renderer;
		HX_STACK_LINE(287)
		gr->Render();
		HX_STACK_LINE(287)
		gr->Clear();
		HX_STACK_LINE(288)
		gr = this->point_renderer;
		HX_STACK_LINE(288)
		gr->Render();
		HX_STACK_LINE(288)
		gr->Clear();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GizmoContext_obj,Render,(void))


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
	HX_MARK_MEMBER_NAME(wire_sphere_renderer,"wire_sphere_renderer");
	HX_MARK_MEMBER_NAME(wire_cube_renderer,"wire_cube_renderer");
	HX_MARK_MEMBER_NAME(axis_renderer,"axis_renderer");
	HX_MARK_MEMBER_NAME(line_renderer,"line_renderer");
	HX_MARK_MEMBER_NAME(point_renderer,"point_renderer");
	HX_MARK_MEMBER_NAME(point_smooth_renderer,"point_smooth_renderer");
	HX_MARK_END_CLASS();
}

void GizmoContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(grid,"grid");
	HX_VISIT_MEMBER_NAME(axis,"axis");
	HX_VISIT_MEMBER_NAME(texture,"texture");
	HX_VISIT_MEMBER_NAME(gizmo_material,"gizmo_material");
	HX_VISIT_MEMBER_NAME(texture_material,"texture_material");
	HX_VISIT_MEMBER_NAME(wire_sphere_renderer,"wire_sphere_renderer");
	HX_VISIT_MEMBER_NAME(wire_cube_renderer,"wire_cube_renderer");
	HX_VISIT_MEMBER_NAME(axis_renderer,"axis_renderer");
	HX_VISIT_MEMBER_NAME(line_renderer,"line_renderer");
	HX_VISIT_MEMBER_NAME(point_renderer,"point_renderer");
	HX_VISIT_MEMBER_NAME(point_smooth_renderer,"point_smooth_renderer");
}

Dynamic GizmoContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"grid") ) { return grid; }
		if (HX_FIELD_EQ(inName,"axis") ) { return axis; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Render") ) { return Render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { return texture; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"DrawGrid") ) { return DrawGrid_dyn(); }
		if (HX_FIELD_EQ(inName,"DrawAxis") ) { return DrawAxis_dyn(); }
		if (HX_FIELD_EQ(inName,"DrawLine") ) { return DrawLine_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"DrawPoint") ) { return DrawPoint_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateAxis") ) { return CreateAxis_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateGrid") ) { return CreateGrid_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"DrawWireCube") ) { return DrawWireCube_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"axis_renderer") ) { return axis_renderer; }
		if (HX_FIELD_EQ(inName,"line_renderer") ) { return line_renderer; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"gizmo_material") ) { return gizmo_material; }
		if (HX_FIELD_EQ(inName,"point_renderer") ) { return point_renderer; }
		if (HX_FIELD_EQ(inName,"DrawWireSphere") ) { return DrawWireSphere_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"texture_material") ) { return texture_material; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"CreateTextureQuad") ) { return CreateTextureQuad_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"wire_cube_renderer") ) { return wire_cube_renderer; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"wire_sphere_renderer") ) { return wire_sphere_renderer; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"point_smooth_renderer") ) { return point_smooth_renderer; }
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
	case 13:
		if (HX_FIELD_EQ(inName,"axis_renderer") ) { axis_renderer=inValue.Cast< ::haxor::context::AxisGizmo >(); return inValue; }
		if (HX_FIELD_EQ(inName,"line_renderer") ) { line_renderer=inValue.Cast< ::haxor::context::LineGizmo >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"gizmo_material") ) { gizmo_material=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
		if (HX_FIELD_EQ(inName,"point_renderer") ) { point_renderer=inValue.Cast< ::haxor::context::PointGizmo >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"texture_material") ) { texture_material=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"wire_cube_renderer") ) { wire_cube_renderer=inValue.Cast< ::haxor::context::WireCubeGizmo >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"wire_sphere_renderer") ) { wire_sphere_renderer=inValue.Cast< ::haxor::context::WireSphereGizmo >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"point_smooth_renderer") ) { point_smooth_renderer=inValue.Cast< ::haxor::context::PointGizmo >(); return inValue; }
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
	outFields->push(HX_CSTRING("wire_sphere_renderer"));
	outFields->push(HX_CSTRING("wire_cube_renderer"));
	outFields->push(HX_CSTRING("axis_renderer"));
	outFields->push(HX_CSTRING("line_renderer"));
	outFields->push(HX_CSTRING("point_renderer"));
	outFields->push(HX_CSTRING("point_smooth_renderer"));
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
	{hx::fsObject /*::haxor::context::WireSphereGizmo*/ ,(int)offsetof(GizmoContext_obj,wire_sphere_renderer),HX_CSTRING("wire_sphere_renderer")},
	{hx::fsObject /*::haxor::context::WireCubeGizmo*/ ,(int)offsetof(GizmoContext_obj,wire_cube_renderer),HX_CSTRING("wire_cube_renderer")},
	{hx::fsObject /*::haxor::context::AxisGizmo*/ ,(int)offsetof(GizmoContext_obj,axis_renderer),HX_CSTRING("axis_renderer")},
	{hx::fsObject /*::haxor::context::LineGizmo*/ ,(int)offsetof(GizmoContext_obj,line_renderer),HX_CSTRING("line_renderer")},
	{hx::fsObject /*::haxor::context::PointGizmo*/ ,(int)offsetof(GizmoContext_obj,point_renderer),HX_CSTRING("point_renderer")},
	{hx::fsObject /*::haxor::context::PointGizmo*/ ,(int)offsetof(GizmoContext_obj,point_smooth_renderer),HX_CSTRING("point_smooth_renderer")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("grid"),
	HX_CSTRING("axis"),
	HX_CSTRING("texture"),
	HX_CSTRING("gizmo_material"),
	HX_CSTRING("texture_material"),
	HX_CSTRING("wire_sphere_renderer"),
	HX_CSTRING("wire_cube_renderer"),
	HX_CSTRING("axis_renderer"),
	HX_CSTRING("line_renderer"),
	HX_CSTRING("point_renderer"),
	HX_CSTRING("point_smooth_renderer"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("CreateTextureQuad"),
	HX_CSTRING("CreateAxis"),
	HX_CSTRING("CreateGrid"),
	HX_CSTRING("DrawGrid"),
	HX_CSTRING("DrawWireSphere"),
	HX_CSTRING("DrawWireCube"),
	HX_CSTRING("DrawAxis"),
	HX_CSTRING("DrawLine"),
	HX_CSTRING("DrawPoint"),
	HX_CSTRING("Render"),
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
