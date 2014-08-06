package haxor.platform.graphics;
import haxor.core.BaseApplication;
import haxor.platform.Types.MeshBufferId;

#if html
typedef PlatformGL  = WebGL;
#end

#if android
 typedef PlatformGL = AndroidGL;
#end

#if windows
typedef PlatformGL  =  OpenGL;
#end


/**
 * ...
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class GL
{
	
	#if html
	static private var NULL_ID : Dynamic = null;
	#else		
	static private var NULL_ID : Int = -1;
	#end
	
	/**
	 * Reference to the GL for the choosen platform.
	 */
	static private var m_gl : PlatformGL;
	
	/**
	 * Initializes the lowlevel graphic library.
	 * @param	p_application
	 */
	static function Initialize(p_application : BaseApplication):Void
	{
		m_gl = new PlatformGL(p_application);		
		m_gl.CheckExtensions();
	}
	
	/**
	 * Resizes the internall structures (e.g. canvas resize in html)
	 */
	static inline function Resize():Void {	m_gl.Resize(); }
	
	/**
	 * Clears the current buffer with the chosen color and depth.
	 * @param	p_r
	 * @param	p_g
	 * @param	p_b
	 * @param	p_a
	 * @param	p_depth
	 */
	static public inline function Clear(p_r:Float, p_g:Float, p_b:Float, p_a:Float, p_depth:Float):Void { m_gl.Clear(p_r, p_g, p_b, p_a, p_depth);	}
	
	/**
	 * Creates a buffer identifier.
	 * @param	p_id
	 */
	static public function CreateBuffer():MeshBufferId { return m_gl.CreateBuffer(); }
	
	/**
	 * Removes a mesh attribute buffer from GPU memory.
	 * @param	p_id
	 */
	static public inline function DeleteBuffer(p_id : MeshBufferId):Void { m_gl.DeleteBuffer(p_id); }
	
	/**
	 * Executes all queued commands and clean the command buffer.
	 */
	static public inline function Flush():Void { m_gl.Flush(); }
	
	/**
	 * Makes the graphics context active (e.g. on windows)
	 */
	static public inline function Focus():Void { m_gl.Focus(); }
	
	
}