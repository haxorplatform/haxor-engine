package haxor.platform.android;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class LoadTexture2D extends haxor.platform.android.LoadBitmap
{
	public    LoadTexture2D(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    LoadTexture2D(java.lang.String p_url, boolean p_apply, haxe.lang.Function p_callback)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.platform.android.LoadTexture2D.__hx_ctor_haxor_platform_android_LoadTexture2D(this, p_url, p_apply, p_callback);
	}
	
	
	public static   void __hx_ctor_haxor_platform_android_LoadTexture2D(haxor.platform.android.LoadTexture2D __temp_me54148, java.lang.String p_url, boolean p_apply, haxe.lang.Function p_callback)
	{
		haxor.platform.android.LoadBitmap.__hx_ctor_haxor_platform_android_LoadBitmap(__temp_me54148, p_url, ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (__temp_me54148) ), haxe.lang.Runtime.toString("OnBitmapCallback"))) ));
		__temp_me54148.m_t2d_callback = p_callback;
		__temp_me54148.m_apply = p_apply;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.LoadTexture2D(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.LoadTexture2D(haxe.lang.Runtime.toString(arr.__get(0)), haxe.lang.Runtime.toBool(arr.__get(1)), ((haxe.lang.Function) (arr.__get(2)) ));
	}
	
	
	public  haxe.lang.Function m_t2d_callback;
	
	public  boolean m_apply;
	
	public   void OnBitmapCallback(haxor.graphics.texture.Bitmap p_data, double p_progress)
	{
		haxe.root.Array<haxor.graphics.texture.Bitmap> p_data1 = new haxe.root.Array<haxor.graphics.texture.Bitmap>(new haxor.graphics.texture.Bitmap[]{p_data});
		haxe.root.Array<haxor.platform.android.LoadTexture2D> _g = new haxe.root.Array<haxor.platform.android.LoadTexture2D>(new haxor.platform.android.LoadTexture2D[]{this});
		if (( this.m_progress < 1.0 )) 
		{
			if (( this.m_t2d_callback != null )) 
			{
				this.m_t2d_callback.__hx_invoke2_o(0.0, null, this.m_progress, haxe.lang.Runtime.undefined);
			}
			
		}
		 else 
		{
			if (( p_data1.__get(0) == null )) 
			{
				return ;
			}
			
			haxor.thread.Activity.RunOnce(new haxor.platform.android.LoadTexture2D_OnBitmapCallback_58__Fun(((haxe.root.Array<haxor.graphics.texture.Bitmap>) (p_data1) ), ((haxe.root.Array<haxor.platform.android.LoadTexture2D>) (_g) )), false, true);
		}
		
	}
	
	
	@Override public   void OnError()
	{
		if (( this.m_t2d_callback != null )) 
		{
			this.m_bitmap_callback.__hx_invoke2_o(0.0, null, 1.0, haxe.lang.Runtime.undefined);
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef54422 = true;
			switch (field.hashCode())
			{
				case 766451996:
				{
					if (field.equals("m_apply")) 
					{
						__temp_executeDef54422 = false;
						this.m_apply = haxe.lang.Runtime.toBool(value);
						return value;
					}
					
					break;
				}
				
				
				case -1492542192:
				{
					if (field.equals("m_t2d_callback")) 
					{
						__temp_executeDef54422 = false;
						this.m_t2d_callback = ((haxe.lang.Function) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54422) 
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
			boolean __temp_executeDef54423 = true;
			switch (field.hashCode())
			{
				case 314785609:
				{
					if (field.equals("OnError")) 
					{
						__temp_executeDef54423 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnError"))) );
					}
					
					break;
				}
				
				
				case -1492542192:
				{
					if (field.equals("m_t2d_callback")) 
					{
						__temp_executeDef54423 = false;
						return this.m_t2d_callback;
					}
					
					break;
				}
				
				
				case -1871658381:
				{
					if (field.equals("OnBitmapCallback")) 
					{
						__temp_executeDef54423 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnBitmapCallback"))) );
					}
					
					break;
				}
				
				
				case 766451996:
				{
					if (field.equals("m_apply")) 
					{
						__temp_executeDef54423 = false;
						return this.m_apply;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54423) 
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
			boolean __temp_executeDef54424 = true;
			switch (field.hashCode())
			{
				case 314785609:
				{
					if (field.equals("OnError")) 
					{
						__temp_executeDef54424 = false;
						return haxe.lang.Runtime.slowCallField(this, field, dynargs);
					}
					
					break;
				}
				
				
				case -1871658381:
				{
					if (field.equals("OnBitmapCallback")) 
					{
						__temp_executeDef54424 = false;
						this.OnBitmapCallback(((haxor.graphics.texture.Bitmap) (dynargs.__get(0)) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef54424) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_apply");
		baseArr.push("m_t2d_callback");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


