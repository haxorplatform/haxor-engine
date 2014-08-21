#if windows
package haxor.platform.windows;
import haxor.platform.Types.ArrayBuffer;
import haxor.graphics.Enums.PixelFormat;
import haxor.graphics.texture.Bitmap;
import haxor.net.Web;
import haxor.thread.Task;
import haxe.Http;
import haxor.io.Buffer;
import haxor.core.Console;


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
	
	override function OnError():Void { if (callback != null) callback(null, 1.0); }
}

/**
 * Base class for HTML load operations.
 */
class HTTPRequest extends Task
{
	
	/**
	 * Lock var to avoid 'Http' thread collision (will crash).
	 */
	static private var m_lock : Bool = false;
	
	/**
	 * URL of the target data.
	 */
	public var url : String;
		
	/**
	 * Flag that indicates if the operation will download binary data.
	 */
	public var binary : Bool;
	
	/**
	 * Reference to the HTTP connection.
	 */
	public var request : Http;
	
	/**
	 * Reference of the data to be sent.
	 */
	public var data : String;
	
	/**
	 * HTTP method of the operation.
	 */
	public var method : String;
	
	/**
	 * Data arrived from the request.
	 */
	public var response : String;
	
	/**
	 * Bytes loaded by the request.
	 */
	public var bytesLoaded : Int;
	
	/**
	 * Bytes total to be loaded.
	 */
	public var bytesTotal : Int;
	
	/**
	 * Error msg if any.
	 */
	public var error : String;
	
	/**
	 * Flag that indicates if the loading request was made.
	 */
	private var m_loading : Bool;
	
	/**
	 * Creates a new Load Task.
	 * @param	p_url
	 * @param	p_method
	 * @param	p_binary
	 */
	public function new(p_url:String,p_method:String, p_binary:Bool,p_data : String=null):Void
	{
		super(true);
		if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", Web.root);		
		url 			= p_url;
		binary  		= p_binary;				
		method  		= p_method.toUpperCase();	
		data			= p_data;
		bytesTotal 		= 0;
		bytesLoaded		= 0;
		error 			= "";
		request			= new Http(url);
		m_loading		= false;		
	}
	
	/**
	 * Starts the load task.
	 */
	override public function OnStart():Void { }
	
	/**
	 * Loading step.
	 */
	override public function OnStep():Void
	{
		if (m_lock) return;
		m_lock = true;
		if (!m_loading)
		{
			Console.Log("HTTPRequest> " + url,4);
			m_loading = true;
			request.onError = function(err:String):Void { error = err; OnError(); Cancel(); m_lock = false; };
			request.onData  = function(d:String):Void
			{
				response = d;
				progress = 1.0;				
				m_lock = false;
			};			
			request.onStatus = function(n :Int):Void { };
			request.request(method == "POST");
		}
	}
	
	/**
	 * Called when the operation is finished.
	 */
	override public function OnComplete():Void { }
	
	/**
	 * Callback called when something went wrong.
	 */
	private function OnError():Void
	{
		Console.Log("HTTPRequest> Error ["+error+"]");	
	}
}



#end