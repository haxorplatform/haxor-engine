#if (html||nodejs)

package haxor.platform.html.net;
import js.html.URL;
import js.html.XMLHttpRequestResponseType;
import haxor.platform.Types.Float32;
import js.Browser;
import haxor.core.Enums.PixelFormat;
import js.html.Event;
import js.html.Image;
import haxor.graphics.texture.Bitmap;
import js.html.Uint8Array;
import js.html.CanvasRenderingContext2D;
import js.html.DOMURL;
import js.html.ImageData;

/**
 * Loads a bitmap file from the web. In the HTML platform.
 */
class BitmapLoader extends HTTPLoader<Uint8Array>
{
	/**
	 * Internal callback.
	 */
	private var m_bitmap_callback : Bitmap-> Float->Void;
	
	/**
	 * Creates a new LoadBitmapFile Task.
	 * @param	p_url
	 * @param	p_callback
	 */
	public function new(p_url:String, p_callback : Bitmap-> Float->Void):Void
	{		
		super(p_url, true, OnBufferCallback);		
		m_bitmap_callback = p_callback;
		request.responseType = XMLHttpRequestResponseType.BLOB;
	}
	
	/**
	 * 
	 * @param	p_bitmap
	 * @param	p_progress
	 */
	private function OnBufferCallback(p_data:Uint8Array, p_progress:Float32):Void 
	{
		if (p_progress < 1.0)
		{
			if(m_bitmap_callback!=null) m_bitmap_callback(null, progress);
		}
		else
		{
			if (p_data == null) return;
			var img : Image = new Image();							
			img.onload = function(e:Event):Void
			{			
				var data : ImageData = null;
				var w    : Int = 1;
				var h    : Int = 1;
				var fmt : PixelFormat = PixelFormat.RGBA8;
				
				if (Browser.document != null)
				{
					var g : CanvasRenderingContext2D = Browser.document.createCanvasElement().getContext2d();
					g.canvas.width 	= img.width;
					g.canvas.height = img.height;			
					g.scale(1.0,-1.0); 						//Set scale to flip the image in Y
					g.drawImage(img, 0,-img.height); 		//Draw the image flipped.				
					data = g.getImageData(0, 0, g.canvas.width, g.canvas.height);					
					w = data.width;
					h = data.height;
					var cc:Int = Std.int(data.data.byteLength / (w * h));					
					switch(cc)
					{
						case 1: fmt = PixelFormat.Alpha8;
						case 3: fmt = PixelFormat.RGB8;
					}
				}
				var b : Bitmap = new Bitmap(w,h, fmt);				
				if(data != null) b.buffer.m_buffer.set(cast data.data);
				if (m_bitmap_callback != null) m_bitmap_callback(b, 1.0);
			}
		
			img.src = URL.createObjectURL(request.response);				
			
		}
	}
	
	override function OnError():Void { if(m_bitmap_callback!=null) m_bitmap_callback(null, 1.0);	}
}

#end