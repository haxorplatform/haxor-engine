#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_haxor_core_BaseApplication
#include <haxor/core/BaseApplication.h>
#endif
#ifndef INCLUDED_haxor_core_ClearFlag
#include <haxor/core/ClearFlag.h>
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
#ifndef INCLUDED_haxor_core_RenderStats
#include <haxor/core/RenderStats.h>
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
#ifndef INCLUDED_haxor_graphics_material_Shader
#include <haxor/graphics/material/Shader.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Mesh
#include <haxor/graphics/mesh/Mesh.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_Model
#include <haxor/graphics/mesh/Model.h>
#endif
#ifndef INCLUDED_haxor_input_Input
#include <haxor/input/Input.h>
#endif
#ifndef INCLUDED_haxor_input_KeyCode
#include <haxor/input/KeyCode.h>
#endif
#ifndef INCLUDED_haxor_math_AABB3
#include <haxor/math/AABB3.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
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
#ifndef INCLUDED_haxor_thread_Activity
#include <haxor/thread/Activity.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_FRAME("Main","new",0x6616a5cb,"Main.new","Main.hx",90,0x087e5c05)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(108)
	this->queue = (int)3;
	HX_STACK_LINE(90)
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
	HX_STACK_FRAME("Main","Load",0xd748ae7b,"Main.Load","Main.hx",123,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_LINE(124)
	::haxor::net::Web_obj::root = HX_CSTRING("http://www.haxor.xyz/resources/");
	HX_STACK_LINE(126)
	return true;
}


