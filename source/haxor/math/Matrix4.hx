/*
HAXOR HTML5 ENGINE (c) 2013 - 2014 by Eduardo Pons - eduardo@thelaborat.org

HAXOR HTML5 ENGINE is licensed under a
Creative Commons Attribution-NoDerivs 3.0 Unported License.

You should have received a copy of the license along with this
work.  If not, see <http://creativecommons.org/licenses/by-nd/3.0/>.
 */
package haxor.math;
import js.html.Float32Array;


/**
 * ...
 * @author Eduardo Pons
 */
class Matrix4 
{
	
	static private var m_temp : Array<Matrix4>;
	static private var m_nexttemp : Int;	
	static public var temp(get_temp, never):Matrix4;
	static private function get_temp():Matrix4
	{
		if (m_temp == null)
		{
			m_temp = [];
			m_nexttemp = 0;
			for (i in 0...150000) m_temp.push(Matrix4.identity);			
		}
		var m :Matrix4 = m_temp[m_nexttemp];
		m_nexttemp = (m_nexttemp + 1) % m_temp.length;
		return m;
	}
	
	/**
	 * 
	 */
	static public var identity(get_identity, null):Matrix4;	
	static private function get_identity():Matrix4 { return new Matrix4(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1); }
	
	/**
	 * 
	 * @param	p_data
	 * @return
	 */
	static public function Parse(p_data : String,p_delimiter:String=" "):Matrix4
	{
		var tk : Array<String> = p_data.split(p_delimiter);
		var res : Matrix4 = Matrix4.identity;
		for (i in 0...tk.length)
		{
			var n : Float = Std.parseFloat(StringTools.trim(tk[i]));
			//res.m[i] = n;
			res.SetIndex(i, n);
		}
		return res;
	}
	
	/**
	 * 
	 * @param	p_array
	 * @return
	 */
	static public function FromArray(p_array : Array<Float>):Matrix4
	{
		var res : Matrix4 = new Matrix4();
		//for (i in 0...p_array.length) res.m[i] = p_array[i];
		for (i in 0...p_array.length) res.SetIndex(i,p_array[i]);
		return res;
	}
	
	/**
	 * 
	 * @param	p_position
	 * @param	p_rotation
	 * @param	p_scale
	 * @return
	 */	
	static public function TRS(p_position : Vector3, p_rotation : Quaternion, p_scale:Vector3 = null,p_result : Matrix4=null):Matrix4
	{		
		var sx:Float = p_scale == null ? 1.0 : p_scale.x;			
		var sy:Float = p_scale == null ? 1.0 : p_scale.y;
		var sz:Float = p_scale == null ? 1.0 : p_scale.z;		
		var px:Float = p_position.x;			
		var py:Float = p_position.y;
		var pz:Float = p_position.z;							
		var r : Matrix4 = p_rotation.matrix;
		var l : Matrix4 = p_result == null ? Matrix4.identity : p_result;
		l.m00 = r.m00 * sx; l.m01 = r.m01 * sy; l.m02 = r.m02 * sz; l.m03 = px;
		l.m10 = r.m10 * sx; l.m11 = r.m11 * sy; l.m12 = r.m12 * sz; l.m13 = py;
		l.m20 = r.m20 * sx; l.m21 = r.m21 * sy; l.m22 = r.m22 * sz; l.m23 = pz;
		l.m30 = l.m31 = l.m32 = 0.0; l.m33 = 1.0;
		return l;
	}
	
