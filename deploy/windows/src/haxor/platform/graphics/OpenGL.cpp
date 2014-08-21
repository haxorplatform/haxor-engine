#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
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
#ifndef INCLUDED_haxor_core_Console
#include <haxor/core/Console.h>
#endif
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
#endif
#ifndef INCLUDED_haxor_graphics_GL
#include <haxor/graphics/GL.h>
#endif
#ifndef INCLUDED_haxor_graphics_GraphicAPI
#include <haxor/graphics/GraphicAPI.h>
#endif
#ifndef INCLUDED_haxor_graphics_GraphicContext
#include <haxor/graphics/GraphicContext.h>
#endif
#ifndef INCLUDED_haxor_io_Buffer
#include <haxor/io/Buffer.h>
#endif
#ifndef INCLUDED_haxor_io_FloatArray
#include <haxor/io/FloatArray.h>
#endif
#ifndef INCLUDED_haxor_io_Int32Array
#include <haxor/io/Int32Array.h>
#endif
#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#include <haxor/platform/graphics/OpenGL.h>
#endif
#ifndef INCLUDED_haxor_platform_windows_graphics_WinGL
#include <haxor/platform/windows/graphics/WinGL.h>
#endif
namespace haxor{
namespace platform{
namespace graphics{

Void OpenGL_obj::__construct(::haxor::core::BaseApplication p_application)
{
HX_STACK_FRAME("haxor.platform.graphics.OpenGL","new",0xa0d46c35,"haxor.platform.graphics.OpenGL.new","haxor/platform/graphics/OpenGL.hx",52,0x3c17389a)
HX_STACK_THIS(this)
HX_STACK_ARG(p_application,"p_application")
{
	HX_STACK_LINE(53)
	super::__construct(p_application);
	HX_STACK_LINE(54)
	this->m_api = ::haxor::graphics::GraphicAPI_obj::OpenGL;
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

Void OpenGL_obj::CheckExtensions( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CheckExtensions",0x58fb7231,"haxor.platform.graphics.OpenGL.CheckExtensions","haxor/platform/graphics/OpenGL.hx",58,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_LINE(59)
		this->Focus();
		HX_STACK_LINE(60)
		::String extstr = HX_CSTRING("");		HX_STACK_VAR(extstr,"extstr");
		HX_STACK_LINE(61)
		
		const char *str = (const char *)glGetString(GL_EXTENSIONS);
		int len = strlen(str);
		extstr.__s = str;
		extstr.length = len;				
		;
		HX_STACK_LINE(68)
		Float f = 0.0;		HX_STACK_VAR(f,"f");
		HX_STACK_LINE(69)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(71)
		Array< ::String > exts = extstr.split(HX_CSTRING(" "));		HX_STACK_VAR(exts,"exts");
		HX_STACK_LINE(72)
		{
			HX_STACK_LINE(72)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(72)
			int _g = exts->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(72)
			while((true)){
				HX_STACK_LINE(72)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(72)
					break;
				}
				HX_STACK_LINE(72)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(74)
				::String n = exts->__get(i1);		HX_STACK_VAR(n,"n");
				HX_STACK_LINE(75)
				::String _g2 = ::StringTools_obj::replace(n,HX_CSTRING("GL_"),HX_CSTRING(""));		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(75)
				n = _g2;
				HX_STACK_LINE(76)
				if (((n == HX_CSTRING("")))){
					HX_STACK_LINE(76)
					continue;
				}
				HX_STACK_LINE(77)
				::haxor::core::Console_obj::Log((HX_CSTRING("\t") + n),null());
				HX_STACK_LINE(78)
				::String _switch_1 = (n);
				if (  ( _switch_1==HX_CSTRING("ARB_texture_half_float"))){
					HX_STACK_LINE(81)
					::haxor::graphics::GL_obj::HALF_FLOAT = (int)36193;
					HX_STACK_LINE(82)
					::haxor::graphics::GL_obj::TEXTURE_HALF = true;
				}
				else if (  ( _switch_1==HX_CSTRING("ARB_texture_half_float_linear"))){
					HX_STACK_LINE(85)
					::haxor::graphics::GL_obj::TEXTURE_HALF_LINEAR = true;
				}
				else if (  ( _switch_1==HX_CSTRING("EXT_texture_filter_anisotropic"))){
					HX_STACK_LINE(88)
					glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &f);;
					HX_STACK_LINE(89)
					::haxor::graphics::GL_obj::MAX_TEXTURE_ANISOTROPY = f;
					HX_STACK_LINE(90)
					::haxor::graphics::GL_obj::TEXTURE_ANISOTROPY_ENABLED = true;
					HX_STACK_LINE(91)
					::haxor::core::Console_obj::Log((HX_CSTRING("\t\tMAX_TEXTURE_MAX_ANISOTROPY: ") + ::haxor::graphics::GL_obj::MAX_TEXTURE_ANISOTROPY),null());
				}
				else if (  ( _switch_1==HX_CSTRING("ARB_texture_float"))){
					HX_STACK_LINE(94)
					::haxor::graphics::GL_obj::TEXTURE_FLOAT = true;
				}
				else if (  ( _switch_1==HX_CSTRING("ARB_depth_texture"))){
					HX_STACK_LINE(97)
					::haxor::graphics::GL_obj::TEXTURE_DEPTH_ENABLED = true;
				}
			}
		}
		HX_STACK_LINE(102)
		glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &i);;
		HX_STACK_LINE(103)
		::haxor::graphics::GL_obj::MAX_ACTIVE_TEXTURE = i;
		HX_STACK_LINE(104)
		::haxor::core::Console_obj::Log((HX_CSTRING("\tMax Active Textures: ") + i),null());
	}
return null();
}


Void OpenGL_obj::BindBuffer( int p_target,int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","BindBuffer",0x81014f88,"haxor.platform.graphics.OpenGL.BindBuffer","haxor/platform/graphics/OpenGL.hx",109,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(109)
		glBindBuffer(p_target,p_id);;
	}
return null();
}


