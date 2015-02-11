#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Camera
#include <haxor/component/Camera.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_MeshRenderer
#include <haxor/component/MeshRenderer.h>
#endif
#ifndef INCLUDED_haxor_component_Renderer
#include <haxor/component/Renderer.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_component_light_Light
#include <haxor/component/light/Light.h>
#endif
#ifndef INCLUDED_haxor_component_physics_Collider
#include <haxor/component/physics/Collider.h>
#endif
#ifndef INCLUDED_haxor_context_BaseProcess
#include <haxor/context/BaseProcess.h>
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
#ifndef INCLUDED_haxor_context_PhysicsContext
#include <haxor/context/PhysicsContext.h>
#endif
#ifndef INCLUDED_haxor_context_Process
#include <haxor/context/Process.h>
#endif
#ifndef INCLUDED_haxor_context_RendererContext
#include <haxor/context/RendererContext.h>
#endif
#ifndef INCLUDED_haxor_context_ShaderContext
#include <haxor/context/ShaderContext.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_haxor_core_Debug
#include <haxor/core/Debug.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IResizeable
#include <haxor/core/IResizeable.h>
#endif
#ifndef INCLUDED_haxor_core_PixelFormat
#include <haxor/core/PixelFormat.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_Graphics
#include <haxor/graphics/Graphics.h>
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
#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#include <haxor/graphics/texture/Bitmap.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_ComputeTexture
#include <haxor/graphics/texture/ComputeTexture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture2D
#include <haxor/graphics/texture/Texture2D.h>
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
#ifndef INCLUDED_haxor_math_Vector4
#include <haxor/math/Vector4.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace context{

