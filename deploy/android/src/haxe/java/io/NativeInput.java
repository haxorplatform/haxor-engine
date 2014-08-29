package haxe.java.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class NativeInput extends haxe.io.Input
{
	public    NativeInput(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    NativeInput(java.io.InputStream stream)
	{
		haxe.java.io.NativeInput.__hx_ctor_haxe_java_io_NativeInput(this, stream);
	}
	
	
	public static   void __hx_ctor_haxe_java_io_NativeInput(haxe.java.io.NativeInput __temp_me80846, java.io.InputStream stream)
	{
		__temp_me80846.stream = stream;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.java.io.NativeInput(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.java.io.NativeInput(((java.io.InputStream) (arr.__get(0)) ));
	}
	
	
	public  java.io.InputStream stream;
	
	@Override public   int readByte()
	{
		int ret = 0;
		try 
		{
			ret = this.stream.read();
		}
		catch (java.io.IOException e)
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.Custom(e));
		}
		
		
		if (( ret == -1 )) 
		{
			throw haxe.lang.HaxeException.wrap(new haxe.io.Eof());
		}
		
		return ret;
	}
	
	
	@Override public   int readBytes(haxe.io.Bytes s, int pos, int len)
	{
		int ret = 0;
		try 
		{
			ret = this.stream.read(((byte[]) (s.b) ), ((int) (pos) ), ((int) (len) ));
		}
		catch (java.io.EOFException e)
		{
			throw haxe.lang.HaxeException.wrap(new haxe.io.Eof());
		}
		
		catch (java.io.IOException e1)
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.Custom(e1));
		}
		
		
		if (( ret == -1 )) 
		{
			throw haxe.lang.HaxeException.wrap(new haxe.io.Eof());
		}
		
		return ret;
	}
	
	
	@Override public   void close()
	{
		try 
		{
			this.stream.close();
		}
		catch (java.io.IOException e)
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.Custom(e));
		}
		
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef81736 = true;
			switch (field.hashCode())
			{
				case -891990144:
				{
					if (field.equals("stream")) 
					{
						__temp_executeDef81736 = false;
						this.stream = ((java.io.InputStream) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81736) 
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
			boolean __temp_executeDef81737 = true;
			switch (field.hashCode())
			{
				case 94756344:
				{
					if (field.equals("close")) 
					{
						__temp_executeDef81737 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("close"))) );
					}
					
					break;
				}
				
				
				case -891990144:
				{
					if (field.equals("stream")) 
					{
						__temp_executeDef81737 = false;
						return this.stream;
					}
					
					break;
				}
				
				
				case -1140063115:
				{
					if (field.equals("readBytes")) 
					{
						__temp_executeDef81737 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readBytes"))) );
					}
					
					break;
				}
				
				
				case -868060226:
				{
					if (field.equals("readByte")) 
					{
						__temp_executeDef81737 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readByte"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81737) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("stream");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


