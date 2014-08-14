#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxor_component_Behaviour
#include <haxor/component/Behaviour.h>
#endif
#ifndef INCLUDED_haxor_component_Component
#include <haxor/component/Component.h>
#endif
#ifndef INCLUDED_haxor_core_BaseApplication
#include <haxor/core/BaseApplication.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GL
#include <haxor/platform/graphics/GL.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_GraphicAPI
#include <haxor/platform/graphics/GraphicAPI.h>
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
namespace haxor{
namespace platform{
namespace graphics{

Void OpenGL_obj::__construct(::haxor::core::BaseApplication p_application)
{
HX_STACK_FRAME("haxor.platform.graphics.OpenGL","new",0xa0d46c35,"haxor.platform.graphics.OpenGL.new","haxor/platform/graphics/OpenGL.hx",46,0x3c17389a)
HX_STACK_THIS(this)
HX_STACK_ARG(p_application,"p_application")
{
	HX_STACK_LINE(47)
	super::__construct(p_application);
	HX_STACK_LINE(48)
	this->m_api = ::haxor::platform::graphics::GraphicAPI_obj::OpenGL;
}
;
	return null();
}

//OpenGL_obj::~OpenGL_obj() { }

Dynamic OpenGL_obj::__CreateEmpty() { return  new OpenGL_obj; }
hx::ObjectPtr< OpenGL_obj > OpenGL_obj::__new(::haxor::core::BaseApplication p_application)
{  hx::ObjectPtr< OpenGL_obj > result = new OpenGL_obj();
	result->__construct(p_application);
	return result;}

Dynamic OpenGL_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< OpenGL_obj > result = new OpenGL_obj();
	result->__construct(inArgs[0]);
	return result;}

Void OpenGL_obj::BindBuffer( int p_target,int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","BindBuffer",0x81014f88,"haxor.platform.graphics.OpenGL.BindBuffer","haxor/platform/graphics/OpenGL.hx",52,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(52)
		glBindBuffer(p_target,p_id);;
	}
return null();
}


Void OpenGL_obj::BufferData( int p_target,::haxor::io::Buffer p_data,int p_mode){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","BufferData",0x1bb67c35,"haxor.platform.graphics.OpenGL.BufferData","haxor/platform/graphics/OpenGL.hx",54,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_ARG(p_mode,"p_mode")
		HX_STACK_LINE(55)
		int _g = p_data->get_bytesPerElement();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(55)
		int bl = (p_data->m_length * _g);		HX_STACK_VAR(bl,"bl");
		HX_STACK_LINE(56)
		::haxe::io::Bytes ba = p_data->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(57)
		glBufferData(p_target, bl, (void*)&ba->b[0], p_mode);;
	}
return null();
}


Void OpenGL_obj::BufferSubData( int p_target,int p_offset,::haxor::io::Buffer p_data){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","BufferSubData",0xb254de9f,"haxor.platform.graphics.OpenGL.BufferSubData","haxor/platform/graphics/OpenGL.hx",60,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_offset,"p_offset")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_LINE(61)
		int _g = p_data->get_bytesPerElement();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(61)
		int bl = (p_data->m_length * _g);		HX_STACK_VAR(bl,"bl");
		HX_STACK_LINE(62)
		::haxe::io::Bytes ba = p_data->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(63)
		glBufferSubData(p_target, p_offset,bl,(void*)&ba->b[0]);;
	}
return null();
}


int OpenGL_obj::CreateBuffer( ){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CreateBuffer",0x1f060ac7,"haxor.platform.graphics.OpenGL.CreateBuffer","haxor/platform/graphics/OpenGL.hx",65,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(65)
	GLuint id; glGenBuffers(1, &id); return id;;
	HX_STACK_LINE(65)
	return ::haxor::platform::graphics::GL_obj::_NULL;
}


Void OpenGL_obj::DrawArrays( int p_primitive,int p_start,int p_count){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DrawArrays",0x81f6b0c9,"haxor.platform.graphics.OpenGL.DrawArrays","haxor/platform/graphics/OpenGL.hx",66,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_primitive,"p_primitive")
		HX_STACK_ARG(p_start,"p_start")
		HX_STACK_ARG(p_count,"p_count")
		HX_STACK_LINE(66)
		glDrawArrays(p_primitive, p_start, p_count);;
	}
return null();
}


