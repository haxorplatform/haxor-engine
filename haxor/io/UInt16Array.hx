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
	
	/**
	 * Allocates a new array using the specified buffer as input.
	 * @param	p_data
	 * @return
	 */
	static public function AllocBuffer(p_data : Buffer):UInt16Array
	{
		var b : UInt16Array = new UInt16Array(Std.int(p_data.byteLength / 2));
		for (i in 0...p_data.byteLength) b.SetByte(i, p_data.GetByte(i));
		return b;
	}
	
	#if (html||nodejs)
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
	 * Resizes this buffer to a new size.
	 * @param	p_length
	 */
	override public function Resize(p_length:Int):Void 
	{
		super.Resize(p_length);
		#if (html||nodejs)
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
		#if (html||nodejs)
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
		#if (html||nodejs)
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
	 * Returns a dynamic array with this buffer contents.
	 * @return
	 */
	public function ToArray():Array<Int>
	{
		var res : Array<Int> = [];
		for (i in 0...length) res.push(Get(i));
		return res;
	}
	
	/**
	 * Adjust the slice selection for int16
	 * @param	p_start
	 * @param	p_length
	 */
	override function SetViewSlice(p_start:Int, p_length:Int):Void 
	{
		super.SetViewSlice(p_start, p_length);		
		#if (html||nodejs)
		var i0 : Int = p_start;
		var i1 : Int = i0 + p_length;
		var i16 : js.html.Uint16Array = cast aux;		
		aux = i16.subarray(i0, i1);		
		#end
	}
	
	/**
	 * Parses a string with the required delimiter into a new instance.
	 * @param	p_data
	 * @return
	 */
	static public function Parse(p_data : String,p_delimiter:String=" ",p_is_byte:Bool=false):UInt16Array
	{
		var tk : Array<String> = p_data.split(p_delimiter);
		var len : Int = tk.length;
		var res : UInt16Array = new UInt16Array(p_is_byte ? Std.int(len/2) : len);		
		for (i in 0...len)
		{
			if (p_is_byte)
			{
				var v : Int = Std.parseInt(StringTools.trim(tk[i]));
				res.SetByte(i,v);
			}
			else
			{
				var v : Int = Std.parseInt(StringTools.trim(tk[i]));
				res.Set(i,v);
			}
		}
		return res;
	}
}