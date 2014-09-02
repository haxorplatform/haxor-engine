package haxor.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class FloatArray extends haxor.io.Buffer
{
	public    FloatArray(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    FloatArray(int p_length)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		haxor.io.FloatArray.__hx_ctor_haxor_io_FloatArray(this, p_length);
	}
	
	
	public static   void __hx_ctor_haxor_io_FloatArray(haxor.io.FloatArray __temp_me164305, int p_length)
	{
		haxor.io.Buffer.__hx_ctor_haxor_io_Buffer(__temp_me164305, p_length);
	}
	
	
	public static   haxor.io.FloatArray Alloc(haxe.root.Array<java.lang.Object> p_data)
	{
		haxor.io.FloatArray b = new haxor.io.FloatArray(((int) (p_data.length) ));
		b.SetRange(p_data, null);
		return b;
	}
	
	
	public static   haxor.io.FloatArray FromBase64(java.lang.String p_data)
	{
		haxor.io.FloatArray b = new haxor.io.FloatArray(( p_data.length() / 4 ));
		b.SetString(p_data, null);
		b.DecodeBase64();
		return b;
	}
	
	
	public static   haxor.io.FloatArray Parse(java.lang.String p_data, java.lang.String p_delimiter)
	{
		if (( p_delimiter == null )) 
		{
			p_delimiter = " ";
		}
		
		haxe.root.Array<java.lang.String> tk = haxe.lang.StringExt.split(p_data, p_delimiter);
		haxor.io.FloatArray res = new haxor.io.FloatArray(((int) (tk.length) ));
		{
			int _g1 = 0;
			int _g = tk.length;
			while (( _g1 < _g ))
			{
				int i = _g1++;
				res.Set(i, haxe.root.Std.parseFloat(tk.__get(i).trim()));
			}
			
		}
		
		return res;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.FloatArray(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.FloatArray(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ));
	}
	
	
	@Override public   int get_bytesPerElement()
	{
		return 4;
	}
	
	
	public  java.nio.FloatBuffer aux;
	
	@Override public   void Resize(int p_length)
	{
		super.Resize(p_length);
		this.aux = this.m_buffer.asFloatBuffer();
	}
	
	
	public   double Get(int p_index)
	{
		return ((double) (this.aux.get(((int) (p_index) ))) );
	}
	
	
	public   void Set(int p_index, double p_value)
	{
		this.aux.put(((int) (p_index) ), ((float) (p_value) ));
	}
	
	
	public   void SetRange(haxe.root.Array<java.lang.Object> p_data, java.lang.Object p_offset)
	{
		int __temp_p_offset164304 = ( (( p_offset == null )) ? (((int) (0) )) : (((int) (haxe.lang.Runtime.toInt(p_offset)) )) );
		int _g1 = 0;
		int _g = p_data.length;
		while (( _g1 < _g ))
		{
			int i = _g1++;
			this.Set(( i + __temp_p_offset164304 ), ((double) (haxe.lang.Runtime.toDouble(p_data.__get(i))) ));
		}
		
	}
	
	
	@Override public   void SetViewSlice(int p_start, int p_length)
	{
		super.SetViewSlice(p_start, p_length);
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef165035 = true;
			switch (field.hashCode())
			{
				case 96964:
				{
					if (field.equals("aux")) 
					{
						__temp_executeDef165035 = false;
						this.aux = ((java.nio.FloatBuffer) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef165035) 
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
			boolean __temp_executeDef165036 = true;
			switch (field.hashCode())
			{
				case 119371723:
				{
					if (field.equals("SetViewSlice")) 
					{
						__temp_executeDef165036 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetViewSlice"))) );
					}
					
					break;
				}
				
				
				case -829503743:
				{
					if (field.equals("get_bytesPerElement")) 
					{
						__temp_executeDef165036 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_bytesPerElement"))) );
					}
					
					break;
				}
				
				
				case 1467637275:
				{
					if (field.equals("SetRange")) 
					{
						__temp_executeDef165036 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetRange"))) );
					}
					
					break;
				}
				
				
				case 96964:
				{
					if (field.equals("aux")) 
					{
						__temp_executeDef165036 = false;
						return this.aux;
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef165036 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Set"))) );
					}
					
					break;
				}
				
				
				case -1850570540:
				{
					if (field.equals("Resize")) 
					{
						__temp_executeDef165036 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Resize"))) );
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef165036 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Get"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef165036) 
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
			int __temp_hash165038 = field.hashCode();
			boolean __temp_executeDef165037 = true;
			switch (__temp_hash165038)
			{
				case 119371723:case -1850570540:case -829503743:
				{
					if (( (( ( __temp_hash165038 == 119371723 ) && field.equals("SetViewSlice") )) || ( (( ( __temp_hash165038 == -1850570540 ) && field.equals("Resize") )) || field.equals("get_bytesPerElement") ) )) 
					{
						__temp_executeDef165037 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 71478:
				{
					if (field.equals("Get")) 
					{
						__temp_executeDef165037 = false;
						return this.Get(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1467637275:
				{
					if (field.equals("SetRange")) 
					{
						__temp_executeDef165037 = false;
						this.SetRange(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case 83010:
				{
					if (field.equals("Set")) 
					{
						__temp_executeDef165037 = false;
						this.Set(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef165037) 
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


