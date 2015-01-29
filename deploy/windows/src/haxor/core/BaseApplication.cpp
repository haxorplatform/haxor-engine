#include <hxcpp.h>

#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_core_ApplicationProtocol
#include <haxor/core/ApplicationProtocol.h>
#endif
#ifndef INCLUDED_haxor_core_BaseApplication
#include <haxor/core/BaseApplication.h>
#endif
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_haxor_core_Engine
#include <haxor/core/Engine.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Platform
#include <haxor/core/Platform.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_core_Scene
#include <haxor/core/Scene.h>
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
#ifndef INCLUDED_haxor_graphics_Screen
#include <haxor/graphics/Screen.h>
#endif
#ifndef INCLUDED_haxor_input_Input
#include <haxor/input/Input.h>
#endif
#ifndef INCLUDED_haxor_input_InputHandler
#include <haxor/input/InputHandler.h>
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
namespace core{

Void BaseApplication_obj::__construct(::String __o_p_name)
{
HX_STACK_FRAME("haxor.core.BaseApplication","new",0xbadb0a2e,"haxor.core.BaseApplication.new","haxor/core/BaseApplication.hx",56,0x69cdc962)
HX_STACK_THIS(this)
HX_STACK_ARG(__o_p_name,"p_name")
::String p_name = __o_p_name.Default(HX_CSTRING(""));
{
	HX_STACK_LINE(56)
	super::__construct(p_name);
}
;
	return null();
}

//BaseApplication_obj::~BaseApplication_obj() { }

Dynamic BaseApplication_obj::__CreateEmpty() { return  new BaseApplication_obj; }
hx::ObjectPtr< BaseApplication_obj > BaseApplication_obj::__new(::String __o_p_name)
{  hx::ObjectPtr< BaseApplication_obj > result = new BaseApplication_obj();
	result->__construct(__o_p_name);
	return result;}

Dynamic BaseApplication_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BaseApplication_obj > result = new BaseApplication_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::core::ApplicationProtocol BaseApplication_obj::get_protocol( ){
	HX_STACK_FRAME("haxor.core.BaseApplication","get_protocol",0x42b326d3,"haxor.core.BaseApplication.get_protocol","haxor/core/BaseApplication.hx",74,0x69cdc962)
	HX_STACK_THIS(this)
	HX_STACK_LINE(74)
	return ::haxor::core::ApplicationProtocol_obj::None;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,get_protocol,return )

::String BaseApplication_obj::get_vendor( ){
	HX_STACK_FRAME("haxor.core.BaseApplication","get_vendor",0x85781143,"haxor.core.BaseApplication.get_vendor","haxor/core/BaseApplication.hx",82,0x69cdc962)
	HX_STACK_THIS(this)
	HX_STACK_LINE(83)
	if (((this->m_vendor != null()))){
		HX_STACK_LINE(83)
		return this->m_vendor;
	}
	HX_STACK_LINE(92)
	return this->m_vendor = HX_CSTRING("");
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,get_vendor,return )

int BaseApplication_obj::get_fps( ){
	HX_STACK_FRAME("haxor.core.BaseApplication","get_fps",0xa465c94e,"haxor.core.BaseApplication.get_fps","haxor/core/BaseApplication.hx",100,0x69cdc962)
	HX_STACK_THIS(this)
	HX_STACK_LINE(100)
	return this->m_fps;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,get_fps,return )

int BaseApplication_obj::set_fps( int v){
	HX_STACK_FRAME("haxor.core.BaseApplication","set_fps",0x97675a5a,"haxor.core.BaseApplication.set_fps","haxor/core/BaseApplication.hx",102,0x69cdc962)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(103)
	this->m_fps = v;
	HX_STACK_LINE(104)
	Float f = v;		HX_STACK_VAR(f,"f");
	HX_STACK_LINE(112)
	hx::AddEq(f,5.0);
	HX_STACK_LINE(123)
	this->m_mspf = ((Float(1.0) / Float(f)) * 1000.0);
	HX_STACK_LINE(124)
	return v;
}


HX_DEFINE_DYNAMIC_FUNC1(BaseApplication_obj,set_fps,return )

::haxor::core::Platform BaseApplication_obj::get_platform( ){
	HX_STACK_FRAME("haxor.core.BaseApplication","get_platform",0xaa49832e,"haxor.core.BaseApplication.get_platform","haxor/core/BaseApplication.hx",145,0x69cdc962)
	HX_STACK_THIS(this)
	HX_STACK_LINE(145)
	return this->m_platform;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,get_platform,return )

Void BaseApplication_obj::OnBuild( ){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","OnBuild",0x9c1cda3d,"haxor.core.BaseApplication.OnBuild","haxor/core/BaseApplication.hx",163,0x69cdc962)
		HX_STACK_THIS(this)
		HX_STACK_LINE(164)
		this->super::OnBuild();
		HX_STACK_LINE(165)
		::haxor::core::BaseApplication_obj::m_instance = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(166)
		this->m_scenes = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(167)
		this->set_fps((int)60);
		HX_STACK_LINE(168)
		this->m_frame_ms = 0.0;
		HX_STACK_LINE(169)
		this->m_init_allowed = false;
		HX_STACK_LINE(170)
		this->m_platform = ::haxor::core::Platform_obj::Unknown;
		HX_STACK_LINE(171)
		::haxor::core::Time_obj::Initialize();
		HX_STACK_LINE(172)
		::haxor::graphics::Screen_obj::Initialize(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(173)
		::haxor::input::Input_obj::Initialize();
	}
return null();
}


Void BaseApplication_obj::LoadScene( ::String p_name){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","LoadScene",0xcd598d74,"haxor.core.BaseApplication.LoadScene","haxor/core/BaseApplication.hx",181,0x69cdc962)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseApplication_obj,LoadScene,(void))

Void BaseApplication_obj::DestroyScene( ::String p_name){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","DestroyScene",0xc01a3a84,"haxor.core.BaseApplication.DestroyScene","haxor/core/BaseApplication.hx",190,0x69cdc962)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_name,"p_name")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BaseApplication_obj,DestroyScene,(void))

bool BaseApplication_obj::Load( ){
	HX_STACK_FRAME("haxor.core.BaseApplication","Load",0xae5c20b8,"haxor.core.BaseApplication.Load","haxor/core/BaseApplication.hx",198,0x69cdc962)
	HX_STACK_THIS(this)
	HX_STACK_LINE(198)
	return true;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,Load,return )

Void BaseApplication_obj::Initialize( ){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","Initialize",0xd9c5f162,"haxor.core.BaseApplication.Initialize","haxor/core/BaseApplication.hx",206,0x69cdc962)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,Initialize,(void))

Void BaseApplication_obj::LoadComplete( ){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","LoadComplete",0x8e795591,"haxor.core.BaseApplication.LoadComplete","haxor/core/BaseApplication.hx",214,0x69cdc962)
		HX_STACK_THIS(this)
		HX_STACK_LINE(214)
		this->m_init_allowed = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,LoadComplete,(void))

Void BaseApplication_obj::Update( ){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","Update",0x44c6551b,"haxor.core.BaseApplication.Update","haxor/core/BaseApplication.hx",221,0x69cdc962)
		HX_STACK_THIS(this)
		HX_STACK_LINE(222)
		::haxor::core::Time_obj::Update();
		HX_STACK_LINE(223)
		::haxor::input::Input_obj::m_handler->Update();
		HX_STACK_LINE(224)
		this->CheckResize();
		HX_STACK_LINE(225)
		::haxor::core::Engine_obj::Update();
		HX_STACK_LINE(226)
		::haxor::core::Engine_obj::Collect();
		HX_STACK_LINE(227)
		::haxor::input::Input_obj::m_handler->Clear();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,Update,(void))

Void BaseApplication_obj::Render( ){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","Render",0xc2ea3a68,"haxor.core.BaseApplication.Render","haxor/core/BaseApplication.hx",234,0x69cdc962)
		HX_STACK_THIS(this)
		HX_STACK_LINE(235)
		if ((this->m_init_allowed)){
			HX_STACK_LINE(237)
			::haxor::core::Console_obj::Log(HX_CSTRING("Application> Initialize."),(int)3);
			HX_STACK_LINE(238)
			this->Initialize();
			HX_STACK_LINE(239)
			this->m_init_allowed = false;
		}
		HX_STACK_LINE(243)
		if ((((::haxor::core::Time_obj::m_clock - this->m_frame_ms) >= this->m_mspf))){
			HX_STACK_LINE(245)
			hx::AddEq(this->m_frame_ms,(::haxor::core::Time_obj::m_clock - this->m_frame_ms));
			HX_STACK_LINE(247)
			::haxor::core::Time_obj::Render();
			HX_STACK_LINE(250)
			::haxor::graphics::GL_obj::m_gl->Focus();
			HX_STACK_LINE(253)
			::haxor::core::Engine_obj::Render();
			HX_STACK_LINE(256)
			::haxor::graphics::GL_obj::m_gl->Flush();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,Render,(void))

Void BaseApplication_obj::OnQuit( ){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","OnQuit",0xab5517a0,"haxor.core.BaseApplication.OnQuit","haxor/core/BaseApplication.hx",265,0x69cdc962)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,OnQuit,(void))

Void BaseApplication_obj::OnFocus( ){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","OnFocus",0xe5bb5ee7,"haxor.core.BaseApplication.OnFocus","haxor/core/BaseApplication.hx",270,0x69cdc962)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,OnFocus,(void))

Void BaseApplication_obj::OnUnfocus( ){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","OnUnfocus",0x121577ae,"haxor.core.BaseApplication.OnUnfocus","haxor/core/BaseApplication.hx",275,0x69cdc962)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,OnUnfocus,(void))

Void BaseApplication_obj::CheckResize( ){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","CheckResize",0x66ea7c8a,"haxor.core.BaseApplication.CheckResize","haxor/core/BaseApplication.hx",281,0x69cdc962)
		HX_STACK_THIS(this)
		HX_STACK_LINE(282)
		bool has_resize = false;		HX_STACK_VAR(has_resize,"has_resize");
		HX_STACK_LINE(283)
		Float _g = this->GetContainerWidth();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(283)
		Float _g1 = (::haxor::graphics::Screen_obj::m_width - _g);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(283)
		Float _g2 = ::Math_obj::abs(_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(283)
		if (((_g2 > 0.0))){
			HX_STACK_LINE(283)
			Float _g3 = this->GetContainerWidth();		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(283)
			::haxor::graphics::Screen_obj::m_width = _g3;
			HX_STACK_LINE(283)
			has_resize = true;
		}
		HX_STACK_LINE(284)
		Float _g4 = this->GetContainerHeight();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(284)
		Float _g5 = (::haxor::graphics::Screen_obj::m_height - _g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(284)
		Float _g6 = ::Math_obj::abs(_g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(284)
		if (((_g6 > 0.0))){
			HX_STACK_LINE(284)
			Float _g7 = this->GetContainerHeight();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(284)
			::haxor::graphics::Screen_obj::m_height = _g7;
			HX_STACK_LINE(284)
			has_resize = true;
		}
		HX_STACK_LINE(285)
		if ((has_resize)){
			HX_STACK_LINE(287)
			this->OnResize();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,CheckResize,(void))

Void BaseApplication_obj::OnResize( ){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","OnResize",0x33088805,"haxor.core.BaseApplication.OnResize","haxor/core/BaseApplication.hx",295,0x69cdc962)
		HX_STACK_THIS(this)
		HX_STACK_LINE(296)
		::haxor::core::Console_obj::Log(((((HX_CSTRING("Application> Resize [") + ::haxor::graphics::Screen_obj::m_width) + HX_CSTRING(",")) + ::haxor::graphics::Screen_obj::m_height) + HX_CSTRING("]")),(int)6);
		HX_STACK_LINE(298)
		::haxor::graphics::GL_obj::m_gl->Resize();
		HX_STACK_LINE(300)
		::haxor::core::Engine_obj::Resize();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,OnResize,(void))

Void BaseApplication_obj::OnFullscreenEnter( ){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","OnFullscreenEnter",0x69cab4ac,"haxor.core.BaseApplication.OnFullscreenEnter","haxor/core/BaseApplication.hx",306,0x69cdc962)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,OnFullscreenEnter,(void))

Void BaseApplication_obj::OnFullscreenExit( ){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","OnFullscreenExit",0xaa67be0a,"haxor.core.BaseApplication.OnFullscreenExit","haxor/core/BaseApplication.hx",311,0x69cdc962)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,OnFullscreenExit,(void))

bool BaseApplication_obj::OnFullscreenRequest( bool v){
	HX_STACK_FRAME("haxor.core.BaseApplication","OnFullscreenRequest",0x4d1933e3,"haxor.core.BaseApplication.OnFullscreenRequest","haxor/core/BaseApplication.hx",317,0x69cdc962)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(317)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(BaseApplication_obj,OnFullscreenRequest,return )

bool BaseApplication_obj::OnPointerLockRequest( bool v){
	HX_STACK_FRAME("haxor.core.BaseApplication","OnPointerLockRequest",0x3f05d878,"haxor.core.BaseApplication.OnPointerLockRequest","haxor/core/BaseApplication.hx",323,0x69cdc962)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(323)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(BaseApplication_obj,OnPointerLockRequest,return )

bool BaseApplication_obj::OnPointerVisibilityRequest( bool v){
	HX_STACK_FRAME("haxor.core.BaseApplication","OnPointerVisibilityRequest",0x706bf871,"haxor.core.BaseApplication.OnPointerVisibilityRequest","haxor/core/BaseApplication.hx",329,0x69cdc962)
	HX_STACK_THIS(this)
	HX_STACK_ARG(v,"v")
	HX_STACK_LINE(329)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(BaseApplication_obj,OnPointerVisibilityRequest,return )

Void BaseApplication_obj::OnMousePosition( Float p_x,Float p_y){
{
		HX_STACK_FRAME("haxor.core.BaseApplication","OnMousePosition",0x27e9c5fd,"haxor.core.BaseApplication.OnMousePosition","haxor/core/BaseApplication.hx",336,0x69cdc962)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(BaseApplication_obj,OnMousePosition,(void))

Float BaseApplication_obj::GetContainerWidth( ){
	HX_STACK_FRAME("haxor.core.BaseApplication","GetContainerWidth",0xf173fa69,"haxor.core.BaseApplication.GetContainerWidth","haxor/core/BaseApplication.hx",342,0x69cdc962)
	HX_STACK_THIS(this)
	HX_STACK_LINE(342)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,GetContainerWidth,return )

Float BaseApplication_obj::GetContainerHeight( ){
	HX_STACK_FRAME("haxor.core.BaseApplication","GetContainerHeight",0x0a569a24,"haxor.core.BaseApplication.GetContainerHeight","haxor/core/BaseApplication.hx",348,0x69cdc962)
	HX_STACK_THIS(this)
	HX_STACK_LINE(348)
	return 0.0;
}


HX_DEFINE_DYNAMIC_FUNC0(BaseApplication_obj,GetContainerHeight,return )

::haxor::core::BaseApplication BaseApplication_obj::m_instance;


BaseApplication_obj::BaseApplication_obj()
{
}

void BaseApplication_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BaseApplication);
	HX_MARK_MEMBER_NAME(m_vendor,"m_vendor");
	HX_MARK_MEMBER_NAME(m_mspf,"m_mspf");
	HX_MARK_MEMBER_NAME(m_fps,"m_fps");
	HX_MARK_MEMBER_NAME(m_frame_ms,"m_frame_ms");
	HX_MARK_MEMBER_NAME(platform,"platform");
	HX_MARK_MEMBER_NAME(m_platform,"m_platform");
	HX_MARK_MEMBER_NAME(m_scenes,"m_scenes");
	HX_MARK_MEMBER_NAME(m_init_allowed,"m_init_allowed");
	::haxor::component::Component_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BaseApplication_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_vendor,"m_vendor");
	HX_VISIT_MEMBER_NAME(m_mspf,"m_mspf");
	HX_VISIT_MEMBER_NAME(m_fps,"m_fps");
	HX_VISIT_MEMBER_NAME(m_frame_ms,"m_frame_ms");
	HX_VISIT_MEMBER_NAME(platform,"platform");
	HX_VISIT_MEMBER_NAME(m_platform,"m_platform");
	HX_VISIT_MEMBER_NAME(m_scenes,"m_scenes");
	HX_VISIT_MEMBER_NAME(m_init_allowed,"m_init_allowed");
	::haxor::component::Component_obj::__Visit(HX_VISIT_ARG);
}

Dynamic BaseApplication_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"fps") ) { return get_fps(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Load") ) { return Load_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_fps") ) { return m_fps; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"vendor") ) { return get_vendor(); }
		if (HX_FIELD_EQ(inName,"m_mspf") ) { return m_mspf; }
		if (HX_FIELD_EQ(inName,"Update") ) { return Update_dyn(); }
		if (HX_FIELD_EQ(inName,"Render") ) { return Render_dyn(); }
		if (HX_FIELD_EQ(inName,"OnQuit") ) { return OnQuit_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_fps") ) { return get_fps_dyn(); }
		if (HX_FIELD_EQ(inName,"set_fps") ) { return set_fps_dyn(); }
		if (HX_FIELD_EQ(inName,"OnBuild") ) { return OnBuild_dyn(); }
		if (HX_FIELD_EQ(inName,"OnFocus") ) { return OnFocus_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"protocol") ) { return get_protocol(); }
		if (HX_FIELD_EQ(inName,"m_vendor") ) { return m_vendor; }
		if (HX_FIELD_EQ(inName,"platform") ) { return inCallProp ? get_platform() : platform; }
		if (HX_FIELD_EQ(inName,"m_scenes") ) { return m_scenes; }
		if (HX_FIELD_EQ(inName,"OnResize") ) { return OnResize_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"LoadScene") ) { return LoadScene_dyn(); }
		if (HX_FIELD_EQ(inName,"OnUnfocus") ) { return OnUnfocus_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_instance") ) { return m_instance; }
		if (HX_FIELD_EQ(inName,"get_vendor") ) { return get_vendor_dyn(); }
		if (HX_FIELD_EQ(inName,"m_frame_ms") ) { return m_frame_ms; }
		if (HX_FIELD_EQ(inName,"m_platform") ) { return m_platform; }
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"CheckResize") ) { return CheckResize_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"get_protocol") ) { return get_protocol_dyn(); }
		if (HX_FIELD_EQ(inName,"get_platform") ) { return get_platform_dyn(); }
		if (HX_FIELD_EQ(inName,"DestroyScene") ) { return DestroyScene_dyn(); }
		if (HX_FIELD_EQ(inName,"LoadComplete") ) { return LoadComplete_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_init_allowed") ) { return m_init_allowed; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"OnMousePosition") ) { return OnMousePosition_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"OnFullscreenExit") ) { return OnFullscreenExit_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"OnFullscreenEnter") ) { return OnFullscreenEnter_dyn(); }
		if (HX_FIELD_EQ(inName,"GetContainerWidth") ) { return GetContainerWidth_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"GetContainerHeight") ) { return GetContainerHeight_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"OnFullscreenRequest") ) { return OnFullscreenRequest_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"OnPointerLockRequest") ) { return OnPointerLockRequest_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"OnPointerVisibilityRequest") ) { return OnPointerVisibilityRequest_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BaseApplication_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"fps") ) { return set_fps(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_fps") ) { m_fps=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_mspf") ) { m_mspf=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_vendor") ) { m_vendor=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"platform") ) { platform=inValue.Cast< ::haxor::core::Platform >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_scenes") ) { m_scenes=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"m_instance") ) { m_instance=inValue.Cast< ::haxor::core::BaseApplication >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_frame_ms") ) { m_frame_ms=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_platform") ) { m_platform=inValue.Cast< ::haxor::core::Platform >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"m_init_allowed") ) { m_init_allowed=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BaseApplication_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("protocol"));
	outFields->push(HX_CSTRING("vendor"));
	outFields->push(HX_CSTRING("m_vendor"));
	outFields->push(HX_CSTRING("fps"));
	outFields->push(HX_CSTRING("m_mspf"));
	outFields->push(HX_CSTRING("m_fps"));
	outFields->push(HX_CSTRING("m_frame_ms"));
	outFields->push(HX_CSTRING("platform"));
	outFields->push(HX_CSTRING("m_platform"));
	outFields->push(HX_CSTRING("m_scenes"));
	outFields->push(HX_CSTRING("m_init_allowed"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("m_instance"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(BaseApplication_obj,m_vendor),HX_CSTRING("m_vendor")},
	{hx::fsFloat,(int)offsetof(BaseApplication_obj,m_mspf),HX_CSTRING("m_mspf")},
	{hx::fsInt,(int)offsetof(BaseApplication_obj,m_fps),HX_CSTRING("m_fps")},
	{hx::fsFloat,(int)offsetof(BaseApplication_obj,m_frame_ms),HX_CSTRING("m_frame_ms")},
	{hx::fsObject /*::haxor::core::Platform*/ ,(int)offsetof(BaseApplication_obj,platform),HX_CSTRING("platform")},
	{hx::fsObject /*::haxor::core::Platform*/ ,(int)offsetof(BaseApplication_obj,m_platform),HX_CSTRING("m_platform")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(BaseApplication_obj,m_scenes),HX_CSTRING("m_scenes")},
	{hx::fsBool,(int)offsetof(BaseApplication_obj,m_init_allowed),HX_CSTRING("m_init_allowed")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_protocol"),
	HX_CSTRING("get_vendor"),
	HX_CSTRING("m_vendor"),
	HX_CSTRING("get_fps"),
	HX_CSTRING("set_fps"),
	HX_CSTRING("m_mspf"),
	HX_CSTRING("m_fps"),
	HX_CSTRING("m_frame_ms"),
	HX_CSTRING("platform"),
	HX_CSTRING("get_platform"),
	HX_CSTRING("m_platform"),
	HX_CSTRING("m_scenes"),
	HX_CSTRING("m_init_allowed"),
	HX_CSTRING("OnBuild"),
	HX_CSTRING("LoadScene"),
	HX_CSTRING("DestroyScene"),
	HX_CSTRING("Load"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("LoadComplete"),
	HX_CSTRING("Update"),
	HX_CSTRING("Render"),
	HX_CSTRING("OnQuit"),
	HX_CSTRING("OnFocus"),
	HX_CSTRING("OnUnfocus"),
	HX_CSTRING("CheckResize"),
	HX_CSTRING("OnResize"),
	HX_CSTRING("OnFullscreenEnter"),
	HX_CSTRING("OnFullscreenExit"),
	HX_CSTRING("OnFullscreenRequest"),
	HX_CSTRING("OnPointerLockRequest"),
	HX_CSTRING("OnPointerVisibilityRequest"),
	HX_CSTRING("OnMousePosition"),
	HX_CSTRING("GetContainerWidth"),
	HX_CSTRING("GetContainerHeight"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BaseApplication_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BaseApplication_obj::m_instance,"m_instance");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BaseApplication_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BaseApplication_obj::m_instance,"m_instance");
};

#endif

Class BaseApplication_obj::__mClass;

void BaseApplication_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.core.BaseApplication"), hx::TCanCast< BaseApplication_obj> ,sStaticFields,sMemberFields,
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

void BaseApplication_obj::__boot()
{
}

} // end namespace haxor
} // end namespace core
