package haxor.platform.graphics;
import haxor.core.BaseApplication;
import haxor.platform.Types.MeshBufferId;


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
	 * Creates a buffer in the GPU and returns its identifier.
	 * @return
	 */
	public function CreateBuffer():MeshBufferId { return GL.NULL_ID; }
	
	/**
	 * Deletes a buffer from the GPU
	 * @param	p_id
	 */
	public function DeleteBuffer(p_id : MeshBufferId):Void { }
	
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
	public function Clear(p_r : Float, p_g:Float, p_b:Float, p_a:Float,p_depth:Float):Void { 	}
	
}