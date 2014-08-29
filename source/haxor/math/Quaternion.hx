package haxor.math;
import haxor.context.DataContext;
import haxor.context.EngineContext;

/**
 * Class that represents a rotation quaternion.
 * @author Eduardo Pons
 */
class Quaternion
{
	/**
	 * Returns a temporary cached instance of this class for local calculations speedup.  [warning] The data isn't setup in any way.
	 */
	static public var temp(get_temp, null):Quaternion; 
	static private inline function get_temp():Quaternion { return EngineContext.data.q; }
	
	/**
	 * Returns the identity quaternion without any rotation.
	 */
	static public var identity(get_identity, null):Quaternion;	
	static private inline function get_identity():Quaternion { return new Quaternion(0, 0, 0, 1.0); }
	
	/**
	 * Returns the Quaternion represented by the euler rotation.
	 * @param	p_euler
	 * @param	p_result
	 * @return
	 */
	static public function FromEuler(p_euler : Vector3, p_result:Quaternion = null):Quaternion
	{
		var r : Quaternion = p_result == null ? (new Quaternion()) : p_result;
		var c : Vector3 = Vector3.temp;
		var s : Vector3 = Vector3.temp;
		var k : Float = 0.5 * Mathf.Deg2Rad;
		var e : Vector3 = Vector3.temp.Set(p_euler.x*k,p_euler.y*k,p_euler.z*k);
		c.Set(Math.cos(e.x), Math.cos(e.y), Math.cos(e.z));
		s.Set(Math.sin(e.x), Math.sin(e.y), Math.sin(e.z));		
		r.x = (s.x*c.y*c.z) - (c.x*s.y*s.z);
		r.y = (c.x*s.y*c.z) + (s.x*c.y*s.z);
		r.z = (c.x*c.y*s.z) - (s.x*s.y*c.z);
		r.w = (c.x*c.y*c.z) + (s.x*s.y*s.z);
		return r;
	}
	
	/**
	 * Returns the euler rotation from the informed quaternion.
	 * @param	p_quaternion
	 * @param	p_result
	 * @return
	 */
	static public function ToEuler(p_quaternion : Quaternion, p_result:Vector3 = null):Vector3
	{
		var q : Quaternion = p_quaternion;
		var r : Vector3 = p_result == null ? (new Vector3()) : p_result;		
		var test : Float = (q.x * q.y) + (q.z * q.w);		
		if (test > 0.499) 
		{ // singularity at north pole
			r.y = 2 * Math.atan2(q.x,q.w) * Mathf.Rad2Deg;
			r.z = Math.PI*0.5 * Mathf.Rad2Deg;
			r.x = 0;
			return r;
		}
		if (test < -0.499)
		{ // singularity at south pole
			r.y = -2.0 * Math.atan2(q.x,q.w);
			r.z = -Math.PI*0.5 * Mathf.Rad2Deg;
			r.x = 0;
			return r;
		}
		//*/
		var sqx : Float = q.x * q.x;		
		var sqy : Float = q.y * q.y;		
		var sqz : Float = q.z * q.z;		
		r.y  = Math.atan2(2.0 * q.y * q.w - 2.0 * q.x * q.z, 1.0 - 2.0 * sqy - 2.0 * sqz) * Mathf.Rad2Deg;
		r.z  = Math.asin (2.0 * test) * Mathf.Rad2Deg;
		r.x  = Math.atan2(2.0 * q.x * q.w - 2.0 * q.y * q.z , 1.0 - 2.0 * sqx - 2.0 * sqz) * Mathf.Rad2Deg;
		return r;		
	}
	
