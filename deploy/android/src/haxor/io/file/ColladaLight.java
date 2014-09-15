package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaLight extends haxe.lang.HxObject
{
	public    ColladaLight(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaLight()
	{
		haxor.io.file.ColladaLight.__hx_ctor_haxor_io_file_ColladaLight(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaLight(haxor.io.file.ColladaLight __temp_me255534)
	{
		__temp_me255534.id = "";
		__temp_me255534.name = "";
		__temp_me255534.type = "";
		__temp_me255534.color = new haxor.math.Color(((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ));
		__temp_me255534.radius = 0.0;
		__temp_me255534.intensity = 0.0;
		__temp_me255534.atten = 0.0;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaLight(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaLight();
	}
	
	
	public  java.lang.String id;
	
	public  java.lang.String name;
	
	public  java.lang.String type;
	
	public  haxor.math.Color color;
	
	public  double radius;
	
	public  double intensity;
	
	public  double atten;
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256338 = true;
			switch (field.hashCode())
			{
				case 93152010:
				{
					if (field.equals("atten")) 
					{
						__temp_executeDef256338 = false;
						this.atten = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -938578798:
				{
					if (field.equals("radius")) 
					{
						__temp_executeDef256338 = false;
						this.radius = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 499324979:
				{
					if (field.equals("intensity")) 
					{
						__temp_executeDef256338 = false;
						this.intensity = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256338) 
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
			boolean __temp_executeDef256339 = true;
			switch (field.hashCode())
			{
				case 93152010:
				{
					if (field.equals("atten")) 
					{
						__temp_executeDef256339 = false;
						this.atten = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef256339 = false;
						this.id = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 499324979:
				{
					if (field.equals("intensity")) 
					{
						__temp_executeDef256339 = false;
						this.intensity = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef256339 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -938578798:
				{
					if (field.equals("radius")) 
					{
						__temp_executeDef256339 = false;
						this.radius = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef256339 = false;
						this.type = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 94842723:
				{
					if (field.equals("color")) 
					{
						__temp_executeDef256339 = false;
						this.color = ((haxor.math.Color) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256339) 
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
			boolean __temp_executeDef256340 = true;
			switch (field.hashCode())
			{
				case 93152010:
				{
					if (field.equals("atten")) 
					{
						__temp_executeDef256340 = false;
						return this.atten;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef256340 = false;
						return this.id;
					}
					
					break;
				}
				
				
				case 499324979:
				{
					if (field.equals("intensity")) 
					{
						__temp_executeDef256340 = false;
						return this.intensity;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef256340 = false;
						return this.name;
					}
					
					break;
				}
				
				
				case -938578798:
				{
					if (field.equals("radius")) 
					{
						__temp_executeDef256340 = false;
						return this.radius;
					}
					
					break;
				}
				
				
				case 3575610:
				{
					if (field.equals("type")) 
					{
						__temp_executeDef256340 = false;
						return this.type;
					}
					
					break;
				}
				
				
				case 94842723:
				{
					if (field.equals("color")) 
					{
						__temp_executeDef256340 = false;
						return this.color;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256340) 
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
			boolean __temp_executeDef256341 = true;
			switch (field.hashCode())
			{
				case 93152010:
				{
					if (field.equals("atten")) 
					{
						__temp_executeDef256341 = false;
						return this.atten;
					}
					
					break;
				}
				
				
				case -938578798:
				{
					if (field.equals("radius")) 
					{
						__temp_executeDef256341 = false;
						return this.radius;
					}
					
					break;
				}
				
				
				case 499324979:
				{
					if (field.equals("intensity")) 
					{
						__temp_executeDef256341 = false;
						return this.intensity;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256341) 
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
		baseArr.push("atten");
		baseArr.push("intensity");
		baseArr.push("radius");
		baseArr.push("color");
		baseArr.push("type");
		baseArr.push("name");
		baseArr.push("id");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


