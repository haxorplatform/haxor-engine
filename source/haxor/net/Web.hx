package haxor.net;
import haxor.graphics.texture.Bitmap;

#if html
import haxor.platform.html.Web.HTTPLoader;
import haxor.platform.html.Web.BitmapLoader;
#end

#if android
import haxor.platform.android.Web.HTTPLoader;
import haxor.platform.android.Web.BitmapLoader;
#end

#if windows
import haxor.platform.windows.Web.HTTPLoader;
import haxor.platform.windows.BitmapLoader;
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
	 * Loads a string from web.
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function Load(p_url:String, p_callback : String->Float->Void):Void { var ld : HTTPLoader<String> = new HTTPLoader<String>(p_url,false,p_callback); }
	
	/**
	 * Loads a Bitmap from the web.
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function LoadImg(p_url:String,p_callback : Bitmap->Float->Void):Void { var ld : BitmapLoader = new BitmapLoader(p_url,p_callback); }
	
	
}