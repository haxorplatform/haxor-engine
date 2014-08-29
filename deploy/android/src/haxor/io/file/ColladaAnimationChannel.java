package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaAnimationChannel extends haxe.lang.HxObject
{
	public    ColladaAnimationChannel(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaAnimationChannel()
	{
		haxor.io.file.ColladaAnimationChannel.__hx_ctor_haxor_io_file_ColladaAnimationChannel(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaAnimationChannel(haxor.io.file.ColladaAnimationChannel __temp_me80723)
	{
		__temp_me80723.target = "";
		__temp_me80723.source = "";
		__temp_me80723.keyframes = new haxe.root.Array<haxor.io.file.ColladaAnimationKeyFrame>(new haxor.io.file.ColladaAnimationKeyFrame[]{});
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaAnimationChannel(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaAnimationChannel();
	}
	
	
	public  java.lang.String source;
	
	public  java.lang.String target;
	
	public  haxe.root.Array<haxor.io.file.ColladaAnimationKeyFrame> keyframes;
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef81554 = true;
			switch (field.hashCode())
			{
				case -1446666299:
				{
					if (field.equals("keyframes")) 
					{
						__temp_executeDef81554 = false;
						this.keyframes = ((haxe.root.Array<haxor.io.file.ColladaAnimationKeyFrame>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -896505829:
				{
					if (field.equals("source")) 
					{
						__temp_executeDef81554 = false;
						this.source = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef81554 = false;
						this.target = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81554) 
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
			boolean __temp_executeDef81555 = true;
			switch (field.hashCode())
			{
				case -1446666299:
				{
					if (field.equals("keyframes")) 
					{
						__temp_executeDef81555 = false;
						return this.keyframes;
					}
					
					break;
				}
				
				
				case -896505829:
				{
					if (field.equals("source")) 
					{
						__temp_executeDef81555 = false;
						return this.source;
					}
					
					break;
				}
				
				
				case -880905839:
				{
					if (field.equals("target")) 
					{
						__temp_executeDef81555 = false;
						return this.target;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef81555) 
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
		baseArr.push("keyframes");
		baseArr.push("target");
		baseArr.push("source");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