	/**
	 * Returns a new Quaternion using the informed matrix.
	 * @param	p_matrix
	 * @param	p_result
	 * @return
	 */
	static public function FromMatrix(p_matrix : Matrix4,p_result : Quaternion=null):Quaternion
	{
		var r : Quaternion = p_result == null ? (new Quaternion()) : p_result;
		var v : Matrix4 = p_matrix;
		var fourXSquaredMinus1 : Float = v.m00 - v.m11 - v.m22;
		var fourYSquaredMinus1 : Float = v.m11 - v.m00 - v.m22;
		var fourZSquaredMinus1 : Float = v.m22 - v.m00 - v.m11;
		var fourWSquaredMinus1 : Float = v.m00 + v.m11 + v.m22;
		var biggestIndex 			 : Int = 0;
		var fourBiggestSquaredMinus1 : Float = fourWSquaredMinus1;		
		if(fourXSquaredMinus1 > fourBiggestSquaredMinus1) { fourBiggestSquaredMinus1 = fourXSquaredMinus1; biggestIndex = 1; }
		if(fourYSquaredMinus1 > fourBiggestSquaredMinus1) {	fourBiggestSquaredMinus1 = fourYSquaredMinus1; biggestIndex = 2; }
		if(fourZSquaredMinus1 > fourBiggestSquaredMinus1) {	fourBiggestSquaredMinus1 = fourZSquaredMinus1; biggestIndex = 3; }
		var biggestVal 	: Float = Math.sqrt(fourBiggestSquaredMinus1 + 1.0) * 0.5;
		var mult 		: Float = 0.25 / biggestVal;
		switch(biggestIndex)
		{
			case 0:	r.w = biggestVal;	r.x = (v.m21 - v.m12) * mult;	r.y = (v.m02 - v.m20) * mult;	r.z = (v.m10 - v.m01) * mult;			
			case 1:	r.w = (v.m21 - v.m12) * mult;	r.x = biggestVal;	r.y = (v.m10 + v.m01) * mult;	r.z = (v.m02 + v.m20) * mult;			
			case 2:	r.w = (v.m02 - v.m20) * mult;	r.x = (v.m10 + v.m01) * mult;	r.y = biggestVal;	r.z = (v.m21 + v.m12) * mult;			
			case 3:	r.w = (v.m10 - v.m01) * mult;	r.x = (v.m02 + v.m20) * mult;	r.y = (v.m21 + v.m12) * mult;	r.z = biggestVal;
		}
		return r;
	}
	
	/**
	 * Returns the Dot product of the informed quaternions.
	 * @param	p_a
	 * @param	p_b
	 * @return
	 */
	static public inline function Dot(p_a : Quaternion, p_b : Quaternion) : Float { return ((p_a.x * p_b.x) + (p_a.y * p_b.y) + (p_a.z * p_b.z) + (p_a.w * p_b.w)); }
	
	/**
	 * Returns the quaternion that rotates from A to B.
	 * @param	p_a
	 * @param	p_b
	 * @return
	 */
	static public function DeltaRotation(p_a : Quaternion, p_b : Quaternion,p_result:Quaternion=null):Quaternion
	{
		var r : Quaternion = p_result == null ? (new Quaternion()) : p_result;
		Quaternion.Inverse(p_a, r);
		r.Multiply(p_b);
		return r;
	}
	
	/**
	 * Returns the inverse rotation of this quaternion.
	 * @param	p_q
	 * @return
	 */
	static public function Inverse(p_q : Quaternion,p_result:Quaternion=null):Quaternion
	{
		var d : Float = 1.0/Dot(p_q, p_q);
		var r : Quaternion = p_result == null ? (new Quaternion()) : p_result;
		return r.Set( -p_q.x * d, -p_q.y*d, -p_q.z*d, p_q.w*d);
	}
	
