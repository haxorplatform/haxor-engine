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
				gl_Position = vec4( -2.0, 0.0, 0.0, 1.0);
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
				gl_PointSize = DataA.x * (ncp.z / ncp.w);				
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
			
							
			v_color = DataColor * color;
		}		
		</vertex>		
		<fragment>			
			varying vec4 v_color;			
			void main(void) { gl_FragColor = v_color; }
		</fragment>	
	</shader>	
	';
	
}