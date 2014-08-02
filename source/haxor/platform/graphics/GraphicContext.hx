package haxor.platform.graphics;
import haxor.core.BaseApplication;


/**
 * API Enumeration
 */
enum GraphicAPI
{	
	None;
	OpenGL;
	OpenGLES;
	DirectX;
	WebGL;
}

/**
 * Base class that describes a Graphics Rendering context with common graphic operations.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class GraphicContext
{
	
	/**
	 * Flag that indicates the running API of the graphic context.
	 */
	public var api : GraphicAPI;	
	private function get_api():GraphicAPI { return m_api; }
	private var m_api : GraphicAPI;

	/**
	 * Reference to the application that contains this context.
	 */
	private var m_application : BaseApplication;
	
	/**
	 * Creates a new GraphicContext.
	 */
	public function new(p_application : BaseApplication) 
	{
		m_api 			= GraphicAPI.None;
		m_application 	= p_application;
	}
		
	/**
	 * Callback to treat extensions case by case.
	 */
	public function CheckExtensions():Void { }
	
	/**
	 * Activates the context
	 */
	public function Focus():Void { }
	
	/**
	 * Executes the rendering commands.
	 */
	public function Flush():Void { }
	
	/**
	 * Destroys the context.
	 */
	public function Destroy():Void { }
	
	/**
	 * Callback called when the application container changed size.
	 */
	public function Resize():Void { }
	
	/**
	 * Clear the screen buffer with the chosen color.
	 * @param	p_r
	 * @param	p_g
	 * @param	p_b
	 * @param	p_a
	 */
	public function Clear(p_r : Float, p_g:Float, p_b:Float, p_a:Float = 1.0,p_depth:Float=1.0):Void { 	}
	
}