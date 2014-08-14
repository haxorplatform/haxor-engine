package haxor.platform.android;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class LoadTask extends haxe.lang.HxObject implements java.lang.Runnable
{
	static 
	{
		haxor.platform.android.LoadTask.__meta__ = new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"fields"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"run"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"override"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{null}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}))}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}))}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{}));
	}
	public    LoadTask(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    LoadTask(java.lang.String p_url, java.lang.String p_method, java.lang.String p_data)
	{
		haxor.platform.android.LoadTask.__hx_ctor_haxor_platform_android_LoadTask(this, p_url, p_method, p_data);
	}
	
	
	public static   void __hx_ctor_haxor_platform_android_LoadTask(haxor.platform.android.LoadTask __temp_me21768, java.lang.String p_url, java.lang.String p_method, java.lang.String p_data)
	{
		__temp_me21768.url = haxe.root.StringTools.replace(p_url, "./", haxor.platform.android.Web.root);
		__temp_me21768.method = p_method;
		__temp_me21768.data = p_data;
		haxor.core.Console.Log(( ( "Web> Load from [" + __temp_me21768.url ) + "]" ), 1);
		__temp_me21768.thread = new java.lang.Thread(((java.lang.Runnable) (__temp_me21768) ));
		__temp_me21768.thread.start();
	}
	
	
	public static  java.lang.Object __meta__;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.LoadTask(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.LoadTask(haxe.lang.Runtime.toString(arr.__get(0)), haxe.lang.Runtime.toString(arr.__get(1)), haxe.lang.Runtime.toString(arr.__get(2)));
	}
	
	
	public  java.lang.Thread thread;
	
	public  java.lang.String url;
	
	public  java.lang.String method;
	
	public  java.lang.String data;
	
	public  java.lang.String contentType;
	
	public  java.io.InputStream stream;
	
	public  int bytesTotal;
	
	public   void run()
	{
		try 
		{
			java.net.HttpURLConnection con = ((java.net.HttpURLConnection) (haxe.lang.Runtime.callField(((java.lang.Object) (new java.net.URL(haxe.lang.Runtime.toString(this.url))) ), "openConnection", null)) );
			con.setRequestMethod(haxe.lang.Runtime.toString(this.method));
			con.setRequestProperty(haxe.lang.Runtime.toString("Accept"), haxe.lang.Runtime.toString("text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8"));
			this.contentType = con.getHeaderField(haxe.lang.Runtime.toString("Content-Type"));
			con.connect();
			this.stream = con.getInputStream();
			this.bytesTotal = ((int) (con.getContentLength()) );
			this.OnConnect(con);
			con.disconnect();
			this.OnComplete();
		}
		catch (java.lang.Exception err)
		{
			this.OnError(err);
		}
		
		
	}
	
	
	public   void OnProgress(double p_ratio, int p_loaded, int p_total)
	{
		{
		}
		
	}
	
	
	public   void OnConnect(java.net.HttpURLConnection p_connection)
	{
		{
		}
		
	}
	
	
	public   void OnComplete()
	{
		{
		}
		
	}
	
	
	public   void OnError(java.lang.Exception p_error)
	{
		haxor.core.Console.LogError(( "Web> " + p_error.getMessage() ), null);
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef21948 = true;
			switch (field.hashCode())
			{
				case 1382331801:
				{
					if (field.equals("bytesTotal")) 
					{
						__temp_executeDef21948 = false;
						this.bytesTotal = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21948) 
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
			boolean __temp_executeDef21949 = true;
			switch (field.hashCode())
			{
				case 1382331801:
				{
					if (field.equals("bytesTotal")) 
					{
						__temp_executeDef21949 = false;
						this.bytesTotal = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -874443254:
				{
					if (field.equals("thread")) 
					{
						__temp_executeDef21949 = false;
						this.thread = ((java.lang.Thread) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -891990144:
				{
					if (field.equals("stream")) 
					{
						__temp_executeDef21949 = false;
						this.stream = ((java.io.InputStream) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 116079:
				{
					if (field.equals("url")) 
					{
						__temp_executeDef21949 = false;
						this.url = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -389131437:
				{
					if (field.equals("contentType")) 
					{
						__temp_executeDef21949 = false;
						this.contentType = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case -1077554975:
				{
					if (field.equals("method")) 
					{
						__temp_executeDef21949 = false;
						this.method = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef21949 = false;
						this.data = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21949) 
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
			boolean __temp_executeDef21950 = true;
			switch (field.hashCode())
			{
				case 314785609:
				{
					if (field.equals("OnError")) 
					{
						__temp_executeDef21950 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnError"))) );
					}
					
					break;
				}
				
				
				case -874443254:
				{
					if (field.equals("thread")) 
					{
						__temp_executeDef21950 = false;
						return this.thread;
					}
					
					break;
				}
				
				
				case -130994088:
				{
					if (field.equals("OnComplete")) 
					{
						__temp_executeDef21950 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnComplete"))) );
					}
					
					break;
				}
				
				
				case 116079:
				{
					if (field.equals("url")) 
					{
						__temp_executeDef21950 = false;
						return this.url;
					}
					
					break;
				}
				
				
				case -3368469:
				{
					if (field.equals("OnConnect")) 
					{
						__temp_executeDef21950 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnConnect"))) );
					}
					
					break;
				}
				
				
				case -1077554975:
				{
					if (field.equals("method")) 
					{
						__temp_executeDef21950 = false;
						return this.method;
					}
					
					break;
				}
				
				
				case -532627124:
				{
					if (field.equals("OnProgress")) 
					{
						__temp_executeDef21950 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnProgress"))) );
					}
					
					break;
				}
				
				
				case 3076010:
				{
					if (field.equals("data")) 
					{
						__temp_executeDef21950 = false;
						return this.data;
					}
					
					break;
				}
				
				
				case 113291:
				{
					if (field.equals("run")) 
					{
						__temp_executeDef21950 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("run"))) );
					}
					
					break;
				}
				
				
				case -389131437:
				{
					if (field.equals("contentType")) 
					{
						__temp_executeDef21950 = false;
						return this.contentType;
					}
					
					break;
				}
				
				
				case 1382331801:
				{
					if (field.equals("bytesTotal")) 
					{
						__temp_executeDef21950 = false;
						return this.bytesTotal;
					}
					
					break;
				}
				
				
				case -891990144:
				{
					if (field.equals("stream")) 
					{
						__temp_executeDef21950 = false;
						return this.stream;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21950) 
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
			boolean __temp_executeDef21951 = true;
			switch (field.hashCode())
			{
				case 1382331801:
				{
					if (field.equals("bytesTotal")) 
					{
						__temp_executeDef21951 = false;
						return ((double) (this.bytesTotal) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21951) 
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
			boolean __temp_executeDef21952 = true;
			switch (field.hashCode())
			{
				case 314785609:
				{
					if (field.equals("OnError")) 
					{
						__temp_executeDef21952 = false;
						this.OnError(((java.lang.Exception) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 113291:
				{
					if (field.equals("run")) 
					{
						__temp_executeDef21952 = false;
						this.run();
					}
					
					break;
				}
				
				
				case -130994088:
				{
					if (field.equals("OnComplete")) 
					{
						__temp_executeDef21952 = false;
						this.OnComplete();
					}
					
					break;
				}
				
				
				case -532627124:
				{
					if (field.equals("OnProgress")) 
					{
						__temp_executeDef21952 = false;
						this.OnProgress(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(2))) ));
					}
					
					break;
				}
				
				
				case -3368469:
				{
					if (field.equals("OnConnect")) 
					{
						__temp_executeDef21952 = false;
						this.OnConnect(((java.net.HttpURLConnection) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef21952) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("bytesTotal");
		baseArr.push("stream");
		baseArr.push("contentType");
		baseArr.push("data");
		baseArr.push("method");
		baseArr.push("url");
		baseArr.push("thread");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


