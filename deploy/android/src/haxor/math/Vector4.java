package haxor.math;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Vector4 extends haxe.lang.HxObject
{
	public    Vector4(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Vector4(java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_z, java.lang.Object p_w)
	{
		haxor.math.Vector4.__hx_ctor_haxor_math_Vector4(this, p_x, p_y, p_z, p_w);
	}
	
	
	public static   void __hx_ctor_haxor_math_Vector4(haxor.math.Vector4 __temp_me255626, java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_z, java.lang.Object p_w)
	{
		double __temp_p_w255625 = ( (( p_w == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_w)) )) );
		double __temp_p_z255624 = ( (( p_z == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_z)) )) );
		double __temp_p_y255623 = ( (( p_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_y)) )) );
		double __temp_p_x255622 = ( (( p_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_x)) )) );
		__temp_me255626.x = __temp_p_x255622;
		__temp_me255626.y = __temp_p_y255623;
		__temp_me255626.z = __temp_p_z255624;
		__temp_me255626.w = __temp_p_w255625;
	}
	
	
	public static  haxor.math.Vector4 temp;
	
	public static   haxor.math.Vector4 get_temp()
	{
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			return _this.m_v4.__get(_this.m_nv4 = ( (( _this.m_nv4 + 1 )) % _this.m_v4.length ));
		}
		
	}
	
	
	public static  haxor.math.Vector4 zero;
	
	public static   haxor.math.Vector4 get_zero()
	{
		return new haxor.math.Vector4(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
	}
	
	
	public static  haxor.math.Vector4 one;
	
	public static   haxor.math.Vector4 get_one()
	{
		return new haxor.math.Vector4(((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Vector4 W;
	
	public static   haxor.math.Vector4 get_W()
	{
		return new haxor.math.Vector4(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
	}
	
	
	public static   haxor.math.Vector4 Lerp(haxor.math.Vector4 p_a, haxor.math.Vector4 p_b, double p_r)
	{
		return new haxor.math.Vector4(((java.lang.Object) (( p_a.x + ( (( p_b.x - p_a.x )) * p_r ) )) ), ((java.lang.Object) (( p_a.y + ( (( p_b.y - p_a.y )) * p_r ) )) ), ((java.lang.Object) (( p_a.z + ( (( p_b.z - p_a.z )) * p_r ) )) ), ((java.lang.Object) (( p_a.w + ( (( p_b.w - p_a.w )) * p_r ) )) ));
	}
	
	
	public static   haxor.math.Vector4 Parse(java.lang.String p_data, java.lang.String p_delimiter)
	{
		if (( p_delimiter == null )) 
		{
			p_delimiter = " ";
		}
		
		haxe.root.Array<java.lang.String> tk = haxe.lang.StringExt.split(p_data, p_delimiter);
		return new haxor.math.Vector4(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) )).Set(haxe.root.Std.parseFloat(tk.__get(0).trim()), haxe.root.Std.parseFloat(tk.__get(1).trim()), haxe.root.Std.parseFloat(tk.__get(2).trim()), haxe.root.Std.parseFloat(tk.__get(3).trim()));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.math.Vector4(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.math.Vector4(((java.lang.Object) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ), ((java.lang.Object) (arr.__get(2)) ), ((java.lang.Object) (arr.__get(3)) ));
	}
	
	
	public  haxor.math.Vector4 clone;
	
	public final   haxor.math.Vector4 get_clone()
	{
		return new haxor.math.Vector4(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ), ((java.lang.Object) (this.w) ));
	}
	
	
	public  haxor.math.Color rgba;
	
	public final   haxor.math.Color get_rgba()
	{
		return new haxor.math.Color(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ), ((java.lang.Object) (this.w) ));
	}
	
	
	public  haxor.math.Color rgb;
	
	public final   haxor.math.Color get_rgb()
	{
		return new haxor.math.Color(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ), ((java.lang.Object) (null) ));
	}
	
	
	public  haxor.math.Vector3 xyz;
	
	public final   haxor.math.Vector3 get_xyz()
	{
		return new haxor.math.Vector3(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ));
	}
	
	
	public  haxor.math.Vector2 xy;
	
	public final   haxor.math.Vector2 get_xy()
	{
		return new haxor.math.Vector2(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ));
	}
	
	
	public  double length;
	
	public final   double get_length()
	{
		return java.lang.Math.sqrt(( ( ( ( this.x * this.x ) + ( this.y * this.y ) ) + ( this.z * this.z ) ) + ( this.w * this.w ) ));
	}
	
	
	public  double lengthSqr;
	
	public final   double get_lengthSqr()
	{
		return ( ( ( ( this.x * this.x ) + ( this.y * this.y ) ) + ( this.z * this.z ) ) + ( this.w * this.w ) );
	}
	
	
	public  haxor.math.Vector4 normalized;
	
	public final   haxor.math.Vector4 get_normalized()
	{
		return new haxor.math.Vector4(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ), ((java.lang.Object) (this.w) )).Normalize();
	}
	
	
	public  double x;
	
	public  double y;
	
	public  double z;
	
	public  double w;
	
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
				if (( p == 2 )) 
				{
					return this.z;
				}
				 else 
				{
					return this.w;
				}
				
			}
			
		}
		
	}
	
	
	public   haxor.math.Vector4 Set(java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_z, java.lang.Object p_w)
	{
		double __temp_p_w255620 = ( (( p_w == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_w)) )) );
		double __temp_p_z255619 = ( (( p_z == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_z)) )) );
		double __temp_p_y255618 = ( (( p_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_y)) )) );
		double __temp_p_x255617 = ( (( p_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_x)) )) );
		this.x = __temp_p_x255617;
		this.y = __temp_p_y255618;
		this.z = __temp_p_z255619;
		this.w = __temp_p_w255620;
		return this;
	}
	
	
	public   haxor.math.Vector4 Set2(haxor.math.Vector2 v)
	{
		this.x = v.x;
		this.y = v.y;
		return this;
	}
	
	
	public   haxor.math.Vector4 Set3(haxor.math.Vector3 v)
	{
		this.x = v.x;
		this.y = v.y;
		this.z = v.z;
		return this;
	}
	
	
	public   haxor.math.Vector4 SetColor(haxor.math.Color v)
	{
		this.x = v.r;
		this.y = v.g;
		this.z = v.b;
		return this;
	}
	
	
	public   haxor.math.Vector4 Add(haxor.math.Vector4 p_v)
	{
		this.x += p_v.x;
		this.y += p_v.y;
		this.z += p_v.z;
		this.w += p_v.w;
		return this;
	}
	
	
	public   haxor.math.Vector4 Sub(haxor.math.Vector4 p_v)
	{
		this.x -= p_v.x;
		this.y -= p_v.y;
		this.z -= p_v.z;
		this.w -= p_v.w;
		return this;
	}
	
	
	public   haxor.math.Vector4 Multiply(haxor.math.Vector4 p_v)
	{
		this.x *= p_v.x;
		this.y *= p_v.y;
		this.z *= p_v.z;
		this.w *= p_v.w;
		return this;
	}
	
	
	public   haxor.math.Vector4 Scale(double p_s)
	{
		this.x *= p_s;
		this.y *= p_s;
		this.z *= p_s;
		this.w *= p_s;
		return this;
	}
	
	
	public   haxor.math.Vector4 Normalize()
	{
		double l = java.lang.Math.sqrt(( ( ( ( this.x * this.x ) + ( this.y * this.y ) ) + ( this.z * this.z ) ) + ( this.w * this.w ) ));
		if (( l <= 0 )) 
		{
			return this;
		}
		
		this.x *= l = ( 1.0 / l );
		this.y *= l;
		this.z *= l;
		this.w *= l;
		return this;
	}
	
	
	public   boolean IsCulled()
	{
		if (( this.x <  - (this.w)  )) 
		{
			return true;
		}
		
		if (( this.x > this.w )) 
		{
			return true;
		}
		
		if (( this.y <  - (this.w)  )) 
		{
			return true;
		}
		
		if (( this.y > this.w )) 
		{
			return true;
		}
		
		if (( this.z <  - (this.w)  )) 
		{
			return true;
		}
		
		if (( this.z > this.w )) 
		{
			return true;
		}
		
		return false;
	}
	
	
	public   haxe.root.Array<java.lang.Object> ToArray()
	{
		return new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ), ((java.lang.Object) (this.z) ), ((java.lang.Object) (this.w) )});
	}
	
	
	public   java.lang.String ToString(java.lang.Object p_places)
	{
		int __temp_p_places255621 = ( (( p_places == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_places)) )) );
		double __temp_stmt256470 = 0.0;
		{
			double d = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places255621) ));
			double __temp_stmt256471 = 0.0;
			{
				double p_v = ( this.x * d );
				__temp_stmt256471 = ((double) (((int) (( p_v + (( (( p_v < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt256470 = ( __temp_stmt256471 / d );
		}
		
		double __temp_stmt256472 = 0.0;
		{
			double d1 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places255621) ));
			double __temp_stmt256473 = 0.0;
			{
				double p_v1 = ( this.y * d1 );
				__temp_stmt256473 = ((double) (((int) (( p_v1 + (( (( p_v1 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt256472 = ( __temp_stmt256473 / d1 );
		}
		
		double __temp_stmt256474 = 0.0;
		{
			double d2 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places255621) ));
			double __temp_stmt256475 = 0.0;
			{
				double p_v2 = ( this.z * d2 );
				__temp_stmt256475 = ((double) (((int) (( p_v2 + (( (( p_v2 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt256474 = ( __temp_stmt256475 / d2 );
		}
		
		double __temp_stmt256476 = 0.0;
		{
			double d3 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places255621) ));
			double __temp_stmt256477 = 0.0;
			{
				double p_v3 = ( this.w * d3 );
				__temp_stmt256477 = ((double) (((int) (( p_v3 + (( (( p_v3 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt256476 = ( __temp_stmt256477 / d3 );
		}
		
		return ( ( ( ( ( ( ( ( "[" + haxe.lang.Runtime.toString(__temp_stmt256470) ) + "," ) + haxe.lang.Runtime.toString(__temp_stmt256472) ) + "," ) + haxe.lang.Runtime.toString(__temp_stmt256474) ) + "," ) + haxe.lang.Runtime.toString(__temp_stmt256476) ) + "]" );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256478 = true;
			switch (field.hashCode())
			{
				case 119:
				{
					if (field.equals("w")) 
					{
						__temp_executeDef256478 = false;
						this.w = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef256478 = false;
						this.length = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef256478 = false;
						this.z = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -101099250:
				{
					if (field.equals("lengthSqr")) 
					{
						__temp_executeDef256478 = false;
						this.lengthSqr = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef256478 = false;
						this.y = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256478 = false;
						this.x = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256478) 
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
			boolean __temp_executeDef256479 = true;
			switch (field.hashCode())
			{
				case 119:
				{
					if (field.equals("w")) 
					{
						__temp_executeDef256479 = false;
						this.w = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef256479 = false;
						this.clone = ((haxor.math.Vector4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef256479 = false;
						this.z = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3498292:
				{
					if (field.equals("rgba")) 
					{
						__temp_executeDef256479 = false;
						this.rgba = ((haxor.math.Color) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef256479 = false;
						this.y = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 112845:
				{
					if (field.equals("rgb")) 
					{
						__temp_executeDef256479 = false;
						this.rgb = ((haxor.math.Color) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256479 = false;
						this.x = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 119193:
				{
					if (field.equals("xyz")) 
					{
						__temp_executeDef256479 = false;
						this.xyz = ((haxor.math.Vector3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1255046409:
				{
					if (field.equals("normalized")) 
					{
						__temp_executeDef256479 = false;
						this.normalized = ((haxor.math.Vector4) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3841:
				{
					if (field.equals("xy")) 
					{
						__temp_executeDef256479 = false;
						this.xy = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -101099250:
				{
					if (field.equals("lengthSqr")) 
					{
						__temp_executeDef256479 = false;
						this.lengthSqr = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef256479 = false;
						this.length = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256479) 
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
			boolean __temp_executeDef256480 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef256480 = false;
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
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToArray"))) );
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_clone"))) );
					}
					
					break;
				}
				
				
				case -610626693:
				{
					if (field.equals("IsCulled")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("IsCulled"))) );
					}
					
					break;
				}
				
				
				case 3498292:
				{
					if (field.equals("rgba")) 
					{
						__temp_executeDef256480 = false;
						if (handleProperties) 
						{
							return this.get_rgba();
						}
						 else 
						{
							return this.rgba;
						}
						
					}
					
					break;
				}
				
				
				case -2054390035:
				{
					if (field.equals("Normalize")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Normalize"))) );
					}
					
					break;
				}
				
				
				case 1976610941:
				{
					if (field.equals("get_rgba")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_rgba"))) );
					}
					
					break;
				}
				
				
				case 79698218:
				{
					if (field.equals("Scale")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Scale"))) );
					}
					
					break;
				}
				
				
				case 112845:
				{
					if (field.equals("rgb")) 
					{
						__temp_executeDef256480 = false;
						if (handleProperties) 
						{
							return this.get_rgb();
						}
						 else 
						{
							return this.rgb;
						}
						
					}
					
					break;
				}
				
				
				case 718473796:
				{
					if (field.equals("Multiply")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Multiply"))) );
					}
					
					break;
				}
				
				
				case -74785692:
				{
					if (field.equals("get_rgb")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_rgb"))) );
					}
					
					break;
				}
				
				
				case 83488:
				{
					if (field.equals("Sub")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Sub"))) );
					}
					
					break;
				}
				
				
				case 119193:
				{
					if (field.equals("xyz")) 
					{
						__temp_executeDef256480 = false;
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
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add"))) );
					}
					
					break;
				}
				
				
				case -74779344:
				{
					if (field.equals("get_xyz")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_xyz"))) );
					}
					
					break;
				}
				
				
				case 1454199873:
				{
					if (field.equals("SetColor")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetColor"))) );
					}
					
					break;
				}
				
				
				case 3841:
				{
					if (field.equals("xy")) 
					{
						__temp_executeDef256480 = false;
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
				
				
				case 2573361:
				{
					if (field.equals("Set3")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set3"))) );
					}
					
					break;
				}
				
				
				case -1249338230:
				{
					if (field.equals("get_xy")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_xy"))) );
					}
					
					break;
				}
				
				
				case 2573360:
				{
					if (field.equals("Set2")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set2"))) );
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef256480 = false;
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
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Get"))) );
					}
					
					break;
				}
				
				
				case -101099250:
				{
					if (field.equals("lengthSqr")) 
					{
						__temp_executeDef256480 = false;
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
				
				
				case 119:
				{
					if (field.equals("w")) 
					{
						__temp_executeDef256480 = false;
						return this.w;
					}
					
					break;
				}
				
				
				case 413740901:
				{
					if (field.equals("get_lengthSqr")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_lengthSqr"))) );
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef256480 = false;
						return this.z;
					}
					
					break;
				}
				
				
				case -1255046409:
				{
					if (field.equals("normalized")) 
					{
						__temp_executeDef256480 = false;
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
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef256480 = false;
						return this.y;
					}
					
					break;
				}
				
				
				case 1820096384:
				{
					if (field.equals("get_normalized")) 
					{
						__temp_executeDef256480 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_normalized"))) );
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256480 = false;
						return this.x;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256480) 
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
			boolean __temp_executeDef256481 = true;
			switch (field.hashCode())
			{
				case 119:
				{
					if (field.equals("w")) 
					{
						__temp_executeDef256481 = false;
						return this.w;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef256481 = false;
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
						__temp_executeDef256481 = false;
						return this.z;
					}
					
					break;
				}
				
				
				case -101099250:
				{
					if (field.equals("lengthSqr")) 
					{
						__temp_executeDef256481 = false;
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
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef256481 = false;
						return this.y;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef256481 = false;
						return this.x;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256481) 
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
			boolean __temp_executeDef256482 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef256482 = false;
						return this.ToString(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef256482 = false;
						return this.get_clone();
					}
					
					break;
				}
				
				
				case 482271358:
				{
					if (field.equals("ToArray")) 
					{
						__temp_executeDef256482 = false;
						return this.ToArray();
					}
					
					break;
				}
				
				
				case 1976610941:
				{
					if (field.equals("get_rgba")) 
					{
						__temp_executeDef256482 = false;
						return this.get_rgba();
					}
					
					break;
				}
				
				
				case -610626693:
				{
					if (field.equals("IsCulled")) 
					{
						__temp_executeDef256482 = false;
						return this.IsCulled();
					}
					
					break;
				}
				
				
				case -74785692:
				{
					if (field.equals("get_rgb")) 
					{
						__temp_executeDef256482 = false;
						return this.get_rgb();
					}
					
					break;
				}
				
				
				case -2054390035:
				{
					if (field.equals("Normalize")) 
					{
						__temp_executeDef256482 = false;
						return this.Normalize();
					}
					
					break;
				}
				
				
				case -74779344:
				{
					if (field.equals("get_xyz")) 
					{
						__temp_executeDef256482 = false;
						return this.get_xyz();
					}
					
					break;
				}
				
				
				case 79698218:
				{
					if (field.equals("Scale")) 
					{
						__temp_executeDef256482 = false;
						return this.Scale(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1249338230:
				{
					if (field.equals("get_xy")) 
					{
						__temp_executeDef256482 = false;
						return this.get_xy();
					}
					
					break;
				}
				
				
				case 718473796:
				{
					if (field.equals("Multiply")) 
					{
						__temp_executeDef256482 = false;
						return this.Multiply(((haxor.math.Vector4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef256482 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case 83488:
				{
					if (field.equals("Sub")) 
					{
						__temp_executeDef256482 = false;
						return this.Sub(((haxor.math.Vector4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 413740901:
				{
					if (field.equals("get_lengthSqr")) 
					{
						__temp_executeDef256482 = false;
						return this.get_lengthSqr();
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef256482 = false;
						return this.Add(((haxor.math.Vector4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1820096384:
				{
					if (field.equals("get_normalized")) 
					{
						__temp_executeDef256482 = false;
						return this.get_normalized();
					}
					
					break;
				}
				
				
				case 1454199873:
				{
					if (field.equals("SetColor")) 
					{
						__temp_executeDef256482 = false;
						return this.SetColor(((haxor.math.Color) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef256482 = false;
						return this.Get(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 2573361:
				{
					if (field.equals("Set3")) 
					{
						__temp_executeDef256482 = false;
						return this.Set3(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef256482 = false;
						return this.Set(dynargs.__get(0), dynargs.__get(1), dynargs.__get(2), dynargs.__get(3));
					}
					
					break;
				}
				
				
				case 2573360:
				{
					if (field.equals("Set2")) 
					{
						__temp_executeDef256482 = false;
						return this.Set2(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256482) 
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
		baseArr.push("w");
		baseArr.push("z");
		baseArr.push("y");
		baseArr.push("x");
		baseArr.push("normalized");
		baseArr.push("lengthSqr");
		baseArr.push("length");
		baseArr.push("xy");
		baseArr.push("xyz");
		baseArr.push("rgb");
		baseArr.push("rgba");
		baseArr.push("clone");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


