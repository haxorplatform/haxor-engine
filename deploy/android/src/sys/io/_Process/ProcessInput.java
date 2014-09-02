package sys.io._Process;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ProcessInput extends haxe.java.io.NativeInput
{
	public    ProcessInput(haxe.lang.EmptyObject empty)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public    ProcessInput(java.io.InputStream stream)
	{
		super(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
		sys.io._Process.ProcessInput.__hx_ctor_sys_io__Process_ProcessInput(this, stream);
	}
	
	
	public static   void __hx_ctor_sys_io__Process_ProcessInput(sys.io._Process.ProcessInput __temp_me160714, java.io.InputStream stream)
	{
		haxe.java.io.NativeInput.__hx_ctor_haxe_java_io_NativeInput(__temp_me160714, stream);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new sys.io._Process.ProcessInput(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new sys.io._Process.ProcessInput(((java.io.InputStream) (arr.__get(0)) ));
	}
	
	
	public  haxe.io.BytesInput chained;
	
	public   void bufferContents()
	{
		if (( this.chained != null )) 
		{
			return ;
		}
		
		haxe.io.Bytes b = this.readAll(null);
		this.chained = new haxe.io.BytesInput(((haxe.io.Bytes) (b) ), ((java.lang.Object) (null) ), ((java.lang.Object) (null) ));
	}
	
	
	@Override public   int readByte()
	{
		if (( this.chained != null )) 
		{
			return this.chained.readByte();
		}
		
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
		if (( this.chained != null )) 
		{
			return this.chained.readBytes(s, pos, len);
		}
		
		int ret = -1;
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
		if (( this.chained != null )) 
		{
			this.chained.close();
		}
		
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
			boolean __temp_executeDef161654 = true;
			switch (field.hashCode())
			{
				case 738801440:
				{
					if (field.equals("chained")) 
					{
						__temp_executeDef161654 = false;
						this.chained = ((haxe.io.BytesInput) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161654) 
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
			boolean __temp_executeDef161655 = true;
			switch (field.hashCode())
			{
				case 94756344:
				{
					if (field.equals("close")) 
					{
						__temp_executeDef161655 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("close"))) );
					}
					
					break;
				}
				
				
				case 738801440:
				{
					if (field.equals("chained")) 
					{
						__temp_executeDef161655 = false;
						return this.chained;
					}
					
					break;
				}
				
				
				case -1140063115:
				{
					if (field.equals("readBytes")) 
					{
						__temp_executeDef161655 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readBytes"))) );
					}
					
					break;
				}
				
				
				case 640488314:
				{
					if (field.equals("bufferContents")) 
					{
						__temp_executeDef161655 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("bufferContents"))) );
					}
					
					break;
				}
				
				
				case -868060226:
				{
					if (field.equals("readByte")) 
					{
						__temp_executeDef161655 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("readByte"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161655) 
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
			int __temp_hash161657 = field.hashCode();
			boolean __temp_executeDef161656 = true;
			switch (__temp_hash161657)
			{
				case 94756344:case -1140063115:case -868060226:
				{
					if (( (( ( __temp_hash161657 == 94756344 ) && field.equals("close") )) || ( (( ( __temp_hash161657 == -1140063115 ) && field.equals("readBytes") )) || field.equals("readByte") ) )) 
					{
						__temp_executeDef161656 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 640488314:
				{
					if (field.equals("bufferContents")) 
					{
						__temp_executeDef161656 = false;
						this.bufferContents();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161656) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("chained");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


