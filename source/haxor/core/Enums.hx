package haxor.core;

import haxor.graphics.GL;


/**
 * File that describes the enumerations used for the engine.
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
	static public inline var Background : Int 	= 0;
	
	/**
	 * Opaque objects layer.
	 */
	static public inline var Opaque : Int 		= 1000;
	
	/**
	 * Transparent objects layer.
	 */
	static public inline var Transparent : Int 	= 2000;
	
	/**
	 * Overlay objects layer.
	 */
	static public inline var Overlay : Int 		= 3000;
	
	/**
	 * UI layer.
	 */
	static public inline var Interface : Int 	= 4000;
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
	static public inline var Zero 						: Int 	= GL.ZERO;
	
	/**
	 * Multiplies the target pixel by one.
	 */
	static public inline var One 						: Int	= GL.ONE;
	
	/**
	 * Multiplies the incoming pixel by its color.
	 */
	static public inline var SrcColor 					: Int	= GL.SRC_COLOR;
	
	/**
	 * Multiplies the incoming pixel by its reverse color.
	 */
	static public inline var OneMinusSrcColor 			: Int	= GL.ONE_MINUS_SRC_COLOR;
	
	/**
	 * Multiplies the incoming pixel by its alpha.
	 */
	static public inline var SrcAlpha 					: Int	= GL.SRC_ALPHA;
	
	/**
	 * Multiplies the incoming pixel by its reverse alpha.
	 */
	static public inline var OneMinusSrcAlpha 			: Int	= GL.ONE_MINUS_SRC_ALPHA;
	
	/**
	 * Multiplies the incoming pixel by the screen's pixel alpha.
	 */
	static public inline var DstAlpha 					: Int	= GL.DST_ALPHA;
	
	/**
	 * Multiplies the incoming pixel by the screen's reverse pixel alpha.
	 */
	static public inline var OneMinusDstAlpha 			: Int	= GL.ONE_MINUS_DST_ALPHA;
	
	/**
	 * Multiplies the incoming pixel by the screen's pixel color.
	 */
	static public inline var DstColor 					: Int	= GL.DST_COLOR;
	
	/**
	 * Multiplies the incoming pixel by the screen's reverse pixel color.
	 */
	static public inline var OneMinusDstColor 			: Int	= GL.ONE_MINUS_DST_COLOR;
	
	/**
	 *  (f,f,f,1); f = min(Asrc, 1 − Adst)
	 */
	static public inline var SrcAlphaSaturate 			: Int	= GL.SRC_ALPHA_SATURATE;
	
}


/**
 * Storage type of the mesh.
 */
class MeshMode
{
	/**
	 * Static IO mode.
	 */
	static public inline var StaticDraw : Int = GL.STATIC_DRAW;
	
	/**
	 * Stream IO mode.
	 */
	static public inline var StreamDraw : Int = GL.STREAM_DRAW;
	
	/**
	 * Dynamic IO mode.
	 */
	static public inline var DynamicDraw : Int = GL.DYNAMIC_DRAW;
}

/**
 * Geometry primitive that will describe the mesh vertices.
 */
class MeshPrimitive
{
	/**
	 * Point.
	 */
	static public inline var Points : Int = GL.POINTS;
	
	/**
	 * Triangle.
	 */
	static public inline var Triangles : Int = GL.TRIANGLES;
	
	/**
	 * TriangleStrip.
	 */
	static public inline var TriangleStrip : Int = GL.TRIANGLE_STRIP;
	
	/**
	 * Triangle Fan.
	 */
	static public inline var TriangleFan : Int = GL.TRIANGLE_FAN;
	
	/**
	 * Line.
	 */
	static public inline var Lines : Int = GL.LINES;
	
	/**
	 * Line Loop.
	 */
	static public inline var LineLoop : Int = GL.LINE_LOOP;
	
	/**
	 * Line Strip.
	 */
	static public inline var LineStrip : Int = GL.LINE_STRIP;
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
	static public inline var None:Int  = 0;
	
	/**
	 * Don't render front facing triangles.
	 */
	static public inline var Front:Int = 1;
	
	/**
	 * Don't render back facing triangles.
	 */
	static public inline var Back:Int  = 2;
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
	static public inline var Never        :Int = GL.NEVER;
	
	/**
	 * 
	 */
	static public inline var Less         :Int = GL.LESS;
	
	/**
	 * 
	 */
	static public inline var Equal        :Int = GL.EQUAL;
	
	/**
	 * 
	 */
	static public inline var LessEqual    :Int = GL.LEQUAL;
	
	/**
	 * 
	 */
	static public inline var Greater      :Int = GL.GREATER;
	
	/**
	 * 
	 */
	static public inline var NotEqual     :Int = GL.NOTEQUAL;
	
	/**
	 * 
	 */
	static public inline var GreaterEqual :Int = GL.GEQUAL;
	
