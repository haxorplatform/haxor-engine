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
#ifndef INCLUDED_haxor_graphics_GL
#include <haxor/graphics/GL.h>
#endif
#ifndef INCLUDED_haxor_graphics_GraphicContext
#include <haxor/graphics/GraphicContext.h>
#endif
#ifndef INCLUDED_haxor_graphics_PixelFormat
#include <haxor/graphics/PixelFormat.h>
#endif
#ifndef INCLUDED_haxor_graphics_TextureFilter
#include <haxor/graphics/TextureFilter.h>
#endif
#ifndef INCLUDED_haxor_graphics_TextureType
#include <haxor/graphics/TextureType.h>
#endif
#ifndef INCLUDED_haxor_graphics_TextureWrap
#include <haxor/graphics/TextureWrap.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_graphics_WinGL
#include <haxor/platform/windows/graphics/WinGL.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace graphics{
namespace texture{

Void Texture_obj::__construct()
{
HX_STACK_FRAME("haxor.graphics.texture.Texture","new",0x9dbfa5a3,"haxor.graphics.texture.Texture.new","haxor/graphics/texture/Texture.hx",92,0x91e47a4e)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(93)
	super::__construct(null());
	HX_STACK_LINE(94)
	this->m_mipmaps = false;
	HX_STACK_LINE(95)
	this->m_format = ::haxor::graphics::PixelFormat_obj::RGBA8;
	HX_STACK_LINE(96)
	this->m_minFilter = ::haxor::graphics::TextureFilter_obj::Linear;
	HX_STACK_LINE(97)
	this->m_magFilter = ::haxor::graphics::TextureFilter_obj::Linear;
	HX_STACK_LINE(98)
	this->m_wrap = (int((int(::haxor::graphics::TextureWrap_obj::ClampX) | int(::haxor::graphics::TextureWrap_obj::ClampY))) | int(::haxor::graphics::TextureWrap_obj::ClampZ));
	HX_STACK_LINE(99)
	this->m_width = (int)0;
	HX_STACK_LINE(100)
	this->m_height = (int)0;
	HX_STACK_LINE(101)
	this->m_aniso = (int)0;
	HX_STACK_LINE(102)
	int _g = (::haxor::context::EngineContext_obj::texture->tid)++;		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(102)
	this->_cid_ = _g;
}
;
	return null();
}

//Texture_obj::~Texture_obj() { }

Dynamic Texture_obj::__CreateEmpty() { return  new Texture_obj; }
hx::ObjectPtr< Texture_obj > Texture_obj::__new()
{  hx::ObjectPtr< Texture_obj > result = new Texture_obj();
	result->__construct();
	return result;}

Dynamic Texture_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Texture_obj > result = new Texture_obj();
	result->__construct();
	return result;}

