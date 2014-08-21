#if android

package haxor.platform.android;
import haxor.thread.Activity;
import haxor.graphics.texture.Texture2D;
import haxor.graphics.Enums.PixelFormat;
import haxor.graphics.texture.Bitmap;
import haxor.net.Web;
import haxor.thread.Task;
import haxor.io.Buffer;
import java.StdTypes.Char16;
import java.StdTypes.Int8;
import java.NativeArray;
import haxor.core.Console;

import java.lang.Thread;
import java.lang.Runnable;
import java.io.ByteArrayOutputStream;
import java.lang.Throwable;
import java.lang.Exception;
import java.net.HttpURLConnection;
import java.net.URLConnection;
import java.net.URL;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import android.graphics.BitmapFactory;
import java.lang.StringBuilder;

class LoadTexture2D extends BitmapLoader
{
	/**
	 * Internal handler of loading events.
	 */
	private var m_t2d_callback : Texture2D->Float->Void;
	
	/**
	 * Applies texture changes.
	 */
	private var m_apply : Bool;
	
	public function new(p_url:String,p_apply:Bool, p_callback : Texture2D->Float->Void):Void 
	{
		super(p_url, OnBitmapCallback);
		m_t2d_callback = p_callback;
		m_apply = p_apply;
	}
	
	private function OnBitmapCallback(p_data : Bitmap, p_progress : Float):Void
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
		}
	}
	
	override function OnError():Void { if(m_t2d_callback!=null)m_bitmap_callback(null, 1.0); }
}

/**
 * Class that will handle the loading of a bitmap.
 */
class BitmapLoader extends HTTPLoader<Buffer>
{
	
	/**
	 * Internal handler of loading events.
	 */
	private var m_bitmap_callback : haxor.graphics.texture.Bitmap->Float->Void;
	
	/**
	 * Creates a new bitmap loader.
	 * @param	p_url
	 * @param	p_callback
	 */
	public function new(p_url:String, p_callback : haxor.graphics.texture.Bitmap->Float->Void):Void 
	{ 
		super(p_url, true, OnBufferCallback); 
		m_bitmap_callback = p_callback;
	}
	
