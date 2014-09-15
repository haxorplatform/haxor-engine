package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ShaderContext extends haxe.lang.HxObject
{
	static 
	{
		haxor.context.ShaderContext.flat_source = "\r\n\t<shader id=\"haxor/unlit/Flat\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\t\t\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tgl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\t\tv_color = color * Tint;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) { gl_FragColor = v_color; }\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t";
		haxor.context.ShaderContext.flat_texture_source = "\r\n\t<shader id=\"haxor/unlit/FlatTexture\">\t\r\n\t\t<vertex>\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\t\r\n\t\tattribute vec4 color;\r\n\t\tattribute vec3 uv0;\t\t\r\n\t\tvarying vec3 v_uv0;\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tgl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\tv_uv0   = uv0;\r\n\t\t\tv_color = color;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\r\n\t\t\tvarying vec3 v_uv0;\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tuniform sampler2D DiffuseTexture;\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\r\n\t\t\t\tvec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy);\t\r\n\t\t\t\tgl_FragColor.xyz = (tex_diffuse.xyz * v_color.xyz);\r\n\t\t\t\tgl_FragColor.a \t = tex_diffuse.a * v_color.a;\r\n\t\t\t}\r\n\t\t</fragment>\t\r\n\t</shader>\r\n\t";
		haxor.context.ShaderContext.gizmo_source = "\r\n\t<shader id=\"haxor/gizmo/Grid\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\r\n\t\tuniform float Area;\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\tgl_Position = ((vec4(vertex*Area, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\tv_color = color * Tint;\t\t\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\r\n\t\t\t\tgl_FragColor = v_color;\r\n\t\t\t}\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t";
		haxor.context.ShaderContext.flat_texture_skin_source = "\r\n\t<shader id=\"haxor/unlit/FlatTextureSkin\">\t\r\n\t\t<vertex>\r\n\t\t\r\n\t\t#define SKINNING_TEXTURE_SIZE 2048.0\r\n\t\t#define BINDS_OFFSET\t\t  1024.0\r\n\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  WorldMatrixIT;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\r\n\t\tuniform vec3  WSCameraPosition;\t\t\r\n\t\t\r\n\t\t//uniform vec4  Skinning[MAX_BONES];\r\n\t\t\r\n\t\tuniform sampler2D Skinning;\r\n\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\t\r\n\t\tattribute vec4 color;\r\n\t\tattribute vec3 normal;\r\n\t\tattribute vec3 uv0;\r\n\t\tattribute vec4 bone;\r\n\t\tattribute vec4 weight;\r\n\t\t\r\n\t\tvarying vec3 v_uv0;\r\n\t\tvarying vec3 v_normal;\r\n\t\tvarying vec4 v_color;\r\n\t\tvarying vec4 v_wsVertex;\r\n\t\tvarying vec3 v_wsView;\t\r\n\t\t\r\n\t\tvec4 SkinningRead(float id)\r\n\t\t{\r\n\t\t\treturn texture2D(Skinning, vec2(0.0,(id/(SKINNING_TEXTURE_SIZE-1.0))));\r\n\t\t}\r\n\t\t\r\n\t\tmat4 SkinWorldMatrix()\r\n\t\t{\r\n\t\t\t\r\n\t\t\tfloat b;\r\n\t\t\tfloat o = BINDS_OFFSET;\r\n\t\t\tvec4 l0,l1,l2;\r\n\t\t\t\r\n\t\t\tb = (bone[0]) * 3.0; \t\t\t\r\n\t\t\tl0 = SkinningRead(b); l1 = SkinningRead(b+1.0); l2 = SkinningRead(b+2.0);\r\n\t\t\tmat4 j0 = mat4(l0.x,l0.y,l0.z,l0.w, l1.x,l1.y,l1.z,l1.w, l2.x,l2.y,l2.z,l2.w, 0,0,0,1);\r\n\t\t\tl0 = SkinningRead(b+o); l1 = SkinningRead(b+1.0+o); l2 = SkinningRead(b+2.0+o);\r\n\t\t\tmat4 b0 = mat4(l0.x,l0.y,l0.z,l0.w, l1.x,l1.y,l1.z,l1.w, l2.x,l2.y,l2.z,l2.w, 0,0,0,1);\r\n\t\t\t\r\n\t\t\tb = (bone[1]) * 3.0; \r\n\t\t\tl0 = SkinningRead(b); l1 = SkinningRead(b+1.0); l2 = SkinningRead(b+2.0);\r\n\t\t\tmat4 j1 = mat4(l0.x,l0.y,l0.z,l0.w, l1.x,l1.y,l1.z,l1.w, l2.x,l2.y,l2.z,l2.w, 0,0,0,1);\r\n\t\t\tl0 = SkinningRead(b+o); l1 = SkinningRead(b+1.0+o); l2 = SkinningRead(b+2.0+o);\r\n\t\t\tmat4 b1 = mat4(l0.x,l0.y,l0.z,l0.w, l1.x,l1.y,l1.z,l1.w, l2.x,l2.y,l2.z,l2.w, 0,0,0,1);\r\n\t\t\t\r\n\t\t\tb = (bone[2]) * 3.0; \r\n\t\t\tl0 = SkinningRead(b); l1 = SkinningRead(b+1.0); l2 = SkinningRead(b+2.0);\r\n\t\t\tmat4 j2 = mat4(l0.x,l0.y,l0.z,l0.w, l1.x,l1.y,l1.z,l1.w, l2.x,l2.y,l2.z,l2.w, 0,0,0,1);\r\n\t\t\tl0 = SkinningRead(b+o); l1 = SkinningRead(b+1.0+o); l2 = SkinningRead(b+2.0+o);\r\n\t\t\tmat4 b2 = mat4(l0.x,l0.y,l0.z,l0.w, l1.x,l1.y,l1.z,l1.w, l2.x,l2.y,l2.z,l2.w, 0,0,0,1);\r\n\t\t\t\r\n\t\t\tb = (bone[3]) * 3.0; \r\n\t\t\tl0 = SkinningRead(b); l1 = SkinningRead(b+1.0); l2 = SkinningRead(b+2.0);\r\n\t\t\tmat4 j3 = mat4(l0.x,l0.y,l0.z,l0.w, l1.x,l1.y,l1.z,l1.w, l2.x,l2.y,l2.z,l2.w, 0,0,0,1);\t\t\t\r\n\t\t\tl0 = SkinningRead(b+o); l1 = SkinningRead(b+1.0+o); l2 = SkinningRead(b+2.0+o);\r\n\t\t\tmat4 b3 = mat4(l0.x,l0.y,l0.z,l0.w, l1.x,l1.y,l1.z,l1.w, l2.x,l2.y,l2.z,l2.w, 0,0,0,1);\r\n\t\t\t\r\n\t\t\t\r\n\t\t\treturn    ((b0 * j0) * weight.x)+\r\n\t\t\t          ((b1 * j1) * weight.y)+\r\n\t\t\t          ((b2 * j2) * weight.z)+\r\n\t\t\t          ((b3 * j3) * weight.w);\r\n\t\t\t\r\n\t\t\t\r\n\t\t}\r\n\t\t\t\t\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\r\n\t\t\tvec4 lv = vec4(vertex,1.0);\r\n\t\t\tvec3 ln = vec3(normal);\r\n\t\t\tmat4 swm = SkinWorldMatrix();\r\n\t\t\tmat4 wm;\t\t\t\t\t\r\n\t\t\twm = swm;\r\n\t\t\t//wm = WorldMatrix + (wm-WorldMatrix) * 1.0;\r\n\t\t\t\r\n\t\t\tv_uv0   = uv0;\r\n\t\t\tv_color = color;\r\n\t\t\t//v_color.xyz = swm[1].xyz;\r\n\t\t\tv_normal = ln * mat3(WorldMatrixIT);\t\t\t\r\n\t\t\tgl_Position = ((lv * wm) * ViewMatrix) * ProjectionMatrix;\r\n\t\t}\t\t\r\n\t\t</vertex>\r\n\t\t\r\n\t\t<fragment>\r\n\t\t\t\t\t\r\n\t\t\tuniform sampler2D DiffuseTexture;\t\t\t\r\n\t\t\t\t\t\t\r\n\t\t\tvarying vec3 v_uv0;\r\n\t\t\tvarying vec4 v_color;\r\n\t\t\tvarying vec3 v_normal;\r\n\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\r\n\t\t\t\tvec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy);\r\n\t\t\t\tgl_FragColor.xyz = tex_diffuse.xyz * v_color.xyz;\r\n\t\t\t\tgl_FragColor.a \t = tex_diffuse.a * v_color.a;\r\n\t\t\t}\r\n\t\t</fragment>\t\r\n\t</shader>\r\n\t";
	}
	public    ShaderContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ShaderContext()
	{
		haxor.context.ShaderContext.__hx_ctor_haxor_context_ShaderContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_ShaderContext(haxor.context.ShaderContext __temp_me255387)
	{
		{
		}
		
	}
	
	
	public static  java.lang.String flat_source;
	
	public static  java.lang.String flat_texture_source;
	
	public static  java.lang.String gizmo_source;
	
	public static  java.lang.String flat_texture_skin_source;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.ShaderContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.ShaderContext();
	}
	
	
}


