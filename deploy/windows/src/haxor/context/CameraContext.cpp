#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Camera
#include <haxor/component/Camera.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_context_CameraContext
#include <haxor/context/CameraContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_RendererContext
#include <haxor/context/RendererContext.h>
#endif
#ifndef INCLUDED_haxor_context_TextureContext
#include <haxor/context/TextureContext.h>
#endif
#ifndef INCLUDED_haxor_context_UID
#include <haxor/context/UID.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_PixelFormat
#include <haxor/core/PixelFormat.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_Graphics
#include <haxor/graphics/Graphics.h>
#endif
#ifndef INCLUDED_haxor_graphics_Screen
#include <haxor/graphics/Screen.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_RenderTexture
#include <haxor/graphics/texture/RenderTexture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_math_AABB2
#include <haxor/math/AABB2.h>
#endif
namespace haxor{
namespace context{

Void CameraContext_obj::__construct()
{
HX_STACK_FRAME("haxor.context.CameraContext","new",0xddbd8c31,"haxor.context.CameraContext.new","haxor/context/CameraContext.hx",43,0x8aadd161)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(44)
	::haxor::context::UID _g = ::haxor::context::UID_obj::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(44)
	this->cid = _g;
	HX_STACK_LINE(45)
	this->list = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(46)
	this->front = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(47)
	this->back = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(49)
	{
		HX_STACK_LINE(49)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(49)
		while((true)){
			HX_STACK_LINE(49)
			if ((!(((_g1 < (int)64))))){
				HX_STACK_LINE(49)
				break;
			}
			HX_STACK_LINE(49)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(51)
			this->front->push(null());
			HX_STACK_LINE(52)
			this->back->push(null());
		}
	}
}
;
	return null();
}

//CameraContext_obj::~CameraContext_obj() { }

Dynamic CameraContext_obj::__CreateEmpty() { return  new CameraContext_obj; }
hx::ObjectPtr< CameraContext_obj > CameraContext_obj::__new()
{  hx::ObjectPtr< CameraContext_obj > result = new CameraContext_obj();
	result->__construct();
	return result;}

Dynamic CameraContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CameraContext_obj > result = new CameraContext_obj();
	result->__construct();
	return result;}

Void CameraContext_obj::Create( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","Create",0x7fe697eb,"haxor.context.CameraContext.Create","haxor/context/CameraContext.hx",61,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(62)
		this->list->push(c);
		HX_STACK_LINE(63)
		this->SortCameraList();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,Create,(void))

