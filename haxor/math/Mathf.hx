package haxor.math;
import haxor.context.EngineContext;
import haxor.platform.Types.Float32;


/**
 * Class with extra Math functionalities.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */
class Mathf 
{
	/**
	 * Error margin to use for boundaries tests.
	 */
    static public inline var Epsilon 			:Float32	= 0.0001;
	
	/**
	 * NotANumber constant.
	 */
	static public var NaN 						:Float32	= Math.NaN;        
	
	/**
	 * Infinity constant.
	 */
	static public var Infinity 					:Float32	= Math.POSITIVE_INFINITY;        
	
	/**
	 * Negative Infinity constant.
	 */
	static public var NegativeInfinity			:Float32	= Math.NEGATIVE_INFINITY;       
	
	/**
	 * Euler number constant.
	 */
	static public inline var E 					:Float32	= 2.7182818284590452353602874713527;        
	
	/**
	 * PI constant.
	 */
	static public inline var PI 				:Float32	= 3.1415926535897932384626433832795028841971693993751058;        
	
	/**
	 * PI * 0.5 constant.
	 */
	static public inline var HalfPI 			:Float32	= 1.5707963267948966192313216916398;
	
	/**
	 * PI * 2.0 constant.
	 */
	static public inline var PI2 				:Float32	= 6.283185307179586476925286766559;        
	
	/**
	 * PI * 4.0 constant.
	 */
	static public inline var PI4 				:Float32	= 12.566370614359172953850573533118;		
	
	/**
	 * 1.0 / PI constant.
	 */
	static public inline var InvPI				:Float32	= 0.31830988618379067153776752674503;        
	
	/**
	 * Convert Radians to Degress (angle * Rad2Deg)
	 */
	static public inline var Rad2Deg 			:Float32	= 57.295779513082320876798154814105;        
	
	/**
	 * Convert Degress to Radians (angle * Rad2Deg)
	 */
	static public inline var Deg2Rad 			:Float32	= 0.01745329251994329576923690768489;        
	
	/**
	 * Convert Px to Em unit.
	 */
	static public inline var Px2Em 				:Float32	= 0.063;        
	
	/**
	 * Convert Em to Px unit.
	 */
	static public inline var Em2Px				:Float32	= 15.87301587301587;		
	
	/**
	 * Normalize a [0,255] byte to [0.0,1.0] float.
	 */
	static public inline var Byte2Float			:Float32	= 0.00392156863;		
	
	/**
	 * Normalize a [0,65536] short to [0.0,1.0] float.
	 */
	static public inline var Short2Float		:Float32	= 0.0000152587890625;		
	
	/**
	 * Normalize a [0,4294967296] long to [0.0,1.0] float.
	 */
	static public inline var Long2Float			:Float32	= 0.00000000023283064365386962890625;		
	
	/**
	 * Maps a [0.0,1.0] float to [0,255] byte.
	 */
	static public inline var Float2Byte			:Float32	= 255.0;		
	
	/**
	 * Maps a [0.0,1.0] float to [0,65536] short.
	 */
	static public inline var Float2Short		:Float32	= 65536.0;		
	
	/**
	 * Maps a [0.0,1.0] float to [0,4294967296] long.
	 */
	static public inline var Float2Long			:Float32	= 4294967296.0;	
	
	/**
	 * Returns true if the informed value is Power of Two.
	 * @param	p_v
	 * @return
	 */
	static public inline function IsPOT(p_v:Int):Bool { return ((p_v > 0) && ((p_v & (p_v - 1)) == 0)); }
	
	/**
	 * Returns the Next Power of Two starting at value.
	 * @param	p_v
	 * @return
	 */
    static public inline function NextPOT(p_v:Int):Int
	{
		--p_v; 
		p_v |= p_v >> 1;  p_v |= p_v >> 2;
		p_v |= p_v >> 4;  p_v |= p_v >> 8;
		p_v |= p_v >> 16;
		return ++p_v;
	}		
	
	/**
	 * Returns the signal of the informed value. Signal will be -1.0 if the number is negative or 1.0 if positive.
	 * @param	p_a
	 * @return
	 */
	static public inline function Sign(p_a:Float32):Float32 { return (p_a < 0 ? -1.0 : 1.0); }	
	
