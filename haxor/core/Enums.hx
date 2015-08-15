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
class CameraMode
{
	/**
	 * Camera expects the user to set the perspective matrix.
	 */
	static public var Custom: Int  = 0;
	/**
	 * Perspective matrix mode.
	 */
	static public var Perspective: Int =1;
	/**
	 * Orthographic projection mode.
	 */	
	static public var Ortho: Int =2;
	/**
	 * Orthographic screen mode.
	 */
	static public var UI: Int =3;	
}


/**
 * Enumeration that describes the channel format of the Bitmap/Texture.
 */
class PixelFormat
{
	static public var Alpha8	: Int = 0;
	static public var Luminance	: Int = 1;	
	static public var RGB8		: Int = 2;
	static public var RGBA8		: Int = 3;	
	static public var Half		: Int = 4;
	static public var Half3		: Int = 5;
	static public var Half4		: Int = 6;
	static public var Float		: Int = 7;
	static public var Float3	: Int = 8;
	static public var Float4	: Int = 9;
	static public var Depth		: Int = 10;
	static public var sRGB		: Int = 11;
	static public var sRGBA		: Int = 12;
	static public var sRGBA8	: Int = 13;
	//RGBA16;
	//RGBA == L
	//Alpha16;
}


/**
 * Texture Filtering enumeration.
 */
class TextureFilter
{            
	/**
	 * Nearest pixel.
	 */
	static public inline var Nearest: Int 					= 0; 		
	/**
	 * Bilinear interpolation.
	 */
	static public inline var Linear: Int 					= 1; 				 
	/**
	 * Nearest downsample with nearest upsample in the mipmap.
	 */
	static public inline var NearestMipmapNearest: Int 		= 2;
	/**
	 * Nearest downsample with linear upsample in the mipmap.
	 */
	static public inline var NearestMipmapLinear: Int 		= 3;             
	/**
	 * Linear downsample with nearest upsample in the mipmap.
	 */
	static public inline var LinearMipmapNearest: Int 		= 4;             
	/**
	 * Linear downsample with linear upsample in the mipmap.
	 */
	static public inline var LinearMipmapLinear: Int 		= 5;               
	/**
	 * Linear downsample with linear upsample in the mipmap.
	 */
	static public inline var Trilinear: Int 				= 6; 			 	
}

/**
 * Wrapping mode bits of the texture. More than one can be combined.
 */
class TextureWrap
{   
	
	/**
	 * Clamp U coordinate.
	 */
	static public inline var ClampX : Int   = 1;
	/**
	 * Repeat U coordinate.
	 */
	static public inline var RepeatX : Int  = 2;            
	/**
	 * Clamp V coordinate.
	 */
	static public inline var ClampY: Int    = 4;           
	/**
	 * Repeat V coordinate.
	 */
	static public inline var RepeatY: Int   = 8;
	/**
	 * Clamp W coordinate. (TBD)
	 */
	static public inline var ClampZ: Int    = 16;          
	/**
	 * Repeat W coordinate. (TBD)
	 */
	static public inline var RepeatZ: Int   = 32;
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
	static public inline var None:Int			= 0;
	/**
	 * Clear only the Color buffer.
	 */
	static public inline var Color:Int			= 1;	
	/**
	 * Clear only the DepthBuffer.
	 */
	static public inline var Depth:Int			= 2;
	/**
	 * Clear the background using only a skybox texture.
	 */
	static public inline var Skybox:Int			= 4; 
	/**
	 * Clear the Depth and Color buffer.
	 */
	static public inline var ColorDepth:Int 	= 3;
	/**
	 * Clear the Depth and render the skybox.
	 */
	static public inline var SkyboxDepth:Int 	= 6;
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
class AnimationWrap
{            
	/**
	 * Stops at the last frame.
	 */
	static public inline var Clamp:Int 		= 0; 			   
	
	/**
	 * Returns to the first frame.
	 */
	static public inline var Loop:Int 		= 1;
    
