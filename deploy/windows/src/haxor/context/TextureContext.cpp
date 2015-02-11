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
#ifndef INCLUDED_haxor_context_UID
#include <haxor/context/UID.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IRenderable
#include <haxor/core/IRenderable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_PixelFormat
#include <haxor/core/PixelFormat.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_TextureFilter
#include <haxor/core/TextureFilter.h>
#endif
#ifndef INCLUDED_haxor_core_TextureType
#include <haxor/core/TextureType.h>
#endif
#ifndef INCLUDED_haxor_core_TextureWrap
#include <haxor/core/TextureWrap.h>
#endif
#ifndef INCLUDED_haxor_graphics_GL
#include <haxor/graphics/GL.h>
#endif
#ifndef INCLUDED_haxor_graphics_GraphicContext
#include <haxor/graphics/GraphicContext.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#include <haxor/graphics/texture/Bitmap.h>
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
#ifndef INCLUDED_haxor_graphics_texture_TextureCube
#include <haxor/graphics/texture/TextureCube.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_graphics_WinGL
#include <haxor/platform/windows/graphics/WinGL.h>
#endif
#ifndef INCLUDED_haxor_thread_Activity
#include <haxor/thread/Activity.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace context{

Void TextureContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.TextureContext","new",0x0513df31,"haxor.context.TextureContext.new","haxor/context/TextureContext.hx",80,0x7978261d)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(81)
	::haxor::context::UID _g = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(81)
	this->tid = _g;
	HX_STACK_LINE(82)
	this->bind = null();
	HX_STACK_LINE(83)
	this->target = null();
	HX_STACK_LINE(84)
	this->active = (int)-1;
	HX_STACK_LINE(85)
	this->next_slot = (int)0;
	HX_STACK_LINE(86)
	this->bind = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(87)
	this->ids = Array_obj< int >::__new();
	HX_STACK_LINE(89)
	this->framebuffers = Array_obj< int >::__new();
	HX_STACK_LINE(90)
	this->renderbuffers = Array_obj< int >::__new();
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
		HX_STACK_FRAME("haxor.context.TextureContext","Initialize",0x6b1912bf,"haxor.context.TextureContext.Initialize","haxor/context/TextureContext.hx",97,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(98)
		{
			HX_STACK_LINE(98)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(98)
			int _g = ::haxor::graphics::GL_obj::MAX_ACTIVE_TEXTURE;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(98)
			while((true)){
				HX_STACK_LINE(98)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(98)
					break;
				}
				HX_STACK_LINE(98)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(98)
				this->bind->push(null());
			}
		}
		HX_STACK_LINE(99)
		{
			HX_STACK_LINE(99)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(99)
			while((true)){
				HX_STACK_LINE(99)
				if ((!(((_g < (int)2048))))){
					HX_STACK_LINE(99)
					break;
				}
				HX_STACK_LINE(99)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(101)
				this->ids->push(::haxor::graphics::GL_obj::INVALID);
				HX_STACK_LINE(102)
				this->framebuffers->push(::haxor::graphics::GL_obj::INVALID);
				HX_STACK_LINE(103)
				this->renderbuffers->push(::haxor::graphics::GL_obj::INVALID);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TextureContext_obj,Initialize,(void))

Void TextureContext_obj::Alloc( ::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.context.TextureContext","Alloc",0x74bf3966,"haxor.context.TextureContext.Alloc","haxor/context/TextureContext.hx",112,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_texture,"p_texture")
		HX_STACK_LINE(113)
		int w = p_texture->m_width;		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(114)
		int h = p_texture->m_height;		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(115)
		int chn_fmt = ::haxor::context::TextureContext_obj::FormatToChannelLayout(p_texture->m_format);		HX_STACK_VAR(chn_fmt,"chn_fmt");
		HX_STACK_LINE(116)
		int chn_bit = ::haxor::context::TextureContext_obj::FormatToChannelBits(p_texture->m_format);		HX_STACK_VAR(chn_bit,"chn_bit");
		HX_STACK_LINE(117)
		int chn_type = ::haxor::context::TextureContext_obj::FormatToChannelType(p_texture->m_format);		HX_STACK_VAR(chn_type,"chn_type");
		HX_STACK_LINE(118)
		::haxor::core::TextureType _g = p_texture->get_type();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(118)
		int tex_type;		HX_STACK_VAR(tex_type,"tex_type");
		HX_STACK_LINE(118)
		if (((_g == ::haxor::core::TextureType_obj::Texture2D))){
			HX_STACK_LINE(118)
			tex_type = (int)3553;
		}
		else{
			HX_STACK_LINE(118)
			::haxor::core::TextureType _g1 = p_texture->get_type();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(118)
			if (((_g1 == ::haxor::core::TextureType_obj::RenderTexture))){
				HX_STACK_LINE(118)
				tex_type = (int)3553;
			}
			else{
				HX_STACK_LINE(118)
				::haxor::core::TextureType _g2 = p_texture->get_type();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(118)
				if (((_g2 == ::haxor::core::TextureType_obj::TextureCube))){
					HX_STACK_LINE(118)
					tex_type = (int)34067;
				}
				else{
					HX_STACK_LINE(118)
					tex_type = (int)3553;
				}
			}
		}
		HX_STACK_LINE(119)
		this->Bind(p_texture,null());
		HX_STACK_LINE(120)
		::haxor::graphics::GL_obj::m_gl->TexImage2DAlloc(tex_type,(int)0,chn_fmt,w,h,(int)0,chn_bit,chn_type);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,Alloc,(void))

Void TextureContext_obj::Create( ::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.context.TextureContext","Create",0xef0624eb,"haxor.context.TextureContext.Create","haxor/context/TextureContext.hx",128,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_texture,"p_texture")
		HX_STACK_LINE(129)
		p_texture->__slot = (int)-1;
		HX_STACK_LINE(132)
		int id = ::haxor::graphics::GL_obj::m_gl->CreateTexture();		HX_STACK_VAR(id,"id");
		HX_STACK_LINE(135)
		this->ids[p_texture->__cid] = id;
		HX_STACK_LINE(137)
		{
			HX_STACK_LINE(137)
			::haxor::core::TextureType _g = p_texture->get_type();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(137)
			int target;		HX_STACK_VAR(target,"target");
			HX_STACK_LINE(137)
			if (((_g == ::haxor::core::TextureType_obj::Texture2D))){
				HX_STACK_LINE(137)
				target = (int)3553;
			}
			else{
				HX_STACK_LINE(137)
				::haxor::core::TextureType _g1 = p_texture->get_type();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(137)
				if (((_g1 == ::haxor::core::TextureType_obj::RenderTexture))){
					HX_STACK_LINE(137)
					target = (int)3553;
				}
				else{
					HX_STACK_LINE(137)
					::haxor::core::TextureType _g2 = p_texture->get_type();		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(137)
					if (((_g2 == ::haxor::core::TextureType_obj::TextureCube))){
						HX_STACK_LINE(137)
						target = (int)34067;
					}
					else{
						HX_STACK_LINE(137)
						target = (int)3553;
					}
				}
			}
			HX_STACK_LINE(137)
			this->Bind(p_texture,null());
			HX_STACK_LINE(137)
			::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10242,(  (((((int(p_texture->m_wrap) & int(::haxor::core::TextureWrap_obj::ClampX))) != (int)0))) ? int((int)33071) : int((int)10497) ));
			HX_STACK_LINE(137)
			::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10243,(  (((((int(p_texture->m_wrap) & int(::haxor::core::TextureWrap_obj::ClampY))) != (int)0))) ? int((int)33071) : int((int)10497) ));
			HX_STACK_LINE(137)
			if ((::haxor::graphics::GL_obj::TEXTURE_ANISOTROPY_ENABLED)){
				HX_STACK_LINE(137)
				Float p_value = ::Math_obj::max((int)1,p_texture->m_aniso);		HX_STACK_VAR(p_value,"p_value");
				HX_STACK_LINE(137)
				::haxor::graphics::GL_obj::m_gl->TexParameterf(target,::haxor::graphics::GL_obj::TEXTURE_ANISOTROPY,p_value);
			}
			HX_STACK_LINE(137)
			::haxor::core::TextureFilter minf = p_texture->m_minFilter;		HX_STACK_VAR(minf,"minf");
			HX_STACK_LINE(137)
			::haxor::core::TextureFilter magf = p_texture->m_magFilter;		HX_STACK_VAR(magf,"magf");
			HX_STACK_LINE(137)
			bool is_half = false;		HX_STACK_VAR(is_half,"is_half");
			HX_STACK_LINE(137)
			if (((p_texture->m_format == ::haxor::core::PixelFormat_obj::Half))){
				HX_STACK_LINE(137)
				is_half = true;
			}
			HX_STACK_LINE(137)
			if (((p_texture->m_format == ::haxor::core::PixelFormat_obj::Half3))){
				HX_STACK_LINE(137)
				is_half = true;
			}
			HX_STACK_LINE(137)
			if (((p_texture->m_format == ::haxor::core::PixelFormat_obj::Half4))){
				HX_STACK_LINE(137)
				is_half = true;
			}
			HX_STACK_LINE(137)
			bool is_float = false;		HX_STACK_VAR(is_float,"is_float");
			HX_STACK_LINE(137)
			if (((p_texture->m_format == ::haxor::core::PixelFormat_obj::_Float))){
				HX_STACK_LINE(137)
				is_float = true;
			}
			HX_STACK_LINE(137)
			if (((p_texture->m_format == ::haxor::core::PixelFormat_obj::Float3))){
				HX_STACK_LINE(137)
				is_float = true;
			}
			HX_STACK_LINE(137)
			if (((p_texture->m_format == ::haxor::core::PixelFormat_obj::Float4))){
				HX_STACK_LINE(137)
				is_float = true;
			}
			HX_STACK_LINE(137)
			if ((is_half)){
				HX_STACK_LINE(137)
				if ((!(::haxor::graphics::GL_obj::TEXTURE_HALF_LINEAR))){
					HX_STACK_LINE(137)
					minf = ::haxor::core::TextureFilter_obj::Nearest;
					HX_STACK_LINE(137)
					magf = ::haxor::core::TextureFilter_obj::Nearest;
				}
			}
			HX_STACK_LINE(137)
			if ((is_float)){
				HX_STACK_LINE(137)
				if ((!(::haxor::graphics::GL_obj::TEXTURE_FLOAT_LINEAR))){
					HX_STACK_LINE(137)
					minf = ::haxor::core::TextureFilter_obj::Nearest;
					HX_STACK_LINE(137)
					magf = ::haxor::core::TextureFilter_obj::Nearest;
				}
			}
			HX_STACK_LINE(137)
			switch( (int)(minf->__Index())){
				case (int)0: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9728);
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9986);
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9984);
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9729);
				}
				;break;
				case (int)5: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9987);
				}
				;break;
				case (int)6: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9987);
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9985);
				}
				;break;
			}
			HX_STACK_LINE(137)
			switch( (int)(magf->__Index())){
				case (int)0: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
				}
				;break;
				case (int)3: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
				}
				;break;
				case (int)1: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
				}
				;break;
				case (int)5: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
				}
				;break;
				case (int)6: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
				}
				;break;
				case (int)4: {
					HX_STACK_LINE(137)
					::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
				}
				;break;
			}
		}
		HX_STACK_LINE(139)
		::haxor::core::TextureType _g3 = p_texture->get_type();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(139)
		if (((_g3 != ::haxor::core::TextureType_obj::TextureCube))){
			HX_STACK_LINE(142)
			this->Alloc(p_texture);
		}
		HX_STACK_LINE(145)
		::haxor::core::TextureType _g4 = p_texture->get_type();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(145)
		if (((_g4 == ::haxor::core::TextureType_obj::RenderTexture))){
			HX_STACK_LINE(147)
			::haxor::graphics::texture::RenderTexture rt = p_texture;		HX_STACK_VAR(rt,"rt");
			HX_STACK_LINE(149)
			int fb_id = ::haxor::graphics::GL_obj::m_gl->CreateFramebuffer();		HX_STACK_VAR(fb_id,"fb_id");
			HX_STACK_LINE(150)
			this->framebuffers[p_texture->__cid] = fb_id;
			HX_STACK_LINE(152)
			::haxor::graphics::GL_obj::m_gl->BindFramebuffer((int)36160,fb_id);
			HX_STACK_LINE(156)
			::haxor::graphics::GL_obj::m_gl->FramebufferTexture2D((int)36160,(int)36064,(int)3553,id,(int)0);
			HX_STACK_LINE(158)
			if (((rt->m_depth != null()))){
				HX_STACK_LINE(160)
				int depth_id = this->ids->__get(rt->m_depth->__cid);		HX_STACK_VAR(depth_id,"depth_id");
				HX_STACK_LINE(161)
				::haxor::graphics::GL_obj::m_gl->FramebufferTexture2D((int)36160,(int)36096,(int)3553,depth_id,(int)0);
			}
			else{
				HX_STACK_LINE(165)
				int rb_id = ::haxor::graphics::GL_obj::m_gl->CreateRenderbuffer();		HX_STACK_VAR(rb_id,"rb_id");
				HX_STACK_LINE(166)
				this->renderbuffers[p_texture->__cid] = rb_id;
				HX_STACK_LINE(167)
				::haxor::graphics::GL_obj::m_gl->BindRenderbuffer((int)36161,rb_id);
				HX_STACK_LINE(168)
				::haxor::graphics::GL_obj::m_gl->RenderbufferStorage((int)36161,(int)33189,rt->m_width,rt->m_height);
				HX_STACK_LINE(169)
				::haxor::graphics::GL_obj::m_gl->FramebufferRenderbuffer((int)36160,(int)36096,(int)36161,rb_id);
			}
			HX_STACK_LINE(172)
			::haxor::graphics::GL_obj::m_gl->BindFramebuffer((int)36160,::haxor::graphics::GL_obj::_NULL);
			HX_STACK_LINE(173)
			::haxor::graphics::GL_obj::m_gl->BindRenderbuffer((int)36161,::haxor::graphics::GL_obj::_NULL);
			HX_STACK_LINE(174)
			this->Unbind();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,Create,(void))

