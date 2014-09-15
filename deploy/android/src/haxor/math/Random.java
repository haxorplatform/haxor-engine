package haxor.math;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Random extends haxe.lang.HxObject
{
	public    Random(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Random()
	{
		haxor.math.Random.__hx_ctor_haxor_math_Random(this);
	}
	
	
	public static   void __hx_ctor_haxor_math_Random(haxor.math.Random __temp_me255602)
	{
		{
		}
		
	}
	
	
	public static  double value;
	
	public static   double get_value()
	{
		return java.lang.Math.random();
	}
	
	
	public static  double interval;
	
	public static   double get_interval()
	{
		return ( (( java.lang.Math.random() - 0.499995 )) * 2.0 );
	}
	
	
	public static  haxor.math.Quaternion rotation;
	
	public static   haxor.math.Quaternion get_rotation()
	{
		return haxor.math.Quaternion.FromAxisAngle(new haxor.math.Vector3(((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) ), ((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) ), ((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) )).Normalize().Scale(java.lang.Math.random()), ( ( (( java.lang.Math.random() - 0.499995 )) * 2.0 ) * 180.0 ));
	}
	
	
	public static  haxor.math.Vector3 box;
	
	public static   haxor.math.Vector3 get_box()
	{
		return new haxor.math.Vector3(((java.lang.Object) (( ( (( java.lang.Math.random() - 0.499995 )) * 2.0 ) * 0.5 )) ), ((java.lang.Object) (( ( (( java.lang.Math.random() - 0.499995 )) * 2.0 ) * 0.5 )) ), ((java.lang.Object) (( ( (( java.lang.Math.random() - 0.499995 )) * 2.0 ) * 0.5 )) ));
	}
	
	
	public static  haxor.math.Vector3 onBox;
	
	public static   haxor.math.Vector3 get_onBox()
	{
		haxor.math.Vector3 p = new haxor.math.Vector3(((java.lang.Object) (( ( (( java.lang.Math.random() - 0.499995 )) * 2.0 ) * 0.5 )) ), ((java.lang.Object) (( ( (( java.lang.Math.random() - 0.499995 )) * 2.0 ) * 0.5 )) ), ((java.lang.Object) (( ( (( java.lang.Math.random() - 0.499995 )) * 2.0 ) * 0.5 )) ));
		int i = ((int) (( ( java.lang.Math.random() * 3 ) + 0.5 )) );
		switch (i)
		{
			case 0:
			{
				if (( p.x < 0.0 )) 
				{
					p.x = -0.5;
				}
				 else 
				{
					p.x = 0.5;
				}
				
				break;
			}
			
			
			case 1:
			{
				if (( p.y < 0.0 )) 
				{
					p.y = -0.5;
				}
				 else 
				{
					p.y = 0.5;
				}
				
				break;
			}
			
			
			case 2:
			{
				if (( p.z < 0.0 )) 
				{
					p.z = -0.5;
				}
				 else 
				{
					p.z = 0.5;
				}
				
				break;
			}
			
			
		}
		
		return p;
	}
	
	
	public static  haxor.math.Vector2 square;
	
	public static   haxor.math.Vector2 get_square()
	{
		return new haxor.math.Vector2(((java.lang.Object) (( ( (( java.lang.Math.random() - 0.499995 )) * 2.0 ) * 0.5 )) ), ((java.lang.Object) (( ( (( java.lang.Math.random() - 0.499995 )) * 2.0 ) * 0.5 )) ));
	}
	
	
	public static  haxor.math.Vector2 onSquare;
	
	public static   haxor.math.Vector2 get_onSquare()
	{
		haxor.math.Vector2 p = new haxor.math.Vector2(((java.lang.Object) (( ( (( java.lang.Math.random() - 0.499995 )) * 2.0 ) * 0.5 )) ), ((java.lang.Object) (( ( (( java.lang.Math.random() - 0.499995 )) * 2.0 ) * 0.5 )) ));
		int i = ((int) (( ( java.lang.Math.random() * 2 ) + 0.5 )) );
		switch (i)
		{
			case 0:
			{
				if (( p.x < 0.0 )) 
				{
					p.x = -0.5;
				}
				 else 
				{
					p.x = 0.5;
				}
				
				break;
			}
			
			
			case 1:
			{
				if (( p.y < 0.0 )) 
				{
					p.y = -0.5;
				}
				 else 
				{
					p.y = 0.5;
				}
				
				break;
			}
			
			
		}
		
		return p;
	}
	
	
	public static  haxor.math.Vector3 sphere;
	
	public static   haxor.math.Vector3 get_sphere()
	{
		return new haxor.math.Vector3(((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) ), ((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) ), ((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) )).Normalize().Scale(java.lang.Math.random());
	}
	
	
	public static  haxor.math.Vector3 onSphere;
	
	public static   haxor.math.Vector3 get_onSphere()
	{
		return new haxor.math.Vector3(((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) ), ((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) ), ((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) )).Normalize();
	}
	
	
	public static  haxor.math.Vector2 circle;
	
	public static   haxor.math.Vector2 get_circle()
	{
		return new haxor.math.Vector2(((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) ), ((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) )).Normalize().Scale(java.lang.Math.random());
	}
	
	
	public static  haxor.math.Vector2 onCircle;
	
	public static   haxor.math.Vector2 get_onCircle()
	{
		return new haxor.math.Vector2(((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) ), ((java.lang.Object) (( (( java.lang.Math.random() - 0.499995 )) * 2.0 )) )).Normalize();
	}
	
	
	public static   int Length(int v)
	{
		return ((int) (( (( v + 1 )) * java.lang.Math.random() )) );
	}
	
	
	public static   double Range(double p_min, double p_max)
	{
		{
			double p_ratio = java.lang.Math.random();
			return ( p_min + ( (( p_max - p_min )) * p_ratio ) );
		}
		
	}
	
	
	public static   double RangeInt(int p_min, int p_max)
	{
		{
			double p_ratio = java.lang.Math.random();
			double __temp_stmt256449 = 0.0;
			{
				double p_a = ((double) (p_min) );
				__temp_stmt256449 = ( p_a + ( (( ((double) (( p_max + 1 )) ) - p_a )) * p_ratio ) );
			}
			
			return ((double) (((int) (__temp_stmt256449) )) );
		}
		
	}
	
	
	public static  <T> T Item(haxe.root.Array<T> p_list)
	{
		return p_list.__get(((int) (( p_list.length * java.lang.Math.random() )) ));
	}
	
	
	public static  <T> void Shuffle(haxe.root.Array<T> p_list)
	{
		int m = p_list.length;
		T t = null;
		int i = 0;
		while (( m > 0 ))
		{
			i = ((int) (java.lang.Math.floor(( java.lang.Math.random() * m-- ))) );
			t = p_list.__get(m);
			p_list.__set(m, p_list.__get(i));
			p_list.__set(i, t);
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.math.Random(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.math.Random();
	}
	
	
}


