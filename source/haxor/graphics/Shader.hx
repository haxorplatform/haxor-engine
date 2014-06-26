/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.graphics;
import js.Browser;
import js.html.Element;
import js.html.EmbedElement;
import js.html.Node;
import js.html.NodeList;
import js.html.ObjectElement;
import js.html.ScriptElement;
import js.html.webgl.Program;
import js.html.XMLHttpRequest;
import js.Lib;
import haxor.api.ShaderAPI;
import haxor.core.Asset;
import haxor.core.Resource;

/**
 * ...
 * @author Eduardo Pons
 */
@:allow(haxor)
class Shader extends Resource
{
	
	/**
	 * 
	 */
	static public var error(get_error, never) : Shader;
	static var m_error : Shader;		
	static function get_error():Shader
	{
		if (m_error != null) return m_error;
		m_error = cast Asset.Get("haxor/internal/Error");
		if (m_error != null) return m_error;
		var src:String = "";		
		src += "<shader id='haxor/internal/Error'>";
		src += "<vertex>";
		src += "uniform mat4 WorldMatrix;";
		src += "uniform mat4 ViewMatrix;";
		src += "uniform mat4 ProjectionMatrix;";
		src += "attribute vec3 vertex;";
		src += "attribute vec3 normal;";
		src += "varying vec3 onormal;";
		src += "void main(void) { gl_Position = ((vec4(vertex, 1.0) * WorldMatrix) * ViewMatrix) * ProjectionMatrix; onormal = normal * mat3(WorldMatrix);}";
		src += "</vertex>";
		src += "<fragment>";
		src += "precision mediump float;";
		src += "varying vec3 onormal;";
		//src += "void main(void) { float diff = clamp(dot(normalize(onormal),normalize(vec3(1,1,1)),0.3,1.0)); gl_FragColor = vec4(1.0, 0.0, 1, 1.0) * diff; }";
		src += "void main(void) { float diff = dot(normalize(onormal),normalize(vec3(1.0,1.0,1.0))); gl_FragColor = vec4(1.0, 0.0, 1, 1.0) * clamp(diff,0.3,1.0); }";
		src += "</fragment>";
		src += "</shader>";
		m_error = new Shader(src);
		m_error.name = "haxor/$Error";
		return m_error;
	}
	
	/**
	 * 
	 */
	static public var texture(get_texture, never) : Shader;
	static var m_texture : Shader;		
	static function get_texture():Shader
	{
		if (m_texture != null) return m_texture;
		m_texture = cast Asset.Get("haxor/internal/Texture");
		if (m_texture != null) return m_texture;
		var src:String = "";		
		src += "<shader id='haxor/internal/Texture'>";
		src += "<vertex>";
		src += "attribute vec3 vertex;";
		src += "attribute vec3 uv0;";
		src += "varying vec3 _uv0;";
		src += "void main(void) { gl_Position = vec4(vertex,1.0); _uv0 = uv0; }";
		src += "</vertex>";
		src += "<fragment>";
		src += "precision mediump float;";	
		src += "uniform sampler2D  Texture;";
		src += "varying vec3 _uv0;";
		src += "void main(void) { gl_FragColor = texture2D(Texture, _uv0.xy); }";
		src += "</fragment>";
		src += "</shader>";
		m_texture = new Shader(src);
		m_texture.name = "haxor/$Texture";
		return m_texture;
	}
	
	/**
	 * 
	 */
	static public var blit(get_blit, never) : Shader;
	static var m_blit : Shader;		
	static function get_blit():Shader
	{
		if (m_blit != null) return m_blit;
		m_blit = cast Asset.Get("haxor/internal/Blit");
		if (m_blit != null) return m_blit;
		var src:String = "";		
		src += "<shader id='haxor/internal/Blit'>";
		src += "<vertex>";
		src += "attribute vec3 vertex;";		
		src += "varying vec2 uv;";
		src += "void main(void) { gl_Position = vec4(vertex,1.0); uv = vec2((vertex.x+1.0)*0.5,(vertex.y+1.0)*0.5); }";
		src += "</vertex>";
		src += "<fragment>";
		src += "precision lowp float;";	
		src += "uniform sampler2D  Texture;";
		src += "varying vec2 uv;";
		src += "void main(void) { gl_FragColor = texture2D(Texture, uv.xy); }";
		src += "</fragment>";
		src += "</shader>";
		m_blit = new Shader(src);
		m_blit.name = "haxor/internal/Blit";
		return m_blit;
	}
		
	
	/**
	 * 
	 */
	static public var skybox(get_skybox, never) : Shader;
	static var m_skybox : Shader;		
	static function get_skybox():Shader
	{
		if (m_skybox != null) return m_skybox;
		m_skybox = cast Asset.Get("haxor/internal/Skybox");
		if (m_skybox != null) return m_skybox;
		var src:String = "";		
		src += "<shader id='haxor/internal/Skybox'>";
		src += "<vertex>";
		src += "precision mediump float;";
		src += "uniform mat4 ViewMatrixInverse;";
		src += "uniform mat4 SkyboxProjectionMatrixInverse;";
		src += "uniform vec3 WSCameraPosition;";
		src += "varying vec3 WSView;";
		src += "attribute vec3 vertex;";
		src += "void main()";
		src += "{";
		src += "	vec4 v = vec4(vertex,1.0);";
		src += "	vec4 ws_vertex = v * SkyboxProjectionMatrixInverse;";
		src += "	ws_vertex /= ws_vertex.w;";
		src += "	ws_vertex = ws_vertex * ViewMatrixInverse;";
		src += "	WSView = ws_vertex.xyz - WSCameraPosition;";      		
		src += "	gl_Position = v;";
		src += "}";
		src += "</vertex>";
		src += "<fragment>";
		src += "precision mediump float;";
		src += "uniform samplerCube  SkyboxTexture;";
		src += "varying vec3 WSView;";
		src += "void main() { gl_FragColor = textureCube(SkyboxTexture,normalize(WSView)); }";
		src += "</fragment>";
		src += "</shader>";
		m_skybox = new Shader(src);
		m_skybox.name = "haxor/internal/Skybox";
		return m_skybox;
	}
	
	
	