Void OpenGL_obj::BufferData( int p_target,::haxor::io::Buffer p_data,int p_mode){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","BufferData",0x1bb67c35,"haxor.platform.graphics.OpenGL.BufferData","haxor/platform/graphics/OpenGL.hx",111,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_ARG(p_mode,"p_mode")
		HX_STACK_LINE(112)
		int _g = p_data->get_bytesPerElement();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(112)
		int bl = (p_data->m_length * _g);		HX_STACK_VAR(bl,"bl");
		HX_STACK_LINE(113)
		::haxe::io::Bytes ba = p_data->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(114)
		glBufferData(p_target, bl, (void*)&ba->b[0], p_mode);;
	}
return null();
}


Void OpenGL_obj::BufferSubData( int p_target,int p_offset,::haxor::io::Buffer p_data){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","BufferSubData",0xb254de9f,"haxor.platform.graphics.OpenGL.BufferSubData","haxor/platform/graphics/OpenGL.hx",117,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_offset,"p_offset")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_LINE(118)
		int _g = p_data->get_bytesPerElement();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(118)
		int bl = (p_data->m_length * _g);		HX_STACK_VAR(bl,"bl");
		HX_STACK_LINE(119)
		::haxe::io::Bytes ba = p_data->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(120)
		glBufferSubData(p_target, p_offset,bl,(void*)&ba->b[0]);;
	}
return null();
}


int OpenGL_obj::CreateBuffer( ){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CreateBuffer",0x1f060ac7,"haxor.platform.graphics.OpenGL.CreateBuffer","haxor/platform/graphics/OpenGL.hx",123,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(123)
	GLuint id; glGenBuffers(1, &id); return id;;
	HX_STACK_LINE(123)
	return ::haxor::graphics::GL_obj::INVALID;
}


Void OpenGL_obj::DrawArrays( int p_primitive,int p_start,int p_count){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DrawArrays",0x81f6b0c9,"haxor.platform.graphics.OpenGL.DrawArrays","haxor/platform/graphics/OpenGL.hx",124,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_primitive,"p_primitive")
		HX_STACK_ARG(p_start,"p_start")
		HX_STACK_ARG(p_count,"p_count")
		HX_STACK_LINE(124)
		glDrawArrays(p_primitive, p_start, p_count);;
	}
return null();
}


Void OpenGL_obj::DrawElements( int p_primitive,int p_count,int p_type,int p_offset){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DrawElements",0x85d3d006,"haxor.platform.graphics.OpenGL.DrawElements","haxor/platform/graphics/OpenGL.hx",125,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_primitive,"p_primitive")
		HX_STACK_ARG(p_count,"p_count")
		HX_STACK_ARG(p_type,"p_type")
		HX_STACK_ARG(p_offset,"p_offset")
		HX_STACK_LINE(125)
		glDrawElements(p_primitive, p_count, p_type,(void*)p_offset);;
	}
return null();
}


Void OpenGL_obj::DeleteBuffer( int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DeleteBuffer",0x6348f136,"haxor.platform.graphics.OpenGL.DeleteBuffer","haxor/platform/graphics/OpenGL.hx",126,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(126)
		GLuint id = p_id; glDeleteBuffers(1, &id);;
	}
return null();
}


Void OpenGL_obj::DisableVertexAttrib( int p_location){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DisableVertexAttrib",0x5b69998b,"haxor.platform.graphics.OpenGL.DisableVertexAttrib","haxor/platform/graphics/OpenGL.hx",127,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_LINE(127)
		glDisableVertexAttribArray(p_location);;
	}
return null();
}


Void OpenGL_obj::EnableVertexAttrib( int p_location){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","EnableVertexAttrib",0x7d132cdc,"haxor.platform.graphics.OpenGL.EnableVertexAttrib","haxor/platform/graphics/OpenGL.hx",128,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_LINE(128)
		glEnableVertexAttribArray(p_location);;
	}
return null();
}


Void OpenGL_obj::VertexAttrib3f( int p_location,Float p_x,Float p_y,Float p_z){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","VertexAttrib3f",0xc931a48c,"haxor.platform.graphics.OpenGL.VertexAttrib3f","haxor/platform/graphics/OpenGL.hx",129,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(129)
		glVertexAttrib3f(p_location,p_x,p_y,p_z);;
	}
return null();
}


Void OpenGL_obj::VertexAttrib4f( int p_location,Float p_x,Float p_y,Float p_z,Float p_w){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","VertexAttrib4f",0xc931a56b,"haxor.platform.graphics.OpenGL.VertexAttrib4f","haxor/platform/graphics/OpenGL.hx",130,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(130)
		glVertexAttrib4f(p_location,p_x,p_y,p_z,p_w);;
	}
return null();
}


Void OpenGL_obj::VertexAttribPointer( int p_location,int p_components_size,int p_type,bool p_normalized,int p_stride,int p_offset){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","VertexAttribPointer",0xd397d244,"haxor.platform.graphics.OpenGL.VertexAttribPointer","haxor/platform/graphics/OpenGL.hx",131,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_components_size,"p_components_size")
		HX_STACK_ARG(p_type,"p_type")
		HX_STACK_ARG(p_normalized,"p_normalized")
		HX_STACK_ARG(p_stride,"p_stride")
		HX_STACK_ARG(p_offset,"p_offset")
		HX_STACK_LINE(131)
		glVertexAttribPointer(p_location,p_components_size,p_type,p_normalized,p_stride,(void*)p_offset);;
	}
return null();
}


Void OpenGL_obj::CompileShader( int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CompileShader",0x472258ed,"haxor.platform.graphics.OpenGL.CompileShader","haxor/platform/graphics/OpenGL.hx",134,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_LINE(134)
		glCompileShader(p_shader);;
	}
return null();
}


int OpenGL_obj::CreateShader( int p_type){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CreateShader",0x6b920cec,"haxor.platform.graphics.OpenGL.CreateShader","haxor/platform/graphics/OpenGL.hx",135,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(135)
	return glCreateShader(p_type);;
	HX_STACK_LINE(135)
	return ::haxor::graphics::GL_obj::INVALID;
}


