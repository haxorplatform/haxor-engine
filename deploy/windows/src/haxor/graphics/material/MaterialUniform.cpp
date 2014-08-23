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
namespace haxor{
namespace graphics{
namespace material{

Void MaterialUniform_obj::__construct(::String p_name,bool p_is_float,int p_length,int p_offset)
{
HX_STACK_FRAME("haxor.graphics.material.MaterialUniform","new",0x09c035af,"haxor.graphics.material.MaterialUniform.new","haxor/graphics/material/Material.hx",438,0xe49118e6)
HX_STACK_THIS(this)
HX_STACK_ARG(p_name,"p_name")
HX_STACK_ARG(p_is_float,"p_is_float")
HX_STACK_ARG(p_length,"p_length")
HX_STACK_ARG(p_offset,"p_offset")
{
	HX_STACK_LINE(439)
	int _g = (::haxor::context::EngineContext_obj::material->uid)++;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(439)
	this->__cid = _g;
	HX_STACK_LINE(440)
	this->__d = true;
	HX_STACK_LINE(441)
	this->name = p_name;
	HX_STACK_LINE(442)
	this->isFloat = p_is_float;
	HX_STACK_LINE(443)
	this->offset = p_offset;
	HX_STACK_LINE(444)
	if ((p_is_float)){
		HX_STACK_LINE(446)
		::haxor::io::FloatArray _g1 = ::haxor::io::FloatArray_obj::__new(p_length);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(446)
		this->data = _g1;
	}
	else{
		HX_STACK_LINE(450)
		::haxor::io::Int32Array _g2 = ::haxor::io::Int32Array_obj::__new(p_length);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(450)
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
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"texture") ) { return texture; }
		if (HX_FIELD_EQ(inName,"isFloat") ) { return isFloat; }
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
