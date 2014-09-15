package haxor.math;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Quaternion extends haxe.lang.HxObject
{
	public    Quaternion(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Quaternion(java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_z, java.lang.Object p_w)
	{
		haxor.math.Quaternion.__hx_ctor_haxor_math_Quaternion(this, p_x, p_y, p_z, p_w);
	}
	
	
	public static   void __hx_ctor_haxor_math_Quaternion(haxor.math.Quaternion __temp_me255601, java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_z, java.lang.Object p_w)
	{
		double __temp_p_w255600 = ( (( p_w == null )) ? (((double) (1.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_w)) )) );
		double __temp_p_z255599 = ( (( p_z == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_z)) )) );
		double __temp_p_y255598 = ( (( p_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_y)) )) );
		double __temp_p_x255597 = ( (( p_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_x)) )) );
		__temp_me255601.x = __temp_p_x255597;
		__temp_me255601.y = __temp_p_y255598;
		__temp_me255601.z = __temp_p_z255599;
		__temp_me255601.w = __temp_p_w255600;
	}
	
	
	public static  haxor.math.Quaternion temp;
	
	public static   haxor.math.Quaternion get_temp()
	{
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			return _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
		}
		
	}
	
	
	public static  haxor.math.Quaternion identity;
	
	public static   haxor.math.Quaternion get_identity()
	{
		return new haxor.math.Quaternion(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1.0) ));
	}
	
	
	public static   haxor.math.Quaternion FromEuler(haxor.math.Vector3 p_euler, haxor.math.Quaternion p_result)
	{
		haxor.math.Quaternion r = null;
		if (( p_result == null )) 
		{
			r = new haxor.math.Quaternion(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			r = p_result;
		}
		
		haxor.math.Vector3 c = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			c = _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
		}
		
		haxor.math.Vector3 s = null;
		{
			haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
			s = _this1.m_v3.__get(_this1.m_nv3 = ( (( _this1.m_nv3 + 1 )) % _this1.m_v3.length ));
		}
		
		double k = 0.0087266462599716477;
		haxor.math.Vector3 __temp_stmt256435 = null;
		{
			haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
			__temp_stmt256435 = _this2.m_v3.__get(_this2.m_nv3 = ( (( _this2.m_nv3 + 1 )) % _this2.m_v3.length ));
		}
		
		haxor.math.Vector3 e = __temp_stmt256435.Set(( p_euler.x * k ), ( p_euler.y * k ), ( p_euler.z * k ));
		c.Set(java.lang.Math.cos(e.x), java.lang.Math.cos(e.y), java.lang.Math.cos(e.z));
		s.Set(java.lang.Math.sin(e.x), java.lang.Math.sin(e.y), java.lang.Math.sin(e.z));
		r.x = ( ( ( s.x * c.y ) * c.z ) - ( ( c.x * s.y ) * s.z ) );
		r.y = ( ( ( c.x * s.y ) * c.z ) + ( ( s.x * c.y ) * s.z ) );
		r.z = ( ( ( c.x * c.y ) * s.z ) - ( ( s.x * s.y ) * c.z ) );
		r.w = ( ( ( c.x * c.y ) * c.z ) + ( ( s.x * s.y ) * s.z ) );
		return r;
	}
	
	
	public static   haxor.math.Vector3 ToEuler(haxor.math.Quaternion p_quaternion, haxor.math.Vector3 p_result)
	{
		haxor.math.Quaternion q = p_quaternion;
		haxor.math.Vector3 r = null;
		if (( p_result == null )) 
		{
			r = new haxor.math.Vector3(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			r = p_result;
		}
		
		double test = ( ( q.x * q.y ) + ( q.z * q.w ) );
		if (( test > 0.499 )) 
		{
			r.y = ( ( 2 * java.lang.Math.atan2(q.x, q.w) ) * 57.295779513082320876798154814105 );
			r.z = ( ( java.lang.Math.PI * 0.5 ) * 57.295779513082320876798154814105 );
			r.x = ((double) (0) );
			return r;
		}
		
		if (( test < -0.499 )) 
		{
			r.y = ( -2. * java.lang.Math.atan2(q.x, q.w) );
			r.z = ( (  - (java.lang.Math.PI)  * 0.5 ) * 57.295779513082320876798154814105 );
			r.x = ((double) (0) );
			return r;
		}
		
		double sqx = ( q.x * q.x );
		double sqy = ( q.y * q.y );
		double sqz = ( q.z * q.z );
		r.y = ( java.lang.Math.atan2(( ( ( 2.0 * q.y ) * q.w ) - ( ( 2.0 * q.x ) * q.z ) ), ( ( 1.0 - ( 2.0 * sqy ) ) - ( 2.0 * sqz ) )) * 57.295779513082320876798154814105 );
		r.z = ( java.lang.Math.asin(( 2.0 * test )) * 57.295779513082320876798154814105 );
		r.x = ( java.lang.Math.atan2(( ( ( 2.0 * q.x ) * q.w ) - ( ( 2.0 * q.y ) * q.z ) ), ( ( 1.0 - ( 2.0 * sqx ) ) - ( 2.0 * sqz ) )) * 57.295779513082320876798154814105 );
		return r;
	}
	
	
	public static   haxor.math.Quaternion FromMatrix4(haxor.math.Matrix4 p_matrix, haxor.math.Quaternion p_result)
	{
		haxor.math.Quaternion r = null;
		if (( p_result == null )) 
		{
			r = new haxor.math.Quaternion(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			r = p_result;
		}
		
		haxor.math.Matrix4 v = p_matrix;
		double fourXSquaredMinus1 = ( ( v.m00 - v.m11 ) - v.m22 );
		double fourYSquaredMinus1 = ( ( v.m11 - v.m00 ) - v.m22 );
		double fourZSquaredMinus1 = ( ( v.m22 - v.m00 ) - v.m11 );
		double fourWSquaredMinus1 = ( ( v.m00 + v.m11 ) + v.m22 );
		int biggestIndex = 0;
		double fourBiggestSquaredMinus1 = fourWSquaredMinus1;
		if (( fourXSquaredMinus1 > fourBiggestSquaredMinus1 )) 
		{
			fourBiggestSquaredMinus1 = fourXSquaredMinus1;
			biggestIndex = 1;
		}
		
		if (( fourYSquaredMinus1 > fourBiggestSquaredMinus1 )) 
		{
			fourBiggestSquaredMinus1 = fourYSquaredMinus1;
			biggestIndex = 2;
		}
		
		if (( fourZSquaredMinus1 > fourBiggestSquaredMinus1 )) 
		{
			fourBiggestSquaredMinus1 = fourZSquaredMinus1;
			biggestIndex = 3;
		}
		
		double biggestVal = ( java.lang.Math.sqrt(( fourBiggestSquaredMinus1 + 1.0 )) * 0.5 );
		double mult = ( 0.25 / biggestVal );
		switch (biggestIndex)
		{
			case 0:
			{
				r.w = biggestVal;
				r.x = ( (( v.m21 - v.m12 )) * mult );
				r.y = ( (( v.m02 - v.m20 )) * mult );
				r.z = ( (( v.m10 - v.m01 )) * mult );
				break;
			}
			
			
			case 1:
			{
				r.w = ( (( v.m21 - v.m12 )) * mult );
				r.x = biggestVal;
				r.y = ( (( v.m10 + v.m01 )) * mult );
				r.z = ( (( v.m02 + v.m20 )) * mult );
				break;
			}
			
			
			case 2:
			{
				r.w = ( (( v.m02 - v.m20 )) * mult );
				r.x = ( (( v.m10 + v.m01 )) * mult );
				r.y = biggestVal;
				r.z = ( (( v.m21 + v.m12 )) * mult );
				break;
			}
			
			
			case 3:
			{
				r.w = ( (( v.m10 - v.m01 )) * mult );
				r.x = ( (( v.m02 + v.m20 )) * mult );
				r.y = ( (( v.m21 + v.m12 )) * mult );
				r.z = biggestVal;
				break;
			}
			
			
		}
		
		return r;
	}
	
	
	public static   double Dot(haxor.math.Quaternion p_a, haxor.math.Quaternion p_b)
	{
		return ( ( ( ( p_a.x * p_b.x ) + ( p_a.y * p_b.y ) ) + ( p_a.z * p_b.z ) ) + ( p_a.w * p_b.w ) );
	}
	
	
	public static   haxor.math.Quaternion DeltaRotation(haxor.math.Quaternion p_a, haxor.math.Quaternion p_b, haxor.math.Quaternion p_result)
	{
		haxor.math.Quaternion r = null;
		if (( p_result == null )) 
		{
			r = new haxor.math.Quaternion(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			r = p_result;
		}
		
		haxor.math.Quaternion.Inverse(p_a, r);
		r.Multiply(p_b, null);
		return r;
	}
	
	
	public static   haxor.math.Quaternion Inverse(haxor.math.Quaternion p_q, haxor.math.Quaternion p_result)
	{
		double d = ( ( ( ( p_q.x * p_q.x ) + ( p_q.y * p_q.y ) ) + ( p_q.z * p_q.z ) ) + ( p_q.w * p_q.w ) );
		if (( d <= 0.0 )) 
		{
			d = 0.0;
		}
		 else 
		{
			d = ( 1.0 / d );
		}
		
		haxor.math.Quaternion r = null;
		if (( p_result == null )) 
		{
			r = new haxor.math.Quaternion(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			r = p_result;
		}
		
		return r.Set((  - (p_q.x)  * d ), (  - (p_q.y)  * d ), (  - (p_q.z)  * d ), ( p_q.w * d ));
	}
	
	
	public static   haxor.math.Quaternion Lerp(haxor.math.Quaternion p_a, haxor.math.Quaternion p_b, double p_ratio, haxor.math.Quaternion p_result)
	{
		haxor.math.Quaternion c = null;
		if (( p_result == null )) 
		{
			c = new haxor.math.Quaternion(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			c = p_result;
		}
		
		haxor.math.Quaternion ca = new haxor.math.Quaternion(((java.lang.Object) (p_a.x) ), ((java.lang.Object) (p_a.y) ), ((java.lang.Object) (p_a.z) ), ((java.lang.Object) (p_a.w) ));
		double dot = ( ( ( ( p_a.x * p_b.x ) + ( p_a.y * p_b.y ) ) + ( p_a.z * p_b.z ) ) + ( p_a.w * p_b.w ) );
		if (( dot < 0.0 )) 
		{
			ca.w =  - (ca.w) ;
			ca.x =  - (ca.x) ;
			ca.y =  - (ca.y) ;
			ca.z =  - (ca.z) ;
		}
		
		c.x = ( ca.x + ( (( p_b.x - ca.x )) * p_ratio ) );
		c.y = ( ca.y + ( (( p_b.y - ca.y )) * p_ratio ) );
		c.z = ( ca.z + ( (( p_b.z - ca.z )) * p_ratio ) );
		c.w = ( ca.w + ( (( p_b.w - ca.w )) * p_ratio ) );
		c.Normalize();
		return c;
	}
	
	
	public static   haxor.math.Quaternion Slerp(haxor.math.Quaternion p_a, haxor.math.Quaternion p_b, double p_ratio)
	{
		haxor.math.Quaternion qm = new haxor.math.Quaternion(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		haxor.math.Quaternion __temp_stmt256436 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt256436 = _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
		}
		
		haxor.math.Quaternion z = __temp_stmt256436.SetQuaternion(p_b);
		double cosTheta = ( ( ( ( p_a.x * p_b.x ) + ( p_a.y * p_b.y ) ) + ( p_a.z * p_b.z ) ) + ( p_a.w * p_b.w ) );
		if (( cosTheta < 0.0 )) 
		{
			z.Invert();
			cosTheta =  - (cosTheta) ;
		}
		
		if (( cosTheta > 0.9999 )) 
		{
			double __temp_stmt256437 = 0.0;
			{
				double p_a1 = p_a.x;
				__temp_stmt256437 = ( p_a1 + ( (( z.x - p_a1 )) * p_ratio ) );
			}
			
			double __temp_stmt256438 = 0.0;
			{
				double p_a2 = p_a.y;
				__temp_stmt256438 = ( p_a2 + ( (( z.y - p_a2 )) * p_ratio ) );
			}
			
			double __temp_stmt256439 = 0.0;
			{
				double p_a3 = p_a.z;
				__temp_stmt256439 = ( p_a3 + ( (( z.z - p_a3 )) * p_ratio ) );
			}
			
			double __temp_stmt256440 = 0.0;
			{
				double p_a4 = p_a.w;
				__temp_stmt256440 = ( p_a4 + ( (( z.w - p_a4 )) * p_ratio ) );
			}
			
			qm.Set(__temp_stmt256437, __temp_stmt256438, __temp_stmt256439, __temp_stmt256440);
		}
		 else 
		{
			double angle = java.lang.Math.acos(cosTheta);
			double s = ( 1.0 / java.lang.Math.sin(angle) );
			double s0 = java.lang.Math.sin(( (( 1.0 - p_ratio )) * angle ));
			double s1 = java.lang.Math.sin(( p_ratio * angle ));
			qm.x = ( (( ( s0 * p_a.x ) + ( s1 * z.x ) )) * s );
			qm.y = ( (( ( s0 * p_a.y ) + ( s1 * z.y ) )) * s );
			qm.z = ( (( ( s0 * p_a.z ) + ( s1 * z.z ) )) * s );
			qm.w = ( (( ( s0 * p_a.w ) + ( s1 * z.w ) )) * s );
		}
		
		return qm;
	}
	
	
	public static   haxor.math.Quaternion FromAxisAngle(haxor.math.Vector3 p_axis, double p_angle)
	{
		p_angle = ( ( p_angle * 0.5 ) * 0.01745329251994329576923690768489 );
		double l = java.lang.Math.sqrt(( ( ( p_axis.x * p_axis.x ) + ( p_axis.y * p_axis.y ) ) + ( p_axis.z * p_axis.z ) ));
		double __temp_stmt256441 = 0.0;
		{
			double p_a = ( l - 1.0 );
			__temp_stmt256441 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
		}
		
		if (( __temp_stmt256441 > 0.0001 )) 
		{
			p_axis.Normalize();
		}
		
		double s = java.lang.Math.sin(p_angle);
		return new haxor.math.Quaternion(((java.lang.Object) (( p_axis.x * s )) ), ((java.lang.Object) (( p_axis.y * s )) ), ((java.lang.Object) (( p_axis.z * s )) ), ((java.lang.Object) (java.lang.Math.cos(p_angle)) ));
	}
	
	
	public static   haxor.math.Quaternion LookAt(haxor.math.Vector3 p_eye, haxor.math.Vector3 p_at, haxor.math.Vector3 p_up, haxor.math.Quaternion p_result)
	{
		haxor.math.Matrix4 __temp_stmt256443 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt256443 = _this.m_m4.__get(_this.m_nq = ( (( _this.m_nm4 + 1 )) % _this.m_m4.length ));
		}
		
		haxor.math.Matrix4 __temp_stmt256442 = haxor.math.Matrix4.LookAt(p_eye, p_at, p_up, __temp_stmt256443);
		return haxor.math.Quaternion.FromMatrix4(__temp_stmt256442, p_result);
	}
	
	
	public static   haxor.math.Quaternion LookRotation(haxor.math.Vector3 p_forward, haxor.math.Vector3 p_up)
	{
		{
			haxor.math.Matrix4 _this = null;
			{
				haxor.math.Matrix4 p_result = null;
				{
					haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
					p_result = _this1.m_m4.__get(_this1.m_nq = ( (( _this1.m_nm4 + 1 )) % _this1.m_m4.length ));
				}
				
				haxor.math.Vector3 __temp_stmt256445 = null;
				{
					haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
					__temp_stmt256445 = _this2.m_v3.__get(_this2.m_nv3 = ( (( _this2.m_nv3 + 1 )) % _this2.m_v3.length ));
				}
				
				haxor.math.Vector3 __temp_stmt256444 = __temp_stmt256445.Set(0, 0, 0);
				_this = haxor.math.Matrix4.LookAt(__temp_stmt256444, p_forward, p_up, p_result);
			}
			
			haxor.math.Matrix4 __temp_stmt256448 = null;
			{
				haxor.context.DataContext _this3 = haxor.context.EngineContext.data;
				__temp_stmt256448 = _this3.m_m4.__get(_this3.m_nq = ( (( _this3.m_nm4 + 1 )) % _this3.m_m4.length ));
			}
			
			haxor.math.Matrix4 __temp_stmt256447 = __temp_stmt256448.SetMatrix4(_this);
			haxor.math.Matrix4 __temp_stmt256446 = __temp_stmt256447.ToRotation();
			return haxor.math.Quaternion.FromMatrix4(__temp_stmt256446, null);
		}
		
	}
	
	
	public static   haxor.math.Quaternion Parse(java.lang.String p_data, java.lang.String p_delimiter)
	{
		if (( p_delimiter == null )) 
		{
			p_delimiter = " ";
		}
		
		haxe.root.Array<java.lang.String> tk = haxe.lang.StringExt.split(p_data, p_delimiter);
		return new haxor.math.Quaternion(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1.0) )).Set(haxe.root.Std.parseFloat(tk.__get(0).trim()), haxe.root.Std.parseFloat(tk.__get(1).trim()), haxe.root.Std.parseFloat(tk.__get(2).trim()), haxe.root.Std.parseFloat(tk.__get(3).trim()));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.math.Quaternion(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.math.Quaternion(((java.lang.Object) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ), ((java.lang.Object) (arr.__get(2)) ), ((java.lang.Object) (arr.__get(3)) ));
	}
	
	
	
	
	public final   haxor.math.Matrix4 get_matrix()
	{
		return haxor.math.Matrix4.FromQuaternion(this, null);
	}
	
	
	public final   haxor.math.Matrix4 set_matrix(haxor.math.Matrix4 v)
	{
		haxor.math.Quaternion.FromMatrix4(v, this);
		return v;
	}
	
	
	
	
	public   haxor.math.Vector3 get_euler()
	{
		return haxor.math.Quaternion.ToEuler(this, null);
	}
	
	
	public   haxor.math.Vector3 set_euler(haxor.math.Vector3 v)
	{
		haxor.math.Quaternion.FromEuler(v, this);
		return v;
	}
	
	
	public  haxor.math.Quaternion clone;
	
	public final   haxor.math.Quaternion get_clone()
	{
		return new haxor.math.Quaternion(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ), ((java.lang.Object) (this.w) ));
	}
	
	
	public  haxor.math.Vector4 xyzw;
	
	public final   haxor.math.Vector4 get_xyzw()
	{
		return new haxor.math.Vector4(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ), ((java.lang.Object) (this.w) ));
	}
	
	
	public  double length;
	
	public final   double get_length()
	{
		return java.lang.Math.sqrt(( ( ( ( this.x * this.x ) + ( this.y * this.y ) ) + ( this.z * this.z ) ) + ( this.w * this.w ) ));
	}
	
	
	public  haxor.math.Quaternion normalized;
	
	public final   haxor.math.Quaternion get_normalized()
	{
		return new haxor.math.Quaternion(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ), ((java.lang.Object) (this.w) )).Normalize();
	}
	
	
	public  double x;
	
	public  double y;
	
	public  double z;
	
	public  double w;
	
	public   haxor.math.Quaternion Set(java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_z, java.lang.Object p_w)
	{
		double __temp_p_w255594 = ( (( p_w == null )) ? (((double) (1.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_w)) )) );
		double __temp_p_z255593 = ( (( p_z == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_z)) )) );
		double __temp_p_y255592 = ( (( p_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_y)) )) );
		double __temp_p_x255591 = ( (( p_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_x)) )) );
		this.x = __temp_p_x255591;
		this.y = __temp_p_y255592;
		this.z = __temp_p_z255593;
		this.w = __temp_p_w255594;
		return this;
	}
	
	
	public   haxor.math.Quaternion SetQuaternion(haxor.math.Quaternion p_q)
	{
		this.x = p_q.x;
		this.y = p_q.y;
		this.z = p_q.z;
		this.w = p_q.w;
		return this;
	}
	
	
	public   haxor.math.Quaternion Normalize()
	{
		double l = java.lang.Math.sqrt(( ( ( ( this.x * this.x ) + ( this.y * this.y ) ) + ( this.z * this.z ) ) + ( this.w * this.w ) ));
		if (( l <= 0 )) 
		{
			this.x = this.y = this.z = 0.0;
			this.w = 1.0;
			return this;
		}
		
		this.x *= l = ( 1.0 / l );
		this.y *= l;
		this.z *= l;
		this.w *= l;
		return this;
	}
	
	
	public  haxor.math.Quaternion conjugate;
	
	public final   haxor.math.Quaternion get_conjugate()
	{
		return new haxor.math.Quaternion(((java.lang.Object) ( - (this.x) ) ), ((java.lang.Object) ( - (this.y) ) ), ((java.lang.Object) ( - (this.z) ) ), ((java.lang.Object) (this.w) ));
	}
	
	
	public  haxor.math.Quaternion inverse;
	
	public final   haxor.math.Quaternion get_inverse()
	{
		return haxor.math.Quaternion.Inverse(this, null);
	}
	
	
	public   haxor.math.Quaternion Invert()
	{
		this.x =  - (this.x) ;
		this.y =  - (this.y) ;
		this.z =  - (this.z) ;
		this.w =  - (this.w) ;
		return this;
	}
	
	
	public   haxor.math.Quaternion Scale(double p_v)
	{
		this.x *= p_v;
		this.y *= p_v;
		this.z *= p_v;
		this.w *= p_v;
		return this;
	}
	
	
	public   haxor.math.Quaternion Multiply(haxor.math.Quaternion p_v, java.lang.Object p_normalize)
	{
		boolean __temp_p_normalize255595 = ( (( p_normalize == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_normalize)) );
		double vx = ( ( ( ( this.w * p_v.x ) + ( this.x * p_v.w ) ) + ( this.y * p_v.z ) ) - ( this.z * p_v.y ) );
		double vy = ( ( ( ( this.w * p_v.y ) + ( this.y * p_v.w ) ) + ( this.z * p_v.x ) ) - ( this.x * p_v.z ) );
		double vz = ( ( ( ( this.w * p_v.z ) + ( this.z * p_v.w ) ) + ( this.x * p_v.y ) ) - ( this.y * p_v.x ) );
		double vw = ( ( ( ( this.w * p_v.w ) - ( this.x * p_v.x ) ) - ( this.y * p_v.y ) ) - ( this.z * p_v.z ) );
		this.x = vx;
		this.y = vy;
		this.z = vz;
		this.w = vw;
		if (__temp_p_normalize255595) 
		{
			return this.Normalize();
		}
		 else 
		{
			return this;
		}
		
	}
	
	
	public   haxor.math.Vector3 Transform(haxor.math.Vector3 p_v)
	{
		double l = java.lang.Math.sqrt(( ( ( p_v.x * p_v.x ) + ( p_v.y * p_v.y ) ) + ( p_v.z * p_v.z ) ));
		double nl = 0.0;
		if (( l <= 0.0 )) 
		{
			nl = 0.0;
		}
		 else 
		{
			nl = ( 1.0 / l );
		}
		
		p_v.x *= nl;
		p_v.y *= nl;
		p_v.z *= nl;
		haxor.math.Quaternion __temp_stmt256416 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt256416 = _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
		}
		
		haxor.math.Quaternion qv = __temp_stmt256416.Set(p_v.x, p_v.y, p_v.z, 0);
		haxor.math.Quaternion __temp_stmt256417 = null;
		{
			haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
			__temp_stmt256417 = _this1.m_q.__get(_this1.m_nq = ( (( _this1.m_nq + 1 )) % _this1.m_q.length ));
		}
		
		haxor.math.Quaternion a = __temp_stmt256417.SetQuaternion(this);
		haxor.math.Quaternion __temp_stmt256418 = null;
		{
			haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
			__temp_stmt256418 = _this2.m_q.__get(_this2.m_nq = ( (( _this2.m_nq + 1 )) % _this2.m_q.length ));
		}
		
		haxor.math.Quaternion c = __temp_stmt256418.Set( - (this.x) ,  - (this.y) ,  - (this.z) , this.w);
		a.Multiply(qv.Multiply(c, null), null);
		p_v.x = ( a.x * l );
		p_v.y = ( a.y * l );
		p_v.z = ( a.z * l );
		return p_v;
	}
	
	
	public final   haxor.math.Quaternion Delta(haxor.math.Quaternion p_q)
	{
		haxor.math.Quaternion __temp_stmt256420 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt256420 = _this.m_q.__get(_this.m_nq = ( (( _this.m_nq + 1 )) % _this.m_q.length ));
		}
		
		haxor.math.Quaternion __temp_stmt256419 = haxor.math.Quaternion.DeltaRotation(this, p_q, __temp_stmt256420);
		return this.SetQuaternion(__temp_stmt256419);
	}
	
	
	public   haxor.math.Quaternion SetAxisAngle(haxor.math.Vector3 p_axis, double p_angle)
	{
		p_angle = ( ( p_angle * 0.5 ) * 0.01745329251994329576923690768489 );
		double l = java.lang.Math.sqrt(( ( ( p_axis.x * p_axis.x ) + ( p_axis.y * p_axis.y ) ) + ( p_axis.z * p_axis.z ) ));
		double __temp_stmt256421 = 0.0;
		{
			double p_a = ( l - 1.0 );
			__temp_stmt256421 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
		}
		
		if (( __temp_stmt256421 > 0.0001 )) 
		{
			p_axis.Normalize();
		}
		
		double s = java.lang.Math.sin(p_angle);
		return this.Set(( p_axis.x * s ), ( p_axis.y * s ), ( p_axis.z * s ), java.lang.Math.cos(p_angle));
	}
	
	
	public   haxe.root.Array<java.lang.Object> ToArray()
	{
		return new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ), ((java.lang.Object) (this.w) )});
	}
	
	
	public   java.lang.String ToString(java.lang.Object p_places)
	{
		int __temp_p_places255596 = ( (( p_places == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_places)) )) );
		double __temp_stmt256422 = 0.0;
		{
			double d = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places255596) ));
			double __temp_stmt256423 = 0.0;
			{
				double p_v = ( this.x * d );
				__temp_stmt256423 = ((double) (((int) (( p_v + (( (( p_v < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt256422 = ( __temp_stmt256423 / d );
		}
		
		double __temp_stmt256424 = 0.0;
		{
			double d1 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places255596) ));
			double __temp_stmt256425 = 0.0;
			{
				double p_v1 = ( this.y * d1 );
				__temp_stmt256425 = ((double) (((int) (( p_v1 + (( (( p_v1 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt256424 = ( __temp_stmt256425 / d1 );
		}
		
		double __temp_stmt256426 = 0.0;
		{
			double d2 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places255596) ));
			double __temp_stmt256427 = 0.0;
			{
				double p_v2 = ( this.z * d2 );
				__temp_stmt256427 = ((double) (((int) (( p_v2 + (( (( p_v2 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt256426 = ( __temp_stmt256427 / d2 );
		}
		
		double __temp_stmt256428 = 0.0;
		{
			double d3 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places255596) ));
			double __temp_stmt256429 = 0.0;
			{
				double p_v3 = ( this.w * d3 );
				__temp_stmt256429 = ((double) (((int) (( p_v3 + (( (( p_v3 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt256428 = ( __temp_stmt256429 / d3 );
		}
		
		return ( ( ( ( ( ( ( ( "[" + haxe.lang.Runtime.toString(__temp_stmt256422) ) + "," ) + haxe.lang.Runtime.toString(__temp_stmt256424) ) + "," ) + haxe.lang.Runtime.toString(__temp_stmt256426) ) + "," ) + haxe.lang.Runtime.toString(__temp_stmt256428) ) + "]" );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256430 = true;
			switch (field.hashCode())
			{
				case 119:
				{
					if (field.equals("w")) 
					{
						__temp_executeDef256430 = false;
						this.w = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef256430 = false;
						this.length = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef256430 = false;
						this.z = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256430 = false;
						this.x = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef256430 = false;
						this.y = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256430) 
			{
				return super.__hx_setField_f(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256431 = true;
			switch (field.hashCode())
			{
				case 1959910192:
				{
					if (field.equals("inverse")) 
					{
						__temp_executeDef256431 = false;
						this.inverse = ((haxor.math.Quaternion) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1081239615:
				{
					if (field.equals("matrix")) 
					{
						__temp_executeDef256431 = false;
						this.set_matrix(((haxor.math.Matrix4) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -678849384:
				{
					if (field.equals("conjugate")) 
					{
						__temp_executeDef256431 = false;
						this.conjugate = ((haxor.math.Quaternion) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 96868201:
				{
					if (field.equals("euler")) 
					{
						__temp_executeDef256431 = false;
						this.set_euler(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 119:
				{
					if (field.equals("w")) 
					{
						__temp_executeDef256431 = false;
						this.w = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef256431 = false;
						this.clone = ((haxor.math.Quaternion) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef256431 = false;
						this.z = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3695102:
				{
					if (field.equals("xyzw")) 
					{
						__temp_executeDef256431 = false;
						this.xyzw = ((haxor.math.Vector4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef256431 = false;
						this.y = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef256431 = false;
						this.length = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256431 = false;
						this.x = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1255046409:
				{
					if (field.equals("normalized")) 
					{
						__temp_executeDef256431 = false;
						this.normalized = ((haxor.math.Quaternion) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256431) 
			{
				return super.__hx_setField(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256432 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case -1081239615:
				{
					if (field.equals("matrix")) 
					{
						__temp_executeDef256432 = false;
						return this.get_matrix();
					}
					
					break;
				}
				
				
				case 482271358:
				{
					if (field.equals("ToArray")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToArray"))) );
					}
					
					break;
				}
				
				
				case 999438538:
				{
					if (field.equals("get_matrix")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_matrix"))) );
					}
					
					break;
				}
				
				
				case -1082473584:
				{
					if (field.equals("SetAxisAngle")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetAxisAngle"))) );
					}
					
					break;
				}
				
				
				case -1358723522:
				{
					if (field.equals("set_matrix")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_matrix"))) );
					}
					
					break;
				}
				
				
				case 65915800:
				{
					if (field.equals("Delta")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Delta"))) );
					}
					
					break;
				}
				
				
				case 96868201:
				{
					if (field.equals("euler")) 
					{
						__temp_executeDef256432 = false;
						return this.get_euler();
					}
					
					break;
				}
				
				
				case -1238332596:
				{
					if (field.equals("Transform")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Transform"))) );
					}
					
					break;
				}
				
				
				case 1133818176:
				{
					if (field.equals("get_euler")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_euler"))) );
					}
					
					break;
				}
				
				
				case 718473796:
				{
					if (field.equals("Multiply")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Multiply"))) );
					}
					
					break;
				}
				
				
				case 919201100:
				{
					if (field.equals("set_euler")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_euler"))) );
					}
					
					break;
				}
				
				
				case 79698218:
				{
					if (field.equals("Scale")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Scale"))) );
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef256432 = false;
						if (handleProperties) 
						{
							return this.get_clone();
						}
						 else 
						{
							return this.clone;
						}
						
					}
					
					break;
				}
				
				
				case -2099835914:
				{
					if (field.equals("Invert")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Invert"))) );
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_clone"))) );
					}
					
					break;
				}
				
				
				case 2036423495:
				{
					if (field.equals("get_inverse")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_inverse"))) );
					}
					
					break;
				}
				
				
				case 3695102:
				{
					if (field.equals("xyzw")) 
					{
						__temp_executeDef256432 = false;
						if (handleProperties) 
						{
							return this.get_xyzw();
						}
						 else 
						{
							return this.xyzw;
						}
						
					}
					
					break;
				}
				
				
				case 1959910192:
				{
					if (field.equals("inverse")) 
					{
						__temp_executeDef256432 = false;
						if (handleProperties) 
						{
							return this.get_inverse();
						}
						 else 
						{
							return this.inverse;
						}
						
					}
					
					break;
				}
				
				
				case 1976807751:
				{
					if (field.equals("get_xyzw")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_xyzw"))) );
					}
					
					break;
				}
				
				
				case -164009233:
				{
					if (field.equals("get_conjugate")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_conjugate"))) );
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef256432 = false;
						if (handleProperties) 
						{
							return this.get_length();
						}
						 else 
						{
							return this.length;
						}
						
					}
					
					break;
				}
				
				
				case -678849384:
				{
					if (field.equals("conjugate")) 
					{
						__temp_executeDef256432 = false;
						if (handleProperties) 
						{
							return this.get_conjugate();
						}
						 else 
						{
							return this.conjugate;
						}
						
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
				case -2054390035:
				{
					if (field.equals("Normalize")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Normalize"))) );
					}
					
					break;
				}
				
				
				case -1255046409:
				{
					if (field.equals("normalized")) 
					{
						__temp_executeDef256432 = false;
						if (handleProperties) 
						{
							return this.get_normalized();
						}
						 else 
						{
							return this.normalized;
						}
						
					}
					
					break;
				}
				
				
				case -349290240:
				{
					if (field.equals("SetQuaternion")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetQuaternion"))) );
					}
					
					break;
				}
				
				
				case 1820096384:
				{
					if (field.equals("get_normalized")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_normalized"))) );
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef256432 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256432 = false;
						return this.x;
					}
					
					break;
				}
				
				
				case 119:
				{
					if (field.equals("w")) 
					{
						__temp_executeDef256432 = false;
						return this.w;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef256432 = false;
						return this.y;
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef256432 = false;
						return this.z;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256432) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256433 = true;
			switch (field.hashCode())
			{
				case 119:
				{
					if (field.equals("w")) 
					{
						__temp_executeDef256433 = false;
						return this.w;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef256433 = false;
						if (handleProperties) 
						{
							return this.get_length();
						}
						 else 
						{
							return this.length;
						}
						
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef256433 = false;
						return this.z;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256433 = false;
						return this.x;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef256433 = false;
						return this.y;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256433) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			boolean __temp_executeDef256434 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef256434 = false;
						return this.ToString(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case 999438538:
				{
					if (field.equals("get_matrix")) 
					{
						__temp_executeDef256434 = false;
						return this.get_matrix();
					}
					
					break;
				}
				
				
				case 482271358:
				{
					if (field.equals("ToArray")) 
					{
						__temp_executeDef256434 = false;
						return this.ToArray();
					}
					
					break;
				}
				
				
				case -1358723522:
				{
					if (field.equals("set_matrix")) 
					{
						__temp_executeDef256434 = false;
						return this.set_matrix(((haxor.math.Matrix4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1082473584:
				{
					if (field.equals("SetAxisAngle")) 
					{
						__temp_executeDef256434 = false;
						return this.SetAxisAngle(((haxor.math.Vector3) (dynargs.__get(0)) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 1133818176:
				{
					if (field.equals("get_euler")) 
					{
						__temp_executeDef256434 = false;
						return this.get_euler();
					}
					
					break;
				}
				
				
				case 65915800:
				{
					if (field.equals("Delta")) 
					{
						__temp_executeDef256434 = false;
						return this.Delta(((haxor.math.Quaternion) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 919201100:
				{
					if (field.equals("set_euler")) 
					{
						__temp_executeDef256434 = false;
						return this.set_euler(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1238332596:
				{
					if (field.equals("Transform")) 
					{
						__temp_executeDef256434 = false;
						return this.Transform(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef256434 = false;
						return this.get_clone();
					}
					
					break;
				}
				
				
				case 718473796:
				{
					if (field.equals("Multiply")) 
					{
						__temp_executeDef256434 = false;
						return this.Multiply(((haxor.math.Quaternion) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 1976807751:
				{
					if (field.equals("get_xyzw")) 
					{
						__temp_executeDef256434 = false;
						return this.get_xyzw();
					}
					
					break;
				}
				
				
				case 79698218:
				{
					if (field.equals("Scale")) 
					{
						__temp_executeDef256434 = false;
						return this.Scale(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef256434 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case -2099835914:
				{
					if (field.equals("Invert")) 
					{
						__temp_executeDef256434 = false;
						return this.Invert();
					}
					
					break;
				}
				
				
				case 1820096384:
				{
					if (field.equals("get_normalized")) 
					{
						__temp_executeDef256434 = false;
						return this.get_normalized();
					}
					
					break;
				}
				
				
				case 2036423495:
				{
					if (field.equals("get_inverse")) 
					{
						__temp_executeDef256434 = false;
						return this.get_inverse();
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef256434 = false;
						return this.Set(dynargs.__get(0), dynargs.__get(1), dynargs.__get(2), dynargs.__get(3));
					}
					
					break;
				}
				
				
				case -164009233:
				{
					if (field.equals("get_conjugate")) 
					{
						__temp_executeDef256434 = false;
						return this.get_conjugate();
					}
					
					break;
				}
				
				
				case -349290240:
				{
					if (field.equals("SetQuaternion")) 
					{
						__temp_executeDef256434 = false;
						return this.SetQuaternion(((haxor.math.Quaternion) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -2054390035:
				{
					if (field.equals("Normalize")) 
					{
						__temp_executeDef256434 = false;
						return this.Normalize();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256434) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("inverse");
		baseArr.push("conjugate");
		baseArr.push("w");
		baseArr.push("z");
		baseArr.push("y");
		baseArr.push("x");
		baseArr.push("normalized");
		baseArr.push("length");
		baseArr.push("xyzw");
		baseArr.push("clone");
		baseArr.push("euler");
		baseArr.push("matrix");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


