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
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_graphics_WinGL
#include <haxor/platform/windows/graphics/WinGL.h>
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
	HX_STACK_LINE(144)
	this->grab = false;
	HX_STACK_LINE(171)
	super::__construct(p_name);
	HX_STACK_LINE(172)
	int _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(172)
	{
		HX_STACK_LINE(172)
		::haxor::context::UID _this = ::haxor::context::EngineContext_obj::material->mid;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(172)
		if (((_this->m_cache->length <= (int)0))){
			HX_STACK_LINE(172)
			_g = (_this->m_id)++;
		}
		else{
			HX_STACK_LINE(172)
			_g = _this->m_cache->shift();
		}
	}
	HX_STACK_LINE(172)
	this->__cid = _g;
	HX_STACK_LINE(173)
	this->m_uniforms = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(174)
	this->queue = (int)1000;
	HX_STACK_LINE(175)
	this->zfunc = (int)515;
	HX_STACK_LINE(176)
	this->ztest = true;
	HX_STACK_LINE(177)
	this->zwrite = true;
	HX_STACK_LINE(178)
	this->blend = false;
	HX_STACK_LINE(179)
	this->blendSrc = (int)1;
	HX_STACK_LINE(180)
	this->blendDst = (int)0;
	HX_STACK_LINE(181)
	this->invert = false;
	HX_STACK_LINE(182)
	this->cull = (int)2;
	HX_STACK_LINE(183)
	this->lighting = false;
	HX_STACK_LINE(184)
	this->grab = false;
	HX_STACK_LINE(186)
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
	HX_STACK_FRAME("haxor.graphics.material.Material","get_shader",0x08828645,"haxor.graphics.material.Material.get_shader","haxor/graphics/material/Material.hx",150,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(150)
	return this->m_shader;
}


HX_DEFINE_DYNAMIC_FUNC0(Material_obj,get_shader,return )

