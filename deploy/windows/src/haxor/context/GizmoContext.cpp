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
#ifndef INCLUDED_haxor_core_IResizeable
#include <haxor/core/IResizeable.h>
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
HX_STACK_FRAME("haxor.context.GizmoContext","new",0x3333c432,"haxor.context.GizmoContext.new","haxor/context/GizmoContext.hx",75,0xa99c50bc)
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
		HX_STACK_FRAME("haxor.context.GizmoContext","Initialize",0x28223fde,"haxor.context.GizmoContext.Initialize","haxor/context/GizmoContext.hx",79,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(80)
		::haxor::graphics::material::Material mat;		HX_STACK_VAR(mat,"mat");
		HX_STACK_LINE(81)
		::haxor::graphics::material::Material _g = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("$GizmoMaterial"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(81)
		::haxor::graphics::material::Material _g1 = this->gizmo_material = _g;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(81)
		mat = _g1;
		HX_STACK_LINE(82)
		::haxor::graphics::material::Shader _g2 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::grid_source);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(82)
		mat->set_shader(_g2);
		HX_STACK_LINE(83)
		mat->blend = true;
		HX_STACK_LINE(84)
		mat->SetBlending((int)770,(int)771);
		HX_STACK_LINE(85)
		mat->SetFloat(HX_CSTRING("Area"),1000.0);
		HX_STACK_LINE(86)
		{
			HX_STACK_LINE(86)
			::haxor::math::Color p_color = ::haxor::math::Color_obj::__new(1.0,1.0,1.0,0.4);		HX_STACK_VAR(p_color,"p_color");
			HX_STACK_LINE(86)
			mat->SetFloat4(HX_CSTRING("Tint"),p_color->r,p_color->g,p_color->b,p_color->a);
		}
		HX_STACK_LINE(87)
		mat->ztest = false;
		HX_STACK_LINE(89)
		::haxor::graphics::material::Material _g3 = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("$TextureMaterial"));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(89)
		::haxor::graphics::material::Material _g4 = this->texture_material = _g3;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(89)
		mat = _g4;
		HX_STACK_LINE(90)
		::haxor::graphics::material::Shader _g5 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::texture_source);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(90)
		mat->set_shader(_g5);
		HX_STACK_LINE(91)
		mat->blend = true;
		HX_STACK_LINE(92)
		mat->SetBlending((int)770,(int)771);
		HX_STACK_LINE(93)
		mat->SetFloat2(HX_CSTRING("Screen"),::haxor::graphics::Screen_obj::m_width,::haxor::graphics::Screen_obj::m_height);
		HX_STACK_LINE(94)
		mat->SetFloat4(HX_CSTRING("Rect"),(int)0,(int)0,(int)100,(int)100);
		HX_STACK_LINE(95)
		{
			HX_STACK_LINE(95)
			::haxor::math::Color p_color = ::haxor::math::Color_obj::__new(1.0,1.0,1.0,1.0);		HX_STACK_VAR(p_color,"p_color");
			HX_STACK_LINE(95)
			mat->SetFloat4(HX_CSTRING("Tint"),p_color->r,p_color->g,p_color->b,p_color->a);
		}
		HX_STACK_LINE(96)
		mat->cull = (int)0;
		HX_STACK_LINE(97)
		mat->ztest = false;
		HX_STACK_LINE(99)
		this->CreateGrid(100.0);
		HX_STACK_LINE(100)
		this->CreateTextureQuad();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GizmoContext_obj,Initialize,(void))

