package haxor.net;
import haxor.graphics.texture.Bitmap;
import haxor.graphics.texture.Texture2D;
import haxor.net.Texture2DLoader;

#if html
import haxor.platform.html.net.HTTPLoader;
import haxor.platform.html.net.BitmapLoader;
#end

#if android
import haxor.platform.android.net.HTTPLoader;
import haxor.platform.android.net.BitmapLoader;
#end

#if windows
import haxor.platform.windows.net.HTTPLoader;
import haxor.platform.windows.net.BitmapLoader;
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
	 * Loads a Bitmap from the web. [windows don't let me use LoadBitmap :( ]
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function LoadImg(p_url:String, p_callback : Bitmap->Float->Void):Void { var ld : BitmapLoader = new BitmapLoader(p_url, p_callback); }
	
	/**
	 * Loads a Bitmap from the web and creates a texture with it. The user can later decide if he Applies or Uploads the pixel data.
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function LoadTexture2D(p_url:String,p_apply:Bool,p_callback : Texture2D->Float->Void):Void { var ld : Texture2DLoader = new Texture2DLoader(p_url,p_apply, p_callback); }
	
	
}