Void OpenGL_obj::DetachShader( int p_program,int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DetachShader",0x16c9de83,"haxor.platform.graphics.OpenGL.DetachShader","haxor/platform/graphics/OpenGL.hx",136,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_LINE(136)
		glDetachShader(p_program, p_shader);;
	}
return null();
}


Void OpenGL_obj::DeleteShader( int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DeleteShader",0xafd4f35b,"haxor.platform.graphics.OpenGL.DeleteShader","haxor/platform/graphics/OpenGL.hx",137,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_LINE(137)
		glDeleteShader(p_shader);;
	}
return null();
}


::String OpenGL_obj::GetShaderInfoLog( int p_shader){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GetShaderInfoLog",0x08f47cc6,"haxor.platform.graphics.OpenGL.GetShaderInfoLog","haxor/platform/graphics/OpenGL.hx",138,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_shader,"p_shader")
	HX_STACK_LINE(138)
	char s[1024]; glGetShaderInfoLog(p_shader,1024,0,s); return s;;
	HX_STACK_LINE(138)
	return HX_CSTRING("");
}


int OpenGL_obj::GetShaderParameter( int p_shader,int p_parameter){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GetShaderParameter",0xbd5589b9,"haxor.platform.graphics.OpenGL.GetShaderParameter","haxor/platform/graphics/OpenGL.hx",139,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_shader,"p_shader")
	HX_STACK_ARG(p_parameter,"p_parameter")
	HX_STACK_LINE(139)
	int d[1]; glGetShaderiv(p_shader, p_parameter, d); return d[0];;
	HX_STACK_LINE(139)
	return (int)-1;
}


Void OpenGL_obj::ShaderSource( int p_shader,::String p_source){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","ShaderSource",0xce365b8b,"haxor.platform.graphics.OpenGL.ShaderSource","haxor/platform/graphics/OpenGL.hx",141,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_ARG(p_source,"p_source")
		HX_STACK_LINE(142)
		int len = p_source.length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(143)
		
		const char ** str = (const char ** ) &p_source.__s;		
		glShaderSource(p_shader, 1, str, & len);
		;
	}
return null();
}


Void OpenGL_obj::AttachShader( int p_program,int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","AttachShader",0xde93de75,"haxor.platform.graphics.OpenGL.AttachShader","haxor/platform/graphics/OpenGL.hx",148,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_LINE(148)
		glAttachShader(p_program, p_shader);;
	}
return null();
}


Void OpenGL_obj::BindAttribLocation( int p_program,int p_location,::String p_name){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","BindAttribLocation",0xa52ac627,"haxor.platform.graphics.OpenGL.BindAttribLocation","haxor/platform/graphics/OpenGL.hx",149,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_LINE(149)
		glBindAttribLocation(p_program, p_location, p_name.__s);;
	}
return null();
}


int OpenGL_obj::CreateProgram( ){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CreateProgram",0x48ac0add,"haxor.platform.graphics.OpenGL.CreateProgram","haxor/platform/graphics/OpenGL.hx",150,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(150)
	return glCreateProgram();;
	HX_STACK_LINE(150)
	return ::haxor::graphics::GL_obj::INVALID;
}


Void OpenGL_obj::DeleteProgram( int p_program){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DeleteProgram",0xbef2c58e,"haxor.platform.graphics.OpenGL.DeleteProgram","haxor/platform/graphics/OpenGL.hx",151,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_LINE(151)
		glDeleteProgram(p_program);;
	}
return null();
}


int OpenGL_obj::GetAttribLocation( int p_program,::String p_name){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GetAttribLocation",0xce2ba14a,"haxor.platform.graphics.OpenGL.GetAttribLocation","haxor/platform/graphics/OpenGL.hx",152,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(152)
	return glGetAttribLocation(p_program,p_name.__s);;
	HX_STACK_LINE(152)
	return (int)-1;
}


int OpenGL_obj::GetUniformLocation( int p_program,::String p_name){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GetUniformLocation",0xd6ce7f7e,"haxor.platform.graphics.OpenGL.GetUniformLocation","haxor/platform/graphics/OpenGL.hx",153,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(153)
	return glGetUniformLocation(p_program,p_name.__s);;
	HX_STACK_LINE(153)
	return (int)-1;
}


::String OpenGL_obj::GetProgramInfoLog( int p_program){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GetProgramInfoLog",0x3f0e783d,"haxor.platform.graphics.OpenGL.GetProgramInfoLog","haxor/platform/graphics/OpenGL.hx",154,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_LINE(154)
	char s[1024]; glGetProgramInfoLog(p_program,1024,0,s); return s;;
	HX_STACK_LINE(154)
	return HX_CSTRING("");
}


int OpenGL_obj::GetProgramParameter( int p_program,int p_parameter){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GetProgramParameter",0x2a7e90f0,"haxor.platform.graphics.OpenGL.GetProgramParameter","haxor/platform/graphics/OpenGL.hx",155,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_ARG(p_parameter,"p_parameter")
	HX_STACK_LINE(155)
	int d[1]; glGetProgramiv(p_program, p_parameter, d); return d[0];;
	HX_STACK_LINE(155)
	return (int)-1;
}


Void OpenGL_obj::LinkProgram( int p_program){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","LinkProgram",0x3b9e3e5f,"haxor.platform.graphics.OpenGL.LinkProgram","haxor/platform/graphics/OpenGL.hx",156,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_LINE(156)
		glLinkProgram(p_program);;
	}
return null();
}


Void OpenGL_obj::UseProgram( int p_program){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","UseProgram",0x7eef29e8,"haxor.platform.graphics.OpenGL.UseProgram","haxor/platform/graphics/OpenGL.hx",157,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_LINE(157)
		glUseProgram(p_program);;
	}
return null();
}


Void OpenGL_obj::ActiveTexture( int p_slot){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","ActiveTexture",0xc319fbaa,"haxor.platform.graphics.OpenGL.ActiveTexture","haxor/platform/graphics/OpenGL.hx",160,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_slot,"p_slot")
		HX_STACK_LINE(160)
		glActiveTexture(p_slot);;
	}
