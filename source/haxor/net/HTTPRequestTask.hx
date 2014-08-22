package haxor.net;
import haxor.core.Console;
import haxor.thread.Task;

/**
 * Base class for HTML load operations.
 */
class HTTPRequestTask<T,U> extends Task
{
	/**
	 * URL of the target data.
	 */
	public var url : String;
	
	/**
	 * Request handler of the operation.
	 */
	public var request : T;
	
	/**
	 * Response that arrives from the request.
	 */
	public var response : U;
	
	/**
	 * Flag that indicates if the operation will download binary data.
	 */
	public var binary : Bool;
	
	/**
	 * HTTP method of the operation.
	 */
	public var method : String;
	
	/**
	 * Reference to the data if the operation will be 'send'.
	 */
	public var data : Dynamic;
	
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
	 * Creates a new Load Task.
	 * @param	p_url
	 * @param	p_method
	 * @param	p_binary
	 */
	public function new(p_url:String,p_method:String, p_binary:Bool,p_data:Dynamic=null):Void
	{
		super();		
		if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", Web.root);		
		url 	= p_url;
		binary  = p_binary;				
		method  = p_method;	
		data	= p_data;
		bytesLoaded = 0;
		bytesTotal  = 0;
		error = "";
		Console.Log("HTTPRequest> " + url,4);
	}
	
	/**
	 * Starts the load task.
	 */
	override public function OnStart():Void { }
		
	/**
	 * Callback called when something went wrong.
	 */
	private function OnError():Void { Console.LogError("HTTPRequest> Error ["+error+"]"); }
}