package haxor.context;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class TextureContext extends haxe.lang.HxObject
{
	public    TextureContext(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    TextureContext()
	{
		haxor.context.TextureContext.__hx_ctor_haxor_context_TextureContext(this);
	}
	
	
	public static   void __hx_ctor_haxor_context_TextureContext(haxor.context.TextureContext __temp_me33809)
	{
		__temp_me33809.tid = 0;
	}
	
	
	public static   int FormatToChannelBits(haxor.graphics.PixelFormat p_format)
	{
		switch (haxe.root.Type.enumIndex(p_format))
		{
			case 0:
			{
				return 6406;
			}
			
			
			case 2:
			{
				return 6407;
			}
			
			
			case 3:
			{
				return 6408;
			}
			
			
			case 7:case 4:
			{
				return 6409;
			}
			
			
			case 8:case 5:
			{
				return 6407;
			}
			
			
			case 9:case 6:
			{
				return 6408;
			}
			
			
			case 1:
			{
				return 6409;
			}
			
			
			case 10:
			{
				return 6402;
			}
			
			
		}
		
		return 6408;
	}
	
	
	public static   int FormatToChannelType(haxor.graphics.PixelFormat p_format)
	{
		switch (haxe.root.Type.enumIndex(p_format))
		{
			case 4:case 5:case 6:
			{
				return haxor.platform.graphics.GL.HALF_FLOAT;
			}
			
			
			case 7:case 8:case 9:
			{
				return 5126;
			}
			
			
			case 10:
			{
				return 5123;
			}
			
			
			case 3:case 2:case 1:case 0:
			{
				return 5121;
			}
			
			
		}
		
		return 5121;
	}
	
	
	public static   int FormatToChannelLayout(haxor.graphics.PixelFormat p_format)
	{
		switch (haxe.root.Type.enumIndex(p_format))
		{
			case 0:
			{
				return 6406;
			}
			
			
			case 2:
			{
				return 6407;
			}
			
			
			case 3:
			{
				return 6408;
			}
			
			
			case 1:case 4:case 7:
			{
				return 6409;
			}
			
			
			case 8:case 5:
			{
				return 6407;
			}
			
			
			case 9:case 6:
			{
				return 6408;
			}
			
			
			case 10:
			{
				return 6402;
			}
			
			
		}
		
		return 6408;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.context.TextureContext(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.context.TextureContext();
	}
	
	
	public  int tid;
	
	public   void Initialize()
	{
		{
		}
		
	}
	
	
	public   void Create(haxor.graphics.texture.Texture p_texture)
	{
		{
		}
		
	}
	
	
	public   void UpdateParameters(haxor.graphics.texture.Texture p_texture)
	{
		{
		}
		
	}
	
	
	public   void Update(haxor.graphics.texture.Texture p_texture)
	{
		{
		}
		
	}
	
	
	public   void UpdateMipmaps(haxor.graphics.texture.Texture p_texture)
	{
		{
		}
		
	}
	
	
	public   void Destroy(haxor.graphics.texture.Texture p_texture)
	{
		{
		}
		
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef34005 = true;
			switch (field.hashCode())
			{
				case 114831:
				{
					if (field.equals("tid")) 
					{
						__temp_executeDef34005 = false;
						this.tid = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef34005) 
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
			boolean __temp_executeDef34006 = true;
			switch (field.hashCode())
			{
				case 114831:
				{
					if (field.equals("tid")) 
					{
						__temp_executeDef34006 = false;
						this.tid = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef34006) 
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
			boolean __temp_executeDef34007 = true;
			switch (field.hashCode())
			{
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef34007 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Destroy"))) );
					}
					
					break;
				}
				
				
				case 114831:
				{
					if (field.equals("tid")) 
					{
						__temp_executeDef34007 = false;
						return this.tid;
					}
					
					break;
				}
				
				
				case 369503682:
				{
					if (field.equals("UpdateMipmaps")) 
					{
						__temp_executeDef34007 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateMipmaps"))) );
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef34007 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Initialize"))) );
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef34007 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Update"))) );
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef34007 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Create"))) );
					}
					
					break;
				}
				
				
				case -1667730509:
				{
					if (field.equals("UpdateParameters")) 
					{
						__temp_executeDef34007 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("UpdateParameters"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef34007) 
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
			boolean __temp_executeDef34008 = true;
			switch (field.hashCode())
			{
				case 114831:
				{
					if (field.equals("tid")) 
					{
						__temp_executeDef34008 = false;
						return ((double) (this.tid) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef34008) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			boolean __temp_executeDef34009 = true;
			switch (field.hashCode())
			{
				case -1072941094:
				{
					if (field.equals("Destroy")) 
					{
						__temp_executeDef34009 = false;
						this.Destroy(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1430411344:
				{
					if (field.equals("Initialize")) 
					{
						__temp_executeDef34009 = false;
						this.Initialize();
					}
					
					break;
				}
				
				
				case 369503682:
				{
					if (field.equals("UpdateMipmaps")) 
					{
						__temp_executeDef34009 = false;
						this.UpdateMipmaps(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 2026540316:
				{
					if (field.equals("Create")) 
					{
						__temp_executeDef34009 = false;
						this.Create(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1754979095:
				{
					if (field.equals("Update")) 
					{
						__temp_executeDef34009 = false;
						this.Update(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1667730509:
				{
					if (field.equals("UpdateParameters")) 
					{
						__temp_executeDef34009 = false;
						this.UpdateParameters(((haxor.graphics.texture.Texture) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef34009) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("tid");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