Void OpenGL_obj::DrawElements( int p_primitive,int p_count,int p_type,int p_offset){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DrawElements",0x85d3d006,"haxor.platform.graphics.OpenGL.DrawElements","haxor/platform/graphics/OpenGL.hx",67,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_primitive,"p_primitive")
		HX_STACK_ARG(p_count,"p_count")
		HX_STACK_ARG(p_type,"p_type")
		HX_STACK_ARG(p_offset,"p_offset")
		HX_STACK_LINE(67)
		glDrawElements(p_primitive, p_count, p_type,(void*)p_offset);;
	}
return null();
}


Void OpenGL_obj::DeleteBuffer( int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DeleteBuffer",0x6348f136,"haxor.platform.graphics.OpenGL.DeleteBuffer","haxor/platform/graphics/OpenGL.hx",68,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(68)
		GLuint id = p_id; glDeleteBuffers(1, &id);;
	}
return null();
}


Void OpenGL_obj::DisableVertexAttrib( int p_location){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DisableVertexAttrib",0x5b69998b,"haxor.platform.graphics.OpenGL.DisableVertexAttrib","haxor/platform/graphics/OpenGL.hx",69,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_LINE(69)
		glDisableVertexAttribArray(p_location);;
	}
return null();
}


Void OpenGL_obj::EnableVertexAttrib( int p_location){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","EnableVertexAttrib",0x7d132cdc,"haxor.platform.graphics.OpenGL.EnableVertexAttrib","haxor/platform/graphics/OpenGL.hx",70,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_LINE(70)
		glEnableVertexAttribArray(p_location);;
	}
return null();
}


Void OpenGL_obj::VertexAttrib3f( int p_location,Float p_x,Float p_y,Float p_z){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","VertexAttrib3f",0xc931a48c,"haxor.platform.graphics.OpenGL.VertexAttrib3f","haxor/platform/graphics/OpenGL.hx",71,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(71)
		glVertexAttrib3f(p_location,p_x,p_y,p_z);;
	}
return null();
}


Void OpenGL_obj::VertexAttrib4f( int p_location,Float p_x,Float p_y,Float p_z,Float p_w){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","VertexAttrib4f",0xc931a56b,"haxor.platform.graphics.OpenGL.VertexAttrib4f","haxor/platform/graphics/OpenGL.hx",72,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(72)
		glVertexAttrib4f(p_location,p_x,p_y,p_z,p_w);;
	}
return null();
}


Void OpenGL_obj::VertexAttribPointer( int p_location,int p_components_size,int p_type,bool p_normalized,int p_stride,int p_offset){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","VertexAttribPointer",0xd397d244,"haxor.platform.graphics.OpenGL.VertexAttribPointer","haxor/platform/graphics/OpenGL.hx",73,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_components_size,"p_components_size")
		HX_STACK_ARG(p_type,"p_type")
		HX_STACK_ARG(p_normalized,"p_normalized")
		HX_STACK_ARG(p_stride,"p_stride")
		HX_STACK_ARG(p_offset,"p_offset")
		HX_STACK_LINE(73)
		glVertexAttribPointer(p_location,p_components_size,p_type,p_normalized,p_stride,(void*)p_offset);;
	}
return null();
}


Void OpenGL_obj::CompileShader( int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CompileShader",0x472258ed,"haxor.platform.graphics.OpenGL.CompileShader","haxor/platform/graphics/OpenGL.hx",76,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_LINE(76)
		glCompileShader(p_shader);;
	}
return null();
}


int OpenGL_obj::CreateShader( int p_type){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CreateShader",0x6b920cec,"haxor.platform.graphics.OpenGL.CreateShader","haxor/platform/graphics/OpenGL.hx",77,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(77)
	return glCreateShader(p_type);;
	HX_STACK_LINE(77)
	return ::haxor::platform::graphics::GL_obj::_NULL;
}


Void OpenGL_obj::DetachShader( int p_program,int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DetachShader",0x16c9de83,"haxor.platform.graphics.OpenGL.DetachShader","haxor/platform/graphics/OpenGL.hx",78,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_LINE(78)
		glDetachShader(p_program, p_shader);;
	}
return null();
}


Void OpenGL_obj::DeleteShader( int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DeleteShader",0xafd4f35b,"haxor.platform.graphics.OpenGL.DeleteShader","haxor/platform/graphics/OpenGL.hx",79,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_LINE(79)
		glDeleteShader(p_shader);;
	}
return null();
}


::String OpenGL_obj::GetShaderInfoLog( int p_shader){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GetShaderInfoLog",0x08f47cc6,"haxor.platform.graphics.OpenGL.GetShaderInfoLog","haxor/platform/graphics/OpenGL.hx",80,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_shader,"p_shader")
	HX_STACK_LINE(80)
	char s[1024]; glGetShaderInfoLog(p_shader,1024,0,s); return s;;
	HX_STACK_LINE(80)
	return HX_CSTRING("");
}


