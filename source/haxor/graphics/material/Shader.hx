package haxor.graphics.material;
import haxor.context.EngineContext;
import haxor.context.ShaderContext;
import haxor.core.Resource;

/**
 * Class that holds the sources for Vertex and Fragment shaders.
 * @author Eduardo Pons
 */
@:allow(haxor)
class Shader extends Resource
{
	/**
	 * Returns a reference to the Flat shader (only vertex color and Tint).
	 */
	static public var Flat(get_Flat, null):Shader;
	static private inline function get_Flat():Shader { return (m_flat_shader == null ? (m_flat_shader = new Shader(ShaderContext.flat_source)) : m_flat_shader);	}
	static private var m_flat_shader : Shader;
	
	/**
	 * Returns a reference to the Flat shader (only vertex color and Tint).
	 */
	static public var FlatTexture(get_FlatTexture, null):Shader;
	static private inline function get_FlatTexture():Shader { return (m_flat_texture_shader == null ? (m_flat_texture_shader = new Shader(ShaderContext.flat_texture_source)) : m_flat_texture_shader);	}
	static private var m_flat_texture_shader : Shader;
	
	/**
	 * String containing the VertexShader source.
	 */
	private var m_vss:String;
	
	/**
	 * String containing the FragmentShader source.
	 */
	private var m_fss:String;
	
	/**
	 * Flag that indicates that this shader couldn't be compiled and has errors in it.
	 */
	public var hasError(get_hasError, never) : Bool;	
	private inline function get_hasError():Bool { return m_hasError; }
	private var m_hasError : Bool;
	
	/**
	 * Creates a new shader from a XML '.shader' file source.
	 * @param	p_source
	 */
	public function new(p_source:String) 
	{
		super();
		__cid 		= EngineContext.material.sid++;
		
		//Adjustments to correct malformed <vertex>/<fragment> tags
		//Must use RegExp :)
		var vt0 : Int 	 = p_source.indexOf("<vertex");
		var vt1 : Int 	 = p_source.indexOf(">", vt0 + 1);
		var vt  : String = p_source.substring(vt0, vt1+1);
		var ft0 : Int 	 = p_source.indexOf("<fragment");
		var ft1 : Int 	 = p_source.indexOf(">", ft0 + 1);
		var ft  : String = p_source.substring(ft0, ft1 + 1);
		
		//Adjustment in the text source to make it XML-valid.
		p_source = StringTools.replace(p_source, vt, vt+"<![CDATA[");
		p_source = StringTools.replace(p_source, "</vertex>", "]]></vertex>");
		p_source = StringTools.replace(p_source, ft, ft+"<![CDATA[");
		p_source = StringTools.replace(p_source, "</fragment>", "]]></fragment>");
		
		var x:Xml;
		
		x = Xml.parse(p_source);
		x = x.firstElement();
		
		name = x.get("id");
		
		if ((name == null) || (name == "")) name = "Shader"+__cid;
		
		var vs : Xml = x.elementsNamed("vertex").next();
		var fs : Xml = x.elementsNamed("fragment").next();
		
		m_vss = GetShaderSource(vs);
		m_fss = GetShaderSource(fs);		
		m_hasError = false;		
		
		EngineContext.material.InitializeShader(this);
	}
	
	/**
	 * Gets the Vertex or Fragment shader source from the XML node.
	 * @param	n
	 * @return
	 */
	private function GetShaderSource(n : Xml):String
	{
		if (n == null) return "";
		var src:String = n.firstChild().nodeValue.toString();
		var prec:String = (n.get("precision") == null ? "low" : n.get("precision")).toLowerCase();
		switch(prec)
		{
			case "low":    prec = "precision lowp float;";
			case "medium": prec = "precision mediump float;";
			case "high":   prec = "precision highp float;";
		}
		return prec + src;
	}
	
	/**
	 * Destroys the Shader data and GPU reference.
	 */
	override public function OnDestroy():Void 
	{
		EngineContext.material.DestroyShader(this);		
	}
}