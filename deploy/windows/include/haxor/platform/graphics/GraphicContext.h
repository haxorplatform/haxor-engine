#ifndef INCLUDED_haxor_platform_graphics_GraphicContext
#define INCLUDED_haxor_platform_graphics_GraphicContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS3(haxor,platform,graphics,GraphicAPI)
HX_DECLARE_CLASS3(haxor,platform,graphics,GraphicContext)
namespace haxor{
namespace platform{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  GraphicContext_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GraphicContext_obj OBJ_;
		GraphicContext_obj();
		Void __construct(::haxor::core::BaseApplication p_application);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GraphicContext_obj > __new(::haxor::core::BaseApplication p_application);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GraphicContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GraphicContext"); }

		virtual ::haxor::platform::graphics::GraphicAPI get_api( );
		Dynamic get_api_dyn();

		::haxor::platform::graphics::GraphicAPI m_api;
		::haxor::core::BaseApplication m_application;
		virtual Void CheckExtensions( );
		Dynamic CheckExtensions_dyn();

		virtual Void Destroy( );
		Dynamic Destroy_dyn();

		virtual Void Flush( );
		Dynamic Flush_dyn();

		virtual Void Focus( );
		Dynamic Focus_dyn();

		virtual Void Resize( );
		Dynamic Resize_dyn();

		virtual Void BindBuffer( int p_target,int p_id);
		Dynamic BindBuffer_dyn();

		virtual Void BufferData( int p_target,::haxor::io::Buffer p_data,int p_mode);
		Dynamic BufferData_dyn();

		virtual Void BufferSubData( int p_target,int p_offset,::haxor::io::Buffer p_data);
		Dynamic BufferSubData_dyn();

		virtual int CreateBuffer( );
		Dynamic CreateBuffer_dyn();

		virtual Void DeleteBuffer( int p_id);
		Dynamic DeleteBuffer_dyn();

		virtual Void DrawArrays( int p_primitive,int p_start,int p_count);
		Dynamic DrawArrays_dyn();

		virtual Void DrawElements( int p_primitive,int p_count,int p_type,int p_offset);
		Dynamic DrawElements_dyn();

		virtual Void EnableVertexAttrib( int p_location);
		Dynamic EnableVertexAttrib_dyn();

		virtual Void DisableVertexAttrib( int p_location);
		Dynamic DisableVertexAttrib_dyn();

		virtual Void VertexAttrib3f( int p_location,Float p_x,Float p_y,Float p_z);
		Dynamic VertexAttrib3f_dyn();

		virtual Void VertexAttrib4f( int p_location,Float p_x,Float p_y,Float p_z,Float p_w);
		Dynamic VertexAttrib4f_dyn();

		virtual Void VertexAttribPointer( int p_location,int p_components_size,int p_type,bool p_normalized,int p_stride,int p_offset);
		Dynamic VertexAttribPointer_dyn();

		virtual Void CompileShader( int p_shader);
		Dynamic CompileShader_dyn();

		virtual int CreateShader( int p_type);
		Dynamic CreateShader_dyn();

		virtual Void DeleteShader( int p_shader);
		Dynamic DeleteShader_dyn();

		virtual Void DetachShader( int p_program,int p_shader);
		Dynamic DetachShader_dyn();

		virtual ::String GetShaderInfoLog( int p_shader);
		Dynamic GetShaderInfoLog_dyn();

		virtual int GetShaderParameter( int p_shader,int p_parameter);
		Dynamic GetShaderParameter_dyn();

		virtual Void ShaderSource( int p_shader,::String p_source);
		Dynamic ShaderSource_dyn();

		virtual Void AttachShader( int p_program,int p_shader);
		Dynamic AttachShader_dyn();

		virtual Void BindAttribLocation( int p_program,int p_location,::String p_name);
		Dynamic BindAttribLocation_dyn();

		virtual int CreateProgram( );
		Dynamic CreateProgram_dyn();

		virtual Void DeleteProgram( int p_program);
		Dynamic DeleteProgram_dyn();

		virtual int GetAttribLocation( int p_program,::String p_name);
		Dynamic GetAttribLocation_dyn();

		virtual ::String GetProgramInfoLog( int p_program);
		Dynamic GetProgramInfoLog_dyn();

		virtual int GetProgramParameter( int p_program,int p_parameter);
		Dynamic GetProgramParameter_dyn();

		virtual Void LinkProgram( int p_program);
		Dynamic LinkProgram_dyn();

		virtual Void UseProgram( int p_program);
		Dynamic UseProgram_dyn();

		virtual Void BlendFunc( int p_src,int p_dst);
		Dynamic BlendFunc_dyn();

		virtual Void Disable( int p_flag);
		Dynamic Disable_dyn();

		virtual Void Enable( int p_flag);
		Dynamic Enable_dyn();

		virtual Void DepthMask( bool p_flag);
		Dynamic DepthMask_dyn();

		virtual Void DepthFunc( int p_flag);
		Dynamic DepthFunc_dyn();

		virtual Void CullFace( int p_face);
		Dynamic CullFace_dyn();

		virtual Void FrontFace( int p_face);
		Dynamic FrontFace_dyn();

		virtual Void Clear( int p_flag);
		Dynamic Clear_dyn();

		virtual Void ClearDepth( Float p_value);
		Dynamic ClearDepth_dyn();

		virtual Void ClearColor( Float p_r,Float p_g,Float p_b,Float p_a);
		Dynamic ClearColor_dyn();

		virtual int GetErrorCode( );
		Dynamic GetErrorCode_dyn();

		virtual ::String GetErrorString( int p_code);
		Dynamic GetErrorString_dyn();

		virtual ::String GetError( );
		Dynamic GetError_dyn();

		virtual Void Assert( ::String p_log);
		Dynamic Assert_dyn();

		virtual Void LogError( );
		Dynamic LogError_dyn();

};

} // end namespace haxor
} // end namespace platform
} // end namespace graphics

#endif /* INCLUDED_haxor_platform_graphics_GraphicContext */ 
