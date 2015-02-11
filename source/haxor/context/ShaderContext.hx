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
		
		#define SKINNING_TEXTURE_SIZE 2048.0
		#define BINDS_OFFSET		  1024.0
		
		uniform mat4  WorldMatrix;
		uniform mat4  WorldMatrixIT;
		uniform mat4  ViewMatrix;
		uniform mat4  ProjectionMatrix;
		uniform vec3  WSCameraPosition;		
		
		//uniform vec4  Skinning[MAX_BONES];
		
		uniform sampler2D Skinning;
		
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
		
		vec4 SkinningRead(float id)
		{
			return texture2D(Skinning, vec2(0.0,(id/(SKINNING_TEXTURE_SIZE-1.0))));
		}
		
		mat4 GetSkinMatrix(float b,float o)
		{
			vec4 l0, l1, l2;						
			l0 = SkinningRead(b+o); l1 = SkinningRead(b+1.0+o); l2 = SkinningRead(b+2.0+o);
			return mat4(l0.x, l0.y, l0.z, l0.w, l1.x, l1.y, l1.z, l1.w, l2.x, l2.y, l2.z, l2.w, 0, 0, 0, 1);			
		}
		
		mat4 SkinWorldMatrix()
		{
			vec4 b = bone * 3.0;
			vec4 w = weight;
			float ivs = 1.0 / (weight.x + weight.y + weight.z + weight.w);
			w *= ivs;
			mat4 j0 = GetSkinMatrix(b[0],0.0);
			mat4 b0 = GetSkinMatrix(b[0],BINDS_OFFSET);
			mat4 j1 = GetSkinMatrix(b[1],0.0);
			mat4 b1 = GetSkinMatrix(b[1],BINDS_OFFSET);
			mat4 j2 = GetSkinMatrix(b[2],0.0);
			mat4 b2 = GetSkinMatrix(b[2],BINDS_OFFSET);
			mat4 j3 = GetSkinMatrix(b[3],0.0);
			mat4 b3 = GetSkinMatrix(b[3],BINDS_OFFSET);
			
			return    ((b0 * j0) * w[0])+
			          ((b1 * j1) * w[1])+
			          ((b2 * j2) * w[2])+
			          ((b3 * j3) * w[3]);
			
			
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
		
		<fragment precision="low">
					
			uniform sampler2D DiffuseTexture;			
			
			uniform sampler2D Skinning;
			
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
		
		#define PARTICLE_LENGTH		 7.0
		
		#define PARTICLE_STATUS		 0.0
		#define PARTICLE_POSITION	 1.0
		#define PARTICLE_ROTATION	 2.0
		#define PARTICLE_SIZE		 3.0
		#define PARTICLE_VELOCITY	 4.0
		#define PARTICLE_COLOR		 5.0
		#define PARTICLE_START		 6.0
		
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
	
}