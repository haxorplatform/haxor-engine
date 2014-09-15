#include <hxcpp.h>

#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_MaterialContext
#include <haxor/context/MaterialContext.h>
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
#ifndef INCLUDED_haxor_graphics_material_MaterialUniform
#include <haxor/graphics/material/MaterialUniform.h>
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

Void MaterialUniform_obj::__construct(::String p_name,bool p_is_float,int p_length,int p_offset)
{
HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","new",0x09c035af,"haxor.graphics.material.MaterialUniform.new","haxor/graphics/material/Material.hx",572,0xe49118e6)
HX_STACK_THIS(this)
HX_STACK_ARG(p_name,"p_name")
HX_STACK_ARG(p_is_float,"p_is_float")
HX_STACK_ARG(p_length,"p_length")
HX_STACK_ARG(p_offset,"p_offset")
{
	HX_STACK_LINE(573)
	int _g;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(573)
	{
		HX_STACK_LINE(573)
		::haxor::context::UID _this = ::haxor::context::EngineContext_obj::material->uid;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(573)
		if (((_this->m_cache->length <= (int)0))){
			HX_STACK_LINE(573)
			_g = (_this->m_id)++;
		}
		else{
			HX_STACK_LINE(573)
			_g = _this->m_cache->shift();
		}
	}
	HX_STACK_LINE(573)
	this->__cid = _g;
	HX_STACK_LINE(574)
	this->__d = true;
	HX_STACK_LINE(575)
	this->name = p_name;
	HX_STACK_LINE(576)
	this->isFloat = p_is_float;
	HX_STACK_LINE(577)
	this->offset = p_offset;
	HX_STACK_LINE(578)
	this->exists = false;
	HX_STACK_LINE(579)
	if ((p_is_float)){
		HX_STACK_LINE(581)
		::haxor::io::FloatArray _g1 = ::haxor::io::FloatArray_obj::__new(p_length);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(581)
		this->data = _g1;
	}
	else{
		HX_STACK_LINE(585)
		::haxor::io::Int32Array _g2 = ::haxor::io::Int32Array_obj::__new(p_length);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(585)
		this->data = _g2;
	}
}
;
	return null();
}

//MaterialUniform_obj::~MaterialUniform_obj() { }

Dynamic MaterialUniform_obj::__CreateEmpty() { return  new MaterialUniform_obj; }
hx::ObjectPtr< MaterialUniform_obj > MaterialUniform_obj::__new(::String p_name,bool p_is_float,int p_length,int p_offset)
{  hx::ObjectPtr< MaterialUniform_obj > result = new MaterialUniform_obj();
	result->__construct(p_name,p_is_float,p_length,p_offset);
	return result;}

Dynamic MaterialUniform_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MaterialUniform_obj > result = new MaterialUniform_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void MaterialUniform_obj::SetFloat( Float p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetFloat",0xdb33e70b,"haxor.graphics.material.MaterialUniform.SetFloat","haxor/graphics/material/Material.hx",589,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(589)
		if ((!(this->exists))){
			HX_STACK_LINE(589)
			return null();
		}
		HX_STACK_LINE(589)
		this->__d = true;
		HX_STACK_LINE(589)
		::haxor::io::FloatArray b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(589)
		b->Set((int)0,p_v);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetFloat,(void))

