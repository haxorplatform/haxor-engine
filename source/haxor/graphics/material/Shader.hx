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
	 * Returns a reference to the Flat shader with a single diffuse texture.
	 */
	static public var FlatTexture(get_FlatTexture, null):Shader;
	static private inline function get_FlatTexture():Shader { return (m_flat_texture_shader == null ? (m_flat_texture_shader = new Shader(ShaderContext.flat_texture_source)) : m_flat_texture_shader);	}
	static private var m_flat_texture_shader : Shader;
	
	/**
	 * Returns a reference to the Flat shader with a single diffuse texture and vertex skinning.
	 */
	static public var FlatTextureSkin(get_FlatTextureSkin, null):Shader;
	static private inline function get_FlatTextureSkin():Shader 
	{ 
		if (m_flat_texture_skin_shader != null) return m_flat_texture_skin_shader;		
		var shd : Shader = m_flat_texture_skin_shader = new Shader(ShaderContext.flat_texture_skin_source, false);
		shd.AddPreprocessor("#define", "MAX_BONES", GL.MAX_UNIFORM_BONES + "");
		if (GL.BONE_TEXTURE) shd.AddPreprocessor("#define", "BONE_TEXTURE");
		shd.Compile();
		return shd;
	}
	static private var m_flat_texture_skin_shader : Shader;
	
	/**
	 * Returns a reference to the Flat particle shader with 1 diffuse texture.
	 */
	static public var FlatParticle(get_FlatParticle, null):Shader;
	static private inline function get_FlatParticle():Shader { return (m_flat_particle_shader == null ? (m_flat_particle_shader = new Shader(ShaderContext.flat_particle_source)) : m_flat_particle_shader);	}
	static private var m_flat_particle_shader : Shader;
	
	/**
	 * Returns the resulting vertex shader.
	 */
	public var vs(get_vs, never):String;
	private function get_vs():String { return GetPreprocessorString() + m_vss; }		
	private var m_vss:String;
	
	/**
	 * Returns the resulting vertex shader.
	 */
	public var fs(get_fs, never):String;
	private function get_fs():String { return GetPreprocessorString() + m_fss; }
	private var m_fss:String;
	
	/**
	 * Flag that indicates that this shader couldn't be compiled and has errors in it.
	 */
	public var hasError(get_hasError, never) : Bool;	
	private inline function get_hasError():Bool { return m_hasError; }
	private var m_hasError : Bool;
	
	/**
	 * Error string if any.
	 */
	public var error : String;
	
	/**
	 * Preprocessor directives.
	 */
	private var m_pp : Map<String,String>;
	
	
	
	/**
	 * Creates a new shader from a XML '.shader' file source.
	 * @param	p_source
	 */
	public function new(p_source:String,p_compile:Bool=true) 
	{
		super();
		__cid 		= EngineContext.material.sid.id;
		m_pp 		= new Map<String,String>();	
		Load(p_source,p_compile);		
	}
	
	/**
	 * Loads the shader XML and store its data.
	 * @param	p_source
	 */
	public function Load(p_source:String,p_compile:Bool=true):Void
	{
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
		m_vss = GetShaderSource(vs,GL.VS_FLOAT_HIGHP);		
		m_fss = GetShaderSource(fs,GL.FS_FLOAT_HIGHP);
		m_hasError = false;
		error = "";
		
		if (p_compile) Compile();
	}
	
	/**
	 * Applies the shader source and compiles it.
	 */
	public function Compile():Void
	{
		EngineContext.material.CompileShader(this);
	}
	
	/**
	 * Adds a preprocessor directive.
	 * @param	p_type
	 * @param	p_name
	 * @param	p_value
	 */
	public function AddPreprocessor(p_type:String, p_name:String, p_value : String = ""):Void
	{
		m_pp.set(p_name, p_type+" " + p_name+" " + p_value);
	}
	
	/**
	 * Removes a preprocessor from the shader sources.
	 * @param	p_name
	 */
	public function RemovePreprocessor(p_name:String):Void
	{
		m_pp.remove(p_name);
	}
	
	/**
	 * Removes all preprocessor directives.
	 */
	public function ClearPreprocessor():Void
	{
		var it : Iterator<String> = m_pp.keys();
		while (it.hasNext()) m_pp.remove(it.next());
	}
	
	/**
	 * Tells if the given shader has preprocessor directive.
	 * @param	p_name
	 * @return
	 */
	public function HasPreprocessor(p_name:String):Bool { return m_pp.exists(p_name); }
	
	/**
	 * Returns the concatenated string of preprocessor directives.
	 * @return
	 */
	private function GetPreprocessorString():String
	{
		var it :Iterator<String> = m_pp.iterator();
		var s : String = "";
		while (it.hasNext()) s += it.next() + "\n";
		s += "\n";		
		return s;
	}
	
	/**
	 * Gets the Vertex or Fragment shader source from the XML node.
	 * @param	n
	 * @return
	 */
	private function GetShaderSource(n : Xml,hp :Bool):String
	{
		if (n == null) return "";
		var src : String = n.firstChild().nodeValue.toString();
		var prec: String = (n.get("precision") == null ? "low" : n.get("precision")).toLowerCase();		
		
		switch(prec)
		{
			case "low":    prec = "lowp";
			case "medium": prec = "mediump";
			case "high":   prec = hp ? "highp" : "mediump";
		}
		prec = "precision " + prec + " float;";
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