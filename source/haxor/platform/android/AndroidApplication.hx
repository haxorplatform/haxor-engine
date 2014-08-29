#if android

package haxor.platform.android;
import haxor.graphics.GL;
import haxor.core.BaseApplication;




/**
 * Class that defines a base Application for Android projects.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class AndroidApplication extends BaseApplication
{

	/**
	 * Reference to the Entry point.
	 */
	private var m_entry : Entry;
	
	/**
	 * Device screen width.
	 */
	private var m_screen_width : Float;
	
	/**
	 * Device screen width.
	 */
	private var m_screen_height : Float;
	
	override function OnBuild():Void 
	{
		m_platform = Platform.Android;
		m_screen_width = 0.0;
		m_screen_height = 0.0;
		super.OnBuild();		
	}
	
	/**
	 * See BaseApplication.
	 * @return
	 */
	override function GetContainerWidth():Float  { return m_screen_width; }
	
	/**
	 * See BaseApplication.
	 * @return
	 */
	override function GetContainerHeight():Float { return m_screen_height; }
	
	
	/**
	 * Callback when application gained focus.
	 */
	override function OnFocus():Void 
	{		
		GL.m_gl.OnResume();
	}
	
	/**
	 * Callback called when the application lost focus.
	 */
	override function OnUnfocus():Void 
	{
		GL.m_gl.OnPause();
	}
	
		
}

#end