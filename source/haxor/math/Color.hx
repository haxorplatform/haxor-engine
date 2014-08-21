package haxor.math;

/**
 * Class that describes a RGBA color represented as a float tuple.
 * @author Eduardo Pons
 */
class Color
{
	/**
	 * Red pixel.
	 */
	static public var red    (get_red    , null):Color;	static private function get_red    ():Color { return new Color(1.0, 0, 0, 1); }
	/**
	 * Yellow pixel.
	 */
	static public var yellow (get_yellow , null):Color;	static private function get_yellow ():Color { return new Color(1, 1, 0, 1); }
	/**
	 * Green pixel.
	 */
	static public var green  (get_green  , null):Color;	static private function get_green  ():Color { return new Color(0, 1, 0, 1); }
	/**
	 * Cyan pixel.
	 */
	static public var cyan   (get_cyan   , null):Color;	static private function get_cyan   ():Color { return new Color(0, 1, 1, 1); }
	/**
	 * Blue pixel.
	 */
	static public var blue   (get_blue   , null):Color;	static private function get_blue   ():Color { return new Color(0, 0, 1, 1); }
	/**
	 * Magenta pixel.
	 */
	static public var magenta(get_magenta, null):Color;	static private function get_magenta():Color { return new Color(1, 0, 1, 1); }
	/**
	 * Black pixel.
	 */
	static public var black  (get_black  , null):Color;	static private function get_black  ():Color { return new Color(0, 0, 0, 1); }
	/**
	 * White pixel.
	 */
	static public var white  (get_white  , null):Color;	static private function get_white  ():Color { return new Color(1, 1, 1, 1); }
	/**
	 * Transparent pixel.
	 */
	static public var empty  (get_empty  , null):Color;	static private function get_empty  ():Color { return new Color(0, 0, 0, 0); }
	/**
	 * 10% Gray pixel
	 */
	static public var gray10 (get_gray10 , null):Color;	static private function get_gray10 ():Color { return new Color(0.1, 0.1, 0.1, 1); }
	/**
	 * 25% Gray pixel
	 */
	static public var gray25 (get_gray25 , null):Color;	static private function get_gray25 ():Color { return new Color(0.25, 0.25, 0.25, 1); }
	/**
	 * 50% Gray pixel
	 */
	static public var gray50 (get_gray50 , null):Color;	static private function get_gray50 ():Color { return new Color(0.5, 0.5, 0.5, 1); }
	/**
	 * 75% Gray pixel
	 */
	static public var gray75 (get_gray75 , null):Color;	static private function get_gray75 ():Color { return new Color(0.75, 0.75, 0.75, 1); }
	/**
	 * 90% Gray pixel
	 */
	static public var gray90 (get_gray90 , null):Color;	static private function get_gray90 ():Color { return new Color(0.9, 0.9, 0.9, 1); }
	
	/**
	 * Creates a new Color instance from a Hexadecimal string representation.
	 * @param	p_hex
	 * @return
	 */
	static public function FromHex(p_hex:String):Color
	{
		var c : Color = new Color();
		if (p_hex.length == 10) c.argb = Std.parseInt(p_hex) else c.rgb = Std.parseInt(p_hex);
		return c;
	}
	
	/**
	 * Returns a new Color using the 8 bits data informed for each channel.
	 * @param	p_r
	 * @param	p_g
	 * @param	p_b
	 * @param	p_a
	 * @return
	 */
	static public function FromBytes(p_r:Float=0, p_g:Float=0, p_b:Float=0, p_a:Float=255.0):Color
	{
		return new Color(p_r * Mathf.Byte2Float, p_g * Mathf.Byte2Float, p_b * Mathf.Byte2Float, p_a * Mathf.Byte2Float);		
	}
	
	/**
	 * Linear interpolates 2 colors.
	 * @param	a
	 * @param	b
	 * @param	r
	 * @return
	 */
	static public function Lerp(a : Color, b : Color, r : Float) :Color
	{
		return new Color(Mathf.Lerp(a.r, b.r, r), Mathf.Lerp(a.g, b.g, r), Mathf.Lerp(a.b, b.b, r), Mathf.Lerp(a.a, b.a, r));
	}
	
	/**
	 * Linear interpolates the color list.
	 * @param	g
	 * @param	r
	 * @return
	 */
	static public function Sample(g: Array<Color>, r:Float):Color
	{
		var pos : Float = cast (g.length-1); 
		pos *= r*0.9999;
		var i0 : Int = Std.int(pos);
		var i1 : Int = (i0 + 1)%g.length;
		r = Mathf.Frac(pos);
		var c0 : Color = g[i0];
		var c1 : Color = g[i1];		
		return Lerp(c0, c1, r);
	}
	
	/**
	 * Creates a copy of this color instance.
	 */
	public var clone(get_clone, null) : Color;
	private inline function get_clone():Color { return (new Color(r, g, b, a)); }
	
	/**
	 * Returns this color represented as Vector3 with the RGB channels.
	 */
	//public var xyz(get_xyz, null):Vector3;
	//private function get_xyz():Vector3 { return new Vector3(r, g, b); }
	
