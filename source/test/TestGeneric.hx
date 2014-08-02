package test;

import haxor.api.BaseApplication;

#if js
import haxor.api.html.Application;
import js.html.Element;
import js.html.EventTarget;
import js.html.Image;
import js.html.XMLHttpRequest;
#end

#if cpp
import haxor.api.windows.Application;
#end

#if java
import haxor.api.android.Application;
#end

/**
 * Example application for the any platform.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class TestGeneric extends Application
{
	
	
	/**
	 * Load any resource your application might use and store it.
	 * If your loading process needs to download from the web, return false so the application can wait your command of LoadComplete()
	 * @return
	 */
	override public function Load():Bool 
	{
		var is_async : Bool = false;
		
		trace("TestGeneric> Load");
		
		return !is_async;
	}
	
	/**
	 * Main entry point of your application. This method is called after your application invokes the LoadComplete callback.
	 */
	override public function Initialize():Void 
	{
		trace("TestGeneric> Initialize");
	}
	
	override function OnRender():Void 
	{		
		graphics.Clear(1.0, 0.0, 1.0);
	}
	
		
}
