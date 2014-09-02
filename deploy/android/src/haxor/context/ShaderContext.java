package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ShaderContext extends haxe.lang.HxObject
{
	static 
	{
		haxor.context.ShaderContext.flat_source = "\r\n\t<shader id=\"haxor/unlit/Flat\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\t\t\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tgl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\t\tv_color = color * Tint;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) { gl_FragColor = v_color; }\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t";
		haxor.context.ShaderContext.flat_texture_source = "\r\n\t<shader id=\"haxor/unlit/FlatTexture\">\t\r\n\t\t<vertex>\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tattribute vec3 vertex;\t\t\t\t\t\r\n\t\tattribute vec4 color;\r\n\t\tattribute vec3 uv0;\t\t\r\n\t\tvarying vec3 v_uv0;\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\t\tgl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\r\n\t\t\tv_uv0   = uv0;\r\n\t\t\tv_color = color;\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\r\n\t\t\tvarying vec3 v_uv0;\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tuniform sampler2D DiffuseTexture;\r\n\t\t\tuniform sampler2D Tex0;\t\t\t\r\n\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\t\r\n\t\t\t\tvec4 tex_diffuse = texture2D(DiffuseTexture, v_uv0.xy*0.1);\t\t\t\r\n\t\t\t\tif (length(tex_diffuse.xyz) < 0.01) discard;\t\t\t\t\r\n\t\t\t\tgl_FragColor.xyz = (tex_diffuse.xyz * v_color.xyz) + texture2D(Tex0, v_uv0.xy).xyz*0.5;\r\n\t\t\t\t\r\n\t\t\t\tgl_FragColor.a \t = tex_diffuse.a * v_color.a*0.5;\r\n\t\t\t}\r\n\t\t</fragment>\t\r\n\t</shader>\r\n\t";
		haxor.context.ShaderContext.gizmo_source = "\r\n\t<shader id=\"haxor/gizmo/Grid\">\t\r\n\t\t<vertex>\t\t\r\n\t\tuniform mat4  WorldMatrix;\r\n\t\tuniform mat4  ViewMatrix;\r\n\t\tuniform mat4  ProjectionMatrix;\t\t\r\n\t\tuniform vec4  Tint;\t\t\r\n\t\tuniform float Area;\r\n\t\tattribute vec3 vertex;\t\t\r\n\t\tattribute vec4 color;\t\t\r\n\t\tvarying vec4 v_color;\t\t\r\n\t\tvoid main(void) \r\n\t\t{\t\t\r\n\t\tgl_Position = ((vec4(vertex*Area, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix;\t\t\t\t\r\n\t\tv_color = color * Tint;\t\t\r\n\t\t}\t\t\r\n\t\t</vertex>\t\t\r\n\t\t<fragment>\t\t\t\r\n\t\t\tvarying vec4 v_color;\t\t\t\r\n\t\t\tvoid main(void) \r\n\t\t\t{\r\n\t\t\t\tgl_FragColor = v_color;\r\n\t\t\t}\t\t\t\r\n\t\t</fragment>\t\r\n\t</shader>\t\r\n\t";
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
	
	
	public static   void __hx_ctor_haxor_context_ShaderContext(haxor.context.ShaderContext __temp_me164193)
	{
		{
		}
		
	}
	
	
	public static  java.lang.String flat_source;
	
	public static  java.lang.String flat_texture_source;
	
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


