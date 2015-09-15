package haxor.context;

/**
 * Class that handles shader templates.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class ShaderContext
{
	/**
	 * Flat VertexShader with Vertex Color
	 */
	static private var vs_flat : String = 
'
uniform mat4  WorldMatrix;
uniform mat4  ViewMatrix;
uniform mat4  ProjectionMatrix;		
uniform vec4  Tint;				
attribute vec3 vertex;
attribute vec4 color;		
varying vec4 v_color;			
void main(void) 
{		
	gl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;				
	v_color = color * Tint;
}			
';
	
	/**
	 * Flat FragmentShader with Vertex Color
	 */
	static private var fs_flat : String = 
'				
varying vec4 v_color;			
void main(void) { gl_FragColor = v_color; }					
';

/**
 * Flat VertexShader with a Diffuse texture.
 */
static private var vs_flat_texture : String =
'
uniform mat4  WorldMatrix;
uniform mat4  ViewMatrix;
uniform mat4  ProjectionMatrix;		
uniform vec4  Tint;

attribute vec3 vertex;					
attribute vec4 color;
attribute vec3 uv0;		

varying vec2 v_uv0;
varying vec4 v_color;	
	
void main(void) 
{		
	gl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;
	v_uv0   = uv0.xy;
	v_color = color*Tint;
}			
';
	
	/**
	 * Flat with a Diffuse texture.
	 */
	static private var fs_flat_texture : String =
'	
varying vec2 v_uv0;
varying vec4 v_color;			
uniform sampler2D DiffuseTexture;
void main(void) 
{	
	vec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy);	
	gl_FragColor.xyz = (tex_diffuse.xyz * v_color.xyz);
	gl_FragColor.a 	 = tex_diffuse.a * v_color.a;
}
';
	
	/**
	 * Flat Skinned VertexShader with DiffuseTexture.
	 */
	static private var vs_flat_skin_texture: String = 
'	
uniform mat4  WorldMatrix;
uniform mat4  WorldMatrixIT;
uniform mat4  ViewMatrix;
uniform mat4  ProjectionMatrix;
uniform vec3  WSCameraPosition;
uniform vec4  Tint;

#ifdef BONE_TEXTURE
uniform sampler2D Joints;
uniform sampler2D Binds;
uniform int		  SkinId;
uniform vec4      SkinTexSize;
#else		
uniform vec4  Joints[MAX_BONES*3];		
uniform vec4   Binds[MAX_BONES*3];
#endif

uniform int SkinQuality;

attribute vec3 vertex;					
attribute vec4 color;
attribute vec3 normal;
attribute vec3 uv0;
attribute vec4 bone;
attribute vec4 weight;

varying vec3 v_uv0;
varying vec3 v_normal;
varying vec4 v_color;
varying vec4 v_wsVertex;
varying vec3 v_wsView;	
	
	
	
mat4 GetJointMatrix(const int b0, const int b1, const int b2) 
{ 
	#ifdef BONE_TEXTURE			
	float itw = SkinTexSize.z;
	float ith = SkinTexSize.w;
	float fb0x = mod(float(b0), SkinTexSize.x);
	float fb1x = mod(float(b1), SkinTexSize.x);
	float fb2x = mod(float(b2), SkinTexSize.x);
	float fb0y = floor(float(b0) * itw);
	float fb1y = floor(float(b1) * itw);
	float fb2y = floor(float(b2) * itw);			
	vec4 l0 = texture2D(Joints, vec2(fb0x*itw,fb0y*ith));
	vec4 l1 = texture2D(Joints, vec2(fb1x*itw,fb1y*ith));
	vec4 l2 = texture2D(Joints, vec2(fb2x*itw,fb2y*ith));
	return mat4(l0,l1,l2,vec4(0,0,0,1));
	#else
	return mat4(Joints[b0], Joints[b1], Joints[b2], vec4(0, 0, 0, 1)); 
	#endif
}
	
