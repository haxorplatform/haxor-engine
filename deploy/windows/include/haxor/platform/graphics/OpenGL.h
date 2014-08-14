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

		virtual ::String GetProgramInfoLog( int p_program);

		virtual int GetProgramParameter( int p_program,int p_parameter);

		virtual Void LinkProgram( int p_program);

		virtual Void UseProgram( int p_program);

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

		virtual int GetErrorCode( );

};

} // end namespace haxor
} // end namespace platform
} // end namespace graphics

#endif /* INCLUDED_haxor_platform_graphics_OpenGL */ 
