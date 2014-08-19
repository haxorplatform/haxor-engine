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
#ifndef INCLUDED_haxor_graphics_PixelFormat
#include <haxor/graphics/PixelFormat.h>
#endif
#ifndef INCLUDED_haxor_graphics_Screen
#include <haxor/graphics/Screen.h>
#endif
#ifndef INCLUDED_haxor_graphics_TextureFilter
#include <haxor/graphics/TextureFilter.h>
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
#ifndef INCLUDED_haxor_graphics_texture_Bitmap
#include <haxor/graphics/texture/Bitmap.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture2D
#include <haxor/graphics/texture/Texture2D.h>
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
#ifndef INCLUDED_haxor_math_Color
#include <haxor/math/Color.h>
#endif
#ifndef INCLUDED_haxor_net_Web
#include <haxor/net/Web.h>
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
#ifndef INCLUDED_haxor_platform_windows_WinApplication
#include <haxor/platform/windows/WinApplication.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_FRAME("Main","new",0x6616a5cb,"Main.new","Main.hx",38,0x087e5c05)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(38)
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
	HX_STACK_FRAME("Main","Load",0xd748ae7b,"Main.Load","Main.hx",55,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_LINE(56)
	::haxor::net::Web_obj::root = HX_CSTRING("https://dl.dropboxusercontent.com/u/20655747/haxor/resources/");
	HX_STACK_LINE(94)
	return true;
}


Void Main_obj::Initialize( ){
{
		HX_STACK_FRAME("Main","Initialize",0x7af3b365,"Main.Initialize","Main.hx",98,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(99)
		::haxor::core::Console_obj::Log(HX_CSTRING("Initialize!"),null());
		HX_STACK_LINE(101)
		Float s = 0.8;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(103)
		::haxor::io::FloatArray vl = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(-(s)).Add(-(s)).Add(0.5).Add(s).Add(-(s)).Add(0.5).Add(s).Add(s).Add(0.5).Add(-(s)).Add(s).Add(0.5));		HX_STACK_VAR(vl,"vl");
		HX_STACK_LINE(110)
		::haxor::io::FloatArray uvl = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(0.0).Add(0.0).Add(1.0).Add(0.0).Add(1.0).Add(1.0).Add(0.0).Add(1.0));		HX_STACK_VAR(uvl,"uvl");
		HX_STACK_LINE(117)
		::haxor::io::FloatArray cl = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(0.0).Add(1.0).Add(0.0).Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(1.0).Add(1.0).Add(1.0).Add(0.0).Add(1.0));		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(125)
		::haxor::io::UInt16Array il = ::haxor::io::UInt16Array_obj::Alloc(Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)0).Add((int)2).Add((int)3));		HX_STACK_VAR(il,"il");
		HX_STACK_LINE(127)
		::haxor::graphics::mesh::Mesh _g = ::haxor::graphics::mesh::Mesh_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(127)
		::haxor::graphics::mesh::Mesh m = this->mesh = _g;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(128)
		m->Set(HX_CSTRING("vertex"),vl,(int)3);
		HX_STACK_LINE(129)
		m->Set(HX_CSTRING("uv0"),uvl,(int)2);
		HX_STACK_LINE(130)
		m->Set(HX_CSTRING("color"),cl,(int)4);
		HX_STACK_LINE(132)
		m->set_topology(il);
		HX_STACK_LINE(133)
		if (((this->ss == null()))){
			HX_STACK_LINE(135)
			this->ss = HX_CSTRING("\r\n\t\t\t<shader id=\"haxor/debug\">\r\n\t\t\t\t<vertex>\t\t\t\r\n\t\t\t\tattribute vec3 vertex;\r\n\t\t\t\tattribute vec2 uv0;\r\n\t\t\t\tattribute vec4 color;\t\t\t\r\n\t\t\t\tuniform float Size;\r\n\t\t\t\tuniform float Time;\r\n\t\t\t\tvarying vec4 v_color;\t\t\r\n\t\t\t\tvarying vec2 v_uv0;\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tv_color = color;\r\n\t\t\t\t\tv_uv0.x = vertex.x / (Size);\r\n\t\t\t\t\tv_uv0.y = -vertex.y / (Size);\r\n\t\t\t\t\tv_uv0.x = (v_uv0.x + 1.0) * 0.5;\r\n\t\t\t\t\tv_uv0.y = (v_uv0.y + 1.0) * 0.5;\r\n\t\t\t\t\t//v_uv0 = uv0;\r\n\t\t\t\t\tvec4 v = vec4(vertex,1.0);\r\n\t\t\t\t\tv.x = v.x*sin(Time);\r\n\t\t\t\t\tgl_Position = vec4(v);\t\t\t\t\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</vertex>\t\t\t\r\n\t\t\t\t<fragment>\t\t\t\r\n\t\t\t\tuniform sampler2D Texture;\r\n\t\t\t\tuniform vec4 Tint[2];\r\n\t\t\t\tvarying vec4 v_color;\t\r\n\t\t\t\tvarying vec2 v_uv0;\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tvec4 c = texture2D(Texture, v_uv0);\r\n\t\t\t\t\t//gl_FragColor = vec4(v_uv0.x,v_uv0.y,0.0,1.0);\r\n\t\t\t\t\tgl_FragColor = c;\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</fragment>\r\n\t\t\t</shader>\r\n\t\t\t");
		}
		HX_STACK_LINE(175)
		int h = (int)2048;		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(176)
		::haxor::graphics::texture::Texture2D tex = ::haxor::graphics::texture::Texture2D_obj::__new((int)1,h,::haxor::graphics::PixelFormat_obj::Float4);		HX_STACK_VAR(tex,"tex");
		HX_STACK_LINE(177)
		::haxor::math::Color _g1 = ::haxor::math::Color_obj::get_red();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(177)
		::haxor::math::Color _g2 = ::haxor::math::Color_obj::get_green();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(177)
		::haxor::math::Color _g3 = ::haxor::math::Color_obj::get_blue();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(177)
		::haxor::math::Color _g4 = ::haxor::math::Color_obj::get_yellow();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(177)
		Array< ::Dynamic > cl1 = Array_obj< ::Dynamic >::__new().Add(_g1).Add(_g2).Add(_g3).Add(_g4);		HX_STACK_VAR(cl1,"cl1");
		HX_STACK_LINE(178)
		{
			HX_STACK_LINE(178)
			int _g5 = (int)0;		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(178)
			while((true)){
				HX_STACK_LINE(178)
				if ((!(((_g5 < h))))){
					HX_STACK_LINE(178)
					break;
				}
				HX_STACK_LINE(178)
				int i = (_g5)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(180)
				Float r = (Float(i) / Float(((h - (int)1))));		HX_STACK_VAR(r,"r");
				HX_STACK_LINE(181)
				::haxor::math::Color _g51 = ::haxor::math::Color_obj::Sample(cl1,r);		HX_STACK_VAR(_g51,"_g51");
				HX_STACK_LINE(181)
				tex->m_data->SetPixel((int)0,i,_g51);
			}
		}
		HX_STACK_LINE(185)
		tex->set_minFilter(::haxor::graphics::TextureFilter_obj::Nearest);
		HX_STACK_LINE(186)
		tex->set_magFilter(::haxor::graphics::TextureFilter_obj::Nearest);
		HX_STACK_LINE(187)
		tex->Upload((int)100,null());
		HX_STACK_LINE(194)
		::haxor::graphics::material::Shader shd = ::haxor::graphics::material::Shader_obj::__new(this->ss);		HX_STACK_VAR(shd,"shd");
		HX_STACK_LINE(196)
		::haxor::graphics::material::Material _g6 = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("DebugMaterial"));		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(196)
		this->mat = _g6;
		HX_STACK_LINE(197)
		this->mat->blend = true;
		HX_STACK_LINE(198)
		this->mat->cull = (int)0;
		HX_STACK_LINE(199)
		this->mat->SetBlending((int)770,(int)771);
		HX_STACK_LINE(200)
		this->mat->set_shader(shd);
		HX_STACK_LINE(201)
		this->mat->SetFloat(HX_CSTRING("Size"),s);
		HX_STACK_LINE(202)
		this->mat->SetTexture(HX_CSTRING("Texture"),tex);
		HX_STACK_LINE(203)
		this->mat->SetFloat4Array(HX_CSTRING("Tint"),Array_obj< Float >::__new().Add(0.0).Add(1.0).Add(0.0).Add(0.3).Add(1.0).Add(0.0).Add(0.0).Add(0.3));
	}
