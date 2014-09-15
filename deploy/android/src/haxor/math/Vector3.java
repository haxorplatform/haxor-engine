package haxor.math;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Vector3 extends haxe.lang.HxObject
{
	public    Vector3(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Vector3(java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_z)
	{
		haxor.math.Vector3.__hx_ctor_haxor_math_Vector3(this, p_x, p_y, p_z);
	}
	
	
	public static   void __hx_ctor_haxor_math_Vector3(haxor.math.Vector3 __temp_me255616, java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_z)
	{
		double __temp_p_z255615 = ( (( p_z == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_z)) )) );
		double __temp_p_y255614 = ( (( p_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_y)) )) );
		double __temp_p_x255613 = ( (( p_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_x)) )) );
		__temp_me255616.x = __temp_p_x255613;
		__temp_me255616.y = __temp_p_y255614;
		__temp_me255616.z = __temp_p_z255615;
	}
	
	
	public static  haxor.math.Vector3 temp;
	
	public static   haxor.math.Vector3 get_temp()
	{
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			return _this.m_v3.__get(_this.m_nv3 = ( (( _this.m_nv3 + 1 )) % _this.m_v3.length ));
		}
		
	}
	
	
	public static  haxor.math.Vector3 zero;
	
	public static   haxor.math.Vector3 get_zero()
	{
		return new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
	}
	
	
	public static  haxor.math.Vector3 one;
	
	public static   haxor.math.Vector3 get_one()
	{
		return new haxor.math.Vector3(((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Vector3 right;
	
	public static   haxor.math.Vector3 get_right()
	{
		return new haxor.math.Vector3(((java.lang.Object) (1) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
	}
	
	
	public static  haxor.math.Vector3 up;
	
	public static   haxor.math.Vector3 get_up()
	{
		return new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (1) ), ((java.lang.Object) (0) ));
	}
	
	
	public static  haxor.math.Vector3 forward;
	
	public static   haxor.math.Vector3 get_forward()
	{
		return new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
	}
	
	
	public static   double Dot(haxor.math.Vector3 p_a, haxor.math.Vector3 p_b)
	{
		return ( ( ( p_a.x * p_b.x ) + ( p_a.y * p_b.y ) ) + ( p_a.z * p_b.z ) );
	}
	
	
	public static   double Distance(haxor.math.Vector3 p_a, haxor.math.Vector3 p_b)
	{
		double dx = ( p_a.x - p_b.x );
		double dy = ( p_a.y - p_b.y );
		double dz = ( p_a.z - p_b.z );
		return java.lang.Math.sqrt(( ( ( dx * dx ) + ( dy * dy ) ) + ( dz * dz ) ));
	}
	
	
	public static   haxor.math.Vector3 Cross(haxor.math.Vector3 p_a, haxor.math.Vector3 p_b, haxor.math.Vector3 p_result)
	{
		if (( p_result == null )) 
		{
			p_result = new haxor.math.Vector3(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			p_result = p_result;
		}
		
		return p_result.Set(( ( p_a.y * p_b.z ) - ( p_a.z * p_b.y ) ), ( ( p_a.z * p_b.x ) - ( p_a.x * p_b.z ) ), ( ( p_a.x * p_b.y ) - ( p_a.y * p_b.x ) ));
	}
	
	
	public static   haxor.math.Vector3 Lerp(haxor.math.Vector3 p_a, haxor.math.Vector3 p_b, double p_r, haxor.math.Vector3 p_result)
	{
		if (( p_result == null )) 
		{
			p_result = new haxor.math.Vector3(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			p_result = p_result;
		}
		
		return p_result.Set(( p_a.x + ( (( p_b.x - p_a.x )) * p_r ) ), ( p_a.y + ( (( p_b.y - p_a.y )) * p_r ) ), ( p_a.z + ( (( p_b.z - p_a.z )) * p_r ) ));
	}
	
	
	public static   haxor.math.Vector3 Min(haxor.math.Vector3 p_a, haxor.math.Vector3 p_b, haxor.math.Vector3 p_result)
	{
		if (( p_result == null )) 
		{
			p_result = new haxor.math.Vector3(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			p_result = p_result;
		}
		
		p_result.x = java.lang.Math.min(p_a.x, p_b.x);
		p_result.y = java.lang.Math.min(p_a.y, p_b.y);
		p_result.z = java.lang.Math.min(p_a.z, p_b.z);
		return p_result;
	}
	
	
	public static   haxor.math.Vector3 Max(haxor.math.Vector3 p_a, haxor.math.Vector3 p_b, haxor.math.Vector3 p_result)
	{
		if (( p_result == null )) 
		{
			p_result = new haxor.math.Vector3(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		}
		 else 
		{
			p_result = p_result;
		}
		
		p_result.x = java.lang.Math.max(p_a.x, p_b.x);
		p_result.y = java.lang.Math.max(p_a.y, p_b.y);
		p_result.z = java.lang.Math.max(p_a.z, p_b.z);
		return p_result;
	}
	
	
	public static   haxor.math.Vector3 Parse(java.lang.String p_data, java.lang.String p_delimiter)
	{
		if (( p_delimiter == null )) 
		{
			p_delimiter = " ";
		}
		
		haxe.root.Array<java.lang.String> tk = haxe.lang.StringExt.split(p_data, p_delimiter);
		return new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) )).Set(haxe.root.Std.parseFloat(tk.__get(0).trim()), haxe.root.Std.parseFloat(tk.__get(1).trim()), haxe.root.Std.parseFloat(tk.__get(2).trim()));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.math.Vector3(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.math.Vector3(((java.lang.Object) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ), ((java.lang.Object) (arr.__get(2)) ));
	}
	
	
	public  haxor.math.Vector3 clone;
	
	public final   haxor.math.Vector3 get_clone()
	{
		return new haxor.math.Vector3(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ));
	}
	
	
	public  haxor.math.Color color;
	
	public final   haxor.math.Color get_color()
	{
		return new haxor.math.Color(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ), ((java.lang.Object) (null) ));
	}
	
	
	public  haxor.math.Vector3 xzy;
	
	public final   haxor.math.Vector3 get_xzy()
	{
		return new haxor.math.Vector3(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.z) ), ((java.lang.Object) (this.y) ));
	}
	
	
	public  haxor.math.Vector3 yxz;
	
	public final   haxor.math.Vector3 get_yxz()
	{
		return new haxor.math.Vector3(((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ), ((java.lang.Object) (this.x) ));
	}
	
	
	public  haxor.math.Vector3 yzx;
	
	public final   haxor.math.Vector3 get_yzx()
	{
		return new haxor.math.Vector3(((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ), ((java.lang.Object) (this.x) ));
	}
	
	
	public  haxor.math.Vector3 zxy;
	
	public final   haxor.math.Vector3 get_zxy()
	{
		return new haxor.math.Vector3(((java.lang.Object) (this.z) ), ((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ));
	}
	
	
	public  haxor.math.Vector3 zyx;
	
	public final   haxor.math.Vector3 get_zyx()
	{
		return new haxor.math.Vector3(((java.lang.Object) (this.z) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.x) ));
	}
	
	
	public  haxor.math.Vector2 xy;
	
	public final   haxor.math.Vector2 get_xy()
	{
		return new haxor.math.Vector2(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ));
	}
	
	
	public  haxor.math.Vector2 xz;
	
	public final   haxor.math.Vector2 get_xz()
	{
		return new haxor.math.Vector2(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.z) ));
	}
	
	
	public  haxor.math.Vector2 yx;
	
	public final   haxor.math.Vector2 get_yx()
	{
		return new haxor.math.Vector2(((java.lang.Object) (this.y) ), ((java.lang.Object) (this.x) ));
	}
	
	
	public  haxor.math.Vector2 yz;
	
	public final   haxor.math.Vector2 get_yz()
	{
		return new haxor.math.Vector2(((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ));
	}
	
	
	public  haxor.math.Vector2 zx;
	
	public final   haxor.math.Vector2 get_zx()
	{
		return new haxor.math.Vector2(((java.lang.Object) (this.z) ), ((java.lang.Object) (this.x) ));
	}
	
	
	public  haxor.math.Vector2 zy;
	
	public final   haxor.math.Vector2 get_zy()
	{
		return new haxor.math.Vector2(((java.lang.Object) (this.z) ), ((java.lang.Object) (this.y) ));
	}
	
	
	public  double length;
	
	public final   double get_length()
	{
		return java.lang.Math.sqrt(( ( ( this.x * this.x ) + ( this.y * this.y ) ) + ( this.z * this.z ) ));
	}
	
	
	public  double lengthSqr;
	
	public final   double get_lengthSqr()
	{
		return ( ( ( this.x * this.x ) + ( this.y * this.y ) ) + ( this.z * this.z ) );
	}
	
	
	public  haxor.math.Vector3 normalized;
	
	public   haxor.math.Vector3 get_normalized()
	{
		return new haxor.math.Vector3(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) )).Normalize();
	}
	
	
	public  haxor.math.Vector3 inverse;
	
	public final   haxor.math.Vector3 get_inverse()
	{
		return new haxor.math.Vector3(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) )).Invert();
	}
	
	
	public  double x;
	
	public  double y;
	
	public  double z;
	
	public   haxor.math.Vector3 Set(java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_z)
	{
		double __temp_p_z255611 = ( (( p_z == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_z)) )) );
		double __temp_p_y255610 = ( (( p_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_y)) )) );
		double __temp_p_x255609 = ( (( p_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_x)) )) );
		this.x = __temp_p_x255609;
		this.y = __temp_p_y255610;
		this.z = __temp_p_z255611;
		return this;
	}
	
	
	public   haxor.math.Vector3 Set2(haxor.math.Vector2 v)
	{
		this.x = v.x;
		this.y = v.y;
		return this;
	}
	
	
	public   haxor.math.Vector3 Set3(haxor.math.Vector3 v)
	{
		this.x = v.x;
		this.y = v.y;
		this.z = v.z;
		return this;
	}
	
	
	public   haxor.math.Vector3 Set4(haxor.math.Vector4 v)
	{
		this.x = v.x;
		this.y = v.y;
		this.z = v.z;
		return this;
	}
	
	
	public   haxor.math.Vector3 SetColor(haxor.math.Color v)
	{
		this.x = v.r;
		this.y = v.g;
		this.z = v.b;
		return this;
	}
	
	
	public   double Get(int p)
	{
		if (( p == 0 )) 
		{
			return this.x;
		}
		 else 
		{
			if (( p == 1 )) 
			{
				return this.y;
			}
			 else 
			{
				return this.z;
			}
			
		}
		
	}
	
	
	public   haxor.math.Vector3 Add(haxor.math.Vector3 p_v)
	{
		this.x += p_v.x;
		this.y += p_v.y;
		this.z += p_v.z;
		return this;
	}
	
	
	public   haxor.math.Vector3 Add3(double p_x, double p_y, double p_z)
	{
		this.x += p_x;
		this.y += p_y;
		this.z += p_z;
		return this;
	}
	
	
	public   haxor.math.Vector3 Sub(haxor.math.Vector3 p_v)
	{
		this.x -= p_v.x;
		this.y -= p_v.y;
		this.z -= p_v.z;
		return this;
	}
	
	
	public   haxor.math.Vector3 Multiply(haxor.math.Vector3 p_v)
	{
		this.x *= p_v.x;
		this.y *= p_v.y;
		this.z *= p_v.z;
		return this;
	}
	
	
	public   boolean Step(haxor.math.Vector3 p_to, double p_step)
	{
		double vx = ( p_to.x - this.x );
		double vy = ( p_to.y - this.y );
		double vz = ( p_to.z - this.z );
		double l = java.lang.Math.sqrt(( ( ( vx * vx ) + ( vy * vy ) ) + ( vz * vz ) ));
		if (( l <= 0.0001 )) 
		{
			return false;
		}
		
		double s = 0.0;
		if (( p_step > l )) 
		{
			s = l;
		}
		 else 
		{
			s = p_step;
		}
		
		l = ( s / l );
		vx *= l;
		vy *= l;
		vz *= l;
		this.x += vx;
		this.y += vy;
		this.z += vz;
		return true;
	}
	
	
	public   haxor.math.Vector3 Reflect(haxor.math.Vector3 p_normal)
	{
		double d = ( java.lang.Math.min(0.0, ( ( ( p_normal.x * this.x ) + ( p_normal.y * this.y ) ) + ( p_normal.z * this.z ) )) * 2.0 );
		this.x += (  - (p_normal.x)  * d );
		this.y += (  - (p_normal.y)  * d );
		this.z += (  - (p_normal.z)  * d );
		return this;
	}
	
	
	public   haxor.math.Vector3 Invert()
	{
		this.x =  - (this.x) ;
		this.y =  - (this.y) ;
		this.z =  - (this.z) ;
		return this;
	}
	
	
	public   haxor.math.Vector3 Scale(double p_s)
	{
		this.x *= p_s;
		this.y *= p_s;
		this.z *= p_s;
		return this;
	}
	
	
	public   haxor.math.Vector3 Normalize()
	{
		double l = java.lang.Math.sqrt(( ( ( this.x * this.x ) + ( this.y * this.y ) ) + ( this.z * this.z ) ));
		if (( l <= 0 )) 
		{
			return this;
		}
		
		this.x *= l = ( 1.0 / l );
		this.y *= l;
		this.z *= l;
		return this;
	}
	
	
	public   haxe.root.Array<java.lang.Object> ToArray()
	{
		return new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) )});
	}
	
	
	public   java.lang.String ToString(java.lang.Object p_places)
	{
		int __temp_p_places255612 = ( (( p_places == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_places)) )) );
		double __temp_stmt256459 = 0.0;
		{
			double d = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places255612) ));
			double __temp_stmt256460 = 0.0;
			{
				double p_v = ( this.x * d );
				__temp_stmt256460 = ((double) (((int) (( p_v + (( (( p_v < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt256459 = ( __temp_stmt256460 / d );
		}
		
		double __temp_stmt256461 = 0.0;
		{
			double d1 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places255612) ));
			double __temp_stmt256462 = 0.0;
			{
				double p_v1 = ( this.y * d1 );
				__temp_stmt256462 = ((double) (((int) (( p_v1 + (( (( p_v1 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt256461 = ( __temp_stmt256462 / d1 );
		}
		
		double __temp_stmt256463 = 0.0;
		{
			double d2 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places255612) ));
			double __temp_stmt256464 = 0.0;
			{
				double p_v2 = ( this.z * d2 );
				__temp_stmt256464 = ((double) (((int) (( p_v2 + (( (( p_v2 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt256463 = ( __temp_stmt256464 / d2 );
		}
		
		return ( ( ( ( ( ( "[" + haxe.lang.Runtime.toString(__temp_stmt256459) ) + "," ) + haxe.lang.Runtime.toString(__temp_stmt256461) ) + "," ) + haxe.lang.Runtime.toString(__temp_stmt256463) ) + "]" );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256465 = true;
			switch (field.hashCode())
			{
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef256465 = false;
						this.z = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef256465 = false;
						this.length = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef256465 = false;
						this.y = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -101099250:
				{
					if (field.equals("lengthSqr")) 
					{
						__temp_executeDef256465 = false;
						this.lengthSqr = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256465 = false;
						this.x = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256465) 
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
			boolean __temp_executeDef256466 = true;
			switch (field.hashCode())
			{
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef256466 = false;
						this.z = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef256466 = false;
						this.clone = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef256466 = false;
						this.y = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 94842723:
				{
					if (field.equals("color")) 
					{
						__temp_executeDef256466 = false;
						this.color = ((haxor.math.Color) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256466 = false;
						this.x = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 119223:
				{
					if (field.equals("xzy")) 
					{
						__temp_executeDef256466 = false;
						this.xzy = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1959910192:
				{
					if (field.equals("inverse")) 
					{
						__temp_executeDef256466 = false;
						this.inverse = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 120123:
				{
					if (field.equals("yxz")) 
					{
						__temp_executeDef256466 = false;
						this.yxz = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1255046409:
				{
					if (field.equals("normalized")) 
					{
						__temp_executeDef256466 = false;
						this.normalized = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 120183:
				{
					if (field.equals("yzx")) 
					{
						__temp_executeDef256466 = false;
						this.yzx = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -101099250:
				{
					if (field.equals("lengthSqr")) 
					{
						__temp_executeDef256466 = false;
						this.lengthSqr = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 121083:
				{
					if (field.equals("zxy")) 
					{
						__temp_executeDef256466 = false;
						this.zxy = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef256466 = false;
						this.length = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 121113:
				{
					if (field.equals("zyx")) 
					{
						__temp_executeDef256466 = false;
						this.zyx = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3903:
				{
					if (field.equals("zy")) 
					{
						__temp_executeDef256466 = false;
						this.zy = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3841:
				{
					if (field.equals("xy")) 
					{
						__temp_executeDef256466 = false;
						this.xy = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3902:
				{
					if (field.equals("zx")) 
					{
						__temp_executeDef256466 = false;
						this.zx = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3842:
				{
					if (field.equals("xz")) 
					{
						__temp_executeDef256466 = false;
						this.xz = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3873:
				{
					if (field.equals("yz")) 
					{
						__temp_executeDef256466 = false;
						this.yz = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3871:
				{
					if (field.equals("yx")) 
					{
						__temp_executeDef256466 = false;
						this.yx = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256466) 
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
			boolean __temp_executeDef256467 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef256467 = false;
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
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToArray"))) );
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_clone"))) );
					}
					
					break;
				}
				
				
				case -2054390035:
				{
					if (field.equals("Normalize")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Normalize"))) );
					}
					
					break;
				}
				
				
				case 94842723:
				{
					if (field.equals("color")) 
					{
						__temp_executeDef256467 = false;
						if (handleProperties) 
						{
							return this.get_color();
						}
						 else 
						{
							return this.color;
						}
						
					}
					
					break;
				}
				
				
				case 79698218:
				{
					if (field.equals("Scale")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Scale"))) );
					}
					
					break;
				}
				
				
				case 1131792698:
				{
					if (field.equals("get_color")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_color"))) );
					}
					
					break;
				}
				
				
				case -2099835914:
				{
					if (field.equals("Invert")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Invert"))) );
					}
					
					break;
				}
				
				
				case 119223:
				{
					if (field.equals("xzy")) 
					{
						__temp_executeDef256467 = false;
						if (handleProperties) 
						{
							return this.get_xzy();
						}
						 else 
						{
							return this.xzy;
						}
						
					}
					
					break;
				}
				
				
				case -1545048419:
				{
					if (field.equals("Reflect")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Reflect"))) );
					}
					
					break;
				}
				
				
				case -74779314:
				{
					if (field.equals("get_xzy")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_xzy"))) );
					}
					
					break;
				}
				
				
				case 2587372:
				{
					if (field.equals("Step")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Step"))) );
					}
					
					break;
				}
				
				
				case 120123:
				{
					if (field.equals("yxz")) 
					{
						__temp_executeDef256467 = false;
						if (handleProperties) 
						{
							return this.get_yxz();
						}
						 else 
						{
							return this.yxz;
						}
						
					}
					
					break;
				}
				
				
				case 718473796:
				{
					if (field.equals("Multiply")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Multiply"))) );
					}
					
					break;
				}
				
				
				case -74778414:
				{
					if (field.equals("get_yxz")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_yxz"))) );
					}
					
					break;
				}
				
				
				case 83488:
				{
					if (field.equals("Sub")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Sub"))) );
					}
					
					break;
				}
				
				
				case 120183:
				{
					if (field.equals("yzx")) 
					{
						__temp_executeDef256467 = false;
						if (handleProperties) 
						{
							return this.get_yzx();
						}
						 else 
						{
							return this.yzx;
						}
						
					}
					
					break;
				}
				
				
				case 2035666:
				{
					if (field.equals("Add3")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add3"))) );
					}
					
					break;
				}
				
				
				case -74778354:
				{
					if (field.equals("get_yzx")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_yzx"))) );
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add"))) );
					}
					
					break;
				}
				
				
				case 121083:
				{
					if (field.equals("zxy")) 
					{
						__temp_executeDef256467 = false;
						if (handleProperties) 
						{
							return this.get_zxy();
						}
						 else 
						{
							return this.zxy;
						}
						
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Get"))) );
					}
					
					break;
				}
				
				
				case -74777454:
				{
					if (field.equals("get_zxy")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_zxy"))) );
					}
					
					break;
				}
				
				
				case 1454199873:
				{
					if (field.equals("SetColor")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetColor"))) );
					}
					
					break;
				}
				
				
				case 121113:
				{
					if (field.equals("zyx")) 
					{
						__temp_executeDef256467 = false;
						if (handleProperties) 
						{
							return this.get_zyx();
						}
						 else 
						{
							return this.zyx;
						}
						
					}
					
					break;
				}
				
				
				case 2573362:
				{
					if (field.equals("Set4")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set4"))) );
					}
					
					break;
				}
				
				
				case -74777424:
				{
					if (field.equals("get_zyx")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_zyx"))) );
					}
					
					break;
				}
				
				
				case 2573361:
				{
					if (field.equals("Set3")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set3"))) );
					}
					
					break;
				}
				
				
				case 3841:
				{
					if (field.equals("xy")) 
					{
						__temp_executeDef256467 = false;
						if (handleProperties) 
						{
							return this.get_xy();
						}
						 else 
						{
							return this.xy;
						}
						
					}
					
					break;
				}
				
				
				case 2573360:
				{
					if (field.equals("Set2")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set2"))) );
					}
					
					break;
				}
				
				
				case -1249338230:
				{
					if (field.equals("get_xy")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_xy"))) );
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 3842:
				{
					if (field.equals("xz")) 
					{
						__temp_executeDef256467 = false;
						if (handleProperties) 
						{
							return this.get_xz();
						}
						 else 
						{
							return this.xz;
						}
						
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef256467 = false;
						return this.z;
					}
					
					break;
				}
				
				
				case -1249338229:
				{
					if (field.equals("get_xz")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_xz"))) );
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef256467 = false;
						return this.y;
					}
					
					break;
				}
				
				
				case 3871:
				{
					if (field.equals("yx")) 
					{
						__temp_executeDef256467 = false;
						if (handleProperties) 
						{
							return this.get_yx();
						}
						 else 
						{
							return this.yx;
						}
						
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256467 = false;
						return this.x;
					}
					
					break;
				}
				
				
				case -1249338200:
				{
					if (field.equals("get_yx")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_yx"))) );
					}
					
					break;
				}
				
				
				case 2036423495:
				{
					if (field.equals("get_inverse")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_inverse"))) );
					}
					
					break;
				}
				
				
				case 3873:
				{
					if (field.equals("yz")) 
					{
						__temp_executeDef256467 = false;
						if (handleProperties) 
						{
							return this.get_yz();
						}
						 else 
						{
							return this.yz;
						}
						
					}
					
					break;
				}
				
				
				case 1959910192:
				{
					if (field.equals("inverse")) 
					{
						__temp_executeDef256467 = false;
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
				
				
				case -1249338198:
				{
					if (field.equals("get_yz")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_yz"))) );
					}
					
					break;
				}
				
				
				case 1820096384:
				{
					if (field.equals("get_normalized")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_normalized"))) );
					}
					
					break;
				}
				
				
				case 3902:
				{
					if (field.equals("zx")) 
					{
						__temp_executeDef256467 = false;
						if (handleProperties) 
						{
							return this.get_zx();
						}
						 else 
						{
							return this.zx;
						}
						
					}
					
					break;
				}
				
				
				case -1255046409:
				{
					if (field.equals("normalized")) 
					{
						__temp_executeDef256467 = false;
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
				
				
				case -1249338169:
				{
					if (field.equals("get_zx")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_zx"))) );
					}
					
					break;
				}
				
				
				case 413740901:
				{
					if (field.equals("get_lengthSqr")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_lengthSqr"))) );
					}
					
					break;
				}
				
				
				case 3903:
				{
					if (field.equals("zy")) 
					{
						__temp_executeDef256467 = false;
						if (handleProperties) 
						{
							return this.get_zy();
						}
						 else 
						{
							return this.zy;
						}
						
					}
					
					break;
				}
				
				
				case -101099250:
				{
					if (field.equals("lengthSqr")) 
					{
						__temp_executeDef256467 = false;
						if (handleProperties) 
						{
							return this.get_lengthSqr();
						}
						 else 
						{
							return this.lengthSqr;
						}
						
					}
					
					break;
				}
				
				
				case -1249338168:
				{
					if (field.equals("get_zy")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_zy"))) );
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef256467 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef256467 = false;
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
				
				
			}
			
			if (__temp_executeDef256467) 
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
			boolean __temp_executeDef256468 = true;
			switch (field.hashCode())
			{
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef256468 = false;
						return this.z;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef256468 = false;
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
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef256468 = false;
						return this.y;
					}
					
					break;
				}
				
				
				case -101099250:
				{
					if (field.equals("lengthSqr")) 
					{
						__temp_executeDef256468 = false;
						if (handleProperties) 
						{
							return this.get_lengthSqr();
						}
						 else 
						{
							return this.lengthSqr;
						}
						
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256468 = false;
						return this.x;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256468) 
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
			boolean __temp_executeDef256469 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef256469 = false;
						return this.ToString(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef256469 = false;
						return this.get_clone();
					}
					
					break;
				}
				
				
				case 482271358:
				{
					if (field.equals("ToArray")) 
					{
						__temp_executeDef256469 = false;
						return this.ToArray();
					}
					
					break;
				}
				
				
				case 1131792698:
				{
					if (field.equals("get_color")) 
					{
						__temp_executeDef256469 = false;
						return this.get_color();
					}
					
					break;
				}
				
				
				case -2054390035:
				{
					if (field.equals("Normalize")) 
					{
						__temp_executeDef256469 = false;
						return this.Normalize();
					}
					
					break;
				}
				
				
				case -74779314:
				{
					if (field.equals("get_xzy")) 
					{
						__temp_executeDef256469 = false;
						return this.get_xzy();
					}
					
					break;
				}
				
				
				case 79698218:
				{
					if (field.equals("Scale")) 
					{
						__temp_executeDef256469 = false;
						return this.Scale(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -74778414:
				{
					if (field.equals("get_yxz")) 
					{
						__temp_executeDef256469 = false;
						return this.get_yxz();
					}
					
					break;
				}
				
				
				case -2099835914:
				{
					if (field.equals("Invert")) 
					{
						__temp_executeDef256469 = false;
						return this.Invert();
					}
					
					break;
				}
				
				
				case -74778354:
				{
					if (field.equals("get_yzx")) 
					{
						__temp_executeDef256469 = false;
						return this.get_yzx();
					}
					
					break;
				}
				
				
				case -1545048419:
				{
					if (field.equals("Reflect")) 
					{
						__temp_executeDef256469 = false;
						return this.Reflect(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -74777454:
				{
					if (field.equals("get_zxy")) 
					{
						__temp_executeDef256469 = false;
						return this.get_zxy();
					}
					
					break;
				}
				
				
				case 2587372:
				{
					if (field.equals("Step")) 
					{
						__temp_executeDef256469 = false;
						return this.Step(((haxor.math.Vector3) (dynargs.__get(0)) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -74777424:
				{
					if (field.equals("get_zyx")) 
					{
						__temp_executeDef256469 = false;
						return this.get_zyx();
					}
					
					break;
				}
				
				
				case 718473796:
				{
					if (field.equals("Multiply")) 
					{
						__temp_executeDef256469 = false;
						return this.Multiply(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1249338230:
				{
					if (field.equals("get_xy")) 
					{
						__temp_executeDef256469 = false;
						return this.get_xy();
					}
					
					break;
				}
				
				
				case 83488:
				{
					if (field.equals("Sub")) 
					{
						__temp_executeDef256469 = false;
						return this.Sub(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1249338229:
				{
					if (field.equals("get_xz")) 
					{
						__temp_executeDef256469 = false;
						return this.get_xz();
					}
					
					break;
				}
				
				
				case 2035666:
				{
					if (field.equals("Add3")) 
					{
						__temp_executeDef256469 = false;
						return this.Add3(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case -1249338200:
				{
					if (field.equals("get_yx")) 
					{
						__temp_executeDef256469 = false;
						return this.get_yx();
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef256469 = false;
						return this.Add(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1249338198:
				{
					if (field.equals("get_yz")) 
					{
						__temp_executeDef256469 = false;
						return this.get_yz();
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef256469 = false;
						return this.Get(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1249338169:
				{
					if (field.equals("get_zx")) 
					{
						__temp_executeDef256469 = false;
						return this.get_zx();
					}
					
					break;
				}
				
				
				case 1454199873:
				{
					if (field.equals("SetColor")) 
					{
						__temp_executeDef256469 = false;
						return this.SetColor(((haxor.math.Color) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1249338168:
				{
					if (field.equals("get_zy")) 
					{
						__temp_executeDef256469 = false;
						return this.get_zy();
					}
					
					break;
				}
				
				
				case 2573362:
				{
					if (field.equals("Set4")) 
					{
						__temp_executeDef256469 = false;
						return this.Set4(((haxor.math.Vector4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef256469 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case 2573361:
				{
					if (field.equals("Set3")) 
					{
						__temp_executeDef256469 = false;
						return this.Set3(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 413740901:
				{
					if (field.equals("get_lengthSqr")) 
					{
						__temp_executeDef256469 = false;
						return this.get_lengthSqr();
					}
					
					break;
				}
				
				
				case 2573360:
				{
					if (field.equals("Set2")) 
					{
						__temp_executeDef256469 = false;
						return this.Set2(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1820096384:
				{
					if (field.equals("get_normalized")) 
					{
						__temp_executeDef256469 = false;
						return this.get_normalized();
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef256469 = false;
						return this.Set(dynargs.__get(0), dynargs.__get(1), dynargs.__get(2));
					}
					
					break;
				}
				
				
				case 2036423495:
				{
					if (field.equals("get_inverse")) 
					{
						__temp_executeDef256469 = false;
						return this.get_inverse();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256469) 
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
		baseArr.push("z");
		baseArr.push("y");
		baseArr.push("x");
		baseArr.push("inverse");
		baseArr.push("normalized");
		baseArr.push("lengthSqr");
		baseArr.push("length");
		baseArr.push("zy");
		baseArr.push("zx");
		baseArr.push("yz");
		baseArr.push("yx");
		baseArr.push("xz");
		baseArr.push("xy");
		baseArr.push("zyx");
		baseArr.push("zxy");
		baseArr.push("yzx");
		baseArr.push("yxz");
		baseArr.push("xzy");
		baseArr.push("color");
		baseArr.push("clone");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


