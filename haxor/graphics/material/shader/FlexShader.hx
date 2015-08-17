package haxor.graphics.material.shader;
import haxor.component.light.Light;
import haxor.core.Enums.ShaderFeature;
import haxor.core.Enums.ShaderPrecision;

/**
 * Flexible shader that can be configured with different behaviours.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class FlexShader extends Shader
{
	/*
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
		if ((v & ShaderFeature.ReflectionVertex) != 0) { AddPreprocessor("#define", "REFLECTION_VERTEX"); AddPreprocessor("#define", "REFLECTION"); }
		if ((v & ShaderFeature.ReflectionPixel) != 0) { AddPreprocessor("#define", "REFLECTION_PIXEL"); AddPreprocessor("#define", "REFLECTION"); }		
		if ((v & ShaderFeature.ReflectionTexture) != 0)	AddPreprocessor("#define", "REFLECTION_TEXTURE");		
		if ((v & ShaderFeature.FalloffVertex) != 0)	{ AddPreprocessor("#define", "FALLOFF_VERTEX"); AddPreprocessor("#define", "FALLOFF"); }
		if ((v & ShaderFeature.FalloffPixel)!=0)	{ AddPreprocessor("#define", "FALLOFF_PIXEL");  AddPreprocessor("#define", "FALLOFF"); }
		if ((v & ShaderFeature.Bump)!=0)		    AddPreprocessor("#define", "BUMP");
		if ((v & ShaderFeature.LightingVertex)!=0) 	{ AddPreprocessor("#define", "LIGHTING_VERTEX"); AddPreprocessor("#define", "LIGHTING"); }
		if ((v & ShaderFeature.LightingPixel)!=0)  	{ AddPreprocessor("#define", "LIGHTING_PIXEL");  AddPreprocessor("#define", "LIGHTING"); }
		if ((v & ShaderFeature.Specular) != 0)  		AddPreprocessor("#define", "SPECULAR");
		if ((v & ShaderFeature.SpecularTexture) != 0)	AddPreprocessor("#define", "SPECULAR_TEXTURE");
		if ((v & ShaderFeature.SpecularAlpha) != 0)	AddPreprocessor("#define", "SPECULAR_ALPHA");
		if ((v & ShaderFeature.Lightmap)!=0)  		AddPreprocessor("#define", "LIGHTMAP");
		if ((v & ShaderFeature.FogVertex)!=0) 		{ AddPreprocessor("#define", "FOG_VERTEX"); AddPreprocessor("#define", "FOG"); }
		if ((v & ShaderFeature.FogPixel)!=0) 		{ AddPreprocessor("#define", "FOG_PIXEL"); AddPreprocessor("#define", "FOG"); }
		if ((v & ShaderFeature.Toon)!=0)	 		AddPreprocessor("#define", "TOON");
		if ((v & ShaderFeature.Cutoff)!=0)	 		AddPreprocessor("#define", "CUTOFF");		
		if ((v & ShaderFeature.Particle) != 0) 		AddPreprocessor("#define", "PARTICLE");
		if ((v & ShaderFeature.UVScroll) != 0) 		AddPreprocessor("#define", "UV_SCROLL");
		if ((v & ShaderFeature.Random) != 0) 		AddPreprocessor("#define", "RANDOM");		
		if ((v & ShaderFeature.AlphaTexture) != 0) 		AddPreprocessor("#define", "ALPHA_TEXTURE");		
		if ((v & ShaderFeature.Emissive) != 0)			AddPreprocessor("#define", "EMISSIVE");		
		if ((v & ShaderFeature.EmissiveTexture) != 0)	AddPreprocessor("#define", "EMISSIVE_TEXTURE");		
		if ((v & (ShaderFeature.LightingVertex | ShaderFeature.LightingPixel)) != 0) AddPreprocessor("#define", "MAX_LIGHTS", Light.max + "");
		return v; 
	}
	private var m_features : Int;
	
	
	//CTOR
	public function new(p_id:String,p_features : Int = ShaderFeature.Empty, p_precision : Int = ShaderPrecision.VertexLow | ShaderPrecision.FragmentLow, p_compile:Bool = true) 
	{	
		super(p_id, p_precision, false);		
		features = p_features;			
		if (p_compile) Compile();
	}
	
	//Vertex Shader Uniforms.
	static private var vs_uniforms : String =
	'
	uniform mat4  WorldMatrix;
	uniform mat4  WorldMatrixIT;
	uniform mat4  WorldMatrixInverse;
	uniform mat4  ViewMatrix;
	uniform mat4  ViewMatrixInverse;
	uniform mat4  ProjectionMatrix;
	uniform mat4  ProjectionMatrixInverse;
	
	
	#ifdef SKINNING	
	uniform int SkinQuality;	
	
	#ifdef BONE_TEXTURE
	uniform sampler2D Joints;
	uniform sampler2D Binds;	
	uniform vec4      SkinTexSize;
	#else		
	uniform vec4  Joints[MAX_BONES*3];
	uniform vec4   Binds[MAX_BONES*3];
	#endif
	
	#endif
	
	#ifdef UV_SCROLL
	uniform vec3 UVOffset;
	uniform vec3 UVSpeed;	
	#endif
	
	#ifdef UV_SCROLL
	uniform float Time;
	#endif	
	
	#ifdef FOG
	#define CameraNear CameraProjection.x
	#define CameraFar  CameraProjection.y
	uniform vec3 CameraProjection;	
	#endif	
	';
	
	//Vertex Shader Attribs
	static private var vs_attribs : String =
	'
	attribute vec3 vertex;
	
	#ifdef VERTEX_COLOR
	attribute vec4 color;
	#endif
	
	#ifdef USE_NORMAL
	attribute vec3 normal;
	#endif
	
	#ifdef SKINNING
	attribute vec4 bone;
	attribute vec4 weight;		
	#endif
	
	#ifdef TEXTURE
	attribute vec3 uv0;
	#endif
	
	#ifdef USE_UV1
	attribute vec3 uv1;
	#endif	
	';
	
	//Vertex Shader related functions
	static private var vs_functions : String =
	'
	#ifdef SKINNING	
	mat4 GetJointMatrix(const int b0, const int b1, const int b2) 
	{ 
		#ifdef BONE_TEXTURE		
		
		//float itw = SkinTexSize.z;
		//float ith = SkinTexSize.w;
		//float fb0x = mod(float(b0), SkinTexSize.x);
		//float fb1x = mod(float(b1), SkinTexSize.x);
		//float fb2x = mod(float(b2), SkinTexSize.x);
		//float fb0y = floor(float(b0) * itw);
		//float fb1y = floor(float(b1) * itw);
		//float fb2y = floor(float(b2) * itw);			
		//vec4 l0 = texture2D(Joints, vec2(fb0x*itw,fb0y*ith));
		//vec4 l1 = texture2D(Joints, vec2(fb1x*itw,fb1y*ith));
		//vec4 l2 = texture2D(Joints, vec2(fb2x*itw,fb2y*ith));
		
		vec2 fb0 = vec2(mod(float(b0), SkinTexSize.x)*SkinTexSize.z, floor(float(b0) * SkinTexSize.z)*SkinTexSize.w);
		vec2 fb1 = vec2(mod(float(b1), SkinTexSize.x)*SkinTexSize.z, floor(float(b1) * SkinTexSize.z)*SkinTexSize.w);
		vec2 fb2 = vec2(mod(float(b2), SkinTexSize.x)*SkinTexSize.z, floor(float(b2) * SkinTexSize.z)*SkinTexSize.w);
		vec4 l0 = texture2D(Joints, fb0);
		vec4 l1 = texture2D(Joints, fb1);
		vec4 l2 = texture2D(Joints, fb2);
		return mat4(l0,l1,l2,vec4(0,0,0,1));
		#else
		return mat4(Joints[b0], Joints[b1], Joints[b2], vec4(0, 0, 0, 1)); 
		#endif
	}
	
	mat4 GetBindMatrix (const int b0, const int b1, const int b2) 
	{ 
		#ifdef BONE_TEXTURE			
		//float itw = SkinTexSize.z;
		//float ith = SkinTexSize.w;
		vec2 fb0 = vec2(mod(float(b0), SkinTexSize.x)*SkinTexSize.z, floor(float(b0) * SkinTexSize.z)*SkinTexSize.w);
		vec2 fb1 = vec2(mod(float(b1), SkinTexSize.x)*SkinTexSize.z, floor(float(b1) * SkinTexSize.z)*SkinTexSize.w);
		vec2 fb2 = vec2(mod(float(b2), SkinTexSize.x)*SkinTexSize.z, floor(float(b2) * SkinTexSize.z)*SkinTexSize.w);
		vec4 l0 = texture2D(Binds, fb0);
		vec4 l1 = texture2D(Binds, fb1);
		vec4 l2 = texture2D(Binds, fb2);
		
		//float fb0x = mod(float(b0), SkinTexSize.x);
		//float fb1x = mod(float(b1), SkinTexSize.x);
		//float fb2x = mod(float(b2), SkinTexSize.x);
		//float fb0y = floor(float(b0) * itw);
		//float fb1y = floor(float(b1) * itw);
		//float fb2y = floor(float(b2) * itw);			
		//vec4 l0 = texture2D(Binds, vec2(fb0x*itw,fb0y*ith));
		//vec4 l1 = texture2D(Binds, vec2(fb1x*itw,fb1y*ith));
		//vec4 l2 = texture2D(Binds, vec2(fb2x*itw,fb2y*ith));
		
		return mat4(l0,l1,l2,vec4(0,0,0,1));
		#else
		return mat4(Binds[b0] , Binds[b1] , Binds[b2] , vec4(0, 0, 0, 1)); 
		#endif
	}
	
	mat4 SkinWorldMatrix()
	{
		vec4 b = bone * 3.0;			
		vec4 w = weight;			
		float ivs = 0.0;
		if (SkinQuality >= 0) ivs += weight.x;
		if (SkinQuality >= 2) ivs += weight.y;
		if (SkinQuality >= 3) ivs += weight.z;
		if (SkinQuality >= 4) ivs += weight.w;			
		w *= 1.0 / ivs;			
		ivec4 bi0 = ivec4(b.x, b.y, b.z, b.w);			
		ivec4 bi1 = ivec4(b.x + 1.0, b.y + 1.0, b.z + 1.0, b.w + 1.0);			
		ivec4 bi2 = ivec4(b.x + 2.0, b.y + 2.0, b.z + 2.0, b.w + 2.0);			
		mat4 res = mat4(0.0),jm,bm;			
		if (SkinQuality >= 0) { jm = GetJointMatrix(bi0.x, bi1.x, bi2.x); bm = GetBindMatrix(bi0.x, bi1.x, bi2.x); res += ((bm * jm) * w.x); }
		if (SkinQuality >= 2) { jm = GetJointMatrix(bi0.y, bi1.y, bi2.y); bm = GetBindMatrix(bi0.y, bi1.y, bi2.y); res += ((bm * jm) * w.y); }
		if (SkinQuality >= 3) { jm = GetJointMatrix(bi0.z, bi1.z, bi2.z); bm = GetBindMatrix(bi0.z, bi1.z, bi2.z); res += ((bm * jm) * w.z); }
		if (SkinQuality >= 4) { jm = GetJointMatrix(bi0.w, bi1.w, bi2.w); bm = GetBindMatrix(bi0.w, bi1.w, bi2.w); res += ((bm * jm) * w.w); }		
		return res;
	}	
	#endif
	';
	
	//Generates the Vertex Shader using all features.
	override function GetVS():String 
	{
		return
		'
		$g_preprocessors
		
		$g_uniforms
		
		$vs_uniforms
		
		$vs_attribs
		
		$g_varyings
		
		$g_functions
		
		$vs_functions
		
		vec4 LPos;
		vec4 WPos;
		vec4 VPos;
		vec4 HPos;
		
		vec3 WorldViewDir;
		vec3 Normal;
		
		vec3 FalloffComponent;
		vec3 DiffuseComponent;
		vec3 SpecularComponent;
		
		void main(void) 
		{		
			mat4 wm;
			
			LPos = vec4(vertex, 1.0);
			
			#ifdef SKINNING
			wm = SkinWorldMatrix();
			#else
			wm = WorldMatrix;
			#endif
			
			WPos = LPos * wm;
			VPos = WPos * ViewMatrix;
			HPos = VPos * ProjectionMatrix;
			
			#ifdef LIGHTING
			v_wpos = WPos.xyz;
			#endif
			
			WorldViewDir = vec3(0.0);
			
			#ifdef USE_VIEW_DIR
			WorldViewDir = v_wview = -normalize(WPos.xyz - CameraPosition);
			#endif
			
			Normal = vec3(0.0);
			
			#ifdef USE_NORMAL
			Normal = v_normal = normal;
			#ifdef SKINNING
			Normal = v_normal = v_normal * mat3(wm);
			#else
			Normal = v_normal = v_normal * mat3(wm);
			#endif
			#endif
			
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
			
			#ifdef UV_SCROLL
			v_uv0 = (v_uv0 + (UVSpeed * Time)) + UVOffset;
			#endif
			
			#ifdef USE_UV1
			v_uv1 = uv1;
			#endif
			
			#ifdef LIGHTING_VERTEX			
			ProcessLights(Normal, WorldViewDir, Shininess, DiffuseComponent, SpecularComponent);						
			v_diffuse_component = DiffuseComponent;			
			#ifdef SPECULAR
			v_specular_component = SpecularComponent;
			#endif
			#endif
			
			#ifdef FALLOFF_VERTEX
			FalloffComponent = v_falloff_component = Falloff(WorldViewDir, Normal, FalloffExp) * FalloffIntensity * FalloffColor.xyz;						
			#endif
			
			#ifdef REFLECTION_VERTEX
			v_wreflection = reflect(-WorldViewDir, Normal);
			#endif
			
			#ifdef FOG
			v_linear_depth = LinearNF(HPos.z/HPos.w,CameraNear,CameraFar);
			#endif
			
			#ifdef FOG_VERTEX
			v_fog_component = FogFactor(v_linear_depth, FogExp, FogDensity, FogStart, FogEnd);
			#endif
			
			gl_Position = HPos;
		}		
		';
	}
	
	//Fragment Shaders Uniforms
	static private var fs_uniforms : String =
	'
	#ifdef TEXTURE	
	uniform sampler2D DiffuseTexture;
	#endif	
	
	#ifdef SPECULAR_TEXTURE
	uniform sampler2D SpecularTexture;
	#endif
	
	#ifdef ALPHA_TEXTURE
	uniform sampler2D AlphaTexture;
	#endif
	
	#ifdef BUMP
	uniform sampler2D NormalTexture;
	#endif
	
	#ifdef LIGHTMAP
	uniform sampler2D Lightmap;
	uniform float LightmapFactor;
	#endif
	
	#ifdef CUTOFF
	uniform float Cutoff;
	#endif	
	
	';
	
	
	//Generates the Fragment Shader using all features.
	override function GetFS():String 
	{
		return
		'
		$g_preprocessors
		
		$g_uniforms
		
		$fs_uniforms
		
		$g_varyings
		
		$g_functions
		
		vec3 FalloffComponent;
		
		vec3 Normal;		
		vec4 Fragment;
		
		vec3 DiffuseComponent;
		vec3 SpecularComponent;
		
		vec3 WorldViewDir;
		
		void main(void) 
		{	
			
			#ifdef USE_VIEW_DIR
			WorldViewDir = v_wview;
			#else
			WorldViewDir = vec3(0, 0, 0);
			#endif
			
			Fragment = v_color;
			
			#ifdef USE_NORMAL
			Normal = v_normal;
			#endif
			
			#ifdef BUMP
			vec3 tex_bump = (texture2D(NormalTexture, v_uv1).xyz * 2.0) - 1.0;
			Normal = tex_bump;
			#endif
			
			#ifdef USE_NORMAL
			Normal = normalize(Normal);
			#endif
			
			vec4 tex_diffuse = vec4(0, 0, 0, 1);
			
			#ifdef TEXTURE			
			tex_diffuse *= texture2D(DiffuseTexture, v_uv0.xy);
			#endif
						
			#ifdef ALPHA_TEXTURE			
			tex_diffuse.a *= texture2D(AlphaTexture, v_uv0.xy).r;
			#endif
			
			#ifdef USE_DIFFUSE_TEXTURE
			Fragment *= tex_diffuse;
			#endif
			
			#ifdef CUTOFF
			if (Fragment.w <= Cutoff) discard;
			#endif
			
			vec3 reflect_dir = vec3(0.0);
			
			#ifdef REFLECTION_VERTEX
			reflect_dir = v_wreflection;
			#endif
			
			#ifdef REFLECTION_PIXEL
			reflect_dir = reflect(-v_wview,Normal);
			#endif
			
			#ifdef REFLECTION
			vec3 tex_reflection = textureCube(ReflectionTexture, reflect_dir).xyz;
			Fragment.xyz += tex_reflection.xyz * ReflectionIntensity * ReflectionColor.xyz;
			#endif
			
			#ifdef LIGHTMAP
			vec4 tex_lightmap  = texture2D(Lightmap, v_uv1.xy);
			Fragment.xyz	  += Fragment.xyz * (tex_lightmap.w * LightmapFactor) * tex_lightmap.xyz;
			#endif
			
			#ifdef LIGHTING
			Fragment.xyz += Fragment.xyz * Ambient.xyz;			
			#endif
			
			#ifdef LIGHTING_VERTEX
			DiffuseComponent  = v_diffuse_component;			
			#ifdef SPECULAR
			SpecularComponent = v_specular_component;
			#endif
			#endif
			
			#ifdef LIGHTING_PIXEL			
			ProcessLights(Normal,WorldViewDir,Shininess,DiffuseComponent,SpecularComponent);			
			#endif
			
			#ifdef LIGHTING
			Fragment.xyz += Fragment.xyz * DiffuseComponent;
			#endif
			
			#ifdef SPECULAR			
			
			#ifdef SPECULAR_ALPHA
			SpecularComponent *= tex_diffuse.a;
			#endif
			
			#ifdef SPECULAR_TEXTURE
			
			vec4 tex_specular = texture2D(SpecularTexture, v_uv0.xy);
			SpecularComponent *= tex_specular.xyz;
			#endif
			
			Fragment.xyz += SpecularComponent;
			#endif
			
			#ifdef FALLOFF_VERTEX
			FalloffComponent = v_falloff_component;
			#endif
			
			#ifdef FALLOFF_PIXEL
			FalloffComponent = Falloff(WorldViewDir, Normal, FalloffExp) * FalloffIntensity * FalloffColor.xyz;			
			#endif
			
			#ifdef FALLOFF			
			Fragment.xyz += FalloffComponent;
			#endif
			
			#ifdef EMISSIVE
			Fragment.xyz += EmissiveColor.xyz;
			#endif
			
			float FogComponent = 0.0;
			
			#ifdef FOG_VERTEX
			FogComponent = v_fog_component;
			#endif
			
			#ifdef FOG_PIXEL
			FogComponent = FogFactor(v_linear_depth, FogExp, FogDensity, FogStart, FogEnd);
			#endif
			
			#ifdef FOG
			Fragment = mix(Fragment, FogColor,FogComponent);
			#endif
			
			gl_FragColor = Fragment;
		}
		';
	}
	
	//Global Usage Varyings
	static private var g_varyings : String =
	'
	varying vec4 v_color;
	
	#ifdef USE_NORMAL
	varying vec3 v_normal;
	#endif
	
	#ifdef LIGHTING
	varying vec3 v_wpos;
	#endif
	
	#ifdef LIGHTING_VERTEX
	varying vec3 v_diffuse_component;	
	#ifdef SPECULAR
	varying vec3 v_specular_component;
	#endif		
	#endif
	
	#ifdef USE_VIEW_DIR
	varying vec3 v_wview;
	#endif
	
	#ifdef REFLECTION_VERTEX
	varying vec3 v_wreflection;
	#endif
	
	#ifdef FALLOFF
	varying vec3 v_falloff_component;
	#endif
	
	#ifdef TEXTURE	
	varying vec3 v_uv0;		
	#endif	
	
	#ifdef USE_UV1
	varying vec3 v_uv1;	
	#endif
	
	#ifdef FOG
	varying float v_linear_depth;
	#endif
	
	#ifdef FOG_VERTEX
	varying float v_fog_component;
	#endif
	
	';
	
	//Global Uniforms.
	static private var g_uniforms : String =
	'
	
	uniform vec3 CameraPosition;
	
	#ifdef RANDOM	
	uniform float RandomSeed;		
	uniform sampler2D RandomTexture;
	#endif	
	
	#ifdef TINT
	uniform vec4  Tint;
	#endif	
	
	#ifdef FOG
	#define FogColor    Fog[0]
	#define FogDensity  Fog[1].x
	#define FogExp      Fog[1].y
	#define FogStart    Fog[1].z
	#define FogEnd      Fog[1].w
	uniform vec4 Fog[2];
	#endif	
	
	#ifdef LIGHTING	
	uniform vec4  Ambient;
	uniform vec4 Lights[MAX_LIGHTS * 3];	
	uniform float Shininess;
	#endif
	
	#ifdef FALLOFF
	uniform float FalloffExp;			
	uniform float FalloffIntensity;
	uniform vec4  FalloffColor;
	#endif
	
	#ifdef USE_RAMP_TEXTURE
	uniform sampler2D RampTexture;
	#endif
	
	#ifdef REFLECTION
	uniform float ReflectionIntensity;
	uniform vec4  ReflectionColor;
	uniform samplerCube  ReflectionTexture;
	#endif
	
	#ifdef EMISSIVE	
	uniform vec4  EmissiveColor;
	#endif
	
	';
	
	
	//Global Usage Functions	
	static private var g_functions : String =
	'
	#ifdef RANDOM	
	float NextSeed = 0.0;
	vec4 Random()
	{
		float itw  = 0.00390625;
		float p    = NextSeed + (RandomSeed * 65536.0);
		float idx  = mod(p,256.0)   * itw;
		float idy  = floor(p * itw) * itw;
		NextSeed  += 1.0;
		return texture2D(RandomTexture, vec2(idx,idy));
	}
	#endif
	
	#ifdef FOG
	float FogFactor(float p_linear_depth,float p_exp,float p_density,float p_start,float p_end) { return pow(clamp((p_linear_depth - p_start) / (p_end - p_start),0.0,1.0),p_exp) * p_density; }
	#endif
	
	vec4 texture2DOffset(sampler2D p_texture, float p_offset, float p_iw, float p_ih) { return texture2D(p_texture, vec2(mod(p_offset,1.0/p_iw)*p_iw,floor(p_offset * p_iw)*p_iw)); }
	
	float LinearNF(float p_hz, float p_near, float p_far) { return p_near * (p_hz + 1.0) / (p_far + p_near - p_hz * (p_far - p_near)); }	
	float LinearEye(float p_hz, float p_near, float p_far) { return (2.0 * p_near) / (p_far + p_near - p_hz * (p_far - p_near)); }	
	float Depth2Eye(float p_hz, float p_near, float p_far) { return (2.0 * p_near * p_far) / (p_far + p_near - p_hz * (p_far - p_near)); }
	
	#ifdef LIGHTING
	
	vec4 LightAttrib(const int p_id)   
	{ 
		if(p_id==0) return Lights[0];
		if(p_id==1) return Lights[3];
		if(p_id==2) return Lights[6];
		if(p_id==3) return Lights[9];
		if(p_id==4) return Lights[12];
		if(p_id==5) return Lights[15];
		if(p_id==6) return Lights[18];
		if(p_id==7) return Lights[21];
		return vec4(-1,0,0,0);		
	}
	
	vec3 LightPosition(int p_id)   
	{ 
		if(p_id==0) return Lights[1].xyz;
		if(p_id==1) return Lights[4].xyz;
		if(p_id==2) return Lights[7].xyz;
		if(p_id==3) return Lights[10].xyz;
		if(p_id==4) return Lights[13].xyz;
		if(p_id==5) return Lights[16].xyz;
		if(p_id==6) return Lights[19].xyz;
		if(p_id==7) return Lights[22].xyz;
		return vec3(0,0,0);
	}
	
	vec4 LightColor(int p_id)   
	{ 
		if(p_id==0) return Lights[2];
		if(p_id==1) return Lights[5];
		if(p_id==2) return Lights[8];
		if(p_id==3) return Lights[11];
		if(p_id==4) return Lights[14];
		if(p_id==5) return Lights[17];
		if(p_id==6) return Lights[20];
		if(p_id==7) return Lights[23];
		return vec4(0,0,0,1);
	}
	
	float DiffuseFactor(vec3 p_normal, vec3 p_light_dir) { return clamp(dot(p_normal,p_light_dir),0.0,1.0); }	
	float SpecularFactor(float p_shininess, vec3 p_normal, vec3 p_light_dir, vec3 p_view_dir) 
	{ 
		vec3 hv  = normalize(p_light_dir + p_view_dir);
		float dv = clamp(dot(hv, p_normal), 0.0, 1.0);
		return pow(dv, p_shininess);
	}
	
	vec3 LightingLambert(float p_intensity,vec3 p_light_color,vec3 p_light_dir,vec3 p_normal)
	{				
		float df = DiffuseFactor(p_normal, p_light_dir);
		return p_light_color * df * p_intensity;
	}
	
	vec3 LightingPhong(float p_intensity,vec3 p_light_color,vec3 p_light_dir,vec3 p_normal,vec3 p_view_dir,float p_shininess)
	{
		float sf = SpecularFactor(p_shininess, p_normal, p_light_dir, p_view_dir);		
		return p_light_color * sf * p_intensity;
	}
	
	#ifdef TOON
	vec3 LightingLambertToon(float p_intensity, vec3 p_light_color, vec3 p_light_dir, vec3 p_normal)
	{
		float df = DiffuseFactor(p_normal, p_light_dir);		
		return p_light_color * texture2D(RampTexture,vec2(df,0)).xyz * p_intensity;
	}
	
	vec3 LightingPhongToon(float p_intensity,vec3 p_light_color,vec3 p_light_dir,vec3 p_normal,vec3 p_view_dir,float p_shininess)
	{
		float sf = SpecularFactor(p_shininess, p_normal, p_light_dir, p_view_dir);
		return p_light_color * texture2D(RampTexture,vec2(sf,0)).xyz * p_intensity;
	}
	#endif
	
	void ProcessLights(vec3 p_normal, vec3 p_view_dir,float p_shininess, out vec3 p_diffuse_component, out vec3 p_specular_component)
	{
		p_diffuse_component  = vec3(0.0);
		p_specular_component = vec3(0.0);
		
		for(int i=0;i<MAX_LIGHTS;i++)
		{
			vec4  l_attrib 	  = LightAttrib(i);
			vec3  l_position  = LightPosition(i);
			vec3  l_color 	  = LightColor(i).xyz;
			int   l_type   	  = int(l_attrib.x);
			float l_intensity = l_attrib.y;
			float l_atten 	  = l_attrib.w;
			
			vec3  l_dir		  = vec3(0.0);
			
			//Invalid Light can stop here
			if (l_type == -1) break;
			
			//Point Light
			if(l_type == 0)
			{
				float l_radius  = l_attrib.z * 0.5;	
				l_dir = -(v_wpos - l_position);
				l_intensity   = (1.0 - clamp(length(l_dir) / l_radius, 0.0, 1.0)) * l_intensity;					
				l_dir = normalize(l_dir);
			}
			
			//Directional Light
			if(l_type == 1)
			{
				l_dir = l_position;
			}
			
			vec3 d_component = vec3(0);
			
			#ifdef TOON
			d_component = LightingLambertToon(l_intensity, l_color, l_dir, p_normal);
			#else
			d_component = LightingLambert(l_intensity, l_color, l_dir, p_normal);
			#endif
			
			p_diffuse_component += d_component;
			
			#ifdef SPECULAR
			vec3 s_component = vec3(0);
			
			#ifdef TOON
			s_component = LightingPhongToon(l_intensity,l_color,l_dir,p_normal,p_view_dir,p_shininess);
			#else
			s_component = LightingPhong(l_intensity,l_color,l_dir,p_normal,p_view_dir,p_shininess);
			#endif
			
			p_specular_component += s_component;
			#endif					
			
		}
		
	}
	
	#endif
	
	#ifdef FALLOFF
	float Falloff(vec3 p_view_dir, vec3 p_normal, float p_exp) { return pow(1.0 - clamp(dot(p_view_dir, p_normal), 0.0, 1.0), p_exp); }
	#endif
	
	';
	
	static private var g_preprocessors : String =
	'	
	#if defined(LIGHTING) || defined(FALLOFF) || defined(REFLECTION) || defined(BUMP) || defined(REFLECTION)
	#define USE_NORMAL
	#endif
	
	#if defined(FALLOFF) || defined(SPECULAR)  || defined(REFLECTION)
	#define USE_VIEW_DIR
	#endif
	
	#if defined(LIGHTMAP) || defined(BUMP)
	#define USE_UV1
	#endif
	
	#if defined(TEXTURE) || defined(ALPHA_TEXTURE)
	#define USE_DIFFUSE_TEXTURE
	#endif
	
	#if defined(TOON)
	#define USE_RAMP_TEXTURE
	#endif
	
	
	
	';
	//*/
}