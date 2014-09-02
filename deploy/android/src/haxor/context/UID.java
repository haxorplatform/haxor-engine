package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class UID extends haxe.lang.HxObject
{
	public    UID(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    UID()
	{
		haxor.context.UID.__hx_ctor_haxor_context_UID(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_UID(haxor.context.UID __temp_me160458)
	{
		__temp_me160458.m_id = 0;
		__temp_me160458.m_cache = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.UID(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.UID();
	}
	
	
	
	
	public final   int get_id()
	{
		if (( this.m_cache.length <= 0 )) 
		{
			return this.m_id++;
		}
		 else 
		{
			return ((int) (haxe.lang.Runtime.toInt(this.m_cache.shift())) );
		}
		
	}
	
	
	public final   int set_id(int v)
	{
		this.m_cache.push(v);
		return v;
	}
	
	
	public  int m_id;
	
	public  haxe.root.Array<java.lang.Object> m_cache;
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161188 = true;
			switch (field.hashCode())
			{
				case 3341869:
				{
					if (field.equals("m_id")) 
					{
						__temp_executeDef161188 = false;
						this.m_id = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef161188 = false;
						this.set_id(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161188) 
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
			boolean __temp_executeDef161189 = true;
			switch (field.hashCode())
			{
				case 767839536:
				{
					if (field.equals("m_cache")) 
					{
						__temp_executeDef161189 = false;
						this.m_cache = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef161189 = false;
						this.set_id(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 3341869:
				{
					if (field.equals("m_id")) 
					{
						__temp_executeDef161189 = false;
						this.m_id = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161189) 
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
			boolean __temp_executeDef161190 = true;
			switch (field.hashCode())
			{
				case 767839536:
				{
					if (field.equals("m_cache")) 
					{
						__temp_executeDef161190 = false;
						return this.m_cache;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef161190 = false;
						return this.get_id();
					}
					
					break;
				}
				
				
				case 3341869:
				{
					if (field.equals("m_id")) 
					{
						__temp_executeDef161190 = false;
						return this.m_id;
					}
					
					break;
				}
				
				
				case -1249338716:
				{
					if (field.equals("get_id")) 
					{
						__temp_executeDef161190 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_id"))) );
					}
					
					break;
				}
				
				
				case -905788904:
				{
					if (field.equals("set_id")) 
					{
						__temp_executeDef161190 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_id"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161190) 
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
			boolean __temp_executeDef161191 = true;
			switch (field.hashCode())
			{
				case 3341869:
				{
					if (field.equals("m_id")) 
					{
						__temp_executeDef161191 = false;
						return ((double) (this.m_id) );
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef161191 = false;
						return ((double) (this.get_id()) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161191) 
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
			boolean __temp_executeDef161192 = true;
			switch (field.hashCode())
			{
				case -905788904:
				{
					if (field.equals("set_id")) 
					{
						__temp_executeDef161192 = false;
						return this.set_id(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1249338716:
				{
					if (field.equals("get_id")) 
					{
						__temp_executeDef161192 = false;
						return this.get_id();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161192) 
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
		baseArr.push("m_cache");
		baseArr.push("m_id");
		baseArr.push("id");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