Void Main_obj::Initialize( ){
{
		HX_STACK_FRAME("Main","Initialize",0x7af3b365,"Main.Initialize","Main.hx",130,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(129)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(131)
		::haxor::core::Console_obj::Log(HX_CSTRING("Initialize!"),null());
		HX_STACK_LINE(147)
		::haxor::component::CameraOrbit cpo;		HX_STACK_VAR(cpo,"cpo");
		HX_STACK_LINE(149)
		::haxor::component::CameraOrbit _g1 = ::haxor::component::CameraOrbit_obj::Create(40.0,(int)45,(int)45);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(149)
		::haxor::component::CameraOrbit _g11 = this->orbit = _g1;		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(149)
		cpo = _g11;
		HX_STACK_LINE(151)
		Dynamic _g2 = cpo->m_entity->AddComponent(hx::ClassOf< ::haxor::component::CameraOrbitInput >());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(151)
		this->ci0 = _g2;
		HX_STACK_LINE(152)
		this->ci0->set_name(HX_CSTRING("C0"));
		HX_STACK_LINE(153)
		this->ci0->zoomSpeed = 1.0;
		HX_STACK_LINE(154)
		cpo->smooth = 5.0;

		HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,_g)
		Void run(){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","Main.hx",156,0x087e5c05)
			{
				HX_STACK_LINE(156)
				_g->__get((int)0).StaticCast< ::Main >()->ci0->set_enabled(false);
			}
			return null();
		}
		HX_END_LOCAL_FUNC0((void))

		HX_STACK_LINE(156)
		::haxor::thread::Activity_obj::Delay(1.0, Dynamic(new _Function_1_1(_g)),null(),null());
		HX_STACK_LINE(159)
		::haxor::component::Camera _g3 = this->orbit->get_camera();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(159)
		this->cam = _g3;
		HX_STACK_LINE(160)
		{
			HX_STACK_LINE(160)
			::haxor::component::Camera _this = this->cam;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(160)
			_this->m_far = 1000.0;
			HX_STACK_LINE(160)
			_this->m_projection_dirty = true;
			HX_STACK_LINE(160)
			_this->m_proj_uniform_dirty = true;
			HX_STACK_LINE(160)
			1000.0;
		}
		HX_STACK_LINE(161)
		::haxor::math::Color _g4 = ::haxor::math::Color_obj::__new(0.3,0.3,0.3,null());		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(161)
		this->cam->background = _g4;
		HX_STACK_LINE(164)
		::haxor::component::CameraOrbit _g5 = ::haxor::component::CameraOrbit_obj::Create(-1.0,(int)0,(int)0);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(164)
		cpo = _g5;
		HX_STACK_LINE(165)
		::haxor::component::Camera _g6 = cpo->get_camera();		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(165)
		this->fc = _g6;
		HX_STACK_LINE(166)
		this->fc->clear = ::haxor::core::ClearFlag_obj::None;
		HX_STACK_LINE(167)
		{
			HX_STACK_LINE(167)
			::haxor::component::Camera _this = this->fc;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(167)
			_this->m_near = 1.0;
			HX_STACK_LINE(167)
			_this->m_projection_dirty = true;
			HX_STACK_LINE(167)
			_this->m_proj_uniform_dirty = true;
			HX_STACK_LINE(167)
			1.0;
		}
		HX_STACK_LINE(168)
		{
			HX_STACK_LINE(168)
			::haxor::component::Camera _this = this->fc;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(168)
			_this->m_far = 12.0;
			HX_STACK_LINE(168)
			_this->m_projection_dirty = true;
			HX_STACK_LINE(168)
			_this->m_proj_uniform_dirty = true;
			HX_STACK_LINE(168)
			12.0;
		}
		HX_STACK_LINE(169)
		{
			HX_STACK_LINE(169)
			::haxor::component::Camera _this = this->fc;		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(169)
			_this->m_fov = (int)40;
			HX_STACK_LINE(169)
			_this->m_projection_dirty = true;
			HX_STACK_LINE(169)
			(int)40;
		}
		HX_STACK_LINE(171)
		Dynamic _g7 = cpo->m_entity->AddComponent(hx::ClassOf< ::haxor::component::CameraOrbitInput >());		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(171)
		this->ci1 = _g7;
		HX_STACK_LINE(172)
		this->ci1->set_name(HX_CSTRING("C1"));
		HX_STACK_LINE(173)
		this->ci1->zoomSpeed = 1.0;
		HX_STACK_LINE(174)
		cpo->smooth = 5.0;
		HX_STACK_LINE(176)
		::haxor::graphics::material::Material mat;		HX_STACK_VAR(mat,"mat");
		HX_STACK_LINE(176)
		{
			HX_STACK_LINE(176)
			bool p_ztest = true;		HX_STACK_VAR(p_ztest,"p_ztest");
			HX_STACK_LINE(176)
			bool p_zwrite = true;		HX_STACK_VAR(p_zwrite,"p_zwrite");
			HX_STACK_LINE(176)
			bool p_double_sided = false;		HX_STACK_VAR(p_double_sided,"p_double_sided");
			HX_STACK_LINE(176)
			::haxor::graphics::material::Material m = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Transparent"));		HX_STACK_VAR(m,"m");
			HX_STACK_LINE(176)
			if ((p_double_sided)){
				HX_STACK_LINE(176)
				m->cull = (int)0;
			}
			HX_STACK_LINE(176)
			m->SetBlending((int)770,(int)771);
			HX_STACK_LINE(176)
			::haxor::graphics::material::Shader _g10;		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(176)
			if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
				HX_STACK_LINE(176)
				::haxor::graphics::material::Shader _g8 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(176)
				_g10 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g8;
			}
			else{
				HX_STACK_LINE(176)
				_g10 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
			}
			HX_STACK_LINE(176)
			m->set_shader(_g10);
			HX_STACK_LINE(176)
			m->queue = (int)2000;
			HX_STACK_LINE(176)
			m->ztest = p_ztest;
			HX_STACK_LINE(176)
			m->zwrite = p_zwrite;
			HX_STACK_LINE(176)
			m->blend = true;
			HX_STACK_LINE(176)
			mat = m;
		}
		HX_STACK_LINE(177)
		{
			HX_STACK_LINE(177)
			::haxor::math::Color p_color = ::haxor::math::Color_obj::__new(1.0,(int)0,(int)0,(int)1);		HX_STACK_VAR(p_color,"p_color");
			HX_STACK_LINE(177)
			mat->SetFloat4(HX_CSTRING("Tint"),p_color->r,p_color->g,p_color->b,p_color->a);
		}
		HX_STACK_LINE(179)
		{
			HX_STACK_LINE(179)
			int _g8 = (int)0;		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(179)
			while((true)){
				HX_STACK_LINE(179)
				if ((!(((_g8 < (int)1))))){
					HX_STACK_LINE(179)
					break;
				}
				HX_STACK_LINE(179)
				int i = (_g8)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(181)
				::haxor::component::MeshRenderer mr = ::haxor::core::Entity_obj::__new((HX_CSTRING("cube") + i))->AddComponent(hx::ClassOf< ::haxor::component::MeshRenderer >());		HX_STACK_VAR(mr,"mr");
				HX_STACK_LINE(182)
				::haxor::graphics::mesh::Mesh _g111 = ::haxor::graphics::mesh::Model_obj::get_cube();		HX_STACK_VAR(_g111,"_g111");
				HX_STACK_LINE(182)
				mr->set_mesh(_g111);
				HX_STACK_LINE(183)
				mr->set_material(mat);
				HX_STACK_LINE(184)
				Float _g12 = ::Math_obj::random();		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(184)
				Float _g13 = (_g12 - 0.499995);		HX_STACK_VAR(_g13,"_g13");
				HX_STACK_LINE(184)
				Float _g14 = (_g13 * 2.0);		HX_STACK_VAR(_g14,"_g14");
				HX_STACK_LINE(184)
				Float _g15 = ::Math_obj::random();		HX_STACK_VAR(_g15,"_g15");
				HX_STACK_LINE(184)
				Float _g16 = (_g15 - 0.499995);		HX_STACK_VAR(_g16,"_g16");
				HX_STACK_LINE(184)
				Float _g17 = (_g16 * 2.0);		HX_STACK_VAR(_g17,"_g17");
				HX_STACK_LINE(184)
				Float _g18 = ::Math_obj::random();		HX_STACK_VAR(_g18,"_g18");
				HX_STACK_LINE(184)
				Float _g19 = (_g18 - 0.499995);		HX_STACK_VAR(_g19,"_g19");
				HX_STACK_LINE(184)
				Float _g20 = (_g19 * 2.0);		HX_STACK_VAR(_g20,"_g20");
				HX_STACK_LINE(184)
				Float _g21 = ::Math_obj::random();		HX_STACK_VAR(_g21,"_g21");
				HX_STACK_LINE(184)
				::haxor::math::Vector3 _g22 = ::haxor::math::Vector3_obj::__new(_g14,_g17,_g20)->Normalize()->Scale(_g21)->Scale(15.0);		HX_STACK_VAR(_g22,"_g22");
				HX_STACK_LINE(184)
				mr->m_entity->m_transform->set_localScale(_g22);
				HX_STACK_LINE(185)
				Float _g23 = ::Math_obj::random();		HX_STACK_VAR(_g23,"_g23");
				HX_STACK_LINE(185)
				Float _g24 = (_g23 - 0.499995);		HX_STACK_VAR(_g24,"_g24");
				HX_STACK_LINE(185)
				Float _g25 = (_g24 * 2.0);		HX_STACK_VAR(_g25,"_g25");
				HX_STACK_LINE(185)
				Float _g26 = ::Math_obj::random();		HX_STACK_VAR(_g26,"_g26");
				HX_STACK_LINE(185)
				Float _g27 = (_g26 - 0.499995);		HX_STACK_VAR(_g27,"_g27");
				HX_STACK_LINE(185)
				Float _g28 = (_g27 * 2.0);		HX_STACK_VAR(_g28,"_g28");
				HX_STACK_LINE(185)
				Float _g29 = ::Math_obj::random();		HX_STACK_VAR(_g29,"_g29");
				HX_STACK_LINE(185)
				Float _g30 = (_g29 - 0.499995);		HX_STACK_VAR(_g30,"_g30");
				HX_STACK_LINE(185)
				Float _g31 = (_g30 * 2.0);		HX_STACK_VAR(_g31,"_g31");
				HX_STACK_LINE(185)
				Float _g32 = ::Math_obj::random();		HX_STACK_VAR(_g32,"_g32");
				HX_STACK_LINE(185)
				::haxor::math::Vector3 _g33 = ::haxor::math::Vector3_obj::__new(_g25,_g28,_g31)->Normalize()->Scale(_g32)->Scale(40.0);		HX_STACK_VAR(_g33,"_g33");
				HX_STACK_LINE(185)
				mr->m_entity->m_transform->set_localPosition(_g33);
				HX_STACK_LINE(186)
				Float _g34 = ::Math_obj::random();		HX_STACK_VAR(_g34,"_g34");
				HX_STACK_LINE(186)
				Float _g35 = (_g34 - 0.499995);		HX_STACK_VAR(_g35,"_g35");
				HX_STACK_LINE(186)
				Float _g36 = (_g35 * 2.0);		HX_STACK_VAR(_g36,"_g36");
				HX_STACK_LINE(186)
				Float _g37 = ::Math_obj::random();		HX_STACK_VAR(_g37,"_g37");
				HX_STACK_LINE(186)
				Float _g38 = (_g37 - 0.499995);		HX_STACK_VAR(_g38,"_g38");
				HX_STACK_LINE(186)
				Float _g39 = (_g38 * 2.0);		HX_STACK_VAR(_g39,"_g39");
				HX_STACK_LINE(186)
				Float _g40 = ::Math_obj::random();		HX_STACK_VAR(_g40,"_g40");
				HX_STACK_LINE(186)
				Float _g41 = (_g40 - 0.499995);		HX_STACK_VAR(_g41,"_g41");
				HX_STACK_LINE(186)
				Float _g42 = (_g41 * 2.0);		HX_STACK_VAR(_g42,"_g42");
				HX_STACK_LINE(186)
				::haxor::math::Vector3 _g43 = ::haxor::math::Vector3_obj::__new(_g36,_g39,_g42)->Normalize();		HX_STACK_VAR(_g43,"_g43");
				HX_STACK_LINE(186)
				Float _g44 = ::haxor::math::Random_obj::Range((int)0,(int)360);		HX_STACK_VAR(_g44,"_g44");
				HX_STACK_LINE(186)
				::haxor::math::Quaternion _g45 = ::haxor::math::Quaternion_obj::FromAxisAngle(_g43,_g44);		HX_STACK_VAR(_g45,"_g45");
				HX_STACK_LINE(186)
				mr->m_entity->m_transform->set_localRotation(_g45);
			}
		}
		HX_STACK_LINE(189)
		::haxor::core::Debug_obj::renderer = true;
		HX_STACK_LINE(190)
		::haxor::core::Debug_obj::rendererAABB = true;
	}
