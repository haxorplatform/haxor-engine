#if html

package haxor.platform.html.net;
import haxor.platform.Types.Float32;

/**
 * Load Task that will handle the download of strings.
 */
class HTTPLoader<T> extends HTTPRequest
{
	/**
	 * Callback that will handle the load feedback.
	 */
	public var callback : T->Float32->Void;
	
	/**
	 * Creates a new Load Task to retrieve a string from the web.
	 * @param	p_url
	 * @param	p_callback
	 */
	public function new(p_url:String,p_binary:Bool, p_callback : T->Float32->Void):Void
	{
		super(p_url, "get", p_binary);
		callback = p_callback;
	}	
	
	override public function OnStart():Void { super.OnStart(); if (callback != null) callback(null, 0.0); }	
	override public function OnComplete():Void 
	{ 
		if (callback == null) return;
		if (request == null) { callback(null, 1.0); return; }	
		response = request.response;		
		if (binary) callback(cast request.response, 1.0); else callback(cast request.responseText, 1.0); 
	}
}

#end