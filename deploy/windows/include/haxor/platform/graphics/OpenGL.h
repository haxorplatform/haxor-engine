#ifndef INCLUDED_haxor_platform_graphics_OpenGL
#define INCLUDED_haxor_platform_graphics_OpenGL

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxor/platform/graphics/WinGL.h>
HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS2(haxor,io,FloatArray)
HX_DECLARE_CLASS2(haxor,io,Int32Array)
HX_DECLARE_CLASS3(haxor,platform,graphics,GraphicContext)
HX_DECLARE_CLASS3(haxor,platform,graphics,OpenGL)
HX_DECLARE_CLASS3(haxor,platform,graphics,WinGL)
namespace haxor{
namespace platform{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  OpenGL_obj : public ::haxor::platform::graphics::WinGL_obj{
	public:
		typedef ::haxor::platform::graphics::WinGL_obj super;
		typedef OpenGL_obj OBJ_;
		OpenGL_obj();
		Void __construct(::haxor::core::BaseApplication p_application);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< OpenGL_obj > __new(::haxor::core::BaseApplication p_application);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~OpenGL_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("OpenGL"); }

		virtual Void CheckExtensions( );

		virtual Void BindBuffer( int p_target,int p_id);

		virtual Void BufferData( int p_target,::haxor::io::Buffer p_data,int p_mode);

		virtual Void BufferSubData( int p_target,int p_offset,::haxor::io::Buffer p_data);

		virtual int CreateBuffer( );

		virtual Void DrawArrays( int p_primitive,int p_start,int p_count);

		virtual Void DrawElements( int p_primitive,int p_count,int p_type,int p_offset);

		virtual Void DeleteBuffer( int p_id);

		virtual Void DisableVertexAttrib( int p_location);

		virtual Void EnableVertexAttrib( int p_location);

		virtual Void VertexAttrib3f( int p_location,Float p_x,Float p_y,Float p_z);

		virtual Void VertexAttrib4f( int p_location,Float p_x,Float p_y,Float p_z,Float p_w);

		virtual Void VertexAttribPointer( int p_location,int p_components_size,int p_type,bool p_normalized,int p_stride,int p_offset);

		virtual Void CompileShader( int p_shader);

		virtual int CreateShader( int p_type);

		virtual Void DetachShader( int p_program,int p_shader);

		virtual Void DeleteShader( int p_shader);

		virtual ::String GetShaderInfoLog( int p_shader);

		virtual int GetShaderParameter( int p_shader,int p_parameter);

		virtual Void ShaderSource( int p_shader,::String p_source);

		virtual Void AttachShader( int p_program,int p_shader);

		virtual Void BindAttribLocation( int p_program,int p_location,::String p_name);

		virtual int CreateProgram( );

		virtual Void DeleteProgram( int p_program);

		virtual int GetAttribLocation( int p_program,::String p_name);

		virtual int GetUniformLocation( int p_program,::String p_name);

		virtual ::String GetProgramInfoLog( int p_program);

		virtual int GetProgramParameter( int p_program,int p_parameter);

		virtual Void LinkProgram( int p_program);

		virtual Void UseProgram( int p_program);

		virtual Void ActiveTexture( int p_slot);

		virtual Void BindFramebuffer( int p_target,int p_id);

		virtual Void BindRenderbuffer( int p_target,int p_id);

		virtual Void BindTexture( int p_target,int p_id);

		virtual int CreateFramebuffer( );

		virtual int CreateRenderbuffer( );

		virtual int CreateTexture( );

		virtual Void DeleteFramebuffer( int p_id);

		virtual Void DeleteRenderbuffer( int p_id);

		virtual Void DeleteTexture( int p_id);

		virtual Void FramebufferRenderbuffer( int p_target,int p_attachment,int p_renderbuffer_target,int p_renderbuffer_id);

		virtual Void FramebufferTexture2D( int p_target,int p_attachment,int p_texture_target,int p_texture_id,int p_miplevel);

		virtual Void GenerateMipmap( int p_target);

		virtual Void PixelStorei( int p_parameter,int p_value);

		virtual Void RenderbufferStorage( int p_target,int p_format,int p_width,int p_height);

		virtual Void TexImage2D( int p_target,int p_level,int p_internal_format,int p_width,int p_height,int p_border,int p_format,int p_channel_type,::haxor::io::Buffer p_data);

		virtual Void TexImage2DAlloc( int p_target,int p_level,int p_internal_format,int p_width,int p_height,int p_border,int p_format,int p_channel_type);

		virtual Void TexSubImage2D( int p_target,int p_level,int p_x,int p_y,int p_width,int p_height,int p_format,int p_channel_type,::haxor::io::Buffer p_data);

		virtual Void TexParameterf( int p_target,int p_parameter,Float p_value);

		virtual Void TexParameteri( int p_target,int p_parameter,int p_value);

		virtual Void Uniform1f( int p_location,Float p_x);

		virtual Void Uniform2f( int p_location,Float p_x,Float p_y);

		virtual Void Uniform3f( int p_location,Float p_x,Float p_y,Float p_z);

		virtual Void Uniform4f( int p_location,Float p_x,Float p_y,Float p_z,Float p_w);

		virtual Void Uniform1i( int p_location,int p_x);

		virtual Void Uniform2i( int p_location,int p_x,int p_y);

		virtual Void Uniform3i( int p_location,int p_x,int p_y,int p_z);

		virtual Void Uniform4i( int p_location,int p_x,int p_y,int p_z,int p_w);

		virtual Void Uniform1fv( int p_location,::haxor::io::FloatArray p_v);

		virtual Void Uniform2fv( int p_location,::haxor::io::FloatArray p_v);

		virtual Void Uniform3fv( int p_location,::haxor::io::FloatArray p_v);

		virtual Void Uniform4fv( int p_location,::haxor::io::FloatArray p_v);

		virtual Void Uniform1iv( int p_location,::haxor::io::Int32Array p_v);

		virtual Void Uniform2iv( int p_location,::haxor::io::Int32Array p_v);

		virtual Void Uniform3iv( int p_location,::haxor::io::Int32Array p_v);

		virtual Void Uniform4iv( int p_location,::haxor::io::Int32Array p_v);

		virtual Void UniformMatrix2fv( int p_location,bool p_transpose,::haxor::io::FloatArray p_v);

		virtual Void UniformMatrix3fv( int p_location,bool p_transpose,::haxor::io::FloatArray p_v);

		virtual Void UniformMatrix4fv( int p_location,bool p_transpose,::haxor::io::FloatArray p_v);

		virtual Void BlendFunc( int p_src,int p_dst);

		virtual Void Disable( int p_flag);

		virtual Void Enable( int p_flag);

		virtual Void DepthMask( bool p_flag);

		virtual Void DepthFunc( int p_flag);

		virtual Void CullFace( int p_face);

		virtual Void FrontFace( int p_face);

		virtual Void Clear( int p_flag);

		virtual Void ClearDepth( Float p_value);

		virtual Void ClearColor( Float p_r,Float p_g,Float p_b,Float p_a);

		virtual Void Viewport( int p_x,int p_y,int p_width,int p_height);

		virtual Void Scissor( int p_x,int p_y,int p_width,int p_height);

		virtual Void ReadPixels( int p_x,int p_y,int p_width,int p_height,int p_format,int p_type,::haxor::io::Buffer p_pixels);

		virtual int GetErrorCode( );

};

} // end namespace haxor
} // end namespace platform
} // end namespace graphics

#endif /* INCLUDED_haxor_platform_graphics_OpenGL */ 
