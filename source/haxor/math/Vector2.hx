package haxor.math;
import haxor.context.EngineContext;
import haxor.platform.Types.Float32;

/**
 * Class that represents a 2 float tuple.
 * @author Eduardo Pons
 */
class Vector2
{	
	/**
	 * Returns a temporary cached instance of this class for local calculations speedup.  [warning] The data isn't setup in any way.
	 */
	static public var temp(get_temp, null):Vector2;
	static private inline function get_temp():Vector2 { return EngineContext.data.v2; }
	
	/**
	 * Returns a new Vector2(0,0);
	 */
	static public var zero(get_zero, null):Vector2;	
	static private inline function get_zero():Vector2 { return new Vector2(0, 0); }
	
	/**
	 * Returns a new Vector2(1,1);
	 */
	static public var one(get_one, null):Vector2;	
	static private inline function get_one():Vector2 { return new Vector2(1, 1); }
	
	/**
	 * Returns a new Vector2(1,0)
	 */
	static public var right(get_right, null):Vector2;
	static private inline function get_right():Vector2 { return new Vector2(1, 0); }
	
	/**
	 * Returns a new Vector2(0,1)
	 */
	static public var up(get_up, null):Vector2;
	static private inline function get_up():Vector2 { return new Vector2(0, 1); }
	
	/**
	 * Returns the Dot product of the informed vectors.
	 * @param	p_a
	 * @param	p_b
	 * @return
	 */
	static public inline function Dot(p_a : Vector2, p_b : Vector2) : Float32 { return ((p_a.x * p_b.x) + (p_a.y * p_b.y)); }
	
	/**
	 * Linear interpolates 2 vectors.
	 * @param	p_a
	 * @param	p_b
	 * @param	p_r
	 * @return
	 */
	static public function Lerp(p_a : Vector2, p_b : Vector2, p_r:Float32):Vector2
	{
		return new Vector2(
		p_a.x + (p_b.x - p_a.x) * p_r,
		p_a.y + (p_b.y - p_a.y) * p_r		
		);
	}
	
	/**
	 * Returns a copy of the vector.
	 */
	public var clone(get_clone, null) : Vector2;
	private inline function get_clone():Vector2 { return new Vector2(x, y); }
	
	/**
	 * Returns a swizzle of this vector with the requested coordinates combination.
	 */
	public var xy(get_xy, null) : Vector2;	private inline function get_xy():Vector2 { return new Vector2(x, y); }
	
	/**
	 * Returns a swizzle of this vector with the requested coordinates combination.
	 */
	public var yx(get_yx, null) : Vector2;	private inline function get_yx():Vector2 { return new Vector2(y, x); }
	
	/**
	 * Returns the length of the vector.
	 */
	public var length(get_length, null) : Float32;	
	private inline function get_length():Float32{ return Math.sqrt(x * x + y * y); }
	
	/**
	 * Returns the squared length.
	 */
	public var lengthSqr(get_lengthSqr, null) : Float32;	
	private inline function get_lengthSqr():Float32{ return (x * x + y * y); }
	
	/**
	 * Returns a copy of this vector, normalized.
	 */
	public var normalized(get_normalized, null) : Vector2;	
	private inline function get_normalized():Vector2 { return clone.Normalize(); }
	
	/**
	 * Returns a copy of this vector if its components inverted.
	 */
	public var inverse(get_inverse, null) : Vector2;
	private inline function get_inverse():Vector2 { return clone.Invert(); }
	
	/**
	 * X coordinate.
	 */
	public var x:Float32;	
	
	/**
	 * Y coordinate.
	 */
	public var y:Float32;
	
	/**
	 * Creates a new Vector2 with the informed coordinates.
	 * @param	p_x
	 * @param	p_y
	 */
	public function new(p_x:Float32=0,p_y:Float32=0) 
	{
		x = p_x;
		y = p_y;
	}
	
	/**
	 * Sets all components of this Vector3. Returns its own reference.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @return
	 */
	public function Set(p_x:Float32= 0, p_y:Float32= 0):Vector2 { x = p_x; y = p_y; return this; }
	
