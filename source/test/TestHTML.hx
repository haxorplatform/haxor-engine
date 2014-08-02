package test;
#if js
import haxor.api.BaseApplication;
import haxor.api.html.Application;
import js.html.Element;
import js.html.EventTarget;
import js.html.Image;
import js.html.XMLHttpRequest;

/**
 * Example application for the HTML platform. Every [hx] found will generate a instance of this application.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class TestHTML extends Application
{
	
	
	/**
	 * Load any resource your application might use and store it.
	 * If your loading process needs to download from the web, return false so the application can wait your command of LoadComplete()
	 * @return
	 */
	override public function Load():Bool 
	{
		return true;
		var is_async : Bool = true;
		
		var img : Image;
		
		var req : XMLHttpRequest;
		
		req = new XMLHttpRequest();
		req.open("get", "https://dl.dropboxusercontent.com/u/20655747/nutsy_alien.apk", true);					
		req.overrideMimeType("application/octet-stream"); 
		Listen("APK", req);
		req.send();
		
		req = new XMLHttpRequest();
		req.open("get", "https://dl.dropboxusercontent.com/u/20655747/haxor/resources/asset/dungeon/module0/asset.dae", true);							
		Listen("COLLADA", req);
		req.send();
		
		req = new XMLHttpRequest();
		req.open("get", "https://www.terra.com.br", true);							
		Listen("ERROR", req);
		req.send();
		
		return !is_async;
	}
	
	override public function OnDependenceComplete(p_id:String, p_target:EventTarget):Void 
	{
		trace("TestHTML> id["+element.id+"] Complete " + p_id+" "+p_target);
	}
	
	override public function OnDependenceProgress(p_id:String, p_target:EventTarget, p_progress:Float, p_total_progress:Float):Void 
	{
		trace("TestHTML> id["+element.id+"] Progress " + p_id + " " + p_progress + " " + p_total_progress);
	}
	
	override public function OnDependenceError(p_id:String, p_target:EventTarget):Void 
	{
		trace("TestHTML> id["+element.id+"] Error " + p_id);
	}
	
	/**
	 * Main entry point of your application. This method is called after your application invokes the LoadComplete callback.
	 */
	override public function Initialize():Void 
	{
		trace("TestHTML> Initialize id["+element.id+"]");
	}
	
}
#end