int Texture_obj::get_width( ){
	HX_STACK_FRAME("haxor.graphics.texture.Texture","get_width",0x4ba3bbe0,"haxor.graphics.texture.Texture.get_width","haxor/graphics/texture/Texture.hx",21,0x91e47a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(21)
	return this->m_width;
}


HX_DEFINE_DYNAMIC_FUNC0(Texture_obj,get_width,return )

int Texture_obj::get_height( ){
	HX_STACK_FRAME("haxor.graphics.texture.Texture","get_height",0x99f020cd,"haxor.graphics.texture.Texture.get_height","haxor/graphics/texture/Texture.hx",28,0x91e47a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(28)
	return this->m_height;
}


HX_DEFINE_DYNAMIC_FUNC0(Texture_obj,get_height,return )

::haxor::graphics::PixelFormat Texture_obj::get_format( ){
	HX_STACK_FRAME("haxor.graphics.texture.Texture","get_format",0x9532a81d,"haxor.graphics.texture.Texture.get_format","haxor/graphics/texture/Texture.hx",35,0x91e47a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(35)
	return this->m_format;
}


HX_DEFINE_DYNAMIC_FUNC0(Texture_obj,get_format,return )

int Texture_obj::get_wrap( ){
	HX_STACK_FRAME("haxor.graphics.texture.Texture","get_wrap",0x7b332d30,"haxor.graphics.texture.Texture.get_wrap","haxor/graphics/texture/Texture.hx",42,0x91e47a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(42)
	return this->m_wrap;
}


HX_DEFINE_DYNAMIC_FUNC0(Texture_obj,get_wrap,return )

int Texture_obj::set_wrap( int v){
	HX_STACK_FRAME("haxor.graphics.texture.Texture","set_wrap",0x299086a4,"haxor.graphics.texture.Texture.set_wrap","haxor/graphics/texture/Texture.hx",43,0x91e47a4e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(43)
	if (((this->m_wrap == v))){
		HX_STACK_LINE(43)
		return v;
	}
	HX_STACK_LINE(43)
	this->m_wrap = v;
	HX_STACK_LINE(43)
	{
		HX_STACK_LINE(43)
		::haxor::context::TextureContext _this = ::haxor::context::EngineContext_obj::texture;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(43)
		::haxor::graphics::TextureType _g = this->get_type();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(43)
		int target;		HX_STACK_VAR(target,"target");
		HX_STACK_LINE(43)
		if (((_g == ::haxor::graphics::TextureType_obj::Texture2D))){
			HX_STACK_LINE(43)
			target = (int)3553;
		}
		else{
			HX_STACK_LINE(43)
			::haxor::graphics::TextureType _g1 = this->get_type();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(43)
			if (((_g1 == ::haxor::graphics::TextureType_obj::RenderTexture))){
				HX_STACK_LINE(43)
				target = (int)3553;
			}
			else{
				HX_STACK_LINE(43)
				::haxor::graphics::TextureType _g2 = this->get_type();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(43)
				if (((_g2 == ::haxor::graphics::TextureType_obj::TextureCube))){
					HX_STACK_LINE(43)
					target = (int)34067;
				}
				else{
					HX_STACK_LINE(43)
					target = (int)3553;
				}
			}
		}
		HX_STACK_LINE(43)
		if (((hx::ObjectPtr<OBJ_>(this) == _this->bind))){
			HX_STACK_LINE(43)
			Dynamic();
		}
		else{
			HX_STACK_LINE(43)
			_this->bind = hx::ObjectPtr<OBJ_>(this);
			HX_STACK_LINE(43)
			int id = _this->ids->__get(_this->bind->_cid_);		HX_STACK_VAR(id,"id");
			HX_STACK_LINE(43)
			int target1;		HX_STACK_VAR(target1,"target1");
			HX_STACK_LINE(43)
			{
				HX_STACK_LINE(43)
				::haxor::graphics::texture::Texture p_texture = _this->bind;		HX_STACK_VAR(p_texture,"p_texture");
				HX_STACK_LINE(43)
				::haxor::graphics::TextureType _g3 = p_texture->get_type();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(43)
				if (((_g3 == ::haxor::graphics::TextureType_obj::Texture2D))){
					HX_STACK_LINE(43)
					target1 = (int)3553;
				}
				else{
					HX_STACK_LINE(43)
					::haxor::graphics::TextureType _g4 = p_texture->get_type();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(43)
					if (((_g4 == ::haxor::graphics::TextureType_obj::RenderTexture))){
						HX_STACK_LINE(43)
						target1 = (int)3553;
					}
					else{
						HX_STACK_LINE(43)
						::haxor::graphics::TextureType _g5 = p_texture->get_type();		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(43)
						if (((_g5 == ::haxor::graphics::TextureType_obj::TextureCube))){
							HX_STACK_LINE(43)
							target1 = (int)34067;
						}
						else{
							HX_STACK_LINE(43)
							target1 = (int)3553;
						}
					}
				}
			}
			HX_STACK_LINE(43)
			::haxor::graphics::GL_obj::m_gl->BindTexture(target1,id);
		}
		HX_STACK_LINE(43)
		::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10242,(  (((((int(this->m_wrap) & int(::haxor::graphics::TextureWrap_obj::ClampX))) != (int)0))) ? int((int)33071) : int((int)10497) ));
		HX_STACK_LINE(43)
		::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10243,(  (((((int(this->m_wrap) & int(::haxor::graphics::TextureWrap_obj::ClampY))) != (int)0))) ? int((int)33071) : int((int)10497) ));
		HX_STACK_LINE(43)
		if ((::haxor::graphics::GL_obj::TEXTURE_ANISOTROPY_ENABLED)){
			HX_STACK_LINE(43)
			Float p_value = ::Math_obj::max((int)1,this->m_aniso);		HX_STACK_VAR(p_value,"p_value");
			HX_STACK_LINE(43)
			::haxor::graphics::GL_obj::m_gl->TexParameterf(target,::haxor::graphics::GL_obj::TEXTURE_ANISOTROPY,p_value);
		}
		HX_STACK_LINE(43)
		::haxor::graphics::TextureFilter minf = this->m_minFilter;		HX_STACK_VAR(minf,"minf");
		HX_STACK_LINE(43)
		::haxor::graphics::TextureFilter magf = this->m_magFilter;		HX_STACK_VAR(magf,"magf");
		HX_STACK_LINE(43)
		if (((this->m_format == ::haxor::graphics::PixelFormat_obj::Half))){
			HX_STACK_LINE(43)
			if ((!(::haxor::graphics::GL_obj::TEXTURE_HALF_LINEAR))){
				HX_STACK_LINE(43)
				minf = ::haxor::graphics::TextureFilter_obj::Nearest;
				HX_STACK_LINE(43)
				magf = ::haxor::graphics::TextureFilter_obj::Nearest;
			}
		}
		HX_STACK_LINE(43)
		switch( (int)(minf->__Index())){
			case (int)0: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9728);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9986);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9984);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9729);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9987);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9987);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9985);
			}
			;break;
		}
		HX_STACK_LINE(43)
		switch( (int)(magf->__Index())){
			case (int)0: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(43)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
		}
	}
	HX_STACK_LINE(43)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Texture_obj,set_wrap,return )

