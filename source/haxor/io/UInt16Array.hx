package haxor.io;

#if (windows || osx || linux)
import haxe.io.Bytes;
#end

/**
 * Class that describes a set of bytes represented as 2 byte ints.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class UInt16Array extends Buffer
{
	/**
	 * Allocates a new FloatBuffer using the passed data as content.
	 * @param	p_data
	 * @return
	 */
	static public function Alloc(p_data : Array<Int>):UInt16Array
	{
		var b : UInt16Array = new UInt16Array(p_data.length);
		b.SetRange(p_data);
		return b;
	}
	
	#if html
	//private var aux : js.html.Uint16Array;
	#end
	
	#if android
	private var aux : java.nio.ShortBuffer;
	#end

	/**
	 * Shorts uses 2 bytes.
	 * @return
	 */
	override inline function get_bytesPerElement():Int { return 2; }
	
	/**
	 * Creates a new FloatBuffer with 'length' elements.
	 * @param	p_length
	 */
	public function new(p_length : Int) 
	{
		super(p_length);		
		
		#if html
		aux = new js.html.Uint16Array(m_buffer.buffer);
		#end
		
		#if android
		aux = m_buffer.asShortBuffer();
		#end
	}
	
	/**
	 * Returns a value at the informed index.
	 * @param	p_index
	 * @return
	 */
	public function Get(p_index : Int):Int
	{
		#if html
		var i16 : js.html.Uint16Array=cast aux;
		return i16[p_index];		
		#end
		
		#if windows
		var aux : Bytes = m_buffer;
		var p:Int = p_index * 2;
		untyped __cpp__('
		int v = 0;
		char* ptr = (char*)(&v);
		ptr[0] = (char) aux->b[p];
		ptr[1] = (char) aux->b[p+1];		
		return v;
		');		
		return 0;
		#end
		
		#if android
		return cast aux.get(p_index);
		#end
	}
	
	/**
	 * Sets a value at the informed index.
	 * @param	p_index
	 * @param	p_value
	 */
	public function Set(p_index : Int, p_value : Int):Void
	{
		#if html
		var i16 : js.html.Uint16Array=cast aux;
		i16[p_index] = p_value;
		#end
		
		#if windows
		var aux : Bytes = m_buffer;
		var p:Int = p_index * 2;
		untyped __cpp__('
		int v   = p_value;
		char* ptr = (char*)(&v);
		aux->b[p]   = ptr[0];
		aux->b[p+1] = ptr[1];		
		');				
		#end
		
		#if android
		aux.put(p_index, p_value);
		#end
	}
	
	/**
	 * Sets a range of values starting at offset.
	 * @param	p_data
	 * @param	p_offset
	 */
	public function SetRange(p_data : Array<Int>, p_offset : Int = 0):Void
	{
		for (i in 0...p_data.length) Set(i + p_offset, p_data[i]);
	}
	
	/**
	 * Adjust the slice selection for int16
	 * @param	p_start
	 * @param	p_length
	 */
	override function SetViewSlice(p_start:Int, p_length:Int):Void 
	{
		super.SetViewSlice(p_start, p_length);		
		#if html
		var i0 : Int = p_start;
		var i1 : Int = i0 + p_length;
		var i16 : js.html.Uint16Array = cast aux;		
		aux = i16.subarray(i0, i1);		
		#end
	}
}