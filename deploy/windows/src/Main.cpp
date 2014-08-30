#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
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
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_Time
#include <haxor/core/Time.h>
#endif
#ifndef INCLUDED_haxor_graphics_GL
#include <haxor/graphics/GL.h>
#endif
#ifndef INCLUDED_haxor_graphics_GraphicContext
#include <haxor/graphics/GraphicContext.h>
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
#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#include <haxor/graphics/texture/Bitmap.h>
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
#ifndef INCLUDED_haxor_input_Joystick
#include <haxor/input/Joystick.h>
#endif
#ifndef INCLUDED_haxor_io_file_Asset
#include <haxor/io/file/Asset.h>
#endif
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
#ifndef INCLUDED_haxor_math_Vector2
#include <haxor/math/Vector2.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_net_Web
#include <haxor/net/Web.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_Entry
#include <haxor/platform/windows/Entry.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_WinApplication
#include <haxor/platform/windows/WinApplication.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_graphics_WinGL
#include <haxor/platform/windows/graphics/WinGL.h>
#endif
#ifndef INCLUDED_haxor_thread_Activity
#include <haxor/thread/Activity.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_FRAME("Main","new",0x6616a5cb,"Main.new","Main.hx",63,0x087e5c05)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(63)
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
	HX_STACK_FRAME("Main","Load",0xd748ae7b,"Main.Load","Main.hx",94,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_LINE(93)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(95)
	::haxor::net::Web_obj::root = HX_CSTRING("http://haxor.thelaborat.org/resources/");

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,_g)
	Void run(::haxor::graphics::texture::Texture2D t,Float p){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","Main.hx",99,0x087e5c05)
		HX_STACK_ARG(t,"t")
		HX_STACK_ARG(p,"p")
		{
			HX_STACK_LINE(99)
			if (((p >= 1.0))){
				HX_STACK_LINE(101)
				::haxor::io::file::Asset_obj::Add(HX_CSTRING("texture"),t);
				HX_STACK_LINE(102)
				_g->__get((int)0).StaticCast< ::Main >()->LoadComplete();
			}
		}
		return null();
	}
	HX_END_LOCAL_FUNC2((void))

	HX_STACK_LINE(97)
	::haxor::net::Web_obj::LoadTexture2D(HX_CSTRING("./texture/misc/metal.jpg"),true, Dynamic(new _Function_1_1(_g)));
	HX_STACK_LINE(153)
	return false;
}


