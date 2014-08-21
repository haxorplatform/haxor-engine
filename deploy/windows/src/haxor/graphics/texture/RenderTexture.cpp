#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_TextureContext
#include <haxor/context/TextureContext.h>
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
#ifndef INCLUDED_haxor_graphics_PixelFormat
#include <haxor/graphics/PixelFormat.h>
#endif
#ifndef INCLUDED_haxor_graphics_TextureType
#include <haxor/graphics/TextureType.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_RenderTexture
#include <haxor/graphics/texture/RenderTexture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture2D
#include <haxor/graphics/texture/Texture2D.h>
#endif
namespace haxor{
namespace graphics{
namespace texture{

Void RenderTexture_obj::__construct(int p_width,int p_height,::haxor::graphics::PixelFormat p_format,hx::Null< bool >  __o_p_store_depth)
{
HX_STACK_FRAME("haxor.graphics.texture.RenderTexture","new",0x4870ea6d,"haxor.graphics.texture.RenderTexture.new","haxor/graphics/texture/RenderTexture.hx",36,0x81f3eb84)
HX_STACK_THIS(this)
HX_STACK_ARG(p_width,"p_width")
HX_STACK_ARG(p_height,"p_height")
HX_STACK_ARG(p_format,"p_format")
HX_STACK_ARG(__o_p_store_depth,"p_store_depth")
bool p_store_depth = __o_p_store_depth.Default(false);
{
	HX_STACK_LINE(37)
	super::__construct();
	HX_STACK_LINE(38)
	this->m_format = p_format;
	HX_STACK_LINE(39)
	int _g = ::Std_obj::_int(p_width);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(39)
	this->m_width = _g;
	HX_STACK_LINE(40)
	int _g1 = ::Std_obj::_int(p_height);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(40)
	this->m_height = _g1;
	HX_STACK_LINE(42)
	bool store_depth = (bool(p_store_depth) && bool(::haxor::graphics::GL_obj::TEXTURE_DEPTH_ENABLED));		HX_STACK_VAR(store_depth,"store_depth");
	HX_STACK_LINE(44)
	if ((store_depth)){
		HX_STACK_LINE(46)
		::haxor::graphics::texture::Texture2D _g2 = ::haxor::graphics::texture::Texture2D_obj::__new(this->m_width,this->m_height,::haxor::graphics::PixelFormat_obj::Depth);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(46)
		this->m_depth = _g2;
	}
	HX_STACK_LINE(49)
	::haxor::context::EngineContext_obj::texture->Create(hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

//RenderTexture_obj::~RenderTexture_obj() { }

Dynamic RenderTexture_obj::__CreateEmpty() { return  new RenderTexture_obj; }
hx::ObjectPtr< RenderTexture_obj > RenderTexture_obj::__new(int p_width,int p_height,::haxor::graphics::PixelFormat p_format,hx::Null< bool >  __o_p_store_depth)
{  hx::ObjectPtr< RenderTexture_obj > result = new RenderTexture_obj();
	result->__construct(p_width,p_height,p_format,__o_p_store_depth);
	return result;}

Dynamic RenderTexture_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< RenderTexture_obj > result = new RenderTexture_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::haxor::graphics::texture::Texture2D RenderTexture_obj::get_depth( ){
	HX_STACK_FRAME("haxor.graphics.texture.RenderTexture","get_depth",0x2156ef27,"haxor.graphics.texture.RenderTexture.get_depth","haxor/graphics/texture/RenderTexture.hx",18,0x81f3eb84)
	HX_STACK_THIS(this)
	HX_STACK_LINE(18)
	return this->m_depth;
}


HX_DEFINE_DYNAMIC_FUNC0(RenderTexture_obj,get_depth,return )

::haxor::graphics::TextureType RenderTexture_obj::get_type( ){
	HX_STACK_FRAME("haxor.graphics.texture.RenderTexture","get_type",0x758c0516,"haxor.graphics.texture.RenderTexture.get_type","haxor/graphics/texture/RenderTexture.hx",25,0x81f3eb84)
	HX_STACK_THIS(this)
	HX_STACK_LINE(25)
	return ::haxor::graphics::TextureType_obj::RenderTexture;
}



RenderTexture_obj::RenderTexture_obj()
{
}

void RenderTexture_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(RenderTexture);
	HX_MARK_MEMBER_NAME(m_depth,"m_depth");
	::haxor::graphics::texture::Texture_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void RenderTexture_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_depth,"m_depth");
	::haxor::graphics::texture::Texture_obj::__Visit(HX_VISIT_ARG);
}

Dynamic RenderTexture_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"depth") ) { return get_depth(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_depth") ) { return m_depth; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_type") ) { return get_type_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_depth") ) { return get_depth_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic RenderTexture_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"m_depth") ) { m_depth=inValue.Cast< ::haxor::graphics::texture::Texture2D >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void RenderTexture_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("depth"));
	outFields->push(HX_CSTRING("m_depth"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::graphics::texture::Texture2D*/ ,(int)offsetof(RenderTexture_obj,m_depth),HX_CSTRING("m_depth")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_depth"),
	HX_CSTRING("m_depth"),
	HX_CSTRING("get_type"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(RenderTexture_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(RenderTexture_obj::__mClass,"__mClass");
};

#endif

Class RenderTexture_obj::__mClass;

void RenderTexture_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.texture.RenderTexture"), hx::TCanCast< RenderTexture_obj> ,sStaticFields,sMemberFields,
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

void RenderTexture_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace texture
