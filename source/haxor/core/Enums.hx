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
	sRGB;
	sRGBA;
	sRGBA8;
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

/**
 * Enumeration that describes how Force must be applied on a RigidBody
 */
enum ForceMode
{
	/**
	 * 
	 */
	Acceleration;
	/**
	 * 
	 */
	Force;
	/**
	 * 
	 */
	Impulse;
	/**
	 * 
	 */
	Velocity;
}

/**
 * Quality of skinning.
 */
enum BoneQuality
{
	/**
	 * Use global settings.
	 */
	Auto;
	/**
	 * 1 Bone skinning
	 */
	Bone1;
	/**
	 * 2 Bone skinning
	 */
	Bone2;
	/**
	 * 3 Bone skinning
	 */
	Bone3;
	/**
	 * 4 Bone skinning
	 */
	Bone4;
}

/**
 * Enumeration that defines the features a FlexShader will implement.
 */
class ShaderFeature
{
	/**
	 * No feature.
	 */
	inline static public var Empty 	 : Int   	= 0;
	/**
	 * Will have 1 diffuse texture slot.
	 */
	inline static public var Texture : Int 		= (1 << 0);
	/**
	 * Will use a Tint color uniform and apply it in the diffuse factor.
	 */
	inline static public var Tint 	 : Int   	= (1 << 1);
	/**
	 * Will use the vertex color in the diffuse factor.
	 */
	inline static public var VertexColor : Int 	= (1 << 2);
	/**
	 * Will use skinning on the vertex.
	 */
	inline static public var Skinning : Int		= (1 << 3);
	/**
	 * Will apply reflection.
	 */
	inline static public var Reflection : Int	= (1 << 4);
	/**
	 * Will use a reflection texture to tint and mask reflection.
	 */
	inline static public var ReflectionTexture : Int	= (1 << 5);
	/**
	 * Will add a falloff effect per vertex.
	 */
	inline static public var FalloffVertex : Int = (1 << 6);
	
	/**
	 * Will add a falloff effect per pixel.
	 */
	inline static public var FalloffPixel : Int = (1 << 7);
	
	/**
	 * Will a bum texture as normals.
	 */
	inline static public var Bump : Int			= (1 << 8);
	/**
	 * Will use lighting per vertex.
	 */
	inline static public var LightingVertex : Int  = (1 << 9);
	/**
	 * Will use lighting per pixel.
	 */
	inline static public var LightingPixel : Int	= (1 << 10);
	/**
	 * Will use deferred lighting.
	 */
	//inline static public var LightingDeferred  : Int = (1 << 11);
	/**
	 * Will have specular component.
	 */
	inline static public var Specular : Int	= (1 << 12);
	/**
	 * Will use a Specular texture to tint and mask the specular component.
	 */
	inline static public var SpecularTexture : Int	= (1 << 13);
	/**
	 * Will use a lightmap texture combined with the diffuse elements.
	 */
	inline static public var Lightmap : Int	= (1 << 14);
	/**
	 * Will apply fog per vertex.
	 */
	inline static public var FogVertex	 : Int	= (1 << 15);
	/**
	 * Will apply fog per pixel.
	 */
	inline static public var FogPixel : Int	= (1 << 16);
	/**
	 * Will use a toon ramp in the diffuse and specular factors.
	 */
	inline static public var Toon : Int		= (1 << 17);
	/**
	 * Will apply an alpha cutoff in the pixel shader.
	 */
	inline static public var Cutoff : Int		= (1 << 18);	
	/**
	 * Will have a particle oriented workflow.
	 */
	inline static public var Particle : Int	= (1 << 19);
	/**
	 * Will scroll the uv0 along Time.
	 */
	inline static public var UVScroll : Int	= (1 << 20);
	/**
	 * Will offer Random features using the internal RandomTexture.
	 */
	inline static public var Random : Int	= (1 << 21);
}

/**
 * Enumeration that defines the 
 */
class ShaderPrecision
{
	/**
	 * Low precision vertex shader.
	 */
	inline static public var VertexLow : Int		= 1;
	/**
	 * Medium precision vertex shader.
	 */
	inline static public var VertexMed : Int		= 2;
	/**
	 * High precision vertex shader.
	 */
	inline static public var VertexHigh	 : Int	= 4;
	/**
	 * Low precision fragment shader.
	 */
	inline static public var FragmentLow : Int		= 8;
	/**
	 * Medium precision fragment shader.
	 */
	inline static public var FragmentMed : Int		= 16;
	/**
	 * High precision fragment shader.
	 */
	inline static public var FragmentHigh : Int	= 32;	
}
