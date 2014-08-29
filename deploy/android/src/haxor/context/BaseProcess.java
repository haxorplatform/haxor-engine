package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class BaseProcess extends haxe.lang.HxObject
{
	static 
	{
		haxor.context.BaseProcess.m_cid = 0;
	}
	public    BaseProcess(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    BaseProcess(java.lang.String p_name, java.lang.Object p_update_cid)
	{
		haxor.context.BaseProcess.__hx_ctor_haxor_context_BaseProcess(this, p_name, p_update_cid);
	}
	
	
	public static   void __hx_ctor_haxor_context_BaseProcess(haxor.context.BaseProcess __temp_me80603, java.lang.String p_name, java.lang.Object p_update_cid)
	{
		boolean __temp_p_update_cid80602 = ( (( p_update_cid == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_update_cid)) );
		__temp_me80603.name = p_name;
		__temp_me80603.__cid = haxor.context.BaseProcess.m_cid;
		haxor.core.Console.Log(( ( ( ( "\tProcess [" + p_name ) + "][" ) + __temp_me80603.__cid ) + "] created." ), 6);
		if (__temp_p_update_cid80602) 
		{
			haxor.context.BaseProcess.m_cid++;
		}
		
	}
	
	
	public static  int m_cid;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.BaseProcess(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.BaseProcess(haxe.lang.Runtime.toString(arr.__get(0)), ((java.lang.Object) (arr.__get(1)) ));
	}
	
	
	public  int __cid;
	
	public  java.lang.String name;
	
	public  int length;
	
	public   int get_length()
	{
		return 0;
	}
	
	
	public   void Add(haxor.core.Resource p_item)
	{
		{
		}
		
	}
	
	
	public   haxor.core.Resource Remove(haxor.core.Resource p_item)
	{
		return null;
	}
	
	
	public   void Clear()
	{
		{
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef81295 = true;
			switch (field.hashCode())
			{
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef81295 = false;
						this.length = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef81295 = false;
						this.__cid = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81295) 
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
			boolean __temp_executeDef81296 = true;
			switch (field.hashCode())
			{
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef81296 = false;
						this.length = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef81296 = false;
						this.__cid = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef81296 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81296) 
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
			boolean __temp_executeDef81297 = true;
			switch (field.hashCode())
			{
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef81297 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef81297 = false;
						return this.__cid;
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef81297 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Remove"))) );
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef81297 = false;
						return this.name;
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef81297 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add"))) );
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef81297 = false;
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
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef81297 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81297) 
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
			boolean __temp_executeDef81298 = true;
			switch (field.hashCode())
			{
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef81298 = false;
						if (handleProperties) 
						{
							return ((double) (this.get_length()) );
						}
						 else 
						{
							return ((double) (this.length) );
						}
						
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef81298 = false;
						return ((double) (this.__cid) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81298) 
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
			boolean __temp_executeDef81299 = true;
			switch (field.hashCode())
			{
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef81299 = false;
						this.Clear();
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef81299 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef81299 = false;
						return this.Remove(((haxor.core.Resource) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef81299 = false;
						this.Add(((haxor.core.Resource) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81299) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("length");
		baseArr.push("name");
		baseArr.push("__cid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


