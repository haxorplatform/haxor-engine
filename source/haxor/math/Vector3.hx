package haxor.math;

/**
 * Class that represents a 3 float tuple.
 * @author Eduardo Pons
 */
class Vector3
{	
	/**
	 * Returns a new Vector3(0,0,0).
	 */
	static public var zero(get_zero, null):Vector3;	
	static private inline function get_zero():Vector3 { return new Vector3(0, 0, 0); }
	
	/**
	 * Returns a new Vector3(1,1,1).
	 */
	static public var one(get_one, null):Vector3;
	static private inline function get_one():Vector3 { return new Vector3(1, 1, 1); }
	
	/**
	 * Returns a new Vector3(1,0,0).
	 */
	static public var right(get_right, null):Vector3;
	static private inline function get_right():Vector3 { return new Vector3(1, 0, 0); }
	
	/**
	 * Returns a new Vector3(0,1,0).
	 */
	static public var up(get_up, null):Vector3;
	static private inline function get_up():Vector3 { return new Vector3(0, 1, 0); }
	
	/**
	 * Returns a new Vector3(0,0,1).
	 */
	static public var forward(get_forward, null):Vector3;
	static private function get_forward():Vector3 { return new Vector3(0, 0, 1); }
	
	/**
	 * Returns the Dot product of the informed vectors.
	 * @param	p_a
	 * @param	p_b
	 * @return
	 */
	static public inline function Dot(p_a : Vector3, p_b : Vector3) : Float { return ((p_a.x * p_b.x) + (p_a.y * p_b.y) + (p_a.z * p_b.z)); }
	
	/**
	 * Measures the distance between 2 points.
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
	 * Returns the Cross product between 2 vectors.
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
	 * Linear interpolates 2 vectors.
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
	 * Returns a copy of this vector instance.
	 */
	public var clone(get_clone, null) : Vector3;
	private inline function get_clone():Vector3 { return new Vector3(x, y, z); }
	
	/**
	 * Returns a copy of this vector in Color(x,y,z,1.0) form.
	 */
	public var color(get_color, null) : Color;
	private inline function get_color():Color { return new Color(x, y, z); }
	
	/**
	 * Returns a swizzle of this vector with the requested coordinates combination.
	 */
	public var xzy(get_xzy, null) : Vector3;	private inline function get_xzy():Vector3 { return new Vector3(x, z, y); }
	
	/**
	 * Returns a swizzle of this vector with the requested coordinates combination.
	 */
	public var yxz(get_yxz, null) : Vector3;	private inline function get_yxz():Vector3 { return new Vector3(y, z, x); }	
		
	/**
	 * Returns a swizzle of this vector with the requested coordinates combination.
	 */
	public var yzx(get_yzx, null) : Vector3;	private inline function get_yzx():Vector3 { return new Vector3(y, z, x); }
	
	/**
	 * Returns a swizzle of this vector with the requested coordinates combination.
	 */
	public var zxy(get_zxy, null) : Vector3;	private inline function get_zxy():Vector3 { return new Vector3(z, x, y); }
	
	/**
	 * Returns a swizzle of this vector with the requested coordinates combination.
	 */
	public var zyx(get_zyx, null) : Vector3;	private inline function get_zyx():Vector3 { return new Vector3(z, y, x); }
	
	/**
	 * Returns a swizzle of this vector with the requested coordinates combination.
	 */
	public var xy(get_xy, null) : Vector2;	private inline function get_xy():Vector2 { return new Vector2(x, y); }

	/**
	 * Returns a swizzle of this vector with the requested coordinates combination.
	 */
	public var xz(get_xz, null) : Vector2;	private inline function get_xz():Vector2 { return new Vector2(x, z); }
	
	/**
	 * Returns a swizzle of this vector with the requested coordinates combination.
	 */
	public var yx(get_yx, null) : Vector2;	private inline function get_yx():Vector2 { return new Vector2(y, x); }
	
	/**
	 * Returns a swizzle of this vector with the requested coordinates combination.
	 */
	public var yz(get_yz, null) : Vector2;	private inline function get_yz():Vector2 { return new Vector2(y, z); }
	
	/**
	 * Returns a swizzle of this vector with the requested coordinates combination.
	 */
	public var zx(get_zx, null) : Vector2;	private inline function get_zx():Vector2 { return new Vector2(z, x); }
	
	/**
	 * Returns a swizzle of this vector with the requested coordinates combination.
	 */
	public var zy(get_zy, null) : Vector2;	private inline function get_zy():Vector2 { return new Vector2(z, y); }

	/**
	 * Returns the length of the vector.
	 */
	public var length(get_length, null) : Float;
	private inline function get_length():Float { return Math.sqrt(x * x + y * y + z * z); }
	
	/**
	 * Returns the squared length.
	 */
	public var lengthSqr(get_lengthSqr, null) : Float;	
	private inline function get_lengthSqr():Float { return (x * x + y * y + z * z); }
	
	/**
	 * Returns a copy of this vector normalized.
	 */
	public var normalized(get_normalized, null) : Vector3;
	private function get_normalized():Vector3 { return clone.Normalize(); }
	
