#if windows

package haxor.platform.windows.net;
import haxor.math.Mathf;
import haxor.math.Color;
import haxor.platform.Types.Float32;

import haxe.Http;
import haxor.core.Console;
import haxor.core.Enums.PixelFormat;
import haxor.graphics.texture.Bitmap;
import haxor.io.Buffer;
import haxor.net.Web;
import haxor.platform.Types.ArrayBuffer;
import haxor.platform.windows.net.HTTPLoader;
import haxor.thread.Task;

@:headerCode('

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include "stb/stb_image.h"  


')

/**
 * Class that will handle the loading of a bitmap.
 */
class BitmapLoader extends HTTPLoader<Buffer>
{
	
	/**
	 * Internal handler of loading events.
	 */
	private var m_bitmap_callback : Bitmap->Float32->Void;
	
	/**
	 * Creates a new bitmap loader.
	 * @param	p_url
	 * @param	p_callback
	 */
	public function new(p_url:String, p_callback : Bitmap->Float32->Void):Void 
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
			
			var file_bl : ArrayBuffer = p_data.m_buffer;
			var file_len : Int = p_data.length;
			var w : Int = 0;
			var h : Int = 0;
			var byte_length : Int = 0;
			var cc : Int = 0;
			
			untyped __cpp__('
			unsigned char * img_buffer = (stbi_uc * ) stbi_load_from_memory( & file_bl->b[0], file_len, & w, & h, & cc, 0);			
			');						
			//*/
			
			byte_length = w * h * cc;			
			var buffer : Buffer = new Buffer(byte_length);
			var bytes : ArrayBuffer = buffer.m_buffer;
			
			untyped __cpp__('
			for (int i = 0; i < byte_length;i++) bytes->b[i] = img_buffer[i];
			stbi_image_free(img_buffer);
			');		
			//*/
			var fmt : PixelFormat = PixelFormat.RGBA8;
			switch(cc)
			{
				case 1: fmt = PixelFormat.Alpha8;
				case 3: fmt = PixelFormat.RGB8;
			}			 
			var b : Bitmap = new Bitmap(w, h, fmt);
			var k  : Int = 0;
			var c : Color = Color.temp;			
			while(k < buffer.byteLength)
			{
				var pix  : Int = cast (k / cc);
				var px 	 : Int = pix % b.width;
				var py 	 : Int = cast (pix / b.width);
				var ipix : Int = ((px + ((b.height - 1 - py) * b.width))*cc)+(k%cc);
				var v : Int = buffer.GetByte(ipix);
				b.buffer.SetByte(k, v);
				k++;
			}			
			if(m_bitmap_callback!=null)m_bitmap_callback(b, 1.0);			
		}
	}
	
	override function OnError():Void { super.OnError(); if (m_bitmap_callback != null) m_bitmap_callback(null, 1.0); }
}


#end