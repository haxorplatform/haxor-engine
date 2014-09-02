package haxe.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Input extends haxe.lang.HxObject
{
	public    Input(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Input()
	{
		haxe.io.Input.__hx_ctor_haxe_io_Input(this);
	}
	
	
	public static   void __hx_ctor_haxe_io_Input(haxe.io.Input __temp_me160405)
	{
		{
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.io.Input(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.io.Input();
	}
	
	
	public  boolean bigEndian;
	
	public  java.nio.ByteBuffer helper;
	
	public   int readByte()
	{
		throw haxe.lang.HaxeException.wrap("Not implemented");
	}
	
	
	public   int readBytes(haxe.io.Bytes s, int pos, int len)
	{
		int k = len;
		byte[] b = s.b;
		if (( ( ( pos < 0 ) || ( len < 0 ) ) || ( ( pos + len ) > s.length ) )) 
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.OutsideBounds);
		}
		
		while (( k > 0 ))
		{
			b[pos] = ((byte) (this.readByte()) );
			pos++;
			k--;
		}
		
		return len;
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
	
	
	public   haxe.io.Bytes readAll(java.lang.Object bufsize)
	{
		if (( bufsize == null )) 
		{
			bufsize = 16384;
		}
		
		haxe.io.Bytes buf = haxe.io.Bytes.alloc(((int) (haxe.lang.Runtime.toInt(bufsize)) ));
		haxe.io.BytesBuffer total = new haxe.io.BytesBuffer();
		try 
		{
			while (true)
			{
				int len = this.readBytes(buf, 0, ((int) (haxe.lang.Runtime.toInt(bufsize)) ));
				if (( len == 0 )) 
				{
					throw haxe.lang.HaxeException.wrap(haxe.io.Error.Blocked);
				}
				
				{
					if (( ( len < 0 ) || ( len > buf.length ) )) 
					{
						throw haxe.lang.HaxeException.wrap(haxe.io.Error.OutsideBounds);
					}
					
					total.b.write(((byte[]) (buf.b) ), ((int) (0) ), ((int) (len) ));
				}
				
			}
			
		}
		catch (java.lang.Throwable __temp_catchallException160980)
		{
			java.lang.Object __temp_catchall160981 = __temp_catchallException160980;
			if (( __temp_catchall160981 instanceof haxe.lang.HaxeException )) 
			{
				__temp_catchall160981 = ((haxe.lang.HaxeException) (__temp_catchallException160980) ).obj;
			}
			
			if (( __temp_catchall160981 instanceof haxe.io.Eof )) 
			{
				haxe.io.Eof e = ((haxe.io.Eof) (__temp_catchall160981) );
				{
					{
					}
					
				}
				
			}
			 else 
			{
				throw haxe.lang.HaxeException.wrap(__temp_catchallException160980);
			}
			
		}
		
		
		return total.getBytes();
	}
	
	
	public   void readFullBytes(haxe.io.Bytes s, int pos, int len)
	{
		while (( len > 0 ))
		{
			int k = this.readBytes(s, pos, len);
			pos += k;
			len -= k;
		}
		
	}
	
	
	public   haxe.io.Bytes read(int nbytes)
	{
		haxe.io.Bytes s = haxe.io.Bytes.alloc(nbytes);
		int p = 0;
		while (( nbytes > 0 ))
		{
			int k = this.readBytes(s, p, nbytes);
			if (( k == 0 )) 
			{
				throw haxe.lang.HaxeException.wrap(haxe.io.Error.Blocked);
			}
			
			p += k;
			nbytes -= k;
		}
		
		return s;
	}
	
	
	public   java.lang.String readUntil(int end)
	{
		haxe.root.StringBuf buf = new haxe.root.StringBuf();
		int last = 0;
		while (( (last = this.readByte()) != end ))
		{
			buf.addChar(last);
		}
		
		return buf.toString();
	}
	
	
	public   java.lang.String readLine()
	{
		haxe.root.StringBuf buf = new haxe.root.StringBuf();
		int last = 0;
		java.lang.String s = null;
		try 
		{
			while (( (last = this.readByte()) != 10 ))
			{
				buf.addChar(last);
			}
			
			s = buf.toString();
			if (haxe.lang.Runtime.eq(haxe.lang.StringExt.charCodeAt(s, ( s.length() - 1 )), 13)) 
			{
				s = haxe.lang.StringExt.substr(s, 0, -1);
			}
			
		}
		catch (java.lang.Throwable __temp_catchallException160982)
		{
			java.lang.Object __temp_catchall160983 = __temp_catchallException160982;
			if (( __temp_catchall160983 instanceof haxe.lang.HaxeException )) 
			{
				__temp_catchall160983 = ((haxe.lang.HaxeException) (__temp_catchallException160982) ).obj;
			}
			
			if (( __temp_catchall160983 instanceof haxe.io.Eof )) 
			{
				haxe.io.Eof e = ((haxe.io.Eof) (__temp_catchall160983) );
				{
					s = buf.toString();
					if (( s.length() == 0 )) 
					{
						throw haxe.lang.HaxeException.wrap(e);
					}
					
				}
				
			}
			 else 
			{
				throw haxe.lang.HaxeException.wrap(__temp_catchallException160982);
			}
			
		}
		
		
		return s;
	}
	
	
	public   double readFloat()
	{
		if (( this.helper == null )) 
		{
			this.helper = java.nio.ByteBuffer.allocateDirect(((int) (8) ));
		}
		
		java.nio.ByteBuffer helper = this.helper;
		helper.order(((java.nio.ByteOrder) (( (this.bigEndian) ? (java.nio.ByteOrder.BIG_ENDIAN) : (java.nio.ByteOrder.LITTLE_ENDIAN) )) ));
		helper.put(((int) (0) ), ((byte) (this.readByte()) ));
		helper.put(((int) (1) ), ((byte) (this.readByte()) ));
		helper.put(((int) (2) ), ((byte) (this.readByte()) ));
		helper.put(((int) (3) ), ((byte) (this.readByte()) ));
		return ((double) (helper.getFloat(((int) (0) ))) );
	}
	
	
	public   double readDouble()
	{
		if (( this.helper == null )) 
		{
			this.helper = java.nio.ByteBuffer.allocateDirect(((int) (8) ));
		}
		
		java.nio.ByteBuffer helper = this.helper;
		helper.order(((java.nio.ByteOrder) (( (this.bigEndian) ? (java.nio.ByteOrder.BIG_ENDIAN) : (java.nio.ByteOrder.LITTLE_ENDIAN) )) ));
		helper.put(((int) (0) ), ((byte) (this.readByte()) ));
		helper.put(((int) (1) ), ((byte) (this.readByte()) ));
		helper.put(((int) (2) ), ((byte) (this.readByte()) ));
		helper.put(((int) (3) ), ((byte) (this.readByte()) ));
		helper.put(((int) (4) ), ((byte) (this.readByte()) ));
		helper.put(((int) (5) ), ((byte) (this.readByte()) ));
		helper.put(((int) (6) ), ((byte) (this.readByte()) ));
		helper.put(((int) (7) ), ((byte) (this.readByte()) ));
		return helper.getDouble(((int) (0) ));
	}
	
	
	public   int readInt8()
	{
		int n = this.readByte();
		if (( n >= 128 )) 
		{
			return ( n - 256 );
		}
		
		return n;
	}
	
	
	public   int readInt16()
	{
		int ch1 = this.readByte();
		int ch2 = this.readByte();
		int n = 0;
		if (this.bigEndian) 
		{
			n = ( ch2 | ( ch1 << 8 ) );
		}
		 else 
		{
			n = ( ch1 | ( ch2 << 8 ) );
		}
		
		if (( (( n & 32768 )) != 0 )) 
		{
			return ( n - 65536 );
		}
		
		return n;
	}
	
	
	public   int readUInt16()
	{
		int ch1 = this.readByte();
		int ch2 = this.readByte();
		if (this.bigEndian) 
		{
			return ( ch2 | ( ch1 << 8 ) );
		}
		 else 
		{
			return ( ch1 | ( ch2 << 8 ) );
		}
		
	}
	
	
	public   int readInt24()
	{
		int ch1 = this.readByte();
		int ch2 = this.readByte();
		int ch3 = this.readByte();
		int n = 0;
		if (this.bigEndian) 
		{
			n = ( ( ch3 | ( ch2 << 8 ) ) | ( ch1 << 16 ) );
		}
		 else 
		{
			n = ( ( ch1 | ( ch2 << 8 ) ) | ( ch3 << 16 ) );
		}
		
		if (( (( n & 8388608 )) != 0 )) 
		{
			return ( n - 16777216 );
		}
		
		return n;
	}
	
	
	public   int readUInt24()
	{
		int ch1 = this.readByte();
		int ch2 = this.readByte();
		int ch3 = this.readByte();
		if (this.bigEndian) 
		{
			return ( ( ch3 | ( ch2 << 8 ) ) | ( ch1 << 16 ) );
		}
		 else 
		{
			return ( ( ch1 | ( ch2 << 8 ) ) | ( ch3 << 16 ) );
		}
		
	}
	
	
	public   int readInt32()
	{
		int ch1 = this.readByte();
		int ch2 = this.readByte();
		int ch3 = this.readByte();
		int ch4 = this.readByte();
		if (this.bigEndian) 
		{
			return ( ( ( ch4 | ( ch3 << 8 ) ) | ( ch2 << 16 ) ) | ( ch1 << 24 ) );
		}
		 else 
		{
			return ( ( ( ch1 | ( ch2 << 8 ) ) | ( ch3 << 16 ) ) | ( ch4 << 24 ) );
		}
		
	}
	
	
	public   java.lang.String readString(int len)
	{
		haxe.io.Bytes b = haxe.io.Bytes.alloc(len);
		this.readFullBytes(b, 0, len);
		return b.toString();
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef160984 = true;
			switch (field.hashCode())
			{
				case -1220931666:
				{
					if (field.equals("helper")) 
					{
						__temp_executeDef160984 = false;
						this.helper = ((java.nio.ByteBuffer) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 573260987:
				{
					if (field.equals("bigEndian")) 
					{
						__temp_executeDef160984 = false;
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
			
			if (__temp_executeDef160984) 
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
			boolean __temp_executeDef160985 = true;
			switch (field.hashCode())
			{
				case -500196025:
				{
					if (field.equals("readString")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readString"))) );
					}
					
					break;
				}
				
				
				case 573260987:
				{
					if (field.equals("bigEndian")) 
					{
						__temp_executeDef160985 = false;
						return this.bigEndian;
					}
					
					break;
				}
				
				
				case -1133927784:
				{
					if (field.equals("readInt32")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readInt32"))) );
					}
					
					break;
				}
				
				
				case -1220931666:
				{
					if (field.equals("helper")) 
					{
						__temp_executeDef160985 = false;
						return this.helper;
					}
					
					break;
				}
				
				
				case -482759630:
				{
					if (field.equals("readUInt24")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readUInt24"))) );
					}
					
					break;
				}
				
				
				case -868060226:
				{
					if (field.equals("readByte")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readByte"))) );
					}
					
					break;
				}
				
				
				case -1133927813:
				{
					if (field.equals("readInt24")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readInt24"))) );
					}
					
					break;
				}
				
				
				case -1140063115:
				{
					if (field.equals("readBytes")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readBytes"))) );
					}
					
					break;
				}
				
				
				case -482759659:
				{
					if (field.equals("readUInt16")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readUInt16"))) );
					}
					
					break;
				}
				
				
				case 94756344:
				{
					if (field.equals("close")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("close"))) );
					}
					
					break;
				}
				
				
				case -1133927842:
				{
					if (field.equals("readInt16")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readInt16"))) );
					}
					
					break;
				}
				
				
				case 1862232350:
				{
					if (field.equals("set_bigEndian")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_bigEndian"))) );
					}
					
					break;
				}
				
				
				case -867862305:
				{
					if (field.equals("readInt8")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readInt8"))) );
					}
					
					break;
				}
				
				
				case 1080375339:
				{
					if (field.equals("readAll")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readAll"))) );
					}
					
					break;
				}
				
				
				case -934168313:
				{
					if (field.equals("readDouble")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readDouble"))) );
					}
					
					break;
				}
				
				
				case 682499622:
				{
					if (field.equals("readFullBytes")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readFullBytes"))) );
					}
					
					break;
				}
				
				
				case -1136761242:
				{
					if (field.equals("readFloat")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readFloat"))) );
					}
					
					break;
				}
				
				
				case 3496342:
				{
					if (field.equals("read")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("read"))) );
					}
					
					break;
				}
				
				
				case -867777878:
				{
					if (field.equals("readLine")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readLine"))) );
					}
					
					break;
				}
				
				
				case -1122843800:
				{
					if (field.equals("readUntil")) 
					{
						__temp_executeDef160985 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readUntil"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160985) 
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
			boolean __temp_executeDef160986 = true;
			switch (field.hashCode())
			{
				case -500196025:
				{
					if (field.equals("readString")) 
					{
						__temp_executeDef160986 = false;
						return this.readString(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -868060226:
				{
					if (field.equals("readByte")) 
					{
						__temp_executeDef160986 = false;
						return this.readByte();
					}
					
					break;
				}
				
				
				case -1133927784:
				{
					if (field.equals("readInt32")) 
					{
						__temp_executeDef160986 = false;
						return this.readInt32();
					}
					
					break;
				}
				
				
				case -1140063115:
				{
					if (field.equals("readBytes")) 
					{
						__temp_executeDef160986 = false;
						return this.readBytes(((haxe.io.Bytes) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case -482759630:
				{
					if (field.equals("readUInt24")) 
					{
						__temp_executeDef160986 = false;
						return this.readUInt24();
					}
					
					break;
				}
				
				
				case 94756344:
				{
					if (field.equals("close")) 
					{
						__temp_executeDef160986 = false;
						this.close();
					}
					
					break;
				}
				
				
				case -1133927813:
				{
					if (field.equals("readInt24")) 
					{
						__temp_executeDef160986 = false;
						return this.readInt24();
					}
					
					break;
				}
				
				
				case 1862232350:
				{
					if (field.equals("set_bigEndian")) 
					{
						__temp_executeDef160986 = false;
						return this.set_bigEndian(haxe.lang.Runtime.toBool(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -482759659:
				{
					if (field.equals("readUInt16")) 
					{
						__temp_executeDef160986 = false;
						return this.readUInt16();
					}
					
					break;
				}
				
				
				case 1080375339:
				{
					if (field.equals("readAll")) 
					{
						__temp_executeDef160986 = false;
						return this.readAll(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case -1133927842:
				{
					if (field.equals("readInt16")) 
					{
						__temp_executeDef160986 = false;
						return this.readInt16();
					}
					
					break;
				}
				
				
				case 682499622:
				{
					if (field.equals("readFullBytes")) 
					{
						__temp_executeDef160986 = false;
						this.readFullBytes(((haxe.io.Bytes) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case -867862305:
				{
					if (field.equals("readInt8")) 
					{
						__temp_executeDef160986 = false;
						return this.readInt8();
					}
					
					break;
				}
				
				
				case 3496342:
				{
					if (field.equals("read")) 
					{
						__temp_executeDef160986 = false;
						return this.read(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -934168313:
				{
					if (field.equals("readDouble")) 
					{
						__temp_executeDef160986 = false;
						return this.readDouble();
					}
					
					break;
				}
				
				
				case -1122843800:
				{
					if (field.equals("readUntil")) 
					{
						__temp_executeDef160986 = false;
						return this.readUntil(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case -1136761242:
				{
					if (field.equals("readFloat")) 
					{
						__temp_executeDef160986 = false;
						return this.readFloat();
					}
					
					break;
				}
				
				
				case -867777878:
				{
					if (field.equals("readLine")) 
					{
						__temp_executeDef160986 = false;
						return this.readLine();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160986) 
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


