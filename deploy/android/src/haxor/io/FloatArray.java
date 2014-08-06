package haxor.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class FloatArray extends haxor.io.BaseArray
{
	public    FloatArray(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    FloatArray(int p_capacity)
	{
		haxor.io.FloatArray.__hx_ctor_haxor_io_FloatArray(this, p_capacity);
	}
	
	
	public static   void __hx_ctor_haxor_io_FloatArray(haxor.io.FloatArray __temp_me26103, int p_capacity)
	{
		__temp_me26103.b = java.nio.ByteBuffer.allocateDirect(((int) (( p_capacity * 4 )) )).order(((java.nio.ByteOrder) (java.nio.ByteOrder.nativeOrder()) )).asFloatBuffer();
	}
	
	
	public static   haxor.io.FloatArray Create(haxe.root.Array<java.lang.Object> p_data)
	{
		haxor.io.FloatArray a = new haxor.io.FloatArray(((int) (p_data.length) ));
		a.Fill(p_data);
		return a;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.FloatArray(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.FloatArray(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ));
	}
	
	
	@Override public   int get_length()
	{
		return this.b.capacity();
	}
	
	
	@Override public   java.lang.String get_type()
	{
		return "float";
	}
	
	
	public  java.nio.FloatBuffer b;
	
	public   haxor.io.FloatArray Clone()
	{
		haxor.io.FloatArray a = new haxor.io.FloatArray(((int) (this.b.capacity()) ));
		{
			int _g1 = 0;
			int _g = this.b.capacity();
			while (( _g1 < _g ))
			{
				int i = _g1++;
				double n = ((double) (this.b.get(((int) (i) ))) );
				a.b.put(((int) (i) ), ((float) (n) ));
			}
			
		}
		
		return a;
	}
	
	
	public   void Fill(haxe.root.Array<java.lang.Object> p_data)
	{
		int _g1 = 0;
		int _g = p_data.length;
		while (( _g1 < _g ))
		{
			int i = _g1++;
			this.b.put(((int) (i) ), ((float) (((double) (haxe.lang.Runtime.toDouble(p_data.__get(i))) )) ));
		}
		
	}
	
	
	public final   double Get(int k)
	{
		return ((double) (this.b.get(((int) (k) ))) );
	}
	
	
	public final   void Set(int k, double v)
	{
		this.b.put(((int) (k) ), ((float) (v) ));
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef26198 = true;
			switch (field.hashCode())
			{
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef26198 = false;
						this.b = ((java.nio.FloatBuffer) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26198) 
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
			boolean __temp_executeDef26199 = true;
			switch (field.hashCode())
			{
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef26199 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef26199 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef26199 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Get"))) );
					}
					
					break;
				}
				
				
				case 1976688259:
				{
					if (field.equals("get_type")) 
					{
						__temp_executeDef26199 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_type"))) );
					}
					
					break;
				}
				
				
				case 2189731:
				{
					if (field.equals("Fill")) 
					{
						__temp_executeDef26199 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Fill"))) );
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef26199 = false;
						return this.b;
					}
					
					break;
				}
				
				
				case 65203517:
				{
					if (field.equals("Clone")) 
					{
						__temp_executeDef26199 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Clone"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26199) 
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
			int __temp_hash26201 = field.hashCode();
			boolean __temp_executeDef26200 = true;
			switch (__temp_hash26201)
			{
				case 1976688259:case 974314479:
				{
					if (( (( ( __temp_hash26201 == 1976688259 ) && field.equals("get_type") )) || field.equals("get_length") )) 
					{
						__temp_executeDef26200 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 65203517:
				{
					if (field.equals("Clone")) 
					{
						__temp_executeDef26200 = false;
						return this.Clone();
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef26200 = false;
						this.Set(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 2189731:
				{
					if (field.equals("Fill")) 
					{
						__temp_executeDef26200 = false;
						this.Fill(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef26200 = false;
						return this.Get(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef26200) 
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


