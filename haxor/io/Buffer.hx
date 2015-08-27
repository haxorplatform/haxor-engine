package haxor.io;
import haxe.crypto.Base64;
import haxor.math.Mathf;
import haxor.platform.Types.ArrayBuffer;
import haxe.io.Bytes;


#if (html||nodejs)
import js.html.Uint8ClampedArray;
import js.html.Uint8Array;
#end

#if (windows || osx || linux)
#end

/**
 * Class that manages information as raw bytes.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class Buffer
{

	/**
	 * Creates a new buffer using the informed string as data.
	 * @param	p_string
	 * @return
	 */
	static public function FromString(p_string:String):Buffer
	{
		var b : Buffer = new Buffer(p_string.length);
		b.SetString(p_string);
		return b;		
	}
	
	/**
	 * Allocates a new array using the specified buffer as input.
	 * @param	p_data
	 * @return
	 */
	static public function AllocBuffer(p_data : Buffer):Buffer
	{
		var b : Buffer = new Buffer(Std.int(p_data.byteLength));
		for (i in 0...p_data.byteLength) b.SetByte(i, p_data.GetByte(i));
		return b;
	}
	
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
	
	#if (html||nodejs)
	private var aux  : js.html.ArrayBufferView;	
	private var orig : js.html.ArrayBufferView;
	#end
	
	/**
	 * Creates a new buffer with 'length' elements with 'offset' bytes each.
	 * @param	p_length
	 * @param	p_offset
	 */
	public function new(p_length : Int) 
	{
		Resize(p_length);
	}
	
	/**
	 * Prepares this buffer data with a new length. The old data is discarded.
	 * @param	p_length
	 */
	public function Resize(p_length:Int):Void
	{
		m_length = p_length;
		var len : Int = m_length * bytesPerElement;
		m_offset = 0;
		
		#if (html||nodejs)		
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
		#if (html||nodejs)
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
		#if (html||nodejs)
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
	 * Sets the content of this buffer with the informed byte list.
	 * @param	p_list
	 */
	public function SetBytes(p_list:Array<Int>,p_offset:Int=0):Void
	{
		for (i in 0...p_list.length) SetByte(i+p_offset, p_list[i]);
	}
	
	/**
	 * Fills the contents of this buffer with the target buffer.
	 * @param	p_target
	 */
	public function SetBuffer(p_target:Buffer,p_offset:Int=0):Void
	{
		for (i in 0...p_target.byteLength) SetByte(i+p_offset, p_target.GetByte(i));
	}
	
	/**
	 * Encodes the contents of this Buffer into Base64 and resize it to fit the new format. Returns the encoded string.
	 * @return
	 */
	public function EncodeBase64():String 
	{
		var b : Bytes = Bytes.alloc(byteLength);
		for (i in 0...b.length) b.set(i, GetByte(i));
		var res : String = Base64.encode(b);
		var new_len : Int = Std.int(res.length / bytesPerElement);		
		Resize(new_len);
		SetString(res);
		return res;		
	}
	
	/**
	 * Decodes the current bytes of this buffer and resize it to fit the new data.
	 * @return
	 */
	public function DecodeBase64():Void 
	{		
		var b64:String 		= GetString();		
		var b : Bytes 		= Base64.decode(b64);
		var new_len : Int 	= Std.int(b.length / bytesPerElement);
		Resize(new_len);
		for (i in 0...b.length) SetByte(i, b.get(i));				
		
	}
	
	/**
	 * Returns the bytes of this buffer represented as string.
	 * @param	p_length
	 * @return
	 */
	public function GetString(p_offset:Int=0,p_length:Int = 0) : String 
	{
		var len : Int = p_length <= 0 ? byteLength : p_length; 
		var s : StringBuf = new StringBuf();
		for (i in 0...len) s.addChar(GetByte(i+p_offset));	
		return s.toString();
	}
	
	/**
	 * Sets the buffer with the bytes of the informed string, starting at offset.
	 * @param	p_string
	 * @param	p_offset
	 */
	public function SetString(p_string:String, p_offset:Int = 0):Void
	{
		for (i in 0...p_string.length)
		{
			SetByte(i+p_offset, p_string.charCodeAt(i));
		}
	}
	
	/**
	 * Converts the byte contents to array.
	 * @return
	 */
	public function ToByteArray():Array<Int>
	{
		var res : Array<Int> = [];
		for (i in 0...byteLength) res.push(GetByte(i));
		return res;
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
		#if (html||nodejs)				
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
		#if (html||nodejs)		
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
	
	/**
	 * Parses a string with the required delimiter into a new instance.
	 * @param	p_data
	 * @return
	 */
	static public function Parse(p_data : String,p_delimiter:String=" ",p_is_byte:Bool=false):Buffer
	{
		var tk : Array<String> = p_data.split(p_delimiter);
		var len : Int = tk.length;		 
		var res : Buffer = new Buffer(len);		
		for (i in 0...len)
		{
			var v : Int = Std.parseInt(StringTools.trim(tk[i]));
			res.SetByte(i,v);
		}
		return res;
	}
	
}