package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaInstance extends haxe.lang.HxObject
{
	public    ColladaInstance(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaInstance()
	{
		haxor.io.file.ColladaInstance.__hx_ctor_haxor_io_file_ColladaInstance(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaInstance(haxor.io.file.ColladaInstance __temp_me255529)
	{
		__temp_me255529.target = "";
		__temp_me255529.type = "";
		__temp_me255529.materials = new haxe.root.Array<java.lang.String>(new java.lang.String[]{});
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaInstance(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaInstance();
	}
	
	
	public  java.lang.String type;
	
	public  java.lang.String target;
	
	public  haxe.root.Array<java.lang.String> materials;
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256326 = true;
			switch (field.hashCode())
			{
				case 681132076:
				{
					if (field.equals("materials")) 
					{
						__temp_executeDef256326 = false;
						this.materials = ((haxe.root.Array<java.lang.String>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef256326 = false;
						this.type = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef256326 = false;
						this.target = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256326) 
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
			boolean __temp_executeDef256327 = true;
			switch (field.hashCode())
			{
				case 681132076:
				{
					if (field.equals("materials")) 
					{
						__temp_executeDef256327 = false;
						return this.materials;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef256327 = false;
						return this.type;
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef256327 = false;
						return this.target;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256327) 
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
		baseArr.push("materials");
		baseArr.push("target");
		baseArr.push("type");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


