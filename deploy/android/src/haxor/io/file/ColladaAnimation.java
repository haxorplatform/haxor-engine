package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaAnimation extends haxe.lang.HxObject
{
	public    ColladaAnimation(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaAnimation()
	{
		haxor.io.file.ColladaAnimation.__hx_ctor_haxor_io_file_ColladaAnimation(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaAnimation(haxor.io.file.ColladaAnimation __temp_me80722)
	{
		__temp_me80722.name = "";
		__temp_me80722.id = "";
		__temp_me80722.channels = new haxe.root.Array<haxor.io.file.ColladaAnimationChannel>(new haxor.io.file.ColladaAnimationChannel[]{});
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaAnimation(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaAnimation();
	}
	
	
	public  java.lang.String id;
	
	public  java.lang.String name;
	
	public  haxe.root.Array<haxor.io.file.ColladaAnimationChannel> channels;
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef81552 = true;
			switch (field.hashCode())
			{
				case 1432626128:
				{
					if (field.equals("channels")) 
					{
						__temp_executeDef81552 = false;
						this.channels = ((haxe.root.Array<haxor.io.file.ColladaAnimationChannel>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef81552 = false;
						this.id = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef81552 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81552) 
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
			boolean __temp_executeDef81553 = true;
			switch (field.hashCode())
			{
				case 1432626128:
				{
					if (field.equals("channels")) 
					{
						__temp_executeDef81553 = false;
						return this.channels;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef81553 = false;
						return this.id;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef81553 = false;
						return this.name;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81553) 
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
		baseArr.push("channels");
		baseArr.push("name");
		baseArr.push("id");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


