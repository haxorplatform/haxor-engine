package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Process<T> extends haxor.context.BaseProcess
{
	public    Process(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    Process(java.lang.String p_name, int p_size)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.context.Process.__hx_ctor_haxor_context_Process(this, p_name, p_size);
	}
	
	
	public static  <T_c> void __hx_ctor_haxor_context_Process(haxor.context.Process<T_c> __temp_me27887, java.lang.String p_name, int p_size)
	{
		haxor.context.BaseProcess.__hx_ctor_haxor_context_BaseProcess(__temp_me27887, p_name);
		__temp_me27887.list = new haxe.root.Array<T_c>(( (T_c[]) (new java.lang.Object[] {}) ));
		__temp_me27887.m_length = 0;
		{
			int _g = 0;
			while (( _g < p_size ))
			{
				int i = _g++;
				__temp_me27887.list.push(null);
			}
			
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.Process<java.lang.Object>(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.Process<java.lang.Object>(haxe.lang.Runtime.toString(arr.__get(0)), ((int) (haxe.lang.Runtime.toInt(arr.__get(1))) ));
	}
	
	
	public  haxe.root.Array<T> list;
	
	@Override public   int get_length()
	{
		return this.m_length;
	}
	
	
	public  int m_length;
	
	@Override public   void Add(haxor.core.Resource p_item)
	{
		int iid = ((int) (haxe.lang.Runtime.toInt(p_item.m_pid.__get(this._cid_))) );
		if (( iid >= 0 )) 
		{
			return ;
		}
		
		this.list.__set(this.m_length, ((T) (((java.lang.Object) (p_item) )) ));
		p_item.m_pid.__set(this._cid_, this.m_length++);
	}
	
	
	@Override public   haxor.core.Resource Remove(haxor.core.Resource p_item)
	{
		int iid = ((int) (haxe.lang.Runtime.toInt(p_item.m_pid.__get(this._cid_))) );
		if (( iid < 0 )) 
		{
			return p_item;
		}
		
		p_item.m_pid.__set(this._cid_, -1);
		this.m_length--;
		if (( this.m_length <= 0 )) 
		{
			return p_item;
		}
		
		this.list.__set(iid, this.list.__get(this.m_length));
		p_item = ((haxor.core.Resource) (((java.lang.Object) (this.list.__get(iid)) )) );
		p_item.m_pid.__set(this._cid_, iid);
		return p_item;
	}
	
	
	@Override public   void Clear()
	{
		this.m_length = 0;
		this.list = new haxe.root.Array<T>(( (T[]) (new java.lang.Object[] {}) ));
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef28068 = true;
			switch (field.hashCode())
			{
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef28068 = false;
						this.m_length = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28068) 
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
			boolean __temp_executeDef28069 = true;
			switch (field.hashCode())
			{
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef28069 = false;
						this.m_length = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3322014:
				{
					if (field.equals("list")) 
					{
						__temp_executeDef28069 = false;
						this.list = ((haxe.root.Array<T>) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28069) 
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
			boolean __temp_executeDef28070 = true;
			switch (field.hashCode())
			{
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef28070 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case 3322014:
				{
					if (field.equals("list")) 
					{
						__temp_executeDef28070 = false;
						return this.list;
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef28070 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Remove"))) );
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef28070 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef28070 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add"))) );
					}
					
					break;
				}
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef28070 = false;
						return this.m_length;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28070) 
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
			boolean __temp_executeDef28071 = true;
			switch (field.hashCode())
			{
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef28071 = false;
						return ((double) (this.m_length) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28071) 
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
		baseArr.push("m_length");
		baseArr.push("list");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


