package haxor.io;

/**
 * Interface that 
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class BaseArray
{	
	/**
	 * Length of the array
	 */
	public var length(get, never):Int;
	function get_length():Int { return 0; }
	
	/**
	 * Type of the array content.
	 */
	public var type(get, never):String;
	function get_type():String { return ""; }
}