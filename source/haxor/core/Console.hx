package haxor.core;



/**
 * Wrapper class for log and console operations.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Console
{
	/**
	 * Verbose Level.
	 */
	static public var verbose : Int = 0;
	
	
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
			trace(p_msg); 
			#end
			
			#if java
			Sys.stdout().writeString(p_msg+"\n");
			Sys.stdout().flush();
			untyped __java__('
			android.util.Log.v("TRACE", p_msg);			
			');
			#end
			
			#if cpp
			cpp.Lib.println(p_msg);
			#end
			
		}
	}
	
	
}
