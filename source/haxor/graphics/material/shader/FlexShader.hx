package haxor.graphics.material.shader;
import haxor.component.light.Light;
import haxor.core.Enums.ShaderFeature;
import haxor.core.Enums.ShaderPrecision;

/**
 * Flexible shader that can be configured with different behaviours.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class FlexShader extends TemplateShader
{
	/**
	 * Bit flags of all features this shader will have.
	 */
	public var features(get_features, set_features):Int;
	private function get_features():Int { return m_features; }
	private function set_features(v:Int):Int 
	{ 
		m_features = v; 	
		ClearPreprocessor();
		if ((v & ShaderFeature.Texture)!=0) 		AddPreprocessor("#define", "TEXTURE");
		if ((v & ShaderFeature.Tint)!=0)    		AddPreprocessor("#define", "TINT");
		if ((v & ShaderFeature.VertexColor)!=0)    	AddPreprocessor("#define", "VERTEX_COLOR");
		if ((v & ShaderFeature.Skinning)!=0)       	{ AddPreprocessor("#define", "SKINNING"); AddPreprocessor("#define", "MAX_BONES", GL.MAX_UNIFORM_BONES+"");  if (GL.BONE_TEXTURE) AddPreprocessor("#define", "BONE_TEXTURE"); }
		if ((v & ShaderFeature.Reflection)!=0)     	AddPreprocessor("#define", "REFLECTION");
		if ((v & ShaderFeature.Falloff)!=0)	    	AddPreprocessor("#define", "FALLOFF");
		if ((v & ShaderFeature.Bump)!=0)		    AddPreprocessor("#define", "BUMP");
		if ((v & ShaderFeature.LightingVertex)!=0) 	AddPreprocessor("#define", "LIGHTING_VERTEX");
		if ((v & ShaderFeature.LightingPixel)!=0)  	AddPreprocessor("#define", "LIGHTING_PIXEL");
		if ((v & ShaderFeature.Specular)!=0)  		AddPreprocessor("#define", "SPECULAR");
		if ((v & ShaderFeature.Lightmap)!=0)  		AddPreprocessor("#define", "LIGHTMAP");
		if ((v & ShaderFeature.FogVertex)!=0) 		AddPreprocessor("#define", "FOG_VERTEX");
		if ((v & ShaderFeature.FogPixel)!=0) 		AddPreprocessor("#define", "FOG_PIXEL");
		if ((v & ShaderFeature.Toon)!=0)	 		AddPreprocessor("#define", "TOON");
		if ((v & ShaderFeature.Cutoff)!=0)	 		AddPreprocessor("#define", "CUTOFF");		
		if ((v & ShaderFeature.Particle)!=0) 		AddPreprocessor("#define", "PARTICLE");
		if ((v & (ShaderFeature.LightingVertex | ShaderFeature.LightingPixel))!=0) AddPreprocessor("#define", "MAX_LIGHT",Light.max+"");
		return v; 
	}
	private var m_features : Int;
	
	
	/**
	 * Creates a FlatShader with a texture or solid color.
	 * @param	p_id
	 * @param	p_texture
	 * @param	p_tint
	 * @param	p_compile
	 */
	public function new(p_id:String,p_features : Int, p_precision : Int = ShaderPrecision.VertexLow | ShaderPrecision.FragmentLow, p_compile:Bool = true) 
	{		
		features = p_features;
		trace(Generate());		
		super(p_id, p_precision, p_compile);		
	}
	
	override function GetVS():String 
	{
		return
		'
		$vs_uniforms
		$vs_attribs
		$g_varyings
		
		void main(void) 
		{		
			mat4 wm = WorldMatrix;
			gl_Position = ((vec4(vertex, 1.0) * wm) * ViewMatrix) * ProjectionMatrix;						
			v_color = vec4(1, 1, 1, 1);			
			#ifdef VERTEX_COLOR
			v_color *= color;
			#endif			
			#ifdef TINT
			v_color *= Tint;
			#endif
			#ifdef TEXTURE
			v_uv0 = uv0;
			#endif
		}		
		';
	}
	
	override function GetFS():String 
	{
		return
		'
		#ifdef TEXTURE
		varying vec3 v_uv0;
		uniform sampler2D DiffuseTexture;
		#endif
		
		varying vec4 v_color;			
				
		void main(void) 
		{	
			gl_FragColor = v_color;
			#ifdef TEXTURE
			gl_FragColor *= texture2D(DiffuseTexture, v_uv0.xy);
			#endif			
		}
		';
	}
	
	/**
	 * Vertex Shader Uniforms.
	 */
	static private var vs_uniforms : String =
	'
	uniform mat4  WorldMatrix;
	uniform mat4  ViewMatrix;
	uniform mat4  ProjectionMatrix;
	
	#ifdef SKINNING	
	uniform int SkinQuality;	
	#endif
	#ifdef BONE_TEXTURE
	uniform sampler2D Joints;
	uniform sampler2D Binds;	
	uniform vec4      SkinTexSize;
	#else		
	uniform vec4  Joints[MAX_BONES*3];
	uniform vec4   Binds[MAX_BONES*3];
	#endif
	
	#ifdef TINT
	uniform vec4  Tint;
	#endif	
	';
	
	/**
	 * Vertex Shader Attribs
	 */
	static private var vs_attribs : String =
	'
	attribute vec3 vertex;
	
	#ifdef VERTEX_COLOR
	attribute vec4 color;
	#endif
	
	#ifdef SKINNING
	attribute vec4 bone;
	attribute vec4 weight;		
	#endif
	
	#ifdef TEXTURE
	attribute vec3 uv0;
	#endif
	
	#ifdef LIGHTMAP
	attribute vec3 uv1;
	#endif	
	';
	
	/**
	 * Fragment Shaders Uniforms
	 */
	static private var fs_uniforms : String =
	'		
	#ifdef LIGHTMAP	
	#endif	
	
	#ifdef TEXTURE	
	uniform sampler2D DiffuseTexture;
	#endif	
	';
	
	/**
	 * Global Usage Varyings
	 */
	static private var g_varyings : String =
	'
	varying vec4 v_color;
		
	#ifdef LIGHTMAP
	varying vec3 v_uv1;
	#endif	
	
	#ifdef TEXTURE	
	varying vec3 v_uv0;		
	#endif	
	';
	
}