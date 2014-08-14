#ifndef INCLUDED_haxor_platform_graphics_GL
#define INCLUDED_haxor_platform_graphics_GL

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxor,component,Behaviour)
HX_DECLARE_CLASS2(haxor,component,Component)
HX_DECLARE_CLASS2(haxor,core,BaseApplication)
HX_DECLARE_CLASS2(haxor,core,IDisposable)
HX_DECLARE_CLASS2(haxor,core,Resource)
HX_DECLARE_CLASS2(haxor,io,Buffer)
HX_DECLARE_CLASS3(haxor,platform,graphics,GL)
HX_DECLARE_CLASS3(haxor,platform,graphics,GraphicAPI)
HX_DECLARE_CLASS3(haxor,platform,graphics,GraphicContext)
HX_DECLARE_CLASS3(haxor,platform,graphics,OpenGL)
HX_DECLARE_CLASS3(haxor,platform,graphics,WinGL)
namespace haxor{
namespace platform{
namespace graphics{


class HXCPP_CLASS_ATTRIBUTES  GL_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GL_obj OBJ_;
		GL_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GL_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GL_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("GL"); }

		static int ACTIVE_ATTRIBUTES;
		static int ACTIVE_TEXTURE;
		static int ACTIVE_UNIFORMS;
		static int ALIASED_LINE_WIDTH_RANGE;
		static int ALIASED_POINT_SIZE_RANGE;
		static int ALPHA;
		static int ALPHA_BITS;
		static int ALWAYS;
		static int ARRAY_BUFFER;
		static int ARRAY_BUFFER_BINDING;
		static int ATTACHED_SHADERS;
		static int BACK;
		static int BLEND;
		static int BLEND_COLOR;
		static int BLEND_DST_ALPHA;
		static int BLEND_DST_RGB;
		static int BLEND_EQUATION;
		static int BLEND_EQUATION_ALPHA;
		static int BLEND_EQUATION_RGB;
		static int BLEND_SRC_ALPHA;
		static int BLEND_SRC_RGB;
		static int BLUE_BITS;
		static int BOOL;
		static int BOOL_VEC2;
		static int BOOL_VEC3;
		static int BOOL_VEC4;
		static int BROWSER_DEFAULT_WEBGL;
		static int BUFFER_SIZE;
		static int BUFFER_USAGE;
		static int BYTE;
		static int CCW;
		static int CLAMP_TO_EDGE;
		static int COLOR_ATTACHMENT0;
		static int COLOR_BUFFER_BIT;
		static int COLOR_CLEAR_VALUE;
		static int COLOR_WRITEMASK;
		static int COMPILE_STATUS;
		static int COMPRESSED_TEXTURE_FORMATS;
		static int CONSTANT_ALPHA;
		static int CONSTANT_COLOR;
		static int CONTEXT_LOST_WEBGL;
		static int CULL_FACE;
		static int CULL_FACE_MODE;
		static int CURRENT_PROGRAM;
		static int CURRENT_VERTEX_ATTRIB;
		static int CW;
		static int DECR;
		static int DECR_WRAP;
		static int DELETE_STATUS;
		static int DEPTH_ATTACHMENT;
		static int DEPTH_BITS;
		static int DEPTH_BUFFER_BIT;
		static int DEPTH_CLEAR_VALUE;
		static int DEPTH_COMPONENT;
		static int DEPTH_COMPONENT16;
		static int DEPTH_FUNC;
		static int DEPTH_RANGE;
		static int DEPTH_STENCIL;
		static int DEPTH_STENCIL_ATTACHMENT;
		static int DEPTH_TEST;
		static int DEPTH_WRITEMASK;
		static int DITHER;
		static int DONT_CARE;
		static int DST_ALPHA;
		static int DST_COLOR;
		static int DYNAMIC_DRAW;
		static int ELEMENT_ARRAY_BUFFER;
		static int ELEMENT_ARRAY_BUFFER_BINDING;
		static int EQUAL;
		static int FASTEST;
		static int FLOAT;
		static int FLOAT_MAT2;
		static int FLOAT_MAT3;
		static int FLOAT_MAT4;
		static int FLOAT_VEC2;
		static int FLOAT_VEC3;
		static int FLOAT_VEC4;
		static int FRAGMENT_SHADER;
		static int FRAMEBUFFER;
		static int FRAMEBUFFER_ATTACHMENT_OBJECT_NAME;
		static int FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE;
		static int FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE;
		static int FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL;
		static int FRAMEBUFFER_BINDING;
		static int FRAMEBUFFER_COMPLETE;
		static int FRAMEBUFFER_INCOMPLETE_ATTACHMENT;
		static int FRAMEBUFFER_INCOMPLETE_DIMENSIONS;
		static int FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT;
		static int FRAMEBUFFER_UNSUPPORTED;
		static int FRONT;
		static int FRONT_AND_BACK;
		static int FRONT_FACE;
		static int FUNC_ADD;
		static int FUNC_REVERSE_SUBTRACT;
		static int FUNC_SUBTRACT;
		static int GENERATE_MIPMAP_HINT;
		static int GEQUAL;
		static int GREATER;
		static int GREEN_BITS;
		static int HIGH_FLOAT;
		static int HIGH_INT;
		static int INCR;
		static int INCR_WRAP;
		static int INT;
		static int INT_VEC2;
		static int INT_VEC3;
		static int INT_VEC4;
		static int INVALID_ENUM;
		static int INVALID_FRAMEBUFFER_OPERATION;
		static int INVALID_OPERATION;
		static int INVALID_VALUE;
		static int INVERT;
		static int KEEP;
		static int LEQUAL;
		static int LESS;
		static int LINEAR;
		static int LINEAR_MIPMAP_LINEAR;
		static int LINEAR_MIPMAP_NEAREST;
		static int LINES;
		static int LINE_LOOP;
		static int LINE_STRIP;
		static int LINE_WIDTH;
		static int LINK_STATUS;
		static int LOW_FLOAT;
		static int LOW_INT;
		static int LUMINANCE;
		static int LUMINANCE_ALPHA;
		static int MAX_COMBINED_TEXTURE_IMAGE_UNITS;
		static int MAX_CUBE_MAP_TEXTURE_SIZE;
		static int MAX_FRAGMENT_UNIFORM_VECTORS;
		static int MAX_RENDERBUFFER_SIZE;
		static int MAX_TEXTURE_IMAGE_UNITS;
		static int MAX_TEXTURE_SIZE;
		static int MAX_VARYING_VECTORS;
		static int MAX_VERTEX_ATTRIBS;
		static int MAX_VERTEX_TEXTURE_IMAGE_UNITS;
		static int MAX_VERTEX_UNIFORM_VECTORS;
		static int MAX_VIEWPORT_DIMS;
		static int MEDIUM_FLOAT;
		static int MEDIUM_INT;
		static int MIRRORED_REPEAT;
		static int NEAREST;
		static int NEAREST_MIPMAP_LINEAR;
		static int NEAREST_MIPMAP_NEAREST;
		static int NEVER;
		static int NICEST;
		static int NONE;
		static int NOTEQUAL;
		static int NO_ERROR_GL;
		static int ONE;
		static int ONE_MINUS_CONSTANT_ALPHA;
		static int ONE_MINUS_CONSTANT_COLOR;
		static int ONE_MINUS_DST_ALPHA;
		static int ONE_MINUS_DST_COLOR;
		static int ONE_MINUS_SRC_ALPHA;
		static int ONE_MINUS_SRC_COLOR;
		static int OUT_OF_MEMORY;
		static int PACK_ALIGNMENT;
		static int POINTS;
		static int POLYGON_OFFSET_FACTOR;
		static int POLYGON_OFFSET_FILL;
		static int POLYGON_OFFSET_UNITS;
		static int RED_BITS;
		static int RENDERBUFFER;
		static int RENDERBUFFER_ALPHA_SIZE;
		static int RENDERBUFFER_BINDING;
		static int RENDERBUFFER_BLUE_SIZE;
		static int RENDERBUFFER_DEPTH_SIZE;
		static int RENDERBUFFER_GREEN_SIZE;
		static int RENDERBUFFER_HEIGHT;
		static int RENDERBUFFER_INTERNAL_FORMAT;
		static int RENDERBUFFER_RED_SIZE;
		static int RENDERBUFFER_STENCIL_SIZE;
		static int RENDERBUFFER_WIDTH;
		static int RENDERER;
		static int REPEAT;
		static int REPLACE;
		static int RGB;
		static int RGB565;
		static int RGB5_A1;
		static int RGBA;
		static int RGBA4;
		static int SAMPLER_2D;
		static int SAMPLER_CUBE;
		static int SAMPLES;
		static int SAMPLE_ALPHA_TO_COVERAGE;
		static int SAMPLE_BUFFERS;
		static int SAMPLE_COVERAGE;
		static int SAMPLE_COVERAGE_INVERT;
		static int SAMPLE_COVERAGE_VALUE;
		static int SCISSOR_BOX;
		static int SCISSOR_TEST;
		static int SHADER_TYPE;
		static int SHADING_LANGUAGE_VERSION;
		static int SHORT;
		static int SRC_ALPHA;
		static int SRC_ALPHA_SATURATE;
		static int SRC_COLOR;
		static int STATIC_DRAW;
		static int STENCIL_ATTACHMENT;
		static int STENCIL_BACK_FAIL;
		static int STENCIL_BACK_FUNC;
		static int STENCIL_BACK_PASS_DEPTH_FAIL;
		static int STENCIL_BACK_PASS_DEPTH_PASS;
		static int STENCIL_BACK_REF;
		static int STENCIL_BACK_VALUE_MASK;
		static int STENCIL_BACK_WRITEMASK;
		static int STENCIL_BITS;
		static int STENCIL_BUFFER_BIT;
		static int STENCIL_CLEAR_VALUE;
		static int STENCIL_FAIL;
		static int STENCIL_FUNC;
		static int STENCIL_INDEX;
		static int STENCIL_INDEX8;
		static int STENCIL_PASS_DEPTH_FAIL;
		static int STENCIL_PASS_DEPTH_PASS;
		static int STENCIL_REF;
		static int STENCIL_TEST;
		static int STENCIL_VALUE_MASK;
		static int STENCIL_WRITEMASK;
		static int STREAM_DRAW;
		static int SUBPIXEL_BITS;
		static int TEXTURE;
		static int TEXTURE0;
		static int TEXTURE1;
		static int TEXTURE10;
		static int TEXTURE11;
		static int TEXTURE12;
		static int TEXTURE13;
		static int TEXTURE14;
		static int TEXTURE15;
		static int TEXTURE16;
		static int TEXTURE17;
		static int TEXTURE18;
		static int TEXTURE19;
		static int TEXTURE2;
		static int TEXTURE20;
		static int TEXTURE21;
		static int TEXTURE22;
		static int TEXTURE23;
		static int TEXTURE24;
		static int TEXTURE25;
		static int TEXTURE26;
		static int TEXTURE27;
		static int TEXTURE28;
		static int TEXTURE29;
		static int TEXTURE3;
		static int TEXTURE30;
		static int TEXTURE31;
		static int TEXTURE4;
		static int TEXTURE5;
		static int TEXTURE6;
		static int TEXTURE7;
		static int TEXTURE8;
		static int TEXTURE9;
		static int TEXTURE_2D;
		static int TEXTURE_BINDING_2D;
		static int TEXTURE_BINDING_CUBE_MAP;
		static int TEXTURE_CUBE_MAP;
		static int TEXTURE_CUBE_MAP_NEGATIVE_X;
		static int TEXTURE_CUBE_MAP_NEGATIVE_Y;
		static int TEXTURE_CUBE_MAP_NEGATIVE_Z;
		static int TEXTURE_CUBE_MAP_POSITIVE_X;
		static int TEXTURE_CUBE_MAP_POSITIVE_Y;
		static int TEXTURE_CUBE_MAP_POSITIVE_Z;
		static int TEXTURE_MAG_FILTER;
		static int TEXTURE_MIN_FILTER;
		static int TEXTURE_WRAP_S;
		static int TEXTURE_WRAP_T;
		static int TRIANGLES;
		static int TRIANGLE_FAN;
		static int TRIANGLE_STRIP;
		static int UNPACK_ALIGNMENT;
		static int UNPACK_COLORSPACE_CONVERSION_WEBGL;
		static int UNPACK_FLIP_Y_WEBGL;
		static int UNPACK_PREMULTIPLY_ALPHA_WEBGL;
		static int UNSIGNED_BYTE;
		static int UNSIGNED_INT;
		static int UNSIGNED_SHORT;
		static int UNSIGNED_SHORT_4_4_4_4;
		static int UNSIGNED_SHORT_5_5_5_1;
		static int UNSIGNED_SHORT_5_6_5;
		static int VALIDATE_STATUS;
		static int VENDOR;
		static int VERSION;
		static int VERTEX_ATTRIB_ARRAY_BUFFER_BINDING;
		static int VERTEX_ATTRIB_ARRAY_ENABLED;
		static int VERTEX_ATTRIB_ARRAY_NORMALIZED;
		static int VERTEX_ATTRIB_ARRAY_POINTER;
		static int VERTEX_ATTRIB_ARRAY_SIZE;
		static int VERTEX_ATTRIB_ARRAY_STRIDE;
		static int VERTEX_ATTRIB_ARRAY_TYPE;
		static int VERTEX_SHADER;
		static int VIEWPORT;
		static int ZERO;
		static int _NULL;
		static ::haxor::platform::graphics::GraphicAPI get_api( );
		static Dynamic get_api_dyn();

