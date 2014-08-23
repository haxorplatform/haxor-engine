package haxor.io;



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
	//private var aux : js.html.Float32Array;
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
	public function Set(p_index : Int, p_value : Float):Void
	{
		#if html
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
	public function SetRange(p_data : Array<Float>, p_offset : Int = 0):Void
	{
		for (i in 0...p_data.length) Set(i + p_offset, p_data[i]);
	}
	
	/**
	 * Adjust the slice selection for floats
	 * @param	p_start
	 * @param	p_length
	 */
	override function SetViewSlice(p_start:Int, p_length:Int):Void 
	{
		super.SetViewSlice(p_start, p_length);		
		#if html
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
	static public function Parse(p_data : String,p_delimiter:String=" "):FloatArray
	{
		var tk : Array<String> = p_data.split(p_delimiter);
		var res : FloatArray = new FloatArray(tk.length);
		for (i in 0...tk.length) res.Set(i,Std.parseFloat(StringTools.trim(tk[i])));
		return res;
	}
	
}