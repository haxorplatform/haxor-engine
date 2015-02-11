#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_ShaderContext
#include <haxor/context/ShaderContext.h>
#endif
#ifndef INCLUDED_haxor_core_Asset
#include <haxor/core/Asset.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
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
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_io_file_AssetFile
#include <haxor/io/file/AssetFile.h>
#endif
#ifndef INCLUDED_haxor_io_file_AssetXML
#include <haxor/io/file/AssetXML.h>
#endif
#ifndef INCLUDED_haxor_io_file_MaterialFile
#include <haxor/io/file/MaterialFile.h>
#endif
#ifndef INCLUDED_haxor_io_file_MaterialFileUniform
#include <haxor/io/file/MaterialFileUniform.h>
#endif
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
namespace haxor{
namespace io{
namespace file{

Void MaterialFile_obj::__construct(::String p_src)
{
HX_STACK_FRAME("haxor.io.file.MaterialFile","new",0xac40b0ab,"haxor.io.file.MaterialFile.new","haxor/io/file/MaterialFile.hx",109,0x5b3fbce4)
HX_STACK_THIS(this)
HX_STACK_ARG(p_src,"p_src")
{
	HX_STACK_LINE(110)
	this->mguid = HX_CSTRING("");
	HX_STACK_LINE(111)
	this->mname = HX_CSTRING("");
	HX_STACK_LINE(112)
	this->queue = HX_CSTRING("opaque");
	HX_STACK_LINE(113)
	this->offset = (int)0;
	HX_STACK_LINE(114)
	this->shader = HX_CSTRING("");
	HX_STACK_LINE(115)
	this->ztest = true;
	HX_STACK_LINE(116)
	this->zfunc = HX_CSTRING("lessequal");
	HX_STACK_LINE(117)
	this->zwrite = true;
	HX_STACK_LINE(118)
	this->blend = false;
	HX_STACK_LINE(119)
	this->blendSrc = HX_CSTRING("one");
	HX_STACK_LINE(120)
	this->blendDst = HX_CSTRING("zero");
	HX_STACK_LINE(121)
	this->invert = false;
	HX_STACK_LINE(122)
	this->lighting = false;
	HX_STACK_LINE(123)
	this->grab = false;
	HX_STACK_LINE(124)
	this->cull = HX_CSTRING("back");
	HX_STACK_LINE(125)
	this->uniforms = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(126)
	super::__construct(HX_CSTRING(""),p_src);
}
;
	return null();
}

//MaterialFile_obj::~MaterialFile_obj() { }

Dynamic MaterialFile_obj::__CreateEmpty() { return  new MaterialFile_obj; }
hx::ObjectPtr< MaterialFile_obj > MaterialFile_obj::__new(::String p_src)
{  hx::ObjectPtr< MaterialFile_obj > result = new MaterialFile_obj();
	result->__construct(p_src);
	return result;}

Dynamic MaterialFile_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MaterialFile_obj > result = new MaterialFile_obj();
	result->__construct(inArgs[0]);
	return result;}

Dynamic MaterialFile_obj::get_asset( ){
	HX_STACK_FRAME("haxor.io.file.MaterialFile","get_asset",0xc58170d2,"haxor.io.file.MaterialFile.get_asset","haxor/io/file/MaterialFile.hx",130,0x5b3fbce4)
	HX_STACK_THIS(this)
	HX_STACK_LINE(131)
	::haxor::graphics::material::Material m = ::haxor::graphics::material::Material_obj::__new(null());		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(132)
	m->set_name(this->mname);
	HX_STACK_LINE(133)
	m->m_guid = this->mguid;
	HX_STACK_LINE(135)
	{
		HX_STACK_LINE(135)
		::String _g = this->queue;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(135)
		::String _switch_1 = (_g);
		if (  ( _switch_1==HX_CSTRING("geometry"))){
			HX_STACK_LINE(137)
			m->queue = (int)1000;
		}
		else if (  ( _switch_1==HX_CSTRING("background"))){
			HX_STACK_LINE(138)
			m->queue = (int)0;
		}
		else if (  ( _switch_1==HX_CSTRING("opaque"))){
			HX_STACK_LINE(139)
			m->queue = (int)1000;
		}
		else if (  ( _switch_1==HX_CSTRING("transparent"))){
			HX_STACK_LINE(140)
			m->queue = (int)2000;
		}
		else if (  ( _switch_1==HX_CSTRING("overlay"))){
			HX_STACK_LINE(141)
			m->queue = (int)3000;
		}
		else if (  ( _switch_1==HX_CSTRING("interface"))){
			HX_STACK_LINE(142)
			m->queue = (int)4000;
		}
	}
	HX_STACK_LINE(144)
	hx::AddEq(m->queue,this->offset);
	HX_STACK_LINE(145)
	::haxor::graphics::material::Shader shd = ::haxor::core::Asset_obj::Get(this->shader);		HX_STACK_VAR(shd,"shd");
	HX_STACK_LINE(146)
	if (((shd == null()))){
		HX_STACK_LINE(146)
		::haxor::core::Console_obj::LogWarning(((((HX_CSTRING("MaterialFile> [") + this->m_name) + HX_CSTRING("] shader[")) + this->shader) + HX_CSTRING("] is null!")),null());
		HX_STACK_LINE(146)
		::haxor::graphics::material::Shader _g1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(146)
		if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
			HX_STACK_LINE(146)
			::haxor::graphics::material::Shader _g = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(146)
			_g1 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g;
		}
		else{
			HX_STACK_LINE(146)
			_g1 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
		}
		HX_STACK_LINE(146)
		shd = _g1;
	}
	HX_STACK_LINE(147)
	m->set_shader(shd);
	HX_STACK_LINE(148)
	m->ztest = this->ztest;
	HX_STACK_LINE(149)
	m->zfunc = (int)515;
	HX_STACK_LINE(150)
	{
		HX_STACK_LINE(150)
		::String _g = this->zfunc;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(150)
		::String _switch_2 = (_g);
		if (  ( _switch_2==HX_CSTRING("never"))){
			HX_STACK_LINE(152)
			m->zfunc = (int)512;
		}
		else if (  ( _switch_2==HX_CSTRING("always"))){
			HX_STACK_LINE(153)
			m->zfunc = (int)519;
		}
		else if (  ( _switch_2==HX_CSTRING("notequal"))){
			HX_STACK_LINE(154)
			m->zfunc = (int)517;
		}
		else if (  ( _switch_2==HX_CSTRING("equal"))){
			HX_STACK_LINE(155)
			m->zfunc = (int)514;
		}
		else if (  ( _switch_2==HX_CSTRING("less"))){
			HX_STACK_LINE(156)
			m->zfunc = (int)513;
		}
		else if (  ( _switch_2==HX_CSTRING("lessequal"))){
			HX_STACK_LINE(157)
			m->zfunc = (int)515;
		}
		else if (  ( _switch_2==HX_CSTRING("greater"))){
			HX_STACK_LINE(158)
			m->zfunc = (int)516;
		}
		else if (  ( _switch_2==HX_CSTRING("greaterequal"))){
			HX_STACK_LINE(159)
			m->zfunc = (int)518;
		}
	}
	HX_STACK_LINE(161)
	m->zwrite = this->zwrite;
	HX_STACK_LINE(162)
	m->blend = this->blend;
	HX_STACK_LINE(163)
	int _g2 = this->BlendModeNameToEnum(this->blendSrc);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(163)
	m->blendSrc = _g2;
	HX_STACK_LINE(164)
	int _g3 = this->BlendModeNameToEnum(this->blendDst);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(164)
	m->blendDst = _g3;
	HX_STACK_LINE(165)
	m->invert = this->invert;
	HX_STACK_LINE(166)
	m->lighting = this->lighting;
	HX_STACK_LINE(167)
	m->grab = this->grab;
	HX_STACK_LINE(168)
	{
		HX_STACK_LINE(168)
		::String _g = this->cull;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(168)
		::String _switch_3 = (_g);
		if (  ( _switch_3==HX_CSTRING("none"))){
			HX_STACK_LINE(170)
			m->cull = (int)0;
		}
		else if (  ( _switch_3==HX_CSTRING("front"))){
			HX_STACK_LINE(171)
			m->cull = (int)1;
		}
		else if (  ( _switch_3==HX_CSTRING("back"))){
			HX_STACK_LINE(172)
			m->cull = (int)2;
		}
	}
	HX_STACK_LINE(174)
	{
		HX_STACK_LINE(174)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(174)
		int _g = this->uniforms->length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(174)
		while((true)){
			HX_STACK_LINE(174)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(174)
				break;
			}
			HX_STACK_LINE(174)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(176)
			::haxor::io::file::MaterialFileUniform u = this->uniforms->__get(i).StaticCast< ::haxor::io::file::MaterialFileUniform >();		HX_STACK_VAR(u,"u");
			HX_STACK_LINE(177)
			Array< Float > a = this->stof32a(u->value,null());		HX_STACK_VAR(a,"a");
			HX_STACK_LINE(178)
			{
				HX_STACK_LINE(178)
				::String _g21 = u->type;		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(178)
				::String _switch_4 = (_g21);
				if (  ( _switch_4==HX_CSTRING("int"))){
					HX_STACK_LINE(180)
					Dynamic _g4 = ::Std_obj::parseInt(u->value);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(180)
					m->SetInt(u->name,_g4);
				}
				else if (  ( _switch_4==HX_CSTRING("vec2"))){
					HX_STACK_LINE(181)
					m->SetFloat2(u->name,a->__get((int)0),a->__get((int)1));
				}
				else if (  ( _switch_4==HX_CSTRING("vec3"))){
					HX_STACK_LINE(182)
					m->SetFloat3(u->name,a->__get((int)0),a->__get((int)1),a->__get((int)2));
				}
				else if (  ( _switch_4==HX_CSTRING("vec4"))){
					HX_STACK_LINE(183)
					m->SetFloat4(u->name,a->__get((int)0),a->__get((int)1),a->__get((int)2),a->__get((int)3));
				}
				else if (  ( _switch_4==HX_CSTRING("mat4"))){
					HX_STACK_LINE(184)
					::haxor::math::Matrix4 _g6;		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(184)
					{
						HX_STACK_LINE(184)
						::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
						HX_STACK_LINE(184)
						int _g5 = _this->m_nq = hx::Mod(((_this->m_nm4 + (int)1)),_this->m_m4->length);		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(184)
						_g6 = _this->m_m4->__get(_g5).StaticCast< ::haxor::math::Matrix4 >();
					}
					HX_STACK_LINE(184)
					::haxor::math::Matrix4 _g7 = ::haxor::math::Matrix4_obj::FromArray(a,_g6);		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(184)
					m->SetMatrix4(u->name,_g7,null());
				}
				else if (  ( _switch_4==HX_CSTRING("color"))){
					HX_STACK_LINE(185)
					m->SetFloat4(u->name,a->__get((int)0),a->__get((int)1),a->__get((int)2),a->__get((int)3));
				}
				else if (  ( _switch_4==HX_CSTRING("texture"))){
					HX_STACK_LINE(186)
					Dynamic _g8 = ::haxor::core::Asset_obj::Get(u->value);		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(186)
					m->SetTexture(u->name,_g8);
				}
			}
		}
	}
	HX_STACK_LINE(189)
	return m;
}