	/**
	 * Returns the signal of the informed value in integer form. Signal will be -1.0 if the number is negative or 1.0 if positive.
	 * @param	p_a
	 * @return
	 */
	static public inline function SignInt(p_a:Int):Int  { return (p_a < 0 ? -1 : 1); }
	
	/**
	 * Absolute value.
	 * @param	p_a
	 * @return
	 */
	static public inline function Abs(p_a:Float32):Float32 { return (p_a < 0 ? -p_a : p_a); }
	
	/**
	 * Absolute value converted to integer.
	 * @param	p_a
	 * @return
	 */
    static public inline function AbsInt(p_a:Int):Int   { return (p_a < 0 ? -p_a : p_a);  }  
	
	/**
	 * Clamps the informed value between the min/max range.
	 * @param	p_v
	 * @param	p_min
	 * @param	p_max
	 * @return
	 */
	static public inline function Clamp(p_v : Float32, p_min : Float32, p_max : Float32) : Float32 { return p_v <= p_min ? p_min : (p_v>=p_max ? p_max : p_v); }
	
	/**
	 * Clamps the informed value inside the [0.0,1.0] range.
	 * @param	p_v
	 * @return
	 */
    static public inline function Clamp01(p_v:Float32):Float32{ return Clamp(p_v, 0.0, 1.0); }
	
	/**
	 * Clamps the informed value between the min/max range converted to integer.
	 * @param	p_v
	 * @param	p_min
	 * @param	p_max
	 * @return
	 */
    static public inline function ClampInt(p_v:Int, p_min : Int, p_max : Int)  : Int { return Std.int(p_v <= p_min ? p_min : (p_v>=p_max ? p_max : p_v)); }		
	
	/**
	 * Returns the Min value between the informed numbers.
	 * @param	a
	 * @param	b
	 * @return
	 */
	static public inline function Min(a:Float32, b:Float32):Float32{ return Math.min(a, b); }
	
	/**
	 * Returns the Min value inside the list.
	 * @param	v
	 * @return
	 */
	static public inline function MinRange(v:Array<Float32>):Float32{ if (v.length <= 0) return 0.0; var n:Float32= v[0]; for (i in 1...v.length) n = Math.min(n, v[i]); return n; }
	
	/**
	 * Returns the Max value between the informed numbers.
	 * @param	a
	 * @param	b
	 * @return
	 */
	static public inline function Max(a:Float32, b:Float32):Float32{ return Math.max(a, b); }
	
	/**
	 * Returns the Max value inside the list.
	 * @param	v
	 * @return
	 */
	static public inline function MaxRange(v:Array<Float32>):Float32{ if (v.length <= 0) return 0.0; var n:Float32= v[0]; for (i in 1...v.length) n = Math.max(n, v[i]); return n; }
	
	/**
	 * Returns the Min value between the informed numbers converted to integer.
	 * @param	a
	 * @param	b
	 * @return
	 */
	static public inline function MinInt(a:Int, b:Int):Int { return cast Math.min(cast a, cast b); }
	
	/**
	 * Returns the Max value between the informed numbers converted to integer.
	 * @param	a
	 * @param	b
	 * @return
	 */
	static public inline function MaxInt(a:Int, b:Int):Int { return cast Math.max(cast a, cast b); }
	
	/**
	 * Returns the Sin of the informed angle in radians.
	 * @param	v
	 * @return
	 */
	static public inline function Sin(v:Float32):Float32{ return Math.sin(v); }
	
	/**
	 * Returns the Cos of the informed angle in radians.
	 * @param	v
	 * @return
	 */
	static public inline function Cos(v:Float32):Float32{ return Math.cos(v); }
	
	/**
	 * Returns the ArcSin of the informed angle in radians.
	 * @param	v
	 * @return
	 */
	static public inline function Asin(v:Float32):Float32{ return Math.asin(v); }
	
	/**
	 * Returns the ArcCos of the informed angle in radians.
	 * @param	v
	 * @return
	 */
	static public inline function Acos(v:Float32):Float32{ return Math.acos(v); }
	