	/**
	 * Returns a copy of this vector if its components inverted.
	 */
	public var inverse(get_inverse, null) : Vector3;
	private inline function get_inverse():Vector3 { return clone.Invert(); }
	
	
	/**
	 * X coordinate.
	 */
	public var x:Float;
	
	/**
	 * Y coordinate.
	 */
	public var y:Float;
	
	/**
	 * Z coordinate.
	 */
	public var z:Float;

	/**
	 * Creates a new Vector3 with the informed coordinates.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 */
	public function new(p_x:Float=0,p_y:Float=0,p_z:Float=0) 
	{
		x = p_x;
		y = p_y;
		z = p_z;
	}
	
	/**
	 * Sets all components of this Vector3. Returns its own reference.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @return
	 */
	public function Set(p_x:Float = 0, p_y:Float = 0, p_z:Float = 0):Vector3 { x = p_x; y = p_y; z = p_z; return this; }
	
	/**
	 * Sets all components of this vector using a Vector2 as template. Returns its own reference.
	 * @param	v
	 * @return
	 */
	public function Set2(v:Vector2):Vector3 { x = v.x; y = v.y; return this; }
	
	/**
	 * Sets all components of this vector using other vector as template. Returns its own reference.
	 * @param	v
	 * @return
	 */
	public function Set3(v:Vector3):Vector3 { x = v.x; y = v.y; z = v.z; return this; }
	
	/**
	 * Sets all components of this vector using other vector as template. Returns its own reference.
	 * @param	v
	 * @return
	 */
	public function Set4(v:Vector4):Vector3 { x = v.x; y = v.y; z = v.z; return this; }
	
	/**
	 * Sets all components of this vector using a Color as template. Returns its own reference.
	 * @param	v
	 * @return
	 */
	public function SetColor(v:Color):Vector3 { x = v.r; y = v.g; z = v.b; return this; }
		
	/**
	 * Returns one of its coordinates indexed by an integer where 0 == x, 1 == y and 2 == z.
	 * @param	p
	 * @return
	 */
	public function Get(p : Int):Float { return p == 0 ? x  : (p == 1 ? y : z); }
	
	/**
	 * Adds this vector with another one, component-wise. Returns its own reference.
	 * @param	p_v
	 * @return
	 */
	public function Add(p_v : Vector3):Vector3 { x += p_v.x; y += p_v.y; z += p_v.z; return this; }
	
	/**
	 * Subtracts this vector with another one, component-wise. Returns its own reference.
	 * @param	p_v
	 * @return
	 */
	public function Sub(p_v : Vector3):Vector3 { x -= p_v.x; y -= p_v.y; z -= p_v.z; return this; }
	
	/**
	 * Subtracts this vector with another one, component-wise. Returns its own reference.
	 * @param	p_v
	 * @return
	 */
	public function Multiply(p_v : Vector3):Vector3 { x *= p_v.x; y *= p_v.y; z *= p_v.z; return this; }
	
	/**
	 * Moves this point towards the target using the specified step. If this point reaches target it returns true, otherwise returns false.
	 * @param	p_to
	 * @param	p_step
	 * @return
	 */
	public function Step(p_to : Vector3, p_step : Float):Bool
	{
		var vx : Float = p_to.x - x;
		var vy : Float = p_to.y - y;
		var vz : Float = p_to.z - z;
		var l : Float = Math.sqrt(vx * vx + vy * vy + vz * vz);
		if (l <= Mathf.Epsilon) return false;
		var s : Float = p_step > l ? l : p_step;
		l = s / l;		
		vx *= l;
		vy *= l;
		vz *= l;
		x += vx;
		y += vy;
		z += vz;
		return true;
	}
	
	/**
	 * Reflects this vector around the normal of a given surface.
	 * @param	p_normal
	 * @return
	 */
	public function Reflect(p_normal:Vector3):Vector3
	{
		var d : Float = Math.min(0.0,Dot(p_normal, this)) * 2.0;		
		x += -p_normal.x * d;
		y += -p_normal.y * d;
		z += -p_normal.z * d;
		return this;
	}
	
	/**
	 * Inverts this vector coordinates. Returns its own reference.
	 * @return
	 */
	public function Invert():Vector3 { x = -x; y = -y; z = -z; return this; }
		
	/**
	 * Scales this vector using the informed scalar. Returns its own reference.
	 * @param	p_s
	 * @return
	 */
	public function Scale(p_s : Float):Vector3 { x *= p_s; y *= p_s; z *= p_s; return this; }
	
	/**
	 * Normalizes this vector. Returns its own reference.
	 * @return
	 */
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
	 * Converts this vector to an Array<Float>
	 * @return
	 */
	public function ToArray() : Array<Float> { return [x, y, z]; }
	
	/**
	 * Returns the String form of this vector.
	 * @return
	 */
	public function ToString(p_places:Int=2):String { return "["+Mathf.RoundPlaces(x,p_places)+","+Mathf.RoundPlaces(y,p_places)+","+Mathf.RoundPlaces(z,p_places)+"]"; }
	
}