return null();
}


Void Main_obj::OnUpdate( ){
{
		HX_STACK_FRAME("Main","OnUpdate",0x876cdf5d,"Main.OnUpdate","Main.hx",208,0x087e5c05)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnUpdate,(void))

Void Main_obj::OnRender( ){
{
		HX_STACK_FRAME("Main","OnRender",0x0590c4aa,"Main.OnRender","Main.hx",215,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(217)
		::haxor::platform::graphics::GL_obj::m_gl->Viewport((int)0,(int)0,::haxor::graphics::Screen_obj::m_width,::haxor::graphics::Screen_obj::m_height);
		HX_STACK_LINE(218)
		::haxor::platform::graphics::GL_obj::m_gl->ClearColor(0.7,0.3,1.0,1.0);
		HX_STACK_LINE(219)
		::haxor::platform::graphics::GL_obj::m_gl->ClearDepth(1.0);
		HX_STACK_LINE(220)
		::haxor::platform::graphics::GL_obj::m_gl->Clear((int)16640);
		HX_STACK_LINE(223)
		if (((this->mesh == null()))){
			HX_STACK_LINE(223)
			return null();
		}
		HX_STACK_LINE(224)
		if (((this->mat == null()))){
			HX_STACK_LINE(224)
			return null();
		}
		HX_STACK_LINE(225)
		this->mat->SetFloat(HX_CSTRING("Time"),::haxor::core::Time_obj::m_elapsed);
		HX_STACK_LINE(226)
		::haxor::graphics::Graphics_obj::RenderMesh(this->mesh,this->mat);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnRender,(void))

Void Main_obj::main( ){
{
		HX_STACK_FRAME("Main","main",0xed0e206e,"Main.main","Main.hx",43,0x087e5c05)
		HX_STACK_LINE(43)
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
	::haxor::platform::windows::WinApplication_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mesh,"mesh");
	HX_VISIT_MEMBER_NAME(mat,"mat");
	HX_VISIT_MEMBER_NAME(ss,"ss");
	::haxor::platform::windows::WinApplication_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"ss") ) { return ss; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"mat") ) { return mat; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"mesh") ) { return mesh; }
		if (HX_FIELD_EQ(inName,"Load") ) { return Load_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"OnUpdate") ) { return OnUpdate_dyn(); }
		if (HX_FIELD_EQ(inName,"OnRender") ) { return OnRender_dyn(); }
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
		if (HX_FIELD_EQ(inName,"ss") ) { ss=inValue.Cast< ::String >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"mat") ) { mat=inValue.Cast< ::haxor::graphics::material::Material >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mesh") ) { mesh=inValue.Cast< ::haxor::graphics::mesh::Mesh >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mesh"));
	outFields->push(HX_CSTRING("mat"));
	outFields->push(HX_CSTRING("ss"));
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
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("mesh"),
	HX_CSTRING("mat"),
	HX_CSTRING("ss"),
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