int Texture_obj::get_aniso( ){
	HX_STACK_FRAME("haxor.graphics.texture.Texture","get_aniso",0xa424d452,"haxor.graphics.texture.Texture.get_aniso","haxor/graphics/texture/Texture.hx",50,0x91e47a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(50)
	return this->m_aniso;
}


HX_DEFINE_DYNAMIC_FUNC0(Texture_obj,get_aniso,return )

int Texture_obj::set_aniso( int v){
	HX_STACK_FRAME("haxor.graphics.texture.Texture","set_aniso",0x8775c05e,"haxor.graphics.texture.Texture.set_aniso","haxor/graphics/texture/Texture.hx",51,0x91e47a4e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(51)
	if (((this->m_aniso == v))){
		HX_STACK_LINE(51)
		return v;
	}
	HX_STACK_LINE(51)
	this->m_aniso = v;
	HX_STACK_LINE(51)
	{
		HX_STACK_LINE(51)
		::haxor::context::TextureContext _this = ::haxor::context::EngineContext_obj::texture;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(51)
		::haxor::graphics::TextureType _g = this->get_type();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(51)
		int target;		HX_STACK_VAR(target,"target");
		HX_STACK_LINE(51)
		if (((_g == ::haxor::graphics::TextureType_obj::Texture2D))){
			HX_STACK_LINE(51)
			target = (int)3553;
		}
		else{
			HX_STACK_LINE(51)
			::haxor::graphics::TextureType _g1 = this->get_type();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(51)
			if (((_g1 == ::haxor::graphics::TextureType_obj::RenderTexture))){
				HX_STACK_LINE(51)
				target = (int)3553;
			}
			else{
				HX_STACK_LINE(51)
				::haxor::graphics::TextureType _g2 = this->get_type();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(51)
				if (((_g2 == ::haxor::graphics::TextureType_obj::TextureCube))){
					HX_STACK_LINE(51)
					target = (int)34067;
				}
				else{
					HX_STACK_LINE(51)
					target = (int)3553;
				}
			}
		}
		HX_STACK_LINE(51)
		if (((hx::ObjectPtr<OBJ_>(this) == _this->bind))){
			HX_STACK_LINE(51)
			Dynamic();
		}
		else{
			HX_STACK_LINE(51)
			_this->bind = hx::ObjectPtr<OBJ_>(this);
			HX_STACK_LINE(51)
			int id = _this->ids->__get(_this->bind->_cid_);		HX_STACK_VAR(id,"id");
			HX_STACK_LINE(51)
			int target1;		HX_STACK_VAR(target1,"target1");
			HX_STACK_LINE(51)
			{
				HX_STACK_LINE(51)
				::haxor::graphics::texture::Texture p_texture = _this->bind;		HX_STACK_VAR(p_texture,"p_texture");
				HX_STACK_LINE(51)
				::haxor::graphics::TextureType _g3 = p_texture->get_type();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(51)
				if (((_g3 == ::haxor::graphics::TextureType_obj::Texture2D))){
					HX_STACK_LINE(51)
					target1 = (int)3553;
				}
				else{
					HX_STACK_LINE(51)
					::haxor::graphics::TextureType _g4 = p_texture->get_type();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(51)
					if (((_g4 == ::haxor::graphics::TextureType_obj::RenderTexture))){
						HX_STACK_LINE(51)
						target1 = (int)3553;
					}
					else{
						HX_STACK_LINE(51)
						::haxor::graphics::TextureType _g5 = p_texture->get_type();		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(51)
						if (((_g5 == ::haxor::graphics::TextureType_obj::TextureCube))){
							HX_STACK_LINE(51)
							target1 = (int)34067;
						}
						else{
							HX_STACK_LINE(51)
							target1 = (int)3553;
						}
					}
				}
			}
			HX_STACK_LINE(51)
			::haxor::graphics::GL_obj::m_gl->BindTexture(target1,id);
		}
		HX_STACK_LINE(51)
		::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10242,(  (((((int(this->m_wrap) & int(::haxor::graphics::TextureWrap_obj::ClampX))) != (int)0))) ? int((int)33071) : int((int)10497) ));
		HX_STACK_LINE(51)
		::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10243,(  (((((int(this->m_wrap) & int(::haxor::graphics::TextureWrap_obj::ClampY))) != (int)0))) ? int((int)33071) : int((int)10497) ));
		HX_STACK_LINE(51)
		if ((::haxor::graphics::GL_obj::TEXTURE_ANISOTROPY_ENABLED)){
			HX_STACK_LINE(51)
			Float p_value = ::Math_obj::max((int)1,this->m_aniso);		HX_STACK_VAR(p_value,"p_value");
			HX_STACK_LINE(51)
			::haxor::graphics::GL_obj::m_gl->TexParameterf(target,::haxor::graphics::GL_obj::TEXTURE_ANISOTROPY,p_value);
		}
		HX_STACK_LINE(51)
		::haxor::graphics::TextureFilter minf = this->m_minFilter;		HX_STACK_VAR(minf,"minf");
		HX_STACK_LINE(51)
		::haxor::graphics::TextureFilter magf = this->m_magFilter;		HX_STACK_VAR(magf,"magf");
		HX_STACK_LINE(51)
		if (((this->m_format == ::haxor::graphics::PixelFormat_obj::Half))){
			HX_STACK_LINE(51)
			if ((!(::haxor::graphics::GL_obj::TEXTURE_HALF_LINEAR))){
				HX_STACK_LINE(51)
				minf = ::haxor::graphics::TextureFilter_obj::Nearest;
				HX_STACK_LINE(51)
				magf = ::haxor::graphics::TextureFilter_obj::Nearest;
			}
		}
		HX_STACK_LINE(51)
		switch( (int)(minf->__Index())){
			case (int)0: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9728);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9986);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9984);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9729);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9987);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9987);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9985);
			}
			;break;
		}
		HX_STACK_LINE(51)
		switch( (int)(magf->__Index())){
			case (int)0: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(51)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
		}
	}
	HX_STACK_LINE(51)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Texture_obj,set_aniso,return )

