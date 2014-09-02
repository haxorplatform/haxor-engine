package haxe.java.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class NativeOutput extends haxe.io.Output
{
	public    NativeOutput(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    NativeOutput(java.io.OutputStream stream)
	{
		haxe.java.io.NativeOutput.__hx_ctor_haxe_java_io_NativeOutput(this, stream);
	}
	
	
	public static   void __hx_ctor_haxe_java_io_NativeOutput(haxe.java.io.NativeOutput __temp_me160712, java.io.OutputStream stream)
	{
		__temp_me160712.stream = stream;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.java.io.NativeOutput(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.java.io.NativeOutput(((java.io.OutputStream) (arr.__get(0)) ));
	}
	
	
	public  java.io.OutputStream stream;
	
	@Override public   void writeByte(int c)
	{
		try 
		{
			this.stream.write(((int) (c) ));
		}
		catch (java.io.EOFException e)
		{
			throw haxe.lang.HaxeException.wrap(new haxe.io.Eof());
		}
		
		catch (java.io.IOException e1)
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.Custom(e1));
		}
		
		
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
	
	
	@Override public   void flush()
	{
		try 
		{
			this.stream.flush();
		}
		catch (java.io.IOException e)
		{
			throw haxe.lang.HaxeException.wrap(haxe.io.Error.Custom(e));
		}
		
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161645 = true;
			switch (field.hashCode())
			{
				case -891990144:
				{
					if (field.equals("stream")) 
					{
						__temp_executeDef161645 = false;
						this.stream = ((java.io.OutputStream) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161645) 
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
			boolean __temp_executeDef161646 = true;
			switch (field.hashCode())
			{
				case 97532676:
				{
					if (field.equals("flush")) 
					{
						__temp_executeDef161646 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("flush"))) );
					}
					
					break;
				}
				
				
				case -891990144:
				{
					if (field.equals("stream")) 
					{
						__temp_executeDef161646 = false;
						return this.stream;
					}
					
					break;
				}
				
				
				case 94756344:
				{
					if (field.equals("close")) 
					{
						__temp_executeDef161646 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("close"))) );
					}
					
					break;
				}
				
				
				case -1406851705:
				{
					if (field.equals("writeByte")) 
					{
						__temp_executeDef161646 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeByte"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161646) 
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


