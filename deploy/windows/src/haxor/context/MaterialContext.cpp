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
#ifndef INCLUDED_haxor_component_Light
#include <haxor/component/Light.h>
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
#ifndef INCLUDED_haxor_context_MaterialContext
#include <haxor/context/MaterialContext.h>
#endif
#ifndef INCLUDED_haxor_context_MeshContext
#include <haxor/context/MeshContext.h>
#endif
#ifndef INCLUDED_haxor_context_TextureContext
#include <haxor/context/TextureContext.h>
#endif
#ifndef INCLUDED_haxor_context_UID
#include <haxor/context/UID.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_TextureType
#include <haxor/core/TextureType.h>
#endif
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
#endif
#ifndef INCLUDED_haxor_graphics_GL
#include <haxor/graphics/GL.h>
#endif
#ifndef INCLUDED_haxor_graphics_GraphicContext
#include <haxor/graphics/GraphicContext.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_MaterialUniform
#include <haxor/graphics/material/MaterialUniform.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Shader
#include <haxor/graphics/material/Shader.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_UberShader
#include <haxor/graphics/material/UberShader.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshAttrib
#include <haxor/graphics/mesh/MeshAttrib.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
#ifndef INCLUDED_haxor_io_Int32Array
#include <haxor/io/Int32Array.h>
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
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_graphics_WinGL
#include <haxor/platform/windows/graphics/WinGL.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace context{

Void MaterialContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.MaterialContext","new",0xcad5d8af,"haxor.context.MaterialContext.new","haxor/context/MaterialContext.hx",33,0x0e17e323)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(35)
	this->uniform_globals = Array_obj< ::String >::__new().Add(HX_CSTRING("ViewMatrix")).Add(HX_CSTRING("ProjectionMatrix")).Add(HX_CSTRING("WorldMatrix")).Add(HX_CSTRING("WorldMatrixInverse")).Add(HX_CSTRING("WorldMatrixIT")).Add(HX_CSTRING("Time")).Add(HX_CSTRING("RandomSeed")).Add(HX_CSTRING("RandomTexture")).Add(HX_CSTRING("ScreenTexture")).Add(HX_CSTRING("ScreenDepth")).Add(HX_CSTRING("Ambient")).Add(HX_CSTRING("CameraPosition")).Add(HX_CSTRING("ProjectionMatrixInverse")).Add(HX_CSTRING("ViewMatrixInverse"));
	HX_STACK_LINE(172)
	::haxor::context::UID _g = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(172)
	this->mid = _g;
	HX_STACK_LINE(173)
	::haxor::context::UID _g1 = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(173)
	this->sid = _g1;
	HX_STACK_LINE(174)
	::haxor::context::UID _g2 = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(174)
	this->uid = _g2;
	HX_STACK_LINE(177)
	this->zfunc = (int)515;
	HX_STACK_LINE(178)
	this->ztest = true;
	HX_STACK_LINE(179)
	this->zwrite = true;
	HX_STACK_LINE(180)
	this->blend = false;
	HX_STACK_LINE(181)
	this->blendSrc = (int)1;
	HX_STACK_LINE(182)
	this->blendDst = (int)0;
	HX_STACK_LINE(183)
	this->invert = false;
	HX_STACK_LINE(184)
	this->cull = (int)2;
	HX_STACK_LINE(186)
	int max_buffers = (int)512;		HX_STACK_VAR(max_buffers,"max_buffers");
	HX_STACK_LINE(187)
	int max_programs = (int)1024;		HX_STACK_VAR(max_programs,"max_programs");
	HX_STACK_LINE(189)
	this->locations = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(190)
	this->uniforms = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(191)
	this->programs = Array_obj< int >::__new();
	HX_STACK_LINE(192)
	this->vertex_shaders = Array_obj< int >::__new();
	HX_STACK_LINE(193)
	this->fragment_shaders = Array_obj< int >::__new();
	HX_STACK_LINE(194)
	this->globals = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(195)
	this->camera = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(196)
	this->transform = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(197)
	this->slot = (int)0;
	HX_STACK_LINE(198)
	this->viewmatrix = Array_obj< bool >::__new();
	HX_STACK_LINE(199)
	this->projmatrix = Array_obj< bool >::__new();
	HX_STACK_LINE(201)
	{
		HX_STACK_LINE(201)
		int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(201)
		while((true)){
			HX_STACK_LINE(201)
			if ((!(((_g3 < max_programs))))){
				HX_STACK_LINE(201)
				break;
			}
			HX_STACK_LINE(201)
			int i = (_g3)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(203)
			Array< int > l = Array_obj< int >::__new();		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(204)
			Array< int > ul = Array_obj< int >::__new();		HX_STACK_VAR(ul,"ul");
			HX_STACK_LINE(205)
			{
				HX_STACK_LINE(205)
				int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(205)
				while((true)){
					HX_STACK_LINE(205)
					if ((!(((_g11 < max_buffers))))){
						HX_STACK_LINE(205)
						break;
					}
					HX_STACK_LINE(205)
					int j = (_g11)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(205)
					l->push((int)-1);
				}
			}
			HX_STACK_LINE(206)
			{
				HX_STACK_LINE(206)
				int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(206)
				while((true)){
					HX_STACK_LINE(206)
					if ((!(((_g11 < (int)200))))){
						HX_STACK_LINE(206)
						break;
					}
					HX_STACK_LINE(206)
					int j = (_g11)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(206)
					ul->push(::haxor::graphics::GL_obj::INVALID);
				}
			}
			HX_STACK_LINE(207)
			this->camera->push(null());
			HX_STACK_LINE(208)
			this->transform->push(null());
			HX_STACK_LINE(209)
			this->globals->push(Array_obj< ::String >::__new());
			HX_STACK_LINE(210)
			this->locations->push(l);
			HX_STACK_LINE(211)
			this->uniforms->push(ul);
			HX_STACK_LINE(212)
			this->programs->push(::haxor::graphics::GL_obj::INVALID);
			HX_STACK_LINE(213)
			this->vertex_shaders->push(::haxor::graphics::GL_obj::INVALID);
			HX_STACK_LINE(214)
			this->fragment_shaders->push(::haxor::graphics::GL_obj::INVALID);
			HX_STACK_LINE(216)
			this->viewmatrix->push(false);
			HX_STACK_LINE(217)
			this->projmatrix->push(false);
		}
	}
}
;
	return null();
}

//MaterialContext_obj::~MaterialContext_obj() { }

Dynamic MaterialContext_obj::__CreateEmpty() { return  new MaterialContext_obj; }
hx::ObjectPtr< MaterialContext_obj > MaterialContext_obj::__new()
{  hx::ObjectPtr< MaterialContext_obj > result = new MaterialContext_obj();
	result->__construct();
	return result;}

Dynamic MaterialContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MaterialContext_obj > result = new MaterialContext_obj();
	result->__construct();
	return result;}

Void MaterialContext_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","Initialize",0x874c6501,"haxor.context.MaterialContext.Initialize","haxor/context/MaterialContext.hx",226,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_LINE(230)
		::haxor::graphics::GL_obj::m_gl->DepthFunc((int)515);
		HX_STACK_LINE(231)
		::haxor::graphics::GL_obj::m_gl->Enable((int)2929);
		HX_STACK_LINE(232)
		::haxor::graphics::GL_obj::m_gl->DepthMask(true);
		HX_STACK_LINE(233)
		::haxor::graphics::GL_obj::m_gl->Disable((int)3042);
		HX_STACK_LINE(234)
		::haxor::graphics::GL_obj::m_gl->BlendFunc((int)1,(int)0);
		HX_STACK_LINE(235)
		::haxor::graphics::GL_obj::m_gl->Enable((int)2884);
		HX_STACK_LINE(236)
		::haxor::graphics::GL_obj::m_gl->FrontFace((int)2305);
		HX_STACK_LINE(237)
		::haxor::graphics::GL_obj::m_gl->CullFace((int)1029);
		HX_STACK_LINE(239)
		::haxor::graphics::GL_obj::m_gl->Enable((int)3089);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MaterialContext_obj,Initialize,(void))

