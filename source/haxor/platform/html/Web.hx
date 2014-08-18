#if html

package haxor.platform.html;
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
import haxor.platform.Types.BitmapFile;
import haxor.platform.html.Web.LoadTask;
import haxor.net.Web;
import haxor.thread.Task;
import js.html.XMLHttpRequestProgressEvent;
import js.html.XMLHttpRequest;

/**
 * Loads a RAW bitmap file from the web. In the HTML platform, the 'BitmapFile' is simply an Image element.
 */
class LoadBitmapFile extends LoadDataTask<Uint8Array>
{
	/**
	 * Internal callback.
	 */
	private var m_bitmap_callback : BitmapFile-> Float->Void;
	
	/**
	 * Creates a new LoadBitmapFile Task.
	 * @param	p_url
	 * @param	p_callback
	 */
	public function new(p_url:String, p_callback : BitmapFile-> Float->Void):Void
	{		
		super(p_url, true, OnBitmapLoadProgress);		
		m_bitmap_callback = p_callback;
		request.responseType = "blob";
	}
	
	/**
	 * 
	 * @param	p_bitmap
	 * @param	p_progress
	 */
	private function OnBitmapLoadProgress(p_bitmap_data:Uint8Array, p_progress:Float):Void 
	{
		if (p_progress < 1.0)
		{
			m_bitmap_callback(null, p_progress);
		}
		else
		{
			if (p_bitmap_data == null)
			{
				m_bitmap_callback(null, 1.0);
			}
			else
			{					
				var img : Image = new Image();				
								
				img.onload = function(e:Event):Void
				{					
					var g : CanvasRenderingContext2D = Browser.document.createCanvasElement().getContext2d();					
					g.canvas.width 	= img.width;
					g.canvas.height = img.height;					
					g.drawImage(img, 0, 0);					
					var data : ImageData = g.getImageData(0, 0, g.canvas.width, g.canvas.height);					
					var pixels : Buffer = new Buffer(0);					
					pixels.m_buffer = data.data;
					pixels.m_length = data.data.length;
					m_bitmap_callback(img, 1.0);
				};
				img.src = DOMURL.createObjectURL(request.response);				
			}
		}
	}
}

/**
 * Load Task that will handle the download of strings.
 */
class LoadDataTask<T> extends LoadTask
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
class LoadTask extends Task
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
	 * Creates a new Load Task.
	 * @param	p_url
	 * @param	p_method
	 * @param	p_binary
	 */
	public function new(p_url:String,p_method:String, p_binary:Bool):Void
	{
		super();		
		if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", Web.root);		
		url 	= p_url;
		binary  = p_binary;		
		request = new XMLHttpRequest();				
		method  = p_method;		
		if (request.withCredentials){ request.withCredentials = false; }		
		if (request.overrideMimeType != null) {  request.overrideMimeType(p_binary ? "application/octet-stream" : "text/plain");  }				
		request.onprogress 	= function(e : XMLHttpRequestProgressEvent)
		{
			progress = (e.total<=0 ? 0 : (e.loaded / (e.total+5))) * 0.999;
			OnProgress();
		};		
		request.onload 		= function(e : XMLHttpRequestProgressEvent) { progress = 1.0; };		
		request.onerror 	= function(e:XMLHttpRequestProgressEvent) {	request = null; progress = 1.0; OnError(); };			
		request.open(method, url, true);
	}
	
	/**
	 * Starts the load task.
	 */
	override public function OnStart():Void { request.send(); }
	
	/**
	 * Callback called when a progress step occur.
	 * @param	p_ratio
	 */
	private function OnProgress():Void { }
	
	/**
	 * Callback called when something went wrong.
	 */
	private function OnError():Void { }
}


#end