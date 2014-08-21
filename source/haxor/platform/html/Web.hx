#if html

package haxor.platform.html;
import haxor.graphics.Enums.PixelFormat;
import haxor.graphics.texture.Bitmap;
import haxe.Timer;
import haxor.core.Console;
import js.html.ImageData;
import haxor.io.Buffer;
import js.html.CanvasRenderingContext2D;
import js.html.CanvasElement;
import js.html.Event;
import js.html.Image;
import js.html.DOMURL;
import js.Browser;
import js.html.Blob;
import js.html.Uint8Array;
import haxor.platform.html.Web.HTTPRequest;
import haxor.net.Web;
import haxor.thread.Task;
import js.html.XMLHttpRequestProgressEvent;
import js.html.XMLHttpRequest;

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
		request.responseType = "blob";
	}
	
	/**
	 * 
	 * @param	p_bitmap
	 * @param	p_progress
	 */
	private function OnBufferCallback(p_data:Uint8Array, p_progress:Float):Void 
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
				var g : CanvasRenderingContext2D = Browser.document.createCanvasElement().getContext2d();					
				g.canvas.width 	= img.width;
				g.canvas.height = img.height;					
				g.drawImage(img, 0, 0);					
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
				var b : Bitmap = new Bitmap(w,h, fmt);				
				b.buffer.m_buffer.set(data.data);
				if (m_bitmap_callback != null) m_bitmap_callback(b, 1.0);
			}
		
			img.src = DOMURL.createObjectURL(request.response);				
			
		}
	}
	
	override function OnError():Void { if(m_bitmap_callback!=null) m_bitmap_callback(null, 1.0);	}
}

/**
 * Load Task that will handle the download of strings.
 */
class HTTPLoader<T> extends HTTPRequest
{
	/**
	 * Callback that will handle the load feedback.
	 */
	public var callback : T->Float->Void;
	
	/**
	 * Creates a new Load Task to retrieve a string from the web.
	 * @param	p_url
	 * @param	p_callback
	 */
	public function new(p_url:String,p_binary:Bool, p_callback : T->Float->Void):Void
	{
		super(p_url, "get", p_binary);
		callback = p_callback;
	}	
	
	override public function OnStart():Void { super.OnStart(); if (callback != null) callback(null, 0.0); }	
	override public function OnComplete():Void 
	{ 
		if (callback == null) return;
		if (request == null) { callback(null, 1.0); return; }		
		if (binary) callback(cast request.response, 1.0); else callback(cast request.responseText, 1.0); 
	}
}




/**
 * Base class for HTML load operations.
 */
class HTTPRequest extends Task
{
	/**
	 * URL of the target data.
	 */
	public var url : String;
	
	/**
	 * Request handler of the operation.
	 */
	public var request : XMLHttpRequest;
	
	/**
	 * Flag that indicates if the operation will download binary data.
	 */
	public var binary : Bool;
	
	/**
	 * HTTP method of the operation.
	 */
	public var method : String;
	
	/**
	 * Reference to the data if the operation will be 'send'.
	 */
	public var data : Dynamic;
	
	/**
	 * Creates a new Load Task.
	 * @param	p_url
	 * @param	p_method
	 * @param	p_binary
	 */
	public function new(p_url:String,p_method:String, p_binary:Bool,p_data:Dynamic=null):Void
	{
		super();		
		if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", Web.root);		
		url 	= p_url;
		binary  = p_binary;		
		request = new XMLHttpRequest();				
		method  = p_method;	
		data	= p_data;
		if (request.withCredentials){ request.withCredentials = false; }		
		if (request.overrideMimeType != null) {  request.overrideMimeType(p_binary ? "application/octet-stream" : "text/plain");  }				
		request.onprogress 	= function(e : XMLHttpRequestProgressEvent)
		{
			progress = (e.total<=0 ? 0 : (e.loaded / (e.total+5))) * 0.999;			
		};		
		request.onload 		= function(e : XMLHttpRequestProgressEvent) { progress = 1.0; };		
		request.onerror 	= function(e:XMLHttpRequestProgressEvent) {	request = null; progress = 1.0; OnError(); };			
		request.open(method, url, true);
	}
	
	/**
	 * Starts the load task.
	 */
	override public function OnStart():Void { if (data == null) { request.send(); } else { request.send(data); } }
		
	/**
	 * Callback called when something went wrong.
	 */
	private function OnError():Void { }
}


#end