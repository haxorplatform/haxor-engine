#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_component_MeshRenderer
#include <haxor/component/MeshRenderer.h>
#endif
#ifndef INCLUDED_haxor_component_ParticleAttribute
#include <haxor/component/ParticleAttribute.h>
#endif
#ifndef INCLUDED_haxor_component_ParticleEmitter
#include <haxor/component/ParticleEmitter.h>
#endif
#ifndef INCLUDED_haxor_component_ParticleLife
#include <haxor/component/ParticleLife.h>
#endif
#ifndef INCLUDED_haxor_component_ParticleRenderer
#include <haxor/component/ParticleRenderer.h>
#endif
#ifndef INCLUDED_haxor_component_ParticleSheet
#include <haxor/component/ParticleSheet.h>
#endif
#ifndef INCLUDED_haxor_component_ParticleStart
#include <haxor/component/ParticleStart.h>
#endif
#ifndef INCLUDED_haxor_component_ParticleSystemState
#include <haxor/component/ParticleSystemState.h>
#endif
#ifndef INCLUDED_haxor_component_Renderer
#include <haxor/component/Renderer.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_core_AnimationWrap
#include <haxor/core/AnimationWrap.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
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
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_MaterialUniform
#include <haxor/graphics/material/MaterialUniform.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Shader
#include <haxor/graphics/material/Shader.h>
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
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_thread_Kernel
#include <haxor/thread/Kernel.h>
#endif
#ifndef INCLUDED_haxor_thread_ParticleKernel
#include <haxor/thread/ParticleKernel.h>
#endif
namespace haxor{
namespace thread{

Void ParticleKernel_obj::__construct(::haxor::component::ParticleRenderer p_renderer)
{
HX_STACK_FRAME("haxor.thread.ParticleKernel","new",0xf0adb12d,"haxor.thread.ParticleKernel.new","haxor/thread/ParticleKernel.hx",42,0x122a7cc3)
HX_STACK_THIS(this)
HX_STACK_ARG(p_renderer,"p_renderer")
{
	HX_STACK_LINE(43)
	super::__construct(::haxor::thread::ParticleKernel_obj::DATA_SIZE,::haxor::thread::ParticleKernel_obj::DATA_SIZE,false,::haxor::core::PixelFormat_obj::Float4);
	HX_STACK_LINE(45)
	int _g = p_renderer->get_uid();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(45)
	::String _g1 = (HX_CSTRING("ParticleKernel") + _g);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(45)
	this->set_name(_g1);
	HX_STACK_LINE(47)
	if (((::haxor::thread::ParticleKernel_obj::particle_kernel_shader == null()))){
		HX_STACK_LINE(47)
		::haxor::graphics::material::Shader _g2 = ::haxor::graphics::material::Shader_obj::__new(::haxor::thread::ParticleKernel_obj::particle_kernel_source);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(47)
		::haxor::thread::ParticleKernel_obj::particle_kernel_shader = _g2;
	}
	HX_STACK_LINE(49)
	::haxor::graphics::texture::RenderTexture _g3 = ::haxor::graphics::texture::RenderTexture_obj::__new(::haxor::thread::ParticleKernel_obj::DATA_SIZE,::haxor::thread::ParticleKernel_obj::DATA_SIZE,::haxor::core::PixelFormat_obj::Float4,null());		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(49)
	this->m_back = _g3;
	HX_STACK_LINE(50)
	this->m_back->set_minFilter(::haxor::core::TextureFilter_obj::Nearest);
	HX_STACK_LINE(51)
	this->m_back->set_magFilter(::haxor::core::TextureFilter_obj::Nearest);
	HX_STACK_LINE(52)
	this->m_back->set_name(HX_CSTRING("ParticleKernelData0"));
	HX_STACK_LINE(53)
	this->m_output->set_name(HX_CSTRING("ParticleKernelData1"));
	HX_STACK_LINE(54)
	this->m_renderer = p_renderer;
	HX_STACK_LINE(56)
	this->m_time = ::haxor::core::Time_obj::m_elapsed;
	HX_STACK_LINE(57)
	this->m_dt = 0.0;
	HX_STACK_LINE(58)
	this->m_resize = false;
	HX_STACK_LINE(60)
	this->set_shader(::haxor::thread::ParticleKernel_obj::particle_kernel_shader);
	HX_STACK_LINE(62)
	this->m_system = Array_obj< Float >::__new().Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)0);
	HX_STACK_LINE(92)
	this->SetTexture(HX_CSTRING("Data"),this->m_back);
	HX_STACK_LINE(93)
	this->SetFloat4Array(HX_CSTRING("System"),this->m_system);
}
;
	return null();
}

//ParticleKernel_obj::~ParticleKernel_obj() { }

Dynamic ParticleKernel_obj::__CreateEmpty() { return  new ParticleKernel_obj; }
hx::ObjectPtr< ParticleKernel_obj > ParticleKernel_obj::__new(::haxor::component::ParticleRenderer p_renderer)
{  hx::ObjectPtr< ParticleKernel_obj > result = new ParticleKernel_obj();
	result->__construct(p_renderer);
	return result;}

Dynamic ParticleKernel_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ParticleKernel_obj > result = new ParticleKernel_obj();
	result->__construct(inArgs[0]);
	return result;}