	/**
	 * 
	 */
	static public inline var Always       :Int = GL.ALWAYS;
} 


/**
 * Enumeration that describes the camera projection matrix mode.
 */
enum CameraMode
{
	/**
	 * Camera expects the user to set the perspective matrix.
	 */
	Custom;
	/**
	 * Perspective matrix mode.
	 */
	Perspective;
	/**
	 * Orthographic projection mode.
	 */	
	Ortho;
	/**
	 * Orthographic screen mode.
	 */
	UI;	
}


/**
 * Enumeration that describes the channel format of the Bitmap/Texture.
 */
enum PixelFormat
{
	Alpha8;
	Luminance;	
	RGB8;
	RGBA8;	
	Half;
	Half3;
	Half4;
	Float;
	Float3;
	Float4;
	Depth;
	//RGBA16;
	//RGBA == L
	//Alpha16;
}


/**
 * Texture Filtering enumeration.
 */
enum TextureFilter
{            
	/**
	 * Nearest pixel.
	 */
	Nearest; 		
	/**
	 * Bilinear interpolation.
	 */
	Linear; 				 
	/**
	 * Nearest downsample with nearest upsample in the mipmap.
	 */
	NearestMipmapNearest;
	/**
	 * Nearest downsample with linear upsample in the mipmap.
	 */
	NearestMipmapLinear;             
	/**
	 * Linear downsample with nearest upsample in the mipmap.
	 */
	LinearMipmapNearest;             
	/**
	 * Linear downsample with linear upsample in the mipmap.
	 */
	LinearMipmapLinear;               
	/**
	 * Linear downsample with linear upsample in the mipmap.
	 */
	Trilinear; 			 	
}

/**
 * Wrapping mode bits of the texture. More than one can be combined.
 */
class TextureWrap
{   
	
	/**
	 * Clamp U coordinate.
	 */
	static public var ClampX  = 1;
	/**
	 * Repeat U coordinate.
	 */
	static public var RepeatX = 2;            
	/**
	 * Clamp V coordinate.
	 */
	static public var ClampY  = 4;           
	/**
	 * Repeat V coordinate.
	 */
	static public var RepeatY = 8;
	/**
	 * Clamp W coordinate. (TBD)
	 */
	static public var ClampZ  = 16;          
	/**
	 * Repeat W coordinate. (TBD)
	 */
	static public var RepeatZ = 32;
}

/**
 * Flag that indicates which type of texture the instanced class represents.
 */
enum TextureType
{
	/**
	 * Invalid Texture type.
	 */
	None;
	/**
	 * 2D Texture Image.
	 */
	Texture2D;
	/**
	 * Cubemap Texture.
	 */
	TextureCube;
	/**
	 * Render Target Texture.
	 */
	RenderTexture;	
	/**
	 * Similar to Texture2D but focused on floating point texels for computing ops.
	 */
	Compute;
}

/**
 * Clear bits for the Camera component.
 * @author Eduardo Pons
 */
class ClearFlag 
{	
	/**
	 * Don't Clear.
	 */
	static public var None:Int			= 0;
	/**
	 * Clear only the Color buffer.
	 */
	static public var Color:Int			= 1;	
	/**
	 * Clear only the DepthBuffer.
	 */
	static public var Depth:Int			= 2;
	/**
	 * Clear the background using only a skybox texture.
	 */
	static public var Skybox:Int		= 4; 
	/**
	 * Clear the Depth and Color buffer.
	 */
	static public var ColorDepth:Int 	= 3;
	/**
	 * Clear the Depth and render the skybox.
	 */
	static public var SkyboxDepth:Int 	= 6;
}

/**
 * Enumeration that describes the state of input elementd.
 */
enum InputState
{
	/**
	 * There is no interaction with the button or key.
	 */
	None;
	
	/**
	 * The button or key are pressed down.
	 */
	Down;
	
	/**
	 * The button or key was released.
	 */
	Up;	
	
	/**
	 * The key or button is being pressed down.
	 */
	Hold;
}

/**
 * Animation Wrapping.
 */
enum AnimationWrap
{            
	/**
	 * Stops at the last frame.
	 */
	Clamp; 			   
	
	/**
	 * Returns to the first frame.
	 */
	Loop; 				 	      
    
	/**
	 * Cycle backwards after last frame.
	 */
	Oscilate;	
}


/**
 * Collider Type.
 */
enum ColliderType
{
	/**
	 * Point Collider.
	 */
	Point;
	/**
	 * Plane Collider.
	 */
	Plane;
	/**
	 * Box Collider.
	 */
	Box;
	/**
	 * Sphere Collider.
	 */
	Sphere;
	/**
	 * Capsule Collider.
	 */
	Capsule;
	/**
	 * Mesh Collider.
	 */
	Mesh;
}
