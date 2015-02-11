#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Camera
#include <haxor/component/Camera.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
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
#ifndef INCLUDED_haxor_context_KernelContext
#include <haxor/context/KernelContext.h>
#endif
#ifndef INCLUDED_haxor_context_TextureContext
#include <haxor/context/TextureContext.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_IResizeable
#include <haxor/core/IResizeable.h>
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
#ifndef INCLUDED_haxor_graphics_mesh_Mesh3
#include <haxor/graphics/mesh/Mesh3.h>
#endif
#ifndef INCLUDED_haxor_graphics_mesh_MeshLayout
#include <haxor/graphics/mesh/MeshLayout.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_RenderTexture
#include <haxor/graphics/texture/RenderTexture.h>
#endif
#ifndef INCLUDED_haxor_graphics_texture_Texture
#include <haxor/graphics/texture/Texture.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
#ifndef INCLUDED_haxor_math_AABB2
#include <haxor/math/AABB2.h>
#endif
#ifndef INCLUDED_haxor_math_Vector3
#include <haxor/math/Vector3.h>
#endif
#ifndef INCLUDED_haxor_thread_Kernel
#include <haxor/thread/Kernel.h>
#endif
namespace haxor{
namespace thread{

Void Kernel_obj::__construct(int p_width,int p_height,hx::Null< bool >  __o_p_readable,::haxor::core::PixelFormat p_format)
{
HX_STACK_FRAME("haxor.thread.Kernel","new",0x7504c347,"haxor.thread.Kernel.new","haxor/thread/Kernel.hx",57,0xd58fcbe9)
HX_STACK_THIS(this)
HX_STACK_ARG(p_width,"p_width")
HX_STACK_ARG(p_height,"p_height")
HX_STACK_ARG(__o_p_readable,"p_readable")
HX_STACK_ARG(p_format,"p_format")
bool p_readable = __o_p_readable.Default(true);
{
	HX_STACK_LINE(58)
	super::__construct(null());
	HX_STACK_LINE(59)
	this->enabled = true;
	HX_STACK_LINE(60)
	::haxor::graphics::mesh::Mesh3 _g = ::haxor::graphics::mesh::Mesh3_obj::__new(null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(60)
	this->m_plane = _g;
	HX_STACK_LINE(63)
	::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new((int)-1,(int)1,(int)1);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(64)
	::haxor::math::Vector3 _g2 = ::haxor::math::Vector3_obj::__new((int)-1,(int)-1,(int)1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(65)
	::haxor::math::Vector3 _g3 = ::haxor::math::Vector3_obj::__new((int)1,(int)-1,(int)1);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(66)
	::haxor::math::Vector3 _g4 = ::haxor::math::Vector3_obj::__new((int)-1,(int)1,(int)1);		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(67)
	::haxor::math::Vector3 _g5 = ::haxor::math::Vector3_obj::__new((int)1,(int)-1,(int)1);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(68)
	::haxor::math::Vector3 _g6 = ::haxor::math::Vector3_obj::__new((int)1,(int)1,(int)1);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(62)
	Array< ::Dynamic > _g7 = Array_obj< ::Dynamic >::__new().Add(_g1).Add(_g2).Add(_g3).Add(_g4).Add(_g5).Add(_g6);		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(61)
	this->m_plane->set_vertex(_g7);
	HX_STACK_LINE(71)
	::haxor::graphics::texture::RenderTexture _g8 = ::haxor::graphics::texture::RenderTexture_obj::__new(p_width,p_height,(  (((p_format == null()))) ? ::haxor::core::PixelFormat(::haxor::core::PixelFormat_obj::RGBA8) : ::haxor::core::PixelFormat(p_format) ),null());		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(71)
	this->m_output = _g8;
	HX_STACK_LINE(72)
	::haxor::core::TextureFilter _g9 = this->m_output->set_magFilter(::haxor::core::TextureFilter_obj::Nearest);		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(72)
	this->m_output->set_minFilter(_g9);
	HX_STACK_LINE(73)
	int _g10 = this->get_uid();		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(73)
	::String _g11 = (HX_CSTRING("Kernel") + _g10);		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(73)
	::String _g12 = (_g11 + HX_CSTRING("Output"));		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(73)
	this->m_output->set_name(_g12);
	HX_STACK_LINE(75)
	int len = (p_width * p_height);		HX_STACK_VAR(len,"len");
	HX_STACK_LINE(76)
	switch( (int)(p_format->__Index())){
		case (int)0: {
			HX_STACK_LINE(78)
			::haxor::io::Buffer _g13 = ::haxor::io::Buffer_obj::__new(len);		HX_STACK_VAR(_g13,"_g13");
			HX_STACK_LINE(78)
			this->m_result = _g13;
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(79)
			::haxor::io::Buffer _g14 = ::haxor::io::Buffer_obj::__new((len * (int)3));		HX_STACK_VAR(_g14,"_g14");
			HX_STACK_LINE(79)
			this->m_result = _g14;
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(80)
			::haxor::io::Buffer _g15 = ::haxor::io::Buffer_obj::__new((len * (int)4));		HX_STACK_VAR(_g15,"_g15");
			HX_STACK_LINE(80)
			this->m_result = _g15;
		}
		;break;
		case (int)7: {
			HX_STACK_LINE(81)
			::haxor::io::FloatArray _g16 = ::haxor::io::FloatArray_obj::__new(len);		HX_STACK_VAR(_g16,"_g16");
			HX_STACK_LINE(81)
			this->m_result = _g16;
		}
		;break;
		case (int)8: {
			HX_STACK_LINE(82)
			::haxor::io::FloatArray _g17 = ::haxor::io::FloatArray_obj::__new((len * (int)3));		HX_STACK_VAR(_g17,"_g17");
			HX_STACK_LINE(82)
			this->m_result = _g17;
		}
		;break;
		case (int)9: {
			HX_STACK_LINE(83)
			::haxor::io::FloatArray _g18 = ::haxor::io::FloatArray_obj::__new((len * (int)4));		HX_STACK_VAR(_g18,"_g18");
			HX_STACK_LINE(83)
			this->m_result = _g18;
		}
		;break;
		case (int)1: {
		}
		;break;
		case (int)4: {
		}
		;break;
		case (int)5: {
		}
		;break;
		case (int)6: {
		}
		;break;
		case (int)10: {
		}
		;break;
	}
	HX_STACK_LINE(91)
	this->SetFloat(HX_CSTRING("width"),p_width);
	HX_STACK_LINE(92)
	this->SetFloat(HX_CSTRING("height"),p_height);
	HX_STACK_LINE(93)
	::haxor::context::EngineContext_obj::kernel->OnCreate(hx::ObjectPtr<OBJ_>(this));
}
;
	return null();
}

//Kernel_obj::~Kernel_obj() { }

Dynamic Kernel_obj::__CreateEmpty() { return  new Kernel_obj; }
hx::ObjectPtr< Kernel_obj > Kernel_obj::__new(int p_width,int p_height,hx::Null< bool >  __o_p_readable,::haxor::core::PixelFormat p_format)
{  hx::ObjectPtr< Kernel_obj > result = new Kernel_obj();
	result->__construct(p_width,p_height,__o_p_readable,p_format);
	return result;}

Dynamic Kernel_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Kernel_obj > result = new Kernel_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::haxor::io::Buffer Kernel_obj::get_result( ){
	HX_STACK_FRAME("haxor.thread.Kernel","get_result",0xc6c2209f,"haxor.thread.Kernel.get_result","haxor/thread/Kernel.hx",29,0xd58fcbe9)
	HX_STACK_THIS(this)
	HX_STACK_LINE(29)
	return this->m_result;
}


HX_DEFINE_DYNAMIC_FUNC0(Kernel_obj,get_result,return )

::haxor::graphics::texture::RenderTexture Kernel_obj::get_output( ){
	HX_STACK_FRAME("haxor.thread.Kernel","get_output",0xcabec6c3,"haxor.thread.Kernel.get_output","haxor/thread/Kernel.hx",41,0xd58fcbe9)
	HX_STACK_THIS(this)
	HX_STACK_LINE(41)
	return this->m_output;
}


HX_DEFINE_DYNAMIC_FUNC0(Kernel_obj,get_output,return )

Void Kernel_obj::Resize( hx::Null< int >  __o_p_width,hx::Null< int >  __o_p_height){
int p_width = __o_p_width.Default(-1);
int p_height = __o_p_height.Default(-1);
	HX_STACK_FRAME("haxor.thread.Kernel","Resize",0x64b2658d,"haxor.thread.Kernel.Resize","haxor/thread/Kernel.hx",102,0xd58fcbe9)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_width,"p_width")
	HX_STACK_ARG(p_height,"p_height")
{
		HX_STACK_LINE(103)
		Float ow = this->m_output->m_width;		HX_STACK_VAR(ow,"ow");
		HX_STACK_LINE(104)
		Float oh = this->m_output->m_height;		HX_STACK_VAR(oh,"oh");
		HX_STACK_LINE(106)
		Float w;		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(106)
		if (((p_width < (int)0))){
			HX_STACK_LINE(106)
			w = ow;
		}
		else{
			HX_STACK_LINE(106)
			w = p_width;
		}
		HX_STACK_LINE(107)
		Float h;		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(107)
		if (((p_height < (int)0))){
			HX_STACK_LINE(107)
			h = oh;
		}
		else{
			HX_STACK_LINE(107)
			h = p_height;
		}
		HX_STACK_LINE(109)
		w = ((int)-1 + ((int)2 * ((Float(w) / Float(ow)))));
		HX_STACK_LINE(110)
		h = ((int)-1 + ((int)2 * ((Float(h) / Float(oh)))));
		HX_STACK_LINE(114)
		::haxor::math::Vector3 _g = ::haxor::math::Vector3_obj::__new((int)-1,h,(int)1);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(115)
		::haxor::math::Vector3 _g1 = ::haxor::math::Vector3_obj::__new((int)-1,(int)-1,(int)1);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(116)
		::haxor::math::Vector3 _g2 = ::haxor::math::Vector3_obj::__new(w,(int)-1,(int)1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(117)
		::haxor::math::Vector3 _g3 = ::haxor::math::Vector3_obj::__new((int)-1,h,(int)1);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(118)
		::haxor::math::Vector3 _g4 = ::haxor::math::Vector3_obj::__new(w,(int)-1,(int)1);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(119)
		::haxor::math::Vector3 _g5 = ::haxor::math::Vector3_obj::__new(w,h,(int)1);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(113)
		Array< ::Dynamic > _g6 = Array_obj< ::Dynamic >::__new().Add(_g).Add(_g1).Add(_g2).Add(_g3).Add(_g4).Add(_g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(112)
		this->m_plane->set_vertex(_g6);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Kernel_obj,Resize,(void))

Void Kernel_obj::Execute( ){
{
		HX_STACK_FRAME("haxor.thread.Kernel","Execute",0x2000247c,"haxor.thread.Kernel.Execute","haxor/thread/Kernel.hx",127,0xd58fcbe9)
		HX_STACK_THIS(this)
		HX_STACK_LINE(128)
		if ((!(this->enabled))){
			HX_STACK_LINE(128)
			return null();
		}
		HX_STACK_LINE(129)
		if (((this->m_shader == null()))){
			HX_STACK_LINE(129)
			return null();
		}
		HX_STACK_LINE(130)
		::haxor::context::EngineContext_obj::texture->BindTarget(this->m_output);
		struct _Function_1_1{
			inline static ::haxor::math::AABB2 Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","haxor/thread/Kernel.hx",131,0xd58fcbe9)
				{
					HX_STACK_LINE(131)
					::haxor::context::DataContext _this = ::haxor::context::EngineContext_obj::data;		HX_STACK_VAR(_this,"_this");
					HX_STACK_LINE(131)
					int _g = _this->m_naabb2 = hx::Mod(((_this->m_naabb2 + (int)1)),_this->m_aabb2->length);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(131)
					return _this->m_aabb2->__get(_g).StaticCast< ::haxor::math::AABB2 >();
				}
				return null();
			}
		};
		HX_STACK_LINE(131)
		::haxor::math::AABB2 _g1 = (_Function_1_1::Block())->SetXYWH((int)0,(int)0,this->m_output->m_width,this->m_output->m_height);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(131)
		::haxor::graphics::Graphics_obj::Viewport(_g1);
		HX_STACK_LINE(132)
		::haxor::graphics::Graphics_obj::Render(this->m_plane,hx::ObjectPtr<OBJ_>(this),null(),null());
		HX_STACK_LINE(133)
		::haxor::context::EngineContext_obj::texture->BindTarget(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Kernel_obj,Execute,(void))

Void Kernel_obj::Update( hx::Null< int >  __o_p_x,hx::Null< int >  __o_p_y,hx::Null< int >  __o_p_width,hx::Null< int >  __o_p_height){
int p_x = __o_p_x.Default(0);
int p_y = __o_p_y.Default(0);
int p_width = __o_p_width.Default(-1);
int p_height = __o_p_height.Default(-1);
	HX_STACK_FRAME("haxor.thread.Kernel","Update",0xe33c91a2,"haxor.thread.Kernel.Update","haxor/thread/Kernel.hx",145,0xd58fcbe9)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_x,"p_x")
	HX_STACK_ARG(p_y,"p_y")
	HX_STACK_ARG(p_width,"p_width")
	HX_STACK_ARG(p_height,"p_height")
{
		HX_STACK_LINE(146)
		if ((!(this->enabled))){
			HX_STACK_LINE(146)
			return null();
		}
		HX_STACK_LINE(147)
		if (((this->m_shader == null()))){
			HX_STACK_LINE(147)
			return null();
		}
		HX_STACK_LINE(148)
		if (((this->m_result == null()))){
			HX_STACK_LINE(148)
			return null();
		}
		HX_STACK_LINE(149)
		int w;		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(149)
		if (((p_width <= (int)0))){
			HX_STACK_LINE(149)
			w = this->m_output->m_width;
		}
		else{
			HX_STACK_LINE(149)
			w = p_width;
		}
		HX_STACK_LINE(150)
		int h;		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(150)
		if (((p_height <= (int)0))){
			HX_STACK_LINE(150)
			h = this->m_output->m_height;
		}
		else{
			HX_STACK_LINE(150)
			h = p_height;
		}
		HX_STACK_LINE(151)
		::haxor::context::EngineContext_obj::texture->BindTarget(this->m_output);
		HX_STACK_LINE(152)
		::haxor::graphics::Graphics_obj::ReadPixels(p_x,p_y,w,h,this->m_result->m_buffer);
		HX_STACK_LINE(153)
		::haxor::context::EngineContext_obj::texture->BindTarget(null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Kernel_obj,Update,(void))

Void Kernel_obj::OnDestroy( ){
{
		HX_STACK_FRAME("haxor.thread.Kernel","OnDestroy",0x86d45fa2,"haxor.thread.Kernel.OnDestroy","haxor/thread/Kernel.hx",160,0xd58fcbe9)
		HX_STACK_THIS(this)
		HX_STACK_LINE(161)
		this->super::OnDestroy();
		HX_STACK_LINE(162)
		::haxor::core::Resource_obj::Destroy(this->m_output);
		HX_STACK_LINE(163)
		::haxor::core::Resource_obj::Destroy(this->m_plane);
		HX_STACK_LINE(164)
		::haxor::context::EngineContext_obj::kernel->OnDestroy(hx::ObjectPtr<OBJ_>(this));
	}
return null();
}



Kernel_obj::Kernel_obj()
{
}

void Kernel_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Kernel);
	HX_MARK_MEMBER_NAME(m_result,"m_result");
	HX_MARK_MEMBER_NAME(enabled,"enabled");
	HX_MARK_MEMBER_NAME(m_output,"m_output");
	HX_MARK_MEMBER_NAME(m_plane,"m_plane");
	::haxor::graphics::material::Material_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Kernel_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_result,"m_result");
	HX_VISIT_MEMBER_NAME(enabled,"enabled");
	HX_VISIT_MEMBER_NAME(m_output,"m_output");
	HX_VISIT_MEMBER_NAME(m_plane,"m_plane");
	::haxor::graphics::material::Material_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Kernel_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"result") ) { return get_result(); }
		if (HX_FIELD_EQ(inName,"output") ) { return get_output(); }
		if (HX_FIELD_EQ(inName,"Resize") ) { return Resize_dyn(); }
		if (HX_FIELD_EQ(inName,"Update") ) { return Update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { return enabled; }
		if (HX_FIELD_EQ(inName,"m_plane") ) { return m_plane; }
		if (HX_FIELD_EQ(inName,"Execute") ) { return Execute_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_result") ) { return m_result; }
		if (HX_FIELD_EQ(inName,"m_output") ) { return m_output; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"OnDestroy") ) { return OnDestroy_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"get_result") ) { return get_result_dyn(); }
		if (HX_FIELD_EQ(inName,"get_output") ) { return get_output_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Kernel_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"enabled") ) { enabled=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_plane") ) { m_plane=inValue.Cast< ::haxor::graphics::mesh::Mesh3 >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"m_result") ) { m_result=inValue.Cast< ::haxor::io::Buffer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_output") ) { m_output=inValue.Cast< ::haxor::graphics::texture::RenderTexture >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Kernel_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("result"));
	outFields->push(HX_CSTRING("m_result"));
	outFields->push(HX_CSTRING("enabled"));
	outFields->push(HX_CSTRING("output"));
	outFields->push(HX_CSTRING("m_output"));
	outFields->push(HX_CSTRING("m_plane"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::io::Buffer*/ ,(int)offsetof(Kernel_obj,m_result),HX_CSTRING("m_result")},
	{hx::fsBool,(int)offsetof(Kernel_obj,enabled),HX_CSTRING("enabled")},
	{hx::fsObject /*::haxor::graphics::texture::RenderTexture*/ ,(int)offsetof(Kernel_obj,m_output),HX_CSTRING("m_output")},
	{hx::fsObject /*::haxor::graphics::mesh::Mesh3*/ ,(int)offsetof(Kernel_obj,m_plane),HX_CSTRING("m_plane")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_result"),
	HX_CSTRING("m_result"),
	HX_CSTRING("enabled"),
	HX_CSTRING("get_output"),
	HX_CSTRING("m_output"),
	HX_CSTRING("m_plane"),
	HX_CSTRING("Resize"),
	HX_CSTRING("Execute"),
	HX_CSTRING("Update"),
	HX_CSTRING("OnDestroy"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Kernel_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Kernel_obj::__mClass,"__mClass");
};

#endif

Class Kernel_obj::__mClass;

void Kernel_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.thread.Kernel"), hx::TCanCast< Kernel_obj> ,sStaticFields,sMemberFields,
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

void Kernel_obj::__boot()
{
}

} // end namespace haxor
} // end namespace thread
