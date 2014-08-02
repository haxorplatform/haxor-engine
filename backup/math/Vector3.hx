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

class Vector3
{
	static private var m_temp : Array<Vector3>;
	static private var m_nexttemp : Int;	
	static public var temp(get_temp, never):Vector3;
	static private function get_temp():Vector3
	{
		if (m_temp == null)
		{
			m_temp = [];
			m_nexttemp = 0;
			for (i in 0...50000) m_temp.push(Vector3.zero);			
		}
		var t :Vector3 = m_temp[m_nexttemp];
		m_nexttemp = (m_nexttemp + 1) % m_temp.length;
		return t;
	}
	
	/**
	 * 
	 */
	static public var zero(get_zero, null):Vector3;	static private function get_zero():Vector3 { return new Vector3(0, 0, 0); }
	
	/**
	 * 
	 */
	static public var one(get_one, null):Vector3;
	static private function get_one():Vector3 { return new Vector3(1, 1, 1); }
	
	/**
	 * 
	 */
	static public var right(get_right, null):Vector3;
	static private function get_right():Vector3 { return new Vector3(1, 0, 0); }
	
	/**
	 * 
	 */
	static public var up(get_up, null):Vector3;
	static private function get_up():Vector3 { return new Vector3(0, 1, 0); }
	
	/**
	 * 
	 */
	static public var forward(get_forward, null):Vector3;
	static private function get_forward():Vector3 { return new Vector3(0, 0, 1); }
	
	/**
	 * 
	 * @param	p_a
	 * @param	p_b
	 * @return
	 */
	static public function Dot(p_a : Vector3, p_b : Vector3) : Float
	{
		return (p_a.x * p_b.x) + (p_a.y * p_b.y) + (p_a.z * p_b.z);
	}
	
	/**
	 * 
	 * @param	p_a
	 * @param	p_b
	 * @return
	 */
	static public function Distance(p_a : Vector3, p_b : Vector3) : Float
	{
		var dx : Float = (p_a.x - p_b.x);
		var dy : Float = (p_a.y - p_b.y);
		var dz : Float = (p_a.z - p_b.z);
		return Mathf.Sqrt(dx * dx + dy * dy + dz * dz);
	}
	
	/**
	 * 
	 * @param	Vector3 p_a
	 * @param	Vector3 p_b
	 * @return
	 */
	static public function Cross(p_a : Vector3,p_b : Vector3): Vector3
	{
		return new Vector3(
		p_a.y * p_b.z - p_a.z * p_b.y,
		p_a.z * p_b.x - p_a.x * p_b.z,
		p_a.x * p_b.y - p_a.y * p_b.x);
	}
	
	/**
	 * 
	 * @param	p_a
	 * @param	p_b
	 * @param	p_r
	 * @return
	 */
	static public function Lerp(p_a : Vector3, p_b : Vector3, p_r:Float):Vector3
	{
		return new Vector3(
		p_a.x + (p_b.x - p_a.x) * p_r,
		p_a.y + (p_b.y - p_a.y) * p_r,
		p_a.z + (p_b.z - p_a.z) * p_r
		);
	}
	
	/**
	 * 
	 */
	public var clone(get_clone, null) : Vector3;
	private function get_clone():Vector3 { return new Vector3(x, y, z); }
	
	/**
	 * 
	 */
	public var xzy(get_xzy, null) : Vector3;	private function get_xzy():Vector3 { return new Vector3(x, z, y); }
	
	/**
	 * 
	 */
	public var yxz(get_yxz, null) : Vector3;	private function get_yxz():Vector3 { return new Vector3(y, z, x); }
	
		
	/**
	 * 
	 */
	public var yzx(get_yzx, null) : Vector3;	private function get_yzx():Vector3 { return new Vector3(y, z, x); }
	
	/**
	 * 
	 */
	public var zxy(get_zxy, null) : Vector3;	private function get_zxy():Vector3 { return new Vector3(z, x, y); }
	
