package haxor.math;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class AABB2 extends haxe.lang.HxObject
{
	public    AABB2(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    AABB2(java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_width, java.lang.Object p_height)
	{
		haxor.math.AABB2.__hx_ctor_haxor_math_AABB2(this, p_x, p_y, p_width, p_height);
	}
	
	
	public static   void __hx_ctor_haxor_math_AABB2(haxor.math.AABB2 __temp_me199, java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_width, java.lang.Object p_height)
	{
		double __temp_p_height198 = ( (( p_height == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_height)) )) );
		double __temp_p_width197 = ( (( p_width == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_width)) )) );
		double __temp_p_y196 = ( (( p_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_y)) )) );
		double __temp_p_x195 = ( (( p_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_x)) )) );
		__temp_me199.SetXYWH(__temp_p_x195, __temp_p_y196, __temp_p_width197, __temp_p_height198);
	}
	
	
	public static  haxor.math.AABB2 temp;
	
	public static   haxor.math.AABB2 get_temp()
	{
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			return _this.m_aabb2.__get(_this.m_naabb2 = ( (( _this.m_naabb2 + 1 )) % _this.m_aabb2.length ));
		}
		
	}
	
	
	public static   haxor.math.AABB2 FromMinMax(double p_xmin, double p_xmax, double p_ymin, double p_ymax)
	{
		haxor.math.AABB2 b = new haxor.math.AABB2(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		b.m_xMin = p_xmin;
		b.m_xMax = p_xmax;
		b.m_yMin = p_ymin;
		b.m_yMax = p_ymax;
		b.Validate();
		return b;
	}
	
	
	public static  haxor.math.AABB2 empty;
	
	public static   haxor.math.AABB2 get_empty()
	{
		return new haxor.math.AABB2(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.math.AABB2(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.math.AABB2(((java.lang.Object) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ), ((java.lang.Object) (arr.__get(2)) ), ((java.lang.Object) (arr.__get(3)) ));
	}
	
	
	public  haxor.math.AABB2 clone;
	
	public   haxor.math.AABB2 get_clone()
	{
		return haxor.math.AABB2.FromMinMax(this.get_xMin(), this.get_xMax(), this.get_yMin(), this.get_yMax());
	}
	
	
	
	
	public   haxor.math.Vector2 get_min()
	{
		return new haxor.math.Vector2(((java.lang.Object) (this.m_xMin) ), ((java.lang.Object) (this.m_yMin) ));
	}
	
	
	public   haxor.math.Vector2 set_min(haxor.math.Vector2 v)
	{
		this.set_xMin(v.x);
		this.set_yMin(v.y);
		return v;
	}
	
	
	
	
	public   haxor.math.Vector2 get_max()
	{
		return new haxor.math.Vector2(((java.lang.Object) (this.m_xMax) ), ((java.lang.Object) (this.m_yMax) ));
	}
	
	
	public   haxor.math.Vector2 set_max(haxor.math.Vector2 v)
	{
		this.set_xMax(v.x);
		this.set_yMax(v.y);
		return v;
	}
	
	
	
	
	public   double get_xMin()
	{
		return this.m_xMin;
	}
	
	
	public   double set_xMin(double v)
	{
		this.m_xMin = v;
		this.Validate();
		return v;
	}
	
	
	public  double m_xMin;
	
	
	
	public   double get_yMin()
	{
		return this.m_yMin;
	}
	
	
	public   double set_yMin(double v)
	{
		this.m_yMin = v;
		this.Validate();
		return v;
	}
	
	
	public  double m_yMin;
	
	
	
	public   double get_xMax()
	{
		return this.m_xMax;
	}
	
	
	public   double set_xMax(double v)
	{
		this.m_xMax = v;
		this.Validate();
		return v;
	}
	
	
	public  double m_xMax;
	
	
	
	public   double get_yMax()
	{
		return this.m_yMax;
	}
	
	
	public   double set_yMax(double v)
	{
		this.m_yMax = v;
		this.Validate();
		return v;
	}
	
	
	public  double m_yMax;
	
	
	
	public   haxor.math.Vector2 get_center()
	{
		return new haxor.math.Vector2(((java.lang.Object) (( this.get_xMin() + ( (( this.get_xMax() - this.get_xMin() )) * 0.5 ) )) ), ((java.lang.Object) (( this.get_yMin() + ( (( this.get_yMax() - this.get_yMin() )) * 0.5 ) )) ));
	}
	
	
	public   haxor.math.Vector2 set_center(haxor.math.Vector2 v)
	{
		double hw = 0.0;
		double __temp_stmt966 = 0.0;
		{
			double p_a = ( this.get_xMax() - this.get_xMin() );
			__temp_stmt966 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
		}
		
		hw = ( __temp_stmt966 * 0.5 );
		double hh = 0.0;
		double __temp_stmt967 = 0.0;
		{
			double p_a1 = ( this.get_yMax() - this.get_yMin() );
			__temp_stmt967 = ( (( p_a1 < 0 )) ? ( - (p_a1) ) : (p_a1) );
		}
		
		hh = ( __temp_stmt967 * 0.5 );
		this.m_xMin = ( v.x - hw );
		this.m_xMax = ( v.x + hw );
		this.m_yMin = ( v.y - hh );
		this.m_yMax = ( v.y + hh );
		return v;
	}
	
	
	
	
	public final   double get_x()
	{
		return this.get_xMin();
	}
	
	
	public final   double set_x(double v)
	{
		this.set_xMin(v);
		return v;
	}
	
	
	
	
	public final   double get_y()
	{
		return this.get_yMin();
	}
	
	
	public final   double set_y(double v)
	{
		this.set_yMin(v);
		return v;
	}
	
	
	
	
	public final   double get_width()
	{
		{
			double p_a = ( this.get_xMax() - this.get_xMin() );
			if (( p_a < 0 )) 
			{
				return  - (p_a) ;
			}
			 else 
			{
				return p_a;
			}
			
		}
		
	}
	
	
	public final   double set_width(double v)
	{
		this.set_xMax(( this.get_xMin() + v ));
		return v;
	}
	
	
	
	
	public final   double get_height()
	{
		{
			double p_a = ( this.get_yMax() - this.get_yMin() );
			if (( p_a < 0 )) 
			{
				return  - (p_a) ;
			}
			 else 
			{
				return p_a;
			}
			
		}
		
	}
	
	
	public final   double set_height(double v)
	{
		this.set_yMax(( this.get_yMin() + v ));
		return v;
	}
	
	
	
	
	public final   haxor.math.Vector2 get_size()
	{
		double __temp_stmt968 = 0.0;
		{
			double p_a = ( this.get_xMax() - this.get_xMin() );
			__temp_stmt968 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
		}
		
		double __temp_stmt969 = 0.0;
		{
			double p_a1 = ( this.get_yMax() - this.get_yMin() );
			__temp_stmt969 = ( (( p_a1 < 0 )) ? ( - (p_a1) ) : (p_a1) );
		}
		
		return new haxor.math.Vector2(((java.lang.Object) (__temp_stmt968) ), ((java.lang.Object) (__temp_stmt969) ));
	}
	
	
	public final   haxor.math.Vector2 set_size(haxor.math.Vector2 v)
	{
		{
			double v1 = v.x;
			this.set_xMax(( this.get_xMin() + v1 ));
			double __temp_expr970 = v1;
		}
		
		{
			double v2 = v.y;
			this.set_yMax(( this.get_yMin() + v2 ));
			double __temp_expr971 = v2;
		}
		
		return v;
	}
	
	
	public   void Validate()
	{
		{
		}
		
	}
	
	
	public   haxor.math.AABB2 Add(haxor.math.AABB2 p_v)
	{
		this.m_xMax = java.lang.Math.max(p_v.m_xMax, this.m_xMax);
		this.m_xMin = java.lang.Math.min(p_v.m_xMin, this.m_xMin);
		this.m_yMax = java.lang.Math.max(p_v.m_yMax, this.m_yMax);
		this.m_yMin = java.lang.Math.min(p_v.m_yMin, this.m_yMin);
		return this;
	}
	
	
	public   haxor.math.AABB2 Set(double p_xmin, double p_xmax, double p_ymin, double p_ymax)
	{
		this.m_xMin = p_xmin;
		this.m_yMin = p_ymin;
		this.m_xMax = p_xmax;
		this.m_yMax = p_ymax;
		this.Validate();
		return this;
	}
	
	
	public   haxor.math.AABB2 SetXYWH(double p_x, double p_y, double p_width, double p_height)
	{
		this.m_xMin = p_x;
		this.m_yMin = p_y;
		this.m_xMax = ( this.m_xMin + p_width );
		this.m_yMax = ( this.m_yMin + p_height );
		return this;
	}
	
	
	public   haxor.math.AABB2 SetAABB2(haxor.math.AABB2 p_v)
	{
		this.m_xMin = p_v.m_xMin;
		this.m_yMin = p_v.m_yMin;
		this.m_xMax = p_v.m_xMax;
		this.m_yMax = p_v.m_yMax;
		return this;
	}
	
	
	public   void Encapsulate(haxor.math.Vector2 p_point)
	{
		double __temp_stmt972 = 0.0;
		{
			double b = this.get_xMin();
			__temp_stmt972 = java.lang.Math.min(p_point.x, b);
		}
		
		this.set_xMin(__temp_stmt972);
		double __temp_stmt973 = 0.0;
		{
			double b1 = this.get_xMax();
			__temp_stmt973 = java.lang.Math.max(p_point.x, b1);
		}
		
		this.set_xMax(__temp_stmt973);
		double __temp_stmt974 = 0.0;
		{
			double b2 = this.get_yMin();
			__temp_stmt974 = java.lang.Math.min(p_point.y, b2);
		}
		
		this.set_yMin(__temp_stmt974);
		double __temp_stmt975 = 0.0;
		{
			double b3 = this.get_yMax();
			__temp_stmt975 = java.lang.Math.max(p_point.y, b3);
		}
		
		this.set_yMax(__temp_stmt975);
	}
	
	
	public   haxor.math.AABB2 Encapsulate3(java.lang.Object p_x, java.lang.Object p_y)
	{
		double __temp_p_y193 = ( (( p_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_y)) )) );
		double __temp_p_x192 = ( (( p_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_x)) )) );
		this.m_xMin = java.lang.Math.min(__temp_p_x192, this.m_xMin);
		this.m_xMax = java.lang.Math.max(__temp_p_x192, this.m_xMax);
		this.m_yMin = java.lang.Math.min(__temp_p_y193, this.m_yMin);
		this.m_yMax = java.lang.Math.max(__temp_p_y193, this.m_yMax);
		this.Validate();
		return this;
	}
	
	
	public   java.lang.String ToString(java.lang.Object p_places)
	{
		int __temp_p_places194 = ( (( p_places == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_places)) )) );
		java.lang.String s0 = null;
		double __temp_stmt976 = 0.0;
		{
			double d = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places194) ));
			double __temp_stmt977 = 0.0;
			{
				double p_v = ( this.m_xMin * d );
				__temp_stmt977 = ((double) (((int) (( p_v + (( (( p_v < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt976 = ( __temp_stmt977 / d );
		}
		
		s0 = ( haxe.lang.Runtime.toString(__temp_stmt976) + "" );
		java.lang.String s1 = null;
		double __temp_stmt978 = 0.0;
		{
			double d1 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places194) ));
			double __temp_stmt979 = 0.0;
			{
				double p_v1 = ( this.m_xMax * d1 );
				__temp_stmt979 = ((double) (((int) (( p_v1 + (( (( p_v1 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt978 = ( __temp_stmt979 / d1 );
		}
		
		s1 = ( haxe.lang.Runtime.toString(__temp_stmt978) + "" );
		java.lang.String s2 = null;
		double __temp_stmt980 = 0.0;
		{
			double d2 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places194) ));
			double __temp_stmt981 = 0.0;
			{
				double p_v2 = ( this.m_yMin * d2 );
				__temp_stmt981 = ((double) (((int) (( p_v2 + (( (( p_v2 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt980 = ( __temp_stmt981 / d2 );
		}
		
		s2 = ( haxe.lang.Runtime.toString(__temp_stmt980) + "" );
		java.lang.String s3 = null;
		double __temp_stmt982 = 0.0;
		{
			double d3 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places194) ));
			double __temp_stmt983 = 0.0;
			{
				double p_v3 = ( this.m_yMax * d3 );
				__temp_stmt983 = ((double) (((int) (( p_v3 + (( (( p_v3 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt982 = ( __temp_stmt983 / d3 );
		}
		
		s3 = ( haxe.lang.Runtime.toString(__temp_stmt982) + "" );
		return ( ( ( ( ( ( ( ( "[" + s0 ) + "," ) + s1 ) + "|" ) + s2 ) + "," ) + s3 ) + "]" );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef984 = true;
			switch (field.hashCode())
			{
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef984 = false;
						this.set_height(value);
						return value;
					}
					
					break;
				}
				
				
				case 3652282:
				{
					if (field.equals("xMin")) 
					{
						__temp_executeDef984 = false;
						this.set_xMin(value);
						return value;
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef984 = false;
						this.set_width(value);
						return value;
					}
					
					break;
				}
				
				
				case -1083003060:
				{
					if (field.equals("m_xMin")) 
					{
						__temp_executeDef984 = false;
						this.m_xMin = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef984 = false;
						this.set_y(value);
						return value;
					}
					
					break;
				}
				
				
				case 3682073:
				{
					if (field.equals("yMin")) 
					{
						__temp_executeDef984 = false;
						this.set_yMin(value);
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef984 = false;
						this.set_x(value);
						return value;
					}
					
					break;
				}
				
				
				case -1082973269:
				{
					if (field.equals("m_yMin")) 
					{
						__temp_executeDef984 = false;
						this.m_yMin = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1082973507:
				{
					if (field.equals("m_yMax")) 
					{
						__temp_executeDef984 = false;
						this.m_yMax = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3652044:
				{
					if (field.equals("xMax")) 
					{
						__temp_executeDef984 = false;
						this.set_xMax(value);
						return value;
					}
					
					break;
				}
				
				
				case 3681835:
				{
					if (field.equals("yMax")) 
					{
						__temp_executeDef984 = false;
						this.set_yMax(value);
						return value;
					}
					
					break;
				}
				
				
				case -1083003298:
				{
					if (field.equals("m_xMax")) 
					{
						__temp_executeDef984 = false;
						this.m_xMax = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef984) 
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
			boolean __temp_executeDef985 = true;
			switch (field.hashCode())
			{
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef985 = false;
						this.set_size(((haxor.math.Vector2) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef985 = false;
						this.clone = ((haxor.math.AABB2) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef985 = false;
						this.set_height(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 108114:
				{
					if (field.equals("min")) 
					{
						__temp_executeDef985 = false;
						this.set_min(((haxor.math.Vector2) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef985 = false;
						this.set_width(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 107876:
				{
					if (field.equals("max")) 
					{
						__temp_executeDef985 = false;
						this.set_max(((haxor.math.Vector2) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef985 = false;
						this.set_y(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 3652282:
				{
					if (field.equals("xMin")) 
					{
						__temp_executeDef985 = false;
						this.set_xMin(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef985 = false;
						this.set_x(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -1083003060:
				{
					if (field.equals("m_xMin")) 
					{
						__temp_executeDef985 = false;
						this.m_xMin = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1364013995:
				{
					if (field.equals("center")) 
					{
						__temp_executeDef985 = false;
						this.set_center(((haxor.math.Vector2) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 3682073:
				{
					if (field.equals("yMin")) 
					{
						__temp_executeDef985 = false;
						this.set_yMin(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -1082973507:
				{
					if (field.equals("m_yMax")) 
					{
						__temp_executeDef985 = false;
						this.m_yMax = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1082973269:
				{
					if (field.equals("m_yMin")) 
					{
						__temp_executeDef985 = false;
						this.m_yMin = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3681835:
				{
					if (field.equals("yMax")) 
					{
						__temp_executeDef985 = false;
						this.set_yMax(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 3652044:
				{
					if (field.equals("xMax")) 
					{
						__temp_executeDef985 = false;
						this.set_xMax(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -1083003298:
				{
					if (field.equals("m_xMax")) 
					{
						__temp_executeDef985 = false;
						this.m_xMax = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef985) 
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
			boolean __temp_executeDef986 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef986 = false;
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
				
				
				case -1221447006:
				{
					if (field.equals("Encapsulate3")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Encapsulate3"))) );
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_clone"))) );
					}
					
					break;
				}
				
				
				case -1147780175:
				{
					if (field.equals("Encapsulate")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Encapsulate"))) );
					}
					
					break;
				}
				
				
				case 108114:
				{
					if (field.equals("min")) 
					{
						__temp_executeDef986 = false;
						return this.get_min();
					}
					
					break;
				}
				
				
				case 1450940624:
				{
					if (field.equals("SetAABB2")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetAABB2"))) );
					}
					
					break;
				}
				
				
				case -74790423:
				{
					if (field.equals("get_min")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_min"))) );
					}
					
					break;
				}
				
				
				case -645223212:
				{
					if (field.equals("SetXYWH")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetXYWH"))) );
					}
					
					break;
				}
				
				
				case 1985319157:
				{
					if (field.equals("set_min")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_min"))) );
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 107876:
				{
					if (field.equals("max")) 
					{
						__temp_executeDef986 = false;
						return this.get_max();
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add"))) );
					}
					
					break;
				}
				
				
				case -74790661:
				{
					if (field.equals("get_max")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_max"))) );
					}
					
					break;
				}
				
				
				case -1356628682:
				{
					if (field.equals("Validate")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Validate"))) );
					}
					
					break;
				}
				
				
				case 1985318919:
				{
					if (field.equals("set_max")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_max"))) );
					}
					
					break;
				}
				
				
				case 1415530942:
				{
					if (field.equals("set_size")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_size"))) );
					}
					
					break;
				}
				
				
				case 3652282:
				{
					if (field.equals("xMin")) 
					{
						__temp_executeDef986 = false;
						return this.get_xMin();
					}
					
					break;
				}
				
				
				case 1976643402:
				{
					if (field.equals("get_size")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_size"))) );
					}
					
					break;
				}
				
				
				case 1976764931:
				{
					if (field.equals("get_xMin")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_xMin"))) );
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef986 = false;
						return this.get_size();
					}
					
					break;
				}
				
				
				case 1415652471:
				{
					if (field.equals("set_xMin")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_xMin"))) );
					}
					
					break;
				}
				
				
				case -1498513500:
				{
					if (field.equals("set_height")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_height"))) );
					}
					
					break;
				}
				
				
				case -1083003060:
				{
					if (field.equals("m_xMin")) 
					{
						__temp_executeDef986 = false;
						return this.m_xMin;
					}
					
					break;
				}
				
				
				case 859648560:
				{
					if (field.equals("get_height")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_height"))) );
					}
					
					break;
				}
				
				
				case 3682073:
				{
					if (field.equals("yMin")) 
					{
						__temp_executeDef986 = false;
						return this.get_yMin();
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef986 = false;
						return this.get_height();
					}
					
					break;
				}
				
				
				case 1976794722:
				{
					if (field.equals("get_yMin")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_yMin"))) );
					}
					
					break;
				}
				
				
				case 935459753:
				{
					if (field.equals("set_width")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_width"))) );
					}
					
					break;
				}
				
				
				case 1415682262:
				{
					if (field.equals("set_yMin")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_yMin"))) );
					}
					
					break;
				}
				
				
				case 1150076829:
				{
					if (field.equals("get_width")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_width"))) );
					}
					
					break;
				}
				
				
				case -1082973269:
				{
					if (field.equals("m_yMin")) 
					{
						__temp_executeDef986 = false;
						return this.m_yMin;
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef986 = false;
						return this.get_width();
					}
					
					break;
				}
				
				
				case 3652044:
				{
					if (field.equals("xMax")) 
					{
						__temp_executeDef986 = false;
						return this.get_xMax();
					}
					
					break;
				}
				
				
				case 109328348:
				{
					if (field.equals("set_y")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_y"))) );
					}
					
					break;
				}
				
				
				case 1976764693:
				{
					if (field.equals("get_xMax")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_xMax"))) );
					}
					
					break;
				}
				
				
				case 98246096:
				{
					if (field.equals("get_y")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_y"))) );
					}
					
					break;
				}
				
				
				case 1415652233:
				{
					if (field.equals("set_xMax")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_xMax"))) );
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef986 = false;
						return this.get_y();
					}
					
					break;
				}
				
				
				case -1083003298:
				{
					if (field.equals("m_xMax")) 
					{
						__temp_executeDef986 = false;
						return this.m_xMax;
					}
					
					break;
				}
				
				
				case 109328347:
				{
					if (field.equals("set_x")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_x"))) );
					}
					
					break;
				}
				
				
				case 3681835:
				{
					if (field.equals("yMax")) 
					{
						__temp_executeDef986 = false;
						return this.get_yMax();
					}
					
					break;
				}
				
				
				case 98246095:
				{
					if (field.equals("get_x")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_x"))) );
					}
					
					break;
				}
				
				
				case 1976794484:
				{
					if (field.equals("get_yMax")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_yMax"))) );
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef986 = false;
						return this.get_x();
					}
					
					break;
				}
				
				
				case 1415682024:
				{
					if (field.equals("set_yMax")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_yMax"))) );
					}
					
					break;
				}
				
				
				case -1641497902:
				{
					if (field.equals("set_center")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_center"))) );
					}
					
					break;
				}
				
				
				case -1082973507:
				{
					if (field.equals("m_yMax")) 
					{
						__temp_executeDef986 = false;
						return this.m_yMax;
					}
					
					break;
				}
				
				
				case 716664158:
				{
					if (field.equals("get_center")) 
					{
						__temp_executeDef986 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_center"))) );
					}
					
					break;
				}
				
				
				case -1364013995:
				{
					if (field.equals("center")) 
					{
						__temp_executeDef986 = false;
						return this.get_center();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef986) 
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
			boolean __temp_executeDef987 = true;
			switch (field.hashCode())
			{
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef987 = false;
						return this.get_height();
					}
					
					break;
				}
				
				
				case 3652282:
				{
					if (field.equals("xMin")) 
					{
						__temp_executeDef987 = false;
						return this.get_xMin();
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef987 = false;
						return this.get_width();
					}
					
					break;
				}
				
				
				case -1083003060:
				{
					if (field.equals("m_xMin")) 
					{
						__temp_executeDef987 = false;
						return this.m_xMin;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef987 = false;
						return this.get_y();
					}
					
					break;
				}
				
				
				case 3682073:
				{
					if (field.equals("yMin")) 
					{
						__temp_executeDef987 = false;
						return this.get_yMin();
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef987 = false;
						return this.get_x();
					}
					
					break;
				}
				
				
				case -1082973269:
				{
					if (field.equals("m_yMin")) 
					{
						__temp_executeDef987 = false;
						return this.m_yMin;
					}
					
					break;
				}
				
				
				case -1082973507:
				{
					if (field.equals("m_yMax")) 
					{
						__temp_executeDef987 = false;
						return this.m_yMax;
					}
					
					break;
				}
				
				
				case 3652044:
				{
					if (field.equals("xMax")) 
					{
						__temp_executeDef987 = false;
						return this.get_xMax();
					}
					
					break;
				}
				
				
				case 3681835:
				{
					if (field.equals("yMax")) 
					{
						__temp_executeDef987 = false;
						return this.get_yMax();
					}
					
					break;
				}
				
				
				case -1083003298:
				{
					if (field.equals("m_xMax")) 
					{
						__temp_executeDef987 = false;
						return this.m_xMax;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef987) 
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
			boolean __temp_executeDef988 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef988 = false;
						return this.ToString(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef988 = false;
						return this.get_clone();
					}
					
					break;
				}
				
				
				case -1221447006:
				{
					if (field.equals("Encapsulate3")) 
					{
						__temp_executeDef988 = false;
						return this.Encapsulate3(dynargs.__get(0), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case -74790423:
				{
					if (field.equals("get_min")) 
					{
						__temp_executeDef988 = false;
						return this.get_min();
					}
					
					break;
				}
				
				
				case -1147780175:
				{
					if (field.equals("Encapsulate")) 
					{
						__temp_executeDef988 = false;
						this.Encapsulate(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1985319157:
				{
					if (field.equals("set_min")) 
					{
						__temp_executeDef988 = false;
						return this.set_min(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1450940624:
				{
					if (field.equals("SetAABB2")) 
					{
						__temp_executeDef988 = false;
						return this.SetAABB2(((haxor.math.AABB2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -74790661:
				{
					if (field.equals("get_max")) 
					{
						__temp_executeDef988 = false;
						return this.get_max();
					}
					
					break;
				}
				
				
				case -645223212:
				{
					if (field.equals("SetXYWH")) 
					{
						__temp_executeDef988 = false;
						return this.SetXYWH(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case 1985318919:
				{
					if (field.equals("set_max")) 
					{
						__temp_executeDef988 = false;
						return this.set_max(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef988 = false;
						return this.Set(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case 1976764931:
				{
					if (field.equals("get_xMin")) 
					{
						__temp_executeDef988 = false;
						return this.get_xMin();
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef988 = false;
						return this.Add(((haxor.math.AABB2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1415652471:
				{
					if (field.equals("set_xMin")) 
					{
						__temp_executeDef988 = false;
						return this.set_xMin(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1356628682:
				{
					if (field.equals("Validate")) 
					{
						__temp_executeDef988 = false;
						this.Validate();
					}
					
					break;
				}
				
				
				case 1976794722:
				{
					if (field.equals("get_yMin")) 
					{
						__temp_executeDef988 = false;
						return this.get_yMin();
					}
					
					break;
				}
				
				
				case 1415530942:
				{
					if (field.equals("set_size")) 
					{
						__temp_executeDef988 = false;
						return this.set_size(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1415682262:
				{
					if (field.equals("set_yMin")) 
					{
						__temp_executeDef988 = false;
						return this.set_yMin(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1976643402:
				{
					if (field.equals("get_size")) 
					{
						__temp_executeDef988 = false;
						return this.get_size();
					}
					
					break;
				}
				
				
				case 1976764693:
				{
					if (field.equals("get_xMax")) 
					{
						__temp_executeDef988 = false;
						return this.get_xMax();
					}
					
					break;
				}
				
				
				case -1498513500:
				{
					if (field.equals("set_height")) 
					{
						__temp_executeDef988 = false;
						return this.set_height(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1415652233:
				{
					if (field.equals("set_xMax")) 
					{
						__temp_executeDef988 = false;
						return this.set_xMax(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 859648560:
				{
					if (field.equals("get_height")) 
					{
						__temp_executeDef988 = false;
						return this.get_height();
					}
					
					break;
				}
				
				
				case 1976794484:
				{
					if (field.equals("get_yMax")) 
					{
						__temp_executeDef988 = false;
						return this.get_yMax();
					}
					
					break;
				}
				
				
				case 935459753:
				{
					if (field.equals("set_width")) 
					{
						__temp_executeDef988 = false;
						return this.set_width(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1415682024:
				{
					if (field.equals("set_yMax")) 
					{
						__temp_executeDef988 = false;
						return this.set_yMax(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1150076829:
				{
					if (field.equals("get_width")) 
					{
						__temp_executeDef988 = false;
						return this.get_width();
					}
					
					break;
				}
				
				
				case 716664158:
				{
					if (field.equals("get_center")) 
					{
						__temp_executeDef988 = false;
						return this.get_center();
					}
					
					break;
				}
				
				
				case 109328348:
				{
					if (field.equals("set_y")) 
					{
						__temp_executeDef988 = false;
						return this.set_y(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1641497902:
				{
					if (field.equals("set_center")) 
					{
						__temp_executeDef988 = false;
						return this.set_center(((haxor.math.Vector2) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 98246096:
				{
					if (field.equals("get_y")) 
					{
						__temp_executeDef988 = false;
						return this.get_y();
					}
					
					break;
				}
				
				
				case 98246095:
				{
					if (field.equals("get_x")) 
					{
						__temp_executeDef988 = false;
						return this.get_x();
					}
					
					break;
				}
				
				
				case 109328347:
				{
					if (field.equals("set_x")) 
					{
						__temp_executeDef988 = false;
						return this.set_x(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef988) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("size");
		baseArr.push("height");
		baseArr.push("width");
		baseArr.push("y");
		baseArr.push("x");
		baseArr.push("center");
		baseArr.push("m_yMax");
		baseArr.push("yMax");
		baseArr.push("m_xMax");
		baseArr.push("xMax");
		baseArr.push("m_yMin");
		baseArr.push("yMin");
		baseArr.push("m_xMin");
		baseArr.push("xMin");
		baseArr.push("max");
		baseArr.push("min");
		baseArr.push("clone");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


