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
#ifndef INCLUDED_haxor_graphics_GL
#include <haxor/graphics/GL.h>
#endif
#ifndef INCLUDED_haxor_graphics_GraphicContext
#include <haxor/graphics/GraphicContext.h>
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
#ifndef INCLUDED_haxor_math_Matrix4
#include <haxor/math/Matrix4.h>
#endif
#ifndef INCLUDED_haxor_math_Quaternion
#include <haxor/math/Quaternion.h>
#endif
#ifndef INCLUDED_haxor_math_Vector2
#include <haxor/math/Vector2.h>
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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_FRAME("Main","new",0x6616a5cb,"Main.new","Main.hx",44,0x087e5c05)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(44)
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
	HX_STACK_FRAME("Main","Load",0xd748ae7b,"Main.Load","Main.hx",63,0x087e5c05)
	HX_STACK_THIS(this)
	HX_STACK_LINE(64)
	::haxor::net::Web_obj::root = HX_CSTRING("http://haxor.thelaborat.org/resources/");
	HX_STACK_LINE(123)
	return true;
}


Void Main_obj::Initialize( ){
{
		HX_STACK_FRAME("Main","Initialize",0x7af3b365,"Main.Initialize","Main.hx",127,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(128)
		::haxor::core::Console_obj::Log(HX_CSTRING("Initialize!"),null());
		HX_STACK_LINE(130)
		Float s = 0.8;		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(132)
		::haxor::io::FloatArray vl = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(-(s)).Add(-(s)).Add(0.5).Add(s).Add(-(s)).Add(0.5).Add(s).Add(s).Add(0.5).Add(-(s)).Add(s).Add(0.5));		HX_STACK_VAR(vl,"vl");
		HX_STACK_LINE(139)
		::haxor::io::FloatArray uvl = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(0.0).Add(0.0).Add(1.0).Add(0.0).Add(1.0).Add(1.0).Add(0.0).Add(1.0));		HX_STACK_VAR(uvl,"uvl");
		HX_STACK_LINE(146)
		::haxor::io::FloatArray cl = ::haxor::io::FloatArray_obj::Alloc(Array_obj< Float >::__new().Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(0.0).Add(1.0).Add(0.0).Add(1.0).Add(0.0).Add(0.0).Add(1.0).Add(1.0).Add(1.0).Add(1.0).Add(0.0).Add(1.0));		HX_STACK_VAR(cl,"cl");
		HX_STACK_LINE(154)
		::haxor::io::UInt16Array il = ::haxor::io::UInt16Array_obj::Alloc(Array_obj< int >::__new().Add((int)0).Add((int)1).Add((int)2).Add((int)0).Add((int)2).Add((int)3));		HX_STACK_VAR(il,"il");
		HX_STACK_LINE(156)
		::haxor::graphics::mesh::Mesh _g = ::haxor::graphics::mesh::Mesh_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(156)
		::haxor::graphics::mesh::Mesh m = this->mesh = _g;		HX_STACK_VAR(m,"m");
		HX_STACK_LINE(157)
		m->Set(HX_CSTRING("vertex"),vl,(int)3);
		HX_STACK_LINE(158)
		m->Set(HX_CSTRING("uv0"),uvl,(int)2);
		HX_STACK_LINE(159)
		m->Set(HX_CSTRING("color"),cl,(int)4);
		HX_STACK_LINE(161)
		m->set_topology(il);
		HX_STACK_LINE(162)
		if (((this->ss == null()))){
			HX_STACK_LINE(164)
			this->ss = HX_CSTRING("\r\n\t\t\t<shader id=\"haxor/debug\">\r\n\t\t\t\t<vertex>\t\t\t\r\n\t\t\t\tattribute vec3 vertex;\r\n\t\t\t\tattribute vec2 uv0;\r\n\t\t\t\tattribute vec4 color;\t\t\t\r\n\t\t\t\tuniform float Size;\r\n\t\t\t\tuniform float Time;\r\n\t\t\t\tvarying vec4 v_color;\t\t\r\n\t\t\t\tvarying vec2 v_uv0;\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tv_color = color;\r\n\t\t\t\t\tv_uv0.x = vertex.x / (Size);\r\n\t\t\t\t\tv_uv0.y = -vertex.y / (Size);\r\n\t\t\t\t\tv_uv0.x = (v_uv0.x + 1.0) * 0.5;\r\n\t\t\t\t\tv_uv0.y = (v_uv0.y + 1.0) * 0.5;\r\n\t\t\t\t\t//v_uv0 = uv0;\r\n\t\t\t\t\tvec4 v = vec4(vertex,1.0);\r\n\t\t\t\t\tv.x = v.x*sin(Time);\r\n\t\t\t\t\tgl_Position = vec4(v);\t\t\t\t\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</vertex>\t\t\t\r\n\t\t\t\t<fragment>\t\t\t\r\n\t\t\t\tuniform sampler2D Texture;\r\n\t\t\t\tuniform vec4 Tint[2];\r\n\t\t\t\tvarying vec4 v_color;\t\r\n\t\t\t\tvarying vec2 v_uv0;\r\n\t\t\t\tvoid main(void) \r\n\t\t\t\t{ \r\n\t\t\t\t\tvec4 c = texture2D(Texture, v_uv0);\r\n\t\t\t\t\t//gl_FragColor = vec4(v_uv0.x,v_uv0.y,0.0,1.0);\r\n\t\t\t\t\tgl_FragColor = c;\r\n\t\t\t\t}\t\t\t\r\n\t\t\t\t</fragment>\r\n\t\t\t</shader>\r\n\t\t\t");
		}
		HX_STACK_LINE(221)
		::haxor::math::Color c;		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(222)
		::haxor::math::Vector2 v2;		HX_STACK_VAR(v2,"v2");
		HX_STACK_LINE(223)
		::haxor::math::Vector3 v3;		HX_STACK_VAR(v3,"v3");
		HX_STACK_LINE(224)
		::haxor::math::Vector4 v4;		HX_STACK_VAR(v4,"v4");
		HX_STACK_LINE(225)
		::haxor::math::Quaternion q;		HX_STACK_VAR(q,"q");
		HX_STACK_LINE(226)
		::haxor::math::Matrix4 m4;		HX_STACK_VAR(m4,"m4");
		HX_STACK_LINE(228)
		Float _g1 = ::Math_obj::random();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(228)
		Float _g2 = (_g1 - 0.499995);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(228)
		Float _g3 = (_g2 * 2.0);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(228)
		Float _g4 = ::Math_obj::random();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(228)
		Float _g5 = (_g4 - 0.499995);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(228)
		Float _g6 = (_g5 * 2.0);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(228)
		Float _g7 = ::Math_obj::random();		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(228)
		Float _g8 = (_g7 - 0.499995);		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(228)
		Float _g9 = (_g8 * 2.0);		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(228)
		Float _g10 = ::Math_obj::random();		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(228)
		::haxor::math::Vector3 _g11 = ::haxor::math::Vector3_obj::__new(_g3,_g6,_g9)->Normalize()->Scale(_g10);		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(228)
		Float _g12 = ::Math_obj::random();		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(228)
		Float _g13 = (_g12 - 0.499995);		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(228)
		Float _g14 = (_g13 * 2.0);		HX_STACK_VAR(_g14,"_g14");
		HX_STACK_LINE(228)
		Float _g15 = (_g14 * 180.0);		HX_STACK_VAR(_g15,"_g15");
		HX_STACK_LINE(228)
		::haxor::math::Quaternion _g16 = ::haxor::math::Quaternion_obj::FromAxisAngle(_g11,_g15);		HX_STACK_VAR(_g16,"_g16");
		HX_STACK_LINE(228)
		q = _g16;
		HX_STACK_LINE(229)
		::String _g17 = q->ToString(null());		HX_STACK_VAR(_g17,"_g17");
		HX_STACK_LINE(229)
		::String _g18 = (_g17 + HX_CSTRING(" "));		HX_STACK_VAR(_g18,"_g18");
		HX_STACK_LINE(229)
		::String _g19 = q->get_euler()->ToString(null());		HX_STACK_VAR(_g19,"_g19");
		HX_STACK_LINE(229)
		::String _g20 = (_g18 + _g19);		HX_STACK_VAR(_g20,"_g20");
		HX_STACK_LINE(229)
		::haxe::Log_obj::trace(_g20,hx::SourceInfo(HX_CSTRING("Main.hx"),229,HX_CSTRING("Main"),HX_CSTRING("Initialize")));
		HX_STACK_LINE(231)
		::haxor::math::Matrix4 _g21 = q->get_matrix();		HX_STACK_VAR(_g21,"_g21");
		HX_STACK_LINE(231)
		m4 = _g21;
		HX_STACK_LINE(232)
		::String _g22 = m4->ToString(null(),null());		HX_STACK_VAR(_g22,"_g22");
		HX_STACK_LINE(232)
		::haxe::Log_obj::trace(_g22,hx::SourceInfo(HX_CSTRING("Main.hx"),232,HX_CSTRING("Main"),HX_CSTRING("Initialize")));
		HX_STACK_LINE(233)
		q->set_matrix(m4);
		HX_STACK_LINE(234)
		::String _g23 = q->ToString(null());		HX_STACK_VAR(_g23,"_g23");
		HX_STACK_LINE(234)
		::String _g24 = (_g23 + HX_CSTRING(" "));		HX_STACK_VAR(_g24,"_g24");
		HX_STACK_LINE(234)
		::String _g25 = q->get_euler()->ToString(null());		HX_STACK_VAR(_g25,"_g25");
		HX_STACK_LINE(234)
		::String _g26 = (_g24 + _g25);		HX_STACK_VAR(_g26,"_g26");
		HX_STACK_LINE(234)
		::haxe::Log_obj::trace(_g26,hx::SourceInfo(HX_CSTRING("Main.hx"),234,HX_CSTRING("Main"),HX_CSTRING("Initialize")));
		HX_STACK_LINE(235)
		q->set_matrix(m4);
		HX_STACK_LINE(236)
		::String _g27 = m4->ToString(null(),null());		HX_STACK_VAR(_g27,"_g27");
		HX_STACK_LINE(236)
		::haxe::Log_obj::trace(_g27,hx::SourceInfo(HX_CSTRING("Main.hx"),236,HX_CSTRING("Main"),HX_CSTRING("Initialize")));
		HX_STACK_LINE(239)
		if (((this->bmp == null()))){
			HX_STACK_LINE(239)
			return null();
		}
		HX_STACK_LINE(240)
		::haxor::graphics::texture::Texture2D _g28 = ::haxor::graphics::texture::Texture2D_obj::FromBitmap(this->bmp,false);		HX_STACK_VAR(_g28,"_g28");
		HX_STACK_LINE(240)
		this->tex = _g28;
		HX_STACK_LINE(241)
		this->tex->Upload((int)100,null());
		HX_STACK_LINE(243)
		::haxor::graphics::material::Shader shd = ::haxor::graphics::material::Shader_obj::__new(this->ss);		HX_STACK_VAR(shd,"shd");
		HX_STACK_LINE(245)
		::haxor::graphics::material::Material _g29 = ::haxor::graphics::material::Material_obj::__new(HX_CSTRING("DebugMaterial"));		HX_STACK_VAR(_g29,"_g29");
		HX_STACK_LINE(245)
		this->mat = _g29;
		HX_STACK_LINE(246)
		this->mat->blend = true;
		HX_STACK_LINE(247)
		this->mat->cull = (int)0;
		HX_STACK_LINE(248)
		this->mat->SetBlending((int)770,(int)771);
		HX_STACK_LINE(249)
		this->mat->set_shader(shd);
		HX_STACK_LINE(250)
		this->mat->SetFloat(HX_CSTRING("Size"),s);
		HX_STACK_LINE(251)
		this->mat->SetTexture(HX_CSTRING("Texture"),this->tex);
		HX_STACK_LINE(252)
		this->mat->SetFloat4Array(HX_CSTRING("Tint"),Array_obj< Float >::__new().Add(0.0).Add(1.0).Add(0.0).Add(0.3).Add(1.0).Add(0.0).Add(0.0).Add(0.3));
	}
