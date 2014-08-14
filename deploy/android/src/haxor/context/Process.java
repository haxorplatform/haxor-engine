package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Process<T> extends haxe.lang.HxObject
{
	static 
	{
		haxor.context.Process.m_cid = 0;
	}
	public    Process(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Process(java.lang.String p_name, int p_size)
	{
		haxor.context.Process.__hx_ctor_haxor_context_Process(this, p_name, p_size);
	}
	
	
	public static  <T_c> void __hx_ctor_haxor_context_Process(haxor.context.Process<T_c> __temp_me21739, java.lang.String p_name, int p_size)
	{
		__temp_me21739.name = p_name;
		haxor.core.Console.Log(( ( "\tProcess [" + p_name ) + "] created." ), 4);
		__temp_me21739._cid_ = haxor.context.Process.m_cid++;
		__temp_me21739.list = new haxe.root.Array<T_c>(( (T_c[]) (new java.lang.Object[] {}) ));
		__temp_me21739.m_length = 0;
		{
			int _g = 0;
			while (( _g < p_size ))
			{
				int i = _g++;
				__temp_me21739.list.push(null);
			}
			
		}
		
	}
	
	
	public static  int m_cid;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.Process<java.lang.Object>(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.Process<java.lang.Object>(haxe.lang.Runtime.toString(arr.__get(0)), ((int) (haxe.lang.Runtime.toInt(arr.__get(1))) ));
	}
	
	
	public  java.lang.String name;
	
	public  haxe.root.Array<T> list;
	
	public  int length;
	
	public   int get_length()
	{
		return this.m_length;
	}
	
	
	public  int m_length;
	
	public  int _cid_;
	
	public  haxe.root.Array<T> m_remove_queue;
	
	public   void Add(haxor.core.Resource p_item)
	{
		int iid = ((int) (haxe.lang.Runtime.toInt(p_item.m_pid.__get(this._cid_))) );
		if (( iid >= 0 )) 
		{
			return ;
		}
		
		this.list.__set(this.m_length, ((T) (((java.lang.Object) (p_item) )) ));
		p_item.m_pid.__set(this._cid_, this.m_length++);
	}
	
	
	public   haxor.core.Resource Remove(haxor.core.Resource p_item)
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
	
	
	public   void Clear()
	{
		this.m_length = 0;
		this.list = new haxe.root.Array<T>(( (T[]) (new java.lang.Object[] {}) ));
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef21903 = true;
			switch (field.hashCode())
			{
				case 90787904:
				{
					if (field.equals("_cid_")) 
					{
						__temp_executeDef21903 = false;
						this._cid_ = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef21903 = false;
						this.length = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef21903 = false;
						this.m_length = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21903) 
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
			boolean __temp_executeDef21904 = true;
			switch (field.hashCode())
			{
				case -1887353816:
				{
					if (field.equals("m_remove_queue")) 
					{
						__temp_executeDef21904 = false;
						this.m_remove_queue = ((haxe.root.Array<T>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef21904 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 90787904:
				{
					if (field.equals("_cid_")) 
					{
						__temp_executeDef21904 = false;
						this._cid_ = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3322014:
				{
					if (field.equals("list")) 
					{
						__temp_executeDef21904 = false;
						this.list = ((haxe.root.Array<T>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef21904 = false;
						this.m_length = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef21904 = false;
						this.length = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21904) 
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
			boolean __temp_executeDef21905 = true;
			switch (field.hashCode())
			{
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef21905 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clear"))) );
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef21905 = false;
						return this.name;
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef21905 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Remove"))) );
					}
					
					break;
				}
				
				
				case 3322014:
				{
					if (field.equals("list")) 
					{
						__temp_executeDef21905 = false;
						return this.list;
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef21905 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Add"))) );
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef21905 = false;
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
				
				
				case -1887353816:
				{
					if (field.equals("m_remove_queue")) 
					{
						__temp_executeDef21905 = false;
						return this.m_remove_queue;
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef21905 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
				case 90787904:
				{
					if (field.equals("_cid_")) 
					{
						__temp_executeDef21905 = false;
						return this._cid_;
					}
					
					break;
				}
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef21905 = false;
						return this.m_length;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21905) 
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
			boolean __temp_executeDef21906 = true;
			switch (field.hashCode())
			{
				case 90787904:
				{
					if (field.equals("_cid_")) 
					{
						__temp_executeDef21906 = false;
						return ((double) (this._cid_) );
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef21906 = false;
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
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef21906 = false;
						return ((double) (this.m_length) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21906) 
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
			boolean __temp_executeDef21907 = true;
			switch (field.hashCode())
			{
				case 65193517:
				{
					if (field.equals("Clear")) 
					{
						__temp_executeDef21907 = false;
						this.Clear();
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef21907 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case -1850743644:
				{
					if (field.equals("Remove")) 
					{
						__temp_executeDef21907 = false;
						return this.Remove(((haxor.core.Resource) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 65665:
				{
					if (field.equals("Add")) 
					{
						__temp_executeDef21907 = false;
						this.Add(((haxor.core.Resource) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21907) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_remove_queue");
		baseArr.push("_cid_");
		baseArr.push("m_length");
		baseArr.push("length");
		baseArr.push("list");
		baseArr.push("name");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