	/**
	 * Linear interpolates 2 quaternions with its rotation adjusted.
	 * @param	p_a
	 * @param	p_b
	 * @param	p_ratio
	 * @return
	 */
	static public function Lerp(p_a:Quaternion, p_b : Quaternion, p_ratio : Float,p_result:Quaternion=null):Quaternion
	{
		var c:Quaternion    = p_result == null ? new Quaternion() : p_result;
		var ca : Quaternion = p_a.clone;
		var dot : Float = Quaternion.Dot(p_a,p_b);
		if (dot < 0.0) 
		{
			ca.w = -ca.w;
			ca.x = -ca.x;
			ca.y = -ca.y;
			ca.z = -ca.z;
		}		
		c.x = ca.x + (p_b.x - ca.x) * p_ratio;
		c.y = ca.y + (p_b.y - ca.y) * p_ratio;
		c.z = ca.z + (p_b.z - ca.z) * p_ratio;
		c.w = ca.w + (p_b.w - ca.w) * p_ratio;
		c.Normalize();
		return c;
	}
	
	/**
	 * 
	 * @param	p_a
	 * @param	p_b
	 * @param	p_ratio
	 * @return
	 */
	static public function Slerp(p_a:Quaternion, p_b:Quaternion, p_ratio:Float):Quaternion
	{
		/*
		//Faster Slerp
		//Use lerp with a spline to adjust middle path.
		float f = 1.0f - 0.7878088f*cosAlpha;
		float k = 0.5069269f;
		float b = 2*k;
		float c = -3*k;
		float d = 1 + k;
		t = t*(b*t + c) + d;
		//*/
		// quaternion to return
		var qm : Quaternion = new Quaternion();		
		var z : Quaternion = Quaternion.temp.SetQuaternion(p_b);
		var cosTheta : Float = Dot(p_a, p_b);		
		// If cosTheta < 0, the interpolation will take the long way around the sphere. 
		// To fix this, one quat must be negated.
		if (cosTheta < 0.0)
		{			
			z.Invert();    //-y;
			cosTheta = -cosTheta;
		}

		// Perform a linear interpolation when cosTheta is close to 1 to avoid side effect of sin(angle) becoming a zero denominator
		if(cosTheta > 1.0 - Mathf.Epsilon)
		{
			// Linear interpolation
			qm.Set(
			Mathf.Lerp(p_a.x, z.x, p_ratio),
			Mathf.Lerp(p_a.y, z.y, p_ratio),
			Mathf.Lerp(p_a.z, z.z, p_ratio),
			Mathf.Lerp(p_a.w, z.w, p_ratio));			
		}
		else
		{
			// Essential Mathematics, page 467
			var angle : Float = Math.acos(cosTheta);
			var s  : Float = 1.0/Math.sin(angle);
			var s0 : Float = Math.sin((1.0 - p_ratio) * angle);
			var s1 : Float = Math.sin(p_ratio * angle);
			qm.x = ((s0 * p_a.x) + (s1 * z.x)) * s;
			qm.y = ((s0 * p_a.y) + (s1 * z.y)) * s;
			qm.z = ((s0 * p_a.z) + (s1 * z.z)) * s;
			qm.w = ((s0 * p_a.w) + (s1 * z.w)) * s;
		}		
		return qm;
	}
	
	/**
	 * Creates a new Quaternion that applies angle degrees around the informed axis.
	 * @param	p_axis
	 * @param	p_angle
	 * @return
	 */
	static public function FromAxisAngle(p_axis : Vector3, p_angle : Float) : Quaternion	
	{		
		p_angle = p_angle * 0.5 * Mathf.Deg2Rad;
		var l:Float = p_axis.length;
		if (Mathf.Abs(l - 1.0) > Mathf.Epsilon) p_axis.Normalize();
		var s:Float = Mathf.Sin(p_angle);		
		return (new Quaternion(p_axis.x * s, p_axis.y * s, p_axis.z * s, Mathf.Cos(p_angle)));
	}
	
	/**
	 * 
	 * @param	p_from
	 * @param	p_at
	 * @param	p_up
	 * @return
	 */
	static public inline function LookAt(p_eye : Vector3, p_at : Vector3, p_up : Vector3 = null, p_result:Quaternion = null) : Quaternion 
	{ 
		return Quaternion.FromMatrix(Matrix4.LookAt(p_eye, p_at, p_up, Matrix4.temp), p_result); 
	}
	
