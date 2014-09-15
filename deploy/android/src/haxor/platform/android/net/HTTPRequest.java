package haxor.platform.android.net;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class HTTPRequest extends haxor.net.HTTPRequestTask<java.net.HttpURLConnection, java.io.ByteArrayOutputStream>
{
	public    HTTPRequest(haxe.lang.EmptyObject empty)
	{
		super(haxe.lang.EmptyObject.EMPTY);
	}
	
	
	public    HTTPRequest(java.lang.String p_url, java.lang.String p_method, boolean p_binary, java.lang.String p_data)
	{
		super(haxe.lang.EmptyObject.EMPTY);
		haxor.platform.android.net.HTTPRequest.__hx_ctor_haxor_platform_android_net_HTTPRequest(this, p_url, p_method, p_binary, p_data);
	}
	
	
	public static   void __hx_ctor_haxor_platform_android_net_HTTPRequest(haxor.platform.android.net.HTTPRequest __temp_me255642, java.lang.String p_url, java.lang.String p_method, boolean p_binary, java.lang.String p_data)
	{
		haxor.net.HTTPRequestTask.__hx_ctor_haxor_net_HTTPRequestTask(__temp_me255642, p_url, p_method, p_binary, ( (( p_data == null )) ? (haxe.lang.Runtime.toString(null)) : (p_data) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxor.platform.android.net.HTTPRequest(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxor.platform.android.net.HTTPRequest(haxe.lang.Runtime.toString(arr.__get(0)), haxe.lang.Runtime.toString(arr.__get(1)), haxe.lang.Runtime.toBool(arr.__get(2)), haxe.lang.Runtime.toString(arr.__get(3)));
	}
	
	
	public  byte[] m_buffer;
	
	public  java.io.InputStream m_stream;
	
	@Override public   void OnStart()
	{
		try 
		{
			this.request = ((java.net.HttpURLConnection) (haxe.lang.Runtime.callField(((java.lang.Object) (new java.net.URL(haxe.lang.Runtime.toString(this.url))) ), "openConnection", null)) );
			this.request.setRequestMethod(haxe.lang.Runtime.toString(this.method));
			this.request.connect();
			this.m_stream = this.request.getInputStream();
			this.bytesTotal = ((int) (this.request.getContentLength()) );
		}
		catch (java.lang.Exception err)
		{
			this.error = err.getMessage();
			this.OnError();
			this.Cancel();
			return ;
		}
		
		
		this.response = new java.io.ByteArrayOutputStream();
		this.m_buffer = new byte[((int) (1024) )];
	}
	
	
	@Override public   void OnStep()
	{
		int step = 0;
		try 
		{
			step = this.m_stream.read(((byte[]) (this.m_buffer) ));
		}
		catch (java.lang.Exception err)
		{
			this.error = err.getMessage();
			this.OnError();
			this.Cancel();
			return ;
		}
		
		
		if (( step == 0 )) 
		{
			return ;
		}
		
		if (( step < 0 )) 
		{
			this.bytesLoaded = this.bytesTotal;
			this.set_progress(1.0);
			return ;
		}
		
		this.response.write(((byte[]) (this.m_buffer) ), ((int) (0) ), ((int) (step) ));
		this.bytesLoaded += step;
		double t = ((double) (this.bytesTotal) );
		double l = ((double) (this.bytesLoaded) );
		double r = 0.0;
		if (( t <= 0.0 )) 
		{
			r = 0.0;
		}
		 else 
		{
			r = ( l / t );
		}
		
		if (( r >= 1.0 )) 
		{
			r = 1.0;
		}
		
		this.set_progress(( r * 0.999 ));
	}
	
	
	@Override public   void OnComplete()
	{
		this.request.disconnect();
		try 
		{
			this.response.flush();
		}
		catch (java.lang.Exception err)
		{
			this.error = err.getMessage();
			this.OnError();
			this.Cancel();
		}
		
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef256499 = true;
			switch (field.hashCode())
			{
				case -1490720878:
				{
					if (field.equals("m_stream")) 
					{
						__temp_executeDef256499 = false;
						this.m_stream = ((java.io.InputStream) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1976849326:
				{
					if (field.equals("m_buffer")) 
					{
						__temp_executeDef256499 = false;
						this.m_buffer = ((byte[]) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256499) 
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
			boolean __temp_executeDef256500 = true;
			switch (field.hashCode())
			{
				case -130994088:
				{
					if (field.equals("OnComplete")) 
					{
						__temp_executeDef256500 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnComplete"))) );
					}
					
					break;
				}
				
				
				case -1976849326:
				{
					if (field.equals("m_buffer")) 
					{
						__temp_executeDef256500 = false;
						return this.m_buffer;
					}
					
					break;
				}
				
				
				case -1929089685:
				{
					if (field.equals("OnStep")) 
					{
						__temp_executeDef256500 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnStep"))) );
					}
					
					break;
				}
				
				
				case -1490720878:
				{
					if (field.equals("m_stream")) 
					{
						__temp_executeDef256500 = false;
						return this.m_stream;
					}
					
					break;
				}
				
				
				case 327758243:
				{
					if (field.equals("OnStart")) 
					{
						__temp_executeDef256500 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("OnStart"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef256500) 
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
		baseArr.push("m_stream");
		baseArr.push("m_buffer");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


