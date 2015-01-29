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
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
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
#ifndef INCLUDED_haxor_context_ShaderContext
#include <haxor/context/ShaderContext.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
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
HX_STACK_FRAME("haxor.context.Gizmo","new",0x1cb67ae1,"haxor.context.Gizmo.new","haxor/context/GizmoContext.hx",342,0xa99c50bc)
HX_STACK_THIS(this)
HX_STACK_ARG(p_type,"p_type")
HX_STACK_ARG(p_count,"p_count")
{
	HX_STACK_LINE(343)
	this->type = p_type;
	HX_STACK_LINE(344)
	this->m_render_count = (int)0;
	HX_STACK_LINE(345)
	this->m_gizmo_count = p_count;
	HX_STACK_LINE(347)
	if (((::haxor::context::Gizmo_obj::SHADER == null()))){
		HX_STACK_LINE(347)
		::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::gizmo_source);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(347)
		::haxor::context::Gizmo_obj::SHADER = _g;
	}
	HX_STACK_LINE(349)
	::haxor::graphics::material::Material _g1 = ::haxor::graphics::material::Material_obj::__new(((HX_CSTRING("Gizmo") + p_type) + HX_CSTRING("Material")));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(349)
	this->material = _g1;
	HX_STACK_LINE(350)
	this->material->set_shader(::haxor::context::Gizmo_obj::SHADER);
	HX_STACK_LINE(351)
	this->material->blend = true;
	HX_STACK_LINE(352)
	this->material->SetBlending((int)770,(int)771);
	HX_STACK_LINE(353)
	this->material->SetInt(HX_CSTRING("Type"),p_type);
	HX_STACK_LINE(354)
	this->material->ztest = false;
	HX_STACK_LINE(355)
	int tw = (int)0;		HX_STACK_VAR(tw,"tw");
	HX_STACK_LINE(356)
	int th = (int)0;		HX_STACK_VAR(th,"th");
	HX_STACK_LINE(358)
	if (((p_count >= (int)1))){
		HX_STACK_LINE(360)
		int data_tex_size;		HX_STACK_VAR(data_tex_size,"data_tex_size");
		struct _Function_2_1{
			inline static Float Block( int &p_count){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",360,0xa99c50bc)
				{
					HX_STACK_LINE(360)
					Float b;		HX_STACK_VAR(b,"b");
					struct _Function_3_1{
						inline static int Block( int &p_count){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",360,0xa99c50bc)
							{
								HX_STACK_LINE(360)
								int p_v;		HX_STACK_VAR(p_v,"p_v");
								struct _Function_4_1{
									inline static Float Block( int &p_count){
										HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",360,0xa99c50bc)
										{
											HX_STACK_LINE(360)
											Float p_v1 = ::Math_obj::sqrt((p_count * ((Float(::haxor::context::Gizmo_obj::DATA_OFFSET) / Float((int)4)))));		HX_STACK_VAR(p_v1,"p_v1");
											HX_STACK_LINE(360)
											return ::Std_obj::_int((p_v1 + ((  (((p_v1 < (int)0))) ? Float(-0.9999999) : Float(0.9999999) ))));
										}
										return null();
									}
								};
								HX_STACK_LINE(360)
								p_v = _Function_4_1::Block(p_count);
								HX_STACK_LINE(360)
								--(p_v);
								HX_STACK_LINE(360)
								hx::OrEq(p_v,(int(p_v) >> int((int)1)));
								HX_STACK_LINE(360)
								hx::OrEq(p_v,(int(p_v) >> int((int)2)));
								HX_STACK_LINE(360)
								hx::OrEq(p_v,(int(p_v) >> int((int)4)));
								HX_STACK_LINE(360)
								hx::OrEq(p_v,(int(p_v) >> int((int)8)));
								HX_STACK_LINE(360)
								hx::OrEq(p_v,(int(p_v) >> int((int)16)));
								HX_STACK_LINE(360)
								return ++(p_v);
							}
							return null();
						}
					};
					HX_STACK_LINE(360)
					b = _Function_3_1::Block(p_count);
					HX_STACK_LINE(360)
					return ::Math_obj::max((int)2,b);
				}
				return null();
			}
		};
		HX_STACK_LINE(360)
		data_tex_size = _Function_2_1::Block(p_count);
		HX_STACK_LINE(361)
		::haxor::graphics::texture::ComputeTexture _g2 = ::haxor::graphics::texture::ComputeTexture_obj::__new(data_tex_size,data_tex_size,::haxor::core::PixelFormat_obj::Float4);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(361)
		this->data = _g2;
		HX_STACK_LINE(362)
		this->material->SetTexture(HX_CSTRING("Data"),this->data);
		HX_STACK_LINE(363)
		this->material->SetInt(HX_CSTRING("DataSize"),this->data->m_width);
		HX_STACK_LINE(364)
		tw = this->data->m_width;
		HX_STACK_LINE(365)
		th = this->data->m_height;
	}
	HX_STACK_LINE(367)
	::haxor::core::Console_obj::Log(((((((HX_CSTRING("Gizmos> Created Renderer [") + p_type) + HX_CSTRING("] data[")) + tw) + HX_CSTRING("x")) + th) + HX_CSTRING("]")),null());
	HX_STACK_LINE(368)
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
		HX_STACK_FRAME("haxor.context.Gizmo","OnBuild",0x792a2070,"haxor.context.Gizmo.OnBuild","haxor/context/GizmoContext.hx",374,0xa99c50bc)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Gizmo_obj,OnBuild,(void))