return null();
}


Void OpenGL_obj::BindFramebuffer( int p_target,int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","BindFramebuffer",0x3d935565,"haxor.platform.graphics.OpenGL.BindFramebuffer","haxor/platform/graphics/OpenGL.hx",161,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(161)
		glBindFramebuffer(p_target, p_id);;
	}
return null();
}


Void OpenGL_obj::BindRenderbuffer( int p_target,int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","BindRenderbuffer",0x29e3755e,"haxor.platform.graphics.OpenGL.BindRenderbuffer","haxor/platform/graphics/OpenGL.hx",162,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(162)
		glBindRenderbuffer(p_target, p_id);;
	}
return null();
}


Void OpenGL_obj::BindTexture( int p_target,int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","BindTexture",0x4d746d53,"haxor.platform.graphics.OpenGL.BindTexture","haxor/platform/graphics/OpenGL.hx",163,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(163)
		glBindTexture(p_target, p_id);;
	}
return null();
}


int OpenGL_obj::CreateFramebuffer( ){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CreateFramebuffer",0x3e0475c6,"haxor.platform.graphics.OpenGL.CreateFramebuffer","haxor/platform/graphics/OpenGL.hx",164,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(164)
	unsigned int id; glGenFramebuffers(1, &id);   return id;;
	HX_STACK_LINE(164)
	return ::haxor::graphics::GL_obj::INVALID;
}


int OpenGL_obj::CreateRenderbuffer( ){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CreateRenderbuffer",0x8c6ea9dd,"haxor.platform.graphics.OpenGL.CreateRenderbuffer","haxor/platform/graphics/OpenGL.hx",165,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(165)
	unsigned int id; glGenRenderbuffers(1, &id);  return id;;
	HX_STACK_LINE(165)
	return ::haxor::graphics::GL_obj::INVALID;
}


int OpenGL_obj::CreateTexture( ){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CreateTexture",0xf3938934,"haxor.platform.graphics.OpenGL.CreateTexture","haxor/platform/graphics/OpenGL.hx",166,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(166)
	unsigned int id; glGenTextures(1, &id);  	 return id;;
	HX_STACK_LINE(166)
	return ::haxor::graphics::GL_obj::INVALID;
}


Void OpenGL_obj::DeleteFramebuffer( int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DeleteFramebuffer",0xc11cdcf7,"haxor.platform.graphics.OpenGL.DeleteFramebuffer","haxor/platform/graphics/OpenGL.hx",167,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(167)
		GLuint id = p_id; glDeleteFramebuffers(1, &id);;
	}
return null();
}


Void OpenGL_obj::DeleteRenderbuffer( int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DeleteRenderbuffer",0xbeb08d8c,"haxor.platform.graphics.OpenGL.DeleteRenderbuffer","haxor/platform/graphics/OpenGL.hx",168,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(168)
		GLuint id = p_id; glDeleteRenderbuffers(1,&id);;
	}
return null();
}


Void OpenGL_obj::DeleteTexture( int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DeleteTexture",0x69da43e5,"haxor.platform.graphics.OpenGL.DeleteTexture","haxor/platform/graphics/OpenGL.hx",169,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(169)
		GLuint id = p_id; glDeleteTextures(1,&id);;
	}
return null();
}


Void OpenGL_obj::FramebufferRenderbuffer( int p_target,int p_attachment,int p_renderbuffer_target,int p_renderbuffer_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","FramebufferRenderbuffer",0x2b862998,"haxor.platform.graphics.OpenGL.FramebufferRenderbuffer","haxor/platform/graphics/OpenGL.hx",171,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_attachment,"p_attachment")
		HX_STACK_ARG(p_renderbuffer_target,"p_renderbuffer_target")
		HX_STACK_ARG(p_renderbuffer_id,"p_renderbuffer_id")
		HX_STACK_LINE(171)
		glFramebufferRenderbuffer(p_target, p_attachment, p_renderbuffer_target, p_renderbuffer_id);;
	}
return null();
}


Void OpenGL_obj::FramebufferTexture2D( int p_target,int p_attachment,int p_texture_target,int p_texture_id,int p_miplevel){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","FramebufferTexture2D",0xf5d4976b,"haxor.platform.graphics.OpenGL.FramebufferTexture2D","haxor/platform/graphics/OpenGL.hx",173,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_attachment,"p_attachment")
		HX_STACK_ARG(p_texture_target,"p_texture_target")
		HX_STACK_ARG(p_texture_id,"p_texture_id")
		HX_STACK_ARG(p_miplevel,"p_miplevel")
		HX_STACK_LINE(173)
		glFramebufferTexture2D(p_target, p_attachment, p_texture_target, p_texture_id, p_miplevel);;
	}
return null();
}


Void OpenGL_obj::GenerateMipmap( int p_target){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GenerateMipmap",0xd088e508,"haxor.platform.graphics.OpenGL.GenerateMipmap","haxor/platform/graphics/OpenGL.hx",174,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_LINE(174)
		glGenerateMipmap(p_target);;
	}
return null();
}


Void OpenGL_obj::PixelStorei( int p_parameter,int p_value){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","PixelStorei",0x32eac543,"haxor.platform.graphics.OpenGL.PixelStorei","haxor/platform/graphics/OpenGL.hx",175,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_parameter,"p_parameter")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(175)
		glPixelStorei(p_parameter, p_value);;
	}
return null();
}


Void OpenGL_obj::RenderbufferStorage( int p_target,int p_format,int p_width,int p_height){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","RenderbufferStorage",0x1b526eba,"haxor.platform.graphics.OpenGL.RenderbufferStorage","haxor/platform/graphics/OpenGL.hx",176,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_format,"p_format")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_LINE(176)
		glRenderbufferStorage(p_target, p_format, p_width, p_height);;
	}
return null();
}


