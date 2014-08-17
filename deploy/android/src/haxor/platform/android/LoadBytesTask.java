package haxor.platform.android;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class LoadBytesTask extends haxor.platform.android.LoadTask
{
	public    LoadBytesTask(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    LoadBytesTask(java.lang.String p_url, java.lang.String p_method, java.lang.String p_data)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.platform.android.LoadBytesTask.__hx_ctor_haxor_platform_android_LoadBytesTask(this, p_url, p_method, p_data);
	}
	
	
	public static   void __hx_ctor_haxor_platform_android_LoadBytesTask(haxor.platform.android.LoadBytesTask __temp_me27918, java.lang.String p_url, java.lang.String p_method, java.lang.String p_data)
	{
		haxor.platform.android.LoadTask.__hx_ctor_haxor_platform_android_LoadTask(__temp_me27918, p_url, p_method, p_data);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.LoadBytesTask(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.LoadBytesTask(haxe.lang.Runtime.toString(arr.__get(0)), haxe.lang.Runtime.toString(arr.__get(1)), haxe.lang.Runtime.toString(arr.__get(2)));
	}
	
	
	public  java.io.ByteArrayOutputStream output;
	
	@Override public   void OnConnect(java.net.HttpURLConnection p_connection)
	{
		this.output = new java.io.ByteArrayOutputStream();
		java.net.HttpURLConnection con = p_connection;
		double loaded = 0.0;
		int step = 0;
		byte[] buffer = new byte[((int) (1024) )];
		while (true)
		{
			try 
			{
				step = this.stream.read(((byte[]) (buffer) ));
			}
			catch (java.lang.Exception err)
			{
				this.OnError(err);
			}
			
			
			if (( step < 0 )) 
			{
				break;
			}
			
			loaded += ((double) (step) );
			double t = ((double) (this.bytesTotal) );
			double r = 0.0;
			if (( t <= 0.0 )) 
			{
				r = 0.0;
			}
			 else 
			{
				r = ( loaded / t );
			}
			
			if (( r >= 1.0 )) 
			{
				r = 1.0;
			}
			
			this.OnProgress(r, step, this.bytesTotal);
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef28119 = true;
			switch (field.hashCode())
			{
				case -1005512447:
				{
					if (field.equals("output")) 
					{
						__temp_executeDef28119 = false;
						this.output = ((java.io.ByteArrayOutputStream) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28119) 
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
			boolean __temp_executeDef28120 = true;
			switch (field.hashCode())
			{
				case -3368469:
				{
					if (field.equals("OnConnect")) 
					{
						__temp_executeDef28120 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnConnect"))) );
					}
					
					break;
				}
				
				
				case -1005512447:
				{
					if (field.equals("output")) 
					{
						__temp_executeDef28120 = false;
						return this.output;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28120) 
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
		baseArr.push("output");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