::haxor::graphics::TextureFilter Texture_obj::get_minFilter( ){
	HX_STACK_FRAME("haxor.graphics.texture.Texture","get_minFilter",0x1a7f19c4,"haxor.graphics.texture.Texture.get_minFilter","haxor/graphics/texture/Texture.hx",59,0x91e47a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(59)
	return this->m_minFilter;
}


HX_DEFINE_DYNAMIC_FUNC0(Texture_obj,get_minFilter,return )

::haxor::graphics::TextureFilter Texture_obj::set_minFilter( ::haxor::graphics::TextureFilter v){
	HX_STACK_FRAME("haxor.graphics.texture.Texture","set_minFilter",0x5f84fbd0,"haxor.graphics.texture.Texture.set_minFilter","haxor/graphics/texture/Texture.hx",60,0x91e47a4e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(60)
	if (((this->m_minFilter == v))){
		HX_STACK_LINE(60)
		return v;
	}
	HX_STACK_LINE(60)
	this->m_minFilter = v;
	HX_STACK_LINE(60)
	{
		HX_STACK_LINE(60)
		::haxor::context::TextureContext _this = ::haxor::context::EngineContext_obj::texture;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(60)
		::haxor::graphics::TextureType _g = this->get_type();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(60)
		int target;		HX_STACK_VAR(target,"target");
		HX_STACK_LINE(60)
		if (((_g == ::haxor::graphics::TextureType_obj::Texture2D))){
			HX_STACK_LINE(60)
			target = (int)3553;
		}
		else{
			HX_STACK_LINE(60)
			::haxor::graphics::TextureType _g1 = this->get_type();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(60)
			if (((_g1 == ::haxor::graphics::TextureType_obj::RenderTexture))){
				HX_STACK_LINE(60)
				target = (int)3553;
			}
			else{
				HX_STACK_LINE(60)
				::haxor::graphics::TextureType _g2 = this->get_type();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(60)
				if (((_g2 == ::haxor::graphics::TextureType_obj::TextureCube))){
					HX_STACK_LINE(60)
					target = (int)34067;
				}
				else{
					HX_STACK_LINE(60)
					target = (int)3553;
				}
			}
		}
		HX_STACK_LINE(60)
		if (((hx::ObjectPtr<OBJ_>(this) == _this->bind))){
			HX_STACK_LINE(60)
			Dynamic();
		}
		else{
			HX_STACK_LINE(60)
			_this->bind = hx::ObjectPtr<OBJ_>(this);
			HX_STACK_LINE(60)
			int id = _this->ids->__get(_this->bind->_cid_);		HX_STACK_VAR(id,"id");
			HX_STACK_LINE(60)
			int target1;		HX_STACK_VAR(target1,"target1");
			HX_STACK_LINE(60)
			{
				HX_STACK_LINE(60)
				::haxor::graphics::texture::Texture p_texture = _this->bind;		HX_STACK_VAR(p_texture,"p_texture");
				HX_STACK_LINE(60)
				::haxor::graphics::TextureType _g3 = p_texture->get_type();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(60)
				if (((_g3 == ::haxor::graphics::TextureType_obj::Texture2D))){
					HX_STACK_LINE(60)
					target1 = (int)3553;
				}
				else{
					HX_STACK_LINE(60)
					::haxor::graphics::TextureType _g4 = p_texture->get_type();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(60)
					if (((_g4 == ::haxor::graphics::TextureType_obj::RenderTexture))){
						HX_STACK_LINE(60)
						target1 = (int)3553;
					}
					else{
						HX_STACK_LINE(60)
						::haxor::graphics::TextureType _g5 = p_texture->get_type();		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(60)
						if (((_g5 == ::haxor::graphics::TextureType_obj::TextureCube))){
							HX_STACK_LINE(60)
							target1 = (int)34067;
						}
						else{
							HX_STACK_LINE(60)
							target1 = (int)3553;
						}
					}
				}
			}
			HX_STACK_LINE(60)
			::haxor::graphics::GL_obj::m_gl->BindTexture(target1,id);
		}
		HX_STACK_LINE(60)
		::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10242,(  (((((int(this->m_wrap) & int(::haxor::graphics::TextureWrap_obj::ClampX))) != (int)0))) ? int((int)33071) : int((int)10497) ));
		HX_STACK_LINE(60)
		::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10243,(  (((((int(this->m_wrap) & int(::haxor::graphics::TextureWrap_obj::ClampY))) != (int)0))) ? int((int)33071) : int((int)10497) ));
		HX_STACK_LINE(60)
		if ((::haxor::graphics::GL_obj::TEXTURE_ANISOTROPY_ENABLED)){
			HX_STACK_LINE(60)
			Float p_value = ::Math_obj::max((int)1,this->m_aniso);		HX_STACK_VAR(p_value,"p_value");
			HX_STACK_LINE(60)
			::haxor::graphics::GL_obj::m_gl->TexParameterf(target,::haxor::graphics::GL_obj::TEXTURE_ANISOTROPY,p_value);
		}
		HX_STACK_LINE(60)
		::haxor::graphics::TextureFilter minf = this->m_minFilter;		HX_STACK_VAR(minf,"minf");
		HX_STACK_LINE(60)
		::haxor::graphics::TextureFilter magf = this->m_magFilter;		HX_STACK_VAR(magf,"magf");
		HX_STACK_LINE(60)
		if (((this->m_format == ::haxor::graphics::PixelFormat_obj::Half))){
			HX_STACK_LINE(60)
			if ((!(::haxor::graphics::GL_obj::TEXTURE_HALF_LINEAR))){
				HX_STACK_LINE(60)
				minf = ::haxor::graphics::TextureFilter_obj::Nearest;
				HX_STACK_LINE(60)
				magf = ::haxor::graphics::TextureFilter_obj::Nearest;
			}
		}
		HX_STACK_LINE(60)
		switch( (int)(minf->__Index())){
			case (int)0: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9728);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9986);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9984);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9729);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9987);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9987);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9985);
			}
			;break;
		}
		HX_STACK_LINE(60)
		switch( (int)(magf->__Index())){
			case (int)0: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(60)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
		}
	}
	HX_STACK_LINE(60)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Texture_obj,set_minFilter,return )