	/**
	 * Returns the rotation that look towards the informed direction.
	 * @param	p_forward
	 * @param	p_up
	 * @return
	 */
	static public inline function LookRotation(p_forward : Vector3, p_up : Vector3 = null) : Quaternion { return Matrix4.LookRotation(p_forward, p_up,Matrix4.temp).quaternion; }
	
	/**
	 * Returns the Matrix4 form of this quaternion.
	 */
	public var matrix(get_matrix, set_matrix):Matrix4;
	private inline function get_matrix():Matrix4 			{ return Matrix4.FromQuaternion(this); }
	private inline function set_matrix(v:Matrix4):Matrix4 	{ FromMatrix(v, this); return v; }
	
	/**
	 * Get/Set the euler angles for this quaternion.
	 */
	public var euler(get_euler, set_euler) : Vector3;
	private function get_euler():Vector3 { return ToEuler(this); }
	private function set_euler(v:Vector3):Vector3 { FromEuler(v, this);	return v; }
		
	/**
	 * Returns a copy of this quaternion.
	 */
	public var clone(get_clone, null) : Quaternion;
	private inline function get_clone():Quaternion { return new Quaternion(x, y,z,w); }		
	
	/**
	 * Returns a copy of this quaternion as Vector4.
	 */
	public var xyzw(get_xyzw, null) : Vector4;
	private inline function get_xyzw():Vector4 { return new Vector4(x, y,z,w); }	
	
	/**
	 * Returns the length of this quaternion.
	 */
	public var length(get_length, null) : Float;	
	private inline function get_length():Float { return Math.sqrt(x * x + y * y + z * z + w * w); }	
	
	/**
	 * Returns a copy of this quaternion normalized.
	 */
	public var normalized(get_normalized, null) : Quaternion;
	private inline function get_normalized():Quaternion { return clone.Normalize(); }
	
	/**
	 * X component.
	 */
	public var x:Float;
	
	/**
	 * Y component.
	 */
	public var y:Float;
	
	/**
	 * Z component.
	 */
	public var z:Float;
	
	/**
	 * W component.
	 */
	public var w:Float;
	
	/**
	 * Creates a new Quaternion.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 */
	public function new(p_x:Float=0,p_y:Float=0,p_z:Float=0,p_w:Float=1.0) 
	{
		x = p_x; y = p_y; z = p_z; w = p_w; 
	}
	
	/**
	 * Sets all components of this Quaternion. Returns its own reference.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 * @return
	 */
	public function Set(p_x:Float = 0, p_y:Float = 0, p_z:Float = 0, p_w:Float = 1.0):Quaternion { x = p_x; y = p_y; z = p_z; w = p_w; return this; }
	
	/**
	 * Sets all components with the template Quaternion. Returns its own reference.
	 * @param	p_q
	 * @return
	 */
	public function SetQuaternion(p_q:Quaternion):Quaternion { x = p_q.x; y = p_q.y; z = p_q.z; w = p_q.w; return this; }
	
	/**
	 * Normalizes this quaternion.
	 * @return
	 */
	public function Normalize():Quaternion
	{
		var l:Float = length;
		if (l <= 0)
		{
			x = y = z = 0.0; w = 1.0;
			return this;
		}
		x *= (l = 1.0 / l);
		y *= l;
		z *= l;
		w *= l;
		return this;
	}
	
	/**
	 * Returns the conjugate of this quaternion.
	 */
	public var conjugate(get_conjugate, null):Quaternion;
	private inline function get_conjugate():Quaternion { return new Quaternion(-x, -y, -z, w); }
	
	/**
	 * Returns the inverse of this quaternion.
	 */
	public var inverse(get_inverse, null):Quaternion;
	private inline function get_inverse():Quaternion { return Inverse(this); }
	
