package haxor.graphics;

/**
 * File that describes the enumerations used for Graphics context.
 */

/**
 * Class that describe the rendering queue of renderers.
 * @author Eduardo Pons
 */
class RenderQueue
{
	/**
	 * Background layer.
	 */
	static public var Background 	= 0;
	
	/**
	 * Opaque objects layer.
	 */
	static public var Opaque 		= 1000;
	
	/**
	 * Transparent objects layer.
	 */
	static public var Transparent 	= 2000;
	
	/**
	 * Overlay objects layer.
	 */
	static public var Overlay 		= 3000;
	
	/**
	 * UI layer.
	 */
	static public var Interface 	= 4000;
}

/**
 * Blending mode flags.
 * @author Eduardo Pons
 */
class BlendMode 
{
	/**
	 * Multiplies the target pixel by zero.
	 */
	static public var Zero 				: Int 	= 0;
	
	/**
	 * Multiplies the target pixel by one.
	 */
	static public var One 				: Int	= 1;
	
	/**
	 * Multiplies the incoming pixel by its color.
	 */
	static public var SrcColor 			: Int	= 0x0300;
	
	/**
	 * Multiplies the incoming pixel by its reverse color.
	 */
	static public var OneMinusSrcColor 	: Int	= 0x0301;
	
	/**
	 * Multiplies the incoming pixel by its alpha.
	 */
	static public var SrcAlpha 			: Int	= 0x0302;
	
	/**
	 * Multiplies the incoming pixel by its reverse alpha.
	 */
	static public var OneMinusSrcAlpha 	: Int	= 0x0303;
	
	/**
	 * Multiplies the incoming pixel by the screen's pixel alpha.
	 */
	static public var DstAlpha 			: Int	= 0x0304;
	
	/**
	 * Multiplies the incoming pixel by the screen's reverse pixel alpha.
	 */
	static public var OneMinusDstAlpha 	: Int	= 0x0305;
	
	/**
	 * Multiplies the incoming pixel by the screen's pixel color.
	 */
	static public var DstColor 			: Int	= 0x0306;
	
	/**
	 * Multiplies the incoming pixel by the screen's reverse pixel color.
	 */
	static public var OneMinusDstColor 	: Int	= 0x0307;
	
	/**
	 *  (f,f,f,1); f = min(Asrc, 1 − Adst)
	 */
	static public var SrcAlphaSaturate 	: Int	= 0x0308;
	
}

/**
 * Storage type of the mesh.
 */
enum MeshMode
{
	/**
	 * Static IO mode.
	 */
	Static;
	
	/**
	 * Stream IO mode.
	 */
	Stream;
	
	/**
	 * Dynamic IO mode.
	 */
	Dynamic;	
}

/**
 * Geometry primitive that will describe the mesh vertices.
 */
enum MeshPrimitive
{
	/**
	 * Point.
	 */
	Points;
	
	/**
	 * Triangle.
	 */
	Triangles;
	
	/**
	 * TriangleStrip.
	 */
	TriangleStrip;
	
	/**
	 * Triangle Fan.
	 */
	TriangleFan;
	
	/**
	 * Line.
	 */
	Lines;
	
	/**
	 * Line Loop.
	 */
	LineLoop;
	
	/**
	 * Line Strip.
	 */
	LineStrip;
}

/**
 * Enumeration that describes the triangle culling method when rendering a mesh.
 * @author Eduardo Pons
 */
class CullMode
{
	/**
	 * No culling. All triangles are rendered.
	 */
	static public var None:Int  = 0;
	
	/**
	 * Don't render front facing triangles.
	 */
	static public var Front:Int = 1;
	
	/**
	 * Don't render back facing triangles.
	 */
	static public var Back:Int  = 2;
}  

/**
 * Depth testing criteria.
 * @author Eduardo Pons
 */
class DepthTest
{
	/**
	 * 
	 */
	static public var Never        :Int = 0x0200;
	
	/**
	 * 
	 */
	static public var Less         :Int = 0x0201;
	
	/**
	 * 
	 */
	static public var Equal        :Int = 0x0202;
	
	/**
	 * 
	 */
	static public var LessEqual    :Int = 0x0203;
	
	/**
	 * 
	 */
	static public var Greater      :Int = 0x0204;
	
	/**
	 * 
	 */
	static public var NotEqual     :Int = 0x0205;
	
	/**
	 * 
	 */
	static public var GreaterEqual :Int = 0x0206;
	
	/**
	 * 
	 */
	static public var Always       :Int = 0x0207;
} 