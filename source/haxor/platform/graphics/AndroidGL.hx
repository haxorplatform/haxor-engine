#if android
package haxor.platform.graphics;
import haxor.io.FloatArray;
import haxor.io.Int32Array;
import haxor.io.UInt16Array;

import java.NativeArray;
import haxor.platform.Types.MeshBufferId;
import haxor.platform.android.Entry;
import haxor.core.Console;
import haxor.platform.graphics.GraphicContext.GraphicAPI;
import haxor.core.BaseApplication;
import android.app.Activity;
import android.opengl.GLES20;
import android.opengl.GLSurfaceView;


/**
 * Wrapper for all Android GLES API commands and context management.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class AndroidGL extends GraphicContext
{	
	private var c : GLSurfaceView;
	
	private var m_ids : NativeArray<Int>;
	
	/**
	 * Creates a new Android GLES context.
	 * @param	p_application
	 */
	override public function new(p_application : BaseApplication):Void
	{
		super(p_application);
		api = GraphicAPI.OpenGLES;
	}
	
	/**
	 * Initializes the GLES context passing its setup attributes.
	 * @param	p_application
	 * @param	p_canvas
	 * @param	p_alpha
	 * @param	p_depth
	 * @param	p_antialias
	 * @param	p_stencil
	 * @param	p_premultipliedAlpha
	 * @param	p_preserveDrawingBuffer
	 * @return
	 */
	public function Initialize(p_entry : Entry,p_version:Int=2):Bool
	{
		if (p_entry == null) { Console.Log("Graphics> Invalid Entry Activity."); return false; }
				
		var cv : Int = p_version;
		untyped __java__('
		 c = new android.opengl.GLSurfaceView(p_entry.getApplication());
		 ');
		
		
		 
		if (c == null) { Console.Log("Graphics> Could not create GLSurfaceView."); return false; }
		
		var w:Int=0;
		var h:Int=0;
		
		untyped __java__('
		c.setEGLContextClientVersion(cv);
		c.setRenderer(p_entry);		
		p_entry.setContentView(c);		
		
		android.view.Display display = p_entry.getWindowManager().getDefaultDisplay();
		
		android.util.DisplayMetrics metrics = new android.util.DisplayMetrics();
		display.getMetrics(metrics);

		w = metrics.widthPixels;
		h = metrics.heightPixels;
		
		');
		
		m_ids = new NativeArray<Int>(1);
		
		Console.Log("Graphics> Initialize Android GLES version["+p_version+"] Resolution["+w+","+h+"]",1);
		
		return true;
	}
	
	/**
	 * Callback for OnPause
	 */
	function OnPause():Void { untyped __java__ ('c.onPause()'); }
	
	/**
	 * Callback for OnResume
	 */
	function OnResume():Void { untyped __java__ ('c.onResume()'); }
	
	/**
	 * See GraphicsContext.
	 */
	override public function CheckExtensions():Void 
	{
		if (c == null) return;		
		Console.Log("Graphics> Available Extensions.",1);
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
		GLES20.glClearDepthf(p_depth);
		GLES20.glClearColor(p_r, p_g, p_b, p_a);
		GLES20.glClear(GLES20.GL_COLOR_BUFFER_BIT | GLES20.GL_DEPTH_BUFFER_BIT);
	}
	
	/**
	 * See GraphicsContext.
	 * @return
	 */
	override public function CreateBuffer():MeshBufferId 
	{	
		GLES20.glGenBuffers(1,m_ids,0);
		return m_ids[0];		
	}
	
	/**
	 * See GraphicsContext.
	 * @param	p_id
	 */
	override public function DeleteBuffer(p_id:MeshBufferId):Void 
	{
		m_ids[0] = p_id;
		GLES20.glDeleteBuffers(1,m_ids, 0);
	}
	
}
#end