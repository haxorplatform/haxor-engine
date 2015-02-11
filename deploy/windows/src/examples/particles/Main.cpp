#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_examples_particles_Main
#include <examples/particles/Main.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Camera
#include <haxor/component/Camera.h>
#endif
#ifndef INCLUDED_haxor_component_CameraOrbit
#include <haxor/component/CameraOrbit.h>
#endif
#ifndef INCLUDED_haxor_component_CameraOrbitInput
#include <haxor/component/CameraOrbitInput.h>
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
#ifndef INCLUDED_haxor_component_ParticleStart
#include <haxor/component/ParticleStart.h>
#endif
#ifndef INCLUDED_haxor_component_Renderer
#include <haxor/component/Renderer.h>
#endif
#ifndef INCLUDED_haxor_component_SphereEmitter
#include <haxor/component/SphereEmitter.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_context_DataContext
#include <haxor/context/DataContext.h>
#endif
#ifndef INCLUDED_haxor_context_EngineContext
#include <haxor/context/EngineContext.h>
#endif
#ifndef INCLUDED_haxor_context_GizmoContext
#include <haxor/context/GizmoContext.h>
#endif
#ifndef INCLUDED_haxor_context_ShaderContext
#include <haxor/context/ShaderContext.h>
#endif
#ifndef INCLUDED_haxor_core_Application
#include <haxor/core/Application.h>
#endif
#ifndef INCLUDED_haxor_core_ApplicationProtocol
#include <haxor/core/ApplicationProtocol.h>
#endif
#ifndef INCLUDED_haxor_core_Asset
#include <haxor/core/Asset.h>
#endif
#ifndef INCLUDED_haxor_core_BaseApplication
#include <haxor/core/BaseApplication.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_haxor_core_Debug
#include <haxor/core/Debug.h>
#endif
#ifndef INCLUDED_haxor_core_Entity
#include <haxor/core/Entity.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IRenderable
#include <haxor/core/IRenderable.h>
#endif
#ifndef INCLUDED_haxor_core_IResizeable
#include <haxor/core/IResizeable.h>
#endif
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
#endif
#ifndef INCLUDED_haxor_core_PixelFormat
#include <haxor/core/PixelFormat.h>
#endif
#ifndef INCLUDED_haxor_core_RenderStats
#include <haxor/core/RenderStats.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
#endif
#ifndef INCLUDED_haxor_graphics_Graphics
#include <haxor/graphics/Graphics.h>
#endif
#ifndef INCLUDED_haxor_graphics_Screen
#include <haxor/graphics/Screen.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Material
#include <haxor/graphics/material/Material.h>
#endif
#ifndef INCLUDED_haxor_graphics_material_Shader
#include <haxor/graphics/material/Shader.h>
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
#ifndef INCLUDED_haxor_input_Input
#include <haxor/input/Input.h>
#endif
#ifndef INCLUDED_haxor_input_KeyCode
#include <haxor/input/KeyCode.h>
#endif
#ifndef INCLUDED_haxor_input_Touch
#include <haxor/input/Touch.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_net_Web
#include <haxor/net/Web.h>
#endif
#ifndef INCLUDED_haxor_platform_OSWindow
#include <haxor/platform/OSWindow.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_Entry
#include <haxor/platform/windows/Entry.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_WinApplication
#include <haxor/platform/windows/WinApplication.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_Window
#include <haxor/platform/windows/Window.h>
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
namespace examples{
namespace particles{

Void Main_obj::__construct()
{
HX_STACK_FRAME("examples.particles.Main","new",0xcaf4df31,"examples.particles.Main.new","examples/particles/Main.hx",93,0x269d325d)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(93)
	super::__construct();
}
;
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

hx::Object *Main_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::haxor::core::IUpdateable_obj)) return operator ::haxor::core::IUpdateable_obj *();
	if (inType==typeid( ::haxor::core::IRenderable_obj)) return operator ::haxor::core::IRenderable_obj *();
	return super::__ToInterface(inType);
}