Void OpenGL_obj::TexImage2D( int p_target,int p_level,int p_internal_format,int p_width,int p_height,int p_border,int p_format,int p_channel_type,::haxor::io::Buffer p_data){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","TexImage2D",0x41aa39b1,"haxor.platform.graphics.OpenGL.TexImage2D","haxor/platform/graphics/OpenGL.hx",178,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_level,"p_level")
		HX_STACK_ARG(p_internal_format,"p_internal_format")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_ARG(p_border,"p_border")
		HX_STACK_ARG(p_format,"p_format")
		HX_STACK_ARG(p_channel_type,"p_channel_type")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_LINE(179)
		::haxe::io::Bytes ba = p_data->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(180)
		glTexImage2D(p_target, p_level, p_internal_format,p_width,p_height,p_border, p_format, p_channel_type,(void*)&ba->b[0]);;
	}
return null();
}


Void OpenGL_obj::TexImage2DAlloc( int p_target,int p_level,int p_internal_format,int p_width,int p_height,int p_border,int p_format,int p_channel_type){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","TexImage2DAlloc",0x47931904,"haxor.platform.graphics.OpenGL.TexImage2DAlloc","haxor/platform/graphics/OpenGL.hx",184,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_level,"p_level")
		HX_STACK_ARG(p_internal_format,"p_internal_format")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_ARG(p_border,"p_border")
		HX_STACK_ARG(p_format,"p_format")
		HX_STACK_ARG(p_channel_type,"p_channel_type")
		HX_STACK_LINE(184)
		glTexImage2D(p_target, p_level, p_internal_format,p_width,p_height,p_border, p_format, p_channel_type,(void*)NULL);;
	}
return null();
}


Void OpenGL_obj::TexSubImage2D( int p_target,int p_level,int p_x,int p_y,int p_width,int p_height,int p_format,int p_channel_type,::haxor::io::Buffer p_data){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","TexSubImage2D",0x95001709,"haxor.platform.graphics.OpenGL.TexSubImage2D","haxor/platform/graphics/OpenGL.hx",187,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_level,"p_level")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_ARG(p_format,"p_format")
		HX_STACK_ARG(p_channel_type,"p_channel_type")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_LINE(188)
		::haxe::io::Bytes ba = p_data->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(189)
		int off = p_data->m_offset;		HX_STACK_VAR(off,"off");
		HX_STACK_LINE(190)
		glTexSubImage2D(p_target, p_level, p_x, p_y,p_width,p_height,p_format, p_channel_type,(void*)((&ba->b[0])+off));;
	}
return null();
}


Void OpenGL_obj::TexParameterf( int p_target,int p_parameter,Float p_value){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","TexParameterf",0xa8a10f59,"haxor.platform.graphics.OpenGL.TexParameterf","haxor/platform/graphics/OpenGL.hx",192,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_parameter,"p_parameter")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(192)
		glTexParameterf(p_target, p_parameter, p_value);;
	}
return null();
}


Void OpenGL_obj::TexParameteri( int p_target,int p_parameter,int p_value){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","TexParameteri",0xa8a10f5c,"haxor.platform.graphics.OpenGL.TexParameteri","haxor/platform/graphics/OpenGL.hx",193,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_parameter,"p_parameter")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(193)
		glTexParameteri(p_target, p_parameter, p_value);;
	}
return null();
}


Void OpenGL_obj::Uniform1f( int p_location,Float p_x){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform1f",0xc273aabe,"haxor.platform.graphics.OpenGL.Uniform1f","haxor/platform/graphics/OpenGL.hx",196,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_LINE(196)
		glUniform1f(p_location, p_x);;
	}
return null();
}


Void OpenGL_obj::Uniform2f( int p_location,Float p_x,Float p_y){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform2f",0xc273ab9d,"haxor.platform.graphics.OpenGL.Uniform2f","haxor/platform/graphics/OpenGL.hx",197,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(197)
		glUniform2f(p_location, p_x, p_y);;
	}
return null();
}


Void OpenGL_obj::Uniform3f( int p_location,Float p_x,Float p_y,Float p_z){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform3f",0xc273ac7c,"haxor.platform.graphics.OpenGL.Uniform3f","haxor/platform/graphics/OpenGL.hx",198,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(198)
		glUniform3f(p_location, p_x, p_y, p_z);;
	}
return null();
}


Void OpenGL_obj::Uniform4f( int p_location,Float p_x,Float p_y,Float p_z,Float p_w){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform4f",0xc273ad5b,"haxor.platform.graphics.OpenGL.Uniform4f","haxor/platform/graphics/OpenGL.hx",199,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(199)
		glUniform4f(p_location, p_x, p_y, p_z, p_w);;
	}
return null();
}


Void OpenGL_obj::Uniform1i( int p_location,int p_x){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform1i",0xc273aac1,"haxor.platform.graphics.OpenGL.Uniform1i","haxor/platform/graphics/OpenGL.hx",200,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_LINE(200)
		glUniform1i(p_location, p_x);;
	}
return null();
}


Void OpenGL_obj::Uniform2i( int p_location,int p_x,int p_y){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform2i",0xc273aba0,"haxor.platform.graphics.OpenGL.Uniform2i","haxor/platform/graphics/OpenGL.hx",201,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(201)
		glUniform2i(p_location, p_x, p_y);;
	}
return null();
}


Void OpenGL_obj::Uniform3i( int p_location,int p_x,int p_y,int p_z){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform3i",0xc273ac7f,"haxor.platform.graphics.OpenGL.Uniform3i","haxor/platform/graphics/OpenGL.hx",202,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(202)
		glUniform3i(p_location, p_x, p_y, p_z);;
	}
return null();
}


Void OpenGL_obj::Uniform4i( int p_location,int p_x,int p_y,int p_z,int p_w){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform4i",0xc273ad5e,"haxor.platform.graphics.OpenGL.Uniform4i","haxor/platform/graphics/OpenGL.hx",203,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(203)
		glUniform4i(p_location, p_x, p_y, p_z, p_w);;
	}
return null();
}


