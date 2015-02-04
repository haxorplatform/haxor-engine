package haxor.math;
import haxor.context.EngineContext;
import haxor.platform.Types.Float32;
import haxor.platform.Types.Float32;


/**
 * Class that describes a 4x4 matrix.
 * @author Eduardo Pons
 */
class Matrix4 
{
	/**
	 * Returns a temporary cached instance of this class for local calculations speedup. [warning] The data isn't setup in any way.
	 */
	static public var temp(get_temp, null):Matrix4; 
	static private inline function get_temp():Matrix4 { return EngineContext.data.m4; }
		
	/**
	 * Returns a new Identity matrix.
	 */
	static public var identity(get_identity, null):Matrix4;	
	static private inline function get_identity():Matrix4 { return new Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1); }
	
	/**
	 * Returns a new Matrix4 from the informed quatenion.
	 * @param	p_quaternion
	 * @param	p_result
	 * @return
	 */
	static public function FromQuaternion(p_quaternion : Quaternion, p_result:Matrix4=null):Matrix4
	{
		var m : Matrix4 = p_result == null ? (new Matrix4()) : p_result;
		var q : Quaternion = p_quaternion;
		var x2:Float32= q.x * q.x;
		var y2:Float32= q.y * q.y;
		var z2:Float32= q.z * q.z;		
		var xy:Float32= q.x * q.y;
		var xz:Float32= q.x * q.z;
		var yz:Float32= q.y * q.z;
		var xw:Float32= q.w * q.x;
		var yw:Float32= q.w * q.y;
		var zw:Float32= q.w * q.z;		
		m.m00 = 1.0 - 2.0 * ( y2 + z2 ); m.m01 =       2.0 * ( xy - zw ); m.m02 =       2.0 * ( xz + yw );	
		m.m10 =       2.0 * ( xy + zw ); m.m11 = 1.0 - 2.0 * ( x2 + z2 ); m.m12 =       2.0 * ( yz - xw );				
		m.m20 =       2.0 * ( xz - yw ); m.m21 =       2.0 * ( yz + xw ); m.m22 = (1.0 - 2.0 * ( x2 + y2 ));		
		m.m30 = m.m31 = m.m32 = 0.0; m.m33 = 1.0;
		return m;
	}
	
	/**
	 * Returns a Matrix4 using the informed array as template.
	 * @param	p_array
	 * @return
	 */
	static public function FromArray(p_array : Array<Float32>,p_result:Matrix4=null):Matrix4 { var res : Matrix4 = p_result == null ? (new Matrix4()) : p_result; for (i in 0...p_array.length) res.SetIndex(i,p_array[i]); return res; }
	
	/**
	 * 
	 * @param	p_position
	 * @param	p_rotation
	 * @param	p_scale
	 * @return
	 */	
	static public inline function TRS(p_position : Vector3, p_rotation : Quaternion, p_scale:Vector3 = null,p_result : Matrix4=null):Matrix4
	{		
		var sx:Float32= p_scale == null ? 1.0 : p_scale.x;			
		var sy:Float32= p_scale == null ? 1.0 : p_scale.y;
		var sz:Float32= p_scale == null ? 1.0 : p_scale.z;		
		var px:Float32= p_position.x;			
		var py:Float32= p_position.y;
		var pz:Float32= p_position.z;							
		var r : Matrix4 = Matrix4.temp;
		Matrix4.FromQuaternion(p_rotation, r);
		var l : Matrix4 = p_result == null ? Matrix4.identity : p_result;
		l.m00 = r.m00 * sx; l.m01 = r.m01 * sy; l.m02 = r.m02 * sz; l.m03 = px;
		l.m10 = r.m10 * sx; l.m11 = r.m11 * sy; l.m12 = r.m12 * sz; l.m13 = py;
		l.m20 = r.m20 * sx; l.m21 = r.m21 * sy; l.m22 = r.m22 * sz; l.m23 = pz;
		l.m30 = l.m31 = l.m32 = 0.0; l.m33 = 1.0;
		return l;
	}
	
	/**
	 * Returns a Frustum projection matrix.
	 * @param	p_left
	 * @param	p_right
	 * @param	p_top
	 * @param	p_bottom
	 * @param	p_near
	 * @param	p_far
	 * @param	p_result
	 * @return
	 */
	static public inline function Frustum(p_left:Float32,p_right:Float32,p_top:Float32,p_bottom:Float32,p_near:Float32,p_far:Float32,p_result:Matrix4=null):Matrix4
	{
		var m : Matrix4 = p_result == null ? (new Matrix4()) : p_result;
		var n2 :Float32= p_near * 2.0;
		var rml:Float32= 1.0 / (p_right - p_left);
		var tmb:Float32= 1.0 / (p_top - p_bottom);
		var fmn:Float32= 1.0 / (p_far - p_near);		
		m.m00 = n2 * rml;	m.m01 = 0.0;		m.m02 = (p_right + p_left) * rml;	m.m03 = 0.0;
		m.m10 = 0.0;		m.m11 = n2 * tmb;   m.m12 = (p_top + p_bottom) * tmb;	m.m13 = 0.0;		
		m.m20 = 0.0;		m.m21 = 0.0;		m.m22 = -(p_near + p_far) * fmn; 	m.m23 = ( -n2 * p_far) * fmn;		
		m.m30 = 0.0;		m.m31 = 0.0;		m.m32 = -1.0;						m.m33 = 0;
		return m;
	}
	
	/**
	 * Returns the Frustum projection inverse matrix.
	 * @param	p_left
	 * @param	p_right
	 * @param	p_top
	 * @param	p_bottom
	 * @param	p_near
	 * @param	p_far
	 * @return
	 */
	static public inline function FrustumInverse(p_left:Float32,p_right:Float32,p_top:Float32,p_bottom:Float32,p_near:Float32,p_far:Float32,p_result:Matrix4=null):Matrix4
	{
		var m : Matrix4 = p_result == null ? (new Matrix4()) : p_result;
		var n2 :Float32= p_near * 2.0;
		var rml:Float32= (p_right - p_left);
		var tmb:Float32= (p_top - p_bottom);
		var fmn:Float32= (p_far - p_near);		
		m.m00 = rml / n2;	m.m01 = 0.0;		m.m02 = 0.0;					m.m03 = (p_right + p_left) / n2;		
		m.m10 = 0.0;		m.m11 = tmb / n2;	m.m12 = 0.0;					m.m13 = (p_top + p_bottom) / n2;		
		m.m20 = 0.0;		m.m21 = 0.0;		m.m22 = 0.0;					m.m23 = -1.0;		
		m.m30 = 0.0;		m.m31 = 0.0;		m.m32 = fmn / (-n2 * p_far);	m.m33 = (p_far + p_near) / (n2 * p_far);
		return m;
	}
	
	/**
	 * Returns a Orthographic projection matrix.
	 * @param	p_left
	 * @param	p_right
	 * @param	p_top
	 * @param	p_bottom
	 * @param	p_near
	 * @param	p_far
	 * @param	p_result
	 * @return
	 */
	static public function Ortho(p_left:Float32,p_right:Float32,p_top:Float32,p_bottom:Float32,p_near:Float32,p_far:Float32,p_result:Matrix4=null):Matrix4
	{
		var m : Matrix4 = p_result == null ? (new Matrix4()) : p_result;
		var n2 :Float32= p_near * 2.0;
		var rml:Float32= 1.0 / (p_right - p_left);
		var tmb:Float32= 1.0 / (p_top - p_bottom);
		var fmn:Float32= 1.0 / (p_far - p_near);
		m.m00 = 2.0 * rml;	m.m01 = 0.0; 		m.m02 = 0.0; 		m.m03 = -(p_right + p_left) * rml;		
		m.m10 = 0.0;        m.m11 = 2.0 * tmb;  m.m12 = 0.0; 		m.m13 = -(p_top + p_bottom) * tmb;		
		m.m20 = 0.0;		m.m21 = 0.0;		m.m22 = -2.0 * fmn;	m.m23 = -(p_far + p_near) * fmn;		
		m.m30 = 0.0; 		m.m31 = 0.0; 		m.m32 = 0.0; 		m.m33 = 1.0;
		return m;
	}
	
	/**
	 * Returns a Orthographic projection inverse matrix.
	 * @param	p_left
	 * @param	p_right
	 * @param	p_top
	 * @param	p_bottom
	 * @param	p_near
	 * @param	p_far
	 * @param	p_result
	 * @return
	 */
	static public function OrthoInverse(p_left:Float32,p_right:Float32,p_top:Float32,p_bottom:Float32,p_near:Float32,p_far:Float32,p_result:Matrix4=null):Matrix4
	{
		var m : Matrix4 = Matrix4.temp.SetOrtho(p_left,p_right,p_top,p_bottom,p_near,p_far);
		return Matrix4.GetInverseTransform(m, p_result);
	}
	
	/**
	 * Returns a Perspective projection matrix.
	 * @param	p_fov
	 * @param	p_aspect
	 * @param	p_near
	 * @param	p_far
	 * @param	p_result
	 * @return
	 */
	static public function Perspective(p_fov:Float32,p_aspect:Float32,p_near:Float32,p_far:Float32,p_result:Matrix4=null):Matrix4
	{
		var t:Float32= Mathf.Tan(p_fov*0.5 * Mathf.Deg2Rad) * p_near;
		var b:Float32= -t;
		var l:Float32= p_aspect * b;
		var r:Float32= p_aspect * t;		
		return Frustum(l, r, t, b, p_near, p_far,p_result);
	}
	
	/**
	 * Returns a Perspective projection inverse matrix.
	 * @param	p_fov
	 * @param	p_aspect
	 * @param	p_near
	 * @param	p_far
	 * @return
	 */
	static public function PerspectiveInverse(p_fov:Float32,p_aspect:Float32,p_near:Float32,p_far:Float32,p_result:Matrix4=null):Matrix4
	{
		var t:Float32= Mathf.Tan(p_fov*0.5 * Mathf.Deg2Rad) * p_near;
		var b:Float32= -t;
		var l:Float32= p_aspect * b;
		var r:Float32= p_aspect * t;
		return FrustumInverse(l, r, t, b, p_near, p_far,p_result);
	}
	
	/**
	 * Returns the Rotation component of the informed matrix.
	 * @param	p_matrix4
	 * @param	p_result
	 * @return
	 */
	static public function GetRotation(p_matrix4 : Matrix4, p_result:Matrix4 = null):Matrix4
	{
		var m : Matrix4 = p_result == null ? (new Matrix4()) : p_result;
		var tmp : Vector3 = Vector3.temp;		
		tmp.Set(m.m00, m.m01,m.m02).Normalize(); m.m00 = tmp.x; m.m01 = tmp.y; m.m02 = tmp.z; m.m03 = 0.0;
		tmp.Set(m.m10, m.m11,m.m12).Normalize(); m.m10 = tmp.x; m.m11 = tmp.y; m.m12 = tmp.z; m.m13 = 0.0;
		tmp.Set(m.m20, m.m21,m.m22).Normalize(); m.m20 = tmp.x; m.m21 = tmp.y; m.m22 = tmp.z; m.m23 = 0.0;
		m.m30 = m.m31 = m.m32 = 0.0; m.m33 = 1.0;
		return m;
	}
	
	/**
	 * Returns the scale component of the informed matrix.
	 * @param	p_matrix4
	 * @param	p_result
	 * @return
	 */
	static public function GetScale(p_matrix4 : Matrix4, p_result : Matrix4 = null) : Matrix4
	{
		var m : Matrix4 = p_matrix4;
		var res : Matrix4 = p_result == null ? (new Matrix4()) : p_result;		
		var d0:Float32= Math.sqrt(m.m00 * m.m00 + m.m10 * m.m10 + m.m20 * m.m20);
		var d1:Float32= Math.sqrt(m.m01 * m.m01 + m.m11 * m.m11 + m.m21 * m.m21);
		var d2:Float32= Math.sqrt(m.m02 * m.m02 + m.m12 * m.m12 + m.m22 * m.m22);
		return res.Set(d0, 0, 0, 0,   0, d1, 0, 0,   0, 0, d2, 0,   0, 0, 0, 1);
	}
	
	/**
	 * Returns a new matrix with the inverse transform of the informed matrix.
	 * @param	p_matrix
	 * @param	p_result
	 * @return
	 */
	static public function GetInverseTransform(p_matrix : Matrix4, p_result : Matrix4 = null):Matrix4
	{
		var result:Matrix4 = p_result == null ? Matrix4.identity : p_result;
		var m : Matrix4 = p_matrix;
		
		var l0x:Float32= m.m00; var l0y:Float32= m.m01; var l0z:Float32= m.m02; var l0w:Float32= m.m03;
		var l1x:Float32= m.m10; var l1y:Float32= m.m11; var l1z:Float32= m.m12; var l1w:Float32= m.m13;
		var l2x:Float32= m.m20; var l2y:Float32= m.m21; var l2z:Float32= m.m22; var l2w:Float32= m.m23; 
		
		//length of the 3 column of the 3x3 sector are the scales
		var vl0 : Float32 = Math.sqrt(l0x * l0x + l1x * l1x + l2x * l2x);
		var vl1 : Float32 = Math.sqrt(l0y * l0y + l1y * l1y + l2y * l2y);
		var vl2 : Float32 = Math.sqrt(l0z * l0z + l1z * l1z + l2z * l2z);
		
		var sx:Float32= (Mathf.Abs(vl0)<= 0.0001) ? 0.0 : (1.0/vl0); 
		var sy:Float32= (Mathf.Abs(vl1)<= 0.0001) ? 0.0 : (1.0/vl1); 
		var sz:Float32= (Mathf.Abs(vl2)<= 0.0001) ? 0.0 : (1.0/vl2); 
		
		//normalized vector lines inside the 3x3 sector are the rotation axis.	
		l0x *= sx; l0y *= sy; l0z *= sz;
		l1x *= sx; l1y *= sy; l1z *= sz;
		l2x *= sx; l2y *= sy; l2z *= sz;
		
		result.Set(
		sx * l0x, sx * l1x, sx * l2x, sx * ((l0x * -l0w) + (l1x * -l1w) + (l2x * -l2w)),
		sy * l0y, sy * l1y, sy * l2y, sy * ((l0y * -l0w) + (l1y * -l1w) + (l2y * -l2w)),
		sz * l0z, sz * l1z, sz * l2z, sz * ((l0z * -l0w) + (l1z * -l1w) + (l2z * -l2w)),
		0,0,0,1
		);		
		return result;
	}
	
	/**
	 * Returns a LookAt rotation located at the origin.
	 * @param	p_forward
	 * @param	p_up
	 * @return
	 */
	static public inline function LookRotation(p_forward : Vector3, p_up : Vector3=null,p_result:Matrix4=null):Matrix4 { return LookAt(Vector3.temp.Set(0,0,0),p_forward,p_up,p_result); }
	
	/**
	 * Returns a LookAt matrix.
	 * @param	p_from
	 * @param	p_at
	 * @param	p_up
	 * @return
	 */
	static public function LookAt(p_eye : Vector3, p_at : Vector3, p_up : Vector3 = null,p_result:Matrix4=null):Matrix4 
	{ 
		p_result = p_result == null ? (new Matrix4()) : p_result;
		p_up = p_up == null ? Vector3.temp.Set(0, 1, 0) : p_up;		
		var f : Vector3 = Vector3.temp.Set3(p_at).Sub(p_eye).Normalize();
		var s : Vector3 = Vector3.Cross(f, p_up, Vector3.temp).Normalize();
		var u : Vector3 = Vector3.Cross(s, f, Vector3.temp);		
		p_result.m00 = s.x; 
		p_result.m10 = s.y;	
		p_result.m20 = s.z;		
		p_result.m01 = u.x; 
		p_result.m11 = u.y;
		p_result.m21 = u.z;		
		p_result.m02 = -f.x; 
		p_result.m12 = -f.y;	
		p_result.m22 = -f.z;		
		p_result.m03 = -Vector3.Dot(s, p_eye);
		p_result.m13 = -Vector3.Dot(u, p_eye);
		p_result.m23 =  Vector3.Dot(f, p_eye);		
		p_result.m30 = p_result.m31 = p_result.m32 = 0.0; p_result.m33 = 1.0;		
		return p_result;
	}
	
	
	
	/**
	 * Returns a copy of this matrix.
	 */
	public var clone(get_clone, never):Matrix4;
	private inline function get_clone():Matrix4 { return new Matrix4(m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33); }
	
	/**
	 * Returns the quaternion representing this matrix rotation.
	 */
	public var quaternion(get_quaternion, set_quaternion):Quaternion;	
	private inline function get_quaternion():Quaternion { return Quaternion.FromMatrix4(Matrix4.temp.SetMatrix4(this).ToRotation()); }
	private inline function set_quaternion(v:Quaternion):Quaternion { FromQuaternion(v, this); return v; }
	
	/**
	 * Returns the trace of this matrix.
	 */
	public var trace(get_trace, never):Float32;
	private inline function get_trace():Float32{ return (m00 + m11 + m22 + m33); }
	
	
	/**
	 * Returns the rotation component of this matrix as copy.
	 */
	public var rotation(get_rotation, null):Matrix4;
	private inline function get_rotation():Matrix4 { return clone.ToRotation(); }
		
	/**
	 * Returns the scale component of this matrix as copy.
	 */
	public var scale(get_scale, null):Matrix4;
	private inline function get_scale():Matrix4 { return GetScale(this); }
	
	/**
	 * Returns the translation component of this matrix as copy.
	 */
	public var translation(get_translation, null):Matrix4;
	private inline function get_translation():Matrix4 { return new Matrix4(1,0,0,m03,  0,1, 0,m13,   0, 0, 1,m23,  0, 0, 0, 1); }
	
	/**
	 * Returns the inverse transform of this matrix.
	 */
	public var inverseTransform(get_inverseTransform, null):Matrix4;
	private function get_inverseTransform():Matrix4
	{   
		/*
		var result:Matrix4 = Matrix4.identity;
		var l0:Vector3 = new Vector3(m00,m01,m02);
		var l1:Vector3 = new Vector3(m10,m11,m12);
		var l2:Vector3 = new Vector3(m20,m21, m22);
		var vl0 : Float32 = l0.length; 
		var vl1 : Float32 = l1.length; 
		var vl2 : Float32 = l2.length; 
		//length of the 3 lines of the 3x3 sector are the scales
		//TODO: The COLUMNS must be used for scale
		var sx:Float32= (Mathf.Abs(vl0)<= 0.0001) ? 0.0 : (1.0/vl0); 
		var sy:Float32= (Mathf.Abs(vl1)<= 0.0001) ? 0.0 : (1.0/vl1); 
		var sz:Float32= (Mathf.Abs(vl2)<= 0.0001) ? 0.0 : (1.0/vl2); 
		
		//normalized vector lines inside the 3x3 sector are the rotation axis.
		l0.x *= sx; l0.y *= sx; l0.z *= sx;
		l1.x *= sy; l1.y *= sy; l1.z *= sy;
		l2.x *= sz; l2.y *= sz; l2.z *= sz;
		
		result.Set(
		sx * l0.x, sx * l1.x, sx * l2.x, sx * ((l0.x * -m03) + (l1.x * -m13) + (l2.x * -m23)),
		sy * l0.y, sy * l1.y, sy * l2.y, sy * ((l0.y * -m03) + (l1.y * -m13) + (l2.y * -m23)),
		sz * l0.z, sz * l1.z, sz * l2.z, sz * ((l0.z * -m03) + (l1.z * -m13) + (l2.z * -m23)),
		0,0,0,1
		);		
		return result;		
		//*/		
		return GetInverseTransform(this, null);		
	}
	
	/**
	 * Returns a copy of this matrix as transposed.
	 */
	public var transposed(get_transposed, null):Matrix4;
	private function get_transposed():Matrix4	
	{ return new Matrix4(m00,m10,m20,m30, m01,m11,m21,m31, m02,m12,m22,m32, m03,m13,m23,m33); }
	
	/**
	 * Returns an Array<Float32> of this matrix converted to Row Major.
	 */
	public function ToRowMajor() : Array<Float32> { return [m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33]; }
	
	/**
	 * Returns an Array<Float32> of this matrix converted to Column Major. 
	 */
	public function ToColumnMajor() : Array<Float32> { return [m00,m10,m20,m30, m01,m11,m21,m31, m02,m12,m22,m32, m03,m13,m23,m33]; }
	
	/**
	 * Components
	 */
	public var m00 : Float32;
	public var m01 : Float32;
	public var m02 : Float32;
	public var m03 : Float32;	
	public var m10 : Float32;
	public var m11 : Float32;
	public var m12 : Float32;
	public var m13 : Float32;	
	public var m20 : Float32;
	public var m21 : Float32;
	public var m22 : Float32;
	public var m23 : Float32;	
	public var m30 : Float32;
	public var m31 : Float32;
	public var m32 : Float32;
	public var m33 : Float32;
	
	/**
	 * Creates a new Matrix4.
	 * @param	p_m00
	 * @param	p_m01
	 * @param	p_m02
	 * @param	p_m03
	 * @param	p_m10
	 * @param	p_m11
	 * @param	p_m12
	 * @param	p_m13
	 * @param	p_m20
	 * @param	p_m21
	 * @param	p_m22
	 * @param	p_m23
	 * @param	p_m30
	 * @param	p_m31
	 * @param	p_m32
	 * @param	p_m33
	 */
	public function new(p_m00:Float32= 0, p_m01:Float32= 0, p_m02:Float32= 0, p_m03:Float32= 0,
						p_m10:Float32= 0, p_m11:Float32= 0, p_m12:Float32= 0, p_m13:Float32= 0,
						p_m20:Float32= 0, p_m21:Float32= 0, p_m22:Float32= 0, p_m23:Float32= 0,
						p_m30:Float32= 0, p_m31:Float32= 0, p_m32:Float32= 0, p_m33:Float32= 0)
	{
		m00 = p_m00; m01 = p_m01; m02 = p_m02; m03 = p_m03; m10 = p_m10; m11 = p_m11; m12 = p_m12; m13 = p_m13; m20 = p_m20; m21 = p_m21; m22 = p_m22; m23 = p_m23; m30 = p_m30; m31 = p_m31; m32 = p_m32;	m33 = p_m33;
	}
	
	/**
	 * Returns a line of this matrix as Vector4.
	 * @param	p_index
	 * @return
	 */
	public function GetLine(p_index:Int,p_result:Vector4=null):Vector4 
	{ 
		p_result = p_result == null? (new Vector4()) : p_result;
		return p_result.Set(GetRowCol(p_index, 0), GetRowCol(p_index, 1), GetRowCol(p_index, 2), GetRowCol(p_index, 3)); 
	}
	
	/**
	 * Sets a line of this matrix.
	 * @param	p_index
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 * @return
	 */
	public inline function SetLine(p_index:Int,p_x : Float32,p_y:Float32,p_z:Float32,p_w:Float32) : Void
	{
		switch(p_index)
		{
			case 0: m00 = p_x; m01 = p_y; m02 = p_z; m03 = p_w;
			case 1: m10 = p_x; m11 = p_y; m12 = p_z; m13 = p_w;
			case 2: m20 = p_x; m21 = p_y; m22 = p_z; m23 = p_w;
			case 3: m30 = p_x; m31 = p_y; m32 = p_z; m33 = p_w;
		}
	}
	
	/**
	 * Returns a column of this matrix as Vector4.
	 * @param	p_index
	 * @return
	 */
	public inline function GetColumn(p_index:Int,p_result:Vector4=null):Vector4
	{
		p_result = p_result == null ? new Vector4() : p_result;
		return p_result.Set(GetRowCol(0,p_index), GetRowCol(1,p_index), GetRowCol(2,p_index), GetRowCol(3,p_index));
	}
	
	/**
	 * Sets a line of this matrix.
	 * @param	p_index
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 * @return
	 */
	public inline function SetColumn(p_index:Int,p_x : Float32,p_y:Float32,p_z:Float32,p_w:Float32) : Void
	{
		switch(p_index)
		{
			case 0: m00 = p_x; m10 = p_y; m20 = p_z; m30 = p_w;
			case 1: m01 = p_x; m11 = p_y; m21 = p_z; m31 = p_w;
			case 2: m02 = p_x; m12 = p_y; m22 = p_z; m32 = p_w;
			case 3: m03 = p_x; m13 = p_y; m23 = p_z; m33 = p_w;
		}
	}
	
	/**
	 * Returns a diagonal of this matrix from top-left to bottom-right.
	 */
	public var diagonalLR(get_diagonalLR, set_diagonalLR) : Vector4;
	private inline function get_diagonalLR():Vector4 { return new Vector4(m00, m11, m22, m33); }
	private inline function set_diagonalLR(v:Vector4):Vector4 { m00 = v.x; m11 = v.y; m22 = v.z; m33 = v.w; return v; }
	
	/**
	 * Resets this matrix to identity. Returns its own reference.
	 * @return
	 */
	public inline function SetIdentity():Matrix4 { return Set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1); }
	
	/**
	 * Sets all values of this matrix. Returns its own reference.
	 * @param	p_m00
	 * @param	p_m01
	 * @param	p_m02
	 * @param	p_m03
	 * @param	p_m10
	 * @param	p_m11
	 * @param	p_m12
	 * @param	p_m13
	 * @param	p_m20
	 * @param	p_m21
	 * @param	p_m22
	 * @param	p_m23
	 * @param	p_m30
	 * @param	p_m31
	 * @param	p_m32
	 * @param	p_m33
	 */
	public function Set(p_m00:Float32= 0, p_m01:Float32= 0, p_m02:Float32= 0, p_m03:Float32= 0,
	                    p_m10:Float32= 0, p_m11:Float32= 0, p_m12:Float32= 0, p_m13:Float32= 0,
	                    p_m20:Float32= 0, p_m21:Float32= 0, p_m22:Float32= 0, p_m23:Float32= 0,
	                    p_m30:Float32= 0, p_m31:Float32= 0, p_m32:Float32= 0, p_m33:Float32= 0):Matrix4
	{	
		m00 = p_m00; m01 = p_m01; m02 = p_m02; m03 = p_m03;
		m10 = p_m10; m11 = p_m11; m12 = p_m12; m13 = p_m13;
		m20 = p_m20; m21 = p_m21; m22 = p_m22; m23 = p_m23;
		m30 = p_m30; m31 = p_m31; m32 = p_m32; m33 = p_m33;
		return this;
	}
	
	/**
	 * Sets this matrix data using a Matrix4 as template.
	 * @param	p_matrix
	 * @return
	 */
	public function SetMatrix4(p_matrix : Matrix4):Matrix4
	{
		m00 = p_matrix.m00; m01 = p_matrix.m01; m02 = p_matrix.m02; m03 = p_matrix.m03;
		m10 = p_matrix.m10; m11 = p_matrix.m11; m12 = p_matrix.m12; m13 = p_matrix.m13;
		m20 = p_matrix.m20; m21 = p_matrix.m21; m22 = p_matrix.m22;	m23 = p_matrix.m23;
		m30 = p_matrix.m30; m31 = p_matrix.m31; m32 = p_matrix.m32; m33 = p_matrix.m33;
		return this;
	}
	
	/**
	 * Returns an element of the matrix by index.
	 * @param	p_index
	 * @return
	 */
	public function GetIndex(p_index : Int):Float
	{
		switch(p_index)
		{
			case  0: return m00;
			case  1: return m01;
			case  2: return m02;
			case  3: return m03;			
			case  4: return m10;
			case  5: return m11;
			case  6: return m12;
			case  7: return m13;			
			case  8: return m20;
			case  9: return m21;
			case 10: return m22;
			case 11: return m23;			
			case 12: return m30;
			case 13: return m31;
			case 14: return m32;
			case 15: return m33;
		}
		return 0;
	}
	
	/**
	 * Sets an individual value of this matrix by index.  Returns its own reference.
	 * @param	p_index
	 * @param	p_value
	 */
	public function SetIndex(p_index : Int, p_value : Float32):Matrix4
	{
		switch(p_index)
		{
			case  0: m00 = p_value;
			case  1: m01 = p_value;
			case  2: m02 = p_value;
			case  3: m03 = p_value;			
			case  4: m10 = p_value;
			case  5: m11 = p_value;
			case  6: m12 = p_value;
			case  7: m13 = p_value;			
			case  8: m20 = p_value;
			case  9: m21 = p_value;
			case 10: m22 = p_value;
			case 11: m23 = p_value;			
			case 12: m30 = p_value;
			case 13: m31 = p_value;
			case 14: m32 = p_value;
			case 15: m33 = p_value;
		}
		return this;
	}
	
	/**
	 * Sets a value of this matrix indexed by row and column.  Returns its own reference.
	 * @param	p_row
	 * @param	p_col
	 * @param	p_value
	 */
	public function SetRowCol(p_row:Int,p_col:Int, p_value:Float32):Matrix4 { return SetIndex(p_col + (p_row << 2), p_value);	}
	
	/**
	 * Sets a value of this matrix indexed by row and column.
	 * @param	p_row
	 * @param	p_col
	 * @return
	 */
	public function GetRowCol(p_row:Int,p_col:Int):Float32{ return GetIndex(p_col + (p_row << 2)); }
	
	/**
	 * SWap 2 columns.  Returns its own reference.
	 * @param	p_a
	 * @param	p_b
	 * @return
	 */
	public function SwapCol(p_a : Int, p_b : Int):Matrix4
	{
		var a0 : Float32 = GetRowCol(0, p_a);
		var a1 : Float32 = GetRowCol(1, p_a);
		var a2 : Float32 = GetRowCol(2, p_a);
		var a3 : Float32 = GetRowCol(3, p_a);		
		SetRowCol(0, p_a, GetRowCol(0, p_b));
		SetRowCol(1, p_a, GetRowCol(1, p_b));
		SetRowCol(2, p_a, GetRowCol(2, p_b));
		SetRowCol(3, p_a, GetRowCol(3, p_b));		
		SetRowCol(0, p_b, a0);
		SetRowCol(1, p_b, a1);
		SetRowCol(2, p_b, a2);
		SetRowCol(3, p_b, a3);
		return this;
	}
	
	/**
	 * Swap 2 rows.  Returns its own reference.
	 * @param	p_a
	 * @param	p_b
	 * @return
	 */
	public function SwapRow(p_a : Int, p_b : Int):Matrix4
	{
		var a0 : Float32 = GetRowCol(p_a,0);
		var a1 : Float32 = GetRowCol(p_a,1);
		var a2 : Float32 = GetRowCol(p_a,2);
		var a3 : Float32 = GetRowCol(p_a,3);		
		SetRowCol(p_a,0, GetRowCol(p_b,0));
		SetRowCol(p_a,1, GetRowCol(p_b,1));
		SetRowCol(p_a,2, GetRowCol(p_b,2));
		SetRowCol(p_a,3, GetRowCol(p_b,3));		
		SetRowCol(p_b,0, a0);
		SetRowCol(p_b,1, a1);
		SetRowCol(p_b,2, a2);
		SetRowCol(p_b,3, a3);
		return this;
	}
	
	/**
	 * Transposes this matrix.  Returns its own reference.
	 * @return
	 */
	public function Transpose():Matrix4
	{
		var t00:Float32= m00; var t01:Float32= m01; var t02:Float32= m02; var t03:Float32= m03;		
		var t10:Float32= m10; var t11:Float32= m11; var t12:Float32= m12; var t13:Float32= m13;
		var t20:Float32= m20; var t21:Float32= m21; var t22:Float32= m22; var t23:Float32= m23;
		var t30:Float32= m30; var t31:Float32= m31; var t32:Float32= m32; var t33:Float32= m33;
		return Set(t00, t10, t20, t30,t01, t11, t21, t31,t02, t12, t22, t32,t03, t13, t23, t33);		
	}
	
	/**
	 * Sets all values to the rotation component of this matrix.   Returns its own reference.
	 * @return
	 */
	public function ToRotation():Matrix4
	{
		var tmp : Vector3 = Vector3.temp;		
		tmp.Set(m00, m01, m02).Normalize(); m00 = tmp.x; m01 = tmp.y; m02 = tmp.z; m03 = 0.0;
		tmp.Set(m10, m11, m12).Normalize(); m10 = tmp.x; m11 = tmp.y; m12 = tmp.z; m13 = 0.0;
		tmp.Set(m20, m21, m22).Normalize(); m20 = tmp.x; m21 = tmp.y; m22 = tmp.z; m23 = 0.0;
		m30 = m31 = m32 = 0.0; m33 = 1.0;
		return this;
	}
	
	/**
	 * Applies a rotation to the informed vector.
	 * @param	p_vector
	 * @return
	 */
	public function Rotate(p_vector : Vector3):Vector3
	{
		var tmp : Vector3 = Vector3.temp;
		tmp.Set(m00, m01, m02).Normalize();				
		p_vector.x = (tmp.x * p_vector.x) + (tmp.y * p_vector.y) + (tmp.z * p_vector.z);
		tmp.Set(m10, m11, m12).Normalize();				
		p_vector.y = (tmp.x * p_vector.x) + (tmp.y * p_vector.y) + (tmp.z * p_vector.z);
		tmp.Set(m20, m21, m22).Normalize();		
		p_vector.z = (tmp.x * p_vector.x) + (tmp.y * p_vector.y) + (tmp.z * p_vector.z);		
		return p_vector;
	}
	
	/**
	 * Sets the values of this matrix to a TRS matrix. Returns its own reference.
	 * @param	p_position
	 * @param	p_rotation
	 * @param	p_scale
	 * @return
	 */
	public inline function SetTRS(p_position : Vector3, p_rotation : Quaternion, p_scale:Vector3 = null):Matrix4 { return TRS(p_position, p_rotation, p_scale, this); }
	
	/**
	 * Converts this instance to its inverse transform form.
	 * @return
	 */
	public inline function ToInverseTransform():Matrix4 { return GetInverseTransform(Matrix4.temp.SetMatrix4(this), this); }
	
	/**
	 * Multiplies the informed matrix using only the transform "sector" of the 2 matrix.  Returns its own reference.
	 * @param	p_matrix
	 * @return
	 */
	public function MultiplyTransform(p_matrix : Matrix4) : Matrix4
	{
		var r00:Float32= m00 * p_matrix.m00 + m01 * p_matrix.m10 + m02 * p_matrix.m20;
		var r01:Float32= m00 * p_matrix.m01 + m01 * p_matrix.m11 + m02 * p_matrix.m21;
		var r02:Float32= m00 * p_matrix.m02 + m01 * p_matrix.m12 + m02 * p_matrix.m22;
		var r03:Float32= m00 * p_matrix.m03 + m01 * p_matrix.m13 + m02 * p_matrix.m23 + m03;
		var r10:Float32= m10 * p_matrix.m00 + m11 * p_matrix.m10 + m12 * p_matrix.m20;
		var r11:Float32= m10 * p_matrix.m01 + m11 * p_matrix.m11 + m12 * p_matrix.m21;
		var r12:Float32= m10 * p_matrix.m02 + m11 * p_matrix.m12 + m12 * p_matrix.m22;
		var r13:Float32= m10 * p_matrix.m03 + m11 * p_matrix.m13 + m12 * p_matrix.m23 + m13;
		var r20:Float32= m20 * p_matrix.m00 + m21 * p_matrix.m10 + m22 * p_matrix.m20;
		var r21:Float32= m20 * p_matrix.m01 + m21 * p_matrix.m11 + m22 * p_matrix.m21;
		var r22:Float32= m20 * p_matrix.m02 + m21 * p_matrix.m12 + m22 * p_matrix.m22;
		var r23:Float32= m20 * p_matrix.m03 + m21 * p_matrix.m13 + m22 * p_matrix.m23 + m23;
		Set(
			r00,r01,r02,r03,
			r10,r11,r12,r13,
			r20,r21,r22,r23,
			0, 0, 0, 1);			
		return this;
	}
	
	/**
	 * Multiplies the informed matrix using only the 3x4 "sector" of the 2 matrix. The last row is unchanged. Returns its own reference.
	 * @param	p_matrix
	 * @return
	 */
	public function Multiply3x4(p_matrix : Matrix4) : Matrix4
	{
		var r00:Float32= m00 * p_matrix.m00 + m01 * p_matrix.m10 + m02 * p_matrix.m20 + m03 * p_matrix.m30;
		var r01:Float32= m00 * p_matrix.m01 + m01 * p_matrix.m11 + m02 * p_matrix.m21 + m03 * p_matrix.m31;
		var r02:Float32= m00 * p_matrix.m02 + m01 * p_matrix.m12 + m02 * p_matrix.m22 + m03 * p_matrix.m32;
		var r03:Float32= m00 * p_matrix.m03 + m01 * p_matrix.m13 + m02 * p_matrix.m23 + m03 * p_matrix.m33;
		var r10:Float32= m10 * p_matrix.m00 + m11 * p_matrix.m10 + m12 * p_matrix.m20 + m13 * p_matrix.m30;
		var r11:Float32= m10 * p_matrix.m01 + m11 * p_matrix.m11 + m12 * p_matrix.m21 + m13 * p_matrix.m31;
		var r12:Float32= m10 * p_matrix.m02 + m11 * p_matrix.m12 + m12 * p_matrix.m22 + m13 * p_matrix.m32;
		var r13:Float32= m10 * p_matrix.m03 + m11 * p_matrix.m13 + m12 * p_matrix.m23 + m13 * p_matrix.m33;
		var r20:Float32= m20 * p_matrix.m00 + m21 * p_matrix.m10 + m22 * p_matrix.m20 + m23 * p_matrix.m30;
		var r21:Float32= m20 * p_matrix.m01 + m21 * p_matrix.m11 + m22 * p_matrix.m21 + m23 * p_matrix.m31;
		var r22:Float32= m20 * p_matrix.m02 + m21 * p_matrix.m12 + m22 * p_matrix.m22 + m23 * p_matrix.m32;
		var r23:Float32= m20 * p_matrix.m03 + m21 * p_matrix.m13 + m22 * p_matrix.m23 + m23 * p_matrix.m33;		
		Set(
			r00,r01,r02,r03,
			r10,r11,r12,r13,
			r20,r21,r22,r23,
			m30, m31, m32, m33);
		return this;
	}
	
	/**
	 * Multiplies the informed matrix using all the 4x4 area of the 2 matrix. Returns its own reference.
	 * @param	p_matrix
	 * @return
	 */
	public function Multiply(p_matrix : Matrix4) : Matrix4
	{
		var r00:Float32= m00 * p_matrix.m00 + m01 * p_matrix.m10 + m02 * p_matrix.m20 + m03 * p_matrix.m30;
		var r01:Float32= m00 * p_matrix.m01 + m01 * p_matrix.m11 + m02 * p_matrix.m21 + m03 * p_matrix.m31;
		var r02:Float32= m00 * p_matrix.m02 + m01 * p_matrix.m12 + m02 * p_matrix.m22 + m03 * p_matrix.m32;
		var r03:Float32= m00 * p_matrix.m03 + m01 * p_matrix.m13 + m02 * p_matrix.m23 + m03 * p_matrix.m33;		
		var r10:Float32= m10 * p_matrix.m00 + m11 * p_matrix.m10 + m12 * p_matrix.m20 + m13 * p_matrix.m30;
		var r11:Float32= m10 * p_matrix.m01 + m11 * p_matrix.m11 + m12 * p_matrix.m21 + m13 * p_matrix.m31;
		var r12:Float32= m10 * p_matrix.m02 + m11 * p_matrix.m12 + m12 * p_matrix.m22 + m13 * p_matrix.m32;
		var r13:Float32= m10 * p_matrix.m03 + m11 * p_matrix.m13 + m12 * p_matrix.m23 + m13 * p_matrix.m33;		
		var r20:Float32= m20 * p_matrix.m00 + m21 * p_matrix.m10 + m22 * p_matrix.m20 + m23 * p_matrix.m30;
		var r21:Float32= m20 * p_matrix.m01 + m21 * p_matrix.m11 + m22 * p_matrix.m21 + m23 * p_matrix.m31;
		var r22:Float32= m20 * p_matrix.m02 + m21 * p_matrix.m12 + m22 * p_matrix.m22 + m23 * p_matrix.m32;
		var r23:Float32= m20 * p_matrix.m03 + m21 * p_matrix.m13 + m22 * p_matrix.m23 + m23 * p_matrix.m33;
		
		var r30:Float32= m30 * p_matrix.m00 + m31 * p_matrix.m10 + m32 * p_matrix.m20 + m33 * p_matrix.m30;
		var r31:Float32= m30 * p_matrix.m01 + m31 * p_matrix.m11 + m32 * p_matrix.m21 + m33 * p_matrix.m31;
		var r32:Float32= m30 * p_matrix.m02 + m31 * p_matrix.m12 + m32 * p_matrix.m22 + m33 * p_matrix.m32;
		var r33:Float32= m30 * p_matrix.m03 + m31 * p_matrix.m13 + m32 * p_matrix.m23 + m33 * p_matrix.m33;
		Set(
			r00,r01,r02,r03,
			r10,r11,r12,r13,
			r20,r21,r22,r23,
			r30, r31, r32, r33);
		return this;
	}
	
	/**
	 * Transforms the informed vector. Returns the same instance of it.
	 * @param	p_point
	 */
	public inline function Transform4x4(p_point : Vector4):Vector4
	{
		var vx:Float32= (m00 * p_point.x) + (m01 * p_point.y) + (m02 * p_point.z) + (m03 * p_point.w);
		var vy:Float32= (m10 * p_point.x) + (m11 * p_point.y) + (m12 * p_point.z) + (m13 * p_point.w);
		var vz:Float32= (m20 * p_point.x) + (m21 * p_point.y) + (m22 * p_point.z) + (m23 * p_point.w);
		var vw:Float32= (m30 * p_point.x) + (m31 * p_point.y) + (m32 * p_point.z) + (m33 * p_point.w);
		p_point.x = vx;
		p_point.y = vy;
		p_point.z = vz;
		p_point.w = vw;
		return p_point;
	}
	
	/**
	 * Transforms the informed vector. Returns the same instance of it.
	 * @param	p_point
	 */
	public inline function Transform3x4(p_point:Vector3):Vector3
	{
		var vx:Float32= (m00 * p_point.x) + (m01 * p_point.y) + (m02 * p_point.z) + m03;
		var vy:Float32= (m10 * p_point.x) + (m11 * p_point.y) + (m12 * p_point.z) + m13;
		var vz:Float32= (m20 * p_point.x) + (m21 * p_point.y) + (m22 * p_point.z) + m23;		
		p_point.x = vx;
		p_point.y = vy;
		p_point.z = vz;		
		return p_point;
	}
	
	/**
	 * Transforms the informed vector with only the 3x3 sector. Returns the same instance of it.
	 * @param	p_point
	 */
	public inline function Transform3x3(p_point:Vector3):Vector3
	{
		var vx:Float32= (m00 * p_point.x) + (m01 * p_point.y) + (m02 * p_point.z);
		var vy:Float32= (m10 * p_point.x) + (m11 * p_point.y) + (m12 * p_point.z);
		var vz:Float32= (m20 * p_point.x) + (m21 * p_point.y) + (m22 * p_point.z);		
		p_point.x = vx;
		p_point.y = vy;
		p_point.z = vz;		
		return p_point;
	}
	
	/**
	 * Transforms the informed vector. Returns the same instance of it.
	 * @param	p_point
	 */
	public inline function Transform2x3(p_point:Vector2):Void
	{
		var vx:Float32= (m00 * p_point.x) + (m01 * p_point.y) + m03;
		var vy:Float32= (m10 * p_point.x) + (m11 * p_point.y) + m13;		
		p_point.x = vx;
		p_point.y = vy;
	}
	
	/**
	 * Transforms the informed vector. Returns the same instance of it.
	 * @param	p_point
	 */
	public inline function Transform2x2(p_point:Vector2):Void
	{
		var vx:Float32= (m00 * p_point.x) + (m01 * p_point.y);
		var vy:Float32= (m10 * p_point.x) + (m11 * p_point.y);		
		p_point.x = vx;
		p_point.y = vy;
	}
	
	/**
	 * Sets this matrix as a LookAt matrix. Returns its own reference.
	 * @param	p_from
	 * @param	p_to
	 * @param	p_up
	 * @return
	 */
	public inline function SetLookAt(p_eye : Vector3, p_at : Vector3, p_up : Vector3=null) : Matrix4 {	return LookAt(p_eye,p_at,p_up,this); }
	
	/**
	 * Transforms this matrix into a frustum matrix. Returns its own reference.
	 * @param	p_left
	 * @param	p_right
	 * @param	p_top
	 * @param	p_bottom
	 * @param	p_near
	 * @param	p_far
	 * @return
	 */
	public inline function SetFrustum(p_left:Float32, p_right:Float32, p_top:Float32, p_bottom:Float32, p_near:Float32, p_far:Float32):Matrix4 { return Frustum(p_left, p_right, p_top, p_bottom, p_near, p_far, this); }
	
	/**
	 * Transforms this matrix into a frustum inverse matrix.  Returns its own reference.
	 * @param	p_left
	 * @param	p_right
	 * @param	p_top
	 * @param	p_bottom
	 * @param	p_near
	 * @param	p_far
	 * @return
	 */
	public inline function SetFrustumInverse(p_left:Float32, p_right:Float32, p_top:Float32, p_bottom:Float32, p_near:Float32, p_far:Float32):Matrix4 { return FrustumInverse(p_left, p_right, p_top, p_bottom, p_near, p_far,this); }
	
	/**
	 * Transforms this matrix into an orthographic matrix.  Returns its own reference.
	 * @param	p_left
	 * @param	p_right
	 * @param	p_top
	 * @param	p_bottom
	 * @param	p_near
	 * @param	p_far
	 * @return
	 */
	public function SetOrtho(p_left:Float32, p_right:Float32, p_top:Float32, p_bottom:Float32, p_near:Float32, p_far:Float32):Matrix4 {	return Ortho(p_left, p_right, p_top, p_bottom, p_near, p_far, this); }
	
	/**
	 * Transforms this matrix into an inverse orthographic matrix. Returns its own reference.
	 * @return
	 */
	public function SetOrthoInverse(p_left:Float32, p_right:Float32, p_top:Float32, p_bottom:Float32, p_near:Float32, p_far:Float32):Matrix4 { return OrthoInverse(p_left, p_right, p_top, p_bottom, p_near, p_far, this); }
	
	/**
	 * Transforms this matrix into a perspective projection matrix. Returns its own reference.
	 * @param	p_fov
	 * @param	p_aspect
	 * @param	p_near
	 * @param	p_far
	 * @return
	 */
	public inline function SetPerspective(p_fov:Float32, p_aspect:Float32, p_near:Float32, p_far:Float32):Matrix4 { return Perspective(p_fov, p_aspect, p_near, p_far, this); }
	
	/**
	 * Transforms this matrix into a perspective projection inverse matrix. Returns its own reference.
	 * @param	p_fov
	 * @param	p_aspect
	 * @param	p_near
	 * @param	p_far
	 * @return
	 */
	public inline function SetPerspectiveInverse(p_fov:Float32, p_aspect:Float32, p_near:Float32, p_far:Float32):Matrix4 { return PerspectiveInverse(p_fov, p_aspect, p_near, p_far, this);	}
	
	/**
	 * Returns all values as an Array<Float32>
	 * @return
	 */
	public function ToArray() : Array<Float32> { return [	m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33]; }
	
	/**
	 * Returns this matrix as string.
	 * @return
	 */
	public function ToString(p_linear : Bool=true,p_places:Int=2):String
	{
		var a : Array<Float32> = ToArray();
		var s : Array<String> = [];
		for (i in 0...a.length) 
		{ 
			a[i] = Mathf.RoundPlaces(a[i], p_places); 
			s.push(a[i] >= 0 ? " " + a[i] : a[i] + ""); 
		}
		var res:String = p_linear ? "[" : "";
		for (i in 0...4)
		{
			for (j in 0...4) { res += s[j+(i*4)] + ((j < 3) ? "," : ""); }
			res += i == 3 ? "" : (p_linear ? " |" : "\n");
			
		}
		if (p_linear) res += "]";
		return res;
	}
	
	/**
	 * Parses a string with the required delimiter into a new instance.
	 * @param	p_data
	 * @return
	 */
	static public function Parse(p_data : String,p_delimiter:String=" "):Matrix4
	{
		var tk : Array<String> = p_data.split(p_delimiter);
		var res : Matrix4 = Matrix4.identity;
		for (i in 0...tk.length)
		{
			var n : Float32 = Std.parseFloat(StringTools.trim(tk[i]));
			//res.m[i] = n;
			res.SetIndex(i, n);
		}
		return res;
	}
	
	
}