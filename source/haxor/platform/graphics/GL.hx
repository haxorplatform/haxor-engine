package haxor.platform.graphics;
import haxor.context.EngineContext;
import haxor.core.BaseApplication;
import haxor.io.Buffer;
import haxor.platform.graphics.GraphicContext.GraphicAPI;
import haxor.platform.Types.ArrayBuffer;
import haxor.platform.Types.MeshBufferId;
import haxor.platform.Types.ProgramId;
import haxor.platform.Types.ShaderId;

#if html
typedef PlatformGL  = WebGL;
#end

#if android
 typedef PlatformGL = AndroidGL;
#end

#if windows
typedef PlatformGL  =  OpenGL;
#end


/**
 * Class that describes the low-level commands of the Graphics Library of the chosen platform.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class GL
{
	static public inline var ACTIVE_ATTRIBUTES : Int = 0x8B89;
	static public inline var ACTIVE_TEXTURE : Int = 0x84E0;
	static public inline var ACTIVE_UNIFORMS : Int = 0x8B86;
	static public inline var ALIASED_LINE_WIDTH_RANGE : Int = 0x846E;
	static public inline var ALIASED_POINT_SIZE_RANGE : Int = 0x846D;
	static public inline var ALPHA : Int = 0x1906;
	static public inline var ALPHA_BITS : Int = 0x0D55;
	static public inline var ALWAYS : Int = 0x0207;
	static public inline var ARRAY_BUFFER : Int = 0x8892;
	static public inline var ARRAY_BUFFER_BINDING : Int = 0x8894;
	static public inline var ATTACHED_SHADERS : Int = 0x8B85;
	static public inline var BACK : Int = 0x0405;
	static public inline var BLEND : Int = 0x0BE2;
	static public inline var BLEND_COLOR : Int = 0x8005;
	static public inline var BLEND_DST_ALPHA : Int = 0x80CA;
	static public inline var BLEND_DST_RGB : Int = 0x80C8;
	static public inline var BLEND_EQUATION : Int = 0x8009;
	static public inline var BLEND_EQUATION_ALPHA : Int = 0x883D;
	static public inline var BLEND_EQUATION_RGB : Int = 0x8009;
	static public inline var BLEND_SRC_ALPHA : Int = 0x80CB;
	static public inline var BLEND_SRC_RGB : Int = 0x80C9;
	static public inline var BLUE_BITS : Int = 0x0D54;
	static public inline var BOOL : Int = 0x8B56;
	static public inline var BOOL_VEC2 : Int = 0x8B57;
	static public inline var BOOL_VEC3 : Int = 0x8B58;
	static public inline var BOOL_VEC4 : Int = 0x8B59;
	static public inline var BROWSER_DEFAULT_WEBGL : Int = 0x9244;
	static public inline var BUFFER_SIZE : Int = 0x8764;
	static public inline var BUFFER_USAGE : Int = 0x8765;
	static public inline var BYTE : Int = 0x1400;
	static public inline var CCW : Int = 0x0901;
	static public inline var CLAMP_TO_EDGE : Int = 0x812F;
	static public inline var COLOR_ATTACHMENT0 : Int = 0x8CE0;
	static public inline var COLOR_BUFFER_BIT : Int = 0x00004000;
	static public inline var COLOR_CLEAR_VALUE : Int = 0x0C22;
	static public inline var COLOR_WRITEMASK : Int = 0x0C23;
	static public inline var COMPILE_STATUS : Int = 0x8B81;
	static public inline var COMPRESSED_TEXTURE_FORMATS : Int = 0x86A3;
	static public inline var CONSTANT_ALPHA : Int = 0x8003;
	static public inline var CONSTANT_COLOR : Int = 0x8001;
	static public inline var CONTEXT_LOST_WEBGL : Int = 0x9242;
	static public inline var CULL_FACE : Int = 0x0B44;
	static public inline var CULL_FACE_MODE : Int = 0x0B45;
	static public inline var CURRENT_PROGRAM : Int = 0x8B8D;
	static public inline var CURRENT_VERTEX_ATTRIB : Int = 0x8626;
	static public inline var CW : Int = 0x0900;
	static public inline var DECR : Int = 0x1E03;
	static public inline var DECR_WRAP : Int = 0x8508;
	static public inline var DELETE_STATUS : Int = 0x8B80;
	static public inline var DEPTH_ATTACHMENT : Int = 0x8D00;
	static public inline var DEPTH_BITS : Int = 0x0D56;
	static public inline var DEPTH_BUFFER_BIT : Int = 0x00000100;
	static public inline var DEPTH_CLEAR_VALUE : Int = 0x0B73;
	static public inline var DEPTH_COMPONENT : Int = 0x1902;
	static public inline var DEPTH_COMPONENT16 : Int = 0x81A5;
	static public inline var DEPTH_FUNC : Int = 0x0B74;
	static public inline var DEPTH_RANGE : Int = 0x0B70;
	static public inline var DEPTH_STENCIL : Int = 0x84F9;
	static public inline var DEPTH_STENCIL_ATTACHMENT : Int = 0x821A;
	static public inline var DEPTH_TEST : Int = 0x0B71;
	static public inline var DEPTH_WRITEMASK : Int = 0x0B72;
	static public inline var DITHER : Int = 0x0BD0;
	static public inline var DONT_CARE : Int = 0x1100;
	static public inline var DST_ALPHA : Int = 0x0304;
	static public inline var DST_COLOR : Int = 0x0306;
	static public inline var DYNAMIC_DRAW : Int = 0x88E8;	
	static public inline var ELEMENT_ARRAY_BUFFER : Int = 0x8893;
	static public inline var ELEMENT_ARRAY_BUFFER_BINDING : Int = 0x8895;
	static public inline var EQUAL : Int = 0x0202;
	static public inline var FASTEST : Int = 0x1101;
	static public inline var FLOAT : Int = 0x1406;
	static public inline var FLOAT_MAT2 : Int = 0x8B5A;
	static public inline var FLOAT_MAT3 : Int = 0x8B5B;
	static public inline var FLOAT_MAT4 : Int = 0x8B5C;
	static public inline var FLOAT_VEC2 : Int = 0x8B50;
	static public inline var FLOAT_VEC3 : Int = 0x8B51;
	static public inline var FLOAT_VEC4 : Int = 0x8B52;
	static public inline var FRAGMENT_SHADER : Int = 0x8B30;
	static public inline var FRAMEBUFFER : Int = 0x8D40;
	static public inline var FRAMEBUFFER_ATTACHMENT_OBJECT_NAME : Int = 0x8CD1;
	static public inline var FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE : Int = 0x8CD0;
	static public inline var FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE : Int = 0x8CD3;
	static public inline var FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL : Int = 0x8CD2;
	static public inline var FRAMEBUFFER_BINDING : Int = 0x8CA6;
	static public inline var FRAMEBUFFER_COMPLETE : Int = 0x8CD5;
	static public inline var FRAMEBUFFER_INCOMPLETE_ATTACHMENT : Int = 0x8CD6;
	static public inline var FRAMEBUFFER_INCOMPLETE_DIMENSIONS : Int = 0x8CD9;
	static public inline var FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT : Int = 0x8CD7;
	static public inline var FRAMEBUFFER_UNSUPPORTED : Int = 0x8CDD;
	static public inline var FRONT : Int = 0x0404;
	static public inline var FRONT_AND_BACK : Int = 0x0408;
	static public inline var FRONT_FACE : Int = 0x0B46;
	static public inline var FUNC_ADD : Int = 0x8006;
	static public inline var FUNC_REVERSE_SUBTRACT : Int = 0x800B;
	static public inline var FUNC_SUBTRACT : Int = 0x800A;
	static public inline var GENERATE_MIPMAP_HINT : Int = 0x8192;
	static public inline var GEQUAL : Int = 0x0206;
	static public inline var GREATER : Int = 0x0204;
	static public inline var GREEN_BITS : Int = 0x0D53;
	static public inline var HIGH_FLOAT : Int = 0x8DF2;
	static public inline var HIGH_INT : Int = 0x8DF5;
	static public inline var INCR : Int = 0x1E02;
	static public inline var INCR_WRAP : Int = 0x8507;
	static public inline var INT : Int = 0x1404;
	static public inline var INT_VEC2 : Int = 0x8B53;
	static public inline var INT_VEC3 : Int = 0x8B54;
	static public inline var INT_VEC4 : Int = 0x8B55;
	static public inline var INVALID_ENUM : Int = 0x0500;
	static public inline var INVALID_FRAMEBUFFER_OPERATION : Int = 0x0506;
	static public inline var INVALID_OPERATION : Int = 0x0502;
	static public inline var INVALID_VALUE : Int = 0x0501;
	static public inline var INVERT : Int = 0x150A;
	static public inline var KEEP : Int = 0x1E00;
	static public inline var LEQUAL : Int = 0x0203;
	static public inline var LESS : Int = 0x0201;
	static public inline var LINEAR : Int = 0x2601;
	static public inline var LINEAR_MIPMAP_LINEAR : Int = 0x2703;
	static public inline var LINEAR_MIPMAP_NEAREST : Int = 0x2701;
	static public inline var LINES : Int = 0x0001;
	static public inline var LINE_LOOP : Int = 0x0002;
	static public inline var LINE_STRIP : Int = 0x0003;
	static public inline var LINE_WIDTH : Int = 0x0B21;
	static public inline var LINK_STATUS : Int = 0x8B82;
	static public inline var LOW_FLOAT : Int = 0x8DF0;
	static public inline var LOW_INT : Int = 0x8DF3;
	static public inline var LUMINANCE : Int = 0x1909;
	static public inline var LUMINANCE_ALPHA : Int = 0x190A;
	static public inline var MAX_COMBINED_TEXTURE_IMAGE_UNITS : Int = 0x8B4D;
	static public inline var MAX_CUBE_MAP_TEXTURE_SIZE : Int = 0x851C;
	static public inline var MAX_FRAGMENT_UNIFORM_VECTORS : Int = 0x8DFD;
	static public inline var MAX_RENDERBUFFER_SIZE : Int = 0x84E8;
	static public inline var MAX_TEXTURE_IMAGE_UNITS : Int = 0x8872;
	static public inline var MAX_TEXTURE_SIZE : Int = 0x0D33;
	static public inline var MAX_VARYING_VECTORS : Int = 0x8DFC;
	static public inline var MAX_VERTEX_ATTRIBS : Int = 0x8869;
	static public inline var MAX_VERTEX_TEXTURE_IMAGE_UNITS : Int = 0x8B4C;
	static public inline var MAX_VERTEX_UNIFORM_VECTORS : Int = 0x8DFB;
	static public inline var MAX_VIEWPORT_DIMS : Int = 0x0D3A;
	static public inline var MEDIUM_FLOAT : Int = 0x8DF1;
	static public inline var MEDIUM_INT : Int = 0x8DF4;
	static public inline var MIRRORED_REPEAT : Int = 0x8370;
	static public inline var NEAREST : Int = 0x2600;
	static public inline var NEAREST_MIPMAP_LINEAR : Int = 0x2702;
	static public inline var NEAREST_MIPMAP_NEAREST : Int = 0x2700;
	static public inline var NEVER : Int = 0x0200;
	static public inline var NICEST : Int = 0x1102;
	static public inline var NONE : Int = 0;
	static public inline var NOTEQUAL : Int = 0x0205;
	static public inline var NO_ERROR_GL : Int = 0; //Renamed for CPP platforms (conflict with something!)
	static public inline var ONE : Int = 1;
	static public inline var ONE_MINUS_CONSTANT_ALPHA : Int = 0x8004;
	static public inline var ONE_MINUS_CONSTANT_COLOR : Int = 0x8002;
	static public inline var ONE_MINUS_DST_ALPHA : Int = 0x0305;
	static public inline var ONE_MINUS_DST_COLOR : Int = 0x0307;
	static public inline var ONE_MINUS_SRC_ALPHA : Int = 0x0303;
	static public inline var ONE_MINUS_SRC_COLOR : Int = 0x0301;
	static public inline var OUT_OF_MEMORY : Int = 0x0505;
	static public inline var PACK_ALIGNMENT : Int = 0x0D05;
	static public inline var POINTS : Int = 0x0000;
	static public inline var POLYGON_OFFSET_FACTOR : Int = 0x8038;
	static public inline var POLYGON_OFFSET_FILL : Int = 0x8037;
	static public inline var POLYGON_OFFSET_UNITS : Int = 0x2A00;
	static public inline var RED_BITS : Int = 0x0D52;
	static public inline var RENDERBUFFER : Int = 0x8D41;
	static public inline var RENDERBUFFER_ALPHA_SIZE : Int = 0x8D53;
	static public inline var RENDERBUFFER_BINDING : Int = 0x8CA7;
	static public inline var RENDERBUFFER_BLUE_SIZE : Int = 0x8D52;
	static public inline var RENDERBUFFER_DEPTH_SIZE : Int = 0x8D54;
	static public inline var RENDERBUFFER_GREEN_SIZE : Int = 0x8D51;
	static public inline var RENDERBUFFER_HEIGHT : Int = 0x8D43;
	static public inline var RENDERBUFFER_INTERNAL_FORMAT : Int = 0x8D44;
	static public inline var RENDERBUFFER_RED_SIZE : Int = 0x8D50;
	static public inline var RENDERBUFFER_STENCIL_SIZE : Int = 0x8D55;
	static public inline var RENDERBUFFER_WIDTH : Int = 0x8D42;
	static public inline var RENDERER : Int = 0x1F01;
	static public inline var REPEAT : Int = 0x2901;
	static public inline var REPLACE : Int = 0x1E01;
	static public inline var RGB : Int = 0x1907;
	static public inline var RGB565 : Int = 0x8D62;
	static public inline var RGB5_A1 : Int = 0x8057;
	static public inline var RGBA : Int = 0x1908;
	static public inline var RGBA4 : Int = 0x8056;
	static public inline var SAMPLER_2D : Int = 0x8B5E;
	static public inline var SAMPLER_CUBE : Int = 0x8B60;
	static public inline var SAMPLES : Int = 0x80A9;
	static public inline var SAMPLE_ALPHA_TO_COVERAGE : Int = 0x809E;
	static public inline var SAMPLE_BUFFERS : Int = 0x80A8;
	static public inline var SAMPLE_COVERAGE : Int = 0x80A0;
	static public inline var SAMPLE_COVERAGE_INVERT : Int = 0x80AB;
	static public inline var SAMPLE_COVERAGE_VALUE : Int = 0x80AA;
	static public inline var SCISSOR_BOX : Int = 0x0C10;
	static public inline var SCISSOR_TEST : Int = 0x0C11;
	static public inline var SHADER_TYPE : Int = 0x8B4F;
	static public inline var SHADING_LANGUAGE_VERSION : Int = 0x8B8C;
	static public inline var SHORT : Int = 0x1402;
	static public inline var SRC_ALPHA : Int = 0x0302;
	static public inline var SRC_ALPHA_SATURATE : Int = 0x0308;
	static public inline var SRC_COLOR : Int = 0x0300;
	static public inline var STATIC_DRAW : Int = 0x88E4;
	static public inline var STENCIL_ATTACHMENT : Int = 0x8D20;
	static public inline var STENCIL_BACK_FAIL : Int = 0x8801;
	static public inline var STENCIL_BACK_FUNC : Int = 0x8800;
	static public inline var STENCIL_BACK_PASS_DEPTH_FAIL : Int = 0x8802;
	static public inline var STENCIL_BACK_PASS_DEPTH_PASS : Int = 0x8803;
	static public inline var STENCIL_BACK_REF : Int = 0x8CA3;
	static public inline var STENCIL_BACK_VALUE_MASK : Int = 0x8CA4;
	static public inline var STENCIL_BACK_WRITEMASK : Int = 0x8CA5;
	static public inline var STENCIL_BITS : Int = 0x0D57;
	static public inline var STENCIL_BUFFER_BIT : Int = 0x00000400;
	static public inline var STENCIL_CLEAR_VALUE : Int = 0x0B91;
	static public inline var STENCIL_FAIL : Int = 0x0B94;
	static public inline var STENCIL_FUNC : Int = 0x0B92;
	static public inline var STENCIL_INDEX : Int = 0x1901;
	static public inline var STENCIL_INDEX8 : Int = 0x8D48;
	static public inline var STENCIL_PASS_DEPTH_FAIL : Int = 0x0B95;
	static public inline var STENCIL_PASS_DEPTH_PASS : Int = 0x0B96;
	static public inline var STENCIL_REF : Int = 0x0B97;
	static public inline var STENCIL_TEST : Int = 0x0B90;
	static public inline var STENCIL_VALUE_MASK : Int = 0x0B93;
	static public inline var STENCIL_WRITEMASK : Int = 0x0B98;
	static public inline var STREAM_DRAW : Int = 0x88E0;
	static public inline var SUBPIXEL_BITS : Int = 0x0D50;
	static public inline var TEXTURE : Int = 0x1702;
	static public inline var TEXTURE0 : Int = 0x84C0;
	static public inline var TEXTURE1 : Int = 0x84C1;
	static public inline var TEXTURE10 : Int = 0x84CA;
	static public inline var TEXTURE11 : Int = 0x84CB;
	static public inline var TEXTURE12 : Int = 0x84CC;
	static public inline var TEXTURE13 : Int = 0x84CD;
	static public inline var TEXTURE14 : Int = 0x84CE;
	static public inline var TEXTURE15 : Int = 0x84CF;
	static public inline var TEXTURE16 : Int = 0x84D0;
	static public inline var TEXTURE17 : Int = 0x84D1;
	static public inline var TEXTURE18 : Int = 0x84D2;
	static public inline var TEXTURE19 : Int = 0x84D3;
	static public inline var TEXTURE2 : Int = 0x84C2;
	static public inline var TEXTURE20 : Int = 0x84D4;
	static public inline var TEXTURE21 : Int = 0x84D5;
	static public inline var TEXTURE22 : Int = 0x84D6;
	static public inline var TEXTURE23 : Int = 0x84D7;
	static public inline var TEXTURE24 : Int = 0x84D8;
	static public inline var TEXTURE25 : Int = 0x84D9;
	static public inline var TEXTURE26 : Int = 0x84DA;
	static public inline var TEXTURE27 : Int = 0x84DB;
	static public inline var TEXTURE28 : Int = 0x84DC;
	static public inline var TEXTURE29 : Int = 0x84DD;
	static public inline var TEXTURE3 : Int = 0x84C3;
	static public inline var TEXTURE30 : Int = 0x84DE;
	static public inline var TEXTURE31 : Int = 0x84DF;
	static public inline var TEXTURE4 : Int = 0x84C4;
	static public inline var TEXTURE5 : Int = 0x84C5;
	static public inline var TEXTURE6 : Int = 0x84C6;
	static public inline var TEXTURE7 : Int = 0x84C7;
	static public inline var TEXTURE8 : Int = 0x84C8;
	static public inline var TEXTURE9 : Int = 0x84C9;
	static public inline var TEXTURE_2D : Int = 0x0DE1;
	static public inline var TEXTURE_BINDING_2D : Int = 0x8069;
	static public inline var TEXTURE_BINDING_CUBE_MAP : Int = 0x8514;	
	static public inline var TEXTURE_CUBE_MAP : Int = 0x8513;
	static public inline var TEXTURE_CUBE_MAP_NEGATIVE_X : Int = 0x8516;
	static public inline var TEXTURE_CUBE_MAP_NEGATIVE_Y : Int = 0x8518;
	static public inline var TEXTURE_CUBE_MAP_NEGATIVE_Z : Int = 0x851A;
	static public inline var TEXTURE_CUBE_MAP_POSITIVE_X : Int = 0x8515;
	static public inline var TEXTURE_CUBE_MAP_POSITIVE_Y : Int = 0x8517;
	static public inline var TEXTURE_CUBE_MAP_POSITIVE_Z : Int = 0x8519;
	static public inline var TEXTURE_MAG_FILTER : Int = 0x2800;
	static public inline var TEXTURE_MIN_FILTER : Int = 0x2801;
	static public inline var TEXTURE_WRAP_S : Int = 0x2802;
	static public inline var TEXTURE_WRAP_T : Int = 0x2803;
	static public inline var TRIANGLES : Int = 0x0004;
	static public inline var TRIANGLE_FAN : Int = 0x0006;
	static public inline var TRIANGLE_STRIP : Int = 0x0005;
	static public inline var UNPACK_ALIGNMENT : Int = 0x0CF5;
	static public inline var UNPACK_COLORSPACE_CONVERSION_WEBGL : Int = 0x9243;
	static public inline var UNPACK_FLIP_Y_WEBGL : Int = 0x9240;
	static public inline var UNPACK_PREMULTIPLY_ALPHA_WEBGL : Int = 0x9241;
	static public inline var UNSIGNED_BYTE : Int = 0x1401;
	static public inline var UNSIGNED_INT : Int = 0x1405;
	static public inline var UNSIGNED_SHORT : Int = 0x1403;
	static public inline var UNSIGNED_SHORT_4_4_4_4 : Int = 0x8033;
	static public inline var UNSIGNED_SHORT_5_5_5_1 : Int = 0x8034;
	static public inline var UNSIGNED_SHORT_5_6_5 : Int = 0x8363;
	static public inline var VALIDATE_STATUS : Int = 0x8B83;
	static public inline var VENDOR : Int = 0x1F00;
	static public inline var VERSION : Int = 0x1F02;
	static public inline var VERTEX_ATTRIB_ARRAY_BUFFER_BINDING : Int = 0x889F;
	static public inline var VERTEX_ATTRIB_ARRAY_ENABLED : Int = 0x8622;
	static public inline var VERTEX_ATTRIB_ARRAY_NORMALIZED : Int = 0x886A;
	static public inline var VERTEX_ATTRIB_ARRAY_POINTER : Int = 0x8645;
	static public inline var VERTEX_ATTRIB_ARRAY_SIZE : Int = 0x8623;
	static public inline var VERTEX_ATTRIB_ARRAY_STRIDE : Int = 0x8624;
	static public inline var VERTEX_ATTRIB_ARRAY_TYPE : Int = 0x8625;
	static public inline var VERTEX_SHADER : Int = 0x8B31;
	static public inline var VIEWPORT : Int = 0x0BA2;
	static public inline var ZERO : Int = 0;
	
	/**
	 * Invalid Id per platform.
	 */
	#if html
	static public var NULL : Dynamic = null;
	#else		
	static public var NULL : Int = -1;
	#end
	
	/**
	 * Flag that indicates the running API of the graphic context.
	 */
	static public var api(get_api,never) : GraphicAPI;	
	static private inline function get_api():GraphicAPI { return m_gl.api; }
	
	
	/**
	 * Reference to the GL for the choosen platform.
	 */
	static private var m_gl : PlatformGL;
	
	/**
	 * Initializes the lowlevel graphic library.
	 * @param	p_application
	 */
	static function Initialize(p_application : BaseApplication):Void
	{
		m_gl = new PlatformGL(p_application);		
		m_gl.CheckExtensions();		
	}
	
	/**
	 * Resizes the internall structures (e.g. canvas resize in html)
	 */
	static inline function Resize():Void {	m_gl.Resize(); }
	
	//=========== Buffer ===========
	
	/**
	 * Activates a Buffer for manipulation or use.
	 * @param	p_target
	 * @param	p_id
	 */
	static public inline function BindBuffer(p_target : Int,p_id : MeshBufferId):Void { m_gl.BindBuffer(p_target, p_id); }
	
	/**
	 * Uploads the data from a Buffer to the GPU.
	 * @param	p_id
	 * @param	p_mode
	 * @param	p_data
	 */
	static public inline function BufferData(p_target:Int,p_data:Buffer,p_mode:Int):Void { m_gl.BufferData(p_target, p_data,p_mode); }
	
	/**
	 * Uploads the data from a buffer, filling a part of the GPU memory, starting at offset with the specified size.
	 * @param	p_id
	 * @param	p_offset
	 * @param	p_size
	 * @param	p_data
	 */
	static public inline function BufferSubData(p_target:Int, p_offset : Int,p_data : Buffer):Void { m_gl.BufferSubData(p_target, p_offset, p_data); }
		
	/**
	 * Creates a buffer identifier.
	 * @param	p_id
	 */
	static public inline function CreateBuffer():MeshBufferId { return m_gl.CreateBuffer(); }
	
	/**
	 * Draws non-indexed primitives of the bound bufffer.
	 * @param	p_primitive
	 * @param	p_start
	 * @param	p_count
	 */
	static public inline function DrawArrays(p_primitive:Int, p_start:Int, p_count:Int) : Void { m_gl.DrawArrays(p_primitive, p_start, p_count); }
	
	/**
	 * Draws indexed primitives of the bound buffer.
	 * @param	p_primitive
	 * @param	p_count
	 * @param	p_type
	 * @param	p_offset
	 */
	static public inline function DrawElements(p_primitive:Int, p_count:Int, p_type:Int, p_offset:Int) : Void { m_gl.DrawElements(p_primitive,p_count,p_type,p_offset); }
	
	/**
	 * Removes a mesh attribute buffer from GPU memory.
	 * @param	p_id
	 */
	static public inline function DeleteBuffer(p_id : MeshBufferId):Void { m_gl.DeleteBuffer(p_id); }
	
	/**
	 * Enables the use of a vertex attribute at a given location.
	 * @param	p_location
	 */
	static public inline function DisableVertexAttrib(p_location:Int):Void { m_gl.DisableVertexAttrib(p_location); }
	
	/**
	 * Enables the use of a vertex attribute at a given location.
	 * @param	p_location
	 */
	static public inline function EnableVertexAttrib(p_location : Int):Void { m_gl.EnableVertexAttrib(p_location); }
	
	/**
	 * Describes a buffer attribute in a given location as a single 3-float vector.
	 * @param	p_location
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 */
	static public inline function VertexAttrib3f(p_location : Int, p_x : Float, p_y:Float, p_z : Float):Void { m_gl.VertexAttrib3f(p_location, p_x, p_y, p_z); }
	
	/**
	 * Describes a buffer attribute in a given location as a single 3-float vector.
	 * @param	p_location
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 */
	static public inline function VertexAttrib4f(p_location : Int, p_x : Float, p_y:Float, p_z : Float, p_w : Float):Void { m_gl.VertexAttrib4f(p_location, p_x, p_y, p_z,p_w); }
	
	/**
	 * Describes given buffer attribute components type (float,int,...), how it will be treated (x,xy,xyz,...) and its location in the shader scope.
	 * @param	p_index
	 * @param	p_size
	 * @param	p_type
	 * @param	p_normalized
	 * @param	p_stride
	 * @param	p_offset
	 */
	static public inline function VertexAttribPointer(p_location : Int, p_components_size : Int, p_type : Int, p_normalized : Bool, p_stride : Int, p_offset : Int):Void { m_gl.VertexAttribPointer(p_location, p_components_size, p_type, p_normalized, p_stride, p_offset); }
	
	//=========== Buffer ===========
	
	
	//=========== Shader ===========
	
	/**
	 * Compiles the bound shader.
	 * @param	p_shader
	 */
	static public inline function CompileShader(p_shader : ShaderId):Void { m_gl.CompileShader(p_shader); }	
	
	/**
	 * Creates a shader of a given type (VERTEX_SHADER or FRAGMENT_SHADER).
	 * @param	p_type
	 * @return
	 */
	static public inline function CreateShader(p_type:Int):ShaderId { return m_gl.CreateShader(p_type); }
	
	/**
	 * Detaches a shader from a Program.
	 * @param	p_program
	 * @param	p_shader
	 */
	static public inline function DetachShader (p_program : ProgramId, p_shader : ShaderId):Void { m_gl.DetachShader(p_program, p_shader); }
	
	/**
	 * Deletes a shader from the GL api.
	 * @param	p_shader
	 */
	static public inline function DeleteShader(p_shader : ShaderId):Void { m_gl.DeleteShader(p_shader); }	
	
	/**
	 * Retrieves the log information of a given Shader operation.
	 * @param	p_shader
	 * @return
	 */
	static public inline function GetShaderInfoLog(p_shader : ShaderId) : String { return m_gl.GetShaderInfoLog(p_shader); }	
	
	/**
	 * Returns a given parameter data from the bound shader.
	 * @param	p_shader
	 * @param	p_parameter
	 * @return
	 */
	static public inline function GetShaderParameter(p_shader : ShaderId, p_parameter:Int):Int { return m_gl.GetShaderParameter(p_shader, p_parameter); }
	
	/**
	 * Associates a shader's source string to the shader in the API memory.
	 * @param	p_shader
	 * @param	p_source
	 */
	static public inline function ShaderSource(p_shader : ShaderId, p_source : String):Void { m_gl.ShaderSource(p_shader, p_source); }
	
	/**
	 * Attachs a shader to the passed program.
	 * @param	p_program
	 * @param	p_shader
	 */
	static public inline function AttachShader(p_program : ProgramId, p_shader : ShaderId):Void { m_gl.AttachShader(p_program, p_shader); }
	
	/**
	 * Specifies the location integer that a given shader Attribute will be located.
	 * @param	p_program
	 * @param	p_location
	 * @param	p_name
	 */
	static public inline function BindAttribLocation(p_program : ProgramId, p_location : Int, p_name : String):Void { m_gl.BindAttribLocation(p_program, p_location, p_name); }		
	
	/**
	 * Creates a Program which will hold the Vertex and Fragment shader context.
	 * @return
	 */
	static public inline function CreateProgram():ProgramId { return m_gl.CreateProgram(); }	
	
	/**
	 * Destroys the reference of a Program.
	 * @param	p_program
	 */
	static public inline function DeleteProgram(p_program : ProgramId):Void { m_gl.DeleteProgram(p_program); } 	
	
	/**
	 * Searches for the location address of a given attribute in a shader. Returns -1 if none is found.
	 * @param	p_program
	 * @param	p_name
	 * @return
	 */
	static public inline function GetAttribLocation(p_program : ProgramId, p_name : String):Int { return m_gl.GetAttribLocation(p_program,p_name); } 
	
	/**
	 * Returns log information of the last operation made by the Program. This method can report errors in the Link, Attach and other API commands.
	 * @param	p_program
	 * @return
	 */
	static public inline function GetProgramInfoLog(p_program : ProgramId):String { return m_gl.GetProgramInfoLog(p_program); }
	
	/**
	 * Returns a given parameter data from the passed program.
	 * @param	p_program
	 * @param	p_parameter
	 * @return
	 */
	static public inline function GetProgramParameter(p_program : ProgramId, p_parameter:Int):Int { return m_gl.GetProgramParameter(p_program, p_parameter); }
	
	/**
	 * Links a program for usage.
	 * @param	p_program
	 */
	static public inline function LinkProgram(p_program:ProgramId):Void { m_gl.LinkProgram(p_program); }
	
	/**
	 * Activates a program and its shaders to be used in the frame.
	 * @param	p_program
	 */
	static public inline function UseProgram(p_program : ProgramId):Void { m_gl.UseProgram(p_program); }
	
	
	//=========== Shader ===========
	
	//=========== Flags ===========
	
	/**
	 * Sets the blending functions for Source and Destination pixels.
	 * @param	p_src
	 * @param	p_dst
	 */
	static public inline function BlendFunc(p_src : Int, p_dst : Int):Void { m_gl.BlendFunc(p_src, p_dst); }
	
	/**
	 * Disables a given API flag.
	 * @param	p_flag
	 */
	static public inline function Disable(p_flag : Int):Void { m_gl.Disable(p_flag); }
	
	/**
	 * Enables a given API flag;
	 * @param	p_flag
	 */
	static public inline function Enable(p_flag : Int):Void { m_gl.Enable(p_flag); }
	
	/**
	 * Enables or Disables Depth Write.
	 * @param	p_flag
	 */
	static public inline function DepthMask(p_flag : Bool):Void { m_gl.DepthMask(p_flag); }
	
	/**
	 * Sets the Depth Test operation.
	 * @param	p_flag
	 */
	static public inline function DepthFunc(p_flag : Int):Void { m_gl.DepthFunc(p_flag); }
	
	/**
	 * Sets which face will be culled.
	 * @param	p_face
	 */
	static public inline function CullFace(p_face : Int):Void { m_gl.CullFace(p_face); }
	
	/**
	 * Sets which face represents the front face of polygons.
	 * @param	p_face
	 */
	static public inline function FrontFace(p_face : Int):Void { m_gl.FrontFace(p_face); }
	
	//=========== Flags ===========
	
	//=========== Clear ===========
	
	/**
	 * Clears the Color and/or the Depth buffer.
	 * @param	p_flag
	 */
	static public inline function Clear(p_flag : Int):Void 		{ m_gl.Clear(p_flag); 	}	
	
	/**
	 * Sets the value that will be used to fill the Depth buffer.
	 * @param	p_value
	 */
	static public inline function ClearDepth(p_value : Float):Void { m_gl.ClearDepth(p_value);	}	
	
	/**
	 * Sets the color that will clear the Color buffer.
	 * @param	p_r
	 * @param	p_g
	 * @param	p_b
	 * @param	p_a
	 */
	static public inline function ClearColor(p_r: Float, p_g:Float, p_b:Float, p_a:Float):Void { m_gl.ClearColor(p_r, p_g, p_b, p_a); 	}
	
	//=========== Clear ===========
	
	//=========== Error ===========
	
	/**
	 * Returns the current Error String from the Graphics library.
	 * GL_NO_ERROR 							No error has been recorded. The value of this symbolic constant is guaranteed to be 0.
	 * GL_INVALID_ENUM 						An unacceptable value is specified for an enumerated argument. The offending command is ignored and has no other side effect than to set the error flag.
	 * GL_INVALID_VALUE 					A numeric argument is out of range. The offending command is ignored and has no other side effect than to set the error flag.
	 * GL_INVALID_OPERATION 				The specified operation is not allowed in the current state. The offending command is ignored and has no other side effect than to set the error flag.
	 * GL_INVALID_FRAMEBUFFER_OPERATION 	The command is trying to render to or read from the framebuffer while the currently bound framebuffer is not framebuffer complete (i.e. the return value from glCheckFramebufferStatus is not GL_FRAMEBUFFER_COMPLETE). The offending command is ignored and has no other side effect than to set the error flag.
	 * GL_OUT_OF_MEMORY 					There is not enough memory left to execute the command. The state of the GL is undefined, except for the state of the error flags, after this error is recorded.
	 * @return
	 */
	static public inline function GetError():String { return m_gl.GetError(); }
	
	/**
	 * Returns the error in integer form.
	 * @return
	 */
	static public inline function GetErrorCode():Int { return m_gl.GetErrorCode(); }
	
	/**
	 * Returns the String description of the error passed in code format.
	 * @param	p_code
	 * @return
	 */
	static public inline function GetErrorString(p_code : Int):String { return m_gl.GetErrorString(p_code); }
	
	/**
	 * Logs an error in console if there is any.
	 * @return
	 */
	static public inline function LogError():Void { m_gl.LogError(); }
	
	/**
	 * Checks the status of the GL execution and throws error when something happens.
	 */
	static public inline function Assert(p_log:String):Void 
	{
		#if gl_debug
		m_gl.Assert(p_log); 
		#end
	}
	
	//=========== Error ===========
	
	
	//=========== Misc ===========
	
	/**
	 * Executes all queued commands and clean the command buffer.
	 */
	static public inline function Flush():Void { m_gl.Flush(); }
	
	/**
	 * Makes the graphics context active (e.g. on windows)
	 */
	static public inline function Focus():Void { m_gl.Focus(); }
	
	//=========== Misc ===========
	
	
}