	/**
	 * 
	 * @param	p_path
	 * @return
	 */
	static public function FromFile(p_path:String) : Shader
	{	
		var loader : XMLHttpRequest = new XMLHttpRequest();
		loader.open("GET", p_path, false);
		loader.send(null);
		return (loader.status == 200) ? new Shader(loader.responseText) : null;
	}
	
	/**
	 * 
	 * @param	p_id
	 * @return
	 */
	static public function FromHTML(p_id:String):Shader
	{
		var e : Element = Browser.document.getElementById(p_id);	
		var src:String = e.innerText;	
		var shd:Shader = new Shader(src);		
		return shd;
	}

	private var m_vertexShaderSource:String;
	
	private var m_vertexShaderId : js.html.webgl.Shader;
	
	private var m_fragmentShaderSource:String;
	
	private var m_fragmentShaderId : js.html.webgl.Shader;
	
	/**
	 * 
	 */
	public var hasError(get_hasError, never) : Bool;
	var m_hasError : Bool;
	function get_hasError():Bool { return m_hasError; }
	
	/**
	 * 
	 */
	public var gid(get_gid, never):Program;
	private function get_gid():Program { return m_gid; }
	private var m_gid : Program;
	
	private var m_locations : Map<String,Int>;
	
	public function new(p_source:String) 
	{
		super();
		
		m_locations = new Map<String,Int>();
		
		
		
		var vt0 : Int = p_source.indexOf("<vertex");
		var vt1 : Int = p_source.indexOf(">", vt0 + 1);
		var vt  : String = p_source.substring(vt0, vt1+1);
		var ft0 : Int = p_source.indexOf("<fragment");
		var ft1 : Int = p_source.indexOf(">", ft0 + 1);
		var ft  : String = p_source.substring(ft0, ft1 + 1);
		
		p_source = StringTools.replace(p_source, vt, vt+"<![CDATA[");
		p_source = StringTools.replace(p_source, "</vertex>", "]]></vertex>");
		p_source = StringTools.replace(p_source, ft, ft+"<![CDATA[");
		p_source = StringTools.replace(p_source, "</fragment>", "]]></fragment>");		
		var shader:Xml = Xml.parse(p_source);
		shader = shader.firstElement();
		name = shader.get("id");
		if ((name == null) || (name == "")) name = "shader";
		
		
		
		if (shader.elementsNamed("lighting").hasNext())
		{
			
		}
		
		var vs : Xml = shader.elementsNamed("vertex").next();
		var fs : Xml = shader.elementsNamed("fragment").next();
		if (vs != null)
		{
			var src:String = vs.firstChild().nodeValue.toString();			
			var prec:String = (vs.get("precision") == null ? "medium" : vs.get("precision")).toLowerCase();
			switch(prec)
			{
				case "low":    prec = "precision lowp float;";
				case "medium": prec = "precision mediump float;";
				case "high":   prec = "precision highp float;";
			}
			m_vertexShaderSource = prec + src;
		}
		if (fs != null)
		{
			var src:String = fs.firstChild().nodeValue.toString();
			var prec:String = (fs.get("precision") == null ? "medium" : fs.get("precision")).toLowerCase();
			switch(prec)
			{
				case "low":    prec = "precision lowp float;";
				case "medium": prec = "precision mediump float;";
				case "high":   prec = "precision highp float;";
			}
			m_fragmentShaderSource = prec + src;
		}
		m_hasError = false;
		ShaderAPI.Create(this);
	}
	
	override public function OnDestroy():Void 
	{
		super.OnDestroy();
		ShaderAPI.Destroy(this);
	}
}