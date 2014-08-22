package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class StringBuf extends haxe.lang.HxObject
{
	public    StringBuf(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    StringBuf()
	{
		haxe.root.StringBuf.__hx_ctor__StringBuf(this);
	}
	
	
	public static   void __hx_ctor__StringBuf(haxe.root.StringBuf __temp_me55664)
	{
		__temp_me55664.b = new java.lang.StringBuilder();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.StringBuf(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.StringBuf();
	}
	
	
	public  java.lang.StringBuilder b;
	
	public  <T> void add(T x)
	{
		if (haxe.lang.Runtime.isInt(x)) 
		{
			int x1 = ((int) (haxe.lang.Runtime.toInt(((java.lang.Object) (x) ))) );
			java.lang.Object xd = x1;
			this.b.append(((java.lang.Object) (xd) ));
		}
		 else 
		{
			this.b.append(((java.lang.Object) (x) ));
		}
		
	}
	
	
	public   void addSub(java.lang.String s, int pos, java.lang.Object len)
	{
		int l = 0;
		if (( len == null )) 
		{
			l = ( s.length() - pos );
		}
		 else 
		{
			l = ((int) (haxe.lang.Runtime.toInt(len)) );
		}
		
		this.b.append(((java.lang.CharSequence) (s) ), ((int) (pos) ), ((int) (( pos + l )) ));
	}
	
	
	@Override public   java.lang.String toString()
	{
		return this.b.toString();
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef55816 = true;
			switch (field.hashCode())
			{
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef55816 = false;
						this.b = ((java.lang.StringBuilder) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef55816) 
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
			boolean __temp_executeDef55817 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef55817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("toString"))) );
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef55817 = false;
						return this.b;
					}
					
					break;
				}
				
				
				case -1422524961:
				{
					if (field.equals("addSub")) 
					{
						__temp_executeDef55817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("addSub"))) );
					}
					
					break;
				}
				
				
				case 96417:
				{
					if (field.equals("add")) 
					{
						__temp_executeDef55817 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("add"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef55817) 
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
			boolean __temp_executeDef55818 = true;
			switch (field.hashCode())
			{
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef55818 = false;
						return this.toString();
					}
					
					break;
				}
				
				
				case 96417:
				{
					if (field.equals("add")) 
					{
						__temp_executeDef55818 = false;
						this.add(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case -1422524961:
				{
					if (field.equals("addSub")) 
					{
						__temp_executeDef55818 = false;
						this.addSub(haxe.lang.Runtime.toString(dynargs.__get(0)), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), dynargs.__get(2));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef55818) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("b");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


