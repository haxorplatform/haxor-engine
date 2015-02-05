

package haxor.net;

import haxor.graphics.texture.Bitmap;
import haxor.platform.Types.Float32;
import haxor.thread.Activity;
import haxor.graphics.texture.Texture2D;

#if android
import haxor.platform.android.net.BitmapLoader;
#end

#if windows
import haxor.platform.windows.net.BitmapLoader;
#end

#if html
import haxor.platform.html.net.BitmapLoader;
#end

/**
 * Class that wraps the BitmapLoader and creates a new Texture2D with the loaded bitmap.
 */
class Texture2DLoader extends BitmapLoader
{
	/**
	 * Internal handler of loading events.
	 */
	private var m_t2d_callback : Texture2D->Float->Void;
	
	/**
	 * Applies texture changes.
	 */
	private var m_apply : Bool;
	
	/**
	 * 
	 * @param	p_url
	 * @param	p_apply
	 * @param	p_callback
	 */
	public function new(p_url:String,p_apply:Bool, p_callback : Texture2D->Float->Void):Void 
	{
		super(p_url, OnBitmapCallback);
		m_t2d_callback = p_callback;
		m_apply = p_apply;
	}
	
	/**
	 * 
	 * @param	p_data
	 * @param	p_progress
	 */
	private function OnBitmapCallback(p_data : Bitmap, p_progress : Float32):Void
	{
		if (progress < 1.0)
		{
			if (m_t2d_callback != null) m_t2d_callback(null, progress);
		}
		else
		{
			if (p_data == null) return;			
			//Needs to finish the texture creation in a Graphics context.
			Activity.RunOnce(function():Void
			{	
				var t : Texture2D = Texture2D.FromBitmap(p_data, m_apply);			
				m_t2d_callback(t, 1.0);
			},false, true);
			//*/
		}
	}
	
	override function OnError():Void { super.OnError(); if (m_t2d_callback != null) m_bitmap_callback(null, 1.0); }
}

