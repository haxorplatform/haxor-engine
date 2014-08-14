#if html

package haxor.platform.html;
import js.html.XMLHttpRequestProgressEvent;
import js.html.XMLHttpRequest;

/**
 * Class that handles the loading of web data.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Web
{
	/**
	 * Root path that will replace the './' string in URLs.
	 */
	static public var root : String="";
	
	/**
	 * Generic method for all load operations that uses a XMLHttpRequest.
	 * @param	p_url
	 * @param	p_binary
	 * @return
	 */
	static private function CreateRequest(p_url:String, p_binary:Bool):XMLHttpRequest
	{
		if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", root);
		var req : XMLHttpRequest = new XMLHttpRequest();		
		if (req.withCredentials) req.withCredentials = false;
		if (req.overrideMimeType != null) { req.overrideMimeType(p_binary ? "application/octet-stream" : "text/plain"); }		
		req.open("get", p_url, true);
		return req;
	}
	
	/**
	 * Loads a String from the URL.
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function Load(p_url:String, p_callback : String -> Float -> Void):Void
	{	
		var req : XMLHttpRequest = CreateRequest(p_url, false);		
		req.onprogress = function(e : XMLHttpRequestProgressEvent)
		{
			var f:Float = e.total<=0 ? 0 : (e.loaded / (e.total+5));
			p_callback(null, f);
		};
		
		req.onload = function(e : XMLHttpRequestProgressEvent)
		{			
			p_callback(req.responseText,1.0);
		};
		
		req.onerror = function(e:XMLHttpRequestProgressEvent)
		{			
			p_callback(null,1.0);
		};		
		req.send();		
	}
	
	
	
}

#end