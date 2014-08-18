package haxor.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class UInt16Array extends haxor.io.Buffer
{
	public    UInt16Array(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    UInt16Array(int p_length)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.io.UInt16Array.__hx_ctor_haxor_io_UInt16Array(this, p_length);
	}
	
	
	public static   void __hx_ctor_haxor_io_UInt16Array(haxor.io.UInt16Array __temp_me33839, int p_length)
	{
		haxor.io.Buffer.__hx_ctor_haxor_io_Buffer(__temp_me33839, p_length);
		__temp_me33839.aux = __temp_me33839.m_buffer.asShortBuffer();
	}
	
	
	public static   haxor.io.UInt16Array Alloc(haxe.root.Array<java.lang.Object> p_data)
	{
		haxor.io.UInt16Array b = new haxor.io.UInt16Array(((int) (p_data.length) ));
		b.SetRange(p_data, null);
		return b;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.UInt16Array(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.UInt16Array(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ));
	}
	
	
	public  java.nio.ShortBuffer aux;
	
	@Override public   int get_bytesPerElement()
	{
		return 2;
	}
	
	
	public   int Get(int p_index)
	{
		return ((int) (this.aux.get(((int) (p_index) ))) );
	}
	
	
	public   void Set(int p_index, int p_value)
	{
		this.aux.put(((int) (p_index) ), ((short) (p_value) ));
	}
	
	
	public   void SetRange(haxe.root.Array<java.lang.Object> p_data, java.lang.Object p_offset)
	{
		int __temp_p_offset33838 = ( (( p_offset == null )) ? (((int) (0) )) : (((int) (haxe.lang.Runtime.toInt(p_offset)) )) );
		int _g1 = 0;
		int _g = p_data.length;
		while (( _g1 < _g ))
		{
			int i = _g1++;
			this.Set(( i + __temp_p_offset33838 ), ((int) (haxe.lang.Runtime.toInt(p_data.__get(i))) ));
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef34051 = true;
			switch (field.hashCode())
			{
				case 96964:
				{
					if (field.equals("aux")) 
					{
						__temp_executeDef34051 = false;
						this.aux = ((java.nio.ShortBuffer) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef34051) 
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
			boolean __temp_executeDef34052 = true;
			switch (field.hashCode())
			{
				case 1467637275:
				{
					if (field.equals("SetRange")) 
					{
						__temp_executeDef34052 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetRange"))) );
					}
					
					break;
				}
				
				
				case 96964:
				{
					if (field.equals("aux")) 
					{
						__temp_executeDef34052 = false;
						return this.aux;
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef34052 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case -829503743:
				{
					if (field.equals("get_bytesPerElement")) 
					{
						__temp_executeDef34052 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_bytesPerElement"))) );
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef34052 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Get"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef34052) 
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
			boolean __temp_executeDef34053 = true;
			switch (field.hashCode())
			{
				case -829503743:
				{
					if (field.equals("get_bytesPerElement")) 
					{
						__temp_executeDef34053 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef34053 = false;
						return this.Get(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1467637275:
				{
					if (field.equals("SetRange")) 
					{
						__temp_executeDef34053 = false;
						this.SetRange(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef34053 = false;
						this.Set(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef34053) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("aux");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


