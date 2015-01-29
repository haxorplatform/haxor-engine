#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
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
#ifndef INCLUDED_haxor_component_Renderer
#include <haxor/component/Renderer.h>
#endif
#ifndef INCLUDED_haxor_component_Transform
#include <haxor/component/Transform.h>
#endif
#ifndef INCLUDED_haxor_component_animation_Animation
#include <haxor/component/animation/Animation.h>
#endif
#ifndef INCLUDED_haxor_component_animation_AnimationClip
#include <haxor/component/animation/AnimationClip.h>
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
#ifndef INCLUDED_haxor_core_AnimationWrap
#include <haxor/core/AnimationWrap.h>
#endif
#ifndef INCLUDED_haxor_core_Application
#include <haxor/core/Application.h>
#endif
#ifndef INCLUDED_haxor_core_BaseApplication
#include <haxor/core/BaseApplication.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
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
#ifndef INCLUDED_haxor_core_IUpdateable
#include <haxor/core/IUpdateable.h>
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
#ifndef INCLUDED_haxor_graphics_Gizmo
#include <haxor/graphics/Gizmo.h>
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
#ifndef INCLUDED_haxor_graphics_texture_Texture2D
#include <haxor/graphics/texture/Texture2D.h>
#endif
#ifndef INCLUDED_haxor_io_file_Asset
#include <haxor/io/file/Asset.h>
#endif
#ifndef INCLUDED_haxor_io_file_AssetFile
#include <haxor/io/file/AssetFile.h>
#endif
#ifndef INCLUDED_haxor_io_file_AssetXML
#include <haxor/io/file/AssetXML.h>
#endif
#ifndef INCLUDED_haxor_io_file_ColladaFile
#include <haxor/io/file/ColladaFile.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Quaternion
#include <haxor/math/Quaternion.h>
#endif
#ifndef INCLUDED_haxor_math_Random
#include <haxor/math/Random.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_math_Vector4
#include <haxor/math/Vector4.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_FRAME("Main","new",0x6616a5cb,"Main.new","Main.hx",74,0x087e5c05)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(92)
	this->queue = (int)3;
	HX_STACK_LINE(74)
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

