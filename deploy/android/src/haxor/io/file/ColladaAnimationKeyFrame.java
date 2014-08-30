package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaAnimationKeyFrame extends haxe.lang.HxObject
{
	public    ColladaAnimationKeyFrame(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaAnimationKeyFrame()
	{
		haxor.io.file.ColladaAnimationKeyFrame.__hx_ctor_haxor_io_file_ColladaAnimationKeyFrame(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaAnimationKeyFrame(haxor.io.file.ColladaAnimationKeyFrame __temp_me151476)
	{
		__temp_me151476.time = 0.0;
		__temp_me151476.values = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaAnimationKeyFrame(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaAnimationKeyFrame();
	}
	
	
	public  double time;
	
	public  haxe.root.Array<java.lang.Object> values;
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152327 = true;
			switch (field.hashCode())
			{
				case 3560141:
				{
					if (field.equals("time")) 
					{
						__temp_executeDef152327 = false;
						this.time = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152327) 
			{
				return super.__hx_setField_f(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152328 = true;
			switch (field.hashCode())
			{
				case -823812830:
				{
					if (field.equals("values")) 
					{
						__temp_executeDef152328 = false;
						this.values = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3560141:
				{
					if (field.equals("time")) 
					{
						__temp_executeDef152328 = false;
						this.time = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152328) 
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
			boolean __temp_executeDef152329 = true;
			switch (field.hashCode())
			{
				case -823812830:
				{
					if (field.equals("values")) 
					{
						__temp_executeDef152329 = false;
						return this.values;
					}
					
					break;
				}
				
				
				case 3560141:
				{
					if (field.equals("time")) 
					{
						__temp_executeDef152329 = false;
						return this.time;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152329) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152330 = true;
			switch (field.hashCode())
			{
				case 3560141:
				{
					if (field.equals("time")) 
					{
						__temp_executeDef152330 = false;
						return this.time;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152330) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("values");
		baseArr.push("time");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