Void Main_obj::Initialize( ){
{
		HX_STACK_FRAME("Main","Initialize",0x7af3b365,"Main.Initialize","Main.hx",157,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(156)
		Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(158)
		::haxor::core::Console_obj::Log(HX_CSTRING("Initialize!"),null());
		HX_STACK_LINE(174)
		::haxor::component::CameraOrbit _g1 = ::haxor::component::CameraOrbit_obj::Create(3.0,(int)45,(int)45);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(174)
		this->orbit = _g1;
		HX_STACK_LINE(175)
		Dynamic _g11 = this->orbit->m_entity->GetComponentInChildren(hx::ClassOf< ::haxor::component::Camera >());		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(175)
		this->cam = _g11;
		HX_STACK_LINE(176)
		::haxor::math::Color _g2 = ::haxor::math::Color_obj::__new(0.3,0.3,0.3,null());		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(176)
		this->cam->background = _g2;
		HX_STACK_LINE(178)
		::haxor::graphics::texture::Texture2D tex = ::haxor::graphics::texture::Texture2D_obj::get_green();		HX_STACK_VAR(tex,"tex");
		HX_STACK_LINE(179)
		Dynamic _g3 = ::haxor::io::file::Asset_obj::Get(HX_CSTRING("texture"));		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(179)
		tex = _g3;
		HX_STACK_LINE(181)
		::haxor::component::Transform _g4;		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(181)
		{
			HX_STACK_LINE(181)
			::haxor::core::Entity _this = ::haxor::core::Entity_obj::__new(HX_CSTRING("container"));		HX_STACK_VAR(_this,"_this");
			HX_STACK_LINE(181)
			_g4 = _this->m_transform;
		}
		HX_STACK_LINE(181)
		this->container = _g4;
		HX_STACK_LINE(182)
		Array< Float > l = Array_obj< Float >::__new().Add((int)2);		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(184)
		Array< Float > px = Array_obj< Float >::__new().Add(0.0);		HX_STACK_VAR(px,"px");
		HX_STACK_LINE(185)
		Array< Float > py = Array_obj< Float >::__new().Add(0.0);		HX_STACK_VAR(py,"py");
		HX_STACK_LINE(186)
		Array< Float > pz = Array_obj< Float >::__new().Add(0.0);		HX_STACK_VAR(pz,"pz");
		HX_STACK_LINE(188)
		::haxor::graphics::material::Material _g8;		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(188)
		{
			HX_STACK_LINE(188)
			::haxor::graphics::texture::Texture p_texture = ::haxor::io::file::Asset_obj::Get(HX_CSTRING("texture"));		HX_STACK_VAR(p_texture,"p_texture");
			HX_STACK_LINE(188)
			bool p_ztest = true;		HX_STACK_VAR(p_ztest,"p_ztest");
			HX_STACK_LINE(188)
			bool p_zwrite = true;		HX_STACK_VAR(p_zwrite,"p_zwrite");
			HX_STACK_LINE(188)
			bool p_double_sided = false;		HX_STACK_VAR(p_double_sided,"p_double_sided");
			HX_STACK_LINE(188)
			::haxor::graphics::material::Material m = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("Transparent"));		HX_STACK_VAR(m,"m");
			HX_STACK_LINE(188)
			if ((p_double_sided)){
				HX_STACK_LINE(188)
				m->cull = (int)0;
			}
			HX_STACK_LINE(188)
			m->SetBlending((int)770,(int)771);
			HX_STACK_LINE(188)
			::haxor::graphics::material::Shader _g7;		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(188)
			if (((p_texture == null()))){
				HX_STACK_LINE(188)
				if (((::haxor::graphics::material::Shader_obj::m_flat_shader == null()))){
					HX_STACK_LINE(188)
					::haxor::graphics::material::Shader _g5 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_source);		HX_STACK_VAR(_g5,"_g5");
					HX_STACK_LINE(188)
					_g7 = ::haxor::graphics::material::Shader_obj::m_flat_shader = _g5;
				}
				else{
					HX_STACK_LINE(188)
					_g7 = ::haxor::graphics::material::Shader_obj::m_flat_shader;
				}
			}
			else{
				HX_STACK_LINE(188)
				if (((::haxor::graphics::material::Shader_obj::m_flat_texture_shader == null()))){
					HX_STACK_LINE(188)
					::haxor::graphics::material::Shader _g6 = ::haxor::graphics::material::Shader_obj::__new(::haxor::context::ShaderContext_obj::flat_texture_source);		HX_STACK_VAR(_g6,"_g6");
					HX_STACK_LINE(188)
					_g7 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader = _g6;
				}
				else{
					HX_STACK_LINE(188)
					_g7 = ::haxor::graphics::material::Shader_obj::m_flat_texture_shader;
				}
			}
			HX_STACK_LINE(188)
			m->set_shader(_g7);
			HX_STACK_LINE(188)
			m->queue = (int)2000;
			HX_STACK_LINE(188)
			m->ztest = p_ztest;
			HX_STACK_LINE(188)
			m->zwrite = p_zwrite;
			HX_STACK_LINE(188)
			m->blend = true;
			HX_STACK_LINE(188)
			if (((p_texture != null()))){
				HX_STACK_LINE(188)
				m->SetTexture(HX_CSTRING("DiffuseTexture"),p_texture);
			}
			HX_STACK_LINE(188)
			_g8 = m;
		}
		HX_STACK_LINE(188)
		this->mat = _g8;
		HX_STACK_LINE(189)
		this->mat->set_name(HX_CSTRING("T"));
		HX_STACK_LINE(190)
		::haxor::graphics::texture::Texture2D _g9 = ::haxor::graphics::texture::Texture2D_obj::get_red();		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(190)
		this->mat->SetTexture(HX_CSTRING("Tex0"),_g9);
		HX_STACK_LINE(191)
		this->mat->blend = true;

		HX_BEGIN_LOCAL_FUNC_S5(hx::LocalFunc,_Function_1_1,Array< ::Dynamic >,_g,Array< Float >,pz,Array< Float >,px,Array< Float >,l,Array< Float >,py)
		bool run(int i){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","Main.hx",195,0x087e5c05)
			HX_STACK_ARG(i,"i")
			{
				HX_STACK_LINE(196)
				_g->__get((int)0).StaticCast< ::Main >()->mr = ::haxor::core::Entity_obj::__new((HX_CSTRING("cube") + i))->AddComponent(hx::ClassOf< ::haxor::component::MeshRenderer >());
				HX_STACK_LINE(197)
				_g->__get((int)0).StaticCast< ::Main >()->mr->m_entity->m_transform->set_localScale(::haxor::math::Vector3_obj::__new(0.1,0.1,0.1));
				HX_STACK_LINE(198)
				_g->__get((int)0).StaticCast< ::Main >()->mr->m_entity->m_transform->set_parent(_g->__get((int)0).StaticCast< ::Main >()->container);
				HX_STACK_LINE(199)
				_g->__get((int)0).StaticCast< ::Main >()->mr->m_entity->m_transform->set_position(::haxor::math::Vector3_obj::__new(px->__get((int)0),py->__get((int)0),pz->__get((int)0)));
				HX_STACK_LINE(200)
				_g->__get((int)0).StaticCast< ::Main >()->mr->set_mesh(::haxor::graphics::mesh::Model_obj::get_cube());
				HX_STACK_LINE(202)
				_g->__get((int)0).StaticCast< ::Main >()->mr->set_material(_g->__get((int)0).StaticCast< ::Main >()->mat);
				HX_STACK_LINE(204)
				hx::AddEq(px[(int)0],0.12);
				HX_STACK_LINE(206)
				if (((px->__get((int)0) >= l->__get((int)0)))){
					HX_STACK_LINE(208)
					px[(int)0] = 0.0;
					HX_STACK_LINE(209)
					hx::AddEq(pz[(int)0],0.12);
					HX_STACK_LINE(210)
					if (((pz->__get((int)0) >= l->__get((int)0)))){
						HX_STACK_LINE(212)
						pz[(int)0] = 0.0;
						HX_STACK_LINE(213)
						hx::AddEq(py[(int)0],0.12);
					}
				}
				HX_STACK_LINE(217)
				return true;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(193)
		::haxor::thread::Activity_obj::Iterate((int)0,(int)200, Dynamic(new _Function_1_1(_g,pz,px,l,py)),(int)50,null(),null());
	}
return null();
}


Void Main_obj::OnUpdate( ){
{
		HX_STACK_FRAME("Main","OnUpdate",0x876cdf5d,"Main.OnUpdate","Main.hx",223,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(224)
		if (((this->orbit != null()))){
			HX_STACK_LINE(226)
			hx::AddEq(this->orbit->angle->x,(::haxor::core::Time_obj::m_delta * 30.0));
		}
		HX_STACK_LINE(229)
		::String log = HX_CSTRING("");		HX_STACK_VAR(log,"log");
		HX_STACK_LINE(232)
		if ((::haxor::input::Joystick_obj::available)){
			HX_STACK_LINE(234)
			Array< ::Dynamic > _g = ::haxor::input::Input_obj::get_joystick();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(234)
			::String _g1 = _g->__get((int)0).StaticCast< ::haxor::input::Joystick >()->ToString(null(),null(),null(),null());		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(234)
			::haxe::Log_obj::trace(_g1,hx::SourceInfo(HX_CSTRING("Main.hx"),234,HX_CSTRING("Main"),HX_CSTRING("OnUpdate")));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnUpdate,(void))

Void Main_obj::OnRender( ){
{
		HX_STACK_FRAME("Main","OnRender",0x0590c4aa,"Main.OnRender","Main.hx",247,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(248)
		::haxor::graphics::GL_obj::m_gl->Clear((int)256);
		HX_STACK_LINE(249)
		{
			HX_STACK_LINE(249)
			::haxor::math::Color p_color = ::haxor::math::Color_obj::__new((int)1,(int)1,(int)1,0.1);		HX_STACK_VAR(p_color,"p_color");
			HX_STACK_LINE(249)
			::haxor::context::EngineContext_obj::gizmo->DrawGrid(100.0,p_color);
		}
		HX_STACK_LINE(250)
		::haxor::context::EngineContext_obj::gizmo->DrawAxis(50.0);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnRender,(void))

Void Main_obj::main( ){
{
		HX_STACK_FRAME("Main","main",0xed0e206e,"Main.main","Main.hx",68,0x087e5c05)
		HX_STACK_LINE(68)
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
	HX_MARK_MEMBER_NAME(mesh,"mesh");
	HX_MARK_MEMBER_NAME(cam,"cam");
	HX_MARK_MEMBER_NAME(orbit,"orbit");
	HX_MARK_MEMBER_NAME(mr,"mr");
	HX_MARK_MEMBER_NAME(container,"container");
	HX_MARK_MEMBER_NAME(mat,"mat");
	HX_MARK_MEMBER_NAME(ss,"ss");
	HX_MARK_MEMBER_NAME(tex,"tex");
	HX_MARK_MEMBER_NAME(bmp,"bmp");
	::haxor::platform::windows::WinApplication_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mesh,"mesh");
	HX_VISIT_MEMBER_NAME(cam,"cam");
	HX_VISIT_MEMBER_NAME(orbit,"orbit");
	HX_VISIT_MEMBER_NAME(mr,"mr");
	HX_VISIT_MEMBER_NAME(container,"container");
	HX_VISIT_MEMBER_NAME(mat,"mat");
	HX_VISIT_MEMBER_NAME(ss,"ss");
	HX_VISIT_MEMBER_NAME(tex,"tex");
	HX_VISIT_MEMBER_NAME(bmp,"bmp");
	::haxor::platform::windows::WinApplication_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"mr") ) { return mr; }
		if (HX_FIELD_EQ(inName,"ss") ) { return ss; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"cam") ) { return cam; }
		if (HX_FIELD_EQ(inName,"mat") ) { return mat; }
		if (HX_FIELD_EQ(inName,"tex") ) { return tex; }
		if (HX_FIELD_EQ(inName,"bmp") ) { return bmp; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"mesh") ) { return mesh; }
		if (HX_FIELD_EQ(inName,"Load") ) { return Load_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"orbit") ) { return orbit; }
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
		if (HX_FIELD_EQ(inName,"mr") ) { mr=inValue.Cast< ::haxor::component::MeshRenderer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ss") ) { ss=inValue.Cast< ::String >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"cam") ) { cam=inValue.Cast< ::haxor::component::Camera >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mat") ) { mat=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tex") ) { tex=inValue.Cast< ::haxor::graphics::texture::Texture2D >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bmp") ) { bmp=inValue.Cast< ::haxor::graphics::texture::Bitmap >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mesh") ) { mesh=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"orbit") ) { orbit=inValue.Cast< ::haxor::component::CameraOrbit >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"container") ) { container=inValue.Cast< ::haxor::component::Transform >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mesh"));
	outFields->push(HX_CSTRING("cam"));
	outFields->push(HX_CSTRING("orbit"));
	outFields->push(HX_CSTRING("mr"));
	outFields->push(HX_CSTRING("container"));
	outFields->push(HX_CSTRING("mat"));
	outFields->push(HX_CSTRING("ss"));
	outFields->push(HX_CSTRING("tex"));
	outFields->push(HX_CSTRING("bmp"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::graphics::mesh::Mesh*/ ,(int)offsetof(Main_obj,mesh),HX_CSTRING("mesh")},
	{hx::fsObject /*::haxor::component::Camera*/ ,(int)offsetof(Main_obj,cam),HX_CSTRING("cam")},
	{hx::fsObject /*::haxor::component::CameraOrbit*/ ,(int)offsetof(Main_obj,orbit),HX_CSTRING("orbit")},
	{hx::fsObject /*::haxor::component::MeshRenderer*/ ,(int)offsetof(Main_obj,mr),HX_CSTRING("mr")},
	{hx::fsObject /*::haxor::component::Transform*/ ,(int)offsetof(Main_obj,container),HX_CSTRING("container")},
	{hx::fsObject /*::haxor::graphics::material::Material*/ ,(int)offsetof(Main_obj,mat),HX_CSTRING("mat")},
	{hx::fsString,(int)offsetof(Main_obj,ss),HX_CSTRING("ss")},
	{hx::fsObject /*::haxor::graphics::texture::Texture2D*/ ,(int)offsetof(Main_obj,tex),HX_CSTRING("tex")},
	{hx::fsObject /*::haxor::graphics::texture::Bitmap*/ ,(int)offsetof(Main_obj,bmp),HX_CSTRING("bmp")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("mesh"),
	HX_CSTRING("cam"),
	HX_CSTRING("orbit"),
	HX_CSTRING("mr"),
	HX_CSTRING("container"),
	HX_CSTRING("mat"),
	HX_CSTRING("ss"),
	HX_CSTRING("tex"),
	HX_CSTRING("bmp"),
	HX_CSTRING("Load"),
	HX_CSTRING("Initialize"),
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