	/**
	 * Returns the Tangent of the informed angle in radians.
	 * @param	v
	 * @return
	 */
	static public inline function Tan(v:Float32):Float32{ return Math.tan(v); }
	
	/**
	 * Returns the Arc Tangent of the informed angle in radians.
	 * @param	v
	 * @return
	 */
	static public inline function ATan(v:Float32):Float32{ return Math.atan(v); }
	
	/**
	 * Returns the Arc Tangent of the informed deltas.
	 * @param	v
	 * @return
	 */
	static public inline function ATan2(y:Float32, x:Float32):Float32{ return Math.atan2(y, x); }
	
	/**
	 * Returns the Square root of the informed value.
	 * @param	v
	 * @return
	 */
	static public inline function Sqrt(v:Float32):Float32{ return Math.sqrt(v); }
	
	/**
	 * Returns the base to the exponent Power.
	 * @param	b
	 * @param	exp
	 * @return
	 */
	static public inline function Pow(b:Float32,exp:Float32):Float32{ return Math.pow(b,exp);}
	
	/**
	 * Removes all decimal places of the informed number.
	 * @param	p_v
	 * @return
	 */
	static public inline function Floor(p_v : Float32):Float32{ return cast Std.int(p_v); }        
	
	/**
	 * Increase the number by one if it has any value in its decimal places.
	 * @param	p_v
	 * @return
	 */
	static public inline function Ceil(p_v : Float32):Float32 { return cast Std.int(p_v + (p_v < 0 ? -0.9999999 : 0.9999999)); }        
	
	/**
	 * Returns the inverse of the number avoiding an NaN exception.
	 * @param	p_v
	 * @return
	 */
	static public inline function Inverse(p_v : Float32):Float32 { return Mathf.Abs(p_v) <= 0.0 ? 0.0 : (1.0/p_v); }        
	
	/**
	 * Rounds the informed number to the nearest integer.
	 * @param	p_v
	 * @return
	 */
	static public inline function Round(p_v:Float32):Float32{ return cast Std.int(p_v + (p_v < 0 ? -0.5 : 0.5)); }		
	
	/**
	 * Rounds the number decimal places up to the choosen limit.
	 * @param	p_v
	 * @param	p_decimal_places
	 * @return
	 */
	static public inline function RoundPlaces(p_v:Float32, p_decimal_places:Int = 2):Float32
	{ 
		var d:Float32= Math.pow(10,p_decimal_places);
		return Mathf.Round(p_v * d)/d;
	}   
	
	/**
	 * Linear interpolates the informed numbers.
	 * @param	p_a
	 * @param	p_b
	 * @param	p_ratio
	 * @return
	 */
	static public inline function Lerp(p_a:Float32, p_b:Float32, p_ratio : Float32):Float32 { return (p_a + (p_b - p_a) * p_ratio); }
	
	/**
	 * SmoothStep interpolates 2 values.
	 * Ref: http://en.wikipedia.org/wiki/Smoothstep
	 * @param	p_a
	 * @param	p_b
	 * @param	p_ratio
	 * @return
	 */
	static public inline function SmoothStep(p_a:Float32, p_b:Float32, p_ratio : Float32):Float32 
	{ 
		return (p_a + (p_b - p_a) * (p_ratio * p_ratio * (3.0 - 2.0 * p_ratio)));
	}
	
	/**
	 * Smoothstep 2 values with better continuity.
	 * Ref: http://en.wikipedia.org/wiki/Smoothstep
	 * @param	p_a
	 * @param	p_b
	 * @param	p_ratio
	 * @return
	 */
	static public inline function PerlinStep(p_a:Float32, p_b:Float32, p_ratio : Float32):Float32
	{
		return (p_a + (p_b - p_a) * (p_ratio * p_ratio * p_ratio * (p_ratio * (p_ratio * 6 - 15) + 10)));
	}
	
