#if android

package haxor.platform.android.net;
import haxor.platform.Types.Float32;
import haxor.core.Console;
import haxor.math.Color;
import haxor.io.Buffer;

import haxor.core.Enums.PixelFormat;
import haxor.graphics.texture.Bitmap;
import android.graphics.BitmapFactory;
import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.lang.Exception;
import java.lang.Runnable;
import java.lang.StringBuilder;
import java.lang.Thread;
import java.lang.Throwable;
import java.NativeArray;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLConnection;
import java.StdTypes.Char16;
import java.StdTypes.Int8;

/**
 * Class that will handle the loading of a bitmap.
 */
class BitmapLoader extends HTTPLoader<Buffer>
{
	
	/**
	 * Internal handler of loading events.
	 */
	private var m_bitmap_callback : Bitmap->Float->Void;
	
	/**
	 * Creates a new bitmap loader.
	 * @param	p_url
	 * @param	p_callback
	 */
	public function new(p_url:String, p_callback : Bitmap->Float->Void):Void 
	{ 
		super(p_url, true, OnBufferCallback); 
		m_bitmap_callback = p_callback;
	}
	
	private function OnBufferCallback(p_data : Buffer, p_progress : Float32):Void
	{
		
		if (progress < 1.0)
		{
			if (m_bitmap_callback != null) m_bitmap_callback(null, progress*0.999);
		}
		else
		{
			if (p_data == null)	return;
			var bl : NativeArray<Int8> = response.toByteArray();			
			var ab : android.graphics.Bitmap = null;
			try
			{
				ab = BitmapFactory.decodeByteArray(bl, 0, bl.length);
			}
			catch (err : Exception)
			{
				error = err.getMessage();
				OnError();
				return;
			}
			if (ab == null) return;
			var w 	: Int 			= ab.getWidth();
			var h 	: Int 			= ab.getHeight();
			var cc 	: Int 			= Std.int((ab.getRowBytes() * ab.getHeight()) / (w * h));
			var fmt : PixelFormat 	= PixelFormat.RGBA8;
			switch(cc)
			{
				case 1: fmt = PixelFormat.Alpha8;
				case 3: fmt = PixelFormat.RGB8;
				case 4: fmt = PixelFormat.RGBA8;
			}			 
			var b : Bitmap = new Bitmap(w, h, fmt);						
			var c : Color = Color.temp;
			for (ix in 0...w)
			for (iy in 0...h)
			{
				var pix : Int = ab.getPixel(ix,iy);				
				c.argb = pix;				
				b.SetPixel(ix,iy, c);
			}
			
			if(m_bitmap_callback!=null)m_bitmap_callback(b, 1.0);
		}
	}
	
	override function OnError():Void { super.OnError(); if (m_bitmap_callback != null) m_bitmap_callback(null, 1.0); }
}


#end