Void Gizmo_obj::Push( ::haxor::math::Color p_color,::haxor::math::Vector4 p_a,::haxor::math::Vector4 p_b,::haxor::math::Matrix4 p_transform){
{
		HX_STACK_FRAME("haxor.context.Gizmo","Push",0xef2cc459,"haxor.context.Gizmo.Push","haxor/context/GizmoContext.hx",384,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_ARG(p_a,"p_a")
		HX_STACK_ARG(p_b,"p_b")
		HX_STACK_ARG(p_transform,"p_transform")
		HX_STACK_LINE(385)
		if (((this->m_render_count >= this->m_gizmo_count))){
			HX_STACK_LINE(387)
			return null();
		}
		HX_STACK_LINE(389)
		int id = this->m_render_count;		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(390)
		::haxor::io::FloatArray f32 = this->data->m_data->get_buffer();		HX_STACK_VAR(f32,"f32");
		HX_STACK_LINE(391)
		int p = (id * ::haxor::context::Gizmo_obj::DATA_OFFSET);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(392)
		::haxor::math::Color c;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(392)
		if (((p_color == null()))){
			struct _Function_2_1{
				inline static ::haxor::math::Color Block( ){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/GizmoContext.hx",392,0xa99c50bc)
					{
						HX_STACK_LINE(392)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(392)
						int _g = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(392)
						return _this->m_c->__get(_g).StaticCast< ::haxor::math::Color >();
					}
					return null();
				}
			};
			HX_STACK_LINE(392)
			c = (_Function_2_1::Block())->Set((int)1,(int)1,(int)1,(int)1);
		}
		else{
			HX_STACK_LINE(392)
			c = p_color;
		}
		HX_STACK_LINE(393)
		int _g1 = (p)++;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(393)
		f32->Set(_g1,c->r);
		HX_STACK_LINE(394)
		int _g2 = (p)++;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(394)
		f32->Set(_g2,c->g);
		HX_STACK_LINE(395)
		int _g3 = (p)++;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(395)
		f32->Set(_g3,c->b);
		HX_STACK_LINE(396)
		int _g4 = (p)++;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(396)
		f32->Set(_g4,c->a);
		HX_STACK_LINE(397)
		int _g5 = (p)++;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(397)
		f32->Set(_g5,p_a->x);
		HX_STACK_LINE(398)
		int _g6 = (p)++;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(398)
		f32->Set(_g6,p_a->y);
		HX_STACK_LINE(399)
		int _g7 = (p)++;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(399)
		f32->Set(_g7,p_a->z);
		HX_STACK_LINE(400)
		int _g8 = (p)++;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(400)
		f32->Set(_g8,p_a->w);
		HX_STACK_LINE(401)
		int _g9 = (p)++;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(401)
		f32->Set(_g9,p_b->x);
		HX_STACK_LINE(402)
		int _g10 = (p)++;		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(402)
		f32->Set(_g10,p_b->y);
		HX_STACK_LINE(403)
		int _g11 = (p)++;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(403)
		f32->Set(_g11,p_b->z);
		HX_STACK_LINE(404)
		int _g12 = (p)++;		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(404)
		f32->Set(_g12,p_b->w);
		HX_STACK_LINE(405)
		::haxor::math::Matrix4 m;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(405)
		if (((p_transform == null()))){
			HX_STACK_LINE(405)
			m = ::haxor::context::Gizmo_obj::IDM;
		}
		else{
			HX_STACK_LINE(405)
			m = p_transform;
		}
		HX_STACK_LINE(406)
		{
			HX_STACK_LINE(406)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(406)
			while((true)){
				HX_STACK_LINE(406)
				if ((!(((_g < (int)12))))){
					HX_STACK_LINE(406)
					break;
				}
				HX_STACK_LINE(406)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(406)
				int _g13 = (p)++;		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(406)
				Float _g14 = m->GetIndex(i);		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(406)
				f32->Set(_g13,_g14);
			}
		}
		HX_STACK_LINE(407)
		(this->m_render_count)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Gizmo_obj,Push,(void))

Void Gizmo_obj::Clear( ){
{
		HX_STACK_FRAME("haxor.context.Gizmo","Clear",0xd5cbee2e,"haxor.context.Gizmo.Clear","haxor/context/GizmoContext.hx",415,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(415)
		this->m_render_count = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Gizmo_obj,Clear,(void))

Void Gizmo_obj::Render( ){
{
		HX_STACK_FRAME("haxor.context.Gizmo","Render",0x3a25fb95,"haxor.context.Gizmo.Render","haxor/context/GizmoContext.hx",423,0xa99c50bc)
		HX_STACK_THIS(this)
		HX_STACK_LINE(423)
		if (((this->m_render_count > (int)0))){
			HX_STACK_LINE(425)
			this->data->Apply();
			HX_STACK_LINE(426)
			this->material->SetInt(HX_CSTRING("Count"),this->m_render_count);
			HX_STACK_LINE(427)
			::haxor::graphics::Graphics_obj::Render(this->mesh,this->material,null(),::haxor::component::Camera_obj::m_main);
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
	DATA_OFFSET= (int)24;
	MAX_GIZMOS= (int)500;
	IDM= ::haxor::math::Matrix4_obj::__new((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);
}

} // end namespace haxor
} // end namespace context