Void CameraContext_obj::Destroy( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","Destroy",0x7cf9cd2b,"haxor.context.CameraContext.Destroy","haxor/context/CameraContext.hx",71,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(72)
		this->ClearTargets(c);
		HX_STACK_LINE(73)
		this->list->remove(c);
		HX_STACK_LINE(74)
		this->SortCameraList();
		HX_STACK_LINE(75)
		{
			HX_STACK_LINE(75)
			int v = c->__cid;		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(75)
			this->cid->m_cache->push(v);
			HX_STACK_LINE(75)
			v;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,Destroy,(void))

Void CameraContext_obj::Bind( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","Bind",0x0b0abcec,"haxor.context.CameraContext.Bind","haxor/context/CameraContext.hx",83,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(84)
		::haxor::graphics::texture::RenderTexture ft = this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();		HX_STACK_VAR(ft,"ft");
		HX_STACK_LINE(85)
		::haxor::graphics::texture::RenderTexture rt = c->m_target;		HX_STACK_VAR(rt,"rt");
		HX_STACK_LINE(86)
		::haxor::graphics::texture::RenderTexture target;		HX_STACK_VAR(target,"target");
		HX_STACK_LINE(86)
		if (((ft == null()))){
			HX_STACK_LINE(86)
			target = rt;
		}
		else{
			HX_STACK_LINE(86)
			target = ft;
		}
		HX_STACK_LINE(88)
		c->UpdateProjection();
		HX_STACK_LINE(90)
		::haxor::context::EngineContext_obj::texture->BindTarget(target);
		HX_STACK_LINE(91)
		::haxor::context::EngineContext_obj::renderer->UpdateDisplayList(c);
		HX_STACK_LINE(93)
		::haxor::graphics::Graphics_obj::Clear(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,Bind,(void))

Void CameraContext_obj::Resize( ){
{
		HX_STACK_FRAME("haxor.context.CameraContext","Resize",0x0c528ae3,"haxor.context.CameraContext.Resize","haxor/context/CameraContext.hx",101,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_LINE(101)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(101)
		int _g = this->list->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(101)
		while((true)){
			HX_STACK_LINE(101)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(101)
				break;
			}
			HX_STACK_LINE(101)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(101)
			this->UpdateViewport(this->list->__get(i).StaticCast< ::haxor::component::Camera >());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CameraContext_obj,Resize,(void))

Void CameraContext_obj::ClearTargets( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","ClearTargets",0x3bcbb424,"haxor.context.CameraContext.ClearTargets","haxor/context/CameraContext.hx",109,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(110)
		::haxor::graphics::texture::RenderTexture rt;		HX_STACK_VAR(rt,"rt");
		HX_STACK_LINE(111)
		rt = this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
		HX_STACK_LINE(111)
		if (((rt != null()))){
			HX_STACK_LINE(111)
			::haxor::core::Resource_obj::Destroy(rt);
		}
		HX_STACK_LINE(112)
		rt = this->back->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
		HX_STACK_LINE(112)
		if (((rt != null()))){
			HX_STACK_LINE(112)
			::haxor::core::Resource_obj::Destroy(rt);
		}
		HX_STACK_LINE(113)
		this->front[c->__cid] = null();
		HX_STACK_LINE(114)
		this->back[c->__cid] = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,ClearTargets,(void))

Void CameraContext_obj::Unbind( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","Unbind",0x62c32d85,"haxor.context.CameraContext.Unbind","haxor/context/CameraContext.hx",124,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(124)
		this->SwapTargets(c);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,Unbind,(void))

Void CameraContext_obj::SwapTargets( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","SwapTargets",0xf131c660,"haxor.context.CameraContext.SwapTargets","haxor/context/CameraContext.hx",132,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(133)
		::haxor::graphics::texture::RenderTexture tmp;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(134)
		tmp = this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
		HX_STACK_LINE(135)
		this->front[c->__cid] = this->back->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
		HX_STACK_LINE(136)
		this->back[c->__cid] = tmp;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,SwapTargets,(void))

Void CameraContext_obj::UpdateViewport( ::haxor::component::Camera c){
{
		HX_STACK_FRAME("haxor.context.CameraContext","UpdateViewport",0x37b7777e,"haxor.context.CameraContext.UpdateViewport","haxor/context/CameraContext.hx",144,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_ARG(c,"c")
		HX_STACK_LINE(145)
		bool need_buffer = false;		HX_STACK_VAR(need_buffer,"need_buffer");
		HX_STACK_LINE(146)
		if (((c->m_quality < 1.0))){
			HX_STACK_LINE(146)
			need_buffer = true;
		}
		else{
			HX_STACK_LINE(148)
			if (((c->get_filters()->__Field(HX_CSTRING("length"),true) > (int)0))){
				HX_STACK_LINE(148)
				need_buffer = true;
			}
		}
		HX_STACK_LINE(150)
		Float w = ::haxor::graphics::Screen_obj::m_width;		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(151)
		Float h = ::haxor::graphics::Screen_obj::m_height;		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(153)
		if (((c->m_target != null()))){
			HX_STACK_LINE(155)
			w = c->m_target->m_width;
			HX_STACK_LINE(156)
			h = c->m_target->m_height;
		}
		HX_STACK_LINE(159)
		c->m_aspect = (Float(w) / Float(h));
		HX_STACK_LINE(161)
		Float sw = (w * c->m_quality);		HX_STACK_VAR(sw,"sw");
		HX_STACK_LINE(162)
		Float sh = (h * c->m_quality);		HX_STACK_VAR(sh,"sh");
		HX_STACK_LINE(163)
		if (((sw < 1.0))){
			HX_STACK_LINE(163)
			w = 1.0;
		}
		else{
			HX_STACK_LINE(163)
			w = sw;
		}
		HX_STACK_LINE(164)
		if (((sh < 1.0))){
			HX_STACK_LINE(164)
			h = 1.0;
		}
		else{
			HX_STACK_LINE(164)
			h = sh;
		}
		HX_STACK_LINE(166)
		Float _g = c->m_viewport->get_xMin();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(166)
		Float _g1 = (_g * w);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(166)
		Float vx = ::Std_obj::_int(_g1);		HX_STACK_VAR(vx,"vx");
		HX_STACK_LINE(167)
		Float _g2 = c->m_viewport->get_yMin();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(167)
		Float _g3 = (_g2 * h);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(167)
		Float vy = ::Std_obj::_int(_g3);		HX_STACK_VAR(vy,"vy");
		HX_STACK_LINE(168)
		Float _g6;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(168)
		{
			HX_STACK_LINE(168)
			::haxor::math::AABB2 _this = c->m_viewport;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(168)
			{
				HX_STACK_LINE(168)
				Float _g4 = _this->get_xMax();		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(168)
				Float _g5 = _this->get_xMin();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(168)
				Float p_a = (_g4 - _g5);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(168)
				if (((p_a < (int)0))){
					HX_STACK_LINE(168)
					_g6 = -(p_a);
				}
				else{
					HX_STACK_LINE(168)
					_g6 = p_a;
				}
			}
		}
		HX_STACK_LINE(168)
		Float aw = (_g6 * w);		HX_STACK_VAR(aw,"aw");
		HX_STACK_LINE(169)
		Float _g9;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(169)
		{
			HX_STACK_LINE(169)
			::haxor::math::AABB2 _this = c->m_viewport;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(169)
			{
				HX_STACK_LINE(169)
				Float _g7 = _this->get_yMax();		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(169)
				Float _g8 = _this->get_yMin();		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(169)
				Float p_a = (_g7 - _g8);		HX_STACK_VAR(p_a,"p_a");
				HX_STACK_LINE(169)
				if (((p_a < (int)0))){
					HX_STACK_LINE(169)
					_g9 = -(p_a);
				}
				else{
					HX_STACK_LINE(169)
					_g9 = p_a;
				}
			}
		}
		HX_STACK_LINE(169)
		Float ah = (_g9 * h);		HX_STACK_VAR(ah,"ah");
		HX_STACK_LINE(171)
		{
			HX_STACK_LINE(171)
			c->m_pixelViewport->set_xMin(vx);
			HX_STACK_LINE(171)
			vx;
		}
		HX_STACK_LINE(172)
		{
			HX_STACK_LINE(172)
			Float v = ((h - ah) - vy);		HX_STACK_VAR(v,"v");
			HX_STACK_LINE(172)
			c->m_pixelViewport->set_yMin(v);
			HX_STACK_LINE(172)
			v;
		}
		HX_STACK_LINE(173)
		{
			HX_STACK_LINE(173)
			::haxor::math::AABB2 _this = c->m_pixelViewport;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(173)
			Float _g10 = _this->get_xMin();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(173)
			Float _g11 = (_g10 + aw);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(173)
			_this->set_xMax(_g11);
			HX_STACK_LINE(173)
			aw;
		}
		HX_STACK_LINE(174)
		{
			HX_STACK_LINE(174)
			::haxor::math::AABB2 _this = c->m_pixelViewport;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(174)
			Float _g12 = _this->get_yMin();		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(174)
			Float _g13 = (_g12 + ah);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(174)
			_this->set_yMax(_g13);
			HX_STACK_LINE(174)
			ah;
		}
		HX_STACK_LINE(176)
		int tw = aw;		HX_STACK_VAR(tw,"tw");
		HX_STACK_LINE(177)
		int th = ah;		HX_STACK_VAR(th,"th");
		HX_STACK_LINE(179)
		::haxor::graphics::texture::RenderTexture grt;		HX_STACK_VAR(grt,"grt");
		HX_STACK_LINE(181)
		grt = this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
		HX_STACK_LINE(183)
		if (((grt != null()))){
			HX_STACK_LINE(185)
			if (((tw != grt->m_width))){
				HX_STACK_LINE(185)
				this->ClearTargets(c);
			}
			else{
				HX_STACK_LINE(187)
				if (((th != grt->m_height))){
					HX_STACK_LINE(187)
					this->ClearTargets(c);
				}
			}
		}
		HX_STACK_LINE(190)
		grt = this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
		HX_STACK_LINE(192)
		if (((grt == null()))){
			HX_STACK_LINE(194)
			if ((need_buffer)){
				HX_STACK_LINE(197)
				::haxor::core::PixelFormat tf;		HX_STACK_VAR(tf,"tf");
				HX_STACK_LINE(197)
				if (((c->m_target == null()))){
					HX_STACK_LINE(197)
					tf = ::haxor::core::PixelFormat_obj::RGB8;
				}
				else{
					HX_STACK_LINE(197)
					tf = c->m_target->m_format;
				}
				HX_STACK_LINE(198)
				this->front[c->__cid] = ::haxor::graphics::texture::RenderTexture_obj::__new(aw,ah,tf,c->m_captureDepth);
				HX_STACK_LINE(199)
				if (((c->get_filters()->__Field(HX_CSTRING("length"),true) <= (int)0))){
					HX_STACK_LINE(199)
					this->back[c->__cid] = this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >();
				}
				else{
					HX_STACK_LINE(199)
					this->back[c->__cid] = ::haxor::graphics::texture::RenderTexture_obj::__new(aw,ah,tf,c->m_captureDepth);
				}
				HX_STACK_LINE(201)
				::String _g14 = this->back->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >()->set_name(HX_CSTRING("CameraScreenBuffer"));		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(200)
				this->front->__get(c->__cid).StaticCast< ::haxor::graphics::texture::RenderTexture >()->set_name(_g14);
			}
		}
		HX_STACK_LINE(205)
		c->m_projection_dirty = true;
		HX_STACK_LINE(206)
		c->m_proj_uniform_dirty = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CameraContext_obj,UpdateViewport,(void))

Void CameraContext_obj::SortCameraList( ){
{
		HX_STACK_FRAME("haxor.context.CameraContext","SortCameraList",0x68c4ca90,"haxor.context.CameraContext.SortCameraList","haxor/context/CameraContext.hx",214,0x8aadd161)
		HX_STACK_THIS(this)
		HX_STACK_LINE(214)
		if (((this->list->length > (int)1))){

			HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_2_1)
			int run(::haxor::component::Camera a,::haxor::component::Camera b){
				HX_STACK_FRAME("*","_Function_2_1",0x5201af78,"*._Function_2_1","haxor/context/CameraContext.hx",215,0x8aadd161)
				HX_STACK_ARG(a,"a")
				HX_STACK_ARG(b,"b")
				{
					HX_STACK_LINE(215)
					if (((a->get_order() == b->get_order()))){
						HX_STACK_LINE(215)
						if (((a->m_entity->get_name() < b->m_entity->get_name()))){
							HX_STACK_LINE(215)
							return (int)-1;
						}
						else{
							HX_STACK_LINE(215)
							return (int)1;
						}
					}
					else{
						HX_STACK_LINE(215)
						if (((a->get_order() < b->get_order()))){
							HX_STACK_LINE(215)
							return (int)-1;
						}
						else{
							HX_STACK_LINE(215)
							return (int)1;
						}
					}
					HX_STACK_LINE(215)
					return (int)0;
				}
				return null();
			}
			HX_END_LOCAL_FUNC2(return)

			HX_STACK_LINE(215)
			this->list->sort( Dynamic(new _Function_2_1()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(CameraContext_obj,SortCameraList,(void))


CameraContext_obj::CameraContext_obj()
{
}

void CameraContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CameraContext);
	HX_MARK_MEMBER_NAME(cid,"cid");
	HX_MARK_MEMBER_NAME(list,"list");
	HX_MARK_MEMBER_NAME(front,"front");
	HX_MARK_MEMBER_NAME(back,"back");
	HX_MARK_END_CLASS();
}

void CameraContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(cid,"cid");
	HX_VISIT_MEMBER_NAME(list,"list");
	HX_VISIT_MEMBER_NAME(front,"front");
	HX_VISIT_MEMBER_NAME(back,"back");
}

Dynamic CameraContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"cid") ) { return cid; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { return list; }
		if (HX_FIELD_EQ(inName,"back") ) { return back; }
		if (HX_FIELD_EQ(inName,"Bind") ) { return Bind_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"front") ) { return front; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Create") ) { return Create_dyn(); }
		if (HX_FIELD_EQ(inName,"Resize") ) { return Resize_dyn(); }
		if (HX_FIELD_EQ(inName,"Unbind") ) { return Unbind_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Destroy") ) { return Destroy_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"SwapTargets") ) { return SwapTargets_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"ClearTargets") ) { return ClearTargets_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"UpdateViewport") ) { return UpdateViewport_dyn(); }
		if (HX_FIELD_EQ(inName,"SortCameraList") ) { return SortCameraList_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CameraContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"cid") ) { cid=inValue.Cast< ::haxor::context::UID >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"list") ) { list=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"back") ) { back=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"front") ) { front=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CameraContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("cid"));
	outFields->push(HX_CSTRING("list"));
	outFields->push(HX_CSTRING("front"));
	outFields->push(HX_CSTRING("back"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::context::UID*/ ,(int)offsetof(CameraContext_obj,cid),HX_CSTRING("cid")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(CameraContext_obj,list),HX_CSTRING("list")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(CameraContext_obj,front),HX_CSTRING("front")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(CameraContext_obj,back),HX_CSTRING("back")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("cid"),
	HX_CSTRING("list"),
	HX_CSTRING("front"),
	HX_CSTRING("back"),
	HX_CSTRING("Create"),
	HX_CSTRING("Destroy"),
	HX_CSTRING("Bind"),
	HX_CSTRING("Resize"),
	HX_CSTRING("ClearTargets"),
	HX_CSTRING("Unbind"),
	HX_CSTRING("SwapTargets"),
	HX_CSTRING("UpdateViewport"),
	HX_CSTRING("SortCameraList"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CameraContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CameraContext_obj::__mClass,"__mClass");
};

#endif

Class CameraContext_obj::__mClass;

void CameraContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.context.CameraContext"), hx::TCanCast< CameraContext_obj> ,sStaticFields,sMemberFields,
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

void CameraContext_obj::__boot()
{
}

} // end namespace haxor
} // end namespace context