mat4 GetBindMatrix (const int b0, const int b1, const int b2) 
{ 
	#ifdef BONE_TEXTURE			
	float itw = SkinTexSize.z;
	float ith = SkinTexSize.w;					
	float fb0x = mod(float(b0), SkinTexSize.x);
	float fb1x = mod(float(b1), SkinTexSize.x);
	float fb2x = mod(float(b2), SkinTexSize.x);
	float fb0y = floor(float(b0) * itw);
	float fb1y = floor(float(b1) * itw);
	float fb2y = floor(float(b2) * itw);			
	vec4 l0 = texture2D(Binds, vec2(fb0x*itw,fb0y*ith));
	vec4 l1 = texture2D(Binds, vec2(fb1x*itw,fb1y*ith));
	vec4 l2 = texture2D(Binds, vec2(fb2x*itw,fb2y*ith));
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
					
void main(void) 
{	
	vec4 lv = vec4(vertex,1.0);
	vec3 ln = vec3(normal);
	mat4 swm = SkinWorldMatrix();
	mat4 wm;					
	wm = swm;
	//wm = WorldMatrix;
	
	v_uv0   = uv0;
	v_color = color * Tint;			
	v_normal = ln * mat3(WorldMatrixIT);			
	gl_Position = ((lv * wm) * ViewMatrix) * ProjectionMatrix;
}			
';
	
	/**
	 * Flat Skinned VertexShader with DiffuseTexture.
	 */
	static private var fs_flat_skin_texture: String = 
'	
uniform sampler2D DiffuseTexture;						
varying vec3 v_uv0;
varying vec4 v_color;
varying vec3 v_normal;

void main(void) 
{	
	vec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy);
	gl_FragColor.xyz = tex_diffuse.xyz * v_color.xyz;
	gl_FragColor.a 	 = tex_diffuse.a * v_color.a;
}		
';
	
	
	/**
	 * Grid Gizmo VertexShader.
	 */
	static private var vs_gizmo_grid : String = 
