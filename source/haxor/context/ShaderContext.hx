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
			uniform sampler2D Tex0;			
			
			void main(void) 
			{	
				vec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy*0.1);			
				if (length(tex_diffuse.xyz) < 0.01) discard;				
				gl_FragColor.xyz = (tex_diffuse.xyz * v_color.xyz) + texture2D(Tex0, v_uv0.xy).xyz*0.5;
				
				gl_FragColor.a 	 = tex_diffuse.a * v_color.a*0.5;
			}
		</fragment>	
	</shader>
	';
	
	/**
	 * Grid gizmo shader.
	 */
	static private var gizmo_source : String = 
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
}