Void TextureContext_obj::Bind( ::haxor::graphics::texture::Texture p_texture,hx::Null< int >  __o_p_slot){
int p_slot = __o_p_slot.Default(-1);
	HX_STACK_FRAME("haxor.context.TextureContext","Bind",0x4f3d09ec,"haxor.context.TextureContext.Bind","haxor/context/TextureContext.hx",184,0x7978261d)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_ARG(p_slot,"p_slot")
{
		HX_STACK_LINE(185)
		int slot = p_slot;		HX_STACK_VAR(slot,"slot");
		HX_STACK_LINE(189)
		if (((slot >= (int)0))){
			HX_STACK_LINE(191)
			::haxor::graphics::GL_obj::m_gl->ActiveTexture(((int)33984 + slot));
			HX_STACK_LINE(192)
			this->active = slot;
		}
		HX_STACK_LINE(197)
		{
			HX_STACK_LINE(199)
			int id = this->ids->__get(p_texture->__cid);		HX_STACK_VAR(id,"id");
			HX_STACK_LINE(200)
			::haxor::core::TextureType _g = p_texture->get_type();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(200)
			int target;		HX_STACK_VAR(target,"target");
			HX_STACK_LINE(200)
			if (((_g == ::haxor::core::TextureType_obj::Texture2D))){
				HX_STACK_LINE(200)
				target = (int)3553;
			}
			else{
				HX_STACK_LINE(200)
				::haxor::core::TextureType _g1 = p_texture->get_type();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(200)
				if (((_g1 == ::haxor::core::TextureType_obj::RenderTexture))){
					HX_STACK_LINE(200)
					target = (int)3553;
				}
				else{
					HX_STACK_LINE(200)
					::haxor::core::TextureType _g2 = p_texture->get_type();		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(200)
					if (((_g2 == ::haxor::core::TextureType_obj::TextureCube))){
						HX_STACK_LINE(200)
						target = (int)34067;
					}
					else{
						HX_STACK_LINE(200)
						target = (int)3553;
					}
				}
			}
			HX_STACK_LINE(202)
			::haxor::graphics::GL_obj::m_gl->BindTexture(target,id);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TextureContext_obj,Bind,(void))

Void TextureContext_obj::Unbind( ){
{
		HX_STACK_FRAME("haxor.context.TextureContext","Unbind",0xd1e2ba85,"haxor.context.TextureContext.Unbind","haxor/context/TextureContext.hx",217,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(217)
		::haxor::graphics::GL_obj::m_gl->BindTexture((int)3553,::haxor::graphics::GL_obj::_NULL);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TextureContext_obj,Unbind,(void))

Void TextureContext_obj::BindTarget( ::haxor::graphics::texture::RenderTexture rt){
{
		HX_STACK_FRAME("haxor.context.TextureContext","BindTarget",0x2d74aa5d,"haxor.context.TextureContext.BindTarget","haxor/context/TextureContext.hx",228,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(rt,"rt")
		HX_STACK_LINE(228)
		if (((rt == null()))){
			HX_STACK_LINE(230)
			if (((this->target != rt))){
				HX_STACK_LINE(232)
				::haxor::graphics::GL_obj::m_gl->BindFramebuffer((int)36160,::haxor::graphics::GL_obj::_NULL);
				HX_STACK_LINE(233)
				::haxor::graphics::GL_obj::m_gl->BindRenderbuffer((int)36161,::haxor::graphics::GL_obj::_NULL);
				HX_STACK_LINE(234)
				this->target = null();
			}
		}
		else{
			HX_STACK_LINE(239)
			if (((this->target != rt))){
				HX_STACK_LINE(241)
				int fb_id = this->framebuffers->__get(rt->__cid);		HX_STACK_VAR(fb_id,"fb_id");
				HX_STACK_LINE(242)
				::haxor::graphics::GL_obj::m_gl->BindFramebuffer((int)36160,fb_id);
				HX_STACK_LINE(243)
				if (((rt->m_depth == null()))){
					HX_STACK_LINE(245)
					int rb_id = this->renderbuffers->__get(rt->__cid);		HX_STACK_VAR(rb_id,"rb_id");
					HX_STACK_LINE(246)
					::haxor::graphics::GL_obj::m_gl->BindRenderbuffer((int)36161,rb_id);
				}
				HX_STACK_LINE(248)
				this->target = rt;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,BindTarget,(void))

Void TextureContext_obj::UpdateParameters( ::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.context.TextureContext","UpdateParameters",0x22b5acc2,"haxor.context.TextureContext.UpdateParameters","haxor/context/TextureContext.hx",260,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_texture,"p_texture")
		HX_STACK_LINE(261)
		::haxor::core::TextureType _g = p_texture->get_type();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(261)
		int target;		HX_STACK_VAR(target,"target");
		HX_STACK_LINE(261)
		if (((_g == ::haxor::core::TextureType_obj::Texture2D))){
			HX_STACK_LINE(261)
			target = (int)3553;
		}
		else{
			HX_STACK_LINE(261)
			::haxor::core::TextureType _g1 = p_texture->get_type();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(261)
			if (((_g1 == ::haxor::core::TextureType_obj::RenderTexture))){
				HX_STACK_LINE(261)
				target = (int)3553;
			}
			else{
				HX_STACK_LINE(261)
				::haxor::core::TextureType _g2 = p_texture->get_type();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(261)
				if (((_g2 == ::haxor::core::TextureType_obj::TextureCube))){
					HX_STACK_LINE(261)
					target = (int)34067;
				}
				else{
					HX_STACK_LINE(261)
					target = (int)3553;
				}
			}
		}
		HX_STACK_LINE(263)
		this->Bind(p_texture,null());
		HX_STACK_LINE(265)
		::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10242,(  (((((int(p_texture->m_wrap) & int(::haxor::core::TextureWrap_obj::ClampX))) != (int)0))) ? int((int)33071) : int((int)10497) ));
		HX_STACK_LINE(266)
		::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10243,(  (((((int(p_texture->m_wrap) & int(::haxor::core::TextureWrap_obj::ClampY))) != (int)0))) ? int((int)33071) : int((int)10497) ));
		HX_STACK_LINE(269)
		if ((::haxor::graphics::GL_obj::TEXTURE_ANISOTROPY_ENABLED)){
			HX_STACK_LINE(269)
			Float p_value = ::Math_obj::max((int)1,p_texture->m_aniso);		HX_STACK_VAR(p_value,"p_value");
			HX_STACK_LINE(269)
			::haxor::graphics::GL_obj::m_gl->TexParameterf(target,::haxor::graphics::GL_obj::TEXTURE_ANISOTROPY,p_value);
		}
		HX_STACK_LINE(271)
		::haxor::core::TextureFilter minf = p_texture->m_minFilter;		HX_STACK_VAR(minf,"minf");
		HX_STACK_LINE(272)
		::haxor::core::TextureFilter magf = p_texture->m_magFilter;		HX_STACK_VAR(magf,"magf");
		HX_STACK_LINE(274)
		bool is_half = false;		HX_STACK_VAR(is_half,"is_half");
		HX_STACK_LINE(275)
		if (((p_texture->m_format == ::haxor::core::PixelFormat_obj::Half))){
			HX_STACK_LINE(275)
			is_half = true;
		}
		HX_STACK_LINE(276)
		if (((p_texture->m_format == ::haxor::core::PixelFormat_obj::Half3))){
			HX_STACK_LINE(276)
			is_half = true;
		}
		HX_STACK_LINE(277)
		if (((p_texture->m_format == ::haxor::core::PixelFormat_obj::Half4))){
			HX_STACK_LINE(277)
			is_half = true;
		}
		HX_STACK_LINE(279)
		bool is_float = false;		HX_STACK_VAR(is_float,"is_float");
		HX_STACK_LINE(280)
		if (((p_texture->m_format == ::haxor::core::PixelFormat_obj::_Float))){
			HX_STACK_LINE(280)
			is_float = true;
		}
		HX_STACK_LINE(281)
		if (((p_texture->m_format == ::haxor::core::PixelFormat_obj::Float3))){
			HX_STACK_LINE(281)
			is_float = true;
		}
		HX_STACK_LINE(282)
		if (((p_texture->m_format == ::haxor::core::PixelFormat_obj::Float4))){
			HX_STACK_LINE(282)
			is_float = true;
		}
		HX_STACK_LINE(286)
		if ((is_half)){
			HX_STACK_LINE(287)
			if ((!(::haxor::graphics::GL_obj::TEXTURE_HALF_LINEAR))){
				HX_STACK_LINE(289)
				minf = ::haxor::core::TextureFilter_obj::Nearest;
				HX_STACK_LINE(290)
				magf = ::haxor::core::TextureFilter_obj::Nearest;
			}
		}
		HX_STACK_LINE(293)
		if ((is_float)){
			HX_STACK_LINE(294)
			if ((!(::haxor::graphics::GL_obj::TEXTURE_FLOAT_LINEAR))){
				HX_STACK_LINE(296)
				minf = ::haxor::core::TextureFilter_obj::Nearest;
				HX_STACK_LINE(297)
				magf = ::haxor::core::TextureFilter_obj::Nearest;
			}
		}
		HX_STACK_LINE(300)
		switch( (int)(minf->__Index())){
			case (int)0: {
				HX_STACK_LINE(302)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9728);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(303)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9986);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(304)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9984);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(305)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9729);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(306)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9987);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(307)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9987);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(308)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9985);
			}
			;break;
		}
		HX_STACK_LINE(313)
		switch( (int)(magf->__Index())){
			case (int)0: {
				HX_STACK_LINE(315)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(316)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(317)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(318)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(319)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(320)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(321)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,UpdateParameters,(void))

Void TextureContext_obj::Update( ::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.context.TextureContext","Update",0xf9fc43f8,"haxor.context.TextureContext.Update","haxor/context/TextureContext.hx",330,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_texture,"p_texture")
		HX_STACK_LINE(331)
		::haxor::core::TextureType _g = p_texture->get_type();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(331)
		int target;		HX_STACK_VAR(target,"target");
		HX_STACK_LINE(331)
		if (((_g == ::haxor::core::TextureType_obj::Texture2D))){
			HX_STACK_LINE(331)
			target = (int)3553;
		}
		else{
			HX_STACK_LINE(331)
			::haxor::core::TextureType _g1 = p_texture->get_type();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(331)
			if (((_g1 == ::haxor::core::TextureType_obj::RenderTexture))){
				HX_STACK_LINE(331)
				target = (int)3553;
			}
			else{
				HX_STACK_LINE(331)
				::haxor::core::TextureType _g2 = p_texture->get_type();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(331)
				if (((_g2 == ::haxor::core::TextureType_obj::TextureCube))){
					HX_STACK_LINE(331)
					target = (int)34067;
				}
				else{
					HX_STACK_LINE(331)
					target = (int)3553;
				}
			}
		}
		HX_STACK_LINE(332)
		this->Bind(p_texture,null());
		HX_STACK_LINE(333)
		if (((target == (int)34067))){
			HX_STACK_LINE(335)
			::haxor::graphics::texture::TextureCube tc = p_texture;		HX_STACK_VAR(tc,"tc");
			HX_STACK_LINE(336)
			if (((tc->m_faces->__get((int)0).StaticCast< ::haxor::graphics::texture::Texture >() != null()))){
				HX_STACK_LINE(336)
				this->WriteTexture((int)34069,tc->m_faces->__get((int)0).StaticCast< ::haxor::graphics::texture::Texture >());
			}
			HX_STACK_LINE(337)
			if (((tc->m_faces->__get((int)1).StaticCast< ::haxor::graphics::texture::Texture >() != null()))){
				HX_STACK_LINE(337)
				this->WriteTexture((int)34070,tc->m_faces->__get((int)1).StaticCast< ::haxor::graphics::texture::Texture >());
			}
			HX_STACK_LINE(338)
			if (((tc->m_faces->__get((int)2).StaticCast< ::haxor::graphics::texture::Texture >() != null()))){
				HX_STACK_LINE(338)
				this->WriteTexture((int)34071,tc->m_faces->__get((int)2).StaticCast< ::haxor::graphics::texture::Texture >());
			}
			HX_STACK_LINE(339)
			if (((tc->m_faces->__get((int)3).StaticCast< ::haxor::graphics::texture::Texture >() != null()))){
				HX_STACK_LINE(339)
				this->WriteTexture((int)34072,tc->m_faces->__get((int)3).StaticCast< ::haxor::graphics::texture::Texture >());
			}
			HX_STACK_LINE(340)
			if (((tc->m_faces->__get((int)4).StaticCast< ::haxor::graphics::texture::Texture >() != null()))){
				HX_STACK_LINE(340)
				this->WriteTexture((int)34073,tc->m_faces->__get((int)4).StaticCast< ::haxor::graphics::texture::Texture >());
			}
			HX_STACK_LINE(341)
			if (((tc->m_faces->__get((int)5).StaticCast< ::haxor::graphics::texture::Texture >() != null()))){
				HX_STACK_LINE(341)
				this->WriteTexture((int)34074,tc->m_faces->__get((int)5).StaticCast< ::haxor::graphics::texture::Texture >());
			}
		}
		else{
			HX_STACK_LINE(345)
			this->WriteTexture(target,p_texture);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,Update,(void))

Void TextureContext_obj::UploadTexture( ::haxor::graphics::texture::Texture2D p_texture,int p_x,int p_y,int p_width,int p_height,int p_steps,Dynamic p_on_complete){
{
		HX_STACK_FRAME("haxor.context.TextureContext","UploadTexture",0x305b46cb,"haxor.context.TextureContext.UploadTexture","haxor/context/TextureContext.hx",354,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_texture,"p_texture")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_ARG(p_steps,"p_steps")
		HX_STACK_ARG(p_on_complete,"p_on_complete")
		HX_STACK_LINE(354)
		Dynamic p_on_complete1 = Dynamic( Array_obj<Dynamic>::__new().Add(p_on_complete));		HX_STACK_VAR(p_on_complete1,"p_on_complete1");
		HX_STACK_LINE(354)
		Array< int > p_height1 = Array_obj< int >::__new().Add(p_height);		HX_STACK_VAR(p_height1,"p_height1");
		HX_STACK_LINE(354)
		Array< int > p_width1 = Array_obj< int >::__new().Add(p_width);		HX_STACK_VAR(p_width1,"p_width1");
		HX_STACK_LINE(354)
		Array< int > p_x1 = Array_obj< int >::__new().Add(p_x);		HX_STACK_VAR(p_x1,"p_x1");
		HX_STACK_LINE(354)
		Array< ::Dynamic > p_texture1 = Array_obj< ::Dynamic >::__new().Add(p_texture);		HX_STACK_VAR(p_texture1,"p_texture1");
		HX_STACK_LINE(354)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(356)
		Array< ::Dynamic > b = Array_obj< ::Dynamic >::__new().Add(p_texture1->__get((int)0).StaticCast< ::haxor::graphics::texture::Texture2D >()->m_data);		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(357)
		Array< int > py = Array_obj< int >::__new().Add(p_y);		HX_STACK_VAR(py,"py");
		HX_STACK_LINE(358)
		Array< int > chn_fmt = Array_obj< int >::__new().Add(::haxor::context::TextureContext_obj::FormatToChannelLayout(p_texture1->__get((int)0).StaticCast< ::haxor::graphics::texture::Texture2D >()->m_format));		HX_STACK_VAR(chn_fmt,"chn_fmt");
		HX_STACK_LINE(359)
		int chn_bit = ::haxor::context::TextureContext_obj::FormatToChannelBits(p_texture1->__get((int)0).StaticCast< ::haxor::graphics::texture::Texture2D >()->m_format);		HX_STACK_VAR(chn_bit,"chn_bit");
		HX_STACK_LINE(360)
		Array< int > chn_type = Array_obj< int >::__new().Add(::haxor::context::TextureContext_obj::FormatToChannelType(p_texture1->__get((int)0).StaticCast< ::haxor::graphics::texture::Texture2D >()->m_format));		HX_STACK_VAR(chn_type,"chn_type");
		HX_STACK_LINE(361)
		Array< int > steps = Array_obj< int >::__new().Add(::Std_obj::_int((Float(p_height1->__get((int)0)) / Float(p_steps))));		HX_STACK_VAR(steps,"steps");
		HX_STACK_LINE(362)
		if (((steps->__get((int)0) <= (int)1))){
			HX_STACK_LINE(362)
			steps[(int)0] = (int)1;
		}

		HX_BEGIN_LOCAL_FUNC_S11(hx::LocalFunc,_Function_1_1,Array< int >,steps,Array< int >,p_x1,Array< int >,p_width1,Array< ::Dynamic >,_g,Array< int >,chn_fmt,Dynamic,p_on_complete1,Array< ::Dynamic >,b,Array< int >,chn_type,Array< int >,p_height1,Array< ::Dynamic >,p_texture1,Array< int >,py)
		bool run(Float t){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","haxor/context/TextureContext.hx",364,0x7978261d)
			HX_STACK_ARG(t,"t")
			{
				HX_STACK_LINE(365)
				if (((py->__get((int)0) >= p_height1->__get((int)0)))){
					HX_STACK_LINE(365)
					if (((p_on_complete1->__GetItem((int)0) != null()))){
						HX_STACK_LINE(365)
						p_on_complete1->__GetItem((int)0)().Cast< Void >();
					}
					HX_STACK_LINE(365)
					return false;
				}
				HX_STACK_LINE(366)
				_g->__get((int)0).StaticCast< ::haxor::context::TextureContext >()->Bind(p_texture1->__get((int)0).StaticCast< ::haxor::graphics::texture::Texture2D >(),null());
				HX_STACK_LINE(367)
				{
					HX_STACK_LINE(367)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(367)
					while(((_g1 < steps->__get((int)0)))){
						HX_STACK_LINE(367)
						int i = (_g1)++;		HX_STACK_VAR(i,"i");
						HX_STACK_LINE(369)
						if (((py->__get((int)0) < (int)0))){
							HX_STACK_LINE(369)
							(py[(int)0])++;
							HX_STACK_LINE(369)
							continue;
						}
						HX_STACK_LINE(370)
						if (((py->__get((int)0) >= b->__get((int)0).StaticCast< ::haxor::graphics::texture::Bitmap >()->m_height))){
							HX_STACK_LINE(370)
							if (((p_on_complete1->__GetItem((int)0) != null()))){
								HX_STACK_LINE(370)
								p_on_complete1->__GetItem((int)0)().Cast< Void >();
							}
							HX_STACK_LINE(370)
							return false;
						}
						HX_STACK_LINE(371)
						int pos = (((p_x1->__get((int)0) + (py->__get((int)0) * p_width1->__get((int)0)))) * b->__get((int)0).StaticCast< ::haxor::graphics::texture::Bitmap >()->m_channels);		HX_STACK_VAR(pos,"pos");
						HX_STACK_LINE(372)
						int len = (p_width1->__get((int)0) * b->__get((int)0).StaticCast< ::haxor::graphics::texture::Bitmap >()->m_channels);		HX_STACK_VAR(len,"len");
						HX_STACK_LINE(373)
						b->__get((int)0).StaticCast< ::haxor::graphics::texture::Bitmap >()->get_buffer()->SetViewSlice(pos,len);
						HX_STACK_LINE(374)
						{
							HX_STACK_LINE(374)
							::haxor::io::Buffer p_data = b->__get((int)0).StaticCast< ::haxor::graphics::texture::Bitmap >()->get_buffer();		HX_STACK_VAR(p_data,"p_data");
							HX_STACK_LINE(374)
							::haxor::graphics::GL_obj::m_gl->TexSubImage2D((int)3553,(int)0,p_x1->__get((int)0),py->__get((int)0),p_width1->__get((int)0),(int)1,chn_fmt->__get((int)0),chn_type->__get((int)0),p_data);
						}
						HX_STACK_LINE(375)
						b->__get((int)0).StaticCast< ::haxor::graphics::texture::Bitmap >()->get_buffer()->ResetSlice();
						HX_STACK_LINE(376)
						(py[(int)0])++;
					}
				}
				HX_STACK_LINE(378)
				return true;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(363)
		::haxor::thread::Activity ua = ::haxor::thread::Activity_obj::__new( Dynamic(new _Function_1_1(steps,p_x1,p_width1,_g,chn_fmt,p_on_complete1,b,chn_type,p_height1,p_texture1,py)),false,true);		HX_STACK_VAR(ua,"ua");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(TextureContext_obj,UploadTexture,(void))

Void TextureContext_obj::WriteTexture( int p_target,::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.context.TextureContext","WriteTexture",0x9ebbc8eb,"haxor.context.TextureContext.WriteTexture","haxor/context/TextureContext.hx",388,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_texture,"p_texture")
		HX_STACK_LINE(389)
		int w = p_texture->m_width;		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(390)
		int h = p_texture->m_height;		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(391)
		int chn_fmt = ::haxor::context::TextureContext_obj::FormatToChannelLayout(p_texture->m_format);		HX_STACK_VAR(chn_fmt,"chn_fmt");
		HX_STACK_LINE(392)
		int chn_bit = ::haxor::context::TextureContext_obj::FormatToChannelBits(p_texture->m_format);		HX_STACK_VAR(chn_bit,"chn_bit");
		HX_STACK_LINE(393)
		int chn_type = ::haxor::context::TextureContext_obj::FormatToChannelType(p_texture->m_format);		HX_STACK_VAR(chn_type,"chn_type");
		HX_STACK_LINE(395)
		if (((p_texture->m_format == ::haxor::core::PixelFormat_obj::Depth))){
			HX_STACK_LINE(397)
			::haxor::graphics::GL_obj::m_gl->TexImage2DAlloc(p_target,(int)0,chn_fmt,w,h,(int)0,chn_fmt,chn_type);
		}
		else{
			HX_STACK_LINE(401)
			::haxor::core::TextureType _g = p_texture->get_type();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(401)
			bool is_ti2d;		HX_STACK_VAR(is_ti2d,"is_ti2d");
			HX_STACK_LINE(401)
			if ((!(((_g == ::haxor::core::TextureType_obj::Compute))))){
				HX_STACK_LINE(401)
				::haxor::core::TextureType _g1 = p_texture->get_type();		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(401)
				is_ti2d = (_g1 == ::haxor::core::TextureType_obj::Texture2D);
			}
			else{
				HX_STACK_LINE(401)
				is_ti2d = true;
			}
			HX_STACK_LINE(402)
			if ((is_ti2d)){
				HX_STACK_LINE(404)
				::haxor::graphics::texture::Texture2D t2d = p_texture;		HX_STACK_VAR(t2d,"t2d");
				HX_STACK_LINE(406)
				{
					HX_STACK_LINE(406)
					::haxor::io::Buffer p_data = t2d->m_data->get_buffer();		HX_STACK_VAR(p_data,"p_data");
					HX_STACK_LINE(406)
					::haxor::graphics::GL_obj::m_gl->TexImage2D(p_target,(int)0,chn_fmt,w,h,(int)0,chn_bit,chn_type,p_data);
				}
			}
			else{
				HX_STACK_LINE(409)
				::haxor::core::TextureType _g2 = p_texture->get_type();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(409)
				if (((_g2 == ::haxor::core::TextureType_obj::RenderTexture))){
					HX_STACK_LINE(411)
					::haxor::graphics::texture::RenderTexture rt = p_texture;		HX_STACK_VAR(rt,"rt");
					HX_STACK_LINE(412)
					int id = this->ids->__get(rt->__cid);		HX_STACK_VAR(id,"id");
					HX_STACK_LINE(413)
					::haxor::graphics::GL_obj::m_gl->FramebufferTexture2D((int)36160,(int)36064,p_target,id,(int)0);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TextureContext_obj,WriteTexture,(void))

Void TextureContext_obj::UpdateMipmaps( ::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.context.TextureContext","UpdateMipmaps",0x5ce57cd3,"haxor.context.TextureContext.UpdateMipmaps","haxor/context/TextureContext.hx",424,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_texture,"p_texture")
		HX_STACK_LINE(425)
		this->Bind(p_texture,null());
		HX_STACK_LINE(426)
		::haxor::core::TextureType _g = p_texture->get_type();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(426)
		int target;		HX_STACK_VAR(target,"target");
		HX_STACK_LINE(426)
		if (((_g == ::haxor::core::TextureType_obj::Texture2D))){
			HX_STACK_LINE(426)
			target = (int)3553;
		}
		else{
			HX_STACK_LINE(426)
			::haxor::core::TextureType _g1 = p_texture->get_type();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(426)
			if (((_g1 == ::haxor::core::TextureType_obj::RenderTexture))){
				HX_STACK_LINE(426)
				target = (int)3553;
			}
			else{
				HX_STACK_LINE(426)
				::haxor::core::TextureType _g2 = p_texture->get_type();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(426)
				if (((_g2 == ::haxor::core::TextureType_obj::TextureCube))){
					HX_STACK_LINE(426)
					target = (int)34067;
				}
				else{
					HX_STACK_LINE(426)
					target = (int)3553;
				}
			}
		}
		HX_STACK_LINE(427)
		::haxor::graphics::GL_obj::m_gl->GenerateMipmap(target);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,UpdateMipmaps,(void))

Void TextureContext_obj::Destroy( ::haxor::graphics::texture::Texture p_texture){
{
		HX_STACK_FRAME("haxor.context.TextureContext","Destroy",0x4975a02b,"haxor.context.TextureContext.Destroy","haxor/context/TextureContext.hx",435,0x7978261d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_texture,"p_texture")
		HX_STACK_LINE(436)
		int tex_id = this->ids->__get(p_texture->__cid);		HX_STACK_VAR(tex_id,"tex_id");
		HX_STACK_LINE(437)
		if (((tex_id != ::haxor::graphics::GL_obj::INVALID))){
			HX_STACK_LINE(437)
			::haxor::graphics::GL_obj::m_gl->DeleteTexture(tex_id);
		}
		HX_STACK_LINE(438)
		::haxor::core::TextureType _g = p_texture->get_type();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(438)
		if (((_g == ::haxor::core::TextureType_obj::RenderTexture))){
			HX_STACK_LINE(440)
			int fb_id = this->framebuffers->__get(p_texture->__cid);		HX_STACK_VAR(fb_id,"fb_id");
			HX_STACK_LINE(441)
			int rb_id = this->renderbuffers->__get(p_texture->__cid);		HX_STACK_VAR(rb_id,"rb_id");
			HX_STACK_LINE(442)
			if (((fb_id != ::haxor::graphics::GL_obj::INVALID))){
				HX_STACK_LINE(442)
				::haxor::graphics::GL_obj::m_gl->DeleteFramebuffer(fb_id);
			}
			HX_STACK_LINE(443)
			if (((rb_id != ::haxor::graphics::GL_obj::INVALID))){
				HX_STACK_LINE(443)
				::haxor::graphics::GL_obj::m_gl->DeleteRenderbuffer(rb_id);
			}
		}
		HX_STACK_LINE(445)
		{
			HX_STACK_LINE(445)
			int v = p_texture->__cid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(445)
			::haxor::context::EngineContext_obj::texture->tid->m_cache->push(v);
			HX_STACK_LINE(445)
			v;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,Destroy,(void))

int TextureContext_obj::TextureToTarget( ::haxor::graphics::texture::Texture p_texture){
	HX_STACK_FRAME("haxor.context.TextureContext","TextureToTarget",0x139a7f58,"haxor.context.TextureContext.TextureToTarget","haxor/context/TextureContext.hx",454,0x7978261d)
	HX_STACK_ARG(p_texture,"p_texture")
	HX_STACK_LINE(455)
	::haxor::core::TextureType _g = p_texture->get_type();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(455)
	if (((_g == ::haxor::core::TextureType_obj::Texture2D))){
		HX_STACK_LINE(455)
		return (int)3553;
	}
	HX_STACK_LINE(456)
	::haxor::core::TextureType _g1 = p_texture->get_type();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(456)
	if (((_g1 == ::haxor::core::TextureType_obj::RenderTexture))){
		HX_STACK_LINE(456)
		return (int)3553;
	}
	HX_STACK_LINE(457)
	::haxor::core::TextureType _g2 = p_texture->get_type();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(457)
	if (((_g2 == ::haxor::core::TextureType_obj::TextureCube))){
		HX_STACK_LINE(457)
		return (int)34067;
	}
	HX_STACK_LINE(458)
	return (int)3553;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,TextureToTarget,return )

int TextureContext_obj::FormatToChannelBits( ::haxor::core::PixelFormat p_format){
	HX_STACK_FRAME("haxor.context.TextureContext","FormatToChannelBits",0x426a86a8,"haxor.context.TextureContext.FormatToChannelBits","haxor/context/TextureContext.hx",467,0x7978261d)
	HX_STACK_ARG(p_format,"p_format")
	HX_STACK_LINE(468)
	switch( (int)(p_format->__Index())){
		case (int)0: {
			HX_STACK_LINE(470)
			return (int)6406;
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(471)
			return (int)6407;
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(472)
			return (int)6408;
		}
		;break;
		case (int)7: case (int)4: {
			HX_STACK_LINE(473)
			return (int)6409;
		}
		;break;
		case (int)8: case (int)5: {
			HX_STACK_LINE(474)
			return (int)6407;
		}
		;break;
		case (int)9: case (int)6: {
			HX_STACK_LINE(475)
			return (int)6408;
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(476)
			return (int)6409;
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(477)
			return (int)6402;
		}
		;break;
	}
	HX_STACK_LINE(479)
	return (int)6408;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,FormatToChannelBits,return )

int TextureContext_obj::FormatToChannelType( ::haxor::core::PixelFormat p_format){
	HX_STACK_FRAME("haxor.context.TextureContext","FormatToChannelType",0x4e5c7e5c,"haxor.context.TextureContext.FormatToChannelType","haxor/context/TextureContext.hx",488,0x7978261d)
	HX_STACK_ARG(p_format,"p_format")
	HX_STACK_LINE(491)
	switch( (int)(p_format->__Index())){
		case (int)4: case (int)5: case (int)6: {
			HX_STACK_LINE(494)
			if ((::haxor::graphics::GL_obj::TEXTURE_HALF)){
				HX_STACK_LINE(494)
				return ::haxor::graphics::GL_obj::HALF_FLOAT;
			}
			else{
				HX_STACK_LINE(494)
				return (int)5121;
			}
		}
		;break;
		case (int)7: case (int)8: case (int)9: {
			HX_STACK_LINE(495)
			if ((::haxor::graphics::GL_obj::TEXTURE_FLOAT)){
				HX_STACK_LINE(495)
				return (int)5126;
			}
			else{
				HX_STACK_LINE(495)
				if ((::haxor::graphics::GL_obj::TEXTURE_HALF)){
					HX_STACK_LINE(495)
					return ::haxor::graphics::GL_obj::HALF_FLOAT;
				}
				else{
					HX_STACK_LINE(495)
					return (int)5121;
				}
			}
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(496)
			return (int)5123;
		}
		;break;
		case (int)3: case (int)2: case (int)1: case (int)0: {
			HX_STACK_LINE(497)
			return (int)5121;
		}
		;break;
	}
	HX_STACK_LINE(499)
	return (int)5121;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,FormatToChannelType,return )

int TextureContext_obj::FormatToChannelLayout( ::haxor::core::PixelFormat p_format){
	HX_STACK_FRAME("haxor.context.TextureContext","FormatToChannelLayout",0xfebfe6cc,"haxor.context.TextureContext.FormatToChannelLayout","haxor/context/TextureContext.hx",508,0x7978261d)
	HX_STACK_ARG(p_format,"p_format")
	HX_STACK_LINE(509)
	switch( (int)(p_format->__Index())){
		case (int)0: {
			HX_STACK_LINE(511)
			return (int)6406;
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(512)
			return (int)6407;
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(513)
			return (int)6408;
		}
		;break;
		case (int)1: case (int)4: case (int)7: {
			HX_STACK_LINE(514)
			return (int)6409;
		}
		;break;
		case (int)8: case (int)5: {
			HX_STACK_LINE(515)
			return (int)6407;
		}
		;break;
		case (int)9: case (int)6: {
			HX_STACK_LINE(516)
			return (int)6408;
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(517)
			return (int)6402;
		}
		;break;
	}
	HX_STACK_LINE(519)
	return (int)6408;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(TextureContext_obj,FormatToChannelLayout,return )


TextureContext_obj::TextureContext_obj()
{
}

void TextureContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TextureContext);
	HX_MARK_MEMBER_NAME(tid,"tid");
	HX_MARK_MEMBER_NAME(ids,"ids");
	HX_MARK_MEMBER_NAME(framebuffers,"framebuffers");
	HX_MARK_MEMBER_NAME(renderbuffers,"renderbuffers");
	HX_MARK_MEMBER_NAME(target,"target");
	HX_MARK_MEMBER_NAME(bind,"bind");
	HX_MARK_MEMBER_NAME(active,"active");
	HX_MARK_MEMBER_NAME(next_slot,"next_slot");
	HX_MARK_MEMBER_NAME(is_flip_y,"is_flip_y");
	HX_MARK_END_CLASS();
}

void TextureContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(tid,"tid");
	HX_VISIT_MEMBER_NAME(ids,"ids");
	HX_VISIT_MEMBER_NAME(framebuffers,"framebuffers");
	HX_VISIT_MEMBER_NAME(renderbuffers,"renderbuffers");
	HX_VISIT_MEMBER_NAME(target,"target");
	HX_VISIT_MEMBER_NAME(bind,"bind");
	HX_VISIT_MEMBER_NAME(active,"active");
	HX_VISIT_MEMBER_NAME(next_slot,"next_slot");
	HX_VISIT_MEMBER_NAME(is_flip_y,"is_flip_y");
}

Dynamic TextureContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"tid") ) { return tid; }
		if (HX_FIELD_EQ(inName,"ids") ) { return ids; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"bind") ) { return bind; }
		if (HX_FIELD_EQ(inName,"Bind") ) { return Bind_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Alloc") ) { return Alloc_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { return target; }
		if (HX_FIELD_EQ(inName,"active") ) { return active; }
		if (HX_FIELD_EQ(inName,"Create") ) { return Create_dyn(); }
		if (HX_FIELD_EQ(inName,"Unbind") ) { return Unbind_dyn(); }
		if (HX_FIELD_EQ(inName,"Update") ) { return Update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Destroy") ) { return Destroy_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"next_slot") ) { return next_slot; }
		if (HX_FIELD_EQ(inName,"is_flip_y") ) { return is_flip_y; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"BindTarget") ) { return BindTarget_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"framebuffers") ) { return framebuffers; }
		if (HX_FIELD_EQ(inName,"WriteTexture") ) { return WriteTexture_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"renderbuffers") ) { return renderbuffers; }
		if (HX_FIELD_EQ(inName,"UploadTexture") ) { return UploadTexture_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateMipmaps") ) { return UpdateMipmaps_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"TextureToTarget") ) { return TextureToTarget_dyn(); }
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
		if (HX_FIELD_EQ(inName,"tid") ) { tid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ids") ) { ids=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"bind") ) { bind=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"target") ) { target=inValue.Cast< ::haxor::graphics::texture::RenderTexture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"active") ) { active=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"next_slot") ) { next_slot=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"is_flip_y") ) { is_flip_y=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"framebuffers") ) { framebuffers=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"renderbuffers") ) { renderbuffers=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TextureContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tid"));
	outFields->push(HX_CSTRING("ids"));
	outFields->push(HX_CSTRING("framebuffers"));
	outFields->push(HX_CSTRING("renderbuffers"));
	outFields->push(HX_CSTRING("target"));
	outFields->push(HX_CSTRING("bind"));
	outFields->push(HX_CSTRING("active"));
	outFields->push(HX_CSTRING("next_slot"));
	outFields->push(HX_CSTRING("is_flip_y"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("TextureToTarget"),
	HX_CSTRING("FormatToChannelBits"),
	HX_CSTRING("FormatToChannelType"),
	HX_CSTRING("FormatToChannelLayout"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(TextureContext_obj,tid),HX_CSTRING("tid")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(TextureContext_obj,ids),HX_CSTRING("ids")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(TextureContext_obj,framebuffers),HX_CSTRING("framebuffers")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(TextureContext_obj,renderbuffers),HX_CSTRING("renderbuffers")},
	{hx::fsObject /*::haxor::graphics::texture::RenderTexture*/ ,(int)offsetof(TextureContext_obj,target),HX_CSTRING("target")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(TextureContext_obj,bind),HX_CSTRING("bind")},
	{hx::fsInt,(int)offsetof(TextureContext_obj,active),HX_CSTRING("active")},
	{hx::fsInt,(int)offsetof(TextureContext_obj,next_slot),HX_CSTRING("next_slot")},
	{hx::fsBool,(int)offsetof(TextureContext_obj,is_flip_y),HX_CSTRING("is_flip_y")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("tid"),
	HX_CSTRING("ids"),
	HX_CSTRING("framebuffers"),
	HX_CSTRING("renderbuffers"),
	HX_CSTRING("target"),
	HX_CSTRING("bind"),
	HX_CSTRING("active"),
	HX_CSTRING("next_slot"),
	HX_CSTRING("is_flip_y"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Alloc"),
	HX_CSTRING("Create"),
	HX_CSTRING("Bind"),
	HX_CSTRING("Unbind"),
	HX_CSTRING("BindTarget"),
	HX_CSTRING("UpdateParameters"),
	HX_CSTRING("Update"),
	HX_CSTRING("UploadTexture"),
	HX_CSTRING("WriteTexture"),
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
