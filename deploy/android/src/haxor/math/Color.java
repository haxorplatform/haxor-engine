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
	
	
	public static   void __hx_ctor_haxor_math_Color(haxor.math.Color __temp_me33852, java.lang.Object p_r, java.lang.Object p_g, java.lang.Object p_b, java.lang.Object p_a)
	{
		double __temp_p_a33851 = ( (( p_a == null )) ? (((double) (1) )) : (((double) (haxe.lang.Runtime.toDouble(p_a)) )) );
		double __temp_p_b33850 = ( (( p_b == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_b)) )) );
		double __temp_p_g33849 = ( (( p_g == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_g)) )) );
		double __temp_p_r33848 = ( (( p_r == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_r)) )) );
		__temp_me33852.r = __temp_p_r33848;
		__temp_me33852.g = __temp_p_g33849;
		__temp_me33852.b = __temp_p_b33850;
		__temp_me33852.a = __temp_p_a33851;
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
		double __temp_p_a33847 = ( (( p_a == null )) ? (((double) (255.0) )) : (((double) (haxe.lang.Runtime.toDouble(p_a)) )) );
		double __temp_p_b33846 = ( (( p_b == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_b)) )) );
		double __temp_p_g33845 = ( (( p_g == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_g)) )) );
		double __temp_p_r33844 = ( (( p_r == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_r)) )) );
		return new haxor.math.Color(((java.lang.Object) (( __temp_p_r33844 * 0.00392156863 )) ), ((java.lang.Object) (( __temp_p_g33845 * 0.00392156863 )) ), ((java.lang.Object) (( __temp_p_b33846 * 0.00392156863 )) ), ((java.lang.Object) (( __temp_p_a33847 * 0.00392156863 )) ));
	}
	
	
	public static   haxor.math.Color Lerp(haxor.math.Color a, haxor.math.Color b, double r)
	{
		double __temp_stmt34059 = 0.0;
		{
			double p_a = a.r;
			__temp_stmt34059 = ( p_a + ( (( b.r - p_a )) * r ) );
		}
		
		double __temp_stmt34060 = 0.0;
		{
			double p_a1 = a.g;
			__temp_stmt34060 = ( p_a1 + ( (( b.g - p_a1 )) * r ) );
		}
		
		double __temp_stmt34061 = 0.0;
		{
			double p_a2 = a.b;
			__temp_stmt34061 = ( p_a2 + ( (( b.b - p_a2 )) * r ) );
		}
		
		double __temp_stmt34062 = 0.0;
		{
			double p_a3 = a.a;
			__temp_stmt34062 = ( p_a3 + ( (( b.a - p_a3 )) * r ) );
		}
		
		return new haxor.math.Color(((java.lang.Object) (__temp_stmt34059) ), ((java.lang.Object) (__temp_stmt34060) ), ((java.lang.Object) (__temp_stmt34061) ), ((java.lang.Object) (__temp_stmt34062) ));
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
	
	
	public  double r;
	
	public  double g;
	
	public  double b;
	
	public  double a;
	
	public   haxor.math.Color Set(java.lang.Object p_r, java.lang.Object p_g, java.lang.Object p_b, java.lang.Object p_a)
	{
		double __temp_p_a33843 = ( (( p_a == null )) ? (((double) (1) )) : (((double) (haxe.lang.Runtime.toDouble(p_a)) )) );
		double __temp_p_b33842 = ( (( p_b == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_b)) )) );
		double __temp_p_g33841 = ( (( p_g == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_g)) )) );
		double __temp_p_r33840 = ( (( p_r == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_r)) )) );
		this.r = __temp_p_r33840;
		this.g = __temp_p_g33841;
		this.b = __temp_p_b33842;
		this.a = __temp_p_a33843;
		return this;
	}
	
	
	public   haxor.math.Color Set4(haxor.math.Color p_color)
	{
		if (( p_color == null )) 
		{
			this.r = 0.0;
		}
		 else 
		{
			this.r = p_color.r;
		}
		
		if (( p_color == null )) 
		{
			this.g = 0.0;
		}
		 else 
		{
			this.g = p_color.g;
		}
		
		if (( p_color == null )) 
		{
			this.b = 0.0;
		}
		 else 
		{
			this.b = p_color.b;
		}
		
		if (( p_color == null )) 
		{
			this.a = 1.0;
		}
		 else 
		{
			this.a = p_color.a;
		}
		
		return this;
	}
	
	
	public   haxe.root.Array<java.lang.Object> ToArray()
	{
		return new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (this.r) ), ((java.lang.Object) (this.g) ), ((java.lang.Object) (this.b) ), ((java.lang.Object) (this.a) )});
	}
	
	
	public   java.lang.String ToString()
	{
		haxe.root.Array<java.lang.Object> a = this.ToArray();
		haxe.root.Array<java.lang.String> s = new haxe.root.Array<java.lang.String>(new java.lang.String[]{});
		{
			int _g1 = 0;
			int _g = a.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				a.__set(i, ( ((double) (((int) (( ((double) (haxe.lang.Runtime.toDouble(a.__get(i))) ) * 100.0 )) )) ) / 100 ));
				s.push(( (( ((double) (haxe.lang.Runtime.toDouble(a.__get(i))) ) >= 0 )) ? (( " " + haxe.lang.Runtime.toString(((double) (haxe.lang.Runtime.toDouble(a.__get(i))) )) )) : (( haxe.lang.Runtime.toString(((double) (haxe.lang.Runtime.toDouble(a.__get(i))) )) + "" )) ));
			}
			
		}
		
		java.lang.String res = "[";
		{
			int _g11 = 0;
			int _g2 = a.length;
			while (( _g11 < _g2 ))
			{
				int i1 = _g11++;
				res += ( s.__get(i1) + (( (( i1 < ( a.length - 1 ) )) ? (",") : ("]") )) );
			}
			
		}
		
		return res;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef34054 = true;
			switch (field.hashCode())
			{
				case 97:
				{
					if (field.equals("a")) 
					{
						__temp_executeDef34054 = false;
						this.a = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3002572:
				{
					if (field.equals("argb")) 
					{
						__temp_executeDef34054 = false;
						this.set_argb(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef34054 = false;
						this.b = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3498292:
				{
					if (field.equals("rgba")) 
					{
						__temp_executeDef34054 = false;
						this.set_rgba(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 103:
				{
					if (field.equals("g")) 
					{
						__temp_executeDef34054 = false;
						this.g = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 112845:
				{
					if (field.equals("rgb")) 
					{
						__temp_executeDef34054 = false;
						this.set_rgb(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 114:
				{
					if (field.equals("r")) 
					{
						__temp_executeDef34054 = false;
						this.r = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef34054) 
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
			boolean __temp_executeDef34055 = true;
			switch (field.hashCode())
			{
				case 97:
				{
					if (field.equals("a")) 
					{
						__temp_executeDef34055 = false;
						this.a = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef34055 = false;
						this.clone = ((haxor.math.Color) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef34055 = false;
						this.b = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3002572:
				{
					if (field.equals("argb")) 
					{
						__temp_executeDef34055 = false;
						this.set_argb(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 103:
				{
					if (field.equals("g")) 
					{
						__temp_executeDef34055 = false;
						this.g = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3498292:
				{
					if (field.equals("rgba")) 
					{
						__temp_executeDef34055 = false;
						this.set_rgba(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 114:
				{
					if (field.equals("r")) 
					{
						__temp_executeDef34055 = false;
						this.r = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 112845:
				{
					if (field.equals("rgb")) 
					{
						__temp_executeDef34055 = false;
						this.set_rgb(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef34055) 
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
			boolean __temp_executeDef34056 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef34056 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef34056 = false;
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
						__temp_executeDef34056 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToArray"))) );
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef34056 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_clone"))) );
					}
					
					break;
				}
				
				
				case 2573362:
				{
					if (field.equals("Set4")) 
					{
						__temp_executeDef34056 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set4"))) );
					}
					
					break;
				}
				
				
				case 3002572:
				{
					if (field.equals("argb")) 
					{
						__temp_executeDef34056 = false;
						return this.get_argb();
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef34056 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 1976115221:
				{
					if (field.equals("get_argb")) 
					{
						__temp_executeDef34056 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_argb"))) );
					}
					
					break;
				}
				
				
				case 97:
				{
					if (field.equals("a")) 
					{
						__temp_executeDef34056 = false;
						return this.a;
					}
					
					break;
				}
				
				
				case 1415002761:
				{
					if (field.equals("set_argb")) 
					{
						__temp_executeDef34056 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_argb"))) );
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef34056 = false;
						return this.b;
					}
					
					break;
				}
				
				
				case 98819:
				{
					if (field.equals("css")) 
					{
						__temp_executeDef34056 = false;
						return this.get_css();
					}
					
					break;
				}
				
				
				case 103:
				{
					if (field.equals("g")) 
					{
						__temp_executeDef34056 = false;
						return this.g;
					}
					
					break;
				}
				
				
				case -74799718:
				{
					if (field.equals("get_css")) 
					{
						__temp_executeDef34056 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_css"))) );
					}
					
					break;
				}
				
				
				case 114:
				{
					if (field.equals("r")) 
					{
						__temp_executeDef34056 = false;
						return this.r;
					}
					
					break;
				}
				
				
				case 3498292:
				{
					if (field.equals("rgba")) 
					{
						__temp_executeDef34056 = false;
						return this.get_rgba();
					}
					
					break;
				}
				
				
				case 1985323888:
				{
					if (field.equals("set_rgb")) 
					{
						__temp_executeDef34056 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_rgb"))) );
					}
					
					break;
				}
				
				
				case 1976610941:
				{
					if (field.equals("get_rgba")) 
					{
						__temp_executeDef34056 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_rgba"))) );
					}
					
					break;
				}
				
				
				case -74785692:
				{
					if (field.equals("get_rgb")) 
					{
						__temp_executeDef34056 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_rgb"))) );
					}
					
					break;
				}
				
				
				case 1415498481:
				{
					if (field.equals("set_rgba")) 
					{
						__temp_executeDef34056 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_rgba"))) );
					}
					
					break;
				}
				
				
				case 112845:
				{
					if (field.equals("rgb")) 
					{
						__temp_executeDef34056 = false;
						return this.get_rgb();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef34056) 
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
			boolean __temp_executeDef34057 = true;
			switch (field.hashCode())
			{
				case 97:
				{
					if (field.equals("a")) 
					{
						__temp_executeDef34057 = false;
						return this.a;
					}
					
					break;
				}
				
				
				case 3002572:
				{
					if (field.equals("argb")) 
					{
						__temp_executeDef34057 = false;
						return ((double) (this.get_argb()) );
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef34057 = false;
						return this.b;
					}
					
					break;
				}
				
				
				case 3498292:
				{
					if (field.equals("rgba")) 
					{
						__temp_executeDef34057 = false;
						return ((double) (this.get_rgba()) );
					}
					
					break;
				}
				
				
				case 103:
				{
					if (field.equals("g")) 
					{
						__temp_executeDef34057 = false;
						return this.g;
					}
					
					break;
				}
				
				
				case 112845:
				{
					if (field.equals("rgb")) 
					{
						__temp_executeDef34057 = false;
						return ((double) (this.get_rgb()) );
					}
					
					break;
				}
				
				
				case 114:
				{
					if (field.equals("r")) 
					{
						__temp_executeDef34057 = false;
						return this.r;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef34057) 
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
			boolean __temp_executeDef34058 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef34058 = false;
						return this.ToString();
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef34058 = false;
						return this.get_clone();
					}
					
					break;
				}
				
				
				case 482271358:
				{
					if (field.equals("ToArray")) 
					{
						__temp_executeDef34058 = false;
						return this.ToArray();
					}
					
					break;
				}
				
				
				case 1976115221:
				{
					if (field.equals("get_argb")) 
					{
						__temp_executeDef34058 = false;
						return this.get_argb();
					}
					
					break;
				}
				
				
				case 2573362:
				{
					if (field.equals("Set4")) 
					{
						__temp_executeDef34058 = false;
						return this.Set4(((haxor.math.Color) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1415002761:
				{
					if (field.equals("set_argb")) 
					{
						__temp_executeDef34058 = false;
						return this.set_argb(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef34058 = false;
						return this.Set(dynargs.__get(0), dynargs.__get(1), dynargs.__get(2), dynargs.__get(3));
					}
					
					break;
				}
				
				
				case -74799718:
				{
					if (field.equals("get_css")) 
					{
						__temp_executeDef34058 = false;
						return this.get_css();
					}
					
					break;
				}
				
				
				case 1985323888:
				{
					if (field.equals("set_rgb")) 
					{
						__temp_executeDef34058 = false;
						return this.set_rgb(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1976610941:
				{
					if (field.equals("get_rgba")) 
					{
						__temp_executeDef34058 = false;
						return this.get_rgba();
					}
					
					break;
				}
				
				
				case -74785692:
				{
					if (field.equals("get_rgb")) 
					{
						__temp_executeDef34058 = false;
						return this.get_rgb();
					}
					
					break;
				}
				
				
				case 1415498481:
				{
					if (field.equals("set_rgba")) 
					{
						__temp_executeDef34058 = false;
						return this.set_rgba(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef34058) 
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
		baseArr.push("rgb");
		baseArr.push("rgba");
		baseArr.push("css");
		baseArr.push("argb");
		baseArr.push("clone");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