Void Gizmo_obj::__construct(int p_type,int p_count)
{
HX_STACK_FRAME("haxor.context.Gizmo","new",0x1cb67ae1,"haxor.context.Gizmo.new","haxor/context/GizmoContext.hx",307,0xa99c50bc)
HX_STACK_THIS(this)
HX_STACK_ARG(p_type,"p_type")
HX_STACK_ARG(p_count,"p_count")
{
	HX_STACK_LINE(308)
	this->type = p_type;
	HX_STACK_LINE(309)
	this->m_render_count = (int)0;
	HX_STACK_LINE(310)
	this->m_gizmo_count = p_count;
	HX_STACK_LINE(312)
	if (((::haxor::context::Gizmo_obj::SHADER == null()))){
		HX_STACK_LINE(312)
		::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::gizmo_source);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(312)
		::haxor::context::Gizmo_obj::SHADER = _g;
	}
	HX_STACK_LINE(314)
	::haxor::graphics::material::Material _g1 = ::haxor::graphics::material::Material_obj::__new(((HX_CSTRING("Gizmo") + p_type) + HX_CSTRING("Material")));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(314)
	this->material = _g1;
	HX_STACK_LINE(315)
	this->material->set_shader(::haxor::context::Gizmo_obj::SHADER);
	HX_STACK_LINE(316)
	this->material->blend = true;
	HX_STACK_LINE(317)
	this->material->SetBlending((int)770,(int)771);
	HX_STACK_LINE(318)
	this->material->SetInt(HX_CSTRING("Type"),p_type);
	HX_STACK_LINE(319)
	this->material->ztest = false;
	HX_STACK_LINE(320)
	int tw = (int)0;		HX_STACK_VAR(tw,"tw");
	HX_STACK_LINE(321)
	int th = (int)0;		HX_STACK_VAR(th,"th");
	HX_STACK_LINE(323)
	if (((p_count >= (int)1))){
		HX_STACK_LINE(325)
		int data_tex_size;		HX_STACK_VAR(data_tex_size,"data_tex_size");
		struct _Function_2_1{
			inline static Float Block( int &p_count){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",325,0xa99c50bc)
				{
					HX_STACK_LINE(325)
					Float b;		HX_STACK_VAR(b,"b");
					struct _Function_3_1{
						inline static int Block( int &p_count){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",325,0xa99c50bc)
							{
								HX_STACK_LINE(325)
								int p_v;		HX_STACK_VAR(p_v,"p_v");
								struct _Function_4_1{
									inline static Float Block( int &p_count){
										HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",325,0xa99c50bc)
										{
											HX_STACK_LINE(325)
											Float p_v1 = ::Math_obj::sqrt((p_count * ((Float(::haxor::context::Gizmo_obj::DATA_OFFSET) / Float((int)4)))));		HX_STACK_VAR(p_v1,"p_v1");
											HX_STACK_LINE(325)
											return ::Std_obj::_int((p_v1 + ((  (((p_v1 < (int)0))) ? Float(-0.9999999) : Float(0.9999999) ))));
										}
										return null();
									}
								};
								HX_STACK_LINE(325)
								p_v = _Function_4_1::Block(p_count);
								HX_STACK_LINE(325)
								--(p_v);
								HX_STACK_LINE(325)
								hx::OrEq(p_v,(int(p_v) >> int((int)1)));
								HX_STACK_LINE(325)
								hx::OrEq(p_v,(int(p_v) >> int((int)2)));
								HX_STACK_LINE(325)
								hx::OrEq(p_v,(int(p_v) >> int((int)4)));
								HX_STACK_LINE(325)
								hx::OrEq(p_v,(int(p_v) >> int((int)8)));
								HX_STACK_LINE(325)
								hx::OrEq(p_v,(int(p_v) >> int((int)16)));
								HX_STACK_LINE(325)
								return ++(p_v);
							}
							return null();
						}
					};
					HX_STACK_LINE(325)
					b = _Function_3_1::Block(p_count);
					HX_STACK_LINE(325)
					return ::Math_obj::max((int)2,b);
				}
				return null();
			}
		};
		HX_STACK_LINE(325)
		data_tex_size = _Function_2_1::Block(p_count);
		HX_STACK_LINE(326)
		::haxor::graphics::texture::ComputeTexture _g2 = ::haxor::graphics::texture::ComputeTexture_obj::__new(data_tex_size,data_tex_size,::haxor::core::PixelFormat_obj::Float4);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(326)
		this->data = _g2;
		HX_STACK_LINE(327)
		::haxor::io::FloatArray f32 = this->data->m_data->get_buffer();		HX_STACK_VAR(f32,"f32");
		HX_STACK_LINE(328)
		{
			HX_STACK_LINE(328)
			int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(328)
			int _g = f32->m_length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(328)
			while((true)){
				HX_STACK_LINE(328)
				if ((!(((_g11 < _g))))){
					HX_STACK_LINE(328)
					break;
				}
				HX_STACK_LINE(328)
				int i = (_g11)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(328)
				f32->Set(i,(  (((hx::Mod(i,(int)4) == (int)3))) ? Float(1.0) : Float(0.0) ));
			}
		}
		HX_STACK_LINE(329)
		this->material->SetTexture(HX_CSTRING("Data"),this->data);
		HX_STACK_LINE(330)
		this->material->SetInt(HX_CSTRING("DataSize"),this->data->m_width);
		HX_STACK_LINE(331)
		tw = this->data->m_width;
		HX_STACK_LINE(332)
		th = this->data->m_height;
	}
	HX_STACK_LINE(334)
	::haxor::core::Console_obj::Log(((((((HX_CSTRING("Gizmos> Created Renderer [") + p_type) + HX_CSTRING("] data[")) + tw) + HX_CSTRING("x")) + th) + HX_CSTRING("]")),(int)6);
	HX_STACK_LINE(335)
	this->OnBuild();
}
;
	return null();
}

//Gizmo_obj::~Gizmo_obj() { }

Dynamic Gizmo_obj::__CreateEmpty() { return  new Gizmo_obj; }
hx::ObjectPtr< Gizmo_obj > Gizmo_obj::__new(int p_type,int p_count)
{  hx::ObjectPtr< Gizmo_obj > result = new Gizmo_obj();
	result->__construct(p_type,p_count);
	return result;}

