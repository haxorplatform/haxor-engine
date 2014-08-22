package haxor.graphics.material;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class MaterialUniform extends haxe.lang.HxObject
{
	public    MaterialUniform(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    MaterialUniform(java.lang.String p_name, boolean p_is_float, int p_length, int p_offset)
	{
		haxor.graphics.material.MaterialUniform.__hx_ctor_haxor_graphics_material_MaterialUniform(this, p_name, p_is_float, p_length, p_offset);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_material_MaterialUniform(haxor.graphics.material.MaterialUniform __temp_me55700, java.lang.String p_name, boolean p_is_float, int p_length, int p_offset)
	{
		__temp_me55700.__cid = haxor.context.EngineContext.material.uid++;
		__temp_me55700.__d = true;
		__temp_me55700.name = p_name;
		__temp_me55700.isFloat = p_is_float;
		__temp_me55700.offset = p_offset;
		if (p_is_float) 
		{
			__temp_me55700.data = new haxor.io.FloatArray(((int) (p_length) ));
		}
		 else 
		{
			__temp_me55700.data = new haxor.io.Int32Array(((int) (p_length) ));
		}
		
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.material.MaterialUniform(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.material.MaterialUniform(haxe.lang.Runtime.toString(arr.__get(0)), haxe.lang.Runtime.toBool(arr.__get(1)), ((int) (haxe.lang.Runtime.toInt(arr.__get(2))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(3))) ));
	}
	
	
	public  int __cid;
	
	public  boolean __d;
	
	public  java.lang.String name;
	
	public  haxor.io.Buffer data;
	
	public  int offset;
	
	public  haxor.graphics.texture.Texture texture;
	
	public  boolean isFloat;
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef55930 = true;
			switch (field.hashCode())
			{
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef55930 = false;
						this.offset = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef55930 = false;
						this.__cid = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef55930) 
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
			boolean __temp_executeDef55931 = true;
			switch (field.hashCode())
			{
				case 2058932050:
				{
					if (field.equals("isFloat")) 
					{
						__temp_executeDef55931 = false;
						this.isFloat = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef55931 = false;
						this.__cid = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1417816805:
				{
					if (field.equals("texture")) 
					{
						__temp_executeDef55931 = false;
						this.texture = ((haxor.graphics.texture.Texture) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 94340:
				{
					if (field.equals("__d")) 
					{
						__temp_executeDef55931 = false;
						this.__d = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef55931 = false;
						this.offset = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef55931 = false;
						this.name = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef55931 = false;
						this.data = ((haxor.io.Buffer) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef55931) 
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
			boolean __temp_executeDef55932 = true;
			switch (field.hashCode())
			{
				case 2058932050:
				{
					if (field.equals("isFloat")) 
					{
						__temp_executeDef55932 = false;
						return this.isFloat;
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef55932 = false;
						return this.__cid;
					}
					
					break;
				}
				
				
				case -1417816805:
				{
					if (field.equals("texture")) 
					{
						__temp_executeDef55932 = false;
						return this.texture;
					}
					
					break;
				}
				
				
				case 94340:
				{
					if (field.equals("__d")) 
					{
						__temp_executeDef55932 = false;
						return this.__d;
					}
					
					break;
				}
				
				
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef55932 = false;
						return this.offset;
					}
					
					break;
				}
				
				
				case 3373707:
				{
					if (field.equals("name")) 
					{
						__temp_executeDef55932 = false;
						return this.name;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef55932 = false;
						return this.data;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef55932) 
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
			boolean __temp_executeDef55933 = true;
			switch (field.hashCode())
			{
				case -1019779949:
				{
					if (field.equals("offset")) 
					{
						__temp_executeDef55933 = false;
						return ((double) (this.offset) );
					}
					
					break;
				}
				
				
				case 90663134:
				{
					if (field.equals("__cid")) 
					{
						__temp_executeDef55933 = false;
						return ((double) (this.__cid) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef55933) 
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
		baseArr.push("isFloat");
		baseArr.push("texture");
		baseArr.push("offset");
		baseArr.push("data");
		baseArr.push("name");
		baseArr.push("__d");
		baseArr.push("__cid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


