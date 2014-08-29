package haxe;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Int64
{
	public    Int64()
	{
		{
		}
		
	}
	
	
	public static   long make(int high, int low)
	{
		{
			long i = 0L;
			i = ((long) (( ( ((long) (high) ) << 32 ) | ( low & 0xffffffffL ) )) );
			return i;
		}
		
	}
	
	
	public static   int getLow(long x)
	{
		return ((int) (( ((long) (x) ) & 0xFFFFFFFFL )) );
	}
	
	
	public static   int getHigh(long x)
	{
		return ((int) (( ((long) (x) ) >>> ((long) (32) ) )) );
	}
	
	
	public static   long ofInt(int x)
	{
		return ((long) (x) );
	}
	
	
	public static   int toInt(long x)
	{
		return ((int) (x) );
	}
	
	
	public static   long add(long a, long b)
	{
		return ((long) (( ((long) (a) ) + ((long) (b) ) )) );
	}
	
	
	public static   long sub(long a, long b)
	{
		return ((long) (( ((long) (a) ) - ((long) (b) ) )) );
	}
	
	
	public static   long mul(long a, long b)
	{
		return ((long) (( ((long) (a) ) * ((long) (b) ) )) );
	}
	
	
	public static   java.lang.Object divMod(long modulus, long divisor)
	{
		long q = ( ((long) (modulus) ) / ((long) (divisor) ) );
		long m = ((long) (( ((long) (modulus) ) % ((long) (divisor) ) )) );
		return new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"modulus", "quotient"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{m, q}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
	}
	
	
	public static   long div(long a, long b)
	{
		return ( ((long) (a) ) / ((long) (b) ) );
	}
	
	
	public static   long mod(long a, long b)
	{
		return ((long) (( ((long) (a) ) % ((long) (b) ) )) );
	}
	
	
	public static   long shl(long a, int b)
	{
		return ((long) (( ((long) (a) ) << b )) );
	}
	
	
	public static   long shr(long a, int b)
	{
		return ((long) (( ((long) (a) ) >> b )) );
	}
	
	
	public static   long ushr(long a, int b)
	{
		return ((long) (( ((long) (a) ) >>> b )) );
	}
	
	
	public static   long and(long a, long b)
	{
		return ((long) (( ((long) (a) ) & ((long) (b) ) )) );
	}
	
	
	public static   long or(long a, long b)
	{
		return ((long) (( ((long) (a) ) | ((long) (b) ) )) );
	}
	
	
	public static   long xor(long a, long b)
	{
		return ((long) (( ((long) (a) ) ^ ((long) (b) ) )) );
	}
	
	
	public static   long neg(long a)
	{
		return ((long) ( ~ (((long) (a) )) ) );
	}
	
	
	public static   boolean isNeg(long a)
	{
		return ( ((long) (a) ) < 0 );
	}
	
	
	public static   boolean isZero(long a)
	{
		return ( ((long) (a) ) == 0 );
	}
	
	
	public static   int compare(long a, long b)
	{
		if (( ((long) (a) ) < ((long) (b) ) )) 
		{
			return -1;
		}
		 else 
		{
			if (( ((long) (a) ) > ((long) (b) ) )) 
			{
				return 1;
			}
			 else 
			{
				return 0;
			}
			
		}
		
	}
	
	
	public static   int ucompare(long a, long b)
	{
		if (( ((long) (a) ) < 0 )) 
		{
			if (( ((long) (b) ) < 0 )) 
			{
				long a1 = ((long) ( ~ (((long) (a) )) ) );
				long b1 = ((long) ( ~ (((long) (b) )) ) );
				if (( ((long) (a1) ) < ((long) (b1) ) )) 
				{
					return -1;
				}
				 else 
				{
					if (( ((long) (a1) ) > ((long) (b1) ) )) 
					{
						return 1;
					}
					 else 
					{
						return 0;
					}
					
				}
				
			}
			 else 
			{
				return 1;
			}
			
		}
		
		if (( ((long) (b) ) < 0 )) 
		{
			return -1;
		}
		 else 
		{
			if (( ((long) (a) ) < ((long) (b) ) )) 
			{
				return -1;
			}
			 else 
			{
				if (( ((long) (a) ) > ((long) (b) ) )) 
				{
					return 1;
				}
				 else 
				{
					return 0;
				}
				
			}
			
		}
		
	}
	
	
	public static   java.lang.String toStr(long a)
	{
		return ( haxe.root.Std.string(a) + "" );
	}
	
	
}


