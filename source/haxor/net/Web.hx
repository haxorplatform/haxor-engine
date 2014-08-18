package haxor.net;

#if html
import haxor.platform.html.Web.LoadDataTask;
#end

#if android
#end

/**
 * Class that handles the loading of data from the Web.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Web
{
	/**
	 * Root path that will replace the './' string in URLs.
	 */
	static public var root : String = "";
	
	/**
	 * Loads a string from the informed URL.
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function Load(p_url:String, p_callback : String->Float->Void):Void
	{
		//var ld : LoadDataTask<String> = new LoadDataTask<String>(p_url,false,p_callback);		
	}
	
	
}