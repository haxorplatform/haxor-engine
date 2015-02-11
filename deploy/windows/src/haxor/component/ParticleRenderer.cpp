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
#ifndef INCLUDED_haxor_component_SphereEmitter
#include <haxor/component/SphereEmitter.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#include <haxor/graphics/mesh/Mesh.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh3
#include <haxor/graphics/mesh/Mesh3.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshLayout
#include <haxor/graphics/mesh/MeshLayout.h>
#endif
#ifndef INCLUDED_haxor_math_AABB3
#include <haxor/math/AABB3.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace haxor{
namespace component{

Void ParticleRenderer_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.component.ParticleRenderer","new",0x3e7e1f38,"haxor.component.ParticleRenderer.new","haxor/component/ParticleRenderer.hx",107,0x91e29536)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(107)
	super::__construct(p_name);
}
;
	return null();
}

//ParticleRenderer_obj::~ParticleRenderer_obj() { }

Dynamic ParticleRenderer_obj::__CreateEmpty() { return  new ParticleRenderer_obj; }
hx::ObjectPtr< ParticleRenderer_obj > ParticleRenderer_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< ParticleRenderer_obj > result = new ParticleRenderer_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic ParticleRenderer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< ParticleRenderer_obj > result = new ParticleRenderer_obj();
	result->__construct(inArgs[0]);
	return result;}

hx::Object *ParticleRenderer_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::haxor::core::IUpdateable_obj)) return operator ::haxor::core::IUpdateable_obj *();
	return super::__ToInterface(inType);
}