	static public function GetInverseTransform(p_matrix : Matrix4, p_result : Matrix4 = null):Matrix4
	{
		var result:Matrix4 = p_result == null ? Matrix4.identity : p_result;
		var m : Matrix4 = p_matrix;
		
		var l0x:Float = m.m00; var l0y:Float = m.m01; var l0z:Float = m.m02; var l0w:Float = m.m03;
		var l1x:Float = m.m10; var l1y:Float = m.m11; var l1z:Float = m.m12; var l1w:Float = m.m13;
		var l2x:Float = m.m20; var l2y:Float = m.m21; var l2z:Float = m.m22; var l2w:Float = m.m23; 
		
		//length of the 3 column of the 3x3 sector are the scales
		var vl0 : Float = Math.sqrt(l0x * l0x + l1x * l1x + l2x * l2x);
		var vl1 : Float = Math.sqrt(l0y * l0y + l1y * l1y + l2y * l2y);
		var vl2 : Float = Math.sqrt(l0z * l0z + l1z * l1z + l2z * l2z);
		
		var sx:Float = (Mathf.Abs(vl0)<= 0.0001) ? 0.0 : (1.0/vl0); 
		var sy:Float = (Mathf.Abs(vl1)<= 0.0001) ? 0.0 : (1.0/vl1); 
		var sz:Float = (Mathf.Abs(vl2)<= 0.0001) ? 0.0 : (1.0/vl2); 
		
		//normalized vector lines inside the 3x3 sector are the rotation axis.
		//l0x *= sx; l0y *= sx; l0z *= sx;
		//l1x *= sy; l1y *= sy; l1z *= sy;
		//l2x *= sz; l2y *= sz; l2z *= sz;
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
	 * 
	 * @param	p_forward
	 * @param	p_up
	 * @return
	 */
	static public function LookRotation(p_forward : Vector3, p_up : Vector3=null):Matrix4
	{		
		return LookAt(Vector3.zero,p_forward,p_up);		
	}
	
	/**
	 * 
	 * @param	p_from
	 * @param	p_at
	 * @param	p_up
	 * @return
	 */
	static public function LookAt(p_from : Vector3, p_at : Vector3, p_up : Vector3=null):Matrix4
	{
		p_up = p_up == null ? Vector3.up : p_up;
		var vz : Vector3 = p_at.clone.Sub(p_from).Normalize().Invert();
		var vx : Vector3 = 
		Vector3.Cross(p_up, vz).Normalize();
		var vy : Vector3 = Vector3.Cross(vz, vx);		
		var m : Matrix4 = new Matrix4();		
		m.Set(
		vx.x, vy.x, vz.x, -Vector3.Dot(vx, p_from),
		vx.y, vy.y, vz.y, -Vector3.Dot(vy, p_from),
		vx.z, vy.z, vz.z, -Vector3.Dot(vz, p_from),
		0, 0, 0, 1);		
		return m;			
	}
	
	/**
	 * 
	 */
	public var clone(get_clone, never):Matrix4;
	private function get_clone():Matrix4 { return new Matrix4(m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33); }
	
	
	public var euler(get_euler, null):Vector3;
	private function get_euler():Vector3
	{
		var m :Matrix4 = rotation;
		var e : Vector3 = Vector3.zero;
		e.x = Mathf.Atan2(m.m12, m.m22);
		var c2 : Float = Mathf.Sqrt((m.m00 * m.m00) + (m.m01 * m.m01));
		e.y = Mathf.Atan2( -m.m02, c2);
		var s1 : Float = Mathf.Sin(e.x);
		var c1 : Float = Mathf.Cos(e.x);
		e.z = Mathf.Atan2((s1 * m.m20) - (c1 * m.m10), c1 * m.m11 - s1 * m.m21);
		e.x = e.x * Mathf.Rad2Deg;
		e.y = e.y * Mathf.Rad2Deg;
		e.z = e.z * Mathf.Rad2Deg;
		return e;
	}
	
	/**
	 * 
	 */
	public var quaternion(get_quaternion, null):Quaternion;	
	private function get_quaternion():Quaternion
	{
		var b : Float32Array = ToBuffer();
		var m:Matrix4 = ToRotation();
				
		var q : Quaternion = new Quaternion();				
		var diag : Float = m.m00 + m.m11 + m.m22 + 1.0;
		var e : Float = 0;// Mathf.Epsilon;
		
		if(diag > e)
		{
			q.w = Mathf.Sqrt(diag) / 2.0;			
			var w4 : Float = (4.0 * q.w);
			q.x = (m.m21 - m.m12) / w4;
			q.y = (m.m02 - m.m20) / w4;
			q.z = (m.m10 - m.m01) / w4;						
		}
		else
		{
			var d01 : Float = m.m00 - m.m11;
			var d02 : Float = m.m00 - m.m22;
			var d12 : Float = m.m11 - m.m22;
			
			if ((d01>e) && (d02>e))
			{
				// 1st element of diag is greatest value
				// find scale according to 1st element, and double it
				var scale : Float = Mathf.Sqrt(1.0 + m.m00 - m.m11 - m.m22) * 2.0;

				// TODO: speed this up
				q.x = 0.25 * scale;
				q.y = (m.m10 + m.m01) / scale;
				q.z = (m.m02 + m.m20) / scale;
				q.w = (m.m12 - m.m21) / scale;
			}
			else if (d12>e)
			{
				// 2nd element of diag is greatest value
				// find scale according to 2nd element, and double it
				var scale : Float = Mathf.Sqrt(1.0 + m.m11 - m.m00 - m.m22) * 2.0;
				
				// TODO: speed this up
				q.x = (m.m10 + m.m01) / scale;
				q.y = 0.25 * scale;
				q.z = (m.m21 + m.m12) / scale;
				q.w = (m.m20 - m.m02) / scale;
			}
			else
			{
				// 3rd element of diag is greatest value
				// find scale according to 3rd element, and double it
				var scale : Float = Mathf.Sqrt(1.0 + m.m22 - m.m00 - m.m11) * 2.0;
				
				// TODO: speed this up
				q.x = (m.m20 + m.m02) / scale;
				q.y = (m.m21 + m.m12) / scale;
				q.z = 0.25 * scale;
				q.w = (m.m01 - m.m10) / scale;
			}
		}

		for (i in 0...b.length) SetIndex(i, b[i]);
		
		q.Normalize();
		
		return q;
	}
	
	/**
	 * 
	 */
	public var trace(get_trace, never):Float;
	private function get_trace():Float { return m00 + m11 + m22 + m33; }
	
	
	/**
	 * 
	 */
	public var rotation(get_rotation, null):Matrix4;
	private function get_rotation():Matrix4
	{		
		var m : Matrix4 = clone;
		return m.ToRotation();
	}
		
	/**
	 * 
	 */
	public var scale(get_scale, null):Matrix4;
	private function get_scale():Matrix4
	{
		//var d0:Float = Math.sqrt(m00 * m00 + m01 * m01 + m02 * m02);
		//var d1:Float = Math.sqrt(m10 * m10 + m11 * m11 + m12 * m12);
		//var d2:Float = Math.sqrt(m20 * m20 + m21 * m21 + m22 * m22);
		var d0:Float = Math.sqrt(m00 * m00 + m10 * m10 + m20 * m20);
		var d1:Float = Math.sqrt(m01 * m01 + m11 * m11 + m21 * m21);
		var d2:Float = Math.sqrt(m02 * m02 + m12 * m12 + m22 * m22);
		return Matrix4.temp.Set(d0, 0, 0, 0,   0, d1, 0, 0,   0, 0, d2, 0,   0, 0, 0, 1);
	}
	
	/**
	 * 
	 */
	public var translation(get_translation, null):Matrix4;
	private function get_translation():Matrix4
	{
		var t0:Float = m03;
		var t1:Float = m13;
		var t2:Float = m23;
		return new Matrix4(1,0,0,t0,  0,1, 0,t1,   0, 0, 1,t2,  0, 0, 0, 1);
	}
	
	public var transform(get_transform, never):Array<Dynamic>;
	private function get_transform():Array<Dynamic>
	{
		return [GetColumn(3).xyz, quaternion, diagonalLR];
	}
	 
	
	
	/**
	 * 
	 */
	public var inverseTransform(get_inverseTransform, null):Matrix4;
	private function get_inverseTransform():Matrix4
	{   
		var result:Matrix4 = Matrix4.identity;
		var l0:Vector3 = new Vector3(m00,m01,m02);
		var l1:Vector3 = new Vector3(m10,m11,m12);
		var l2:Vector3 = new Vector3(m20,m21, m22);
		var vl0 : Float = l0.length; 
		var vl1 : Float = l1.length; 
		var vl2 : Float = l2.length; 
		//length of the 3 lines of the 3x3 sector are the scales
		//TODO: The COLUMNS must be used for scale
		var sx:Float = (Mathf.Abs(vl0)<= 0.0001) ? 0.0 : (1.0/vl0); 
		var sy:Float = (Mathf.Abs(vl1)<= 0.0001) ? 0.0 : (1.0/vl1); 
		var sz:Float = (Mathf.Abs(vl2)<= 0.0001) ? 0.0 : (1.0/vl2); 
		
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
	}
	
	/**
	 * 
	 */
	public var transposed(get_transposed, null):Matrix4;
	private function get_transposed():Matrix4	
	{ return new Matrix4(m00,m10,m20,m30, m01,m11,m21,m31, m02,m12,m22,m32, m03,m13,m23,m33); }
	
	/**
	 * 
	 */
	public function ToRowMajor() : Array<Float> { return [m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33]; }
	
	/**
	 * 
	 */
	public function ToColumnMajor() : Array<Float> { return [m00,m10,m20,m30, m01,m11,m21,m31, m02,m12,m22,m32, m03,m13,m23,m33]; }
	
	/*
	public var m00(get_m00, set_m00) : Float; private function get_m00():Float { return m[ 0]; }	private function set_m00(v:Float):Float { m[ 0] = v; return v; }
	public var m01(get_m01, set_m01) : Float; private function get_m01():Float { return m[ 1]; }	private function set_m01(v:Float):Float { m[ 1] = v; return v; }
	public var m02(get_m02, set_m02) : Float; private function get_m02():Float { return m[ 2]; }	private function set_m02(v:Float):Float { m[ 2] = v; return v; }
	public var m03(get_m03, set_m03) : Float; private function get_m03():Float { return m[ 3]; }	private function set_m03(v:Float):Float { m[ 3] = v; return v; }
	
	public var m10(get_m10, set_m10) : Float; private function get_m10():Float { return m[ 4]; }	private function set_m10(v:Float):Float { m[ 4] = v; return v; }
	public var m11(get_m11, set_m11) : Float; private function get_m11():Float { return m[ 5]; }	private function set_m11(v:Float):Float { m[ 5] = v; return v; }
	public var m12(get_m12, set_m12) : Float; private function get_m12():Float { return m[ 6]; }	private function set_m12(v:Float):Float { m[ 6] = v; return v; }
	public var m13(get_m13, set_m13) : Float; private function get_m13():Float { return m[ 7]; }	private function set_m13(v:Float):Float { m[ 7] = v; return v; }
	
	public var m20(get_m20, set_m20) : Float; private function get_m20():Float { return m[ 8]; }	private function set_m20(v:Float):Float { m[ 8] = v; return v; }
	public var m21(get_m21, set_m21) : Float; private function get_m21():Float { return m[ 9]; }	private function set_m21(v:Float):Float { m[ 9] = v; return v; }
	public var m22(get_m22, set_m22) : Float; private function get_m22():Float { return m[10]; }	private function set_m22(v:Float):Float { m[ 9] = v; return v; }
	public var m23(get_m23, set_m23) : Float; private function get_m23():Float { return m[11]; }	private function set_m23(v:Float):Float { m[10] = v; return v; }
	
	public var m30(get_m30, set_m30) : Float; private function get_m30():Float { return m[12]; }	private function set_m30(v:Float):Float { m[11] = v; return v; }
	public var m31(get_m31, set_m31) : Float; private function get_m31():Float { return m[13]; }	private function set_m31(v:Float):Float { m[12] = v; return v; }
	public var m32(get_m32, set_m32) : Float; private function get_m32():Float { return m[14]; }	private function set_m32(v:Float):Float { m[13] = v; return v; }
	public var m33(get_m33, set_m33) : Float; private function get_m33():Float { return m[15]; }	private function set_m33(v:Float):Float { m[14] = v; return v; }
	
	public var m : Float32Array;
	//*/
	
	private var m : Float32Array;
	
	public var m00 : Float;
	public var m01 : Float;
	public var m02 : Float;
	public var m03 : Float;	
	public var m10 : Float;
	public var m11 : Float;
	public var m12 : Float;
	public var m13 : Float;	
	public var m20 : Float;
	public var m21 : Float;
	public var m22 : Float;
	public var m23 : Float;	
	public var m30 : Float;
	public var m31 : Float;
	public var m32 : Float;
	public var m33 : Float;
	
	/**
	 * 
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
	public function new(p_m00:Float = 0, p_m01:Float = 0, p_m02:Float = 0, p_m03:Float = 0,
						p_m10:Float = 0, p_m11:Float = 0, p_m12:Float = 0, p_m13:Float = 0,
						p_m20:Float = 0, p_m21:Float = 0, p_m22:Float = 0, p_m23:Float = 0,
						p_m30:Float = 0, p_m31:Float = 0, p_m32:Float = 0, p_m33:Float = 0)
	{
		/*
		m = new Float32Array([
		p_m00, p_m01, p_m02, p_m03,
		p_m10, p_m11, p_m12, p_m13,
		p_m20, p_m21, p_m22, p_m23,
		p_m30, p_m31, p_m32, p_m33
		]);	
		//*/
		m = new Float32Array(16);
		
		m00 = p_m00;
		m01 = p_m01;
		m02 = p_m02;
		m03 = p_m03;
		m10 = p_m10;
		m11 = p_m11;
		m12 = p_m12;
		m13 = p_m13;
		m20 = p_m20;
		m21 = p_m21;
		m22 = p_m22;
		m23 = p_m23;
		m30 = p_m30;
		m31 = p_m31;
		m32 = p_m32;
		m33 = p_m33;
		
		
		
		
	}
	
