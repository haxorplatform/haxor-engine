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
#ifndef INCLUDED_haxor_core_IDisposable
#include <haxor/core/IDisposable.h>
#endif
#ifndef INCLUDED_haxor_core_Resource
#include <haxor/core/Resource.h>
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

Void GL_obj::__construct()
{
	return null();
}

//GL_obj::~GL_obj() { }

Dynamic GL_obj::__CreateEmpty() { return  new GL_obj; }
hx::ObjectPtr< GL_obj > GL_obj::__new()
{  hx::ObjectPtr< GL_obj > result = new GL_obj();
	result->__construct();
	return result;}

Dynamic GL_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GL_obj > result = new GL_obj();
	result->__construct();
	return result;}

int GL_obj::ACTIVE_ATTRIBUTES;

int GL_obj::ACTIVE_TEXTURE;

int GL_obj::ACTIVE_UNIFORMS;

int GL_obj::ALIASED_LINE_WIDTH_RANGE;

int GL_obj::ALIASED_POINT_SIZE_RANGE;

int GL_obj::ALPHA;

int GL_obj::ALPHA_BITS;

int GL_obj::ALWAYS;

int GL_obj::ARRAY_BUFFER;

int GL_obj::ARRAY_BUFFER_BINDING;

int GL_obj::ATTACHED_SHADERS;

int GL_obj::BACK;

int GL_obj::BLEND;

int GL_obj::BLEND_COLOR;

int GL_obj::BLEND_DST_ALPHA;

int GL_obj::BLEND_DST_RGB;

int GL_obj::BLEND_EQUATION;

int GL_obj::BLEND_EQUATION_ALPHA;

int GL_obj::BLEND_EQUATION_RGB;

int GL_obj::BLEND_SRC_ALPHA;

int GL_obj::BLEND_SRC_RGB;

int GL_obj::BLUE_BITS;

int GL_obj::BOOL;

int GL_obj::BOOL_VEC2;

int GL_obj::BOOL_VEC3;

int GL_obj::BOOL_VEC4;

int GL_obj::BROWSER_DEFAULT_WEBGL;

int GL_obj::BUFFER_SIZE;

int GL_obj::BUFFER_USAGE;

int GL_obj::BYTE;

int GL_obj::CCW;

int GL_obj::CLAMP_TO_EDGE;

int GL_obj::COLOR_ATTACHMENT0;

int GL_obj::COLOR_BUFFER_BIT;

int GL_obj::COLOR_CLEAR_VALUE;

int GL_obj::COLOR_WRITEMASK;

int GL_obj::COMPILE_STATUS;

int GL_obj::COMPRESSED_TEXTURE_FORMATS;

int GL_obj::CONSTANT_ALPHA;

int GL_obj::CONSTANT_COLOR;

int GL_obj::CONTEXT_LOST_WEBGL;

int GL_obj::CULL_FACE;

int GL_obj::CULL_FACE_MODE;

int GL_obj::CURRENT_PROGRAM;

int GL_obj::CURRENT_VERTEX_ATTRIB;

int GL_obj::CW;

int GL_obj::DECR;

int GL_obj::DECR_WRAP;

int GL_obj::DELETE_STATUS;

int GL_obj::DEPTH_ATTACHMENT;

int GL_obj::DEPTH_BITS;

int GL_obj::DEPTH_BUFFER_BIT;

int GL_obj::DEPTH_CLEAR_VALUE;

int GL_obj::DEPTH_COMPONENT;

int GL_obj::DEPTH_COMPONENT16;

int GL_obj::DEPTH_FUNC;

int GL_obj::DEPTH_RANGE;

int GL_obj::DEPTH_STENCIL;

int GL_obj::DEPTH_STENCIL_ATTACHMENT;

int GL_obj::DEPTH_TEST;

int GL_obj::DEPTH_WRITEMASK;

int GL_obj::DITHER;

int GL_obj::DONT_CARE;

int GL_obj::DST_ALPHA;

int GL_obj::DST_COLOR;

int GL_obj::DYNAMIC_DRAW;

int GL_obj::ELEMENT_ARRAY_BUFFER;

int GL_obj::ELEMENT_ARRAY_BUFFER_BINDING;

int GL_obj::EQUAL;

int GL_obj::FASTEST;

int GL_obj::FLOAT;

int GL_obj::FLOAT_MAT2;

int GL_obj::FLOAT_MAT3;

int GL_obj::FLOAT_MAT4;

int GL_obj::FLOAT_VEC2;

int GL_obj::FLOAT_VEC3;

int GL_obj::FLOAT_VEC4;

int GL_obj::FRAGMENT_SHADER;

int GL_obj::FRAMEBUFFER;

int GL_obj::FRAMEBUFFER_ATTACHMENT_OBJECT_NAME;

int GL_obj::FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE;

int GL_obj::FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE;

int GL_obj::FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL;

int GL_obj::FRAMEBUFFER_BINDING;

int GL_obj::FRAMEBUFFER_COMPLETE;

int GL_obj::FRAMEBUFFER_INCOMPLETE_ATTACHMENT;

int GL_obj::FRAMEBUFFER_INCOMPLETE_DIMENSIONS;

int GL_obj::FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT;

int GL_obj::FRAMEBUFFER_UNSUPPORTED;

int GL_obj::FRONT;

int GL_obj::FRONT_AND_BACK;

int GL_obj::FRONT_FACE;

int GL_obj::FUNC_ADD;

int GL_obj::FUNC_REVERSE_SUBTRACT;

int GL_obj::FUNC_SUBTRACT;

int GL_obj::GENERATE_MIPMAP_HINT;

int GL_obj::GEQUAL;

int GL_obj::GREATER;

int GL_obj::GREEN_BITS;

int GL_obj::HIGH_FLOAT;

int GL_obj::HIGH_INT;

int GL_obj::INCR;

int GL_obj::INCR_WRAP;

int GL_obj::INT;

int GL_obj::INT_VEC2;

int GL_obj::INT_VEC3;

int GL_obj::INT_VEC4;

int GL_obj::INVALID_ENUM;

int GL_obj::INVALID_FRAMEBUFFER_OPERATION;

int GL_obj::INVALID_OPERATION;

int GL_obj::INVALID_VALUE;

int GL_obj::INVERT;

int GL_obj::KEEP;

int GL_obj::LEQUAL;

int GL_obj::LESS;

int GL_obj::LINEAR;

int GL_obj::LINEAR_MIPMAP_LINEAR;

int GL_obj::LINEAR_MIPMAP_NEAREST;

int GL_obj::LINES;

int GL_obj::LINE_LOOP;

int GL_obj::LINE_STRIP;

int GL_obj::LINE_WIDTH;

int GL_obj::LINK_STATUS;

int GL_obj::LOW_FLOAT;

int GL_obj::LOW_INT;

int GL_obj::LUMINANCE;

int GL_obj::LUMINANCE_ALPHA;

int GL_obj::MAX_COMBINED_TEXTURE_IMAGE_UNITS;

int GL_obj::MAX_CUBE_MAP_TEXTURE_SIZE;

int GL_obj::MAX_FRAGMENT_UNIFORM_VECTORS;

int GL_obj::MAX_RENDERBUFFER_SIZE;

int GL_obj::MAX_TEXTURE_IMAGE_UNITS;

int GL_obj::MAX_TEXTURE_SIZE;

int GL_obj::MAX_VARYING_VECTORS;

int GL_obj::MAX_VERTEX_ATTRIBS;

int GL_obj::MAX_VERTEX_TEXTURE_IMAGE_UNITS;

int GL_obj::MAX_VERTEX_UNIFORM_VECTORS;

int GL_obj::MAX_VIEWPORT_DIMS;

int GL_obj::MEDIUM_FLOAT;

int GL_obj::MEDIUM_INT;

int GL_obj::MIRRORED_REPEAT;

int GL_obj::NEAREST;

int GL_obj::NEAREST_MIPMAP_LINEAR;

int GL_obj::NEAREST_MIPMAP_NEAREST;

int GL_obj::NEVER;

int GL_obj::NICEST;

int GL_obj::NONE;

int GL_obj::NOTEQUAL;

int GL_obj::NO_ERROR_GL;

int GL_obj::ONE;

int GL_obj::ONE_MINUS_CONSTANT_ALPHA;

int GL_obj::ONE_MINUS_CONSTANT_COLOR;

int GL_obj::ONE_MINUS_DST_ALPHA;

int GL_obj::ONE_MINUS_DST_COLOR;

int GL_obj::ONE_MINUS_SRC_ALPHA;

int GL_obj::ONE_MINUS_SRC_COLOR;

int GL_obj::OUT_OF_MEMORY;

int GL_obj::PACK_ALIGNMENT;

int GL_obj::POINTS;

int GL_obj::POLYGON_OFFSET_FACTOR;

int GL_obj::POLYGON_OFFSET_FILL;

int GL_obj::POLYGON_OFFSET_UNITS;

int GL_obj::RED_BITS;

int GL_obj::RENDERBUFFER;

int GL_obj::RENDERBUFFER_ALPHA_SIZE;

int GL_obj::RENDERBUFFER_BINDING;

int GL_obj::RENDERBUFFER_BLUE_SIZE;

int GL_obj::RENDERBUFFER_DEPTH_SIZE;

int GL_obj::RENDERBUFFER_GREEN_SIZE;

int GL_obj::RENDERBUFFER_HEIGHT;

int GL_obj::RENDERBUFFER_INTERNAL_FORMAT;

int GL_obj::RENDERBUFFER_RED_SIZE;

int GL_obj::RENDERBUFFER_STENCIL_SIZE;

int GL_obj::RENDERBUFFER_WIDTH;

int GL_obj::RENDERER;

int GL_obj::REPEAT;

int GL_obj::REPLACE;

int GL_obj::RGB;

int GL_obj::RGB565;

int GL_obj::RGB5_A1;

int GL_obj::RGBA;

int GL_obj::RGBA4;

int GL_obj::SAMPLER_2D;

int GL_obj::SAMPLER_CUBE;

int GL_obj::SAMPLES;

int GL_obj::SAMPLE_ALPHA_TO_COVERAGE;

int GL_obj::SAMPLE_BUFFERS;

int GL_obj::SAMPLE_COVERAGE;

int GL_obj::SAMPLE_COVERAGE_INVERT;

int GL_obj::SAMPLE_COVERAGE_VALUE;

int GL_obj::SCISSOR_BOX;

int GL_obj::SCISSOR_TEST;

int GL_obj::SHADER_TYPE;

int GL_obj::SHADING_LANGUAGE_VERSION;

int GL_obj::SHORT;

int GL_obj::SRC_ALPHA;

int GL_obj::SRC_ALPHA_SATURATE;

int GL_obj::SRC_COLOR;

int GL_obj::STATIC_DRAW;

int GL_obj::STENCIL_ATTACHMENT;

int GL_obj::STENCIL_BACK_FAIL;

int GL_obj::STENCIL_BACK_FUNC;

int GL_obj::STENCIL_BACK_PASS_DEPTH_FAIL;

int GL_obj::STENCIL_BACK_PASS_DEPTH_PASS;

int GL_obj::STENCIL_BACK_REF;

int GL_obj::STENCIL_BACK_VALUE_MASK;

int GL_obj::STENCIL_BACK_WRITEMASK;

int GL_obj::STENCIL_BITS;

int GL_obj::STENCIL_BUFFER_BIT;

int GL_obj::STENCIL_CLEAR_VALUE;

int GL_obj::STENCIL_FAIL;

int GL_obj::STENCIL_FUNC;

int GL_obj::STENCIL_INDEX;

int GL_obj::STENCIL_INDEX8;

int GL_obj::STENCIL_PASS_DEPTH_FAIL;

int GL_obj::STENCIL_PASS_DEPTH_PASS;

int GL_obj::STENCIL_REF;

int GL_obj::STENCIL_TEST;

int GL_obj::STENCIL_VALUE_MASK;

int GL_obj::STENCIL_WRITEMASK;

int GL_obj::STREAM_DRAW;

int GL_obj::SUBPIXEL_BITS;

int GL_obj::TEXTURE;

int GL_obj::TEXTURE0;

int GL_obj::TEXTURE1;

int GL_obj::TEXTURE10;

int GL_obj::TEXTURE11;

int GL_obj::TEXTURE12;

int GL_obj::TEXTURE13;

int GL_obj::TEXTURE14;

int GL_obj::TEXTURE15;

int GL_obj::TEXTURE16;

int GL_obj::TEXTURE17;

int GL_obj::TEXTURE18;

int GL_obj::TEXTURE19;

int GL_obj::TEXTURE2;

int GL_obj::TEXTURE20;

int GL_obj::TEXTURE21;

int GL_obj::TEXTURE22;

int GL_obj::TEXTURE23;

int GL_obj::TEXTURE24;

int GL_obj::TEXTURE25;

int GL_obj::TEXTURE26;

int GL_obj::TEXTURE27;

int GL_obj::TEXTURE28;

int GL_obj::TEXTURE29;

int GL_obj::TEXTURE3;

int GL_obj::TEXTURE30;

int GL_obj::TEXTURE31;

int GL_obj::TEXTURE4;

int GL_obj::TEXTURE5;

int GL_obj::TEXTURE6;

int GL_obj::TEXTURE7;

int GL_obj::TEXTURE8;

int GL_obj::TEXTURE9;

int GL_obj::TEXTURE_2D;

int GL_obj::TEXTURE_BINDING_2D;

int GL_obj::TEXTURE_BINDING_CUBE_MAP;

int GL_obj::TEXTURE_CUBE_MAP;

int GL_obj::TEXTURE_CUBE_MAP_NEGATIVE_X;

int GL_obj::TEXTURE_CUBE_MAP_NEGATIVE_Y;

int GL_obj::TEXTURE_CUBE_MAP_NEGATIVE_Z;

int GL_obj::TEXTURE_CUBE_MAP_POSITIVE_X;

int GL_obj::TEXTURE_CUBE_MAP_POSITIVE_Y;

int GL_obj::TEXTURE_CUBE_MAP_POSITIVE_Z;

int GL_obj::TEXTURE_MAG_FILTER;

int GL_obj::TEXTURE_MIN_FILTER;

int GL_obj::TEXTURE_WRAP_S;

int GL_obj::TEXTURE_WRAP_T;

int GL_obj::TRIANGLES;

int GL_obj::TRIANGLE_FAN;

int GL_obj::TRIANGLE_STRIP;

int GL_obj::UNPACK_ALIGNMENT;

int GL_obj::UNPACK_COLORSPACE_CONVERSION_WEBGL;

int GL_obj::UNPACK_FLIP_Y_WEBGL;

int GL_obj::UNPACK_PREMULTIPLY_ALPHA_WEBGL;

int GL_obj::UNSIGNED_BYTE;

int GL_obj::UNSIGNED_INT;

int GL_obj::UNSIGNED_SHORT;

int GL_obj::UNSIGNED_SHORT_4_4_4_4;

int GL_obj::UNSIGNED_SHORT_5_5_5_1;

int GL_obj::UNSIGNED_SHORT_5_6_5;

int GL_obj::VALIDATE_STATUS;

int GL_obj::VENDOR;

int GL_obj::VERSION;

int GL_obj::VERTEX_ATTRIB_ARRAY_BUFFER_BINDING;

int GL_obj::VERTEX_ATTRIB_ARRAY_ENABLED;

int GL_obj::VERTEX_ATTRIB_ARRAY_NORMALIZED;

int GL_obj::VERTEX_ATTRIB_ARRAY_POINTER;

int GL_obj::VERTEX_ATTRIB_ARRAY_SIZE;

int GL_obj::VERTEX_ATTRIB_ARRAY_STRIDE;

int GL_obj::VERTEX_ATTRIB_ARRAY_TYPE;

int GL_obj::VERTEX_SHADER;

int GL_obj::VIEWPORT;

int GL_obj::ZERO;

bool GL_obj::VERTEX_ARRAY_OBJECT;

int GL_obj::HALF_FLOAT;

bool GL_obj::TEXTURE_HALF;

bool GL_obj::TEXTURE_HALF_LINEAR;

int GL_obj::TEXTURE_ANISOTROPY;

bool GL_obj::TEXTURE_ANISOTROPY_ENABLED;

int GL_obj::MAX_TEXTURE_ANISOTROPY;

bool GL_obj::TEXTURE_FLOAT;

bool GL_obj::TEXTURE_FLOAT_LINEAR;

bool GL_obj::TEXTURE_DEPTH_ENABLED;

int GL_obj::MAX_ACTIVE_TEXTURE;

int GL_obj::_NULL;

int GL_obj::INVALID;

::haxor::platform::graphics::GraphicAPI GL_obj::get_api( ){
	HX_STACK_FRAME("haxor.platform.graphics.GL","get_api",0xaeb6cd1c,"haxor.platform.graphics.GL.get_api","haxor/platform/graphics/GL.hx",404,0x83cf3744)
	HX_STACK_LINE(404)
	return ::haxor::platform::graphics::GL_obj::m_gl->get_api();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,get_api,return )

::haxor::platform::graphics::OpenGL GL_obj::m_gl;

Void GL_obj::Initialize( ::haxor::core::BaseApplication p_application){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Initialize",0xe247b265,"haxor.platform.graphics.GL.Initialize","haxor/platform/graphics/GL.hx",417,0x83cf3744)
		HX_STACK_ARG(p_application,"p_application")
		HX_STACK_LINE(418)
		::haxor::platform::graphics::OpenGL _g = ::haxor::platform::graphics::OpenGL_obj::__new(p_application);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(418)
		::haxor::platform::graphics::GL_obj::m_gl = _g;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,Initialize,(void))

Void GL_obj::Resize( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Resize",0xfd626c89,"haxor.platform.graphics.GL.Resize","haxor/platform/graphics/GL.hx",424,0x83cf3744)
		HX_STACK_LINE(424)
		::haxor::platform::graphics::GL_obj::m_gl->Resize();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,Resize,(void))

Void GL_obj::BindBuffer( int p_target,int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","BindBuffer",0xee4b13b2,"haxor.platform.graphics.GL.BindBuffer","haxor/platform/graphics/GL.hx",433,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(433)
		::haxor::platform::graphics::GL_obj::m_gl->BindBuffer(p_target,p_id);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,BindBuffer,(void))

