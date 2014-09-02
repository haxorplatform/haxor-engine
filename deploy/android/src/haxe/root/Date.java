package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Date extends haxe.lang.HxObject
{
	public    Date(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Date(int year, int month, int day, int hour, int min, int sec)
	{
		haxe.root.Date.__hx_ctor__Date(this, year, month, day, hour, min, sec);
	}
	
	
	public static   void __hx_ctor__Date(haxe.root.Date __temp_me160369, int year, int month, int day, int hour, int min, int sec)
	{
		if (( year != 0 )) 
		{
			year = ( year - 1900 );
		}
		 else 
		{
			year = 0;
		}
		
		__temp_me160369.date = new java.util.Date(((int) (year) ), ((int) (month) ), ((int) (day) ), ((int) (hour) ), ((int) (min) ), ((int) (sec) ));
	}
	
	
	public static   haxe.root.Date now()
	{
		haxe.root.Date d = new haxe.root.Date(((int) (0) ), ((int) (0) ), ((int) (0) ), ((int) (0) ), ((int) (0) ), ((int) (0) ));
		d.date = new java.util.Date();
		return d;
	}
	
	
	public static   haxe.root.Date fromTime(double t)
	{
		haxe.root.Date d = new haxe.root.Date(((int) (0) ), ((int) (0) ), ((int) (0) ), ((int) (0) ), ((int) (0) ), ((int) (0) ));
		d.date = new java.util.Date(((long) (t) ));
		return d;
	}
	
	
	public static   haxe.root.Date fromString(java.lang.String s)
	{
		int _g = s.length();
		switch (_g)
		{
			case 8:
			{
				haxe.root.Array<java.lang.String> k = haxe.lang.StringExt.split(s, ":");
				haxe.root.Date d = new haxe.root.Date(((int) (0) ), ((int) (0) ), ((int) (0) ), ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(k.__get(0)))) ), ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(k.__get(1)))) ), ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(k.__get(2)))) ));
				return d;
			}
			
			
			case 10:
			{
				haxe.root.Array<java.lang.String> k1 = haxe.lang.StringExt.split(s, "-");
				return new haxe.root.Date(((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(k1.__get(0)))) ), ((int) (( ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(k1.__get(1)))) ) - ((int) (1) ) )) ), ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(k1.__get(2)))) ), ((int) (0) ), ((int) (0) ), ((int) (0) ));
			}
			
			
			case 19:
			{
				haxe.root.Array<java.lang.String> k2 = haxe.lang.StringExt.split(s, " ");
				haxe.root.Array<java.lang.String> y = haxe.lang.StringExt.split(k2.__get(0), "-");
				haxe.root.Array<java.lang.String> t = haxe.lang.StringExt.split(k2.__get(1), ":");
				return new haxe.root.Date(((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(y.__get(0)))) ), ((int) (( ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(y.__get(1)))) ) - ((int) (1) ) )) ), ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(y.__get(2)))) ), ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(t.__get(0)))) ), ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(t.__get(1)))) ), ((int) (haxe.lang.Runtime.toInt(haxe.root.Std.parseInt(t.__get(2)))) ));
			}
			
			
			default:
			{
				throw haxe.lang.HaxeException.wrap(( "Invalid date format : " + s ));
			}
			
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.Date(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.Date(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(3))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(4))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(5))) ));
	}
	
	
	public  java.util.Date date;
	
	public final   double getTime()
	{
		return ((double) (this.date.getTime()) );
	}
	
	
	public final   int getHours()
	{
		return this.date.getHours();
	}
	
	
	public final   int getMinutes()
	{
		return this.date.getMinutes();
	}
	
	
	public final   int getSeconds()
	{
		return this.date.getSeconds();
	}
	
	
	public final   int getFullYear()
	{
		return ( this.date.getYear() + 1900 );
	}
	
	
	public final   int getMonth()
	{
		return this.date.getMonth();
	}
	
	
	public final   int getDate()
	{
		return this.date.getDate();
	}
	
	
	public final   int getDay()
	{
		return this.date.getDay();
	}
	
	
	@Override public   java.lang.String toString()
	{
		int m = ( this.date.getMonth() + 1 );
		int d = this.date.getDate();
		int h = this.date.getHours();
		int mi = this.date.getMinutes();
		int s = this.date.getSeconds();
		return ( ( ( ( ( ( ( ( ( ( ( this.date.getYear() + 1900 ) + "-" ) + (( (( m < 10 )) ? (( "0" + m )) : (( "" + m )) )) ) + "-" ) + (( (( d < 10 )) ? (( "0" + d )) : (( "" + d )) )) ) + " " ) + (( (( h < 10 )) ? (( "0" + h )) : (( "" + h )) )) ) + ":" ) + (( (( mi < 10 )) ? (( "0" + mi )) : (( "" + mi )) )) ) + ":" ) + (( (( s < 10 )) ? (( "0" + s )) : (( "" + s )) )) );
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef160752 = true;
			switch (field.hashCode())
			{
				case 3076014:
				{
					if (field.equals("date")) 
					{
						__temp_executeDef160752 = false;
						this.date = ((java.util.Date) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160752) 
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
			boolean __temp_executeDef160753 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef160753 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("toString"))) );
					}
					
					break;
				}
				
				
				case 3076014:
				{
					if (field.equals("date")) 
					{
						__temp_executeDef160753 = false;
						return this.date;
					}
					
					break;
				}
				
				
				case -1249364890:
				{
					if (field.equals("getDay")) 
					{
						__temp_executeDef160753 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getDay"))) );
					}
					
					break;
				}
				
				
				case -75121853:
				{
					if (field.equals("getTime")) 
					{
						__temp_executeDef160753 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getTime"))) );
					}
					
					break;
				}
				
				
				case -75605980:
				{
					if (field.equals("getDate")) 
					{
						__temp_executeDef160753 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getDate"))) );
					}
					
					break;
				}
				
				
				case 1955294553:
				{
					if (field.equals("getHours")) 
					{
						__temp_executeDef160753 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getHours"))) );
					}
					
					break;
				}
				
				
				case 1959905482:
				{
					if (field.equals("getMonth")) 
					{
						__temp_executeDef160753 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getMonth"))) );
					}
					
					break;
				}
				
				
				case 2101762217:
				{
					if (field.equals("getMinutes")) 
					{
						__temp_executeDef160753 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getMinutes"))) );
					}
					
					break;
				}
				
				
				case -885883678:
				{
					if (field.equals("getFullYear")) 
					{
						__temp_executeDef160753 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getFullYear"))) );
					}
					
					break;
				}
				
				
				case -1288010167:
				{
					if (field.equals("getSeconds")) 
					{
						__temp_executeDef160753 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getSeconds"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160753) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
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
			boolean __temp_executeDef160754 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef160754 = false;
						return this.toString();
					}
					
					break;
				}
				
				
				case -75121853:
				{
					if (field.equals("getTime")) 
					{
						__temp_executeDef160754 = false;
						return this.getTime();
					}
					
					break;
				}
				
				
				case -1249364890:
				{
					if (field.equals("getDay")) 
					{
						__temp_executeDef160754 = false;
						return this.getDay();
					}
					
					break;
				}
				
				
				case 1955294553:
				{
					if (field.equals("getHours")) 
					{
						__temp_executeDef160754 = false;
						return this.getHours();
					}
					
					break;
				}
				
				
				case -75605980:
				{
					if (field.equals("getDate")) 
					{
						__temp_executeDef160754 = false;
						return this.getDate();
					}
					
					break;
				}
				
				
				case 2101762217:
				{
					if (field.equals("getMinutes")) 
					{
						__temp_executeDef160754 = false;
						return this.getMinutes();
					}
					
					break;
				}
				
				
				case 1959905482:
				{
					if (field.equals("getMonth")) 
					{
						__temp_executeDef160754 = false;
						return this.getMonth();
					}
					
					break;
				}
				
				
				case -1288010167:
				{
					if (field.equals("getSeconds")) 
					{
						__temp_executeDef160754 = false;
						return this.getSeconds();
					}
					
					break;
				}
				
				
				case -885883678:
				{
					if (field.equals("getFullYear")) 
					{
						__temp_executeDef160754 = false;
						return this.getFullYear();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160754) 
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
		baseArr.push("date");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