	/**
	 * 
	 * @param	p_index
	 * @return
	 */
	public function GetLine(p_index:Int):Vector4
	{
		return new Vector4(GetRowCol(p_index, 0), GetRowCol(p_index, 1), GetRowCol(p_index, 2), GetRowCol(p_index, 3));
	}
	
	/**
	 * 
	 * @param	p_index
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 * @return
	 */
	public function SetLine(p_index:Int,p_x : Float,p_y:Float,p_z:Float,p_w:Float) : Void
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
	 * 
	 * @param	p_index
	 * @return
	 */
	public function GetColumn(p_index:Int):Vector4
	{
		return new Vector4(GetRowCol(0,p_index), GetRowCol(1,p_index), GetRowCol(2,p_index), GetRowCol(3,p_index));
	}
	
	/**
	 * 
	 * @param	p_index
	 * @param	p_x
	 * @param	p_y
	 * @param	p_z
	 * @param	p_w
	 * @return
	 */
	public function SetColumn(p_index:Int,p_x : Float,p_y:Float,p_z:Float,p_w:Float) : Void
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
	 * 
	 */
	public var diagonalLR(get_diagonalLR, set_diagonalLR) : Vector4;
	//private function get_diagonalLR():Vector4 { return new Vector4(m[0], m[5], m[10], m[15]); }
	//private function set_diagonalLR(v:Vector4):Vector4 { m[0] = v.x; m[5] = v.y; m[10] = v.z; m[15] = v.w; return v; }
	private function get_diagonalLR():Vector4 { return new Vector4(m00, m11, m22, m33); }
	private function set_diagonalLR(v:Vector4):Vector4 { m00 = v.x; m11 = v.y; m22 = v.z; m33 = v.w; return v; }
	
