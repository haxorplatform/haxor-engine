package haxor.graphics.texture;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class Texture2D extends haxor.graphics.texture.Texture
{
	public    Texture2D(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    Texture2D(int p_width, int p_height, haxor.graphics.PixelFormat p_format)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.graphics.texture.Texture2D.__hx_ctor_haxor_graphics_texture_Texture2D(this, p_width, p_height, p_format);
	}
	
	
	public static   void __hx_ctor_haxor_graphics_texture_Texture2D(haxor.graphics.texture.Texture2D __temp_me56118, int p_width, int p_height, haxor.graphics.PixelFormat p_format)
	{
		haxor.graphics.texture.Texture.__hx_ctor_haxor_graphics_texture_Texture(__temp_me56118);
		__temp_me56118.m_format = p_format;
		__temp_me56118.m_width = p_width;
		__temp_me56118.m_height = p_height;
		if (( p_width <= 0 )) 
		{
			return ;
		}
		
		if (( p_height <= 0 )) 
		{
			return ;
		}
		
		__temp_me56118.m_data = new haxor.graphics.texture.Bitmap(((int) (p_width) ), ((int) (p_height) ), ((haxor.graphics.PixelFormat) (p_format) ));
		haxor.context.EngineContext.texture.Create(__temp_me56118);
	}
	
	
	
	
	public static   haxor.graphics.texture.Texture2D get_white()
	{
		if (( haxor.graphics.texture.Texture2D.m_white != null )) 
		{
			return haxor.graphics.texture.Texture2D.m_white;
		}
		
		haxor.graphics.texture.Texture2D.m_white = new haxor.graphics.texture.Texture2D(((int) (1) ), ((int) (1) ), ((haxor.graphics.PixelFormat) (haxor.graphics.PixelFormat.RGB8) ));
		haxor.graphics.texture.Texture2D.m_white.m_data.Fill(new haxor.math.Color(((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) ), ((java.lang.Object) (1) )));
		haxor.graphics.texture.Texture2D.m_white.Apply();
		return haxor.graphics.texture.Texture2D.m_white;
	}
	
	
	public static  haxor.graphics.texture.Texture2D m_white;
	
	
	
	public static   haxor.graphics.texture.Texture2D get_red()
	{
		if (( haxor.graphics.texture.Texture2D.m_red != null )) 
		{
			return haxor.graphics.texture.Texture2D.m_red;
		}
		
		haxor.graphics.texture.Texture2D.m_red = new haxor.graphics.texture.Texture2D(((int) (1) ), ((int) (1) ), ((haxor.graphics.PixelFormat) (haxor.graphics.PixelFormat.RGB8) ));
		haxor.graphics.texture.Texture2D.m_red.m_data.Fill(new haxor.math.Color(((java.lang.Object) (1.0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (0) ), ((java.lang.Object) (1) )));
		haxor.graphics.texture.Texture2D.m_red.Apply();
		return haxor.graphics.texture.Texture2D.m_red;
	}
	
	
	public static  haxor.graphics.texture.Texture2D m_red;
	
	public static   haxor.graphics.texture.Texture2D FromBitmap(haxor.graphics.texture.Bitmap p_bitmap, java.lang.Object p_apply)
	{
		boolean __temp_p_apply56117 = ( (( p_apply == null )) ? (haxe.lang.Runtime.toBool(true)) : (haxe.lang.Runtime.toBool(p_apply)) );
		haxor.graphics.texture.Texture2D t = new haxor.graphics.texture.Texture2D(((int) (0) ), ((int) (0) ), ((haxor.graphics.PixelFormat) (p_bitmap.m_format) ));
		t.m_data = p_bitmap;
		t.m_width = p_bitmap.m_width;
		t.m_height = p_bitmap.m_height;
		haxor.context.EngineContext.texture.Create(t);
		t.Apply();
		return t;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.graphics.texture.Texture2D(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.graphics.texture.Texture2D(((int) (haxe.lang.Runtime.toInt(arr.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(1))) ), ((haxor.graphics.PixelFormat) (arr.__get(2)) ));
	}
	
	
	public  haxor.graphics.texture.Bitmap data;
	
	public final   haxor.graphics.texture.Bitmap get_data()
	{
		return this.m_data;
	}
	
	
	public  haxor.graphics.texture.Bitmap m_data;
	
	@Override public   haxor.graphics.TextureType get_type()
	{
		return haxor.graphics.TextureType.Texture2D;
	}
	
	
	public   void Upload(java.lang.Object p_steps, haxe.lang.Function p_on_complete)
	{
		int __temp_p_steps56116 = ( (( p_steps == null )) ? (((int) (200) )) : (((int) (haxe.lang.Runtime.toInt(p_steps)) )) );
		haxor.context.EngineContext.texture.UploadTexture(this, __temp_p_steps56116, p_on_complete);
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef56448 = true;
			switch (field.hashCode())
			{
				case -1083579332:
				{
					if (field.equals("m_data")) 
					{
						__temp_executeDef56448 = false;
						this.m_data = ((haxor.graphics.texture.Bitmap) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef56448 = false;
						this.data = ((haxor.graphics.texture.Bitmap) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56448) 
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
			boolean __temp_executeDef56449 = true;
			switch (field.hashCode())
			{
				case -1754727903:
				{
					if (field.equals("Upload")) 
					{
						__temp_executeDef56449 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("Upload"))) );
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef56449 = false;
						if (handleProperties) 
						{
							return this.get_data();
						}
						 else 
						{
							return this.data;
						}
						
					}
					
					break;
				}
				
				
				case 1976688259:
				{
					if (field.equals("get_type")) 
					{
						__temp_executeDef56449 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_type"))) );
					}
					
					break;
				}
				
				
				case 1976188659:
				{
					if (field.equals("get_data")) 
					{
						__temp_executeDef56449 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("get_data"))) );
					}
					
					break;
				}
				
				
				case -1083579332:
				{
					if (field.equals("m_data")) 
					{
						__temp_executeDef56449 = false;
						return this.m_data;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56449) 
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
			boolean __temp_executeDef56450 = true;
			switch (field.hashCode())
			{
				case 1976688259:
				{
					if (field.equals("get_type")) 
					{
						__temp_executeDef56450 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 1976188659:
				{
					if (field.equals("get_data")) 
					{
						__temp_executeDef56450 = false;
						return this.get_data();
					}
					
					break;
				}
				
				
				case -1754727903:
				{
					if (field.equals("Upload")) 
					{
						__temp_executeDef56450 = false;
						this.Upload(dynargs.__get(0), ((haxe.lang.Function) (dynargs.__get(1)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef56450) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_data");
		baseArr.push("data");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


