package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaMaterial extends haxe.lang.HxObject
{
	public    ColladaMaterial(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaMaterial()
	{
		haxor.io.file.ColladaMaterial.__hx_ctor_haxor_io_file_ColladaMaterial(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaMaterial(haxor.io.file.ColladaMaterial __temp_me164332)
	{
		{
			__temp_me164332.name = "";
			__temp_me164332.id = "";
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaMaterial(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaMaterial();
	}
	
	
	public  java.lang.String id;
	
	public  java.lang.String name;
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef165136 = true;
			switch (field.hashCode())
			{
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef165136 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef165136 = false;
						this.id = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef165136) 
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
			boolean __temp_executeDef165137 = true;
			switch (field.hashCode())
			{
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef165137 = false;
						return this.name;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef165137 = false;
						return this.id;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef165137) 
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
		baseArr.push("name");
		baseArr.push("id");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


