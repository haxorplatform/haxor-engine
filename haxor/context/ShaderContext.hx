package haxor.context;

/**
 * Class that handles shader templates.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class ShaderContext
{
	/**
	 * Flat with solid color shader.
	 */
	static private var flat_source : String = 
	'
	<shader id="haxor/unlit/Flat">	
		<vertex>		
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
		</vertex>		
		<fragment>			
			varying vec4 v_color;			
			void main(void) { gl_FragColor = v_color; }			
		</fragment>	
	</shader>	
	';
	
	/**
	 * Flat with a Diffuse texture.
	 */
	static private var flat_texture_source : String =
	'
	<shader id="haxor/unlit/FlatTexture">	
		<vertex>
		uniform mat4  WorldMatrix;
		uniform mat4  ViewMatrix;
		uniform mat4  ProjectionMatrix;		
		attribute vec3 vertex;					
		attribute vec4 color;
		attribute vec3 uv0;		
		varying vec3 v_uv0;
		varying vec4 v_color;		
		void main(void) 
		{		
			gl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;
			v_uv0   = uv0;
			v_color = color;
		}		
		</vertex>		
		<fragment>
			varying vec3 v_uv0;
			varying vec4 v_color;			
			uniform sampler2D DiffuseTexture;
			void main(void) 
			{	
				vec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy);	
				gl_FragColor.xyz = (tex_diffuse.xyz * v_color.xyz);
				gl_FragColor.a 	 = tex_diffuse.a * v_color.a;
			}
		</fragment>	
	</shader>
	';
	
	
	static private var flat_texture_skin_source : String = 
	'
	<shader id="haxor/unlit/FlatTextureSkin">	
		<vertex precision="low">
		
		uniform mat4  WorldMatrix;
		uniform mat4  WorldMatrixIT;
		uniform mat4  ViewMatrix;
		uniform mat4  ProjectionMatrix;
		uniform vec3  WSCameraPosition;		
		
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
			v_color = color;			
			v_normal = ln * mat3(WorldMatrixIT);			
			gl_Position = ((lv * wm) * ViewMatrix) * ProjectionMatrix;
		}		
		</vertex>
		
		<fragment precision="medium">
					
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
		</fragment>	
	</shader>
	';
	
	
	/**
	 * Grid gizmo shader.
	 */
	static private var grid_source : String = 
	'
	<shader id="haxor/gizmo/Grid">	
		<vertex>		
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
		</vertex>		
		<fragment>			
			varying vec4 v_color;			
			void main(void) 
			{
				gl_FragColor = v_color;
			}			
		</fragment>	
	</shader>	
	';
	
	
	/**
	 * Screen Texture shader.
	 */
	static private var texture_source : String = 
	'
	<shader id="haxor/gizmo/Texture">	
		<vertex>		
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
		</vertex>		
		<fragment>			
			varying vec4 v_color;	
			varying vec2 v_uv0;
			uniform sampler2D Texture;			
			void main(void) 
			{
				gl_FragColor = texture2D(Texture, v_uv0) * v_color;
			}			
		</fragment>	
	</shader>	
	';
	
	
	/**
	 * Gizmos shader.
	 */
	static private var gizmo_source : String = 
	'
	<shader id="haxor/gizmo/Gizmo">	
		<vertex>	
		
		#define GIZMO_POINT       0
		#define GIZMO_LINE        1
		#define GIZMO_AXIS        2
		#define GIZMO_WIRE_CUBE   3
		#define GIZMO_WIRE_SPHERE 4
		#define GIZMO_CANVAS	  10
		
		
		
				mat4         WorldMatrix;
		uniform mat4  		 ViewMatrix;
		uniform mat4  		 ProjectionMatrix;				
		uniform int   		 Count;
		uniform int   		 Type;		
		uniform sampler2D 	 Data;
		uniform int  		 DataSize;		
			    vec4		 DataColor;
				vec4		 DataA;
				vec4		 DataB;
		
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
		</vertex>		
		<fragment>			
			varying vec4 v_color;			
			void main(void) { gl_FragColor = v_color; }
		</fragment>	
	</shader>	
	';
	
	/**
	 * Particle system rendering shader.
	 */
	static private var flat_particle_source : String = 
	'
	<shader id="haxor/unlit/Particle">	

		<vertex precision="low">
		
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
		</vertex>
		
		<fragment precision="low">
			
			
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
		</fragment>	
	</shader>	
	';
	
	/**
	 * Shader responsible by the camera clear function with cubemaps.
	 */
	static private var clear_skybox_source : String =
	'
	<shader id="haxor/clear/Skybox">
		<vertex precision="low">		
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
		</vertex>
		<fragment precision="low">			
			uniform samplerCube  SkyboxTexture;
			varying vec3 v_view_dir;
			void main() 
			{ 
			gl_FragColor = textureCube(SkyboxTexture, normalize(v_view_dir));
			}
		</fragment>
	</shader>
	';
	
}