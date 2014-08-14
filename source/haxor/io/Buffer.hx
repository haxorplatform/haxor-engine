package haxor.io;
import haxor.platform.Types.ArrayBuffer;


#if html
import js.html.Uint8Array;
#end

#if (windows || osx || linux)
import haxe.io.Bytes;
#end

/**
 * Class that manages information as raw bytes.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Buffer
{

	/**
	 * Returns the raw reference of this buffer. Usually the instance is readonly.
	 */
	public var buffer(get_buffer, null):ArrayBuffer;
	private inline function get_buffer():ArrayBuffer { return m_buffer; }
	private var m_buffer : ArrayBuffer;	
	
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
	
	
	/**
	 * Creates a new buffer with 'length' elements with 'offset' bytes each.
	 * @param	p_length
	 * @param	p_offset
	 */
	public function new(p_length : Int) 
	{
		m_length = p_length;
		var len : Int = m_length * bytesPerElement;
		
		#if html		
		m_buffer = new Uint8Array(len);
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
	
}