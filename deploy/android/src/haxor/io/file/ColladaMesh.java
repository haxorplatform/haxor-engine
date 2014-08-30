package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaMesh extends haxe.lang.HxObject
{
	public    ColladaMesh(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaMesh()
	{
		haxor.io.file.ColladaMesh.__hx_ctor_haxor_io_file_ColladaMesh(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaMesh(haxor.io.file.ColladaMesh __temp_me151461)
	{
		__temp_me151461.primitives = null;
		__temp_me151461.type = "";
		__temp_me151461.primitives = new haxe.root.Array<haxor.io.file.ColladaPrimitive>(new haxor.io.file.ColladaPrimitive[]{});
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaMesh(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaMesh();
	}
	
	
	public  java.lang.String type;
	
	public  haxe.root.Array<haxor.io.file.ColladaPrimitive> primitives;
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152291 = true;
			switch (field.hashCode())
			{
				case -1044475796:
				{
					if (field.equals("primitives")) 
					{
						__temp_executeDef152291 = false;
						this.primitives = ((haxe.root.Array<haxor.io.file.ColladaPrimitive>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef152291 = false;
						this.type = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152291) 
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
			boolean __temp_executeDef152292 = true;
			switch (field.hashCode())
			{
				case -1044475796:
				{
					if (field.equals("primitives")) 
					{
						__temp_executeDef152292 = false;
						return this.primitives;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef152292 = false;
						return this.type;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152292) 
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
		baseArr.push("primitives");
		baseArr.push("type");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


