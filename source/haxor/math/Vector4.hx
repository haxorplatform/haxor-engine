package haxor.math;
import haxor.context.EngineContext;

/**
 * Class that represents a 4 float tuple.
 * @author Eduardo Pons
 */
class Vector4
{
	/**
	 * Returns a temporary cached instance of this class for local calculations speedup.  [warning] The data isn't setup in any way.
	 */
	static public var temp(get_temp, null):Vector4; 
	static private inline function get_temp():Vector4 { return EngineContext.data.v4; }
	
	/**
	 * Returns a new Vector4(0,0,0,0).
	 */
	static public var zero(get_zero, null):Vector4;
	static private inline function get_zero():Vector4 { return new Vector4(0,0,0,0); }
	
	/**
	 * Returns a new Vector4(1,1,1,1).
	 */
	static public var one(get_one, null):Vector4;
	static private inline function get_one():Vector4 { return new Vector4(1, 1, 1, 1); }
	
	/**
	 * Returns a new Vector4(0,0,0,1).
	 */
	static public var W(get_W, null):Vector4;
	static private inline function get_W():Vector4 { return new Vector4(0,0,0,1); }
	
	/**
	 * Linear interpolates the vector.
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
	
	/**
	 * Returns a copy of this vector.
	 */
	public var clone(get_clone, null) : Vector4;
	private inline function get_clone():Vector4 { return new Vector4(x, y,z,w); }	
	
	/**
	 * Returns this vector as a RGBA color copy.
	 */
	public var rgba(get_rgba, null) : Color;	
	private inline function get_rgba():Color { return new Color(x, y, z, w); }
	
	/**
	 * Returns this vector as a RGB color copy.
	 */
	public var rgb(get_rgb, null) : Color;	
	private inline function get_rgb():Color { return new Color(x, y,z); }
	
	/**
	 * Returns this vector as a Vector3 copy.
	 */
	public var xyz(get_xyz, null) : Vector3;	
	private inline function get_xyz():Vector3 { return new Vector3(x, y,z); }
	
	/**
	 * Returns this vector as a Vector2 copy.
	 */
	public var xy(get_xy, null) : Vector2;	
	private inline function get_xy():Vector2 { return new Vector2(x, y); }
	
	/**
	 * Returns the length of this vector.
	 */
	public var length(get_length, null) : Float;	
	private inline function get_length():Float { return Math.sqrt(x * x + y * y + z * z + w*w); }
	
	/**
	 * Returns the squared length.
	 */
	public var lengthSqr(get_lengthSqr, null) : Float;	
	private inline function get_lengthSqr():Float { return (x * x + y * y + z * z + w * w); }
	
	/**
	 * Returns a copy of this vector normalized.
	 */
	public var normalized(get_normalized, null) : Vector4;
	private inline function get_normalized():Vector4 { return clone.Normalize(); }
	
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
	 * W coordinate.
	 */
	public var w:Float;

	/**
	 * Creates a new Vector4.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 */
	public function new(p_x:Float=0,p_y:Float=0,p_z:Float=0,p_w:Float=0) 
	{
		x = p_x;
		y = p_y;
		z = p_z;
		w = p_w;
	}
	
	/**
	 * Returns one of its coordinates indexed by an integer where 0 == x, 1 == y and 2 == z, 3 == w.
	 * @param	p
	 * @return
	 */
	public function Get(p : Int):Float { return p == 0 ? x  : (p == 1 ? y : (p==2 ? z : w)); }
	
	/**
	 * Sets all components of this Vector4. Returns its own reference.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 * @return
	 */
	public function Set(p_x:Float = 0, p_y:Float = 0, p_z:Float = 0, p_w:Float = 0):Vector4 { x = p_x; y = p_y; z = p_z; w = p_w; return this; }
	
	/**
	 * Sets all components of this vector using a Vector2 as template. Returns its own reference.
	 * @param	v
	 * @return
	 */
	public function Set2(v:Vector2):Vector4 { x = v.x; y = v.y; return this; }
	
	/**
	 * Sets all components of this vector using other vector as template. Returns its own reference.
	 * @param	v
	 * @return
	 */
	public function Set3(v:Vector3):Vector4 { x = v.x; y = v.y; z = v.z; return this; }
	
	/**
	 * Sets all components of this vector using a Color as template. Returns its own reference.
	 * @param	v
	 * @return
	 */
	public function SetColor(v:Color):Vector4 { x = v.r; y = v.g; z = v.b; return this; }
	
	/**
	 * Adds this vector with another one, component-wise. Returns its own reference.
	 * @param	p_v
	 * @return
	 */
	public function Add(p_v : Vector4):Vector4 { x += p_v.x; y += p_v.y; z += p_v.z; w += p_v.w; return this; }
	
	/**
	 * Subtracts this vector with another one, component-wise. Returns its own reference.
	 * @param	p_v
	 * @return
	 */
	public function Sub(p_v : Vector4):Vector4 { x -= p_v.x; y -= p_v.y; z -= p_v.z; w -= p_v.w; return this; }
	
	/**
	 * Subtracts this vector with another one, component-wise. Returns its own reference.
	 * @param	p_v
	 * @return
	 */
	public function Multiply(p_v : Vector4):Vector4 { x *= p_v.x; y *= p_v.y; z *= p_v.z; w *= p_v.w; return this; }
	
	/**
	 * Normalizes the vector and returns its own reference.
	 * @return
	 */
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
	
	/**
	 * Returns a boolean telling if this vector is out of the w-sized projection box.
	 * @return
	 */
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
	 * Converts this vector to an Array<Float>
	 * @return
	 */
	public function ToArray() : Array<Float> { return [x,y,z,w]; }
	
		
	/**
	 * Returns the String form of this vector.
	 * @return
	 */
	public function ToString(p_places:Int=2):String { return "["+Mathf.RoundPlaces(x,p_places)+","+Mathf.RoundPlaces(y,p_places)+","+Mathf.RoundPlaces(z,p_places)+","+Mathf.RoundPlaces(w,p_places)+"]"; }
		
	/**
	 * Parses a string with the required delimiter into a new instance.
	 * @param	p_data
	 * @return
	 */
	static public function Parse(p_data : String,p_delimiter:String=" "):Vector4
	{
		var tk : Array<String> = p_data.split(p_delimiter);		
		return Vector4.zero.Set(
		Std.parseFloat(StringTools.trim(tk[0])),
		Std.parseFloat(StringTools.trim(tk[1])),
		Std.parseFloat(StringTools.trim(tk[2])),
		Std.parseFloat(StringTools.trim(tk[3])));				
	}
	
	
}