Void GizmoContext_obj::CreateTextureQuad( ){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","CreateTextureQuad",0xdfdc10d8,"haxor.context.GizmoContext.CreateTextureQuad","haxor/context/GizmoContext.hx",116,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(117)
		::haxor::graphics::mesh::Mesh _g = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$TextureQuad"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(117)
		::haxor::graphics::mesh::Mesh m = this->texture = _g;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(118)
		::haxor::io::FloatArray vl;		HX_STACK_VAR(vl,"vl");
		HX_STACK_LINE(119)
		::haxor::io::FloatArray _g1 = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)-1).Add((int)0).Add((int)1).Add((int)-1).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1).Add((int)-1).Add((int)0).Add((int)1).Add((int)0).Add((int)0));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(119)
		vl = _g1;
		HX_STACK_LINE(127)
		m->Set(HX_CSTRING("vertex"),vl,(int)3);
		HX_STACK_LINE(128)
		::haxor::math::AABB3 _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(128)
		{
			HX_STACK_LINE(128)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(128)
			int _g2 = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(128)
			_g3 = _this->m_aabb3->__get(_g2).StaticCast< ::haxor::math::AABB3 >();
		}
		HX_STACK_LINE(128)
		::haxor::math::AABB3 _g4 = m->GenerateAttribBounds(HX_CSTRING("vertex"),_g3);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(128)
		m->set_bounds(_g4);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GizmoContext_obj,CreateTextureQuad,(void))