	/**
	 * 
	 */
	public var zyx(get_zyx, null) : Vector3;	private function get_zyx():Vector3 { return new Vector3(z, y, x); }
	
	/**
	 * 
	 */
	public var xy(get_xy, null) : Vector2;	private function get_xy():Vector2 { return new Vector2(x, y); }

	/**
	 * 
	 */
	public var xz(get_xz, null) : Vector2;	private function get_xz():Vector2 { return new Vector2(x, z); }
	
	/**
	 * 
	 */
	public var yx(get_yx, null) : Vector2;	private function get_yx():Vector2 { return new Vector2(y, x); }
	
	/**
	 * 
	 */
	public var yz(get_yz, null) : Vector2;	private function get_yz():Vector2 { return new Vector2(y, z); }
	
	/**
	 * 
	 */
	public var zx(get_zx, null) : Vector2;	private function get_zx():Vector2 { return new Vector2(z, x); }
	
	/**
	 * 
	 */
	public var zy(get_zy, null) : Vector2;	private function get_zy():Vector2 { return new Vector2(z, y); }

	/**
	 * 
	 */
	public var length(get_length, null) : Float;
	private function get_length():Float { return Math.sqrt(x * x + y * y + z * z); }
	
	public var normalized(get_normalized, null) : Vector3;
	private function get_normalized():Vector3 { return clone.Normalize(); }
	
	public var inverse(get_inverse, null) : Vector3;
	private function get_inverse():Vector3 { return clone.Invert(); }
	
	public var x:Float;
	public var y:Float;
	public var z:Float;

	
	public function new(p_x:Float=0,p_y:Float=0,p_z:Float=0) 
	{
		x = p_x;
		y = p_y;
		z = p_z;
	}
	
	public function Set(p_x:Float = 0, p_y:Float = 0, p_z:Float = 0):Vector3 { x = p_x; y = p_y; z = p_z; return this; }
	
	public function Set3(v:Vector3):Vector3 { x = v.x; y = v.y; z = v.z; return this; }
	
	
	/**
	 * 
	 * @param	p
	 * @return
	 */
	public function Get(p : Int):Float { return p == 0 ? x  : (p == 1 ? y : z); }
	
	/**
	 * 
	 * @param	p_v
	 * @return
	 */
	public function Add(p_v : Vector3):Vector3
	{
		x += p_v.x;
		y += p_v.y;
		z += p_v.z;		
		return this;
	}
	
	/**
	 * 
	 * @param	p_v
	 * @return
	 */
	public function Sub(p_v : Vector3):Vector3
	{
		x -= p_v.x;
		y -= p_v.y;
		z -= p_v.z;		
		return this;
	}
	
	/**
	 * 
	 * @param	p_v
	 * @return
	 */
	public function Multiply(p_v : Vector3):Vector3
	{
		x *= p_v.x;
		y *= p_v.y;
		z *= p_v.z;		
		return this;
	}
	
	public function Reflect(p_normal:Vector3):Vector3
	{
		var d : Float = Math.min(0.0,Dot(p_normal, this));		
		x += -p_normal.x * d * 2;
		y += -p_normal.y * d * 2;
		z += -p_normal.z * d * 2;
		return this;
	}
	
	public function Invert():Vector3
	{
		x = -x;
		y = -y;
		z = -z;		
		return this;
	}
		
	/**
	 * 
	 * @param	p_s
	 * @return
	 */
	public function Scale(p_s : Float):Vector3
	{
		x *= p_s;
		y *= p_s;
		z *= p_s;		
		return this;
	}
	
	public function Normalize():Vector3
	{
		var l:Float = length;
		if (l <= 0) return this;
		x *= (l = 1.0 / l);
		y *= l;
		z *= l;
		return this;
	}
	
	/**
	 * 
	 * @return
	 */
	public function ToArray() : Array<Float> { return [x, y, z]; }
	
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