	/**
	 * Sets all components of this vector using other vector as template. Returns its own reference.
	 * @param	v
	 * @return
	 */
	public function Set2(v:Vector2):Vector2 { x = v.x; y = v.y; return this; }
	
	/**
	 * Sets all components of this vector using a Vector3 as template. Returns its own reference.
	 * @param	v
	 * @return
	 */
	public function Set3(v:Vector3):Vector2 { x = v.x; y = v.y; return this; }
	
	/**
	 * Sets all components of this vector using other vector as template. Returns its own reference.
	 * @param	v
	 * @return
	 */
	public function Set4(v:Vector4):Vector2 { x = v.x; y = v.y; return this; }
	
	/**
	 * Returns one of its coordinates indexed by an integer where 0 == x, 1 == y and 2 == z.
	 * @param	p
	 * @return
	 */
	public function Get(p : Int):Float32{ return p == 0 ? x : y; }
	
	/**
	 * Adds this vector with another one, component-wise. Returns its own reference.
	 * @param	p_v
	 * @return
	 */
	public function Add(p_v : Vector2):Vector2 { x += p_v.x; y += p_v.y; return this; }
	
	/**
	 * Subtracts this vector with another one, component-wise. Returns its own reference.
	 * @param	p_v
	 * @return
	 */
	public function Sub(p_v : Vector2):Vector2 { x -= p_v.x; y -= p_v.y; return this; }
	
	/**
	 * Subtracts this vector with another one, component-wise. Returns its own reference.
	 * @param	p_v
	 * @return
	 */
	public function Multiply(p_v : Vector2):Vector2 { x *= p_v.x; y *= p_v.y; return this; }
		
	/**
	 * Scales this vector using the informed scalar. Returns its own reference.
	 * @param	p_s
	 * @return
	 */
	public function Scale(p_s : Float32):Vector2 { x *= p_s; y *= p_s; return this; }
	
	/**
	 * Moves this point towards the target using the specified step. If this point reaches target it returns true, otherwise returns false.
	 * @param	p_to
	 * @param	p_step
	 * @return
	 */
	public function Step(p_to : Vector2, p_step : Float32):Bool
	{
		var vx : Float32 = p_to.x - x;
		var vy : Float32 = p_to.y - y;		
		var l : Float32 = Math.sqrt(vx * vx + vy * vy);
		if (l <= Mathf.Epsilon) return false;
		var s : Float32 = p_step > l ? l : p_step;
		l = s / l;		
		vx *= l;
		vy *= l;		
		x += vx;
		y += vy;		
		return true;
	}
	
	/**
	 * Reflects this vector around the normal of a given surface.
	 * @param	p_normal
	 * @return
	 */
	public function Reflect(p_normal:Vector2):Vector2
	{
		var d : Float32 = Math.min(0.0,Dot(p_normal, this)) * 2.0;		
		x += -p_normal.x * d;
		y += -p_normal.y * d;		
		return this;
	}
	
	/**
	 * Inverts the vector components and returns itself.
	 * @return
	 */
	public inline function Invert():Vector2 { x = -x; y = -y; return this; }
	
	/**
	 * Normalizes the vector and returns its own instance.
	 * @return
	 */
	public function Normalize():Vector2
	{
		var l:Float32= length;
		if (l <= 0) return this;
		x *= (l = 1.0 / l);
		y *= l;		
		return this;
	}
	
	/**
	 * Returns this Vector2 as Array<Float32>.
	 * @return
	 */
	public function ToArray() : Array<Float32> { return [x,y]; }
	
	/**
	 * Returns the String form of this vector.
	 * @return
	 */
	public function ToString(p_places:Int=2):String { return "["+Mathf.RoundPlaces(x,p_places)+","+Mathf.RoundPlaces(y,p_places)+"]"; }
	
	/**
	 * Parses a string with the required delimiter into a new instance.
	 * @param	p_data
	 * @return
	 */
	static public function Parse(p_data : String,p_delimiter:String=" "):Vector2
	{
		var tk : Array<String> = p_data.split(p_delimiter);		
		return Vector2.zero.Set(
		Std.parseFloat(StringTools.trim(tk[0])),
		Std.parseFloat(StringTools.trim(tk[1])));				
	}
	
}