Void ParticleKernel_obj::Execute( ){
{
		HX_STACK_FRAME("haxor.thread.ParticleKernel","Execute",0xf54cfd62,"haxor.thread.ParticleKernel.Execute","haxor/thread/ParticleKernel.hx",97,0x122a7cc3)
		HX_STACK_THIS(this)
		HX_STACK_LINE(98)
		if ((this->m_resize)){
			HX_STACK_LINE(100)
			this->m_resize = false;
		}
		HX_STACK_LINE(103)
		Array< Float > s = this->m_system;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(104)
		::haxor::component::ParticleRenderer r = this->m_renderer;		HX_STACK_VAR(r,"r");
		HX_STACK_LINE(105)
		::haxor::component::ParticleAttribute af;		HX_STACK_VAR(af,"af");
		HX_STACK_LINE(106)
		::haxor::component::ParticleAttribute af3;		HX_STACK_VAR(af3,"af3");
		HX_STACK_LINE(107)
		int k = (int)0;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(110)
		int _g = (k)++;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(110)
		s[_g] = r->emitter->m_data->__get((int)0);
		HX_STACK_LINE(111)
		int _g1 = (k)++;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(111)
		s[_g1] = r->emitter->m_data->__get((int)3);
		HX_STACK_LINE(112)
		int _g2 = (k)++;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(112)
		s[_g2] = r->emitter->m_data->__get((int)4);
		HX_STACK_LINE(113)
		int _g3 = (k)++;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(113)
		s[_g3] = r->emitter->m_data->__get((int)5);
		HX_STACK_LINE(114)
		int _g4 = (k)++;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(114)
		s[_g4] = r->emitter->m_data->__get((int)1);
		HX_STACK_LINE(115)
		int _g5 = (k)++;		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(115)
		s[_g5] = r->emitter->m_data->__get((int)2);
		HX_STACK_LINE(117)
		int _g6 = (k)++;		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(117)
		if ((r->local)){
			HX_STACK_LINE(117)
			s[_g6] = 1.0;
		}
		else{
			HX_STACK_LINE(117)
			s[_g6] = 0.0;
		}
		HX_STACK_LINE(118)
		int _g7 = (k)++;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(118)
		if ((r->loop)){
			HX_STACK_LINE(118)
			s[_g7] = 1.0;
		}
		else{
			HX_STACK_LINE(118)
			s[_g7] = 0.0;
		}
		HX_STACK_LINE(119)
		int _g8 = (k)++;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(119)
		if (((r->m_state == ::haxor::component::ParticleSystemState_obj::None))){
			HX_STACK_LINE(119)
			s[_g8] = 0.0;
		}
		else{
			HX_STACK_LINE(119)
			if (((r->m_state == ::haxor::component::ParticleSystemState_obj::Reset))){
				HX_STACK_LINE(119)
				s[_g8] = 1.0;
			}
			else{
				HX_STACK_LINE(119)
				if (((r->m_state == ::haxor::component::ParticleSystemState_obj::Update))){
					HX_STACK_LINE(119)
					s[_g8] = 2.0;
				}
				else{
					HX_STACK_LINE(119)
					s[_g8] = 0.0;
				}
			}
		}
		HX_STACK_LINE(120)
		int _g9 = (k)++;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(120)
		{
			HX_STACK_LINE(120)
			Float p_v;		HX_STACK_VAR(p_v,"p_v");
			HX_STACK_LINE(120)
			if (((r->duration <= 0.0))){
				HX_STACK_LINE(120)
				p_v = 0.0;
			}
			else{
				HX_STACK_LINE(120)
				p_v = (Float(r->elapsed) / Float(r->duration));
			}
			HX_STACK_LINE(120)
			if (((p_v <= 0.0))){
				HX_STACK_LINE(120)
				s[_g9] = 0.0;
			}
			else{
				HX_STACK_LINE(120)
				if (((p_v >= 1.0))){
					HX_STACK_LINE(120)
					s[_g9] = 1.0;
				}
				else{
					HX_STACK_LINE(120)
					s[_g9] = p_v;
				}
			}
		}
		HX_STACK_LINE(121)
		int _g10 = (k)++;		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(121)
		s[_g10] = 0.0;
		HX_STACK_LINE(122)
		int _g11 = (k)++;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(122)
		s[_g11] = ::haxor::core::Time_obj::m_delta;
		HX_STACK_LINE(124)
		af = r->start->speed;
		HX_STACK_LINE(125)
		int _g12 = (k)++;		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(125)
		s[_g12] = af->start;
		HX_STACK_LINE(126)
		int _g13 = (k)++;		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(126)
		s[_g13] = af->end;
		HX_STACK_LINE(127)
		int _g14 = (k)++;		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(127)
		s[_g14] = af->curve;
		HX_STACK_LINE(128)
		int _g15 = (k)++;		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(128)
		if ((af->random)){
			HX_STACK_LINE(128)
			s[_g15] = 1.0;
		}
		else{
			HX_STACK_LINE(128)
			s[_g15] = 0.0;
		}
		HX_STACK_LINE(130)
		af3 = r->start->size;
		HX_STACK_LINE(131)
		int _g16 = (k)++;		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(131)
		s[_g16] = af3->start->__Field(HX_CSTRING("x"),true);
		HX_STACK_LINE(132)
		int _g17 = (k)++;		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(132)
		s[_g17] = af3->start->__Field(HX_CSTRING("y"),true);
		HX_STACK_LINE(133)
		int _g18 = (k)++;		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(133)
		s[_g18] = af3->start->__Field(HX_CSTRING("z"),true);
		HX_STACK_LINE(134)
		int _g19 = (k)++;		HX_STACK_VAR(_g19,"_g19");
		HX_STACK_LINE(134)
		s[_g19] = af3->curve;
		HX_STACK_LINE(135)
		int _g20 = (k)++;		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(135)
		s[_g20] = af3->end->__Field(HX_CSTRING("x"),true);
		HX_STACK_LINE(136)
		int _g21 = (k)++;		HX_STACK_VAR(_g21,"_g21");
		HX_STACK_LINE(136)
		s[_g21] = af3->end->__Field(HX_CSTRING("y"),true);
		HX_STACK_LINE(137)
		int _g22 = (k)++;		HX_STACK_VAR(_g22,"_g22");
		HX_STACK_LINE(137)
		s[_g22] = af3->end->__Field(HX_CSTRING("z"),true);
		HX_STACK_LINE(138)
		int _g23 = (k)++;		HX_STACK_VAR(_g23,"_g23");
		HX_STACK_LINE(138)
		if ((af3->random)){
			HX_STACK_LINE(138)
			s[_g23] = 1.0;
		}
		else{
			HX_STACK_LINE(138)
			s[_g23] = 0.0;
		}
		HX_STACK_LINE(140)
		af = r->start->life;
		HX_STACK_LINE(141)
		int _g24 = (k)++;		HX_STACK_VAR(_g24,"_g24");
		HX_STACK_LINE(141)
		s[_g24] = af->start;
		HX_STACK_LINE(142)
		int _g25 = (k)++;		HX_STACK_VAR(_g25,"_g25");
		HX_STACK_LINE(142)
		s[_g25] = af->end;
		HX_STACK_LINE(143)
		int _g26 = (k)++;		HX_STACK_VAR(_g26,"_g26");
		HX_STACK_LINE(143)
		s[_g26] = af->curve;
		HX_STACK_LINE(144)
		int _g27 = (k)++;		HX_STACK_VAR(_g27,"_g27");
		HX_STACK_LINE(144)
		if ((af->random)){
			HX_STACK_LINE(144)
			s[_g27] = 1.0;
		}
		else{
			HX_STACK_LINE(144)
			s[_g27] = 0.0;
		}
		HX_STACK_LINE(146)
		af3 = r->start->rotation;
		HX_STACK_LINE(147)
		int _g28 = (k)++;		HX_STACK_VAR(_g28,"_g28");
		HX_STACK_LINE(147)
		s[_g28] = af3->start->__Field(HX_CSTRING("x"),true);
		HX_STACK_LINE(148)
		int _g29 = (k)++;		HX_STACK_VAR(_g29,"_g29");
		HX_STACK_LINE(148)
		s[_g29] = af3->start->__Field(HX_CSTRING("y"),true);
		HX_STACK_LINE(149)
		int _g30 = (k)++;		HX_STACK_VAR(_g30,"_g30");
		HX_STACK_LINE(149)
		s[_g30] = af3->start->__Field(HX_CSTRING("z"),true);
		HX_STACK_LINE(150)
		int _g31 = (k)++;		HX_STACK_VAR(_g31,"_g31");
		HX_STACK_LINE(150)
		s[_g31] = af3->curve;
		HX_STACK_LINE(151)
		int _g32 = (k)++;		HX_STACK_VAR(_g32,"_g32");
		HX_STACK_LINE(151)
		s[_g32] = af3->end->__Field(HX_CSTRING("x"),true);
		HX_STACK_LINE(152)
		int _g33 = (k)++;		HX_STACK_VAR(_g33,"_g33");
		HX_STACK_LINE(152)
		s[_g33] = af3->end->__Field(HX_CSTRING("y"),true);
		HX_STACK_LINE(153)
		int _g34 = (k)++;		HX_STACK_VAR(_g34,"_g34");
		HX_STACK_LINE(153)
		s[_g34] = af3->end->__Field(HX_CSTRING("z"),true);
		HX_STACK_LINE(154)
		int _g35 = (k)++;		HX_STACK_VAR(_g35,"_g35");
		HX_STACK_LINE(154)
		if ((af3->random)){
			HX_STACK_LINE(154)
			s[_g35] = 1.0;
		}
		else{
			HX_STACK_LINE(154)
			s[_g35] = 0.0;
		}
		HX_STACK_LINE(156)
		af = r->life->speed;
		HX_STACK_LINE(157)
		int _g36 = (k)++;		HX_STACK_VAR(_g36,"_g36");
		HX_STACK_LINE(157)
		s[_g36] = af->start;
		HX_STACK_LINE(158)
		int _g37 = (k)++;		HX_STACK_VAR(_g37,"_g37");
		HX_STACK_LINE(158)
		s[_g37] = af->end;
		HX_STACK_LINE(159)
		int _g38 = (k)++;		HX_STACK_VAR(_g38,"_g38");
		HX_STACK_LINE(159)
		s[_g38] = af->curve;
		HX_STACK_LINE(160)
		int _g39 = (k)++;		HX_STACK_VAR(_g39,"_g39");
		HX_STACK_LINE(160)
		if ((af->random)){
			HX_STACK_LINE(160)
			s[_g39] = 1.0;
		}
		else{
			HX_STACK_LINE(160)
			s[_g39] = 0.0;
		}
		HX_STACK_LINE(162)
		af3 = r->life->motion;
		HX_STACK_LINE(163)
		int _g40 = (k)++;		HX_STACK_VAR(_g40,"_g40");
		HX_STACK_LINE(163)
		s[_g40] = af3->start->__Field(HX_CSTRING("x"),true);
		HX_STACK_LINE(164)
		int _g41 = (k)++;		HX_STACK_VAR(_g41,"_g41");
		HX_STACK_LINE(164)
		s[_g41] = af3->start->__Field(HX_CSTRING("y"),true);
		HX_STACK_LINE(165)
		int _g42 = (k)++;		HX_STACK_VAR(_g42,"_g42");
		HX_STACK_LINE(165)
		s[_g42] = af3->start->__Field(HX_CSTRING("z"),true);
		HX_STACK_LINE(166)
		int _g43 = (k)++;		HX_STACK_VAR(_g43,"_g43");
		HX_STACK_LINE(166)
		s[_g43] = af3->curve;
		HX_STACK_LINE(167)
		int _g44 = (k)++;		HX_STACK_VAR(_g44,"_g44");
		HX_STACK_LINE(167)
		s[_g44] = af3->end->__Field(HX_CSTRING("x"),true);
		HX_STACK_LINE(168)
		int _g45 = (k)++;		HX_STACK_VAR(_g45,"_g45");
		HX_STACK_LINE(168)
		s[_g45] = af3->end->__Field(HX_CSTRING("y"),true);
		HX_STACK_LINE(169)
		int _g46 = (k)++;		HX_STACK_VAR(_g46,"_g46");
		HX_STACK_LINE(169)
		s[_g46] = af3->end->__Field(HX_CSTRING("z"),true);
		HX_STACK_LINE(170)
		int _g47 = (k)++;		HX_STACK_VAR(_g47,"_g47");
		HX_STACK_LINE(170)
		if ((af3->random)){
			HX_STACK_LINE(170)
			s[_g47] = 1.0;
		}
		else{
			HX_STACK_LINE(170)
			s[_g47] = 0.0;
		}
		HX_STACK_LINE(172)
		af3 = r->life->size;
		HX_STACK_LINE(173)
		int _g48 = (k)++;		HX_STACK_VAR(_g48,"_g48");
		HX_STACK_LINE(173)
		s[_g48] = af3->start->__Field(HX_CSTRING("x"),true);
		HX_STACK_LINE(174)
		int _g49 = (k)++;		HX_STACK_VAR(_g49,"_g49");
		HX_STACK_LINE(174)
		s[_g49] = af3->start->__Field(HX_CSTRING("y"),true);
		HX_STACK_LINE(175)
		int _g50 = (k)++;		HX_STACK_VAR(_g50,"_g50");
		HX_STACK_LINE(175)
		s[_g50] = af3->start->__Field(HX_CSTRING("z"),true);
		HX_STACK_LINE(176)
		int _g51 = (k)++;		HX_STACK_VAR(_g51,"_g51");
		HX_STACK_LINE(176)
		s[_g51] = af3->curve;
		HX_STACK_LINE(177)
		int _g52 = (k)++;		HX_STACK_VAR(_g52,"_g52");
		HX_STACK_LINE(177)
		s[_g52] = af3->end->__Field(HX_CSTRING("x"),true);
		HX_STACK_LINE(178)
		int _g53 = (k)++;		HX_STACK_VAR(_g53,"_g53");
		HX_STACK_LINE(178)
		s[_g53] = af3->end->__Field(HX_CSTRING("y"),true);
		HX_STACK_LINE(179)
		int _g54 = (k)++;		HX_STACK_VAR(_g54,"_g54");
		HX_STACK_LINE(179)
		s[_g54] = af3->end->__Field(HX_CSTRING("z"),true);
		HX_STACK_LINE(180)
		int _g55 = (k)++;		HX_STACK_VAR(_g55,"_g55");
		HX_STACK_LINE(180)
		if ((af3->random)){
			HX_STACK_LINE(180)
			s[_g55] = 1.0;
		}
		else{
			HX_STACK_LINE(180)
			s[_g55] = 0.0;
		}
		HX_STACK_LINE(182)
		af3 = r->life->rotation;
		HX_STACK_LINE(183)
		int _g56 = (k)++;		HX_STACK_VAR(_g56,"_g56");
		HX_STACK_LINE(183)
		s[_g56] = af3->start->__Field(HX_CSTRING("x"),true);
		HX_STACK_LINE(184)
		int _g57 = (k)++;		HX_STACK_VAR(_g57,"_g57");
		HX_STACK_LINE(184)
		s[_g57] = af3->start->__Field(HX_CSTRING("y"),true);
		HX_STACK_LINE(185)
		int _g58 = (k)++;		HX_STACK_VAR(_g58,"_g58");
		HX_STACK_LINE(185)
		s[_g58] = af3->start->__Field(HX_CSTRING("z"),true);
		HX_STACK_LINE(186)
		int _g59 = (k)++;		HX_STACK_VAR(_g59,"_g59");
		HX_STACK_LINE(186)
		s[_g59] = af3->curve;
		HX_STACK_LINE(187)
		int _g60 = (k)++;		HX_STACK_VAR(_g60,"_g60");
		HX_STACK_LINE(187)
		s[_g60] = af3->end->__Field(HX_CSTRING("x"),true);
		HX_STACK_LINE(188)
		int _g61 = (k)++;		HX_STACK_VAR(_g61,"_g61");
		HX_STACK_LINE(188)
		s[_g61] = af3->end->__Field(HX_CSTRING("y"),true);
		HX_STACK_LINE(189)
		int _g62 = (k)++;		HX_STACK_VAR(_g62,"_g62");
		HX_STACK_LINE(189)
		s[_g62] = af3->end->__Field(HX_CSTRING("z"),true);
		HX_STACK_LINE(190)
		int _g63 = (k)++;		HX_STACK_VAR(_g63,"_g63");
		HX_STACK_LINE(190)
		if ((af3->random)){
			HX_STACK_LINE(190)
			s[_g63] = 1.0;
		}
		else{
			HX_STACK_LINE(190)
			s[_g63] = 0.0;
		}
		HX_STACK_LINE(193)
		int _g64 = (k)++;		HX_STACK_VAR(_g64,"_g64");
		HX_STACK_LINE(193)
		s[_g64] = r->force->x;
		HX_STACK_LINE(194)
		int _g65 = (k)++;		HX_STACK_VAR(_g65,"_g65");
		HX_STACK_LINE(194)
		s[_g65] = r->force->y;
		HX_STACK_LINE(195)
		int _g66 = (k)++;		HX_STACK_VAR(_g66,"_g66");
		HX_STACK_LINE(195)
		s[_g66] = r->force->z;
		HX_STACK_LINE(196)
		int _g67 = (k)++;		HX_STACK_VAR(_g67,"_g67");
		HX_STACK_LINE(196)
		s[_g67] = 0.0;
		HX_STACK_LINE(198)
		::haxor::math::Matrix4 wm = this->m_renderer->m_entity->m_transform->get_WorldMatrix();		HX_STACK_VAR(wm,"wm");
		HX_STACK_LINE(199)
		int _g68 = (k)++;		HX_STACK_VAR(_g68,"_g68");
		HX_STACK_LINE(199)
		s[_g68] = wm->m00;
		HX_STACK_LINE(199)
		int _g69 = (k)++;		HX_STACK_VAR(_g69,"_g69");
		HX_STACK_LINE(199)
		s[_g69] = wm->m01;
		HX_STACK_LINE(199)
		int _g70 = (k)++;		HX_STACK_VAR(_g70,"_g70");
		HX_STACK_LINE(199)
		s[_g70] = wm->m02;
		HX_STACK_LINE(199)
		int _g71 = (k)++;		HX_STACK_VAR(_g71,"_g71");
		HX_STACK_LINE(199)
		s[_g71] = wm->m03;
		HX_STACK_LINE(200)
		int _g72 = (k)++;		HX_STACK_VAR(_g72,"_g72");
		HX_STACK_LINE(200)
		s[_g72] = wm->m10;
		HX_STACK_LINE(200)
		int _g73 = (k)++;		HX_STACK_VAR(_g73,"_g73");
		HX_STACK_LINE(200)
		s[_g73] = wm->m11;
		HX_STACK_LINE(200)
		int _g74 = (k)++;		HX_STACK_VAR(_g74,"_g74");
		HX_STACK_LINE(200)
		s[_g74] = wm->m12;
		HX_STACK_LINE(200)
		int _g75 = (k)++;		HX_STACK_VAR(_g75,"_g75");
		HX_STACK_LINE(200)
		s[_g75] = wm->m13;
		HX_STACK_LINE(201)
		int _g76 = (k)++;		HX_STACK_VAR(_g76,"_g76");
		HX_STACK_LINE(201)
		s[_g76] = wm->m20;
		HX_STACK_LINE(201)
		int _g77 = (k)++;		HX_STACK_VAR(_g77,"_g77");
		HX_STACK_LINE(201)
		s[_g77] = wm->m21;
		HX_STACK_LINE(201)
		int _g78 = (k)++;		HX_STACK_VAR(_g78,"_g78");
		HX_STACK_LINE(201)
		s[_g78] = wm->m22;
		HX_STACK_LINE(201)
		int _g79 = (k)++;		HX_STACK_VAR(_g79,"_g79");
		HX_STACK_LINE(201)
		s[_g79] = wm->m23;
		HX_STACK_LINE(203)
		af = r->sheet->frame;
		HX_STACK_LINE(204)
		int _g80 = (k)++;		HX_STACK_VAR(_g80,"_g80");
		HX_STACK_LINE(204)
		s[_g80] = af->start;
		HX_STACK_LINE(205)
		int _g81 = (k)++;		HX_STACK_VAR(_g81,"_g81");
		HX_STACK_LINE(205)
		s[_g81] = af->end;
		HX_STACK_LINE(206)
		int _g82 = (k)++;		HX_STACK_VAR(_g82,"_g82");
		HX_STACK_LINE(206)
		s[_g82] = af->curve;
		HX_STACK_LINE(207)
		int _g83 = (k)++;		HX_STACK_VAR(_g83,"_g83");
		HX_STACK_LINE(207)
		if ((af->random)){
			HX_STACK_LINE(207)
			s[_g83] = 1.0;
		}
		else{
			HX_STACK_LINE(207)
			s[_g83] = 0.0;
		}
		HX_STACK_LINE(209)
		int _g84 = (k)++;		HX_STACK_VAR(_g84,"_g84");
		HX_STACK_LINE(209)
		s[_g84] = r->sheet->width;
		HX_STACK_LINE(210)
		int _g85 = (k)++;		HX_STACK_VAR(_g85,"_g85");
		HX_STACK_LINE(210)
		s[_g85] = r->sheet->height;
		HX_STACK_LINE(211)
		int _g86 = (k)++;		HX_STACK_VAR(_g86,"_g86");
		HX_STACK_LINE(211)
		if ((r->sheet->reverse)){
			HX_STACK_LINE(211)
			s[_g86] = -(this->m_renderer->sheet->fps);
		}
		else{
			HX_STACK_LINE(211)
			s[_g86] = this->m_renderer->sheet->fps;
		}
		HX_STACK_LINE(212)
		int _g87 = (k)++;		HX_STACK_VAR(_g87,"_g87");
		HX_STACK_LINE(212)
		if (((r->sheet->wrap == ::haxor::core::AnimationWrap_obj::Clamp))){
			HX_STACK_LINE(212)
			s[_g87] = 0.0;
		}
		else{
			HX_STACK_LINE(212)
			if (((this->m_renderer->sheet->wrap == ::haxor::core::AnimationWrap_obj::Loop))){
				HX_STACK_LINE(212)
				s[_g87] = 1.0;
			}
			else{
				HX_STACK_LINE(212)
				s[_g87] = 2.0;
			}
		}
		HX_STACK_LINE(213)
		int _g88 = (k)++;		HX_STACK_VAR(_g88,"_g88");
		HX_STACK_LINE(213)
		s[_g88] = r->sheet->length;
		HX_STACK_LINE(215)
		int _g89 = (k)++;		HX_STACK_VAR(_g89,"_g89");
		HX_STACK_LINE(215)
		s[_g89] = r->emitter->ranges->__get((int)0);
		HX_STACK_LINE(216)
		int _g90 = (k)++;		HX_STACK_VAR(_g90,"_g90");
		HX_STACK_LINE(216)
		s[_g90] = r->emitter->ranges->__get((int)1);
		HX_STACK_LINE(217)
		int _g91 = (k)++;		HX_STACK_VAR(_g91,"_g91");
		HX_STACK_LINE(217)
		s[_g91] = 0.0;
		HX_STACK_LINE(219)
		int _g92 = (k)++;		HX_STACK_VAR(_g92,"_g92");
		HX_STACK_LINE(219)
		s[_g92] = r->emitter->ranges->__get((int)2);
		HX_STACK_LINE(220)
		int _g93 = (k)++;		HX_STACK_VAR(_g93,"_g93");
		HX_STACK_LINE(220)
		s[_g93] = r->emitter->ranges->__get((int)3);
		HX_STACK_LINE(221)
		int _g94 = (k)++;		HX_STACK_VAR(_g94,"_g94");
		HX_STACK_LINE(221)
		s[_g94] = r->emitter->ranges->__get((int)4);
		HX_STACK_LINE(222)
		int _g95 = (k)++;		HX_STACK_VAR(_g95,"_g95");
		HX_STACK_LINE(222)
		s[_g95] = r->emitter->ranges->__get((int)5);
		HX_STACK_LINE(224)
		int _g96 = (k)++;		HX_STACK_VAR(_g96,"_g96");
		HX_STACK_LINE(224)
		s[_g96] = r->m_emitted_start;
		HX_STACK_LINE(225)
		int _g97 = (k)++;		HX_STACK_VAR(_g97,"_g97");
		HX_STACK_LINE(225)
		s[_g97] = r->m_emitted_count;
		HX_STACK_LINE(226)
		int _g98 = (k)++;		HX_STACK_VAR(_g98,"_g98");
		HX_STACK_LINE(226)
		s[_g98] = 0.0;
		HX_STACK_LINE(227)
		int _g99 = (k)++;		HX_STACK_VAR(_g99,"_g99");
		HX_STACK_LINE(227)
		s[_g99] = 0.0;
		HX_STACK_LINE(230)
		this->SetFloat4Array(HX_CSTRING("System"),this->m_system);
		HX_STACK_LINE(231)
		::haxor::graphics::texture::Texture _g100;		HX_STACK_VAR(_g100,"_g100");
		HX_STACK_LINE(231)
		if (((r->start->color == null()))){
			HX_STACK_LINE(231)
			_g100 = ::haxor::graphics::texture::Texture2D_obj::get_white();
		}
		else{
			HX_STACK_LINE(231)
			_g100 = r->start->color;
		}
		HX_STACK_LINE(231)
		this->SetTexture(HX_CSTRING("StartColor"),_g100);
		HX_STACK_LINE(232)
		::haxor::graphics::texture::Texture _g101;		HX_STACK_VAR(_g101,"_g101");
		HX_STACK_LINE(232)
		if (((r->life->color == null()))){
			HX_STACK_LINE(232)
			_g101 = ::haxor::graphics::texture::Texture2D_obj::get_white();
		}
		else{
			HX_STACK_LINE(232)
			_g101 = r->life->color;
		}
		HX_STACK_LINE(232)
		this->SetTexture(HX_CSTRING("Color"),_g101);
		HX_STACK_LINE(234)
		if (((r->m_material != null()))){
			HX_STACK_LINE(236)
			r->m_material->SetFloat4Array(HX_CSTRING("System"),this->m_system);
			HX_STACK_LINE(237)
			r->m_material->SetTexture(HX_CSTRING("Data"),this->m_back);
			HX_STACK_LINE(238)
			r->m_material->SetFloat(HX_CSTRING("DataWidth"),this->m_back->m_width);
			HX_STACK_LINE(239)
			r->m_material->SetFloat(HX_CSTRING("DataHeight"),this->m_back->m_height);
			HX_STACK_LINE(240)
			::haxor::graphics::texture::Texture tex;		HX_STACK_VAR(tex,"tex");
			HX_STACK_LINE(240)
			if ((r->m_material->HasUniform(HX_CSTRING("Texture"),null()))){
				HX_STACK_LINE(240)
				tex = r->m_material->GetUniform(HX_CSTRING("Texture"))->texture;
			}
			else{
				HX_STACK_LINE(240)
				tex = null();
			}
			HX_STACK_LINE(241)
			if (((tex != null()))){
				HX_STACK_LINE(243)
				r->m_material->SetFloat(HX_CSTRING("TextureWidth"),tex->m_width);
				HX_STACK_LINE(244)
				r->m_material->SetFloat(HX_CSTRING("TextureHeight"),tex->m_height);
			}
		}
		HX_STACK_LINE(248)
		this->super::Execute();
		HX_STACK_LINE(251)
		::haxor::graphics::texture::RenderTexture tmp = this->m_back;		HX_STACK_VAR(tmp,"tmp");
		HX_STACK_LINE(252)
		this->m_back = this->m_output;
		HX_STACK_LINE(253)
		this->m_output = tmp;
		HX_STACK_LINE(255)
		this->SetTexture(HX_CSTRING("Data"),this->m_back);
	}
return null();
}