	/**
	 * 
	 * @return
	 */
	public function SetIdentity():Matrix4
	{
		Set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
		return this;
	}
	
	/**
	 * 
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
	public function Set(p_m00:Float = 0, p_m01:Float = 0, p_m02:Float = 0, p_m03:Float = 0,
	                    p_m10:Float = 0, p_m11:Float = 0, p_m12:Float = 0, p_m13:Float = 0,
	                    p_m20:Float = 0, p_m21:Float = 0, p_m22:Float = 0, p_m23:Float = 0,
	                    p_m30:Float = 0, p_m31:Float = 0, p_m32:Float = 0, p_m33:Float = 0):Matrix4
	{
		/*
		m[ 0] = p_m00;
		m[ 1] = p_m01;
		m[ 2] = p_m02;
		m[ 3] = p_m03;
		m[ 4] = p_m10;
		m[ 5] = p_m11;
		m[ 6] = p_m12;
		m[ 7] = p_m13;
		m[ 8] = p_m20;
		m[ 9] = p_m21;
		m[10] = p_m22;
		m[11] = p_m23;
		m[12] = p_m30;
		m[13] = p_m31;
		m[14] = p_m32;
		m[15] = p_m33;
		//*/
		
		m00 = p_m00;
		m01 = p_m01;
		m02 = p_m02;
		m03 = p_m03;
		m10 = p_m10;
		m11 = p_m11;
		m12 = p_m12;
		m13 = p_m13;
		m20 = p_m20;
		m21 = p_m21;
		m22 = p_m22;
		m23 = p_m23;
		m30 = p_m30;
		m31 = p_m31;
		m32 = p_m32;
		m33 = p_m33;
		
		
		
		
		
