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
#ifndef INCLUDED_haxor_graphics_PixelFormat
#include <haxor/graphics/PixelFormat.h>
#endif
#ifndef INCLUDED_haxor_graphics_TextureType
#include <haxor/graphics/TextureType.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#include <haxor/graphics/texture/Bitmap.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture2D
#include <haxor/graphics/texture/Texture2D.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
namespace haxor{
namespace graphics{
namespace texture{

Void Texture2D_obj::__construct(int p_width,int p_height,::haxor::graphics::PixelFormat p_format)
{
HX_STACK_FRAME("haxor.graphics.texture.Texture2D","new",0x8f6670b5,"haxor.graphics.texture.Texture2D.new","haxor/graphics/texture/Texture2D.hx",78,0x654901bc)
HX_STACK_THIS(this)
HX_STACK_ARG(p_width,"p_width")
HX_STACK_ARG(p_height,"p_height")
HX_STACK_ARG(p_format,"p_format")
{
	HX_STACK_LINE(79)
	super::__construct();
	HX_STACK_LINE(80)
	this->m_format = p_format;
	HX_STACK_LINE(81)
	this->m_width = p_width;
	HX_STACK_LINE(82)
	this->m_height = p_height;
	HX_STACK_LINE(83)
	if (((p_width <= (int)0))){
		HX_STACK_LINE(83)
		return null();
	}
	HX_STACK_LINE(84)
	if (((p_height <= (int)0))){
		HX_STACK_LINE(84)
		return null();
	}
	HX_STACK_LINE(85)
	::haxor::graphics::texture::Bitmap _g = ::haxor::graphics::texture::Bitmap_obj::__new(p_width,p_height,p_format);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(85)
	this->m_data = _g;
	HX_STACK_LINE(86)
	::haxor::context::EngineContext_obj::texture->Create(hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

//Texture2D_obj::~Texture2D_obj() { }

Dynamic Texture2D_obj::__CreateEmpty() { return  new Texture2D_obj; }
hx::ObjectPtr< Texture2D_obj > Texture2D_obj::__new(int p_width,int p_height,::haxor::graphics::PixelFormat p_format)
{  hx::ObjectPtr< Texture2D_obj > result = new Texture2D_obj();
	result->__construct(p_width,p_height,p_format);
	return result;}

Dynamic Texture2D_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Texture2D_obj > result = new Texture2D_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::haxor::graphics::texture::Bitmap Texture2D_obj::get_data( ){
	HX_STACK_FRAME("haxor.graphics.texture.Texture2D","get_data",0x67dd1d3e,"haxor.graphics.texture.Texture2D.get_data","haxor/graphics/texture/Texture2D.hx",62,0x654901bc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(62)
	return this->m_data;
}


HX_DEFINE_DYNAMIC_FUNC0(Texture2D_obj,get_data,return )

::haxor::graphics::TextureType Texture2D_obj::get_type( ){
	HX_STACK_FRAME("haxor.graphics.texture.Texture2D","get_type",0x7282b9ce,"haxor.graphics.texture.Texture2D.get_type","haxor/graphics/texture/Texture2D.hx",69,0x654901bc)
	HX_STACK_THIS(this)
	HX_STACK_LINE(69)
	return ::haxor::graphics::TextureType_obj::Texture2D;
}


Void Texture2D_obj::Upload( hx::Null< int >  __o_p_steps,Dynamic p_on_complete){
int p_steps = __o_p_steps.Default(200);
	HX_STACK_FRAME("haxor.graphics.texture.Texture2D","Upload",0x636ec0ec,"haxor.graphics.texture.Texture2D.Upload","haxor/graphics/texture/Texture2D.hx",96,0x654901bc)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_steps,"p_steps")
	HX_STACK_ARG(p_on_complete,"p_on_complete")
{
		HX_STACK_LINE(96)
		::haxor::context::EngineContext_obj::texture->UploadTexture(hx::ObjectPtr<OBJ_>(this),p_steps,p_on_complete);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Texture2D_obj,Upload,(void))

::haxor::graphics::texture::Texture2D Texture2D_obj::get_white( ){
	HX_STACK_FRAME("haxor.graphics.texture.Texture2D","get_white",0x6ed1b515,"haxor.graphics.texture.Texture2D.get_white","haxor/graphics/texture/Texture2D.hx",18,0x654901bc)
	HX_STACK_LINE(19)
	if (((::haxor::graphics::texture::Texture2D_obj::m_white != null()))){
		HX_STACK_LINE(19)
		return ::haxor::graphics::texture::Texture2D_obj::m_white;
	}
	HX_STACK_LINE(20)
	::haxor::graphics::texture::Texture2D _g = ::haxor::graphics::texture::Texture2D_obj::__new((int)1,(int)1,::haxor::graphics::PixelFormat_obj::RGB8);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(20)
	::haxor::graphics::texture::Texture2D_obj::m_white = _g;
	HX_STACK_LINE(21)
	::haxor::math::Color _g1 = ::haxor::math::Color_obj::get_white();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(21)
	::haxor::graphics::texture::Texture2D_obj::m_white->m_data->Fill(_g1);
	HX_STACK_LINE(22)
	::haxor::graphics::texture::Texture2D_obj::m_white->Apply();
	HX_STACK_LINE(23)
	return ::haxor::graphics::texture::Texture2D_obj::m_white;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Texture2D_obj,get_white,return )

::haxor::graphics::texture::Texture2D Texture2D_obj::m_white;

::haxor::graphics::texture::Texture2D Texture2D_obj::get_red( ){
	HX_STACK_FRAME("haxor.graphics.texture.Texture2D","get_red",0xb4bd90bd,"haxor.graphics.texture.Texture2D.get_red","haxor/graphics/texture/Texture2D.hx",32,0x654901bc)
	HX_STACK_LINE(33)
	if (((::haxor::graphics::texture::Texture2D_obj::m_red != null()))){
		HX_STACK_LINE(33)
		return ::haxor::graphics::texture::Texture2D_obj::m_red;
	}
	HX_STACK_LINE(34)
	::haxor::graphics::texture::Texture2D _g = ::haxor::graphics::texture::Texture2D_obj::__new((int)1,(int)1,::haxor::graphics::PixelFormat_obj::RGB8);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(34)
	::haxor::graphics::texture::Texture2D_obj::m_red = _g;
	HX_STACK_LINE(35)
	::haxor::math::Color _g1 = ::haxor::math::Color_obj::get_red();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(35)
	::haxor::graphics::texture::Texture2D_obj::m_red->m_data->Fill(_g1);
	HX_STACK_LINE(36)
	::haxor::graphics::texture::Texture2D_obj::m_red->Apply();
	HX_STACK_LINE(37)
	return ::haxor::graphics::texture::Texture2D_obj::m_red;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Texture2D_obj,get_red,return )

::haxor::graphics::texture::Texture2D Texture2D_obj::m_red;

::haxor::graphics::texture::Texture2D Texture2D_obj::FromBitmap( ::haxor::graphics::texture::Bitmap p_bitmap,hx::Null< bool >  __o_p_apply){
bool p_apply = __o_p_apply.Default(true);
	HX_STACK_FRAME("haxor.graphics.texture.Texture2D","FromBitmap",0x07425d64,"haxor.graphics.texture.Texture2D.FromBitmap","haxor/graphics/texture/Texture2D.hx",48,0x654901bc)
	HX_STACK_ARG(p_bitmap,"p_bitmap")
	HX_STACK_ARG(p_apply,"p_apply")
{
		HX_STACK_LINE(49)
		::haxor::graphics::texture::Texture2D t = ::haxor::graphics::texture::Texture2D_obj::__new((int)0,(int)0,p_bitmap->m_format);		HX_STACK_VAR(t,"t");
		HX_STACK_LINE(50)
		t->m_data = p_bitmap;
		HX_STACK_LINE(51)
		t->m_width = p_bitmap->m_width;
		HX_STACK_LINE(52)
		t->m_height = p_bitmap->m_height;
		HX_STACK_LINE(53)
		::haxor::context::EngineContext_obj::texture->Create(t);
		HX_STACK_LINE(54)
		t->Apply();
		HX_STACK_LINE(55)
		return t;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Texture2D_obj,FromBitmap,return )


Texture2D_obj::Texture2D_obj()
{
}

void Texture2D_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Texture2D);
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(m_data,"m_data");
	::haxor::graphics::texture::Texture_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Texture2D_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(m_data,"m_data");
	::haxor::graphics::texture::Texture_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Texture2D_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"red") ) { return get_red(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return inCallProp ? get_data() : data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"white") ) { return get_white(); }
		if (HX_FIELD_EQ(inName,"m_red") ) { return m_red; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_data") ) { return m_data; }
		if (HX_FIELD_EQ(inName,"Upload") ) { return Upload_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_white") ) { return m_white; }
		if (HX_FIELD_EQ(inName,"get_red") ) { return get_red_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_data") ) { return get_data_dyn(); }
		if (HX_FIELD_EQ(inName,"get_type") ) { return get_type_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_white") ) { return get_white_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FromBitmap") ) { return FromBitmap_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Texture2D_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::haxor::graphics::texture::Bitmap >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_red") ) { m_red=inValue.Cast< ::haxor::graphics::texture::Texture2D >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_data") ) { m_data=inValue.Cast< ::haxor::graphics::texture::Bitmap >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_white") ) { m_white=inValue.Cast< ::haxor::graphics::texture::Texture2D >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Texture2D_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("m_data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("get_white"),
	HX_CSTRING("m_white"),
	HX_CSTRING("get_red"),
	HX_CSTRING("m_red"),
	HX_CSTRING("FromBitmap"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::graphics::texture::Bitmap*/ ,(int)offsetof(Texture2D_obj,data),HX_CSTRING("data")},
	{hx::fsObject /*::haxor::graphics::texture::Bitmap*/ ,(int)offsetof(Texture2D_obj,m_data),HX_CSTRING("m_data")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("data"),
	HX_CSTRING("get_data"),
	HX_CSTRING("m_data"),
	HX_CSTRING("get_type"),
	HX_CSTRING("Upload"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Texture2D_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Texture2D_obj::m_white,"m_white");
	HX_MARK_MEMBER_NAME(Texture2D_obj::m_red,"m_red");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Texture2D_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Texture2D_obj::m_white,"m_white");
	HX_VISIT_MEMBER_NAME(Texture2D_obj::m_red,"m_red");
};

#endif

Class Texture2D_obj::__mClass;

void Texture2D_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.texture.Texture2D"), hx::TCanCast< Texture2D_obj> ,sStaticFields,sMemberFields,
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

void Texture2D_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace texture
