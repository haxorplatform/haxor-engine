package haxor.math;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Color extends haxe.lang.HxObject
{
	public    Color(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Color(java.lang.Object p_r, java.lang.Object p_g, java.lang.Object p_b, java.lang.Object p_a)
	{
		haxor.math.Color.__hx_ctor_haxor_math_Color(this, p_r, p_g, p_b, p_a);
	}
	
	
	public static   void __hx_ctor_haxor_math_Color(haxor.math.Color __temp_me160433, java.lang.Object p_r, java.lang.Object p_g, java.lang.Object p_b, java.lang.Object p_a)
	{
		double __temp_p_a160432 = ( (( p_a == null )) ? (((double) (1) )) : (((double) (haxe.lang.Runtime.toDouble(p_a)) )) );
		double __temp_p_b160431 = ( (( p_b == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_b)) )) );
		double __temp_p_g160430 = ( (( p_g == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_g)) )) );
		double __temp_p_r160429 = ( (( p_r == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_r)) )) );
		__temp_me160433.r = __temp_p_r160429;
		__temp_me160433.g = __temp_p_g160430;
		__temp_me160433.b = __temp_p_b160431;
		__temp_me160433.a = __temp_p_a160432;
	}
	
	
	public static  haxor.math.Color temp;
	
	public static   haxor.math.Color get_temp()
	{
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			return _this.m_c.__get(_this.m_nc = ( (( _this.m_nc + 1 )) % _this.m_c.length ));
		}
		
	}
	
	
	public static  haxor.math.Color red;
	
	public static   haxor.math.Color get_red()
	{
		return new haxor.math.Color(((java.lang.Object) (1.0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Color yellow;
	
	public static   haxor.math.Color get_yellow()
	{
		return new haxor.math.Color(((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Color green;
	
	public static   haxor.math.Color get_green()
	{
		return new haxor.math.Color(((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Color cyan;
	
	public static   haxor.math.Color get_cyan()
	{
		return new haxor.math.Color(((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Color blue;
	
	public static   haxor.math.Color get_blue()
	{
		return new haxor.math.Color(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Color magenta;
	
	public static   haxor.math.Color get_magenta()
	{
		return new haxor.math.Color(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Color black;
	
	public static   haxor.math.Color get_black()
	{
		return new haxor.math.Color(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Color white;
	
	public static   haxor.math.Color get_white()
	{
		return new haxor.math.Color(((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Color empty;
	
	public static   haxor.math.Color get_empty()
	{
		return new haxor.math.Color(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
	}
	
	
	public static  haxor.math.Color gray10;
	
	public static   haxor.math.Color get_gray10()
	{
		return new haxor.math.Color(((java.lang.Object) (0.1) ), ((java.lang.Object) (0.1) ), ((java.lang.Object) (0.1) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Color gray25;
	
	public static   haxor.math.Color get_gray25()
	{
		return new haxor.math.Color(((java.lang.Object) (0.25) ), ((java.lang.Object) (0.25) ), ((java.lang.Object) (0.25) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Color gray50;
	
	public static   haxor.math.Color get_gray50()
	{
		return new haxor.math.Color(((java.lang.Object) (0.5) ), ((java.lang.Object) (0.5) ), ((java.lang.Object) (0.5) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Color gray75;
	
	public static   haxor.math.Color get_gray75()
	{
		return new haxor.math.Color(((java.lang.Object) (0.75) ), ((java.lang.Object) (0.75) ), ((java.lang.Object) (0.75) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Color gray90;
	
	public static   haxor.math.Color get_gray90()
	{
		return new haxor.math.Color(((java.lang.Object) (0.9) ), ((java.lang.Object) (0.9) ), ((java.lang.Object) (0.9) ), ((java.lang.Object) (1) ));
	}
	
	
	public static   haxor.math.Color FromHex(java.lang.String p_hex)
	{
		haxor.math.Color c = new haxor.math.Color(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		if (( p_hex.length() == 10 )) 
		{
			c.set_argb(((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(p_hex))) ));
		}
		 else 
		{
			c.set_rgb(((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(p_hex))) ));
		}
		
		return c;
	}
	
	
	public static   haxor.math.Color FromBytes(java.lang.Object p_r, java.lang.Object p_g, java.lang.Object p_b, java.lang.Object p_a)
	{
		double __temp_p_a160428 = ( (( p_a == null )) ? (((double) (255.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_a)) )) );
		double __temp_p_b160427 = ( (( p_b == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_b)) )) );
		double __temp_p_g160426 = ( (( p_g == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_g)) )) );
		double __temp_p_r160425 = ( (( p_r == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_r)) )) );
		return new haxor.math.Color(((java.lang.Object) (( __temp_p_r160425 * 0.00392156863 )) ), ((java.lang.Object) (( __temp_p_g160426 * 0.00392156863 )) ), ((java.lang.Object) (( __temp_p_b160427 * 0.00392156863 )) ), ((java.lang.Object) (( __temp_p_a160428 * 0.00392156863 )) ));
	}
	
	
	public static   haxor.math.Color Lerp(haxor.math.Color a, haxor.math.Color b, double r)
	{
		double __temp_stmt161074 = 0.0;
		{
			double p_a = a.r;
			__temp_stmt161074 = ( p_a + ( (( b.r - p_a )) * r ) );
		}
		
		double __temp_stmt161075 = 0.0;
		{
			double p_a1 = a.g;
			__temp_stmt161075 = ( p_a1 + ( (( b.g - p_a1 )) * r ) );
		}
		
		double __temp_stmt161076 = 0.0;
		{
			double p_a2 = a.b;
			__temp_stmt161076 = ( p_a2 + ( (( b.b - p_a2 )) * r ) );
		}
		
		double __temp_stmt161077 = 0.0;
		{
			double p_a3 = a.a;
			__temp_stmt161077 = ( p_a3 + ( (( b.a - p_a3 )) * r ) );
		}
		
		return new haxor.math.Color(((java.lang.Object) (__temp_stmt161074) ), ((java.lang.Object) (__temp_stmt161075) ), ((java.lang.Object) (__temp_stmt161076) ), ((java.lang.Object) (__temp_stmt161077) ));
	}
	
	
	public static   haxor.math.Color Sample(haxe.root.Array<haxor.math.Color> g, double r)
	{
		double pos = ((double) (( g.length - 1 )) );
		pos *= ( r * 0.9999 );
		int i0 = ((int) (pos) );
		int i1 = ( (( i0 + 1 )) % g.length );
		r = ( pos - java.lang.Math.floor(pos) );
		haxor.math.Color c0 = g.__get(i0);
		haxor.math.Color c1 = g.__get(i1);
		return haxor.math.Color.Lerp(c0, c1, r);
	}
	
	
	public static   haxor.math.Color Parse(java.lang.String p_data, java.lang.String p_delimiter)
	{
		if (( p_delimiter == null )) 
		{
			p_delimiter = " ";
		}
		
		haxe.root.Array<java.lang.String> tk = haxe.lang.StringExt.split(p_data, p_delimiter);
		return new haxor.math.Color(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) )).Set(haxe.root.Std.parseFloat(tk.__get(0).trim()), haxe.root.Std.parseFloat(tk.__get(1).trim()), haxe.root.Std.parseFloat(tk.__get(2).trim()), haxe.root.Std.parseFloat(tk.__get(3).trim()));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.math.Color(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.math.Color(((java.lang.Object) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ), ((java.lang.Object) (arr.__get(2)) ), ((java.lang.Object) (arr.__get(3)) ));
	}
	
	
	public  haxor.math.Color clone;
	
	public final   haxor.math.Color get_clone()
	{
		return new haxor.math.Color(((java.lang.Object) (this.r) ), ((java.lang.Object) (this.g) ), ((java.lang.Object) (this.b) ), ((java.lang.Object) (this.a) ));
	}
	
	
	public  haxor.math.Vector3 xyz;
	
	public final   haxor.math.Vector3 get_xyz()
	{
		return new haxor.math.Vector3(((java.lang.Object) (this.r) ), ((java.lang.Object) (this.g) ), ((java.lang.Object) (this.b) ));
	}
	
	
	public  haxor.math.Vector4 xyzw;
	
	public final   haxor.math.Vector4 get_xyzw()
	{
		return new haxor.math.Vector4(((java.lang.Object) (this.r) ), ((java.lang.Object) (this.g) ), ((java.lang.Object) (this.b) ), ((java.lang.Object) (this.a) ));
	}
	
	
	
	
	public   int get_argb()
	{
		int rb = ((int) (( this.r * 255.0 )) );
		int gb = ((int) (( this.g * 255.0 )) );
		int bb = ((int) (( this.b * 255.0 )) );
		int ab = ((int) (( this.a * 255.0 )) );
		return ( ( ( ( ab << 24 ) | ( rb << 16 ) ) | ( gb << 8 ) ) | bb );
	}
	
	
	public   int set_argb(int v)
	{
		this.a = ((double) (( (( ( v >> 24 ) & 255 )) * 0.00392156863 )) );
		this.g = ((double) (( (( ( v >> 16 ) & 255 )) * 0.00392156863 )) );
		this.b = ((double) (( (( ( v >> 8 ) & 255 )) * 0.00392156863 )) );
		this.r = ((double) (( (( v & 255 )) * 0.00392156863 )) );
		return v;
	}
	
	
	
	
	public final   java.lang.String get_css()
	{
		return ( ( ( ( ( ( ( ( "rgba(" + ((int) (( this.r * 255 )) ) ) + "," ) + ((int) (( this.g * 255 )) ) ) + "," ) + ((int) (( this.b * 255 )) ) ) + "," ) + haxe.lang.Runtime.toString(this.a) ) + ")" );
	}
	
	
	
	
	public   int get_rgba()
	{
		int rb = ((int) (( this.r * 255.0 )) );
		int gb = ((int) (( this.g * 255.0 )) );
		int bb = ((int) (( this.b * 255.0 )) );
		int ab = ((int) (( this.a * 255.0 )) );
		return ( ( ( ( rb << 24 ) | ( gb << 16 ) ) | ( bb << 8 ) ) | ab );
	}
	
	
	public   int set_rgba(int v)
	{
		this.r = ((double) (( (( ( v >> 24 ) & 255 )) * 0.00392156863 )) );
		this.g = ((double) (( (( ( v >> 16 ) & 255 )) * 0.00392156863 )) );
		this.b = ((double) (( (( ( v >> 8 ) & 255 )) * 0.00392156863 )) );
		this.a = ((double) (( (( v & 255 )) * 0.00392156863 )) );
		return v;
	}
	
	
	
	
	public   int get_rgb()
	{
		int rb = ((int) (( this.r * 255.0 )) );
		int gb = ((int) (( this.g * 255.0 )) );
		int bb = ((int) (( this.b * 255.0 )) );
		return ( ( ( rb << 16 ) | ( gb << 8 ) ) | bb );
	}
	
	
	public   int set_rgb(int v)
	{
		this.r = ((double) (( (( ( v >> 16 ) & 255 )) * 0.00392156863 )) );
		this.g = ((double) (( (( ( v >> 8 ) & 255 )) * 0.00392156863 )) );
		this.b = ((double) (( (( v & 255 )) * 0.00392156863 )) );
		return v;
	}
	
	
	public  double luminance;
	
	public final   double get_luminance()
	{
		return ( ( ( this.r * 0.3 ) + ( this.g * 0.59 ) ) + ( this.b * 0.11 ) );
	}
	
	
	public  haxor.math.Color negative;
	
	public final   haxor.math.Color get_negative()
	{
		return new haxor.math.Color(((java.lang.Object) (( 1.0 - this.r )) ), ((java.lang.Object) (( 1.0 - this.g )) ), ((java.lang.Object) (( 1.0 - this.b )) ), ((java.lang.Object) (( 1.0 - this.a )) ));
	}
	
	
	public  double r;
	
	public  double g;
	
	public  double b;
	
	public  double a;
	
	public   haxor.math.Color Set(java.lang.Object p_r, java.lang.Object p_g, java.lang.Object p_b, java.lang.Object p_a)
	{
		double __temp_p_a160423 = ( (( p_a == null )) ? (((double) (1) )) : (((double) (haxe.lang.Runtime.toDouble(p_a)) )) );
		double __temp_p_b160422 = ( (( p_b == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_b)) )) );
		double __temp_p_g160421 = ( (( p_g == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_g)) )) );
		double __temp_p_r160420 = ( (( p_r == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_r)) )) );
		this.r = __temp_p_r160420;
		this.g = __temp_p_g160421;
		this.b = __temp_p_b160422;
		this.a = __temp_p_a160423;
		return this;
	}
	
	
	public   haxor.math.Color Set3(haxor.math.Vector3 v)
	{
		this.r = v.x;
		this.g = v.y;
		this.b = v.z;
		return this;
	}
	
	
	public   haxor.math.Color Set4(haxor.math.Vector4 v)
	{
		this.r = v.x;
		this.g = v.y;
		this.b = v.z;
		this.a = v.w;
		return this;
	}
	
	
	public   haxor.math.Color SetColor(haxor.math.Color p_color)
	{
		this.r = p_color.r;
		this.g = p_color.g;
		this.b = p_color.b;
		this.a = p_color.a;
		return this;
	}
	
	
	public   double Get(int p)
	{
		if (( p == 0 )) 
		{
			return this.r;
		}
		 else 
		{
			if (( p == 1 )) 
			{
				return this.g;
			}
			 else 
			{
				if (( p == 2 )) 
				{
					return this.b;
				}
				 else 
				{
					return this.a;
				}
				
			}
			
		}
		
	}
	
	
	public   haxor.math.Color Add(haxor.math.Color p_v)
	{
		this.r += p_v.r;
		this.g += p_v.g;
		this.b += p_v.b;
		this.a += p_v.a;
		return this;
	}
	
	
	public   haxor.math.Color Sub(haxor.math.Color p_v)
	{
		this.r -= p_v.r;
		this.g -= p_v.g;
		this.b -= p_v.b;
		this.a -= p_v.a;
		return this;
	}
	
	
	public   haxor.math.Color Multiply(haxor.math.Color p_v)
	{
		this.r *= p_v.r;
		this.g *= p_v.g;
		this.b *= p_v.b;
		this.a *= p_v.a;
		return this;
	}
	
	
	public   haxor.math.Color MultiplyRGB(haxor.math.Color p_v)
	{
		this.r *= p_v.r;
		this.g *= p_v.g;
		this.b *= p_v.b;
		return this;
	}
	
	
	public   haxor.math.Color Scale(double p_s)
	{
		this.r *= p_s;
		this.g *= p_s;
		this.b *= p_s;
		this.a *= p_s;
		return this;
	}
	
	
	public   haxor.math.Color ScaleRGB(double p_s)
	{
		this.r *= p_s;
		this.g *= p_s;
		this.b *= p_s;
		return this;
	}
	
	
	public   haxe.root.Array<java.lang.Object> ToArray()
	{
		return new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (this.r) ), ((java.lang.Object) (this.g) ), ((java.lang.Object) (this.b) ), ((java.lang.Object) (this.a) )});
	}
	
	
	public   java.lang.String ToString(java.lang.Object p_places)
	{
		int __temp_p_places160424 = ( (( p_places == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_places)) )) );
		double __temp_stmt161061 = 0.0;
		{
			double d = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places160424) ));
			double __temp_stmt161062 = 0.0;
			{
				double p_v = ( this.r * d );
				__temp_stmt161062 = ((double) (((int) (( p_v + (( (( p_v < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt161061 = ( __temp_stmt161062 / d );
		}
		
		double __temp_stmt161063 = 0.0;
		{
			double d1 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places160424) ));
			double __temp_stmt161064 = 0.0;
			{
				double p_v1 = ( this.g * d1 );
				__temp_stmt161064 = ((double) (((int) (( p_v1 + (( (( p_v1 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt161063 = ( __temp_stmt161064 / d1 );
		}
		
		double __temp_stmt161065 = 0.0;
		{
			double d2 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places160424) ));
			double __temp_stmt161066 = 0.0;
			{
				double p_v2 = ( this.b * d2 );
				__temp_stmt161066 = ((double) (((int) (( p_v2 + (( (( p_v2 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt161065 = ( __temp_stmt161066 / d2 );
		}
		
		double __temp_stmt161067 = 0.0;
		{
			double d3 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places160424) ));
			double __temp_stmt161068 = 0.0;
			{
				double p_v3 = ( this.a * d3 );
				__temp_stmt161068 = ((double) (((int) (( p_v3 + (( (( p_v3 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt161067 = ( __temp_stmt161068 / d3 );
		}
		
		return ( ( ( ( ( ( ( ( "[" + haxe.lang.Runtime.toString(__temp_stmt161061) ) + "," ) + haxe.lang.Runtime.toString(__temp_stmt161063) ) + "," ) + haxe.lang.Runtime.toString(__temp_stmt161065) ) + "," ) + haxe.lang.Runtime.toString(__temp_stmt161067) ) + "]" );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161069 = true;
			switch (field.hashCode())
			{
				case 97:
				{
					if (field.equals("a")) 
					{
						__temp_executeDef161069 = false;
						this.a = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3002572:
				{
					if (field.equals("argb")) 
					{
						__temp_executeDef161069 = false;
						this.set_argb(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef161069 = false;
						this.b = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3498292:
				{
					if (field.equals("rgba")) 
					{
						__temp_executeDef161069 = false;
						this.set_rgba(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 103:
				{
					if (field.equals("g")) 
					{
						__temp_executeDef161069 = false;
						this.g = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 112845:
				{
					if (field.equals("rgb")) 
					{
						__temp_executeDef161069 = false;
						this.set_rgb(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 114:
				{
					if (field.equals("r")) 
					{
						__temp_executeDef161069 = false;
						this.r = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1178092792:
				{
					if (field.equals("luminance")) 
					{
						__temp_executeDef161069 = false;
						this.luminance = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161069) 
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
			boolean __temp_executeDef161070 = true;
			switch (field.hashCode())
			{
				case 97:
				{
					if (field.equals("a")) 
					{
						__temp_executeDef161070 = false;
						this.a = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef161070 = false;
						this.clone = ((haxor.math.Color) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef161070 = false;
						this.b = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 119193:
				{
					if (field.equals("xyz")) 
					{
						__temp_executeDef161070 = false;
						this.xyz = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 103:
				{
					if (field.equals("g")) 
					{
						__temp_executeDef161070 = false;
						this.g = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3695102:
				{
					if (field.equals("xyzw")) 
					{
						__temp_executeDef161070 = false;
						this.xyzw = ((haxor.math.Vector4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 114:
				{
					if (field.equals("r")) 
					{
						__temp_executeDef161070 = false;
						this.r = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3002572:
				{
					if (field.equals("argb")) 
					{
						__temp_executeDef161070 = false;
						this.set_argb(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 921111605:
				{
					if (field.equals("negative")) 
					{
						__temp_executeDef161070 = false;
						this.negative = ((haxor.math.Color) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3498292:
				{
					if (field.equals("rgba")) 
					{
						__temp_executeDef161070 = false;
						this.set_rgba(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 1178092792:
				{
					if (field.equals("luminance")) 
					{
						__temp_executeDef161070 = false;
						this.luminance = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 112845:
				{
					if (field.equals("rgb")) 
					{
						__temp_executeDef161070 = false;
						this.set_rgb(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161070) 
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
			boolean __temp_executeDef161071 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef161071 = false;
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
				
				
				case 482271358:
				{
					if (field.equals("ToArray")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToArray"))) );
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_clone"))) );
					}
					
					break;
				}
				
				
				case -827221181:
				{
					if (field.equals("ScaleRGB")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ScaleRGB"))) );
					}
					
					break;
				}
				
				
				case 119193:
				{
					if (field.equals("xyz")) 
					{
						__temp_executeDef161071 = false;
						if (handleProperties) 
						{
							return this.get_xyz();
						}
						 else 
						{
							return this.xyz;
						}
						
					}
					
					break;
				}
				
				
				case 79698218:
				{
					if (field.equals("Scale")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Scale"))) );
					}
					
					break;
				}
				
				
				case -74779344:
				{
					if (field.equals("get_xyz")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_xyz"))) );
					}
					
					break;
				}
				
				
				case -2064065559:
				{
					if (field.equals("MultiplyRGB")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("MultiplyRGB"))) );
					}
					
					break;
				}
				
				
				case 3695102:
				{
					if (field.equals("xyzw")) 
					{
						__temp_executeDef161071 = false;
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
				
				
				case 718473796:
				{
					if (field.equals("Multiply")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Multiply"))) );
					}
					
					break;
				}
				
				
				case 1976807751:
				{
					if (field.equals("get_xyzw")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_xyzw"))) );
					}
					
					break;
				}
				
				
				case 83488:
				{
					if (field.equals("Sub")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Sub"))) );
					}
					
					break;
				}
				
				
				case 3002572:
				{
					if (field.equals("argb")) 
					{
						__temp_executeDef161071 = false;
						return this.get_argb();
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add"))) );
					}
					
					break;
				}
				
				
				case 1976115221:
				{
					if (field.equals("get_argb")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_argb"))) );
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Get"))) );
					}
					
					break;
				}
				
				
				case 1415002761:
				{
					if (field.equals("set_argb")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_argb"))) );
					}
					
					break;
				}
				
				
				case 1454199873:
				{
					if (field.equals("SetColor")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetColor"))) );
					}
					
					break;
				}
				
				
				case 98819:
				{
					if (field.equals("css")) 
					{
						__temp_executeDef161071 = false;
						return this.get_css();
					}
					
					break;
				}
				
				
				case 2573362:
				{
					if (field.equals("Set4")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set4"))) );
					}
					
					break;
				}
				
				
				case -74799718:
				{
					if (field.equals("get_css")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_css"))) );
					}
					
					break;
				}
				
				
				case 2573361:
				{
					if (field.equals("Set3")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set3"))) );
					}
					
					break;
				}
				
				
				case 3498292:
				{
					if (field.equals("rgba")) 
					{
						__temp_executeDef161071 = false;
						return this.get_rgba();
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 1976610941:
				{
					if (field.equals("get_rgba")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_rgba"))) );
					}
					
					break;
				}
				
				
				case 97:
				{
					if (field.equals("a")) 
					{
						__temp_executeDef161071 = false;
						return this.a;
					}
					
					break;
				}
				
				
				case 1415498481:
				{
					if (field.equals("set_rgba")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_rgba"))) );
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef161071 = false;
						return this.b;
					}
					
					break;
				}
				
				
				case 112845:
				{
					if (field.equals("rgb")) 
					{
						__temp_executeDef161071 = false;
						return this.get_rgb();
					}
					
					break;
				}
				
				
				case 103:
				{
					if (field.equals("g")) 
					{
						__temp_executeDef161071 = false;
						return this.g;
					}
					
					break;
				}
				
				
				case -74785692:
				{
					if (field.equals("get_rgb")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_rgb"))) );
					}
					
					break;
				}
				
				
				case 114:
				{
					if (field.equals("r")) 
					{
						__temp_executeDef161071 = false;
						return this.r;
					}
					
					break;
				}
				
				
				case 1985323888:
				{
					if (field.equals("set_rgb")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_rgb"))) );
					}
					
					break;
				}
				
				
				case -1001943298:
				{
					if (field.equals("get_negative")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_negative"))) );
					}
					
					break;
				}
				
				
				case 1178092792:
				{
					if (field.equals("luminance")) 
					{
						__temp_executeDef161071 = false;
						if (handleProperties) 
						{
							return this.get_luminance();
						}
						 else 
						{
							return this.luminance;
						}
						
					}
					
					break;
				}
				
				
				case 921111605:
				{
					if (field.equals("negative")) 
					{
						__temp_executeDef161071 = false;
						if (handleProperties) 
						{
							return this.get_negative();
						}
						 else 
						{
							return this.negative;
						}
						
					}
					
					break;
				}
				
				
				case 1692932943:
				{
					if (field.equals("get_luminance")) 
					{
						__temp_executeDef161071 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_luminance"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161071) 
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
			boolean __temp_executeDef161072 = true;
			switch (field.hashCode())
			{
				case 97:
				{
					if (field.equals("a")) 
					{
						__temp_executeDef161072 = false;
						return this.a;
					}
					
					break;
				}
				
				
				case 3002572:
				{
					if (field.equals("argb")) 
					{
						__temp_executeDef161072 = false;
						return ((double) (this.get_argb()) );
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef161072 = false;
						return this.b;
					}
					
					break;
				}
				
				
				case 3498292:
				{
					if (field.equals("rgba")) 
					{
						__temp_executeDef161072 = false;
						return ((double) (this.get_rgba()) );
					}
					
					break;
				}
				
				
				case 103:
				{
					if (field.equals("g")) 
					{
						__temp_executeDef161072 = false;
						return this.g;
					}
					
					break;
				}
				
				
				case 112845:
				{
					if (field.equals("rgb")) 
					{
						__temp_executeDef161072 = false;
						return ((double) (this.get_rgb()) );
					}
					
					break;
				}
				
				
				case 114:
				{
					if (field.equals("r")) 
					{
						__temp_executeDef161072 = false;
						return this.r;
					}
					
					break;
				}
				
				
				case 1178092792:
				{
					if (field.equals("luminance")) 
					{
						__temp_executeDef161072 = false;
						if (handleProperties) 
						{
							return this.get_luminance();
						}
						 else 
						{
							return this.luminance;
						}
						
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161072) 
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
			boolean __temp_executeDef161073 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef161073 = false;
						return this.ToString(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef161073 = false;
						return this.get_clone();
					}
					
					break;
				}
				
				
				case 482271358:
				{
					if (field.equals("ToArray")) 
					{
						__temp_executeDef161073 = false;
						return this.ToArray();
					}
					
					break;
				}
				
				
				case -74779344:
				{
					if (field.equals("get_xyz")) 
					{
						__temp_executeDef161073 = false;
						return this.get_xyz();
					}
					
					break;
				}
				
				
				case -827221181:
				{
					if (field.equals("ScaleRGB")) 
					{
						__temp_executeDef161073 = false;
						return this.ScaleRGB(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1976807751:
				{
					if (field.equals("get_xyzw")) 
					{
						__temp_executeDef161073 = false;
						return this.get_xyzw();
					}
					
					break;
				}
				
				
				case 79698218:
				{
					if (field.equals("Scale")) 
					{
						__temp_executeDef161073 = false;
						return this.Scale(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1976115221:
				{
					if (field.equals("get_argb")) 
					{
						__temp_executeDef161073 = false;
						return this.get_argb();
					}
					
					break;
				}
				
				
				case -2064065559:
				{
					if (field.equals("MultiplyRGB")) 
					{
						__temp_executeDef161073 = false;
						return this.MultiplyRGB(((haxor.math.Color) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1415002761:
				{
					if (field.equals("set_argb")) 
					{
						__temp_executeDef161073 = false;
						return this.set_argb(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 718473796:
				{
					if (field.equals("Multiply")) 
					{
						__temp_executeDef161073 = false;
						return this.Multiply(((haxor.math.Color) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -74799718:
				{
					if (field.equals("get_css")) 
					{
						__temp_executeDef161073 = false;
						return this.get_css();
					}
					
					break;
				}
				
				
				case 83488:
				{
					if (field.equals("Sub")) 
					{
						__temp_executeDef161073 = false;
						return this.Sub(((haxor.math.Color) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1976610941:
				{
					if (field.equals("get_rgba")) 
					{
						__temp_executeDef161073 = false;
						return this.get_rgba();
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef161073 = false;
						return this.Add(((haxor.math.Color) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1415498481:
				{
					if (field.equals("set_rgba")) 
					{
						__temp_executeDef161073 = false;
						return this.set_rgba(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef161073 = false;
						return this.Get(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -74785692:
				{
					if (field.equals("get_rgb")) 
					{
						__temp_executeDef161073 = false;
						return this.get_rgb();
					}
					
					break;
				}
				
				
				case 1454199873:
				{
					if (field.equals("SetColor")) 
					{
						__temp_executeDef161073 = false;
						return this.SetColor(((haxor.math.Color) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1985323888:
				{
					if (field.equals("set_rgb")) 
					{
						__temp_executeDef161073 = false;
						return this.set_rgb(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 2573362:
				{
					if (field.equals("Set4")) 
					{
						__temp_executeDef161073 = false;
						return this.Set4(((haxor.math.Vector4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1692932943:
				{
					if (field.equals("get_luminance")) 
					{
						__temp_executeDef161073 = false;
						return this.get_luminance();
					}
					
					break;
				}
				
				
				case 2573361:
				{
					if (field.equals("Set3")) 
					{
						__temp_executeDef161073 = false;
						return this.Set3(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1001943298:
				{
					if (field.equals("get_negative")) 
					{
						__temp_executeDef161073 = false;
						return this.get_negative();
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef161073 = false;
						return this.Set(dynargs.__get(0), dynargs.__get(1), dynargs.__get(2), dynargs.__get(3));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161073) 
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
		baseArr.push("a");
		baseArr.push("b");
		baseArr.push("g");
		baseArr.push("r");
		baseArr.push("negative");
		baseArr.push("luminance");
		baseArr.push("rgb");
		baseArr.push("rgba");
		baseArr.push("css");
		baseArr.push("argb");
		baseArr.push("xyzw");
		baseArr.push("xyz");
		baseArr.push("clone");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


