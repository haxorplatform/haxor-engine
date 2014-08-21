#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_MaterialContext
#include <haxor/context/MaterialContext.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
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
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_graphics_WinGL
#include <haxor/platform/windows/graphics/WinGL.h>
#endif
namespace haxor{
namespace graphics{
namespace material{

Void Material_obj::__construct(::String p_name)
{
HX_STACK_FRAME("haxor.graphics.material.Material","new",0xec1f7429,"haxor.graphics.material.Material.new","haxor/graphics/material/Material.hx",23,0xe49118e6)
HX_STACK_THIS(this)
HX_STACK_ARG(p_name,"p_name")
{
	HX_STACK_LINE(89)
	this->grab = false;
	HX_STACK_LINE(116)
	super::__construct(p_name);
	HX_STACK_LINE(117)
	int _g = (::haxor::context::EngineContext_obj::material->mid)++;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(117)
	this->_cid_ = _g;
	HX_STACK_LINE(118)
	this->m_uniforms = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(119)
	this->queue = (int)1000;
	HX_STACK_LINE(120)
	this->zfunc = (int)515;
	HX_STACK_LINE(121)
	this->ztest = true;
	HX_STACK_LINE(122)
	this->zwrite = true;
	HX_STACK_LINE(123)
	this->blend = false;
	HX_STACK_LINE(124)
	this->blendSrc = (int)1;
	HX_STACK_LINE(125)
	this->blendDst = (int)0;
	HX_STACK_LINE(126)
	this->invert = false;
	HX_STACK_LINE(127)
	this->cull = (int)2;
	HX_STACK_LINE(128)
	this->lighting = false;
	HX_STACK_LINE(129)
	this->grab = false;
	HX_STACK_LINE(131)
	::haxor::context::EngineContext_obj::material->InitializeMaterial(hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

//Material_obj::~Material_obj() { }

Dynamic Material_obj::__CreateEmpty() { return  new Material_obj; }
hx::ObjectPtr< Material_obj > Material_obj::__new(::String p_name)
{  hx::ObjectPtr< Material_obj > result = new Material_obj();
	result->__construct(p_name);
	return result;}

Dynamic Material_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Material_obj > result = new Material_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::graphics::material::Shader Material_obj::get_shader( ){
	HX_STACK_FRAME("haxor.graphics.material.Material","get_shader",0x08828645,"haxor.graphics.material.Material.get_shader","haxor/graphics/material/Material.hx",95,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(95)
	return this->m_shader;
}


HX_DEFINE_DYNAMIC_FUNC0(Material_obj,get_shader,return )

::haxor::graphics::material::Shader Material_obj::set_shader( ::haxor::graphics::material::Shader v){
	HX_STACK_FRAME("haxor.graphics.material.Material","set_shader",0x0c0024b9,"haxor.graphics.material.Material.set_shader","haxor/graphics/material/Material.hx",97,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(98)
	if (((this->m_shader == v))){
		HX_STACK_LINE(98)
		return v;
	}
	HX_STACK_LINE(99)
	::haxor::context::EngineContext_obj::material->UpdateShader(hx::ObjectPtr<OBJ_>(this),this->m_shader,v);
	HX_STACK_LINE(100)
	this->m_shader = v;
	HX_STACK_LINE(101)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,set_shader,return )

Void Material_obj::SetBlending( int p_src,int p_dst){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetBlending",0x03abe39c,"haxor.graphics.material.Material.SetBlending","haxor/graphics/material/Material.hx",140,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_src,"p_src")
		HX_STACK_ARG(p_dst,"p_dst")
		HX_STACK_LINE(141)
		this->blendSrc = p_src;
		HX_STACK_LINE(142)
		this->blendDst = p_dst;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetBlending,(void))

Void Material_obj::SetTexture( ::String p_name,::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetTexture",0xe34b48d0,"haxor.graphics.material.Material.SetTexture","haxor/graphics/material/Material.hx",151,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_texture,"p_texture")
		HX_STACK_LINE(152)
		if (((p_texture == null()))){
			HX_STACK_LINE(152)
			this->RemoveUniform(p_name);
			HX_STACK_LINE(152)
			return null();
		}
		HX_STACK_LINE(153)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)1,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(154)
		::haxor::io::Int32Array b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(154)
		b->Set((int)0,p_texture->__slot);
		HX_STACK_LINE(155)
		u->texture = p_texture;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetTexture,(void))

Void Material_obj::SetFloat( ::String p_name,Float p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat",0xe85dee51,"haxor.graphics.material.Material.SetFloat","haxor/graphics/material/Material.hx",164,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(165)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)1,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(166)
		::haxor::io::FloatArray b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(166)
		b->Set((int)0,p_v);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat,(void))

Void Material_obj::SetFloat4( ::String p_name,Float p_x,Float p_y,Float p_z,Float p_w){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat4",0x69d298c3,"haxor.graphics.material.Material.SetFloat4","haxor/graphics/material/Material.hx",178,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(179)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)4,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(180)
		::haxor::io::FloatArray b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(180)
		b->Set((int)0,p_x);
		HX_STACK_LINE(180)
		b->Set((int)1,p_y);
		HX_STACK_LINE(180)
		b->Set((int)2,p_z);
		HX_STACK_LINE(180)
		b->Set((int)3,p_w);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Material_obj,SetFloat4,(void))

Void Material_obj::SetFloat3( ::String p_name,Float p_x,Float p_y,Float p_z){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat3",0x69d298c2,"haxor.graphics.material.Material.SetFloat3","haxor/graphics/material/Material.hx",192,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(193)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)3,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(194)
		::haxor::io::FloatArray b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(194)
		b->Set((int)0,p_x);
		HX_STACK_LINE(194)
		b->Set((int)1,p_y);
		HX_STACK_LINE(194)
		b->Set((int)2,p_z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Material_obj,SetFloat3,(void))

Void Material_obj::SetFloat2( ::String p_name,Float p_x,Float p_y){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat2",0x69d298c1,"haxor.graphics.material.Material.SetFloat2","haxor/graphics/material/Material.hx",204,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(205)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)2,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(206)
		::haxor::io::FloatArray b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(206)
		b->Set((int)0,p_x);
		HX_STACK_LINE(206)
		b->Set((int)1,p_y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Material_obj,SetFloat2,(void))

Void Material_obj::SetFloatArray( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloatArray",0xb2086988,"haxor.graphics.material.Material.SetFloatArray","haxor/graphics/material/Material.hx",214,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(214)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(214)
		::haxor::io::FloatArray b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(214)
		{
			HX_STACK_LINE(214)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(214)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(214)
			while((true)){
				HX_STACK_LINE(214)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(214)
					break;
				}
				HX_STACK_LINE(214)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(214)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloatArray,(void))

Void Material_obj::SetFloat2Array( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat2Array",0xdf63e918,"haxor.graphics.material.Material.SetFloat2Array","haxor/graphics/material/Material.hx",221,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(221)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(221)
		::haxor::io::FloatArray b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(221)
		{
			HX_STACK_LINE(221)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(221)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(221)
			while((true)){
				HX_STACK_LINE(221)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(221)
					break;
				}
				HX_STACK_LINE(221)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(221)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat2Array,(void))

Void Material_obj::SetFloat3Array( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat3Array",0x45bf4577,"haxor.graphics.material.Material.SetFloat3Array","haxor/graphics/material/Material.hx",228,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(228)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(228)
		::haxor::io::FloatArray b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(228)
		{
			HX_STACK_LINE(228)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(228)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(228)
			while((true)){
				HX_STACK_LINE(228)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(228)
					break;
				}
				HX_STACK_LINE(228)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(228)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat3Array,(void))

Void Material_obj::SetFloat4Array( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat4Array",0xac1aa1d6,"haxor.graphics.material.Material.SetFloat4Array","haxor/graphics/material/Material.hx",235,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(235)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(235)
		::haxor::io::FloatArray b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(235)
		{
			HX_STACK_LINE(235)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(235)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(235)
			while((true)){
				HX_STACK_LINE(235)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(235)
					break;
				}
				HX_STACK_LINE(235)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(235)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat4Array,(void))

Void Material_obj::SetInt( ::String p_name,int p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt",0x2bb42e64,"haxor.graphics.material.Material.SetInt","haxor/graphics/material/Material.hx",245,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(246)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)1,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(247)
		::haxor::io::Int32Array b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(247)
		b->Set((int)0,p_v);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt,(void))

Void Material_obj::SetInt4( ::String p_name,int p_x,int p_y,int p_z,int p_w){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt4",0x11f46950,"haxor.graphics.material.Material.SetInt4","haxor/graphics/material/Material.hx",259,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(260)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)4,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(261)
		::haxor::io::Int32Array b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(261)
		b->Set((int)0,p_x);
		HX_STACK_LINE(261)
		b->Set((int)1,p_y);
		HX_STACK_LINE(261)
		b->Set((int)2,p_z);
		HX_STACK_LINE(261)
		b->Set((int)3,p_w);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Material_obj,SetInt4,(void))

Void Material_obj::SetInt3( ::String p_name,int p_x,int p_y,int p_z){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt3",0x11f4694f,"haxor.graphics.material.Material.SetInt3","haxor/graphics/material/Material.hx",272,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(273)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)3,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(274)
		::haxor::io::Int32Array b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(274)
		b->Set((int)0,p_x);
		HX_STACK_LINE(274)
		b->Set((int)1,p_y);
		HX_STACK_LINE(274)
		b->Set((int)2,p_z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Material_obj,SetInt3,(void))

Void Material_obj::SetInt2( ::String p_name,int p_x,int p_y){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt2",0x11f4694e,"haxor.graphics.material.Material.SetInt2","haxor/graphics/material/Material.hx",284,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(285)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)2,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(286)
		::haxor::io::Int32Array b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(286)
		b->Set((int)0,p_x);
		HX_STACK_LINE(286)
		b->Set((int)1,p_y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Material_obj,SetInt2,(void))

Void Material_obj::SetIntArray( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetIntArray",0x06d20495,"haxor.graphics.material.Material.SetIntArray","haxor/graphics/material/Material.hx",294,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(294)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(294)
		::haxor::io::Int32Array b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(294)
		{
			HX_STACK_LINE(294)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(294)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(294)
			while((true)){
				HX_STACK_LINE(294)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(294)
					break;
				}
				HX_STACK_LINE(294)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(294)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetIntArray,(void))

Void Material_obj::SetInt2Array( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt2Array",0xbb01f96b,"haxor.graphics.material.Material.SetInt2Array","haxor/graphics/material/Material.hx",301,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(301)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(301)
		::haxor::io::Int32Array b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(301)
		{
			HX_STACK_LINE(301)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(301)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(301)
			while((true)){
				HX_STACK_LINE(301)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(301)
					break;
				}
				HX_STACK_LINE(301)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(301)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt2Array,(void))

Void Material_obj::SetInt3Array( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt3Array",0x215d55ca,"haxor.graphics.material.Material.SetInt3Array","haxor/graphics/material/Material.hx",308,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(308)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(308)
		::haxor::io::Int32Array b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(308)
		{
			HX_STACK_LINE(308)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(308)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(308)
			while((true)){
				HX_STACK_LINE(308)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(308)
					break;
				}
				HX_STACK_LINE(308)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(308)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt3Array,(void))

Void Material_obj::SetInt4Array( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt4Array",0x87b8b229,"haxor.graphics.material.Material.SetInt4Array","haxor/graphics/material/Material.hx",315,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(315)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(315)
		::haxor::io::Int32Array b = u->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(315)
		{
			HX_STACK_LINE(315)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(315)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(315)
			while((true)){
				HX_STACK_LINE(315)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(315)
					break;
				}
				HX_STACK_LINE(315)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(315)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt4Array,(void))

Void Material_obj::RemoveUniform( ::String p_name){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","RemoveUniform",0x5a868639,"haxor.graphics.material.Material.RemoveUniform","haxor/graphics/material/Material.hx",323,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_LINE(324)
		::haxor::graphics::material::MaterialUniform u = null();		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(325)
		{
			HX_STACK_LINE(325)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(325)
			int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(325)
			while((true)){
				HX_STACK_LINE(325)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(325)
					break;
				}
				HX_STACK_LINE(325)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(327)
				u = this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >();
				HX_STACK_LINE(328)
				if (((u->name == p_name))){
					HX_STACK_LINE(328)
					break;
				}
			}
		}
		HX_STACK_LINE(330)
		if (((u != null()))){
			HX_STACK_LINE(332)
			::haxor::context::EngineContext_obj::material->DestroyUniform(hx::ObjectPtr<OBJ_>(this),u);
			HX_STACK_LINE(333)
			this->m_uniforms->remove(u);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,RemoveUniform,(void))

::haxor::graphics::material::MaterialUniform Material_obj::FetchUniform( ::String p_name,bool p_is_float,int p_length,int p_offset,bool p_create){
	HX_STACK_FRAME("haxor.graphics.material.Material","FetchUniform",0x6e061751,"haxor.graphics.material.Material.FetchUniform","haxor/graphics/material/Material.hx",344,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_is_float,"p_is_float")
	HX_STACK_ARG(p_length,"p_length")
	HX_STACK_ARG(p_offset,"p_offset")
	HX_STACK_ARG(p_create,"p_create")
	HX_STACK_LINE(345)
	::haxor::graphics::material::MaterialUniform u = null();		HX_STACK_VAR(u,"u");
	HX_STACK_LINE(346)
	{
		HX_STACK_LINE(346)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(346)
		int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(346)
		while((true)){
			HX_STACK_LINE(346)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(346)
				break;
			}
			HX_STACK_LINE(346)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(348)
			u = this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >();
			HX_STACK_LINE(349)
			if (((u->name == p_name))){
				HX_STACK_LINE(351)
				if (((u->isFloat == p_is_float))){
					HX_STACK_LINE(353)
					if (((u->offset == p_offset))){
						HX_STACK_LINE(355)
						if (((u->data->m_length == p_length))){
							HX_STACK_LINE(356)
							u->__d = true;
						}
						HX_STACK_LINE(357)
						return u;
					}
				}
			}
		}
	}
	HX_STACK_LINE(362)
	if ((p_create)){
		HX_STACK_LINE(364)
		::haxor::graphics::material::MaterialUniform _g = ::haxor::graphics::material::MaterialUniform_obj::__new(p_name,p_is_float,p_length,p_offset);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(364)
		u = _g;
		HX_STACK_LINE(365)
		::haxor::context::EngineContext_obj::material->CreateUniform(hx::ObjectPtr<OBJ_>(this),u);
		HX_STACK_LINE(366)
		this->m_uniforms->push(u);
	}
	HX_STACK_LINE(368)
	return u;
}


HX_DEFINE_DYNAMIC_FUNC5(Material_obj,FetchUniform,return )

Void Material_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","OnDestroy",0xc505e604,"haxor.graphics.material.Material.OnDestroy","haxor/graphics/material/Material.hx",403,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(403)
		::haxor::context::MaterialContext _this = ::haxor::context::EngineContext_obj::material;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(403)
		int p = _this->programs->__get(this->_cid_);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(403)
		if (((this->m_shader != null()))){
			HX_STACK_LINE(403)
			::haxor::graphics::GL_obj::m_gl->DetachShader(p,_this->vertex_shaders->__get(this->m_shader->_cid_));
			HX_STACK_LINE(403)
			::haxor::graphics::GL_obj::m_gl->DetachShader(p,_this->fragment_shaders->__get(this->m_shader->_cid_));
		}
		HX_STACK_LINE(403)
		::haxor::graphics::GL_obj::m_gl->DeleteProgram(p);
	}
return null();
}



Material_obj::Material_obj()
{
}

void Material_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Material);
	HX_MARK_MEMBER_NAME(ztest,"ztest");
	HX_MARK_MEMBER_NAME(zfunc,"zfunc");
	HX_MARK_MEMBER_NAME(zwrite,"zwrite");
	HX_MARK_MEMBER_NAME(blend,"blend");
	HX_MARK_MEMBER_NAME(queue,"queue");
	HX_MARK_MEMBER_NAME(blendSrc,"blendSrc");
	HX_MARK_MEMBER_NAME(blendDst,"blendDst");
	HX_MARK_MEMBER_NAME(invert,"invert");
	HX_MARK_MEMBER_NAME(cull,"cull");
	HX_MARK_MEMBER_NAME(lighting,"lighting");
	HX_MARK_MEMBER_NAME(grab,"grab");
	HX_MARK_MEMBER_NAME(m_shader,"m_shader");
	HX_MARK_MEMBER_NAME(m_uniforms,"m_uniforms");
	::haxor::core::Resource_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Material_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(ztest,"ztest");
	HX_VISIT_MEMBER_NAME(zfunc,"zfunc");
	HX_VISIT_MEMBER_NAME(zwrite,"zwrite");
	HX_VISIT_MEMBER_NAME(blend,"blend");
	HX_VISIT_MEMBER_NAME(queue,"queue");
	HX_VISIT_MEMBER_NAME(blendSrc,"blendSrc");
	HX_VISIT_MEMBER_NAME(blendDst,"blendDst");
	HX_VISIT_MEMBER_NAME(invert,"invert");
	HX_VISIT_MEMBER_NAME(cull,"cull");
	HX_VISIT_MEMBER_NAME(lighting,"lighting");
	HX_VISIT_MEMBER_NAME(grab,"grab");
	HX_VISIT_MEMBER_NAME(m_shader,"m_shader");
	HX_VISIT_MEMBER_NAME(m_uniforms,"m_uniforms");
	::haxor::core::Resource_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Material_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"cull") ) { return cull; }
		if (HX_FIELD_EQ(inName,"grab") ) { return grab; }
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
		if (HX_FIELD_EQ(inName,"shader") ) { return get_shader(); }
		if (HX_FIELD_EQ(inName,"SetInt") ) { return SetInt_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"SetInt4") ) { return SetInt4_dyn(); }
		if (HX_FIELD_EQ(inName,"SetInt3") ) { return SetInt3_dyn(); }
		if (HX_FIELD_EQ(inName,"SetInt2") ) { return SetInt2_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"blendSrc") ) { return blendSrc; }
		if (HX_FIELD_EQ(inName,"blendDst") ) { return blendDst; }
		if (HX_FIELD_EQ(inName,"lighting") ) { return lighting; }
		if (HX_FIELD_EQ(inName,"m_shader") ) { return m_shader; }
		if (HX_FIELD_EQ(inName,"SetFloat") ) { return SetFloat_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"SetFloat4") ) { return SetFloat4_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloat3") ) { return SetFloat3_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloat2") ) { return SetFloat2_dyn(); }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_shader") ) { return get_shader_dyn(); }
		if (HX_FIELD_EQ(inName,"set_shader") ) { return set_shader_dyn(); }
		if (HX_FIELD_EQ(inName,"m_uniforms") ) { return m_uniforms; }
		if (HX_FIELD_EQ(inName,"SetTexture") ) { return SetTexture_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SetBlending") ) { return SetBlending_dyn(); }
		if (HX_FIELD_EQ(inName,"SetIntArray") ) { return SetIntArray_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"SetInt2Array") ) { return SetInt2Array_dyn(); }
		if (HX_FIELD_EQ(inName,"SetInt3Array") ) { return SetInt3Array_dyn(); }
		if (HX_FIELD_EQ(inName,"SetInt4Array") ) { return SetInt4Array_dyn(); }
		if (HX_FIELD_EQ(inName,"FetchUniform") ) { return FetchUniform_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"SetFloatArray") ) { return SetFloatArray_dyn(); }
		if (HX_FIELD_EQ(inName,"RemoveUniform") ) { return RemoveUniform_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"SetFloat2Array") ) { return SetFloat2Array_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloat3Array") ) { return SetFloat3Array_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloat4Array") ) { return SetFloat4Array_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Material_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"cull") ) { cull=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"grab") ) { grab=inValue.Cast< bool >(); return inValue; }
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
		if (HX_FIELD_EQ(inName,"shader") ) { return set_shader(inValue); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"blendSrc") ) { blendSrc=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blendDst") ) { blendDst=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lighting") ) { lighting=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_shader") ) { m_shader=inValue.Cast< ::haxor::graphics::material::Shader >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_uniforms") ) { m_uniforms=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Material_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("ztest"));
	outFields->push(HX_CSTRING("zfunc"));
	outFields->push(HX_CSTRING("zwrite"));
	outFields->push(HX_CSTRING("blend"));
	outFields->push(HX_CSTRING("queue"));
	outFields->push(HX_CSTRING("blendSrc"));
	outFields->push(HX_CSTRING("blendDst"));
	outFields->push(HX_CSTRING("invert"));
	outFields->push(HX_CSTRING("cull"));
	outFields->push(HX_CSTRING("lighting"));
	outFields->push(HX_CSTRING("grab"));
	outFields->push(HX_CSTRING("shader"));
	outFields->push(HX_CSTRING("m_shader"));
	outFields->push(HX_CSTRING("m_uniforms"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Material_obj,ztest),HX_CSTRING("ztest")},
	{hx::fsInt,(int)offsetof(Material_obj,zfunc),HX_CSTRING("zfunc")},
	{hx::fsBool,(int)offsetof(Material_obj,zwrite),HX_CSTRING("zwrite")},
	{hx::fsBool,(int)offsetof(Material_obj,blend),HX_CSTRING("blend")},
	{hx::fsInt,(int)offsetof(Material_obj,queue),HX_CSTRING("queue")},
	{hx::fsInt,(int)offsetof(Material_obj,blendSrc),HX_CSTRING("blendSrc")},
	{hx::fsInt,(int)offsetof(Material_obj,blendDst),HX_CSTRING("blendDst")},
	{hx::fsBool,(int)offsetof(Material_obj,invert),HX_CSTRING("invert")},
	{hx::fsInt,(int)offsetof(Material_obj,cull),HX_CSTRING("cull")},
	{hx::fsBool,(int)offsetof(Material_obj,lighting),HX_CSTRING("lighting")},
	{hx::fsBool,(int)offsetof(Material_obj,grab),HX_CSTRING("grab")},
	{hx::fsObject /*::haxor::graphics::material::Shader*/ ,(int)offsetof(Material_obj,m_shader),HX_CSTRING("m_shader")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Material_obj,m_uniforms),HX_CSTRING("m_uniforms")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("ztest"),
	HX_CSTRING("zfunc"),
	HX_CSTRING("zwrite"),
	HX_CSTRING("blend"),
	HX_CSTRING("queue"),
	HX_CSTRING("blendSrc"),
	HX_CSTRING("blendDst"),
	HX_CSTRING("invert"),
	HX_CSTRING("cull"),
	HX_CSTRING("lighting"),
	HX_CSTRING("grab"),
	HX_CSTRING("get_shader"),
	HX_CSTRING("set_shader"),
	HX_CSTRING("m_shader"),
	HX_CSTRING("m_uniforms"),
	HX_CSTRING("SetBlending"),
	HX_CSTRING("SetTexture"),
	HX_CSTRING("SetFloat"),
	HX_CSTRING("SetFloat4"),
	HX_CSTRING("SetFloat3"),
	HX_CSTRING("SetFloat2"),
	HX_CSTRING("SetFloatArray"),
	HX_CSTRING("SetFloat2Array"),
	HX_CSTRING("SetFloat3Array"),
	HX_CSTRING("SetFloat4Array"),
	HX_CSTRING("SetInt"),
	HX_CSTRING("SetInt4"),
	HX_CSTRING("SetInt3"),
	HX_CSTRING("SetInt2"),
	HX_CSTRING("SetIntArray"),
	HX_CSTRING("SetInt2Array"),
	HX_CSTRING("SetInt3Array"),
	HX_CSTRING("SetInt4Array"),
	HX_CSTRING("RemoveUniform"),
	HX_CSTRING("FetchUniform"),
	HX_CSTRING("OnDestroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Material_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Material_obj::__mClass,"__mClass");
};

#endif

Class Material_obj::__mClass;

void Material_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.material.Material"), hx::TCanCast< Material_obj> ,sStaticFields,sMemberFields,
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

void Material_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace material