Void MaterialUniform_obj::SetFloat2( Float p_x,Float p_y){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetFloat2",0xf23642c7,"haxor.graphics.material.MaterialUniform.SetFloat2","haxor/graphics/material/Material.hx",590,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(590)
		if ((!(this->exists))){
			HX_STACK_LINE(590)
			return null();
		}
		HX_STACK_LINE(590)
		this->__d = true;
		HX_STACK_LINE(590)
		::haxor::io::FloatArray b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(590)
		b->Set((int)0,p_x);
		HX_STACK_LINE(590)
		b->Set((int)1,p_y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MaterialUniform_obj,SetFloat2,(void))

Void MaterialUniform_obj::SetFloat3( Float p_x,Float p_y,Float p_z){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetFloat3",0xf23642c8,"haxor.graphics.material.MaterialUniform.SetFloat3","haxor/graphics/material/Material.hx",591,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(591)
		if ((!(this->exists))){
			HX_STACK_LINE(591)
			return null();
		}
		HX_STACK_LINE(591)
		this->__d = true;
		HX_STACK_LINE(591)
		::haxor::io::FloatArray b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(591)
		b->Set((int)0,p_x);
		HX_STACK_LINE(591)
		b->Set((int)1,p_y);
		HX_STACK_LINE(591)
		b->Set((int)2,p_z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(MaterialUniform_obj,SetFloat3,(void))

Void MaterialUniform_obj::SetFloat4( Float p_x,Float p_y,Float p_z,Float p_w){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetFloat4",0xf23642c9,"haxor.graphics.material.MaterialUniform.SetFloat4","haxor/graphics/material/Material.hx",592,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(592)
		if ((!(this->exists))){
			HX_STACK_LINE(592)
			return null();
		}
		HX_STACK_LINE(592)
		this->__d = true;
		HX_STACK_LINE(592)
		::haxor::io::FloatArray b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(592)
		b->Set((int)0,p_x);
		HX_STACK_LINE(592)
		b->Set((int)1,p_y);
		HX_STACK_LINE(592)
		b->Set((int)2,p_z);
		HX_STACK_LINE(592)
		b->Set((int)3,p_w);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(MaterialUniform_obj,SetFloat4,(void))

Void MaterialUniform_obj::SetFloatArray( Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetFloatArray",0x3af08e8e,"haxor.graphics.material.MaterialUniform.SetFloatArray","haxor/graphics/material/Material.hx",593,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(593)
		if ((!(this->exists))){
			HX_STACK_LINE(593)
			return null();
		}
		HX_STACK_LINE(593)
		this->__d = true;
		HX_STACK_LINE(593)
		::haxor::io::FloatArray b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(593)
		{
			HX_STACK_LINE(593)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(593)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(593)
			while((true)){
				HX_STACK_LINE(593)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(593)
					break;
				}
				HX_STACK_LINE(593)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(593)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetFloatArray,(void))

Void MaterialUniform_obj::SetFloat2Array( Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetFloat2Array",0x219c2952,"haxor.graphics.material.MaterialUniform.SetFloat2Array","haxor/graphics/material/Material.hx",594,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(594)
		if ((!(this->exists))){
			HX_STACK_LINE(594)
			return null();
		}
		HX_STACK_LINE(594)
		this->__d = true;
		HX_STACK_LINE(594)
		::haxor::io::FloatArray b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(594)
		{
			HX_STACK_LINE(594)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(594)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(594)
			while((true)){
				HX_STACK_LINE(594)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(594)
					break;
				}
				HX_STACK_LINE(594)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(594)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetFloat2Array,(void))

Void MaterialUniform_obj::SetFloat3Array( Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetFloat3Array",0x87f785b1,"haxor.graphics.material.MaterialUniform.SetFloat3Array","haxor/graphics/material/Material.hx",595,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(595)
		if ((!(this->exists))){
			HX_STACK_LINE(595)
			return null();
		}
		HX_STACK_LINE(595)
		this->__d = true;
		HX_STACK_LINE(595)
		::haxor::io::FloatArray b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(595)
		{
			HX_STACK_LINE(595)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(595)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(595)
			while((true)){
				HX_STACK_LINE(595)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(595)
					break;
				}
				HX_STACK_LINE(595)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(595)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetFloat3Array,(void))

Void MaterialUniform_obj::SetFloat4Array( Array< Float > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetFloat4Array",0xee52e210,"haxor.graphics.material.MaterialUniform.SetFloat4Array","haxor/graphics/material/Material.hx",596,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(596)
		if ((!(this->exists))){
			HX_STACK_LINE(596)
			return null();
		}
		HX_STACK_LINE(596)
		this->__d = true;
		HX_STACK_LINE(596)
		::haxor::io::FloatArray b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(596)
		{
			HX_STACK_LINE(596)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(596)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(596)
			while((true)){
				HX_STACK_LINE(596)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(596)
					break;
				}
				HX_STACK_LINE(596)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(596)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetFloat4Array,(void))

Void MaterialUniform_obj::SetInt( int p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetInt",0x3cd4a49e,"haxor.graphics.material.MaterialUniform.SetInt","haxor/graphics/material/Material.hx",598,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(598)
		if ((!(this->exists))){
			HX_STACK_LINE(598)
			return null();
		}
		HX_STACK_LINE(598)
		this->__d = true;
		HX_STACK_LINE(598)
		::haxor::io::Int32Array b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(598)
		b->Set((int)0,p_v);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetInt,(void))

Void MaterialUniform_obj::SetInt2( int p_x,int p_y){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetInt2",0xfd3b65d4,"haxor.graphics.material.MaterialUniform.SetInt2","haxor/graphics/material/Material.hx",599,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(599)
		if ((!(this->exists))){
			HX_STACK_LINE(599)
			return null();
		}
		HX_STACK_LINE(599)
		this->__d = true;
		HX_STACK_LINE(599)
		::haxor::io::Int32Array b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(599)
		b->Set((int)0,p_x);
		HX_STACK_LINE(599)
		b->Set((int)1,p_y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MaterialUniform_obj,SetInt2,(void))

Void MaterialUniform_obj::SetInt3( int p_x,int p_y,int p_z){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetInt3",0xfd3b65d5,"haxor.graphics.material.MaterialUniform.SetInt3","haxor/graphics/material/Material.hx",600,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(600)
		if ((!(this->exists))){
			HX_STACK_LINE(600)
			return null();
		}
		HX_STACK_LINE(600)
		this->__d = true;
		HX_STACK_LINE(600)
		::haxor::io::Int32Array b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(600)
		b->Set((int)0,p_x);
		HX_STACK_LINE(600)
		b->Set((int)1,p_y);
		HX_STACK_LINE(600)
		b->Set((int)2,p_z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(MaterialUniform_obj,SetInt3,(void))

Void MaterialUniform_obj::SetInt4( int p_x,int p_y,int p_z,int p_w){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetInt4",0xfd3b65d6,"haxor.graphics.material.MaterialUniform.SetInt4","haxor/graphics/material/Material.hx",601,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(601)
		if ((!(this->exists))){
			HX_STACK_LINE(601)
			return null();
		}
		HX_STACK_LINE(601)
		this->__d = true;
		HX_STACK_LINE(601)
		::haxor::io::Int32Array b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(601)
		b->Set((int)0,p_x);
		HX_STACK_LINE(601)
		b->Set((int)1,p_y);
		HX_STACK_LINE(601)
		b->Set((int)2,p_z);
		HX_STACK_LINE(601)
		b->Set((int)3,p_w);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(MaterialUniform_obj,SetInt4,(void))

Void MaterialUniform_obj::SetIntArray( Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetIntArray",0x2ef8bc1b,"haxor.graphics.material.MaterialUniform.SetIntArray","haxor/graphics/material/Material.hx",602,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(602)
		if ((!(this->exists))){
			HX_STACK_LINE(602)
			return null();
		}
		HX_STACK_LINE(602)
		this->__d = true;
		HX_STACK_LINE(602)
		::haxor::io::Int32Array b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(602)
		{
			HX_STACK_LINE(602)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(602)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(602)
			while((true)){
				HX_STACK_LINE(602)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(602)
					break;
				}
				HX_STACK_LINE(602)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(602)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetIntArray,(void))

Void MaterialUniform_obj::SetInt2Array( Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetInt2Array",0xb4bbd725,"haxor.graphics.material.MaterialUniform.SetInt2Array","haxor/graphics/material/Material.hx",603,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(603)
		if ((!(this->exists))){
			HX_STACK_LINE(603)
			return null();
		}
		HX_STACK_LINE(603)
		this->__d = true;
		HX_STACK_LINE(603)
		::haxor::io::Int32Array b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(603)
		{
			HX_STACK_LINE(603)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(603)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(603)
			while((true)){
				HX_STACK_LINE(603)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(603)
					break;
				}
				HX_STACK_LINE(603)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(603)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetInt2Array,(void))

Void MaterialUniform_obj::SetInt3Array( Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetInt3Array",0x1b173384,"haxor.graphics.material.MaterialUniform.SetInt3Array","haxor/graphics/material/Material.hx",604,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(604)
		if ((!(this->exists))){
			HX_STACK_LINE(604)
			return null();
		}
		HX_STACK_LINE(604)
		this->__d = true;
		HX_STACK_LINE(604)
		::haxor::io::Int32Array b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(604)
		{
			HX_STACK_LINE(604)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(604)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(604)
			while((true)){
				HX_STACK_LINE(604)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(604)
					break;
				}
				HX_STACK_LINE(604)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(604)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetInt3Array,(void))

Void MaterialUniform_obj::SetInt4Array( Array< int > p_list){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetInt4Array",0x81728fe3,"haxor.graphics.material.MaterialUniform.SetInt4Array","haxor/graphics/material/Material.hx",605,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_list,"p_list")
		HX_STACK_LINE(605)
		if ((!(this->exists))){
			HX_STACK_LINE(605)
			return null();
		}
		HX_STACK_LINE(605)
		this->__d = true;
		HX_STACK_LINE(605)
		::haxor::io::Int32Array b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(605)
		{
			HX_STACK_LINE(605)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(605)
			int _g = p_list->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(605)
			while((true)){
				HX_STACK_LINE(605)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(605)
					break;
				}
				HX_STACK_LINE(605)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(605)
				b->Set(i,p_list->__get(i));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetInt4Array,(void))

Void MaterialUniform_obj::SetTexture( ::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetTexture",0xb21c640a,"haxor.graphics.material.MaterialUniform.SetTexture","haxor/graphics/material/Material.hx",608,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_texture,"p_texture")
		HX_STACK_LINE(609)
		if ((!(this->exists))){
			HX_STACK_LINE(609)
			return null();
		}
		HX_STACK_LINE(610)
		this->__d = true;
		HX_STACK_LINE(611)
		::haxor::io::Int32Array b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(612)
		b->Set((int)0,p_texture->__slot);
		HX_STACK_LINE(613)
		this->texture = p_texture;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetTexture,(void))

Void MaterialUniform_obj::SetMatrix4( ::haxor::math::Matrix4 m,hx::Null< bool >  __o_t){
bool t = __o_t.Default(false);
	HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetMatrix4",0xa6a2de02,"haxor.graphics.material.MaterialUniform.SetMatrix4","haxor/graphics/material/Material.hx",617,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(m,"m")
	HX_STACK_ARG(t,"t")
{
		HX_STACK_LINE(618)
		if ((!(this->exists))){
			HX_STACK_LINE(618)
			return null();
		}
		HX_STACK_LINE(618)
		this->__d = true;
		HX_STACK_LINE(619)
		::haxor::io::FloatArray b = this->data;		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(621)
		if ((!(t))){
			HX_STACK_LINE(623)
			b->Set((int)0,m->m00);
			HX_STACK_LINE(623)
			b->Set((int)1,m->m01);
			HX_STACK_LINE(623)
			b->Set((int)2,m->m02);
			HX_STACK_LINE(623)
			b->Set((int)3,m->m03);
			HX_STACK_LINE(624)
			b->Set((int)4,m->m10);
			HX_STACK_LINE(624)
			b->Set((int)5,m->m11);
			HX_STACK_LINE(624)
			b->Set((int)6,m->m12);
			HX_STACK_LINE(624)
			b->Set((int)7,m->m13);
			HX_STACK_LINE(625)
			b->Set((int)8,m->m20);
			HX_STACK_LINE(625)
			b->Set((int)9,m->m21);
			HX_STACK_LINE(625)
			b->Set((int)10,m->m22);
			HX_STACK_LINE(625)
			b->Set((int)11,m->m23);
			HX_STACK_LINE(626)
			b->Set((int)12,m->m30);
			HX_STACK_LINE(626)
			b->Set((int)13,m->m31);
			HX_STACK_LINE(626)
			b->Set((int)14,m->m32);
			HX_STACK_LINE(626)
			b->Set((int)15,m->m33);
		}
		else{
			HX_STACK_LINE(630)
			b->Set((int)0,m->m00);
			HX_STACK_LINE(630)
			b->Set((int)1,m->m10);
			HX_STACK_LINE(630)
			b->Set((int)2,m->m20);
			HX_STACK_LINE(630)
			b->Set((int)3,m->m30);
			HX_STACK_LINE(631)
			b->Set((int)4,m->m01);
			HX_STACK_LINE(631)
			b->Set((int)5,m->m11);
			HX_STACK_LINE(631)
			b->Set((int)6,m->m21);
			HX_STACK_LINE(631)
			b->Set((int)7,m->m31);
			HX_STACK_LINE(632)
			b->Set((int)8,m->m02);
			HX_STACK_LINE(632)
			b->Set((int)9,m->m12);
			HX_STACK_LINE(632)
			b->Set((int)10,m->m22);
			HX_STACK_LINE(632)
			b->Set((int)11,m->m32);
			HX_STACK_LINE(633)
			b->Set((int)12,m->m03);
			HX_STACK_LINE(633)
			b->Set((int)13,m->m13);
			HX_STACK_LINE(633)
			b->Set((int)14,m->m23);
			HX_STACK_LINE(633)
			b->Set((int)15,m->m33);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(MaterialUniform_obj,SetMatrix4,(void))

Void MaterialUniform_obj::SetVector2( ::haxor::math::Vector2 p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetVector2",0xedd8953e,"haxor.graphics.material.MaterialUniform.SetVector2","haxor/graphics/material/Material.hx",637,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(637)
		this->SetFloat2(p_v->x,p_v->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetVector2,(void))

Void MaterialUniform_obj::SetVector3( ::haxor::math::Vector3 p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetVector3",0xedd8953f,"haxor.graphics.material.MaterialUniform.SetVector3","haxor/graphics/material/Material.hx",638,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(638)
		this->SetFloat3(p_v->x,p_v->y,p_v->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetVector3,(void))

Void MaterialUniform_obj::SetVector4( ::haxor::math::Vector4 p_v){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetVector4",0xedd89540,"haxor.graphics.material.MaterialUniform.SetVector4","haxor/graphics/material/Material.hx",639,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(639)
		this->SetFloat4(p_v->x,p_v->y,p_v->z,p_v->w);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetVector4,(void))

Void MaterialUniform_obj::SetColor( ::haxor::math::Color p_color){
{
		HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","SetColor",0x22f992d2,"haxor.graphics.material.MaterialUniform.SetColor","haxor/graphics/material/Material.hx",640,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_color,"p_color")
		HX_STACK_LINE(640)
		this->SetFloat4(p_color->r,p_color->g,p_color->b,p_color->a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialUniform_obj,SetColor,(void))


MaterialUniform_obj::MaterialUniform_obj()
{
}

void MaterialUniform_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MaterialUniform);
	HX_MARK_MEMBER_NAME(__cid,"__cid");
	HX_MARK_MEMBER_NAME(__d,"__d");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(offset,"offset");
	HX_MARK_MEMBER_NAME(texture,"texture");
	HX_MARK_MEMBER_NAME(isFloat,"isFloat");
	HX_MARK_MEMBER_NAME(exists,"exists");
	HX_MARK_END_CLASS();
}

void MaterialUniform_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__cid,"__cid");
	HX_VISIT_MEMBER_NAME(__d,"__d");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(offset,"offset");
	HX_VISIT_MEMBER_NAME(texture,"texture");
	HX_VISIT_MEMBER_NAME(isFloat,"isFloat");
	HX_VISIT_MEMBER_NAME(exists,"exists");
}

Dynamic MaterialUniform_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__d") ) { return __d; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"__cid") ) { return __cid; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { return offset; }
		if (HX_FIELD_EQ(inName,"exists") ) { return exists; }
		if (HX_FIELD_EQ(inName,"SetInt") ) { return SetInt_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { return texture; }
		if (HX_FIELD_EQ(inName,"isFloat") ) { return isFloat; }
		if (HX_FIELD_EQ(inName,"SetInt2") ) { return SetInt2_dyn(); }
		if (HX_FIELD_EQ(inName,"SetInt3") ) { return SetInt3_dyn(); }
		if (HX_FIELD_EQ(inName,"SetInt4") ) { return SetInt4_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"SetFloat") ) { return SetFloat_dyn(); }
		if (HX_FIELD_EQ(inName,"SetColor") ) { return SetColor_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"SetFloat2") ) { return SetFloat2_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloat3") ) { return SetFloat3_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloat4") ) { return SetFloat4_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"SetTexture") ) { return SetTexture_dyn(); }
		if (HX_FIELD_EQ(inName,"SetMatrix4") ) { return SetMatrix4_dyn(); }
		if (HX_FIELD_EQ(inName,"SetVector2") ) { return SetVector2_dyn(); }
		if (HX_FIELD_EQ(inName,"SetVector3") ) { return SetVector3_dyn(); }
		if (HX_FIELD_EQ(inName,"SetVector4") ) { return SetVector4_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SetIntArray") ) { return SetIntArray_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"SetInt2Array") ) { return SetInt2Array_dyn(); }
		if (HX_FIELD_EQ(inName,"SetInt3Array") ) { return SetInt3Array_dyn(); }
		if (HX_FIELD_EQ(inName,"SetInt4Array") ) { return SetInt4Array_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"SetFloatArray") ) { return SetFloatArray_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"SetFloat2Array") ) { return SetFloat2Array_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloat3Array") ) { return SetFloat3Array_dyn(); }
		if (HX_FIELD_EQ(inName,"SetFloat4Array") ) { return SetFloat4Array_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MaterialUniform_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__d") ) { __d=inValue.Cast< bool >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::haxor::io::Buffer >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"__cid") ) { __cid=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { offset=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"exists") ) { exists=inValue.Cast< bool >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { texture=inValue.Cast< ::haxor::graphics::texture::Texture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isFloat") ) { isFloat=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MaterialUniform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__cid"));
	outFields->push(HX_CSTRING("__d"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("offset"));
	outFields->push(HX_CSTRING("texture"));
	outFields->push(HX_CSTRING("isFloat"));
	outFields->push(HX_CSTRING("exists"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(MaterialUniform_obj,__cid),HX_CSTRING("__cid")},
	{hx::fsBool,(int)offsetof(MaterialUniform_obj,__d),HX_CSTRING("__d")},
	{hx::fsString,(int)offsetof(MaterialUniform_obj,name),HX_CSTRING("name")},
	{hx::fsObject /*::haxor::io::Buffer*/ ,(int)offsetof(MaterialUniform_obj,data),HX_CSTRING("data")},
	{hx::fsInt,(int)offsetof(MaterialUniform_obj,offset),HX_CSTRING("offset")},
	{hx::fsObject /*::haxor::graphics::texture::Texture*/ ,(int)offsetof(MaterialUniform_obj,texture),HX_CSTRING("texture")},
	{hx::fsBool,(int)offsetof(MaterialUniform_obj,isFloat),HX_CSTRING("isFloat")},
	{hx::fsBool,(int)offsetof(MaterialUniform_obj,exists),HX_CSTRING("exists")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("__cid"),
	HX_CSTRING("__d"),
	HX_CSTRING("name"),
	HX_CSTRING("data"),
	HX_CSTRING("offset"),
	HX_CSTRING("texture"),
	HX_CSTRING("isFloat"),
	HX_CSTRING("exists"),
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
	HX_CSTRING("SetTexture"),
	HX_CSTRING("SetMatrix4"),
	HX_CSTRING("SetVector2"),
	HX_CSTRING("SetVector3"),
	HX_CSTRING("SetVector4"),
	HX_CSTRING("SetColor"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MaterialUniform_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MaterialUniform_obj::__mClass,"__mClass");
};

#endif

Class MaterialUniform_obj::__mClass;

void MaterialUniform_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.material.MaterialUniform"), hx::TCanCast< MaterialUniform_obj> ,sStaticFields,sMemberFields,
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

void MaterialUniform_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace material