Void MaterialFile_obj::Parse( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.MaterialFile","Parse",0x79a0c91e,"haxor.io.file.MaterialFile.Parse","haxor/io/file/MaterialFile.hx",196,0x5b3fbce4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(196)
		::String _g = n->get_nodeName();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(196)
		::String _switch_5 = (_g);
		if (  ( _switch_5==HX_CSTRING("material"))){
			HX_STACK_LINE(199)
			::String _g1 = this->_a(n,HX_CSTRING("guid"),HX_CSTRING(""));		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(199)
			this->mguid = _g1;
			HX_STACK_LINE(200)
			::String _g11 = this->_a(n,HX_CSTRING("name"),HX_CSTRING(""));		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(200)
			this->mname = _g11;
		}
		else if (  ( _switch_5==HX_CSTRING("queue"))){
			HX_STACK_LINE(203)
			::String _g2 = this->_a(n,HX_CSTRING("offset"),HX_CSTRING("0"));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(203)
			Dynamic _g3 = ::Std_obj::parseInt(_g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(203)
			this->offset = _g3;
			HX_STACK_LINE(204)
			Dynamic _g4 = this->_p(n,HX_CSTRING("$text"),HX_CSTRING("geometry"),true,true);		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(204)
			this->queue = _g4;
		}
		else if (  ( _switch_5==HX_CSTRING("shader"))){
			HX_STACK_LINE(206)
			Dynamic _g5 = this->_p(n,HX_CSTRING("$text"),HX_CSTRING(""),null(),null());		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(206)
			this->shader = _g5;
		}
		else if (  ( _switch_5==HX_CSTRING("ztest"))){
			HX_STACK_LINE(207)
			Dynamic _g6 = this->_p(n,HX_CSTRING("$text"),HX_CSTRING("true"),true,true);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(207)
			bool _g7 = (_g6 == HX_CSTRING("true"));		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(207)
			this->ztest = _g7;
		}
		else if (  ( _switch_5==HX_CSTRING("zfunc"))){
			HX_STACK_LINE(208)
			Dynamic _g8 = this->_p(n,HX_CSTRING("$text"),this->zfunc,null(),null());		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(208)
			this->zfunc = _g8;
		}
		else if (  ( _switch_5==HX_CSTRING("zwrite"))){
			HX_STACK_LINE(209)
			Dynamic _g9 = this->_p(n,HX_CSTRING("$text"),HX_CSTRING("true"),true,true);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(209)
			bool _g10 = (_g9 == HX_CSTRING("true"));		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(209)
			this->zwrite = _g10;
		}
		else if (  ( _switch_5==HX_CSTRING("blend"))){
			HX_STACK_LINE(210)
			::String _g11 = this->_a(n,HX_CSTRING("enabled"),HX_CSTRING("false"));		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(210)
			bool _g12 = (_g11 == HX_CSTRING("true"));		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(210)
			this->blend = _g12;
			HX_STACK_LINE(211)
			Dynamic _g13 = this->_p(n,HX_CSTRING("src.$text"),HX_CSTRING("one"),true,true);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(211)
			this->blendSrc = _g13;
			HX_STACK_LINE(212)
			Dynamic _g14 = this->_p(n,HX_CSTRING("dst.$text"),HX_CSTRING("zero"),true,true);		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(212)
			this->blendDst = _g14;
		}
		else if (  ( _switch_5==HX_CSTRING("invert"))){
			HX_STACK_LINE(213)
			Dynamic _g15 = this->_p(n,HX_CSTRING("$text"),HX_CSTRING("false"),true,true);		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(213)
			bool _g16 = (_g15 == HX_CSTRING("true"));		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(213)
			this->invert = _g16;
		}
		else if (  ( _switch_5==HX_CSTRING("lighting"))){
			HX_STACK_LINE(214)
			Dynamic _g17 = this->_p(n,HX_CSTRING("$text"),HX_CSTRING("false"),true,true);		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(214)
			bool _g18 = (_g17 == HX_CSTRING("true"));		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(214)
			this->lighting = _g18;
		}
		else if (  ( _switch_5==HX_CSTRING("grab"))){
			HX_STACK_LINE(215)
			Dynamic _g19 = this->_p(n,HX_CSTRING("$text"),HX_CSTRING("false"),true,true);		HX_STACK_VAR(_g19,"_g19");
			HX_STACK_LINE(215)
			bool _g20 = (_g19 == HX_CSTRING("true"));		HX_STACK_VAR(_g20,"_g20");
			HX_STACK_LINE(215)
			this->grab = _g20;
		}
		else if (  ( _switch_5==HX_CSTRING("cull"))){
			HX_STACK_LINE(216)
			Dynamic _g21 = this->_p(n,HX_CSTRING("$text"),this->cull,true,true);		HX_STACK_VAR(_g21,"_g21");
			HX_STACK_LINE(216)
			this->cull = _g21;
		}
		else if (  ( _switch_5==HX_CSTRING("uniforms"))){
			HX_STACK_LINE(218)
			this->ParseUniforms(n);
		}
	}
return null();
}


