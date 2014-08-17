#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
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
#ifndef INCLUDED_haxor_graphics_Graphics
#include <haxor/graphics/Graphics.h>
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
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
#ifndef INCLUDED_haxor_io_UInt16Array
#include <haxor/io/UInt16Array.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GL
#include <haxor/platform/graphics/GL.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GraphicContext
#include <haxor/platform/graphics/GraphicContext.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_WinGL
#include <haxor/platform/graphics/WinGL.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_Entry
#include <haxor/platform/windows/Entry.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_Web
#include <haxor/platform/windows/Web.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_WinApplication
#include <haxor/platform/windows/WinApplication.h>
#endif
#ifndef INCLUDED_haxor_thread_Activity
#include <haxor/thread/Activity.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_FRAME("Main","new",0x6616a5cb,"Main.new","Main.hx",30,0x087e5c05)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(181)
	this->init = false;
	HX_STACK_LINE(30)
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
	HX_STACK_FRAME("Main","Load",0xd748ae7b,"Main.Load","Main.hx",45,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_LINE(46)
	::haxor::platform::windows::Web_obj::root = HX_CSTRING("https://dl.dropboxusercontent.com/u/20655747/haxor/resources/");
	HX_STACK_LINE(82)
	return true;
}


Void Main_obj::Initialize( ){
{
		HX_STACK_FRAME("Main","Initialize",0x7af3b365,"Main.Initialize","Main.hx",86,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(87)
		::haxor::core::Console_obj::Log(HX_CSTRING("Initialize!"),null());
		HX_STACK_LINE(90)
		Float s = 0.8;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(92)
		::haxor::io::FloatArray vl = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(-(s)).Add(-(s)).Add(0.5).Add(s).Add(-(s)).Add(0.5).Add(s).Add(s).Add(0.5).Add(-(s)).Add(s).Add(0.5));		HX_STACK_VAR(vl,"vl");
		HX_STACK_LINE(99)
		::haxor::io::FloatArray cl = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(0.0).Add(1.0).Add(0.0).Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(1.0).Add(1.0).Add(1.0).Add(0.0).Add(1.0));		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(107)
		::haxor::io::UInt16Array il = ::haxor::io::UInt16Array_obj::Alloc(Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)0).Add((int)2).Add((int)3));		HX_STACK_VAR(il,"il");
		HX_STACK_LINE(109)
		::haxor::graphics::mesh::Mesh _g = ::haxor::graphics::mesh::Mesh_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(109)
		::haxor::graphics::mesh::Mesh m = this->mesh = _g;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(110)
		m->Set(HX_CSTRING("vertex"),vl,(int)3);
		HX_STACK_LINE(111)
		m->Set(HX_CSTRING("color"),cl,(int)4);
		HX_STACK_LINE(113)
		m->set_topology(il);
		HX_STACK_LINE(114)
		if (((this->ss == null()))){
			HX_STACK_LINE(116)
			this->ss = HX_CSTRING("\r\n\t\t\t<shader id=\"haxor/debug\">\r\n\t\t\t\t<vertex>\t\t\t\r\n\t\t\t\tattribute vec3 vertex;\r\n\t\t\t\tattribute vec4 color;\t\t\t\r\n\t\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tv_color = color;\r\n\t\t\t\t\tgl_Position = vec4(vertex, 1.0);\t\t\t\t\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</vertex>\t\t\t\r\n\t\t\t\t<fragment>\t\t\t\t\t\r\n\t\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tgl_FragColor = v_color;\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</fragment>\r\n\t\t\t</shader>\r\n\t\t\t");
		}
		HX_STACK_LINE(139)
		::haxor::graphics::material::Shader shd = ::haxor::graphics::material::Shader_obj::__new(this->ss);		HX_STACK_VAR(shd,"shd");
		HX_STACK_LINE(141)
		::haxor::graphics::material::Material _g1 = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("DebugMaterial"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(141)
		this->mat = _g1;
		HX_STACK_LINE(142)
		this->mat->blend = true;
		HX_STACK_LINE(143)
		this->mat->SetBlending((int)770,(int)771);
		HX_STACK_LINE(144)
		this->mat->set_shader(shd);
		HX_STACK_LINE(146)
		::haxor::core::Console_obj::Log(HX_CSTRING("Start"),null());
		HX_STACK_LINE(147)
		Array< Float > t0 = Array_obj< Float >::__new().Add(::haxor::core::Time_obj::m_clock);		HX_STACK_VAR(t0,"t0");
		HX_STACK_LINE(148)
		Array< int > len = Array_obj< int >::__new().Add((int)100000);		HX_STACK_VAR(len,"len");

		HX_BEGIN_LOCAL_FUNC_S2(hx::LocalFunc,_Function_1_1,Array< int >,len,Array< Float >,t0)
		bool run(int pos){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","Main.hx",150,0x087e5c05)
			HX_STACK_ARG(pos,"pos")
			{
				HX_STACK_LINE(151)
				if (((pos >= (len->__get((int)0) - (int)1)))){
					HX_STACK_LINE(153)
					::haxor::core::Console_obj::Log(((HX_CSTRING("T: Finished! ") + ((::haxor::core::Time_obj::m_clock - t0->__get((int)0)))) + HX_CSTRING(" ms")),null());
				}
				HX_STACK_LINE(155)
				return true;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(149)
		::haxor::thread::Activity_obj::Iterate((int)0,len->__get((int)0), Dynamic(new _Function_1_1(len,t0)),(int)100,true);
	}
return null();
}


Void Main_obj::OnActivityComplete( ){
{
		HX_STACK_FRAME("Main","OnActivityComplete",0x05409bfc,"Main.OnActivityComplete","Main.hx",164,0x087e5c05)
		HX_STACK_THIS(this)

		HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
		bool run(Float t){
			HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","Main.hx",165,0x087e5c05)
			HX_STACK_ARG(t,"t")
			{
				HX_STACK_LINE(166)
				if (((t < 3.0))){
					HX_STACK_LINE(168)
					return true;
				}
				HX_STACK_LINE(170)
				::haxor::core::Console_obj::Log((HX_CSTRING("Time: ") + t),null());
				HX_STACK_LINE(171)
				return false;
			}
			return null();
		}
		HX_END_LOCAL_FUNC1(return)

		HX_STACK_LINE(164)
		::haxor::thread::Activity_obj::Run( Dynamic(new _Function_1_1()),true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnActivityComplete,(void))

Void Main_obj::OnUpdate( ){
{
		HX_STACK_FRAME("Main","OnUpdate",0x876cdf5d,"Main.OnUpdate","Main.hx",177,0x087e5c05)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnUpdate,(void))

Void Main_obj::OnRender( ){
{
		HX_STACK_FRAME("Main","OnRender",0x0590c4aa,"Main.OnRender","Main.hx",186,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(190)
		::haxor::platform::graphics::GL_obj::m_gl->ClearColor(1.0,0.0,1.0,1.0);
		HX_STACK_LINE(191)
		::haxor::platform::graphics::GL_obj::m_gl->ClearDepth(1.0);
		HX_STACK_LINE(192)
		::haxor::platform::graphics::GL_obj::m_gl->Clear((int)16640);
		HX_STACK_LINE(195)
		if (((this->mesh == null()))){
			HX_STACK_LINE(195)
			return null();
		}
		HX_STACK_LINE(196)
		if (((this->mat == null()))){
			HX_STACK_LINE(196)
			return null();
		}
		HX_STACK_LINE(197)
		::haxor::graphics::Graphics_obj::RenderMesh(this->mesh,this->mat);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnRender,(void))

Void Main_obj::main( ){
{
		HX_STACK_FRAME("Main","main",0xed0e206e,"Main.main","Main.hx",35,0x087e5c05)
		HX_STACK_LINE(35)
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
	HX_MARK_MEMBER_NAME(mat,"mat");
	HX_MARK_MEMBER_NAME(ss,"ss");
	HX_MARK_MEMBER_NAME(init,"init");
	HX_MARK_MEMBER_NAME(vb,"vb");
	::haxor::platform::windows::WinApplication_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mesh,"mesh");
	HX_VISIT_MEMBER_NAME(mat,"mat");
	HX_VISIT_MEMBER_NAME(ss,"ss");
	HX_VISIT_MEMBER_NAME(init,"init");
	HX_VISIT_MEMBER_NAME(vb,"vb");
	::haxor::platform::windows::WinApplication_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ss") ) { return ss; }
		if (HX_FIELD_EQ(inName,"vb") ) { return vb; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"mat") ) { return mat; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"mesh") ) { return mesh; }
		if (HX_FIELD_EQ(inName,"Load") ) { return Load_dyn(); }
		if (HX_FIELD_EQ(inName,"init") ) { return init; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"OnUpdate") ) { return OnUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"OnRender") ) { return OnRender_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"OnActivityComplete") ) { return OnActivityComplete_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ss") ) { ss=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vb") ) { vb=inValue.Cast< int >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"mat") ) { mat=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mesh") ) { mesh=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
		if (HX_FIELD_EQ(inName,"init") ) { init=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mesh"));
	outFields->push(HX_CSTRING("mat"));
	outFields->push(HX_CSTRING("ss"));
	outFields->push(HX_CSTRING("init"));
	outFields->push(HX_CSTRING("vb"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::graphics::mesh::Mesh*/ ,(int)offsetof(Main_obj,mesh),HX_CSTRING("mesh")},
	{hx::fsObject /*::haxor::graphics::material::Material*/ ,(int)offsetof(Main_obj,mat),HX_CSTRING("mat")},
	{hx::fsString,(int)offsetof(Main_obj,ss),HX_CSTRING("ss")},
	{hx::fsBool,(int)offsetof(Main_obj,init),HX_CSTRING("init")},
	{hx::fsInt,(int)offsetof(Main_obj,vb),HX_CSTRING("vb")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("mesh"),
	HX_CSTRING("mat"),
	HX_CSTRING("ss"),
	HX_CSTRING("Load"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("OnActivityComplete"),
	HX_CSTRING("OnUpdate"),
	HX_CSTRING("init"),
	HX_CSTRING("vb"),
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

