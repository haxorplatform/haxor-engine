package haxe.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Bytes extends haxe.lang.HxObject
{
	public    Bytes(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Bytes(int length, byte[] b)
	{
		haxe.io.Bytes.__hx_ctor_haxe_io_Bytes(this, length, b);
	}
	
	
	public static   void __hx_ctor_haxe_io_Bytes(haxe.io.Bytes __temp_me80541, int length, byte[] b)
	{
		__temp_me80541.length = length;
		__temp_me80541.b = b;
	}
	
	
	public static   haxe.io.Bytes alloc(int length)
	{
		return new haxe.io.Bytes(((int) (length) ), ((byte[]) (new byte[((int) (length) )]) ));
	}
	
	
	public static   haxe.io.Bytes ofString(java.lang.String s)
	{
		try 
		{
			byte[] b = s.getBytes(haxe.lang.Runtime.toString("UTF-8"));
			return new haxe.io.Bytes(((int) (b.length) ), ((byte[]) (b) ));
		}
		catch (java.lang.Throwable __temp_catchallException80959)
		{
			java.lang.Object __temp_catchall80960 = __temp_catchallException80959;
			if (( __temp_catchall80960 instanceof haxe.lang.HaxeException )) 
			{
				__temp_catchall80960 = ((haxe.lang.HaxeException) (__temp_catchallException80959) ).obj;
			}
			
			{
				java.lang.Object e = __temp_catchall80960;
				throw haxe.lang.HaxeException.wrap(e);
			}
			
		}
		
		
	}
	
	
	public static   haxe.io.Bytes ofData(byte[] b)
	{
		return new haxe.io.Bytes(((int) (b.length) ), ((byte[]) (b) ));
	}
	
	
	public static   int fastGet(byte[] b, int pos)
	{
		return ( b[pos] & 255 );
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.io.Bytes(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.io.Bytes(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ), ((byte[]) (arr.__get(1)) ));
	}
	
	
	public  int length;
	
	public  byte[] b;
	
	public final   int get(int pos)
	{
		return ( this.b[pos] & 255 );
	}
	
	
	public final   void set(int pos, int v)
	{
		this.b[pos] = ((byte) (v) );
	}
	
	
	public   void blit(int pos, haxe.io.Bytes src, int srcpos, int len)
	{
		if (( ( ( ( ( pos < 0 ) || ( srcpos < 0 ) ) || ( len < 0 ) ) || ( ( pos + len ) > this.length ) ) || ( ( srcpos + len ) > src.length ) )) 
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.OutsideBounds);
		}
		
		java.lang.System.arraycopy(((java.lang.Object) (src.b) ), ((int) (srcpos) ), ((java.lang.Object) (this.b) ), ((int) (pos) ), ((int) (len) ));
	}
	
	
	public   void fill(int pos, int len, int value)
	{
		int _g = 0;
		while (( _g < len ))
		{
			int i = _g++;
			int pos1 = pos++;
			this.b[pos1] = ((byte) (value) );
		}
		
	}
	
	
	public   haxe.io.Bytes sub(int pos, int len)
	{
		if (( ( ( pos < 0 ) || ( len < 0 ) ) || ( ( pos + len ) > this.length ) )) 
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.OutsideBounds);
		}
		
		byte[] newarr = new byte[((int) (len) )];
		java.lang.System.arraycopy(((java.lang.Object) (this.b) ), ((int) (pos) ), ((java.lang.Object) (newarr) ), ((int) (0) ), ((int) (len) ));
		return new haxe.io.Bytes(((int) (len) ), ((byte[]) (newarr) ));
	}
	
	
	public   int compare(haxe.io.Bytes other)
	{
		byte[] b1 = this.b;
		byte[] b2 = other.b;
		int len = 0;
		if (( this.length < other.length )) 
		{
			len = this.length;
		}
		 else 
		{
			len = other.length;
		}
		
		{
			int _g = 0;
			while (( _g < ((int) (len) ) ))
			{
				int i = _g++;
				if (( b1[i] != b2[i] )) 
				{
					return ( b1[i] - ((int) (b2[i]) ) );
				}
				
			}
			
		}
		
		return ( this.length - other.length );
	}
	
	
	public   double getDouble(int pos)
	{
		haxe.io.BytesInput b = new haxe.io.BytesInput(((haxe.io.Bytes) (this) ), ((java.lang.Object) (pos) ), ((java.lang.Object) (8) ));
		return b.readDouble();
	}
	
	
	public   double getFloat(int pos)
	{
		haxe.io.BytesInput b = new haxe.io.BytesInput(((haxe.io.Bytes) (this) ), ((java.lang.Object) (pos) ), ((java.lang.Object) (4) ));
		return b.readFloat();
	}
	
	
	public   void setDouble(int pos, double v)
	{
		throw haxe.lang.HaxeException.wrap("Not supported");
	}
	
	
	public   void setFloat(int pos, double v)
	{
		throw haxe.lang.HaxeException.wrap("Not supported");
	}
	
	
	public   java.lang.String getString(int pos, int len)
	{
		if (( ( ( pos < 0 ) || ( len < 0 ) ) || ( ( pos + len ) > this.length ) )) 
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.OutsideBounds);
		}
		
		try 
		{
			return new java.lang.String(((byte[]) (this.b) ), ((int) (pos) ), ((int) (len) ), haxe.lang.Runtime.toString("UTF-8"));
		}
		catch (java.lang.Throwable __temp_catchallException80950)
		{
			java.lang.Object __temp_catchall80951 = __temp_catchallException80950;
			if (( __temp_catchall80951 instanceof haxe.lang.HaxeException )) 
			{
				__temp_catchall80951 = ((haxe.lang.HaxeException) (__temp_catchallException80950) ).obj;
			}
			
			{
				java.lang.Object e = __temp_catchall80951;
				throw haxe.lang.HaxeException.wrap(e);
			}
			
		}
		
		
	}
	
	
	public final   java.lang.String readString(int pos, int len)
	{
		return this.getString(pos, len);
	}
	
	
	@Override public   java.lang.String toString()
	{
		try 
		{
			return new java.lang.String(((byte[]) (this.b) ), ((int) (0) ), ((int) (this.length) ), haxe.lang.Runtime.toString("UTF-8"));
		}
		catch (java.lang.Throwable __temp_catchallException80952)
		{
			java.lang.Object __temp_catchall80953 = __temp_catchallException80952;
			if (( __temp_catchall80953 instanceof haxe.lang.HaxeException )) 
			{
				__temp_catchall80953 = ((haxe.lang.HaxeException) (__temp_catchallException80952) ).obj;
			}
			
			{
				java.lang.Object e = __temp_catchall80953;
				throw haxe.lang.HaxeException.wrap(e);
			}
			
		}
		
		
	}
	
	
	public   java.lang.String toHex()
	{
		haxe.root.StringBuf s = new haxe.root.StringBuf();
		haxe.root.Array<java.lang.Object> chars = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		java.lang.String str = "0123456789abcdef";
		{
			int _g1 = 0;
			int _g = str.length();
			while (( _g1 < _g ))
			{
				int i = _g1++;
				chars.push(haxe.lang.StringExt.charCodeAt(str, i));
			}
			
		}
		
		{
			int _g11 = 0;
			int _g2 = this.length;
			while (( _g11 < _g2 ))
			{
				int i1 = _g11++;
				int c = ( this.b[i1] & 255 );
				s.addChar(((int) (haxe.lang.Runtime.toInt(chars.__get(( c >> 4 )))) ));
				s.addChar(((int) (haxe.lang.Runtime.toInt(chars.__get(( c & 15 )))) ));
			}
			
		}
		
		return s.toString();
	}
	
	
	public final   byte[] getData()
	{
		return this.b;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef80954 = true;
			switch (field.hashCode())
			{
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef80954 = false;
						this.length = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef80954) 
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
			boolean __temp_executeDef80955 = true;
			switch (field.hashCode())
			{
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef80955 = false;
						this.b = ((byte[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef80955 = false;
						this.length = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef80955) 
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
			boolean __temp_executeDef80956 = true;
			switch (field.hashCode())
			{
				case -75605984:
				{
					if (field.equals("getData")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getData"))) );
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef80956 = false;
						return this.length;
					}
					
					break;
				}
				
				
				case 110507680:
				{
					if (field.equals("toHex")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("toHex"))) );
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef80956 = false;
						return this.b;
					}
					
					break;
				}
				
				
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("toString"))) );
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get"))) );
					}
					
					break;
				}
				
				
				case -500196025:
				{
					if (field.equals("readString")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readString"))) );
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set"))) );
					}
					
					break;
				}
				
				
				case 804029191:
				{
					if (field.equals("getString")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getString"))) );
					}
					
					break;
				}
				
				
				case 3026677:
				{
					if (field.equals("blit")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("blit"))) );
					}
					
					break;
				}
				
				
				case 1392239386:
				{
					if (field.equals("setFloat")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setFloat"))) );
					}
					
					break;
				}
				
				
				case 3143043:
				{
					if (field.equals("fill")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("fill"))) );
					}
					
					break;
				}
				
				
				case 155439827:
				{
					if (field.equals("setDouble")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("setDouble"))) );
					}
					
					break;
				}
				
				
				case 114240:
				{
					if (field.equals("sub")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("sub"))) );
					}
					
					break;
				}
				
				
				case 1953351846:
				{
					if (field.equals("getFloat")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getFloat"))) );
					}
					
					break;
				}
				
				
				case 950484197:
				{
					if (field.equals("compare")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("compare"))) );
					}
					
					break;
				}
				
				
				case 370056903:
				{
					if (field.equals("getDouble")) 
					{
						__temp_executeDef80956 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getDouble"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef80956) 
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
			boolean __temp_executeDef80957 = true;
			switch (field.hashCode())
			{
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef80957 = false;
						return ((double) (this.length) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef80957) 
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
			boolean __temp_executeDef80958 = true;
			switch (field.hashCode())
			{
				case -75605984:
				{
					if (field.equals("getData")) 
					{
						__temp_executeDef80958 = false;
						return this.getData();
					}
					
					break;
				}
				
				
				case 102230:
				{
					if (field.equals("get")) 
					{
						__temp_executeDef80958 = false;
						return this.get(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 110507680:
				{
					if (field.equals("toHex")) 
					{
						__temp_executeDef80958 = false;
						return this.toHex();
					}
					
					break;
				}
				
				
				case 113762:
				{
					if (field.equals("set")) 
					{
						__temp_executeDef80958 = false;
						this.set(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case -1776922004:
				{
					if (field.equals("toString")) 
					{
						__temp_executeDef80958 = false;
						return this.toString();
					}
					
					break;
				}
				
				
				case 3026677:
				{
					if (field.equals("blit")) 
					{
						__temp_executeDef80958 = false;
						this.blit(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((haxe.io.Bytes) (dynargs.__get(1)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ));
					}
					
					break;
				}
				
				
				case -500196025:
				{
					if (field.equals("readString")) 
					{
						__temp_executeDef80958 = false;
						return this.readString(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 3143043:
				{
					if (field.equals("fill")) 
					{
						__temp_executeDef80958 = false;
						this.fill(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case 804029191:
				{
					if (field.equals("getString")) 
					{
						__temp_executeDef80958 = false;
						return this.getString(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 114240:
				{
					if (field.equals("sub")) 
					{
						__temp_executeDef80958 = false;
						return this.sub(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 1392239386:
				{
					if (field.equals("setFloat")) 
					{
						__temp_executeDef80958 = false;
						this.setFloat(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 950484197:
				{
					if (field.equals("compare")) 
					{
						__temp_executeDef80958 = false;
						return this.compare(((haxe.io.Bytes) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 155439827:
				{
					if (field.equals("setDouble")) 
					{
						__temp_executeDef80958 = false;
						this.setDouble(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 370056903:
				{
					if (field.equals("getDouble")) 
					{
						__temp_executeDef80958 = false;
						return this.getDouble(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1953351846:
				{
					if (field.equals("getFloat")) 
					{
						__temp_executeDef80958 = false;
						return this.getFloat(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef80958) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("b");
		baseArr.push("length");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


