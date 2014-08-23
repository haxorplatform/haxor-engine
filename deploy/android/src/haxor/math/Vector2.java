package haxor.math;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Vector2 extends haxe.lang.HxObject
{
	public    Vector2(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Vector2(java.lang.Object p_x, java.lang.Object p_y)
	{
		haxor.math.Vector2.__hx_ctor_haxor_math_Vector2(this, p_x, p_y);
	}
	
	
	public static   void __hx_ctor_haxor_math_Vector2(haxor.math.Vector2 __temp_me56195, java.lang.Object p_x, java.lang.Object p_y)
	{
		double __temp_p_y56194 = ( (( p_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_y)) )) );
		double __temp_p_x56193 = ( (( p_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_x)) )) );
		__temp_me56195.x = __temp_p_x56193;
		__temp_me56195.y = __temp_p_y56194;
	}
	
	
	public static  haxor.math.Vector2 temp;
	
	public static   haxor.math.Vector2 get_temp()
	{
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			return _this.m_v2.__get(_this.m_nv2 = ( (( _this.m_nv2 + 1 )) % _this.m_v2.length ));
		}
		
	}
	
	
	public static  haxor.math.Vector2 zero;
	
	public static   haxor.math.Vector2 get_zero()
	{
		return new haxor.math.Vector2(((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
	}
	
	
	public static  haxor.math.Vector2 one;
	
	public static   haxor.math.Vector2 get_one()
	{
		return new haxor.math.Vector2(((java.lang.Object) (1) ), ((java.lang.Object) (1) ));
	}
	
	
	public static  haxor.math.Vector2 right;
	
	public static   haxor.math.Vector2 get_right()
	{
		return new haxor.math.Vector2(((java.lang.Object) (1) ), ((java.lang.Object) (0) ));
	}
	
	
	public static  haxor.math.Vector2 up;
	
	public static   haxor.math.Vector2 get_up()
	{
		return new haxor.math.Vector2(((java.lang.Object) (0) ), ((java.lang.Object) (1) ));
	}
	
	
	public static   double Dot(haxor.math.Vector2 p_a, haxor.math.Vector2 p_b)
	{
		return ( ( p_a.x * p_b.x ) + ( p_a.y * p_b.y ) );
	}
	
	
	public static   haxor.math.Vector2 Lerp(haxor.math.Vector2 p_a, haxor.math.Vector2 p_b, double p_r)
	{
		return new haxor.math.Vector2(((java.lang.Object) (( p_a.x + ( (( p_b.x - p_a.x )) * p_r ) )) ), ((java.lang.Object) (( p_a.y + ( (( p_b.y - p_a.y )) * p_r ) )) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.math.Vector2(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.math.Vector2(((java.lang.Object) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ));
	}
	
	
	public  haxor.math.Vector2 clone;
	
	public final   haxor.math.Vector2 get_clone()
	{
		return new haxor.math.Vector2(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ));
	}
	
	
	public  haxor.math.Vector2 xy;
	
	public final   haxor.math.Vector2 get_xy()
	{
		return new haxor.math.Vector2(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ));
	}
	
	
	public  haxor.math.Vector2 yx;
	
	public final   haxor.math.Vector2 get_yx()
	{
		return new haxor.math.Vector2(((java.lang.Object) (this.y) ), ((java.lang.Object) (this.x) ));
	}
	
	
	public  double length;
	
	public final   double get_length()
	{
		return java.lang.Math.sqrt(( ( this.x * this.x ) + ( this.y * this.y ) ));
	}
	
	
	public  double lengthSqr;
	
	public final   double get_lengthSqr()
	{
		return ( ( this.x * this.x ) + ( this.y * this.y ) );
	}
	
	
	public  haxor.math.Vector2 normalized;
	
	public final   haxor.math.Vector2 get_normalized()
	{
		return new haxor.math.Vector2(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) )).Normalize();
	}
	
	
	public  haxor.math.Vector2 inverse;
	
	public final   haxor.math.Vector2 get_inverse()
	{
		{
			haxor.math.Vector2 _this = new haxor.math.Vector2(((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) ));
			_this.x =  - (_this.x) ;
			_this.y =  - (_this.y) ;
			return _this;
		}
		
	}
	
	
	public  double x;
	
	public  double y;
	
	public   haxor.math.Vector2 Set(java.lang.Object p_x, java.lang.Object p_y)
	{
		double __temp_p_y56191 = ( (( p_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_y)) )) );
		double __temp_p_x56190 = ( (( p_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_x)) )) );
		this.x = __temp_p_x56190;
		this.y = __temp_p_y56191;
		return this;
	}
	
	
	public   haxor.math.Vector2 Set2(haxor.math.Vector2 v)
	{
		this.x = v.x;
		this.y = v.y;
		return this;
	}
	
	
	public   haxor.math.Vector2 Set3(haxor.math.Vector3 v)
	{
		this.x = v.x;
		this.y = v.y;
		return this;
	}
	
	
	public   haxor.math.Vector2 Set4(haxor.math.Vector4 v)
	{
		this.x = v.x;
		this.y = v.y;
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
			return this.y;
		}
		
	}
	
	
	public   haxor.math.Vector2 Add(haxor.math.Vector2 p_v)
	{
		this.x += p_v.x;
		this.y += p_v.y;
		return this;
	}
	
	
	public   haxor.math.Vector2 Sub(haxor.math.Vector2 p_v)
	{
		this.x -= p_v.x;
		this.y -= p_v.y;
		return this;
	}
	
	
	public   haxor.math.Vector2 Multiply(haxor.math.Vector2 p_v)
	{
		this.x *= p_v.x;
		this.y *= p_v.y;
		return this;
	}
	
	
	public   haxor.math.Vector2 Scale(double p_s)
	{
		this.x *= p_s;
		this.y *= p_s;
		return this;
	}
	
	
	public   boolean Step(haxor.math.Vector2 p_to, double p_step)
	{
		double vx = ( p_to.x - this.x );
		double vy = ( p_to.y - this.y );
		double l = java.lang.Math.sqrt(( ( vx * vx ) + ( vy * vy ) ));
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
		this.x += vx;
		this.y += vy;
		return true;
	}
	
	
	public   haxor.math.Vector2 Reflect(haxor.math.Vector2 p_normal)
	{
		double d = ( java.lang.Math.min(0.0, ( ( p_normal.x * this.x ) + ( p_normal.y * this.y ) )) * 2.0 );
		this.x += (  - (p_normal.x)  * d );
		this.y += (  - (p_normal.y)  * d );
		return this;
	}
	
	
	public final   haxor.math.Vector2 Invert()
	{
		this.x =  - (this.x) ;
		this.y =  - (this.y) ;
		return this;
	}
	
	
	public   haxor.math.Vector2 Normalize()
	{
		double l = java.lang.Math.sqrt(( ( this.x * this.x ) + ( this.y * this.y ) ));
		if (( l <= 0 )) 
		{
			return this;
		}
		
		this.x *= l = ( 1.0 / l );
		this.y *= l;
		return this;
	}
	
	
	public   haxe.root.Array<java.lang.Object> ToArray()
	{
		return new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (this.x) ), ((java.lang.Object) (this.y) )});
	}
	
	
	public   java.lang.String ToString(java.lang.Object p_places)
	{
		int __temp_p_places56192 = ( (( p_places == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_places)) )) );
		double __temp_stmt56530 = 0.0;
		{
			double d = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places56192) ));
			double __temp_stmt56531 = 0.0;
			{
				double p_v = ( this.x * d );
				__temp_stmt56531 = ((double) (((int) (( p_v + (( (( p_v < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt56530 = ( __temp_stmt56531 / d );
		}
		
		double __temp_stmt56532 = 0.0;
		{
			double d1 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places56192) ));
			double __temp_stmt56533 = 0.0;
			{
				double p_v1 = ( this.y * d1 );
				__temp_stmt56533 = ((double) (((int) (( p_v1 + (( (( p_v1 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt56532 = ( __temp_stmt56533 / d1 );
		}
		
		return ( ( ( ( "[" + haxe.lang.Runtime.toString(__temp_stmt56530) ) + "," ) + haxe.lang.Runtime.toString(__temp_stmt56532) ) + "]" );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef56534 = true;
			switch (field.hashCode())
			{
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef56534 = false;
						this.y = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef56534 = false;
						this.length = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef56534 = false;
						this.x = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -101099250:
				{
					if (field.equals("lengthSqr")) 
					{
						__temp_executeDef56534 = false;
						this.lengthSqr = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56534) 
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
			boolean __temp_executeDef56535 = true;
			switch (field.hashCode())
			{
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef56535 = false;
						this.y = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef56535 = false;
						this.clone = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef56535 = false;
						this.x = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3841:
				{
					if (field.equals("xy")) 
					{
						__temp_executeDef56535 = false;
						this.xy = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1959910192:
				{
					if (field.equals("inverse")) 
					{
						__temp_executeDef56535 = false;
						this.inverse = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3871:
				{
					if (field.equals("yx")) 
					{
						__temp_executeDef56535 = false;
						this.yx = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1255046409:
				{
					if (field.equals("normalized")) 
					{
						__temp_executeDef56535 = false;
						this.normalized = ((haxor.math.Vector2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef56535 = false;
						this.length = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -101099250:
				{
					if (field.equals("lengthSqr")) 
					{
						__temp_executeDef56535 = false;
						this.lengthSqr = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56535) 
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
			boolean __temp_executeDef56536 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef56536 = false;
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
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToArray"))) );
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_clone"))) );
					}
					
					break;
				}
				
				
				case -2054390035:
				{
					if (field.equals("Normalize")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Normalize"))) );
					}
					
					break;
				}
				
				
				case 3841:
				{
					if (field.equals("xy")) 
					{
						__temp_executeDef56536 = false;
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
				
				
				case -2099835914:
				{
					if (field.equals("Invert")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Invert"))) );
					}
					
					break;
				}
				
				
				case -1249338230:
				{
					if (field.equals("get_xy")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_xy"))) );
					}
					
					break;
				}
				
				
				case -1545048419:
				{
					if (field.equals("Reflect")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Reflect"))) );
					}
					
					break;
				}
				
				
				case 3871:
				{
					if (field.equals("yx")) 
					{
						__temp_executeDef56536 = false;
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
				
				
				case 2587372:
				{
					if (field.equals("Step")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Step"))) );
					}
					
					break;
				}
				
				
				case -1249338200:
				{
					if (field.equals("get_yx")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_yx"))) );
					}
					
					break;
				}
				
				
				case 79698218:
				{
					if (field.equals("Scale")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Scale"))) );
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef56536 = false;
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
				
				
				case 718473796:
				{
					if (field.equals("Multiply")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Multiply"))) );
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
				case 83488:
				{
					if (field.equals("Sub")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Sub"))) );
					}
					
					break;
				}
				
				
				case -101099250:
				{
					if (field.equals("lengthSqr")) 
					{
						__temp_executeDef56536 = false;
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
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add"))) );
					}
					
					break;
				}
				
				
				case 413740901:
				{
					if (field.equals("get_lengthSqr")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_lengthSqr"))) );
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Get"))) );
					}
					
					break;
				}
				
				
				case -1255046409:
				{
					if (field.equals("normalized")) 
					{
						__temp_executeDef56536 = false;
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
				
				
				case 2573362:
				{
					if (field.equals("Set4")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set4"))) );
					}
					
					break;
				}
				
				
				case 1820096384:
				{
					if (field.equals("get_normalized")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_normalized"))) );
					}
					
					break;
				}
				
				
				case 2573361:
				{
					if (field.equals("Set3")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set3"))) );
					}
					
					break;
				}
				
				
				case 1959910192:
				{
					if (field.equals("inverse")) 
					{
						__temp_executeDef56536 = false;
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
				
				
				case 2573360:
				{
					if (field.equals("Set2")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set2"))) );
					}
					
					break;
				}
				
				
				case 2036423495:
				{
					if (field.equals("get_inverse")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_inverse"))) );
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef56536 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef56536 = false;
						return this.x;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef56536 = false;
						return this.y;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56536) 
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
			boolean __temp_executeDef56537 = true;
			switch (field.hashCode())
			{
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef56537 = false;
						return this.y;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef56537 = false;
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
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef56537 = false;
						return this.x;
					}
					
					break;
				}
				
				
				case -101099250:
				{
					if (field.equals("lengthSqr")) 
					{
						__temp_executeDef56537 = false;
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
				
				
			}
			
			if (__temp_executeDef56537) 
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
			boolean __temp_executeDef56538 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef56538 = false;
						return this.ToString(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef56538 = false;
						return this.get_clone();
					}
					
					break;
				}
				
				
				case 482271358:
				{
					if (field.equals("ToArray")) 
					{
						__temp_executeDef56538 = false;
						return this.ToArray();
					}
					
					break;
				}
				
				
				case -1249338230:
				{
					if (field.equals("get_xy")) 
					{
						__temp_executeDef56538 = false;
						return this.get_xy();
					}
					
					break;
				}
				
				
				case -2054390035:
				{
					if (field.equals("Normalize")) 
					{
						__temp_executeDef56538 = false;
						return this.Normalize();
					}
					
					break;
				}
				
				
				case -1249338200:
				{
					if (field.equals("get_yx")) 
					{
						__temp_executeDef56538 = false;
						return this.get_yx();
					}
					
					break;
				}
				
				
				case -2099835914:
				{
					if (field.equals("Invert")) 
					{
						__temp_executeDef56538 = false;
						return this.Invert();
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef56538 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case -1545048419:
				{
					if (field.equals("Reflect")) 
					{
						__temp_executeDef56538 = false;
						return this.Reflect(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 413740901:
				{
					if (field.equals("get_lengthSqr")) 
					{
						__temp_executeDef56538 = false;
						return this.get_lengthSqr();
					}
					
					break;
				}
				
				
				case 2587372:
				{
					if (field.equals("Step")) 
					{
						__temp_executeDef56538 = false;
						return this.Step(((haxor.math.Vector2) (dynargs.__get(0)) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 1820096384:
				{
					if (field.equals("get_normalized")) 
					{
						__temp_executeDef56538 = false;
						return this.get_normalized();
					}
					
					break;
				}
				
				
				case 79698218:
				{
					if (field.equals("Scale")) 
					{
						__temp_executeDef56538 = false;
						return this.Scale(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 2036423495:
				{
					if (field.equals("get_inverse")) 
					{
						__temp_executeDef56538 = false;
						return this.get_inverse();
					}
					
					break;
				}
				
				
				case 718473796:
				{
					if (field.equals("Multiply")) 
					{
						__temp_executeDef56538 = false;
						return this.Multiply(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef56538 = false;
						return this.Set(dynargs.__get(0), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 83488:
				{
					if (field.equals("Sub")) 
					{
						__temp_executeDef56538 = false;
						return this.Sub(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2573360:
				{
					if (field.equals("Set2")) 
					{
						__temp_executeDef56538 = false;
						return this.Set2(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef56538 = false;
						return this.Add(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2573361:
				{
					if (field.equals("Set3")) 
					{
						__temp_executeDef56538 = false;
						return this.Set3(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef56538 = false;
						return this.Get(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 2573362:
				{
					if (field.equals("Set4")) 
					{
						__temp_executeDef56538 = false;
						return this.Set4(((haxor.math.Vector4) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56538) 
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
		baseArr.push("y");
		baseArr.push("x");
		baseArr.push("inverse");
		baseArr.push("normalized");
		baseArr.push("lengthSqr");
		baseArr.push("length");
		baseArr.push("yx");
		baseArr.push("xy");
		baseArr.push("clone");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


