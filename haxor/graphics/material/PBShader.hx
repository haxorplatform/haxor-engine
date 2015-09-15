package haxor.graphics.material;
import haxor.context.ShaderContext;
import haxor.graphics.material.Shader;

/**
 * Class that implements an extension of the default shader to handle Physically Based Shading.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class PBShader extends Shader
{	
	/**
	 * Flag tha indicates the use of normal textures.
	 */
	@serialize
	public var normal(get, set):Bool;
	private function get_normal():Bool  { return m_normal; }
	private function set_normal(v:Bool) { if (m_normal != v) { m_normal = v; Generate(); } return v; }
	private var m_normal:Bool;
	
	/**
	 * Flag tha indicates the use of extra textures like detail.
	 */
	@serialize
	public var secondary(get, set):Bool;
	private function get_secondary():Bool  { return m_secondary; }
	private function set_secondary(v:Bool) { if (m_secondary != v) { m_secondary = v; Generate(); } return v; }
	private var m_secondary:Bool;
	
	/**
	 * Flag tha indicates the use of the global skybox of the main camera.
	 */
	@serialize
	public var global(get, set):Bool;
	private function get_global():Bool  { return m_global; }
	private function set_global(v:Bool) { if (m_global != v) { m_global = v; Generate(); } return v; }
	private var m_global:Bool;
	
	/**
	 * Flag tha indicates the use of a Specular Texture and Controls.
	 */
	@serialize
	public var specular(get, set):Bool;
	private function get_specular():Bool  { return m_specular; }
	private function set_specular(v:Bool) { if (m_specular != v) { m_specular = v; Generate(); } return v; }
	private var m_specular:Bool;
	
	/**
	 * Flag tha indicates the use of a Occlusion Texture and Controls.
	 */
	@serialize
	public var occlusion(get, set):Bool;
	private function get_occlusion():Bool  { return m_occlusion; }
	private function set_occlusion(v:Bool) { if (m_occlusion != v) { m_occlusion = v; Generate(); } return v; }
	private var m_occlusion:Bool;
	
	/**
	 * Flag tha indicates the use of a Emission Texture and Controls.
	 */
	@serialize
	public var emission(get, set):Bool;
	private function get_emission():Bool  { return m_emission; }
	private function set_emission(v:Bool) { if (m_emission != v) { m_emission = v; Generate(); } return v; }
	private var m_emission:Bool;
	
	/**
	 * CTOR
	 */
	public function new() 
	{	
		m_global 	 = true;
		m_normal 	 = false;
		m_secondary  = false;
		m_specular   = false;
		m_occlusion  = false;
		m_emission   = false;		
		preprocessor = "#define GLOBAL_SKYBOX \n";
		super(ShaderContext.vs_pbs, ShaderContext.fs_pbs);		
	}
	
	/**
	 * Generates the shader.
	 */
	private function Generate():Void
	{
		var defs : String = "";		
		if (m_normal) 	 	defs += "#define NORMAL_TEXTURE    \n";		
		if (m_secondary)  	defs += "#define SECONDARY_MAP     \n";		
		if (m_global) 	 	defs += "#define GLOBAL_SKYBOX     \n";		
		if (m_specular) 	defs += "#define SPECULAR_TEXTURE  \n";
		if (m_occlusion) 	defs += "#define OCCLUSION_TEXTURE \n";
		if (m_emission) 	defs += "#define EMISSION_TEXTURE  \n";		
		preprocessor = defs;
		Compile();
	}
	
}