package haxor.io;



#if (windows || osx || linux)
import haxe.io.Bytes;
#end

/**
 * Class that describes a set of bytes represented as 2 byte ints.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Int32Array extends Buffer
{
	/**
	 * Allocates a new FloatBuffer using the passed data as content.
	 * @param	p_data
	 * @return
	 */
	static public function Alloc(p_data : Array<Int>):Int32Array
	{
		var b : Int32Array = new Int32Array(p_data.length);
		b.SetRange(p_data);
		return b;
	}
	
	#if html
	//private var aux : js.html.Int32Array;
	#end
	
	#if android
	private var aux : java.nio.IntBuffer;
	#end

	/**
	 * Long uses 4 bytes.
	 * @return
	 */
	override inline function get_bytesPerElement():Int { return 4; }
	
	/**
	 * Creates a new FloatBuffer with 'length' elements.
	 * @param	p_length
	 */
	public function new(p_length : Int) 
	{
		super(p_length);		
		
		#if html
		aux = new js.html.Int32Array(m_buffer.buffer);
		#end
		
		#if android
		aux = m_buffer.asIntBuffer();
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
		var i32 : js.html.Int32Array = cast aux;
		return i32[p_index];		
		#end
		
		#if windows
		var aux : Bytes = m_buffer;
		var p:Int = p_index * 4;
		untyped __cpp__('
		long v = 0;
		char* ptr = (char*)(&v);
		ptr[0] = (char) aux->b[p];
		ptr[1] = (char) aux->b[p + 1];
		ptr[2] = (char) aux->b[p + 2];
		ptr[3] = (char) aux->b[p + 3];
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
		var i32 : js.html.Int32Array = cast aux;
		i32[p_index] = p_value;
		#end
		
		#if windows
		var aux : Bytes = m_buffer;
		var p:Int = p_index * 4;
		untyped __cpp__('
		long v   = p_value;
		char* ptr = (char*)(&v);
		aux->b[p]   = ptr[0];
		aux->b[p + 1] = ptr[1];		
		aux->b[p + 2] = ptr[2];		
		aux->b[p + 3] = ptr[3];				
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
	 * Adjust the slice selection for int32
	 * @param	p_start
	 * @param	p_length
	 */
	override function SetViewSlice(p_start:Int, p_length:Int):Void 
	{
		super.SetViewSlice(p_start, p_length);		
		#if html
		var i0 : Int = p_start;
		var i1 : Int = i0 + p_length;
		var i32 : js.html.Int32Array = cast aux;		
		aux = i32.subarray(i0, i1);		
		#end
	}
	
}