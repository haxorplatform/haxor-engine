#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
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
#ifndef INCLUDED_haxor_graphics_material_Shader
#include <haxor/graphics/material/Shader.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_UberShader
#include <haxor/graphics/material/UberShader.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshAttrib
#include <haxor/graphics/mesh/MeshAttrib.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GL
#include <haxor/platform/graphics/GL.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GraphicContext
#include <haxor/platform/graphics/GraphicContext.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_WinGL
#include <haxor/platform/graphics/WinGL.h>
#endif
namespace haxor{
namespace context{

Void MaterialContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.MaterialContext","new",0xcad5d8af,"haxor.context.MaterialContext.new","haxor/context/MaterialContext.hx",119,0x0e17e323)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(120)
	this->mid = (int)0;
	HX_STACK_LINE(121)
	this->sid = (int)0;
	HX_STACK_LINE(125)
	this->zfunc = (int)515;
	HX_STACK_LINE(126)
	this->ztest = true;
	HX_STACK_LINE(127)
	this->zwrite = true;
	HX_STACK_LINE(128)
	this->blend = false;
	HX_STACK_LINE(129)
	this->blendSrc = (int)1;
	HX_STACK_LINE(130)
	this->blendDst = (int)0;
	HX_STACK_LINE(131)
	this->invert = false;
	HX_STACK_LINE(132)
	this->cull = (int)2;
	HX_STACK_LINE(134)
	int max_buffers = (int)512;		HX_STACK_VAR(max_buffers,"max_buffers");
	HX_STACK_LINE(135)
	int max_programs = (int)256;		HX_STACK_VAR(max_programs,"max_programs");
	HX_STACK_LINE(137)
	this->locations = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(138)
	this->programs = Array_obj< int >::__new();
	HX_STACK_LINE(139)
	this->vertex_shaders = Array_obj< int >::__new();
	HX_STACK_LINE(140)
	this->fragment_shaders = Array_obj< int >::__new();
	HX_STACK_LINE(141)
	{
		HX_STACK_LINE(141)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(141)
		while((true)){
			HX_STACK_LINE(141)
			if ((!(((_g < max_programs))))){
				HX_STACK_LINE(141)
				break;
			}
			HX_STACK_LINE(141)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(143)
			Array< int > l = Array_obj< int >::__new();		HX_STACK_VAR(l,"l");
			HX_STACK_LINE(144)
			{
				HX_STACK_LINE(144)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(144)
				while((true)){
					HX_STACK_LINE(144)
					if ((!(((_g1 < max_buffers))))){
						HX_STACK_LINE(144)
						break;
					}
					HX_STACK_LINE(144)
					int j = (_g1)++;		HX_STACK_VAR(j,"j");
					HX_STACK_LINE(144)
					l->push((int)-1);
				}
			}
			HX_STACK_LINE(145)
			this->locations->push(l);
			HX_STACK_LINE(146)
			this->programs->push(::haxor::platform::graphics::GL_obj::_NULL);
			HX_STACK_LINE(147)
			this->vertex_shaders->push(::haxor::platform::graphics::GL_obj::_NULL);
			HX_STACK_LINE(148)
			this->fragment_shaders->push(::haxor::platform::graphics::GL_obj::_NULL);
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
		HX_STACK_FRAME("haxor.context.MaterialContext","Initialize",0x874c6501,"haxor.context.MaterialContext.Initialize","haxor/context/MaterialContext.hx",157,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_LINE(158)
		::haxor::core::Console_obj::Log(HX_CSTRING("MaterialContext> Initialize."),(int)3);
		HX_STACK_LINE(161)
		::haxor::platform::graphics::GL_obj::m_gl->DepthFunc((int)515);
		HX_STACK_LINE(162)
		::haxor::platform::graphics::GL_obj::m_gl->Enable((int)2929);
		HX_STACK_LINE(163)
		::haxor::platform::graphics::GL_obj::m_gl->DepthMask(true);
		HX_STACK_LINE(164)
		::haxor::platform::graphics::GL_obj::m_gl->Disable((int)3042);
		HX_STACK_LINE(165)
		::haxor::platform::graphics::GL_obj::m_gl->BlendFunc((int)1,(int)0);
		HX_STACK_LINE(166)
		::haxor::platform::graphics::GL_obj::m_gl->Enable((int)2884);
		HX_STACK_LINE(167)
		::haxor::platform::graphics::GL_obj::m_gl->FrontFace((int)2305);
		HX_STACK_LINE(168)
		::haxor::platform::graphics::GL_obj::m_gl->CullFace((int)1029);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MaterialContext_obj,Initialize,(void))

Void MaterialContext_obj::UpdateFlags( ::haxor::graphics::material::Material m){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","UpdateFlags",0x8ca09bad,"haxor.context.MaterialContext.UpdateFlags","haxor/context/MaterialContext.hx",178,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_LINE(190)
		if (((m->zfunc != this->zfunc))){
			HX_STACK_LINE(190)
			this->zfunc = m->zfunc;
			HX_STACK_LINE(190)
			::haxor::platform::graphics::GL_obj::m_gl->DepthFunc(this->zfunc);
		}
		HX_STACK_LINE(191)
		if (((m->ztest != this->ztest))){
			HX_STACK_LINE(191)
			this->ztest = m->ztest;
			HX_STACK_LINE(191)
			if ((this->ztest)){
				HX_STACK_LINE(191)
				::haxor::platform::graphics::GL_obj::m_gl->Enable((int)2929);
			}
			else{
				HX_STACK_LINE(191)
				::haxor::platform::graphics::GL_obj::m_gl->Disable((int)2929);
			}
		}
		HX_STACK_LINE(192)
		if (((m->zwrite != this->zwrite))){
			HX_STACK_LINE(192)
			this->zwrite = m->zwrite;
			HX_STACK_LINE(192)
			::haxor::platform::graphics::GL_obj::m_gl->DepthMask(this->zwrite);
		}
		HX_STACK_LINE(193)
		if (((m->blend != this->blend))){
			HX_STACK_LINE(193)
			this->blend = m->blend;
			HX_STACK_LINE(193)
			if ((this->blend)){
				HX_STACK_LINE(193)
				::haxor::platform::graphics::GL_obj::m_gl->Enable((int)3042);
			}
			else{
				HX_STACK_LINE(193)
				::haxor::platform::graphics::GL_obj::m_gl->Disable((int)3042);
			}
		}
		HX_STACK_LINE(194)
		bool blend_change = false;		HX_STACK_VAR(blend_change,"blend_change");
		HX_STACK_LINE(195)
		if (((m->blendSrc != this->blendSrc))){
			HX_STACK_LINE(195)
			blend_change = true;
			HX_STACK_LINE(195)
			this->blendSrc = m->blendSrc;
		}
		HX_STACK_LINE(196)
		if (((m->blendDst != this->blendDst))){
			HX_STACK_LINE(196)
			blend_change = true;
			HX_STACK_LINE(196)
			this->blendDst = m->blendDst;
		}
		HX_STACK_LINE(197)
		if ((blend_change)){
			HX_STACK_LINE(197)
			::haxor::platform::graphics::GL_obj::m_gl->BlendFunc(this->blendSrc,this->blendDst);
		}
		HX_STACK_LINE(199)
		if (((m->invert != this->invert))){
			HX_STACK_LINE(199)
			this->invert = m->invert;
			HX_STACK_LINE(199)
			::haxor::platform::graphics::GL_obj::m_gl->FrontFace((  ((this->invert)) ? int((int)2304) : int((int)2305) ));
		}
		HX_STACK_LINE(200)
		if (((m->cull != this->cull))){
			HX_STACK_LINE(202)
			this->cull = m->cull;
			HX_STACK_LINE(203)
			if (((this->cull == (int)0))){
				HX_STACK_LINE(205)
				::haxor::platform::graphics::GL_obj::m_gl->Disable((int)2884);
			}
			else{
				HX_STACK_LINE(209)
				::haxor::platform::graphics::GL_obj::m_gl->Enable((int)2884);
				HX_STACK_LINE(210)
				::haxor::platform::graphics::GL_obj::m_gl->CullFace((  (((this->cull == (int)1))) ? int((int)1028) : int((int)1029) ));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,UpdateFlags,(void))

Void MaterialContext_obj::InitializeMaterial( ::haxor::graphics::material::Material m){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","InitializeMaterial",0x8f01e6c8,"haxor.context.MaterialContext.InitializeMaterial","haxor/context/MaterialContext.hx",220,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_LINE(221)
		this->programs[m->_cid_] = ::haxor::platform::graphics::GL_obj::m_gl->CreateProgram();
		HX_STACK_LINE(222)
		::haxor::core::Console_obj::Log(((HX_CSTRING("Material> id[") + this->programs->__get(m->_cid_)) + HX_CSTRING("]")),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,InitializeMaterial,(void))

Void MaterialContext_obj::InitializeShader( ::haxor::graphics::material::Shader s){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","InitializeShader",0x7b70cf06,"haxor.context.MaterialContext.InitializeShader","haxor/context/MaterialContext.hx",230,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(232)
		if ((::Std_obj::is(s,hx::ClassOf< ::haxor::graphics::material::UberShader >()))){
			HX_STACK_LINE(232)
			return null();
		}
		HX_STACK_LINE(233)
		::String vs_err = HX_CSTRING("");		HX_STACK_VAR(vs_err,"vs_err");
		HX_STACK_LINE(234)
		::String fs_err = HX_CSTRING("");		HX_STACK_VAR(fs_err,"fs_err");
		HX_STACK_LINE(235)
		::String _g = this->CreateCompileShader(s,(int)35633,this->vertex_shaders);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(235)
		vs_err = _g;
		HX_STACK_LINE(236)
		::String _g1 = this->CreateCompileShader(s,(int)35632,this->fragment_shaders);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(236)
		fs_err = _g1;
		HX_STACK_LINE(237)
		if ((s->m_hasError)){
			HX_STACK_LINE(239)
			::String _g2 = s->get_name();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(239)
			::String _g3 = (HX_CSTRING("Shader> Compile Error @ [") + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(239)
			::String _g4 = (_g3 + HX_CSTRING("]"));		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(239)
			::haxor::core::Console_obj::LogError(_g4,null());
			HX_STACK_LINE(241)
			::haxor::core::Console_obj::Log((HX_CSTRING("[vertex]\n") + vs_err),null());
			HX_STACK_LINE(243)
			::haxor::core::Console_obj::Log((HX_CSTRING("[fragment]\n") + fs_err),null());
		}
		HX_STACK_LINE(245)
		Dynamic();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,InitializeShader,(void))

::String MaterialContext_obj::CreateCompileShader( ::haxor::graphics::material::Shader s,int t,Array< int > c){
	HX_STACK_FRAME("haxor.context.MaterialContext","CreateCompileShader",0x8fb6fa8b,"haxor.context.MaterialContext.CreateCompileShader","haxor/context/MaterialContext.hx",256,0x0e17e323)
	HX_STACK_THIS(this)
	HX_STACK_ARG(s,"s")
	HX_STACK_ARG(t,"t")
	HX_STACK_ARG(c,"c")
	HX_STACK_LINE(257)
	int id = ::haxor::platform::graphics::GL_obj::m_gl->CreateShader(t);		HX_STACK_VAR(id,"id");
	HX_STACK_LINE(258)
	::String ss;		HX_STACK_VAR(ss,"ss");
	HX_STACK_LINE(258)
	if (((t == (int)35633))){
		HX_STACK_LINE(258)
		ss = s->m_vss;
	}
	else{
		HX_STACK_LINE(258)
		ss = s->m_fss;
	}
	HX_STACK_LINE(259)
	c[s->_cid_] = id;
	HX_STACK_LINE(260)
	::haxor::platform::graphics::GL_obj::m_gl->ShaderSource(id,ss);
	HX_STACK_LINE(261)
	::haxor::platform::graphics::GL_obj::m_gl->CompileShader(id);
	HX_STACK_LINE(262)
	int _g = ::haxor::platform::graphics::GL_obj::m_gl->GetShaderParameter(id,(int)35713);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(262)
	if (((_g == (int)0))){
		HX_STACK_LINE(264)
		s->m_hasError = true;
		HX_STACK_LINE(265)
		return ::haxor::platform::graphics::GL_obj::m_gl->GetShaderInfoLog(id);
	}
	HX_STACK_LINE(267)
	return HX_CSTRING("");
}


HX_DEFINE_DYNAMIC_FUNC3(MaterialContext_obj,CreateCompileShader,return )

Void MaterialContext_obj::UpdateShader( ::haxor::graphics::material::Material m,::haxor::graphics::material::Shader s0,::haxor::graphics::material::Shader s1){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","UpdateShader",0x64eea7ff,"haxor.context.MaterialContext.UpdateShader","haxor/context/MaterialContext.hx",275,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_ARG(s0,"s0")
		HX_STACK_ARG(s1,"s1")
		HX_STACK_LINE(276)
		int p = this->programs->__get(m->_cid_);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(277)
		int vs_id;		HX_STACK_VAR(vs_id,"vs_id");
		HX_STACK_LINE(278)
		int fs_id;		HX_STACK_VAR(fs_id,"fs_id");
		HX_STACK_LINE(280)
		if (((s0 != null()))){
			HX_STACK_LINE(282)
			vs_id = this->vertex_shaders->__get(s0->_cid_);
			HX_STACK_LINE(283)
			fs_id = this->fragment_shaders->__get(s0->_cid_);
			HX_STACK_LINE(284)
			::haxor::platform::graphics::GL_obj::m_gl->DetachShader(p,vs_id);
			HX_STACK_LINE(285)
			::haxor::platform::graphics::GL_obj::m_gl->DetachShader(p,fs_id);
		}
		HX_STACK_LINE(290)
		if (((s1 != null()))){
			HX_STACK_LINE(292)
			vs_id = this->vertex_shaders->__get(s1->_cid_);
			HX_STACK_LINE(293)
			fs_id = this->fragment_shaders->__get(s1->_cid_);
			HX_STACK_LINE(294)
			::haxor::platform::graphics::GL_obj::m_gl->AttachShader(p,vs_id);
			HX_STACK_LINE(295)
			::haxor::platform::graphics::GL_obj::m_gl->AttachShader(p,fs_id);
			HX_STACK_LINE(297)
			Array< ::String > al = ::haxor::context::EngineContext_obj::mesh->attribs;		HX_STACK_VAR(al,"al");
			HX_STACK_LINE(298)
			{
				HX_STACK_LINE(298)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(298)
				int _g = al->length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(298)
				while((true)){
					HX_STACK_LINE(298)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(298)
						break;
					}
					HX_STACK_LINE(298)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(298)
					::haxor::platform::graphics::GL_obj::m_gl->BindAttribLocation(p,i,al->__get(i));
				}
			}
			HX_STACK_LINE(299)
			::haxor::platform::graphics::GL_obj::m_gl->LinkProgram(p);
			HX_STACK_LINE(301)
			int _g = ::haxor::platform::graphics::GL_obj::m_gl->GetProgramParameter(p,(int)35714);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(301)
			if (((_g == (int)0))){
				HX_STACK_LINE(303)
				::String _g1 = m->get_name();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(303)
				::String _g2 = (HX_CSTRING("Material> [") + _g1);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(303)
				::String _g3 = (_g2 + HX_CSTRING("] Link Error @ ["));		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(303)
				::String _g4 = s1->get_name();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(303)
				::String _g5 = (_g3 + _g4);		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(303)
				::String _g6 = (_g5 + HX_CSTRING("]"));		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(303)
				::haxor::core::Console_obj::LogError(_g6,null());
			}
			HX_STACK_LINE(309)
			{
				HX_STACK_LINE(309)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(309)
				int _g2 = this->locations->__get(m->_cid_).StaticCast< Array< int > >()->length;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(309)
				while((true)){
					HX_STACK_LINE(309)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(309)
						break;
					}
					HX_STACK_LINE(309)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(309)
					this->locations->__get(m->_cid_).StaticCast< Array< int > >()[i] = (int)-1;
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(MaterialContext_obj,UpdateShader,(void))

Void MaterialContext_obj::UpdateMaterial( ::haxor::graphics::material::Material m){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","UpdateMaterial",0x3662b001,"haxor.context.MaterialContext.UpdateMaterial","haxor/context/MaterialContext.hx",319,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,UpdateMaterial,(void))

int MaterialContext_obj::GetAttribLocation( ::haxor::graphics::mesh::MeshAttrib a){
	HX_STACK_FRAME("haxor.context.MaterialContext","GetAttribLocation",0x3f3c2f44,"haxor.context.MaterialContext.GetAttribLocation","haxor/context/MaterialContext.hx",328,0x0e17e323)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_LINE(329)
	if (((this->current == null()))){
		HX_STACK_LINE(329)
		return (int)-1;
	}
	HX_STACK_LINE(330)
	int p = this->programs->__get(this->current->_cid_);		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(331)
	int loc = this->locations->__get(this->current->_cid_).StaticCast< Array< int > >()->__get(a->_cid_);		HX_STACK_VAR(loc,"loc");
	HX_STACK_LINE(332)
	if (((loc == (int)-1))){
		HX_STACK_LINE(334)
		int _g = ::haxor::platform::graphics::GL_obj::m_gl->GetAttribLocation(p,a->m_name);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(334)
		loc = _g;
		HX_STACK_LINE(335)
		if (((loc < (int)0))){
			HX_STACK_LINE(335)
			this->locations->__get(this->current->_cid_).StaticCast< Array< int > >()[a->_cid_] = (int)-2;
		}
	}
	HX_STACK_LINE(337)
	return loc;
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,GetAttribLocation,return )

Void MaterialContext_obj::Bind( ::haxor::graphics::material::Material m){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","Bind",0x93355eae,"haxor.context.MaterialContext.Bind","haxor/context/MaterialContext.hx",346,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_LINE(346)
		if (((m != this->current))){
			HX_STACK_LINE(349)
			this->current = m;
			HX_STACK_LINE(350)
			if (((m != null()))){
				HX_STACK_LINE(352)
				this->UpdateFlags(m);
				HX_STACK_LINE(353)
				::haxor::platform::graphics::GL_obj::m_gl->UseProgram(this->programs->__get(m->_cid_));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,Bind,(void))

Void MaterialContext_obj::Unbind( ){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","Unbind",0x442b43c7,"haxor.context.MaterialContext.Unbind","haxor/context/MaterialContext.hx",363,0x0e17e323)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MaterialContext_obj,Unbind,(void))

Void MaterialContext_obj::DestroyMaterial( ::haxor::graphics::material::Material m){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","DestroyMaterial",0xd30a9a70,"haxor.context.MaterialContext.DestroyMaterial","haxor/context/MaterialContext.hx",372,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(m,"m")
		HX_STACK_LINE(373)
		int p = this->programs->__get(m->_cid_);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(374)
		if (((m->m_shader != null()))){
			HX_STACK_LINE(376)
			::haxor::platform::graphics::GL_obj::m_gl->DetachShader(p,this->vertex_shaders->__get(m->m_shader->_cid_));
			HX_STACK_LINE(377)
			::haxor::platform::graphics::GL_obj::m_gl->DetachShader(p,this->fragment_shaders->__get(m->m_shader->_cid_));
		}
		HX_STACK_LINE(379)
		::haxor::platform::graphics::GL_obj::m_gl->DeleteProgram(p);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialContext_obj,DestroyMaterial,(void))

Void MaterialContext_obj::DestroyShader( ::haxor::graphics::material::Shader s){
{
		HX_STACK_FRAME("haxor.context.MaterialContext","DestroyShader",0xac09c8ae,"haxor.context.MaterialContext.DestroyShader","haxor/context/MaterialContext.hx",387,0x0e17e323)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(388)
		::haxor::platform::graphics::GL_obj::m_gl->DeleteShader(this->vertex_shaders->__get(s->_cid_));
		HX_STACK_LINE(389)
		::haxor::platform::graphics::GL_obj::m_gl->DeleteShader(this->fragment_shaders->__get(s->_cid_));
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
	HX_MARK_MEMBER_NAME(mid,"mid");
	HX_MARK_MEMBER_NAME(sid,"sid");
	HX_MARK_MEMBER_NAME(vertex_shaders,"vertex_shaders");
	HX_MARK_MEMBER_NAME(fragment_shaders,"fragment_shaders");
	HX_MARK_MEMBER_NAME(error_shader,"error_shader");
	HX_MARK_MEMBER_NAME(programs,"programs");
	HX_MARK_MEMBER_NAME(locations,"locations");
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
	HX_VISIT_MEMBER_NAME(mid,"mid");
	HX_VISIT_MEMBER_NAME(sid,"sid");
	HX_VISIT_MEMBER_NAME(vertex_shaders,"vertex_shaders");
	HX_VISIT_MEMBER_NAME(fragment_shaders,"fragment_shaders");
	HX_VISIT_MEMBER_NAME(error_shader,"error_shader");
	HX_VISIT_MEMBER_NAME(programs,"programs");
	HX_VISIT_MEMBER_NAME(locations,"locations");
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
		break;
	case 4:
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
		if (HX_FIELD_EQ(inName,"zwrite") ) { return zwrite; }
		if (HX_FIELD_EQ(inName,"invert") ) { return invert; }
		if (HX_FIELD_EQ(inName,"Unbind") ) { return Unbind_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { return current; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"programs") ) { return programs; }
		if (HX_FIELD_EQ(inName,"blendSrc") ) { return blendSrc; }
		if (HX_FIELD_EQ(inName,"blendDst") ) { return blendDst; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"locations") ) { return locations; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"UpdateFlags") ) { return UpdateFlags_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"error_shader") ) { return error_shader; }
		if (HX_FIELD_EQ(inName,"UpdateShader") ) { return UpdateShader_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"DestroyShader") ) { return DestroyShader_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"vertex_shaders") ) { return vertex_shaders; }
		if (HX_FIELD_EQ(inName,"UpdateMaterial") ) { return UpdateMaterial_dyn(); }
		break;
	case 15:
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
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MaterialContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"mid") ) { mid=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sid") ) { sid=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"cull") ) { cull=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"ztest") ) { ztest=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"zfunc") ) { zfunc=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blend") ) { blend=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"queue") ) { queue=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"zwrite") ) { zwrite=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"invert") ) { invert=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"current") ) { current=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"programs") ) { programs=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blendSrc") ) { blendSrc=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blendDst") ) { blendDst=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"locations") ) { locations=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"error_shader") ) { error_shader=inValue.Cast< ::haxor::graphics::material::Shader >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"vertex_shaders") ) { vertex_shaders=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"fragment_shaders") ) { fragment_shaders=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MaterialContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mid"));
	outFields->push(HX_CSTRING("sid"));
	outFields->push(HX_CSTRING("vertex_shaders"));
	outFields->push(HX_CSTRING("fragment_shaders"));
	outFields->push(HX_CSTRING("error_shader"));
	outFields->push(HX_CSTRING("programs"));
	outFields->push(HX_CSTRING("locations"));
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
	{hx::fsInt,(int)offsetof(MaterialContext_obj,mid),HX_CSTRING("mid")},
	{hx::fsInt,(int)offsetof(MaterialContext_obj,sid),HX_CSTRING("sid")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(MaterialContext_obj,vertex_shaders),HX_CSTRING("vertex_shaders")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(MaterialContext_obj,fragment_shaders),HX_CSTRING("fragment_shaders")},
	{hx::fsObject /*::haxor::graphics::material::Shader*/ ,(int)offsetof(MaterialContext_obj,error_shader),HX_CSTRING("error_shader")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(MaterialContext_obj,programs),HX_CSTRING("programs")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(MaterialContext_obj,locations),HX_CSTRING("locations")},
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
	HX_CSTRING("mid"),
	HX_CSTRING("sid"),
	HX_CSTRING("vertex_shaders"),
	HX_CSTRING("fragment_shaders"),
	HX_CSTRING("error_shader"),
	HX_CSTRING("programs"),
	HX_CSTRING("locations"),
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
	HX_CSTRING("CreateCompileShader"),
	HX_CSTRING("UpdateShader"),
	HX_CSTRING("UpdateMaterial"),
	HX_CSTRING("GetAttribLocation"),
	HX_CSTRING("Bind"),
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