	/**
	 * Hermite interpolation with a tangent per point.
	 * @param	p_a
	 * @param	p_b
	 * @param	p_ma
	 * @param	p_mb
	 * @param	p_ratio
	 * @return
	 */
	static public inline function Hermite(p_a:Float32, p_b:Float32, p_ma:Float32, p_mb:Float32, p_ratio : Float32):Float32	
	{
		var r  : Float32  = p_ratio;
		var r2 : Float32  = r * r;
		var r3 : Float32  = r2 * r;
		var r32: Float32  = 2.0 * r3;
		var r23: Float32  = 3.0 * r2;
		return ((r32 - r23 + 1.0) * p_a) + ((r3 - (2.0 * r2) + r) * p_ma) + (( -r32 + r23) * p_b) + ((r3 - r2) * p_mb);
	}
	
	
	/**
	 * Linear interpolates the informed numbers and returns their integer form.
	 * @param	p_a
	 * @param	p_b
	 * @param	p_ratio
	 * @return
	 */
	static inline public function LerpInt(p_a:Int, p_b:Int, p_ratio : Float32):Int { return Std.int(Lerp(cast p_a, cast p_b, p_ratio)); }
	
	/**
	 * Smoothstep interpolates the informed numbers and returns their integer form.
	 * @param	p_a
	 * @param	p_b
	 * @param	p_ratio
	 * @return
	 */
	static inline public function SmoothStepInt(p_a:Int, p_b:Int, p_ratio : Float32):Int { return Std.int(SmoothStep(cast p_a, cast p_b, p_ratio)); }
	
	/**
	 * Smoothstep interpolates the informed numbers and returns their integer form.
	 * @param	p_a
	 * @param	p_b
	 * @param	p_ratio
	 * @return
	 */
	static inline public function PerlinStepInt(p_a:Int, p_b:Int, p_ratio : Float32):Int { return Std.int(PerlinStep(cast p_a,cast p_b, p_ratio)); }
	
	/**
	 * Returns only the decimal places of the informed number.
	 * @param	p_v
	 * @return
	 */
	static inline public function Frac(p_v:Float32,p_signed:Bool=false):Float32 { var f : Float32 = (Mathf.Abs(p_v) - Math.ffloor(Mathf.Abs(p_v))); return p_signed ? (p_v < 0.0 ? -f : f) : f; }
	
	/**
	 * Maps the informed number to inside the interval.
	 * @param	p_v
	 * @param	p_v0
	 * @param	p_v1
	 * @return
	 */
	static public function Loop(p_v:Float32, p_v0:Float32, p_v1:Float32):Float32
	{ 
		var vv0 : Float32 = Math.min(p_v0, p_v1);
		var vv1 : Float32 = Math.max(p_v0, p_v1);
		var dv : Float32 = (vv1 - vv0);
		if (dv <= 0) return vv0;
		var n : Float32  = (p_v - p_v0) / dv;			
		var r : Float32  = p_v < p_v0 ? (1.0 - Mathf.Frac(n)) : Mathf.Frac(n);
		return Mathf.Lerp(p_v0, p_v1, r); 
	}
        
	/**
	 * Maps the luminance value from linear to gamma space.
	 * @param	p_v
	 * @return
	 */
	static public inline function Linear2Gamma(p_v:Float32):Float32{ return Math.pow(p_v, 2.2); }
        
	/**
	 * Maps the informed value inside the interval but going back and forth instead of wrapping it.
	 * @param	p_v
	 * @param	p_v0
	 * @param	p_v1
	 */
	static public inline function Oscilate(p_v:Float32, p_v0:Float32, p_v1:Float32)
	{	
		var vv0 : Float32 = Math.min(p_v0, p_v1);
		var vv1 : Float32 = Math.max(p_v0, p_v1);
		var dv : Float32 = (vv1 - vv0);
		if (dv <= 0) return vv0;
		var n : Float32  = (p_v - p_v0) / dv;
		var r:Float32= -Mathf.Abs(Loop(n - 1.0, -1.0, 1.0)) + 1.0;
		return Mathf.Lerp(p_v0, p_v1,r);
	}

	/**
	 * Wraps the angle in degress inside the [-360,360] range.
	 * @param	p_angle
	 * @return
	 */
	static public function WrapAngle(p_angle:Float32):Float32
	{
		var a : Float32 = Mathf.Frac(p_angle / 360.0,true) * 360.0;	
		return a;		
	}
		
		
		
}