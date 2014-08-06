package haxor.io;
import haxor.core.Console;
import haxor.platform.Types.UInt16Buffer;



/**
 * Class that describes a list of Unsigned Int with 2 bytes aligment.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class UInt16Array extends BaseArray implements ArrayAccess<Int>
{
	/**
	 * Creates a UInt16Array using the native array of the platform.
	 * @param	p_data
	 * @return
	 */
	static public function Create(p_data : Array<Int>):UInt16Array
	{
		var a : UInt16Array = new UInt16Array(p_data.length);
		a.Set(p_data);		
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
	private var b : UInt16Buffer;
	
	/**
	 * 
	 * @param	p_capacity
	 */
	public function new(p_capacity:Int):Void
	{ 
		#if html
		b = new UInt16Buffer(p_capacity);
		#end
		
		#if android
		b = java.nio.ByteBuffer
		.allocateDirect(p_capacity * 2)
		.order(java.nio.ByteOrder.nativeOrder())
		.asShortBuffer();	
		#end
		
		#if windows
		m_length = p_capacity;
		var arr : Array<UInt> = [];
		for (i in 0...m_length) arr.push(0);
		b = cpp.Pointer.fromArray(arr,0);
		#end
	}
	
	/**
	 * Creates a new array with the same content.
	 * @return
	 */
	public function Clone():UInt16Array
	{
		var a : UInt16Array = new UInt16Array(length);
		for (i in 0...length) a.array_set(i,array_get(i));
		return a;
	}
	
	/**
	 * Sets the Array contents with the passed data.
	 * @param	p_data
	 */
	@:overload(function(p_data : UInt16Array):Void { })
	public function Set(p_data : Array<Int>):Void
	{		
		for (i in 0...p_data.length) array_set(i,p_data[i]);
	}
	
	@:arrayAccess 
	public inline function array_get(k:Int) : Int
	{ 
		#if html
		return b[k];
		#end		
		#if android
		return cast b.get(k);
		#end		
		#if windows
		return b[k];
		#end
	}
	
	@:arrayAccess 
	public inline function array_set(k:Int, v:Int):Int 
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
		return v; 
	}
}


