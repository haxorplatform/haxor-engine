package haxor.graphics.texture;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class RenderTexture extends haxor.graphics.texture.Texture
{
	public    RenderTexture(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    RenderTexture(int p_width, int p_height, haxor.core.PixelFormat p_format, java.lang.Object p_store_depth)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.graphics.texture.RenderTexture.__hx_ctor_haxor_graphics_texture_RenderTexture(this, p_width, p_height, p_format, p_store_depth);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_texture_RenderTexture(haxor.graphics.texture.RenderTexture __temp_me151427, int p_width, int p_height, haxor.core.PixelFormat p_format, java.lang.Object p_store_depth)
	{
		haxor.graphics.texture.Texture.__hx_ctor_haxor_graphics_texture_Texture(__temp_me151427);
		boolean __temp_p_store_depth151426 = ( (( p_store_depth == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(p_store_depth)) );
		__temp_me151427.m_format = p_format;
		__temp_me151427.m_width = ((int) (p_width) );
		__temp_me151427.m_height = ((int) (p_height) );
		boolean store_depth = ( __temp_p_store_depth151426 && haxor.graphics.GL.TEXTURE_DEPTH_ENABLED );
		if (store_depth) 
		{
			__temp_me151427.m_depth = new haxor.graphics.texture.Texture2D(((int) (__temp_me151427.m_width) ), ((int) (__temp_me151427.m_height) ), ((haxor.core.PixelFormat) (haxor.core.PixelFormat.Depth) ));
		}
		
		haxor.context.EngineContext.texture.Create(__temp_me151427);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.texture.RenderTexture(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.texture.RenderTexture(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(1))) ), ((haxor.core.PixelFormat) (arr.__get(2)) ), ((java.lang.Object) (arr.__get(3)) ));
	}
	
	
	
	
	public final   haxor.graphics.texture.Texture2D get_depth()
	{
		return this.m_depth;
	}
	
	
	public  haxor.graphics.texture.Texture2D m_depth;
	
	@Override public   haxor.core.TextureType get_type()
	{
		return haxor.core.TextureType.RenderTexture;
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef152196 = true;
			switch (field.hashCode())
			{
				case 768895089:
				{
					if (field.equals("m_depth")) 
					{
						__temp_executeDef152196 = false;
						this.m_depth = ((haxor.graphics.texture.Texture2D) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152196) 
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
			boolean __temp_executeDef152197 = true;
			switch (field.hashCode())
			{
				case 1976688259:
				{
					if (field.equals("get_type")) 
					{
						__temp_executeDef152197 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_type"))) );
					}
					
					break;
				}
				
				
				case 95472323:
				{
					if (field.equals("depth")) 
					{
						__temp_executeDef152197 = false;
						return this.get_depth();
					}
					
					break;
				}
				
				
				case 768895089:
				{
					if (field.equals("m_depth")) 
					{
						__temp_executeDef152197 = false;
						return this.m_depth;
					}
					
					break;
				}
				
				
				case 1132422298:
				{
					if (field.equals("get_depth")) 
					{
						__temp_executeDef152197 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_depth"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152197) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
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
			boolean __temp_executeDef152198 = true;
			switch (field.hashCode())
			{
				case 1976688259:
				{
					if (field.equals("get_type")) 
					{
						__temp_executeDef152198 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1132422298:
				{
					if (field.equals("get_depth")) 
					{
						__temp_executeDef152198 = false;
						return this.get_depth();
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef152198) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_depth");
		baseArr.push("depth");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


