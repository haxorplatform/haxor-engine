#if html
package haxor.platform.html;
import js.html.DivElement;
import haxor.core.BaseApplication;
import js.Browser;
import js.html.CanvasElement;
import js.html.CanvasRenderingContext2D;
import js.html.EventListener;
import js.html.Image;
import js.html.Event;
import js.html.Node;
import js.html.NodeList;
import js.html.ProgressEvent;
import js.html.EventTarget;
import js.html.XMLHttpRequest;
import js.html.Element;

enum ApplicationProtocol
{
	Unknown;
	File;
	HTTP;
	HTTPS;
}

/**
 * Class that defines a base Application for HTML projects.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class HTMLApplication extends BaseApplication
{
	
	/**
	 * Reference to the Element container in the HTML
	 */
	private var m_container : Element;
		
	/**
	 * Constructor called on page load for each [application] tag found in the page.
	 * @param	p_tag [application] element found on the HTML source.
	 */
	private function new() 
	{
		super();				
		m_platform 			= Platform.HTML;				
	}
	
	override function GetContainerWidth():Float { return m_container.clientWidth; }
	
	override function GetContainerHeight():Float { return m_container.clientHeight; }
	
	/*
	private function SetupGraphics():Void
	{
		Console.Log("Application> Setup Graphics.",1);
		m_canvas = new List<CanvasRenderingContext2D>();
		
		var g  : Graphics = cast m_graphics = new Graphics(this);
		var nl : NodeList = element.childNodes;
		var found_3d : Bool = false;
		var success3d:Bool = false;
		for (i in 0...nl.length)
		{
			var n : Node = nl.item(i);
			if (n.nodeName.toLowerCase() != "canvas") continue;
			var c : CanvasElement = cast n;
			
			if(!found_3d)
			if (c.getAttribute("3d") != null)
			{
				success3d = g.Initialize(c);
				found_3d = true;
			}
			else
			{
				var ctx_2d : CanvasRenderingContext2D = c.getContext2d();				
				m_canvas.push(ctx_2d);
			}
		}
				
		g.CheckExtensions();
		
		if (success3d){ Console.Log("ApplicationHTML> RenderingContext3D Created.",1); }
		if (!found_3d){ Console.Log("ApplicationHTML> RenderingContext3D Not Found."); }
		Console.Log("Application> Found "+m_canvas.length+" CanvasRenderingContexts.",1);
	}
		
	
	private function RequestAnimationRender(p_time:Float):Bool { Render(); Browser.window.requestAnimationFrame(RequestAnimationRender); return true; }
		
	private function RequestAnimationUpdate(p_time:Float):Bool { Update(); Render(); Browser.window.requestAnimationFrame(RequestAnimationUpdate); return true; }
		
	private function OnReqProgress(p_event:ProgressEvent):Void
	{
		var t  : EventTarget = p_event.target;
		var id : String 	 = untyped __js__("t.__id__");
		var p  :Int 		 = m_queue.indexOf(t);		
		var bl : Float 		 = cast p_event.loaded;
		var bt : Float 		 = cast p_event.total;
		var r  : Float 		 = (bt <= 0.0 ? 0.0 : (bl / bt))*0.99;		
		m_progress_list[p]   = r;
		var tr : Float = get_progress();
		OnDependenceProgress(id, t, r, tr);
	}
		
	private function OnReqComplete(p_event:Event):Void
	{
		var t  : EventTarget = p_event.target;		
		var id : String 	 = untyped __js__("t.__id__");
		var p  :Int 		 = m_queue.indexOf(t);		
		m_progress_list[p]   = 1.0;
		var tr : Float 		 = get_progress();
		OnDependenceProgress(id, t, 1.0, tr);
		OnDependenceComplete(id, t);
		ReqFinish(t);
	}
		
	private function OnReqError(p_event:Event):Void
	{
		var t  : EventTarget = p_event.target;
		var id : String 	 = untyped __js__("t.__id__");
		var p  :Int 		 = m_queue.indexOf(t);		
		m_progress_list[p]   = 1.0;
		var tr : Float 		 = get_progress();
		OnDependenceProgress(id, t, 1.0, tr);
		OnDependenceError(id, t);
		ReqFinish(t);
	}
		
	private function ReqFinish(p_req:EventTarget):Void
	{		
		p_req.removeEventListener("progress", OnReqProgress, false);
		p_req.removeEventListener("load", 	  OnReqComplete, false);
		p_req.removeEventListener("error", 	  OnReqError, 	 false);
		p_req.removeEventListener("abort", 	  OnReqError, 	 false);
		p_req.removeEventListener("canplaythrough", OnReqComplete,false);
		m_finish_count++;
		Console.Log("Application> Request Finished ["+p_req+"]",2);
		if (m_finish_count >= m_queue.length) LoadComplete();
	}
		
	override function OnFullscreenRequest(v:Bool):Bool 
	{
		var c : Dynamic = element;
		var d:Dynamic = Browser.document;
		var kf : Int = Element.ALLOW_KEYBOARD_INPUT;
		if (v)
		{	
			if (c.requestFullScreen 		!= null) 	c.requestFullScreen(kf) 		else			
			if (c.mozRequestFullScreen 		!= null) 	c.mozRequestFullScreen(kf) 		else
			if (c.msRequestFullScreen 		!= null) 	c.msRequestFullScreen(kf) 		else
			if (c.oRequestFullScreen 		!= null) 	c.oRequestFullScreen(kf) 	 	else
			if (c.webkitRequestFullScreen 	!= null) 	c.webkitRequestFullScreen(kf); 
		}
		else 
		{	
			if (d.cancelFullScreen) 		d.cancelFullScreen();			else
			if (d.mozCancelFullScreen)  	d.mozCancelFullScreen();		else
			if (d.msCancelFullScreen)  		d.msCancelFullScreen();			else
			if (d.oCancelFullScreen)  		d.oCancelFullScreen();			else
			if (d.webkitCancelFullScreen) 	d.webkitCancelFullScreen();			
		}
		
		if (d.fullscreenElement 	!= null) 			v = element == d.fullscreenElement;
		if (d.mozFullScreenElement 	!= null) 			v = element == d.mozFullScreenElement;
		if (d.msFullScreenElement 	!= null) 			v = element == d.msFullScreenElement;
		if (d.oFullScreenElement 	!= null) 			v = element == d.oFullScreenElement;
		if (d.webkitCurrentFullScreenElement != null)   v = element == d.webkitCurrentFullScreenElement;
		
		return v;
	}
		
	override function OnPointerLockRequest(v:Bool):Bool 
	{
		var e : Dynamic = element;
		var rpl: Dynamic = e.requestPointerLock    ||  e.mozRequestPointerLock || e.webkitRequestPointerLock;
    
		if (rpl == null) return false;
		
		var d : Dynamic = Browser.document;
		var epl : Dynamic = d.exitPointerLock    || d.mozExitPointerLock || d.webkitExitPointerLock;
		
		if (epl == null) return false;
		
		if (v) rpl(); else epl();
		
		return v;
	}
		
	override function OnPointerVisibilityRequest(v:Bool):Bool 
	{
		element.style.cursor = v ? "auto" : "none";
		return v;
	}
	
	//*/
	
}
#end