Void GL_obj::BufferData( int p_target,::haxor::io::Buffer p_data,int p_mode){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","BufferData",0x8900405f,"haxor.platform.graphics.GL.BufferData","haxor/platform/graphics/GL.hx",441,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_ARG(p_mode,"p_mode")
		HX_STACK_LINE(441)
		::haxor::platform::graphics::GL_obj::m_gl->BufferData(p_target,p_data,p_mode);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(GL_obj,BufferData,(void))

Void GL_obj::BufferSubData( int p_target,int p_offset,::haxor::io::Buffer p_data){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","BufferSubData",0xa24090b5,"haxor.platform.graphics.GL.BufferSubData","haxor/platform/graphics/GL.hx",450,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_offset,"p_offset")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_LINE(450)
		::haxor::platform::graphics::GL_obj::m_gl->BufferSubData(p_target,p_offset,p_data);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(GL_obj,BufferSubData,(void))

int GL_obj::CreateBuffer( ){
	HX_STACK_FRAME("haxor.platform.graphics.GL","CreateBuffer",0xc568ad71,"haxor.platform.graphics.GL.CreateBuffer","haxor/platform/graphics/GL.hx",456,0x83cf3744)
	HX_STACK_LINE(456)
	return ::haxor::platform::graphics::GL_obj::m_gl->CreateBuffer();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,CreateBuffer,return )

Void GL_obj::DrawArrays( int p_primitive,int p_start,int p_count){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","DrawArrays",0xef4074f3,"haxor.platform.graphics.GL.DrawArrays","haxor/platform/graphics/GL.hx",464,0x83cf3744)
		HX_STACK_ARG(p_primitive,"p_primitive")
		HX_STACK_ARG(p_start,"p_start")
		HX_STACK_ARG(p_count,"p_count")
		HX_STACK_LINE(464)
		::haxor::platform::graphics::GL_obj::m_gl->DrawArrays(p_primitive,p_start,p_count);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(GL_obj,DrawArrays,(void))

Void GL_obj::DrawElements( int p_primitive,int p_count,int p_type,int p_offset){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","DrawElements",0x2c3672b0,"haxor.platform.graphics.GL.DrawElements","haxor/platform/graphics/GL.hx",473,0x83cf3744)
		HX_STACK_ARG(p_primitive,"p_primitive")
		HX_STACK_ARG(p_count,"p_count")
		HX_STACK_ARG(p_type,"p_type")
		HX_STACK_ARG(p_offset,"p_offset")
		HX_STACK_LINE(473)
		::haxor::platform::graphics::GL_obj::m_gl->DrawElements(p_primitive,p_count,p_type,p_offset);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(GL_obj,DrawElements,(void))

Void GL_obj::DeleteBuffer( int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","DeleteBuffer",0x09ab93e0,"haxor.platform.graphics.GL.DeleteBuffer","haxor/platform/graphics/GL.hx",479,0x83cf3744)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(479)
		::haxor::platform::graphics::GL_obj::m_gl->DeleteBuffer(p_id);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,DeleteBuffer,(void))

Void GL_obj::DisableVertexAttrib( int p_location){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","DisableVertexAttrib",0x0cff0021,"haxor.platform.graphics.GL.DisableVertexAttrib","haxor/platform/graphics/GL.hx",485,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_LINE(485)
		::haxor::platform::graphics::GL_obj::m_gl->DisableVertexAttrib(p_location);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,DisableVertexAttrib,(void))

Void GL_obj::EnableVertexAttrib( int p_location){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","EnableVertexAttrib",0x4b5c2b06,"haxor.platform.graphics.GL.EnableVertexAttrib","haxor/platform/graphics/GL.hx",491,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_LINE(491)
		::haxor::platform::graphics::GL_obj::m_gl->EnableVertexAttrib(p_location);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,EnableVertexAttrib,(void))

Void GL_obj::VertexAttrib3f( int p_location,Float p_x,Float p_y,Float p_z){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","VertexAttrib3f",0xc781c5b6,"haxor.platform.graphics.GL.VertexAttrib3f","haxor/platform/graphics/GL.hx",500,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(500)
		::haxor::platform::graphics::GL_obj::m_gl->VertexAttrib3f(p_location,p_x,p_y,p_z);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(GL_obj,VertexAttrib3f,(void))

Void GL_obj::VertexAttrib4f( int p_location,Float p_x,Float p_y,Float p_z,Float p_w){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","VertexAttrib4f",0xc781c695,"haxor.platform.graphics.GL.VertexAttrib4f","haxor/platform/graphics/GL.hx",510,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(510)
		::haxor::platform::graphics::GL_obj::m_gl->VertexAttrib4f(p_location,p_x,p_y,p_z,p_w);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(GL_obj,VertexAttrib4f,(void))

Void GL_obj::VertexAttribPointer( int p_location,int p_components_size,int p_type,bool p_normalized,int p_stride,int p_offset){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","VertexAttribPointer",0x852d38da,"haxor.platform.graphics.GL.VertexAttribPointer","haxor/platform/graphics/GL.hx",521,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_components_size,"p_components_size")
		HX_STACK_ARG(p_type,"p_type")
		HX_STACK_ARG(p_normalized,"p_normalized")
		HX_STACK_ARG(p_stride,"p_stride")
		HX_STACK_ARG(p_offset,"p_offset")
		HX_STACK_LINE(521)
		::haxor::platform::graphics::GL_obj::m_gl->VertexAttribPointer(p_location,p_components_size,p_type,p_normalized,p_stride,p_offset);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(GL_obj,VertexAttribPointer,(void))

Void GL_obj::CompileShader( int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","CompileShader",0x370e0b03,"haxor.platform.graphics.GL.CompileShader","haxor/platform/graphics/GL.hx",532,0x83cf3744)
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_LINE(532)
		::haxor::platform::graphics::GL_obj::m_gl->CompileShader(p_shader);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,CompileShader,(void))

int GL_obj::CreateShader( int p_type){
	HX_STACK_FRAME("haxor.platform.graphics.GL","CreateShader",0x11f4af96,"haxor.platform.graphics.GL.CreateShader","haxor/platform/graphics/GL.hx",539,0x83cf3744)
	HX_STACK_ARG(p_type,"p_type")
	HX_STACK_LINE(539)
	return ::haxor::platform::graphics::GL_obj::m_gl->CreateShader(p_type);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,CreateShader,return )

Void GL_obj::DetachShader( int p_program,int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","DetachShader",0xbd2c812d,"haxor.platform.graphics.GL.DetachShader","haxor/platform/graphics/GL.hx",546,0x83cf3744)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_LINE(546)
		::haxor::platform::graphics::GL_obj::m_gl->DetachShader(p_program,p_shader);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,DetachShader,(void))

Void GL_obj::DeleteShader( int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","DeleteShader",0x56379605,"haxor.platform.graphics.GL.DeleteShader","haxor/platform/graphics/GL.hx",552,0x83cf3744)
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_LINE(552)
		::haxor::platform::graphics::GL_obj::m_gl->DeleteShader(p_shader);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,DeleteShader,(void))

::String GL_obj::GetShaderInfoLog( int p_shader){
	HX_STACK_FRAME("haxor.platform.graphics.GL","GetShaderInfoLog",0x546ebc70,"haxor.platform.graphics.GL.GetShaderInfoLog","haxor/platform/graphics/GL.hx",559,0x83cf3744)
	HX_STACK_ARG(p_shader,"p_shader")
	HX_STACK_LINE(559)
	return ::haxor::platform::graphics::GL_obj::m_gl->GetShaderInfoLog(p_shader);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,GetShaderInfoLog,return )

int GL_obj::GetShaderParameter( int p_shader,int p_parameter){
	HX_STACK_FRAME("haxor.platform.graphics.GL","GetShaderParameter",0x8b9e87e3,"haxor.platform.graphics.GL.GetShaderParameter","haxor/platform/graphics/GL.hx",567,0x83cf3744)
	HX_STACK_ARG(p_shader,"p_shader")
	HX_STACK_ARG(p_parameter,"p_parameter")
	HX_STACK_LINE(567)
	return ::haxor::platform::graphics::GL_obj::m_gl->GetShaderParameter(p_shader,p_parameter);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,GetShaderParameter,return )

Void GL_obj::ShaderSource( int p_shader,::String p_source){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","ShaderSource",0x7498fe35,"haxor.platform.graphics.GL.ShaderSource","haxor/platform/graphics/GL.hx",574,0x83cf3744)
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_ARG(p_source,"p_source")
		HX_STACK_LINE(574)
		::haxor::platform::graphics::GL_obj::m_gl->ShaderSource(p_shader,p_source);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,ShaderSource,(void))

Void GL_obj::AttachShader( int p_program,int p_shader){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","AttachShader",0x84f6811f,"haxor.platform.graphics.GL.AttachShader","haxor/platform/graphics/GL.hx",581,0x83cf3744)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_ARG(p_shader,"p_shader")
		HX_STACK_LINE(581)
		::haxor::platform::graphics::GL_obj::m_gl->AttachShader(p_program,p_shader);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,AttachShader,(void))

Void GL_obj::BindAttribLocation( int p_program,int p_location,::String p_name){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","BindAttribLocation",0x7373c451,"haxor.platform.graphics.GL.BindAttribLocation","haxor/platform/graphics/GL.hx",589,0x83cf3744)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_name,"p_name")
		HX_STACK_LINE(589)
		::haxor::platform::graphics::GL_obj::m_gl->BindAttribLocation(p_program,p_location,p_name);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(GL_obj,BindAttribLocation,(void))

int GL_obj::CreateProgram( ){
	HX_STACK_FRAME("haxor.platform.graphics.GL","CreateProgram",0x3897bcf3,"haxor.platform.graphics.GL.CreateProgram","haxor/platform/graphics/GL.hx",595,0x83cf3744)
	HX_STACK_LINE(595)
	return ::haxor::platform::graphics::GL_obj::m_gl->CreateProgram();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,CreateProgram,return )

Void GL_obj::DeleteProgram( int p_program){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","DeleteProgram",0xaede77a4,"haxor.platform.graphics.GL.DeleteProgram","haxor/platform/graphics/GL.hx",601,0x83cf3744)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_LINE(601)
		::haxor::platform::graphics::GL_obj::m_gl->DeleteProgram(p_program);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,DeleteProgram,(void))

int GL_obj::GetAttribLocation( int p_program,::String p_name){
	HX_STACK_FRAME("haxor.platform.graphics.GL","GetAttribLocation",0x8da91660,"haxor.platform.graphics.GL.GetAttribLocation","haxor/platform/graphics/GL.hx",609,0x83cf3744)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(609)
	return ::haxor::platform::graphics::GL_obj::m_gl->GetAttribLocation(p_program,p_name);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,GetAttribLocation,return )

int GL_obj::GetUniformLocation( int p_program,::String p_name){
	HX_STACK_FRAME("haxor.platform.graphics.GL","GetUniformLocation",0xa5177da8,"haxor.platform.graphics.GL.GetUniformLocation","haxor/platform/graphics/GL.hx",617,0x83cf3744)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_ARG(p_name,"p_name")
	HX_STACK_LINE(617)
	return ::haxor::platform::graphics::GL_obj::m_gl->GetUniformLocation(p_program,p_name);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,GetUniformLocation,return )

::String GL_obj::GetProgramInfoLog( int p_program){
	HX_STACK_FRAME("haxor.platform.graphics.GL","GetProgramInfoLog",0xfe8bed53,"haxor.platform.graphics.GL.GetProgramInfoLog","haxor/platform/graphics/GL.hx",624,0x83cf3744)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_LINE(624)
	return ::haxor::platform::graphics::GL_obj::m_gl->GetProgramInfoLog(p_program);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,GetProgramInfoLog,return )

int GL_obj::GetProgramParameter( int p_program,int p_parameter){
	HX_STACK_FRAME("haxor.platform.graphics.GL","GetProgramParameter",0xdc13f786,"haxor.platform.graphics.GL.GetProgramParameter","haxor/platform/graphics/GL.hx",632,0x83cf3744)
	HX_STACK_ARG(p_program,"p_program")
	HX_STACK_ARG(p_parameter,"p_parameter")
	HX_STACK_LINE(632)
	return ::haxor::platform::graphics::GL_obj::m_gl->GetProgramParameter(p_program,p_parameter);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,GetProgramParameter,return )

Void GL_obj::LinkProgram( int p_program){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","LinkProgram",0x6ee01ef5,"haxor.platform.graphics.GL.LinkProgram","haxor/platform/graphics/GL.hx",638,0x83cf3744)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_LINE(638)
		::haxor::platform::graphics::GL_obj::m_gl->LinkProgram(p_program);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,LinkProgram,(void))

Void GL_obj::UseProgram( int p_program){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","UseProgram",0xec38ee12,"haxor.platform.graphics.GL.UseProgram","haxor/platform/graphics/GL.hx",644,0x83cf3744)
		HX_STACK_ARG(p_program,"p_program")
		HX_STACK_LINE(644)
		::haxor::platform::graphics::GL_obj::m_gl->UseProgram(p_program);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,UseProgram,(void))

Void GL_obj::ActiveTexture( int p_slot){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","ActiveTexture",0xb305adc0,"haxor.platform.graphics.GL.ActiveTexture","haxor/platform/graphics/GL.hx",655,0x83cf3744)
		HX_STACK_ARG(p_slot,"p_slot")
		HX_STACK_LINE(655)
		::haxor::platform::graphics::GL_obj::m_gl->ActiveTexture(p_slot);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,ActiveTexture,(void))

Void GL_obj::BindFramebuffer( int p_target,int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","BindFramebuffer",0xc56038fb,"haxor.platform.graphics.GL.BindFramebuffer","haxor/platform/graphics/GL.hx",662,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(662)
		::haxor::platform::graphics::GL_obj::m_gl->BindFramebuffer(p_target,p_id);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,BindFramebuffer,(void))

Void GL_obj::BindRenderbuffer( int p_target,int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","BindRenderbuffer",0x755db508,"haxor.platform.graphics.GL.BindRenderbuffer","haxor/platform/graphics/GL.hx",669,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(669)
		::haxor::platform::graphics::GL_obj::m_gl->BindRenderbuffer(p_target,p_id);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,BindRenderbuffer,(void))

Void GL_obj::BindTexture( int p_target,int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","BindTexture",0x80b64de9,"haxor.platform.graphics.GL.BindTexture","haxor/platform/graphics/GL.hx",676,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(676)
		::haxor::platform::graphics::GL_obj::m_gl->BindTexture(p_target,p_id);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,BindTexture,(void))

int GL_obj::CreateFramebuffer( ){
	HX_STACK_FRAME("haxor.platform.graphics.GL","CreateFramebuffer",0xfd81eadc,"haxor.platform.graphics.GL.CreateFramebuffer","haxor/platform/graphics/GL.hx",682,0x83cf3744)
	HX_STACK_LINE(682)
	return ::haxor::platform::graphics::GL_obj::m_gl->CreateFramebuffer();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,CreateFramebuffer,return )

int GL_obj::CreateRenderbuffer( ){
	HX_STACK_FRAME("haxor.platform.graphics.GL","CreateRenderbuffer",0x5ab7a807,"haxor.platform.graphics.GL.CreateRenderbuffer","haxor/platform/graphics/GL.hx",688,0x83cf3744)
	HX_STACK_LINE(688)
	return ::haxor::platform::graphics::GL_obj::m_gl->CreateRenderbuffer();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,CreateRenderbuffer,return )

int GL_obj::CreateTexture( ){
	HX_STACK_FRAME("haxor.platform.graphics.GL","CreateTexture",0xe37f3b4a,"haxor.platform.graphics.GL.CreateTexture","haxor/platform/graphics/GL.hx",694,0x83cf3744)
	HX_STACK_LINE(694)
	return ::haxor::platform::graphics::GL_obj::m_gl->CreateTexture();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,CreateTexture,return )

Void GL_obj::DeleteFramebuffer( int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","DeleteFramebuffer",0x809a520d,"haxor.platform.graphics.GL.DeleteFramebuffer","haxor/platform/graphics/GL.hx",700,0x83cf3744)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(700)
		::haxor::platform::graphics::GL_obj::m_gl->DeleteFramebuffer(p_id);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,DeleteFramebuffer,(void))

Void GL_obj::DeleteRenderbuffer( int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","DeleteRenderbuffer",0x8cf98bb6,"haxor.platform.graphics.GL.DeleteRenderbuffer","haxor/platform/graphics/GL.hx",706,0x83cf3744)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(706)
		::haxor::platform::graphics::GL_obj::m_gl->DeleteRenderbuffer(p_id);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,DeleteRenderbuffer,(void))

Void GL_obj::DeleteTexture( int p_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","DeleteTexture",0x59c5f5fb,"haxor.platform.graphics.GL.DeleteTexture","haxor/platform/graphics/GL.hx",712,0x83cf3744)
		HX_STACK_ARG(p_id,"p_id")
		HX_STACK_LINE(712)
		::haxor::platform::graphics::GL_obj::m_gl->DeleteTexture(p_id);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,DeleteTexture,(void))

Void GL_obj::FramebufferRenderbuffer( int p_target,int p_attachment,int p_renderbuffer_target,int p_renderbuffer_id){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","FramebufferRenderbuffer",0x08e1932e,"haxor.platform.graphics.GL.FramebufferRenderbuffer","haxor/platform/graphics/GL.hx",722,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_attachment,"p_attachment")
		HX_STACK_ARG(p_renderbuffer_target,"p_renderbuffer_target")
		HX_STACK_ARG(p_renderbuffer_id,"p_renderbuffer_id")
		HX_STACK_LINE(722)
		::haxor::platform::graphics::GL_obj::m_gl->FramebufferRenderbuffer(p_target,p_attachment,p_renderbuffer_target,p_renderbuffer_id);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(GL_obj,FramebufferRenderbuffer,(void))

Void GL_obj::FramebufferTexture2D( int p_target,int p_attachment,int p_texture_target,int p_texture_id,int p_miplevel){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","FramebufferTexture2D",0xa6f8f415,"haxor.platform.graphics.GL.FramebufferTexture2D","haxor/platform/graphics/GL.hx",732,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_attachment,"p_attachment")
		HX_STACK_ARG(p_texture_target,"p_texture_target")
		HX_STACK_ARG(p_texture_id,"p_texture_id")
		HX_STACK_ARG(p_miplevel,"p_miplevel")
		HX_STACK_LINE(732)
		::haxor::platform::graphics::GL_obj::m_gl->FramebufferTexture2D(p_target,p_attachment,p_texture_target,p_texture_id,p_miplevel);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(GL_obj,FramebufferTexture2D,(void))

Void GL_obj::GenerateMipmap( int p_target){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","GenerateMipmap",0xced90632,"haxor.platform.graphics.GL.GenerateMipmap","haxor/platform/graphics/GL.hx",737,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_LINE(737)
		::haxor::platform::graphics::GL_obj::m_gl->GenerateMipmap(p_target);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,GenerateMipmap,(void))

Void GL_obj::PixelStorei( int p_parameter,int p_value){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","PixelStorei",0x662ca5d9,"haxor.platform.graphics.GL.PixelStorei","haxor/platform/graphics/GL.hx",744,0x83cf3744)
		HX_STACK_ARG(p_parameter,"p_parameter")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(744)
		::haxor::platform::graphics::GL_obj::m_gl->PixelStorei(p_parameter,p_value);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,PixelStorei,(void))

Void GL_obj::RenderbufferStorage( int p_target,int p_format,int p_width,int p_height){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","RenderbufferStorage",0xcce7d550,"haxor.platform.graphics.GL.RenderbufferStorage","haxor/platform/graphics/GL.hx",754,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_format,"p_format")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_LINE(754)
		::haxor::platform::graphics::GL_obj::m_gl->RenderbufferStorage(p_target,p_format,p_width,p_height);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(GL_obj,RenderbufferStorage,(void))

Void GL_obj::TexImage2D( int p_target,int p_level,int p_internal_format,int p_width,int p_height,int p_border,int p_format,int p_channel_type,::haxor::io::Buffer p_data){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","TexImage2D",0xaef3fddb,"haxor.platform.graphics.GL.TexImage2D","haxor/platform/graphics/GL.hx",768,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_level,"p_level")
		HX_STACK_ARG(p_internal_format,"p_internal_format")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_ARG(p_border,"p_border")
		HX_STACK_ARG(p_format,"p_format")
		HX_STACK_ARG(p_channel_type,"p_channel_type")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_LINE(768)
		::haxor::platform::graphics::GL_obj::m_gl->TexImage2D(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type,p_data);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC9(GL_obj,TexImage2D,(void))

Void GL_obj::TexImage2DAlloc( int p_target,int p_level,int p_internal_format,int p_width,int p_height,int p_border,int p_format,int p_channel_type){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","TexImage2DAlloc",0xcf5ffc9a,"haxor.platform.graphics.GL.TexImage2DAlloc","haxor/platform/graphics/GL.hx",781,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_level,"p_level")
		HX_STACK_ARG(p_internal_format,"p_internal_format")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_ARG(p_border,"p_border")
		HX_STACK_ARG(p_format,"p_format")
		HX_STACK_ARG(p_channel_type,"p_channel_type")
		HX_STACK_LINE(781)
		::haxor::platform::graphics::GL_obj::m_gl->TexImage2DAlloc(p_target,p_level,p_internal_format,p_width,p_height,p_border,p_format,p_channel_type);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC8(GL_obj,TexImage2DAlloc,(void))

Void GL_obj::TexSubImage2D( int p_target,int p_level,int p_x,int p_y,int p_width,int p_height,int p_format,int p_channel_type,::haxor::io::Buffer p_data){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","TexSubImage2D",0x84ebc91f,"haxor.platform.graphics.GL.TexSubImage2D","haxor/platform/graphics/GL.hx",796,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_level,"p_level")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_ARG(p_format,"p_format")
		HX_STACK_ARG(p_channel_type,"p_channel_type")
		HX_STACK_ARG(p_data,"p_data")
		HX_STACK_LINE(796)
		::haxor::platform::graphics::GL_obj::m_gl->TexSubImage2D(p_target,p_level,p_x,p_y,p_width,p_height,p_format,p_channel_type,p_data);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC9(GL_obj,TexSubImage2D,(void))

Void GL_obj::TexStorage2D( int p_target,int p_num_mipmaps,int p_channels,int p_width,int p_height){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","TexStorage2D",0xa1c34d3b,"haxor.platform.graphics.GL.TexStorage2D","haxor/platform/graphics/GL.hx",807,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_num_mipmaps,"p_num_mipmaps")
		HX_STACK_ARG(p_channels,"p_channels")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_LINE(807)
		::haxor::platform::graphics::GL_obj::m_gl->TexStorage2D(p_target,p_num_mipmaps,p_channels,p_width,p_height);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(GL_obj,TexStorage2D,(void))

Void GL_obj::TexParameterf( int p_target,int p_parameter,Float p_value){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","TexParameterf",0x988cc16f,"haxor.platform.graphics.GL.TexParameterf","haxor/platform/graphics/GL.hx",814,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_parameter,"p_parameter")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(814)
		::haxor::platform::graphics::GL_obj::m_gl->TexParameterf(p_target,p_parameter,p_value);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(GL_obj,TexParameterf,(void))

Void GL_obj::TexParameteri( int p_target,int p_parameter,int p_value){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","TexParameteri",0x988cc172,"haxor.platform.graphics.GL.TexParameteri","haxor/platform/graphics/GL.hx",822,0x83cf3744)
		HX_STACK_ARG(p_target,"p_target")
		HX_STACK_ARG(p_parameter,"p_parameter")
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(822)
		::haxor::platform::graphics::GL_obj::m_gl->TexParameteri(p_target,p_parameter,p_value);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(GL_obj,TexParameteri,(void))

Void GL_obj::Uniform1f( int p_location,Float p_x){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform1f",0x25ab19d4,"haxor.platform.graphics.GL.Uniform1f","haxor/platform/graphics/GL.hx",833,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_LINE(833)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform1f(p_location,p_x);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,Uniform1f,(void))

Void GL_obj::Uniform2f( int p_location,Float p_x,Float p_y){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform2f",0x25ab1ab3,"haxor.platform.graphics.GL.Uniform2f","haxor/platform/graphics/GL.hx",841,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(841)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform2f(p_location,p_x,p_y);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(GL_obj,Uniform2f,(void))

Void GL_obj::Uniform3f( int p_location,Float p_x,Float p_y,Float p_z){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform3f",0x25ab1b92,"haxor.platform.graphics.GL.Uniform3f","haxor/platform/graphics/GL.hx",850,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(850)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform3f(p_location,p_x,p_y,p_z);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(GL_obj,Uniform3f,(void))

Void GL_obj::Uniform4f( int p_location,Float p_x,Float p_y,Float p_z,Float p_w){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform4f",0x25ab1c71,"haxor.platform.graphics.GL.Uniform4f","haxor/platform/graphics/GL.hx",860,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(860)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform4f(p_location,p_x,p_y,p_z,p_w);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(GL_obj,Uniform4f,(void))

Void GL_obj::Uniform1i( int p_location,int p_x){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform1i",0x25ab19d7,"haxor.platform.graphics.GL.Uniform1i","haxor/platform/graphics/GL.hx",867,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_LINE(867)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform1i(p_location,p_x);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,Uniform1i,(void))

Void GL_obj::Uniform2i( int p_location,int p_x,int p_y){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform2i",0x25ab1ab6,"haxor.platform.graphics.GL.Uniform2i","haxor/platform/graphics/GL.hx",875,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_LINE(875)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform2i(p_location,p_x,p_y);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(GL_obj,Uniform2i,(void))

Void GL_obj::Uniform3i( int p_location,int p_x,int p_y,int p_z){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform3i",0x25ab1b95,"haxor.platform.graphics.GL.Uniform3i","haxor/platform/graphics/GL.hx",884,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_LINE(884)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform3i(p_location,p_x,p_y,p_z);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(GL_obj,Uniform3i,(void))

Void GL_obj::Uniform4i( int p_location,int p_x,int p_y,int p_z,int p_w){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform4i",0x25ab1c74,"haxor.platform.graphics.GL.Uniform4i","haxor/platform/graphics/GL.hx",894,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_z,"p_z")
		HX_STACK_ARG(p_w,"p_w")
		HX_STACK_LINE(894)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform4i(p_location,p_x,p_y,p_z,p_w);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(GL_obj,Uniform4i,(void))

Void GL_obj::Uniform1fv( int p_location,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform1fv",0xd00b8022,"haxor.platform.graphics.GL.Uniform1fv","haxor/platform/graphics/GL.hx",901,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(901)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform1fv(p_location,p_v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,Uniform1fv,(void))

Void GL_obj::Uniform2fv( int p_location,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform2fv",0xd00c4263,"haxor.platform.graphics.GL.Uniform2fv","haxor/platform/graphics/GL.hx",908,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(908)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform2fv(p_location,p_v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,Uniform2fv,(void))

Void GL_obj::Uniform3fv( int p_location,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform3fv",0xd00d04a4,"haxor.platform.graphics.GL.Uniform3fv","haxor/platform/graphics/GL.hx",915,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(915)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform3fv(p_location,p_v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,Uniform3fv,(void))

Void GL_obj::Uniform4fv( int p_location,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform4fv",0xd00dc6e5,"haxor.platform.graphics.GL.Uniform4fv","haxor/platform/graphics/GL.hx",922,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(922)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform4fv(p_location,p_v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,Uniform4fv,(void))

Void GL_obj::Uniform1iv( int p_location,::haxor::io::Int32Array p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform1iv",0xd00b82bf,"haxor.platform.graphics.GL.Uniform1iv","haxor/platform/graphics/GL.hx",929,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(929)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform1iv(p_location,p_v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,Uniform1iv,(void))

Void GL_obj::Uniform2iv( int p_location,::haxor::io::Int32Array p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform2iv",0xd00c4500,"haxor.platform.graphics.GL.Uniform2iv","haxor/platform/graphics/GL.hx",936,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(936)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform2iv(p_location,p_v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,Uniform2iv,(void))

Void GL_obj::Uniform3iv( int p_location,::haxor::io::Int32Array p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform3iv",0xd00d0741,"haxor.platform.graphics.GL.Uniform3iv","haxor/platform/graphics/GL.hx",943,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(943)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform3iv(p_location,p_v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,Uniform3iv,(void))

Void GL_obj::Uniform4iv( int p_location,::haxor::io::Int32Array p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Uniform4iv",0xd00dc982,"haxor.platform.graphics.GL.Uniform4iv","haxor/platform/graphics/GL.hx",950,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(950)
		::haxor::platform::graphics::GL_obj::m_gl->Uniform4iv(p_location,p_v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,Uniform4iv,(void))

Void GL_obj::UniformMatrix2fv( int p_location,bool p_transpose,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","UniformMatrix2fv",0x25ff8962,"haxor.platform.graphics.GL.UniformMatrix2fv","haxor/platform/graphics/GL.hx",958,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_transpose,"p_transpose")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(958)
		::haxor::platform::graphics::GL_obj::m_gl->UniformMatrix2fv(p_location,p_transpose,p_v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(GL_obj,UniformMatrix2fv,(void))

Void GL_obj::UniformMatrix3fv( int p_location,bool p_transpose,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","UniformMatrix3fv",0x26004ba3,"haxor.platform.graphics.GL.UniformMatrix3fv","haxor/platform/graphics/GL.hx",966,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_transpose,"p_transpose")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(966)
		::haxor::platform::graphics::GL_obj::m_gl->UniformMatrix3fv(p_location,p_transpose,p_v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(GL_obj,UniformMatrix3fv,(void))

Void GL_obj::UniformMatrix4fv( int p_location,bool p_transpose,::haxor::io::FloatArray p_v){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","UniformMatrix4fv",0x26010de4,"haxor.platform.graphics.GL.UniformMatrix4fv","haxor/platform/graphics/GL.hx",974,0x83cf3744)
		HX_STACK_ARG(p_location,"p_location")
		HX_STACK_ARG(p_transpose,"p_transpose")
		HX_STACK_ARG(p_v,"p_v")
		HX_STACK_LINE(974)
		::haxor::platform::graphics::GL_obj::m_gl->UniformMatrix4fv(p_location,p_transpose,p_v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(GL_obj,UniformMatrix4fv,(void))

Void GL_obj::BlendFunc( int p_src,int p_dst){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","BlendFunc",0x2568f4c0,"haxor.platform.graphics.GL.BlendFunc","haxor/platform/graphics/GL.hx",985,0x83cf3744)
		HX_STACK_ARG(p_src,"p_src")
		HX_STACK_ARG(p_dst,"p_dst")
		HX_STACK_LINE(985)
		::haxor::platform::graphics::GL_obj::m_gl->BlendFunc(p_src,p_dst);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(GL_obj,BlendFunc,(void))

Void GL_obj::Disable( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Disable",0x06a199b3,"haxor.platform.graphics.GL.Disable","haxor/platform/graphics/GL.hx",991,0x83cf3744)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(991)
		::haxor::platform::graphics::GL_obj::m_gl->Disable(p_flag);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,Disable,(void))

Void GL_obj::Enable( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Enable",0xed6ec118,"haxor.platform.graphics.GL.Enable","haxor/platform/graphics/GL.hx",997,0x83cf3744)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(997)
		::haxor::platform::graphics::GL_obj::m_gl->Enable(p_flag);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,Enable,(void))

Void GL_obj::DepthMask( bool p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","DepthMask",0xbca6941a,"haxor.platform.graphics.GL.DepthMask","haxor/platform/graphics/GL.hx",1003,0x83cf3744)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(1003)
		::haxor::platform::graphics::GL_obj::m_gl->DepthMask(p_flag);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,DepthMask,(void))

Void GL_obj::DepthFunc( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","DepthFunc",0xb8153e72,"haxor.platform.graphics.GL.DepthFunc","haxor/platform/graphics/GL.hx",1009,0x83cf3744)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(1009)
		::haxor::platform::graphics::GL_obj::m_gl->DepthFunc(p_flag);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,DepthFunc,(void))

Void GL_obj::CullFace( int p_face){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","CullFace",0xf6f28944,"haxor.platform.graphics.GL.CullFace","haxor/platform/graphics/GL.hx",1015,0x83cf3744)
		HX_STACK_ARG(p_face,"p_face")
		HX_STACK_LINE(1015)
		::haxor::platform::graphics::GL_obj::m_gl->CullFace(p_face);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,CullFace,(void))

Void GL_obj::FrontFace( int p_face){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","FrontFace",0x9e8dfa71,"haxor.platform.graphics.GL.FrontFace","haxor/platform/graphics/GL.hx",1021,0x83cf3744)
		HX_STACK_ARG(p_face,"p_face")
		HX_STACK_LINE(1021)
		::haxor::platform::graphics::GL_obj::m_gl->FrontFace(p_face);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,FrontFace,(void))

Void GL_obj::Clear( int p_flag){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Clear",0x0ee88898,"haxor.platform.graphics.GL.Clear","haxor/platform/graphics/GL.hx",1031,0x83cf3744)
		HX_STACK_ARG(p_flag,"p_flag")
		HX_STACK_LINE(1031)
		::haxor::platform::graphics::GL_obj::m_gl->Clear(p_flag);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,Clear,(void))

Void GL_obj::ClearDepth( Float p_value){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","ClearDepth",0xa1c0b14b,"haxor.platform.graphics.GL.ClearDepth","haxor/platform/graphics/GL.hx",1037,0x83cf3744)
		HX_STACK_ARG(p_value,"p_value")
		HX_STACK_LINE(1037)
		::haxor::platform::graphics::GL_obj::m_gl->ClearDepth(p_value);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,ClearDepth,(void))

Void GL_obj::ClearColor( Float p_r,Float p_g,Float p_b,Float p_a){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","ClearColor",0x14f331ab,"haxor.platform.graphics.GL.ClearColor","haxor/platform/graphics/GL.hx",1046,0x83cf3744)
		HX_STACK_ARG(p_r,"p_r")
		HX_STACK_ARG(p_g,"p_g")
		HX_STACK_ARG(p_b,"p_b")
		HX_STACK_ARG(p_a,"p_a")
		HX_STACK_LINE(1046)
		::haxor::platform::graphics::GL_obj::m_gl->ClearColor(p_r,p_g,p_b,p_a);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(GL_obj,ClearColor,(void))

Void GL_obj::Viewport( int p_x,int p_y,int p_width,int p_height){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Viewport",0xe765ee3b,"haxor.platform.graphics.GL.Viewport","haxor/platform/graphics/GL.hx",1055,0x83cf3744)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_LINE(1055)
		::haxor::platform::graphics::GL_obj::m_gl->Viewport(p_x,p_y,p_width,p_height);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(GL_obj,Viewport,(void))

Void GL_obj::Scissor( int p_x,int p_y,int p_width,int p_height){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Scissor",0x5a3057e7,"haxor.platform.graphics.GL.Scissor","haxor/platform/graphics/GL.hx",1064,0x83cf3744)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_LINE(1064)
		::haxor::platform::graphics::GL_obj::m_gl->Scissor(p_x,p_y,p_width,p_height);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(GL_obj,Scissor,(void))

Void GL_obj::ReadPixels( int p_x,int p_y,int p_width,int p_height,int p_format,int p_type,::haxor::io::Buffer p_pixels){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","ReadPixels",0x7bb25438,"haxor.platform.graphics.GL.ReadPixels","haxor/platform/graphics/GL.hx",1076,0x83cf3744)
		HX_STACK_ARG(p_x,"p_x")
		HX_STACK_ARG(p_y,"p_y")
		HX_STACK_ARG(p_width,"p_width")
		HX_STACK_ARG(p_height,"p_height")
		HX_STACK_ARG(p_format,"p_format")
		HX_STACK_ARG(p_type,"p_type")
		HX_STACK_ARG(p_pixels,"p_pixels")
		HX_STACK_LINE(1076)
		::haxor::platform::graphics::GL_obj::m_gl->ReadPixels(p_x,p_y,p_width,p_height,p_format,p_type,p_pixels);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(GL_obj,ReadPixels,(void))

::String GL_obj::GetError( ){
	HX_STACK_FRAME("haxor.platform.graphics.GL","GetError",0x1dc17d27,"haxor.platform.graphics.GL.GetError","haxor/platform/graphics/GL.hx",1092,0x83cf3744)
	HX_STACK_LINE(1092)
	return ::haxor::platform::graphics::GL_obj::m_gl->GetError();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,GetError,return )

int GL_obj::GetErrorCode( ){
	HX_STACK_FRAME("haxor.platform.graphics.GL","GetErrorCode",0x4a0279f4,"haxor.platform.graphics.GL.GetErrorCode","haxor/platform/graphics/GL.hx",1098,0x83cf3744)
	HX_STACK_LINE(1098)
	return ::haxor::platform::graphics::GL_obj::m_gl->GetErrorCode();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,GetErrorCode,return )

::String GL_obj::GetErrorString( int p_code){
	HX_STACK_FRAME("haxor.platform.graphics.GL","GetErrorString",0xfb06f158,"haxor.platform.graphics.GL.GetErrorString","haxor/platform/graphics/GL.hx",1105,0x83cf3744)
	HX_STACK_ARG(p_code,"p_code")
	HX_STACK_LINE(1105)
	return ::haxor::platform::graphics::GL_obj::m_gl->GetErrorString(p_code);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,GetErrorString,return )

Void GL_obj::LogError( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","LogError",0xa8f0aa79,"haxor.platform.graphics.GL.LogError","haxor/platform/graphics/GL.hx",1111,0x83cf3744)
		HX_STACK_LINE(1111)
		::haxor::platform::graphics::GL_obj::m_gl->LogError();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,LogError,(void))

Void GL_obj::Assert( ::String p_log){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Assert",0x40ea595b,"haxor.platform.graphics.GL.Assert","haxor/platform/graphics/GL.hx",1117,0x83cf3744)
		HX_STACK_ARG(p_log,"p_log")
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(GL_obj,Assert,(void))

Void GL_obj::Flush( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Flush",0xc92879cf,"haxor.platform.graphics.GL.Flush","haxor/platform/graphics/GL.hx",1131,0x83cf3744)
		HX_STACK_LINE(1131)
		::haxor::platform::graphics::GL_obj::m_gl->Flush();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,Flush,(void))

Void GL_obj::Focus( ){
{
		HX_STACK_FRAME("haxor.platform.graphics.GL","Focus",0xcb1676e3,"haxor.platform.graphics.GL.Focus","haxor/platform/graphics/GL.hx",1136,0x83cf3744)
		HX_STACK_LINE(1136)
		::haxor::platform::graphics::GL_obj::m_gl->Focus();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(GL_obj,Focus,(void))


GL_obj::GL_obj()
{
}

Dynamic GL_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"api") ) { return get_api(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"NULL") ) { return _NULL; }
		if (HX_FIELD_EQ(inName,"m_gl") ) { return m_gl; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Clear") ) { return Clear_dyn(); }
		if (HX_FIELD_EQ(inName,"Flush") ) { return Flush_dyn(); }
		if (HX_FIELD_EQ(inName,"Focus") ) { return Focus_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Resize") ) { return Resize_dyn(); }
		if (HX_FIELD_EQ(inName,"Enable") ) { return Enable_dyn(); }
		if (HX_FIELD_EQ(inName,"Assert") ) { return Assert_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"INVALID") ) { return INVALID; }
		if (HX_FIELD_EQ(inName,"get_api") ) { return get_api_dyn(); }
		if (HX_FIELD_EQ(inName,"Disable") ) { return Disable_dyn(); }
		if (HX_FIELD_EQ(inName,"Scissor") ) { return Scissor_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"CullFace") ) { return CullFace_dyn(); }
		if (HX_FIELD_EQ(inName,"Viewport") ) { return Viewport_dyn(); }
		if (HX_FIELD_EQ(inName,"GetError") ) { return GetError_dyn(); }
		if (HX_FIELD_EQ(inName,"LogError") ) { return LogError_dyn(); }
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
		if (HX_FIELD_EQ(inName,"HALF_FLOAT") ) { return HALF_FLOAT; }
		if (HX_FIELD_EQ(inName,"Initialize") ) { return Initialize_dyn(); }
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
		if (HX_FIELD_EQ(inName,"TEXTURE_HALF") ) { return TEXTURE_HALF; }
		if (HX_FIELD_EQ(inName,"CreateBuffer") ) { return CreateBuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"DrawElements") ) { return DrawElements_dyn(); }
		if (HX_FIELD_EQ(inName,"DeleteBuffer") ) { return DeleteBuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateShader") ) { return CreateShader_dyn(); }
		if (HX_FIELD_EQ(inName,"DetachShader") ) { return DetachShader_dyn(); }
		if (HX_FIELD_EQ(inName,"DeleteShader") ) { return DeleteShader_dyn(); }
		if (HX_FIELD_EQ(inName,"ShaderSource") ) { return ShaderSource_dyn(); }
		if (HX_FIELD_EQ(inName,"AttachShader") ) { return AttachShader_dyn(); }
		if (HX_FIELD_EQ(inName,"TexStorage2D") ) { return TexStorage2D_dyn(); }
		if (HX_FIELD_EQ(inName,"GetErrorCode") ) { return GetErrorCode_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TEXTURE_FLOAT") ) { return TEXTURE_FLOAT; }
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
		if (HX_FIELD_EQ(inName,"GetErrorString") ) { return GetErrorString_dyn(); }
		break;
	case 15:
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
		if (HX_FIELD_EQ(inName,"TEXTURE_ANISOTROPY") ) { return TEXTURE_ANISOTROPY; }
		if (HX_FIELD_EQ(inName,"MAX_ACTIVE_TEXTURE") ) { return MAX_ACTIVE_TEXTURE; }
		if (HX_FIELD_EQ(inName,"EnableVertexAttrib") ) { return EnableVertexAttrib_dyn(); }
		if (HX_FIELD_EQ(inName,"GetShaderParameter") ) { return GetShaderParameter_dyn(); }
		if (HX_FIELD_EQ(inName,"BindAttribLocation") ) { return BindAttribLocation_dyn(); }
		if (HX_FIELD_EQ(inName,"GetUniformLocation") ) { return GetUniformLocation_dyn(); }
		if (HX_FIELD_EQ(inName,"CreateRenderbuffer") ) { return CreateRenderbuffer_dyn(); }
		if (HX_FIELD_EQ(inName,"DeleteRenderbuffer") ) { return DeleteRenderbuffer_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"VERTEX_ARRAY_OBJECT") ) { return VERTEX_ARRAY_OBJECT; }
		if (HX_FIELD_EQ(inName,"TEXTURE_HALF_LINEAR") ) { return TEXTURE_HALF_LINEAR; }
		if (HX_FIELD_EQ(inName,"DisableVertexAttrib") ) { return DisableVertexAttrib_dyn(); }
		if (HX_FIELD_EQ(inName,"VertexAttribPointer") ) { return VertexAttribPointer_dyn(); }
		if (HX_FIELD_EQ(inName,"GetProgramParameter") ) { return GetProgramParameter_dyn(); }
		if (HX_FIELD_EQ(inName,"RenderbufferStorage") ) { return RenderbufferStorage_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"TEXTURE_FLOAT_LINEAR") ) { return TEXTURE_FLOAT_LINEAR; }
		if (HX_FIELD_EQ(inName,"FramebufferTexture2D") ) { return FramebufferTexture2D_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"TEXTURE_DEPTH_ENABLED") ) { return TEXTURE_DEPTH_ENABLED; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"MAX_TEXTURE_ANISOTROPY") ) { return MAX_TEXTURE_ANISOTROPY; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"FramebufferRenderbuffer") ) { return FramebufferRenderbuffer_dyn(); }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"TEXTURE_ANISOTROPY_ENABLED") ) { return TEXTURE_ANISOTROPY_ENABLED; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GL_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"NULL") ) { _NULL=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_gl") ) { m_gl=inValue.Cast< ::haxor::platform::graphics::OpenGL >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"INVALID") ) { INVALID=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"HALF_FLOAT") ) { HALF_FLOAT=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"TEXTURE_HALF") ) { TEXTURE_HALF=inValue.Cast< bool >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"TEXTURE_FLOAT") ) { TEXTURE_FLOAT=inValue.Cast< bool >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"TEXTURE_ANISOTROPY") ) { TEXTURE_ANISOTROPY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MAX_ACTIVE_TEXTURE") ) { MAX_ACTIVE_TEXTURE=inValue.Cast< int >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"VERTEX_ARRAY_OBJECT") ) { VERTEX_ARRAY_OBJECT=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TEXTURE_HALF_LINEAR") ) { TEXTURE_HALF_LINEAR=inValue.Cast< bool >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"TEXTURE_FLOAT_LINEAR") ) { TEXTURE_FLOAT_LINEAR=inValue.Cast< bool >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"TEXTURE_DEPTH_ENABLED") ) { TEXTURE_DEPTH_ENABLED=inValue.Cast< bool >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"MAX_TEXTURE_ANISOTROPY") ) { MAX_TEXTURE_ANISOTROPY=inValue.Cast< int >(); return inValue; }
		break;
	case 26:
		if (HX_FIELD_EQ(inName,"TEXTURE_ANISOTROPY_ENABLED") ) { TEXTURE_ANISOTROPY_ENABLED=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GL_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ACTIVE_ATTRIBUTES"),
	HX_CSTRING("ACTIVE_TEXTURE"),
	HX_CSTRING("ACTIVE_UNIFORMS"),
	HX_CSTRING("ALIASED_LINE_WIDTH_RANGE"),
	HX_CSTRING("ALIASED_POINT_SIZE_RANGE"),
	HX_CSTRING("ALPHA"),
	HX_CSTRING("ALPHA_BITS"),
	HX_CSTRING("ALWAYS"),
	HX_CSTRING("ARRAY_BUFFER"),
	HX_CSTRING("ARRAY_BUFFER_BINDING"),
	HX_CSTRING("ATTACHED_SHADERS"),
	HX_CSTRING("BACK"),
	HX_CSTRING("BLEND"),
	HX_CSTRING("BLEND_COLOR"),
	HX_CSTRING("BLEND_DST_ALPHA"),
	HX_CSTRING("BLEND_DST_RGB"),
	HX_CSTRING("BLEND_EQUATION"),
	HX_CSTRING("BLEND_EQUATION_ALPHA"),
	HX_CSTRING("BLEND_EQUATION_RGB"),
	HX_CSTRING("BLEND_SRC_ALPHA"),
	HX_CSTRING("BLEND_SRC_RGB"),
	HX_CSTRING("BLUE_BITS"),
	HX_CSTRING("BOOL"),
	HX_CSTRING("BOOL_VEC2"),
	HX_CSTRING("BOOL_VEC3"),
	HX_CSTRING("BOOL_VEC4"),
	HX_CSTRING("BROWSER_DEFAULT_WEBGL"),
	HX_CSTRING("BUFFER_SIZE"),
	HX_CSTRING("BUFFER_USAGE"),
	HX_CSTRING("BYTE"),
	HX_CSTRING("CCW"),
	HX_CSTRING("CLAMP_TO_EDGE"),
	HX_CSTRING("COLOR_ATTACHMENT0"),
	HX_CSTRING("COLOR_BUFFER_BIT"),
	HX_CSTRING("COLOR_CLEAR_VALUE"),
	HX_CSTRING("COLOR_WRITEMASK"),
	HX_CSTRING("COMPILE_STATUS"),
	HX_CSTRING("COMPRESSED_TEXTURE_FORMATS"),
	HX_CSTRING("CONSTANT_ALPHA"),
	HX_CSTRING("CONSTANT_COLOR"),
	HX_CSTRING("CONTEXT_LOST_WEBGL"),
	HX_CSTRING("CULL_FACE"),
	HX_CSTRING("CULL_FACE_MODE"),
	HX_CSTRING("CURRENT_PROGRAM"),
	HX_CSTRING("CURRENT_VERTEX_ATTRIB"),
	HX_CSTRING("CW"),
	HX_CSTRING("DECR"),
	HX_CSTRING("DECR_WRAP"),
	HX_CSTRING("DELETE_STATUS"),
	HX_CSTRING("DEPTH_ATTACHMENT"),
	HX_CSTRING("DEPTH_BITS"),
	HX_CSTRING("DEPTH_BUFFER_BIT"),
	HX_CSTRING("DEPTH_CLEAR_VALUE"),
	HX_CSTRING("DEPTH_COMPONENT"),
	HX_CSTRING("DEPTH_COMPONENT16"),
	HX_CSTRING("DEPTH_FUNC"),
	HX_CSTRING("DEPTH_RANGE"),
	HX_CSTRING("DEPTH_STENCIL"),
	HX_CSTRING("DEPTH_STENCIL_ATTACHMENT"),
	HX_CSTRING("DEPTH_TEST"),
	HX_CSTRING("DEPTH_WRITEMASK"),
	HX_CSTRING("DITHER"),
	HX_CSTRING("DONT_CARE"),
	HX_CSTRING("DST_ALPHA"),
	HX_CSTRING("DST_COLOR"),
	HX_CSTRING("DYNAMIC_DRAW"),
	HX_CSTRING("ELEMENT_ARRAY_BUFFER"),
	HX_CSTRING("ELEMENT_ARRAY_BUFFER_BINDING"),
	HX_CSTRING("EQUAL"),
	HX_CSTRING("FASTEST"),
	HX_CSTRING("FLOAT"),
	HX_CSTRING("FLOAT_MAT2"),
	HX_CSTRING("FLOAT_MAT3"),
	HX_CSTRING("FLOAT_MAT4"),
	HX_CSTRING("FLOAT_VEC2"),
	HX_CSTRING("FLOAT_VEC3"),
	HX_CSTRING("FLOAT_VEC4"),
	HX_CSTRING("FRAGMENT_SHADER"),
	HX_CSTRING("FRAMEBUFFER"),
	HX_CSTRING("FRAMEBUFFER_ATTACHMENT_OBJECT_NAME"),
	HX_CSTRING("FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE"),
	HX_CSTRING("FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE"),
	HX_CSTRING("FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL"),
	HX_CSTRING("FRAMEBUFFER_BINDING"),
	HX_CSTRING("FRAMEBUFFER_COMPLETE"),
	HX_CSTRING("FRAMEBUFFER_INCOMPLETE_ATTACHMENT"),
	HX_CSTRING("FRAMEBUFFER_INCOMPLETE_DIMENSIONS"),
	HX_CSTRING("FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT"),
	HX_CSTRING("FRAMEBUFFER_UNSUPPORTED"),
	HX_CSTRING("FRONT"),
	HX_CSTRING("FRONT_AND_BACK"),
	HX_CSTRING("FRONT_FACE"),
	HX_CSTRING("FUNC_ADD"),
	HX_CSTRING("FUNC_REVERSE_SUBTRACT"),
	HX_CSTRING("FUNC_SUBTRACT"),
	HX_CSTRING("GENERATE_MIPMAP_HINT"),
	HX_CSTRING("GEQUAL"),
	HX_CSTRING("GREATER"),
	HX_CSTRING("GREEN_BITS"),
	HX_CSTRING("HIGH_FLOAT"),
	HX_CSTRING("HIGH_INT"),
	HX_CSTRING("INCR"),
	HX_CSTRING("INCR_WRAP"),
	HX_CSTRING("INT"),
	HX_CSTRING("INT_VEC2"),
	HX_CSTRING("INT_VEC3"),
	HX_CSTRING("INT_VEC4"),
	HX_CSTRING("INVALID_ENUM"),
	HX_CSTRING("INVALID_FRAMEBUFFER_OPERATION"),
	HX_CSTRING("INVALID_OPERATION"),
	HX_CSTRING("INVALID_VALUE"),
	HX_CSTRING("INVERT"),
	HX_CSTRING("KEEP"),
	HX_CSTRING("LEQUAL"),
	HX_CSTRING("LESS"),
	HX_CSTRING("LINEAR"),
	HX_CSTRING("LINEAR_MIPMAP_LINEAR"),
	HX_CSTRING("LINEAR_MIPMAP_NEAREST"),
	HX_CSTRING("LINES"),
	HX_CSTRING("LINE_LOOP"),
	HX_CSTRING("LINE_STRIP"),
	HX_CSTRING("LINE_WIDTH"),
	HX_CSTRING("LINK_STATUS"),
	HX_CSTRING("LOW_FLOAT"),
	HX_CSTRING("LOW_INT"),
	HX_CSTRING("LUMINANCE"),
	HX_CSTRING("LUMINANCE_ALPHA"),
	HX_CSTRING("MAX_COMBINED_TEXTURE_IMAGE_UNITS"),
	HX_CSTRING("MAX_CUBE_MAP_TEXTURE_SIZE"),
	HX_CSTRING("MAX_FRAGMENT_UNIFORM_VECTORS"),
	HX_CSTRING("MAX_RENDERBUFFER_SIZE"),
	HX_CSTRING("MAX_TEXTURE_IMAGE_UNITS"),
	HX_CSTRING("MAX_TEXTURE_SIZE"),
	HX_CSTRING("MAX_VARYING_VECTORS"),
	HX_CSTRING("MAX_VERTEX_ATTRIBS"),
	HX_CSTRING("MAX_VERTEX_TEXTURE_IMAGE_UNITS"),
	HX_CSTRING("MAX_VERTEX_UNIFORM_VECTORS"),
	HX_CSTRING("MAX_VIEWPORT_DIMS"),
	HX_CSTRING("MEDIUM_FLOAT"),
	HX_CSTRING("MEDIUM_INT"),
	HX_CSTRING("MIRRORED_REPEAT"),
	HX_CSTRING("NEAREST"),
	HX_CSTRING("NEAREST_MIPMAP_LINEAR"),
	HX_CSTRING("NEAREST_MIPMAP_NEAREST"),
	HX_CSTRING("NEVER"),
	HX_CSTRING("NICEST"),
	HX_CSTRING("NONE"),
	HX_CSTRING("NOTEQUAL"),
	HX_CSTRING("NO_ERROR_GL"),
	HX_CSTRING("ONE"),
	HX_CSTRING("ONE_MINUS_CONSTANT_ALPHA"),
	HX_CSTRING("ONE_MINUS_CONSTANT_COLOR"),
	HX_CSTRING("ONE_MINUS_DST_ALPHA"),
	HX_CSTRING("ONE_MINUS_DST_COLOR"),
	HX_CSTRING("ONE_MINUS_SRC_ALPHA"),
	HX_CSTRING("ONE_MINUS_SRC_COLOR"),
	HX_CSTRING("OUT_OF_MEMORY"),
	HX_CSTRING("PACK_ALIGNMENT"),
	HX_CSTRING("POINTS"),
	HX_CSTRING("POLYGON_OFFSET_FACTOR"),
	HX_CSTRING("POLYGON_OFFSET_FILL"),
	HX_CSTRING("POLYGON_OFFSET_UNITS"),
	HX_CSTRING("RED_BITS"),
	HX_CSTRING("RENDERBUFFER"),
	HX_CSTRING("RENDERBUFFER_ALPHA_SIZE"),
	HX_CSTRING("RENDERBUFFER_BINDING"),
	HX_CSTRING("RENDERBUFFER_BLUE_SIZE"),
	HX_CSTRING("RENDERBUFFER_DEPTH_SIZE"),
	HX_CSTRING("RENDERBUFFER_GREEN_SIZE"),
	HX_CSTRING("RENDERBUFFER_HEIGHT"),
	HX_CSTRING("RENDERBUFFER_INTERNAL_FORMAT"),
	HX_CSTRING("RENDERBUFFER_RED_SIZE"),
	HX_CSTRING("RENDERBUFFER_STENCIL_SIZE"),
	HX_CSTRING("RENDERBUFFER_WIDTH"),
	HX_CSTRING("RENDERER"),
	HX_CSTRING("REPEAT"),
	HX_CSTRING("REPLACE"),
	HX_CSTRING("RGB"),
	HX_CSTRING("RGB565"),
	HX_CSTRING("RGB5_A1"),
	HX_CSTRING("RGBA"),
	HX_CSTRING("RGBA4"),
	HX_CSTRING("SAMPLER_2D"),
	HX_CSTRING("SAMPLER_CUBE"),
	HX_CSTRING("SAMPLES"),
	HX_CSTRING("SAMPLE_ALPHA_TO_COVERAGE"),
	HX_CSTRING("SAMPLE_BUFFERS"),
	HX_CSTRING("SAMPLE_COVERAGE"),
	HX_CSTRING("SAMPLE_COVERAGE_INVERT"),
	HX_CSTRING("SAMPLE_COVERAGE_VALUE"),
	HX_CSTRING("SCISSOR_BOX"),
	HX_CSTRING("SCISSOR_TEST"),
	HX_CSTRING("SHADER_TYPE"),
	HX_CSTRING("SHADING_LANGUAGE_VERSION"),
	HX_CSTRING("SHORT"),
	HX_CSTRING("SRC_ALPHA"),
	HX_CSTRING("SRC_ALPHA_SATURATE"),
	HX_CSTRING("SRC_COLOR"),
	HX_CSTRING("STATIC_DRAW"),
	HX_CSTRING("STENCIL_ATTACHMENT"),
	HX_CSTRING("STENCIL_BACK_FAIL"),
	HX_CSTRING("STENCIL_BACK_FUNC"),
	HX_CSTRING("STENCIL_BACK_PASS_DEPTH_FAIL"),
	HX_CSTRING("STENCIL_BACK_PASS_DEPTH_PASS"),
	HX_CSTRING("STENCIL_BACK_REF"),
	HX_CSTRING("STENCIL_BACK_VALUE_MASK"),
	HX_CSTRING("STENCIL_BACK_WRITEMASK"),
	HX_CSTRING("STENCIL_BITS"),
	HX_CSTRING("STENCIL_BUFFER_BIT"),
	HX_CSTRING("STENCIL_CLEAR_VALUE"),
	HX_CSTRING("STENCIL_FAIL"),
	HX_CSTRING("STENCIL_FUNC"),
	HX_CSTRING("STENCIL_INDEX"),
	HX_CSTRING("STENCIL_INDEX8"),
	HX_CSTRING("STENCIL_PASS_DEPTH_FAIL"),
	HX_CSTRING("STENCIL_PASS_DEPTH_PASS"),
	HX_CSTRING("STENCIL_REF"),
	HX_CSTRING("STENCIL_TEST"),
	HX_CSTRING("STENCIL_VALUE_MASK"),
	HX_CSTRING("STENCIL_WRITEMASK"),
	HX_CSTRING("STREAM_DRAW"),
	HX_CSTRING("SUBPIXEL_BITS"),
	HX_CSTRING("TEXTURE"),
	HX_CSTRING("TEXTURE0"),
	HX_CSTRING("TEXTURE1"),
	HX_CSTRING("TEXTURE10"),
	HX_CSTRING("TEXTURE11"),
	HX_CSTRING("TEXTURE12"),
	HX_CSTRING("TEXTURE13"),
	HX_CSTRING("TEXTURE14"),
	HX_CSTRING("TEXTURE15"),
	HX_CSTRING("TEXTURE16"),
	HX_CSTRING("TEXTURE17"),
	HX_CSTRING("TEXTURE18"),
	HX_CSTRING("TEXTURE19"),
	HX_CSTRING("TEXTURE2"),
	HX_CSTRING("TEXTURE20"),
	HX_CSTRING("TEXTURE21"),
	HX_CSTRING("TEXTURE22"),
	HX_CSTRING("TEXTURE23"),
	HX_CSTRING("TEXTURE24"),
	HX_CSTRING("TEXTURE25"),
	HX_CSTRING("TEXTURE26"),
	HX_CSTRING("TEXTURE27"),
	HX_CSTRING("TEXTURE28"),
	HX_CSTRING("TEXTURE29"),
	HX_CSTRING("TEXTURE3"),
	HX_CSTRING("TEXTURE30"),
	HX_CSTRING("TEXTURE31"),
	HX_CSTRING("TEXTURE4"),
	HX_CSTRING("TEXTURE5"),
	HX_CSTRING("TEXTURE6"),
	HX_CSTRING("TEXTURE7"),
	HX_CSTRING("TEXTURE8"),
	HX_CSTRING("TEXTURE9"),
	HX_CSTRING("TEXTURE_2D"),
	HX_CSTRING("TEXTURE_BINDING_2D"),
	HX_CSTRING("TEXTURE_BINDING_CUBE_MAP"),
	HX_CSTRING("TEXTURE_CUBE_MAP"),
	HX_CSTRING("TEXTURE_CUBE_MAP_NEGATIVE_X"),
	HX_CSTRING("TEXTURE_CUBE_MAP_NEGATIVE_Y"),
	HX_CSTRING("TEXTURE_CUBE_MAP_NEGATIVE_Z"),
	HX_CSTRING("TEXTURE_CUBE_MAP_POSITIVE_X"),
	HX_CSTRING("TEXTURE_CUBE_MAP_POSITIVE_Y"),
	HX_CSTRING("TEXTURE_CUBE_MAP_POSITIVE_Z"),
	HX_CSTRING("TEXTURE_MAG_FILTER"),
	HX_CSTRING("TEXTURE_MIN_FILTER"),
	HX_CSTRING("TEXTURE_WRAP_S"),
	HX_CSTRING("TEXTURE_WRAP_T"),
	HX_CSTRING("TRIANGLES"),
	HX_CSTRING("TRIANGLE_FAN"),
	HX_CSTRING("TRIANGLE_STRIP"),
	HX_CSTRING("UNPACK_ALIGNMENT"),
	HX_CSTRING("UNPACK_COLORSPACE_CONVERSION_WEBGL"),
	HX_CSTRING("UNPACK_FLIP_Y_WEBGL"),
	HX_CSTRING("UNPACK_PREMULTIPLY_ALPHA_WEBGL"),
	HX_CSTRING("UNSIGNED_BYTE"),
	HX_CSTRING("UNSIGNED_INT"),
	HX_CSTRING("UNSIGNED_SHORT"),
	HX_CSTRING("UNSIGNED_SHORT_4_4_4_4"),
	HX_CSTRING("UNSIGNED_SHORT_5_5_5_1"),
	HX_CSTRING("UNSIGNED_SHORT_5_6_5"),
	HX_CSTRING("VALIDATE_STATUS"),
	HX_CSTRING("VENDOR"),
	HX_CSTRING("VERSION"),
	HX_CSTRING("VERTEX_ATTRIB_ARRAY_BUFFER_BINDING"),
	HX_CSTRING("VERTEX_ATTRIB_ARRAY_ENABLED"),
	HX_CSTRING("VERTEX_ATTRIB_ARRAY_NORMALIZED"),
	HX_CSTRING("VERTEX_ATTRIB_ARRAY_POINTER"),
	HX_CSTRING("VERTEX_ATTRIB_ARRAY_SIZE"),
	HX_CSTRING("VERTEX_ATTRIB_ARRAY_STRIDE"),
	HX_CSTRING("VERTEX_ATTRIB_ARRAY_TYPE"),
	HX_CSTRING("VERTEX_SHADER"),
	HX_CSTRING("VIEWPORT"),
	HX_CSTRING("ZERO"),
	HX_CSTRING("VERTEX_ARRAY_OBJECT"),
	HX_CSTRING("HALF_FLOAT"),
	HX_CSTRING("TEXTURE_HALF"),
	HX_CSTRING("TEXTURE_HALF_LINEAR"),
	HX_CSTRING("TEXTURE_ANISOTROPY"),
	HX_CSTRING("TEXTURE_ANISOTROPY_ENABLED"),
	HX_CSTRING("MAX_TEXTURE_ANISOTROPY"),
	HX_CSTRING("TEXTURE_FLOAT"),
	HX_CSTRING("TEXTURE_FLOAT_LINEAR"),
	HX_CSTRING("TEXTURE_DEPTH_ENABLED"),
	HX_CSTRING("MAX_ACTIVE_TEXTURE"),
	HX_CSTRING("NULL"),
	HX_CSTRING("INVALID"),
	HX_CSTRING("get_api"),
	HX_CSTRING("m_gl"),
	HX_CSTRING("Initialize"),
	HX_CSTRING("Resize"),
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
	HX_CSTRING("TexStorage2D"),
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
	HX_CSTRING("GetError"),
	HX_CSTRING("GetErrorCode"),
	HX_CSTRING("GetErrorString"),
	HX_CSTRING("LogError"),
	HX_CSTRING("Assert"),
	HX_CSTRING("Flush"),
	HX_CSTRING("Focus"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GL_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(GL_obj::ACTIVE_ATTRIBUTES,"ACTIVE_ATTRIBUTES");
	HX_MARK_MEMBER_NAME(GL_obj::ACTIVE_TEXTURE,"ACTIVE_TEXTURE");
	HX_MARK_MEMBER_NAME(GL_obj::ACTIVE_UNIFORMS,"ACTIVE_UNIFORMS");
	HX_MARK_MEMBER_NAME(GL_obj::ALIASED_LINE_WIDTH_RANGE,"ALIASED_LINE_WIDTH_RANGE");
	HX_MARK_MEMBER_NAME(GL_obj::ALIASED_POINT_SIZE_RANGE,"ALIASED_POINT_SIZE_RANGE");
	HX_MARK_MEMBER_NAME(GL_obj::ALPHA,"ALPHA");
	HX_MARK_MEMBER_NAME(GL_obj::ALPHA_BITS,"ALPHA_BITS");
	HX_MARK_MEMBER_NAME(GL_obj::ALWAYS,"ALWAYS");
	HX_MARK_MEMBER_NAME(GL_obj::ARRAY_BUFFER,"ARRAY_BUFFER");
	HX_MARK_MEMBER_NAME(GL_obj::ARRAY_BUFFER_BINDING,"ARRAY_BUFFER_BINDING");
	HX_MARK_MEMBER_NAME(GL_obj::ATTACHED_SHADERS,"ATTACHED_SHADERS");
	HX_MARK_MEMBER_NAME(GL_obj::BACK,"BACK");
	HX_MARK_MEMBER_NAME(GL_obj::BLEND,"BLEND");
	HX_MARK_MEMBER_NAME(GL_obj::BLEND_COLOR,"BLEND_COLOR");
	HX_MARK_MEMBER_NAME(GL_obj::BLEND_DST_ALPHA,"BLEND_DST_ALPHA");
	HX_MARK_MEMBER_NAME(GL_obj::BLEND_DST_RGB,"BLEND_DST_RGB");
	HX_MARK_MEMBER_NAME(GL_obj::BLEND_EQUATION,"BLEND_EQUATION");
	HX_MARK_MEMBER_NAME(GL_obj::BLEND_EQUATION_ALPHA,"BLEND_EQUATION_ALPHA");
	HX_MARK_MEMBER_NAME(GL_obj::BLEND_EQUATION_RGB,"BLEND_EQUATION_RGB");
	HX_MARK_MEMBER_NAME(GL_obj::BLEND_SRC_ALPHA,"BLEND_SRC_ALPHA");
	HX_MARK_MEMBER_NAME(GL_obj::BLEND_SRC_RGB,"BLEND_SRC_RGB");
	HX_MARK_MEMBER_NAME(GL_obj::BLUE_BITS,"BLUE_BITS");
	HX_MARK_MEMBER_NAME(GL_obj::BOOL,"BOOL");
	HX_MARK_MEMBER_NAME(GL_obj::BOOL_VEC2,"BOOL_VEC2");
	HX_MARK_MEMBER_NAME(GL_obj::BOOL_VEC3,"BOOL_VEC3");
	HX_MARK_MEMBER_NAME(GL_obj::BOOL_VEC4,"BOOL_VEC4");
	HX_MARK_MEMBER_NAME(GL_obj::BROWSER_DEFAULT_WEBGL,"BROWSER_DEFAULT_WEBGL");
	HX_MARK_MEMBER_NAME(GL_obj::BUFFER_SIZE,"BUFFER_SIZE");
	HX_MARK_MEMBER_NAME(GL_obj::BUFFER_USAGE,"BUFFER_USAGE");
	HX_MARK_MEMBER_NAME(GL_obj::BYTE,"BYTE");
	HX_MARK_MEMBER_NAME(GL_obj::CCW,"CCW");
	HX_MARK_MEMBER_NAME(GL_obj::CLAMP_TO_EDGE,"CLAMP_TO_EDGE");
	HX_MARK_MEMBER_NAME(GL_obj::COLOR_ATTACHMENT0,"COLOR_ATTACHMENT0");
	HX_MARK_MEMBER_NAME(GL_obj::COLOR_BUFFER_BIT,"COLOR_BUFFER_BIT");
	HX_MARK_MEMBER_NAME(GL_obj::COLOR_CLEAR_VALUE,"COLOR_CLEAR_VALUE");
	HX_MARK_MEMBER_NAME(GL_obj::COLOR_WRITEMASK,"COLOR_WRITEMASK");
	HX_MARK_MEMBER_NAME(GL_obj::COMPILE_STATUS,"COMPILE_STATUS");
	HX_MARK_MEMBER_NAME(GL_obj::COMPRESSED_TEXTURE_FORMATS,"COMPRESSED_TEXTURE_FORMATS");
	HX_MARK_MEMBER_NAME(GL_obj::CONSTANT_ALPHA,"CONSTANT_ALPHA");
	HX_MARK_MEMBER_NAME(GL_obj::CONSTANT_COLOR,"CONSTANT_COLOR");
	HX_MARK_MEMBER_NAME(GL_obj::CONTEXT_LOST_WEBGL,"CONTEXT_LOST_WEBGL");
	HX_MARK_MEMBER_NAME(GL_obj::CULL_FACE,"CULL_FACE");
	HX_MARK_MEMBER_NAME(GL_obj::CULL_FACE_MODE,"CULL_FACE_MODE");
	HX_MARK_MEMBER_NAME(GL_obj::CURRENT_PROGRAM,"CURRENT_PROGRAM");
	HX_MARK_MEMBER_NAME(GL_obj::CURRENT_VERTEX_ATTRIB,"CURRENT_VERTEX_ATTRIB");
	HX_MARK_MEMBER_NAME(GL_obj::CW,"CW");
	HX_MARK_MEMBER_NAME(GL_obj::DECR,"DECR");
	HX_MARK_MEMBER_NAME(GL_obj::DECR_WRAP,"DECR_WRAP");
	HX_MARK_MEMBER_NAME(GL_obj::DELETE_STATUS,"DELETE_STATUS");
	HX_MARK_MEMBER_NAME(GL_obj::DEPTH_ATTACHMENT,"DEPTH_ATTACHMENT");
	HX_MARK_MEMBER_NAME(GL_obj::DEPTH_BITS,"DEPTH_BITS");
	HX_MARK_MEMBER_NAME(GL_obj::DEPTH_BUFFER_BIT,"DEPTH_BUFFER_BIT");
	HX_MARK_MEMBER_NAME(GL_obj::DEPTH_CLEAR_VALUE,"DEPTH_CLEAR_VALUE");
	HX_MARK_MEMBER_NAME(GL_obj::DEPTH_COMPONENT,"DEPTH_COMPONENT");
	HX_MARK_MEMBER_NAME(GL_obj::DEPTH_COMPONENT16,"DEPTH_COMPONENT16");
	HX_MARK_MEMBER_NAME(GL_obj::DEPTH_FUNC,"DEPTH_FUNC");
	HX_MARK_MEMBER_NAME(GL_obj::DEPTH_RANGE,"DEPTH_RANGE");
	HX_MARK_MEMBER_NAME(GL_obj::DEPTH_STENCIL,"DEPTH_STENCIL");
	HX_MARK_MEMBER_NAME(GL_obj::DEPTH_STENCIL_ATTACHMENT,"DEPTH_STENCIL_ATTACHMENT");
	HX_MARK_MEMBER_NAME(GL_obj::DEPTH_TEST,"DEPTH_TEST");
	HX_MARK_MEMBER_NAME(GL_obj::DEPTH_WRITEMASK,"DEPTH_WRITEMASK");
	HX_MARK_MEMBER_NAME(GL_obj::DITHER,"DITHER");
	HX_MARK_MEMBER_NAME(GL_obj::DONT_CARE,"DONT_CARE");
	HX_MARK_MEMBER_NAME(GL_obj::DST_ALPHA,"DST_ALPHA");
	HX_MARK_MEMBER_NAME(GL_obj::DST_COLOR,"DST_COLOR");
	HX_MARK_MEMBER_NAME(GL_obj::DYNAMIC_DRAW,"DYNAMIC_DRAW");
	HX_MARK_MEMBER_NAME(GL_obj::ELEMENT_ARRAY_BUFFER,"ELEMENT_ARRAY_BUFFER");
	HX_MARK_MEMBER_NAME(GL_obj::ELEMENT_ARRAY_BUFFER_BINDING,"ELEMENT_ARRAY_BUFFER_BINDING");
	HX_MARK_MEMBER_NAME(GL_obj::EQUAL,"EQUAL");
	HX_MARK_MEMBER_NAME(GL_obj::FASTEST,"FASTEST");
	HX_MARK_MEMBER_NAME(GL_obj::FLOAT,"FLOAT");
	HX_MARK_MEMBER_NAME(GL_obj::FLOAT_MAT2,"FLOAT_MAT2");
	HX_MARK_MEMBER_NAME(GL_obj::FLOAT_MAT3,"FLOAT_MAT3");
	HX_MARK_MEMBER_NAME(GL_obj::FLOAT_MAT4,"FLOAT_MAT4");
	HX_MARK_MEMBER_NAME(GL_obj::FLOAT_VEC2,"FLOAT_VEC2");
	HX_MARK_MEMBER_NAME(GL_obj::FLOAT_VEC3,"FLOAT_VEC3");
	HX_MARK_MEMBER_NAME(GL_obj::FLOAT_VEC4,"FLOAT_VEC4");
	HX_MARK_MEMBER_NAME(GL_obj::FRAGMENT_SHADER,"FRAGMENT_SHADER");
	HX_MARK_MEMBER_NAME(GL_obj::FRAMEBUFFER,"FRAMEBUFFER");
	HX_MARK_MEMBER_NAME(GL_obj::FRAMEBUFFER_ATTACHMENT_OBJECT_NAME,"FRAMEBUFFER_ATTACHMENT_OBJECT_NAME");
	HX_MARK_MEMBER_NAME(GL_obj::FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE,"FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE");
	HX_MARK_MEMBER_NAME(GL_obj::FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE,"FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE");
	HX_MARK_MEMBER_NAME(GL_obj::FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL,"FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL");
	HX_MARK_MEMBER_NAME(GL_obj::FRAMEBUFFER_BINDING,"FRAMEBUFFER_BINDING");
	HX_MARK_MEMBER_NAME(GL_obj::FRAMEBUFFER_COMPLETE,"FRAMEBUFFER_COMPLETE");
	HX_MARK_MEMBER_NAME(GL_obj::FRAMEBUFFER_INCOMPLETE_ATTACHMENT,"FRAMEBUFFER_INCOMPLETE_ATTACHMENT");
	HX_MARK_MEMBER_NAME(GL_obj::FRAMEBUFFER_INCOMPLETE_DIMENSIONS,"FRAMEBUFFER_INCOMPLETE_DIMENSIONS");
	HX_MARK_MEMBER_NAME(GL_obj::FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,"FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT");
	HX_MARK_MEMBER_NAME(GL_obj::FRAMEBUFFER_UNSUPPORTED,"FRAMEBUFFER_UNSUPPORTED");
	HX_MARK_MEMBER_NAME(GL_obj::FRONT,"FRONT");
	HX_MARK_MEMBER_NAME(GL_obj::FRONT_AND_BACK,"FRONT_AND_BACK");
	HX_MARK_MEMBER_NAME(GL_obj::FRONT_FACE,"FRONT_FACE");
	HX_MARK_MEMBER_NAME(GL_obj::FUNC_ADD,"FUNC_ADD");
	HX_MARK_MEMBER_NAME(GL_obj::FUNC_REVERSE_SUBTRACT,"FUNC_REVERSE_SUBTRACT");
	HX_MARK_MEMBER_NAME(GL_obj::FUNC_SUBTRACT,"FUNC_SUBTRACT");
	HX_MARK_MEMBER_NAME(GL_obj::GENERATE_MIPMAP_HINT,"GENERATE_MIPMAP_HINT");
	HX_MARK_MEMBER_NAME(GL_obj::GEQUAL,"GEQUAL");
	HX_MARK_MEMBER_NAME(GL_obj::GREATER,"GREATER");
	HX_MARK_MEMBER_NAME(GL_obj::GREEN_BITS,"GREEN_BITS");
	HX_MARK_MEMBER_NAME(GL_obj::HIGH_FLOAT,"HIGH_FLOAT");
	HX_MARK_MEMBER_NAME(GL_obj::HIGH_INT,"HIGH_INT");
	HX_MARK_MEMBER_NAME(GL_obj::INCR,"INCR");
	HX_MARK_MEMBER_NAME(GL_obj::INCR_WRAP,"INCR_WRAP");
	HX_MARK_MEMBER_NAME(GL_obj::INT,"INT");
	HX_MARK_MEMBER_NAME(GL_obj::INT_VEC2,"INT_VEC2");
	HX_MARK_MEMBER_NAME(GL_obj::INT_VEC3,"INT_VEC3");
	HX_MARK_MEMBER_NAME(GL_obj::INT_VEC4,"INT_VEC4");
	HX_MARK_MEMBER_NAME(GL_obj::INVALID_ENUM,"INVALID_ENUM");
	HX_MARK_MEMBER_NAME(GL_obj::INVALID_FRAMEBUFFER_OPERATION,"INVALID_FRAMEBUFFER_OPERATION");
	HX_MARK_MEMBER_NAME(GL_obj::INVALID_OPERATION,"INVALID_OPERATION");
	HX_MARK_MEMBER_NAME(GL_obj::INVALID_VALUE,"INVALID_VALUE");
	HX_MARK_MEMBER_NAME(GL_obj::INVERT,"INVERT");
	HX_MARK_MEMBER_NAME(GL_obj::KEEP,"KEEP");
	HX_MARK_MEMBER_NAME(GL_obj::LEQUAL,"LEQUAL");
	HX_MARK_MEMBER_NAME(GL_obj::LESS,"LESS");
	HX_MARK_MEMBER_NAME(GL_obj::LINEAR,"LINEAR");
	HX_MARK_MEMBER_NAME(GL_obj::LINEAR_MIPMAP_LINEAR,"LINEAR_MIPMAP_LINEAR");
	HX_MARK_MEMBER_NAME(GL_obj::LINEAR_MIPMAP_NEAREST,"LINEAR_MIPMAP_NEAREST");
	HX_MARK_MEMBER_NAME(GL_obj::LINES,"LINES");
	HX_MARK_MEMBER_NAME(GL_obj::LINE_LOOP,"LINE_LOOP");
	HX_MARK_MEMBER_NAME(GL_obj::LINE_STRIP,"LINE_STRIP");
	HX_MARK_MEMBER_NAME(GL_obj::LINE_WIDTH,"LINE_WIDTH");
	HX_MARK_MEMBER_NAME(GL_obj::LINK_STATUS,"LINK_STATUS");
	HX_MARK_MEMBER_NAME(GL_obj::LOW_FLOAT,"LOW_FLOAT");
	HX_MARK_MEMBER_NAME(GL_obj::LOW_INT,"LOW_INT");
	HX_MARK_MEMBER_NAME(GL_obj::LUMINANCE,"LUMINANCE");
	HX_MARK_MEMBER_NAME(GL_obj::LUMINANCE_ALPHA,"LUMINANCE_ALPHA");
	HX_MARK_MEMBER_NAME(GL_obj::MAX_COMBINED_TEXTURE_IMAGE_UNITS,"MAX_COMBINED_TEXTURE_IMAGE_UNITS");
	HX_MARK_MEMBER_NAME(GL_obj::MAX_CUBE_MAP_TEXTURE_SIZE,"MAX_CUBE_MAP_TEXTURE_SIZE");
	HX_MARK_MEMBER_NAME(GL_obj::MAX_FRAGMENT_UNIFORM_VECTORS,"MAX_FRAGMENT_UNIFORM_VECTORS");
	HX_MARK_MEMBER_NAME(GL_obj::MAX_RENDERBUFFER_SIZE,"MAX_RENDERBUFFER_SIZE");
	HX_MARK_MEMBER_NAME(GL_obj::MAX_TEXTURE_IMAGE_UNITS,"MAX_TEXTURE_IMAGE_UNITS");
	HX_MARK_MEMBER_NAME(GL_obj::MAX_TEXTURE_SIZE,"MAX_TEXTURE_SIZE");
	HX_MARK_MEMBER_NAME(GL_obj::MAX_VARYING_VECTORS,"MAX_VARYING_VECTORS");
	HX_MARK_MEMBER_NAME(GL_obj::MAX_VERTEX_ATTRIBS,"MAX_VERTEX_ATTRIBS");
	HX_MARK_MEMBER_NAME(GL_obj::MAX_VERTEX_TEXTURE_IMAGE_UNITS,"MAX_VERTEX_TEXTURE_IMAGE_UNITS");
	HX_MARK_MEMBER_NAME(GL_obj::MAX_VERTEX_UNIFORM_VECTORS,"MAX_VERTEX_UNIFORM_VECTORS");
	HX_MARK_MEMBER_NAME(GL_obj::MAX_VIEWPORT_DIMS,"MAX_VIEWPORT_DIMS");
	HX_MARK_MEMBER_NAME(GL_obj::MEDIUM_FLOAT,"MEDIUM_FLOAT");
	HX_MARK_MEMBER_NAME(GL_obj::MEDIUM_INT,"MEDIUM_INT");
	HX_MARK_MEMBER_NAME(GL_obj::MIRRORED_REPEAT,"MIRRORED_REPEAT");
	HX_MARK_MEMBER_NAME(GL_obj::NEAREST,"NEAREST");
	HX_MARK_MEMBER_NAME(GL_obj::NEAREST_MIPMAP_LINEAR,"NEAREST_MIPMAP_LINEAR");
	HX_MARK_MEMBER_NAME(GL_obj::NEAREST_MIPMAP_NEAREST,"NEAREST_MIPMAP_NEAREST");
	HX_MARK_MEMBER_NAME(GL_obj::NEVER,"NEVER");
	HX_MARK_MEMBER_NAME(GL_obj::NICEST,"NICEST");
	HX_MARK_MEMBER_NAME(GL_obj::NONE,"NONE");
	HX_MARK_MEMBER_NAME(GL_obj::NOTEQUAL,"NOTEQUAL");
	HX_MARK_MEMBER_NAME(GL_obj::NO_ERROR_GL,"NO_ERROR_GL");
	HX_MARK_MEMBER_NAME(GL_obj::ONE,"ONE");
	HX_MARK_MEMBER_NAME(GL_obj::ONE_MINUS_CONSTANT_ALPHA,"ONE_MINUS_CONSTANT_ALPHA");
	HX_MARK_MEMBER_NAME(GL_obj::ONE_MINUS_CONSTANT_COLOR,"ONE_MINUS_CONSTANT_COLOR");
	HX_MARK_MEMBER_NAME(GL_obj::ONE_MINUS_DST_ALPHA,"ONE_MINUS_DST_ALPHA");
	HX_MARK_MEMBER_NAME(GL_obj::ONE_MINUS_DST_COLOR,"ONE_MINUS_DST_COLOR");
	HX_MARK_MEMBER_NAME(GL_obj::ONE_MINUS_SRC_ALPHA,"ONE_MINUS_SRC_ALPHA");
	HX_MARK_MEMBER_NAME(GL_obj::ONE_MINUS_SRC_COLOR,"ONE_MINUS_SRC_COLOR");
	HX_MARK_MEMBER_NAME(GL_obj::OUT_OF_MEMORY,"OUT_OF_MEMORY");
	HX_MARK_MEMBER_NAME(GL_obj::PACK_ALIGNMENT,"PACK_ALIGNMENT");
	HX_MARK_MEMBER_NAME(GL_obj::POINTS,"POINTS");
	HX_MARK_MEMBER_NAME(GL_obj::POLYGON_OFFSET_FACTOR,"POLYGON_OFFSET_FACTOR");
	HX_MARK_MEMBER_NAME(GL_obj::POLYGON_OFFSET_FILL,"POLYGON_OFFSET_FILL");
	HX_MARK_MEMBER_NAME(GL_obj::POLYGON_OFFSET_UNITS,"POLYGON_OFFSET_UNITS");
	HX_MARK_MEMBER_NAME(GL_obj::RED_BITS,"RED_BITS");
	HX_MARK_MEMBER_NAME(GL_obj::RENDERBUFFER,"RENDERBUFFER");
	HX_MARK_MEMBER_NAME(GL_obj::RENDERBUFFER_ALPHA_SIZE,"RENDERBUFFER_ALPHA_SIZE");
	HX_MARK_MEMBER_NAME(GL_obj::RENDERBUFFER_BINDING,"RENDERBUFFER_BINDING");
	HX_MARK_MEMBER_NAME(GL_obj::RENDERBUFFER_BLUE_SIZE,"RENDERBUFFER_BLUE_SIZE");
	HX_MARK_MEMBER_NAME(GL_obj::RENDERBUFFER_DEPTH_SIZE,"RENDERBUFFER_DEPTH_SIZE");
	HX_MARK_MEMBER_NAME(GL_obj::RENDERBUFFER_GREEN_SIZE,"RENDERBUFFER_GREEN_SIZE");
	HX_MARK_MEMBER_NAME(GL_obj::RENDERBUFFER_HEIGHT,"RENDERBUFFER_HEIGHT");
	HX_MARK_MEMBER_NAME(GL_obj::RENDERBUFFER_INTERNAL_FORMAT,"RENDERBUFFER_INTERNAL_FORMAT");
	HX_MARK_MEMBER_NAME(GL_obj::RENDERBUFFER_RED_SIZE,"RENDERBUFFER_RED_SIZE");
	HX_MARK_MEMBER_NAME(GL_obj::RENDERBUFFER_STENCIL_SIZE,"RENDERBUFFER_STENCIL_SIZE");
	HX_MARK_MEMBER_NAME(GL_obj::RENDERBUFFER_WIDTH,"RENDERBUFFER_WIDTH");
	HX_MARK_MEMBER_NAME(GL_obj::RENDERER,"RENDERER");
	HX_MARK_MEMBER_NAME(GL_obj::REPEAT,"REPEAT");
	HX_MARK_MEMBER_NAME(GL_obj::REPLACE,"REPLACE");
	HX_MARK_MEMBER_NAME(GL_obj::RGB,"RGB");
	HX_MARK_MEMBER_NAME(GL_obj::RGB565,"RGB565");
	HX_MARK_MEMBER_NAME(GL_obj::RGB5_A1,"RGB5_A1");
	HX_MARK_MEMBER_NAME(GL_obj::RGBA,"RGBA");
	HX_MARK_MEMBER_NAME(GL_obj::RGBA4,"RGBA4");
	HX_MARK_MEMBER_NAME(GL_obj::SAMPLER_2D,"SAMPLER_2D");
	HX_MARK_MEMBER_NAME(GL_obj::SAMPLER_CUBE,"SAMPLER_CUBE");
	HX_MARK_MEMBER_NAME(GL_obj::SAMPLES,"SAMPLES");
	HX_MARK_MEMBER_NAME(GL_obj::SAMPLE_ALPHA_TO_COVERAGE,"SAMPLE_ALPHA_TO_COVERAGE");
	HX_MARK_MEMBER_NAME(GL_obj::SAMPLE_BUFFERS,"SAMPLE_BUFFERS");
	HX_MARK_MEMBER_NAME(GL_obj::SAMPLE_COVERAGE,"SAMPLE_COVERAGE");
	HX_MARK_MEMBER_NAME(GL_obj::SAMPLE_COVERAGE_INVERT,"SAMPLE_COVERAGE_INVERT");
	HX_MARK_MEMBER_NAME(GL_obj::SAMPLE_COVERAGE_VALUE,"SAMPLE_COVERAGE_VALUE");
	HX_MARK_MEMBER_NAME(GL_obj::SCISSOR_BOX,"SCISSOR_BOX");
	HX_MARK_MEMBER_NAME(GL_obj::SCISSOR_TEST,"SCISSOR_TEST");
	HX_MARK_MEMBER_NAME(GL_obj::SHADER_TYPE,"SHADER_TYPE");
	HX_MARK_MEMBER_NAME(GL_obj::SHADING_LANGUAGE_VERSION,"SHADING_LANGUAGE_VERSION");
	HX_MARK_MEMBER_NAME(GL_obj::SHORT,"SHORT");
	HX_MARK_MEMBER_NAME(GL_obj::SRC_ALPHA,"SRC_ALPHA");
	HX_MARK_MEMBER_NAME(GL_obj::SRC_ALPHA_SATURATE,"SRC_ALPHA_SATURATE");
	HX_MARK_MEMBER_NAME(GL_obj::SRC_COLOR,"SRC_COLOR");
	HX_MARK_MEMBER_NAME(GL_obj::STATIC_DRAW,"STATIC_DRAW");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_ATTACHMENT,"STENCIL_ATTACHMENT");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_BACK_FAIL,"STENCIL_BACK_FAIL");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_BACK_FUNC,"STENCIL_BACK_FUNC");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_BACK_PASS_DEPTH_FAIL,"STENCIL_BACK_PASS_DEPTH_FAIL");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_BACK_PASS_DEPTH_PASS,"STENCIL_BACK_PASS_DEPTH_PASS");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_BACK_REF,"STENCIL_BACK_REF");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_BACK_VALUE_MASK,"STENCIL_BACK_VALUE_MASK");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_BACK_WRITEMASK,"STENCIL_BACK_WRITEMASK");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_BITS,"STENCIL_BITS");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_BUFFER_BIT,"STENCIL_BUFFER_BIT");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_CLEAR_VALUE,"STENCIL_CLEAR_VALUE");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_FAIL,"STENCIL_FAIL");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_FUNC,"STENCIL_FUNC");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_INDEX,"STENCIL_INDEX");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_INDEX8,"STENCIL_INDEX8");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_PASS_DEPTH_FAIL,"STENCIL_PASS_DEPTH_FAIL");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_PASS_DEPTH_PASS,"STENCIL_PASS_DEPTH_PASS");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_REF,"STENCIL_REF");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_TEST,"STENCIL_TEST");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_VALUE_MASK,"STENCIL_VALUE_MASK");
	HX_MARK_MEMBER_NAME(GL_obj::STENCIL_WRITEMASK,"STENCIL_WRITEMASK");
	HX_MARK_MEMBER_NAME(GL_obj::STREAM_DRAW,"STREAM_DRAW");
	HX_MARK_MEMBER_NAME(GL_obj::SUBPIXEL_BITS,"SUBPIXEL_BITS");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE,"TEXTURE");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE0,"TEXTURE0");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE1,"TEXTURE1");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE10,"TEXTURE10");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE11,"TEXTURE11");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE12,"TEXTURE12");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE13,"TEXTURE13");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE14,"TEXTURE14");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE15,"TEXTURE15");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE16,"TEXTURE16");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE17,"TEXTURE17");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE18,"TEXTURE18");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE19,"TEXTURE19");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE2,"TEXTURE2");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE20,"TEXTURE20");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE21,"TEXTURE21");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE22,"TEXTURE22");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE23,"TEXTURE23");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE24,"TEXTURE24");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE25,"TEXTURE25");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE26,"TEXTURE26");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE27,"TEXTURE27");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE28,"TEXTURE28");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE29,"TEXTURE29");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE3,"TEXTURE3");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE30,"TEXTURE30");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE31,"TEXTURE31");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE4,"TEXTURE4");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE5,"TEXTURE5");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE6,"TEXTURE6");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE7,"TEXTURE7");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE8,"TEXTURE8");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE9,"TEXTURE9");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_2D,"TEXTURE_2D");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_BINDING_2D,"TEXTURE_BINDING_2D");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_BINDING_CUBE_MAP,"TEXTURE_BINDING_CUBE_MAP");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP,"TEXTURE_CUBE_MAP");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP_NEGATIVE_X,"TEXTURE_CUBE_MAP_NEGATIVE_X");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP_NEGATIVE_Y,"TEXTURE_CUBE_MAP_NEGATIVE_Y");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP_NEGATIVE_Z,"TEXTURE_CUBE_MAP_NEGATIVE_Z");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP_POSITIVE_X,"TEXTURE_CUBE_MAP_POSITIVE_X");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP_POSITIVE_Y,"TEXTURE_CUBE_MAP_POSITIVE_Y");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP_POSITIVE_Z,"TEXTURE_CUBE_MAP_POSITIVE_Z");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_MAG_FILTER,"TEXTURE_MAG_FILTER");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_MIN_FILTER,"TEXTURE_MIN_FILTER");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_WRAP_S,"TEXTURE_WRAP_S");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_WRAP_T,"TEXTURE_WRAP_T");
	HX_MARK_MEMBER_NAME(GL_obj::TRIANGLES,"TRIANGLES");
	HX_MARK_MEMBER_NAME(GL_obj::TRIANGLE_FAN,"TRIANGLE_FAN");
	HX_MARK_MEMBER_NAME(GL_obj::TRIANGLE_STRIP,"TRIANGLE_STRIP");
	HX_MARK_MEMBER_NAME(GL_obj::UNPACK_ALIGNMENT,"UNPACK_ALIGNMENT");
	HX_MARK_MEMBER_NAME(GL_obj::UNPACK_COLORSPACE_CONVERSION_WEBGL,"UNPACK_COLORSPACE_CONVERSION_WEBGL");
	HX_MARK_MEMBER_NAME(GL_obj::UNPACK_FLIP_Y_WEBGL,"UNPACK_FLIP_Y_WEBGL");
	HX_MARK_MEMBER_NAME(GL_obj::UNPACK_PREMULTIPLY_ALPHA_WEBGL,"UNPACK_PREMULTIPLY_ALPHA_WEBGL");
	HX_MARK_MEMBER_NAME(GL_obj::UNSIGNED_BYTE,"UNSIGNED_BYTE");
	HX_MARK_MEMBER_NAME(GL_obj::UNSIGNED_INT,"UNSIGNED_INT");
	HX_MARK_MEMBER_NAME(GL_obj::UNSIGNED_SHORT,"UNSIGNED_SHORT");
	HX_MARK_MEMBER_NAME(GL_obj::UNSIGNED_SHORT_4_4_4_4,"UNSIGNED_SHORT_4_4_4_4");
	HX_MARK_MEMBER_NAME(GL_obj::UNSIGNED_SHORT_5_5_5_1,"UNSIGNED_SHORT_5_5_5_1");
	HX_MARK_MEMBER_NAME(GL_obj::UNSIGNED_SHORT_5_6_5,"UNSIGNED_SHORT_5_6_5");
	HX_MARK_MEMBER_NAME(GL_obj::VALIDATE_STATUS,"VALIDATE_STATUS");
	HX_MARK_MEMBER_NAME(GL_obj::VENDOR,"VENDOR");
	HX_MARK_MEMBER_NAME(GL_obj::VERSION,"VERSION");
	HX_MARK_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_BUFFER_BINDING,"VERTEX_ATTRIB_ARRAY_BUFFER_BINDING");
	HX_MARK_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_ENABLED,"VERTEX_ATTRIB_ARRAY_ENABLED");
	HX_MARK_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_NORMALIZED,"VERTEX_ATTRIB_ARRAY_NORMALIZED");
	HX_MARK_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_POINTER,"VERTEX_ATTRIB_ARRAY_POINTER");
	HX_MARK_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_SIZE,"VERTEX_ATTRIB_ARRAY_SIZE");
	HX_MARK_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_STRIDE,"VERTEX_ATTRIB_ARRAY_STRIDE");
	HX_MARK_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_TYPE,"VERTEX_ATTRIB_ARRAY_TYPE");
	HX_MARK_MEMBER_NAME(GL_obj::VERTEX_SHADER,"VERTEX_SHADER");
	HX_MARK_MEMBER_NAME(GL_obj::VIEWPORT,"VIEWPORT");
	HX_MARK_MEMBER_NAME(GL_obj::ZERO,"ZERO");
	HX_MARK_MEMBER_NAME(GL_obj::VERTEX_ARRAY_OBJECT,"VERTEX_ARRAY_OBJECT");
	HX_MARK_MEMBER_NAME(GL_obj::HALF_FLOAT,"HALF_FLOAT");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_HALF,"TEXTURE_HALF");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_HALF_LINEAR,"TEXTURE_HALF_LINEAR");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_ANISOTROPY,"TEXTURE_ANISOTROPY");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_ANISOTROPY_ENABLED,"TEXTURE_ANISOTROPY_ENABLED");
	HX_MARK_MEMBER_NAME(GL_obj::MAX_TEXTURE_ANISOTROPY,"MAX_TEXTURE_ANISOTROPY");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_FLOAT,"TEXTURE_FLOAT");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_FLOAT_LINEAR,"TEXTURE_FLOAT_LINEAR");
	HX_MARK_MEMBER_NAME(GL_obj::TEXTURE_DEPTH_ENABLED,"TEXTURE_DEPTH_ENABLED");
	HX_MARK_MEMBER_NAME(GL_obj::MAX_ACTIVE_TEXTURE,"MAX_ACTIVE_TEXTURE");
	HX_MARK_MEMBER_NAME(GL_obj::_NULL,"NULL");
	HX_MARK_MEMBER_NAME(GL_obj::INVALID,"INVALID");
	HX_MARK_MEMBER_NAME(GL_obj::m_gl,"m_gl");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GL_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(GL_obj::ACTIVE_ATTRIBUTES,"ACTIVE_ATTRIBUTES");
	HX_VISIT_MEMBER_NAME(GL_obj::ACTIVE_TEXTURE,"ACTIVE_TEXTURE");
	HX_VISIT_MEMBER_NAME(GL_obj::ACTIVE_UNIFORMS,"ACTIVE_UNIFORMS");
	HX_VISIT_MEMBER_NAME(GL_obj::ALIASED_LINE_WIDTH_RANGE,"ALIASED_LINE_WIDTH_RANGE");
	HX_VISIT_MEMBER_NAME(GL_obj::ALIASED_POINT_SIZE_RANGE,"ALIASED_POINT_SIZE_RANGE");
	HX_VISIT_MEMBER_NAME(GL_obj::ALPHA,"ALPHA");
	HX_VISIT_MEMBER_NAME(GL_obj::ALPHA_BITS,"ALPHA_BITS");
	HX_VISIT_MEMBER_NAME(GL_obj::ALWAYS,"ALWAYS");
	HX_VISIT_MEMBER_NAME(GL_obj::ARRAY_BUFFER,"ARRAY_BUFFER");
	HX_VISIT_MEMBER_NAME(GL_obj::ARRAY_BUFFER_BINDING,"ARRAY_BUFFER_BINDING");
	HX_VISIT_MEMBER_NAME(GL_obj::ATTACHED_SHADERS,"ATTACHED_SHADERS");
	HX_VISIT_MEMBER_NAME(GL_obj::BACK,"BACK");
	HX_VISIT_MEMBER_NAME(GL_obj::BLEND,"BLEND");
	HX_VISIT_MEMBER_NAME(GL_obj::BLEND_COLOR,"BLEND_COLOR");
	HX_VISIT_MEMBER_NAME(GL_obj::BLEND_DST_ALPHA,"BLEND_DST_ALPHA");
	HX_VISIT_MEMBER_NAME(GL_obj::BLEND_DST_RGB,"BLEND_DST_RGB");
	HX_VISIT_MEMBER_NAME(GL_obj::BLEND_EQUATION,"BLEND_EQUATION");
	HX_VISIT_MEMBER_NAME(GL_obj::BLEND_EQUATION_ALPHA,"BLEND_EQUATION_ALPHA");
	HX_VISIT_MEMBER_NAME(GL_obj::BLEND_EQUATION_RGB,"BLEND_EQUATION_RGB");
	HX_VISIT_MEMBER_NAME(GL_obj::BLEND_SRC_ALPHA,"BLEND_SRC_ALPHA");
	HX_VISIT_MEMBER_NAME(GL_obj::BLEND_SRC_RGB,"BLEND_SRC_RGB");
	HX_VISIT_MEMBER_NAME(GL_obj::BLUE_BITS,"BLUE_BITS");
	HX_VISIT_MEMBER_NAME(GL_obj::BOOL,"BOOL");
	HX_VISIT_MEMBER_NAME(GL_obj::BOOL_VEC2,"BOOL_VEC2");
	HX_VISIT_MEMBER_NAME(GL_obj::BOOL_VEC3,"BOOL_VEC3");
	HX_VISIT_MEMBER_NAME(GL_obj::BOOL_VEC4,"BOOL_VEC4");
	HX_VISIT_MEMBER_NAME(GL_obj::BROWSER_DEFAULT_WEBGL,"BROWSER_DEFAULT_WEBGL");
	HX_VISIT_MEMBER_NAME(GL_obj::BUFFER_SIZE,"BUFFER_SIZE");
	HX_VISIT_MEMBER_NAME(GL_obj::BUFFER_USAGE,"BUFFER_USAGE");
	HX_VISIT_MEMBER_NAME(GL_obj::BYTE,"BYTE");
	HX_VISIT_MEMBER_NAME(GL_obj::CCW,"CCW");
	HX_VISIT_MEMBER_NAME(GL_obj::CLAMP_TO_EDGE,"CLAMP_TO_EDGE");
	HX_VISIT_MEMBER_NAME(GL_obj::COLOR_ATTACHMENT0,"COLOR_ATTACHMENT0");
	HX_VISIT_MEMBER_NAME(GL_obj::COLOR_BUFFER_BIT,"COLOR_BUFFER_BIT");
	HX_VISIT_MEMBER_NAME(GL_obj::COLOR_CLEAR_VALUE,"COLOR_CLEAR_VALUE");
	HX_VISIT_MEMBER_NAME(GL_obj::COLOR_WRITEMASK,"COLOR_WRITEMASK");
	HX_VISIT_MEMBER_NAME(GL_obj::COMPILE_STATUS,"COMPILE_STATUS");
	HX_VISIT_MEMBER_NAME(GL_obj::COMPRESSED_TEXTURE_FORMATS,"COMPRESSED_TEXTURE_FORMATS");
	HX_VISIT_MEMBER_NAME(GL_obj::CONSTANT_ALPHA,"CONSTANT_ALPHA");
	HX_VISIT_MEMBER_NAME(GL_obj::CONSTANT_COLOR,"CONSTANT_COLOR");
	HX_VISIT_MEMBER_NAME(GL_obj::CONTEXT_LOST_WEBGL,"CONTEXT_LOST_WEBGL");
	HX_VISIT_MEMBER_NAME(GL_obj::CULL_FACE,"CULL_FACE");
	HX_VISIT_MEMBER_NAME(GL_obj::CULL_FACE_MODE,"CULL_FACE_MODE");
	HX_VISIT_MEMBER_NAME(GL_obj::CURRENT_PROGRAM,"CURRENT_PROGRAM");
	HX_VISIT_MEMBER_NAME(GL_obj::CURRENT_VERTEX_ATTRIB,"CURRENT_VERTEX_ATTRIB");
	HX_VISIT_MEMBER_NAME(GL_obj::CW,"CW");
	HX_VISIT_MEMBER_NAME(GL_obj::DECR,"DECR");
	HX_VISIT_MEMBER_NAME(GL_obj::DECR_WRAP,"DECR_WRAP");
	HX_VISIT_MEMBER_NAME(GL_obj::DELETE_STATUS,"DELETE_STATUS");
	HX_VISIT_MEMBER_NAME(GL_obj::DEPTH_ATTACHMENT,"DEPTH_ATTACHMENT");
	HX_VISIT_MEMBER_NAME(GL_obj::DEPTH_BITS,"DEPTH_BITS");
	HX_VISIT_MEMBER_NAME(GL_obj::DEPTH_BUFFER_BIT,"DEPTH_BUFFER_BIT");
	HX_VISIT_MEMBER_NAME(GL_obj::DEPTH_CLEAR_VALUE,"DEPTH_CLEAR_VALUE");
	HX_VISIT_MEMBER_NAME(GL_obj::DEPTH_COMPONENT,"DEPTH_COMPONENT");
	HX_VISIT_MEMBER_NAME(GL_obj::DEPTH_COMPONENT16,"DEPTH_COMPONENT16");
	HX_VISIT_MEMBER_NAME(GL_obj::DEPTH_FUNC,"DEPTH_FUNC");
	HX_VISIT_MEMBER_NAME(GL_obj::DEPTH_RANGE,"DEPTH_RANGE");
	HX_VISIT_MEMBER_NAME(GL_obj::DEPTH_STENCIL,"DEPTH_STENCIL");
	HX_VISIT_MEMBER_NAME(GL_obj::DEPTH_STENCIL_ATTACHMENT,"DEPTH_STENCIL_ATTACHMENT");
	HX_VISIT_MEMBER_NAME(GL_obj::DEPTH_TEST,"DEPTH_TEST");
	HX_VISIT_MEMBER_NAME(GL_obj::DEPTH_WRITEMASK,"DEPTH_WRITEMASK");
	HX_VISIT_MEMBER_NAME(GL_obj::DITHER,"DITHER");
	HX_VISIT_MEMBER_NAME(GL_obj::DONT_CARE,"DONT_CARE");
	HX_VISIT_MEMBER_NAME(GL_obj::DST_ALPHA,"DST_ALPHA");
	HX_VISIT_MEMBER_NAME(GL_obj::DST_COLOR,"DST_COLOR");
	HX_VISIT_MEMBER_NAME(GL_obj::DYNAMIC_DRAW,"DYNAMIC_DRAW");
	HX_VISIT_MEMBER_NAME(GL_obj::ELEMENT_ARRAY_BUFFER,"ELEMENT_ARRAY_BUFFER");
	HX_VISIT_MEMBER_NAME(GL_obj::ELEMENT_ARRAY_BUFFER_BINDING,"ELEMENT_ARRAY_BUFFER_BINDING");
	HX_VISIT_MEMBER_NAME(GL_obj::EQUAL,"EQUAL");
	HX_VISIT_MEMBER_NAME(GL_obj::FASTEST,"FASTEST");
	HX_VISIT_MEMBER_NAME(GL_obj::FLOAT,"FLOAT");
	HX_VISIT_MEMBER_NAME(GL_obj::FLOAT_MAT2,"FLOAT_MAT2");
	HX_VISIT_MEMBER_NAME(GL_obj::FLOAT_MAT3,"FLOAT_MAT3");
	HX_VISIT_MEMBER_NAME(GL_obj::FLOAT_MAT4,"FLOAT_MAT4");
	HX_VISIT_MEMBER_NAME(GL_obj::FLOAT_VEC2,"FLOAT_VEC2");
	HX_VISIT_MEMBER_NAME(GL_obj::FLOAT_VEC3,"FLOAT_VEC3");
	HX_VISIT_MEMBER_NAME(GL_obj::FLOAT_VEC4,"FLOAT_VEC4");
	HX_VISIT_MEMBER_NAME(GL_obj::FRAGMENT_SHADER,"FRAGMENT_SHADER");
	HX_VISIT_MEMBER_NAME(GL_obj::FRAMEBUFFER,"FRAMEBUFFER");
	HX_VISIT_MEMBER_NAME(GL_obj::FRAMEBUFFER_ATTACHMENT_OBJECT_NAME,"FRAMEBUFFER_ATTACHMENT_OBJECT_NAME");
	HX_VISIT_MEMBER_NAME(GL_obj::FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE,"FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE");
	HX_VISIT_MEMBER_NAME(GL_obj::FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE,"FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE");
	HX_VISIT_MEMBER_NAME(GL_obj::FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL,"FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL");
	HX_VISIT_MEMBER_NAME(GL_obj::FRAMEBUFFER_BINDING,"FRAMEBUFFER_BINDING");
	HX_VISIT_MEMBER_NAME(GL_obj::FRAMEBUFFER_COMPLETE,"FRAMEBUFFER_COMPLETE");
	HX_VISIT_MEMBER_NAME(GL_obj::FRAMEBUFFER_INCOMPLETE_ATTACHMENT,"FRAMEBUFFER_INCOMPLETE_ATTACHMENT");
	HX_VISIT_MEMBER_NAME(GL_obj::FRAMEBUFFER_INCOMPLETE_DIMENSIONS,"FRAMEBUFFER_INCOMPLETE_DIMENSIONS");
	HX_VISIT_MEMBER_NAME(GL_obj::FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT,"FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT");
	HX_VISIT_MEMBER_NAME(GL_obj::FRAMEBUFFER_UNSUPPORTED,"FRAMEBUFFER_UNSUPPORTED");
	HX_VISIT_MEMBER_NAME(GL_obj::FRONT,"FRONT");
	HX_VISIT_MEMBER_NAME(GL_obj::FRONT_AND_BACK,"FRONT_AND_BACK");
	HX_VISIT_MEMBER_NAME(GL_obj::FRONT_FACE,"FRONT_FACE");
	HX_VISIT_MEMBER_NAME(GL_obj::FUNC_ADD,"FUNC_ADD");
	HX_VISIT_MEMBER_NAME(GL_obj::FUNC_REVERSE_SUBTRACT,"FUNC_REVERSE_SUBTRACT");
	HX_VISIT_MEMBER_NAME(GL_obj::FUNC_SUBTRACT,"FUNC_SUBTRACT");
	HX_VISIT_MEMBER_NAME(GL_obj::GENERATE_MIPMAP_HINT,"GENERATE_MIPMAP_HINT");
	HX_VISIT_MEMBER_NAME(GL_obj::GEQUAL,"GEQUAL");
	HX_VISIT_MEMBER_NAME(GL_obj::GREATER,"GREATER");
	HX_VISIT_MEMBER_NAME(GL_obj::GREEN_BITS,"GREEN_BITS");
	HX_VISIT_MEMBER_NAME(GL_obj::HIGH_FLOAT,"HIGH_FLOAT");
	HX_VISIT_MEMBER_NAME(GL_obj::HIGH_INT,"HIGH_INT");
	HX_VISIT_MEMBER_NAME(GL_obj::INCR,"INCR");
	HX_VISIT_MEMBER_NAME(GL_obj::INCR_WRAP,"INCR_WRAP");
	HX_VISIT_MEMBER_NAME(GL_obj::INT,"INT");
	HX_VISIT_MEMBER_NAME(GL_obj::INT_VEC2,"INT_VEC2");
	HX_VISIT_MEMBER_NAME(GL_obj::INT_VEC3,"INT_VEC3");
	HX_VISIT_MEMBER_NAME(GL_obj::INT_VEC4,"INT_VEC4");
	HX_VISIT_MEMBER_NAME(GL_obj::INVALID_ENUM,"INVALID_ENUM");
	HX_VISIT_MEMBER_NAME(GL_obj::INVALID_FRAMEBUFFER_OPERATION,"INVALID_FRAMEBUFFER_OPERATION");
	HX_VISIT_MEMBER_NAME(GL_obj::INVALID_OPERATION,"INVALID_OPERATION");
	HX_VISIT_MEMBER_NAME(GL_obj::INVALID_VALUE,"INVALID_VALUE");
	HX_VISIT_MEMBER_NAME(GL_obj::INVERT,"INVERT");
	HX_VISIT_MEMBER_NAME(GL_obj::KEEP,"KEEP");
	HX_VISIT_MEMBER_NAME(GL_obj::LEQUAL,"LEQUAL");
	HX_VISIT_MEMBER_NAME(GL_obj::LESS,"LESS");
	HX_VISIT_MEMBER_NAME(GL_obj::LINEAR,"LINEAR");
	HX_VISIT_MEMBER_NAME(GL_obj::LINEAR_MIPMAP_LINEAR,"LINEAR_MIPMAP_LINEAR");
	HX_VISIT_MEMBER_NAME(GL_obj::LINEAR_MIPMAP_NEAREST,"LINEAR_MIPMAP_NEAREST");
	HX_VISIT_MEMBER_NAME(GL_obj::LINES,"LINES");
	HX_VISIT_MEMBER_NAME(GL_obj::LINE_LOOP,"LINE_LOOP");
	HX_VISIT_MEMBER_NAME(GL_obj::LINE_STRIP,"LINE_STRIP");
	HX_VISIT_MEMBER_NAME(GL_obj::LINE_WIDTH,"LINE_WIDTH");
	HX_VISIT_MEMBER_NAME(GL_obj::LINK_STATUS,"LINK_STATUS");
	HX_VISIT_MEMBER_NAME(GL_obj::LOW_FLOAT,"LOW_FLOAT");
	HX_VISIT_MEMBER_NAME(GL_obj::LOW_INT,"LOW_INT");
	HX_VISIT_MEMBER_NAME(GL_obj::LUMINANCE,"LUMINANCE");
	HX_VISIT_MEMBER_NAME(GL_obj::LUMINANCE_ALPHA,"LUMINANCE_ALPHA");
	HX_VISIT_MEMBER_NAME(GL_obj::MAX_COMBINED_TEXTURE_IMAGE_UNITS,"MAX_COMBINED_TEXTURE_IMAGE_UNITS");
	HX_VISIT_MEMBER_NAME(GL_obj::MAX_CUBE_MAP_TEXTURE_SIZE,"MAX_CUBE_MAP_TEXTURE_SIZE");
	HX_VISIT_MEMBER_NAME(GL_obj::MAX_FRAGMENT_UNIFORM_VECTORS,"MAX_FRAGMENT_UNIFORM_VECTORS");
	HX_VISIT_MEMBER_NAME(GL_obj::MAX_RENDERBUFFER_SIZE,"MAX_RENDERBUFFER_SIZE");
	HX_VISIT_MEMBER_NAME(GL_obj::MAX_TEXTURE_IMAGE_UNITS,"MAX_TEXTURE_IMAGE_UNITS");
	HX_VISIT_MEMBER_NAME(GL_obj::MAX_TEXTURE_SIZE,"MAX_TEXTURE_SIZE");
	HX_VISIT_MEMBER_NAME(GL_obj::MAX_VARYING_VECTORS,"MAX_VARYING_VECTORS");
	HX_VISIT_MEMBER_NAME(GL_obj::MAX_VERTEX_ATTRIBS,"MAX_VERTEX_ATTRIBS");
	HX_VISIT_MEMBER_NAME(GL_obj::MAX_VERTEX_TEXTURE_IMAGE_UNITS,"MAX_VERTEX_TEXTURE_IMAGE_UNITS");
	HX_VISIT_MEMBER_NAME(GL_obj::MAX_VERTEX_UNIFORM_VECTORS,"MAX_VERTEX_UNIFORM_VECTORS");
	HX_VISIT_MEMBER_NAME(GL_obj::MAX_VIEWPORT_DIMS,"MAX_VIEWPORT_DIMS");
	HX_VISIT_MEMBER_NAME(GL_obj::MEDIUM_FLOAT,"MEDIUM_FLOAT");
	HX_VISIT_MEMBER_NAME(GL_obj::MEDIUM_INT,"MEDIUM_INT");
	HX_VISIT_MEMBER_NAME(GL_obj::MIRRORED_REPEAT,"MIRRORED_REPEAT");
	HX_VISIT_MEMBER_NAME(GL_obj::NEAREST,"NEAREST");
	HX_VISIT_MEMBER_NAME(GL_obj::NEAREST_MIPMAP_LINEAR,"NEAREST_MIPMAP_LINEAR");
	HX_VISIT_MEMBER_NAME(GL_obj::NEAREST_MIPMAP_NEAREST,"NEAREST_MIPMAP_NEAREST");
	HX_VISIT_MEMBER_NAME(GL_obj::NEVER,"NEVER");
	HX_VISIT_MEMBER_NAME(GL_obj::NICEST,"NICEST");
	HX_VISIT_MEMBER_NAME(GL_obj::NONE,"NONE");
	HX_VISIT_MEMBER_NAME(GL_obj::NOTEQUAL,"NOTEQUAL");
	HX_VISIT_MEMBER_NAME(GL_obj::NO_ERROR_GL,"NO_ERROR_GL");
	HX_VISIT_MEMBER_NAME(GL_obj::ONE,"ONE");
	HX_VISIT_MEMBER_NAME(GL_obj::ONE_MINUS_CONSTANT_ALPHA,"ONE_MINUS_CONSTANT_ALPHA");
	HX_VISIT_MEMBER_NAME(GL_obj::ONE_MINUS_CONSTANT_COLOR,"ONE_MINUS_CONSTANT_COLOR");
	HX_VISIT_MEMBER_NAME(GL_obj::ONE_MINUS_DST_ALPHA,"ONE_MINUS_DST_ALPHA");
	HX_VISIT_MEMBER_NAME(GL_obj::ONE_MINUS_DST_COLOR,"ONE_MINUS_DST_COLOR");
	HX_VISIT_MEMBER_NAME(GL_obj::ONE_MINUS_SRC_ALPHA,"ONE_MINUS_SRC_ALPHA");
	HX_VISIT_MEMBER_NAME(GL_obj::ONE_MINUS_SRC_COLOR,"ONE_MINUS_SRC_COLOR");
	HX_VISIT_MEMBER_NAME(GL_obj::OUT_OF_MEMORY,"OUT_OF_MEMORY");
	HX_VISIT_MEMBER_NAME(GL_obj::PACK_ALIGNMENT,"PACK_ALIGNMENT");
	HX_VISIT_MEMBER_NAME(GL_obj::POINTS,"POINTS");
	HX_VISIT_MEMBER_NAME(GL_obj::POLYGON_OFFSET_FACTOR,"POLYGON_OFFSET_FACTOR");
	HX_VISIT_MEMBER_NAME(GL_obj::POLYGON_OFFSET_FILL,"POLYGON_OFFSET_FILL");
	HX_VISIT_MEMBER_NAME(GL_obj::POLYGON_OFFSET_UNITS,"POLYGON_OFFSET_UNITS");
	HX_VISIT_MEMBER_NAME(GL_obj::RED_BITS,"RED_BITS");
	HX_VISIT_MEMBER_NAME(GL_obj::RENDERBUFFER,"RENDERBUFFER");
	HX_VISIT_MEMBER_NAME(GL_obj::RENDERBUFFER_ALPHA_SIZE,"RENDERBUFFER_ALPHA_SIZE");
	HX_VISIT_MEMBER_NAME(GL_obj::RENDERBUFFER_BINDING,"RENDERBUFFER_BINDING");
	HX_VISIT_MEMBER_NAME(GL_obj::RENDERBUFFER_BLUE_SIZE,"RENDERBUFFER_BLUE_SIZE");
	HX_VISIT_MEMBER_NAME(GL_obj::RENDERBUFFER_DEPTH_SIZE,"RENDERBUFFER_DEPTH_SIZE");
	HX_VISIT_MEMBER_NAME(GL_obj::RENDERBUFFER_GREEN_SIZE,"RENDERBUFFER_GREEN_SIZE");
	HX_VISIT_MEMBER_NAME(GL_obj::RENDERBUFFER_HEIGHT,"RENDERBUFFER_HEIGHT");
	HX_VISIT_MEMBER_NAME(GL_obj::RENDERBUFFER_INTERNAL_FORMAT,"RENDERBUFFER_INTERNAL_FORMAT");
	HX_VISIT_MEMBER_NAME(GL_obj::RENDERBUFFER_RED_SIZE,"RENDERBUFFER_RED_SIZE");
	HX_VISIT_MEMBER_NAME(GL_obj::RENDERBUFFER_STENCIL_SIZE,"RENDERBUFFER_STENCIL_SIZE");
	HX_VISIT_MEMBER_NAME(GL_obj::RENDERBUFFER_WIDTH,"RENDERBUFFER_WIDTH");
	HX_VISIT_MEMBER_NAME(GL_obj::RENDERER,"RENDERER");
	HX_VISIT_MEMBER_NAME(GL_obj::REPEAT,"REPEAT");
	HX_VISIT_MEMBER_NAME(GL_obj::REPLACE,"REPLACE");
	HX_VISIT_MEMBER_NAME(GL_obj::RGB,"RGB");
	HX_VISIT_MEMBER_NAME(GL_obj::RGB565,"RGB565");
	HX_VISIT_MEMBER_NAME(GL_obj::RGB5_A1,"RGB5_A1");
	HX_VISIT_MEMBER_NAME(GL_obj::RGBA,"RGBA");
	HX_VISIT_MEMBER_NAME(GL_obj::RGBA4,"RGBA4");
	HX_VISIT_MEMBER_NAME(GL_obj::SAMPLER_2D,"SAMPLER_2D");
	HX_VISIT_MEMBER_NAME(GL_obj::SAMPLER_CUBE,"SAMPLER_CUBE");
	HX_VISIT_MEMBER_NAME(GL_obj::SAMPLES,"SAMPLES");
	HX_VISIT_MEMBER_NAME(GL_obj::SAMPLE_ALPHA_TO_COVERAGE,"SAMPLE_ALPHA_TO_COVERAGE");
	HX_VISIT_MEMBER_NAME(GL_obj::SAMPLE_BUFFERS,"SAMPLE_BUFFERS");
	HX_VISIT_MEMBER_NAME(GL_obj::SAMPLE_COVERAGE,"SAMPLE_COVERAGE");
	HX_VISIT_MEMBER_NAME(GL_obj::SAMPLE_COVERAGE_INVERT,"SAMPLE_COVERAGE_INVERT");
	HX_VISIT_MEMBER_NAME(GL_obj::SAMPLE_COVERAGE_VALUE,"SAMPLE_COVERAGE_VALUE");
	HX_VISIT_MEMBER_NAME(GL_obj::SCISSOR_BOX,"SCISSOR_BOX");
	HX_VISIT_MEMBER_NAME(GL_obj::SCISSOR_TEST,"SCISSOR_TEST");
	HX_VISIT_MEMBER_NAME(GL_obj::SHADER_TYPE,"SHADER_TYPE");
	HX_VISIT_MEMBER_NAME(GL_obj::SHADING_LANGUAGE_VERSION,"SHADING_LANGUAGE_VERSION");
	HX_VISIT_MEMBER_NAME(GL_obj::SHORT,"SHORT");
	HX_VISIT_MEMBER_NAME(GL_obj::SRC_ALPHA,"SRC_ALPHA");
	HX_VISIT_MEMBER_NAME(GL_obj::SRC_ALPHA_SATURATE,"SRC_ALPHA_SATURATE");
	HX_VISIT_MEMBER_NAME(GL_obj::SRC_COLOR,"SRC_COLOR");
	HX_VISIT_MEMBER_NAME(GL_obj::STATIC_DRAW,"STATIC_DRAW");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_ATTACHMENT,"STENCIL_ATTACHMENT");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_BACK_FAIL,"STENCIL_BACK_FAIL");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_BACK_FUNC,"STENCIL_BACK_FUNC");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_BACK_PASS_DEPTH_FAIL,"STENCIL_BACK_PASS_DEPTH_FAIL");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_BACK_PASS_DEPTH_PASS,"STENCIL_BACK_PASS_DEPTH_PASS");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_BACK_REF,"STENCIL_BACK_REF");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_BACK_VALUE_MASK,"STENCIL_BACK_VALUE_MASK");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_BACK_WRITEMASK,"STENCIL_BACK_WRITEMASK");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_BITS,"STENCIL_BITS");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_BUFFER_BIT,"STENCIL_BUFFER_BIT");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_CLEAR_VALUE,"STENCIL_CLEAR_VALUE");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_FAIL,"STENCIL_FAIL");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_FUNC,"STENCIL_FUNC");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_INDEX,"STENCIL_INDEX");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_INDEX8,"STENCIL_INDEX8");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_PASS_DEPTH_FAIL,"STENCIL_PASS_DEPTH_FAIL");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_PASS_DEPTH_PASS,"STENCIL_PASS_DEPTH_PASS");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_REF,"STENCIL_REF");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_TEST,"STENCIL_TEST");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_VALUE_MASK,"STENCIL_VALUE_MASK");
	HX_VISIT_MEMBER_NAME(GL_obj::STENCIL_WRITEMASK,"STENCIL_WRITEMASK");
	HX_VISIT_MEMBER_NAME(GL_obj::STREAM_DRAW,"STREAM_DRAW");
	HX_VISIT_MEMBER_NAME(GL_obj::SUBPIXEL_BITS,"SUBPIXEL_BITS");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE,"TEXTURE");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE0,"TEXTURE0");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE1,"TEXTURE1");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE10,"TEXTURE10");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE11,"TEXTURE11");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE12,"TEXTURE12");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE13,"TEXTURE13");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE14,"TEXTURE14");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE15,"TEXTURE15");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE16,"TEXTURE16");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE17,"TEXTURE17");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE18,"TEXTURE18");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE19,"TEXTURE19");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE2,"TEXTURE2");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE20,"TEXTURE20");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE21,"TEXTURE21");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE22,"TEXTURE22");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE23,"TEXTURE23");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE24,"TEXTURE24");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE25,"TEXTURE25");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE26,"TEXTURE26");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE27,"TEXTURE27");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE28,"TEXTURE28");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE29,"TEXTURE29");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE3,"TEXTURE3");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE30,"TEXTURE30");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE31,"TEXTURE31");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE4,"TEXTURE4");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE5,"TEXTURE5");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE6,"TEXTURE6");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE7,"TEXTURE7");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE8,"TEXTURE8");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE9,"TEXTURE9");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_2D,"TEXTURE_2D");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_BINDING_2D,"TEXTURE_BINDING_2D");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_BINDING_CUBE_MAP,"TEXTURE_BINDING_CUBE_MAP");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP,"TEXTURE_CUBE_MAP");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP_NEGATIVE_X,"TEXTURE_CUBE_MAP_NEGATIVE_X");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP_NEGATIVE_Y,"TEXTURE_CUBE_MAP_NEGATIVE_Y");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP_NEGATIVE_Z,"TEXTURE_CUBE_MAP_NEGATIVE_Z");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP_POSITIVE_X,"TEXTURE_CUBE_MAP_POSITIVE_X");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP_POSITIVE_Y,"TEXTURE_CUBE_MAP_POSITIVE_Y");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_CUBE_MAP_POSITIVE_Z,"TEXTURE_CUBE_MAP_POSITIVE_Z");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_MAG_FILTER,"TEXTURE_MAG_FILTER");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_MIN_FILTER,"TEXTURE_MIN_FILTER");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_WRAP_S,"TEXTURE_WRAP_S");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_WRAP_T,"TEXTURE_WRAP_T");
	HX_VISIT_MEMBER_NAME(GL_obj::TRIANGLES,"TRIANGLES");
	HX_VISIT_MEMBER_NAME(GL_obj::TRIANGLE_FAN,"TRIANGLE_FAN");
	HX_VISIT_MEMBER_NAME(GL_obj::TRIANGLE_STRIP,"TRIANGLE_STRIP");
	HX_VISIT_MEMBER_NAME(GL_obj::UNPACK_ALIGNMENT,"UNPACK_ALIGNMENT");
	HX_VISIT_MEMBER_NAME(GL_obj::UNPACK_COLORSPACE_CONVERSION_WEBGL,"UNPACK_COLORSPACE_CONVERSION_WEBGL");
	HX_VISIT_MEMBER_NAME(GL_obj::UNPACK_FLIP_Y_WEBGL,"UNPACK_FLIP_Y_WEBGL");
	HX_VISIT_MEMBER_NAME(GL_obj::UNPACK_PREMULTIPLY_ALPHA_WEBGL,"UNPACK_PREMULTIPLY_ALPHA_WEBGL");
	HX_VISIT_MEMBER_NAME(GL_obj::UNSIGNED_BYTE,"UNSIGNED_BYTE");
	HX_VISIT_MEMBER_NAME(GL_obj::UNSIGNED_INT,"UNSIGNED_INT");
	HX_VISIT_MEMBER_NAME(GL_obj::UNSIGNED_SHORT,"UNSIGNED_SHORT");
	HX_VISIT_MEMBER_NAME(GL_obj::UNSIGNED_SHORT_4_4_4_4,"UNSIGNED_SHORT_4_4_4_4");
	HX_VISIT_MEMBER_NAME(GL_obj::UNSIGNED_SHORT_5_5_5_1,"UNSIGNED_SHORT_5_5_5_1");
	HX_VISIT_MEMBER_NAME(GL_obj::UNSIGNED_SHORT_5_6_5,"UNSIGNED_SHORT_5_6_5");
	HX_VISIT_MEMBER_NAME(GL_obj::VALIDATE_STATUS,"VALIDATE_STATUS");
	HX_VISIT_MEMBER_NAME(GL_obj::VENDOR,"VENDOR");
	HX_VISIT_MEMBER_NAME(GL_obj::VERSION,"VERSION");
	HX_VISIT_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_BUFFER_BINDING,"VERTEX_ATTRIB_ARRAY_BUFFER_BINDING");
	HX_VISIT_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_ENABLED,"VERTEX_ATTRIB_ARRAY_ENABLED");
	HX_VISIT_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_NORMALIZED,"VERTEX_ATTRIB_ARRAY_NORMALIZED");
	HX_VISIT_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_POINTER,"VERTEX_ATTRIB_ARRAY_POINTER");
	HX_VISIT_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_SIZE,"VERTEX_ATTRIB_ARRAY_SIZE");
	HX_VISIT_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_STRIDE,"VERTEX_ATTRIB_ARRAY_STRIDE");
	HX_VISIT_MEMBER_NAME(GL_obj::VERTEX_ATTRIB_ARRAY_TYPE,"VERTEX_ATTRIB_ARRAY_TYPE");
	HX_VISIT_MEMBER_NAME(GL_obj::VERTEX_SHADER,"VERTEX_SHADER");
	HX_VISIT_MEMBER_NAME(GL_obj::VIEWPORT,"VIEWPORT");
	HX_VISIT_MEMBER_NAME(GL_obj::ZERO,"ZERO");
	HX_VISIT_MEMBER_NAME(GL_obj::VERTEX_ARRAY_OBJECT,"VERTEX_ARRAY_OBJECT");
	HX_VISIT_MEMBER_NAME(GL_obj::HALF_FLOAT,"HALF_FLOAT");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_HALF,"TEXTURE_HALF");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_HALF_LINEAR,"TEXTURE_HALF_LINEAR");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_ANISOTROPY,"TEXTURE_ANISOTROPY");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_ANISOTROPY_ENABLED,"TEXTURE_ANISOTROPY_ENABLED");
	HX_VISIT_MEMBER_NAME(GL_obj::MAX_TEXTURE_ANISOTROPY,"MAX_TEXTURE_ANISOTROPY");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_FLOAT,"TEXTURE_FLOAT");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_FLOAT_LINEAR,"TEXTURE_FLOAT_LINEAR");
	HX_VISIT_MEMBER_NAME(GL_obj::TEXTURE_DEPTH_ENABLED,"TEXTURE_DEPTH_ENABLED");
	HX_VISIT_MEMBER_NAME(GL_obj::MAX_ACTIVE_TEXTURE,"MAX_ACTIVE_TEXTURE");
	HX_VISIT_MEMBER_NAME(GL_obj::_NULL,"NULL");
	HX_VISIT_MEMBER_NAME(GL_obj::INVALID,"INVALID");
	HX_VISIT_MEMBER_NAME(GL_obj::m_gl,"m_gl");
};

