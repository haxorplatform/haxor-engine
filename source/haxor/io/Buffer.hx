package haxor.io;
import haxor.platform.Types.ArrayBuffer;



#if html
import js.html.Uint8ClampedArray;
import js.html.Uint8Array;
#end

#if (windows || osx || linux)
import haxe.io.Bytes;
#end

/**
 * Class that manages information as raw bytes.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Buffer
{

	/**
	 * Returns the raw reference of this buffer. Usually the instance is readonly.
	 */
	public var buffer(get_buffer, null):ArrayBuffer;
	private inline function get_buffer():ArrayBuffer { return m_buffer; }
	private var m_buffer : ArrayBuffer;		
	private var m_original : ArrayBuffer;		
	private var m_offset : Int;
	/**
	 * Returns the size of the buffer in bytes.
	 */
	public var byteLength(get_byteLength, null):Int;
	private inline function get_byteLength():Int { return length * bytesPerElement; }	
	
	/**
	 * Returns the number of bytes of each element.
	 */
	public var bytesPerElement(get_bytesPerElement, null):Int;
	private function get_bytesPerElement():Int { return 1; }
	
	
	/**
	 * Returns the number of elements of this buffer. The value is related to the number of bytes per element of this Buffer.
	 */
	public var length(get_length, null):Int;
	private inline function get_length():Int { return m_length; }
	private var m_length : Int;
	
	#if html
	private var aux : js.html.ArrayBufferView;	
	private var orig : js.html.ArrayBufferView;
	#end
	
	/**
	 * Creates a new buffer with 'length' elements with 'offset' bytes each.
	 * @param	p_length
	 * @param	p_offset
	 */
	public function new(p_length : Int) 
	{
		m_length = p_length;
		var len : Int = m_length * bytesPerElement;
		m_offset = 0;
		
		#if html		
		m_buffer = new Uint8Array(len);
		aux = m_buffer;
		#end
		
		#if windows
		m_buffer = haxe.io.Bytes.alloc(len);
		#end
		
		#if android
		m_buffer = java.nio.ByteBuffer.allocateDirect(len).order(java.nio.ByteOrder.nativeOrder());		
		#end
		
	}
	
	/**
	 * Returns a byte value at the informed position.
	 * @param	p_index
	 * @return
	 */
	public function GetByte(p_index : Int) : Int
	{
		#if html
		return m_buffer[p_index];
		#end
		
		#if windows
		return m_buffer.get(p_index);
		#end
		
		#if android
		return cast m_buffer.get(p_index);
		#end
		
		return 0;
	}
	
	/**
	 * Sets a byte in the informed position.
	 * @param	p_index
	 * @param	p_value
	 */
	public function SetByte(p_index : Int, p_value : Int):Void
	{
		#if html
		m_buffer[p_index] = p_value;		
		#end
		
		#if windows
		m_buffer.set(p_index, p_value);
		#end
		
		#if android
		m_buffer.put(p_index, p_value);
		#end
	}
	
	/**
	 * Sets the interval of data to be used in API methods like TexSubImage and BufferSubData
	 * @param	p_start
	 * @return
	 */
	private function SetViewSlice(p_start : Int,p_length:Int):Void
	{
		var i0 : Int = p_start * bytesPerElement;
		var i1 : Int = i0 + p_length * bytesPerElement;
		#if html				
		orig = aux;
		if (bytesPerElement == 1)
		{
			var i8 : Uint8Array = cast aux;
			aux = i8.subarray(i0, i1);
		}
		#end
		
		#if windows				
		//Needs to treat in the GL class because of pointers.
		m_offset = i0;
		#end
		
		#if android		
		m_original = m_buffer;	
		m_buffer.position(i0);
		m_buffer.limit(i1);
		m_buffer = m_buffer.slice();
		#end
	}
	
	/**
	 * Resets the buffer to its original start and end limits.
	 */
	private function ResetSlice():Void
	{
		#if html		
		aux = orig;
		#end
		
		#if windows				
		//Needs to treat in the GL class because of pointers.
		m_offset = 0;
		#end
		
		#if android
		m_buffer = m_original;
		#end
	}
	
}