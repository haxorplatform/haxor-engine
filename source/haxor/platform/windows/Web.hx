#if windows

package haxor.platform.windows;
import haxor.core.Console;

/**
 * 
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Web
{
	/**
	 * Root path that will replace the './' string in URLs.
	 */
	static public var root : String="";

	static private var m_running : Bool = false;
	
	static private var q : Array<LoadTask>;
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function Load(p_url:String, p_callback : String->Float->Void):Void
	{	
		if (q == null) q = [];		
		p_callback(null, 0.0);
		var ld : LoadTask = new LoadTask(p_url, "GET", "", function(d:String):Void
		{
			p_callback(d, 1.0);
		}
		,
		function(err:String):Void
		{
			p_callback(null, 1.0);
		});	
		q.push(ld);
		//if (!m_running) { Thread.create(QueueUpdate); m_running = true; }
    }
	
	static function QueueUpdate():Void
	{
		while (q.length > 0)
		{
			var ld : LoadTask = q.shift();
			ld.Run();
		}
		Web.m_running = false;
	}
    
}

class LoadTask
{
	public var url 			: String;
	public var method		: String;
	public var data			: String;
	
	public var ondata : String->Void;
	public var onerror : String->Void;
	
	
	public function new(p_url:String, p_method:String, p_data:String,p_ondata : String->Void,p_onerror : String->Void):Void
	{
		url 	= StringTools.replace(p_url, "./", Web.root);
		method	= p_method;
		data	= p_data;					
		ondata  = p_ondata;
		onerror = p_onerror;
	}	
	
	public function Run():Void
	{
		/*
		trace("Web> Load from ["+url+"]");
		try
		{
			var d : String = Http.requestUrl(url);
			ondata(d);
		}
		catch (err : Dynamic)
		{
			onerror(err + "");
		}
		//*/
	}

	
}

#end