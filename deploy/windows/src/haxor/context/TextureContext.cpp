#include <hxcpp.h>

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
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GL
#include <haxor/platform/graphics/GL.h>
#endif
namespace haxor{
namespace context{

Void TextureContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.TextureContext","new",0x0513df31,"haxor.context.TextureContext.new","haxor/context/TextureContext.hx",25,0x7978261d)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(25)
	this->tid = (int)0;
}
;
	return null();
}

//TextureContext_obj::~TextureContext_obj() { }

Dynamic TextureContext_obj::__CreateEmpty() { return  new TextureContext_obj; }
hx::ObjectPtr< TextureContext_obj > TextureContext_obj::__new()
{  hx::ObjectPtr< TextureContext_obj > result = new TextureContext_obj();
	result->__construct();
	return result;}

Dynamic TextureContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TextureContext_obj > result = new TextureContext_obj();
	result->__construct();
	return result;}

Void TextureContext_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.context.TextureContext","Initialize",0x6b1912bf,"haxor.context.TextureContext.Initialize","haxor/context/TextureContext.hx",32,0x7978261d)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TextureContext_obj,Initialize,(void))

Void TextureContext_obj::Create( ::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.context.TextureContext","Create",0xef0624eb,"haxor.context.TextureContext.Create","haxor/context/TextureContext.hx",41,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_texture,"p_texture")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,Create,(void))

Void TextureContext_obj::UpdateParameters( ::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.context.TextureContext","UpdateParameters",0x22b5acc2,"haxor.context.TextureContext.UpdateParameters","haxor/context/TextureContext.hx",50,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_texture,"p_texture")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,UpdateParameters,(void))

Void TextureContext_obj::Update( ::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.context.TextureContext","Update",0xf9fc43f8,"haxor.context.TextureContext.Update","haxor/context/TextureContext.hx",59,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_texture,"p_texture")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,Update,(void))

Void TextureContext_obj::UpdateMipmaps( ::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.context.TextureContext","UpdateMipmaps",0x5ce57cd3,"haxor.context.TextureContext.UpdateMipmaps","haxor/context/TextureContext.hx",68,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_texture,"p_texture")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,UpdateMipmaps,(void))

Void TextureContext_obj::Destroy( ::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.context.TextureContext","Destroy",0x4975a02b,"haxor.context.TextureContext.Destroy","haxor/context/TextureContext.hx",77,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_texture,"p_texture")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,Destroy,(void))

int TextureContext_obj::FormatToChannelBits( ::haxor::graphics::PixelFormat p_format){
	HX_STACK_FRAME("haxor.context.TextureContext","FormatToChannelBits",0x426a86a8,"haxor.context.TextureContext.FormatToChannelBits","haxor/context/TextureContext.hx",87,0x7978261d)
	HX_STACK_ARG(p_format,"p_format")
	HX_STACK_LINE(88)
	switch( (int)(p_format->__Index())){
		case (int)0: {
			HX_STACK_LINE(90)
			return (int)6406;
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(91)
			return (int)6407;
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(92)
			return (int)6408;
		}
		;break;
		case (int)7: case (int)4: {
			HX_STACK_LINE(93)
			return (int)6409;
		}
		;break;
		case (int)8: case (int)5: {
			HX_STACK_LINE(94)
			return (int)6407;
		}
		;break;
		case (int)9: case (int)6: {
			HX_STACK_LINE(95)
			return (int)6408;
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(96)
			return (int)6409;
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(97)
			return (int)6402;
		}
		;break;
	}
	HX_STACK_LINE(99)
	return (int)6408;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,FormatToChannelBits,return )

int TextureContext_obj::FormatToChannelType( ::haxor::graphics::PixelFormat p_format){
	HX_STACK_FRAME("haxor.context.TextureContext","FormatToChannelType",0x4e5c7e5c,"haxor.context.TextureContext.FormatToChannelType","haxor/context/TextureContext.hx",108,0x7978261d)
	HX_STACK_ARG(p_format,"p_format")
	HX_STACK_LINE(109)
	switch( (int)(p_format->__Index())){
		case (int)4: case (int)5: case (int)6: {
			HX_STACK_LINE(111)
			return ::haxor::platform::graphics::GL_obj::HALF_FLOAT;
		}
		;break;
		case (int)7: case (int)8: case (int)9: {
			HX_STACK_LINE(112)
			return (int)5126;
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(113)
			return (int)5123;
		}
		;break;
		case (int)3: case (int)2: case (int)1: case (int)0: {
			HX_STACK_LINE(114)
			return (int)5121;
		}
		;break;
	}
	HX_STACK_LINE(116)
	return (int)5121;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,FormatToChannelType,return )

int TextureContext_obj::FormatToChannelLayout( ::haxor::graphics::PixelFormat p_format){
	HX_STACK_FRAME("haxor.context.TextureContext","FormatToChannelLayout",0xfebfe6cc,"haxor.context.TextureContext.FormatToChannelLayout","haxor/context/TextureContext.hx",125,0x7978261d)
	HX_STACK_ARG(p_format,"p_format")
	HX_STACK_LINE(126)
	switch( (int)(p_format->__Index())){
		case (int)0: {
			HX_STACK_LINE(128)
			return (int)6406;
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(129)
			return (int)6407;
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(130)
			return (int)6408;
		}
		;break;
		case (int)1: case (int)4: case (int)7: {
			HX_STACK_LINE(131)
			return (int)6409;
		}
		;break;
		case (int)8: case (int)5: {
			HX_STACK_LINE(132)
			return (int)6407;
		}
		;break;
		case (int)9: case (int)6: {
			HX_STACK_LINE(133)
			return (int)6408;
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(134)
			return (int)6402;
		}
		;break;
	}
	HX_STACK_LINE(136)
	return (int)6408;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,FormatToChannelLayout,return )


TextureContext_obj::TextureContext_obj()
{
}

Dynamic TextureContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"tid") ) { return tid; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Create") ) { return Create_dyn(); }
		if (HX_FIELD_EQ(inName,"Update") ) { return Update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Destroy") ) { return Destroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"UpdateMipmaps") ) { return UpdateMipmaps_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"UpdateParameters") ) { return UpdateParameters_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"FormatToChannelBits") ) { return FormatToChannelBits_dyn(); }
		if (HX_FIELD_EQ(inName,"FormatToChannelType") ) { return FormatToChannelType_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"FormatToChannelLayout") ) { return FormatToChannelLayout_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TextureContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"tid") ) { tid=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextureContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tid"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("FormatToChannelBits"),
	HX_CSTRING("FormatToChannelType"),
	HX_CSTRING("FormatToChannelLayout"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(TextureContext_obj,tid),HX_CSTRING("tid")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("tid"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Create"),
	HX_CSTRING("UpdateParameters"),
	HX_CSTRING("Update"),
	HX_CSTRING("UpdateMipmaps"),
	HX_CSTRING("Destroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TextureContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TextureContext_obj::__mClass,"__mClass");
};

#endif

Class TextureContext_obj::__mClass;

void TextureContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.TextureContext"), hx::TCanCast< TextureContext_obj> ,sStaticFields,sMemberFields,
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

void TextureContext_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
