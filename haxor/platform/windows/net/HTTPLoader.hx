#if windows

package haxor.platform.windows.net;
import haxor.io.Buffer;

/**
 * Load Task that will handle the download of strings.
 */
class HTTPLoader<T> extends HTTPRequest
{
	/**
	 * Callback that will handle the load feedback.
	 */
	public var callback : T->Float->Void;
	
	/**
	 * Creates a new Load Task to retrieve bytes from the web.
	 * @param	p_url
	 * @param	p_binary
	 * @param	p_callback
	 */
	public function new(p_url:String,p_binary:Bool, p_callback : T->Float->Void):Void
	{
		super(p_url, "GET", p_binary);
		callback = p_callback;
	}	
	override public function OnStart():Void { if (callback != null) callback(null, 0.0); }	
	override function OnProgress():Void     { if (callback != null) callback(null, progress*0.9999); }
	override public function OnComplete():Void 
	{ 
		if (callback == null) return;		
		if (binary)
		{
			if (response == null) { if (callback != null) callback(null, 1.0); return; }
			var b : Buffer = new Buffer(response.length);
			for (i in 0...response.length) b.SetByte(i, response.charCodeAt(i));			
			if (callback != null)callback(cast b, 1.0); 
		}
		else 
		{
			if (callback != null)callback(cast response, 1.0);
		}
	}
	
	override function OnError():Void { super.OnError(); if (callback != null) callback(null, 1.0); }
}


#end