package haxor.math;

/**
 * Class that represents a rotation quaternion.
 * @author Eduardo Pons
 */
class Quaternion
{
	
	/**
	 * Returns the identity quaternion without any rotation.
	 */
	static public var identity(get_identity, null):Quaternion;	
	static private inline function get_identity():Quaternion { return new Quaternion(0, 0, 0, 1.0); }
	
	/**
	 * Returns the Dot product of the informed quaternions.
	 * @param	p_a
	 * @param	p_b
	 * @return
	 */
	static public inline function Dot(p_a : Quaternion, p_b : Quaternion) : Float { return ((p_a.x * p_b.x) + (p_a.y * p_b.y) + (p_a.z * p_b.z) + (p_a.w * p_b.w)); }
	
	/**
	 * Linear interpolates 2 quaternions with its rotation adjusted.
	 * @param	p_a
	 * @param	p_b
	 * @param	p_ratio
	 * @return
	 */
	static public function Lerp(p_a:Quaternion, p_b : Quaternion, p_ratio : Float):Quaternion
	{
		var c:Quaternion    = new Quaternion();
		var ca : Quaternion = p_a.clone;
		var dot : Float = p_a.Dot(p_b);
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
		// quaternion to return
		var qm : Quaternion = new Quaternion();
		// Calculate angle between them.
		var cosHalfTheta : Float = p_a.w * p_b.w + p_a.x * p_b.x + p_a.y * p_b.y + p_a.z * p_b.z;
		// if qa=qb or qa=-qb then theta = 0 and we can return qa
		if (Math.abs(cosHalfTheta) >= 1.0)
		{
			qm.w = p_a.w;qm.x = p_a.x;qm.y = p_a.y;qm.z = p_a.z;
			return qm;
		}
		// Calculate temporary values.
		var halfTheta 	 : Float = Math.acos(cosHalfTheta);
		var sinHalfTheta : Float = Math.sqrt(1.0 - cosHalfTheta*cosHalfTheta);
		// if theta = 180 degrees then result is not fully defined
		// we could rotate around any axis normal to qa or qb
		if (Math.abs(sinHalfTheta) < 0.001)
		{ // fabs is floating point absolute
			qm.w = (p_a.w * 0.5 + p_b.w * 0.5);
			qm.x = (p_a.x * 0.5 + p_b.x * 0.5);
			qm.y = (p_a.y * 0.5 + p_b.y * 0.5);
			qm.z = (p_a.z * 0.5 + p_b.z * 0.5);
			return qm;
		}
		var ratioA : Float = Math.sin((1.0 - p_ratio) * halfTheta) / sinHalfTheta;
		var ratioB : Float = Math.sin(p_ratio * halfTheta) / sinHalfTheta; 
		//calculate Quaternion.
		qm.w = (p_a.w * ratioA + p_b.w * ratioB);
		qm.x = (p_a.x * ratioA + p_b.x * ratioB);
		qm.y = (p_a.y * ratioA + p_b.y * ratioB);
		qm.z = (p_a.z * ratioA + p_b.z * ratioB);
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
		return new Quaternion(p_axis.x * s, p_axis.y * s, p_axis.z * s, Mathf.Cos(p_angle));
	}
	
	
	/**
	 * 
	 * @param	p_euler
	 * @return
	 */
	static public function FromEuler(p_euler : Vector3):Quaternion
	{
		// Assuming the angles are in radians.
		var q : Quaternion = new Quaternion();
		var ax : Float = p_euler.x * Mathf.Rad2Deg;
		var ay : Float = p_euler.y * Mathf.Rad2Deg;
		var az : Float = p_euler.z * Mathf.Rad2Deg;		
		var c1 : Float = Mathf.Cos(ax*0.5);
		var s1 : Float = Mathf.Sin(ax*0.5);
		var c2 : Float = Mathf.Cos(ay*0.5);
		var s2 : Float = Mathf.Sin(ay*0.5);
		var c3 : Float = Mathf.Cos(az*0.5);
		var s3 : Float = Mathf.Sin(az*0.5);
		var c1c2 : Float = c1*c2;
		var s1s2 : Float = s1*s2;
		q.w = c1c2 * c3 - s1s2 * s3;
		q.x = c1c2 * s3 + s1s2 * c3;
		q.y = s1 * c2 * c3 + c1 * s2 * s3;
		q.z = c1 * s2 * c3 - s1 * c2 * s3;
		q.Normalize();
		return q;
	}
	
