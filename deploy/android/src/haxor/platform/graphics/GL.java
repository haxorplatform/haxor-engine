package haxor.platform.graphics;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class GL extends haxe.lang.HxObject
{
	static 
	{
		haxor.platform.graphics.GL.ACTIVE_ATTRIBUTES = 35721;
		haxor.platform.graphics.GL.ACTIVE_TEXTURE = 34016;
		haxor.platform.graphics.GL.ACTIVE_UNIFORMS = 35718;
		haxor.platform.graphics.GL.ALIASED_LINE_WIDTH_RANGE = 33902;
		haxor.platform.graphics.GL.ALIASED_POINT_SIZE_RANGE = 33901;
		haxor.platform.graphics.GL.ALPHA = 6406;
		haxor.platform.graphics.GL.ALPHA_BITS = 3413;
		haxor.platform.graphics.GL.ALWAYS = 519;
		haxor.platform.graphics.GL.ARRAY_BUFFER = 34962;
		haxor.platform.graphics.GL.ARRAY_BUFFER_BINDING = 34964;
		haxor.platform.graphics.GL.ATTACHED_SHADERS = 35717;
		haxor.platform.graphics.GL.BACK = 1029;
		haxor.platform.graphics.GL.BLEND = 3042;
		haxor.platform.graphics.GL.BLEND_COLOR = 32773;
		haxor.platform.graphics.GL.BLEND_DST_ALPHA = 32970;
		haxor.platform.graphics.GL.BLEND_DST_RGB = 32968;
		haxor.platform.graphics.GL.BLEND_EQUATION = 32777;
		haxor.platform.graphics.GL.BLEND_EQUATION_ALPHA = 34877;
		haxor.platform.graphics.GL.BLEND_EQUATION_RGB = 32777;
		haxor.platform.graphics.GL.BLEND_SRC_ALPHA = 32971;
		haxor.platform.graphics.GL.BLEND_SRC_RGB = 32969;
		haxor.platform.graphics.GL.BLUE_BITS = 3412;
		haxor.platform.graphics.GL.BOOL = 35670;
		haxor.platform.graphics.GL.BOOL_VEC2 = 35671;
		haxor.platform.graphics.GL.BOOL_VEC3 = 35672;
		haxor.platform.graphics.GL.BOOL_VEC4 = 35673;
		haxor.platform.graphics.GL.BROWSER_DEFAULT_WEBGL = 37444;
		haxor.platform.graphics.GL.BUFFER_SIZE = 34660;
		haxor.platform.graphics.GL.BUFFER_USAGE = 34661;
		haxor.platform.graphics.GL.BYTE = 5120;
		haxor.platform.graphics.GL.CCW = 2305;
		haxor.platform.graphics.GL.CLAMP_TO_EDGE = 33071;
		haxor.platform.graphics.GL.COLOR_ATTACHMENT0 = 36064;
		haxor.platform.graphics.GL.COLOR_BUFFER_BIT = 16384;
		haxor.platform.graphics.GL.COLOR_CLEAR_VALUE = 3106;
		haxor.platform.graphics.GL.COLOR_WRITEMASK = 3107;
		haxor.platform.graphics.GL.COMPILE_STATUS = 35713;
		haxor.platform.graphics.GL.COMPRESSED_TEXTURE_FORMATS = 34467;
		haxor.platform.graphics.GL.CONSTANT_ALPHA = 32771;
		haxor.platform.graphics.GL.CONSTANT_COLOR = 32769;
		haxor.platform.graphics.GL.CONTEXT_LOST_WEBGL = 37442;
		haxor.platform.graphics.GL.CULL_FACE = 2884;
		haxor.platform.graphics.GL.CULL_FACE_MODE = 2885;
		haxor.platform.graphics.GL.CURRENT_PROGRAM = 35725;
		haxor.platform.graphics.GL.CURRENT_VERTEX_ATTRIB = 34342;
		haxor.platform.graphics.GL.CW = 2304;
		haxor.platform.graphics.GL.DECR = 7683;
		haxor.platform.graphics.GL.DECR_WRAP = 34056;
		haxor.platform.graphics.GL.DELETE_STATUS = 35712;
		haxor.platform.graphics.GL.DEPTH_ATTACHMENT = 36096;
		haxor.platform.graphics.GL.DEPTH_BITS = 3414;
		haxor.platform.graphics.GL.DEPTH_BUFFER_BIT = 256;
		haxor.platform.graphics.GL.DEPTH_CLEAR_VALUE = 2931;
		haxor.platform.graphics.GL.DEPTH_COMPONENT = 6402;
		haxor.platform.graphics.GL.DEPTH_COMPONENT16 = 33189;
		haxor.platform.graphics.GL.DEPTH_FUNC = 2932;
		haxor.platform.graphics.GL.DEPTH_RANGE = 2928;
		haxor.platform.graphics.GL.DEPTH_STENCIL = 34041;
		haxor.platform.graphics.GL.DEPTH_STENCIL_ATTACHMENT = 33306;
		haxor.platform.graphics.GL.DEPTH_TEST = 2929;
		haxor.platform.graphics.GL.DEPTH_WRITEMASK = 2930;
		haxor.platform.graphics.GL.DITHER = 3024;
		haxor.platform.graphics.GL.DONT_CARE = 4352;
		haxor.platform.graphics.GL.DST_ALPHA = 772;
		haxor.platform.graphics.GL.DST_COLOR = 774;
		haxor.platform.graphics.GL.DYNAMIC_DRAW = 35048;
		haxor.platform.graphics.GL.ELEMENT_ARRAY_BUFFER = 34963;
		haxor.platform.graphics.GL.ELEMENT_ARRAY_BUFFER_BINDING = 34965;
		haxor.platform.graphics.GL.EQUAL = 514;
		haxor.platform.graphics.GL.FASTEST = 4353;
		haxor.platform.graphics.GL.FLOAT = 5126;
		haxor.platform.graphics.GL.FLOAT_MAT2 = 35674;
		haxor.platform.graphics.GL.FLOAT_MAT3 = 35675;
		haxor.platform.graphics.GL.FLOAT_MAT4 = 35676;
		haxor.platform.graphics.GL.FLOAT_VEC2 = 35664;
		haxor.platform.graphics.GL.FLOAT_VEC3 = 35665;
		haxor.platform.graphics.GL.FLOAT_VEC4 = 35666;
		haxor.platform.graphics.GL.FRAGMENT_SHADER = 35632;
		haxor.platform.graphics.GL.FRAMEBUFFER = 36160;
		haxor.platform.graphics.GL.FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 36049;
		haxor.platform.graphics.GL.FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 36048;
		haxor.platform.graphics.GL.FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 36051;
		haxor.platform.graphics.GL.FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 36050;
		haxor.platform.graphics.GL.FRAMEBUFFER_BINDING = 36006;
		haxor.platform.graphics.GL.FRAMEBUFFER_COMPLETE = 36053;
		haxor.platform.graphics.GL.FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 36054;
		haxor.platform.graphics.GL.FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 36057;
		haxor.platform.graphics.GL.FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 36055;
		haxor.platform.graphics.GL.FRAMEBUFFER_UNSUPPORTED = 36061;
		haxor.platform.graphics.GL.FRONT = 1028;
		haxor.platform.graphics.GL.FRONT_AND_BACK = 1032;
		haxor.platform.graphics.GL.FRONT_FACE = 2886;
		haxor.platform.graphics.GL.FUNC_ADD = 32774;
		haxor.platform.graphics.GL.FUNC_REVERSE_SUBTRACT = 32779;
		haxor.platform.graphics.GL.FUNC_SUBTRACT = 32778;
		haxor.platform.graphics.GL.GENERATE_MIPMAP_HINT = 33170;
		haxor.platform.graphics.GL.GEQUAL = 518;
		haxor.platform.graphics.GL.GREATER = 516;
		haxor.platform.graphics.GL.GREEN_BITS = 3411;
		haxor.platform.graphics.GL.HIGH_FLOAT = 36338;
		haxor.platform.graphics.GL.HIGH_INT = 36341;
		haxor.platform.graphics.GL.INCR = 7682;
		haxor.platform.graphics.GL.INCR_WRAP = 34055;
		haxor.platform.graphics.GL.INT = 5124;
		haxor.platform.graphics.GL.INT_VEC2 = 35667;
		haxor.platform.graphics.GL.INT_VEC3 = 35668;
		haxor.platform.graphics.GL.INT_VEC4 = 35669;
		haxor.platform.graphics.GL.INVALID_ENUM = 1280;
		haxor.platform.graphics.GL.INVALID_FRAMEBUFFER_OPERATION = 1286;
		haxor.platform.graphics.GL.INVALID_OPERATION = 1282;
		haxor.platform.graphics.GL.INVALID_VALUE = 1281;
		haxor.platform.graphics.GL.INVERT = 5386;
		haxor.platform.graphics.GL.KEEP = 7680;
		haxor.platform.graphics.GL.LEQUAL = 515;
		haxor.platform.graphics.GL.LESS = 513;
		haxor.platform.graphics.GL.LINEAR = 9729;
		haxor.platform.graphics.GL.LINEAR_MIPMAP_LINEAR = 9987;
		haxor.platform.graphics.GL.LINEAR_MIPMAP_NEAREST = 9985;
		haxor.platform.graphics.GL.LINES = 1;
		haxor.platform.graphics.GL.LINE_LOOP = 2;
		haxor.platform.graphics.GL.LINE_STRIP = 3;
		haxor.platform.graphics.GL.LINE_WIDTH = 2849;
		haxor.platform.graphics.GL.LINK_STATUS = 35714;
		haxor.platform.graphics.GL.LOW_FLOAT = 36336;
		haxor.platform.graphics.GL.LOW_INT = 36339;
		haxor.platform.graphics.GL.LUMINANCE = 6409;
		haxor.platform.graphics.GL.LUMINANCE_ALPHA = 6410;
		haxor.platform.graphics.GL.MAX_COMBINED_TEXTURE_IMAGE_UNITS = 35661;
		haxor.platform.graphics.GL.MAX_CUBE_MAP_TEXTURE_SIZE = 34076;
		haxor.platform.graphics.GL.MAX_FRAGMENT_UNIFORM_VECTORS = 36349;
		haxor.platform.graphics.GL.MAX_RENDERBUFFER_SIZE = 34024;
		haxor.platform.graphics.GL.MAX_TEXTURE_IMAGE_UNITS = 34930;
		haxor.platform.graphics.GL.MAX_TEXTURE_SIZE = 3379;
		haxor.platform.graphics.GL.MAX_VARYING_VECTORS = 36348;
		haxor.platform.graphics.GL.MAX_VERTEX_ATTRIBS = 34921;
		haxor.platform.graphics.GL.MAX_VERTEX_TEXTURE_IMAGE_UNITS = 35660;
		haxor.platform.graphics.GL.MAX_VERTEX_UNIFORM_VECTORS = 36347;
		haxor.platform.graphics.GL.MAX_VIEWPORT_DIMS = 3386;
		haxor.platform.graphics.GL.MEDIUM_FLOAT = 36337;
		haxor.platform.graphics.GL.MEDIUM_INT = 36340;
		haxor.platform.graphics.GL.MIRRORED_REPEAT = 33648;
		haxor.platform.graphics.GL.NEAREST = 9728;
		haxor.platform.graphics.GL.NEAREST_MIPMAP_LINEAR = 9986;
		haxor.platform.graphics.GL.NEAREST_MIPMAP_NEAREST = 9984;
		haxor.platform.graphics.GL.NEVER = 512;
		haxor.platform.graphics.GL.NICEST = 4354;
		haxor.platform.graphics.GL.NONE = 0;
		haxor.platform.graphics.GL.NOTEQUAL = 517;
		haxor.platform.graphics.GL.NO_ERROR_GL = 0;
		haxor.platform.graphics.GL.ONE = 1;
		haxor.platform.graphics.GL.ONE_MINUS_CONSTANT_ALPHA = 32772;
		haxor.platform.graphics.GL.ONE_MINUS_CONSTANT_COLOR = 32770;
		haxor.platform.graphics.GL.ONE_MINUS_DST_ALPHA = 773;
		haxor.platform.graphics.GL.ONE_MINUS_DST_COLOR = 775;
		haxor.platform.graphics.GL.ONE_MINUS_SRC_ALPHA = 771;
		haxor.platform.graphics.GL.ONE_MINUS_SRC_COLOR = 769;
		haxor.platform.graphics.GL.OUT_OF_MEMORY = 1285;
		haxor.platform.graphics.GL.PACK_ALIGNMENT = 3333;
		haxor.platform.graphics.GL.POINTS = 0;
		haxor.platform.graphics.GL.POLYGON_OFFSET_FACTOR = 32824;
		haxor.platform.graphics.GL.POLYGON_OFFSET_FILL = 32823;
		haxor.platform.graphics.GL.POLYGON_OFFSET_UNITS = 10752;
		haxor.platform.graphics.GL.RED_BITS = 3410;
		haxor.platform.graphics.GL.RENDERBUFFER = 36161;
		haxor.platform.graphics.GL.RENDERBUFFER_ALPHA_SIZE = 36179;
		haxor.platform.graphics.GL.RENDERBUFFER_BINDING = 36007;
		haxor.platform.graphics.GL.RENDERBUFFER_BLUE_SIZE = 36178;
		haxor.platform.graphics.GL.RENDERBUFFER_DEPTH_SIZE = 36180;
		haxor.platform.graphics.GL.RENDERBUFFER_GREEN_SIZE = 36177;
		haxor.platform.graphics.GL.RENDERBUFFER_HEIGHT = 36163;
		haxor.platform.graphics.GL.RENDERBUFFER_INTERNAL_FORMAT = 36164;
		haxor.platform.graphics.GL.RENDERBUFFER_RED_SIZE = 36176;
		haxor.platform.graphics.GL.RENDERBUFFER_STENCIL_SIZE = 36181;
		haxor.platform.graphics.GL.RENDERBUFFER_WIDTH = 36162;
		haxor.platform.graphics.GL.RENDERER = 7937;
		haxor.platform.graphics.GL.REPEAT = 10497;
		haxor.platform.graphics.GL.REPLACE = 7681;
		haxor.platform.graphics.GL.RGB = 6407;
		haxor.platform.graphics.GL.RGB565 = 36194;
		haxor.platform.graphics.GL.RGB5_A1 = 32855;
		haxor.platform.graphics.GL.RGBA = 6408;
		haxor.platform.graphics.GL.RGBA4 = 32854;
		haxor.platform.graphics.GL.SAMPLER_2D = 35678;
		haxor.platform.graphics.GL.SAMPLER_CUBE = 35680;
		haxor.platform.graphics.GL.SAMPLES = 32937;
		haxor.platform.graphics.GL.SAMPLE_ALPHA_TO_COVERAGE = 32926;
		haxor.platform.graphics.GL.SAMPLE_BUFFERS = 32936;
		haxor.platform.graphics.GL.SAMPLE_COVERAGE = 32928;
		haxor.platform.graphics.GL.SAMPLE_COVERAGE_INVERT = 32939;
		haxor.platform.graphics.GL.SAMPLE_COVERAGE_VALUE = 32938;
		haxor.platform.graphics.GL.SCISSOR_BOX = 3088;
		haxor.platform.graphics.GL.SCISSOR_TEST = 3089;
		haxor.platform.graphics.GL.SHADER_TYPE = 35663;
		haxor.platform.graphics.GL.SHADING_LANGUAGE_VERSION = 35724;
		haxor.platform.graphics.GL.SHORT = 5122;
		haxor.platform.graphics.GL.SRC_ALPHA = 770;
		haxor.platform.graphics.GL.SRC_ALPHA_SATURATE = 776;
		haxor.platform.graphics.GL.SRC_COLOR = 768;
		haxor.platform.graphics.GL.STATIC_DRAW = 35044;
		haxor.platform.graphics.GL.STENCIL_ATTACHMENT = 36128;
		haxor.platform.graphics.GL.STENCIL_BACK_FAIL = 34817;
		haxor.platform.graphics.GL.STENCIL_BACK_FUNC = 34816;
		haxor.platform.graphics.GL.STENCIL_BACK_PASS_DEPTH_FAIL = 34818;
		haxor.platform.graphics.GL.STENCIL_BACK_PASS_DEPTH_PASS = 34819;
		haxor.platform.graphics.GL.STENCIL_BACK_REF = 36003;
		haxor.platform.graphics.GL.STENCIL_BACK_VALUE_MASK = 36004;
		haxor.platform.graphics.GL.STENCIL_BACK_WRITEMASK = 36005;
		haxor.platform.graphics.GL.STENCIL_BITS = 3415;
		haxor.platform.graphics.GL.STENCIL_BUFFER_BIT = 1024;
		haxor.platform.graphics.GL.STENCIL_CLEAR_VALUE = 2961;
		haxor.platform.graphics.GL.STENCIL_FAIL = 2964;
		haxor.platform.graphics.GL.STENCIL_FUNC = 2962;
		haxor.platform.graphics.GL.STENCIL_INDEX = 6401;
		haxor.platform.graphics.GL.STENCIL_INDEX8 = 36168;
		haxor.platform.graphics.GL.STENCIL_PASS_DEPTH_FAIL = 2965;
		haxor.platform.graphics.GL.STENCIL_PASS_DEPTH_PASS = 2966;
		haxor.platform.graphics.GL.STENCIL_REF = 2967;
		haxor.platform.graphics.GL.STENCIL_TEST = 2960;
		haxor.platform.graphics.GL.STENCIL_VALUE_MASK = 2963;
		haxor.platform.graphics.GL.STENCIL_WRITEMASK = 2968;
		haxor.platform.graphics.GL.STREAM_DRAW = 35040;
		haxor.platform.graphics.GL.SUBPIXEL_BITS = 3408;
		haxor.platform.graphics.GL.TEXTURE = 5890;
		haxor.platform.graphics.GL.TEXTURE0 = 33984;
		haxor.platform.graphics.GL.TEXTURE1 = 33985;
		haxor.platform.graphics.GL.TEXTURE10 = 33994;
		haxor.platform.graphics.GL.TEXTURE11 = 33995;
		haxor.platform.graphics.GL.TEXTURE12 = 33996;
		haxor.platform.graphics.GL.TEXTURE13 = 33997;
		haxor.platform.graphics.GL.TEXTURE14 = 33998;
		haxor.platform.graphics.GL.TEXTURE15 = 33999;
		haxor.platform.graphics.GL.TEXTURE16 = 34000;
		haxor.platform.graphics.GL.TEXTURE17 = 34001;
		haxor.platform.graphics.GL.TEXTURE18 = 34002;
		haxor.platform.graphics.GL.TEXTURE19 = 34003;
		haxor.platform.graphics.GL.TEXTURE2 = 33986;
		haxor.platform.graphics.GL.TEXTURE20 = 34004;
		haxor.platform.graphics.GL.TEXTURE21 = 34005;
		haxor.platform.graphics.GL.TEXTURE22 = 34006;
		haxor.platform.graphics.GL.TEXTURE23 = 34007;
		haxor.platform.graphics.GL.TEXTURE24 = 34008;
		haxor.platform.graphics.GL.TEXTURE25 = 34009;
		haxor.platform.graphics.GL.TEXTURE26 = 34010;
		haxor.platform.graphics.GL.TEXTURE27 = 34011;
		haxor.platform.graphics.GL.TEXTURE28 = 34012;
		haxor.platform.graphics.GL.TEXTURE29 = 34013;
		haxor.platform.graphics.GL.TEXTURE3 = 33987;
		haxor.platform.graphics.GL.TEXTURE30 = 34014;
		haxor.platform.graphics.GL.TEXTURE31 = 34015;
		haxor.platform.graphics.GL.TEXTURE4 = 33988;
		haxor.platform.graphics.GL.TEXTURE5 = 33989;
		haxor.platform.graphics.GL.TEXTURE6 = 33990;
		haxor.platform.graphics.GL.TEXTURE7 = 33991;
		haxor.platform.graphics.GL.TEXTURE8 = 33992;
		haxor.platform.graphics.GL.TEXTURE9 = 33993;
		haxor.platform.graphics.GL.TEXTURE_2D = 3553;
		haxor.platform.graphics.GL.TEXTURE_BINDING_2D = 32873;
		haxor.platform.graphics.GL.TEXTURE_BINDING_CUBE_MAP = 34068;
		haxor.platform.graphics.GL.TEXTURE_CUBE_MAP = 34067;
		haxor.platform.graphics.GL.TEXTURE_CUBE_MAP_NEGATIVE_X = 34070;
		haxor.platform.graphics.GL.TEXTURE_CUBE_MAP_NEGATIVE_Y = 34072;
		haxor.platform.graphics.GL.TEXTURE_CUBE_MAP_NEGATIVE_Z = 34074;
		haxor.platform.graphics.GL.TEXTURE_CUBE_MAP_POSITIVE_X = 34069;
		haxor.platform.graphics.GL.TEXTURE_CUBE_MAP_POSITIVE_Y = 34071;
		haxor.platform.graphics.GL.TEXTURE_CUBE_MAP_POSITIVE_Z = 34073;
		haxor.platform.graphics.GL.TEXTURE_MAG_FILTER = 10240;
		haxor.platform.graphics.GL.TEXTURE_MIN_FILTER = 10241;
		haxor.platform.graphics.GL.TEXTURE_WRAP_S = 10242;
		haxor.platform.graphics.GL.TEXTURE_WRAP_T = 10243;
		haxor.platform.graphics.GL.TRIANGLES = 4;
		haxor.platform.graphics.GL.TRIANGLE_FAN = 6;
		haxor.platform.graphics.GL.TRIANGLE_STRIP = 5;
		haxor.platform.graphics.GL.UNPACK_ALIGNMENT = 3317;
		haxor.platform.graphics.GL.UNPACK_COLORSPACE_CONVERSION_WEBGL = 37443;
		haxor.platform.graphics.GL.UNPACK_FLIP_Y_WEBGL = 37440;
		haxor.platform.graphics.GL.UNPACK_PREMULTIPLY_ALPHA_WEBGL = 37441;
		haxor.platform.graphics.GL.UNSIGNED_BYTE = 5121;
		haxor.platform.graphics.GL.UNSIGNED_INT = 5125;
		haxor.platform.graphics.GL.UNSIGNED_SHORT = 5123;
		haxor.platform.graphics.GL.UNSIGNED_SHORT_4_4_4_4 = 32819;
		haxor.platform.graphics.GL.UNSIGNED_SHORT_5_5_5_1 = 32820;
		haxor.platform.graphics.GL.UNSIGNED_SHORT_5_6_5 = 33635;
		haxor.platform.graphics.GL.VALIDATE_STATUS = 35715;
		haxor.platform.graphics.GL.VENDOR = 7936;
		haxor.platform.graphics.GL.VERSION = 7938;
		haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 34975;
		haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_ENABLED = 34338;
		haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_NORMALIZED = 34922;
		haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_POINTER = 34373;
		haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_SIZE = 34339;
		haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_STRIDE = 34340;
		haxor.platform.graphics.GL.VERTEX_ATTRIB_ARRAY_TYPE = 34341;
		haxor.platform.graphics.GL.VERTEX_SHADER = 35633;
		haxor.platform.graphics.GL.VIEWPORT = 2978;
		haxor.platform.graphics.GL.ZERO = 0;
		haxor.platform.graphics.GL.NULL = -1;
	}
	public    GL(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    GL()
	{
		haxor.platform.graphics.GL.__hx_ctor_haxor_platform_graphics_GL(this);
	}
	
	
	public static   void __hx_ctor_haxor_platform_graphics_GL(haxor.platform.graphics.GL __temp_me21775)
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
	
	public static  int NULL;
	
	
	
	public static   haxor.platform.graphics.GraphicAPI get_api()
	{
		return haxor.platform.graphics.GL.m_gl.get_api();
	}
	
	
	public static  haxor.platform.graphics.AndroidGL m_gl;
	
	public static   void Initialize(haxor.core.BaseApplication p_application)
	{
		haxor.platform.graphics.GL.m_gl = new haxor.platform.graphics.AndroidGL(((haxor.core.BaseApplication) (p_application) ));
		haxor.platform.graphics.GL.m_gl.CheckExtensions();
	}
	
	
	public static   void Resize()
	{
		haxor.platform.graphics.GL.m_gl.Resize();
	}
	
	
	public static   void BindBuffer(int p_target, int p_id)
	{
		haxor.platform.graphics.GL.m_gl.BindBuffer(p_target, p_id);
	}
	
	
	public static   void BufferData(int p_target, haxor.io.Buffer p_data, int p_mode)
	{
		haxor.platform.graphics.GL.m_gl.BufferData(p_target, p_data, p_mode);
	}
	
	
	public static   void BufferSubData(int p_target, int p_offset, haxor.io.Buffer p_data)
	{
		haxor.platform.graphics.GL.m_gl.BufferSubData(p_target, p_offset, p_data);
	}
	
	
	public static   int CreateBuffer()
	{
		return haxor.platform.graphics.GL.m_gl.CreateBuffer();
	}
	
	
	public static   void DrawArrays(int p_primitive, int p_start, int p_count)
	{
		haxor.platform.graphics.GL.m_gl.DrawArrays(p_primitive, p_start, p_count);
	}
	
	
	public static   void DrawElements(int p_primitive, int p_count, int p_type, int p_offset)
	{
		haxor.platform.graphics.GL.m_gl.DrawElements(p_primitive, p_count, p_type, p_offset);
	}
	
	
	public static   void DeleteBuffer(int p_id)
	{
		haxor.platform.graphics.GL.m_gl.DeleteBuffer(p_id);
	}
	
	
	public static   void DisableVertexAttrib(int p_location)
	{
		haxor.platform.graphics.GL.m_gl.DisableVertexAttrib(p_location);
	}
	
	
	public static   void EnableVertexAttrib(int p_location)
	{
		haxor.platform.graphics.GL.m_gl.EnableVertexAttrib(p_location);
	}
	
	
	public static   void VertexAttrib3f(int p_location, double p_x, double p_y, double p_z)
	{
		haxor.platform.graphics.GL.m_gl.VertexAttrib3f(p_location, p_x, p_y, p_z);
	}
	
	
	public static   void VertexAttrib4f(int p_location, double p_x, double p_y, double p_z, double p_w)
	{
		haxor.platform.graphics.GL.m_gl.VertexAttrib4f(p_location, p_x, p_y, p_z, p_w);
	}
	
	
	public static   void VertexAttribPointer(int p_location, int p_components_size, int p_type, boolean p_normalized, int p_stride, int p_offset)
	{
		haxor.platform.graphics.GL.m_gl.VertexAttribPointer(p_location, p_components_size, p_type, p_normalized, p_stride, p_offset);
	}
	
	
	public static   void CompileShader(int p_shader)
	{
		haxor.platform.graphics.GL.m_gl.CompileShader(p_shader);
	}
	
	
	public static   int CreateShader(int p_type)
	{
		return haxor.platform.graphics.GL.m_gl.CreateShader(p_type);
	}
	
	
	public static   void DetachShader(int p_program, int p_shader)
	{
		haxor.platform.graphics.GL.m_gl.DetachShader(p_program, p_shader);
	}
	
	
	public static   void DeleteShader(int p_shader)
	{
		haxor.platform.graphics.GL.m_gl.DeleteShader(p_shader);
	}
	
	
	public static   java.lang.String GetShaderInfoLog(int p_shader)
	{
		return haxor.platform.graphics.GL.m_gl.GetShaderInfoLog(p_shader);
	}
	
	
	public static   int GetShaderParameter(int p_shader, int p_parameter)
	{
		return haxor.platform.graphics.GL.m_gl.GetShaderParameter(p_shader, p_parameter);
	}
	
	
	public static   void ShaderSource(int p_shader, java.lang.String p_source)
	{
		haxor.platform.graphics.GL.m_gl.ShaderSource(p_shader, p_source);
	}
	
	
	public static   void AttachShader(int p_program, int p_shader)
	{
		haxor.platform.graphics.GL.m_gl.AttachShader(p_program, p_shader);
	}
	
	
	public static   void BindAttribLocation(int p_program, int p_location, java.lang.String p_name)
	{
		haxor.platform.graphics.GL.m_gl.BindAttribLocation(p_program, p_location, p_name);
	}
	
	
	public static   int CreateProgram()
	{
		return haxor.platform.graphics.GL.m_gl.CreateProgram();
	}
	
	
	public static   void DeleteProgram(int p_program)
	{
		haxor.platform.graphics.GL.m_gl.DeleteProgram(p_program);
	}
	
	
	public static   int GetAttribLocation(int p_program, java.lang.String p_name)
	{
		return haxor.platform.graphics.GL.m_gl.GetAttribLocation(p_program, p_name);
	}
	
	
	public static   java.lang.String GetProgramInfoLog(int p_program)
	{
		return haxor.platform.graphics.GL.m_gl.GetProgramInfoLog(p_program);
	}
	
	
	public static   int GetProgramParameter(int p_program, int p_parameter)
	{
		return haxor.platform.graphics.GL.m_gl.GetProgramParameter(p_program, p_parameter);
	}
	
	
	public static   void LinkProgram(int p_program)
	{
		haxor.platform.graphics.GL.m_gl.LinkProgram(p_program);
	}
	
	
	public static   void UseProgram(int p_program)
	{
		haxor.platform.graphics.GL.m_gl.UseProgram(p_program);
	}
	
	
	public static   void BlendFunc(int p_src, int p_dst)
	{
		haxor.platform.graphics.GL.m_gl.BlendFunc(p_src, p_dst);
	}
	
	
	public static   void Disable(int p_flag)
	{
		haxor.platform.graphics.GL.m_gl.Disable(p_flag);
	}
	
	
	public static   void Enable(int p_flag)
	{
		haxor.platform.graphics.GL.m_gl.Enable(p_flag);
	}
	
	
	public static   void DepthMask(boolean p_flag)
	{
		haxor.platform.graphics.GL.m_gl.DepthMask(p_flag);
	}
	
	
	public static   void DepthFunc(int p_flag)
	{
		haxor.platform.graphics.GL.m_gl.DepthFunc(p_flag);
	}
	
	
	public static   void CullFace(int p_face)
	{
		haxor.platform.graphics.GL.m_gl.CullFace(p_face);
	}
	
	
	public static   void FrontFace(int p_face)
	{
		haxor.platform.graphics.GL.m_gl.FrontFace(p_face);
	}
	
	
	public static   void Clear(int p_flag)
	{
		haxor.platform.graphics.GL.m_gl.Clear(p_flag);
	}
	
	
	public static   void ClearDepth(double p_value)
	{
		haxor.platform.graphics.GL.m_gl.ClearDepth(p_value);
	}
	
	
	public static   void ClearColor(double p_r, double p_g, double p_b, double p_a)
	{
		haxor.platform.graphics.GL.m_gl.ClearColor(p_r, p_g, p_b, p_a);
	}
	
	
	public static   java.lang.String GetError()
	{
		return haxor.platform.graphics.GL.m_gl.GetError();
	}
	
	
	public static   int GetErrorCode()
	{
		return haxor.platform.graphics.GL.m_gl.GetErrorCode();
	}
	
	
	public static   java.lang.String GetErrorString(int p_code)
	{
		return haxor.platform.graphics.GL.m_gl.GetErrorString(p_code);
	}
	
	
	public static   void LogError()
	{
		haxor.platform.graphics.GL.m_gl.LogError();
	}
	
	
	public static   void Assert(java.lang.String p_log)
	{
		haxor.platform.graphics.GL.m_gl.Assert(p_log);
	}
	
	
	public static   void Flush()
	{
		haxor.platform.graphics.GL.m_gl.Flush();
	}
	
	
	public static   void Focus()
	{
		haxor.platform.graphics.GL.m_gl.Focus();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.graphics.GL(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.graphics.GL();
	}
	
	
}