	/**
	 * Returns this Quaternion with the components inverted.
	 * @return
	 */
	public function Invert():Quaternion { x = -x; y = -y; z = -z; w = -w; return this; }
	
	/**
	 * Applies a scalar to this quaternion. Returns its own reference.
	 * @param	p_v
	 * @return
	 */
	public function Scale(p_v:Float):Quaternion { x *= p_v; y *= p_v; z *= p_v; w *= p_v; return this; }
	
	/**
	 * Multiplies the informed quaternion to this instance. Returns its own reference.
	 * @param	p_v
	 * @param	p_normalize
	 * @return
	 */
	public function Multiply(p_v:Quaternion,p_normalize:Bool=false):Quaternion
	{
		var vx:Float = (w * p_v.x) + (x * p_v.w) + (y * p_v.z) - (z * p_v.y);
		var vy:Float = (w * p_v.y) + (y * p_v.w) + (z * p_v.x) - (x * p_v.z);
		var vz:Float = (w * p_v.z) + (z * p_v.w) + (x * p_v.y) - (y * p_v.x);
		var vw:Float = (w * p_v.w) - (x * p_v.x) - (y * p_v.y) - (z * p_v.z);   				
		x = vx; y = vy;	z = vz; w = vw;				
		return p_normalize ? Normalize() : this;
	}
	
	/**
	 * Applies this quaternion to the informed vector.
	 * @param	p_v
	 * @return
	 */
	public function Rotate(p_v:Vector3):Vector3
	{
		var l : Float = Math.sqrt(p_v.x * p_v.x + p_v.y * p_v.y + p_v.z * p_v.z);
		var nl : Float = l<=0.0 ? 0.0 : (1.0 / l);
		p_v.x *= nl;
		p_v.y *= nl;
		p_v.z *= nl;
		var qv:Quaternion 	= Quaternion.temp.Set(p_v.x, p_v.y, p_v.z, 0);
		var a:Quaternion 	= Quaternion.temp.SetQuaternion(this);		
		var c:Quaternion	= Quaternion.temp.Set( -x, -y, -z, w);
		a.Multiply(qv.Multiply(c));
		p_v.x = a.x*l;
		p_v.y = a.y*l;
		p_v.z = a.z*l;
		return p_v;
	}
	
	/**
	 * Sets this quaternion as a delta rotation that moves from this quaternion to the target one. Returns its own reference.
	 * @param	p_q
	 * @return
	 */
	public inline function Delta(p_q : Quaternion):Quaternion { return SetQuaternion(DeltaRotation(this, p_q, Quaternion.temp));	}
	
	/**
	 * Resets this quaternion structure so it represents the axis/angle rotation. Returns its own reference.
	 * @param	p_axis
	 * @param	p_angle
	 * @return
	 */
	public function SetAxisAngle(p_axis : Vector3, p_angle : Float):Quaternion
	{
		p_angle = p_angle * 0.5 * Mathf.Deg2Rad;
		var l:Float = p_axis.length;
		if (Mathf.Abs(l - 1.0) > Mathf.Epsilon) p_axis.Normalize();
		var s:Float = Mathf.Sin(p_angle);		
		return Set(p_axis.x * s, p_axis.y * s, p_axis.z * s, Mathf.Cos(p_angle));		
	}
	
	/**
	 * Converts this vector to an Array<Float>
	 * @return
	 */
	public function ToArray() : Array<Float> { return [x, y, z, w]; }
	
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
	static public function Parse(p_data : String,p_delimiter:String=" "):Quaternion
	{
		var tk : Array<String> = p_data.split(p_delimiter);		
		return Quaternion.identity.Set(
		Std.parseFloat(StringTools.trim(tk[0])),
		Std.parseFloat(StringTools.trim(tk[1])),
		Std.parseFloat(StringTools.trim(tk[2])),
		Std.parseFloat(StringTools.trim(tk[3])));				
	}
	
}