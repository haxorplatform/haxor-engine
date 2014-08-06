package haxor.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class UInt16Array extends haxor.io.BaseArray
{
	public    UInt16Array(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    UInt16Array(int p_capacity)
	{
		haxor.io.UInt16Array.__hx_ctor_haxor_io_UInt16Array(this, p_capacity);
	}
	
	
	public static   void __hx_ctor_haxor_io_UInt16Array(haxor.io.UInt16Array __temp_me26105, int p_capacity)
	{
		__temp_me26105.b = java.nio.ByteBuffer.allocateDirect(((int) (( p_capacity * 2 )) )).order(((java.nio.ByteOrder) (java.nio.ByteOrder.nativeOrder()) )).asShortBuffer();
	}
	
	
	public static   haxor.io.UInt16Array Create(haxe.root.Array<java.lang.Object> p_data)
	{
		haxor.io.UInt16Array a = new haxor.io.UInt16Array(((int) (p_data.length) ));
		a.Set(((haxe.root.Array<java.lang.Object>) (p_data) ));
		return a;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.UInt16Array(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.UInt16Array(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ));
	}
	
	
	@Override public   int get_length()
	{
		return this.b.capacity();
	}
	
	
	@Override public   java.lang.String get_type()
	{
		return "int";
	}
	
	
	public  java.nio.ShortBuffer b;
	
	public   haxor.io.UInt16Array Clone()
	{
		haxor.io.UInt16Array a = new haxor.io.UInt16Array(((int) (this.b.capacity()) ));
		{
			int _g1 = 0;
			int _g = this.b.capacity();
			while (( _g1 < _g ))
			{
				int i = _g1++;
				int v = ((int) (this.b.get(((int) (i) ))) );
				a.b.put(((int) (i) ), ((short) (v) ));
				int __temp_expr26206 = v;
			}
			
		}
		
		return a;
	}
	
	
	public   void Set(haxe.root.Array<java.lang.Object> p_data)
	{
		int _g1 = 0;
		int _g = p_data.length;
		while (( _g1 < _g ))
		{
			int i = _g1++;
			int v = ((int) (haxe.lang.Runtime.toInt(p_data.__get(i))) );
			this.b.put(((int) (i) ), ((short) (v) ));
			int __temp_expr26207 = v;
		}
		
	}
	
	
	public final   int array_get(int k)
	{
		return ((int) (this.b.get(((int) (k) ))) );
	}
	
	
	public final   int array_set(int k, int v)
	{
		this.b.put(((int) (k) ), ((short) (v) ));
		return v;
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef26208 = true;
			switch (field.hashCode())
			{
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef26208 = false;
						this.b = ((java.nio.ShortBuffer) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26208) 
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
			boolean __temp_executeDef26209 = true;
			switch (field.hashCode())
			{
				case -1424586372:
				{
					if (field.equals("array_set")) 
					{
						__temp_executeDef26209 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("array_set"))) );
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef26209 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
				case -1424597904:
				{
					if (field.equals("array_get")) 
					{
						__temp_executeDef26209 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("array_get"))) );
					}
					
					break;
				}
				
				
				case 1976688259:
				{
					if (field.equals("get_type")) 
					{
						__temp_executeDef26209 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_type"))) );
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef26209 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef26209 = false;
						return this.b;
					}
					
					break;
				}
				
				
				case 65203517:
				{
					if (field.equals("Clone")) 
					{
						__temp_executeDef26209 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clone"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26209) 
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
			int __temp_hash26211 = field.hashCode();
			boolean __temp_executeDef26210 = true;
			switch (__temp_hash26211)
			{
				case 1976688259:case 974314479:
				{
					if (( (( ( __temp_hash26211 == 1976688259 ) && field.equals("get_type") )) || field.equals("get_length") )) 
					{
						__temp_executeDef26210 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 65203517:
				{
					if (field.equals("Clone")) 
					{
						__temp_executeDef26210 = false;
						return this.Clone();
					}
					
					break;
				}
				
				
				case -1424586372:
				{
					if (field.equals("array_set")) 
					{
						__temp_executeDef26210 = false;
						return this.array_set(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef26210 = false;
						this.Set(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1424597904:
				{
					if (field.equals("array_get")) 
					{
						__temp_executeDef26210 = false;
						return this.array_get(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26210) 
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