		static ::haxor::platform::graphics::OpenGL m_gl;
		static Void Initialize( ::haxor::core::BaseApplication p_application);
		static Dynamic Initialize_dyn();

		static Void Resize( );
		static Dynamic Resize_dyn();

		static Void BindBuffer( int p_target,int p_id);
		static Dynamic BindBuffer_dyn();

		static Void BufferData( int p_target,::haxor::io::Buffer p_data,int p_mode);
		static Dynamic BufferData_dyn();

		static Void BufferSubData( int p_target,int p_offset,::haxor::io::Buffer p_data);
		static Dynamic BufferSubData_dyn();

		static int CreateBuffer( );
		static Dynamic CreateBuffer_dyn();

		static Void DrawArrays( int p_primitive,int p_start,int p_count);
		static Dynamic DrawArrays_dyn();

		static Void DrawElements( int p_primitive,int p_count,int p_type,int p_offset);
		static Dynamic DrawElements_dyn();

		static Void DeleteBuffer( int p_id);
		static Dynamic DeleteBuffer_dyn();

		static Void DisableVertexAttrib( int p_location);
		static Dynamic DisableVertexAttrib_dyn();

		static Void EnableVertexAttrib( int p_location);
		static Dynamic EnableVertexAttrib_dyn();

		static Void VertexAttrib3f( int p_location,Float p_x,Float p_y,Float p_z);
		static Dynamic VertexAttrib3f_dyn();

