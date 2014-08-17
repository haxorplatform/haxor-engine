package haxor.platform.android;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class LoadStringTask extends haxor.platform.android.LoadTask
{
	public    LoadStringTask(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    LoadStringTask(java.lang.String p_url, java.lang.String p_method, java.lang.String p_data, haxe.lang.Function p_callback)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.platform.android.LoadStringTask.__hx_ctor_haxor_platform_android_LoadStringTask(this, p_url, p_method, p_data, p_callback);
	}
	
	
	public static   void __hx_ctor_haxor_platform_android_LoadStringTask(haxor.platform.android.LoadStringTask __temp_me27917, java.lang.String p_url, java.lang.String p_method, java.lang.String p_data, haxe.lang.Function p_callback)
	{
		haxor.platform.android.LoadTask.__hx_ctor_haxor_platform_android_LoadTask(__temp_me27917, p_url, p_method, p_data);
		__temp_me27917.callback = p_callback;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.LoadStringTask(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.LoadStringTask(haxe.lang.Runtime.toString(arr.__get(0)), haxe.lang.Runtime.toString(arr.__get(1)), haxe.lang.Runtime.toString(arr.__get(2)), ((haxe.lang.Function) (arr.__get(3)) ));
	}
	
	
	public  java.lang.String result;
	
	public  haxe.lang.Function callback;
	
	@Override public   void OnConnect(java.net.HttpURLConnection p_connection)
	{
		this.result = "";
		java.net.HttpURLConnection con = p_connection;
		java.io.BufferedReader buffer = new java.io.BufferedReader(((java.io.Reader) (new java.io.InputStreamReader(((java.io.InputStream) (this.stream) ))) ));
		double loaded = 0.0;
		java.lang.String l = "";
		haxe.root.Array<java.lang.String> lines = new haxe.root.Array<java.lang.String>(new java.lang.String[]{});
		this.callback.__hx_invoke2_o(0.0, null, 0.0, haxe.lang.Runtime.undefined);
		while (true)
		{
			try 
			{
				l = buffer.readLine();
			}
			catch (java.lang.Exception err)
			{
				this.OnError(err);
			}
			
			
			if (( l == null )) 
			{
				break;
			}
			
			lines.push(l);
			loaded += ((double) (l.length()) );
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
			
			this.OnProgress(r, l.length(), this.bytesTotal);
			if (( this.bytesTotal >= 0 )) 
			{
				this.callback.__hx_invoke2_o(0.0, null, ( r * 0.99 ), haxe.lang.Runtime.undefined);
			}
			
		}
		
		this.result = lines.join("\n");
	}
	
	
	@Override public   void OnComplete()
	{
		this.callback.__hx_invoke2_o(0.0, this.result, 1.0, haxe.lang.Runtime.undefined);
	}
	
	
	@Override public   void OnError(java.lang.Exception p_error)
	{
		super.OnError(p_error);
		this.callback.__hx_invoke2_o(0.0, null, 1.0, haxe.lang.Runtime.undefined);
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef28117 = true;
			switch (field.hashCode())
			{
				case -172220347:
				{
					if (field.equals("callback")) 
					{
						__temp_executeDef28117 = false;
						this.callback = ((haxe.lang.Function) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -934426595:
				{
					if (field.equals("result")) 
					{
						__temp_executeDef28117 = false;
						this.result = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28117) 
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
			boolean __temp_executeDef28118 = true;
			switch (field.hashCode())
			{
				case 314785609:
				{
					if (field.equals("OnError")) 
					{
						__temp_executeDef28118 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnError"))) );
					}
					
					break;
				}
				
				
				case -934426595:
				{
					if (field.equals("result")) 
					{
						__temp_executeDef28118 = false;
						return this.result;
					}
					
					break;
				}
				
				
				case -130994088:
				{
					if (field.equals("OnComplete")) 
					{
						__temp_executeDef28118 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnComplete"))) );
					}
					
					break;
				}
				
				
				case -172220347:
				{
					if (field.equals("callback")) 
					{
						__temp_executeDef28118 = false;
						return this.callback;
					}
					
					break;
				}
				
				
				case -3368469:
				{
					if (field.equals("OnConnect")) 
					{
						__temp_executeDef28118 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnConnect"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef28118) 
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
		baseArr.push("result");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