	/**
	 * 
	 * @param	p_from
	 * @param	p_at
	 * @param	p_up
	 * @return
	 */
	static public function LookAt(p_from : Vector3, p_at : Vector3,p_up : Vector3=null) : Quaternion
	{
		return Matrix4.LookAt(p_from, p_at, p_up).quaternion;
	}
	
	/**
	 * 
	 * @param	p_forward
	 * @param	p_up
	 * @return
	 */
	static public function LookRotation(p_forward : Vector3, p_up : Vector3) : Quaternion
	{		
		return Matrix4.LookRotation(p_forward,p_up).quaternion;
	}
	
	/**
	 * 
	 */
	public var matrix(get_matrix, null):Matrix4;
	private function get_matrix():Matrix4
	{
		Normalize();
		var m : Matrix4 = Matrix4.temp;// Matrix4.identity;
		var x2:Float = x * x;
		var y2:Float = y * y;
		var z2:Float = z * z;		
		var xy:Float = x * y;
		var xz:Float = x * z;
		var yz:Float = y * z;
		var xw:Float = w * x;
		var yw:Float = w * y;
		var zw:Float = w * z;
		m.m00 = 1.0 - 2.0 * ( y2 + z2 );
		m.m01 =       2.0 * ( xy - zw );
		m.m02 =       2.0 * ( xz + yw );		
		m.m10 =       2.0 * ( xy + zw );
		m.m11 = 1.0 - 2.0 * ( x2 + z2 );
		m.m12 =       2.0 * ( yz - xw );		
		m.m20 =       2.0 * ( xz - yw );
		m.m21 =       2.0 * ( yz + xw );
		m.m22 = 1.0 - 2.0 * ( x2 + y2 );
		m.m30 = m.m31 = m.m32 = 0.0; m.m33 = 1.0;
		return m;
	}	
	
	public var euler(get_euler, null) : Vector3;
	private function get_euler():Vector3 
	{ 
		Normalize();
		var test : Float = x * y + z * w;
		var a : Vector3 = new Vector3();
		if (test > 0.499) 
		{ // singularity at north pole
			a.x = 2.0 * Mathf.Atan2(x,w) * Mathf.Rad2Deg;
			a.y = Mathf.HalfPI * Mathf.Rad2Deg;
			a.z = 0;
			return a;
		}
		if (test < -0.499) 
		{ // singularity at south pole
			a.x = -2.0 * Mathf.Atan2(x,w) * Mathf.Rad2Deg;
			a.y = - Mathf.HalfPI * Mathf.Rad2Deg;
			a.z = 0;
			return a;
		}
		var sqx : Float = x * x;
		var sqy : Float = y * y;
		var sqz : Float = z * z;		
		a.x = Mathf.Atan2(2.0 * y * w - 2.0 * x * z , 1.0 - 2.0 * sqy - 2.0 * sqz) * Mathf.Rad2Deg;
		a.y = Mathf.Asin(2.0 * test) * Mathf.Rad2Deg;
		a.z = Mathf.Atan2(2.0 * x * w - 2.0 * y * z , 1.0 - 2.0 * sqx - 2.0 * sqz) * Mathf.Rad2Deg;		
		return a;
	}
		
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
		x = p_x;
		y = p_y;
		z = p_z;
		w = p_w;
	}
	
	/**
	 * Sets all components of this Vector3. Returns its own reference.
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 * @return
	 */
	public function Set(p_x:Float = 0, p_y:Float = 0, p_z:Float = 0, p_w:Float = 1.0):Quaternion { x = p_x; y = p_y; z = p_z; w = p_w; return this; }
	
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
	public function Multiply(p_v:Quaternion,p_normalize:Bool=true):Quaternion
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
	public function Multiply3(p_v:Vector3):Vector3
	{
		var l : Float = Math.sqrt(p_v.x * p_v.x + p_v.y * p_v.y + p_v.z * p_v.z);
		var nl : Float = 1.0 / l;
		p_v.x *= nl;
		p_v.y *= nl;
		p_v.z *= nl;
		var qv:Quaternion = new Quaternion(p_v.x, p_v.y, p_v.z, 0);
		var a:Quaternion = clone;		
		a.Multiply(qv.Multiply(conjugate));
		p_v.x = a.x*l;
		p_v.y = a.y*l;
		p_v.z = a.z*l;
		return p_v;
	}
	
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
		Set(p_axis.x * s, p_axis.y * s, p_axis.z * s, Mathf.Cos(p_angle));
		return this;
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
		
	
}