Dynamic Gizmo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Gizmo_obj > result = new Gizmo_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Gizmo_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.context.Gizmo","OnBuild",0x792a2070,"haxor.context.Gizmo.OnBuild","haxor/context/GizmoContext.hx",341,0xa99c50bc)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Gizmo_obj,OnBuild,(void))

Void Gizmo_obj::Push( ::haxor::math::Color p_color,::haxor::math::Vector4 p_a,::haxor::math::Vector4 p_b,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.context.Gizmo","Push",0xef2cc459,"haxor.context.Gizmo.Push","haxor/context/GizmoContext.hx",351,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_a,"p_a")
		HX_STACK_ARG(p_b,"p_b")
		HX_STACK_ARG(p_transform,"p_transform")
		HX_STACK_LINE(352)
		if (((this->m_render_count >= this->m_gizmo_count))){
			HX_STACK_LINE(354)
			return null();
		}
		HX_STACK_LINE(356)
		int id = this->m_render_count;		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(357)
		::haxor::io::FloatArray f32 = this->data->m_data->get_buffer();		HX_STACK_VAR(f32,"f32");
		HX_STACK_LINE(358)
		int p = (id * ::haxor::context::Gizmo_obj::DATA_OFFSET);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(359)
		::haxor::math::Color c;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(359)
		if (((p_color == null()))){
			struct _Function_2_1{
				inline static ::haxor::math::Color Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",359,0xa99c50bc)
					{
						HX_STACK_LINE(359)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(359)
						int _g = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(359)
						return _this->m_c->__get(_g).StaticCast< ::haxor::math::Color >();
					}
					return null();
				}
			};
			HX_STACK_LINE(359)
			c = (_Function_2_1::Block())->Set((int)1,(int)1,(int)1,(int)1);
		}
		else{
			HX_STACK_LINE(359)
			c = p_color;
		}
		HX_STACK_LINE(360)
		int _g1 = (p)++;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(360)
		f32->Set(_g1,c->r);
		HX_STACK_LINE(361)
		int _g2 = (p)++;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(361)
		f32->Set(_g2,c->g);
		HX_STACK_LINE(362)
		int _g3 = (p)++;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(362)
		f32->Set(_g3,c->b);
		HX_STACK_LINE(363)
		int _g4 = (p)++;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(363)
		f32->Set(_g4,c->a);
		HX_STACK_LINE(364)
		int _g5 = (p)++;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(364)
		f32->Set(_g5,p_a->x);
		HX_STACK_LINE(365)
		int _g6 = (p)++;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(365)
		f32->Set(_g6,p_a->y);
		HX_STACK_LINE(366)
		int _g7 = (p)++;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(366)
		f32->Set(_g7,p_a->z);
		HX_STACK_LINE(367)
		int _g8 = (p)++;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(367)
		f32->Set(_g8,p_a->w);
		HX_STACK_LINE(368)
		int _g9 = (p)++;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(368)
		f32->Set(_g9,p_b->x);
		HX_STACK_LINE(369)
		int _g10 = (p)++;		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(369)
		f32->Set(_g10,p_b->y);
		HX_STACK_LINE(370)
		int _g11 = (p)++;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(370)
		f32->Set(_g11,p_b->z);
		HX_STACK_LINE(371)
		int _g12 = (p)++;		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(371)
		f32->Set(_g12,p_b->w);
		HX_STACK_LINE(373)
		::haxor::math::Matrix4 m;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(373)
		if (((p_transform == null()))){
			HX_STACK_LINE(373)
			m = ::haxor::context::Gizmo_obj::IDM;
		}
		else{
			HX_STACK_LINE(373)
			m = p_transform;
		}
		HX_STACK_LINE(374)
		::String ms = HX_CSTRING("");		HX_STACK_VAR(ms,"ms");
		HX_STACK_LINE(375)
		{
			HX_STACK_LINE(375)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(375)
			while((true)){
				HX_STACK_LINE(375)
				if ((!(((_g < (int)12))))){
					HX_STACK_LINE(375)
					break;
				}
				HX_STACK_LINE(375)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(377)
				int _g13 = (p)++;		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(377)
				Float _g14 = m->GetIndex(i);		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(377)
				f32->Set(_g13,_g14);
			}
		}
		HX_STACK_LINE(380)
		(this->m_render_count)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Gizmo_obj,Push,(void))

