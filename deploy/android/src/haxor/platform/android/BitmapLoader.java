package haxor.platform.android;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class BitmapLoader extends haxor.platform.android.HTTPLoader<haxor.io.Buffer>
{
	public    BitmapLoader(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    BitmapLoader(java.lang.String p_url, haxe.lang.Function p_callback)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.platform.android.BitmapLoader.__hx_ctor_haxor_platform_android_BitmapLoader(this, p_url, p_callback);
	}
	
	
	public static   void __hx_ctor_haxor_platform_android_BitmapLoader(haxor.platform.android.BitmapLoader __temp_me54551, java.lang.String p_url, haxe.lang.Function p_callback)
	{
		haxor.platform.android.HTTPLoader.__hx_ctor_haxor_platform_android_HTTPLoader(__temp_me54551, p_url, true, ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (__temp_me54551) ), haxe.lang.Runtime.toString("OnBufferCallback"))) ));
		__temp_me54551.m_bitmap_callback = p_callback;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.BitmapLoader(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.BitmapLoader(haxe.lang.Runtime.toString(arr.__get(0)), ((haxe.lang.Function) (arr.__get(1)) ));
	}
	
	
	public  haxe.lang.Function m_bitmap_callback;
	
	public   void OnBufferCallback(haxor.io.Buffer p_data, double p_progress)
	{
		if (( this.m_progress < 1.0 )) 
		{
			if (( this.m_bitmap_callback != null )) 
			{
				this.m_bitmap_callback.__hx_invoke2_o(0.0, null, ( this.m_progress * 0.999 ), haxe.lang.Runtime.undefined);
			}
			
		}
		 else 
		{
			if (( p_data == null )) 
			{
				return ;
			}
			
			byte[] bl = this.response.toByteArray();
			android.graphics.Bitmap ab = null;
			try 
			{
				ab = android.graphics.BitmapFactory.decodeByteArray(((byte[]) (bl) ), ((int) (0) ), ((int) (bl.length) ));
			}
			catch (java.lang.Exception err)
			{
				this.error = err;
				this.OnError();
				return ;
			}
			
			
			if (( ab == null )) 
			{
				return ;
			}
			
			int w = ab.getWidth();
			int h = ab.getHeight();
			int cc = 0;
			{
				double x = ( ((double) (ab.getByteCount()) ) / (( w * h )) );
				cc = ((int) (x) );
			}
			
			haxor.graphics.PixelFormat fmt = haxor.graphics.PixelFormat.RGBA8;
			switch (cc)
			{
				case 1:
				{
					fmt = haxor.graphics.PixelFormat.Alpha8;
					break;
				}
				
				
				case 3:
				{
					fmt = haxor.graphics.PixelFormat.RGB8;
					break;
				}
				
				
			}
			
			haxor.graphics.texture.Bitmap b = new haxor.graphics.texture.Bitmap(((int) (w) ), ((int) (h) ), ((haxor.graphics.PixelFormat) (fmt) ));
			ab.copyPixelsToBuffer(((java.nio.Buffer) (b.get_buffer().m_buffer) ));
			if (( this.m_bitmap_callback != null )) 
			{
				this.m_bitmap_callback.__hx_invoke2_o(0.0, b, 1.0, haxe.lang.Runtime.undefined);
			}
			
		}
		
	}
	
	
	@Override public   void OnError()
	{
		if (( this.m_bitmap_callback != null )) 
		{
			this.m_bitmap_callback.__hx_invoke2_o(0.0, null, 1.0, haxe.lang.Runtime.undefined);
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef54824 = true;
			switch (field.hashCode())
			{
				case -1218961021:
				{
					if (field.equals("m_bitmap_callback")) 
					{
						__temp_executeDef54824 = false;
						this.m_bitmap_callback = ((haxe.lang.Function) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54824) 
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
			boolean __temp_executeDef54825 = true;
			switch (field.hashCode())
			{
				case 314785609:
				{
					if (field.equals("OnError")) 
					{
						__temp_executeDef54825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnError"))) );
					}
					
					break;
				}
				
				
				case -1218961021:
				{
					if (field.equals("m_bitmap_callback")) 
					{
						__temp_executeDef54825 = false;
						return this.m_bitmap_callback;
					}
					
					break;
				}
				
				
				case 978044036:
				{
					if (field.equals("OnBufferCallback")) 
					{
						__temp_executeDef54825 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBufferCallback"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54825) 
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
			boolean __temp_executeDef54826 = true;
			switch (field.hashCode())
			{
				case 314785609:
				{
					if (field.equals("OnError")) 
					{
						__temp_executeDef54826 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case 978044036:
				{
					if (field.equals("OnBufferCallback")) 
					{
						__temp_executeDef54826 = false;
						this.OnBufferCallback(((haxor.io.Buffer) (dynargs.__get(0)) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54826) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_bitmap_callback");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