return null();
}


Void Main_obj::OnUpdate( ){
{
		HX_STACK_FRAME("Main","OnUpdate",0x876cdf5d,"Main.OnUpdate","Main.hx",198,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(199)
		if (((this->ci0 == null()))){
			HX_STACK_LINE(199)
			return null();
		}
		HX_STACK_LINE(200)
		::String log = HX_CSTRING("");		HX_STACK_VAR(log,"log");
		HX_STACK_LINE(202)
		hx::AddEq(log,HX_CSTRING("Stats"));
		HX_STACK_LINE(203)
		::String _g = ::Std_obj::string(::haxor::component::Camera_obj::SAPCulling);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(203)
		::String _g1 = (HX_CSTRING("\nSAP: ") + _g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(203)
		hx::AddEq(log,_g1);
		HX_STACK_LINE(204)
		hx::AddEq(log,(HX_CSTRING("\nVisible: ") + ::haxor::core::RenderStats_obj::visible));
		HX_STACK_LINE(205)
		hx::AddEq(log,(HX_CSTRING("\nCulled: ") + ::haxor::core::RenderStats_obj::culled));
		HX_STACK_LINE(206)
		int _g2 = ::haxor::core::RenderStats_obj::get_total();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(206)
		::String _g3 = (HX_CSTRING("\nActive: ") + _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(206)
		hx::AddEq(log,_g3);
		HX_STACK_LINE(207)
		hx::AddEq(log,(HX_CSTRING("\nRenderers: ") + ::haxor::core::RenderStats_obj::renderers));
		HX_STACK_LINE(208)
		hx::AddEq(log,(HX_CSTRING("\nTris: ") + ::haxor::core::RenderStats_obj::triangles));
		HX_STACK_LINE(209)
		bool _g4 = this->ci0->get_enabled();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(209)
		::String _g5 = ::Std_obj::string(_g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(209)
		::String _g6 = (HX_CSTRING("\nInput0: ") + _g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(209)
		hx::AddEq(log,_g6);
		HX_STACK_LINE(210)
		bool _g7 = this->ci1->get_enabled();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(210)
		::String _g8 = ::Std_obj::string(_g7);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(210)
		::String _g9 = (HX_CSTRING("\nInput1: ") + _g8);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(210)
		hx::AddEq(log,_g9);
		HX_STACK_LINE(222)
		if ((::haxor::input::Input_obj::Down(::haxor::input::KeyCode_obj::A))){
			HX_STACK_LINE(224)
			::haxor::component::Camera_obj::SAPCulling = !(::haxor::component::Camera_obj::SAPCulling);
		}
		HX_STACK_LINE(227)
		if ((::haxor::input::Input_obj::Down(::haxor::input::KeyCode_obj::Q))){
			HX_STACK_LINE(229)
			bool _g10 = !(this->ci0->get_enabled());		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(229)
			this->ci0->set_enabled(_g10);
			HX_STACK_LINE(230)
			bool _g11 = !(this->ci1->get_enabled());		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(230)
			this->ci1->set_enabled(_g11);
		}
		HX_STACK_LINE(233)
		if (((this->tp == null()))){
			HX_STACK_LINE(235)
			this->tp = Array_obj< ::Dynamic >::__new();
			HX_STACK_LINE(236)
			{
				HX_STACK_LINE(236)
				int _g10 = (int)0;		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(236)
				while((true)){
					HX_STACK_LINE(236)
					if ((!(((_g10 < (int)12))))){
						HX_STACK_LINE(236)
						break;
					}
					HX_STACK_LINE(236)
					int i = (_g10)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(237)
					int _g11 = (int)0;		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(237)
					while((true)){
						HX_STACK_LINE(237)
						if ((!(((_g11 < (int)12))))){
							HX_STACK_LINE(237)
							break;
						}
						HX_STACK_LINE(237)
						int j = (_g11)++;		HX_STACK_VAR(j,"j");
						HX_STACK_LINE(238)
						int _g21 = (int)0;		HX_STACK_VAR(_g21,"_g21");
						HX_STACK_LINE(238)
						while((true)){
							HX_STACK_LINE(238)
							if ((!(((_g21 < (int)12))))){
								HX_STACK_LINE(238)
								break;
							}
							HX_STACK_LINE(238)
							int k = (_g21)++;		HX_STACK_VAR(k,"k");
							HX_STACK_LINE(240)
							::haxor::math::Vector3 p = ::haxor::math::Vector3_obj::__new((i - (int)6),(j - (int)6),(k - (int)6))->Scale(1.0);		HX_STACK_VAR(p,"p");
							HX_STACK_LINE(241)
							this->tp->push(p);
						}
					}
				}
			}
		}
		HX_STACK_LINE(246)
		if (((this->fc != null()))){
			HX_STACK_LINE(248)
			::haxor::core::Debug_obj::Camera(this->fc);
			HX_STACK_LINE(249)
			::haxor::core::Debug_obj::BoundingAABB(this->fc->m_aabb);
		}
		HX_STACK_LINE(269)
		::String _g12 = ::StringTools_obj::replace(((log + HX_CSTRING(" FPS: ")) + ::haxor::core::Time_obj::m_fps),HX_CSTRING("\n"),HX_CSTRING(" "));		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(269)
		this->get_application()->get_window()->set_title(_g12);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnUpdate,(void))

Void Main_obj::OnRender( ){
{
		HX_STACK_FRAME("Main","OnRender",0x0590c4aa,"Main.OnRender","Main.hx",281,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(281)
		::haxor::math::Color p_color = ::haxor::math::Color_obj::__new((int)1,(int)1,(int)1,0.1);		HX_STACK_VAR(p_color,"p_color");
		HX_STACK_LINE(281)
		::haxor::context::EngineContext_obj::gizmo->DrawGrid(100.0,p_color);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnRender,(void))

Void Main_obj::main( ){
{
		HX_STACK_FRAME("Main","main",0xed0e206e,"Main.main","Main.hx",95,0x087e5c05)
		HX_STACK_LINE(95)
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
	HX_MARK_MEMBER_NAME(fc,"fc");
	HX_MARK_MEMBER_NAME(cp,"cp");
	HX_MARK_MEMBER_NAME(ci0,"ci0");
	HX_MARK_MEMBER_NAME(ci1,"ci1");
	HX_MARK_MEMBER_NAME(obj,"obj");
	HX_MARK_MEMBER_NAME(tp,"tp");
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
	HX_VISIT_MEMBER_NAME(fc,"fc");
	HX_VISIT_MEMBER_NAME(cp,"cp");
	HX_VISIT_MEMBER_NAME(ci0,"ci0");
	HX_VISIT_MEMBER_NAME(ci1,"ci1");
	HX_VISIT_MEMBER_NAME(obj,"obj");
	HX_VISIT_MEMBER_NAME(tp,"tp");
	::haxor::platform::windows::WinApplication_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"fc") ) { return fc; }
		if (HX_FIELD_EQ(inName,"cp") ) { return cp; }
		if (HX_FIELD_EQ(inName,"tp") ) { return tp; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"cam") ) { return cam; }
		if (HX_FIELD_EQ(inName,"mat") ) { return mat; }
		if (HX_FIELD_EQ(inName,"ci0") ) { return ci0; }
		if (HX_FIELD_EQ(inName,"ci1") ) { return ci1; }
		if (HX_FIELD_EQ(inName,"obj") ) { return obj; }
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
		if (HX_FIELD_EQ(inName,"fc") ) { fc=inValue.Cast< ::haxor::component::Camera >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cp") ) { cp=inValue.Cast< ::haxor::component::Transform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tp") ) { tp=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"cam") ) { cam=inValue.Cast< ::haxor::component::Camera >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mat") ) { mat=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ci0") ) { ci0=inValue.Cast< ::haxor::component::CameraOrbitInput >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ci1") ) { ci1=inValue.Cast< ::haxor::component::CameraOrbitInput >(); return inValue; }
		if (HX_FIELD_EQ(inName,"obj") ) { obj=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
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
	outFields->push(HX_CSTRING("fc"));
	outFields->push(HX_CSTRING("cp"));
	outFields->push(HX_CSTRING("ci0"));
	outFields->push(HX_CSTRING("ci1"));
	outFields->push(HX_CSTRING("obj"));
	outFields->push(HX_CSTRING("tp"));
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
	{hx::fsObject /*::haxor::component::Camera*/ ,(int)offsetof(Main_obj,fc),HX_CSTRING("fc")},
	{hx::fsObject /*::haxor::component::Transform*/ ,(int)offsetof(Main_obj,cp),HX_CSTRING("cp")},
	{hx::fsObject /*::haxor::component::CameraOrbitInput*/ ,(int)offsetof(Main_obj,ci0),HX_CSTRING("ci0")},
	{hx::fsObject /*::haxor::component::CameraOrbitInput*/ ,(int)offsetof(Main_obj,ci1),HX_CSTRING("ci1")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Main_obj,obj),HX_CSTRING("obj")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Main_obj,tp),HX_CSTRING("tp")},
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
	HX_CSTRING("fc"),
	HX_CSTRING("cp"),
	HX_CSTRING("ci0"),
	HX_CSTRING("ci1"),
	HX_CSTRING("Load"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("obj"),
	HX_CSTRING("tp"),
	HX_CSTRING("OnUpdate"),
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