		static Void VertexAttrib4f( int p_location,Float p_x,Float p_y,Float p_z,Float p_w);
		static Dynamic VertexAttrib4f_dyn();

		static Void VertexAttribPointer( int p_location,int p_components_size,int p_type,bool p_normalized,int p_stride,int p_offset);
		static Dynamic VertexAttribPointer_dyn();

		static Void CompileShader( int p_shader);
		static Dynamic CompileShader_dyn();

		static int CreateShader( int p_type);
		static Dynamic CreateShader_dyn();

		static Void DetachShader( int p_program,int p_shader);
		static Dynamic DetachShader_dyn();

		static Void DeleteShader( int p_shader);
		static Dynamic DeleteShader_dyn();

		static ::String GetShaderInfoLog( int p_shader);
		static Dynamic GetShaderInfoLog_dyn();

		static int GetShaderParameter( int p_shader,int p_parameter);
		static Dynamic GetShaderParameter_dyn();

		static Void ShaderSource( int p_shader,::String p_source);
		static Dynamic ShaderSource_dyn();

		static Void AttachShader( int p_program,int p_shader);
		static Dynamic AttachShader_dyn();

		static Void BindAttribLocation( int p_program,int p_location,::String p_name);
		static Dynamic BindAttribLocation_dyn();