int OpenGL_obj::GetShaderParameter( int p_shader,int p_parameter){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GetShaderParameter",0xbd5589b9,"haxor.platform.graphics.OpenGL.GetShaderParameter","haxor/platform/graphics/OpenGL.hx",81,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_shader,"p_shader")
	HX_STACK_ARG(p_parameter,"p_parameter")
	HX_STACK_LINE(81)
	int d[1]; glGetShaderiv(p_shader, p_parameter, d); return d[0];;
	HX_STACK_LINE(81)
	return (int)-1;
}


Void OpenGL_obj::ShaderSource( int p_shader,::String p_source){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","ShaderSource",0xce365b8b,"haxor.platform.graphics.OpenGL.ShaderSource","haxor/platform/graphics/OpenGL.hx",83,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_ARG(p_source,"p_source")
		HX_STACK_LINE(84)
		int len = p_source.length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(85)
		
		const char ** str = (const char ** ) &p_source.__s;		
		glShaderSource(p_shader, 1, str, & len);
		;
	}
return null();
}


Void OpenGL_obj::AttachShader( int p_program,int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","AttachShader",0xde93de75,"haxor.platform.graphics.OpenGL.AttachShader","haxor/platform/graphics/OpenGL.hx",90,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_LINE(90)
		glAttachShader(p_program, p_shader);;
	}
return null();
}


Void OpenGL_obj::BindAttribLocation( int p_program,int p_location,::String p_name){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","BindAttribLocation",0xa52ac627,"haxor.platform.graphics.OpenGL.BindAttribLocation","haxor/platform/graphics/OpenGL.hx",91,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_LINE(91)
		glBindAttribLocation(p_program, p_location, p_name.__s);;
	}
return null();
}


int OpenGL_obj::CreateProgram( ){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CreateProgram",0x48ac0add,"haxor.platform.graphics.OpenGL.CreateProgram","haxor/platform/graphics/OpenGL.hx",92,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(92)
	return glCreateProgram();;
	HX_STACK_LINE(92)
	return ::haxor::platform::graphics::GL_obj::_NULL;
}


Void OpenGL_obj::DeleteProgram( int p_program){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DeleteProgram",0xbef2c58e,"haxor.platform.graphics.OpenGL.DeleteProgram","haxor/platform/graphics/OpenGL.hx",93,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_LINE(93)
		glDeleteProgram(p_program);;
	}
return null();
}


int OpenGL_obj::GetAttribLocation( int p_program,::String p_name){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GetAttribLocation",0xce2ba14a,"haxor.platform.graphics.OpenGL.GetAttribLocation","haxor/platform/graphics/OpenGL.hx",94,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(94)
	return glGetAttribLocation(p_program,p_name.__s);;
	HX_STACK_LINE(94)
	return (int)-1;
}


::String OpenGL_obj::GetProgramInfoLog( int p_program){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GetProgramInfoLog",0x3f0e783d,"haxor.platform.graphics.OpenGL.GetProgramInfoLog","haxor/platform/graphics/OpenGL.hx",95,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_LINE(95)
	char s[1024]; glGetProgramInfoLog(p_program,1024,0,s); return s;;
	HX_STACK_LINE(95)
	return HX_CSTRING("");
}


int OpenGL_obj::GetProgramParameter( int p_program,int p_parameter){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GetProgramParameter",0x2a7e90f0,"haxor.platform.graphics.OpenGL.GetProgramParameter","haxor/platform/graphics/OpenGL.hx",96,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_ARG(p_parameter,"p_parameter")
	HX_STACK_LINE(96)
	int d[1]; glGetProgramiv(p_program, p_parameter, d); return d[0];;
	HX_STACK_LINE(96)
	return (int)-1;
}


Void OpenGL_obj::LinkProgram( int p_program){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","LinkProgram",0x3b9e3e5f,"haxor.platform.graphics.OpenGL.LinkProgram","haxor/platform/graphics/OpenGL.hx",97,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_LINE(97)
		glLinkProgram(p_program);;
	}
return null();
}


Void OpenGL_obj::UseProgram( int p_program){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","UseProgram",0x7eef29e8,"haxor.platform.graphics.OpenGL.UseProgram","haxor/platform/graphics/OpenGL.hx",98,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_LINE(98)
		glUseProgram(p_program);;
	}
return null();
}