Void MaterialContext_obj::UpdateFlags( ::haxor::graphics::material::Material m){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","UpdateFlags",0x8ca09bad,"haxor.context.MaterialContext.UpdateFlags","haxor/context/MaterialContext.hx",248,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_LINE(260)
		if (((m->zfunc != this->zfunc))){
			HX_STACK_LINE(260)
			this->zfunc = m->zfunc;
			HX_STACK_LINE(260)
			::haxor::graphics::GL_obj::m_gl->DepthFunc(this->zfunc);
		}
		HX_STACK_LINE(261)
		if (((m->ztest != this->ztest))){
			HX_STACK_LINE(261)
			this->ztest = m->ztest;
			HX_STACK_LINE(261)
			if ((this->ztest)){
				HX_STACK_LINE(261)
				::haxor::graphics::GL_obj::m_gl->Enable((int)2929);
			}
			else{
				HX_STACK_LINE(261)
				::haxor::graphics::GL_obj::m_gl->Disable((int)2929);
			}
		}
		HX_STACK_LINE(262)
		if (((m->zwrite != this->zwrite))){
			HX_STACK_LINE(262)
			this->zwrite = m->zwrite;
			HX_STACK_LINE(262)
			::haxor::graphics::GL_obj::m_gl->DepthMask(this->zwrite);
		}
		HX_STACK_LINE(263)
		if (((m->blend != this->blend))){
			HX_STACK_LINE(263)
			this->blend = m->blend;
			HX_STACK_LINE(263)
			if ((this->blend)){
				HX_STACK_LINE(263)
				::haxor::graphics::GL_obj::m_gl->Enable((int)3042);
			}
			else{
				HX_STACK_LINE(263)
				::haxor::graphics::GL_obj::m_gl->Disable((int)3042);
			}
		}
		HX_STACK_LINE(264)
		bool blend_change = false;		HX_STACK_VAR(blend_change,"blend_change");
		HX_STACK_LINE(265)
		if (((m->blendSrc != this->blendSrc))){
			HX_STACK_LINE(265)
			blend_change = true;
			HX_STACK_LINE(265)
			this->blendSrc = m->blendSrc;
		}
		HX_STACK_LINE(266)
		if (((m->blendDst != this->blendDst))){
			HX_STACK_LINE(266)
			blend_change = true;
			HX_STACK_LINE(266)
			this->blendDst = m->blendDst;
		}
		HX_STACK_LINE(267)
		if ((blend_change)){
			HX_STACK_LINE(267)
			::haxor::graphics::GL_obj::m_gl->BlendFunc(this->blendSrc,this->blendDst);
		}
		HX_STACK_LINE(270)
		if (((m->invert != this->invert))){
			HX_STACK_LINE(270)
			this->invert = m->invert;
			HX_STACK_LINE(270)
			::haxor::graphics::GL_obj::m_gl->FrontFace((  ((this->invert)) ? int((int)2304) : int((int)2305) ));
		}
		HX_STACK_LINE(271)
		if (((m->cull != this->cull))){
			HX_STACK_LINE(273)
			this->cull = m->cull;
			HX_STACK_LINE(274)
			if (((this->cull == (int)0))){
				HX_STACK_LINE(276)
				::haxor::graphics::GL_obj::m_gl->Disable((int)2884);
			}
			else{
				HX_STACK_LINE(280)
				::haxor::graphics::GL_obj::m_gl->Enable((int)2884);
				HX_STACK_LINE(281)
				::haxor::graphics::GL_obj::m_gl->CullFace((  (((this->cull == (int)1))) ? int((int)1028) : int((int)1029) ));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,UpdateFlags,(void))

Void MaterialContext_obj::InitializeMaterial( ::haxor::graphics::material::Material m){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","InitializeMaterial",0x8f01e6c8,"haxor.context.MaterialContext.InitializeMaterial","haxor/context/MaterialContext.hx",292,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_LINE(292)
		this->programs[m->__cid] = ::haxor::graphics::GL_obj::m_gl->CreateProgram();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,InitializeMaterial,(void))

Void MaterialContext_obj::InitializeShader( ::haxor::graphics::material::Shader s){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","InitializeShader",0x7b70cf06,"haxor.context.MaterialContext.InitializeShader","haxor/context/MaterialContext.hx",301,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(303)
		if ((::Std_obj::is(s,hx::ClassOf< ::haxor::graphics::material::UberShader >()))){
			HX_STACK_LINE(303)
			return null();
		}
		HX_STACK_LINE(304)
		::String vs_err = HX_CSTRING("");		HX_STACK_VAR(vs_err,"vs_err");
		HX_STACK_LINE(305)
		::String fs_err = HX_CSTRING("");		HX_STACK_VAR(fs_err,"fs_err");
		HX_STACK_LINE(306)
		::String _g = this->CreateCompileShader(s,(int)35633,this->vertex_shaders);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(306)
		vs_err = _g;
		HX_STACK_LINE(307)
		::String _g1 = this->CreateCompileShader(s,(int)35632,this->fragment_shaders);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(307)
		fs_err = _g1;
		HX_STACK_LINE(308)
		if ((s->m_hasError)){
			HX_STACK_LINE(310)
			::String _g2 = s->get_name();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(310)
			::String _g3 = (HX_CSTRING("Shader> Compile Error @ [") + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(310)
			::String _g4 = (_g3 + HX_CSTRING("]"));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(310)
			::haxor::core::Console_obj::LogError(_g4,null());
			HX_STACK_LINE(312)
			::haxor::core::Console_obj::Log((HX_CSTRING("[vertex]\n") + vs_err),null());
			HX_STACK_LINE(314)
			::haxor::core::Console_obj::Log((HX_CSTRING("[fragment]\n") + fs_err),null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,InitializeShader,(void))

Void MaterialContext_obj::CreateUniform( ::haxor::graphics::material::Material m,::haxor::graphics::material::MaterialUniform u){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","CreateUniform",0x5e968a87,"haxor.context.MaterialContext.CreateUniform","haxor/context/MaterialContext.hx",327,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_ARG(u,"u")
		HX_STACK_LINE(328)
		int p = this->programs->__get(m->__cid);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(329)
		int loc = ::haxor::graphics::GL_obj::m_gl->GetUniformLocation(p,u->name);		HX_STACK_VAR(loc,"loc");
		HX_STACK_LINE(331)
		this->uniforms->__get(m->__cid).StaticCast< Array< int > >()[u->__cid] = loc;
		HX_STACK_LINE(332)
		u->__d = true;
		HX_STACK_LINE(333)
		u->exists = (loc != ::haxor::graphics::GL_obj::INVALID);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MaterialContext_obj,CreateUniform,(void))

Void MaterialContext_obj::DestroyUniform( ::haxor::graphics::material::Material m,::haxor::graphics::material::MaterialUniform u){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","DestroyUniform",0x32638f8b,"haxor.context.MaterialContext.DestroyUniform","haxor/context/MaterialContext.hx",342,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_ARG(u,"u")
		HX_STACK_LINE(345)
		if (((m != null()))){
			HX_STACK_LINE(345)
			this->uniforms->__get(m->__cid).StaticCast< Array< int > >()[u->__cid] = ::haxor::graphics::GL_obj::INVALID;
		}
		HX_STACK_LINE(346)
		{
			HX_STACK_LINE(346)
			int v = u->__cid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(346)
			::haxor::context::EngineContext_obj::material->uid->m_cache->push(v);
			HX_STACK_LINE(346)
			v;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MaterialContext_obj,DestroyUniform,(void))

::String MaterialContext_obj::CreateCompileShader( ::haxor::graphics::material::Shader s,int t,Array< int > c){
	HX_STACK_FRAME("haxor.context.MaterialContext","CreateCompileShader",0x8fb6fa8b,"haxor.context.MaterialContext.CreateCompileShader","haxor/context/MaterialContext.hx",357,0x0e17e323)
	HX_STACK_THIS(this)
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(358)
	int id = ::haxor::graphics::GL_obj::m_gl->CreateShader(t);		HX_STACK_VAR(id,"id");
	HX_STACK_LINE(359)
	::String ss;		HX_STACK_VAR(ss,"ss");
	HX_STACK_LINE(359)
	if (((t == (int)35633))){
		HX_STACK_LINE(359)
		ss = s->m_vss;
	}
	else{
		HX_STACK_LINE(359)
		ss = s->m_fss;
	}
	HX_STACK_LINE(360)
	c[s->__cid] = id;
	HX_STACK_LINE(361)
	::haxor::graphics::GL_obj::m_gl->ShaderSource(id,ss);
	HX_STACK_LINE(362)
	::haxor::graphics::GL_obj::m_gl->CompileShader(id);
	HX_STACK_LINE(363)
	int _g = ::haxor::graphics::GL_obj::m_gl->GetShaderParameter(id,(int)35713);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(363)
	if (((_g == (int)0))){
		HX_STACK_LINE(365)
		s->m_hasError = true;
		HX_STACK_LINE(366)
		return ::haxor::graphics::GL_obj::m_gl->GetShaderInfoLog(id);
	}
	HX_STACK_LINE(368)
	return HX_CSTRING("");
}


HX_DEFINE_DYNAMIC_FUNC3(MaterialContext_obj,CreateCompileShader,return )

Void MaterialContext_obj::UpdateShader( ::haxor::graphics::material::Material m,::haxor::graphics::material::Shader s0,::haxor::graphics::material::Shader s1){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","UpdateShader",0x64eea7ff,"haxor.context.MaterialContext.UpdateShader","haxor/context/MaterialContext.hx",376,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_ARG(s0,"s0")
		HX_STACK_ARG(s1,"s1")
		HX_STACK_LINE(377)
		int p = this->programs->__get(m->__cid);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(378)
		int vs_id;		HX_STACK_VAR(vs_id,"vs_id");
		HX_STACK_LINE(379)
		int fs_id;		HX_STACK_VAR(fs_id,"fs_id");
		HX_STACK_LINE(381)
		if (((s0 != null()))){
			HX_STACK_LINE(383)
			vs_id = this->vertex_shaders->__get(s0->__cid);
			HX_STACK_LINE(384)
			fs_id = this->fragment_shaders->__get(s0->__cid);
			HX_STACK_LINE(385)
			::haxor::graphics::GL_obj::m_gl->DetachShader(p,vs_id);
			HX_STACK_LINE(386)
			::haxor::graphics::GL_obj::m_gl->DetachShader(p,fs_id);
		}
		HX_STACK_LINE(391)
		if (((s1 != null()))){
			HX_STACK_LINE(393)
			vs_id = this->vertex_shaders->__get(s1->__cid);
			HX_STACK_LINE(394)
			fs_id = this->fragment_shaders->__get(s1->__cid);
			HX_STACK_LINE(395)
			::haxor::graphics::GL_obj::m_gl->AttachShader(p,vs_id);
			HX_STACK_LINE(396)
			::haxor::graphics::GL_obj::m_gl->AttachShader(p,fs_id);
			HX_STACK_LINE(398)
			Array< ::String > al = ::haxor::context::EngineContext_obj::mesh->attribs;		HX_STACK_VAR(al,"al");
			HX_STACK_LINE(399)
			{
				HX_STACK_LINE(399)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(399)
				int _g = al->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(399)
				while((true)){
					HX_STACK_LINE(399)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(399)
						break;
					}
					HX_STACK_LINE(399)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(399)
					::haxor::graphics::GL_obj::m_gl->BindAttribLocation(p,i,al->__get(i));
				}
			}
			HX_STACK_LINE(400)
			::haxor::graphics::GL_obj::m_gl->LinkProgram(p);
			HX_STACK_LINE(402)
			int _g = ::haxor::graphics::GL_obj::m_gl->GetProgramParameter(p,(int)35714);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(402)
			if (((_g == (int)0))){
				HX_STACK_LINE(404)
				::String _g1 = m->get_name();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(404)
				::String _g2 = (HX_CSTRING("Material> [") + _g1);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(404)
				::String _g3 = (_g2 + HX_CSTRING("] Link Error @ ["));		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(404)
				::String _g4 = s1->get_name();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(404)
				::String _g5 = (_g3 + _g4);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(404)
				::String _g6 = (_g5 + HX_CSTRING("]"));		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(404)
				::haxor::core::Console_obj::LogError(_g6,null());
			}
			HX_STACK_LINE(407)
			Array< ::Dynamic > ul = m->m_uniforms;		HX_STACK_VAR(ul,"ul");
			HX_STACK_LINE(409)
			{
				HX_STACK_LINE(409)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(409)
				int _g2 = ul->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(409)
				while((true)){
					HX_STACK_LINE(409)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(409)
						break;
					}
					HX_STACK_LINE(409)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(409)
					this->CreateUniform(m,ul->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >());
				}
			}
			HX_STACK_LINE(412)
			{
				HX_STACK_LINE(412)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(412)
				int _g2 = this->locations->__get(m->__cid).StaticCast< Array< int > >()->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(412)
				while((true)){
					HX_STACK_LINE(412)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(412)
						break;
					}
					HX_STACK_LINE(412)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(412)
					this->locations->__get(m->__cid).StaticCast< Array< int > >()[i] = (int)-1;
				}
			}
		}
		HX_STACK_LINE(416)
		Array< ::String > gl = this->uniform_globals->copy();		HX_STACK_VAR(gl,"gl");
		HX_STACK_LINE(417)
		int k = (int)0;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(418)
		::haxor::math::Matrix4 m4;		HX_STACK_VAR(m4,"m4");
		HX_STACK_LINE(418)
		{
			HX_STACK_LINE(418)
			::haxor::math::Matrix4 _this;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(418)
			{
				HX_STACK_LINE(418)
				::haxor::context::DataContext _this1 = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this1,"_this1");
				HX_STACK_LINE(418)
				int _g7 = _this1->m_nq = hx::Mod(((_this1->m_nm4 + (int)1)),_this1->m_m4->length);		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(418)
				_this = _this1->m_m4->__get(_g7).StaticCast< ::haxor::math::Matrix4 >();
			}
			HX_STACK_LINE(418)
			m4 = _this->Set((int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1,(int)0,(int)0,(int)0,(int)0,(int)1);
		}
		HX_STACK_LINE(419)
		while((true)){
			HX_STACK_LINE(419)
			if ((!(((k < gl->length))))){
				HX_STACK_LINE(419)
				break;
			}
			HX_STACK_LINE(421)
			::String un = gl->__get(k);		HX_STACK_VAR(un,"un");
			HX_STACK_LINE(422)
			int _g8 = ::haxor::graphics::GL_obj::m_gl->GetUniformLocation(p,un);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(422)
			if (((_g8 == ::haxor::graphics::GL_obj::INVALID))){
				HX_STACK_LINE(422)
				gl->remove(un);
				HX_STACK_LINE(422)
				continue;
			}
			HX_STACK_LINE(425)
			::String _switch_1 = (un);
			if (  ( _switch_1==HX_CSTRING("Ambient"))){
				struct _Function_3_1{
					inline static ::haxor::math::Color Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/MaterialContext.hx",427,0x0e17e323)
						{
							HX_STACK_LINE(427)
							::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(427)
							int _g9 = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g9,"_g9");
							HX_STACK_LINE(427)
							return _this->m_c->__get(_g9).StaticCast< ::haxor::math::Color >();
						}
						return null();
					}
				};
				HX_STACK_LINE(427)
				::haxor::math::Color p_color = (_Function_3_1::Block())->Set((int)1,(int)1,(int)1,(int)1);		HX_STACK_VAR(p_color,"p_color");
				HX_STACK_LINE(427)
				m->SetFloat4(un,p_color->r,p_color->g,p_color->b,p_color->a);
			}
			else if (  ( _switch_1==HX_CSTRING("Time"))){
				HX_STACK_LINE(428)
				m->SetFloat(un,0.0);
			}
			else if (  ( _switch_1==HX_CSTRING("RandomSeed"))){
				HX_STACK_LINE(429)
				m->SetFloat(un,0.0);
			}
			else if (  ( _switch_1==HX_CSTRING("WorldMatrix"))){
				HX_STACK_LINE(433)
				m->SetMatrix4(un,m4,null());
			}
			else if (  ( _switch_1==HX_CSTRING("WorldMatrixInverse"))){
				HX_STACK_LINE(434)
				m->SetMatrix4(un,m4,null());
			}
			else if (  ( _switch_1==HX_CSTRING("WorldMatrixIT"))){
				HX_STACK_LINE(435)
				m->SetMatrix4(un,m4,null());
			}
			else if (  ( _switch_1==HX_CSTRING("CameraPosition"))){
				struct _Function_3_1{
					inline static ::haxor::math::Vector3 Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/context/MaterialContext.hx",436,0x0e17e323)
						{
							HX_STACK_LINE(436)
							::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(436)
							int _g10 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g10,"_g10");
							HX_STACK_LINE(436)
							return _this->m_v3->__get(_g10).StaticCast< ::haxor::math::Vector3 >();
						}
						return null();
					}
				};
				HX_STACK_LINE(436)
				::haxor::math::Vector3 p_v = (_Function_3_1::Block())->Set((int)0,(int)0,(int)0);		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(436)
				m->SetFloat3(un,p_v->x,p_v->y,p_v->z);
			}
			else if (  ( _switch_1==HX_CSTRING("ViewMatrix"))){
				HX_STACK_LINE(437)
				m->SetMatrix4(un,m4,null());
			}
			else if (  ( _switch_1==HX_CSTRING("ViewMatrixInverse"))){
				HX_STACK_LINE(438)
				m->SetMatrix4(un,m4,null());
			}
			else if (  ( _switch_1==HX_CSTRING("ProjectionMatrix"))){
				HX_STACK_LINE(439)
				m->SetMatrix4(un,m4,null());
			}
			else if (  ( _switch_1==HX_CSTRING("ProjectionMatrixInverse"))){
				HX_STACK_LINE(440)
				m->SetMatrix4(un,m4,null());
			}
			HX_STACK_LINE(442)
			(k)++;
		}
		HX_STACK_LINE(444)
		this->globals[m->__cid] = gl;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(MaterialContext_obj,UpdateShader,(void))

