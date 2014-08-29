package haxe.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Output extends haxe.lang.HxObject
{
	static 
	{
		haxe.io.Output.LN2 = java.lang.Math.log(((double) (2) ));
	}
	public    Output(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Output()
	{
		haxe.io.Output.__hx_ctor_haxe_io_Output(this);
	}
	
	
	public static   void __hx_ctor_haxe_io_Output(haxe.io.Output __temp_me80561)
	{
		{
		}
		
	}
	
	
	public static  double LN2;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.io.Output(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.io.Output();
	}
	
	
	public  boolean bigEndian;
	
	public  java.nio.ByteBuffer helper;
	
	public   void writeByte(int c)
	{
		throw haxe.lang.HaxeException.wrap("Not implemented");
	}
	
	
	public   int writeBytes(haxe.io.Bytes s, int pos, int len)
	{
		int k = len;
		byte[] b = s.b;
		if (( ( ( pos < 0 ) || ( len < 0 ) ) || ( ( pos + len ) > s.length ) )) 
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.OutsideBounds);
		}
		
		while (( k > 0 ))
		{
			this.writeByte(((int) (b[pos]) ));
			pos++;
			k--;
		}
		
		return len;
	}
	
	
	public   void flush()
	{
		{
		}
		
	}
	
	
	public   void close()
	{
		{
		}
		
	}
	
	
	public   boolean set_bigEndian(boolean b)
	{
		this.bigEndian = b;
		return b;
	}
	
	
	public   void write(haxe.io.Bytes s)
	{
		int l = s.length;
		int p = 0;
		while (( l > 0 ))
		{
			int k = this.writeBytes(s, p, l);
			if (( k == 0 )) 
			{
				throw haxe.lang.HaxeException.wrap(haxe.io.Error.Blocked);
			}
			
			p += k;
			l -= k;
		}
		
	}
	
	
	public   void writeFullBytes(haxe.io.Bytes s, int pos, int len)
	{
		while (( len > 0 ))
		{
			int k = this.writeBytes(s, pos, len);
			pos += k;
			len -= k;
		}
		
	}
	
	
	public   void writeFloat(double x)
	{
		if (( this.helper == null )) 
		{
			this.helper = java.nio.ByteBuffer.allocateDirect(((int) (8) ));
		}
		
		java.nio.ByteBuffer helper = this.helper;
		helper.order(((java.nio.ByteOrder) (( (this.bigEndian) ? (java.nio.ByteOrder.BIG_ENDIAN) : (java.nio.ByteOrder.LITTLE_ENDIAN) )) ));
		helper.putFloat(((int) (0) ), ((float) (x) ));
		this.writeByte(((int) (helper.get(((int) (0) ))) ));
		this.writeByte(((int) (helper.get(((int) (1) ))) ));
		this.writeByte(((int) (helper.get(((int) (2) ))) ));
		this.writeByte(((int) (helper.get(((int) (3) ))) ));
	}
	
	
	public   void writeDouble(double x)
	{
		if (( this.helper == null )) 
		{
			this.helper = java.nio.ByteBuffer.allocateDirect(((int) (8) ));
		}
		
		java.nio.ByteBuffer helper = this.helper;
		helper.order(((java.nio.ByteOrder) (( (this.bigEndian) ? (java.nio.ByteOrder.BIG_ENDIAN) : (java.nio.ByteOrder.LITTLE_ENDIAN) )) ));
		helper.putDouble(((int) (0) ), ((double) (x) ));
		this.writeByte(((int) (helper.get(((int) (0) ))) ));
		this.writeByte(((int) (helper.get(((int) (1) ))) ));
		this.writeByte(((int) (helper.get(((int) (2) ))) ));
		this.writeByte(((int) (helper.get(((int) (3) ))) ));
		this.writeByte(((int) (helper.get(((int) (4) ))) ));
		this.writeByte(((int) (helper.get(((int) (5) ))) ));
		this.writeByte(((int) (helper.get(((int) (6) ))) ));
		this.writeByte(((int) (helper.get(((int) (7) ))) ));
	}
	
	
	public   void writeInt8(int x)
	{
		if (( ( x < -128 ) || ( x >= 128 ) )) 
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.Overflow);
		}
		
		this.writeByte(( x & 255 ));
	}
	
	
	public   void writeInt16(int x)
	{
		if (( ( x < -32768 ) || ( x >= 32768 ) )) 
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.Overflow);
		}
		
		this.writeUInt16(( x & 65535 ));
	}
	
	
	public   void writeUInt16(int x)
	{
		if (( ( x < 0 ) || ( x >= 65536 ) )) 
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.Overflow);
		}
		
		if (this.bigEndian) 
		{
			this.writeByte(( x >> 8 ));
			this.writeByte(( x & 255 ));
		}
		 else 
		{
			this.writeByte(( x & 255 ));
			this.writeByte(( x >> 8 ));
		}
		
	}
	
	
	public   void writeInt24(int x)
	{
		if (( ( x < -8388608 ) || ( x >= 8388608 ) )) 
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.Overflow);
		}
		
		this.writeUInt24(( x & 16777215 ));
	}
	
	
	public   void writeUInt24(int x)
	{
		if (( ( x < 0 ) || ( x >= 16777216 ) )) 
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.Overflow);
		}
		
		if (this.bigEndian) 
		{
			this.writeByte(( x >> 16 ));
			this.writeByte(( ( x >> 8 ) & 255 ));
			this.writeByte(( x & 255 ));
		}
		 else 
		{
			this.writeByte(( x & 255 ));
			this.writeByte(( ( x >> 8 ) & 255 ));
			this.writeByte(( x >> 16 ));
		}
		
	}
	
	
	public   void writeInt32(int x)
	{
		if (this.bigEndian) 
		{
			this.writeByte(( x >>> 24 ));
			this.writeByte(( ( x >> 16 ) & 255 ));
			this.writeByte(( ( x >> 8 ) & 255 ));
			this.writeByte(( x & 255 ));
		}
		 else 
		{
			this.writeByte(( x & 255 ));
			this.writeByte(( ( x >> 8 ) & 255 ));
			this.writeByte(( ( x >> 16 ) & 255 ));
			this.writeByte(( x >>> 24 ));
		}
		
	}
	
	
	public   void prepare(int nbytes)
	{
		{
		}
		
	}
	
	
	public   void writeInput(haxe.io.Input i, java.lang.Object bufsize)
	{
		if (( bufsize == null )) 
		{
			bufsize = 4096;
		}
		
		haxe.io.Bytes buf = haxe.io.Bytes.alloc(((int) (haxe.lang.Runtime.toInt(bufsize)) ));
		try 
		{
			while (true)
			{
				int len = i.readBytes(buf, 0, ((int) (haxe.lang.Runtime.toInt(bufsize)) ));
				if (( len == 0 )) 
				{
					throw haxe.lang.HaxeException.wrap(haxe.io.Error.Blocked);
				}
				
				int p = 0;
				while (( len > 0 ))
				{
					int k = this.writeBytes(buf, p, len);
					if (( k == 0 )) 
					{
						throw haxe.lang.HaxeException.wrap(haxe.io.Error.Blocked);
					}
					
					p += k;
					len -= k;
				}
				
			}
			
		}
		catch (java.lang.Throwable __temp_catchallException81127)
		{
			java.lang.Object __temp_catchall81128 = __temp_catchallException81127;
			if (( __temp_catchall81128 instanceof haxe.lang.HaxeException )) 
			{
				__temp_catchall81128 = ((haxe.lang.HaxeException) (__temp_catchallException81127) ).obj;
			}
			
			if (( __temp_catchall81128 instanceof haxe.io.Eof )) 
			{
				haxe.io.Eof e = ((haxe.io.Eof) (__temp_catchall81128) );
				{
					{
					}
					
				}
				
			}
			 else 
			{
				throw haxe.lang.HaxeException.wrap(__temp_catchallException81127);
			}
			
		}
		
		
	}
	
	
	public   void writeString(java.lang.String s)
	{
		haxe.io.Bytes b = haxe.io.Bytes.ofString(s);
		this.writeFullBytes(b, 0, b.length);
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef81129 = true;
			switch (field.hashCode())
			{
				case -1220931666:
				{
					if (field.equals("helper")) 
					{
						__temp_executeDef81129 = false;
						this.helper = ((java.nio.ByteBuffer) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 573260987:
				{
					if (field.equals("bigEndian")) 
					{
						__temp_executeDef81129 = false;
						if (handleProperties) 
						{
							this.set_bigEndian(haxe.lang.Runtime.toBool(value));
							return value;
						}
						 else 
						{
							this.bigEndian = haxe.lang.Runtime.toBool(value);
							return value;
						}
						
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81129) 
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
			boolean __temp_executeDef81130 = true;
			switch (field.hashCode())
			{
				case 1412235472:
				{
					if (field.equals("writeString")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeString"))) );
					}
					
					break;
				}
				
				
				case 573260987:
				{
					if (field.equals("bigEndian")) 
					{
						__temp_executeDef81130 = false;
						return this.bigEndian;
					}
					
					break;
				}
				
				
				case -656596181:
				{
					if (field.equals("writeInput")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeInput"))) );
					}
					
					break;
				}
				
				
				case -1220931666:
				{
					if (field.equals("helper")) 
					{
						__temp_executeDef81130 = false;
						return this.helper;
					}
					
					break;
				}
				
				
				case -318370553:
				{
					if (field.equals("prepare")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("prepare"))) );
					}
					
					break;
				}
				
				
				case -1406851705:
				{
					if (field.equals("writeByte")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeByte"))) );
					}
					
					break;
				}
				
				
				case -656594449:
				{
					if (field.equals("writeInt32")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeInt32"))) );
					}
					
					break;
				}
				
				
				case -662729780:
				{
					if (field.equals("writeBytes")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeBytes"))) );
					}
					
					break;
				}
				
				
				case 1429671867:
				{
					if (field.equals("writeUInt24")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeUInt24"))) );
					}
					
					break;
				}
				
				
				case 97532676:
				{
					if (field.equals("flush")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("flush"))) );
					}
					
					break;
				}
				
				
				case -656594478:
				{
					if (field.equals("writeInt24")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeInt24"))) );
					}
					
					break;
				}
				
				
				case 94756344:
				{
					if (field.equals("close")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("close"))) );
					}
					
					break;
				}
				
				
				case 1429671838:
				{
					if (field.equals("writeUInt16")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeUInt16"))) );
					}
					
					break;
				}
				
				
				case 1862232350:
				{
					if (field.equals("set_bigEndian")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_bigEndian"))) );
					}
					
					break;
				}
				
				
				case -656594507:
				{
					if (field.equals("writeInt16")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeInt16"))) );
					}
					
					break;
				}
				
				
				case 113399775:
				{
					if (field.equals("write")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("write"))) );
					}
					
					break;
				}
				
				
				case -1406653784:
				{
					if (field.equals("writeInt8")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeInt8"))) );
					}
					
					break;
				}
				
				
				case 1188045309:
				{
					if (field.equals("writeFullBytes")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeFullBytes"))) );
					}
					
					break;
				}
				
				
				case 978263184:
				{
					if (field.equals("writeDouble")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeDouble"))) );
					}
					
					break;
				}
				
				
				case -659427907:
				{
					if (field.equals("writeFloat")) 
					{
						__temp_executeDef81130 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeFloat"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81130) 
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
			boolean __temp_executeDef81131 = true;
			switch (field.hashCode())
			{
				case 1412235472:
				{
					if (field.equals("writeString")) 
					{
						__temp_executeDef81131 = false;
						this.writeString(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1406851705:
				{
					if (field.equals("writeByte")) 
					{
						__temp_executeDef81131 = false;
						this.writeByte(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -656596181:
				{
					if (field.equals("writeInput")) 
					{
						__temp_executeDef81131 = false;
						this.writeInput(((haxe.io.Input) (dynargs.__get(0)) ), dynargs.__get(1));
					}
					
					break;
				}
				
				
				case -662729780:
				{
					if (field.equals("writeBytes")) 
					{
						__temp_executeDef81131 = false;
						return this.writeBytes(((haxe.io.Bytes) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case -318370553:
				{
					if (field.equals("prepare")) 
					{
						__temp_executeDef81131 = false;
						this.prepare(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 97532676:
				{
					if (field.equals("flush")) 
					{
						__temp_executeDef81131 = false;
						this.flush();
					}
					
					break;
				}
				
				
				case -656594449:
				{
					if (field.equals("writeInt32")) 
					{
						__temp_executeDef81131 = false;
						this.writeInt32(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 94756344:
				{
					if (field.equals("close")) 
					{
						__temp_executeDef81131 = false;
						this.close();
					}
					
					break;
				}
				
				
				case 1429671867:
				{
					if (field.equals("writeUInt24")) 
					{
						__temp_executeDef81131 = false;
						this.writeUInt24(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1862232350:
				{
					if (field.equals("set_bigEndian")) 
					{
						__temp_executeDef81131 = false;
						return this.set_bigEndian(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -656594478:
				{
					if (field.equals("writeInt24")) 
					{
						__temp_executeDef81131 = false;
						this.writeInt24(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 113399775:
				{
					if (field.equals("write")) 
					{
						__temp_executeDef81131 = false;
						this.write(((haxe.io.Bytes) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 1429671838:
				{
					if (field.equals("writeUInt16")) 
					{
						__temp_executeDef81131 = false;
						this.writeUInt16(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1188045309:
				{
					if (field.equals("writeFullBytes")) 
					{
						__temp_executeDef81131 = false;
						this.writeFullBytes(((haxe.io.Bytes) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case -656594507:
				{
					if (field.equals("writeInt16")) 
					{
						__temp_executeDef81131 = false;
						this.writeInt16(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -659427907:
				{
					if (field.equals("writeFloat")) 
					{
						__temp_executeDef81131 = false;
						this.writeFloat(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1406653784:
				{
					if (field.equals("writeInt8")) 
					{
						__temp_executeDef81131 = false;
						this.writeInt8(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 978263184:
				{
					if (field.equals("writeDouble")) 
					{
						__temp_executeDef81131 = false;
						this.writeDouble(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81131) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("helper");
		baseArr.push("bigEndian");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