::haxor::graphics::TextureFilter Texture_obj::get_magFilter( ){
	HX_STACK_FRAME("haxor.graphics.texture.Texture","get_magFilter",0x2dd54985,"haxor.graphics.texture.Texture.get_magFilter","haxor/graphics/texture/Texture.hx",67,0x91e47a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(67)
	return this->m_magFilter;
}


HX_DEFINE_DYNAMIC_FUNC0(Texture_obj,get_magFilter,return )

::haxor::graphics::TextureFilter Texture_obj::set_magFilter( ::haxor::graphics::TextureFilter v){
	HX_STACK_FRAME("haxor.graphics.texture.Texture","set_magFilter",0x72db2b91,"haxor.graphics.texture.Texture.set_magFilter","haxor/graphics/texture/Texture.hx",68,0x91e47a4e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(68)
	if (((this->m_magFilter == v))){
		HX_STACK_LINE(68)
		return v;
	}
	HX_STACK_LINE(68)
	this->m_magFilter = v;
	HX_STACK_LINE(68)
	{
		HX_STACK_LINE(68)
		::haxor::context::TextureContext _this = ::haxor::context::EngineContext_obj::texture;		HX_STACK_VAR(_this,"_this");
		HX_STACK_LINE(68)
		::haxor::graphics::TextureType _g = this->get_type();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(68)
		int target;		HX_STACK_VAR(target,"target");
		HX_STACK_LINE(68)
		if (((_g == ::haxor::graphics::TextureType_obj::Texture2D))){
			HX_STACK_LINE(68)
			target = (int)3553;
		}
		else{
			HX_STACK_LINE(68)
			::haxor::graphics::TextureType _g1 = this->get_type();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(68)
			if (((_g1 == ::haxor::graphics::TextureType_obj::RenderTexture))){
				HX_STACK_LINE(68)
				target = (int)3553;
			}
			else{
				HX_STACK_LINE(68)
				::haxor::graphics::TextureType _g2 = this->get_type();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(68)
				if (((_g2 == ::haxor::graphics::TextureType_obj::TextureCube))){
					HX_STACK_LINE(68)
					target = (int)34067;
				}
				else{
					HX_STACK_LINE(68)
					target = (int)3553;
				}
			}
		}
		HX_STACK_LINE(68)
		if (((hx::ObjectPtr<OBJ_>(this) == _this->bind))){
			HX_STACK_LINE(68)
			Dynamic();
		}
		else{
			HX_STACK_LINE(68)
			_this->bind = hx::ObjectPtr<OBJ_>(this);
			HX_STACK_LINE(68)
			int id = _this->ids->__get(_this->bind->_cid_);		HX_STACK_VAR(id,"id");
			HX_STACK_LINE(68)
			int target1;		HX_STACK_VAR(target1,"target1");
			HX_STACK_LINE(68)
			{
				HX_STACK_LINE(68)
				::haxor::graphics::texture::Texture p_texture = _this->bind;		HX_STACK_VAR(p_texture,"p_texture");
				HX_STACK_LINE(68)
				::haxor::graphics::TextureType _g3 = p_texture->get_type();		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(68)
				if (((_g3 == ::haxor::graphics::TextureType_obj::Texture2D))){
					HX_STACK_LINE(68)
					target1 = (int)3553;
				}
				else{
					HX_STACK_LINE(68)
					::haxor::graphics::TextureType _g4 = p_texture->get_type();		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(68)
					if (((_g4 == ::haxor::graphics::TextureType_obj::RenderTexture))){
						HX_STACK_LINE(68)
						target1 = (int)3553;
					}
					else{
						HX_STACK_LINE(68)
						::haxor::graphics::TextureType _g5 = p_texture->get_type();		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(68)
						if (((_g5 == ::haxor::graphics::TextureType_obj::TextureCube))){
							HX_STACK_LINE(68)
							target1 = (int)34067;
						}
						else{
							HX_STACK_LINE(68)
							target1 = (int)3553;
						}
					}
				}
			}
			HX_STACK_LINE(68)
			::haxor::graphics::GL_obj::m_gl->BindTexture(target1,id);
		}
		HX_STACK_LINE(68)
		::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10242,(  (((((int(this->m_wrap) & int(::haxor::graphics::TextureWrap_obj::ClampX))) != (int)0))) ? int((int)33071) : int((int)10497) ));
		HX_STACK_LINE(68)
		::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10243,(  (((((int(this->m_wrap) & int(::haxor::graphics::TextureWrap_obj::ClampY))) != (int)0))) ? int((int)33071) : int((int)10497) ));
		HX_STACK_LINE(68)
		if ((::haxor::graphics::GL_obj::TEXTURE_ANISOTROPY_ENABLED)){
			HX_STACK_LINE(68)
			Float p_value = ::Math_obj::max((int)1,this->m_aniso);		HX_STACK_VAR(p_value,"p_value");
			HX_STACK_LINE(68)
			::haxor::graphics::GL_obj::m_gl->TexParameterf(target,::haxor::graphics::GL_obj::TEXTURE_ANISOTROPY,p_value);
		}
		HX_STACK_LINE(68)
		::haxor::graphics::TextureFilter minf = this->m_minFilter;		HX_STACK_VAR(minf,"minf");
		HX_STACK_LINE(68)
		::haxor::graphics::TextureFilter magf = this->m_magFilter;		HX_STACK_VAR(magf,"magf");
		HX_STACK_LINE(68)
		if (((this->m_format == ::haxor::graphics::PixelFormat_obj::Half))){
			HX_STACK_LINE(68)
			if ((!(::haxor::graphics::GL_obj::TEXTURE_HALF_LINEAR))){
				HX_STACK_LINE(68)
				minf = ::haxor::graphics::TextureFilter_obj::Nearest;
				HX_STACK_LINE(68)
				magf = ::haxor::graphics::TextureFilter_obj::Nearest;
			}
		}
		HX_STACK_LINE(68)
		switch( (int)(minf->__Index())){
			case (int)0: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9728);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9986);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9984);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9729);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9987);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9987);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10241,(int)9985);
			}
			;break;
		}
		HX_STACK_LINE(68)
		switch( (int)(magf->__Index())){
			case (int)0: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9728);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(68)
				::haxor::graphics::GL_obj::m_gl->TexParameteri(target,(int)10240,(int)9729);
			}
			;break;
		}
	}
	HX_STACK_LINE(68)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(Texture_obj,set_magFilter,return )

