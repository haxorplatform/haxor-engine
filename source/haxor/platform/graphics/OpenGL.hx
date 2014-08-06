#if (windows || osx || linux)
package haxor.platform.graphics;
import haxor.platform.Types.MeshBufferId;
import haxor.core.Time;
import haxor.core.Console;
import haxor.platform.graphics.GraphicContext;
import haxor.platform.OSWindow;
import haxor.core.BaseApplication;

/**
 * Wrapper for OpenGL API commands and context management.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class OpenGL extends

#if windows
WinGL
#end

{	
	
	
	/**
	 * Creates a new OpenGL context.
	 * @param	p_application
	 */
	override public function new(p_application : BaseApplication):Void
	{
		super(p_application);
		api = GraphicAPI.OpenGL;
	}
	
	/**
	 * See GraphicsContext.
	 * @param	p_r
	 * @param	p_g
	 * @param	p_b
	 * @param	p_a
	 * @param	p_depth
	 */
	override public function Clear(p_r:Float, p_g:Float, p_b:Float, p_a:Float, p_depth:Float):Void 
	{	
		untyped __cpp__('
		glClearDepth(p_depth); 
		glClearColor(p_r, p_g, p_b, p_a); 						
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		');
	}
	
	/**
	 * See GraphicsContext.
	 * @return
	 */
	override public function CreateBuffer():MeshBufferId 
	{	
		untyped __cpp__('
		GLuint id;
		glGenBuffers(1, &id);
		return (Int) id;
		');
		return GL.NULL_ID;
	}
	
	/**
	 * See GraphicsContext.
	 * @param	p_id
	 */
	override public function DeleteBuffer(p_id:MeshBufferId):Void 
	{
		untyped __cpp__('
		GLuint id = p_id;
		glDeleteBuffers(1, &id);		
		');		
	}
}



#end