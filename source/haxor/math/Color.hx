/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.math;

/**
 * ...
 * @author Eduardo Pons
 */
class Color
{
	static private var m_temp : Array<Color>;
	static private var m_nexttemp : Int;	
	static public var temp(get_temp, never):Color;
	static private function get_temp():Color
	{
		if (m_temp == null)
		{
			m_temp = [];
			m_nexttemp = 0;
			for (i in 0...50000) m_temp.push(new Color(0,0,0,1));			
		}
		var t :Color = m_temp[m_nexttemp];
		m_nexttemp = (m_nexttemp + 1) % m_temp.length;
		return t;
	}
	
	
	static public var red    (get_red    , null):Color;	static private function get_red    ():Color { return Color.temp.Set(1.0, 0, 0, 1); }
	static public var yellow (get_yellow , null):Color;	static private function get_yellow ():Color { return Color.temp.Set(1, 1, 0, 1); }
	static public var green  (get_green  , null):Color;	static private function get_green  ():Color { return Color.temp.Set(0, 1, 0, 1); }
	static public var cyan   (get_cyan   , null):Color;	static private function get_cyan   ():Color { return Color.temp.Set(0, 1, 1, 1); }
	static public var blue   (get_blue   , null):Color;	static private function get_blue   ():Color { return Color.temp.Set(0, 0, 1, 1); }
	static public var magenta(get_magenta, null):Color;	static private function get_magenta():Color { return Color.temp.Set(1, 0, 1, 1); }
	static public var black  (get_black  , null):Color;	static private function get_black  ():Color { return Color.temp.Set(0, 0, 0, 1); }
	static public var white  (get_white  , null):Color;	static private function get_white  ():Color { return Color.temp.Set(1, 1, 1, 1); }
	static public var empty  (get_empty  , null):Color;	static private function get_empty  ():Color { return Color.temp.Set(0, 0, 0, 0); }
	static public var gray10 (get_gray10 , null):Color;	static private function get_gray10 ():Color { return Color.temp.Set(0.1, 0.1, 0.1, 1); }
	static public var gray25 (get_gray25 , null):Color;	static private function get_gray25 ():Color { return Color.temp.Set(0.25, 0.25, 0.25, 1); }
	static public var gray50 (get_gray50 , null):Color;	static private function get_gray50 ():Color { return Color.temp.Set(0.5, 0.5, 0.5, 1); }
	static public var gray75 (get_gray75 , null):Color;	static private function get_gray75 ():Color { return Color.temp.Set(0.75, 0.75, 0.75, 1); }
	static public var gray90 (get_gray90 , null):Color;	static private function get_gray90 ():Color { return Color.temp.Set(0.9, 0.9, 0.9, 1); }
	
	/**
	 * 
	 * @param	p_hex
	 * @return
	 */
	static public function FromHex(p_hex:String):Color
	{
		var c : Color = new Color();
		if (p_hex.length == 10) c.argb = Std.parseInt(p_hex) else c.rgb = Std.parseInt(p_hex);
		return c;
	}
	
	static public function FromBytes(p_r:Float=0, p_g:Float=0, p_b:Float=0, p_a:Float=255.0):Color
	{
		return new Color(p_r * Mathf.Byte2Float, p_g * Mathf.Byte2Float, p_b * Mathf.Byte2Float, p_a * Mathf.Byte2Float);		
	}
	
	/**
	 * 
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
	 * 
	 */
	public var clone(get_clone, null) : Color;
	private function get_clone():Color { return new Color(r, g, b, a); }	
	
	/**
	 * 
	 */
	public var xyz(get_xyz, null):Vector3;
	private function get_xyz():Vector3 { return new Vector3(r, g, b); }
	
	/**
	 * 
	 */
	public var xyzw(get_xyzw, null):Vector4;
	private function get_xyzw():Vector4 { return new Vector4(r, g, b, a); }	
	
	/**
	 * 
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
	 * 
	 */
	public var css(get_css, never) : String;
	private function get_css():String { return "rgba("+Std.int(r*255)+","+Std.int(g*255)+","+Std.int(b*255)+","+(a)+")"; }
	
	/**
	 * 
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
	 * 
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
	 * 
	 */
	public var r:Float;
	
	/**
	 * 
	 */
	public var g:Float;
	
	/**
	 * 
	 */
	public var b:Float;
	
	/**
	 * 
	 */
	public var a:Float;


	/**
	 * 
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
	 * 
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
	
	
	public function Set4(p_color : Color = null) : Color
	{
		r = p_color == null ? 0.0 : p_color.r;
		g = p_color == null ? 0.0 : p_color.g;
		b = p_color == null ? 0.0 : p_color.b;		
		a = p_color == null ? 1.0 : p_color.a;
		return this;
	}
	
		/**
	 * 
	 * @return
	 */
	public function ToArray() : Array<Float> { return [r, g, b, a]; }
	
	/**
	 * 
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