::haxor::graphics::material::Shader Material_obj::set_shader( ::haxor::graphics::material::Shader v){
	HX_STACK_FRAME("haxor.graphics.material.Material","set_shader",0x0c0024b9,"haxor.graphics.material.Material.set_shader","haxor/graphics/material/Material.hx",152,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(153)
	if (((this->m_shader == v))){
		HX_STACK_LINE(153)
		return v;
	}
	HX_STACK_LINE(154)
	::haxor::context::EngineContext_obj::material->UpdateShader(hx::ObjectPtr<OBJ_>(this),this->m_shader,v);
	HX_STACK_LINE(155)
	this->m_shader = v;
	HX_STACK_LINE(156)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,set_shader,return )

Void Material_obj::SetBlending( int p_src,int p_dst){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetBlending",0x03abe39c,"haxor.graphics.material.Material.SetBlending","haxor/graphics/material/Material.hx",195,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_src,"p_src")
		HX_STACK_ARG(p_dst,"p_dst")
		HX_STACK_LINE(196)
		this->blendSrc = p_src;
		HX_STACK_LINE(197)
		this->blendDst = p_dst;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetBlending,(void))

Void Material_obj::SetTexture( ::String p_name,::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetTexture",0xe34b48d0,"haxor.graphics.material.Material.SetTexture","haxor/graphics/material/Material.hx",206,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_texture,"p_texture")
		HX_STACK_LINE(207)
		if (((p_texture == null()))){
			HX_STACK_LINE(207)
			this->RemoveUniform(p_name);
			HX_STACK_LINE(207)
			return null();
		}
		HX_STACK_LINE(208)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)1,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(209)
		if ((u->exists)){
			HX_STACK_LINE(209)
			u->SetTexture(p_texture);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetTexture,(void))

Void Material_obj::SetMatrix4( ::String p_name,::haxor::math::Matrix4 p_matrix4){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetMatrix4",0xd7d1c2c8,"haxor.graphics.material.Material.SetMatrix4","haxor/graphics/material/Material.hx",218,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_matrix4,"p_matrix4")
		HX_STACK_LINE(219)
		if (((p_matrix4 == null()))){
			HX_STACK_LINE(219)
			this->RemoveUniform(p_name);
			HX_STACK_LINE(219)
			return null();
		}
		HX_STACK_LINE(220)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)16,(int)16,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(221)
		if ((u->exists)){
			HX_STACK_LINE(221)
			u->SetMatrix4(p_matrix4);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetMatrix4,(void))

Void Material_obj::SetVector2( ::String p_name,::haxor::math::Vector2 p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetVector2",0x1f077a04,"haxor.graphics.material.Material.SetVector2","haxor/graphics/material/Material.hx",229,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(229)
		this->SetFloat2(p_name,p_v->x,p_v->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetVector2,(void))

Void Material_obj::SetVector3( ::String p_name,::haxor::math::Vector3 p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetVector3",0x1f077a05,"haxor.graphics.material.Material.SetVector3","haxor/graphics/material/Material.hx",236,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(236)
		this->SetFloat3(p_name,p_v->x,p_v->y,p_v->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetVector3,(void))

Void Material_obj::SetVector4( ::String p_name,::haxor::math::Vector4 p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetVector4",0x1f077a06,"haxor.graphics.material.Material.SetVector4","haxor/graphics/material/Material.hx",243,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(243)
		this->SetFloat4(p_name,p_v->x,p_v->y,p_v->z,p_v->w);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetVector4,(void))

Void Material_obj::SetColor( ::String p_name,::haxor::math::Color p_color){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetColor",0x30239a18,"haxor.graphics.material.Material.SetColor","haxor/graphics/material/Material.hx",250,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_LINE(250)
		this->SetFloat4(p_name,p_color->r,p_color->g,p_color->b,p_color->a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetColor,(void))

Void Material_obj::SetFloat( ::String p_name,Float p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat",0xe85dee51,"haxor.graphics.material.Material.SetFloat","haxor/graphics/material/Material.hx",257,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(257)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)1,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(257)
		if ((u->exists)){
			HX_STACK_LINE(257)
			u->SetFloat(p_v);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat,(void))

Void Material_obj::SetFloat2( ::String p_name,Float p_x,Float p_y){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat2",0x69d298c1,"haxor.graphics.material.Material.SetFloat2","haxor/graphics/material/Material.hx",265,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(265)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)2,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(265)
		if ((u->exists)){
			HX_STACK_LINE(265)
			u->SetFloat2(p_x,p_y);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Material_obj,SetFloat2,(void))

Void Material_obj::SetFloat3( ::String p_name,Float p_x,Float p_y,Float p_z){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat3",0x69d298c2,"haxor.graphics.material.Material.SetFloat3","haxor/graphics/material/Material.hx",275,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(275)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)3,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(275)
		if ((u->exists)){
			HX_STACK_LINE(275)
			u->SetFloat3(p_x,p_y,p_z);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Material_obj,SetFloat3,(void))

Void Material_obj::SetFloat4( ::String p_name,Float p_x,Float p_y,Float p_z,Float p_w){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat4",0x69d298c3,"haxor.graphics.material.Material.SetFloat4","haxor/graphics/material/Material.hx",285,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(285)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,(int)4,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(285)
		if ((u->exists)){
			HX_STACK_LINE(285)
			u->SetFloat4(p_x,p_y,p_z,p_w);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Material_obj,SetFloat4,(void))

Void Material_obj::SetFloatArray( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloatArray",0xb2086988,"haxor.graphics.material.Material.SetFloatArray","haxor/graphics/material/Material.hx",292,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(292)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(292)
		if ((u->exists)){
			HX_STACK_LINE(292)
			u->SetFloatArray(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloatArray,(void))

Void Material_obj::SetFloat2Array( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat2Array",0xdf63e918,"haxor.graphics.material.Material.SetFloat2Array","haxor/graphics/material/Material.hx",299,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(299)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(299)
		if ((u->exists)){
			HX_STACK_LINE(299)
			u->SetFloat2Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat2Array,(void))

Void Material_obj::SetFloat3Array( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat3Array",0x45bf4577,"haxor.graphics.material.Material.SetFloat3Array","haxor/graphics/material/Material.hx",306,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(306)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(306)
		if ((u->exists)){
			HX_STACK_LINE(306)
			u->SetFloat3Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat3Array,(void))

Void Material_obj::SetFloat4Array( ::String p_name,Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetFloat4Array",0xac1aa1d6,"haxor.graphics.material.Material.SetFloat4Array","haxor/graphics/material/Material.hx",313,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(313)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,true,p_list->length,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(313)
		if ((u->exists)){
			HX_STACK_LINE(313)
			u->SetFloat4Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetFloat4Array,(void))

Void Material_obj::SetInt( ::String p_name,int p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt",0x2bb42e64,"haxor.graphics.material.Material.SetInt","haxor/graphics/material/Material.hx",320,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(320)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)1,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(320)
		if ((u->exists)){
			HX_STACK_LINE(320)
			u->SetInt(p_v);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt,(void))

Void Material_obj::SetInt2( ::String p_name,int p_x,int p_y){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt2",0x11f4694e,"haxor.graphics.material.Material.SetInt2","haxor/graphics/material/Material.hx",328,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(328)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)2,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(328)
		if ((u->exists)){
			HX_STACK_LINE(328)
			u->SetInt2(p_x,p_y);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Material_obj,SetInt2,(void))

Void Material_obj::SetInt3( ::String p_name,int p_x,int p_y,int p_z){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt3",0x11f4694f,"haxor.graphics.material.Material.SetInt3","haxor/graphics/material/Material.hx",337,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(337)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)3,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(337)
		if ((u->exists)){
			HX_STACK_LINE(337)
			u->SetInt3(p_x,p_y,p_z);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Material_obj,SetInt3,(void))

Void Material_obj::SetInt4( ::String p_name,int p_x,int p_y,int p_z,int p_w){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt4",0x11f46950,"haxor.graphics.material.Material.SetInt4","haxor/graphics/material/Material.hx",347,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(347)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,(int)4,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(347)
		if ((u->exists)){
			HX_STACK_LINE(347)
			u->SetInt4(p_x,p_y,p_z,p_w);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(Material_obj,SetInt4,(void))

Void Material_obj::SetIntArray( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetIntArray",0x06d20495,"haxor.graphics.material.Material.SetIntArray","haxor/graphics/material/Material.hx",354,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(354)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)1,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(354)
		if ((u->exists)){
			HX_STACK_LINE(354)
			u->SetIntArray(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetIntArray,(void))

Void Material_obj::SetInt2Array( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt2Array",0xbb01f96b,"haxor.graphics.material.Material.SetInt2Array","haxor/graphics/material/Material.hx",361,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(361)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)2,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(361)
		if ((u->exists)){
			HX_STACK_LINE(361)
			u->SetInt2Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt2Array,(void))

Void Material_obj::SetInt3Array( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt3Array",0x215d55ca,"haxor.graphics.material.Material.SetInt3Array","haxor/graphics/material/Material.hx",368,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(368)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)3,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(368)
		if ((u->exists)){
			HX_STACK_LINE(368)
			u->SetInt3Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt3Array,(void))

Void Material_obj::SetInt4Array( ::String p_name,Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetInt4Array",0x87b8b229,"haxor.graphics.material.Material.SetInt4Array","haxor/graphics/material/Material.hx",375,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(375)
		::haxor::graphics::material::MaterialUniform u = this->FetchUniform(p_name,false,p_list->length,(int)4,true);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(375)
		if ((u->exists)){
			HX_STACK_LINE(375)
			u->SetInt4Array(p_list);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetInt4Array,(void))

::haxor::graphics::material::MaterialUniform Material_obj::GetUniform( ::String p_name){
	HX_STACK_FRAME("haxor.graphics.material.Material","GetUniform",0xf65122b5,"haxor.graphics.material.Material.GetUniform","haxor/graphics/material/Material.hx",383,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(384)
	{
		HX_STACK_LINE(384)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(384)
		int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(384)
		while((true)){
			HX_STACK_LINE(384)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(384)
				break;
			}
			HX_STACK_LINE(384)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(384)
			if (((this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >()->name == p_name))){
				HX_STACK_LINE(384)
				return this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >();
			}
		}
	}
	HX_STACK_LINE(385)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,GetUniform,return )

bool Material_obj::HasUniform( ::String p_name,hx::Null< bool >  __o_p_check_shader){
bool p_check_shader = __o_p_check_shader.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","HasUniform",0x31a38471,"haxor.graphics.material.Material.HasUniform","haxor/graphics/material/Material.hx",395,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_check_shader,"p_check_shader")
{
		HX_STACK_LINE(396)
		{
			HX_STACK_LINE(396)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(396)
			int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(396)
			while((true)){
				HX_STACK_LINE(396)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(396)
					break;
				}
				HX_STACK_LINE(396)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(398)
				if (((this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >()->name == p_name))){
					HX_STACK_LINE(400)
					if ((p_check_shader)){
						HX_STACK_LINE(400)
						return this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >()->exists;
					}
					HX_STACK_LINE(401)
					return true;
				}
			}
		}
		HX_STACK_LINE(404)
		return false;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,HasUniform,return )

Void Material_obj::RemoveUniform( ::String p_name){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","RemoveUniform",0x5a868639,"haxor.graphics.material.Material.RemoveUniform","haxor/graphics/material/Material.hx",412,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_LINE(413)
		::haxor::graphics::material::MaterialUniform u = null();		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(414)
		{
			HX_STACK_LINE(414)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(414)
			int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(414)
			while((true)){
				HX_STACK_LINE(414)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(414)
					break;
				}
				HX_STACK_LINE(414)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(416)
				u = this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >();
				HX_STACK_LINE(417)
				if (((u->name == p_name))){
					HX_STACK_LINE(417)
					break;
				}
			}
		}
		HX_STACK_LINE(419)
		if (((u != null()))){
			HX_STACK_LINE(421)
			::haxor::context::EngineContext_obj::material->DestroyUniform(hx::ObjectPtr<OBJ_>(this),u);
			HX_STACK_LINE(422)
			this->m_uniforms->remove(u);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,RemoveUniform,(void))

::haxor::graphics::material::MaterialUniform Material_obj::FetchUniform( ::String p_name,bool p_is_float,int p_length,int p_offset,bool p_create){
	HX_STACK_FRAME("haxor.graphics.material.Material","FetchUniform",0x6e061751,"haxor.graphics.material.Material.FetchUniform","haxor/graphics/material/Material.hx",433,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_ARG(p_is_float,"p_is_float")
	HX_STACK_ARG(p_length,"p_length")
	HX_STACK_ARG(p_offset,"p_offset")
	HX_STACK_ARG(p_create,"p_create")
	HX_STACK_LINE(434)
	::haxor::graphics::material::MaterialUniform u = null();		HX_STACK_VAR(u,"u");
	HX_STACK_LINE(435)
	{
		HX_STACK_LINE(435)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(435)
		int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(435)
		while((true)){
			HX_STACK_LINE(435)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(435)
				break;
			}
			HX_STACK_LINE(435)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(437)
			u = this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >();
			HX_STACK_LINE(438)
			if (((u->name == p_name))){
				HX_STACK_LINE(440)
				if (((u->isFloat == p_is_float))){
					HX_STACK_LINE(442)
					if (((u->offset == p_offset))){
						HX_STACK_LINE(444)
						if (((u->data->m_length == p_length))){
							HX_STACK_LINE(445)
							return u;
						}
					}
				}
				HX_STACK_LINE(449)
				::haxor::context::EngineContext_obj::material->DestroyUniform(hx::ObjectPtr<OBJ_>(this),u);
				HX_STACK_LINE(450)
				this->m_uniforms->remove(u);
				HX_STACK_LINE(451)
				break;
			}
		}
	}
	HX_STACK_LINE(454)
	if ((p_create)){
		HX_STACK_LINE(456)
		::haxor::graphics::material::MaterialUniform _g = ::haxor::graphics::material::MaterialUniform_obj::__new(p_name,p_is_float,p_length,p_offset);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(456)
		u = _g;
		HX_STACK_LINE(457)
		::haxor::context::EngineContext_obj::material->CreateUniform(hx::ObjectPtr<OBJ_>(this),u);
		HX_STACK_LINE(458)
		this->m_uniforms->push(u);
	}
	HX_STACK_LINE(460)
	return u;
}


HX_DEFINE_DYNAMIC_FUNC5(Material_obj,FetchUniform,return )

Void Material_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","OnDestroy",0xc505e604,"haxor.graphics.material.Material.OnDestroy","haxor/graphics/material/Material.hx",495,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(495)
		::haxor::context::MaterialContext _this = ::haxor::context::EngineContext_obj::material;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(495)
		int p = _this->programs->__get(this->__cid);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(495)
		if (((this->m_shader != null()))){
			HX_STACK_LINE(495)
			::haxor::graphics::GL_obj::m_gl->DetachShader(p,_this->vertex_shaders->__get(this->m_shader->__cid));
			HX_STACK_LINE(495)
			::haxor::graphics::GL_obj::m_gl->DetachShader(p,_this->fragment_shaders->__get(this->m_shader->__cid));
		}
		HX_STACK_LINE(495)
		::haxor::graphics::GL_obj::m_gl->DeleteProgram(p);
		HX_STACK_LINE(495)
		{
			HX_STACK_LINE(495)
			int v = this->__cid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(495)
			::haxor::context::EngineContext_obj::material->mid->m_cache->push(v);
			HX_STACK_LINE(495)
			v;
		}
		HX_STACK_LINE(495)
		{
			HX_STACK_LINE(495)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(495)
			int _g = this->m_uniforms->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(495)
			while((true)){
				HX_STACK_LINE(495)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(495)
					break;
				}
				HX_STACK_LINE(495)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(495)
				int v = this->m_uniforms->__get(i).StaticCast< ::haxor::graphics::material::MaterialUniform >()->__cid;		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(495)
				_this->uid->m_cache->push(v);
				HX_STACK_LINE(495)
				v;
			}
		}
	}
return null();
}


::haxor::graphics::material::Material Material_obj::Transparent( ::haxor::graphics::texture::Texture p_texture,hx::Null< bool >  __o_p_ztest,hx::Null< bool >  __o_p_zwrite,hx::Null< bool >  __o_p_double_sided){
bool p_ztest = __o_p_ztest.Default(true);
bool p_zwrite = __o_p_zwrite.Default(true);
bool p_double_sided = __o_p_double_sided.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","Transparent",0x8b1ed7fb,"haxor.graphics.material.Material.Transparent","haxor/graphics/material/Material.hx",38,0xe49118e6)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_ARG(p_ztest,"p_ztest")
	HX_STACK_ARG(p_zwrite,"p_zwrite")
	HX_STACK_ARG(p_double_sided,"p_double_sided")
{
		HX_STACK_LINE(39)
		::haxor::graphics::material::Material m = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Transparent"));		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(40)
		if ((p_double_sided)){
			HX_STACK_LINE(40)
			m->cull = (int)0;
		}
		HX_STACK_LINE(41)
		m->SetBlending((int)770,(int)771);
		HX_STACK_LINE(42)
		::haxor::graphics::material::Shader _g2;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(42)
		if (((p_texture == null()))){
			HX_STACK_LINE(42)
			if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
				HX_STACK_LINE(42)
				::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(42)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g;
			}
			else{
				HX_STACK_LINE(42)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
			}
		}
		else{
			HX_STACK_LINE(42)
			if (((::haxor::graphics::material::Shader_obj::m_flat_texture_shader == null()))){
				HX_STACK_LINE(42)
				::haxor::graphics::material::Shader _g1 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_texture_source);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(42)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader = _g1;
			}
			else{
				HX_STACK_LINE(42)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader;
			}
		}
		HX_STACK_LINE(42)
		m->set_shader(_g2);
		HX_STACK_LINE(43)
		m->queue = (int)2000;
		HX_STACK_LINE(44)
		m->ztest = p_ztest;
		HX_STACK_LINE(45)
		m->zwrite = p_zwrite;
		HX_STACK_LINE(46)
		m->blend = true;
		HX_STACK_LINE(47)
		if (((p_texture != null()))){
			HX_STACK_LINE(47)
			m->SetTexture(HX_CSTRING("DiffuseTexture"),p_texture);
		}
		HX_STACK_LINE(48)
		return m;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Material_obj,Transparent,return )

::haxor::graphics::material::Material Material_obj::AdditiveAlpha( ::haxor::graphics::texture::Texture p_texture,hx::Null< bool >  __o_p_ztest,hx::Null< bool >  __o_p_zwrite,hx::Null< bool >  __o_p_double_sided){
bool p_ztest = __o_p_ztest.Default(true);
bool p_zwrite = __o_p_zwrite.Default(true);
bool p_double_sided = __o_p_double_sided.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","AdditiveAlpha",0x6b54019b,"haxor.graphics.material.Material.AdditiveAlpha","haxor/graphics/material/Material.hx",59,0xe49118e6)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_ARG(p_ztest,"p_ztest")
	HX_STACK_ARG(p_zwrite,"p_zwrite")
	HX_STACK_ARG(p_double_sided,"p_double_sided")
{
		HX_STACK_LINE(60)
		::haxor::graphics::material::Material m;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(60)
		{
			HX_STACK_LINE(60)
			::haxor::graphics::material::Material m1 = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Transparent"));		HX_STACK_VAR(m1,"m1");
			HX_STACK_LINE(60)
			if ((p_double_sided)){
				HX_STACK_LINE(60)
				m1->cull = (int)0;
			}
			HX_STACK_LINE(60)
			m1->SetBlending((int)770,(int)771);
			HX_STACK_LINE(60)
			::haxor::graphics::material::Shader _g2;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(60)
			if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
				HX_STACK_LINE(60)
				::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(60)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g;
			}
			else{
				HX_STACK_LINE(60)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
			}
			HX_STACK_LINE(60)
			m1->set_shader(_g2);
			HX_STACK_LINE(60)
			m1->queue = (int)2000;
			HX_STACK_LINE(60)
			m1->ztest = p_ztest;
			HX_STACK_LINE(60)
			m1->zwrite = p_zwrite;
			HX_STACK_LINE(60)
			m1->blend = true;
			HX_STACK_LINE(60)
			m = m1;
		}
		HX_STACK_LINE(61)
		m->set_name(HX_CSTRING("AdditiveAlpha"));
		HX_STACK_LINE(62)
		m->SetBlending((int)770,(int)1);
		HX_STACK_LINE(63)
		return m;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Material_obj,AdditiveAlpha,return )

::haxor::graphics::material::Material Material_obj::Additive( ::haxor::graphics::texture::Texture p_texture,hx::Null< bool >  __o_p_ztest,hx::Null< bool >  __o_p_zwrite,hx::Null< bool >  __o_p_double_sided){
bool p_ztest = __o_p_ztest.Default(true);
bool p_zwrite = __o_p_zwrite.Default(true);
bool p_double_sided = __o_p_double_sided.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.Material","Additive",0x7fd232c3,"haxor.graphics.material.Material.Additive","haxor/graphics/material/Material.hx",74,0xe49118e6)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_ARG(p_ztest,"p_ztest")
	HX_STACK_ARG(p_zwrite,"p_zwrite")
	HX_STACK_ARG(p_double_sided,"p_double_sided")
{
		HX_STACK_LINE(75)
		::haxor::graphics::material::Material m;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(75)
		{
			HX_STACK_LINE(75)
			::haxor::graphics::material::Material m1 = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Transparent"));		HX_STACK_VAR(m1,"m1");
			HX_STACK_LINE(75)
			if ((p_double_sided)){
				HX_STACK_LINE(75)
				m1->cull = (int)0;
			}
			HX_STACK_LINE(75)
			m1->SetBlending((int)770,(int)771);
			HX_STACK_LINE(75)
			::haxor::graphics::material::Shader _g2;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(75)
			if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
				HX_STACK_LINE(75)
				::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(75)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g;
			}
			else{
				HX_STACK_LINE(75)
				_g2 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
			}
			HX_STACK_LINE(75)
			m1->set_shader(_g2);
			HX_STACK_LINE(75)
			m1->queue = (int)2000;
			HX_STACK_LINE(75)
			m1->ztest = p_ztest;
			HX_STACK_LINE(75)
			m1->zwrite = p_zwrite;
			HX_STACK_LINE(75)
			m1->blend = true;
			HX_STACK_LINE(75)
			m = m1;
		}
		HX_STACK_LINE(76)
		m->set_name(HX_CSTRING("Additive"));
		HX_STACK_LINE(77)
		m->SetBlending((int)1,(int)1);
		HX_STACK_LINE(78)
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