Void Gizmo_obj::Clear( ){
{
		HX_STACK_FRAME("haxor.context.Gizmo","Clear",0xd5cbee2e,"haxor.context.Gizmo.Clear","haxor/context/GizmoContext.hx",388,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(388)
		this->m_render_count = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Gizmo_obj,Clear,(void))

Void Gizmo_obj::Render( ){
{
		HX_STACK_FRAME("haxor.context.Gizmo","Render",0x3a25fb95,"haxor.context.Gizmo.Render","haxor/context/GizmoContext.hx",395,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(396)
		bool gizmo_collider = (bool((bool(::haxor::core::Debug_obj::collider) || bool(::haxor::core::Debug_obj::colliderAABB))) || bool(::haxor::core::Debug_obj::colliderSB));		HX_STACK_VAR(gizmo_collider,"gizmo_collider");
		HX_STACK_LINE(398)
		if ((gizmo_collider)){
			HX_STACK_LINE(400)
			Array< ::Dynamic > cl = ::haxor::context::EngineContext_obj::physics->colliders;		HX_STACK_VAR(cl,"cl");
			HX_STACK_LINE(401)
			{
				HX_STACK_LINE(401)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(401)
				int _g = cl->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(401)
				while((true)){
					HX_STACK_LINE(401)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(401)
						break;
					}
					HX_STACK_LINE(401)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(403)
					::haxor::component::physics::Collider c = cl->__get(i).StaticCast< ::haxor::component::physics::Collider >();		HX_STACK_VAR(c,"c");
					HX_STACK_LINE(404)
					if ((::haxor::core::Debug_obj::collider)){
						HX_STACK_LINE(404)
						::haxor::core::Debug_obj::Collider(c);
					}
					HX_STACK_LINE(405)
					if ((::haxor::core::Debug_obj::colliderAABB)){
						HX_STACK_LINE(405)
						::haxor::math::AABB3 _g2 = c->get_aabb();		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(405)
						::haxor::core::Debug_obj::BoundingAABB(_g2);
					}
					HX_STACK_LINE(406)
					if ((::haxor::core::Debug_obj::colliderSB)){
						HX_STACK_LINE(406)
						::haxor::math::Vector4 _g11 = c->get_sphere();		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(406)
						::haxor::core::Debug_obj::BoundingSphere(_g11);
					}
				}
			}
		}
		HX_STACK_LINE(410)
		if ((::haxor::core::Debug_obj::renderer)){
			HX_STACK_LINE(412)
			Array< ::Dynamic > rpl = ::haxor::context::EngineContext_obj::renderer->display;		HX_STACK_VAR(rpl,"rpl");
			HX_STACK_LINE(413)
			{
				HX_STACK_LINE(413)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(413)
				int _g = rpl->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(413)
				while((true)){
					HX_STACK_LINE(413)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(413)
						break;
					}
					HX_STACK_LINE(413)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(415)
					::haxor::context::Process rp = rpl->__get(i).StaticCast< ::haxor::context::Process >();		HX_STACK_VAR(rp,"rp");
					HX_STACK_LINE(416)
					{
						HX_STACK_LINE(416)
						int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(416)
						int _g2 = rp->m_length;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(416)
						while((true)){
							HX_STACK_LINE(416)
							if ((!(((_g3 < _g2))))){
								HX_STACK_LINE(416)
								break;
							}
							HX_STACK_LINE(416)
							int j = (_g3)++;		HX_STACK_VAR(j,"j");
							HX_STACK_LINE(418)
							::haxor::component::MeshRenderer mr = rp->list->__GetItem(j);		HX_STACK_VAR(mr,"mr");
							HX_STACK_LINE(420)
							if (((mr == null()))){
								HX_STACK_LINE(420)
								continue;
							}
							HX_STACK_LINE(421)
							::haxor::core::Debug_obj::MeshRenderer(mr);
						}
					}
				}
			}
		}
		HX_STACK_LINE(426)
		if ((::haxor::core::Debug_obj::transform)){

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_2_1)
			bool run(::haxor::component::Transform p_t,int p_d){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","haxor/context/GizmoContext.hx",429,0xa99c50bc)
				HX_STACK_ARG(p_t,"p_t")
				HX_STACK_ARG(p_d,"p_d")
				{
					HX_STACK_LINE(430)
					if (((p_t == ::haxor::component::Transform_obj::get_root()))){
						HX_STACK_LINE(430)
						return true;
					}
					HX_STACK_LINE(431)
					if (((p_t == ::haxor::component::Camera_obj::m_main->m_entity->m_transform))){
						HX_STACK_LINE(431)
						return true;
					}
					HX_STACK_LINE(432)
					::haxor::core::Debug_obj::Transform(p_t);
					HX_STACK_LINE(433)
					return true;
				}
				return null();
			}
			HX_END_LOCAL_FUNC2(return)

			HX_STACK_LINE(428)
			::haxor::component::Transform_obj::get_root()->Traverse( Dynamic(new _Function_2_1()));
		}
		HX_STACK_LINE(437)
		if ((::haxor::core::Debug_obj::light)){
			HX_STACK_LINE(439)
			Array< ::Dynamic > ll = ::haxor::component::light::Light_obj::m_list;		HX_STACK_VAR(ll,"ll");
			HX_STACK_LINE(440)
			{
				HX_STACK_LINE(440)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(440)
				int _g = ll->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(440)
				while((true)){
					HX_STACK_LINE(440)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(440)
						break;
					}
					HX_STACK_LINE(440)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(442)
					::haxor::core::Debug_obj::Light(ll->__get(i).StaticCast< ::haxor::component::light::Light >());
				}
			}
		}
		HX_STACK_LINE(446)
		if (((this->m_render_count > (int)0))){
			HX_STACK_LINE(448)
			this->data->Apply();
			HX_STACK_LINE(449)
			this->material->SetInt(HX_CSTRING("Count"),this->m_render_count);
			HX_STACK_LINE(450)
			Float np = ::haxor::component::Camera_obj::m_main->m_near;		HX_STACK_VAR(np,"np");
			HX_STACK_LINE(451)
			Float fp = ::haxor::component::Camera_obj::m_main->m_far;		HX_STACK_VAR(fp,"fp");
			HX_STACK_LINE(452)
			{
				HX_STACK_LINE(452)
				::haxor::component::Camera _this = ::haxor::component::Camera_obj::m_main;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(452)
				_this->m_near = 1.0;
				HX_STACK_LINE(452)
				_this->m_projection_dirty = true;
				HX_STACK_LINE(452)
				_this->m_proj_uniform_dirty = true;
				HX_STACK_LINE(452)
				1.0;
			}
			HX_STACK_LINE(453)
			{
				HX_STACK_LINE(453)
				::haxor::component::Camera _this = ::haxor::component::Camera_obj::m_main;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(453)
				_this->m_far = (int)50000;
				HX_STACK_LINE(453)
				_this->m_projection_dirty = true;
				HX_STACK_LINE(453)
				_this->m_proj_uniform_dirty = true;
				HX_STACK_LINE(453)
				(int)50000;
			}
			HX_STACK_LINE(454)
			::haxor::graphics::Graphics_obj::Render(this->mesh,this->material,null(),::haxor::component::Camera_obj::m_main);
			HX_STACK_LINE(455)
			{
				HX_STACK_LINE(455)
				::haxor::component::Camera _this = ::haxor::component::Camera_obj::m_main;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(455)
				_this->m_near = np;
				HX_STACK_LINE(455)
				_this->m_projection_dirty = true;
				HX_STACK_LINE(455)
				_this->m_proj_uniform_dirty = true;
				HX_STACK_LINE(455)
				np;
			}
			HX_STACK_LINE(456)
			{
				HX_STACK_LINE(456)
				::haxor::component::Camera _this = ::haxor::component::Camera_obj::m_main;		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(456)
				_this->m_far = fp;
				HX_STACK_LINE(456)
				_this->m_projection_dirty = true;
				HX_STACK_LINE(456)
				_this->m_proj_uniform_dirty = true;
				HX_STACK_LINE(456)
				fp;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Gizmo_obj,Render,(void))

int Gizmo_obj::POINT;

int Gizmo_obj::LINE;

int Gizmo_obj::AXIS;

int Gizmo_obj::WIRE_CUBE;

int Gizmo_obj::WIRE_SPHERE;

int Gizmo_obj::CANVAS;

int Gizmo_obj::DATA_OFFSET;

int Gizmo_obj::MAX_GIZMOS;

::haxor::math::Matrix4 Gizmo_obj::IDM;

::haxor::graphics::material::Shader Gizmo_obj::SHADER;


Gizmo_obj::Gizmo_obj()
{
}

void Gizmo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Gizmo);
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(mesh,"mesh");
	HX_MARK_MEMBER_NAME(material,"material");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(m_render_count,"m_render_count");
	HX_MARK_MEMBER_NAME(m_gizmo_count,"m_gizmo_count");
	HX_MARK_END_CLASS();
}

