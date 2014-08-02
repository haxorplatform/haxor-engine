package haxe.io;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Output extends haxe.lang.HxObject
{
	public    Output(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    Output()
	{
		haxe.io.Output.__hx_ctor_haxe_io_Output(this);
	}
	
	
	public static   void __hx_ctor_haxe_io_Output(haxe.io.Output __temp_me1821)
	{
		{
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.io.Output(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.io.Output();
	}
	
	
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
	
	
	public   void writeFullBytes(haxe.io.Bytes s, int pos, int len)
	{
		while (( len > 0 ))
		{
			int k = this.writeBytes(s, pos, len);
			pos += k;
			len -= k;
		}
		
	}
	
	
	public   void writeString(java.lang.String s)
	{
		haxe.io.Bytes b = haxe.io.Bytes.ofString(s);
		this.writeFullBytes(b, 0, b.length);
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef1899 = true;
			switch (field.hashCode())
			{
				case 1412235472:
				{
					if (field.equals("writeString")) 
					{
						__temp_executeDef1899 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeString"))) );
					}
					
					break;
				}
				
				
				case -1406851705:
				{
					if (field.equals("writeByte")) 
					{
						__temp_executeDef1899 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeByte"))) );
					}
					
					break;
				}
				
				
				case 1188045309:
				{
					if (field.equals("writeFullBytes")) 
					{
						__temp_executeDef1899 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeFullBytes"))) );
					}
					
					break;
				}
				
				
				case -662729780:
				{
					if (field.equals("writeBytes")) 
					{
						__temp_executeDef1899 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("writeBytes"))) );
					}
					
					break;
				}
				
				
				case 97532676:
				{
					if (field.equals("flush")) 
					{
						__temp_executeDef1899 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("flush"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1899) 
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
			boolean __temp_executeDef1900 = true;
			switch (field.hashCode())
			{
				case 1412235472:
				{
					if (field.equals("writeString")) 
					{
						__temp_executeDef1900 = false;
						this.writeString(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case -1406851705:
				{
					if (field.equals("writeByte")) 
					{
						__temp_executeDef1900 = false;
						this.writeByte(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 1188045309:
				{
					if (field.equals("writeFullBytes")) 
					{
						__temp_executeDef1900 = false;
						this.writeFullBytes(((haxe.io.Bytes) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case -662729780:
				{
					if (field.equals("writeBytes")) 
					{
						__temp_executeDef1900 = false;
						return this.writeBytes(((haxe.io.Bytes) (dynargs.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case 97532676:
				{
					if (field.equals("flush")) 
					{
						__temp_executeDef1900 = false;
						this.flush();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef1900) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
}


