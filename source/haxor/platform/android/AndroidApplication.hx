#if android

package haxor.platform.android;
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
		graphics.OnResume();
	}
	
	override function OnUnfocus():Void 
	{
		graphics.OnPause();
	}
	
		
}

#end