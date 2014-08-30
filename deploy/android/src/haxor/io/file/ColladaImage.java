package haxor.io.file;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class ColladaImage extends haxe.lang.HxObject
{
	public    ColladaImage(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    ColladaImage()
	{
		haxor.io.file.ColladaImage.__hx_ctor_haxor_io_file_ColladaImage(this);
	}
	
	
	public static   void __hx_ctor_haxor_io_file_ColladaImage(haxor.io.file.ColladaImage __temp_me151468)
	{
		{
			__temp_me151468.data = null;
			__temp_me151468.depth = 0;
			__temp_me151468.height = 0;
			__temp_me151468.width = 0;
			__temp_me151468.source = "";
			__temp_me151468.format = "";
			__temp_me151468.name = "";
			__temp_me151468.id = "";
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.io.file.ColladaImage(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.io.file.ColladaImage();
	}
	
	
	public  java.lang.String id;
	
	public  java.lang.String name;
	
	public  java.lang.String format;
	
	public  java.lang.String source;
	
	public  int width;
	
	public  int height;
	
	public  int depth;
	
	public  haxor.graphics.texture.Bitmap data;
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152302 = true;
			switch (field.hashCode())
			{
				case 95472323:
				{
					if (field.equals("depth")) 
					{
						__temp_executeDef152302 = false;
						this.depth = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef152302 = false;
						this.width = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef152302 = false;
						this.height = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152302) 
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
			boolean __temp_executeDef152303 = true;
			switch (field.hashCode())
			{
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef152303 = false;
						this.data = ((haxor.graphics.texture.Bitmap) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef152303 = false;
						this.id = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 95472323:
				{
					if (field.equals("depth")) 
					{
						__temp_executeDef152303 = false;
						this.depth = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef152303 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef152303 = false;
						this.height = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1268779017:
				{
					if (field.equals("format")) 
					{
						__temp_executeDef152303 = false;
						this.format = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef152303 = false;
						this.width = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -896505829:
				{
					if (field.equals("source")) 
					{
						__temp_executeDef152303 = false;
						this.source = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152303) 
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
			boolean __temp_executeDef152304 = true;
			switch (field.hashCode())
			{
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef152304 = false;
						return this.data;
					}
					
					break;
				}
				
				
				case 3355:
				{
					if (field.equals("id")) 
					{
						__temp_executeDef152304 = false;
						return this.id;
					}
					
					break;
				}
				
				
				case 95472323:
				{
					if (field.equals("depth")) 
					{
						__temp_executeDef152304 = false;
						return this.depth;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef152304 = false;
						return this.name;
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef152304 = false;
						return this.height;
					}
					
					break;
				}
				
				
				case -1268779017:
				{
					if (field.equals("format")) 
					{
						__temp_executeDef152304 = false;
						return this.format;
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef152304 = false;
						return this.width;
					}
					
					break;
				}
				
				
				case -896505829:
				{
					if (field.equals("source")) 
					{
						__temp_executeDef152304 = false;
						return this.source;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152304) 
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
			boolean __temp_executeDef152305 = true;
			switch (field.hashCode())
			{
				case 95472323:
				{
					if (field.equals("depth")) 
					{
						__temp_executeDef152305 = false;
						return ((double) (this.depth) );
					}
					
					break;
				}
				
				
				case 113126854:
				{
					if (field.equals("width")) 
					{
						__temp_executeDef152305 = false;
						return ((double) (this.width) );
					}
					
					break;
				}
				
				
				case -1221029593:
				{
					if (field.equals("height")) 
					{
						__temp_executeDef152305 = false;
						return ((double) (this.height) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152305) 
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
		baseArr.push("data");
		baseArr.push("depth");
		baseArr.push("height");
		baseArr.push("width");
		baseArr.push("source");
		baseArr.push("format");
		baseArr.push("name");
		baseArr.push("id");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


