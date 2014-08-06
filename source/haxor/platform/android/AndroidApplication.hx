#if android

package haxor.platform.android;
import haxor.platform.graphics.GL;
import haxor.core.BaseApplication;




/**
 * Class that defines a base Application for Android projects.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class AndroidApplication extends BaseApplication
{
	
	private var m_entry : Entry;

	
	/**
	 * Creates a new ApplicationWindows.
	 */
	public function new() 
	{
		super();		
		m_platform = Platform.Android;
		
	}
	
	override function OnFocus():Void 
	{		
		GL.m_gl.OnResume();
	}
	
	override function OnUnfocus():Void 
	{
		GL.m_gl.OnPause();
	}
	
		
}

#end