bool Main_obj::Load( ){
	HX_STACK_FRAME("Main","Load",0xd748ae7b,"Main.Load","Main.hx",99,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_LINE(98)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(100)
	::haxor::net::Web_obj::root = HX_CSTRING("http://www.haxor.xyz/resources/");

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,_g)
	Void run(::haxor::io::file::ColladaFile f,Float p){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","Main.hx",106,0x087e5c05)
		HX_STACK_ARG(f,"f")
		HX_STACK_ARG(p,"p")
		{
			HX_STACK_LINE(106)
			if (((p >= 1.0))){
				HX_STACK_LINE(108)
				::haxor::io::file::Asset_obj::Add(HX_CSTRING("animation_idle"),f);
				HX_STACK_LINE(109)
				if (((--(_g->__get((int)0).StaticCast< ::Main >()->queue) <= (int)0))){
					HX_STACK_LINE(109)
					_g->__get((int)0).StaticCast< ::Main >()->LoadComplete();
				}
			}
		}
		return null();
	}
	HX_END_LOCAL_FUNC2((void))

	HX_STACK_LINE(104)
	::haxor::net::Web_obj::LoadCollada(HX_CSTRING("./character/skeleton/grunt/animation_idle01.DAE"), Dynamic(new _Function_1_1(_g)));

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_2,Array< ::Dynamic >,_g)
	Void run(::haxor::graphics::texture::Texture2D t,Float p){
		HX_STACK_FRAME("*","_Function_1_2",0x5200ed38,"*._Function_1_2","Main.hx",116,0x087e5c05)
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(p,"p")
		{
			HX_STACK_LINE(116)
			if (((p >= 1.0))){
				HX_STACK_LINE(118)
				::haxor::io::file::Asset_obj::Add(HX_CSTRING("texture_diffuse"),t);
				HX_STACK_LINE(119)
				if (((--(_g->__get((int)0).StaticCast< ::Main >()->queue) <= (int)0))){
					HX_STACK_LINE(119)
					_g->__get((int)0).StaticCast< ::Main >()->LoadComplete();
				}
			}
		}
		return null();
	}
	HX_END_LOCAL_FUNC2((void))

	HX_STACK_LINE(114)
	::haxor::net::Web_obj::LoadTexture2D(HX_CSTRING("./character/skeleton/grunt/DiffuseTexture.png"),true, Dynamic(new _Function_1_2(_g)));

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_3,Array< ::Dynamic >,_g)
	Void run(::haxor::io::file::ColladaFile f,Float p){
		HX_STACK_FRAME("*","_Function_1_3",0x5200ed39,"*._Function_1_3","Main.hx",126,0x087e5c05)
		HX_STACK_ARG(f,"f")
		HX_STACK_ARG(p,"p")
		{
			HX_STACK_LINE(126)
			if (((p >= 1.0))){
				HX_STACK_LINE(128)
				::haxor::io::file::Asset_obj::Add(HX_CSTRING("model"),f);
				HX_STACK_LINE(129)
				if (((--(_g->__get((int)0).StaticCast< ::Main >()->queue) <= (int)0))){
					HX_STACK_LINE(129)
					_g->__get((int)0).StaticCast< ::Main >()->LoadComplete();
				}
			}
		}
		return null();
	}
	HX_END_LOCAL_FUNC2((void))

	HX_STACK_LINE(124)
	::haxor::net::Web_obj::LoadCollada(HX_CSTRING("./character/skeleton/grunt/model.DAE"), Dynamic(new _Function_1_3(_g)));
	HX_STACK_LINE(135)
	return false;
}


