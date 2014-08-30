package haxe.ds._WeakMap;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Entry<K, V> extends java.lang.ref.WeakReference<K> implements haxe.lang.IHxObject
{
	public    Entry(haxe.lang.EmptyObject empty)
	{
		super(null);
	}
	
	
	public    Entry(K key, V value, int hash, java.lang.ref.ReferenceQueue<K> queue)
	{
		super(key, ((java.lang.ref.ReferenceQueue) (((java.lang.ref.ReferenceQueue) (queue) )) ));
		this.value = value;
		this.hash = hash;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.ds._WeakMap.Entry<java.lang.Object, java.lang.Object>(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.ds._WeakMap.Entry<java.lang.Object, java.lang.Object>(((java.lang.Object) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(2))) ), ((java.lang.ref.ReferenceQueue<java.lang.Object>) (arr.__get(3)) ));
	}
	
	
	public  V value;
	
	public  int hash;
	
	public final   boolean keyEquals(K k)
	{
		return ( ( ! (( k == null )) ) && k.equals(this.get()) );
	}
	
	
	public   boolean __hx_deleteField(java.lang.String field)
	{
		return false;
	}
	
	
	public   java.lang.Object __hx_lookupField(java.lang.String field, boolean throwErrors, boolean isCheck)
	{
		if (isCheck) 
		{
			return haxe.lang.Runtime.undefined;
		}
		 else 
		{
			if (throwErrors) 
			{
				throw haxe.lang.HaxeException.wrap("Field not found.");
			}
			 else 
			{
				return null;
			}
			
		}
		
	}
	
	
	public   double __hx_lookupField_f(java.lang.String field, boolean throwErrors)
	{
		if (throwErrors) 
		{
			throw haxe.lang.HaxeException.wrap("Field not found or incompatible field type.");
		}
		 else 
		{
			return 0.0;
		}
		
	}
	
	
	public   java.lang.Object __hx_lookupSetField(java.lang.String field, java.lang.Object value)
	{
		throw haxe.lang.HaxeException.wrap("Cannot access field for writing.");
	}
	
	
	public   double __hx_lookupSetField_f(java.lang.String field, double value)
	{
		throw haxe.lang.HaxeException.wrap("Cannot access field for writing or incompatible type.");
	}
	
	
	public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef151820 = true;
			switch (field.hashCode())
			{
				case 3195150:
				{
					if (field.equals("hash")) 
					{
						__temp_executeDef151820 = false;
						this.hash = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef151820 = false;
						this.value = ((V) (((java.lang.Object) (value) )) );
						return ((double) (haxe.lang.Runtime.toDouble(((java.lang.Object) (value) ))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151820) 
			{
				return this.__hx_lookupSetField_f(field, value);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef151821 = true;
			switch (field.hashCode())
			{
				case 3195150:
				{
					if (field.equals("hash")) 
					{
						__temp_executeDef151821 = false;
						this.hash = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef151821 = false;
						this.value = ((V) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151821) 
			{
				return this.__hx_lookupSetField(field, value);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef151822 = true;
			switch (field.hashCode())
			{
				case 1324341926:
				{
					if (field.equals("isEnqueued")) 
					{
						__temp_executeDef151822 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("isEnqueued"))) );
					}
					
					break;
				}
				
				
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef151822 = false;
						return this.value;
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef151822 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get"))) );
					}
					
					break;
				}
				
				
				case 3195150:
				{
					if (field.equals("hash")) 
					{
						__temp_executeDef151822 = false;
						return this.hash;
					}
					
					break;
				}
				
				
				case -1594257912:
				{
					if (field.equals("enqueue")) 
					{
						__temp_executeDef151822 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("enqueue"))) );
					}
					
					break;
				}
				
				
				case 1903199998:
				{
					if (field.equals("keyEquals")) 
					{
						__temp_executeDef151822 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("keyEquals"))) );
					}
					
					break;
				}
				
				
				case 94746189:
				{
					if (field.equals("clear")) 
					{
						__temp_executeDef151822 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("clear"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151822) 
			{
				return this.__hx_lookupField(field, throwErrors, isCheck);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			boolean __temp_executeDef151823 = true;
			switch (field.hashCode())
			{
				case 3195150:
				{
					if (field.equals("hash")) 
					{
						__temp_executeDef151823 = false;
						return ((double) (this.hash) );
					}
					
					break;
				}
				
				
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef151823 = false;
						return ((double) (haxe.lang.Runtime.toDouble(((java.lang.Object) (this.value) ))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151823) 
			{
				return this.__hx_lookupField_f(field, throwErrors);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			int __temp_hash151825 = field.hashCode();
			boolean __temp_executeDef151824 = true;
			switch (__temp_hash151825)
			{
				case 1324341926:case 102230:case -1594257912:case 94746189:
				{
					if (( (( ( __temp_hash151825 == 1324341926 ) && field.equals("isEnqueued") )) || ( (( ( __temp_hash151825 == 102230 ) && field.equals("get") )) || ( (( ( __temp_hash151825 == -1594257912 ) && field.equals("enqueue") )) || field.equals("clear") ) ) )) 
					{
						__temp_executeDef151824 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1903199998:
				{
					if (field.equals("keyEquals")) 
					{
						__temp_executeDef151824 = false;
						return this.keyEquals(((K) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef151824) 
			{
				return ((haxe.lang.Function) (this.__hx_getField(field, true, false, false)) ).__hx_invokeDynamic(dynargs);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("hash");
		baseArr.push("value");
	}
	
	
}


