package test;
import haxor.api.BaseApplication;
import haxor.api.android.Application;
import haxor.api.Console;


/**
 * Example application for the Android platform. Every [hx] found will generate a instance of this application.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class TestAndroid extends Application
{
	
	
	/**
	 * Load any resource your application might use and store it.
	 * If your loading process needs to download from the web, return false so the application can wait your command of LoadComplete()
	 * @return
	 */
	override public function Load():Bool 
	{
		
		var is_async : Bool = false;
		
		return !is_async;
	}
	
	/**
	 * Main entry point of your application. This method is called after your application invokes the LoadComplete callback.
	 */
	override public function Initialize():Void 
	{
		Console.Log("TestAndroid> Initialize");
	}
	
	var c : Float;
	var e : Float=0;
	var f :Int=0;
	
	override function OnUpdate():Void 
	{
		var dt : Float = clock - c;
		c = clock;
		e+= dt;
		if (e > 1.0)
		{
			e = 0.0;
			Console.Log("update " + f);
			f = 0;
		}
		f++;
	}
	
	override function OnRender():Void 
	{	
		
	}
}
