package haxor.io;
import haxor.core.Console;
import haxor.platform.Types.Int32Buffer;
import haxor.platform.Types.UInt16Buffer;



/**
 * Class that describes a list of Signed Int with 4 bytes aligment.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Int32Array extends BaseArray
{
	/**
	 * Creates a UInt16Array using the native array of the platform.
	 * @param	p_data
	 * @return
	 */
	static public function Create(p_data : Array<Int>):Int32Array
	{
		var a : Int32Array = new Int32Array(p_data.length);
		a.Fill(p_data);		
		return a;
	}
		
	#if android	
	override inline function get_length():Int { return b.capacity(); }	
	#end
	#if html	
	override inline function get_length():Int { return b.length; }
	#end
	
	#if windows
	override inline function get_length():Int { return m_length; }	
	private var m_length : Int;
	#end
	
	override inline function get_type():String { return "int"; }
	
	
	/**
	 * Internal array.
	 */
	private var b : Int32Buffer;
	
	/**
	 * 
	 * @param	p_capacity
	 */
	public function new(p_capacity:Int):Void
	{ 
		#if html
		b = new Int32Buffer(p_capacity);
		#end
		
		#if android
		b = java.nio.ByteBuffer
		.allocateDirect(p_capacity * 4)
		.order(java.nio.ByteOrder.nativeOrder())
		.asIntBuffer();	
		#end
		
		#if windows
		m_length = p_capacity;
		var arr : Array<Int> = [];
		for (i in 0...m_length) arr.push(0);
		b = cpp.Pointer.fromArray(arr,0);
		#end
	}
	
	/**
	 * Creates a new array with the same content.
	 * @return
	 */
	public function Clone():Int32Array
	{
		var a : Int32Array = new Int32Array(length);
		for (i in 0...length) a.Set(i,Get(i));
		return a;
	}
	
	/**
	 * Sets the Array contents with the passed data.
	 * @param	p_data
	 */	
	public function Fill(p_data : Array<Int>):Void
	{		
		for (i in 0...p_data.length) Set(i,p_data[i]);
	}
	
	/**
	 * 
	 * @param	k
	 * @return
	 */
	public inline function Get(k:Int) : Int
	{ 
		var v : Int = 0;
		#if html
		return b[k];
		#end		
		#if android
		return b.get(k);	
		#end		
		#if windows
		return b[k];
		#end
	}
	
 
	/**
	 * 
	 * @param	k
	 * @param	v
	 */
	public inline function Set(k:Int, v:Int):Void 
	{ 			
		#if html
		b[k] = v; 
		#end		
		#if android			
		b.put(k, v);
		#end		
		#if windows
		b[k] = v; 
		#end		
	}
}


