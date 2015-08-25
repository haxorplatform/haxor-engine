package haxor.graphics.material;
import haxor.context.EngineContext;
import haxor.context.ShaderContext;
import haxor.core.Enums.ShaderFeature;
import haxor.core.Enums.ShaderPrecision;
import haxor.core.Resource;
import haxor.graphics.material.shader.FlexShader;
import haxor.graphics.material.Shader.ShaderCompilation;
import haxor.graphics.material.Shader.ShaderCompileResult;

/**
 * Class that holds the sources for Vertex and Fragment shaders.
 * @author Eduardo Pons
 */
@:allow(haxor)
class Shader extends Resource
{
	/**
	 * List of all shaders.
	 */
	static public var list : Array<Shader> = [];
	
	/**
	 * Global shader precision (will override all shaders).
	 */
	static public var globalPrecision(get, set) : Int;
	static private function get_globalPrecision():Int {  return m_global_precision; }
	static private function set_globalPrecision(v:Int):Int {  m_global_precision = v; for (s in list) s.Compile(); return v; }
	static private var m_global_precision : Int = ShaderPrecision.None;
	
	/**
	 * Global preprocessor (will be added before individual preprocessors).
	 */
	static public var globalPreprocessor(get, set) : String;
	static private function get_globalPreprocessor():String {  return m_global_preprocessor; }
	static private function set_globalPreprocessor(v:String):String {  m_global_preprocessor = v; for (s in list) s.Compile(); return v; }
	static private var m_global_preprocessor : String = "";
	
	/**
	 * Generates a new Flat shader.
	 */
	static public var Flat(get_Flat, null):Shader;
	static private inline function get_Flat():Shader 
	{ 
		if (m_flat_shader != null) return m_flat_shader;
		var shd : Shader = m_flat_shader = new Shader(ShaderContext.vs_flat, ShaderContext.fs_flat);
		shd.name = "Flat";
		shd.guid = "9a58ee0f9a784909addc215a";				   
		return shd;
	}
	static private var m_flat_shader : Shader;
	
	/**
	 * Generates a new Flat shader with a DiffuseTexture.
	 */
	static public var FlatTexture(get_FlatTexture, null):Shader;
	static private inline function get_FlatTexture():Shader 
	{ 
		if (m_flat_texture_shader != null) return m_flat_texture_shader;
		var shd : Shader = m_flat_texture_shader = new Shader(ShaderContext.vs_flat_texture, ShaderContext.fs_flat_texture);
		shd.name = "FlatTexture";
		shd.guid = "2a501691270e420b8b894f2a";				   
		return shd;
	}
	static private var m_flat_texture_shader : Shader;
	
	/**
	 * Generates a new Skinned Flat shader with a DiffuseTexture.
	 */
	static public var FlatTextureSkin(get_FlatTextureSkin, null):Shader;
	static private inline function get_FlatTextureSkin():Shader 
	{ 
		if (m_flat_texture_skin_shader != null) return m_flat_texture_skin_shader;		
		var shd : Shader = m_flat_texture_skin_shader = new Shader();
		shd.name = "FlatTextureSkin";
		shd.guid = "9ff884fd32ae4e9fa023defa";
		shd.vertex 	 = ShaderContext.vs_flat_skin_texture;
		shd.fragment = ShaderContext.fs_flat_skin_texture;
		shd.preprocessor += "#define MAX_BONES " + GL.MAX_UNIFORM_BONES + "\n";
		if (GL.BONE_TEXTURE) shd.preprocessor += "#define BONE_TEXTURE\n";		
		shd.Compile();
		return shd;
	}
	static private var m_flat_texture_skin_shader : Shader;
	
	/**
	 * Generates a new Flat shader for particles.	 
	 */
	static public var FlatParticle(get_FlatParticle, null):Shader;
	static private inline function get_FlatParticle():Shader 
	{ 
		if (m_flat_particle_shader != null) return m_flat_particle_shader;		
		var shd : Shader = m_flat_particle_shader = new Shader(ShaderContext.vs_flat_particle, ShaderContext.fs_flat_particle);
		shd.name = "FlatParticle";
		shd.guid = "3cdfaa96235342a82a670cda";				   
		return shd;		
	}
	static private var m_flat_particle_shader : Shader;
	
	
	/**
	 * Vertex shader source.
	 */
	@serialize
	public var vertex:String;
	
	/**
	 * Fragment shader source.
	 */
	@serialize
	public var fragment:String;
	
	/**
	 * Preprocessor directives. 
	 */
	@serialize
	public var preprocessor : String;
	
	/**
	 * Bit flag that tells the precision level of the shaders.
	 */
	@serialize
	public var precision:Int;
	
	/**
	 * Flag that indicates that this shader couldn't be compiled and has errors in it.
	 */
	public var hasError(get, never) : Bool;	
	private function get_hasError():Bool { if (compilation == null) return false; return !compilation.success; }
	
	/**
	 * Error string if any.
	 */
	public var compilation : ShaderCompileResult;
	
	/**
	 * Creates a new shader from a XML '.shader' file source.
	 * @param	p_source
	 */
	public function new(p_vs:String="",p_fs:String="") 
	{
		super();
		__cid 		 = EngineContext.material.sid.id;
		vertex		 = p_vs;
		fragment	 = p_fs;
		preprocessor = "";
		compilation  = new ShaderCompileResult();
		precision    = ShaderPrecision.FragmentMed | ShaderPrecision.VertexMed;				
		list.push(this);
		if (p_vs != "") if (p_fs != "") Compile();
	}
		
	/**
	 * Applies the shader source and compiles it.
	 */
	public function Compile():ShaderCompileResult
	{
		return compilation = EngineContext.material.CompileShader(this);
	}
		
	/**
	 * Destroys the Shader data and GPU reference.
	 */
	override public function OnDestroy():Void 
	{
		list.remove(this);
		EngineContext.material.DestroyShader(this);		
	}
}

/**
 * Class that describes a shader compilation error.
 */
class ShaderError
{
	public var message: String;
	public var line : Int;
	public var text : String;
	public function new() { message = ""; line = 0; text = ""; }	
}

/**
 * Class that describes the result of compilation of a shader.
 */
class ShaderCompilation
{
	public var source : String;
	public var offset : Int;
	public var errors : Array<ShaderError>;
	public var success(get, never):Bool;
	private function get_success():Bool { return errors.length <= 0; }
	public function new() { source = ""; offset = 0; errors = []; }
	
	public function ErrorString():String
	{
		var s : String = "";
		for (e in errors) s += e.message+"\n";
		return s;
	}
	
}

/**
 * Class that describes the compilation of a Shader class.
 */
class ShaderCompileResult
{
	public var vertex   : ShaderCompilation;
	public var fragment : ShaderCompilation;
	public var success(get, never):Bool;
	private function get_success():Bool { return vertex.success&&fragment.success; }
	public function new() { vertex = new ShaderCompilation(); fragment = new ShaderCompilation(); }
	public function ErrorString():String
	{
		var s : String = "";
		var e : String;
		e = vertex.ErrorString();   if (e != "") s += "=== [vertex shader] ===\n" + e;
		e = fragment.ErrorString(); if (e != "") s += "=== [fragment shader] ===\n" + e;		
		return s;
	}
}