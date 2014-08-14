package haxor.io;

#if (windows || osx || linux)
import haxe.io.Bytes;
#end

/**
 * Class that describes a set of bytes represented as 4 byte floats.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class FloatArray extends Buffer
{
		
	/**
	 * Allocates a new FloatBuffer using the passed data as content.
	 * @param	p_data
	 * @return
	 */
	static public function Alloc(p_data : Array<Float>):FloatArray
	{
		var b : FloatArray = new FloatArray(p_data.length);
		b.SetRange(p_data);
		return b;
	}
	
	/**
	 * Floats uses 4 bytes.
	 * @return
	 */
	override inline function get_bytesPerElement():Int { return 4; }
	
	#if html
	private var aux : js.html.Float32Array;
	#end
	
	#if android
	private var aux : java.nio.FloatBuffer;
	#end

	/**
	 * Creates a new FloatBuffer with 'length' elements.
	 * @param	p_length
	 */
	public function new(p_length : Int) 
	{
		super(p_length);
				
		#if html
		aux = new js.html.Float32Array(m_buffer.buffer);
		#end
		
		#if android
		aux = m_buffer.asFloatBuffer();
		#end
	}
	
	/**
	 * Gets a value at the position.
	 * @param	p_index
	 * @return
	 */
	public function Get(p_index : Int):Float
	{
		#if html
		return aux[p_index];		
		#end
		
		#if windows
		var aux : Bytes = m_buffer;
		var p:Int = p_index * 4;
		untyped __cpp__('
		float v = 0.0;
		char* ptr = (char*)(&v);
		ptr[0] = (char) aux->b[p];
		ptr[1] = (char) aux->b[p+1];
		ptr[2] = (char) aux->b[p+2];
		ptr[3] = (char) aux->b[p+3];
		return v;
		');		
		return 0.0;
		#end
		
		#if android
		return aux.get(p_index);
		#end
	}
	
	/**
	 * Sets a single value at a position.
	 * @param	p_index
	 * @param	p_value
	 */
	public function Set(p_index : Int, p_value : Float):Void
	{
		#if html
		aux[p_index] = p_value;
		#end
		
		#if windows
		var aux : Bytes = m_buffer;
		var p:Int = p_index * 4;
		untyped __cpp__('
		float v   = p_value;
		char * ptr = (char * )( & v);		
		aux->b[p]   = ptr[0];
		aux->b[p+1] = ptr[1];
		aux->b[p+2] = ptr[2];
		aux->b[p+3] = ptr[3];
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
	public function SetRange(p_data : Array<Float>, p_offset : Int = 0):Void
	{
		for (i in 0...p_data.length) Set(i + p_offset, p_data[i]);
	}
	
}