return null();
}


Void Main_obj::OnUpdate( ){
{
		HX_STACK_FRAME("Main","OnUpdate",0x876cdf5d,"Main.OnUpdate","Main.hx",257,0x087e5c05)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnUpdate,(void))

Void Main_obj::OnRender( ){
{
		HX_STACK_FRAME("Main","OnRender",0x0590c4aa,"Main.OnRender","Main.hx",264,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(266)
		::haxor::graphics::GL_obj::m_gl->Viewport((int)0,(int)0,::haxor::graphics::Screen_obj::m_width,::haxor::graphics::Screen_obj::m_height);
		HX_STACK_LINE(267)
		::haxor::graphics::GL_obj::m_gl->Scissor((int)0,(int)0,::haxor::graphics::Screen_obj::m_width,::haxor::graphics::Screen_obj::m_height);
		HX_STACK_LINE(268)
		::haxor::graphics::GL_obj::m_gl->ClearColor(0.7,0.3,1.0,1.0);
		HX_STACK_LINE(269)
		::haxor::graphics::GL_obj::m_gl->ClearDepth(1.0);
		HX_STACK_LINE(270)
		::haxor::graphics::GL_obj::m_gl->Clear((int)16640);
		HX_STACK_LINE(273)
		if (((this->mesh == null()))){
			HX_STACK_LINE(273)
			return null();
		}
		HX_STACK_LINE(274)
		if (((this->mat == null()))){
			HX_STACK_LINE(274)
			return null();
		}
		HX_STACK_LINE(275)
		this->mat->SetFloat(HX_CSTRING("Time"),::haxor::core::Time_obj::m_elapsed);
		HX_STACK_LINE(276)
		::haxor::graphics::Graphics_obj::RenderMesh(this->mesh,this->mat);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,OnRender,(void))

Void Main_obj::main( ){
{
		HX_STACK_FRAME("Main","main",0xed0e206e,"Main.main","Main.hx",49,0x087e5c05)
		HX_STACK_LINE(49)
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
	HX_MARK_MEMBER_NAME(tex,"tex");
	HX_MARK_MEMBER_NAME(bmp,"bmp");
	::haxor::platform::windows::WinApplication_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mesh,"mesh");
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
		if (HX_FIELD_EQ(inName,"ss") ) { return ss; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"mat") ) { return mat; }
		if (HX_FIELD_EQ(inName,"tex") ) { return tex; }
		if (HX_FIELD_EQ(inName,"bmp") ) { return bmp; }
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
		if (HX_FIELD_EQ(inName,"tex") ) { tex=inValue.Cast< ::haxor::graphics::texture::Texture2D >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bmp") ) { bmp=inValue.Cast< ::haxor::graphics::texture::Bitmap >(); return inValue; }
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
	{hx::fsObject /*::haxor::graphics::material::Material*/ ,(int)offsetof(Main_obj,mat),HX_CSTRING("mat")},
	{hx::fsString,(int)offsetof(Main_obj,ss),HX_CSTRING("ss")},
	{hx::fsObject /*::haxor::graphics::texture::Texture2D*/ ,(int)offsetof(Main_obj,tex),HX_CSTRING("tex")},
	{hx::fsObject /*::haxor::graphics::texture::Bitmap*/ ,(int)offsetof(Main_obj,bmp),HX_CSTRING("bmp")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("mesh"),
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

