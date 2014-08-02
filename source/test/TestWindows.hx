package test;

import haxor.api.windows.Application;
import haxor.api.BaseApplication;


/**
 * Example application for the Windows platform. It is created after the native window is created.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class TestWindows extends Application
{
	
	
	/**
	 * Load any resource your application might use and store it if necessary.
	 * If your loading process is asynchronous return false so the application can wait your command of LoadComplete()
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
		trace("TestWindows> Initialize");
	}
	
	
	
}