#endif

Class GL_obj::__mClass;

void GL_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxor.platform.graphics.GL"), hx::TCanCast< GL_obj> ,sStaticFields,sMemberFields,
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

void GL_obj::__boot()
{
	ACTIVE_ATTRIBUTES= (int)35721;
	ACTIVE_TEXTURE= (int)34016;
	ACTIVE_UNIFORMS= (int)35718;
	ALIASED_LINE_WIDTH_RANGE= (int)33902;
	ALIASED_POINT_SIZE_RANGE= (int)33901;
	ALPHA= (int)6406;
	ALPHA_BITS= (int)3413;
	ALWAYS= (int)519;
	ARRAY_BUFFER= (int)34962;
	ARRAY_BUFFER_BINDING= (int)34964;
	ATTACHED_SHADERS= (int)35717;
	BACK= (int)1029;
	BLEND= (int)3042;
	BLEND_COLOR= (int)32773;
	BLEND_DST_ALPHA= (int)32970;
	BLEND_DST_RGB= (int)32968;
	BLEND_EQUATION= (int)32777;
	BLEND_EQUATION_ALPHA= (int)34877;
	BLEND_EQUATION_RGB= (int)32777;
	BLEND_SRC_ALPHA= (int)32971;
	BLEND_SRC_RGB= (int)32969;
	BLUE_BITS= (int)3412;
	BOOL= (int)35670;
	BOOL_VEC2= (int)35671;
	BOOL_VEC3= (int)35672;
	BOOL_VEC4= (int)35673;
	BROWSER_DEFAULT_WEBGL= (int)37444;
	BUFFER_SIZE= (int)34660;
	BUFFER_USAGE= (int)34661;
	BYTE= (int)5120;
	CCW= (int)2305;
	CLAMP_TO_EDGE= (int)33071;
	COLOR_ATTACHMENT0= (int)36064;
	COLOR_BUFFER_BIT= (int)16384;
	COLOR_CLEAR_VALUE= (int)3106;
	COLOR_WRITEMASK= (int)3107;
	COMPILE_STATUS= (int)35713;
	COMPRESSED_TEXTURE_FORMATS= (int)34467;
	CONSTANT_ALPHA= (int)32771;
	CONSTANT_COLOR= (int)32769;
	CONTEXT_LOST_WEBGL= (int)37442;
	CULL_FACE= (int)2884;
	CULL_FACE_MODE= (int)2885;
	CURRENT_PROGRAM= (int)35725;
	CURRENT_VERTEX_ATTRIB= (int)34342;
	CW= (int)2304;
	DECR= (int)7683;
	DECR_WRAP= (int)34056;
	DELETE_STATUS= (int)35712;
	DEPTH_ATTACHMENT= (int)36096;
	DEPTH_BITS= (int)3414;
	DEPTH_BUFFER_BIT= (int)256;
	DEPTH_CLEAR_VALUE= (int)2931;
	DEPTH_COMPONENT= (int)6402;
	DEPTH_COMPONENT16= (int)33189;
	DEPTH_FUNC= (int)2932;
	DEPTH_RANGE= (int)2928;
	DEPTH_STENCIL= (int)34041;
	DEPTH_STENCIL_ATTACHMENT= (int)33306;
	DEPTH_TEST= (int)2929;
	DEPTH_WRITEMASK= (int)2930;
	DITHER= (int)3024;
	DONT_CARE= (int)4352;
	DST_ALPHA= (int)772;
	DST_COLOR= (int)774;
	DYNAMIC_DRAW= (int)35048;
	ELEMENT_ARRAY_BUFFER= (int)34963;
	ELEMENT_ARRAY_BUFFER_BINDING= (int)34965;
	EQUAL= (int)514;
	FASTEST= (int)4353;
	FLOAT= (int)5126;
	FLOAT_MAT2= (int)35674;
	FLOAT_MAT3= (int)35675;
	FLOAT_MAT4= (int)35676;
	FLOAT_VEC2= (int)35664;
	FLOAT_VEC3= (int)35665;
	FLOAT_VEC4= (int)35666;
	FRAGMENT_SHADER= (int)35632;
	FRAMEBUFFER= (int)36160;
	FRAMEBUFFER_ATTACHMENT_OBJECT_NAME= (int)36049;
	FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE= (int)36048;
	FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE= (int)36051;
	FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL= (int)36050;
	FRAMEBUFFER_BINDING= (int)36006;
	FRAMEBUFFER_COMPLETE= (int)36053;
	FRAMEBUFFER_INCOMPLETE_ATTACHMENT= (int)36054;
	FRAMEBUFFER_INCOMPLETE_DIMENSIONS= (int)36057;
	FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT= (int)36055;
	FRAMEBUFFER_UNSUPPORTED= (int)36061;
	FRONT= (int)1028;
	FRONT_AND_BACK= (int)1032;
	FRONT_FACE= (int)2886;
	FUNC_ADD= (int)32774;
	FUNC_REVERSE_SUBTRACT= (int)32779;
	FUNC_SUBTRACT= (int)32778;
	GENERATE_MIPMAP_HINT= (int)33170;
	GEQUAL= (int)518;
	GREATER= (int)516;
	GREEN_BITS= (int)3411;
	HIGH_FLOAT= (int)36338;
	HIGH_INT= (int)36341;
	INCR= (int)7682;
	INCR_WRAP= (int)34055;
	INT= (int)5124;
	INT_VEC2= (int)35667;
	INT_VEC3= (int)35668;
	INT_VEC4= (int)35669;
	INVALID_ENUM= (int)1280;
	INVALID_FRAMEBUFFER_OPERATION= (int)1286;
	INVALID_OPERATION= (int)1282;
	INVALID_VALUE= (int)1281;
	INVERT= (int)5386;
	KEEP= (int)7680;
	LEQUAL= (int)515;
	LESS= (int)513;
	LINEAR= (int)9729;
	LINEAR_MIPMAP_LINEAR= (int)9987;
	LINEAR_MIPMAP_NEAREST= (int)9985;
	LINES= (int)1;
	LINE_LOOP= (int)2;
	LINE_STRIP= (int)3;
	LINE_WIDTH= (int)2849;
	LINK_STATUS= (int)35714;
	LOW_FLOAT= (int)36336;
	LOW_INT= (int)36339;
	LUMINANCE= (int)6409;
	LUMINANCE_ALPHA= (int)6410;
	MAX_COMBINED_TEXTURE_IMAGE_UNITS= (int)35661;
	MAX_CUBE_MAP_TEXTURE_SIZE= (int)34076;
	MAX_FRAGMENT_UNIFORM_VECTORS= (int)36349;
	MAX_RENDERBUFFER_SIZE= (int)34024;
	MAX_TEXTURE_IMAGE_UNITS= (int)34930;
	MAX_TEXTURE_SIZE= (int)3379;
	MAX_VARYING_VECTORS= (int)36348;
	MAX_VERTEX_ATTRIBS= (int)34921;
	MAX_VERTEX_TEXTURE_IMAGE_UNITS= (int)35660;
	MAX_VERTEX_UNIFORM_VECTORS= (int)36347;
	MAX_VIEWPORT_DIMS= (int)3386;
	MEDIUM_FLOAT= (int)36337;
	MEDIUM_INT= (int)36340;
	MIRRORED_REPEAT= (int)33648;
	NEAREST= (int)9728;
	NEAREST_MIPMAP_LINEAR= (int)9986;
	NEAREST_MIPMAP_NEAREST= (int)9984;
	NEVER= (int)512;
	NICEST= (int)4354;
	NONE= (int)0;
	NOTEQUAL= (int)517;
	NO_ERROR_GL= (int)0;
	ONE= (int)1;
	ONE_MINUS_CONSTANT_ALPHA= (int)32772;
	ONE_MINUS_CONSTANT_COLOR= (int)32770;
	ONE_MINUS_DST_ALPHA= (int)773;
	ONE_MINUS_DST_COLOR= (int)775;
	ONE_MINUS_SRC_ALPHA= (int)771;
	ONE_MINUS_SRC_COLOR= (int)769;
	OUT_OF_MEMORY= (int)1285;
	PACK_ALIGNMENT= (int)3333;
	POINTS= (int)0;
	POLYGON_OFFSET_FACTOR= (int)32824;
	POLYGON_OFFSET_FILL= (int)32823;
	POLYGON_OFFSET_UNITS= (int)10752;
	RED_BITS= (int)3410;
	RENDERBUFFER= (int)36161;
	RENDERBUFFER_ALPHA_SIZE= (int)36179;
	RENDERBUFFER_BINDING= (int)36007;
	RENDERBUFFER_BLUE_SIZE= (int)36178;
	RENDERBUFFER_DEPTH_SIZE= (int)36180;
	RENDERBUFFER_GREEN_SIZE= (int)36177;
	RENDERBUFFER_HEIGHT= (int)36163;
	RENDERBUFFER_INTERNAL_FORMAT= (int)36164;
	RENDERBUFFER_RED_SIZE= (int)36176;
	RENDERBUFFER_STENCIL_SIZE= (int)36181;
	RENDERBUFFER_WIDTH= (int)36162;
	RENDERER= (int)7937;
	REPEAT= (int)10497;
	REPLACE= (int)7681;
	RGB= (int)6407;
	RGB565= (int)36194;
	RGB5_A1= (int)32855;
	RGBA= (int)6408;
	RGBA4= (int)32854;
	SAMPLER_2D= (int)35678;
	SAMPLER_CUBE= (int)35680;
	SAMPLES= (int)32937;
	SAMPLE_ALPHA_TO_COVERAGE= (int)32926;
	SAMPLE_BUFFERS= (int)32936;
	SAMPLE_COVERAGE= (int)32928;
	SAMPLE_COVERAGE_INVERT= (int)32939;
	SAMPLE_COVERAGE_VALUE= (int)32938;
	SCISSOR_BOX= (int)3088;
	SCISSOR_TEST= (int)3089;
	SHADER_TYPE= (int)35663;
	SHADING_LANGUAGE_VERSION= (int)35724;
	SHORT= (int)5122;
	SRC_ALPHA= (int)770;
	SRC_ALPHA_SATURATE= (int)776;
	SRC_COLOR= (int)768;
	STATIC_DRAW= (int)35044;
	STENCIL_ATTACHMENT= (int)36128;
	STENCIL_BACK_FAIL= (int)34817;
	STENCIL_BACK_FUNC= (int)34816;
	STENCIL_BACK_PASS_DEPTH_FAIL= (int)34818;
	STENCIL_BACK_PASS_DEPTH_PASS= (int)34819;
	STENCIL_BACK_REF= (int)36003;
	STENCIL_BACK_VALUE_MASK= (int)36004;
	STENCIL_BACK_WRITEMASK= (int)36005;
	STENCIL_BITS= (int)3415;
	STENCIL_BUFFER_BIT= (int)1024;
	STENCIL_CLEAR_VALUE= (int)2961;
	STENCIL_FAIL= (int)2964;
	STENCIL_FUNC= (int)2962;
	STENCIL_INDEX= (int)6401;
	STENCIL_INDEX8= (int)36168;
	STENCIL_PASS_DEPTH_FAIL= (int)2965;
	STENCIL_PASS_DEPTH_PASS= (int)2966;
	STENCIL_REF= (int)2967;
	STENCIL_TEST= (int)2960;
	STENCIL_VALUE_MASK= (int)2963;
	STENCIL_WRITEMASK= (int)2968;
	STREAM_DRAW= (int)35040;
	SUBPIXEL_BITS= (int)3408;
	TEXTURE= (int)5890;
	TEXTURE0= (int)33984;
	TEXTURE1= (int)33985;
	TEXTURE10= (int)33994;
	TEXTURE11= (int)33995;
	TEXTURE12= (int)33996;
	TEXTURE13= (int)33997;
	TEXTURE14= (int)33998;
	TEXTURE15= (int)33999;
	TEXTURE16= (int)34000;
	TEXTURE17= (int)34001;
	TEXTURE18= (int)34002;
	TEXTURE19= (int)34003;
	TEXTURE2= (int)33986;
	TEXTURE20= (int)34004;
	TEXTURE21= (int)34005;
	TEXTURE22= (int)34006;
	TEXTURE23= (int)34007;
	TEXTURE24= (int)34008;
	TEXTURE25= (int)34009;
	TEXTURE26= (int)34010;
	TEXTURE27= (int)34011;
	TEXTURE28= (int)34012;
	TEXTURE29= (int)34013;
	TEXTURE3= (int)33987;
	TEXTURE30= (int)34014;
	TEXTURE31= (int)34015;
	TEXTURE4= (int)33988;
	TEXTURE5= (int)33989;
	TEXTURE6= (int)33990;
	TEXTURE7= (int)33991;
	TEXTURE8= (int)33992;
	TEXTURE9= (int)33993;
	TEXTURE_2D= (int)3553;
	TEXTURE_BINDING_2D= (int)32873;
	TEXTURE_BINDING_CUBE_MAP= (int)34068;
	TEXTURE_CUBE_MAP= (int)34067;
	TEXTURE_CUBE_MAP_NEGATIVE_X= (int)34070;
	TEXTURE_CUBE_MAP_NEGATIVE_Y= (int)34072;
	TEXTURE_CUBE_MAP_NEGATIVE_Z= (int)34074;
	TEXTURE_CUBE_MAP_POSITIVE_X= (int)34069;
	TEXTURE_CUBE_MAP_POSITIVE_Y= (int)34071;
	TEXTURE_CUBE_MAP_POSITIVE_Z= (int)34073;
	TEXTURE_MAG_FILTER= (int)10240;
	TEXTURE_MIN_FILTER= (int)10241;
	TEXTURE_WRAP_S= (int)10242;
	TEXTURE_WRAP_T= (int)10243;
	TRIANGLES= (int)4;
	TRIANGLE_FAN= (int)6;
	TRIANGLE_STRIP= (int)5;
	UNPACK_ALIGNMENT= (int)3317;
	UNPACK_COLORSPACE_CONVERSION_WEBGL= (int)37443;
	UNPACK_FLIP_Y_WEBGL= (int)37440;
	UNPACK_PREMULTIPLY_ALPHA_WEBGL= (int)37441;
	UNSIGNED_BYTE= (int)5121;
	UNSIGNED_INT= (int)5125;
	UNSIGNED_SHORT= (int)5123;
	UNSIGNED_SHORT_4_4_4_4= (int)32819;
	UNSIGNED_SHORT_5_5_5_1= (int)32820;
	UNSIGNED_SHORT_5_6_5= (int)33635;
	VALIDATE_STATUS= (int)35715;
	VENDOR= (int)7936;
	VERSION= (int)7938;
	VERTEX_ATTRIB_ARRAY_BUFFER_BINDING= (int)34975;
	VERTEX_ATTRIB_ARRAY_ENABLED= (int)34338;
	VERTEX_ATTRIB_ARRAY_NORMALIZED= (int)34922;
	VERTEX_ATTRIB_ARRAY_POINTER= (int)34373;
	VERTEX_ATTRIB_ARRAY_SIZE= (int)34339;
	VERTEX_ATTRIB_ARRAY_STRIDE= (int)34340;
	VERTEX_ATTRIB_ARRAY_TYPE= (int)34341;
	VERTEX_SHADER= (int)35633;
	VIEWPORT= (int)2978;
	ZERO= (int)0;
	VERTEX_ARRAY_OBJECT= false;
	HALF_FLOAT= (int)5126;
	TEXTURE_HALF= false;
	TEXTURE_HALF_LINEAR= false;
	TEXTURE_ANISOTROPY= (int)-1;
	TEXTURE_ANISOTROPY_ENABLED= false;
	MAX_TEXTURE_ANISOTROPY= (int)1;
	TEXTURE_FLOAT= false;
	TEXTURE_FLOAT_LINEAR= false;
	TEXTURE_DEPTH_ENABLED= false;
	MAX_ACTIVE_TEXTURE= (int)8;
	_NULL= (int)0;
	INVALID= (int)-1;
}

} // end namespace haxor
} // end namespace platform
} // end namespace graphics
