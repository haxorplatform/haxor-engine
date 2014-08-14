package haxe.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Bytes extends haxe.lang.HxObject
{
	public    Bytes(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Bytes(int length, byte[] b)
	{
		haxe.io.Bytes.__hx_ctor_haxe_io_Bytes(this, length, b);
	}
	
	
	public static   void __hx_ctor_haxe_io_Bytes(haxe.io.Bytes __temp_me21731, int length, byte[] b)
	{
		__temp_me21731.length = length;
		__temp_me21731.b = b;
	}
	
	
	public static   haxe.io.Bytes ofString(java.lang.String s)
	{
		try 
		{
			byte[] b = s.getBytes(haxe.lang.Runtime.toString("UTF-8"));
			return new haxe.io.Bytes(((int) (b.length) ), ((byte[]) (b) ));
		}
		catch (java.lang.Throwable __temp_catchallException21860)
		{
			java.lang.Object __temp_catchall21861 = __temp_catchallException21860;
			if (( __temp_catchall21861 instanceof haxe.lang.HaxeException )) 
			{
				__temp_catchall21861 = ((haxe.lang.HaxeException) (__temp_catchallException21860) ).obj;
			}
			
			{
				java.lang.Object e = __temp_catchall21861;
				throw haxe.lang.HaxeException.wrap(e);
			}
			
		}
		
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.io.Bytes(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.io.Bytes(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ), ((byte[]) (arr.__get(1)) ));
	}
	
	
	public  int length;
	
	public  byte[] b;
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef21856 = true;
			switch (field.hashCode())
			{
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef21856 = false;
						this.length = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21856) 
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
			boolean __temp_executeDef21857 = true;
			switch (field.hashCode())
			{
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef21857 = false;
						this.b = ((byte[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef21857 = false;
						this.length = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21857) 
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
			boolean __temp_executeDef21858 = true;
			switch (field.hashCode())
			{
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef21858 = false;
						return this.b;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef21858 = false;
						return this.length;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21858) 
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
			boolean __temp_executeDef21859 = true;
			switch (field.hashCode())
			{
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef21859 = false;
						return ((double) (this.length) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21859) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("b");
		baseArr.push("length");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


