#if html

package haxor.platform.html.net;
import js.html.ErrorEvent;
import js.html.XMLHttpRequestProgressEvent;
import haxor.net.HTTPRequestTask;
import js.html.XMLHttpRequest;

/**
 * Base class for HTML load operations.
 */
class HTTPRequest extends HTTPRequestTask<XMLHttpRequest,Dynamic>
{
	/**
	 * Creates a new Load Task.
	 * @param	p_url
	 * @param	p_method
	 * @param	p_binary
	 */
	public function new(p_url:String,p_method:String, p_binary:Bool,p_data:Dynamic=null):Void
	{
		super(p_url, p_method, p_binary, p_data);	
		request = new XMLHttpRequest();						
		if (request.withCredentials){ request.withCredentials = false; }		
		if (request.overrideMimeType != null) {  request.overrideMimeType(p_binary ? "application/octet-stream" : "text/plain");  }				
		request.onprogress 	= function(e : XMLHttpRequestProgressEvent)
		{
			bytesLoaded = e.loaded;
			bytesTotal  = e.total;
			progress = (e.total<=0 ? 0 : (e.loaded / (e.total+5))) * 0.999;			
		};		
		request.onload 		= function(e : XMLHttpRequestProgressEvent) { progress = 1.0; };		
		request.onerror 	= function(e:ErrorEvent) {	request = null; progress = 1.0; error = e.message; OnError(); };			
		request.open(method, url, true);
	}
	
	/**
	 * Starts the load task.
	 */
	override public function OnStart():Void { if (data == null) { request.send(); } else { request.send(data); } }		
}

#end