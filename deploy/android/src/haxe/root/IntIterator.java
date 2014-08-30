package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class IntIterator extends haxe.lang.HxObject
{
	public    IntIterator(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    IntIterator(int min, int max)
	{
		haxe.root.IntIterator.__hx_ctor__IntIterator(this, min, max);
	}
	
	
	public static   void __hx_ctor__IntIterator(haxe.root.IntIterator __temp_me151266, int min, int max)
	{
		__temp_me151266.min = min;
		__temp_me151266.max = max;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.IntIterator(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.IntIterator(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(1))) ));
	}
	
	
	public  int min;
	
	public  int max;
	
	public   boolean hasNext()
	{
		return ( this.min < this.max );
	}
	
	
	public   int next()
	{
		return this.min++;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef151642 = true;
			switch (field.hashCode())
			{
				case 107876:
				{
					if (field.equals("max")) 
					{
						__temp_executeDef151642 = false;
						this.max = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 108114:
				{
					if (field.equals("min")) 
					{
						__temp_executeDef151642 = false;
						this.min = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151642) 
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
			boolean __temp_executeDef151643 = true;
			switch (field.hashCode())
			{
				case 107876:
				{
					if (field.equals("max")) 
					{
						__temp_executeDef151643 = false;
						this.max = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 108114:
				{
					if (field.equals("min")) 
					{
						__temp_executeDef151643 = false;
						this.min = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151643) 
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
			boolean __temp_executeDef151644 = true;
			switch (field.hashCode())
			{
				case 3377907:
				{
					if (field.equals("next")) 
					{
						__temp_executeDef151644 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("next"))) );
					}
					
					break;
				}
				
				
				case 108114:
				{
					if (field.equals("min")) 
					{
						__temp_executeDef151644 = false;
						return this.min;
					}
					
					break;
				}
				
				
				case 696759469:
				{
					if (field.equals("hasNext")) 
					{
						__temp_executeDef151644 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("hasNext"))) );
					}
					
					break;
				}
				
				
				case 107876:
				{
					if (field.equals("max")) 
					{
						__temp_executeDef151644 = false;
						return this.max;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151644) 
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
			boolean __temp_executeDef151645 = true;
			switch (field.hashCode())
			{
				case 107876:
				{
					if (field.equals("max")) 
					{
						__temp_executeDef151645 = false;
						return ((double) (this.max) );
					}
					
					break;
				}
				
				
				case 108114:
				{
					if (field.equals("min")) 
					{
						__temp_executeDef151645 = false;
						return ((double) (this.min) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151645) 
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
			boolean __temp_executeDef151646 = true;
			switch (field.hashCode())
			{
				case 3377907:
				{
					if (field.equals("next")) 
					{
						__temp_executeDef151646 = false;
						return this.next();
					}
					
					break;
				}
				
				
				case 696759469:
				{
					if (field.equals("hasNext")) 
					{
						__temp_executeDef151646 = false;
						return this.hasNext();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151646) 
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
		baseArr.push("max");
		baseArr.push("min");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


