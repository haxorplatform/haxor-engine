package haxor.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class BaseArray extends haxe.lang.HxObject
{
	public    BaseArray(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    BaseArray()
	{
		haxor.io.BaseArray.__hx_ctor_haxor_io_BaseArray(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_BaseArray(haxor.io.BaseArray __temp_me26102)
	{
		{
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.BaseArray(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.BaseArray();
	}
	
	
	
	
	public   int get_length()
	{
		return 0;
	}
	
	
	
	
	public   java.lang.String get_type()
	{
		return "";
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef26195 = true;
			switch (field.hashCode())
			{
				case 1976688259:
				{
					if (field.equals("get_type")) 
					{
						__temp_executeDef26195 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_type"))) );
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef26195 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef26195 = false;
						return this.get_type();
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef26195 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26195) 
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
			boolean __temp_executeDef26196 = true;
			switch (field.hashCode())
			{
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef26196 = false;
						return ((double) (this.get_length()) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26196) 
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
			boolean __temp_executeDef26197 = true;
			switch (field.hashCode())
			{
				case 1976688259:
				{
					if (field.equals("get_type")) 
					{
						__temp_executeDef26197 = false;
						return this.get_type();
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef26197 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26197) 
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
		baseArr.push("type");
		baseArr.push("length");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