Void Main_obj::Initialize( ){
{
		HX_STACK_FRAME("Main","Initialize",0x7af3b365,"Main.Initialize","Main.hx",139,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(140)
		::haxor::core::Console_obj::Log(HX_CSTRING("Initialize!"),null());
		HX_STACK_LINE(156)
		::haxor::component::CameraOrbit _g = ::haxor::component::CameraOrbit_obj::Create(40.0,(int)45,(int)30);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(156)
		this->orbit = _g;
		HX_STACK_LINE(158)
		::haxor::component::CameraOrbitInput ci = this->orbit->m_entity->AddComponent(hx::ClassOf< ::haxor::component::CameraOrbitInput >());		HX_STACK_VAR(ci,"ci");
		HX_STACK_LINE(159)
		this->orbit->smooth = 5.0;
		HX_STACK_LINE(160)
		ci->zoomSpeed = 1.0;
		HX_STACK_LINE(161)
		Dynamic _g1 = this->orbit->m_entity->GetComponentInChildren(hx::ClassOf< ::haxor::component::Camera >());		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(161)
		this->cam = _g1;
		HX_STACK_LINE(162)
		{
			HX_STACK_LINE(162)
			::haxor::component::Camera _this = this->cam;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(162)
			_this->m_far = 1000.0;
			HX_STACK_LINE(162)
			_this->m_projection_dirty = true;
			HX_STACK_LINE(162)
			_this->m_proj_uniform_dirty = true;
			HX_STACK_LINE(162)
			1000.0;
		}
		HX_STACK_LINE(163)
		::haxor::math::Color _g2 = ::haxor::math::Color_obj::__new(0.3,0.3,0.3,null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(163)
		this->cam->background = _g2;
		HX_STACK_LINE(167)
		::haxor::component::Transform _g3;		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(167)
		{
			HX_STACK_LINE(167)
			::haxor::core::Entity _this = ::haxor::core::Entity_obj::__new(HX_CSTRING("container"));		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(167)
			_g3 = _this->m_transform;
		}
		HX_STACK_LINE(167)
		this->container = _g3;
		HX_STACK_LINE(169)
		::haxor::graphics::material::Material _g7;		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(169)
		{
			HX_STACK_LINE(169)
			::haxor::graphics::texture::Texture p_texture = ::haxor::io::file::Asset_obj::Get(HX_CSTRING("texture_diffuse"));		HX_STACK_VAR(p_texture,"p_texture");
			HX_STACK_LINE(169)
			bool p_ztest = true;		HX_STACK_VAR(p_ztest,"p_ztest");
			HX_STACK_LINE(169)
			bool p_zwrite = true;		HX_STACK_VAR(p_zwrite,"p_zwrite");
			HX_STACK_LINE(169)
			::haxor::graphics::material::Material m = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Opaque"));		HX_STACK_VAR(m,"m");
			HX_STACK_LINE(169)
			::haxor::graphics::material::Shader _g6;		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(169)
			if (((p_texture == null()))){
				HX_STACK_LINE(169)
				if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
					HX_STACK_LINE(169)
					::haxor::graphics::material::Shader _g4 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(169)
					_g6 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g4;
				}
				else{
					HX_STACK_LINE(169)
					_g6 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
				}
			}
			else{
				HX_STACK_LINE(169)
				if (((::haxor::graphics::material::Shader_obj::m_flat_texture_shader == null()))){
					HX_STACK_LINE(169)
					::haxor::graphics::material::Shader _g5 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_texture_source);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(169)
					_g6 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader = _g5;
				}
				else{
					HX_STACK_LINE(169)
					_g6 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader;
				}
			}
			HX_STACK_LINE(169)
			m->set_shader(_g6);
			HX_STACK_LINE(169)
			m->queue = (int)1000;
			HX_STACK_LINE(169)
			m->ztest = p_ztest;
			HX_STACK_LINE(169)
			m->zwrite = p_zwrite;
			HX_STACK_LINE(169)
			if (((p_texture != null()))){
				HX_STACK_LINE(169)
				m->SetTexture(HX_CSTRING("DiffuseTexture"),p_texture);
			}
			HX_STACK_LINE(169)
			_g7 = m;
		}
		HX_STACK_LINE(169)
		this->mat = _g7;
		HX_STACK_LINE(170)
		::haxor::graphics::material::Shader _g9;		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(170)
		if (((::haxor::graphics::material::Shader_obj::m_flat_texture_skin_shader == null()))){
			HX_STACK_LINE(170)
			::haxor::graphics::material::Shader _g8 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_texture_skin_source);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(170)
			_g9 = ::haxor::graphics::material::Shader_obj::m_flat_texture_skin_shader = _g8;
		}
		else{
			HX_STACK_LINE(170)
			_g9 = ::haxor::graphics::material::Shader_obj::m_flat_texture_skin_shader;
		}
		HX_STACK_LINE(170)
		this->mat->set_shader(_g9);
		HX_STACK_LINE(171)
		this->mat->set_name(HX_CSTRING("PlayerMaterial"));
		HX_STACK_LINE(172)
		Dynamic _g10 = ::haxor::io::file::Asset_obj::Get(HX_CSTRING("texture_diffuse"));		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(172)
		this->mat->SetTexture(HX_CSTRING("DiffuseTexture"),_g10);
		HX_STACK_LINE(174)
		::haxor::io::file::ColladaFile cf;		HX_STACK_VAR(cf,"cf");
		HX_STACK_LINE(176)
		Dynamic _g11 = ::haxor::io::file::Asset_obj::Get(HX_CSTRING("model"));		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(176)
		cf = _g11;
		HX_STACK_LINE(178)
		::haxor::component::Transform _g12;		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(178)
		{
			HX_STACK_LINE(178)
			::haxor::core::Entity _this = ::haxor::core::Entity_obj::__new(HX_CSTRING("player"));		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(178)
			_g12 = _this->m_transform;
		}
		HX_STACK_LINE(178)
		this->player = _g12;
		HX_STACK_LINE(179)
		::haxor::component::Transform asset;		HX_STACK_VAR(asset,"asset");
		HX_STACK_LINE(179)
		{
			HX_STACK_LINE(179)
			::haxor::core::Entity _this;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(179)
			_this = hx::TCast< haxor::core::Entity >::cast(cf->get_asset());
			HX_STACK_LINE(179)
			asset = _this->m_transform;
		}
		HX_STACK_LINE(180)
		asset->set_parent(this->player);
		HX_STACK_LINE(182)
		::haxor::math::Vector3 _g13 = ::haxor::math::Vector3_obj::__new(0.1,0.1,0.1);		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(182)
		asset->set_localScale(_g13);
		HX_STACK_LINE(185)
		Array< ::Dynamic > mr = this->player->m_entity->GetComponentsInChildren(hx::ClassOf< ::haxor::component::MeshRenderer >());		HX_STACK_VAR(mr,"mr");
		HX_STACK_LINE(186)
		{
			HX_STACK_LINE(186)
			int _g14 = (int)0;		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(186)
			int _g4 = mr->length;		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(186)
			while((true)){
				HX_STACK_LINE(186)
				if ((!(((_g14 < _g4))))){
					HX_STACK_LINE(186)
					break;
				}
				HX_STACK_LINE(186)
				int i = (_g14)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(189)
				mr->__get(i).StaticCast< ::haxor::component::MeshRenderer >()->set_material(this->mat);
			}
		}
		HX_STACK_LINE(192)
		::haxor::component::animation::Animation anim;		HX_STACK_VAR(anim,"anim");
		HX_STACK_LINE(193)
		Dynamic _g14 = ::haxor::io::file::Asset_obj::Get(HX_CSTRING("animation_idle"));		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(193)
		cf = _g14;
		HX_STACK_LINE(194)
		cf->AddAnimations(asset->m_entity,null());
		HX_STACK_LINE(195)
		anim = asset->m_entity->m_animation;
		HX_STACK_LINE(196)
		anim->Play(anim->clips->__get((int)0).StaticCast< ::haxor::component::animation::AnimationClip >(),null());
		HX_STACK_LINE(197)
		anim->clips->__get((int)0).StaticCast< ::haxor::component::animation::AnimationClip >()->wrap = ::haxor::core::AnimationWrap_obj::Loop;
	}