Void MaterialContext_obj::UpdateMaterial( ::haxor::graphics::material::Material m){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","UpdateMaterial",0x3662b001,"haxor.context.MaterialContext.UpdateMaterial","haxor/context/MaterialContext.hx",454,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,UpdateMaterial,(void))

int MaterialContext_obj::GetAttribLocation( ::haxor::graphics::mesh::MeshAttrib a){
	HX_STACK_FRAME("haxor.context.MaterialContext","GetAttribLocation",0x3f3c2f44,"haxor.context.MaterialContext.GetAttribLocation","haxor/context/MaterialContext.hx",464,0x0e17e323)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_LINE(465)
	if (((this->current == null()))){
		HX_STACK_LINE(465)
		return (int)-1;
	}
	HX_STACK_LINE(466)
	int p = this->programs->__get(this->current->__cid);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(467)
	int loc = this->locations->__get(this->current->__cid).StaticCast< Array< int > >()->__get(a->__cid);		HX_STACK_VAR(loc,"loc");
	HX_STACK_LINE(468)
	if (((loc == (int)-1))){
		HX_STACK_LINE(470)
		int _g = ::haxor::graphics::GL_obj::m_gl->GetAttribLocation(p,a->m_name);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(470)
		loc = _g;
		HX_STACK_LINE(471)
		if (((loc < (int)0))){
			HX_STACK_LINE(471)
			this->locations->__get(this->current->__cid).StaticCast< Array< int > >()[a->__cid] = (int)-2;
		}
	}
	HX_STACK_LINE(473)
	return loc;
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,GetAttribLocation,return )

Void MaterialContext_obj::Bind( ::haxor::graphics::material::Material m,::haxor::component::Transform t,::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","Bind",0x93355eae,"haxor.context.MaterialContext.Bind","haxor/context/MaterialContext.hx",481,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(482)
		bool material_change = (m != this->current);		HX_STACK_VAR(material_change,"material_change");
		HX_STACK_LINE(483)
		this->UseMaterial(m);
		HX_STACK_LINE(484)
		this->UpdateMaterialUniforms(t,c,material_change);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(MaterialContext_obj,Bind,(void))

Void MaterialContext_obj::UseMaterial( ::haxor::graphics::material::Material m){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","UseMaterial",0xef2c6b3d,"haxor.context.MaterialContext.UseMaterial","haxor/context/MaterialContext.hx",493,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_LINE(493)
		if (((m != this->current))){
			HX_STACK_LINE(495)
			this->Unbind();
			HX_STACK_LINE(496)
			this->current = m;
			HX_STACK_LINE(497)
			if (((m != null()))){
				HX_STACK_LINE(499)
				this->viewmatrix[m->__cid] = false;
				HX_STACK_LINE(500)
				this->projmatrix[m->__cid] = false;
				HX_STACK_LINE(501)
				int p = this->programs->__get(m->__cid);		HX_STACK_VAR(p,"p");
				HX_STACK_LINE(502)
				this->UpdateFlags(m);
				HX_STACK_LINE(503)
				::haxor::graphics::GL_obj::m_gl->UseProgram(p);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,UseMaterial,(void))

Void MaterialContext_obj::UpdateMaterialUniforms( ::haxor::component::Transform t,::haxor::component::Camera c,bool p_changed){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","UpdateMaterialUniforms",0x0f8aa1e0,"haxor.context.MaterialContext.UpdateMaterialUniforms","haxor/context/MaterialContext.hx",517,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(c,"c")
		HX_STACK_ARG(p_changed,"p_changed")
		HX_STACK_LINE(517)
		if (((this->current != null()))){
			HX_STACK_LINE(520)
			{
				HX_STACK_LINE(521)
				if (((c == null()))){
					HX_STACK_LINE(521)
					this->viewmatrix[this->current->__cid] = false;
				}
				else{
					HX_STACK_LINE(521)
					this->viewmatrix[this->current->__cid] = c->m_view_uniform_dirty;
				}
				HX_STACK_LINE(522)
				if (((c == null()))){
					HX_STACK_LINE(522)
					this->projmatrix[this->current->__cid] = false;
				}
				else{
					HX_STACK_LINE(522)
					this->projmatrix[this->current->__cid] = c->m_proj_uniform_dirty;
				}
			}
			HX_STACK_LINE(526)
			::haxor::component::Transform _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(526)
			if (((t == null()))){
				HX_STACK_LINE(526)
				_g = ::haxor::component::Transform_obj::get_root();
			}
			else{
				HX_STACK_LINE(526)
				_g = t;
			}
			HX_STACK_LINE(526)
			t = _g;
			HX_STACK_LINE(527)
			bool ut = (t != this->transform->__get(this->current->__cid).StaticCast< ::haxor::component::Transform >());		HX_STACK_VAR(ut,"ut");
			HX_STACK_LINE(528)
			if (((this->transform->__get(this->current->__cid).StaticCast< ::haxor::component::Transform >() != null()))){
				HX_STACK_LINE(528)
				this->transform->__get(this->current->__cid).StaticCast< ::haxor::component::Transform >()->m_uniform_dirty = false;
			}
			HX_STACK_LINE(529)
			this->transform[this->current->__cid] = t;
			HX_STACK_LINE(530)
			ut = (bool(ut) || bool(t->m_uniform_dirty));
			HX_STACK_LINE(533)
			bool uc = (bool((c != this->camera->__get(this->current->__cid).StaticCast< ::haxor::component::Camera >())) && bool((c != null())));		HX_STACK_VAR(uc,"uc");
			HX_STACK_LINE(534)
			bool ucv = (bool(this->viewmatrix->__get(this->current->__cid)) || bool(uc));		HX_STACK_VAR(ucv,"ucv");
			HX_STACK_LINE(535)
			bool ucp = (bool(this->projmatrix->__get(this->current->__cid)) || bool(uc));		HX_STACK_VAR(ucp,"ucp");
			HX_STACK_LINE(536)
			if (((c != null()))){
				HX_STACK_LINE(536)
				this->camera[this->current->__cid] = c;
			}
			HX_STACK_LINE(538)
			this->UploadUniforms(ut,ucv,ucp,t,c);
			HX_STACK_LINE(540)
			this->viewmatrix[this->current->__cid] = false;
			HX_STACK_LINE(541)
			this->projmatrix[this->current->__cid] = false;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(MaterialContext_obj,UpdateMaterialUniforms,(void))

Void MaterialContext_obj::UploadUniforms( bool ut,bool ucv,bool ucp,::haxor::component::Transform t,::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","UploadUniforms",0x49bf1c11,"haxor.context.MaterialContext.UploadUniforms","haxor/context/MaterialContext.hx",550,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ut,"ut")
		HX_STACK_ARG(ucv,"ucv")
		HX_STACK_ARG(ucp,"ucp")
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(551)
		Array< ::Dynamic > ul = this->current->m_uniforms;		HX_STACK_VAR(ul,"ul");
		HX_STACK_LINE(553)
		{
			HX_STACK_LINE(553)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(553)
			int _g = ul->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(553)
			while((true)){
				HX_STACK_LINE(553)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(553)
					break;
				}
				HX_STACK_LINE(553)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(555)
				::haxor::graphics::material::MaterialUniform u = ul->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >();		HX_STACK_VAR(u,"u");
				HX_STACK_LINE(558)
				this->UploadGlobalUniform(u,ut,ucv,ucp,t,c);
				HX_STACK_LINE(561)
				this->UploadUniform(this->current,u);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(MaterialContext_obj,UploadUniforms,(void))

Void MaterialContext_obj::UploadUniform( ::haxor::graphics::material::Material m,::haxor::graphics::material::MaterialUniform u){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","UploadUniform",0xebaac222,"haxor.context.MaterialContext.UploadUniform","haxor/context/MaterialContext.hx",570,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_ARG(u,"u")
		HX_STACK_LINE(571)
		int loc;		HX_STACK_VAR(loc,"loc");
		HX_STACK_LINE(572)
		loc = this->uniforms->__get(m->__cid).StaticCast< Array< int > >()->__get(u->__cid);
		HX_STACK_LINE(573)
		if (((loc == ::haxor::graphics::GL_obj::INVALID))){
			HX_STACK_LINE(573)
			return null();
		}
		HX_STACK_LINE(574)
		if (((u->texture != null()))){
			HX_STACK_LINE(576)
			::haxor::context::TextureContext _this = ::haxor::context::EngineContext_obj::texture;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(576)
			::haxor::graphics::texture::Texture p_texture = u->texture;		HX_STACK_VAR(p_texture,"p_texture");
			HX_STACK_LINE(576)
			int slot = p_texture->__slot;		HX_STACK_VAR(slot,"slot");
			HX_STACK_LINE(576)
			{
				HX_STACK_LINE(576)
				::haxor::graphics::GL_obj::m_gl->ActiveTexture(((int)33984 + slot));
				HX_STACK_LINE(576)
				_this->active = slot;
			}
			HX_STACK_LINE(576)
			{
				HX_STACK_LINE(576)
				int id = _this->ids->__get(p_texture->__cid);		HX_STACK_VAR(id,"id");
				HX_STACK_LINE(576)
				::haxor::core::TextureType _g = p_texture->get_type();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(576)
				int target;		HX_STACK_VAR(target,"target");
				HX_STACK_LINE(576)
				if (((_g == ::haxor::core::TextureType_obj::Texture2D))){
					HX_STACK_LINE(576)
					target = (int)3553;
				}
				else{
					HX_STACK_LINE(576)
					::haxor::core::TextureType _g1 = p_texture->get_type();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(576)
					if (((_g1 == ::haxor::core::TextureType_obj::RenderTexture))){
						HX_STACK_LINE(576)
						target = (int)3553;
					}
					else{
						HX_STACK_LINE(576)
						::haxor::core::TextureType _g2 = p_texture->get_type();		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(576)
						if (((_g2 == ::haxor::core::TextureType_obj::TextureCube))){
							HX_STACK_LINE(576)
							target = (int)34067;
						}
						else{
							HX_STACK_LINE(576)
							target = (int)3553;
						}
					}
				}
				HX_STACK_LINE(576)
				::haxor::graphics::GL_obj::m_gl->BindTexture(target,id);
				HX_STACK_LINE(576)
				_this->bind[slot] = p_texture;
			}
		}
		HX_STACK_LINE(578)
		if ((!(u->__d))){
			HX_STACK_LINE(578)
			return null();
		}
		HX_STACK_LINE(580)
		this->ApplyUniform(loc,u);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MaterialContext_obj,UploadUniform,(void))

Void MaterialContext_obj::ApplyUniform( int loc,::haxor::graphics::material::MaterialUniform u){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","ApplyUniform",0x3cdbcf57,"haxor.context.MaterialContext.ApplyUniform","haxor/context/MaterialContext.hx",589,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(loc,"loc")
		HX_STACK_ARG(u,"u")
		HX_STACK_LINE(590)
		int off = u->offset;		HX_STACK_VAR(off,"off");
		HX_STACK_LINE(592)
		if ((u->isFloat)){
			HX_STACK_LINE(594)
			::haxor::io::FloatArray b = u->data;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(595)
			switch( (int)(off)){
				case (int)1: {
					HX_STACK_LINE(597)
					Float p_x = b->Get((int)0);		HX_STACK_VAR(p_x,"p_x");
					HX_STACK_LINE(597)
					::haxor::graphics::GL_obj::m_gl->Uniform1f(loc,p_x);
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(598)
					Float p_x = b->Get((int)0);		HX_STACK_VAR(p_x,"p_x");
					HX_STACK_LINE(598)
					Float p_y = b->Get((int)1);		HX_STACK_VAR(p_y,"p_y");
					HX_STACK_LINE(598)
					::haxor::graphics::GL_obj::m_gl->Uniform2f(loc,p_x,p_y);
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(599)
					Float p_x = b->Get((int)0);		HX_STACK_VAR(p_x,"p_x");
					HX_STACK_LINE(599)
					Float p_y = b->Get((int)1);		HX_STACK_VAR(p_y,"p_y");
					HX_STACK_LINE(599)
					Float p_z = b->Get((int)2);		HX_STACK_VAR(p_z,"p_z");
					HX_STACK_LINE(599)
					::haxor::graphics::GL_obj::m_gl->Uniform3f(loc,p_x,p_y,p_z);
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(600)
					Float p_x = b->Get((int)0);		HX_STACK_VAR(p_x,"p_x");
					HX_STACK_LINE(600)
					Float p_y = b->Get((int)1);		HX_STACK_VAR(p_y,"p_y");
					HX_STACK_LINE(600)
					Float p_z = b->Get((int)2);		HX_STACK_VAR(p_z,"p_z");
					HX_STACK_LINE(600)
					Float p_w = b->Get((int)3);		HX_STACK_VAR(p_w,"p_w");
					HX_STACK_LINE(600)
					::haxor::graphics::GL_obj::m_gl->Uniform4f(loc,p_x,p_y,p_z,p_w);
				}
				;break;
				case (int)16: {
					HX_STACK_LINE(601)
					::haxor::graphics::GL_obj::m_gl->UniformMatrix4fv(loc,false,b);
				}
				;break;
				default: {
					HX_STACK_LINE(602)
					::haxor::graphics::GL_obj::m_gl->Uniform1fv(loc,b);
				}
			}
		}
		else{
			HX_STACK_LINE(607)
			::haxor::io::Int32Array b = u->data;		HX_STACK_VAR(b,"b");
			HX_STACK_LINE(608)
			switch( (int)(off)){
				case (int)1: {
					HX_STACK_LINE(610)
					int p_x = b->Get((int)0);		HX_STACK_VAR(p_x,"p_x");
					HX_STACK_LINE(610)
					::haxor::graphics::GL_obj::m_gl->Uniform1i(loc,p_x);
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(611)
					int p_x = b->Get((int)0);		HX_STACK_VAR(p_x,"p_x");
					HX_STACK_LINE(611)
					int p_y = b->Get((int)1);		HX_STACK_VAR(p_y,"p_y");
					HX_STACK_LINE(611)
					::haxor::graphics::GL_obj::m_gl->Uniform2i(loc,p_x,p_y);
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(612)
					int p_x = b->Get((int)0);		HX_STACK_VAR(p_x,"p_x");
					HX_STACK_LINE(612)
					int p_y = b->Get((int)1);		HX_STACK_VAR(p_y,"p_y");
					HX_STACK_LINE(612)
					int p_z = b->Get((int)2);		HX_STACK_VAR(p_z,"p_z");
					HX_STACK_LINE(612)
					::haxor::graphics::GL_obj::m_gl->Uniform3i(loc,p_x,p_y,p_z);
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(613)
					int p_x = b->Get((int)0);		HX_STACK_VAR(p_x,"p_x");
					HX_STACK_LINE(613)
					int p_y = b->Get((int)1);		HX_STACK_VAR(p_y,"p_y");
					HX_STACK_LINE(613)
					int p_z = b->Get((int)2);		HX_STACK_VAR(p_z,"p_z");
					HX_STACK_LINE(613)
					int p_w = b->Get((int)3);		HX_STACK_VAR(p_w,"p_w");
					HX_STACK_LINE(613)
					::haxor::graphics::GL_obj::m_gl->Uniform4i(loc,p_x,p_y,p_z,p_w);
				}
				;break;
				default: {
					HX_STACK_LINE(614)
					::haxor::graphics::GL_obj::m_gl->Uniform1iv(loc,b);
				}
			}
		}
		HX_STACK_LINE(617)
		u->__d = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MaterialContext_obj,ApplyUniform,(void))

Void MaterialContext_obj::UploadGlobalUniform( ::haxor::graphics::material::MaterialUniform u,bool ut,bool ucv,bool ucp,::haxor::component::Transform t,::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","UploadGlobalUniform",0x6eb8617f,"haxor.context.MaterialContext.UploadGlobalUniform","haxor/context/MaterialContext.hx",626,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(u,"u")
		HX_STACK_ARG(ut,"ut")
		HX_STACK_ARG(ucv,"ucv")
		HX_STACK_ARG(ucp,"ucp")
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(626)
		::String _g = u->name;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(626)
		::String _switch_2 = (_g);
		if (  ( _switch_2==HX_CSTRING("Ambient"))){
			HX_STACK_LINE(628)
			::haxor::math::Color p_color = ::haxor::component::Light_obj::ambient;		HX_STACK_VAR(p_color,"p_color");
			HX_STACK_LINE(628)
			u->SetFloat4(p_color->r,p_color->g,p_color->b,p_color->a);
		}
		else if (  ( _switch_2==HX_CSTRING("Time"))){
			HX_STACK_LINE(629)
			u->SetFloat(::haxor::core::Time_obj::m_elapsed);
		}
		else if (  ( _switch_2==HX_CSTRING("RandomSeed"))){
			HX_STACK_LINE(630)
			Float _g1 = ::Math_obj::random();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(630)
			u->SetFloat(_g1);
		}
		else if (  ( _switch_2==HX_CSTRING("WorldMatrix"))){
			HX_STACK_LINE(634)
			if ((ut)){
				HX_STACK_LINE(634)
				::haxor::math::Matrix4 _g1 = t->get_WorldMatrix();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(634)
				u->SetMatrix4(_g1,null());
			}
		}
		else if (  ( _switch_2==HX_CSTRING("WorldMatrixInverse"))){
			HX_STACK_LINE(635)
			if ((ut)){
				HX_STACK_LINE(635)
				::haxor::math::Matrix4 _g2 = t->get_WorldMatrixInverse();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(635)
				u->SetMatrix4(_g2,null());
			}
		}
		else if (  ( _switch_2==HX_CSTRING("WorldMatrixIT"))){
			HX_STACK_LINE(636)
			if ((ut)){
				HX_STACK_LINE(636)
				::haxor::math::Matrix4 _g3 = t->get_WorldMatrixInverse();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(636)
				u->SetMatrix4(_g3,true);
			}
		}
		else if (  ( _switch_2==HX_CSTRING("CameraPosition"))){
			HX_STACK_LINE(637)
			if ((ucv)){
				HX_STACK_LINE(637)
				::haxor::math::Vector3 p_v = c->m_entity->m_transform->get_position();		HX_STACK_VAR(p_v,"p_v");
				HX_STACK_LINE(637)
				u->SetFloat3(p_v->x,p_v->y,p_v->z);
			}
		}
		else if (  ( _switch_2==HX_CSTRING("ViewMatrix"))){
			HX_STACK_LINE(638)
			if ((ucv)){
				HX_STACK_LINE(638)
				::haxor::math::Matrix4 _g4 = c->m_entity->m_transform->get_WorldMatrixInverse();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(638)
				u->SetMatrix4(_g4,null());
			}
		}
		else if (  ( _switch_2==HX_CSTRING("ViewMatrixInverse"))){
			HX_STACK_LINE(639)
			if ((ucv)){
				HX_STACK_LINE(639)
				::haxor::math::Matrix4 _g5 = c->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(639)
				u->SetMatrix4(_g5,null());
			}
		}
		else if (  ( _switch_2==HX_CSTRING("ProjectionMatrix"))){
			HX_STACK_LINE(640)
			if ((ucp)){
				HX_STACK_LINE(640)
				::haxor::math::Matrix4 _g6;		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(640)
				{
					HX_STACK_LINE(640)
					c->UpdateProjection();
					HX_STACK_LINE(640)
					_g6 = c->m_projectionMatrix;
				}
				HX_STACK_LINE(640)
				u->SetMatrix4(_g6,null());
			}
		}
		else if (  ( _switch_2==HX_CSTRING("ProjectionMatrixInverse"))){
			HX_STACK_LINE(641)
			if ((ucp)){
				HX_STACK_LINE(641)
				::haxor::math::Matrix4 _g7;		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(641)
				{
					HX_STACK_LINE(641)
					c->UpdateProjection();
					HX_STACK_LINE(641)
					_g7 = c->m_projectionMatrixInverse;
				}
				HX_STACK_LINE(641)
				u->SetMatrix4(_g7,null());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(MaterialContext_obj,UploadGlobalUniform,(void))

Void MaterialContext_obj::Unbind( ){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","Unbind",0x442b43c7,"haxor.context.MaterialContext.Unbind","haxor/context/MaterialContext.hx",649,0x0e17e323)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MaterialContext_obj,Unbind,(void))

Void MaterialContext_obj::DestroyMaterial( ::haxor::graphics::material::Material m){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","DestroyMaterial",0xd30a9a70,"haxor.context.MaterialContext.DestroyMaterial","haxor/context/MaterialContext.hx",658,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_LINE(659)
		int p = this->programs->__get(m->__cid);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(660)
		if (((m->m_shader != null()))){
			HX_STACK_LINE(662)
			::haxor::graphics::GL_obj::m_gl->DetachShader(p,this->vertex_shaders->__get(m->m_shader->__cid));
			HX_STACK_LINE(663)
			::haxor::graphics::GL_obj::m_gl->DetachShader(p,this->fragment_shaders->__get(m->m_shader->__cid));
		}
		HX_STACK_LINE(665)
		::haxor::graphics::GL_obj::m_gl->DeleteProgram(p);
		HX_STACK_LINE(666)
		{
			HX_STACK_LINE(666)
			int v = m->__cid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(666)
			::haxor::context::EngineContext_obj::material->mid->m_cache->push(v);
			HX_STACK_LINE(666)
			v;
		}
		HX_STACK_LINE(667)
		{
			HX_STACK_LINE(667)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(667)
			int _g = m->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(667)
			while((true)){
				HX_STACK_LINE(667)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(667)
					break;
				}
				HX_STACK_LINE(667)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(667)
				int v = m->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >()->__cid;		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(667)
				this->uid->m_cache->push(v);
				HX_STACK_LINE(667)
				v;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,DestroyMaterial,(void))

Void MaterialContext_obj::DestroyShader( ::haxor::graphics::material::Shader s){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","DestroyShader",0xac09c8ae,"haxor.context.MaterialContext.DestroyShader","haxor/context/MaterialContext.hx",675,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(676)
		::haxor::graphics::GL_obj::m_gl->DeleteShader(this->vertex_shaders->__get(s->__cid));
		HX_STACK_LINE(677)
		::haxor::graphics::GL_obj::m_gl->DeleteShader(this->fragment_shaders->__get(s->__cid));
		HX_STACK_LINE(678)
		{
			HX_STACK_LINE(678)
			int v = s->__cid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(678)
			::haxor::context::EngineContext_obj::material->sid->m_cache->push(v);
			HX_STACK_LINE(678)
			v;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,DestroyShader,(void))


MaterialContext_obj::MaterialContext_obj()
{
}

void MaterialContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MaterialContext);
	HX_MARK_MEMBER_NAME(uniform_globals,"uniform_globals");
	HX_MARK_MEMBER_NAME(globals,"globals");
	HX_MARK_MEMBER_NAME(mid,"mid");
	HX_MARK_MEMBER_NAME(sid,"sid");
	HX_MARK_MEMBER_NAME(uid,"uid");
	HX_MARK_MEMBER_NAME(vertex_shaders,"vertex_shaders");
	HX_MARK_MEMBER_NAME(fragment_shaders,"fragment_shaders");
	HX_MARK_MEMBER_NAME(error_shader,"error_shader");
	HX_MARK_MEMBER_NAME(programs,"programs");
	HX_MARK_MEMBER_NAME(camera,"camera");
	HX_MARK_MEMBER_NAME(transform,"transform");
	HX_MARK_MEMBER_NAME(viewmatrix,"viewmatrix");
	HX_MARK_MEMBER_NAME(projmatrix,"projmatrix");
	HX_MARK_MEMBER_NAME(locations,"locations");
	HX_MARK_MEMBER_NAME(slot,"slot");
	HX_MARK_MEMBER_NAME(uniforms,"uniforms");
	HX_MARK_MEMBER_NAME(current,"current");
	HX_MARK_MEMBER_NAME(ztest,"ztest");
	HX_MARK_MEMBER_NAME(zfunc,"zfunc");
	HX_MARK_MEMBER_NAME(zwrite,"zwrite");
	HX_MARK_MEMBER_NAME(blend,"blend");
	HX_MARK_MEMBER_NAME(queue,"queue");
	HX_MARK_MEMBER_NAME(blendSrc,"blendSrc");
	HX_MARK_MEMBER_NAME(blendDst,"blendDst");
	HX_MARK_MEMBER_NAME(invert,"invert");
	HX_MARK_MEMBER_NAME(cull,"cull");
	HX_MARK_END_CLASS();
}

void MaterialContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(uniform_globals,"uniform_globals");
	HX_VISIT_MEMBER_NAME(globals,"globals");
	HX_VISIT_MEMBER_NAME(mid,"mid");
	HX_VISIT_MEMBER_NAME(sid,"sid");
	HX_VISIT_MEMBER_NAME(uid,"uid");
	HX_VISIT_MEMBER_NAME(vertex_shaders,"vertex_shaders");
	HX_VISIT_MEMBER_NAME(fragment_shaders,"fragment_shaders");
	HX_VISIT_MEMBER_NAME(error_shader,"error_shader");
	HX_VISIT_MEMBER_NAME(programs,"programs");
	HX_VISIT_MEMBER_NAME(camera,"camera");
	HX_VISIT_MEMBER_NAME(transform,"transform");
	HX_VISIT_MEMBER_NAME(viewmatrix,"viewmatrix");
	HX_VISIT_MEMBER_NAME(projmatrix,"projmatrix");
	HX_VISIT_MEMBER_NAME(locations,"locations");
	HX_VISIT_MEMBER_NAME(slot,"slot");
	HX_VISIT_MEMBER_NAME(uniforms,"uniforms");
	HX_VISIT_MEMBER_NAME(current,"current");
	HX_VISIT_MEMBER_NAME(ztest,"ztest");
	HX_VISIT_MEMBER_NAME(zfunc,"zfunc");
	HX_VISIT_MEMBER_NAME(zwrite,"zwrite");
	HX_VISIT_MEMBER_NAME(blend,"blend");
	HX_VISIT_MEMBER_NAME(queue,"queue");
	HX_VISIT_MEMBER_NAME(blendSrc,"blendSrc");
	HX_VISIT_MEMBER_NAME(blendDst,"blendDst");
	HX_VISIT_MEMBER_NAME(invert,"invert");
	HX_VISIT_MEMBER_NAME(cull,"cull");
}

Dynamic MaterialContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"mid") ) { return mid; }
		if (HX_FIELD_EQ(inName,"sid") ) { return sid; }
		if (HX_FIELD_EQ(inName,"uid") ) { return uid; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"slot") ) { return slot; }
		if (HX_FIELD_EQ(inName,"cull") ) { return cull; }
		if (HX_FIELD_EQ(inName,"Bind") ) { return Bind_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"ztest") ) { return ztest; }
		if (HX_FIELD_EQ(inName,"zfunc") ) { return zfunc; }
		if (HX_FIELD_EQ(inName,"blend") ) { return blend; }
		if (HX_FIELD_EQ(inName,"queue") ) { return queue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"camera") ) { return camera; }
		if (HX_FIELD_EQ(inName,"zwrite") ) { return zwrite; }
		if (HX_FIELD_EQ(inName,"invert") ) { return invert; }
		if (HX_FIELD_EQ(inName,"Unbind") ) { return Unbind_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"globals") ) { return globals; }
		if (HX_FIELD_EQ(inName,"current") ) { return current; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"programs") ) { return programs; }
		if (HX_FIELD_EQ(inName,"uniforms") ) { return uniforms; }
		if (HX_FIELD_EQ(inName,"blendSrc") ) { return blendSrc; }
		if (HX_FIELD_EQ(inName,"blendDst") ) { return blendDst; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { return transform; }
		if (HX_FIELD_EQ(inName,"locations") ) { return locations; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"viewmatrix") ) { return viewmatrix; }
		if (HX_FIELD_EQ(inName,"projmatrix") ) { return projmatrix; }
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"UpdateFlags") ) { return UpdateFlags_dyn(); }
		if (HX_FIELD_EQ(inName,"UseMaterial") ) { return UseMaterial_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"error_shader") ) { return error_shader; }
		if (HX_FIELD_EQ(inName,"UpdateShader") ) { return UpdateShader_dyn(); }
		if (HX_FIELD_EQ(inName,"ApplyUniform") ) { return ApplyUniform_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"CreateUniform") ) { return CreateUniform_dyn(); }
		if (HX_FIELD_EQ(inName,"UploadUniform") ) { return UploadUniform_dyn(); }
		if (HX_FIELD_EQ(inName,"DestroyShader") ) { return DestroyShader_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"vertex_shaders") ) { return vertex_shaders; }
		if (HX_FIELD_EQ(inName,"DestroyUniform") ) { return DestroyUniform_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateMaterial") ) { return UpdateMaterial_dyn(); }
		if (HX_FIELD_EQ(inName,"UploadUniforms") ) { return UploadUniforms_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"uniform_globals") ) { return uniform_globals; }
		if (HX_FIELD_EQ(inName,"DestroyMaterial") ) { return DestroyMaterial_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"fragment_shaders") ) { return fragment_shaders; }
		if (HX_FIELD_EQ(inName,"InitializeShader") ) { return InitializeShader_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"GetAttribLocation") ) { return GetAttribLocation_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"InitializeMaterial") ) { return InitializeMaterial_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"CreateCompileShader") ) { return CreateCompileShader_dyn(); }
		if (HX_FIELD_EQ(inName,"UploadGlobalUniform") ) { return UploadGlobalUniform_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"UpdateMaterialUniforms") ) { return UpdateMaterialUniforms_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MaterialContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"mid") ) { mid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sid") ) { sid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
		if (HX_FIELD_EQ(inName,"uid") ) { uid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"slot") ) { slot=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cull") ) { cull=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"ztest") ) { ztest=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"zfunc") ) { zfunc=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blend") ) { blend=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"queue") ) { queue=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"camera") ) { camera=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"zwrite") ) { zwrite=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"invert") ) { invert=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"globals") ) { globals=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"current") ) { current=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"programs") ) { programs=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"uniforms") ) { uniforms=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blendSrc") ) { blendSrc=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blendDst") ) { blendDst=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"transform") ) { transform=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"locations") ) { locations=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"viewmatrix") ) { viewmatrix=inValue.Cast< Array< bool > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"projmatrix") ) { projmatrix=inValue.Cast< Array< bool > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"error_shader") ) { error_shader=inValue.Cast< ::haxor::graphics::material::Shader >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"vertex_shaders") ) { vertex_shaders=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"uniform_globals") ) { uniform_globals=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"fragment_shaders") ) { fragment_shaders=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MaterialContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("uniform_globals"));
	outFields->push(HX_CSTRING("globals"));
	outFields->push(HX_CSTRING("mid"));
	outFields->push(HX_CSTRING("sid"));
	outFields->push(HX_CSTRING("uid"));
	outFields->push(HX_CSTRING("vertex_shaders"));
	outFields->push(HX_CSTRING("fragment_shaders"));
	outFields->push(HX_CSTRING("error_shader"));
	outFields->push(HX_CSTRING("programs"));
	outFields->push(HX_CSTRING("camera"));
	outFields->push(HX_CSTRING("transform"));
	outFields->push(HX_CSTRING("viewmatrix"));
	outFields->push(HX_CSTRING("projmatrix"));
	outFields->push(HX_CSTRING("locations"));
	outFields->push(HX_CSTRING("slot"));
	outFields->push(HX_CSTRING("uniforms"));
	outFields->push(HX_CSTRING("current"));
	outFields->push(HX_CSTRING("ztest"));
	outFields->push(HX_CSTRING("zfunc"));
	outFields->push(HX_CSTRING("zwrite"));
	outFields->push(HX_CSTRING("blend"));
	outFields->push(HX_CSTRING("queue"));
	outFields->push(HX_CSTRING("blendSrc"));
	outFields->push(HX_CSTRING("blendDst"));
	outFields->push(HX_CSTRING("invert"));
	outFields->push(HX_CSTRING("cull"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(MaterialContext_obj,uniform_globals),HX_CSTRING("uniform_globals")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(MaterialContext_obj,globals),HX_CSTRING("globals")},
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(MaterialContext_obj,mid),HX_CSTRING("mid")},
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(MaterialContext_obj,sid),HX_CSTRING("sid")},
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(MaterialContext_obj,uid),HX_CSTRING("uid")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(MaterialContext_obj,vertex_shaders),HX_CSTRING("vertex_shaders")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(MaterialContext_obj,fragment_shaders),HX_CSTRING("fragment_shaders")},
	{hx::fsObject /*::haxor::graphics::material::Shader*/ ,(int)offsetof(MaterialContext_obj,error_shader),HX_CSTRING("error_shader")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(MaterialContext_obj,programs),HX_CSTRING("programs")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(MaterialContext_obj,camera),HX_CSTRING("camera")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(MaterialContext_obj,transform),HX_CSTRING("transform")},
	{hx::fsObject /*Array< bool >*/ ,(int)offsetof(MaterialContext_obj,viewmatrix),HX_CSTRING("viewmatrix")},
	{hx::fsObject /*Array< bool >*/ ,(int)offsetof(MaterialContext_obj,projmatrix),HX_CSTRING("projmatrix")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(MaterialContext_obj,locations),HX_CSTRING("locations")},
	{hx::fsInt,(int)offsetof(MaterialContext_obj,slot),HX_CSTRING("slot")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(MaterialContext_obj,uniforms),HX_CSTRING("uniforms")},
	{hx::fsObject /*::haxor::graphics::material::Material*/ ,(int)offsetof(MaterialContext_obj,current),HX_CSTRING("current")},
	{hx::fsBool,(int)offsetof(MaterialContext_obj,ztest),HX_CSTRING("ztest")},
	{hx::fsInt,(int)offsetof(MaterialContext_obj,zfunc),HX_CSTRING("zfunc")},
	{hx::fsBool,(int)offsetof(MaterialContext_obj,zwrite),HX_CSTRING("zwrite")},
	{hx::fsBool,(int)offsetof(MaterialContext_obj,blend),HX_CSTRING("blend")},
	{hx::fsInt,(int)offsetof(MaterialContext_obj,queue),HX_CSTRING("queue")},
	{hx::fsInt,(int)offsetof(MaterialContext_obj,blendSrc),HX_CSTRING("blendSrc")},
	{hx::fsInt,(int)offsetof(MaterialContext_obj,blendDst),HX_CSTRING("blendDst")},
	{hx::fsBool,(int)offsetof(MaterialContext_obj,invert),HX_CSTRING("invert")},
	{hx::fsInt,(int)offsetof(MaterialContext_obj,cull),HX_CSTRING("cull")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("uniform_globals"),
	HX_CSTRING("globals"),
	HX_CSTRING("mid"),
	HX_CSTRING("sid"),
	HX_CSTRING("uid"),
	HX_CSTRING("vertex_shaders"),
	HX_CSTRING("fragment_shaders"),
	HX_CSTRING("error_shader"),
	HX_CSTRING("programs"),
	HX_CSTRING("camera"),
	HX_CSTRING("transform"),
	HX_CSTRING("viewmatrix"),
	HX_CSTRING("projmatrix"),
	HX_CSTRING("locations"),
	HX_CSTRING("slot"),
	HX_CSTRING("uniforms"),
	HX_CSTRING("current"),
	HX_CSTRING("ztest"),
	HX_CSTRING("zfunc"),
	HX_CSTRING("zwrite"),
	HX_CSTRING("blend"),
	HX_CSTRING("queue"),
	HX_CSTRING("blendSrc"),
	HX_CSTRING("blendDst"),
	HX_CSTRING("invert"),
	HX_CSTRING("cull"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("UpdateFlags"),
	HX_CSTRING("InitializeMaterial"),
	HX_CSTRING("InitializeShader"),
	HX_CSTRING("CreateUniform"),
	HX_CSTRING("DestroyUniform"),
	HX_CSTRING("CreateCompileShader"),
	HX_CSTRING("UpdateShader"),
	HX_CSTRING("UpdateMaterial"),
	HX_CSTRING("GetAttribLocation"),
	HX_CSTRING("Bind"),
	HX_CSTRING("UseMaterial"),
	HX_CSTRING("UpdateMaterialUniforms"),
	HX_CSTRING("UploadUniforms"),
	HX_CSTRING("UploadUniform"),
	HX_CSTRING("ApplyUniform"),
	HX_CSTRING("UploadGlobalUniform"),
	HX_CSTRING("Unbind"),
	HX_CSTRING("DestroyMaterial"),
	HX_CSTRING("DestroyShader"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MaterialContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MaterialContext_obj::__mClass,"__mClass");
};

#endif

Class MaterialContext_obj::__mClass;

void MaterialContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.MaterialContext"), hx::TCanCast< MaterialContext_obj> ,sStaticFields,sMemberFields,
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

void MaterialContext_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
