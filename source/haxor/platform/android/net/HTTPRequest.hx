#if android

package haxor.platform.android.net;
import haxor.platform.Types.Float32;

import haxor.net.HTTPRequestTask;

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
 * Base class for HTML load operations.
 */
class HTTPRequest extends HTTPRequestTask<HttpURLConnection,ByteArrayOutputStream>
{	
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
		super(p_url, p_method, p_binary, p_data);		
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
			request.connect();				
			m_stream	= request.getInputStream();
			bytesTotal 	= cast request.getContentLength();		
		}
		catch (err : Exception)
		{
			error = err.getMessage();
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
			error = err.getMessage();
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
		var t : Float32 = cast bytesTotal;
		var l : Float32 = cast bytesLoaded;
		var r : Float32 = t <= 0.0 ? 0.0 : (l / t);
		if (r >= 1.0) r = 1.0;
		progress = r * 0.999;
	}
	
	/**
	 * Called when the operation is finished.
	 */
	override public function OnComplete():Void 
	{
		request.disconnect();		
		try { response.flush(); }
		catch (err : Exception) 
		{ 
			error = err.getMessage();
			OnError();  
			Cancel();			
		}		
	}	
}

#end