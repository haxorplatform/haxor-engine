package haxor.graphics.material.shader;
import haxor.core.Asset;
import haxor.core.Enums.ShaderPrecision;
import haxor.graphics.material.Shader;

/**
 * Base Shader class to derive more specialized shaders. After creation the shader is added to the Asset database.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class TemplateShader extends Shader
{
	
	/**
	 * Bit flags of precision for both vertex and fragment shaders.
	 */
	public var precision(get_precision, set_precision):Int;
	private function get_precision():Int { return m_precision; }
	private function set_precision(v:Int):Int { m_precision = v; return v; }
	private var m_precision : Int;
		
	/**
	 * Creates a template shader with a id and separated data.
	 * @param	p_id
	 * @param	p_precision
	 * @param	p_compile	 
	 */
	private function new(p_id : String,p_precision : Int = ShaderPrecision.VertexLow | ShaderPrecision.FragmentLow ,p_compile:Bool=true) 
	{		
		m_precision = p_precision;
		name = p_id;
		Asset.Add(p_id, this);
		super(Generate(), p_compile);
	}
	
	
	/**
	 * Compiles this shader generating a new source for the given flags.
	 */
	override public function Compile():Void 
	{
		var src : String = Generate();
		Load(src,false);
		super.Compile();
	}
	
	/**
	 * Generates the XML with the shaders content and precision.
	 * @param	p_vs
	 * @param	p_fs
	 * @param	p_vsp
	 * @param	p_fsp
	 * @return
	 */
	private function Generate():String
	{
		var vsp : String = "low";
		var fsp : String = "low";
		if ((m_precision & ShaderPrecision.VertexMed)  != 0) vsp = "medium"; else		
		if ((m_precision & ShaderPrecision.VertexHigh) != 0) vsp = "high";
		if ((m_precision & ShaderPrecision.FragmentMed)  != 0) fsp = "medium"; else		
		if ((m_precision & ShaderPrecision.FragmentHigh) != 0) fsp = "high";		
		var src : String = template;		
		src = StringTools.replace(src, "@ID",  name);
		src = StringTools.replace(src, "@VSP", vsp);
		src = StringTools.replace(src, "@FSP", fsp);
		src = StringTools.replace(src, "@VS", GetVS());
		src = StringTools.replace(src, "@FS", GetFS());
		return src;
	}
	
	/**
	 * Returns the Vertex Shader source.
	 * @return
	 */
	private function GetVS():String { return ""; }
	
	/**
	 * Returns the Fragment Shader source.
	 * @return
	 */
	private function GetFS():String { return ""; }
	
	/**
	 * XML Template.
	 */
	static private var template : String = 
	'
	<shader id="@ID">	
		<vertex precision="@VSP">		
			@VS
		</vertex>		
		<fragment precision="@FSP">			
			@FS
		</fragment>	
	</shader>	
	';
	
}