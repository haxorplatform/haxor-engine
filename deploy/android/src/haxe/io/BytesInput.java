package haxe.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class BytesInput extends haxe.io.Input
{
	public    BytesInput(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    BytesInput(haxe.io.Bytes b, java.lang.Object pos, java.lang.Object len)
	{
		haxe.io.BytesInput.__hx_ctor_haxe_io_BytesInput(this, b, pos, len);
	}
	
	
	public static   void __hx_ctor_haxe_io_BytesInput(haxe.io.BytesInput __temp_me160406, haxe.io.Bytes b, java.lang.Object pos, java.lang.Object len)
	{
		if (( pos == null )) 
		{
			pos = 0;
		}
		
		if (( len == null )) 
		{
			len = ( ((int) (b.length) ) - ((int) (haxe.lang.Runtime.toInt(pos)) ) );
		}
		
		if (( ( ( haxe.lang.Runtime.compare(pos, 0) < 0 ) || ( haxe.lang.Runtime.compare(len, 0) < 0 ) ) || ( ( ((int) (haxe.lang.Runtime.toInt(pos)) ) + ((int) (haxe.lang.Runtime.toInt(len)) ) ) > b.length ) )) 
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.OutsideBounds);
		}
		
		__temp_me160406.b = b.b;
		__temp_me160406.pos = ((int) (haxe.lang.Runtime.toInt(pos)) );
		__temp_me160406.len = ((int) (haxe.lang.Runtime.toInt(len)) );
		__temp_me160406.totlen = ((int) (haxe.lang.Runtime.toInt(len)) );
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.io.BytesInput(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.io.BytesInput(((haxe.io.Bytes) (arr.__get(0)) ), ((java.lang.Object) (arr.__get(1)) ), ((java.lang.Object) (arr.__get(2)) ));
	}
	
	
	public  byte[] b;
	
	public  int pos;
	
	public  int len;
	
	public  int totlen;
	
	
	
	
	
	public final   int get_position()
	{
		return this.pos;
	}
	
	
	public final   int get_length()
	{
		return this.totlen;
	}
	
	
	public   int set_position(int p)
	{
		if (( p < 0 )) 
		{
			p = 0;
		}
		 else 
		{
			if (( p > this.totlen )) 
			{
				p = this.totlen;
			}
			
		}
		
		this.len = ( this.totlen - p );
		return this.pos = p;
	}
	
	
	@Override public   int readByte()
	{
		if (( this.len == 0 )) 
		{
			throw haxe.lang.HaxeException.wrap(new haxe.io.Eof());
		}
		
		this.len--;
		return ( this.b[this.pos++] & 255 );
	}
	
	
	@Override public   int readBytes(haxe.io.Bytes buf, int pos, int len)
	{
		if (( ( ( pos < 0 ) || ( len < 0 ) ) || ( ( pos + len ) > buf.length ) )) 
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.OutsideBounds);
		}
		
		int avail = this.len;
		if (( len > avail )) 
		{
			len = avail;
		}
		
		if (( len == 0 )) 
		{
			throw haxe.lang.HaxeException.wrap(new haxe.io.Eof());
		}
		
		java.lang.System.arraycopy(((java.lang.Object) (this.b) ), ((int) (this.pos) ), ((java.lang.Object) (buf.b) ), ((int) (pos) ), ((int) (len) ));
		this.pos += len;
		this.len -= len;
		return len;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef160987 = true;
			switch (field.hashCode())
			{
				case 747804969:
				{
					if (field.equals("position")) 
					{
						__temp_executeDef160987 = false;
						this.set_position(((int) (value) ));
						return value;
					}
					
					break;
				}
				
				
				case 111188:
				{
					if (field.equals("pos")) 
					{
						__temp_executeDef160987 = false;
						this.pos = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -867912164:
				{
					if (field.equals("totlen")) 
					{
						__temp_executeDef160987 = false;
						this.totlen = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107029:
				{
					if (field.equals("len")) 
					{
						__temp_executeDef160987 = false;
						this.len = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160987) 
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
			boolean __temp_executeDef160988 = true;
			switch (field.hashCode())
			{
				case 747804969:
				{
					if (field.equals("position")) 
					{
						__temp_executeDef160988 = false;
						this.set_position(((int) (haxe.lang.Runtime.toInt(value)) ));
						return value;
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef160988 = false;
						this.b = ((byte[]) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -867912164:
				{
					if (field.equals("totlen")) 
					{
						__temp_executeDef160988 = false;
						this.totlen = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 111188:
				{
					if (field.equals("pos")) 
					{
						__temp_executeDef160988 = false;
						this.pos = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 107029:
				{
					if (field.equals("len")) 
					{
						__temp_executeDef160988 = false;
						this.len = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160988) 
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
			boolean __temp_executeDef160989 = true;
			switch (field.hashCode())
			{
				case -1140063115:
				{
					if (field.equals("readBytes")) 
					{
						__temp_executeDef160989 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readBytes"))) );
					}
					
					break;
				}
				
				
				case 98:
				{
					if (field.equals("b")) 
					{
						__temp_executeDef160989 = false;
						return this.b;
					}
					
					break;
				}
				
				
				case -868060226:
				{
					if (field.equals("readByte")) 
					{
						__temp_executeDef160989 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readByte"))) );
					}
					
					break;
				}
				
				
				case 111188:
				{
					if (field.equals("pos")) 
					{
						__temp_executeDef160989 = false;
						return this.pos;
					}
					
					break;
				}
				
				
				case 373742694:
				{
					if (field.equals("set_position")) 
					{
						__temp_executeDef160989 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("set_position"))) );
					}
					
					break;
				}
				
				
				case 107029:
				{
					if (field.equals("len")) 
					{
						__temp_executeDef160989 = false;
						return this.len;
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef160989 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_length"))) );
					}
					
					break;
				}
				
				
				case -867912164:
				{
					if (field.equals("totlen")) 
					{
						__temp_executeDef160989 = false;
						return this.totlen;
					}
					
					break;
				}
				
				
				case -1175249934:
				{
					if (field.equals("get_position")) 
					{
						__temp_executeDef160989 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_position"))) );
					}
					
					break;
				}
				
				
				case 747804969:
				{
					if (field.equals("position")) 
					{
						__temp_executeDef160989 = false;
						return this.get_position();
					}
					
					break;
				}
				
				
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef160989 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160989) 
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
			boolean __temp_executeDef160990 = true;
			switch (field.hashCode())
			{
				case -1106363674:
				{
					if (field.equals("length")) 
					{
						__temp_executeDef160990 = false;
						return ((double) (this.get_length()) );
					}
					
					break;
				}
				
				
				case 111188:
				{
					if (field.equals("pos")) 
					{
						__temp_executeDef160990 = false;
						return ((double) (this.pos) );
					}
					
					break;
				}
				
				
				case 747804969:
				{
					if (field.equals("position")) 
					{
						__temp_executeDef160990 = false;
						return ((double) (this.get_position()) );
					}
					
					break;
				}
				
				
				case 107029:
				{
					if (field.equals("len")) 
					{
						__temp_executeDef160990 = false;
						return ((double) (this.len) );
					}
					
					break;
				}
				
				
				case -867912164:
				{
					if (field.equals("totlen")) 
					{
						__temp_executeDef160990 = false;
						return ((double) (this.totlen) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160990) 
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
			int __temp_hash160992 = field.hashCode();
			boolean __temp_executeDef160991 = true;
			switch (__temp_hash160992)
			{
				case -1140063115:case -868060226:
				{
					if (( (( ( __temp_hash160992 == -1140063115 ) && field.equals("readBytes") )) || field.equals("readByte") )) 
					{
						__temp_executeDef160991 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -1175249934:
				{
					if (field.equals("get_position")) 
					{
						__temp_executeDef160991 = false;
						return this.get_position();
					}
					
					break;
				}
				
				
				case 373742694:
				{
					if (field.equals("set_position")) 
					{
						__temp_executeDef160991 = false;
						return this.set_position(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 974314479:
				{
					if (field.equals("get_length")) 
					{
						__temp_executeDef160991 = false;
						return this.get_length();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef160991) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("length");
		baseArr.push("position");
		baseArr.push("totlen");
		baseArr.push("len");
		baseArr.push("pos");
		baseArr.push("b");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