Void OpenGL_obj::BlendFunc( int p_src,int p_dst){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","BlendFunc",0xc23185aa,"haxor.platform.graphics.OpenGL.BlendFunc","haxor/platform/graphics/OpenGL.hx",101,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_src,"p_src")
		HX_STACK_ARG(p_dst,"p_dst")
		HX_STACK_LINE(101)
		glBlendFunc(p_src, p_dst);;
	}
return null();
}


Void OpenGL_obj::Disable( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Disable",0x1f6d3c1d,"haxor.platform.graphics.OpenGL.Disable","haxor/platform/graphics/OpenGL.hx",102,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(102)
		glDisable(p_flag);;
	}
return null();
}


Void OpenGL_obj::Enable( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Enable",0xdd78d9ee,"haxor.platform.graphics.OpenGL.Enable","haxor/platform/graphics/OpenGL.hx",103,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(103)
		glEnable(p_flag);;
	}
return null();
}


Void OpenGL_obj::DepthMask( bool p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DepthMask",0x596f2504,"haxor.platform.graphics.OpenGL.DepthMask","haxor/platform/graphics/OpenGL.hx",104,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(104)
		glDepthMask(p_flag);;
	}
return null();
}


Void OpenGL_obj::DepthFunc( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DepthFunc",0x54ddcf5c,"haxor.platform.graphics.OpenGL.DepthFunc","haxor/platform/graphics/OpenGL.hx",105,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(105)
		glDepthFunc(p_flag);;
	}
return null();
}


Void OpenGL_obj::CullFace( int p_face){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CullFace",0x9055039a,"haxor.platform.graphics.OpenGL.CullFace","haxor/platform/graphics/OpenGL.hx",106,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_face,"p_face")
		HX_STACK_LINE(106)
		glCullFace(p_face);;
	}
return null();
}


Void OpenGL_obj::FrontFace( int p_face){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","FrontFace",0x3b568b5b,"haxor.platform.graphics.OpenGL.FrontFace","haxor/platform/graphics/OpenGL.hx",107,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_face,"p_face")
		HX_STACK_LINE(107)
		glFrontFace(p_face);;
	}
return null();
}


Void OpenGL_obj::Clear( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Clear",0x1247dc82,"haxor.platform.graphics.OpenGL.Clear","haxor/platform/graphics/OpenGL.hx",110,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(110)
		glClear(p_flag);;
	}
return null();
}


Void OpenGL_obj::ClearDepth( Float p_value){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","ClearDepth",0x3476ed21,"haxor.platform.graphics.OpenGL.ClearDepth","haxor/platform/graphics/OpenGL.hx",111,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(111)
		glClearDepthf(p_value);;
	}
return null();
}


Void OpenGL_obj::ClearColor( Float p_r,Float p_g,Float p_b,Float p_a){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","ClearColor",0xa7a96d81,"haxor.platform.graphics.OpenGL.ClearColor","haxor/platform/graphics/OpenGL.hx",112,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_r,"p_r")
		HX_STACK_ARG(p_g,"p_g")
		HX_STACK_ARG(p_b,"p_b")
		HX_STACK_ARG(p_a,"p_a")
		HX_STACK_LINE(112)
		glClearColor(p_r, p_g, p_b, p_a);;
	}
return null();
}


int OpenGL_obj::GetErrorCode( ){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GetErrorCode",0xa39fd74a,"haxor.platform.graphics.OpenGL.GetErrorCode","haxor/platform/graphics/OpenGL.hx",115,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(115)
	return glGetError();;
	HX_STACK_LINE(115)
	return (int)0;
}



OpenGL_obj::OpenGL_obj()
{
}

