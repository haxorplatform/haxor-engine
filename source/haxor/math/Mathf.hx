package haxor.math;


/**
 * Class with extra Math functionalities.
 * @author Eduardo Pons - eduardo@thelaborat.org
 */

class Mathf 
{
	
    static public inline var Epsilon 			:Float	= 1.0 / 100000.0;
	static public var NaN 				:Float	= Math.NaN;        
	static public var Infinity 			:Float	= Math.POSITIVE_INFINITY;        
	static public var NegativeInfinity	:Float 	= Math.NEGATIVE_INFINITY;       
	static public inline var E 					:Float	= 2.7182818284590452353602874713527;        
	static public inline var PI 				:Float	= 3.1415926535897932384626433832795028841971693993751058;        
	static public inline var HalfPI 			:Float	= 1.5707963267948966192313216916398;        
	static public inline var PI2 				:Float	= 6.283185307179586476925286766559;        
	static public inline var PI4 				:Float	= 12.566370614359172953850573533118;		
	static public inline var InvPI				:Float	= 0.31830988618379067153776752674503;        
	static public inline var Rad2Deg 			:Float	= 57.295779513082320876798154814105;        
	static public inline var Deg2Rad 			:Float	= 0.01745329251994329576923690768489;        
	static public inline var Px2Em 				:Float	= 0.063;        
	static public inline var Em2Px				:Float	= 15.87301587301587;		
	static public inline var Byte2Float			:Float	= 0.00392156863;		
	static public inline var Short2Float		:Float	= 0.0000152587890625;		
	static public inline var Long2Float			:Float	= 0.00000000023283064365386962890625;		
	static public inline var Float2Byte			:Float	= 255.0;		
	static public inline var Float2Short		:Float	= 65536.0;		
	static public inline var Float2Long			:Float	= 4294967296.0;	
	
	static public inline function IsPOT(p_v:Int):Bool { return ((p_v > 0) && ((p_v & (p_v - 1)) == 0)); }
    static public inline function NextPOT(p_v:Int):Int
	{
		--p_v; 
		p_v |= p_v >> 1;  p_v |= p_v >> 2;
		p_v |= p_v >> 4;  p_v |= p_v >> 8;
		p_v |= p_v >> 16;
		return ++p_v;
	}		
	
	static public inline function Sign(p_a:Float):Float  { return (p_a < 0 ? -1.0 : 1.0); }	
	static public inline function SignInt(p_a:Int):Int  { return (p_a < 0 ? -1 : 1); }	
	static public inline function Abs(p_a:Float):Float  { return (p_a < 0 ? -p_a : p_a); }
    static public inline function AbsInt(p_a:Int):Int   { return (p_a < 0 ? -p_a : p_a);  }        
	static public inline function Clamp(p_v : Float,p_min : Float, p_max : Float) : Float { return p_v <= p_min ? p_min : (p_v>=p_max ? p_max : p_v); }
    static public inline function Clamp01(p_v:Float):Float { return Clamp(p_v,0.0,1.0); }
    static public inline function ClampInt(p_v:Int, p_min : Int, p_max : Int)  : Int { return Std.int(p_v <= p_min ? p_min : (p_v>=p_max ? p_max : p_v)); }		
	static public inline function Min(a:Float, b:Float):Float { return Math.min(a, b); }
	static public inline function Max(a:Float, b:Float):Float { return Math.max(a, b); }
	static public inline function MinInt(a:Int, b:Int):Int { return cast Math.min(cast a, cast b); }
	static public inline function MaxInt(a:Int, b:Int):Int { return cast Math.max(cast a, cast b); }
	static public inline function Sin(v:Float):Float { return Math.sin(v);}
	static public inline function Cos(v:Float):Float { return Math.cos(v);}
	static public inline function ASin(v:Float):Float { return Math.asin(v);}
	static public inline function ACos(v:Float):Float { return Math.acos(v);}
	static public inline function Tan(v:Float):Float { return Math.tan(v);}
	static public inline function ATan(v:Float):Float { return Math.atan(v); }
	static public inline function ATan2(y:Float,x:Float):Float { return Math.atan2(y,x);}
	static public inline function Sqrt(v:Float):Float { return Math.sqrt(v);}
	static public inline function Pow(b:Float,exp:Float):Float { return Math.pow(b,exp);}
	
	static public inline function Floor(p_v : Float):Float { return cast Std.int(p_v); }        
	static public inline function Ceil(p_v : Float):Float  { return cast Std.int(p_v + (p_v < 0 ? -0.9999999 : 0.9999999)); }        
	static public inline function Round(p_v:Float):Float { return cast Std.int(p_v + (p_v < 0 ? -0.5 : 0.5)); }		
	static public inline function RoundPlaces(p_v:Float, p_decimal_places:Int = 2):Float 
	{ 
		var d:Float = Math.pow(10,p_decimal_places);
		return Mathf.Round(p_v * d)/d;
	}   
	
	static public inline function Lerp(p_a:Float, p_b:Float, p_ratio : Float):Float { return (p_a + (p_b - p_a) * p_ratio); }		
	static inline public function LerpInt(p_a:Int, p_b:Int, p_ratio : Float):Int { return Std.int(Lerp(cast p_a,cast p_b, p_ratio)); }
	
	static inline public function Frac(p_v:Float):Float { return (p_v - Math.ffloor(p_v)); }
	
	static public function Loop(p_v:Float, p_v0:Float, p_v1:Float):Float 
	{ 
		var vv0 : Float = Math.min(p_v0, p_v1);
		var vv1 : Float = Math.max(p_v0, p_v1);
		var dv : Float = (vv1 - vv0);
		if (dv <= 0) return vv0;
		var n : Float  = (p_v - p_v0) / dv;			
		var r : Float  = p_v < 0 ? 1.0 - Mathf.Frac(Mathf.Abs(n)) : Mathf.Frac(n);			
		return Mathf.Lerp(p_v0, p_v1, r); 
	}
        
	static public inline function Linear2Gamma(p_v:Float):Float { return Math.pow(p_v, 2.2); }
        
	static public inline function Oscilate(p_v:Float, p_v0:Float, p_v1:Float)
	{		
		
		var w:Float = -Mathf.Abs(Loop(p_v - 1.0, -1.0, 1.0)) + 1.0;
		return Mathf.Lerp(w, p_v0, p_v1);
	}

	static public inline function WrapAngle(p_angle:Float):Float
	{
		if (p_angle < 360.0) if (p_angle > -360.0) return p_angle;
		return Mathf.Frac(Mathf.Abs(p_angle) / 360.0) * 360.0;
	}
		
		
			
		
}