'
uniform mat4  WorldMatrix;
uniform mat4  ViewMatrix;
uniform mat4  ProjectionMatrix;		
uniform vec4  Tint;		
uniform float Area;
attribute vec3 vertex;		
attribute vec4 color;		
varying vec4 v_color;		
void main(void) 
{		
	gl_Position = ((vec4(vertex*Area, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;				
	v_color = color * Tint;		
}
';
	
	/**
	 * Screen Texture shader.
	 */
	static private var vs_gizmo_screen_texture : String = 
'	
uniform vec2  Screen;
uniform vec4  Rect;
uniform vec4  Tint;		
attribute vec3 vertex;				
varying vec4 v_color;
varying vec2 v_uv0;

void main(void) 
{		
	vec4 p = vec4(vertex, 1);
	float sw = Screen.x * 0.5;
	float sh = Screen.y * 0.5;
	p.x *= Rect.z / sw;
	p.y *= Rect.w / sh;
	p.x += Rect.x / sw;
	p.y -= Rect.y / sh;			
	p.x -= 1.0;
	p.y += 1.0;			
	p.z = 0.001;
	gl_Position = p;
	v_color = Tint;		
	v_uv0   = vec2(vertex.x,1.0+vertex.y);
}
';
	
	
	/**
	 * Gizmos shader.
	 */
	static private var vs_gizmo : String = 
'	
#define GIZMO_POINT       0
#define GIZMO_LINE        1
#define GIZMO_AXIS        2
#define GIZMO_WIRE_CUBE   3
#define GIZMO_WIRE_SPHERE 4
#define GIZMO_CANVAS	  10
	
	
	
mat4         		 WorldMatrix;
uniform mat4  		 ViewMatrix;
uniform mat4  		 ProjectionMatrix;				
uniform int   		 Count;
uniform int   		 Type;		
uniform sampler2D 	 Data;
uniform int  		 DataSize;		
vec4		 		 DataColor;
vec4		 		 DataA;
vec4		 		 DataB;
	
attribute float id;
attribute vec3 vertex;		
attribute vec4 color;

varying vec4 v_color;

vec4 GetPixel(float p_pix,float p_ds,float p_ids)
{			
	float px = mod(p_pix, p_ds) * p_ids;
	float py = (p_pix * p_ids) * p_ids;
	return texture2D(Data, vec2(px,py));
}
	
void main(void) 
{				
	if (id >= float(Count)) 
	{
		gl_Position = vec4( -2.0, 0.0, 0.0, 0.0);
		return; 
	}			
	float p  	= id * 6.0;
	float ds	= float(DataSize);
	float ids	= 1.0 / ds;			
	DataColor 	= GetPixel(p,ds,ids);
	DataA 		= GetPixel(p + 1.0,ds,ids);
	DataB 		= GetPixel(p + 2.0,ds,ids);			
	vec4 l0 	= GetPixel(p + 3.0,ds,ids);
	vec4 l1 	= GetPixel(p + 4.0,ds,ids);
	vec4 l2 	= GetPixel(p + 5.0,ds,ids);	
	vec4 v		= vec4(vertex, 1.0);
	WorldMatrix = mat4(l0.x, l0.y, l0.z, l0.w, l1.x, l1.y, l1.z, l1.w, l2.x, l2.y, l2.z, l2.w, 0, 0, 0, 1);
	
	if (Type == GIZMO_POINT)
	{	
		vec4 ncp = ((vec4(DataB.xyz, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;				
		v.xyz += DataB.xyz;
		float pf = (ncp.z / ncp.w);
		gl_PointSize = pf <= 0.0 ? DataA.x : (DataA.x * pf);
		gl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;
	}
	else
	if (Type == GIZMO_LINE)
	{
		float r = v.x;
		v.xyz = DataA.xyz + (DataB.xyz - DataA.xyz) * r;
		gl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;
	}
	else
	if (Type == GIZMO_AXIS)
	{		
		float sx   = length(vec3(WorldMatrix[0][0],WorldMatrix[1][0],WorldMatrix[2][0]));
		float sy   = length(vec3(WorldMatrix[0][1],WorldMatrix[1][1],WorldMatrix[2][1]));
		float sz   = length(vec3(WorldMatrix[0][2],WorldMatrix[1][2],WorldMatrix[2][2]));				
		vec3 scale = vec3(sx, sy, sz);				
		vec4 ncp = ((vec4(DataB.xyz, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;				
		v.xyz *= (DataA.xyz / scale.xyz) * ncp.w * 0.025;
		v.xyz += DataB.xyz;
		gl_Position  = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;				
	}
	else
	if (Type == GIZMO_WIRE_CUBE)
	{
		v.xyz *= DataA.xyz;
		v.xyz += DataB.xyz;
		gl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;
	}
	else
	if (Type == GIZMO_WIRE_SPHERE)
	{
		v.xyz *= DataA.x;
		v.xyz += DataB.xyz;
		gl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;
	}
	else
	if (Type == GIZMO_CANVAS)
	{				
		v.xyz += DataB.xyz;
		gl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;
	}
	
	v_color = DataColor * color;
}				
';
	
	
	/**
	 * Particle system rendering shader.
	 */
	static private var vs_flat_particle : String = 
'
#define IsLocal				 (System[1].z > 0.0)
#define SheetFrameWidth	 	 System[21].x
#define SheetFrameHeight 	 System[21].y
#define SheetLength		 	 System[22].x
#define SystemEmissionStart	 System[24].x
#define SystemEmissionCount	 System[24].y

#define PARTICLE_LENGTH		 8.0

#define PARTICLE_STATUS		 0.0
#define PARTICLE_POSITION	 1.0
#define PARTICLE_ROTATION	 2.0
#define PARTICLE_SIZE		 3.0
#define PARTICLE_VELOCITY	 4.0
#define PARTICLE_COLOR		 5.0
#define PARTICLE_START		 6.0
#define PARTICLE_NULL		 7.0

#define PARTICLE_DISABLED	 0
#define PARTICLE_INIT		 1
#define PARTICLE_ENABLED	 2
#define PARTICLE_DEAD		 3

attribute vec3 vertex;
		

uniform mat4  WorldMatrix;
uniform mat4  ViewMatrix;
uniform mat4  ViewMatrixInverse;
uniform mat4  ProjectionMatrix;		

uniform float Time;

uniform sampler2D Data;

uniform float DataWidth;
uniform float DataHeight;


uniform float TextureWidth;
uniform float TextureHeight;

uniform vec4  System[25];
		

varying vec2 v_uv0;
varying vec4 v_color;


uniform float RandomSeed;		
uniform sampler2D RandomTexture;

vec4 Random()
{
	float tw   = 0.001953125;
	float seed = RandomSeed * 262144.0;
	float idx  = mod(seed,512.0) * tw;
	float idy  = floor(seed * tw)  * tw;
	seed      += tw;
	return texture2D(RandomTexture, vec2(idx,idy));
}
//*/
vec4 ParticleData(float p_id,float p_field)
{
	float w   = floor(DataWidth);
	float h   = floor(DataHeight);
	float pid = mod(floor(SystemEmissionStart)+p_id,floor(w*h)/PARTICLE_LENGTH);
	float pix = floor(pid) * PARTICLE_LENGTH;			
	float px  = mod(pix+p_field,w) / (w-1.0);
	float py  = floor((pix+p_field)/w) / (h-1.0);
	return texture2D(Data,vec2(px,py));
}

vec4 ParticleStatus()   { return ParticleData(vertex.z,PARTICLE_STATUS); 	}
vec4 ParticlePosition() { return ParticleData(vertex.z,PARTICLE_POSITION); 	}
vec4 ParticleRotation() { return ParticleData(vertex.z,PARTICLE_ROTATION); 	}
vec4 ParticleSize() 	{ return ParticleData(vertex.z,PARTICLE_SIZE); 		}
vec4 ParticleColor() 	{ return ParticleData(vertex.z,PARTICLE_COLOR); 		}

void main(void) 
{		
	
	vec4  status   = ParticleStatus();
	
	float enabled  = int(status.x) == PARTICLE_DEAD ? 0.0 : 1.0;
	
	vec4  v   = vec4(vertex.xy,0.0,1.0);
	v.xyz	 *= enabled;
	
	if(enabled <= 0.0) { gl_Position = vec4(0,0,0,-1.0); return; }
	
	vec3 size	   = ParticleSize().xyz;			
	vec3 center    = vec3(0,0,0);
	vec3 position  = ParticlePosition().xyz;
				
	v.xyz  *= size;
	v.xyz   = v.xyz * mat3(ViewMatrixInverse); //billboard
	
	v.xyz  += center + position;
	
	mat4 wm     = IsLocal ? WorldMatrix : mat4(1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1); 
	
	gl_Position = ((v * wm) * ViewMatrix) * ProjectionMatrix;
	
	float frame   = floor(status.w);		
	
	v_uv0 = (vertex.xy+0.5);
	
	if(SheetLength > 0.0)
	{			
		float sw	  = (SheetFrameWidth);
		float sh	  = (SheetFrameHeight);			
		float tw	  = floor(TextureWidth);
		float th	  = floor(TextureHeight);
		float sheet_uvw = sw/tw;
		float sheet_uvh = sh/th;
		v_uv0   	*= vec2(sheet_uvw,sheet_uvh);					
		float cx     = floor(TextureWidth/SheetFrameWidth);
		v_uv0.x		 += (mod(frame,cx) * (sheet_uvw));
		v_uv0.y		 += 1.0 - (sheet_uvh) - (floor(frame/cx) * (sheet_uvh));
	}			
	
	v_color = ParticleColor();
}
';
	
	/**
	 * Particle system rendering shader.
	 */
	static private var fs_flat_particle : String = 
'
varying vec2 v_uv0;
varying vec4 v_color;	
uniform sampler2D Color;	
uniform sampler2D Texture;	
void main(void) 
{	
	vec4 tex		 = texture2D(Texture, v_uv0.xy);
	gl_FragColor.xyz = tex.xyz * v_color.xyz;
	gl_FragColor.a 	 = tex.a * v_color.a;
}	
';
	
	/**
	 * Shader responsible by the camera clear function with cubemaps.
	 */
	static private var vs_screen_skybox : String =
'
uniform mat4 ViewMatrixInverse;
uniform mat4 SkyboxProjectionMatrixInverse;
uniform vec3 CameraPosition;			
varying vec3 v_view_dir;
attribute vec3 vertex;			
void main()
{
	vec4 wpos = vec4(vertex,1.0) * SkyboxProjectionMatrixInverse;
	wpos /= wpos.w;
	wpos = wpos * ViewMatrixInverse;
	v_view_dir = wpos.xyz - CameraPosition;      		
	
	gl_Position = vec4(vertex,1.0);	
}
';
	
	/**
	 * Shader responsible by the camera clear function with cubemaps.
	 */
	static private var fs_screen_skybox : String =
'	
uniform samplerCube  SkyboxTexture;
varying vec3 v_view_dir;
void main() 
{ 
	gl_FragColor = textureCube(SkyboxTexture, normalize(v_view_dir));
}	
';

	/**
	 * Shader responsible by the camera clear function with cubemaps.
	 */
	static private var vs_pbs : String =
'
uniform mat4  WorldMatrix;
uniform mat4  ViewMatrix;
uniform mat4  ProjectionMatrix;		
uniform vec4  Tint;

attribute vec3 vertex;					
attribute vec4 color;
attribute vec3 normal;

#ifdef NORMAL_TEXTURE
attribute vec4 tangent;
#endif

attribute vec2 uv0;

uniform vec2 UVScale0;

varying vec2 v_uv0;
varying vec3 v_normal;
varying vec3 v_binormal;
varying vec3 v_tangent;
varying vec4 v_color;
varying vec4 v_wsVertex;	

#ifdef SECONDARY_MAP
attribute vec2 uv1;
uniform   vec2 UVScale1;
varying   vec2 v_uv1;
#endif

vec3 binormal(vec3 n,vec4 t) { return cross(n,t.xyz) * t.w; }

void main(void) 
{		
	v_wsVertex  = vec4(vertex, 1.0) * WorldMatrix;	
	gl_Position = (v_wsVertex * ViewMatrix) * ProjectionMatrix;	
	v_uv0    	= uv0 * UVScale0;
	
	#ifdef SECONDARY_MAP
	v_uv1    	= uv1 * UVScale1;
	#endif
	
	v_color  	= color * Tint;
	mat3 nm    	= mat3(WorldMatrix);
	v_normal   	= normal   * nm;	
	
	#ifdef NORMAL_TEXTURE
	v_tangent  	= tangent.xyz  * nm;
	v_binormal 	= binormal(v_normal,vec4(v_tangent,tangent.w));
	#endif
}	
';

static private var fs_pbs : String =
'
#ifdef GLOBAL_SKYBOX
#define SKYBOX_TEXTURE SkyboxMain
#else
#define SKYBOX_TEXTURE SkyboxTexture
#endif
		
uniform vec4 Lights[MAX_LIGHTS*3];
	
varying vec2 v_uv0;
varying vec3 v_normal;

varying vec4 v_color;
varying vec4 v_wsVertex;	

uniform vec4        Ambient;

uniform vec3        CameraPosition;

uniform sampler2D   DiffuseTexture;
uniform vec4        DiffuseColor;
uniform float       DiffuseGain;

#ifdef NORMAL_TEXTURE
uniform sampler2D   NormalTexture;
varying vec3 v_binormal;
varying vec3 v_tangent;
#endif

#ifdef SPECULAR_TEXTURE
uniform sampler2D   SpecularTexture;
uniform vec4        SpecularColor;
uniform float       SpecularExp;
#endif

uniform sampler2D   SmoothTexture;
uniform float       SmoothMax;
uniform float       SmoothRatio;

#ifdef OCCLUSION_TEXTURE
uniform sampler2D   OcclusionTexture;
uniform float       OcclusionFactor;
#endif

#ifdef EMISSION_TEXTURE
uniform sampler2D   EmissionTexture;
uniform vec4        EmissionColor;
#endif

uniform samplerCube SKYBOX_TEXTURE;

uniform float FresnelExp;
uniform float FresnelFactor;

#ifdef SECONDARY_MAP
varying vec2 v_uv1;
#endif

vec4 LightAttrib(int p_id)   { 	if(p_id==0) return Lights[0];		if(p_id==1) return Lights[3];		if(p_id==2) return Lights[6];		if(p_id==3) return Lights[9];		return vec4(-1,0,0,0);  }
vec3 LightPosition(int p_id) { 	if(p_id==0) return Lights[0+1].xyz;	if(p_id==1) return Lights[3+1].xyz; if(p_id==2) return Lights[6+1].xyz;	if(p_id==3) return Lights[9+1].xyz;	return vec3(0,0,0); 	}
vec4 LightColor(int p_id)    { 	if(p_id==0) return Lights[0+2];		if(p_id==1) return Lights[3+2];		if(p_id==2) return Lights[6+2];		if(p_id==3) return Lights[9+2]; 	return vec4(0,0,0,1); 	}

mat3 transpose(mat3 m) {	vec3 l0 = m[0], l1 = m[1], l2 = m[2]; return mat3(vec3(l0.x, l1.x, l2.x), vec3(l0.y, l1.y, l2.y), vec3(l0.z, l1.z, l2.z)); }
mat4 transpose(mat4 m) {	vec4 l0 = m[0], l1 = m[1], l2 = m[2], l3 = m[3]; return mat4(vec4(l0.x, l1.x, l2.x,l3.x), vec4(l0.y, l1.y, l2.y,l3.y), vec4(l0.z, l1.z, l2.z,l3.z),vec4(l0.w, l1.w, l2.w,l3.w)); }

vec3 LightingDiffuse(float p_intensity,vec3 p_light_dir,vec3 p_color,vec3 p_normal) { return p_color.xyz * clamp(dot(p_normal,p_light_dir),0.0,1.0) * p_intensity; }

vec3 LightingSpecular(float p_intensity,vec3 p_light_dir,vec3 p_color, vec3 p_normal, vec3 p_view, float p_shininess)
{
	vec3 rdir = normalize(reflect(p_light_dir, p_normal));  
	return pow(max(dot(rdir, p_view), 0.0), p_shininess) * p_color * p_intensity;	
}

vec3 Lighting(vec3 p_position,vec3 p_normal,vec3 p_color,vec3 p_view,vec3 p_specular,float p_shininess)
{
    vec3 c = vec3(0.0);
    
    for(int i=0;i<MAX_LIGHTS;i++)
	{
		vec4 la 	= LightAttrib(i);
		vec3 lp 	= LightPosition(i);
		vec3 lc 	= LightColor(i).xyz;
		int t   	= int(la.x); //type
		float m		= la.y; 	 //intensity
		float r 	= la.z*0.5;	 //radius
		float atten = la.w; 	 //attenuation
		if(t>=0)
		{
			vec3 v   = -(p_position - lp);
			float a  = t == 0 ? (1.0 - clamp(length(v) / r, 0.0,1.0)) : 1.0;					
			vec3 dir = t == 0 ? normalize(v) : normalize(lp);						
			
			float intensity = m * a;
			
			c += LightingDiffuse (intensity, dir, lc * p_color   , p_normal);
			
			#ifdef SPECULAR_TEXTURE
			c += LightingSpecular(intensity, dir, lc * p_specular, p_normal, p_view, p_shininess);
			#endif
			
			//vec3 rdir = normalize(reflect(v,p_normal));  
		    //c += pow(max(dot(rdir,p_view),0.0),p_shinniness) * p_specular * lc * a * m;
			
		}
	}
	return c;
}

void main(void) 
{	
    vec3 c = vec3(0.0);
    vec3 n = vec3(0.0);
	
    #ifdef NORMAL_TEXTURE
    n = ((texture2D(NormalTexture,    v_uv0.xy).xyz - 0.5) * 2.0);
	n = n * transpose(mat3(normalize(v_tangent),normalize(v_binormal),normalize(v_normal)));
    #else    
    n = normalize(v_normal);
	#endif
    
    vec3 view_dir       = normalize(v_wsVertex.xyz - CameraPosition);
	vec3 reflect_dir    = reflect(view_dir,n);
    
	
	//Sample the Diffuse Term
    vec4  tex_diffuse   = texture2D(DiffuseTexture,   v_uv0.xy) * DiffuseColor;
    
	//Set Diffuse Color
	c = tex_diffuse.xyz;
	
	//Sample Smoothing Factor
	//SmoothMax   -> Max Mipmap Level
	//SmoothRatio -> Blend between constant and sampled smooth.
	vec3  tex_smooth    = texture2D(SmoothTexture,    v_uv0.xy).xyz;
    float smooth_factor = (1.0-tex_smooth.x) * SmoothMax * (1.0-SmoothRatio);
    
	//Sample Global Illumination from Skybox
	vec3  tex_ambient   = textureCube(SKYBOX_TEXTURE, reflect(view_dir,n),smooth_factor).xyz * Ambient.xyz;
	
	//Default Specular data
    vec4  tex_specular  =  vec4(0, 0, 0, 0);
	float exp_specular  =  1.0;
	
	#ifdef SPECULAR_TEXTURE
	//Sample Specular data
	tex_specular = texture2D(SpecularTexture,  v_uv0.xy) * SpecularColor;
	exp_specular = SpecularExp;
	#endif
	
	//Calculate Lighting for Diffuse and Specular Terms (if enabled)
	c  = Lighting(v_wsVertex.xyz, n, c, view_dir, tex_specular.xyz, exp_specular);
	
	//Compose the result using the Global Illumination sample and a Contant "gain" to finetune the final color.
	c += (tex_ambient * tex_diffuse.xyz * (DiffuseGain + 1.0));
	
	//Sample the Skybox again for Fresnel term.
	vec4  tex_skybox    = textureCube(SKYBOX_TEXTURE, reflect(view_dir, n));	
	
	//Calculates the falloff term.
	float falloff       = pow(1.0 - clamp(dot(-view_dir, n),0.0,1.0),FresnelExp) * FresnelFactor;
	
	//Adds the Fresnel term.
    c  = c + (tex_skybox.xyz - c) * falloff;
	
	#ifdef OCCLUSION_TEXTURE
	//Sample Occlusion Texture.
    vec4  tex_occlusion = texture2D(OcclusionTexture, v_uv0.xy);
	tex_occlusion       = vec4(1.0) + (tex_occlusion - vec4(1.0)) * OcclusionFactor;
	
	//Attenuate the fragment color based on it.
	c *= tex_occlusion.xyz;	
	#endif
    
	#ifdef EMISSION_TEXTURE
	//Sample the Emission Texture
	vec4  tex_emission  = texture2D(EmissionTexture,  v_uv0.xy) * EmissionColor;
	
	//Adds the emission to the final color.
	c += tex_emission.xyz;
	#endif
	
	//Sets the final color and alpha
	gl_FragColor.xyz = c.xyz;
	gl_FragColor.a 	 = tex_diffuse.a * v_color.a;
}
';
	
}