Dynamic OpenGL_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Enable") ) { return Enable_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Disable") ) { return Disable_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"CullFace") ) { return CullFace_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"BlendFunc") ) { return BlendFunc_dyn(); }
		if (HX_FIELD_EQ(inName,"DepthMask") ) { return DepthMask_dyn(); }
		if (HX_FIELD_EQ(inName,"DepthFunc") ) { return DepthFunc_dyn(); }
		if (HX_FIELD_EQ(inName,"FrontFace") ) { return FrontFace_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"BindBuffer") ) { return BindBuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"BufferData") ) { return BufferData_dyn(); }
		if (HX_FIELD_EQ(inName,"DrawArrays") ) { return DrawArrays_dyn(); }
		if (HX_FIELD_EQ(inName,"UseProgram") ) { return UseProgram_dyn(); }
		if (HX_FIELD_EQ(inName,"ClearDepth") ) { return ClearDepth_dyn(); }
		if (HX_FIELD_EQ(inName,"ClearColor") ) { return ClearColor_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"LinkProgram") ) { return LinkProgram_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"CreateBuffer") ) { return CreateBuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"DrawElements") ) { return DrawElements_dyn(); }
		if (HX_FIELD_EQ(inName,"DeleteBuffer") ) { return DeleteBuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateShader") ) { return CreateShader_dyn(); }
		if (HX_FIELD_EQ(inName,"DetachShader") ) { return DetachShader_dyn(); }
		if (HX_FIELD_EQ(inName,"DeleteShader") ) { return DeleteShader_dyn(); }
		if (HX_FIELD_EQ(inName,"ShaderSource") ) { return ShaderSource_dyn(); }
		if (HX_FIELD_EQ(inName,"AttachShader") ) { return AttachShader_dyn(); }
		if (HX_FIELD_EQ(inName,"GetErrorCode") ) { return GetErrorCode_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"BufferSubData") ) { return BufferSubData_dyn(); }
		if (HX_FIELD_EQ(inName,"CompileShader") ) { return CompileShader_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateProgram") ) { return CreateProgram_dyn(); }
		if (HX_FIELD_EQ(inName,"DeleteProgram") ) { return DeleteProgram_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"VertexAttrib3f") ) { return VertexAttrib3f_dyn(); }
		if (HX_FIELD_EQ(inName,"VertexAttrib4f") ) { return VertexAttrib4f_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"GetShaderInfoLog") ) { return GetShaderInfoLog_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"GetAttribLocation") ) { return GetAttribLocation_dyn(); }
		if (HX_FIELD_EQ(inName,"GetProgramInfoLog") ) { return GetProgramInfoLog_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"EnableVertexAttrib") ) { return EnableVertexAttrib_dyn(); }
		if (HX_FIELD_EQ(inName,"GetShaderParameter") ) { return GetShaderParameter_dyn(); }
		if (HX_FIELD_EQ(inName,"BindAttribLocation") ) { return BindAttribLocation_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"DisableVertexAttrib") ) { return DisableVertexAttrib_dyn(); }
		if (HX_FIELD_EQ(inName,"VertexAttribPointer") ) { return VertexAttribPointer_dyn(); }
		if (HX_FIELD_EQ(inName,"GetProgramParameter") ) { return GetProgramParameter_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic OpenGL_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void OpenGL_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("BindBuffer"),
	HX_CSTRING("BufferData"),
	HX_CSTRING("BufferSubData"),
	HX_CSTRING("CreateBuffer"),
	HX_CSTRING("DrawArrays"),
	HX_CSTRING("DrawElements"),
	HX_CSTRING("DeleteBuffer"),
	HX_CSTRING("DisableVertexAttrib"),
	HX_CSTRING("EnableVertexAttrib"),
	HX_CSTRING("VertexAttrib3f"),
	HX_CSTRING("VertexAttrib4f"),
	HX_CSTRING("VertexAttribPointer"),
	HX_CSTRING("CompileShader"),
	HX_CSTRING("CreateShader"),
	HX_CSTRING("DetachShader"),
	HX_CSTRING("DeleteShader"),
	HX_CSTRING("GetShaderInfoLog"),
	HX_CSTRING("GetShaderParameter"),
	HX_CSTRING("ShaderSource"),
	HX_CSTRING("AttachShader"),
	HX_CSTRING("BindAttribLocation"),
	HX_CSTRING("CreateProgram"),
	HX_CSTRING("DeleteProgram"),
	HX_CSTRING("GetAttribLocation"),
	HX_CSTRING("GetProgramInfoLog"),
	HX_CSTRING("GetProgramParameter"),
	HX_CSTRING("LinkProgram"),
	HX_CSTRING("UseProgram"),
	HX_CSTRING("BlendFunc"),
	HX_CSTRING("Disable"),
	HX_CSTRING("Enable"),
	HX_CSTRING("DepthMask"),
	HX_CSTRING("DepthFunc"),
	HX_CSTRING("CullFace"),
	HX_CSTRING("FrontFace"),
	HX_CSTRING("Clear"),
	HX_CSTRING("ClearDepth"),
	HX_CSTRING("ClearColor"),
	HX_CSTRING("GetErrorCode"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(OpenGL_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(OpenGL_obj::__mClass,"__mClass");
};

#endif

Class OpenGL_obj::__mClass;

void OpenGL_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.graphics.OpenGL"), hx::TCanCast< OpenGL_obj> ,sStaticFields,sMemberFields,
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

void OpenGL_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace graphics