Void MaterialFile_obj::ParseUniforms( ::Xml n){
{
		HX_STACK_FRAME("haxor.io.file.MaterialFile","ParseUniforms",0x39629ffd,"haxor.io.file.MaterialFile.ParseUniforms","haxor/io/file/MaterialFile.hx",227,0x5b3fbce4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(228)
		Dynamic it = n->elements();		HX_STACK_VAR(it,"it");
		HX_STACK_LINE(229)
		while((true)){
			HX_STACK_LINE(229)
			if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
				HX_STACK_LINE(229)
				break;
			}
			HX_STACK_LINE(231)
			::Xml _g = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(231)
			n = _g;
			HX_STACK_LINE(232)
			::haxor::io::file::MaterialFileUniform u = ::haxor::io::file::MaterialFileUniform_obj::__new();		HX_STACK_VAR(u,"u");
			HX_STACK_LINE(233)
			::String _g1 = n->get_nodeName().toLowerCase();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(233)
			u->type = _g1;
			HX_STACK_LINE(234)
			::String _g2 = this->_a(n,HX_CSTRING("name"),HX_CSTRING(""));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(234)
			u->name = _g2;
			HX_STACK_LINE(235)
			Dynamic _g3 = this->_p(n,HX_CSTRING("$text"),HX_CSTRING(""),true,null());		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(235)
			u->value = _g3;
			HX_STACK_LINE(236)
			this->uniforms->push(u);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialFile_obj,ParseUniforms,(void))

int MaterialFile_obj::BlendModeNameToEnum( ::String b){
	HX_STACK_FRAME("haxor.io.file.MaterialFile","BlendModeNameToEnum",0xc2f0fe66,"haxor.io.file.MaterialFile.BlendModeNameToEnum","haxor/io/file/MaterialFile.hx",242,0x5b3fbce4)
	HX_STACK_THIS(this)
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(243)
	::String _switch_6 = (b);
	if (  ( _switch_6==HX_CSTRING("zero"))){
		HX_STACK_LINE(245)
		return (int)0;
	}
	else if (  ( _switch_6==HX_CSTRING("one"))){
		HX_STACK_LINE(246)
		return (int)1;
	}
	else if (  ( _switch_6==HX_CSTRING("srccolor"))){
		HX_STACK_LINE(247)
		return (int)768;
	}
	else if (  ( _switch_6==HX_CSTRING("oneminussrccolor"))){
		HX_STACK_LINE(248)
		return (int)769;
	}
	else if (  ( _switch_6==HX_CSTRING("srcalpha"))){
		HX_STACK_LINE(249)
		return (int)770;
	}
	else if (  ( _switch_6==HX_CSTRING("oneminussrcalpha"))){
		HX_STACK_LINE(250)
		return (int)771;
	}
	else if (  ( _switch_6==HX_CSTRING("dstalpha"))){
		HX_STACK_LINE(251)
		return (int)772;
	}
	else if (  ( _switch_6==HX_CSTRING("oneminusdstalpha"))){
		HX_STACK_LINE(252)
		return (int)773;
	}
	else if (  ( _switch_6==HX_CSTRING("dstcolor"))){
		HX_STACK_LINE(253)
		return (int)774;
	}
	else if (  ( _switch_6==HX_CSTRING("oneminusdstcolor"))){
		HX_STACK_LINE(254)
		return (int)775;
	}
	else if (  ( _switch_6==HX_CSTRING("srcalphasaturate"))){
		HX_STACK_LINE(255)
		return (int)776;
	}
	HX_STACK_LINE(257)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC1(MaterialFile_obj,BlendModeNameToEnum,return )


MaterialFile_obj::MaterialFile_obj()
{
}

void MaterialFile_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MaterialFile);
	HX_MARK_MEMBER_NAME(mguid,"mguid");
	HX_MARK_MEMBER_NAME(mname,"mname");
	HX_MARK_MEMBER_NAME(queue,"queue");
	HX_MARK_MEMBER_NAME(shader,"shader");
	HX_MARK_MEMBER_NAME(offset,"offset");
	HX_MARK_MEMBER_NAME(ztest,"ztest");
	HX_MARK_MEMBER_NAME(zfunc,"zfunc");
	HX_MARK_MEMBER_NAME(zwrite,"zwrite");
	HX_MARK_MEMBER_NAME(blend,"blend");
	HX_MARK_MEMBER_NAME(blendSrc,"blendSrc");
	HX_MARK_MEMBER_NAME(blendDst,"blendDst");
	HX_MARK_MEMBER_NAME(invert,"invert");
	HX_MARK_MEMBER_NAME(lighting,"lighting");
	HX_MARK_MEMBER_NAME(grab,"grab");
	HX_MARK_MEMBER_NAME(cull,"cull");
	HX_MARK_MEMBER_NAME(uniforms,"uniforms");
	::haxor::io::file::AssetXML_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MaterialFile_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mguid,"mguid");
	HX_VISIT_MEMBER_NAME(mname,"mname");
	HX_VISIT_MEMBER_NAME(queue,"queue");
	HX_VISIT_MEMBER_NAME(shader,"shader");
	HX_VISIT_MEMBER_NAME(offset,"offset");
	HX_VISIT_MEMBER_NAME(ztest,"ztest");
	HX_VISIT_MEMBER_NAME(zfunc,"zfunc");
	HX_VISIT_MEMBER_NAME(zwrite,"zwrite");
	HX_VISIT_MEMBER_NAME(blend,"blend");
	HX_VISIT_MEMBER_NAME(blendSrc,"blendSrc");
	HX_VISIT_MEMBER_NAME(blendDst,"blendDst");
	HX_VISIT_MEMBER_NAME(invert,"invert");
	HX_VISIT_MEMBER_NAME(lighting,"lighting");
	HX_VISIT_MEMBER_NAME(grab,"grab");
	HX_VISIT_MEMBER_NAME(cull,"cull");
	HX_VISIT_MEMBER_NAME(uniforms,"uniforms");
	::haxor::io::file::AssetXML_obj::__Visit(HX_VISIT_ARG);
}