		static int CreateProgram( );
		static Dynamic CreateProgram_dyn();

		static Void DeleteProgram( int p_program);
		static Dynamic DeleteProgram_dyn();

		static int GetAttribLocation( int p_program,::String p_name);
		static Dynamic GetAttribLocation_dyn();

		static ::String GetProgramInfoLog( int p_program);
		static Dynamic GetProgramInfoLog_dyn();

		static int GetProgramParameter( int p_program,int p_parameter);
		static Dynamic GetProgramParameter_dyn();

		static Void LinkProgram( int p_program);
		static Dynamic LinkProgram_dyn();

		static Void UseProgram( int p_program);
		static Dynamic UseProgram_dyn();

		static Void BlendFunc( int p_src,int p_dst);
		static Dynamic BlendFunc_dyn();

		static Void Disable( int p_flag);
		static Dynamic Disable_dyn();

		static Void Enable( int p_flag);
		static Dynamic Enable_dyn();

		static Void DepthMask( bool p_flag);
		static Dynamic DepthMask_dyn();

		static Void DepthFunc( int p_flag);
		static Dynamic DepthFunc_dyn();

		static Void CullFace( int p_face);
		static Dynamic CullFace_dyn();

		static Void FrontFace( int p_face);
		static Dynamic FrontFace_dyn();

		static Void Clear( int p_flag);
		static Dynamic Clear_dyn();

		static Void ClearDepth( Float p_value);
		static Dynamic ClearDepth_dyn();

		static Void ClearColor( Float p_r,Float p_g,Float p_b,Float p_a);
		static Dynamic ClearColor_dyn();

		static ::String GetError( );
		static Dynamic GetError_dyn();

		static int GetErrorCode( );
		static Dynamic GetErrorCode_dyn();

		static ::String GetErrorString( int p_code);
		static Dynamic GetErrorString_dyn();

		static Void LogError( );
		static Dynamic LogError_dyn();

		static Void Assert( ::String p_log);
		static Dynamic Assert_dyn();

		static Void Flush( );
		static Dynamic Flush_dyn();

		static Void Focus( );
		static Dynamic Focus_dyn();

};

} // end namespace haxor
} // end namespace platform
} // end namespace graphics

#endif /* INCLUDED_haxor_platform_graphics_GL */ 
