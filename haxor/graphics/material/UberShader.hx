package haxor.graphics.material;

/**
 * Shader class that simplifies the writing of GLSL shaders by encapsulating the core scripting thus allowing the user to focus in the shading part only.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class UberShader extends Shader
{

	
	/**
	 * Creates a new UberShader from a '.shader' source file.
	 * @param	p_source
	 */
	public function new(p_source : String) 
	{
		super(p_source);		
		//use m_vss and m_fss to combine it with predefined shader script to make it easier to the final user.
		
	}
	
}