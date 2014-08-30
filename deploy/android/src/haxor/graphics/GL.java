package haxor.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class GL extends haxe.lang.HxObject
{
	static 
	{
		haxor.graphics.GL.ACTIVE_ATTRIBUTES = 35721;
		haxor.graphics.GL.ACTIVE_TEXTURE = 34016;
		haxor.graphics.GL.ACTIVE_UNIFORMS = 35718;
		haxor.graphics.GL.ALIASED_LINE_WIDTH_RANGE = 33902;
		haxor.graphics.GL.ALIASED_POINT_SIZE_RANGE = 33901;
		haxor.graphics.GL.ALPHA = 6406;
		haxor.graphics.GL.ALPHA_BITS = 3413;
		haxor.graphics.GL.ALWAYS = 519;
		haxor.graphics.GL.ARRAY_BUFFER = 34962;
		haxor.graphics.GL.ARRAY_BUFFER_BINDING = 34964;
		haxor.graphics.GL.ATTACHED_SHADERS = 35717;
		haxor.graphics.GL.BACK = 1029;
		haxor.graphics.GL.BLEND = 3042;
		haxor.graphics.GL.BLEND_COLOR = 32773;
		haxor.graphics.GL.BLEND_DST_ALPHA = 32970;
		haxor.graphics.GL.BLEND_DST_RGB = 32968;
		haxor.graphics.GL.BLEND_EQUATION = 32777;
		haxor.graphics.GL.BLEND_EQUATION_ALPHA = 34877;
		haxor.graphics.GL.BLEND_EQUATION_RGB = 32777;
		haxor.graphics.GL.BLEND_SRC_ALPHA = 32971;
		haxor.graphics.GL.BLEND_SRC_RGB = 32969;
		haxor.graphics.GL.BLUE_BITS = 3412;
		haxor.graphics.GL.BOOL = 35670;
		haxor.graphics.GL.BOOL_VEC2 = 35671;
		haxor.graphics.GL.BOOL_VEC3 = 35672;
		haxor.graphics.GL.BOOL_VEC4 = 35673;
		haxor.graphics.GL.BROWSER_DEFAULT_WEBGL = 37444;
		haxor.graphics.GL.BUFFER_SIZE = 34660;
		haxor.graphics.GL.BUFFER_USAGE = 34661;
		haxor.graphics.GL.BYTE = 5120;
		haxor.graphics.GL.CCW = 2305;
		haxor.graphics.GL.CLAMP_TO_EDGE = 33071;
		haxor.graphics.GL.COLOR_ATTACHMENT0 = 36064;
		haxor.graphics.GL.COLOR_BUFFER_BIT = 16384;
		haxor.graphics.GL.COLOR_CLEAR_VALUE = 3106;
		haxor.graphics.GL.COLOR_WRITEMASK = 3107;
		haxor.graphics.GL.COMPILE_STATUS = 35713;
		haxor.graphics.GL.COMPRESSED_TEXTURE_FORMATS = 34467;
		haxor.graphics.GL.CONSTANT_ALPHA = 32771;
		haxor.graphics.GL.CONSTANT_COLOR = 32769;
		haxor.graphics.GL.CONTEXT_LOST_WEBGL = 37442;
		haxor.graphics.GL.CULL_FACE = 2884;
		haxor.graphics.GL.CULL_FACE_MODE = 2885;
		haxor.graphics.GL.CURRENT_PROGRAM = 35725;
		haxor.graphics.GL.CURRENT_VERTEX_ATTRIB = 34342;
		haxor.graphics.GL.CW = 2304;
		haxor.graphics.GL.DECR = 7683;
		haxor.graphics.GL.DECR_WRAP = 34056;
		haxor.graphics.GL.DELETE_STATUS = 35712;
		haxor.graphics.GL.DEPTH_ATTACHMENT = 36096;
		haxor.graphics.GL.DEPTH_BITS = 3414;
		haxor.graphics.GL.DEPTH_BUFFER_BIT = 256;
		haxor.graphics.GL.DEPTH_CLEAR_VALUE = 2931;
		haxor.graphics.GL.DEPTH_COMPONENT = 6402;
		haxor.graphics.GL.DEPTH_COMPONENT16 = 33189;
		haxor.graphics.GL.DEPTH_FUNC = 2932;
		haxor.graphics.GL.DEPTH_RANGE = 2928;
		haxor.graphics.GL.DEPTH_STENCIL = 34041;
		haxor.graphics.GL.DEPTH_STENCIL_ATTACHMENT = 33306;
		haxor.graphics.GL.DEPTH_TEST = 2929;
		haxor.graphics.GL.DEPTH_WRITEMASK = 2930;
		haxor.graphics.GL.DITHER = 3024;
		haxor.graphics.GL.DONT_CARE = 4352;
		haxor.graphics.GL.DST_ALPHA = 772;
		haxor.graphics.GL.DST_COLOR = 774;
		haxor.graphics.GL.DYNAMIC_DRAW = 35048;
		haxor.graphics.GL.ELEMENT_ARRAY_BUFFER = 34963;
		haxor.graphics.GL.ELEMENT_ARRAY_BUFFER_BINDING = 34965;
		haxor.graphics.GL.EQUAL = 514;
		haxor.graphics.GL.FASTEST = 4353;
		haxor.graphics.GL.FLOAT = 5126;
		haxor.graphics.GL.FLOAT_MAT2 = 35674;
		haxor.graphics.GL.FLOAT_MAT3 = 35675;
		haxor.graphics.GL.FLOAT_MAT4 = 35676;
		haxor.graphics.GL.FLOAT_VEC2 = 35664;
		haxor.graphics.GL.FLOAT_VEC3 = 35665;
		haxor.graphics.GL.FLOAT_VEC4 = 35666;
		haxor.graphics.GL.FRAGMENT_SHADER = 35632;
		haxor.graphics.GL.FRAMEBUFFER = 36160;
		haxor.graphics.GL.FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 36049;
		haxor.graphics.GL.FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 36048;
		haxor.graphics.GL.FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 36051;
		haxor.graphics.GL.FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 36050;
		haxor.graphics.GL.FRAMEBUFFER_BINDING = 36006;
		haxor.graphics.GL.FRAMEBUFFER_COMPLETE = 36053;
		haxor.graphics.GL.FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 36054;
		haxor.graphics.GL.FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 36057;
		haxor.graphics.GL.FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 36055;
		haxor.graphics.GL.FRAMEBUFFER_UNSUPPORTED = 36061;
		haxor.graphics.GL.FRONT = 1028;
		haxor.graphics.GL.FRONT_AND_BACK = 1032;
		haxor.graphics.GL.FRONT_FACE = 2886;
		haxor.graphics.GL.FUNC_ADD = 32774;
		haxor.graphics.GL.FUNC_REVERSE_SUBTRACT = 32779;
		haxor.graphics.GL.FUNC_SUBTRACT = 32778;
		haxor.graphics.GL.GENERATE_MIPMAP_HINT = 33170;
		haxor.graphics.GL.GEQUAL = 518;
		haxor.graphics.GL.GREATER = 516;
		haxor.graphics.GL.GREEN_BITS = 3411;
		haxor.graphics.GL.HIGH_FLOAT = 36338;
		haxor.graphics.GL.HIGH_INT = 36341;
		haxor.graphics.GL.INCR = 7682;
		haxor.graphics.GL.INCR_WRAP = 34055;
		haxor.graphics.GL.INT = 5124;
		haxor.graphics.GL.INT_VEC2 = 35667;
		haxor.graphics.GL.INT_VEC3 = 35668;
		haxor.graphics.GL.INT_VEC4 = 35669;
		haxor.graphics.GL.INVALID_ENUM = 1280;
		haxor.graphics.GL.INVALID_FRAMEBUFFER_OPERATION = 1286;
		haxor.graphics.GL.INVALID_OPERATION = 1282;
		haxor.graphics.GL.INVALID_VALUE = 1281;
		haxor.graphics.GL.INVERT = 5386;
		haxor.graphics.GL.KEEP = 7680;
		haxor.graphics.GL.LEQUAL = 515;
		haxor.graphics.GL.LESS = 513;
		haxor.graphics.GL.LINEAR = 9729;
		haxor.graphics.GL.LINEAR_MIPMAP_LINEAR = 9987;
		haxor.graphics.GL.LINEAR_MIPMAP_NEAREST = 9985;
		haxor.graphics.GL.LINES = 1;
		haxor.graphics.GL.LINE_LOOP = 2;
		haxor.graphics.GL.LINE_STRIP = 3;
		haxor.graphics.GL.LINE_WIDTH = 2849;
		haxor.graphics.GL.LINK_STATUS = 35714;
		haxor.graphics.GL.LOW_FLOAT = 36336;
		haxor.graphics.GL.LOW_INT = 36339;
		haxor.graphics.GL.LUMINANCE = 6409;
		haxor.graphics.GL.LUMINANCE_ALPHA = 6410;
		haxor.graphics.GL.MAX_COMBINED_TEXTURE_IMAGE_UNITS = 35661;
		haxor.graphics.GL.MAX_CUBE_MAP_TEXTURE_SIZE = 34076;
		haxor.graphics.GL.MAX_FRAGMENT_UNIFORM_VECTORS = 36349;
		haxor.graphics.GL.MAX_RENDERBUFFER_SIZE = 34024;
		haxor.graphics.GL.MAX_TEXTURE_IMAGE_UNITS = 34930;
		haxor.graphics.GL.MAX_TEXTURE_SIZE = 3379;
		haxor.graphics.GL.MAX_VARYING_VECTORS = 36348;
		haxor.graphics.GL.MAX_VERTEX_ATTRIBS = 34921;
		haxor.graphics.GL.MAX_VERTEX_TEXTURE_IMAGE_UNITS = 35660;
		haxor.graphics.GL.MAX_VERTEX_UNIFORM_VECTORS = 36347;
		haxor.graphics.GL.MAX_VIEWPORT_DIMS = 3386;
		haxor.graphics.GL.MEDIUM_FLOAT = 36337;
		haxor.graphics.GL.MEDIUM_INT = 36340;
		haxor.graphics.GL.MIRRORED_REPEAT = 33648;
		haxor.graphics.GL.NEAREST = 9728;
		haxor.graphics.GL.NEAREST_MIPMAP_LINEAR = 9986;
		haxor.graphics.GL.NEAREST_MIPMAP_NEAREST = 9984;
		haxor.graphics.GL.NEVER = 512;
		haxor.graphics.GL.NICEST = 4354;
		haxor.graphics.GL.NONE = 0;
		haxor.graphics.GL.NOTEQUAL = 517;
		haxor.graphics.GL.NO_ERROR_GL = 0;
		haxor.graphics.GL.ONE = 1;
		haxor.graphics.GL.ONE_MINUS_CONSTANT_ALPHA = 32772;
		haxor.graphics.GL.ONE_MINUS_CONSTANT_COLOR = 32770;
		haxor.graphics.GL.ONE_MINUS_DST_ALPHA = 773;
		haxor.graphics.GL.ONE_MINUS_DST_COLOR = 775;
		haxor.graphics.GL.ONE_MINUS_SRC_ALPHA = 771;
		haxor.graphics.GL.ONE_MINUS_SRC_COLOR = 769;
		haxor.graphics.GL.OUT_OF_MEMORY = 1285;
		haxor.graphics.GL.PACK_ALIGNMENT = 3333;
		haxor.graphics.GL.POINTS = 0;
		haxor.graphics.GL.POLYGON_OFFSET_FACTOR = 32824;
		haxor.graphics.GL.POLYGON_OFFSET_FILL = 32823;
		haxor.graphics.GL.POLYGON_OFFSET_UNITS = 10752;
		haxor.graphics.GL.RED_BITS = 3410;
		haxor.graphics.GL.RENDERBUFFER = 36161;
		haxor.graphics.GL.RENDERBUFFER_ALPHA_SIZE = 36179;
		haxor.graphics.GL.RENDERBUFFER_BINDING = 36007;
		haxor.graphics.GL.RENDERBUFFER_BLUE_SIZE = 36178;
		haxor.graphics.GL.RENDERBUFFER_DEPTH_SIZE = 36180;
		haxor.graphics.GL.RENDERBUFFER_GREEN_SIZE = 36177;
		haxor.graphics.GL.RENDERBUFFER_HEIGHT = 36163;
		haxor.graphics.GL.RENDERBUFFER_INTERNAL_FORMAT = 36164;
		haxor.graphics.GL.RENDERBUFFER_RED_SIZE = 36176;
		haxor.graphics.GL.RENDERBUFFER_STENCIL_SIZE = 36181;
		haxor.graphics.GL.RENDERBUFFER_WIDTH = 36162;
		haxor.graphics.GL.RENDERER = 7937;
		haxor.graphics.GL.REPEAT = 10497;
		haxor.graphics.GL.REPLACE = 7681;
		haxor.graphics.GL.RGB = 6407;
		haxor.graphics.GL.RGB565 = 36194;
		haxor.graphics.GL.RGB5_A1 = 32855;
		haxor.graphics.GL.RGBA = 6408;
		haxor.graphics.GL.RGBA4 = 32854;
		haxor.graphics.GL.SAMPLER_2D = 35678;
		haxor.graphics.GL.SAMPLER_CUBE = 35680;
		haxor.graphics.GL.SAMPLES = 32937;
		haxor.graphics.GL.SAMPLE_ALPHA_TO_COVERAGE = 32926;
		haxor.graphics.GL.SAMPLE_BUFFERS = 32936;
		haxor.graphics.GL.SAMPLE_COVERAGE = 32928;
		haxor.graphics.GL.SAMPLE_COVERAGE_INVERT = 32939;
		haxor.graphics.GL.SAMPLE_COVERAGE_VALUE = 32938;
		haxor.graphics.GL.SCISSOR_BOX = 3088;
		haxor.graphics.GL.SCISSOR_TEST = 3089;
		haxor.graphics.GL.SHADER_TYPE = 35663;
		haxor.graphics.GL.SHADING_LANGUAGE_VERSION = 35724;
		haxor.graphics.GL.SHORT = 5122;
		haxor.graphics.GL.SRC_ALPHA = 770;
		haxor.graphics.GL.SRC_ALPHA_SATURATE = 776;
		haxor.graphics.GL.SRC_COLOR = 768;
		haxor.graphics.GL.STATIC_DRAW = 35044;
		haxor.graphics.GL.STENCIL_ATTACHMENT = 36128;
		haxor.graphics.GL.STENCIL_BACK_FAIL = 34817;
		haxor.graphics.GL.STENCIL_BACK_FUNC = 34816;
		haxor.graphics.GL.STENCIL_BACK_PASS_DEPTH_FAIL = 34818;
		haxor.graphics.GL.STENCIL_BACK_PASS_DEPTH_PASS = 34819;
		haxor.graphics.GL.STENCIL_BACK_REF = 36003;
		haxor.graphics.GL.STENCIL_BACK_VALUE_MASK = 36004;
		haxor.graphics.GL.STENCIL_BACK_WRITEMASK = 36005;
		haxor.graphics.GL.STENCIL_BITS = 3415;
		haxor.graphics.GL.STENCIL_BUFFER_BIT = 1024;
		haxor.graphics.GL.STENCIL_CLEAR_VALUE = 2961;
		haxor.graphics.GL.STENCIL_FAIL = 2964;
		haxor.graphics.GL.STENCIL_FUNC = 2962;
		haxor.graphics.GL.STENCIL_INDEX = 6401;
		haxor.graphics.GL.STENCIL_INDEX8 = 36168;
		haxor.graphics.GL.STENCIL_PASS_DEPTH_FAIL = 2965;
		haxor.graphics.GL.STENCIL_PASS_DEPTH_PASS = 2966;
		haxor.graphics.GL.STENCIL_REF = 2967;
		haxor.graphics.GL.STENCIL_TEST = 2960;
		haxor.graphics.GL.STENCIL_VALUE_MASK = 2963;
		haxor.graphics.GL.STENCIL_WRITEMASK = 2968;
		haxor.graphics.GL.STREAM_DRAW = 35040;
		haxor.graphics.GL.SUBPIXEL_BITS = 3408;
		haxor.graphics.GL.TEXTURE = 5890;
		haxor.graphics.GL.TEXTURE0 = 33984;
		haxor.graphics.GL.TEXTURE1 = 33985;
		haxor.graphics.GL.TEXTURE10 = 33994;
		haxor.graphics.GL.TEXTURE11 = 33995;
		haxor.graphics.GL.TEXTURE12 = 33996;
		haxor.graphics.GL.TEXTURE13 = 33997;
		haxor.graphics.GL.TEXTURE14 = 33998;
		haxor.graphics.GL.TEXTURE15 = 33999;
		haxor.graphics.GL.TEXTURE16 = 34000;
		haxor.graphics.GL.TEXTURE17 = 34001;
		haxor.graphics.GL.TEXTURE18 = 34002;
		haxor.graphics.GL.TEXTURE19 = 34003;
		haxor.graphics.GL.TEXTURE2 = 33986;
		haxor.graphics.GL.TEXTURE20 = 34004;
		haxor.graphics.GL.TEXTURE21 = 34005;
		haxor.graphics.GL.TEXTURE22 = 34006;
		haxor.graphics.GL.TEXTURE23 = 34007;
		haxor.graphics.GL.TEXTURE24 = 34008;
		haxor.graphics.GL.TEXTURE25 = 34009;
		haxor.graphics.GL.TEXTURE26 = 34010;
		haxor.graphics.GL.TEXTURE27 = 34011;
		haxor.graphics.GL.TEXTURE28 = 34012;
		haxor.graphics.GL.TEXTURE29 = 34013;
		haxor.graphics.GL.TEXTURE3 = 33987;
		haxor.graphics.GL.TEXTURE30 = 34014;
		haxor.graphics.GL.TEXTURE31 = 34015;
		haxor.graphics.GL.TEXTURE4 = 33988;
		haxor.graphics.GL.TEXTURE5 = 33989;
		haxor.graphics.GL.TEXTURE6 = 33990;
		haxor.graphics.GL.TEXTURE7 = 33991;
		haxor.graphics.GL.TEXTURE8 = 33992;
		haxor.graphics.GL.TEXTURE9 = 33993;
		haxor.graphics.GL.TEXTURE_2D = 3553;
		haxor.graphics.GL.TEXTURE_BINDING_2D = 32873;
		haxor.graphics.GL.TEXTURE_BINDING_CUBE_MAP = 34068;
		haxor.graphics.GL.TEXTURE_CUBE_MAP = 34067;
		haxor.graphics.GL.TEXTURE_CUBE_MAP_NEGATIVE_X = 34070;
		haxor.graphics.GL.TEXTURE_CUBE_MAP_NEGATIVE_Y = 34072;
		haxor.graphics.GL.TEXTURE_CUBE_MAP_NEGATIVE_Z = 34074;
		haxor.graphics.GL.TEXTURE_CUBE_MAP_POSITIVE_X = 34069;
		haxor.graphics.GL.TEXTURE_CUBE_MAP_POSITIVE_Y = 34071;
		haxor.graphics.GL.TEXTURE_CUBE_MAP_POSITIVE_Z = 34073;
		haxor.graphics.GL.TEXTURE_MAG_FILTER = 10240;
		haxor.graphics.GL.TEXTURE_MIN_FILTER = 10241;
		haxor.graphics.GL.TEXTURE_WRAP_S = 10242;
		haxor.graphics.GL.TEXTURE_WRAP_T = 10243;
		haxor.graphics.GL.TRIANGLES = 4;
		haxor.graphics.GL.TRIANGLE_FAN = 6;
		haxor.graphics.GL.TRIANGLE_STRIP = 5;
		haxor.graphics.GL.UNPACK_ALIGNMENT = 3317;
		haxor.graphics.GL.UNPACK_COLORSPACE_CONVERSION_WEBGL = 37443;
		haxor.graphics.GL.UNPACK_FLIP_Y_WEBGL = 37440;
		haxor.graphics.GL.UNPACK_PREMULTIPLY_ALPHA_WEBGL = 37441;
		haxor.graphics.GL.UNSIGNED_BYTE = 5121;
		haxor.graphics.GL.UNSIGNED_INT = 5125;
		haxor.graphics.GL.UNSIGNED_SHORT = 5123;
		haxor.graphics.GL.UNSIGNED_SHORT_4_4_4_4 = 32819;
		haxor.graphics.GL.UNSIGNED_SHORT_5_5_5_1 = 32820;
		haxor.graphics.GL.UNSIGNED_SHORT_5_6_5 = 33635;
		haxor.graphics.GL.VALIDATE_STATUS = 35715;
		haxor.graphics.GL.VENDOR = 7936;
		haxor.graphics.GL.VERSION = 7938;
		haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 34975;
		haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_ENABLED = 34338;
		haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_NORMALIZED = 34922;
		haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_POINTER = 34373;
		haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_SIZE = 34339;
		haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_STRIDE = 34340;
		haxor.graphics.GL.VERTEX_ATTRIB_ARRAY_TYPE = 34341;
		haxor.graphics.GL.VERTEX_SHADER = 35633;
		haxor.graphics.GL.VIEWPORT = 2978;
		haxor.graphics.GL.ZERO = 0;
		haxor.graphics.GL.VERTEX_ARRAY_OBJECT = false;
		haxor.graphics.GL.HALF_FLOAT = 5126;
		haxor.graphics.GL.TEXTURE_HALF = false;
		haxor.graphics.GL.TEXTURE_HALF_LINEAR = false;
		haxor.graphics.GL.TEXTURE_ANISOTROPY = -1;
		haxor.graphics.GL.TEXTURE_ANISOTROPY_ENABLED = false;
		haxor.graphics.GL.MAX_TEXTURE_ANISOTROPY = 1;
		haxor.graphics.GL.TEXTURE_FLOAT = false;
		haxor.graphics.GL.TEXTURE_FLOAT_LINEAR = false;
		haxor.graphics.GL.TEXTURE_DEPTH_ENABLED = false;
		haxor.graphics.GL.MAX_ACTIVE_TEXTURE = 8;
		haxor.graphics.GL.NULL = 0;
		haxor.graphics.GL.INVALID = -1;
	}
	public    GL(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    GL()
	{
		haxor.graphics.GL.__hx_ctor_haxor_graphics_GL(this);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_GL(haxor.graphics.GL __temp_me151367)
	{
		{
		}
		
	}
	
	
	public static  int ACTIVE_ATTRIBUTES;
	
	public static  int ACTIVE_TEXTURE;
	
	public static  int ACTIVE_UNIFORMS;
	
	public static  int ALIASED_LINE_WIDTH_RANGE;
	
	public static  int ALIASED_POINT_SIZE_RANGE;
	
	public static  int ALPHA;
	
	public static  int ALPHA_BITS;
	
	public static  int ALWAYS;
	
	public static  int ARRAY_BUFFER;
	
	public static  int ARRAY_BUFFER_BINDING;
	
	public static  int ATTACHED_SHADERS;
	
	public static  int BACK;
	
	public static  int BLEND;
	
	public static  int BLEND_COLOR;
	
	public static  int BLEND_DST_ALPHA;
	
	public static  int BLEND_DST_RGB;
	
	public static  int BLEND_EQUATION;
	
	public static  int BLEND_EQUATION_ALPHA;
	
	public static  int BLEND_EQUATION_RGB;
	
	public static  int BLEND_SRC_ALPHA;
	
	public static  int BLEND_SRC_RGB;
	
	public static  int BLUE_BITS;
	
	public static  int BOOL;
	
	public static  int BOOL_VEC2;
	
	public static  int BOOL_VEC3;
	
	public static  int BOOL_VEC4;
	
	public static  int BROWSER_DEFAULT_WEBGL;
	
	public static  int BUFFER_SIZE;
	
	public static  int BUFFER_USAGE;
	
	public static  int BYTE;
	
	public static  int CCW;
	
	public static  int CLAMP_TO_EDGE;
	
	public static  int COLOR_ATTACHMENT0;
	
	public static  int COLOR_BUFFER_BIT;
	
	public static  int COLOR_CLEAR_VALUE;
	
	public static  int COLOR_WRITEMASK;
	
	public static  int COMPILE_STATUS;
	
	public static  int COMPRESSED_TEXTURE_FORMATS;
	
	public static  int CONSTANT_ALPHA;
	
	public static  int CONSTANT_COLOR;
	
	public static  int CONTEXT_LOST_WEBGL;
	
	public static  int CULL_FACE;
	
	public static  int CULL_FACE_MODE;
	
	public static  int CURRENT_PROGRAM;
	
	public static  int CURRENT_VERTEX_ATTRIB;
	
	public static  int CW;
	
	public static  int DECR;
	
	public static  int DECR_WRAP;
	
	public static  int DELETE_STATUS;
	
	public static  int DEPTH_ATTACHMENT;
	
	public static  int DEPTH_BITS;
	
	public static  int DEPTH_BUFFER_BIT;
	
	public static  int DEPTH_CLEAR_VALUE;
	
	public static  int DEPTH_COMPONENT;
	
	public static  int DEPTH_COMPONENT16;
	
	public static  int DEPTH_FUNC;
	
	public static  int DEPTH_RANGE;
	
	public static  int DEPTH_STENCIL;
	
	public static  int DEPTH_STENCIL_ATTACHMENT;
	
	public static  int DEPTH_TEST;
	
	public static  int DEPTH_WRITEMASK;
	
	public static  int DITHER;
	
	public static  int DONT_CARE;
	
	public static  int DST_ALPHA;
	
	public static  int DST_COLOR;
	
	public static  int DYNAMIC_DRAW;
	
	public static  int ELEMENT_ARRAY_BUFFER;
	
	public static  int ELEMENT_ARRAY_BUFFER_BINDING;
	
	public static  int EQUAL;
	
	public static  int FASTEST;
	
	public static  int FLOAT;
	
	public static  int FLOAT_MAT2;
	
	public static  int FLOAT_MAT3;
	
	public static  int FLOAT_MAT4;
	
	public static  int FLOAT_VEC2;
	
	public static  int FLOAT_VEC3;
	
	public static  int FLOAT_VEC4;
	
	public static  int FRAGMENT_SHADER;
	
	public static  int FRAMEBUFFER;
	
	public static  int FRAMEBUFFER_ATTACHMENT_OBJECT_NAME;
	
	public static  int FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE;
	
	public static  int FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE;
	
	public static  int FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL;
	
	public static  int FRAMEBUFFER_BINDING;
	
	public static  int FRAMEBUFFER_COMPLETE;
	
	public static  int FRAMEBUFFER_INCOMPLETE_ATTACHMENT;
	
	public static  int FRAMEBUFFER_INCOMPLETE_DIMENSIONS;
	
	public static  int FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT;
	
	public static  int FRAMEBUFFER_UNSUPPORTED;
	
	public static  int FRONT;
	
	public static  int FRONT_AND_BACK;
	
	public static  int FRONT_FACE;
	
	public static  int FUNC_ADD;
	
	public static  int FUNC_REVERSE_SUBTRACT;
	
	public static  int FUNC_SUBTRACT;
	
	public static  int GENERATE_MIPMAP_HINT;
	
	public static  int GEQUAL;
	
	public static  int GREATER;
	
	public static  int GREEN_BITS;
	
	public static  int HIGH_FLOAT;
	
	public static  int HIGH_INT;
	
	public static  int INCR;
	
	public static  int INCR_WRAP;
	
	public static  int INT;
	
	public static  int INT_VEC2;
	
	public static  int INT_VEC3;
	
	public static  int INT_VEC4;
	
	public static  int INVALID_ENUM;
	
	public static  int INVALID_FRAMEBUFFER_OPERATION;
	
	public static  int INVALID_OPERATION;
	
	public static  int INVALID_VALUE;
	
	public static  int INVERT;
	
	public static  int KEEP;
	
	public static  int LEQUAL;
	
	public static  int LESS;
	
	public static  int LINEAR;
	
	public static  int LINEAR_MIPMAP_LINEAR;
	
	public static  int LINEAR_MIPMAP_NEAREST;
	
	public static  int LINES;
	
	public static  int LINE_LOOP;
	
	public static  int LINE_STRIP;
	
	public static  int LINE_WIDTH;
	
	public static  int LINK_STATUS;
	
	public static  int LOW_FLOAT;
	
	public static  int LOW_INT;
	
	public static  int LUMINANCE;
	
	public static  int LUMINANCE_ALPHA;
	
	public static  int MAX_COMBINED_TEXTURE_IMAGE_UNITS;
	
	public static  int MAX_CUBE_MAP_TEXTURE_SIZE;
	
	public static  int MAX_FRAGMENT_UNIFORM_VECTORS;
	
	public static  int MAX_RENDERBUFFER_SIZE;
	
	public static  int MAX_TEXTURE_IMAGE_UNITS;
	
	public static  int MAX_TEXTURE_SIZE;
	
	public static  int MAX_VARYING_VECTORS;
	
	public static  int MAX_VERTEX_ATTRIBS;
	
	public static  int MAX_VERTEX_TEXTURE_IMAGE_UNITS;
	
	public static  int MAX_VERTEX_UNIFORM_VECTORS;
	
	public static  int MAX_VIEWPORT_DIMS;
	
	public static  int MEDIUM_FLOAT;
	
	public static  int MEDIUM_INT;
	
	public static  int MIRRORED_REPEAT;
	
	public static  int NEAREST;
	
	public static  int NEAREST_MIPMAP_LINEAR;
	
	public static  int NEAREST_MIPMAP_NEAREST;
	
	public static  int NEVER;
	
	public static  int NICEST;
	
	public static  int NONE;
	
	public static  int NOTEQUAL;
	
	public static  int NO_ERROR_GL;
	
	public static  int ONE;
	
	public static  int ONE_MINUS_CONSTANT_ALPHA;
	
	public static  int ONE_MINUS_CONSTANT_COLOR;
	
	public static  int ONE_MINUS_DST_ALPHA;
	
	public static  int ONE_MINUS_DST_COLOR;
	
	public static  int ONE_MINUS_SRC_ALPHA;
	
	public static  int ONE_MINUS_SRC_COLOR;
	
	public static  int OUT_OF_MEMORY;
	
	public static  int PACK_ALIGNMENT;
	
	public static  int POINTS;
	
	public static  int POLYGON_OFFSET_FACTOR;
	
	public static  int POLYGON_OFFSET_FILL;
	
	public static  int POLYGON_OFFSET_UNITS;
	
	public static  int RED_BITS;
	
	public static  int RENDERBUFFER;
	
	public static  int RENDERBUFFER_ALPHA_SIZE;
	
	public static  int RENDERBUFFER_BINDING;
	
	public static  int RENDERBUFFER_BLUE_SIZE;
	
	public static  int RENDERBUFFER_DEPTH_SIZE;
	
	public static  int RENDERBUFFER_GREEN_SIZE;
	
	public static  int RENDERBUFFER_HEIGHT;
	
	public static  int RENDERBUFFER_INTERNAL_FORMAT;
	
	public static  int RENDERBUFFER_RED_SIZE;
	
	public static  int RENDERBUFFER_STENCIL_SIZE;
	
	public static  int RENDERBUFFER_WIDTH;
	
	public static  int RENDERER;
	
	public static  int REPEAT;
	
	public static  int REPLACE;
	
	public static  int RGB;
	
	public static  int RGB565;
	
	public static  int RGB5_A1;
	
	public static  int RGBA;
	
	public static  int RGBA4;
	
	public static  int SAMPLER_2D;
	
	public static  int SAMPLER_CUBE;
	
	public static  int SAMPLES;
	
	public static  int SAMPLE_ALPHA_TO_COVERAGE;
	
	public static  int SAMPLE_BUFFERS;
	
	public static  int SAMPLE_COVERAGE;
	
	public static  int SAMPLE_COVERAGE_INVERT;
	
	public static  int SAMPLE_COVERAGE_VALUE;
	
	public static  int SCISSOR_BOX;
	
	public static  int SCISSOR_TEST;
	
	public static  int SHADER_TYPE;
	
	public static  int SHADING_LANGUAGE_VERSION;
	
	public static  int SHORT;
	
	public static  int SRC_ALPHA;
	
	public static  int SRC_ALPHA_SATURATE;
	
	public static  int SRC_COLOR;
	
	public static  int STATIC_DRAW;
	
	public static  int STENCIL_ATTACHMENT;
	
	public static  int STENCIL_BACK_FAIL;
	
	public static  int STENCIL_BACK_FUNC;
	
	public static  int STENCIL_BACK_PASS_DEPTH_FAIL;
	
	public static  int STENCIL_BACK_PASS_DEPTH_PASS;
	
	public static  int STENCIL_BACK_REF;
	
	public static  int STENCIL_BACK_VALUE_MASK;
	
	public static  int STENCIL_BACK_WRITEMASK;
	
	public static  int STENCIL_BITS;
	
	public static  int STENCIL_BUFFER_BIT;
	
	public static  int STENCIL_CLEAR_VALUE;
	
	public static  int STENCIL_FAIL;
	
	public static  int STENCIL_FUNC;
	
	public static  int STENCIL_INDEX;
	
	public static  int STENCIL_INDEX8;
	
	public static  int STENCIL_PASS_DEPTH_FAIL;
	
	public static  int STENCIL_PASS_DEPTH_PASS;
	
	public static  int STENCIL_REF;
	
	public static  int STENCIL_TEST;
	
	public static  int STENCIL_VALUE_MASK;
	
	public static  int STENCIL_WRITEMASK;
	
	public static  int STREAM_DRAW;
	
	public static  int SUBPIXEL_BITS;
	
	public static  int TEXTURE;
	
	public static  int TEXTURE0;
	
	public static  int TEXTURE1;
	
	public static  int TEXTURE10;
	
	public static  int TEXTURE11;
	
	public static  int TEXTURE12;
	
	public static  int TEXTURE13;
	
	public static  int TEXTURE14;
	
	public static  int TEXTURE15;
	
	public static  int TEXTURE16;
	
	public static  int TEXTURE17;
	
	public static  int TEXTURE18;
	
	public static  int TEXTURE19;
	
	public static  int TEXTURE2;
	
	public static  int TEXTURE20;
	
	public static  int TEXTURE21;
	
	public static  int TEXTURE22;
	
	public static  int TEXTURE23;
	
	public static  int TEXTURE24;
	
	public static  int TEXTURE25;
	
	public static  int TEXTURE26;
	
	public static  int TEXTURE27;
	
	public static  int TEXTURE28;
	
	public static  int TEXTURE29;
	
	public static  int TEXTURE3;
	
	public static  int TEXTURE30;
	
	public static  int TEXTURE31;
	
	public static  int TEXTURE4;
	
	public static  int TEXTURE5;
	
	public static  int TEXTURE6;
	
	public static  int TEXTURE7;
	
	public static  int TEXTURE8;
	
	public static  int TEXTURE9;
	
	public static  int TEXTURE_2D;
	
	public static  int TEXTURE_BINDING_2D;
	
	public static  int TEXTURE_BINDING_CUBE_MAP;
	
	public static  int TEXTURE_CUBE_MAP;
	
	public static  int TEXTURE_CUBE_MAP_NEGATIVE_X;
	
	public static  int TEXTURE_CUBE_MAP_NEGATIVE_Y;
	
	public static  int TEXTURE_CUBE_MAP_NEGATIVE_Z;
	
	public static  int TEXTURE_CUBE_MAP_POSITIVE_X;
	
	public static  int TEXTURE_CUBE_MAP_POSITIVE_Y;
	
	public static  int TEXTURE_CUBE_MAP_POSITIVE_Z;
	
	public static  int TEXTURE_MAG_FILTER;
	
	public static  int TEXTURE_MIN_FILTER;
	
	public static  int TEXTURE_WRAP_S;
	
	public static  int TEXTURE_WRAP_T;
	
	public static  int TRIANGLES;
	
	public static  int TRIANGLE_FAN;
	
	public static  int TRIANGLE_STRIP;
	
	public static  int UNPACK_ALIGNMENT;
	
	public static  int UNPACK_COLORSPACE_CONVERSION_WEBGL;
	
	public static  int UNPACK_FLIP_Y_WEBGL;
	
	public static  int UNPACK_PREMULTIPLY_ALPHA_WEBGL;
	
	public static  int UNSIGNED_BYTE;
	
	public static  int UNSIGNED_INT;
	
	public static  int UNSIGNED_SHORT;
	
	public static  int UNSIGNED_SHORT_4_4_4_4;
	
	public static  int UNSIGNED_SHORT_5_5_5_1;
	
	public static  int UNSIGNED_SHORT_5_6_5;
	
	public static  int VALIDATE_STATUS;
	
	public static  int VENDOR;
	
	public static  int VERSION;
	
	public static  int VERTEX_ATTRIB_ARRAY_BUFFER_BINDING;
	
	public static  int VERTEX_ATTRIB_ARRAY_ENABLED;
	
	public static  int VERTEX_ATTRIB_ARRAY_NORMALIZED;
	
	public static  int VERTEX_ATTRIB_ARRAY_POINTER;
	
	public static  int VERTEX_ATTRIB_ARRAY_SIZE;
	
	public static  int VERTEX_ATTRIB_ARRAY_STRIDE;
	
	public static  int VERTEX_ATTRIB_ARRAY_TYPE;
	
	public static  int VERTEX_SHADER;
	
	public static  int VIEWPORT;
	
	public static  int ZERO;
	
	public static  boolean VERTEX_ARRAY_OBJECT;
	
	public static  int HALF_FLOAT;
	
	public static  boolean TEXTURE_HALF;
	
	public static  boolean TEXTURE_HALF_LINEAR;
	
	public static  int TEXTURE_ANISOTROPY;
	
	public static  boolean TEXTURE_ANISOTROPY_ENABLED;
	
	public static  int MAX_TEXTURE_ANISOTROPY;
	
	public static  boolean TEXTURE_FLOAT;
	
	public static  boolean TEXTURE_FLOAT_LINEAR;
	
	public static  boolean TEXTURE_DEPTH_ENABLED;
	
	public static  int MAX_ACTIVE_TEXTURE;
	
	public static  int NULL;
	
	public static  int INVALID;
	
	
	
	public static   haxor.graphics.GraphicAPI get_api()
	{
		return haxor.graphics.GL.m_gl.get_api();
	}
	
	
	public static  haxor.platform.android.graphics.AndroidGL m_gl;
	
	public static   void Initialize(haxor.core.BaseApplication p_application)
	{
		haxor.graphics.GL.m_gl = new haxor.platform.android.graphics.AndroidGL(((haxor.core.BaseApplication) (p_application) ));
	}
	
	
	public static   void Resize()
	{
		haxor.graphics.GL.m_gl.Resize();
	}
	
	
	public static   void BindBuffer(int p_target, int p_id)
	{
		haxor.graphics.GL.m_gl.BindBuffer(p_target, p_id);
	}
	
	
	public static   void BufferData(int p_target, haxor.io.Buffer p_data, int p_mode)
	{
		haxor.graphics.GL.m_gl.BufferData(p_target, p_data, p_mode);
	}
	
	
	public static   void BufferSubData(int p_target, int p_offset, haxor.io.Buffer p_data)
	{
		haxor.graphics.GL.m_gl.BufferSubData(p_target, p_offset, p_data);
	}
	
	
	public static   int CreateBuffer()
	{
		return haxor.graphics.GL.m_gl.CreateBuffer();
	}
	
	
	public static   void DrawArrays(int p_primitive, int p_start, int p_count)
	{
		haxor.graphics.GL.m_gl.DrawArrays(p_primitive, p_start, p_count);
	}
	
	
	public static   void DrawElements(int p_primitive, int p_count, int p_type, int p_offset)
	{
		haxor.graphics.GL.m_gl.DrawElements(p_primitive, p_count, p_type, p_offset);
	}
	
	
	public static   void DeleteBuffer(int p_id)
	{
		haxor.graphics.GL.m_gl.DeleteBuffer(p_id);
	}
	
	
	public static   void DisableVertexAttrib(int p_location)
	{
		haxor.graphics.GL.m_gl.DisableVertexAttrib(p_location);
	}
	
	
	public static   void EnableVertexAttrib(int p_location)
	{
		haxor.graphics.GL.m_gl.EnableVertexAttrib(p_location);
	}
	
	
	public static   void VertexAttrib3f(int p_location, double p_x, double p_y, double p_z)
	{
		haxor.graphics.GL.m_gl.VertexAttrib3f(p_location, p_x, p_y, p_z);
	}
	
	
	public static   void VertexAttrib4f(int p_location, double p_x, double p_y, double p_z, double p_w)
	{
		haxor.graphics.GL.m_gl.VertexAttrib4f(p_location, p_x, p_y, p_z, p_w);
	}
	
	
	public static   void VertexAttribPointer(int p_location, int p_components_size, int p_type, boolean p_normalized, int p_stride, int p_offset)
	{
		haxor.graphics.GL.m_gl.VertexAttribPointer(p_location, p_components_size, p_type, p_normalized, p_stride, p_offset);
	}
	
	
	public static   void CompileShader(int p_shader)
	{
		haxor.graphics.GL.m_gl.CompileShader(p_shader);
	}
	
	
	public static   int CreateShader(int p_type)
	{
		return haxor.graphics.GL.m_gl.CreateShader(p_type);
	}
	
	
	public static   void DetachShader(int p_program, int p_shader)
	{
		haxor.graphics.GL.m_gl.DetachShader(p_program, p_shader);
	}
	
	
	public static   void DeleteShader(int p_shader)
	{
		haxor.graphics.GL.m_gl.DeleteShader(p_shader);
	}
	
	
	public static   java.lang.String GetShaderInfoLog(int p_shader)
	{
		return haxor.graphics.GL.m_gl.GetShaderInfoLog(p_shader);
	}
	
	
	public static   int GetShaderParameter(int p_shader, int p_parameter)
	{
		return haxor.graphics.GL.m_gl.GetShaderParameter(p_shader, p_parameter);
	}
	
	
	public static   void ShaderSource(int p_shader, java.lang.String p_source)
	{
		haxor.graphics.GL.m_gl.ShaderSource(p_shader, p_source);
	}
	
	
	public static   void AttachShader(int p_program, int p_shader)
	{
		haxor.graphics.GL.m_gl.AttachShader(p_program, p_shader);
	}
	
	
	public static   void BindAttribLocation(int p_program, int p_location, java.lang.String p_name)
	{
		haxor.graphics.GL.m_gl.BindAttribLocation(p_program, p_location, p_name);
	}
	
	
	public static   int CreateProgram()
	{
		return haxor.graphics.GL.m_gl.CreateProgram();
	}
	
	
	public static   void DeleteProgram(int p_program)
	{
		haxor.graphics.GL.m_gl.DeleteProgram(p_program);
	}
	
	
	public static   int GetAttribLocation(int p_program, java.lang.String p_name)
	{
		return haxor.graphics.GL.m_gl.GetAttribLocation(p_program, p_name);
	}
	
	
	public static   int GetUniformLocation(int p_program, java.lang.String p_name)
	{
		return haxor.graphics.GL.m_gl.GetUniformLocation(p_program, p_name);
	}
	
	
	public static   java.lang.String GetProgramInfoLog(int p_program)
	{
		return haxor.graphics.GL.m_gl.GetProgramInfoLog(p_program);
	}
	
	
	public static   int GetProgramParameter(int p_program, int p_parameter)
	{
		return haxor.graphics.GL.m_gl.GetProgramParameter(p_program, p_parameter);
	}
	
	
	public static   void LinkProgram(int p_program)
	{
		haxor.graphics.GL.m_gl.LinkProgram(p_program);
	}
	
	
	public static   void UseProgram(int p_program)
	{
		haxor.graphics.GL.m_gl.UseProgram(p_program);
	}
	
	
	public static   void ActiveTexture(int p_slot)
	{
		haxor.graphics.GL.m_gl.ActiveTexture(p_slot);
	}
	
	
	public static   void BindFramebuffer(int p_target, int p_id)
	{
		haxor.graphics.GL.m_gl.BindFramebuffer(p_target, p_id);
	}
	
	
	public static   void BindRenderbuffer(int p_target, int p_id)
	{
		haxor.graphics.GL.m_gl.BindRenderbuffer(p_target, p_id);
	}
	
	
	public static   void BindTexture(int p_target, int p_id)
	{
		haxor.graphics.GL.m_gl.BindTexture(p_target, p_id);
	}
	
	
	public static   int CreateFramebuffer()
	{
		return haxor.graphics.GL.m_gl.CreateFramebuffer();
	}
	
	
	public static   int CreateRenderbuffer()
	{
		return haxor.graphics.GL.m_gl.CreateRenderbuffer();
	}
	
	
	public static   int CreateTexture()
	{
		return haxor.graphics.GL.m_gl.CreateTexture();
	}
	
	
	public static   void DeleteFramebuffer(int p_id)
	{
		haxor.graphics.GL.m_gl.DeleteFramebuffer(p_id);
	}
	
	
	public static   void DeleteRenderbuffer(int p_id)
	{
		haxor.graphics.GL.m_gl.DeleteRenderbuffer(p_id);
	}
	
	
	public static   void DeleteTexture(int p_id)
	{
		haxor.graphics.GL.m_gl.DeleteTexture(p_id);
	}
	
	
	public static   void FramebufferRenderbuffer(int p_target, int p_attachment, int p_renderbuffer_target, int p_renderbuffer_id)
	{
		haxor.graphics.GL.m_gl.FramebufferRenderbuffer(p_target, p_attachment, p_renderbuffer_target, p_renderbuffer_id);
	}
	
	
	public static   void FramebufferTexture2D(int p_target, int p_attachment, int p_texture_target, int p_texture_id, int p_miplevel)
	{
		haxor.graphics.GL.m_gl.FramebufferTexture2D(p_target, p_attachment, p_texture_target, p_texture_id, p_miplevel);
	}
	
	
	public static   void GenerateMipmap(int p_target)
	{
		haxor.graphics.GL.m_gl.GenerateMipmap(p_target);
	}
	
	
	public static   void PixelStorei(int p_parameter, int p_value)
	{
		haxor.graphics.GL.m_gl.PixelStorei(p_parameter, p_value);
	}
	
	
	public static   void RenderbufferStorage(int p_target, int p_format, int p_width, int p_height)
	{
		haxor.graphics.GL.m_gl.RenderbufferStorage(p_target, p_format, p_width, p_height);
	}
	
	
	public static   void TexImage2D(int p_target, int p_level, int p_internal_format, int p_width, int p_height, int p_border, int p_format, int p_channel_type, haxor.io.Buffer p_data)
	{
		haxor.graphics.GL.m_gl.TexImage2D(p_target, p_level, p_internal_format, p_width, p_height, p_border, p_format, p_channel_type, p_data);
	}
	
	
	public static   void TexImage2DAlloc(int p_target, int p_level, int p_internal_format, int p_width, int p_height, int p_border, int p_format, int p_channel_type)
	{
		haxor.graphics.GL.m_gl.TexImage2DAlloc(p_target, p_level, p_internal_format, p_width, p_height, p_border, p_format, p_channel_type);
	}
	
	
	public static   void TexSubImage2D(int p_target, int p_level, int p_x, int p_y, int p_width, int p_height, int p_format, int p_channel_type, haxor.io.Buffer p_data)
	{
		haxor.graphics.GL.m_gl.TexSubImage2D(p_target, p_level, p_x, p_y, p_width, p_height, p_format, p_channel_type, p_data);
	}
	
	
	public static   void TexStorage2D(int p_target, int p_num_mipmaps, int p_channels, int p_width, int p_height)
	{
		haxor.graphics.GL.m_gl.TexStorage2D(p_target, p_num_mipmaps, p_channels, p_width, p_height);
	}
	
	
	public static   void TexParameterf(int p_target, int p_parameter, double p_value)
	{
		haxor.graphics.GL.m_gl.TexParameterf(p_target, p_parameter, p_value);
	}
	
	
	public static   void TexParameteri(int p_target, int p_parameter, int p_value)
	{
		haxor.graphics.GL.m_gl.TexParameteri(p_target, p_parameter, p_value);
	}
	
	
	public static   void Uniform1f(int p_location, double p_x)
	{
		haxor.graphics.GL.m_gl.Uniform1f(p_location, p_x);
	}
	
	
	public static   void Uniform2f(int p_location, double p_x, double p_y)
	{
		haxor.graphics.GL.m_gl.Uniform2f(p_location, p_x, p_y);
	}
	
	
	public static   void Uniform3f(int p_location, double p_x, double p_y, double p_z)
	{
		haxor.graphics.GL.m_gl.Uniform3f(p_location, p_x, p_y, p_z);
	}
	
	
	public static   void Uniform4f(int p_location, double p_x, double p_y, double p_z, double p_w)
	{
		haxor.graphics.GL.m_gl.Uniform4f(p_location, p_x, p_y, p_z, p_w);
	}
	
	
	public static   void Uniform1i(int p_location, int p_x)
	{
		haxor.graphics.GL.m_gl.Uniform1i(p_location, p_x);
	}
	
	
	public static   void Uniform2i(int p_location, int p_x, int p_y)
	{
		haxor.graphics.GL.m_gl.Uniform2i(p_location, p_x, p_y);
	}
	
	
	public static   void Uniform3i(int p_location, int p_x, int p_y, int p_z)
	{
		haxor.graphics.GL.m_gl.Uniform3i(p_location, p_x, p_y, p_z);
	}
	
	
	public static   void Uniform4i(int p_location, int p_x, int p_y, int p_z, int p_w)
	{
		haxor.graphics.GL.m_gl.Uniform4i(p_location, p_x, p_y, p_z, p_w);
	}
	
	
	public static   void Uniform1fv(int p_location, haxor.io.FloatArray p_v)
	{
		haxor.graphics.GL.m_gl.Uniform1fv(p_location, p_v);
	}
	
	
	public static   void Uniform2fv(int p_location, haxor.io.FloatArray p_v)
	{
		haxor.graphics.GL.m_gl.Uniform2fv(p_location, p_v);
	}
	
	
	public static   void Uniform3fv(int p_location, haxor.io.FloatArray p_v)
	{
		haxor.graphics.GL.m_gl.Uniform3fv(p_location, p_v);
	}
	
	
	public static   void Uniform4fv(int p_location, haxor.io.FloatArray p_v)
	{
		haxor.graphics.GL.m_gl.Uniform4fv(p_location, p_v);
	}
	
	
	public static   void Uniform1iv(int p_location, haxor.io.Int32Array p_v)
	{
		haxor.graphics.GL.m_gl.Uniform1iv(p_location, p_v);
	}
	
	
	public static   void Uniform2iv(int p_location, haxor.io.Int32Array p_v)
	{
		haxor.graphics.GL.m_gl.Uniform2iv(p_location, p_v);
	}
	
	
	public static   void Uniform3iv(int p_location, haxor.io.Int32Array p_v)
	{
		haxor.graphics.GL.m_gl.Uniform3iv(p_location, p_v);
	}
	
	
	public static   void Uniform4iv(int p_location, haxor.io.Int32Array p_v)
	{
		haxor.graphics.GL.m_gl.Uniform4iv(p_location, p_v);
	}
	
	
	public static   void UniformMatrix2fv(int p_location, boolean p_transpose, haxor.io.FloatArray p_v)
	{
		haxor.graphics.GL.m_gl.UniformMatrix2fv(p_location, p_transpose, p_v);
	}
	
	
	public static   void UniformMatrix3fv(int p_location, boolean p_transpose, haxor.io.FloatArray p_v)
	{
		haxor.graphics.GL.m_gl.UniformMatrix3fv(p_location, p_transpose, p_v);
	}
	
	
	public static   void UniformMatrix4fv(int p_location, boolean p_transpose, haxor.io.FloatArray p_v)
	{
		haxor.graphics.GL.m_gl.UniformMatrix4fv(p_location, p_transpose, p_v);
	}
	
	
	public static   void BlendFunc(int p_src, int p_dst)
	{
		haxor.graphics.GL.m_gl.BlendFunc(p_src, p_dst);
	}
	
	
	public static   void Disable(int p_flag)
	{
		haxor.graphics.GL.m_gl.Disable(p_flag);
	}
	
	
	public static   void Enable(int p_flag)
	{
		haxor.graphics.GL.m_gl.Enable(p_flag);
	}
	
	
	public static   void DepthMask(boolean p_flag)
	{
		haxor.graphics.GL.m_gl.DepthMask(p_flag);
	}
	
	
	public static   void DepthFunc(int p_flag)
	{
		haxor.graphics.GL.m_gl.DepthFunc(p_flag);
	}
	
	
	public static   void CullFace(int p_face)
	{
		haxor.graphics.GL.m_gl.CullFace(p_face);
	}
	
	
	public static   void FrontFace(int p_face)
	{
		haxor.graphics.GL.m_gl.FrontFace(p_face);
	}
	
	
	public static   void Clear(int p_flag)
	{
		haxor.graphics.GL.m_gl.Clear(p_flag);
	}
	
	
	public static   void ClearDepth(double p_value)
	{
		haxor.graphics.GL.m_gl.ClearDepth(p_value);
	}
	
	
	public static   void ClearColor(double p_r, double p_g, double p_b, double p_a)
	{
		haxor.graphics.GL.m_gl.ClearColor(p_r, p_g, p_b, p_a);
	}
	
	
	public static   void Viewport(int p_x, int p_y, int p_width, int p_height)
	{
		haxor.graphics.GL.m_gl.Viewport(p_x, p_y, p_width, p_height);
	}
	
	
	public static   void Scissor(int p_x, int p_y, int p_width, int p_height)
	{
		haxor.graphics.GL.m_gl.Scissor(p_x, p_y, p_width, p_height);
	}
	
	
	public static   void ReadPixels(int p_x, int p_y, int p_width, int p_height, int p_format, int p_type, haxor.io.Buffer p_pixels)
	{
		haxor.graphics.GL.m_gl.ReadPixels(p_x, p_y, p_width, p_height, p_format, p_type, p_pixels);
	}
	
	
	public static   java.lang.String GetError()
	{
		return haxor.graphics.GL.m_gl.GetError();
	}
	
	
	public static   int GetErrorCode()
	{
		return haxor.graphics.GL.m_gl.GetErrorCode();
	}
	
	
	public static   java.lang.String GetErrorString(int p_code)
	{
		return haxor.graphics.GL.m_gl.GetErrorString(p_code);
	}
	
	
	public static   void LogError()
	{
		haxor.graphics.GL.m_gl.LogError();
	}
	
	
	public static   void Assert(java.lang.String p_log)
	{
		haxor.graphics.GL.m_gl.Assert(p_log);
	}
	
	
	public static   void Flush()
	{
		haxor.graphics.GL.m_gl.Flush();
	}
	
	
	public static   void Focus()
	{
		haxor.graphics.GL.m_gl.Focus();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.GL(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.GL();
	}
	
	
}