int ParticleKernel_obj::DATA_SIZE;

::haxor::graphics::material::Shader ParticleKernel_obj::particle_kernel_shader;

::String ParticleKernel_obj::particle_kernel_source;


ParticleKernel_obj::ParticleKernel_obj()
{
}

void ParticleKernel_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ParticleKernel);
	HX_MARK_MEMBER_NAME(m_back,"m_back");
	HX_MARK_MEMBER_NAME(m_time,"m_time");
	HX_MARK_MEMBER_NAME(m_dt,"m_dt");
	HX_MARK_MEMBER_NAME(m_renderer,"m_renderer");
	HX_MARK_MEMBER_NAME(m_resize,"m_resize");
	HX_MARK_MEMBER_NAME(m_system,"m_system");
	::haxor::thread::Kernel_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ParticleKernel_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_back,"m_back");
	HX_VISIT_MEMBER_NAME(m_time,"m_time");
	HX_VISIT_MEMBER_NAME(m_dt,"m_dt");
	HX_VISIT_MEMBER_NAME(m_renderer,"m_renderer");
	HX_VISIT_MEMBER_NAME(m_resize,"m_resize");
	HX_VISIT_MEMBER_NAME(m_system,"m_system");
	::haxor::thread::Kernel_obj::__Visit(HX_VISIT_ARG);
}