Dynamic MaterialFile_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"grab") ) { return grab; }
		if (HX_FIELD_EQ(inName,"cull") ) { return cull; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mguid") ) { return mguid; }
		if (HX_FIELD_EQ(inName,"mname") ) { return mname; }
		if (HX_FIELD_EQ(inName,"queue") ) { return queue; }
		if (HX_FIELD_EQ(inName,"ztest") ) { return ztest; }
		if (HX_FIELD_EQ(inName,"zfunc") ) { return zfunc; }
		if (HX_FIELD_EQ(inName,"blend") ) { return blend; }
		if (HX_FIELD_EQ(inName,"Parse") ) { return Parse_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"shader") ) { return shader; }
		if (HX_FIELD_EQ(inName,"offset") ) { return offset; }
		if (HX_FIELD_EQ(inName,"zwrite") ) { return zwrite; }
		if (HX_FIELD_EQ(inName,"invert") ) { return invert; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"blendSrc") ) { return blendSrc; }
		if (HX_FIELD_EQ(inName,"blendDst") ) { return blendDst; }
		if (HX_FIELD_EQ(inName,"lighting") ) { return lighting; }
		if (HX_FIELD_EQ(inName,"uniforms") ) { return uniforms; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_asset") ) { return get_asset_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"ParseUniforms") ) { return ParseUniforms_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"BlendModeNameToEnum") ) { return BlendModeNameToEnum_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MaterialFile_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"grab") ) { grab=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cull") ) { cull=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mguid") ) { mguid=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mname") ) { mname=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"queue") ) { queue=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ztest") ) { ztest=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"zfunc") ) { zfunc=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blend") ) { blend=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"shader") ) { shader=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offset") ) { offset=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"zwrite") ) { zwrite=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"invert") ) { invert=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"blendSrc") ) { blendSrc=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"blendDst") ) { blendDst=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lighting") ) { lighting=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"uniforms") ) { uniforms=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MaterialFile_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mguid"));
	outFields->push(HX_CSTRING("mname"));
	outFields->push(HX_CSTRING("queue"));
	outFields->push(HX_CSTRING("shader"));
	outFields->push(HX_CSTRING("offset"));
	outFields->push(HX_CSTRING("ztest"));
	outFields->push(HX_CSTRING("zfunc"));
	outFields->push(HX_CSTRING("zwrite"));
	outFields->push(HX_CSTRING("blend"));
	outFields->push(HX_CSTRING("blendSrc"));
	outFields->push(HX_CSTRING("blendDst"));
	outFields->push(HX_CSTRING("invert"));
	outFields->push(HX_CSTRING("lighting"));
	outFields->push(HX_CSTRING("grab"));
	outFields->push(HX_CSTRING("cull"));
	outFields->push(HX_CSTRING("uniforms"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(MaterialFile_obj,mguid),HX_CSTRING("mguid")},
	{hx::fsString,(int)offsetof(MaterialFile_obj,mname),HX_CSTRING("mname")},
	{hx::fsString,(int)offsetof(MaterialFile_obj,queue),HX_CSTRING("queue")},
	{hx::fsString,(int)offsetof(MaterialFile_obj,shader),HX_CSTRING("shader")},
	{hx::fsInt,(int)offsetof(MaterialFile_obj,offset),HX_CSTRING("offset")},
	{hx::fsBool,(int)offsetof(MaterialFile_obj,ztest),HX_CSTRING("ztest")},
	{hx::fsString,(int)offsetof(MaterialFile_obj,zfunc),HX_CSTRING("zfunc")},
	{hx::fsBool,(int)offsetof(MaterialFile_obj,zwrite),HX_CSTRING("zwrite")},
	{hx::fsBool,(int)offsetof(MaterialFile_obj,blend),HX_CSTRING("blend")},
	{hx::fsString,(int)offsetof(MaterialFile_obj,blendSrc),HX_CSTRING("blendSrc")},
	{hx::fsString,(int)offsetof(MaterialFile_obj,blendDst),HX_CSTRING("blendDst")},
	{hx::fsBool,(int)offsetof(MaterialFile_obj,invert),HX_CSTRING("invert")},
	{hx::fsBool,(int)offsetof(MaterialFile_obj,lighting),HX_CSTRING("lighting")},
	{hx::fsBool,(int)offsetof(MaterialFile_obj,grab),HX_CSTRING("grab")},
	{hx::fsString,(int)offsetof(MaterialFile_obj,cull),HX_CSTRING("cull")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(MaterialFile_obj,uniforms),HX_CSTRING("uniforms")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("mguid"),
	HX_CSTRING("mname"),
	HX_CSTRING("queue"),
	HX_CSTRING("shader"),
	HX_CSTRING("offset"),
	HX_CSTRING("ztest"),
	HX_CSTRING("zfunc"),
	HX_CSTRING("zwrite"),
	HX_CSTRING("blend"),
	HX_CSTRING("blendSrc"),
	HX_CSTRING("blendDst"),
	HX_CSTRING("invert"),
	HX_CSTRING("lighting"),
	HX_CSTRING("grab"),
	HX_CSTRING("cull"),
	HX_CSTRING("uniforms"),
	HX_CSTRING("get_asset"),
	HX_CSTRING("Parse"),
	HX_CSTRING("ParseUniforms"),
	HX_CSTRING("BlendModeNameToEnum"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MaterialFile_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MaterialFile_obj::__mClass,"__mClass");
};

#endif

Class MaterialFile_obj::__mClass;

void MaterialFile_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.io.file.MaterialFile"), hx::TCanCast< MaterialFile_obj> ,sStaticFields,sMemberFields,
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

void MaterialFile_obj::__boot()
{
}

} // end namespace haxor
} // end namespace io
} // end namespace file
