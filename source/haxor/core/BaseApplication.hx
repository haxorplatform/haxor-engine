package haxor.core;

import haxe.Timer;
import haxor.component.Behaviour;
import haxor.component.Component;
import haxor.graphics.Screen;
import haxor.graphics.GL;
import haxor.input.Input;
import haxor.platform.html.BrowserAgent;
import haxor.platform.Types.Float32;


#if html
typedef EntryPoint  = haxor.platform.html.Entry;
#end

#if android
 typedef EntryPoint = haxor.platform.android.Entry;
#end

#if windows
typedef EntryPoint  =  haxor.platform.windows.Entry;
#end


/**
 * Flag that indicates the platform this application is running.
 */
enum Platform
{
	Unknown;
	Windows;
	Linux;
	Android;
	MacOS;
	iOS;
	HTML;
	NodeJS;
}

/**
 * Protocol enumeration for HTML applications.
 */
enum ApplicationProtocol
{
	None;
	File;
	HTTP;
	HTTPS;
}

/**
 * Base class that describes an Application running in the choson platform.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class BaseApplication extends Behaviour
{	
	/**
	 * Reference to the created application instance.
	 */
	static private var m_instance : BaseApplication;

	/**
	 * HTML protocol passed in HTML builds.
	 */
	public var protocol(get_protocol, never) : ApplicationProtocol;
	private function get_protocol():ApplicationProtocol	 
	{
		#if html
		if (js.Browser.window.location.protocol.toLowerCase() == "file:")  return ApplicationProtocol.File;
		if (js.Browser.window.location.protocol.toLowerCase() == "http:")  return ApplicationProtocol.HTTP;
		if (js.Browser.window.location.protocol.toLowerCase() == "https:") return ApplicationProtocol.HTTPS;		
		#end
		return ApplicationProtocol.None;
	}
	
	/**
	 * Browser vendor for HTML builds.
	 */
	public var vendor(get_vendor, never) : String;	
	private function get_vendor():String	 
	{		
		if (m_vendor != null) return m_vendor;
		#if html
		var vdr : String = "";
		untyped __js__("if(window.msRequestAnimationFrame 		!= null) vdr = \"-ms-\"");
		untyped __js__("if(window.oRequestAnimationFrame 		!= null) vdr = \"-o-\"");
		untyped __js__("if(window.webkitRequestAnimationFrame 	!= null) vdr = \"-webkit-\"");
		untyped __js__("if(window.mozRequestAnimationFrame 		!= null) vdr = \"-moz-\"");
		return m_vendor = vdr;
		#end
		return m_vendor = "";		
	}
	private var m_vendor : String;
	
	/**
	 * Framerate of the rendering callbacks.
	 */
	public var fps(get_fps,set_fps) : Int;
	private inline function get_fps():Int { return m_fps; }
	private function set_fps(v:Int):Int 
	{
		m_fps = v;
		var f : Float32 = cast v;		
		
		//clock precision adjustment for html/android platform. if bigger than 60fps don't need to control time.		
		#if (html||android)
		if (f >= 60.0) f = 1000000.0;
		#end
		
		#if windows
		f += 5.0;
		#end
		
		#if (android)
		f *= 1.35;
		#end
		
		#if html
		f *= 1.25;
		#end
		
		m_mspf = (((1.0 / f) * 1000.0));				
		return v; 
	}	
	/**
	 * Milliseconds per frame.
	 */
	private var m_mspf : Float32;
	
	/**
	 * Frames per second.
	 */
	private var m_fps  : Int;
	
	/**
	 * Time to next frame;
	 */
	private var m_frame_ms : Float32;
	
	/**
	 * Platform this application is currently running.
	 */
	public var platform(get_platform, null):Platform;
	private function get_platform():Platform { return Platform.Unknown; }
	
	
	/**
	 * Flag that indicates if the platform running the application is mobile.
	 */
	public var mobile(get_mobile, null):Bool;
	private function get_mobile():Bool
	{
		switch(platform)
		{
			case Platform.iOS:
			case Platform.Android: return true;
			
			case Platform.Unknown:
			case Platform.NodeJS:
			case Platform.Windows:
			case Platform.Linux:
			case Platform.MacOS: return false;
			
			case Platform.HTML:
			return browser.mobile;
			
		}
		return false;
	}
	
	/**
	 * Reference to the browser agent being used (HTML-only).
	 */
	public var browser(get_browser, never):BrowserAgent;
	private function get_browser():BrowserAgent	{ return m_browser;	}
	private var m_browser : BrowserAgent;
	
	/**
	 * Flag that indicates if the application must run on the window's focus state changes.
	 */
	public var runOnBackground(get_runOnBackground, set_runOnBackground):Bool;
	private function get_runOnBackground():Bool { return m_run_on_background; }
	private function set_runOnBackground(v:Bool):Bool { m_run_on_background = v; return v; }	
	private var m_run_on_background : Bool;
	
	/**
	 * List of scenes of the project.
	 */
	private var m_scenes : Array<Scene>;
	
	/**
	 * Flag that allows the initialization.
	 */
	private var m_init_allowed : Bool;
	
	/**
	 * Creates a new Application and register it in the global list.
	 */	
	override function OnBuild():Void 
	{
		super.OnBuild();		
		m_instance 		= this;
		m_browser		= new BrowserAgent();
		m_scenes   		= [];
		fps 			= 60;
		m_frame_ms	    = 0.0;		
		m_init_allowed  = false;
		m_run_on_background = false;		
		Time.Initialize();		
		Screen.Initialize(this);
		Input.Initialize();
	}
	
	/**
	 * Loads a new scene in the current context and keep it together with the current one.
	 * @param	p_name
	 */
	public function LoadScene(p_name : String):Void
	{
		//TODO
	}
	
	/**
	 * Destroys the scene referenced by name.
	 * @param	p_name
	 */
	public function DestroyScene(p_name : String):Void
	{
		//TODO
	}
	
	/**
	 * Callback to handle resource preloading. Load elements from disk or web here.
	 * @return Bool - Flag that indicates if the loading process will be synchronized [true = Initialize immediately, false = Wait for load completion]
	 */
	public function Load():Bool { return true; }
	
	
	/**
	 * Application main entry point. This method is called after all Loading is done.
	 * If Load() returns true, this method is called soon after it.
	 * If it returns false, the Application instance will wait for the LoadComplete() callback.
	 */
	public function Initialize():Void { }
	
	
	/**
	 * Callback called after all loading is complete. If the load process is async the user must call this method manually.
	 */
	public function LoadComplete():Void
	{	
		m_init_allowed = true;		
	}
	
	/**
	 * Callback called by the asset manager while assets are loaded.
	 * @param	p_id
	 * @param	p_progress
	 */
	public function OnLoadProgress(p_id : String, p_progress : Float32):Void { }
	
	/**
	 * Callback called when some asset finished loading and is ready to use.
	 * @param	p_id
	 * @param	p_asset
	 */
	public function OnLoadComplete(p_id : String,p_asset : Dynamic):Void { }
	
	/**
	 * Update callback.
	 */
	private function Update():Void 
	{			
		Time.Update();
		Input.m_handler.Update();
		CheckResize();		
		Engine.Update();
		Engine.Collect();
		Input.m_handler.Clear();
	}
	
	/**
	 * Render callback.
	 */
	private  function Render():Void 
	{			
		if (m_init_allowed)
		{
			Console.Log("Application> Initialize.", 3);		
			Initialize();
			m_init_allowed = false;
		}		
		
		m_frame_ms += Time.delta;
		
		if (m_frame_ms >= m_mspf)
		{	
			m_frame_ms = 0.0;
			
			Time.Render();
			
			#if !ie8
			GL.Focus();		
			#end
			
			Engine.Render();						
			
			#if !ie8
			GL.Flush();		
			#end
		}		
		
	}
	
	/**
	 * Application Quit Callback
	 */
	private function OnQuit():Void	{ }
	
	/**
	 * Focus Callback
	 */
	private function OnFocus():Void {  }
	
	/**
	 * Unfocus Callback
	 */
	private function OnUnfocus():Void {  }
	
	/**
	 * Check if the application container changed size.
	 */
	private function CheckResize():Void
	{		
		var has_resize : Bool = false;		
		if (Math.abs(Screen.m_width  - GetContainerWidth()) > 0.0)  { Screen.m_width   = GetContainerWidth();  has_resize = true;	}
		if (Math.abs(Screen.m_height - GetContainerHeight()) > 0.0) { Screen.m_height  = GetContainerHeight(); has_resize = true;	}		
		if (has_resize)
		{
			OnResize();
		}
	}
	
	/**
	 * Resize Callback
	 */
	private function OnResize():Void 
	{
		Console.Log("Application> Resize [" + Screen.m_width + "," + Screen.m_height + "]", 6);
		#if !ie8
		GL.Resize();
		#end
		Engine.Resize();
	}
	
	/**
	 * Fullscreen Enter Callback
	 */
	private function OnFullscreenEnter():Void { }
	
	/**
	 * Fullscreen Exit Callback
	 */
	private function OnFullscreenExit():Void { }
	
	/**
	 * Callback called when the system/user requests a change in the fullscreen flag
	 * @param	v
	 */
	private function OnFullscreenRequest(v:Bool):Bool { return false; }
	
	/**
	 * Callback called when the system/user requests a change in the pointer lock flag.
	 * @param	v
	 */
	private function OnPointerLockRequest(v:Bool):Bool {  return false; }
	
	/**
	 * Callback called when the system/user requests to change the visibility of the pointer.
	 * @param	v
	 */
	private function OnPointerVisibilityRequest(v:Bool):Bool { return false; }
	
	/**
	 * Callback for updating the mouse information.
	 * @param	p_x
	 * @param	p_y
	 */
	private function OnMousePosition(p_x:Float32,p_y:Float32):Void { }
	
	/**
	 * Returns the application container (Element, OSWindow, ...) width
	 * @return
	 */
	private function GetContainerWidth():Float32{ return 0.0; }
	
	/**
	 * Returns the application container (Element, OSWindow, ...) height
	 * @return
	 */
	private function GetContainerHeight():Float32{ return 0.0; }
	
}