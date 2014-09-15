package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class MaterialFileUniform extends haxe.lang.HxObject
{
	public    MaterialFileUniform(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    MaterialFileUniform()
	{
		haxor.io.file.MaterialFileUniform.__hx_ctor_haxor_io_file_MaterialFileUniform(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_MaterialFileUniform(haxor.io.file.MaterialFileUniform __temp_me255536)
	{
		__temp_me255536.type = "";
		__temp_me255536.name = "";
		__temp_me255536.value = "";
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.MaterialFileUniform(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.MaterialFileUniform();
	}
	
	
	public  java.lang.String type;
	
	public  java.lang.String name;
	
	public  java.lang.String value;
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256361 = true;
			switch (field.hashCode())
			{
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef256361 = false;
						this.value = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef256361 = false;
						this.type = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef256361 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256361) 
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
			boolean __temp_executeDef256362 = true;
			switch (field.hashCode())
			{
				case 111972721:
				{
					if (field.equals("value")) 
					{
						__temp_executeDef256362 = false;
						return this.value;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef256362 = false;
						return this.type;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef256362 = false;
						return this.name;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256362) 
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
		baseArr.push("value");
		baseArr.push("name");
		baseArr.push("type");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