bool Texture_obj::get_mipmaps( ){
	HX_STACK_FRAME("haxor.graphics.texture.Texture","get_mipmaps",0x8d455a45,"haxor.graphics.texture.Texture.get_mipmaps","haxor/graphics/texture/Texture.hx",75,0x91e47a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(75)
	return this->m_mipmaps;
}


HX_DEFINE_DYNAMIC_FUNC0(Texture_obj,get_mipmaps,return )

::haxor::graphics::TextureType Texture_obj::get_type( ){
	HX_STACK_FRAME("haxor.graphics.texture.Texture","get_type",0x793ce620,"haxor.graphics.texture.Texture.get_type","haxor/graphics/texture/Texture.hx",82,0x91e47a4e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(82)
	return ::haxor::graphics::TextureType_obj::None;
}


HX_DEFINE_DYNAMIC_FUNC0(Texture_obj,get_type,return )

Void Texture_obj::Apply( ){
{
		HX_STACK_FRAME("haxor.graphics.texture.Texture","Apply",0x6766e151,"haxor.graphics.texture.Texture.Apply","haxor/graphics/texture/Texture.hx",110,0x91e47a4e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(110)
		::haxor::context::EngineContext_obj::texture->Update(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Texture_obj,Apply,(void))

Void Texture_obj::GenerateMipmaps( ){
{
		HX_STACK_FRAME("haxor.graphics.texture.Texture","GenerateMipmaps",0xad5228d9,"haxor.graphics.texture.Texture.GenerateMipmaps","haxor/graphics/texture/Texture.hx",116,0x91e47a4e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(116)
		if ((this->m_mipmaps)){
			HX_STACK_LINE(116)
			return null();
		}
		HX_STACK_LINE(116)
		this->m_mipmaps = true;
		HX_STACK_LINE(116)
		::haxor::context::EngineContext_obj::texture->UpdateMipmaps(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Texture_obj,GenerateMipmaps,(void))

Void Texture_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.graphics.texture.Texture","OnDestroy",0xdb9b6efe,"haxor.graphics.texture.Texture.OnDestroy","haxor/graphics/texture/Texture.hx",122,0x91e47a4e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(123)
		this->super::OnDestroy();
		HX_STACK_LINE(124)
		::haxor::context::EngineContext_obj::texture->Destroy(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}



Texture_obj::Texture_obj()
{
}

void Texture_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Texture);
	HX_MARK_MEMBER_NAME(m_width,"m_width");
	HX_MARK_MEMBER_NAME(m_height,"m_height");
	HX_MARK_MEMBER_NAME(m_format,"m_format");
	HX_MARK_MEMBER_NAME(m_wrap,"m_wrap");
	HX_MARK_MEMBER_NAME(m_aniso,"m_aniso");
	HX_MARK_MEMBER_NAME(m_minFilter,"m_minFilter");
	HX_MARK_MEMBER_NAME(m_magFilter,"m_magFilter");
	HX_MARK_MEMBER_NAME(mipmaps,"mipmaps");
	HX_MARK_MEMBER_NAME(m_mipmaps,"m_mipmaps");
	HX_MARK_MEMBER_NAME(type,"type");
	HX_MARK_MEMBER_NAME(__slot,"__slot");
	::haxor::core::Resource_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Texture_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_width,"m_width");
	HX_VISIT_MEMBER_NAME(m_height,"m_height");
	HX_VISIT_MEMBER_NAME(m_format,"m_format");
	HX_VISIT_MEMBER_NAME(m_wrap,"m_wrap");
	HX_VISIT_MEMBER_NAME(m_aniso,"m_aniso");
	HX_VISIT_MEMBER_NAME(m_minFilter,"m_minFilter");
	HX_VISIT_MEMBER_NAME(m_magFilter,"m_magFilter");
	HX_VISIT_MEMBER_NAME(mipmaps,"mipmaps");
	HX_VISIT_MEMBER_NAME(m_mipmaps,"m_mipmaps");
	HX_VISIT_MEMBER_NAME(type,"type");
	HX_VISIT_MEMBER_NAME(__slot,"__slot");
	::haxor::core::Resource_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Texture_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"wrap") ) { return get_wrap(); }
		if (HX_FIELD_EQ(inName,"type") ) { return inCallProp ? get_type() : type; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return get_width(); }
		if (HX_FIELD_EQ(inName,"aniso") ) { return get_aniso(); }
		if (HX_FIELD_EQ(inName,"Apply") ) { return Apply_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return get_height(); }
		if (HX_FIELD_EQ(inName,"format") ) { return get_format(); }
		if (HX_FIELD_EQ(inName,"m_wrap") ) { return m_wrap; }
		if (HX_FIELD_EQ(inName,"__slot") ) { return __slot; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_width") ) { return m_width; }
		if (HX_FIELD_EQ(inName,"m_aniso") ) { return m_aniso; }
		if (HX_FIELD_EQ(inName,"mipmaps") ) { return inCallProp ? get_mipmaps() : mipmaps; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_height") ) { return m_height; }
		if (HX_FIELD_EQ(inName,"m_format") ) { return m_format; }
		if (HX_FIELD_EQ(inName,"get_wrap") ) { return get_wrap_dyn(); }
		if (HX_FIELD_EQ(inName,"set_wrap") ) { return set_wrap_dyn(); }
		if (HX_FIELD_EQ(inName,"get_type") ) { return get_type_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_width") ) { return get_width_dyn(); }
		if (HX_FIELD_EQ(inName,"get_aniso") ) { return get_aniso_dyn(); }
		if (HX_FIELD_EQ(inName,"set_aniso") ) { return set_aniso_dyn(); }
		if (HX_FIELD_EQ(inName,"minFilter") ) { return get_minFilter(); }
		if (HX_FIELD_EQ(inName,"magFilter") ) { return get_magFilter(); }
		if (HX_FIELD_EQ(inName,"m_mipmaps") ) { return m_mipmaps; }
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_height") ) { return get_height_dyn(); }
		if (HX_FIELD_EQ(inName,"get_format") ) { return get_format_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_minFilter") ) { return m_minFilter; }
		if (HX_FIELD_EQ(inName,"m_magFilter") ) { return m_magFilter; }
		if (HX_FIELD_EQ(inName,"get_mipmaps") ) { return get_mipmaps_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_minFilter") ) { return get_minFilter_dyn(); }
		if (HX_FIELD_EQ(inName,"set_minFilter") ) { return set_minFilter_dyn(); }
		if (HX_FIELD_EQ(inName,"get_magFilter") ) { return get_magFilter_dyn(); }
		if (HX_FIELD_EQ(inName,"set_magFilter") ) { return set_magFilter_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"GenerateMipmaps") ) { return GenerateMipmaps_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Texture_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"wrap") ) { return set_wrap(inValue); }
		if (HX_FIELD_EQ(inName,"type") ) { type=inValue.Cast< ::haxor::graphics::TextureType >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"aniso") ) { return set_aniso(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_wrap") ) { m_wrap=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"__slot") ) { __slot=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_width") ) { m_width=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_aniso") ) { m_aniso=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mipmaps") ) { mipmaps=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_height") ) { m_height=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_format") ) { m_format=inValue.Cast< ::haxor::graphics::PixelFormat >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"minFilter") ) { return set_minFilter(inValue); }
		if (HX_FIELD_EQ(inName,"magFilter") ) { return set_magFilter(inValue); }
		if (HX_FIELD_EQ(inName,"m_mipmaps") ) { m_mipmaps=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_minFilter") ) { m_minFilter=inValue.Cast< ::haxor::graphics::TextureFilter >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_magFilter") ) { m_magFilter=inValue.Cast< ::haxor::graphics::TextureFilter >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Texture_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("m_width"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("m_height"));
	outFields->push(HX_CSTRING("format"));
	outFields->push(HX_CSTRING("m_format"));
	outFields->push(HX_CSTRING("wrap"));
	outFields->push(HX_CSTRING("m_wrap"));
	outFields->push(HX_CSTRING("aniso"));
	outFields->push(HX_CSTRING("m_aniso"));
	outFields->push(HX_CSTRING("minFilter"));
	outFields->push(HX_CSTRING("m_minFilter"));
	outFields->push(HX_CSTRING("magFilter"));
	outFields->push(HX_CSTRING("m_magFilter"));
	outFields->push(HX_CSTRING("mipmaps"));
	outFields->push(HX_CSTRING("m_mipmaps"));
	outFields->push(HX_CSTRING("type"));
	outFields->push(HX_CSTRING("__slot"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Texture_obj,m_width),HX_CSTRING("m_width")},
	{hx::fsInt,(int)offsetof(Texture_obj,m_height),HX_CSTRING("m_height")},
	{hx::fsObject /*::haxor::graphics::PixelFormat*/ ,(int)offsetof(Texture_obj,m_format),HX_CSTRING("m_format")},
	{hx::fsInt,(int)offsetof(Texture_obj,m_wrap),HX_CSTRING("m_wrap")},
	{hx::fsInt,(int)offsetof(Texture_obj,m_aniso),HX_CSTRING("m_aniso")},
	{hx::fsObject /*::haxor::graphics::TextureFilter*/ ,(int)offsetof(Texture_obj,m_minFilter),HX_CSTRING("m_minFilter")},
	{hx::fsObject /*::haxor::graphics::TextureFilter*/ ,(int)offsetof(Texture_obj,m_magFilter),HX_CSTRING("m_magFilter")},
	{hx::fsBool,(int)offsetof(Texture_obj,mipmaps),HX_CSTRING("mipmaps")},
	{hx::fsBool,(int)offsetof(Texture_obj,m_mipmaps),HX_CSTRING("m_mipmaps")},
	{hx::fsObject /*::haxor::graphics::TextureType*/ ,(int)offsetof(Texture_obj,type),HX_CSTRING("type")},
	{hx::fsInt,(int)offsetof(Texture_obj,__slot),HX_CSTRING("__slot")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_width"),
	HX_CSTRING("m_width"),
	HX_CSTRING("get_height"),
	HX_CSTRING("m_height"),
	HX_CSTRING("get_format"),
	HX_CSTRING("m_format"),
	HX_CSTRING("get_wrap"),
	HX_CSTRING("set_wrap"),
	HX_CSTRING("m_wrap"),
	HX_CSTRING("get_aniso"),
	HX_CSTRING("set_aniso"),
	HX_CSTRING("m_aniso"),
	HX_CSTRING("get_minFilter"),
	HX_CSTRING("set_minFilter"),
	HX_CSTRING("m_minFilter"),
	HX_CSTRING("get_magFilter"),
	HX_CSTRING("set_magFilter"),
	HX_CSTRING("m_magFilter"),
	HX_CSTRING("mipmaps"),
	HX_CSTRING("get_mipmaps"),
	HX_CSTRING("m_mipmaps"),
	HX_CSTRING("type"),
	HX_CSTRING("get_type"),
	HX_CSTRING("__slot"),
	HX_CSTRING("Apply"),
	HX_CSTRING("GenerateMipmaps"),
	HX_CSTRING("OnDestroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Texture_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Texture_obj::__mClass,"__mClass");
};

#endif

Class Texture_obj::__mClass;

void Texture_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.graphics.texture.Texture"), hx::TCanCast< Texture_obj> ,sStaticFields,sMemberFields,
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

void Texture_obj::__boot()
{
}

} // end namespace haxor
} // end namespace graphics
} // end namespace texture
