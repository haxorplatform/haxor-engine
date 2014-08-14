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
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Shader
#include <haxor/graphics/material/Shader.h>
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
namespace graphics{
namespace material{

Void Material_obj::__construct(::String p_name)
{
HX_STACK_FRAME("haxor.graphics.material.Material","new",0xec1f7429,"haxor.graphics.material.Material.new","haxor/graphics/material/Material.hx",18,0xe49118e6)
HX_STACK_THIS(this)
HX_STACK_ARG(p_name,"p_name")
{
	HX_STACK_LINE(84)
	this->grab = false;
	HX_STACK_LINE(102)
	super::__construct(p_name);
	HX_STACK_LINE(103)
	int _g = (::haxor::context::EngineContext_obj::material->mid)++;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(103)
	this->_cid_ = _g;
	HX_STACK_LINE(105)
	this->queue = (int)1000;
	HX_STACK_LINE(106)
	this->zfunc = (int)515;
	HX_STACK_LINE(107)
	this->ztest = true;
	HX_STACK_LINE(108)
	this->zwrite = true;
	HX_STACK_LINE(109)
	this->blend = false;
	HX_STACK_LINE(110)
	this->blendSrc = (int)1;
	HX_STACK_LINE(111)
	this->blendDst = (int)0;
	HX_STACK_LINE(112)
	this->invert = false;
	HX_STACK_LINE(113)
	this->cull = (int)2;
	HX_STACK_LINE(114)
	this->lighting = false;
	HX_STACK_LINE(115)
	this->grab = false;
	HX_STACK_LINE(117)
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
	HX_STACK_FRAME("haxor.graphics.material.Material","get_shader",0x08828645,"haxor.graphics.material.Material.get_shader","haxor/graphics/material/Material.hx",90,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_LINE(90)
	return this->m_shader;
}


HX_DEFINE_DYNAMIC_FUNC0(Material_obj,get_shader,return )

::haxor::graphics::material::Shader Material_obj::set_shader( ::haxor::graphics::material::Shader v){
	HX_STACK_FRAME("haxor.graphics.material.Material","set_shader",0x0c0024b9,"haxor.graphics.material.Material.set_shader","haxor/graphics/material/Material.hx",92,0xe49118e6)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(93)
	if (((this->m_shader == v))){
		HX_STACK_LINE(93)
		return v;
	}
	HX_STACK_LINE(94)
	::haxor::context::EngineContext_obj::material->UpdateShader(hx::ObjectPtr<OBJ_>(this),this->m_shader,v);
	HX_STACK_LINE(95)
	this->m_shader = v;
	HX_STACK_LINE(96)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Material_obj,set_shader,return )

Void Material_obj::SetBlending( int p_src,int p_dst){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","SetBlending",0x03abe39c,"haxor.graphics.material.Material.SetBlending","haxor/graphics/material/Material.hx",126,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_src,"p_src")
		HX_STACK_ARG(p_dst,"p_dst")
		HX_STACK_LINE(127)
		this->blend = !(((bool((p_src == (int)1)) && bool((p_dst == (int)0)))));
		HX_STACK_LINE(128)
		this->blendSrc = p_src;
		HX_STACK_LINE(129)
		this->blendDst = p_dst;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Material_obj,SetBlending,(void))

Void Material_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.graphics.material.Material","OnDestroy",0xc505e604,"haxor.graphics.material.Material.OnDestroy","haxor/graphics/material/Material.hx",164,0xe49118e6)
		HX_STACK_THIS(this)
		HX_STACK_LINE(164)
		::haxor::context::MaterialContext _this = ::haxor::context::EngineContext_obj::material;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(164)
		int p = _this->programs->__get(this->_cid_);		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(164)
		if (((this->m_shader != null()))){
			HX_STACK_LINE(164)
			::haxor::platform::graphics::GL_obj::m_gl->DetachShader(p,_this->vertex_shaders->__get(this->m_shader->_cid_));
			HX_STACK_LINE(164)
			::haxor::platform::graphics::GL_obj::m_gl->DetachShader(p,_this->fragment_shaders->__get(this->m_shader->_cid_));
		}
		HX_STACK_LINE(164)
		::haxor::platform::graphics::GL_obj::m_gl->DeleteProgram(p);
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
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"blendSrc") ) { return blendSrc; }
		if (HX_FIELD_EQ(inName,"blendDst") ) { return blendDst; }
		if (HX_FIELD_EQ(inName,"lighting") ) { return lighting; }
		if (HX_FIELD_EQ(inName,"m_shader") ) { return m_shader; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_shader") ) { return get_shader_dyn(); }
		if (HX_FIELD_EQ(inName,"set_shader") ) { return set_shader_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SetBlending") ) { return SetBlending_dyn(); }
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
	HX_CSTRING("SetBlending"),
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