Float ParticleRenderer_obj::get_emitted( ){
	HX_STACK_FRAME("haxor.component.ParticleRenderer","get_emitted",0x46c97c4f,"haxor.component.ParticleRenderer.get_emitted","haxor/component/ParticleRenderer.hx",114,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(114)
	return this->m_emitted_count;
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleRenderer_obj,get_emitted,return )

bool ParticleRenderer_obj::get_playing( ){
	HX_STACK_FRAME("haxor.component.ParticleRenderer","get_playing",0x11eb565d,"haxor.component.ParticleRenderer.get_playing","haxor/component/ParticleRenderer.hx",122,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(122)
	return this->m_playing;
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleRenderer_obj,get_playing,return )

::haxor::math::AABB3 ParticleRenderer_obj::get_bounds( ){
	HX_STACK_FRAME("haxor.component.ParticleRenderer","get_bounds",0x3310b266,"haxor.component.ParticleRenderer.get_bounds","haxor/component/ParticleRenderer.hx",129,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(129)
	return this->m_mesh->get_bounds();
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleRenderer_obj,get_bounds,return )

::haxor::math::AABB3 ParticleRenderer_obj::set_bounds( ::haxor::math::AABB3 v){
	HX_STACK_FRAME("haxor.component.ParticleRenderer","set_bounds",0x368e50da,"haxor.component.ParticleRenderer.set_bounds","haxor/component/ParticleRenderer.hx",130,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(130)
	this->m_mesh->set_bounds(v);
	HX_STACK_LINE(130)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(ParticleRenderer_obj,set_bounds,return )

int ParticleRenderer_obj::get_count( ){
	HX_STACK_FRAME("haxor.component.ParticleRenderer","get_count",0x6801a1fe,"haxor.component.ParticleRenderer.get_count","haxor/component/ParticleRenderer.hx",138,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_LINE(138)
	return this->m_count;
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleRenderer_obj,get_count,return )

int ParticleRenderer_obj::set_count( int v){
	HX_STACK_FRAME("haxor.component.ParticleRenderer","set_count",0x4b528e0a,"haxor.component.ParticleRenderer.set_count","haxor/component/ParticleRenderer.hx",139,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(139)
	this->m_count = v;
	HX_STACK_LINE(139)
	this->Reset();
	HX_STACK_LINE(139)
	this->UpdateMesh();
	HX_STACK_LINE(139)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(ParticleRenderer_obj,set_count,return )

Void ParticleRenderer_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.component.ParticleRenderer","OnBuild",0x59703c47,"haxor.component.ParticleRenderer.OnBuild","haxor/component/ParticleRenderer.hx",202,0x91e29536)
		HX_STACK_THIS(this)
		HX_STACK_LINE(203)
		this->super::OnBuild();
		HX_STACK_LINE(205)
		this->m_state = ::haxor::component::ParticleSystemState_obj::Reset;
		HX_STACK_LINE(206)
		::haxor::thread::ParticleKernel _g = ::haxor::thread::ParticleKernel_obj::__new(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(206)
		this->m_kernel = _g;
		HX_STACK_LINE(207)
		this->elapsed = 0.0;
		HX_STACK_LINE(208)
		this->m_playing = false;
		HX_STACK_LINE(209)
		this->m_emitted_count = 0.0;
		HX_STACK_LINE(210)
		this->m_emitted_start = 0.0;
		HX_STACK_LINE(212)
		this->set_count((int)10);
		HX_STACK_LINE(214)
		this->duration = 1.0;
		HX_STACK_LINE(216)
		::haxor::component::SphereEmitter _g1 = ::haxor::component::SphereEmitter_obj::__new(1.0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(216)
		this->emitter = _g1;
		HX_STACK_LINE(218)
		::haxor::component::ParticleSheet _g2 = ::haxor::component::ParticleSheet_obj::__new();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(218)
		this->sheet = _g2;
		HX_STACK_LINE(220)
		this->local = true;
		HX_STACK_LINE(221)
		this->loop = true;
		HX_STACK_LINE(222)
		this->billboard = true;
		HX_STACK_LINE(224)
		::haxor::component::ParticleStart _g3 = ::haxor::component::ParticleStart_obj::__new();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(224)
		this->start = _g3;
		HX_STACK_LINE(225)
		::haxor::component::ParticleLife _g4 = ::haxor::component::ParticleLife_obj::__new();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(225)
		this->life = _g4;
		HX_STACK_LINE(227)
		::haxor::component::ParticleAttribute _g5 = ::haxor::component::ParticleAttribute_obj::__new(1.0,1.0,null(),null());		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(227)
		this->rate = _g5;
		HX_STACK_LINE(229)
		::haxor::math::Vector3 _g6 = ::haxor::math::Vector3_obj::__new(null(),null(),null());		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(229)
		this->force = _g6;
	}
return null();
}


Void ParticleRenderer_obj::Emit( hx::Null< Float >  __o_p_emit_count){
Float p_emit_count = __o_p_emit_count.Default(1.0);
	HX_STACK_FRAME("haxor.component.ParticleRenderer","Emit",0x54c9789b,"haxor.component.ParticleRenderer.Emit","haxor/component/ParticleRenderer.hx",237,0x91e29536)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_emit_count,"p_emit_count")
{
		HX_STACK_LINE(238)
		int _g = this->get_count();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(238)
		Float _g1 = this->get_emitted();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(238)
		Float remain = (_g - _g1);		HX_STACK_VAR(remain,"remain");
		HX_STACK_LINE(239)
		Float c = ::Math_obj::min(p_emit_count,remain);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(240)
		Float d = (p_emit_count - c);		HX_STACK_VAR(d,"d");
		HX_STACK_LINE(241)
		if ((this->loop)){
			HX_STACK_LINE(241)
			hx::AddEq(this->m_emitted_start,d);
		}
		HX_STACK_LINE(242)
		hx::AddEq(this->m_emitted_count,c);
		HX_STACK_LINE(243)
		this->m_playing = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(ParticleRenderer_obj,Emit,(void))

Void ParticleRenderer_obj::Play( ){
{
		HX_STACK_FRAME("haxor.component.ParticleRenderer","Play",0x5c0e083c,"haxor.component.ParticleRenderer.Play","haxor/component/ParticleRenderer.hx",251,0x91e29536)
		HX_STACK_THIS(this)
		HX_STACK_LINE(251)
		this->m_playing = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleRenderer_obj,Play,(void))

Void ParticleRenderer_obj::Pause( ){
{
		HX_STACK_FRAME("haxor.component.ParticleRenderer","Pause",0x2902fbae,"haxor.component.ParticleRenderer.Pause","haxor/component/ParticleRenderer.hx",259,0x91e29536)
		HX_STACK_THIS(this)
		HX_STACK_LINE(259)
		this->m_playing = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleRenderer_obj,Pause,(void))

Void ParticleRenderer_obj::Reset( ){
{
		HX_STACK_FRAME("haxor.component.ParticleRenderer","Reset",0x52736e87,"haxor.component.ParticleRenderer.Reset","haxor/component/ParticleRenderer.hx",266,0x91e29536)
		HX_STACK_THIS(this)
		HX_STACK_LINE(268)
		this->elapsed = 0.0;
		HX_STACK_LINE(269)
		this->m_emitted_count = 0.0;
		HX_STACK_LINE(270)
		this->m_emitted_start = 0.0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleRenderer_obj,Reset,(void))

Void ParticleRenderer_obj::Stop( ){
{
		HX_STACK_FRAME("haxor.component.ParticleRenderer","Stop",0x5e0fca4a,"haxor.component.ParticleRenderer.Stop","haxor/component/ParticleRenderer.hx",274,0x91e29536)
		HX_STACK_THIS(this)
		HX_STACK_LINE(275)
		this->elapsed = 0.0;
		HX_STACK_LINE(276)
		this->m_emitted_count = 0.0;
		HX_STACK_LINE(277)
		this->m_emitted_start = 0.0;
		HX_STACK_LINE(278)
		this->m_state = ::haxor::component::ParticleSystemState_obj::Reset;
		HX_STACK_LINE(279)
		this->m_playing = false;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleRenderer_obj,Stop,(void))

Void ParticleRenderer_obj::Simulate( ){
{
		HX_STACK_FRAME("haxor.component.ParticleRenderer","Simulate",0x30eed5ec,"haxor.component.ParticleRenderer.Simulate","haxor/component/ParticleRenderer.hx",284,0x91e29536)
		HX_STACK_THIS(this)
		HX_STACK_LINE(284)
		::haxor::component::ParticleSystemState _g = this->m_state;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(284)
		switch( (int)(_g->__Index())){
			case (int)0: {
				HX_STACK_LINE(288)
				if ((this->m_playing)){
					HX_STACK_LINE(288)
					this->m_state = ::haxor::component::ParticleSystemState_obj::Update;
				}
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(293)
				if ((this->m_playing)){
					HX_STACK_LINE(293)
					this->m_state = ::haxor::component::ParticleSystemState_obj::Update;
				}
				else{
					HX_STACK_LINE(293)
					this->m_state = ::haxor::component::ParticleSystemState_obj::None;
				}
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(297)
				if ((!(this->m_playing))){
					HX_STACK_LINE(297)
					this->m_state = ::haxor::component::ParticleSystemState_obj::None;
					HX_STACK_LINE(297)
					return null();
				}
				HX_STACK_LINE(301)
				Float max_life = ::Math_obj::max(this->start->life->start,this->start->life->end);		HX_STACK_VAR(max_life,"max_life");
				HX_STACK_LINE(302)
				if (((this->elapsed >= (this->duration + max_life)))){
					HX_STACK_LINE(302)
					if ((!(this->loop))){
						HX_STACK_LINE(302)
						return null();
					}
				}
				HX_STACK_LINE(303)
				Float dt = ::haxor::core::Time_obj::m_delta;		HX_STACK_VAR(dt,"dt");
				HX_STACK_LINE(304)
				Float r;		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(304)
				{
					HX_STACK_LINE(304)
					Float p_v;		HX_STACK_VAR(p_v,"p_v");
					HX_STACK_LINE(304)
					if (((this->duration <= 0.0))){
						HX_STACK_LINE(304)
						p_v = 0.0;
					}
					else{
						HX_STACK_LINE(304)
						p_v = (Float(this->elapsed) / Float(this->duration));
					}
					HX_STACK_LINE(304)
					if (((p_v <= 0.0))){
						HX_STACK_LINE(304)
						r = 0.0;
					}
					else{
						HX_STACK_LINE(304)
						if (((p_v >= 1.0))){
							HX_STACK_LINE(304)
							r = 1.0;
						}
						else{
							HX_STACK_LINE(304)
							r = p_v;
						}
					}
				}
				HX_STACK_LINE(307)
				hx::AddEq(this->elapsed,dt);
				HX_STACK_LINE(308)
				if (((this->elapsed >= (this->duration + max_life)))){
					HX_STACK_LINE(308)
					this->elapsed = (this->duration + max_life);
				}
				HX_STACK_LINE(310)
				Float _g1;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(310)
				{
					HX_STACK_LINE(310)
					Float p_a = this->rate->start;		HX_STACK_VAR(p_a,"p_a");
					HX_STACK_LINE(310)
					Float p_ratio;		HX_STACK_VAR(p_ratio,"p_ratio");
					HX_STACK_LINE(310)
					if ((this->rate->random)){
						HX_STACK_LINE(310)
						p_ratio = ::Math_obj::random();
					}
					else{
						HX_STACK_LINE(310)
						p_ratio = ::Math_obj::pow(r,this->rate->curve);
					}
					HX_STACK_LINE(310)
					_g1 = (p_a + (((this->rate->end - p_a)) * p_ratio));
				}
				HX_STACK_LINE(310)
				Float er = (dt * _g1);		HX_STACK_VAR(er,"er");
				HX_STACK_LINE(311)
				this->Emit(er);
			}
			;break;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleRenderer_obj,Simulate,(void))

Void ParticleRenderer_obj::OnUpdate( ){
{
		HX_STACK_FRAME("haxor.component.ParticleRenderer","OnUpdate",0x9d351ad0,"haxor.component.ParticleRenderer.OnUpdate","haxor/component/ParticleRenderer.hx",333,0x91e29536)
		HX_STACK_THIS(this)
		HX_STACK_LINE(333)
		this->Simulate();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleRenderer_obj,OnUpdate,(void))

Void ParticleRenderer_obj::UpdateMesh( ){
{
		HX_STACK_FRAME("haxor.component.ParticleRenderer","UpdateMesh",0xd42af4de,"haxor.component.ParticleRenderer.UpdateMesh","haxor/component/ParticleRenderer.hx",338,0x91e29536)
		HX_STACK_THIS(this)
		HX_STACK_LINE(339)
		if (((this->m_particles != null()))){
			HX_STACK_LINE(339)
			::haxor::core::Resource_obj::Destroy(this->m_particles);
		}
		HX_STACK_LINE(340)
		::haxor::graphics::mesh::Mesh3 _g = ::haxor::graphics::mesh::Mesh3_obj::__new(null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(340)
		this->m_particles = _g;
		HX_STACK_LINE(341)
		int _g1 = this->get_uid();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(341)
		::String _g2 = (HX_CSTRING("ParticleMesh") + _g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(341)
		this->m_particles->set_name(_g2);
		HX_STACK_LINE(342)
		::haxor::math::AABB3 _g3 = ::haxor::math::AABB3_obj::FromCenter((int)0,(int)0,(int)0,(int)1,(int)1,(int)1,null());		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(342)
		this->m_particles->set_bounds(_g3);
		HX_STACK_LINE(344)
		this->set_mesh(this->m_particles);
		HX_STACK_LINE(346)
		Array< ::Dynamic > vl = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(vl,"vl");
		HX_STACK_LINE(348)
		Float s = 0.5;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(351)
		::haxor::math::Vector3 _g4 = ::haxor::math::Vector3_obj::__new(-(s),s,(int)0);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(352)
		::haxor::math::Vector3 _g5 = ::haxor::math::Vector3_obj::__new(-(s),-(s),(int)0);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(353)
		::haxor::math::Vector3 _g6 = ::haxor::math::Vector3_obj::__new(s,-(s),(int)0);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(354)
		::haxor::math::Vector3 _g7 = ::haxor::math::Vector3_obj::__new(-(s),s,(int)0);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(355)
		::haxor::math::Vector3 _g8 = ::haxor::math::Vector3_obj::__new(s,-(s),(int)0);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(356)
		::haxor::math::Vector3 _g9 = ::haxor::math::Vector3_obj::__new(s,s,(int)0);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(350)
		Array< ::Dynamic > plane = Array_obj< ::Dynamic >::__new().Add(_g4).Add(_g5).Add(_g6).Add(_g7).Add(_g8).Add(_g9);		HX_STACK_VAR(plane,"plane");
		HX_STACK_LINE(362)
		{
			HX_STACK_LINE(362)
			int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(362)
			int _g10 = this->get_count();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(362)
			while((true)){
				HX_STACK_LINE(362)
				if ((!(((_g11 < _g10))))){
					HX_STACK_LINE(362)
					break;
				}
				HX_STACK_LINE(362)
				int i = (_g11)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(364)
				{
					HX_STACK_LINE(364)
					int _g31 = (int)0;		HX_STACK_VAR(_g31,"_g31");
					HX_STACK_LINE(364)
					int _g21 = plane->length;		HX_STACK_VAR(_g21,"_g21");
					HX_STACK_LINE(364)
					while((true)){
						HX_STACK_LINE(364)
						if ((!(((_g31 < _g21))))){
							HX_STACK_LINE(364)
							break;
						}
						HX_STACK_LINE(364)
						int j = (_g31)++;		HX_STACK_VAR(j,"j");
						HX_STACK_LINE(366)
						::haxor::math::Vector3 v;		HX_STACK_VAR(v,"v");
						HX_STACK_LINE(366)
						{
							HX_STACK_LINE(366)
							::haxor::math::Vector3 _this = plane->__get(j).StaticCast< ::haxor::math::Vector3 >();		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(366)
							v = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
						}
						HX_STACK_LINE(367)
						v->z = i;
						HX_STACK_LINE(368)
						vl->push(v);
					}
				}
			}
		}
		HX_STACK_LINE(373)
		this->m_particles->set_vertex(vl);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(ParticleRenderer_obj,UpdateMesh,(void))


ParticleRenderer_obj::ParticleRenderer_obj()
{
}

void ParticleRenderer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(ParticleRenderer);
	HX_MARK_MEMBER_NAME(m_emitted_start,"m_emitted_start");
	HX_MARK_MEMBER_NAME(m_emitted_count,"m_emitted_count");
	HX_MARK_MEMBER_NAME(m_playing,"m_playing");
	HX_MARK_MEMBER_NAME(m_count,"m_count");
	HX_MARK_MEMBER_NAME(elapsed,"elapsed");
	HX_MARK_MEMBER_NAME(duration,"duration");
	HX_MARK_MEMBER_NAME(billboard,"billboard");
	HX_MARK_MEMBER_NAME(local,"local");
	HX_MARK_MEMBER_NAME(loop,"loop");
	HX_MARK_MEMBER_NAME(emitter,"emitter");
	HX_MARK_MEMBER_NAME(start,"start");
	HX_MARK_MEMBER_NAME(life,"life");
	HX_MARK_MEMBER_NAME(sheet,"sheet");
	HX_MARK_MEMBER_NAME(rate,"rate");
	HX_MARK_MEMBER_NAME(force,"force");
	HX_MARK_MEMBER_NAME(m_particles,"m_particles");
	HX_MARK_MEMBER_NAME(m_state,"m_state");
	HX_MARK_MEMBER_NAME(m_kernel,"m_kernel");
	::haxor::component::MeshRenderer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void ParticleRenderer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_emitted_start,"m_emitted_start");
	HX_VISIT_MEMBER_NAME(m_emitted_count,"m_emitted_count");
	HX_VISIT_MEMBER_NAME(m_playing,"m_playing");
	HX_VISIT_MEMBER_NAME(m_count,"m_count");
	HX_VISIT_MEMBER_NAME(elapsed,"elapsed");
	HX_VISIT_MEMBER_NAME(duration,"duration");
	HX_VISIT_MEMBER_NAME(billboard,"billboard");
	HX_VISIT_MEMBER_NAME(local,"local");
	HX_VISIT_MEMBER_NAME(loop,"loop");
	HX_VISIT_MEMBER_NAME(emitter,"emitter");
	HX_VISIT_MEMBER_NAME(start,"start");
	HX_VISIT_MEMBER_NAME(life,"life");
	HX_VISIT_MEMBER_NAME(sheet,"sheet");
	HX_VISIT_MEMBER_NAME(rate,"rate");
	HX_VISIT_MEMBER_NAME(force,"force");
	HX_VISIT_MEMBER_NAME(m_particles,"m_particles");
	HX_VISIT_MEMBER_NAME(m_state,"m_state");
	HX_VISIT_MEMBER_NAME(m_kernel,"m_kernel");
	::haxor::component::MeshRenderer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic ParticleRenderer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"loop") ) { return loop; }
		if (HX_FIELD_EQ(inName,"life") ) { return life; }
		if (HX_FIELD_EQ(inName,"rate") ) { return rate; }
		if (HX_FIELD_EQ(inName,"Emit") ) { return Emit_dyn(); }
		if (HX_FIELD_EQ(inName,"Play") ) { return Play_dyn(); }
		if (HX_FIELD_EQ(inName,"Stop") ) { return Stop_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"count") ) { return get_count(); }
		if (HX_FIELD_EQ(inName,"local") ) { return local; }
		if (HX_FIELD_EQ(inName,"start") ) { return start; }
		if (HX_FIELD_EQ(inName,"sheet") ) { return sheet; }
		if (HX_FIELD_EQ(inName,"force") ) { return force; }
		if (HX_FIELD_EQ(inName,"Pause") ) { return Pause_dyn(); }
		if (HX_FIELD_EQ(inName,"Reset") ) { return Reset_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bounds") ) { return get_bounds(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"emitted") ) { return get_emitted(); }
		if (HX_FIELD_EQ(inName,"playing") ) { return get_playing(); }
		if (HX_FIELD_EQ(inName,"m_count") ) { return m_count; }
		if (HX_FIELD_EQ(inName,"elapsed") ) { return elapsed; }
		if (HX_FIELD_EQ(inName,"emitter") ) { return emitter; }
		if (HX_FIELD_EQ(inName,"m_state") ) { return m_state; }
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { return duration; }
		if (HX_FIELD_EQ(inName,"m_kernel") ) { return m_kernel; }
		if (HX_FIELD_EQ(inName,"Simulate") ) { return Simulate_dyn(); }
		if (HX_FIELD_EQ(inName,"OnUpdate") ) { return OnUpdate_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_playing") ) { return m_playing; }
		if (HX_FIELD_EQ(inName,"get_count") ) { return get_count_dyn(); }
		if (HX_FIELD_EQ(inName,"set_count") ) { return set_count_dyn(); }
		if (HX_FIELD_EQ(inName,"billboard") ) { return billboard; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_bounds") ) { return get_bounds_dyn(); }
		if (HX_FIELD_EQ(inName,"set_bounds") ) { return set_bounds_dyn(); }
		if (HX_FIELD_EQ(inName,"UpdateMesh") ) { return UpdateMesh_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"get_emitted") ) { return get_emitted_dyn(); }
		if (HX_FIELD_EQ(inName,"get_playing") ) { return get_playing_dyn(); }
		if (HX_FIELD_EQ(inName,"m_particles") ) { return m_particles; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_emitted_start") ) { return m_emitted_start; }
		if (HX_FIELD_EQ(inName,"m_emitted_count") ) { return m_emitted_count; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic ParticleRenderer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"loop") ) { loop=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"life") ) { life=inValue.Cast< ::haxor::component::ParticleLife >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rate") ) { rate=inValue.Cast< ::haxor::component::ParticleAttribute >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"count") ) { return set_count(inValue); }
		if (HX_FIELD_EQ(inName,"local") ) { local=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"start") ) { start=inValue.Cast< ::haxor::component::ParticleStart >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sheet") ) { sheet=inValue.Cast< ::haxor::component::ParticleSheet >(); return inValue; }
		if (HX_FIELD_EQ(inName,"force") ) { force=inValue.Cast< ::haxor::math::Vector3 >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"bounds") ) { return set_bounds(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"m_count") ) { m_count=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"elapsed") ) { elapsed=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"emitter") ) { emitter=inValue.Cast< ::haxor::component::ParticleEmitter >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_state") ) { m_state=inValue.Cast< ::haxor::component::ParticleSystemState >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"duration") ) { duration=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_kernel") ) { m_kernel=inValue.Cast< ::haxor::thread::ParticleKernel >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"m_playing") ) { m_playing=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"billboard") ) { billboard=inValue.Cast< bool >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"m_particles") ) { m_particles=inValue.Cast< ::haxor::graphics::mesh::Mesh3 >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"m_emitted_start") ) { m_emitted_start=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_emitted_count") ) { m_emitted_count=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void ParticleRenderer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("emitted"));
	outFields->push(HX_CSTRING("m_emitted_start"));
	outFields->push(HX_CSTRING("m_emitted_count"));
	outFields->push(HX_CSTRING("playing"));
	outFields->push(HX_CSTRING("m_playing"));
	outFields->push(HX_CSTRING("bounds"));
	outFields->push(HX_CSTRING("count"));
	outFields->push(HX_CSTRING("m_count"));
	outFields->push(HX_CSTRING("elapsed"));
	outFields->push(HX_CSTRING("duration"));
	outFields->push(HX_CSTRING("billboard"));
	outFields->push(HX_CSTRING("local"));
	outFields->push(HX_CSTRING("loop"));
	outFields->push(HX_CSTRING("emitter"));
	outFields->push(HX_CSTRING("start"));
	outFields->push(HX_CSTRING("life"));
	outFields->push(HX_CSTRING("sheet"));
	outFields->push(HX_CSTRING("rate"));
	outFields->push(HX_CSTRING("force"));
	outFields->push(HX_CSTRING("m_particles"));
	outFields->push(HX_CSTRING("m_state"));
	outFields->push(HX_CSTRING("m_kernel"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(ParticleRenderer_obj,m_emitted_start),HX_CSTRING("m_emitted_start")},
	{hx::fsFloat,(int)offsetof(ParticleRenderer_obj,m_emitted_count),HX_CSTRING("m_emitted_count")},
	{hx::fsBool,(int)offsetof(ParticleRenderer_obj,m_playing),HX_CSTRING("m_playing")},
	{hx::fsInt,(int)offsetof(ParticleRenderer_obj,m_count),HX_CSTRING("m_count")},
	{hx::fsFloat,(int)offsetof(ParticleRenderer_obj,elapsed),HX_CSTRING("elapsed")},
	{hx::fsFloat,(int)offsetof(ParticleRenderer_obj,duration),HX_CSTRING("duration")},
	{hx::fsBool,(int)offsetof(ParticleRenderer_obj,billboard),HX_CSTRING("billboard")},
	{hx::fsBool,(int)offsetof(ParticleRenderer_obj,local),HX_CSTRING("local")},
	{hx::fsBool,(int)offsetof(ParticleRenderer_obj,loop),HX_CSTRING("loop")},
	{hx::fsObject /*::haxor::component::ParticleEmitter*/ ,(int)offsetof(ParticleRenderer_obj,emitter),HX_CSTRING("emitter")},
	{hx::fsObject /*::haxor::component::ParticleStart*/ ,(int)offsetof(ParticleRenderer_obj,start),HX_CSTRING("start")},
	{hx::fsObject /*::haxor::component::ParticleLife*/ ,(int)offsetof(ParticleRenderer_obj,life),HX_CSTRING("life")},
	{hx::fsObject /*::haxor::component::ParticleSheet*/ ,(int)offsetof(ParticleRenderer_obj,sheet),HX_CSTRING("sheet")},
	{hx::fsObject /*::haxor::component::ParticleAttribute*/ ,(int)offsetof(ParticleRenderer_obj,rate),HX_CSTRING("rate")},
	{hx::fsObject /*::haxor::math::Vector3*/ ,(int)offsetof(ParticleRenderer_obj,force),HX_CSTRING("force")},
	{hx::fsObject /*::haxor::graphics::mesh::Mesh3*/ ,(int)offsetof(ParticleRenderer_obj,m_particles),HX_CSTRING("m_particles")},
	{hx::fsObject /*::haxor::component::ParticleSystemState*/ ,(int)offsetof(ParticleRenderer_obj,m_state),HX_CSTRING("m_state")},
	{hx::fsObject /*::haxor::thread::ParticleKernel*/ ,(int)offsetof(ParticleRenderer_obj,m_kernel),HX_CSTRING("m_kernel")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_emitted"),
	HX_CSTRING("m_emitted_start"),
	HX_CSTRING("m_emitted_count"),
	HX_CSTRING("get_playing"),
	HX_CSTRING("m_playing"),
	HX_CSTRING("get_bounds"),
	HX_CSTRING("set_bounds"),
	HX_CSTRING("get_count"),
	HX_CSTRING("set_count"),
	HX_CSTRING("m_count"),
	HX_CSTRING("elapsed"),
	HX_CSTRING("duration"),
	HX_CSTRING("billboard"),
	HX_CSTRING("local"),
	HX_CSTRING("loop"),
	HX_CSTRING("emitter"),
	HX_CSTRING("start"),
	HX_CSTRING("life"),
	HX_CSTRING("sheet"),
	HX_CSTRING("rate"),
	HX_CSTRING("force"),
	HX_CSTRING("m_particles"),
	HX_CSTRING("m_state"),
	HX_CSTRING("m_kernel"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("Emit"),
	HX_CSTRING("Play"),
	HX_CSTRING("Pause"),
	HX_CSTRING("Reset"),
	HX_CSTRING("Stop"),
	HX_CSTRING("Simulate"),
	HX_CSTRING("OnUpdate"),
	HX_CSTRING("UpdateMesh"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ParticleRenderer_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ParticleRenderer_obj::__mClass,"__mClass");
};

#endif

Class ParticleRenderer_obj::__mClass;

void ParticleRenderer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.component.ParticleRenderer"), hx::TCanCast< ParticleRenderer_obj> ,sStaticFields,sMemberFields,
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

void ParticleRenderer_obj::__boot()
{
}

} // end namespace haxor
} // end namespace component