	/**
	 * Returns this color represented as Vector4 with the RGBA channels.
	 */
	//public var xyzw(get_xyzw, null):Vector4;
	//private function get_xyzw():Vector4 { return new Vector4(r, g, b, a); }	
	
	/**
	 * Get/Set the Int32 representation of this color with the ARGB channels.
	 */
	public var argb(get_argb, set_argb):Int;
	private function get_argb():Int
	{
		var rb : Int = cast (r * Mathf.Float2Byte);
		var gb : Int = cast (g * Mathf.Float2Byte);
		var bb : Int = cast (b * Mathf.Float2Byte);
		var ab : Int = cast (a * Mathf.Float2Byte);
		return (ab << 24) | (rb << 16) | (gb << 8) | (bb);
	}	
	private function set_argb(v:Int):Int
	{
		a = cast (((v >> 24) & 0xff) * Mathf.Byte2Float);
		g = cast (((v >> 16) & 0xff) * Mathf.Byte2Float);
		b = cast (((v >>  8) & 0xff) * Mathf.Byte2Float);
		r = cast (((v      ) & 0xff) * Mathf.Byte2Float);
		return v;
	}
	
	/**
	 * Returns the CSS representation of this color.
	 */
	public var css(get_css, never) : String;
	private inline function get_css():String { return "rgba("+Std.int(r*255)+","+Std.int(g*255)+","+Std.int(b*255)+","+(a)+")"; }
	
	/**
	 *Get/Set the Int32 representation of this color  with the RGBA channels.
	 */
	public var rgba(get_rgba, set_rgba):Int;
	private function get_rgba():Int
	{
		var rb : Int = cast (r * Mathf.Float2Byte);
		var gb : Int = cast (g * Mathf.Float2Byte);
		var bb : Int = cast (b * Mathf.Float2Byte);
		var ab : Int = cast (a * Mathf.Float2Byte);
		return (rb << 24) | (gb << 16) | (bb << 8) | (ab);
	}	
	private function set_rgba(v:Int):Int
	{
		r = cast (((v >> 24) & 0xff) * Mathf.Byte2Float);
		g = cast (((v >> 16) & 0xff) * Mathf.Byte2Float);
		b = cast (((v >>  8) & 0xff) * Mathf.Byte2Float);
		a = cast (((v      ) & 0xff) * Mathf.Byte2Float);
		return v;
	}
	
	/**
	 * Get/Set the Int24 representation of this color with the RGB channels.
	 */
	public var rgb(get_rgb, set_rgb):Int;
	private function get_rgb():Int
	{
		var rb : Int = cast (r * Mathf.Float2Byte);
		var gb : Int = cast (g * Mathf.Float2Byte);
		var bb : Int = cast (b * Mathf.Float2Byte);		
		return (rb << 16) | (gb << 8) | (bb);
	}	
	private function set_rgb(v:Int):Int
	{
		r = cast (((v >> 16) & 0xff) * Mathf.Byte2Float);
		g = cast (((v >>  8) & 0xff) * Mathf.Byte2Float);
		b = cast (((v      ) & 0xff) * Mathf.Byte2Float);
		return v;
	}
	
	/**
	 * Red Channel.
	 */
	public var r:Float;
	
	/**
	 * Green Channel.
	 */
	public var g:Float;
	
	/**
	 * Blue Channel.
	 */
	public var b:Float;
	
	/**
	 * Alpha Channel
	 */
	public var a:Float;


	/**
	 * Creates a new Color instance with the informed channels.
	 * @param	p_r
	 * @param	p_g
	 * @param	p_b
	 * @param	p_a
	 */
	public function new(p_r:Float=0,p_g:Float=0,p_b:Float=0,p_a:Float=1)
	{
		r = p_r;
		g = p_g;
		b = p_b;
		a = p_a;
	}
	
	
	/**
	 * Sets all color channels.
	 * @param	p_r
	 * @param	p_g
	 * @param	p_b
	 * @param	p_a
	 * @return
	 */
	public function Set(p_r:Float = 0, p_g:Float = 0, p_b:Float = 0, p_a:Float = 1) : Color
	{
		r = p_r;
		g = p_g;
		b = p_b;
		a = p_a;
		return this;
	}
	
	/**
	 * Sets all color channels using a Color instance as template.
	 * @param	p_color
	 * @return
	 */
	public function Set4(p_color : Color = null) : Color
	{
		r = p_color == null ? 0.0 : p_color.r;
		g = p_color == null ? 0.0 : p_color.g;
		b = p_color == null ? 0.0 : p_color.b;		
		a = p_color == null ? 1.0 : p_color.a;
		return this;
	}
	
	/**
	 * Returns all channels as an Array of Floats.
	 * @return
	 */
	public function ToArray() : Array<Float> { return [r, g, b, a]; }
	
	/**
	 * Outputs this color channels values as String.
	 * @return
	 */
	public function ToString():String
	{
		var a : Array<Float> = ToArray();
		var s : Array<String> = [];
		for (i in 0...a.length) { a[i] = Std.int(a[i] * 100.0) / 100; s.push(a[i] >= 0 ? " " + a[i] : a[i] + ""); }
		var res:String = "[";
		for (i in 0...a.length)
		{
			res += s[i] + ((i < (a.length-1)) ? "," : "]");			
		}
		return res;
	}
	
	
}