package haxor.platform.android;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class LoadImageTask extends haxor.platform.android.LoadBytesTask
{
	public    LoadImageTask(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    LoadImageTask(java.lang.String p_url, java.lang.String p_method, java.lang.String p_data, haxe.lang.Function p_callback)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.platform.android.LoadImageTask.__hx_ctor_haxor_platform_android_LoadImageTask(this, p_url, p_method, p_data, p_callback);
	}
	
	
	public static   void __hx_ctor_haxor_platform_android_LoadImageTask(haxor.platform.android.LoadImageTask __temp_me21771, java.lang.String p_url, java.lang.String p_method, java.lang.String p_data, haxe.lang.Function p_callback)
	{
		haxor.platform.android.LoadBytesTask.__hx_ctor_haxor_platform_android_LoadBytesTask(__temp_me21771, p_url, p_method, p_data);
		__temp_me21771.callback = p_callback;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.LoadImageTask(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.LoadImageTask(haxe.lang.Runtime.toString(arr.__get(0)), haxe.lang.Runtime.toString(arr.__get(1)), haxe.lang.Runtime.toString(arr.__get(2)), ((haxe.lang.Function) (arr.__get(3)) ));
	}
	
	
	public  haxe.lang.Function callback;
	
	@Override public   void OnProgress(double p_ratio, int p_loaded, int p_total)
	{
		this.callback.__hx_invoke2_o(0.0, null, p_ratio, haxe.lang.Runtime.undefined);
	}
	
	
	@Override public   void OnComplete()
	{
		byte[] bl = this.output.toByteArray();
		android.graphics.Bitmap img = android.graphics.BitmapFactory.decodeByteArray(((byte[]) (bl) ), ((int) (0) ), ((int) (bl.length) ));
	}
	
	
	@Override public   void OnError(java.lang.Exception p_error)
	{
		super.OnError(p_error);
		this.callback.__hx_invoke2_o(0.0, null, 1.0, haxe.lang.Runtime.undefined);
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef21957 = true;
			switch (field.hashCode())
			{
				case -172220347:
				{
					if (field.equals("callback")) 
					{
						__temp_executeDef21957 = false;
						this.callback = ((haxe.lang.Function) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21957) 
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
			boolean __temp_executeDef21958 = true;
			switch (field.hashCode())
			{
				case 314785609:
				{
					if (field.equals("OnError")) 
					{
						__temp_executeDef21958 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnError"))) );
					}
					
					break;
				}
				
				
				case -172220347:
				{
					if (field.equals("callback")) 
					{
						__temp_executeDef21958 = false;
						return this.callback;
					}
					
					break;
				}
				
				
				case -130994088:
				{
					if (field.equals("OnComplete")) 
					{
						__temp_executeDef21958 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnComplete"))) );
					}
					
					break;
				}
				
				
				case -532627124:
				{
					if (field.equals("OnProgress")) 
					{
						__temp_executeDef21958 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnProgress"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21958) 
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
		baseArr.push("callback");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


