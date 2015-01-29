#include <hxcpp.h>

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
HX_STACK_FRAME("haxor.graphics.material.Material","new",0xec1f7429,"haxor.graphics.material.Material.new","haxor/graphics/material/Material.hx",28,0xe49118e6)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(163)
	this->grab = false;
	HX_STACK_LINE(190)
	super::__construct(p_name);
	HX_STACK_LINE(191)
	int _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(191)
	{
		HX_STACK_LINE(191)
		::haxor::context::UID _this = ::haxor::context::EngineContext_obj::material->mid;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(191)
		if (((_this->m_cache->length <= (int)0))){
			HX_STACK_LINE(191)
			_g = (_this->m_id)++;
		}
		else{
			HX_STACK_LINE(191)
			_g = _this->m_cache->shift();
		}
	}
	HX_STACK_LINE(191)
	this->__cid = _g;
	HX_STACK_LINE(192)
	this->m_uniforms = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(193)
	this->queue = (int)1000;
	HX_STACK_LINE(194)
	this->zfunc = (int)515;
	HX_STACK_LINE(195)
	this->ztest = true;
	HX_STACK_LINE(196)
	this->zwrite = true;
	HX_STACK_LINE(197)
	this->blend = false;
	HX_STACK_LINE(198)
	this->blendSrc = (int)1;
	HX_STACK_LINE(199)
	this->blendDst = (int)0;
	HX_STACK_LINE(200)
	this->invert = false;
	HX_STACK_LINE(201)
	this->cull = (int)2;
	HX_STACK_LINE(202)
	this->lighting = false;
	HX_STACK_LINE(203)
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
	HX_STACK_FRAME("haxor.graphics.material.Material","get_shader",0x08828645,"haxor.graphics.material.Material.get_shader","haxor/graphics/material/Material.hx",169,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(169)
	return this->m_shader;
}


HX_DEFINE_DYNAMIC_FUNC0(Material_obj,get_shader,return )