void Gizmo_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(mesh,"mesh");
	HX_VISIT_MEMBER_NAME(material,"material");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(m_render_count,"m_render_count");
	HX_VISIT_MEMBER_NAME(m_gizmo_count,"m_gizmo_count");
}

Dynamic Gizmo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"IDM") ) { return IDM; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"LINE") ) { return LINE; }
		if (HX_FIELD_EQ(inName,"AXIS") ) { return AXIS; }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		if (HX_FIELD_EQ(inName,"mesh") ) { return mesh; }
		if (HX_FIELD_EQ(inName,"type") ) { return type; }
		if (HX_FIELD_EQ(inName,"Push") ) { return Push_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"POINT") ) { return POINT; }
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"CANVAS") ) { return CANVAS; }
		if (HX_FIELD_EQ(inName,"SHADER") ) { return SHADER; }
		if (HX_FIELD_EQ(inName,"Render") ) { return Render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"material") ) { return material; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"WIRE_CUBE") ) { return WIRE_CUBE; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"MAX_GIZMOS") ) { return MAX_GIZMOS; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"WIRE_SPHERE") ) { return WIRE_SPHERE; }
		if (HX_FIELD_EQ(inName,"DATA_OFFSET") ) { return DATA_OFFSET; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_gizmo_count") ) { return m_gizmo_count; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_render_count") ) { return m_render_count; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Gizmo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"IDM") ) { IDM=inValue.Cast< ::haxor::math::Matrix4 >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"LINE") ) { LINE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"AXIS") ) { AXIS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::haxor::graphics::texture::ComputeTexture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mesh") ) { mesh=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"POINT") ) { POINT=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"CANVAS") ) { CANVAS=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SHADER") ) { SHADER=inValue.Cast< ::haxor::graphics::material::Shader >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"material") ) { material=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"WIRE_CUBE") ) { WIRE_CUBE=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"MAX_GIZMOS") ) { MAX_GIZMOS=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"WIRE_SPHERE") ) { WIRE_SPHERE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"DATA_OFFSET") ) { DATA_OFFSET=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_gizmo_count") ) { m_gizmo_count=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_render_count") ) { m_render_count=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Gizmo_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("mesh"));
	outFields->push(HX_CSTRING("material"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("m_render_count"));
	outFields->push(HX_CSTRING("m_gizmo_count"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("POINT"),
	HX_CSTRING("LINE"),
	HX_CSTRING("AXIS"),
	HX_CSTRING("WIRE_CUBE"),
	HX_CSTRING("WIRE_SPHERE"),
	HX_CSTRING("CANVAS"),
	HX_CSTRING("DATA_OFFSET"),
	HX_CSTRING("MAX_GIZMOS"),
	HX_CSTRING("IDM"),
	HX_CSTRING("SHADER"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::graphics::texture::ComputeTexture*/ ,(int)offsetof(Gizmo_obj,data),HX_CSTRING("data")},
	{hx::fsObject /*::haxor::graphics::mesh::Mesh*/ ,(int)offsetof(Gizmo_obj,mesh),HX_CSTRING("mesh")},
	{hx::fsObject /*::haxor::graphics::material::Material*/ ,(int)offsetof(Gizmo_obj,material),HX_CSTRING("material")},
	{hx::fsInt,(int)offsetof(Gizmo_obj,type),HX_CSTRING("type")},
	{hx::fsInt,(int)offsetof(Gizmo_obj,m_render_count),HX_CSTRING("m_render_count")},
	{hx::fsInt,(int)offsetof(Gizmo_obj,m_gizmo_count),HX_CSTRING("m_gizmo_count")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	HX_CSTRING("mesh"),
	HX_CSTRING("material"),
	HX_CSTRING("type"),
	HX_CSTRING("m_render_count"),
	HX_CSTRING("m_gizmo_count"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("Push"),
	HX_CSTRING("Clear"),
	HX_CSTRING("Render"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Gizmo_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Gizmo_obj::POINT,"POINT");
	HX_MARK_MEMBER_NAME(Gizmo_obj::LINE,"LINE");
	HX_MARK_MEMBER_NAME(Gizmo_obj::AXIS,"AXIS");
	HX_MARK_MEMBER_NAME(Gizmo_obj::WIRE_CUBE,"WIRE_CUBE");
	HX_MARK_MEMBER_NAME(Gizmo_obj::WIRE_SPHERE,"WIRE_SPHERE");
	HX_MARK_MEMBER_NAME(Gizmo_obj::CANVAS,"CANVAS");
	HX_MARK_MEMBER_NAME(Gizmo_obj::DATA_OFFSET,"DATA_OFFSET");
	HX_MARK_MEMBER_NAME(Gizmo_obj::MAX_GIZMOS,"MAX_GIZMOS");
	HX_MARK_MEMBER_NAME(Gizmo_obj::IDM,"IDM");
	HX_MARK_MEMBER_NAME(Gizmo_obj::SHADER,"SHADER");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Gizmo_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Gizmo_obj::POINT,"POINT");
	HX_VISIT_MEMBER_NAME(Gizmo_obj::LINE,"LINE");
	HX_VISIT_MEMBER_NAME(Gizmo_obj::AXIS,"AXIS");
	HX_VISIT_MEMBER_NAME(Gizmo_obj::WIRE_CUBE,"WIRE_CUBE");
	HX_VISIT_MEMBER_NAME(Gizmo_obj::WIRE_SPHERE,"WIRE_SPHERE");
	HX_VISIT_MEMBER_NAME(Gizmo_obj::CANVAS,"CANVAS");
	HX_VISIT_MEMBER_NAME(Gizmo_obj::DATA_OFFSET,"DATA_OFFSET");
	HX_VISIT_MEMBER_NAME(Gizmo_obj::MAX_GIZMOS,"MAX_GIZMOS");
	HX_VISIT_MEMBER_NAME(Gizmo_obj::IDM,"IDM");
	HX_VISIT_MEMBER_NAME(Gizmo_obj::SHADER,"SHADER");
};

#endif

Class Gizmo_obj::__mClass;

void Gizmo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.Gizmo"), hx::TCanCast< Gizmo_obj> ,sStaticFields,sMemberFields,
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

void Gizmo_obj::__boot()
{
	POINT= (int)0;
	LINE= (int)1;
	AXIS= (int)2;
	WIRE_CUBE= (int)3;
	WIRE_SPHERE= (int)4;
	CANVAS= (int)10;
	DATA_OFFSET= (int)24;
	MAX_GIZMOS= (int)500;
	IDM= ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);
}

} // end namespace haxor
} // end namespace context