	/**
	 * Cycle backwards after last frame.
	 */
	static public inline var Oscilate : Int = 2;	
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
class ForceMode
{
	/**
	 * 
	 */
	static public var Acceleration:Int=0;
	/**
	 * 
	 */
	static public var Force:Int=1;
	/**
	 * 
	 */
	static public var Impulse:Int=2;
	/**
	 * 
	 */
	static public var Velocity:Int=3;
}

/**
 * Quality of skinning.
 */
class BoneQuality
{
	/**
	 * Use global settings.
	 */
	static public var Auto : Int = 0;
	/**
	 * 1 Bone skinning
	 */
	static public var Bone1 : Int = 1;
	/**
	 * 2 Bone skinning
	 */
	static public var Bone2 : Int = 2;
	/**
	 * 3 Bone skinning
	 */
	static public var Bone3 : Int = 3;
	/**
	 * 4 Bone skinning
	 */
	static public var Bone4 : Int = 4;
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
	 * Will apply reflection per vertex.
	 */
	inline static public var ReflectionVertex : Int	= (1 << 5);
	/**
	 * Will apply reflection per pixel.
	 */
	inline static public var ReflectionPixel : Int	= (1 << 6);
	/**
	 * Will use a reflection texture to tint and mask reflection.
	 */
	inline static public var ReflectionTexture : Int	= (1 << 7);
	/**
	 * Will add a falloff effect per vertex.
	 */
	inline static public var FalloffVertex : Int = (1 << 8);
	
	/**
	 * Will add a falloff effect per pixel.
	 */
	inline static public var FalloffPixel : Int = (1 << 9);
	
	/**
	 * Will a bum texture as normals.
	 */
	inline static public var Bump : Int			= (1 << 10);
	/**
	 * Will use lighting per vertex.
	 */
	inline static public var LightingVertex : Int  = (1 << 11);
	/**
	 * Will use lighting per pixel.
	 */
	inline static public var LightingPixel : Int	= (1 << 12);
	/**
	 * Will use deferred lighting.
	 */
	//inline static public var LightingDeferred  : Int = (1 << 13);
	/**
	 * Will have specular component.
	 */
	inline static public var Specular : Int	= (1 << 14);
	/**
	 * Will use a Specular texture to tint and mask the specular component.
	 */
	inline static public var SpecularTexture : Int	= (1 << 15);
	/**
	 * Will use the alpha channel of the DiffuseTexture as Specular mask.
	 */
	inline static public var SpecularAlpha : Int	= (1 << 16);
	/**
	 * Will use a lightmap texture combined with the diffuse elements.
	 */
	inline static public var Lightmap : Int	= (1 << 17);
	/**
	 * Will apply fog per vertex.
	 */
	inline static public var FogVertex	 : Int	= (1 << 18);
	/**
	 * Will apply fog per pixel.
	 */
	inline static public var FogPixel : Int	= (1 << 18);
	/**
	 * Will use a toon ramp in the diffuse and specular factors.
	 */
	inline static public var Toon : Int		= (1 << 19);
	/**
	 * Will apply an alpha cutoff in the pixel shader.
	 */
	inline static public var Cutoff : Int		= (1 << 20);	
	/**
	 * Will have a particle oriented workflow.
	 */
	inline static public var Particle : Int	= (1 << 21);
	/**
	 * Will scroll the uv0 along Time.
	 */
	inline static public var UVScroll : Int	= (1 << 22);
	/**
	 * Will offer Random features using the internal RandomTexture.
	 */
	inline static public var Random : Int	= (1 << 23);
	/**
	 * Will offer a separated Texture as alpha source.
	 */
	inline static public var AlphaTexture : Int	= (1 << 24);
	/**
	 * Will offer a color to act as emissive component for the shader.
	 */
	inline static public var Emissive : Int	= (1 << 25);
	/**
	 * Will offer a texture to act as emissive component for the shader.
	 */
	inline static public var EmissiveTexture : Int	= (1 << 26);
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