	private function OnBufferCallback(p_data : Buffer, p_progress : Float):Void
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
				error = err;
				OnError();
				return;
			}
			if (ab == null) return;
			var w : Int = ab.getWidth();
			var h : Int = ab.getHeight();
			var cc : Int = Std.int(ab.getByteCount() / (w * h));
			var fmt : PixelFormat = PixelFormat.RGBA8;
			switch(cc)
			{
				case 1: fmt = PixelFormat.Alpha8;
				case 3: fmt = PixelFormat.RGB8;
			}			 
			var b : Bitmap = new Bitmap(w,h, fmt);
			//Console.Log(ab.getWidth() + " " + ab.getHeight()+" b: "+ab.getByteCount()+" "+b.buffer.byteLength+" "+cc);			
			ab.copyPixelsToBuffer(b.buffer.m_buffer);
			if(m_bitmap_callback!=null)m_bitmap_callback(b, 1.0);
		}
	}
	
	override function OnError():Void { if(m_bitmap_callback!=null)m_bitmap_callback(null, 1.0); }
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
	 * Creates a new Load Task to retrieve bytes from the web.
	 * @param	p_url
	 * @param	p_binary
	 * @param	p_callback
	 */
	public function new(p_url:String,p_binary:Bool, p_callback : T->Float->Void):Void
	{
		super(p_url, "GET", p_binary);
		callback = p_callback;
	}	
	override public function OnStart():Void { super.OnStart(); if (callback != null) callback(null, 0.0); }	
	override function OnProgress():Void     { if (callback != null) callback(null, progress*0.9999); }
	override public function OnComplete():Void 
	{ 
		if (callback == null) return;		
		if (binary)
		{
			var bl : NativeArray<Int8> = response.toByteArray();			
			var b : Buffer = new Buffer(bl.length);
			b.m_buffer.put(bl);
			b.m_buffer.position(0);
			//Console.Log("complete> " + url + " " + b.length);
			if (callback != null)callback(cast b, 1.0);  
		}
		else 
		{
			if (callback != null)callback(cast response.toString(), 1.0);
		}
	}
	
	override function OnError():Void { if (callback != null) callback(null, 1.0); }
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
	 * Flag that indicates if the operation will download binary data.
	 */
	public var binary : Bool;
	
	/**
	 * Reference to the HTTP connection.
	 */
	public var request : HttpURLConnection;
	
	/**
	 * Reference of the data to be sent.
	 */
	public var data : String;
	
	/**
	 * HTTP method of the operation.
	 */
	public var method : String;
	
	/**
	 * Content-Type data arrived.
	 */
	public var contentType : String;
	
	/**
	 * Data arrived from the request.
	 */
	public var response : ByteArrayOutputStream;
	
	/**
	 * Bytes loaded by the request.
	 */
	public var bytesLoaded : Int;
	
	/**
	 * Bytes total to be loaded.
	 */
	public var bytesTotal : Int;
	
	/**
	 * Reference to the thrown error if any.
	 */
	public var error : Exception;
	
	/**
	 * Buffer to capture partial data loaded.
	 */
	private var m_buffer : NativeArray<Int8>;
	
	/**
	 * Input stream for the connection.
	 */
	private var m_stream : InputStream; 
	
	/**
	 * Creates a new Load Task.
	 * @param	p_url
	 * @param	p_method
	 * @param	p_binary
	 */
	public function new(p_url:String,p_method:String, p_binary:Bool,p_data : String=null):Void
	{
		super(true);
		if (p_url.indexOf("./") >= 0) p_url = StringTools.replace(p_url, "./", Web.root);		
		url 			= p_url;
		binary  		= p_binary;				
		method  		= p_method.toUpperCase();	
		data			= p_data;
		contentType 	= "";
		bytesTotal 		= 0;
		bytesLoaded		= 0;
		Console.Log("HTTPRequest> " + url,4);
	}
	
	/**
	 * Starts the load task.
	 */
	override public function OnStart():Void 
	{
		try
		{
			request 		= cast (new URL(url)).openConnection();
			request.setRequestMethod(method);					
			contentType = request.getHeaderField("Content-Type");
			request.connect();				
			m_stream	= request.getInputStream();
			bytesTotal 	= cast request.getContentLength();		
		}
		catch (err : Exception)
		{
			error = err;
			OnError();
			Cancel();
			return;
		}
		
		response 	= new ByteArrayOutputStream();			
		m_buffer	= new NativeArray<Int8>(1024);
		
	}
	
	/**
	 * Loading step.
	 */
	override public function OnStep():Void 
	{
		var step : Int = 0;
		try 
		{ 
			step = m_stream.read(m_buffer); 
		} 
		catch (err : Exception) 
		{ 
			error = err;
			OnError();  
			Cancel();
			return;
		}
		
		if (step == 0) return;
		
		if (step < 0)
		{
			bytesLoaded = bytesTotal;
			progress = 1.0;			
			return;
		}
		response.write(m_buffer, 0, step);
		bytesLoaded += step;
		
		var t : Float = cast bytesTotal;
		var l : Float = cast bytesLoaded;
		var r : Float = t <= 0.0 ? 0.0 : (l / t);
		if (r >= 1.0) r = 1.0;
		progress = r * 0.999;
		
		//Console.Log("step> " + bytesLoaded + " " + bytesTotal + " " + progress);
	}
	
	/**
	 * Called when the operation is finished.
	 */
	override public function OnComplete():Void 
	{
		request.disconnect();
		Console.Log("complete!");
		try
		{
			response.flush();
		}
		catch (err : Exception) 
		{ 
			error = err;
			OnError();  
			Cancel();
			return;
		}
		Console.Log(response.size() + " bytes");
		Console.Log(response.toString().substr(0,100));		
	}
	
	/**
	 * Callback called when something went wrong.
	 */
	private function OnError():Void
	{
		Console.Log("HTTPRequest> Error ["+error.getMessage()+"]");
		//request.disconnect();
	}
}


//con.setRequestProperty("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8");
#end