Void OpenGL_obj::Uniform1fv( int p_location,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform1fv",0x62c1bbf8,"haxor.platform.graphics.OpenGL.Uniform1fv","haxor/platform/graphics/OpenGL.hx",204,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(204)
		::haxe::io::Bytes ba = p_v->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(204)
		int len = p_v->m_length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(204)
		glUniform1fv(p_location,len,(float*)&ba->b[0]);;
	}
return null();
}


Void OpenGL_obj::Uniform2fv( int p_location,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform2fv",0x62c27e39,"haxor.platform.graphics.OpenGL.Uniform2fv","haxor/platform/graphics/OpenGL.hx",205,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(205)
		::haxe::io::Bytes ba = p_v->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(205)
		int len = p_v->m_length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(205)
		glUniform2fv(p_location,len/2,(float*)&ba->b[0]);;
	}
return null();
}


Void OpenGL_obj::Uniform3fv( int p_location,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform3fv",0x62c3407a,"haxor.platform.graphics.OpenGL.Uniform3fv","haxor/platform/graphics/OpenGL.hx",206,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(206)
		::haxe::io::Bytes ba = p_v->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(206)
		int len = p_v->m_length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(206)
		glUniform3fv(p_location,len/3,(float*)&ba->b[0]);;
	}
return null();
}


Void OpenGL_obj::Uniform4fv( int p_location,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform4fv",0x62c402bb,"haxor.platform.graphics.OpenGL.Uniform4fv","haxor/platform/graphics/OpenGL.hx",207,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(207)
		::haxe::io::Bytes ba = p_v->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(207)
		int len = p_v->m_length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(207)
		glUniform4fv(p_location,len/4,(float*)&ba->b[0]);;
	}
return null();
}


Void OpenGL_obj::Uniform1iv( int p_location,::haxor::io::Int32Array p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform1iv",0x62c1be95,"haxor.platform.graphics.OpenGL.Uniform1iv","haxor/platform/graphics/OpenGL.hx",209,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(209)
		::haxe::io::Bytes ba = p_v->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(209)
		int len = p_v->m_length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(209)
		int * il = new int[len]; long * b = (long*)(&ba->b[0]); for (int i = 0; i < len; i++) il[i] = (int) b; glUniform1iv(p_location, len, il); delete[] il;;
	}
return null();
}


Void OpenGL_obj::Uniform2iv( int p_location,::haxor::io::Int32Array p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform2iv",0x62c280d6,"haxor.platform.graphics.OpenGL.Uniform2iv","haxor/platform/graphics/OpenGL.hx",211,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(211)
		::haxe::io::Bytes ba = p_v->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(211)
		int len = p_v->m_length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(211)
		int * il = new int[len]; long * b = (long*)(&ba->b[0]); for (int i = 0; i < len; i++) il[i] = (int) b; glUniform2iv(p_location, len/2, il); delete[] il;;
	}
return null();
}


Void OpenGL_obj::Uniform3iv( int p_location,::haxor::io::Int32Array p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform3iv",0x62c34317,"haxor.platform.graphics.OpenGL.Uniform3iv","haxor/platform/graphics/OpenGL.hx",213,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(213)
		::haxe::io::Bytes ba = p_v->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(213)
		int len = p_v->m_length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(213)
		int * il = new int[len]; long * b = (long*)(&ba->b[0]); for (int i = 0; i < len; i++) il[i] = (int) b; glUniform3iv(p_location, len/3, il); delete[] il;;
	}
return null();
}


Void OpenGL_obj::Uniform4iv( int p_location,::haxor::io::Int32Array p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Uniform4iv",0x62c40558,"haxor.platform.graphics.OpenGL.Uniform4iv","haxor/platform/graphics/OpenGL.hx",215,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(215)
		::haxe::io::Bytes ba = p_v->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(215)
		int len = p_v->m_length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(215)
		int * il = new int[len]; long * b = (long*)(&ba->b[0]); for (int i = 0; i < len; i++) il[i] = (int) b; glUniform4iv(p_location, len/4, il); delete[] il;;
	}
return null();
}


Void OpenGL_obj::UniformMatrix2fv( int p_location,bool p_transpose,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","UniformMatrix2fv",0xda8549b8,"haxor.platform.graphics.OpenGL.UniformMatrix2fv","haxor/platform/graphics/OpenGL.hx",217,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_transpose,"p_transpose")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(217)
		::haxe::io::Bytes ba = p_v->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(217)
		int len = p_v->m_length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(217)
		glUniformMatrix2fv(p_location,len/4,  p_transpose, (float*)&ba->b[0]);;
	}
return null();
}


Void OpenGL_obj::UniformMatrix3fv( int p_location,bool p_transpose,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","UniformMatrix3fv",0xda860bf9,"haxor.platform.graphics.OpenGL.UniformMatrix3fv","haxor/platform/graphics/OpenGL.hx",218,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_transpose,"p_transpose")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(218)
		::haxe::io::Bytes ba = p_v->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(218)
		int len = p_v->m_length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(218)
		glUniformMatrix3fv(p_location,len/9,  p_transpose, (float*)&ba->b[0]);;
	}
return null();
}


Void OpenGL_obj::UniformMatrix4fv( int p_location,bool p_transpose,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","UniformMatrix4fv",0xda86ce3a,"haxor.platform.graphics.OpenGL.UniformMatrix4fv","haxor/platform/graphics/OpenGL.hx",219,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_transpose,"p_transpose")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(219)
		::haxe::io::Bytes ba = p_v->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(219)
		int len = p_v->m_length;		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(219)
		glUniformMatrix4fv(p_location,len/16, p_transpose, (float*)&ba->b[0]);;
	}
return null();
}


Void OpenGL_obj::BlendFunc( int p_src,int p_dst){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","BlendFunc",0xc23185aa,"haxor.platform.graphics.OpenGL.BlendFunc","haxor/platform/graphics/OpenGL.hx",222,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_src,"p_src")
		HX_STACK_ARG(p_dst,"p_dst")
		HX_STACK_LINE(222)
		glBlendFunc(p_src, p_dst);;
	}
return null();
}