Dynamic ParticleKernel_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_dt") ) { return m_dt; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_back") ) { return m_back; }
		if (HX_FIELD_EQ(inName,"m_time") ) { return m_time; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Execute") ) { return Execute_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_resize") ) { return m_resize; }
		if (HX_FIELD_EQ(inName,"m_system") ) { return m_system; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"DATA_SIZE") ) { return DATA_SIZE; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_renderer") ) { return m_renderer; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"particle_kernel_shader") ) { return particle_kernel_shader; }
		if (HX_FIELD_EQ(inName,"particle_kernel_source") ) { return particle_kernel_source; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ParticleKernel_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"m_dt") ) { m_dt=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_back") ) { m_back=inValue.Cast< ::haxor::graphics::texture::RenderTexture >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_time") ) { m_time=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_resize") ) { m_resize=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_system") ) { m_system=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"DATA_SIZE") ) { DATA_SIZE=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_renderer") ) { m_renderer=inValue.Cast< ::haxor::component::ParticleRenderer >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"particle_kernel_shader") ) { particle_kernel_shader=inValue.Cast< ::haxor::graphics::material::Shader >(); return inValue; }
		if (HX_FIELD_EQ(inName,"particle_kernel_source") ) { particle_kernel_source=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ParticleKernel_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_back"));
	outFields->push(HX_CSTRING("m_time"));
	outFields->push(HX_CSTRING("m_dt"));
	outFields->push(HX_CSTRING("m_renderer"));
	outFields->push(HX_CSTRING("m_resize"));
	outFields->push(HX_CSTRING("m_system"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("DATA_SIZE"),
	HX_CSTRING("particle_kernel_shader"),
	HX_CSTRING("particle_kernel_source"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::graphics::texture::RenderTexture*/ ,(int)offsetof(ParticleKernel_obj,m_back),HX_CSTRING("m_back")},
	{hx::fsFloat,(int)offsetof(ParticleKernel_obj,m_time),HX_CSTRING("m_time")},
	{hx::fsFloat,(int)offsetof(ParticleKernel_obj,m_dt),HX_CSTRING("m_dt")},
	{hx::fsObject /*::haxor::component::ParticleRenderer*/ ,(int)offsetof(ParticleKernel_obj,m_renderer),HX_CSTRING("m_renderer")},
	{hx::fsBool,(int)offsetof(ParticleKernel_obj,m_resize),HX_CSTRING("m_resize")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(ParticleKernel_obj,m_system),HX_CSTRING("m_system")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("m_back"),
	HX_CSTRING("m_time"),
	HX_CSTRING("m_dt"),
	HX_CSTRING("m_renderer"),
	HX_CSTRING("m_resize"),
	HX_CSTRING("m_system"),
	HX_CSTRING("Execute"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ParticleKernel_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(ParticleKernel_obj::DATA_SIZE,"DATA_SIZE");
	HX_MARK_MEMBER_NAME(ParticleKernel_obj::particle_kernel_shader,"particle_kernel_shader");
	HX_MARK_MEMBER_NAME(ParticleKernel_obj::particle_kernel_source,"particle_kernel_source");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ParticleKernel_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ParticleKernel_obj::DATA_SIZE,"DATA_SIZE");
	HX_VISIT_MEMBER_NAME(ParticleKernel_obj::particle_kernel_shader,"particle_kernel_shader");
	HX_VISIT_MEMBER_NAME(ParticleKernel_obj::particle_kernel_source,"particle_kernel_source");
};

#endif

Class ParticleKernel_obj::__mClass;

void ParticleKernel_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.thread.ParticleKernel"), hx::TCanCast< ParticleKernel_obj> ,sStaticFields,sMemberFields,
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

void ParticleKernel_obj::__boot()
{
	DATA_SIZE= (int)8;
	particle_kernel_source= ( HX_CSTRING("\r\n\t<shader id=\"haxor/kernel/ParticleKernel\">\t\r\n\t\t<vertex precision=\"high\">\r\n\t\tattribute vec3 vertex;\t\t\t\r\n\t\tvarying vec2 iterator;\t\t\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\r\n\t\t\tgl_Position = vec4(vertex,1.0);\r\n\t\t\titerator.x = (vertex.x+1.0)*0.5;\r\n\t\t\titerator.y = (vertex.y+1.0)*0.5;\r\n\t\t}\t\t\r\n\t\t</vertex>\r\n\t\t\r\n\t\t<fragment precision=\"high\">\r\n\t\t\r\n\t\t\t#define EmmiterType\t\t\t int(System[0].x)\r\n\t\t\t#define EmitterSize\t\t\t System[0].yzw\r\n\t\t\t\r\n\t\t\t#define IsSurfaceEmission\t (System[1].x > 0.0)\r\n\t\t\t#define IsRandomDirection\t (System[1].y > 0.0)\t\t\t\r\n\t\t\t#define IsLocal\t\t\t\t (System[1].z > 0.0)\r\n\t\t\t#define IsLoop\t\t\t\t (System[1].w > 0.0)\r\n\t\t\t\r\n\t\t\t#define SystemState\t\t\t int(System[2].x)\r\n\t\t\t#define SystemProgress\t\t System[2].y\t\t\t\r\n\t\t\t#define DeltaTime\t\t \t System[2].w\r\n\t\t\t\r\n\t\t\t#define StartSpeed\t\t\t System[3]\r\n\t\t\t#define StartSize0\t\t\t System[4]\r\n\t\t\t#define StartSize1\t\t\t System[5]\r\n\t\t\t#define StartLife\t\t\t System[6]\r\n\t\t\t#define StartRotation0\t\t System[7]\r\n\t\t\t#define StartRotation1\t\t System[8]\r\n\t\t\t\r\n\t\t\t#define LifeSpeed\t\t\t System[9]\r\n\t\t\t#define LifeMotion0\t\t\t System[10]\r\n\t\t\t#define LifeMotion1\t\t\t System[11]\r\n\t\t\t#define LifeSize0\t\t\t System[12]\r\n\t\t\t#define LifeSize1\t\t\t System[13]\r\n\t\t\t#define LifeRotation0\t\t System[14]\r\n\t\t\t#define LifeRotation1\t\t System[15]\r\n\t\t\t\r\n\t\t\t#define SystemForce\t\t\t System[16].xyz\r\n\t\t\t\r\n\t\t\t#define WorldMatrix\t\t\t mat4(System[17].xyzw, System[18].xyzw, System[19].xyzw, vec4(0,0,0,1))\r\n\t\t\t\r\n\t\t\t#define StartFrame\t\t\t System[20]\r\n\t\t\t#define SheetFrameWidth\t \t System[21].x\r\n\t\t\t#define SheetFrameHeight \t System[21].y\r\n\t\t\t#define SheetFPS\t\t \t System[21].z\r\n\t\t\t#define SheetWrap\t\t \t System[21].w\r\n\t\t\t#define SheetLength\t\t \t System[22].x\r\n\t\t\t#define EmitterRangeX\t \t System[22].yz\r\n\t\t\t#define EmitterRangeY\t \t System[23].xy\r\n\t\t\t#define EmitterRangeZ\t \t System[23].zw\r\n\t\t\t#define SystemEmissionStart\t System[24].x\r\n\t\t\t#define SystemEmissionCount\t System[24].y\r\n\t\t\t\t\t\t\r\n\t\t\t#define PARTICLE_LENGTH\t\t 7.0\r\n\t\t\t\r\n\t\t\t#define EMITTER_SPHERE\t\t 0\r\n\t\t\t#define EMITTER_BOX\t\t\t 1\r\n\t\t\t#define EMITTER_CONE\t\t 2\r\n\t\t\t#define EMITTER_CYLINDER\t 3\r\n\t\t\t\r\n\t\t\t#define PARTICLE_STATUS\t\t 0\r\n\t\t\t#define PARTICLE_POSITION\t 1\r\n\t\t\t#define PARTICLE_ROTATION\t 2\r\n\t\t\t#define PARTICLE_SIZE\t\t 3\r\n\t\t\t#define PARTICLE_VELOCITY\t 4\r\n\t\t\t#define PARTICLE_COLOR\t\t 5\r\n\t\t\t#define PARTICLE_START\t\t 6\r\n\t\t\t\r\n\t\t\t#define STATE_NONE\t\t 0\r\n\t\t\t#define STATE_RESET\t\t 1\r\n\t\t\t#define STATE_UPDATE\t 2\r\n\t\t\t\r\n\t\t\t#define PARTICLE_DISABLED\t 0\r\n\t\t\t#define PARTICLE_INIT\t\t 1\r\n\t\t\t#define PARTICLE_ENABLED\t 2\r\n\t\t\t#define PARTICLE_DEAD\t\t 3\r\n\t\t\t\r\n\t\t\tfloat particle_id;\t\t\t\r\n\t\t\tfloat particle_field;\r\n\t\t\tfloat fragment_id;\r\n\t\t\t\r\n\t\t\tvarying vec2 \t\titerator;\t\t\t\r\n\t\t\tuniform sampler2D \tData;\t\t\t\r\n\t\t\tuniform sampler2D \tStartColor;\t\t\t\r\n\t\t\tuniform sampler2D \tColor;\t\t\t\r\n\t\t\tuniform float \t\twidth;\t\t\t\r\n\t\t\tuniform float \t\theight;\t\t\t\r\n\t\t\tuniform vec4  \t\tSystem[25];\t\t\t\r\n\t\t\tuniform float \t\tRandomSeed;\t\t\r\n\t\t\tuniform sampler2D \tRandomTexture;\r\n\t\t\t\r\n\t\t\t\r\n\t\t\tvec4 Random()\r\n\t\t\t{\r\n\t\t\t\tfloat tw   = 0.001953125;\r\n\t\t\t\tfloat seed = RandomSeed * 262144.0;\r\n\t\t\t\tfloat idx  = mod(seed+fragment_id,512.0) * tw;\r\n\t\t\t\tfloat idy  = floor((seed+fragment_id) * tw)  * tw;\r\n\t\t\t\tvec2  ruv  = vec2(idx,idy);\r\n\t\t\t\tseed      += tw * fract(sin(dot(ruv ,vec2(12.9898,78.233))) * 43758.5453);\r\n\t\t\t\treturn texture2D(RandomTexture, ruv);\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tvec3 RandomVector() { return (Random().xyz - 0.5)*2.0; }\r\n\t\t\t\r\n\t\t\tfloat Lerp(float a, float b,float r) { return a + ((b-a)*r); }\r\n\t\t\tvec2  Lerp(vec2  a, vec2  b,float r) { return a + ((b-a)*r); }\r\n\t\t\tvec3  Lerp(vec3  a, vec3  b,float r) { return a + ((b-a)*r); }\r\n\t\t\tvec4  Lerp(vec4  a, vec4  b,float r) { return a + ((b-a)*r); }\r\n\t\t\t\r\n\t\t\tvec3 GetSphereRandomPosition(bool p_surface,float p_radius)\t\r\n\t\t\t{\t\r\n\t\t\t\tfloat r   = (p_radius*0.5);\r\n\t\t\t\tvec3 v    = RandomVector();\t\t\t\t\t\t\t\t\r\n\t\t\t\treturn p_surface ? (normalize(v) * r) : (v * r); \r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tvec3 GetBoxRandomPosition(bool p_surface,vec3 p_size)\r\n\t\t\t{\t\t\t\t\r\n\t\t\t\tvec3 hs  = p_size*0.5;\r\n\t\t\t\tif(p_surface)\r\n\t\t\t\t{\r\n\t\t\t\t\tvec3 p = GetSphereRandomPosition(true,length(p_size));\r\n\t\t\t\t\tp.x = clamp(p.x,-hs.x,hs.x);\r\n\t\t\t\t\tp.y = clamp(p.y,-hs.y,hs.y);\r\n\t\t\t\t\tp.z = clamp(p.z,-hs.z,hs.z);\r\n\t\t\t\t\treturn p;\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\tvec3 rnd = Random().xyz;\r\n\t\t\t\treturn vec3( Lerp(-hs.x,hs.x,rnd.x), Lerp(-hs.y,hs.y,rnd.y), Lerp(-hs.z,hs.z,rnd.z));\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tvec3 GetEmitterRandomPosition()\r\n\t\t\t{\r\n\t\t\t\tint id \t\t\t= EmmiterType;\r\n\t\t\t\tbool is_surface = IsSurfaceEmission;\r\n\t\t\t\t\r\n\t\t\t\tif(id == EMITTER_SPHERE) return GetSphereRandomPosition(is_surface,EmitterSize.x);\r\n\t\t\t\tif(id == EMITTER_BOX) \t return GetBoxRandomPosition(is_surface,EmitterSize);\r\n\t\t\t\treturn GetSphereRandomPosition(is_surface,EmitterSize.x);\r\n\t\t\t}\r\n\t\t\t\t\t\t\r\n\t\t\tvec3 SampleParticleAttribVec3(vec4 p_start,vec4 p_end,float p_random)\r\n\t\t\t{\r\n\t\t\t\tfloat c  = p_start.w;\r\n\t\t\t\tfloat rf = p_end.w;\t\t\t\t\r\n\t\t\t\tvec3 a   = p_start.xyz;\r\n\t\t\t\tvec3 b   = p_end.xyz;\r\n\t\t\t\treturn (rf > 0.0) ? Lerp(a,b,p_random) : Lerp(a,b,pow(SystemProgress,c));\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tfloat SampleParticleAttribFloat(vec4 p_attribute,float p_random)\r\n\t\t\t{\r\n\t\t\t\tvec4 a   = p_attribute;\t\t\t\t\r\n\t\t\t\treturn (a.w > 0.0) ? Lerp(a.x,a.y,p_random) : Lerp(a.x,a.y,pow(SystemProgress,a.z));\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tvec4 ParticleData(float p_id,int p_field)\r\n\t\t\t{\r\n\t\t\t\tfloat pix = floor(p_id) * PARTICLE_LENGTH;\r\n\t\t\t\tfloat f   = float(p_field);\r\n\t\t\t\tfloat w   = floor(width);\r\n\t\t\t\tfloat h   = floor(height);\r\n\t\t\t\tfloat px  = mod(pix+f,w) / (w-1.0);\r\n\t\t\t\tfloat py  = floor((pix+f)/w) / (h-1.0);\r\n\t\t\t\treturn texture2D(Data,vec2(px,py));\r\n\t\t\t}\r\n\t\t\r\n\t\t\tvec4 ParticleStatus()   \t{ return ParticleData(particle_id,PARTICLE_STATUS); \t}\r\n\t\t\tvec4 ParticlePosition() \t{ return ParticleData(particle_id,PARTICLE_POSITION); \t}\r\n\t\t\tvec4 ParticleRotation() \t{ return ParticleData(particle_id,PARTICLE_ROTATION); \t}\r\n\t\t\tvec4 ParticleSize() \t\t{ return ParticleData(particle_id,PARTICLE_SIZE); \t\t}\r\n\t\t\tvec4 ParticleVelocity()\t\t{ return ParticleData(particle_id,PARTICLE_VELOCITY);\t}\r\n\t\t\tvec4 ParticleColor() \t\t{ return ParticleData(particle_id,PARTICLE_COLOR); \t\t}\r\n\t\t\tvec4 ParticleStart() \t\t{ return ParticleData(particle_id,PARTICLE_START); \t\t}\r\n\t\t\r\n\t\t\t\r\n\t\t\tvec4 UpdateStatus(int p_state,vec4 p_current)\r\n\t\t\t{\r\n\t\t\t\t//[state][life][duration][frame]\r\n\t\t\t\tvec4 p   = p_current;\r\n\t\t\t\t\r\n\t\t\t\tif(int(p.x) == PARTICLE_DISABLED)\r\n\t\t\t\t{\r\n\t\t\t\t\tvec4 rnd = Random();\r\n\t\t\t\t\tp.x = 1.0;\r\n\t\t\t\t\tp.y = 0.0;\r\n\t\t\t\t\tp.z = SampleParticleAttribFloat(StartLife,rnd.x);\r\n\t\t\t\t\tp.w = SampleParticleAttribFloat(StartFrame,rnd.y);\r\n\t\t\t\t\treturn p;\r\n\t\t\t\t}\r\n\t\t\t\t\r\n\t\t\t\tif(int(p.x) == PARTICLE_INIT)\r\n\t\t\t\t{\r\n\t\t\t\t\tp.x = 2.0;\r\n\t\t\t\t}\r\n\t\t\t\t\r\n\t\t\t\tif(int(p.x) == PARTICLE_ENABLED)\r\n\t\t\t\t{\t\t\t\t\t\t\r\n\t\t\t\t\tif(p.y >= p.z)\r\n\t\t\t\t\t{\r\n\t\t\t\t\t\tp.y = p.z;\r\n\t\t\t\t\t\tp.x = 3.0;\r\n\t\t\t\t\t\treturn p;\r\n\t\t\t\t\t}\r\n\t\t\t\t\tp.y += DeltaTime;\t\t\t\t\t\r\n\t\t\t\t\tp.w += SheetFPS * DeltaTime;\r\n\t\t\t\t\tif(p.w >= SheetLength)\r\n\t\t\t\t\t{\r\n\t\t\t\t\t\tp.w = SheetLength;\t\t\t\t\t\t\r\n\t\t\t\t\t\tif(int(SheetWrap)==1) p.w=0.0;\t\t\t\t\t\t\r\n\t\t\t\t\t}\r\n\t\t\t\t\treturn p;\r\n\t\t\t\t}\r\n\t\t\t\t\r\n\t\t\t\treturn p;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tvec4 UpdatePosition(int p_state,vec4 p_status,vec4 p_current)\r\n\t\t\t{\r\n\t\t\t\tvec4 p   = p_status;\r\n\t\t\t\tvec4 c   = p_current;\r\n\t\t\t\t\r\n\t\t\t\tif(int(p.x) == PARTICLE_DISABLED)\r\n\t\t\t\t{\r\n\t\t\t\t\tc.xyz = GetEmitterRandomPosition();\r\n\t\t\t\t\tif(!IsLocal) { c.w=1.0; c = c * WorldMatrix; }\r\n\t\t\t\t}\r\n\t\t\t\t\r\n\t\t\t\tif(int(p.x) == PARTICLE_ENABLED)\r\n\t\t\t\t{\r\n\t\t\t\t\tfloat r = p.z <= 0.0 ? 0.0 : (p.y/p.z);\r\n\t\t\t\t\tvec3  v = ParticleVelocity().xyz * Lerp(LifeMotion0.xyz,LifeMotion1.xyz,r);\t\t\t\t\t\r\n\t\t\t\t\tfloat speed =  Lerp(StartSpeed.x,StartSpeed.y,ParticleStart().x) * Lerp(LifeSpeed.x,LifeSpeed.y,r);\t\t\t\t\t\r\n\t\t\t\t\tc.xyz")+ HX_CSTRING(" += v * speed * DeltaTime;\r\n\t\t\t\t}\r\n\t\t\t\t\r\n\t\t\t\treturn c;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\t\r\n\t\t\tvec4 UpdateVelocity(int p_state,vec4 p_status,vec4 p_current)\r\n\t\t\t{\r\n\t\t\t\tvec4 p   \t\t= p_status;\t\t\t\t\r\n\t\t\t\tvec4 c   \t\t= p_current;\r\n\t\t\t\t\r\n\t\t\t\tif(int(p.x) == PARTICLE_INIT)\r\n\t\t\t\t{\r\n\t\t\t\t\tvec4 rnd;\r\n\t\t\t\t\tc.xyz  = IsRandomDirection ? normalize((Random().xyz-0.5)*2.0) : normalize(ParticlePosition().xyz);\t\t\t\t\t\r\n\t\t\t\t\tc.x = clamp(c.x,EmitterRangeX.x,EmitterRangeX.y);\r\n\t\t\t\t\tc.y = clamp(c.y,EmitterRangeY.x,EmitterRangeY.y);\r\n\t\t\t\t\tc.z = clamp(c.z,EmitterRangeZ.x,EmitterRangeZ.y);\r\n\t\t\t\t\tc = normalize(c);\r\n\t\t\t\t}\r\n\t\t\t\t\r\n\t\t\t\tif(int(p.x) == PARTICLE_ENABLED)\r\n\t\t\t\t{\r\n\t\t\t\t\tc.xyz += SystemForce * DeltaTime;\t\t\t\t\t\r\n\t\t\t\t}\r\n\t\t\t\t\r\n\t\t\t\treturn c;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tvec4 UpdateRotation(int p_state,vec4 p_status,vec4 p_current)\r\n\t\t\t{\r\n\t\t\t\tvec4 p   = p_status;\r\n\t\t\t\tvec4 c   = p_current;\r\n\t\t\t\tc = vec4(0,0,0,0);\r\n\t\t\t\treturn c;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tvec4 UpdateSize(int p_state,vec4 p_status,vec4 p_current)\r\n\t\t\t{\r\n\t\t\t\tvec4 p   = p_status;\r\n\t\t\t\tvec4 c   = p_current;\r\n\t\t\t\t\r\n\t\t\t\tif(int(p.x) == PARTICLE_DISABLED)\r\n\t\t\t\t{\r\n\t\t\t\t\tfloat r = p.z <= 0.0 ? 0.0 : (p.y/p.z);\r\n\t\t\t\t\tc.xyz = Lerp(StartSize0.xyz,StartSize1.xyz,ParticleStart().y) * Lerp(LifeSize0.xyz,LifeSize1.xyz,r);\r\n\t\t\t\t}\r\n\t\t\t\t\r\n\t\t\t\tif(int(p.x) == PARTICLE_ENABLED)\r\n\t\t\t\t{\r\n\t\t\t\t\tfloat r = p.z <= 0.0 ? 0.0 : (p.y/p.z);\r\n\t\t\t\t\tc.xyz = Lerp(StartSize0.xyz,StartSize1.xyz,ParticleStart().y) * Lerp(LifeSize0.xyz,LifeSize1.xyz,r);\r\n\t\t\t\t}\r\n\t\t\t\t\r\n\t\t\t\treturn c;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\t\r\n\t\t\tvec4 UpdateColor(int p_state,vec4 p_status,vec4 p_current)\r\n\t\t\t{\r\n\t\t\t\tvec4 p   = p_status;\r\n\t\t\t\tvec4 c   = p_current;\r\n\t\t\t\t\r\n\t\t\t\tif(int(p.x) == PARTICLE_DISABLED)\r\n\t\t\t\t{\r\n\t\t\t\t\tvec4 c0 = texture2D(StartColor,vec2(ParticleStart().z,0.0));\r\n\t\t\t\t\tfloat r = p.z <= 0.0 ? 0.0 : (p.y/p.z);\r\n\t\t\t\t\tvec4 c1 = texture2D(Color,vec2(r,0.0));\r\n\t\t\t\t\tc = c0 * c1;\r\n\t\t\t\t}\r\n\t\t\t\t\r\n\t\t\t\tif(int(p.x) == PARTICLE_ENABLED)\r\n\t\t\t\t{\r\n\t\t\t\t\tvec4 c0 = texture2D(StartColor,vec2(ParticleStart().z,0.0));\r\n\t\t\t\t\tfloat r = p.z <= 0.0 ? 0.0 : (p.y/p.z);\r\n\t\t\t\t\tvec4 c1 = texture2D(Color,vec2(r,0.0));\r\n\t\t\t\t\tc = c0 * c1;\r\n\t\t\t\t}\r\n\t\t\t\t\r\n\t\t\t\treturn c;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tvec4 UpdateStart(int p_state,vec4 p_status,vec4 p_current)\r\n\t\t\t{\r\n\t\t\t\tvec4 p   \t\t= p_status;\t\t\t\t\r\n\t\t\t\tvec4 c   \t\t= p_current;\r\n\t\t\t\t\r\n\t\t\t\tif(int(p.x) == PARTICLE_DISABLED)\r\n\t\t\t\t{\r\n\t\t\t\t\tvec4 rnd = Random();\r\n\t\t\t\t\tc.x = StartSpeed.w > 0.0 ? rnd.x : SystemProgress;\r\n\t\t\t\t\tc.y = StartSize1.w > 0.0 ? rnd.y : SystemProgress;\r\n\t\t\t\t\tc.z = SystemProgress;\r\n\t\t\t\t\tc.w = StartRotation1.w > 0.0 ? rnd.w : SystemProgress;\r\n\t\t\t\t}\r\n\t\t\t\t\t\t\t\t\r\n\t\t\t\treturn c;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\tuniform float Time;\r\n\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\t\r\n\t\t\t\tfloat count\t\t = floor(SystemEmissionCount);\r\n\t\t\t\t//if(count <= 0.0) { gl_FragColor = vec4(1,1,0,1); return; }\r\n\t\t\t\tfloat ix\t     = iterator.x;\r\n\t\t\t\tfloat iy\t     = iterator.y;\t\t\r\n\t\t\t\tfloat iw         = 1.0 / width;\t\t\t\t\r\n\t\t\t\tfloat ih         = 1.0 / height;\t\t\t\t\r\n\t\t\t\t//float hiw        = iw*0.5;\t\t\t\t\r\n\t\t\t\t//float hih        = ih*0.5;\t\t\t\t\r\n\t\t\t\t//ix = (ix - hiw) / (1.0 - iw);\r\n\t\t\t\t//iy = (iy - hih) / (1.0 - ih);\r\n\t\t\t\t\r\n\t\t\t\tfloat size       = width * height;\r\n\t\t\t\tfloat max_count  = floor((width * height)/PARTICLE_LENGTH);\r\n\t\t\t\tfloat px         = floor(ix*(width));\r\n\t\t\t\tfloat py         = floor(iy*(height));\r\n\t\t\t\tfloat pix\t     = (px + (py * width));\r\n\t\t\t\tfloat id\t\t = ((pix / (PARTICLE_LENGTH)));\r\n\t\t\t\tfloat field\t\t = mod(pix,PARTICLE_LENGTH);\r\n\t\t\t\t\r\n\t\t\t\tparticle_id = id;\r\n\t\t\t\tfragment_id = pix;\r\n\t\t\t\t\r\n\t\t\t\tfloat ck = floor(mod(pix, 2.0)) <= 0.0 ? 0.8 : 1.0;\t\t\t\t\r\n\t\t\t\tck = field/PARTICLE_LENGTH;\r\n\t\t\t\tvec4 mc = vec4(ck, ck, ck, 1.0);\t\r\n\t\t\t\t\r\n\t\t\t\t//gl_FragColor = mc;\r\n\t\t\t\t//return;\r\n\t\t\t\t\r\n\t\t\t\tfloat emin \t\t = floor(mod(SystemEmissionStart,max_count));\r\n\t\t\t\tfloat emax \t\t = floor(mod(SystemEmissionStart+count-1.0,max_count));\r\n\t\t\t\t\r\n\t\t\t\tif (int(id) == 1) { gl_FragColor = vec4(0, 1, 0, 1); return; }\r\n\t\t\t\tgl_FragColor = vec4(1, 0, 0, 1); return;\r\n\t\t\t\t\r\n\t\t\t\tfloat dv = 1.0 / 7.0;\t\t\t\t\r\n\t\t\t\t\r\n\t\t\t\tvec4 c0 = vec4(1.0, 0.0, 0.0, 1.0)*mc;\r\n\t\t\t\tvec4 c1 = vec4(1.0, 1.0, 0.0, 1.0)*mc;\r\n\t\t\t\tvec4 c2 = vec4(0.0, 1.0, 0.0, 1.0)*mc;\r\n\t\t\t\tvec4 c3 = vec4(0.0, 1.0, 1.0, 1.0)*mc;\r\n\t\t\t\tvec4 c4 = vec4(0.0, 0.0, 1.0, 1.0)*mc;\r\n\t\t\t\tvec4 c5 = vec4(1.0, 0.0, 1.0, 1.0)*mc;\r\n\t\t\t\tvec4 c6 = vec4(1.0, 1.0, 1.0, 1.0)*mc;\r\n\t\t\t\tvec4 c7 = vec4(0.8, 0.8, 0.8, 1.0)*mc;\r\n\t\t\t\tvec4 c8 = vec4(0.6, 0.6, 0.6, 1.0)*mc;\r\n\t\t\t\tvec4 c9 = vec4(0.4, 0.4, 0.4, 1.0)*mc;\r\n\t\t\t\t\r\n\t\t\t\tif(int(id)==0) { gl_FragColor = c0; return; }\r\n\t\t\t\tif(int(id)==1) { gl_FragColor = c1; return; }\r\n\t\t\t\tif(int(id)==2) { gl_FragColor = c2; return; }\r\n\t\t\t\tif(int(id)==3) { gl_FragColor = c3; return; }\r\n\t\t\t\tif(int(id)==4) { gl_FragColor = c4; return; }\r\n\t\t\t\tif(int(id)==5) { gl_FragColor = c5; return; }\r\n\t\t\t\tif(int(id)==6) { gl_FragColor = c6; return; }\r\n\t\t\t\tif(int(id)==7) { gl_FragColor = c7; return; }\r\n\t\t\t\tif(int(id)==8) { gl_FragColor = c8; return; }\r\n\t\t\t\tif(int(id)==9) { gl_FragColor = c9; return; }\r\n\t\t\t\t\r\n\t\t\t\tgl_FragColor = vec4(0.0, 1.0, 1.0, 1.0);\r\n\t\t\t\treturn;\r\n\t\t\t\t\r\n\t\t\t\tfloat b = (field / PARTICLE_LENGTH) + 0.2;\r\n\t\t\t\tc0.xyz *= b;\r\n\t\t\t\tc1.xyz *= b;\r\n\t\t\t\tc2.xyz *= b;\r\n\t\t\t\tc3.xyz *= b;\r\n\t\t\t\tc4.xyz *= b;\r\n\t\t\t\tc5.xyz *= b;\r\n\t\t\t\tc6.xyz *= b;\r\n\t\t\t\t\r\n\t\t\t\tfield = id;\r\n\t\t\t\t\r\n\t\t\t\t//*/\r\n\t\t\t\t/*\r\n\t\t\t\tvec4 c0 = vec4(1.0,0.0,0.0, 1.0);        \r\n\t\t\t\tvec4 c1 = vec4(dv*1.0, 1.0, dv*1.0, 1.0);\r\n\t\t\t\tvec4 c2 = vec4(dv*2.0, 0.0, dv*2.0, 1.0);\r\n\t\t\t\tvec4 c3 = vec4(dv*3.0, 0.0, dv*3.0, 1.0);\r\n\t\t\t\tvec4 c4 = vec4(dv*4.0, 0.0, dv*4.0, 1.0);\r\n\t\t\t\tvec4 c5 = vec4(dv*5.0, 0.0, dv*5.0, 1.0);\r\n\t\t\t\tvec4 c6 = vec4(1.0, 0.0, 1.0, 1.0);      \r\n\t\t\t\t//*/\r\n\t\t\t\t\r\n\t\t\t\tif(int(field)==0) { gl_FragColor = c0; return; }\r\n\t\t\t\tif(int(field)==1) { gl_FragColor = c1; return; }\r\n\t\t\t\tif(int(field)==2) { gl_FragColor = c2; return; }\r\n\t\t\t\tif(int(field)==3) { gl_FragColor = c3; return; }\r\n\t\t\t\tif(int(field)==4) { gl_FragColor = c4; return; }\r\n\t\t\t\tif(int(field)==5) { gl_FragColor = c5; return; }\r\n\t\t\t\tif(int(field)==6) { gl_FragColor = c6; return; }\r\n\t\t\t\t\r\n\t\t\t\tgl_FragColor = vec4(0.0, 1.0, 1.0, 1.0);\r\n\t\t\t\treturn;\r\n\t\t\t\t//*/\r\n\t\t\t\t\r\n\t\t\t\tif(emin > emax)\r\n\t\t\t\t{\r\n\t\t\t\t\tif(id < emin) \r\n\t\t\t\t\tif(id > emax) { gl_FragColor = vec4(1.0,0.0,0.0,1.0); return; }\r\n\t\t\t\t}\r\n\t\t\t\telse\r\n\t\t\t\t{\t\t\t\t\r\n\t\t\t\t\tif(id < emin) { gl_FragColor = vec4(0.0,1.0,0.0,1.0); return; }\r\n\t\t\t\t\tif(id > emax) { gl_FragColor = vec4(0.0,0.0,1.0,1.0); return; }\r\n\t\t\t\t}\r\n\t\t\t\t\r\n\t\t\t\t\r\n\t\t\t\t\r\n\t\t\t\t\r\n\t\t\t\t//gl_FragColor = vec4(1.0,1.0,0.0,1.0);\t\t\t\treturn;\r\n\t\t\t\t//if(id >= SystemEmission) { gl_FragColor = vec4(0.0,0.0,0.0,1.0); return; }\r\n\t\t\t\t\r\n\t\t\t\tint   state\t\t = SystemState;\r\n\t\t\t\t\r\n\t\t\t\tvec4  status\t = ParticleStatus();\r\n\t\t\t\tvec4  data\t\t = texture2D(Data,iterator);\r\n\t\t\t\t\r\n\t\t\t\tgl_FragColor \t = data;\r\n\t\t\t\t\r\n\t\t\t\tif(state == STATE_NONE) return;\r\n\t\t\t\t\r\n\t\t\t\tint field_id        = int(field);\r\n\t\t\t\t\r\n\t\t\t\tif(field_id == PARTICLE_STATUS) \t{ gl_FragColor = UpdateStatus(state,data);\t\t\t   \treturn; }\r\n\t\t\t\tif(field_id == PARTICLE_POSITION) \t{ gl_FragColor = UpdatePosition(state,status,data); \treturn; }\t\t\t\t\r\n\t\t\t\tif(field_id == PARTICLE_ROTATION) \t{ gl_FragColor = UpdateRotation(state,status,data); \treturn; }\t\t\t\t\r\n\t\t\t\tif(field_id == PARTICLE_SIZE)\t \t{ gl_FragColor = UpdateSize(state,status,data); \t \treturn; }\t\t\t\t\r\n\t\t\t\tif(field_id == PARTICLE_VELOCITY)\t{ gl_FragColor = UpdateVelocity(state,status,data); \treturn; }\r\n\t\t\t\tif(field_id == PARTICLE_COLOR)\t\t{ gl_FragColor = UpdateColor(state,status,data); \t \treturn; }\r\n\t\t\t\tif(field_id == PARTICLE_START)\t\t{ gl_FragColor = UpdateStart(state,status,data); \t \treturn; }\r\n\t\t\t\t\r\n\t\t\t}\r\n\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\r\n\t"));
}

} // end namespace haxor
} // end namespace thread
