#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_MaterialContext
#include <haxor/context/MaterialContext.h>
#endif
#ifndef INCLUDED_haxor_context_ShaderContext
#include <haxor/context/ShaderContext.h>
#endif
#ifndef INCLUDED_haxor_context_UID
#include <haxor/context/UID.h>
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
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Vector2
#include <haxor/math/Vector2.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_math_Vector4
#include <haxor/math/Vector4.h>
#endif
namespace haxor{
namespace graphics{
namespace material{

Void Material_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.graphics.material.Material","new",0xec1f7429,"haxor.graphics.material.Material.new","haxor/graphics/material/Material.hx",29,0xe49118e6)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(164)
	this->grab = false;
	HX_STACK_LINE(191)
	super::__construct(p_name);
	HX_STACK_LINE(192)
	int _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(192)
	{
		HX_STACK_LINE(192)
		::haxor::context::UID _this = ::haxor::context::EngineContext_obj::material->mid;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(192)
		if (((_this->m_cache->length <= (int)0))){
			HX_STACK_LINE(192)
			_g = (_this->m_id)++;
		}
		else{
			HX_STACK_LINE(192)
			_g = _this->m_cache->shift();
		}
	}
	HX_STACK_LINE(192)
	this->__cid = _g;
	HX_STACK_LINE(193)
	this->m_uniforms = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(194)
	this->queue = (int)1000;
	HX_STACK_LINE(195)
	this->zfunc = (int)515;
	HX_STACK_LINE(196)
	this->ztest = true;
	HX_STACK_LINE(197)
	this->zwrite = true;
	HX_STACK_LINE(198)
	this->blend = false;
	HX_STACK_LINE(199)
	this->blendSrc = (int)1;
	HX_STACK_LINE(200)
	this->blendDst = (int)0;
	HX_STACK_LINE(201)
	this->invert = false;
	HX_STACK_LINE(202)
	this->cull = (int)2;
	HX_STACK_LINE(203)
	this->lighting = false;
	HX_STACK_LINE(204)
	this->grab = false;
	HX_STACK_LINE(205)
	::haxor::context::EngineContext_obj::material->InitializeMaterial(hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

//Material_obj::~Material_obj() { }

Dynamic Material_obj::__CreateEmpty() { return  new Material_obj; }
hx::ObjectPtr< Material_obj > Material_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< Material_obj > result = new Material_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic Material_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Material_obj > result = new Material_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::graphics::material::Shader Material_obj::get_shader( ){
	HX_STACK_FRAME("haxor.graphics.material.Material","get_shader",0x08828645,"haxor.graphics.material.Material.get_shader","haxor/graphics/material/Material.hx",170,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(170)
	return this->m_shader;
}


HX_DEFINE_DYNAMIC_FUNC0(Material_obj,get_shader,return )

::haxor::graphics::material::Shader Material_obj::set_shader( ::haxor::graphics::material::Shader v){
	HX_STACK_FRAME("haxor.graphics.material.Material","set_shader",0x0c0024b9,"haxor.graphics.material.Material.set_shader","haxor/graphics/material/Material.hx",172,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(173)
	if (((this->m_shader == v))){
		HX_STACK_LINE(173)
		return v;
	}
	HX_STACK_LINE(174)
	::haxor::context::EngineContext_obj::material->UpdateShader(hx::ObjectPtr<OBJ_>(this),this->m_shader,v);
	HX_STACK_LINE(175)
	this->m_shader = v;
	HX_STACK_LINE(176)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,set_shader,return )

Void Material_obj::SetBlending( int p_src,int p_dst){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetBlending",0x03abe39c,"haxor.graphics.material.Material.SetBlending","haxor/graphics/material/Material.hx",214,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_src,"p_src")
		HX_STACK_ARG(p_dst,"p_dst")
		HX_STACK_LINE(215)
		this->blendSrc = p_src;
		HX_STACK_LINE(216)
		this->blendDst = p_dst;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetBlending,(void))

Void Material_obj::SetTexture( ::String p_name,::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetTexture",0xe34b48d0,"haxor.graphics.material.Material.SetTexture","haxor/graphics/material/Material.hx",225,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_texture,"p_texture")
		HX_STACK_LINE(226)
		if (((p_texture == null()))){
			HX_STACK_LINE(226)
			this->RemoveUniform(p_name);
			HX_STACK_LINE(226)
			return null();
		}
		HX_STACK_LINE(227)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)1,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(228)
		if (((u->texture != null()))){
			HX_STACK_LINE(228)
			u->texture->__slot = (int)-1;
		}
		HX_STACK_LINE(229)
		if ((u->exists)){
			HX_STACK_LINE(229)
			u->SetTexture(p_texture);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetTexture,(void))

Void Material_obj::SetMatrix4( ::String p_name,::haxor::math::Matrix4 p_matrix4,hx::Null< bool >  __o_p_transpose){
bool p_transpose = __o_p_transpose.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","SetMatrix4",0xd7d1c2c8,"haxor.graphics.material.Material.SetMatrix4","haxor/graphics/material/Material.hx",238,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_matrix4,"p_matrix4")
	HX_STACK_ARG(p_transpose,"p_transpose")
{
		HX_STACK_LINE(239)
		if (((p_matrix4 == null()))){
			HX_STACK_LINE(239)
			this->RemoveUniform(p_name);
			HX_STACK_LINE(239)
			return null();
		}
		HX_STACK_LINE(240)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)16,(int)16,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(241)
		if ((u->exists)){
			HX_STACK_LINE(241)
			u->SetMatrix4(p_matrix4,p_transpose);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Material_obj,SetMatrix4,(void))

Void Material_obj::SetVector2( ::String p_name,::haxor::math::Vector2 p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetVector2",0x1f077a04,"haxor.graphics.material.Material.SetVector2","haxor/graphics/material/Material.hx",249,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(249)
		this->SetFloat2(p_name,p_v->x,p_v->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetVector2,(void))

Void Material_obj::SetVector3( ::String p_name,::haxor::math::Vector3 p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetVector3",0x1f077a05,"haxor.graphics.material.Material.SetVector3","haxor/graphics/material/Material.hx",256,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(256)
		this->SetFloat3(p_name,p_v->x,p_v->y,p_v->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetVector3,(void))

Void Material_obj::SetVector4( ::String p_name,::haxor::math::Vector4 p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetVector4",0x1f077a06,"haxor.graphics.material.Material.SetVector4","haxor/graphics/material/Material.hx",263,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(263)
		this->SetFloat4(p_name,p_v->x,p_v->y,p_v->z,p_v->w);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetVector4,(void))

Void Material_obj::SetColor( ::String p_name,::haxor::math::Color p_color){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetColor",0x30239a18,"haxor.graphics.material.Material.SetColor","haxor/graphics/material/Material.hx",270,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_LINE(270)
		this->SetFloat4(p_name,p_color->r,p_color->g,p_color->b,p_color->a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetColor,(void))

Void Material_obj::SetFloat( ::String p_name,Float p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat",0xe85dee51,"haxor.graphics.material.Material.SetFloat","haxor/graphics/material/Material.hx",277,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(277)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)1,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(277)
		if ((u->exists)){
			HX_STACK_LINE(277)
			u->SetFloat(p_v);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat,(void))

Void Material_obj::SetFloat2( ::String p_name,Float p_x,Float p_y){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat2",0x69d298c1,"haxor.graphics.material.Material.SetFloat2","haxor/graphics/material/Material.hx",285,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(285)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)2,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(285)
		if ((u->exists)){
			HX_STACK_LINE(285)
			u->SetFloat2(p_x,p_y);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Material_obj,SetFloat2,(void))

Void Material_obj::SetFloat3( ::String p_name,Float p_x,Float p_y,Float p_z){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat3",0x69d298c2,"haxor.graphics.material.Material.SetFloat3","haxor/graphics/material/Material.hx",295,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(295)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)3,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(295)
		if ((u->exists)){
			HX_STACK_LINE(295)
			u->SetFloat3(p_x,p_y,p_z);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Material_obj,SetFloat3,(void))

Void Material_obj::SetFloat4( ::String p_name,Float p_x,Float p_y,Float p_z,Float p_w){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat4",0x69d298c3,"haxor.graphics.material.Material.SetFloat4","haxor/graphics/material/Material.hx",305,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(305)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)4,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(305)
		if ((u->exists)){
			HX_STACK_LINE(305)
			u->SetFloat4(p_x,p_y,p_z,p_w);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Material_obj,SetFloat4,(void))

Void Material_obj::SetFloatArray( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloatArray",0xb2086988,"haxor.graphics.material.Material.SetFloatArray","haxor/graphics/material/Material.hx",312,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(312)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(312)
		if ((u->exists)){
			HX_STACK_LINE(312)
			u->SetFloatArray(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloatArray,(void))

Void Material_obj::SetFloat2Array( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat2Array",0xdf63e918,"haxor.graphics.material.Material.SetFloat2Array","haxor/graphics/material/Material.hx",319,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(319)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(319)
		if ((u->exists)){
			HX_STACK_LINE(319)
			u->SetFloat2Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat2Array,(void))

Void Material_obj::SetFloat3Array( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat3Array",0x45bf4577,"haxor.graphics.material.Material.SetFloat3Array","haxor/graphics/material/Material.hx",326,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(326)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(326)
		if ((u->exists)){
			HX_STACK_LINE(326)
			u->SetFloat3Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat3Array,(void))

Void Material_obj::SetFloat4Array( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat4Array",0xac1aa1d6,"haxor.graphics.material.Material.SetFloat4Array","haxor/graphics/material/Material.hx",333,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(333)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(333)
		if ((u->exists)){
			HX_STACK_LINE(333)
			u->SetFloat4Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat4Array,(void))

Void Material_obj::SetInt( ::String p_name,int p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt",0x2bb42e64,"haxor.graphics.material.Material.SetInt","haxor/graphics/material/Material.hx",340,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(340)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)1,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(340)
		if ((u->exists)){
			HX_STACK_LINE(340)
			u->SetInt(p_v);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt,(void))

Void Material_obj::SetInt2( ::String p_name,int p_x,int p_y){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt2",0x11f4694e,"haxor.graphics.material.Material.SetInt2","haxor/graphics/material/Material.hx",348,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(348)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)2,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(348)
		if ((u->exists)){
			HX_STACK_LINE(348)
			u->SetInt2(p_x,p_y);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Material_obj,SetInt2,(void))

Void Material_obj::SetInt3( ::String p_name,int p_x,int p_y,int p_z){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt3",0x11f4694f,"haxor.graphics.material.Material.SetInt3","haxor/graphics/material/Material.hx",357,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(357)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)3,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(357)
		if ((u->exists)){
			HX_STACK_LINE(357)
			u->SetInt3(p_x,p_y,p_z);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Material_obj,SetInt3,(void))

Void Material_obj::SetInt4( ::String p_name,int p_x,int p_y,int p_z,int p_w){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt4",0x11f46950,"haxor.graphics.material.Material.SetInt4","haxor/graphics/material/Material.hx",367,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(367)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)4,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(367)
		if ((u->exists)){
			HX_STACK_LINE(367)
			u->SetInt4(p_x,p_y,p_z,p_w);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Material_obj,SetInt4,(void))

Void Material_obj::SetIntArray( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetIntArray",0x06d20495,"haxor.graphics.material.Material.SetIntArray","haxor/graphics/material/Material.hx",374,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(374)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(374)
		if ((u->exists)){
			HX_STACK_LINE(374)
			u->SetIntArray(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetIntArray,(void))

Void Material_obj::SetInt2Array( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt2Array",0xbb01f96b,"haxor.graphics.material.Material.SetInt2Array","haxor/graphics/material/Material.hx",381,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(381)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(381)
		if ((u->exists)){
			HX_STACK_LINE(381)
			u->SetInt2Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt2Array,(void))

Void Material_obj::SetInt3Array( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt3Array",0x215d55ca,"haxor.graphics.material.Material.SetInt3Array","haxor/graphics/material/Material.hx",388,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(388)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(388)
		if ((u->exists)){
			HX_STACK_LINE(388)
			u->SetInt3Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt3Array,(void))

Void Material_obj::SetInt4Array( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt4Array",0x87b8b229,"haxor.graphics.material.Material.SetInt4Array","haxor/graphics/material/Material.hx",395,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(395)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(395)
		if ((u->exists)){
			HX_STACK_LINE(395)
			u->SetInt4Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt4Array,(void))

::haxor::graphics::material::MaterialUniform Material_obj::GetUniform( ::String p_name){
	HX_STACK_FRAME("haxor.graphics.material.Material","GetUniform",0xf65122b5,"haxor.graphics.material.Material.GetUniform","haxor/graphics/material/Material.hx",403,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(404)
	{
		HX_STACK_LINE(404)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(404)
		int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(404)
		while((true)){
			HX_STACK_LINE(404)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(404)
				break;
			}
			HX_STACK_LINE(404)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(404)
			if (((this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >()->name == p_name))){
				HX_STACK_LINE(404)
				return this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >();
			}
		}
	}
	HX_STACK_LINE(405)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,GetUniform,return )

bool Material_obj::HasUniform( ::String p_name,hx::Null< bool >  __o_p_check_shader){
bool p_check_shader = __o_p_check_shader.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","HasUniform",0x31a38471,"haxor.graphics.material.Material.HasUniform","haxor/graphics/material/Material.hx",415,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_check_shader,"p_check_shader")
{
		HX_STACK_LINE(416)
		{
			HX_STACK_LINE(416)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(416)
			int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(416)
			while((true)){
				HX_STACK_LINE(416)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(416)
					break;
				}
				HX_STACK_LINE(416)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(418)
				if (((this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >()->name == p_name))){
					HX_STACK_LINE(420)
					if ((p_check_shader)){
						HX_STACK_LINE(420)
						return this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >()->exists;
					}
					HX_STACK_LINE(421)
					return true;
				}
			}
		}
		HX_STACK_LINE(424)
		return false;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,HasUniform,return )

Void Material_obj::RemoveUniform( ::String p_name){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","RemoveUniform",0x5a868639,"haxor.graphics.material.Material.RemoveUniform","haxor/graphics/material/Material.hx",432,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_LINE(433)
		::haxor::graphics::material::MaterialUniform u = null();		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(434)
		{
			HX_STACK_LINE(434)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(434)
			int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(434)
			while((true)){
				HX_STACK_LINE(434)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(434)
					break;
				}
				HX_STACK_LINE(434)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(436)
				u = this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >();
				HX_STACK_LINE(437)
				if (((u->name == p_name))){
					HX_STACK_LINE(437)
					break;
				}
			}
		}
		HX_STACK_LINE(439)
		if (((u != null()))){
			HX_STACK_LINE(441)
			if (((u->texture != null()))){
				HX_STACK_LINE(441)
				u->texture->__slot = (int)-1;
			}
			HX_STACK_LINE(442)
			::haxor::context::EngineContext_obj::material->DestroyUniform(hx::ObjectPtr<OBJ_>(this),u);
			HX_STACK_LINE(443)
			this->m_uniforms->remove(u);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,RemoveUniform,(void))

::haxor::graphics::material::MaterialUniform Material_obj::FetchUniform( ::String p_name,bool p_is_float,int p_length,int p_offset,bool p_create){
	HX_STACK_FRAME("haxor.graphics.material.Material","FetchUniform",0x6e061751,"haxor.graphics.material.Material.FetchUniform","haxor/graphics/material/Material.hx",454,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_is_float,"p_is_float")
	HX_STACK_ARG(p_length,"p_length")
	HX_STACK_ARG(p_offset,"p_offset")
	HX_STACK_ARG(p_create,"p_create")
	HX_STACK_LINE(455)
	::haxor::graphics::material::MaterialUniform u = null();		HX_STACK_VAR(u,"u");
	HX_STACK_LINE(456)
	{
		HX_STACK_LINE(456)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(456)
		int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(456)
		while((true)){
			HX_STACK_LINE(456)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(456)
				break;
			}
			HX_STACK_LINE(456)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(458)
			u = this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >();
			HX_STACK_LINE(459)
			if (((u->name == p_name))){
				HX_STACK_LINE(461)
				if (((u->isFloat == p_is_float))){
					HX_STACK_LINE(463)
					if (((u->offset == p_offset))){
						HX_STACK_LINE(465)
						if (((u->data->m_length == p_length))){
							HX_STACK_LINE(466)
							return u;
						}
					}
				}
				HX_STACK_LINE(470)
				::haxor::context::EngineContext_obj::material->DestroyUniform(hx::ObjectPtr<OBJ_>(this),u);
				HX_STACK_LINE(471)
				this->m_uniforms->remove(u);
				HX_STACK_LINE(472)
				break;
			}
		}
	}
	HX_STACK_LINE(475)
	if ((p_create)){
		HX_STACK_LINE(477)
		::haxor::graphics::material::MaterialUniform _g = ::haxor::graphics::material::MaterialUniform_obj::__new(p_name,p_is_float,p_length,p_offset);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(477)
		u = _g;
		HX_STACK_LINE(478)
		::haxor::context::EngineContext_obj::material->CreateUniform(hx::ObjectPtr<OBJ_>(this),u);
		HX_STACK_LINE(479)
		this->m_uniforms->push(u);
	}
	HX_STACK_LINE(481)
	return u;
}


HX_DEFINE_DYNAMIC_FUNC5(Material_obj,FetchUniform,return )

Dynamic Material_obj::Clone( ){
	HX_STACK_FRAME("haxor.graphics.material.Material","Clone",0x0c636b46,"haxor.graphics.material.Material.Clone","haxor/graphics/material/Material.hx",490,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(491)
	::haxor::graphics::material::Material m = ::haxor::graphics::material::Material_obj::__new(null());		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(492)
	::String _g = this->get_name();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(492)
	::String _g1 = (_g + HX_CSTRING("Copy"));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(492)
	m->set_name(_g1);
	HX_STACK_LINE(493)
	m->set_shader(this->m_shader);
	HX_STACK_LINE(494)
	m->queue = this->queue;
	HX_STACK_LINE(495)
	m->zfunc = this->zfunc;
	HX_STACK_LINE(496)
	m->ztest = this->ztest;
	HX_STACK_LINE(497)
	m->zwrite = this->zwrite;
	HX_STACK_LINE(498)
	m->blend = this->blend;
	HX_STACK_LINE(499)
	m->blendSrc = this->blendSrc;
	HX_STACK_LINE(500)
	m->blendDst = this->blendDst;
	HX_STACK_LINE(501)
	m->invert = this->invert;
	HX_STACK_LINE(502)
	m->cull = this->cull;
	HX_STACK_LINE(503)
	m->lighting = this->lighting;
	HX_STACK_LINE(504)
	m->grab = this->grab;
	HX_STACK_LINE(505)
	Array< ::Dynamic > ul = this->m_uniforms;		HX_STACK_VAR(ul,"ul");
	HX_STACK_LINE(506)
	{
		HX_STACK_LINE(506)
		int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(506)
		int _g2 = ul->length;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(506)
		while((true)){
			HX_STACK_LINE(506)
			if ((!(((_g11 < _g2))))){
				HX_STACK_LINE(506)
				break;
			}
			HX_STACK_LINE(506)
			int i = (_g11)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(508)
			::haxor::graphics::material::MaterialUniform u = ul->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >();		HX_STACK_VAR(u,"u");
			HX_STACK_LINE(509)
			if ((u->isFloat)){
				HX_STACK_LINE(509)
				this->SetUniformFloat(u);
			}
			else{
				HX_STACK_LINE(509)
				this->SetUniformInt(u);
			}
		}
	}
	HX_STACK_LINE(511)
	return m;
}


Void Material_obj::SetUniformFloat( ::haxor::graphics::material::MaterialUniform u){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetUniformFloat",0x967b9fb3,"haxor.graphics.material.Material.SetUniformFloat","haxor/graphics/material/Material.hx",516,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(u,"u")
		HX_STACK_LINE(517)
		::haxor::io::FloatArray d = u->data;		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(518)
		bool is_array = (d->m_length > u->offset);		HX_STACK_VAR(is_array,"is_array");
		HX_STACK_LINE(519)
		Array< Float > l = null();		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(520)
		if ((is_array)){
			HX_STACK_LINE(522)
			l = Array_obj< Float >::__new();
			HX_STACK_LINE(523)
			{
				HX_STACK_LINE(523)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(523)
				int _g = d->m_length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(523)
				while((true)){
					HX_STACK_LINE(523)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(523)
						break;
					}
					HX_STACK_LINE(523)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(523)
					Float _g2 = d->Get(i);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(523)
					l->push(_g2);
				}
			}
		}
		HX_STACK_LINE(526)
		{
			HX_STACK_LINE(526)
			int _g = u->offset;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(526)
			switch( (int)(_g)){
				case (int)1: {
					HX_STACK_LINE(528)
					if ((is_array)){
						HX_STACK_LINE(528)
						this->SetFloatArray(u->name,l);
					}
					else{
						HX_STACK_LINE(528)
						Float _g1 = d->Get((int)0);		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(528)
						this->SetFloat(u->name,_g1);
					}
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(529)
					if ((is_array)){
						HX_STACK_LINE(529)
						this->SetFloat2Array(u->name,l);
					}
					else{
						HX_STACK_LINE(529)
						Float _g2 = d->Get((int)0);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(529)
						Float _g3 = d->Get((int)1);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(529)
						this->SetFloat2(u->name,_g2,_g3);
					}
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(530)
					if ((is_array)){
						HX_STACK_LINE(530)
						this->SetFloat3Array(u->name,l);
					}
					else{
						HX_STACK_LINE(530)
						Float _g4 = d->Get((int)0);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(530)
						Float _g5 = d->Get((int)1);		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(530)
						Float _g6 = d->Get((int)2);		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(530)
						this->SetFloat3(u->name,_g4,_g5,_g6);
					}
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(531)
					if ((is_array)){
						HX_STACK_LINE(531)
						this->SetFloat4Array(u->name,l);
					}
					else{
						HX_STACK_LINE(531)
						Float _g7 = d->Get((int)0);		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(531)
						Float _g8 = d->Get((int)1);		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(531)
						Float _g9 = d->Get((int)2);		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(531)
						Float _g10 = d->Get((int)3);		HX_STACK_VAR(_g10,"_g10");
						HX_STACK_LINE(531)
						this->SetFloat4(u->name,_g7,_g8,_g9,_g10);
					}
				}
				;break;
				case (int)16: {
					HX_STACK_LINE(533)
					::haxor::math::Matrix4 mat;		HX_STACK_VAR(mat,"mat");
					HX_STACK_LINE(533)
					{
						HX_STACK_LINE(533)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(533)
						int _g11 = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g11,"_g11");
						HX_STACK_LINE(533)
						mat = _this->m_m4->__get(_g11).StaticCast< ::haxor::math::Matrix4 >();
					}
					HX_STACK_LINE(534)
					{
						HX_STACK_LINE(534)
						int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(534)
						while((true)){
							HX_STACK_LINE(534)
							if ((!(((_g1 < (int)16))))){
								HX_STACK_LINE(534)
								break;
							}
							HX_STACK_LINE(534)
							int i = (_g1)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(534)
							Float _g12 = d->Get(i);		HX_STACK_VAR(_g12,"_g12");
							HX_STACK_LINE(534)
							mat->SetIndex(i,_g12);
						}
					}
					HX_STACK_LINE(535)
					if ((u->transposed)){
						HX_STACK_LINE(535)
						mat->Transpose();
					}
					HX_STACK_LINE(536)
					this->SetMatrix4(u->name,mat,u->transposed);
				}
				;break;
				default: {
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,SetUniformFloat,(void))

Void Material_obj::SetUniformInt( ::haxor::graphics::material::MaterialUniform u){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetUniformInt",0x48716346,"haxor.graphics.material.Material.SetUniformInt","haxor/graphics/material/Material.hx",546,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(u,"u")
		HX_STACK_LINE(547)
		::haxor::io::Int32Array d = u->data;		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(548)
		bool is_array = (d->m_length > u->offset);		HX_STACK_VAR(is_array,"is_array");
		HX_STACK_LINE(549)
		Array< int > l = null();		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(550)
		if ((is_array)){
			HX_STACK_LINE(552)
			l = Array_obj< int >::__new();
			HX_STACK_LINE(553)
			{
				HX_STACK_LINE(553)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(553)
				int _g = d->m_length;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(553)
				while((true)){
					HX_STACK_LINE(553)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(553)
						break;
					}
					HX_STACK_LINE(553)
					int i = (_g1)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(553)
					int _g2 = d->Get(i);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(553)
					l->push(_g2);
				}
			}
		}
		HX_STACK_LINE(556)
		{
			HX_STACK_LINE(556)
			int _g = u->offset;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(556)
			switch( (int)(_g)){
				case (int)1: {
					HX_STACK_LINE(559)
					if (((u->texture != null()))){
						HX_STACK_LINE(561)
						this->SetTexture(u->name,u->texture);
					}
					else{
						HX_STACK_LINE(565)
						if ((is_array)){
							HX_STACK_LINE(565)
							this->SetIntArray(u->name,l);
						}
						else{
							HX_STACK_LINE(565)
							int _g1 = d->Get((int)0);		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(565)
							this->SetInt(u->name,_g1);
						}
					}
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(567)
					if ((is_array)){
						HX_STACK_LINE(567)
						this->SetInt2Array(u->name,l);
					}
					else{
						HX_STACK_LINE(567)
						int _g2 = d->Get((int)0);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(567)
						int _g3 = d->Get((int)1);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(567)
						this->SetInt2(u->name,_g2,_g3);
					}
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(568)
					if ((is_array)){
						HX_STACK_LINE(568)
						this->SetInt3Array(u->name,l);
					}
					else{
						HX_STACK_LINE(568)
						int _g4 = d->Get((int)0);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(568)
						int _g5 = d->Get((int)1);		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(568)
						int _g6 = d->Get((int)2);		HX_STACK_VAR(_g6,"_g6");
						HX_STACK_LINE(568)
						this->SetInt3(u->name,_g4,_g5,_g6);
					}
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(569)
					if ((is_array)){
						HX_STACK_LINE(569)
						this->SetInt4Array(u->name,l);
					}
					else{
						HX_STACK_LINE(569)
						int _g7 = d->Get((int)0);		HX_STACK_VAR(_g7,"_g7");
						HX_STACK_LINE(569)
						int _g8 = d->Get((int)1);		HX_STACK_VAR(_g8,"_g8");
						HX_STACK_LINE(569)
						int _g9 = d->Get((int)2);		HX_STACK_VAR(_g9,"_g9");
						HX_STACK_LINE(569)
						int _g10 = d->Get((int)3);		HX_STACK_VAR(_g10,"_g10");
						HX_STACK_LINE(569)
						this->SetInt4(u->name,_g7,_g8,_g9,_g10);
					}
				}
				;break;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,SetUniformInt,(void))

Void Material_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","OnDestroy",0xc505e604,"haxor.graphics.material.Material.OnDestroy","haxor/graphics/material/Material.hx",578,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(578)
		::haxor::context::EngineContext_obj::material->DestroyMaterial(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


::haxor::graphics::material::Material Material_obj::Opaque( ::haxor::graphics::texture::Texture p_texture,hx::Null< bool >  __o_p_ztest,hx::Null< bool >  __o_p_zwrite){
bool p_ztest = __o_p_ztest.Default(true);
bool p_zwrite = __o_p_zwrite.Default(true);
	HX_STACK_FRAME("haxor.graphics.material.Material","Opaque",0xdb3e70d8,"haxor.graphics.material.Material.Opaque","haxor/graphics/material/Material.hx",39,0xe49118e6)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_ARG(p_ztest,"p_ztest")
	HX_STACK_ARG(p_zwrite,"p_zwrite")
{
		HX_STACK_LINE(40)
		::haxor::graphics::material::Material m = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Opaque"));		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(41)
		::haxor::graphics::material::Shader _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(41)
		if (((p_texture == null()))){
			HX_STACK_LINE(41)
			if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
				HX_STACK_LINE(41)
				::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(41)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g;
			}
			else{
				HX_STACK_LINE(41)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
			}
		}
		else{
			HX_STACK_LINE(41)
			if (((::haxor::graphics::material::Shader_obj::m_flat_texture_shader == null()))){
				HX_STACK_LINE(41)
				::haxor::graphics::material::Shader _g1 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_texture_source);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(41)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader = _g1;
			}
			else{
				HX_STACK_LINE(41)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader;
			}
		}
		HX_STACK_LINE(41)
		m->set_shader(_g2);
		HX_STACK_LINE(42)
		m->queue = (int)1000;
		HX_STACK_LINE(43)
		m->ztest = p_ztest;
		HX_STACK_LINE(44)
		m->zwrite = p_zwrite;
		HX_STACK_LINE(45)
		if (((p_texture != null()))){
			HX_STACK_LINE(45)
			m->SetTexture(HX_CSTRING("DiffuseTexture"),p_texture);
		}
		HX_STACK_LINE(46)
		return m;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Material_obj,Opaque,return )

::haxor::graphics::material::Material Material_obj::Transparent( ::haxor::graphics::texture::Texture p_texture,hx::Null< bool >  __o_p_ztest,hx::Null< bool >  __o_p_zwrite,hx::Null< bool >  __o_p_double_sided){
bool p_ztest = __o_p_ztest.Default(true);
bool p_zwrite = __o_p_zwrite.Default(true);
bool p_double_sided = __o_p_double_sided.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","Transparent",0x8b1ed7fb,"haxor.graphics.material.Material.Transparent","haxor/graphics/material/Material.hx",58,0xe49118e6)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_ARG(p_ztest,"p_ztest")
	HX_STACK_ARG(p_zwrite,"p_zwrite")
	HX_STACK_ARG(p_double_sided,"p_double_sided")
{
		HX_STACK_LINE(59)
		::haxor::graphics::material::Material m = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Transparent"));		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(60)
		if ((p_double_sided)){
			HX_STACK_LINE(60)
			m->cull = (int)0;
		}
		HX_STACK_LINE(61)
		m->SetBlending((int)770,(int)771);
		HX_STACK_LINE(62)
		::haxor::graphics::material::Shader _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(62)
		if (((p_texture == null()))){
			HX_STACK_LINE(62)
			if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
				HX_STACK_LINE(62)
				::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(62)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g;
			}
			else{
				HX_STACK_LINE(62)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
			}
		}
		else{
			HX_STACK_LINE(62)
			if (((::haxor::graphics::material::Shader_obj::m_flat_texture_shader == null()))){
				HX_STACK_LINE(62)
				::haxor::graphics::material::Shader _g1 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_texture_source);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(62)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader = _g1;
			}
			else{
				HX_STACK_LINE(62)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader;
			}
		}
		HX_STACK_LINE(62)
		m->set_shader(_g2);
		HX_STACK_LINE(63)
		m->queue = (int)2000;
		HX_STACK_LINE(64)
		m->ztest = p_ztest;
		HX_STACK_LINE(65)
		m->zwrite = p_zwrite;
		HX_STACK_LINE(66)
		m->blend = true;
		HX_STACK_LINE(67)
		if (((p_texture != null()))){
			HX_STACK_LINE(67)
			m->SetTexture(HX_CSTRING("DiffuseTexture"),p_texture);
		}
		HX_STACK_LINE(68)
		return m;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Material_obj,Transparent,return )

::haxor::graphics::material::Material Material_obj::AdditiveAlpha( ::haxor::graphics::texture::Texture p_texture,hx::Null< bool >  __o_p_ztest,hx::Null< bool >  __o_p_zwrite,hx::Null< bool >  __o_p_double_sided){
bool p_ztest = __o_p_ztest.Default(true);
bool p_zwrite = __o_p_zwrite.Default(true);
bool p_double_sided = __o_p_double_sided.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","AdditiveAlpha",0x6b54019b,"haxor.graphics.material.Material.AdditiveAlpha","haxor/graphics/material/Material.hx",79,0xe49118e6)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_ARG(p_ztest,"p_ztest")
	HX_STACK_ARG(p_zwrite,"p_zwrite")
	HX_STACK_ARG(p_double_sided,"p_double_sided")
{
		HX_STACK_LINE(80)
		::haxor::graphics::material::Material m;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(80)
		{
			HX_STACK_LINE(80)
			::haxor::graphics::material::Material m1 = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Transparent"));		HX_STACK_VAR(m1,"m1");
			HX_STACK_LINE(80)
			if ((p_double_sided)){
				HX_STACK_LINE(80)
				m1->cull = (int)0;
			}
			HX_STACK_LINE(80)
			m1->SetBlending((int)770,(int)771);
			HX_STACK_LINE(80)
			::haxor::graphics::material::Shader _g2;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(80)
			if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
				HX_STACK_LINE(80)
				::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(80)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g;
			}
			else{
				HX_STACK_LINE(80)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
			}
			HX_STACK_LINE(80)
			m1->set_shader(_g2);
			HX_STACK_LINE(80)
			m1->queue = (int)2000;
			HX_STACK_LINE(80)
			m1->ztest = p_ztest;
			HX_STACK_LINE(80)
			m1->zwrite = p_zwrite;
			HX_STACK_LINE(80)
			m1->blend = true;
			HX_STACK_LINE(80)
			m = m1;
		}
		HX_STACK_LINE(81)
		m->set_name(HX_CSTRING("AdditiveAlpha"));
		HX_STACK_LINE(82)
		m->SetBlending((int)770,(int)1);
		HX_STACK_LINE(83)
		return m;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Material_obj,AdditiveAlpha,return )

::haxor::graphics::material::Material Material_obj::Additive( ::haxor::graphics::texture::Texture p_texture,hx::Null< bool >  __o_p_ztest,hx::Null< bool >  __o_p_zwrite,hx::Null< bool >  __o_p_double_sided){
bool p_ztest = __o_p_ztest.Default(true);
bool p_zwrite = __o_p_zwrite.Default(true);
bool p_double_sided = __o_p_double_sided.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","Additive",0x7fd232c3,"haxor.graphics.material.Material.Additive","haxor/graphics/material/Material.hx",94,0xe49118e6)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_ARG(p_ztest,"p_ztest")
	HX_STACK_ARG(p_zwrite,"p_zwrite")
	HX_STACK_ARG(p_double_sided,"p_double_sided")
{
		HX_STACK_LINE(95)
		::haxor::graphics::material::Material m;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(95)
		{
			HX_STACK_LINE(95)
			::haxor::graphics::material::Material m1 = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Transparent"));		HX_STACK_VAR(m1,"m1");
			HX_STACK_LINE(95)
			if ((p_double_sided)){
				HX_STACK_LINE(95)
				m1->cull = (int)0;
			}
			HX_STACK_LINE(95)
			m1->SetBlending((int)770,(int)771);
			HX_STACK_LINE(95)
			::haxor::graphics::material::Shader _g2;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(95)
			if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
				HX_STACK_LINE(95)
				::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(95)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g;
			}
			else{
				HX_STACK_LINE(95)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
			}
			HX_STACK_LINE(95)
			m1->set_shader(_g2);
			HX_STACK_LINE(95)
			m1->queue = (int)2000;
			HX_STACK_LINE(95)
			m1->ztest = p_ztest;
			HX_STACK_LINE(95)
			m1->zwrite = p_zwrite;
			HX_STACK_LINE(95)
			m1->blend = true;
			HX_STACK_LINE(95)
			m = m1;
		}
		HX_STACK_LINE(96)
		m->set_name(HX_CSTRING("Additive"));
		HX_STACK_LINE(97)
		m->SetBlending((int)1,(int)1);
		HX_STACK_LINE(98)
		return m;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Material_obj,Additive,return )


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
		if (HX_FIELD_EQ(inName,"Clone") ) { return Clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Opaque") ) { return Opaque_dyn(); }
		if (HX_FIELD_EQ(inName,"zwrite") ) { return zwrite; }
		if (HX_FIELD_EQ(inName,"invert") ) { return invert; }
		if (HX_FIELD_EQ(inName,"shader") ) { return get_shader(); }
		if (HX_FIELD_EQ(inName,"SetInt") ) { return SetInt_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"SetInt2") ) { return SetInt2_dyn(); }
		if (HX_FIELD_EQ(inName,"SetInt3") ) { return SetInt3_dyn(); }
		if (HX_FIELD_EQ(inName,"SetInt4") ) { return SetInt4_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Additive") ) { return Additive_dyn(); }
		if (HX_FIELD_EQ(inName,"blendSrc") ) { return blendSrc; }
		if (HX_FIELD_EQ(inName,"blendDst") ) { return blendDst; }
		if (HX_FIELD_EQ(inName,"lighting") ) { return lighting; }
		if (HX_FIELD_EQ(inName,"m_shader") ) { return m_shader; }
		if (HX_FIELD_EQ(inName,"SetColor") ) { return SetColor_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloat") ) { return SetFloat_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"SetFloat2") ) { return SetFloat2_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloat3") ) { return SetFloat3_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloat4") ) { return SetFloat4_dyn(); }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_shader") ) { return get_shader_dyn(); }
		if (HX_FIELD_EQ(inName,"set_shader") ) { return set_shader_dyn(); }
		if (HX_FIELD_EQ(inName,"m_uniforms") ) { return m_uniforms; }
		if (HX_FIELD_EQ(inName,"SetTexture") ) { return SetTexture_dyn(); }
		if (HX_FIELD_EQ(inName,"SetMatrix4") ) { return SetMatrix4_dyn(); }
		if (HX_FIELD_EQ(inName,"SetVector2") ) { return SetVector2_dyn(); }
		if (HX_FIELD_EQ(inName,"SetVector3") ) { return SetVector3_dyn(); }
		if (HX_FIELD_EQ(inName,"SetVector4") ) { return SetVector4_dyn(); }
		if (HX_FIELD_EQ(inName,"GetUniform") ) { return GetUniform_dyn(); }
		if (HX_FIELD_EQ(inName,"HasUniform") ) { return HasUniform_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"Transparent") ) { return Transparent_dyn(); }
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
		if (HX_FIELD_EQ(inName,"AdditiveAlpha") ) { return AdditiveAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloatArray") ) { return SetFloatArray_dyn(); }
		if (HX_FIELD_EQ(inName,"RemoveUniform") ) { return RemoveUniform_dyn(); }
		if (HX_FIELD_EQ(inName,"SetUniformInt") ) { return SetUniformInt_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"SetFloat2Array") ) { return SetFloat2Array_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloat3Array") ) { return SetFloat3Array_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloat4Array") ) { return SetFloat4Array_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"SetUniformFloat") ) { return SetUniformFloat_dyn(); }
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
	HX_CSTRING("Opaque"),
	HX_CSTRING("Transparent"),
	HX_CSTRING("AdditiveAlpha"),
	HX_CSTRING("Additive"),
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
	HX_CSTRING("SetMatrix4"),
	HX_CSTRING("SetVector2"),
	HX_CSTRING("SetVector3"),
	HX_CSTRING("SetVector4"),
	HX_CSTRING("SetColor"),
	HX_CSTRING("SetFloat"),
	HX_CSTRING("SetFloat2"),
	HX_CSTRING("SetFloat3"),
	HX_CSTRING("SetFloat4"),
	HX_CSTRING("SetFloatArray"),
	HX_CSTRING("SetFloat2Array"),
	HX_CSTRING("SetFloat3Array"),
	HX_CSTRING("SetFloat4Array"),
	HX_CSTRING("SetInt"),
	HX_CSTRING("SetInt2"),
	HX_CSTRING("SetInt3"),
	HX_CSTRING("SetInt4"),
	HX_CSTRING("SetIntArray"),
	HX_CSTRING("SetInt2Array"),
	HX_CSTRING("SetInt3Array"),
	HX_CSTRING("SetInt4Array"),
	HX_CSTRING("GetUniform"),
	HX_CSTRING("HasUniform"),
	HX_CSTRING("RemoveUniform"),
	HX_CSTRING("FetchUniform"),
	HX_CSTRING("Clone"),
	HX_CSTRING("SetUniformFloat"),
	HX_CSTRING("SetUniformInt"),
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
