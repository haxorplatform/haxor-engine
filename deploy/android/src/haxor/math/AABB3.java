package haxor.math;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class AABB3 extends haxe.lang.HxObject
{
	public    AABB3(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    AABB3(java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_z, java.lang.Object p_width, java.lang.Object p_height, java.lang.Object p_depth)
	{
		haxor.math.AABB3.__hx_ctor_haxor_math_AABB3(this, p_x, p_y, p_z, p_width, p_height, p_depth);
	}
	
	
	public static   void __hx_ctor_haxor_math_AABB3(haxor.math.AABB3 __temp_me160606, java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_z, java.lang.Object p_width, java.lang.Object p_height, java.lang.Object p_depth)
	{
		double __temp_p_depth160605 = ( (( p_depth == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_depth)) )) );
		double __temp_p_height160604 = ( (( p_height == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_height)) )) );
		double __temp_p_width160603 = ( (( p_width == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_width)) )) );
		double __temp_p_z160602 = ( (( p_z == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_z)) )) );
		double __temp_p_y160601 = ( (( p_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_y)) )) );
		double __temp_p_x160600 = ( (( p_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_x)) )) );
		__temp_me160606.m_xMin = __temp_p_x160600;
		__temp_me160606.m_yMin = __temp_p_y160601;
		__temp_me160606.m_zMin = __temp_p_y160601;
		__temp_me160606.m_xMax = ( __temp_me160606.m_xMin + __temp_p_width160603 );
		__temp_me160606.m_yMax = ( __temp_me160606.m_yMin + __temp_p_height160604 );
		__temp_me160606.m_zMax = ( __temp_me160606.m_zMin + __temp_p_depth160605 );
	}
	
	
	public static  haxor.math.AABB3 temp;
	
	public static   haxor.math.AABB3 get_temp()
	{
		{
			haxor.context.DataContext _this = haxor.context.EngineContext.data;
			return _this.m_aabb3.__get(_this.m_naabb3 = ( (( _this.m_naabb3 + 1 )) % _this.m_aabb3.length ));
		}
		
	}
	
	
	public static   haxor.math.AABB3 FromMinMax(double p_xmin, double p_xmax, double p_ymin, double p_ymax, double p_zmin, double p_zmax)
	{
		haxor.math.AABB3 b = new haxor.math.AABB3(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		b.set_xMin(p_xmin);
		b.set_xMax(p_xmax);
		b.set_yMin(p_ymin);
		b.set_yMax(p_ymax);
		b.set_zMin(p_zmin);
		b.set_zMax(p_zmax);
		return b;
	}
	
	
	public static   haxor.math.AABB3 FromCenter(double p_x, double p_y, double p_z, double p_width, double p_height, double p_depth)
	{
		haxor.math.AABB3 b = new haxor.math.AABB3(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
		{
			b.set_xMax(( b.m_xMin + p_width ));
			double __temp_expr161494 = p_width;
		}
		
		{
			b.set_yMax(( b.m_yMin + p_height ));
			double __temp_expr161495 = p_height;
		}
		
		{
			b.set_zMax(( b.m_zMin + p_depth ));
			double __temp_expr161496 = p_depth;
		}
		
		b.set_center(new haxor.math.Vector3(((java.lang.Object) (p_x) ), ((java.lang.Object) (p_y) ), ((java.lang.Object) (p_z) )));
		return b;
	}
	
	
	public static  haxor.math.AABB3 empty;
	
	public static   haxor.math.AABB3 get_empty()
	{
		return new haxor.math.AABB3(((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.math.AABB3(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.math.AABB3(((java.lang.Object) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ), ((java.lang.Object) (arr.__get(2)) ), ((java.lang.Object) (arr.__get(3)) ), ((java.lang.Object) (arr.__get(4)) ), ((java.lang.Object) (arr.__get(5)) ));
	}
	
	
	public  haxor.math.AABB3 clone;
	
	public   haxor.math.AABB3 get_clone()
	{
		return haxor.math.AABB3.FromMinMax(this.m_xMin, this.m_xMax, this.m_yMin, this.m_yMax, this.m_zMin, this.m_zMax);
	}
	
	
	
	
	public final   haxor.math.Vector3 get_min()
	{
		return new haxor.math.Vector3(((java.lang.Object) (this.m_xMin) ), ((java.lang.Object) (this.m_yMin) ), ((java.lang.Object) (null) ));
	}
	
	
	public final   haxor.math.Vector3 set_min(haxor.math.Vector3 v)
	{
		this.set_xMin(v.x);
		this.set_yMin(v.y);
		return v;
	}
	
	
	
	
	public final   haxor.math.Vector3 get_max()
	{
		return new haxor.math.Vector3(((java.lang.Object) (this.m_xMax) ), ((java.lang.Object) (this.m_yMax) ), ((java.lang.Object) (null) ));
	}
	
	
	public final   haxor.math.Vector3 set_max(haxor.math.Vector3 v)
	{
		this.set_xMax(v.x);
		this.set_yMax(v.y);
		return v;
	}
	
	
	
	
	public final   double get_xMin()
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
	
	
	
	public final   double get_yMin()
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
	
	
	
	public final   double get_zMin()
	{
		return this.m_zMin;
	}
	
	
	public   double set_zMin(double v)
	{
		this.m_zMin = v;
		this.Validate();
		return v;
	}
	
	
	public  double m_zMin;
	
	
	
	public final   double get_xMax()
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
	
	
	
	public final   double get_yMax()
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
	
	
	
	public final   double get_zMax()
	{
		return this.m_zMax;
	}
	
	
	public   double set_zMax(double v)
	{
		this.m_zMax = v;
		this.Validate();
		return v;
	}
	
	
	public  double m_zMax;
	
	
	
	public   haxor.math.Vector3 get_center()
	{
		return new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) )).Set(( this.m_xMin + ( (( this.m_xMax - this.m_xMin )) * 0.5 ) ), ( this.m_yMin + ( (( this.m_yMax - this.m_yMin )) * 0.5 ) ), ( this.m_zMin + ( (( this.m_zMax - this.m_zMin )) * 0.5 ) ));
	}
	
	
	public   haxor.math.Vector3 set_center(haxor.math.Vector3 v)
	{
		double hw = 0.0;
		double __temp_stmt161467 = 0.0;
		{
			double p_a = ( this.m_xMax - this.m_xMin );
			__temp_stmt161467 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
		}
		
		hw = ( __temp_stmt161467 * 0.5 );
		double hh = 0.0;
		double __temp_stmt161468 = 0.0;
		{
			double p_a1 = ( this.m_yMax - this.m_yMin );
			__temp_stmt161468 = ( (( p_a1 < 0 )) ? ( - (p_a1) ) : (p_a1) );
		}
		
		hh = ( __temp_stmt161468 * 0.5 );
		double hd = 0.0;
		double __temp_stmt161469 = 0.0;
		{
			double p_a2 = ( this.m_zMax - this.m_zMin );
			__temp_stmt161469 = ( (( p_a2 < 0 )) ? ( - (p_a2) ) : (p_a2) );
		}
		
		hd = ( __temp_stmt161469 * 0.5 );
		this.m_xMin = ( v.x - hw );
		this.m_xMax = ( v.x + hw );
		this.m_yMin = ( v.y - hh );
		this.m_yMax = ( v.y + hh );
		this.m_zMin = ( v.z - hd );
		this.m_zMax = ( v.z + hd );
		this.Validate();
		return v;
	}
	
	
	
	
	public final   double get_x()
	{
		return this.m_xMin;
	}
	
	
	public final   double set_x(double v)
	{
		this.set_xMin(v);
		return v;
	}
	
	
	
	
	public final   double get_y()
	{
		return this.m_yMin;
	}
	
	
	public final   double set_y(double v)
	{
		this.set_yMin(v);
		return v;
	}
	
	
	
	
	public final   double get_z()
	{
		return this.m_zMin;
	}
	
	
	public final   double set_z(double v)
	{
		this.set_zMin(v);
		return v;
	}
	
	
	
	
	public final   double get_width()
	{
		{
			double p_a = ( this.m_xMax - this.m_xMin );
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
		this.set_xMax(( this.m_xMin + v ));
		return v;
	}
	
	
	
	
	public final   double get_height()
	{
		{
			double p_a = ( this.m_yMax - this.m_yMin );
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
		this.set_yMax(( this.m_yMin + v ));
		return v;
	}
	
	
	
	
	public final   double get_depth()
	{
		{
			double p_a = ( this.m_zMax - this.m_zMin );
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
	
	
	public final   double set_depth(double v)
	{
		this.set_zMax(( this.m_zMin + v ));
		return v;
	}
	
	
	
	
	public final   haxor.math.Vector3 get_size()
	{
		double __temp_stmt161470 = 0.0;
		{
			double p_a = ( this.m_xMax - this.m_xMin );
			__temp_stmt161470 = ( (( p_a < 0 )) ? ( - (p_a) ) : (p_a) );
		}
		
		double __temp_stmt161471 = 0.0;
		{
			double p_a1 = ( this.m_yMax - this.m_yMin );
			__temp_stmt161471 = ( (( p_a1 < 0 )) ? ( - (p_a1) ) : (p_a1) );
		}
		
		double __temp_stmt161472 = 0.0;
		{
			double p_a2 = ( this.m_zMax - this.m_zMin );
			__temp_stmt161472 = ( (( p_a2 < 0 )) ? ( - (p_a2) ) : (p_a2) );
		}
		
		haxor.math.Vector3 __temp_stmt161473 = new haxor.math.Vector3(((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ));
		return __temp_stmt161473.Set(__temp_stmt161470, __temp_stmt161471, __temp_stmt161472);
	}
	
	
	public final   haxor.math.Vector3 set_size(haxor.math.Vector3 v)
	{
		{
			double v1 = v.x;
			this.set_xMax(( this.m_xMin + v1 ));
			double __temp_expr161474 = v1;
		}
		
		{
			double v2 = v.y;
			this.set_yMax(( this.m_yMin + v2 ));
			double __temp_expr161475 = v2;
		}
		
		{
			double v3 = v.z;
			this.set_zMax(( this.m_zMin + v3 ));
			double __temp_expr161476 = v3;
		}
		
		return v;
	}
	
	
	public   void Validate()
	{
		double x0 = this.m_xMin;
		double x1 = this.m_xMax;
		double y0 = this.m_yMin;
		double y1 = this.m_yMax;
		double z0 = this.m_zMin;
		double z1 = this.m_zMax;
		if (( x0 <= x1 )) 
		{
			this.m_xMin = x0;
			this.m_xMax = x1;
		}
		 else 
		{
			this.m_xMin = x1;
			this.m_xMax = x0;
		}
		
		if (( y0 <= y1 )) 
		{
			this.m_yMin = y0;
			this.m_yMax = y1;
		}
		 else 
		{
			this.m_yMin = y1;
			this.m_yMax = y0;
		}
		
		if (( z0 <= z1 )) 
		{
			this.m_zMin = z0;
			this.m_zMax = z1;
		}
		 else 
		{
			this.m_zMin = z1;
			this.m_zMax = z0;
		}
		
	}
	
	
	public   haxor.math.AABB3 Add(haxor.math.AABB3 p_v)
	{
		this.m_xMax = java.lang.Math.max(p_v.m_xMax, this.m_xMax);
		this.m_xMin = java.lang.Math.min(p_v.m_xMin, this.m_xMin);
		this.m_yMax = java.lang.Math.max(p_v.m_yMax, this.m_yMax);
		this.m_yMin = java.lang.Math.min(p_v.m_yMin, this.m_yMin);
		this.m_zMax = java.lang.Math.max(p_v.m_zMax, this.m_zMax);
		this.m_zMin = java.lang.Math.min(p_v.m_zMin, this.m_zMin);
		return this;
	}
	
	
	public   haxor.math.AABB3 Set(double p_xmin, double p_xmax, double p_ymin, double p_ymax, double p_zmin, double p_zmax)
	{
		this.m_xMin = p_xmin;
		this.m_yMin = p_ymin;
		this.m_zMin = p_zmin;
		this.m_xMax = p_xmax;
		this.m_yMax = p_ymax;
		this.m_zMax = p_zmax;
		this.Validate();
		return this;
	}
	
	
	public   haxor.math.AABB3 SetAABB3(haxor.math.AABB3 p_v)
	{
		this.m_xMin = p_v.m_xMin;
		this.m_yMin = p_v.m_yMin;
		this.m_zMin = p_v.m_zMin;
		this.m_xMax = p_v.m_xMax;
		this.m_yMax = p_v.m_yMax;
		this.m_zMax = p_v.m_zMax;
		return this;
	}
	
	
	public   haxor.math.AABB3 SetXYZWHD(java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_z, java.lang.Object p_width, java.lang.Object p_height, java.lang.Object p_depth)
	{
		double __temp_p_depth160595 = ( (( p_depth == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_depth)) )) );
		double __temp_p_height160594 = ( (( p_height == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_height)) )) );
		double __temp_p_width160593 = ( (( p_width == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_width)) )) );
		double __temp_p_z160592 = ( (( p_z == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_z)) )) );
		double __temp_p_y160591 = ( (( p_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_y)) )) );
		double __temp_p_x160590 = ( (( p_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_x)) )) );
		this.m_xMin = __temp_p_x160590;
		this.m_yMin = __temp_p_y160591;
		this.m_zMin = __temp_p_y160591;
		this.m_xMax = ( this.m_xMin + __temp_p_width160593 );
		this.m_yMax = ( this.m_yMin + __temp_p_height160594 );
		this.m_zMax = ( this.m_zMin + __temp_p_depth160595 );
		return this;
	}
	
	
	public final   haxor.math.AABB3 Encapsulate(haxor.math.Vector3 p_point)
	{
		return this.Encapsulate3(p_point.x, p_point.y, p_point.z);
	}
	
	
	public   haxor.math.AABB3 Encapsulate3(java.lang.Object p_x, java.lang.Object p_y, java.lang.Object p_z)
	{
		double __temp_p_z160598 = ( (( p_z == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_z)) )) );
		double __temp_p_y160597 = ( (( p_y == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_y)) )) );
		double __temp_p_x160596 = ( (( p_x == null )) ? (((double) (0) )) : (((double) (haxe.lang.Runtime.toDouble(p_x)) )) );
		this.m_xMin = java.lang.Math.min(__temp_p_x160596, this.m_xMin);
		this.m_xMax = java.lang.Math.max(__temp_p_x160596, this.m_xMax);
		this.m_yMin = java.lang.Math.min(__temp_p_y160597, this.m_yMin);
		this.m_yMax = java.lang.Math.max(__temp_p_y160597, this.m_yMax);
		this.m_zMin = java.lang.Math.min(__temp_p_z160598, this.m_zMin);
		this.m_zMax = java.lang.Math.max(__temp_p_z160598, this.m_zMax);
		this.Validate();
		return this;
	}
	
	
	public   java.lang.String ToString(java.lang.Object p_places)
	{
		int __temp_p_places160599 = ( (( p_places == null )) ? (((int) (2) )) : (((int) (haxe.lang.Runtime.toInt(p_places)) )) );
		java.lang.String s0 = null;
		double __temp_stmt161477 = 0.0;
		{
			double d = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places160599) ));
			double __temp_stmt161478 = 0.0;
			{
				double p_v = ( this.m_xMin * d );
				__temp_stmt161478 = ((double) (((int) (( p_v + (( (( p_v < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt161477 = ( __temp_stmt161478 / d );
		}
		
		s0 = ( haxe.lang.Runtime.toString(__temp_stmt161477) + "" );
		java.lang.String s1 = null;
		double __temp_stmt161479 = 0.0;
		{
			double d1 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places160599) ));
			double __temp_stmt161480 = 0.0;
			{
				double p_v1 = ( this.m_xMax * d1 );
				__temp_stmt161480 = ((double) (((int) (( p_v1 + (( (( p_v1 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt161479 = ( __temp_stmt161480 / d1 );
		}
		
		s1 = ( haxe.lang.Runtime.toString(__temp_stmt161479) + "" );
		java.lang.String s2 = null;
		double __temp_stmt161481 = 0.0;
		{
			double d2 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places160599) ));
			double __temp_stmt161482 = 0.0;
			{
				double p_v2 = ( this.m_yMin * d2 );
				__temp_stmt161482 = ((double) (((int) (( p_v2 + (( (( p_v2 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt161481 = ( __temp_stmt161482 / d2 );
		}
		
		s2 = ( haxe.lang.Runtime.toString(__temp_stmt161481) + "" );
		java.lang.String s3 = null;
		double __temp_stmt161483 = 0.0;
		{
			double d3 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places160599) ));
			double __temp_stmt161484 = 0.0;
			{
				double p_v3 = ( this.m_yMax * d3 );
				__temp_stmt161484 = ((double) (((int) (( p_v3 + (( (( p_v3 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt161483 = ( __temp_stmt161484 / d3 );
		}
		
		s3 = ( haxe.lang.Runtime.toString(__temp_stmt161483) + "" );
		java.lang.String s4 = null;
		double __temp_stmt161485 = 0.0;
		{
			double d4 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places160599) ));
			double __temp_stmt161486 = 0.0;
			{
				double p_v4 = ( this.m_zMin * d4 );
				__temp_stmt161486 = ((double) (((int) (( p_v4 + (( (( p_v4 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt161485 = ( __temp_stmt161486 / d4 );
		}
		
		s4 = ( haxe.lang.Runtime.toString(__temp_stmt161485) + "" );
		java.lang.String s5 = null;
		double __temp_stmt161487 = 0.0;
		{
			double d5 = java.lang.Math.pow(((double) (10) ), ((double) (__temp_p_places160599) ));
			double __temp_stmt161488 = 0.0;
			{
				double p_v5 = ( this.m_zMax * d5 );
				__temp_stmt161488 = ((double) (((int) (( p_v5 + (( (( p_v5 < 0 )) ? (-0.5) : (0.5) )) )) )) );
			}
			
			__temp_stmt161487 = ( __temp_stmt161488 / d5 );
		}
		
		s5 = ( haxe.lang.Runtime.toString(__temp_stmt161487) + "" );
		return ( ( ( ( ( ( ( ( ( ( ( ( "[" + s0 ) + "," ) + s1 ) + "|" ) + s2 ) + "," ) + s3 ) + "|" ) + s4 ) + "," ) + s5 ) + "]" );
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161489 = true;
			switch (field.hashCode())
			{
				case 95472323:
				{
					if (field.equals("depth")) 
					{
						__temp_executeDef161489 = false;
						this.set_depth(value);
						return value;
					}
					
					break;
				}
				
				
				case 3652282:
				{
					if (field.equals("xMin")) 
					{
						__temp_executeDef161489 = false;
						this.set_xMin(value);
						return value;
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef161489 = false;
						this.set_height(value);
						return value;
					}
					
					break;
				}
				
				
				case -1083003060:
				{
					if (field.equals("m_xMin")) 
					{
						__temp_executeDef161489 = false;
						this.m_xMin = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef161489 = false;
						this.set_width(value);
						return value;
					}
					
					break;
				}
				
				
				case 3682073:
				{
					if (field.equals("yMin")) 
					{
						__temp_executeDef161489 = false;
						this.set_yMin(value);
						return value;
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef161489 = false;
						this.set_z(value);
						return value;
					}
					
					break;
				}
				
				
				case -1082973269:
				{
					if (field.equals("m_yMin")) 
					{
						__temp_executeDef161489 = false;
						this.m_yMin = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef161489 = false;
						this.set_y(value);
						return value;
					}
					
					break;
				}
				
				
				case 3711864:
				{
					if (field.equals("zMin")) 
					{
						__temp_executeDef161489 = false;
						this.set_zMin(value);
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef161489 = false;
						this.set_x(value);
						return value;
					}
					
					break;
				}
				
				
				case -1082943478:
				{
					if (field.equals("m_zMin")) 
					{
						__temp_executeDef161489 = false;
						this.m_zMin = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1082943716:
				{
					if (field.equals("m_zMax")) 
					{
						__temp_executeDef161489 = false;
						this.m_zMax = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3652044:
				{
					if (field.equals("xMax")) 
					{
						__temp_executeDef161489 = false;
						this.set_xMax(value);
						return value;
					}
					
					break;
				}
				
				
				case 3711626:
				{
					if (field.equals("zMax")) 
					{
						__temp_executeDef161489 = false;
						this.set_zMax(value);
						return value;
					}
					
					break;
				}
				
				
				case -1083003298:
				{
					if (field.equals("m_xMax")) 
					{
						__temp_executeDef161489 = false;
						this.m_xMax = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1082973507:
				{
					if (field.equals("m_yMax")) 
					{
						__temp_executeDef161489 = false;
						this.m_yMax = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3681835:
				{
					if (field.equals("yMax")) 
					{
						__temp_executeDef161489 = false;
						this.set_yMax(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161489) 
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
			boolean __temp_executeDef161490 = true;
			switch (field.hashCode())
			{
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef161490 = false;
						this.set_size(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef161490 = false;
						this.clone = ((haxor.math.AABB3) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 95472323:
				{
					if (field.equals("depth")) 
					{
						__temp_executeDef161490 = false;
						this.set_depth(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 108114:
				{
					if (field.equals("min")) 
					{
						__temp_executeDef161490 = false;
						this.set_min(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef161490 = false;
						this.set_height(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 107876:
				{
					if (field.equals("max")) 
					{
						__temp_executeDef161490 = false;
						this.set_max(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef161490 = false;
						this.set_width(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 3652282:
				{
					if (field.equals("xMin")) 
					{
						__temp_executeDef161490 = false;
						this.set_xMin(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef161490 = false;
						this.set_z(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -1083003060:
				{
					if (field.equals("m_xMin")) 
					{
						__temp_executeDef161490 = false;
						this.m_xMin = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef161490 = false;
						this.set_y(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 3682073:
				{
					if (field.equals("yMin")) 
					{
						__temp_executeDef161490 = false;
						this.set_yMin(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef161490 = false;
						this.set_x(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -1082973269:
				{
					if (field.equals("m_yMin")) 
					{
						__temp_executeDef161490 = false;
						this.m_yMin = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1364013995:
				{
					if (field.equals("center")) 
					{
						__temp_executeDef161490 = false;
						this.set_center(((haxor.math.Vector3) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 3711864:
				{
					if (field.equals("zMin")) 
					{
						__temp_executeDef161490 = false;
						this.set_zMin(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -1082943716:
				{
					if (field.equals("m_zMax")) 
					{
						__temp_executeDef161490 = false;
						this.m_zMax = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1082943478:
				{
					if (field.equals("m_zMin")) 
					{
						__temp_executeDef161490 = false;
						this.m_zMin = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3711626:
				{
					if (field.equals("zMax")) 
					{
						__temp_executeDef161490 = false;
						this.set_zMax(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 3652044:
				{
					if (field.equals("xMax")) 
					{
						__temp_executeDef161490 = false;
						this.set_xMax(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case -1082973507:
				{
					if (field.equals("m_yMax")) 
					{
						__temp_executeDef161490 = false;
						this.m_yMax = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1083003298:
				{
					if (field.equals("m_xMax")) 
					{
						__temp_executeDef161490 = false;
						this.m_xMax = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3681835:
				{
					if (field.equals("yMax")) 
					{
						__temp_executeDef161490 = false;
						this.set_yMax(((double) (haxe.lang.Runtime.toDouble(value)) ));
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161490) 
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
			boolean __temp_executeDef161491 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("ToString"))) );
					}
					
					break;
				}
				
				
				case 94756189:
				{
					if (field.equals("clone")) 
					{
						__temp_executeDef161491 = false;
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
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Encapsulate3"))) );
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_clone"))) );
					}
					
					break;
				}
				
				
				case -1147780175:
				{
					if (field.equals("Encapsulate")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Encapsulate"))) );
					}
					
					break;
				}
				
				
				case 108114:
				{
					if (field.equals("min")) 
					{
						__temp_executeDef161491 = false;
						return this.get_min();
					}
					
					break;
				}
				
				
				case -1584110020:
				{
					if (field.equals("SetXYZWHD")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetXYZWHD"))) );
					}
					
					break;
				}
				
				
				case -74790423:
				{
					if (field.equals("get_min")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_min"))) );
					}
					
					break;
				}
				
				
				case 1450940625:
				{
					if (field.equals("SetAABB3")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetAABB3"))) );
					}
					
					break;
				}
				
				
				case 1985319157:
				{
					if (field.equals("set_min")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_min"))) );
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 107876:
				{
					if (field.equals("max")) 
					{
						__temp_executeDef161491 = false;
						return this.get_max();
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add"))) );
					}
					
					break;
				}
				
				
				case -74790661:
				{
					if (field.equals("get_max")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_max"))) );
					}
					
					break;
				}
				
				
				case -1356628682:
				{
					if (field.equals("Validate")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Validate"))) );
					}
					
					break;
				}
				
				
				case 1985318919:
				{
					if (field.equals("set_max")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_max"))) );
					}
					
					break;
				}
				
				
				case 1415530942:
				{
					if (field.equals("set_size")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_size"))) );
					}
					
					break;
				}
				
				
				case 3652282:
				{
					if (field.equals("xMin")) 
					{
						__temp_executeDef161491 = false;
						return this.get_xMin();
					}
					
					break;
				}
				
				
				case 1976643402:
				{
					if (field.equals("get_size")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_size"))) );
					}
					
					break;
				}
				
				
				case 1976764931:
				{
					if (field.equals("get_xMin")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_xMin"))) );
					}
					
					break;
				}
				
				
				case 3530753:
				{
					if (field.equals("size")) 
					{
						__temp_executeDef161491 = false;
						return this.get_size();
					}
					
					break;
				}
				
				
				case 1415652471:
				{
					if (field.equals("set_xMin")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_xMin"))) );
					}
					
					break;
				}
				
				
				case 917805222:
				{
					if (field.equals("set_depth")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_depth"))) );
					}
					
					break;
				}
				
				
				case -1083003060:
				{
					if (field.equals("m_xMin")) 
					{
						__temp_executeDef161491 = false;
						return this.m_xMin;
					}
					
					break;
				}
				
				
				case 1132422298:
				{
					if (field.equals("get_depth")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_depth"))) );
					}
					
					break;
				}
				
				
				case 3682073:
				{
					if (field.equals("yMin")) 
					{
						__temp_executeDef161491 = false;
						return this.get_yMin();
					}
					
					break;
				}
				
				
				case 95472323:
				{
					if (field.equals("depth")) 
					{
						__temp_executeDef161491 = false;
						return this.get_depth();
					}
					
					break;
				}
				
				
				case 1976794722:
				{
					if (field.equals("get_yMin")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_yMin"))) );
					}
					
					break;
				}
				
				
				case -1498513500:
				{
					if (field.equals("set_height")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_height"))) );
					}
					
					break;
				}
				
				
				case 1415682262:
				{
					if (field.equals("set_yMin")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_yMin"))) );
					}
					
					break;
				}
				
				
				case 859648560:
				{
					if (field.equals("get_height")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_height"))) );
					}
					
					break;
				}
				
				
				case -1082973269:
				{
					if (field.equals("m_yMin")) 
					{
						__temp_executeDef161491 = false;
						return this.m_yMin;
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef161491 = false;
						return this.get_height();
					}
					
					break;
				}
				
				
				case 3711864:
				{
					if (field.equals("zMin")) 
					{
						__temp_executeDef161491 = false;
						return this.get_zMin();
					}
					
					break;
				}
				
				
				case 935459753:
				{
					if (field.equals("set_width")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_width"))) );
					}
					
					break;
				}
				
				
				case 1976824513:
				{
					if (field.equals("get_zMin")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_zMin"))) );
					}
					
					break;
				}
				
				
				case 1150076829:
				{
					if (field.equals("get_width")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_width"))) );
					}
					
					break;
				}
				
				
				case 1415712053:
				{
					if (field.equals("set_zMin")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_zMin"))) );
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef161491 = false;
						return this.get_width();
					}
					
					break;
				}
				
				
				case -1082943478:
				{
					if (field.equals("m_zMin")) 
					{
						__temp_executeDef161491 = false;
						return this.m_zMin;
					}
					
					break;
				}
				
				
				case 109328349:
				{
					if (field.equals("set_z")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_z"))) );
					}
					
					break;
				}
				
				
				case 3652044:
				{
					if (field.equals("xMax")) 
					{
						__temp_executeDef161491 = false;
						return this.get_xMax();
					}
					
					break;
				}
				
				
				case 98246097:
				{
					if (field.equals("get_z")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_z"))) );
					}
					
					break;
				}
				
				
				case 1976764693:
				{
					if (field.equals("get_xMax")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_xMax"))) );
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef161491 = false;
						return this.get_z();
					}
					
					break;
				}
				
				
				case 1415652233:
				{
					if (field.equals("set_xMax")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_xMax"))) );
					}
					
					break;
				}
				
				
				case 109328348:
				{
					if (field.equals("set_y")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_y"))) );
					}
					
					break;
				}
				
				
				case -1083003298:
				{
					if (field.equals("m_xMax")) 
					{
						__temp_executeDef161491 = false;
						return this.m_xMax;
					}
					
					break;
				}
				
				
				case 98246096:
				{
					if (field.equals("get_y")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_y"))) );
					}
					
					break;
				}
				
				
				case 3681835:
				{
					if (field.equals("yMax")) 
					{
						__temp_executeDef161491 = false;
						return this.get_yMax();
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef161491 = false;
						return this.get_y();
					}
					
					break;
				}
				
				
				case 1976794484:
				{
					if (field.equals("get_yMax")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_yMax"))) );
					}
					
					break;
				}
				
				
				case 109328347:
				{
					if (field.equals("set_x")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_x"))) );
					}
					
					break;
				}
				
				
				case 1415682024:
				{
					if (field.equals("set_yMax")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_yMax"))) );
					}
					
					break;
				}
				
				
				case 98246095:
				{
					if (field.equals("get_x")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_x"))) );
					}
					
					break;
				}
				
				
				case -1082973507:
				{
					if (field.equals("m_yMax")) 
					{
						__temp_executeDef161491 = false;
						return this.m_yMax;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef161491 = false;
						return this.get_x();
					}
					
					break;
				}
				
				
				case 3711626:
				{
					if (field.equals("zMax")) 
					{
						__temp_executeDef161491 = false;
						return this.get_zMax();
					}
					
					break;
				}
				
				
				case -1641497902:
				{
					if (field.equals("set_center")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_center"))) );
					}
					
					break;
				}
				
				
				case 1976824275:
				{
					if (field.equals("get_zMax")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_zMax"))) );
					}
					
					break;
				}
				
				
				case 716664158:
				{
					if (field.equals("get_center")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_center"))) );
					}
					
					break;
				}
				
				
				case 1415711815:
				{
					if (field.equals("set_zMax")) 
					{
						__temp_executeDef161491 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_zMax"))) );
					}
					
					break;
				}
				
				
				case -1364013995:
				{
					if (field.equals("center")) 
					{
						__temp_executeDef161491 = false;
						return this.get_center();
					}
					
					break;
				}
				
				
				case -1082943716:
				{
					if (field.equals("m_zMax")) 
					{
						__temp_executeDef161491 = false;
						return this.m_zMax;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161491) 
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
			boolean __temp_executeDef161492 = true;
			switch (field.hashCode())
			{
				case 95472323:
				{
					if (field.equals("depth")) 
					{
						__temp_executeDef161492 = false;
						return this.get_depth();
					}
					
					break;
				}
				
				
				case 3652282:
				{
					if (field.equals("xMin")) 
					{
						__temp_executeDef161492 = false;
						return this.get_xMin();
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef161492 = false;
						return this.get_height();
					}
					
					break;
				}
				
				
				case -1083003060:
				{
					if (field.equals("m_xMin")) 
					{
						__temp_executeDef161492 = false;
						return this.m_xMin;
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef161492 = false;
						return this.get_width();
					}
					
					break;
				}
				
				
				case 3682073:
				{
					if (field.equals("yMin")) 
					{
						__temp_executeDef161492 = false;
						return this.get_yMin();
					}
					
					break;
				}
				
				
				case 122:
				{
					if (field.equals("z")) 
					{
						__temp_executeDef161492 = false;
						return this.get_z();
					}
					
					break;
				}
				
				
				case -1082973269:
				{
					if (field.equals("m_yMin")) 
					{
						__temp_executeDef161492 = false;
						return this.m_yMin;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef161492 = false;
						return this.get_y();
					}
					
					break;
				}
				
				
				case 3711864:
				{
					if (field.equals("zMin")) 
					{
						__temp_executeDef161492 = false;
						return this.get_zMin();
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef161492 = false;
						return this.get_x();
					}
					
					break;
				}
				
				
				case -1082943478:
				{
					if (field.equals("m_zMin")) 
					{
						__temp_executeDef161492 = false;
						return this.m_zMin;
					}
					
					break;
				}
				
				
				case -1082943716:
				{
					if (field.equals("m_zMax")) 
					{
						__temp_executeDef161492 = false;
						return this.m_zMax;
					}
					
					break;
				}
				
				
				case 3652044:
				{
					if (field.equals("xMax")) 
					{
						__temp_executeDef161492 = false;
						return this.get_xMax();
					}
					
					break;
				}
				
				
				case 3711626:
				{
					if (field.equals("zMax")) 
					{
						__temp_executeDef161492 = false;
						return this.get_zMax();
					}
					
					break;
				}
				
				
				case -1083003298:
				{
					if (field.equals("m_xMax")) 
					{
						__temp_executeDef161492 = false;
						return this.m_xMax;
					}
					
					break;
				}
				
				
				case -1082973507:
				{
					if (field.equals("m_yMax")) 
					{
						__temp_executeDef161492 = false;
						return this.m_yMax;
					}
					
					break;
				}
				
				
				case 3681835:
				{
					if (field.equals("yMax")) 
					{
						__temp_executeDef161492 = false;
						return this.get_yMax();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161492) 
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
			boolean __temp_executeDef161493 = true;
			switch (field.hashCode())
			{
				case -1712277876:
				{
					if (field.equals("ToString")) 
					{
						__temp_executeDef161493 = false;
						return this.ToString(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case 1131706164:
				{
					if (field.equals("get_clone")) 
					{
						__temp_executeDef161493 = false;
						return this.get_clone();
					}
					
					break;
				}
				
				
				case -1221447006:
				{
					if (field.equals("Encapsulate3")) 
					{
						__temp_executeDef161493 = false;
						return this.Encapsulate3(dynargs.__get(0), dynargs.__get(1), dynargs.__get(2));
					}
					
					break;
				}
				
				
				case -74790423:
				{
					if (field.equals("get_min")) 
					{
						__temp_executeDef161493 = false;
						return this.get_min();
					}
					
					break;
				}
				
				
				case -1147780175:
				{
					if (field.equals("Encapsulate")) 
					{
						__temp_executeDef161493 = false;
						return this.Encapsulate(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1985319157:
				{
					if (field.equals("set_min")) 
					{
						__temp_executeDef161493 = false;
						return this.set_min(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1584110020:
				{
					if (field.equals("SetXYZWHD")) 
					{
						__temp_executeDef161493 = false;
						return this.SetXYZWHD(dynargs.__get(0), dynargs.__get(1), dynargs.__get(2), dynargs.__get(3), dynargs.__get(4), dynargs.__get(5));
					}
					
					break;
				}
				
				
				case -74790661:
				{
					if (field.equals("get_max")) 
					{
						__temp_executeDef161493 = false;
						return this.get_max();
					}
					
					break;
				}
				
				
				case 1450940625:
				{
					if (field.equals("SetAABB3")) 
					{
						__temp_executeDef161493 = false;
						return this.SetAABB3(((haxor.math.AABB3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1985318919:
				{
					if (field.equals("set_max")) 
					{
						__temp_executeDef161493 = false;
						return this.set_max(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef161493 = false;
						return this.Set(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(2))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(3))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(4))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(5))) ));
					}
					
					break;
				}
				
				
				case 1976764931:
				{
					if (field.equals("get_xMin")) 
					{
						__temp_executeDef161493 = false;
						return this.get_xMin();
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef161493 = false;
						return this.Add(((haxor.math.AABB3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1415652471:
				{
					if (field.equals("set_xMin")) 
					{
						__temp_executeDef161493 = false;
						return this.set_xMin(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1356628682:
				{
					if (field.equals("Validate")) 
					{
						__temp_executeDef161493 = false;
						this.Validate();
					}
					
					break;
				}
				
				
				case 1976794722:
				{
					if (field.equals("get_yMin")) 
					{
						__temp_executeDef161493 = false;
						return this.get_yMin();
					}
					
					break;
				}
				
				
				case 1415530942:
				{
					if (field.equals("set_size")) 
					{
						__temp_executeDef161493 = false;
						return this.set_size(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1415682262:
				{
					if (field.equals("set_yMin")) 
					{
						__temp_executeDef161493 = false;
						return this.set_yMin(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1976643402:
				{
					if (field.equals("get_size")) 
					{
						__temp_executeDef161493 = false;
						return this.get_size();
					}
					
					break;
				}
				
				
				case 1976824513:
				{
					if (field.equals("get_zMin")) 
					{
						__temp_executeDef161493 = false;
						return this.get_zMin();
					}
					
					break;
				}
				
				
				case 917805222:
				{
					if (field.equals("set_depth")) 
					{
						__temp_executeDef161493 = false;
						return this.set_depth(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1415712053:
				{
					if (field.equals("set_zMin")) 
					{
						__temp_executeDef161493 = false;
						return this.set_zMin(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1132422298:
				{
					if (field.equals("get_depth")) 
					{
						__temp_executeDef161493 = false;
						return this.get_depth();
					}
					
					break;
				}
				
				
				case 1976764693:
				{
					if (field.equals("get_xMax")) 
					{
						__temp_executeDef161493 = false;
						return this.get_xMax();
					}
					
					break;
				}
				
				
				case -1498513500:
				{
					if (field.equals("set_height")) 
					{
						__temp_executeDef161493 = false;
						return this.set_height(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1415652233:
				{
					if (field.equals("set_xMax")) 
					{
						__temp_executeDef161493 = false;
						return this.set_xMax(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 859648560:
				{
					if (field.equals("get_height")) 
					{
						__temp_executeDef161493 = false;
						return this.get_height();
					}
					
					break;
				}
				
				
				case 1976794484:
				{
					if (field.equals("get_yMax")) 
					{
						__temp_executeDef161493 = false;
						return this.get_yMax();
					}
					
					break;
				}
				
				
				case 935459753:
				{
					if (field.equals("set_width")) 
					{
						__temp_executeDef161493 = false;
						return this.set_width(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1415682024:
				{
					if (field.equals("set_yMax")) 
					{
						__temp_executeDef161493 = false;
						return this.set_yMax(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1150076829:
				{
					if (field.equals("get_width")) 
					{
						__temp_executeDef161493 = false;
						return this.get_width();
					}
					
					break;
				}
				
				
				case 1976824275:
				{
					if (field.equals("get_zMax")) 
					{
						__temp_executeDef161493 = false;
						return this.get_zMax();
					}
					
					break;
				}
				
				
				case 109328349:
				{
					if (field.equals("set_z")) 
					{
						__temp_executeDef161493 = false;
						return this.set_z(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1415711815:
				{
					if (field.equals("set_zMax")) 
					{
						__temp_executeDef161493 = false;
						return this.set_zMax(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 98246097:
				{
					if (field.equals("get_z")) 
					{
						__temp_executeDef161493 = false;
						return this.get_z();
					}
					
					break;
				}
				
				
				case 716664158:
				{
					if (field.equals("get_center")) 
					{
						__temp_executeDef161493 = false;
						return this.get_center();
					}
					
					break;
				}
				
				
				case 109328348:
				{
					if (field.equals("set_y")) 
					{
						__temp_executeDef161493 = false;
						return this.set_y(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1641497902:
				{
					if (field.equals("set_center")) 
					{
						__temp_executeDef161493 = false;
						return this.set_center(((haxor.math.Vector3) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 98246096:
				{
					if (field.equals("get_y")) 
					{
						__temp_executeDef161493 = false;
						return this.get_y();
					}
					
					break;
				}
				
				
				case 98246095:
				{
					if (field.equals("get_x")) 
					{
						__temp_executeDef161493 = false;
						return this.get_x();
					}
					
					break;
				}
				
				
				case 109328347:
				{
					if (field.equals("set_x")) 
					{
						__temp_executeDef161493 = false;
						return this.set_x(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161493) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("size");
		baseArr.push("depth");
		baseArr.push("height");
		baseArr.push("width");
		baseArr.push("z");
		baseArr.push("y");
		baseArr.push("x");
		baseArr.push("center");
		baseArr.push("m_zMax");
		baseArr.push("zMax");
		baseArr.push("m_yMax");
		baseArr.push("yMax");
		baseArr.push("m_xMax");
		baseArr.push("xMax");
		baseArr.push("m_zMin");
		baseArr.push("zMin");
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


