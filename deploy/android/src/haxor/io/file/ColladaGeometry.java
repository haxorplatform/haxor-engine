package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaGeometry extends haxe.lang.HxObject
{
	public    ColladaGeometry(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaGeometry()
	{
		haxor.io.file.ColladaGeometry.__hx_ctor_haxor_io_file_ColladaGeometry(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaGeometry(haxor.io.file.ColladaGeometry __temp_me160570)
	{
		{
			__temp_me160570.mesh = null;
			__temp_me160570.name = "";
			__temp_me160570.id = "";
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaGeometry(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaGeometry();
	}
	
	
	public  java.lang.String id;
	
	public  java.lang.String name;
	
	public  haxor.io.file.ColladaMesh mesh;
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef161400 = true;
			switch (field.hashCode())
			{
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef161400 = false;
						this.mesh = ((haxor.io.file.ColladaMesh) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef161400 = false;
						this.id = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef161400 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161400) 
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
			boolean __temp_executeDef161401 = true;
			switch (field.hashCode())
			{
				case 3347949:
				{
					if (field.equals("mesh")) 
					{
						__temp_executeDef161401 = false;
						return this.mesh;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef161401 = false;
						return this.id;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef161401 = false;
						return this.name;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef161401) 
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
		baseArr.push("mesh");
		baseArr.push("name");
		baseArr.push("id");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


