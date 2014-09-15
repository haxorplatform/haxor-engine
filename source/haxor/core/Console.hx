package haxor.core;
import haxe.Timer;
import haxor.platform.Types.Float32;



/**
 * Wrapper class for log and console operations.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Console
{
	#if html
	static var m_console 		: js.html.Console;
	static private var m_style 	: String		 	= "";
	
	//static public var field : js.html.DivElement;
	
	#else
	
	static private var m_benchmarks : Map<String,Float>;
	
	#end
	
	/**
	 * Initializes the internal structure of the console class.
	 */
	static private function Initialize():Void
	{
		var c : Dynamic = 
		{
			log : function(s:String):Void {}
		};		
		
		try
		{
			m_console = untyped __js__("console");
		}
		catch (err:Dynamic)
		{
			m_console = c;
		}
		
		#if html
		
		//field = cast js.Browser.document.getElementById("field");
		
		
		#else		
		m_benchmarks = new Map<String,Float>();
		#end
	}
	
	/**
	 * Verbose Level.
	 */
	static public var verbose : Int = 0;
	
	/**
	 * HTML Platform Only.
	 * Adds a breakpoint directive to debug the desired line of code.
	 */
	static public inline function Breakpoint():Void 
	{ 
		#if html
		untyped __js__("debugger");  
		#end
	}
	
	/**
	 * Outputs the message if its level is equal or greater than the verbose level.
	 * @param	p_msg
	 * @param	p_level
	 */
	static public function Log(p_msg : String, p_level:Int = 0):Void 
	{ 
		if (verbose >= p_level)
		{
			#if js
			m_console.log(p_msg);
			#end
			
			#if android
			//Sys.stdout().writeString(p_msg+"\n");
			//Sys.stdout().flush();
			untyped __java__('
			android.util.Log.v("TRACE", p_msg);			
			');
			#end
			
			#if cpp
			cpp.Lib.println(p_msg);
			#end
			
		}
	}
	
	/**
	 * HTML Platform Only.
	 * Logs an image in the browser console.
	 * @param	p_url
	 * @param	p_height
	 */
	static public function LogImage(p_url : String,p_height : Int):Void
	{
		#if html
		var s : String = "background: transparent url(" + p_url + ") no-repeat; font-size: " + (p_height-3) + "px;";
		m_console.log("%c                                                                                                                                                            ", s);
		#end
	}
	
	/**
	 * Logs a warning message.
	 * @param	p_msg
	 * @param	p_obj
	 */
	static public function LogWarning(p_msg : String, p_obj : Array<Dynamic> = null) : Void
	{
		#if html
		if (m_console == null) { trace("[W] " + p_msg); }
		if (p_obj == null) p_obj = [];
		switch(p_obj.length)
		{
			case 0:  m_console.warn(p_msg);
			case 1:  m_console.warn(p_msg, p_obj[0]);
			case 2:  m_console.warn(p_msg,p_obj[0],p_obj[1]);
			case 3:  m_console.warn(p_msg,p_obj[0],p_obj[1],p_obj[2]);
			case 4:  m_console.warn(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3]);			
		}
		#else
		Log("[W] " + p_msg);
		#end
	}
	
	/**
	 * Logs an error message.
	 * @param	p_msg
	 */
	static public function LogError(p_msg : String, p_obj : Array<Dynamic> = null) : Void
	{
		#if html
		if (m_console == null) { trace("[E] " + p_msg); return; }
		if (p_obj == null) p_obj = [];
		switch(p_obj.length)
		{
			case 0:  m_console.error(p_msg);
			case 1:  m_console.error(p_msg, p_obj[0]);
			case 2:  m_console.error(p_msg,p_obj[0],p_obj[1]);
			case 3:  m_console.error(p_msg,p_obj[0],p_obj[1],p_obj[2]);
			case 4:  m_console.error(p_msg,p_obj[0],p_obj[1],p_obj[2],p_obj[3]);			
		}
		#else
		Log("[E] " + p_msg);
		#end
	}
	
	/**
	 * HTML Platform Only.
	 * Clears the text style of the console.
	 */
	static public function ClearStyle():Void
	{
		#if html
		m_style = "";
		#end
	}
	
	/**
	 * Clears the output console.
	 */
	static public function Clear():Void
	{
		#if html
		if (m_console != null) m_console.clear();
		#end
		
		#if android
		#end
		
		#if (windows || osx || linux)
		#end
	}
	
	/**
	 * Begins a benchmark with a given id.
	 * @param	p_msg
	 */
	static public function TimeStart(p_id : String):Void
	{
		#if html
		if (m_console != null) m_console.time(p_id);
		#else
		if (m_benchmarks.exists(p_id)) return;
		m_benchmarks.set(p_id, Timer.stamp());
		#end
		
	}
	
	/**
	 * Finishes the benchmark with given id.
	 * @param	p_id
	 */
	static public function TimeEnd(p_id : String):Void
	{
		#if html
		if (m_console != null) m_console.timeEnd(p_id);
		#else
		if (!m_benchmarks.exists(p_id)) return;
		var t: Float32 = m_benchmarks.get(p_id);
		m_benchmarks.remove(p_id);
		Log(p_id + ": " + Math.floor(t * 1000.0) + "ms");
		#end
	}
	
	/**
	 * Prints the stack trace.
	 */
	static public inline function StackTrace() : Void
	{
		#if html
		if (m_console != null) m_console.trace();
		#end
		
		#if android
		Log(java.util.Arrays.toString(java.lang.Thread.currentThread().getStackTrace()),0);		
		#end
		
		#if (windows || osx || linux)
		#end
	}
	
	/**
	 * HTML Platform Only.
	 * Sets the print style of the browser console.
	 */
	static public function SetStyle(p_size : String = "12px", p_color : String = "rgba(0,0,0,1)",p_background : String = "rgba(255,255,255,0)", p_font : String = "'Lucida Console', Monaco, monospace"):Void
	{
		#if html				
		m_style = "background-color: " + p_background + "; font-size: " + p_size + "; color: " + p_color + "; font-family: " + p_font + ";";
		#end
	}
	
	
}
