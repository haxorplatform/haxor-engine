package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ShaderContext extends haxe.lang.HxObject
{
	static 
	{
		haxor.context.ShaderContext.flat_source = "\r\n\t<shader id=\"haxor/unlit/Flat\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\t\t\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tgl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\t\tv_color = color * Tint;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) { gl_FragColor = v_color; }\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t";
		haxor.context.ShaderContext.flat_texture_source = "\r\n\t<shader id=\"haxor/unlit/FlatTexture\">\t\r\n\t\t<vertex>\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\t\r\n\t\tattribute vec4 color;\r\n\t\tattribute vec3 uv0;\t\t\r\n\t\tvarying vec3 v_uv0;\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tgl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\tv_uv0   = uv0;\r\n\t\t\tv_color = color;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\r\n\t\t\tvarying vec3 v_uv0;\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tuniform sampler2D DiffuseTexture;\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\r\n\t\t\t\tvec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy);\t\r\n\t\t\t\tgl_FragColor.xyz = (tex_diffuse.xyz * v_color.xyz);\r\n\t\t\t\tgl_FragColor.a \t = tex_diffuse.a * v_color.a;\r\n\t\t\t}\r\n\t\t</fragment>\t\r\n\t</shader>\r\n\t";
		haxor.context.ShaderContext.flat_texture_skin_source = "\r\n\t<shader id=\"haxor/unlit/FlatTextureSkin\">\t\r\n\t\t<vertex precision=\"low\">\r\n\t\t\r\n\t\t#define SKINNING_TEXTURE_SIZE 2048.0\r\n\t\t#define BINDS_OFFSET\t\t  1024.0\r\n\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  WorldMatrixIT;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\r\n\t\tuniform vec3  WSCameraPosition;\t\t\r\n\t\t\r\n\t\t//uniform vec4  Skinning[MAX_BONES];\r\n\t\t\r\n\t\tuniform sampler2D Skinning;\r\n\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\t\r\n\t\tattribute vec4 color;\r\n\t\tattribute vec3 normal;\r\n\t\tattribute vec3 uv0;\r\n\t\tattribute vec4 bone;\r\n\t\tattribute vec4 weight;\r\n\t\t\r\n\t\tvarying vec3 v_uv0;\r\n\t\tvarying vec3 v_normal;\r\n\t\tvarying vec4 v_color;\r\n\t\tvarying vec4 v_wsVertex;\r\n\t\tvarying vec3 v_wsView;\t\r\n\t\t\r\n\t\tvec4 SkinningRead(float id)\r\n\t\t{\r\n\t\t\treturn texture2D(Skinning, vec2(0.0,(id/(SKINNING_TEXTURE_SIZE-1.0))));\r\n\t\t}\r\n\t\t\r\n\t\tmat4 GetSkinMatrix(float b,float o)\r\n\t\t{\r\n\t\t\tvec4 l0, l1, l2;\t\t\t\t\t\t\r\n\t\t\tl0 = SkinningRead(b+o); l1 = SkinningRead(b+1.0+o); l2 = SkinningRead(b+2.0+o);\r\n\t\t\treturn mat4(l0.x, l0.y, l0.z, l0.w, l1.x, l1.y, l1.z, l1.w, l2.x, l2.y, l2.z, l2.w, 0, 0, 0, 1);\t\t\t\r\n\t\t}\r\n\t\t\r\n\t\tmat4 SkinWorldMatrix()\r\n\t\t{\r\n\t\t\tvec4 b = bone * 3.0;\r\n\t\t\tvec4 w = weight;\r\n\t\t\tfloat ivs = 1.0 / (weight.x + weight.y + weight.z + weight.w);\r\n\t\t\tw *= ivs;\r\n\t\t\tmat4 j0 = GetSkinMatrix(b[0],0.0);\r\n\t\t\tmat4 b0 = GetSkinMatrix(b[0],BINDS_OFFSET);\r\n\t\t\tmat4 j1 = GetSkinMatrix(b[1],0.0);\r\n\t\t\tmat4 b1 = GetSkinMatrix(b[1],BINDS_OFFSET);\r\n\t\t\tmat4 j2 = GetSkinMatrix(b[2],0.0);\r\n\t\t\tmat4 b2 = GetSkinMatrix(b[2],BINDS_OFFSET);\r\n\t\t\tmat4 j3 = GetSkinMatrix(b[3],0.0);\r\n\t\t\tmat4 b3 = GetSkinMatrix(b[3],BINDS_OFFSET);\r\n\t\t\t\r\n\t\t\treturn    ((b0 * j0) * w[0])+\r\n\t\t\t          ((b1 * j1) * w[1])+\r\n\t\t\t          ((b2 * j2) * w[2])+\r\n\t\t\t          ((b3 * j3) * w[3]);\r\n\t\t\t\r\n\t\t\t\r\n\t\t}\r\n\t\t\t\t\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\r\n\t\t\tvec4 lv = vec4(vertex,1.0);\r\n\t\t\tvec3 ln = vec3(normal);\r\n\t\t\tmat4 swm = SkinWorldMatrix();\r\n\t\t\tmat4 wm;\t\t\t\t\t\r\n\t\t\twm = swm;\r\n\t\t\t//wm = WorldMatrix;\r\n\t\t\t\r\n\t\t\tv_uv0   = uv0;\r\n\t\t\tv_color = color;\t\t\t\r\n\t\t\tv_normal = ln * mat3(WorldMatrixIT);\t\t\t\r\n\t\t\tgl_Position = ((lv * wm) * ViewMatrix) * ProjectionMatrix;\r\n\t\t}\t\t\r\n\t\t</vertex>\r\n\t\t\r\n\t\t<fragment precision=\"low\">\r\n\t\t\t\t\t\r\n\t\t\tuniform sampler2D DiffuseTexture;\t\t\t\r\n\t\t\t\r\n\t\t\tuniform sampler2D Skinning;\r\n\t\t\t\r\n\t\t\tvarying vec3 v_uv0;\r\n\t\t\tvarying vec4 v_color;\r\n\t\t\tvarying vec3 v_normal;\r\n\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\r\n\t\t\t\tvec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy);\r\n\t\t\t\tgl_FragColor.xyz = tex_diffuse.xyz * v_color.xyz;\r\n\t\t\t\tgl_FragColor.a \t = tex_diffuse.a * v_color.a;\r\n\t\t\t}\r\n\t\t</fragment>\t\r\n\t</shader>\r\n\t";
		haxor.context.ShaderContext.grid_source = "\r\n\t<shader id=\"haxor/gizmo/Grid\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\r\n\t\tuniform float Area;\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\tgl_Position = ((vec4(vertex*Area, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\tv_color = color * Tint;\t\t\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\r\n\t\t\t\tgl_FragColor = v_color;\r\n\t\t\t}\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t";
		haxor.context.ShaderContext.texture_source = "\r\n\t<shader id=\"haxor/gizmo/Texture\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform vec2  Screen;\r\n\t\tuniform vec4  Rect;\r\n\t\tuniform vec4  Tint;\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\r\n\t\tvarying vec4 v_color;\r\n\t\tvarying vec2 v_uv0;\r\n\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tvec4 p = vec4(vertex, 1);\r\n\t\t\tfloat sw = Screen.x * 0.5;\r\n\t\t\tfloat sh = Screen.y * 0.5;\r\n\t\t\tp.x *= Rect.z / sw;\r\n\t\t\tp.y *= Rect.w / sh;\r\n\t\t\tp.x += Rect.x / sw;\r\n\t\t\tp.y -= Rect.y / sh;\t\t\t\r\n\t\t\tp.x -= 1.0;\r\n\t\t\tp.y += 1.0;\t\t\t\r\n\t\t\tp.z = 0.001;\r\n\t\t\tgl_Position = p;\r\n\t\t\tv_color = Tint;\t\t\r\n\t\t\tv_uv0   = vec2(vertex.x,1.0+vertex.y);\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\r\n\t\t\tvarying vec2 v_uv0;\r\n\t\t\tuniform sampler2D Texture;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\r\n\t\t\t\tgl_FragColor = texture2D(Texture, v_uv0) * v_color;\r\n\t\t\t}\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t";
		haxor.context.ShaderContext.gizmo_source = "\r\n\t<shader id=\"haxor/gizmo/Gizmo\">\t\r\n\t\t<vertex>\t\r\n\t\t\r\n\t\t#define GIZMO_POINT       0\r\n\t\t#define GIZMO_LINE        1\r\n\t\t#define GIZMO_AXIS        2\r\n\t\t#define GIZMO_WIRE_CUBE   3\r\n\t\t#define GIZMO_WIRE_SPHERE 4\r\n\t\t\r\n\t\t\r\n\t\t\r\n\t\t\t\tmat4         WorldMatrix;\r\n\t\tuniform mat4  \t\t ViewMatrix;\r\n\t\tuniform mat4  \t\t ProjectionMatrix;\t\t\t\t\r\n\t\tuniform int   \t\t Count;\r\n\t\tuniform int   \t\t Type;\t\t\r\n\t\tuniform sampler2D \t Data;\r\n\t\tuniform int  \t\t DataSize;\r\n\t\t\t\tvec4\t\t DataColor;\r\n\t\t\t\tvec4\t\t DataA;\r\n\t\t\t\tvec4\t\t DataB;\r\n\t\t\r\n\t\tattribute float id;\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\r\n\t\t\r\n\t\tvarying vec4 v_color;\r\n\t\t\r\n\t\tvec4 GetPixel(float p_pix,float p_ds,float p_ids)\r\n\t\t{\t\t\t\r\n\t\t\tfloat px = mod(p_pix, p_ds) * p_ids;\r\n\t\t\tfloat py = (p_pix * p_ids) * p_ids;\r\n\t\t\treturn texture2D(Data, vec2(px,py));\r\n\t\t}\r\n\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\r\n\t\t\tif (id >= float(Count)) \r\n\t\t\t{\r\n\t\t\t\tgl_Position = vec4( -2.0, 0.0, 0.0, 1.0);\r\n\t\t\t\treturn; \r\n\t\t\t}\t\t\t\r\n\t\t\tfloat p  \t= id * 6.0;\r\n\t\t\tfloat ds\t= float(DataSize);\r\n\t\t\tfloat ids\t= 1.0 / ds;\t\t\t\r\n\t\t\tDataColor \t= GetPixel(p,ds,ids);\r\n\t\t\tDataA \t\t= GetPixel(p + 1.0,ds,ids);\r\n\t\t\tDataB \t\t= GetPixel(p + 2.0,ds,ids);\t\t\t\r\n\t\t\tvec4 l0 \t= GetPixel(p + 3.0,ds,ids);\r\n\t\t\tvec4 l1 \t= GetPixel(p + 4.0,ds,ids);\r\n\t\t\tvec4 l2 \t= GetPixel(p + 5.0,ds,ids);\t\r\n\t\t\tvec4 v\t\t= vec4(vertex, 1.0);\r\n\t\t\tWorldMatrix = mat4(l0.x, l0.y, l0.z, l0.w, l1.x, l1.y, l1.z, l1.w, l2.x, l2.y, l2.z, l2.w, 0, 0, 0, 1);\r\n\t\t\t\r\n\t\t\tif (Type == GIZMO_POINT)\r\n\t\t\t{\t\r\n\t\t\t\tvec4 ncp = ((vec4(DataB.xyz, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\t\t\tv.xyz += DataB.xyz;\r\n\t\t\t\tgl_PointSize = DataA.x * (ncp.z / ncp.w);\t\t\t\t\t\t\t\t\r\n\t\t\t\tgl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\t}\r\n\t\t\telse\r\n\t\t\tif (Type == GIZMO_LINE)\r\n\t\t\t{\r\n\t\t\t\tfloat r = v.x;\r\n\t\t\t\tv.xyz = DataA.xyz + (DataB.xyz - DataA.xyz) * r;\r\n\t\t\t\tgl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\t}\r\n\t\t\telse\r\n\t\t\tif (Type == GIZMO_AXIS)\r\n\t\t\t{\t\t\r\n\t\t\t\tfloat sx   = length(vec3(WorldMatrix[0][0],WorldMatrix[1][0],WorldMatrix[2][0]));\r\n\t\t\t\tfloat sy   = length(vec3(WorldMatrix[0][1],WorldMatrix[1][1],WorldMatrix[2][1]));\r\n\t\t\t\tfloat sz   = length(vec3(WorldMatrix[0][2],WorldMatrix[1][2],WorldMatrix[2][2]));\t\t\t\t\r\n\t\t\t\tvec3 scale = vec3(sx, sy, sz);\t\t\t\t\r\n\t\t\t\tvec4 ncp = ((vec4(DataB.xyz, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\t\t\tv.xyz *= (DataA.xyz / scale.xyz) * ncp.w * 0.025;\r\n\t\t\t\tv.xyz += DataB.xyz;\r\n\t\t\t\tgl_Position  = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\t\t}\r\n\t\t\telse\r\n\t\t\tif (Type == GIZMO_WIRE_CUBE)\r\n\t\t\t{\r\n\t\t\t\tv.xyz *= DataA.xyz;\r\n\t\t\t\tv.xyz += DataB.xyz;\r\n\t\t\t\tgl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\t}\r\n\t\t\telse\r\n\t\t\tif (Type == GIZMO_WIRE_SPHERE)\r\n\t\t\t{\r\n\t\t\t\tv.xyz *= DataA.x;\r\n\t\t\t\tv.xyz += DataB.xyz;\r\n\t\t\t\tgl_Position = ((v * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\t}\r\n\t\t\t\r\n\t\t\t\t\t\t\t\r\n\t\t\tv_color = DataColor * color;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) { gl_FragColor = v_color; }\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t";
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
	
	
	public static   void __hx_ctor_haxor_context_ShaderContext(haxor.context.ShaderContext __temp_me156)
	{
		{
		}
		
	}
	
	
	public static  java.lang.String flat_source;
	
	public static  java.lang.String flat_texture_source;
	
	public static  java.lang.String flat_texture_skin_source;
	
	public static  java.lang.String grid_source;
	
	public static  java.lang.String texture_source;
	
	public static  java.lang.String gizmo_source;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.ShaderContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.ShaderContext();
	}
	
	
}