Void Main_obj::LoadDebug( ){
{
		HX_STACK_FRAME("examples.particles.Main","LoadDebug",0xad0effbe,"examples.particles.Main.LoadDebug","examples/particles/Main.hx",120,0x269d325d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(129)
		this->debug = false;
		HX_STACK_LINE(131)
		this->CreateParticle();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,LoadDebug,(void))

Void Main_obj::Initialize( ){
{
		HX_STACK_FRAME("examples.particles.Main","Initialize",0x935812bf,"examples.particles.Main.Initialize","examples/particles/Main.hx",138,0x269d325d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(139)
		::haxor::core::Console_obj::Log(HX_CSTRING("Initialize!"),null());
		HX_STACK_LINE(140)
		this->LoadDebug();
		HX_STACK_LINE(141)
		this->m_entity->set_enabled(true);
		HX_STACK_LINE(142)
		this->angle = (int)0;
	}
return null();
}


Void Main_obj::OnStart( ){
{
		HX_STACK_FRAME("examples.particles.Main","OnStart",0x099985f4,"examples.particles.Main.OnStart","examples/particles/Main.hx",146,0x269d325d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(147)
		this->m_entity->set_enabled(false);
		HX_STACK_LINE(149)
		::haxor::component::CameraOrbit _g = ::haxor::component::CameraOrbit_obj::Create((int)10,(int)45,(int)45);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(149)
		this->orbit = _g;
		HX_STACK_LINE(150)
		::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(150)
		this->orbit->m_entity->m_transform->set_localPosition(_g1);
		HX_STACK_LINE(151)
		this->orbit->smooth = (int)5;
		HX_STACK_LINE(152)
		::haxor::math::Color _g2 = ::haxor::math::Color_obj::__new(0.25,0.25,0.25,(int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(152)
		this->orbit->get_camera()->background = _g2;
		HX_STACK_LINE(153)
		{
			HX_STACK_LINE(153)
			::haxor::component::Camera _this = this->orbit->get_camera();		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(153)
			_this->m_near = 0.1;
			HX_STACK_LINE(153)
			_this->m_projection_dirty = true;
			HX_STACK_LINE(153)
			_this->m_proj_uniform_dirty = true;
			HX_STACK_LINE(153)
			0.1;
		}
		HX_STACK_LINE(154)
		{
			HX_STACK_LINE(154)
			::haxor::component::Camera _this = this->orbit->get_camera();		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(154)
			_this->m_far = (int)500;
			HX_STACK_LINE(154)
			_this->m_projection_dirty = true;
			HX_STACK_LINE(154)
			_this->m_proj_uniform_dirty = true;
			HX_STACK_LINE(154)
			(int)500;
		}
		HX_STACK_LINE(155)
		{
			HX_STACK_LINE(155)
			::haxor::component::Camera _this = this->orbit->get_camera();		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(155)
			_this->m_fov = (int)40;
			HX_STACK_LINE(155)
			_this->m_projection_dirty = true;
			HX_STACK_LINE(155)
			(int)40;
		}
		HX_STACK_LINE(157)
		::haxor::component::CameraOrbitInput orbit_input = this->orbit->m_entity->AddComponent(hx::ClassOf< ::haxor::component::CameraOrbitInput >());		HX_STACK_VAR(orbit_input,"orbit_input");
		HX_STACK_LINE(158)
		orbit_input->zoomSpeed = 0.2;
	}
return null();
}


Void Main_obj::CreateParticle( ){
{
		HX_STACK_FRAME("examples.particles.Main","CreateParticle",0xf5678251,"examples.particles.Main.CreateParticle","examples/particles/Main.hx",164,0x269d325d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(166)
		Dynamic _g = ::haxor::core::Entity_obj::__new(HX_CSTRING("emitter"))->AddComponent(hx::ClassOf< ::haxor::component::ParticleRenderer >());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(166)
		this->particle = _g;
		HX_STACK_LINE(169)
		::haxor::component::SphereEmitter _g1 = ::haxor::component::SphereEmitter_obj::__new(1.0);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(169)
		::haxor::component::SphereEmitter sphere_emitter = this->particle->emitter = _g1;		HX_STACK_VAR(sphere_emitter,"sphere_emitter");
		HX_STACK_LINE(172)
		sphere_emitter->set_random(false);
		HX_STACK_LINE(175)
		sphere_emitter->set_surface(false);
		HX_STACK_LINE(179)
		sphere_emitter->ranges = Array_obj< Float >::__new().Add((int)-1000).Add((int)1000).Add((int)-1000).Add((int)1000).Add((int)-1000).Add((int)1000);
		HX_STACK_LINE(182)
		this->particle->set_count((int)5);
		HX_STACK_LINE(185)
		Float _g2 = this->particle->rate->end = (int)0;		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(185)
		this->particle->rate->start = _g2;
		HX_STACK_LINE(188)
		::haxor::math::Vector3 _g3 = ::haxor::math::Vector3_obj::__new(0.1,0.1,0.1);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(188)
		this->particle->life->size->start = _g3;
		HX_STACK_LINE(189)
		::haxor::math::Vector3 _g4 = ::haxor::math::Vector3_obj::__new(3.0,3.0,3.0);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(189)
		this->particle->life->size->end = _g4;
		HX_STACK_LINE(190)
		this->particle->life->size->curve = 2.0;
		HX_STACK_LINE(194)
		this->particle->local = false;
		HX_STACK_LINE(197)
		this->particle->loop = true;
		HX_STACK_LINE(200)
		this->particle->billboard = true;
		HX_STACK_LINE(203)
		this->particle->start->life->start = 5.0;
		HX_STACK_LINE(204)
		this->particle->start->life->end = 5.0;
		HX_STACK_LINE(205)
		this->particle->start->life->random = true;
		HX_STACK_LINE(208)
		this->particle->start->speed->start = 0.1;
		HX_STACK_LINE(209)
		this->particle->start->speed->end = 0.1;
		HX_STACK_LINE(210)
		this->particle->start->speed->curve = 0.5;
		HX_STACK_LINE(213)
		::haxor::math::Vector3 _g5 = ::haxor::math::Vector3_obj::__new((int)0,0.0,(int)0);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(213)
		this->particle->force = _g5;
		HX_STACK_LINE(216)
		::haxor::graphics::texture::Texture2D color_fade = ::haxor::graphics::texture::Texture2D_obj::__new((int)4,(int)1,::haxor::core::PixelFormat_obj::RGBA8);		HX_STACK_VAR(color_fade,"color_fade");
		HX_STACK_LINE(219)
		::haxor::math::Color _g6 = ::haxor::math::Color_obj::__new((int)1,(int)1,(int)1,(int)1);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(219)
		::haxor::math::Color _g7 = ::haxor::math::Color_obj::__new((int)1,(int)1,(int)0,(int)1);		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(219)
		::haxor::math::Color _g8 = ::haxor::math::Color_obj::__new(1.0,(int)0,(int)0,(int)1);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(219)
		::haxor::math::Color _g9 = ::haxor::math::Color_obj::__new((int)0,(int)0,(int)0,(int)0);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(219)
		Array< ::Dynamic > _g10 = Array_obj< ::Dynamic >::__new().Add(_g6).Add(_g7).Add(_g8).Add(_g9);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(219)
		color_fade->m_data->SetPixels(_g10,null(),null(),null(),null());
		HX_STACK_LINE(222)
		color_fade->Apply();
		HX_STACK_LINE(225)
		this->particle->life->color = color_fade;
		HX_STACK_LINE(229)
		this->particle->Play();
		HX_STACK_LINE(231)
		::haxor::graphics::texture::Texture tex = ::haxor::core::Asset_obj::Get(HX_CSTRING("particle"));		HX_STACK_VAR(tex,"tex");
		HX_STACK_LINE(232)
		tex->set_name(HX_CSTRING("particle"));
		HX_STACK_LINE(234)
		::haxor::graphics::material::Material mat = ::haxor::graphics::material::Material_obj::__new(null());		HX_STACK_VAR(mat,"mat");
		HX_STACK_LINE(235)
		mat->set_name(HX_CSTRING("ParticleAdditive"));
		HX_STACK_LINE(236)
		::haxor::graphics::material::Shader _g12;		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(236)
		if (((::haxor::graphics::material::Shader_obj::m_flat_particle_shader == null()))){
			HX_STACK_LINE(236)
			::haxor::graphics::material::Shader _g11 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_particle_source);		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(236)
			_g12 = ::haxor::graphics::material::Shader_obj::m_flat_particle_shader = _g11;
		}
		else{
			HX_STACK_LINE(236)
			_g12 = ::haxor::graphics::material::Shader_obj::m_flat_particle_shader;
		}
		HX_STACK_LINE(236)
		mat->set_shader(_g12);
		HX_STACK_LINE(237)
		mat->SetTexture(HX_CSTRING("Texture"),tex);
		HX_STACK_LINE(238)
		mat->SetBlending((int)770,(int)1);
		HX_STACK_LINE(239)
		mat->blend = true;
		HX_STACK_LINE(240)
		mat->zwrite = false;
		HX_STACK_LINE(241)
		mat->cull = (int)0;
		HX_STACK_LINE(243)
		this->particle->set_material(mat);
		HX_STACK_LINE(246)
		::haxor::core::Debug_obj::transform = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,CreateParticle,(void))

Void Main_obj::OnUpdate( ){
{
		HX_STACK_FRAME("examples.particles.Main","OnUpdate",0xddc6d437,"examples.particles.Main.OnUpdate","examples/particles/Main.hx",250,0x269d325d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(253)
		::String log = HX_CSTRING("");		HX_STACK_VAR(log,"log");
		HX_STACK_LINE(254)
		hx::AddEq(log,HX_CSTRING("Stats"));
		HX_STACK_LINE(255)
		::String _g = ::Std_obj::string(::haxor::component::Camera_obj::SAPCulling);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(255)
		::String _g1 = (HX_CSTRING("\nSAP: ") + _g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(255)
		hx::AddEq(log,_g1);
		HX_STACK_LINE(256)
		hx::AddEq(log,(HX_CSTRING("\nVisible: ") + ::haxor::core::RenderStats_obj::visible));
		HX_STACK_LINE(257)
		hx::AddEq(log,(HX_CSTRING("\nCulled: ") + ::haxor::core::RenderStats_obj::culled));
		HX_STACK_LINE(258)
		int _g2 = ::haxor::core::RenderStats_obj::get_total();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(258)
		::String _g3 = (HX_CSTRING("\nActive: ") + _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(258)
		hx::AddEq(log,_g3);
		HX_STACK_LINE(259)
		hx::AddEq(log,(HX_CSTRING("\nRenderers: ") + ::haxor::core::RenderStats_obj::renderers));
		HX_STACK_LINE(260)
		hx::AddEq(log,(HX_CSTRING("\nTris: ") + ::haxor::core::RenderStats_obj::triangles));
		HX_STACK_LINE(262)
		if ((::haxor::input::Input_obj::Down(::haxor::input::KeyCode_obj::Q))){
			HX_STACK_LINE(262)
			::haxor::component::Camera_obj::SAPCulling = !(::haxor::component::Camera_obj::SAPCulling);
		}
		HX_STACK_LINE(263)
		if ((::haxor::input::Input_obj::Down(::haxor::input::KeyCode_obj::D2))){
			HX_STACK_LINE(263)
			::haxor::core::Debug_obj::transform = !(::haxor::core::Debug_obj::transform);
		}
		HX_STACK_LINE(264)
		if ((::haxor::input::Input_obj::Down(::haxor::input::KeyCode_obj::D3))){
			HX_STACK_LINE(264)
			::haxor::core::Debug_obj::collider = !(::haxor::core::Debug_obj::collider);
		}
		HX_STACK_LINE(265)
		if ((::haxor::input::Input_obj::Down(::haxor::input::KeyCode_obj::D4))){
			HX_STACK_LINE(265)
			::haxor::core::Debug_obj::light = !(::haxor::core::Debug_obj::light);
		}
		HX_STACK_LINE(266)
		if ((::haxor::input::Input_obj::Down(::haxor::input::KeyCode_obj::D5))){
			HX_STACK_LINE(266)
			::haxor::core::Debug_obj::renderer = !(::haxor::core::Debug_obj::renderer);
		}
		HX_STACK_LINE(284)
		::haxor::math::Vector3 p = this->orbit->get_pivot()->get_localPosition();		HX_STACK_VAR(p,"p");
		HX_STACK_LINE(285)
		::haxor::math::Vector3 vz = this->orbit->get_pivot()->get_forward();		HX_STACK_VAR(vz,"vz");
		HX_STACK_LINE(286)
		::haxor::math::Vector3 vx = this->orbit->get_pivot()->get_right();		HX_STACK_VAR(vx,"vx");
		HX_STACK_LINE(287)
		vz->y = (int)0;
		HX_STACK_LINE(287)
		vz->Normalize();
		HX_STACK_LINE(288)
		vx->y = (int)0;
		HX_STACK_LINE(288)
		vx->Normalize();
		HX_STACK_LINE(290)
		if ((this->debug)){
			HX_STACK_LINE(292)
			if ((::haxor::input::Input_obj::Pressed(::haxor::input::KeyCode_obj::W))){
				HX_STACK_LINE(292)
				::haxor::math::Vector3 _g4 = vz->Scale((::haxor::core::Time_obj::m_delta * 500.0));		HX_STACK_VAR(_g4,"_g4");
				HX_STACK_LINE(292)
				p->Add(_g4);
			}
			HX_STACK_LINE(293)
			if ((::haxor::input::Input_obj::Pressed(::haxor::input::KeyCode_obj::S))){
				HX_STACK_LINE(293)
				::haxor::math::Vector3 _g5 = vz->Scale((::haxor::core::Time_obj::m_delta * 500.0));		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(293)
				p->Sub(_g5);
			}
			HX_STACK_LINE(294)
			if ((::haxor::input::Input_obj::Pressed(::haxor::input::KeyCode_obj::A))){
				HX_STACK_LINE(294)
				::haxor::math::Vector3 _g6 = vx->Scale((::haxor::core::Time_obj::m_delta * 500.0));		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(294)
				p->Sub(_g6);
			}
			HX_STACK_LINE(295)
			if ((::haxor::input::Input_obj::Pressed(::haxor::input::KeyCode_obj::D))){
				HX_STACK_LINE(295)
				::haxor::math::Vector3 _g7 = vx->Scale((::haxor::core::Time_obj::m_delta * 500.0));		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(295)
				p->Add(_g7);
			}
			HX_STACK_LINE(296)
			this->orbit->get_pivot()->set_localPosition(p);
		}
		HX_STACK_LINE(300)
		::String _g8 = ::StringTools_obj::replace(((log + HX_CSTRING(" FPS: ")) + ::haxor::core::Time_obj::m_fps),HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(300)
		this->get_application()->get_window()->set_title(_g8);
		HX_STACK_LINE(307)
		hx::AddEq(this->angle,(::haxor::core::Time_obj::m_delta * 45.0));
		HX_STACK_LINE(308)
		Float s = ::Math_obj::sin((this->angle * 0.01745329251994329576923690768489));		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(312)
		bool flag_emit = false;		HX_STACK_VAR(flag_emit,"flag_emit");
		HX_STACK_LINE(314)
		if ((::haxor::input::Input_obj::Down(::haxor::input::KeyCode_obj::Space))){
			HX_STACK_LINE(314)
			flag_emit = true;
		}
		HX_STACK_LINE(315)
		if (((::haxor::input::Input_obj::get_touches()->length > (int)0))){
			HX_STACK_LINE(315)
			Array< ::Dynamic > _g9 = ::haxor::input::Input_obj::get_touches();		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(315)
			if ((_g9->__get((int)0).StaticCast< ::haxor::input::Touch >()->get_down())){
				HX_STACK_LINE(315)
				flag_emit = true;
			}
		}
		HX_STACK_LINE(316)
		if (((::haxor::input::Input_obj::get_touches()->length > (int)1))){
			HX_STACK_LINE(316)
			Array< ::Dynamic > _g10 = ::haxor::input::Input_obj::get_touches();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(316)
			if ((_g10->__get((int)1).StaticCast< ::haxor::input::Touch >()->get_down())){
				HX_STACK_LINE(316)
				this->particle->Reset();
			}
		}
		HX_STACK_LINE(317)
		if ((flag_emit)){
			HX_STACK_LINE(319)
			::haxe::Log_obj::trace(HX_CSTRING("EMIT"),hx::SourceInfo(HX_CSTRING("Main.hx"),319,HX_CSTRING("examples.particles.Main"),HX_CSTRING("OnUpdate")));
			HX_STACK_LINE(320)
			this->particle->Emit(1.0);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnUpdate,(void))

Void Main_obj::OnRender( ){
{
		HX_STACK_FRAME("examples.particles.Main","OnRender",0x5beab984,"examples.particles.Main.OnRender","examples/particles/Main.hx",327,0x269d325d)
		HX_STACK_THIS(this)
		HX_STACK_LINE(329)
		{
			HX_STACK_LINE(330)
			{
				HX_STACK_LINE(330)
				::haxor::math::Color p_color = ::haxor::math::Color_obj::__new((int)1,(int)1,(int)1,0.1);		HX_STACK_VAR(p_color,"p_color");
				HX_STACK_LINE(330)
				::haxor::context::EngineContext_obj::gizmo->DrawGrid(100.0,p_color);
			}
			HX_STACK_LINE(331)
			{
				struct _Function_3_1{
					inline static ::haxor::math::Vector3 Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","examples/particles/Main.hx",331,0x269d325d)
						{
							HX_STACK_LINE(331)
							::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(331)
							int _g = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g,"_g");
							HX_STACK_LINE(331)
							return _this->m_v3->__get(_g).StaticCast< ::haxor::math::Vector3 >();
						}
						return null();
					}
				};
				HX_STACK_LINE(331)
				::haxor::math::Vector3 p_position = (_Function_3_1::Block())->Set(null(),null(),null());		HX_STACK_VAR(p_position,"p_position");
				struct _Function_3_2{
					inline static ::haxor::math::Vector3 Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","examples/particles/Main.hx",331,0x269d325d)
						{
							HX_STACK_LINE(331)
							::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(331)
							int _g1 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(331)
							return _this->m_v3->__get(_g1).StaticCast< ::haxor::math::Vector3 >();
						}
						return null();
					}
				};
				HX_STACK_LINE(331)
				::haxor::math::Vector3 p_size = (_Function_3_2::Block())->Set((int)2,(int)2,(int)2);		HX_STACK_VAR(p_size,"p_size");
				HX_STACK_LINE(331)
				::haxor::context::EngineContext_obj::gizmo->DrawAxis(p_position,p_size,null(),null());
			}
		}
		HX_STACK_LINE(334)
		Float sh = ::haxor::graphics::Screen_obj::m_height;		HX_STACK_VAR(sh,"sh");
		HX_STACK_LINE(335)
		Float th = 2048.0;		HX_STACK_VAR(th,"th");
		HX_STACK_LINE(336)
		::haxor::graphics::texture::Texture tex = this->particle->m_kernel->m_back;		HX_STACK_VAR(tex,"tex");
		HX_STACK_LINE(338)
		if (((tex != null()))){
			HX_STACK_LINE(338)
			::haxor::graphics::Graphics_obj::DrawTexture(tex,(int)0,(int)100,(int)320,(int)320,null());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnRender,(void))

bool Main_obj::Load( ){
	HX_STACK_FRAME("examples.particles.Main","Load",0xb4dcae55,"examples.particles.Main.Load","examples/particles/Main.hx",348,0x269d325d)
	HX_STACK_THIS(this)
	HX_STACK_LINE(349)
	::haxor::net::Web_obj::root = HX_CSTRING("http://www.haxor.xyz/resources/");
	HX_STACK_LINE(351)
	::haxor::core::ApplicationProtocol _g = this->get_protocol();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(351)
	if (((_g == ::haxor::core::ApplicationProtocol_obj::File))){
		HX_STACK_LINE(353)
		::haxor::core::Asset_obj::LoadTexture2D(HX_CSTRING("particle"),HX_CSTRING("assets/particles/particle.png"));
	}
	else{
		HX_STACK_LINE(357)
		::haxor::core::Asset_obj::LoadTexture2D(HX_CSTRING("particle"),HX_CSTRING("./texture/particle/particle.png"));
	}
	HX_STACK_LINE(405)
	return false;
}


Void Main_obj::OnLoadProgress( ::String p_id,Float p_progress){
{
		HX_STACK_FRAME("examples.particles.Main","OnLoadProgress",0xa01f08a1,"examples.particles.Main.OnLoadProgress","examples/particles/Main.hx",409,0x269d325d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_progress,"p_progress")
	}
return null();
}


Void Main_obj::OnLoadComplete( ::String p_id,Dynamic p_asset){
{
		HX_STACK_FRAME("examples.particles.Main","OnLoadComplete",0x99bc11ad,"examples.particles.Main.OnLoadComplete","examples/particles/Main.hx",417,0x269d325d)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_ARG(p_asset,"p_asset")
	}
return null();
}


Void Main_obj::main( ){
{
		HX_STACK_FRAME("examples.particles.Main","main",0xcaa22048,"examples.particles.Main.main","examples/particles/Main.hx",98,0x269d325d)
		HX_STACK_LINE(98)
		::haxor::platform::windows::Entry_obj::Initialize();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(debug,"debug");
	HX_MARK_MEMBER_NAME(orbit,"orbit");
	HX_MARK_MEMBER_NAME(particle,"particle");
	HX_MARK_MEMBER_NAME(angle,"angle");
	::haxor::platform::windows::WinApplication_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(debug,"debug");
	HX_VISIT_MEMBER_NAME(orbit,"orbit");
	HX_VISIT_MEMBER_NAME(particle,"particle");
	HX_VISIT_MEMBER_NAME(angle,"angle");
	::haxor::platform::windows::WinApplication_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"Load") ) { return Load_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"debug") ) { return debug; }
		if (HX_FIELD_EQ(inName,"orbit") ) { return orbit; }
		if (HX_FIELD_EQ(inName,"angle") ) { return angle; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"OnStart") ) { return OnStart_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"particle") ) { return particle; }
		if (HX_FIELD_EQ(inName,"OnUpdate") ) { return OnUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"OnRender") ) { return OnRender_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"LoadDebug") ) { return LoadDebug_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"CreateParticle") ) { return CreateParticle_dyn(); }
		if (HX_FIELD_EQ(inName,"OnLoadProgress") ) { return OnLoadProgress_dyn(); }
		if (HX_FIELD_EQ(inName,"OnLoadComplete") ) { return OnLoadComplete_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"debug") ) { debug=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"orbit") ) { orbit=inValue.Cast< ::haxor::component::CameraOrbit >(); return inValue; }
		if (HX_FIELD_EQ(inName,"angle") ) { angle=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"particle") ) { particle=inValue.Cast< ::haxor::component::ParticleRenderer >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("debug"));
	outFields->push(HX_CSTRING("orbit"));
	outFields->push(HX_CSTRING("particle"));
	outFields->push(HX_CSTRING("angle"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Main_obj,debug),HX_CSTRING("debug")},
	{hx::fsObject /*::haxor::component::CameraOrbit*/ ,(int)offsetof(Main_obj,orbit),HX_CSTRING("orbit")},
	{hx::fsObject /*::haxor::component::ParticleRenderer*/ ,(int)offsetof(Main_obj,particle),HX_CSTRING("particle")},
	{hx::fsFloat,(int)offsetof(Main_obj,angle),HX_CSTRING("angle")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("debug"),
	HX_CSTRING("orbit"),
	HX_CSTRING("particle"),
	HX_CSTRING("angle"),
	HX_CSTRING("LoadDebug"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("OnStart"),
	HX_CSTRING("CreateParticle"),
	HX_CSTRING("OnUpdate"),
	HX_CSTRING("OnRender"),
	HX_CSTRING("Load"),
	HX_CSTRING("OnLoadProgress"),
	HX_CSTRING("OnLoadComplete"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#endif

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("examples.particles.Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
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

void Main_obj::__boot()
{
}

} // end namespace examples
} // end namespace particles