Void GizmoContext_obj::CreateGrid( Float p_step){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","CreateGrid",0x9260a670,"haxor.context.GizmoContext.CreateGrid","haxor/context/GizmoContext.hx",137,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_step,"p_step")
		HX_STACK_LINE(138)
		::haxor::graphics::mesh::Mesh _g = ::haxor::graphics::mesh::Mesh_obj::__new(HX_CSTRING("$GridMesh"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(138)
		this->grid = _g;
		HX_STACK_LINE(139)
		this->grid->primitive = (int)1;
		HX_STACK_LINE(140)
		int len = (p_step + (int)1);		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(141)
		p_step = (Float(1.0) / Float(p_step));
		HX_STACK_LINE(142)
		Float ox = 0.5;		HX_STACK_VAR(ox,"ox");
		HX_STACK_LINE(143)
		Float oz = 0.5;		HX_STACK_VAR(oz,"oz");
		HX_STACK_LINE(144)
		Float px = 0.0;		HX_STACK_VAR(px,"px");
		HX_STACK_LINE(145)
		Float pz = 0.0;		HX_STACK_VAR(pz,"pz");
		HX_STACK_LINE(146)
		::haxor::io::FloatArray vl = ::haxor::io::FloatArray_obj::__new(((int)12 * len));		HX_STACK_VAR(vl,"vl");
		HX_STACK_LINE(147)
		int k;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(149)
		k = (int)0;
		HX_STACK_LINE(150)
		{
			HX_STACK_LINE(150)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(150)
			while((true)){
				HX_STACK_LINE(150)
				if ((!(((_g1 < len))))){
					HX_STACK_LINE(150)
					break;
				}
				HX_STACK_LINE(150)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(152)
				int _g11 = (k)++;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(152)
				vl->Set(_g11,(px - ox));
				HX_STACK_LINE(152)
				int _g2 = (k)++;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(152)
				vl->Set(_g2,0.0);
				HX_STACK_LINE(152)
				int _g3 = (k)++;		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(152)
				vl->Set(_g3,oz);
				HX_STACK_LINE(153)
				int _g4 = (k)++;		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(153)
				vl->Set(_g4,(px - ox));
				HX_STACK_LINE(153)
				int _g5 = (k)++;		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(153)
				vl->Set(_g5,0.0);
				HX_STACK_LINE(153)
				int _g6 = (k)++;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(153)
				vl->Set(_g6,-(oz));
				HX_STACK_LINE(154)
				hx::AddEq(px,p_step);
			}
		}
		HX_STACK_LINE(158)
		{
			HX_STACK_LINE(158)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(158)
			while((true)){
				HX_STACK_LINE(158)
				if ((!(((_g1 < len))))){
					HX_STACK_LINE(158)
					break;
				}
				HX_STACK_LINE(158)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(160)
				int _g7 = (k)++;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(160)
				vl->Set(_g7,ox);
				HX_STACK_LINE(160)
				int _g8 = (k)++;		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(160)
				vl->Set(_g8,0.0);
				HX_STACK_LINE(160)
				int _g9 = (k)++;		HX_STACK_VAR(_g9,"_g9");
				HX_STACK_LINE(160)
				vl->Set(_g9,(pz - oz));
				HX_STACK_LINE(161)
				int _g10 = (k)++;		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(161)
				vl->Set(_g10,-(ox));
				HX_STACK_LINE(161)
				int _g11 = (k)++;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(161)
				vl->Set(_g11,0.0);
				HX_STACK_LINE(161)
				int _g12 = (k)++;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(161)
				vl->Set(_g12,(pz - oz));
				HX_STACK_LINE(162)
				hx::AddEq(pz,p_step);
			}
		}
		HX_STACK_LINE(164)
		this->grid->Set(HX_CSTRING("vertex"),vl,(int)3);
		HX_STACK_LINE(165)
		::haxor::math::AABB3 _g14;		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(165)
		{
			HX_STACK_LINE(165)
			::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(165)
			int _g13 = _this->m_naabb3 = hx::Mod(((_this->m_naabb3 + (int)1)),_this->m_aabb3->length);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(165)
			_g14 = _this->m_aabb3->__get(_g13).StaticCast< ::haxor::math::AABB3 >();
		}
		HX_STACK_LINE(165)
		::haxor::math::AABB3 _g15 = this->grid->GenerateAttribBounds(HX_CSTRING("vertex"),_g14);		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(165)
		this->grid->set_bounds(_g15);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GizmoContext_obj,CreateGrid,(void))

Void GizmoContext_obj::DrawGrid( Float p_area,::haxor::math::Color p_color){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawGrid",0xe6e82ff8,"haxor.context.GizmoContext.DrawGrid","haxor/context/GizmoContext.hx",174,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_area,"p_area")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_LINE(175)
		this->gizmo_material->SetFloat(HX_CSTRING("Area"),p_area);
		HX_STACK_LINE(176)
		if (((p_color != null()))){
			HX_STACK_LINE(176)
			this->gizmo_material->SetFloat4(HX_CSTRING("Tint"),p_color->r,p_color->g,p_color->b,p_color->a);
		}
		HX_STACK_LINE(177)
		::haxor::graphics::Graphics_obj::Render(this->grid,this->gizmo_material,null(),::haxor::component::Camera_obj::m_main);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GizmoContext_obj,DrawGrid,(void))

Void GizmoContext_obj::DrawWireSphere( ::haxor::math::Vector3 p_position,Float p_radius,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawWireSphere",0x7691e3e4,"haxor.context.GizmoContext.DrawWireSphere","haxor/context/GizmoContext.hx",187,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_position,"p_position")
		HX_STACK_ARG(p_radius,"p_radius")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_transform,"p_transform")
		struct _Function_1_1{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",188,0xa99c50bc)
				{
					HX_STACK_LINE(188)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(188)
					int _g = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(188)
					return _this->m_v4->__get(_g).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(188)
		::haxor::math::Vector4 _g1 = (_Function_1_1::Block())->Set(p_radius,p_radius,p_radius,1.0);		HX_STACK_VAR(_g1,"_g1");
		struct _Function_1_2{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",188,0xa99c50bc)
				{
					HX_STACK_LINE(188)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(188)
					int _g2 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(188)
					return _this->m_v4->__get(_g2).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(188)
		::haxor::math::Vector4 _g3 = (_Function_1_2::Block())->Set3(p_position);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(188)
		this->wire_sphere_renderer->Push(p_color,_g1,_g3,p_transform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(GizmoContext_obj,DrawWireSphere,(void))

Void GizmoContext_obj::DrawWireCube( ::haxor::math::Vector3 p_position,::haxor::math::Vector3 p_size,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawWireCube",0x91b0be0c,"haxor.context.GizmoContext.DrawWireCube","haxor/context/GizmoContext.hx",199,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_position,"p_position")
		HX_STACK_ARG(p_size,"p_size")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_transform,"p_transform")
		struct _Function_1_1{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",200,0xa99c50bc)
				{
					HX_STACK_LINE(200)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(200)
					int _g = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(200)
					return _this->m_v4->__get(_g).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(200)
		::haxor::math::Vector4 _g1 = (_Function_1_1::Block())->Set3(p_size);		HX_STACK_VAR(_g1,"_g1");
		struct _Function_1_2{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",200,0xa99c50bc)
				{
					HX_STACK_LINE(200)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(200)
					int _g2 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(200)
					return _this->m_v4->__get(_g2).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(200)
		::haxor::math::Vector4 _g3 = (_Function_1_2::Block())->Set3(p_position);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(200)
		this->wire_cube_renderer->Push(p_color,_g1,_g3,p_transform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(GizmoContext_obj,DrawWireCube,(void))

Void GizmoContext_obj::DrawAxis( ::haxor::math::Vector3 p_position,::haxor::math::Vector3 p_size,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawAxis",0xe2f575d3,"haxor.context.GizmoContext.DrawAxis","haxor/context/GizmoContext.hx",211,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_position,"p_position")
		HX_STACK_ARG(p_size,"p_size")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_transform,"p_transform")
		struct _Function_1_1{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",212,0xa99c50bc)
				{
					HX_STACK_LINE(212)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(212)
					int _g = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(212)
					return _this->m_v4->__get(_g).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(212)
		::haxor::math::Vector4 _g1 = (_Function_1_1::Block())->Set3(p_size);		HX_STACK_VAR(_g1,"_g1");
		struct _Function_1_2{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",212,0xa99c50bc)
				{
					HX_STACK_LINE(212)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(212)
					int _g2 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(212)
					return _this->m_v4->__get(_g2).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(212)
		::haxor::math::Vector4 _g3 = (_Function_1_2::Block())->Set3(p_position);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(212)
		this->axis_renderer->Push(p_color,_g1,_g3,p_transform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(GizmoContext_obj,DrawAxis,(void))

Void GizmoContext_obj::DrawLine( ::haxor::math::Vector3 p_from,::haxor::math::Vector3 p_to,::haxor::math::Color p_color,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawLine",0xea2f7126,"haxor.context.GizmoContext.DrawLine","haxor/context/GizmoContext.hx",223,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_from,"p_from")
		HX_STACK_ARG(p_to,"p_to")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_transform,"p_transform")
		struct _Function_1_1{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",224,0xa99c50bc)
				{
					HX_STACK_LINE(224)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(224)
					int _g = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(224)
					return _this->m_v4->__get(_g).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(224)
		::haxor::math::Vector4 _g1 = (_Function_1_1::Block())->Set3(p_from);		HX_STACK_VAR(_g1,"_g1");
		struct _Function_1_2{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",224,0xa99c50bc)
				{
					HX_STACK_LINE(224)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(224)
					int _g2 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(224)
					return _this->m_v4->__get(_g2).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(224)
		::haxor::math::Vector4 _g3 = (_Function_1_2::Block())->Set3(p_to);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(224)
		this->line_renderer->Push(p_color,_g1,_g3,p_transform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(GizmoContext_obj,DrawLine,(void))

Void GizmoContext_obj::DrawPoint( ::haxor::math::Vector3 p_position,Float p_size,::haxor::math::Color p_color,bool p_smooth,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","DrawPoint",0x50e166de,"haxor.context.GizmoContext.DrawPoint","haxor/context/GizmoContext.hx",236,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_position,"p_position")
		HX_STACK_ARG(p_size,"p_size")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_smooth,"p_smooth")
		HX_STACK_ARG(p_transform,"p_transform")
		struct _Function_1_1{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",237,0xa99c50bc)
				{
					HX_STACK_LINE(237)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(237)
					int _g = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(237)
					return _this->m_v4->__get(_g).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(237)
		::haxor::math::Vector4 _g1 = (_Function_1_1::Block())->Set(p_size,(  ((p_smooth)) ? Float(1.0) : Float(0.0) ),0.0,0.0);		HX_STACK_VAR(_g1,"_g1");
		struct _Function_1_2{
			inline static ::haxor::math::Vector4 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",237,0xa99c50bc)
				{
					HX_STACK_LINE(237)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(237)
					int _g2 = _this->m_nv4 = hx::Mod(((_this->m_nv4 + (int)1)),_this->m_v4->length);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(237)
					return _this->m_v4->__get(_g2).StaticCast< ::haxor::math::Vector4 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(237)
		::haxor::math::Vector4 _g3 = (_Function_1_2::Block())->Set((int)1,(int)1,(int)1,(int)1)->Set3(p_position);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(237)
		this->point_renderer->Push(p_color,_g1,_g3,p_transform);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(GizmoContext_obj,DrawPoint,(void))

Void GizmoContext_obj::Render( ){
{
		HX_STACK_FRAME("haxor.context.GizmoContext","Render",0x05e69ae4,"haxor.context.GizmoContext.Render","haxor/context/GizmoContext.hx",244,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(245)
		::haxor::context::Gizmo gr;		HX_STACK_VAR(gr,"gr");
		HX_STACK_LINE(246)
		return null();
		HX_STACK_LINE(247)
		gr = this->wire_sphere_renderer;
		HX_STACK_LINE(247)
		gr->Render();
		HX_STACK_LINE(247)
		gr->Clear();
		HX_STACK_LINE(248)
		gr = this->wire_cube_renderer;
		HX_STACK_LINE(248)
		gr->Render();
		HX_STACK_LINE(248)
		gr->Clear();
		HX_STACK_LINE(249)
		gr = this->axis_renderer;
		HX_STACK_LINE(249)
		gr->Render();
		HX_STACK_LINE(249)
		gr->Clear();
		HX_STACK_LINE(250)
		gr = this->canvas_renderer;
		HX_STACK_LINE(250)
		gr->Render();
		HX_STACK_LINE(250)
		gr->Clear();
		HX_STACK_LINE(251)
		gr = this->line_renderer;
		HX_STACK_LINE(251)
		gr->Render();
		HX_STACK_LINE(251)
		gr->Clear();
		HX_STACK_LINE(252)
		gr = this->point_renderer;
		HX_STACK_LINE(252)
		gr->Render();
		HX_STACK_LINE(252)
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
	HX_MARK_MEMBER_NAME(canvas_renderer,"canvas_renderer");
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
	HX_VISIT_MEMBER_NAME(canvas_renderer,"canvas_renderer");
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
	case 15:
		if (HX_FIELD_EQ(inName,"canvas_renderer") ) { return canvas_renderer; }
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
	case 15:
		if (HX_FIELD_EQ(inName,"canvas_renderer") ) { canvas_renderer=inValue.Cast< ::haxor::context::CanvasGizmo >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"texture_material") ) { texture_material=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"wire_cube_renderer") ) { wire_cube_renderer=inValue.Cast< ::haxor::context::WireCubeGizmo >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"wire_sphere_renderer") ) { wire_sphere_renderer=inValue.Cast< ::haxor::context::WireSphereGizmo >(); return inValue; }
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
	outFields->push(HX_CSTRING("canvas_renderer"));
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
	{hx::fsObject /*::haxor::context::CanvasGizmo*/ ,(int)offsetof(GizmoContext_obj,canvas_renderer),HX_CSTRING("canvas_renderer")},
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
	HX_CSTRING("canvas_renderer"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("CreateTextureQuad"),
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
