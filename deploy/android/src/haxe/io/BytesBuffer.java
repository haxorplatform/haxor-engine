package haxe.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class BytesBuffer extends haxe.lang.HxObject
{
	public    BytesBuffer(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    BytesBuffer()
	{
		haxe.io.BytesBuffer.__hx_ctor_haxe_io_BytesBuffer(this);
	}
	
	
	public static   void __hx_ctor_haxe_io_BytesBuffer(haxe.io.BytesBuffer __temp_me80558)
	{
		__temp_me80558.b = new java.io.ByteArrayOutputStream();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.io.BytesBuffer(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.io.BytesBuffer();
	}
	
	
	public  java.io.ByteArrayOutputStream b;
	
	
	
	public final   int get_length()
	{
		return this.b.size();
	}
	
	
	public final   void addByte(int _byte)
	{
		this.b.write(((int) (_byte) ));
	}
	
	
	public final   void add(haxe.io.Bytes src)
	{
		this.b.write(((byte[]) (src.b) ), ((int) (0) ), ((int) (src.length) ));
	}
	
	
	public final   void addString(java.lang.String v)
	{
		haxe.io.Bytes src = haxe.io.Bytes.ofString(v);
		this.b.write(((byte[]) (src.b) ), ((int) (0) ), ((int) (src.length) ));
	}
	
	
	public final   void addFloat(double v)
	{
		haxe.io.BytesOutput b = new haxe.io.BytesOutput();
		b.writeFloat(v);
		{
			haxe.io.Bytes src = b.getBytes();
			this.b.write(((byte[]) (src.b) ), ((int) (0) ), ((int) (src.length) ));
		}
		
	}
	
	
	public final   void addDouble(double v)
	{
		haxe.io.BytesOutput b = new haxe.io.BytesOutput();
		b.writeDouble(v);
		{
			haxe.io.Bytes src = b.getBytes();
			this.b.write(((byte[]) (src.b) ), ((int) (0) ), ((int) (src.length) ));
		}
		
	}
	
	
	public final   void addBytes(haxe.io.Bytes src, int pos, int len)
	{
		if (( ( ( pos < 0 ) || ( len < 0 ) ) || ( ( pos + len ) > src.length ) )) 
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.OutsideBounds);
		}
		
		this.b.write(((byte[]) (src.b) ), ((int) (pos) ), ((int) (len) ));
	}
	
	
	public   haxe.io.Bytes getBytes()
	{
		byte[] buf = this.b.toByteArray();
		haxe.io.Bytes bytes = new haxe.io.Bytes(((int) (buf.length) ), ((byte[]) (buf) ));
		this.b = null;
		return bytes;
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef81110 = true;
			switch (field.hashCode())
			{
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef81110 = false;
						this.b = ((java.io.ByteArrayOutputStream) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81110) 
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
			boolean __temp_executeDef81111 = true;
			switch (field.hashCode())
			{
				case 1950049973:
				{
					if (field.equals("getBytes")) 
					{
						__temp_executeDef81111 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getBytes"))) );
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef81111 = false;
						return this.b;
					}
					
					break;
				}
				
				
				case -1262447542:
				{
					if (field.equals("addBytes")) 
					{
						__temp_executeDef81111 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("addBytes"))) );
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef81111 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case -433118254:
				{
					if (field.equals("addDouble")) 
					{
						__temp_executeDef81111 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("addDouble"))) );
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef81111 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
				case -1259145669:
				{
					if (field.equals("addFloat")) 
					{
						__temp_executeDef81111 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("addFloat"))) );
					}
					
					break;
				}
				
				
				case -1149102775:
				{
					if (field.equals("addByte")) 
					{
						__temp_executeDef81111 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("addByte"))) );
					}
					
					break;
				}
				
				
				case 854034:
				{
					if (field.equals("addString")) 
					{
						__temp_executeDef81111 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("addString"))) );
					}
					
					break;
				}
				
				
				case 96417:
				{
					if (field.equals("add")) 
					{
						__temp_executeDef81111 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("add"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81111) 
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
			boolean __temp_executeDef81112 = true;
			switch (field.hashCode())
			{
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef81112 = false;
						return ((double) (this.get_length()) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81112) 
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
			boolean __temp_executeDef81113 = true;
			switch (field.hashCode())
			{
				case 1950049973:
				{
					if (field.equals("getBytes")) 
					{
						__temp_executeDef81113 = false;
						return this.getBytes();
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef81113 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
				case -1262447542:
				{
					if (field.equals("addBytes")) 
					{
						__temp_executeDef81113 = false;
						this.addBytes(((haxe.io.Bytes) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case -1149102775:
				{
					if (field.equals("addByte")) 
					{
						__temp_executeDef81113 = false;
						this.addByte(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -433118254:
				{
					if (field.equals("addDouble")) 
					{
						__temp_executeDef81113 = false;
						this.addDouble(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 96417:
				{
					if (field.equals("add")) 
					{
						__temp_executeDef81113 = false;
						this.add(((haxe.io.Bytes) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1259145669:
				{
					if (field.equals("addFloat")) 
					{
						__temp_executeDef81113 = false;
						this.addFloat(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 854034:
				{
					if (field.equals("addString")) 
					{
						__temp_executeDef81113 = false;
						this.addString(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81113) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("length");
		baseArr.push("b");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