		return this;
	}
	
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
	
	public function SetIndex(p_index : Int, p_value : Float):Void
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
	}
	
	/**
	 * 
	 * @param	p_row
	 * @param	p_col
	 * @param	p_value
	 */
	public function SetRowCol(p_row:Int,p_col:Int, p_value:Float):Void
	{
		//m[p_col + (p_row << 2)] = p_value;
		SetIndex(p_col + (p_row << 2), p_value);
	}
	
	/**
	 * 
	 * @param	p_row
	 * @param	p_col
	 * @return
	 */
	public function GetRowCol(p_row:Int,p_col:Int):Float
	{
		//return m[p_col + (p_row << 2)];
		return GetIndex(p_col + (p_row << 2));
	}
	
	/**
	 * 
	 * @param	p_a
	 * @param	p_b
	 * @return
	 */
	public function SwapCol(p_a : Int, p_b : Int):Matrix4
	{
		var a0 : Float = GetRowCol(0, p_a);
		var a1 : Float = GetRowCol(1, p_a);
		var a2 : Float = GetRowCol(2, p_a);
		var a3 : Float = GetRowCol(3, p_a);		
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
	 * 
	 * @param	p_a
	 * @param	p_b
	 * @return
	 */
	public function SwapRow(p_a : Int, p_b : Int):Matrix4
	{
		var a0 : Float = GetRowCol(p_a,0);
		var a1 : Float = GetRowCol(p_a,1);
		var a2 : Float = GetRowCol(p_a,2);
		var a3 : Float = GetRowCol(p_a,3);		
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
	 * 
	 * @return
	 */
	public function Transpose():Matrix4
	{
		var t00:Float = m00;
		var t01:Float = m01;
		var t02:Float = m02;
		var t03:Float = m03;		
		var t10:Float = m10;
		var t11:Float = m11;
		var t12:Float = m12;
		var t13:Float = m13;
		var t20:Float = m20;
		var t21:Float = m21;
		var t22:Float = m22;
		var t23:Float = m23;
		var t30:Float = m30;
		var t31:Float = m31;
		var t32:Float = m32;
		var t33:Float = m33;
		Set(t00, t10, t20, t30,		
			t01, t11, t21, t31,
			t02, t12, t22, t32,
			t03, t13, t23, t33);
		return this;
	}
	
	public function ToRotation():Matrix4
	{
		var tmp : Vector3 = new Vector3();		
		tmp.Set(m00, m01, m02).Normalize(); m00 = tmp.x; m01 = tmp.y; m02 = tmp.z; m03 = 0.0;
		tmp.Set(m10, m11, m12).Normalize(); m10 = tmp.x; m11 = tmp.y; m12 = tmp.z; m13 = 0.0;
		tmp.Set(m20, m21, m22).Normalize(); m20 = tmp.x; m21 = tmp.y; m22 = tmp.z; m23 = 0.0;
		m30 = m31 = m32 = 0.0; m33 = 1.0;
		return this;
	}
	
	public function Rotate(p_vector : Vector3):Vector3
	{
		var tmp : Vector3 = new Vector3();
		tmp.Set(m00, m01, m02).Normalize();
		var vx:Float = (tmp.x * p_vector.x) + (tmp.y * p_vector.y) + (tmp.z * p_vector.z);
		
		tmp.Set(m10, m11, m12).Normalize(); 
		var vy:Float = (tmp.x * p_vector.x) + (tmp.y * p_vector.y) + (tmp.z * p_vector.z);
		
		tmp.Set(m20, m21, m22).Normalize();
		var vz:Float = (tmp.x * p_vector.x) + (tmp.y * p_vector.y) + (tmp.z * p_vector.z);
		
		p_vector.x = vx;
		p_vector.y = vy;
		p_vector.z = vz;	
		
		return p_vector;
	}
	
	public function SetTRS(p_position : Vector3, p_rotation : Quaternion, p_scale:Vector3 = null):Matrix4
	{
		var sx:Float = p_scale == null ? 1.0 : p_scale.x;			
		var sy:Float = p_scale == null ? 1.0 : p_scale.y;
		var sz:Float = p_scale == null ? 1.0 : p_scale.z;		
		var px:Float = p_position.x;			
		var py:Float = p_position.y;
		var pz:Float = p_position.z;							
		var r : Matrix4 = p_rotation.matrix;
		var l : Matrix4 = this;
		l.m00 = r.m00 * sx; l.m01 = r.m01 * sy; l.m02 = r.m02 * sz; l.m03 = px;
		l.m10 = r.m10 * sx; l.m11 = r.m11 * sy; l.m12 = r.m12 * sz; l.m13 = py;
		l.m20 = r.m20 * sx; l.m21 = r.m21 * sy; l.m22 = r.m22 * sz; l.m23 = pz;
		l.m30 = l.m31 = l.m32 = 0.0; l.m33 = 1.0;
		return l;
	}
	
	/**
	 * 
	 * @param	p_matrix
	 * @return
	 */
	public function MultiplyTransform(p_matrix : Matrix4) : Matrix4
	{
		var r00:Float = m00 * p_matrix.m00 + m01 * p_matrix.m10 + m02 * p_matrix.m20;
		var r01:Float = m00 * p_matrix.m01 + m01 * p_matrix.m11 + m02 * p_matrix.m21;
		var r02:Float = m00 * p_matrix.m02 + m01 * p_matrix.m12 + m02 * p_matrix.m22;
		var r03:Float = m00 * p_matrix.m03 + m01 * p_matrix.m13 + m02 * p_matrix.m23 + m03;
		var r10:Float = m10 * p_matrix.m00 + m11 * p_matrix.m10 + m12 * p_matrix.m20;
		var r11:Float = m10 * p_matrix.m01 + m11 * p_matrix.m11 + m12 * p_matrix.m21;
		var r12:Float = m10 * p_matrix.m02 + m11 * p_matrix.m12 + m12 * p_matrix.m22;
		var r13:Float = m10 * p_matrix.m03 + m11 * p_matrix.m13 + m12 * p_matrix.m23 + m13;
		var r20:Float = m20 * p_matrix.m00 + m21 * p_matrix.m10 + m22 * p_matrix.m20;
		var r21:Float = m20 * p_matrix.m01 + m21 * p_matrix.m11 + m22 * p_matrix.m21;
		var r22:Float = m20 * p_matrix.m02 + m21 * p_matrix.m12 + m22 * p_matrix.m22;
		var r23:Float = m20 * p_matrix.m03 + m21 * p_matrix.m13 + m22 * p_matrix.m23 + m23;
		Set(
			r00,r01,r02,r03,
			r10,r11,r12,r13,
			r20,r21,r22,r23,
			0, 0, 0, 1);			
		return this;
	}
	
	/**
	 * 
	 * @param	p_matrix
	 * @return
	 */
	public function Multiply3x4(p_matrix : Matrix4) : Matrix4
	{
		var r00:Float = m00 * p_matrix.m00 + m01 * p_matrix.m10 + m02 * p_matrix.m20 + m03 * p_matrix.m30;
		var r01:Float = m00 * p_matrix.m01 + m01 * p_matrix.m11 + m02 * p_matrix.m21 + m03 * p_matrix.m31;
		var r02:Float = m00 * p_matrix.m02 + m01 * p_matrix.m12 + m02 * p_matrix.m22 + m03 * p_matrix.m32;
		var r03:Float = m00 * p_matrix.m03 + m01 * p_matrix.m13 + m02 * p_matrix.m23 + m03 * p_matrix.m33;
		var r10:Float = m10 * p_matrix.m00 + m11 * p_matrix.m10 + m12 * p_matrix.m20 + m13 * p_matrix.m30;
		var r11:Float = m10 * p_matrix.m01 + m11 * p_matrix.m11 + m12 * p_matrix.m21 + m13 * p_matrix.m31;
		var r12:Float = m10 * p_matrix.m02 + m11 * p_matrix.m12 + m12 * p_matrix.m22 + m13 * p_matrix.m32;
		var r13:Float = m10 * p_matrix.m03 + m11 * p_matrix.m13 + m12 * p_matrix.m23 + m13 * p_matrix.m33;
		var r20:Float = m20 * p_matrix.m00 + m21 * p_matrix.m10 + m22 * p_matrix.m20 + m23 * p_matrix.m30;
		var r21:Float = m20 * p_matrix.m01 + m21 * p_matrix.m11 + m22 * p_matrix.m21 + m23 * p_matrix.m31;
		var r22:Float = m20 * p_matrix.m02 + m21 * p_matrix.m12 + m22 * p_matrix.m22 + m23 * p_matrix.m32;
		var r23:Float = m20 * p_matrix.m03 + m21 * p_matrix.m13 + m22 * p_matrix.m23 + m23 * p_matrix.m33;		
		Set(
			r00,r01,r02,r03,
			r10,r11,r12,r13,
			r20,r21,r22,r23,
			m30, m31, m32, m33);
		return this;
	}
	
	/**
	 * 
	 * @param	p_matrix
	 * @return
	 */
	public function Multiply(p_matrix : Matrix4) : Matrix4
	{
		var r00:Float = m00 * p_matrix.m00 + m01 * p_matrix.m10 + m02 * p_matrix.m20 + m03 * p_matrix.m30;
		var r01:Float = m00 * p_matrix.m01 + m01 * p_matrix.m11 + m02 * p_matrix.m21 + m03 * p_matrix.m31;
		var r02:Float = m00 * p_matrix.m02 + m01 * p_matrix.m12 + m02 * p_matrix.m22 + m03 * p_matrix.m32;
		var r03:Float = m00 * p_matrix.m03 + m01 * p_matrix.m13 + m02 * p_matrix.m23 + m03 * p_matrix.m33;
		
		var r10:Float = m10 * p_matrix.m00 + m11 * p_matrix.m10 + m12 * p_matrix.m20 + m13 * p_matrix.m30;
		var r11:Float = m10 * p_matrix.m01 + m11 * p_matrix.m11 + m12 * p_matrix.m21 + m13 * p_matrix.m31;
		var r12:Float = m10 * p_matrix.m02 + m11 * p_matrix.m12 + m12 * p_matrix.m22 + m13 * p_matrix.m32;
		var r13:Float = m10 * p_matrix.m03 + m11 * p_matrix.m13 + m12 * p_matrix.m23 + m13 * p_matrix.m33;
		
		var r20:Float = m20 * p_matrix.m00 + m21 * p_matrix.m10 + m22 * p_matrix.m20 + m23 * p_matrix.m30;
		var r21:Float = m20 * p_matrix.m01 + m21 * p_matrix.m11 + m22 * p_matrix.m21 + m23 * p_matrix.m31;
		var r22:Float = m20 * p_matrix.m02 + m21 * p_matrix.m12 + m22 * p_matrix.m22 + m23 * p_matrix.m32;
		var r23:Float = m20 * p_matrix.m03 + m21 * p_matrix.m13 + m22 * p_matrix.m23 + m23 * p_matrix.m33;
		
		var r30:Float = m30 * p_matrix.m00 + m31 * p_matrix.m10 + m32 * p_matrix.m20 + m33 * p_matrix.m30;
		var r31:Float = m30 * p_matrix.m01 + m31 * p_matrix.m11 + m32 * p_matrix.m21 + m33 * p_matrix.m31;
		var r32:Float = m30 * p_matrix.m02 + m31 * p_matrix.m12 + m32 * p_matrix.m22 + m33 * p_matrix.m32;
		var r33:Float = m30 * p_matrix.m03 + m31 * p_matrix.m13 + m32 * p_matrix.m23 + m33 * p_matrix.m33;
		Set(
			r00,r01,r02,r03,
			r10,r11,r12,r13,
			r20,r21,r22,r23,
			r30, r31, r32, r33);
		return this;
	}
	
	/**
	 * 
	 * 
	 * @param	p_point
	 */
	public function Transform4x4(p_point : Vector4):Vector4
	{
		var vx:Float = (m00 * p_point.x) + (m01 * p_point.y) + (m02 * p_point.z) + (m03 * p_point.w);
		var vy:Float = (m10 * p_point.x) + (m11 * p_point.y) + (m12 * p_point.z) + (m13 * p_point.w);
		var vz:Float = (m20 * p_point.x) + (m21 * p_point.y) + (m22 * p_point.z) + (m23 * p_point.w);
		var vw:Float = (m30 * p_point.x) + (m31 * p_point.y) + (m32 * p_point.z) + (m33 * p_point.w);
		p_point.x = vx;
		p_point.y = vy;
		p_point.z = vz;
		p_point.w = vw;
		return p_point;
	}
	
	/**
	 * 
	 * @param	p_point
	 */
	public function Transform3x4(p_point:Vector3):Vector3
	{
		var vx:Float = (m00 * p_point.x) + (m01 * p_point.y) + (m02 * p_point.z) + m03;
		var vy:Float = (m10 * p_point.x) + (m11 * p_point.y) + (m12 * p_point.z) + m13;
		var vz:Float = (m20 * p_point.x) + (m21 * p_point.y) + (m22 * p_point.z) + m23;		
		p_point.x = vx;
		p_point.y = vy;
		p_point.z = vz;		
		return p_point;
	}
	
	/**
	 * 
	 * @param	p_point
	 */
	public function Transform3x3(p_point:Vector3):Vector3
	{
		var vx:Float = (m00 * p_point.x) + (m01 * p_point.y) + (m02 * p_point.z);
		var vy:Float = (m10 * p_point.x) + (m11 * p_point.y) + (m12 * p_point.z);
		var vz:Float = (m20 * p_point.x) + (m21 * p_point.y) + (m22 * p_point.z);		
		p_point.x = vx;
		p_point.y = vy;
		p_point.z = vz;		
		return p_point;
	}
	
	/**
	 * 
	 * @param	p_point
	 */
	public function Transform2x3(p_point:Vector2):Void
	{
		var vx:Float = (m00 * p_point.x) + (m01 * p_point.y) + m03;
		var vy:Float = (m10 * p_point.x) + (m11 * p_point.y) + m13;		
		p_point.x = vx;
		p_point.y = vy;
	}
	
	/**
	 * 
	 * @param	p_point
	 */
	public function Transform2x2(p_point:Vector2):Void
	{
		var vx:Float = (m00 * p_point.x) + (m01 * p_point.y);
		var vy:Float = (m10 * p_point.x) + (m11 * p_point.y);		
		p_point.x = vx;
		p_point.y = vy;
	}
	
	/**
	 * 
	 * @param	p_left
	 * @param	p_right
	 * @param	p_top
	 * @param	p_bottom
	 * @param	p_near
	 * @param	p_far
	 * @return
	 */
	public function SetFrustum(p_left:Float,p_right:Float,p_top:Float,p_bottom:Float,p_near:Float,p_far:Float):Matrix4
	{
		SetIdentity();
		var n2 :Float = p_near * 2.0;
		var rml:Float = 1.0 / (p_right - p_left);
		var tmb:Float = 1.0 / (p_top - p_bottom);
		var fmn:Float = 1.0 / (p_far - p_near);
		m00 = n2 * rml;                
		m02 = (p_right + p_left) * rml;
		m11 = n2 * tmb;                
		m12 = (p_top + p_bottom) * tmb;
		m22 = -(p_near + p_far) * fmn; 
		m23 = (-n2 * p_far) * fmn;
		m32 = -1.0;
		m33 = 0;
		return this;
	}
	
	/**
	 * 
	 * @param	p_left
	 * @param	p_right
	 * @param	p_top
	 * @param	p_bottom
	 * @param	p_near
	 * @param	p_far
	 * @return
	 */
	public function SetFrustumInverse(p_left:Float,p_right:Float,p_top:Float,p_bottom:Float,p_near:Float,p_far:Float):Matrix4
	{
		SetIdentity();
		var n2 :Float = p_near * 2.0;
		var rml:Float = (p_right - p_left);
		var tmb:Float = (p_top - p_bottom);
		var fmn:Float = (p_far - p_near);
		m00 = rml / n2;
		m03 = (p_right + p_left) / n2;
		m11 = tmb / n2;
		m13 = (p_top + p_bottom) / n2;
		m22 = 0.0;
		m23 = -1.0;
		m32 = fmn / (-n2 * p_far);
		m33 = (p_far + p_near) / (n2 * p_far);
		return this;
	}
	
	/**
	 * 
	 * @param	p_left
	 * @param	p_right
	 * @param	p_top
	 * @param	p_bottom
	 * @param	p_near
	 * @param	p_far
	 * @return
	 */
	public function SetOrtho(p_left:Float,p_right:Float,p_top:Float,p_bottom:Float,p_near:Float,p_far:Float):Matrix4
	{
		SetIdentity();
		var n2 :Float = p_near * 2.0;
		var rml:Float = 1.0 / (p_right - p_left);
		var tmb:Float = 1.0 / (p_top - p_bottom);
		var fmn:Float = 1.0 / (p_far - p_near);
		m00 = 2.0 * rml;
		m03 = -(p_right + p_left) * rml;
		m11 = 2.0 * tmb;
		m13 = -(p_top + p_bottom) * tmb;
		m22 = -2.0 * fmn;
		m23 = -(p_far + p_near) * fmn;
		return this;
	}
	
	/**
	 * 
	 * @param	p_fov
	 * @param	p_aspect
	 * @param	p_near
	 * @param	p_far
	 * @return
	 */
	public function SetPerspective(p_fov:Float,p_aspect:Float,p_near:Float,p_far:Float):Matrix4
	{
		var t:Float = Mathf.Tan(p_fov*0.5 * Mathf.Deg2Rad) * p_near;
		var b:Float = -t;
		var l:Float = p_aspect * b;
		var r:Float = p_aspect * t;		
		return SetFrustum(l, r, t, b, p_near, p_far);
	}
	
	/**
	 * 
	 * @param	p_fov
	 * @param	p_aspect
	 * @param	p_near
	 * @param	p_far
	 * @return
	 */
	public function SetPerspectiveInverse(p_fov:Float,p_aspect:Float,p_near:Float,p_far:Float):Matrix4
	{
		var t:Float = Mathf.Tan(p_fov*0.5 * Mathf.Deg2Rad) * p_near;
		var b:Float = -t;
		var l:Float = p_aspect * b;
		var r:Float = p_aspect * t;
		return SetFrustumInverse(l, r, t, b, p_near, p_far);
	}
	
	/**
	 * 
	 * @return
	 */
	public function ToArray() : Array<Float> { return [	m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33]; }
	
	/**
	 * 
	 * @return
	 */
	public function ToBuffer() : Float32Array 
	{ 
		m[ 0] = m00;
		m[ 1] = m01;
		m[ 2] = m02;
		m[ 3] = m03;
		m[ 4] = m10;
		m[ 5] = m11;
		m[ 6] = m12;
		m[ 7] = m13;
		m[ 8] = m20;
		m[ 9] = m21;
		m[10] = m22;
		m[11] = m23;
		m[12] = m30;
		m[13] = m31;
		m[14] = m32;
		m[15] = m33;		
		return m; 
	}
	
	/**
	 * 
	 * @return
	 */
	public function ToString(p_linear : Bool=true):String
	{
		var a : Array<Float> = ToArray();
		var s : Array<String> = [];
		for (i in 0...a.length) { a[i] = Std.int(a[i] * 100.0) / 100; s.push(a[i] >= 0 ? " " + a[i] : a[i] + ""); }
		var res:String = "";
		for (i in 0...4)
		{
			for (j in 0...4) { res += s[j+(i*4)] + ((j < 3) ? "," : ""); }
			res += i == 3 ? "" : (p_linear ? " |" : "\n");
		}
		return res;
	}
	
}