::haxor::graphics::material::Shader Material_obj::set_shader( ::haxor::graphics::material::Shader v){
	HX_STACK_FRAME("haxor.graphics.material.Material","set_shader",0x0c0024b9,"haxor.graphics.material.Material.set_shader","haxor/graphics/material/Material.hx",171,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(172)
	if (((this->m_shader == v))){
		HX_STACK_LINE(172)
		return v;
	}
	HX_STACK_LINE(173)
	::haxor::context::EngineContext_obj::material->UpdateShader(hx::ObjectPtr<OBJ_>(this),this->m_shader,v);
	HX_STACK_LINE(174)
	this->m_shader = v;
	HX_STACK_LINE(175)
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
		if ((u->exists)){
			HX_STACK_LINE(228)
			u->SetTexture(p_texture);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetTexture,(void))

Void Material_obj::SetMatrix4( ::String p_name,::haxor::math::Matrix4 p_matrix4,hx::Null< bool >  __o_p_transpose){
bool p_transpose = __o_p_transpose.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","SetMatrix4",0xd7d1c2c8,"haxor.graphics.material.Material.SetMatrix4","haxor/graphics/material/Material.hx",237,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_matrix4,"p_matrix4")
	HX_STACK_ARG(p_transpose,"p_transpose")
{
		HX_STACK_LINE(238)
		if (((p_matrix4 == null()))){
			HX_STACK_LINE(238)
			this->RemoveUniform(p_name);
			HX_STACK_LINE(238)
			return null();
		}
		HX_STACK_LINE(239)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)16,(int)16,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(240)
		if ((u->exists)){
			HX_STACK_LINE(240)
			u->SetMatrix4(p_matrix4,p_transpose);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Material_obj,SetMatrix4,(void))

Void Material_obj::SetVector2( ::String p_name,::haxor::math::Vector2 p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetVector2",0x1f077a04,"haxor.graphics.material.Material.SetVector2","haxor/graphics/material/Material.hx",248,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(248)
		this->SetFloat2(p_name,p_v->x,p_v->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetVector2,(void))

Void Material_obj::SetVector3( ::String p_name,::haxor::math::Vector3 p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetVector3",0x1f077a05,"haxor.graphics.material.Material.SetVector3","haxor/graphics/material/Material.hx",255,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(255)
		this->SetFloat3(p_name,p_v->x,p_v->y,p_v->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetVector3,(void))

Void Material_obj::SetVector4( ::String p_name,::haxor::math::Vector4 p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetVector4",0x1f077a06,"haxor.graphics.material.Material.SetVector4","haxor/graphics/material/Material.hx",262,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(262)
		this->SetFloat4(p_name,p_v->x,p_v->y,p_v->z,p_v->w);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetVector4,(void))

Void Material_obj::SetColor( ::String p_name,::haxor::math::Color p_color){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetColor",0x30239a18,"haxor.graphics.material.Material.SetColor","haxor/graphics/material/Material.hx",269,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_LINE(269)
		this->SetFloat4(p_name,p_color->r,p_color->g,p_color->b,p_color->a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetColor,(void))

Void Material_obj::SetFloat( ::String p_name,Float p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat",0xe85dee51,"haxor.graphics.material.Material.SetFloat","haxor/graphics/material/Material.hx",276,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(276)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)1,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(276)
		if ((u->exists)){
			HX_STACK_LINE(276)
			u->SetFloat(p_v);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat,(void))

Void Material_obj::SetFloat2( ::String p_name,Float p_x,Float p_y){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat2",0x69d298c1,"haxor.graphics.material.Material.SetFloat2","haxor/graphics/material/Material.hx",284,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(284)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)2,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(284)
		if ((u->exists)){
			HX_STACK_LINE(284)
			u->SetFloat2(p_x,p_y);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Material_obj,SetFloat2,(void))

Void Material_obj::SetFloat3( ::String p_name,Float p_x,Float p_y,Float p_z){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat3",0x69d298c2,"haxor.graphics.material.Material.SetFloat3","haxor/graphics/material/Material.hx",294,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(294)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)3,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(294)
		if ((u->exists)){
			HX_STACK_LINE(294)
			u->SetFloat3(p_x,p_y,p_z);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Material_obj,SetFloat3,(void))

Void Material_obj::SetFloat4( ::String p_name,Float p_x,Float p_y,Float p_z,Float p_w){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat4",0x69d298c3,"haxor.graphics.material.Material.SetFloat4","haxor/graphics/material/Material.hx",304,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(304)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)4,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(304)
		if ((u->exists)){
			HX_STACK_LINE(304)
			u->SetFloat4(p_x,p_y,p_z,p_w);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Material_obj,SetFloat4,(void))

Void Material_obj::SetFloatArray( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloatArray",0xb2086988,"haxor.graphics.material.Material.SetFloatArray","haxor/graphics/material/Material.hx",311,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(311)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(311)
		if ((u->exists)){
			HX_STACK_LINE(311)
			u->SetFloatArray(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloatArray,(void))

Void Material_obj::SetFloat2Array( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat2Array",0xdf63e918,"haxor.graphics.material.Material.SetFloat2Array","haxor/graphics/material/Material.hx",318,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(318)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(318)
		if ((u->exists)){
			HX_STACK_LINE(318)
			u->SetFloat2Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat2Array,(void))

Void Material_obj::SetFloat3Array( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat3Array",0x45bf4577,"haxor.graphics.material.Material.SetFloat3Array","haxor/graphics/material/Material.hx",325,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(325)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(325)
		if ((u->exists)){
			HX_STACK_LINE(325)
			u->SetFloat3Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat3Array,(void))

Void Material_obj::SetFloat4Array( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat4Array",0xac1aa1d6,"haxor.graphics.material.Material.SetFloat4Array","haxor/graphics/material/Material.hx",332,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(332)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(332)
		if ((u->exists)){
			HX_STACK_LINE(332)
			u->SetFloat4Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat4Array,(void))

Void Material_obj::SetInt( ::String p_name,int p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt",0x2bb42e64,"haxor.graphics.material.Material.SetInt","haxor/graphics/material/Material.hx",339,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(339)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)1,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(339)
		if ((u->exists)){
			HX_STACK_LINE(339)
			u->SetInt(p_v);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt,(void))

Void Material_obj::SetInt2( ::String p_name,int p_x,int p_y){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt2",0x11f4694e,"haxor.graphics.material.Material.SetInt2","haxor/graphics/material/Material.hx",347,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(347)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)2,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(347)
		if ((u->exists)){
			HX_STACK_LINE(347)
			u->SetInt2(p_x,p_y);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Material_obj,SetInt2,(void))

Void Material_obj::SetInt3( ::String p_name,int p_x,int p_y,int p_z){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt3",0x11f4694f,"haxor.graphics.material.Material.SetInt3","haxor/graphics/material/Material.hx",356,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(356)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)3,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(356)
		if ((u->exists)){
			HX_STACK_LINE(356)
			u->SetInt3(p_x,p_y,p_z);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Material_obj,SetInt3,(void))

Void Material_obj::SetInt4( ::String p_name,int p_x,int p_y,int p_z,int p_w){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt4",0x11f46950,"haxor.graphics.material.Material.SetInt4","haxor/graphics/material/Material.hx",366,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(366)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)4,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(366)
		if ((u->exists)){
			HX_STACK_LINE(366)
			u->SetInt4(p_x,p_y,p_z,p_w);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Material_obj,SetInt4,(void))

Void Material_obj::SetIntArray( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetIntArray",0x06d20495,"haxor.graphics.material.Material.SetIntArray","haxor/graphics/material/Material.hx",373,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(373)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(373)
		if ((u->exists)){
			HX_STACK_LINE(373)
			u->SetIntArray(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetIntArray,(void))

Void Material_obj::SetInt2Array( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt2Array",0xbb01f96b,"haxor.graphics.material.Material.SetInt2Array","haxor/graphics/material/Material.hx",380,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(380)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(380)
		if ((u->exists)){
			HX_STACK_LINE(380)
			u->SetInt2Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt2Array,(void))

Void Material_obj::SetInt3Array( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt3Array",0x215d55ca,"haxor.graphics.material.Material.SetInt3Array","haxor/graphics/material/Material.hx",387,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(387)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(387)
		if ((u->exists)){
			HX_STACK_LINE(387)
			u->SetInt3Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt3Array,(void))

Void Material_obj::SetInt4Array( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt4Array",0x87b8b229,"haxor.graphics.material.Material.SetInt4Array","haxor/graphics/material/Material.hx",394,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(394)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(394)
		if ((u->exists)){
			HX_STACK_LINE(394)
			u->SetInt4Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt4Array,(void))

::haxor::graphics::material::MaterialUniform Material_obj::GetUniform( ::String p_name){
	HX_STACK_FRAME("haxor.graphics.material.Material","GetUniform",0xf65122b5,"haxor.graphics.material.Material.GetUniform","haxor/graphics/material/Material.hx",402,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(403)
	{
		HX_STACK_LINE(403)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(403)
		int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(403)
		while((true)){
			HX_STACK_LINE(403)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(403)
				break;
			}
			HX_STACK_LINE(403)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(403)
			if (((this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >()->name == p_name))){
				HX_STACK_LINE(403)
				return this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >();
			}
		}
	}
	HX_STACK_LINE(404)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,GetUniform,return )

bool Material_obj::HasUniform( ::String p_name,hx::Null< bool >  __o_p_check_shader){
bool p_check_shader = __o_p_check_shader.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","HasUniform",0x31a38471,"haxor.graphics.material.Material.HasUniform","haxor/graphics/material/Material.hx",414,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_check_shader,"p_check_shader")
{
		HX_STACK_LINE(415)
		{
			HX_STACK_LINE(415)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(415)
			int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(415)
			while((true)){
				HX_STACK_LINE(415)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(415)
					break;
				}
				HX_STACK_LINE(415)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(417)
				if (((this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >()->name == p_name))){
					HX_STACK_LINE(419)
					if ((p_check_shader)){
						HX_STACK_LINE(419)
						return this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >()->exists;
					}
					HX_STACK_LINE(420)
					return true;
				}
			}
		}
		HX_STACK_LINE(423)
		return false;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,HasUniform,return )

Void Material_obj::RemoveUniform( ::String p_name){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","RemoveUniform",0x5a868639,"haxor.graphics.material.Material.RemoveUniform","haxor/graphics/material/Material.hx",431,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_LINE(432)
		::haxor::graphics::material::MaterialUniform u = null();		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(433)
		{
			HX_STACK_LINE(433)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(433)
			int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(433)
			while((true)){
				HX_STACK_LINE(433)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(433)
					break;
				}
				HX_STACK_LINE(433)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(435)
				u = this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >();
				HX_STACK_LINE(436)
				if (((u->name == p_name))){
					HX_STACK_LINE(436)
					break;
				}
			}
		}
		HX_STACK_LINE(438)
		if (((u != null()))){
			HX_STACK_LINE(440)
			::haxor::context::EngineContext_obj::material->DestroyUniform(hx::ObjectPtr<OBJ_>(this),u);
			HX_STACK_LINE(441)
			this->m_uniforms->remove(u);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,RemoveUniform,(void))

::haxor::graphics::material::MaterialUniform Material_obj::FetchUniform( ::String p_name,bool p_is_float,int p_length,int p_offset,bool p_create){
	HX_STACK_FRAME("haxor.graphics.material.Material","FetchUniform",0x6e061751,"haxor.graphics.material.Material.FetchUniform","haxor/graphics/material/Material.hx",452,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_is_float,"p_is_float")
	HX_STACK_ARG(p_length,"p_length")
	HX_STACK_ARG(p_offset,"p_offset")
	HX_STACK_ARG(p_create,"p_create")
	HX_STACK_LINE(453)
	::haxor::graphics::material::MaterialUniform u = null();		HX_STACK_VAR(u,"u");
	HX_STACK_LINE(454)
	{
		HX_STACK_LINE(454)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(454)
		int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(454)
		while((true)){
			HX_STACK_LINE(454)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(454)
				break;
			}
			HX_STACK_LINE(454)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(456)
			u = this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >();
			HX_STACK_LINE(457)
			if (((u->name == p_name))){
				HX_STACK_LINE(459)
				if (((u->isFloat == p_is_float))){
					HX_STACK_LINE(461)
					if (((u->offset == p_offset))){
						HX_STACK_LINE(463)
						if (((u->data->m_length == p_length))){
							HX_STACK_LINE(464)
							return u;
						}
					}
				}
				HX_STACK_LINE(468)
				::haxor::context::EngineContext_obj::material->DestroyUniform(hx::ObjectPtr<OBJ_>(this),u);
				HX_STACK_LINE(469)
				this->m_uniforms->remove(u);
				HX_STACK_LINE(470)
				break;
			}
		}
	}
	HX_STACK_LINE(473)
	if ((p_create)){
		HX_STACK_LINE(475)
		::haxor::graphics::material::MaterialUniform _g = ::haxor::graphics::material::MaterialUniform_obj::__new(p_name,p_is_float,p_length,p_offset);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(475)
		u = _g;
		HX_STACK_LINE(476)
		::haxor::context::EngineContext_obj::material->CreateUniform(hx::ObjectPtr<OBJ_>(this),u);
		HX_STACK_LINE(477)
		this->m_uniforms->push(u);
	}
	HX_STACK_LINE(479)
	return u;
}


HX_DEFINE_DYNAMIC_FUNC5(Material_obj,FetchUniform,return )

Void Material_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","OnDestroy",0xc505e604,"haxor.graphics.material.Material.OnDestroy","haxor/graphics/material/Material.hx",514,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(514)
		::haxor::context::EngineContext_obj::material->DestroyMaterial(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


::haxor::graphics::material::Material Material_obj::Opaque( ::haxor::graphics::texture::Texture p_texture,hx::Null< bool >  __o_p_ztest,hx::Null< bool >  __o_p_zwrite){
bool p_ztest = __o_p_ztest.Default(true);
bool p_zwrite = __o_p_zwrite.Default(true);
	HX_STACK_FRAME("haxor.graphics.material.Material","Opaque",0xdb3e70d8,"haxor.graphics.material.Material.Opaque","haxor/graphics/material/Material.hx",38,0xe49118e6)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_ARG(p_ztest,"p_ztest")
	HX_STACK_ARG(p_zwrite,"p_zwrite")
{
		HX_STACK_LINE(39)
		::haxor::graphics::material::Material m = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Opaque"));		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(40)
		::haxor::graphics::material::Shader _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(40)
		if (((p_texture == null()))){
			HX_STACK_LINE(40)
			if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
				HX_STACK_LINE(40)
				::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(40)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g;
			}
			else{
				HX_STACK_LINE(40)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
			}
		}
		else{
			HX_STACK_LINE(40)
			if (((::haxor::graphics::material::Shader_obj::m_flat_texture_shader == null()))){
				HX_STACK_LINE(40)
				::haxor::graphics::material::Shader _g1 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_texture_source);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(40)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader = _g1;
			}
			else{
				HX_STACK_LINE(40)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader;
			}
		}
		HX_STACK_LINE(40)
		m->set_shader(_g2);
		HX_STACK_LINE(41)
		m->queue = (int)1000;
		HX_STACK_LINE(42)
		m->ztest = p_ztest;
		HX_STACK_LINE(43)
		m->zwrite = p_zwrite;
		HX_STACK_LINE(44)
		if (((p_texture != null()))){
			HX_STACK_LINE(44)
			m->SetTexture(HX_CSTRING("DiffuseTexture"),p_texture);
		}
		HX_STACK_LINE(45)
		return m;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Material_obj,Opaque,return )

::haxor::graphics::material::Material Material_obj::Transparent( ::haxor::graphics::texture::Texture p_texture,hx::Null< bool >  __o_p_ztest,hx::Null< bool >  __o_p_zwrite,hx::Null< bool >  __o_p_double_sided){
bool p_ztest = __o_p_ztest.Default(true);
bool p_zwrite = __o_p_zwrite.Default(true);
bool p_double_sided = __o_p_double_sided.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","Transparent",0x8b1ed7fb,"haxor.graphics.material.Material.Transparent","haxor/graphics/material/Material.hx",57,0xe49118e6)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_ARG(p_ztest,"p_ztest")
	HX_STACK_ARG(p_zwrite,"p_zwrite")
	HX_STACK_ARG(p_double_sided,"p_double_sided")
{
		HX_STACK_LINE(58)
		::haxor::graphics::material::Material m = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Transparent"));		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(59)
		if ((p_double_sided)){
			HX_STACK_LINE(59)
			m->cull = (int)0;
		}
		HX_STACK_LINE(60)
		m->SetBlending((int)770,(int)771);
		HX_STACK_LINE(61)
		::haxor::graphics::material::Shader _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(61)
		if (((p_texture == null()))){
			HX_STACK_LINE(61)
			if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
				HX_STACK_LINE(61)
				::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(61)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g;
			}
			else{
				HX_STACK_LINE(61)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
			}
		}
		else{
			HX_STACK_LINE(61)
			if (((::haxor::graphics::material::Shader_obj::m_flat_texture_shader == null()))){
				HX_STACK_LINE(61)
				::haxor::graphics::material::Shader _g1 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_texture_source);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(61)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader = _g1;
			}
			else{
				HX_STACK_LINE(61)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader;
			}
		}
		HX_STACK_LINE(61)
		m->set_shader(_g2);
		HX_STACK_LINE(62)
		m->queue = (int)2000;
		HX_STACK_LINE(63)
		m->ztest = p_ztest;
		HX_STACK_LINE(64)
		m->zwrite = p_zwrite;
		HX_STACK_LINE(65)
		m->blend = true;
		HX_STACK_LINE(66)
		if (((p_texture != null()))){
			HX_STACK_LINE(66)
			m->SetTexture(HX_CSTRING("DiffuseTexture"),p_texture);
		}
		HX_STACK_LINE(67)
		return m;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Material_obj,Transparent,return )

::haxor::graphics::material::Material Material_obj::AdditiveAlpha( ::haxor::graphics::texture::Texture p_texture,hx::Null< bool >  __o_p_ztest,hx::Null< bool >  __o_p_zwrite,hx::Null< bool >  __o_p_double_sided){
bool p_ztest = __o_p_ztest.Default(true);
bool p_zwrite = __o_p_zwrite.Default(true);
bool p_double_sided = __o_p_double_sided.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","AdditiveAlpha",0x6b54019b,"haxor.graphics.material.Material.AdditiveAlpha","haxor/graphics/material/Material.hx",78,0xe49118e6)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_ARG(p_ztest,"p_ztest")
	HX_STACK_ARG(p_zwrite,"p_zwrite")
	HX_STACK_ARG(p_double_sided,"p_double_sided")
{
		HX_STACK_LINE(79)
		::haxor::graphics::material::Material m;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(79)
		{
			HX_STACK_LINE(79)
			::haxor::graphics::material::Material m1 = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Transparent"));		HX_STACK_VAR(m1,"m1");
			HX_STACK_LINE(79)
			if ((p_double_sided)){
				HX_STACK_LINE(79)
				m1->cull = (int)0;
			}
			HX_STACK_LINE(79)
			m1->SetBlending((int)770,(int)771);
			HX_STACK_LINE(79)
			::haxor::graphics::material::Shader _g2;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(79)
			if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
				HX_STACK_LINE(79)
				::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(79)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g;
			}
			else{
				HX_STACK_LINE(79)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
			}
			HX_STACK_LINE(79)
			m1->set_shader(_g2);
			HX_STACK_LINE(79)
			m1->queue = (int)2000;
			HX_STACK_LINE(79)
			m1->ztest = p_ztest;
			HX_STACK_LINE(79)
			m1->zwrite = p_zwrite;
			HX_STACK_LINE(79)
			m1->blend = true;
			HX_STACK_LINE(79)
			m = m1;
		}
		HX_STACK_LINE(80)
		m->set_name(HX_CSTRING("AdditiveAlpha"));
		HX_STACK_LINE(81)
		m->SetBlending((int)770,(int)1);
		HX_STACK_LINE(82)
		return m;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Material_obj,AdditiveAlpha,return )

::haxor::graphics::material::Material Material_obj::Additive( ::haxor::graphics::texture::Texture p_texture,hx::Null< bool >  __o_p_ztest,hx::Null< bool >  __o_p_zwrite,hx::Null< bool >  __o_p_double_sided){
bool p_ztest = __o_p_ztest.Default(true);
bool p_zwrite = __o_p_zwrite.Default(true);
bool p_double_sided = __o_p_double_sided.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","Additive",0x7fd232c3,"haxor.graphics.material.Material.Additive","haxor/graphics/material/Material.hx",93,0xe49118e6)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_ARG(p_ztest,"p_ztest")
	HX_STACK_ARG(p_zwrite,"p_zwrite")
	HX_STACK_ARG(p_double_sided,"p_double_sided")
{
		HX_STACK_LINE(94)
		::haxor::graphics::material::Material m;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(94)
		{
			HX_STACK_LINE(94)
			::haxor::graphics::material::Material m1 = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Transparent"));		HX_STACK_VAR(m1,"m1");
			HX_STACK_LINE(94)
			if ((p_double_sided)){
				HX_STACK_LINE(94)
				m1->cull = (int)0;
			}
			HX_STACK_LINE(94)
			m1->SetBlending((int)770,(int)771);
			HX_STACK_LINE(94)
			::haxor::graphics::material::Shader _g2;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(94)
			if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
				HX_STACK_LINE(94)
				::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(94)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g;
			}
			else{
				HX_STACK_LINE(94)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
			}
			HX_STACK_LINE(94)
			m1->set_shader(_g2);
			HX_STACK_LINE(94)
			m1->queue = (int)2000;
			HX_STACK_LINE(94)
			m1->ztest = p_ztest;
			HX_STACK_LINE(94)
			m1->zwrite = p_zwrite;
			HX_STACK_LINE(94)
			m1->blend = true;
			HX_STACK_LINE(94)
			m = m1;
		}
		HX_STACK_LINE(95)
		m->set_name(HX_CSTRING("Additive"));
		HX_STACK_LINE(96)
		m->SetBlending((int)1,(int)1);
		HX_STACK_LINE(97)
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
