#if windows

package haxor.platform.windows.net;
import haxor.core.Console;
import haxe.Http;
import haxor.net.HTTPRequestTask;

/**
 * Base class for HTML load operations.
 */
class HTTPRequest extends HTTPRequestTask<Http,String>
{
	
	/**
	 * Lock var to avoid 'Http' thread collision (will crash).
	 */
	static private var m_lock : Bool = false;
		
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
		super(p_url, p_method, p_binary, p_data);
		request			= new Http(url);
		m_loading		= false;		
	}
	
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
	
}

#end