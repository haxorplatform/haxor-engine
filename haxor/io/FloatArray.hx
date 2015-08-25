package haxor.io;
import haxe.crypto.Base64;
import haxor.platform.Types.Float32;



#if (windows || osx || linux)
import haxe.io.Bytes;
#end

/**
 * Class that describes a set of bytes represented as 4 byte floats.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
@:allow(haxor)
class FloatArray extends Buffer
{
		
	/**
	 * Allocates a new FloatBuffer using the passed data as content.
	 * @param	p_data
	 * @return
	 */
	static public function Alloc(p_data : Array<Float32>):FloatArray
	{
		var b : FloatArray = new FloatArray(p_data.length);
		b.SetRange(p_data);
		return b;
	}
	
	/**
	 * Allocates a new array using the specified buffer as input.
	 * @param	p_data
	 * @return
	 */
	static public function AllocBuffer(p_data : Buffer):FloatArray
	{
		var b : FloatArray = new FloatArray(Std.int(p_data.byteLength / 4));
		for (i in 0...p_data.byteLength) b.SetByte(i, p_data.GetByte(i));
		return b;
	}
	
	/**
	 * Creates a new FloatArray using the Base64 encoded data.
	 * @param	p_data
	 * @return
	 */
	static public function FromBase64(p_data : String):FloatArray
	{		
		var b : FloatArray = new FloatArray(Std.int(p_data.length/4));
		b.SetString(p_data);
		b.DecodeBase64();
		return b;
	}
	
	/**
	 * Floats uses 4 bytes.
	 * @return
	 */
	override inline function get_bytesPerElement():Int { return 4; }
	
	#if (html||nodejs)
	//private var aux : js.html.Float32Array;
	#end
	
	#if android
	private var aux : java.nio.FloatBuffer;
	#end

	/**
	 * Resizes this buffer.
	 * @param	p_length
	 */
	override public function Resize(p_length:Int):Void 
	{
		super.Resize(p_length);
		#if (html||nodejs)
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
	public function Get(p_index : Int):Float32
	{
		#if (html||nodejs)
		var f32 : js.html.Float32Array = cast aux;
		return f32[p_index];		
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
	public function Set(p_index : Int, p_value : Float32):Void
	{
		#if (html||nodejs)
		var f32 : js.html.Float32Array = cast aux;
		f32[p_index] = p_value;
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
	public function SetRange(p_data : Array<Float32>, p_offset : Int = 0):Void
	{
		for (i in 0...p_data.length) Set(i + p_offset, p_data[i]);
	}
	
	/**
	 * Returns a dynamic array with this buffer contents.
	 * @return
	 */
	public function ToArray():Array<Float32>
	{
		var res : Array<Float32> = [];
		for (i in 0...length) res.push(Get(i));
		return res;
	}
	
	/**
	 * Adjust the slice selection for floats
	 * @param	p_start
	 * @param	p_length
	 */
	override function SetViewSlice(p_start:Int, p_length:Int):Void 
	{
		super.SetViewSlice(p_start, p_length);		
		#if (html||nodejs)
		var i0 : Int = p_start;
		var i1 : Int = i0 + p_length;
		var f32 : js.html.Float32Array = cast aux;		
		aux = f32.subarray(i0, i1);		
		#end
	}
	
	/**
	 * Parses a string with the required delimiter into a new instance.
	 * @param	p_data
	 * @return
	 */
	static public function Parse(p_data : String,p_delimiter:String=" ",p_is_byte:Bool=false):FloatArray
	{
		var tk : Array<String> = p_data.split(p_delimiter);
		var len : Int = tk.length;		
		var res : FloatArray = new FloatArray(p_is_byte ? Std.int(len/4) : len);		
		for (i in 0...len)
		{
			if (p_is_byte)
			{
				var v : Int = Std.parseInt(StringTools.trim(tk[i]));
				res.SetByte(i,v);
			}
			else
			{
				var v : Float32 = Std.parseFloat(StringTools.trim(tk[i]));
				res.Set(i,v);
			}
		}
		return res;
	}
	
}