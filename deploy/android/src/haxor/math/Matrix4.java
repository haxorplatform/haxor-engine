package haxor.math;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Matrix4 extends haxe.lang.HxObject
{
	public    Matrix4(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Matrix4(java.lang.Object p_m00, java.lang.Object p_m01, java.lang.Object p_m02, java.lang.Object p_m03, java.lang.Object p_m10, java.lang.Object p_m11, java.lang.Object p_m12, java.lang.Object p_m13, java.lang.Object p_m20, java.lang.Object p_m21, java.lang.Object p_m22, java.lang.Object p_m23, java.lang.Object p_m30, java.lang.Object p_m31, java.lang.Object p_m32, java.lang.Object p_m33)
	{
		haxor.math.Matrix4.__hx_ctor_haxor_math_Matrix4(this, p_m00, p_m01, p_m02, p_m03, p_m10, p_m11, p_m12, p_m13, p_m20, p_m21, p_m22, p_m23, p_m30, p_m31, p_m32, p_m33);
	}
	
	
	public static   void __hx_ctor_haxor_math_Matrix4(haxor.math.Matrix4 __temp_me151531, java.lang.Object p_m00, java.lang.Object p_m01, java.lang.Object p_m02, java.lang.Object p_m03, java.lang.Object p_m10, java.lang.Object p_m11, java.lang.Object p_m12, java.lang.Object p_m13, java.lang.Object p_m20, java.lang.Object p_m21, java.lang.Object p_m22, java.lang.Object p_m23, java.lang.Object p_m30, java.lang.Object p_m31, java.lang.Object p_m32, java.lang.Object p_m33)
	{
		double __temp_p_m33151530 = ( (( p_m33 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m33)) )) );
		double __temp_p_m32151529 = ( (( p_m32 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m32)) )) );
		double __temp_p_m31151528 = ( (( p_m31 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m31)) )) );
		double __temp_p_m30151527 = ( (( p_m30 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m30)) )) );
		double __temp_p_m23151526 = ( (( p_m23 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m23)) )) );
		double __temp_p_m22151525 = ( (( p_m22 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m22)) )) );
		double __temp_p_m21151524 = ( (( p_m21 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m21)) )) );
		double __temp_p_m20151523 = ( (( p_m20 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m20)) )) );
		double __temp_p_m13151522 = ( (( p_m13 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m13)) )) );
		double __temp_p_m12151521 = ( (( p_m12 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m12)) )) );
		double __temp_p_m11151520 = ( (( p_m11 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m11)) )) );
		double __temp_p_m10151519 = ( (( p_m10 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m10)) )) );
		double __temp_p_m03151518 = ( (( p_m03 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m03)) )) );
		double __temp_p_m02151517 = ( (( p_m02 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m02)) )) );
		double __temp_p_m01151516 = ( (( p_m01 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m01)) )) );
		double __temp_p_m00151515 = ( (( p_m00 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m00)) )) );
		__temp_me151531.m00 = __temp_p_m00151515;
		__temp_me151531.m01 = __temp_p_m01151516;
		__temp_me151531.m02 = __temp_p_m02151517;
		__temp_me151531.m03 = __temp_p_m03151518;
		__temp_me151531.m10 = __temp_p_m10151519;
		__temp_me151531.m11 = __temp_p_m11151520;
		__temp_me151531.m12 = __temp_p_m12151521;
		__temp_me151531.m13 = __temp_p_m13151522;
		__temp_me151531.m20 = __temp_p_m20151523;
		__temp_me151531.m21 = __temp_p_m21151524;
		__temp_me151531.m22 = __temp_p_m22151525;
		__temp_me151531.m23 = __temp_p_m23151526;
		__temp_me151531.m30 = __temp_p_m30151527;
		__temp_me151531.m31 = __temp_p_m31151528;
		__temp_me151531.m32 = __temp_p_m32151529;
		__temp_me151531.m33 = __temp_p_m33151530;
	}
	
	
	public static  haxor.math.Matrix4 temp;
	
	public static   haxor.math.Matrix4 get_temp()
	{
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			return _this.m_m4.__get(_this.m_nq = ( (( _this.m_nm4 + 1 )) % _this.m_m4.length ));
		}
		
	}
	
	
	public static  haxor.math.Matrix4 identity;
	
	public static   haxor.math.Matrix4 get_identity()
	{
		return new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
	}
	
	
	public static   haxor.math.Matrix4 FromQuaternion(haxor.math.Quaternion p_quaternion, haxor.math.Matrix4 p_result)
	{
		haxor.math.Matrix4 m = null;
		if (( p_result == null )) 
		{
			m = new haxor.math.Matrix4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			m = p_result;
		}
		
		haxor.math.Quaternion q = p_quaternion;
		double x2 = ( q.x * q.x );
		double y2 = ( q.y * q.y );
		double z2 = ( q.z * q.z );
		double xy = ( q.x * q.y );
		double xz = ( q.x * q.z );
		double yz = ( q.y * q.z );
		double xw = ( q.w * q.x );
		double yw = ( q.w * q.y );
		double zw = ( q.w * q.z );
		m.m00 = ( 1.0 - ( 2.0 * (( y2 + z2 )) ) );
		m.m01 = ( 2.0 * (( xy - zw )) );
		m.m02 = ( 2.0 * (( xz + yw )) );
		m.m10 = ( 2.0 * (( xy + zw )) );
		m.m11 = ( 1.0 - ( 2.0 * (( x2 + z2 )) ) );
		m.m12 = ( 2.0 * (( yz - xw )) );
		m.m20 = ( 2.0 * (( xz - yw )) );
		m.m21 = ( 2.0 * (( yz + xw )) );
		m.m22 = ( 1.0 - ( 2.0 * (( x2 + y2 )) ) );
		m.m30 = m.m31 = m.m32 = 0.0;
		m.m33 = 1.0;
		return m;
	}
	
	
	public static   haxor.math.Matrix4 FromArray(haxe.root.Array<java.lang.Object> p_array, haxor.math.Matrix4 p_result)
	{
		haxor.math.Matrix4 res = null;
		if (( p_result == null )) 
		{
			res = new haxor.math.Matrix4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			res = p_result;
		}
		
		{
			int _g1 = 0;
			int _g = p_array.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				res.SetIndex(i, ((double) (haxe.lang.Runtime.toDouble(p_array.__get(i))) ));
			}
			
		}
		
		return res;
	}
	
	
	public static   haxor.math.Matrix4 TRS(haxor.math.Vector3 p_position, haxor.math.Quaternion p_rotation, haxor.math.Vector3 p_scale, haxor.math.Matrix4 p_result)
	{
		double sx = 0.0;
		if (( p_scale == null )) 
		{
			sx = 1.0;
		}
		 else 
		{
			sx = p_scale.x;
		}
		
		double sy = 0.0;
		if (( p_scale == null )) 
		{
			sy = 1.0;
		}
		 else 
		{
			sy = p_scale.y;
		}
		
		double sz = 0.0;
		if (( p_scale == null )) 
		{
			sz = 1.0;
		}
		 else 
		{
			sz = p_scale.z;
		}
		
		double px = p_position.x;
		double py = p_position.y;
		double pz = p_position.z;
		haxor.math.Matrix4 r = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			r = _this.m_m4.__get(_this.m_nq = ( (( _this.m_nm4 + 1 )) % _this.m_m4.length ));
		}
		
		haxor.math.Matrix4.FromQuaternion(p_rotation, r);
		haxor.math.Matrix4 l = null;
		if (( p_result == null )) 
		{
			l = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		}
		 else 
		{
			l = p_result;
		}
		
		l.m00 = ( r.m00 * sx );
		l.m01 = ( r.m01 * sy );
		l.m02 = ( r.m02 * sz );
		l.m03 = px;
		l.m10 = ( r.m10 * sx );
		l.m11 = ( r.m11 * sy );
		l.m12 = ( r.m12 * sz );
		l.m13 = py;
		l.m20 = ( r.m20 * sx );
		l.m21 = ( r.m21 * sy );
		l.m22 = ( r.m22 * sz );
		l.m23 = pz;
		l.m30 = l.m31 = l.m32 = 0.0;
		l.m33 = 1.0;
		return l;
	}
	
	
	public static   haxor.math.Matrix4 Frustum(double p_left, double p_right, double p_top, double p_bottom, double p_near, double p_far, haxor.math.Matrix4 p_result)
	{
		haxor.math.Matrix4 m = null;
		if (( p_result == null )) 
		{
			m = new haxor.math.Matrix4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			m = p_result;
		}
		
		double n2 = ( p_near * 2.0 );
		double rml = ( 1.0 / (( p_right - p_left )) );
		double tmb = ( 1.0 / (( p_top - p_bottom )) );
		double fmn = ( 1.0 / (( p_far - p_near )) );
		m.m00 = ( n2 * rml );
		m.m01 = 0.0;
		m.m02 = ( (( p_right + p_left )) * rml );
		m.m03 = 0.0;
		m.m10 = 0.0;
		m.m11 = ( n2 * tmb );
		m.m12 = ( (( p_top + p_bottom )) * tmb );
		m.m13 = 0.0;
		m.m20 = 0.0;
		m.m21 = 0.0;
		m.m22 = (  - ((( p_near + p_far )))  * fmn );
		m.m23 = ( (  - (n2)  * p_far ) * fmn );
		m.m30 = 0.0;
		m.m31 = 0.0;
		m.m32 = -1.0;
		m.m33 = ((double) (0) );
		return m;
	}
	
	
	public static   haxor.math.Matrix4 FrustumInverse(double p_left, double p_right, double p_top, double p_bottom, double p_near, double p_far, haxor.math.Matrix4 p_result)
	{
		haxor.math.Matrix4 m = null;
		if (( p_result == null )) 
		{
			m = new haxor.math.Matrix4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			m = p_result;
		}
		
		double n2 = ( p_near * 2.0 );
		double rml = ( p_right - p_left );
		double tmb = ( p_top - p_bottom );
		double fmn = ( p_far - p_near );
		m.m00 = ( rml / n2 );
		m.m01 = 0.0;
		m.m02 = 0.0;
		m.m03 = ( (( p_right + p_left )) / n2 );
		m.m10 = 0.0;
		m.m11 = ( tmb / n2 );
		m.m12 = 0.0;
		m.m13 = ( (( p_top + p_bottom )) / n2 );
		m.m20 = 0.0;
		m.m21 = 0.0;
		m.m22 = 0.0;
		m.m23 = -1.0;
		m.m30 = 0.0;
		m.m31 = 0.0;
		m.m32 = ( fmn / ((  - (n2)  * p_far )) );
		m.m33 = ( (( p_far + p_near )) / (( n2 * p_far )) );
		return m;
	}
	
	
	public static   haxor.math.Matrix4 Ortho(double p_left, double p_right, double p_top, double p_bottom, double p_near, double p_far, haxor.math.Matrix4 p_result)
	{
		haxor.math.Matrix4 m = null;
		if (( p_result == null )) 
		{
			m = new haxor.math.Matrix4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			m = p_result;
		}
		
		double n2 = ( p_near * 2.0 );
		double rml = ( 1.0 / (( p_right - p_left )) );
		double tmb = ( 1.0 / (( p_top - p_bottom )) );
		double fmn = ( 1.0 / (( p_far - p_near )) );
		m.m00 = ( 2.0 * rml );
		m.m01 = 0.0;
		m.m02 = 0.0;
		m.m03 = (  - ((( p_right + p_left )))  * rml );
		m.m10 = 0.0;
		m.m11 = ( 2.0 * tmb );
		m.m12 = 0.0;
		m.m13 = (  - ((( p_top + p_bottom )))  * tmb );
		m.m20 = 0.0;
		m.m21 = 0.0;
		m.m22 = ( -2. * fmn );
		m.m23 = (  - ((( p_far + p_near )))  * fmn );
		m.m30 = 0.0;
		m.m31 = 0.0;
		m.m32 = 0.0;
		m.m33 = 1.0;
		return m;
	}
	
	
	public static   haxor.math.Matrix4 OrthoInverse(double p_left, double p_right, double p_top, double p_bottom, double p_near, double p_far, haxor.math.Matrix4 p_result)
	{
		haxor.math.Matrix4 __temp_stmt152378 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt152378 = _this.m_m4.__get(_this.m_nq = ( (( _this.m_nm4 + 1 )) % _this.m_m4.length ));
		}
		
		haxor.math.Matrix4 m = __temp_stmt152378.SetOrtho(p_left, p_right, p_top, p_bottom, p_near, p_far);
		return haxor.math.Matrix4.GetInverseTransform(m, p_result);
	}
	
	
	public static   haxor.math.Matrix4 Perspective(double p_fov, double p_aspect, double p_near, double p_far, haxor.math.Matrix4 p_result)
	{
		double t = ( java.lang.Math.tan(( ( p_fov * 0.5 ) * 0.01745329251994329576923690768489 )) * p_near );
		double b =  - (t) ;
		double l = ( p_aspect * b );
		double r = ( p_aspect * t );
		{
			haxor.math.Matrix4 m = null;
			if (( p_result == null )) 
			{
				m = new haxor.math.Matrix4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
			}
			 else 
			{
				m = p_result;
			}
			
			double n2 = ( p_near * 2.0 );
			double rml = ( 1.0 / (( r - l )) );
			double tmb = ( 1.0 / (( t - b )) );
			double fmn = ( 1.0 / (( p_far - p_near )) );
			m.m00 = ( n2 * rml );
			m.m01 = 0.0;
			m.m02 = ( (( r + l )) * rml );
			m.m03 = 0.0;
			m.m10 = 0.0;
			m.m11 = ( n2 * tmb );
			m.m12 = ( (( t + b )) * tmb );
			m.m13 = 0.0;
			m.m20 = 0.0;
			m.m21 = 0.0;
			m.m22 = (  - ((( p_near + p_far )))  * fmn );
			m.m23 = ( (  - (n2)  * p_far ) * fmn );
			m.m30 = 0.0;
			m.m31 = 0.0;
			m.m32 = -1.0;
			m.m33 = ((double) (0) );
			return m;
		}
		
	}
	
	
	public static   haxor.math.Matrix4 PerspectiveInverse(double p_fov, double p_aspect, double p_near, double p_far, haxor.math.Matrix4 p_result)
	{
		double t = ( java.lang.Math.tan(( ( p_fov * 0.5 ) * 0.01745329251994329576923690768489 )) * p_near );
		double b =  - (t) ;
		double l = ( p_aspect * b );
		double r = ( p_aspect * t );
		{
			haxor.math.Matrix4 m = null;
			if (( p_result == null )) 
			{
				m = new haxor.math.Matrix4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
			}
			 else 
			{
				m = p_result;
			}
			
			double n2 = ( p_near * 2.0 );
			double rml = ( r - l );
			double tmb = ( t - b );
			double fmn = ( p_far - p_near );
			m.m00 = ( rml / n2 );
			m.m01 = 0.0;
			m.m02 = 0.0;
			m.m03 = ( (( r + l )) / n2 );
			m.m10 = 0.0;
			m.m11 = ( tmb / n2 );
			m.m12 = 0.0;
			m.m13 = ( (( t + b )) / n2 );
			m.m20 = 0.0;
			m.m21 = 0.0;
			m.m22 = 0.0;
			m.m23 = -1.0;
			m.m30 = 0.0;
			m.m31 = 0.0;
			m.m32 = ( fmn / ((  - (n2)  * p_far )) );
			m.m33 = ( (( p_far + p_near )) / (( n2 * p_far )) );
			return m;
		}
		
	}
	
	
	public static   haxor.math.Matrix4 GetRotation(haxor.math.Matrix4 p_matrix4, haxor.math.Matrix4 p_result)
	{
		haxor.math.Matrix4 m = null;
		if (( p_result == null )) 
		{
			m = new haxor.math.Matrix4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			m = p_result;
		}
		
		haxor.math.Vector3 tmp = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			tmp = _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
		}
		
		tmp.Set(m.m00, m.m01, m.m02).Normalize();
		m.m00 = tmp.x;
		m.m01 = tmp.y;
		m.m02 = tmp.z;
		m.m03 = 0.0;
		tmp.Set(m.m10, m.m11, m.m12).Normalize();
		m.m10 = tmp.x;
		m.m11 = tmp.y;
		m.m12 = tmp.z;
		m.m13 = 0.0;
		tmp.Set(m.m20, m.m21, m.m22).Normalize();
		m.m20 = tmp.x;
		m.m21 = tmp.y;
		m.m22 = tmp.z;
		m.m23 = 0.0;
		m.m30 = m.m31 = m.m32 = 0.0;
		m.m33 = 1.0;
		return m;
	}
	
	
	public static   haxor.math.Matrix4 GetInverseTransform(haxor.math.Matrix4 p_matrix, haxor.math.Matrix4 p_result)
	{
		haxor.math.Matrix4 result = null;
		if (( p_result == null )) 
		{
			result = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		}
		 else 
		{
			result = p_result;
		}
		
		haxor.math.Matrix4 m = p_matrix;
		double l0x = m.m00;
		double l0y = m.m01;
		double l0z = m.m02;
		double l0w = m.m03;
		double l1x = m.m10;
		double l1y = m.m11;
		double l1z = m.m12;
		double l1w = m.m13;
		double l2x = m.m20;
		double l2y = m.m21;
		double l2z = m.m22;
		double l2w = m.m23;
		double vl0 = java.lang.Math.sqrt(( ( ( l0x * l0x ) + ( l1x * l1x ) ) + ( l2x * l2x ) ));
		double vl1 = java.lang.Math.sqrt(( ( ( l0y * l0y ) + ( l1y * l1y ) ) + ( l2y * l2y ) ));
		double vl2 = java.lang.Math.sqrt(( ( ( l0z * l0z ) + ( l1z * l1z ) ) + ( l2z * l2z ) ));
		double sx = 0.0;
		if (( (( (( vl0 < 0 )) ? ( - (vl0) ) : (vl0) )) <= 0.0001 )) 
		{
			sx = 0.0;
		}
		 else 
		{
			sx = ( 1.0 / vl0 );
		}
		
		double sy = 0.0;
		if (( (( (( vl1 < 0 )) ? ( - (vl1) ) : (vl1) )) <= 0.0001 )) 
		{
			sy = 0.0;
		}
		 else 
		{
			sy = ( 1.0 / vl1 );
		}
		
		double sz = 0.0;
		if (( (( (( vl2 < 0 )) ? ( - (vl2) ) : (vl2) )) <= 0.0001 )) 
		{
			sz = 0.0;
		}
		 else 
		{
			sz = ( 1.0 / vl2 );
		}
		
		l0x *= sx;
		l0y *= sy;
		l0z *= sz;
		l1x *= sx;
		l1y *= sy;
		l1z *= sz;
		l2x *= sx;
		l2y *= sy;
		l2z *= sz;
		result.Set(( sx * l0x ), ( sx * l1x ), ( sx * l2x ), ( sx * (( ( ( l0x *  - (l0w)  ) + ( l1x *  - (l1w)  ) ) + ( l2x *  - (l2w)  ) )) ), ( sy * l0y ), ( sy * l1y ), ( sy * l2y ), ( sy * (( ( ( l0y *  - (l0w)  ) + ( l1y *  - (l1w)  ) ) + ( l2y *  - (l2w)  ) )) ), ( sz * l0z ), ( sz * l1z ), ( sz * l2z ), ( sz * (( ( ( l0z *  - (l0w)  ) + ( l1z *  - (l1w)  ) ) + ( l2z *  - (l2w)  ) )) ), 0, 0, 0, 1);
		return result;
	}
	
	
	public static   haxor.math.Matrix4 LookRotation(haxor.math.Vector3 p_forward, haxor.math.Vector3 p_up, haxor.math.Matrix4 p_result)
	{
		haxor.math.Vector3 __temp_stmt152380 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt152380 = _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
		}
		
		haxor.math.Vector3 __temp_stmt152379 = __temp_stmt152380.Set(0, 0, 0);
		return haxor.math.Matrix4.LookAt(__temp_stmt152379, p_forward, p_up, p_result);
	}
	
	
	public static   haxor.math.Matrix4 LookAt(haxor.math.Vector3 p_eye, haxor.math.Vector3 p_at, haxor.math.Vector3 p_up, haxor.math.Matrix4 p_result)
	{
		if (( p_result == null )) 
		{
			p_result = new haxor.math.Matrix4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			p_result = p_result;
		}
		
		if (( p_up == null )) 
		{
			haxor.math.Vector3 __temp_stmt152381 = null;
			{
				haxor.context.DataContext _this = haxor.context.EngineContext.data;
				__temp_stmt152381 = _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
			}
			
			p_up = __temp_stmt152381.Set(0, 1, 0);
		}
		 else 
		{
			p_up = p_up;
		}
		
		haxor.math.Vector3 __temp_stmt152384 = null;
		{
			haxor.context.DataContext _this1 = haxor.context.EngineContext.data;
			__temp_stmt152384 = _this1.m_v3.__get(_this1.m_nv3 = ( (( _this1.m_nv3 + 1 )) % _this1.m_v3.length ));
		}
		
		haxor.math.Vector3 __temp_stmt152383 = __temp_stmt152384.Set3(p_at);
		haxor.math.Vector3 __temp_stmt152382 = __temp_stmt152383.Sub(p_eye);
		haxor.math.Vector3 f = __temp_stmt152382.Normalize();
		haxor.math.Vector3 __temp_stmt152386 = null;
		{
			haxor.context.DataContext _this2 = haxor.context.EngineContext.data;
			__temp_stmt152386 = _this2.m_v3.__get(_this2.m_nv3 = ( (( _this2.m_nv3 + 1 )) % _this2.m_v3.length ));
		}
		
		haxor.math.Vector3 __temp_stmt152385 = haxor.math.Vector3.Cross(f, p_up, __temp_stmt152386);
		haxor.math.Vector3 s = __temp_stmt152385.Normalize();
		haxor.math.Vector3 __temp_stmt152387 = null;
		{
			haxor.context.DataContext _this3 = haxor.context.EngineContext.data;
			__temp_stmt152387 = _this3.m_v3.__get(_this3.m_nv3 = ( (( _this3.m_nv3 + 1 )) % _this3.m_v3.length ));
		}
		
		haxor.math.Vector3 u = haxor.math.Vector3.Cross(s, f, __temp_stmt152387);
		p_result.m00 = s.x;
		p_result.m10 = s.y;
		p_result.m20 = s.z;
		p_result.m01 = u.x;
		p_result.m11 = u.y;
		p_result.m21 = u.z;
		p_result.m02 =  - (f.x) ;
		p_result.m12 =  - (f.y) ;
		p_result.m22 =  - (f.z) ;
		p_result.m03 =  - ((( ( ( s.x * p_eye.x ) + ( s.y * p_eye.y ) ) + ( s.z * p_eye.z ) ))) ;
		p_result.m13 =  - ((( ( ( u.x * p_eye.x ) + ( u.y * p_eye.y ) ) + ( u.z * p_eye.z ) ))) ;
		p_result.m23 = ( ( ( f.x * p_eye.x ) + ( f.y * p_eye.y ) ) + ( f.z * p_eye.z ) );
		p_result.m30 = p_result.m31 = p_result.m32 = 0.0;
		p_result.m33 = 1.0;
		return p_result;
	}
	
	
	public static   haxor.math.Matrix4 Parse(java.lang.String p_data, java.lang.String p_delimiter)
	{
		if (( p_delimiter == null )) 
		{
			p_delimiter = " ";
		}
		
		haxe.root.Array<java.lang.String> tk = haxe.lang.StringExt.split(p_data, p_delimiter);
		haxor.math.Matrix4 res = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		{
			int _g1 = 0;
			int _g = tk.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				double n = haxe.root.Std.parseFloat(tk.__get(i).trim());
				res.SetIndex(i, n);
			}
			
		}
		
		return res;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.math.Matrix4(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.math.Matrix4(((java.lang.Object) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ), ((java.lang.Object) (arr.__get(2)) ), ((java.lang.Object) (arr.__get(3)) ), ((java.lang.Object) (arr.__get(4)) ), ((java.lang.Object) (arr.__get(5)) ), ((java.lang.Object) (arr.__get(6)) ), ((java.lang.Object) (arr.__get(7)) ), ((java.lang.Object) (arr.__get(8)) ), ((java.lang.Object) (arr.__get(9)) ), ((java.lang.Object) (arr.__get(10)) ), ((java.lang.Object) (arr.__get(11)) ), ((java.lang.Object) (arr.__get(12)) ), ((java.lang.Object) (arr.__get(13)) ), ((java.lang.Object) (arr.__get(14)) ), ((java.lang.Object) (arr.__get(15)) ));
	}
	
	
	
	
	public final   haxor.math.Matrix4 get_clone()
	{
		return new haxor.math.Matrix4(((java.lang.Object) (this.m00) ), ((java.lang.Object) (this.m01) ), ((java.lang.Object) (this.m02) ), ((java.lang.Object) (this.m03) ), ((java.lang.Object) (this.m10) ), ((java.lang.Object) (this.m11) ), ((java.lang.Object) (this.m12) ), ((java.lang.Object) (this.m13) ), ((java.lang.Object) (this.m20) ), ((java.lang.Object) (this.m21) ), ((java.lang.Object) (this.m22) ), ((java.lang.Object) (this.m23) ), ((java.lang.Object) (this.m30) ), ((java.lang.Object) (this.m31) ), ((java.lang.Object) (this.m32) ), ((java.lang.Object) (this.m33) ));
	}
	
	
	
	
	public final   haxor.math.Quaternion get_quaternion()
	{
		haxor.math.Matrix4 __temp_stmt152371 = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			__temp_stmt152371 = _this.m_m4.__get(_this.m_nq = ( (( _this.m_nm4 + 1 )) % _this.m_m4.length ));
		}
		
		haxor.math.Matrix4 __temp_stmt152370 = __temp_stmt152371.SetMatrix4(this);
		haxor.math.Matrix4 __temp_stmt152369 = __temp_stmt152370.ToRotation();
		return haxor.math.Quaternion.FromMatrix(__temp_stmt152369, null);
	}
	
	
	public final   haxor.math.Quaternion set_quaternion(haxor.math.Quaternion v)
	{
		haxor.math.Matrix4.FromQuaternion(v, this);
		return v;
	}
	
	
	
	
	public final   double get_trace()
	{
		return ( ( ( this.m00 + this.m11 ) + this.m22 ) + this.m33 );
	}
	
	
	public  haxor.math.Matrix4 rotation;
	
	public final   haxor.math.Matrix4 get_rotation()
	{
		return new haxor.math.Matrix4(((java.lang.Object) (this.m00) ), ((java.lang.Object) (this.m01) ), ((java.lang.Object) (this.m02) ), ((java.lang.Object) (this.m03) ), ((java.lang.Object) (this.m10) ), ((java.lang.Object) (this.m11) ), ((java.lang.Object) (this.m12) ), ((java.lang.Object) (this.m13) ), ((java.lang.Object) (this.m20) ), ((java.lang.Object) (this.m21) ), ((java.lang.Object) (this.m22) ), ((java.lang.Object) (this.m23) ), ((java.lang.Object) (this.m30) ), ((java.lang.Object) (this.m31) ), ((java.lang.Object) (this.m32) ), ((java.lang.Object) (this.m33) )).ToRotation();
	}
	
	
	public  haxor.math.Matrix4 scale;
	
	public final   haxor.math.Matrix4 get_scale()
	{
		double d0 = java.lang.Math.sqrt(( ( ( this.m00 * this.m00 ) + ( this.m10 * this.m10 ) ) + ( this.m20 * this.m20 ) ));
		double d1 = java.lang.Math.sqrt(( ( ( this.m01 * this.m01 ) + ( this.m11 * this.m11 ) ) + ( this.m21 * this.m21 ) ));
		double d2 = java.lang.Math.sqrt(( ( ( this.m02 * this.m02 ) + ( this.m12 * this.m12 ) ) + ( this.m22 * this.m22 ) ));
		return new haxor.math.Matrix4(((java.lang.Object) (d0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (d1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (d2) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
	}
	
	
	public  haxor.math.Matrix4 translation;
	
	public final   haxor.math.Matrix4 get_translation()
	{
		return new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (this.m03) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (this.m13) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (this.m23) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
	}
	
	
	public  haxor.math.Matrix4 inverseTransform;
	
	public   haxor.math.Matrix4 get_inverseTransform()
	{
		haxor.math.Matrix4 result = new haxor.math.Matrix4(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
		haxor.math.Vector3 l0 = new haxor.math.Vector3(((java.lang.Object) (this.m00) ), ((java.lang.Object) (this.m01) ), ((java.lang.Object) (this.m02) ));
		haxor.math.Vector3 l1 = new haxor.math.Vector3(((java.lang.Object) (this.m10) ), ((java.lang.Object) (this.m11) ), ((java.lang.Object) (this.m12) ));
		haxor.math.Vector3 l2 = new haxor.math.Vector3(((java.lang.Object) (this.m20) ), ((java.lang.Object) (this.m21) ), ((java.lang.Object) (this.m22) ));
		double vl0 = java.lang.Math.sqrt(( ( ( l0.x * l0.x ) + ( l0.y * l0.y ) ) + ( l0.z * l0.z ) ));
		double vl1 = java.lang.Math.sqrt(( ( ( l1.x * l1.x ) + ( l1.y * l1.y ) ) + ( l1.z * l1.z ) ));
		double vl2 = java.lang.Math.sqrt(( ( ( l2.x * l2.x ) + ( l2.y * l2.y ) ) + ( l2.z * l2.z ) ));
		double sx = 0.0;
		if (( (( (( vl0 < 0 )) ? ( - (vl0) ) : (vl0) )) <= 0.0001 )) 
		{
			sx = 0.0;
		}
		 else 
		{
			sx = ( 1.0 / vl0 );
		}
		
		double sy = 0.0;
		if (( (( (( vl1 < 0 )) ? ( - (vl1) ) : (vl1) )) <= 0.0001 )) 
		{
			sy = 0.0;
		}
		 else 
		{
			sy = ( 1.0 / vl1 );
		}
		
		double sz = 0.0;
		if (( (( (( vl2 < 0 )) ? ( - (vl2) ) : (vl2) )) <= 0.0001 )) 
		{
			sz = 0.0;
		}
		 else 
		{
			sz = ( 1.0 / vl2 );
		}
		
		l0.x *= sx;
		l0.y *= sx;
		l0.z *= sx;
		l1.x *= sy;
		l1.y *= sy;
		l1.z *= sy;
		l2.x *= sz;
		l2.y *= sz;
		l2.z *= sz;
		result.Set(( sx * l0.x ), ( sx * l1.x ), ( sx * l2.x ), ( sx * (( ( ( l0.x *  - (this.m03)  ) + ( l1.x *  - (this.m13)  ) ) + ( l2.x *  - (this.m23)  ) )) ), ( sy * l0.y ), ( sy * l1.y ), ( sy * l2.y ), ( sy * (( ( ( l0.y *  - (this.m03)  ) + ( l1.y *  - (this.m13)  ) ) + ( l2.y *  - (this.m23)  ) )) ), ( sz * l0.z ), ( sz * l1.z ), ( sz * l2.z ), ( sz * (( ( ( l0.z *  - (this.m03)  ) + ( l1.z *  - (this.m13)  ) ) + ( l2.z *  - (this.m23)  ) )) ), 0, 0, 0, 1);
		return result;
	}
	
	
	public  haxor.math.Matrix4 transposed;
	
	public   haxor.math.Matrix4 get_transposed()
	{
		return new haxor.math.Matrix4(((java.lang.Object) (this.m00) ), ((java.lang.Object) (this.m10) ), ((java.lang.Object) (this.m20) ), ((java.lang.Object) (this.m30) ), ((java.lang.Object) (this.m01) ), ((java.lang.Object) (this.m11) ), ((java.lang.Object) (this.m21) ), ((java.lang.Object) (this.m31) ), ((java.lang.Object) (this.m02) ), ((java.lang.Object) (this.m12) ), ((java.lang.Object) (this.m22) ), ((java.lang.Object) (this.m32) ), ((java.lang.Object) (this.m03) ), ((java.lang.Object) (this.m13) ), ((java.lang.Object) (this.m23) ), ((java.lang.Object) (this.m33) ));
	}
	
	
	public   haxe.root.Array<java.lang.Object> ToRowMajor()
	{
		return new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (this.m00) ), ((java.lang.Object) (this.m01) ), ((java.lang.Object) (this.m02) ), ((java.lang.Object) (this.m03) ), ((java.lang.Object) (this.m10) ), ((java.lang.Object) (this.m11) ), ((java.lang.Object) (this.m12) ), ((java.lang.Object) (this.m13) ), ((java.lang.Object) (this.m20) ), ((java.lang.Object) (this.m21) ), ((java.lang.Object) (this.m22) ), ((java.lang.Object) (this.m23) ), ((java.lang.Object) (this.m30) ), ((java.lang.Object) (this.m31) ), ((java.lang.Object) (this.m32) ), ((java.lang.Object) (this.m33) )});
	}
	
	
	public   haxe.root.Array<java.lang.Object> ToColumnMajor()
	{
		return new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (this.m00) ), ((java.lang.Object) (this.m10) ), ((java.lang.Object) (this.m20) ), ((java.lang.Object) (this.m30) ), ((java.lang.Object) (this.m01) ), ((java.lang.Object) (this.m11) ), ((java.lang.Object) (this.m21) ), ((java.lang.Object) (this.m31) ), ((java.lang.Object) (this.m02) ), ((java.lang.Object) (this.m12) ), ((java.lang.Object) (this.m22) ), ((java.lang.Object) (this.m32) ), ((java.lang.Object) (this.m03) ), ((java.lang.Object) (this.m13) ), ((java.lang.Object) (this.m23) ), ((java.lang.Object) (this.m33) )});
	}
	
	
	public  double m00;
	
	public  double m01;
	
	public  double m02;
	
	public  double m03;
	
	public  double m10;
	
	public  double m11;
	
	public  double m12;
	
	public  double m13;
	
	public  double m20;
	
	public  double m21;
	
	public  double m22;
	
	public  double m23;
	
	public  double m30;
	
	public  double m31;
	
	public  double m32;
	
	public  double m33;
	
	public   haxor.math.Vector4 GetLine(int p_index, haxor.math.Vector4 p_result)
	{
		if (( p_result == null )) 
		{
			p_result = new haxor.math.Vector4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			p_result = p_result;
		}
		
		return p_result.Set(this.GetRowCol(p_index, 0), this.GetRowCol(p_index, 1), this.GetRowCol(p_index, 2), this.GetRowCol(p_index, 3));
	}
	
	
	public final   void SetLine(int p_index, double p_x, double p_y, double p_z, double p_w)
	{
		switch (p_index)
		{
			case 0:
			{
				this.m00 = p_x;
				this.m01 = p_y;
				this.m02 = p_z;
				this.m03 = p_w;
				break;
			}
			
			
			case 1:
			{
				this.m10 = p_x;
				this.m11 = p_y;
				this.m12 = p_z;
				this.m13 = p_w;
				break;
			}
			
			
			case 2:
			{
				this.m20 = p_x;
				this.m21 = p_y;
				this.m22 = p_z;
				this.m23 = p_w;
				break;
			}
			
			
			case 3:
			{
				this.m30 = p_x;
				this.m31 = p_y;
				this.m32 = p_z;
				this.m33 = p_w;
				break;
			}
			
			
		}
		
	}
	
	
	public final   haxor.math.Vector4 GetColumn(int p_index, haxor.math.Vector4 p_result)
	{
		if (( p_result == null )) 
		{
			p_result = new haxor.math.Vector4(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			p_result = p_result;
		}
		
		return p_result.Set(this.GetRowCol(0, p_index), this.GetRowCol(1, p_index), this.GetRowCol(2, p_index), this.GetRowCol(3, p_index));
	}
	
	
	public final   void SetColumn(int p_index, double p_x, double p_y, double p_z, double p_w)
	{
		switch (p_index)
		{
			case 0:
			{
				this.m00 = p_x;
				this.m10 = p_y;
				this.m20 = p_z;
				this.m30 = p_w;
				break;
			}
			
			
			case 1:
			{
				this.m01 = p_x;
				this.m11 = p_y;
				this.m21 = p_z;
				this.m31 = p_w;
				break;
			}
			
			
			case 2:
			{
				this.m02 = p_x;
				this.m12 = p_y;
				this.m22 = p_z;
				this.m32 = p_w;
				break;
			}
			
			
			case 3:
			{
				this.m03 = p_x;
				this.m13 = p_y;
				this.m23 = p_z;
				this.m33 = p_w;
				break;
			}
			
			
		}
		
	}
	
	
	
	
	public final   haxor.math.Vector4 get_diagonalLR()
	{
		return new haxor.math.Vector4(((java.lang.Object) (this.m00) ), ((java.lang.Object) (this.m11) ), ((java.lang.Object) (this.m22) ), ((java.lang.Object) (this.m33) ));
	}
	
	
	public final   haxor.math.Vector4 set_diagonalLR(haxor.math.Vector4 v)
	{
		this.m00 = v.x;
		this.m11 = v.y;
		this.m22 = v.z;
		this.m33 = v.w;
		return v;
	}
	
	
	public final   haxor.math.Matrix4 SetIdentity()
	{
		return this.Set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	}
	
	
	public   haxor.math.Matrix4 Set(java.lang.Object p_m00, java.lang.Object p_m01, java.lang.Object p_m02, java.lang.Object p_m03, java.lang.Object p_m10, java.lang.Object p_m11, java.lang.Object p_m12, java.lang.Object p_m13, java.lang.Object p_m20, java.lang.Object p_m21, java.lang.Object p_m22, java.lang.Object p_m23, java.lang.Object p_m30, java.lang.Object p_m31, java.lang.Object p_m32, java.lang.Object p_m33)
	{
		double __temp_p_m33151512 = ( (( p_m33 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m33)) )) );
		double __temp_p_m32151511 = ( (( p_m32 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m32)) )) );
		double __temp_p_m31151510 = ( (( p_m31 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m31)) )) );
		double __temp_p_m30151509 = ( (( p_m30 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m30)) )) );
		double __temp_p_m23151508 = ( (( p_m23 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m23)) )) );
		double __temp_p_m22151507 = ( (( p_m22 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m22)) )) );
		double __temp_p_m21151506 = ( (( p_m21 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m21)) )) );
		double __temp_p_m20151505 = ( (( p_m20 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m20)) )) );
		double __temp_p_m13151504 = ( (( p_m13 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m13)) )) );
		double __temp_p_m12151503 = ( (( p_m12 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m12)) )) );
		double __temp_p_m11151502 = ( (( p_m11 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m11)) )) );
		double __temp_p_m10151501 = ( (( p_m10 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m10)) )) );
		double __temp_p_m03151500 = ( (( p_m03 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m03)) )) );
		double __temp_p_m02151499 = ( (( p_m02 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m02)) )) );
		double __temp_p_m01151498 = ( (( p_m01 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m01)) )) );
		double __temp_p_m00151497 = ( (( p_m00 == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_m00)) )) );
		this.m00 = __temp_p_m00151497;
		this.m01 = __temp_p_m01151498;
		this.m02 = __temp_p_m02151499;
		this.m03 = __temp_p_m03151500;
		this.m10 = __temp_p_m10151501;
		this.m11 = __temp_p_m11151502;
		this.m12 = __temp_p_m12151503;
		this.m13 = __temp_p_m13151504;
		this.m20 = __temp_p_m20151505;
		this.m21 = __temp_p_m21151506;
		this.m22 = __temp_p_m22151507;
		this.m23 = __temp_p_m23151508;
		this.m30 = __temp_p_m30151509;
		this.m31 = __temp_p_m31151510;
		this.m32 = __temp_p_m32151511;
		this.m33 = __temp_p_m33151512;
		return this;
	}
	
	
	public   haxor.math.Matrix4 SetMatrix4(haxor.math.Matrix4 p_matrix)
	{
		this.m00 = p_matrix.m00;
		this.m01 = p_matrix.m01;
		this.m02 = p_matrix.m02;
		this.m03 = p_matrix.m03;
		this.m10 = p_matrix.m10;
		this.m11 = p_matrix.m11;
		this.m12 = p_matrix.m12;
		this.m13 = p_matrix.m13;
		this.m20 = p_matrix.m20;
		this.m21 = p_matrix.m21;
		this.m22 = p_matrix.m22;
		this.m23 = p_matrix.m23;
		this.m30 = p_matrix.m30;
		this.m31 = p_matrix.m31;
		this.m32 = p_matrix.m32;
		this.m33 = p_matrix.m33;
		return this;
	}
	
	
	public   double GetIndex(int p_index)
	{
		switch (p_index)
		{
			case 0:
			{
				return this.m00;
			}
			
			
			case 1:
			{
				return this.m01;
			}
			
			
			case 2:
			{
				return this.m02;
			}
			
			
			case 3:
			{
				return this.m03;
			}
			
			
			case 4:
			{
				return this.m10;
			}
			
			
			case 5:
			{
				return this.m11;
			}
			
			
			case 6:
			{
				return this.m12;
			}
			
			
			case 7:
			{
				return this.m13;
			}
			
			
			case 8:
			{
				return this.m20;
			}
			
			
			case 9:
			{
				return this.m21;
			}
			
			
			case 10:
			{
				return this.m22;
			}
			
			
			case 11:
			{
				return this.m23;
			}
			
			
			case 12:
			{
				return this.m30;
			}
			
			
			case 13:
			{
				return this.m31;
			}
			
			
			case 14:
			{
				return this.m32;
			}
			
			
			case 15:
			{
				return this.m33;
			}
			
			
		}
		
		return ((double) (0) );
	}
	
	
	public   haxor.math.Matrix4 SetIndex(int p_index, double p_value)
	{
		switch (p_index)
		{
			case 0:
			{
				this.m00 = p_value;
				break;
			}
			
			
			case 1:
			{
				this.m01 = p_value;
				break;
			}
			
			
			case 2:
			{
				this.m02 = p_value;
				break;
			}
			
			
			case 3:
			{
				this.m03 = p_value;
				break;
			}
			
			
			case 4:
			{
				this.m10 = p_value;
				break;
			}
			
			
			case 5:
			{
				this.m11 = p_value;
				break;
			}
			
			
			case 6:
			{
				this.m12 = p_value;
				break;
			}
			
			
			case 7:
			{
				this.m13 = p_value;
				break;
			}
			
			
			case 8:
			{
				this.m20 = p_value;
				break;
			}
			
			
			case 9:
			{
				this.m21 = p_value;
				break;
			}
			
			
			case 10:
			{
				this.m22 = p_value;
				break;
			}
			
			
			case 11:
			{
				this.m23 = p_value;
				break;
			}
			
			
			case 12:
			{
				this.m30 = p_value;
				break;
			}
			
			
			case 13:
			{
				this.m31 = p_value;
				break;
			}
			
			
			case 14:
			{
				this.m32 = p_value;
				break;
			}
			
			
			case 15:
			{
				this.m33 = p_value;
				break;
			}
			
			
		}
		
		return this;
	}
	
	
	public   haxor.math.Matrix4 SetRowCol(int p_row, int p_col, double p_value)
	{
		return this.SetIndex(( p_col + (( p_row << 2 )) ), p_value);
	}
	
	
	public   double GetRowCol(int p_row, int p_col)
	{
		return this.GetIndex(( p_col + (( p_row << 2 )) ));
	}
	
	
	public   haxor.math.Matrix4 SwapCol(int p_a, int p_b)
	{
		double a0 = this.GetRowCol(0, p_a);
		double a1 = this.GetRowCol(1, p_a);
		double a2 = this.GetRowCol(2, p_a);
		double a3 = this.GetRowCol(3, p_a);
		this.SetRowCol(0, p_a, this.GetRowCol(0, p_b));
		this.SetRowCol(1, p_a, this.GetRowCol(1, p_b));
		this.SetRowCol(2, p_a, this.GetRowCol(2, p_b));
		this.SetRowCol(3, p_a, this.GetRowCol(3, p_b));
		this.SetRowCol(0, p_b, a0);
		this.SetRowCol(1, p_b, a1);
		this.SetRowCol(2, p_b, a2);
		this.SetRowCol(3, p_b, a3);
		return this;
	}
	
	
	public   haxor.math.Matrix4 SwapRow(int p_a, int p_b)
	{
		double a0 = this.GetRowCol(p_a, 0);
		double a1 = this.GetRowCol(p_a, 1);
		double a2 = this.GetRowCol(p_a, 2);
		double a3 = this.GetRowCol(p_a, 3);
		this.SetRowCol(p_a, 0, this.GetRowCol(p_b, 0));
		this.SetRowCol(p_a, 1, this.GetRowCol(p_b, 1));
		this.SetRowCol(p_a, 2, this.GetRowCol(p_b, 2));
		this.SetRowCol(p_a, 3, this.GetRowCol(p_b, 3));
		this.SetRowCol(p_b, 0, a0);
		this.SetRowCol(p_b, 1, a1);
		this.SetRowCol(p_b, 2, a2);
		this.SetRowCol(p_b, 3, a3);
		return this;
	}
	
	
	public   haxor.math.Matrix4 Transpose()
	{
		double t00 = this.m00;
		double t01 = this.m01;
		double t02 = this.m02;
		double t03 = this.m03;
		double t10 = this.m10;
		double t11 = this.m11;
		double t12 = this.m12;
		double t13 = this.m13;
		double t20 = this.m20;
		double t21 = this.m21;
		double t22 = this.m22;
		double t23 = this.m23;
		double t30 = this.m30;
		double t31 = this.m31;
		double t32 = this.m32;
		double t33 = this.m33;
		return this.Set(t00, t10, t20, t30, t01, t11, t21, t31, t02, t12, t22, t32, t03, t13, t23, t33);
	}
	
	
	public   haxor.math.Matrix4 ToRotation()
	{
		haxor.math.Vector3 tmp = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			tmp = _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
		}
		
		tmp.Set(this.m00, this.m01, this.m02).Normalize();
		this.m00 = tmp.x;
		this.m01 = tmp.y;
		this.m02 = tmp.z;
		this.m03 = 0.0;
		tmp.Set(this.m10, this.m11, this.m12).Normalize();
		this.m10 = tmp.x;
		this.m11 = tmp.y;
		this.m12 = tmp.z;
		this.m13 = 0.0;
		tmp.Set(this.m20, this.m21, this.m22).Normalize();
		this.m20 = tmp.x;
		this.m21 = tmp.y;
		this.m22 = tmp.z;
		this.m23 = 0.0;
		this.m30 = this.m31 = this.m32 = 0.0;
		this.m33 = 1.0;
		return this;
	}
	
	
	public   haxor.math.Vector3 Rotate(haxor.math.Vector3 p_vector)
	{
		haxor.math.Vector3 tmp = null;
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			tmp = _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
		}
		
		tmp.Set(this.m00, this.m01, this.m02).Normalize();
		p_vector.x = ( ( ( tmp.x * p_vector.x ) + ( tmp.y * p_vector.y ) ) + ( tmp.z * p_vector.z ) );
		tmp.Set(this.m10, this.m11, this.m12).Normalize();
		p_vector.y = ( ( ( tmp.x * p_vector.x ) + ( tmp.y * p_vector.y ) ) + ( tmp.z * p_vector.z ) );
		tmp.Set(this.m20, this.m21, this.m22).Normalize();
		p_vector.z = ( ( ( tmp.x * p_vector.x ) + ( tmp.y * p_vector.y ) ) + ( tmp.z * p_vector.z ) );
		return p_vector;
	}
	
	
	public final   haxor.math.Matrix4 SetTRS(haxor.math.Vector3 p_position, haxor.math.Quaternion p_rotation, haxor.math.Vector3 p_scale)
	{
		{
			double sx = 0.0;
			if (( p_scale == null )) 
			{
				sx = 1.0;
			}
			 else 
			{
				sx = p_scale.x;
			}
			
			double sy = 0.0;
			if (( p_scale == null )) 
			{
				sy = 1.0;
			}
			 else 
			{
				sy = p_scale.y;
			}
			
			double sz = 0.0;
			if (( p_scale == null )) 
			{
				sz = 1.0;
			}
			 else 
			{
				sz = p_scale.z;
			}
			
			double px = p_position.x;
			double py = p_position.y;
			double pz = p_position.z;
			haxor.math.Matrix4 r = null;
			{
				haxor.context.DataContext _this = haxor.context.EngineContext.data;
				r = _this.m_m4.__get(_this.m_nq = ( (( _this.m_nm4 + 1 )) % _this.m_m4.length ));
			}
			
			haxor.math.Matrix4.FromQuaternion(p_rotation, r);
			haxor.math.Matrix4 l = this;
			l.m00 = ( r.m00 * sx );
			l.m01 = ( r.m01 * sy );
			l.m02 = ( r.m02 * sz );
			l.m03 = px;
			l.m10 = ( r.m10 * sx );
			l.m11 = ( r.m11 * sy );
			l.m12 = ( r.m12 * sz );
			l.m13 = py;
			l.m20 = ( r.m20 * sx );
			l.m21 = ( r.m21 * sy );
			l.m22 = ( r.m22 * sz );
			l.m23 = pz;
			l.m30 = l.m31 = l.m32 = 0.0;
			l.m33 = 1.0;
			return l;
		}
		
	}
	
	
	public   haxor.math.Matrix4 MultiplyTransform(haxor.math.Matrix4 p_matrix)
	{
		double r00 = ( ( ( this.m00 * p_matrix.m00 ) + ( this.m01 * p_matrix.m10 ) ) + ( this.m02 * p_matrix.m20 ) );
		double r01 = ( ( ( this.m00 * p_matrix.m01 ) + ( this.m01 * p_matrix.m11 ) ) + ( this.m02 * p_matrix.m21 ) );
		double r02 = ( ( ( this.m00 * p_matrix.m02 ) + ( this.m01 * p_matrix.m12 ) ) + ( this.m02 * p_matrix.m22 ) );
		double r03 = ( ( ( ( this.m00 * p_matrix.m03 ) + ( this.m01 * p_matrix.m13 ) ) + ( this.m02 * p_matrix.m23 ) ) + this.m03 );
		double r10 = ( ( ( this.m10 * p_matrix.m00 ) + ( this.m11 * p_matrix.m10 ) ) + ( this.m12 * p_matrix.m20 ) );
		double r11 = ( ( ( this.m10 * p_matrix.m01 ) + ( this.m11 * p_matrix.m11 ) ) + ( this.m12 * p_matrix.m21 ) );
		double r12 = ( ( ( this.m10 * p_matrix.m02 ) + ( this.m11 * p_matrix.m12 ) ) + ( this.m12 * p_matrix.m22 ) );
		double r13 = ( ( ( ( this.m10 * p_matrix.m03 ) + ( this.m11 * p_matrix.m13 ) ) + ( this.m12 * p_matrix.m23 ) ) + this.m13 );
		double r20 = ( ( ( this.m20 * p_matrix.m00 ) + ( this.m21 * p_matrix.m10 ) ) + ( this.m22 * p_matrix.m20 ) );
		double r21 = ( ( ( this.m20 * p_matrix.m01 ) + ( this.m21 * p_matrix.m11 ) ) + ( this.m22 * p_matrix.m21 ) );
		double r22 = ( ( ( this.m20 * p_matrix.m02 ) + ( this.m21 * p_matrix.m12 ) ) + ( this.m22 * p_matrix.m22 ) );
		double r23 = ( ( ( ( this.m20 * p_matrix.m03 ) + ( this.m21 * p_matrix.m13 ) ) + ( this.m22 * p_matrix.m23 ) ) + this.m23 );
		this.Set(r00, r01, r02, r03, r10, r11, r12, r13, r20, r21, r22, r23, 0, 0, 0, 1);
		return this;
	}
	
	
	public   haxor.math.Matrix4 Multiply3x4(haxor.math.Matrix4 p_matrix)
	{
		double r00 = ( ( ( ( this.m00 * p_matrix.m00 ) + ( this.m01 * p_matrix.m10 ) ) + ( this.m02 * p_matrix.m20 ) ) + ( this.m03 * p_matrix.m30 ) );
		double r01 = ( ( ( ( this.m00 * p_matrix.m01 ) + ( this.m01 * p_matrix.m11 ) ) + ( this.m02 * p_matrix.m21 ) ) + ( this.m03 * p_matrix.m31 ) );
		double r02 = ( ( ( ( this.m00 * p_matrix.m02 ) + ( this.m01 * p_matrix.m12 ) ) + ( this.m02 * p_matrix.m22 ) ) + ( this.m03 * p_matrix.m32 ) );
		double r03 = ( ( ( ( this.m00 * p_matrix.m03 ) + ( this.m01 * p_matrix.m13 ) ) + ( this.m02 * p_matrix.m23 ) ) + ( this.m03 * p_matrix.m33 ) );
		double r10 = ( ( ( ( this.m10 * p_matrix.m00 ) + ( this.m11 * p_matrix.m10 ) ) + ( this.m12 * p_matrix.m20 ) ) + ( this.m13 * p_matrix.m30 ) );
		double r11 = ( ( ( ( this.m10 * p_matrix.m01 ) + ( this.m11 * p_matrix.m11 ) ) + ( this.m12 * p_matrix.m21 ) ) + ( this.m13 * p_matrix.m31 ) );
		double r12 = ( ( ( ( this.m10 * p_matrix.m02 ) + ( this.m11 * p_matrix.m12 ) ) + ( this.m12 * p_matrix.m22 ) ) + ( this.m13 * p_matrix.m32 ) );
		double r13 = ( ( ( ( this.m10 * p_matrix.m03 ) + ( this.m11 * p_matrix.m13 ) ) + ( this.m12 * p_matrix.m23 ) ) + ( this.m13 * p_matrix.m33 ) );
		double r20 = ( ( ( ( this.m20 * p_matrix.m00 ) + ( this.m21 * p_matrix.m10 ) ) + ( this.m22 * p_matrix.m20 ) ) + ( this.m23 * p_matrix.m30 ) );
		double r21 = ( ( ( ( this.m20 * p_matrix.m01 ) + ( this.m21 * p_matrix.m11 ) ) + ( this.m22 * p_matrix.m21 ) ) + ( this.m23 * p_matrix.m31 ) );
		double r22 = ( ( ( ( this.m20 * p_matrix.m02 ) + ( this.m21 * p_matrix.m12 ) ) + ( this.m22 * p_matrix.m22 ) ) + ( this.m23 * p_matrix.m32 ) );
		double r23 = ( ( ( ( this.m20 * p_matrix.m03 ) + ( this.m21 * p_matrix.m13 ) ) + ( this.m22 * p_matrix.m23 ) ) + ( this.m23 * p_matrix.m33 ) );
		this.Set(r00, r01, r02, r03, r10, r11, r12, r13, r20, r21, r22, r23, this.m30, this.m31, this.m32, this.m33);
		return this;
	}
	
	
	public   haxor.math.Matrix4 Multiply(haxor.math.Matrix4 p_matrix)
	{
		double r00 = ( ( ( ( this.m00 * p_matrix.m00 ) + ( this.m01 * p_matrix.m10 ) ) + ( this.m02 * p_matrix.m20 ) ) + ( this.m03 * p_matrix.m30 ) );
		double r01 = ( ( ( ( this.m00 * p_matrix.m01 ) + ( this.m01 * p_matrix.m11 ) ) + ( this.m02 * p_matrix.m21 ) ) + ( this.m03 * p_matrix.m31 ) );
		double r02 = ( ( ( ( this.m00 * p_matrix.m02 ) + ( this.m01 * p_matrix.m12 ) ) + ( this.m02 * p_matrix.m22 ) ) + ( this.m03 * p_matrix.m32 ) );
		double r03 = ( ( ( ( this.m00 * p_matrix.m03 ) + ( this.m01 * p_matrix.m13 ) ) + ( this.m02 * p_matrix.m23 ) ) + ( this.m03 * p_matrix.m33 ) );
		double r10 = ( ( ( ( this.m10 * p_matrix.m00 ) + ( this.m11 * p_matrix.m10 ) ) + ( this.m12 * p_matrix.m20 ) ) + ( this.m13 * p_matrix.m30 ) );
		double r11 = ( ( ( ( this.m10 * p_matrix.m01 ) + ( this.m11 * p_matrix.m11 ) ) + ( this.m12 * p_matrix.m21 ) ) + ( this.m13 * p_matrix.m31 ) );
		double r12 = ( ( ( ( this.m10 * p_matrix.m02 ) + ( this.m11 * p_matrix.m12 ) ) + ( this.m12 * p_matrix.m22 ) ) + ( this.m13 * p_matrix.m32 ) );
		double r13 = ( ( ( ( this.m10 * p_matrix.m03 ) + ( this.m11 * p_matrix.m13 ) ) + ( this.m12 * p_matrix.m23 ) ) + ( this.m13 * p_matrix.m33 ) );
		double r20 = ( ( ( ( this.m20 * p_matrix.m00 ) + ( this.m21 * p_matrix.m10 ) ) + ( this.m22 * p_matrix.m20 ) ) + ( this.m23 * p_matrix.m30 ) );
		double r21 = ( ( ( ( this.m20 * p_matrix.m01 ) + ( this.m21 * p_matrix.m11 ) ) + ( this.m22 * p_matrix.m21 ) ) + ( this.m23 * p_matrix.m31 ) );
		double r22 = ( ( ( ( this.m20 * p_matrix.m02 ) + ( this.m21 * p_matrix.m12 ) ) + ( this.m22 * p_matrix.m22 ) ) + ( this.m23 * p_matrix.m32 ) );
		double r23 = ( ( ( ( this.m20 * p_matrix.m03 ) + ( this.m21 * p_matrix.m13 ) ) + ( this.m22 * p_matrix.m23 ) ) + ( this.m23 * p_matrix.m33 ) );
		double r30 = ( ( ( ( this.m30 * p_matrix.m00 ) + ( this.m31 * p_matrix.m10 ) ) + ( this.m32 * p_matrix.m20 ) ) + ( this.m33 * p_matrix.m30 ) );
		double r31 = ( ( ( ( this.m30 * p_matrix.m01 ) + ( this.m31 * p_matrix.m11 ) ) + ( this.m32 * p_matrix.m21 ) ) + ( this.m33 * p_matrix.m31 ) );
		double r32 = ( ( ( ( this.m30 * p_matrix.m02 ) + ( this.m31 * p_matrix.m12 ) ) + ( this.m32 * p_matrix.m22 ) ) + ( this.m33 * p_matrix.m32 ) );
		double r33 = ( ( ( ( this.m30 * p_matrix.m03 ) + ( this.m31 * p_matrix.m13 ) ) + ( this.m32 * p_matrix.m23 ) ) + ( this.m33 * p_matrix.m33 ) );
		this.Set(r00, r01, r02, r03, r10, r11, r12, r13, r20, r21, r22, r23, r30, r31, r32, r33);
		return this;
	}
	
	
	public final   haxor.math.Vector4 Transform4x4(haxor.math.Vector4 p_point)
	{
		double vx = ( ( ( ( this.m00 * p_point.x ) + ( this.m01 * p_point.y ) ) + ( this.m02 * p_point.z ) ) + ( this.m03 * p_point.w ) );
		double vy = ( ( ( ( this.m10 * p_point.x ) + ( this.m11 * p_point.y ) ) + ( this.m12 * p_point.z ) ) + ( this.m13 * p_point.w ) );
		double vz = ( ( ( ( this.m20 * p_point.x ) + ( this.m21 * p_point.y ) ) + ( this.m22 * p_point.z ) ) + ( this.m23 * p_point.w ) );
		double vw = ( ( ( ( this.m30 * p_point.x ) + ( this.m31 * p_point.y ) ) + ( this.m32 * p_point.z ) ) + ( this.m33 * p_point.w ) );
		p_point.x = vx;
		p_point.y = vy;
		p_point.z = vz;
		p_point.w = vw;
		return p_point;
	}
	
	
	public final   haxor.math.Vector3 Transform3x4(haxor.math.Vector3 p_point)
	{
		double vx = ( ( ( ( this.m00 * p_point.x ) + ( this.m01 * p_point.y ) ) + ( this.m02 * p_point.z ) ) + this.m03 );
		double vy = ( ( ( ( this.m10 * p_point.x ) + ( this.m11 * p_point.y ) ) + ( this.m12 * p_point.z ) ) + this.m13 );
		double vz = ( ( ( ( this.m20 * p_point.x ) + ( this.m21 * p_point.y ) ) + ( this.m22 * p_point.z ) ) + this.m23 );
		p_point.x = vx;
		p_point.y = vy;
		p_point.z = vz;
		return p_point;
	}
	
	
	public final   haxor.math.Vector3 Transform3x3(haxor.math.Vector3 p_point)
	{
		double vx = ( ( ( this.m00 * p_point.x ) + ( this.m01 * p_point.y ) ) + ( this.m02 * p_point.z ) );
		double vy = ( ( ( this.m10 * p_point.x ) + ( this.m11 * p_point.y ) ) + ( this.m12 * p_point.z ) );
		double vz = ( ( ( this.m20 * p_point.x ) + ( this.m21 * p_point.y ) ) + ( this.m22 * p_point.z ) );
		p_point.x = vx;
		p_point.y = vy;
		p_point.z = vz;
		return p_point;
	}
	
	
	public final   void Transform2x3(haxor.math.Vector2 p_point)
	{
		double vx = ( ( ( this.m00 * p_point.x ) + ( this.m01 * p_point.y ) ) + this.m03 );
		double vy = ( ( ( this.m10 * p_point.x ) + ( this.m11 * p_point.y ) ) + this.m13 );
		p_point.x = vx;
		p_point.y = vy;
	}
	
	
	public final   void Transform2x2(haxor.math.Vector2 p_point)
	{
		double vx = ( ( this.m00 * p_point.x ) + ( this.m01 * p_point.y ) );
		double vy = ( ( this.m10 * p_point.x ) + ( this.m11 * p_point.y ) );
		p_point.x = vx;
		p_point.y = vy;
	}
	
	
	public final   haxor.math.Matrix4 SetLookAt(haxor.math.Vector3 p_eye, haxor.math.Vector3 p_at, haxor.math.Vector3 p_up)
	{
		return haxor.math.Matrix4.LookAt(p_eye, p_at, p_up, this);
	}
	
	
	public final   haxor.math.Matrix4 SetFrustum(double p_left, double p_right, double p_top, double p_bottom, double p_near, double p_far)
	{
		{
			haxor.math.Matrix4 m = this;
			double n2 = ( p_near * 2.0 );
			double rml = ( 1.0 / (( p_right - p_left )) );
			double tmb = ( 1.0 / (( p_top - p_bottom )) );
			double fmn = ( 1.0 / (( p_far - p_near )) );
			m.m00 = ( n2 * rml );
			m.m01 = 0.0;
			m.m02 = ( (( p_right + p_left )) * rml );
			m.m03 = 0.0;
			m.m10 = 0.0;
			m.m11 = ( n2 * tmb );
			m.m12 = ( (( p_top + p_bottom )) * tmb );
			m.m13 = 0.0;
			m.m20 = 0.0;
			m.m21 = 0.0;
			m.m22 = (  - ((( p_near + p_far )))  * fmn );
			m.m23 = ( (  - (n2)  * p_far ) * fmn );
			m.m30 = 0.0;
			m.m31 = 0.0;
			m.m32 = -1.0;
			m.m33 = ((double) (0) );
			return m;
		}
		
	}
	
	
	public final   haxor.math.Matrix4 SetFrustumInverse(double p_left, double p_right, double p_top, double p_bottom, double p_near, double p_far)
	{
		{
			haxor.math.Matrix4 m = this;
			double n2 = ( p_near * 2.0 );
			double rml = ( p_right - p_left );
			double tmb = ( p_top - p_bottom );
			double fmn = ( p_far - p_near );
			m.m00 = ( rml / n2 );
			m.m01 = 0.0;
			m.m02 = 0.0;
			m.m03 = ( (( p_right + p_left )) / n2 );
			m.m10 = 0.0;
			m.m11 = ( tmb / n2 );
			m.m12 = 0.0;
			m.m13 = ( (( p_top + p_bottom )) / n2 );
			m.m20 = 0.0;
			m.m21 = 0.0;
			m.m22 = 0.0;
			m.m23 = -1.0;
			m.m30 = 0.0;
			m.m31 = 0.0;
			m.m32 = ( fmn / ((  - (n2)  * p_far )) );
			m.m33 = ( (( p_far + p_near )) / (( n2 * p_far )) );
			return m;
		}
		
	}
	
	
	public   haxor.math.Matrix4 SetOrtho(double p_left, double p_right, double p_top, double p_bottom, double p_near, double p_far)
	{
		return haxor.math.Matrix4.Ortho(p_left, p_right, p_top, p_bottom, p_near, p_far, this);
	}
	
	
	public final   haxor.math.Matrix4 SetPerspective(double p_fov, double p_aspect, double p_near, double p_far)
	{
		return haxor.math.Matrix4.Perspective(p_fov, p_aspect, p_near, p_far, this);
	}
	
	
	public final   haxor.math.Matrix4 SetPerspectiveInverse(double p_fov, double p_aspect, double p_near, double p_far)
	{
		return haxor.math.Matrix4.PerspectiveInverse(p_fov, p_aspect, p_near, p_far, this);
	}
	
	
	public   haxe.root.Array<java.lang.Object> ToArray()
	{
		return new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (this.m00) ), ((java.lang.Object) (this.m01) ), ((java.lang.Object) (this.m02) ), ((java.lang.Object) (this.m03) ), ((java.lang.Object) (this.m10) ), ((java.lang.Object) (this.m11) ), ((java.lang.Object) (this.m12) ), ((java.lang.Object) (this.m13) ), ((java.lang.Object) (this.m20) ), ((java.lang.Object) (this.m21) ), ((java.lang.Object) (this.m22) ), ((java.lang.Object) (this.m23) ), ((java.lang.Object) (this.m30) ), ((java.lang.Object) (this.m31) ), ((java.lang.Object) (this.m32) ), ((java.lang.Object) (this.m33) )});
	}
	
	
	public   java.lang.String ToString(java.lang.Object p_linear, java.lang.Object p_places)
	{
		int __temp_p_places151514 = ( (( p_places == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_places)) )) );
		boolean __temp_p_linear151513 = ( (( p_linear == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_linear)) );
		haxe.root.Array<java.lang.Object> a = this.ToArray();
		haxe.root.Array<java.lang.String> s = new haxe.root.Array<java.lang.String>(new java.lang.String[]{});
		{
			int _g1 = 0;
			int _g = a.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				{
					double d = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places151514) ));
					double __temp_stmt152372 = 0.0;
					{
						double p_v = ( ((double) (haxe.lang.Runtime.toDouble(a.__get(i))) ) * d );
						__temp_stmt152372 = ((double) (((int) (( p_v + (( (( p_v < 0 )) ? (-0.5) : (0.5) )) )) )) );
					}
					
					a.__set(i, ( __temp_stmt152372 / d ));
				}
				
				s.push(( (( ((double) (haxe.lang.Runtime.toDouble(a.__get(i))) ) >= 0 )) ? (( " " + haxe.lang.Runtime.toString(((double) (haxe.lang.Runtime.toDouble(a.__get(i))) )) )) : (( haxe.lang.Runtime.toString(((double) (haxe.lang.Runtime.toDouble(a.__get(i))) )) + "" )) ));
			}
			
		}
		
		java.lang.String res = null;
		if (__temp_p_linear151513) 
		{
			res = "[";
		}
		 else 
		{
			res = "";
		}
		
		{
			int _g2 = 0;
			while (( _g2 < 4 ))
			{
				int i1 = _g2++;
				{
					int _g11 = 0;
					while (( _g11 < 4 ))
					{
						int j = _g11++;
						res += ( s.__get(( j + ( i1 * 4 ) )) + (( (( j < 3 )) ? (",") : ("") )) );
					}
					
				}
				
				if (( i1 == 3 )) 
				{
					res += "";
				}
				 else 
				{
					if (__temp_p_linear151513) 
					{
						res += " |";
					}
					 else 
					{
						res += "\n";
					}
					
				}
				
			}
			
		}
		
		if (__temp_p_linear151513) 
		{
			res += "]";
		}
		
		return res;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152373 = true;
			switch (field.hashCode())
			{
				case 106381:
				{
					if (field.equals("m33")) 
					{
						__temp_executeDef152373 = false;
						this.m33 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106285:
				{
					if (field.equals("m00")) 
					{
						__temp_executeDef152373 = false;
						this.m00 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106380:
				{
					if (field.equals("m32")) 
					{
						__temp_executeDef152373 = false;
						this.m32 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106286:
				{
					if (field.equals("m01")) 
					{
						__temp_executeDef152373 = false;
						this.m01 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106379:
				{
					if (field.equals("m31")) 
					{
						__temp_executeDef152373 = false;
						this.m31 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106287:
				{
					if (field.equals("m02")) 
					{
						__temp_executeDef152373 = false;
						this.m02 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106378:
				{
					if (field.equals("m30")) 
					{
						__temp_executeDef152373 = false;
						this.m30 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106288:
				{
					if (field.equals("m03")) 
					{
						__temp_executeDef152373 = false;
						this.m03 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106350:
				{
					if (field.equals("m23")) 
					{
						__temp_executeDef152373 = false;
						this.m23 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106316:
				{
					if (field.equals("m10")) 
					{
						__temp_executeDef152373 = false;
						this.m10 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106349:
				{
					if (field.equals("m22")) 
					{
						__temp_executeDef152373 = false;
						this.m22 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106317:
				{
					if (field.equals("m11")) 
					{
						__temp_executeDef152373 = false;
						this.m11 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106348:
				{
					if (field.equals("m21")) 
					{
						__temp_executeDef152373 = false;
						this.m21 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106318:
				{
					if (field.equals("m12")) 
					{
						__temp_executeDef152373 = false;
						this.m12 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106347:
				{
					if (field.equals("m20")) 
					{
						__temp_executeDef152373 = false;
						this.m20 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106319:
				{
					if (field.equals("m13")) 
					{
						__temp_executeDef152373 = false;
						this.m13 = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152373) 
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
			boolean __temp_executeDef152374 = true;
			switch (field.hashCode())
			{
				case -1520743301:
				{
					if (field.equals("diagonalLR")) 
					{
						__temp_executeDef152374 = false;
						this.set_diagonalLR(((haxor.math.Vector4) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1624634594:
				{
					if (field.equals("quaternion")) 
					{
						__temp_executeDef152374 = false;
						this.set_quaternion(((haxor.math.Quaternion) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 106381:
				{
					if (field.equals("m33")) 
					{
						__temp_executeDef152374 = false;
						this.m33 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -40300674:
				{
					if (field.equals("rotation")) 
					{
						__temp_executeDef152374 = false;
						this.rotation = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106380:
				{
					if (field.equals("m32")) 
					{
						__temp_executeDef152374 = false;
						this.m32 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 109250890:
				{
					if (field.equals("scale")) 
					{
						__temp_executeDef152374 = false;
						this.scale = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106379:
				{
					if (field.equals("m31")) 
					{
						__temp_executeDef152374 = false;
						this.m31 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1840647503:
				{
					if (field.equals("translation")) 
					{
						__temp_executeDef152374 = false;
						this.translation = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106378:
				{
					if (field.equals("m30")) 
					{
						__temp_executeDef152374 = false;
						this.m30 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1106622948:
				{
					if (field.equals("inverseTransform")) 
					{
						__temp_executeDef152374 = false;
						this.inverseTransform = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106350:
				{
					if (field.equals("m23")) 
					{
						__temp_executeDef152374 = false;
						this.m23 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1717833653:
				{
					if (field.equals("transposed")) 
					{
						__temp_executeDef152374 = false;
						this.transposed = ((haxor.math.Matrix4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 106349:
				{
					if (field.equals("m22")) 
					{
						__temp_executeDef152374 = false;
						this.m22 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 106285:
				{
					if (field.equals("m00")) 
					{
						__temp_executeDef152374 = false;
						this.m00 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 106348:
				{
					if (field.equals("m21")) 
					{
						__temp_executeDef152374 = false;
						this.m21 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 106286:
				{
					if (field.equals("m01")) 
					{
						__temp_executeDef152374 = false;
						this.m01 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 106347:
				{
					if (field.equals("m20")) 
					{
						__temp_executeDef152374 = false;
						this.m20 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 106287:
				{
					if (field.equals("m02")) 
					{
						__temp_executeDef152374 = false;
						this.m02 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 106319:
				{
					if (field.equals("m13")) 
					{
						__temp_executeDef152374 = false;
						this.m13 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 106288:
				{
					if (field.equals("m03")) 
					{
						__temp_executeDef152374 = false;
						this.m03 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 106318:
				{
					if (field.equals("m12")) 
					{
						__temp_executeDef152374 = false;
						this.m12 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 106316:
				{
					if (field.equals("m10")) 
					{
						__temp_executeDef152374 = false;
						this.m10 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 106317:
				{
					if (field.equals("m11")) 
					{
						__temp_executeDef152374 = false;
						this.m11 = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152374) 
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
			boolean __temp_executeDef152375 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef152375 = false;
						return this.get_clone();
					}
					
					break;
				}
				
				
				case 482271358:
				{
					if (field.equals("ToArray")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToArray"))) );
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_clone"))) );
					}
					
					break;
				}
				
				
				case 1952428342:
				{
					if (field.equals("SetPerspectiveInverse")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetPerspectiveInverse"))) );
					}
					
					break;
				}
				
				
				case -1624634594:
				{
					if (field.equals("quaternion")) 
					{
						__temp_executeDef152375 = false;
						return this.get_quaternion();
					}
					
					break;
				}
				
				
				case 1088929946:
				{
					if (field.equals("SetPerspective")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetPerspective"))) );
					}
					
					break;
				}
				
				
				case 1450508199:
				{
					if (field.equals("get_quaternion")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_quaternion"))) );
					}
					
					break;
				}
				
				
				case 1465378966:
				{
					if (field.equals("SetOrtho")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetOrtho"))) );
					}
					
					break;
				}
				
				
				case -321228005:
				{
					if (field.equals("set_quaternion")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_quaternion"))) );
					}
					
					break;
				}
				
				
				case -999351216:
				{
					if (field.equals("SetFrustumInverse")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFrustumInverse"))) );
					}
					
					break;
				}
				
				
				case 110620997:
				{
					if (field.equals("trace")) 
					{
						__temp_executeDef152375 = false;
						return this.get_trace();
					}
					
					break;
				}
				
				
				case 83574464:
				{
					if (field.equals("SetFrustum")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetFrustum"))) );
					}
					
					break;
				}
				
				
				case 1147570972:
				{
					if (field.equals("get_trace")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_trace"))) );
					}
					
					break;
				}
				
				
				case -1906697708:
				{
					if (field.equals("SetLookAt")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetLookAt"))) );
					}
					
					break;
				}
				
				
				case -40300674:
				{
					if (field.equals("rotation")) 
					{
						__temp_executeDef152375 = false;
						if (handleProperties) 
						{
							return this.get_rotation();
						}
						 else 
						{
							return this.rotation;
						}
						
					}
					
					break;
				}
				
				
				case -1692210272:
				{
					if (field.equals("Transform2x2")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Transform2x2"))) );
					}
					
					break;
				}
				
				
				case -1963355577:
				{
					if (field.equals("get_rotation")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_rotation"))) );
					}
					
					break;
				}
				
				
				case -1692210271:
				{
					if (field.equals("Transform2x3")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Transform2x3"))) );
					}
					
					break;
				}
				
				
				case 109250890:
				{
					if (field.equals("scale")) 
					{
						__temp_executeDef152375 = false;
						if (handleProperties) 
						{
							return this.get_scale();
						}
						 else 
						{
							return this.scale;
						}
						
					}
					
					break;
				}
				
				
				case -1692209310:
				{
					if (field.equals("Transform3x3")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Transform3x3"))) );
					}
					
					break;
				}
				
				
				case 1146200865:
				{
					if (field.equals("get_scale")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_scale"))) );
					}
					
					break;
				}
				
				
				case -1692209309:
				{
					if (field.equals("Transform3x4")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Transform3x4"))) );
					}
					
					break;
				}
				
				
				case -1840647503:
				{
					if (field.equals("translation")) 
					{
						__temp_executeDef152375 = false;
						if (handleProperties) 
						{
							return this.get_translation();
						}
						 else 
						{
							return this.translation;
						}
						
					}
					
					break;
				}
				
				
				case -1692208348:
				{
					if (field.equals("Transform4x4")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Transform4x4"))) );
					}
					
					break;
				}
				
				
				case -1000501432:
				{
					if (field.equals("get_translation")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_translation"))) );
					}
					
					break;
				}
				
				
				case 718473796:
				{
					if (field.equals("Multiply")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Multiply"))) );
					}
					
					break;
				}
				
				
				case -1106622948:
				{
					if (field.equals("inverseTransform")) 
					{
						__temp_executeDef152375 = false;
						if (handleProperties) 
						{
							return this.get_inverseTransform();
						}
						 else 
						{
							return this.inverseTransform;
						}
						
					}
					
					break;
				}
				
				
				case -2064093845:
				{
					if (field.equals("Multiply3x4")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Multiply3x4"))) );
					}
					
					break;
				}
				
				
				case 360968165:
				{
					if (field.equals("get_inverseTransform")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_inverseTransform"))) );
					}
					
					break;
				}
				
				
				case -894775928:
				{
					if (field.equals("MultiplyTransform")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("MultiplyTransform"))) );
					}
					
					break;
				}
				
				
				case -1717833653:
				{
					if (field.equals("transposed")) 
					{
						__temp_executeDef152375 = false;
						if (handleProperties) 
						{
							return this.get_transposed();
						}
						 else 
						{
							return this.transposed;
						}
						
					}
					
					break;
				}
				
				
				case -1821933037:
				{
					if (field.equals("SetTRS")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetTRS"))) );
					}
					
					break;
				}
				
				
				case 1357309140:
				{
					if (field.equals("get_transposed")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_transposed"))) );
					}
					
					break;
				}
				
				
				case -1841313413:
				{
					if (field.equals("Rotate")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Rotate"))) );
					}
					
					break;
				}
				
				
				case 1999947706:
				{
					if (field.equals("ToRowMajor")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToRowMajor"))) );
					}
					
					break;
				}
				
				
				case 1933095737:
				{
					if (field.equals("ToRotation")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToRotation"))) );
					}
					
					break;
				}
				
				
				case -911796632:
				{
					if (field.equals("ToColumnMajor")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToColumnMajor"))) );
					}
					
					break;
				}
				
				
				case -1238034663:
				{
					if (field.equals("Transpose")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Transpose"))) );
					}
					
					break;
				}
				
				
				case 106285:
				{
					if (field.equals("m00")) 
					{
						__temp_executeDef152375 = false;
						return this.m00;
					}
					
					break;
				}
				
				
				case -146736345:
				{
					if (field.equals("SwapRow")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SwapRow"))) );
					}
					
					break;
				}
				
				
				case 106286:
				{
					if (field.equals("m01")) 
					{
						__temp_executeDef152375 = false;
						return this.m01;
					}
					
					break;
				}
				
				
				case -146750771:
				{
					if (field.equals("SwapCol")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SwapCol"))) );
					}
					
					break;
				}
				
				
				case 106287:
				{
					if (field.equals("m02")) 
					{
						__temp_executeDef152375 = false;
						return this.m02;
					}
					
					break;
				}
				
				
				case -1520104420:
				{
					if (field.equals("GetRowCol")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetRowCol"))) );
					}
					
					break;
				}
				
				
				case 106288:
				{
					if (field.equals("m03")) 
					{
						__temp_executeDef152375 = false;
						return this.m03;
					}
					
					break;
				}
				
				
				case -1734721496:
				{
					if (field.equals("SetRowCol")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetRowCol"))) );
					}
					
					break;
				}
				
				
				case 106316:
				{
					if (field.equals("m10")) 
					{
						__temp_executeDef152375 = false;
						return this.m10;
					}
					
					break;
				}
				
				
				case 1459703216:
				{
					if (field.equals("SetIndex")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetIndex"))) );
					}
					
					break;
				}
				
				
				case 106317:
				{
					if (field.equals("m11")) 
					{
						__temp_executeDef152375 = false;
						return this.m11;
					}
					
					break;
				}
				
				
				case 2020815676:
				{
					if (field.equals("GetIndex")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetIndex"))) );
					}
					
					break;
				}
				
				
				case 106318:
				{
					if (field.equals("m12")) 
					{
						__temp_executeDef152375 = false;
						return this.m12;
					}
					
					break;
				}
				
				
				case 1513473521:
				{
					if (field.equals("SetMatrix4")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetMatrix4"))) );
					}
					
					break;
				}
				
				
				case 106319:
				{
					if (field.equals("m13")) 
					{
						__temp_executeDef152375 = false;
						return this.m13;
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 106347:
				{
					if (field.equals("m20")) 
					{
						__temp_executeDef152375 = false;
						return this.m20;
					}
					
					break;
				}
				
				
				case -773540064:
				{
					if (field.equals("SetIdentity")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetIdentity"))) );
					}
					
					break;
				}
				
				
				case 106348:
				{
					if (field.equals("m21")) 
					{
						__temp_executeDef152375 = false;
						return this.m21;
					}
					
					break;
				}
				
				
				case -217336712:
				{
					if (field.equals("set_diagonalLR")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_diagonalLR"))) );
					}
					
					break;
				}
				
				
				case 106349:
				{
					if (field.equals("m22")) 
					{
						__temp_executeDef152375 = false;
						return this.m22;
					}
					
					break;
				}
				
				
				case 1554399492:
				{
					if (field.equals("get_diagonalLR")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_diagonalLR"))) );
					}
					
					break;
				}
				
				
				case 106350:
				{
					if (field.equals("m23")) 
					{
						__temp_executeDef152375 = false;
						return this.m23;
					}
					
					break;
				}
				
				
				case -1520743301:
				{
					if (field.equals("diagonalLR")) 
					{
						__temp_executeDef152375 = false;
						return this.get_diagonalLR();
					}
					
					break;
				}
				
				
				case 106378:
				{
					if (field.equals("m30")) 
					{
						__temp_executeDef152375 = false;
						return this.m30;
					}
					
					break;
				}
				
				
				case 2130528824:
				{
					if (field.equals("SetColumn")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetColumn"))) );
					}
					
					break;
				}
				
				
				case 106379:
				{
					if (field.equals("m31")) 
					{
						__temp_executeDef152375 = false;
						return this.m31;
					}
					
					break;
				}
				
				
				case -1949821396:
				{
					if (field.equals("GetColumn")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetColumn"))) );
					}
					
					break;
				}
				
				
				case 106380:
				{
					if (field.equals("m32")) 
					{
						__temp_executeDef152375 = false;
						return this.m32;
					}
					
					break;
				}
				
				
				case -645564586:
				{
					if (field.equals("SetLine")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetLine"))) );
					}
					
					break;
				}
				
				
				case 106381:
				{
					if (field.equals("m33")) 
					{
						__temp_executeDef152375 = false;
						return this.m33;
					}
					
					break;
				}
				
				
				case 1589293130:
				{
					if (field.equals("GetLine")) 
					{
						__temp_executeDef152375 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetLine"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152375) 
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
			boolean __temp_executeDef152376 = true;
			switch (field.hashCode())
			{
				case 106381:
				{
					if (field.equals("m33")) 
					{
						__temp_executeDef152376 = false;
						return this.m33;
					}
					
					break;
				}
				
				
				case 110620997:
				{
					if (field.equals("trace")) 
					{
						__temp_executeDef152376 = false;
						return this.get_trace();
					}
					
					break;
				}
				
				
				case 106380:
				{
					if (field.equals("m32")) 
					{
						__temp_executeDef152376 = false;
						return this.m32;
					}
					
					break;
				}
				
				
				case 106285:
				{
					if (field.equals("m00")) 
					{
						__temp_executeDef152376 = false;
						return this.m00;
					}
					
					break;
				}
				
				
				case 106379:
				{
					if (field.equals("m31")) 
					{
						__temp_executeDef152376 = false;
						return this.m31;
					}
					
					break;
				}
				
				
				case 106286:
				{
					if (field.equals("m01")) 
					{
						__temp_executeDef152376 = false;
						return this.m01;
					}
					
					break;
				}
				
				
				case 106378:
				{
					if (field.equals("m30")) 
					{
						__temp_executeDef152376 = false;
						return this.m30;
					}
					
					break;
				}
				
				
				case 106287:
				{
					if (field.equals("m02")) 
					{
						__temp_executeDef152376 = false;
						return this.m02;
					}
					
					break;
				}
				
				
				case 106350:
				{
					if (field.equals("m23")) 
					{
						__temp_executeDef152376 = false;
						return this.m23;
					}
					
					break;
				}
				
				
				case 106288:
				{
					if (field.equals("m03")) 
					{
						__temp_executeDef152376 = false;
						return this.m03;
					}
					
					break;
				}
				
				
				case 106349:
				{
					if (field.equals("m22")) 
					{
						__temp_executeDef152376 = false;
						return this.m22;
					}
					
					break;
				}
				
				
				case 106316:
				{
					if (field.equals("m10")) 
					{
						__temp_executeDef152376 = false;
						return this.m10;
					}
					
					break;
				}
				
				
				case 106348:
				{
					if (field.equals("m21")) 
					{
						__temp_executeDef152376 = false;
						return this.m21;
					}
					
					break;
				}
				
				
				case 106317:
				{
					if (field.equals("m11")) 
					{
						__temp_executeDef152376 = false;
						return this.m11;
					}
					
					break;
				}
				
				
				case 106347:
				{
					if (field.equals("m20")) 
					{
						__temp_executeDef152376 = false;
						return this.m20;
					}
					
					break;
				}
				
				
				case 106318:
				{
					if (field.equals("m12")) 
					{
						__temp_executeDef152376 = false;
						return this.m12;
					}
					
					break;
				}
				
				
				case 106319:
				{
					if (field.equals("m13")) 
					{
						__temp_executeDef152376 = false;
						return this.m13;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152376) 
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
			boolean __temp_executeDef152377 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef152377 = false;
						return this.ToString(dynargs.__get(0), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef152377 = false;
						return this.get_clone();
					}
					
					break;
				}
				
				
				case 482271358:
				{
					if (field.equals("ToArray")) 
					{
						__temp_executeDef152377 = false;
						return this.ToArray();
					}
					
					break;
				}
				
				
				case 1450508199:
				{
					if (field.equals("get_quaternion")) 
					{
						__temp_executeDef152377 = false;
						return this.get_quaternion();
					}
					
					break;
				}
				
				
				case 1952428342:
				{
					if (field.equals("SetPerspectiveInverse")) 
					{
						__temp_executeDef152377 = false;
						return this.SetPerspectiveInverse(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case -321228005:
				{
					if (field.equals("set_quaternion")) 
					{
						__temp_executeDef152377 = false;
						return this.set_quaternion(((haxor.math.Quaternion) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1088929946:
				{
					if (field.equals("SetPerspective")) 
					{
						__temp_executeDef152377 = false;
						return this.SetPerspective(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case 1147570972:
				{
					if (field.equals("get_trace")) 
					{
						__temp_executeDef152377 = false;
						return this.get_trace();
					}
					
					break;
				}
				
				
				case 1465378966:
				{
					if (field.equals("SetOrtho")) 
					{
						__temp_executeDef152377 = false;
						return this.SetOrtho(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(4))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(5))) ));
					}
					
					break;
				}
				
				
				case -1963355577:
				{
					if (field.equals("get_rotation")) 
					{
						__temp_executeDef152377 = false;
						return this.get_rotation();
					}
					
					break;
				}
				
				
				case -999351216:
				{
					if (field.equals("SetFrustumInverse")) 
					{
						__temp_executeDef152377 = false;
						return this.SetFrustumInverse(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(4))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(5))) ));
					}
					
					break;
				}
				
				
				case 1146200865:
				{
					if (field.equals("get_scale")) 
					{
						__temp_executeDef152377 = false;
						return this.get_scale();
					}
					
					break;
				}
				
				
				case 83574464:
				{
					if (field.equals("SetFrustum")) 
					{
						__temp_executeDef152377 = false;
						return this.SetFrustum(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(4))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(5))) ));
					}
					
					break;
				}
				
				
				case -1000501432:
				{
					if (field.equals("get_translation")) 
					{
						__temp_executeDef152377 = false;
						return this.get_translation();
					}
					
					break;
				}
				
				
				case -1906697708:
				{
					if (field.equals("SetLookAt")) 
					{
						__temp_executeDef152377 = false;
						return this.SetLookAt(((haxor.math.Vector3) (dynargs.__get(0)) ), ((haxor.math.Vector3) (dynargs.__get(1)) ), ((haxor.math.Vector3) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case 360968165:
				{
					if (field.equals("get_inverseTransform")) 
					{
						__temp_executeDef152377 = false;
						return this.get_inverseTransform();
					}
					
					break;
				}
				
				
				case -1692210272:
				{
					if (field.equals("Transform2x2")) 
					{
						__temp_executeDef152377 = false;
						this.Transform2x2(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1357309140:
				{
					if (field.equals("get_transposed")) 
					{
						__temp_executeDef152377 = false;
						return this.get_transposed();
					}
					
					break;
				}
				
				
				case -1692210271:
				{
					if (field.equals("Transform2x3")) 
					{
						__temp_executeDef152377 = false;
						this.Transform2x3(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1999947706:
				{
					if (field.equals("ToRowMajor")) 
					{
						__temp_executeDef152377 = false;
						return this.ToRowMajor();
					}
					
					break;
				}
				
				
				case -1692209310:
				{
					if (field.equals("Transform3x3")) 
					{
						__temp_executeDef152377 = false;
						return this.Transform3x3(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -911796632:
				{
					if (field.equals("ToColumnMajor")) 
					{
						__temp_executeDef152377 = false;
						return this.ToColumnMajor();
					}
					
					break;
				}
				
				
				case -1692209309:
				{
					if (field.equals("Transform3x4")) 
					{
						__temp_executeDef152377 = false;
						return this.Transform3x4(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1589293130:
				{
					if (field.equals("GetLine")) 
					{
						__temp_executeDef152377 = false;
						return this.GetLine(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxor.math.Vector4) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -1692208348:
				{
					if (field.equals("Transform4x4")) 
					{
						__temp_executeDef152377 = false;
						return this.Transform4x4(((haxor.math.Vector4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -645564586:
				{
					if (field.equals("SetLine")) 
					{
						__temp_executeDef152377 = false;
						this.SetLine(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(4))) ));
					}
					
					break;
				}
				
				
				case 718473796:
				{
					if (field.equals("Multiply")) 
					{
						__temp_executeDef152377 = false;
						return this.Multiply(((haxor.math.Matrix4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1949821396:
				{
					if (field.equals("GetColumn")) 
					{
						__temp_executeDef152377 = false;
						return this.GetColumn(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxor.math.Vector4) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
				case -2064093845:
				{
					if (field.equals("Multiply3x4")) 
					{
						__temp_executeDef152377 = false;
						return this.Multiply3x4(((haxor.math.Matrix4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2130528824:
				{
					if (field.equals("SetColumn")) 
					{
						__temp_executeDef152377 = false;
						this.SetColumn(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(4))) ));
					}
					
					break;
				}
				
				
				case -894775928:
				{
					if (field.equals("MultiplyTransform")) 
					{
						__temp_executeDef152377 = false;
						return this.MultiplyTransform(((haxor.math.Matrix4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1554399492:
				{
					if (field.equals("get_diagonalLR")) 
					{
						__temp_executeDef152377 = false;
						return this.get_diagonalLR();
					}
					
					break;
				}
				
				
				case -1821933037:
				{
					if (field.equals("SetTRS")) 
					{
						__temp_executeDef152377 = false;
						return this.SetTRS(((haxor.math.Vector3) (dynargs.__get(0)) ), ((haxor.math.Quaternion) (dynargs.__get(1)) ), ((haxor.math.Vector3) (dynargs.__get(2)) ));
					}
					
					break;
				}
				
				
				case -217336712:
				{
					if (field.equals("set_diagonalLR")) 
					{
						__temp_executeDef152377 = false;
						return this.set_diagonalLR(((haxor.math.Vector4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1841313413:
				{
					if (field.equals("Rotate")) 
					{
						__temp_executeDef152377 = false;
						return this.Rotate(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -773540064:
				{
					if (field.equals("SetIdentity")) 
					{
						__temp_executeDef152377 = false;
						return this.SetIdentity();
					}
					
					break;
				}
				
				
				case 1933095737:
				{
					if (field.equals("ToRotation")) 
					{
						__temp_executeDef152377 = false;
						return this.ToRotation();
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef152377 = false;
						return this.Set(dynargs.__get(0), dynargs.__get(1), dynargs.__get(2), dynargs.__get(3), dynargs.__get(4), dynargs.__get(5), dynargs.__get(6), dynargs.__get(7), dynargs.__get(8), dynargs.__get(9), dynargs.__get(10), dynargs.__get(11), dynargs.__get(12), dynargs.__get(13), dynargs.__get(14), dynargs.__get(15));
					}
					
					break;
				}
				
				
				case -1238034663:
				{
					if (field.equals("Transpose")) 
					{
						__temp_executeDef152377 = false;
						return this.Transpose();
					}
					
					break;
				}
				
				
				case 1513473521:
				{
					if (field.equals("SetMatrix4")) 
					{
						__temp_executeDef152377 = false;
						return this.SetMatrix4(((haxor.math.Matrix4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -146736345:
				{
					if (field.equals("SwapRow")) 
					{
						__temp_executeDef152377 = false;
						return this.SwapRow(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 2020815676:
				{
					if (field.equals("GetIndex")) 
					{
						__temp_executeDef152377 = false;
						return this.GetIndex(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -146750771:
				{
					if (field.equals("SwapCol")) 
					{
						__temp_executeDef152377 = false;
						return this.SwapCol(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 1459703216:
				{
					if (field.equals("SetIndex")) 
					{
						__temp_executeDef152377 = false;
						return this.SetIndex(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -1520104420:
				{
					if (field.equals("GetRowCol")) 
					{
						__temp_executeDef152377 = false;
						return this.GetRowCol(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -1734721496:
				{
					if (field.equals("SetRowCol")) 
					{
						__temp_executeDef152377 = false;
						return this.SetRowCol(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152377) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("diagonalLR");
		baseArr.push("m33");
		baseArr.push("m32");
		baseArr.push("m31");
		baseArr.push("m30");
		baseArr.push("m23");
		baseArr.push("m22");
		baseArr.push("m21");
		baseArr.push("m20");
		baseArr.push("m13");
		baseArr.push("m12");
		baseArr.push("m11");
		baseArr.push("m10");
		baseArr.push("m03");
		baseArr.push("m02");
		baseArr.push("m01");
		baseArr.push("m00");
		baseArr.push("transposed");
		baseArr.push("inverseTransform");
		baseArr.push("translation");
		baseArr.push("scale");
		baseArr.push("rotation");
		baseArr.push("trace");
		baseArr.push("quaternion");
		baseArr.push("clone");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