Void OpenGL_obj::Disable( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Disable",0x1f6d3c1d,"haxor.platform.graphics.OpenGL.Disable","haxor/platform/graphics/OpenGL.hx",223,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(223)
		glDisable(p_flag);;
	}
return null();
}


Void OpenGL_obj::Enable( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Enable",0xdd78d9ee,"haxor.platform.graphics.OpenGL.Enable","haxor/platform/graphics/OpenGL.hx",224,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(224)
		glEnable(p_flag);;
	}
return null();
}


Void OpenGL_obj::DepthMask( bool p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DepthMask",0x596f2504,"haxor.platform.graphics.OpenGL.DepthMask","haxor/platform/graphics/OpenGL.hx",225,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(225)
		glDepthMask(p_flag);;
	}
return null();
}


Void OpenGL_obj::DepthFunc( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","DepthFunc",0x54ddcf5c,"haxor.platform.graphics.OpenGL.DepthFunc","haxor/platform/graphics/OpenGL.hx",226,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(226)
		glDepthFunc(p_flag);;
	}
return null();
}


Void OpenGL_obj::CullFace( int p_face){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","CullFace",0x9055039a,"haxor.platform.graphics.OpenGL.CullFace","haxor/platform/graphics/OpenGL.hx",227,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_face,"p_face")
		HX_STACK_LINE(227)
		glCullFace(p_face);;
	}
return null();
}


Void OpenGL_obj::FrontFace( int p_face){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","FrontFace",0x3b568b5b,"haxor.platform.graphics.OpenGL.FrontFace","haxor/platform/graphics/OpenGL.hx",228,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_face,"p_face")
		HX_STACK_LINE(228)
		glFrontFace(p_face);;
	}
return null();
}


Void OpenGL_obj::Clear( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Clear",0x1247dc82,"haxor.platform.graphics.OpenGL.Clear","haxor/platform/graphics/OpenGL.hx",232,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(232)
		glClear(p_flag);;
	}
return null();
}


Void OpenGL_obj::ClearDepth( Float p_value){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","ClearDepth",0x3476ed21,"haxor.platform.graphics.OpenGL.ClearDepth","haxor/platform/graphics/OpenGL.hx",233,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(233)
		glClearDepthf(p_value);;
	}
return null();
}


Void OpenGL_obj::ClearColor( Float p_r,Float p_g,Float p_b,Float p_a){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","ClearColor",0xa7a96d81,"haxor.platform.graphics.OpenGL.ClearColor","haxor/platform/graphics/OpenGL.hx",234,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_r,"p_r")
		HX_STACK_ARG(p_g,"p_g")
		HX_STACK_ARG(p_b,"p_b")
		HX_STACK_ARG(p_a,"p_a")
		HX_STACK_LINE(234)
		glClearColor(p_r, p_g, p_b, p_a);;
	}
return null();
}


Void OpenGL_obj::Viewport( int p_x,int p_y,int p_width,int p_height){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Viewport",0x80c86891,"haxor.platform.graphics.OpenGL.Viewport","haxor/platform/graphics/OpenGL.hx",235,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_LINE(235)
		glViewport(p_x, p_y, p_width, p_height);;
	}
return null();
}


Void OpenGL_obj::Scissor( int p_x,int p_y,int p_width,int p_height){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","Scissor",0x72fbfa51,"haxor.platform.graphics.OpenGL.Scissor","haxor/platform/graphics/OpenGL.hx",236,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_LINE(236)
		glScissor(p_x, p_y, p_width, p_height);;
	}
return null();
}


