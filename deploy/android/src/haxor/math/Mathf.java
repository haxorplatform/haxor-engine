package haxor.math;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Mathf extends haxe.lang.HxObject
{
	static 
	{
		haxor.math.Mathf.Epsilon = 0.0001;
		haxor.math.Mathf.NaN = java.lang.Double.NaN;
		haxor.math.Mathf.Infinity = java.lang.Double.POSITIVE_INFINITY;
		haxor.math.Mathf.NegativeInfinity = java.lang.Double.NEGATIVE_INFINITY;
		haxor.math.Mathf.E = 2.7182818284590452353602874713527;
		haxor.math.Mathf.PI = 3.1415926535897932384626433832795028841971693993751058;
		haxor.math.Mathf.HalfPI = 1.5707963267948966192313216916398;
		haxor.math.Mathf.PI2 = 6.283185307179586476925286766559;
		haxor.math.Mathf.PI4 = 12.566370614359172953850573533118;
		haxor.math.Mathf.InvPI = 0.31830988618379067153776752674503;
		haxor.math.Mathf.Rad2Deg = 57.295779513082320876798154814105;
		haxor.math.Mathf.Deg2Rad = 0.01745329251994329576923690768489;
		haxor.math.Mathf.Px2Em = 0.063;
		haxor.math.Mathf.Em2Px = 15.87301587301587;
		haxor.math.Mathf.Byte2Float = 0.00392156863;
		haxor.math.Mathf.Short2Float = 0.0000152587890625;
		haxor.math.Mathf.Long2Float = 0.00000000023283064365386962890625;
		haxor.math.Mathf.Float2Byte = 255.0;
		haxor.math.Mathf.Float2Short = 65536.0;
		haxor.math.Mathf.Float2Long = 4294967296.0;
	}
	public    Mathf(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Mathf()
	{
		haxor.math.Mathf.__hx_ctor_haxor_math_Mathf(this);
	}
	
	
	public static   void __hx_ctor_haxor_math_Mathf(haxor.math.Mathf __temp_me332)
	{
		{
		}
		
	}
	
	
	public static  double Epsilon;
	
	public static  double NaN;
	
	public static  double Infinity;
	
	public static  double NegativeInfinity;
	
	public static  double E;
	
	public static  double PI;
	
	public static  double HalfPI;
	
	public static  double PI2;
	
	public static  double PI4;
	
	public static  double InvPI;
	
	public static  double Rad2Deg;
	
	public static  double Deg2Rad;
	
	public static  double Px2Em;
	
	public static  double Em2Px;
	
	public static  double Byte2Float;
	
	public static  double Short2Float;
	
	public static  double Long2Float;
	
	public static  double Float2Byte;
	
	public static  double Float2Short;
	
	public static  double Float2Long;
	
	public static   boolean IsPOT(int p_v)
	{
		return ( ( p_v > 0 ) && ( (( p_v & ( p_v - 1 ) )) == 0 ) );
	}
	
	
	public static   int NextPOT(int p_v)
	{
		 -- p_v;
		p_v |= ( p_v >> 1 );
		p_v |= ( p_v >> 2 );
		p_v |= ( p_v >> 4 );
		p_v |= ( p_v >> 8 );
		p_v |= ( p_v >> 16 );
		return  ++ p_v;
	}
	
	
	public static   double Sign(double p_a)
	{
		if (( p_a < 0 )) 
		{
			return -1.0;
		}
		 else 
		{
			return 1.0;
		}
		
	}
	
	
	public static   int SignInt(int p_a)
	{
		if (( p_a < 0 )) 
		{
			return -1;
		}
		 else 
		{
			return 1;
		}
		
	}
	
	
	public static   double Abs(double p_a)
	{
		if (( p_a < 0 )) 
		{
			return  - (p_a) ;
		}
		 else 
		{
			return p_a;
		}
		
	}
	
	
	public static   int AbsInt(int p_a)
	{
		if (( p_a < 0 )) 
		{
			return  - (p_a) ;
		}
		 else 
		{
			return p_a;
		}
		
	}
	
	
	public static   double Clamp(double p_v, double p_min, double p_max)
	{
		if (( p_v <= p_min )) 
		{
			return p_min;
		}
		 else 
		{
			if (( p_v >= p_max )) 
			{
				return p_max;
			}
			 else 
			{
				return p_v;
			}
			
		}
		
	}
	
	
	public static   double Clamp01(double p_v)
	{
		if (( p_v <= 0.0 )) 
		{
			return 0.0;
		}
		 else 
		{
			if (( p_v >= 1.0 )) 
			{
				return 1.0;
			}
			 else 
			{
				return p_v;
			}
			
		}
		
	}
	
	
	public static   int ClampInt(int p_v, int p_min, int p_max)
	{
		return ((int) (( (( p_v <= p_min )) ? (((double) (p_min) )) : (( (( p_v >= p_max )) ? (((double) (p_max) )) : (((double) (p_v) )) )) )) );
	}
	
	
	public static   double Min(double a, double b)
	{
		return java.lang.Math.min(a, b);
	}
	
	
	public static   double MinRange(haxe.root.Array<java.lang.Object> v)
	{
		if (( v.length <= 0 )) 
		{
			return 0.0;
		}
		
		double n = ((double) (haxe.lang.Runtime.toDouble(v.__get(0))) );
		{
			int _g1 = 1;
			int _g = v.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				n = java.lang.Math.min(n, ((double) (haxe.lang.Runtime.toDouble(v.__get(i))) ));
			}
			
		}
		
		return n;
	}
	
	
	public static   double Max(double a, double b)
	{
		return java.lang.Math.max(a, b);
	}
	
	
	public static   double MaxRange(haxe.root.Array<java.lang.Object> v)
	{
		if (( v.length <= 0 )) 
		{
			return 0.0;
		}
		
		double n = ((double) (haxe.lang.Runtime.toDouble(v.__get(0))) );
		{
			int _g1 = 1;
			int _g = v.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				n = java.lang.Math.max(n, ((double) (haxe.lang.Runtime.toDouble(v.__get(i))) ));
			}
			
		}
		
		return n;
	}
	
	
	public static   int MinInt(int a, int b)
	{
		return ((int) (java.lang.Math.min(((double) (a) ), ((double) (b) ))) );
	}
	
	
	public static   int MaxInt(int a, int b)
	{
		return ((int) (java.lang.Math.max(((double) (a) ), ((double) (b) ))) );
	}
	
	
	public static   double Sin(double v)
	{
		return java.lang.Math.sin(v);
	}
	
	
	public static   double Cos(double v)
	{
		return java.lang.Math.cos(v);
	}
	
	
	public static   double Asin(double v)
	{
		return java.lang.Math.asin(v);
	}
	
	
	public static   double Acos(double v)
	{
		return java.lang.Math.acos(v);
	}
	
	
	public static   double Tan(double v)
	{
		return java.lang.Math.tan(v);
	}
	
	
	public static   double ATan(double v)
	{
		return java.lang.Math.atan(v);
	}
	
	
	public static   double ATan2(double y, double x)
	{
		return java.lang.Math.atan2(y, x);
	}
	
	
	public static   double Sqrt(double v)
	{
		return java.lang.Math.sqrt(v);
	}
	
	
	public static   double Pow(double b, double exp)
	{
		return java.lang.Math.pow(b, exp);
	}
	
	
	public static   double Floor(double p_v)
	{
		return ((double) (((int) (p_v) )) );
	}
	
	
	public static   double Ceil(double p_v)
	{
		return ((double) (((int) (( p_v + (( (( p_v < 0 )) ? (-0.9999999) : (0.9999999) )) )) )) );
	}
	
	
	public static   double Round(double p_v)
	{
		return ((double) (((int) (( p_v + (( (( p_v < 0 )) ? (-0.5) : (0.5) )) )) )) );
	}
	
	
	public static   double RoundPlaces(double p_v, java.lang.Object p_decimal_places)
	{
		int __temp_p_decimal_places331 = ( (( p_decimal_places == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_decimal_places)) )) );
		double d = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_decimal_places331) ));
		double __temp_stmt1265 = 0.0;
		{
			double p_v1 = ( p_v * d );
			__temp_stmt1265 = ((double) (((int) (( p_v1 + (( (( p_v1 < 0 )) ? (-0.5) : (0.5) )) )) )) );
		}
		
		return ( __temp_stmt1265 / d );
	}
	
	
	public static   double Lerp(double p_a, double p_b, double p_ratio)
	{
		return ( p_a + ( (( p_b - p_a )) * p_ratio ) );
	}
	
	
	public static   int LerpInt(int p_a, int p_b, double p_ratio)
	{
		double __temp_stmt1266 = 0.0;
		{
			double p_a1 = ((double) (p_a) );
			__temp_stmt1266 = ( p_a1 + ( (( ((double) (p_b) ) - p_a1 )) * p_ratio ) );
		}
		
		return ((int) (__temp_stmt1266) );
	}
	
	
	public static   double Frac(double p_v)
	{
		return ( p_v - java.lang.Math.floor(p_v) );
	}
	
	
	public static   double Loop(double p_v, double p_v0, double p_v1)
	{
		double vv0 = java.lang.Math.min(p_v0, p_v1);
		double vv1 = java.lang.Math.max(p_v0, p_v1);
		double dv = ( vv1 - vv0 );
		if (( dv <= 0 )) 
		{
			return vv0;
		}
		
		double n = ( (( p_v - p_v0 )) / dv );
		double r = 0.0;
		if (( p_v < 0 )) 
		{
			double __temp_stmt1267 = 0.0;
			{
				double p_v2 = 0.0;
				if (( n < 0 )) 
				{
					p_v2 =  - (n) ;
				}
				 else 
				{
					p_v2 = n;
				}
				
				__temp_stmt1267 = ( p_v2 - java.lang.Math.floor(p_v2) );
			}
			
			r = ( 1.0 - __temp_stmt1267 );
		}
		 else 
		{
			r = ( n - java.lang.Math.floor(n) );
		}
		
		return ( p_v0 + ( (( p_v1 - p_v0 )) * r ) );
	}
	
	
	public static   double Linear2Gamma(double p_v)
	{
		return java.lang.Math.pow(p_v, 2.2);
	}
	
	
	public static   double Oscilate(double p_v, double p_v0, double p_v1)
	{
		double __temp_stmt1268 = 0.0;
		{
			double p_a = haxor.math.Mathf.Loop(( p_v - 1.0 ), -1.0, 1.0);
			__temp_stmt1268 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
		}
		
		double w = (  - (__temp_stmt1268)  + 1.0 );
		return ( w + ( (( p_v0 - w )) * p_v1 ) );
	}
	
	
	public static   double WrapAngle(double p_angle)
	{
		if (( p_angle < -360.0 )) 
		{
			return ( 360 + p_angle );
		}
		
		if (( p_angle > 360.0 )) 
		{
			return ( p_angle - 360 );
		}
		
		return p_angle;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.math.Mathf(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.math.Mathf();
	}
	
	
}


