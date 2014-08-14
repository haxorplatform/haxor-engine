#include <hxcpp.h>

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
namespace haxor{
namespace platform{
namespace graphics{

Void GraphicContext_obj::__construct(::haxor::core::BaseApplication p_application)
{
HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","new",0xdecf5bed,"haxor.platform.graphics.GraphicContext.new","haxor/platform/graphics/GraphicContext.hx",48,0x2319fee2)
HX_STACK_THIS(this)
HX_STACK_ARG(p_application,"p_application")
{
	HX_STACK_LINE(49)
	this->m_api = ::haxor::platform::graphics::GraphicAPI_obj::None;
	HX_STACK_LINE(50)
	this->m_application = p_application;
}
;
	return null();
}

//GraphicContext_obj::~GraphicContext_obj() { }

Dynamic GraphicContext_obj::__CreateEmpty() { return  new GraphicContext_obj; }
hx::ObjectPtr< GraphicContext_obj > GraphicContext_obj::__new(::haxor::core::BaseApplication p_application)
{  hx::ObjectPtr< GraphicContext_obj > result = new GraphicContext_obj();
	result->__construct(p_application);
	return result;}

Dynamic GraphicContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GraphicContext_obj > result = new GraphicContext_obj();
	result->__construct(inArgs[0]);
	return result;}

::haxor::platform::graphics::GraphicAPI GraphicContext_obj::get_api( ){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","get_api",0x40db9b3e,"haxor.platform.graphics.GraphicContext.get_api","haxor/platform/graphics/GraphicContext.hx",36,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(36)
	return this->m_api;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,get_api,return )

Void GraphicContext_obj::CheckExtensions( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","CheckExtensions",0x7d7b15e9,"haxor.platform.graphics.GraphicContext.CheckExtensions","haxor/platform/graphics/GraphicContext.hx",56,0x2319fee2)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,CheckExtensions,(void))

Void GraphicContext_obj::Destroy( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","Destroy",0x0bf42ae7,"haxor.platform.graphics.GraphicContext.Destroy","haxor/platform/graphics/GraphicContext.hx",59,0x2319fee2)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,Destroy,(void))

Void GraphicContext_obj::Flush( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","Flush",0xb2e81b71,"haxor.platform.graphics.GraphicContext.Flush","haxor/platform/graphics/GraphicContext.hx",60,0x2319fee2)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,Flush,(void))

Void GraphicContext_obj::Focus( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","Focus",0xb4d61885,"haxor.platform.graphics.GraphicContext.Focus","haxor/platform/graphics/GraphicContext.hx",61,0x2319fee2)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,Focus,(void))

Void GraphicContext_obj::Resize( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","Resize",0x9b5038a7,"haxor.platform.graphics.GraphicContext.Resize","haxor/platform/graphics/GraphicContext.hx",62,0x2319fee2)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,Resize,(void))

Void GraphicContext_obj::BindBuffer( int p_target,int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","BindBuffer",0x8b1446d0,"haxor.platform.graphics.GraphicContext.BindBuffer","haxor/platform/graphics/GraphicContext.hx",65,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_id,"p_id")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GraphicContext_obj,BindBuffer,(void))

Void GraphicContext_obj::BufferData( int p_target,::haxor::io::Buffer p_data,int p_mode){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","BufferData",0x25c9737d,"haxor.platform.graphics.GraphicContext.BufferData","haxor/platform/graphics/GraphicContext.hx",66,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_ARG(p_mode,"p_mode")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(GraphicContext_obj,BufferData,(void))

Void GraphicContext_obj::BufferSubData( int p_target,int p_offset,::haxor::io::Buffer p_data){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","BufferSubData",0x32cda457,"haxor.platform.graphics.GraphicContext.BufferSubData","haxor/platform/graphics/GraphicContext.hx",67,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_offset,"p_offset")
		HX_STACK_ARG(p_data,"p_data")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(GraphicContext_obj,BufferSubData,(void))

int GraphicContext_obj::CreateBuffer( ){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","CreateBuffer",0x0d3b640f,"haxor.platform.graphics.GraphicContext.CreateBuffer","haxor/platform/graphics/GraphicContext.hx",68,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(68)
	return ::haxor::platform::graphics::GL_obj::_NULL;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,CreateBuffer,return )

Void GraphicContext_obj::DeleteBuffer( int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","DeleteBuffer",0x517e4a7e,"haxor.platform.graphics.GraphicContext.DeleteBuffer","haxor/platform/graphics/GraphicContext.hx",69,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_id,"p_id")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,DeleteBuffer,(void))

Void GraphicContext_obj::DrawArrays( int p_primitive,int p_start,int p_count){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","DrawArrays",0x8c09a811,"haxor.platform.graphics.GraphicContext.DrawArrays","haxor/platform/graphics/GraphicContext.hx",70,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_primitive,"p_primitive")
		HX_STACK_ARG(p_start,"p_start")
		HX_STACK_ARG(p_count,"p_count")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(GraphicContext_obj,DrawArrays,(void))

Void GraphicContext_obj::DrawElements( int p_primitive,int p_count,int p_type,int p_offset){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","DrawElements",0x7409294e,"haxor.platform.graphics.GraphicContext.DrawElements","haxor/platform/graphics/GraphicContext.hx",71,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_primitive,"p_primitive")
		HX_STACK_ARG(p_count,"p_count")
		HX_STACK_ARG(p_type,"p_type")
		HX_STACK_ARG(p_offset,"p_offset")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(GraphicContext_obj,DrawElements,(void))

Void GraphicContext_obj::EnableVertexAttrib( int p_location){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","EnableVertexAttrib",0x295aac24,"haxor.platform.graphics.GraphicContext.EnableVertexAttrib","haxor/platform/graphics/GraphicContext.hx",72,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,EnableVertexAttrib,(void))

Void GraphicContext_obj::DisableVertexAttrib( int p_location){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","DisableVertexAttrib",0x6db17943,"haxor.platform.graphics.GraphicContext.DisableVertexAttrib","haxor/platform/graphics/GraphicContext.hx",73,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,DisableVertexAttrib,(void))

Void GraphicContext_obj::VertexAttrib3f( int p_location,Float p_x,Float p_y,Float p_z){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","VertexAttrib3f",0xb265dfd4,"haxor.platform.graphics.GraphicContext.VertexAttrib3f","haxor/platform/graphics/GraphicContext.hx",74,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(GraphicContext_obj,VertexAttrib3f,(void))

Void GraphicContext_obj::VertexAttrib4f( int p_location,Float p_x,Float p_y,Float p_z,Float p_w){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","VertexAttrib4f",0xb265e0b3,"haxor.platform.graphics.GraphicContext.VertexAttrib4f","haxor/platform/graphics/GraphicContext.hx",75,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC5(GraphicContext_obj,VertexAttrib4f,(void))

Void GraphicContext_obj::VertexAttribPointer( int p_location,int p_components_size,int p_type,bool p_normalized,int p_stride,int p_offset){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","VertexAttribPointer",0xe5dfb1fc,"haxor.platform.graphics.GraphicContext.VertexAttribPointer","haxor/platform/graphics/GraphicContext.hx",76,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_components_size,"p_components_size")
		HX_STACK_ARG(p_type,"p_type")
		HX_STACK_ARG(p_normalized,"p_normalized")
		HX_STACK_ARG(p_stride,"p_stride")
		HX_STACK_ARG(p_offset,"p_offset")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(GraphicContext_obj,VertexAttribPointer,(void))

Void GraphicContext_obj::CompileShader( int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","CompileShader",0xc79b1ea5,"haxor.platform.graphics.GraphicContext.CompileShader","haxor/platform/graphics/GraphicContext.hx",79,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_shader,"p_shader")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,CompileShader,(void))

int GraphicContext_obj::CreateShader( int p_type){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","CreateShader",0x59c76634,"haxor.platform.graphics.GraphicContext.CreateShader","haxor/platform/graphics/GraphicContext.hx",80,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(80)
	return ::haxor::platform::graphics::GL_obj::_NULL;
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,CreateShader,return )

Void GraphicContext_obj::DeleteShader( int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","DeleteShader",0x9e0a4ca3,"haxor.platform.graphics.GraphicContext.DeleteShader","haxor/platform/graphics/GraphicContext.hx",81,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_shader,"p_shader")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,DeleteShader,(void))

Void GraphicContext_obj::DetachShader( int p_program,int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","DetachShader",0x04ff37cb,"haxor.platform.graphics.GraphicContext.DetachShader","haxor/platform/graphics/GraphicContext.hx",82,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_ARG(p_shader,"p_shader")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GraphicContext_obj,DetachShader,(void))

::String GraphicContext_obj::GetShaderInfoLog( int p_shader){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","GetShaderInfoLog",0xd4241a0e,"haxor.platform.graphics.GraphicContext.GetShaderInfoLog","haxor/platform/graphics/GraphicContext.hx",83,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_shader,"p_shader")
	HX_STACK_LINE(83)
	return HX_CSTRING("");
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,GetShaderInfoLog,return )

int GraphicContext_obj::GetShaderParameter( int p_shader,int p_parameter){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","GetShaderParameter",0x699d0901,"haxor.platform.graphics.GraphicContext.GetShaderParameter","haxor/platform/graphics/GraphicContext.hx",84,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_shader,"p_shader")
	HX_STACK_ARG(p_parameter,"p_parameter")
	HX_STACK_LINE(84)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC2(GraphicContext_obj,GetShaderParameter,return )

Void GraphicContext_obj::ShaderSource( int p_shader,::String p_source){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","ShaderSource",0xbc6bb4d3,"haxor.platform.graphics.GraphicContext.ShaderSource","haxor/platform/graphics/GraphicContext.hx",85,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_ARG(p_source,"p_source")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GraphicContext_obj,ShaderSource,(void))

Void GraphicContext_obj::AttachShader( int p_program,int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","AttachShader",0xccc937bd,"haxor.platform.graphics.GraphicContext.AttachShader","haxor/platform/graphics/GraphicContext.hx",86,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_ARG(p_shader,"p_shader")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GraphicContext_obj,AttachShader,(void))

Void GraphicContext_obj::BindAttribLocation( int p_program,int p_location,::String p_name){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","BindAttribLocation",0x5172456f,"haxor.platform.graphics.GraphicContext.BindAttribLocation","haxor/platform/graphics/GraphicContext.hx",87,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_name,"p_name")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(GraphicContext_obj,BindAttribLocation,(void))

int GraphicContext_obj::CreateProgram( ){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","CreateProgram",0xc924d095,"haxor.platform.graphics.GraphicContext.CreateProgram","haxor/platform/graphics/GraphicContext.hx",88,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(88)
	return ::haxor::platform::graphics::GL_obj::_NULL;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,CreateProgram,return )

Void GraphicContext_obj::DeleteProgram( int p_program){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","DeleteProgram",0x3f6b8b46,"haxor.platform.graphics.GraphicContext.DeleteProgram","haxor/platform/graphics/GraphicContext.hx",89,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,DeleteProgram,(void))

int GraphicContext_obj::GetAttribLocation( int p_program,::String p_name){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","GetAttribLocation",0xcca5a302,"haxor.platform.graphics.GraphicContext.GetAttribLocation","haxor/platform/graphics/GraphicContext.hx",90,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(90)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC2(GraphicContext_obj,GetAttribLocation,return )

::String GraphicContext_obj::GetProgramInfoLog( int p_program){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","GetProgramInfoLog",0x3d8879f5,"haxor.platform.graphics.GraphicContext.GetProgramInfoLog","haxor/platform/graphics/GraphicContext.hx",91,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_LINE(91)
	return HX_CSTRING("");
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,GetProgramInfoLog,return )

int GraphicContext_obj::GetProgramParameter( int p_program,int p_parameter){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","GetProgramParameter",0x3cc670a8,"haxor.platform.graphics.GraphicContext.GetProgramParameter","haxor/platform/graphics/GraphicContext.hx",92,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_ARG(p_parameter,"p_parameter")
	HX_STACK_LINE(92)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC2(GraphicContext_obj,GetProgramParameter,return )

Void GraphicContext_obj::LinkProgram( int p_program){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","LinkProgram",0x0223a617,"haxor.platform.graphics.GraphicContext.LinkProgram","haxor/platform/graphics/GraphicContext.hx",93,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,LinkProgram,(void))

Void GraphicContext_obj::UseProgram( int p_program){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","UseProgram",0x89022130,"haxor.platform.graphics.GraphicContext.UseProgram","haxor/platform/graphics/GraphicContext.hx",94,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_program,"p_program")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,UseProgram,(void))

Void GraphicContext_obj::BlendFunc( int p_src,int p_dst){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","BlendFunc",0x24f70f62,"haxor.platform.graphics.GraphicContext.BlendFunc","haxor/platform/graphics/GraphicContext.hx",97,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_src,"p_src")
		HX_STACK_ARG(p_dst,"p_dst")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GraphicContext_obj,BlendFunc,(void))

Void GraphicContext_obj::Disable( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","Disable",0x98c667d5,"haxor.platform.graphics.GraphicContext.Disable","haxor/platform/graphics/GraphicContext.hx",98,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,Disable,(void))

Void GraphicContext_obj::Enable( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","Enable",0x8b5c8d36,"haxor.platform.graphics.GraphicContext.Enable","haxor/platform/graphics/GraphicContext.hx",99,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,Enable,(void))

Void GraphicContext_obj::DepthMask( bool p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","DepthMask",0xbc34aebc,"haxor.platform.graphics.GraphicContext.DepthMask","haxor/platform/graphics/GraphicContext.hx",100,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,DepthMask,(void))

Void GraphicContext_obj::DepthFunc( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","DepthFunc",0xb7a35914,"haxor.platform.graphics.GraphicContext.DepthFunc","haxor/platform/graphics/GraphicContext.hx",101,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,DepthFunc,(void))

Void GraphicContext_obj::CullFace( int p_face){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","CullFace",0x450218e2,"haxor.platform.graphics.GraphicContext.CullFace","haxor/platform/graphics/GraphicContext.hx",102,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_face,"p_face")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,CullFace,(void))

Void GraphicContext_obj::FrontFace( int p_face){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","FrontFace",0x9e1c1513,"haxor.platform.graphics.GraphicContext.FrontFace","haxor/platform/graphics/GraphicContext.hx",103,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_face,"p_face")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,FrontFace,(void))

Void GraphicContext_obj::Clear( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","Clear",0xf8a82a3a,"haxor.platform.graphics.GraphicContext.Clear","haxor/platform/graphics/GraphicContext.hx",106,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_flag,"p_flag")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,Clear,(void))

Void GraphicContext_obj::ClearDepth( Float p_value){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","ClearDepth",0x3e89e469,"haxor.platform.graphics.GraphicContext.ClearDepth","haxor/platform/graphics/GraphicContext.hx",107,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_value,"p_value")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,ClearDepth,(void))

Void GraphicContext_obj::ClearColor( Float p_r,Float p_g,Float p_b,Float p_a){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","ClearColor",0xb1bc64c9,"haxor.platform.graphics.GraphicContext.ClearColor","haxor/platform/graphics/GraphicContext.hx",108,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_r,"p_r")
		HX_STACK_ARG(p_g,"p_g")
		HX_STACK_ARG(p_b,"p_b")
		HX_STACK_ARG(p_a,"p_a")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(GraphicContext_obj,ClearColor,(void))

int GraphicContext_obj::GetErrorCode( ){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","GetErrorCode",0x91d53092,"haxor.platform.graphics.GraphicContext.GetErrorCode","haxor/platform/graphics/GraphicContext.hx",113,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(113)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,GetErrorCode,return )

::String GraphicContext_obj::GetErrorString( int p_code){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","GetErrorString",0xe5eb0b76,"haxor.platform.graphics.GraphicContext.GetErrorString","haxor/platform/graphics/GraphicContext.hx",115,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_ARG(p_code,"p_code")
	HX_STACK_LINE(116)
	switch( (int)(p_code)){
		case (int)0: {
			HX_STACK_LINE(118)
			return HX_CSTRING("");
		}
		;break;
		case (int)1280: {
			HX_STACK_LINE(119)
			return HX_CSTRING("Invalid Enum.");
		}
		;break;
		case (int)1281: {
			HX_STACK_LINE(120)
			return HX_CSTRING("Numeric argument is out of range.");
		}
		;break;
		case (int)1282: {
			HX_STACK_LINE(121)
			return HX_CSTRING("Operation not allowed in the current state.");
		}
		;break;
		case (int)1286: {
			HX_STACK_LINE(122)
			return HX_CSTRING("Write or Read in FrameBuffer not complete.");
		}
		;break;
		case (int)1285: {
			HX_STACK_LINE(123)
			return HX_CSTRING("Out of Memory.");
		}
		;break;
	}
	HX_STACK_LINE(125)
	return HX_CSTRING("Unknown Error.");
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,GetErrorString,return )

::String GraphicContext_obj::GetError( ){
	HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","GetError",0x6bd10cc5,"haxor.platform.graphics.GraphicContext.GetError","haxor/platform/graphics/GraphicContext.hx",127,0x2319fee2)
	HX_STACK_THIS(this)
	HX_STACK_LINE(127)
	int _g = this->GetErrorCode();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(127)
	return this->GetErrorString(_g);
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,GetError,return )

Void GraphicContext_obj::Assert( ::String p_log){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","Assert",0xded82579,"haxor.platform.graphics.GraphicContext.Assert","haxor/platform/graphics/GraphicContext.hx",129,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_ARG(p_log,"p_log")
		HX_STACK_LINE(130)
		int err = this->GetErrorCode();		HX_STACK_VAR(err,"err");
		HX_STACK_LINE(131)
		if (((err != (int)0))){
			HX_STACK_LINE(131)
			::String _g = this->GetErrorString(err);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(131)
			::String _g1 = (HX_CSTRING("GraphicContext> ") + _g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(131)
			::String _g2 = (_g1 + HX_CSTRING(" - "));		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(131)
			HX_STACK_DO_THROW((_g2 + p_log));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GraphicContext_obj,Assert,(void))

Void GraphicContext_obj::LogError( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GraphicContext","LogError",0xf7003a17,"haxor.platform.graphics.GraphicContext.LogError","haxor/platform/graphics/GraphicContext.hx",133,0x2319fee2)
		HX_STACK_THIS(this)
		HX_STACK_LINE(133)
		::String _g = this->GetError();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(133)
		::haxor::core::Console_obj::Log(_g,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GraphicContext_obj,LogError,(void))


GraphicContext_obj::GraphicContext_obj()
{
}

void GraphicContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GraphicContext);
	HX_MARK_MEMBER_NAME(m_api,"m_api");
	HX_MARK_MEMBER_NAME(m_application,"m_application");
	HX_MARK_END_CLASS();
}

void GraphicContext_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_api,"m_api");
	HX_VISIT_MEMBER_NAME(m_application,"m_application");
}

Dynamic GraphicContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"api") ) { return get_api(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"m_api") ) { return m_api; }
		if (HX_FIELD_EQ(inName,"Flush") ) { return Flush_dyn(); }
		if (HX_FIELD_EQ(inName,"Focus") ) { return Focus_dyn(); }
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Resize") ) { return Resize_dyn(); }
		if (HX_FIELD_EQ(inName,"Enable") ) { return Enable_dyn(); }
		if (HX_FIELD_EQ(inName,"Assert") ) { return Assert_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"get_api") ) { return get_api_dyn(); }
		if (HX_FIELD_EQ(inName,"Destroy") ) { return Destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"Disable") ) { return Disable_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"CullFace") ) { return CullFace_dyn(); }
		if (HX_FIELD_EQ(inName,"GetError") ) { return GetError_dyn(); }
		if (HX_FIELD_EQ(inName,"LogError") ) { return LogError_dyn(); }
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
		if (HX_FIELD_EQ(inName,"DeleteBuffer") ) { return DeleteBuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"DrawElements") ) { return DrawElements_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateShader") ) { return CreateShader_dyn(); }
		if (HX_FIELD_EQ(inName,"DeleteShader") ) { return DeleteShader_dyn(); }
		if (HX_FIELD_EQ(inName,"DetachShader") ) { return DetachShader_dyn(); }
		if (HX_FIELD_EQ(inName,"ShaderSource") ) { return ShaderSource_dyn(); }
		if (HX_FIELD_EQ(inName,"AttachShader") ) { return AttachShader_dyn(); }
		if (HX_FIELD_EQ(inName,"GetErrorCode") ) { return GetErrorCode_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_application") ) { return m_application; }
		if (HX_FIELD_EQ(inName,"BufferSubData") ) { return BufferSubData_dyn(); }
		if (HX_FIELD_EQ(inName,"CompileShader") ) { return CompileShader_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateProgram") ) { return CreateProgram_dyn(); }
		if (HX_FIELD_EQ(inName,"DeleteProgram") ) { return DeleteProgram_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"VertexAttrib3f") ) { return VertexAttrib3f_dyn(); }
		if (HX_FIELD_EQ(inName,"VertexAttrib4f") ) { return VertexAttrib4f_dyn(); }
		if (HX_FIELD_EQ(inName,"GetErrorString") ) { return GetErrorString_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"CheckExtensions") ) { return CheckExtensions_dyn(); }
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

Dynamic GraphicContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"m_api") ) { m_api=inValue.Cast< ::haxor::platform::graphics::GraphicAPI >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"m_application") ) { m_application=inValue.Cast< ::haxor::core::BaseApplication >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GraphicContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("api"));
	outFields->push(HX_CSTRING("m_api"));
	outFields->push(HX_CSTRING("m_application"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::haxor::platform::graphics::GraphicAPI*/ ,(int)offsetof(GraphicContext_obj,m_api),HX_CSTRING("m_api")},
	{hx::fsObject /*::haxor::core::BaseApplication*/ ,(int)offsetof(GraphicContext_obj,m_application),HX_CSTRING("m_application")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("get_api"),
	HX_CSTRING("m_api"),
	HX_CSTRING("m_application"),
	HX_CSTRING("CheckExtensions"),
	HX_CSTRING("Destroy"),
	HX_CSTRING("Flush"),
	HX_CSTRING("Focus"),
	HX_CSTRING("Resize"),
	HX_CSTRING("BindBuffer"),
	HX_CSTRING("BufferData"),
	HX_CSTRING("BufferSubData"),
	HX_CSTRING("CreateBuffer"),
	HX_CSTRING("DeleteBuffer"),
	HX_CSTRING("DrawArrays"),
	HX_CSTRING("DrawElements"),
	HX_CSTRING("EnableVertexAttrib"),
	HX_CSTRING("DisableVertexAttrib"),
	HX_CSTRING("VertexAttrib3f"),
	HX_CSTRING("VertexAttrib4f"),
	HX_CSTRING("VertexAttribPointer"),
	HX_CSTRING("CompileShader"),
	HX_CSTRING("CreateShader"),
	HX_CSTRING("DeleteShader"),
	HX_CSTRING("DetachShader"),
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
	HX_CSTRING("GetErrorString"),
	HX_CSTRING("GetError"),
	HX_CSTRING("Assert"),
	HX_CSTRING("LogError"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GraphicContext_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GraphicContext_obj::__mClass,"__mClass");
};

#endif

Class GraphicContext_obj::__mClass;

void GraphicContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.graphics.GraphicContext"), hx::TCanCast< GraphicContext_obj> ,sStaticFields,sMemberFields,
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

void GraphicContext_obj::__boot()
{
}

} // end namespace haxor
} // end namespace platform
} // end namespace graphics
