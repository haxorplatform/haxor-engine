package haxor.io;
import haxe.io.BytesBuffer;
import haxe.io.BytesInput;
import haxor.core.Console;
import haxor.platform.Types.Float32Buffer;



/**
 * Class that describes a list of Floats with 4 bytes aligment.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class FloatArray extends BaseArray
{
	/**
	 * Creates a FloatArray using the native array of the platform.
	 * @param	p_data
	 * @return
	 */
	static public function Create(p_data : Array<Float>):FloatArray
	{
		var a : FloatArray = new FloatArray(p_data.length);
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
	
	/**
	 * Type of array content.
	 */	
	override inline function get_type():String { return "float"; }
		
	/**
	 * Internal buffer.
	 */
	public var b : Float32Buffer;
	
	/**
	 * 
	 * @param	p_capacity
	 */
	public function new(p_capacity:Int):Void
	{ 		
		#if html
		b = new Float32Buffer(p_capacity);
		#end
		
		#if android
		b = java.nio.ByteBuffer
		.allocateDirect(p_capacity * 4)
		.order(java.nio.ByteOrder.nativeOrder())
		.asFloatBuffer();	
		#end
		
		#if windows
		m_length = p_capacity;
		var arr : Array<Float> = [];
		for (i in 0...m_length) arr.push(0.0);
		b = cpp.Pointer.fromArray(arr,0);
		#end
	}
	
	/**
	 * Creates a new array with the same content.
	 * @return
	 */
	public function Clone():FloatArray
	{
		var a : FloatArray = new FloatArray(length);		
		for (i in 0...length)
		{
			var n : Float = Get(i);
			a.Set(i,n);
		}
		return a;
	}
	
	/**
	 * Sets the Array contents with the passed data.
	 * @param	p_data
	 */	
	public function Fill(p_data : Array<Float>):Void
	{	
		for (i in 0...p_data.length)
		{
			Set(i, p_data[i]);
		}
	}
	
	/**
	 * 
	 * @param	k
	 * @return
	 */
	public inline function Get(k:Int) : Float
	{ 
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
	 * @return
	 */
	public inline function Set(k:Int, v:Float):Void 
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


