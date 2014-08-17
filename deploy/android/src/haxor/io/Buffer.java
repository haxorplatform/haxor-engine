package haxor.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Buffer extends haxe.lang.HxObject
{
	public    Buffer(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Buffer(int p_length)
	{
		haxor.io.Buffer.__hx_ctor_haxor_io_Buffer(this, p_length);
	}
	
	
	public static   void __hx_ctor_haxor_io_Buffer(haxor.io.Buffer __temp_me27910, int p_length)
	{
		__temp_me27910.m_length = p_length;
		int len = ( __temp_me27910.m_length * __temp_me27910.get_bytesPerElement() );
		__temp_me27910.m_buffer = java.nio.ByteBuffer.allocateDirect(((int) (len) )).order(((java.nio.ByteOrder) (java.nio.ByteOrder.nativeOrder()) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.Buffer(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.Buffer(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ));
	}
	
	
	public  java.nio.ByteBuffer buffer;
	
	public final   java.nio.ByteBuffer get_buffer()
	{
		return this.m_buffer;
	}
	
	
	public  java.nio.ByteBuffer m_buffer;
	
	public  int byteLength;
	
	public final   int get_byteLength()
	{
		return ( this.m_length * this.get_bytesPerElement() );
	}
	
	
	public  int bytesPerElement;
	
	public   int get_bytesPerElement()
	{
		return 1;
	}
	
	
	public  int length;
	
	public final   int get_length()
	{
		return this.m_length;
	}
	
	
	public  int m_length;
	
	public   int GetByte(int p_index)
	{
		return ((int) (this.m_buffer.get(((int) (p_index) ))) );
	}
	
	
	public   void SetByte(int p_index, int p_value)
	{
		this.m_buffer.put(((int) (p_index) ), ((byte) (p_value) ));
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef28095 = true;
			switch (field.hashCode())
			{
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef28095 = false;
						this.m_length = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 281453070:
				{
					if (field.equals("byteLength")) 
					{
						__temp_executeDef28095 = false;
						this.byteLength = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef28095 = false;
						this.length = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1062817258:
				{
					if (field.equals("bytesPerElement")) 
					{
						__temp_executeDef28095 = false;
						this.bytesPerElement = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28095) 
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
			boolean __temp_executeDef28096 = true;
			switch (field.hashCode())
			{
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef28096 = false;
						this.m_length = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1378118592:
				{
					if (field.equals("buffer")) 
					{
						__temp_executeDef28096 = false;
						this.buffer = ((java.nio.ByteBuffer) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef28096 = false;
						this.length = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1976849326:
				{
					if (field.equals("m_buffer")) 
					{
						__temp_executeDef28096 = false;
						this.m_buffer = ((java.nio.ByteBuffer) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 1062817258:
				{
					if (field.equals("bytesPerElement")) 
					{
						__temp_executeDef28096 = false;
						this.bytesPerElement = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 281453070:
				{
					if (field.equals("byteLength")) 
					{
						__temp_executeDef28096 = false;
						this.byteLength = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28096) 
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
			boolean __temp_executeDef28097 = true;
			switch (field.hashCode())
			{
				case -645846934:
				{
					if (field.equals("SetByte")) 
					{
						__temp_executeDef28097 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("SetByte"))) );
					}
					
					break;
				}
				
				
				case -1378118592:
				{
					if (field.equals("buffer")) 
					{
						__temp_executeDef28097 = false;
						if (handleProperties) 
						{
							return this.get_buffer();
						}
						 else 
						{
							return this.buffer;
						}
						
					}
					
					break;
				}
				
				
				case 1589010782:
				{
					if (field.equals("GetByte")) 
					{
						__temp_executeDef28097 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("GetByte"))) );
					}
					
					break;
				}
				
				
				case 702559561:
				{
					if (field.equals("get_buffer")) 
					{
						__temp_executeDef28097 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_buffer"))) );
					}
					
					break;
				}
				
				
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef28097 = false;
						return this.m_length;
					}
					
					break;
				}
				
				
				case -1976849326:
				{
					if (field.equals("m_buffer")) 
					{
						__temp_executeDef28097 = false;
						return this.m_buffer;
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef28097 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
				case 281453070:
				{
					if (field.equals("byteLength")) 
					{
						__temp_executeDef28097 = false;
						if (handleProperties) 
						{
							return this.get_byteLength();
						}
						 else 
						{
							return this.byteLength;
						}
						
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef28097 = false;
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
				
				
				case -938371433:
				{
					if (field.equals("get_byteLength")) 
					{
						__temp_executeDef28097 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_byteLength"))) );
					}
					
					break;
				}
				
				
				case -829503743:
				{
					if (field.equals("get_bytesPerElement")) 
					{
						__temp_executeDef28097 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_bytesPerElement"))) );
					}
					
					break;
				}
				
				
				case 1062817258:
				{
					if (field.equals("bytesPerElement")) 
					{
						__temp_executeDef28097 = false;
						if (handleProperties) 
						{
							return this.get_bytesPerElement();
						}
						 else 
						{
							return this.bytesPerElement;
						}
						
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28097) 
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
			boolean __temp_executeDef28098 = true;
			switch (field.hashCode())
			{
				case -1705094408:
				{
					if (field.equals("m_length")) 
					{
						__temp_executeDef28098 = false;
						return ((double) (this.m_length) );
					}
					
					break;
				}
				
				
				case 281453070:
				{
					if (field.equals("byteLength")) 
					{
						__temp_executeDef28098 = false;
						if (handleProperties) 
						{
							return ((double) (this.get_byteLength()) );
						}
						 else 
						{
							return ((double) (this.byteLength) );
						}
						
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef28098 = false;
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
				
				
				case 1062817258:
				{
					if (field.equals("bytesPerElement")) 
					{
						__temp_executeDef28098 = false;
						if (handleProperties) 
						{
							return ((double) (this.get_bytesPerElement()) );
						}
						 else 
						{
							return ((double) (this.bytesPerElement) );
						}
						
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28098) 
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
			boolean __temp_executeDef28099 = true;
			switch (field.hashCode())
			{
				case -645846934:
				{
					if (field.equals("SetByte")) 
					{
						__temp_executeDef28099 = false;
						this.SetByte(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 702559561:
				{
					if (field.equals("get_buffer")) 
					{
						__temp_executeDef28099 = false;
						return this.get_buffer();
					}
					
					break;
				}
				
				
				case 1589010782:
				{
					if (field.equals("GetByte")) 
					{
						__temp_executeDef28099 = false;
						return this.GetByte(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -938371433:
				{
					if (field.equals("get_byteLength")) 
					{
						__temp_executeDef28099 = false;
						return this.get_byteLength();
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef28099 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case -829503743:
				{
					if (field.equals("get_bytesPerElement")) 
					{
						__temp_executeDef28099 = false;
						return this.get_bytesPerElement();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28099) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_length");
		baseArr.push("length");
		baseArr.push("bytesPerElement");
		baseArr.push("byteLength");
		baseArr.push("m_buffer");
		baseArr.push("buffer");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


