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

class Vector4
{
	static private var m_temp : Array<Vector4>;
	static private var m_nexttemp : Int;	
	static public var temp(get_temp, never):Vector4;
	static private function get_temp():Vector4
	{
		if (m_temp == null)
		{
			m_temp = [];
			m_nexttemp = 0;
			for (i in 0...50000) m_temp.push(Vector4.zero);			
		}
		var t :Vector4 = m_temp[m_nexttemp];
		m_nexttemp = (m_nexttemp + 1) % m_temp.length;
		return t;
	}
	
	/**
	 * 
	 */
	static public var zero(get_zero, null):Vector4;
	static private function get_zero():Vector4 { return new Vector4(0, 0, 0,0); }
	
	/**
	 * 
	 * @param	p_a
	 * @param	p_b
	 * @param	p_r
	 * @return
	 */
	static public function Lerp(p_a : Vector4, p_b : Vector4, p_r:Float):Vector4
	{
		return new Vector4(
		p_a.x + (p_b.x - p_a.x) * p_r,
		p_a.y + (p_b.y - p_a.y) * p_r,
		p_a.z + (p_b.z - p_a.z) * p_r,
		p_a.w + (p_b.w - p_a.w) * p_r
		);
	}
	
	
	
	
	public var clone(get_clone, null) : Vector4;
	private function get_clone():Vector4 { return new Vector4(x, y,z,w); }	
	
	public var rgba(get_rgba, null) : Color;	
	private function get_rgba():Color { return new Color(x, y,z,w); }
	
	public var xyz(get_xyz, null) : Vector3;	
	private function get_xyz():Vector3 { return new Vector3(x, y,z); }
	
	public var xy(get_xy, null) : Vector2;	
	private function get_xy():Vector2 { return new Vector2(x, y); }
	
	public var length(get_length, null) : Float;	
	private function get_length():Float { return Math.sqrt(x * x + y * y + z * z + w*w); }
	
	public var normalized(get_normalized, null) : Vector4;
	private function get_normalized():Vector4 { return clone.Normalize(); }
	
	public var x:Float;
	public var y:Float;
	public var z:Float;
	public var w:Float;

	
	public function new(p_x:Float=0,p_y:Float=0,p_z:Float=0,p_w:Float=0) 
	{
		x = p_x;
		y = p_y;
		z = p_z;
		w = p_w;
	}
	
	/**
	 * 
	 * @param	p
	 * @return
	 */
	public function Get(p : Int):Float { return p == 0 ? x  : (p == 1 ? y : (p==2 ? z : w)); }
	
	public function Set(p_x:Float = 0, p_y:Float = 0, p_z:Float = 0, p_w:Float = 0):Vector4 { x = p_x; y = p_y; z = p_z; w = p_w; return this; }
	
	/**
	 * 
	 * @param	p_v
	 * @return
	 */
	public function Add(p_v : Vector4):Vector4
	{
		x += p_v.x;
		y += p_v.y;
		z += p_v.z;
		w += p_v.w;
		return this;
	}
	
	/**
	 * 
	 * @param	p_s
	 * @return
	 */
	public function Scale(p_s : Float):Vector4
	{
		x *= p_s;
		y *= p_s;
		z *= p_s;
		w *= p_s;
		return this;
	}
	
	public function Normalize():Vector4
	{
		var l:Float = length;
		if (l <= 0) return this;
		x *= (l = 1.0 / l);
		y *= l;
		z *= l;
		w *= l;
		return this;
	}
	
	
	public function IsCulled():Bool
	{
		if (x < -w)  return true;
		if (x >  w)  return true;
		if (y < -w)  return true;
		if (y >  w)  return true;
		if (z < -w)  return true;
		if (z >  w)  return true;
		return false;
	}
	 
	
	/**
	 * 
	 * @return
	 */
	public function ToArray() : Array<Float> { return [x,y,z,w]; }
	
		
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