#include <hxcpp.h>

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
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture2D
#include <haxor/graphics/texture/Texture2D.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_TextureCube
#include <haxor/graphics/texture/TextureCube.h>
#endif
namespace haxor{
namespace graphics{
namespace texture{

Void TextureCube_obj::__construct()
{
HX_STACK_FRAME("haxor.graphics.texture.TextureCube","new",0x43f369b8,"haxor.graphics.texture.TextureCube.new","haxor/graphics/texture/TextureCube.hx",112,0x53e63459)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(113)
	this->m_faces = Array_obj< ::Dynamic >::__new().Add(null()).Add(null()).Add(null()).Add(null()).Add(null()).Add(null());
	HX_STACK_LINE(114)
	this->m_is_cross = false;
	HX_STACK_LINE(115)
	super::__construct();
	HX_STACK_LINE(116)
	::haxor::context::EngineContext_obj::texture->Create(hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

//TextureCube_obj::~TextureCube_obj() { }

Dynamic TextureCube_obj::__CreateEmpty() { return  new TextureCube_obj; }
hx::ObjectPtr< TextureCube_obj > TextureCube_obj::__new()
{  hx::ObjectPtr< TextureCube_obj > result = new TextureCube_obj();
	result->__construct();
	return result;}

Dynamic TextureCube_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextureCube_obj > result = new TextureCube_obj();
	result->__construct();
	return result;}

::haxor::graphics::texture::Texture TextureCube_obj::get_px( ){
	HX_STACK_FRAME("haxor.graphics.texture.TextureCube","get_px",0x88c0c6f9,"haxor.graphics.texture.TextureCube.get_px","haxor/graphics/texture/TextureCube.hx",54,0x53e63459)
	HX_STACK_THIS(this)
	HX_STACK_LINE(54)
	return this->m_faces->__get((int)0).StaticCast< ::haxor::graphics::texture::Texture >();
}


HX_DEFINE_DYNAMIC_FUNC0(TextureCube_obj,get_px,return )

::haxor::graphics::texture::Texture TextureCube_obj::set_px( ::haxor::graphics::texture::Texture v){
	HX_STACK_FRAME("haxor.graphics.texture.TextureCube","set_px",0x55091b6d,"haxor.graphics.texture.TextureCube.set_px","haxor/graphics/texture/TextureCube.hx",55,0x53e63459)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(55)
	this->InvalidateCross();
	HX_STACK_LINE(55)
	this->m_faces[(int)0] = v;
	HX_STACK_LINE(55)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(TextureCube_obj,set_px,return )

::haxor::graphics::texture::Texture TextureCube_obj::get_nx( ){
	HX_STACK_FRAME("haxor.graphics.texture.TextureCube","get_nx",0x88c0c53b,"haxor.graphics.texture.TextureCube.get_nx","haxor/graphics/texture/TextureCube.hx",62,0x53e63459)
	HX_STACK_THIS(this)
	HX_STACK_LINE(62)
	return this->m_faces->__get((int)1).StaticCast< ::haxor::graphics::texture::Texture >();
}


HX_DEFINE_DYNAMIC_FUNC0(TextureCube_obj,get_nx,return )

::haxor::graphics::texture::Texture TextureCube_obj::set_nx( ::haxor::graphics::texture::Texture v){
	HX_STACK_FRAME("haxor.graphics.texture.TextureCube","set_nx",0x550919af,"haxor.graphics.texture.TextureCube.set_nx","haxor/graphics/texture/TextureCube.hx",63,0x53e63459)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(63)
	this->InvalidateCross();
	HX_STACK_LINE(63)
	this->m_faces[(int)1] = v;
	HX_STACK_LINE(63)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(TextureCube_obj,set_nx,return )

::haxor::graphics::texture::Texture TextureCube_obj::get_py( ){
	HX_STACK_FRAME("haxor.graphics.texture.TextureCube","get_py",0x88c0c6fa,"haxor.graphics.texture.TextureCube.get_py","haxor/graphics/texture/TextureCube.hx",70,0x53e63459)
	HX_STACK_THIS(this)
	HX_STACK_LINE(70)
	return this->m_faces->__get((int)2).StaticCast< ::haxor::graphics::texture::Texture >();
}


HX_DEFINE_DYNAMIC_FUNC0(TextureCube_obj,get_py,return )

::haxor::graphics::texture::Texture TextureCube_obj::set_py( ::haxor::graphics::texture::Texture v){
	HX_STACK_FRAME("haxor.graphics.texture.TextureCube","set_py",0x55091b6e,"haxor.graphics.texture.TextureCube.set_py","haxor/graphics/texture/TextureCube.hx",71,0x53e63459)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(71)
	this->InvalidateCross();
	HX_STACK_LINE(71)
	this->m_faces[(int)2] = v;
	HX_STACK_LINE(71)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(TextureCube_obj,set_py,return )

::haxor::graphics::texture::Texture TextureCube_obj::get_ny( ){
	HX_STACK_FRAME("haxor.graphics.texture.TextureCube","get_ny",0x88c0c53c,"haxor.graphics.texture.TextureCube.get_ny","haxor/graphics/texture/TextureCube.hx",78,0x53e63459)
	HX_STACK_THIS(this)
	HX_STACK_LINE(78)
	return this->m_faces->__get((int)3).StaticCast< ::haxor::graphics::texture::Texture >();
}


HX_DEFINE_DYNAMIC_FUNC0(TextureCube_obj,get_ny,return )

::haxor::graphics::texture::Texture TextureCube_obj::set_ny( ::haxor::graphics::texture::Texture v){
	HX_STACK_FRAME("haxor.graphics.texture.TextureCube","set_ny",0x550919b0,"haxor.graphics.texture.TextureCube.set_ny","haxor/graphics/texture/TextureCube.hx",79,0x53e63459)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(79)
	this->InvalidateCross();
	HX_STACK_LINE(79)
	this->m_faces[(int)3] = v;
	HX_STACK_LINE(79)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(TextureCube_obj,set_ny,return )

::haxor::graphics::texture::Texture TextureCube_obj::get_pz( ){
	HX_STACK_FRAME("haxor.graphics.texture.TextureCube","get_pz",0x88c0c6fb,"haxor.graphics.texture.TextureCube.get_pz","haxor/graphics/texture/TextureCube.hx",86,0x53e63459)
	HX_STACK_THIS(this)
	HX_STACK_LINE(86)
	return this->m_faces->__get((int)4).StaticCast< ::haxor::graphics::texture::Texture >();
}


HX_DEFINE_DYNAMIC_FUNC0(TextureCube_obj,get_pz,return )

::haxor::graphics::texture::Texture TextureCube_obj::set_pz( ::haxor::graphics::texture::Texture v){
	HX_STACK_FRAME("haxor.graphics.texture.TextureCube","set_pz",0x55091b6f,"haxor.graphics.texture.TextureCube.set_pz","haxor/graphics/texture/TextureCube.hx",87,0x53e63459)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(87)
	this->InvalidateCross();
	HX_STACK_LINE(87)
	this->m_faces[(int)4] = v;
	HX_STACK_LINE(87)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(TextureCube_obj,set_pz,return )

::haxor::graphics::texture::Texture TextureCube_obj::get_nz( ){
	HX_STACK_FRAME("haxor.graphics.texture.TextureCube","get_nz",0x88c0c53d,"haxor.graphics.texture.TextureCube.get_nz","haxor/graphics/texture/TextureCube.hx",94,0x53e63459)
	HX_STACK_THIS(this)
	HX_STACK_LINE(94)
	return this->m_faces->__get((int)5).StaticCast< ::haxor::graphics::texture::Texture >();
}


HX_DEFINE_DYNAMIC_FUNC0(TextureCube_obj,get_nz,return )

::haxor::graphics::texture::Texture TextureCube_obj::set_nz( ::haxor::graphics::texture::Texture v){
	HX_STACK_FRAME("haxor.graphics.texture.TextureCube","set_nz",0x550919b1,"haxor.graphics.texture.TextureCube.set_nz","haxor/graphics/texture/TextureCube.hx",95,0x53e63459)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(95)
	this->InvalidateCross();
	HX_STACK_LINE(95)
	this->m_faces[(int)5] = v;
	HX_STACK_LINE(95)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(TextureCube_obj,set_nz,return )

Void TextureCube_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.graphics.texture.TextureCube","OnDestroy",0x823cf0d3,"haxor.graphics.texture.TextureCube.OnDestroy","haxor/graphics/texture/TextureCube.hx",123,0x53e63459)
		HX_STACK_THIS(this)
		HX_STACK_LINE(124)
		this->super::OnDestroy();
		HX_STACK_LINE(125)
		{
			HX_STACK_LINE(125)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(125)
			int _g = this->m_faces->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(125)
			while((true)){
				HX_STACK_LINE(125)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(125)
					break;
				}
				HX_STACK_LINE(125)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(125)
				if (((this->m_faces->__get(i).StaticCast< ::haxor::graphics::texture::Texture >() != null()))){
					HX_STACK_LINE(125)
					::haxor::core::Resource_obj::Destroy(this->m_faces->__get(i).StaticCast< ::haxor::graphics::texture::Texture >());
				}
			}
		}
	}
return null();
}


Void TextureCube_obj::InvalidateCross( ){
{
		HX_STACK_FRAME("haxor.graphics.texture.TextureCube","InvalidateCross",0x55e0bd3d,"haxor.graphics.texture.TextureCube.InvalidateCross","haxor/graphics/texture/TextureCube.hx",132,0x53e63459)
		HX_STACK_THIS(this)
		HX_STACK_LINE(133)
		if ((!(this->m_is_cross))){
			HX_STACK_LINE(133)
			return null();
		}
		HX_STACK_LINE(134)
		{
			HX_STACK_LINE(134)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(134)
			int _g = this->m_faces->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(134)
			while((true)){
				HX_STACK_LINE(134)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(134)
					break;
				}
				HX_STACK_LINE(134)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(134)
				if (((this->m_faces->__get(i).StaticCast< ::haxor::graphics::texture::Texture >() != null()))){
					HX_STACK_LINE(134)
					::haxor::core::Resource_obj::Destroy(this->m_faces->__get(i).StaticCast< ::haxor::graphics::texture::Texture >());
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TextureCube_obj,InvalidateCross,(void))

::haxor::graphics::texture::TextureCube TextureCube_obj::FromCrossTexture( ::haxor::graphics::texture::Texture2D p_texture){
	HX_STACK_FRAME("haxor.graphics.texture.TextureCube","FromCrossTexture",0xeb7b358d,"haxor.graphics.texture.TextureCube.FromCrossTexture","haxor/graphics/texture/TextureCube.hx",47,0x53e63459)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_LINE(47)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextureCube_obj,FromCrossTexture,return )


TextureCube_obj::TextureCube_obj()
{
}

void TextureCube_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextureCube);
	HX_MARK_MEMBER_NAME(p_px,"p_px");
	HX_MARK_MEMBER_NAME(p_nx,"p_nx");
	HX_MARK_MEMBER_NAME(p_py,"p_py");
	HX_MARK_MEMBER_NAME(p_ny,"p_ny");
	HX_MARK_MEMBER_NAME(p_pz,"p_pz");
	HX_MARK_MEMBER_NAME(p_nz,"p_nz");
	HX_MARK_MEMBER_NAME(m_faces,"m_faces");
	HX_MARK_MEMBER_NAME(m_is_cross,"m_is_cross");
	::haxor::graphics::texture::Texture_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TextureCube_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(p_px,"p_px");
	HX_VISIT_MEMBER_NAME(p_nx,"p_nx");
	HX_VISIT_MEMBER_NAME(p_py,"p_py");
	HX_VISIT_MEMBER_NAME(p_ny,"p_ny");
	HX_VISIT_MEMBER_NAME(p_pz,"p_pz");
	HX_VISIT_MEMBER_NAME(p_nz,"p_nz");
	HX_VISIT_MEMBER_NAME(m_faces,"m_faces");
	HX_VISIT_MEMBER_NAME(m_is_cross,"m_is_cross");
	::haxor::graphics::texture::Texture_obj::__Visit(HX_VISIT_ARG);
}

Dynamic TextureCube_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"px") ) { return get_px(); }
		if (HX_FIELD_EQ(inName,"nx") ) { return get_nx(); }
		if (HX_FIELD_EQ(inName,"py") ) { return get_py(); }
		if (HX_FIELD_EQ(inName,"ny") ) { return get_ny(); }
		if (HX_FIELD_EQ(inName,"pz") ) { return get_pz(); }
		if (HX_FIELD_EQ(inName,"nz") ) { return get_nz(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"p_px") ) { return p_px; }
		if (HX_FIELD_EQ(inName,"p_nx") ) { return p_nx; }
		if (HX_FIELD_EQ(inName,"p_py") ) { return p_py; }
		if (HX_FIELD_EQ(inName,"p_ny") ) { return p_ny; }
		if (HX_FIELD_EQ(inName,"p_pz") ) { return p_pz; }
		if (HX_FIELD_EQ(inName,"p_nz") ) { return p_nz; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"get_px") ) { return get_px_dyn(); }
		if (HX_FIELD_EQ(inName,"set_px") ) { return set_px_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nx") ) { return get_nx_dyn(); }
		if (HX_FIELD_EQ(inName,"set_nx") ) { return set_nx_dyn(); }
		if (HX_FIELD_EQ(inName,"get_py") ) { return get_py_dyn(); }
		if (HX_FIELD_EQ(inName,"set_py") ) { return set_py_dyn(); }
		if (HX_FIELD_EQ(inName,"get_ny") ) { return get_ny_dyn(); }
		if (HX_FIELD_EQ(inName,"set_ny") ) { return set_ny_dyn(); }
		if (HX_FIELD_EQ(inName,"get_pz") ) { return get_pz_dyn(); }
		if (HX_FIELD_EQ(inName,"set_pz") ) { return set_pz_dyn(); }
		if (HX_FIELD_EQ(inName,"get_nz") ) { return get_nz_dyn(); }
		if (HX_FIELD_EQ(inName,"set_nz") ) { return set_nz_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_faces") ) { return m_faces; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_is_cross") ) { return m_is_cross; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"InvalidateCross") ) { return InvalidateCross_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"FromCrossTexture") ) { return FromCrossTexture_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextureCube_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"px") ) { return set_px(inValue); }
		if (HX_FIELD_EQ(inName,"nx") ) { return set_nx(inValue); }
		if (HX_FIELD_EQ(inName,"py") ) { return set_py(inValue); }
		if (HX_FIELD_EQ(inName,"ny") ) { return set_ny(inValue); }
		if (HX_FIELD_EQ(inName,"pz") ) { return set_pz(inValue); }
		if (HX_FIELD_EQ(inName,"nz") ) { return set_nz(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"p_px") ) { p_px=inValue.Cast< ::haxor::graphics::texture::Texture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_nx") ) { p_nx=inValue.Cast< ::haxor::graphics::texture::Texture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_py") ) { p_py=inValue.Cast< ::haxor::graphics::texture::Texture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_ny") ) { p_ny=inValue.Cast< ::haxor::graphics::texture::Texture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_pz") ) { p_pz=inValue.Cast< ::haxor::graphics::texture::Texture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"p_nz") ) { p_nz=inValue.Cast< ::haxor::graphics::texture::Texture >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_faces") ) { m_faces=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_is_cross") ) { m_is_cross=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextureCube_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("px"));
	outFields->push(HX_CSTRING("p_px"));
	outFields->push(HX_CSTRING("nx"));
	outFields->push(HX_CSTRING("p_nx"));
	outFields->push(HX_CSTRING("py"));
	outFields->push(HX_CSTRING("p_py"));
	outFields->push(HX_CSTRING("ny"));
	outFields->push(HX_CSTRING("p_ny"));
	outFields->push(HX_CSTRING("pz"));
	outFields->push(HX_CSTRING("p_pz"));
	outFields->push(HX_CSTRING("nz"));
	outFields->push(HX_CSTRING("p_nz"));
	outFields->push(HX_CSTRING("m_faces"));
	outFields->push(HX_CSTRING("m_is_cross"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("FromCrossTexture"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::graphics::texture::Texture*/ ,(int)offsetof(TextureCube_obj,p_px),HX_CSTRING("p_px")},
	{hx::fsObject /*::haxor::graphics::texture::Texture*/ ,(int)offsetof(TextureCube_obj,p_nx),HX_CSTRING("p_nx")},
	{hx::fsObject /*::haxor::graphics::texture::Texture*/ ,(int)offsetof(TextureCube_obj,p_py),HX_CSTRING("p_py")},
	{hx::fsObject /*::haxor::graphics::texture::Texture*/ ,(int)offsetof(TextureCube_obj,p_ny),HX_CSTRING("p_ny")},
	{hx::fsObject /*::haxor::graphics::texture::Texture*/ ,(int)offsetof(TextureCube_obj,p_pz),HX_CSTRING("p_pz")},
	{hx::fsObject /*::haxor::graphics::texture::Texture*/ ,(int)offsetof(TextureCube_obj,p_nz),HX_CSTRING("p_nz")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(TextureCube_obj,m_faces),HX_CSTRING("m_faces")},
	{hx::fsBool,(int)offsetof(TextureCube_obj,m_is_cross),HX_CSTRING("m_is_cross")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_px"),
	HX_CSTRING("set_px"),
	HX_CSTRING("p_px"),
	HX_CSTRING("get_nx"),
	HX_CSTRING("set_nx"),
	HX_CSTRING("p_nx"),
	HX_CSTRING("get_py"),
	HX_CSTRING("set_py"),
	HX_CSTRING("p_py"),
	HX_CSTRING("get_ny"),
	HX_CSTRING("set_ny"),
	HX_CSTRING("p_ny"),
	HX_CSTRING("get_pz"),
	HX_CSTRING("set_pz"),
	HX_CSTRING("p_pz"),
	HX_CSTRING("get_nz"),
	HX_CSTRING("set_nz"),
	HX_CSTRING("p_nz"),
	HX_CSTRING("m_faces"),
	HX_CSTRING("m_is_cross"),
	HX_CSTRING("OnDestroy"),
	HX_CSTRING("InvalidateCross"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextureCube_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextureCube_obj::__mClass,"__mClass");
};

#endif

Class TextureCube_obj::__mClass;

void TextureCube_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.texture.TextureCube"), hx::TCanCast< TextureCube_obj> ,sStaticFields,sMemberFields,
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

void TextureCube_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace texture
