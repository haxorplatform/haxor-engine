#if android

package haxor.platform.android;
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
import java.net.URL;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import android.graphics.BitmapFactory;
import android.graphics.Bitmap;
import java.lang.StringBuilder;
/**
 * 
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Web
{
	/**
	 * Root path that will replace the './' string in URLs.
	 */
	static public var root : String="";

	/**
	 * 
	 * @param	p_url
	 * @param	p_callback
	 */
	static public function Load(p_url:String, p_callback : String->Float->Void):Void { var ld : LoadStringTask = new LoadStringTask(p_url,"GET","",p_callback); }
    
}

class LoadTask implements Runnable
{	
	public var thread 		: Thread;		
	public var url 			: String;
	public var method 		: String;
	public var data 		: String;
	public var contentType  : String;
	public var stream 		: InputStream;
	public var bytesTotal	: Int;
	public function new(p_url:String,p_method : String,p_data : String):Void
	{
		url = StringTools.replace(p_url, "./", Web.root);
		method = p_method;
		data = p_data;
		
		Console.Log("Web> Load from [" + url+"]",1);		
		thread = new Thread(this);
		thread.start();
	}
	
	@override
	public function run():Void
	{	
		try
		{
			
			var con : HttpURLConnection = cast (new URL(url)).openConnection();
			con.setRequestMethod(method);			
			con.setRequestProperty("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8");
			//con.setDoInput(true);
			//con.setDoOutput(true);
			//if(data !="") {} //send
			contentType = con.getHeaderField("Content-Type");
			con.connect();				
			stream = con.getInputStream();
			bytesTotal = cast con.getContentLength();
			OnConnect(con);
			con.disconnect();
			OnComplete();
		
		}
		catch (err : Exception)
		{
			OnError(err);
		}
	}
	
	private function OnProgress(p_ratio:Float,p_loaded : Int,p_total:Int):Void { }
	private function OnConnect(p_connection : HttpURLConnection):Void { }
	private function OnComplete():Void { }
	private function OnError(p_error : Exception):Void
	{
		Console.LogError("Web> "+p_error.getMessage());		
	}
}

/**
 * Aux class to handle async string loading.
 */
class LoadStringTask extends LoadTask
{	
	public var result : String;
	public var callback : String -> Float-> Void;
	
	public function new(p_url:String,p_method : String,p_data : String,p_callback : String->Float->Void):Void
	{
		super(p_url, p_method, p_data);
		callback = p_callback;
	}
	
	override inline function OnConnect(p_connection:HttpURLConnection):Void 
	{
		result	= "";		
		var con 	: HttpURLConnection = p_connection;				
		var buffer  : BufferedReader 	= new BufferedReader(new InputStreamReader(stream));				
		var loaded  : Float 			= 0.0;			
		var l 		: String 			= "";		
		var lines	: Array<String>		= [];
		callback(null,0.0);
		while (true)
		{				
			try { l = buffer.readLine(); } catch (err : Exception) { OnError(err);  }							
			if (l == null) break;			
			lines.push(l);				
			loaded += l.length;		
			var t : Float = bytesTotal;
			var r : Float = t <= 0.0 ? 0.0 : (loaded / t);
			if (r >= 1.0) r = 1.0;
			OnProgress(r, l.length, bytesTotal);
			if(bytesTotal>=0) callback(null, r*0.99);
		}
		result = lines.join("\n");
	}
	
	override function OnComplete():Void 
	{		
		callback(result, 1.0);
	}
	
	override function OnError(p_error:Exception):Void 
	{
		super.OnError(p_error);
		callback(null, 1.0);
	}
}

class LoadBytesTask extends LoadTask
{
	public var output : ByteArrayOutputStream;
	
	override public function OnConnect(p_connection:HttpURLConnection):Void 
	{
		output	= new ByteArrayOutputStream();		
		var con 	: HttpURLConnection = p_connection;								
		var loaded  : Float 			= 0.0;	
		var step 	: Int				= 0;
		var buffer  : NativeArray<Int8> = new NativeArray<Int8>(1024);
		while (true)
		{	
			try { step = stream.read(buffer); } catch (err : Exception) { OnError(err);  }
			if(step < 0) break;			
			loaded += step;
			var t : Float = cast bytesTotal;
			var r : Float = t <= 0.0 ? 0.0 : (loaded / t);
			if (r >= 1.0) r = 1.0;
			OnProgress(r, step, bytesTotal);			
		}		
	}
}

class LoadImageTask extends LoadBytesTask
{
	public var callback : Buffer -> Float-> Void;
	
	public function new(p_url:String,p_method : String,p_data : String,p_callback : Buffer->Float->Void):Void
	{
		super(p_url, p_method, p_data);
		callback = p_callback;
	}
	
	override function OnConnect(p_connection:HttpURLConnection):Void 
	{
		callback(null,0.0);
		super.OnConnect(p_connection);
	}
	
	override function OnProgress(p_ratio:Float, p_loaded:Int, p_total:Int):Void 
	{
		callback(null, p_ratio);
	}
	
	override function OnComplete():Void 
	{
		var bl : NativeArray<Int8> = output.toByteArray();		
		var img : Bitmap = BitmapFactory.decodeByteArray(bl,0,bl.length);
		//var buffer : Buffer = new Buffer(bl.length);
		//for (i in 0...bl.length) buffer.SetByte(i, bl[i]);
	}
	
	override function OnError(p_error:Exception):Void 
	{
		super.OnError(p_error);
		callback(null, 1.0);
	}
}

#end