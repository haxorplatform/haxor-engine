package haxor.graphics.texture;
import haxor.core.Resource;
import haxor.graphics.Enums.PixelFormat;
import haxor.io.Buffer;
import haxor.io.FloatArray;
import haxor.math.Color;
import haxor.math.Mathf;

/**
 * Class that describes a container for pixels with each channel made of bytes or floats.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Bitmap extends Resource
{

	/**
	 * Reference to the raw buffer of this class. If the chosen content is float, the reference of the Buffer will be a FloatArray.
	 */
	public var buffer(get_buffer, null):Buffer;
	private function get_buffer():Buffer { return m_buffer; }
	private var m_buffer : Buffer;
	
	/**
	 * Flag that indicates if the Bitmap pixels are made of floats.
	 */
	public var float(get_float, null):Bool;
	private inline function get_float():Bool { return m_float; }
	private var m_float : Bool;
	
	/**
	 * Bitmap width.
	 */
	public var width(get_width, null):Int;
	private inline function get_width():Int { return m_width; }
	private var m_width : Int;
	
	/**
	 * Bitmap height.
	 */
	public var height(get_height, null):Int;
	private inline function get_height():Int { return m_height; }
	private var m_height : Int;
	
	/**
	 * Number of channels per pixel.
	 */
	public var channels(get_channels, null):Int;
	private inline function get_channels():Int { return m_channels; }
	private var m_channels : Int;
	
	/**
	 * Pixel format of this bitmap.
	 */
	public var format(get_format, null):PixelFormat;
	private inline function get_format():PixelFormat { return m_format; }
	private var m_format : PixelFormat;
	
	/**
	 * * Creates a new Bitmap with the informed width and height.
	 * The contents of this class can be bytes or floats depending on the specified format.
	 * @param	p_width
	 * @param	p_height
	 * @param	p_format
	 */
	public function new(p_width:Int,p_height:Int,p_format : PixelFormat) 
	{
		super();
		m_width  	= p_width;
		m_height 	= p_height;				
		m_format 	= p_format;
		m_float		= false;
		m_channels 	= 1;		
		switch (p_format)
		{
			case PixelFormat.Luminance: m_channels = 1;
			case PixelFormat.Alpha8: 	m_channels = 1;
			case PixelFormat.RGB8: 		m_channels = 3;
			case PixelFormat.RGBA8: 	m_channels = 4;			
			case PixelFormat.Depth:	{ m_channels = 1; m_float = true; }
			case PixelFormat.Float: { m_channels = 1; m_float = true; }
			case PixelFormat.Half:  { m_channels = 1; m_float = true; }
			case PixelFormat.Float3:{ m_channels = 3; m_float = true; }
			case PixelFormat.Half3:	{ m_channels = 3; m_float = true; }
			case PixelFormat.Float4:{ m_channels = 4; m_float = true; }
			case PixelFormat.Half4:	{ m_channels = 4; m_float = true; }			
			
		}				
		var len : Int = m_width * m_height * m_channels;		
		m_buffer = m_float ? (new FloatArray(len)) : (new Buffer(len));		
	}
	
	/**
	 * Gets a pixel in the informed coordinate.
	 * @param	p_x
	 * @param	p_y
	 * @return
	 */
	public function GetPixel(p_x:Int, p_y:Int):Color
	{
		if (p_x < 0) return new Color();
		if (p_y < 0) return new Color();
		if (p_x >= m_width)  return new Color();
		if (p_y >= m_height) return new Color();		
		var cc 	: Int 	= m_channels;
		var pos : Int 	= (p_x + (p_y * m_width)) * cc;				
		if (m_float)
		{
			var c : Color = new Color();
			var b : FloatArray = cast m_buffer;			
			switch(cc)
			{
				case 1: c.r = b.Get(pos); c.g = c.r; c.b = c.r;	c.a = 1.0;
				case 2: c.r = b.Get(pos); c.g = b.Get(pos + 1); c.b = c.r;	c.a = 1.0;
				case 3: c.r = b.Get(pos); c.g = b.Get(pos + 1); c.b = b.Get(pos + 2); c.a = 1.0;
				case 4: c.r = b.Get(pos); c.g = b.Get(pos + 1); c.b = b.Get(pos + 2); c.a = b.Get(pos + 3);
			}			
			return c;
		}		
		var b : Buffer = m_buffer;		
		var rb : Int = b.GetByte(pos);
		var gb : Int = cc >= 2 ? b.GetByte(pos + 1) : rb;
		var bb : Int = cc >= 3 ? b.GetByte(pos + 2) : rb;
		var ab : Int = cc >= 4 ? b.GetByte(pos + 3) : rb;			
		return Color.FromBytes(rb, gb, bb, ab);					
	}
	
	/**
	 * Sets the pixel of the bitmap at the specified position.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_color
	 */
	public function SetPixel(p_x:Int, p_y:Int, p_color:Color):Void
	{
		if (p_x < 0) return;
		if (p_y < 0) return;
		if (p_x >= m_width)  return;
		if (p_y >= m_height) return;		
		var cc 	: Int 	= m_channels;
		var pos : Int 	= (p_x + (p_y * m_width)) * cc;		
		if (m_float)
		{
			var b : FloatArray = cast m_buffer;
			b.Set(pos, p_color.r);			
			if (cc >= 2) b.Set(pos + 1, p_color.g);			
			if (cc >= 3) b.Set(pos + 2, p_color.b);			
			if (cc >= 4) b.Set(pos + 3, p_color.a);
			return;
		}		
		var b : Buffer = cast m_buffer;
		b.SetByte(pos,cast (p_color.r * Mathf.Float2Byte));			
		if (cc >= 2) b.SetByte(pos+1,cast (p_color.g * Mathf.Float2Byte));			
		if (cc >= 3) b.SetByte(pos+2,cast (p_color.b * Mathf.Float2Byte));			
		if (cc >= 4) b.SetByte(pos+3,cast (p_color.a * Mathf.Float2Byte));
	}
	
	/**
	 * Fills the data with the same color.
	 * @param	p_color
	 */
	public function Fill(p_color:Color):Void
	{		
		for (ix in 0...m_width) for (iy in 0...m_height) { SetPixel(ix, iy, p_color); }		
	}
	
	
	/**
	 * Sets a value directly into this bitmap buffer.
	 * There is no check for boundaries for this method.
	 * @param	p_position
	 * @param	p_value
	 */
	public function Set(p_x:Int,p_y:Int, p_v0:Float=0.0,p_v1:Float=0.0,p_v2:Float=0.0,p_v3:Float=0.0):Void
	{
		var cc 	: Int 	= m_channels;
		var pos : Int 	= ((p_x + (p_y * m_width)) * cc);		
		if (m_float)
		{
			var b : FloatArray = cast m_buffer;
			b.Set(pos, p_v0);
			if (cc >= 2) b.Set(pos + 1,p_v1);			
			if (cc >= 3) b.Set(pos + 2,p_v2);			
			if (cc >= 4) b.Set(pos + 3,p_v3);
			return;
		}		
		var b : Buffer = cast m_buffer;
		b.SetByte(pos, cast (p_v0 * Mathf.Float2Byte));
		if (cc >= 2) b.SetByte(pos+1,cast (p_v1 * Mathf.Float2Byte));			
		if (cc >= 3) b.SetByte(pos+2,cast (p_v2 * Mathf.Float2Byte));			
		if (cc >= 4) b.SetByte(pos+3,cast (p_v3 * Mathf.Float2Byte));
	}
	
	/**
	 * Sets a range of values directly into this bitmap buffer.
	 * There is no check for boundaries for this method.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_width
	 * @param	p_height
	 * @param	p_channel
	 * @param	p_value
	 */
	public function SetRange(p_x:Int, p_y:Int, p_width:Int, p_height:Int,p_values:Array<Float>,p_length:Int=-1):Void
	{
		var cc 	: Int 	= m_channels;
		var len : Int   = p_length < 0 ? p_values.length : p_length;		
		var k : Int 	= 0;
		var px : Int = p_x;
		var py : Int = p_y;
		var v0 : Float=0.0;
		var v1 : Float=0.0;
		var v2 : Float=0.0;
		var v3 : Float=0.0;
		
		for (i in 0...len)
		{
			var pos : Int 	= ((px + (py * m_width)) * cc);
			px++;
			if (px >= p_width) { px = p_x; py++; }
			
						 v0	= p_values[k++];
			if (cc >= 2) v1 = p_values[k++];
			if (cc >= 3) v2 = p_values[k++];
			if (cc >= 4) v3 = p_values[k++];
			
			if (m_float)
			{
				var b : FloatArray = cast m_buffer;
				b.Set(pos, v0);
				if (cc >= 2) b.Set(pos + 1,v1);			
				if (cc >= 3) b.Set(pos + 2,v2);			
				if (cc >= 4) b.Set(pos + 3,v3);
				continue;
			}		
			var b : Buffer = cast m_buffer;
			b.SetByte(pos, cast (v0 * Mathf.Float2Byte));
			if (cc >= 2) b.SetByte(pos+1,cast (v1 * Mathf.Float2Byte));			
			if (cc >= 3) b.SetByte(pos+2,cast (v2 * Mathf.Float2Byte));			
			if (cc >= 4) b.SetByte(pos + 3, cast (v3 * Mathf.Float2Byte));
		
		}
	}
	
}