return null();
}


Void Main_obj::OnUpdate( ){
{
		HX_STACK_FRAME("Main","OnUpdate",0x876cdf5d,"Main.OnUpdate","Main.hx",202,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(203)
		::String log = HX_CSTRING("");		HX_STACK_VAR(log,"log");
		HX_STACK_LINE(205)
		hx::AddEq(log,HX_CSTRING("Stats"));
		HX_STACK_LINE(206)
		hx::AddEq(log,(HX_CSTRING("\nVisible: ") + ::haxor::core::RenderStats_obj::visible));
		HX_STACK_LINE(207)
		hx::AddEq(log,(HX_CSTRING("\nCulled: ") + ::haxor::core::RenderStats_obj::culled));
		HX_STACK_LINE(208)
		int _g = ::haxor::core::RenderStats_obj::get_total();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(208)
		::String _g1 = (HX_CSTRING("\nActive: ") + _g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(208)
		hx::AddEq(log,_g1);
		HX_STACK_LINE(209)
		hx::AddEq(log,(HX_CSTRING("\nRenderers: ") + ::haxor::core::RenderStats_obj::renderers));
		HX_STACK_LINE(210)
		hx::AddEq(log,(HX_CSTRING("\nTris: ") + ::haxor::core::RenderStats_obj::triangles));
		HX_STACK_LINE(212)
		if (((this->player != null()))){
			HX_STACK_LINE(214)
			::haxor::math::Quaternion r = this->player->get_localRotation();		HX_STACK_VAR(r,"r");
			HX_STACK_LINE(216)
			::haxor::math::Vector3 _g2 = ::haxor::math::Vector3_obj::__new((int)0,(int)1,(int)0);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(216)
			::haxor::math::Quaternion _g3 = ::haxor::math::Quaternion_obj::FromAxisAngle(_g2,33.0);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(216)
			r = _g3;
			HX_STACK_LINE(217)
			this->player->set_localRotation(r);
		}
		HX_STACK_LINE(225)
		::String _g4 = ::StringTools_obj::replace(((log + HX_CSTRING(" FPS: ")) + ::haxor::core::Time_obj::m_fps),HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(225)
		this->get_application()->get_window()->set_title(_g4);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnUpdate,(void))

Void Main_obj::OnRender( ){
{
		HX_STACK_FRAME("Main","OnRender",0x0590c4aa,"Main.OnRender","Main.hx",238,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(239)
		{
			HX_STACK_LINE(239)
			::haxor::math::Color p_color = ::haxor::math::Color_obj::__new((int)1,(int)1,(int)1,0.1);		HX_STACK_VAR(p_color,"p_color");
			HX_STACK_LINE(239)
			::haxor::context::EngineContext_obj::gizmo->DrawGrid(100.0,p_color);
		}
		HX_STACK_LINE(250)
		if (((this->pl == null()))){
			HX_STACK_LINE(252)
			this->pl = Array_obj< ::Dynamic >::__new();
			HX_STACK_LINE(253)
			{
				HX_STACK_LINE(253)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(253)
				while((true)){
					HX_STACK_LINE(253)
					if ((!(((_g < (int)500))))){
						HX_STACK_LINE(253)
						break;
					}
					HX_STACK_LINE(253)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(255)
					::haxor::math::Vector4 pt = ::haxor::math::Vector4_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(pt,"pt");
					HX_STACK_LINE(256)
					Float _g1 = ::Math_obj::random();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(256)
					Float _g11 = (_g1 - 0.499995);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(256)
					Float _g2 = (_g11 * 2.0);		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(256)
					Float _g3 = ::Math_obj::random();		HX_STACK_VAR(_g3,"_g3");
					HX_STACK_LINE(256)
					Float _g4 = (_g3 - 0.499995);		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(256)
					Float _g5 = (_g4 * 2.0);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(256)
					Float _g6 = ::Math_obj::random();		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(256)
					Float _g7 = (_g6 - 0.499995);		HX_STACK_VAR(_g7,"_g7");
					HX_STACK_LINE(256)
					Float _g8 = (_g7 * 2.0);		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(256)
					Float _g9 = ::Math_obj::random();		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(256)
					::haxor::math::Vector3 _g10 = ::haxor::math::Vector3_obj::__new(_g2,_g5,_g8)->Normalize()->Scale(_g9)->Scale(25.0);		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(256)
					pt->Set3(_g10);
					HX_STACK_LINE(257)
					Float _g111 = ::haxor::math::Random_obj::Range(10.0,10.0);		HX_STACK_VAR(_g111,"_g111");
					HX_STACK_LINE(257)
					pt->w = _g111;
					HX_STACK_LINE(258)
					this->pl->push(pt);
				}
			}
		}
		HX_STACK_LINE(262)
		{
			HX_STACK_LINE(262)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(262)
			int _g = this->pl->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(262)
			while((true)){
				HX_STACK_LINE(262)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(262)
					break;
				}
				HX_STACK_LINE(262)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(264)
				::haxor::math::Vector3 _g12;		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(264)
				{
					HX_STACK_LINE(264)
					::haxor::math::Vector4 _this = this->pl->__get(i).StaticCast< ::haxor::math::Vector4 >();		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(264)
					_g12 = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
				}
				HX_STACK_LINE(264)
				::haxor::math::Color _g14 = ::haxor::math::Color_obj::__new(0.9,0.3,0.3,(int)1);		HX_STACK_VAR(_g14,"_g14");
				struct _Function_3_1{
					inline static ::haxor::math::Color Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",264,0x087e5c05)
						{
							HX_STACK_LINE(264)
							::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(264)
							int _g13 = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g13,"_g13");
							HX_STACK_LINE(264)
							return _this->m_c->__get(_g13).StaticCast< ::haxor::math::Color >();
						}
						return null();
					}
				};
				HX_STACK_LINE(264)
				::haxor::math::Color _g15 = (_Function_3_1::Block())->Set((int)0,(int)0,(int)0,0.5)->SetRGB(_g14);		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(264)
				::haxor::graphics::Gizmo_obj::Point(_g12,this->pl->__get(i).StaticCast< ::haxor::math::Vector4 >()->w,_g15,true,null());
				HX_STACK_LINE(265)
				::haxor::math::Vector3 _g16;		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(265)
				{
					HX_STACK_LINE(265)
					::haxor::math::Vector4 _this = this->pl->__get(i).StaticCast< ::haxor::math::Vector4 >();		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(265)
					_g16 = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
				}
				struct _Function_3_2{
					inline static ::haxor::math::Vector3 Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",265,0x087e5c05)
						{
							HX_STACK_LINE(265)
							::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(265)
							int _g17 = _this->m_nv3 = hx::Mod(((_this->m_nv3 + (int)1)),_this->m_v3->length);		HX_STACK_VAR(_g17,"_g17");
							HX_STACK_LINE(265)
							return _this->m_v3->__get(_g17).StaticCast< ::haxor::math::Vector3 >();
						}
						return null();
					}
				};
				HX_STACK_LINE(265)
				::haxor::math::Vector3 _g18 = (_Function_3_2::Block())->Set((int)1,(int)1,(int)1)->Scale(0.5);		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(265)
				::haxor::math::Color _g20 = ::haxor::math::Color_obj::__new(0.3,0.9,0.3,(int)1);		HX_STACK_VAR(_g20,"_g20");
				struct _Function_3_3{
					inline static ::haxor::math::Color Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",265,0x087e5c05)
						{
							HX_STACK_LINE(265)
							::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(265)
							int _g19 = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g19,"_g19");
							HX_STACK_LINE(265)
							return _this->m_c->__get(_g19).StaticCast< ::haxor::math::Color >();
						}
						return null();
					}
				};
				HX_STACK_LINE(265)
				::haxor::math::Color _g21 = (_Function_3_3::Block())->Set((int)0,(int)0,(int)0,1.0)->SetRGB(_g20);		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(265)
				::haxor::graphics::Gizmo_obj::WireCube(_g16,_g18,_g21,null());
				HX_STACK_LINE(266)
				::haxor::math::Vector3 _g22;		HX_STACK_VAR(_g22,"_g22");
				HX_STACK_LINE(266)
				{
					HX_STACK_LINE(266)
					::haxor::math::Vector4 _this = this->pl->__get(i).StaticCast< ::haxor::math::Vector4 >();		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(266)
					_g22 = ::haxor::math::Vector3_obj::__new(_this->x,_this->y,_this->z);
				}
				HX_STACK_LINE(266)
				::haxor::math::Color _g24 = ::haxor::math::Color_obj::__new(0.3,0.3,0.9,(int)1);		HX_STACK_VAR(_g24,"_g24");
				struct _Function_3_4{
					inline static ::haxor::math::Color Block( ){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Main.hx",266,0x087e5c05)
						{
							HX_STACK_LINE(266)
							::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
							HX_STACK_LINE(266)
							int _g23 = _this->m_nc = hx::Mod(((_this->m_nc + (int)1)),_this->m_c->length);		HX_STACK_VAR(_g23,"_g23");
							HX_STACK_LINE(266)
							return _this->m_c->__get(_g23).StaticCast< ::haxor::math::Color >();
						}
						return null();
					}
				};
				HX_STACK_LINE(266)
				::haxor::math::Color _g25 = (_Function_3_4::Block())->Set((int)0,(int)0,(int)0,1.0)->SetRGB(_g24);		HX_STACK_VAR(_g25,"_g25");
				HX_STACK_LINE(266)
				::haxor::graphics::Gizmo_obj::WireSphere(_g22,1.0,_g25,null());
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnRender,(void))

Void Main_obj::main( ){
{
		HX_STACK_FRAME("Main","main",0xed0e206e,"Main.main","Main.hx",79,0x087e5c05)
		HX_STACK_LINE(79)
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
	HX_MARK_MEMBER_NAME(cam,"cam");
	HX_MARK_MEMBER_NAME(orbit,"orbit");
	HX_MARK_MEMBER_NAME(container,"container");
	HX_MARK_MEMBER_NAME(mat,"mat");
	HX_MARK_MEMBER_NAME(player,"player");
	HX_MARK_MEMBER_NAME(queue,"queue");
	HX_MARK_MEMBER_NAME(pl,"pl");
	::haxor::platform::windows::WinApplication_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(cam,"cam");
	HX_VISIT_MEMBER_NAME(orbit,"orbit");
	HX_VISIT_MEMBER_NAME(container,"container");
	HX_VISIT_MEMBER_NAME(mat,"mat");
	HX_VISIT_MEMBER_NAME(player,"player");
	HX_VISIT_MEMBER_NAME(queue,"queue");
	HX_VISIT_MEMBER_NAME(pl,"pl");
	::haxor::platform::windows::WinApplication_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"pl") ) { return pl; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"cam") ) { return cam; }
		if (HX_FIELD_EQ(inName,"mat") ) { return mat; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"Load") ) { return Load_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"orbit") ) { return orbit; }
		if (HX_FIELD_EQ(inName,"queue") ) { return queue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"player") ) { return player; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"OnUpdate") ) { return OnUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"OnRender") ) { return OnRender_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"container") ) { return container; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"pl") ) { pl=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"cam") ) { cam=inValue.Cast< ::haxor::component::Camera >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mat") ) { mat=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"orbit") ) { orbit=inValue.Cast< ::haxor::component::CameraOrbit >(); return inValue; }
		if (HX_FIELD_EQ(inName,"queue") ) { queue=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"player") ) { player=inValue.Cast< ::haxor::component::Transform >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"container") ) { container=inValue.Cast< ::haxor::component::Transform >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("cam"));
	outFields->push(HX_CSTRING("orbit"));
	outFields->push(HX_CSTRING("container"));
	outFields->push(HX_CSTRING("mat"));
	outFields->push(HX_CSTRING("player"));
	outFields->push(HX_CSTRING("queue"));
	outFields->push(HX_CSTRING("pl"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::component::Camera*/ ,(int)offsetof(Main_obj,cam),HX_CSTRING("cam")},
	{hx::fsObject /*::haxor::component::CameraOrbit*/ ,(int)offsetof(Main_obj,orbit),HX_CSTRING("orbit")},
	{hx::fsObject /*::haxor::component::Transform*/ ,(int)offsetof(Main_obj,container),HX_CSTRING("container")},
	{hx::fsObject /*::haxor::graphics::material::Material*/ ,(int)offsetof(Main_obj,mat),HX_CSTRING("mat")},
	{hx::fsObject /*::haxor::component::Transform*/ ,(int)offsetof(Main_obj,player),HX_CSTRING("player")},
	{hx::fsInt,(int)offsetof(Main_obj,queue),HX_CSTRING("queue")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Main_obj,pl),HX_CSTRING("pl")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("cam"),
	HX_CSTRING("orbit"),
	HX_CSTRING("container"),
	HX_CSTRING("mat"),
	HX_CSTRING("player"),
	HX_CSTRING("queue"),
	HX_CSTRING("Load"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("OnUpdate"),
	HX_CSTRING("pl"),
	HX_CSTRING("OnRender"),
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
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
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