Void OpenGL_obj::ReadPixels( int p_x,int p_y,int p_width,int p_height,int p_format,int p_type,::haxor::io::Buffer p_pixels){
{
		HX_STACK_FRAME("haxor.platform.graphics.OpenGL","ReadPixels",0x0e68900e,"haxor.platform.graphics.OpenGL.ReadPixels","haxor/platform/graphics/OpenGL.hx",238,0x3c17389a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_ARG(p_format,"p_format")
		HX_STACK_ARG(p_type,"p_type")
		HX_STACK_ARG(p_pixels,"p_pixels")
		HX_STACK_LINE(238)
		::haxe::io::Bytes ba = p_pixels->m_buffer;		HX_STACK_VAR(ba,"ba");
		HX_STACK_LINE(238)
		glReadPixels(p_x, p_y, p_width, p_height, p_format, p_type, (void*)(&ba->b[0]));;
	}
return null();
}


int OpenGL_obj::GetErrorCode( ){
	HX_STACK_FRAME("haxor.platform.graphics.OpenGL","GetErrorCode",0xa39fd74a,"haxor.platform.graphics.OpenGL.GetErrorCode","haxor/platform/graphics/OpenGL.hx",241,0x3c17389a)
	HX_STACK_THIS(this)
	HX_STACK_LINE(241)
	return glGetError();;
	HX_STACK_LINE(241)
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
		if (HX_FIELD_EQ(inName,"Scissor") ) { return Scissor_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"CullFace") ) { return CullFace_dyn(); }
		if (HX_FIELD_EQ(inName,"Viewport") ) { return Viewport_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"Uniform1f") ) { return Uniform1f_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform2f") ) { return Uniform2f_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform3f") ) { return Uniform3f_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform4f") ) { return Uniform4f_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform1i") ) { return Uniform1i_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform2i") ) { return Uniform2i_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform3i") ) { return Uniform3i_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform4i") ) { return Uniform4i_dyn(); }
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
		if (HX_FIELD_EQ(inName,"TexImage2D") ) { return TexImage2D_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform1fv") ) { return Uniform1fv_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform2fv") ) { return Uniform2fv_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform3fv") ) { return Uniform3fv_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform4fv") ) { return Uniform4fv_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform1iv") ) { return Uniform1iv_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform2iv") ) { return Uniform2iv_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform3iv") ) { return Uniform3iv_dyn(); }
		if (HX_FIELD_EQ(inName,"Uniform4iv") ) { return Uniform4iv_dyn(); }
		if (HX_FIELD_EQ(inName,"ClearDepth") ) { return ClearDepth_dyn(); }
		if (HX_FIELD_EQ(inName,"ClearColor") ) { return ClearColor_dyn(); }
		if (HX_FIELD_EQ(inName,"ReadPixels") ) { return ReadPixels_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"LinkProgram") ) { return LinkProgram_dyn(); }
		if (HX_FIELD_EQ(inName,"BindTexture") ) { return BindTexture_dyn(); }
		if (HX_FIELD_EQ(inName,"PixelStorei") ) { return PixelStorei_dyn(); }
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
		if (HX_FIELD_EQ(inName,"ActiveTexture") ) { return ActiveTexture_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateTexture") ) { return CreateTexture_dyn(); }
		if (HX_FIELD_EQ(inName,"DeleteTexture") ) { return DeleteTexture_dyn(); }
		if (HX_FIELD_EQ(inName,"TexSubImage2D") ) { return TexSubImage2D_dyn(); }
		if (HX_FIELD_EQ(inName,"TexParameterf") ) { return TexParameterf_dyn(); }
		if (HX_FIELD_EQ(inName,"TexParameteri") ) { return TexParameteri_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"VertexAttrib3f") ) { return VertexAttrib3f_dyn(); }
		if (HX_FIELD_EQ(inName,"VertexAttrib4f") ) { return VertexAttrib4f_dyn(); }
		if (HX_FIELD_EQ(inName,"GenerateMipmap") ) { return GenerateMipmap_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"CheckExtensions") ) { return CheckExtensions_dyn(); }
		if (HX_FIELD_EQ(inName,"BindFramebuffer") ) { return BindFramebuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"TexImage2DAlloc") ) { return TexImage2DAlloc_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"GetShaderInfoLog") ) { return GetShaderInfoLog_dyn(); }
		if (HX_FIELD_EQ(inName,"BindRenderbuffer") ) { return BindRenderbuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"UniformMatrix2fv") ) { return UniformMatrix2fv_dyn(); }
		if (HX_FIELD_EQ(inName,"UniformMatrix3fv") ) { return UniformMatrix3fv_dyn(); }
		if (HX_FIELD_EQ(inName,"UniformMatrix4fv") ) { return UniformMatrix4fv_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"GetAttribLocation") ) { return GetAttribLocation_dyn(); }
		if (HX_FIELD_EQ(inName,"GetProgramInfoLog") ) { return GetProgramInfoLog_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateFramebuffer") ) { return CreateFramebuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"DeleteFramebuffer") ) { return DeleteFramebuffer_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"EnableVertexAttrib") ) { return EnableVertexAttrib_dyn(); }
		if (HX_FIELD_EQ(inName,"GetShaderParameter") ) { return GetShaderParameter_dyn(); }
		if (HX_FIELD_EQ(inName,"BindAttribLocation") ) { return BindAttribLocation_dyn(); }
		if (HX_FIELD_EQ(inName,"GetUniformLocation") ) { return GetUniformLocation_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateRenderbuffer") ) { return CreateRenderbuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"DeleteRenderbuffer") ) { return DeleteRenderbuffer_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"DisableVertexAttrib") ) { return DisableVertexAttrib_dyn(); }
		if (HX_FIELD_EQ(inName,"VertexAttribPointer") ) { return VertexAttribPointer_dyn(); }
		if (HX_FIELD_EQ(inName,"GetProgramParameter") ) { return GetProgramParameter_dyn(); }
		if (HX_FIELD_EQ(inName,"RenderbufferStorage") ) { return RenderbufferStorage_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"FramebufferTexture2D") ) { return FramebufferTexture2D_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"FramebufferRenderbuffer") ) { return FramebufferRenderbuffer_dyn(); }
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
	HX_CSTRING("CheckExtensions"),
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
	HX_CSTRING("GetUniformLocation"),
	HX_CSTRING("GetProgramInfoLog"),
	HX_CSTRING("GetProgramParameter"),
	HX_CSTRING("LinkProgram"),
	HX_CSTRING("UseProgram"),
	HX_CSTRING("ActiveTexture"),
	HX_CSTRING("BindFramebuffer"),
	HX_CSTRING("BindRenderbuffer"),
	HX_CSTRING("BindTexture"),
	HX_CSTRING("CreateFramebuffer"),
	HX_CSTRING("CreateRenderbuffer"),
	HX_CSTRING("CreateTexture"),
	HX_CSTRING("DeleteFramebuffer"),
	HX_CSTRING("DeleteRenderbuffer"),
	HX_CSTRING("DeleteTexture"),
	HX_CSTRING("FramebufferRenderbuffer"),
	HX_CSTRING("FramebufferTexture2D"),
	HX_CSTRING("GenerateMipmap"),
	HX_CSTRING("PixelStorei"),
	HX_CSTRING("RenderbufferStorage"),
	HX_CSTRING("TexImage2D"),
	HX_CSTRING("TexImage2DAlloc"),
	HX_CSTRING("TexSubImage2D"),
	HX_CSTRING("TexParameterf"),
	HX_CSTRING("TexParameteri"),
	HX_CSTRING("Uniform1f"),
	HX_CSTRING("Uniform2f"),
	HX_CSTRING("Uniform3f"),
	HX_CSTRING("Uniform4f"),
	HX_CSTRING("Uniform1i"),
	HX_CSTRING("Uniform2i"),
	HX_CSTRING("Uniform3i"),
	HX_CSTRING("Uniform4i"),
	HX_CSTRING("Uniform1fv"),
	HX_CSTRING("Uniform2fv"),
	HX_CSTRING("Uniform3fv"),
	HX_CSTRING("Uniform4fv"),
	HX_CSTRING("Uniform1iv"),
	HX_CSTRING("Uniform2iv"),
	HX_CSTRING("Uniform3iv"),
	HX_CSTRING("Uniform4iv"),
	HX_CSTRING("UniformMatrix2fv"),
	HX_CSTRING("UniformMatrix3fv"),
	HX_CSTRING("UniformMatrix4fv"),
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
	HX_CSTRING("Viewport"),
	HX_CSTRING("Scissor"),
	HX_CSTRING("ReadPixels"),
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
