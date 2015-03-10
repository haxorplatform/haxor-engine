package haxor.net;
import haxor.core.Resource;
import haxor.graphics.material.Material;
import haxor.graphics.material.Shader;
import haxor.graphics.texture.Bitmap;
import haxor.graphics.texture.Texture2D;
import haxor.graphics.texture.TextureCube;
import haxor.io.file.ColladaFile;
import haxor.io.file.MaterialFile;
import haxor.net.Texture2DLoader;
import haxor.platform.Types.Float32;

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
	static public function Load(p_url:String, p_callback : String->Float32->Void):Void { var ld : HTTPLoader<String> = new HTTPLoader<String>(p_url,false,p_callback); }
	
	/**
	 * Loads a Bitmap from the web. [windows don't let me use LoadBitmap :( ]
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function LoadImg(p_url:String, p_callback : Bitmap->Float32->Void):Void { var ld : BitmapLoader = new BitmapLoader(p_url, p_callback); }
	
	/**
	 * Loads a Bitmap from the web and creates a texture with it. The user can later decide if he Applies or Uploads the pixel data.
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function LoadTexture2D(p_url:String, p_apply:Bool, p_callback : Texture2D->Float32->Void):Void { var ld : Texture2DLoader = new Texture2DLoader(p_url, p_apply, p_callback); }
	
	/**
	 * Loads a Bitmap from the web and creates a cube texture with it.
	 * @param	p_url
	 * @param	p_apply
	 * @param	p_callback
	 */
	static public function LoadTextureCubeCross(p_url:String, p_apply:Bool, p_callback : TextureCube-> Float32->Void):Void 
	{ 
		var ld : Texture2DLoader = new Texture2DLoader(p_url, true, function(t : Texture2D, p : Float32):Void
		{
			if (p < 1.0) p_callback(null, p);
			else
			{
				if (t == null)
				{
					p_callback(null, 1.0);
					return;
				}
				var tc : TextureCube = new TextureCube();
				tc.LoadCrossTexture(t);
				Resource.Destroy(t);
				p_callback(tc, 1.0);
			}
		}); 
	}
	
	
	/**
	 * Loads a ColladaFile from the web.
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function LoadCollada(p_url:String, p_callback : ColladaFile-> Float32->Void):Void {	Load(p_url, function(d : String, p:Float):Void { if (p < 1.0) p_callback(null, p); else p_callback(d == null ? null : new ColladaFile(p_url, d), 1.0); } ); }
	
	/**
	 * Loads a shader from the web.
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function LoadShader(p_url:String, p_callback : Shader-> Float32->Void):Void {	Load(p_url, function(d : String, p:Float):Void { if (p < 1.0) p_callback(null, p); else p_callback(d == null ? null : new Shader(d), 1.0); } ); }
	
	/**
	 * Loads a material from the web.
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function LoadMaterial(p_url:String, p_callback : MaterialFile-> Float32->Void):Void {	Load(p_url, function(d : String, p:Float):Void { if (p < 1.0) p_callback(null, p); else p_callback(d == null ? null : new MaterialFile(d), 1.0); } ); }
	
	
}