#if html

package haxor.platform.html.graphics;
import haxor.core.Console;
import js.html.ImageData;
import haxor.core.Enums.PixelFormat;
import js.Browser;
import js.html.CanvasRenderingContext2D;
import js.html.Event;
import js.html.URL;
import js.html.Image;
import js.html.Blob;
import haxor.graphics.Bitmap;
import haxor.io.Buffer;

/**
 * Class that handles the conversion of a Image files raw bytes into a Bitmap.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class ImageReader
{

	/**
	 * Shortcut to a canvas that will be used to render the loaded img.
	 */
	static var c2d : CanvasRenderingContext2D;
	
	/**
	 * Decodes the PNG file described in the informed buffer and calls a callback when the process has ended.
	 * @param	p_buffer
	 * @return
	 */
	static public function ReadAsync(p_buffer : Buffer,p_on_complete : Bitmap -> Void,p_flip_y : Bool=false) : Void
	{
		var blob : Blob = new Blob([p_buffer.buffer],{ type: "application/octet-stream" });
		var img : Image = new Image();
		img.onload = function(ev:Event):Void
		{
			trace(img.width + " " + img.height);
			var g 			: CanvasRenderingContext2D = c2d = (c2d == null) ?  Browser.document.createCanvasElement().getContext2d() : c2d;
			g.canvas.width 	= img.width;
			g.canvas.height = img.height;			
			g.scale(1.0,p_flip_y ? -1.0 : 1.0); 						//Set scale to flip the image in Y
			g.drawImage(img, 0, p_flip_y ? -img.height : 0.0);			//Draw the image flipped.			
			var data : ImageData = g.getImageData(0, 0, g.canvas.width, g.canvas.height);								
			var w : Int = data.width;
			var h : Int = data.height;			
			var cc:Int = Std.int(data.data.byteLength / (w * h));			
			var fmt : PixelFormat = PixelFormat.RGBA8;
			switch(cc)
			{
				case 1: fmt = PixelFormat.Alpha8;
				case 3: fmt = PixelFormat.RGB8;
			}
			var b : Bitmap = new Bitmap(w, h, fmt);			
			b.buffer.m_buffer.set(cast data.data);	
			if(p_on_complete!=null)p_on_complete(b);
		};
		img.src = URL.createObjectURL(blob);
	}
	
	/**
	 * Decodes the PNG file described in the informed buffer and returns a Bitmap class reference.
	 * @param	p_buffer
	 * @return
	 */
	static public function Read(p_buffer : Buffer,p_flip_y : Bool=false) : Bitmap
	{
		Console.LogError("ImageReader> Synchronous Read isn't available in this platform!");
		var img : Bitmap = new Bitmap(1, 1, PixelFormat.RGB8);
		img.Set(0, 0, 1.0, 0.0, 0.0, 1.0);
		return img;
	}
	
}

#end